/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Rtm.h
 *    Component:  -
 *       Module:  RTM
 *    Generator:  -
 *
 *  Description:  RTM static header file.
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2013-04-22  visazb  -             Initial version
 *  01.00.01  2013-08-06  visore  ESCAN00068379 Unknown runtime behavior if Rtm_InitMemory is not invoked
 *            2013-08-06  visore  ESCAN00069628 Missing DET check for invalid disableInterrupts parameter in Rtm_StartMP and Rtm_StopMP
 *            2013-07-06  visore  ESCAN00069629 Compiler warning: undeclared symbol 'Rtm_LiveMeasurement'
 *            2013-09-19  visore  ESCAN00070505 AR4-220: redefine STATIC to static
 *            2013-09-19  visore  ESCAN00070506 Compiler error: "error C2159: more than one storage class specified" if STATIC is defined as "static"
 *            2013-09-23  visore  ESCAN00070619 Compiler warning: warning C4127: conditional expression is constant
 *            2013-09-23  visore  ESCAN00070621 DET error RTM_E_UNBALANCED is thrown if Rtm_Stop() is called before Rtm_Start()
 *  01.01.00  2013-11-26  visore  ESCAN00070889 AR4-372: Support Measurement of Net Runtimes
 *  01.01.01  2014-05-21  visore  ESCAN00075552 Remove TO-DO Sections
 *            2014-05-21  visore  ESCAN00075805 Compiler warning: Rtm_GetFreeMeasurementObject(void) is called with parameter
 *            2014-05-21  visore  ESCAN00075806 RTM_NET_RUNTIME_PAUSE_SUPPORT  is not filtered by ORGANi in in Rtm.h
 *  01.01.02  2014-07-07  visore  ESCAN00076777 Compiler warning: ["../Source/../AMD/BSW/Rtm/Rtm.c" 758/40] invalid shift count
 *            2014-07-07  visore  ESCAN00076778 Measured minimum and maximum run times are incorrect for measurements with measurement count > 1
 *            2014-07-07  visore  ESCAN00076779 Remove the critical section from Rtm_EnterIsrFct() and Rtm_LeaveIsrFct()
 *  01.02.00  2014-07-08  viszda  ESCAN00076464 AR4-817: Runtime optimization of the RTM measurement functions
 *            2014-07-09  viszda  ESCAN00076861 Duplicated external Array declaration in Rtm.h
 *            2014-07-23  viszda  ESCAN00077300 MISRA deviation: MISRA-C:2004 Rule 8.8: Duplicated declaration
 *            2014-07-29  viszda  ESCAN00077455 Type cast from 'int' to 'Rtm_MeasurementTimestampType'
 *            2014-07-29  viszda  ESCAN00077449 Add initialization of Rtm_Ctrl in Rtm_InitMemory
 *            2014-07-29  viszda  ESCAN00076463 AR4-791: Serial and parallel measurement of CPU load
 *            2014-07-16  viszda  ESCAN00077119 The measured maximum run times are in correct in case net runtime support is enabled
 *            2014-10-09  viszda  ESCAN00078841 Calculated CPU Load is wrong
 *            2014-10-24  viszda  ESCAN00079113 Overall CPU load measurement results can be higher than 100%
 *            2014-11-06  viszda  ESCAN00077452 Compiler warning: Duplicated declaration of Rtm_MainFunction
 *  01.02.01  2014-11-27  viszda  ESCAN00079842 The CPU load is always 100% in CPU load control mode C_API
 *            2014-11-27  viszda  ESCAN00079844 The current result of CPU load measurement should be available for CPU load control mode C_API
 *  01.02.02  2015-06-25  viszda  ESCAN00080430 Inline function not encapsulated in RTM_START_SEC_CODE
 *            2015-07-01  viszda  ESCAN00083746 Implausible measurement results for min and max values
 *  02.00.00  2015-10-01  viszda  ESCAN00085574 FEAT-921: Multicore support for RTM Measurement Points [AR4-816]
 *            2015-10-01  viszda  ESCAN00083646 Support of 32bit timer
 *            2015-10-01  viszda  ESCAN00085572 Optimization of Net Runtime implementation
 *  2.00.01   2016-02-25  viszda  ESCAN00087879 DET occurs during start up of RTM
 *  2.00.02   2016-04-05  viszda  ESCAN00089228 Load current AUTOSAR schema for BSWMD
 *  2.01.00   2016-04-15  viszda  ESCAN00089508 FEAT-1846: RTM cleanup and improvements
 *            2016-05-17  viszda  ESCAN00089265 API based RTM control in CANoe
 *            2016-04-07  viszda  ESCAN00090816 Implausible measurement results due to not stopped measurement points
 *  2.02.00   2016-09-14  viszda  ESCAN00091859 FEAT-2055: SafeRTM (Disable RTM safely)
 *  3.00.00   2017-04-03  viszda  STORYC-724    [AMD] Support net runtime measurement with RTM in Gen7 OS
 *            2017-04-03  viszda  ESCAN00087435 Rework RTM implementation structure and comments
 *            2017-04-03  viszda  ESCAN00080428 Correction of formal issues
 *            2017-04-05  viszda  ESCAN00093290 Wrong measurement results in case of execution time measurement
 *            2017-04-05  viszda  ESCAN00085578 Add DET checks to RTM's APIs
 *            2017-04-05  viszda  ESCAN00094525 Net runtime measurement deviates to a large extent from real runtime in special cases
 *            2017-04-07  viszda  ESCAN00094694 Add missing initialization of Rtm_DisableInterruptFlag in Rtm_InitMemory
 *  3.01.00   2017-04-19  viszda  STORYC-671    Rtm: reduce RTM measurement overhead.
 *  3.01.01   2017-06-09  viszda  ESCAN00095484 DET occurs before second initialization phase, no measurement possible
 *  3.01.02   2018-02-22  viszda  ESCAN00095675 CPU load measurement results greater than 100% if C-API is used
 *            2018-04-06  viszda  ESCAN00099000 Compiler error: Code section closed but not opened one.
 *            2018-08-06  viszda  ESCAN00100326 Implausible CPU load measurement results for repeated measurements
 *  3.01.03   2018-10-09  viszda  ESCAN00100966 Throw a DET error to notify a overflown measurement point result
 *  3.01.04   2018-12-10  viszda  ESCAN00101021 DET error occurs if measurement is started
 *  4.00.00   2020-12-04  viszda  SWAT-82       Tidy up Rtm
 *            2020-12-04  viszda  SWAT-59       MISRA-C2012
 *            2020-12-04  viszda  SWAT-712      Add missing plausibility check and measurement correction in Rtm_GetMeasurementItem
 *            2020-12-04  viszda  ESCAN00104499 A DET indicating an overflow of CPU load measurement is caused even though there was no CPU load
 *            2021-01-15  viszda  ESCAN00104491 DETs are not reported if triggered by a core that is not the BSW core
 *            2021-01-20  viszda  SWAT-1316     Make the Rtm independent from Xcp
 *  5.00.00   2021-02-01  viszda  SWAT-1285     Support of CPU load histogram
 *            2021-02-22  viszda  SWAT-1289     Support of task response time histogram
 *            2021-03-10  viszda  SWAT-1291     Support of task stack usage
 *  6.00.00   2021-04-12  viszda  SWAT-1468     Implement the improvements found during FeatureTesting
 *  6.01.00   2021-06-16  viszda  SWAT-1545     Implement improvements found during product testing
 *            2021-06-21  viszda  ESCAN00109549 Inconsistent memory mapping of array Rtm_MeasurementPointInfo
 *  6.02.00   2021-08-09  viszda  SWAT-1611     Renaming of measurement point types
 *  7.00.00   2021-09-01  viszda  SWAT-1591     Usage of <Ma>_MemMap in RTM
 *  7.01.00   2021-11-17  viszda  SWAT-1737     Migrate Asr4Rtm design to text-based format
 *  7.02.00   2021-12-17  viszda  SWAT-1683     Refactor the CPU load measurement mechanism
 *  7.03.00   2022-01-31  viszda  SWAT-1685     Refactor the Rtm code due to VCA analysis
 *  8.00.00   2022-03-29  viszda  SWAT-2012     Support C-API Access possibility to all measurement points
 *            2022-04-26  viszda  ESCAN00111766 Compiler warning: conversion from somelargertype to somesmallertype, possible loss of data
 *  8.00.01   2022-05-13  viszda  ESCAN00111893 Compiler error: l-value specifies const object
 *  8.00.02   2022-07-14  viszda  SWAT-2047     Tidy up (rework memory mapping to core independent)
 *            2022-07-26  viszda  ESCAN00112420 Implausible CPU load measurement results
 *********************************************************************************************************************/

#if !defined (RTM_H)
#define RTM_H

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Rtm_Types.h"
#include "Rtm_Cfg.h"

# if (RTM_XCP_IS_PRESENT == STD_ON)
#include "Xcp.h"
#endif

#if (RTM_NET_RUNTIME_SUPPORT == STD_ON) || (RTM_TASK_STACK_USAGE == STD_ON) || (RTM_NUMBER_OF_TASKRESPONSETIME_PERCENTILES > 0) /* COV_RTM_MSR_UNSUPPORTED */
# include "Os.h"

# if defined (osdGetTaskIDNotUsed) /* COV_RTM_MSR_CONFIG */
#  error "GetTaskId() API is not available but needed for the RTM net runtime measurement!"
# endif
#endif

#if (RTM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#if (RTM_NVM_IS_USED == STD_ON)
# include "NvM.h"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define Rtm_Start( measurement )                    Rtm_Start_ ## measurement /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#define Rtm_Stop( measurement )                     Rtm_Stop_ ## measurement /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */

/* ##V_CFG_MANAGEMENT ##CQProject : Monitoring_RuntimeMeasurement CQComponent : Implementation */
#define RTM_VERSION                                 (0x0800u)
#define RTM_RELEASE_VERSION                         (0x02u)

/* vendor and module identification */
#define RTM_VENDOR_ID                               (30u)
#define RTM_MODULE_ID                               (255u)

#define RTM_AR_RELEASE_MAJOR_VERSION                4u
#define RTM_AR_RELEASE_MINOR_VERSION                0u
#define RTM_AR_RELEASE_REVISION_VERSION             1u

/* Component Version Information */
#define RTM_SW_MAJOR_VERSION                        (RTM_VERSION >> 8u)
#define RTM_SW_MINOR_VERSION                        (RTM_VERSION & 0x00FFu)
#define RTM_SW_PATCH_VERSION                        (RTM_RELEASE_VERSION)

/* Development Error Detection */
#define RTM_E_NO_ERROR                              ((uint8)0x00u)
#define RTM_E_UNINIT                                ((uint8)0x01u)
#define RTM_E_WRONG_PARAMETERS                      ((uint8)0x02u)
#define RTM_E_INVALID_CONFIGURATION                 ((uint8)0x03u)
#define RTM_E_UNBALANCED                            ((uint8)0x04u)
#define RTM_E_MEASUREMENT_POINT_RESULT_OVERFLOWN    ((uint8)0x05u)
#define RTM_E_WRONG_CORE                            ((uint8)0x06u)

/* API ID */
#define RTM_SID_CPULOADMEASUREMENT                  ((uint8)0x01u)
#define RTM_SID_GETVERSIONINFO                      ((uint8)0x02u)
#define RTM_SID_INIT                                ((uint8)0x03u)
#define RTM_SID_INITMEMORY                          ((uint8)0x04u)
#define RTM_SID_MAINFUNCTION                        ((uint8)0x05u)
#define RTM_SID_STARTMP                             ((uint8)0x06u)
#define RTM_SID_STOPMP                              ((uint8)0x07u)
#define RTM_SID_GETMEASUREMENTITEM                  ((uint8)0x08u)
#define RTM_SID_ENTERTASKFCT                        ((uint8)0x09u)
#define RTM_SID_LEAVETASKFCT                        ((uint8)0x0Au)
#define RTM_SID_ENTERISRFCT                         ((uint8)0x0Bu)
#define RTM_SID_LEAVEISRFCT                         ((uint8)0x0Cu)
#define RTM_SID_SCHEDULE                            ((uint8)0x0Du)
#define RTM_SID_STARTNETMP                          ((uint8)0x0Eu)
#define RTM_SID_STOPNETMP                           ((uint8)0x0Fu)
#define RTM_SID_GETCPULOADHISTOGRAM                 ((uint8)0x10u)
#define RTM_SID_GETTASKRESPONSETIMEHISTOGRAM        ((uint8)0x11u)
#define RTM_SID_GETTASKSTACKUSAGE                   ((uint8)0x12u)
#define RTM_SID_CLEARRESULTS                        ((uint8)0x13u)
#define RTM_SID_STARTMEASUREMENT                    ((uint8)0x14u)
#define RTM_SID_STOPMEASUREMENT                     ((uint8)0x15u)
#define RTM_SID_PREPAREMPSETTINGS                   ((uint8)0x16u)
#define RTM_SID_CLEARMEASUREMENTRESULTS             ((uint8)0x17u)

#define RTM_UNINITIALIZED                           (0x00u)
#define RTM_INITIALIZED                             (0x01u)

/* Rtm_ControlState */
#define RTM_CONTROL_STATE_DISABLED                  (0x00u)
#define RTM_CONTROL_STATE_ENABLED                   (0x01u)

/* ESCAN00076777 */
/* Rtm_Cmd */
#define RTM_NULL                                    (0x00000000uL)
#define RTM_CMD_START_SERIAL_MEASUREMENT            (0x00000001uL)
#define RTM_CMD_START_PARALLEL_MEASUREMENT          (0x00000002uL)
#define RTM_CMD_START_LIVE_MEASUREMENT              (0x00000003uL)
#define RTM_CMD_STOP_MEASUREMENT                    (0x00000004uL)
#define RTM_CMD_CLEAR_RESULTS                       (0x00000005uL)
#define RTM_RESP_OK                                 (0x00000006uL)

#if (RTM_NET_RUNTIME_SUPPORT == STD_ON) /* COV_RTM_MSR_UNSUPPORTED */
# define RTM_INACTIVE                               (0xFFFFFFFFu)
# define RTM_PAUSED_BY_TASK                         (0xFFFFFFFEu)
# define RTM_PAUSED_BY_ISR                          (0xFFFFFFFDu)
# define RTM_PAUSED_BY_MEASUREMENT                  ((uint8)0x02u)
# define RTM_PAUSED_BY_USER                         ((uint8)0x08u)
#endif

/* Rtm_MeasurementType */
#define RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME    (0x00u)
#define RTM_MEASUREMENT_TYPE_NET_EXECUTIONTIME      (0x01u)
#define RTM_MEASUREMENT_TYPE_FLAT_EXECUTIONTIME     (0x02u)

/* Rtm_MeasurementPointType */
#define RTM_MP_TYPE_RUNTIME                         (0x00u)
#define RTM_MP_TYPE_CPU_LOAD                        (0x01u)
#define RTM_MP_TYPE_TASK                            (0x02u)

/* Std_ReturnType */
#define RTM_RETVAL_MP_NOT_ACTIVE                    (Std_ReturnType)(0x02u)
#define RTM_RETVAL_ITEM_NOT_AVAILABLE_FOR_MP        (Std_ReturnType)(0x03u)
#define RTM_RETVAL_MP_NOT_EXECUTED_YET              (Std_ReturnType)(0x04u)
#define RTM_RETVAL_MEASUREMENT_CONFIG_INVALID       (Std_ReturnType)(0x05u)
#define RTM_RETVAL_ANY_COMMAND_ALREADY_ACTIVE       (Std_ReturnType)(0x06u)
#define RTM_RETVAL_RTM_INACTIVE                     (Std_ReturnType)(0x07u)

#if !defined (RTM_HISTOGRAM_OVERFLOW_THRESHOLD)
# define RTM_HISTOGRAM_OVERFLOW_THRESHOLD           (0x80000000u)
#endif

#if !defined (RTM_HISTOGRAM_RIGHTSHIFTLENGTH)
# define RTM_HISTOGRAM_RIGHTSHIFTLENGTH             (3u)
#endif

#if !defined (RTM_SIZE_OF_CPULOAD_PERCENTILES)
# define RTM_SIZE_OF_CPULOAD_PERCENTILES            (RTM_NUMBER_OF_CPULOAD_PERCENTILES + 1u)
#endif

#if !defined (RTM_SIZE_OF_TASKRESPONSETIME_PERCENTILES)
# define RTM_SIZE_OF_TASKRESPONSETIME_PERCENTILES   (RTM_NUMBER_OF_TASKRESPONSETIME_PERCENTILES + 1u)
#endif

#if !defined (RTM_REPORT_DET_FOR_MEASUREMENT_POINT_RESULT_OVERFLOW)
# define RTM_REPORT_DET_FOR_MEASUREMENT_POINT_RESULT_OVERFLOW STD_OFF
#endif

#if !defined (RTM_WAIT_FOR_NVM_READ_TIMEOUT)
# define RTM_WAIT_FOR_NVM_READ_TIMEOUT (2048u)
#endif

/* Keyword macros */
#if !defined (STATIC)                               /* COV_RTM_MSR_COMPATIBILITY */
# define STATIC static
#endif

#if !defined (LOCAL_INLINE)                         /* COV_RTM_MSR_COMPATIBILITY */
# define LOCAL_INLINE INLINE STATIC
#endif

#if !defined (RTM_LOCAL)                            /* COV_RTM_MSR_COMPATIBILITY */
# define RTM_LOCAL STATIC
#endif

#if !defined (RTM_LOCAL_INLINE)                     /* COV_RTM_MSR_COMPATIBILITY */
# define RTM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#if !defined (RTM_DUMMY_STATEMENT)                  /* COV_RTM_MSR_COMPATIBILITY */
# if defined (RTM_USE_DUMMY_STATEMENT)
#  define RTM_DUMMY_STATEMENT(statement)            (void)(statement) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# else
#  define RTM_DUMMY_STATEMENT(statement)
# endif
#endif

#if !defined (RTM_DUMMY_STATEMENT_CONST)            /* COV_RTM_MSR_COMPATIBILITY */
# if defined (RTM_USE_DUMMY_STATEMENT_CONST)
#  define RTM_DUMMY_STATEMENT_CONST(statement)      (void)(statement) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# else
#  define RTM_DUMMY_STATEMENT_CONST(statement)
# endif
#endif

#if (RTM_NET_RUNTIME_SUPPORT == STD_ON) /* COV_RTM_MSR_UNSUPPORTED */
# if defined OS_TRACE_INVALID_THREAD                /* COV_RTM_MSR_COMPATIBILITY */
#  if (OS_TRACE_INVALID_THREAD != RTM_NUMBER_OF_THREADS) /* COV_RTM_MSR_CONFIG */
#   error "The number of OS threads does not match the number specified by RTM!"
#  endif
# endif
#endif

#if (RTM_DEV_ERROR_REPORT == STD_ON)
# if !defined Rtm_DetReportError
#  define Rtm_DetReportError(api, err)              (void)Det_ReportError( RTM_MODULE_ID, 0u, (api), (err)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# endif
#else
# if !defined Rtm_DetReportError
# define Rtm_DetReportError(api, err)
# endif
#endif

#define RTM_UP                                      (0x01u)
#define RTM_DOWN                                    (0x02u)

#define Rtm_ConvertTicksToUs(ticks)                 ((ticks)/(RTM_TICKS_PER_MILISECOND/1000u)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if (RTM_TIME_MEASUREMENT == STD_OFF) /* ESCAN00076464 */
# define Rtm_StartMP(id)
# define Rtm_StopMP(id)
#endif /* RTM_TIME_MEASUREMENT == STD_OFF */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
  uint8 Percentiles[RTM_SIZE_OF_CPULOAD_PERCENTILES];
} Rtm_CpuLoadHistogramType;

typedef struct
{
  uint32 MaxRuntimeInUs;
  uint8 Percentiles[RTM_SIZE_OF_TASKRESPONSETIME_PERCENTILES];
} Rtm_TaskResponseTimeHistogramType;

typedef uint32 Rtm_MaxTaskStackUsageType;

typedef struct
{
  Rtm_MaxTaskStackUsageType MaxStackUsage;
  uint32 TaskStackSize;
} Rtm_TaskStackUsageInfoType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define RTM_START_SEC_VAR_CLEARED_8
#include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#if (RTM_CONTROL == STD_ON)
extern VAR(uint8, RTM_VAR_CLEARED)                  Rtm_ControlDeniedCount;
#endif

#if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
extern VAR(uint8,  RTM_VAR_CLEARED)                 Rtm_TimerOverrunCnt;
#endif

#define RTM_STOP_SEC_VAR_CLEARED_8
#include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


#define RTM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
extern VAR(Rtm_MeasurementTimestampType, RTM_VAR_CLEARED) Rtm_PrevTimerValue;
#endif

#define RTM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


# define RTM_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#if (RTM_CONTROL == STD_ON)
extern VAR(uint8, RTM_VAR_INIT)                     Rtm_ControlState;
#endif

# define RTM_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


# define RTM_START_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

extern VAR(uint8, RTM_VAR_INIT)                     Rtm_InitState[RTM_NUMBER_OF_CORES]; /* ESCAN00068379 */

#if (RTM_TIME_MEASUREMENT == STD_ON)
# if (RTM_NESTING_COUNTER == STD_ON) || (RTM_DEV_ERROR_DETECT == STD_ON)
extern VAR(sint8, RTM_VAR_INIT)                     Rtm_MeasurementNestingCtr[RTM_NUMBER_OF_ACTIVATED_MPS];
# endif

extern VAR(uint8, RTM_VAR_INIT)                     Rtm_Ctrl[RTM_CTRL_VECTOR_LEN];
extern VAR(uint8, RTM_VAR_INIT)                     Rtm_MeasurementConfig[RTM_CTRL_VECTOR_LEN];
extern VAR(Rtm_MeasurementTimestampType, RTM_VAR_INIT) Rtm_StartTimeStamps[RTM_NUMBER_OF_ACTIVATED_MPS];
extern VAR(Rtm_DataSet, RTM_VAR_INIT)               Rtm_Results[RTM_NUMBER_OF_ACTIVATED_MPS];

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON) /* COV_RTM_MSR_UNSUPPORTED */
extern VAR(Rtm_TaskContextInfoType, RTM_VAR_INIT)   Rtm_TaskContext[RTM_NUMBER_OF_TASKS];
extern VAR(Rtm_IsrContextInfoType, RTM_VAR_INIT)    Rtm_IsrContext;
extern VAR(Rtm_ThreadContextInfoType, RTM_VAR_INIT) Rtm_ThreadContext[RTM_NUMBER_OF_THREADS];

extern VAR(uint32, RTM_VAR_INIT)                    Rtm_ActiveMeasurementId;
extern VAR(uint32, RTM_VAR_INIT)                    Rtm_ActiveThreadId;

extern VAR(Rtm_MeasurementPointInfoType, RTM_VAR_INIT) Rtm_MeasurementPointInfo[RTM_NUMBER_OF_ACTIVATED_MPS];
# endif
#endif

# define RTM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


# define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

# if (RTM_TASK_STACK_USAGE == STD_ON)
extern VAR(Rtm_MaxTaskStackUsageType, RTM_VAR_NO_INIT) Rtm_MaxTaskStackUsage[RTM_NUMBER_OF_TASKS];
# endif

#if (RTM_TIME_MEASUREMENT == STD_ON)
# if (RTM_TIMER_OVERRUN_SUPPORT == STD_ON)
extern VAR(uint8,  RTM_VAR_NO_INIT)                  Rtm_GetCurrentTimeCnt;
# endif

extern VAR(uint32, RTM_VAR_NO_INIT)                  Rtm_Cmd;
extern VAR(uint32, RTM_VAR_NO_INIT)                  Rtm_Resp;
extern VAR(sint32, RTM_VAR_NO_INIT)                  Rtm_MeasTimeCorrection;

extern VAR(uint32, RTM_VAR_NO_INIT)                  Rtm_AverageMainFunctionCycleTime;
extern VAR(uint32, RTM_VAR_NO_INIT)                  Rtm_MainFunctionCounter;

# if (RTM_MULTICORE_SUPPORT == STD_ON)
#  if (RTM_XCP_IS_PRESENT == STD_ON)
extern VAR(uint8, RTM_VAR_NO_INIT)                   Rtm_XcpState;
#  endif
extern VAR(uint8, RTM_VAR_NO_INIT)                   Rtm_SendNextMainFunction;
# endif
#endif

# define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#if (RTM_TIME_MEASUREMENT == STD_ON)

# define RTM_START_SEC_CONST_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

extern CONST(Rtm_MeasurementPointConfigType, RTM_CONST) Rtm_MeasurementPointConfigInfo[RTM_NUMBER_OF_ACTIVATED_MPS];
extern CONST(uint32, RTM_CONST)                     Rtm_ConfiguredToActivatedMPIds[RTM_NUMBER_OF_CONFIGURED_MPS];

# if (RTM_USE_32BIT_TIMER == STD_ON)
extern CONST(uint32, RTM_CONST)                     Rtm_ThresholdTimes[RTM_NUMBER_OF_ACTIVATED_MPS];
# else
extern CONST(uint16, RTM_CONST)                     Rtm_ThresholdTimes[RTM_NUMBER_OF_ACTIVATED_MPS];
# endif
extern CONST(Rtm_ThresholdCbkFctType, RTM_CONST)    Rtm_ThresholdCbkFctArr[RTM_NUMBER_OF_ACTIVATED_MPS];
extern CONST(uint8, RTM_CONST)                      Rtm_CtrlConfig[RTM_CTRL_VECTOR_LEN];

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON) /* COV_RTM_MSR_UNSUPPORTED */
extern CONST(Rtm_TaskContextInfoType, RTM_CONST)    Rtm_TaskContextInit[RTM_NUMBER_OF_TASKS];
extern CONST(Rtm_IsrContextInfoType, RTM_CONST)     Rtm_IsrContextInit;
extern CONST(Rtm_ThreadContextInfoType, RTM_CONST)  Rtm_ThreadContextInit[RTM_NUMBER_OF_THREADS];
# endif

# define RTM_STOP_SEC_CONST_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define RTM_START_SEC_CODE
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Rtm_InitMemory()
 *********************************************************************************************************************/
/*! \brief       Function for *_INIT_*-variable initialization
 *  \details     Service to initialize module global variables at power up. This function initializes the
 *               variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 *  \pre         Module is uninitialized.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_InitMemory(void);

#if (RTM_MULTICORE_SUPPORT == STD_OFF)
/**********************************************************************************************************************
 * Rtm_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the Rtm module.
 *  \details     This function initializes the module Rtm. It initializes all variables and sets the module state to
 *               initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \pre         Rtm_InitMemory has been called unless Xcp_ModuleInitialized is initialized by start-up code.
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_Init(void);
#else
/**********************************************************************************************************************
 * Rtm_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the Rtm module.
 *  \details     This function initializes the module Rtm. It initializes all variables and sets the module state to
 *               initialized.
 *  \param[in]   CoreIndex               The core index that is initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \pre         Rtm_InitMemory has been called unless Xcp_ModuleInitialized is initialized by start-up code.
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_Init(
  const uint16 CoreIndex);
#endif

/**********************************************************************************************************************
 *  Rtm_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Returns the version information.
 *  \details     Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  Versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \spec        requires Versioninfo != NULL_PTR;
 *  \endspec
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, RTM_APPL_VAR) Versioninfo);

#if (RTM_TIME_MEASUREMENT == STD_ON)
/* ESCAN00078841 */
/**********************************************************************************************************************
 * Rtm_CheckTimerOverrun()
 *********************************************************************************************************************/
/*! \brief       This function handles timer overruns.
 *  \details     It must be called cyclically with a higher frequency than the used timer.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         Should be called if RTM_TIMER_OVERRUN_SUPPORT is STD_ON.
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON.
 *  \ingroup     timer
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_CheckTimerOverrun(void);

/* ESCAN00069629 */
# if (RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF)
/**********************************************************************************************************************
 * Rtm_Cpu_CalculateCurrentCPULoad()
 *********************************************************************************************************************/
/*! \brief       Calculates current and cumulated measurement results of CPU load.
 *  \details     -
 *  \param[in]   CoreIndex               The core on which the CPU load is calculated.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON and 
 *               RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF.
 *  \pre         -
 *  \ingroup     cpuLoad
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_Cpu_CalculateCurrentCPULoad(
  uint16 CoreIndex);
# endif

# if (RTM_NUMBER_OF_CPULOAD_PERCENTILES > 0u)
/**********************************************************************************************************************
 * Rtm_CpuLoadHistogram_Calculate()
 *********************************************************************************************************************/
/*! \brief       Calculates the current percentile of CPU load measurement if the measurement is enabled and the
 *               hyperperiod is elapsed.
 *  \details     -
 *  \param[in]   CoreIndex          The core index for which the counter overrun shall be checked.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON and 
 *               RTM_NUMBER_OF_CPULOAD_PERCENTILES > 0u and 
 *               RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         -
 *  \ingroup     cpuLoad
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_CpuLoadHistogram_Calculate(
  uint16 CoreIndex);
# endif /* RTM_NUMBER_OF_CPULOAD_PERCENTILES > 0u */

/**********************************************************************************************************************
 * Rtm_GetCpuLoadHistogram()
 *********************************************************************************************************************/
/*! \brief       Returns the CPU load histogram results of the given core.
 *  \details     Sets all percentiles.
 *  \param[in]   CoreId                  The core for which the results are requested.
 *  \param[out]  CpuLoadHistogram        The pointer to the result percentiles.
 *  \return      E_NOT_OK                The request failed.
 *  \return      E_OK                    The request succeeded.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires CpuLoadHistogram != NULL_PTR;
 *  \endspec
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Only returns valid result if RTM_NUMBER_OF_CPULOAD_PERCENTILES > 0u.
 *  \ingroup     cpuLoad
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_GetCpuLoadHistogram(
  const uint16 CoreId, 
  P2VAR(Rtm_CpuLoadHistogramType, AUTOMATIC, RTM_APPL_VAR) CpuLoadHistogram);

/**********************************************************************************************************************
 * Rtm_GetTaskResponseTimeHistogram()
 *********************************************************************************************************************/
/*! \brief       Returns the task response time histogram results of the given task.
 *  \details     Sets all percentiles.
 *  \param[in]   TaskId                     The task for which the results are requested.
 *  \param[out]  TaskResponseTimeHistogram  The pointer to the result percentiles.
 *  \return      E_NOT_OK                   The request failed.
 *  \return      E_OK                       The request succeeded.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires TaskResponseTimeHistogram != NULL_PTR;
 *  \endspec
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Only returns valid result if RTM_NUMBER_OF_TASKRESPONSETIME_PERCENTILES > 0u.
 *  \ingroup     taskResponseTime
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_GetTaskResponseTimeHistogram(
  const uint16 TaskId, 
  P2VAR(Rtm_TaskResponseTimeHistogramType, AUTOMATIC, RTM_APPL_VAR) TaskResponseTimeHistogram);

#endif /* (RTM_TIME_MEASUREMENT == STD_ON) */

/**********************************************************************************************************************
 * Rtm_GetTaskStackUsage()
 *********************************************************************************************************************/
/*! \brief       Returns the task stack usage results of the given task.
 *  \details     Sets all percentiles.
 *  \param[in]   TaskId                     The task for which the results are requested.
 *  \param[out]  TaskStackUsage             The pointer to the results.
 *  \return      E_NOT_OK                   The request failed.
 *  \return      E_OK                       The request succeeded.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires TaskStackUsage != NULL_PTR;
 *  \endspec
 *  \pre         -
 *  \ingroup     taskStackUsage
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_GetTaskStackUsage(
  const uint16 TaskId, 
  P2VAR(Rtm_TaskStackUsageInfoType, AUTOMATIC, RTM_APPL_VAR) TaskStackUsage);

/**********************************************************************************************************************
 * Rtm_ClearHistogramResults()
 *********************************************************************************************************************/
/*! \brief       Clears the results of the CPU load histogram, the task response time, the task stack usage, or all 
 *               MPs.
 *  \details     Clears the requested results. Clearing all MP's results must only be done on BSW core.
 *  \param[in]   CoreId                   The core id for which the results are cleared.
 *  \param[in]   ResultsToBeCleared       Defines which result is to be cleared:
 *                                         - RTM_ALL_HISTOGRAM_AND_TASK_STACK_RESULTS: All histogram and task stack
 *                                                                                     usage results are cleared.
 *                                         - RTM_CPU_LOAD_HISTOGRAM_RESULTS: The CPU load histogram results are cleared.
 *                                         - RTM_TASK_RESPONSE_TIME_RESULTS: The task response time histogram results
 *                                                                           are cleared.
 *                                         - RTM_TASK_STACK_USAGE_RESULTS: The task stack usage results are cleared.
 *  \return      E_NOT_OK                 The request failed.
 *  \return      E_OK                     The request succeeded.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     clearResults
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_ClearHistogramResults(
  const uint16 CoreId,
  Rtm_ClearResultsType ResultsToBeCleared);

/**********************************************************************************************************************
 * Rtm_ClearMeasurementResults()
 *********************************************************************************************************************/
/*! \brief       Clears the measurement results of all MPs.
 *  \details     The actual clear is executed in next call of Rtm_MainFunction.
 *               The prepared MPs remain prepared, so they are not cleared.
 *  \return      E_OK                     The request succeeded.
 *  \return      E_NOT_OK                 The request failed, e.g. because of a DET or no MP is activated in
 *                                        configuration.
 *  \return      RTM_RETVAL_ANY_COMMAND_ALREADY_ACTIVE  A command is already active, repeat request later.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires GetCoreID() == RTM_BSW_CORE;
 *  \endspec
 *  \pre         -
 *  \ingroup     measCtr
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTM_CODE) Rtm_ClearMeasurementResults(void);

/**********************************************************************************************************************
 * Rtm_StartMeasurement()
 *********************************************************************************************************************/
/*! \brief       Starts the measurement of all prepared MPs.
 *  \details     To prepare the MPs Rtm_PrepareMPSettings must be called first. The measurement is always parallel. The
 *               measurement can be time-limited or endless. Maximum for time-limited is 0xFFFF.
 *               The actual start is executed in next call of Rtm_MainFunction.
 *  \param[in]   MeasurementDuration      Defines how long the measurement shall take. The value 0 starts an endless
 *                                        measurement. If greater than 0, than it defines the number of
 *                                        Rtm_MainFunction calls until the measurement is stopped. The maximum allowed
 *                                        value is 0xFFFF.
 *  \return      E_OK                     The request succeeded.
 *  \return      E_NOT_OK                 The request failed, e.g. because of a DET or no MP is activated in
 *                                        configuration.
 *  \return      RTM_RETVAL_ANY_COMMAND_ALREADY_ACTIVE  A command is already active, repeat request later.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires GetCoreID() == RTM_BSW_CORE;
 *  \endspec
 *  \pre         -
 *  \ingroup     measCtr
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_StartMeasurement(
  Rtm_MeasurementTimestampType MeasurementDuration);

/**********************************************************************************************************************
 * Rtm_StopMeasurement()
 *********************************************************************************************************************/
/*! \brief       Stops an active endless measurement.
 *  \details     The actual stop is executed in next call of Rtm_MainFunction.
 *  \param[in]   MeasurementDuration      Defines how long the measurement shall take. The value 0 starts an endless
 *                                        measurement. Maximum allowed value is 0xFFFF.
 *  \return      E_OK                     The request succeeded.
 *  \return      E_NOT_OK                 The request failed, e.g. because of a DET or no MP is activated in
 *                                        configuration.
 *  \return      RTM_RETVAL_MEASUREMENT_CONFIG_INVALID  No endless measurement is active, therefore it is not possible
 *                                                      to stop the measurement.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires GetCoreID() == RTM_BSW_CORE;
 *  \endspec
 *  \pre         -
 *  \ingroup     measCtr
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_StopMeasurement(void);

/**********************************************************************************************************************
 * Rtm_PrepareMPSettings()
 *********************************************************************************************************************/
/*! \brief       Prepares the required MPs for next measurement.
 *  \details     This function can be called multiple times to active all required MPs. The MPs are started by calling
 *               Rtm_StartMeasurement.
 *  \param[in]   MpSetting                Possible values:
 *                                          RTM_MP_SETTING_DISABLE_ALL: Disables all activated MPs.
 *                                          RTM_MP_SETTING_ENABLE_ALL: Enables all activated MPs.
 *                                          RTM_MP_SETTING_DEFAULT: Enables all activated MPs that are configured as
 *                                                                  Autostart. All other activated MPs are disabled.
 *                                          RTM_MP_SETTING_DISABLE_ONE_MP: Disables the given configured MP.
 *                                          RTM_MP_SETTING_ENABLE_ONE_MP: Enables the given configured MP.
 *  \param[in]   ConfiguredMPId           The configured MP to be dis-/enabled. Only required for
 *                                        RTM_MP_SETTING_DISABLE_ONE_MP and RTM_MP_SETTING_ENABLE_ONE_MP.
 *                                        Use the macros also used for Rtm_Start()/Rtm_Stop():
 *                                        -> RtmConf_RtmMeasurementPoint_<MP_Name>
 *  \return      E_OK                     The request succeeded.
 *  \return      E_NOT_OK                 The request failed, e.g. because of a DET or no MP is activated in
 *                                        configuration.
 *  \return      RTM_RETVAL_ANY_COMMAND_ALREADY_ACTIVE  A command is already active, repeat request later.
 *  \return      RTM_RETVAL_MEASUREMENT_CONFIG_INVALID  The MpSetting is invalid.
 *  \return      RTM_RETVAL_MP_NOT_ACTIVE               The selected configured MP is not activated in configuration.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires GetCoreID() == RTM_BSW_CORE;
 *  \endspec
 *  \pre         -
 *  \ingroup     measCtr
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_PrepareMPSettings(
  Rtm_MpSettingType MpSetting,
  const uint32 ConfiguredMPId);

/**********************************************************************************************************************
 * Rtm_GetMeasurementItem()
 *********************************************************************************************************************/
/*! \brief       Returns the CPU load measurement results.
 *  \details     Returns average CPU load, current CPU load, min or max CPU load.
 *  \param[in]   ConfiguredMPId          The configured measurement id for which the result is requested.
 *  \param[in]   ItemType                The requested result (RTM_ITEM_CPU_LOAD_AVERAGE, RTM_ITEM_CPU_LOAD_CURRENT,
 *                                         RTM_ITEM_MIN, RTM_ITEM_MAX, RTM_ITEM_RUNTIME_AVERAGE,
 *                                         RTM_ITEM_RUNTIME_OVERALL).
 *  \param[out]  ItemValuePtr            The pointer to the requested result.
 *  \return      E_OK                                 The request succeeded.
 *  \return      E_NOT_OK                             The request failed.
 *  \return      RTM_RETVAL_MP_NOT_EXECUTED_YET       The MP has no result because it was not executed, yet.
 *  \return      RTM_RETVAL_ITEM_NOT_AVAILABLE_FOR_MP The selected ItemType is invalid or not available for requested MP. 
 *  \return      RTM_RETVAL_MP_NOT_ACTIVE             The MP is not active, therefore it will never provide any result.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires ConfiguredMPId < RTM_NUMBER_OF_CONFIGURED_MPS;
 *               requires ((ItemType == RTM_ITEM_RUNTIME_AVERAGE) || ((ItemType == RTM_ITEM_RUNTIME_OVERALL) || ((ItemType == RTM_ITEM_CPU_LOAD_AVERAGE) || (ItemType == RTM_ITEM_CPU_LOAD_CURRENT) || (ItemType == RTM_ITEM_MIN) || (ItemType == RTM_ITEM_MAX));
 *               requires ItemValuePtr != NULL_PTR;
 *  \endspec
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Only the CPU load measurement section is allowed to be requested. Only returns valid result if 
 *               RTM_CPU_LOAD_CONTROL_MODE != RTM_CPU_LOAD_CONTROL_OFF.
 *  \ingroup     measItem
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_GetMeasurementItem(
  const uint32 ConfiguredMPId, 
  const Rtm_ItemType ItemType, 
  P2VAR(uint32, AUTOMATIC, RTM_APPL_VAR) ItemValuePtr);

#if (RTM_TIME_MEASUREMENT == STD_ON)

/**********************************************************************************************************************
 *  Rtm_Start()
 *********************************************************************************************************************/
/*! \fn          void Rtm_Start(uint8* MP_Name)
 *  \brief       Enters the measurement section of the given measurement point.
 *  \details     -
 *  \param[in]   <MP_Name>               The string name of the measurement point (e.g.
 *                                         RtmConf_RtmMeasurementPoint_<Name>).
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         -
 *  \ingroup     runtime
 *********************************************************************************************************************/
/* extern FUNC(void, RTM_CODE) Rtm_Start(<MP_Name>); */

/**********************************************************************************************************************
 *  Rtm_Stop()
 *********************************************************************************************************************/
/*! \fn          void Rtm_Stop(uint8* MP_Name)
 *  \brief       Leaves the measurement section of the given measurement point.
 *  \details     -
 *  \param[in]   <MP_Name>               The string name of the measurement point (e.g.
 *                                         RtmConf_RtmMeasurementPoint_<Name>).
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         -
 *  \ingroup     runtime
 *********************************************************************************************************************/
/* extern FUNC(void, RTM_CODE) Rtm_Start(<MP_Name>); */

/**********************************************************************************************************************
 * Rtm_StartMP()
 *********************************************************************************************************************/
/*! \brief       Starts runtime measurement for the given measurement section.
 *  \details     -
 *  \param[in]   measurementId           ID of the measurement section.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires measurementId < RTM_NUMBER_OF_ACTIVATED_MPS;
 *  \endspec
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Runtime measurement was started globally and this measurement section is active.
 *  \ingroup     runtime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_StartMP(
  uint32 measurementId); /* ESCAN00076464 */

/**********************************************************************************************************************
 * Rtm_StopMP()
 *********************************************************************************************************************/
/*! \brief       Stops runtime measurement for the given measurement section.
 *  \details     This function calculates the runtime for the given measurement section.
 *  \param[in]   measurementId           ID of the measurement section.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires measurementId < RTM_NUMBER_OF_ACTIVATED_MPS;
 *  \endspec
 *  \config      Available only if RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Runtime measurement was started globally and this measurement section is active.
 *  \ingroup     runtime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_StopMP(
  uint32 measurementId); /* ESCAN00076464 */

# if (RTM_NET_RUNTIME_SUPPORT == STD_ON) /* COV_RTM_MSR_UNSUPPORTED */
/**********************************************************************************************************************
 * Rtm_StartNetMP()
 *********************************************************************************************************************/
/*! \brief       Starts net runtime measurement for the given measurement section.
 *  \details     -
 *  \param[in]   measurementId           ID of the measurement section.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires measurementId < RTM_NUMBER_OF_ACTIVATED_MPS;
 *  \endspec
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON && RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Runtime measurement was started globally and this measurement section is active.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_StartNetMP(
  uint32 measurementId); /* ESCAN00076464 */

/**********************************************************************************************************************
 * Rtm_StopNetMP()
 *********************************************************************************************************************/
/*! \brief       Stops net runtime measurement for the given measurement section.
 *  \details     This function calculates the net runtime for the given measurement section.
 *  \param[in]   measurementId           ID of the measurement section.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \spec        requires measurementId < RTM_NUMBER_OF_ACTIVATED_MPS;
 *  \endspec
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON && RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Runtime measurement was started globally and this measurement section is active.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_StopNetMP(
  uint32 measurementId); /* ESCAN00076464 */

/**********************************************************************************************************************
 * Rtm_EnterTaskFct()
 *********************************************************************************************************************/
/*! \brief       Starts a preempted net measurement section.
 *  \details     Was a net measurement section active on the entered task this measurement section is reactivated.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON && RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Must be called by PreTaskHook of OS.
 *  \note        Must not be called if Rtm_Schedule is used.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_EnterTaskFct(void);

/**********************************************************************************************************************
 * Rtm_LeaveTaskFct()
 *********************************************************************************************************************/
/*! \brief       Preempts an active net measurement section.
 *  \details     Is a net measurement section active on the left task this measurement section is preempted.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON && RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Must be called by PostTaskHook of OS.
 *  \note        Must not be called if Rtm_Schedule is used.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_LeaveTaskFct(void);

/**********************************************************************************************************************
 * Rtm_EnterIsrFct()
 *********************************************************************************************************************/
/*! \brief       Starts a preempted net measurement section.
 *  \details     Was a net measurement section active on the entered ISR this measurement section is reactivated.
 *  \context     ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON && RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Must be called by PreISRHook of OS.
 *  \note        Must not be called if Rtm_Schedule is used.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_EnterIsrFct(void);

/**********************************************************************************************************************
 * Rtm_LeaveIsrFct()
 *********************************************************************************************************************/
/*! \brief       Preempts an active net measurement section.
 *  \details     Is a net measurement section active on the left ISR this measurement section is preempted.
 *  \context     ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON && RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Must be called by PostISRHook of OS.
 *  \note        Must not be called if Rtm_Schedule is used.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_LeaveIsrFct(void);

/**********************************************************************************************************************
 * Rtm_Schedule()
 *********************************************************************************************************************/
/*! \brief       Handles a scheduling event of the OS.
 *  \details     -
 *  \param[in]   FromThreadId            The thread which is preempted/terminated.
 *  \param[in]   ToThreadId              The thread which is entered (now running).
 *  \param[in]   CoreId                  The core on which the scheduling is performed.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_NET_RUNTIME_SUPPORT == STD_ON && RTM_TIME_MEASUREMENT == STD_ON.
 *  \pre         Must not be called if the APIs Rtm_EnterTaskFct/Rtm_LeaveTaskFct/Rtm_EnterIsrFctRtm_LeaveIsrFct
 *               are used.
 *  \note        Should be called by the TimingHook OS_VTH_SCHEDULE.
 *  \ingroup     netRuntime
 *********************************************************************************************************************/
extern FUNC(void, RTM_CODE) Rtm_Schedule(
  uint32 FromThreadId,
  uint32 ToThreadId,
  uint16 CoreId);
# endif /* (RTM_NET_RUNTIME_SUPPORT == STD_ON) */

#endif /* RTM_TIME_MEASUREMENT == STD_ON */

/**********************************************************************************************************************
 *  Rtm_Shutdown()
 *********************************************************************************************************************/
/*! \brief       Shuts down the Rtm.
 *  \details     Updates the task stack usage values.
 *  \return      E_NOT_OK    The shutdown request is still pending.
 *  \return      E_OK        The shutdown request is executed successfully.
 *  \context     TASK|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(Std_ReturnType, RTM_CODE) Rtm_Shutdown(void);

#if (RTM_MULTICORE_SUPPORT == STD_OFF)
/**********************************************************************************************************************
 *  Rtm_MainFunction()
 *********************************************************************************************************************/
/*! \fn          void Rtm_MainFunction(void)
 *  \brief       Cyclically executed API service of the Rtm.
 *  \details     Interprets commands from Rtm user, transmits runtime measurement results and control variables via 
 *               XCP, calculates CPU load measurement results.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_MULTICORE_SUPPORT == STD_OFF.
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
/* extern FUNC(void, RTM_CODE) Rtm_MainFunction(void); */

#else

/**********************************************************************************************************************
 *  Rtm_MainFunction()
 *********************************************************************************************************************/
/*! \brief       Cyclically executed API service of the Rtm.
 *  \details     Interprets commands from Rtm user, transmits runtime measurement results and control variables via 
 *               XCP, calculates CPU load measurement results.
 *  \param[in]   CoreIndex          The core index for which the cyclic job is executed.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      Available only if RTM_MULTICORE_SUPPORT == STD_ON.
 *  \pre         -
 *  \ingroup     general
 *********************************************************************************************************************/
extern FUNC(uint8, RTM_CODE) Rtm_MainFunction(
  const uint16 CoreIndex);

#endif /* RTM_MULTICORE_SUPPORT == STD_OFF */

# define RTM_STOP_SEC_CODE
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* RTM_H */

/*!
 * \exclusivearea RTM_EXCLUSIVE_AREA_0
 * Ensures that measurement results are consistently calculated.
 * This exclusive area is only open during execution of the calling service.
 * \protects Rtm_Results, Rtm_StartTimeStamps, Rtm_MeasurementNestingCtr
 * \usedin Rtm_Start, Rtm_Stop, Rtm_GetMeasurementItem, Rtm_CheckTimerOverrun
 * \exclude Rtm_MainFunction, Rtm_Start, Rtm_Stop, Rtm_GetMeasurementItem, Rtm_CheckTimerOverrun
 * \length MEDIUM Multiple results are calculated.
 * \endexclusivearea
 *
 * \exclusivearea RTM_EXCLUSIVE_AREA_1
 * Ensures that measurement results are consistently calculated. This exclusive area is open from Rtm_Start until
 * Rtm_Stop. Used for MPs for which RtmDisableInterrupts is enabled.
 * \protects Rtm_Results, Rtm_StartTimeStamps, Rtm_MeasurementPointInfo, Rtm_MeasurementNestingCtr
 * \usedin Rtm_Start, Rtm_Stop
 * \exclude Rtm_MainFunction, Rtm_Start, Rtm_Stop, Rtm_GetMeasurementItem, Rtm_CheckTimerOverrun
 * \length LONG Any code can be executed during this exclusive area.
 * \endexclusivearea
 *
 * \exclusivearea RTM_EXCLUSIVE_AREA_2
 * Ensures that measurement control remains consistently.
 * \protects Rtm_Cmd, Rtm_LastCommandToEcu, Rtm_Resp, Rtm_MeasurementTimer, Rtm_EndlessMeasurement,
 *           Rtm_LastMainFunctionTime, Rtm_AvgMainFunctionCycleTimeCalcCounter, Rtm_CalculatedCtrEndVal
 * \usedin Rtm_MainFunction, Rtm_ClearMeasurementResults, Rtm_StartMeasurement, Rtm_StopMeasurement,
 *         Rtm_PrepareMPSettings
 * \exclude Rtm_Start, Rtm_Stop (for same core), Rtm_MainFunction, Rtm_ClearMeasurementResults, Rtm_StartMeasurement,
 *          Rtm_StopMeasurement, Rtm_PrepareMPSettings
 * \length MEDIUM Some sub functions called in Rtm_MainFunction to control measurement. SHORT for other functions.
 * \endexclusivearea
 */

/**********************************************************************************************************************
 *  END OF FILE: Rtm.h
 *********************************************************************************************************************/

