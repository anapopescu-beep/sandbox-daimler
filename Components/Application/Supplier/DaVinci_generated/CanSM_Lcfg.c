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
 *            Module: CanSM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanSM_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:05
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/




#define CANSM_LCFG_C


 /**********************************************************************************************************************
 *  Includes
 **********************************************************************************************************************/

#include "CanSM_EcuM.h"



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanSM_ChannelConfigLeft
**********************************************************************************************************************/
/** 
  \var    CanSM_ChannelConfigLeft
  \details
  Element          Description
  NetworkHandle
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanSM_ChannelConfigType, CANSM_CONST) CanSM_ChannelConfigLeft[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    NetworkHandle */
  { /*     0 */            0u }
};
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_ChannelConfigRight
**********************************************************************************************************************/
/** 
  \var    CanSM_ChannelConfigRight
  \details
  Element          Description
  NetworkHandle
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanSM_ChannelConfigType, CANSM_CONST) CanSM_ChannelConfigRight[1] = {  /* PRQA S 1514, 1533, 1504 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ExternalMcData */
    /* Index    NetworkHandle */
  { /*     0 */            1u }
};
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_ChannelVarRecord
**********************************************************************************************************************/
#define CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanSM_ChannelVarRecordType, CANSM_VAR_NOINIT) CanSM_ChannelVarRecord[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanSM_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanSM_PCConfig
  \details
  Element          Description
  ChannelConfig    the pointer to CanSM_ChannelConfig
*/ 
#define CANSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanSM_PCConfigsType, CANSM_CONST) CanSM_PCConfig = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  { /* Index: 0 Keys: [Config_Left] */
      CanSM_ChannelConfigLeft   /**< the pointer to CanSM_ChannelConfigLeft */
  },
  { /* Index: 1 Keys: [Config_Right] */
      CanSM_ChannelConfigRight  /**< the pointer to CanSM_ChannelConfigRight */
  }
};
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




 /**********************************************************************************************************************
 *  VAR DATA PROTOTYPES
 **********************************************************************************************************************/




#define CANSM_START_SEC_VAR_ZERO_INIT_8BIT 
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, CANSM_VAR_ZERO_INIT) CanSM_EnableSetBusSleep[ CANSM_ENABLE_SET_BUS_SLEEP_ARRAY_MAX_SIZE ] =
{
  0u /*  enable CANSM_SET_BUS_SLEEP_MODE  */ 
};

#define CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT 
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/








/* -----------------------------------------------------------------------------
    CanSM Functions
 ----------------------------------------------------------------------------- */

#define CANSM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, CANSM_CODE) CanSM_Dem_ReportErrorEvent(Dem_EventIdType CanSM_EventID, Dem_EventStatusType CanSM_EventStatus)
{
  (void)Dem_ReportErrorStatus( CanSM_EventID, CanSM_EventStatus );
}

#define CANSM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


