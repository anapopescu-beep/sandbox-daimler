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
 *             File:  Rte_BeltAdjFunction.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <BeltAdjFunction>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BELTADJFUNCTION_H
# define RTE_BELTADJFUNCTION_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_BeltAdjFunction_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_P_RevBltTns_FL_ComCyc_Actv_ST3_RevBltTns_FL_ComCyc_Actv_ST3 (3U)
#  define Rte_InitValue_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3 (3U)
#  define Rte_InitValue_R_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3 (0U)
#  define Rte_InitValue_R_RevBltTns_FR_ComCyc_Actv_ST3_RevBltTns_FR_ComCyc_Actv_ST3 (3U)
#  define Rte_InitValue_R_VehSpd_Disp_ST3_VehSpd_Disp_ST3 (4095U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3(P2VAR(c02_Off_On, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3(P2VAR(REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_DPC_Md_Rq_ESP_Pr5_ST3_DPC_Md_Rq_ESP_Pr5_ST3(P2VAR(REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(P2VAR(REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(P2VAR(REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3(P2VAR(c03_PN14_TDP_Sw_Stat, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(P2VAR(REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PT4_PTCoor9_Pr5_ST3_PT4_PTCoor9_Pr5_ST3(P2VAR(REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(P2VAR(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(P2VAR(REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_RevBltTns_FR_ComCyc_Actv_ST3_RevBltTns_FR_ComCyc_Actv_ST3(P2VAR(c02_Ndef_False_True_ST3, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_VehSpd_Disp_ST3_VehSpd_Disp_ST3(P2VAR(c12_km_p_h_0_409k4_0k1, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BeltAdjFunction_P_RevBltTns_FL_ComCyc_Actv_ST3_RevBltTns_FL_ComCyc_Actv_ST3(c02_Ndef_False_True_ST3 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3 Rte_Read_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3
#  define Rte_Read_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3 Rte_Read_BeltAdjFunction_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3
#  define Rte_Read_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3 Rte_Read_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3
#  define Rte_Read_R_DPC_Md_Rq_ESP_Pr5_ST3_DPC_Md_Rq_ESP_Pr5_ST3 Rte_Read_BeltAdjFunction_R_DPC_Md_Rq_ESP_Pr5_ST3_DPC_Md_Rq_ESP_Pr5_ST3
#  define Rte_Read_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3 Rte_Read_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3
#  define Rte_Read_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3 Rte_Read_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3
#  define Rte_Read_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3 Rte_Read_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3
#  define Rte_Read_R_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3 Rte_Read_BeltAdjFunction_R_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3
#  define Rte_Read_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3 Rte_Read_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3
#  define Rte_Read_R_PT4_PTCoor9_Pr5_ST3_PT4_PTCoor9_Pr5_ST3 Rte_Read_BeltAdjFunction_R_PT4_PTCoor9_Pr5_ST3_PT4_PTCoor9_Pr5_ST3
#  define Rte_Read_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 Rte_Read_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3
#  define Rte_Read_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3 Rte_Read_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3
#  define Rte_Read_R_RevBltTns_FR_ComCyc_Actv_ST3_RevBltTns_FR_ComCyc_Actv_ST3 Rte_Read_BeltAdjFunction_R_RevBltTns_FR_ComCyc_Actv_ST3_RevBltTns_FR_ComCyc_Actv_ST3
#  define Rte_Read_R_VehSpd_Disp_ST3_VehSpd_Disp_ST3 Rte_Read_BeltAdjFunction_R_VehSpd_Disp_ST3_VehSpd_Disp_ST3


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_RevBltTns_FL_ComCyc_Actv_ST3_RevBltTns_FL_ComCyc_Actv_ST3 Rte_Write_BeltAdjFunction_P_RevBltTns_FL_ComCyc_Actv_ST3_RevBltTns_FL_ComCyc_Actv_ST3


# endif /* !defined(RTE_CORE) */


# define BeltAdjFunction_START_SEC_CODE
# include "BeltAdjFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BeltAdjFunction_Init BeltAdjFunction_Init
#  define RTE_RUNNABLE_BeltAdjFunction_Main BeltAdjFunction_Main
# endif

FUNC(void, BeltAdjFunction_CODE) BeltAdjFunction_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, BeltAdjFunction_CODE) BeltAdjFunction_Main(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define BeltAdjFunction_STOP_SEC_CODE
# include "BeltAdjFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BELTADJFUNCTION_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
