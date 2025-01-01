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
 *             File:  ComXf.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR ComXf Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  MICROSAR ComXf header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef COMXF_H
# define COMXF_H


# include "SchM_ComXf_Type.h"

# define COMXF_SW_MAJOR_VERSION (0x04U)
# define COMXF_SW_MINOR_VERSION (0x20U)
# define COMXF_SW_PATCH_VERSION (0x00U)

# define COMXF_VENDOR_ID (0x1EU)
# define COMXF_MODULE_ID (0xAFU)

# define COMXF_AR_RELEASE_MAJOR_VERSION     (0x04U)
# define COMXF_AR_RELEASE_MINOR_VERSION     (0x02U)
# define COMXF_AR_RELEASE_REVISION_VERSION  (0x02U)

/* Return Codes */
# define COMXF_E_SER_GENERIC_ERROR (0x81U)

# define COMXF_START_SEC_CODE
# include "ComXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * ComXf retransformers
 *********************************************************************************************************************/

/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_CLkS_DrRltch_Stat_Pr5_ST3_7at68qvnk0r9npofyykyfq82v_10e0cb0e_Rx_REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx_REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx_Ssa_OdometerRecordType(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(Ssa_OdometerRecordType, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Ign_Stat_Pr5_ST3, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Ssa_IgnitionStatusType(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(Ssa_IgnitionStatusType, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx_REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx_REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx_REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106x(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx_REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/*!
 * \spec
 *    requires dataElement != NULL_PTR;
 * \endspec
 */
FUNC(Std_ReturnType, COMXF_CODE) ComXf_Inv_Com_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx_REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt(P2CONST(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, COMXF_APPL_VAR) dataElement); /* PRQA S 0786, 0777, 0779 */ /* MD_ComXf_0786, MD_MSR_Rule5.1, MD_MSR_Rule5.2 */


# define COMXF_STOP_SEC_CODE
# include "ComXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Defines for ComXf retransformer APIs
 *********************************************************************************************************************/

# define ComXf_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3 ComXf_Inv_Com_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx
# define ComXf_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3 ComXf_Inv_Com_CLkS_DrRltch_Stat_Pr5_ST3_7at68qvnk0r9npofyykyfq82v_10e0cb0e_Rx_REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx
# define ComXf_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3 ComXf_Inv_Com_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby
# define ComXf_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3 ComXf_Inv_Com_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx_REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh
# define ComXf_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3 ComXf_Inv_Com_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx_REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58
# define ComXf_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3 ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh
# define ComXf_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 ComXf_Inv_Com_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106x
# define ComXf_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3 ComXf_Inv_Com_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx_REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr
# define ComXf_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3 ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3
# define ComXf_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3 ComXf_Inv_Com_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx_REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh
# define ComXf_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3 ComXf_Inv_Com_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx_REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19
# define ComXf_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3 ComXf_Inv_Com_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j
# define ComXf_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3 ComXf_Inv_Com_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt
# define ComXf_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3 ComXf_Inv_Com_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw
# define ComXf_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3 ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw
# define ComXf_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 ComXf_Inv_Com_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106x
# define ComXf_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3 ComXf_Inv_Com_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx_REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt
# define ComXf_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3 ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3
# define ComXf_Inv_Ct_MBBL_ResetPreconditionChecker_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3 ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96
# define ComXf_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3 ComXf_Inv_Com_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt
# define ComXf_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3 ComXf_Inv_Com_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw
# define ComXf_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3 ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96
# define ComXf_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3 ComXf_Inv_Com_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx_REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19
# define ComXf_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3 ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw
# define ComXf_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 ComXf_Inv_Com_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106x
# define ComXf_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3 ComXf_Inv_Com_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j
# define ComXf_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3 ComXf_Inv_Com_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx_REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt
# define ComXf_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3 ComXf_Inv_Com_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx_REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh
# define ComXf_Inv_DiagFunction_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3 ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0
# define ComXf_Inv_DiagFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3 ComXf_Inv_Com_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby
# define ComXf_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3 ComXf_Inv_Com_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx_Ssa_OdometerRecordType
# define ComXf_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3 ComXf_Inv_Com_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Ssa_IgnitionStatusType

/**********************************************************************************************************************
 * ComXf Init/DeInit API
 *********************************************************************************************************************/

typedef uint8 ComXf_ConfigType;
FUNC(void, COMXF_CODE) ComXf_Init(P2CONST(ComXf_ConfigType, AUTOMATIC, COMXF_APPL_DATA) config);
FUNC(void, COMXF_CODE) ComXf_DeInit(void);

#endif /* COMXF_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_ComXf_0786:  MISRA rule: Rule5.5
     Reason:       Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:         No functional risk.
     Prevention:   Not required.

*/
