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
 *            Module: FblCw
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblCw_Lcfg.c
 *   Generation Time: 2023-07-05 16:23:57
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define FBLCW_LCFG_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "fbl_inc.h"
#include "FblCw_Lcfg.h"
#include "PduR_Dcm.h"

#include "CanIf.h"
#include "CanTp.h"
#include "ComM.h"




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
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  FblCw_CanIfCtrlInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_CanIfCtrlInfo
  \brief  DefinitionRef: /[ANY]/CanIf/CanIfCtrlDrvCfg/CanIfCtrlCfg
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_CanIfCtrlInfoType, FBLCW_CONST) FblCw_CanIfCtrlInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanIfCtrlInfo                                      Referable Keys */
  /*     0 */  CanIfConf_CanIfCtrlCfg_RBTM_FL_BODY3_180ddaa4   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/RBTM_FL_BODY3_180ddaa4{RBTM_FL}] */
};
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_CwDcmComMChannelMappingRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_CwDcmComMChannelMappingRBTM_FL
  \brief  Mapping of ComMChannels
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_CwDcmComMChannelMappingType, FBLCW_CONST) FblCw_CwDcmComMChannelMappingRBTM_FL[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     CwDcmComMChannelMapping                                                    Referable Keys */
  /*     0 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 ,  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{RBTM_FL}] */
  /*     1 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 ,  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{RBTM_FL}] */
  /*     2 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6    /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{RBTM_FL}] */
};
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_CwDcmComMChannelMappingRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_CwDcmComMChannelMappingRBTM_FR
  \brief  Mapping of ComMChannels
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_CwDcmComMChannelMappingType, FBLCW_CONST) FblCw_CwDcmComMChannelMappingRBTM_FR[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     CwDcmComMChannelMapping                                                    Referable Keys */
  /*     0 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 ,  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{RBTM_FR}] */
  /*     1 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 ,  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{RBTM_FR}] */
  /*     2 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727    /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{RBTM_FR}] */
};
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslConnectionInfoRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslConnectionInfoRBTM_FL
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection
  \details
  Element                  Description
  PayloadLimit             DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslPayloadLimit
  RxTesterSourceAddress    DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRxTesterSourceAddr
  Controller               controller handle
  ParameterInfoIdx         the index of the 0:1 relation pointing to FblCw_ParameterInfo
  TxRemotePduId            DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu based symbolic name value
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslConnectionInfoType, FBLCW_CONST) FblCw_DcmDslConnectionInfoRBTM_FL[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    PayloadLimit  RxTesterSourceAddress  Controller                                     ParameterInfoIdx  TxRemotePduId                                  Referable Keys */
  { /*     0 */      0x0FFFu,                 3833u, CanIfConf_CanIfCtrlCfg_RBTM_FL_BODY3_180ddaa4,               0u, PduRConf_PduRSrcPdu_PduRSrcPdu_7f35c914 },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42{RBTM_FL}] */
  { /*     1 */      0x0FFFu,                 3832u, CanIfConf_CanIfCtrlCfg_RBTM_FL_BODY3_180ddaa4,               1u, PduRConf_PduRSrcPdu_PduRSrcPdu_249a1158 },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3{RBTM_FL}] */
  { /*     2 */      0x0FFFu,                 3853u, CanIfConf_CanIfCtrlCfg_RBTM_FL_BODY3_180ddaa4,               2u, PduRConf_PduRSrcPdu_PduRSrcPdu_3fa3fd23 }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c{RBTM_FL}] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslConnectionInfoRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslConnectionInfoRBTM_FR
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection
  \details
  Element                  Description
  PayloadLimit             DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslPayloadLimit
  RxTesterSourceAddress    DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRxTesterSourceAddr
  Controller               controller handle
  ParameterInfoIdx         the index of the 0:1 relation pointing to FblCw_ParameterInfo
  TxRemotePduId            DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu based symbolic name value
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslConnectionInfoType, FBLCW_CONST) FblCw_DcmDslConnectionInfoRBTM_FR[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    PayloadLimit  RxTesterSourceAddress  Controller                                     ParameterInfoIdx  TxRemotePduId                                  Referable Keys */
  { /*     0 */      0x0FFFu,                 3832u, CanIfConf_CanIfCtrlCfg_RBTM_FR_BODY3_2fec3d37,               0u, PduRConf_PduRSrcPdu_PduRSrcPdu_a0766459 },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987{RBTM_FR}] */
  { /*     1 */      0x0FFFu,                 3833u, CanIfConf_CanIfCtrlCfg_RBTM_FR_BODY3_2fec3d37,               1u, PduRConf_PduRSrcPdu_PduRSrcPdu_8d2872fc },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76{RBTM_FR}] */
  { /*     2 */      0x0FFFu,                 3853u, CanIfConf_CanIfCtrlCfg_RBTM_FR_BODY3_2fec3d37,               2u, PduRConf_PduRSrcPdu_PduRSrcPdu_f76356d0 }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528{RBTM_FR}] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolRxInfoRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolRxInfoRBTM_FL
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx
  \details
  Element                    Description
  AddrType                   DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx/DcmDslProtocolRxAddrType
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslProtocolRxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolRxInfoRBTM_FL[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    AddrType                                         DcmDslConnectionInfoIdx        Referable Keys */
  { /*     0 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx_2b322367{RBTM_FL}] */
  { /*     1 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx_2873db84{RBTM_FL}] */
  { /*     2 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      1u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx_d414628a{RBTM_FL}] */
  { /*     3 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      1u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx_5a27dd11{RBTM_FL}] */
  { /*     4 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      2u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx_c0cc433b{RBTM_FL}] */
  { /*     5 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      2u }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx_6a163982{RBTM_FL}] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolRxInfoRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolRxInfoRBTM_FR
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx
  \details
  Element                    Description
  AddrType                   DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx/DcmDslProtocolRxAddrType
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslProtocolRxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolRxInfoRBTM_FR[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    AddrType                                         DcmDslConnectionInfoIdx        Referable Keys */
  { /*     0 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      1u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx_2b322367{RBTM_FR}] */
  { /*     1 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      1u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx_3b6533a8{RBTM_FR}] */
  { /*     2 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx_d414628a{RBTM_FR}] */
  { /*     3 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx_510ebea9{RBTM_FR}] */
  { /*     4 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      2u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx_c0cc433b{RBTM_FR}] */
  { /*     5 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      2u }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx_536fd8c4{RBTM_FR}] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolTxInfoRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolTxInfoRBTM_FL
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolTx
  \details
  Element                    Description
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslProtocolTxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolTxInfoRBTM_FL[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    DcmDslConnectionInfoIdx        Referable Keys */
  { /*     0 */                      0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx_70f6d2b0{RBTM_FL}] */
  { /*     1 */                      1u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx_2b590afc{RBTM_FL}] */
  { /*     2 */                      2u }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx_3060e687{RBTM_FL}] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolTxInfoRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolTxInfoRBTM_FR
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolTx
  \details
  Element                    Description
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_DcmDslProtocolTxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolTxInfoRBTM_FR[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    DcmDslConnectionInfoIdx        Referable Keys */
  { /*     0 */                      1u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx_82eb6958{RBTM_FR}] */
  { /*     1 */                      0u },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx_afb57ffd{RBTM_FR}] */
  { /*     2 */                      2u }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx_f8a04d74{RBTM_FR}] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_ParameterInfoRBTM_FL
**********************************************************************************************************************/
/** 
  \var    FblCw_ParameterInfoRBTM_FL
  \brief  all Change and Read parameter infos.
  \details
  Element    Description
  PduRId     PduR SNVs of DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSourcePduHandleId
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_ParameterInfoType, FBLCW_CONST) FblCw_ParameterInfoRBTM_FL[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    PduRId                                                                                      Referable Keys */
  { /*     0 */ PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx_a44b5ded_Rx },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42{RBTM_FL}] */
  { /*     1 */ PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx_80d1f2da_Rx },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3{RBTM_FL}] */
  { /*     2 */ PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx_03bff274_Rx }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c{RBTM_FL}] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_ParameterInfoRBTM_FR
**********************************************************************************************************************/
/** 
  \var    FblCw_ParameterInfoRBTM_FR
  \brief  all Change and Read parameter infos.
  \details
  Element    Description
  PduRId     PduR SNVs of DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSourcePduHandleId
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_ParameterInfoType, FBLCW_CONST) FblCw_ParameterInfoRBTM_FR[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    PduRId                                                                                      Referable Keys */
  { /*     0 */ PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx_4d07a2cf_Rx },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987{RBTM_FR}] */
  { /*     1 */ PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx_7beeea72_Rx },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76{RBTM_FR}] */
  { /*     2 */ PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx_8aa11052_Rx }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528{RBTM_FR}] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_InitialBC
**********************************************************************************************************************/
/** 
  \var    FblCw_InitialBC
  \brief  initial STmin Values
*/ 
#define FBLCW_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(FblCw_InitialBCUType, FBLCW_VAR_NOINIT) FblCw_InitialBC;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42{RBTM_FL}] */
  /*     1 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3{RBTM_FL}] */
  /*     2 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c{RBTM_FL}] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987{RBTM_FR}] */
  /*     1 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76{RBTM_FR}] */
  /*     2 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528{RBTM_FR}] */

#define FBLCW_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_InitialBS
**********************************************************************************************************************/
/** 
  \var    FblCw_InitialBS
  \brief  initial BlockSize Values
*/ 
#define FBLCW_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(FblCw_InitialBSUType, FBLCW_VAR_NOINIT) FblCw_InitialBS;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42{RBTM_FL}] */
  /*     1 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3{RBTM_FL}] */
  /*     2 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c{RBTM_FL}] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987{RBTM_FR}] */
  /*     1 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76{RBTM_FR}] */
  /*     2 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528{RBTM_FR}] */

#define FBLCW_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_InitialSTmin
**********************************************************************************************************************/
/** 
  \var    FblCw_InitialSTmin
  \brief  initial STmin Values
*/ 
#define FBLCW_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(FblCw_InitialSTminUType, FBLCW_VAR_NOINIT) FblCw_InitialSTmin;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_2f852a42{RBTM_FL}] */
  /*     1 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_816f6eb3{RBTM_FL}] */
  /*     2 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_1d9ca21c{RBTM_FL}] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_b444e987{RBTM_FR}] */
  /*     1 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_1aaead76{RBTM_FR}] */
  /*     2 */  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow_29812fbf/DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_28b72528{RBTM_FR}] */

#define FBLCW_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_Initialized
**********************************************************************************************************************/
/** 
  \var    FblCw_Initialized
  \brief  Initialization state of the Dcm. TRUE, if Dcm_Init() has been called, else FALSE.
*/ 
#define FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(FblCw_InitializedType, FBLCW_VAR_ZERO_INIT) FblCw_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_PCConfig
**********************************************************************************************************************/
/** 
  \var    FblCw_PCConfig
  \details
  Element                    Description
  CwDcmComMChannelMapping    the pointer to FblCw_CwDcmComMChannelMapping
  DcmDslConnectionInfo       the pointer to FblCw_DcmDslConnectionInfo
  DcmDslProtocolRxInfo       the pointer to FblCw_DcmDslProtocolRxInfo
  DcmDslProtocolTxInfo       the pointer to FblCw_DcmDslProtocolTxInfo
  ParameterInfo              the pointer to FblCw_ParameterInfo
  VariantIdx             
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(FblCw_PCConfigsType, FBLCW_CONST) FblCw_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RBTM_FL] */
      FblCw_CwDcmComMChannelMappingRBTM_FL  /**< the pointer to FblCw_CwDcmComMChannelMappingRBTM_FL */
    , FblCw_DcmDslConnectionInfoRBTM_FL     /**< the pointer to FblCw_DcmDslConnectionInfoRBTM_FL */
    , FblCw_DcmDslProtocolRxInfoRBTM_FL     /**< the pointer to FblCw_DcmDslProtocolRxInfoRBTM_FL */
    , FblCw_DcmDslProtocolTxInfoRBTM_FL     /**< the pointer to FblCw_DcmDslProtocolTxInfoRBTM_FL */
    , FblCw_ParameterInfoRBTM_FL            /**< the pointer to FblCw_ParameterInfoRBTM_FL */
    , 0u
  },
  { /* Index: 1 Keys: [Config_RBTM_FR] */
      FblCw_CwDcmComMChannelMappingRBTM_FR  /**< the pointer to FblCw_CwDcmComMChannelMappingRBTM_FR */
    , FblCw_DcmDslConnectionInfoRBTM_FR     /**< the pointer to FblCw_DcmDslConnectionInfoRBTM_FR */
    , FblCw_DcmDslProtocolRxInfoRBTM_FR     /**< the pointer to FblCw_DcmDslProtocolRxInfoRBTM_FR */
    , FblCw_DcmDslProtocolTxInfoRBTM_FR     /**< the pointer to FblCw_DcmDslProtocolTxInfoRBTM_FR */
    , FblCw_ParameterInfoRBTM_FR            /**< the pointer to FblCw_ParameterInfoRBTM_FR */
    , 1u
  }
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
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

#define FBLCW_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FBLCW_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
  END OF FILE: FblCw_Lcfg.c
**********************************************************************************************************************/

