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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2023-07-05 16:23:56
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
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

 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  CDD Header Files  */ 
#include "CanIf_Cdd.h"


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
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = FblCw_ControllerBusOff;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
    /* Index    MappedTxBuffersConfigEndIdx                                                                                    MappedTxBuffersConfigStartIdx                                                                                          Referable Keys */
  { /*     0 */                          1u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL} */,                            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL} */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL}] */
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
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = FblCw_ControllerModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CtrlStatesIdx                                                                                    PduIdFirst                           PduIdLast                           TxBufferCfg                                                          TxBufferCfgIdx                                                                               TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL} */,         0u  /* Unused, TxPduId 0 */,        0u  /* Unused, TxPduId 2 */, CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG,                                     0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{RBTM_FL}] */
  { /*     1 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL} */,         0u  /* RxPduId */          ,        5u  /* RxPduId  */         ,                                 CANIF_NO_TXBUFFERCFGOFMAILBOXCONFIG, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                 , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_e046a621_Rx{RBTM_FL}] */
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
    /* Index    MailBoxConfigIdx                                                                                                         Referable Keys */
  { /*     0 */               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{RBTM_FL} */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL}] */
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
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxIndicationFct                                           RxIndicationLayout                                                                 Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }          , CanIf_SimpleRxIndicationLayout    /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ }   /* [CanTp_RxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRBTM_FL
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRBTM_FL
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
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRBTM_FL[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RxPduCanId                                                                    RxPduMask                                                     UpperPduId                                      RxIndicationFctListIdx                            RxPduDlc                                    Comment                                                                         Referable Keys */
  { /*     0 */ 0x98EF0D8Du  /* DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFu  /* DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_29880c5f    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx, CanId: 0x18ef0d8d]     */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx] */
  { /*     1 */ 0x98EEF989u  /* DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx, 2.0- or FD-PDU */    , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a8dd74b8    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx, CanId: 0x18eef989]     */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx] */
  { /*     2 */ 0x98EEF888u  /* DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx, 2.0- or FD-PDU */    , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2dd5cd3e    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx, CanId: 0x18eef888]     */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx] */
  { /*     3 */ 0x98E1A48Du  /* DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx, 2.0- or FD-PDU */, 0x9FFFFFFFu  /* DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx */, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_afe154c1    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx, CanId: 0x18e1a48d] */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx] */
  { /*     4 */ 0x98E1A489u  /* DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx, 2.0- or FD-PDU */, 0x9FFFFFFFu  /* DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx */, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_5cdfcb87,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx, CanId: 0x18e1a489] */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx] */
  { /*     5 */ 0x98E1A488u  /* DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx, 2.0- or FD-PDU */, 0x9FFFFFFFu  /* DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx */, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2f8b5959    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ }   /* [PDU: DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx, CanId: 0x18e1a488] */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRBTM_FR
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRBTM_FR
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
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRBTM_FR[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RxPduCanId                                                                    RxPduMask                                                     UpperPduId                                      RxIndicationFctListIdx                            RxPduDlc                                    Comment                                                                         Referable Keys */
  { /*     0 */ 0x98EF0D8Du  /* DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFu  /* DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_68607596    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx, CanId: 0x18ef0d8d]     */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx] */
  { /*     1 */ 0x98EEF989u  /* DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx, 2.0- or FD-PDU */    , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_42fcb720    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx, CanId: 0x18eef989]     */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx] */
  { /*     2 */ 0x98EEF888u  /* DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx, 2.0- or FD-PDU */    , 0x9FFFFFFFu  /* DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4461701a    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx, CanId: 0x18eef888]     */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx] */
  { /*     3 */ 0x98E1A58Du  /* DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx, 2.0- or FD-PDU */, 0x9FFFFFFFu  /* DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx */, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4b1f8ee6    ,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx, CanId: 0x18e1a58d] */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx] */
  { /*     4 */ 0x98E1A589u  /* DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx, 2.0- or FD-PDU */, 0x9FFFFFFFu  /* DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx */, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ebeac4b1,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ },  /* [PDU: DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx, CanId: 0x18e1a589] */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx] */
  { /*     5 */ 0x98E1A588u  /* DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx, 2.0- or FD-PDU */, 0x9FFFFFFFu  /* DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx */, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_619ae506,                     1u  /* CanTp_RxIndication */,       8u  /* DLC-Check is enabled */ }   /* [PDU: DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx, CanId: 0x18e1a588] */  /* [CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxBufferPrioByCanIdBaseIdx                                                       TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                       TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                       TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                             Referable Keys */
  { /*     0 */                         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */,                                             3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */,                                             3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */,                                               0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduConfigIdx                                                                                                 Referable Keys */
  { /*     0 */             0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{RBTM_FL} */ },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */
  { /*     1 */             1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{RBTM_FL} */ },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */
  { /*     2 */             2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{RBTM_FL} */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */
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
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanTp_TxConfirmation                     /* [CanTp_TxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRBTM_FL
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRBTM_FL
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
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRBTM_FL[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    CanId        UpperLayerTxPduId                               IsTxPduTruncation  CtrlStatesIdx                                                                                    MailBoxConfigIdx                                                                                                   TxConfirmationFctListIdx                              TxPduLength        Comment                                                      Referable Keys */
  { /*     0 */ 0x98E1A485u, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_afe154c1, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{RBTM_FL} */,                       1u  /* CanTp_TxConfirmation */,          8u },  /* [PDU: DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{RBTM_FL}] */
  { /*     1 */ 0x98E1A481u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_5cdfcb87    , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{RBTM_FL} */,                       1u  /* CanTp_TxConfirmation */,          8u },  /* [PDU: DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{RBTM_FL}] */
  { /*     2 */ 0x98E1A480u, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_2f8b5959, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{RBTM_FL} */,                       1u  /* CanTp_TxConfirmation */,          8u }   /* [PDU: DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{RBTM_FL}] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRBTM_FR
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRBTM_FR
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
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRBTM_FR[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    CanId        UpperLayerTxPduId                               IsTxPduTruncation  CtrlStatesIdx                                                                                    MailBoxConfigIdx                                                                                                   TxConfirmationFctListIdx                              TxPduLength        Comment                                                      Referable Keys */
  { /*     0 */ 0x98E1A585u, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_4b1f8ee6, TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{RBTM_FR} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{RBTM_FR} */,                       1u  /* CanTp_TxConfirmation */,          8u },  /* [PDU: DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx{RBTM_FR}] */
  { /*     1 */ 0x98E1A581u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ebeac4b1    , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{RBTM_FR} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{RBTM_FR} */,                       1u  /* CanTp_TxConfirmation */,          8u },  /* [PDU: DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx{RBTM_FR}] */
  { /*     2 */ 0x98E1A580u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_619ae506    , TRUE             ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{RBTM_FR} */,               0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_Tx{RBTM_FR} */,                       1u  /* CanTp_TxConfirmation */,          8u }   /* [PDU: DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx{RBTM_FR}] */
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
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxQueue                                 TxQueueIdx                                                                                                 Comment                                                                                Referable Keys */
  { /*     0 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{RBTM_FL} */ },  /* [DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{RBTM_FL}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL}] */
  { /*     1 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{RBTM_FL} */ },  /* [DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{RBTM_FL}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL}] */
  { /*     2 */ CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX,         2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{RBTM_FL} */ }   /* [DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{RBTM_FL}, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL}] */
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
CONST(CanIf_UlTxPduId2InternalTxPduIdType, CANIF_CONST) CanIf_UlTxPduId2InternalTxPduId[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     UlTxPduId2InternalTxPduId                                                                                              */
  /*     0 */                         1u  /* CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx, CanId:0x18E1A481u */,
  /*     1 */                         2u  /* CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx, CanId:0x18E1A480u */,
  /*     2 */                         0u  /* CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx, CanId:0x18E1A485u */
};
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL}] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FR_BODY3_2fec3d37{RBTM_FR}] */

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
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/BODY3_bccb160f] */
  /* Index        Referable Keys   RBTM_FR */
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
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx{RBTM_FL}] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx{RBTM_FL}] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx{RBTM_FL}] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx{RBTM_FR}] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx{RBTM_FR}] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx{RBTM_FR}] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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
  { /* Index: 0 Keys: [Config_RBTM_FL] */
      CanIf_RxPduConfigRBTM_FL  /**< the pointer to CanIf_RxPduConfig in Config_RBTM_FL */
    , CanIf_TxPduConfigRBTM_FL  /**< the pointer to CanIf_TxPduConfig in Config_RBTM_FL */
  },
  { /* Index: 1 Keys: [Config_RBTM_FR] */
      CanIf_RxPduConfigRBTM_FR  /**< the pointer to CanIf_RxPduConfig in Config_RBTM_FR */
    , CanIf_TxPduConfigRBTM_FR  /**< the pointer to CanIf_TxPduConfig in Config_RBTM_FR */
  }
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




