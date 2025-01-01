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
 *            Module: Rtm
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Rtm_Cfg.c
 *   Generation Time: 2024-03-04 18:59:17
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 1297 EOF */ /* MD_Rtm_1297 */
#include "Rtm.h"

/*lint -e546 */ /* Suppress ID546 because & is required for function pointer access */

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
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
  LOCAL DATA
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
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Rtm_CommonConst
**********************************************************************************************************************/
/** 
  \var    Rtm_CommonConst
  \brief  List of common const data
  \details
  Element                                Description
  BSWCore                                This flag defines the BSW Core
  CPULoadAutostart                       The autostart flag of the respective MP
  CpuLoadNvMHandleUsed                   A flag indicating the availability of a handle
  TaskResponseTimeNvMHandleUsed          A flag indicating the availability of a handle
  ActivatedMPIdOfCPULoad                 The activated MP id of CPU load
  ConfiguredMPIdOfCPULoad                The configured MP id of CPU
  CoreId                                 The id of the respective CPU Load MP Core Id
  NumberofTaskResponseTimePercentiles    This is the number of percentiles for Response Time Data
  NvMCpuLoadBlockSnv                     The CPU Load NvM Block SNV
  NvMTaskResponseTimeBlockSnv            The Task Response Time NvM Block SNV
  OsTaskInfoEndIdx                       the end index of the 0:n relation pointing to Rtm_OsTaskInfo
  OsTaskInfoLength                       the number of relations pointing to Rtm_OsTaskInfo
  OsTaskInfoStartIdx                     the start index of the 0:n relation pointing to Rtm_OsTaskInfo
  PartitionIndexOfCslStringSNV           The Core index
  TaskResponseTimeDataPtr                This ptr defines the var struct of Response Time Data
*/ 
#define RTM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Rtm_CommonConstType, RTM_CONST) Rtm_CommonConst[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BSWCore  CPULoadAutostart  CpuLoadNvMHandleUsed  TaskResponseTimeNvMHandleUsed  ActivatedMPIdOfCPULoad  ConfiguredMPIdOfCPULoad  CoreId  NumberofTaskResponseTimePercentiles  NvMCpuLoadBlockSnv                                     NvMTaskResponseTimeBlockSnv                      OsTaskInfoEndIdx  OsTaskInfoLength  OsTaskInfoStartIdx  PartitionIndexOfCslStringSNV                 TaskResponseTimeDataPtr             Referable Keys */
  { /*     0 */    TRUE,             TRUE,                 TRUE,                         FALSE,                    36u,                     36u,     0u,                                 10u, NvMConf_NvMBlockDescriptor_Rtm_CpuLoadPersistencyData, RTM_NO_NVMTASKRESPONSETIMEBLOCKSNVOFCOMMONCONST,              11u,              11u,                 0u, RtmConf_RtmCoreDefinition_RtmCoreDefinition, Rtm_TaskResponseTimeStruct_0 }   /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
};
#define RTM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_IndexToOsTaskInfo
**********************************************************************************************************************/
/** 
  \var    Rtm_IndexToOsTaskInfo
  \brief  List of indexes to Os task Infos
  \details
  Element                  Description
  TaskIndexToOsTaskInfo    This is the index to Os TaskId
*/ 
#define RTM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Rtm_IndexToOsTaskInfoType, RTM_CONST) Rtm_IndexToOsTaskInfo[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TaskIndexToOsTaskInfo */
  { /*     0 */                    0u },
  { /*     1 */                    1u },
  { /*     2 */                    2u },
  { /*     3 */                    3u },
  { /*     4 */                    4u },
  { /*     5 */                    5u },
  { /*     6 */                    6u },
  { /*     7 */                    7u },
  { /*     8 */                    8u },
  { /*     9 */                    9u },
  { /*    10 */                   10u }
};
#define RTM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_OsTaskInfo
**********************************************************************************************************************/
/** 
  \var    Rtm_OsTaskInfo
  \brief  List of Os task Infos
  \details
  Element     Description
  MaxStack    This is the max stack for this task
  TaskId      This is the Os TaskId
*/ 
#define RTM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Rtm_OsTaskInfoType, RTM_CONST) Rtm_OsTaskInfo[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaxStack  TaskId                             Referable Keys */
  { /*     0 */    4096u,    ApplBackgroundTask_Core0 },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     1 */     512u,          ApplInitTask_Core0 },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     2 */     512u,     ApplTask_Core0_HighPrio },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     3 */    1536u,      ApplTask_Core0_LowPrio },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     4 */    3584u,        BackgroundTask_Core0 },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     5 */    2048u,      BswTask_Core0_HighPrio },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     6 */    4096u,       BswTask_Core0_LowPrio },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     7 */    1024u,           Default_Init_Task },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     8 */     256u,   Default_Init_Task_Trusted },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*     9 */      64u,            IdleTask_OsCore0 },  /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
  { /*    10 */     512u, OsTask_ALV_BeltFunctionAlgo }   /* [/ActiveEcuC/Rtm/RtmCoreDefinition] */
};
#define RTM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_CpuLoadData
**********************************************************************************************************************/
/** 
  \var    Rtm_CpuLoadData
  \details
  Element                       Description
  CollectedTime                 Collected Time
  LastTicks                     Last Ticks
  StartTimeStamp                Start Timestamp
  Threshold                     Threshold
  IsCpuLoadMPResultOverflown    Result Overflown
  MeasurementActive             Measurement Active
  MeasurementWasStopped         Measurement was Stopped
  SendResult                    Send Result
*/ 
#define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_CpuLoadDataType, RTM_VAR_NO_INIT) Rtm_CpuLoadData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_CpuLoadPersistencyData
**********************************************************************************************************************/
/** 
  \var    Rtm_CpuLoadPersistencyData
  \details
  Element                          Description
  CpuLoadOverallPercentileCount    The percentile count
  CpuLoadPercentiles               the percentile list
*/ 
#define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_CpuLoadPersistencyDataType, RTM_VAR_NO_INIT) Rtm_CpuLoadPersistencyData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_CpuLoadTime
**********************************************************************************************************************/
/** 
  \var    Rtm_CpuLoadTime
  \brief  CpuLoadTime
*/ 
#define RTM_START_SEC_VAR_NO_INIT_32
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_CpuLoadTimeType, RTM_VAR_NO_INIT) Rtm_CpuLoadTime;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_32
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_HyperPeriodData
**********************************************************************************************************************/
/** 
  \var    Rtm_HyperPeriodData
  \details
  Element                Description
  AccumulatedTime        The accumulated time
  MainFunctionCounter    MainFunction Counter
*/ 
#define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_HyperPeriodDataType, RTM_VAR_NO_INIT) Rtm_HyperPeriodData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Rtm_MainFunctionRuntimeData
**********************************************************************************************************************/
/** 
  \var    Rtm_MainFunctionRuntimeData
  \details
  Element           Description
  Average           Average
  Delta             Delta
  LastCall          Last Call
  AverageCounter    AverageCounter
*/ 
#define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Rtm_MainFunctionRuntimeDataType, RTM_VAR_NO_INIT) Rtm_MainFunctionRuntimeData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Rtm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



# define RTM_START_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

VAR(uint8, RTM_VAR_INIT) Rtm_InitState[RTM_NUMBER_OF_CORES] = {
  RTM_UNINITIALIZED
};

# define RTM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


#if (RTM_TIME_MEASUREMENT == STD_ON)
# define RTM_START_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

VAR(sint8, RTM_VAR_INIT) Rtm_MeasurementNestingCtr[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  0x00 /* Measurement Id: 0 */, 
  0x00 /* Measurement Id: 1 */, 
  0x00 /* Measurement Id: 2 */, 
  0x00 /* Measurement Id: 3 */, 
  0x00 /* Measurement Id: 4 */, 
  0x00 /* Measurement Id: 5 */, 
  0x00 /* Measurement Id: 6 */, 
  0x00 /* Measurement Id: 7 */, 
  0x00 /* Measurement Id: 8 */, 
  0x00 /* Measurement Id: 9 */, 
  0x00 /* Measurement Id: 10 */, 
  0x00 /* Measurement Id: 11 */, 
  0x00 /* Measurement Id: 12 */, 
  0x00 /* Measurement Id: 13 */, 
  0x00 /* Measurement Id: 14 */, 
  0x00 /* Measurement Id: 15 */, 
  0x00 /* Measurement Id: 16 */, 
  0x00 /* Measurement Id: 17 */, 
  0x00 /* Measurement Id: 18 */, 
  0x00 /* Measurement Id: 19 */, 
  0x00 /* Measurement Id: 20 */, 
  0x00 /* Measurement Id: 21 */, 
  0x00 /* Measurement Id: 22 */, 
  0x00 /* Measurement Id: 23 */, 
  0x00 /* Measurement Id: 24 */, 
  0x00 /* Measurement Id: 25 */, 
  0x00 /* Measurement Id: 26 */, 
  0x00 /* Measurement Id: 27 */, 
  0x00 /* Measurement Id: 28 */, 
  0x00 /* Measurement Id: 29 */, 
  0x00 /* Measurement Id: 30 */, 
  0x00 /* Measurement Id: 31 */, 
  0x00 /* Measurement Id: 32 */, 
  0x00 /* Measurement Id: 33 */, 
  0x00 /* Measurement Id: 34 */, 
  0x00 /* Measurement Id: 35 */, 
  0x00 /* Measurement Id: 36 */, 
  0x00 /* Measurement Id: 37 */, 
  0x00 /* Measurement Id: 38 */, 
  0x00 /* Measurement Id: 39 */, 
  0x00 /* Measurement Id: 40 */, 
  0x00 /* Measurement Id: 41 */, 
  0x00 /* Measurement Id: 42 */, 
  0x00 /* Measurement Id: 43 */, 
  0x00 /* Measurement Id: 44 */, 
  0x00 /* Measurement Id: 45 */, 
  0x00 /* Measurement Id: 46 */, 
  0x00 /* Measurement Id: 47 */
};

VAR(uint8, RTM_VAR_INIT) Rtm_Ctrl[RTM_CTRL_VECTOR_LEN] = 
{
  0x00u, 
  0x00u, 
  0x00u, 
  0x00u, 
  0xF0u, 
  0xFFu
};

VAR(uint8, RTM_VAR_INIT) Rtm_MeasurementConfig[RTM_CTRL_VECTOR_LEN] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};

VAR(Rtm_MeasurementTimestampType, RTM_VAR_INIT) Rtm_StartTimeStamps[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 0 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 1 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 2 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 3 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 4 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 5 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 6 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 7 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 8 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 9 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 10 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 11 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 12 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 13 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 14 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 15 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 16 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 17 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 18 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 19 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 20 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 21 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 22 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 23 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 24 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 25 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 26 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 27 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 28 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 29 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 30 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 31 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 32 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 33 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 34 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 35 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 36 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 37 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 38 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 39 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 40 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 41 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 42 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 43 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 44 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 45 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 46 */, 
  (Rtm_MeasurementTimestampType) 0x00 /* Measurement Id: 47 */
};

VAR(Rtm_DataSet, RTM_VAR_INIT) Rtm_Results[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 0, Measurement Name: Rtm_Overhead_GrossExecutionTime_EnableISRs */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 1, Measurement Name: Rtm_Overhead_GrossExecutionTime_DisableISRs */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 2, Measurement Name: CANNM_SID_CHECKREMOTESLEEPIND */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 3, Measurement Name: CANNM_SID_CONFIRMPNAVAILABILITY */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 4, Measurement Name: CANNM_SID_DISABLECOMMUNICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 5, Measurement Name: CANNM_SID_ENABLECOMMUNICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 6, Measurement Name: CANNM_SID_GETSTATE */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 7, Measurement Name: CANNM_SID_INIT */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 8, Measurement Name: CANNM_SID_MAINFUNCTION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 9, Measurement Name: CANNM_SID_NETWORKRELEASE */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 10, Measurement Name: CANNM_SID_NETWORKREQUEST */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 11, Measurement Name: CANNM_SID_PASSIVESTARTUP */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 12, Measurement Name: CANNM_SID_RXINDICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 13, Measurement Name: CANNM_SID_TRANSMIT */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 14, Measurement Name: CANNM_SID_TXCONFIRMATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 15, Measurement Name: CanInterrupt */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 16, Measurement Name: Can_Init */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 17, Measurement Name: Can_SetControllerMode */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 18, Measurement Name: Can_Write */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 19, Measurement Name: NM_SID_BUSSLEEPMODE */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 20, Measurement Name: NM_SID_CHECKREMOTESLEEPINDICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 21, Measurement Name: NM_SID_DISABLECOMMUNICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 22, Measurement Name: NM_SID_ENABLECOMMUNICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 23, Measurement Name: NM_SID_GETSTATE */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 24, Measurement Name: NM_SID_INIT */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 25, Measurement Name: NM_SID_MAINFUNCTION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 26, Measurement Name: NM_SID_NETWORKMODE */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 27, Measurement Name: NM_SID_NETWORKRELEASE */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 28, Measurement Name: NM_SID_NETWORKREQUEST */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 29, Measurement Name: NM_SID_NETWORKSTARTINDICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 30, Measurement Name: NM_SID_PASSIVESTARTUP */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 31, Measurement Name: NM_SID_PREPAREBUSSLEEPMODE */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 32, Measurement Name: NM_SID_REMOTESLEEPCANCELLATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 33, Measurement Name: NM_SID_REMOTESLEEPINDICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 34, Measurement Name: NM_SID_STATECHANGENOTIFICATION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 35, Measurement Name: NM_SID_TXTIMEOUTEXCEPTION */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 36, Measurement Name: Rtm_CpuLoadMeasurement */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 37, Measurement Name: Task_ApplBackgroundTask_Core0 */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 38, Measurement Name: Task_ApplInitTask_Core0 */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 39, Measurement Name: Task_ApplTask_Core0_HighPrio */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 40, Measurement Name: Task_ApplTask_Core0_LowPrio */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 41, Measurement Name: Task_BackgroundTask_Core0 */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 42, Measurement Name: Task_BswTask_Core0_HighPrio */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 43, Measurement Name: Task_BswTask_Core0_LowPrio */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 44, Measurement Name: Task_Default_Init_Task */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 45, Measurement Name: Task_Default_Init_Task_Trusted */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 46, Measurement Name: Task_IdleTask_OsCore0 */, 
  {0u, 0u, (Rtm_MeasurementTimestampType) 0xFFFFFFFFu, 0u} /* Measurement Id: 47, Measurement Name: Task_OsTask_ALV_BeltFunctionAlgo */
};


# define RTM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

# define RTM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

VAR(Rtm_TaskResponseTimeStructType, RTM_VAR_NO_INIT) Rtm_TaskResponseTimeStruct_0[RTM_NUMBER_OF_TASKS_ON_CORE_0];

# define RTM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


# define RTM_START_SEC_CONST_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

CONST(uint32, RTM_CONST) Rtm_ThresholdTimes[RTM_NUMBER_OF_ACTIVATED_MPS] =
{
  0x00000000u /* Measurement Id: 0 */, 
  0x00000000u /* Measurement Id: 1 */, 
  0x00000000u /* Measurement Id: 2 */, 
  0x00000000u /* Measurement Id: 3 */, 
  0x00000000u /* Measurement Id: 4 */, 
  0x00000000u /* Measurement Id: 5 */, 
  0x00000000u /* Measurement Id: 6 */, 
  0x00000000u /* Measurement Id: 7 */, 
  0x00000000u /* Measurement Id: 8 */, 
  0x00000000u /* Measurement Id: 9 */, 
  0x00000000u /* Measurement Id: 10 */, 
  0x00000000u /* Measurement Id: 11 */, 
  0x00000000u /* Measurement Id: 12 */, 
  0x00000000u /* Measurement Id: 13 */, 
  0x00000000u /* Measurement Id: 14 */, 
  0x00000000u /* Measurement Id: 15 */, 
  0x00000000u /* Measurement Id: 16 */, 
  0x00000000u /* Measurement Id: 17 */, 
  0x00000000u /* Measurement Id: 18 */, 
  0x00000000u /* Measurement Id: 19 */, 
  0x00000000u /* Measurement Id: 20 */, 
  0x00000000u /* Measurement Id: 21 */, 
  0x00000000u /* Measurement Id: 22 */, 
  0x00000000u /* Measurement Id: 23 */, 
  0x00000000u /* Measurement Id: 24 */, 
  0x00000000u /* Measurement Id: 25 */, 
  0x00000000u /* Measurement Id: 26 */, 
  0x00000000u /* Measurement Id: 27 */, 
  0x00000000u /* Measurement Id: 28 */, 
  0x00000000u /* Measurement Id: 29 */, 
  0x00000000u /* Measurement Id: 30 */, 
  0x00000000u /* Measurement Id: 31 */, 
  0x00000000u /* Measurement Id: 32 */, 
  0x00000000u /* Measurement Id: 33 */, 
  0x00000000u /* Measurement Id: 34 */, 
  0x00000000u /* Measurement Id: 35 */, 
  0x00000000u /* Measurement Id: 36 */, 
  0x00000000u /* Measurement Id: 37 */, 
  0x00000000u /* Measurement Id: 38 */, 
  0x00000000u /* Measurement Id: 39 */, 
  0x00000000u /* Measurement Id: 40 */, 
  0x00000000u /* Measurement Id: 41 */, 
  0x00000000u /* Measurement Id: 42 */, 
  0x00000000u /* Measurement Id: 43 */, 
  0x00000000u /* Measurement Id: 44 */, 
  0x00000000u /* Measurement Id: 45 */, 
  0x00000000u /* Measurement Id: 46 */, 
  0x00000000u /* Measurement Id: 47 */
};

CONST(Rtm_ThresholdCbkFctType, RTM_CONST) Rtm_ThresholdCbkFctArr[RTM_NUMBER_OF_ACTIVATED_MPS] =
{
  NULL_PTR /* Measurement Id: 0 */, 
  NULL_PTR /* Measurement Id: 1 */, 
  NULL_PTR /* Measurement Id: 2 */, 
  NULL_PTR /* Measurement Id: 3 */, 
  NULL_PTR /* Measurement Id: 4 */, 
  NULL_PTR /* Measurement Id: 5 */, 
  NULL_PTR /* Measurement Id: 6 */, 
  NULL_PTR /* Measurement Id: 7 */, 
  NULL_PTR /* Measurement Id: 8 */, 
  NULL_PTR /* Measurement Id: 9 */, 
  NULL_PTR /* Measurement Id: 10 */, 
  NULL_PTR /* Measurement Id: 11 */, 
  NULL_PTR /* Measurement Id: 12 */, 
  NULL_PTR /* Measurement Id: 13 */, 
  NULL_PTR /* Measurement Id: 14 */, 
  NULL_PTR /* Measurement Id: 15 */, 
  NULL_PTR /* Measurement Id: 16 */, 
  NULL_PTR /* Measurement Id: 17 */, 
  NULL_PTR /* Measurement Id: 18 */, 
  NULL_PTR /* Measurement Id: 19 */, 
  NULL_PTR /* Measurement Id: 20 */, 
  NULL_PTR /* Measurement Id: 21 */, 
  NULL_PTR /* Measurement Id: 22 */, 
  NULL_PTR /* Measurement Id: 23 */, 
  NULL_PTR /* Measurement Id: 24 */, 
  NULL_PTR /* Measurement Id: 25 */, 
  NULL_PTR /* Measurement Id: 26 */, 
  NULL_PTR /* Measurement Id: 27 */, 
  NULL_PTR /* Measurement Id: 28 */, 
  NULL_PTR /* Measurement Id: 29 */, 
  NULL_PTR /* Measurement Id: 30 */, 
  NULL_PTR /* Measurement Id: 31 */, 
  NULL_PTR /* Measurement Id: 32 */, 
  NULL_PTR /* Measurement Id: 33 */, 
  NULL_PTR /* Measurement Id: 34 */, 
  NULL_PTR /* Measurement Id: 35 */, 
  NULL_PTR /* Measurement Id: 36 */, 
  NULL_PTR /* Measurement Id: 37 */, 
  NULL_PTR /* Measurement Id: 38 */, 
  NULL_PTR /* Measurement Id: 39 */, 
  NULL_PTR /* Measurement Id: 40 */, 
  NULL_PTR /* Measurement Id: 41 */, 
  NULL_PTR /* Measurement Id: 42 */, 
  NULL_PTR /* Measurement Id: 43 */, 
  NULL_PTR /* Measurement Id: 44 */, 
  NULL_PTR /* Measurement Id: 45 */, 
  NULL_PTR /* Measurement Id: 46 */, 
  NULL_PTR /* Measurement Id: 47 */
};

CONST(uint8, RTM_CONST) Rtm_CtrlConfig[RTM_CTRL_VECTOR_LEN] = 
{
  0x00u, 
  0x00u, 
  0x00u, 
  0x00u, 
  0xF0u, 
  0xFFu
};


CONST(Rtm_MeasurementPointConfigType, RTM_CONST) Rtm_MeasurementPointConfigInfo[RTM_NUMBER_OF_ACTIVATED_MPS] = 
{
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 0, Measurement Name: Rtm_Overhead_GrossExecutionTime_EnableISRs */, 
  {0u, TRUE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 1, Measurement Name: Rtm_Overhead_GrossExecutionTime_DisableISRs */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 2, Measurement Name: CANNM_SID_CHECKREMOTESLEEPIND */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 3, Measurement Name: CANNM_SID_CONFIRMPNAVAILABILITY */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 4, Measurement Name: CANNM_SID_DISABLECOMMUNICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 5, Measurement Name: CANNM_SID_ENABLECOMMUNICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 6, Measurement Name: CANNM_SID_GETSTATE */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 7, Measurement Name: CANNM_SID_INIT */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 8, Measurement Name: CANNM_SID_MAINFUNCTION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 9, Measurement Name: CANNM_SID_NETWORKRELEASE */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 10, Measurement Name: CANNM_SID_NETWORKREQUEST */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 11, Measurement Name: CANNM_SID_PASSIVESTARTUP */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 12, Measurement Name: CANNM_SID_RXINDICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 13, Measurement Name: CANNM_SID_TRANSMIT */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 14, Measurement Name: CANNM_SID_TXCONFIRMATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 15, Measurement Name: CanInterrupt */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 16, Measurement Name: Can_Init */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 17, Measurement Name: Can_SetControllerMode */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 18, Measurement Name: Can_Write */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 19, Measurement Name: NM_SID_BUSSLEEPMODE */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 20, Measurement Name: NM_SID_CHECKREMOTESLEEPINDICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 21, Measurement Name: NM_SID_DISABLECOMMUNICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 22, Measurement Name: NM_SID_ENABLECOMMUNICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 23, Measurement Name: NM_SID_GETSTATE */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 24, Measurement Name: NM_SID_INIT */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 25, Measurement Name: NM_SID_MAINFUNCTION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 26, Measurement Name: NM_SID_NETWORKMODE */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 27, Measurement Name: NM_SID_NETWORKRELEASE */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 28, Measurement Name: NM_SID_NETWORKREQUEST */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 29, Measurement Name: NM_SID_NETWORKSTARTINDICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 30, Measurement Name: NM_SID_PASSIVESTARTUP */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 31, Measurement Name: NM_SID_PREPAREBUSSLEEPMODE */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 32, Measurement Name: NM_SID_REMOTESLEEPCANCELLATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 33, Measurement Name: NM_SID_REMOTESLEEPINDICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 34, Measurement Name: NM_SID_STATECHANGENOTIFICATION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_RUNTIME, 0, 0u} /* Measurement Id: 35, Measurement Name: NM_SID_TXTIMEOUTEXCEPTION */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_CPU_LOAD, 0, 0u} /* Measurement Id: 36, Measurement Name: Rtm_CpuLoadMeasurement */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 0, 0u} /* Measurement Id: 37, Measurement Name: Task_ApplBackgroundTask_Core0 */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 1, 0u} /* Measurement Id: 38, Measurement Name: Task_ApplInitTask_Core0 */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 2, 0u} /* Measurement Id: 39, Measurement Name: Task_ApplTask_Core0_HighPrio */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 3, 0u} /* Measurement Id: 40, Measurement Name: Task_ApplTask_Core0_LowPrio */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 4, 0u} /* Measurement Id: 41, Measurement Name: Task_BackgroundTask_Core0 */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 5, 0u} /* Measurement Id: 42, Measurement Name: Task_BswTask_Core0_HighPrio */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 6, 0u} /* Measurement Id: 43, Measurement Name: Task_BswTask_Core0_LowPrio */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 7, 0u} /* Measurement Id: 44, Measurement Name: Task_Default_Init_Task */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 8, 0u} /* Measurement Id: 45, Measurement Name: Task_Default_Init_Task_Trusted */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 9, 0u} /* Measurement Id: 46, Measurement Name: Task_IdleTask_OsCore0 */, 
  {0u, FALSE, RTM_MEASUREMENT_TYPE_GROSS_EXECUTIONTIME, RTM_MP_TYPE_TASK, 10, 0u} /* Measurement Id: 47, Measurement Name: Task_OsTask_ALV_BeltFunctionAlgo */
};

CONST(uint32, RTM_CONST) Rtm_ConfiguredToActivatedMPIds[RTM_NUMBER_OF_CONFIGURED_MPS] = 
{
  0x00000000u /* Measurement Id: 0, Measurement Name: Rtm_Overhead_GrossExecutionTime_EnableISRs */, 
  0x00000001u /* Measurement Id: 1, Measurement Name: Rtm_Overhead_GrossExecutionTime_DisableISRs */, 
  0x00000002u /* Measurement Id: 2, Measurement Name: CANNM_SID_CHECKREMOTESLEEPIND */, 
  0x00000003u /* Measurement Id: 3, Measurement Name: CANNM_SID_CONFIRMPNAVAILABILITY */, 
  0x00000004u /* Measurement Id: 4, Measurement Name: CANNM_SID_DISABLECOMMUNICATION */, 
  0x00000005u /* Measurement Id: 5, Measurement Name: CANNM_SID_ENABLECOMMUNICATION */, 
  0x00000006u /* Measurement Id: 6, Measurement Name: CANNM_SID_GETSTATE */, 
  0x00000007u /* Measurement Id: 7, Measurement Name: CANNM_SID_INIT */, 
  0x00000008u /* Measurement Id: 8, Measurement Name: CANNM_SID_MAINFUNCTION */, 
  0x00000009u /* Measurement Id: 9, Measurement Name: CANNM_SID_NETWORKRELEASE */, 
  0x0000000au /* Measurement Id: 10, Measurement Name: CANNM_SID_NETWORKREQUEST */, 
  0x0000000bu /* Measurement Id: 11, Measurement Name: CANNM_SID_PASSIVESTARTUP */, 
  0x0000000cu /* Measurement Id: 12, Measurement Name: CANNM_SID_RXINDICATION */, 
  0x0000000du /* Measurement Id: 13, Measurement Name: CANNM_SID_TRANSMIT */, 
  0x0000000eu /* Measurement Id: 14, Measurement Name: CANNM_SID_TXCONFIRMATION */, 
  0x0000000fu /* Measurement Id: 15, Measurement Name: CanInterrupt */, 
  0x00000010u /* Measurement Id: 16, Measurement Name: Can_Init */, 
  0x00000011u /* Measurement Id: 17, Measurement Name: Can_SetControllerMode */, 
  0x00000012u /* Measurement Id: 18, Measurement Name: Can_Write */, 
  0x00000013u /* Measurement Id: 19, Measurement Name: NM_SID_BUSSLEEPMODE */, 
  0x00000014u /* Measurement Id: 20, Measurement Name: NM_SID_CHECKREMOTESLEEPINDICATION */, 
  0x00000015u /* Measurement Id: 21, Measurement Name: NM_SID_DISABLECOMMUNICATION */, 
  0x00000016u /* Measurement Id: 22, Measurement Name: NM_SID_ENABLECOMMUNICATION */, 
  0x00000017u /* Measurement Id: 23, Measurement Name: NM_SID_GETSTATE */, 
  0x00000018u /* Measurement Id: 24, Measurement Name: NM_SID_INIT */, 
  0x00000019u /* Measurement Id: 25, Measurement Name: NM_SID_MAINFUNCTION */, 
  0x0000001au /* Measurement Id: 26, Measurement Name: NM_SID_NETWORKMODE */, 
  0x0000001bu /* Measurement Id: 27, Measurement Name: NM_SID_NETWORKRELEASE */, 
  0x0000001cu /* Measurement Id: 28, Measurement Name: NM_SID_NETWORKREQUEST */, 
  0x0000001du /* Measurement Id: 29, Measurement Name: NM_SID_NETWORKSTARTINDICATION */, 
  0x0000001eu /* Measurement Id: 30, Measurement Name: NM_SID_PASSIVESTARTUP */, 
  0x0000001fu /* Measurement Id: 31, Measurement Name: NM_SID_PREPAREBUSSLEEPMODE */, 
  0x00000020u /* Measurement Id: 32, Measurement Name: NM_SID_REMOTESLEEPCANCELLATION */, 
  0x00000021u /* Measurement Id: 33, Measurement Name: NM_SID_REMOTESLEEPINDICATION */, 
  0x00000022u /* Measurement Id: 34, Measurement Name: NM_SID_STATECHANGENOTIFICATION */, 
  0x00000023u /* Measurement Id: 35, Measurement Name: NM_SID_TXTIMEOUTEXCEPTION */, 
  0x00000024u /* Measurement Id: 36, Measurement Name: Rtm_CpuLoadMeasurement */, 
  0x00000025u /* Measurement Id: 37, Measurement Name: Task_ApplBackgroundTask_Core0 */, 
  0x00000026u /* Measurement Id: 38, Measurement Name: Task_ApplInitTask_Core0 */, 
  0x00000027u /* Measurement Id: 39, Measurement Name: Task_ApplTask_Core0_HighPrio */, 
  0x00000028u /* Measurement Id: 40, Measurement Name: Task_ApplTask_Core0_LowPrio */, 
  0x00000029u /* Measurement Id: 41, Measurement Name: Task_BackgroundTask_Core0 */, 
  0x0000002au /* Measurement Id: 42, Measurement Name: Task_BswTask_Core0_HighPrio */, 
  0x0000002bu /* Measurement Id: 43, Measurement Name: Task_BswTask_Core0_LowPrio */, 
  0x0000002cu /* Measurement Id: 44, Measurement Name: Task_Default_Init_Task */, 
  0x0000002du /* Measurement Id: 45, Measurement Name: Task_Default_Init_Task_Trusted */, 
  0x0000002eu /* Measurement Id: 46, Measurement Name: Task_IdleTask_OsCore0 */, 
  0x0000002fu /* Measurement Id: 47, Measurement Name: Task_OsTask_ALV_BeltFunctionAlgo */
};

# define RTM_STOP_SEC_CONST_UNSPECIFIED
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */


# define RTM_START_SEC_CODE
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * Rtm_SetCpuLoadTimeOfCore()
 *********************************************************************************************************************/
/*!
 *
 * \internal
 * - #10 Set the cpu load time to new value.
 * \endinternal
 */
FUNC(void, RTM_CODE) Rtm_SetCpuLoadTimeOfCore(const uint16 CoreIndex, const uint32 NewCpuLoadTime)
{
  /* ----- Implementation -------------------------------------------------------------------- */
  /* #10 Set the cpu load time to new value. */
  Rtm_SetCpuLoadTime(NewCpuLoadTime);
  RTM_DUMMY_STATEMENT_CONST(CoreIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */
} /* Rtm_SetCpuLoadTimeOfCore */

/**********************************************************************************************************************
 * Rtm_GetCpuLoadTimeOfCore()
 *********************************************************************************************************************/
/*!
 *
 * \internal
 * - #10 Get the cpu load time.
 * \endinternal
 */
FUNC(uint32, RTM_CODE) Rtm_GetCpuLoadTimeOfCore(const uint16 CoreIndex)
{
  /* ----- Implementation -------------------------------------------------------------------- */
  /* #10 Get the cpu load time. */
  RTM_DUMMY_STATEMENT_CONST(CoreIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e438 */
  return Rtm_GetCpuLoadTime();
} /* Rtm_GetCpuLoadTimeOfCore */

# define RTM_STOP_SEC_CODE
# include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* RTM_TIME_MEASUREMENT == STD_ON */



