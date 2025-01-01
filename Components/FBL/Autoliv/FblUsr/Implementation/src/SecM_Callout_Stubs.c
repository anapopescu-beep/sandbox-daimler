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
 *            Module: Smh
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000614_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecM_Callout_Stubs.c
 *   Generation Time: 2020-10-22 10:07:17
 *           Project: CBD2000614_Upd - Version 1.0
 *          Delivery: CBD2000614_D00
 *      Tool Version: DaVinci Configurator (beta) 5.22.35 SP1
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


#define SMH_CALLOUT_STUBS_SOURCE


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "ESLib_RNG.h"

/**********************************************************************************************************************
 *  USERCALLOUT FUNCTIONS
 *********************************************************************************************************************/

FUNC(eslt_ErrorCode, VSECPRIM_CODE) esl_getBytesRNG(const eslt_Length targetLength, P2VAR(eslt_Byte, AUTOMATIC, VSECPRIM_APPL_VAR) target)
{
   eslt_ErrorCode retVal = ESL_ERC_ERROR;

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK esl_getBytesRNG> DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   if (targetLength > 0u)
   {
      target[0u] = 0x00u;
   }

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK> DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   return retVal;
}

/* Unrecognized user block tags */
#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: SecM_Callout_Stubs.c
 *********************************************************************************************************************/
