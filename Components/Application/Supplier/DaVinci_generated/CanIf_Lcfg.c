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
 *            Module: CanIf
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:05
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define CANIF_LCFG_SOURCE

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanNm Header Files  */ 
#include "CanNm_Cfg.h"
#include "CanNm_Cbk.h"
 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  CanTSyn Header Files  */ 
#include "CanTSyn_Cbk.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE

#include "CanIf_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/




 /** 
  \brief  Wake-up validation function.
*/

FUNC(void, CANIF_APPL_CODE) EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType CanWakeupEvents);

#define CANIF_STOP_SEC_APPL_CODE

#include "CanIf_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
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
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MappedTxBuffersConfigEndIdx                                                                                 MappedTxBuffersConfigStartIdx                                                                                       Referable Keys */
  { /*     0 */                          1u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,                            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfg         
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdBitQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CtrlStatesIdx                                                                                 PduIdFirst                           PduIdLast                            TxBufferCfg                                                         TxBufferCfgIdx                                                                               TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,         0u  /* Unused, TxPduId 0 */,        0u  /* Unused, TxPduId 10 */, CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG,                                     0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left}] */
  { /*     1 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,         1u  /* RxPduId */          ,       37u  /* RxPduId  */          ,                                CANIF_NO_TXBUFFERCFGOFMAILBOXCONFIG, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                 , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_d50cf0d9_Rx{Left}] */
  { /*     2 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,         1u  /* RxPduId */          ,       37u  /* RxPduId  */          ,                                CANIF_NO_TXBUFFERCFGOFMAILBOXCONFIG, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex2 */                                 , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_e046a621_Rx{Left}] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MailBoxConfigIdx                                                                                                      Referable Keys */
  { /*     0 */               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                                 Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanNm_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanNm_RxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)CanTSyn_RxIndication }  , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanTSyn_RxIndication] */
  { /*     3 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanTp_RxIndication] */
  { /*     4 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ }   /* [PduR_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigLeft
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigLeft
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigLeft[38] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RxPduCanId                                                                                RxPduMask                                                                 UpperPduId                                                          RxIndicationFctListIdx                                RxPduDlc        Comment                                                                              Referable Keys */
  { /*     0 */ 0x94420000u  /* Lower CanId of range: RBTM_FL_BODY3NMNODE_032841d9_Rx, 2.0- or FD-PDU */, 0xF4420FFFu  /* Upper CanId of range: RBTM_FL_BODY3NMNODE_032841d9_Rx */, CanNmConf_CanNmRxPdu_BODY3_8b033453_Rx                            ,                     1u  /* CanNm_RxIndication */    ,       8u },  /* [PDU: RBTM_FL_BODY3NMNODE_032841d9_Rx, Lower CanId of range: 0x14420000] */  /* [CanIfConf_CanIfRxPduCfg_RBTM_FL_BODY3NMNODE_032841d9_Rx] */
  { /*     1 */ 0x000006E6u  /* ADAS_PREDICTION_ST3_7c36fc01_Rx, 2.0- or FD-PDU */                      , 0x000007FFu  /* ADAS_PREDICTION_ST3_7c36fc01_Rx */                      , PduRConf_PduRSrcPdu_PduRSrcPdu_0518217c                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: ADAS_PREDICTION_ST3_7c36fc01_Rx, CanId: 0x6e6]                     */  /* [CanIfConf_CanIfRxPduCfg_ADAS_PREDICTION_ST3_7c36fc01_Rx] */
  { /*     2 */ 0x000006E0u  /* EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx, 2.0- or FD-PDU */                , 0x000007FFu  /* EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx */                , PduRConf_PduRSrcPdu_PduRSrcPdu_4b27d50a                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx, CanId: 0x6e0]               */  /* [CanIfConf_CanIfRxPduCfg_EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx] */
  { /*     3 */ 0x000006D0u  /* DIAG_Stat_ST3_7f697120_Rx, 2.0- or FD-PDU */                            , 0x000007FFu  /* DIAG_Stat_ST3_7f697120_Rx */                            , PduRConf_PduRSrcPdu_PduRSrcPdu_65d40bec                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: DIAG_Stat_ST3_7f697120_Rx, CanId: 0x6d0]                           */  /* [CanIfConf_CanIfRxPduCfg_DIAG_Stat_ST3_7f697120_Rx] */
  { /*     4 */ 0x000006C5u  /* ELC_Lvr_Stat_ST3_secured_612a2882_Rx, 2.0- or FD-PDU */                 , 0x000007FFu  /* ELC_Lvr_Stat_ST3_secured_612a2882_Rx */                 , PduRConf_PduRSrcPdu_PduRSrcPdu_d27a099a                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: ELC_Lvr_Stat_ST3_secured_612a2882_Rx, CanId: 0x6c5]                */  /* [CanIfConf_CanIfRxPduCfg_ELC_Lvr_Stat_ST3_secured_612a2882_Rx] */
  { /*     5 */ 0x000006C4u  /* NTG_Master_Navi_ST3_1e826461_Rx, 2.0- or FD-PDU */                      , 0x000007FFu  /* NTG_Master_Navi_ST3_1e826461_Rx */                      , PduRConf_PduRSrcPdu_PduRSrcPdu_8a45ba67                           ,                     4u  /* PduR_CanIfRxIndication */,       2u },  /* [PDU: NTG_Master_Navi_ST3_1e826461_Rx, CanId: 0x6c4]                     */  /* [CanIfConf_CanIfRxPduCfg_NTG_Master_Navi_ST3_1e826461_Rx] */
  { /*     6 */ 0x000006C3u  /* DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx, 2.0- or FD-PDU */                     , 0x000007FFu  /* DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx */                     , PduRConf_PduRSrcPdu_PduRSrcPdu_ee8d9c90                           ,                     4u  /* PduR_CanIfRxIndication */,       1u },  /* [PDU: DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx, CanId: 0x6c3]                    */  /* [CanIfConf_CanIfRxPduCfg_DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx] */
  { /*     7 */ 0x000006A3u  /* Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx, 2.0- or FD-PDU */              , 0x000007FFu  /* Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx */              , PduRConf_PduRSrcPdu_PduRSrcPdu_79ab8c0b                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx, CanId: 0x6a3]             */  /* [CanIfConf_CanIfRxPduCfg_Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx] */
  { /*     8 */ 0x000006A2u  /* BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx, 2.0- or FD-PDU */                    , 0x000007FFu  /* BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx */                    , PduRConf_PduRSrcPdu_PduRSrcPdu_350798fb                           ,                     4u  /* PduR_CanIfRxIndication */,       1u },  /* [PDU: BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx, CanId: 0x6a2]                   */  /* [CanIfConf_CanIfRxPduCfg_BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx] */
  { /*     9 */ 0x000006A1u  /* BeltAdj_FR_Stat_ST3_070be586_Rx, 2.0- or FD-PDU */                      , 0x000007FFu  /* BeltAdj_FR_Stat_ST3_070be586_Rx */                      , PduRConf_PduRSrcPdu_PduRSrcPdu_f252e81e                           ,                     4u  /* PduR_CanIfRxIndication */,       1u },  /* [PDU: BeltAdj_FR_Stat_ST3_070be586_Rx, CanId: 0x6a1]                     */  /* [CanIfConf_CanIfRxPduCfg_BeltAdj_FR_Stat_ST3_070be586_Rx] */
  { /*    10 */ 0x00000699u  /* RBTM_FR_Stat_ST3_b20121fa_Rx, 2.0- or FD-PDU */                         , 0x000007FFu  /* RBTM_FR_Stat_ST3_b20121fa_Rx */                         , PduRConf_PduRSrcPdu_PduRSrcPdu_7234ddac                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: RBTM_FR_Stat_ST3_b20121fa_Rx, CanId: 0x699]                        */  /* [CanIfConf_CanIfRxPduCfg_RBTM_FR_Stat_ST3_b20121fa_Rx] */
  { /*    11 */ 0x00000696u  /* ADAS_POSITION_ST3_bc4541a2_Rx, 2.0- or FD-PDU */                        , 0x000007FFu  /* ADAS_POSITION_ST3_bc4541a2_Rx */                        , PduRConf_PduRSrcPdu_PduRSrcPdu_fa09a036                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: ADAS_POSITION_ST3_bc4541a2_Rx, CanId: 0x696]                       */  /* [CanIfConf_CanIfRxPduCfg_ADAS_POSITION_ST3_bc4541a2_Rx] */
  { /*    12 */ 0x00000695u  /* PresfAct_Adj_ST3_87d3ccaf_Rx, 2.0- or FD-PDU */                         , 0x000007FFu  /* PresfAct_Adj_ST3_87d3ccaf_Rx */                         , PduRConf_PduRSrcPdu_PduRSrcPdu_7d3a747f                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: PresfAct_Adj_ST3_87d3ccaf_Rx, CanId: 0x695]                        */  /* [CanIfConf_CanIfRxPduCfg_PresfAct_Adj_ST3_87d3ccaf_Rx] */
  { /*    13 */ 0x98EF0D8Du  /* DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx, 2.0- or FD-PDU */                , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx */                , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_29880c5f                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx, CanId: 0x18ef0d8d]          */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx] */
  { /*    14 */ 0x98EEF989u  /* DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx, 2.0- or FD-PDU */                , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx */                , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a8dd74b8                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx, CanId: 0x18eef989]          */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx] */
  { /*    15 */ 0x98EEF888u  /* DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx, 2.0- or FD-PDU */                , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx */                , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2dd5cd3e                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx, CanId: 0x18eef888]          */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx] */
  { /*    16 */ 0x98E1A48Du  /* DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx, 2.0- or FD-PDU */            , 0x9FFFFFFFu  /* DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx */            , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_afe154c1                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx, CanId: 0x18e1a48d]      */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx] */
  { /*    17 */ 0x98E1A489u  /* DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx, 2.0- or FD-PDU */            , 0x9FFFFFFFu  /* DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx */            , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_5cdfcb87                    ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx, CanId: 0x18e1a489]      */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx] */
  { /*    18 */ 0x98E1A488u  /* DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx, 2.0- or FD-PDU */            , 0x9FFFFFFFu  /* DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx */            , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2f8b5959                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx, CanId: 0x18e1a488]      */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx] */
  { /*    19 */ 0x98E1A441u  /* Develop8_Rq_RBTM_FL_ST3_fe216789_Rx, 2.0- or FD-PDU */                  , 0x9FFFFFFFu  /* Develop8_Rq_RBTM_FL_ST3_fe216789_Rx */                  , PduRConf_PduRSrcPdu_PduRSrcPdu_c2dcef25                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: Develop8_Rq_RBTM_FL_ST3_fe216789_Rx, CanId: 0x18e1a441]            */  /* [CanIfConf_CanIfRxPduCfg_Develop8_Rq_RBTM_FL_ST3_fe216789_Rx] */
  { /*    20 */ 0x000005FCu  /* BeltHdOvr_FL_State_ST3_b4846ceb_Rx, 2.0- or FD-PDU */                   , 0x000007FFu  /* BeltHdOvr_FL_State_ST3_b4846ceb_Rx */                   , PduRConf_PduRSrcPdu_PduRSrcPdu_11170208                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: BeltHdOvr_FL_State_ST3_b4846ceb_Rx, CanId: 0x5fc]                  */  /* [CanIfConf_CanIfRxPduCfg_BeltHdOvr_FL_State_ST3_b4846ceb_Rx] */
  { /*    21 */ 0x00000592u  /* CLkS_Dr_State_ST3_27f55e1e_Rx, 2.0- or FD-PDU */                        , 0x000007FFu  /* CLkS_Dr_State_ST3_27f55e1e_Rx */                        , PduRConf_PduRSrcPdu_PduRSrcPdu_0fa9281f                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: CLkS_Dr_State_ST3_27f55e1e_Rx, CanId: 0x592]                       */  /* [CanIfConf_CanIfRxPduCfg_CLkS_Dr_State_ST3_27f55e1e_Rx] */
  { /*    22 */ 0x00000582u  /* PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx, 2.0- or FD-PDU */              , 0x000007FFu  /* PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx */              , PduRConf_PduRSrcPdu_PduRSrcPdu_3ba6bace                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx, CanId: 0x582]             */  /* [CanIfConf_CanIfRxPduCfg_PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx] */
  { /*    23 */ 0x00000565u  /* DI_OdoSpeedometer_ST3_11e98e6f_Rx, 2.0- or FD-PDU */                    , 0x000007FFu  /* DI_OdoSpeedometer_ST3_11e98e6f_Rx */                    , PduRConf_PduRSrcPdu_PduRSrcPdu_3e9512b9                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: DI_OdoSpeedometer_ST3_11e98e6f_Rx, CanId: 0x565]                   */  /* [CanIfConf_CanIfRxPduCfg_DI_OdoSpeedometer_ST3_11e98e6f_Rx] */
  { /*    24 */ 0x0000053Du  /* ADAS_PROFILE_SHORT_ST3_7ff16020_Rx, 2.0- or FD-PDU */                   , 0x000007FFu  /* ADAS_PROFILE_SHORT_ST3_7ff16020_Rx */                   , PduRConf_PduRSrcPdu_PduRSrcPdu_e0198081                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: ADAS_PROFILE_SHORT_ST3_7ff16020_Rx, CanId: 0x53d]                  */  /* [CanIfConf_CanIfRxPduCfg_ADAS_PROFILE_SHORT_ST3_7ff16020_Rx] */
  { /*    25 */ 0x00000465u  /* Impact3_ST3_c1d5b894_Rx, 2.0- or FD-PDU */                              , 0x000007FFu  /* Impact3_ST3_c1d5b894_Rx */                              , PduRConf_PduRSrcPdu_PduRSrcPdu_7842cc32                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: Impact3_ST3_c1d5b894_Rx, CanId: 0x465]                             */  /* [CanIfConf_CanIfRxPduCfg_Impact3_ST3_c1d5b894_Rx] */
  { /*    26 */ 0x00000464u  /* PN14_Master_Stat1_ST3_56fd286b_Rx, 2.0- or FD-PDU */                    , 0x000007FFu  /* PN14_Master_Stat1_ST3_56fd286b_Rx */                    , PduRConf_PduRSrcPdu_PduRSrcPdu_a0c57bb3                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: PN14_Master_Stat1_ST3_56fd286b_Rx, CanId: 0x464]                   */  /* [CanIfConf_CanIfRxPduCfg_PN14_Master_Stat1_ST3_56fd286b_Rx] */
  { /*    27 */ 0x00000463u  /* Impact2_ST3_e5526ccc_Rx, 2.0- or FD-PDU */                              , 0x000007FFu  /* Impact2_ST3_e5526ccc_Rx */                              , PduRConf_PduRSrcPdu_PduRSrcPdu_22492bdd                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: Impact2_ST3_e5526ccc_Rx, CanId: 0x463]                             */  /* [CanIfConf_CanIfRxPduCfg_Impact2_ST3_e5526ccc_Rx] */
  { /*    28 */ 0x0000035Fu  /* PT4_PTCoor4_ST3_59056fb4_Rx, 2.0- or FD-PDU */                          , 0x000007FFu  /* PT4_PTCoor4_ST3_59056fb4_Rx */                          , PduRConf_PduRSrcPdu_PduRSrcPdu_a7894e67                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: PT4_PTCoor4_ST3_59056fb4_Rx, CanId: 0x35f]                         */  /* [CanIfConf_CanIfRxPduCfg_PT4_PTCoor4_ST3_59056fb4_Rx] */
  { /*    29 */ 0x0000030Eu  /* SBeltTens_SP_Lvl_ST3_7cf5644e_Rx, 2.0- or FD-PDU */                     , 0x000007FFu  /* SBeltTens_SP_Lvl_ST3_7cf5644e_Rx */                     , PduRConf_PduRSrcPdu_PduRSrcPdu_c609bb6e                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: SBeltTens_SP_Lvl_ST3_7cf5644e_Rx, CanId: 0x30e]                    */  /* [CanIfConf_CanIfRxPduCfg_SBeltTens_SP_Lvl_ST3_7cf5644e_Rx] */
  { /*    30 */ 0x00000304u  /* PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx, 2.0- or FD-PDU */                  , 0x000007FFu  /* PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx */                  , PduRConf_PduRSrcPdu_PduRSrcPdu_470e8c8b                           ,                     4u  /* PduR_CanIfRxIndication */,       1u },  /* [PDU: PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx, CanId: 0x304]                 */  /* [CanIfConf_CanIfRxPduCfg_PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx] */
  { /*    31 */ 0x000002EFu  /* VSS_TP_SharedSecret_ST3_70962814_Rx, 2.0- or FD-PDU */                  , 0x000007FFu  /* VSS_TP_SharedSecret_ST3_70962814_Rx */                  , PduRConf_PduRSrcPdu_PduRSrcPdu_44cfb2dc                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_SharedSecret_ST3_70962814_Rx, CanId: 0x2ef]                 */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_SharedSecret_ST3_70962814_Rx] */
  { /*    32 */ 0x000002EDu  /* VSS_TP_Auth_ST3_1d67253f_Rx, 2.0- or FD-PDU */                          , 0x000007FFu  /* VSS_TP_Auth_ST3_1d67253f_Rx */                          , PduRConf_PduRSrcPdu_PduRSrcPdu_c76c8221                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_Auth_ST3_1d67253f_Rx, CanId: 0x2ed]                         */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_Auth_ST3_1d67253f_Rx] */
  { /*    33 */ 0x000002EBu  /* VSS_TP_VIN_ST3_b3b4e778_Rx, 2.0- or FD-PDU */                           , 0x000007FFu  /* VSS_TP_VIN_ST3_b3b4e778_Rx */                           , PduRConf_PduRSrcPdu_PduRSrcPdu_da8efc5d                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_VIN_ST3_b3b4e778_Rx, CanId: 0x2eb]                          */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_VIN_ST3_b3b4e778_Rx] */
  { /*    34 */ 0x000002EAu  /* VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx, 2.0- or FD-PDU */             , 0x000007FFu  /* VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx */             , PduRConf_PduRSrcPdu_PduRSrcPdu_13123c17                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx, CanId: 0x2ea]            */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx] */
  { /*    35 */ 0x000002E5u  /* VSS_TP_RealTmOffset_ST3_012f1a71_Rx, 2.0- or FD-PDU */                  , 0x000007FFu  /* VSS_TP_RealTmOffset_ST3_012f1a71_Rx */                  , PduRConf_PduRSrcPdu_PduRSrcPdu_9136979d                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_RealTmOffset_ST3_012f1a71_Rx, CanId: 0x2e5]                 */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_RealTmOffset_ST3_012f1a71_Rx] */
  { /*    36 */ 0x0000007Fu  /* Ign_Stat_ST3_secured_07d79dc2_Rx, 2.0- or FD-PDU */                     , 0x000007FFu  /* Ign_Stat_ST3_secured_07d79dc2_Rx */                     , PduRConf_PduRSrcPdu_PduRSrcPdu_f57d7485                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: Ign_Stat_ST3_secured_07d79dc2_Rx, CanId: 0x7f]                     */  /* [CanIfConf_CanIfRxPduCfg_Ign_Stat_ST3_secured_07d79dc2_Rx] */
  { /*    37 */ 0x00000079u  /* GTS_Main_CAN_ST3_007ffebc_Rx, 2.0- or FD-PDU */                         , 0x000007FFu  /* GTS_Main_CAN_ST3_007ffebc_Rx */                         , CanTSynConf_CanTSynGlobalTimeSlavePdu_GTS_Main_CAN_ST3_dd88dcd5_Rx,                     2u  /* CanTSyn_RxIndication */  ,       8u }   /* [PDU: GTS_Main_CAN_ST3_007ffebc_Rx, CanId: 0x79]                         */  /* [CanIfConf_CanIfRxPduCfg_GTS_Main_CAN_ST3_007ffebc_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRight
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRight
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRight[38] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RxPduCanId                                                                                RxPduMask                                                                 UpperPduId                                                          RxIndicationFctListIdx                                RxPduDlc        Comment                                                                              Referable Keys */
  { /*     0 */ 0x94420000u  /* Lower CanId of range: RBTM_FR_BODY3NMNODE_65b97d54_Rx, 2.0- or FD-PDU */, 0xF4420FFFu  /* Upper CanId of range: RBTM_FR_BODY3NMNODE_65b97d54_Rx */, CanNmConf_CanNmRxPdu_BODY3_8b033453_Rx                            ,                     1u  /* CanNm_RxIndication */    ,       8u },  /* [PDU: RBTM_FR_BODY3NMNODE_65b97d54_Rx, Lower CanId of range: 0x14420000] */  /* [CanIfConf_CanIfRxPduCfg_RBTM_FR_BODY3NMNODE_65b97d54_Rx] */
  { /*     1 */ 0x000006E6u  /* ADAS_PREDICTION_ST3_7c36fc01_Rx, 2.0- or FD-PDU */                      , 0x000007FFu  /* ADAS_PREDICTION_ST3_7c36fc01_Rx */                      , PduRConf_PduRSrcPdu_PduRSrcPdu_0518217c                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: ADAS_PREDICTION_ST3_7c36fc01_Rx, CanId: 0x6e6]                     */  /* [CanIfConf_CanIfRxPduCfg_ADAS_PREDICTION_ST3_7c36fc01_Rx] */
  { /*     2 */ 0x000006E0u  /* EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx, 2.0- or FD-PDU */                , 0x000007FFu  /* EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx */                , PduRConf_PduRSrcPdu_PduRSrcPdu_4b27d50a                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx, CanId: 0x6e0]               */  /* [CanIfConf_CanIfRxPduCfg_EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx] */
  { /*     3 */ 0x000006D0u  /* DIAG_Stat_ST3_7f697120_Rx, 2.0- or FD-PDU */                            , 0x000007FFu  /* DIAG_Stat_ST3_7f697120_Rx */                            , PduRConf_PduRSrcPdu_PduRSrcPdu_65d40bec                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: DIAG_Stat_ST3_7f697120_Rx, CanId: 0x6d0]                           */  /* [CanIfConf_CanIfRxPduCfg_DIAG_Stat_ST3_7f697120_Rx] */
  { /*     4 */ 0x000006C5u  /* ELC_Lvr_Stat_ST3_secured_612a2882_Rx, 2.0- or FD-PDU */                 , 0x000007FFu  /* ELC_Lvr_Stat_ST3_secured_612a2882_Rx */                 , PduRConf_PduRSrcPdu_PduRSrcPdu_d27a099a                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: ELC_Lvr_Stat_ST3_secured_612a2882_Rx, CanId: 0x6c5]                */  /* [CanIfConf_CanIfRxPduCfg_ELC_Lvr_Stat_ST3_secured_612a2882_Rx] */
  { /*     5 */ 0x000006C4u  /* NTG_Master_Navi_ST3_1e826461_Rx, 2.0- or FD-PDU */                      , 0x000007FFu  /* NTG_Master_Navi_ST3_1e826461_Rx */                      , PduRConf_PduRSrcPdu_PduRSrcPdu_8a45ba67                           ,                     4u  /* PduR_CanIfRxIndication */,       2u },  /* [PDU: NTG_Master_Navi_ST3_1e826461_Rx, CanId: 0x6c4]                     */  /* [CanIfConf_CanIfRxPduCfg_NTG_Master_Navi_ST3_1e826461_Rx] */
  { /*     6 */ 0x000006C3u  /* DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx, 2.0- or FD-PDU */                     , 0x000007FFu  /* DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx */                     , PduRConf_PduRSrcPdu_PduRSrcPdu_ee8d9c90                           ,                     4u  /* PduR_CanIfRxIndication */,       1u },  /* [PDU: DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx, CanId: 0x6c3]                    */  /* [CanIfConf_CanIfRxPduCfg_DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx] */
  { /*     7 */ 0x000006A3u  /* Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx, 2.0- or FD-PDU */              , 0x000007FFu  /* Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx */              , PduRConf_PduRSrcPdu_PduRSrcPdu_79ab8c0b                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx, CanId: 0x6a3]             */  /* [CanIfConf_CanIfRxPduCfg_Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx] */
  { /*     8 */ 0x000006A2u  /* BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx, 2.0- or FD-PDU */                    , 0x000007FFu  /* BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx */                    , PduRConf_PduRSrcPdu_PduRSrcPdu_350798fb                           ,                     4u  /* PduR_CanIfRxIndication */,       1u },  /* [PDU: BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx, CanId: 0x6a2]                   */  /* [CanIfConf_CanIfRxPduCfg_BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx] */
  { /*     9 */ 0x000006A0u  /* BeltAdj_FL_Stat_ST3_df27ce55_Rx, 2.0- or FD-PDU */                      , 0x000007FFu  /* BeltAdj_FL_Stat_ST3_df27ce55_Rx */                      , PduRConf_PduRSrcPdu_PduRSrcPdu_9982cecc                           ,                     4u  /* PduR_CanIfRxIndication */,       1u },  /* [PDU: BeltAdj_FL_Stat_ST3_df27ce55_Rx, CanId: 0x6a0]                     */  /* [CanIfConf_CanIfRxPduCfg_BeltAdj_FL_Stat_ST3_df27ce55_Rx] */
  { /*    10 */ 0x00000698u  /* RBTM_FL_Stat_ST3_558a33d8_Rx, 2.0- or FD-PDU */                         , 0x000007FFu  /* RBTM_FL_Stat_ST3_558a33d8_Rx */                         , PduRConf_PduRSrcPdu_PduRSrcPdu_16ae0594                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: RBTM_FL_Stat_ST3_558a33d8_Rx, CanId: 0x698]                        */  /* [CanIfConf_CanIfRxPduCfg_RBTM_FL_Stat_ST3_558a33d8_Rx] */
  { /*    11 */ 0x00000696u  /* ADAS_POSITION_ST3_bc4541a2_Rx, 2.0- or FD-PDU */                        , 0x000007FFu  /* ADAS_POSITION_ST3_bc4541a2_Rx */                        , PduRConf_PduRSrcPdu_PduRSrcPdu_fa09a036                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: ADAS_POSITION_ST3_bc4541a2_Rx, CanId: 0x696]                       */  /* [CanIfConf_CanIfRxPduCfg_ADAS_POSITION_ST3_bc4541a2_Rx] */
  { /*    12 */ 0x00000695u  /* PresfAct_Adj_ST3_87d3ccaf_Rx, 2.0- or FD-PDU */                         , 0x000007FFu  /* PresfAct_Adj_ST3_87d3ccaf_Rx */                         , PduRConf_PduRSrcPdu_PduRSrcPdu_7d3a747f                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: PresfAct_Adj_ST3_87d3ccaf_Rx, CanId: 0x695]                        */  /* [CanIfConf_CanIfRxPduCfg_PresfAct_Adj_ST3_87d3ccaf_Rx] */
  { /*    13 */ 0x98EF0D8Du  /* DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx, 2.0- or FD-PDU */                , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx */                , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_68607596                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx, CanId: 0x18ef0d8d]          */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx] */
  { /*    14 */ 0x98EEF989u  /* DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx, 2.0- or FD-PDU */                , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx */                , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_42fcb720                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx, CanId: 0x18eef989]          */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx] */
  { /*    15 */ 0x98EEF888u  /* DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx, 2.0- or FD-PDU */                , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx */                , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4461701a                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx, CanId: 0x18eef888]          */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx] */
  { /*    16 */ 0x98E1A58Du  /* DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx, 2.0- or FD-PDU */            , 0x9FFFFFFFu  /* DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx */            , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4b1f8ee6                        ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx, CanId: 0x18e1a58d]      */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx] */
  { /*    17 */ 0x98E1A589u  /* DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx, 2.0- or FD-PDU */            , 0x9FFFFFFFu  /* DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx */            , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ebeac4b1                    ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx, CanId: 0x18e1a589]      */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx] */
  { /*    18 */ 0x98E1A588u  /* DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx, 2.0- or FD-PDU */            , 0x9FFFFFFFu  /* DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx */            , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_619ae506                    ,                     3u  /* CanTp_RxIndication */    ,       8u },  /* [PDU: DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx, CanId: 0x18e1a588]      */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx] */
  { /*    19 */ 0x98E1A541u  /* Develop8_Rq_RBTM_FR_ST3_197eb912_Rx, 2.0- or FD-PDU */                  , 0x9FFFFFFFu  /* Develop8_Rq_RBTM_FR_ST3_197eb912_Rx */                  , PduRConf_PduRSrcPdu_PduRSrcPdu_73b8d236                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: Develop8_Rq_RBTM_FR_ST3_197eb912_Rx, CanId: 0x18e1a541]            */  /* [CanIfConf_CanIfRxPduCfg_Develop8_Rq_RBTM_FR_ST3_197eb912_Rx] */
  { /*    20 */ 0x000005FDu  /* BeltHdOvr_FR_State_ST3_61b04b2f_Rx, 2.0- or FD-PDU */                   , 0x000007FFu  /* BeltHdOvr_FR_State_ST3_61b04b2f_Rx */                   , PduRConf_PduRSrcPdu_PduRSrcPdu_4c2f4fea                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: BeltHdOvr_FR_State_ST3_61b04b2f_Rx, CanId: 0x5fd]                  */  /* [CanIfConf_CanIfRxPduCfg_BeltHdOvr_FR_State_ST3_61b04b2f_Rx] */
  { /*    21 */ 0x00000592u  /* CLkS_Dr_State_ST3_27f55e1e_Rx, 2.0- or FD-PDU */                        , 0x000007FFu  /* CLkS_Dr_State_ST3_27f55e1e_Rx */                        , PduRConf_PduRSrcPdu_PduRSrcPdu_0fa9281f                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: CLkS_Dr_State_ST3_27f55e1e_Rx, CanId: 0x592]                       */  /* [CanIfConf_CanIfRxPduCfg_CLkS_Dr_State_ST3_27f55e1e_Rx] */
  { /*    22 */ 0x00000582u  /* PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx, 2.0- or FD-PDU */              , 0x000007FFu  /* PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx */              , PduRConf_PduRSrcPdu_PduRSrcPdu_3ba6bace                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx, CanId: 0x582]             */  /* [CanIfConf_CanIfRxPduCfg_PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx] */
  { /*    23 */ 0x00000565u  /* DI_OdoSpeedometer_ST3_11e98e6f_Rx, 2.0- or FD-PDU */                    , 0x000007FFu  /* DI_OdoSpeedometer_ST3_11e98e6f_Rx */                    , PduRConf_PduRSrcPdu_PduRSrcPdu_3e9512b9                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: DI_OdoSpeedometer_ST3_11e98e6f_Rx, CanId: 0x565]                   */  /* [CanIfConf_CanIfRxPduCfg_DI_OdoSpeedometer_ST3_11e98e6f_Rx] */
  { /*    24 */ 0x0000053Du  /* ADAS_PROFILE_SHORT_ST3_7ff16020_Rx, 2.0- or FD-PDU */                   , 0x000007FFu  /* ADAS_PROFILE_SHORT_ST3_7ff16020_Rx */                   , PduRConf_PduRSrcPdu_PduRSrcPdu_e0198081                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: ADAS_PROFILE_SHORT_ST3_7ff16020_Rx, CanId: 0x53d]                  */  /* [CanIfConf_CanIfRxPduCfg_ADAS_PROFILE_SHORT_ST3_7ff16020_Rx] */
  { /*    25 */ 0x00000465u  /* Impact3_ST3_c1d5b894_Rx, 2.0- or FD-PDU */                              , 0x000007FFu  /* Impact3_ST3_c1d5b894_Rx */                              , PduRConf_PduRSrcPdu_PduRSrcPdu_7842cc32                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: Impact3_ST3_c1d5b894_Rx, CanId: 0x465]                             */  /* [CanIfConf_CanIfRxPduCfg_Impact3_ST3_c1d5b894_Rx] */
  { /*    26 */ 0x00000464u  /* PN14_Master_Stat1_ST3_56fd286b_Rx, 2.0- or FD-PDU */                    , 0x000007FFu  /* PN14_Master_Stat1_ST3_56fd286b_Rx */                    , PduRConf_PduRSrcPdu_PduRSrcPdu_a0c57bb3                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: PN14_Master_Stat1_ST3_56fd286b_Rx, CanId: 0x464]                   */  /* [CanIfConf_CanIfRxPduCfg_PN14_Master_Stat1_ST3_56fd286b_Rx] */
  { /*    27 */ 0x00000463u  /* Impact2_ST3_e5526ccc_Rx, 2.0- or FD-PDU */                              , 0x000007FFu  /* Impact2_ST3_e5526ccc_Rx */                              , PduRConf_PduRSrcPdu_PduRSrcPdu_22492bdd                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: Impact2_ST3_e5526ccc_Rx, CanId: 0x463]                             */  /* [CanIfConf_CanIfRxPduCfg_Impact2_ST3_e5526ccc_Rx] */
  { /*    28 */ 0x0000035Fu  /* PT4_PTCoor4_ST3_59056fb4_Rx, 2.0- or FD-PDU */                          , 0x000007FFu  /* PT4_PTCoor4_ST3_59056fb4_Rx */                          , PduRConf_PduRSrcPdu_PduRSrcPdu_a7894e67                           ,                     4u  /* PduR_CanIfRxIndication */,       4u },  /* [PDU: PT4_PTCoor4_ST3_59056fb4_Rx, CanId: 0x35f]                         */  /* [CanIfConf_CanIfRxPduCfg_PT4_PTCoor4_ST3_59056fb4_Rx] */
  { /*    29 */ 0x0000030Eu  /* SBeltTens_SP_Lvl_ST3_7cf5644e_Rx, 2.0- or FD-PDU */                     , 0x000007FFu  /* SBeltTens_SP_Lvl_ST3_7cf5644e_Rx */                     , PduRConf_PduRSrcPdu_PduRSrcPdu_c609bb6e                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: SBeltTens_SP_Lvl_ST3_7cf5644e_Rx, CanId: 0x30e]                    */  /* [CanIfConf_CanIfRxPduCfg_SBeltTens_SP_Lvl_ST3_7cf5644e_Rx] */
  { /*    30 */ 0x00000304u  /* PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx, 2.0- or FD-PDU */                  , 0x000007FFu  /* PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx */                  , PduRConf_PduRSrcPdu_PduRSrcPdu_470e8c8b                           ,                     4u  /* PduR_CanIfRxIndication */,       1u },  /* [PDU: PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx, CanId: 0x304]                 */  /* [CanIfConf_CanIfRxPduCfg_PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx] */
  { /*    31 */ 0x000002EFu  /* VSS_TP_SharedSecret_ST3_70962814_Rx, 2.0- or FD-PDU */                  , 0x000007FFu  /* VSS_TP_SharedSecret_ST3_70962814_Rx */                  , PduRConf_PduRSrcPdu_PduRSrcPdu_44cfb2dc                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_SharedSecret_ST3_70962814_Rx, CanId: 0x2ef]                 */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_SharedSecret_ST3_70962814_Rx] */
  { /*    32 */ 0x000002EDu  /* VSS_TP_Auth_ST3_1d67253f_Rx, 2.0- or FD-PDU */                          , 0x000007FFu  /* VSS_TP_Auth_ST3_1d67253f_Rx */                          , PduRConf_PduRSrcPdu_PduRSrcPdu_c76c8221                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_Auth_ST3_1d67253f_Rx, CanId: 0x2ed]                         */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_Auth_ST3_1d67253f_Rx] */
  { /*    33 */ 0x000002EBu  /* VSS_TP_VIN_ST3_b3b4e778_Rx, 2.0- or FD-PDU */                           , 0x000007FFu  /* VSS_TP_VIN_ST3_b3b4e778_Rx */                           , PduRConf_PduRSrcPdu_PduRSrcPdu_da8efc5d                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_VIN_ST3_b3b4e778_Rx, CanId: 0x2eb]                          */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_VIN_ST3_b3b4e778_Rx] */
  { /*    34 */ 0x000002EAu  /* VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx, 2.0- or FD-PDU */             , 0x000007FFu  /* VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx */             , PduRConf_PduRSrcPdu_PduRSrcPdu_13123c17                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx, CanId: 0x2ea]            */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx] */
  { /*    35 */ 0x000002E5u  /* VSS_TP_RealTmOffset_ST3_012f1a71_Rx, 2.0- or FD-PDU */                  , 0x000007FFu  /* VSS_TP_RealTmOffset_ST3_012f1a71_Rx */                  , PduRConf_PduRSrcPdu_PduRSrcPdu_9136979d                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: VSS_TP_RealTmOffset_ST3_012f1a71_Rx, CanId: 0x2e5]                 */  /* [CanIfConf_CanIfRxPduCfg_VSS_TP_RealTmOffset_ST3_012f1a71_Rx] */
  { /*    36 */ 0x0000007Fu  /* Ign_Stat_ST3_secured_07d79dc2_Rx, 2.0- or FD-PDU */                     , 0x000007FFu  /* Ign_Stat_ST3_secured_07d79dc2_Rx */                     , PduRConf_PduRSrcPdu_PduRSrcPdu_f57d7485                           ,                     4u  /* PduR_CanIfRxIndication */,       8u },  /* [PDU: Ign_Stat_ST3_secured_07d79dc2_Rx, CanId: 0x7f]                     */  /* [CanIfConf_CanIfRxPduCfg_Ign_Stat_ST3_secured_07d79dc2_Rx] */
  { /*    37 */ 0x00000079u  /* GTS_Main_CAN_ST3_007ffebc_Rx, 2.0- or FD-PDU */                         , 0x000007FFu  /* GTS_Main_CAN_ST3_007ffebc_Rx */                         , CanTSynConf_CanTSynGlobalTimeSlavePdu_GTS_Main_CAN_ST3_dd88dcd5_Rx,                     2u  /* CanTSyn_RxIndication */  ,       8u }   /* [PDU: GTS_Main_CAN_ST3_007ffebc_Rx, CanId: 0x79]                         */  /* [CanIfConf_CanIfRxPduCfg_GTS_Main_CAN_ST3_007ffebc_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBitQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBitQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BIT_QUEUE
  \details
  Element                       Description
  BitPos2TxPduIdOffset      
  TxBufferPrioByCanIdBaseIdx    the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxQueueFlagsEndIdx            the end index of the 1:n relation pointing to CanIf_TxQueueFlags
  TxQueueFlagsStartIdx          the start index of the 1:n relation pointing to CanIf_TxQueueFlags
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdBitQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdBitQueueConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BitPos2TxPduIdOffset  TxBufferPrioByCanIdBaseIdx                                                       TxQueueFlagsEndIdx                                                       TxQueueFlagsStartIdx                                                             Referable Keys */
  { /*     0 */                   0u,                         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */,                 1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */,                   0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanNm_TxConfirmation                  ,  /* [CanNm_TxConfirmation] */
  /*     2 */ CanTp_TxConfirmation                  ,  /* [CanTp_TxConfirmation] */
  /*     3 */ PduR_CanIfTxConfirmation                 /* [PduR_CanIfTxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigLeft
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigLeft
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigLeft[11] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    CanId        UpperLayerTxPduId                                         IsTxPduTruncation  CtrlStatesIdx                                                                                 MailBoxConfigIdx                                                                                                TxConfirmationFctListIdx                                  TxPduLength        Comment                                                      Referable Keys */
  { /*     0 */ 0x000006A0u, PduRConf_PduRDestPdu_BeltAdj_FL_Stat_ST3_71e5093a_Tx    , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       3u  /* PduR_CanIfTxConfirmation */,          1u },  /* [PDU: BeltAdj_FL_Stat_ST3_df27ce55_Tx]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BeltAdj_FL_Stat_ST3_df27ce55_Tx{Left}] */
  { /*     1 */ 0x00000698u, PduRConf_PduRDestPdu_RBTM_FL_Stat_ST3_d76d14af_Tx       , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: RBTM_FL_Stat_ST3_558a33d8_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FL_Stat_ST3_558a33d8_Tx{Left}] */
  { /*     2 */ 0x98E1A490u, PduRConf_PduRDestPdu_Meas8_RBTM_FL_ST3_b4f3e350_Tx      , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: Meas8_RBTM_FL_ST3_a87f4b23_Tx]             */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meas8_RBTM_FL_ST3_a87f4b23_Tx{Left}] */
  { /*     3 */ 0x98E1A485u, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_afe154c1          , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{Left}] */
  { /*     4 */ 0x98E1A481u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_5cdfcb87              , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{Left}] */
  { /*     5 */ 0x98E1A480u, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_2f8b5959          , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{Left}] */
  { /*     6 */ 0x98E1A440u, PduRConf_PduRDestPdu_Develop8_Rs_RBTM_FL_ST3_711f265e_Tx, FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx{Left}] */
  { /*     7 */ 0x98E1A400u, PduRConf_PduRDestPdu_ROE_RBTM_FL_ST3_75ad963a_Tx        , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: ROE_RBTM_FL_ST3_e9956dfc_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ROE_RBTM_FL_ST3_e9956dfc_Tx{Left}] */
  { /*     8 */ 0x964201A4u, PduRConf_PduRDestPdu_ECU_Stat_RBTM_FL_ST3_42655720_Tx   , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx{Left}] */
  { /*     9 */ 0x944201A4u, CanNmConf_CanNmTxPdu_NM_RBTM_FL_ST3_b7c99fb7_Tx         , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       1u  /* CanNm_TxConfirmation */    ,          8u },  /* [PDU: NM_RBTM_FL_ST3_8b5cec70_Tx]                */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_RBTM_FL_ST3_8b5cec70_Tx{Left}] */
  { /*    10 */ 0x0000030Fu, PduRConf_PduRDestPdu_RBTM_FL_Tens_ST3_49d8a970_Tx       , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u }   /* [PDU: RBTM_FL_Tens_ST3_1446be6f_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FL_Tens_ST3_1446be6f_Tx{Left}] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRight
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRight
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRight[11] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    CanId        UpperLayerTxPduId                                         IsTxPduTruncation  CtrlStatesIdx                                                                                  MailBoxConfigIdx                                                                                                 TxConfirmationFctListIdx                                  TxPduLength        Comment                                                      Referable Keys */
  { /*     0 */ 0x000006A1u, PduRConf_PduRDestPdu_BeltAdj_FR_Stat_ST3_2b5906f9_Tx    , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       3u  /* PduR_CanIfTxConfirmation */,          1u },  /* [PDU: BeltAdj_FR_Stat_ST3_070be586_Tx]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BeltAdj_FR_Stat_ST3_070be586_Tx{Right}] */
  { /*     1 */ 0x00000699u, PduRConf_PduRDestPdu_RBTM_FR_Stat_ST3_8dd11b6c_Tx       , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: RBTM_FR_Stat_ST3_b20121fa_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FR_Stat_ST3_b20121fa_Tx{Right}] */
  { /*     2 */ 0x98E1A590u, PduRConf_PduRDestPdu_Meas8_RBTM_FR_ST3_6f1e0041_Tx      , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: Meas8_RBTM_FR_ST3_492d97af_Tx]             */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meas8_RBTM_FR_ST3_492d97af_Tx{Right}] */
  { /*     3 */ 0x98E1A585u, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_4b1f8ee6          , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx{Right}] */
  { /*     4 */ 0x98E1A581u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ebeac4b1              , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx{Right}] */
  { /*     5 */ 0x98E1A580u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_619ae506              , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       2u  /* CanTp_TxConfirmation */    ,          8u },  /* [PDU: DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx{Right}] */
  { /*     6 */ 0x98E1A540u, PduRConf_PduRDestPdu_Develop8_Rs_RBTM_FR_ST3_aaf2c54f_Tx, FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: Develop8_Rs_RBTM_FR_ST3_1a924f62_Tx]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Develop8_Rs_RBTM_FR_ST3_1a924f62_Tx{Right}] */
  { /*     7 */ 0x98E1A500u, PduRConf_PduRDestPdu_ROE_RBTM_FR_ST3_ae40752b_Tx        , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: ROE_RBTM_FR_ST3_d7dfdf54_Tx]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ROE_RBTM_FR_ST3_d7dfdf54_Tx{Right}] */
  { /*     8 */ 0x964201A5u, PduRConf_PduRDestPdu_ECU_Stat_RBTM_FR_ST3_9988b431_Tx   , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u },  /* [PDU: ECU_Stat_RBTM_FR_ST3_430ba797_Tx]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ECU_Stat_RBTM_FR_ST3_430ba797_Tx{Right}] */
  { /*     9 */ 0x944201A5u, CanNmConf_CanNmTxPdu_NM_RBTM_FR_ST3_6c247ca6_Tx         , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       1u  /* CanNm_TxConfirmation */    ,          8u },  /* [PDU: NM_RBTM_FR_ST3_d6dddcba_Tx]                */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_RBTM_FR_ST3_d6dddcba_Tx{Right}] */
  { /*    10 */ 0x00000310u, PduRConf_PduRDestPdu_RBTM_FR_Tens_ST3_1364a6b3_Tx       , FALSE            ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{Right} */,                       3u  /* PduR_CanIfTxConfirmation */,          8u }   /* [PDU: RBTM_FR_Tens_ST3_019feca0_Tx]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FR_Tens_ST3_019feca0_Tx{Right}] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle-Id to corresponding Tx buffer handle-Id. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element       Description
  TxQueue   
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxQueue                                 TxQueueIdx                                                                                              Comment                                                                                Referable Keys */
  { /*     0 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BeltAdj_FL_Stat_ST3_df27ce55_Tx{Left} */           },  /* [BeltAdj_FL_Stat_ST3_df27ce55_Tx, BasicCAN TxPdu with Tx-buffer]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BeltAdj_FL_Stat_ST3_df27ce55_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     1 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FL_Stat_ST3_558a33d8_Tx{Left} */              },  /* [RBTM_FL_Stat_ST3_558a33d8_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FL_Stat_ST3_558a33d8_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     2 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Meas8_RBTM_FL_ST3_a87f4b23_Tx{Left} */             },  /* [Meas8_RBTM_FL_ST3_a87f4b23_Tx, BasicCAN TxPdu with Tx-buffer]             */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meas8_RBTM_FL_ST3_a87f4b23_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     3 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{Left} */ },  /* [DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     4 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         4u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{Left} */ },  /* [DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     5 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         5u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{Left} */ },  /* [DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     6 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         6u  /* /ActiveEcuC/CanIf/CanIfInitCfg/Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx{Left} */       },  /* [Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx, BasicCAN TxPdu with Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     7 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         7u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ROE_RBTM_FL_ST3_e9956dfc_Tx{Left} */               },  /* [ROE_RBTM_FL_ST3_e9956dfc_Tx, BasicCAN TxPdu with Tx-buffer]               */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ROE_RBTM_FL_ST3_e9956dfc_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     8 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         8u  /* /ActiveEcuC/CanIf/CanIfInitCfg/ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx{Left} */          },  /* [ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx, BasicCAN TxPdu with Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*     9 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         9u  /* /ActiveEcuC/CanIf/CanIfInitCfg/NM_RBTM_FL_ST3_8b5cec70_Tx{Left} */                },  /* [NM_RBTM_FL_ST3_8b5cec70_Tx, BasicCAN TxPdu with Tx-buffer]                */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_RBTM_FL_ST3_8b5cec70_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  { /*    10 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,        10u  /* /ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FL_Tens_ST3_1446be6f_Tx{Left} */              }   /* [RBTM_FL_Tens_ST3_1446be6f_Tx, BasicCAN TxPdu with Tx-buffer]              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FL_Tens_ST3_1446be6f_Tx{Left}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_UlTxPduId2InternalTxPduId
**********************************************************************************************************************/
/** 
  \var    CanIf_UlTxPduId2InternalTxPduId
  \brief  Indirection table - Upper layer Tx-PduId to internal one.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_UlTxPduId2InternalTxPduIdType, CANIF_CONST) CanIf_UlTxPduId2InternalTxPduId[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     UlTxPduId2InternalTxPduId                                                                                              */
  /*     0 */                         0u  /* CanIfConf_CanIfTxPduCfg_BeltAdj_FL_Stat_ST3_df27ce55_Tx, CanId:0x000006A0u */          ,
  /*     1 */                         4u  /* CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx, CanId:0x18E1A481u */,
  /*     2 */                         5u  /* CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx, CanId:0x18E1A480u */,
  /*     3 */                         3u  /* CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx, CanId:0x18E1A485u */,
  /*     4 */                         6u  /* CanIfConf_CanIfTxPduCfg_Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx, CanId:0x18E1A440u */      ,
  /*     5 */                         8u  /* CanIfConf_CanIfTxPduCfg_ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx, CanId:0x164201A4u */         ,
  /*     6 */                         2u  /* CanIfConf_CanIfTxPduCfg_Meas8_RBTM_FL_ST3_a87f4b23_Tx, CanId:0x18E1A490u */            ,
  /*     7 */                         9u  /* CanIfConf_CanIfTxPduCfg_NM_RBTM_FL_ST3_8b5cec70_Tx, CanId:0x144201A4u */               ,
  /*     8 */                         1u  /* CanIfConf_CanIfTxPduCfg_RBTM_FL_Stat_ST3_558a33d8_Tx, CanId:0x00000698u */             ,
  /*     9 */                        10u  /* CanIfConf_CanIfTxPduCfg_RBTM_FL_Tens_ST3_1446be6f_Tx, CanId:0x0000030Fu */             ,
  /*    10 */                         7u  /* CanIfConf_CanIfTxPduCfg_ROE_RBTM_FL_ST3_e9956dfc_Tx, CanId:0x18E1A400u */              
};
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_WakeUpConfig
  \brief  Wake-up source configuration
  \details
  Element                Description
  ControllerId           ControllerId of this wake-up source configuration
  WakeUpSource           Wake-up source identifier
  WakeUpTargetAddress    Target address of wake up source (driver independent handle Id): CAN controller (ControllerId)/CAN transceiver (TransceiverId)
  WakeUpTargetModule     Target module of wake-up source: CAN driver/CAN transceiver driver
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_WakeUpConfigType, CANIF_CONST) CanIf_WakeUpConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ControllerId               WakeUpSource                              WakeUpTargetAddress               WakeUpTargetModule              Comment */
  { /*     0 */        0xFFu  /* Dummy */,           0u  /* Dummy wake-up source */,               0xFFu  /* Dummy */, CANIF_WAKEUPREQUEST_NONE }   /* [Dummy Wake-up source entry] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpValidationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_WakeUpValidationFctType, CANIF_CONST) CanIf_WakeUpValidationFctPtr = EcuM_ValidateWakeupEvent;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element                  Description
  CtrlMode                 Controller mode.
  PduMode                  PDU mode state.
  WakeUpValidationState    Wake-up validation state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{Right}] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx bit queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BeltAdj_FL_Stat_ST3_df27ce55_Tx{Left}] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FL_Stat_ST3_558a33d8_Tx{Left}] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meas8_RBTM_FL_ST3_a87f4b23_Tx{Left}] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{Left}] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{Left}] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{Left}] */
  /*     6 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx{Left}] */
  /*     7 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ROE_RBTM_FL_ST3_e9956dfc_Tx{Left}] */
  /*     8 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx{Left}] */
  /*     9 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_RBTM_FL_ST3_8b5cec70_Tx{Left}] */
  /*    10 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FL_Tens_ST3_1446be6f_Tx{Left}] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BeltAdj_FR_Stat_ST3_070be586_Tx{Right}] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FR_Stat_ST3_b20121fa_Tx{Right}] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Meas8_RBTM_FR_ST3_492d97af_Tx{Right}] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx{Right}] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx{Right}] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx{Right}] */
  /*     6 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Develop8_Rs_RBTM_FR_ST3_1a924f62_Tx{Right}] */
  /*     7 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ROE_RBTM_FR_ST3_d7dfdf54_Tx{Right}] */
  /*     8 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/ECU_Stat_RBTM_FR_ST3_430ba797_Tx{Right}] */
  /*     9 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_RBTM_FR_ST3_d6dddcba_Tx{Right}] */
  /*    10 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/RBTM_FR_Tens_ST3_019feca0_Tx{Right}] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueFlags
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueFlags
  \brief  Variable declaration - Tx bit queue flags.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueFlagsUType, CANIF_VAR_NOINIT) CanIf_TxQueueFlags;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */

#define CANIF_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_PCConfig
  \details
  Element        Description
  RxPduConfig    the pointer to CanIf_RxPduConfig
  TxPduConfig    the pointer to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_PCConfigsType, CANIF_CONST) CanIf_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_Left] */
      CanIf_RxPduConfigLeft   /**< the pointer to CanIf_RxPduConfig in Config_Left */
    , CanIf_TxPduConfigLeft   /**< the pointer to CanIf_TxPduConfig in Config_Left */
  },
  { /* Index: 1 Keys: [Config_Right] */
      CanIf_RxPduConfigRight  /**< the pointer to CanIf_RxPduConfig in Config_Right */
    , CanIf_TxPduConfigRight  /**< the pointer to CanIf_TxPduConfig in Config_Right */
  }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




