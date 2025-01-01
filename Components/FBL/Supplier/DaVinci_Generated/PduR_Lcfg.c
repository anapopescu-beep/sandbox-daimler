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
 *            Module: PduR
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.c
 *   Generation Time: 2023-07-05 16:23:57
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define PDUR_LCFG_SOURCE

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Fm.h"
#include "PduR_IFQ.h"
#include "PduR_Sm.h"
#include "PduR_RmIf.h"
#include "PduR_RmTp.h"
#include "PduR_RmTp_TxInst.h"
#include "SchM_PduR.h"
#if(PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
# include "PduR_Lcfg.h"



/* Include headers with callbacks */
#include "PduR_CanTp.h"
#include "PduR_Dcm.h"


/**********************************************************************************************************************
 * LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* Exclusive Area Wrapper functions */
static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void);
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void);
  
/**********************************************************************************************************************
 * LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA
 *********************************************************************************************************************/
/* \trace SPEC-663, SPEC-661 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_DestApplicationManagerRom
**********************************************************************************************************************/
/** 
  \var    PduR_DestApplicationManagerRom
  \brief  Destination Application Manager
  \details
  Element               Description
  RmGDestRomStartIdx    the start index of the 0:n relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_DestApplicationManagerRomType, PDUR_CONST) PduR_DestApplicationManagerRom[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RmGDestRomStartIdx        Comment                         Referable Keys */
  { /*     0 */                 0u }   /* [SingleApplication] */  /* [PduRSinglePartitionDummy] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_ExclusiveAreaRom
**********************************************************************************************************************/
/** 
  \var    PduR_ExclusiveAreaRom
  \brief  PduR Exclusive Area Locks
  \details
  Element    Description
  Lock       Lock function
  Unlock     Unlock function
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_ExclusiveAreaRomType, PDUR_CONST) PduR_ExclusiveAreaRom[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Lock                                        Unlock                                           Referable Keys */
  { /*     0 */ PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0, PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0 }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRLock_PduRExclusiveArea] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_LockRom
**********************************************************************************************************************/
/** 
  \var    PduR_LockRom
  \brief  PduR Lock Manager Table
  \details
  Element                Description
  ExclusiveAreaRomIdx    the index of the 0:1 relation pointing to PduR_ExclusiveAreaRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_LockRomType, PDUR_CONST) PduR_LockRom[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ExclusiveAreaRomIdx        Referable Keys */
  { /*     0 */                  0u }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRLock_PduRExclusiveArea] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_MmRom
**********************************************************************************************************************/
/** 
  \var    PduR_MmRom
  \brief  Module manager: Contains all function pointers of the bordering modules.
  \details
  Element                       Description
  MaskedBits                    contains bitcoded the boolean data of PduR_ChangeParameterSupportedOfMmRom, PduR_LoTpOfMmRom, PduR_UpTpOfMmRom
  LoTpChangeParameterFctPtr     lower layer change parameter function pointers to change e.g. BS or STmin..
  UpTpCopyRxDataFctPtr          Transport protocol CopyRxData function pointers
  UpTpCopyTxDataFctPtr          Transport protocol CopyTxData function pointers
  UpTpStartOfReceptionFctPtr    Transport protocol StartOfReception function pointers
  UpTpTpRxIndicationFctPtr      Transport protocol TpRxIndication function pointers
  UpTpTpTxConfirmationFctPtr    Transport protocol TpTxConfimation function pointers
  LoTpTransmitFctPtr            Lower layer Tp transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  LoTpChangeParameterFctPtr  UpTpCopyRxDataFctPtr  UpTpCopyTxDataFctPtr  UpTpStartOfReceptionFctPtr  UpTpTpRxIndicationFctPtr  UpTpTpTxConfirmationFctPtr  LoTpTransmitFctPtr        Referable Keys */
  { /*     0 */      0x06u, CanTp_ChangeParameter    , NULL_PTR            , NULL_PTR            , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , CanTp_Transmit     },  /* [/ActiveEcuC/PduR/CanTp] */
  { /*     1 */      0x01u, NULL_PTR                 , Dcm_CopyRxData      , Dcm_CopyTxData      , Dcm_StartOfReception      , Dcm_TpRxIndication      , Dcm_TpTxConfirmation      , NULL_PTR           }   /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    PduR_PartitionIdentifiers
  \brief  the partition context in Config_RBTM_FL
  \details
  Element         Description
  PartitionSNV
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_PartitionIdentifiersType, PDUR_CONST) PduR_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV       */
  { /*     0 */ CommonSharedMemory }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRomRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRomRBTM_FL
  \brief  PduR RoutingPathManager destPdu Table
  \details
  Element                      Description
  PduLengthHandlingStrategy    The strategy how larger than configured If Pdus are handled.
  RmGDestRomIdx                the index of the 1:1 relation pointing to PduR_RmGDestRom
  RmSrcRomIdx                  the index of the 1:1 relation pointing to PduR_RmSrcRom
  RoutingType                  Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRomRBTM_FL[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduLengthHandlingStrategy                         RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                                    Referable Keys */
  { /*     0 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            7u,          5u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx_03bff274_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx/PduRSrcPdu_03bff274{RBTM_FL}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx_03bff274_Rx{RBTM_FL}] */
  { /*     1 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            1u,          1u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/PduRSrcPdu_0e266b08, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx] */
  { /*     2 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            0u,          0u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/PduRSrcPdu_19a79fac, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx] */
  { /*     3 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            2u,          2u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/PduRSrcPdu_1a629478, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx] */
  { /*     4 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            6u,          7u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx/PduRSrcPdu_249a1158{RBTM_FL}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx{RBTM_FL}] */
  { /*     5 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            8u,          8u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx/PduRSrcPdu_3fa3fd23{RBTM_FL}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx{RBTM_FL}] */
  { /*     6 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            4u,          6u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx/PduRSrcPdu_7f35c914{RBTM_FL}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx{RBTM_FL}] */
  { /*     7 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            5u,          4u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx_80d1f2da_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx/PduRSrcPdu_80d1f2da{RBTM_FL}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx_80d1f2da_Rx{RBTM_FL}] */
  { /*     8 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            3u,          3u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM }   /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx_a44b5ded_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx/PduRSrcPdu_a44b5ded{RBTM_FL}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx_a44b5ded_Rx{RBTM_FL}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRomRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRomRBTM_FR
  \brief  PduR RoutingPathManager destPdu Table
  \details
  Element                      Description
  PduLengthHandlingStrategy    The strategy how larger than configured If Pdus are handled.
  RmGDestRomIdx                the index of the 1:1 relation pointing to PduR_RmGDestRom
  RmSrcRomIdx                  the index of the 1:1 relation pointing to PduR_RmSrcRom
  RoutingType                  Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRomRBTM_FR[9] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    PduLengthHandlingStrategy                         RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                                    Referable Keys */
  { /*     0 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            1u,          1u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/PduRSrcPdu_0e266b08, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx] */
  { /*     1 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            0u,          0u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/PduRSrcPdu_19a79fac, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx] */
  { /*     2 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            2u,          2u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/PduRSrcPdu_1a629478, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx] */
  { /*     3 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            5u,          4u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx_4d07a2cf_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx/PduRSrcPdu_4d07a2cf{RBTM_FR}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx_4d07a2cf_Rx{RBTM_FR}] */
  { /*     4 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            3u,          3u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx_7beeea72_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx/PduRSrcPdu_7beeea72{RBTM_FR}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx_7beeea72_Rx{RBTM_FR}] */
  { /*     5 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            7u,          5u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx_8aa11052_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx/PduRSrcPdu_8aa11052{RBTM_FR}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx_8aa11052_Rx{RBTM_FR}] */
  { /*     6 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            4u,          6u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx/PduRSrcPdu_8d2872fc{RBTM_FR}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx{RBTM_FR}] */
  { /*     7 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            6u,          7u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx/PduRSrcPdu_a0766459{RBTM_FR}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx{RBTM_FR}] */
  { /*     8 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            8u,          8u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM }   /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx/PduRSrcPdu_f76356d0{RBTM_FR}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx{RBTM_FR}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRomRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRomRBTM_FL
  \brief  PduR RoutingPathManager global destPdu Table
  \details
  Element         Description
  MaxPduLength    Configured PduLength + metadata length.
  DestHnd         handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  Direction       Direction of this Pdu: Rx or Tx
  LockRomIdx      the index of the 1:1 relation pointing to PduR_LockRom
  MmRomIdx        the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomIdx    the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRomRBTM_FL[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaxPduLength  DestHnd                                                                                Direction                      LockRomIdx  MmRomIdx  RmDestRomIdx        Comment                                                                               Referable Keys */
  { /*     0 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx_2b322367, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           2u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     1 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx_d414628a, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           1u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     2 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx_c0cc433b, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           3u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     3 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx_2873db84, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           8u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx{RBTM_FL}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     4 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_530d12e8, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           6u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx{RBTM_FL}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
  { /*     5 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx_5a27dd11, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           7u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx{RBTM_FL}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     6 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_690fe637, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           4u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx{RBTM_FL}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
  { /*     7 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx_6a163982, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           0u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx{RBTM_FL}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     8 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_b61ae5cc, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           5u }   /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx{RBTM_FL}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRomRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRomRBTM_FR
  \brief  PduR RoutingPathManager global destPdu Table
  \details
  Element         Description
  MaxPduLength    Configured PduLength + metadata length.
  DestHnd         handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  Direction       Direction of this Pdu: Rx or Tx
  LockRomIdx      the index of the 1:1 relation pointing to PduR_LockRom
  MmRomIdx        the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomIdx    the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRomRBTM_FR[9] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    MaxPduLength  DestHnd                                                                                Direction                      LockRomIdx  MmRomIdx  RmDestRomIdx        Comment                                                                               Referable Keys */
  { /*     0 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx_2b322367, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           1u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     1 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx_d414628a, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           0u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     2 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx_c0cc433b, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           2u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     3 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx_3b6533a8, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           4u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx{RBTM_FR}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     4 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_036251db, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           6u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx{RBTM_FR}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
  { /*     5 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx_510ebea9, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           3u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx{RBTM_FR}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     6 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_b14888e8, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           7u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx{RBTM_FR}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
  { /*     7 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx_536fd8c4, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       1u,           5u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx{RBTM_FR}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*     8 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_6f7c1760, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           8u }   /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx{RBTM_FR}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRomRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRomRBTM_FL
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  LockRomIdx           the index of the 1:1 relation pointing to PduR_LockRom
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRomRBTM_FL[9] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LockRomIdx  MmRomIdx  RmDestRomStartIdx  SrcHnd                                                                                       Comment                                       Referable Keys */
  { /*     0 */         0u,       0u,                2u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_e35239dd },  /* [PduRSrcPdu: PduRSrcPdu_19a79fac] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/PduRSrcPdu_19a79fac] */
  { /*     1 */         0u,       0u,                1u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_4a102435 },  /* [PduRSrcPdu: PduRSrcPdu_0e266b08] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/PduRSrcPdu_0e266b08] */
  { /*     2 */         0u,       0u,                3u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_44714e59 },  /* [PduRSrcPdu: PduRSrcPdu_1a629478] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/PduRSrcPdu_1a629478] */
  { /*     3 */         0u,       0u,                8u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_530d12e8 },  /* [PduRSrcPdu: PduRSrcPdu_a44b5ded] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx/PduRSrcPdu_a44b5ded{RBTM_FL}] */
  { /*     4 */         0u,       0u,                7u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_690fe637 },  /* [PduRSrcPdu: PduRSrcPdu_80d1f2da] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx/PduRSrcPdu_80d1f2da{RBTM_FL}] */
  { /*     5 */         0u,       0u,                0u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_b61ae5cc },  /* [PduRSrcPdu: PduRSrcPdu_03bff274] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx/PduRSrcPdu_03bff274{RBTM_FL}] */
  { /*     6 */         0u,       1u,                6u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx_70f6d2b0 },  /* [PduRSrcPdu: PduRSrcPdu_7f35c914] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx/PduRSrcPdu_7f35c914{RBTM_FL}] */
  { /*     7 */         0u,       1u,                4u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx_2b590afc },  /* [PduRSrcPdu: PduRSrcPdu_249a1158] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx/PduRSrcPdu_249a1158{RBTM_FL}] */
  { /*     8 */         0u,       1u,                5u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx_3060e687 }   /* [PduRSrcPdu: PduRSrcPdu_3fa3fd23] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx/PduRSrcPdu_3fa3fd23{RBTM_FL}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRomRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRomRBTM_FR
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  LockRomIdx           the index of the 1:1 relation pointing to PduR_LockRom
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRomRBTM_FR[9] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    LockRomIdx  MmRomIdx  RmDestRomStartIdx  SrcHnd                                                                                       Comment                                       Referable Keys */
  { /*     0 */         0u,       0u,                1u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_64c01817 },  /* [PduRSrcPdu: PduRSrcPdu_19a79fac] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/PduRSrcPdu_19a79fac] */
  { /*     1 */         0u,       0u,                0u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_84669b72 },  /* [PduRSrcPdu: PduRSrcPdu_0e266b08] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/PduRSrcPdu_0e266b08] */
  { /*     2 */         0u,       0u,                2u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_dbf7577d },  /* [PduRSrcPdu: PduRSrcPdu_1a629478] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/PduRSrcPdu_1a629478] */
  { /*     3 */         0u,       0u,                4u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_036251db },  /* [PduRSrcPdu: PduRSrcPdu_7beeea72] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx/PduRSrcPdu_7beeea72{RBTM_FR}] */
  { /*     4 */         0u,       0u,                3u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_b14888e8 },  /* [PduRSrcPdu: PduRSrcPdu_4d07a2cf] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx/PduRSrcPdu_4d07a2cf{RBTM_FR}] */
  { /*     5 */         0u,       0u,                5u,                                            CanTpConf_CanTpRxNSdu_CanTpRxNSdu_6f7c1760 },  /* [PduRSrcPdu: PduRSrcPdu_8aa11052] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx/PduRSrcPdu_8aa11052{RBTM_FR}] */
  { /*     6 */         0u,       1u,                6u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx_82eb6958 },  /* [PduRSrcPdu: PduRSrcPdu_8d2872fc] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx/PduRSrcPdu_8d2872fc{RBTM_FR}] */
  { /*     7 */         0u,       1u,                7u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx_afb57ffd },  /* [PduRSrcPdu: PduRSrcPdu_a0766459] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx/PduRSrcPdu_a0766459{RBTM_FR}] */
  { /*     8 */         0u,       1u,                8u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx_f8a04d74 }   /* [PduRSrcPdu: PduRSrcPdu_f76356d0] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx/PduRSrcPdu_f76356d0{RBTM_FR}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_RmTransmitFctPtr
  \brief  Internal routing manager Transmit functions.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RmTransmitFctPtr                  Referable Keys */
  /*     0 */ PduR_RmTp_Transmit_MultiDest    /* [PduR_RmTp_Transmit_MultiDest] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2SrcRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2SrcRBTM_FL
  \brief  This table contains all routing information to perform the ChangeParameter or CancelReceive handling. Used in ChangeParameter and CancelReceive APIs 	race SPEC-1024
  \details
  Element         Description
  RmDestRomIdx    the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RxTp2SrcType, PDUR_CONST) PduR_RxTp2SrcRBTM_FL[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RmDestRomIdx */
  { /*     0 */           2u },
  { /*     1 */           1u },
  { /*     2 */           3u },
  { /*     3 */           8u },
  { /*     4 */           7u },
  { /*     5 */           0u }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2SrcRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2SrcRBTM_FR
  \brief  This table contains all routing information to perform the ChangeParameter or CancelReceive handling. Used in ChangeParameter and CancelReceive APIs 	race SPEC-1024
  \details
  Element         Description
  RmDestRomIdx    the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RxTp2SrcType, PDUR_CONST) PduR_RxTp2SrcRBTM_FR[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    RmDestRomIdx */
  { /*     0 */           1u },
  { /*     1 */           0u },
  { /*     2 */           2u },
  { /*     3 */           4u },
  { /*     4 */           3u },
  { /*     5 */           5u }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all information to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element                Description
  RmSrcRomIdx            the index of the 0:1 relation pointing to PduR_RmSrcRom
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RmSrcRomIdx  RmTransmitFctPtrIdx        Referable Keys */
  { /*     0 */          6u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx/PduRSrcPdu_7f35c914{RBTM_FL}] */
  { /*     1 */          7u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx/PduRSrcPdu_249a1158{RBTM_FL}] */
  { /*     2 */          8u,                  0u }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx/PduRSrcPdu_3fa3fd23{RBTM_FL}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxTp2Src
**********************************************************************************************************************/
/** 
  \var    PduR_TxTp2Src
  \brief  This table contains all routing information to perform the Tx handling of a transport protocol routing, Used in the &lt;LoTp&gt;_CopyTxData and &lt;LoTp&gt;_TxConfirmation
  \details
  Element          Description
  RmGDestRomIdx    the index of the 1:1 relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_TxTp2SrcType, PDUR_CONST) PduR_TxTp2Src[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RmGDestRomIdx        Referable Keys */
  { /*     0 */            4u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx{RBTM_FL}] */
  { /*     1 */            6u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx{RBTM_FL}] */
  { /*     2 */            8u }   /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx{RBTM_FL}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_InitializedRam
**********************************************************************************************************************/
/** 
  \var    PduR_InitializedRam
  \brief  Initialized status of each partition the PduR runs on.
*/ 
#define PDUR_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(PduR_InitializedRamUType, PDUR_VAR_NO_INIT) PduR_InitializedRam;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [PduRSinglePartitionDummy] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [PduRSinglePartitionDummy] */

#define PDUR_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCConfig
**********************************************************************************************************************/
/** 
  \var    PduR_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to PduR_PCPartitionConfig
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_PCConfigsType, PDUR_CONST) PduR_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_RBTM_FL] */
      PduR_PCPartitionConfigRBTM_FL  /**< the pointer to PduR_PCPartitionConfig in Config_RBTM_FL */
  },
  { /* Index: 1 Keys: [Config_RBTM_FR] */
      PduR_PCPartitionConfigRBTM_FR  /**< the pointer to PduR_PCPartitionConfig in Config_RBTM_FR */
  }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfigRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfigRBTM_FL
  \details
  Element       Description
  RmDestRom     the pointer to PduR_RmDestRom
  RmGDestRom    the pointer to PduR_RmGDestRom
  RmSrcRom      the pointer to PduR_RmSrcRom
  RxTp2Src      the pointer to PduR_RxTp2Src
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfigRBTM_FL[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CommonSharedMemory] */
      PduR_RmDestRomRBTM_FL   /**< the pointer to PduR_RmDestRom in Config_RBTM_FL */
    , PduR_RmGDestRomRBTM_FL  /**< the pointer to PduR_RmGDestRom in Config_RBTM_FL */
    , PduR_RmSrcRomRBTM_FL    /**< the pointer to PduR_RmSrcRom in Config_RBTM_FL */
    , PduR_RxTp2SrcRBTM_FL    /**< the pointer to PduR_RxTp2Src in Config_RBTM_FL */
  }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfigRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfigRBTM_FR
  \details
  Element       Description
  RmDestRom     the pointer to PduR_RmDestRom
  RmGDestRom    the pointer to PduR_RmGDestRom
  RmSrcRom      the pointer to PduR_RmSrcRom
  RxTp2Src      the pointer to PduR_RxTp2Src
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfigRBTM_FR[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CommonSharedMemory] */
      PduR_RmDestRomRBTM_FR   /**< the pointer to PduR_RmDestRom in Config_RBTM_FR */
    , PduR_RmGDestRomRBTM_FR  /**< the pointer to PduR_RmGDestRom in Config_RBTM_FR */
    , PduR_RmSrcRomRBTM_FR    /**< the pointer to PduR_RmSrcRom in Config_RBTM_FR */
    , PduR_RxTp2SrcRBTM_FR    /**< the pointer to PduR_RxTp2Src in Config_RBTM_FR */
  }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


#define PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(PDUR_USE_INIT_POINTER == STD_ON)
P2CONST(PduR_PBConfigType, PDUR_VAR_CLEARED, PDUR_PBCFG) PduR_ConfigDataPtr = (const PduR_PBConfigType *) NULL_PTR;
#endif

#define PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#define PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

VAR(boolean, PDUR_VAR_NO_INIT) PduR_PreInitialized;

#define PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */
  
/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define PDUR_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "PduR_MemMap.h"

/* Exclusive Area Wrapper functions */

/**********************************************************************************************************************
 * PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/
/*!
 * \internal
 * -  enter the EA  
 * \endinternal
 *********************************************************************************************************************/
static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void)
{
  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
}


/**********************************************************************************************************************
 * PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/
/*!
 * \internal
 * -  exit the EA  
 * \endinternal
 *********************************************************************************************************************/
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void)
{
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
}


/* Upper Layer Interface APIs */

/**********************************************************************************************************************
 * PduR_DcmTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
  Std_ReturnType retVal = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/* Communication Interface APIs */


/* Transport Protocol APIs */

/**********************************************************************************************************************
 * PduR_CanTpStartOfReception
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call transport protocoll StartOfReception function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpStartOfReception(id, info, TpSduLength, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_SOR, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyRxData.
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyRxData(id, info, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYRX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);  			/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyTxData.
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if(PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyTxData(id, info, retry, availableDataPtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYTX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     				/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);  					/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);  				/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp RxIndication function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpRxIndication(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPRXIND, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp TxConfirmation function 
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpTxConfirmation(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPTXCFM, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 * PduR_DcmChangeParameter
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general ChangeParameter function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
  return PduR_ChangeParameter(id, parameter, value); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}


/* CancelReceive global without UseTag API */

/* ChangeParameter global without UseTag  API */


/* Communication Interface / Transport Protocol APIs */

/* Communication Interface / Transport Protocol APIs */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


#define PDUR_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "PduR_MemMap.h"

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API is called with an Id and a pointer.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \N The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       The pointer is provided by the lower layer and is assumed to be valid. It is passed as is to the corresponding function. 

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API is called with an Id.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \R The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       
  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY
    \DESCRIPTION    The API call is forwarded to an internal function.
    \COUNTERMEASURE \N The parameter are checked in the called function.

 SBSW_JUSTIFICATION_END */
 
 /* COV_JUSTIFICATION_BEGIN
 
  \ID COV_PDUR_WRAPPER_FUNC
    \ACCEPT X
    \REASON Each neighbouring module call the same internal function. The call is covered by an other module. 
    
  \ID COV_PDUR_RX_OR_TX_ONLY_CONFIG
    \ACCEPT TX
    \REASON The API is mandatory if this Bsw module exists. In case of Rx or Tx only configs the API call is not forwarded to the internal function. 
 
 COV_JUSTIFICATION_END */
 

/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.c
 *********************************************************************************************************************/

