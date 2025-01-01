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
 *            Module: Dem
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_Lcfg.c
 *   Generation Time: 2024-02-14 08:40:23
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/



/* configuration, interrupt handling implementations differ from the
 * source identification define used here. The naming
 * schemes for those files can be taken from this list:
 *
 * Dem.c:         DEM_SOURCE
 * Dem_Lcfg.c:    DEM_LCFG_SOURCE
 * Dem_PBcfg.c:   DEM_PBCFG_SOURCE */
#define DEM_LCFG_SOURCE


/**********************************************************************************************************************
  MISRA JUSTIFICATIONS
**********************************************************************************************************************/

/* PRQA S 0828 EOF */ /* MD_MSR_1.1_828 */                                      /* Maximum '#if...' nesting exceeds 8 levels - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */                                      /* Number of macro definitions exceeds 1024 - program is non-conforming -- caused by #include'd files. */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */                                          /* Identifier does not differ in 32 significant characters -- caused by Autosar algorithm for unique symbolic names. */
/* PRQA S 0612 EOF */ /* MD_DEM_1.1_612 */                                      /* The size of an object exceeds 32767 bytes - program is non-conforming -- caused by large user configuration. */
/* PRQA S 0613 EOF */ /* MD_DEM_613 */                                          /* The size of an object exceeds 65535 bytes - program is non-conforming -- caused by large user configuration. */


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "Dem.h"
#include "Os.h"
#if (DEM_CFG_USE_NVM == STD_ON)
# include "NvM.h"                                                               /* get: symbolic names for NvM block IDs */
#endif
#if (DEM_CFG_SUPPORT_J1939 == STD_ON)
# include "J1939Nm.h"                                                           /* get: symbolic names for J1939Nm node IDs */
#endif
#if (DEM_CFG_USE_RTE == STD_ON)
/* DEM used with RTE */
# include "Rte_DemMaster_0.h"
#endif
#include "Dem_AdditionalIncludeCfg.h"                                           /* additional, configuration defined files */

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

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
  Dem_Cfg_CallbackDtcStatusChanged
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_DtcStatusChangedFPtrType, DEM_CONST) Dem_Cfg_CallbackDtcStatusChanged[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CallbackDtcStatusChanged                        */
  /*     0 */ Rte_Call_CBStatusDTC_RoELight_DTCStatusChanged 
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ClearDtcNotificationFinishTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ClearDtcNotificationFinishTable
  \brief  ClearDTCNotification callback functions which are called when FINISHing a clear DTC operation.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_ClearDtcNotificationFPtrType, DEM_CONST) Dem_Cfg_ClearDtcNotificationFinishTable[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ClearDtcNotificationFinishTable                    Comment */
  /*     0 */ Dem_ClearDTC_Callback_Notification_StartClear    /* [DemEventMemorySet_DemClearDTCNotification] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CycleIdTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_CycleIdTable
  \details
  Element        Description
  MaskedBits     contains bitcoded the boolean data of Dem_Cfg_EndsOnInitOfCycleIdTable, Dem_Cfg_UsedForAgingOfCycleIdTable
  OpCycleType    DemOperationCycleType of the DemOperationCycle: [DEM_CFG_OPCYC_IGNITION, DEM_CFG_OPCYC_OBD_DCY, DEM_CFG_OPCYC_OTHER, DEM_CFG_OPCYC_POWER, DEM_CFG_OPCYC_TIME, DEM_CFG_OPCYC_WARMUP, DEM_CFG_OPCYC_IGNITION_HYBRID, DEM_CFG_OPCYC_AGING]
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_CycleIdTableType, DEM_CONST) Dem_Cfg_CycleIdTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  OpCycleType                   Comment */
  { /*     0 */      0x01u, DEM_CFG_OPCYC_IGNITION },  /* [DemConf_DemOperationCycle_IgnitionCycle] */
  { /*     1 */      0x00u, DEM_CFG_OPCYC_POWER    }   /* [DemConf_DemOperationCycle_PowerCycle] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTable
  \details
  Element                                Description
  IdNumber                           
  CollectionSize                     
  DataElementTableCol2ElmtIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataElementTableCol2ElmtInd
  DataElementTableCol2ElmtIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataElementTableCol2ElmtInd
  StorageKind                        
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableType, DEM_CONST) Dem_Cfg_DataCollectionTable[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IdNumber  CollectionSize  DataElementTableCol2ElmtIndEndIdx                                  DataElementTableCol2ElmtIndStartIdx                                  StorageKind                       Referable Keys */
  { /*     0 */  0x0000u,             0u, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDENDIDXOFDATACOLLECTIONTABLE, DEM_CFG_NO_DATAELEMENTTABLECOL2ELMTINDSTARTIDXOFDATACOLLECTIONTABLE, DEM_CFG_EREC_TYPE_GLOBAL   },  /* [#NoDataCollectionConfigured] */
  { /*     1 */  0x0001u,             4u,                                                                4u,                                                                  0u, DEM_CFG_EREC_TYPE_INTERNAL },  /* [#EdrExtendedDataRecord_StandardEnvironmentData, Ext:ExtendedDataClass_dda5abf3, #ExtendedDataRecord] */
  { /*     2 */  0x018Bu,             2u,                                                                5u,                                                                  4u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidDID_0x18b, Ffm:FreezeFrame_b430d746] */
  { /*     3 */  0xFD05u,             1u,                                                                6u,                                                                  5u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidDID_0xfd05, Ffm:FreezeFrame_8035c374, Ffm:FreezeFrame_b430d746] */
  { /*     4 */  0x0133u,             5u,                                                                8u,                                                                  6u, DEM_CFG_EREC_TYPE_USER     },  /* [#DidDID_Current_Operating_Time_Read_0x133, Ffm:FreezeFrame_8035c374, Ffm:FreezeFrame_b430d746] */
  { /*     5 */  0x010Au,             2u,                                                                9u,                                                                  8u, DEM_CFG_EREC_TYPE_USER     }   /* [#DidDID_Vehicle_Odometer_in_Low_Resolution_Read_0x10a, Ffm:FreezeFrame_8035c374, Ffm:FreezeFrame_b430d746] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataCollectionTableFfm2CollInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataCollectionTableFfm2CollInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataCollectionTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataCollectionTableFfm2CollIndType, DEM_CONST) Dem_Cfg_DataCollectionTableFfm2CollInd[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataCollectionTableFfm2CollInd      Referable Keys */
  /*     0 */                              5u,  /* [Ffm:FreezeFrame_8035c374] */
  /*     1 */                              4u,  /* [Ffm:FreezeFrame_8035c374] */
  /*     2 */                              3u,  /* [Ffm:FreezeFrame_8035c374] */
  /*     3 */                              5u,  /* [Ffm:FreezeFrame_b430d746] */
  /*     4 */                              4u,  /* [Ffm:FreezeFrame_b430d746] */
  /*     5 */                              2u,  /* [Ffm:FreezeFrame_b430d746] */
  /*     6 */                              3u   /* [Ffm:FreezeFrame_b430d746] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTable
  \details
  Element            Description
  ElementDataType    DataElement data type, returned by Dem_Cfg_DataElementDataType()
  ElementKind        DataElement kind, returned by Dem_Cfg_DataCallbackType()
  ElementSize        Size of data element in Byte.
  ReadDataFunc       C-function for getting the data. Its signature depends on ElementKind and ElementDataType: With value(s) DEM_CFG_DATA_FROM_CS_PORT_WITH_EVENTID use: Std_ReturnType (*)(uint8* Buffer, uint16 EventId); - and use: Std_ReturnType (*)(uint8* Buffer); with the other values DEM_CFG_DATA_FROM_CS_PORT, DEM_CFG_DATA_FROM_SR_PORT.
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableType, DEM_CONST) Dem_Cfg_DataElementTable[10] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ElementDataType            ElementKind                     ElementSize  ReadDataFunc                                                                                                                                      Referable Keys */
  { /*     0 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATAELEMENT_INVALID   ,          0u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                       },  /* [#NoDataElementConfigured] */
  { /*     1 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_AGINGCTR    ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                       },  /* [#Data_StandardEnvironmentData_Operation_Cycle_Counter, EdrExtendedDataRecord_StandardEnvironmentData] */
  { /*     2 */ DEM_CFG_DATA_TYPE_UINT32 , DEM_CFG_DATA_FROM_CS_PORT     ,          4u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x133_Current_Operating_Time_ReadData             },  /* [#Data_DID_0x133_Current_Operating_Time, DidDID_Current_Operating_Time_Read_0x133] */
  { /*     3 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_SIGNIFICANCE,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                       },  /* [#Data_StandardEnvironmentData_Occurrence_Flag, EdrExtendedDataRecord_StandardEnvironmentData] */
  { /*     4 */ DEM_CFG_DATA_TYPE_UINT16 , DEM_CFG_DATA_FROM_CS_PORT     ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution_ReadData },  /* [#Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution, DidDID_Vehicle_Odometer_in_Low_Resolution_Read_0x10a] */
  { /*     5 */ DEM_CFG_DATA_TYPE_UINT8_N, DEM_CFG_DATA_FROM_CS_PORT     ,          2u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x18b_SecOcDataID_ReadData                        },  /* [#Data_DID_0x18b_SecOcDataID, DidDID_0x18b] */
  { /*     6 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_SIGNIFICANCE,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                       },  /* [#Data_StandardEnvironmentData_External_Tester_Present_Flag, EdrExtendedDataRecord_StandardEnvironmentData] */
  { /*     7 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT     ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0x133_Operating_Time_Status_ReadData              },  /* [#Data_DID_0x133_Operating_Time_Status, DidDID_Current_Operating_Time_Read_0x133] */
  { /*     8 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_OCCCTR      ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ NULL_PTR                                                                       },  /* [#Data_StandardEnvironmentData_Frequency_Counter, EdrExtendedDataRecord_StandardEnvironmentData] */
  { /*     9 */ DEM_CFG_DATA_TYPE_UINT8  , DEM_CFG_DATA_FROM_CS_PORT     ,          1u,  (Dem_ReadDataFPtrType) /* PRQA S 0313 */ /* MD_DEM_11.1 */ Rte_Call_CBReadData_Data_DID_0xfd05_Root_Causes_ReadData                       }   /* [#Data_DID_0xfd05_Root_Causes, DidDID_0xfd05] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DataElementTableCol2ElmtInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DataElementTableCol2ElmtInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_DataElementTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DataElementTableCol2ElmtIndType, DEM_CONST) Dem_Cfg_DataElementTableCol2ElmtInd[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DataElementTableCol2ElmtInd      Referable Keys */
  /*     0 */                           3u,  /* [EdrExtendedDataRecord_StandardEnvironmentData] */
  /*     1 */                           6u,  /* [EdrExtendedDataRecord_StandardEnvironmentData] */
  /*     2 */                           8u,  /* [EdrExtendedDataRecord_StandardEnvironmentData] */
  /*     3 */                           1u,  /* [EdrExtendedDataRecord_StandardEnvironmentData] */
  /*     4 */                           5u,  /* [DidDID_0x18b] */
  /*     5 */                           9u,  /* [DidDID_0xfd05] */
  /*     6 */                           2u,  /* [DidDID_Current_Operating_Time_Read_0x133] */
  /*     7 */                           7u,  /* [DidDID_Current_Operating_Time_Read_0x133] */
  /*     8 */                           4u   /* [DidDID_Vehicle_Odometer_in_Low_Resolution_Read_0x10a] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DebounceHiResTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DebounceHiResTable
  \brief  EventIDs of events using the high resolution timer (tick time: 10.0ms) - contains available events and also events that are not 'available in variant'.
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DebounceHiResTableType, DEM_CONST) Dem_Cfg_DebounceHiResTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DebounceHiResTable      Referable Keys */
  /*     0 */                 32u,  /* [DTC_0xd12087, Satellite#0] */
  /*     1 */                 39u   /* [ADC_ERROR_Dummy, Satellite#0] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DebounceTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DebounceTable
  \details
  Element                   Description
  FailTimerCycles           HiRes- or LoRes-Timer ticks for DemDebounceTimeFailedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceTimeBase
  DecrementStepSize         (-1) * DemDebounceCounterDecrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  FailedThreshold           DemDebounceCounterFailedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  IncrementStepSize         DemDebounceCounterIncrementStepSize of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  PassTimerCycles           HiRes- or LoRes-Timer ticks for DemDebounceTimePassedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceTimeBase
  PassedThreshold           DemDebounceCounterPassedThreshold of the DemEventParameter/DemEventClass/DemDebounceAlgorithmClass/DemDebounceCounterBased
  EventDebounceAlgorithm    Used DemEventParameter/DemEventClass/DemDebounceAlgorithmClass
  MaskedBits                contains bitcoded the boolean data of Dem_Cfg_DebounceContinuousOfDebounceTable, Dem_Cfg_EventDebounceBehaviorOfDebounceTable, Dem_Cfg_JumpDownOfDebounceTable, Dem_Cfg_JumpUpOfDebounceTable, Dem_Cfg_StorageOfDebounceTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DebounceTableType, DEM_CONST) Dem_Cfg_DebounceTable[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FailTimerCycles  DecrementStepSize  FailedThreshold  IncrementStepSize  PassTimerCycles  PassedThreshold  EventDebounceAlgorithm                                                      MaskedBits        Referable Keys */
  { /*     0 */               0,                -1,             127,                 1,               0,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06u },  /* [FEE_E_READ, MCU_E_OSC_FAILURE, MCU_E_SYSTEM_PLL_LOCK_LOSS, SPI_E_HARDWARE_ERROR, WDGM_E_IMPROPER_CALLER, WDGM_E_MONITORING] */
  { /*     1 */             300,                -1,             127,                 1,               1,            -128,   DEM_CFG_DEM_CFG_DEBOUNCETYPE_TIMER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06u },  /* [DTC_0xd12087] */
  { /*     2 */               0,                -1,              10,                 1,               0,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x04u },  /* [DTC_0xc12287, DTC_0xc15187] */
  { /*     3 */               0,              -127,              10,                43,               0,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x04u },  /* [DTC_0xa28b16, DTC_0xa28b17] */
  { /*     4 */               0,              -127,              10,               127,               0,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x04u },  /* [DTC_0xa20400, DTC_0xa28b45, DTC_0xa28b47, DTC_0xa28b49, DTC_0xa28b4b, DTC_0xa28b71, DTC_0xa28b96, DTC_0xa28b97, DTC_0xa28bfa] */
  { /*     5 */               0,                -1,             127,                 1,               0,            -128, DEM_CFG_DEM_CFG_DEBOUNCETYPE_COUNTER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x04u },  /* [DTC_0x164456, DTC_0x1ca000, DTC_0x9a6857, DTC_0xa10a00, DTC_0xa10b00, DTC_0xa10d00, DTC_0xa10e00, DTC_0xc11587, DTC_0xc15587, DTC_0xc16887, DTC_0xc20187, DTC_0xc20287, DTC_0xc41608, DTC_0xc42708, DTC_0xc44286, DTC_0xc45208, DTC_0xd12081, DTC_0xd12083, DTC_0xd22488, DTC_0xd88987, DTC_0xd88a08] */
  { /*     6 */               1,                -1,             127,                 1,               1,            -128,   DEM_CFG_DEM_CFG_DEBOUNCETYPE_TIMER_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x06u },  /* [ADC_ERROR_Dummy] */
  { /*     7 */               0,                 0,               0,                 0,               0,               0, DEM_CFG_DEM_CFG_DEBOUNCETYPE_INVALID_EVENTDEBOUNCEALGORITHMOFDEBOUNCETABLE,      0x00u }   /* [#EVENT_INVALID] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DtcTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DtcTable
  \details
  Element           Description
  UdsDtc        
  FunctionalUnit
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_DtcTableType, DEM_CONST) Dem_Cfg_DtcTable[36] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UdsDtc       FunctionalUnit        Referable Keys */
  { /*     0 */ 0x00FFFFFFu,           255u },  /* [#NoUdsDtcConfigured, #NoObdDtcConfigured, #NoJ1939DtcConfigured] */
  { /*     1 */ 0x001CA000u,             0u },  /* [DtcClass_DTC_0x1ca000] */
  { /*     2 */ 0x009A6857u,             0u },  /* [DtcClass_DTC_0x9a6857] */
  { /*     3 */ 0x00164456u,             0u },  /* [DtcClass_DTC_0x164456] */
  { /*     4 */ 0x00A10A00u,             0u },  /* [DtcClass_DTC_0xa10a00] */
  { /*     5 */ 0x00A10B00u,             0u },  /* [DtcClass_DTC_0xa10b00] */
  { /*     6 */ 0x00A10D00u,             0u },  /* [DtcClass_DTC_0xa10d00] */
  { /*     7 */ 0x00A10E00u,             0u },  /* [DtcClass_DTC_0xa10e00] */
  { /*     8 */ 0x00A28B4Bu,             0u },  /* [DtcClass_DTC_0xa28b4b] */
  { /*     9 */ 0x00A28B16u,             0u },  /* [DtcClass_DTC_0xa28b16] */
  { /*    10 */ 0x00A28B17u,             0u },  /* [DtcClass_DTC_0xa28b17] */
  { /*    11 */ 0x00A28B45u,             0u },  /* [DtcClass_DTC_0xa28b45] */
  { /*    12 */ 0x00A28B47u,             0u },  /* [DtcClass_DTC_0xa28b47] */
  { /*    13 */ 0x00A28B49u,             0u },  /* [DtcClass_DTC_0xa28b49] */
  { /*    14 */ 0x00A28B71u,             0u },  /* [DtcClass_DTC_0xa28b71] */
  { /*    15 */ 0x00A28B96u,             0u },  /* [DtcClass_DTC_0xa28b96] */
  { /*    16 */ 0x00A28B97u,             0u },  /* [DtcClass_DTC_0xa28b97] */
  { /*    17 */ 0x00A28BFAu,             0u },  /* [DtcClass_DTC_0xa28bfa] */
  { /*    18 */ 0x00A20400u,             0u },  /* [DtcClass_DTC_0xa20400] */
  { /*    19 */ 0x00C11587u,             0u },  /* [DtcClass_DTC_0xc11587] */
  { /*    20 */ 0x00C12287u,             0u },  /* [DtcClass_DTC_0xc12287] */
  { /*    21 */ 0x00C15187u,             0u },  /* [DtcClass_DTC_0xc15187] */
  { /*    22 */ 0x00C15587u,             0u },  /* [DtcClass_DTC_0xc15587] */
  { /*    23 */ 0x00C16887u,             0u },  /* [DtcClass_DTC_0xc16887] */
  { /*    24 */ 0x00C20187u,             0u },  /* [DtcClass_DTC_0xc20187] */
  { /*    25 */ 0x00C20287u,             0u },  /* [DtcClass_DTC_0xc20287] */
  { /*    26 */ 0x00C41608u,             0u },  /* [DtcClass_DTC_0xc41608] */
  { /*    27 */ 0x00C42708u,             0u },  /* [DtcClass_DTC_0xc42708] */
  { /*    28 */ 0x00C44286u,             0u },  /* [DtcClass_DTC_0xc44286] */
  { /*    29 */ 0x00C45208u,             0u },  /* [DtcClass_DTC_0xc45208] */
  { /*    30 */ 0x00D12081u,             0u },  /* [DtcClass_DTC_0xd12081] */
  { /*    31 */ 0x00D12083u,             0u },  /* [DtcClass_DTC_0xd12083] */
  { /*    32 */ 0x00D12087u,             0u },  /* [DtcClass_DTC_0xd12087] */
  { /*    33 */ 0x00D22488u,             0u },  /* [DtcClass_DTC_0xd22488] */
  { /*    34 */ 0x00D88987u,             0u },  /* [DtcClass_DTC_0xd88987] */
  { /*    35 */ 0x00D88A08u,             0u }   /* [DtcClass_DTC_0xd88a08] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupTableInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_EnableConditionGroupTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionGroupTableIndType, DEM_CONST) Dem_Cfg_EnableConditionGroupTableInd[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     EnableConditionGroupTableInd      Referable Keys */
  /*     0 */                            0u,  /* [__Internal_ControlDtcSetting] */
  /*     1 */                            1u,  /* [__Internal_ControlDtcSetting] */
  /*     2 */                            3u,  /* [__Internal_ControlDtcSetting] */
  /*     3 */                            4u,  /* [__Internal_ControlDtcSetting] */
  /*     4 */                            2u,  /* [__Internal_ControlDtcSetting] */
  /*     5 */                            5u,  /* [__Internal_ControlDtcSetting] */
  /*     6 */                            4u,  /* [DemEnableCondition_ECUPowerUp] */
  /*     7 */                            1u,  /* [DemEnableCondition_CodingAPI] */
  /*     8 */                            2u,  /* [DemEnableCondition_CodingRBTMFL] */
  /*     9 */                            3u,  /* [DemEnableCondition_CodingRBTMFR] */
  /*    10 */                            1u,  /* [DemEnableCondition_IgnitionON] */
  /*    11 */                            5u   /* [DemEnableCondition_IgnitionON] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionTable
  \brief  Map each EnableCondition(Id) to the referring EnableConditionGroups - this is reverse direction of the AUTOSAR configuration model.
  \details
  Element                                 Description
  EnableConditionGroupTableIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd
  EnableConditionGroupTableIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_EnableConditionGroupTableInd
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EnableConditionTableType, DEM_CONST) Dem_Cfg_EnableConditionTable[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EnableConditionGroupTableIndEndIdx  EnableConditionGroupTableIndStartIdx */
  { /*     0 */                                 6u,                                   0u },
  { /*     1 */                                 7u,                                   6u },
  { /*     2 */                                 8u,                                   7u },
  { /*     3 */                                 9u,                                   8u },
  { /*     4 */                                10u,                                   9u },
  { /*     5 */                                12u,                                  10u }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventStatusChanged
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_EventStatusChangedFPtrType, DEM_CONST) Dem_Cfg_EventStatusChanged[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     EventStatusChanged                            Referable Keys */
  /*     0 */ SBC_SpiConfigurationHwError_Notification ,  /* [SPI_E_HARDWARE_ERROR] */
  /*     1 */ RCM_ClockFailure_Notification            ,  /* [MCU_E_OSC_FAILURE] */
  /*     2 */ RCM_PllFailure_Notification              ,  /* [MCU_E_SYSTEM_PLL_LOCK_LOSS] */
  /*     3 */ RCM_DFlashEccFailure_Notification           /* [FEE_E_READ] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventTable
  \details
  Element                          Description
  AgingCycleCounterThreshold       DemAgingCycleCounterThreshold of the DemEventParameter/DemEventClass. If AgingAllowedOfEventTable==FALSE and DemAgingCycleCounterThreshold does not exist '255' is set. If AgingAllowedOfEventTable==TRUE and DemAgingCycleCounterThreshold does not exist '0' is set.
  AgingCycleId                     DemOperationCycle (ID) referenced by DemEventParameter/DemEventClass/DemAgingCycleRef
  DebounceTableIdx                 the index of the 1:1 relation pointing to Dem_Cfg_DebounceTable
  DtcTableIdx                      the index of the 1:1 relation pointing to Dem_Cfg_DtcTable
  EnableConditionGroupTableIdx     the index of the 1:1 relation pointing to Dem_Cfg_EnableConditionGroupTable
  EventDestination                 Memory Destination of the referenced DTC
  EventKind                        DemEventKind of the DemEventParameter
  EventPriority                    DemEventParameter/DemEventClass/DemEventPriority, values [1..255] for the configuration range [1..255].
  EventSignificance                DemEventSignificance of the DemEventParameter/DemEventClass
  EventStatusChangedEndIdx         the end index of the 0:n relation pointing to Dem_Cfg_EventStatusChanged
  EventStatusChangedStartIdx       the start index of the 0:n relation pointing to Dem_Cfg_EventStatusChanged
  ExtendedDataTableIdx             the index of the 1:1 relation pointing to Dem_Cfg_ExtendedDataTable
  FreezeFrameNumTableEndIdx        the end index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  FreezeFrameNumTableStartIdx      the start index of the 0:n relation pointing to Dem_Cfg_FreezeFrameNumTable
  FreezeFrameTableStdFFIdx         the index of the 1:1 relation pointing to Dem_Cfg_FreezeFrameTable
  HealingTarget                    DemIndicatorHealingCycleCounterThreshold of the DemEventParameter/DemEventClass/DemIndicatorAttribute (for each event all attribute's value must be identical). Events without DemIndicatorAttribute have: 0.
  IndicatorTableIndEndIdx          the end index of the 0:n relation pointing to Dem_Cfg_IndicatorTableInd
  IndicatorTableIndStartIdx        the start index of the 0:n relation pointing to Dem_Cfg_IndicatorTableInd
  InitMonitorForEventIdx           the index of the 0:1 relation pointing to Dem_Cfg_InitMonitorForEvent
  MaskedBits                       contains bitcoded the boolean data of Dem_Cfg_AgingAllowedOfEventTable, Dem_Cfg_EventLatchTFOfEventTable, Dem_Cfg_OBDVisibilityDelayedUntilDcyQualificationOfEventTable
  StorageConditionGroupTableIdx    the index of the 0:1 relation pointing to Dem_Cfg_StorageConditionGroupTable
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_EventTableType, DEM_CONST) Dem_Cfg_EventTable[43] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AgingCycleCounterThreshold  AgingCycleId                             DebounceTableIdx  DtcTableIdx  EnableConditionGroupTableIdx  EventDestination          EventKind                                         EventPriority  EventSignificance                                                        EventStatusChangedEndIdx                         EventStatusChangedStartIdx                         ExtendedDataTableIdx  FreezeFrameNumTableEndIdx                         FreezeFrameNumTableStartIdx                         FreezeFrameTableStdFFIdx  HealingTarget  IndicatorTableIndEndIdx                         IndicatorTableIndStartIdx                         InitMonitorForEventIdx  MaskedBits  StorageConditionGroupTableIdx                               Referable Keys */
  { /*     0 */                         1u, DemConf_DemOperationCycle_IgnitionCycle,               5u,          1u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   0u },  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured, Satellite#0] */
  { /*     1 */                         1u, DemConf_DemOperationCycle_IgnitionCycle,               5u,          1u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   0u },  /* [DTC_0x1ca000, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*     2 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               5u,          2u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [DTC_0x9a6857, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*     3 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               5u,          3u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     1u,      0x04u,                                                   2u },  /* [DTC_0x164456, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*     4 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               5u,          4u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   3u },  /* [DTC_0xa10a00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*     5 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               5u,          5u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   3u },  /* [DTC_0xa10b00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*     6 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               5u,          6u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   3u },  /* [DTC_0xa10d00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*     7 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               5u,          7u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   3u },  /* [DTC_0xa10e00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*     8 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               4u,          8u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u,                                             1u,                                               0u,                     0u,      0x04u,                                                   0u },  /* [DTC_0xa28b4b, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*     9 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               3u,          9u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   3u },  /* [DTC_0xa28b16, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    10 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               3u,         10u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   3u },  /* [DTC_0xa28b17, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    11 */                       255u, DemConf_DemOperationCycle_IgnitionCycle,               4u,         11u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u,                                             2u,                                               1u,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [DTC_0xa28b45, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    12 */                       255u, DemConf_DemOperationCycle_IgnitionCycle,               4u,         12u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [DTC_0xa28b47, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    13 */                       255u, DemConf_DemOperationCycle_IgnitionCycle,               4u,         13u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u,                                             3u,                                               2u,                     0u,      0x00u,                                                   0u },  /* [DTC_0xa28b49, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    14 */                       255u, DemConf_DemOperationCycle_IgnitionCycle,               4u,         14u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u,                                             4u,                                               3u,                     0u,      0x00u,                                                   0u },  /* [DTC_0xa28b71, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    15 */                       255u, DemConf_DemOperationCycle_IgnitionCycle,               4u,         15u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u,                                             5u,                                               4u,                     0u,      0x00u,                                                   0u },  /* [DTC_0xa28b96, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    16 */                       255u, DemConf_DemOperationCycle_IgnitionCycle,               4u,         16u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u,                                                   0u },  /* [DTC_0xa28b97, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    17 */                       255u, DemConf_DemOperationCycle_IgnitionCycle,               4u,         17u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u,                                                   0u },  /* [DTC_0xa28bfa, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    18 */                       255u, DemConf_DemOperationCycle_IgnitionCycle,               4u,         18u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            1u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u,                                             6u,                                               5u,                     0u,      0x00u,                                                   0u },  /* [DTC_0xa20400, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    19 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         19u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc11587, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    20 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               2u,         20u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,          100u,                                             7u,                                               6u,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc12287, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    21 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               2u,         21u,                           5u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,          100u,                                             8u,                                               7u,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc15187, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    22 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         22u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc15587, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    23 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         23u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   2u },  /* [DTC_0xc16887, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    24 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         24u,                           2u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc20187, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    25 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         25u,                           3u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc20287, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    26 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         26u,                           5u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,          100u,                                             9u,                                               8u,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc41608, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    27 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         27u,                           5u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,          100u,                                            10u,                                               9u,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc42708, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    28 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         28u,                           5u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc44286, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    29 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         29u,                           5u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,          100u,                                            11u,                                              10u,                     0u,      0x04u,                                                   1u },  /* [DTC_0xc45208, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    30 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         30u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     2u,      0x04u,                                                   0u },  /* [DTC_0xd12081, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    31 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         31u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       2u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     3u,      0x04u,                                                   0u },  /* [DTC_0xd12083, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    32 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               1u,         32u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     4u,      0x04u,                                                   0u },  /* [DTC_0xd12087, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    33 */                       100u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         33u,                           4u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   3u },  /* [DTC_0xd22488, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    34 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         34u,                           1u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   1u },  /* [DTC_0xd88987, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    35 */                        10u, DemConf_DemOperationCycle_IgnitionCycle,               5u,         35u,                           1u, DEM_CFG_MEMORYID_PRIMARY, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u, DEM_CFG_DEM_EVENT_SIGNIFICANCE_OCCURRENCE_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   1u,                                               2u,                                                 0u,                       1u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x04u,                                                   1u },  /* [DTC_0xd88a08, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  { /*    36 */                       255u, /*no AgingCycle*/ 2U                   ,               0u,          0u,                           0u, DEM_CFG_MEMORYID_INVALID, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE,                                              1u,                                                0u,                   0u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [SPI_E_HARDWARE_ERROR, #NoExtendedDataRecordConfigured, Satellite#0] */
  { /*    37 */                       255u, /*no AgingCycle*/ 2U                   ,               0u,          0u,                           0u, DEM_CFG_MEMORYID_INVALID, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [WDGM_E_MONITORING, #NoExtendedDataRecordConfigured, Satellite#0] */
  { /*    38 */                       255u, /*no AgingCycle*/ 2U                   ,               0u,          0u,                           0u, DEM_CFG_MEMORYID_INVALID, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [WDGM_E_IMPROPER_CALLER, #NoExtendedDataRecordConfigured, Satellite#0] */
  { /*    39 */                       100u, /*no AgingCycle*/ 2U                   ,               6u,          0u,                           0u, DEM_CFG_MEMORYID_INVALID, DEM_CFG_DEM_EVENT_KIND_SWC_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDENDIDXOFEVENTTABLE, DEM_CFG_NO_EVENTSTATUSCHANGEDSTARTIDXOFEVENTTABLE,                   0u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [ADC_ERROR_Dummy, #NoExtendedDataRecordConfigured, Satellite#0] */
  { /*    40 */                       100u, /*no AgingCycle*/ 2U                   ,               0u,          0u,                           0u, DEM_CFG_MEMORYID_INVALID, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE,                                              2u,                                                1u,                   0u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [MCU_E_OSC_FAILURE, #NoExtendedDataRecordConfigured, Satellite#0] */
  { /*    41 */                       100u, /*no AgingCycle*/ 2U                   ,               0u,          0u,                           0u, DEM_CFG_MEMORYID_INVALID, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE,                                              3u,                                                2u,                   0u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE },  /* [MCU_E_SYSTEM_PLL_LOCK_LOSS, #NoExtendedDataRecordConfigured, Satellite#0] */
  { /*    42 */                       100u, /*no AgingCycle*/ 2U                   ,               0u,          0u,                           0u, DEM_CFG_MEMORYID_INVALID, DEM_CFG_DEM_EVENT_KIND_BSW_EVENTKINDOFEVENTTABLE,            2u,      DEM_CFG_DEM_EVENT_SIGNIFICANCE_FAULT_EVENTSIGNIFICANCEOFEVENTTABLE,                                              4u,                                                3u,                   0u, DEM_CFG_NO_FREEZEFRAMENUMTABLEENDIDXOFEVENTTABLE, DEM_CFG_NO_FREEZEFRAMENUMTABLESTARTIDXOFEVENTTABLE,                       0u,            0u, DEM_CFG_NO_INDICATORTABLEINDENDIDXOFEVENTTABLE, DEM_CFG_NO_INDICATORTABLEINDSTARTIDXOFEVENTTABLE,                     0u,      0x00u, DEM_CFG_NO_STORAGECONDITIONGROUPTABLEIDXOFEVENTTABLE }   /* [FEE_E_READ, #NoExtendedDataRecordConfigured, Satellite#0] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ExtendedDataTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ExtendedDataTable
  \details
  Element                                   Description
  DataCollectionTableEdr2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableEdr2CollInd
  DataCollectionTableEdr2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableEdr2CollInd
  MaxRecordSize                         
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_ExtendedDataTableType, DEM_CONST) Dem_Cfg_ExtendedDataTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DataCollectionTableEdr2CollIndEndIdx                                DataCollectionTableEdr2CollIndStartIdx                                MaxRecordSize        Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDENDIDXOFEXTENDEDDATATABLE, DEM_CFG_NO_DATACOLLECTIONTABLEEDR2COLLINDSTARTIDXOFEXTENDEDDATATABLE,            0u },  /* [#NoExtendedDataRecordConfigured, SPI_E_HARDWARE_ERROR, WDGM_E_MONITORING, WDGM_E_IMPROPER_CALLER, ADC_ERROR_Dummy, MCU_E_OSC_FAILURE, MCU_E_SYSTEM_PLL_LOCK_LOSS, FEE_E_READ] */
  { /*     1 */                                                                 1u,                                                                   0u,            4u }   /* [#ExtendedDataClass_dda5abf3, #EVENT_INVALID, DTC_0x1ca000, DTC_0x9a6857, DTC_0x164456, DTC_0xa10a00, DTC_0xa10b00, DTC_0xa10d00, DTC_0xa10e00, DTC_0xa28b4b, DTC_0xa28b16, DTC_0xa28b17, DTC_0xa28b45, DTC_0xa28b47, DTC_0xa28b49, DTC_0xa28b71, DTC_0xa28b96, DTC_0xa28b97, DTC_0xa28bfa, DTC_0xa20400, DTC_0xc11587, DTC_0xc12287, DTC_0xc15187, DTC_0xc15587, DTC_0xc16887, DTC_0xc20187, DTC_0xc20287, DTC_0xc41608, DTC_0xc42708, DTC_0xc44286, DTC_0xc45208, DTC_0xd12081, DTC_0xd12083, DTC_0xd12087, DTC_0xd22488, DTC_0xd88987, DTC_0xd88a08] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameNumTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameNumTable
  \details
  Element      Description
  FFTrigger
  FFNumber 
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_FreezeFrameNumTableType, DEM_CONST) Dem_Cfg_FreezeFrameNumTable[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FFTrigger                   FFNumber        Referable Keys */
  { /*     0 */ DEM_CFG_TRIGGER_CONFIRMED ,      16u },  /* [FreezeFrameRecNum_bc8f2da9, #EVENT_INVALID, DTC_0x1ca000, DTC_0x9a6857, DTC_0x164456, DTC_0xa10a00, DTC_0xa10b00, DTC_0xa10d00, DTC_0xa10e00, DTC_0xa28b4b, DTC_0xa28b16, DTC_0xa28b17, DTC_0xa28b45, DTC_0xa28b47, DTC_0xa28b49, DTC_0xa28b71, DTC_0xa28b96, DTC_0xa28b97, DTC_0xa28bfa, DTC_0xa20400, DTC_0xc11587, DTC_0xc12287, DTC_0xc15187, DTC_0xc15587, DTC_0xc16887, DTC_0xc20187, DTC_0xc20287, DTC_0xc41608, DTC_0xc42708, DTC_0xc44286, DTC_0xc45208, DTC_0xd12081, DTC_0xd12083, DTC_0xd12087, DTC_0xd22488, DTC_0xd88987, DTC_0xd88a08] */
  { /*     1 */ DEM_CFG_TRIGGER_TESTFAILED,      32u }   /* [FreezeFrameRecNum_bc8f2da9, #EVENT_INVALID, DTC_0x1ca000, DTC_0x9a6857, DTC_0x164456, DTC_0xa10a00, DTC_0xa10b00, DTC_0xa10d00, DTC_0xa10e00, DTC_0xa28b4b, DTC_0xa28b16, DTC_0xa28b17, DTC_0xa28b45, DTC_0xa28b47, DTC_0xa28b49, DTC_0xa28b71, DTC_0xa28b96, DTC_0xa28b97, DTC_0xa28bfa, DTC_0xa20400, DTC_0xc11587, DTC_0xc12287, DTC_0xc15187, DTC_0xc15587, DTC_0xc16887, DTC_0xc20187, DTC_0xc20287, DTC_0xc41608, DTC_0xc42708, DTC_0xc44286, DTC_0xc45208, DTC_0xd12081, DTC_0xd12083, DTC_0xd12087, DTC_0xd22488, DTC_0xd88987, DTC_0xd88a08] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameTable
  \details
  Element                                   Description
  DataCollectionTableFfm2CollIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableFfm2CollInd
  DataCollectionTableFfm2CollIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_DataCollectionTableFfm2CollInd
  RecordSize                                Summarized size of did data that is stored in Dem_Cfg_PrimaryEntryType.SnapshotData[][] (i.e. typically without size of dids containing internal data elements).
  RecordSizeUds                             Summarized size of did data, did numbers and snapshot header (i.e. dynamical payload size of the uds response message).
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_FreezeFrameTableType, DEM_CONST) Dem_Cfg_FreezeFrameTable[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DataCollectionTableFfm2CollIndEndIdx                               DataCollectionTableFfm2CollIndStartIdx                               RecordSize  RecordSizeUds        Referable Keys */
  { /*     0 */ DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDENDIDXOFFREEZEFRAMETABLE, DEM_CFG_NO_DATACOLLECTIONTABLEFFM2COLLINDSTARTIDXOFFREEZEFRAMETABLE,         0u,            0u },  /* [#NoFreezeFrameConfigured, SPI_E_HARDWARE_ERROR, WDGM_E_MONITORING, WDGM_E_IMPROPER_CALLER, ADC_ERROR_Dummy, MCU_E_OSC_FAILURE, MCU_E_SYSTEM_PLL_LOCK_LOSS, FEE_E_READ] */
  { /*     1 */                                                                3u,                                                                  0u,         8u,           16u },  /* [#FreezeFrame_8035c374, #EVENT_INVALID, DTC_0x1ca000, DTC_0x9a6857, DTC_0x164456, DTC_0xa10a00, DTC_0xa10b00, DTC_0xa10d00, DTC_0xa10e00, DTC_0xa28b4b, DTC_0xa28b16, DTC_0xa28b17, DTC_0xa28b45, DTC_0xa28b47, DTC_0xa28b49, DTC_0xa28b71, DTC_0xa28b96, DTC_0xa28b97, DTC_0xa28bfa, DTC_0xa20400, DTC_0xc11587, DTC_0xc12287, DTC_0xc15187, DTC_0xc15587, DTC_0xc16887, DTC_0xc20187, DTC_0xc20287, DTC_0xc41608, DTC_0xc42708, DTC_0xc44286, DTC_0xc45208, DTC_0xd12081, DTC_0xd12087, DTC_0xd22488, DTC_0xd88987, DTC_0xd88a08] */
  { /*     2 */                                                                7u,                                                                  3u,        10u,           20u }   /* [#FreezeFrame_b430d746, DTC_0xd12083] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_InitMonitorForEvent
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_InitMonitorForEventFPtrType, DEM_CONST) Dem_Cfg_InitMonitorForEvent[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitMonitorForEvent                                      Referable Keys */
  /*     0 */ NULL_PTR                                            ,  /* [#NoCallbackInitMonitorConfigured] */
  /*     1 */ Rte_Call_CBInitEvt_DTC_0x164456_InitMonitorForEvent ,  /* [DTC_0x164456] */
  /*     2 */ Rte_Call_CBInitEvt_DTC_0xd12081_InitMonitorForEvent ,  /* [DTC_0xd12081] */
  /*     3 */ Rte_Call_CBInitEvt_DTC_0xd12083_InitMonitorForEvent ,  /* [DTC_0xd12083] */
  /*     4 */ Rte_Call_CBInitEvt_DTC_0xd12087_InitMonitorForEvent    /* [DTC_0xd12087] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryBlockId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryBlockId
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryBlockIdType, DEM_CONST) Dem_Cfg_MemoryBlockId[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryBlockId                                                             Comment */
  /*     0 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Admin_Data /*NvMBlockId=94*/ ,  /* [DemNvRamBlock_Admin] */
  /*     1 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Status /*NvMBlockId=93*/     ,  /* [DemNvRamBlock_Status] */
  /*     2 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_0 /*NvMBlockId=83*/  ,  /* [DemNvRamBlock_Primary_0] */
  /*     3 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_1 /*NvMBlockId=84*/  ,  /* [DemNvRamBlock_Primary_1] */
  /*     4 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_2 /*NvMBlockId=85*/  ,  /* [DemNvRamBlock_Primary_2] */
  /*     5 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_3 /*NvMBlockId=86*/  ,  /* [DemNvRamBlock_Primary_3] */
  /*     6 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_4 /*NvMBlockId=87*/  ,  /* [DemNvRamBlock_Primary_4] */
  /*     7 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_5 /*NvMBlockId=88*/  ,  /* [DemNvRamBlock_Primary_5] */
  /*     8 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_6 /*NvMBlockId=89*/  ,  /* [DemNvRamBlock_Primary_6] */
  /*     9 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_7 /*NvMBlockId=90*/  ,  /* [DemNvRamBlock_Primary_7] */
  /*    10 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_8 /*NvMBlockId=91*/  ,  /* [DemNvRamBlock_Primary_8] */
  /*    11 */ NvMConf_NvMBlockDescriptor_NvMBlock_Dem_Primary_9 /*NvMBlockId=92*/     /* [DemNvRamBlock_Primary_9] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryBlockIdToMemoryEntryId
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryBlockIdToMemoryEntryId
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryEntryHandleType, DEM_CONST) Dem_Cfg_MemoryBlockIdToMemoryEntryId[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryBlockIdToMemoryEntryId        Comment */
  /*     0 */ DEM_MEMORYENTRY_HANDLE_INVALID ,  /* [DemNvRamBlock_Admin] */
  /*     1 */ DEM_MEMORYENTRY_HANDLE_INVALID ,  /* [DemNvRamBlock_Status] */
  /*     2 */ 0u                             ,  /* [DemNvRamBlock_Primary_0] */
  /*     3 */ 1u                             ,  /* [DemNvRamBlock_Primary_1] */
  /*     4 */ 2u                             ,  /* [DemNvRamBlock_Primary_2] */
  /*     5 */ 3u                             ,  /* [DemNvRamBlock_Primary_3] */
  /*     6 */ 4u                             ,  /* [DemNvRamBlock_Primary_4] */
  /*     7 */ 5u                             ,  /* [DemNvRamBlock_Primary_5] */
  /*     8 */ 6u                             ,  /* [DemNvRamBlock_Primary_6] */
  /*     9 */ 7u                             ,  /* [DemNvRamBlock_Primary_7] */
  /*    10 */ 8u                             ,  /* [DemNvRamBlock_Primary_8] */
  /*    11 */ 9u                                /* [DemNvRamBlock_Primary_9] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryDataPtr
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryDataPtr
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_NvDataPtrType, DEM_CONST) Dem_Cfg_MemoryDataPtr[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryDataPtr                                                                                  Comment */
  /*     0 */ (Dem_NvDataPtrType) &Dem_Cfg_GetAdminData()        /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Admin] */
  /*     1 */ (Dem_NvDataPtrType) &Dem_Cfg_GetStatusData()       /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Status] */
  /*     2 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_0()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_0] */
  /*     3 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_1()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_1] */
  /*     4 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_2()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_2] */
  /*     5 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_3()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_3] */
  /*     6 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_4()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_4] */
  /*     7 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_5()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_5] */
  /*     8 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_6()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_6] */
  /*     9 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_7()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_7] */
  /*    10 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_8()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_8] */
  /*    11 */ (Dem_NvDataPtrType) &Dem_Cfg_GetPrimaryEntry_9()   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [DemNvRamBlock_Primary_9] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryDataSize
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryDataSize
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_MemoryDataSizeType, DEM_CONST) Dem_Cfg_MemoryDataSize[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryDataSize                                                        Comment */
  /*     0 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetAdminData())      ,  /* [DemNvRamBlock_Admin] */
  /*     1 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetStatusData())     ,  /* [DemNvRamBlock_Status] */
  /*     2 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_0()) ,  /* [DemNvRamBlock_Primary_0] */
  /*     3 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_1()) ,  /* [DemNvRamBlock_Primary_1] */
  /*     4 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_2()) ,  /* [DemNvRamBlock_Primary_2] */
  /*     5 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_3()) ,  /* [DemNvRamBlock_Primary_3] */
  /*     6 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_4()) ,  /* [DemNvRamBlock_Primary_4] */
  /*     7 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_5()) ,  /* [DemNvRamBlock_Primary_5] */
  /*     8 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_6()) ,  /* [DemNvRamBlock_Primary_6] */
  /*     9 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_7()) ,  /* [DemNvRamBlock_Primary_7] */
  /*    10 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_8()) ,  /* [DemNvRamBlock_Primary_8] */
  /*    11 */ (Dem_Cfg_MemoryDataSizeType) sizeof(Dem_Cfg_GetPrimaryEntry_9())    /* [DemNvRamBlock_Primary_9] */
};
#define DEM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryEntry
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryEntry
  \brief  The array contains these items: 10 * Primary, ReadoutBuffer; size = DEM_CFG_GLOBAL_PRIMARY_SIZE + DEM_CFG_GLOBAL_SECONDARY_SIZE + DEM_CFG_NUMBER_OF_READOUTBUFFERS * DEM_CFG_NUMBER_OF_SUBEVENT_DATA_READOUTBUFFERS
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_SharedMemoryEntryPtrType, DEM_CONST) Dem_Cfg_MemoryEntry[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     MemoryEntry                                                                                          Comment */
  /*     0 */ &Dem_Cfg_GetPrimaryEntry_0()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_0] */
  /*     1 */ &Dem_Cfg_GetPrimaryEntry_1()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_1] */
  /*     2 */ &Dem_Cfg_GetPrimaryEntry_2()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_2] */
  /*     3 */ &Dem_Cfg_GetPrimaryEntry_3()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_3] */
  /*     4 */ &Dem_Cfg_GetPrimaryEntry_4()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_4] */
  /*     5 */ &Dem_Cfg_GetPrimaryEntry_5()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_5] */
  /*     6 */ &Dem_Cfg_GetPrimaryEntry_6()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_6] */
  /*     7 */ &Dem_Cfg_GetPrimaryEntry_7()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_7] */
  /*     8 */ &Dem_Cfg_GetPrimaryEntry_8()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_8] */
  /*     9 */ &Dem_Cfg_GetPrimaryEntry_9()                             /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */,  /* [DemNvRamBlock_Primary_9] */
  /*    10 */ &Dem_Cfg_GetReadoutBuffer(0).ReadOutBufferData[0].Data   /* PRQA S 0310 */ /* MD_DEM_11.4_nvm */   /* [Dem_Cfg_ReadoutBuffer[0].ReadOutBufferData[0].Data] */
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_PrimaryEntryType, DEM_CONST) Dem_Cfg_MemoryEntryInit = { 0 };  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StorageConditionGroupTableInd
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_StorageConditionGroupTableInd
  \brief  the indexes of the 1:1 sorted relation pointing to Dem_Cfg_StorageConditionGroupTable
*/ 
#define DEM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_StorageConditionGroupTableIndType, DEM_CONST) Dem_Cfg_StorageConditionGroupTableInd[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     StorageConditionGroupTableInd      Referable Keys */
  /*     0 */                             2u,  /* [DemStorageCondition_SC1_ControlDTC] */
  /*     1 */                             1u,  /* [DemStorageCondition_SC1_ControlDTC] */
  /*     2 */                             0u,  /* [DemStorageCondition_SC1_ControlDTC] */
  /*     3 */                             3u,  /* [DemStorageCondition_SC1_ControlDTC] */
  /*     4 */                             1u,  /* [DemStorageCondition_SC2_IgnitonStatus] */
  /*     5 */                             3u,  /* [DemStorageCondition_SC2_IgnitonStatus] */
  /*     6 */                             0u,  /* [DemStorageCondition_SC3_LocalVoltage] */
  /*     7 */                             2u,  /* [DemStorageCondition_SC4_SystemVoltage] */
  /*     8 */                             1u,  /* [DemStorageCondition_SC4_SystemVoltage] */
  /*     9 */                             2u,  /* [DemStorageCondition_SC5_TransportationMode] */
  /*    10 */                             1u,  /* [DemStorageCondition_SC5_TransportationMode] */
  /*    11 */                             3u,  /* [DemStorageCondition_SC5_TransportationMode] */
  /*    12 */                             2u,  /* [DemStorageCondition_SC8_CommunicationStatus] */
  /*    13 */                             1u,  /* [DemStorageCondition_SC8_CommunicationStatus] */
  /*    14 */                             3u,  /* [DemStorageCondition_SC10_debounceTimerPD] */
  /*    15 */                             1u,  /* [DemStorageCondition_SC10_debounceTimerNC] */
  /*    16 */                             2u,  /* [DemStorageCondition_SC10_debounceTimerNC15] */
  /*    17 */                             2u,  /* [DemStorageCondition_SC11_VehicleStartup] */
  /*    18 */                             1u,  /* [DemStorageCondition_SC11_VehicleStartup] */
  /*    19 */                             0u,  /* [DemStorageCondition_SC11_VehicleStartup] */
  /*    20 */                             3u,  /* [DemStorageCondition_SC11_VehicleStartup] */
  /*    21 */                             2u,  /* [DemStorageCondition_SC12_ProductionMode] */
  /*    22 */                             1u,  /* [DemStorageCondition_SC12_ProductionMode] */
  /*    23 */                             3u   /* [DemStorageCondition_SC12_ProductionMode] */
};
#define DEM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StorageConditionInitTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_StorageConditionInitTable
  \details
  Element            Description
  FulfilledAtInit    Initial value: 'FALSE' condition is not fulfilled, 'TRUE' condition is fulfilled
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_StorageConditionInitTableType, DEM_CONST) Dem_Cfg_StorageConditionInitTable[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FulfilledAtInit */
  { /*     0 */            TRUE },
  { /*     1 */           FALSE },
  { /*     2 */           FALSE },
  { /*     3 */           FALSE },
  { /*     4 */            TRUE },
  { /*     5 */            TRUE },
  { /*     6 */           FALSE },
  { /*     7 */           FALSE },
  { /*     8 */           FALSE },
  { /*     9 */           FALSE },
  { /*    10 */            TRUE }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StorageConditionTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_StorageConditionTable
  \brief  Map each StorageCondition(Id) to the referring StorageConditionGroups - this is reverse direction of the AUTOSAR configuration model.
  \details
  Element                                  Description
  StorageConditionGroupTableIndEndIdx      the end index of the 0:n relation pointing to Dem_Cfg_StorageConditionGroupTableInd
  StorageConditionGroupTableIndStartIdx    the start index of the 0:n relation pointing to Dem_Cfg_StorageConditionGroupTableInd
*/ 
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_StorageConditionTableType, DEM_CONST) Dem_Cfg_StorageConditionTable[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    StorageConditionGroupTableIndEndIdx  StorageConditionGroupTableIndStartIdx */
  { /*     0 */                                  4u,                                    0u },
  { /*     1 */                                  6u,                                    4u },
  { /*     2 */                                  7u,                                    6u },
  { /*     3 */                                  9u,                                    7u },
  { /*     4 */                                 12u,                                    9u },
  { /*     5 */                                 14u,                                   12u },
  { /*     6 */                                 15u,                                   14u },
  { /*     7 */                                 16u,                                   15u },
  { /*     8 */                                 17u,                                   16u },
  { /*     9 */                                 21u,                                   17u },
  { /*    10 */                                 24u,                                   21u }
};
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_TimeSeriesEntryInit
**********************************************************************************************************************/
#define DEM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Dem_Cfg_TimeSeriesEntryType, DEM_CONST) Dem_Cfg_TimeSeriesEntryInit = { 0 };  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_AdminData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_AdminDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_AdminData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ClearDTCTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ClearDTCTable
  \brief  size = DEM_CFG_NUMBER_OF_CLEARDTCS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_ClearDTC_DataType, DEM_VAR_NOINIT) Dem_Cfg_ClearDTCTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_CommitBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_CommitBufferType, DEM_VAR_NOINIT) Dem_Cfg_CommitBuffer;  /* PRQA S 1514, 1533, 0759 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_MSR_Union */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_DTCSelectorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_DTCSelectorTable
  \brief  size = DEM_CFG_NUMBER_OF_DTCSELECTORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_DTCSelector_DataType, DEM_VAR_NOINIT) Dem_Cfg_DTCSelectorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionFulfilled
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionFulfilled
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition ID. Table value: current condition state 'FALSE' not fulfilled, 'TRUE' fulfilled.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionFulfilledType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionFulfilled[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupCounter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupCounter
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_EnableConditionGroupCounterType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionGroupCounter[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [##NoEnableConditionGroupConfigured, __Internal_ControlDtcSetting] */
  /*     1 */  /* [#DemEnableConditionGroup_CodingAPI_IgnON, __Internal_ControlDtcSetting, DemEnableCondition_CodingAPI, DemEnableCondition_IgnitionON] */
  /*     2 */  /* [#DemEnableConditionGroup_CodingRBTMFL, __Internal_ControlDtcSetting, DemEnableCondition_CodingRBTMFL] */
  /*     3 */  /* [#DemEnableConditionGroup_CodingRBTMFR, __Internal_ControlDtcSetting, DemEnableCondition_CodingRBTMFR] */
  /*     4 */  /* [#DemEnableConditionGroup_ECUPowerUp, __Internal_ControlDtcSetting, DemEnableCondition_ECUPowerUp] */
  /*     5 */  /* [#DemEnableConditionGroup_IgnitionON, __Internal_ControlDtcSetting, DemEnableCondition_IgnitionON] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EnableConditionGroupState
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EnableConditionGroupState
  \brief  (DEM_CFG_SUPPORT_ENABLE_CONDITIONS == STD_ON) or there are internal EnableConditions. Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EnableConditionGroupStateType, DEM_VAR_NOINIT) Dem_Cfg_EnableConditionGroupState[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [##NoEnableConditionGroupConfigured, __Internal_ControlDtcSetting] */
  /*     1 */  /* [#DemEnableConditionGroup_CodingAPI_IgnON, __Internal_ControlDtcSetting, DemEnableCondition_CodingAPI, DemEnableCondition_IgnitionON] */
  /*     2 */  /* [#DemEnableConditionGroup_CodingRBTMFL, __Internal_ControlDtcSetting, DemEnableCondition_CodingRBTMFL] */
  /*     3 */  /* [#DemEnableConditionGroup_CodingRBTMFR, __Internal_ControlDtcSetting, DemEnableCondition_CodingRBTMFR] */
  /*     4 */  /* [#DemEnableConditionGroup_ECUPowerUp, __Internal_ControlDtcSetting, DemEnableCondition_ECUPowerUp] */
  /*     5 */  /* [#DemEnableConditionGroup_IgnitionON, __Internal_ControlDtcSetting, DemEnableCondition_IgnitionON] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventDataCommitNumber
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventDataCommitNumber
  \brief  Index = Index in Dem_Cfg_Eventtable
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EventDataCommitNumberType, DEM_VAR_NOINIT) Dem_Cfg_EventDataCommitNumber[43];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventDebounceValue
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventDebounceValue
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Cfg_EventDebounceValueType, DEM_VAR_NOINIT) Dem_Cfg_EventDebounceValue[43];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*     1 */  /* [DTC_0x1ca000, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     2 */  /* [DTC_0x9a6857, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     3 */  /* [DTC_0x164456, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     4 */  /* [DTC_0xa10a00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     5 */  /* [DTC_0xa10b00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     6 */  /* [DTC_0xa10d00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     7 */  /* [DTC_0xa10e00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     8 */  /* [DTC_0xa28b4b, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     9 */  /* [DTC_0xa28b16, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    10 */  /* [DTC_0xa28b17, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    11 */  /* [DTC_0xa28b45, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    12 */  /* [DTC_0xa28b47, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    13 */  /* [DTC_0xa28b49, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    14 */  /* [DTC_0xa28b71, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    15 */  /* [DTC_0xa28b96, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    16 */  /* [DTC_0xa28b97, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    17 */  /* [DTC_0xa28bfa, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    18 */  /* [DTC_0xa20400, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    19 */  /* [DTC_0xc11587, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    20 */  /* [DTC_0xc12287, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    21 */  /* [DTC_0xc15187, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    22 */  /* [DTC_0xc15587, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    23 */  /* [DTC_0xc16887, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    24 */  /* [DTC_0xc20187, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    25 */  /* [DTC_0xc20287, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    26 */  /* [DTC_0xc41608, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    27 */  /* [DTC_0xc42708, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    28 */  /* [DTC_0xc44286, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    29 */  /* [DTC_0xc45208, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    30 */  /* [DTC_0xd12081, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    31 */  /* [DTC_0xd12083, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    32 */  /* [DTC_0xd12087, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    33 */  /* [DTC_0xd22488, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    34 */  /* [DTC_0xd88987, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    35 */  /* [DTC_0xd88a08, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    36 */  /* [SPI_E_HARDWARE_ERROR, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    37 */  /* [WDGM_E_MONITORING, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    38 */  /* [WDGM_E_IMPROPER_CALLER, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    39 */  /* [ADC_ERROR_Dummy, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    40 */  /* [MCU_E_OSC_FAILURE, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    41 */  /* [MCU_E_SYSTEM_PLL_LOCK_LOSS, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    42 */  /* [FEE_E_READ, #NoExtendedDataRecordConfigured, Satellite#0] */

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_EventInternalStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_EventInternalStatus
  \brief  size = DEM_G_NUMBER_OF_EVENTS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(Dem_Event_InternalStatusType, DEM_VAR_NOINIT) Dem_Cfg_EventInternalStatus[43];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [#EVENT_INVALID, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*     1 */  /* [DTC_0x1ca000, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     2 */  /* [DTC_0x9a6857, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     3 */  /* [DTC_0x164456, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     4 */  /* [DTC_0xa10a00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     5 */  /* [DTC_0xa10b00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     6 */  /* [DTC_0xa10d00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     7 */  /* [DTC_0xa10e00, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     8 */  /* [DTC_0xa28b4b, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*     9 */  /* [DTC_0xa28b16, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    10 */  /* [DTC_0xa28b17, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    11 */  /* [DTC_0xa28b45, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    12 */  /* [DTC_0xa28b47, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    13 */  /* [DTC_0xa28b49, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    14 */  /* [DTC_0xa28b71, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    15 */  /* [DTC_0xa28b96, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    16 */  /* [DTC_0xa28b97, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    17 */  /* [DTC_0xa28bfa, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    18 */  /* [DTC_0xa20400, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    19 */  /* [DTC_0xc11587, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    20 */  /* [DTC_0xc12287, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    21 */  /* [DTC_0xc15187, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    22 */  /* [DTC_0xc15587, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    23 */  /* [DTC_0xc16887, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    24 */  /* [DTC_0xc20187, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    25 */  /* [DTC_0xc20287, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    26 */  /* [DTC_0xc41608, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    27 */  /* [DTC_0xc42708, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    28 */  /* [DTC_0xc44286, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    29 */  /* [DTC_0xc45208, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    30 */  /* [DTC_0xd12081, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    31 */  /* [DTC_0xd12083, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    32 */  /* [DTC_0xd12087, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    33 */  /* [DTC_0xd22488, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    34 */  /* [DTC_0xd88987, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    35 */  /* [DTC_0xd88a08, #EdrExtendedDataRecord_StandardEnvironmentData, Satellite#0] */
  /*    36 */  /* [SPI_E_HARDWARE_ERROR, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    37 */  /* [WDGM_E_MONITORING, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    38 */  /* [WDGM_E_IMPROPER_CALLER, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    39 */  /* [ADC_ERROR_Dummy, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    40 */  /* [MCU_E_OSC_FAILURE, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    41 */  /* [MCU_E_SYSTEM_PLL_LOCK_LOSS, #NoExtendedDataRecordConfigured, Satellite#0] */
  /*    42 */  /* [FEE_E_READ, #NoExtendedDataRecordConfigured, Satellite#0] */

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ExtendedDataRecordIteratorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ExtendedDataRecordIteratorTable
  \brief  size = 1
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ExtendedDataRecordIterator_FilterType, DEM_VAR_NOINIT) Dem_Cfg_ExtendedDataRecordIteratorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FilterInfoTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FilterInfoTable
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FilterData_InfoType, DEM_VAR_NOINIT) Dem_Cfg_FilterInfoTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FilterReportedEvents
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FilterReportedEvents
  \brief  size = ceiling( DEM_G_NUMBER_OF_EVENTS / 8 )
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FilterReportedEventsType, DEM_VAR_NOINIT) Dem_Cfg_FilterReportedEvents[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_FreezeFrameIteratorTable
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_FreezeFrameIteratorTable
  \brief  size = DEM_CFG_NUMBER_OF_FREEZEFRAMEITERATORS
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_FreezeFrameIterator_FilterType, DEM_VAR_NOINIT) Dem_Cfg_FreezeFrameIteratorTable[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_IndicatorEventCounters
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_IndicatorEventCounters
  \brief  Table index: Index in Dem_Cfg_IndicatorTable. Table value: Number of Events currently requesting corresponding Indicator.
*/ 
#define DEM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_IndicatorEventCountersType, DEM_VAR_NOINIT) Dem_Cfg_IndicatorEventCounters[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [IndID=0, DTC_0xa20400, DTC_0xa28b45, DTC_0xa28b49, DTC_0xa28b4b, DTC_0xa28b71, DTC_0xa28b96, DTC_0xc12287, DTC_0xc15187, DTC_0xc41608, DTC_0xc42708, DTC_0xc45208] */

#define DEM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryCurrentCount
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryCurrentCountType, DEM_VAR_NOINIT) Dem_Cfg_MemoryCurrentCount[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_MemoryStatus
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_MemoryStatus
  \brief  The array contains these items: Admin, Status, 10 * Primary
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryStatusType, DEM_VAR_NOINIT) Dem_Cfg_MemoryStatus[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryChronology
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_PrimaryChronology
  \brief  size = DEM_CFG_GLOBAL_PRIMARY_SIZE
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_MemoryIndexType, DEM_VAR_NOINIT) Dem_Cfg_PrimaryChronology[10];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_0
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_0;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_1
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_1;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_2
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_2;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_3
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_3;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_4
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_4;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_5
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_5;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_6
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_6;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_7
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_7;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_8
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_8;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_PrimaryEntry_9
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_PrimaryEntryType, DEM_NVM_DATA_NOINIT) Dem_Cfg_PrimaryEntry_9;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReadoutBuffer
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ReadoutBufferEntryType, DEM_VAR_NOINIT) Dem_Cfg_ReadoutBuffer[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_ReportedEventsOfFilter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_ReportedEventsOfFilter
  \brief  size = DEM_CFG_NUMBER_OF_FILTER
*/ 
#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_ReportedEventsType, DEM_VAR_NOINIT) Dem_Cfg_ReportedEventsOfFilter[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_SatelliteInfo0
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_SatelliteInfo0
  \brief  Buffer for satellite data on OsApplication "0"
*/ 
#define DEM_START_SEC_0_VAR_ZERO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_SatelliteInfoType0, DEM_VAR_ZERO_INIT) Dem_Cfg_SatelliteInfo0 = {0};  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_0_VAR_ZERO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StatusData
**********************************************************************************************************************/
#define DEM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_StatusDataType, DEM_NVM_DATA_NOINIT) Dem_Cfg_StatusData;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StorageConditionFulfilled
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_StorageConditionFulfilled
  \brief  (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_ON) Table index: Condition ID. Table value: current condition state 'FALSE' not fulfilled, 'TRUE' fulfilled.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_StorageConditionFulfilledType, DEM_VAR_NOINIT) Dem_Cfg_StorageConditionFulfilled[11];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Dem_Cfg_StorageConditionGroupCounter
**********************************************************************************************************************/
/** 
  \var    Dem_Cfg_StorageConditionGroupCounter
  \brief  (DEM_CFG_HAS_STORAGE_CONDITIONS == STD_ON) Table index: Condition group number. Table value: count of conditions in state 'enable'.
*/ 
#define DEM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Dem_Cfg_StorageConditionGroupCounterType, DEM_VAR_NOINIT) Dem_Cfg_StorageConditionGroupCounter[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [#DemStorageConditionGroup_ECU_LEVEL, DemStorageCondition_SC1_ControlDTC, DemStorageCondition_SC3_LocalVoltage, DemStorageCondition_SC11_VehicleStartup] */
  /*     1 */  /* [#DemStorageConditionGroup_NetworkCommunication, DemStorageCondition_SC1_ControlDTC, DemStorageCondition_SC2_IgnitonStatus, DemStorageCondition_SC4_SystemVoltage, DemStorageCondition_SC5_TransportationMode, DemStorageCondition_SC8_CommunicationStatus, DemStorageCondition_SC10_debounceTimerNC, DemStorageCondition_SC11_VehicleStartup, DemStorageCondition_SC12_ProductionMode] */
  /*     2 */  /* [#DemStorageConditionGroup_NetworkCommunication_WithoutClamp15, DemStorageCondition_SC1_ControlDTC, DemStorageCondition_SC4_SystemVoltage, DemStorageCondition_SC5_TransportationMode, DemStorageCondition_SC8_CommunicationStatus, DemStorageCondition_SC10_debounceTimerNC15, DemStorageCondition_SC11_VehicleStartup, DemStorageCondition_SC12_ProductionMode] */
  /*     3 */  /* [#DemStorageConditionGroup_PowerDistribution, DemStorageCondition_SC1_ControlDTC, DemStorageCondition_SC2_IgnitonStatus, DemStorageCondition_SC5_TransportationMode, DemStorageCondition_SC10_debounceTimerPD, DemStorageCondition_SC11_VehicleStartup, DemStorageCondition_SC12_ProductionMode] */

#define DEM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/



/**********************************************************************************************************************
  END OF FILE: Dem_Lcfg.c     [Daimler, VARIANT-PRE-COMPILE, 22.06.00.146775]
**********************************************************************************************************************/

