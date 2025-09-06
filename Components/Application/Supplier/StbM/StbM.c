/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  StbM.c
 *        \brief  Vector AUTOSAR StbM code file
 *
 *      \details  This is the main implementation file of the Vector AUTOSAR module StbM.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define STBM_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "StbM.h"
#include "SchM_StbM.h"
#if (STBM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
#if (STBM_USE_ECUM_BSW_ERROR_HOOK == STD_ON) /* COV_STBM_POSTBUILD_SWITCH */
# include "EcuM_Error.h"
#endif
#include "StbM_Cbk.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of StbM header file */
#if (  (STBM_SW_MAJOR_VERSION != (9u)) \
    || (STBM_SW_MINOR_VERSION != (5u)) \
    || (STBM_SW_PATCH_VERSION != (1u)) )
# error "Vendor specific version numbers of StbM.c and StbM.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (STBM_CFG_MAJOR_VERSION != (9u)) \
    || (STBM_CFG_MINOR_VERSION != (5u)) )
# error "Version numbers of StbM.c and StbM_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#define STBM_MICROSECOND_IN_ONE_SECOND                  (1000000u)
#define STBM_NANOSECONDS_IN_ONE_MICROSECOND             (1000u)
#define STBM_NANOSECONDS_IN_ONE_SECOND                  (1000000000uL)

#define STBM_NANOSECONDS_IN_ONE_SECOND_DOUBLE           ((float64)(1000000000.0))
#define STBM_SECONDS_IN_ONE_SECONDHI_DOUBLE             ((float64)(4294967296.0))

#define STBM_TIMESTAMP_MAX_NANOSECONDS                  (999999999uL)   /* 10^9 nanoseconds per second */
#define STBM_TIMESTAMP_MAX_SECONDS                      (4294967295uL)
#define STBM_TIMESTAMP_MAX_SECONDSHI                    (65535u)

#define STBM_TIMESTAMP_MAX_SECONDSHI_DOUBLE             ((float64)(65535.0))

#define STBM_VIRTUALLOCALTIME_MAX_NANOSECONDS           (4294967295uL)

#define STBM_TIMEDIFF_MAX_NANOSECONDS                   (0x7FFFFFFFFFFFFFFFuLL)
#define STBM_TIMEDIFF_MAX_SECONDS                       (STBM_TIMEDIFF_MAX_NANOSECONDS / STBM_NANOSECONDS_IN_ONE_SECOND)

#define STBM_TIMELEAP_MAX_FUTURE                        (2147483647)
#define STBM_TIMELEAP_MAX_PAST                          (-STBM_TIMELEAP_MAX_FUTURE)

#define STBM_MAX_RATE_PPM                               (32000)
#define STBM_MIN_RATE_PPM                               (-32000)
#define STBM_MAX_RATE_FLOAT                             (1.032)
#define STBM_MIN_RATE_FLOAT                             (0.968)

#define STBM_GPT_TIMER_STOPPED                          (0u)
#define STBM_GPT_TIMER_RUNNING                          (1u)

/* Timer has no expire time set */
#define STBM_NOTIFICATION_TIMER_STOPPED                 (0u)
/* Timer has an expire time set */
#define STBM_NOTIFICATION_TIMER_STARTED                 (1u)
/* Gpt timer is running for this timer */
#define STBM_NOTIFICATION_TIMER_RUNNING                 (2u)
/* Timer is expired */
#define STBM_NOTIFICATION_TIMER_EXPIRED                 (3u)

/* id for invalid time notification customer */
#define STBM_INVALID_TIME_NOTIFICATION_CUSTOMER         (65535u)

/* id for invalid time base index */
#define STBM_INVALID_TIME_BASE_INDEX                    (255u)

/* initialize timestamp with time zero */
#define STBM_INIT_TIME_ZERO                             {0u, 0u, 0u}

/* initialize clock with value zero */
#define STBM_INIT_CLOCK_ZERO                            {0u, 0u, 0u}

/* initialize virtual local time with time zero */
#define STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO               {0u, 0u}

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define StbM_SetTimeoutBit(status)                      (status) = ((status) | StbM_Timeout_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_SetTimeLeapFutureBit(status)               (status) = ((status) | StbM_TimeLeapFuture_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_SetTimeLeapPastBit(status)                 (status) = ((status) | StbM_TimeLeapPast_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_SetSyncToGatewayBit(status)                (status) = ((status) | StbM_Sync_To_Gateway_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_SetGlobalTimeBaseBit(status)               (status) = ((status) | StbM_Global_Time_Base_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define StbM_ClearTimeoutBit(status)                    (status) = ((status) & ~StbM_Timeout_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_ClearTimeLeapFutureBit(status)             (status) = ((status) & ~StbM_TimeLeapFuture_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_ClearTimeLeapPastBit(status)               (status) = ((status) & ~StbM_TimeLeapPast_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_ClearSyncToGatewayBit(status)              (status) = ((status) & ~StbM_Sync_To_Gateway_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_ClearGlobalTimeBaseBit(status)             (status) = ((status) & ~StbM_Global_Time_Base_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define StbM_GetTimeoutBit(status)                      ((status) & StbM_Timeout_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_GetTimeLeapFutureBit(status)               ((status) & StbM_TimeLeapFuture_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_GetTimeLeapPastBit(status)                 ((status) & StbM_TimeLeapPast_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_GetSyncToGatewayBit(status)                ((status) & StbM_Sync_To_Gateway_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_GetGlobalTimeBaseBit(status)               ((status) & StbM_Global_Time_Base_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define StbM_GetCloneDeferredCopy(cloneCfg)             ((cloneCfg) & STBM_DEFERRED_COPY_MASK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_GetCloneApplyRate(cloneCfg)                ((cloneCfg) & STBM_APPLY_RATE_MASK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define StbM_GetCloneImmediateTx(cloneCfg)              ((cloneCfg) & STBM_IMMEDIATE_TX_MASK) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if (STBM_DEV_ERROR_REPORT == STD_ON)
# define StbM_ReportError(API_ID, ERROR_CODE)           (void) Det_ReportError((STBM_MODULE_ID), 0u, ((uint8)(API_ID)), ((uint8)(ERROR_CODE))) /* PRQA  S 3453 */ /* MD_MSR_FctLikeMacro */
#endif
                                                        /* Get the fractional part of the number (e.g. 1.5 -> 0.5) */
#define StbM_fPart(x)                                   ((x) - (float64)((uint64)(x))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
                                                        /* Get the integer part of the number (e.g. 1.5 -> 1) */
#define StbM_iPart(x)                                   (float64)((uint64)(x)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON))
# define StbM_ToStbMRateDeviationType(x)                 (((x) * (float64)1000000.0) - (float64)1000000.0) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define StbM_ToStbMInternalRateType(x)                  (((x) * (float64)0.000001) + (float64)1.0)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

/* Check if component is already pre initialized */
#define StbM_IsPreInitialized()                         (StbM_PreInitialized != FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Check if component is already initialized */
#define StbM_IsPostInitialized()                        (StbM_PostInitialized != FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Critical section for retry in Adaptive */
#if !defined (StbM_Enter_CRITICAL_SECTION_GET_TS)
# define StbM_Enter_CRITICAL_SECTION_GET_TS()
#endif
#if !defined (StbM_Exit_CRITICAL_SECTION_GET_TS)
# define StbM_Exit_CRITICAL_SECTION_GET_TS()
#endif

/*! Enter critical section of StbM */
#define StbM_EnterCritical_LocalCore()                  SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_0()
#define StbM_EnterCritical_CrossCore()                  SchM_Enter_StbM_STBM_EXCLUSIVE_AREA_1()
#define StbM_EnterCritical_Get_TS()                     StbM_Enter_CRITICAL_SECTION_GET_TS()
/*! Leave critical section of StbM */
#define StbM_LeaveCritical_LocalCore()                  SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_0()
#define StbM_LeaveCritical_CrossCore()                  SchM_Exit_StbM_STBM_EXCLUSIVE_AREA_1()
#define StbM_LeaveCritical_Get_TS()                     StbM_Exit_CRITICAL_SECTION_GET_TS()

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (STBM_CONFIG_GPT_CLOCK == STD_ON)
typedef uint32 StbM_GptTickType;
#endif
#if (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON)
typedef uint64 StbM_MicrosecondType;
#endif
#if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON))
typedef float64 StbM_InternalRateType;
#endif
typedef uint8 StbM_UpdateCounterType;

#if !defined (STBM_LOCAL)       /* COV_STBM_MSR_COMPATIBILITY */
# define STBM_LOCAL static
#endif

#if !defined (STBM_LOCAL_INLINE)        /* COV_STBM_MSR_COMPATIBILITY */
# define STBM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA VAR
 *********************************************************************************************************************/

#if (STBM_CONFIG_TIME_NOTIFICATION == STD_ON)
#define STBM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Timer variable of time notification customers */
STBM_LOCAL VAR(uint8, STBM_VAR_NO_INIT) StbM_GptTimerState;

/*! Flag to indicate whether or not the StbM is in the timer callback context */
STBM_LOCAL VAR(boolean, STBM_VAR_NO_INIT) StbM_TimerCallbackContextActive;

/*! Flag to indicate whether or not the timer notification task was already activated */
STBM_LOCAL VAR(boolean, STBM_VAR_NO_INIT) StbM_NotificationTaskActivated;

#define STBM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL DATA CONST
 *********************************************************************************************************************/

#define STBM_START_SEC_CONST_UNSPECIFIED
#include "StbM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* timestamp with time zero */
STBM_LOCAL CONST(StbM_InternalTimeStampType, STBM_CONST) STBM_ZERO_TIME = STBM_INIT_TIME_ZERO;

/* virtual local time with time zero */
STBM_LOCAL CONST(StbM_VirtualLocalTimeType, STBM_CONST) STBM_ZERO_VIRTUAL_LOCAL_TIME = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

#define STBM_STOP_SEC_CONST_UNSPECIFIED
#include "StbM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#if (STBM_USE_INIT_POINTER == STD_ON)
# define STBM_START_SEC_VAR_INIT_CONFIGPTR
# include "StbM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

P2CONST(StbM_ConfigType, AUTOMATIC, STBM_INIT_DATA) StbM_ConfigDataPtr = NULL_PTR;

# define STBM_STOP_SEC_VAR_INIT_CONFIGPTR
# include "StbM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define STBM_START_SEC_CODE
#include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  UNITS
 *********************************************************************************************************************/
#ifndef STBM_NOUNIT_COMMON /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: Common
 *********************************************************************************************************************/
/*! \brief      This unit handles the common part of the StbM.
 *  \details    -
 *  \pre        -
 *  \trace      COMMON_UNIT
 *********************************************************************************************************************/
# if (STBM_MULTIPARTITION_USED == STD_ON)
/**********************************************************************************************************************
 *  StbM_Common_GetCurrentPartitionIndexByOsApplication
 *********************************************************************************************************************/
/*! \brief       Get current Partition Index
 *  \details     Get current partition index by os application
 *  \param[in]   osAppId, os application id.
 *  \return      partitionIndex
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        Common
 *********************************************************************************************************************/
STBM_LOCAL FUNC(StbM_PartitionIdentifiersIterType, STBM_CODE) StbM_Common_GetCurrentPartitionIndexByOsApplication(ApplicationType osAppId);
# endif /* STBM_MULTIPARTITION_USED == STD_ON */
#endif /* STBM_NOUNIT_COMMON */

#ifndef STBM_NOUNIT_GLOBALTIME /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: GlobalTime
 *********************************************************************************************************************/
/*! \brief      This unit handles the GlobalTime.
 *  \details    -
 *  \pre        -
 *  \trace      GLOBALTIME_UNIT
 *********************************************************************************************************************/
# if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_GlobalTime_SetNewGlobalTime
 *********************************************************************************************************************/
/*! \brief       Sets new global time
 *  \details     Sets the given global time without incrementing the update counter.s
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   globalTime, new global time.
 *  \param[in]   incrementOnSuccess, if true, StbM_TimeBase_IncrementUpdateCounter gets called on success.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        GlobalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_SetNewGlobalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTime,
        boolean incrementOnSuccess,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_GlobalTime_ReceiveGlobalTime
 *********************************************************************************************************************/
/*! \brief       Receive new global time for the given timebase
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   globalTimePtr, new global time.
 *  \param[in]   localTimePtr, new virtual local time.
 *  \param[in]   timeBaseStatus, status.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        GlobalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_ReceiveGlobalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) localTimePtr,
        StbM_TimeBaseStatusType timeBaseStatus,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_GlobalTime_OnGetCurrentTime
 *********************************************************************************************************************/
/*! \brief       Get the current time (TL)
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[out]  localTimePtr, TL.
 *  \param[out]  virtualLocalTimePtr, TV.
 *  \param[out]  userData, the user data.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        GlobalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_OnGetCurrentTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) localTimePtr,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTimePtr,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userData,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_GlobalTime_GetTime
 *********************************************************************************************************************/
/*! \brief       Get the current time (TL)
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[out]  localTime, TL.
 *  \param[out]  virtualLocalTime, TV.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_GetTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTime,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if ((STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON))
/**********************************************************************************************************************
 *  StbM_GlobalTime_OnGetCurrentTimeExtended
 *********************************************************************************************************************/
/*! \brief       Get the current time (TL) in extended format.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[out]  localTimePtr, TL.
 *  \param[out]  userData, the user data.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        GlobalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_OnGetCurrentTimeExtended(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_VAR) localTimePtr,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userData,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON) */

/**********************************************************************************************************************
 *  StbM_GlobalTime_OnGetMainTime
 *********************************************************************************************************************/
/*! \brief       Get the main time tuple (TGsync, TVsync) and status
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[out]  globalTimeSyncPtr, TGsync and status.
 *  \param[out]  localTimeSyncPtr, TVsync.
 *  \param[out]  rateDeviation, rate.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        GlobalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_GlobalTime_OnGetMainTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimeSyncPtr,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) localTimeSyncPtr,
        P2VAR(StbM_RateDeviationType, AUTOMATIC, STBM_APPL_VAR) rateDeviation,
        StbM_PartitionIdentifiersIterType partitionIdx);

#endif /* STBM_NOUNIT_GLOBALTIME */

#ifndef STBM_NOUNIT_CLONETIME /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  Unit: CloneTime
 *********************************************************************************************************************/
/*! \brief      This unit handles cloning of Time Base.
 *  \details    -
 *  \pre        -
 *  \trace      CLONETIME_UNIT
 *********************************************************************************************************************/

#  if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_CloneTime_InitCloneRequestState
 *********************************************************************************************************************/
/*! \brief       Initialize clone request state table.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index of source time base.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \unit        CloneTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_CloneTime_InitCloneRequestState(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_CloneTime_StoreCloneRequest
 *********************************************************************************************************************/
/*! \brief       Store clone request.
 *  \details     -
 *  \param[in]   destinationTimeBaseIdx, time base index of destination time base.
 *  \param[in]   partitionIdx, valid partition index.
 *  \param[in]   cloneCfg, Refines how source Time Base is cloned to destination.
 *  \param[in]   statusMask, Status flags mask for definition of relevant status flags.
 *  \param[in]   statusValue, Status flags value define whether cloning shall take place.
 *  \return      E_OK, if there is a clone source Time Base to store request
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        CloneTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_CloneTime_StoreCloneRequest(
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx,
        StbM_CloneConfigType cloneCfg,
        StbM_TimeBaseStatusType statusMask,
        StbM_TimeBaseStatusType statusValue);

/**********************************************************************************************************************
 *  StbM_CloneTime_CallCloneRequest
 *********************************************************************************************************************/
/*! \brief       Call all clone requests for a source time base.
 *  \details     -
 *  \param[in]   sourceTimeBaseIdx, time base index of source time base.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \unit        CloneTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_CloneTime_CallCloneRequest(
        StbM_SynchronizedTimeBaseType sourceTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

#   if (STBM_CONFIG_TIMEOUT == STD_ON)
/**********************************************************************************************************************
 *  StbM_CloneTime_RemovePendingCloneRequest
 *********************************************************************************************************************/
/*! \brief       Call all clone requests for a source time base.
 *  \details     -
 *  \param[in]   sourceTimeBaseIdx, time base index of source time base.
 *  \param[in]   sourcePartitionIdx, Partition Index of source time base for cloning.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \unit        CloneTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_CloneTime_RemovePendingCloneRequest(
        StbM_SynchronizedTimeBaseType sourceTimeBaseIdx,
        StbM_PartitionIdentifiersIterType sourcePartitionIdx);
#   endif /* (STBM_CONFIG_TIMEOUT == STD_ON) */
#  endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_CloneTime_GetCloneSourceTimeBase
 *********************************************************************************************************************/
/*! \brief       Return the clone source timeBaseIdx of a destination timeBaseIdx.
 *  \details     -
 *  \param[in]   destinationTimeBaseIdx, time base index of destination time base.
 *  \param[in]   partitionIdx, valid partition index.
 *  \param[out]  sourceTimeBaseIdx, time base index of source time base.
 *  \return      E_OK, if there is a clone source Time Base
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        CloneTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_CloneTime_GetCloneSourceTimeBase(
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx,
        P2VAR(StbM_SynchronizedTimeBaseType, AUTOMATIC, STBM_APPL_VAR) sourceTimeBaseIdx);

/**********************************************************************************************************************
 *  StbM_CloneTime_ProcessCloneRequest
 *********************************************************************************************************************/
/*! \brief       Clone user data, time value and rate correction value if applicable.
 *  \details     -
 *  \param[in]   destinationTimeBaseIdx, time base index of destination time base.
 *  \param[in]   partitionIdx, valid partition index.
 *  \param[in]   cloneCfg, Refines how source Time Base is cloned to destination.
 *  \param[in]   statusMask, Status flags mask for definition of relevant status flags.
 *  \param[in]   statusValue, Status flags value define whether cloning shall take place.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        CloneTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_CloneTime_ProcessCloneRequest(
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx,
        StbM_CloneConfigType cloneCfg,
        StbM_TimeBaseStatusType statusMask,
        StbM_TimeBaseStatusType statusValue);
# endif /* (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON) */
#endif /* STBM_NOUNIT_CLONETIME */

#ifndef STBM_NOUNIT_TRIGGEREDCUSTOMER /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON)
/**********************************************************************************************************************
 *  Unit: TriggeredCustomer
 *********************************************************************************************************************/
/*! \brief      This unit handles the triggered customer feature.
 *  \details    -
 *  \pre        -
 *  \trace      TRIGGERED_CUSTOMER_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_Init
 *********************************************************************************************************************/
/*! \brief       Initialize TriggeredCustomer unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TriggeredCustomer_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_Update
 *********************************************************************************************************************/
/*! \brief       Trigger triggerable configured customers.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TriggeredCustomer_Update(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_ToOsTicks
 *********************************************************************************************************************/
/*! \brief       Converts microseconds to Os ticks for a given customer.
 *  \details     -
 *  \param[in]   customerIdx, valid customer index.
 *  \param[in]   microseconds, microseconds to convert.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      Os ticks.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TriggeredCustomer
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(TickType, STBM_CODE) StbM_TriggeredCustomer_ToOsTicks(
        StbM_CustomerIdType customerIdx,
        StbM_MicrosecondType microseconds,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_IsTriggerable
 *********************************************************************************************************************/
/*! \brief       Check if customer is triggerable.
 *  \details     Checks if the given customer meets all conditions in order to be triggered.
 *  \param[in]   customerId, valid customer index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if the customer has to be triggered.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TriggeredCustomer
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TriggeredCustomer_IsTriggerable(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_IncrementPeriodCounter
 *********************************************************************************************************************/
/*! \brief      Increment the customer period counter.
 *  \details    This function increments the period counter of the given triggered customers state.
 *  \param[in]  customerIdx, valid customer index.
 *  \param[in]  partitionIdx, valid partition index.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \visibility  Private
 *  \unit        TriggeredCustomer
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TriggeredCustomer_IncrementPeriodCounter(
        StbM_CustomerIdType customerIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */
#endif /* STBM_NOUNIT_TRIGGEREDCUSTOMER */

#ifndef STBM_NOUNIT_STATUSNOTIFICATION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
/**********************************************************************************************************************
 *  Unit: StatusNotification
 *********************************************************************************************************************/
/*! \brief      This unit handles the status notification feature.
 *  \details    -
 *  \pre        -
 *  \trace      STATUS_NOTIFICATION_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_StatusNotification_Init
 *********************************************************************************************************************/
/*! \brief       Initialize StatusNotification unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_StatusNotification_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_StatusNotification_ResetLastStatus
 *********************************************************************************************************************/
/*! \brief       Set the last analyzed status to zero.
 *  \details     -
 *  \param[in]   customerIdx, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        StatusNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_StatusNotification_ResetLastStatus(
        StbM_CustomerIdType customerIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_StatusNotification_ResetEvents
 *********************************************************************************************************************/
/*! \brief       Resets occurred events to zero.
 *  \details     -
 *  \param[in]   customerIdx, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        StatusNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_StatusNotification_ResetEvents(
        StbM_CustomerIdType customerIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_StatusNotification_NotifyCustomers
 *********************************************************************************************************************/
/*! \brief       Notifies configured status notification customers for which configured events occurred.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_StatusNotification_NotifyCustomers(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_StatusNotification_Update
 *********************************************************************************************************************/
/*! \brief       Updates the status notification events for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_StatusNotification_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_StatusNotification_CalculateEventMask
 *********************************************************************************************************************/
/*! \brief       Calculates the status event mask. (Stateless)
 *  \details     Based on the given timebase status, configured status event mask and the requested events, a combined status
 *               event mask is calculated, which can be stored into the related status notification customer event table.
 *  \param[in]   lastTimeBaseStatus, last analyzed timebase status.
 *  \param[in]   timeBaseStatus, time base status of a specific timebase.
 *  \return      calculated status event mask based on timebase status changes.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        StatusNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_TimeBaseNotificationType, STBM_CODE) StbM_StatusNotification_CalculateEventMask(
        StbM_TimeBaseStatusType lastTimeBaseStatus,
        StbM_TimeBaseStatusType timeBaseStatus);

#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_StatusNotification_OnRateCorrectionEvent
 *********************************************************************************************************************/
/*! \brief       Notify that a rate correction event occurred.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_StatusNotification_OnRateCorrectionEvent(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) */

/**********************************************************************************************************************
 *  StbM_StatusNotification_OnReSyncEvent
 *********************************************************************************************************************/
/*! \brief       Notify that a resynchronization event occurred.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_StatusNotification_OnReSyncEvent(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON) */
#endif /* STBM_NOUNIT_STATUSNOTIFICATION */

#ifndef STBM_NOUNIT_TIMEBASE /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: TimeBase
 *********************************************************************************************************************/
/*! \brief      This unit provides function to get basic info of the timebase and the update counter.
 *  \details    Infos are related to the 'type' of the timebase and its role.
 *  \pre        -
 *  \trace      TIME_BASE_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeBase_Init
 *********************************************************************************************************************/
/*! \brief       Initialize the TimeBase unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeBase_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeBase_ResetUpdateCounter
 *********************************************************************************************************************/
/*! \brief       Reset the update counter.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeBase
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeBase_ResetUpdateCounter(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeBase_IncrementUpdateCounter
 *********************************************************************************************************************/
/*! \brief      Increment the timebase update counter by one.
 *  \details    -
 *  \param[in]  timeBaseIdx, valid timebase index.
 *  \param[in]  partitionIdx, valid partition index.
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeBase_IncrementUpdateCounter(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeBase_GetUpdateCounter
 *********************************************************************************************************************/
/*! \brief       Get the current update counter for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_UpdateCounterType, STBM_CODE) StbM_TimeBase_GetUpdateCounter(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if ((STBM_CONFIG_TIME_SLAVE == STD_ON) && (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON))
/**********************************************************************************************************************
 *  StbM_TimeBase_IsSlave
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase is a time slave.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if time slave.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeBase_IsSlave(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* ((STBM_CONFIG_TIME_SLAVE == STD_ON) && (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)) */

# if (((STBM_CONFIG_TIME_SLAVE == STD_ON) && ((STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) || (STBM_HAS_ALLOW_SYSTEM_WIDE_GLOBAL_TIME_MASTER == STD_ON))) || ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)))
/**********************************************************************************************************************
 *  StbM_TimeBase_IsMaster
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase is a global time master.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if master.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeBase_IsMaster(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (((STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) && ((STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_HAS_ALLOW_SYSTEM_WIDE_GLOBAL_TIME_MASTER == STD_ON))) || ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON))) */

# if (((STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) || (STBM_CONFIG_GATEWAY == STD_ON) || (STBM_CONFIG_TIME_RECORDING == STD_ON)) && (STBM_DEV_ERROR_DETECT == STD_ON) && ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))) /* COV_STBM_DEV_ERROR_DETECT_TF_tf_tf_tf_tx_tf_tf */
/**********************************************************************************************************************
 *  StbM_TimeBase_IsSynchronized
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase is a synchronized timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if synchronized timebase.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeBase_IsSynchronized(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (((STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) || (STBM_CONFIG_GATEWAY == STD_ON) || (STBM_CONFIG_TIME_RECORDING == STD_ON)) && (STBM_DEV_ERROR_DETECT == STD_ON) && ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))) */

# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeBase_IsOffset
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase is a offset timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if offset timebase.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeBase_IsOffset(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) */

# if ((STBM_CONFIG_GATEWAY == STD_ON) && ((STBM_CONFIG_TIMEOUT == STD_ON) || (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON)))
/**********************************************************************************************************************
 *  StbM_TimeBase_IsGateway
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase is a gateway.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if gateway.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeBase_IsGateway(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* ((STBM_CONFIG_GATEWAY == STD_ON) && ((STBM_CONFIG_TIMEOUT == STD_ON) || (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON))) */

# if ((STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON) && (STBM_DEV_ERROR_DETECT == STD_ON)) /* COV_STBM_DEV_ERROR_DETECT_TF_tf_tx */
/**********************************************************************************************************************
 *  StbM_TimeBase_IsPure
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase is a pure timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if pure timebase.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeBase_IsPure(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON) && (STBM_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  StbM_TimeBase_GetReferredTimeBase
 *********************************************************************************************************************/
/*! \brief       Get the referred timebase.
 *  \details     If the given timebase is an offset timebase, get the underlying synchronized timebase.
 *               Otherwise return the given timebase.
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \param[out]  referredTimeBaseIdx, valid index of referred timebase or given timebase.
 *  \param[out]  referredPartitionIdx, valid partition index of referred timebase or given timebase.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeBase_GetReferredTimeBase(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx,
        P2VAR(StbM_SynchronizedTimeBaseType, AUTOMATIC, STBM_APPL_VAR) referredTimeBaseIdx,
        P2VAR(StbM_PartitionIdentifiersIterType, AUTOMATIC, STBM_APPL_VAR) referredPartitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeBase_IsTimeBaseIdValid
 *********************************************************************************************************************/
/*! \brief       Check if timebase id is valid.
 *  \details     -
 *  \param[in]   timeBaseId, valid timebase id.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeBase_IsTimeBaseIdValid(
        StbM_SynchronizedTimeBaseType timeBaseId);

/**********************************************************************************************************************
 *  StbM_TimeBase_GetPartitionMapping
 *********************************************************************************************************************/
/*! \brief       Get partition mapping of given timebase.
 *  \details     -
 *  \param[in]   timeBaseId, valid timebase id.
 *  \param[out]  timeBaseIdx, valid timebase index.
 *  \param[out]  partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeBase_GetPartitionMapping(
        StbM_SynchronizedTimeBaseType timeBaseId,
        P2VAR(StbM_SynchronizedTimeBaseType, AUTOMATIC, STBM_APPL_VAR) timeBaseIdx,
        P2VAR(StbM_PartitionIdentifiersIterType, AUTOMATIC, STBM_APPL_VAR) partitionIdx);
#endif /* STBM_NOUNIT_TIMEBASE */

#ifndef STBM_NOUNIT_TIMEOUT /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIMEOUT == STD_ON)
/**********************************************************************************************************************
 *  Unit: Timeout
 *********************************************************************************************************************/
/*! \brief      This unit handles the timeout feature
 *  \details    -
 *  \pre        -
 *  \trace      TIMEOUT_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_Timeout_Init
 *********************************************************************************************************************/
/*! \brief       Initialize the Timeout unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Timeout_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Timeout_Update
 *********************************************************************************************************************/
/*! \brief       Update the Timeout unit.
 *  \details     Checks if any timeout occurred.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Timeout_Update(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Timeout_IsExpired
 *********************************************************************************************************************/
/*! \brief       Check if the timeout is expired.
 *  \details     -
 *  \param[in]   timeoutIdx, valid timeout index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if timeout occurred.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        Timeout
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Timeout_IsExpired(
        uint32 timeoutIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Timeout_IsRunning
 *********************************************************************************************************************/
/*! \brief       Check if the timeout is running.
 *  \details     -
 *  \param[in]   timeoutIdx, valid timeout index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if timeout running.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        Timeout
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Timeout_IsRunning(
        uint32 timeoutIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Timeout_Reset
 *********************************************************************************************************************/
/*! \brief       Reset the timeout counter.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Timeout_Reset(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Timeout_HasTimeoutConfigured
 *********************************************************************************************************************/
/*! \brief       Check if timeout is configured for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        Timeout
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Timeout_HasTimeoutConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIMEOUT == STD_ON) */
#endif /* STBM_NOUNIT_TIMEOUT */

#ifndef STBM_NOUNIT_USERDATA /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: UserData
 *********************************************************************************************************************/
/*! \brief      This unit handles the user data feature
 *  \details    -
 *  \pre        -
 *  \trace      USER_DATA_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_UserData_Init
 *********************************************************************************************************************/
/*! \brief       Initialize the UserData unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_UserData_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_UserData_Get
 *********************************************************************************************************************/
/*! \brief       Get the user data for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[out]  userData, buffer to store the user data.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_UserData_Get(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userData,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_UserData_Set
 *********************************************************************************************************************/
/*! \brief       Set the user data for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid timebase index.
 *  \param[in]   userData, user data to store.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_UserData_Set(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userData,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_UserData_Copy
 *********************************************************************************************************************/
/*! \brief       Copy user data
 *  \details     This function copies user data depending on the user data length of the src param to the dst.
 *  \param[in]   src, the user data to be copied.
 *  \param[out]  dst, destination for the copy operation.
 *  \pre         src.userDataLength <= 3
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        UserData
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_UserData_Copy(P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) src,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) dst);
#endif /* STBM_NOUNIT_USERDATA */

#ifndef STBM_NOUNIT_TIMENOTIFICATION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_NOTIFICATION == STD_ON)
/**********************************************************************************************************************
 *  Unit: TimeNotification
 *********************************************************************************************************************/
/*! \brief      This unit handles the time notification feature
 *  \details    -
 *  \pre        -
 *  \trace      TIME_NOTIFICATION_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeNotification_Init
 *********************************************************************************************************************/
/*! \brief       Initialize the TimeNotification unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeNotification_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_ResetCustomer
 *********************************************************************************************************************/
/*! \brief       Reset the given customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_ResetCustomer(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_Update
 *********************************************************************************************************************/
/*! \brief       Update the TimeNotification unit.
 *  \details     Checks which customer can be started next and starts the Gpt-Timer if necessary.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_Update(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetNextRunnableTimer
 *********************************************************************************************************************/
/*! \brief       Get the next customer ready to start.
 *  \details     -
 *  \param[out]  customerId, index of customer which timer to run next
 *               or STBM_INVALID_TIME_NOTIFICATION_CUSTOMER if no timer ready to run.
 *  \param[out]  partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_GetNextRunnableTimer(
        P2VAR(StbM_CustomerIdType, AUTOMATIC, STBM_APPL_VAR) customerId,
        P2VAR(StbM_PartitionIdentifiersIterType, AUTOMATIC, STBM_APPL_VAR) partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_RunTimer
 *********************************************************************************************************************/
/*! \brief       Starts the Gpt-Timer for the given customer.
 *  \details     Start the Gpt-Timer for the given customer with the remaining time.
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_RunTimer(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_StartTimerImmediately
 *********************************************************************************************************************/
/*! \brief       Starts a task for calling the StbM_NotificationFunction callback function immediately.
 *  \details     This function is used, whenever a customers expiration point is already expired.
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_StartTimerImmediately(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_StartTimer
 *********************************************************************************************************************/
/*! \brief       Start the given customer after the given expire time.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   expireTime, time after which the customer shall be notified.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeNotification_StartTimer(
        StbM_CustomerIdType customerId,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) expireTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_NotifyCustomers
 *********************************************************************************************************************/
/*! \brief       Notify all customers which are ready to be notified.
 *  \details     A customer is ready to be notified, when its expire time is expired.
 *               This function is called from StbM_NotificationFunction callback function.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_NotifyCustomers(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_ProcessTimerCallback
 *********************************************************************************************************************/
/*! \brief       Process the Gpt-Timer callback.
 *  \details     The Gpt-Timer has expired for a customer.
 *               This function is called from StbM_TimerCallback callback function.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_ProcessTimerCallback(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_ActivateTaskForCallback
 *********************************************************************************************************************/
/*! \brief       Activate the task or sets an Event for calling the StbM_NotificationFunction callback function.
 *  \details     -
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_ActivateTaskForCallback(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerStarted
 *********************************************************************************************************************/
/*! \brief       Check if the given timer is in state STBM_NOTIFICATION_TIMER_STARTED.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if customer is in state STBM_NOTIFICATION_TIMER_STARTED.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerStarted(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerRunning
 *********************************************************************************************************************/
/*! \brief       Check if the given timer is in state STBM_NOTIFICATION_TIMER_RUNNING.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if customer is in state STBM_NOTIFICATION_TIMER_RUNNING.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerRunning(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerExpired
 *********************************************************************************************************************/
/*! \brief       Check if the given timer is in state STBM_NOTIFICATION_TIMER_EXPIRED.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if customer is in state STBM_NOTIFICATION_TIMER_EXPIRED.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerExpired(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerStopped
 *********************************************************************************************************************/
/*! \brief       Check if the given timer is in state STBM_NOTIFICATION_TIMER_STOPPED.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if customer is in state STBM_NOTIFICATION_TIMER_STOPPED.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerStopped(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerStarted
 *********************************************************************************************************************/
/*! \brief       Set the given timer is to the state STBM_NOTIFICATION_TIMER_STARTED.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerStarted(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerRunning
 *********************************************************************************************************************/
/*! \brief       Set the given timer is to the state STBM_NOTIFICATION_TIMER_RUNNING.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerRunning(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerExpired
 *********************************************************************************************************************/
/*! \brief       Set the given timer is to the state STBM_NOTIFICATION_TIMER_EXPIRED.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerExpired(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerStopped
 *********************************************************************************************************************/
/*! \brief       Set the given timer is to the state STBM_NOTIFICATION_TIMER_STOPPED.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerStopped(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetThreshold
 *********************************************************************************************************************/
/*! \brief       Get the configured threshold for the given customer.
 *  \details     -
 *  \param[in]   customerId, valid index of customer.
 *  \param[out]  threshold, the configured threshold.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_GetThreshold(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) threshold,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetExpireTime
 *********************************************************************************************************************/
/*! \brief       Set the expire time for given customer (TLexp).
 *  \details     This the absolute time when this customer expires. Not the relative expire time which was passed by
 *               StbM_TimeNotification_StartTimer.
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   expireTime, the expire time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetExpireTime(
        StbM_CustomerIdType customerId,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) expireTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetExpireTime
 *********************************************************************************************************************/
/*! \brief       Get the expire time (TLexp) for given customer.
 *  \details     This the absolute time when this customer expires. Not the relative expire time which was passed by
 *               StbM_TimeNotification_StartTimer.
 *  \param[in]   customerId, valid index of customer.
 *  \param[out]  expireTime, the expire time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_GetExpireTime(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) expireTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetStartTime
 *********************************************************************************************************************/
/*! \brief       Set the time when a Gpt-Timer shall be started for the given customer. (TLstart = TL + exp - threshold).
 *  \details     This the absolute time when this customer expires. Not the relative expire time which was passed by
 *               StbM_TimeNotification_StartTimer.
 *  \param[in]   customerId, valid index of customer.
 *  \param[in]   startTime, the start time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_SetStartTime(
        StbM_CustomerIdType customerId,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) startTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetStartTime
 *********************************************************************************************************************/
/*! \brief       Get the time when a Gpt-Timer shall be started for the given customer. (TLstart = TL + exp - threshold).
 *  \details     This the absolute time when this customer expires. Not the relative expire time which was passed by
 *               StbM_TimeNotification_StartTimer.
 *  \param[in]   customerId, valid index of customer.
 *  \param[out]  startTime, the start time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_GetStartTime(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) startTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetGptTimerRunning
 *********************************************************************************************************************/
/*! \brief       Set the global Gpt-Timer to the state STBM_GPT_TIMER_RUNNING.
 *  \details     -
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetGptTimerRunning(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetGptTimerStopped
 *********************************************************************************************************************/
/*! \brief       Set the global Gpt-Timer to the state STBM_GPT_TIMER_STOPPED.
 *  \details     -
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetGptTimerStopped(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsGptTimerStopped
 *********************************************************************************************************************/
/*! \brief       Set the global Gpt-Timer to the state STBM_GPT_TIMER_STOPPED.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsGptTimerStopped(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerCallbackContext
 *********************************************************************************************************************/
/*! \brief       Indicates if StbM is in timer callback context.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerCallbackContext(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerCallbackContext
 *********************************************************************************************************************/
/*! \brief       Set the current context indication to timer callback.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerCallbackContext(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_ClearTimerCallbackContext
 *********************************************************************************************************************/
/*! \brief       Removes the indication, that StbM is in timer callback context.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_ClearTimerCallbackContext(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsNotificationTaskActivated
 *********************************************************************************************************************/
/*! \brief       Indicates if StbM has activated notification task already.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsNotificationTaskActivated(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetNotificationTaskActivated
 *********************************************************************************************************************/
/*! \brief       Set the indication that StbM has activated task for timer notification already.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetNotificationTaskActivated(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_ClearNotificationTaskActivated
 *********************************************************************************************************************/
/*! \brief       Removes the indication, that StbM has activated the notification task.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_ClearNotificationTaskActivated(void);

/**********************************************************************************************************************
 *  StbM_TimeNotification_CalculateDeviationTime
 *********************************************************************************************************************/
/*! \brief       Calculates the deviation
 *  \details     -
 *  \param[in]   customerId, customer id
 *  \param[out]  deviationTime, calculated deviation time
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeNotification_CalculateDeviationTime(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_TimeDiffType, AUTOMATIC, STBM_APPL_VAR) deviationTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetPartitionMapping
 *********************************************************************************************************************/
/*! \brief       Get partition mapping of given customer.
 *  \details     -
 *  \param[in]   customerId, valid customer id.
 *  \param[out]  customerIdx, valid customer index.
 *  \param[out]  partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_GetPartitionMapping(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_CustomerIdType, AUTOMATIC, STBM_APPL_VAR) customerIdx,
        P2VAR(StbM_PartitionIdentifiersIterType, AUTOMATIC, STBM_APPL_VAR) partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsCustomerIdValid
 *********************************************************************************************************************/
/*! \brief       Check if customer id is valid.
 *  \details     -
 *  \param[in]   customerId, valid customer id.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeNotification
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsCustomerIdValid(
        StbM_CustomerIdType customerId);
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) */
#endif /* STBM_NOUNIT_TIMENOTIFICATION */

#ifndef STBM_NOUNIT_TIMELEAP /* COV_STBM_NOUNIT_SWITCH */
#if (STBM_CONFIG_TIME_LEAP == STD_ON)
/**********************************************************************************************************************
 *  Unit: TimeLeap
 *********************************************************************************************************************/
/*! \brief      This unit handles the time leap feature
 *  \details    -
 *  \pre        -
 *  \trace      TIME_LEAP_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeLeap_Init
 *********************************************************************************************************************/
/*! \brief       Initialize TimeLeap unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_ResetClearCounterFuture
 *********************************************************************************************************************/
/*! \brief       Reset the clear counter future for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_ResetClearCounterFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_ResetClearCounterPast
 *********************************************************************************************************************/
/*! \brief       Reset the clear counter past for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_ResetClearCounterPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_UpdateClearCounterFuture
 *********************************************************************************************************************/
/*! \brief       Update the future clear counter for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_UpdateClearCounterFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_UpdateClearCounterPast
 *********************************************************************************************************************/
/*! \brief       Update the past clear counter for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_UpdateClearCounterPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_IsClearCounterFutureExpired
 *********************************************************************************************************************/
/*! \brief       Check if the future clear counter for the given timebase is expired.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if the counter is expired.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_IsClearCounterFutureExpired(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_IsClearCounterPastExpired
 *********************************************************************************************************************/
/*! \brief       Check if the past clear counter for the given timebase is expired.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if the counter is expired.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_IsClearCounterPastExpired(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_UpdateLeapStatus
 *********************************************************************************************************************/
/*! \brief       Check if a clear counter for the given timebase is expired and reset the status.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_UpdateLeapStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_Update
 *********************************************************************************************************************/
/*! \brief       Update the TimeLeap unit for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_GetFutureThreshold
 *********************************************************************************************************************/
/*! \brief       Get the configured threshold for future time leap of the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      threshold, the configured threshold.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_NanosecondsType, STBM_CODE) StbM_TimeLeap_GetFutureThreshold(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_GetPastThreshold
 *********************************************************************************************************************/
/*! \brief       Get the configured threshold for past time leap of the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      threshold, the configured threshold.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_NanosecondsType, STBM_CODE) StbM_TimeLeap_GetPastThreshold(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_IsTimeLeapFuture
 *********************************************************************************************************************/
/*! \brief       Check if the given time leap exceeds the configured future time leap threshold.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   timeLeap, the time leap to check.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_IsTimeLeapFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeDiffType timeLeap,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_IsTimeLeapPast
 *********************************************************************************************************************/
/*! \brief       Check if the given time leap exceeds the configured past time leap threshold.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   timeLeap, the time leap to check.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_IsTimeLeapPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeDiffType timeLeap,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeLeap_HasTimeLeapConfigured
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase has time leap configured.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeLeap
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_HasTimeLeapConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_LEAP == STD_ON) */
#endif /* STBM_NOUNIT_TIMELEAP */

#ifndef STBM_NOUNIT_TIMERECORDING /* COV_STBM_NOUNIT_SWITCH */
#if (STBM_CONFIG_TIME_RECORDING == STD_ON)
/**********************************************************************************************************************
 *  Unit: TimeRecording
 *********************************************************************************************************************/
/*! \brief      This unit handles the time recording feature
 *  \details    -
 *  \pre        -
 *  \trace      TIME_RECORDING_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeRecording_Init
 *********************************************************************************************************************/
/*! \brief       Initialize TimeRecording unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeRecording_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_Update
 *********************************************************************************************************************/
/*! \brief       Update the TimeRecording unit for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_NotifyCustomers
 *********************************************************************************************************************/
/*! \brief       Notify customers, if measurement is completed.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_NotifyCustomers(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_CommitBlock
 *********************************************************************************************************************/
/*! \brief       Commit atomically the given block index to the given time recording customer
 *  \details     -
 *  \param[in]   timeRecordingIdx, valid index of time recording.
 *  \param[in]   blockIdx, valid block index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_CommitBlock(
        uint16 timeRecordingIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_InitSyncBlocks
 *********************************************************************************************************************/
/*! \brief       Initialize measurement blocks of synchronized timebase recording customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_InitSyncBlocks(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_UpdateSync
 *********************************************************************************************************************/
/*! \brief       Update the TimeRecording unit for the given synchronized timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   beforeUpdateTimestamp, TL before update.
 *  \param[in]   afterUpdateTimestamp, TL after update.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_UpdateSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) beforeUpdateTimestamp,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) afterUpdateTimestamp,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetNextBlockIndex
 *********************************************************************************************************************/
/*! \brief       Get the next available block index of the given timebase customer.
 *  \details     -
 *  \param[in]   timeRecordingIdx, valid index of time recording customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      index of next measurement block. Overflow is handled.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetNextBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetStartBlockIndex
 *********************************************************************************************************************/
/*! \brief       Get the start index of the time recording blocks for the given timebase.
 *  \details     -
 *  \param[in]   timeRecordingIdx, valid index of time recording customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      start index time recording blocks.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetStartBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetEndBlockIndex
 *********************************************************************************************************************/
/*! \brief       Get the end index of the time recording blocks for the given timebase.
 *  \details     -
 *  \param[in]   timeRecordingIdx, valid index of time recording customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      end index time recording blocks.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetEndBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_SetCurrentBlockIndex
 *********************************************************************************************************************/
/*! \brief       Set the current block index of the given timebase customer.
 *  \details     -
 *  \param[in]   timeRecordingIdx, valid index of time recording customer.
 *  \param[in]   index, current index to set.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_SetCurrentBlockIndex(
        uint16 timeRecordingIdx,
        uint32 index,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetCurrentBlockIndex
 *********************************************************************************************************************/
/*! \brief       Get the current block index of the given timebase customer.
 *  \details     -
 *  \param[in]   timeRecordingIdx, valid index of time recording customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      index of current measurement block.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetCurrentBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetOldestBlockIndex
 *********************************************************************************************************************/
/*! \brief       Get the block index with the oldest recorded block data.
 *  \details     -
 *  \param[in]   timeRecordingIdx, valid index of time recording customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      index of oldest block index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetOldestBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetRecordedBlockCount
 *********************************************************************************************************************/
/*! \brief       Get current block count.
 *  \details     -
 *  \param[in]   timeRecordingIdx, valid index of time recording customer.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      current amount of recorded blocks.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint16, STBM_CODE) StbM_TimeRecording_GetRecordedBlockCount(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_IncrementRecordedBlockCount
 *********************************************************************************************************************/
/*! \brief       Increment the recorded block count.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase with time recording configured.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeRecording_IncrementRecordedBlockCount(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_SetPathDelay
 *********************************************************************************************************************/
/*! \brief       Set the path delay for the given synchronized timebase customer.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   pathdelay, the path delay.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_SetPathDelay(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        uint32 pathdelay,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetPathDelay
 *********************************************************************************************************************/
/*! \brief       Get the path delay of the given synchronized timebase customer.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetPathDelay(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetSyncRecordTableHead
 *********************************************************************************************************************/
/*! \brief       Get the time recording header of the given synchronized timebase customer.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[out]  syncTableHead, the header.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_GetSyncRecordTableHead(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_SyncRecordTableHeadType, AUTOMATIC, STBM_APPL_VAR) syncTableHead,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetSyncRecordTableBlock
 *********************************************************************************************************************/
/*! \brief       Get the measurement block with the given block index.
 *  \details     -
 *  \param[in]   blockIdx, valid block index.
 *  \param[out]  syncTableBlock, the measurement block.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_GetSyncRecordTableBlock(
        uint32 blockIdx,
        P2VAR(StbM_SyncRecordTableBlockType, AUTOMATIC, STBM_APPL_VAR) syncTableBlock,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_IsConfigured
 *********************************************************************************************************************/
/*! \brief       Check if time recording is configured for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeRecording_IsConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

#  if (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeRecording_InitOffsetBlocks
 *********************************************************************************************************************/
/*! \brief       Initialize measurement blocks of offset timebase recording customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_InitOffsetBlocks(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_UpdateOffset
 *********************************************************************************************************************/
/*! \brief       Update the TimeRecording unit for the given offset timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   afterUpdateTimeStamp, TL after update.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_UpdateOffset(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) afterUpdateTimeStamp,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetOffsetRecordTableHead
 *********************************************************************************************************************/
/*! \brief       Get the time recording header of the given offset timebase customer.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[out]  offsetTableHead, the header.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_GetOffsetRecordTableHead(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_OffsetRecordTableHeadType, AUTOMATIC, STBM_APPL_VAR) offsetTableHead,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetOffsetRecordTableBlock
 *********************************************************************************************************************/
/*! \brief       Get the measurement block with the given block index.
 *  \details     -
 *  \param[in]   blockIdx, valid block index.
 *  \param[out]  offsetTableBlock, the measurement block.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeRecording
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_GetOffsetRecordTableBlock(
        uint32 blockIdx,
        P2VAR(StbM_OffsetRecordTableBlockType, AUTOMATIC, STBM_APPL_VAR) offsetTableBlock,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON) */
# endif  /* (STBM_CONFIG_TIME_RECORDING == STD_ON) */
#endif /* STBM_NOUNIT_TIMERECORDING */

#ifndef STBM_NOUNIT_TIMEVALIDATION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_VALIDATION == STD_ON)
/**********************************************************************************************************************
 *  Unit: TimeValidation
 *********************************************************************************************************************/
/*! \brief      This unit handles the time validation feature
 *  \details    -
 *  \pre        -
 *  \trace      TIME_VALIDATION_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeValidation_Init
 *********************************************************************************************************************/
/*! \brief       Initialize TimeValidation unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthBlocks
 *********************************************************************************************************************/
/*! \brief       Initialize ethernet blocks of synchronized timebase validation customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_InitEthBlocks(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthStates
 *********************************************************************************************************************/
/*! \brief       Initialize ethernet states of synchronized timebase validation customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_InitEthStates(StbM_PartitionIdentifiersIterType partitionIdx);

#  if (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthMasterBlocks
 *********************************************************************************************************************/
/*! \brief       Initialize ethernet master blocks of synchronized timebase validation customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_InitEthMasterBlocks(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthMasterStates
 *********************************************************************************************************************/
/*! \brief       Initialize ethernet master states of synchronized timebase validation customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_InitEthMasterStates(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnSetEthMasterTimingData
 *********************************************************************************************************************/
/*! \brief       Set ethernet master timing data.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   measureDataPtr, forwarded pointer from EthTsyn.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_OnSetEthMasterTimingData(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_EthTimeMasterMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnSetEthPdelayResponderData
*********************************************************************************************************************/
/*! \brief       Set ethernet pdelay responder data.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   measureDataPtr, forwarded pointer from EthTsyn.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
*********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_OnSetEthPdelayResponderData(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_PdelayResponderMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_GetMasterIndex
 *********************************************************************************************************************/
/*! \brief       Selection of the correct master for further measurement data processing.
 *  \details     Get master index if available, otherwise store the master if free slots are available and return the index.
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   portId, port identifier from received measurement type.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      master index which size has to be checked
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL FUNC(uint16, STBM_CODE) StbM_TimeValidation_GetMasterIndex(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_PortIdType, AUTOMATIC, STBM_APPL_DATA) portId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_NotifyEthMasterCustomers
 *********************************************************************************************************************/
/*! \brief       Notify ethernet master customers.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_NotifyEthMasterCustomers(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnNotifyEthMasterMeasurementData
 *********************************************************************************************************************/
/*! \brief       Notify ethernet master customers (MasterMeasurementData), if measurement is completed.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_OnNotifyEthMasterMeasurementData(
        uint16 timeValidationIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnNotifyEthMasterPdelayResponderData
 *********************************************************************************************************************/
/*! \brief       Notify ethernet master customers (PdelayResponderData), if measurement is completed.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_OnNotifyEthMasterPdelayResponderData(
        uint16 timeValidationIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_CommitEthMasterTimeValidationBlock
 *********************************************************************************************************************/
/*! \brief       Commit atomically the given block index to the given time validation customer (MasterTimeValidationBlock).
 *  \details     -
 *  \param[in]   timeValidationIdx, valid index of time validation.
 *  \param[in]   blockIdx, valid block index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_CommitEthMasterTimeValidationBlock(
        uint16 timeValidationIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_CommitEthPdelayResponderTimeValidationBlock
 *********************************************************************************************************************/
/*! \brief       Commit atomically the given block index to the given time validation customer (PdelayResponderTimeValidationBlock).
 *  \details     -
 *  \param[in]   timeValidationIdx, valid index of time validation.
 *  \param[in]   blockIdx, valid block index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_CommitEthPdelayResponderTimeValidationBlock(
        uint16 timeValidationIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

#   if (STBM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_IsMasterConfigured
 *********************************************************************************************************************/
/*! \brief       Check if time validation for master is configured for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \return      true, if time validation for master is configured.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeValidation_IsMasterConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#   endif
#  endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_TimeValidation_NotifyCustomers
 *********************************************************************************************************************/
/*! \brief       Notify time validation customers.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_NotifyCustomers(StbM_PartitionIdentifiersIterType partitionIdx);

#  if (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthSlaveBlocks
 *********************************************************************************************************************/
/*! \brief       Initialize ethernet slave blocks of synchronized timebase validation customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_InitEthSlaveBlocks(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthSlaveStates
 *********************************************************************************************************************/
/*! \brief       Initialize ethernet slave states of synchronized timebase validation customer.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_InitEthSlaveStates(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnSetEthSlaveTimingData
 *********************************************************************************************************************/
/*! \brief       Set ethernet slave timing data.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   measureDataPtr, forwarded pointer from EthTsyn.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_OnSetEthSlaveTimingData(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_EthTimeSlaveMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnSetEthPdelayInitiatorData
 *********************************************************************************************************************/
/*! \brief       Set ethernet pdelay initiator data.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   measureDataPtr, forwarded pointer from EthTsyn.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_OnSetEthPdelayInitiatorData(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_PdelayInitiatorMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_NotifyEthSlaveCustomers
 *********************************************************************************************************************/
/*! \brief       Notify ethernet slave customers.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_NotifyEthSlaveCustomers(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnNotifyEthSlaveMeasurementData
 *********************************************************************************************************************/
/*! \brief       Notify ethernet slave customers (SlaveMeasurementData), if measurement is completed.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_OnNotifyEthSlaveMeasurementData(
        uint16 timeValidationIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnNotifyEthSlavePdelayInitiatorData
 *********************************************************************************************************************/
 /*! \brief      Notify ethernet slave customers (PdelayInitiatorData), if measurement is completed.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_OnNotifyEthSlavePdelayInitiatorData(
        uint16 timeValidationIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_CommitEthSlaveTimeValidationBlock
 *********************************************************************************************************************/
 /*! \brief      Commit atomically the given block index to the given time validation customer (SlaveTimeValidationBlock).
 *  \details     -
 *  \param[in]   timeValidationIdx, valid index of time validation.
 *  \param[in]   blockIdx, valid block index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_CommitEthSlaveTimeValidationBlock(
        uint16 timeValidationIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_CommitEthPdelayInitiatorTimeValidationBlock
 *********************************************************************************************************************/
 /*! \brief      Commit atomically the given block index to the given time validation customer (PdelayInitiatorTimeValidationBlock).
 *  \details     -
 *  \param[in]   timeValidationIdx, valid index of time validation.
 *  \param[in]   blockIdx, valid block index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_CommitEthPdelayInitiatorTimeValidationBlock(
        uint16 timeValidationIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

#   if (STBM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_IsSlaveConfigured
 *********************************************************************************************************************/
/*! \brief       Check if time validation for slave is configured for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \return      true, if time validation for slave is configured.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeValidation_IsSlaveConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#   endif
#  endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_TimeValidation_GetNextBlockIndex
 *********************************************************************************************************************/
/*! \brief       Get the next available block index of the given timebase customer.
 *  \details     -
 *  \param[in]   startBlockIdx, start block element from time validation customer.
 *  \param[in]   endBlockIdx, end block element from time validation customer.
 *  \param[in]   currentBlockIdx, current block element from time validation customer.
 *  \return      index of next measurement block. Overflow is handled.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_TimeValidation_GetNextBlockIndex(uint32 startBlockIdx, uint32 endBlockIdx,
        uint32 currentBlockIdx);

/**********************************************************************************************************************
 *  StbM_TimeValidation_GetOldestBlockIndex
 *********************************************************************************************************************/
/*! \brief       Get the block index with the oldest recorded block data.
 *  \details     -
 *  \param[in]   startBlockIdx, start block element from time validation customer.
 *  \param[in]   endBlockIdx, end block element from time validation customer.
 *  \param[in]   currentBlockIdx, current block element from time validation customer.
 *  \param[in]   recordedBlockCount, number of recorded element of time validation customer.
 *  \return      index of oldest block index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL FUNC(uint32, STBM_CODE) StbM_TimeValidation_GetOldestBlockIndex(
        uint32 startBlockIdx,
        uint32 endBlockIdx,
        uint32 currentBlockIdx,
        uint32 recordedBlockCount);

#  if (STBM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_IsConfigured
 *********************************************************************************************************************/
/*! \brief       Check if time validation is configured for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \return      true, if time validation is configured.
 *  \context     TASK
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeValidation
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeValidation_IsConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif
# endif /* (STBM_CONFIG_TIME_VALIDATION == STD_ON) */
#endif /* STBM_NOUNIT_TIMEVALIDATION */

#ifndef STBM_NOUNIT_TIMECORRECTION /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: TimeCorrection
 *********************************************************************************************************************/
/*! \brief      This unit handles the time correction feature
 *  \details    -
 *  \pre        -
 *  \trace      TIME_CORRECTION_UNIT
 *********************************************************************************************************************/

# if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON))
/**********************************************************************************************************************
*  StbM_TimeCorrection_Init
*********************************************************************************************************************/
/*! \brief       Initialize TimeCorrection unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_Init(StbM_PartitionIdentifiersIterType partitionIdx);

#  if (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeCorrection_ResetRate
 *********************************************************************************************************************/
/*! \brief       Reset the rate for time correction depending upon the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_ResetRate(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateDeviation
 *********************************************************************************************************************/
/*! \brief       Get the current rate deviation of the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      rate deviation
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(StbM_RateDeviationType, STBM_CODE) StbM_TimeCorrection_GetRateDeviation(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRate
 *********************************************************************************************************************/
/*! \brief       Get the rate for time correction depending upon the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      rate, the rate or 0 if not configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_GetRate(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsRateDeviationValid
 *********************************************************************************************************************/
/*! \brief       Check if current rate deviation is valid.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if valid.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsRateDeviationValid(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_HasTimeCorrectionConfigured
 *********************************************************************************************************************/
/*! \brief       Check if given timebase has time correction configured.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \return      true, if configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeCorrection_HasTimeCorrectionConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured
 *********************************************************************************************************************/
/*! \brief       Check if given slave timebase has time correction configured.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) */

#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeCorrection_InitMaster
 *********************************************************************************************************************/
/*! \brief       Initialize TimeCorrection unit for global time masters.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_InitMaster(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_HasTimeCorrectionMasterConfigured
 *********************************************************************************************************************/
/*! \brief       Check if given master timebase has time correction configured.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_HasTimeCorrectionMasterConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_SetRateMaster
 *********************************************************************************************************************/
/*! \brief       Set the rate for the given global time master.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   rateDeviation, rate.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_SetRateMaster(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_RateDeviationType rateDeviation,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateMaster
 *********************************************************************************************************************/
/*! \brief       Get the rate of the given global time master.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of master timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      the rate deviation.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_GetRateMaster(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsAllowMasterRateCorrection
 *********************************************************************************************************************/
/*! \brief       Check if given global time master is allowed to set the rate correction.
 *  \details     -
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsAllowMasterRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) */

#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeCorrection_InitSlave
 *********************************************************************************************************************/
/*! \brief       Initialize TimeCorrection unit for time slave.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_InitSlave(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_InitRateMeasurement
 *********************************************************************************************************************/
/*! \brief       Initialize rate measurement.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_InitRateMeasurement(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_Update
 *********************************************************************************************************************/
/*! \brief       Update the TimeCorrection unit.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_UpdateRateCorrection
 *********************************************************************************************************************/
/*! \brief       Update rate correction for the given timebase.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_UpdateRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_UpdateOffsetRateCorrection
 *********************************************************************************************************************/
/*! \brief       Update offset rate correction for the given timebase.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_UpdateOffsetRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_ResetOffsetRateCorrection
 *********************************************************************************************************************/
/*! \brief       Reset the state of offset rate correction
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_ResetOffsetRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsOffsetRateCorrectionValid
 *********************************************************************************************************************/
/*! \brief       Check if offset rate correction is valid.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true if valid, false otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsOffsetRateCorrectionValid(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_StartNewRateMeasurement
 *********************************************************************************************************************/
/*! \brief       Start a new measurement for the given timebase, if possible.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_StartNewRateMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_StopExpiredRateMeasurement
 *********************************************************************************************************************/
/*! \brief       Stop expired rate measurements for the given timebase, if needed.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_StopExpiredRateMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_StopInvalidRateMeasurement
 *********************************************************************************************************************/
/*! \brief       Stop invalid rate measurements for the given timebase, if needed.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_StopInvalidRateMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_StopRateMeasurement
 *********************************************************************************************************************/
/*! \brief       Stop rate measurements for the given timebase, if needed.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_StopRateMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_DidSyncToGatewayStateChanged
 *********************************************************************************************************************/
/*! \brief       Check if the gateway bit changed according to current rate measurement.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if changed.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_DidSyncToGatewayStateChanged(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsRateMeasurementValid
 *********************************************************************************************************************/
/*! \brief       Check if rate measurement is valid for the given timebase.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if valid.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsRateMeasurementValid(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_CalculateRateForRateCorrectionSlave
 *********************************************************************************************************************/
/*! \brief       Calculate rate for rate correction.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   rateMeasurementIdx, index of rate measurement.
 *  \param[out]  rate, calculated rate.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeCorrection_CalculateRateForRateCorrectionSlave(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        uint32 rateMeasurementIdx,
        P2VAR(StbM_InternalRateType, AUTOMATIC, STBM_APPL_VAR) rate,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_CalculateRateForOffsetRateCorrectionSlave
 *********************************************************************************************************************/
/*! \brief       Calculate rate for offset rate correction.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      rate, calculated rate
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_CalculateRateForOffsetRateCorrectionSlave(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_SetRateForRateCorrectionSlave
 *********************************************************************************************************************/
/*! \brief       Set the rate for rate correction, of the given timebase.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   rate, the rate to set.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_SetRateForRateCorrectionSlave(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_InternalRateType rate,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_SetRateForOffsetRateCorrection
 *********************************************************************************************************************/
/*! \brief       Set the rate for offset rate correction, of the given timebase.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   rate, the rate to set.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_SetRateForOffsetRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_InternalRateType rate,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateForRateCorrection
 *********************************************************************************************************************/
/*! \brief       Get the rate for rate correction, of the given timebase.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      rate, the rate or 1 if not configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_GetRateForRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateForOffsetRateCorrection
 *********************************************************************************************************************/
/*! \brief       Get the rate for offset rate correction, of the given timebase.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      rate, the rate or 0 if not configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_GetRateForOffsetRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetOffsetCorrectionAdaptionInterval
 *********************************************************************************************************************/
/*! \brief       Get the offset rate correction adaption interval of the given timebase.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      Tcorr_int or 0 if not configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_NanosecondsType, STBM_CODE) StbM_TimeCorrection_GetOffsetCorrectionAdaptionInterval(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateCorrectionMeasurementDuration
 *********************************************************************************************************************/
/*! \brief       Get the rate correction measurement duration.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase with time correction for slave configured.
 *  \param[out]  rateMeasurementDuration, the measurement duration.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_GetRateCorrectionMeasurementDuration(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) rateMeasurementDuration,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetDistanceForNextParallelRateCorrectionMeasurement
 *********************************************************************************************************************/
/*! \brief       Get the distance to start the next parallel rate measurement.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, valid index of timebase with time correction for slave configured.
 *  \param[out]  distance, the distance.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_GetDistanceForNextParallelRateCorrectionMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) distance,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetJumpThreshold
 *********************************************************************************************************************/
/*! \brief       Get the configured jump threshold.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      jump threshold or 0 if not configured.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_NanosecondsType, STBM_CODE) StbM_TimeCorrection_GetJumpThreshold(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsJumpWithinJumpThreshold
 *********************************************************************************************************************/
/*! \brief       Check if jump is within configured boundaries.
 *  \details     This is only relevant for time slave.
 *  \param[in]   timeBaseIdx, index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true if jump was valid.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsJumpWithinJumpThreshold(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */
# endif /* (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) */

# if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON))
/**********************************************************************************************************************
 *  StbM_TimeCorrection_CloneRateValue
 *********************************************************************************************************************/
/*! \brief       Copy rate value from source time base to destination time base
 *  \details     -
 *  \param[in]   destinationTimeBaseIdx, time base index of destination time base.
 *  \param[in]   sourceTimeBaseIdx, time base index of source time base.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  public
 *  \unit        TimeCorrection
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_CloneRateValue(
        StbM_SynchronizedTimeBaseType sourceTimeBaseIdx,
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON) */
#endif /* STBM_NOUNIT_TIMECORRECTION */

#ifndef STBM_NOUNIT_STATUS /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: Status
 *********************************************************************************************************************/
/*! \brief      This unit handles the status feature
 *  \details    -
 *  \pre        -
 *  \trace      STATUS_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_Status_Init
 *********************************************************************************************************************/
/*! \brief       Initialize Status unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_Init(StbM_PartitionIdentifiersIterType partitionIdx);

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_Update
 *********************************************************************************************************************/
/*! \brief       Update the Status unit.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   timeBaseStatus, status.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeBaseStatusType timeBaseStatus,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_ResetStatusLocalTime
 *********************************************************************************************************************/
/*! \brief       Reset the status of the local time for the given timebase status index.
 *  \details     -
 *  \param[in]   statusIdx, valid timebase status index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        Status
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ResetStatusLocalTime(
        uint16 statusIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_ClearLocalStatus
 *********************************************************************************************************************/
/*! \brief       Clear the status of the local time for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ClearLocalStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_SetLocalTimeStatus
 *********************************************************************************************************************/
/*! \brief       Set the status of the local time for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   timeBaseStatus, status.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        Status
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_Status_SetLocalTimeStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeBaseStatusType timeBaseStatus,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Status_GetLocalTimeStatus
 *********************************************************************************************************************/
/*! \brief       Get the status of the local time for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      status.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(StbM_TimeBaseStatusType, STBM_CODE) StbM_Status_GetLocalTimeStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_GetLocalTimeStatusCombined
 *********************************************************************************************************************/
/*! \brief       Get the combined status of the local time for the given offset timebase.
 *  \details     Combines the status of the given timebase and its underlying synchronized timebase.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      combined status.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(StbM_TimeBaseStatusType, STBM_CODE) StbM_Status_GetLocalTimeStatusCombined(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Status_CalculateCombinedStatus
 *********************************************************************************************************************/
/*! \brief       Calculate the combined status.
 *  \details     -
 *  \param[in]   syncStatus, status of underlying synchronized timebase.
 *  \param[in]   offsetStatus, status of offset timebase.
 *  \return      combined status.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        Status
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_TimeBaseStatusType, STBM_CODE) StbM_Status_CalculateCombinedStatus(
        StbM_TimeBaseStatusType syncStatus,
        StbM_TimeBaseStatusType offsetStatus);
# endif /* (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_ResetStatusGlobalTime
 *********************************************************************************************************************/
/*! \brief       Reset the status of the global time for the given timebase status index.
 *  \details     -
 *  \param[in]   statusIdx, valid timebase status index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        Status
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ResetStatusGlobalTime(
        uint16 statusIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_SetGlobalTimeSyncStatus
 *********************************************************************************************************************/
/*! \brief       Set the status of the global time for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   timeBaseStatus, status.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetGlobalTimeSyncStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeBaseStatusType timeBaseStatus,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Status_GetGlobalTimeSyncStatus
 *********************************************************************************************************************/
/*! \brief       Get the status of the global time for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      status.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_TimeBaseStatusType, STBM_CODE) StbM_Status_GetGlobalTimeSyncStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_SetSynchronized
 *********************************************************************************************************************/
/*! \brief       Set synchronized status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_Status_SetSynchronized(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if ((STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) || (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsSynchronized
 *********************************************************************************************************************/
/*! \brief       Check if given timebase has synchronized status flag set.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if synchronized.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Status_IsSynchronized(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) || (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) */

# if (STBM_CONFIG_TIMEOUT == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_ClearTimeout
 *********************************************************************************************************************/
/*! \brief       Clear timeout status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ClearTimeout(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Status_SetTimeout
 *********************************************************************************************************************/
/*! \brief       Set timeout status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetTimeout(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsTimeout
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase has timeout status flag set.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if timeout flag is set.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Status_IsTimeout(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */
# endif /* (STBM_CONFIG_TIMEOUT == STD_ON) */

# if (STBM_CONFIG_TIME_LEAP == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_ClearTimeLeapFuture
 *********************************************************************************************************************/
/*! \brief       Clear time leap future status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ClearTimeLeapFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Status_SetTimeLeapFuture
 *********************************************************************************************************************/
/*! \brief       Set time leap future status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetTimeLeapFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsTimeLeapFuture
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase has time leap future status flag set.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if time leap future flag is set.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        Status
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Status_IsTimeLeapFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_ClearTimeLeapPast
 *********************************************************************************************************************/
/*! \brief       Clear time leap past status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ClearTimeLeapPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_Status_SetTimeLeapPast
 *********************************************************************************************************************/
/*! \brief       Set time leap past status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetTimeLeapPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsTimeLeapPast
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase has time leap past status flag set.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if time leap past flag is set.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        Status
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Status_IsTimeLeapPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */

#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsTimeLeap
 *********************************************************************************************************************/
/*! \brief       Check if the given timebase has time leap status flag set.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if time leap past or time leap future flag is set.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Status_IsTimeLeap(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */
# endif /* (STBM_CONFIG_TIME_LEAP == STD_ON) */

# if ((STBM_CONFIG_GATEWAY == STD_ON) && (STBM_CONFIG_TIMEOUT == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_SetSyncToGateway
 *********************************************************************************************************************/
/*! \brief       Set gateway status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetSyncToGateway(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_GATEWAY == STD_ON) && (STBM_CONFIG_TIMEOUT == STD_ON) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_UpdateSyncToGatewayStatus
 *********************************************************************************************************************/
/*! \brief       Update gateway status flag for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_UpdateSyncToGatewayStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */
#endif /* STBM_NOUNIT_STATUS */

#ifndef STBM_NOUNIT_LOCALTIME /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: LocalTime
 *********************************************************************************************************************/
/*! \brief      This unit handles the local time feature
 *  \details    -
 *  \pre        -
 *  \trace      LOCAL_TIME_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_LocalTime_Init
 *********************************************************************************************************************/
/*! \brief       Initialize LocalTime unit.
 *  \details     -
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_Init(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetLocalTime
 *********************************************************************************************************************/
/*! \brief       Reset the local time (TL) of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetLocalTime(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetLocalTimeSync
 *********************************************************************************************************************/
/*! \brief       Reset the local time sync (TLsync) of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetLocalTimeSync(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetGlobalTimeSync
 *********************************************************************************************************************/
/*! \brief       Reset the global sync time (TGsync) of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetGlobalTimeSync(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetGlobalTimeRx
 *********************************************************************************************************************/
/*! \brief       Reset the received global time (TGrx) of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetGlobalTimeRx(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Reset the virtual local time (TV) of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         timebase needs to have a local clock.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetVirtualLocalTime(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetVirtualLocalTimeSync
 *********************************************************************************************************************/
/*! \brief       Reset the virtual local time sync (TVsync) of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         timebase needs to have a local clock.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetVirtualLocalTimeSync(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetVirtualLocalTimeElapsedAfterAdaptionInterval
 *********************************************************************************************************************/
/*! \brief       Reset the virtual local time elapsed after adaption interval of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         timebase needs to have a local clock.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetVirtualLocalTimeElapsedAfterAdaptionInterval(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_ResetVirtualLocalTimeRx
 *********************************************************************************************************************/
/*! \brief       Reset the received virtual local time (TVrx) of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         timebase needs to have a local clock.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetVirtualLocalTimeRx(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* STBM_CONFIG_TIME_SLAVE == STD_ON */

/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateLocalTime
 *********************************************************************************************************************/
/*! \brief       Calculate the (corrected) local time of the given timebase valid at given virtual local time.
 *  \details     If time correction is configured for the given timebase, the time is corrected.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   virtualLocalTime, virtual local time.
 *  \param[out]  localTime, (corrected) local time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_CalculateLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetLocalTime
 *********************************************************************************************************************/
/*! \brief       Get the (corrected) local time of the given timebase valid at given virtual local time.
 *  \details     If time correction is configured for the given timebase, the time is corrected.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   virtualLocalTime, virtual local time.
 *  \param[out]  localTime, (corrected) local time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if ((STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) || (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_GetLastUpdatedLocalTime
 *********************************************************************************************************************/
/*! \brief       Get the latest calculated (corrected) local time of the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  localTime, (corrected) local time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if the last updated time is valid.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetLastUpdatedLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTime,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) || (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_GetLocalTimeSync
 *********************************************************************************************************************/
/*! \brief       Get the local time sync (TLsync).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  localTimeSync, TLsync.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetLocalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_SetLocalTimeSync
 *********************************************************************************************************************/
/*! \brief       Set the local time sync (TLsync).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   localTimeSync, TLsync.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetLocalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) localTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetGlobalTimeRx
 *********************************************************************************************************************/
/*! \brief       Get the received global time (TGrx).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  globalTimeRx, TGrx.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetGlobalTimeRx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimeRx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_SetGlobalTimeRx
 *********************************************************************************************************************/
/*! \brief       Set the received global time (TGrx).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   globalTimeRx, TGrx.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetGlobalTimeRx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimeRx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetGlobalTimeSync
 *********************************************************************************************************************/
/*! \brief       Get the global time sync (TGsync).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  globalTimeSync, TGsync.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetGlobalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_SetGlobalTimeSync
 *********************************************************************************************************************/
/*! \brief       Set the global time sync (TGsync).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   globalTimeSync, TGsync.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetGlobalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) && (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateOffsetValue
 *********************************************************************************************************************/
/*! \brief       Calculate the offset value (TOL) of the given offset timebase based on the given global time.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   globalTime, TG.
 *  \param[out]  offsetValue, TOL.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_CalculateOffsetValue(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTime,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) offsetValue,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) && (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_ResetTimeLeap
 *********************************************************************************************************************/
/*! \brief       Reset the time leap of the given timebase local time index.
 *  \details     -
 *  \param[in]   localTimeId, valid timebase local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetTimeLeap(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateTimeLeap
 *********************************************************************************************************************/
/*! \brief       Calculate the time leap TG - TL.
 *  \details     -
 *  \param[in]   globalTime, the global time.
 *  \param[in]   localTime, the local time.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_TimeDiffType, STBM_CODE) StbM_LocalTime_CalculateTimeLeap(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTime,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) localTime);

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateTimeLeap
 *********************************************************************************************************************/
/*! \brief       Update the time leap TG - TL.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_UpdateTimeLeap(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetTimeLeap
 *********************************************************************************************************************/
/*! \brief       Get the time leap, if already calcualted.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      time leap.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_TimeDiffType, STBM_CODE) StbM_LocalTime_GetTimeLeap(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_SetTimeLeap
 *********************************************************************************************************************/
/*! \brief       Set the time leap.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   timeLeap, the time leap.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetTimeLeap(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeDiffType timeLeap,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_IsTimeLeapValid
 *********************************************************************************************************************/
/*! \brief       Check if the calculated time leap is valid
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true if valid
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_LocalTime_IsTimeLeapValid(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateLocalTime
 *********************************************************************************************************************/
/*! \brief       Update the local time of all timebases.
 *  \details     Updates the local clock source and stores the local time. It also ensures the 3s update of the main time tuple.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_UpdateLocalTime(StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_Update
 *********************************************************************************************************************/
/*! \brief       Update the local time unit.
 *  \details     Get hardware counter and calculate the new virtual local time.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateMainTimeTuple
 *********************************************************************************************************************/
/*! \brief       Update the main time tuple.
 *  \details     Update TGsync and TVsync.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   globalTimePtr, new global time.
 *  \param[in]   localTimePtr, new virtual local time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_UpdateMainTimeTuple(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) localTimePtr,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateMainTimeTupleAfterBusReceive
 *********************************************************************************************************************/
/*! \brief       Update the main time tuple after time receive from bus.
 *  \details     Update TGsync and TVsync.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_UpdateMainTimeTupleAfterBusReceive(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateReceivedTimeTuple
 *********************************************************************************************************************/
/*! \brief       Update the received time tuple.
 *  \details     Update TGrx and TVrx.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   globalTimePtr, received global time.
 *  \param[in]   localTimePtr, received virtual local time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateReceivedTimeTuple(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) localTimePtr,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateUpdatedReceivedGlobalTime
 *********************************************************************************************************************/
/*! \brief       Correct received global time by rate corrected sync reception delay.
 *  \details     Update TGrx by rate corrected sync reception delay.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   globalTimePtr, received global time.
 *  \param[in]   receptionDelayPtr, reception delay of sync message.
 *  \param[out]  updatedGlobalTimePtr, global time corrected by reception delay.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_CalculateUpdatedReceivedGlobalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) receptionDelayPtr,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) updatedGlobalTimePtr,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateSynclocalTimeTuple
 *********************************************************************************************************************/
/*! \brief       Update the synclocal time tuple.
 *  \details     Update TLsync and TVsync.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateSynclocalTimeTuple(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_SynchronizeVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Synchronize the virtual local time to virtual local time sync (TVsync).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   virtualLocalTimeSync, TVsync.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SynchronizeVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateAfterMainTimeTupleTimeout
 *********************************************************************************************************************/
/*! \brief       Update the local time unit after timeout of the main time tuple.
 *  \details     Update TGsync and TVsync if timeout of main time tuple occurred.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_UpdateAfterMainTimeTupleTimeout(
        StbM_PartitionIdentifiersIterType partitionIdx);

# if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateAfterOffsetCorrectionAdaptionInterval
 *********************************************************************************************************************/
/*! \brief       Update the local time unit after offset correction adaption interval.
 *  \details     Update TGsync and TVsync after offset correction adaption interval.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   virtualLocalTime, TV.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateAfterOffsetCorrectionAdaptionInterval(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) */

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Update the virtual local time by the given elapsed time for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   elapsedTime, elapsed time.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) elapsedTime,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Get the virtual local time (TV).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  virtualLocalTime, TV.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTimeSync
 *********************************************************************************************************************/
/*! \brief       Get the virtual local time sync (TVsync).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  virtualLocalTime, TVsync.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetVirtualLocalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_SetVirtualLocalTimeSync
 *********************************************************************************************************************/
/*! \brief       Set the virtual local time sync (TVsync).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   virtualLocalTimeSync, TVsync.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SetVirtualLocalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTimeRx
 *********************************************************************************************************************/
/*! \brief       Get the received virtual local time (TVrx).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  virtualLocalTime, TVrx.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetVirtualLocalTimeRx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_SetVirtualLocalTimeRx
 *********************************************************************************************************************/
/*! \brief       Set the received virtual local time (TVrx).
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   virtualLocalTimeRx, TVrx.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetVirtualLocalTimeRx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTimeRx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* STBM_CONFIG_TIME_SLAVE == STD_ON */

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTimeElapsedAfterAdaptionInterval
 *********************************************************************************************************************/
/*! \brief       Get the virtual local time elapsed after adaption interval.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  elapsedVirtualLocalTime, elapsed TV.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_GetVirtualLocalTimeElapsedAfterAdaptionInterval(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedVirtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_OnGetCurrentVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Get the current virtual local time (TV)
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[out]  virtualLocalTimePtr, TV.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_OnGetCurrentVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTimePtr,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_SetVirtualLocalTimeElapsedAfterAdaptionInterval
 *********************************************************************************************************************/
/*! \brief       Set the virtual local time elapsed after adaption interval.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   elapsedVirtualLocalTime, elapsed TV.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SetVirtualLocalTimeElapsedAfterAdaptionInterval(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) elapsedVirtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateElapsedVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Calculate elapsed virtual local time.
 *  \details     dTV = TV - TVsync
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   virtualLocalTime, TV.
 *  \param[out]  elapsedVirtualLocalTime, dTV.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_CalculateElapsedVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedVirtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetLocalClockIdx
 *********************************************************************************************************************/
/*! \brief       Get the local clock index of the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid local time index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      local clock index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(uint16, STBM_CODE) StbM_LocalTime_GetLocalClockIdx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetLastClockValue
 *********************************************************************************************************************/
/*! \brief       Get the last clock value.
 *  \details     -
 *  \param[in]   clockIdx, valid local clock index of timebase.
 *  \param[out]  clockValue, the last read clock value. It depends on the clock type how the value has to be understand.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetLastClockValue(
        uint32 clockIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) clockValue,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_SetLastClockValue
 *********************************************************************************************************************/
/*! \brief       Set the last clock value.
 *  \details     -
 *  \param[in]   clockIdx, valid local clock index of timebase.
 *  \param[in]   clockValue, the last read clock value.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SetLastClockValue(
        uint32 clockIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) clockValue,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) || (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_GetElapsedClockValue
 *********************************************************************************************************************/
/*! \brief       Get the elapsed clock value.
 *  \details     -
 *  \param[in]   clockIdx, valid local clock index of timebase.
 *  \param[out]  elapsedClockValue, the elapsed clock value. It depends on the clock type how the value has to be understand.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetElapsedClockValue(
        uint32 clockIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) elapsedClockValue,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) || (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetElapsedClockValue
 *********************************************************************************************************************/
/*! \brief       Set the elapsed clock value.
 *  \details     -
 *  \param[in]   clockIdx, valid local clock index of timebase.
 *  \param[in]   elapsedClockValue, the elapsed clock value.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SetElapsedClockValue(
        uint32 clockIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) elapsedClockValue,
        StbM_PartitionIdentifiersIterType partitionIdx);

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateElapsedClockValue
 *********************************************************************************************************************/
/*! \brief       Update the elapsed clock value.
 *  \details     -
 *  \param[in]   clockIdx, valid local clock index of timebase.
 *  \param[in]   elapsedClockValue, the elapsed clock value.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         needs to have a local clock.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateElapsedClockValue(
        uint32 clockIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) elapsedClockValue,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) */

# if (STBM_CONFIG_OS_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_InitOsLocalClock
 *********************************************************************************************************************/
/*! \brief       Initialize the Os local clock.
 *  \details     -
 *  \param[in]   localTimeId, valid local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_InitOsLocalClock(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetOsLocalClockIdx
 *********************************************************************************************************************/
/*! \brief       Get the local clock index.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      the local clock index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint16, STBM_CODE) StbM_LocalTime_GetOsLocalClockIdx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetOsElapsedTime
 *********************************************************************************************************************/
/*! \brief       Get the elapsed time for given timebase with Os based clock source.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  elapsedTime, elapsed time in nanoseconds.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetOsElapsedTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_OnUpdateOsVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Update the virtual local time for given timebase with Os based clock source.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_OnUpdateOsVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) */

# if (STBM_CONFIG_GPT_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_InitGptLocalClock
 *********************************************************************************************************************/
/*! \brief       Initialize the Gpt local clock.
 *  \details     -
 *  \param[in]   localTimeId, valid local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_InitGptLocalClock(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetGptLocalClockIdx
 *********************************************************************************************************************/
/*! \brief       Get the local clock index.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      the local clock index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint16, STBM_CODE) StbM_LocalTime_GetGptLocalClockIdx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetGptElapsedTime
 *********************************************************************************************************************/
/*! \brief       Get the elapsed time for given timebase with Gpt based clock source.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  elapsedTime, elapsed time in nanoseconds.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetGptElapsedTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_OnUpdateGptVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Update the virtual local time for given timebase with Gpt based clock source.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_OnUpdateGptVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_GPT_CLOCK == STD_ON) */

# if (STBM_CONFIG_ETH_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_InitEthLocalClock
 *********************************************************************************************************************/
/*! \brief       Initialize the Ethernet local clock.
 *  \details     -
 *  \param[in]   localTimeId, valid local time index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_InitEthLocalClock(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetEthLocalClockIdx
 *********************************************************************************************************************/
/*! \brief       Get the local clock index.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      the local clock index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint16, STBM_CODE) StbM_LocalTime_GetEthLocalClockIdx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetEthTime
 *********************************************************************************************************************/
/*! \brief       Get the ethernet time in nanoseconds for given timebase with Eth based clock source.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  ethernetTime, ethernet time in nanoseconds.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetEthTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) ethernetTime,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_OnUpdateEthVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Update the virtual local time for given timebase with Eth based clock source.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, otherwise.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_OnUpdateEthVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_IsEthControllerAvailable
 *********************************************************************************************************************/
/*! \brief       Check if the ethernet controller is available for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if available
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_LocalTime_IsEthControllerAvailable(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_GetEthCurrentTime
 *********************************************************************************************************************/
/*! \brief       Get the current ethernet controller time for the given timebase.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  timeStamp, ethernet timestamp.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      true, if succeeded.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_LocalTime_GetEthCurrentTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStamp,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_ETH_CLOCK == STD_ON) */

# if (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_TriggerLocalClockSync
 *********************************************************************************************************************/
/*! \brief       Trigger synchronization of local clock.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      type of clock adjustment (major|minor|none).
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL FUNC(uint8, STBM_CODE) StbM_LocalTime_TriggerLocalClockSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);

/**********************************************************************************************************************
 *  StbM_LocalTime_HandleLocalClockSync
 *********************************************************************************************************************/
/*! \brief       Handle synchronization of local clock.
 *  \details     -
 *  \param[in]   timeBaseIdx, timebase index.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_HandleLocalClockSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON) */

# if (STBM_CONFIG_TIME_RECORDING == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTimeLow
 *********************************************************************************************************************/
/*! \brief       Get the least significant 32 bit of the virtual local time.
 *  \details     -
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      virtual local time low.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_LocalTime_GetVirtualLocalTimeLow(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* (STBM_CONFIG_TIME_RECORDING == STD_ON) */

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateElapsedTimeFromElapsedCounterValue
 *********************************************************************************************************************/
/*! \brief       Calculate elapsed time for OS or GPT local time
 *  \details     This function calculates the elapsed time of the given time-base for OS or GPT timer based on the
 *               elapsedCounterValue.
 *  \param[in]   timeBaseIdx, valid index of timebase.
 *  \param[out]  elapsedTime, calculated elapsed nanoseconds.
 *  \param[in]   partitionIdx, valid partition index.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  Private
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_CalculateElapsedTimeFromElapsedCounterValue(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedTime,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* STBM_EXISTS_OS_LOCALCLOCK_CLOCKTYPEOFLOCALTIMECONFIG || STBM_EXISTS_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALTIMECONFIG */

# if (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_CloneTimeValue
 *********************************************************************************************************************/
/*! \brief       Copy time value from source time base to destination time base
 *  \details     -
 *  \param[in]   destinationTimeBaseIdx, time base index of destination time base.
 *  \param[in]   sourceTimeBaseIdx, time base index of source time base.
 *  \param[in]   partitionIdx, valid partition index.
 *  \return      E_OK, if succeeded
 *               E_NOT_OK, otherwise
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \visibility  public
 *  \unit        LocalTime
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_CloneTimeValue(
        StbM_SynchronizedTimeBaseType sourceTimeBaseIdx,
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx);
# endif /* STBM_CONFIG_SOURCE_TIMEBASE == STD_ON */
#endif /* STBM_NOUNIT_LOCALTIME */

#ifndef STBM_NOUNIT_CALC /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: Calc
 *********************************************************************************************************************/
/*! \brief      This unit is a helper unit providing calculation functionality.
 *  \details    This unit has no state.
 *  \pre        -
 *  \trace      CALC_UNIT
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_Calc_AddTimeStamps
 *********************************************************************************************************************/
/*! \brief       Add timestamps.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \param[out]  sum, lhs + rhs.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, overflow occurred.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_AddTimeStamps(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) sum);

# if ((STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TIME_NOTIFICATION == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_SubtractTimeStamps
 *********************************************************************************************************************/
/*! \brief       Subtract timestamps.
 *  \details     Difference is still calculated, even if underflow occurs.
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \param[out]  difference, lhs - rhs.
 *  \return      E_OK, if lhs >= rhs. Therefore positive difference.
 *               E_NOT_OK, if lhs < rhs, underflow occurred. Therefore negative difference.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_SubtractTimeStamps(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) difference);
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) */

# if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_AddVirtualLocalTimes
 *********************************************************************************************************************/
/*! \brief       Add virtual local times.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \param[out]  sum, lhs + rhs.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, overflow occurred.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_AddVirtualLocalTimes(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) sum);
# endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_SubtractVirtualLocalTimes
 *********************************************************************************************************************/
/*! \brief       Subtract virtual local times.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \param[out]  difference, lhs - rhs.
 *  \pre         lhs >= rhs
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(void, STBM_CODE) StbM_Calc_SubtractVirtualLocalTimes(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) difference);

# if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_MultiplyTimeStampWithRate
 *********************************************************************************************************************/
/*! \brief           Multiply the given timestamp by the given rate.
 *  \details         -
 *  \param[in,out]   timeStamp, timestamp.
 *  \param[in]       rate, the rate.
 *  \return          E_OK, if succeeded.
 *                   E_NOT_OK, overflow occurred.
 *  \pre             -
 *  \context         TASK|ISR2
 *  \reentrant       TRUE
 *  \unit            Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_MultiplyTimeStampWithRate(
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStamp, StbM_InternalRateType rate);
# endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) */

# if ((STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_EqualThan
 *********************************************************************************************************************/
/*! \brief       Check if time of given timestamp is equal.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \return      true, if equal.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Calc_EqualThan(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs);
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON)*/

/**********************************************************************************************************************
 *  StbM_Calc_LessThan
 *********************************************************************************************************************/
/*! \brief       Check lhs < rhs.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \return      true, if lhs < rhs.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Calc_LessThan(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs);

/**********************************************************************************************************************
 *  StbM_Calc_EqualThan_VirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Check if time of given virtual local time is equal.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \return      true, if equal.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Calc_EqualThan_VirtualLocalTime(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs);

/**********************************************************************************************************************
 *  StbM_Calc_LessThan_VirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Check lhs < rhs.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \return      true, if lhs < rhs.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Calc_LessThan_VirtualLocalTime(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs);

# if ((STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_LessEqualThan
 *********************************************************************************************************************/
/*! \brief       Check lhs <= rhs.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \return      true, if lhs <= rhs.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Calc_LessEqualThan(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs);
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_LessEqualThan_VirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Check lhs <= rhs.
 *  \details     -
 *  \param[in]   lhs, left-hand side operand.
 *  \param[in]   rhs, right-hand side operand.
 *  \return      true, if lhs <= rhs.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Calc_LessEqualThan_VirtualLocalTime(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs);

# if ((STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_ToNanoseconds
 *********************************************************************************************************************/
/*! \brief       Convert given timestamp to nanoseconds.
 *  \details     -
 *  \param[in]   timeStamp, timestamp.
 *  \param[out]  nanoseconds, converted nanoseconds.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, if not convertable (overflow).
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_ToNanoseconds(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStamp,
        P2VAR(uint32, AUTOMATIC, STBM_APPL_VAR) nanoseconds);
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) */

# if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_ToNanoseconds_Uint64
 *********************************************************************************************************************/
/*! \brief       Convert given timestamp to nanoseconds with 64 bit.
 *  \details     -
 *  \param[in]   timeStamp, timestamp.
 *  \param[out]  nanoseconds, converted nanoseconds.
 *  \return      E_OK, if succeeded.
 *               E_NOT_OK, if not convertable (overflow).
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_ToNanoseconds_Uint64(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStamp,
        P2VAR(uint64, AUTOMATIC, STBM_APPL_VAR) nanoseconds);
# endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_ToNanoseconds_Uint64_VirtualLocalTime
 *********************************************************************************************************************/
/*! \brief       Convert given virtual local time to nanoseconds with 64 bit.
 *  \details     -
 *  \param[in]   timeStamp, timestamp.
 *  \param[out]  nanoseconds, converted nanoseconds.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Calc_ToNanoseconds_Uint64_VirtualLocalTime(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        P2VAR(uint64, AUTOMATIC, STBM_APPL_VAR) nanoseconds);

# if (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON)
/**********************************************************************************************************************
 *  StbM_Calc_ToMicroseconds
 *********************************************************************************************************************/
/*! \brief       Convert given timestamp to microseconds.
 *  \details     -
 *  \param[in]   timeStamp, timestamp.
 *  \return      microseconds, converted microseconds.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(StbM_MicrosecondType, STBM_CODE) StbM_Calc_ToMicroseconds(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStamp);
# endif /* (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_ToInternalTimeStampType
 *********************************************************************************************************************/
/*! \brief       Convert given AUTOSAR timestamp into internal timestamp.
 *  \details     -
 *  \param[in]   fromTimeStamp, AUTOSAR timestamp.
 *  \param[out]  toTimeStamp, internal timestamp.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Calc_ToInternalTimeStampType(
        P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) fromTimeStamp,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) toTimeStamp);

/**********************************************************************************************************************
 *  StbM_Calc_ToStbMTimeStampType
 *********************************************************************************************************************/
/*! \brief       Convert given internal timestamp into AUTOSAR timestamp.
 *  \details     -
 *  \param[in]   fromTimeStamp, internal timestamp.
 *  \param[out]  toTimeStamp, AUTOSAR timestamp.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Calc_ToStbMTimeStampType(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA)fromTimeStamp,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA)toTimeStamp);

# if (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON)
/**********************************************************************************************************************
 *  StbM_Calc_ToStbMTimeStampExtendedType
 *********************************************************************************************************************/
/*! \brief       Convert given internal timestamp into AUTOSAR extended format timestamp.
 *  \details     -
 *  \param[in]   fromTimeStamp, internal timestamp.
 *  \param[out]  toTimeStamp, AUTOSAR extended format timestamp.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
*********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Calc_ToStbMTimeStampExtendedType(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA)fromTimeStamp,
        P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_DATA)toTimeStamp);
# endif /* (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON) */

# if (STBM_CONFIG_ETH_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_Calc_InternalTimeStampTypeToVirtualLocalTimeType
 *********************************************************************************************************************/
/*! \brief       Convert given internal timestamp into virtual local time.
 *  \details     -
 *  \param[in]   fromTimeStamp, internal timestamp.
 *  \param[out]  toTimeStamp, virtual local time.
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \unit        Calc
 *********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_InternalTimeStampTypeToVirtualLocalTimeType(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA)fromTimeStamp,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA)toTimeStamp);
# endif /* (STBM_CONFIG_ETH_CLOCK == STD_ON) */
#endif /* STBM_NOUNIT_CALC */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#ifndef STBM_NOUNIT_COMMON /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: Common
 *********************************************************************************************************************/
# if (STBM_MULTIPARTITION_USED == STD_ON)
/**********************************************************************************************************************
 *  StbM_Common_GetCurrentPartitionIndexByOsApplication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(StbM_PartitionIdentifiersIterType, STBM_CODE) StbM_Common_GetCurrentPartitionIndexByOsApplication(ApplicationType osAppId)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_PartitionIdentifiersIterType i;

  /* #10 Set partition index to invalid value */
  StbM_PartitionIdentifiersIterType partitionIdx = STBM_MAX_PARTITION_INDEX_VALUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Find partition index by application id in os application to partition mapping table */
  for (i = 0u; i < StbM_GetSizeOfPartitionIdentifiers(); i++)
  {
    if (StbM_GetPartitionSNVOfPartitionIdentifiers(i) == osAppId)
    {
      partitionIdx = StbM_GetPCPartitionConfigIdxOfPartitionIdentifiers(i);
      break;
    }
  }

  return partitionIdx;
} /* StbM_Common_GetCurrentPartitionIndexByOsApplication */
# endif /* STBM_MULTIPARTITION_USED == STD_ON */
#endif /* STBM_NOUNIT_COMMON */

#ifndef STBM_NOUNIT_GLOBALTIME /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: GlobalTime
 *********************************************************************************************************************/
# if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_GlobalTime_SetNewGlobalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 ********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_SetNewGlobalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTime,
        boolean incrementOnSuccess,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get current virtual local time */
  retVal = StbM_LocalTime_OnGetCurrentVirtualLocalTime(timeBaseIdx, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 If time calculation succeeded: */
  if (retVal == E_OK)
  {
    /* #30 Update main time tuple */
    StbM_LocalTime_UpdateMainTimeTuple(timeBaseIdx, globalTime, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #40 Clear all bits in local status */
    StbM_Status_ClearLocalStatus(timeBaseIdx, partitionIdx);

    /* #50 Set global timebase bit */
    StbM_Status_SetSynchronized(timeBaseIdx, partitionIdx);

    if (incrementOnSuccess == TRUE)
    {
      /* #60 Increment timebase update counter, if it shall be incremented on success */
      StbM_TimeBase_IncrementUpdateCounter(timeBaseIdx, partitionIdx);
    }

    /* #70 Update status notification event with: Resync */
#  if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
    StbM_StatusNotification_OnReSyncEvent(timeBaseIdx, partitionIdx);
#  endif
  }
  return retVal;
} /* StbM_GlobalTime_SetNewGlobalTime */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

# endif /* (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_GlobalTime_ReceiveGlobalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 ********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_ReceiveGlobalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) localTimePtr,
        StbM_TimeBaseStatusType timeBaseStatus,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update received time tuple */
  retVal = StbM_LocalTime_UpdateReceivedTimeTuple(timeBaseIdx, globalTimePtr, localTimePtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #20 Update synclocal time tuple */
  retVal |= StbM_LocalTime_UpdateSynclocalTimeTuple(timeBaseIdx, partitionIdx); /* PRQA S 2985 */ /* MD_StbM_Rule2.2_2985 */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #30 Update time leap */
  StbM_LocalTime_UpdateTimeLeap(timeBaseIdx, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #40 If received time and time leap update succeeded: */
  if (retVal == E_OK)
  {
    /* #50 Reset timeout monitoring */
#  if (STBM_CONFIG_TIMEOUT == STD_ON)
    StbM_Timeout_Reset(timeBaseIdx, partitionIdx);
#  endif

    /* #60 Update TimeLeap unit */
#  if (STBM_CONFIG_TIME_LEAP == STD_ON)
    StbM_TimeLeap_Update(timeBaseIdx, partitionIdx);
#  endif

    /* #70 Update Status unit */
    StbM_Status_Update(timeBaseIdx, timeBaseStatus, partitionIdx);

    /* #80 Update TimeCorrection unit */
#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
    StbM_TimeCorrection_Update(timeBaseIdx, partitionIdx);
#  endif

    /* #90 Set global timebase bit */
    StbM_Status_SetSynchronized(timeBaseIdx, partitionIdx);

    /* #100 Update TimeRecording unit */
#  if (STBM_CONFIG_TIME_RECORDING == STD_ON)
    StbM_TimeRecording_Update(timeBaseIdx, partitionIdx);
#  endif

    /* #110 Increment timebase update counter */
    StbM_TimeBase_IncrementUpdateCounter(timeBaseIdx, partitionIdx);

    /* #120 Update status notification that resync event occurred */
#  if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
    StbM_StatusNotification_OnReSyncEvent(timeBaseIdx, partitionIdx);
#  endif

    /* #130 Update main time tuple */
    StbM_LocalTime_UpdateMainTimeTupleAfterBusReceive(timeBaseIdx, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    /* #140 Handle local clock synchronization */
#  if (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON)
    StbM_LocalTime_HandleLocalClockSync(timeBaseIdx, partitionIdx);
#  endif
  }

  return retVal;
} /* StbM_GlobalTime_ReceiveGlobalTime */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_GlobalTime_OnGetCurrentTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_OnGetCurrentTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) localTimePtr,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTimePtr,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userData,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If offset timebase, get combined status */
# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
  {
    localTimePtr->timeBaseStatus = StbM_Status_GetLocalTimeStatusCombined(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  }
  else
# endif
  /* #20 Otherwise get status */
  {
    localTimePtr->timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  /* #30 Get current time of timebase */
  retVal = StbM_GlobalTime_GetTime(timeBaseIdx, &localTime, virtualLocalTimePtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #40 Convert local time to AUTOSAR timestamp format */
  StbM_Calc_ToStbMTimeStampType(&localTime, localTimePtr); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #50 Get user data */
  StbM_UserData_Get(timeBaseIdx, userData, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  return retVal;
} /* StbM_GlobalTime_OnGetCurrentTime */

/**********************************************************************************************************************
 *  StbM_GlobalTime_GetTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_GetTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTime,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_InternalTimeStampType syncLocalTime = STBM_INIT_TIME_ZERO;
  StbM_SynchronizedTimeBaseType referredTimeBaseIdx = timeBaseIdx;
  StbM_PartitionIdentifiersIterType referredPartitionIdx = partitionIdx;

  /* ----- Implementation ----------------------------------------------- */
  StbM_TimeBase_GetReferredTimeBase(timeBaseIdx, partitionIdx, &referredTimeBaseIdx, &referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #10 Get current virtual local time */
  retVal = StbM_LocalTime_OnGetCurrentVirtualLocalTime(timeBaseIdx, virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #20 Get current local time of synchronized timebase */
  retVal |= StbM_LocalTime_GetLocalTime(referredTimeBaseIdx, virtualLocalTime, &syncLocalTime, referredPartitionIdx); /* PRQA S 2985 */ /* MD_StbM_Rule2.2_2985 */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

# if  (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  /* #30 If given timebase is offset timebase */
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
  {
    StbM_InternalTimeStampType offsetLocalTime = STBM_INIT_TIME_ZERO;

    /* #40 Get local time of offset timebase */
    retVal |= StbM_LocalTime_GetLocalTime(timeBaseIdx, virtualLocalTime, &offsetLocalTime, partitionIdx); /* PRQA S 2985 */ /* MD_StbM_Rule2.2_2985 */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #50 Add local time of synchronized timebase to local time of offset timebase and write result to out parameter */
    retVal |= StbM_Calc_AddTimeStamps(&syncLocalTime, &offsetLocalTime, localTime); /* PRQA S 2985 */ /* MD_StbM_Rule2.2_2985 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  }
  else
# endif
  /* #60 Otherwise write local time of synchronized timebase to out parameter */
  {
    *localTime = syncLocalTime; /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  return retVal;
} /* StbM_GlobalTime_GetTime */

# if (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON)
/**********************************************************************************************************************
 *  StbM_GlobalTime_OnGetCurrentTimeExtended
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_GlobalTime_OnGetCurrentTimeExtended(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_VAR) localTimePtr,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userData,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;
  StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If offset timebase, get combined status */
#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
  {
    localTimePtr->timeBaseStatus = StbM_Status_GetLocalTimeStatusCombined(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  }
  else
#  endif
  /* #20 Otherwise get status */
  {
    localTimePtr->timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  /* #30 Get current time of timebase */
  retVal = StbM_GlobalTime_GetTime(timeBaseIdx, &localTime, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #40 Convert to AUTOSAR extended timestamp format */
  StbM_Calc_ToStbMTimeStampExtendedType(&localTime, localTimePtr); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #50 Get user data */
  StbM_UserData_Get(timeBaseIdx, userData, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  return retVal;
} /* StbM_GlobalTime_OnGetCurrentTimeExtended */
# endif /* (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON) */

/**********************************************************************************************************************
 *  StbM_GlobalTime_OnGetMainTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_GlobalTime_OnGetMainTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimeSyncPtr,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) localTimeSyncPtr,
        P2VAR(StbM_RateDeviationType, AUTOMATIC, STBM_APPL_VAR) rateDeviation,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalTimeStampType globalTime = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If offset timebase, get combined status */
# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
  {
    globalTimeSyncPtr->timeBaseStatus = StbM_Status_GetLocalTimeStatusCombined(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  }
  else
# endif
  {
    /* #20 Otherwise get status */
    globalTimeSyncPtr->timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  /* #30 Get global time from local time unit */
  StbM_LocalTime_GetGlobalTimeSync(timeBaseIdx, &globalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  StbM_Calc_ToStbMTimeStampType(&globalTime, globalTimeSyncPtr); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #40 Get local time from local time unit */
  StbM_LocalTime_GetVirtualLocalTimeSync(timeBaseIdx, localTimeSyncPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #50 Get rate deviation */
# if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON))
  if (StbM_TimeCorrection_HasTimeCorrectionConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
    *rateDeviation = StbM_TimeCorrection_GetRateDeviation(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  }
  else
  {
    *rateDeviation = 0; /* SBSW_STBM_ACCESS_PARAMPTR */
  }
# else
  *rateDeviation = 0; /* SBSW_STBM_ACCESS_PARAMPTR */
# endif
} /* StbM_GlobalTime_OnGetMainTime */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* STBM_NOUNIT_GLOBALTIME */

#ifndef STBM_NOUNIT_CLONETIME /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  Unit: CloneTime
 *********************************************************************************************************************/
#  if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_CloneTime_InitCloneRequestState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_CloneTime_InitCloneRequestState(StbM_PartitionIdentifiersIterType partitionIdx)
{
  uint16 deferredCloneRequestStateIdx;

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 For every clone request set destination time base idx to invalid and validity of request to FALSE */
  for (deferredCloneRequestStateIdx = 0u; deferredCloneRequestStateIdx < StbM_GetSizeOfDeferredCloneRequestState(partitionIdx); deferredCloneRequestStateIdx++)
  {
    StbM_SetDestinationTimeBaseIdxOfDeferredCloneRequestState(deferredCloneRequestStateIdx, STBM_INVALID_TIME_BASE_INDEX, partitionIdx); /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
    StbM_SetCloneConfigOfDeferredCloneRequestState(deferredCloneRequestStateIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
    StbM_SetStatusMaskOfDeferredCloneRequestState(deferredCloneRequestStateIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
    StbM_SetStatusValueOfDeferredCloneRequestState(deferredCloneRequestStateIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
    StbM_SetRequestValidOfDeferredCloneRequestState(deferredCloneRequestStateIdx, FALSE, partitionIdx); /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
  }
} /* StbM_CloneTime_InitCloneRequestState */

/**********************************************************************************************************************
 *  StbM_CloneTime_StoreCloneRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_CloneTime_StoreCloneRequest(
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx,
        StbM_CloneConfigType cloneCfg,
        StbM_TimeBaseStatusType statusMask,
        StbM_TimeBaseStatusType statusValue)
{
  Std_ReturnType retVal;
  uint16 cloningTableIdx;
  uint16 startTableIdx;
  uint16 endTableIdx;
  StbM_SynchronizedTimeBaseType sourceTimeBaseIdx = destinationTimeBaseIdx;
  StbM_SynchronizedTimeBaseType tableDestinationIdx;

  retVal = StbM_CloneTime_GetCloneSourceTimeBase(destinationTimeBaseIdx, partitionIdx, &sourceTimeBaseIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  if (StbM_TimeBase_IsMaster(sourceTimeBaseIdx, partitionIdx) == TRUE)
  {
    retVal = E_NOT_OK;
  }

  if (retVal == E_OK)
  {
    startTableIdx = StbM_GetDeferredCloneRequestStateStartIdxOfTimeBaseConfig(sourceTimeBaseIdx, partitionIdx);
    endTableIdx = StbM_GetDeferredCloneRequestStateEndIdxOfTimeBaseConfig(sourceTimeBaseIdx, partitionIdx);

    /* #10 Find corresponding table entry or next empty table entry */
    for (cloningTableIdx = startTableIdx; cloningTableIdx < endTableIdx; cloningTableIdx++) /* FETA_StbM_2 */
    {
      /*@ assert cloningTableIdx < StbM_GetSizeOfDeferredCloneRequestState(partitionIdx); */ /* VCA_STBM_CSL03_ITERATION */
      tableDestinationIdx = StbM_GetDestinationTimeBaseIdxOfDeferredCloneRequestState(cloningTableIdx, partitionIdx);
      if ((destinationTimeBaseIdx == tableDestinationIdx) || (tableDestinationIdx == STBM_INVALID_TIME_BASE_INDEX))
      {
        /* #20 Save destinationTimeBaseId, cloneCfg, statusMask and statusValue in deferred clone state with right destination time base */
        StbM_SetDestinationTimeBaseIdxOfDeferredCloneRequestState(cloningTableIdx, destinationTimeBaseIdx, partitionIdx); /* PRQA S 2843 */ /* MD_StbM_Rule1.3_2843 */ /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
        StbM_SetCloneConfigOfDeferredCloneRequestState(cloningTableIdx, cloneCfg, partitionIdx); /* PRQA S 2843 */ /* MD_StbM_Rule1.3_2843 */ /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
        StbM_SetStatusMaskOfDeferredCloneRequestState(cloningTableIdx, statusMask, partitionIdx); /* PRQA S 2843 */ /* MD_StbM_Rule1.3_2843 */ /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
        StbM_SetStatusValueOfDeferredCloneRequestState(cloningTableIdx, statusValue, partitionIdx); /* PRQA S 2843 */ /* MD_StbM_Rule1.3_2843 */ /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
        StbM_SetRequestValidOfDeferredCloneRequestState(cloningTableIdx, TRUE, partitionIdx); /* PRQA S 2843 */ /* MD_StbM_Rule1.3_2843 */ /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
        break;
      }
    }
  }

  return retVal;
} /* StbM_CloneTime_StoreCloneRequest */

/**********************************************************************************************************************
 *  StbM_CloneTime_CallCloneRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_CloneTime_CallCloneRequest(
        StbM_SynchronizedTimeBaseType sourceTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  uint16 cloningTableIdx;
  uint16 startTableIdx;
  uint16 endTableIdx;
  StbM_SynchronizedTimeBaseType destinationTimeBaseIdx;

  /* #10 If time base is used as source time base find clone requests */
  if (StbM_IsDeferredCloneRequestStateUsedOfTimeBaseConfig(sourceTimeBaseIdx, partitionIdx))
  {
    startTableIdx = StbM_GetDeferredCloneRequestStateStartIdxOfTimeBaseConfig(sourceTimeBaseIdx, partitionIdx);
    endTableIdx = StbM_GetDeferredCloneRequestStateEndIdxOfTimeBaseConfig(sourceTimeBaseIdx, partitionIdx);

    for (cloningTableIdx = startTableIdx; cloningTableIdx < endTableIdx; cloningTableIdx++) /* FETA_StbM_2 */
    {
      if (StbM_IsRequestValidOfDeferredCloneRequestState(cloningTableIdx, partitionIdx) == TRUE)
      {
        destinationTimeBaseIdx = StbM_GetDestinationTimeBaseIdxOfDeferredCloneRequestState(cloningTableIdx, partitionIdx);

        /* #20 Trigger cloning of time bases */
        /*@ assert destinationTimeBaseIdx < StbM_GetSizeOfTimeBaseConfig(partitionIdx); */ /* VCA_STBM_CSL01 */
        (void)StbM_CloneTime_ProcessCloneRequest(destinationTimeBaseIdx, partitionIdx, StbM_GetCloneConfigOfDeferredCloneRequestState(cloningTableIdx, partitionIdx), StbM_GetStatusMaskOfDeferredCloneRequestState(cloningTableIdx, partitionIdx), StbM_GetStatusValueOfDeferredCloneRequestState(cloningTableIdx, partitionIdx));
      }
    }
  }
} /* StbM_CloneTime_CallCloneRequest */

#   if (STBM_CONFIG_TIMEOUT == STD_ON)
/**********************************************************************************************************************
 *  StbM_CloneTime_RemovePendingCloneRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_CloneTime_RemovePendingCloneRequest(
        StbM_SynchronizedTimeBaseType sourceTimeBaseIdx,
        StbM_PartitionIdentifiersIterType sourcePartitionIdx)
{
  uint16 cloningTableIdx;
  uint16 startTableIdx;
  uint16 endTableIdx;

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(sourcePartitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  startTableIdx = StbM_GetDeferredCloneRequestStateStartIdxOfTimeBaseConfig(sourceTimeBaseIdx, sourcePartitionIdx);
  endTableIdx = StbM_GetDeferredCloneRequestStateEndIdxOfTimeBaseConfig(sourceTimeBaseIdx, sourcePartitionIdx);

  /* #10 Mark all pending clone requests for a source time base as not valid */
  for (cloningTableIdx = startTableIdx; cloningTableIdx < endTableIdx; cloningTableIdx++) /* FETA_StbM_2 */
  {
    /*@ assert cloningTableIdx < StbM_GetSizeOfDeferredCloneRequestState(sourcePartitionIdx); */ /* VCA_STBM_CSL03_ITERATION */
    StbM_SetRequestValidOfDeferredCloneRequestState(cloningTableIdx, FALSE, sourcePartitionIdx); /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
  }

}/* StbM_CloneTime_RemovePendingCloneRequest */
#   endif /* STBM_CONFIG_TIMEOUT */
#  endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_CloneTime_GetCloneSourceTimeBase
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_CloneTime_GetCloneSourceTimeBase(
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx,
        P2VAR(StbM_SynchronizedTimeBaseType, AUTOMATIC, STBM_APPL_VAR) sourceTimeBaseIdx)
{
  Std_ReturnType retVal = E_NOT_OK;
  StbM_PartitionIdentifiersIterType sourcePartitionIdx;

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get timeBaseId of cloning source time base for a cloning destination time base */
  if (StbM_GetTimeBasePartitionMappingSourceIdxOfTimeBaseConfig(destinationTimeBaseIdx, partitionIdx) < StbM_GetSizeOfTimeBasePartitionMapping())
  {
    StbM_TimeBase_GetPartitionMapping(StbM_GetTimeBasePartitionMappingSourceIdxOfTimeBaseConfig(destinationTimeBaseIdx, partitionIdx), sourceTimeBaseIdx, &sourcePartitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    retVal = E_OK;
  }

  return retVal;
} /* StbM_CloneTime_GetCloneSourceTimeBase */

/**********************************************************************************************************************
 *  StbM_CloneTime_ProcessCloneRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_CloneTime_ProcessCloneRequest(
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx,
        StbM_CloneConfigType cloneCfg,
        StbM_TimeBaseStatusType statusMask,
        StbM_TimeBaseStatusType statusValue)
{
  Std_ReturnType retVal;
  StbM_TimeBaseStatusType currentTimeBaseStatus;
  StbM_SynchronizedTimeBaseType sourceTimeBaseIdx = destinationTimeBaseIdx;
  uint16 cloningTableIdx = 0;
  uint16 startTableIdx = 0;
  uint16 endTableIdx = 0;
  StbM_UserDataType userData = {0u, 0u, 0u, 0u};

  retVal = StbM_CloneTime_GetCloneSourceTimeBase(destinationTimeBaseIdx, partitionIdx, &sourceTimeBaseIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  if (retVal == E_OK)
  {
    /* #20 Get current status of source time base */
    currentTimeBaseStatus = StbM_Status_GetLocalTimeStatus(sourceTimeBaseIdx, partitionIdx);

    /* #30 If current time base status matches status of clone request */
    if ((currentTimeBaseStatus & statusMask) == statusValue)
    {
      /* #40 copy user data */
      StbM_UserData_Get(sourceTimeBaseIdx, &userData, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      StbM_UserData_Set(destinationTimeBaseIdx, &userData, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      /* #50 copy time value */
      retVal = StbM_LocalTime_CloneTimeValue(sourceTimeBaseIdx, destinationTimeBaseIdx, partitionIdx);

#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
      /* #60 If APPLY_RATE flag is set, copy rate correction value */
      if (StbM_GetCloneApplyRate(cloneCfg) != 0u)
      {
        StbM_TimeCorrection_CloneRateValue(sourceTimeBaseIdx, destinationTimeBaseIdx, partitionIdx);
      }
#  endif

      /* #70 If IMMEDIATE_TX flag is set, increment time base update counter of destination time base */
      if (StbM_GetCloneImmediateTx(cloneCfg) != 0u)
      {
        StbM_TimeBase_IncrementUpdateCounter(destinationTimeBaseIdx, partitionIdx);
      }

      /* #80 Set global time base bit of destination time base */
      StbM_Status_SetSynchronized(destinationTimeBaseIdx, partitionIdx);
    }
    else
    {
      retVal = E_NOT_OK;
    }

#  if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    startTableIdx = StbM_GetDeferredCloneRequestStateStartIdxOfTimeBaseConfig(sourceTimeBaseIdx, partitionIdx);
    endTableIdx = StbM_GetDeferredCloneRequestStateEndIdxOfTimeBaseConfig(sourceTimeBaseIdx, partitionIdx);

    for (cloningTableIdx = startTableIdx; cloningTableIdx < endTableIdx; cloningTableIdx++) /* FETA_StbM_2 */
    {
      /*@ assert cloningTableIdx < StbM_GetSizeOfDeferredCloneRequestState(partitionIdx); */ /* VCA_STBM_CSL03_ITERATION */
      if (StbM_GetDestinationTimeBaseIdxOfDeferredCloneRequestState(cloningTableIdx, partitionIdx) == destinationTimeBaseIdx)
      {
        /* #90 Mark clone request as not valid */
        StbM_SetRequestValidOfDeferredCloneRequestState(cloningTableIdx, FALSE, partitionIdx); /* SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE */
      }
    }
#  else
    STBM_DUMMY_STATEMENT(startTableIdx);
    STBM_DUMMY_STATEMENT(endTableIdx);
    STBM_DUMMY_STATEMENT(cloningTableIdx);
#  endif
  }

  return retVal;
} /* StbM_CloneTime_ProcessCloneRequest */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* STBM_CONFIG_SOURCE_TIMEBASE */
#endif /* STBM_NOUNIT_CLONETIME */

#ifndef STBM_NOUNIT_TRIGGEREDCUSTOMER /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON)
/**********************************************************************************************************************
 *  Unit: TriggeredCustomer
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TriggeredCustomer_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TriggeredCustomerStateIterType customerIdx;

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 For each configured triggered customer */
  for (customerIdx = 0u; customerIdx < StbM_GetSizeOfTriggeredCustomerState(partitionIdx); customerIdx++)
  {
    /* #20 Set period counter to zero */
    StbM_SetPeriodCounterOfTriggeredCustomerState(customerIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TRIGGEREDCUSTOMERSTATE */
  }
} /* StbM_TriggeredCustomer_Init */

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TriggeredCustomer_Update(StbM_PartitionIdentifiersIterType partitionIdx)
{

  /* ----- Local Variables ---------------------------------------------- */
  StbM_CustomerIdType customerId;
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured triggered customer */
  for (customerId = 0u; customerId < StbM_GetSizeOfTriggeredCustomerConfig(partitionIdx); customerId++)
  {
    /* #20 Increment period customer counter */
    StbM_TriggeredCustomer_IncrementPeriodCounter(customerId, partitionIdx);

    /* #30 Check if customer is triggerable */
    if (StbM_TriggeredCustomer_IsTriggerable(customerId, partitionIdx) == TRUE)
    {
      TickType osTicks;
      StbM_MicrosecondType localTimeInUs;
      StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;

      /* #40 Get current time of associated timebase */
      retVal = StbM_LocalTime_GetLastUpdatedLocalTime(StbM_GetTimeBaseConfigIdxOfTriggeredCustomerConfig(customerId, partitionIdx), &localTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      /* #50 If retrieval of current time succeeded: */
      if (retVal == E_OK)
      {
        /* #60 Convert time to microseconds */
        localTimeInUs = StbM_Calc_ToMicroseconds(&localTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

        /* #70 Convert time in microseconds to ticks and synchronize the schedule table */
        osTicks = StbM_TriggeredCustomer_ToOsTicks(customerId, localTimeInUs, partitionIdx);

        /* #80 Synchronize the schedule table */
        (void)SyncScheduleTable(StbM_GetScheduleTableIDOfTriggeredCustomerConfig(customerId, partitionIdx), osTicks);
      }
    }
  }
} /* StbM_TriggeredCustomer_Update */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_ToOsTicks
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(TickType, STBM_CODE) StbM_TriggeredCustomer_ToOsTicks(
        StbM_CustomerIdType customerIdx,
        StbM_MicrosecondType microseconds,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Convert given microseconds into Os ticks */
  return (TickType)((microseconds * StbM_GetScheduleTableCounterTicksPerUsOfTriggeredCustomerConfig(customerIdx, partitionIdx)) % StbM_GetScheduleTableDurationOfTriggeredCustomerConfig(customerIdx, partitionIdx));
} /* StbM_TriggeredCustomer_ToOsTicks */

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_IsTriggerable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TriggeredCustomer_IsTriggerable(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  boolean triggeredCustomerIsTriggerable = FALSE;

  if (
       /* #10 Check if triggered customer period counter is zero */
          (StbM_GetPeriodCounterOfTriggeredCustomerState(customerId, partitionIdx) == StbM_GetTriggeredCustomerPeriodOfTriggeredCustomerConfig(customerId, partitionIdx))
       /* #20 Check if time base has been synchronized to global time */
       && (StbM_Status_IsSynchronized(StbM_GetTimeBaseConfigIdxOfTriggeredCustomerConfig(customerId, partitionIdx), partitionIdx) == TRUE)

#  if (STBM_CONFIG_TIMEOUT == STD_ON)
       /* #30 Check if timeout has not occurred */
       && (StbM_Status_IsTimeout(StbM_GetTimeBaseConfigIdxOfTriggeredCustomerConfig(customerId, partitionIdx), partitionIdx) == FALSE)
#  endif

#  if (STBM_CONFIG_TIME_LEAP == STD_ON)
       /* #40 Check if no time leap has occurred */
       && (StbM_Status_IsTimeLeap(StbM_GetTimeBaseConfigIdxOfTriggeredCustomerConfig(customerId, partitionIdx), partitionIdx) == FALSE)
#  endif
    )
  {
    /* #50 Check if table status is RUNNING || WAITING || RUNNING_AND_SYNCHRONOUS */
    ScheduleTableStatusType scheduleStatus = 0u;
    StatusType currentScheduleTableStatus = GetScheduleTableStatus(StbM_GetScheduleTableIDOfTriggeredCustomerConfig(customerId, partitionIdx), &scheduleStatus); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    if ((currentScheduleTableStatus == E_OK)
        && ((scheduleStatus == SCHEDULETABLE_WAITING) || (scheduleStatus == SCHEDULETABLE_RUNNING) || (scheduleStatus == SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)))
      {
        triggeredCustomerIsTriggerable = TRUE;
      }
  }
  return triggeredCustomerIsTriggerable;
} /* StbM_TriggeredCustomer_IsTriggerable */

/**********************************************************************************************************************
 *  StbM_TriggeredCustomer_IncrementPeriodCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TriggeredCustomer_IncrementPeriodCounter(
        StbM_CustomerIdType customerIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 If customer counter overflows */
  if (StbM_GetPeriodCounterOfTriggeredCustomerState(customerIdx, partitionIdx) == StbM_GetTriggeredCustomerPeriodOfTriggeredCustomerConfig(customerIdx, partitionIdx))
  {
    /* #20 Set to one because this function is called after the StbM_MainFunction has run and therefore computed one cycle */
    StbM_SetPeriodCounterOfTriggeredCustomerState(customerIdx, 1u, partitionIdx); /* SBSW_STBM_ACCESS_TRIGGEREDCUSTOMERSTATE */
  }
  else
  {
    /* #30 Else increment the customer counter */
    StbM_IncPeriodCounterOfTriggeredCustomerState(customerIdx, partitionIdx); /* SBSW_STBM_ACCESS_TRIGGEREDCUSTOMERSTATE */
  }
} /* StbM_TriggeredCustomer_IncrementPeriodCounter */
# endif /* (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */
#endif /* STBM_NOUNIT_TRIGGEREDCUSTOMER */

#ifndef STBM_NOUNIT_STATUSNOTIFICATION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
/**********************************************************************************************************************
 *  Unit: StatusNotification
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_StatusNotification_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_StatusNotification_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  StbM_CustomerIdType notificationCustomerIdx;
  StbMStatusNotificationCbkType StatusNotificationPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured status notification customer: */
  for (notificationCustomerIdx = 0u; notificationCustomerIdx < StbM_GetSizeOfStatusNotificationState(partitionIdx); notificationCustomerIdx++)
  {
    /* #20 Set the events to zero */
    StbM_StatusNotification_ResetEvents(notificationCustomerIdx, partitionIdx);

    /* #30 Set last analyzed status to zero */
    StbM_StatusNotification_ResetLastStatus(notificationCustomerIdx, partitionIdx);

    /* #40 Retrieve the status notification callback */
    StatusNotificationPtr = StbM_GetCallbackOfStatusNotificationCustomerCallback(StbM_GetStatusNotificationCustomerCallbackIdxOfStatusNotificationCustomerConfig(notificationCustomerIdx, partitionIdx), partitionIdx);

    /* #50 If the callback function is null: */
    if (StatusNotificationPtr == NULL_PTR) /* COV_STBM_SILENT_XF */
    {
      /* #60 Set retVal to E_NOT_OK */
      retVal = E_NOT_OK;
    }
  }

  return retVal;
} /* StbM_StatusNotification_Init */

/**********************************************************************************************************************
 *  StbM_StatusNotification_ResetLastStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_StatusNotification_ResetLastStatus(
        StbM_CustomerIdType customerIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Reset last analyzed status to zero */
  StbM_SetLastStatusOfStatusNotificationState(customerIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_STATUSNOTIFICATIONSTATE */
} /* StbM_StatusNotification_ResetLastStatus */

/**********************************************************************************************************************
 *  StbM_StatusNotification_ResetEvents
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_StatusNotification_ResetEvents(
        StbM_CustomerIdType customerIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Reset events of the given customer to zero */
  StbM_SetEventsOfStatusNotificationState(customerIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_STATUSNOTIFICATIONSTATE */
} /* StbM_StatusNotification_ResetEvents */

/**********************************************************************************************************************
 *  StbM_StatusNotification_NotifyCustomers
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_StatusNotification_NotifyCustomers(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_CustomerIdType customerIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured customer */
  for (customerIdx = 0; customerIdx < StbM_GetSizeOfStatusNotificationState(partitionIdx); customerIdx++)
  {
    StbM_TimeBaseNotificationType event;

    /* exclusive area is used because status notification events might happen in different context, than StbM_MainFunction e.g. leap event in StBM_BusSetGlobalTime. */
    StbM_EnterCritical_LocalCore();

    /* #20 Retrieve the current state of status notification */
    event = StbM_GetEventsOfStatusNotificationState(customerIdx, partitionIdx);

    /* #30 Clear status events */
    StbM_StatusNotification_ResetEvents(customerIdx, partitionIdx);

    StbM_LeaveCritical_LocalCore();

    /* #40 If any event occurred */
    if (event != 0u)
    {
      /* #50 Retrieve the status notification callback */
      StbMStatusNotificationCbkType StatusNotificationPtr = StbM_GetCallbackOfStatusNotificationCustomerCallback(StbM_GetStatusNotificationCustomerCallbackIdxOfStatusNotificationCustomerConfig(customerIdx, partitionIdx), partitionIdx);

      /* #60 Invoke status notification callback with occurred events */
      (void)StatusNotificationPtr(event); /* SBSW_STBM_FCTPTRCALL_NOTIFICATION */
    }
  }
} /* StbM_StatusNotification_NotifyCustomers */

/**********************************************************************************************************************
 *  StbM_StatusNotification_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_StatusNotification_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If status notification is configured for the given timebase */
  if (StbM_IsStatusNotificationCustomerConfigUsedOfTimeBaseConfig(timeBaseIdx, partitionIdx))
  {
    StbM_TimeBaseNotificationType configuredEventStatusMask;
    StbM_TimeBaseNotificationType currentStoredStatusEventMask;
    StbM_TimeBaseNotificationType newStatusEventMask;
    StbM_TimeBaseStatusType timeBaseStatus;
    StbM_TimeBaseStatusType lastTimeBaseStatus;

    /* #20 Retrieve the configured status notification event mask for the given timebase */
    configuredEventStatusMask = StbM_GetStatusNotificationEventMaskOfStatusNotificationCustomerConfig(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

    /* #30 Retrieve the timebase status of given timebase */
    timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

    /* #40 Get last analyzed timebase status */
    lastTimeBaseStatus = StbM_GetLastStatusOfStatusNotificationState(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

    /* #50 Retrieve the current stored status event mask */
    currentStoredStatusEventMask = StbM_GetEventsOfStatusNotificationState(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

    /* #60 Calculate the new status event mask by: current events | events based on timebase status changes | configured event mask */
    newStatusEventMask = (currentStoredStatusEventMask | StbM_StatusNotification_CalculateEventMask(lastTimeBaseStatus, timeBaseStatus)) & configuredEventStatusMask;

    /* #70 Update status notification event mask */
    StbM_SetEventsOfStatusNotificationState(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), newStatusEventMask, partitionIdx); /* SBSW_STBM_ACCESS_STATUSNOTIFICATIONSTATE_IND_TIMEBASECONFIG */

    /* #80 Store last analyzed timebase status */
    StbM_SetLastStatusOfStatusNotificationState(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), timeBaseStatus, partitionIdx); /* SBSW_STBM_ACCESS_STATUSNOTIFICATIONSTATE_IND_TIMEBASECONFIG */
  }
} /* StbM_StatusNotification_Update */

/**********************************************************************************************************************
 *  StbM_StatusNotification_CalculateEventMask
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_TimeBaseNotificationType, STBM_CODE) StbM_StatusNotification_CalculateEventMask(
        StbM_TimeBaseStatusType lastTimeBaseStatus,
        StbM_TimeBaseStatusType timeBaseStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseNotificationType newStatusEventMask;
  StbM_TimeBaseNotificationType occurredEventMask;
  StbM_TimeBaseNotificationType removedEventMask;

  /* ----- Implementation ----------------------------------------------- */
  occurredEventMask = (StbM_TimeBaseNotificationType) (~(uint32)lastTimeBaseStatus & (uint32)timeBaseStatus);
  removedEventMask = (StbM_TimeBaseNotificationType) ((uint32)lastTimeBaseStatus & ~(uint32)timeBaseStatus);

  newStatusEventMask = (
                         /* #10 Analyze global time base bit from 0 to 1 and map to STBM_EV_GLOBAL_TIME_BASE_MASK */
                        ((occurredEventMask & StbM_Global_Time_Base_BflMask) >> 3u)

                        /* #20 Analyze timeout bit from 0 to 1 and map to STBM_EV_TIMEOUT_OCCURRED_MASK */
                      | ((occurredEventMask & StbM_Timeout_BflMask) << 1u)

                        /* #30 Analyze sync to gateway bit from 0 to 1 and map to STBM_EV_SYNC_TO_SUBDOMAIN_MASK */
                      | ((occurredEventMask & StbM_Sync_To_Gateway_BflMask) << 5u)

                        /* #40 Analyze time leap past bit from 0 to 1 and map to STBM_EV_TIMELEAP_PAST_MASK */
                      | ((occurredEventMask & StbM_TimeLeapPast_BflMask))

                        /* #50 Analyze time leap future bit from 0 to 1 and map to STBM_EV_TIMELEAP_FUTURE_MASK */
                      | ((occurredEventMask & StbM_TimeLeapFuture_BflMask) >> 1u)

                        /* #60 Analyze timeout bit from 1 to 0 and map to STBM_EV_TIMEOUT_REMOVED_MASK */
                      | ((removedEventMask & StbM_Timeout_BflMask) << 2u)

                        /* #70 Analyze sync to gateway bit from 1 to 0 and map to STBM_EV_SYNC_TO_GLOBAL_MASTER_MASK */
                      | ((removedEventMask & StbM_Sync_To_Gateway_BflMask) << 6u)

                        /* #80 Analyze time leap past bit from 1 to 0 and map to STBM_EV_TIMELEAP_PAST_REMOVED_MASK */
                      | ((removedEventMask & StbM_TimeLeapPast_BflMask) << 1u)

                        /* #90 Analyze time leap future bit from 1 to 0 and map to STBM_EV_TIMELEAP_FUTURE_REMOVED_MASK */
                      | ((removedEventMask & StbM_TimeLeapFuture_BflMask))
                      );

  return newStatusEventMask;
} /* StbM_StatusNotification_CalculateEventMask */

/**********************************************************************************************************************
 *  StbM_StatusNotification_OnReSyncEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_StatusNotification_OnReSyncEvent(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 If status notification is configured: */
  if (StbM_IsStatusNotificationCustomerConfigUsedOfTimeBaseConfig(timeBaseIdx, partitionIdx))
  {
    StbM_TimeBaseNotificationType configuredEventStatusMask;
    StbM_TimeBaseNotificationType currentStoredStatusEventMask;

    /* #20 Update status event by STBM_EV_RESYNC_MASK, if configured */
    configuredEventStatusMask = StbM_GetStatusNotificationEventMaskOfStatusNotificationCustomerConfig(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
    currentStoredStatusEventMask = StbM_GetEventsOfStatusNotificationState(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

    currentStoredStatusEventMask |= (STBM_EV_RESYNC_MASK & configuredEventStatusMask);
    StbM_SetEventsOfStatusNotificationState(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), currentStoredStatusEventMask, partitionIdx); /* SBSW_STBM_ACCESS_STATUSNOTIFICATIONSTATE_IND_TIMEBASECONFIG */
  }
} /* StbM_StatusNotification_OnReSyncEvent */

#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_StatusNotification_OnRateCorrectionEvent
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_StatusNotification_OnRateCorrectionEvent(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 If status notification is configured: */
  if (StbM_IsStatusNotificationCustomerConfigUsedOfTimeBaseConfig(timeBaseIdx, partitionIdx))
  {
    StbM_TimeBaseNotificationType configuredEventStatusMask;
    StbM_TimeBaseNotificationType currentStoredStatusEventMask;

    /* #20 Update status event by STBM_EV_RATECORRECTION_MASK, if configured */
    configuredEventStatusMask = StbM_GetStatusNotificationEventMaskOfStatusNotificationCustomerConfig(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
    currentStoredStatusEventMask = StbM_GetEventsOfStatusNotificationState(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

    currentStoredStatusEventMask |= (STBM_EV_RATECORRECTION_MASK & configuredEventStatusMask);
    StbM_SetEventsOfStatusNotificationState(StbM_GetStatusNotificationCustomerConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), currentStoredStatusEventMask, partitionIdx); /* SBSW_STBM_ACCESS_STATUSNOTIFICATIONSTATE_IND_TIMEBASECONFIG */
  }
} /* StbM_StatusNotification_OnRateCorrectionEvent */
#  endif /* (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)*/
# endif /* (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON) */
#endif /* STBM_NOUNIT_STATUSNOTIFICATION */

#ifndef STBM_NOUNIT_TIMEBASE /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: TimeBase
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeBase_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeBase_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_SynchronizedTimeBaseType timebaseIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured timebase: */
  for (timebaseIdx = 0u; timebaseIdx < StbM_GetSizeOfTimeBaseState(partitionIdx); timebaseIdx++)
  {
    /* #20 Reset the update counter */
    StbM_TimeBase_ResetUpdateCounter(timebaseIdx, partitionIdx);
  }
} /* StbM_TimeBase_Init */

/**********************************************************************************************************************
 *  StbM_TimeBase_ResetUpdateCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeBase_ResetUpdateCounter(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset the update counter of the given timebase */
  StbM_SetUpdateCounterOfTimeBaseState(timeBaseIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEBASESTATE */
} /* StbM_TimeBase_ResetUpdateCounter */

/**********************************************************************************************************************
 *  StbM_TimeBase_IncrementUpdateCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeBase_IncrementUpdateCounter(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Increment update counter, which by C-Standard will wrap around by itself */
  StbM_IncUpdateCounterOfTimeBaseState(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEBASESTATE */
} /* StbM_TimeBase_IncrementUpdateCounter */

/**********************************************************************************************************************
 *  StbM_TimeBase_GetUpdateCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_UpdateCounterType, STBM_CODE) StbM_TimeBase_GetUpdateCounter(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Get update counter */
  return StbM_GetUpdateCounterOfTimeBaseState(timeBaseIdx, partitionIdx);
} /* StbM_TimeBase_GetUpdateCounter */

# if ((STBM_CONFIG_TIME_SLAVE == STD_ON) && (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON))
/**********************************************************************************************************************
 *  StbM_TimeBase_IsSlave
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeBase_IsSlave(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the given timebase is a slave */
  return StbM_IsTimeSlaveOfTimeBaseConfig(timeBaseIdx, partitionIdx);
} /* StbM_TimeBase_IsSlave */
# endif /* ((STBM_CONFIG_TIME_SLAVE == STD_ON) && (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)) */

# if (((STBM_CONFIG_TIME_SLAVE == STD_ON) && ((STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) || (STBM_HAS_ALLOW_SYSTEM_WIDE_GLOBAL_TIME_MASTER == STD_ON))) || ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)))
/**********************************************************************************************************************
 *  StbM_TimeBase_IsMaster
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeBase_IsMaster(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the given timebase is a global time master */
  return StbM_IsGlobalTimeMasterOfTimeBaseConfig(timeBaseIdx, partitionIdx);
} /**/
# endif /* ((STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) && ((STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_HAS_ALLOW_SYSTEM_WIDE_GLOBAL_TIME_MASTER == STD_ON))) || ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)) */

# if (((STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) || (STBM_CONFIG_GATEWAY == STD_ON) || (STBM_CONFIG_TIME_RECORDING == STD_ON)) && (STBM_DEV_ERROR_DETECT == STD_ON) && ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))) /* COV_STBM_DEV_ERROR_DETECT_TF_tf_tf_tf_tx_tf_tf */
/**********************************************************************************************************************
 *  StbM_TimeBase_IsSynchronized
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeBase_IsSynchronized(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 The given timebase is not a synchronized timebase if one of the following cases is true: */
  boolean isNotSynchronized = FALSE; /* PRQA S 2981 */ /* MD_StbM_Rule2.2_2981 */

  /* #20 The given timebase is an offset timebase */
#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  isNotSynchronized = StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx);
#  endif

  /* #30 The given timebase is a pure local timebase */
#  if ((STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON) && (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON))
  if (isNotSynchronized || StbM_TimeBase_IsPure(timeBaseIdx, partitionIdx)) /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */
  {
    isNotSynchronized = TRUE;
  }
  else
  {
    isNotSynchronized = FALSE;
  }
#  elif (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON)
  isNotSynchronized = StbM_TimeBase_IsPure(timeBaseIdx, partitionIdx);
#  endif

  return (isNotSynchronized == FALSE);
} /* StbM_TimeBase_IsSynchronized */
# endif /* (((STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) || (STBM_CONFIG_GATEWAY == STD_ON) || (STBM_CONFIG_TIME_RECORDING == STD_ON)) && (STBM_DEV_ERROR_DETECT == STD_ON) && ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))) */

# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeBase_IsOffset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeBase_IsOffset(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the given timebase is an offset one */
  return (StbM_GetTimeBasePartitionMappingOffsetIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx) < StbM_GetSizeOfTimeBasePartitionMapping());
} /* StbM_TimeBase_IsOffset */
# endif /* (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) */

# if ((STBM_CONFIG_GATEWAY == STD_ON) && ((STBM_CONFIG_TIMEOUT == STD_ON) || (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON)))
/**********************************************************************************************************************
 *  StbM_TimeBase_IsGateway
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeBase_IsGateway(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the given timebase is a gateway */
  return StbM_IsTimeGatewayOfTimeBaseConfig(timeBaseIdx, partitionIdx);
} /* StbM_TimeBase_IsGateway */
# endif /* ((STBM_CONFIG_GATEWAY == STD_ON) && ((STBM_CONFIG_TIMEOUT == STD_ON) || (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON))) */

# if ((STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON) && (STBM_DEV_ERROR_DETECT == STD_ON)) /* COV_STBM_DEV_ERROR_DETECT_TF_tf_tx */
/**********************************************************************************************************************
 *  StbM_TimeBase_IsPure
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeBase_IsPure(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the given timebase is a pure timebase */
  return StbM_IsPureLocalTimeBaseOfTimeBaseConfig(timeBaseIdx, partitionIdx);
} /* StbM_TimeBase_IsPure */
# endif /* (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON) && (STBM_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  StbM_TimeBase_GetReferredTimeBase
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeBase_GetReferredTimeBase(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx,
        P2VAR(StbM_SynchronizedTimeBaseType, AUTOMATIC, STBM_APPL_VAR) referredTimeBaseIdx,
        P2VAR(StbM_PartitionIdentifiersIterType, AUTOMATIC, STBM_APPL_VAR) referredPartitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the underlying synchronized timebase if available, otherwise return the given timebase */
# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
  {
    StbM_TimeBase_GetPartitionMapping(StbM_GetTimeBasePartitionMappingOffsetIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), referredTimeBaseIdx, referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  }
  else
# endif
  {
    *referredTimeBaseIdx = timeBaseIdx; /* SBSW_STBM_ACCESS_PARAMPTR */
    *referredPartitionIdx = partitionIdx; /* SBSW_STBM_ACCESS_PARAMPTR */
  }
} /* StbM_TimeBase_GetReferredTimeBase */

/**********************************************************************************************************************
 *  StbM_TimeBase_IsTimeBaseIdValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeBase_IsTimeBaseIdValid(
        StbM_SynchronizedTimeBaseType timeBaseId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if time base id is valid */
#  if (STBM_MULTIPARTITION_USED == STD_ON)
  return (timeBaseId < StbM_GetSizeOfTimeBasePartitionMapping());
#  else
  return (timeBaseId < StbM_GetSizeOfTimeBaseConfig(0u));
#  endif
} /* StbM_TimeBase_IsTimeBaseIdValid */

/**********************************************************************************************************************
 *  StbM_TimeBase_GetPartitionMapping
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeBase_GetPartitionMapping(
        StbM_SynchronizedTimeBaseType timeBaseId,
        P2VAR(StbM_SynchronizedTimeBaseType, AUTOMATIC, STBM_APPL_VAR) timeBaseIdx,
        P2VAR(StbM_PartitionIdentifiersIterType, AUTOMATIC, STBM_APPL_VAR) partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  if (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == TRUE)
  {
# if (STBM_MULTIPARTITION_USED == STD_ON)
    *timeBaseIdx = StbM_GetIndirectionToTimeBaseConfigIdxOfTimeBasePartitionMapping(timeBaseId); /* SBSW_STBM_ACCESS_PARAMPTR */
    *partitionIdx = StbM_GetIndirectionToTimeBaseConfigPartitionIdxOfTimeBasePartitionMapping(timeBaseId); /* SBSW_STBM_ACCESS_PARAMPTR */
# else
    *timeBaseIdx = timeBaseId; /* SBSW_STBM_ACCESS_PARAMPTR */
    *partitionIdx = 0u; /* SBSW_STBM_ACCESS_PARAMPTR */
# endif
  }
} /* StbM_TimeBase_GetPartitionMapping */
#endif /* STBM_NOUNIT_TIMEBASE */

#ifndef STBM_NOUNIT_TIMEOUT /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIMEOUT == STD_ON)
/**********************************************************************************************************************
 *  Unit: Timeout
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_Timeout_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Timeout_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeoutConfigIterType timeoutIdx;

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 For each configured timeout: */
  for (timeoutIdx = 0u; timeoutIdx < StbM_GetSizeOfTimeoutState(partitionIdx); timeoutIdx++)
  {
    /* #20 Set the timeout counter to zero */
    StbM_SetSyncLossTimeoutCounterOfTimeoutState(timeoutIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEOUTSTATE */
  }
} /* StbM_Timeout_Init */

/**********************************************************************************************************************
 *  StbM_Timeout_HasTimeoutConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Timeout_HasTimeoutConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the indirection of timebase config to timeout config table exists */
  return (StbM_GetTimeoutConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx) < StbM_GetSizeOfTimeoutConfig(partitionIdx));
} /* StbM_Timeout_HasTimeoutConfigured */

/**********************************************************************************************************************
 *  StbM_Timeout_IsExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Timeout_IsExpired(
        uint32 timeoutIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the sync loss timeout counter is equal to zero */
  return (StbM_GetSyncLossTimeoutCounterOfTimeoutState(timeoutIdx, partitionIdx) == 0u);
} /* StbM_Timeout_IsExpired */

/**********************************************************************************************************************
 *  StbM_Timeout_IsRunning
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Timeout_IsRunning(
        uint32 timeoutIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the sync loss timeout counter is greater than zero */
  return (StbM_GetSyncLossTimeoutCounterOfTimeoutState(timeoutIdx, partitionIdx) > 0u);
} /* StbM_Timeout_IsRunning */

/**********************************************************************************************************************
 *  StbM_Timeout_Reset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Timeout_Reset(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If given timebase has timeout configured: */
  if (StbM_Timeout_HasTimeoutConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
    /* #20 Reset the timeout counter to the configured value */
    StbM_SetSyncLossTimeoutCounterOfTimeoutState(StbM_GetTimeoutConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), StbM_GetSyncLossTimeoutCounterOfTimeoutConfig(StbM_GetTimeoutConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_TIMEOUTSTATE_IND_TIMEBASECONFIG */

    /* #30 Clear timeout bit */
    StbM_Status_ClearTimeout(timeBaseIdx, partitionIdx);
  }
} /* StbM_Timeout_Reset */

/**********************************************************************************************************************
 *  StbM_Timeout_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Timeout_Update(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 timeoutIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter exclusive area because timeout is shared across StbM_MainFunction and StbM_BusSetGlobalTime */
  StbM_EnterCritical_CrossCore();

  for (timeoutIdx = 0u; timeoutIdx < StbM_GetSizeOfTimeoutState(partitionIdx); timeoutIdx++)
  {
    /* #20 If timeout is running, decrement it by one */
    if (StbM_Timeout_IsRunning(timeoutIdx, partitionIdx) == TRUE)
    {
      StbM_DecSyncLossTimeoutCounterOfTimeoutState(timeoutIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEOUTSTATE */

      /* #30 If timeout is expired: */
      if (StbM_Timeout_IsExpired(timeoutIdx, partitionIdx) == TRUE)
      {
        /* #40 Set timeout flag */
        StbM_Status_SetTimeout(StbM_GetTimeBaseConfigIdxOfTimeoutConfig(timeoutIdx, partitionIdx), partitionIdx);

        /* #50 If timebase is gateway, then set sync to gateway */
#  if (STBM_CONFIG_GATEWAY == STD_ON)
        if (StbM_TimeBase_IsGateway(StbM_GetTimeBaseConfigIdxOfTimeoutConfig(timeoutIdx, partitionIdx), partitionIdx) == TRUE)
        {
          StbM_Status_SetSyncToGateway(StbM_GetTimeBaseConfigIdxOfTimeoutConfig(timeoutIdx, partitionIdx), partitionIdx);
        }
#  endif

        /* #60 Stop invalid rate measurements */
#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
        if (StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured(StbM_GetTimeBaseConfigIdxOfTimeoutConfig(timeoutIdx, partitionIdx), partitionIdx) == TRUE)
        {
          StbM_TimeCorrection_StopInvalidRateMeasurement(StbM_GetTimeBaseConfigIdxOfTimeoutConfig(timeoutIdx, partitionIdx), partitionIdx);
        }
#  endif
      }
    }
  }

  /* #70 Exit exclusive area */
  StbM_LeaveCritical_CrossCore();
} /* StbM_Timeout_Update */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_TIMEOUT == STD_ON) */
#endif /* STBM_NOUNIT_TIMEOUT */

#ifndef STBM_NOUNIT_USERDATA /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: UserData
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_UserData_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_UserData_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 i;
  StbM_UserDataType initUserData = {0u, 0u, 0u, 0u};

  /* ----- Implementation ----------------------------------------------- */
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Initialize all user data to zero */
  for (i = 0u; i < StbM_GetSizeOfUserDataState(partitionIdx); i++)
  {
    StbM_SetUserDataOfUserDataState(i, initUserData, partitionIdx); /* SBSW_STBM_ACCESS_USERDATASTATE */
  }
} /* StbM_UserData_Init */

/**********************************************************************************************************************
 *  StbM_UserData_Get
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_UserData_Get(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userData,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Copy the user data internal state table to given user data out parameter */
  *userData = StbM_GetUserDataOfUserDataState(StbM_GetUserDataStateIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_UserData_Get */

/**********************************************************************************************************************
 *  StbM_UserData_Set
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_UserData_Set(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userData,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 If given user data not null, copy the user data from given user data into internal state table */
  if (userData != NULL_PTR)
  {
    StbM_UserData_Copy(userData, StbM_GetAddrUserDataOfUserDataState(StbM_GetUserDataStateIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx)); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_ACCESS_CSL_VAR */
  }
} /* StbM_UserData_Set */

/**********************************************************************************************************************
 *  StbM_UserData_Copy
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_UserData_Copy(P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) src,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) dst)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Copy as many user data bytes from src to dst, as given in src user data length */
  switch (src->userDataLength)
  {
    case 3:
      dst->userByte0 = src->userByte0; /* SBSW_STBM_ACCESS_PARAMPTR */
      dst->userByte1 = src->userByte1; /* SBSW_STBM_ACCESS_PARAMPTR */
      dst->userByte2 = src->userByte2; /* SBSW_STBM_ACCESS_PARAMPTR */
      break;

    case 2:
      dst->userByte0 = src->userByte0; /* SBSW_STBM_ACCESS_PARAMPTR */
      dst->userByte1 = src->userByte1; /* SBSW_STBM_ACCESS_PARAMPTR */
      break;

    case 1:
      dst->userByte0 = src->userByte0; /* SBSW_STBM_ACCESS_PARAMPTR */
      break;

    default: /* COV_STBM_MSR_MISRA */
      /* In this error case nothing is copied. */
      break;
  }

  /* #20 If src user data length is greater than dst user data length, set dst user data length to new value */
  if (src->userDataLength > dst->userDataLength)
  {
    dst->userDataLength = src->userDataLength; /* SBSW_STBM_ACCESS_PARAMPTR */
  }
} /* StbM_UserData_Copy */
#endif /* STBM_NOUNIT_USERDATA */

#ifndef STBM_NOUNIT_TIMENOTIFICATION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_NOTIFICATION == STD_ON)
/**********************************************************************************************************************
 *  Unit: TimeNotification
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeNotification_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeNotification_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  StbM_CustomerIdType customerIdx;
  StbMTimeNotificationType TimeNotificationPtr;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured time notification customer: */
  for (customerIdx = 0u; customerIdx < StbM_GetSizeOfTimeNotificationConfig(partitionIdx); customerIdx++)
  {
    /* #20 Reset customer */
    StbM_TimeNotification_ResetCustomer(customerIdx, partitionIdx);

    /* #30 Get the configured callback function */
    TimeNotificationPtr = StbM_GetCallbackOfTimeNotificationCallback(StbM_GetTimeNotificationCallbackIdxOfTimeNotificationConfig(customerIdx, partitionIdx), partitionIdx);

    /* #40 If the callback function is null: */
    if (TimeNotificationPtr == NULL_PTR) /* COV_STBM_SILENT_XF */
    {
      /* #50 Set retVal to E_NOT_OK */
      retVal = E_NOT_OK;
    }
  }

  /* #60 Enable interrupt notification from Gpt */
  Gpt_EnableNotification(STBM_TIME_NOTIFICATION_GPT_CHANNEL);

  /* #70 Set global state of gpt timer stopped */
  StbM_TimeNotification_SetGptTimerStopped();

  /* #80 Set timer notification as not activated */
  StbM_TimeNotification_ClearNotificationTaskActivated();

  /* #90 Set StbM to be no longer in timer callback context */
  StbM_TimeNotification_ClearTimerCallbackContext();

  return retVal;
} /* StbM_TimeNotification_Init */

/**********************************************************************************************************************
 *  StbM_TimeNotification_ResetCustomer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_ResetCustomer(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

  /* #10 Set initial timer state to STOPPED */
  StbM_TimeNotification_SetTimerStopped(customerId, partitionIdx);

  /* #20 Set expire time to zero */
  StbM_SetStartTimeOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), STBM_ZERO_TIME, StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_TIMENOTIFICATIONSTATE_IND_TIMENOTIFICATIONPARTITIONMAPPING */
} /* StbM_TimeNotification_ResetCustomer */

/**********************************************************************************************************************
 *  StbM_TimeNotification_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_Update(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If Gpt timer is stopped: */
  if (StbM_TimeNotification_IsGptTimerStopped() == TRUE)
  {
    StbM_CustomerIdType nextCustomer = STBM_INVALID_TIME_NOTIFICATION_CUSTOMER;
    StbM_PartitionIdentifiersIterType partitionIdx = 0u;

    /* #20 Get next startable timer */
    StbM_TimeNotification_GetNextRunnableTimer(&nextCustomer, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #30 If next startable timer exists: */
    if (nextCustomer < StbM_GetSizeOfTimeNotificationConfig(partitionIdx))
    {
      /* #40 Run customers timer */
      StbM_TimeNotification_RunTimer(nextCustomer, partitionIdx);
    }
  }
} /* StbM_TimeNotification_Update */

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetNextRunnableTimer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_GetNextRunnableTimer(
        P2VAR(StbM_CustomerIdType, AUTOMATIC, STBM_APPL_VAR) customerId,
        P2VAR(StbM_PartitionIdentifiersIterType, AUTOMATIC, STBM_APPL_VAR) partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_CustomerIdType customerIdx;
  StbM_PartitionIdentifiersIterType curPartitionIdx;
  StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType startTime = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType minimumExpireTime = {STBM_TIMESTAMP_MAX_NANOSECONDS, STBM_TIMESTAMP_MAX_SECONDS, STBM_TIMESTAMP_MAX_SECONDSHI};

  /* ----- Implementation ----------------------------------------------- */
  *customerId = STBM_INVALID_TIME_NOTIFICATION_CUSTOMER; /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #10 For each configured time notification customer: */
  for (curPartitionIdx = 0u; curPartitionIdx < StbM_GetSizeOfPartitionIdentifiers(); curPartitionIdx++)
  {
    for (customerIdx = 0u; customerIdx < StbM_GetSizeOfTimeNotificationConfig(curPartitionIdx); customerIdx++)
    {
      /* #20 If customer is started: */
      if (StbM_TimeNotification_IsTimerStarted(customerIdx, curPartitionIdx) == TRUE)
      {
        StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
        StbM_PartitionIdentifiersIterType timeBasePartitionIdx = 0u;

        /* #30 Get current time of associated timebase */
        StbM_TimeBase_GetPartitionMapping(StbM_GetTimeBasePartitionMappingIdxOfTimeNotificationConfig(customerIdx, curPartitionIdx), &timeBaseIdx, &timeBasePartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
        retVal = StbM_LocalTime_GetLastUpdatedLocalTime(timeBaseIdx, &localTime, timeBasePartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

        if (retVal == E_OK)
        {
          /* #40 Get the time when customer is in its threshold i.e. StartTime */
          StbM_TimeNotification_GetStartTime(customerIdx, &startTime, curPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

          /* #50 If StartTime is less or equal to current time (i.e. timer is within threshold) and StartTime is minimal, store customer and associated data */
          if ((StbM_Calc_LessEqualThan(&startTime, &localTime) == TRUE) && (StbM_Calc_LessEqualThan(&startTime, &minimumExpireTime) == TRUE)) /* PRQA S 3415 */ /* MD_StbM_Rule13.5_3415 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
          {
            minimumExpireTime = startTime;
            *customerId = customerIdx; /* SBSW_STBM_ACCESS_PARAMPTR */
            *partitionIdx = curPartitionIdx; /* SBSW_STBM_ACCESS_PARAMPTR */
          }
        }
        else
        {
          /* #60 If retrieval of current time failed, stop timer */
          StbM_TimeNotification_SetTimerStopped(customerIdx, curPartitionIdx);
        }
      }
    }
  }
} /* StbM_TimeNotification_GetNextRunnableTimer */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  StbM_TimeNotification_RunTimer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_RunTimer(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType expireTime = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType timeBasePartitionIdx = 0u;

  /* #10 Get current time of associated timebase */
  StbM_TimeBase_GetPartitionMapping(StbM_GetTimeBasePartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx), &timeBaseIdx, &timeBasePartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  (void) StbM_LocalTime_GetLastUpdatedLocalTime(timeBaseIdx, &localTime, timeBasePartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Get expire time of customer */
  StbM_TimeNotification_GetExpireTime(customerId, &expireTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #30 If expire time <= local time, start timer immediately */
  if (StbM_Calc_LessEqualThan(&expireTime, &localTime) == TRUE) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  {
    StbM_TimeNotification_StartTimerImmediately(customerId, partitionIdx);
  }
  /* #40 Otherwise, start gpt timer */
  else
  {
    StbM_InternalTimeStampType remainingTime = STBM_INIT_TIME_ZERO;
    uint32 remainingTimeNs = 0u;

    /* #50 Calculate the remaining = time expire time - current time */
    (void) StbM_Calc_SubtractTimeStamps(&expireTime, &localTime, &remainingTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #60 Convert to nanoseconds, no overflow check needed, at this point expire time can be max 2s */
    (void) StbM_Calc_ToNanoseconds(&remainingTime, &remainingTimeNs); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #70 Call Gpt_StartTimer and pass converted expire time to gpt ticks */
    Gpt_StartTimer(STBM_TIME_NOTIFICATION_GPT_CHANNEL, remainingTimeNs / STBM_NS_TICKS_GPT_NOTIFICATION_TIMER);

    /* #80 Set Gpt to running state */
    StbM_TimeNotification_SetGptTimerRunning();

    /* #90 Set customer to running state */
    StbM_TimeNotification_SetTimerRunning(customerId, partitionIdx);
  }
} /* StbM_TimeNotification_RunTimer */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_TimeNotification_StartTimerImmediately
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_StartTimerImmediately(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the timer of customer to expired */
  StbM_TimeNotification_SetTimerExpired(customerId, partitionIdx);

  /* #20 Check that StbM has not already activated timer notification task and StbM is not in timer callback context */
  if ((StbM_TimeNotification_IsNotificationTaskActivated() == FALSE) && (StbM_TimeNotification_IsTimerCallbackContext() == FALSE))
  {
    /* #30 Activate the associated task of callback */
    StbM_TimeNotification_ActivateTaskForCallback();
  }
} /* StbM_TimeNotification_StartTimerImmediately */

/**********************************************************************************************************************
 *  StbM_TimeNotification_StartTimer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeNotification_StartTimer(
        StbM_CustomerIdType customerId,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) expireTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If given time notification customer has a stopped timer: */
  if (StbM_TimeNotification_IsTimerStopped(customerId, partitionIdx) == TRUE)
  {
    StbM_InternalTimeStampType mainFunctionCycle = {(StbM_NanosecondsType)STBM_MAINFUNCTION_CYCLETIME_NS, (StbM_SecondsType)STBM_MAINFUNCTION_CYCLETIME_S, (StbM_SecondsHiType)STBM_MAINFUNCTION_CYCLETIME_S_HI};
    StbM_InternalTimeStampType thresholdMax = {(StbM_NanosecondsType)STBM_MAX_GPT_THRESHOLD_NS, (StbM_SecondsType)STBM_MAX_GPT_THRESHOLD_S, (StbM_SecondsHiType)STBM_MAX_GPT_THRESHOLD_HIS};

    /* #20 If expire time is greater than main function cycle and either Gpt timer is stopped or expire time is greater than max threshold of all customers: */
    if ((StbM_Calc_LessEqualThan(expireTime, &mainFunctionCycle) == FALSE) && ((StbM_TimeNotification_IsGptTimerStopped() == TRUE) || (StbM_Calc_LessEqualThan(expireTime, &thresholdMax) == FALSE))) /* PRQA S 3415 */ /* MD_StbM_Rule13.5_3415 */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    {
      StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;
      StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
      StbM_InternalTimeStampType expirationPointForImmediateStart = STBM_INIT_TIME_ZERO;
      StbM_InternalTimeStampType expirationPointForGptStart = STBM_INIT_TIME_ZERO;
      StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
      StbM_PartitionIdentifiersIterType timeBasePartitionIdx = 0u;

      /* #30 Get current time of associated timebase */
      StbM_TimeBase_GetPartitionMapping(StbM_GetTimeBasePartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx), &timeBaseIdx, &timeBasePartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      retVal = StbM_GlobalTime_GetTime(timeBaseIdx, &localTime, &virtualLocalTime, timeBasePartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      /* #40 Calculate the final expiration point = current time + expire time, if succeeded (expire time is reachable): */
      retVal |= StbM_Calc_AddTimeStamps(expireTime, &localTime, &expirationPointForImmediateStart); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      if (retVal == E_OK)
      {
        StbM_InternalTimeStampType threshold = STBM_INIT_TIME_ZERO;

        /* #50 Get the configured threshold of customer */
        StbM_TimeNotification_GetThreshold(customerId, &threshold, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

        /* #60 Calculate the expiration point to start the timer = final expiration point - threshold */
        /* #70 If expiration point is not expired: */
        if (StbM_Calc_SubtractTimeStamps(&expirationPointForImmediateStart, &threshold, &expirationPointForGptStart) == E_OK) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
        {
          /* #80 Set the StartTime = expiration point to start the timer */
          StbM_TimeNotification_SetStartTime(customerId, &expirationPointForGptStart, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
        }
        else
        {
          /* #90 Otherwise, timer is already expired, set it to the current time in order to get it started as soon as possible */
          StbM_TimeNotification_SetStartTime(customerId, &localTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
        }

        /* #100 Set the ExpireTime = final expiration point */
        StbM_TimeNotification_SetExpireTime(customerId, &expirationPointForImmediateStart, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

        /* #110 Set state of timer to started */
        StbM_TimeNotification_SetTimerStarted(customerId, partitionIdx);
      }
    }
  }
  return retVal;
} /* StbM_TimeNotification_StartTimer */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_TimeNotification_NotifyCustomers
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 ********************************************************************************************************************/
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_NotifyCustomers(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_CustomerIdType customerId;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured time notification customer: */
  for (customerId = 0u; customerId < StbM_GetSizeOfTimeNotificationConfig(partitionIdx); customerId++)
  {
    /* #20 If customer has expired timer: */
    if (StbM_TimeNotification_IsTimerExpired(customerId, partitionIdx) == TRUE)
    {
      /* #30 Get callback function */
      StbMTimeNotificationType TimeNotificationPtr = StbM_GetCallbackOfTimeNotificationCallback(StbM_GetTimeNotificationCallbackIdxOfTimeNotificationConfig(customerId, partitionIdx), partitionIdx);

      StbM_TimeDiffType deviationTime = 0;

      /* #40 Calculate the deviation time */
      if (StbM_TimeNotification_CalculateDeviationTime(customerId, &deviationTime, partitionIdx) == E_OK) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      {
        /* #50 Call callback and provide deviation time */
        (void)TimeNotificationPtr(deviationTime); /* SBSW_STBM_FCTPTRCALL_NOTIFICATION */
      }

      /* #60 Reset customer */
      StbM_TimeNotification_ResetCustomer(customerId, partitionIdx);

      /* #70 Clear timer notification task activated */
      StbM_TimeNotification_ClearNotificationTaskActivated();
    }
  }
} /* StbM_TimeNotification_NotifyCustomers */

/**********************************************************************************************************************
 *  StbM_TimeNotification_ProcessTimerCallback
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_ProcessTimerCallback(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_PartitionIdentifiersIterType partitionIdx;
  StbM_CustomerIdType customerIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set StbM is in timer callback context */
  StbM_TimeNotification_SetTimerCallbackContext();

  /* #20 For each configured time notification customer: */
  for (partitionIdx = 0u; partitionIdx < StbM_GetSizeOfPartitionIdentifiers(); partitionIdx++)
  {
    for (customerIdx = 0u; customerIdx < StbM_GetSizeOfTimeNotificationConfig(partitionIdx); customerIdx++)
    {
      /* #30 If customer is running (only one customer at a time can run): */
      if (StbM_TimeNotification_IsTimerRunning(customerIdx, partitionIdx) == TRUE)
      {
        /* #40 Set customer to expired and break */
        StbM_TimeNotification_SetTimerExpired(customerIdx, partitionIdx);
        break;
      }
    }
  }

  /* #50 Set Gpt timer stopped */
  StbM_TimeNotification_SetGptTimerStopped();

  /* #60 Update local time */
  for (partitionIdx = 0u; partitionIdx < StbM_GetSizeOfPartitionIdentifiers(); partitionIdx++)
  {
    StbM_LocalTime_UpdateLocalTime(partitionIdx);
  }

  /* #70 Update time notification unit */
  StbM_TimeNotification_Update();

  /* #80 Clear StbM is in timer callback context */
  StbM_TimeNotification_ClearTimerCallbackContext();
} /* StbM_TimeNotification_ProcessTimerCallback */

/**********************************************************************************************************************
 *  StbM_TimeNotification_ActivateTaskForCallback
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_ActivateTaskForCallback(void)
{
  /* #10 Activate the high prio task, which calls the the actual callback function */
#  if (STBM_USE_OS_SET_EVENT_API == STD_ON)
  (void) SetEvent(STBM_TIME_CUSTOMER_TASK_NAME, STBM_TIME_CUSTOMER_EVENT_NAME);
#  else
  (void) ActivateTask(STBM_TIME_CUSTOMER_TASK_NAME);
#  endif

  /* #20 Set timer notification task as activated */
  StbM_TimeNotification_SetNotificationTaskActivated();
} /* StbM_TimeNotification_ActivateTaskForCallback */

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerStarted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerStarted(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if timer of the given customer has the state STBM_NOTIFICATION_TIMER_STARTED */
  return (StbM_GetTimerStateOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)) == STBM_NOTIFICATION_TIMER_STARTED);
} /* StbM_TimeNotification_IsTimerStarted */

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerRunning
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerRunning(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if timer of the given customer has the state STBM_NOTIFICATION_TIMER_RUNNING */
  return (StbM_GetTimerStateOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)) == STBM_NOTIFICATION_TIMER_RUNNING);
} /* StbM_TimeNotification_IsTimerRunning */

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerExpired(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if timer of the given customer has the state STBM_NOTIFICATION_TIMER_EXPIRED */
  return (StbM_GetTimerStateOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)) == STBM_NOTIFICATION_TIMER_EXPIRED);
} /* StbM_TimeNotification_IsTimerExpired */

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerStopped
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerStopped(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if timer of the given customer has the state STBM_NOTIFICATION_TIMER_STOPPED */
  return (StbM_GetTimerStateOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)) == STBM_NOTIFICATION_TIMER_STOPPED);
} /* StbM_TimeNotification_IsTimerStopped */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerStarted
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerStarted(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set the timer state of the given customer to STBM_NOTIFICATION_TIMER_STARTED */
  StbM_SetTimerStateOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), STBM_NOTIFICATION_TIMER_STARTED, StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_TIMENOTIFICATIONSTATE_IND_TIMENOTIFICATIONPARTITIONMAPPING */
} /* StbM_TimeNotification_SetTimerStarted */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerRunning
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerRunning(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set the timer state of the given customer to STBM_NOTIFICATION_TIMER_RUNNING */
  StbM_SetTimerStateOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), STBM_NOTIFICATION_TIMER_RUNNING, StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_TIMENOTIFICATIONSTATE_IND_TIMENOTIFICATIONPARTITIONMAPPING */
} /* StbM_TimeNotification_SetTimerRunning */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerExpired(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set the timer state of the given customer to STBM_NOTIFICATION_TIMER_EXPIRED */
  StbM_SetTimerStateOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), STBM_NOTIFICATION_TIMER_EXPIRED, StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_TIMENOTIFICATIONSTATE_IND_TIMENOTIFICATIONPARTITIONMAPPING */
} /* StbM_TimeNotification_SetTimerExpired */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerStopped
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerStopped(
        StbM_CustomerIdType customerId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set the timer state of the given customer to STBM_NOTIFICATION_TIMER_STOPPED */
  StbM_SetTimerStateOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), STBM_NOTIFICATION_TIMER_STOPPED, StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_TIMENOTIFICATIONSTATE_IND_TIMENOTIFICATIONPARTITIONMAPPING */
} /* StbM_TimeNotification_SetTimerStopped */

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetThreshold
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_GetThreshold(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) threshold,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the threshold for time notification */
  threshold->secondsHi = 0u; /* SBSW_STBM_ACCESS_PARAMPTR */
  threshold->seconds = StbM_GetTimerStartThresholdSecondsOfTimeNotificationConfig(customerId, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  threshold->nanoseconds = StbM_GetTimerStartThresholdNanosecondsOfTimeNotificationConfig(customerId, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeNotification_GetThreshold */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetExpireTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetExpireTime(
        StbM_CustomerIdType customerId,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) expireTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set expire time, corresponds to final expiration point */
  StbM_SetExpireTimeOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), *expireTime, StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_TIMENOTIFICATIONSTATE_IND_TIMENOTIFICATIONPARTITIONMAPPING */
} /* StbM_TimeNotification_SetExpireTime */

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetExpireTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_GetExpireTime(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) expireTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get expire time, corresponds to final expiration point */
  *expireTime = StbM_GetExpireTimeOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeNotification_GetExpireTime */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetStartTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeNotification_SetStartTime(
        StbM_CustomerIdType customerId,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) startTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set start time, corresponds to expire time - threshold */
  StbM_SetStartTimeOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), *startTime, StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_TIMENOTIFICATIONSTATE_IND_TIMENOTIFICATIONPARTITIONMAPPING */
} /* StbM_TimeNotification_SetStartTime */

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetStartTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_GetStartTime(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) startTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_CustomerIdType customerIdx = StbM_GetTimeNotificationPartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get start time, corresponds to expire time - threshold */
  *startTime = StbM_GetStartTimeOfTimeNotificationState(StbM_GetIndirectionToTimeNotificationStateIdxOfTimeNotificationPartitionMapping(customerIdx), StbM_GetIndirectionToTimeNotificationStatePartitionIdxOfTimeNotificationPartitionMapping(customerIdx)); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeNotification_GetStartTime */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetGptTimerRunning
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetGptTimerRunning(void)
{
  /* #10 Set gpt state to STBM_GPT_TIMER_RUNNING */
  StbM_GptTimerState = STBM_GPT_TIMER_RUNNING;
} /* StbM_TimeNotification_SetGptTimerRunning */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetGptTimerStopped
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetGptTimerStopped(void)
{
  /* #10 Set gpt state to STBM_GPT_TIMER_STOPPED */
  StbM_GptTimerState = STBM_GPT_TIMER_STOPPED;
} /* StbM_TimeNotification_SetGptTimerStopped */

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsGptTimerStopped
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsGptTimerStopped(void)
{
  /* #10 Return true if gpt timer is set to STBM_GPT_TIMER_STOPPED */
  return ((StbM_GptTimerState == STBM_GPT_TIMER_STOPPED) == TRUE);
} /* StbM_TimeNotification_IsGptTimerStopped */

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsTimerCallbackContext
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsTimerCallbackContext(void)
{
  /* #10 Check if StbM is in timer callback context */
  return (StbM_TimerCallbackContextActive == TRUE);
} /* StbM_TimeNotification_IsTimerCallbackContext */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetTimerCallbackContext
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetTimerCallbackContext(void)
{
  /* #10 Set StbM timer callback context indication as true */
  StbM_TimerCallbackContextActive = TRUE;
} /* StbM_TimeNotification_SetTimerCallbackContext */

/**********************************************************************************************************************
 *  StbM_TimeNotification_ClearTimerCallbackContext
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_ClearTimerCallbackContext(void)
{
  /* #10 Set StbM timer callback context indication as false */
  StbM_TimerCallbackContextActive = FALSE;
} /* StbM_TimeNotification_ClearTimerCallbackContext */

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsNotificationTaskActivated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsNotificationTaskActivated(void)
{
  /* #10 Check if StbM has activated timer notification task */
  return (StbM_NotificationTaskActivated == TRUE);
} /* StbM_TimeNotification_IsNotificationTaskActivated */

/**********************************************************************************************************************
 *  StbM_TimeNotification_SetNotificationTaskActivated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_SetNotificationTaskActivated(void)
{
  /* #10 Set timer notification task as activated */
  StbM_NotificationTaskActivated = TRUE;
} /* StbM_TimeNotification_SetNotificationTaskActivated */

/**********************************************************************************************************************
 *  StbM_TimeNotification_ClearNotificationTaskActivated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_ClearNotificationTaskActivated(void)
{
  /* #10 Set timer notification task as not activated */
  StbM_NotificationTaskActivated = FALSE;
} /* StbM_TimeNotification_ClearNotificationTaskActivated */

/**********************************************************************************************************************
 *  StbM_TimeNotification_CalculateDeviationTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeNotification_CalculateDeviationTime(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_TimeDiffType, AUTOMATIC, STBM_APPL_VAR) deviationTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType timeBasePartitionIdx = 0u;
  StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;
  StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_InternalTimeStampType expireTime = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType differenceLocalTimeExpireTime = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType maxDeviation = {147483647u, 2u, 0u}; /* range of StbM_TimeDiffType */
  uint32 absDeviationTimeNs = 0u;
  Std_ReturnType retVal;
  Std_ReturnType isDeviationTimePositive;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get time of associated timebase */
  StbM_TimeBase_GetPartitionMapping(StbM_GetTimeBasePartitionMappingIdxOfTimeNotificationConfig(customerId, partitionIdx), &timeBaseIdx, &timeBasePartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  retVal = StbM_GlobalTime_GetTime(timeBaseIdx, &localTime, &virtualLocalTime, timeBasePartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Get expire time of customer */
  StbM_TimeNotification_GetExpireTime(customerId, &expireTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #30 Calculate deviation time: dT = expire time - local time */
  isDeviationTimePositive = StbM_Calc_SubtractTimeStamps(&localTime, &expireTime, &differenceLocalTimeExpireTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #40 Set the deviation time to within the max possible range of StbM_TimeDiffType */
  if (StbM_Calc_LessThan(&maxDeviation, &differenceLocalTimeExpireTime) == TRUE) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  {
    differenceLocalTimeExpireTime = maxDeviation;
  }

  /* #50 Convert deviation time to nanoseconds */
  (void) StbM_Calc_ToNanoseconds(&differenceLocalTimeExpireTime, &absDeviationTimeNs); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #60 Set the sign to deviation time */
  if (isDeviationTimePositive == E_NOT_OK)
  {
    *deviationTime = -((sint32)absDeviationTimeNs);  /* SBSW_STBM_ACCESS_PARAMPTR */
  }
  else
  {
    *deviationTime = (sint32)absDeviationTimeNs; /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  StbM_TimeNotification_GetPartitionMapping
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeNotification_GetPartitionMapping(
        StbM_CustomerIdType customerId,
        P2VAR(StbM_CustomerIdType, AUTOMATIC, STBM_APPL_VAR) customerIdx,
        P2VAR(StbM_PartitionIdentifiersIterType, AUTOMATIC, STBM_APPL_VAR) partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  if (StbM_TimeNotification_IsCustomerIdValid(customerId) == TRUE)
  {
#  if (STBM_MULTIPARTITION_USED == STD_ON)
    *customerIdx = StbM_GetIndirectionToTimeNotificationConfigIdxOfTimeNotificationPartitionMapping(customerId); /* SBSW_STBM_ACCESS_PARAMPTR */
    *partitionIdx = StbM_GetIndirectionToTimeNotificationConfigPartitionIdxOfTimeNotificationPartitionMapping(customerId); /* SBSW_STBM_ACCESS_PARAMPTR */
#  else
    *customerIdx = customerId; /* SBSW_STBM_ACCESS_PARAMPTR */
    *partitionIdx = 0u; /* SBSW_STBM_ACCESS_PARAMPTR */
#  endif
  }
} /* StbM_TimeNotification_GetPartitionMapping */

/**********************************************************************************************************************
 *  StbM_TimeNotification_IsCustomerIdValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeNotification_IsCustomerIdValid(
        StbM_CustomerIdType customerId)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if customer id is valid */
#   if (STBM_MULTIPARTITION_USED == STD_ON)
  return (customerId < StbM_GetSizeOfTimeNotificationPartitionMapping());
#   else
  return (customerId < StbM_GetSizeOfTimeNotificationConfig(0u));
#   endif
} /* StbM_TimeNotification_IsCustomerIdValid */
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) */
#endif /* STBM_NOUNIT_TIMENOTIFICATION */

#ifndef STBM_NOUNIT_TIMELEAP /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_LEAP == STD_ON)
/**********************************************************************************************************************
 *  Unit: TimeLeap
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeLeap_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeLeapConfigIterType timeLeapIdx;

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 For each configured time leap: */
  for (timeLeapIdx = 0u; timeLeapIdx < StbM_GetSizeOfTimeLeapClearState(partitionIdx); timeLeapIdx++)
  {
    /* #20 Set clear counts for time leap to zero */
    StbM_SetClearCountFutureOfTimeLeapClearState(timeLeapIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAPCLEARSTATE */
    StbM_SetClearCountPastOfTimeLeapClearState(timeLeapIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAPCLEARSTATE */
  }
}

/**********************************************************************************************************************
 *  StbM_TimeLeap_ResetClearCounterFuture
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_ResetClearCounterFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Reset the future time leap counter to the configured value */
  StbM_SetClearCountFutureOfTimeLeapClearState(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), StbM_GetClearCountOfTimeLeapConfig(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAPCLEARSTATE_IND_TIMEBASECONFIG */
} /* StbM_TimeLeap_ResetClearCounterFuture */

/**********************************************************************************************************************
 *  StbM_TimeLeap_ResetClearCounterPast
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_ResetClearCounterPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Reset the past time leap counter to the configured value */
  StbM_SetClearCountPastOfTimeLeapClearState(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), StbM_GetClearCountOfTimeLeapConfig(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAPCLEARSTATE_IND_TIMEBASECONFIG */
} /* StbM_TimeLeap_ResetClearCounterPast */

/**********************************************************************************************************************
 *  StbM_TimeLeap_UpdateClearCounterFuture
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_UpdateClearCounterFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 If future clear counter is greater than zero, decrement by one */
  if (StbM_GetClearCountFutureOfTimeLeapClearState(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx) > 0u)
  {
    StbM_DecClearCountFutureOfTimeLeapClearState(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAPCLEARSTATE_IND_TIMEBASECONFIG */
  }
} /* StbM_TimeLeap_UpdateClearCounterFuture */

/**********************************************************************************************************************
 *  StbM_TimeLeap_UpdateClearCounterPast
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_UpdateClearCounterPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 If past clear counter is greater than zero, decrement by one */
  if (StbM_GetClearCountPastOfTimeLeapClearState(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx) > 0u)
  {
    StbM_DecClearCountPastOfTimeLeapClearState(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAPCLEARSTATE_IND_TIMEBASECONFIG */
  }
} /* StbM_TimeLeap_UpdateClearCounterPast */

/**********************************************************************************************************************
 *  StbM_TimeLeap_IsClearCounterFutureExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_IsClearCounterFutureExpired(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the future clear count of time leap is zero */
  return (StbM_GetClearCountFutureOfTimeLeapClearState(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx) == 0u);
} /* StbM_TimeLeap_IsClearCounterFutureExpired */

/**********************************************************************************************************************
 *  StbM_TimeLeap_IsClearCounterPastExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_IsClearCounterPastExpired(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the past clear count of time leap is zero */
  return (StbM_GetClearCountPastOfTimeLeapClearState(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx) == 0u);
} /* StbM_TimeLeap_IsClearCounterPastExpired */

/**********************************************************************************************************************
 *  StbM_TimeLeap_UpdateLeapStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_UpdateLeapStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 If time leap future clear counter expired, reset time leap status */
  if (StbM_TimeLeap_IsClearCounterFutureExpired(timeBaseIdx, partitionIdx) == TRUE)
  {
      StbM_Status_ClearTimeLeapFuture(timeBaseIdx, partitionIdx);
  }

  /* #20 If time leap past clear counter expired, reset time leap status */
  if (StbM_TimeLeap_IsClearCounterPastExpired(timeBaseIdx, partitionIdx) == TRUE)
  {
      StbM_Status_ClearTimeLeapPast(timeBaseIdx, partitionIdx);
  }
} /* StbM_TimeLeap_UpdateLeapStatus */

/**********************************************************************************************************************
 *  StbM_TimeLeap_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeLeap_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If time leap is configured and global timebase bit is set */
  if ((StbM_TimeLeap_HasTimeLeapConfigured(timeBaseIdx, partitionIdx) == TRUE) && (StbM_Status_IsSynchronized(timeBaseIdx, partitionIdx) == TRUE))
  {
    /* #20 Get the time leap */
    StbM_TimeDiffType timeLeap = StbM_LocalTime_GetTimeLeap(timeBaseIdx, partitionIdx);

    /* #30 Decrement time leap clear counter */
    StbM_TimeLeap_UpdateClearCounterFuture(timeBaseIdx, partitionIdx);
    StbM_TimeLeap_UpdateClearCounterPast(timeBaseIdx, partitionIdx);

    /* #40 If time leap future occurred: */
    if (StbM_TimeLeap_IsTimeLeapFuture(timeBaseIdx, timeLeap, partitionIdx) == TRUE)
    {
      /* #50 Set time leap future status */
      StbM_Status_SetTimeLeapFuture(timeBaseIdx, partitionIdx);

      /* #60 Clear future time leap clear counter */
      StbM_TimeLeap_ResetClearCounterFuture(timeBaseIdx, partitionIdx);
    }

    /* #70 If time leap past occurred: */
    if (StbM_TimeLeap_IsTimeLeapPast(timeBaseIdx, timeLeap, partitionIdx) == TRUE)
    {
      /* #80 Set time leap past status */
      StbM_Status_SetTimeLeapPast(timeBaseIdx, partitionIdx);

      /* #90 Clear past time leap clear counter */
      StbM_TimeLeap_ResetClearCounterPast(timeBaseIdx, partitionIdx);
    }

    /* #100 Update time leap status */
    StbM_TimeLeap_UpdateLeapStatus(timeBaseIdx, partitionIdx);
  }
} /* StbM_TimeLeap_Update */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_TimeLeap_GetFutureThreshold
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_NanosecondsType, STBM_CODE) StbM_TimeLeap_GetFutureThreshold(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the future time leap threshold */
  return StbM_GetFutureThresholdOfTimeLeapConfig(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_TimeLeap_GetFutureThreshold */

/**********************************************************************************************************************
 *  StbM_TimeLeap_GetPastThreshold
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_NanosecondsType, STBM_CODE) StbM_TimeLeap_GetPastThreshold(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the past time leap threshold */
  return StbM_GetPastThresholdOfTimeLeapConfig(StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_TimeLeap_GetPastThreshold */

/**********************************************************************************************************************
 *  StbM_TimeLeap_IsTimeLeapFuture
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_IsTimeLeapFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeDiffType timeLeap,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_TimeDiffType timeLeapFutureThreshold = (StbM_TimeDiffType)StbM_TimeLeap_GetFutureThreshold(timeBaseIdx, partitionIdx);

  /* #10 Check if the time leap future check is activated and the given time leap is greater than the configured time leap future threshold */
  return ((timeLeapFutureThreshold > 0) && (timeLeap > timeLeapFutureThreshold));
} /* StbM_TimeLeap_IsTimeLeapFuture */

/**********************************************************************************************************************
 *  StbM_TimeLeap_IsTimeLeapPast
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_IsTimeLeapPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeDiffType timeLeap,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_TimeDiffType timeLeapPastThreshold = (StbM_TimeDiffType)StbM_TimeLeap_GetPastThreshold(timeBaseIdx, partitionIdx);

  /* #10 Check if the time leap past check is activated and the given time leap is less than the configured time leap past threshold */
  return ((timeLeapPastThreshold > 0) && (timeLeap < -(timeLeapPastThreshold)));
} /* StbM_TimeLeap_IsTimeLeapPast */

/**********************************************************************************************************************
 *  StbM_TimeLeap_HasTimeLeapConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeLeap_HasTimeLeapConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the indirection of timebase config to time leap config table exists */
  return (StbM_GetTimeLeapConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx) < StbM_GetSizeOfTimeLeapConfig(partitionIdx));
} /* StbM_Timeout_HasTimeoutConfigured */
# endif /* (STBM_CONFIG_TIME_LEAP == STD_ON) */
#endif /* STBM_NOUNIT_TIMELEAP */

#ifndef STBM_NOUNIT_TIMERECORDING /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_RECORDING == STD_ON)
/**********************************************************************************************************************
 *  Unit: TimeRecording
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_TimeRecording_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeRecording_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint16 timeRecordingIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialization time recording blocks for synchronized timebase */
  StbM_TimeRecording_InitSyncBlocks(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */

  /* #20 Initialization time recording blocks for offset timebase */
#  if (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON)
  StbM_TimeRecording_InitOffsetBlocks(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
#  endif

  for (timeRecordingIdx = 0u; timeRecordingIdx < StbM_GetSizeOfTimeRecordingState(partitionIdx); timeRecordingIdx++)
  {
#  if (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON)
    if (StbM_TimeBase_IsOffset(StbM_GetTimeBaseConfigIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx), partitionIdx) == TRUE)
    {
      /* #30 Get callback index */
      uint8 offsetCallbackIdx = StbM_GetTimeRecordingOffsetCallbackIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx);

      /* #40 Get the configured callback function */
      StbM_OffsetTimeRecordBlockCallbackFctType OffsetTimeRecordBlockCallbackPtr = StbM_GetCallbackOfTimeRecordingOffsetCallback(offsetCallbackIdx, partitionIdx);

      /* #50 If the callback function for time recording is null: */
      if (OffsetTimeRecordBlockCallbackPtr == NULL_PTR) /* COV_STBM_SILENT_XF */
      {
        /* #60 Set retVal to E_NOT_OK */
        retVal = E_NOT_OK;
      }
    }
    else
#  endif
    {
      /* #30 Get callback index */
      uint8 syncCallbackIdx = StbM_GetTimeRecordingSyncCallbackIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx);

      /* #40 Get the configured callback function */
      StbM_SyncTimeRecordBlockCallbackFctType SyncTimeRecordBlockCallbackPtr = StbM_GetCallbackOfTimeRecordingSyncCallback(syncCallbackIdx, partitionIdx);

      /* #50 If the callback function for time recording is null: */
      if (SyncTimeRecordBlockCallbackPtr == NULL_PTR) /* COV_STBM_SILENT_XF */
      {
        /* #60 Set retVal to E_NOT_OK */
        retVal = E_NOT_OK;
      }
    }

    /* #70 Set current index of timebase block table to end block index, hence we start with the start index next time an index is requested */
    StbM_SetCurrentBlockIdxOfTimeRecordingState(timeRecordingIdx, (uint32)StbM_TimeRecording_GetEndBlockIndex(timeRecordingIdx, partitionIdx) - 1u, partitionIdx); /* SBSW_STBM_ACCESS_TIMERECORDINGSTATE */

    /* #80 Set path delay  to zero */
    StbM_SetPathDelayOfTimeRecordingState(timeRecordingIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMERECORDINGSTATE */

    /* #90 Set recorded blocks count to zero */
    StbM_SetRecordedBlocksCountOfTimeRecordingState(timeRecordingIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMERECORDINGSTATE */
  }

  return retVal;
} /* StbM_TimeRecording_Init */

/**********************************************************************************************************************
 *  StbM_TimeRecording_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalTimeStampType afterUpdateTimestamp = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Every slave has to have time recording configured, if time recording is enabled */
  if (StbM_TimeRecording_IsConfigured(timeBaseIdx, partitionIdx)) /* COV_STBM_SILENT_TX */
  {
    /* #20 Get current global time after reception of new time value */
    StbM_LocalTime_GetGlobalTimeRx(timeBaseIdx, &afterUpdateTimestamp, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

#  if (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON)
    if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
    {
      /* #30 If offset timebase, update time recording */
      StbM_TimeRecording_UpdateOffset(timeBaseIdx, &afterUpdateTimestamp, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    }
    else
#  endif
    {
      /* #40 Otherwise, synchronized timebase: */
      StbM_InternalTimeStampType beforeUpdateTimestamp = STBM_INIT_TIME_ZERO;

      /* #50 Get time before update (TLsync) */
      StbM_LocalTime_GetLocalTimeSync(timeBaseIdx, &beforeUpdateTimestamp, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      /* #60 Update time recording for synchronized timebase */
      StbM_TimeRecording_UpdateSync(timeBaseIdx, &beforeUpdateTimestamp, &afterUpdateTimestamp, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    }
  }
} /* StbM_TimeRecording_Update */

/**********************************************************************************************************************
 *  StbM_TimeRecording_NotifyCustomers
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_NotifyCustomers(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 timeRecordingIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter exclusive area in order to guarantee atomic notification of recorded blocks */
  StbM_EnterCritical_LocalCore();

  /* #20 For each configured time recording customer: */
  for (timeRecordingIdx = 0u; timeRecordingIdx < StbM_GetSizeOfTimeRecordingConfig(partitionIdx); timeRecordingIdx++)
  {
    uint16 committedBlocksCount = 0u;

    /* #30 Get recorded block count */
    uint16 blocksToCommit = StbM_TimeRecording_GetRecordedBlockCount(timeRecordingIdx, partitionIdx);

    /* #40 While blocks to commit: */
    while ((blocksToCommit > 0u) && (committedBlocksCount < StbM_GetBlockCountOfTimeRecordingConfig(timeRecordingIdx, partitionIdx))) /* COV_STBM_WHILE_COMMIT_BLOCKS */ /* FETA_StbM_BlocksToCommit */
    {
      /* #50 Get oldest block index */
      uint32 blockIdx = StbM_TimeRecording_GetOldestBlockIndex(timeRecordingIdx, partitionIdx);

      /* #60 Decrease recorded block count */
      StbM_DecRecordedBlocksCountOfTimeRecordingState(timeRecordingIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMERECORDINGSTATE */

      /* #70 Commit block to customer */
      StbM_TimeRecording_CommitBlock(timeRecordingIdx, blockIdx, partitionIdx);
      committedBlocksCount++;

      /* #80 Get recorded block count */
      blocksToCommit = StbM_TimeRecording_GetRecordedBlockCount(timeRecordingIdx, partitionIdx);
    }
  }

  /* #90 Exit exclusive area */
  StbM_LeaveCritical_LocalCore();
} /* StbM_TimeRecording_NotifyCustomers */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_TimeRecording_CommitBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_CommitBlock(
        uint16 timeRecordingIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON)
  if (StbM_TimeBase_IsOffset(StbM_GetTimeBaseConfigIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx), partitionIdx) == TRUE)
  {
    /* #10 Get the configured callback function */
    StbM_OffsetTimeRecordBlockCallbackFctType OffsetTimeRecordBlockCallbackPtr = StbM_GetCallbackOfTimeRecordingOffsetCallback(StbM_GetTimeRecordingOffsetCallbackIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx), partitionIdx);

    StbM_OffsetRecordTableBlockType block = {0};

    /* #20 Get the block data */
    StbM_TimeRecording_GetOffsetRecordTableBlock(blockIdx, &block, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #30 Exit exclusive area for callback */
    StbM_LeaveCritical_LocalCore();

    /* #40 Call callback with block data */
    (void)OffsetTimeRecordBlockCallbackPtr(&block); /* SBSW_STBM_FCTPTRCALL_RECORDTABLE */

    /* #50 Enter exclusive area */
    StbM_EnterCritical_LocalCore();
  }
  else
#  endif
  {
    /* #10 Get the configured callback function */
    StbM_SyncTimeRecordBlockCallbackFctType SyncTimeRecordBlockCallbackPtr = StbM_GetCallbackOfTimeRecordingSyncCallback(StbM_GetTimeRecordingSyncCallbackIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx), partitionIdx);

    StbM_SyncRecordTableBlockType block = {0};

    /* #20 Get the block data */
    StbM_TimeRecording_GetSyncRecordTableBlock(blockIdx, &block, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #30 Exit exclusive area for callback */
    StbM_LeaveCritical_LocalCore();

    /* #40 Call callback with block data */
    (void)SyncTimeRecordBlockCallbackPtr(&block); /* SBSW_STBM_FCTPTRCALL_RECORDTABLE */

    /* #50 Enter exclusive area */
    StbM_EnterCritical_LocalCore();
  }
} /* StbM_TimeRecording_CommitBlock */

/**********************************************************************************************************************
 *  StbM_TimeRecording_InitSyncBlocks
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_InitSyncBlocks(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 i;

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  for (i = 0u; i < StbM_GetSizeOfSyncTimeRecordingBlock(partitionIdx); i++)
  {
    /* #10 Set GlbNanoSeconds to zero */
    StbM_SetGlbNanoSecondsOfSyncTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    /* #20 Set GlbSeconds to zero */
    StbM_SetGlbSecondsOfSyncTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    /* #30 Set TimeBaseStatus to zero */
    StbM_SetTimeBaseStatusOfSyncTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    /* #40 Set VirtualLocalTimeLow to zero */
    StbM_SetVirtualLocalTimeLowOfSyncTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    /* #50 Set RateDeviation to zero */
    StbM_SetRateDeviationOfSyncTimeRecordingBlock(i, 0, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    /* #60 Set LocNanoSeconds to zero */
    StbM_SetLocNanoSecondsOfSyncTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    /* #70 Set LocSeconds to zero */
    StbM_SetLocSecondsOfSyncTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    /* #80 Set PathDelay to zero */
    StbM_SetPathDelayOfSyncTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
  }
} /* StbM_TimeRecording_InitSyncBlocks */

/**********************************************************************************************************************
 *  StbM_TimeRecording_UpdateSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_UpdateSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) beforeUpdateTimestamp,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) afterUpdateTimestamp,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 blockIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the next block index */
  blockIdx = StbM_TimeRecording_GetNextBlockIndex(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

  /* #20 If block index is valid: */
  if (blockIdx < StbM_GetSizeOfSyncTimeRecordingBlock(partitionIdx)) /* COV_STBM_SILENT_TX */
  {
    /* #30 Set GlbSeconds and GlbNanoSeconds */
    StbM_SetGlbSecondsOfSyncTimeRecordingBlock(blockIdx, afterUpdateTimestamp->seconds, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    StbM_SetGlbNanoSecondsOfSyncTimeRecordingBlock(blockIdx, afterUpdateTimestamp->nanoseconds, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */

    /* #40 Set LocSeconds and LocNanoSeconds */
    StbM_SetLocSecondsOfSyncTimeRecordingBlock(blockIdx, beforeUpdateTimestamp->seconds, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    StbM_SetLocNanoSecondsOfSyncTimeRecordingBlock(blockIdx, beforeUpdateTimestamp->nanoseconds, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */

    /* #50 Set the timebase status */
    StbM_SetTimeBaseStatusOfSyncTimeRecordingBlock(blockIdx, StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */

    /* #60 Set the pathdelay */
    StbM_SetPathDelayOfSyncTimeRecordingBlock(blockIdx, StbM_TimeRecording_GetPathDelay(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */

    /* #70 Set the rate deviation */
#  if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON))
    if (StbM_TimeCorrection_IsRateDeviationValid(timeBaseIdx, partitionIdx) == TRUE)
    {
      StbM_SetRateDeviationOfSyncTimeRecordingBlock(blockIdx, StbM_TimeCorrection_GetRateDeviation(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    }
    else
#  endif
    {
      StbM_SetRateDeviationOfSyncTimeRecordingBlock(blockIdx, 0, partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */
    }

    /* #80 Set the virtual local time low */
    StbM_SetVirtualLocalTimeLowOfSyncTimeRecordingBlock(blockIdx, StbM_LocalTime_GetVirtualLocalTimeLow(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK */

    /* #90 Update current block index */
    StbM_TimeRecording_SetCurrentBlockIndex(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), blockIdx, partitionIdx);

    /* #100 Increment recorded blocks count */
    StbM_TimeRecording_IncrementRecordedBlockCount(timeBaseIdx, partitionIdx);
  }
} /* StbM_TimeRecording_UpdateSync */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetNextBlockIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetNextBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 startBlockIdx = StbM_TimeRecording_GetStartBlockIndex(timeRecordingIdx, partitionIdx);
  uint32 endBlockIdx = StbM_TimeRecording_GetEndBlockIndex(timeRecordingIdx, partitionIdx);
  uint32 blockIdx = StbM_TimeRecording_GetCurrentBlockIndex(timeRecordingIdx, partitionIdx);

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return the next block index from the buffer, the calculation ensures that in case of an overflow the next block index will be the startBlockIdx again */
  blockIdx++;
  return ((blockIdx - startBlockIdx) % (endBlockIdx - startBlockIdx)) + startBlockIdx;
} /* StbM_TimeRecording_GetNextBlockIndex */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetStartBlockIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetStartBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 startIndex;

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the start index of time recording blocks */
#  if (STBM_CONFIG_TIME_RECORDING_OFFSET)
  if (StbM_TimeBase_IsOffset(StbM_GetTimeBaseConfigIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx), partitionIdx) == TRUE)
  {
    startIndex = StbM_GetOffsetTimeRecordingBlockStartIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx);
  }
  else
#  endif
  {
    startIndex = StbM_GetSyncTimeRecordingBlockStartIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx);
  }

  return startIndex;
} /* StbM_TimeRecording_GetStartBlockIndex */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetEndBlockIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetEndBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 endIndex;

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the end index of time recording blocks */
#  if (STBM_CONFIG_TIME_RECORDING_OFFSET)
  if (StbM_TimeBase_IsOffset(StbM_GetTimeBaseConfigIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx), partitionIdx) == TRUE)
  {
    endIndex = StbM_GetOffsetTimeRecordingBlockEndIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx);
  }
  else
#  endif
  {
    endIndex = StbM_GetSyncTimeRecordingBlockEndIdxOfTimeRecordingConfig(timeRecordingIdx, partitionIdx);
  }

  return endIndex;
} /* StbM_TimeRecording_GetEndBlockIndex */

/**********************************************************************************************************************
 *  StbM_TimeRecording_SetCurrentBlockIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_SetCurrentBlockIndex(
        uint16 timeRecordingIdx,
        uint32 index,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set the current used block index */
  StbM_SetCurrentBlockIdxOfTimeRecordingState(timeRecordingIdx, index, partitionIdx); /* SBSW_STBM_ACCESS_TIMERECORDINGSTATE_IND_TIMEBASECONFIG */
} /* StbM_TimeRecording_SetCurrentBlockIndex */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetCurrentBlockIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetCurrentBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

/* #10 Get the current block index of timebase */
  return StbM_GetCurrentBlockIdxOfTimeRecordingState(timeRecordingIdx, partitionIdx);
} /* StbM_TimeRecording_GetCurrentBlockIndex */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetOldestBlockIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetOldestBlockIndex(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 oldestBlockIdx;
  uint32 startBlockIdx = StbM_TimeRecording_GetStartBlockIndex(timeRecordingIdx, partitionIdx);
  uint32 endBlockIdx = StbM_TimeRecording_GetEndBlockIndex(timeRecordingIdx, partitionIdx);
  uint32 nextBlockIdx = StbM_TimeRecording_GetNextBlockIndex(timeRecordingIdx, partitionIdx);
  uint32 recordedBlockCount = StbM_TimeRecording_GetRecordedBlockCount(timeRecordingIdx, partitionIdx);
  uint32 blockCount = nextBlockIdx - startBlockIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the oldest block index, the calculation ensures that when the oldest block is overwritten, the next one in the buffer is automatically the oldest */
  if (blockCount < recordedBlockCount)
  {
    oldestBlockIdx = endBlockIdx - (recordedBlockCount - blockCount);
  }
  else
  {
    oldestBlockIdx = nextBlockIdx - recordedBlockCount;
  }

  return oldestBlockIdx;
} /* StbM_TimeRecording_GetOldestBlockIndex */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetRecordedBlockCount
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint16, STBM_CODE) StbM_TimeRecording_GetRecordedBlockCount(
        uint16 timeRecordingIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the current recorded block count */
  return StbM_GetRecordedBlocksCountOfTimeRecordingState(timeRecordingIdx, partitionIdx);
} /* StbM_TimeRecording_GetRecordedBlockCount */

/**********************************************************************************************************************
 *  StbM_TimeRecording_IncrementRecordedBlockCount
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeRecording_IncrementRecordedBlockCount(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  uint16 timeRecordingIdx = StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /*  #10 Increment recorded blocks count, if current value smaller than configured block count */
  if (StbM_TimeRecording_GetRecordedBlockCount(timeRecordingIdx, partitionIdx) < StbM_GetBlockCountOfTimeRecordingConfig(timeRecordingIdx, partitionIdx))
  {
    StbM_IncRecordedBlocksCountOfTimeRecordingState(timeRecordingIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMERECORDINGSTATE_IND_TIMEBASECONFIG */
  }
} /* StbM_TimeRecording_IncrementRecordedBlockCount */

/**********************************************************************************************************************
 *  StbM_TimeRecording_SetPathDelay
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_SetPathDelay(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        uint32 pathdelay,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set path delay for the given timebase */
  StbM_SetPathDelayOfTimeRecordingState(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), pathdelay, partitionIdx); /* SBSW_STBM_ACCESS_TIMERECORDINGSTATE_IND_TIMEBASECONFIG */
} /* StbM_TimeRecording_SetPathDelay */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetPathDelay
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_TimeRecording_GetPathDelay(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get path delay for the given timebase */
  return StbM_GetPathDelayOfTimeRecordingState(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_TimeRecording_GetPathDelay */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetSyncRecordTableHead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_GetSyncRecordTableHead(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_SyncRecordTableHeadType, AUTOMATIC, STBM_APPL_VAR) syncTableHead,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get time domain */
  syncTableHead->SynchronizedTimeDomain = StbM_GetTimeDomainOfSyncTimeRecordingHeader(StbM_GetSyncTimeRecordingHeaderIdxOfTimeRecordingConfig(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  /* #20 Get hardware frequency */
  syncTableHead->HWprescaler = StbM_GetHwPrescalerOfSyncTimeRecordingHeader(StbM_GetSyncTimeRecordingHeaderIdxOfTimeRecordingConfig(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  /* #30 Get hardware prescaler */
  syncTableHead->HWfrequency = StbM_GetHwFrequencyOfSyncTimeRecordingHeader(StbM_GetSyncTimeRecordingHeaderIdxOfTimeRecordingConfig(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeRecording_GetSyncRecordTableHead */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetSyncRecordTableBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_GetSyncRecordTableBlock(
        uint32 blockIdx,
        P2VAR(StbM_SyncRecordTableBlockType, AUTOMATIC, STBM_APPL_VAR) syncTableBlock,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get GlbNanoSeconds, GlbSeconds */
  syncTableBlock->GlbNanoSeconds = StbM_GetGlbNanoSecondsOfSyncTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  syncTableBlock->GlbSeconds = StbM_GetGlbSecondsOfSyncTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #20 Get LocNanoSeconds, LocSeconds */
  syncTableBlock->LocNanoSeconds = StbM_GetLocNanoSecondsOfSyncTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  syncTableBlock->LocSeconds = StbM_GetLocSecondsOfSyncTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #30 Get virtual local time low */
  syncTableBlock->VirtualLocalTimeLow = StbM_GetVirtualLocalTimeLowOfSyncTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #40 Get path delay */
  syncTableBlock->PathDelay = StbM_GetPathDelayOfSyncTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #50 Get rate deviation */
  syncTableBlock->RateDeviation = StbM_GetRateDeviationOfSyncTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #60 Get timebase status */
  syncTableBlock->TimeBaseStatus = StbM_GetTimeBaseStatusOfSyncTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeRecording_GetSyncRecordTableBlock */

/**********************************************************************************************************************
 *  StbM_TimeRecording_IsConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeRecording_IsConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 True, if given timebase has time recording configured */
  return (StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx) < StbM_GetSizeOfTimeRecordingConfig(partitionIdx));
} /* StbM_TimeRecording_IsConfigured */

#  if (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeRecording_InitOffsetBlocks
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_InitOffsetBlocks(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 i;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  for (i = 0u; i < StbM_GetSizeOfOffsetTimeRecordingBlock(partitionIdx); i++)
  {
    /* #10 Set GlbNanoSeconds to zero */
    StbM_SetGlbNanoSecondsOfOffsetTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_OFFSETTIMERECORDINGBLOCK */
    /* #20 Set GlbSeconds to zero */
    StbM_SetGlbSecondsOfOffsetTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_OFFSETTIMERECORDINGBLOCK */
    /* #30 Set TimeBaseStatus to zero */
    StbM_SetTimeBaseStatusOfOffsetTimeRecordingBlock(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_OFFSETTIMERECORDINGBLOCK */
  }
} /* StbM_TimeRecording_InitOffsetBlocks */

/**********************************************************************************************************************
 *  StbM_TimeRecording_UpdateOffset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_UpdateOffset(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) afterUpdateTimeStamp,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 blockIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the next block index */
  blockIdx = StbM_TimeRecording_GetNextBlockIndex(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

  /* #20 If block index is valid: */
  if (blockIdx < StbM_GetSizeOfOffsetTimeRecordingBlock(partitionIdx)) /* COV_STBM_SILENT_TX */
  {
    /* #30 Set GlbSeconds and GlbNanoSeconds */
    StbM_SetGlbSecondsOfOffsetTimeRecordingBlock(blockIdx, afterUpdateTimeStamp->seconds, partitionIdx); /* SBSW_STBM_ACCESS_OFFSETTIMERECORDINGBLOCK */
    StbM_SetGlbNanoSecondsOfOffsetTimeRecordingBlock(blockIdx, afterUpdateTimeStamp->nanoseconds, partitionIdx); /* SBSW_STBM_ACCESS_OFFSETTIMERECORDINGBLOCK */
    StbM_SetTimeBaseStatusOfOffsetTimeRecordingBlock(blockIdx, StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_OFFSETTIMERECORDINGBLOCK */

    /* #40 Update current block index */
    StbM_TimeRecording_SetCurrentBlockIndex(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), blockIdx, partitionIdx);

    /* #50 Increment recorded blocks count */
    StbM_TimeRecording_IncrementRecordedBlockCount(timeBaseIdx, partitionIdx);
  }
} /* StbM_TimeRecording_UpdateOffset */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetOffsetRecordTableHead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_GetOffsetRecordTableHead(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_OffsetRecordTableHeadType, AUTOMATIC, STBM_APPL_VAR) offsetTableHead,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get offset time domain */
  offsetTableHead->OffsetTimeDomain = StbM_GetOffsetTimeDomainOfOffsetTimeRecordingHeader(StbM_GetOffsetTimeRecordingHeaderIdxOfTimeRecordingConfig(StbM_GetTimeRecordingConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeRecording_GetOffsetRecordTableHead */

/**********************************************************************************************************************
 *  StbM_TimeRecording_GetOffsetRecordTableBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeRecording_GetOffsetRecordTableBlock(
        uint32 blockIdx,
        P2VAR(StbM_OffsetRecordTableBlockType, AUTOMATIC, STBM_APPL_VAR) offsetTableBlock,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get GlbNanoSeconds, GlbSeconds */
  offsetTableBlock->GlbNanoSeconds = StbM_GetGlbNanoSecondsOfOffsetTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  offsetTableBlock->GlbSeconds = StbM_GetGlbSecondsOfOffsetTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #20 Get timebase status */
  offsetTableBlock->TimeBaseStatus = StbM_GetTimeBaseStatusOfOffsetTimeRecordingBlock(blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeRecording_GetOffsetRecordTableBlock */
#  endif /* (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON) */
# endif /* (STBM_CONFIG_TIME_RECORDING == STD_ON) */
#endif /* STBM_NOUNIT_TIMERECORDING */

#ifndef STBM_NOUNIT_TIMEVALIDATION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_VALIDATION == STD_ON)
/**********************************************************************************************************************
 *  Unit: TimeValidation
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  StbM_TimeValidation_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialization of time validation blocks for timebase with ethernet */
  StbM_TimeValidation_InitEthBlocks(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */

  /* #20 Initialization of time validation states for timebases with ethernet */
  retVal = StbM_TimeValidation_InitEthStates(partitionIdx);

  return retVal;
} /* StbM_TimeValidation_Init */

/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthBlocks
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_InitEthBlocks(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialization of time validation blocks for timebase with ethernet master */
#  if (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON)
  StbM_TimeValidation_InitEthMasterBlocks(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
#  endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON) */

  /* #20 Initialization of time validation blocks for timebase with ethernet slave */
#  if (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON)
  StbM_TimeValidation_InitEthSlaveBlocks(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
#  endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON) */

} /* StbM_TimeValidation_InitEthBlocks */

/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthStates
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_InitEthStates(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialization of time validation states for timebase with ethernet master */
#  if (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON)
  retVal |= StbM_TimeValidation_InitEthMasterStates(partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */
#  endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON) */

  /* #20 Initialization of time validation states for timebase with ethernet slave */
#  if (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON)
  retVal |= StbM_TimeValidation_InitEthSlaveStates(partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */
#  endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON) */
  return retVal;
} /* StbM_TimeValidation_InitEthStates */

#  if (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_InitMasterEthBlocks
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_InitEthMasterBlocks(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 i;
  StbM_EthTimeMasterMeasurementType masterTimingData = { 0 };
  StbM_PdelayResponderMeasurementType pDelayResponderData = { 0 };

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  for (i = 0u; i < StbM_GetSizeOfTimeValidationEthMasterBlockData(partitionIdx); i++)
  {
    /* #10 Set ethernet master timing data and pdelay responder data to zero */
    StbM_SetEthMasterTimingDataOfTimeValidationEthMasterBlockData(i, masterTimingData, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERBLOCKDATA */
    StbM_SetEthPdelayResponderTimingDataOfTimeValidationEthPdelayResponderBlockData(i, pDelayResponderData, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERBLOCKDATA_IDX_TIMEVALIDATIONETHMASTERBLOCKDATA */
  }
} /* StbM_TimeValidation_InitEthMasterBlocks */

/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthMasterStates
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_InitEthMasterStates(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint16 timeValidationIdx;
  StbM_MasterIdSlot portId = { 0 };

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 For each configured time validation master customer: */
  for (timeValidationIdx = 0u; timeValidationIdx < StbM_GetSizeOfTimeValidationEthMasterState(partitionIdx); timeValidationIdx++)
  {
    /* #20 Get the configured callback function for the time validation master and pdelay responder block data */
    StbM_EthMasterTimeValidationBlockCallbackFctType EthMasterTimeValidationBlockCallbackPtr = StbM_GetCallbackOfTimeValidationEthMasterCallback(StbM_GetTimeValidationEthMasterCallbackIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), partitionIdx);
    StbM_PdelayResponderCallbackFctType PdelayResponderCallbackPtr = StbM_GetCallbackOfTimeValidationEthPdelayResponderCallback(StbM_GetTimeValidationEthPdelayResponderCallbackIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), partitionIdx);

    /* #30 If the callback functions for master time validation is null: */
    if (EthMasterTimeValidationBlockCallbackPtr == NULL_PTR) /* COV_STBM_SILENT_XF */
    {
      /* #40 Set retVal to E_NOT_OK */
      retVal |= E_NOT_OK;
    }

    /* #30 If the callback functions for master time validation is null: */
    if (PdelayResponderCallbackPtr == NULL_PTR) /* COV_STBM_SILENT_XF */
    {
      /* #40 Set retVal to E_NOT_OK */
      retVal |= E_NOT_OK;
    }

    /* #50 Set current index of timebase master block table to end block index, hence we start with the start index next time an index is requested */
    StbM_SetCurrentBlockIdxOfTimeValidationEthMasterState(timeValidationIdx, (uint32)StbM_GetTimeValidationEthMasterBlockDataEndIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx) - 1u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERSTATE */
    StbM_SetCurrentBlockIdxOfTimeValidationEthPdelayResponderState(timeValidationIdx, (uint32)StbM_GetTimeValidationEthPdelayResponderBlockDataEndIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx) - 1u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERSTATE_IDX_TIMEVALIDATIONETHMASTERSTATE */

    /* #60 Set recorded blocks count for master and pdelay responder to zero */
    StbM_SetRecordedBlocksCountOfTimeValidationEthMasterState(timeValidationIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERSTATE */
    StbM_SetRecordedBlocksCountOfTimeValidationEthPdelayResponderState(timeValidationIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERSTATE_IDX_TIMEVALIDATIONETHMASTERSTATE */

    /* #70 Set sourcePortId for master identification to unused */
    StbM_SetPortIdOfTimeValidationEthMasterIdentification(timeValidationIdx, portId, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERIDENTIFICATION_IDX_TIMEVALIDATIONETHMASTERSTATE */
  }

  return retVal;
} /* StbM_TimeValidation_InitEthMasterStates */

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnSetEthMasterTimingData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_OnSetEthMasterTimingData(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_EthTimeMasterMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint16 masterIdx;
  uint32 blockIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get master index */
  masterIdx = StbM_TimeValidation_GetMasterIndex(timeBaseIdx, &measureDataPtr->sourcePortId, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 If master index is valid: */
  if (masterIdx < StbM_GetSizeOfTimeValidationEthMasterConfig(partitionIdx))
  {
    /* #30 Get the next block index */
    blockIdx = StbM_TimeValidation_GetNextBlockIndex(StbM_GetTimeValidationEthMasterBlockDataStartIdxOfTimeValidationEthMasterConfig(masterIdx, partitionIdx), StbM_GetTimeValidationEthMasterBlockDataEndIdxOfTimeValidationEthMasterConfig(masterIdx, partitionIdx), StbM_GetCurrentBlockIdxOfTimeValidationEthMasterState(masterIdx, partitionIdx));

    /* #40 If block index is valid: */
    if (blockIdx < StbM_GetSizeOfTimeValidationEthMasterBlockData(partitionIdx)) /* COV_STBM_SILENT_TX */
    {
      /* #50 Set ethernet master timing data */
      StbM_SetEthMasterTimingDataOfTimeValidationEthMasterBlockData(blockIdx, *measureDataPtr, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERBLOCKDATA_IND_TIMEVALIDATIONETHMASTERCONFIG */

      /* #60 Update current block index */
      StbM_SetCurrentBlockIdxOfTimeValidationEthMasterState(masterIdx, blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERSTATE_IND_TIMEVALIDATIONETHMASTERCONFIG */

      /* #70 Increment recorded blocks count, if current value smaller than configured block count */
      if (StbM_GetRecordedBlocksCountOfTimeValidationEthMasterState(masterIdx, partitionIdx) < StbM_GetBlockCountOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeValidationEthMasterConfig(masterIdx, partitionIdx), partitionIdx))
      {
        StbM_IncRecordedBlocksCountOfTimeValidationEthMasterState(masterIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERSTATE_IND_TIMEVALIDATIONETHMASTERCONFIG */
      }

      retVal = E_OK;
    }
  }

  return retVal;
} /* StbM_TimeValidation_OnSetEthMasterTimingData */

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnSetEthPdelayResponderData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_OnSetEthPdelayResponderData(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_PdelayResponderMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint16 masterIdx;
  uint32 blockIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get master index */
  masterIdx = StbM_TimeValidation_GetMasterIndex(timeBaseIdx, &measureDataPtr->responsePortId, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 If master index is valid: */
  if (masterIdx < StbM_GetSizeOfTimeValidationEthMasterConfig(partitionIdx))
  {
    /* #30 Get the next block index */
    blockIdx = StbM_TimeValidation_GetNextBlockIndex(StbM_GetTimeValidationEthPdelayResponderBlockDataStartIdxOfTimeValidationEthMasterConfig(masterIdx, partitionIdx), StbM_GetTimeValidationEthPdelayResponderBlockDataEndIdxOfTimeValidationEthMasterConfig(masterIdx, partitionIdx), StbM_GetCurrentBlockIdxOfTimeValidationEthPdelayResponderState(masterIdx, partitionIdx));

    /* #40 If block index is valid: */
    if (blockIdx < StbM_GetSizeOfTimeValidationEthPdelayResponderBlockData(partitionIdx)) /* COV_STBM_SILENT_TX */
    {
      /* #50 Set ethernet master pdelay timing data */
      StbM_SetEthPdelayResponderTimingDataOfTimeValidationEthPdelayResponderBlockData(blockIdx, *measureDataPtr, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERBLOCKDATA_IND_TIMEVALIDATIONETHMASTERCONFIG */

      /* #60 Update current block index */
      StbM_SetCurrentBlockIdxOfTimeValidationEthPdelayResponderState(masterIdx, blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERSTATE_IND_TIMEVALIDATIONETHMASTERCONFIG */

      /* #70 Increment recorded blocks count, if current value smaller than configured block count */
      if (StbM_GetRecordedBlocksCountOfTimeValidationEthPdelayResponderState(masterIdx, partitionIdx) < StbM_GetBlockCountOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeValidationEthMasterConfig(masterIdx, partitionIdx), partitionIdx))
      {
        StbM_IncRecordedBlocksCountOfTimeValidationEthPdelayResponderState(masterIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERSTATE_IND_TIMEVALIDATIONETHMASTERCONFIG */
      }

      retVal = E_OK;
    }
  }

  return retVal;
} /* StbM_TimeValidation_OnSetEthPdelayResponderData */

/**********************************************************************************************************************
 *  StbM_TimeValidation_GetMasterIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(uint16, STBM_CODE) StbM_TimeValidation_GetMasterIndex(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_PortIdType, AUTOMATIC, STBM_APPL_DATA) portId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 i;
  uint16 startMasterIdx;
  uint16 endMasterIdx;
  StbM_MasterIdSlot nextIdSlot;
  uint16 masterIdx = STBM_NO_TIMEVALIDATIONETHMASTERCONFIGENDIDXOFTIMEVALIDATIONCONFIG;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  startMasterIdx = StbM_GetTimeValidationEthMasterConfigStartIdxOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
  endMasterIdx = StbM_GetTimeValidationEthMasterConfigEndIdxOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

  /* #10 For each configured time validation master: */
  for (i = startMasterIdx; i < endMasterIdx; i++)  /* FETA_StbM_2 */
  {
    /* #20 Get portId from master identification table for that timebase */
    nextIdSlot = StbM_GetPortIdOfTimeValidationEthMasterIdentification(i, partitionIdx);

    /* #30 portId is unused or it has been found: */
    if ((nextIdSlot.used == FALSE)
      || ((nextIdSlot.portId.portNumber == portId->portNumber) && (nextIdSlot.portId.clockIdentity == portId->clockIdentity)))
    {
      /* #40 reserve slot for this master and return slot number */
      masterIdx = i;
      nextIdSlot.portId = *portId;
      nextIdSlot.used = TRUE; /* PRQA S 2983 */ /* MD_StbM_Rule2.2_2983 */
      StbM_SetPortIdOfTimeValidationEthMasterIdentification(i, nextIdSlot, partitionIdx); /* PRQA S 2843 */ /* MD_StbM_Rule1.3_2843 */ /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERIDENTIFICATION_IDX_TIMEVALIDATIONETHMASTERCONFIG */
      break;
    }
  }

  /* #50 return master index */
  return masterIdx;
} /* StbM_TimeValidation_GetMasterIndex */

/**********************************************************************************************************************
 *  StbM_TimeValidation_NotifyEthMasterCustomers
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_NotifyEthMasterCustomers(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 timeValidationIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter exclusive area in order to guarantee atomic notification of recorded blocks */
  StbM_EnterCritical_LocalCore();

  /* #20 For each configured time validation customer */
  for (timeValidationIdx = 0u; timeValidationIdx < StbM_GetSizeOfTimeValidationEthMasterState(partitionIdx); timeValidationIdx++)
  {
    /* #30 Notify available blocks for time master measurement data */
    StbM_TimeValidation_OnNotifyEthMasterMeasurementData(timeValidationIdx, partitionIdx);

    /* #40 Notify available blocks for time master pdelay responder data */
    StbM_TimeValidation_OnNotifyEthMasterPdelayResponderData(timeValidationIdx, partitionIdx);
  }
  /* #50 Exit exclusive area */
  StbM_LeaveCritical_LocalCore();
} /* StbM_TimeValidation_NotifyEthMasterCustomers */

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnNotifyEthMasterMeasurementData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_OnNotifyEthMasterMeasurementData(
        uint16 timeValidationIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  uint16 committedBlocksCount = 0u;

  /* #10 Get recorded block count */
  uint16 blocksToCommit = StbM_GetRecordedBlocksCountOfTimeValidationEthMasterState(timeValidationIdx, partitionIdx);

  /* #20 While blocks to commit: */
  while ((blocksToCommit > 0u) && (committedBlocksCount < StbM_GetBlockCountOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), partitionIdx))) /* COV_STBM_WHILE_COMMIT_BLOCKS */ /* FETA_StbM_BlocksToCommit */
  {
    /* #30 Get oldest block index */
    uint32 blockIdx = StbM_TimeValidation_GetOldestBlockIndex(StbM_GetTimeValidationEthMasterBlockDataStartIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), StbM_GetTimeValidationEthMasterBlockDataEndIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), StbM_GetCurrentBlockIdxOfTimeValidationEthMasterState(timeValidationIdx, partitionIdx), blocksToCommit);

    /* #40 Decrease recorded block count */
    StbM_DecRecordedBlocksCountOfTimeValidationEthMasterState(timeValidationIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERSTATE */

    /* #50 Commit block to customer */
    StbM_TimeValidation_CommitEthMasterTimeValidationBlock(timeValidationIdx, blockIdx, partitionIdx);
    committedBlocksCount++;

    /* #60 Get recorded block count */
    blocksToCommit = StbM_GetRecordedBlocksCountOfTimeValidationEthMasterState(timeValidationIdx, partitionIdx);
  }
} /* StbM_TimeValidation_OnNotifyEthMasterMeasurementData */

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnNotifyEthMasterPdelayResponderData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_OnNotifyEthMasterPdelayResponderData(
        uint16 timeValidationIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  uint16 committedBlocksCount = 0u;

  /* #10 Get recorded block count */
  uint16 blocksToCommit = StbM_GetRecordedBlocksCountOfTimeValidationEthPdelayResponderState(timeValidationIdx, partitionIdx);

  /* #20 While blocks to commit: */
  while ((blocksToCommit > 0u) && (committedBlocksCount < StbM_GetBlockCountOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), partitionIdx))) /* COV_STBM_WHILE_COMMIT_BLOCKS */ /* FETA_StbM_BlocksToCommit */
  {
    /* #30 Get oldest block index */
    uint32 blockIdx = StbM_TimeValidation_GetOldestBlockIndex(StbM_GetTimeValidationEthPdelayResponderBlockDataStartIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), StbM_GetTimeValidationEthPdelayResponderBlockDataEndIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), StbM_GetCurrentBlockIdxOfTimeValidationEthPdelayResponderState(timeValidationIdx, partitionIdx), blocksToCommit);

    /* #40 Decrease recorded block count */
    StbM_DecRecordedBlocksCountOfTimeValidationEthPdelayResponderState(timeValidationIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERSTATE_IDX_TIMEVALIDATIONETHMASTERSTATE */

    /* #50 Commit block to customer */
    StbM_TimeValidation_CommitEthPdelayResponderTimeValidationBlock(timeValidationIdx, blockIdx, partitionIdx);
    committedBlocksCount++;

    /* #60 Get recorded block count */
    blocksToCommit = StbM_GetRecordedBlocksCountOfTimeValidationEthPdelayResponderState(timeValidationIdx, partitionIdx);
  }
} /* StbM_TimeValidation_OnNotifyEthMasterPdelayResponderData */

/**********************************************************************************************************************
 *  StbM_TimeValidation_CommitEthMasterTimeValidationBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_CommitEthMasterTimeValidationBlock(
        uint16 timeValidationIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_EthMasterTimeValidationBlockCallbackFctType EthMasterTimeValidationBlockCallbackPtr;
  StbM_EthTimeMasterMeasurementType block;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get the configured callback function */
  EthMasterTimeValidationBlockCallbackPtr = StbM_GetCallbackOfTimeValidationEthMasterCallback(StbM_GetTimeValidationEthMasterCallbackIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), partitionIdx);

  /* #20 Get block data */
  block = StbM_GetEthMasterTimingDataOfTimeValidationEthMasterBlockData(blockIdx, partitionIdx);

  /* #30 Exit exclusive area for callback */
  StbM_LeaveCritical_LocalCore();

  /* #40 Call callback with block data */
  (void)EthMasterTimeValidationBlockCallbackPtr(&block); /* SBSW_STBM_FCTPTRCALL_RECORDTABLE */

  /* #50 Enter exclusive area */
  StbM_EnterCritical_LocalCore();
} /* StbM_TimeValidation_CommitEthMasterTimeValidationBlock */

/**********************************************************************************************************************
 *  StbM_TimeValidation_CommitEthPdelayResponderTimeValidationBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_CommitEthPdelayResponderTimeValidationBlock(
        uint16 timeValidationIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_PdelayResponderCallbackFctType PdelayResponderCallbackPtr;
  StbM_PdelayResponderMeasurementType block;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get the configured callback function */
  PdelayResponderCallbackPtr = StbM_GetCallbackOfTimeValidationEthPdelayResponderCallback(StbM_GetTimeValidationEthPdelayResponderCallbackIdxOfTimeValidationEthMasterConfig(timeValidationIdx, partitionIdx), partitionIdx);

  /* #20 Get block data */
  block = StbM_GetEthPdelayResponderTimingDataOfTimeValidationEthPdelayResponderBlockData(blockIdx, partitionIdx);

  /* #30 Exit exclusive area for callback */
  StbM_LeaveCritical_LocalCore();

  /* #40 Call callback with block data */
  (void)PdelayResponderCallbackPtr(&block); /* SBSW_STBM_FCTPTRCALL_RECORDTABLE */

  /* #50 Enter exclusive area */
  StbM_EnterCritical_LocalCore();
} /* StbM_TimeValidation_CommitEthPdelayResponderTimeValidationBlock */

#   if (STBM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_IsMasterConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeValidation_IsMasterConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#    if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#    endif

  /* #10 True, if given timebase has time validation for master configured */
  return ((StbM_GetTimeValidationEthMasterConfigLengthOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx)) > 0u);
} /* StbM_TimeValidation_IsMasterConfigured */
#   endif
#  endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_TimeValidation_NotifyCustomers
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_NotifyCustomers(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON)
  /* #10 Notify ethernet master customers */
  StbM_TimeValidation_NotifyEthMasterCustomers(partitionIdx);
#  endif

#  if (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON)
  /* #20 Notify ethernet slave customers */
  StbM_TimeValidation_NotifyEthSlaveCustomers(partitionIdx);
#  endif
} /* StbM_TimeValidation_NotifyCustomers */

#  if (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthSlaveBlocks
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_InitEthSlaveBlocks(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 i;
  StbM_EthTimeSlaveMeasurementType slaveTimingData = { 0 };
  StbM_PdelayInitiatorMeasurementType pDelayInitiatorData = { 0 };

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  for (i = 0u; i < StbM_GetSizeOfTimeValidationEthSlaveBlockData(partitionIdx); i++)
  {
    /* #10 Set ethernet slave timing data and pdelay initiator data to zero */
    StbM_SetEthSlaveTimingDataOfTimeValidationEthSlaveBlockData(i, slaveTimingData, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVEBLOCKDATA */
    StbM_SetEthPdelayInitiatorTimingDataOfTimeValidationEthPdelayInitiatorBlockData(i, pDelayInitiatorData, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORBLOCKDATA_IDX_TIMEVALIDATIONETHSLAVEBLOCKDATA */
  }
} /* StbM_TimeValidation_InitEthSlaveBlocks */

/**********************************************************************************************************************
 *  StbM_TimeValidation_InitEthSlaveStates
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_InitEthSlaveStates(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  uint16 timeValidationIdx;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 For each configured time validation slave customer: */
  for (timeValidationIdx = 0u; timeValidationIdx < StbM_GetSizeOfTimeValidationEthSlaveState(partitionIdx); timeValidationIdx++)
  {
    /* #20 Get the configured callback function for the time validation master and pdelayInitiator block data */
    StbM_EthSlaveTimeValidationBlockCallbackFctType EthSlaveTimeValidationBlockCallbackPtr = StbM_GetCallbackOfTimeValidationEthSlaveCallback(StbM_GetTimeValidationEthSlaveCallbackIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), partitionIdx);
    StbM_PdelayInitiatorCallbackFctType PdelayInitiatorCallbackPtr = StbM_GetCallbackOfTimeValidationEthPdelayInitiatorCallback(StbM_GetTimeValidationEthPdelayInitiatorCallbackIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), partitionIdx);

    /* #30 If the callback functions for slave time validation is null: */
    if (EthSlaveTimeValidationBlockCallbackPtr == NULL_PTR) /* COV_STBM_SILENT_XF */
    {
      /* #40 Set retVal to E_NOT_OK */
      retVal |= E_NOT_OK;
    }

    /* #30 If the callback functions for slave time validation is null: */
    if (PdelayInitiatorCallbackPtr == NULL_PTR) /* COV_STBM_SILENT_XF */
    {
      /* #40 Set retVal to E_NOT_OK */
      retVal |= E_NOT_OK;
    }

    /* #50 Set current index of timebase slave block table to end block index, hence we start with the start index next time an index is requested */
    StbM_SetCurrentBlockIdxOfTimeValidationEthSlaveState(timeValidationIdx, (uint32)StbM_GetTimeValidationEthSlaveBlockDataEndIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx) - 1u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVESTATE */
    StbM_SetCurrentBlockIdxOfTimeValidationEthPdelayInitiatorState(timeValidationIdx, (uint32)StbM_GetTimeValidationEthPdelayInitiatorBlockDataEndIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx) - 1u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORSTATE_IDX_TIMEVALIDATIONETHSLAVESTATE */

    /* #60 Set recorded blocks count for slave and pdelay initiator to zero */
    StbM_SetRecordedBlocksCountOfTimeValidationEthSlaveState(timeValidationIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVESTATE */
    StbM_SetRecordedBlocksCountOfTimeValidationEthPdelayInitiatorState(timeValidationIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORSTATE_IDX_TIMEVALIDATIONETHSLAVESTATE */
  }

  return retVal;
} /* StbM_TimeValidation_InitEthSlaveStates */

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnSetEthSlaveTimingData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_OnSetEthSlaveTimingData(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_EthTimeSlaveMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint32 blockIdx;
  uint16 slaveIdx;
  StbM_EthTimeSlaveMeasurementType slaveTimingData;
  StbM_VirtualLocalTimeType tvSync = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_InternalTimeStampType localTimeSync = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the next block index */
  slaveIdx = StbM_GetTimeValidationEthSlaveConfigIdxOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
  blockIdx = StbM_TimeValidation_GetNextBlockIndex(StbM_GetTimeValidationEthSlaveBlockDataStartIdxOfTimeValidationEthSlaveConfig(slaveIdx, partitionIdx), StbM_GetTimeValidationEthSlaveBlockDataEndIdxOfTimeValidationEthSlaveConfig(slaveIdx, partitionIdx), StbM_GetCurrentBlockIdxOfTimeValidationEthSlaveState(slaveIdx, partitionIdx));

  /* #20 If block index is valid: */
  if (blockIdx < StbM_GetSizeOfTimeValidationEthSlaveBlockData(partitionIdx)) /* COV_STBM_SILENT_TX */
  {
    retVal = E_OK;

    /* #30 Get TVsync */
    StbM_LocalTime_GetVirtualLocalTimeSync(timeBaseIdx, &tvSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #40 Set items to slave timing data */
    slaveTimingData = *measureDataPtr;

    /* #50 Convert TVsync to slave timing data */
    slaveTimingData.referenceLocalTimestamp.nanosecondsLo = tvSync.nanosecondsLo; /* PRQA S 2983 */ /* MD_StbM_Rule2.2_2983 */
    slaveTimingData.referenceLocalTimestamp.nanosecondsHi = tvSync.nanosecondsHi; /* PRQA S 2983 */ /* MD_StbM_Rule2.2_2983 */

    /* #60 Get TLsync */
    StbM_LocalTime_GetLocalTimeSync(timeBaseIdx, &localTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #70 Set TLsync to slave timing data */
    slaveTimingData.referenceGlobalTimestamp.nanoseconds = localTimeSync.nanoseconds; /* PRQA S 2983 */ /* MD_StbM_Rule2.2_2983 */
    slaveTimingData.referenceGlobalTimestamp.seconds = localTimeSync.seconds; /* PRQA S 2983 */ /* MD_StbM_Rule2.2_2983 */

    /* #80 Set ethernet slave timing data */
    StbM_SetEthSlaveTimingDataOfTimeValidationEthSlaveBlockData(blockIdx, slaveTimingData, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVEBLOCKDATA_IND_TIMEVALIDATIONETHSLAVECONFIG */

    /* #90 Update current block index */
    StbM_SetCurrentBlockIdxOfTimeValidationEthSlaveState(slaveIdx, blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVESTATE_IND_TIMEVALIDATIONETHSLAVECONFIG */

    /* #100 Increment recorded blocks count, if current value smaller than configured block count */
    if (StbM_GetRecordedBlocksCountOfTimeValidationEthSlaveState(slaveIdx, partitionIdx) < StbM_GetBlockCountOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeValidationEthSlaveConfig(slaveIdx, partitionIdx), partitionIdx))
    {
      StbM_IncRecordedBlocksCountOfTimeValidationEthSlaveState(slaveIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVESTATE_IND_TIMEVALIDATIONETHSLAVECONFIG */
    }
  }

  return retVal;
} /* StbM_TimeValidation_OnSetEthSlaveTimingData */

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnSetEthPdelayInitiatorData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeValidation_OnSetEthPdelayInitiatorData(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_PdelayInitiatorMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint16 slaveIdx;
  uint32 blockIdx;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get the next block index */
  slaveIdx = StbM_GetTimeValidationEthSlaveConfigIdxOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
  blockIdx = StbM_TimeValidation_GetNextBlockIndex(StbM_GetTimeValidationEthPdelayInitiatorBlockDataStartIdxOfTimeValidationEthSlaveConfig(slaveIdx, partitionIdx), StbM_GetTimeValidationEthPdelayInitiatorBlockDataEndIdxOfTimeValidationEthSlaveConfig(slaveIdx, partitionIdx), StbM_GetCurrentBlockIdxOfTimeValidationEthPdelayInitiatorState(slaveIdx, partitionIdx));

  /* #20 If block index is valid: */
  if (blockIdx < StbM_GetSizeOfTimeValidationEthPdelayInitiatorBlockData(partitionIdx)) /* COV_STBM_SILENT_TX */
  {
    /* #30 Set ethernet slave pdelay initiator timing data */
    StbM_SetEthPdelayInitiatorTimingDataOfTimeValidationEthPdelayInitiatorBlockData(blockIdx, *measureDataPtr, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORBLOCKDATA_IND_TIMEVALIDATIONETHSLAVECONFIG */

    /* #40 Update current block index */
    StbM_SetCurrentBlockIdxOfTimeValidationEthPdelayInitiatorState(slaveIdx, blockIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORSTATE_IND_TIMEVALIDATIONETHSLAVECONFIG */

    /* #50 Increment recorded blocks count, if current value smaller than configured block count */
    if (StbM_GetRecordedBlocksCountOfTimeValidationEthPdelayInitiatorState(slaveIdx, partitionIdx) < StbM_GetBlockCountOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeValidationEthSlaveConfig(slaveIdx, partitionIdx), partitionIdx))
    {
      StbM_IncRecordedBlocksCountOfTimeValidationEthPdelayInitiatorState(slaveIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORSTATE_IND_TIMEVALIDATIONETHSLAVECONFIG */
    }

    retVal = E_OK;
  }

  return retVal;
} /* StbM_TimeValidation_OnSetEthPdelayInitiatorData */

/**********************************************************************************************************************
 *  StbM_TimeValidation_NotifyEthSlaveCustomers
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_NotifyEthSlaveCustomers(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 timeValidationIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter exclusive area in order to guarantee atomic notification of recorded blocks */
  StbM_EnterCritical_LocalCore();

  /* #20 For each configured time validation customer: */
  for (timeValidationIdx = 0u; timeValidationIdx < StbM_GetSizeOfTimeValidationEthSlaveState(partitionIdx); timeValidationIdx++)
  {
    /* #30 Notify available blocks for time slave measurement data */
    StbM_TimeValidation_OnNotifyEthSlaveMeasurementData(timeValidationIdx, partitionIdx);

    /* #40 Notify available blocks for time slave pdelay initiator data */
    StbM_TimeValidation_OnNotifyEthSlavePdelayInitiatorData(timeValidationIdx, partitionIdx);
  }

  /* #50 Exit exclusive area */
  StbM_LeaveCritical_LocalCore();
} /* StbM_TimeValidation_NotifyEthSlaveCustomers */

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnNotifyEthSlaveMeasurementData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_OnNotifyEthSlaveMeasurementData(
        uint16 timeValidationIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  uint16 committedBlocksCount = 0u;

  /* #10 Get recorded block count */
  uint16 blocksToCommit = StbM_GetRecordedBlocksCountOfTimeValidationEthSlaveState(timeValidationIdx, partitionIdx);

  /* #20 While blocks to commit: */
  while ((blocksToCommit > 0u) && (committedBlocksCount < StbM_GetBlockCountOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), partitionIdx))) /* COV_STBM_WHILE_COMMIT_BLOCKS */ /* FETA_StbM_BlocksToCommit */
  {
    /* #30 Get oldest block index */
    uint32 blockIdx = StbM_TimeValidation_GetOldestBlockIndex(StbM_GetTimeValidationEthSlaveBlockDataStartIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), StbM_GetTimeValidationEthSlaveBlockDataEndIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), StbM_GetCurrentBlockIdxOfTimeValidationEthSlaveState(timeValidationIdx, partitionIdx), blocksToCommit);

    /* #40 Decrease recorded block count */
    StbM_DecRecordedBlocksCountOfTimeValidationEthSlaveState(timeValidationIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVESTATE */

    /* #50 Commit block to customer */
    StbM_TimeValidation_CommitEthSlaveTimeValidationBlock(timeValidationIdx, blockIdx, partitionIdx);
    committedBlocksCount++;

    /* #60 Get recorded block count */
    blocksToCommit = StbM_GetRecordedBlocksCountOfTimeValidationEthSlaveState(timeValidationIdx, partitionIdx);
  }
} /* StbM_TimeValidation_OnNotifyEthSlaveMeasurementData */

/**********************************************************************************************************************
 *  StbM_TimeValidation_OnNotifyEthSlavePdelayInitiatorData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_OnNotifyEthSlavePdelayInitiatorData(
        uint16 timeValidationIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  uint16 committedBlocksCount = 0u;

  /* #10 Get recorded block count */
  uint16 blocksToCommit = StbM_GetRecordedBlocksCountOfTimeValidationEthPdelayInitiatorState(timeValidationIdx, partitionIdx);

  /* #20 While blocks to commit: */
  while ((blocksToCommit > 0u) && (committedBlocksCount < StbM_GetBlockCountOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), partitionIdx))) /* COV_STBM_WHILE_COMMIT_BLOCKS */ /* FETA_StbM_BlocksToCommit */
  {
    /* #30 Get oldest block index */
    uint32 blockIdx = StbM_TimeValidation_GetOldestBlockIndex(StbM_GetTimeValidationEthPdelayInitiatorBlockDataStartIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), StbM_GetTimeValidationEthPdelayInitiatorBlockDataEndIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), StbM_GetCurrentBlockIdxOfTimeValidationEthPdelayInitiatorState(timeValidationIdx, partitionIdx), blocksToCommit);

    /* #40 Decrease recorded block count */
    StbM_DecRecordedBlocksCountOfTimeValidationEthPdelayInitiatorState(timeValidationIdx, partitionIdx); /* SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORSTATE_IDX_TIMEVALIDATIONETHSLAVESTATE */

    /* #50 Commit block to customer */
    StbM_TimeValidation_CommitEthPdelayInitiatorTimeValidationBlock(timeValidationIdx, blockIdx, partitionIdx);
    committedBlocksCount++;

    /* #60 Get recorded block count */
    blocksToCommit = StbM_GetRecordedBlocksCountOfTimeValidationEthPdelayInitiatorState(timeValidationIdx, partitionIdx);
  }
} /* StbM_TimeValidation_OnNotifyEthSlavePdelayInitiatorData */

/**********************************************************************************************************************
 *  StbM_TimeValidation_CommitEthSlaveTimeValidationBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_CommitEthSlaveTimeValidationBlock(
        uint16 timeValidationIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_EthSlaveTimeValidationBlockCallbackFctType EthSlaveTimeValidationBlockCallbackPtr;
  StbM_EthTimeSlaveMeasurementType block;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get the configured callback function */
  EthSlaveTimeValidationBlockCallbackPtr = StbM_GetCallbackOfTimeValidationEthSlaveCallback(StbM_GetTimeValidationEthSlaveCallbackIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), partitionIdx);

  /* #20 Get block data */
  block = StbM_GetEthSlaveTimingDataOfTimeValidationEthSlaveBlockData(blockIdx, partitionIdx);

  /* #30 Exit exclusive area for callback */
  StbM_LeaveCritical_LocalCore();

  /* #40 Call callback with block data */
  (void)EthSlaveTimeValidationBlockCallbackPtr(&block); /* SBSW_STBM_FCTPTRCALL_RECORDTABLE */

  /* #50 Enter exclusive area */
  StbM_EnterCritical_LocalCore();
} /* StbM_TimeValidation_CommitEthSlaveTimeValidationBlock */

/**********************************************************************************************************************
 *  StbM_TimeValidation_CommitEthPdelayInitiatorTimeValidationBlock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeValidation_CommitEthPdelayInitiatorTimeValidationBlock(
        uint16 timeValidationIdx,
        uint32 blockIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_PdelayInitiatorCallbackFctType PdelayInitiatorCallbackPtr;
  StbM_PdelayInitiatorMeasurementType block;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get the configured callback function */
  PdelayInitiatorCallbackPtr = StbM_GetCallbackOfTimeValidationEthPdelayInitiatorCallback(StbM_GetTimeValidationEthPdelayInitiatorCallbackIdxOfTimeValidationEthSlaveConfig(timeValidationIdx, partitionIdx), partitionIdx);

  /* #20 Get block data */
  block = StbM_GetEthPdelayInitiatorTimingDataOfTimeValidationEthPdelayInitiatorBlockData(blockIdx, partitionIdx);

  /* #30 Exit exclusive area for callback */
  StbM_LeaveCritical_LocalCore();

  /* #40 Call callback with block data */
  (void)PdelayInitiatorCallbackPtr(&block); /* SBSW_STBM_FCTPTRCALL_RECORDTABLE */

  /* #50 Enter exclusive area */
  StbM_EnterCritical_LocalCore();
} /* StbM_TimeValidation_CommitEthPdelayInitiatorTimeValidationBlock */

#   if (STBM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_IsSlaveConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeValidation_IsSlaveConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#    if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#    endif

  /* #10 True, if given is timebase has time validation for slave configured */
  return (StbM_GetTimeValidationEthSlaveConfigIdxOfTimeValidationConfig(StbM_GetTimeValidationConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx) < StbM_GetSizeOfTimeValidationEthSlaveConfig(partitionIdx));
} /* StbM_TimeValidation_IsSlaveConfigured */
#   endif
#  endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_TimeValidation_GetNextBlockIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_TimeValidation_GetNextBlockIndex(uint32 startBlockIdx,
        uint32 endBlockIdx,
        uint32 currentBlockIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 blockIdx = currentBlockIdx;
  blockIdx++;
  /* #10 Return the next block index from the buffer, the calculation ensures that in case of an overflow the next block index will be the startBlockIdx again */
  return ((blockIdx - startBlockIdx) % (endBlockIdx - startBlockIdx)) + startBlockIdx;
} /* StbM_TimeValidation_GetNextBlockIndex */

/**********************************************************************************************************************
 *  StbM_TimeValidation_GetOldestBlockIndex
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(uint32, STBM_CODE) StbM_TimeValidation_GetOldestBlockIndex(
        uint32 startBlockIdx,
        uint32 endBlockIdx,
        uint32 currentBlockIdx,
        uint32 recordedBlockCount)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 oldestBlockIdx;
  uint32 nextBlockIdx = StbM_TimeValidation_GetNextBlockIndex(startBlockIdx, endBlockIdx, currentBlockIdx);
  uint32 blockCount = nextBlockIdx - startBlockIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate the oldest block index, the calculation ensures that when the oldest block is overwritten, the next one in the buffer is automatically the oldest */
  if (blockCount < recordedBlockCount)
  {
    oldestBlockIdx = endBlockIdx - (recordedBlockCount - blockCount);
  }
  else
  {
    oldestBlockIdx = nextBlockIdx - recordedBlockCount;
  }

  return oldestBlockIdx;
} /* StbM_TimeValidation_GetOldestBlockIndex */

#  if (STBM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeValidation_IsConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeValidation_IsConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 True, if given timebase has time validation configured */
  return (StbM_GetTimeValidationConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx) < StbM_GetSizeOfTimeValidationConfig(partitionIdx));
} /* StbM_TimeValidation_IsConfigured */
#  endif
# endif /* (STBM_CONFIG_TIME_VALIDATION == STD_ON) */
#endif /* STBM_NOUNIT_TIMEVALIDATION */

#ifndef STBM_NOUNIT_TIMECORRECTION /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: TimeCorrection
 *********************************************************************************************************************/

# if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON))
/**********************************************************************************************************************
 *  StbM_TimeCorrection_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Initialization time correction for master */
#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
  StbM_TimeCorrection_InitMaster(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
#  endif

  /* #20 Initialization time correction for slave */
#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
  StbM_TimeCorrection_InitSlave(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
#  endif
} /* StbM_TimeCorrection_Init */

#  if (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeCorrection_ResetRate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_ResetRate(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If time correction is configured: */
  if (StbM_TimeCorrection_HasTimeCorrectionConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
#   if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
    /* #20 If timebase is master: */
#    if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
    if (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == TRUE)
#    endif
    {
      /* #30 Reset rate correction rate for master to one */
      StbM_SetRateCorrectionRateOfTimeCorrectionMasterState(StbM_GetTimeCorrectionMasterConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), 1.0, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE_IND_TIMEBASECONFIG */ /* VCA_STBM_CSL02_CSL03 */
    }
#    if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
    else
#    endif
#   endif

#   if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
      /* #40 If timebase is slave: */
    {
      /* #50 Reset rate correction rate for slave to one */
      StbM_TimeCorrection_SetRateForRateCorrectionSlave(timeBaseIdx, 1.0, partitionIdx);
    }
#   endif
  }
} /* StbM_TimeCorrection_ResetRate */
#  endif /* (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateDeviation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(StbM_RateDeviationType, STBM_CODE) StbM_TimeCorrection_GetRateDeviation(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalRateType r_rc;
  StbM_InternalRateType ratePPM;

  /* ----- Implementation ----------------------------------------------- */
#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON))
  r_rc = 1.0;
#  endif

  /* #10 If time correction is configured, get rate */
#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
#   if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
  if (StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == TRUE)
#   endif
  {
    r_rc = StbM_TimeCorrection_GetRateForRateCorrection(timeBaseIdx, partitionIdx);
  }
#  endif

#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
#   if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
  if (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == TRUE)
#   endif
  {
    r_rc = StbM_TimeCorrection_GetRateMaster(timeBaseIdx, partitionIdx);
  }
#  endif

  /* #20 Convert rate to ppm format */
  ratePPM = StbM_ToStbMRateDeviationType(r_rc);

  return (StbM_RateDeviationType) ratePPM;
} /* StbM_TimeCorrection_GetRateDeviation */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_GetRate(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalRateType r = 1.0;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If time correction is configured and rate deviation is valid: */
  if (StbM_TimeCorrection_HasTimeCorrectionConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
    /* #20 If timebase is master, get current rate correction factor */
#   if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
    if (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == TRUE)
#   endif
    {
      r = StbM_TimeCorrection_GetRateMaster(timeBaseIdx, partitionIdx);
    }
#   if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
    else
#   endif
#  endif

#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
      /* #30 If timebase is slave: */
    {
      /* #40 Get last calculated rate correction factor */
      r = StbM_TimeCorrection_GetRateForRateCorrection(timeBaseIdx, partitionIdx) + StbM_TimeCorrection_GetRateForOffsetRateCorrection(timeBaseIdx, partitionIdx);
    }
#  endif
  }

#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  /* #50 If offset timebase, subtract 1 from rate */
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
  {
    r -= 1.0;
  }
#  endif

  return r;
} /* StbM_TimeCorrection_GetRate */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsRateDeviationValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsRateDeviationValid(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If timebase has rate correction configured: */
  if (StbM_TimeCorrection_HasTimeCorrectionConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
#   if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
    if (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == TRUE)
#   endif
    {
      /* #20 Check if at least one valid rate deviation has been calculated */
      isValid = StbM_IsRateDeviationValidOfTimeCorrectionMasterState(StbM_GetTimeCorrectionMasterConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
    }
#  endif

#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
#   if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
    if (StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == TRUE)
#   endif
    {
      /* #20 Check if at least one valid rate deviation has been calculated */
      isValid = StbM_IsRateDeviationValidOfTimeCorrectionSlaveState(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
    }
#  endif
  }

  return isValid;
} /* StbM_TimeCorrection_IsRateDeviationValid */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_HasTimeCorrectionConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeCorrection_HasTimeCorrectionConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isConfigured;

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
  if (StbM_TimeCorrection_HasTimeCorrectionMasterConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
    isConfigured = TRUE;
  }
  else
#  endif
#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
  if (StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
    isConfigured = TRUE;
  }
  else
#  endif
  {
    isConfigured = FALSE;
  }

  return isConfigured;
} /* StbM_TimeCorrection_HasTimeCorrectionConfigured */

#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Check if timebase is slave and has time correction indirection and time correction is enabled */
  return (StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx) < StbM_GetSizeOfTimeCorrectionSlaveConfig(partitionIdx));
} /* StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured */
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) */

#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeCorrection_InitMaster
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_InitMaster(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 i;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  for (i = 0u; i < StbM_GetSizeOfTimeCorrectionMasterState(partitionIdx); i++)
  {
    /* #10 Set rate correction rate for master to one */
    StbM_SetRateCorrectionRateOfTimeCorrectionMasterState(i, 1.0, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE */

    /* #20 Set rate deviation invalid */
    StbM_SetRateDeviationValidOfTimeCorrectionMasterState(i, FALSE, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE */
  }
} /* StbM_TimeCorrection_InitMaster */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_HasTimeCorrectionMasterConfigured
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_HasTimeCorrectionMasterConfigured(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 Check if timebase has master rate correction enabled */
  return StbM_TimeCorrection_IsAllowMasterRateCorrection(timeBaseIdx, partitionIdx);
} /* StbM_TimeCorrection_HasTimeCorrectionMasterConfigured */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_SetRateMaster
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_SetRateMaster(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_RateDeviationType rateDeviation,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalRateType newRate;
  StbM_InternalRateType maxRateDeviation;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Store given rate deviation in local internal rate type */
  newRate = (StbM_InternalRateType)rateDeviation;

  /* #20 Get configured max rate deviation: r_max */
  maxRateDeviation = (StbM_InternalRateType) StbM_GetMaxRateDeviationOfTimeCorrectionMasterConfig(StbM_GetTimeCorrectionMasterConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

  /* #30 Ensure that rate deviation is bound to configured max value like: -r_max < r < r_max */
  if ((newRate > maxRateDeviation) || (newRate < -maxRateDeviation))
  {
    if (newRate > 0.0)
    {
      newRate = maxRateDeviation;
    }
    else
    {
      newRate = -maxRateDeviation;
    }
  }

  /* #40 Convert given rate from ppm into internal rate type */
  newRate = StbM_ToStbMInternalRateType(newRate);

  /* #50 Store new converted rate */
  StbM_SetRateCorrectionRateOfTimeCorrectionMasterState(StbM_GetTimeCorrectionMasterConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), newRate, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE_IND_TIMEBASECONFIG */
  StbM_SetRateDeviationValidOfTimeCorrectionMasterState(StbM_GetTimeCorrectionMasterConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), TRUE, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE_IND_TIMEBASECONFIG */

#   if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
  /* #60 Update status notification event with: RateCorrection */
  StbM_StatusNotification_OnRateCorrectionEvent(timeBaseIdx, partitionIdx);
#   endif
} /* StbM_TimeCorrection_SetRateMaster */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateMaster
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_GetRateMaster(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get rate for rate correction in internal rate type */
  return StbM_GetRateCorrectionRateOfTimeCorrectionMasterState(StbM_GetTimeCorrectionMasterConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_TimeCorrection_GetRateMaster */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsAllowMasterRateCorrection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsAllowMasterRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Check if rate correction is allowed for the given timebase */
  return (StbM_GetTimeCorrectionMasterConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx) < StbM_GetSizeOfTimeCorrectionMasterConfig(partitionIdx));
} /* StbM_TimeCorrection_IsAllowMasterRateCorrection */
#  endif /* (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) */

#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_TimeCorrection_InitSlave
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_InitSlave(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 slaveIdx;

  /* ----- Implementation ----------------------------------------------- */

  for (slaveIdx = 0u; slaveIdx < StbM_GetSizeOfTimeCorrectionSlaveState(partitionIdx); slaveIdx++)
  {
    StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfTimeCorrectionSlaveConfig(slaveIdx, partitionIdx);

    /* #10 Set rate correction rate to zero */
    StbM_SetRateCorrectionOfTimeCorrectionSlaveState(slaveIdx, 1.0, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONSLAVESTATE */

    /* #20 Set valid rate calculation to FALSE */
    StbM_SetRateDeviationValidOfTimeCorrectionSlaveState(slaveIdx, FALSE, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONSLAVESTATE */

    /* #30 Set offset rate correction to zero */
    StbM_SetOffsetRateCorrectionOfTimeCorrectionOffsetSlaveState(StbM_GetIndirectionToTimeCorrectionOffsetSlaveStateIdxOfTimeBasePartitionMapping(timeBaseIdx), 0.0, StbM_GetIndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_TIMECORRECTIONOFFSETSLAVESTATE_IND_TIMEBASEPARTITIONMAPPING */

    /* #40 Set valid offset correction rate to FALSE */
    StbM_SetOffsetCorrectionRateValidOfTimeCorrectionOffsetSlaveState(StbM_GetIndirectionToTimeCorrectionOffsetSlaveStateIdxOfTimeBasePartitionMapping(timeBaseIdx), FALSE, StbM_GetIndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_TIMECORRECTIONOFFSETSLAVESTATE_IND_TIMEBASEPARTITIONMAPPING */
  }

  /* #50 Initialize the rate measurement */
  StbM_TimeCorrection_InitRateMeasurement(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
} /* StbM_TimeCorrection_InitSlave */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_InitRateMeasurement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_InitRateMeasurement(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 i;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  for (i = 0u; i < StbM_GetSizeOfRateMeasurements(partitionIdx); i++)
  {
    /* #10 Set valid flag for reate measurement to FALSE */
    StbM_SetValidOfRateMeasurements(i, FALSE, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS */

    /* #30 Set the start status to 0 */
    StbM_SetStartStatusOfRateMeasurements(i, 0u, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS */

    /* #40 Set TGstart, TVstart, TGstop and TVstop to 0 */
    StbM_SetStartGlobalTimeOfRateMeasurements(i, STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS */
    StbM_SetStopGlobalTimeOfRateMeasurements(i, STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS */
    StbM_SetStartVirtualLocalTimeOfRateMeasurements(i, STBM_ZERO_VIRTUAL_LOCAL_TIME, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS */
    StbM_SetStopVirtualLocalTimeOfRateMeasurements(i, STBM_ZERO_VIRTUAL_LOCAL_TIME, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS */
  }
} /* StbM_TimeCorrection_InitRateMeasurement */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If timebase has time correction for slave configured: */
  if (StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
    /* #20 Update rate for rate correction, r_rc and r_roc */
    StbM_TimeCorrection_UpdateRateCorrection(timeBaseIdx, partitionIdx);

    /* #30 Update rate for offset correction, r_oc */
    StbM_TimeCorrection_UpdateOffsetRateCorrection(timeBaseIdx, partitionIdx);
  }
} /* StbM_TimeCorrection_Update */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_UpdateRateCorrection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_UpdateRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if all running measurements are still valid to run */
  StbM_TimeCorrection_StopInvalidRateMeasurement(timeBaseIdx, partitionIdx);

  /* #20 Check all running rate corrections and stop them if necessary */
  StbM_TimeCorrection_StopExpiredRateMeasurement(timeBaseIdx, partitionIdx);

  /* #30 Check if any new measurement shall be started */
  StbM_TimeCorrection_StartNewRateMeasurement(timeBaseIdx, partitionIdx);
} /* StbM_TimeCorrection_UpdateRateCorrection */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_UpdateOffsetRateCorrection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_UpdateOffsetRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If rate deviation is valid and jump is within jump threshold: */
  if ((StbM_TimeCorrection_IsRateDeviationValid(timeBaseIdx, partitionIdx) == TRUE)
     && (StbM_TimeCorrection_IsJumpWithinJumpThreshold(timeBaseIdx, partitionIdx) == TRUE))
  {
    StbM_InternalRateType rate;

    /* #20 Calculate rate for offset rate correction, denoted as r_oc */
    rate = StbM_TimeCorrection_CalculateRateForOffsetRateCorrectionSlave(timeBaseIdx, partitionIdx);

    /* #30 Set r_oc */
    StbM_TimeCorrection_SetRateForOffsetRateCorrection(timeBaseIdx, rate, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }
  /* #40 Otherwise set offset correction rate invalid */
  else
  {
    StbM_TimeCorrection_ResetOffsetRateCorrection(timeBaseIdx, partitionIdx);
  }
} /* StbM_TimeCorrection_UpdateOffsetRateCorrection */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_ResetOffsetRateCorrection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_ResetOffsetRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Set offset rate correction to zero */
  StbM_SetOffsetRateCorrectionOfTimeCorrectionOffsetSlaveState(StbM_GetIndirectionToTimeCorrectionOffsetSlaveStateIdxOfTimeBasePartitionMapping(timeBaseId), 0.0, StbM_GetIndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_TIMECORRECTIONOFFSETSLAVESTATE_IND_TIMEBASEPARTITIONMAPPING */

  /* #20 Set valid offset correction rate to FALSE */
  StbM_SetOffsetCorrectionRateValidOfTimeCorrectionOffsetSlaveState(StbM_GetIndirectionToTimeCorrectionOffsetSlaveStateIdxOfTimeBasePartitionMapping(timeBaseId), FALSE, StbM_GetIndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_TIMECORRECTIONOFFSETSLAVESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_TimeCorrection_ResetOffsetRateCorrection */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsOffsetRateCorrectionValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsOffsetRateCorrectionValid(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Check if offset rate correction has been calculated and is valid therefore */
  return StbM_IsOffsetCorrectionRateValidOfTimeCorrectionOffsetSlaveState(StbM_GetIndirectionToTimeCorrectionOffsetSlaveStateIdxOfTimeBasePartitionMapping(timeBaseId), StbM_GetIndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId));
} /* StbM_TimeCorrection_IsOffsetRateCorrectionValid */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_StartNewRateMeasurement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_StartNewRateMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #5 Initialize min start time to infinity */
  StbM_VirtualLocalTimeType minStartTime = {STBM_VIRTUALLOCALTIME_MAX_NANOSECONDS, STBM_VIRTUALLOCALTIME_MAX_NANOSECONDS};

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Don't start a new measurement if time leap is set */
  if (StbM_Status_IsTimeLeap(timeBaseIdx, partitionIdx) == FALSE)
  {
    uint32 i;
    uint32 startIdx;
    uint32 stopIdx;
    uint32 idxNewMeasurement;
    StbM_InternalTimeStampType globalTimeStart = STBM_INIT_TIME_ZERO;
    StbM_VirtualLocalTimeType virtualLocalTimeStart = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
    StbM_VirtualLocalTimeType startTimeMeasurement;
    StbM_VirtualLocalTimeType deltaStartTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
    StbM_VirtualLocalTimeType singleRateCorrectionMeasurementDuration = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

    /* #20 Get configured duration between two starts of parallel measurements */
    StbM_TimeCorrection_GetDistanceForNextParallelRateCorrectionMeasurement(timeBaseIdx, &singleRateCorrectionMeasurementDuration, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #30 Get TGstart and TVstart */
    StbM_LocalTime_GetGlobalTimeRx(timeBaseIdx, &globalTimeStart, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LocalTime_GetVirtualLocalTimeRx(timeBaseIdx, &virtualLocalTimeStart, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #40 Set start/stop index of rate measurement storage for the given timebase */
    startIdx = StbM_GetRateMeasurementsStartIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
    stopIdx = StbM_GetRateMeasurementsEndIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

    /* #50 Set index for new measurement to stop index */
    idxNewMeasurement = stopIdx;

    /* #60 For each measurement slot between start and stop: */
    for (i = startIdx; i < stopIdx; i++) /* FETA_StbM_2 */
    {
      /* #70 Find minimal delta (dTVmin) between TVsync and stored measurement TVstart */
      if (StbM_IsValidOfRateMeasurements(i, partitionIdx))
      {
        startTimeMeasurement = StbM_GetStartVirtualLocalTimeOfRateMeasurements(i, partitionIdx);

        StbM_Calc_SubtractVirtualLocalTimes(&virtualLocalTimeStart, &startTimeMeasurement, &deltaStartTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

        if (StbM_Calc_LessThan_VirtualLocalTime(&deltaStartTime, &minStartTime) == TRUE) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
        {
          minStartTime = deltaStartTime;
        }
      }
      else
      {
        /* #80 Find new slot to put the measurement */
        if (idxNewMeasurement == stopIdx)
        {
          /* #90 Set TGstart and TVstart */
          StbM_SetStartGlobalTimeOfRateMeasurements(i, globalTimeStart, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG */
          StbM_SetStartVirtualLocalTimeOfRateMeasurements(i, virtualLocalTimeStart, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG */
          StbM_SetStartStatusOfRateMeasurements(i, StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG */

          /* #100 Store index of slot to new measurement index */
          idxNewMeasurement = i;
        }
      }
    }

    /* #110 If index for new measurement was set and minimal delta dTVmin > configured duration between two starts of parallel measurement: */
    if ((idxNewMeasurement < stopIdx) && (StbM_Calc_LessThan_VirtualLocalTime(&minStartTime, &singleRateCorrectionMeasurementDuration) == FALSE)) /* PRQA S 3415 */ /* MD_StbM_Rule13.5_3415 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    {
      /* #120 Start new measurement */
      StbM_SetValidOfRateMeasurements(idxNewMeasurement, TRUE, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG */
    }
  }
} /* StbM_TimeCorrection_StartNewRateMeasurement */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_StopExpiredRateMeasurement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_StopExpiredRateMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 i;
  uint32 startIdx;
  uint32 stopIdx;
  StbM_InternalTimeStampType globalTimeStop = STBM_INIT_TIME_ZERO;
  StbM_VirtualLocalTimeType virtualLocalTimeStop = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType virtualLocalTimeStart;
  StbM_VirtualLocalTimeType deltaVirtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType rateCorrectionMeasurementDuration = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get TGstop and TVstop and rate correction duration */
  StbM_LocalTime_GetGlobalTimeRx(timeBaseIdx, &globalTimeStop, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  StbM_LocalTime_GetVirtualLocalTimeRx(timeBaseIdx, &virtualLocalTimeStop, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  StbM_TimeCorrection_GetRateCorrectionMeasurementDuration(timeBaseIdx, &rateCorrectionMeasurementDuration, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  startIdx = StbM_GetRateMeasurementsStartIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
  stopIdx = StbM_GetRateMeasurementsEndIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

  /* #20 For each measurement storage of the given timebase: */
  for (i = startIdx; i < stopIdx; i++) /* FETA_StbM_2 */
  {
    /* #30 If measurement is running: */
    if (StbM_IsValidOfRateMeasurements(i, partitionIdx))
    {
      /* #40 Update TGstop and TVstop */
      StbM_SetStopGlobalTimeOfRateMeasurements(i, globalTimeStop, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG */
      StbM_SetStopVirtualLocalTimeOfRateMeasurements(i, virtualLocalTimeStop, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG */

      /* #50 Get TVstart */
      virtualLocalTimeStart = StbM_GetStartVirtualLocalTimeOfRateMeasurements(i, partitionIdx);

      /* #60 Calculate dTV = TVstop - TVstart */
      StbM_Calc_SubtractVirtualLocalTimes(&virtualLocalTimeStop, &virtualLocalTimeStart, &deltaVirtualLocalTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      /* #70 If dTV >= StbMRateCorrectionMeasurementDuration then stop measurement */
      if (StbM_Calc_LessThan_VirtualLocalTime(&deltaVirtualLocalTime, &rateCorrectionMeasurementDuration) == FALSE) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      {
        Std_ReturnType retVal;
        StbM_InternalRateType newRate = 1.0;

        /* #80 Calculate new rate */
        retVal = StbM_TimeCorrection_CalculateRateForRateCorrectionSlave(timeBaseIdx, i, &newRate, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

        /* #90 If new rate is valid: */
        if (retVal == E_OK)
        {
          /* #100 Set new rate */
          StbM_TimeCorrection_SetRateForRateCorrectionSlave(timeBaseIdx, newRate, partitionIdx);

          /* #110 Set a valid rate has been calculated for this timebase */
          StbM_SetRateDeviationValidOfTimeCorrectionSlaveState(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), TRUE, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONSLAVESTATE_IND_TIMEBASECONFIG */

#   if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
          /* #120 Update status notification event with: RateCorrection */
          StbM_StatusNotification_OnRateCorrectionEvent(timeBaseIdx, partitionIdx);
#   endif
        }

        /* #130 Invalidate this measurement storage */
        StbM_SetValidOfRateMeasurements(i, FALSE, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG */
      }
    }
  }
} /* StbM_TimeCorrection_StopExpiredRateMeasurement */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_StopInvalidRateMeasurement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_StopInvalidRateMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If for the given timebase: time leap, timeout or a change in the sgw bit occurred: */
  if (StbM_TimeCorrection_IsRateMeasurementValid(timeBaseIdx, partitionIdx) == FALSE)
  {
    /* #20 Stop invalid measurement */
    StbM_TimeCorrection_StopRateMeasurement(timeBaseIdx, partitionIdx);
  }
} /* StbM_TimeCorrection_StopInvalidRateMeasurement */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_StopRateMeasurement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_StopRateMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 startIdx;
  uint32 endIdx;
  uint32 i;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  startIdx = StbM_GetRateMeasurementsStartIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
  endIdx = StbM_GetRateMeasurementsEndIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

  /* #10 Set rate deviation to invalid */
  StbM_SetRateDeviationValidOfTimeCorrectionSlaveState(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), FALSE, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONSLAVESTATE_IND_TIMEBASECONFIG */

  /* #20 For each configured measurement: */
  for (i = startIdx; i < endIdx; i++) /* FETA_StbM_2 */
  {
    /* #30 Invalidate the measurement */
    StbM_SetValidOfRateMeasurements(i, FALSE, partitionIdx); /* SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG */
  }
} /* StbM_TimeCorrection_StopRateMeasurement */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_DidSyncToGatewayStateChanged
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_DidSyncToGatewayStateChanged(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 i;
  uint32 startIdx;
  uint32 stopIdx;
  StbM_TimeBaseStatusType globalTimeStatus;
  StbM_TimeBaseStatusType measurementStatus;
  boolean change = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the timebase status of TGsync */
  globalTimeStatus = StbM_Status_GetGlobalTimeSyncStatus(timeBaseIdx, partitionIdx);

  startIdx = StbM_GetRateMeasurementsStartIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
  stopIdx = StbM_GetRateMeasurementsEndIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

  /* #20 For each measurement storage of the given timebase */
  for (i = startIdx; i < stopIdx; i++) /* FETA_StbM_2 */
  {
    /* #30 If measurement is running */
    if (StbM_IsValidOfRateMeasurements(i, partitionIdx))
    {
      /* #40 Get status of stored TGsync of this measurement */
      measurementStatus = StbM_GetStartStatusOfRateMeasurements(i, partitionIdx);

      /* #50 Return invalid, if sync to gateway bit is different between current TGsync and stored */
      if (StbM_GetSyncToGatewayBit(globalTimeStatus) != StbM_GetSyncToGatewayBit(measurementStatus))
      {
        change = TRUE;
        break;
      }
    }
  }
  return change;
} /* StbM_TimeCorrection_DidSyncToGatewayStateChanged */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsRateMeasurementValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsRateMeasurementValid(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  boolean isValid = FALSE;

  /* #10 Rate measurement valid if: sgw bit did not change during measurement and no timeout and no time leap */
  if ((StbM_TimeCorrection_DidSyncToGatewayStateChanged(timeBaseIdx, partitionIdx) == FALSE)
      && (StbM_Status_IsTimeLeap(timeBaseIdx, partitionIdx) == FALSE)
#   if (STBM_CONFIG_TIMEOUT == STD_ON)
      && (StbM_Status_IsTimeout(timeBaseIdx, partitionIdx) == FALSE)
#   endif
  )
  {
    isValid = TRUE;
  }

  return isValid;
} /* StbM_TimeCorrection_IsRateMeasurementValid */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_CalculateRateForRateCorrectionSlave
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_TimeCorrection_CalculateRateForRateCorrectionSlave(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        uint32 rateMeasurementIdx,
        P2VAR(StbM_InternalRateType, AUTOMATIC, STBM_APPL_VAR) rate,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType virtualLocalTimeStart;
  StbM_VirtualLocalTimeType virtualLocalTimeStop;
  StbM_VirtualLocalTimeType deltaVirtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  uint64 deltaTV = 0u;
  StbM_InternalTimeStampType globalTimeStart;
  StbM_InternalTimeStampType globalTimeStop;
  Std_ReturnType isdTGpositive;
  StbM_InternalTimeStampType deltaGlobalTime = STBM_INIT_TIME_ZERO;
  uint64 deltaTG = 0u;
  StbM_InternalRateType calculatedRate;

  /* ----- Implementation ----------------------------------------------- */
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get TVstart */
  virtualLocalTimeStart = StbM_GetStartVirtualLocalTimeOfRateMeasurements(rateMeasurementIdx, partitionIdx);

  /* #20 Get TVstop */
  virtualLocalTimeStop = StbM_GetStopVirtualLocalTimeOfRateMeasurements(rateMeasurementIdx, partitionIdx);

  /* #30 Calculate dTV = TVstop - TVstart */
  StbM_Calc_SubtractVirtualLocalTimes(&virtualLocalTimeStop, &virtualLocalTimeStart, &deltaVirtualLocalTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #40 Convert to appropriate type */
  StbM_Calc_ToNanoseconds_Uint64_VirtualLocalTime(&deltaVirtualLocalTime, &deltaTV); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #50 Get TGstart */
  globalTimeStart = StbM_GetStartGlobalTimeOfRateMeasurements(rateMeasurementIdx, partitionIdx);

  /* #60 Get TGstop */
  globalTimeStop = StbM_GetStopGlobalTimeOfRateMeasurements(rateMeasurementIdx, partitionIdx);

  /* #70 Calculate dTG = TGstop - TGstart */
  isdTGpositive = StbM_Calc_SubtractTimeStamps(&globalTimeStop, &globalTimeStart, &deltaGlobalTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #80 Convert to appropriate type */
  retVal = StbM_Calc_ToNanoseconds_Uint64(&deltaGlobalTime, &deltaTG); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #90 Calculate rate = (dTG / dTV) */
  calculatedRate = (StbM_InternalRateType)deltaTG / (StbM_InternalRateType)deltaTV;

  /* #100 Consider sign of rate */
  if (isdTGpositive == E_NOT_OK)
  {
#   if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
    /* #110 If offset timebase, rate = (dTG / dTV) + 1 */
    if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
    {
      calculatedRate *= -1.0;
    }
    else
#   endif
    {
      retVal = E_NOT_OK;
    }
  }

#   if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  /* #110 If offset timebase, rate = (dTG / dTV) + 1 */
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
  {
    calculatedRate += 1.0;
  }
  else
#   endif
  {
    STBM_DUMMY_STATEMENT(timeBaseIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* #120 Ensure rate is within bounds [0.968, 1.032], which corresponds to [-32000, 32000] ppm */
  if ((calculatedRate > STBM_MAX_RATE_FLOAT) || (calculatedRate < STBM_MIN_RATE_FLOAT))
  {
    retVal = E_NOT_OK;
  }
  else
  {
    *rate = calculatedRate; /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  return retVal;
} /* StbM_TimeCorrection_CalculateRateForRateCorrectionSlave */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_CalculateRateForOffsetRateCorrectionSlave
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_CalculateRateForOffsetRateCorrectionSlave(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_NanosecondsType offsetCorrectionAdaptionInterval;
  StbM_InternalTimeStampType globalTimeRx = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType localTimeSync = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType delta = STBM_INIT_TIME_ZERO;
  uint32 deltaNs = 0u;
  Std_ReturnType isDeltaPositive;
  StbM_InternalRateType rate;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get StbMOffsetCorrectionAdaptionInterval */
  offsetCorrectionAdaptionInterval = StbM_TimeCorrection_GetOffsetCorrectionAdaptionInterval(timeBaseIdx, partitionIdx);

  /* #20 Get TLsync */
  StbM_LocalTime_GetLocalTimeSync(timeBaseIdx, &localTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #30 Get TGrx */
  StbM_LocalTime_GetGlobalTimeRx(timeBaseIdx, &globalTimeRx, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #40 Calculate dT = TGrx - TLsync */
  isDeltaPositive = StbM_Calc_SubtractTimeStamps(&globalTimeRx, &localTimeSync, &delta); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #50 If Conversion to nanoseconds. Can not fail because this function is called only if abs(TG - TLsync) < StbMOffsetCorrectionJumpThreshold <= 4sec */
  (void) StbM_Calc_ToNanoseconds(&delta, &deltaNs); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #60 Calculate (dT / Tcorr_int), Tcorr_int = OffsetCorrectionAdaptionInterval */
  rate = (StbM_InternalRateType)deltaNs / (StbM_InternalRateType)offsetCorrectionAdaptionInterval;

  /* #70 Consider sign of rate */
  if (isDeltaPositive == E_NOT_OK)
  {
    rate *= -1.0;
  }

  return rate;
} /* StbM_TimeCorrection_CalculateRateForOffsetRateCorrectionSlave */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_SetRateForRateCorrectionSlave
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_SetRateForRateCorrectionSlave(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_InternalRateType rate,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Set rate for rate correction to given slave */
  StbM_SetRateCorrectionOfTimeCorrectionSlaveState(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), rate, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONSLAVESTATE_IND_TIMEBASECONFIG */ /* VCA_STBM_CSL02_CSL03 */
} /* StbM_TimeCorrection_SetRateForRateCorrectionSlave */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_SetRateForOffsetRateCorrection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_SetRateForOffsetRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_InternalRateType rate,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Set rate for offset correction to given slave */
  StbM_SetOffsetRateCorrectionOfTimeCorrectionOffsetSlaveState(StbM_GetIndirectionToTimeCorrectionOffsetSlaveStateIdxOfTimeBasePartitionMapping(timeBaseId), rate, StbM_GetIndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_TIMECORRECTIONOFFSETSLAVESTATE_IND_TIMEBASEPARTITIONMAPPING */

  /* #20 Set a valid offset correction rate has been calculated for this timebase */
  StbM_SetOffsetCorrectionRateValidOfTimeCorrectionOffsetSlaveState(StbM_GetIndirectionToTimeCorrectionOffsetSlaveStateIdxOfTimeBasePartitionMapping(timeBaseId), TRUE, StbM_GetIndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_TIMECORRECTIONOFFSETSLAVESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_TimeCorrection_SetRateForOffsetRateCorrection */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateForRateCorrection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_GetRateForRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get current stored rate for rate correction */
  return StbM_GetRateCorrectionOfTimeCorrectionSlaveState(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_TimeCorrection_GetRateForRateCorrection */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateForOffsetRateCorrection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_InternalRateType, STBM_CODE) StbM_TimeCorrection_GetRateForOffsetRateCorrection(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get current stored rate for offset rate correction */
  return StbM_GetOffsetRateCorrectionOfTimeCorrectionOffsetSlaveState(StbM_GetIndirectionToTimeCorrectionOffsetSlaveStateIdxOfTimeBasePartitionMapping(timeBaseId), StbM_GetIndirectionToTimeCorrectionOffsetSlaveStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId));
} /* StbM_TimeCorrection_GetRateForOffsetRateCorrection */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetOffsetCorrectionAdaptionInterval
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_NanosecondsType, STBM_CODE) StbM_TimeCorrection_GetOffsetCorrectionAdaptionInterval(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

    /* #10 Get the configured offset correction adaption interval */
  return (StbM_NanosecondsType) StbM_GetOffsetCorrectionAdaptionIntervalOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_TimeCorrection_GetOffsetCorrectionAdaptionInterval */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetRateCorrectionMeasurementDuration
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_GetRateCorrectionMeasurementDuration(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) rateMeasurementDuration,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get rate correction measurement duration */
  rateMeasurementDuration->nanosecondsHi = StbM_GetRateCorrectionMeasurementDurationNanosecondsHiOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  rateMeasurementDuration->nanosecondsLo = StbM_GetRateCorrectionMeasurementDurationNanosecondsLoOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeCorrection_GetRateCorrectionMeasurementDuration */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetDistanceForNextParallelRateCorrectionMeasurement
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_TimeCorrection_GetDistanceForNextParallelRateCorrectionMeasurement(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) distance,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get rate correction measurement duration / rate correction per measurement */
  distance->nanosecondsHi = StbM_GetSingleRateCorrectionMeasurementDurationNanosecondsHiOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
  distance->nanosecondsLo = StbM_GetSingleRateCorrectionMeasurementDurationNanosecondsLoOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_TimeCorrection_GetDistanceForNextParallelRateCorrectionMeasurement */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_GetJumpThreshold
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_NanosecondsType, STBM_CODE) StbM_TimeCorrection_GetJumpThreshold(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#   if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif

  /* #10 Get the configured jump threshold */
  return (StbM_NanosecondsType) StbM_GetOffsetCorrectionJumpThresholdOfTimeCorrectionSlaveConfig(StbM_GetTimeCorrectionSlaveConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_TimeCorrection_GetJumpThreshold */

/**********************************************************************************************************************
 *  StbM_TimeCorrection_IsJumpWithinJumpThreshold
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_TimeCorrection_IsJumpWithinJumpThreshold(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalTimeStampType jump = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType jumpThreshold;
  StbM_NanosecondsType jumpThresholdNs;

  StbM_InternalTimeStampType localTimeSync = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType globalTimeRx = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If time correction is configured for the given timebase: */
  StbM_LocalTime_GetGlobalTimeRx(timeBaseIdx, &globalTimeRx, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  StbM_LocalTime_GetLocalTimeSync(timeBaseIdx, &localTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Get the jump threshold */
  jumpThresholdNs = StbM_TimeCorrection_GetJumpThreshold(timeBaseIdx, partitionIdx);

  jumpThreshold.secondsHi = 0u;
  jumpThreshold.seconds = jumpThresholdNs / STBM_NANOSECONDS_IN_ONE_SECOND;
  jumpThreshold.nanoseconds = jumpThresholdNs % STBM_NANOSECONDS_IN_ONE_SECOND;

  /* #30 Jump is valid, if it is jump < StbMOffsetCorrectionJumpThreshold */
  (void) StbM_Calc_SubtractTimeStamps(&localTimeSync, &globalTimeRx, &jump); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  return StbM_Calc_LessThan(&jump, &jumpThreshold); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
} /* StbM_TimeCorrection_IsJumpWithinJumpThreshold */
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) */
# endif /* (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) */

#  if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON))
/**********************************************************************************************************************
 *  StbM_TimeCorrection_CloneRateValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_TimeCorrection_CloneRateValue(
        StbM_SynchronizedTimeBaseType sourceTimeBaseIdx,
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_InternalRateType sourceRateDeviation;
  StbM_InternalRateType sourceRatePPM;
  StbM_InternalRateType maxRateDeviation;
  uint16 timeCorrectionIdx;

  /* #10 If time correction is configured, get rate value of source time base */
  if (StbM_TimeCorrection_HasTimeCorrectionConfigured(destinationTimeBaseIdx, partitionIdx) == TRUE)
  {
    timeCorrectionIdx = StbM_GetTimeCorrectionMasterConfigIdxOfTimeBaseConfig(destinationTimeBaseIdx, partitionIdx);

    sourceRateDeviation = StbM_TimeCorrection_GetRate(sourceTimeBaseIdx, partitionIdx);

    sourceRatePPM = (StbM_InternalRateType) StbM_ToStbMRateDeviationType(sourceRateDeviation);

    /* #20 Get configured max rate deviation: r_max */
    maxRateDeviation = (StbM_InternalRateType) StbM_GetMaxRateDeviationOfTimeCorrectionMasterConfig(timeCorrectionIdx, partitionIdx);

    /* #30 Ensure that rate deviation is bound to configured max value like: -r_max < r < r_max */
    if ((sourceRatePPM > maxRateDeviation) || (sourceRatePPM < -maxRateDeviation))
    {
      if (sourceRatePPM > 0.0)
      {
        sourceRatePPM = maxRateDeviation;
      }
      else
      {
        sourceRatePPM = -maxRateDeviation;
      }
    }

    /* #40 Convert given rate from ppm into internal rate type */
    sourceRateDeviation = StbM_ToStbMInternalRateType(sourceRatePPM);

    /* #50 Store new converted rate */
    /*@ assert timeCorrectionIdx < StbM_GetSizeOfTimeCorrectionMasterState(partitionIdx); */ /* VCA_STBM_CSL02_CSL03 */
    StbM_SetRateCorrectionRateOfTimeCorrectionMasterState(timeCorrectionIdx, sourceRateDeviation, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE_IND_TIMEBASECONFIG */
    StbM_SetRateDeviationValidOfTimeCorrectionMasterState(timeCorrectionIdx, TRUE, partitionIdx); /* SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE_IND_TIMEBASECONFIG */
  }

} /* StbM_TimeCorrection_CloneRateValue */
#  endif /* (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) && (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON) */
#endif /* STBM_NOUNIT_TIMECORRECTION */ 

#ifndef STBM_NOUNIT_STATUS /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: Status
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_Status_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 statusIdx;

  /* ----- Implementation ----------------------------------------------- */
  for (statusIdx = 0u; statusIdx < StbM_GetSizeOfStatus(partitionIdx); statusIdx++)
  {
    /* #10 Initialize global time status to 0x00 */
    StbM_Status_ResetStatusGlobalTime(statusIdx, partitionIdx);

    /* #20 Initialize local time status to 0x00 */
    StbM_Status_ResetStatusLocalTime(statusIdx, partitionIdx);
  }
} /* StbM_Status_Init */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeBaseStatusType timeBaseStatus,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set status of TGsync */
  StbM_Status_SetGlobalTimeSyncStatus(timeBaseIdx, timeBaseStatus, partitionIdx);

  /* #20 Update changes in SGW bit */
  StbM_Status_UpdateSyncToGatewayStatus(timeBaseIdx, partitionIdx);
} /* StbM_Status_Update */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_ResetStatusLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ResetStatusLocalTime(
        uint16 statusIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set the status to zero */
  StbM_SetLocalTimeStatusOfStatus(statusIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_STATUS */
} /* StbM_Status_ResetStatusLocalTime */

# if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_ClearLocalStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ClearLocalStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 Set all status bits to zero */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, 0u, partitionIdx);
} /* StbM_Status_ClearLocalStatus */
# endif /* (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_SetLocalTimeStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_Status_SetLocalTimeStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeBaseStatusType timeBaseStatus,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 Set the status of the local time */
  StbM_SetLocalTimeStatusOfStatus(StbM_GetStatusIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), timeBaseStatus, partitionIdx); /* SBSW_STBM_ACCESS_STATUS_IND_TIMEBASECONFIG */

# if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
  if (timeBaseStatus != 0u)
  {
    /* #20 Update status notification, if configured */
    StbM_StatusNotification_Update(timeBaseIdx, partitionIdx);
  }
# elif (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* StbM_Status_SetLocalTimeStatus */

/**********************************************************************************************************************
 *  StbM_Status_GetLocalTimeStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(StbM_TimeBaseStatusType, STBM_CODE) StbM_Status_GetLocalTimeStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Get the status of given time base */
  return StbM_GetLocalTimeStatusOfStatus(StbM_GetStatusIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_Status_GetLocalTimeStatus */

# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_GetLocalTimeStatusCombined
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(StbM_TimeBaseStatusType, STBM_CODE) StbM_Status_GetLocalTimeStatusCombined(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType referredTimeBaseIdx = timeBaseIdx;
  StbM_PartitionIdentifiersIterType referredPartitionIdx = partitionIdx;

  StbM_TimeBase_GetReferredTimeBase(timeBaseIdx, partitionIdx, &referredTimeBaseIdx, &referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  /* #10 Get combined local time status */
  return StbM_Status_CalculateCombinedStatus(StbM_GetLocalTimeStatusOfStatus(StbM_GetStatusIdxOfTimeBaseConfig(referredTimeBaseIdx, referredPartitionIdx), referredPartitionIdx), StbM_GetLocalTimeStatusOfStatus(StbM_GetStatusIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx));
} /* StbM_Status_GetLocalTimeStatusCombined */

/**********************************************************************************************************************
 *  StbM_Status_CalculateCombinedStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_TimeBaseStatusType, STBM_CODE) StbM_Status_CalculateCombinedStatus(
        StbM_TimeBaseStatusType syncStatus,
        StbM_TimeBaseStatusType offsetStatus)
{
  /* #10 Combine status of sync- and offset-timebase. The global time bit gets enabled if it is enabled in sync- and offset timebase */
  return (((offsetStatus | syncStatus) & ~StbM_Global_Time_Base_BflMask) | (offsetStatus & syncStatus & StbM_Global_Time_Base_BflMask));
} /* StbM_Status_CalculateCombinedStatus */
# endif /* (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_ResetStatusGlobalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ResetStatusGlobalTime(
        uint16 statusIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set the status to zero */
  StbM_SetGlobalTimeStatusOfStatus(statusIdx, 0u, partitionIdx); /* SBSW_STBM_ACCESS_STATUS */
} /* StbM_Status_ResetStatusGlobalTime */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_SetGlobalTimeSyncStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetGlobalTimeSyncStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeBaseStatusType timeBaseStatus,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set the status of the global time */
  StbM_SetGlobalTimeStatusOfStatus(StbM_GetStatusIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), timeBaseStatus, partitionIdx); /* SBSW_STBM_ACCESS_STATUS_IND_TIMEBASECONFIG */
} /* StbM_Status_SetGlobalTimeSyncStatus */

/**********************************************************************************************************************
 *  StbM_Status_GetGlobalTimeSyncStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_TimeBaseStatusType, STBM_CODE) StbM_Status_GetGlobalTimeSyncStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the status of the global time */
  return StbM_GetGlobalTimeStatusOfStatus(StbM_GetStatusIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_Status_GetGlobalTimeSyncStatus */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_SetSynchronized
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_Status_SetSynchronized(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Set the global time base bit */
  StbM_SetGlobalTimeBaseBit(timeBaseStatus);

  /* #30 Set the new status to local time status */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, timeBaseStatus, partitionIdx);
} /* StbM_Status_SetSynchronized */

# if ((STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) || (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsSynchronized
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Status_IsSynchronized(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Check if global timebase bit is not equal zero */
  return (StbM_GetGlobalTimeBaseBit(timeBaseStatus) != 0u);
} /* StbM_Status_SetSynchronized */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) || (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) */

# if (STBM_CONFIG_TIMEOUT == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_ClearTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ClearTimeout(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Remove pending clone request */
#  if (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON)
  if (StbM_GetTimeoutBit(timeBaseStatus) != 0u)
  {
    StbM_CloneTime_RemovePendingCloneRequest(timeBaseIdx, partitionIdx);
  }
#  endif

  /* #30 Clear the timeout bit */
  StbM_ClearTimeoutBit(timeBaseStatus);

  /* #40 Set the new status to local time status */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, timeBaseStatus, partitionIdx);
} /* StbM_Status_ClearTimeout */

/**********************************************************************************************************************
 *  StbM_Status_SetTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetTimeout(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Set the timeout bit */
  StbM_SetTimeoutBit(timeBaseStatus);

  /* #30 Set the new status to local time status */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, timeBaseStatus, partitionIdx);

  /* #40 Remove pending clone request */
#  if (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON)
  StbM_CloneTime_RemovePendingCloneRequest(timeBaseIdx, partitionIdx);
#  endif

  /* #50 Trigger local clock synchronization */
#  if (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON)
  (void)StbM_LocalTime_TriggerLocalClockSync(timeBaseIdx, partitionIdx);
#  endif
} /* StbM_Status_SetTimeout */

#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Status_IsTimeout(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Check if timeout bit is set */
  return (StbM_GetTimeoutBit(timeBaseStatus) != 0u);
} /* StbM_Status_IsTimeout */
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */
# endif /* (STBM_CONFIG_TIMEOUT == STD_ON) */

# if (STBM_CONFIG_TIME_LEAP == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_ClearTimeLeapFuture
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ClearTimeLeapFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Clear the time leap future bit */
  StbM_ClearTimeLeapFutureBit(timeBaseStatus);

  /* #30 Set the new status to local time status */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, timeBaseStatus, partitionIdx);
} /* StbM_Status_ClearTimeLeapFuture */

/**********************************************************************************************************************
 *  StbM_Status_SetTimeLeapFuture
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetTimeLeapFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Set the time leap future bit */
  StbM_SetTimeLeapFutureBit(timeBaseStatus);

  /* #30 Set the new status to local time status */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, timeBaseStatus, partitionIdx);
} /* StbM_Status_SetTimeLeapFuture */

#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsTimeLeapFuture
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Status_IsTimeLeapFuture(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);
  /* #20 Check if the time leap future bit is set */
  return (StbM_GetTimeLeapFutureBit(timeBaseStatus) != 0u);
} /* StbM_Status_IsTimeLeapFuture */
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Status_ClearTimeLeapPast
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_ClearTimeLeapPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Clear the time leap past bit */
  StbM_ClearTimeLeapPastBit(timeBaseStatus);

  /* #30 Set the new status to local time status */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, timeBaseStatus, partitionIdx);
} /* StbM_Status_ClearTimeLeapPast */

/**********************************************************************************************************************
 *  StbM_Status_SetTimeLeapPast
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetTimeLeapPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Set the time leap past bit */
  StbM_SetTimeLeapPastBit(timeBaseStatus);

  /* #30 Set the new status to local time status */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, timeBaseStatus, partitionIdx);
} /* StbM_Status_SetTimeLeapPast */

#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsTimeLeapPast
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Status_IsTimeLeapPast(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Check if the time leap past bit is set */
  return (StbM_GetTimeLeapPastBit(timeBaseStatus) != 0u);
} /* StbM_Status_IsTimeLeapPast */
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */

#  if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_IsTimeLeap
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Status_IsTimeLeap(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isTimeLeap;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if either time leap future or time leap past is active */
  if (StbM_Status_IsTimeLeapFuture(timeBaseIdx, partitionIdx) == TRUE)
  {
    isTimeLeap = TRUE;
  }
  else if (StbM_Status_IsTimeLeapPast(timeBaseIdx, partitionIdx) == TRUE)
  {
    isTimeLeap = TRUE;
  }
  else
  {
    isTimeLeap = FALSE;
  }
  return isTimeLeap;
} /* StbM_Status_IsTimeLeap */
#  endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */
# endif /* (STBM_CONFIG_TIME_LEAP == STD_ON) */

# if ((STBM_CONFIG_GATEWAY == STD_ON) && (STBM_CONFIG_TIMEOUT == STD_ON))
/**********************************************************************************************************************
 *  StbM_Status_SetSyncToGateway
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_SetSyncToGateway(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType timeBaseStatus;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of local time */
  timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #20 Set the sync to gateway bit */
  StbM_SetSyncToGatewayBit(timeBaseStatus);

  /* #30 Set the new status to local time status */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, timeBaseStatus, partitionIdx);
} /* StbM_Status_SetSyncToGateway */
# endif /* (STBM_CONFIG_GATEWAY == STD_ON) && (STBM_CONFIG_TIMEOUT == STD_ON) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_Status_UpdateSyncToGatewayStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Status_UpdateSyncToGatewayStatus(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_TimeBaseStatusType statusGlobalTime;
  StbM_TimeBaseStatusType statusLocalTime;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the current status of global time */
  statusGlobalTime = StbM_Status_GetGlobalTimeSyncStatus(timeBaseIdx, partitionIdx);

  /* #20 Get the current status of local time */
  statusLocalTime = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx);

  /* #30 Remove sync to gateway bit from current status, add the sync to gateway bit from the received status */
  statusLocalTime = ((statusLocalTime & ~StbM_Sync_To_Gateway_BflMask) | (statusGlobalTime & StbM_Sync_To_Gateway_BflMask));

  /* #40 Write the local status back */
  StbM_Status_SetLocalTimeStatus(timeBaseIdx, statusLocalTime, partitionIdx);
} /* StbM_Status_UpdateSyncToGatewayStatus */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */
#endif /* STBM_NOUNIT_STATUS */

#ifndef STBM_NOUNIT_LOCALTIME /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: LocalTime
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_LocalTime_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_Init(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 localTimeIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For all configured local time: */
  for (localTimeIdx = 0u; localTimeIdx < StbM_GetSizeOfLocalTimeConfig(partitionIdx); localTimeIdx++)
  {
# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
    if (StbM_TimeBase_IsOffset(StbM_GetTimeBaseConfigIdxOfLocalTimeConfig(localTimeIdx, partitionIdx), partitionIdx) == FALSE)
# endif
    {
      /* #20 Initialize Os local clock */
# if (STBM_CONFIG_OS_CLOCK == STD_ON)
      StbM_LocalTime_InitOsLocalClock(localTimeIdx, partitionIdx);
# endif

      /* #30 Initialize Gpt local clock */
# if (STBM_CONFIG_GPT_CLOCK == STD_ON)
      StbM_LocalTime_InitGptLocalClock(localTimeIdx, partitionIdx);
# endif

      /* #40 Initialize Eth local clock */
# if (STBM_CONFIG_ETH_CLOCK == STD_ON)
      StbM_LocalTime_InitEthLocalClock(localTimeIdx, partitionIdx);
# endif
    }

    /* #50 Reset local time */
    StbM_LocalTime_ResetLocalTime(localTimeIdx, partitionIdx);

    /* #60 Reset local time sync */
    StbM_LocalTime_ResetLocalTimeSync(localTimeIdx, partitionIdx);

    /* #70 Reset global time sync */
    StbM_LocalTime_ResetGlobalTimeSync(localTimeIdx, partitionIdx);

    /* #80 Reset global time rx */
    StbM_LocalTime_ResetGlobalTimeRx(localTimeIdx, partitionIdx);

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    /* #90 Reset time leap */
    StbM_LocalTime_ResetTimeLeap(localTimeIdx, partitionIdx);

    /* #100 Reset virtual local time rx */
    StbM_LocalTime_ResetVirtualLocalTimeRx(localTimeIdx, partitionIdx);
# endif

    /* #110 Reset virtual local time */
    StbM_LocalTime_ResetVirtualLocalTime(localTimeIdx, partitionIdx);

    /* #120 Reset virtual local time sync */
    StbM_LocalTime_ResetVirtualLocalTimeSync(localTimeIdx, partitionIdx);

    /* #130 Reset virtual local time elapsed after adaption interval */
    StbM_LocalTime_ResetVirtualLocalTimeElapsedAfterAdaptionInterval(localTimeIdx, partitionIdx);
  }
} /* StbM_LocalTime_Init */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetLocalTime(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(localTimeId, partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set local time to zero */
  StbM_SetLocalTimeOfLocalTimeState(StbM_GetIndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseIdx), STBM_ZERO_TIME, StbM_GetIndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_LOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
  StbM_SetLocalTimeUpdatedOfLocalTimeState(StbM_GetIndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseIdx), E_NOT_OK, StbM_GetIndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_LOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_ResetLocalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetLocalLocalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetLocalTimeSync(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set local time at synchronization event to zero */
  StbM_SetLocalTimeSyncOfReceivedTimeState(localTimeId, STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_ACCESS_RECEIVEDTIME_IND_LOCALTIME */
} /* StbM_LocalTime_ResetLocalLocalTimeSync */

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetGlobalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetGlobalTimeSync(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(localTimeId, partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set global time to zero */
  StbM_SetGlobalTimeSyncOfMainTimeState(StbM_GetIndirectionToMainTimeStateIdxOfTimeBasePartitionMapping(timeBaseIdx), STBM_ZERO_TIME, StbM_GetIndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_MAINTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_ResetGlobalTimeSync */

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetGlobalTimeRx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetGlobalTimeRx(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set global time to zero */
  StbM_SetGlobalTimeRxOfReceivedTimeState(localTimeId, STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_ACCESS_RECEIVEDTIME_IND_LOCALTIME */
} /* StbM_LocalTime_ResetGlobalTimeRx */

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetVirtualLocalTime(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(localTimeId, partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set virtual local time to zero */
  StbM_SetVirtualLocalTimeOfVirtualLocalTimeState(StbM_GetIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseIdx), STBM_ZERO_VIRTUAL_LOCAL_TIME, StbM_GetIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_VIRTUALLOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_ResetVirtualLocalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetVirtualLocalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetVirtualLocalTimeSync(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(localTimeId, partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set virtual local time at synchronization event to zero */
  StbM_SetVirtualLocalTimeSyncOfMainTimeState(StbM_GetIndirectionToMainTimeStateIdxOfTimeBasePartitionMapping(timeBaseIdx), STBM_ZERO_VIRTUAL_LOCAL_TIME, StbM_GetIndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_MAINTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_ResetVirtualLocalTimeSync */

/**********************************************************************************************************************
 *  StbM_LocalTime_ResetVirtualLocalTimeElapsedAfterAdaptionInterval
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetVirtualLocalTimeElapsedAfterAdaptionInterval(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(localTimeId, partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set virtual local time elapsed after adaption interval to zero */
  StbM_SetVirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState(StbM_GetIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseIdx), STBM_ZERO_VIRTUAL_LOCAL_TIME, StbM_GetIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_VIRTUALLOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_ResetVirtualLocalTimeElapsedAfterAdaptionInterval */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_ResetVirtualLocalTimeRx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetVirtualLocalTimeRx(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set received virtual local time to zero */
  StbM_SetVirtualLocalTimeRxOfReceivedTimeState(localTimeId, STBM_ZERO_VIRTUAL_LOCAL_TIME, partitionIdx); /* SBSW_STBM_ACCESS_RECEIVEDTIME_IND_LOCALTIME */
} /* StbM_LocalTime_ResetVirtualLocalTimeRx */
# endif /* STBM_CONFIG_TIME_SLAVE == STD_ON */

/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_CalculateLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType elapsedVirtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_InternalTimeStampType elapsedVirtualLocalInternalTimeStamp = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType globalTimeSync = STBM_INIT_TIME_ZERO;
# if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON))
  StbM_InternalRateType rate;
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate elapsed virtual local time */
  StbM_LocalTime_CalculateElapsedVirtualLocalTime(timeBaseIdx, virtualLocalTime, &elapsedVirtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  if (elapsedVirtualLocalTime.nanosecondsHi == 0u)
  {
    elapsedVirtualLocalInternalTimeStamp.nanoseconds = elapsedVirtualLocalTime.nanosecondsLo % STBM_NANOSECONDS_IN_ONE_SECOND;
    elapsedVirtualLocalInternalTimeStamp.seconds = elapsedVirtualLocalTime.nanosecondsLo / STBM_NANOSECONDS_IN_ONE_SECOND;
  }
  else
  {
    uint64 elapsedVirtualLocalTimeNanoseconds = 0u;
    StbM_Calc_ToNanoseconds_Uint64_VirtualLocalTime(&elapsedVirtualLocalTime, &elapsedVirtualLocalTimeNanoseconds); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    elapsedVirtualLocalInternalTimeStamp.nanoseconds = (uint32)(elapsedVirtualLocalTimeNanoseconds % STBM_NANOSECONDS_IN_ONE_SECOND);
    elapsedVirtualLocalInternalTimeStamp.seconds = (uint32)(elapsedVirtualLocalTimeNanoseconds / STBM_NANOSECONDS_IN_ONE_SECOND);
  }

  /* #20 Get TGsync */
  StbM_LocalTime_GetGlobalTimeSync(timeBaseIdx, &globalTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #30 If rate correction is configured: */
# if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON))
  /* #40 Get current rate to apply */
  rate = StbM_TimeCorrection_GetRate(timeBaseIdx, partitionIdx);

#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  /* #50 If rate is negative: */
  if (rate < 0.0)
  {
    /* #60 Calculate corrected elapsed virtual local time */
    retVal = StbM_Calc_MultiplyTimeStampWithRate(&elapsedVirtualLocalInternalTimeStamp, -rate); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #70 Subtract corrected elapsed virtual local time from global time */
    retVal |= StbM_Calc_SubtractTimeStamps(&globalTimeSync, &elapsedVirtualLocalInternalTimeStamp, localTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  }
  else
#  endif
  {
    /* #80 Calculate corrected elapsed virtual local time */
    retVal = StbM_Calc_MultiplyTimeStampWithRate(&elapsedVirtualLocalInternalTimeStamp, rate); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #90 Add corrected elapsed virtual local time to global time */
    retVal |= StbM_Calc_AddTimeStamps(&globalTimeSync, &elapsedVirtualLocalInternalTimeStamp, localTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  }
# else
#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  /* #100 If given timebase is offset timebase, TGsync is local time */
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
  {
    *localTime = globalTimeSync; /* SBSW_STBM_ACCESS_PARAMPTR */
    retVal = E_OK;
  }
  else
#  endif
  {
    /* #110 Add elapsed virtual local time to global time */
    retVal = StbM_Calc_AddTimeStamps(&globalTimeSync, &elapsedVirtualLocalInternalTimeStamp, localTime); /* PRQA S 2985 */ /* MD_StbM_Rule2.2_2985 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  }
# endif

  return retVal;
} /* StbM_LocalTime_CalculateLocalTime */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
# if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
  /* #10 Update local time after offset correction adaption interval */
  retVal = StbM_LocalTime_UpdateAfterOffsetCorrectionAdaptionInterval(timeBaseIdx, virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
# else
  retVal = E_OK;
# endif

  /* #20 Calculate current local time */
  retVal |= StbM_LocalTime_CalculateLocalTime(timeBaseIdx, virtualLocalTime, localTime, partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  return retVal;
} /* StbM_LocalTime_GetLocalTime */

# if ((STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) || (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_GetLastUpdatedLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetLastUpdatedLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get last updated local time and return E_OK if it is valid */
  *localTime = StbM_GetLocalTimeOfLocalTimeState(StbM_GetIndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), StbM_GetIndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_PARAMPTR */
  return StbM_GetLocalTimeUpdatedOfLocalTimeState(StbM_GetIndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), StbM_GetIndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId));
} /* StbM_LocalTime_GetLastUpdatedLocalTime */
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) || (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_GetLocalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetLocalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) localTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set TLsync */
  *localTimeSync = StbM_GetLocalTimeSyncOfReceivedTimeState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetLocalTimeSync */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetLocalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetLocalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) localTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the current local time of the synchronized timebase, which is TL */
  StbM_SetLocalTimeSyncOfReceivedTimeState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), *localTimeSync, partitionIdx); /* SBSW_STBM_ACCESS_RECEIVEDTIME_IND_LOCALTIME */
} /* StbM_LocalTime_SetLocalTimeSync */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetGlobalTimeRx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetGlobalTimeRx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimeRx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get received global time of given timebase */
  *globalTimeRx = StbM_GetGlobalTimeRxOfReceivedTimeState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetGlobalTimeRx */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetGlobalTimeRx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetGlobalTimeRx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimeRx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set TGrx */
  StbM_SetGlobalTimeRxOfReceivedTimeState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), *globalTimeRx, partitionIdx); /* SBSW_STBM_ACCESS_RECEIVEDTIME_IND_LOCALTIME */
} /* StbM_LocalTime_SetGlobalTimeRx */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetGlobalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetGlobalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Get received global time of given timebase */
  *globalTimeSync = StbM_GetGlobalTimeSyncOfMainTimeState(StbM_GetIndirectionToMainTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), StbM_GetIndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetGlobalTimeSync */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetGlobalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetGlobalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set TGsync */
  StbM_SetGlobalTimeSyncOfMainTimeState(StbM_GetIndirectionToMainTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), *globalTimeSync, StbM_GetIndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_MAINTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_SetGlobalTimeSync */

# if ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) && (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateOffsetValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_CalculateOffsetValue(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTime,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) offsetValue,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_InternalTimeStampType underlyingSyncTimeBaseLocalTime = STBM_INIT_TIME_ZERO;
  StbM_SynchronizedTimeBaseType referredTimeBaseIdx = timeBaseIdx;
  StbM_PartitionIdentifiersIterType referredPartitionIdx = partitionIdx;

  /* ----- Implementation ----------------------------------------------- */
  StbM_TimeBase_GetReferredTimeBase(timeBaseIdx, partitionIdx, &referredTimeBaseIdx, &referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #10 If the global timebase bit is set for the underlying synchronized timebase: */
  if (StbM_Status_IsSynchronized(referredTimeBaseIdx, referredPartitionIdx) == TRUE)
  {
    /* #20 Get current local time of the underlying synchronized timebase: TLref */
    retVal = StbM_LocalTime_OnGetCurrentVirtualLocalTime(timeBaseIdx, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    retVal |= StbM_LocalTime_GetLocalTime(referredTimeBaseIdx, &virtualLocalTime, &underlyingSyncTimeBaseLocalTime, referredPartitionIdx); /* PRQA S 2985 */ /* MD_StbM_Rule2.2_2985 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #30 Calculate the absolute offset of the given time and the underlying synchronized timebase by: abs(TG - TLref) */
    retVal |= StbM_Calc_SubtractTimeStamps(globalTime, &underlyingSyncTimeBaseLocalTime, offsetValue); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  }
  return retVal;
} /* StbM_LocalTime_CalculateOffsetValue */
# endif /* ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) && (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_ResetTimeLeap
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_ResetTimeLeap(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set time leap to zero and valid flag to false */
  StbM_SetTimeLeapOfTimeLeapState(localTimeId, 0, partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAP_IND_LOCALTIME */
  StbM_SetTimeLeapValidOfTimeLeapState(localTimeId, FALSE, partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAP_IND_LOCALTIME */
} /* StbM_LocalTime_ResetTimeLeap */

/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateTimeLeap
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_TimeDiffType, STBM_CODE) StbM_LocalTime_CalculateTimeLeap(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTime,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) localTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalTimeStampType maxTimeLeap = {147483647u, 2u, 0u};
  Std_ReturnType retVal;
  StbM_InternalTimeStampType difference = STBM_INIT_TIME_ZERO;
  StbM_TimeDiffType timeLeap;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set time leap to max */
  timeLeap = STBM_TIMELEAP_MAX_FUTURE;

  /* #20 Calculate the difference between given timestamps TG - TL */
  retVal = StbM_Calc_SubtractTimeStamps(globalTime, localTime, &difference); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #30 If difference is less than time leap max i.e. <= 2s: */
  if (StbM_Calc_LessThan(&difference, &maxTimeLeap) == TRUE) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  {
    uint32 timeLeapNs = 0u;

    /* #40 Convert difference to nanoseconds. Conversion can't fail because of step #30 */
    (void) StbM_Calc_ToNanoseconds(&difference, &timeLeapNs); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    timeLeap = (StbM_TimeDiffType) timeLeapNs;

    /* #50 Consider sign of difference (negative, positive) */
    if (retVal == E_NOT_OK)
    {
      timeLeap = -((StbM_TimeDiffType)timeLeapNs);
    }
  }
  else
  {
    /* #50 Consider sign of difference (negative, positive) */
    if (retVal == E_NOT_OK)
    {
      timeLeap = STBM_TIMELEAP_MAX_PAST;
    }
  }
  return timeLeap;
} /* StbM_LocalTime_CalculateTimeLeap */

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateTimeLeap
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_UpdateTimeLeap(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalTimeStampType localTimeSync = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType globalTimeReceived = STBM_INIT_TIME_ZERO;
  StbM_TimeDiffType timeLeap;

  /* ----- Implementation ----------------------------------------------- */
  if (StbM_Status_IsSynchronized(timeBaseIdx, partitionIdx) == TRUE)
  {
    /* #10 Get TLsync, which is the time before update */
    StbM_LocalTime_GetLocalTimeSync(timeBaseIdx, &localTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #20 Get TGrx, which is the received global time */
    StbM_LocalTime_GetGlobalTimeRx(timeBaseIdx, &globalTimeReceived, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #30 Calculate the time leap = TGrx - TLsync */
    timeLeap = StbM_LocalTime_CalculateTimeLeap(&globalTimeReceived, &localTimeSync); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #40 Set the time leap */
    StbM_LocalTime_SetTimeLeap(timeBaseIdx, timeLeap, partitionIdx);
  }
} /* StbM_LocalTime_UpdateTimeLeap */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetTimeLeap
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_TimeDiffType, STBM_CODE) StbM_LocalTime_GetTimeLeap(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get time leap */
  return StbM_GetTimeLeapOfTimeLeapState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_LocalTime_GetTimeLeap */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetTimeLeap
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetTimeLeap(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_TimeDiffType timeLeap,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set time leap and flag for valid time leap */
  StbM_SetTimeLeapOfTimeLeapState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), timeLeap, partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAP_IND_LOCALTIME */
  StbM_SetTimeLeapValidOfTimeLeapState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), TRUE, partitionIdx); /* SBSW_STBM_ACCESS_TIMELEAP_IND_LOCALTIME */
} /* StbM_LocalTime_SetTimeLeap */

/**********************************************************************************************************************
 *  StbM_LocalTime_IsTimeLeapValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_LocalTime_IsTimeLeapValid(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Check if the time leap is valid */
  return StbM_IsTimeLeapValidOfTimeLeapState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_LocalTime_IsTimeLeapValid */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_UpdateLocalTime(StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_SynchronizedTimeBaseType timeBaseIdx;
  StbM_SynchronizedTimeBaseType timeBaseId;
  StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each timebase: */
  for (timeBaseIdx = 0u; timeBaseIdx < StbM_GetSizeOfTimeBaseConfig(partitionIdx); timeBaseIdx++)
  {
      timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

      /* #20 Get the current time of the timebase */
      retVal = StbM_GlobalTime_GetTime(timeBaseIdx, &localTime, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      /* #30 Store it for later use */
      StbM_SetLocalTimeOfLocalTimeState(StbM_GetIndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), localTime, StbM_GetIndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_LOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */

      /* #40 Store also the return value of time retrieval */
      StbM_SetLocalTimeUpdatedOfLocalTimeState(StbM_GetIndirectionToLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), retVal, StbM_GetIndirectionToLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_LOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
  }
} /* StbM_LocalTime_UpdateLocalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_Update(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  StbM_SynchronizedTimeBaseType referredTimeBaseIdx = timeBaseIdx;
  StbM_PartitionIdentifiersIterType referredPartitionIdx = partitionIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get timebase index of synchronized timebase */
  StbM_TimeBase_GetReferredTimeBase(timeBaseIdx, partitionIdx, &referredTimeBaseIdx, &referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Update virtual local time based on clock source */
  switch (StbM_GetClockTypeOfLocalClockConfig(StbM_LocalTime_GetLocalClockIdx(referredTimeBaseIdx, referredPartitionIdx), referredPartitionIdx))
  {
# if (STBM_CONFIG_OS_CLOCK == STD_ON)
    case STBM_OS_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG:
      retVal = StbM_LocalTime_OnUpdateOsVirtualLocalTime(referredTimeBaseIdx, referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      break;
# endif

# if (STBM_CONFIG_GPT_CLOCK == STD_ON)
    case STBM_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG:
      retVal = StbM_LocalTime_OnUpdateGptVirtualLocalTime(referredTimeBaseIdx, referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      break;
# endif

# if (STBM_CONFIG_ETH_CLOCK == STD_ON)
    case STBM_ETH_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG:
      retVal = StbM_LocalTime_OnUpdateEthVirtualLocalTime(referredTimeBaseIdx, referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      break;
# endif

    default: /* COV_STBM_MSR_MISRA */
      break;
  }

  return retVal;
} /* StbM_LocalTime_Update */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateMainTimeTuple
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_UpdateMainTimeTuple(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) localTimePtr,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update TGsync */
  StbM_LocalTime_SetGlobalTimeSync(timeBaseIdx, globalTimePtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  /* #20 Update TVsync */
  StbM_LocalTime_SynchronizeVirtualLocalTime(timeBaseIdx, localTimePtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

} /* StbM_LocalTime_UpdateMainTimeTuple */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateMainTimeTupleAfterBusReceive
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_UpdateMainTimeTupleAfterBusReceive(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalTimeStampType globalTime = STBM_INIT_TIME_ZERO;
  StbM_VirtualLocalTimeType receivedVirtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the received virtual local time */
  StbM_LocalTime_GetVirtualLocalTimeRx(timeBaseIdx, &receivedVirtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
  /* #20 If offset correction is performed, get local time sync */
  if ((StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured(timeBaseIdx, partitionIdx) == TRUE) && (StbM_TimeCorrection_IsOffsetRateCorrectionValid(timeBaseIdx, partitionIdx) == TRUE))
  {
    StbM_LocalTime_GetLocalTimeSync(timeBaseIdx, &globalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }
  else
#  endif
  /* #30 Otherwise get received global time */
  {
    StbM_LocalTime_GetGlobalTimeRx(timeBaseIdx, &globalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }

  /* #40 Update main time tuple */
  StbM_LocalTime_UpdateMainTimeTuple(timeBaseIdx, &globalTime, &receivedVirtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

} /* StbM_LocalTime_UpdateMainTimeTupleAfterBusReceive */

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateReceivedTimeTuple
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateReceivedTimeTuple(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) localTimePtr,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType currentVirtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType receptionDelay = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_InternalTimeStampType updatedGlobalTime = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Get current virtual local time */
  retVal = StbM_LocalTime_OnGetCurrentVirtualLocalTime(timeBaseIdx, &currentVirtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Calculate reception delay */
  StbM_Calc_SubtractVirtualLocalTimes(&currentVirtualLocalTime, localTimePtr, &receptionDelay); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #30 Calculate updated received global time */
  retVal |= StbM_LocalTime_CalculateUpdatedReceivedGlobalTime(timeBaseIdx, globalTimePtr, &receptionDelay, &updatedGlobalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #40 Update TGrx */
  StbM_LocalTime_SetGlobalTimeRx(timeBaseIdx, &updatedGlobalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #50 Update TVrx */
  StbM_LocalTime_SetVirtualLocalTimeRx(timeBaseIdx, &currentVirtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  return retVal;
} /* StbM_LocalTime_UpdateReceivedTimeTuple */

/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateUpdatedReceivedGlobalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_CalculateUpdatedReceivedGlobalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) receptionDelayPtr,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) updatedGlobalTimePtr,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  Std_ReturnType retVal;
  StbM_InternalTimeStampType receptionDelayInternalTimeStamp = STBM_INIT_TIME_ZERO;
#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
  StbM_InternalRateType rate;
#  endif

  /* ----- Implementation ----------------------------------------------- */

  /* #10 If valid convert reception delay to internal time stamp type */
  if (receptionDelayPtr->nanosecondsHi == 0u)
  {
    receptionDelayInternalTimeStamp.nanoseconds = receptionDelayPtr->nanosecondsLo % STBM_NANOSECONDS_IN_ONE_SECOND;
    receptionDelayInternalTimeStamp.seconds = receptionDelayPtr->nanosecondsLo / STBM_NANOSECONDS_IN_ONE_SECOND;

    /* #20 Rate correct reception delay and set updated global time */
#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
    if (StbM_TimeCorrection_HasTimeCorrectionConfigured(timeBaseIdx, partitionIdx) == TRUE)
    {
      rate = StbM_TimeCorrection_GetRateForRateCorrection(timeBaseIdx, partitionIdx);
#   if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
      if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
      {
        rate -= 1.0;
      }
#   endif

      retVal = StbM_Calc_MultiplyTimeStampWithRate(&receptionDelayInternalTimeStamp, rate); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
      retVal |= StbM_Calc_AddTimeStamps(&receptionDelayInternalTimeStamp, globalTimePtr, updatedGlobalTimePtr); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    }
    else
#  endif
    {
#   if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
      if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
      {
        retVal = E_OK;
        /* For offset time bases without time correction, rate is 0 */
        *updatedGlobalTimePtr = *globalTimePtr; /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      }
      else
#   endif
      {
        STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
        STBM_DUMMY_STATEMENT(timeBaseIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

        /* For normal time bases without time correction, rate is 1 */
        retVal = StbM_Calc_AddTimeStamps(&receptionDelayInternalTimeStamp, globalTimePtr, updatedGlobalTimePtr); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      }
    }
  }
  else
  {
    /* #30 If reception delay is invalid set updated global time to global time */
    retVal = E_NOT_OK;
    *updatedGlobalTimePtr = *globalTimePtr; /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }

  return retVal;
} /* StbM_LocalTime_CalculateUpdatedReceivedGlobalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateSynclocalTimeTuple
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateSynclocalTimeTuple(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType updatedVirtualLocalTimeRx = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_InternalTimeStampType localTimeSync = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get virtual local time of updated Rx time tuple */
  StbM_LocalTime_GetVirtualLocalTimeRx(timeBaseIdx, &updatedVirtualLocalTimeRx, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Get local time TL of timebase, if succeeded: */
  retVal = StbM_LocalTime_GetLocalTime(timeBaseIdx, &updatedVirtualLocalTimeRx, &localTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  if (retVal == E_OK) /* PRQA S 2991, 2995 */ /* MD_StbM_Rule14.3_2991, MD_StbM_Rule2.2_2995 */
  {
    /* #30 Update TLsync */
    StbM_LocalTime_SetLocalTimeSync(timeBaseIdx, &localTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #40 Update TVsync */
    StbM_LocalTime_SynchronizeVirtualLocalTime(timeBaseIdx, &updatedVirtualLocalTimeRx, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  }

  return retVal;
} /* StbM_LocalTime_UpdateSynclocalTimeTuple */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_SynchronizeVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SynchronizeVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 Set virtual local time sync, TVsync */
  StbM_LocalTime_SetVirtualLocalTimeSync(timeBaseIdx, virtualLocalTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
  if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == FALSE)
# endif
  {
    /* #20 Set elapsed clock value and virtual local time elapsed after adaption interval to zero */
    StbM_LocalTime_SetElapsedClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LocalTime_SetVirtualLocalTimeElapsedAfterAdaptionInterval(timeBaseIdx, &STBM_ZERO_VIRTUAL_LOCAL_TIME, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }
} /* StbM_LocalTime_SynchronizeVirtualLocalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateAfterMainTimeTupleTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_UpdateAfterMainTimeTupleTimeout(
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_SynchronizedTimeBaseType timeBaseIdx;
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType elapsedTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType updateTime = {3u * STBM_NANOSECONDS_IN_ONE_SECOND, 0u};
  StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  for (timeBaseIdx = 0u; timeBaseIdx < StbM_GetSizeOfTimeBaseConfig(partitionIdx); timeBaseIdx++)
  {
    /* #10 Get virtual local time */
    StbM_LocalTime_GetVirtualLocalTime(timeBaseIdx, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #20 Calculate dTV, elapsed virtual local time */
    StbM_LocalTime_CalculateElapsedVirtualLocalTime(timeBaseIdx, &virtualLocalTime, &elapsedTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #30 Get local time TL of timebase */
    retVal = StbM_LocalTime_GetLocalTime(timeBaseIdx, &virtualLocalTime, &localTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #40 If time calculation succeeded and timeout occurred: */
    if ((retVal == E_OK) && (StbM_Calc_LessEqualThan_VirtualLocalTime(&elapsedTime, &updateTime) == FALSE)) /* PRQA S 2995, 3415 */ /* MD_StbM_Rule2.2_2995, MD_StbM_Rule13.5_3415 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    {
      /* #50 Update main time tuple */
      StbM_LocalTime_UpdateMainTimeTuple(timeBaseIdx, &localTime, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    }
  }
} /* StbM_LocalTime_UpdateAfterMainTimeTupleTimeout */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

# if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateAfterOffsetCorrectionAdaptionInterval
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateAfterOffsetCorrectionAdaptionInterval(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured(timeBaseIdx, partitionIdx) == TRUE)
  {
    StbM_VirtualLocalTimeType virtualLocalTimeSync = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
    StbM_VirtualLocalTimeType elapsedVirtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
    StbM_VirtualLocalTimeType offsetCorrectionAdaptionInterval = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
    StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;

    /* #10 Get TVsync */
    StbM_LocalTime_GetVirtualLocalTimeSync(timeBaseIdx, &virtualLocalTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #20 Get offset correction adaption interval */
    offsetCorrectionAdaptionInterval.nanosecondsLo = StbM_TimeCorrection_GetOffsetCorrectionAdaptionInterval(timeBaseIdx, partitionIdx);

    StbM_LocalTime_CalculateElapsedVirtualLocalTime(timeBaseIdx, virtualLocalTime, &elapsedVirtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    if ((StbM_TimeCorrection_IsOffsetRateCorrectionValid(timeBaseIdx, partitionIdx) == TRUE) && (StbM_Calc_LessThan_VirtualLocalTime(&elapsedVirtualLocalTime, &offsetCorrectionAdaptionInterval) == FALSE)) /* PRQA S 3415 */ /* MD_StbM_Rule13.5_3415 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    {
      StbM_VirtualLocalTimeType virtualLocalTimeTemp = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

      /* #30 Calculate TVtemp = TVsync + OffsetCorrectionAdaptionInterval. Can not overflow because TVtemp < TV */
      (void) StbM_Calc_AddVirtualLocalTimes(&virtualLocalTimeSync, &offsetCorrectionAdaptionInterval, &virtualLocalTimeTemp); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      /* #40 Calculate local time TLtemp of timebase, if succeeded: */
      retVal = StbM_LocalTime_CalculateLocalTime(timeBaseIdx, &virtualLocalTimeTemp, &localTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      if (retVal == E_OK)
      {
        /* #50 Update main time tuple */
        StbM_LocalTime_UpdateMainTimeTuple(timeBaseIdx, &localTime, &virtualLocalTimeTemp, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
        if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == FALSE)
#  endif
        {
          /* #60 Calculate and set virtual local time elapsed after adaption interval */
          StbM_VirtualLocalTimeType virtualLocalTimeElapsedAfterAdaptionInterval = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
          StbM_Calc_SubtractVirtualLocalTimes(virtualLocalTime, &virtualLocalTimeTemp, &virtualLocalTimeElapsedAfterAdaptionInterval); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
          StbM_LocalTime_SetVirtualLocalTimeElapsedAfterAdaptionInterval(timeBaseIdx, &virtualLocalTimeElapsedAfterAdaptionInterval, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
        }
      }

      /* #70 Set offset correction rate invalid */
      StbM_TimeCorrection_ResetOffsetRateCorrection(timeBaseIdx, partitionIdx);
    }
  }

  return retVal;
} /* StbM_LocalTime_UpdateAfterOffsetCorrectionAdaptionInterval */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) elapsedTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_SynchronizedTimeBaseType timeBaseId;
  StbM_VirtualLocalTimeType virtualLocalTimeSync = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType currentVirtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType virtualLocalTimeElapsedAfterAdaptionInterval = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType updatedVirtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get virtual local time at synchronization event */
  StbM_LocalTime_GetVirtualLocalTimeSync(timeBaseIdx, &virtualLocalTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Add elapsed time to virtual local time at synchronization event */
  retVal = StbM_Calc_AddVirtualLocalTimes(&virtualLocalTimeSync, elapsedTime, &currentVirtualLocalTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #30 Add virtual local time elapsed after adaption interval */
  StbM_LocalTime_GetVirtualLocalTimeElapsedAfterAdaptionInterval(timeBaseIdx, &virtualLocalTimeElapsedAfterAdaptionInterval, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  retVal |= StbM_Calc_AddVirtualLocalTimes(&currentVirtualLocalTime, &virtualLocalTimeElapsedAfterAdaptionInterval, &updatedVirtualLocalTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #40 If no overflow of virtual local time happened */
  if (retVal == E_OK)
  {
    timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

    /* #50 Set new current virtual local time */
    StbM_SetVirtualLocalTimeOfVirtualLocalTimeState(StbM_GetIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), updatedVirtualLocalTime, StbM_GetIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_VIRTUALLOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
  }

  return retVal;
} /* StbM_LocalTime_UpdateVirtualLocalTime */
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType referredTimeBaseIdx = timeBaseIdx;
  StbM_PartitionIdentifiersIterType referredPartitionIdx = partitionIdx;
  StbM_SynchronizedTimeBaseType referredTimeBaseId;

  StbM_TimeBase_GetReferredTimeBase(timeBaseIdx, partitionIdx, &referredTimeBaseIdx, &referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  referredTimeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(referredTimeBaseIdx, referredPartitionIdx), referredPartitionIdx);

  /* #10 Get virtual local time, TV */
  *virtualLocalTime = StbM_GetVirtualLocalTimeOfVirtualLocalTimeState(StbM_GetIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping(referredTimeBaseId), StbM_GetIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(referredTimeBaseId)); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetVirtualLocalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetVirtualLocalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Get virtual local time, TVsync */
  *virtualLocalTime = StbM_GetVirtualLocalTimeSyncOfMainTimeState(StbM_GetIndirectionToMainTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), StbM_GetIndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetVirtualLocalTimeSync */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetVirtualLocalTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SetVirtualLocalTimeSync(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTimeSync,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set virtual local time sync, TVsync */
  StbM_SetVirtualLocalTimeSyncOfMainTimeState(StbM_GetIndirectionToMainTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), *virtualLocalTimeSync, StbM_GetIndirectionToMainTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_MAINTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_SetVirtualLocalTimeSync */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTimeRx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetVirtualLocalTimeRx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get received virtual local time, TVrx */
  *virtualLocalTime = StbM_GetVirtualLocalTimeRxOfReceivedTimeState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetVirtualLocalTimeRx */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetVirtualLocalTimeRx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_SetVirtualLocalTimeRx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTimeRx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Set received virtual local time, TVrx */
  StbM_SetVirtualLocalTimeRxOfReceivedTimeState(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), *virtualLocalTimeRx, partitionIdx); /* SBSW_STBM_ACCESS_RECEIVEDTIME_IND_LOCALTIME */
} /* StbM_LocalTime_SetVirtualLocalTimeRx */
# endif /* STBM_CONFIG_TIME_SLAVE == STD_ON */

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTimeElapsedAfterAdaptionInterval
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_GetVirtualLocalTimeElapsedAfterAdaptionInterval(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedVirtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get virtual local time elapsed after adaption interval */
  *elapsedVirtualLocalTime = StbM_GetVirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState(StbM_GetIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), StbM_GetIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetVirtualLocalTimeElapsedAfterAdaptionInterval */
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_OnGetCurrentVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_OnGetCurrentVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) virtualLocalTimePtr,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update virtual local time */
  retVal = StbM_LocalTime_Update(timeBaseIdx, partitionIdx);

  /* #20 Get virtual local time */
  StbM_LocalTime_GetVirtualLocalTime(timeBaseIdx, virtualLocalTimePtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  return retVal;
} /* StbM_LocalTime_OnGetCurrentVirtualLocalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetVirtualLocalTimeElapsedAfterAdaptionInterval
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SetVirtualLocalTimeElapsedAfterAdaptionInterval(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) elapsedVirtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set virtual local time elapsed after adaption interval */
  StbM_SetVirtualLocalTimeElapsedAfterAdaptionIntervalOfVirtualLocalTimeState(StbM_GetIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), *elapsedVirtualLocalTime, StbM_GetIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_VIRTUALLOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_SetVirtualLocalTimeElapsedAfterAdaptionInterval */

/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateElapsedVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_CalculateElapsedVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedVirtualLocalTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_VirtualLocalTimeType virtualLocalTimeSync = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the TVsync */
  StbM_LocalTime_GetVirtualLocalTimeSync(timeBaseIdx, &virtualLocalTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Calculate the delta virtual local time dTV = TV - TVsync */
  StbM_Calc_SubtractVirtualLocalTimes(virtualLocalTime, &virtualLocalTimeSync, elapsedVirtualLocalTime); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
} /* StbM_LocalTime_CalculateElapsedVirtualLocalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetLocalClockIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(uint16, STBM_CODE) StbM_LocalTime_GetLocalClockIdx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Get the index from timebase -> local time -> local index */
  return StbM_GetLocalClockConfigIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_LocalTime_GetLocalClockIdx */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetLastClockValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetLastClockValue(
        uint32 clockIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) clockValue,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalClockConfig(clockIdx, partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Get the last clock value */
  *clockValue = StbM_GetLastReadTimeOfLocalClockState(StbM_GetIndirectionToLocalClockStateIdxOfTimeBasePartitionMapping(timeBaseIdx), StbM_GetIndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetLastClockValue */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetLastClockValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SetLastClockValue(
        uint32 clockIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) clockValue,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalClockConfig(clockIdx, partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set the last clock value */
  StbM_SetLastReadTimeOfLocalClockState(StbM_GetIndirectionToLocalClockStateIdxOfTimeBasePartitionMapping(timeBaseIdx), *clockValue, StbM_GetIndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_LOCALCLOCKSTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_SetLastClockValue */

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) || (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_GetElapsedClockValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_GetElapsedClockValue(
        uint32 clockIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) elapsedClockValue,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalClockConfig(clockIdx, partitionIdx);

#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 Get the elapsed clock value since last synchronization event */
  *elapsedClockValue = StbM_GetElapsedTimeOfLocalClockState(StbM_GetIndirectionToLocalClockStateIdxOfTimeBasePartitionMapping(timeBaseIdx), StbM_GetIndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_GetElapsedClockValue */
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) || (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON) */

/**********************************************************************************************************************
 *  StbM_LocalTime_SetElapsedClockValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_SetElapsedClockValue(
        uint32 clockIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) elapsedClockValue,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalClockConfig(clockIdx, partitionIdx);

# if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set the elapsed clock value since last synchronization event */
  StbM_SetElapsedTimeOfLocalClockState(StbM_GetIndirectionToLocalClockStateIdxOfTimeBasePartitionMapping(timeBaseIdx), *elapsedClockValue, StbM_GetIndirectionToLocalClockStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_LOCALCLOCKSTATE_IND_TIMEBASEPARTITIONMAPPING */
} /* StbM_LocalTime_SetElapsedClockValue */

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_UpdateElapsedClockValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_UpdateElapsedClockValue(
        uint32 clockIdx,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) elapsedClockValue,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  StbM_InternalTimeStampType currentElapsedClockValue = STBM_INIT_TIME_ZERO;
  StbM_InternalTimeStampType updatedElapsedClockValue = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get current elapsed clock value */
  StbM_LocalTime_GetElapsedClockValue(clockIdx, &currentElapsedClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Add elapsed clock value to current elapsed clock value */
  updatedElapsedClockValue.nanoseconds = currentElapsedClockValue.nanoseconds + (*elapsedClockValue).nanoseconds;

  /* #30 If no overflow of elapsed clock value happened */
  if (updatedElapsedClockValue.nanoseconds >= currentElapsedClockValue.nanoseconds)
  {
    /* #40 Set new current elapsed clock value */
    StbM_LocalTime_SetElapsedClockValue(clockIdx, &updatedElapsedClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    retVal = E_OK;
  }

  return retVal;
} /* StbM_LocalTime_UpdateElapsedClockValue */
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) */

# if (STBM_CONFIG_OS_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_InitOsLocalClock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_InitOsLocalClock(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

#  if ((STBM_CONFIG_GPT_CLOCK == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON))
  if ((StbM_GetClockTypeOfLocalClockConfig(StbM_GetLocalClockConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), partitionIdx)) == STBM_OS_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG)
#  endif
  {
    TickType osTickValue = 0u;
    StbM_InternalTimeStampType clockValue = STBM_INIT_CLOCK_ZERO;

    /* #10 Set last read counter value to current counter value */
    (void) GetCounterValue(StbM_GetOsCounterSymbolicNameOfOsClockConfig(StbM_GetOsClockConfigIdxOfLocalClockConfig(StbM_GetLocalClockConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), partitionIdx), partitionIdx), &osTickValue); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    clockValue.nanoseconds = osTickValue;
    StbM_LocalTime_SetLastClockValue(StbM_GetLocalClockConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), &clockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #20 Reset elapsed clock value */
    StbM_LocalTime_SetElapsedClockValue(StbM_GetLocalClockConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), &STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }
} /* StbM_LocalTime_InitOsLocalClock */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetOsLocalClockIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint16, STBM_CODE) StbM_LocalTime_GetOsLocalClockIdx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 Get index of Os local clock by: timebase -> local time -> local clock -> Os local clock */
  return StbM_GetOsClockConfigIdxOfLocalClockConfig(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_LocalTime_GetOsLocalClockIdx */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetOsElapsedTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetOsElapsedTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  TickType osTicks, elapsedOsCounterValue = 0u;
  StbM_InternalTimeStampType lastClockValue, elapsedClockValue = STBM_INIT_CLOCK_ZERO;
  StatusType retValGetElapsedValue;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get last read Os counter value */
  StbM_LocalTime_GetLastClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &lastClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  osTicks = lastClockValue.nanoseconds;

  /* #20 Call Os to get the delta of the last read Os counter value and the current Os counter value */
  retValGetElapsedValue = GetElapsedValue(StbM_GetOsCounterSymbolicNameOfOsClockConfig(StbM_LocalTime_GetOsLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx), &osTicks, &elapsedOsCounterValue); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #30 If retrieved Os counter value is valid: */
  if (retValGetElapsedValue == E_OK)
  {
    /* #40 Store this new delta read value for next retrieval */
    lastClockValue.nanoseconds = osTicks;
    StbM_LocalTime_SetLastClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &lastClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #50 Update and get current elapsed clock value */
    elapsedClockValue.nanoseconds = elapsedOsCounterValue;
    retVal = StbM_LocalTime_UpdateElapsedClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &elapsedClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #60 Calculate and set elapsed nanoseconds */
    StbM_LocalTime_CalculateElapsedTimeFromElapsedCounterValue(timeBaseIdx, elapsedTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  }
  return retVal;
} /* StbM_LocalTime_GetOsElapsedTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_OnUpdateOsVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_OnUpdateOsVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType elapsedTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If retrieval of elapsed time from Os based clock source succeeded: */
  retVal = StbM_LocalTime_GetOsElapsedTime(timeBaseIdx, &elapsedTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  if (retVal == E_OK)
  {
    /* #20 Update virtual local time */
    retVal = StbM_LocalTime_UpdateVirtualLocalTime(timeBaseIdx, &elapsedTime, partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }

  return retVal;
} /* StbM_LocalTime_OnUpdateOsVirtualLocalTime */
# endif /* (STBM_CONFIG_OS_CLOCK == STD_ON) */

# if (STBM_CONFIG_GPT_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_InitGptLocalClock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_InitGptLocalClock(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint16 clockIdx = StbM_GetLocalClockConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx);

  /* ----- Implementation ----------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  STBM_DUMMY_STATEMENT(partitionIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  /* #10 If local time has Gpt clock reference: */
#  if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON))
  if (StbM_GetClockTypeOfLocalClockConfig(clockIdx, partitionIdx) == STBM_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG)
#  endif
  {
    uint16 gptClockIdx = StbM_GetGptClockConfigIdxOfLocalClockConfig(clockIdx, partitionIdx);
    StbM_SynchronizedTimeBaseType timeBaseIdx = StbM_GetTimeBasePartitionMappingIdxOfLocalClockConfig(clockIdx, partitionIdx);

    /* #20 If Gpt channel not yet active: */
    if (StbM_IsGptChannelActiveOfGptClockState(StbM_GetIndirectionToGptClockStateIdxOfTimeBasePartitionMapping(timeBaseIdx), StbM_GetIndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)) == FALSE)
    {
      /* #30 Set Gpt channel active */
      StbM_SetGptChannelActiveOfGptClockState(StbM_GetIndirectionToGptClockStateIdxOfTimeBasePartitionMapping(timeBaseIdx), TRUE, StbM_GetIndirectionToGptClockStatePartitionIdxOfTimeBasePartitionMapping(timeBaseIdx)); /* SBSW_STBM_ACCESS_GPTCLOCKSTATE_IND_TIMEBASEPARTITIONMAPPING */

      /* #40 Initialize the Gpt timer with max tick value */
      Gpt_StartTimer(StbM_GetGptChannelSymbolicNameOfGptClockConfig(gptClockIdx, partitionIdx), (Gpt_ValueType) StbM_GetMaxTickValueOfGptClockConfig(gptClockIdx, partitionIdx));
    }

    /* #50 Set last read counter value to zero */
    StbM_LocalTime_SetLastClockValue(clockIdx, &STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #60 Reset elapsed clock value */
    StbM_LocalTime_SetElapsedClockValue(clockIdx, &STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }
} /* StbM_LocalTime_InitGptLocalClock */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetGptLocalClockIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint16, STBM_CODE) StbM_LocalTime_GetGptLocalClockIdx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 Get index of Gpt local clock by: timebase -> local time -> local clock -> Gpt local clock */
  return StbM_GetGptClockConfigIdxOfLocalClockConfig(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_LocalTime_GetGptLocalClockIdx */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetGptElapsedTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetGptElapsedTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_GptTickType gptCounterValue, lastGptCounterValue, elapsedCounterValue;
  StbM_InternalTimeStampType lastClockValue, elapsedClockValue = STBM_INIT_CLOCK_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call Gpt to get the current counter value */
  gptCounterValue = Gpt_GetTimeElapsed(StbM_GetGptChannelSymbolicNameOfGptClockConfig(StbM_LocalTime_GetGptLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx));

  /* #20 Calculate the delta of the counter value based on the last read value */
  StbM_LocalTime_GetLastClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &lastClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  lastGptCounterValue = lastClockValue.nanoseconds;

  if (lastGptCounterValue <= gptCounterValue)
  {
    elapsedCounterValue = gptCounterValue - lastGptCounterValue;
  }
  else
  {
    elapsedCounterValue = (StbM_GetMaxTickValueOfGptClockConfig(StbM_LocalTime_GetGptLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx) - lastGptCounterValue) + (1u + gptCounterValue);
  }

  /* #30 Update last read counter value to new retrieved value */
  lastClockValue.nanoseconds = gptCounterValue;
  StbM_LocalTime_SetLastClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &lastClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #40 Update and get current elapsed clock value */
  elapsedClockValue.nanoseconds = elapsedCounterValue;
  retVal = StbM_LocalTime_UpdateElapsedClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &elapsedClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR  */

  /* #50 Calculate and set elapsed nanoseconds */
  StbM_LocalTime_CalculateElapsedTimeFromElapsedCounterValue(timeBaseIdx, elapsedTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

  return retVal;
} /* StbM_LocalTime_GetGptElapsedTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_OnUpdateGptVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_OnUpdateGptVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType elapsedTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Retrieve elapsed time from Gpt clock source */
  retVal = StbM_LocalTime_GetGptElapsedTime(timeBaseIdx, &elapsedTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  if (retVal == E_OK)
  {
    /* #20 Update virtual local time */
    retVal = StbM_LocalTime_UpdateVirtualLocalTime(timeBaseIdx, &elapsedTime, partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }

  return retVal;
} /* StbM_LocalTime_OnUpdateGptVirtualLocalTime */
# endif /* (STBM_CONFIG_GPT_CLOCK == STD_ON) */

# if (STBM_CONFIG_ETH_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_InitEthLocalClock
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_InitEthLocalClock(
        uint16 localTimeId,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 If local time has ethernet clock configured: */
#  if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
  if (StbM_GetClockTypeOfLocalClockConfig(StbM_GetLocalClockConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), partitionIdx) == STBM_ETH_LOCALCLOCK_CLOCKTYPEOFLOCALCLOCKCONFIG)
#  endif
  {
    /* #20 Reset last read EthController time to zero */
    StbM_LocalTime_SetLastClockValue(StbM_GetLocalClockConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), &STBM_ZERO_TIME, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #30 If EthController is available: */
    if (StbM_LocalTime_IsEthControllerAvailable(StbM_GetTimeBaseConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), partitionIdx) == TRUE)
    {
      StbM_InternalTimeStampType newEthTimeInternalType = STBM_INIT_TIME_ZERO;

      /* #40 Get the current time of the EthController */
      if (StbM_LocalTime_GetEthCurrentTime(StbM_GetTimeBaseConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), &newEthTimeInternalType, partitionIdx) == TRUE) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      {
        /* #50 Set last read Ethernet time value to current time of Ethernet controller */
        StbM_LocalTime_SetLastClockValue(StbM_GetLocalClockConfigIdxOfLocalTimeConfig(localTimeId, partitionIdx), &newEthTimeInternalType, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      }
    }
  }
} /* StbM_LocalTime_InitEthLocalClock */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetEthLocalClockIdx
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint16, STBM_CODE) StbM_LocalTime_GetEthLocalClockIdx(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* #10 Get index of Ethernet local clock by: timebase -> local time -> local clock -> Ethernet local clock */
  return StbM_GetEthClockConfigIdxOfLocalClockConfig(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx);
} /* StbM_LocalTime_GetEthLocalClockIdx */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetEthTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_GetEthTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) ethernetTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  StbM_InternalTimeStampType newEthTimeInternalType = STBM_INIT_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If Ethernet controller is available and get Ethernet time succeeded: */
  if ((StbM_LocalTime_IsEthControllerAvailable(timeBaseIdx, partitionIdx) == TRUE) && (StbM_LocalTime_GetEthCurrentTime(timeBaseIdx, &newEthTimeInternalType, partitionIdx) == TRUE)) /* PRQA S 3415 */ /* MD_StbM_Rule13.5_3415 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  {
    StbM_InternalTimeStampType oldEthTimeInternalType = STBM_INIT_TIME_ZERO;

    /* #20 Convert retrieved time to nanoseconds and check that new ethernet time is greater or equal than the last read time */
    StbM_LocalTime_GetLastClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &oldEthTimeInternalType, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    retVal = StbM_Calc_InternalTimeStampTypeToVirtualLocalTimeType(&newEthTimeInternalType, ethernetTime); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    if (StbM_Calc_LessThan(&newEthTimeInternalType, &oldEthTimeInternalType) == TRUE) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    {
      retVal = E_NOT_OK;
    }

    /* #30 Overwrite last read time with new one */
    StbM_LocalTime_SetLastClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &newEthTimeInternalType, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }
  return retVal;
} /* StbM_LocalTime_GetEthTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_OnUpdateEthVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_OnUpdateEthVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_SynchronizedTimeBaseType timeBaseId;
  StbM_VirtualLocalTimeType ethernetTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If retrieval of ethernet time succeeded: */
  retVal = StbM_LocalTime_GetEthTime(timeBaseIdx, &ethernetTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  if (retVal == E_OK)
  {
    timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);

    /* #20 Set new virtual local time to ethernet time */
    StbM_SetVirtualLocalTimeOfVirtualLocalTimeState(StbM_GetIndirectionToVirtualLocalTimeStateIdxOfTimeBasePartitionMapping(timeBaseId), ethernetTime, StbM_GetIndirectionToVirtualLocalTimeStatePartitionIdxOfTimeBasePartitionMapping(timeBaseId)); /* SBSW_STBM_ACCESS_VIRTUALLOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING */
  }

  return retVal;
} /* StbM_LocalTime_OnUpdateEthVirtualLocalTime */

/**********************************************************************************************************************
 *  StbM_LocalTime_IsEthControllerAvailable
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_LocalTime_IsEthControllerAvailable(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Eth_ModeType ethIfMode = 0u;
  boolean isAvailable = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call EthIf to get the current mode */
  retVal = EthIf_GetControllerMode(StbM_GetEthIfCtrlIdxOfEthClockConfig(StbM_LocalTime_GetEthLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx), &ethIfMode); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Check if return value is E_OK and the mode is ETH_MODE_ACTIVE */
  if ((retVal == E_OK) && (ethIfMode == ETH_MODE_ACTIVE))
  {
    isAvailable = TRUE;
  }
  
  return isAvailable;
} /* StbM_LocalTime_IsEthControllerAvailable */

/**********************************************************************************************************************
 *  StbM_LocalTime_GetEthCurrentTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_LocalTime_GetEthCurrentTime(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStamp,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  Eth_TimeStampQualType ethIfTimeQual = 0u;
  Eth_TimeStampType ethIfTimeStamp = {0u};
  boolean getSuccessful = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call EthIf to get the current time */
  retVal = EthIf_GetCurrentTime(StbM_GetEthIfCtrlIdxOfEthClockConfig(StbM_LocalTime_GetEthLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx), &ethIfTimeQual, &ethIfTimeStamp); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #20 Extract the time from EthIf time stamp and convert it to the internal time stamp */
  timeStamp->secondsHi = ethIfTimeStamp.secondsHi; /* SBSW_STBM_ACCESS_PARAMPTR */
  timeStamp->seconds = ethIfTimeStamp.seconds; /* SBSW_STBM_ACCESS_PARAMPTR */
  timeStamp->nanoseconds = ethIfTimeStamp.nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #30 Check if the return value is E_Ok and the qualifier is set to ETH_VALID */
  if ((retVal == E_OK) && (ethIfTimeQual == ETH_VALID))
  {
    getSuccessful = TRUE;
  }
  
  return getSuccessful;
} /* StbM_LocalTime_GetEthCurrentTime */
# endif /* (STBM_CONFIG_ETH_CLOCK == STD_ON) */

# if (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_TriggerLocalClockSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(uint8, STBM_CODE) StbM_LocalTime_TriggerLocalClockSync(StbM_SynchronizedTimeBaseType timeBaseIdx, StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_SynchronizedTimeBaseType timeBaseId;
  uint8 ethIfCtrlIdx;
  StbM_TimeStampType tgSync = { 0u, 0u, 0u, 0u };
  StbM_VirtualLocalTimeType tvSync = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_RateDeviationType rateDeviation = 0;
  StbM_TimeDiffType timeLeap;
  StbM_UpdateCounterType updateCounter;
  uint8 clockAdjustment;

  /* ----- Implementation ----------------------------------------------- */
  timeBaseId = StbM_GetTimeBasePartitionMappingIdxOfLocalTimeConfig(StbM_GetLocalTimeConfigIdxOfTimeBaseConfig(timeBaseIdx, partitionIdx), partitionIdx);
  ethIfCtrlIdx = StbM_GetEthIfCtrlIdxOfEthClockConfig(StbM_LocalTime_GetEthLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx);
  /* #10 Trigger local clock synchronization */
  StbM_GlobalTime_OnGetMainTime(timeBaseIdx, &tgSync, &tvSync, &rateDeviation, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  timeLeap = StbM_LocalTime_GetTimeLeap(timeBaseIdx, partitionIdx);
  updateCounter = StbM_TimeBase_GetUpdateCounter(timeBaseIdx, partitionIdx);
  clockAdjustment = StbM_LocalClockSyncCallback(timeBaseId, ethIfCtrlIdx, &tgSync, &tvSync, rateDeviation, timeLeap, updateCounter); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  return clockAdjustment;
} /* StbM_LocalTime_TriggerLocalClockSync */

/**********************************************************************************************************************
 *  StbM_LocalTime_HandleLocalClockSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_LocalTime_HandleLocalClockSync(StbM_SynchronizedTimeBaseType timeBaseIdx, StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 clockAdjustment;
  uint16 localClockIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Update the local time for all timebases */
  StbM_LocalTime_UpdateLocalTime(partitionIdx);

  /* #20 Trigger local clock synchronization */
  clockAdjustment = StbM_LocalTime_TriggerLocalClockSync(timeBaseIdx, partitionIdx);

  /* #30 If local clock was adjusted: */
  if (clockAdjustment != STBM_NONE_CLOCK_ADJUSTMENT)
  {
    uint16 ethClockIdx = StbM_LocalTime_GetEthLocalClockIdx(timeBaseIdx, partitionIdx);

    /* #40 For all time bases with the same local clock: */
    for (localClockIdx = 0u; localClockIdx < StbM_GetSizeOfLocalClockConfig(partitionIdx); localClockIdx++)
    {
      if (ethClockIdx == StbM_GetEthClockConfigIdxOfLocalClockConfig(localClockIdx, partitionIdx))
      {
        StbM_InternalTimeStampType globalTimeSync = STBM_INIT_TIME_ZERO;
        StbM_VirtualLocalTimeType virtualLocalTimeSync = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
        StbM_SynchronizedTimeBaseType currentTimeBaseIdx = StbM_GetIndirectionToTimeBaseConfigIdxOfTimeBasePartitionMapping(StbM_GetTimeBasePartitionMappingIdxOfLocalClockConfig(localClockIdx, partitionIdx));

        /* #50 If not current time base with already updated MainTimeTuple: */
        if (timeBaseIdx != currentTimeBaseIdx)
        {
          StbM_InternalTimeStampType localTime = STBM_INIT_TIME_ZERO;

          /* #60 If retrieval of current time succeeded: */
          if (StbM_LocalTime_GetLastUpdatedLocalTime(currentTimeBaseIdx, &localTime, partitionIdx) == E_OK) /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
          {
            /* #70 Update TGsync */
            StbM_LocalTime_SetGlobalTimeSync(currentTimeBaseIdx, &localTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
          }
        }

        /* #80 Update TVsync */
        StbM_LocalTime_GetGlobalTimeSync(currentTimeBaseIdx, &globalTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
        if (StbM_Calc_InternalTimeStampTypeToVirtualLocalTimeType(&globalTimeSync, &virtualLocalTimeSync) == E_OK) /* PRQA S 2991, 2995 */ /* MD_StbM_Rule14.3_2991, MD_StbM_Rule2.2_2995 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
        {
          StbM_LocalTime_SetVirtualLocalTimeSync(currentTimeBaseIdx, &virtualLocalTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
        }

        /* #90 Overwrite last read Eth time with new synchronized time */
        StbM_LocalTime_SetLastClockValue(localClockIdx, &globalTimeSync, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

#  if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON))
        /* #100 Reset rate */
        StbM_TimeCorrection_ResetRate(currentTimeBaseIdx, partitionIdx);
#  endif

#  if (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON)
        /* #110 If major adjustment and timebase has time correction for slave configured: */
        if ((clockAdjustment == STBM_MAJOR_CLOCK_ADJUSTMENT) && (StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured(currentTimeBaseIdx, partitionIdx) == TRUE))
        {
          /* #120 Stop invalid rate measurements */
          StbM_TimeCorrection_StopRateMeasurement(currentTimeBaseIdx, partitionIdx);
          /* #130 Start new rate measurement */
          StbM_TimeCorrection_StartNewRateMeasurement(currentTimeBaseIdx, partitionIdx);
        }
#  endif
      }
    }
  }
} /* StbM_LocalTime_HandleLocalClockSync */ /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
# endif /* (STBM_USE_SYNCHRONIZED_LOCAL_CLOCK == STD_ON) */

# if (STBM_CONFIG_TIME_RECORDING == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_GetVirtualLocalTimeLow
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(uint32, STBM_CODE) StbM_LocalTime_GetVirtualLocalTimeLow(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get virtual local time low */
  StbM_LocalTime_GetVirtualLocalTime(timeBaseIdx, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  return virtualLocalTime.nanosecondsLo;
} /* StbM_LocalTime_GetVirtualLocalTimeLow */
# endif /* (STBM_CONFIG_TIME_RECORDING == STD_ON) */

# if ((STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_LocalTime_CalculateElapsedTimeFromElapsedCounterValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_LocalTime_CalculateElapsedTimeFromElapsedCounterValue(
        StbM_SynchronizedTimeBaseType timeBaseIdx,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) elapsedTime,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_InternalTimeStampType elapsedClockValue = STBM_INIT_CLOCK_ZERO;
  uint64 elapsedTimeInNs;

  /* ----- Implementation ----------------------------------------------- */
  StbM_LocalTime_GetElapsedClockValue(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), &elapsedClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* #10 Convert the elapsed ticks into nanoseconds */
  elapsedTimeInNs = ((uint64)elapsedClockValue.nanoseconds) * ((uint64)StbM_GetNumeratorOfFactorClockTicksToLocalTimeOfLocalClockConfig(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx))
                    / ((uint64)StbM_GetDenominatorOfFactorClockTicksToLocalTimeOfLocalClockConfig(StbM_LocalTime_GetLocalClockIdx(timeBaseIdx, partitionIdx), partitionIdx)); /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #20 Convert the nanoseconds into virtual local time type */
  elapsedTime->nanosecondsLo = (uint32)(elapsedTimeInNs & 0x00000000FFFFFFFFuL); /* SBSW_STBM_ACCESS_PARAMPTR */
  elapsedTime->nanosecondsHi = (uint32)(elapsedTimeInNs >> 32u); /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_LocalTime_CalculateElapsedTimeFromElapsedCounterValue */
# endif /* STBM_EXISTS_OS_LOCALCLOCK_CLOCKTYPEOFLOCALTIMECONFIG || STBM_EXISTS_GPT_LOCALCLOCK_CLOCKTYPEOFLOCALTIMECONFIG */

# if (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_LocalTime_CloneTimeValue
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_LocalTime_CloneTimeValue(
        StbM_SynchronizedTimeBaseType sourceTimeBaseIdx,
        StbM_SynchronizedTimeBaseType destinationTimeBaseIdx,
        StbM_PartitionIdentifiersIterType partitionIdx)
{
  Std_ReturnType retVal;

  StbM_VirtualLocalTimeType TVSource = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_VirtualLocalTimeType TVDestination = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
  StbM_InternalTimeStampType TLSource = STBM_INIT_TIME_ZERO;

  /* #10 If timeBases use different time source, get current virtual local time of time bases and replace main time tuple */
  if (StbM_IsDifferentLocalClockSourceForCloningOfTimeBaseConfig(destinationTimeBaseIdx, partitionIdx))
  {
    StbM_EnterCritical_Get_TS();
    retVal = StbM_LocalTime_OnGetCurrentVirtualLocalTime(sourceTimeBaseIdx, &TVSource, partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    retVal |= StbM_LocalTime_OnGetCurrentVirtualLocalTime(destinationTimeBaseIdx, &TVDestination, partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    retVal |= StbM_LocalTime_GetLocalTime(sourceTimeBaseIdx, &TVSource, &TLSource, partitionIdx); /* PRQA S 2985 */ /* MD_StbM_Rule2.2_2985 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LeaveCritical_Get_TS();

    StbM_LocalTime_UpdateMainTimeTuple(destinationTimeBaseIdx, &TLSource, &TVDestination, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  }
  else
  {
    StbM_InternalTimeStampType lastClockValue, elapsedClockValue = STBM_INIT_CLOCK_ZERO;

    /* #20 Otherwise copy main time tuple, last value and elapsed value of local clock */
    StbM_LocalTime_GetGlobalTimeSync(sourceTimeBaseIdx, &TLSource, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LocalTime_GetVirtualLocalTimeSync(sourceTimeBaseIdx, &TVSource, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LocalTime_UpdateMainTimeTuple(destinationTimeBaseIdx, &TLSource,  &TVSource, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LocalTime_GetLastClockValue(StbM_LocalTime_GetLocalClockIdx(sourceTimeBaseIdx, partitionIdx), &lastClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LocalTime_SetLastClockValue(StbM_LocalTime_GetLocalClockIdx(destinationTimeBaseIdx, partitionIdx), &lastClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LocalTime_GetElapsedClockValue(StbM_LocalTime_GetLocalClockIdx(sourceTimeBaseIdx, partitionIdx), &elapsedClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_LocalTime_SetElapsedClockValue(StbM_LocalTime_GetLocalClockIdx(destinationTimeBaseIdx, partitionIdx), &elapsedClockValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    retVal = E_OK;
  }

  return retVal;
} /* StbM_LocalTime_CloneTimeValue */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* STBM_CONFIG_SOURCE_TIMEBASE == STD_ON */
#endif /* STBM_NOUNIT_LOCALTIME */

#ifndef STBM_NOUNIT_CALC /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  Unit: Calc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StbM_Calc_AddTimeStamps
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_AddTimeStamps(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) sum)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the two timestamps */
  sum->nanoseconds = lhs->nanoseconds + rhs->nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */
  sum->seconds = lhs->seconds + rhs->seconds; /* SBSW_STBM_ACCESS_PARAMPTR */
  sum->secondsHi = lhs->secondsHi + rhs->secondsHi; /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #20 Check for overflow of nanoseconds */
  /* no real overflow of nanoseconds possible, since max value is 10^9 - 1 */
  if (sum->nanoseconds > STBM_TIMESTAMP_MAX_NANOSECONDS)
  {
    sum->seconds++; /* SBSW_STBM_ACCESS_PARAMPTR */
    sum->nanoseconds -= STBM_NANOSECONDS_IN_ONE_SECOND; /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  /* #30 Check for overflow of seconds */
  if (sum->seconds < (lhs->seconds | rhs->seconds))
  {
    sum->secondsHi++; /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  /* #40 Check for overflow of seconds high */
  /* calculated sum is invalid, if overflow of secondsHi occurred */
  if ((sum->secondsHi >= lhs->secondsHi) && (sum->secondsHi >= rhs->secondsHi))
  {
    retVal = E_OK;
  }

  return retVal;
} /* StbM_Calc_AddTimeStamps */

# if ((STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TIME_NOTIFICATION == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_SubtractTimeStamps
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_SubtractTimeStamps(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) difference)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) left;
  P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) right;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If left < right, swap operands */
  if (StbM_Calc_LessThan(lhs, rhs) == TRUE) /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  {
    left = rhs;
    right = lhs;
    retVal = E_NOT_OK;
  }
  else
  {
    left = lhs;
    right = rhs;
    retVal = E_OK;
  }

  /* #20 Calculate time difference */
  difference->secondsHi = left->secondsHi - right->secondsHi; /* SBSW_STBM_ACCESS_PARAMPTR */
  difference->seconds = left->seconds - right->seconds; /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #30 Check for underflow of seconds */
  if (left->seconds < right->seconds)
  {
    difference->secondsHi--; /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  /* #40 Check for underflow of nanoseconds */
  if (left->nanoseconds < right->nanoseconds)
  {
    difference->seconds--; /* SBSW_STBM_ACCESS_PARAMPTR */

    /* #50 Check for underflow of seconds */
    if (difference->seconds == STBM_TIMESTAMP_MAX_SECONDS)
    {
      difference->secondsHi--; /* SBSW_STBM_ACCESS_PARAMPTR */
    }

    difference->nanoseconds = (STBM_TIMESTAMP_MAX_NANOSECONDS - right->nanoseconds) + (1u + left->nanoseconds); /* SBSW_STBM_ACCESS_PARAMPTR */
  }
  else
  {
    difference->nanoseconds = left->nanoseconds - right->nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  return retVal;
} /* StbM_Calc_SubtractTimeStamps */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) */

# if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_AddVirtualLocalTimes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_AddVirtualLocalTimes(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) sum)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the two virtual local times */
  sum->nanosecondsLo = lhs->nanosecondsLo + rhs->nanosecondsLo; /* SBSW_STBM_ACCESS_PARAMPTR */
  sum->nanosecondsHi = lhs->nanosecondsHi + rhs->nanosecondsHi; /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #20 Check for overflow of nanoseconds low */
  if (sum->nanosecondsLo < (lhs->nanosecondsLo | rhs->nanosecondsLo))
  {
    sum->nanosecondsHi++; /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  /* #30 Check for overflow of nanoseconds high */
  /* calculated sum is invalid, if overflow of nanosecondsHi occurred */
  if ((sum->nanosecondsHi >= lhs->nanosecondsHi) && (sum->nanosecondsHi >= rhs->nanosecondsHi))
  {
    retVal = E_OK;
  }

  return retVal;
} /* StbM_Calc_AddVirtualLocalTimes */
# endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_OS_CLOCK == STD_ON) || (STBM_CONFIG_GPT_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_SubtractVirtualLocalTimes
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
STBM_LOCAL FUNC(void, STBM_CODE) StbM_Calc_SubtractVirtualLocalTimes(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) difference)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate time difference */
  difference->nanosecondsHi = lhs->nanosecondsHi - rhs->nanosecondsHi; /* SBSW_STBM_ACCESS_PARAMPTR */
  difference->nanosecondsLo = lhs->nanosecondsLo - rhs->nanosecondsLo; /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #20 Check for underflow of nanoseconds low */
  if (lhs->nanosecondsLo < rhs->nanosecondsLo)
  {
    difference->nanosecondsHi--; /* SBSW_STBM_ACCESS_PARAMPTR */
  }
} /* StbM_Calc_SubtractVirtualLocalTimes */

# if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_MultiplyTimeStampWithRate
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_MultiplyTimeStampWithRate(
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStamp,
        StbM_InternalRateType rate)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_OK;
  float64 nanoseconds;
  float64 seconds;
  float64 secondsHi;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Multiply nanoseconds with rate */
  nanoseconds = (float64)timeStamp->nanoseconds * rate;

  /* #20 Multiply seconds with rate */
  seconds = (float64)timeStamp->seconds * rate;

  /* #30 Multiply secondsHi with rate */
  secondsHi = (float64)timeStamp->secondsHi * rate;

  /* #40 If secondsHi overflows, return E_NOT_OK */
  if ((secondsHi + (seconds / STBM_SECONDS_IN_ONE_SECONDHI_DOUBLE)) > STBM_TIMESTAMP_MAX_SECONDSHI_DOUBLE)
  {
    retVal = E_NOT_OK;
  }

  /* #50 If rate is not integer number, get the not integer part and add it to the nanoseconds */
  if (seconds > StbM_iPart(seconds))
  {
    nanoseconds += StbM_fPart(seconds) * STBM_NANOSECONDS_IN_ONE_SECOND_DOUBLE;
    seconds -= StbM_fPart(seconds);
  }

  /* #60 Convert result to internal timestamp part */
  timeStamp->nanoseconds = (StbM_NanosecondsType)(nanoseconds - (STBM_NANOSECONDS_IN_ONE_SECOND_DOUBLE * StbM_iPart(nanoseconds / STBM_NANOSECONDS_IN_ONE_SECOND_DOUBLE))); /* PRQA S 4395 */ /* MD_StbM_Rule10.8_4395 */ /* SBSW_STBM_ACCESS_PARAMPTR */
  timeStamp->seconds = (StbM_SecondsType)(seconds - (STBM_SECONDS_IN_ONE_SECONDHI_DOUBLE * StbM_iPart(seconds / STBM_SECONDS_IN_ONE_SECONDHI_DOUBLE))) + (StbM_SecondsType)(nanoseconds / STBM_NANOSECONDS_IN_ONE_SECOND_DOUBLE); /* PRQA S 4395 */ /* MD_StbM_Rule10.8_4395 */ /* SBSW_STBM_ACCESS_PARAMPTR */
  timeStamp->secondsHi = (StbM_SecondsHiType)secondsHi + (StbM_SecondsHiType)(seconds / STBM_SECONDS_IN_ONE_SECONDHI_DOUBLE); /* PRQA S 4395 */ /* MD_StbM_Rule10.8_4395 */ /* SBSW_STBM_ACCESS_PARAMPTR */

  return retVal;
} /* StbM_Calc_MultiplyTimeStampWithRate */
# endif /* ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)) */

# if ((STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_EqualThan
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Calc_EqualThan(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs)
{
  /* ----- Implementation ----------------------------------------------- */
  boolean equalThan = FALSE;

  /* #10 True if left == right */
  if ((lhs->secondsHi == rhs->secondsHi) && (lhs->seconds == rhs->seconds) && (lhs->nanoseconds == rhs->nanoseconds))
  {
    equalThan = TRUE;
  }

  return equalThan;
} /* StbM_Calc_EqualThan */
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_LessThan
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Calc_LessThan(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs)
{
  boolean lessThan = FALSE;

  /* #10 True if left < right */
  if ((lhs->secondsHi < rhs->secondsHi)
                || ((lhs->secondsHi == rhs->secondsHi) && (lhs->seconds < rhs->seconds))
                || ((lhs->secondsHi == rhs->secondsHi) && (lhs->seconds == rhs->seconds) && (lhs->nanoseconds < rhs->nanoseconds)))
  {
    lessThan = TRUE;
  }

  return lessThan;
} /* StbM_Calc_LessThan */

/**********************************************************************************************************************
 *  StbM_Calc_EqualThan_VirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(boolean, STBM_CODE) StbM_Calc_EqualThan_VirtualLocalTime(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs)
{
  /* ----- Implementation ----------------------------------------------- */
  boolean equalThan = FALSE;

  /* #10 True if left == right */
  if ((lhs->nanosecondsHi == rhs->nanosecondsHi) && (lhs->nanosecondsLo == rhs->nanosecondsLo))
  {
    equalThan = TRUE;
  }

  return equalThan;	
} /* StbM_Calc_EqualThan_VirtualLocalTime */

/**********************************************************************************************************************
 *  StbM_Calc_LessThan_VirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Calc_LessThan_VirtualLocalTime(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs)
{
  boolean lessThan = FALSE;

  /* #10 True if left < right */
  if ((lhs->nanosecondsHi < rhs->nanosecondsHi)
                || ((lhs->nanosecondsHi == rhs->nanosecondsHi) && (lhs->nanosecondsLo < rhs->nanosecondsLo)))
  {
    lessThan = TRUE;
  }
  
  return lessThan;
} /* StbM_Calc_LessThan_VirtualLocalTime */

# if ((STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_LessEqualThan
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Calc_LessEqualThan(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) rhs)
{
  /* ----- Implementation ----------------------------------------------- */
  boolean lessEqualThan = FALSE;

  /* #10 True if left <= right */
  if ((StbM_Calc_LessThan(lhs, rhs) == TRUE) || (StbM_Calc_EqualThan(lhs, rhs) == TRUE)) /* PRQA S 3415 */ /* MD_StbM_Rule13.5_3415 */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  {
    lessEqualThan = TRUE;
  }
  
  return lessEqualThan;
} /* StbM_Calc_LessEqualThan */
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_LessEqualThan_VirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(boolean, STBM_CODE) StbM_Calc_LessEqualThan_VirtualLocalTime(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) lhs,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) rhs)
{
  /* ----- Implementation ----------------------------------------------- */
  boolean lessEqualThan = FALSE;

  /* #10 True if left <= right */
  if ((StbM_Calc_LessThan_VirtualLocalTime(lhs, rhs) == TRUE) || (StbM_Calc_EqualThan_VirtualLocalTime(lhs, rhs) == TRUE)) /* PRQA S 3415 */ /* MD_StbM_Rule13.5_3415 */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */
  {
    lessEqualThan = TRUE;
  }
  
  return lessEqualThan;
} /* StbM_Calc_LessEqualThan_VirtualLocalTime */

# if ((STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_ToNanoseconds
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_ToNanoseconds(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStamp,
        P2VAR(uint32, AUTOMATIC, STBM_APPL_VAR) nanoseconds)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  StbM_InternalTimeStampType maxNanoseconds = {294967295u, 4u, 0u};

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert given timestamp into nanoseconds */
  if (StbM_Calc_LessEqualThan(timeStamp, &maxNanoseconds) == TRUE) /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  {
    *nanoseconds = ((timeStamp->seconds) * STBM_NANOSECONDS_IN_ONE_SECOND) + timeStamp->nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */
    retVal = E_OK;
  }
  return retVal;
} /* StbM_Calc_ToNanoseconds */
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) || (STBM_CONFIG_TIME_SLAVE == STD_ON) */

# if ((STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON))
/**********************************************************************************************************************
 *  StbM_Calc_ToNanoseconds_Uint64
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_ToNanoseconds_Uint64(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStamp,
        P2VAR(uint64, AUTOMATIC, STBM_APPL_VAR) nanoseconds)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  StbM_InternalTimeStampType maxNanoseconds = {709551615u, 1266874889u, 4u}; /* max nanoseconds in uint64 = 18446744073709551615 */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert given timestamp into nanoseconds */
  if (StbM_Calc_LessEqualThan(timeStamp, &maxNanoseconds) == TRUE) /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
  {
    *nanoseconds = ((((uint64)timeStamp->seconds) | ((uint64)timeStamp->secondsHi << 32u)) * (uint64)STBM_NANOSECONDS_IN_ONE_SECOND) + (uint64)timeStamp->nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */
    retVal = E_OK;
  }
  return retVal;
} /* StbM_Calc_ToNanoseconds_Uint64 */
# endif /* (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_ETH_CLOCK == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_ToNanoseconds_Uint64_VirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Calc_ToNanoseconds_Uint64_VirtualLocalTime(
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) virtualLocalTime,
        P2VAR(uint64, AUTOMATIC, STBM_APPL_VAR) nanoseconds)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert given virtual local time into nanoseconds */
    *nanoseconds = (((uint64)virtualLocalTime->nanosecondsHi) << 32u) + virtualLocalTime->nanosecondsLo; /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_Calc_ToNanoseconds_Uint64_VirtualLocalTime */

# if (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON)
/**********************************************************************************************************************
 *  StbM_Calc_ToMicroseconds
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(StbM_MicrosecondType, STBM_CODE) StbM_Calc_ToMicroseconds(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStamp)
{
  /* #10 Convert into microseconds by: seconds * 1000000 + nanoseconds / 1000 */
  return (((((StbM_MicrosecondType)timeStamp->secondsHi) << 32u) | (StbM_MicrosecondType)timeStamp->seconds) * (StbM_MicrosecondType)STBM_MICROSECOND_IN_ONE_SECOND)
            + ((StbM_MicrosecondType)timeStamp->nanoseconds / (StbM_MicrosecondType)STBM_NANOSECONDS_IN_ONE_MICROSECOND);
} /* StbM_Calc_ToMicroseconds */
# endif /* (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_Calc_ToInternalTimeStampType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Calc_ToInternalTimeStampType(
        P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) fromTimeStamp,
        P2VAR(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_VAR) toTimeStamp)
{
  /* #10 Convert AUTOSAR timestamp to internal timestamp */
  toTimeStamp->nanoseconds = fromTimeStamp->nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */
  toTimeStamp->seconds = fromTimeStamp->seconds; /* SBSW_STBM_ACCESS_PARAMPTR */
  toTimeStamp->secondsHi = fromTimeStamp->secondsHi; /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_Calc_ToInternalTimeStampType */

/**********************************************************************************************************************
 *  StbM_Calc_ToStbMTimeStampType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Calc_ToStbMTimeStampType(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) fromTimeStamp,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) toTimeStamp)
{
  /* #10 Convert internal timestamp to AUTOSAR timestamp */
  toTimeStamp->secondsHi = fromTimeStamp->secondsHi; /* SBSW_STBM_ACCESS_PARAMPTR */
  toTimeStamp->seconds = fromTimeStamp->seconds; /* SBSW_STBM_ACCESS_PARAMPTR */
  toTimeStamp->nanoseconds = fromTimeStamp->nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */
} /* StbM_Calc_ToStbMTimeStampType */

# if (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON)
/**********************************************************************************************************************
 *  StbM_Calc_ToStbMTimeStampExtendedType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
STBM_LOCAL_INLINE FUNC(void, STBM_CODE) StbM_Calc_ToStbMTimeStampExtendedType(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA)fromTimeStamp,
        P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_DATA)toTimeStamp)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the nanoseconds */
  toTimeStamp->nanoseconds = fromTimeStamp->nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #20 Set the first 32 bits of seconds of the 'from' (0-31) to the first 32 bit of the 'to' */
  toTimeStamp->seconds = fromTimeStamp->seconds; /* SBSW_STBM_ACCESS_PARAMPTR */

  /* #30 Set secondsHi of 'from' to the (32-47) bit of the seconds of the 'to' */
  toTimeStamp->seconds |= (((uint64)fromTimeStamp->secondsHi) << 32u); /* SBSW_STBM_ACCESS_PARAMPTR */

} /* StbM_Calc_ToStbMTimeStampExtendedType */
# endif /* (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON) */

# if (STBM_CONFIG_ETH_CLOCK == STD_ON)
/**********************************************************************************************************************
 *  StbM_Calc_InternalTimeStampTypeToVirtualLocalTimeType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
STBM_LOCAL_INLINE FUNC(Std_ReturnType, STBM_CODE) StbM_Calc_InternalTimeStampTypeToVirtualLocalTimeType(
        P2CONST(StbM_InternalTimeStampType, AUTOMATIC, STBM_APPL_DATA) fromTimeStamp,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) toTimeStamp)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint64 nanoseconds = 0u;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert internal timestamp to virtual local time */
  retVal = StbM_Calc_ToNanoseconds_Uint64(fromTimeStamp, &nanoseconds); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  if (retVal == E_OK)
  {
    toTimeStamp->nanosecondsLo = (uint32)nanoseconds; /* SBSW_STBM_ACCESS_PARAMPTR */
    toTimeStamp->nanosecondsHi = (uint32)(nanoseconds >> 32u); /* SBSW_STBM_ACCESS_PARAMPTR */
  }

  return retVal;
} /* StbM_Calc_InternalTimeStampTypeToVirtualLocalTimeType */
# endif /* (STBM_CONFIG_ETH_CLOCK == STD_ON) */
#endif /* STBM_NOUNIT_CALC */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#ifndef STBM_NOUNIT_COMMON /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  StbM_InitMemory
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, STBM_CODE) StbM_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set module pre initialization state to false */
  StbM_PreInitialized = FALSE;

  /* #20 Set module post initialization state to false */
  StbM_PostInitialized = FALSE;

# if (STBM_USE_INIT_POINTER == STD_ON) /* COV_STBM_POSTBUILD_SWITCH */
  /* #30 Set the local configuration pointer to NULL_PTR */
  StbM_ConfigDataPtr = NULL_PTR;
# endif
} /* StbM_InitMemory */

/**********************************************************************************************************************
 *  StbM_PreInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, STBM_CODE) StbM_PreInit(P2CONST(StbM_ConfigType, AUTOMATIC, STBM_INIT_DATA) ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_PartitionIdentifiersIterType partitionIdentifiersIdx;
# if (STBM_CONFIG_GPT_CLOCK == STD_ON)
  uint16 gptClockIdx;
# endif

# if (STBM_USE_INIT_POINTER == STD_ON)
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Store configuration pointer */
  StbM_ConfigDataPtr = ConfigPtr;

  /* #20 If configuration pointer is NULL: */
  if (StbM_ConfigDataPtr == NULL_PTR)
  {
#  if(STBM_USE_ECUM_BSW_ERROR_HOOK == STD_ON) /* COV_STBM_POSTBUILD_SWITCH */
    /* #30 Report error to EcuM as ECUM_BSWERROR_NULLPTR */
    EcuM_BswErrorHook(STBM_MODULE_ID, ECUM_BSWERROR_NULLPTR);
#  endif
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
    /* #40 Set Dev error id to STBM_E_INIT_FAILED */
    errorId = STBM_E_INIT_FAILED;
#  endif
  }
  /* #50 If hash code is not valid: */
#  if(STBM_USE_ECUM_BSW_ERROR_HOOK == STD_ON)/* COV_STBM_POSTBUILD_SWITCH */
  else if (StbM_GetInitDataHashCode() != STBM_INIT_DATA_HASH_CODE)
  {
    /* #60 Report error to EcuM as ECUM_BSWERROR_MAGICNUMBER */
    EcuM_BswErrorHook(STBM_MODULE_ID, ECUM_BSWERROR_MAGICNUMBER);
#   if (STBM_DEV_ERROR_DETECT == STD_ON)
    /* #70 Set Dev error id to STBM_E_INIT_FAILED */
    errorId = STBM_E_INIT_FAILED;
#   endif
  }
#  endif
  else
# else
  STBM_DUMMY_STATEMENT(ConfigPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* STBM_USE_INIT_POINTER == STD_ON */
  {
# if (STBM_CONFIG_GPT_CLOCK == STD_ON)
    /* #80 If StbM is not yet initialized (Gpt should not be re-initialized): */
    if (StbM_PreInitialized == FALSE)
    {
      /* #90 For each configured Gpt local clock: */
      for (gptClockIdx = 0u; gptClockIdx < StbM_GetSizeOfGptClockState(StbM_PartitionIndexOfCSLForCommonSharedMemory); gptClockIdx++)
      {
        /* #100 Set Gpt channel inactive */
        StbM_SetGptChannelActiveOfGptClockState(gptClockIdx, FALSE, StbM_PartitionIndexOfCSLForCommonSharedMemory); /* SBSW_STBM_ACCESS_GPTCLOCKSTATE */
      }
    }
# endif

    /* #110 Initialize all partition specific initialized flags to FALSE */
    for (partitionIdentifiersIdx = 0u; partitionIdentifiersIdx < StbM_GetSizeOfPartitionIdentifiers(); partitionIdentifiersIdx++)
    {
      StbM_SetInitialized(FALSE, partitionIdentifiersIdx); /* SBSW_STBM_ACCESS_CSL_VAR */
    }

    /* #120 Set pre initialized state of component to TRUE */
    StbM_PreInitialized = TRUE;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_USE_INIT_POINTER == STD_ON)
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    StbM_ReportError(STBM_SID_PRE_INIT, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
# endif /* STBM_USE_INIT_POINTER == STD_ON */
} /* StbM_PreInit */

/***********************************************************************************************************************
 *  StbM_Init
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(void, STBM_CODE) StbM_Init(P2CONST(StbM_ConfigType, AUTOMATIC, STBM_INIT_DATA) ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = STBM_E_NO_ERROR;
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  Std_ReturnType retVal = E_OK;
# endif

  /* ----- Implementation ----------------------------------------------- */
  STBM_DUMMY_STATEMENT(ConfigPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* #10 Check if component is already pre initialized */
  if (StbM_IsPreInitialized())
  {
    StbM_PartitionIdentifiersIterType partitionIdx;

# if (STBM_MULTIPARTITION_USED == STD_ON)
    ApplicationType osAppId;

    /* #20 Get current partition index by os application id: */
    osAppId = GetApplicationID();

    partitionIdx = StbM_Common_GetCurrentPartitionIndexByOsApplication(osAppId);

    if (partitionIdx < StbM_GetSizeOfPartitionIdentifiers())
# else
    /* in a not multipartition configuration the partition is always 0. */
    partitionIdx = 0u;
# endif
    {

      /* #30 Init TimeBase */
      StbM_TimeBase_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */

      /* #40 Init LocalTime */
      StbM_LocalTime_Init(partitionIdx);

      /* #50 Init Status */
      StbM_Status_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */

# if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON))
      /* #60 Init TimeCorrection */
      StbM_TimeCorrection_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
# endif

      /* #70 Init UserData */
      StbM_UserData_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */

# if (STBM_CONFIG_TIMEOUT == STD_ON)
      /* #80 Init Timeout */
      StbM_Timeout_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
# endif

# if (STBM_CONFIG_TIME_LEAP == STD_ON)
      /* #90 Init TimeLeap */
      StbM_TimeLeap_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
# endif

# if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
      /* #100 Init StatusNotification and store the return value */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
      retVal |= StbM_StatusNotification_Init(partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */
#  else
      (void)StbM_StatusNotification_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
#  endif
# endif

# if (STBM_CONFIG_TIME_RECORDING == STD_ON)
      /* #110 Init TimeRecording and store the return value */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
      retVal |= StbM_TimeRecording_Init(partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */
#  else
      (void)StbM_TimeRecording_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
#  endif
# endif

# if (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON)
      /* #120 Init TriggeredCustomer */
      StbM_TriggeredCustomer_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
# endif

# if (STBM_CONFIG_TIME_NOTIFICATION == STD_ON)
      /* #130 Init TimeNotification and store the return value */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
      retVal |= StbM_TimeNotification_Init(partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */
#  else
      (void)StbM_TimeNotification_Init(partitionIdx);
#  endif
# endif

# if (STBM_CONFIG_TIME_VALIDATION == STD_ON)
      /* #140 Init TimeValidation and store the return value */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
      retVal |= StbM_TimeValidation_Init(partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */
#  else
      (void)StbM_TimeValidation_Init(partitionIdx); /* PRQA S 2987 */ /* MD_StbM_Rule2.2_2987 */
#  endif
# endif

# if ((STBM_CONFIG_SOURCE_TIMEBASE == STD_ON) && (STBM_CONFIG_TIME_SLAVE == STD_ON))
      /* #150 Init clone requests */
      StbM_CloneTime_InitCloneRequestState(partitionIdx);
#  endif

# if (STBM_DEV_ERROR_DETECT == STD_ON)
      /* #160 Set partition specific initialized flag to TRUE, if initialization succeeded */
      StbM_SetInitialized(retVal == E_OK, partitionIdx); /* SBSW_STBM_ACCESS_CSL_VAR */ /* PRQA S 2995 */ /* MD_StbM_Rule2.2_2995 */ /* COV_STBM_SETINITIALIZED_TX */
# endif
    }
# if ((STBM_MULTIPARTITION_USED == STD_ON) && (STBM_DEV_ERROR_DETECT == STD_ON)) /* COV_STBM_DEV_ERROR_DETECT_TF_tf_tx */
    else
    {
      errorId = STBM_E_INIT_FAILED;
    }
# endif
  }
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  else
  {
    errorId = STBM_E_INIT_FAILED;
  }
# endif

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  /* #170 If any dev error occurred, report it using Det */
  if (errorId != STBM_E_NO_ERROR)
  {
    StbM_ReportError(STBM_SID_INIT, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* StbM_Init */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_PostInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, STBM_CODE) StbM_PostInit(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = STBM_E_NO_ERROR;
  boolean initialized = TRUE;
  StbM_PartitionIdentifiersIterType partitionIdentifiersIdx;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if component is pre initialized */
  if (StbM_IsPreInitialized() == FALSE)
  {
    errorId = STBM_E_INIT_FAILED;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Check if every partition is initialized */
    for (partitionIdentifiersIdx = 0u; partitionIdentifiersIdx < StbM_GetSizeOfPartitionIdentifiers(); partitionIdentifiersIdx++)
    {
      if ((StbM_IsInitialized(partitionIdentifiersIdx) == FALSE)
# if (STBM_MULTIPARTITION_USED == STD_ON)
		  && (StbM_GetPartitionSNVOfPartitionIdentifiers(partitionIdentifiersIdx) != INVALID_OSAPPLICATION)
# endif
         )
      {
        initialized = FALSE;
# if (STBM_DEV_ERROR_DETECT == STD_ON)
        errorId = STBM_E_INIT_FAILED;
# endif
        break;
      }
    }

    /* #30 Set post initialized state of component */
    StbM_PostInitialized = initialized;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  /* #40 If any dev error occurred, report it using Det */
  if (errorId != STBM_E_NO_ERROR)
  {
    StbM_ReportError(STBM_SID_POST_INIT, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* StbM_PostInit */

/**********************************************************************************************************************
 *  StbM_MainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080, 6050 4 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
# if (STBM_MULTIPARTITION_USED == STD_ON)
FUNC(void, STBM_CODE) StbM_MainFunction(StbM_PartitionIdentifiersIterType partitionIndex)
# else
FUNC(void, STBM_CODE) StbM_MainFunction(void)
# endif
{
  /* ----- Local Variables ---------------------------------------------- */
# if (STBM_MULTIPARTITION_USED == STD_OFF)
  StbM_PartitionIdentifiersIterType partitionIndex = 0u;
# endif

  /* ----- Implementation ----------------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check If module is initialized */
  if (StbM_IsPostInitialized())
  {
# endif

    /* #20 Update timeout */
# if (STBM_CONFIG_TIMEOUT == STD_ON)
    StbM_Timeout_Update(partitionIndex);
# endif

    /* #30 Update time recording */
# if (STBM_CONFIG_TIME_RECORDING == STD_ON)
    StbM_TimeRecording_NotifyCustomers(partitionIndex);
# endif

    /* #40 Update time validation */
# if (STBM_CONFIG_TIME_VALIDATION == STD_ON)
    StbM_TimeValidation_NotifyCustomers(partitionIndex);
# endif

    /* #50 Enter exclusive area to calculate local time which is re-used in StbM_TimeNotification_Update and StbM_TriggeredCustomer_Update */
    StbM_EnterCritical_CrossCore();

    /* #60 Update the local time for all timebases */
    StbM_LocalTime_UpdateLocalTime(partitionIndex);

    /* #70 Update main time tuple if timeout occurred */
    StbM_LocalTime_UpdateAfterMainTimeTupleTimeout(partitionIndex); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #80 Update time notification customer */
# if (STBM_CONFIG_TIME_NOTIFICATION == STD_ON)
    StbM_TimeNotification_Update();
# endif

    /* #90 Trigger customers */
# if (STBM_CONFIG_TRIGGERED_CUSTOMER == STD_ON)
    StbM_TriggeredCustomer_Update(partitionIndex);
# endif

    /* #100 Exit exclusive area */
    StbM_LeaveCritical_CrossCore();

    /* #110 Notify status notification customers */
# if (STBM_CONFIG_STATUS_NOTIFICATION == STD_ON)
    StbM_StatusNotification_NotifyCustomers(partitionIndex);
# endif

# if (STBM_DEV_ERROR_DETECT == STD_ON)
  }
# endif
} /* StbM_MainFunction */ /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */

# if (STBM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetVersionInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, STBM_CODE) StbM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, STBM_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check version info for NULL pointer */
  if (versioninfo == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set version info with corresponding macros from component header */
    versioninfo->vendorID = STBM_VENDOR_ID; /* SBSW_STBM_ACCESS_PARAMPTR */
    versioninfo->moduleID = STBM_MODULE_ID; /* SBSW_STBM_ACCESS_PARAMPTR */
    versioninfo->sw_major_version = STBM_SW_MAJOR_VERSION; /* SBSW_STBM_ACCESS_PARAMPTR */
    versioninfo->sw_minor_version = STBM_SW_MINOR_VERSION; /* SBSW_STBM_ACCESS_PARAMPTR */
    versioninfo->sw_patch_version = STBM_SW_PATCH_VERSION; /* SBSW_STBM_ACCESS_PARAMPTR */
   }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #30 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_VERSION_INFO, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
} /* StbM_GetVersionInfo */
# endif /* (STBM_VERSION_INFO_API == STD_ON) */
#endif /* STBM_NOUNIT_COMMON */

#ifndef STBM_NOUNIT_GLOBALTIME /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  StbM_GetCurrentTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTime(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check timeStampPtr parameter for NULL pointer */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #40 Check userDataPtr parameter for NULL pointer */
  else if (userDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {

    /* ----- Implementation ----------------------------------------------- */
    StbM_VirtualLocalTimeType virtualLocalTime;
    StbM_SynchronizedTimeBaseType timeBaseIdx = timeBaseId;
    StbM_PartitionIdentifiersIterType partitionIdx = 0u;

    StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    StbM_EnterCritical_CrossCore();

    /* #50 Get current time */
    retVal = StbM_GlobalTime_OnGetCurrentTime(timeBaseIdx, timeStampPtr, &virtualLocalTime, userDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #60 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_CURRENT_TIME, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retVal;
} /* StbM_GetCurrentTime */

# if (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetCurrentTimeExtended
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentTimeExtended(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2VAR(StbM_TimeStampExtendedType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check timeStampPtr and userDataPtr parameter for NULL pointer */
  else if ((timeStampPtr == NULL_PTR) || (userDataPtr == NULL_PTR))
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_SynchronizedTimeBaseType timeBaseIdx = timeBaseId;
    StbM_PartitionIdentifiersIterType partitionIdx = 0u;

    StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    StbM_EnterCritical_CrossCore();

    /* #40 Get current time */
    retVal = StbM_GlobalTime_OnGetCurrentTimeExtended(timeBaseIdx, timeStampPtr, userDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #50 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_CURRENT_TIME_EXTENDED, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_GetCurrentTimeExtended */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
# endif /* (STBM_GET_CURRENT_TIME_EXTENDED_API == STD_ON) */

/**********************************************************************************************************************
 *  StbM_GetMainTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetMainTime(
        StbM_SynchronizedTimeBaseType timeBaseId,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimeSyncPtr,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) localTimeSyncPtr,
        P2VAR(StbM_RateDeviationType, AUTOMATIC, STBM_APPL_VAR) rateDeviation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check globalTimeSyncPtr, localTimeSyncPtr and rateDeviation parameter for NULL pointer */
  else if ((globalTimeSyncPtr == NULL_PTR) || (localTimeSyncPtr == NULL_PTR) || (rateDeviation == NULL_PTR))
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_SynchronizedTimeBaseType timeBaseIdx = timeBaseId;
    StbM_PartitionIdentifiersIterType partitionIdx = 0u;

    StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    StbM_EnterCritical_CrossCore();

    /* #40 Get global time, local time and time base status */
    StbM_GlobalTime_OnGetMainTime(timeBaseIdx, globalTimeSyncPtr, localTimeSyncPtr, rateDeviation, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    retVal = E_OK;
    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #60 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_MAIN_TIME, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retVal;
} /* StbM_GetMainTime */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

# if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_SetGlobalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_SetGlobalTime(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr,
        P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeStampPtr parameter for NULL pointer */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #30 Check timeStampPtr parameter for invalid elements */
  else if (timeStampPtr->nanoseconds > STBM_TIMESTAMP_MAX_NANOSECONDS)
  {
    errorId = STBM_E_PARAM_TIMESTAMP;
  }
  /* #40 Check userDataPtr parameter for invalid length */
  else if ((userDataPtr != NULL_PTR) && (userDataPtr->userDataLength > 3u))
  {
    errorId = STBM_E_PARAM_USERDATA;
  }
  /* #50 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    || (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == FALSE)
#   endif
  )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_InternalTimeStampType globalTime = STBM_INIT_TIME_ZERO;

    StbM_EnterCritical_CrossCore();

    retVal = E_OK;

    /* #60 Convert received time to internal timestamp */
    StbM_Calc_ToInternalTimeStampType(timeStampPtr, &globalTime); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
    /* #70 If offset timebase, calculate the offset value from received time */
    if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
    {
      StbM_InternalTimeStampType offsetValue = STBM_INIT_TIME_ZERO;

      retVal = StbM_LocalTime_CalculateOffsetValue(timeBaseIdx, &globalTime, &offsetValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      globalTime = offsetValue;
    }
#  endif

    /* #80 Set new global time */
    retVal |= StbM_GlobalTime_SetNewGlobalTime(timeBaseIdx, &globalTime, TRUE, partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #90 Copy the user data */
    StbM_UserData_Set(timeBaseIdx, userDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_CrossCore();
  }
  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #100 Report error if applicable */
    StbM_ReportError(STBM_SID_SET_GLOBAL_TIME, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_SetGlobalTime */ /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_UpdateGlobalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_UpdateGlobalTime(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStamp,
        P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userData)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeStamp parameter for NULL pointer */
  else if (timeStamp == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #30 Check timeStamp parameter for invalid elements */
  else if (timeStamp->nanoseconds > STBM_TIMESTAMP_MAX_NANOSECONDS)
  {
    errorId = STBM_E_PARAM_TIMESTAMP;
  }
  /* #40 Check userData parameter for invalid length */
  else if ((userData != NULL_PTR) && (userData->userDataLength > 3u))
  {
    errorId = STBM_E_PARAM_USERDATA;
  }
  /* #50 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    || (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == FALSE)
#   endif
  )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_InternalTimeStampType globalTime = STBM_INIT_TIME_ZERO;

    StbM_EnterCritical_CrossCore();

    retVal = E_OK;

    /* #60 Convert received time to internal timestamp */
    StbM_Calc_ToInternalTimeStampType(timeStamp, &globalTime); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
    /* #70 If offset timebase, calculate the offset value from received time */
    if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
    {
      StbM_InternalTimeStampType offsetValue = STBM_INIT_TIME_ZERO;

      retVal = StbM_LocalTime_CalculateOffsetValue(timeBaseIdx, &globalTime, &offsetValue, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      globalTime = offsetValue;
    }
#  endif

    /* #80 Set new global time */
    retVal |= StbM_GlobalTime_SetNewGlobalTime(timeBaseIdx, &globalTime, FALSE, partitionIdx); /* PRQA S 2986 */ /* MD_StbM_Rule2.2_2986 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #90 Copy the user data */
    StbM_UserData_Set(timeBaseIdx, userData, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #100 Report error if applicable */
    StbM_ReportError(STBM_SID_UPDATE_GLOBAL_TIME, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_UpdateGlobalTime */ /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */

#  if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_SetOffset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_SetOffset(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) timeStampPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#   if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check initialization state of the component */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check parameter 'timeStampPtr' for NULL pointer */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #30 Check parameter 'timeStampPtr' for invalid elements */
  else if (timeStampPtr->nanoseconds > STBM_TIMESTAMP_MAX_NANOSECONDS)
  {
    errorId = STBM_E_PARAM_TIMESTAMP;
  }
  /* #40 Check parameter 'timeBaseId' */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#    if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    || (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == FALSE)
#    endif
    || (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == FALSE))
  {
    errorId = STBM_E_PARAM;
  }
  else
#   endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_InternalTimeStampType receivedOffsetValue = STBM_INIT_TIME_ZERO;

    StbM_EnterCritical_CrossCore();

    /* #50 Convert received offset value to internal timestamp */
    StbM_Calc_ToInternalTimeStampType(timeStampPtr, &receivedOffsetValue); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #60 Set new offset time */
    retVal = StbM_GlobalTime_SetNewGlobalTime(timeBaseIdx, &receivedOffsetValue, TRUE, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* Should handle user data here */

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#   if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #70 Report error if applicable */
    StbM_ReportError(STBM_SID_SET_OFFSET, errorId);
  }
#   else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif
  return retVal;
} /* StbM_SetOffset */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
#  endif /* (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) */
# endif /* (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_BusGetCurrentTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_BusGetCurrentTime(
        StbM_SynchronizedTimeBaseType timeBaseId,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) globalTimePtr,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) localTimePtr,
        P2VAR(StbM_UserDataType, AUTOMATIC, STBM_APPL_VAR) userData)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))
    || (StbM_TimeBase_IsSynchronized(timeBaseIdx, partitionIdx) == FALSE)
#   endif
    )
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check globalTimePtr, localTimePtr and userData parameter for NULL pointer */
  else if ((globalTimePtr == NULL_PTR) || (localTimePtr == NULL_PTR) || (userData == NULL_PTR))
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#  endif
  {

    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_CrossCore();

    /* #40 Get current time and user data */
    retVal = StbM_GlobalTime_OnGetCurrentTime(timeBaseIdx, globalTimePtr, localTimePtr, userData, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #50 Report error if applicable */
    StbM_ReportError(STBM_SID_BUS_GET_CURRENT_TIME, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_BusGetCurrentTime */

# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetOffset
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetOffset(StbM_SynchronizedTimeBaseType timeBaseId,
        P2VAR(StbM_TimeStampType, AUTOMATIC, STBM_APPL_VAR) timeStampPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE) || (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == FALSE))
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check timeStampPtr parameter for NULL pointer */
  else if (timeStampPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Local Variables ---------------------------------------------- */
    StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;
    StbM_InternalTimeStampType offset = STBM_INIT_TIME_ZERO;

    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_CrossCore();

    /* #40 Get the offset value */
    retVal = StbM_LocalTime_OnGetCurrentVirtualLocalTime(timeBaseIdx, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    retVal |= StbM_LocalTime_GetLocalTime(timeBaseIdx, &virtualLocalTime, &offset, partitionIdx); /* PRQA S 2985 */ /* MD_StbM_Rule2.2_2985 */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
    StbM_Calc_ToStbMTimeStampType(&offset, timeStampPtr); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    /* #50 Get local time status */
    timeStampPtr->timeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #60 Report error if applicable  */
    StbM_ReportError(STBM_SID_GET_OFFSET, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_GetOffset */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) */

# if (STBM_CONFIG_TIME_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_BusSetGlobalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_BusSetGlobalTime(
        StbM_SynchronizedTimeBaseType timeBaseId,
        P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) globalTimePtr,
        P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr,
        P2CONST(StbM_MeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr,
        P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_DATA) localTimePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
    || (StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == FALSE)
#   endif
  )
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check globalTimePtr, measureDataPtr and localTimePtr parameter for NULL pointer */
  else if ((globalTimePtr == NULL_PTR) || (measureDataPtr == NULL_PTR) || (localTimePtr == NULL_PTR))
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #40 Check globalTimePtr parameter for invalid elements */
  else if (globalTimePtr->nanoseconds > STBM_TIMESTAMP_MAX_NANOSECONDS)
  {
    errorId = STBM_E_PARAM_TIMESTAMP;
  }
  /* #50 Check userDataPtr parameter for invalid length */
  else if ((userDataPtr != NULL_PTR) && (userDataPtr->userDataLength > 3u))
  {
    errorId = STBM_E_PARAM_USERDATA;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_InternalTimeStampType globalTime = STBM_INIT_TIME_ZERO;

    StbM_EnterCritical_CrossCore();

    /* #60 Set the path delay for the time recording unit */
#  if (STBM_CONFIG_TIME_RECORDING == STD_ON)
    if (StbM_TimeRecording_IsConfigured(timeBaseIdx, partitionIdx)) /* COV_STBM_SILENT_TX */
    {
      StbM_TimeRecording_SetPathDelay(timeBaseIdx, measureDataPtr->pathDelay, partitionIdx);
    }
#  endif

    /* #70 Convert received global time to internal timestamp */
    StbM_Calc_ToInternalTimeStampType(globalTimePtr, &globalTime); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #80 Receive the new global time */
    retVal = StbM_GlobalTime_ReceiveGlobalTime(timeBaseIdx, &globalTime, localTimePtr, globalTimePtr->timeBaseStatus, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    /* #90 Set received user data */
    StbM_UserData_Set(timeBaseIdx, userDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    /* #100 Process all cloning requests that use time base as source */
#  if (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON)
    StbM_CloneTime_CallCloneRequest(timeBaseIdx, partitionIdx);
#  endif

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #110 Report error if applicable */
    StbM_ReportError(STBM_SID_BUS_SET_GLOBAL_TIME, errorId);
  }
#  elif (STBM_CONFIG_TIME_RECORDING == STD_OFF)
  STBM_DUMMY_STATEMENT(measureDataPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  STBM_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  else
  STBM_DUMMY_STATEMENT(errorId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_BusSetGlobalTime */ /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_GetTimeLeap
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetTimeLeap(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2VAR(StbM_TimeDiffType, AUTOMATIC, STBM_APPL_VAR) timeJump)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
    /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON)
    || (StbM_TimeBase_IsPure(timeBaseIdx, partitionIdx) == TRUE)
#   endif
  )
  {
    errorId = STBM_E_PARAM;
  }
    /* #30 Check timeJump parameter for NULL pointer */
  else if (timeJump == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_CrossCore();

    if (StbM_LocalTime_IsTimeLeapValid(timeBaseIdx, partitionIdx) == TRUE)
    {
      retVal = E_OK;
      /* #40 If no other error occurred, get the time leap from the time leap unit */
      *timeJump = StbM_LocalTime_GetTimeLeap(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
    }

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #50 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_TIMELEAP, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_GetTimeLeap */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_TIME_SLAVE == STD_ON) */
#endif /* STBM_NOUNIT_GLOBALTIME */

#ifndef STBM_NOUNIT_CLONETIME /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_SOURCE_TIMEBASE == STD_ON)
/**********************************************************************************************************************
 *  StbM_CloneTimeBase
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_CloneTimeBase(
        StbM_SynchronizedTimeBaseType timeBaseId,
        StbM_CloneConfigType cloneCfg,
        StbM_TimeBaseStatusType statusMask,
        StbM_TimeBaseStatusType statusValue)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType destinationTimeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType destinationPartitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &destinationTimeBaseIdx, &destinationPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
    /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
    || (StbM_TimeBase_IsOffset(destinationTimeBaseIdx, destinationPartitionIdx) == TRUE)
#   endif
  )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_CrossCore();

    if (StbM_GetCloneDeferredCopy(cloneCfg) == 0u)
    {
      /* #30 If deferred copy flag is empty, process clone request immediately */
      retVal = StbM_CloneTime_ProcessCloneRequest(destinationTimeBaseIdx, destinationPartitionIdx, cloneCfg, statusMask, statusValue);
    }
#  if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    else
    {
      /* #40 Otherwise, store deferred clone request */
      retVal = StbM_CloneTime_StoreCloneRequest(destinationTimeBaseIdx, destinationPartitionIdx, cloneCfg, statusMask, statusValue);
    }
#  endif

    StbM_LeaveCritical_CrossCore();
  }
  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #50 Report error if applicable */
    StbM_ReportError(STBM_SID_CLONE_TIME_BASE, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retVal;
} /* StbM_CloneTimeBase */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* STBM_CONFIG_SOURCE_TIMEBASE */
#endif /* STBM_NOUNIT_CLONETIME */

#ifndef STBM_NOUNIT_LOCALTIME /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  StbM_GetCurrentVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetCurrentVirtualLocalTime(
        StbM_SynchronizedTimeBaseType timeBaseId,
        P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, STBM_APPL_VAR) localTimePtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check localTimePtr parameter for NULL pointer */
  else if (localTimePtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {

    /* ----- Implementation ----------------------------------------------- */
    StbM_SynchronizedTimeBaseType timeBaseIdx = timeBaseId;
    StbM_PartitionIdentifiersIterType partitionIdx = 0u;

    StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    StbM_EnterCritical_CrossCore();

    /* #40 Get current virtual local time of the referenced time base */
    retVal = StbM_LocalTime_OnGetCurrentVirtualLocalTime(timeBaseIdx, localTimePtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #50 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_CURRENT_VIRTUAL_LOCAL_TIME, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retVal;
} /* StbM_GetCurrentVirtualLocalTime */
#endif /* STBM_NOUNIT_LOCALTIME */

#ifndef STBM_NOUNIT_TIMERECORDING /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_RECORDING == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetSyncTimeRecordHead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetSyncTimeRecordHead(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2VAR(StbM_SyncRecordTableHeadType, AUTOMATIC, STBM_APPL_VAR) syncRecordTableHead)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))
    || (StbM_TimeBase_IsSynchronized(timeBaseIdx, partitionIdx) == FALSE)
#   endif
    || (StbM_TimeRecording_IsConfigured(timeBaseIdx, partitionIdx) == FALSE)
    )
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check syncRecordTableHead parameter for NULL pointer */
  else if (syncRecordTableHead == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_LocalCore();

    retVal = E_OK;

    /* #40 Set syncRecordTableHead to the recorded snapshot data header of the submitted time-base */
    StbM_TimeRecording_GetSyncRecordTableHead(timeBaseIdx, syncRecordTableHead, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_LocalCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #50 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_SYNC_TIME_RECORD_HEAD, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_GetSyncTimeRecordHead */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_TIME_RECORDING == STD_ON) */

# if (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetOffsetTimeRecordHead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetOffsetTimeRecordHead(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2VAR(StbM_OffsetRecordTableHeadType, AUTOMATIC, STBM_APPL_VAR) offsetRecordTableHead)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
    || (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == FALSE)
    || (StbM_TimeRecording_IsConfigured(timeBaseIdx, partitionIdx) == FALSE))
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check offsetRecordTableHead parameter for NULL pointer */
  else if (offsetRecordTableHead == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_LocalCore();

    retVal = E_OK;

    /* #40 Set offsetRecordTableHead to the recorded snapshot data header of the submitted time-base */
    StbM_TimeRecording_GetOffsetRecordTableHead(timeBaseIdx, offsetRecordTableHead, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_LocalCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #50 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_OFFSET_TIME_RECORD_HEAD, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

#  if (STBM_DEV_ERROR_DETECT == STD_OFF)
  STBM_DUMMY_STATEMENT(timeBaseId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_GetOffsetTimeRecordHead */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_TIME_RECORDING_OFFSET == STD_ON) */
#endif /* STBM_NOUNIT_TIMERECORDING */

#ifndef STBM_NOUNIT_TIMECORRECTION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_SetRateCorrection
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_SetRateCorrection(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        StbM_RateDeviationType rateDeviation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

#   if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
  errorId = STBM_E_NO_ERROR;
#   endif
  /* #10 Check initialization state of the component */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check parameter 'timeBaseId' and if given timebase is a master and has rate correction configured 'allowed' */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    || (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == FALSE)
#   endif
  )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  else
  {
    errorId = STBM_E_NO_ERROR;
  }
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
#  if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
    if (StbM_TimeCorrection_IsAllowMasterRateCorrection(timeBaseIdx, partitionIdx) == TRUE)
    {
      StbM_InternalTimeStampType currentTimeBeforeNewRate = STBM_INIT_TIME_ZERO;
      StbM_VirtualLocalTimeType virtualLocalTime = STBM_INIT_VIRTUAL_LOCAL_TIME_ZERO;

      StbM_EnterCritical_CrossCore();

      /* #30 Get time before new rate is set */
      retVal = StbM_LocalTime_OnGetCurrentVirtualLocalTime(timeBaseIdx, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      retVal |= StbM_LocalTime_GetLocalTime(timeBaseIdx, &virtualLocalTime, &currentTimeBeforeNewRate, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

      if (retVal == E_OK)
      {
        /* #40 Update main time tuple */
        StbM_LocalTime_UpdateMainTimeTuple(timeBaseIdx, &currentTimeBeforeNewRate, &virtualLocalTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

        /* #50 Set new rate */
        StbM_TimeCorrection_SetRateMaster(timeBaseIdx, rateDeviation, partitionIdx);
      }

      StbM_LeaveCritical_CrossCore();
    }
    else
    {
      retVal = E_NOT_OK;
    }
#  else
    STBM_DUMMY_STATEMENT(rateDeviation); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    STBM_DUMMY_STATEMENT(timeBaseId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
    retVal = E_NOT_OK;
#  endif

#  if (STBM_DEV_ERROR_DETECT == STD_ON)
#   if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
    if (retVal == E_NOT_OK)
#   endif
    {
      errorId = STBM_E_SERVICE_DISABLED;
    }
#  endif
  }
  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
#   if (STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
#   endif
  {
    /* #60 Report error if applicable */
    StbM_ReportError(STBM_SID_SET_RATE_CORRECTION, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* StbM_SetRateCorrection */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) */

/**********************************************************************************************************************
 *  StbM_GetRateDeviation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetRateDeviation(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2VAR(StbM_RateDeviationType, AUTOMATIC, STBM_APPL_VAR) rateDeviation)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check rateDeviation parameter for NULL pointer */
  else if (rateDeviation == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
# if ((STBM_CONFIG_MASTER_RATE_CORRECTION == STD_ON) || (STBM_CONFIG_SLAVE_RATE_CORRECTION == STD_ON))
    StbM_SynchronizedTimeBaseType timeBaseIdx = timeBaseId;
    StbM_PartitionIdentifiersIterType partitionIdx = 0u;

    StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    StbM_EnterCritical_CrossCore();

    if (StbM_TimeCorrection_IsRateDeviationValid(timeBaseIdx, partitionIdx) == TRUE)
    {
      retVal = E_OK;

      /* #40 Get rate from time correction unit */
      *rateDeviation = StbM_TimeCorrection_GetRateDeviation(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
    }

    StbM_LeaveCritical_CrossCore();
# else
    *rateDeviation = 0; /* SBSW_STBM_ACCESS_PARAMPTR */
    STBM_DUMMY_STATEMENT(timeBaseId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #60 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_RATE_DEVIATION, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retVal;
} /* StbM_GetRateDeviation */
#endif /* STBM_NOUNIT_TIMECORRECTION */

#ifndef STBM_NOUNIT_STATUS /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  StbM_GetTimeBaseStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetTimeBaseStatus(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2VAR(StbM_TimeBaseStatusType, AUTOMATIC, STBM_APPL_VAR) syncTimeBaseStatus,
        P2VAR(StbM_TimeBaseStatusType, AUTOMATIC, STBM_APPL_VAR) offsetTimeBaseStatus)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check syncTimeBaseStatus and offsetTimeBaseStatus parameter for NULL pointer */
  else if ((syncTimeBaseStatus == NULL_PTR) || (offsetTimeBaseStatus == NULL_PTR))
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_SynchronizedTimeBaseType timeBaseIdx = timeBaseId;
    StbM_PartitionIdentifiersIterType partitionIdx = 0u;

    StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    StbM_EnterCritical_CrossCore();

# if (STBM_CONFIG_OFFSET_TIMEBASE == STD_ON)
    if (StbM_TimeBase_IsOffset(timeBaseIdx, partitionIdx) == TRUE)
    {
      StbM_SynchronizedTimeBaseType referredTimeBaseIdx = timeBaseIdx;
      StbM_PartitionIdentifiersIterType referredPartitionIdx = partitionIdx;

      StbM_TimeBase_GetReferredTimeBase(timeBaseIdx, partitionIdx, &referredTimeBaseIdx, &referredPartitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */
      /* #40 Set timebase status for synchronized timebase */
      *syncTimeBaseStatus = StbM_Status_GetLocalTimeStatus(referredTimeBaseIdx, referredPartitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
      /* #50 Set timebase status for offset timebase */
      *offsetTimeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
    }
    else
# endif
    {
      /* #40 Set timebase status for synchronized timebase */
      *syncTimeBaseStatus = StbM_Status_GetLocalTimeStatus(timeBaseIdx, partitionIdx); /* SBSW_STBM_ACCESS_PARAMPTR */
      /* #50 Set timebase status for offset timebase */
      *offsetTimeBaseStatus = 0x00; /* SBSW_STBM_ACCESS_PARAMPTR */
    }

    StbM_LeaveCritical_CrossCore();

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #60 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_TIME_BASE_STATUS, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retVal;
} /* StbM_GetTimeBaseStatus */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* STBM_NOUNIT_STATUS */

#ifndef STBM_NOUNIT_TIMENOTIFICATION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_NOTIFICATION == STD_ON)
/**********************************************************************************************************************
 *  StbM_StartTimer
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 ******************************************************************************************************************/
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_StartTimer(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        StbM_CustomerIdType customerId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2CONST(StbM_TimeStampType, AUTOMATIC, STBM_APPL_DATA) expireTime)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = STBM_E_NO_ERROR;
  Std_ReturnType retVal;
  StbM_CustomerIdType customerIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeNotification_GetPartitionMapping(customerId, &customerIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check initialization state of the component */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId and customerId parameter validity against configuration */
  else if (
          (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
          || (StbM_TimeNotification_IsCustomerIdValid(customerId) == FALSE)
          || (StbM_GetTimeBasePartitionMappingIdxOfTimeNotificationConfig(customerIdx, partitionIdx) != timeBaseId)
          )
  {
    errorId = STBM_E_PARAM;
  }
  /* #30 Check expireTime against NULL_PTR */
  else if (expireTime == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #40 Check timeStampPtr parameter for invalid elements */
  else if (expireTime->nanoseconds > STBM_TIMESTAMP_MAX_NANOSECONDS)
  {
    errorId = STBM_E_PARAM_TIMESTAMP;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_InternalTimeStampType timeStampExpireTime = STBM_INIT_TIME_ZERO;

    /* #50 Convert Autosar timestamp to internal timestamp */
    StbM_Calc_ToInternalTimeStampType(expireTime, &timeStampExpireTime); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    StbM_EnterCritical_CrossCore();

    /* #60 Start timer */
    retVal = StbM_TimeNotification_StartTimer(customerIdx, &timeStampExpireTime, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    StbM_LeaveCritical_CrossCore();

#  if (STBM_DEV_ERROR_DETECT == STD_OFF)
    STBM_DUMMY_STATEMENT(timeBaseId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #70 Report error if applicable */
    StbM_ReportError(STBM_SID_START_TIMER, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return retVal;
} /* StbM_StartTimer */ /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_NotificationFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 ********************************************************************************************************************/
#  if (STBM_MULTIPARTITION_USED == STD_ON)
FUNC(void, STBM_CODE) StbM_NotificationFunction(StbM_PartitionIdentifiersIterType partitionIndex)
#  else
FUNC(void, STBM_CODE) StbM_NotificationFunction(void)
#  endif
{
  /* ----- Local Variables ---------------------------------------------- */
#  if (STBM_MULTIPARTITION_USED == STD_OFF)
  StbM_PartitionIdentifiersIterType partitionIndex = 0u;
#  endif

  /* ----- Implementation ----------------------------------------------- */
  StbM_EnterCritical_CrossCore();

  /* #10 Notify time notification customers */
  StbM_TimeNotification_NotifyCustomers(partitionIndex);

  StbM_LeaveCritical_CrossCore();
} /* StbM_NotificationFunction */

/**********************************************************************************************************************
 *  StbM_TimerCallback
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, STBM_CODE) StbM_TimerCallback(void)
{
  /* ----- Implementation ----------------------------------------------- */
  StbM_EnterCritical_CrossCore();

  /* #10 Process the timer callback */
  StbM_TimeNotification_ProcessTimerCallback();

  StbM_LeaveCritical_CrossCore();

  /* #20 Activate task to call StbM_NotificationFunction in order to call the callbacks */
  StbM_TimeNotification_ActivateTaskForCallback();
} /* StbM_TimerCallback */
# endif /* (STBM_CONFIG_TIME_NOTIFICATION == STD_ON) */
#endif /* STBM_NOUNIT_TIMENOTIFICATION */

#ifndef STBM_NOUNIT_TIMEBASE /* COV_STBM_NOUNIT_SWITCH */
/**********************************************************************************************************************
 *  StbM_GetTimeBaseUpdateCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(uint8, STBM_CODE) StbM_GetTimeBaseUpdateCounter(StbM_SynchronizedTimeBaseType timeBaseId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
# if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = 0u;
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#  if (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON)
    || (StbM_TimeBase_IsPure(timeBaseIdx, partitionIdx) == TRUE)
#  endif
  )
  {
    errorId = STBM_E_PARAM;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_CrossCore();

    /* #30 Set return value to update counter of given time base */
    retVal = StbM_TimeBase_GetUpdateCounter(timeBaseIdx, partitionIdx);

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #40 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_TIME_BASE_UPDATE_COUNTER, errorId);
  }
# else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
} /* StbM_GetTimeBaseUpdateCounter */

# if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_TriggerTimeTransmission
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_TriggerTimeTransmission(StbM_SynchronizedTimeBaseType timeBaseId) /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    || (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == FALSE)
#   endif
#   if (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON)
    || (StbM_TimeBase_IsPure(timeBaseIdx, partitionIdx) == TRUE)
#   endif
  )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = E_OK;

    StbM_EnterCritical_CrossCore();

    /* #30 Increment update counter of time base */
    StbM_TimeBase_IncrementUpdateCounter(timeBaseIdx, partitionIdx);

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #40 Report error if applicable */
    StbM_ReportError(STBM_SID_TRIGGER_TIME_TRANSMISSION, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_TriggerTimeTransmission */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

#  if (STBM_HAS_ALLOW_SYSTEM_WIDE_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_GetMasterConfig
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_GetMasterConfig(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2VAR(StbM_MasterConfigType, AUTOMATIC, STBM_APPL_VAR) masterConfig)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#   if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check initialization state of the component */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
    /* #20 Check parameter 'masterConfig' */
  else if (masterConfig == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
    /* #30 Check parameter 'timeBaseId' is configured */
  else if (StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
  {
    errorId = STBM_E_PARAM;
  }
    /* #40 If all check passed: */
  else
#   endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_SynchronizedTimeBaseType timeBaseIdx = timeBaseId;
    StbM_PartitionIdentifiersIterType partitionIdx = 0u;

    StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

    /* #50 Set return value to E_OK */
    retVal = E_OK;

    /* #60 If requested timebase is not a system wide global time master: */
#   if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    if (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == FALSE)
    {
      /* #70 Set out parameter to STBM_SYSTEM_WIDE_MASTER_DISABLED */
      *masterConfig = STBM_SYSTEM_WIDE_MASTER_DISABLED; /* SBSW_STBM_ACCESS_PARAMPTR */
    }
    else
#   endif
    {
      /* #80 Otherwise, set out parameter to STBM_SYSTEM_WIDE_MASTER_ENABLED */
      *masterConfig = STBM_SYSTEM_WIDE_MASTER_ENABLED; /* SBSW_STBM_ACCESS_PARAMPTR */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#   if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #90 Report error if applicable */
    StbM_ReportError(STBM_SID_GET_MASTER_CONFIG, errorId);
  }
#   else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#   endif
  return retVal;
} /* StbM_GetMasterConfig */
#  endif /* STBM_HAS_ALLOW_SYSTEM_WIDE_GLOBAL_TIME_MASTER == STD_ON */
# endif /* STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON */
#endif /* STBM_NOUNIT_TIMEBASE */

#ifndef STBM_NOUNIT_TIMEVALIDATION /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_EthSetMasterTimingData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_EthSetMasterTimingData(StbM_SynchronizedTimeBaseType timeBaseId,
        P2CONST(StbM_EthTimeMasterMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check measureDataPtr for NULL pointer */
  if (measureDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))
  /* #30 Check if the given timebase is a synchronized timebase */
    || (StbM_TimeBase_IsSynchronized(timeBaseIdx, partitionIdx) == FALSE)
#   endif
#   if (STBM_CONFIG_TIME_SLAVE == STD_ON) && (STBM_CONFIG_GATEWAY == STD_OFF)
  /* #40 Check if the given timebase is a slave timebase */
    || (StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == TRUE)
#   endif
#   if (STBM_CONFIG_GATEWAY == STD_ON)
  /* #50 Check if the given timebase is a slave but not a gateway timebase */
    || ((StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == TRUE) && (StbM_TimeBase_IsGateway(timeBaseIdx, partitionIdx) == FALSE))
#   endif
  /* #60 Check if time validation for master is configured */
    || ((StbM_TimeValidation_IsConfigured(timeBaseIdx, partitionIdx) == FALSE) || (StbM_TimeValidation_IsMasterConfigured(timeBaseIdx, partitionIdx) == FALSE))
    )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_LocalCore();

    /* #70 Set eth master timing data */
    retVal = StbM_TimeValidation_OnSetEthMasterTimingData(timeBaseIdx, measureDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_LocalCore();
  }
  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #80 Report error if applicable */
    StbM_ReportError(STBM_SID_ETH_SET_MASTER_TIMINIG_DATA, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_EthSetMasterTimingData */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_EthSetPdelayResponderData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_EthSetPdelayResponderData(StbM_SynchronizedTimeBaseType timeBaseId,
        P2CONST(StbM_PdelayResponderMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check measureDataPtr for NULL pointer */
  if (measureDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))
  /* #30 Check if the given timebase is a synchronized timebase */
    || (StbM_TimeBase_IsSynchronized(timeBaseIdx, partitionIdx) == FALSE)
#   endif
#   if (STBM_CONFIG_TIME_SLAVE == STD_ON) && (STBM_CONFIG_GATEWAY == STD_OFF)
  /* #40 Check if the given timebase is a slave timebase */
    || (StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == TRUE)
#   endif
#   if (STBM_CONFIG_GATEWAY == STD_ON)
  /* #50 Check if the given timebase is a slave but not a gateway timebase */
    || ((StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == TRUE) && (StbM_TimeBase_IsGateway(timeBaseIdx, partitionIdx) == FALSE))
#   endif
  /* #60 Check if time validation for master is configured */
    || ((StbM_TimeValidation_IsConfigured(timeBaseIdx, partitionIdx) == FALSE) || (StbM_TimeValidation_IsMasterConfigured(timeBaseIdx, partitionIdx) == FALSE))
    )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_LocalCore();

    /* #70 Set eth master pdelay responder data */
    retVal = StbM_TimeValidation_OnSetEthPdelayResponderData(timeBaseIdx, measureDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_LocalCore();
  }
  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #80 Report error if applicable */
    StbM_ReportError(STBM_SID_ETH_SET_PDELAY_RESPONDER_DATA, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_EthSetPdelayResponderData */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_MASTER == STD_ON) */

# if (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE == STD_ON)
/**********************************************************************************************************************
 *  StbM_EthSetSlaveTimingData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_EthSetSlaveTimingData(StbM_SynchronizedTimeBaseType timeBaseId,
        P2CONST(StbM_EthTimeSlaveMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check measureDataPtr for NULL pointer */
  if (measureDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))
  /* #30 Check if the given timebase is a synchronized timebase */
    || (StbM_TimeBase_IsSynchronized(timeBaseIdx, partitionIdx) == FALSE)
#   endif
#   if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
  /* #40 Check if the given timebase is not a slave timebase */
    || (StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == FALSE)
#   endif
  /* #60 Check if time validation for slave is configured */
    || ((StbM_TimeValidation_IsConfigured(timeBaseIdx, partitionIdx) == FALSE) || (StbM_TimeValidation_IsSlaveConfigured(timeBaseIdx, partitionIdx) == FALSE))
    )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_LocalCore();

    /* #70 Set eth slave timing data */
    retVal = StbM_TimeValidation_OnSetEthSlaveTimingData(timeBaseIdx, measureDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_LocalCore();
  }
  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #80 Report error if applicable */
    StbM_ReportError(STBM_SID_ETH_SET_SLAVE_TIMING_DATA, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_EthSetSlaveTimingData */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  StbM_EthSetPdelayInitiatorData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, STBM_CODE) StbM_EthSetPdelayInitiatorData(StbM_SynchronizedTimeBaseType timeBaseId,
        P2CONST(StbM_PdelayInitiatorMeasurementType, AUTOMATIC, STBM_APPL_DATA) measureDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;

  /* #10 Check measureDataPtr for NULL pointer */
  if (measureDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #20 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if ((STBM_CONFIG_OFFSET_TIMEBASE == STD_ON) || (STBM_CONFIG_PURE_LOCAL_TIMEBASE == STD_ON))
  /* #30 Check if the given timebase is a synchronized timebase */
    || (StbM_TimeBase_IsSynchronized(timeBaseIdx, partitionIdx) == FALSE)
#   endif
#   if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
  /* #40 Check if the given timebase is not a slave timebase */
    || (StbM_TimeBase_IsSlave(timeBaseIdx, partitionIdx) == FALSE)
#   endif
  /* #50 Check if time validation for slave is configured */
    || ((StbM_TimeValidation_IsConfigured(timeBaseIdx, partitionIdx) == FALSE) || (StbM_TimeValidation_IsSlaveConfigured(timeBaseIdx, partitionIdx) == FALSE))
    )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_LocalCore();

    /* #60 Set eth master pdelay initiator data */
    retVal = StbM_TimeValidation_OnSetEthPdelayInitiatorData(timeBaseIdx, measureDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_LocalCore();
  }
  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #70 Report error if applicable */
    StbM_ReportError(STBM_SID_ETH_SET_PDELAY_INITIATOR_DATA, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_EthSetPdelayInitiatorData */ /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif /* (STBM_CONFIG_TIME_VALIDATION_ETH_SLAVE = STD_ON) */
#endif /* STBM_NOUNIT_TIMEVALIDATION */

#ifndef STBM_NOUNIT_USERDATA /* COV_STBM_NOUNIT_SWITCH */
# if (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON)
/**********************************************************************************************************************
 *  StbM_SetUserData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, STBM_CODE) StbM_SetUserData(StbM_SynchronizedTimeBaseType timeBaseId, /* PRQA S 1330 */ /* MD_StbM_Rule8.3_1330 */
        P2CONST(StbM_UserDataType, AUTOMATIC, STBM_APPL_DATA) userDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = STBM_E_NO_ERROR;
  StbM_SynchronizedTimeBaseType timeBaseIdx = 0u;
  StbM_PartitionIdentifiersIterType partitionIdx = 0u;

  StbM_TimeBase_GetPartitionMapping(timeBaseId, &timeBaseIdx, &partitionIdx); /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */ /* SBSW_STBM_FUNCTIONCALL_LOCALPTR */

  /* ----- Development Error Checks ------------------------------------- */
#  if (STBM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check if component is initialized */
  if (StbM_IsPostInitialized() == FALSE)
  {
    errorId = STBM_E_NOT_INITIALIZED;
  }
  /* #20 Check userDataPtr parameter for NULL pointer */
  else if (userDataPtr == NULL_PTR)
  {
    errorId = STBM_E_PARAM_POINTER;
  }
  /* #30 Check userDataPtr parameter for invalid length */
  else if (userDataPtr->userDataLength > 3u)
  {
    errorId = STBM_E_PARAM_USERDATA;
  }
  /* #40 Check timeBaseId parameter validity against configuration */
  else if ((StbM_TimeBase_IsTimeBaseIdValid(timeBaseId) == FALSE)
#   if (STBM_CONFIG_TIME_SLAVE == STD_ON)
    || (StbM_TimeBase_IsMaster(timeBaseIdx, partitionIdx) == FALSE)
#   endif
  )
  {
    errorId = STBM_E_PARAM;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    StbM_EnterCritical_CrossCore();

    retVal = E_OK;

    /* #50 Get current user data from userDataPtr */
    StbM_UserData_Set(timeBaseIdx, userDataPtr, partitionIdx); /* SBSW_STBM_FUNCTIONCALL_PARAMPTR */

    StbM_LeaveCritical_CrossCore();
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (STBM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != STBM_E_NO_ERROR)
  {
    /* #60 Report error if applicable */
    StbM_ReportError(STBM_SID_SET_USER_DATA, errorId);
  }
#  else
  STBM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* StbM_SetUserData */
# endif /* (STBM_CONFIG_GLOBAL_TIME_MASTER == STD_ON) */
#endif /* STBM_NOUNIT_USERDATA */

#define STBM_STOP_SEC_CODE
#include "StbM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:
 MD_StbM_Rule8.3_1330:  MISRA rule: 8.3
     Reason:     The RTE Generator uses default names for parameter identifiers of port defined arguments of service modules.
                 Therefore the parameter identifiers in the function declaration differs from those of the implementation of the BSW module.
     Risk:       No functional risk.
     Prevention: Not required.

 MD_StbM_Rule8.5_3449:  MISRA rule: 8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

 MD_StbM_Rule8.5_3451:  MISRA rule: 8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

 MD_StbM_Rule13.5_3415:
     Reason:     QAC side effect analysis is wrong.
     Risk:       no risk
     Prevention: Covered by code review.

 MD_StbM_Rule1.3_2843:
     Reason:     QAC false positive. Wrong data flow analysis.
                 The variables are created and accessed using ComStackLib, which ensures the access.
     Risk:       no risk
     Prevention: Covered by code review (silent analysis).

 MD_StbM_Rule10.8_4395:
     Reason:     QAC cast is done on purpose.
     Risk:       no risk
     Prevention: Covered by code review.

  MD_StbM_Rule2.2_2981:
     Reason:     QAC redundant operation is ok for the benefit of readability.
     Risk:       no risk
     Prevention: Covered by code review.

 MD_StbM_Rule2.2_2983:
     Reason:     QAC redundant operation is ok for the benefit of readability.
     Risk:       no risk
     Prevention: Covered by code review.

 MD_StbM_Rule2.2_2985:
     Reason:     QAC redundant operation is ok for the benefit of readability.
     Risk:       no risk
     Prevention: Covered by code review.

 MD_StbM_Rule2.2_2986:
     Reason:     QAC redundant operation is ok for the benefit of readability.
     Risk:       no risk
     Prevention: Covered by code review.

  MD_StbM_Rule2.2_2987:
     Reason:     QAC false positive. Wrong data flow analysis. (only for postbuild configs)
     Risk:       no risk
     Prevention: Covered by code review.

 MD_StbM_Rule2.2_2995:
     Reason:     QAC redundant operation is ok for the benefit of readability.
     Risk:       no risk
     Prevention: Covered by code review.

 MD_StbM_Rule14.3_2991:
     Reason:     QAC redundant operation is ok for the benefit of readability.
     Risk:       no risk
     Prevention: Covered by code review.
*/

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_STBM_ACCESS_DEFERREDCLONEREQUESTSTATE
  \DESCRIPTION Access of StbM_DeferredCloneRequestState using ComStackLib.
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEBASESTATE
  \DESCRIPTION Access of StbM_TimeBaseState using ComStackLib.
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TRIGGEREDCUSTOMERSTATE
  \DESCRIPTION Write access to TriggeredCustomerState or referencing from TriggeredCustomerState using ComStackLib.
               The CustomerIndex is given by iterating over the triggered customers.
  \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

  \ID SBSW_STBM_ACCESS_STATUSNOTIFICATIONSTATE
  \DESCRIPTION Access of StbM_StatusNotificationState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_STATUSNOTIFICATIONSTATE_IND_TIMEBASECONFIG
  \DESCRIPTION Access to StbM_StatusNotificationState via indirection over StbM_TimeBaseConfig.
               Valid access of 0:1 indirection is ensured via StbM_IsStatusNotificationCustomerConfigUsedOfTimeBaseConfig()
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEOUTSTATE
  \DESCRIPTION Access of StbM_TimeoutState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEOUTSTATE_IND_TIMEBASECONFIG
  \DESCRIPTION Access to StbM_TimeoutState via indirection over StbM_TimeBaseConfig.
               Valid access of 0:1 indirection is ensured via StbM_Timeout_HasTimeoutConfigured()
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_USERDATASTATE
  \DESCRIPTION Access of StbM_UserDataState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMENOTIFICATIONSTATE_IND_TIMENOTIFICATIONPARTITIONMAPPING
  \DESCRIPTION Access to StbM_TimeNotificationState via indirection over StbM_TimeNotificationPartitionMapping.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMELEAPCLEARSTATE
  \DESCRIPTION Access of StbM_TimeLeapClearState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMELEAPCLEARSTATE_IND_TIMEBASECONFIG
  \DESCRIPTION Access to StbM_TimeLeapClearState via indirection over StbM_TimeBaseConfig.
               Valid access of 0:1 indirection is ensured via StbM_TimeLeap_HasTimeLeapConfigured()
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMERECORDINGSTATE
  \DESCRIPTION Access of StbM_TimeRecordingState using ComStackLib
               StbM_TimeRecordingState and StbM_TimeRecordingConfig have same size ensured by using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 and CSL02 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMERECORDINGSTATE_IND_TIMEBASECONFIG
  \DESCRIPTION Access to StbM_TimeRecordingState via indirection over StbM_TimeBaseConfig.
               Valid access of 0:1 indirection is ensured via StbM_TimeRecording_IsConfigured()
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_SYNCTIMERECORDINGBLOCK
  \DESCRIPTION Access of StbM_SyncTimeRecordingBlock using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_OFFSETTIMERECORDINGBLOCK
  \DESCRIPTION Access of StbM_OffsetTimeRecordingBlock using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERBLOCKDATA
  \DESCRIPTION Access of StbM_TimeValidationEthMasterBlockData using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVEBLOCKDATA
  \DESCRIPTION Access of StbM_TimeValidationEthSlaveBlockData using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERSTATE
  \DESCRIPTION Access of StbM_TimeValidationEthMasterState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVESTATE
  \DESCRIPTION Access of StbM_TimeValidationEthSlaveState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERBLOCKDATA_IDX_TIMEVALIDATIONETHMASTERBLOCKDATA
  \DESCRIPTION Access of StbM_TimeValidationEthPdelayResponderBlock via indirection over StbM_TimeValidationEthMasterBlock
               1:1 Indirection between StbM_TimeValidationEthPdelayResponderBlock and StbM_TimeValidationEthMasterBlock
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORBLOCKDATA_IDX_TIMEVALIDATIONETHSLAVEBLOCKDATA
  \DESCRIPTION Access of StbM_TimeValidationEthPdelayInitiatorBlock via indirection over StbM_TimeValidationEthSlaveBlock
               1:1 Indirection between StbM_TimeValidationEthPdelayInitiatorBlock and StbM_TimeValidationEthSlaveBlock
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERIDENTIFICATION_IDX_TIMEVALIDATIONETHMASTERSTATE
  \DESCRIPTION Access of StbM_TimeValidationEthMasterIdentification via indirection over StbM_TimeValidationEthMasterState
               1:1 Indirection between StbM_TimeValidationEthMasterIdentification and StbM_TimeValidationEthMasterState
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERSTATE_IDX_TIMEVALIDATIONETHMASTERSTATE
  \DESCRIPTION Access of StbM_TimeValidationEthPdelayResponderState via indirection over StbM_TimeValidationEthMasterState
               1:1 Indirection between StbM_TimeValidationEthPdelayResponderState and StbM_TimeValidationEthMasterState
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORSTATE_IDX_TIMEVALIDATIONETHSLAVESTATE
  \DESCRIPTION Access of StbM_TimeValidationEthPdelayInitiatorState via indirection over StbM_TimeValidationEthSlaveState
               1:1 Indirection between StbM_TimeValidationEthPdelayInitiatorState and StbM_TimeValidationEthSlaveState
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERIDENTIFICATION_IDX_TIMEVALIDATIONETHMASTERCONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthMasterIdentification via indirection over StbM_TimeBaseConfig.
               0:1 Indirection between StbM_TimeBaseConfig and StbM_TimeValidationConfig. Access ensured using runtime check.
               0:1 Indirection between StbM_TimeValidationConfig and StbM_TimeValidationEthMasterConfig. Access ensured using runtime check.
               1:1 Indirection between StbM_TimeValidationEthMasterConfig and StbM_TimeValidationEthMasterIdentification.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERSTATE_IND_TIMEVALIDATIONETHMASTERCONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthMasterState via indirection over StbM_TimeValidiationEthMasterConfig
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVESTATE_IND_TIMEVALIDATIONETHSLAVECONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthSlaveState via indirection over StbM_TimeValidiationEthSlaveConfig
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERBLOCKDATA_IND_TIMEVALIDATIONETHMASTERCONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthPdelayResponderBlock via indirection over StbM_TimeValidiationEthMasterConfig
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORBLOCKDATA_IND_TIMEVALIDATIONETHSLAVECONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthPdelayInitiatorBlock via indirection over StbM_TimeValidiationEthSlaveConfig
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYRESPONDERSTATE_IND_TIMEVALIDATIONETHMASTERCONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthPdelayResponderState via indirection over StbM_TimeValidationMasterConfig
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHPDELAYINITIATORSTATE_IND_TIMEVALIDATIONETHSLAVECONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthPdelayInitiatorState via indirection over StbM_TimeValidationSlaveConfig
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHMASTERBLOCKDATA_IND_TIMEVALIDATIONETHMASTERCONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthMasterBlock via indirection over StbM_TimeValidationMasterConfig
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMEVALIDATIONETHSLAVEBLOCKDATA_IND_TIMEVALIDATIONETHSLAVECONFIG
  \DESCRIPTION Access of StbM_TimeValidationEthSlaveBlock via indirection over StbM_TimeValidationSlaveConfig
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE
  \DESCRIPTION Access of StbM_TimeCorrectionMasterState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMECORRECTIONMASTERSTATE_IND_TIMEBASECONFIG
  \DESCRIPTION Access to StbM_TimeCorrectionMasterState via indirection over StbM_TimeBaseConfig.
               Valid access of 0:1 indirection is ensured via StbM_TimeCorrection_IsAllowMasterRateCorrection()
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMECORRECTIONSLAVESTATE
  \DESCRIPTION Access of StbM_TimeCorrectionSlaveState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMECORRECTIONSLAVESTATE_IND_TIMEBASECONFIG
  \DESCRIPTION Access to StbM_TimeCorrectionSlaveState via indirection over StbM_TimeBaseConfig.
               Valid access of 0:1 indirection is ensured via StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured().
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMECORRECTIONOFFSETSLAVESTATE_IND_TIMEBASEPARTITIONMAPPING
  \DESCRIPTION Access to StbM_TimeCorrectionOffsetSlaveState via indirection over StbM_TimeBasePartitionMapping.
               Valid access of 0:1 indirection is ensured via StbM_TimeCorrection_HasTimeCorrectionSlaveConfigured().
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_RATEMEASUREMENTS
  \DESCRIPTION Access of StbM_RateMeasurements using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_RATEMEASUREMENTS_IND_TIMEBASECONFIG
  \DESCRIPTION Access of StbM_RateMeasurements via indirection over StbM_TimeBaseConfig.
               0:1 Indirection between StbM_TimeBaseConfig and StbM_TimeCorrectionSlaveConfig. Access ensured using runtime check.
               1:N Indirection between StbM_TimeCorrectionSlaveConfig and StbM_RateMeasurements.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_STATUS
  \DESCRIPTION Access of StbM_Status using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_STATUS_IND_TIMEBASECONFIG
  \DESCRIPTION Access to StbM_Status via indirection over StbM_TimeBaseConfig.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_LOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING
  \DESCRIPTION Access to StbM_LocalTimeState via indirection over StbM_TimeBasePartitionMapping.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_VIRTUALLOCALTIMESTATE_IND_TIMEBASEPARTITIONMAPPING
  \DESCRIPTION Access to StbM_VirtualLocalTimeState via indirection over StbM_TimeBasePartitionMapping.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_RECEIVEDTIME_IND_LOCALTIME
  \DESCRIPTION Access to StbM_ReceivedTimeState via indirection over StbM_LocalTimeConfig. StbM_ReceivedTimeState has same size as StbM_LocalTimeConfig.
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_MAINTIMESTATE_IND_TIMEBASEPARTITIONMAPPING
  \DESCRIPTION Access to StbM_MainTimeState via indirection over StbM_TimeBasePartitionMapping.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_TIMELEAP_IND_LOCALTIME
  \DESCRIPTION Access to StbM_TimeLeapState via indirection over StbM_LocalTimeConfig. StbM_TimeLeapState has same size as StbM_LocalTimeConfig.
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_GPTCLOCKSTATE
  \DESCRIPTION Access of StbM_GptClockState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_STBM_ACCESS_GPTCLOCKSTATE_IND_TIMEBASEPARTITIONMAPPING
  \DESCRIPTION Access to StbM_GptClockState via indirection over StbM_TimeBasePartitionMapping and StbM_LocalClockConfig.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_ACCESS_LOCALCLOCKSTATE_IND_TIMEBASEPARTITIONMAPPING
  \DESCRIPTION Access to StbM_LocalClockState via indirection over StbM_TimeBasePartitionMapping and StbM_LocalClockConfig.
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_STBM_FUNCTIONCALL_LOCALPTR
  \DESCRIPTION Call of a function with pointer parameters where the pointers are pointing to local (stack) objects.
  \COUNTERMEASURE \N Compiler ensures validity of the pointers.

  \ID SBSW_STBM_FUNCTIONCALL_PARAMPTR
  \DESCRIPTION Forwarding the pointer that was given as parameter, without modifying anything.
  \COUNTERMEASURE \N Caller ensures validity of the pointers.

  \ID SBSW_STBM_FCTPTRCALL_NOTIFICATION
  \DESCRIPTION Function pointer stored in table modelled with ComStackLib is called.
               The index is given by iterating over the customers.
               Qualified use-case CSL03 of ComStackLib and compiler ensures type of the pointer from parameters.
  \COUNTERMEASURE \R Pointer is checked against NULL pointer at runtime.

  \ID SBSW_STBM_FCTPTRCALL_RECORDTABLE
  \DESCRIPTION Function pointer stored in table modelled with ComStackLib is called.
               The index is calculated by indirection of the TimeBaseConfig.
               The TimeBaseIndex is given as parameter on external interfaces or by iterating over the timebases.
               Qualified use-case CSL03 of ComStackLib and compiler ensures type of the pointer from parameters.
  \COUNTERMEASURE \R Pointer is checked against NULL pointer at runtime.

  \ID SBSW_STBM_ACCESS_PARAMPTR
  \DESCRIPTION The function read or writes to the object referenced by the parameter.
  \COUNTERMEASURE \N The caller ensures that the pointers passed to the parameter is valid.

  \ID SBSW_STBM_ACCESS_CSL_VAR
  \DESCRIPTION A ComStackLib generated variable is accessed.
  \COUNTERMEASURE \N The variable is written using a generated macro of the CSL. It immediately dereferences the variables address without pointer arithmetic.

SBSW_JUSTIFICATION_END */

/* VCA_JUSTIFICATION_BEGIN

\ID VCA_STBM_CSL02_CSL03
\DESCRIPTION Access to state table via indirection over StbM_TimeBaseConfig.
             Valid access of 0:1 indirection is ensured via previous run-time check.
\COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

\ID VCA_STBM_CSL01
\DESCRIPTION Passing value retrieved from state table to function as timeBaseIdx.
             Validity of used value is ensured via run-time check before being originally written to state table.
\COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID VCA_STBM_CSL03_ITERATION
\DESCRIPTION Value range of iteration variable is based on start and end indices generated by ComStackLib.
             Index retrieved via 0:N indirection is always lower than size of destination table.
\COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

VCA_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN
  \ID COV_STBM_DEV_ERROR_DETECT_TF_tf_tx
    \ACCEPT TF tf tx
    \REASON SafeBSW requires DEV_ERROR_DETECT to be always on. A MSSV Plugin enforces this configuration.

  \ID COV_STBM_DEV_ERROR_DETECT_TF_tf_tf_tf_tx_tf_tf
    \ACCEPT TF tf tf tf tx tf tf
    \REASON SafeBSW requires DEV_ERROR_DETECT to be always on. A MSSV Plugin enforces this configuration.

  \ID COV_STBM_MSR_COMPATIBILITY
    \ACCEPT XF
    \REASON [COV_MSR_COMPATIBILITY]

  \ID COV_STBM_SILENT_XF
    \ACCEPT XF
    \REASON This check ensures that no incorrect memory is overwritten. This should never happen in normal configurations.

  \ID COV_STBM_SILENT_TX
    \ACCEPT TX
    \REASON This check ensures that no incorrect memory is overwritten. This should never happen in normal configurations.

  \ID COV_STBM_MSR_MISRA
    \ACCEPT XX
    \REASON [COV_MSR_MISRA]

  \ID COV_STBM_POSTBUILD_SWITCH
    \ACCEPT XF
    \REASON This check is used only in case of post build configuration.

  \ID COV_STBM_NOUNIT_SWITCH
    \ACCEPT TX
    \REASON This switch is only used for unit testing and always true for normal operation.

  \ID COV_STBM_WHILE_COMMIT_BLOCKS
    \ACCEPT TF tf tx
    \REASON This check is required to avoid an endless loop if blocks are recorded faster than they can be passed to the application.
            This can only happen if new blocks are recorded in interrupt context while other blocks are passed in context of the main function.

  \ID COV_STBM_SETINITIALIZED_TX
    \ACCEPT TX
    \REASON This is always true for configs with disables switches STBM_CONFIG_STATUS_NOTIFICATION, STBM_CONFIG_TIME_RECORDING, STBM_CONFIG_TIME_NOTIFICATION and STBM_CONFIG_TIME_VALIDATION.

COV_JUSTIFICATION_END */

/* FETA_JUSTIFICATION_BEGIN

  \ID FETA_StbM_BlocksToCommit
  \DESCRIPTION The upper border of the loop is a positive constant value provided by CSL. The value in the table depends on the configuration.
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID FETA_StbM_2
  \DESCRIPTION The start index and the stop index of the loop is provided by CSL. The qualified CSL APIs returns the positive constant values from 
			   CSL tables. The positive values in the table depends on the configuration. The CSL guarantees that the start index is smaller than the stop index.
			   The stop index is a defined upper border of the loop. 
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

\FETA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: StbM.c
 *********************************************************************************************************************/
