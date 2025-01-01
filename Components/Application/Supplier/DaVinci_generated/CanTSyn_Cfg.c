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
 *            Module: CanTSyn
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTSyn_Cfg.c
 *   Generation Time: 2023-07-10 14:36:04
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define CANTSYN_CFG_SOURCE

/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "CanTSyn.h"
#include "StbM.h"

#include "CanIf.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/* Dummy define for partition name in non multi-core/multi-partition context */
# define CANTSYN_SINGLEPARTITION                           (0u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTSyn_DomainConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_DomainConfig
  \brief  Table containing data about the time domain.
  \details
  Element                   Description
  CrcAndDomainType          Sets the domain to crc supported if it contains a master that supports txCrc.
  DomainId                  Domain Id
  FupDataIDListEndIdx       the end index of the 0:n relation pointing to CanTSyn_FupDataIDList
  FupDataIDListStartIdx     the start index of the 0:n relation pointing to CanTSyn_FupDataIDList
  MessageDlc                Indicates if the Extended Message Format for CAN-FD is used.
  OffsetDomain              Sets the domain to supported is domain transmits offset message.
  SlaveConfigIdx            the index of the 0:1 relation pointing to CanTSyn_SlaveConfig
  SyncDataIDListEndIdx      the end index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  SyncDataIDListStartIdx    the start index of the 0:n relation pointing to CanTSyn_SyncDataIDList
  TimeBaseId                Mandatory reference to the required synchronized time-base.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_DomainConfigType, CANTSYN_CONST) CanTSyn_DomainConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CrcAndDomainType                                     DomainId  FupDataIDListEndIdx                                                  FupDataIDListStartIdx                                                  MessageDlc  OffsetDomain                                   SlaveConfigIdx                                                  SyncDataIDListEndIdx                                                  SyncDataIDListStartIdx                                                  TimeBaseId                                                    Referable Keys */
  { /*     0 */ CANTSYN_NOT_CRC_SYNC_CRCANDDOMAINTYPEOFDOMAINCONFIG,       0u,                 16u  /* /ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11 */,                    0u  /* /ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11 */,         8u, CANTSYN_NOT_OFFSET_OFFSETDOMAINOFDOMAINCONFIG,             0u  /* /ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11 */,                  16u  /* /ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11 */,                     0u  /* /ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11 */, StbMConf_StbMSynchronizedTimeBase_GTD_BODY3_0_14e64f11 }   /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_FupDataIDList
**********************************************************************************************************************/
/** 
  \var    CanTSyn_FupDataIDList
  \brief  Element of the DataIDList for FUP/OFNS messages ensures the identification of data elements due to CRC calculation process.
*/ 
#define CANTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_FupDataIDListType, CANTSYN_CONST) CanTSyn_FupDataIDList[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     FupDataIDList      Referable Keys */
  /*     0 */           143u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     1 */            78u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     2 */            13u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     3 */           199u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     4 */           134u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     5 */            69u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     6 */             4u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     7 */           190u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     8 */           125u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     9 */            60u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    10 */           246u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    11 */           181u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    12 */           116u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    13 */            51u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    14 */           237u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    15 */           172u   /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
};
#define CANTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    CanTSyn_PartitionIdentifiers
  \brief  the partition context in Config
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_PartitionIdentifiersType, CANTSYN_CONST) CanTSyn_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV             PCPartitionConfigIdx                                */
  { /*     0 */ CANTSYN_SINGLEPARTITION,                   0u  /* CANTSYN_SINGLEPARTITION */ }
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SlaveConfig
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SlaveConfig
  \brief  Contains configuration parameters of slave.
  \details
  Element                     Description
  DomainConfigIdx             the index of the 1:1 relation pointing to CanTSyn_DomainConfig
  FollowUpTimeout             Rx timeout for the follow-up message. This is only relevant for selected bus systems.
  PartitionConfigIdx          the index of the 1:1 relation pointing to CanTSyn_PCPartitionConfig
  RxCrcValidated              Validation of the CRC is supported or not
  SequenceCounterJumpWidth    The SequenceCounterJumpWidth specifies the maximum allowed gap of the sequence counter between two SYNC resp. two OFS messages.
  SlaveHandleId               This represents the handle ID of the PDU that contains the global time information.
*/ 
#define CANTSYN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_SlaveConfigType, CANTSYN_CONST) CanTSyn_SlaveConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DomainConfigIdx                                                  FollowUpTimeout  PartitionConfigIdx                                 RxCrcValidated                                 SequenceCounterJumpWidth  SlaveHandleId                                                             Referable Keys */
  { /*     0 */              0u  /* /ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11 */,             50u,                 0u  /* CANTSYN_SINGLEPARTITION */, CANTSYN_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG,                       3u, CanTSynConf_CanTSynGlobalTimeSlavePdu_GTS_Main_CAN_ST3_dd88dcd5_Rx }   /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
};
#define CANTSYN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SyncDataIDList
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SyncDataIDList
  \brief  Element of the DataIDList for SYNC/OFS messages ensures the identification of data elements due to CRC calculation process.
*/ 
#define CANTSYN_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanTSyn_SyncDataIDListType, CANTSYN_CONST) CanTSyn_SyncDataIDList[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SyncDataIDList      Referable Keys */
  /*     0 */            225u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     1 */            102u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     2 */            230u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     3 */            107u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     4 */            235u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     5 */            112u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     6 */            240u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     7 */            117u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     8 */            245u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*     9 */            122u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    10 */            250u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    11 */            127u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    12 */              4u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    13 */            132u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    14 */              9u,  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
  /*    15 */            137u   /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */
};
#define CANTSYN_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_Initialized
**********************************************************************************************************************/
/** 
  \var    CanTSyn_Initialized
  \brief  Initialization state of the CanTSyn. TRUE, if CanTSyn_Init() has been called, else FALSE.
*/ 
#define CANTSYN_START_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTSyn_InitializedType, CANTSYN_VAR_CLEARED) CanTSyn_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANTSYN_STOP_SEC_VAR_CLEARED_8
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTSyn_SlaveState
**********************************************************************************************************************/
/** 
  \var    CanTSyn_SlaveState
  \details
  Element                   Description
  RxFollowUpTimeoutCount    Count of number of Rx timeouts for follow-up messages.
  RxSequenceCounter         Sequence counter for Rx messages.
  State                     State of the slave
  SyncMsg                   This represents the synchronized message type.
  VirtualLocalTime          This represents Virtual Local Time value from StbM.
*/ 
#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanTSyn_SlaveStateUType, CANTSYN_VAR_NO_INIT) CanTSyn_SlaveState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanTSyn/GTD_BODY3_0_14e64f11] */

#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanTSyn_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#define CANTSYN_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTSyn_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

VAR(boolean, CANTSYN_VAR_NO_INIT) CanTSyn_PreInitialized;

#define CANTSYN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTSyn_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: CanTSyn_Cfg.c
 *********************************************************************************************************************/
