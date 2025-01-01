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
 *            Module: Dem
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dem_AdditionalIncludeCfg.h
 *   Generation Time: 2023-12-12 15:58:23
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* configuration, interrupt handling and callback headers use different names
 * for the multiple inclusion protection define, shown in this example. The
 * appropriate names for these files can be taken from this list:
 *
 * Dem_Cfg.h:                   DEM_CFG_H
 * Dem_Lcfg.h:                  DEM_LCFG_H
 * Dem_PBcfg.h:                 DEM_PBFG_H
 * Dem_AdditionalIncludeCfg.h:  DEM_ADDITIONALINCLUDECFG_H
 */
#if !defined (DEM_ADDITIONALINCLUDECFG_H)
# define DEM_ADDITIONALINCLUDECFG_H


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

/* From configuration parameter /Dem/DemGeneral/DemHeaderFileInclusion: */
#include "RCM_Callout_Stubs.h"
#include "Dem_Callout_Stubs.h"
#include "SBC.h"


#endif  /* DEM_ADDITIONALINCLUDECFG_H */
/**********************************************************************************************************************
  END OF FILE: Dem_AdditionalIncludeCfg.h     [Daimler, VARIANT-PRE-COMPILE, 22.06.00.146775]
**********************************************************************************************************************/

