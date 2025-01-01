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
 *            Module: EcuM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Cfg.c
 *   Generation Time: 2023-08-03 15:16:14
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/




/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* PRQA S 0310 EOF */ /* MD_CSL_0310 */
#include "EcuM_Cbk.h"

#define ECUM_PRIVATE_CFG_PARTLY_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_PARTLY_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */

#if((ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) ||(ECUM_PNCOFCOMMPNCS == STD_ON) || (ECUM_SUPPORT_COMM == STD_ON))
#include "ComM.h"
#endif

#if !defined (ECUM_LOCAL) /* COV_ECUM_LOCAL */
# define ECUM_LOCAL static
#endif

#if !defined (ECUM_LOCAL_INLINE) /* COV_ECUM_LOCAL_INLINE */
# define ECUM_LOCAL_INLINE LOCAL_INLINE
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
  EcuM_DriverInitOneLeft
**********************************************************************************************************************/
/** 
  \var    EcuM_DriverInitOneLeft
  \details
  Element     Description
  Function
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverInitOneType, ECUM_CONST) EcuM_DriverInitOneLeft[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Function                   */
  { /*     0 */ EcuM_AL_DriverInitOne_Left }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOneRight
**********************************************************************************************************************/
/** 
  \var    EcuM_DriverInitOneRight
  \details
  Element     Description
  Function
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_DriverInitOneType, ECUM_CONST) EcuM_DriverInitOneRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Function                    */
  { /*     0 */ EcuM_AL_DriverInitOne_Right }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_WakeupSourceListLeft
**********************************************************************************************************************/
/** 
  \var    EcuM_WakeupSourceListLeft
  \brief  Contains all parameters configured for Wakeup Sources
  \details
  Element    Description
  Channel    Mapped ComM channel number - 255 if no ComM channel is assigned.
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_WakeupSourceListType, ECUM_CONST) EcuM_WakeupSourceListLeft[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Channel                                                                      Comment                                                        Referable Keys */
  { /*     0 */ 255                                                                   },  /* [ECUM_WKSOURCE_POWER]                              */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_POWER, ECUM_WKSOURCE_POWER] */
  { /*     1 */ 255                                                                   },  /* [ECUM_WKSOURCE_RESET]                              */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_RESET, ECUM_WKSOURCE_RESET] */
  { /*     2 */ 255                                                                   },  /* [ECUM_WKSOURCE_INTERNAL_RESET]                     */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_RESET, ECUM_WKSOURCE_INTERNAL_RESET] */
  { /*     3 */ 255                                                                   },  /* [ECUM_WKSOURCE_INTERNAL_WDG]                       */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_WDG, ECUM_WKSOURCE_INTERNAL_WDG] */
  { /*     4 */ 255                                                                   },  /* [ECUM_WKSOURCE_EXTERNAL_WDG]                       */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_EXTERNAL_WDG, ECUM_WKSOURCE_EXTERNAL_WDG] */
  { /*     5 */ ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 }   /* [RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6{Left}, RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6] */
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_WakeupSourceListRight
**********************************************************************************************************************/
/** 
  \var    EcuM_WakeupSourceListRight
  \brief  Contains all parameters configured for Wakeup Sources
  \details
  Element    Description
  Channel    Mapped ComM channel number - 255 if no ComM channel is assigned.
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_WakeupSourceListType, ECUM_CONST) EcuM_WakeupSourceListRight[6] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    Channel                                                                      Comment                                                        Referable Keys */
  { /*     0 */ 255                                                                   },  /* [ECUM_WKSOURCE_POWER]                              */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_POWER, ECUM_WKSOURCE_POWER] */
  { /*     1 */ 255                                                                   },  /* [ECUM_WKSOURCE_RESET]                              */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_RESET, ECUM_WKSOURCE_RESET] */
  { /*     2 */ 255                                                                   },  /* [ECUM_WKSOURCE_INTERNAL_RESET]                     */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_RESET, ECUM_WKSOURCE_INTERNAL_RESET] */
  { /*     3 */ 255                                                                   },  /* [ECUM_WKSOURCE_INTERNAL_WDG]                       */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_INTERNAL_WDG, ECUM_WKSOURCE_INTERNAL_WDG] */
  { /*     4 */ 255                                                                   },  /* [ECUM_WKSOURCE_EXTERNAL_WDG]                       */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/ECUM_WKSOURCE_EXTERNAL_WDG, ECUM_WKSOURCE_EXTERNAL_WDG] */
  { /*     5 */ ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 }   /* [RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */  /* [/ActiveEcuC/EcuM/EcuMConfiguration/EcuMCommonConfiguration/RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727{Right}, RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727] */
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_BswMCurrentModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_NO_INIT) EcuM_BswMCurrentModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_BswMRequestedModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_NO_INIT) EcuM_BswMRequestedModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_ModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_StateType, ECUM_VAR_NO_INIT) EcuM_ModuleState;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PostRunRequestCounter
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_PostRunRequestCounterType, ECUM_VAR_NO_INIT) EcuM_PostRunRequestCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_RunRequestCounter
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(EcuM_RunRequestCounterType, ECUM_VAR_NO_INIT) EcuM_RunRequestCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define ECUM_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PCConfig
**********************************************************************************************************************/
/** 
  \var    EcuM_PCConfig
  \details
  Element             Description
  DriverInitOne       the pointer to EcuM_DriverInitOne
  WakeupSourceList    the pointer to EcuM_WakeupSourceList
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(EcuM_PCConfigsType, ECUM_CONST) EcuM_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_Left] */
      EcuM_DriverInitOneLeft      /**< the pointer to EcuM_DriverInitOne in Config_Left */
    , EcuM_WakeupSourceListLeft   /**< the pointer to EcuM_WakeupSourceList in Config_Left */
  },
  { /* Index: 1 Keys: [Config_Right] */
      EcuM_DriverInitOneRight     /**< the pointer to EcuM_DriverInitOne in Config_Right */
    , EcuM_WakeupSourceListRight  /**< the pointer to EcuM_WakeupSourceList in Config_Right */
  }
};
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "EcuM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




