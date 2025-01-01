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
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:06
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
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
#include "PduR_CanIf.h"
#include "PduR_CanNm.h"
#include "PduR_CanTp.h"
#include "PduR_Com.h"
#include "PduR_Dcm.h"
#include "PduR_IpduM.h"
#include "PduR_SecOC.h"


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
  PduR_GeneralPropertiesRom
**********************************************************************************************************************/
/** 
  \var    PduR_GeneralPropertiesRom
  \brief  General Properties Switches of the PduR.
  \details
  Element         Description
  hasIfRouting
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_GeneralPropertiesRomType, PDUR_CONST) PduR_GeneralPropertiesRom[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    hasIfRouting        Referable Keys */
  { /*     0 */         TRUE }   /* [/ActiveEcuC/PduR] */
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
  MaskedBits                    contains bitcoded the boolean data of PduR_IfCancelTransmitSupportedOfMmRom, PduR_LoIfOfMmRom, PduR_LoTpOfMmRom, PduR_TpCancelTransmitSupportedOfMmRom, PduR_UpIfOfMmRom, PduR_UpTpOfMmRom
  LoIfCancelTransmitFctPtr      Lower layer cancel transmit function pointers.
  LoTpCancelTransmitFctPtr      Lower layer cancel transmit function pointers.
  UpTpCopyRxDataFctPtr          Transport protocol CopyRxData function pointers
  UpTpCopyTxDataFctPtr          Transport protocol CopyTxData function pointers
  UpIfRxIndicationFctPtr        Upper layer communication interface Rx indication function pointers.
  UpIfTxConfirmationFctPtr      Upper layer communication interface Tx confimation function pointers
  UpTpStartOfReceptionFctPtr    Transport protocol StartOfReception function pointers
  UpTpTpRxIndicationFctPtr      Transport protocol TpRxIndication function pointers
  UpTpTpTxConfirmationFctPtr    Transport protocol TpTxConfimation function pointers
  LoIfTransmitFctPtr            Lower layer If transmit function pointers
  LoTpTransmitFctPtr            Lower layer Tp transmit function pointers
  UpIfTriggerTransmitFctPtr     Upper layer trigger transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  LoIfCancelTransmitFctPtr  LoTpCancelTransmitFctPtr  UpTpCopyRxDataFctPtr  UpTpCopyTxDataFctPtr  UpIfRxIndicationFctPtr  UpIfTxConfirmationFctPtr  UpTpStartOfReceptionFctPtr  UpTpTpRxIndicationFctPtr  UpTpTpTxConfirmationFctPtr  LoIfTransmitFctPtr  LoTpTransmitFctPtr  UpIfTriggerTransmitFctPtr        Referable Keys */
  { /*     0 */      0x30u, CanIf_CancelTransmit    , NULL_PTR                , NULL_PTR            , NULL_PTR            , NULL_PTR              , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , CanIf_Transmit    , NULL_PTR          , NULL_PTR                  },  /* [/ActiveEcuC/PduR/CanIf] */
  { /*     1 */      0x30u, CanNm_CancelTransmit    , NULL_PTR                , NULL_PTR            , NULL_PTR            , NULL_PTR              , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , CanNm_Transmit    , NULL_PTR          , NULL_PTR                  },  /* [/ActiveEcuC/PduR/CanNm] */
  { /*     2 */      0x0Cu, NULL_PTR                , CanTp_CancelTransmit    , NULL_PTR            , NULL_PTR            , NULL_PTR              , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , NULL_PTR          , CanTp_Transmit    , NULL_PTR                  },  /* [/ActiveEcuC/PduR/CanTp] */
  { /*     3 */      0x02u, NULL_PTR                , NULL_PTR                , NULL_PTR            , NULL_PTR            , Com_RxIndication      , Com_TxConfirmation      , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , NULL_PTR          , NULL_PTR          , Com_TriggerTransmit       },  /* [/ActiveEcuC/PduR/Com] */
  { /*     4 */      0x01u, NULL_PTR                , NULL_PTR                , Dcm_CopyRxData      , Dcm_CopyTxData      , NULL_PTR              , NULL_PTR                , Dcm_StartOfReception      , Dcm_TpRxIndication      , Dcm_TpTxConfirmation      , NULL_PTR          , NULL_PTR          , NULL_PTR                  },  /* [/ActiveEcuC/PduR/Dcm] */
  { /*     5 */      0x12u, NULL_PTR                , NULL_PTR                , NULL_PTR            , NULL_PTR            , IpduM_RxIndication    , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , IpduM_Transmit    , NULL_PTR          , NULL_PTR                  },  /* [/ActiveEcuC/PduR/IpduM] */
  { /*     6 */      0x12u, NULL_PTR                , NULL_PTR                , NULL_PTR            , NULL_PTR            , SecOC_RxIndication    , NULL_PTR                , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , SecOC_Transmit    , NULL_PTR          , NULL_PTR                  }   /* [/ActiveEcuC/PduR/SecOc] */
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
  \brief  the partition context in Config_Left
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
  PduR_RmDestRomLeft
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRomLeft
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
CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRomLeft[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduLengthHandlingStrategy                         RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                                    Referable Keys */
  { /*     0 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           48u,         43u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx_03bff274_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx/PduRSrcPdu_03bff274{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx_03bff274_Rx{Left}] */
  { /*     1 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            1u,          1u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PREDICTION_ST3_1de136c9_Rx_0518217c_Rx]                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_1de136c9_Rx/PduRSrcPdu_0518217c, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_1de136c9_Rx/ADAS_PREDICTION_ST3_1de136c9_Rx_0518217c_Rx] */
  { /*     2 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           37u,         50u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: RBTM_FL_Tens_ST3_49d8a970_Tx]                                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Tens_ST3_553ec607_Tx/PduRSrcPdu_074527d1{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Tens_ST3_553ec607_Tx/RBTM_FL_Tens_ST3_49d8a970_Tx{Left}] */
  { /*     3 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           42u,         39u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/PduRSrcPdu_0e266b08, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx] */
  { /*     4 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           13u,         10u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: CLkS_Dr_State_ST3_74337ed5_Rx_0fa9281f_Rx]                       */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CLkS_Dr_State_ST3_74337ed5_Rx/PduRSrcPdu_0fa9281f, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CLkS_Dr_State_ST3_74337ed5_Rx/CLkS_Dr_State_ST3_74337ed5_Rx_0fa9281f_Rx] */
  { /*     5 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           12u,         35u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BeltHdOvr_FL_State_ST3_0b4fb3a9_Rx_11170208_Rx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltHdOvr_FL_State_ST3_0b4fb3a9_Rx/PduRSrcPdu_11170208{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltHdOvr_FL_State_ST3_0b4fb3a9_Rx/BeltHdOvr_FL_State_ST3_0b4fb3a9_Rx_11170208_Rx{Left}] */
  { /*     6 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           52u,         31u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx_13123c17_Rx]            */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx/PduRSrcPdu_13123c17, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx/VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx_13123c17_Rx] */
  { /*     7 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           19u,         46u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ECU_Stat_RBTM_FL_ST3_42655720_Tx]                                */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ECU_Stat_RBTM_FL_ST3_f703b6eb_Tx/PduRSrcPdu_140ec449{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ECU_Stat_RBTM_FL_ST3_f703b6eb_Tx/ECU_Stat_RBTM_FL_ST3_42655720_Tx{Left}] */
  { /*     8 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           41u,         38u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/PduRSrcPdu_19a79fac, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx] */
  { /*     9 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           43u,         40u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/PduRSrcPdu_1a629478, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx] */
  { /*    10 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           25u,         20u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Impact2_ST3_e5526ccc_Rx]                                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact2_ST3_e5526ccc_Rx/PduRSrcPdu_22492bdd, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact2_ST3_e5526ccc_Rx/Impact2_ST3_e5526ccc_Rx] */
  { /*    11 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           47u,         53u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx/PduRSrcPdu_249a1158{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx{Left}] */
  { /*    12 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           39u,         51u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ROE_RBTM_FL_ST3_75ad963a_Tx]                                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ROE_RBTM_FL_ST3_a66ccb5f_Tx/PduRSrcPdu_25bb0169{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ROE_RBTM_FL_ST3_a66ccb5f_Tx/ROE_RBTM_FL_ST3_75ad963a_Tx{Left}] */
  { /*    13 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            2u,          2u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PREDICTION_ST3_6_262b63d1_Rx]                               */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_6_262b63d1_Rx/PduRSrcPdu_27f93d01, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_6_262b63d1_Rx/ADAS_PREDICTION_ST3_6_262b63d1_Rx] */
  { /*    14 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           11u,          9u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BeltAdj_UI_Set_Rq_ST3_7be22993_Rx_350798fb_Rx]                   */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_UI_Set_Rq_ST3_7be22993_Rx/PduRSrcPdu_350798fb, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_UI_Set_Rq_ST3_7be22993_Rx/BeltAdj_UI_Set_Rq_ST3_7be22993_Rx_350798fb_Rx] */
  { /*    15 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           33u,         26u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx_3ba6bace_Rx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx/PduRSrcPdu_3ba6bace, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx/PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx_3ba6bace_Rx] */
  { /*    16 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           15u,         13u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DI_OdoSpeedometer_ST3_0665a232_Rx_3e9512b9_Rx]                   */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DI_OdoSpeedometer_ST3_0665a232_Rx/PduRSrcPdu_3e9512b9, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DI_OdoSpeedometer_ST3_0665a232_Rx/DI_OdoSpeedometer_ST3_0665a232_Rx_3e9512b9_Rx] */
  { /*    17 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           49u,         54u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx/PduRSrcPdu_3fa3fd23{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx{Left}] */
  { /*    18 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            9u,         44u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BeltAdj_FL_Stat_ST3_71e5093a_Tx]                                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FL_Stat_ST3_d2ce0dbb_Tx/PduRSrcPdu_4459b19c{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FL_Stat_ST3_d2ce0dbb_Tx/BeltAdj_FL_Stat_ST3_71e5093a_Tx{Left}] */
  { /*    19 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           53u,         32u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_SharedSecret_ST3_6d7ca724_Rx_44cfb2dc_Rx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SharedSecret_ST3_6d7ca724_Rx/PduRSrcPdu_44cfb2dc, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SharedSecret_ST3_6d7ca724_Rx/VSS_TP_SharedSecret_ST3_6d7ca724_Rx_44cfb2dc_Rx] */
  { /*    20 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           32u,         25u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx_470e8c8b_Rx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx/PduRSrcPdu_470e8c8b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx/PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx_470e8c8b_Rx] */
  { /*    21 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           22u,         17u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx_4b27d50a_Rx]               */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx/PduRSrcPdu_4b27d50a, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx/EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx_4b27d50a_Rx] */
  { /*    22 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           14u,         12u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DIAG_Stat_ST3_d3ec8369_Rx_65d40bec_Rx]                           */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DIAG_Stat_ST3_d3ec8369_Rx/PduRSrcPdu_65d40bec, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DIAG_Stat_ST3_d3ec8369_Rx/DIAG_Stat_ST3_d3ec8369_Rx_65d40bec_Rx] */
  { /*    23 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            7u,          7u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx]                                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx/PduRSrcPdu_6e617592, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx] */
  { /*    24 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           38u,         37u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: RBTM_FR_Stat_ST3_8dd11b6c_Rx_7234ddac_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Stat_ST3_8dd11b6c_Rx/PduRSrcPdu_7234ddac{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Stat_ST3_8dd11b6c_Rx/RBTM_FR_Stat_ST3_8dd11b6c_Rx_7234ddac_Rx{Left}] */
  { /*    25 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           26u,         21u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Impact3_ST3_993f4b56_Rx_7842cc32_Rx]                             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact3_ST3_993f4b56_Rx/PduRSrcPdu_7842cc32, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact3_ST3_993f4b56_Rx/Impact3_ST3_993f4b56_Rx_7842cc32_Rx] */
  { /*    26 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           28u,         48u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: NM_RBTM_FL_ST3_0cdf2d0f_Tx_78db9cf2_Tx]                          */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NM_RBTM_FL_ST3_0cdf2d0f_Tx/PduRSrcPdu_78db9cf2{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NM_RBTM_FL_ST3_0cdf2d0f_Tx/NM_RBTM_FL_ST3_0cdf2d0f_Tx_78db9cf2_Tx{Left}] */
  { /*    27 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            8u,          8u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx_79ab8c0b_Rx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx/PduRSrcPdu_79ab8c0b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx/Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx_79ab8c0b_Rx] */
  { /*    28 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           35u,         27u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PresfAct_Adj_ST3_81976f17_Rx_7d3a747f_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PresfAct_Adj_ST3_81976f17_Rx/PduRSrcPdu_7d3a747f, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PresfAct_Adj_ST3_81976f17_Rx/PresfAct_Adj_ST3_81976f17_Rx_7d3a747f_Rx] */
  { /*    29 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           45u,         52u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx/PduRSrcPdu_7f35c914{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx{Left}] */
  { /*    30 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           46u,         42u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx_80d1f2da_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx/PduRSrcPdu_80d1f2da{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx_80d1f2da_Rx{Left}] */
  { /*    31 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           29u,         22u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: NTG_Master_Navi_ST3_1032e485_Rx_8a45ba67_Rx]                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NTG_Master_Navi_ST3_1032e485_Rx/PduRSrcPdu_8a45ba67, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NTG_Master_Navi_ST3_1032e485_Rx/NTG_Master_Navi_ST3_1032e485_Rx_8a45ba67_Rx] */
  { /*    32 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           51u,         30u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_RealTmOffset_ST3_d6d134b3_Rx_9136979d_Rx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_RealTmOffset_ST3_d6d134b3_Rx/PduRSrcPdu_9136979d, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_RealTmOffset_ST3_d6d134b3_Rx/VSS_TP_RealTmOffset_ST3_d6d134b3_Rx_9136979d_Rx] */
  { /*    33 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           36u,         49u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: RBTM_FL_Stat_ST3_d76d14af_Tx]                                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Stat_ST3_dd2436a1_Tx/PduRSrcPdu_9690baaa{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Stat_ST3_dd2436a1_Tx/RBTM_FL_Stat_ST3_d76d14af_Tx{Left}] */
  { /*    34 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            6u,          5u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx]                           */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx/PduRSrcPdu_9e880434, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx] */
  { /*    35 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           30u,         23u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PN14_Master_Stat1_ST3_69644078_Rx_a0c57bb3_Rx]                   */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PN14_Master_Stat1_ST3_69644078_Rx/PduRSrcPdu_a0c57bb3, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PN14_Master_Stat1_ST3_69644078_Rx/PN14_Master_Stat1_ST3_69644078_Rx_a0c57bb3_Rx] */
  { /*    36 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           44u,         41u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx_a44b5ded_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx/PduRSrcPdu_a44b5ded{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx_a44b5ded_Rx{Left}] */
  { /*    37 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           31u,         24u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PT4_PTCoor4_ST3_868ca7d3_Rx_a7894e67_Rx]                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor4_ST3_868ca7d3_Rx/PduRSrcPdu_a7894e67, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor4_ST3_868ca7d3_Rx/PT4_PTCoor4_ST3_868ca7d3_Rx_a7894e67_Rx] */
  { /*    38 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           20u,         15u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ELC_Lvr_Stat_ST3_d97bab99_Rx]                                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_d97bab99_Rx/PduRSrcPdu_ae29c120, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_d97bab99_Rx/ELC_Lvr_Stat_ST3_d97bab99_Rx] */
  { /*    39 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           18u,         45u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Develop8_Rs_RBTM_FL_ST3_711f265e_Tx]                             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rs_RBTM_FL_ST3_9a3b4dd1_Tx/PduRSrcPdu_b7de4975{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rs_RBTM_FL_ST3_9a3b4dd1_Tx/Develop8_Rs_RBTM_FL_ST3_711f265e_Tx{Left}] */
  { /*    40 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           34u,         11u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx_bb7efc37_Rx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx/PduRSrcPdu_bb7efc37, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx/ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx_bb7efc37_Rx] */
  { /*    41 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           17u,         36u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Develop8_Rq_RBTM_FL_ST3_0a7cffe6_Rx_c2dcef25_Rx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rq_RBTM_FL_ST3_0a7cffe6_Rx/PduRSrcPdu_c2dcef25{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rq_RBTM_FL_ST3_0a7cffe6_Rx/Develop8_Rq_RBTM_FL_ST3_0a7cffe6_Rx_c2dcef25_Rx{Left}] */
  { /*    42 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           40u,         28u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SBeltTens_SP_Lvl_ST3_73b20851_Rx_c609bb6e_Rx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SBeltTens_SP_Lvl_ST3_73b20851_Rx/PduRSrcPdu_c609bb6e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SBeltTens_SP_Lvl_ST3_73b20851_Rx/SBeltTens_SP_Lvl_ST3_73b20851_Rx_c609bb6e_Rx] */
  { /*    43 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           50u,         29u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_Auth_ST3_29a0d419_Rx_c76c8221_Rx]                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_Auth_ST3_29a0d419_Rx/PduRSrcPdu_c76c8221, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_Auth_ST3_29a0d419_Rx/VSS_TP_Auth_ST3_29a0d419_Rx_c76c8221_Rx] */
  { /*    44 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           23u,         18u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Ign_Stat_ST3_1e3dc39f_Rx]                                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_1e3dc39f_Rx/PduRSrcPdu_c9c2269b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_1e3dc39f_Rx/Ign_Stat_ST3_1e3dc39f_Rx] */
  { /*    45 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            3u,          3u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PREDICTION_ST3_7_512c5347_Rx]                               */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_7_512c5347_Rx/PduRSrcPdu_d1b2606a, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_7_512c5347_Rx/ADAS_PREDICTION_ST3_7_512c5347_Rx] */
  { /*    46 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           21u,         16u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ELC_Lvr_Stat_ST3_secured_29d2456c_Rx_d27a099a_Rx]                */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_secured_29d2456c_Rx/PduRSrcPdu_d27a099a, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_secured_29d2456c_Rx/ELC_Lvr_Stat_ST3_secured_29d2456c_Rx_d27a099a_Rx] */
  { /*    47 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            4u,          4u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx]                            */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx/PduRSrcPdu_d645a86c, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx] */
  { /*    48 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           27u,         47u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Meas8_RBTM_FL_ST3_b4f3e350_Tx]                                   */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meas8_RBTM_FL_ST3_a92f14da_Tx/PduRSrcPdu_d98cd95c{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meas8_RBTM_FL_ST3_a92f14da_Tx/Meas8_RBTM_FL_ST3_b4f3e350_Tx{Left}] */
  { /*    49 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           54u,         33u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_VIN_ST3_f7ab6516_Rx_da8efc5d_Rx]                          */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_VIN_ST3_f7ab6516_Rx/PduRSrcPdu_da8efc5d, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_VIN_ST3_f7ab6516_Rx/VSS_TP_VIN_ST3_f7ab6516_Rx_da8efc5d_Rx] */
    /* Index    PduLengthHandlingStrategy                         RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                                    Referable Keys */
  { /*    50 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            5u,          6u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PROFILE_SHORT_ST3_894b8265_Rx_e0198081_Rx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_894b8265_Rx/PduRSrcPdu_e0198081, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_894b8265_Rx/ADAS_PROFILE_SHORT_ST3_894b8265_Rx_e0198081_Rx] */
  { /*    51 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           16u,         14u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx_ee8d9c90_Rx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx/PduRSrcPdu_ee8d9c90, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx/DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx_ee8d9c90_Rx] */
  { /*    52 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           10u,         34u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BeltAdj_FR_Stat_ST3_2b5906f9_Rx_f252e81e_Rx]                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FR_Stat_ST3_2b5906f9_Rx/PduRSrcPdu_f252e81e{Left}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FR_Stat_ST3_2b5906f9_Rx/BeltAdj_FR_Stat_ST3_2b5906f9_Rx_f252e81e_Rx{Left}] */
  { /*    53 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           24u,         19u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Ign_Stat_ST3_secured_fb0d4f19_Rx_f57d7485_Rx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_secured_fb0d4f19_Rx/PduRSrcPdu_f57d7485, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_secured_fb0d4f19_Rx/Ign_Stat_ST3_secured_fb0d4f19_Rx_f57d7485_Rx] */
  { /*    54 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            0u,          0u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM }   /* [PduRDestPdu: ADAS_POSITION_ST3_1ca04d74_Rx_fa09a036_Rx]                       */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_POSITION_ST3_1ca04d74_Rx/PduRSrcPdu_fa09a036, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_POSITION_ST3_1ca04d74_Rx/ADAS_POSITION_ST3_1ca04d74_Rx_fa09a036_Rx] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRomRight
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRomRight
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
CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRomRight[55] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    PduLengthHandlingStrategy                         RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                                    Referable Keys */
  { /*     0 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            1u,          1u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PREDICTION_ST3_1de136c9_Rx_0518217c_Rx]                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_1de136c9_Rx/PduRSrcPdu_0518217c, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_1de136c9_Rx/ADAS_PREDICTION_ST3_1de136c9_Rx_0518217c_Rx] */
  { /*     1 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           10u,         44u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BeltAdj_FR_Stat_ST3_2b5906f9_Tx]                                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FR_Stat_ST3_eba9bce0_Tx/PduRSrcPdu_0892c3c5{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FR_Stat_ST3_eba9bce0_Tx/BeltAdj_FR_Stat_ST3_2b5906f9_Tx{Right}] */
  { /*     2 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           42u,         39u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/PduRSrcPdu_0e266b08, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx] */
  { /*     3 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           13u,         10u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: CLkS_Dr_State_ST3_74337ed5_Rx_0fa9281f_Rx]                       */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CLkS_Dr_State_ST3_74337ed5_Rx/PduRSrcPdu_0fa9281f, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CLkS_Dr_State_ST3_74337ed5_Rx/CLkS_Dr_State_ST3_74337ed5_Rx_0fa9281f_Rx] */
  { /*     4 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           52u,         31u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx_13123c17_Rx]            */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx/PduRSrcPdu_13123c17, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx/VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx_13123c17_Rx] */
  { /*     5 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           36u,         37u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: RBTM_FL_Stat_ST3_d76d14af_Rx_16ae0594_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Stat_ST3_d76d14af_Rx/PduRSrcPdu_16ae0594{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Stat_ST3_d76d14af_Rx/RBTM_FL_Stat_ST3_d76d14af_Rx_16ae0594_Rx{Right}] */
  { /*     6 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           41u,         38u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/PduRSrcPdu_19a79fac, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx] */
  { /*     7 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           43u,         40u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/PduRSrcPdu_1a629478, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx] */
  { /*     8 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           25u,         20u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Impact2_ST3_e5526ccc_Rx]                                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact2_ST3_e5526ccc_Rx/PduRSrcPdu_22492bdd, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact2_ST3_e5526ccc_Rx/Impact2_ST3_e5526ccc_Rx] */
  { /*     9 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            2u,          2u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PREDICTION_ST3_6_262b63d1_Rx]                               */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_6_262b63d1_Rx/PduRSrcPdu_27f93d01, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_6_262b63d1_Rx/ADAS_PREDICTION_ST3_6_262b63d1_Rx] */
  { /*    10 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           28u,         48u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: NM_RBTM_FR_ST3_d30f04ec_Tx_2c5f6cda_Tx]                          */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NM_RBTM_FR_ST3_d30f04ec_Tx/PduRSrcPdu_2c5f6cda{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NM_RBTM_FR_ST3_d30f04ec_Tx/NM_RBTM_FR_ST3_d30f04ec_Tx_2c5f6cda_Tx{Right}] */
  { /*    11 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           19u,         46u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ECU_Stat_RBTM_FR_ST3_9988b431_Tx]                                */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ECU_Stat_RBTM_FR_ST3_28d39f08_Tx/PduRSrcPdu_2db65a34{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ECU_Stat_RBTM_FR_ST3_28d39f08_Tx/ECU_Stat_RBTM_FR_ST3_9988b431_Tx{Right}] */
  { /*    12 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           11u,          9u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BeltAdj_UI_Set_Rq_ST3_7be22993_Rx_350798fb_Rx]                   */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_UI_Set_Rq_ST3_7be22993_Rx/PduRSrcPdu_350798fb, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_UI_Set_Rq_ST3_7be22993_Rx/BeltAdj_UI_Set_Rq_ST3_7be22993_Rx_350798fb_Rx] */
  { /*    13 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           33u,         26u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx_3ba6bace_Rx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx/PduRSrcPdu_3ba6bace, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx/PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx_3ba6bace_Rx] */
  { /*    14 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           15u,         13u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DI_OdoSpeedometer_ST3_0665a232_Rx_3e9512b9_Rx]                   */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DI_OdoSpeedometer_ST3_0665a232_Rx/PduRSrcPdu_3e9512b9, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DI_OdoSpeedometer_ST3_0665a232_Rx/DI_OdoSpeedometer_ST3_0665a232_Rx_3e9512b9_Rx] */
  { /*    15 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           53u,         32u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_SharedSecret_ST3_6d7ca724_Rx_44cfb2dc_Rx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SharedSecret_ST3_6d7ca724_Rx/PduRSrcPdu_44cfb2dc, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SharedSecret_ST3_6d7ca724_Rx/VSS_TP_SharedSecret_ST3_6d7ca724_Rx_44cfb2dc_Rx] */
  { /*    16 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           37u,         49u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: RBTM_FR_Stat_ST3_8dd11b6c_Tx]                                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Stat_ST3_e44387fa_Tx/PduRSrcPdu_45e6f19d{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Stat_ST3_e44387fa_Tx/RBTM_FR_Stat_ST3_8dd11b6c_Tx{Right}] */
  { /*    17 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           32u,         25u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx_470e8c8b_Rx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx/PduRSrcPdu_470e8c8b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx/PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx_470e8c8b_Rx] */
  { /*    18 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           22u,         17u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx_4b27d50a_Rx]               */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx/PduRSrcPdu_4b27d50a, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx/EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx_4b27d50a_Rx] */
  { /*    19 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           12u,         35u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BeltHdOvr_FR_State_ST3_09789cac_Rx_4c2f4fea_Rx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltHdOvr_FR_State_ST3_09789cac_Rx/PduRSrcPdu_4c2f4fea{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltHdOvr_FR_State_ST3_09789cac_Rx/BeltHdOvr_FR_State_ST3_09789cac_Rx_4c2f4fea_Rx{Right}] */
  { /*    20 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           46u,         42u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx_4d07a2cf_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx/PduRSrcPdu_4d07a2cf{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx_4d07a2cf_Rx{Right}] */
  { /*    21 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           14u,         12u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DIAG_Stat_ST3_d3ec8369_Rx_65d40bec_Rx]                           */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DIAG_Stat_ST3_d3ec8369_Rx/PduRSrcPdu_65d40bec, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DIAG_Stat_ST3_d3ec8369_Rx/DIAG_Stat_ST3_d3ec8369_Rx_65d40bec_Rx] */
  { /*    22 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            7u,          7u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx]                                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx/PduRSrcPdu_6e617592, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx] */
  { /*    23 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           17u,         36u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Develop8_Rq_RBTM_FR_ST3_d1911cf7_Rx_73b8d236_Rx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rq_RBTM_FR_ST3_d1911cf7_Rx/PduRSrcPdu_73b8d236{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rq_RBTM_FR_ST3_d1911cf7_Rx/Develop8_Rq_RBTM_FR_ST3_d1911cf7_Rx_73b8d236_Rx{Right}] */
  { /*    24 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           26u,         21u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Impact3_ST3_993f4b56_Rx_7842cc32_Rx]                             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact3_ST3_993f4b56_Rx/PduRSrcPdu_7842cc32, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact3_ST3_993f4b56_Rx/Impact3_ST3_993f4b56_Rx_7842cc32_Rx] */
  { /*    25 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            8u,          8u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx_79ab8c0b_Rx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx/PduRSrcPdu_79ab8c0b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx/Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx_79ab8c0b_Rx] */
  { /*    26 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           44u,         41u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx_7beeea72_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx/PduRSrcPdu_7beeea72{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx_7beeea72_Rx{Right}] */
  { /*    27 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           35u,         27u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PresfAct_Adj_ST3_81976f17_Rx_7d3a747f_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PresfAct_Adj_ST3_81976f17_Rx/PduRSrcPdu_7d3a747f, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PresfAct_Adj_ST3_81976f17_Rx/PresfAct_Adj_ST3_81976f17_Rx_7d3a747f_Rx] */
  { /*    28 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           29u,         22u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: NTG_Master_Navi_ST3_1032e485_Rx_8a45ba67_Rx]                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NTG_Master_Navi_ST3_1032e485_Rx/PduRSrcPdu_8a45ba67, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NTG_Master_Navi_ST3_1032e485_Rx/NTG_Master_Navi_ST3_1032e485_Rx_8a45ba67_Rx] */
  { /*    29 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           48u,         43u, PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx_8aa11052_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx/PduRSrcPdu_8aa11052{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx_8aa11052_Rx{Right}] */
  { /*    30 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           45u,         52u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx/PduRSrcPdu_8d2872fc{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx{Right}] */
  { /*    31 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           51u,         30u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_RealTmOffset_ST3_d6d134b3_Rx_9136979d_Rx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_RealTmOffset_ST3_d6d134b3_Rx/PduRSrcPdu_9136979d, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_RealTmOffset_ST3_d6d134b3_Rx/VSS_TP_RealTmOffset_ST3_d6d134b3_Rx_9136979d_Rx] */
  { /*    32 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           18u,         45u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Develop8_Rs_RBTM_FR_ST3_aaf2c54f_Tx]                             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rs_RBTM_FR_ST3_45eb6432_Tx/PduRSrcPdu_981fdebc{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rs_RBTM_FR_ST3_45eb6432_Tx/Develop8_Rs_RBTM_FR_ST3_aaf2c54f_Tx{Right}] */
  { /*    33 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            9u,         34u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BeltAdj_FL_Stat_ST3_71e5093a_Rx_9982cecc_Rx]                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FL_Stat_ST3_71e5093a_Rx/PduRSrcPdu_9982cecc{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FL_Stat_ST3_71e5093a_Rx/BeltAdj_FL_Stat_ST3_71e5093a_Rx_9982cecc_Rx{Right}] */
  { /*    34 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            6u,          5u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx]                           */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx/PduRSrcPdu_9e880434, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx] */
  { /*    35 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           47u,         53u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx/PduRSrcPdu_a0766459{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx{Right}] */
  { /*    36 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           30u,         23u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PN14_Master_Stat1_ST3_69644078_Rx_a0c57bb3_Rx]                   */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PN14_Master_Stat1_ST3_69644078_Rx/PduRSrcPdu_a0c57bb3, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PN14_Master_Stat1_ST3_69644078_Rx/PN14_Master_Stat1_ST3_69644078_Rx_a0c57bb3_Rx] */
  { /*    37 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           31u,         24u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: PT4_PTCoor4_ST3_868ca7d3_Rx_a7894e67_Rx]                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor4_ST3_868ca7d3_Rx/PduRSrcPdu_a7894e67, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor4_ST3_868ca7d3_Rx/PT4_PTCoor4_ST3_868ca7d3_Rx_a7894e67_Rx] */
  { /*    38 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           38u,         50u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: RBTM_FR_Tens_ST3_1364a6b3_Tx]                                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Tens_ST3_6c59775c_Tx/PduRSrcPdu_a9321799{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Tens_ST3_6c59775c_Tx/RBTM_FR_Tens_ST3_1364a6b3_Tx{Right}] */
  { /*    39 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           20u,         15u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ELC_Lvr_Stat_ST3_d97bab99_Rx]                                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_d97bab99_Rx/PduRSrcPdu_ae29c120, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_d97bab99_Rx/ELC_Lvr_Stat_ST3_d97bab99_Rx] */
  { /*    40 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           34u,         11u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx_bb7efc37_Rx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx/PduRSrcPdu_bb7efc37, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx/ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx_bb7efc37_Rx] */
  { /*    41 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           40u,         28u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SBeltTens_SP_Lvl_ST3_73b20851_Rx_c609bb6e_Rx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SBeltTens_SP_Lvl_ST3_73b20851_Rx/PduRSrcPdu_c609bb6e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SBeltTens_SP_Lvl_ST3_73b20851_Rx/SBeltTens_SP_Lvl_ST3_73b20851_Rx_c609bb6e_Rx] */
  { /*    42 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           50u,         29u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_Auth_ST3_29a0d419_Rx_c76c8221_Rx]                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_Auth_ST3_29a0d419_Rx/PduRSrcPdu_c76c8221, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_Auth_ST3_29a0d419_Rx/VSS_TP_Auth_ST3_29a0d419_Rx_c76c8221_Rx] */
  { /*    43 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           23u,         18u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Ign_Stat_ST3_1e3dc39f_Rx]                                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_1e3dc39f_Rx/PduRSrcPdu_c9c2269b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_1e3dc39f_Rx/Ign_Stat_ST3_1e3dc39f_Rx] */
  { /*    44 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            3u,          3u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PREDICTION_ST3_7_512c5347_Rx]                               */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_7_512c5347_Rx/PduRSrcPdu_d1b2606a, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_7_512c5347_Rx/ADAS_PREDICTION_ST3_7_512c5347_Rx] */
  { /*    45 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           21u,         16u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ELC_Lvr_Stat_ST3_secured_29d2456c_Rx_d27a099a_Rx]                */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_secured_29d2456c_Rx/PduRSrcPdu_d27a099a, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_secured_29d2456c_Rx/ELC_Lvr_Stat_ST3_secured_29d2456c_Rx_d27a099a_Rx] */
  { /*    46 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            4u,          4u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx]                            */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx/PduRSrcPdu_d645a86c, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx] */
  { /*    47 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           54u,         33u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VSS_TP_VIN_ST3_f7ab6516_Rx_da8efc5d_Rx]                          */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_VIN_ST3_f7ab6516_Rx/PduRSrcPdu_da8efc5d, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_VIN_ST3_f7ab6516_Rx/VSS_TP_VIN_ST3_f7ab6516_Rx_da8efc5d_Rx] */
  { /*    48 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           27u,         47u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Meas8_RBTM_FR_ST3_6f1e0041_Tx]                                   */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meas8_RBTM_FR_ST3_76ff3d39_Tx/PduRSrcPdu_dedcc96f{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meas8_RBTM_FR_ST3_76ff3d39_Tx/Meas8_RBTM_FR_ST3_6f1e0041_Tx{Right}] */
  { /*    49 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            5u,          6u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ADAS_PROFILE_SHORT_ST3_894b8265_Rx_e0198081_Rx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_894b8265_Rx/PduRSrcPdu_e0198081, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_894b8265_Rx/ADAS_PROFILE_SHORT_ST3_894b8265_Rx_e0198081_Rx] */
    /* Index    PduLengthHandlingStrategy                         RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                                    Referable Keys */
  { /*    50 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           16u,         14u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx_ee8d9c90_Rx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx/PduRSrcPdu_ee8d9c90, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx/DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx_ee8d9c90_Rx] */
  { /*    51 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           39u,         51u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: ROE_RBTM_FR_ST3_ae40752b_Tx]                                     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ROE_RBTM_FR_ST3_79bce2bc_Tx/PduRSrcPdu_efc3e236{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ROE_RBTM_FR_ST3_79bce2bc_Tx/ROE_RBTM_FR_ST3_ae40752b_Tx{Right}] */
  { /*    52 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           24u,         19u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: Ign_Stat_ST3_secured_fb0d4f19_Rx_f57d7485_Rx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_secured_fb0d4f19_Rx/PduRSrcPdu_f57d7485, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_secured_fb0d4f19_Rx/Ign_Stat_ST3_secured_fb0d4f19_Rx_f57d7485_Rx] */
  { /*    53 */ PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,           49u,         54u, PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx]             */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx/PduRSrcPdu_f76356d0{Right}, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx{Right}] */
  { /*    54 */ PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM,            0u,          0u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM }   /* [PduRDestPdu: ADAS_POSITION_ST3_1ca04d74_Rx_fa09a036_Rx]                       */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_POSITION_ST3_1ca04d74_Rx/PduRSrcPdu_fa09a036, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_POSITION_ST3_1ca04d74_Rx/ADAS_POSITION_ST3_1ca04d74_Rx_fa09a036_Rx] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRomLeft
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRomLeft
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
CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRomLeft[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaxPduLength  DestHnd                                                                                Direction                      LockRomIdx  MmRomIdx  RmDestRomIdx        Comment                                                                               Referable Keys */
  { /*     0 */           8u,                                         ComConf_ComIPdu_ADAS_POSITION_ST3_0b61d436_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          54u },  /* [Global PduRDestPdu: ADAS_POSITION_ST3_0b61d436_Rx]                       */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_POSITION_ST3_0b61d436_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     1 */           8u,                                IpduMConf_IpduMRxIndication_IpduMRxIndication_33e88c66, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       5u,           1u },  /* [Global PduRDestPdu: ADAS_PREDICTION_ST3_549e2a63_Rx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PREDICTION_ST3_549e2a63_Rx, /ActiveEcuC/PduR/IpduM, PduRSinglePartitionDummy] */
  { /*     2 */           8u,                                     ComConf_ComIPdu_ADAS_PREDICTION_ST3_6_262b63d1_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          13u },  /* [Global PduRDestPdu: ADAS_PREDICTION_ST3_6_262b63d1_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PREDICTION_ST3_6_262b63d1_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     3 */           8u,                                     ComConf_ComIPdu_ADAS_PREDICTION_ST3_7_512c5347_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          45u },  /* [Global PduRDestPdu: ADAS_PREDICTION_ST3_7_512c5347_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PREDICTION_ST3_7_512c5347_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     4 */           8u,                                  ComConf_ComIPdu_ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          47u },  /* [Global PduRDestPdu: ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx]                */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     5 */           8u,                                IpduMConf_IpduMRxIndication_IpduMRxIndication_17ccd7a3, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       5u,          50u },  /* [Global PduRDestPdu: ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx]                  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx, /ActiveEcuC/PduR/IpduM, PduRSinglePartitionDummy] */
  { /*     6 */           8u,                                 ComConf_ComIPdu_ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          34u },  /* [Global PduRDestPdu: ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx]               */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     7 */           4u,                                       ComConf_ComIPdu_Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          23u },  /* [Global PduRDestPdu: Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     8 */           8u,                   SecOCConf_SecOCRxSecuredPdu_Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       6u,          27u },  /* [Global PduRDestPdu: Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx]             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/PduR/SecOc, PduRSinglePartitionDummy] */
  { /*     9 */           1u,                               CanIfConf_CanIfTxPduCfg_BeltAdj_FL_Stat_ST3_df27ce55_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          18u },  /* [Global PduRDestPdu: BeltAdj_FL_Stat_ST3_71e5093a_Tx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltAdj_FL_Stat_ST3_71e5093a_Tx{Left}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    10 */           1u,                                       ComConf_ComIPdu_BeltAdj_FR_Stat_ST3_eba9bce0_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          52u },  /* [Global PduRDestPdu: BeltAdj_FR_Stat_ST3_eba9bce0_Rx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltAdj_FR_Stat_ST3_eba9bce0_Rx{Left}, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    11 */           1u,                                     ComConf_ComIPdu_BeltAdj_UI_Set_Rq_ST3_1223a83d_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          14u },  /* [Global PduRDestPdu: BeltAdj_UI_Set_Rq_ST3_1223a83d_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltAdj_UI_Set_Rq_ST3_1223a83d_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    12 */           4u,                                    ComConf_ComIPdu_BeltHdOvr_FL_State_ST3_342163b7_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,           5u },  /* [Global PduRDestPdu: BeltHdOvr_FL_State_ST3_342163b7_Rx]                  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltHdOvr_FL_State_ST3_342163b7_Rx{Left}, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    13 */           8u,                                         ComConf_ComIPdu_CLkS_Dr_State_ST3_513e9c19_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,           4u },  /* [Global PduRDestPdu: CLkS_Dr_State_ST3_513e9c19_Rx]                       */  /* [/ActiveEcuC/EcuC/EcucPduCollection/CLkS_Dr_State_ST3_513e9c19_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    14 */           4u,                                             ComConf_ComIPdu_DIAG_Stat_ST3_3a031d4a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          22u },  /* [Global PduRDestPdu: DIAG_Stat_ST3_3a031d4a_Rx]                           */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DIAG_Stat_ST3_3a031d4a_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    15 */           8u,                                     ComConf_ComIPdu_DI_OdoSpeedometer_ST3_6fef7507_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          16u },  /* [Global PduRDestPdu: DI_OdoSpeedometer_ST3_6fef7507_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DI_OdoSpeedometer_ST3_6fef7507_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    16 */           1u,                                      ComConf_ComIPdu_DPC_Md_Rq_ESP_d1_ST3_e30f951d_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          51u },  /* [Global PduRDestPdu: DPC_Md_Rq_ESP_d1_ST3_e30f951d_Rx]                    */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DPC_Md_Rq_ESP_d1_ST3_e30f951d_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    17 */           8u,                                   ComConf_ComIPdu_Develop8_Rq_RBTM_FL_ST3_fa67f89a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          41u },  /* [Global PduRDestPdu: Develop8_Rq_RBTM_FL_ST3_fa67f89a_Rx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Develop8_Rq_RBTM_FL_ST3_fa67f89a_Rx{Left}, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    18 */           8u,                           CanIfConf_CanIfTxPduCfg_Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          39u },  /* [Global PduRDestPdu: Develop8_Rs_RBTM_FL_ST3_711f265e_Tx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Develop8_Rs_RBTM_FL_ST3_711f265e_Tx{Left}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    19 */           8u,                              CanIfConf_CanIfTxPduCfg_ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           7u },  /* [Global PduRDestPdu: ECU_Stat_RBTM_FL_ST3_42655720_Tx]                    */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ECU_Stat_RBTM_FL_ST3_42655720_Tx{Left}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    20 */           4u,                                          ComConf_ComIPdu_ELC_Lvr_Stat_ST3_d97bab99_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          38u },  /* [Global PduRDestPdu: ELC_Lvr_Stat_ST3_d97bab99_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_d97bab99_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    21 */           8u,                      SecOCConf_SecOCRxSecuredPdu_ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       6u,          46u },  /* [Global PduRDestPdu: ELC_Lvr_Stat_ST3_secured_7bad7996_Rx]                */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/PduR/SecOc, PduRSinglePartitionDummy] */
  { /*    22 */           8u,                                 ComConf_ComIPdu_EVC_CfgList_01_08_Pr5_ST3_32c5e6fb_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          21u },  /* [Global PduRDestPdu: EVC_CfgList_01_08_Pr5_ST3_32c5e6fb_Rx]               */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EVC_CfgList_01_08_Pr5_ST3_32c5e6fb_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    23 */           4u,                                              ComConf_ComIPdu_Ign_Stat_ST3_1e3dc39f_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          44u },  /* [Global PduRDestPdu: Ign_Stat_ST3_1e3dc39f_Rx]                            */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_1e3dc39f_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    24 */           8u,                          SecOCConf_SecOCRxSecuredPdu_Ign_Stat_ST3_secured_87afaf29_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       6u,          53u },  /* [Global PduRDestPdu: Ign_Stat_ST3_secured_87afaf29_Rx]                    */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/PduR/SecOc, PduRSinglePartitionDummy] */
  { /*    25 */           4u,                                               ComConf_ComIPdu_Impact2_ST3_e5526ccc_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          10u },  /* [Global PduRDestPdu: Impact2_ST3_e5526ccc_Rx]                             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Impact2_ST3_e5526ccc_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    26 */           4u,                                               ComConf_ComIPdu_Impact3_ST3_d832457c_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          25u },  /* [Global PduRDestPdu: Impact3_ST3_d832457c_Rx]                             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Impact3_ST3_d832457c_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    27 */           8u,                                 CanIfConf_CanIfTxPduCfg_Meas8_RBTM_FL_ST3_a87f4b23_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          48u },  /* [Global PduRDestPdu: Meas8_RBTM_FL_ST3_b4f3e350_Tx]                       */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Meas8_RBTM_FL_ST3_b4f3e350_Tx{Left}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    28 */           7u,                                  CanNmConf_CanNmUserDataTxPdu_NM_RBTM_FL_ST3_e414ee7b, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       1u,          26u },  /* [Global PduRDestPdu: NM_RBTM_FL_ST3_0cdf2d0f_Tx]                          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/NM_RBTM_FL_ST3_0cdf2d0f_Tx{Left}, /ActiveEcuC/PduR/CanNm, PduRSinglePartitionDummy] */
  { /*    29 */           2u,                                       ComConf_ComIPdu_NTG_Master_Navi_ST3_dea580a6_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          31u },  /* [Global PduRDestPdu: NTG_Master_Navi_ST3_dea580a6_Rx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/NTG_Master_Navi_ST3_dea580a6_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    30 */           8u,                                     ComConf_ComIPdu_PN14_Master_Stat1_ST3_eba3e383_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          35u },  /* [Global PduRDestPdu: PN14_Master_Stat1_ST3_eba3e383_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PN14_Master_Stat1_ST3_eba3e383_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    31 */           4u,                                           ComConf_ComIPdu_PT4_PTCoor4_ST3_bf069154_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          37u },  /* [Global PduRDestPdu: PT4_PTCoor4_ST3_bf069154_Rx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT4_PTCoor4_ST3_bf069154_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    32 */           1u,                                   ComConf_ComIPdu_PT4_PTCoor9_d1_BC_F_ST3_da786b84_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          20u },  /* [Global PduRDestPdu: PT4_PTCoor9_d1_BC_F_ST3_da786b84_Rx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT4_PTCoor9_d1_BC_F_ST3_da786b84_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    33 */           8u,                               ComConf_ComIPdu_PT4_PTCoor_DrvPosn_Gear_ST3_6b508375_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          15u },  /* [Global PduRDestPdu: PT4_PTCoor_DrvPosn_Gear_ST3_6b508375_Rx]             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT4_PTCoor_DrvPosn_Gear_ST3_6b508375_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    34 */           7u,                                                ComConf_ComIPdu_ComIPduPnc_EIRA_CAN_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          40u },  /* [Global PduRDestPdu: PduPnc_EIRA_CAN_Rx]                                  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PduPnc_EIRA_CAN_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    35 */           8u,                                          ComConf_ComIPdu_PresfAct_Adj_ST3_61c58c91_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          28u },  /* [Global PduRDestPdu: PresfAct_Adj_ST3_61c58c91_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PresfAct_Adj_ST3_61c58c91_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    36 */           8u,                                  CanIfConf_CanIfTxPduCfg_RBTM_FL_Stat_ST3_558a33d8_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          33u },  /* [Global PduRDestPdu: RBTM_FL_Stat_ST3_d76d14af_Tx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FL_Stat_ST3_d76d14af_Tx{Left}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    37 */           8u,                                  CanIfConf_CanIfTxPduCfg_RBTM_FL_Tens_ST3_1446be6f_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           2u },  /* [Global PduRDestPdu: RBTM_FL_Tens_ST3_49d8a970_Tx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FL_Tens_ST3_49d8a970_Tx{Left}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    38 */           8u,                                          ComConf_ComIPdu_RBTM_FR_Stat_ST3_e44387fa_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          24u },  /* [Global PduRDestPdu: RBTM_FR_Stat_ST3_e44387fa_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FR_Stat_ST3_e44387fa_Rx{Left}, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    39 */           8u,                                   CanIfConf_CanIfTxPduCfg_ROE_RBTM_FL_ST3_e9956dfc_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          12u },  /* [Global PduRDestPdu: ROE_RBTM_FL_ST3_75ad963a_Tx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ROE_RBTM_FL_ST3_75ad963a_Tx{Left}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    40 */           8u,                                      ComConf_ComIPdu_SBeltTens_SP_Lvl_ST3_46421e11_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          42u },  /* [Global PduRDestPdu: SBeltTens_SP_Lvl_ST3_46421e11_Rx]                    */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SBeltTens_SP_Lvl_ST3_46421e11_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    41 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx_2b322367, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,           8u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    42 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx_d414628a, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,           3u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    43 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx_c0cc433b, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,           9u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    44 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx_2873db84, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,          36u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx{Left}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    45 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_530d12e8, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       2u,          29u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx{Left}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
  { /*    46 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx_5a27dd11, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,          30u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx{Left}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    47 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_690fe637, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       2u,          11u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx{Left}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
  { /*    48 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx_6a163982, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,           0u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx{Left}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    49 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_b61ae5cc, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       2u,          17u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx{Left}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
    /* Index    MaxPduLength  DestHnd                                                                                Direction                      LockRomIdx  MmRomIdx  RmDestRomIdx        Comment                                                                               Referable Keys */
  { /*    50 */           8u,                                           ComConf_ComIPdu_VSS_TP_Auth_ST3_7c9f23ce_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          43u },  /* [Global PduRDestPdu: VSS_TP_Auth_ST3_7c9f23ce_Rx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_Auth_ST3_7c9f23ce_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    51 */           8u,                                   ComConf_ComIPdu_VSS_TP_RealTmOffset_ST3_62955a84_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          32u },  /* [Global PduRDestPdu: VSS_TP_RealTmOffset_ST3_62955a84_Rx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_RealTmOffset_ST3_62955a84_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    52 */           8u,                              ComConf_ComIPdu_VSS_TP_SecTickCount_Lvl2_ST3_4917056b_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,           6u },  /* [Global PduRDestPdu: VSS_TP_SecTickCount_Lvl2_ST3_4917056b_Rx]            */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_SecTickCount_Lvl2_ST3_4917056b_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    53 */           8u,                                   ComConf_ComIPdu_VSS_TP_SharedSecret_ST3_605b0fee_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          19u },  /* [Global PduRDestPdu: VSS_TP_SharedSecret_ST3_605b0fee_Rx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_SharedSecret_ST3_605b0fee_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    54 */           8u,                                            ComConf_ComIPdu_VSS_TP_VIN_ST3_8e87972a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          49u }   /* [Global PduRDestPdu: VSS_TP_VIN_ST3_8e87972a_Rx]                          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_VIN_ST3_8e87972a_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRomRight
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRomRight
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
CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRomRight[55] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    MaxPduLength  DestHnd                                                                                Direction                      LockRomIdx  MmRomIdx  RmDestRomIdx        Comment                                                                               Referable Keys */
  { /*     0 */           8u,                                         ComConf_ComIPdu_ADAS_POSITION_ST3_0b61d436_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          54u },  /* [Global PduRDestPdu: ADAS_POSITION_ST3_0b61d436_Rx]                       */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_POSITION_ST3_0b61d436_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     1 */           8u,                                IpduMConf_IpduMRxIndication_IpduMRxIndication_33e88c66, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       5u,           0u },  /* [Global PduRDestPdu: ADAS_PREDICTION_ST3_549e2a63_Rx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PREDICTION_ST3_549e2a63_Rx, /ActiveEcuC/PduR/IpduM, PduRSinglePartitionDummy] */
  { /*     2 */           8u,                                     ComConf_ComIPdu_ADAS_PREDICTION_ST3_6_262b63d1_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,           9u },  /* [Global PduRDestPdu: ADAS_PREDICTION_ST3_6_262b63d1_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PREDICTION_ST3_6_262b63d1_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     3 */           8u,                                     ComConf_ComIPdu_ADAS_PREDICTION_ST3_7_512c5347_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          44u },  /* [Global PduRDestPdu: ADAS_PREDICTION_ST3_7_512c5347_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PREDICTION_ST3_7_512c5347_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     4 */           8u,                                  ComConf_ComIPdu_ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          46u },  /* [Global PduRDestPdu: ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx]                */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     5 */           8u,                                IpduMConf_IpduMRxIndication_IpduMRxIndication_17ccd7a3, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       5u,          49u },  /* [Global PduRDestPdu: ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx]                  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx, /ActiveEcuC/PduR/IpduM, PduRSinglePartitionDummy] */
  { /*     6 */           8u,                                 ComConf_ComIPdu_ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          34u },  /* [Global PduRDestPdu: ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx]               */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     7 */           4u,                                       ComConf_ComIPdu_Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          22u },  /* [Global PduRDestPdu: Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*     8 */           8u,                   SecOCConf_SecOCRxSecuredPdu_Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       6u,          25u },  /* [Global PduRDestPdu: Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx]             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx, /ActiveEcuC/PduR/SecOc, PduRSinglePartitionDummy] */
  { /*     9 */           1u,                                       ComConf_ComIPdu_BeltAdj_FL_Stat_ST3_d2ce0dbb_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          33u },  /* [Global PduRDestPdu: BeltAdj_FL_Stat_ST3_d2ce0dbb_Rx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltAdj_FL_Stat_ST3_d2ce0dbb_Rx{Right}, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    10 */           1u,                               CanIfConf_CanIfTxPduCfg_BeltAdj_FR_Stat_ST3_070be586_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,           1u },  /* [Global PduRDestPdu: BeltAdj_FR_Stat_ST3_2b5906f9_Tx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltAdj_FR_Stat_ST3_2b5906f9_Tx{Right}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    11 */           1u,                                     ComConf_ComIPdu_BeltAdj_UI_Set_Rq_ST3_1223a83d_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          12u },  /* [Global PduRDestPdu: BeltAdj_UI_Set_Rq_ST3_1223a83d_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltAdj_UI_Set_Rq_ST3_1223a83d_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    12 */           4u,                                    ComConf_ComIPdu_BeltHdOvr_FR_State_ST3_c8a18c7a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          19u },  /* [Global PduRDestPdu: BeltHdOvr_FR_State_ST3_c8a18c7a_Rx]                  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltHdOvr_FR_State_ST3_c8a18c7a_Rx{Right}, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    13 */           8u,                                         ComConf_ComIPdu_CLkS_Dr_State_ST3_513e9c19_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,           3u },  /* [Global PduRDestPdu: CLkS_Dr_State_ST3_513e9c19_Rx]                       */  /* [/ActiveEcuC/EcuC/EcucPduCollection/CLkS_Dr_State_ST3_513e9c19_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    14 */           4u,                                             ComConf_ComIPdu_DIAG_Stat_ST3_3a031d4a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          21u },  /* [Global PduRDestPdu: DIAG_Stat_ST3_3a031d4a_Rx]                           */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DIAG_Stat_ST3_3a031d4a_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    15 */           8u,                                     ComConf_ComIPdu_DI_OdoSpeedometer_ST3_6fef7507_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          14u },  /* [Global PduRDestPdu: DI_OdoSpeedometer_ST3_6fef7507_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DI_OdoSpeedometer_ST3_6fef7507_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    16 */           1u,                                      ComConf_ComIPdu_DPC_Md_Rq_ESP_d1_ST3_e30f951d_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          50u },  /* [Global PduRDestPdu: DPC_Md_Rq_ESP_d1_ST3_e30f951d_Rx]                    */  /* [/ActiveEcuC/EcuC/EcucPduCollection/DPC_Md_Rq_ESP_d1_ST3_e30f951d_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    17 */           8u,                                   ComConf_ComIPdu_Develop8_Rq_RBTM_FR_ST3_25b7d179_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          23u },  /* [Global PduRDestPdu: Develop8_Rq_RBTM_FR_ST3_25b7d179_Rx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Develop8_Rq_RBTM_FR_ST3_25b7d179_Rx{Right}, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    18 */           8u,                           CanIfConf_CanIfTxPduCfg_Develop8_Rs_RBTM_FR_ST3_1a924f62_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          32u },  /* [Global PduRDestPdu: Develop8_Rs_RBTM_FR_ST3_aaf2c54f_Tx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Develop8_Rs_RBTM_FR_ST3_aaf2c54f_Tx{Right}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    19 */           8u,                              CanIfConf_CanIfTxPduCfg_ECU_Stat_RBTM_FR_ST3_430ba797_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          11u },  /* [Global PduRDestPdu: ECU_Stat_RBTM_FR_ST3_9988b431_Tx]                    */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ECU_Stat_RBTM_FR_ST3_9988b431_Tx{Right}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    20 */           4u,                                          ComConf_ComIPdu_ELC_Lvr_Stat_ST3_d97bab99_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          39u },  /* [Global PduRDestPdu: ELC_Lvr_Stat_ST3_d97bab99_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_d97bab99_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    21 */           8u,                      SecOCConf_SecOCRxSecuredPdu_ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       6u,          45u },  /* [Global PduRDestPdu: ELC_Lvr_Stat_ST3_secured_7bad7996_Rx]                */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ELC_Lvr_Stat_ST3_secured_7bad7996_Rx, /ActiveEcuC/PduR/SecOc, PduRSinglePartitionDummy] */
  { /*    22 */           8u,                                 ComConf_ComIPdu_EVC_CfgList_01_08_Pr5_ST3_32c5e6fb_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          18u },  /* [Global PduRDestPdu: EVC_CfgList_01_08_Pr5_ST3_32c5e6fb_Rx]               */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EVC_CfgList_01_08_Pr5_ST3_32c5e6fb_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    23 */           4u,                                              ComConf_ComIPdu_Ign_Stat_ST3_1e3dc39f_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          43u },  /* [Global PduRDestPdu: Ign_Stat_ST3_1e3dc39f_Rx]                            */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_1e3dc39f_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    24 */           8u,                          SecOCConf_SecOCRxSecuredPdu_Ign_Stat_ST3_secured_87afaf29_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       6u,          52u },  /* [Global PduRDestPdu: Ign_Stat_ST3_secured_87afaf29_Rx]                    */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Ign_Stat_ST3_secured_87afaf29_Rx, /ActiveEcuC/PduR/SecOc, PduRSinglePartitionDummy] */
  { /*    25 */           4u,                                               ComConf_ComIPdu_Impact2_ST3_e5526ccc_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,           8u },  /* [Global PduRDestPdu: Impact2_ST3_e5526ccc_Rx]                             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Impact2_ST3_e5526ccc_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    26 */           4u,                                               ComConf_ComIPdu_Impact3_ST3_d832457c_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          24u },  /* [Global PduRDestPdu: Impact3_ST3_d832457c_Rx]                             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Impact3_ST3_d832457c_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    27 */           8u,                                 CanIfConf_CanIfTxPduCfg_Meas8_RBTM_FR_ST3_492d97af_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          48u },  /* [Global PduRDestPdu: Meas8_RBTM_FR_ST3_6f1e0041_Tx]                       */  /* [/ActiveEcuC/EcuC/EcucPduCollection/Meas8_RBTM_FR_ST3_6f1e0041_Tx{Right}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    28 */           7u,                                  CanNmConf_CanNmUserDataTxPdu_NM_RBTM_FR_ST3_f94fffa8, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       1u,          10u },  /* [Global PduRDestPdu: NM_RBTM_FR_ST3_d30f04ec_Tx]                          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/NM_RBTM_FR_ST3_d30f04ec_Tx{Right}, /ActiveEcuC/PduR/CanNm, PduRSinglePartitionDummy] */
  { /*    29 */           2u,                                       ComConf_ComIPdu_NTG_Master_Navi_ST3_dea580a6_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          28u },  /* [Global PduRDestPdu: NTG_Master_Navi_ST3_dea580a6_Rx]                     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/NTG_Master_Navi_ST3_dea580a6_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    30 */           8u,                                     ComConf_ComIPdu_PN14_Master_Stat1_ST3_eba3e383_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          36u },  /* [Global PduRDestPdu: PN14_Master_Stat1_ST3_eba3e383_Rx]                   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PN14_Master_Stat1_ST3_eba3e383_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    31 */           4u,                                           ComConf_ComIPdu_PT4_PTCoor4_ST3_bf069154_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          37u },  /* [Global PduRDestPdu: PT4_PTCoor4_ST3_bf069154_Rx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT4_PTCoor4_ST3_bf069154_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    32 */           1u,                                   ComConf_ComIPdu_PT4_PTCoor9_d1_BC_F_ST3_da786b84_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          17u },  /* [Global PduRDestPdu: PT4_PTCoor9_d1_BC_F_ST3_da786b84_Rx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT4_PTCoor9_d1_BC_F_ST3_da786b84_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    33 */           8u,                               ComConf_ComIPdu_PT4_PTCoor_DrvPosn_Gear_ST3_6b508375_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          13u },  /* [Global PduRDestPdu: PT4_PTCoor_DrvPosn_Gear_ST3_6b508375_Rx]             */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT4_PTCoor_DrvPosn_Gear_ST3_6b508375_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    34 */           7u,                                                ComConf_ComIPdu_ComIPduPnc_EIRA_CAN_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          40u },  /* [Global PduRDestPdu: PduPnc_EIRA_CAN_Rx]                                  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PduPnc_EIRA_CAN_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    35 */           8u,                                          ComConf_ComIPdu_PresfAct_Adj_ST3_61c58c91_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          27u },  /* [Global PduRDestPdu: PresfAct_Adj_ST3_61c58c91_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PresfAct_Adj_ST3_61c58c91_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    36 */           8u,                                          ComConf_ComIPdu_RBTM_FL_Stat_ST3_dd2436a1_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,           5u },  /* [Global PduRDestPdu: RBTM_FL_Stat_ST3_dd2436a1_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FL_Stat_ST3_dd2436a1_Rx{Right}, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    37 */           8u,                                  CanIfConf_CanIfTxPduCfg_RBTM_FR_Stat_ST3_b20121fa_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          16u },  /* [Global PduRDestPdu: RBTM_FR_Stat_ST3_8dd11b6c_Tx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FR_Stat_ST3_8dd11b6c_Tx{Right}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    38 */           8u,                                  CanIfConf_CanIfTxPduCfg_RBTM_FR_Tens_ST3_019feca0_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          38u },  /* [Global PduRDestPdu: RBTM_FR_Tens_ST3_1364a6b3_Tx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FR_Tens_ST3_1364a6b3_Tx{Right}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    39 */           8u,                                   CanIfConf_CanIfTxPduCfg_ROE_RBTM_FR_ST3_d7dfdf54_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       0u,          51u },  /* [Global PduRDestPdu: ROE_RBTM_FR_ST3_ae40752b_Tx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/ROE_RBTM_FR_ST3_ae40752b_Tx{Right}, /ActiveEcuC/PduR/CanIf, PduRSinglePartitionDummy] */
  { /*    40 */           8u,                                      ComConf_ComIPdu_SBeltTens_SP_Lvl_ST3_46421e11_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          41u },  /* [Global PduRDestPdu: SBeltTens_SP_Lvl_ST3_46421e11_Rx]                    */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SBeltTens_SP_Lvl_ST3_46421e11_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    41 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx_2b322367, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,           6u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    42 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx_d414628a, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,           2u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    43 */           7u,     DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx_c0cc433b, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,           7u },  /* [Global PduRDestPdu: SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    44 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx_3b6533a8, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,          26u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx{Right}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    45 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_036251db, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       2u,          30u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx{Right}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
  { /*    46 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx_510ebea9, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,          20u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx{Right}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    47 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_b14888e8, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       2u,          35u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx{Right}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
  { /*    48 */        4095u, DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx_536fd8c4, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       4u,          29u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx{Right}, /ActiveEcuC/PduR/Dcm, PduRSinglePartitionDummy] */
  { /*    49 */        4095u,                                            CanTpConf_CanTpTxNSdu_CanTpTxNSdu_6f7c1760, PDUR_TX_DIRECTIONOFRMGDESTROM,         0u,       2u,          53u },  /* [Global PduRDestPdu: SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx{Right}, /ActiveEcuC/PduR/CanTp, PduRSinglePartitionDummy] */
    /* Index    MaxPduLength  DestHnd                                                                                Direction                      LockRomIdx  MmRomIdx  RmDestRomIdx        Comment                                                                               Referable Keys */
  { /*    50 */           8u,                                           ComConf_ComIPdu_VSS_TP_Auth_ST3_7c9f23ce_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          42u },  /* [Global PduRDestPdu: VSS_TP_Auth_ST3_7c9f23ce_Rx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_Auth_ST3_7c9f23ce_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    51 */           8u,                                   ComConf_ComIPdu_VSS_TP_RealTmOffset_ST3_62955a84_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          31u },  /* [Global PduRDestPdu: VSS_TP_RealTmOffset_ST3_62955a84_Rx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_RealTmOffset_ST3_62955a84_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    52 */           8u,                              ComConf_ComIPdu_VSS_TP_SecTickCount_Lvl2_ST3_4917056b_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,           4u },  /* [Global PduRDestPdu: VSS_TP_SecTickCount_Lvl2_ST3_4917056b_Rx]            */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_SecTickCount_Lvl2_ST3_4917056b_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    53 */           8u,                                   ComConf_ComIPdu_VSS_TP_SharedSecret_ST3_605b0fee_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          15u },  /* [Global PduRDestPdu: VSS_TP_SharedSecret_ST3_605b0fee_Rx]                 */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_SharedSecret_ST3_605b0fee_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
  { /*    54 */           8u,                                            ComConf_ComIPdu_VSS_TP_VIN_ST3_8e87972a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,         0u,       3u,          47u }   /* [Global PduRDestPdu: VSS_TP_VIN_ST3_8e87972a_Rx]                          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VSS_TP_VIN_ST3_8e87972a_Rx, /ActiveEcuC/PduR/Com, PduRSinglePartitionDummy] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRomLeft
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRomLeft
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  LockRomIdx           the index of the 1:1 relation pointing to PduR_LockRom
  MaskedBits           contains bitcoded the boolean data of PduR_TriggerTransmitSupportedOfRmSrcRom, PduR_TxConfirmationSupportedOfRmSrcRom
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRomLeft[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    LockRomIdx  MaskedBits  MmRomIdx  RmDestRomStartIdx  SrcHnd                                                                                       Comment                                       Referable Keys */
  { /*     0 */         0u,      0x00u,       0u,               54u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_fa09a036] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_POSITION_ST3_1ca04d74_Rx/PduRSrcPdu_fa09a036] */
  { /*     1 */         0u,      0x00u,       0u,                1u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_0518217c] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_1de136c9_Rx/PduRSrcPdu_0518217c] */
  { /*     2 */         0u,      0x00u,       5u,               13u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_27f93d01] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_6_262b63d1_Rx/PduRSrcPdu_27f93d01] */
  { /*     3 */         0u,      0x00u,       5u,               45u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_d1b2606a] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_7_512c5347_Rx/PduRSrcPdu_d1b2606a] */
  { /*     4 */         0u,      0x00u,       5u,               47u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_d645a86c] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx/PduRSrcPdu_d645a86c] */
  { /*     5 */         0u,      0x00u,       5u,               34u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_9e880434] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx/PduRSrcPdu_9e880434] */
  { /*     6 */         0u,      0x00u,       0u,               50u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_e0198081] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_894b8265_Rx/PduRSrcPdu_e0198081] */
  { /*     7 */         0u,      0x00u,       6u,               23u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_6e617592] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx/PduRSrcPdu_6e617592] */
  { /*     8 */         0u,      0x00u,       0u,               27u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_79ab8c0b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx/PduRSrcPdu_79ab8c0b] */
  { /*     9 */         0u,      0x00u,       0u,               14u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_350798fb] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_UI_Set_Rq_ST3_7be22993_Rx/PduRSrcPdu_350798fb] */
  { /*    10 */         0u,      0x00u,       0u,                4u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_0fa9281f] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CLkS_Dr_State_ST3_74337ed5_Rx/PduRSrcPdu_0fa9281f] */
  { /*    11 */         0u,      0x00u,       1u,               40u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_bb7efc37] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx/PduRSrcPdu_bb7efc37] */
  { /*    12 */         0u,      0x00u,       0u,               22u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_65d40bec] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DIAG_Stat_ST3_d3ec8369_Rx/PduRSrcPdu_65d40bec] */
  { /*    13 */         0u,      0x00u,       0u,               16u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_3e9512b9] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DI_OdoSpeedometer_ST3_0665a232_Rx/PduRSrcPdu_3e9512b9] */
  { /*    14 */         0u,      0x00u,       0u,               51u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_ee8d9c90] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx/PduRSrcPdu_ee8d9c90] */
  { /*    15 */         0u,      0x00u,       6u,               38u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_ae29c120] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_d97bab99_Rx/PduRSrcPdu_ae29c120] */
  { /*    16 */         0u,      0x00u,       0u,               46u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_d27a099a] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_secured_29d2456c_Rx/PduRSrcPdu_d27a099a] */
  { /*    17 */         0u,      0x00u,       0u,               21u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4b27d50a] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx/PduRSrcPdu_4b27d50a] */
  { /*    18 */         0u,      0x00u,       6u,               44u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_c9c2269b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_1e3dc39f_Rx/PduRSrcPdu_c9c2269b] */
  { /*    19 */         0u,      0x00u,       0u,               53u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_f57d7485] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_secured_fb0d4f19_Rx/PduRSrcPdu_f57d7485] */
  { /*    20 */         0u,      0x00u,       0u,               10u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_22492bdd] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact2_ST3_e5526ccc_Rx/PduRSrcPdu_22492bdd] */
  { /*    21 */         0u,      0x00u,       0u,               25u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_7842cc32] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact3_ST3_993f4b56_Rx/PduRSrcPdu_7842cc32] */
  { /*    22 */         0u,      0x00u,       0u,               31u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_8a45ba67] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NTG_Master_Navi_ST3_1032e485_Rx/PduRSrcPdu_8a45ba67] */
  { /*    23 */         0u,      0x00u,       0u,               35u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_a0c57bb3] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PN14_Master_Stat1_ST3_69644078_Rx/PduRSrcPdu_a0c57bb3] */
  { /*    24 */         0u,      0x00u,       0u,               37u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_a7894e67] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor4_ST3_868ca7d3_Rx/PduRSrcPdu_a7894e67] */
  { /*    25 */         0u,      0x00u,       0u,               20u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_470e8c8b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx/PduRSrcPdu_470e8c8b] */
  { /*    26 */         0u,      0x00u,       0u,               15u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_3ba6bace] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx/PduRSrcPdu_3ba6bace] */
  { /*    27 */         0u,      0x00u,       0u,               28u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_7d3a747f] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PresfAct_Adj_ST3_81976f17_Rx/PduRSrcPdu_7d3a747f] */
  { /*    28 */         0u,      0x00u,       0u,               42u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_c609bb6e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SBeltTens_SP_Lvl_ST3_73b20851_Rx/PduRSrcPdu_c609bb6e] */
  { /*    29 */         0u,      0x00u,       0u,               43u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_c76c8221] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_Auth_ST3_29a0d419_Rx/PduRSrcPdu_c76c8221] */
  { /*    30 */         0u,      0x00u,       0u,               32u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_9136979d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_RealTmOffset_ST3_d6d134b3_Rx/PduRSrcPdu_9136979d] */
  { /*    31 */         0u,      0x00u,       0u,                6u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_13123c17] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx/PduRSrcPdu_13123c17] */
  { /*    32 */         0u,      0x00u,       0u,               19u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_44cfb2dc] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SharedSecret_ST3_6d7ca724_Rx/PduRSrcPdu_44cfb2dc] */
  { /*    33 */         0u,      0x00u,       0u,               49u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_da8efc5d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_VIN_ST3_f7ab6516_Rx/PduRSrcPdu_da8efc5d] */
  { /*    34 */         0u,      0x00u,       0u,               52u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_f252e81e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FR_Stat_ST3_2b5906f9_Rx/PduRSrcPdu_f252e81e{Left}] */
  { /*    35 */         0u,      0x00u,       0u,                5u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_11170208] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltHdOvr_FL_State_ST3_0b4fb3a9_Rx/PduRSrcPdu_11170208{Left}] */
  { /*    36 */         0u,      0x00u,       0u,               41u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_c2dcef25] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rq_RBTM_FL_ST3_0a7cffe6_Rx/PduRSrcPdu_c2dcef25{Left}] */
  { /*    37 */         0u,      0x00u,       0u,               24u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_7234ddac] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Stat_ST3_8dd11b6c_Rx/PduRSrcPdu_7234ddac{Left}] */
  { /*    38 */         0u,      0x00u,       2u,                8u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_19a79fac] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/PduRSrcPdu_19a79fac] */
  { /*    39 */         0u,      0x00u,       2u,                3u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_0e266b08] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/PduRSrcPdu_0e266b08] */
  { /*    40 */         0u,      0x00u,       2u,                9u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_1a629478] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/PduRSrcPdu_1a629478] */
  { /*    41 */         0u,      0x00u,       2u,               36u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_a44b5ded] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx/PduRSrcPdu_a44b5ded{Left}] */
  { /*    42 */         0u,      0x00u,       2u,               30u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_80d1f2da] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx/PduRSrcPdu_80d1f2da{Left}] */
  { /*    43 */         0u,      0x00u,       2u,                0u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_03bff274] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx/PduRSrcPdu_03bff274{Left}] */
  { /*    44 */         0u,      0x01u,       3u,               18u,                                       ComConf_ComIPdu_BeltAdj_FL_Stat_ST3_d2ce0dbb_Tx },  /* [PduRSrcPdu: PduRSrcPdu_4459b19c] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FL_Stat_ST3_d2ce0dbb_Tx/PduRSrcPdu_4459b19c{Left}] */
  { /*    45 */         0u,      0x01u,       3u,               39u,                                   ComConf_ComIPdu_Develop8_Rs_RBTM_FL_ST3_9a3b4dd1_Tx },  /* [PduRSrcPdu: PduRSrcPdu_b7de4975] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rs_RBTM_FL_ST3_9a3b4dd1_Tx/PduRSrcPdu_b7de4975{Left}] */
  { /*    46 */         0u,      0x01u,       3u,                7u,                                      ComConf_ComIPdu_ECU_Stat_RBTM_FL_ST3_f703b6eb_Tx },  /* [PduRSrcPdu: PduRSrcPdu_140ec449] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ECU_Stat_RBTM_FL_ST3_f703b6eb_Tx/PduRSrcPdu_140ec449{Left}] */
  { /*    47 */         0u,      0x01u,       3u,               48u,                                         ComConf_ComIPdu_Meas8_RBTM_FL_ST3_a92f14da_Tx },  /* [PduRSrcPdu: PduRSrcPdu_d98cd95c] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meas8_RBTM_FL_ST3_a92f14da_Tx/PduRSrcPdu_d98cd95c{Left}] */
  { /*    48 */         0u,      0x03u,       3u,               26u,                                            ComConf_ComIPdu_NM_RBTM_FL_ST3_0cdf2d0f_Tx },  /* [PduRSrcPdu: PduRSrcPdu_78db9cf2] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NM_RBTM_FL_ST3_0cdf2d0f_Tx/PduRSrcPdu_78db9cf2{Left}] */
  { /*    49 */         0u,      0x01u,       3u,               33u,                                          ComConf_ComIPdu_RBTM_FL_Stat_ST3_dd2436a1_Tx },  /* [PduRSrcPdu: PduRSrcPdu_9690baaa] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Stat_ST3_dd2436a1_Tx/PduRSrcPdu_9690baaa{Left}] */
    /* Index    LockRomIdx  MaskedBits  MmRomIdx  RmDestRomStartIdx  SrcHnd                                                                                       Comment                                       Referable Keys */
  { /*    50 */         0u,      0x01u,       3u,                2u,                                          ComConf_ComIPdu_RBTM_FL_Tens_ST3_553ec607_Tx },  /* [PduRSrcPdu: PduRSrcPdu_074527d1] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Tens_ST3_553ec607_Tx/PduRSrcPdu_074527d1{Left}] */
  { /*    51 */         0u,      0x01u,       3u,               12u,                                           ComConf_ComIPdu_ROE_RBTM_FL_ST3_a66ccb5f_Tx },  /* [PduRSrcPdu: PduRSrcPdu_25bb0169] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ROE_RBTM_FL_ST3_a66ccb5f_Tx/PduRSrcPdu_25bb0169{Left}] */
  { /*    52 */         0u,      0x00u,       4u,               29u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx_70f6d2b0 },  /* [PduRSrcPdu: PduRSrcPdu_7f35c914] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx/PduRSrcPdu_7f35c914{Left}] */
  { /*    53 */         0u,      0x00u,       4u,               11u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx_2b590afc },  /* [PduRSrcPdu: PduRSrcPdu_249a1158] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx/PduRSrcPdu_249a1158{Left}] */
  { /*    54 */         0u,      0x00u,       4u,               17u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx_3060e687 }   /* [PduRSrcPdu: PduRSrcPdu_3fa3fd23] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx/PduRSrcPdu_3fa3fd23{Left}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRomRight
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRomRight
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  LockRomIdx           the index of the 1:1 relation pointing to PduR_LockRom
  MaskedBits           contains bitcoded the boolean data of PduR_TriggerTransmitSupportedOfRmSrcRom, PduR_TxConfirmationSupportedOfRmSrcRom
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRomRight[55] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    LockRomIdx  MaskedBits  MmRomIdx  RmDestRomStartIdx  SrcHnd                                                                                       Comment                                       Referable Keys */
  { /*     0 */         0u,      0x00u,       0u,               54u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_fa09a036] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_POSITION_ST3_1ca04d74_Rx/PduRSrcPdu_fa09a036] */
  { /*     1 */         0u,      0x00u,       0u,                0u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_0518217c] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_1de136c9_Rx/PduRSrcPdu_0518217c] */
  { /*     2 */         0u,      0x00u,       5u,                9u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_27f93d01] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_6_262b63d1_Rx/PduRSrcPdu_27f93d01] */
  { /*     3 */         0u,      0x00u,       5u,               44u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_d1b2606a] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PREDICTION_ST3_7_512c5347_Rx/PduRSrcPdu_d1b2606a] */
  { /*     4 */         0u,      0x00u,       5u,               46u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_d645a86c] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx/PduRSrcPdu_d645a86c] */
  { /*     5 */         0u,      0x00u,       5u,               34u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_9e880434] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx/PduRSrcPdu_9e880434] */
  { /*     6 */         0u,      0x00u,       0u,               49u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_e0198081] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ADAS_PROFILE_SHORT_ST3_894b8265_Rx/PduRSrcPdu_e0198081] */
  { /*     7 */         0u,      0x00u,       6u,               22u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_6e617592] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx/PduRSrcPdu_6e617592] */
  { /*     8 */         0u,      0x00u,       0u,               25u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_79ab8c0b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx/PduRSrcPdu_79ab8c0b] */
  { /*     9 */         0u,      0x00u,       0u,               12u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_350798fb] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_UI_Set_Rq_ST3_7be22993_Rx/PduRSrcPdu_350798fb] */
  { /*    10 */         0u,      0x00u,       0u,                3u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_0fa9281f] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/CLkS_Dr_State_ST3_74337ed5_Rx/PduRSrcPdu_0fa9281f] */
  { /*    11 */         0u,      0x00u,       1u,               40u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_bb7efc37] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx/PduRSrcPdu_bb7efc37] */
  { /*    12 */         0u,      0x00u,       0u,               21u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_65d40bec] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DIAG_Stat_ST3_d3ec8369_Rx/PduRSrcPdu_65d40bec] */
  { /*    13 */         0u,      0x00u,       0u,               14u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_3e9512b9] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DI_OdoSpeedometer_ST3_0665a232_Rx/PduRSrcPdu_3e9512b9] */
  { /*    14 */         0u,      0x00u,       0u,               50u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_ee8d9c90] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx/PduRSrcPdu_ee8d9c90] */
  { /*    15 */         0u,      0x00u,       6u,               39u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_ae29c120] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_d97bab99_Rx/PduRSrcPdu_ae29c120] */
  { /*    16 */         0u,      0x00u,       0u,               45u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_d27a099a] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ELC_Lvr_Stat_ST3_secured_29d2456c_Rx/PduRSrcPdu_d27a099a] */
  { /*    17 */         0u,      0x00u,       0u,               18u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4b27d50a] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx/PduRSrcPdu_4b27d50a] */
  { /*    18 */         0u,      0x00u,       6u,               43u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_c9c2269b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_1e3dc39f_Rx/PduRSrcPdu_c9c2269b] */
  { /*    19 */         0u,      0x00u,       0u,               52u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_f57d7485] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Ign_Stat_ST3_secured_fb0d4f19_Rx/PduRSrcPdu_f57d7485] */
  { /*    20 */         0u,      0x00u,       0u,                8u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_22492bdd] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact2_ST3_e5526ccc_Rx/PduRSrcPdu_22492bdd] */
  { /*    21 */         0u,      0x00u,       0u,               24u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_7842cc32] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Impact3_ST3_993f4b56_Rx/PduRSrcPdu_7842cc32] */
  { /*    22 */         0u,      0x00u,       0u,               28u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_8a45ba67] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NTG_Master_Navi_ST3_1032e485_Rx/PduRSrcPdu_8a45ba67] */
  { /*    23 */         0u,      0x00u,       0u,               36u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_a0c57bb3] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PN14_Master_Stat1_ST3_69644078_Rx/PduRSrcPdu_a0c57bb3] */
  { /*    24 */         0u,      0x00u,       0u,               37u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_a7894e67] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor4_ST3_868ca7d3_Rx/PduRSrcPdu_a7894e67] */
  { /*    25 */         0u,      0x00u,       0u,               17u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_470e8c8b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx/PduRSrcPdu_470e8c8b] */
  { /*    26 */         0u,      0x00u,       0u,               13u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_3ba6bace] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx/PduRSrcPdu_3ba6bace] */
  { /*    27 */         0u,      0x00u,       0u,               27u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_7d3a747f] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/PresfAct_Adj_ST3_81976f17_Rx/PduRSrcPdu_7d3a747f] */
  { /*    28 */         0u,      0x00u,       0u,               41u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_c609bb6e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SBeltTens_SP_Lvl_ST3_73b20851_Rx/PduRSrcPdu_c609bb6e] */
  { /*    29 */         0u,      0x00u,       0u,               42u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_c76c8221] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_Auth_ST3_29a0d419_Rx/PduRSrcPdu_c76c8221] */
  { /*    30 */         0u,      0x00u,       0u,               31u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_9136979d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_RealTmOffset_ST3_d6d134b3_Rx/PduRSrcPdu_9136979d] */
  { /*    31 */         0u,      0x00u,       0u,                4u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_13123c17] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx/PduRSrcPdu_13123c17] */
  { /*    32 */         0u,      0x00u,       0u,               15u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_44cfb2dc] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_SharedSecret_ST3_6d7ca724_Rx/PduRSrcPdu_44cfb2dc] */
  { /*    33 */         0u,      0x00u,       0u,               47u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_da8efc5d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VSS_TP_VIN_ST3_f7ab6516_Rx/PduRSrcPdu_da8efc5d] */
  { /*    34 */         0u,      0x00u,       0u,               33u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_9982cecc] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FL_Stat_ST3_71e5093a_Rx/PduRSrcPdu_9982cecc{Right}] */
  { /*    35 */         0u,      0x00u,       0u,               19u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4c2f4fea] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltHdOvr_FR_State_ST3_09789cac_Rx/PduRSrcPdu_4c2f4fea{Right}] */
  { /*    36 */         0u,      0x00u,       0u,               23u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_73b8d236] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rq_RBTM_FR_ST3_d1911cf7_Rx/PduRSrcPdu_73b8d236{Right}] */
  { /*    37 */         0u,      0x00u,       0u,                5u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_16ae0594] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Stat_ST3_d76d14af_Rx/PduRSrcPdu_16ae0594{Right}] */
  { /*    38 */         0u,      0x00u,       2u,                6u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_19a79fac] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx/PduRSrcPdu_19a79fac] */
  { /*    39 */         0u,      0x00u,       2u,                2u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_0e266b08] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx/PduRSrcPdu_0e266b08] */
  { /*    40 */         0u,      0x00u,       2u,                7u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_1a629478] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx/PduRSrcPdu_1a629478] */
  { /*    41 */         0u,      0x00u,       2u,               26u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_7beeea72] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx/PduRSrcPdu_7beeea72{Right}] */
  { /*    42 */         0u,      0x00u,       2u,               20u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4d07a2cf] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx/PduRSrcPdu_4d07a2cf{Right}] */
  { /*    43 */         0u,      0x00u,       2u,               29u,                                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_8aa11052] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx/PduRSrcPdu_8aa11052{Right}] */
  { /*    44 */         0u,      0x01u,       3u,                1u,                                       ComConf_ComIPdu_BeltAdj_FR_Stat_ST3_eba9bce0_Tx },  /* [PduRSrcPdu: PduRSrcPdu_0892c3c5] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FR_Stat_ST3_eba9bce0_Tx/PduRSrcPdu_0892c3c5{Right}] */
  { /*    45 */         0u,      0x01u,       3u,               32u,                                   ComConf_ComIPdu_Develop8_Rs_RBTM_FR_ST3_45eb6432_Tx },  /* [PduRSrcPdu: PduRSrcPdu_981fdebc] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rs_RBTM_FR_ST3_45eb6432_Tx/PduRSrcPdu_981fdebc{Right}] */
  { /*    46 */         0u,      0x01u,       3u,               11u,                                      ComConf_ComIPdu_ECU_Stat_RBTM_FR_ST3_28d39f08_Tx },  /* [PduRSrcPdu: PduRSrcPdu_2db65a34] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ECU_Stat_RBTM_FR_ST3_28d39f08_Tx/PduRSrcPdu_2db65a34{Right}] */
  { /*    47 */         0u,      0x01u,       3u,               48u,                                         ComConf_ComIPdu_Meas8_RBTM_FR_ST3_76ff3d39_Tx },  /* [PduRSrcPdu: PduRSrcPdu_dedcc96f] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meas8_RBTM_FR_ST3_76ff3d39_Tx/PduRSrcPdu_dedcc96f{Right}] */
  { /*    48 */         0u,      0x03u,       3u,               10u,                                            ComConf_ComIPdu_NM_RBTM_FR_ST3_d30f04ec_Tx },  /* [PduRSrcPdu: PduRSrcPdu_2c5f6cda] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NM_RBTM_FR_ST3_d30f04ec_Tx/PduRSrcPdu_2c5f6cda{Right}] */
  { /*    49 */         0u,      0x01u,       3u,               16u,                                          ComConf_ComIPdu_RBTM_FR_Stat_ST3_e44387fa_Tx },  /* [PduRSrcPdu: PduRSrcPdu_45e6f19d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Stat_ST3_e44387fa_Tx/PduRSrcPdu_45e6f19d{Right}] */
    /* Index    LockRomIdx  MaskedBits  MmRomIdx  RmDestRomStartIdx  SrcHnd                                                                                       Comment                                       Referable Keys */
  { /*    50 */         0u,      0x01u,       3u,               38u,                                          ComConf_ComIPdu_RBTM_FR_Tens_ST3_6c59775c_Tx },  /* [PduRSrcPdu: PduRSrcPdu_a9321799] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FR_Tens_ST3_6c59775c_Tx/PduRSrcPdu_a9321799{Right}] */
  { /*    51 */         0u,      0x01u,       3u,               51u,                                           ComConf_ComIPdu_ROE_RBTM_FR_ST3_79bce2bc_Tx },  /* [PduRSrcPdu: PduRSrcPdu_efc3e236] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ROE_RBTM_FR_ST3_79bce2bc_Tx/PduRSrcPdu_efc3e236{Right}] */
  { /*    52 */         0u,      0x00u,       4u,               30u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx_82eb6958 },  /* [PduRSrcPdu: PduRSrcPdu_8d2872fc] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx/PduRSrcPdu_8d2872fc{Right}] */
  { /*    53 */         0u,      0x00u,       4u,               35u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx_afb57ffd },  /* [PduRSrcPdu: PduRSrcPdu_a0766459] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx/PduRSrcPdu_a0766459{Right}] */
  { /*    54 */         0u,      0x00u,       4u,               53u, DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx_f8a04d74 }   /* [PduRSrcPdu: PduRSrcPdu_f76356d0] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx/PduRSrcPdu_f76356d0{Right}] */
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
CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RmTransmitFctPtr                  Referable Keys */
  /*     0 */ PduR_RmIf_RoutePdu           ,  /* [PduR_RmIf_RoutePdu] */
  /*     1 */ PduR_RmTp_Transmit_MultiDest    /* [PduR_RmTp_Transmit_MultiDest] */
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
  CancelTransmitUsed     TRUE if the routing can use the CancelTransmit API
  RmSrcRomIdx            the index of the 0:1 relation pointing to PduR_RmSrcRom
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CancelTransmitUsed  RmSrcRomIdx  RmTransmitFctPtrIdx        Referable Keys */
  { /*     0 */               TRUE,         44u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BeltAdj_FL_Stat_ST3_d2ce0dbb_Tx/PduRSrcPdu_4459b19c{Left}] */
  { /*     1 */               TRUE,         45u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Develop8_Rs_RBTM_FL_ST3_9a3b4dd1_Tx/PduRSrcPdu_b7de4975{Left}] */
  { /*     2 */               TRUE,         46u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ECU_Stat_RBTM_FL_ST3_f703b6eb_Tx/PduRSrcPdu_140ec449{Left}] */
  { /*     3 */               TRUE,         47u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Meas8_RBTM_FL_ST3_a92f14da_Tx/PduRSrcPdu_d98cd95c{Left}] */
  { /*     4 */               TRUE,         48u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/NM_RBTM_FL_ST3_0cdf2d0f_Tx/PduRSrcPdu_78db9cf2{Left}] */
  { /*     5 */               TRUE,         49u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Stat_ST3_dd2436a1_Tx/PduRSrcPdu_9690baaa{Left}] */
  { /*     6 */               TRUE,         50u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/RBTM_FL_Tens_ST3_553ec607_Tx/PduRSrcPdu_074527d1{Left}] */
  { /*     7 */               TRUE,         51u,                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/ROE_RBTM_FL_ST3_a66ccb5f_Tx/PduRSrcPdu_25bb0169{Left}] */
  { /*     8 */               TRUE,         52u,                  1u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx/PduRSrcPdu_7f35c914{Left}] */
  { /*     9 */               TRUE,         53u,                  1u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx/PduRSrcPdu_249a1158{Left}] */
  { /*    10 */               TRUE,         54u,                  1u }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx/PduRSrcPdu_3fa3fd23{Left}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2UpLeft
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2UpLeft
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element               Description
  TxConfirmationUsed    True, if any of the source PduRDestPdus uses a TxConfirmation.
  RmGDestRomIdx         the index of the 1:1 relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2UpLeft[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxConfirmationUsed  RmGDestRomIdx        Referable Keys */
  { /*     0 */               TRUE,            9u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltAdj_FL_Stat_ST3_71e5093a_Tx{Left}] */
  { /*     1 */               TRUE,           18u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Develop8_Rs_RBTM_FL_ST3_711f265e_Tx{Left}] */
  { /*     2 */               TRUE,           19u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/ECU_Stat_RBTM_FL_ST3_42655720_Tx{Left}] */
  { /*     3 */               TRUE,           27u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Meas8_RBTM_FL_ST3_b4f3e350_Tx{Left}] */
  { /*     4 */               TRUE,           28u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/NM_RBTM_FL_ST3_0cdf2d0f_Tx{Left}] */
  { /*     5 */               TRUE,           36u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FL_Stat_ST3_d76d14af_Tx{Left}] */
  { /*     6 */               TRUE,           37u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FL_Tens_ST3_49d8a970_Tx{Left}] */
  { /*     7 */               TRUE,           39u }   /* [/ActiveEcuC/EcuC/EcucPduCollection/ROE_RBTM_FL_ST3_75ad963a_Tx{Left}] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2UpRight
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2UpRight
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element               Description
  TxConfirmationUsed    True, if any of the source PduRDestPdus uses a TxConfirmation.
  RmGDestRomIdx         the index of the 1:1 relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2UpRight[8] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    TxConfirmationUsed  RmGDestRomIdx        Referable Keys */
  { /*     0 */               TRUE,           10u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/BeltAdj_FR_Stat_ST3_2b5906f9_Tx{Right}] */
  { /*     1 */               TRUE,           18u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Develop8_Rs_RBTM_FR_ST3_aaf2c54f_Tx{Right}] */
  { /*     2 */               TRUE,           19u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/ECU_Stat_RBTM_FR_ST3_9988b431_Tx{Right}] */
  { /*     3 */               TRUE,           27u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/Meas8_RBTM_FR_ST3_6f1e0041_Tx{Right}] */
  { /*     4 */               TRUE,           28u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/NM_RBTM_FR_ST3_d30f04ec_Tx{Right}] */
  { /*     5 */               TRUE,           37u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FR_Stat_ST3_8dd11b6c_Tx{Right}] */
  { /*     6 */               TRUE,           38u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/RBTM_FR_Tens_ST3_1364a6b3_Tx{Right}] */
  { /*     7 */               TRUE,           39u }   /* [/ActiveEcuC/EcuC/EcucPduCollection/ROE_RBTM_FR_ST3_ae40752b_Tx{Right}] */
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
  { /*     0 */           45u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx{Left}] */
  { /*     1 */           47u },  /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx{Left}] */
  { /*     2 */           49u }   /* [/ActiveEcuC/EcuC/EcucPduCollection/SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx{Left}] */
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
  /* Index        Referable Keys   Left */
  /*     0 */  /* [PduRSinglePartitionDummy] */
  /* Index        Referable Keys   Right */
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
  { /* Index: 0 Keys: [Config_Left] */
      PduR_PCPartitionConfigLeft   /**< the pointer to PduR_PCPartitionConfig in Config_Left */
  },
  { /* Index: 1 Keys: [Config_Right] */
      PduR_PCPartitionConfigRight  /**< the pointer to PduR_PCPartitionConfig in Config_Right */
  }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfigLeft
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfigLeft
  \details
  Element       Description
  RmDestRom     the pointer to PduR_RmDestRom
  RmGDestRom    the pointer to PduR_RmGDestRom
  RmSrcRom      the pointer to PduR_RmSrcRom
  TxIf2Up       the pointer to PduR_TxIf2Up
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfigLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CommonSharedMemory] */
      PduR_RmDestRomLeft   /**< the pointer to PduR_RmDestRom in Config_Left */
    , PduR_RmGDestRomLeft  /**< the pointer to PduR_RmGDestRom in Config_Left */
    , PduR_RmSrcRomLeft    /**< the pointer to PduR_RmSrcRom in Config_Left */
    , PduR_TxIf2UpLeft     /**< the pointer to PduR_TxIf2Up in Config_Left */
  }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfigRight
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfigRight
  \details
  Element       Description
  RmDestRom     the pointer to PduR_RmDestRom
  RmGDestRom    the pointer to PduR_RmGDestRom
  RmSrcRom      the pointer to PduR_RmSrcRom
  TxIf2Up       the pointer to PduR_TxIf2Up
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfigRight[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [CommonSharedMemory] */
      PduR_RmDestRomRight   /**< the pointer to PduR_RmDestRom in Config_Right */
    , PduR_RmGDestRomRight  /**< the pointer to PduR_RmGDestRom in Config_Right */
    , PduR_RmSrcRomRight    /**< the pointer to PduR_RmSrcRom in Config_Right */
    , PduR_TxIf2UpRight     /**< the pointer to PduR_TxIf2Up in Config_Right */
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
 * PduR_ComTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
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


/**********************************************************************************************************************
 * PduR_IpduMTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_IpduMTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
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


/**********************************************************************************************************************
 * PduR_SecOCTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SecOCTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
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

/**********************************************************************************************************************
 * PduR_CanIfRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general communication interface TxConfirmation function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(PduIdType TxPduId) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
  PduR_LoIfTxConfirmation(TxPduId);
#endif
  PDUR_DUMMY_STATEMENT(TxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}



/**********************************************************************************************************************
 * PduR_CanNmRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanNmRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanNmTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general communication interface TxConfirmation function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanNmTxConfirmation(PduIdType TxPduId) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
  PduR_LoIfTxConfirmation(TxPduId);
#endif
  PDUR_DUMMY_STATEMENT(TxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}



/**********************************************************************************************************************
 * PduR_IpduMRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_IpduMRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_SecOCRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_SecOCRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}



/**********************************************************************************************************************
 * PduR_CanNmTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general TriggerTransmit function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CanNmTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  return PduR_LoIfTriggerTransmit(TxPduId, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}


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


/* CancelReceive global without UseTag API */

/* ChangeParameter global without UseTag  API */

/* Communication Interface / Transport Protocol APIs */

/* Communication Interface / Transport Protocol APIs */

/**********************************************************************************************************************
 * PduR_ComCancelTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CancelTransmit function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComCancelTransmit(PduIdType id)
{
  return PduR_CancelTransmit(id); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}


/**********************************************************************************************************************
 * PduR_DcmCancelTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CancelTransmit function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmCancelTransmit(PduIdType id)
{
  return PduR_CancelTransmit(id); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
}


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

