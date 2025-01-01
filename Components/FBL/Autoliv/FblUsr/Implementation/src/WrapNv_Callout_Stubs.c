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
 *            Module: WrapNv
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000614_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WrapNv_Callout_Stubs.c
 *   Generation Time: 2022-02-21 15:07:58
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2000614_D04
 *      Tool Version: DaVinci Configurator (beta) 5.24.30 SP1
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

#define WRAPNV_CALLOUT_STUBS_SOURCE

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "WrapNv.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK user_includes> DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#if (WRAPNV_MAINFUNCTION_POLLING == STD_ON)
# include "fbl_inc.h"
#endif /* WRAPNV_MAINFUNCTION_POLLING */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK> DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  USERCALLOUT FUNCTIONS
 *********************************************************************************************************************/

#if (WRAPNV_MAINFUNCTION_POLLING == STD_ON)

# define WRAPNV_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  WrapNv_TriggerFct_Callout
 **********************************************************************************************************************/
/*! \brief       Checks if the millisecond timer is expired
 *  \return      return WRAPNV_E_OK Millisecond timer expired
 *                      WRAPNV_E_NOT_OK Otherwise
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_TriggerFct_Callout( void )
{
   WrapNv_ReturnType result = WRAPNV_E_NOT_OK;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK calloutstub> DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   if((FblLookForWatchdog() & FBL_TM_TRIGGERED ) == FBL_TM_TRIGGERED)
   {
      result = WRAPNV_E_OK;
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK> DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   return result;
}

# define WRAPNV_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* WRAPNV_MAINFUNCTION_POLLING */

/* Unrecognized user block tags */
#if 0
#endif


/**********************************************************************************************************************
  END OF FILE: WrapNv_Callout_Stubs.c
**********************************************************************************************************************/
