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
 *            Module: IpduM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IpduM_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:06
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define IPDUM_LCFG_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "IpduM.h"
#include "SchM_IpduM.h"
#include "IpduM_Cfg.h"
#include "IpduM_Lcfg.h"
#include "IpduM_PBcfg.h"

/* include headers with symbolic name values */
# include "PduR_Cfg.h"

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
  IpduM_RxDynPdu
**********************************************************************************************************************/
/** 
  \var    IpduM_RxDynPdu
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart
  \details
  Element          Description
  SegmentEndIdx    the end index of the 1:n relation pointing to IpduM_Segment
  UlPduRef         the DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway/IpduMRxIndication/IpduMRxDynamicPart/IpduMOutgoingDynamicPduRef
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_RxDynPduType, IPDUM_CONST) IpduM_RxDynPdu[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SegmentEndIdx  UlPduRef                                       Referable Keys */
  { /*     0 */            1u, PduRConf_PduRSrcPdu_PduRSrcPdu_27f93d01 },  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66] */
  { /*     1 */            1u, PduRConf_PduRSrcPdu_PduRSrcPdu_d1b2606a },  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66] */
  { /*     2 */            1u, PduRConf_PduRSrcPdu_PduRSrcPdu_9e880434 },  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3] */
  { /*     3 */            1u, PduRConf_PduRSrcPdu_PduRSrcPdu_d645a86c }   /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxInfo
**********************************************************************************************************************/
/** 
  \var    IpduM_RxInfo
  \brief  All DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway and DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMContainerRxPdu, used for RxIndication().
  \details
  Element         Description
  RxPathwayInd    the enum value of the according target of the 1:1 relation pointing to one of IpduM_RxMuxPdu,IpduM_RxContainerPdu
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_RxInfoType, IPDUM_CONST) IpduM_RxInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxPathwayInd                        */
  { /*     0 */ IPDUM_RXMUXPDU_RXPATHWAYINDOFRXINFO },
  { /*     1 */ IPDUM_RXMUXPDU_RXPATHWAYINDOFRXINFO }
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxMuxPdu
**********************************************************************************************************************/
/** 
  \var    IpduM_RxMuxPdu
  \brief  DefinitionRef: /MICROSAR/IpduM/IpduMConfig/IpduMRxPathway
  \details
  Element                  Description
  RxBufferStartIdx         the start index of the 1:n relation pointing to IpduM_RxBuffer
  RxDynPduStartIdx         the start index of the 1:n relation pointing to IpduM_RxDynPdu
  SelectorFieldStartBit    the bit position of the selector value in the byte position.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_RxMuxPduType, IPDUM_CONST) IpduM_RxMuxPdu[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxBufferStartIdx  RxDynPduStartIdx  SelectorFieldStartBit        Referable Keys */
  { /*     0 */               0u,               0u,                    0u },  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66] */
  { /*     1 */               8u,               2u,                    3u }   /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxSelectorPattern
**********************************************************************************************************************/
/** 
  \var    IpduM_RxSelectorPattern
  \brief  Selector patterns for single- and multi-byte selector value matching. This table is sorted for ascending byte number within one DynPdu.
  \details
  Element                    Description
  SelectorFieldSubMask       One byte of the mask the pattern is masked with for the selector field as it is transmitted.
  SelectorFieldSubPattern    One byte of the masked pattern for the selector field as it is transmitted - calculated from position and length.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_RxSelectorPatternType, IPDUM_CONST) IpduM_RxSelectorPattern[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    SelectorFieldSubMask  SelectorFieldSubPattern        Referable Keys */
  { /*     0 */                0x07u,                   0x06u },  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66/ADAS_PREDICTION_ST3_aeaf2bf1] */
  { /*     1 */                0x07u,                   0x07u },  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66/ADAS_PREDICTION_ST3_d9a81b67] */
  { /*     2 */                0xF8u,                   0xF8u },  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3/ADAS_PROFILE_SHORT_ST3_42520299] */
  { /*     3 */                0xF8u,                   0x08u }   /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3/ADAS_PROFILE_SHORT_ST3_01fee412] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Segment
**********************************************************************************************************************/
/** 
  \var    IpduM_Segment
  \brief  all IpduMSegments
  \details
  Element             Description
  FullBytesPresent    True if full bytes exist in this segment.
*/ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(IpduM_SegmentType, IPDUM_CONST) IpduM_Segment[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FullBytesPresent        Referable Keys */
  { /*     0 */             TRUE }   /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66/ADAS_PREDICTION_ST3_aeaf2bf1, /ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66/ADAS_PREDICTION_ST3_d9a81b67, /ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3/ADAS_PROFILE_SHORT_ST3_01fee412, /ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3/ADAS_PROFILE_SHORT_ST3_42520299] */
};
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_Initialized
**********************************************************************************************************************/
/** 
  \var    IpduM_Initialized
  \brief  Initialization state of the IpduM. TRUE, if IpduM_Init() has been called, else FALSE.
*/ 
#define IPDUM_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpduM_InitializedType, IPDUM_VAR_CLEARED) IpduM_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define IPDUM_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  IpduM_RxBuffer
**********************************************************************************************************************/
/** 
  \var    IpduM_RxBuffer
  \brief  buffer to de-multiplex and forward RX static and dynamic parts from the received multiplex I-PDU.
*/ 
#define IPDUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(IpduM_RxBufferUType, IPDUM_VAR_NO_INIT) IpduM_RxBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66] */
  /*   ... */  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66] */
  /*     7 */  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PREDICTION_ST3_549e2a63_Rx/IpduMRxIndication_33e88c66] */
  /*     8 */  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3] */
  /*   ... */  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3] */
  /*    15 */  /* [/ActiveEcuC/IpduM/IpduMConfig/ADAS_PROFILE_SHORT_ST3_2225c4a7_Rx/IpduMRxIndication_17ccd7a3] */

#define IPDUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "IpduM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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
#define IPDUM_START_SEC_CODE
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * IpduM_MainFunctionRx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call IpduM_MainFunctionRx with the id which represents the corresponding MainFunction context.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_MainFunctionRx(void)
{
#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
  if(IpduM_IsInitialized())
  {
    IpduM_MainFunctionRxIndirectionIterType mainFunctionRxIndirectionIdx = 0;
    IpduM_MainFunctionRxInternal(mainFunctionRxIndirectionIdx);
  }
#endif
}

/**********************************************************************************************************************
 * IpduM_MainFunctionTx
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call IpduM_MainFunctionTx with the id which represents the corresponding MainFunction context.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_MainFunctionTx(void)
{
#if((IPDUM_TXCONFTIMEOUTCNTOFVTXLOINFO == STD_ON) || (IPDUM_TXCONTAINEDPDU == STD_ON))
  if(IpduM_IsInitialized())
  {
    IpduM_MainFunctionTxIndirectionIterType mainFunctionTxIndirectionIdx = 0;
    IpduM_MainFunctionTxInternal(mainFunctionTxIndirectionIdx);
  }
#endif
}

#define IPDUM_STOP_SEC_CODE
#include "IpduM_MemMap.h" /* PRQA S 5087 */   /* MD_MSR_MemMap */

/**********************************************************************************************************************
  END OF FILE: IpduM_Lcfg.c
**********************************************************************************************************************/

