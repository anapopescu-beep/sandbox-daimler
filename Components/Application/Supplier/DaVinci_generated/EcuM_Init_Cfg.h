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
 *              File: EcuM_Init_Cfg.h
 *   Generation Time: 2023-07-10 14:36:12
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (ECUM_INIT_CFG_H)
# define ECUM_INIT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

 

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_Init_Includes>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#include "Adc.h" 
#include "BswM.h" 
#include "CanIf.h" 
#include "CanNm.h" 
#include "CanSM_EcuM.h" 
#include "CanTp.h" 
#include "Can.h" 
#include "ComM.h" 
#include "Com.h" 
#include "Dcm.h" 
#include "Dma.h" 
#include "EcuM.h" 
#include "Fee.h" 
#include "Fls_17_Dmu.h" 
#include "Gpt.h" 
#include "Icu_17_TimerIp.h" 
#include "Mcu.h" 
#include "Nm.h" 
#include "PduR.h" 
#include "Port.h" 
#include "Pwm_17_GtmCcu6.h" 
#include "Rte_Main.h" 
#include "Smu.h" 
#include "Spi.h" 
#include "Wdg_17_Scu.h" 

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* In the following is the generated EcuM_GlobalConfigType. It contains supported BSW modules which
 * have configuration variant post-build-loadable. 
 */

#if (ECUM_USE_GENERATED_GLOBAL_CONFIG == STD_ON)

typedef struct
{
  CONSTP2CONST(BswM_ConfigType, TYPEDEF, BSWM_INIT_DATA) CfgPtr_BswM_Init;
  CONSTP2CONST(BswM_ConfigType, TYPEDEF, BSWM_INIT_DATA) CfgPtr_BswM_PreInit;
  CONSTP2CONST(CanIf_ConfigType, TYPEDEF, CANIF_INIT_DATA) CfgPtr_CanIf_Init;
  CONSTP2CONST(CanNm_ConfigType, TYPEDEF, CANNM_INIT_DATA) CfgPtr_CanNm_Init;
  CONSTP2CONST(CanSM_ConfigType, TYPEDEF, CANSM_INIT_DATA) CfgPtr_CanSM_Init;
  CONSTP2CONST(CanTp_ConfigType, TYPEDEF, CANTP_INIT_DATA) CfgPtr_CanTp_Init;
  CONSTP2CONST(Can_ConfigType, TYPEDEF, CAN_INIT_DATA) CfgPtr_Can_Init;
  CONSTP2CONST(ComM_ConfigType, TYPEDEF, COMM_INIT_DATA) CfgPtr_ComM_Init;
  CONSTP2CONST(ComM_ConfigType, TYPEDEF, COMM_INIT_DATA) CfgPtr_ComM_PreInit;
  CONSTP2CONST(Com_ConfigType, TYPEDEF, COM_INIT_DATA) CfgPtr_Com_Init;
  CONSTP2CONST(Dcm_ConfigType, TYPEDEF, DCM_CONST) CfgPtr_Dcm_Init;
  CONSTP2CONST(EcuM_PbConfigType, TYPEDEF, ECUM_INIT_DATA) CfgPtr_EcuM_Init;
  CONSTP2CONST(Nm_ConfigType, TYPEDEF, NM_INIT_DATA) CfgPtr_Nm_Init;
  CONSTP2CONST(Nm_ConfigType, TYPEDEF, NM_INIT_DATA) CfgPtr_Nm_PreInit;
  CONSTP2CONST(PduR_PBConfigType, TYPEDEF, PDUR_INIT_DATA) CfgPtr_PduR_Init;
  CONSTP2CONST(PduR_PBConfigType, TYPEDEF, PDUR_INIT_DATA) CfgPtr_PduR_PreInit;
  CONSTP2CONST(SchM_ConfigType, TYPEDEF, RTE_CONST) CfgPtr_SchM_Init;
} EcuM_GlobalPCConfigType;


typedef EcuM_GlobalPCConfigType EcuM_GlobalConfigType;

typedef P2CONST(EcuM_GlobalConfigType, AUTOMATIC, ECUM_CONST) EcuM_GlobalConfigRefType;

typedef struct
{
  EcuM_GlobalConfigType Left;
  EcuM_GlobalConfigType Right;
} EcuM_GlobalConfigRootType;


#endif


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GlobalConfigType>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* In this section a custom EcuM_GlobalConfigType can be defined. Use generated EcuM_GlobalConfigType as template.
 *
 * Caution: EcuM must be always in variant post-build if one of the BSW module is in variant post-build.
 *          Do not change the name of the member EcuM. If the BswM is in variant post-build 
 *          it is also not allowed to change the name of the struct member. This two modules 
 *          are accessed during initialization via this names.
 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Global pointer to access the global variant data, do not remove and do not change the name */
 
extern P2CONST(EcuM_GlobalConfigType, ECUM_VAR_NO_INIT, ECUM_CONST) EcuM_GlobalPCConfig_Ptr;

#define ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ECUM_START_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 

extern CONST(EcuM_GlobalConfigRootType, ECUM_CONST) EcuM_GlobalConfigRoot; 

#define ECUM_STOP_SEC_CONST_UNSPECIFIED
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 



#if 0
#endif




#endif
/**********************************************************************************************************************
 *  END OF FILE: ECUM_INIT_PBCFG.H
 *********************************************************************************************************************/


