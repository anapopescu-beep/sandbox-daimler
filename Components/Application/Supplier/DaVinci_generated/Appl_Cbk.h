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
 *            Module: Com
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Appl_Cbk.h
 *   Generation Time: 2024-01-09 10:59:57
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (APPL_CBK_H)
# define APPL_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COM_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

/* Configurable notification interface prototypes */
FUNC(void, COM_APPL_CODE) CIL_API_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_BeltAdj_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_BltHandoverLeft_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_BltHandoverRight_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_Buckle_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_BeltHdOvr_FL_Stat_ST3_3489841d_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_ExtTest_Pres_ST3_7e50ca1d_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_PN14_TransMd_Stat_ST3_2208da29_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_ProdMd_Stat_ST3_be2b5dfe_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ComNotification_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx(void);
FUNC(void, COM_APPL_CODE) CIL_ExtTest_Pres_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_Ignition_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_Odospeedometer_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_Powertrain_TimeoutError(void);
FUNC(void, COM_APPL_CODE) CIL_Presafe_TimeoutError(void);
FUNC(void, COM_APPL_CODE) ComM_ComCbk_ComSignalPnc_EIRA_CAN_Rx(void);


#define COM_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

#endif  /* APPL_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Appl_Cbk.h
**********************************************************************************************************************/

