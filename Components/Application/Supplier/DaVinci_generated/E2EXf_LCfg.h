/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  E2EXf_LCfg.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR E2EXf Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  MICROSAR E2EXf header file for link-time variant
 *********************************************************************************************************************/

/* double include prevention */
#ifndef E2EXF_LCFG_H
# define E2EXF_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "SchM_E2EXf_Type.h"
# define E2EXF_LEGACY_STATEMACHINE (STD_OFF)

# include "E2E_P05.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version identification */
# define E2EXF_CFG_MAJOR_VERSION   (0x01U)
# define E2EXF_CFG_MINOR_VERSION   (0x0fU)

# define E2EXF_VERSION_INFO_API    (STD_OFF)

# define E2EXF_DEV_ERROR_DETECT    (STD_ON)
# define E2EXF_DEV_ERROR_REPORT    (STD_ON)

# define E2EXF_P01_ENABLED         (STD_OFF)
# define E2EXF_P02_ENABLED         (STD_OFF)
# define E2EXF_P04_ENABLED         (STD_OFF)
# define E2EXF_P05_ENABLED         (STD_ON)
# define E2EXF_P06_ENABLED         (STD_OFF)
# define E2EXF_P07_ENABLED         (STD_OFF)
# define E2EXF_P08_ENABLED         (STD_OFF)
# define E2EXF_P11_ENABLED         (STD_OFF)
# define E2EXF_P22_ENABLED         (STD_OFF)
# define E2EXF_P44_ENABLED         (STD_OFF)

# define E2EXF_OUTOFPLACE_ENABLED  (STD_OFF)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#ifndef E2EXF_DUMMY_STATEMENT
# define E2EXF_DUMMY_STATEMENT(v)
#endif
#ifndef E2EXF_DUMMY_STATEMENT_CONST
# define E2EXF_DUMMY_STATEMENT_CONST(v)
#endif

/**********************************************************************************************************************
 * E2EXf retransformers
 *********************************************************************************************************************/

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_P05Config_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3, \
         &E2EXf_P05Config_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3, \
         &E2EXf_P05Config_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_P05Config_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_P05Config_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_P05Config_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3, \
         &E2EXf_P05Config_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_P05Config_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3, \
         &E2EXf_P05Config_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* PRQA S 0777, 0779, 0791 L2 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_E2EXf_0791 */
# define E2EXf_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3(buffer, bufferLength, inputBufferLength) \
         E2EXf_P05_Inv(buffer, bufferLength, NULL_PTR, inputBufferLength, \
         &E2EXf_Options_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05Config_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3, \
         &E2EXf_P05CheckState_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMConfig_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3, \
         &E2EXf_SMCheckState_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3)
/* PRQA L:L2 */

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct {
    boolean inPlace;
    boolean executeDespiteDataUnavailability;
    boolean profileBehavior;
    boolean disableEndToEndCheck;
    uint32 headerLength;
    uint32 upperHeaderBitsToShift;
} E2EXf_OptionsType;

typedef struct
{
    /* postbuild not yet supported */
    uint8 E2EXf_dummy;
} E2EXf_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define E2EXF_START_SEC_CONST_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2EXf_OptionsType, E2EXF_CONST) E2EXf_Options_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_P05ConfigType, E2EXF_CONST) E2EXf_P05Config_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_CONST_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(E2E_P05CheckStateType, E2EXF_VAR_NOINIT) E2EXf_P05CheckState_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_CONST_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern CONST(E2E_SMConfigType, E2EXF_CONST) E2EXf_SMConfig_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_CONST_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, E2EXF_VAR_NOINIT) E2EXf_SMProfileStatusWindow_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3[10]; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

extern VAR(E2E_SMCheckStateType, E2EXF_VAR_NOINIT) E2EXf_SMCheckState_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3; /* PRQA S 0777, 0779 */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# define E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define E2EXF_START_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  E2EXf_Init_Calls
 *********************************************************************************************************************/
/*! \brief       State structures initialization function
 *  \details     This function initializes all state structures managed by E2EXf.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, E2EXF_CODE) E2EXf_Init_Calls(void);

# define E2EXF_STOP_SEC_CODE
# include "E2EXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* E2EXF_LCFG_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_E2EXf_0791:  MISRA rule: -
     Reason:       Transformer names are derived from the configuration.
     Risk:         No functional risk.
     Prevention:   Not required.

*/
