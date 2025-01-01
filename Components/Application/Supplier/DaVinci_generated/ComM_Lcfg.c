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
 *            Module: ComM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:11
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define CCL_ASR_COMM_LCFG_MODULE

/**********************************************************************************************************************
   LOCAL MISRA / PCLINT JUSTIFICATION
**********************************************************************************************************************/
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2_0779 */
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1_0777 */
/* PRQA S 3453 EOF */ /* MD_MSR_FctLikeMacro */

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "ComM_Private_Cfg.h"
#include "CanSM_ComM.h"
#include "CanSM.h"



#include "Rte_ComM.h"

# include "ComM_Lcfg.h"


#if defined( COMM_LOCAL )
#else
# define COMM_LOCAL static
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
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
  ComM_ChannelLeft
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelLeft
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  Enabled                   Decides if the channel is enabled in the variant
  NmType                    The Network Management type of the channel
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelLeft[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Enabled  NmType                                         GetCurrentBusSMModeApi   RequestBusSMModeApi         Referable Keys */
  { /*     0 */    TRUE,                     COMM_FULL_NMTYPEOFCHANNEL, CanSM_GetCurrentComMode, CanSM_RequestComMode },  /* [ComMChannel_0] */
  { /*     1 */   FALSE, COMM_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL, NULL_PTR               , NULL_PTR             }   /* [ComMChannel_1] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelRight
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelRight
  \brief  Contains PreCompile configuration parameters of channels
  \details
  Element                   Description
  Enabled                   Decides if the channel is enabled in the variant
  NmType                    The Network Management type of the channel
  GetCurrentBusSMModeApi    Query the current communication mode from the corresponding BusSM
  RequestBusSMModeApi       Request the communication mode from the corresponding BusSM
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelRight[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Enabled  NmType                                         GetCurrentBusSMModeApi   RequestBusSMModeApi         Referable Keys */
  { /*     0 */   FALSE, COMM_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL, NULL_PTR               , NULL_PTR             },  /* [ComMChannel_0] */
  { /*     1 */    TRUE,                     COMM_FULL_NMTYPEOFCHANNEL, CanSM_GetCurrentComMode, CanSM_RequestComMode }   /* [ComMChannel_1] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbLeft
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbLeft
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  PncPbIndEndIdx            the end index of the 0:n relation pointing to ComM_PncPbInd
  PncPbIndStartIdx          the start index of the 0:n relation pointing to ComM_PncPbInd
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbLeft[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PncPbIndEndIdx                     PncPbIndStartIdx                     UserReqFullComEndIdx                     UserReqFullComStartIdx                    */
  { /*     0 */                                2u,                                  0u,                                      1u,                                        0u },
  { /*     1 */ COMM_NO_PNCPBINDENDIDXOFCHANNELPB, COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB, COMM_NO_USERREQFULLCOMENDIDXOFCHANNELPB, COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbRight
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbRight
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  PncPbIndEndIdx            the end index of the 0:n relation pointing to ComM_PncPbInd
  PncPbIndStartIdx          the start index of the 0:n relation pointing to ComM_PncPbInd
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbRight[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    PncPbIndEndIdx                     PncPbIndStartIdx                     UserReqFullComEndIdx                     UserReqFullComStartIdx                    */
  { /*     0 */ COMM_NO_PNCPBINDENDIDXOFCHANNELPB, COMM_NO_PNCPBINDSTARTIDXOFCHANNELPB, COMM_NO_USERREQFULLCOMENDIDXOFCHANNELPB, COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB },
  { /*     1 */                                2u,                                  0u,                                      1u,                                        0u }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_EiraTxSignalIndirection
**********************************************************************************************************************/
/** 
  \var    ComM_EiraTxSignalIndirection
  \brief  Indirection of internal signal id to the actual Eira Tx Symbolic Name Value
  \details
  Element              Description
  SymbolicNameValue    SymbolicNameValue of Tx Eira Signal
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_EiraTxSignalIndirectionType, COMM_CONST) ComM_EiraTxSignalIndirection[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SymbolicNameValue                                */
  { /*     0 */ ComConf_ComSignal_NM_RBTM_FL_ST3_PNC_785a2d76_Tx },
  { /*     1 */ COMM_NO_SYMBOLICNAMEVALUE                        },
  { /*     2 */ ComConf_ComSignal_NM_RBTM_FR_ST3_PNC_0103a546_Tx }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    ComM_PartitionIdentifiers
  \brief  the partition context in Config_Left
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PartitionIdentifiersType, COMM_CONST) ComM_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV          PCPartitionConfigIdx */
  { /*     0 */ COMM_SINGLEPARTITION,                   0u }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Pnc
**********************************************************************************************************************/
/** 
  \var    ComM_Pnc
  \brief  Contains PreCompile configuration parameters of partial networks
  \details
  Element      Description
  ClearMask    Clear mask for the partial network related signals (EIRA, ERA)
  PncId        System ID of the partial network
  SetMask      Set mask for the partial network related signals (EIRA, ERA)
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncType, COMM_CONST) ComM_Pnc[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ClearMask  PncId  SetMask        Referable Keys */
  { /*     0 */     0xFEu,    8u,   0x01u },  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  { /*     1 */     0xEFu,   28u,   0x10u }   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncChannelMappingLeft
**********************************************************************************************************************/
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncChannelMappingType, COMM_CONST) ComM_PncChannelMappingLeft[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PncChannelMapping      Referable Keys */
  /*     0 */                 0u,  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */                 0u   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
};
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncChannelMappingRight
**********************************************************************************************************************/
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncChannelMappingType, COMM_CONST) ComM_PncChannelMappingRight[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     PncChannelMapping      Referable Keys */
  /*     0 */                 1u,  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */                 1u   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
};
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPb
**********************************************************************************************************************/
/** 
  \var    ComM_PncPb
  \brief  Contains PostBuild configuration parameters of partial networks
  \details
  Element                      Description
  PncChannelMappingEndIdx      the end index of the 0:n relation pointing to ComM_PncChannelMapping
  PncChannelMappingStartIdx    the start index of the 0:n relation pointing to ComM_PncChannelMapping
  PncSignalIndEndIdx           the end index of the 0:n relation pointing to ComM_PncSignalInd
  PncSignalIndStartIdx         the start index of the 0:n relation pointing to ComM_PncSignalInd
  SignalByteIndex              Byte index in the partial network related signals (EIRA, ERA)
  UserReqPncFullComEndIdx      the end index of the 1:n relation pointing to ComM_UserReqPncFullCom
  UserReqPncFullComStartIdx    the start index of the 1:n relation pointing to ComM_UserReqPncFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncPbType, COMM_CONST) ComM_PncPb[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PncChannelMappingEndIdx  PncChannelMappingStartIdx  PncSignalIndEndIdx  PncSignalIndStartIdx  SignalByteIndex  UserReqPncFullComEndIdx  UserReqPncFullComStartIdx        Referable Keys */
  { /*     0 */                      1u,                        0u,                 1u,                   0u,              0u,                      1u,                        0u },  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696, ComMChannel_0] */
  { /*     1 */                      2u,                        1u,                 2u,                   1u,              2u,                      2u,                        1u }   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885, ComMChannel_0] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPbInd
**********************************************************************************************************************/
/** 
  \var    ComM_PncPbInd
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncPb
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncPbIndType, COMM_CONST) ComM_PncPbInd[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PncPbInd      Referable Keys */
  /*     0 */        0u,  /* [ComMChannel_0] */
  /*     1 */        1u   /* [ComMChannel_0] */
};
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalLeft
  \brief  Information about partial network signals (EIRA, ERA)
  \details
  Element                    Description
  ChannelIdx                 the index of the 0:1 relation pointing to ComM_Channel
  PncSignalValuesEndIdx      the end index of the 0:n relation pointing to ComM_PncSignalValues
  PncSignalValuesStartIdx    the start index of the 0:n relation pointing to ComM_PncSignalValues
  Type                       Partial network signal type
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncSignalType, COMM_CONST) ComM_PncSignalLeft[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ChannelIdx                     PncSignalValuesEndIdx                     PncSignalValuesStartIdx                     Type                                                 Referable Keys */
  { /*     0 */                            0u,                                       7u,                                         0u,                  COMM_EIRA_TX_TYPEOFPNCSIGNAL },  /* [ComM_ComConf_ComSignal_NM_RBTM_FL_ST3_PNC_785a2d76_Tx, /ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696, /ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
  { /*     1 */ COMM_NO_CHANNELIDXOFPNCSIGNAL,                                      14u,                                         7u,                  COMM_EIRA_RX_TYPEOFPNCSIGNAL },  /* [ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx] */
  { /*     2 */ COMM_NO_CHANNELIDXOFPNCSIGNAL, COMM_NO_PNCSIGNALVALUESENDIDXOFPNCSIGNAL, COMM_NO_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL, COMM_NOT_USED_IN_THIS_VARIANT_TYPEOFPNCSIGNAL }   /* [UnusedComConf_ComSignal_NM_RBTM_FR_ST3_PNC_0103a546_Tx] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalRight
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalRight
  \brief  Information about partial network signals (EIRA, ERA)
  \details
  Element                    Description
  ChannelIdx                 the index of the 0:1 relation pointing to ComM_Channel
  PncSignalValuesEndIdx      the end index of the 0:n relation pointing to ComM_PncSignalValues
  PncSignalValuesStartIdx    the start index of the 0:n relation pointing to ComM_PncSignalValues
  Type                       Partial network signal type
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncSignalType, COMM_CONST) ComM_PncSignalRight[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    ChannelIdx                     PncSignalValuesEndIdx                     PncSignalValuesStartIdx                     Type                                                 Referable Keys */
  { /*     0 */ COMM_NO_CHANNELIDXOFPNCSIGNAL, COMM_NO_PNCSIGNALVALUESENDIDXOFPNCSIGNAL, COMM_NO_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL, COMM_NOT_USED_IN_THIS_VARIANT_TYPEOFPNCSIGNAL },  /* [UnusedComConf_ComSignal_NM_RBTM_FL_ST3_PNC_785a2d76_Tx] */
  { /*     1 */ COMM_NO_CHANNELIDXOFPNCSIGNAL,                                       7u,                                         0u,                  COMM_EIRA_RX_TYPEOFPNCSIGNAL },  /* [ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx] */
  { /*     2 */                            1u,                                      14u,                                         7u,                  COMM_EIRA_TX_TYPEOFPNCSIGNAL }   /* [ComM_ComConf_ComSignal_NM_RBTM_FR_ST3_PNC_0103a546_Tx, /ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696, /ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalIndLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalIndLeft
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncSignal
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncSignalIndType, COMM_CONST) ComM_PncSignalIndLeft[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PncSignalInd      Referable Keys */
  /*     0 */            0u,  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */            0u   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
};
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalIndRight
**********************************************************************************************************************/
/** 
  \var    ComM_PncSignalIndRight
  \brief  the indexes of the 1:1 sorted relation pointing to ComM_PncSignal
*/ 
#define COMM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PncSignalIndType, COMM_CONST) ComM_PncSignalIndRight[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     PncSignalInd      Referable Keys */
  /*     0 */            2u,  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */            2u   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
};
#define COMM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element                    Description
  PncUser                    decides if a user is a partial network user or a direct channel user
  UserByteMaskEndIdx         the end index of the 0:n relation pointing to ComM_UserByteMask
  UserByteMaskStartIdx       the start index of the 0:n relation pointing to ComM_UserByteMask
  UserPncByteMaskEndIdx      the end index of the 0:n relation pointing to ComM_UserPncByteMask
  UserPncByteMaskLength      the number of relations pointing to ComM_UserPncByteMask
  UserPncByteMaskStartIdx    the start index of the 0:n relation pointing to ComM_UserPncByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_UserType, COMM_CONST) ComM_User[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PncUser  UserByteMaskEndIdx  UserByteMaskStartIdx  UserPncByteMaskEndIdx                UserPncByteMaskLength  UserPncByteMaskStartIdx                      Comment */
  { /*     0 */   FALSE,                 1u,                   0u, COMM_NO_USERPNCBYTEMASKENDIDXOFUSER,                    0u, COMM_NO_USERPNCBYTEMASKSTARTIDXOFUSER },  /* [RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_a4eabb6e] */
  { /*     1 */    TRUE,                 2u,                   1u,                                  1u,                    1u,                                    0u },  /* [PNC_00_MAPPING_60241c9f] */
  { /*     2 */    TRUE,                 3u,                   2u,                                  2u,                    1u,                                    1u }   /* [PNC_20_MAPPING_4fe27ecf] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskLeft
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskLeft
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element      Description
  Channel      ID of the channel which is requested by this entry.
  ClearMask    Clear-mask for clearing the bit which corresponds to this user
  SetMask      Set-mask for setting the bit which corresponds to this user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskLeft[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Channel  ClearMask  SetMask        Referable Keys */
  { /*     0 */      0u,     0xFEu,   0x01u },  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_a4eabb6e{Left}] */
  { /*     1 */      0u,     0xFDu,   0x02u },  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_60241c9f] */
  { /*     2 */      0u,     0xFBu,   0x04u }   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_4fe27ecf] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskRight
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskRight
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element      Description
  Channel      ID of the channel which is requested by this entry.
  ClearMask    Clear-mask for clearing the bit which corresponds to this user
  SetMask      Set-mask for setting the bit which corresponds to this user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskRight[3] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Channel  ClearMask  SetMask        Referable Keys */
  { /*     0 */      1u,     0xFEu,   0x01u },  /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_1f2180a7{Right}] */
  { /*     1 */      1u,     0xFDu,   0x02u },  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_60241c9f] */
  { /*     2 */      1u,     0xFBu,   0x04u }   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_4fe27ecf] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserPncByteMask
**********************************************************************************************************************/
/** 
  \var    ComM_UserPncByteMask
  \brief  Each partial network user has N entries in this array (N = # pncs attached to this user). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqPncFullCom
  \details
  Element                 Description
  PncID                   System Id of the partial network which is requested by this entry
  PncIdx                  the index of the 1:1 relation pointing to ComM_Pnc
  UserReqPncFullComIdx    the index of the 1:1 relation pointing to ComM_UserReqPncFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_UserPncByteMaskType, COMM_CONST) ComM_UserPncByteMask[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PncID  PncIdx  UserReqPncFullComIdx        Referable Keys */
  { /*     0 */    8u,     0u,                   0u },  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_60241c9f] */
  { /*     1 */   28u,     1u,                   1u }   /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_4fe27ecf] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActiveComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActiveComMode
  \brief  Current state of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_ActiveComModeUType, COMM_VAR_NO_INIT) ComM_ActiveComMode;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ActivePncComMode
**********************************************************************************************************************/
/** 
  \var    ComM_ActivePncComMode
  \brief  stores the current partial network state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_ActivePncComModeUType, COMM_VAR_NO_INIT) ComM_ActivePncComMode;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusComModeReq
  \brief  State requested externally (bus)
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_BusComModeReqUType, COMM_VAR_NO_INIT) ComM_BusComModeReq;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusPncComModeReq
**********************************************************************************************************************/
/** 
  \var    ComM_BusPncComModeReq
  \brief  Stores the partial network state requested by external requests
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_BusPncComModeReqUType, COMM_VAR_NO_INIT) ComM_BusPncComModeReq;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_BusSmState
**********************************************************************************************************************/
/** 
  \var    ComM_BusSmState
  \brief  Communication state of a channel provided by BusSM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_BusSmStateUType, COMM_VAR_NO_INIT) ComM_BusSmState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ComAllowed
**********************************************************************************************************************/
/** 
  \var    ComM_ComAllowed
  \brief  Communication allowed status of a channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_ComAllowedUType, COMM_VAR_NO_INIT) ComM_ComAllowed;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_DcmRequestActive
**********************************************************************************************************************/
/** 
  \var    ComM_DcmRequestActive
  \brief  Status of Dcm active diagnostic request, TRUE if requested, FALSE otherwise
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_DcmRequestActiveUType, COMM_VAR_NO_INIT) ComM_DcmRequestActive;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_EcuMWakeUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_EcuMWakeUpIndicated
  \brief  Passive Wakeup indicated by EcuM (ComM_EcuM_WakeUpIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(ComM_EcuMWakeUpIndicatedType, COMM_VAR_NO_INIT) ComM_EcuMWakeUpIndicated[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_Inhibition
**********************************************************************************************************************/
/** 
  \var    ComM_Inhibition
  \brief  Status of mode limitation (inhibition)
*/ 
#define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_InhibitionType, COMM_NVM_DATA_NO_INIT) ComM_Inhibition;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_InitStatus
**********************************************************************************************************************/
/** 
  \var    ComM_InitStatus
  \brief  Initialization state of ComM
*/ 
#define COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_InitStatusType, COMM_VAR_NO_INIT) ComM_InitStatus;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_NmStartUpIndicated
**********************************************************************************************************************/
/** 
  \var    ComM_NmStartUpIndicated
  \brief  Passive Wakeup indicated by Nm (ComM_Nm_NetworkStartIndication() or ComM_Nm_RestartIndication()). TRUE if indicated, FALSE otherwise.
*/ 
#define COMM_START_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
volatile VAR(ComM_NmStartUpIndicatedType, COMM_VAR_NO_INIT) ComM_NmStartUpIndicated[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COMM_STOP_SEC_VAR_NOCACHE_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncPSleepTimer
**********************************************************************************************************************/
/** 
  \var    ComM_PncPSleepTimer
  \brief  partial network prepare sleep timer
*/ 
#define COMM_START_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_PncPSleepTimerUType, COMM_VAR_NO_INIT) ComM_PncPSleepTimer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885] */

#define COMM_STOP_SEC_VAR_NO_INIT_16
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncSignalValues
**********************************************************************************************************************/
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_PncSignalValuesUType, COMM_VAR_NO_INIT) ComM_PncSignalValues;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComM_ComConf_ComSignal_NM_RBTM_FL_ST3_PNC_785a2d76_Tx] */
  /*   ... */  /* [ComM_ComConf_ComSignal_NM_RBTM_FL_ST3_PNC_785a2d76_Tx] */
  /*     6 */  /* [ComM_ComConf_ComSignal_NM_RBTM_FL_ST3_PNC_785a2d76_Tx] */
  /*     7 */  /* [ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx] */
  /*   ... */  /* [ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx] */
  /*    13 */  /* [ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx] */
  /*   ... */  /* [ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx] */
  /*     6 */  /* [ComM_ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx] */
  /*     7 */  /* [ComM_ComConf_ComSignal_NM_RBTM_FR_ST3_PNC_0103a546_Tx] */
  /*   ... */  /* [ComM_ComConf_ComSignal_NM_RBTM_FR_ST3_PNC_0103a546_Tx] */
  /*    13 */  /* [ComM_ComConf_ComSignal_NM_RBTM_FR_ST3_PNC_0103a546_Tx] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PncToChannelRoutingState
**********************************************************************************************************************/
/** 
  \var    ComM_PncToChannelRoutingState
  \brief  Bit flags describing the current PNC Routing state per channel
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_PncToChannelRoutingStateUType, COMM_VAR_NO_INIT) ComM_PncToChannelRoutingState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PostInitialized
**********************************************************************************************************************/
/** 
  \var    ComM_PostInitialized
  \brief  Post-Initialized state
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_PostInitializedType, COMM_VAR_NO_INIT) ComM_PostInitialized[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ResetRequired
**********************************************************************************************************************/
/** 
  \var    ComM_ResetRequired
  \brief  TRUE if a reset has to be performed
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_ResetRequiredUType, COMM_VAR_NO_INIT) ComM_ResetRequired;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqFullCom
  \brief  RAM array used to store user requests for channels as bitmasks. Each channel 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_UserReqFullComType, COMM_VAR_NO_INIT) ComM_UserReqFullCom[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [ComMChannel_0, Channel0_To_User0, Channel0_To_User1, Channel0_To_User2] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [ComMChannel_1, Channel1_To_User0, Channel1_To_User1, Channel1_To_User2] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserReqPncFullCom
**********************************************************************************************************************/
/** 
  \var    ComM_UserReqPncFullCom
  \brief  RAM array used to store user requests for PNCs as bitmasks. Each PNC 'owns' 1..n bytes in this array, depending on the number of users assigned to it.
*/ 
#define COMM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(ComM_UserReqPncFullComType, COMM_VAR_NO_INIT) ComM_UserReqPncFullCom[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys   Left */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696, Pnc8_To_User1] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885, Pnc28_To_User2] */
  /* Index        Referable Keys   Right */
  /*     0 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_00_MAPPING_b2c42696, Pnc8_To_User1] */
  /*     1 */  /* [/ActiveEcuC/ComM/ComMConfigSet/PNC_20_MAPPING_796df885, Pnc28_To_User2] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCConfig
**********************************************************************************************************************/
/** 
  \var    ComM_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to ComM_PCPartitionConfig
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PCConfigsType, COMM_CONST) ComM_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_Left] */
      ComM_PCPartitionConfigLeft   /**< the pointer to ComM_PCPartitionConfig in Config_Left */
  },
  { /* Index: 1 Keys: [Config_Right] */
      ComM_PCPartitionConfigRight  /**< the pointer to ComM_PCPartitionConfig in Config_Right */
  }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigLeft
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigLeft
  \details
  Element              Description
  Channel              the pointer to ComM_Channel
  ChannelPb            the pointer to ComM_ChannelPb
  PncChannelMapping    the pointer to ComM_PncChannelMapping
  PncSignal            the pointer to ComM_PncSignal
  PncSignalInd         the pointer to ComM_PncSignalInd
  UserByteMask         the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [COMM_SINGLEPARTITION] */
      ComM_ChannelLeft            /**< the pointer to ComM_Channel in Config_Left */
    , ComM_ChannelPbLeft          /**< the pointer to ComM_ChannelPb in Config_Left */
    , ComM_PncChannelMappingLeft  /**< the pointer to ComM_PncChannelMapping in Config_Left */
    , ComM_PncSignalLeft          /**< the pointer to ComM_PncSignal in Config_Left */
    , ComM_PncSignalIndLeft       /**< the pointer to ComM_PncSignalInd in Config_Left */
    , ComM_UserByteMaskLeft       /**< the pointer to ComM_UserByteMask in Config_Left */
  }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigRight
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigRight
  \details
  Element              Description
  Channel              the pointer to ComM_Channel
  ChannelPb            the pointer to ComM_ChannelPb
  PncChannelMapping    the pointer to ComM_PncChannelMapping
  PncSignal            the pointer to ComM_PncSignal
  PncSignalInd         the pointer to ComM_PncSignalInd
  UserByteMask         the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRight[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [COMM_SINGLEPARTITION] */
      ComM_ChannelRight            /**< the pointer to ComM_Channel in Config_Right */
    , ComM_ChannelPbRight          /**< the pointer to ComM_ChannelPb in Config_Right */
    , ComM_PncChannelMappingRight  /**< the pointer to ComM_PncChannelMapping in Config_Right */
    , ComM_PncSignalRight          /**< the pointer to ComM_PncSignal in Config_Right */
    , ComM_PncSignalIndRight       /**< the pointer to ComM_PncSignalInd in Config_Right */
    , ComM_UserByteMaskRight       /**< the pointer to ComM_UserByteMask in Config_Right */
  }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */




/* -----------------------------------------------------------------------------
    &&&~ GLOBAL DATA ROM
 ----------------------------------------------------------------------------- */

#define COMM_START_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_MemMap */ 
#include "ComM_MemMap.h"

CONST(ComM_InhibitionStatusType, COMM_CONST) ComM_ECUGroupClassInit = 0x03; /* PRQA S 1533 */ /* MD_ComM_1533 */


#define COMM_STOP_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_MemMap */ 
#include "ComM_MemMap.h"


/* -----------------------------------------------------------------------------
    &&&~ INTERNAL DATA RAM
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ GLOBAL DATA RAM
 ----------------------------------------------------------------------------- */

#define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ GLOBAL FUNCTION PROTOTYPES
 ----------------------------------------------------------------------------- */

/*********************************************************************************************************************
FUNCTION: ComM_MainFunction_0
*********************************************************************************************************************/
/*!
 * \internal
 * - #10 Call the ComM_MainFunction() for the corresponding channel.
 * \endinternal
 */
FUNC(void, COMM_CODE) ComM_MainFunction_0(void)
{
  /* ----- Development Error Checks ------------------------------------- */
  /* Not needed, ComM_MainFunction() performs an initialization check. */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call the ComM_MainFunction() for the corresponding channel. */
  ComM_MainFunction((NetworkHandleType)0 );
}

/*********************************************************************************************************************
FUNCTION: ComM_MainFunction_1
*********************************************************************************************************************/
/*!
 * \internal
 * - #10 Call the ComM_MainFunction() for the corresponding channel.
 * \endinternal
 */
FUNC(void, COMM_CODE) ComM_MainFunction_1(void)
{
  /* ----- Development Error Checks ------------------------------------- */
  /* Not needed, ComM_MainFunction() performs an initialization check. */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Call the ComM_MainFunction() for the corresponding channel. */
  ComM_MainFunction((NetworkHandleType)1 );
}



/*********************************************************************************************************************
  FUNCTION: ComM_ComCbk_ComSignalPnc_EIRA_CAN_Rx
*********************************************************************************************************************/
/*!
 * \internal
 * - #10 Notification that an EIRA_RX or ERA signal data has changed. 
 *       Receive the data of the corresponding signal and trigger signal data processing.
 * \endinternal
 */
FUNC(void, COMM_CODE) ComM_ComCbk_ComSignalPnc_EIRA_CAN_Rx(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 EiraOrEraValuesRx[COMM_PNC_SIGNAL_LENGTH] = {0};

  /* ----- Implementation ----------------------------------------------- */
  /* - #10 Notification that an EIRA_RX or ERA signal data has changed. 
   *       Receive the data of the corresponding signal and trigger signal data processing. */
  {
    (void)Com_ReceiveSignal(ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx, &EiraOrEraValuesRx[0]); /* SBSW_COMM_CALL_COM_RECEIVE_SIGNAL */ /* PRQA S 0315 */ /* MD_ComM_0315 */

    ComM_PncProcessRxSignalEira(1, &EiraOrEraValuesRx[0]); /* SBSW_COMM_CALL_WITH_PTR_TO_CONST */
  }

}
#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"

