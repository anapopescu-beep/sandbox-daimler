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
 *              File: ComM_Lcfg.h
 *   Generation Time: 2023-07-05 16:23:57
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(COMM_LCFG_H)
#define COMM_LCFG_H

/* -----------------------------------------------------------------------------
    &&&~ INCLUDES
 ----------------------------------------------------------------------------- */

#include "ComM_Cfg.h"

/* -----------------------------------------------------------------------------
    &&&~ GLOBAL DATA
 ----------------------------------------------------------------------------- */

#define COMM_START_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_MemMap */ 
#include "ComM_MemMap.h"

extern CONST(ComM_InhibitionStatusType, COMM_CONST) ComM_ECUGroupClassInit;

#define COMM_STOP_SEC_CONST_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_MemMap */ 
#include "ComM_MemMap.h"

/* PRQA S 3451, 3449 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */ 
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
extern CONST(ComM_PCConfigsType, COMM_CONST) ComM_PCConfig;
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
extern CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRBTM_FL[1];
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
extern CONST(ComM_PCPartitionConfigType, COMM_CONST) ComM_PCPartitionConfigRBTM_FR[1];
#define COMM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "ComM_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/* PRQA L:EXTERNDECLARATIONS */

#define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"

/* -----------------------------------------------------------------------------
    &&&~ GLOBAL FUNCTION PROTOTYPES
 ----------------------------------------------------------------------------- */

 /* PRQA S 3451, 3449 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */ 
/*********************************************************************************************************************
FUNCTION: ComM_MainFunction_0
*********************************************************************************************************************/
/*! \brief       Calls ComM_MainFunction() for the corresponding channel. This function is called by RTE with the 
 *               configured channel-specific Main Function Period
 *  \pre         ComM must be initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_MainFunction_0(void);
/* PRQA L:EXTERNDECLARATIONS */

 /* PRQA S 3451, 3449 EXTERNDECLARATIONS */ /* MD_ComM_3451_3449 */ 
/*********************************************************************************************************************
FUNCTION: ComM_MainFunction_1
*********************************************************************************************************************/
/*! \brief       Calls ComM_MainFunction() for the corresponding channel. This function is called by RTE with the 
 *               configured channel-specific Main Function Period
 *  \pre         ComM must be initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_MainFunction_1(void);
/* PRQA L:EXTERNDECLARATIONS */

/* -----------------------------------------------------------------------------
    &&&~ INTERNAL GENERATED FUNCTION PROTOTYPES
 ----------------------------------------------------------------------------- */


#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "ComM_MemMap.h"


#endif /* COMM_LCFG_H */

