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
 *            Module: WdgIf
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgIf_Lcfg.c
 *   Generation Time: 2023-07-10 14:36:13
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define WDGIF_LCFG_C


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Wdg_17_Scu.h" 
#include "WdgIf_Lcfg.h" 
#include "WdgIf.h" 


/**********************************************************************************************************************
 *  VERSION INFORMATION AND CHECK
 *********************************************************************************************************************/
#define WDGIF_LCFG_C_MAJOR_VERSION (2u) 
#define WDGIF_LCFG_C_MINOR_VERSION (3u) 
#define WDGIF_LCFG_C_PATCH_VERSION (1u) 

/* Check the version of WdgIf header file */
#if ( (WDGIF_SW_MAJOR_VERSION != (5u)) \
   || (WDGIF_SW_MINOR_VERSION != (5u)) )
# error "Version numbers of WdgIf_Lcfg.c and WdgIf.h are inconsistent!"
#endif

/* Check the version of WdgIf_Lcfg header file */
#if ( (WDGIF_LCFG_MAJOR_VERSION != WDGIF_LCFG_C_MAJOR_VERSION) \
   || (WDGIF_LCFG_MINOR_VERSION != WDGIF_LCFG_C_MINOR_VERSION) \
   || (WDGIF_LCFG_PATCH_VERSION != WDGIF_LCFG_C_PATCH_VERSION) )
# error "Version numbers of WdgIf_Lcfg.c and WdgIf_Lcfg.h are inconsistent!"
#endif

#if !defined (WDGIF_LOCAL) /* COV_WDGIF_COMPATIBILITY */
# define WDGIF_LOCAL static
#endif

#define WDGIF_START_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

WDGIF_LOCAL const WdgIf_InterfaceFunctionsType wdgifdevice_functions = 
{
  Wdg_17_Scu_SetMode /*  Wdg_SetMode  */ , 
  Wdg_17_Scu_SetTriggerCondition /*  Wdg_SetTriggerCondition  */ 
}; /* WdgGeneral */ 


WDGIF_LOCAL const WdgIf_InterfaceFunctionsPerWdgDeviceType WdgIf_FunctionsPerWdg [WDGIF_NUMBER_OF_WDGIFDEVICES] =
{
  {
    &wdgifdevice_functions /*  WdgFunctions  */ 
  } /*  [0]  */ 
};

const WdgIf_InterfaceType WdgIf_Interface =
{
  WDGIF_NUMBER_OF_WDGIFDEVICES /*  NumOfWdgs  */ , 
  WdgIf_FunctionsPerWdg /*  WdgFunctionsPerDevice  */ 
};

#define WDGIF_STOP_SEC_CONST_UNSPECIFIED 
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
  MD_WdgIf_1297: rule 10.3
    Reason:     In case OSSpinlock is used there is the possibility to define explicit the ID which will be forwarded.
                In this case the forwarded OSSpinlock ID is of integer type instead of an OS provided enum type.
    Risk:       None
    Prevention: User must ensure that the explicit configured ID will match with the related OS Spinlock ID (Safety-Manual Item: SMI-522).

*/

/**********************************************************************************************************************
 *  END OF FILE: WdgIf_Lcfg.c
 *********************************************************************************************************************/

