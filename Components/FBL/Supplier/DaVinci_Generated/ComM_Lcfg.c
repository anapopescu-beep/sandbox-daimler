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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_Lcfg.c
 *   Generation Time: 2023-07-05 16:23:57
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
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


#include "Det.h"
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
  ComM_ChannelRBTM_FL
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelRBTM_FL
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
CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelRBTM_FL[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Enabled  NmType                                         GetCurrentBusSMModeApi   RequestBusSMModeApi         Referable Keys */
  { /*     0 */    TRUE,                     COMM_NONE_NMTYPEOFCHANNEL, CanSM_GetCurrentComMode, CanSM_RequestComMode },  /* [ComMChannel_0] */
  { /*     1 */   FALSE, COMM_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL, NULL_PTR               , NULL_PTR             }   /* [ComMChannel_1] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelRBTM_FR
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelRBTM_FR
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
CONST(ComM_ChannelType, COMM_CONST) ComM_ChannelRBTM_FR[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Enabled  NmType                                         GetCurrentBusSMModeApi   RequestBusSMModeApi         Referable Keys */
  { /*     0 */   FALSE, COMM_NOT_USED_IN_THIS_VARIANT_NMTYPEOFCHANNEL, NULL_PTR               , NULL_PTR             },  /* [ComMChannel_0] */
  { /*     1 */    TRUE,                     COMM_NONE_NMTYPEOFCHANNEL, CanSM_GetCurrentComMode, CanSM_RequestComMode }   /* [ComMChannel_1] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbRBTM_FL
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbRBTM_FL
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbRBTM_FL[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    UserReqFullComEndIdx                     UserReqFullComStartIdx                    */
  { /*     0 */                                      1u,                                        0u },
  { /*     1 */ COMM_NO_USERREQFULLCOMENDIDXOFCHANNELPB, COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_ChannelPbRBTM_FR
**********************************************************************************************************************/
/** 
  \var    ComM_ChannelPbRBTM_FR
  \brief  Contains PostBuild configuration parameters of channels
  \details
  Element                   Description
  UserReqFullComEndIdx      the end index of the 0:n relation pointing to ComM_UserReqFullCom
  UserReqFullComStartIdx    the start index of the 0:n relation pointing to ComM_UserReqFullCom
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_ChannelPbType, COMM_CONST) ComM_ChannelPbRBTM_FR[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    UserReqFullComEndIdx                     UserReqFullComStartIdx                    */
  { /*     0 */ COMM_NO_USERREQFULLCOMENDIDXOFCHANNELPB, COMM_NO_USERREQFULLCOMSTARTIDXOFCHANNELPB },
  { /*     1 */                                      1u,                                        0u }
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
  \brief  the partition context in Config_RBTM_FL
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
  ComM_User
**********************************************************************************************************************/
/** 
  \var    ComM_User
  \brief  Information about ComM users
  \details
  Element    Description
  PncUser    decides if a user is a partial network user or a direct channel user
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_UserType, COMM_CONST) ComM_User[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PncUser        Comment */
  { /*     0 */   FALSE }   /* [RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_a4eabb6e] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskRBTM_FL
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskRBTM_FL
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element    Description
  Channel    ID of the channel which is requested by this entry.
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskRBTM_FL[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Channel        Referable Keys */
  { /*     0 */      0u }   /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_a4eabb6e{RBTM_FL}] */
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_UserByteMaskRBTM_FR
**********************************************************************************************************************/
/** 
  \var    ComM_UserByteMaskRBTM_FR
  \brief  Each user has N entries in this array (N = # channels attached to this user, directly or through PNC). Each entry describes a Byte Position and a Mask for storing/clearing the user request in UserReqFullCom
  \details
  Element    Description
  Channel    ID of the channel which is requested by this entry.
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_UserByteMaskType, COMM_CONST) ComM_UserByteMaskRBTM_FR[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Channel        Referable Keys */
  { /*     0 */      1u }   /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_1f2180a7{RBTM_FR}] */
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
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

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
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
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
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   RBTM_FR */
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
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   RBTM_FR */
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
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [ComMChannel_0] */
  /*     1 */  /* [ComMChannel_1] */

#define COMM_STOP_SEC_VAR_NO_INIT_8
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
  /* Index        Referable Keys   RBTM_FL */
  /*     0 */  /* [ComMChannel_0, Channel0_To_User0] */
  /* Index        Referable Keys   RBTM_FR */
  /*     0 */  /* [ComMChannel_1, Channel1_To_User0] */

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
  { /* Index: 0 Keys: [Config_RBTM_FL] */
      ComM_PCPartitionConfigRBTM_FL  /**< the pointer to ComM_PCPartitionConfig in Config_RBTM_FL */
  },
  { /* Index: 1 Keys: [Config_RBTM_FR] */
      ComM_PCPartitionConfigRBTM_FR  /**< the pointer to ComM_PCPartitionConfig in Config_RBTM_FR */
  }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigRBTM_FL
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigRBTM_FL
  \details
  Element         Description
  Channel         the pointer to ComM_Channel
  ChannelPb       the pointer to ComM_ChannelPb
  UserByteMask    the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRBTM_FL[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [COMM_SINGLEPARTITION] */
      ComM_ChannelRBTM_FL       /**< the pointer to ComM_Channel in Config_RBTM_FL */
    , ComM_ChannelPbRBTM_FL     /**< the pointer to ComM_ChannelPb in Config_RBTM_FL */
    , ComM_UserByteMaskRBTM_FL  /**< the pointer to ComM_UserByteMask in Config_RBTM_FL */
  }
};
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  ComM_PCPartitionConfigRBTM_FR
**********************************************************************************************************************/
/** 
  \var    ComM_PCPartitionConfigRBTM_FR
  \details
  Element         Description
  Channel         the pointer to ComM_Channel
  ChannelPb       the pointer to ComM_ChannelPb
  UserByteMask    the pointer to ComM_UserByteMask
*/ 
#define COMM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRBTM_FR[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [COMM_SINGLEPARTITION] */
      ComM_ChannelRBTM_FR       /**< the pointer to ComM_Channel in Config_RBTM_FR */
    , ComM_ChannelPbRBTM_FR     /**< the pointer to ComM_ChannelPb in Config_RBTM_FR */
    , ComM_UserByteMaskRBTM_FR  /**< the pointer to ComM_UserByteMask in Config_RBTM_FR */
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

CONST(ComM_InhibitionStatusType, COMM_CONST) ComM_ECUGroupClassInit = 0x0; /* PRQA S 1533 */ /* MD_ComM_1533 */


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


#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"

