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
 *            Module: BswM
 *           Program: 
 *          Customer: 
 *       Expiry Date: 2023-04-09
 *    License Scope : The usage is restricted to PAI194
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: BswM_Callout_Stubs.c
 *   Generation Time: 2021-06-10 20:28:39
 *           Project: StartApplication - Version 1.0
 *          Delivery: PAI194
 *      Tool Version: DaVinci Configurator (beta) 5.23.10 S-3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
#define BSWM_CALLOUT_STUBS_SOURCE
#include "BswM.h"
#include "BswM_Private_Cfg.h"
#include "CanNm.h"
#include "NvM.h"
#include "SchM_Fee.h"
#include "SchM_Fls_17_Dmu.h"
#include "MemIf_Types.h"
#include "SBC.h"
#include "Nvp_Generated.h"
/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ECU_SIDE_RBTM_FR (0x99u)

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_AL_SetProgrammableInterrupts(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  uint32 i;

  for (i = 0; i < OS_ISRID_COUNT; i++)
  {
    Os_EnableInterruptSource(i, FALSE);
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_AL_SetProgrammableInterrupts */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPostRun(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPostRun>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPostRun */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterPrepShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterPrepShutdown>           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterPrepShutdown */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterRun(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterRun>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  
} /* End of BswM_ESH_OnEnterRun */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterShutdown(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterShutdown>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  uint8 RequestResultPtr;

  NvM_WriteAll();
  do
    {
      NvM_MainFunction();
      Fee_MainFunction();
      Fls_17_Dmu_MainFunction();
      NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &RequestResultPtr);
    } while (RequestResultPtr == NVM_REQ_PENDING);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterShutdown */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWaitForNvm(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWaitForNvm>             DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterWaitForNvm */


FUNC(void, BSWM_CODE) BswM_ESH_OnEnterWakeup(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_ESH_OnEnterWakeup>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

  EcuM_WakeupSourceType locWakeupSource = 0;

  if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
  {
      locWakeupSource = locWakeupSource | ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727;
  }
  else
  {
      locWakeupSource = locWakeupSource | ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6;
  }

  EcuM_CheckWakeup(locWakeupSource);

  /* Set Controller mode to START so Appl_GenericPrecopy callback will be called(in order to set wake up event) */
  Can_SetControllerMode(0, CAN_T_WAKEUP);
  Can_SetControllerMode(0, CAN_T_START);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_ESH_OnEnterWakeup */


FUNC(void, BSWM_CODE) BswM_INIT_NvMReadAll(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK BswM_INIT_NvMReadAll>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
    uint8 RequestResultPtr;

    while(Fee_GetStatus() != MEMIF_IDLE)
    {
      Fee_MainFunction();
      Fls_17_Dmu_MainFunction();
    }

    NvM_ReadAll();
    do
    {
      NvM_MainFunction();
      Fee_MainFunction();
      Fls_17_Dmu_MainFunction();
      NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &RequestResultPtr);
    } while (RequestResultPtr == NVM_REQ_PENDING);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

} /* End of BswM_INIT_NvMReadAll */


FUNC(void, BSWM_CODE) ESH_ComM_CheckPendingRequests_Left(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_ComM_CheckPendingRequests>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  ComM_StateType RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 = COMM_NO_COM_NO_PENDING_REQUEST;
  
  (void)ComM_GetState(ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, &RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6); /* SBSW_BSWM_FCTCALL_LOCALVAR */
  
  if(RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 != COMM_NO_COM_NO_PENDING_REQUEST)
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST);
  }
  else
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST);
  }
  
} /* End of ESH_ComM_CheckPendingRequests */

FUNC(void, BSWM_CODE) ESH_ComM_CheckPendingRequests_Right(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_ComM_CheckPendingRequests>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  ComM_StateType RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 = COMM_NO_COM_NO_PENDING_REQUEST;

  (void)ComM_GetState(ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, &RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727); /* SBSW_BSWM_FCTCALL_LOCALVAR */

  if(RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727 != COMM_NO_COM_NO_PENDING_REQUEST)
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_PENDING_REQUEST);
  }
  else
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_ComMPendingRequests, BSWM_GENERICVALUE_ESH_ComMPendingRequests_ESH_COMM_NO_REQUEST);
  }

} /* End of ESH_ComM_CheckPendingRequests */


FUNC(void, BSWM_CODE) ESH_Dem_PostRunRequested_Left(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_Dem_PostRunRequested_Left>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  boolean isRequested = FALSE;
  (void)Dem_PostRunRequested(&isRequested); /* SBSW_BSWM_FCTCALL_LOCALVAR */
  if (isRequested == TRUE)
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_DemPostRunRequested, BSWM_GENERICVALUE_ESH_DemPostRunRequested_TRUE);
  }
  else
  {
    BswM_RequestMode(BSWM_GENERIC_ESH_DemPostRunRequested, BSWM_GENERICVALUE_ESH_DemPostRunRequested_FALSE);
  }
  
} /* End of ESH_Dem_PostRunRequested */

FUNC(void, BSWM_CODE) ESH_Dem_PostRunRequested_Right(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK ESH_Dem_PostRunRequested_Right>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  ESH_Dem_PostRunRequested_Left();

} /* End of ESH_Dem_PostRunRequested */


#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: BSWM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


