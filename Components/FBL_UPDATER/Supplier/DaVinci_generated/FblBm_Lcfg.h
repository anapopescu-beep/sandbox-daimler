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
 *            Module: FblBm
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblBm_Lcfg.h
 *   Generation Time: 2023-07-24 13:42:10
 *           Project: CBD2000614_Upd - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (FBLBM_LCFG_H)
# define FBLBM_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "fbl_def.h"
# include "bm_hdr_types.h"
# include "FblBm_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
   FBLBM_TARGET_TYPE_MANDATORY = 0u,
   FBLBM_TARGET_TYPE_OPTIONAL
} tFblBmTargetType;

typedef struct
{
   tFblBmHdrTargetHandle target;
   tFblBmTargetType      type;
}tFblBmHdrTargetDependency;

typedef struct
{
   tFblBmHdrTargetHandle       target;
   V_MEMROM1 tFblBmHdrTargetDependency V_MEMROM2 V_MEMROM3 * dependencies;
   vuintx                      dependenciesSize;
}tFblBmHdrTargetListEntry;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* FBLBM_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: FblBm_Lcfg.h
 *********************************************************************************************************************/
