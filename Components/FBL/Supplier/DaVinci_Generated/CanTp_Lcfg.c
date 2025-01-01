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
 *            Module: CanTp
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTp_Lcfg.c
 *   Generation Time: 2023-07-05 16:23:57
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define CANTP_LCFG_SOURCE

/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */

#include "CanTp_Lcfg.h"
#if (CANTP_LOLAYER_CANIF == STD_ON)
# include "CanIf.h"
#endif
#include "PduR_CanTp.h"

/* -----------------------------------------------------------------------------
    &&&~ Data definitions
 ----------------------------------------------------------------------------- */



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
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTp_RxPduMap
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPduMap
  \details
  Element                Description
  RxSduCfgIndEndIdx      the end index of the 0:n relation pointing to CanTp_RxSduCfgInd
  RxSduCfgIndStartIdx    the start index of the 0:n relation pointing to CanTp_RxSduCfgInd
  TxSduCfgIndEndIdx      the end index of the 0:n relation pointing to CanTp_TxSduCfgInd
  TxSduCfgIndStartIdx    the start index of the 0:n relation pointing to CanTp_TxSduCfgInd
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxPduMapType, CANTP_CONST) CanTp_RxPduMap[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxSduCfgIndEndIdx  RxSduCfgIndStartIdx  TxSduCfgIndEndIdx                     TxSduCfgIndStartIdx                    */
  { /*     0 */                1u,                  0u,                                   1u,                                     0u },
  { /*     1 */                2u,                  1u,                                   2u,                                     1u },
  { /*     2 */                3u,                  2u,                                   3u,                                     2u },
  { /*     3 */                4u,                  3u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP },
  { /*     4 */                5u,                  4u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP },
  { /*     5 */                6u,                  5u, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRBTM_FL
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRBTM_FL
  \details
  Element                     Description
  NBr                     
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  BlockSize               
  ChannelMode             
  NAr                     
  NCr                     
  RxTaType                
  RxWftMax                
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRBTM_FL[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    NBr   LoLayerTxFcPduId                                                   PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        BlockSize  ChannelMode                              NAr  NCr   RxTaType                             RxWftMax  TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */  21u, CANTP_INVALID_HDL                                                , PduRConf_PduRSrcPdu_PduRSrcPdu_19a79fac, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a8dd74b8, CANTP_INVALID_HDL                             ,        8u, CANTP_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG, 11u,  11u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,      15u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_e35239dd] */  /* [CanTpRxNSdu_e35239dd, 3] */
  { /*     1 */  21u, CANTP_INVALID_HDL                                                , PduRConf_PduRSrcPdu_PduRSrcPdu_0e266b08, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2dd5cd3e, CANTP_INVALID_HDL                             ,       32u, CANTP_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG, 11u,  11u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,      15u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_4a102435] */  /* [CanTpRxNSdu_4a102435, 4] */
  { /*     2 */  21u, CANTP_INVALID_HDL                                                , PduRConf_PduRSrcPdu_PduRSrcPdu_1a629478, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_29880c5f, CANTP_INVALID_HDL                             ,       32u, CANTP_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG, 11u,  11u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,      15u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_44714e59] */  /* [CanTpRxNSdu_44714e59, 5] */
  { /*     3 */ 301u, CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_a44b5ded, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7e251f75, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_7e251f75,        0u, CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG, 21u, 101u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,       5u,                             0u },  /* [CanTpRxNSdu_530d12e8] */  /* [CanTpRxNSdu_530d12e8, 0] */
  { /*     4 */ 301u, CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_80d1f2da, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2f8b5959, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_2f8b5959,        0u, CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG, 21u, 101u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,       5u,                             1u },  /* [CanTpRxNSdu_690fe637] */  /* [CanTpRxNSdu_690fe637, 1] */
  { /*     5 */ 301u, CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_03bff274, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_afe154c1, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_afe154c1,        0u, CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG, 21u, 101u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,       5u,                             2u }   /* [CanTpRxNSdu_b61ae5cc] */  /* [CanTpRxNSdu_b61ae5cc, 2] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRBTM_FR
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRBTM_FR
  \details
  Element                     Description
  NBr                     
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  BlockSize               
  ChannelMode             
  NAr                     
  NCr                     
  RxTaType                
  RxWftMax                
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRBTM_FR[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    NBr   LoLayerTxFcPduId                                                   PduRRxSduId                              RxPduId                                     TxFcPduConfirmationPduId                        BlockSize  ChannelMode                              NAr  NCr   RxTaType                             RxWftMax  TxSduCfgIdx                           Comment                            Referable Keys */
  { /*     0 */  21u, CANTP_INVALID_HDL                                                , PduRConf_PduRSrcPdu_PduRSrcPdu_19a79fac, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_42fcb720, CANTP_INVALID_HDL                             ,        8u, CANTP_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG, 11u,  11u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,      15u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_64c01817] */  /* [CanTpRxNSdu_64c01817, 3] */
  { /*     1 */  21u, CANTP_INVALID_HDL                                                , PduRConf_PduRSrcPdu_PduRSrcPdu_0e266b08, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4461701a, CANTP_INVALID_HDL                             ,        8u, CANTP_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG, 11u,  11u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,      15u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_84669b72] */  /* [CanTpRxNSdu_84669b72, 4] */
  { /*     2 */  21u, CANTP_INVALID_HDL                                                , PduRConf_PduRSrcPdu_PduRSrcPdu_1a629478, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_68607596, CANTP_INVALID_HDL                             ,        8u, CANTP_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG, 11u,  11u, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG,      15u, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [CanTpRxNSdu_dbf7577d] */  /* [CanTpRxNSdu_dbf7577d, 5] */
  { /*     3 */ 301u, CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_7beeea72, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_c9101043, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_c9101043,        0u, CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG, 21u, 101u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,       5u,                             0u },  /* [CanTpRxNSdu_036251db] */  /* [CanTpRxNSdu_036251db, 0] */
  { /*     4 */ 301u, CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_4d07a2cf, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_436031f4, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_436031f4,        0u, CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG, 21u, 101u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,       5u,                             1u },  /* [CanTpRxNSdu_b14888e8] */  /* [CanTpRxNSdu_b14888e8, 1] */
  { /*     5 */ 301u, CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx, PduRConf_PduRSrcPdu_PduRSrcPdu_8aa11052, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4b1f8ee6, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_4b1f8ee6,        0u, CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG, 21u, 101u,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,       5u,                             2u }   /* [CanTpRxNSdu_6f7c1760] */  /* [CanTpRxNSdu_6f7c1760, 2] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgInd
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgInd
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduCfgIndType, CANTP_CONST) CanTp_RxSduCfgInd[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxSduCfgInd      Referable Keys */
  /*     0 */           3u,  /* [0] */
  /*     1 */           4u,  /* [1] */
  /*     2 */           5u,  /* [2] */
  /*     3 */           0u,  /* [3] */
  /*     4 */           1u,  /* [4] */
  /*     5 */           2u   /* [5] */
};
#define CANTP_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduSnv2Hdl
  \details
  Element        Description
  RxSduCfgIdx    the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxSduCfgIdx        Comment */
  { /*     0 */          0u },  /* [CanTpRxNSdu_e35239dd] */
  { /*     1 */          1u },  /* [CanTpRxNSdu_4a102435] */
  { /*     2 */          2u },  /* [CanTpRxNSdu_44714e59] */
  { /*     3 */          3u },  /* [CanTpRxNSdu_530d12e8] */
  { /*     4 */          4u },  /* [CanTpRxNSdu_690fe637] */
  { /*     5 */          5u }   /* [CanTpRxNSdu_b61ae5cc] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRBTM_FL
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRBTM_FL
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRBTM_FL[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    LoLayerTxPduId                                                     PduRTxSduId                                                               RxFcPduId                                       TxPduConfirmationPduId                      RxSduCfgIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx, PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_5cdfcb87, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_5cdfcb87,          3u },  /* [CanTpTxNSdu_530d12e8] */  /* [CanTpTxNSdu_530d12e8, 0] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx, PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_0d718dab, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_0d718dab,          4u },  /* [CanTpTxNSdu_690fe637] */  /* [CanTpTxNSdu_690fe637, 1] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx, PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8d1b8033, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8d1b8033,          5u }   /* [CanTpTxNSdu_b61ae5cc] */  /* [CanTpTxNSdu_b61ae5cc, 2] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRBTM_FR
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRBTM_FR
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRBTM_FR[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    LoLayerTxPduId                                                     PduRTxSduId                                                               RxFcPduId                                       TxPduConfirmationPduId                      RxSduCfgIdx        Comment                            Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx, PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ebeac4b1, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ebeac4b1,          3u },  /* [CanTpTxNSdu_036251db] */  /* [CanTpTxNSdu_036251db, 0] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx, PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_619ae506, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_619ae506,          4u },  /* [CanTpTxNSdu_b14888e8] */  /* [CanTpTxNSdu_b14888e8, 1] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx, PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_69e55a14, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_69e55a14,          5u }   /* [CanTpTxNSdu_6f7c1760] */  /* [CanTpTxNSdu_6f7c1760, 2] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgInd
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgInd
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduCfgIndType, CANTP_CONST) CanTp_TxSduCfgInd[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxSduCfgInd      Referable Keys */
  /*     0 */           0u,  /* [0] */
  /*     1 */           1u,  /* [1] */
  /*     2 */           2u   /* [2] */
};
#define CANTP_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduSnv2Hdl
  \details
  Element        Description
  TxSduCfgIdx    the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_TxSduSnv2HdlType, CANTP_CONST) CanTp_TxSduSnv2Hdl[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxSduCfgIdx        Comment */
  { /*     0 */          0u },  /* [CanTpTxNSdu_530d12e8] */
  { /*     1 */          1u },  /* [CanTpTxNSdu_690fe637] */
  { /*     2 */          2u }   /* [CanTpTxNSdu_b61ae5cc] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_CalcBS
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_CalcBSType, CANTP_VAR_NOINIT) CanTp_CalcBS[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_DynFCParameters
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_DynFCParameterType, CANTP_VAR_NOINIT) CanTp_DynFCParameters[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxState
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_RxStateType, CANTP_VAR_NOINIT) CanTp_RxState[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSemaphores
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_TxSemaphoreType, CANTP_VAR_NOINIT) CanTp_TxSemaphores[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxState
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTp_TxStateType, CANTP_VAR_NOINIT) CanTp_TxState[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanTp_PCConfig
  \details
  Element     Description
  RxSduCfg    the pointer to CanTp_RxSduCfg
  TxSduCfg    the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTp_PCConfigsType, CANTP_CONST) CanTp_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RBTM_FL] */
      CanTp_RxSduCfgRBTM_FL  /**< the pointer to CanTp_RxSduCfg in Config_RBTM_FL */
    , CanTp_TxSduCfgRBTM_FL  /**< the pointer to CanTp_TxSduCfg in Config_RBTM_FL */
  },
  { /* Index: 1 Keys: [Config_RBTM_FR] */
      CanTp_RxSduCfgRBTM_FR  /**< the pointer to CanTp_RxSduCfg in Config_RBTM_FR */
    , CanTp_TxSduCfgRBTM_FR  /**< the pointer to CanTp_TxSduCfg in Config_RBTM_FR */
  }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 * FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




