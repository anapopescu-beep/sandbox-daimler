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
 *              File: WdgIf_Cfg_Features.h
 *   Generation Time: 2023-07-10 14:36:13
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (WDGIF_CFG_FEATURES_H)
# define WDGIF_CFG_FEATURES_H
 
/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
# define WDGIF_CFG_FEATURE_MAJOR_VERSION (2u) 
# define WDGIF_CFG_FEATURE_MINOR_VERSION (3u) 
# define WDGIF_CFG_FEATURE_PATCH_VERSION (1u) 


/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CONSTANT MACROS
 *********************************************************************************************************************/
# define WDGIF_VERSION_INFO_API                  STD_OFF
# define WDGIF_DEV_ERROR_DETECT                  STD_ON
# define WDGIF_USE_STATECOMBINER                 STD_OFF

# if (WDGIF_DEV_ERROR_DETECT == STD_ON)
/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#  define WdgIf_ReportDet(WdgIf_FunctionId, WdgIf_ErrorCode) \
     ( (void) Det_ReportError( (WDGIF_MODULE_ID), (WDGIF_INSTANCE_ID), (WdgIf_FunctionId), (WdgIf_ErrorCode)) )
# else
#  define WdgIf_ReportDet(WdgIf_FunctionId, WdgIf_ErrorCode)
# endif /* (WDGIF_DEV_ERROR_DETECT == STD_ON) */

#endif /* WDGIF_CFG_FEATURES_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgIf_Cfg_Features.h
 *********************************************************************************************************************/





