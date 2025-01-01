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
 *            Module: Nm
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Nm_Cfg.c
 *   Generation Time: 2023-07-10 14:36:13
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define NM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nm_Cfg.h"


#include "ComM.h"
#include "CanNm.h"
#include "App_Nm.h"
#include "Cdd_MBBL_EcuStatHandler.h"
#include "Rtm.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
/* (NM_SYSTONMCHIND == STD_ON) If the number of system channels is not equal to the number of NM channels,
 * channel indirection is needed. Otherwise, the channel index is equals to the network handler. */
# if ( NM_SYSTONMCHIND == STD_ON )
#  define NM_CHANNEL_IDX                          Nm_GetSysToNmChInd(nmNetworkHandle)
# else
#  define NM_CHANNEL_IDX                          nmNetworkHandle
# endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
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
  Nm_CarWakeUpCallbackFctPtr
**********************************************************************************************************************/
/** 
  \var    Nm_CarWakeUpCallbackFctPtr
  \brief  Car Wake Up Callback
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_CallbackFunction, NM_CONST) Nm_CarWakeUpCallbackFctPtr = NULL_PTR;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_ChannelConfigLeft
**********************************************************************************************************************/
/** 
  \var    Nm_ChannelConfigLeft
  \brief  Structure for channel specific configuration parameters
  \details
  Element               Description
  NmChannelId       
  NmFunctionTableIdx    the index of the 1:1 relation pointing to Nm_NmFunctionTable
  PartitionConfigIdx    the index of the 1:1 relation pointing to Nm_PCPartitionConfig
  PduRxIndication   
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_ChannelConfigType, NM_CONST) Nm_ChannelConfigLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    NmChannelId                                                            NmFunctionTableIdx  PartitionConfigIdx  PduRxIndication        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6,                 0u,                 0u, NULL_PTR        }   /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}] */
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_ChannelConfigRight
**********************************************************************************************************************/
/** 
  \var    Nm_ChannelConfigRight
  \brief  Structure for channel specific configuration parameters
  \details
  Element               Description
  NmChannelId       
  NmFunctionTableIdx    the index of the 1:1 relation pointing to Nm_NmFunctionTable
  PartitionConfigIdx    the index of the 1:1 relation pointing to Nm_PCPartitionConfig
  PduRxIndication   
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_ChannelConfigType, NM_CONST) Nm_ChannelConfigRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    NmChannelId                                                            NmFunctionTableIdx  PartitionConfigIdx  PduRxIndication        Referable Keys */
  { /*     0 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727,                 0u,                 0u, NULL_PTR        }   /* [/ActiveEcuC/ComM/ComMConfigSet/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}] */
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_NmFunctionTable
**********************************************************************************************************************/
/** 
  \var    Nm_NmFunctionTable
  \details
  Element                       Description
  CheckRemoteSleepIndication
  GetState                  
  DisableCommunication      
  EnableCommunication       
  NetworkRelease            
  NetworkRequest            
  PassiveStartUp            
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_NmFunctionTableType, NM_CONST) Nm_NmFunctionTable[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CheckRemoteSleepIndication        GetState        DisableCommunication        EnableCommunication        NetworkRelease        NetworkRequest        PassiveStartUp              Referable Keys */
  { /*     0 */ CanNm_CheckRemoteSleepIndication, CanNm_GetState, CanNm_DisableCommunication, CanNm_EnableCommunication, CanNm_NetworkRelease, CanNm_NetworkRequest, CanNm_PassiveStartUp }   /* [CanNm] */
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    Nm_PartitionIdentifiers
  \brief  the partition context in Config_Left
  \details
  Element                 Description
  PartitionSNV        
  PCPartitionConfigIdx    the index of the 1:1 relation pointing to Nm_PCPartitionConfig
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_PartitionIdentifiersType, NM_CONST) Nm_PartitionIdentifiers[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionSNV         PCPartitionConfigIdx */
  { /*     0 */ NM_SINGLE_PARTITION,                   0u }
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_SysToNmChInd
**********************************************************************************************************************/
/** 
  \var    Nm_SysToNmChInd
  \brief  Channel indirection: System Channel handle to NM channel handle
*/ 
#define NM_START_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_SysToNmChIndType, NM_CONST) Nm_SysToNmChInd[2] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
  /* Index     SysToNmChInd        */
  /*     0 */  NM_NO_SYSTONMCHIND,
  /*     1 */                  0u
};
#define NM_STOP_SEC_CONST_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_Initialized
**********************************************************************************************************************/
/** 
  \var    Nm_Initialized
  \brief  Initialized state
*/ 
#define NM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Nm_InitializedType, NM_VAR_NO_INIT) Nm_Initialized;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define NM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PostInitialized
**********************************************************************************************************************/
/** 
  \var    Nm_PostInitialized
  \brief  Post-Initialized state
*/ 
#define NM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Nm_PostInitializedType, NM_VAR_NO_INIT) Nm_PostInitialized[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define NM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PCConfig
**********************************************************************************************************************/
/** 
  \var    Nm_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to Nm_PCPartitionConfig
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_PCConfigsType, NM_CONST) Nm_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_Left] */
      Nm_PCPartitionConfigLeft   /**< the pointer to Nm_PCPartitionConfig in Config_Left */
  },
  { /* Index: 1 Keys: [Config_Right] */
      Nm_PCPartitionConfigRight  /**< the pointer to Nm_PCPartitionConfig in Config_Right */
  }
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PCPartitionConfigLeft
**********************************************************************************************************************/
/** 
  \var    Nm_PCPartitionConfigLeft
  \details
  Element               Description
  ChannelConfig         the pointer to Nm_ChannelConfig
  SysToNmChInd          the pointer to Nm_SysToNmChInd
  SizeOfSysToNmChInd    the number of accomplishable value elements in Nm_SysToNmChInd
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_PCPartitionConfigType, NM_CONST) Nm_PCPartitionConfigLeft[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [NM_SINGLE_PARTITION] */
      Nm_ChannelConfigLeft     /**< the pointer to Nm_ChannelConfig in Config_Left */
    , (&(Nm_SysToNmChInd[1]))  /**< the pointer to Nm_SysToNmChInd in Config_Left */
    , 1u                       /**< the number of elements in Nm_SysToNmChInd in Config_Left */
  }
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Nm_PCPartitionConfigRight
**********************************************************************************************************************/
/** 
  \var    Nm_PCPartitionConfigRight
  \details
  Element               Description
  ChannelConfig         the pointer to Nm_ChannelConfig
  SysToNmChInd          the pointer to Nm_SysToNmChInd
  SizeOfSysToNmChInd    the number of accomplishable value elements in Nm_SysToNmChInd
*/ 
#define NM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Nm_PCPartitionConfigType, NM_CONST) Nm_PCPartitionConfigRight[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [NM_SINGLE_PARTITION] */
      Nm_ChannelConfigRight  /**< the pointer to Nm_ChannelConfig in Config_Right */
    , Nm_SysToNmChInd        /**< the pointer to Nm_SysToNmChInd in Config_Right */
    , 2u                     /**< the number of elements in Nm_SysToNmChInd in Config_Right */
  }
};
#define NM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Nm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



#if ( NM_USE_INIT_POINTER == STD_ON )
# define NM_START_SEC_VAR_INIT_UNSPECIFIED
# include "Nm_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Pointer to Postbuild configuration */
P2CONST(Nm_ConfigType, NM_VAR_INIT, NM_CONST) Nm_ConfigPtr = NULL_PTR;

# define NM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "Nm_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

 

/**********************************************************************************************************************
 *  END OF FILE: Nm_Cfg.c
 *********************************************************************************************************************/

