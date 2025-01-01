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
 *              File: EcuM_Init_Cfg.c
 *   Generation Time: 2023-07-10 14:36:12
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define ECUM_INIT_CFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "EcuM_Init_PBcfg.h" 
 

 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_Init_Includes>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* In the following is the generated EcuM_GlobalConfigRoot. It contains supported BSW modules which
 * have configuration variant post-build-loadable. 
 */

#if (ECUM_USE_GENERATED_GLOBAL_CONFIG == STD_ON)

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(EcuM_GlobalConfigRootType, ECUM_CONST) EcuM_GlobalConfigRoot = /* PRQA S 1533 *//* MD_EcuM_1533 */
{
  {
    BswM_Config_Left_Ptr, 
    BswM_Config_Left_Ptr, 
    CanIf_Config_Left_Ptr, 
    CanNm_Config_Left_Ptr, 
    CanSM_Config_Left_Ptr, 
    CanTp_Config_Left_Ptr, 
    Can_Config_Left_Ptr, 
    ComM_Config_Left_Ptr, 
    ComM_Config_Left_Ptr, 
    Com_Config_Left_Ptr, 
    &Dcm_CfgConfig_Left, 
    EcuM_Config_Left_Ptr, 
    Nm_Config_Left_Ptr, 
    Nm_Config_Left_Ptr, 
    PduR_Config_Left_Ptr, 
    PduR_Config_Left_Ptr, 
    &Rte_Config_Left
  }, 
  {
    BswM_Config_Right_Ptr, 
    BswM_Config_Right_Ptr, 
    CanIf_Config_Right_Ptr, 
    CanNm_Config_Right_Ptr, 
    CanSM_Config_Right_Ptr, 
    CanTp_Config_Right_Ptr, 
    Can_Config_Right_Ptr, 
    ComM_Config_Right_Ptr, 
    ComM_Config_Right_Ptr, 
    Com_Config_Right_Ptr, 
    &Dcm_CfgConfig_Right, 
    EcuM_Config_Right_Ptr, 
    Nm_Config_Right_Ptr, 
    Nm_Config_Right_Ptr, 
    PduR_Config_Right_Ptr, 
    PduR_Config_Right_Ptr, 
    &Rte_Config_Right
  }
};

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GlobalPcConfigRoot>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* In this section a custom EcuM_GlobalConfigRoot can be defined. Use generated EcuM_GlobalConfigRoot as template.
 *
 * Caution: If a custom EcuM_GlobalConfigRoot is used, the EcuM_GlobalConfigType must be adapted in EcuM_Init_PBcfg.h!
 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

 

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: ECUM_INIT_PBCFG_SOURCE.C
 *********************************************************************************************************************/
 

