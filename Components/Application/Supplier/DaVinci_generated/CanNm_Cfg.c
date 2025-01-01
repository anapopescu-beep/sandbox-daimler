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
 *              File: CanNm_Cfg.c
 *   Generation Time: 2023-07-10 14:36:07
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define CANNM_CFG_SOURCE

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2_0779 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CanNm_Cfg.h"

#include "PduR_Cfg.h"

#include "CanIf_Cfg.h"

#include "Nm.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
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
CONST(CanNm_ChannelConfigType, CANNM_CONST) CanNm_ChannelConfigLeft[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RepeatMessageTime  ActiveWakeUpBitEnabled  AllMessagesKeepAwake  ComControlEnabled  PnHandleMultipleNetworkRequest  ChannelId                                                                ImmediateNmCycleTime  ImmediateNmTransmissions  MsgCycleTime  MsgTimeoutTime  PduCbvPosition    RemoteSleepIndTime  TimeoutTime  WaitBusSleepTime        Referable Keys */
  { /*     0 */              300u,                   TRUE,                 TRUE,              TRUE,                           TRUE, NmConf_NmChannelConfig_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6,                   2u,                       6u,         100u,            50u, CANNM_PDU_BYTE_0,               250u,        250u,             151u }   /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
};
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
CONST(CanNm_ChannelConfigType, CANNM_CONST) CanNm_ChannelConfigRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RepeatMessageTime  ActiveWakeUpBitEnabled  AllMessagesKeepAwake  ComControlEnabled  PnHandleMultipleNetworkRequest  ChannelId                                                                ImmediateNmCycleTime  ImmediateNmTransmissions  MsgCycleTime  MsgTimeoutTime  PduCbvPosition    RemoteSleepIndTime  TimeoutTime  WaitBusSleepTime        Referable Keys */
  { /*     0 */              300u,                   TRUE,                 TRUE,              TRUE,                           TRUE, NmConf_NmChannelConfig_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727,                   2u,                       6u,         100u,            50u, CANNM_PDU_BYTE_0,               250u,        250u,             151u }   /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */
};
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
CONST(CanNm_PbChannelConfigType, CANNM_CONST) CanNm_PbChannelConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PnEnabled  MsgCycleOffset  TxMessageDataEndIdx  TxMessageDataLength  TxMessageDataStartIdx  TxMessageData_CBVIdx  TxMessageData_PnFilterMaskEndIdx  TxMessageData_PnFilterMaskStartIdx  TxMessageData_UserDataEndIdx  TxMessageData_UserDataLength  TxMessageData_UserDataStartIdx  TxPduId                                             TxUserDataPduId                                                    Referable Keys */
  { /*     0 */      TRUE,             0u,                  8u,                  8u,                    0u,                   0u,                               8u,                                 1u,                           8u,                           7u,                             1u, CanIfConf_CanIfTxPduCfg_NM_RBTM_FL_ST3_8b5cec70_Tx, PduRConf_PduRDestPdu_NM_RBTM_FL_ST3_0cdf2d0f_Tx_78db9cf2_Tx }   /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453] */
};
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
CONST(CanNm_PnInfoByteConfigType, CANNM_CONST) CanNm_PnInfoByteConfig[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PnClusterResetTimerEndIdx  PnClusterResetTimerStartIdx  PnFilterMask        Referable Keys */
  { /*     0 */                        8u,                          0u,           1u },  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  { /*     1 */                       16u,                          8u,           0u },  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  { /*     2 */                       24u,                         16u,          16u },  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  { /*     3 */                       32u,                         24u,           0u },  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  { /*     4 */                       40u,                         32u,           0u },  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  { /*     5 */                       48u,                         40u,           0u },  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  { /*     6 */                       56u,                         48u,           0u }   /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */
};
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
VAR(CanNm_CommStateUType, CANNM_VAR_NOINIT) CanNm_CommState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_CoordReadyToSleepStateUType, CANNM_VAR_NOINIT) CanNm_CoordReadyToSleepState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_ImmediateNmMsgCountUType, CANNM_VAR_NOINIT) CanNm_ImmediateNmMsgCount;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_ModuleInitializedType, CANNM_VAR_ZERO_INIT) CanNm_ModuleInitialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(CanNm_MsgConfirmationFlagUType, CANNM_VAR_NOINIT) CanNm_MsgConfirmationFlag;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_MsgIndicationFlagUType, CANNM_VAR_NOINIT) CanNm_MsgIndicationFlag;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_MsgRequestUType, CANNM_VAR_NOINIT) CanNm_MsgRequest;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_MsgTimeoutTimerUType, CANNM_VAR_NOINIT) CanNm_MsgTimeoutTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_MsgTimerUType, CANNM_VAR_NOINIT) CanNm_MsgTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_NetworkRestartFlagUType, CANNM_VAR_NOINIT) CanNm_NetworkRestartFlag;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_NmStateUType, CANNM_VAR_NOINIT) CanNm_NmState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_PnClusterReqUType, CANNM_VAR_NOINIT) CanNm_PnClusterReq;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*     1 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*     2 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*     3 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*     4 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*     5 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*     6 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*     1 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*     2 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*     3 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*     4 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*     5 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*     6 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */

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
VAR(CanNm_PnClusterReqNewUType, CANNM_VAR_NOINIT) CanNm_PnClusterReqNew;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*     1 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*     2 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*     3 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*     4 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*     5 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*     6 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*     1 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*     2 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*     3 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*     4 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*     5 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*     6 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */

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
VAR(CanNm_PnClusterResetTimerUType, CANNM_VAR_NOINIT) CanNm_PnClusterResetTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*     7 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*     8 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*    15 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*    16 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*    23 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*    24 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*    31 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*    32 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*    39 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*    40 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*    47 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*    48 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */
  /*    55 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*     7 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_2] */
  /*     8 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*    15 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_3] */
  /*    16 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*    23 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_4] */
  /*    24 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*    31 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_5] */
  /*    32 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*    39 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_0] */
  /*    40 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*    47 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_1] */
  /*    48 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */
  /*    55 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/CanNmPnInfo/CanNmPnFilterMaskByte_6] */

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
VAR(CanNm_PnMessageFilterDeactivationIndicatedUType, CANNM_VAR_NOINIT) CanNm_PnMessageFilterDeactivationIndicated;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_PnMessageFilterEnabledUType, CANNM_VAR_NOINIT) CanNm_PnMessageFilterEnabled;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_RemoteSleepIndStateUType, CANNM_VAR_NOINIT) CanNm_RemoteSleepIndState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_RemoteSleepTimerUType, CANNM_VAR_NOINIT) CanNm_RemoteSleepTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_RepeatMsgTimerUType, CANNM_VAR_NOINIT) CanNm_RepeatMsgTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_TimeoutTimerUType, CANNM_VAR_NOINIT) CanNm_TimeoutTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_TxControlStateUType, CANNM_VAR_NOINIT) CanNm_TxControlState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_TxControlStateRequestUType, CANNM_VAR_NOINIT) CanNm_TxControlStateRequest;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
VAR(CanNm_TxMessageDataType, CANNM_VAR_NOINIT) CanNm_TxMessageData[8];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_CBV] */
  /*     1 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_UserData, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_PnFilterMask] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_UserData, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_PnFilterMask] */
  /*     7 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_UserData, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_PnFilterMask] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_CBV] */
  /*     1 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_UserData, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_PnFilterMask] */
  /*   ... */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_UserData, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_PnFilterMask] */
  /*     7 */  /* [/ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_UserData, /ActiveEcuC/CanNm/CanNmGlobalConfig/BODY3_8b033453_PnFilterMask] */

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
VAR(CanNm_WaitBusSleepTimerUType, CANNM_VAR_NOINIT) CanNm_WaitBusSleepTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */

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
CONST(CanNm_PCConfigsType, CANNM_CONST) CanNm_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_Left] */
      CanNm_ChannelConfigLeft   /**< the pointer to CanNm_ChannelConfigLeft */
  },
  { /* Index: 1 Keys: [Config_Right] */
      CanNm_ChannelConfigRight  /**< the pointer to CanNm_ChannelConfigRight */
  }
};
#define CANNM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  END OF FILE: CanNm_Cfg.c
**********************************************************************************************************************/

