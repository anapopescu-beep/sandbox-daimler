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
 *         File:  Rtm_Types.h
 *    Component:  -
 *       Module:  RTM
 *    Generator:  -
 *
 *  Description:  RTM static type definition header file.
 *  
 *********************************************************************************************************************/

#ifndef RTM_TYPES_H_
# define RTM_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "ComStack_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* ESCAN00078841 */
typedef uint32 Rtm_MeasurementTimestampType;

typedef struct
{
  uint32 time;
  uint32 count;
  Rtm_MeasurementTimestampType min;
  Rtm_MeasurementTimestampType max;
} Rtm_DataSet;

typedef struct
{
  uint32 execTime_Flat_EnableISRs;
  uint32 execTime_Flat_DisableISRs;
} Rtm_OverheadCorrectionType;

typedef struct
{
  uint32 Rtm_MFR_LastCall;
  uint32 Rtm_MFR_Delta;
  uint32 Rtm_MFR_Average;
  uint8  Rtm_MFR_AverageCounter;
} Rtm_MainFunctionRuntimeType;

typedef struct
{
  Rtm_MeasurementTimestampType Rtm_CLM_StartTimestamp;
  uint32  Rtm_CLM_Threshold;
  uint32  Rtm_CLM_CollectedTime;
  uint32  Rtm_CLM_LastTicks;
  boolean Rtm_CLM_MeasurementActive;
  boolean Rtm_CLM_MeasurementWasStopped;
  boolean Rtm_CLM_IsCpuLoadMPResultOverflown;
  uint8   Rtm_CLM_SendResult;
} Rtm_CpuLoadType;

/* ESCAN00079844 */
typedef enum
{
  RTM_ITEM_CPU_LOAD_AVERAGE  = 0u, /* The average result of CPU load measurement. */
  RTM_ITEM_CPU_LOAD_CURRENT  = 1u, /* The result of the latest CPU load measurement. */
  RTM_ITEM_MIN               = 2u, /* The minimum measurement time. */
  RTM_ITEM_MAX               = 3u, /* The maximum measurement time. */
  RTM_ITEM_RUNTIME_AVERAGE   = 4u, /* The average runtime. */
  RTM_ITEM_RUNTIME_OVERALL   = 5u  /* The overall runtime. */
} Rtm_ItemType;                    /* This type describes the requested measurement item type. */

typedef enum
{
  RTM_MP_SETTING_DISABLE_ALL    = 0u, /* Disables all MPs. */
  RTM_MP_SETTING_ENABLE_ALL     = 1u, /* Enables all MPs. */
  RTM_MP_SETTING_DEFAULT        = 2u, /* Sets the MP states depending on their Autostart settings.
                                       *  - The setting of ./RtmAutostartEnabled is used to decide. */
  RTM_MP_SETTING_DISABLE_ONE_MP = 3u, /* Disables one dedicated MP. */
  RTM_MP_SETTING_ENABLE_ONE_MP  = 4u  /* Enables one dedicated MP. */
} Rtm_MpSettingType;

typedef enum
{
  RTM_ALL_HISTOGRAM_AND_TASK_STACK_RESULTS = 0u,
  RTM_CPU_LOAD_HISTOGRAM_RESULTS = 1u,
  RTM_TASK_RESPONSE_TIME_RESULTS = 2u,
  RTM_TASK_STACK_USAGE_RESULTS = 3u
} Rtm_ClearResultsType;

typedef void (*Rtm_ThresholdCbkFctType) (Rtm_MeasurementTimestampType executionTime);

#endif /* RTM_TYPES_H_ */
