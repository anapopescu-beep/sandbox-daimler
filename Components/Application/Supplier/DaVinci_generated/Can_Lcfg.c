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
 *            Module: Can
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:11
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define CAN_LCFG_SOURCE

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "Can_Cfg.h"

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */

/* HW specific CT global C file */

/* !HW specific CT global C file */

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
  Can_BTP
**********************************************************************************************************************/
/** 
  \var    Can_BTP
  \brief  Bit Timing and Prescaler
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_BTPType, CAN_CONST) Can_BTP[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     BTP              Comment */
  /*     0 */  0x060F0E03u   /* [RBTM_FL_BODY3_180ddaa4 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_BufferConfig
**********************************************************************************************************************/
/** 
  \var    Can_BufferConfig
  \brief  CAN Buffer Configuration
  \details
  Element    Description
  RXF0C  
  RXF1C  
  TXBC   
  RXBC   
  TXEFC  
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_BufferConfigType, CAN_CONST) Can_BufferConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RXF0C        RXF1C        TXBC         RXBC   TXEFC        Comment */
  { /*     0 */ 0x0006000Cu, 0x0006006Cu, 0x000100CCu, 0x00u, 0x00u }   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanIfChannelId      Comment */
  /*     0 */              0u   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanSubSystemBaseAdr
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_CanSubSystemBaseAdrType, CAN_CONST) Can_CanSubSystemBaseAdr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanSubSystemBaseAdr      Comment */
  /*     0 */          0xF0208000u   /* [Sub-system base address for system 0] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                            Description
  BasisAdr                           CAN channel base address
  IsTTCan                            TTCAN channel support
  CanControllerDefaultBaudrate   
  CanControllerDefaultBaudrateIdx
  MailboxRxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxRxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxTxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  RxBasicHwStart                 
  RxBasicHwStop                  
  RxFullHwStart                  
  RxFullHwStop                   
  RxSelection                        CAN Rx Selection
  TxBasicHwStart                 
  TxBasicHwStop                  
  TxFullHwStart                  
  TxFullHwStop                   
  UnusedHwStart                  
  UnusedHwStop                   
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BasisAdr     IsTTCan  CanControllerDefaultBaudrate  CanControllerDefaultBaudrateIdx  MailboxRxBasicEndIdx                                                                                                                                                      MailboxRxBasicLength                                                                                                                                                      MailboxRxBasicStartIdx                                                                                                                                                      MailboxTxBasicEndIdx                                                                                                                                                      MailboxTxBasicLength                                                                                                                                                      MailboxTxBasicStartIdx                                                                                                                                                      RxBasicHwStart  RxBasicHwStop  RxFullHwStart  RxFullHwStop  RxSelection  TxBasicHwStart  TxBasicHwStop  TxFullHwStart  TxFullHwStop  UnusedHwStart  UnusedHwStop        Comment                              Referable Keys */
  { /*     0 */ 0xF0208500u,   FALSE,                         250u,                              0u,                   3u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   2u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                     1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                     0u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,             0u,            2u,            0u,           0u,       0x00u,             0u,            1u,            2u,           2u,            0u,           0u }   /* [RBTM_FL_BODY3_180ddaa4] */  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left}] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_FBTP
**********************************************************************************************************************/
/** 
  \var    Can_FBTP
  \brief  Fast Bit Timing and Prescaler
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_FBTPType, CAN_CONST) Can_FBTP[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     FBTP       Comment */
  /*     0 */  0x00u   /* [RBTM_FL_BODY3_180ddaa4 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_GFC
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_GFCType, CAN_CONST) Can_GFC[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     GFC        Comment */
  /*     0 */  0x3Fu   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_INT_Priority
**********************************************************************************************************************/
/** 
  \var    Can_INT_Priority
  \brief  Interrupt Priority
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_INT_PriorityType, CAN_CONST) Can_INT_Priority[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     INT_Priority      Comment */
  /*     0 */         0x00u   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_INT_RoutingGroup
**********************************************************************************************************************/
/** 
  \var    Can_INT_RoutingGroup
  \brief  Interrupt routing for Groups
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_INT_RoutingGroupType, CAN_CONST) Can_INT_RoutingGroup[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     INT_RoutingGroup      Comment */
  /*     0 */       0x11111111u   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectBaudrate      Comment */
  /*     0 */                250u   /* [RBTM_FL_BODY3_180ddaa4 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectStartIndex      Comment */
  /*     0 */                    0u,  /* [RBTM_FL_BODY3_180ddaa4] */
  /*     1 */                    1u   /* [stop index] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsrOsId
**********************************************************************************************************************/
/** 
  \var    Can_IsrOsId
  \brief  OS Symbolic Name Value for Service Request Nodes.
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_OsIsrType, CAN_CONST) Can_IsrOsId[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     IsrOsId       Comment */
  /*     0 */ CanIsr_1    /* [RBTM_FL_BODY3_180ddaa4 [Node | Channel] 1] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  ActiveSendObject   
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_ControllerConfig
  HwHandle           
  IDValue            
  MailboxSize        
  MailboxType        
  MaxDataLen         
  MemorySectionsIndex
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ActiveSendObject  ControllerConfigIdx                                                                   HwHandle  IDValue  MailboxSize  MailboxType                                MaxDataLen  MemorySectionsIndex        Comment                                                           Referable Keys */
  { /*     0 */               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} */,       0u,   0x00u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                 32u },  /* [RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx] */  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left}, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     1 */               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} */,       0u,   0x00u,          6u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                 32u },  /* [RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_d50cf0d9_Rx] */  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_d50cf0d9_Rx{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left}, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     2 */               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} */,       1u,   0x00u,          6u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,         8u,                 33u }   /* [RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_e046a621_Rx] */  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_e046a621_Rx{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left}, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionInfo
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionInfo
  \brief  Memory section description
  \details
  Element               Description
  MemorySectionStart
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MemorySectionInfoType, CAN_CONST) Can_MemorySectionInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MemorySectionStart        Comment */
  { /*     0 */                 0u }   /* [MemorySection: TxBuffer_RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionObjects
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionObjects
  \brief  Memory section objects description
  \details
  Element           Description
  HwHandle      
  MailboxElement
  MailboxHandle 
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MemorySectionObjectsType, CAN_CONST) Can_MemorySectionObjects[32] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HwHandle  MailboxElement  MailboxHandle        Comment */
  { /*     0 */       0u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_Tx] */
  { /*     1 */       1u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*     2 */       2u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*     3 */       3u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*     4 */       4u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*     5 */       5u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*     6 */       6u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*     7 */       7u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*     8 */       8u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*     9 */       9u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    10 */      10u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    11 */      11u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    12 */      12u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    13 */      13u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    14 */      14u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    15 */      15u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    16 */      16u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    17 */      17u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    18 */      18u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    19 */      19u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    20 */      20u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    21 */      21u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    22 */      22u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    23 */      23u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    24 */      24u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    25 */      25u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    26 */      26u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    27 */      27u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    28 */      28u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    29 */      29u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    30 */      30u,             0u,            0u },  /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
  { /*    31 */      31u,             0u,            0u }   /* [TxBuffer_RBTM_FL_BODY3_180ddaa4 - Reserved] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_PhysToLogChannel
**********************************************************************************************************************/
/** 
  \var    Can_PhysToLogChannel
  \brief  indirection table physical to logical controller
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_PhysToLogChannelType, CAN_CONST) Can_PhysToLogChannel[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PhysToLogChannel             Comment */
  /*     0 */  CAN_NO_PHYSTOLOGCHANNEL,  /* [dummy element] */
  /*     1 */                       0u   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFC
**********************************************************************************************************************/
/** 
  \var    Can_SIDFC
  \brief  Standard ID filter configuration
  \details
  Element          Description
  FLSSA            Filter List Standard Start Address
  LSS              List size standard
  SIDFEEndIdx      the end index of the 0:n relation pointing to Can_SIDFE
  SIDFEStartIdx    the start index of the 0:n relation pointing to Can_SIDFE
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_SIDFCType, CAN_CONST) Can_SIDFC[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FLSSA  LSS    SIDFEEndIdx                                                                   SIDFEStartIdx                                                                         Comment */
  { /*     0 */ 0x00u, 0x01u,          1u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} */,            0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} */ }   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFELeft
**********************************************************************************************************************/
/** 
  \var    Can_SIDFELeft
  \brief  Standard ID filters
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_SIDFEType, CAN_CONST) Can_SIDFELeft[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     SIDFE                                   Comment                         Referable Keys */
  /*     0 */  0x88000000u  /*  I: 0 S0 FIFO_0 */   /* [RBTM_FL_BODY3_180ddaa4] */  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left}] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFERight
**********************************************************************************************************************/
/** 
  \var    Can_SIDFERight
  \brief  Standard ID filters
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_SIDFEType, CAN_CONST) Can_SIDFERight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     SIDFE                                   Comment                         Referable Keys */
  /*     0 */  0x90000000u  /*  I: 0 S0 FIFO_1 */   /* [RBTM_FR_BODY3_2fec3d37] */  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_2fec3d37{Right}] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SRN_Address
**********************************************************************************************************************/
/** 
  \var    Can_SRN_Address
  \brief  Service Request Node Addresses
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_SRN_AddressType, CAN_CONST) Can_SRN_Address[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SRN_Address      Comment */
  /*     0 */  0xF00385B4u   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ShmAdr
**********************************************************************************************************************/
/** 
  \var    Can_ShmAdr
  \brief  CAN Shared Message RAM configuration
  \details
  Element     Description
  RXBA        RX Buffer Address
  RXF0A       RX FIFO0 Address
  RXF1A       RX FIFO1 Address
  SIDFA       Standard Filters Address
  StartAdr    Start address of the shared memory area
  StopAdr     Stop address of the shared memory area
  TXBA        TX Buffer address
  TXEFA       TX Event FIFO address
  XIDFA       Extended Filters Address
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_ShmAdrType, CAN_CONST) Can_ShmAdr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RXBA                           RXF0A                           RXF1A                           SIDFA                          StartAdr     StopAdr      TXBA                            TXEFA                          XIDFA                                Comment */
  { /*     0 */ 0xF0200000u  /* Size[B]: 0 */, 0xF020000Cu  /* Size[B]: 96 */, 0xF020006Cu  /* Size[B]: 96 */, 0xF0200000u  /* Size[B]: 4 */, 0xF0200000u, 0xF02000DDu, 0xF02000CCu  /* Size[B]: 16 */, 0xF0200000u  /* Size[B]: 0 */, 0xF0200004u  /* Size[B]: 8 */ }   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_TDCR
**********************************************************************************************************************/
/** 
  \var    Can_TDCR
  \brief  Transmitter Delay Compensation
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_TDCRType, CAN_CONST) Can_TDCR[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TDCR       Comment */
  /*     0 */  0x00u   /* [RBTM_FL_BODY3_180ddaa4 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDAM
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_XIDAMType, CAN_CONST) Can_XIDAM[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     XIDAM            Comment */
  /*     0 */  0x1FFFFFFFu   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFC
**********************************************************************************************************************/
/** 
  \var    Can_XIDFC
  \brief  Extended ID filter configuration
  \details
  Element          Description
  FLESA            Filter List Extended Start Address
  LSE              List size extended
  XIDFEEndIdx      the end index of the 0:n relation pointing to Can_XIDFE
  XIDFEStartIdx    the start index of the 0:n relation pointing to Can_XIDFE
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_XIDFCType, CAN_CONST) Can_XIDFC[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FLESA  LSE    XIDFEEndIdx                                                                   XIDFEStartIdx                                                                         Comment */
  { /*     0 */ 0x04u, 0x01u,          1u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} */,            0u  /* /ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left} */ }   /* [RBTM_FL_BODY3_180ddaa4] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFELeft
**********************************************************************************************************************/
/** 
  \var    Can_XIDFELeft
  \brief  Extended ID filters
  \details
  Element    Description
  EIDFE_0
  EIDFE_1
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_XIDFEType, CAN_CONST) Can_XIDFELeft[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EIDFE_0                            EIDFE_1                                  Comment                              Referable Keys */
  { /*     0 */ 0x40000000u  /*  I:0 F0 FIFO_1 */, 0x80000000u  /*  I:0 F1 FIFO_1 */ }   /* [RBTM_FL_BODY3_180ddaa4] */  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FL_BODY3_180ddaa4{Left}] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFERight
**********************************************************************************************************************/
/** 
  \var    Can_XIDFERight
  \brief  Extended ID filters
  \details
  Element    Description
  EIDFE_0
  EIDFE_1
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_XIDFEType, CAN_CONST) Can_XIDFERight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    EIDFE_0                            EIDFE_1                                  Comment                              Referable Keys */
  { /*     0 */ 0x20000000u  /*  I:0 F0 FIFO_0 */, 0x80000000u  /*  I:0 F1 FIFO_0 */ }   /* [RBTM_FR_BODY3_2fec3d37] */  /* [/ActiveEcuC/Can/CanConfigSet/RBTM_FR_BODY3_2fec3d37{Right}] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  State      send state like cancelled or send activ
  Pdu        buffered PduId for confirmation or cancellation
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                      Description
  IntEnable                    CAN Interrupt Enable state for each controller
  TXBCR                        CAN Tx Buffer Cancellation Request for each controller
  TXBRP                        CAN Tx Buffer request Pending for each controller
  BusOffNotification           CAN state for each controller: busoff occur
  BusOffTransitionRequest      CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01
  CanInterruptCounter          CAN interrupt disable counter for each controller
  IsBusOff                     CAN state for each controller: busoff occur
  LastInitObject               last set baudrate for reinit
  LastState                    CAN mode transition request status for each controller
  LogStatus                    CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  ModeTransitionRequest        CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06
  PrevMode                     CAN mode transition request for each controller
  RamCheckTransitionRequest    CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00
  CanInterruptOldStatus        last CAN interrupt status for restore interrupt for each controller
  LoopTimeout                  hw loop timeout for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_PCConfig
**********************************************************************************************************************/
/** 
  \var    Can_PCConfig
  \details
  Element             Description
  SIDFE               the pointer to Can_SIDFE
  XIDFE               the pointer to Can_XIDFE
  IdentitySelected
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_PCConfigsType, CAN_CONST) Can_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_Left] */
      Can_SIDFELeft     /**< the pointer to Can_SIDFELeft */
    , Can_XIDFELeft     /**< the pointer to Can_XIDFELeft */
    , 0u
  },
  { /* Index: 1 Keys: [Config_Right] */
      Can_SIDFERight    /**< the pointer to Can_SIDFERight */
    , Can_XIDFERight    /**< the pointer to Can_XIDFERight */
    , 1u
  }
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/




