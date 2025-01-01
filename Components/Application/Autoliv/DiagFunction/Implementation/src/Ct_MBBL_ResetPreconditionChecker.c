/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Ct_MBBL_ResetPreconditionChecker.c
 *           Config:  S:\Tools\Vector_configuration\Workspace\Daimler MMA/S:/Tools/Vector_configuration/Workspace/Daimler MMA/StartApplication.dpa
 *        SW-C Type:  Ct_MBBL_ResetPreconditionChecker
 *  Generation Time:  2021-10-29 14:31:13
 *
 *        Generator:  MICROSAR RTE Generator Version 4.24.0
 *                    RTE Core Version 1.24.0
 *          License:  PAI981
 *
 *      Description:  C-Code implementation template for SW-C <Ct_MBBL_ResetPreconditionChecker>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW
 *  configuration. The Example Code has not passed any quality control measures and may be incomplete. The
 *  Example Code is neither intended nor qualified for use in series production. The Example Code as well
 *  as any of its modifications and/or implementations must be tested with diligent care and must comply
 *  with all quality requirements which are necessary according to the state of the art before their use.
 *********************************************************************************************************************/
/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * DC_BOOL
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * REC_ADAS_Meta_ST3_b2mk60164reg2lw3ivnikdnou
 *   (degraded)
 *
 * REC_ADAS_Posn_ST3_7tu0j7cag3wthixhamscgyjyr
 *   (degraded)
 *
 * REC_ADAS_Profile_Short_CurvLn_ST3_490g5rtcnid4ivawivkcosvcg
 *   (degraded)
 *
 * REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx
 *   (degraded)
 *
 * REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt
 *   (degraded)
 *
 * REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx
 *   (degraded)
 *
 * REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh
 *   (degraded)
 *
 * REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86
 *   (degraded)
 *
 * REC_Develop8_Rq_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv
 *   (degraded)
 *
 * REC_Develop8_Rs_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv
 *   (degraded)
 *
 * REC_ELC_Lvr_Stat_Pr5_ST3_9t50popkpz30is106xpis1iyh
 *   (degraded)
 *
 * REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby
 *   (degraded)
 *
 * REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw
 *   (degraded)
 *
 * REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0
 *   (degraded)
 *
 * REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96
 *   (degraded)
 *
 * REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv
 *   (degraded)
 *
 * REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh
 *   (degraded)
 *
 * REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19
 *   (degraded)
 *
 * REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58
 *   (degraded)
 *
 * REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby
 *   (degraded)
 *
 * REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh
 *   (degraded)
 *
 * REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw
 *   (degraded)
 *
 * REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u
 *   (degraded)
 *
 * REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh
 *   (degraded)
 *
 * REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j
 *   (degraded)
 *
 * REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr
 *   (degraded)
 *
 * REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv
 *   (degraded)
 *
 * REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4
 *   (degraded)
 *
 * Rsrv01
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Rsrv02
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Rsrv04
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Rsrv05
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Rsrv08
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Rsrv24
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * Rsrv27
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * c01_FalseTrue
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c01_Right_Left
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c01_UnitVehSpd
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_0_3_1_nSNA
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_ADAS_MapVerQuar
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Bckl_Sw_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_BeltHdOvr_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_DPC_Md_SSA
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Dr_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_EVC_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_HiBmLvr_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Inact_Act_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Inactv_Silent_Actv_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_NDef_ECO_Comfort
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_NDef_Off_On_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_NDef_On_Off
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Navi_MPP_ResetRsn_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Ndef_False_True_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Off_On
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Off_Stage1_Stage2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_PT_Rdy_V2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Presf_Disp_Rq
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_Presf_Snd
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_SSA_Standby_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_StStyle
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_TransMd_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_TurnIndLvr_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_TxBurnOut_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c02_false_true_sna
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_0_6_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_0_to_7_1_no_SNA
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_ADAS_MapProvid
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_ADAS_Posn_CurLane
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_ADAS_Posn_Idx
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_Accel_Md_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_DCDCBuckSuprtStat_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_DPC_Md_ExhaustFlap
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_DPC_Md_St
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_EngStartPN14_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_ISw_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_MsgTyp_1_to_7
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_No_Lt_Rt_Both
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_PN14_ProdMd_Stat_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_PN14_TDP_Sw_Stat
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_VehPos_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c03_m2_p3_1_Init
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_0_15_1_SNA_na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_DPC_GlobalMd_Rq
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_DPC_Md_ESP_Rq_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_DrvPosn_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_EVC_HL_Style_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_EVC_TxStyle_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_EVC_YrOfModf_1_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_EVC_YrOfModf_2_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_Gr
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_Gr_Target
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_NDef_Man_Auto
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_Presf_Frct_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_Presf_Lvl_V2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c04_VehOpMode
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c05_ADAS_ProfShort_ProfTyp
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c05_DPC_Md_PT_HU
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c05_DPC_Md_Susp_V2
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c05_perc_0_31_3k333
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c06_ADAS_MapVerYear
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c06_EVC_BodyStyle_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c06_EVC_VehLine_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c06_Idx_0_to_63_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c07_0_111_1_SNA
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c07_per_0to100_1_SNA
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_0_254_1_SNA_255
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_0_255_1_SNA_na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_EVC_Country_extended
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_ROE_0
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_TxDrvPosn
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_UInt_SNA_na
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_V_0_25k4_0k1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_degC_m40_85_0k5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_deg_0_358k5_1k417
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_km_p_h_0_250_1_Blank
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_km_p_h_0_254_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_km_p_h_30_250_1_NoRcmnd
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_m_1d6_2d87_0d005
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_perc_0_100_0k4
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c08_perc_0_100_0k5
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c09_ADAS_HwVer
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c09_km_p_h_0_500_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c09_m_p_s_m12k8_89k2_0k2
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c09_ms_0_510_5
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * c10_ADAS_CountryCode
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c10_PT4_PTCoor_DAS_Hlth_Stat
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c10_V_0_25k55_0k025
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c10_WakeupRsn_ST3
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c10_m_0_510_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c10_to_1022_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c12_0_4094_1_SNA
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c12_km_p_h_0_409k4_0k1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c12_rpm_0_16376_4
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c13_A_m409k6_409k4_0k1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c13_PresfAct_Adj_Rq
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * c13_m_0_8190_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c14_rpm_0_16382_1
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c15_ADAS_RegionCode
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c16_CRC_woSNA
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c16_SeatBeltHdOvr_FctAvlStat_ST3
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * c24_km_0_999999k9_0k1_Invld_SNA
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * cDC_errorCode_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * cDC_keyStorageTask_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * cDC_keyStorageUseCase_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * cDC_syncState_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * cDC_tickCount_ST3
 *   uint64 represents integers with a minimum value of 0 and a maximum value 
 *      of 18446744073709551615. The order-relation on uint64 is: x < y if y - x is positive.
 *      uint64 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * c_DC_VIN_Stat_ST3
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Port Prototypes:
 * ================
 * R_VehSpd8_Pr5_ST3
 *   vehicle Spd 8 ST3 (degraded)
 *
 *
 * Data Element Prototypes:
 * ========================
 * VehSpd8_Pr5_ST3 of Port Interface IG_VehSpd8_Pr5_ST3_atci5a3rslji054k0igvxyzqz
 *   SHORT: vehicle Spd 8 ST3
 *      LONG:  (degraded)
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Coding_MemoryStatus
 *   Notifies the Ssa of memory status changes while storing or restoring the Variant Coding Data to or from non-volatile memory.
 *
 * Coding_Mode
 *   Coding state
 *
 * Coding_Mode
 *   Notifies application about an ongoing, successful or failed coding attempt.
 *
 * RightsM_AuthenticationMode
 *   RIGHTSM_AUTHENTICATED - A Tester was successfully authenticated
 *      RIGHTSM_UNAUTHENTICATED - No tester was authenticated
 *
 * WdgM_Mode
 *   The mode declaration group WdgMMode represents the modes of the Watchdog Manager module that will be notified to the SW-Cs / CDDs and the RTE.
 *
 *
 * Mode Declarations:
 * ==================
 * CODING_ACTIVE of Mode Declaration Group Coding_Mode
 *   Active
 *
 * CODING_FAILED of Mode Declaration Group Coding_Mode
 *   Failed
 *
 * CODING_OK of Mode Declaration Group Coding_Mode
 *   Ok
 *
 *********************************************************************************************************************/

#include "Rte_Ct_MBBL_ResetPreconditionChecker.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * DC_BOOL: Boolean
 * Rsrv01: Integer in interval [0...1]
 * Rsrv02: Integer in interval [0...3]
 * Rsrv04: Integer in interval [0...15]
 * Rsrv05: Integer in interval [0...31]
 * Rsrv08: Integer in interval [0...255]
 * Rsrv24: Integer in interval [0...16777215]
 * Rsrv27: Integer in interval [0...134217727]
 * boolean: Boolean (standard type)
 * c02_0_3_1_nSNA: Integer in interval [0...3]
 * c02_ADAS_MapVerQuar: Integer in interval [0...3]
 * c02_Navi_MPP_ResetRsn_ST3: Integer in interval [0...3]
 * c03_0_to_7_1_no_SNA: Integer in interval [0...7]
 * c03_ADAS_Posn_Idx: Integer in interval [0...3]
 * c04_0_15_1_SNA_na: Integer in interval [0...15]
 * c07_0_111_1_SNA: Integer in interval [0...127]
 * c08_0_254_1_SNA_255: Integer in interval [0...255]
 * c08_0_255_1_SNA_na: Integer in interval [0...255]
 * c08_UInt_SNA_na: Integer in interval [0...255]
 * c08_degC_m40_85_0k5: Integer in interval [0...255]
 * c08_km_p_h_0_250_1_Blank: Integer in interval [0...255]
 * c08_m_1d6_2d87_0d005: Integer in interval [0...255]
 * c13_A_m409k6_409k4_0k1: Integer in interval [0...8191]
 * c16_CRC_woSNA: Integer in interval [0...65535]
 * c16_SeatBeltHdOvr_FctAvlStat_ST3: Integer in interval [0...65535]
 * cDC_tickCount_ST3: Integer in interval [0...18446744073709551615]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_AUTHENTICATIONREQUIRED (52U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_CVF_INVALIDTIMEPERIOD (80U)
 *   DCM_E_CVF_INVALIDSIGNATURE (81U)
 *   DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
 *   DCM_E_CVF_INVALIDTYPE (83U)
 *   DCM_E_CVF_INVALIDFORMAT (84U)
 *   DCM_E_CVF_INVALIDCONTENT (85U)
 *   DCM_E_CVF_INVALIDSCOPE (86U)
 *   DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
 *   DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
 *   DCM_E_CHALLENGECALCULATIONFAILED (89U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * c01_FalseTrue: Enumeration of integer in interval [0...1] with enumerators
 *   I_C01_FALSETRUE_FALSE (0U)
 *   I_C01_FALSETRUE_TRUE (1U)
 * c01_Right_Left: Enumeration of integer in interval [0...1] with enumerators
 *   I_C01_RIGHT_LEFT_LHD (0U)
 *   I_C01_RIGHT_LEFT_RHD (1U)
 * c01_UnitVehSpd: Enumeration of integer in interval [0...1] with enumerators
 *   I_C01_UNITVEHSPD_KMH (0U)
 *   I_C01_UNITVEHSPD_MPH (1U)
 * c02_Bckl_Sw_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_BCKL_SW_STAT_OK (0U)
 *   I_C02_BCKL_SW_STAT_NOT (1U)
 *   I_C02_BCKL_SW_STAT_FLT (2U)
 *   I_C02_BCKL_SW_STAT_SNA (3U)
 * c02_BeltHdOvr_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_BELTHDOVR_STAT_RETRACT (0U)
 *   I_C02_BELTHDOVR_STAT_OUT_OF_END (1U)
 *   I_C02_BELTHDOVR_STAT_EXTEND (2U)
 *   I_C02_BELTHDOVR_STAT_SNA (3U)
 * c02_DPC_Md_SSA: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_DPC_MD_SSA_SSA_ON (1U)
 *   I_C02_DPC_MD_SSA_SSA_OFF (2U)
 *   I_C02_DPC_MD_SSA_SNA (3U)
 * c02_Dr_Stat: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_DR_STAT_CLS (1U)
 *   I_C02_DR_STAT_OPN (2U)
 *   I_C02_DR_STAT_SNA (3U)
 * c02_EVC_Stat: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_EVC_STAT_PROG (1U)
 *   I_C02_EVC_STAT_REQ (2U)
 *   I_C02_EVC_STAT_SNA (3U)
 * c02_HiBmLvr_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_HIBMLVR_STAT_IDLE (0U)
 *   I_C02_HIBMLVR_STAT_HIBM_ON_PSD (1U)
 *   I_C02_HIBMLVR_STAT_HIBM_FLSH_ON_PSD (2U)
 *   I_C02_HIBMLVR_STAT_SNA (3U)
 * c02_Inact_Act_ST3: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_INACT_ACT_ST3_INACTIVE (0U)
 *   I_C02_INACT_ACT_ST3_ACTIVE (1U)
 *   I_C02_INACT_ACT_ST3_SNA (3U)
 * c02_Inactv_Silent_Actv_ST3: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_INACTV_SILENT_ACTV_ST3_INACTIVE (0U)
 *   I_C02_INACTV_SILENT_ACTV_ST3_SILENT (1U)
 *   I_C02_INACTV_SILENT_ACTV_ST3_ACTIVE (2U)
 *   I_C02_INACTV_SILENT_ACTV_ST3_SNA (3U)
 * c02_NDef_ECO_Comfort: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_NDEF_ECO_COMFORT_ECO (1U)
 *   I_C02_NDEF_ECO_COMFORT_COMFORT (2U)
 *   I_C02_NDEF_ECO_COMFORT_SNA (3U)
 * c02_NDef_Off_On_ST3: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_NDEF_OFF_ON_ST3_OFF (1U)
 *   I_C02_NDEF_OFF_ON_ST3_ON (2U)
 *   I_C02_NDEF_OFF_ON_ST3_SNA (3U)
 * c02_NDef_On_Off: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_NDEF_ON_OFF_ON (1U)
 *   I_C02_NDEF_ON_OFF_OFF (2U)
 *   I_C02_NDEF_ON_OFF_SNA (3U)
 * c02_Ndef_False_True_ST3: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_NDEF_FALSE_TRUE_ST3_FALSE (1U)
 *   I_C02_NDEF_FALSE_TRUE_ST3_TRUE (2U)
 *   I_C02_NDEF_FALSE_TRUE_ST3_SNA (3U)
 * c02_Off_On: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_OFF_ON_OFF (0U)
 *   I_C02_OFF_ON_ON (1U)
 *   I_C02_OFF_ON_SNA (3U)
 * c02_Off_Stage1_Stage2: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_OFF_STAGE1_STAGE2_OFF (0U)
 *   I_C02_OFF_STAGE1_STAGE2_STAGE1 (1U)
 *   I_C02_OFF_STAGE1_STAGE2_STAGE2 (2U)
 *   I_C02_OFF_STAGE1_STAGE2_SNA (3U)
 * c02_PT_Rdy_V2: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_PT_RDY_V2_PT_NOT_RDY (0U)
 *   I_C02_PT_RDY_V2_PT_RDY (1U)
 *   I_C02_PT_RDY_V2_SNA (3U)
 * c02_Presf_Disp_Rq: Enumeration of integer in interval [0...1] with enumerators
 *   I_C02_PRESF_DISP_RQ_IDLE (0U)
 *   I_C02_PRESF_DISP_RQ_SRV_DISP_RQ (1U)
 * c02_Presf_Snd: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_PRESF_SND_IDLE (0U)
 *   I_C02_PRESF_SND_PINK_NOISE1 (1U)
 *   I_C02_PRESF_SND_PINK_NOISE2 (2U)
 *   I_C02_PRESF_SND_SNA (3U)
 * c02_SSA_Standby_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_SSA_STANDBY_STAT_IDLE (0U)
 *   I_C02_SSA_STANDBY_STAT_STANDBY_MD_ACTV (1U)
 *   I_C02_SSA_STANDBY_STAT_STANDBY_MD_PSV (2U)
 *   I_C02_SSA_STANDBY_STAT_SNA (3U)
 * c02_StStyle: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_STSTYLE_LHD (1U)
 *   I_C02_STSTYLE_RHD (2U)
 *   I_C02_STSTYLE_SNA (3U)
 * c02_TransMd_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_TRANSMD_STAT_OFF (0U)
 *   I_C02_TRANSMD_STAT_TEMP_OFF (1U)
 *   I_C02_TRANSMD_STAT_ACTV (2U)
 *   I_C02_TRANSMD_STAT_SNA (3U)
 * c02_TurnIndLvr_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_TURNINDLVR_STAT_IDLE (0U)
 *   I_C02_TURNINDLVR_STAT_LEFT (1U)
 *   I_C02_TURNINDLVR_STAT_RIGHT (2U)
 *   I_C02_TURNINDLVR_STAT_SNA (3U)
 * c02_TxBurnOut_Stat: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_TXBURNOUT_STAT_INACTIVE (0U)
 *   I_C02_TXBURNOUT_STAT_ENBL (1U)
 *   I_C02_TXBURNOUT_STAT_ACTIVE (2U)
 *   I_C02_TXBURNOUT_STAT_ABORT (3U)
 * c02_false_true_sna: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_FALSE_TRUE_SNA_FALSE (0U)
 *   I_C02_FALSE_TRUE_SNA_TRUE (1U)
 *   I_C02_FALSE_TRUE_SNA_SNA (3U)
 * c03_0_6_1: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_0_6_1_SNA (7U)
 * c03_ADAS_MapProvid: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ADAS_MAPPROVID_UNKNOWN (0U)
 *   I_C03_ADAS_MAPPROVID_NAVTEQ (1U)
 *   I_C03_ADAS_MAPPROVID_TELEATLAS (2U)
 *   I_C03_ADAS_MAPPROVID_ZENRIN (3U)
 *   I_C03_ADAS_MAPPROVID_IPC (4U)
 *   I_C03_ADAS_MAPPROVID_NAVINFO (5U)
 *   I_C03_ADAS_MAPPROVID_OTHER (6U)
 *   I_C03_ADAS_MAPPROVID_SNA (7U)
 * c03_ADAS_Posn_CurLane: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ADAS_POSN_CURLANE_UNKWN (0U)
 *   I_C03_ADAS_POSN_CURLANE_EMG_L (1U)
 *   I_C03_ADAS_POSN_CURLANE_SINGLE_L (2U)
 *   I_C03_ADAS_POSN_CURLANE_LM_L (3U)
 *   I_C03_ADAS_POSN_CURLANE_RM_L (4U)
 *   I_C03_ADAS_POSN_CURLANE_MID_L (5U)
 *   I_C03_ADAS_POSN_CURLANE_RES (6U)
 *   I_C03_ADAS_POSN_CURLANE_SNA (7U)
 * c03_Accel_Md_ST3: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ACCEL_MD_ST3_NORMAL_ACCLRN_MODE (0U)
 *   I_C03_ACCEL_MD_ST3_OPTMD_FULL_LOAD_WO_OVR_TRQ (1U)
 *   I_C03_ACCEL_MD_ST3_OPTMD_FULL_LOAD_WITH_OVR_TRQ (2U)
 *   I_C03_ACCEL_MD_ST3_RACESTRT_PHASE_WO_OVR_TRQ (3U)
 *   I_C03_ACCEL_MD_ST3_RACESTRT_PHASE_WITH_OVR_TRQ (4U)
 *   I_C03_ACCEL_MD_ST3_RACESTRT_ACCLN_WO_OVR_TRQ (5U)
 *   I_C03_ACCEL_MD_ST3_RACESTRT_ACCLN_WITH_OVR_TRQ (6U)
 *   I_C03_ACCEL_MD_ST3_SNA (7U)
 * c03_DCDCBuckSuprtStat_ST3: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_DCDCBUCKSUPRTSTAT_ST3_NO_DCDC (0U)
 *   I_C03_DCDCBUCKSUPRTSTAT_ST3_DCDC_BUCKSUPRT_ACTV (1U)
 *   I_C03_DCDCBUCKSUPRTSTAT_ST3_DCDC_BUCKSUPRT_STOP (2U)
 *   I_C03_DCDCBUCKSUPRTSTAT_ST3_SNA (7U)
 * c03_DPC_Md_ExhaustFlap: Enumeration of integer in interval [1...7] with enumerators
 *   I_C03_DPC_MD_EXHAUSTFLAP_COMFORT (1U)
 *   I_C03_DPC_MD_EXHAUSTFLAP_SPORT (2U)
 *   I_C03_DPC_MD_EXHAUSTFLAP_SPORTPLUS (3U)
 *   I_C03_DPC_MD_EXHAUSTFLAP_RACE (4U)
 *   I_C03_DPC_MD_EXHAUSTFLAP_SNA (7U)
 * c03_DPC_Md_St: Enumeration of integer in interval [1...7] with enumerators
 *   I_C03_DPC_MD_ST_COMFORT (1U)
 *   I_C03_DPC_MD_ST_SPORT (2U)
 *   I_C03_DPC_MD_ST_SPORTPLUS (3U)
 *   I_C03_DPC_MD_ST_OFFROAD (4U)
 *   I_C03_DPC_MD_ST_SNA (7U)
 * c03_EngStartPN14_Stat: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ENGSTARTPN14_STAT_NO_COMBUSTIONSTART_RQ (0U)
 *   I_C03_ENGSTARTPN14_STAT_CUSTOMER_START_RQ (1U)
 *   I_C03_ENGSTARTPN14_STAT_AUTO_START_NO_PN_SUP_RQ (2U)
 *   I_C03_ENGSTARTPN14_STAT_AUTO_START_PN_SUP_RQ (3U)
 *   I_C03_ENGSTARTPN14_STAT_SNA (7U)
 * c03_ISw_Stat: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ISW_STAT_IGN_LOCK (0U)
 *   I_C03_ISW_STAT_IGN_OFF (1U)
 *   I_C03_ISW_STAT_IGN_ACC (2U)
 *   I_C03_ISW_STAT_IGN_ON (4U)
 *   I_C03_ISW_STAT_IGN_START (5U)
 *   I_C03_ISW_STAT_SNA (7U)
 * c03_MsgTyp_1_to_7: Enumeration of integer in interval [1...7] with enumerators
 *   I_C03_MSGTYP_1_TO_7_POSITION (1U)
 *   I_C03_MSGTYP_1_TO_7_SEGMENT (2U)
 *   I_C03_MSGTYP_1_TO_7_STUB (3U)
 *   I_C03_MSGTYP_1_TO_7_PROFILE_SHORT (4U)
 *   I_C03_MSGTYP_1_TO_7_PROFILE_LONG (5U)
 *   I_C03_MSGTYP_1_TO_7_META_DATA (6U)
 *   I_C03_MSGTYP_1_TO_7_SNA (7U)
 * c03_No_Lt_Rt_Both: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_NO_LT_RT_BOTH_NO (0U)
 *   I_C03_NO_LT_RT_BOTH_LEFT (1U)
 *   I_C03_NO_LT_RT_BOTH_RIGHT (2U)
 *   I_C03_NO_LT_RT_BOTH_BOTH (3U)
 *   I_C03_NO_LT_RT_BOTH_SNA (7U)
 * c03_PN14_ProdMd_Stat_ST3: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_PN14_PRODMD_STAT_ST3_OFF (0U)
 *   I_C03_PN14_PRODMD_STAT_ST3_ON (1U)
 *   I_C03_PN14_PRODMD_STAT_ST3_SF01 (2U)
 *   I_C03_PN14_PRODMD_STAT_ST3_SF02 (3U)
 *   I_C03_PN14_PRODMD_STAT_ST3_SF03 (4U)
 *   I_C03_PN14_PRODMD_STAT_ST3_SNA (7U)
 * c03_PN14_TDP_Sw_Stat: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_PN14_TDP_SW_STAT_CLS (0U)
 *   I_C03_PN14_TDP_SW_STAT_PRE_RESET (1U)
 *   I_C03_PN14_TDP_SW_STAT_RESET (2U)
 *   I_C03_PN14_TDP_SW_STAT_PRE_OPN (3U)
 *   I_C03_PN14_TDP_SW_STAT_OPN (4U)
 *   I_C03_PN14_TDP_SW_STAT_SNA (7U)
 * c03_VehPos_ST3: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_VEHPOS_ST3_VEHPOSI_UNKNOWN (0U)
 *   I_C03_VEHPOS_ST3_VEHPOSI_ROOF (1U)
 *   I_C03_VEHPOS_ST3_VEHPOSI_SIDE_LEFT (2U)
 *   I_C03_VEHPOS_ST3_VEHPOSI_SIDE_RIGHT (3U)
 *   I_C03_VEHPOS_ST3_SNA (7U)
 * c03_m2_p3_1_Init: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_M2_P3_1_INIT_INIT (0U)
 *   I_C03_M2_P3_1_INIT_SNA (7U)
 * c04_DPC_GlobalMd_Rq: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_DPC_GLOBALMD_RQ_COMFORT (0U)
 *   I_C04_DPC_GLOBALMD_RQ_SPORT (1U)
 *   I_C04_DPC_GLOBALMD_RQ_SPORT_PLUS (2U)
 *   I_C04_DPC_GLOBALMD_RQ_ALLROAD (3U)
 *   I_C04_DPC_GLOBALMD_RQ_ECO (4U)
 *   I_C04_DPC_GLOBALMD_RQ_INDIVIDUAL (5U)
 *   I_C04_DPC_GLOBALMD_RQ_MANUAL (6U)
 *   I_C04_DPC_GLOBALMD_RQ_CURVEURBANCRUISEAMG (7U)
 *   I_C04_DPC_GLOBALMD_RQ_SLIPPERY_WET (8U)
 *   I_C04_DPC_GLOBALMD_RQ_TERRAIN (9U)
 *   I_C04_DPC_GLOBALMD_RQ_UPHILL (10U)
 *   I_C04_DPC_GLOBALMD_RQ_TRAILER (11U)
 *   I_C04_DPC_GLOBALMD_RQ_ROCKING_FREE (12U)
 *   I_C04_DPC_GLOBALMD_RQ_TERRAIN_PLUS (13U)
 *   I_C04_DPC_GLOBALMD_RQ_NO_DPC (14U)
 *   I_C04_DPC_GLOBALMD_RQ_SNA (15U)
 * c04_DPC_Md_ESP_Rq_ST3: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_DPC_MD_ESP_RQ_ST3_INIT (0U)
 *   I_C04_DPC_MD_ESP_RQ_ST3_COMFORT (1U)
 *   I_C04_DPC_MD_ESP_RQ_ST3_SPORT (2U)
 *   I_C04_DPC_MD_ESP_RQ_ST3_OFF (3U)
 *   I_C04_DPC_MD_ESP_RQ_ST3_SPORT_PLUS (4U)
 *   I_C04_DPC_MD_ESP_RQ_ST3_OFFROAD (5U)
 *   I_C04_DPC_MD_ESP_RQ_ST3_OFFROAD_PLUS (6U)
 *   I_C04_DPC_MD_ESP_RQ_ST3_SNOW (7U)
 *   I_C04_DPC_MD_ESP_RQ_ST3_SNA (15U)
 * c04_DrvPosn_ST3: Enumeration of integer in interval [1...15] with enumerators
 *   I_C04_DRVPOSN_ST3_D (1U)
 *   I_C04_DRVPOSN_ST3_N (2U)
 *   I_C04_DRVPOSN_ST3_R (3U)
 *   I_C04_DRVPOSN_ST3_P (4U)
 *   I_C04_DRVPOSN_ST3_SNA (15U)
 * c04_EVC_HL_Style_ST3: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_EVC_HL_STYLE_ST3_LED_STAT_LHT (0U)
 *   I_C04_EVC_HL_STYLE_ST3_LED_STAT_RHT (1U)
 *   I_C04_EVC_HL_STYLE_ST3_LED_DYN_SAE_RHT (2U)
 *   I_C04_EVC_HL_STYLE_ST3_LED_DYN_LHT (3U)
 *   I_C04_EVC_HL_STYLE_ST3_LED_DYN_RHT (4U)
 *   I_C04_EVC_HL_STYLE_ST3_HEADLIGHT_LHT (5U)
 *   I_C04_EVC_HL_STYLE_ST3_HEADLIGHT_RHT (6U)
 *   I_C04_EVC_HL_STYLE_ST3_DIGITAL_SAE_RHT (7U)
 *   I_C04_EVC_HL_STYLE_ST3_DIGITAL_LHT (8U)
 *   I_C04_EVC_HL_STYLE_ST3_DIGITAL_RHT (9U)
 *   I_C04_EVC_HL_STYLE_ST3_OTHER (15U)
 * c04_EVC_TxStyle_ST3: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_EVC_TXSTYLE_ST3_MANUAL_6 (0U)
 *   I_C04_EVC_TXSTYLE_ST3_AUTOM_7 (2U)
 *   I_C04_EVC_TXSTYLE_ST3_AUTOM_9 (3U)
 *   I_C04_EVC_TXSTYLE_ST3_MANUAL_6_NSG2 (4U)
 *   I_C04_EVC_TXSTYLE_ST3_AUTOM_7_DCT (5U)
 *   I_C04_EVC_TXSTYLE_ST3_AUTOM_9_DCT (6U)
 *   I_C04_EVC_TXSTYLE_ST3_E_DRIVE (7U)
 *   I_C04_EVC_TXSTYLE_ST3_OTHER (15U)
 * c04_EVC_YrOfModf_1_ST3: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_EVC_YROFMODF_1_ST3_YOM800 (0U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM801 (1U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM802 (2U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM803 (3U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM804 (4U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM805 (5U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM806 (6U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM807 (7U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM808 (8U)
 *   I_C04_EVC_YROFMODF_1_ST3_YOM809 (9U)
 *   I_C04_EVC_YROFMODF_1_ST3_OTHER (15U)
 * c04_EVC_YrOfModf_2_ST3: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_EVC_YROFMODF_2_ST3_YOM050 (0U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM051 (1U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM052 (2U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM053 (3U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM054 (4U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM055 (5U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM056 (6U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM057 (7U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM058 (8U)
 *   I_C04_EVC_YROFMODF_2_ST3_YOM059 (9U)
 *   I_C04_EVC_YROFMODF_2_ST3_OTHER (15U)
 * c04_Gr: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_GR_N (0U)
 *   I_C04_GR_D1 (1U)
 *   I_C04_GR_D2 (2U)
 *   I_C04_GR_D3 (3U)
 *   I_C04_GR_D4 (4U)
 *   I_C04_GR_D5 (5U)
 *   I_C04_GR_D6 (6U)
 *   I_C04_GR_D7 (7U)
 *   I_C04_GR_D8 (8U)
 *   I_C04_GR_D9 (9U)
 *   I_C04_GR_R (11U)
 *   I_C04_GR_R2 (12U)
 *   I_C04_GR_P (13U)
 *   I_C04_GR_PWRFREE (14U)
 *   I_C04_GR_SNA (15U)
 * c04_Gr_Target: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_GR_TARGET_N (0U)
 *   I_C04_GR_TARGET_D1 (1U)
 *   I_C04_GR_TARGET_D2 (2U)
 *   I_C04_GR_TARGET_D3 (3U)
 *   I_C04_GR_TARGET_D4 (4U)
 *   I_C04_GR_TARGET_D5 (5U)
 *   I_C04_GR_TARGET_D6 (6U)
 *   I_C04_GR_TARGET_D7 (7U)
 *   I_C04_GR_TARGET_D8 (8U)
 *   I_C04_GR_TARGET_D9 (9U)
 *   I_C04_GR_TARGET_R (11U)
 *   I_C04_GR_TARGET_R2 (12U)
 *   I_C04_GR_TARGET_P (13U)
 *   I_C04_GR_TARGET_ABORT (14U)
 *   I_C04_GR_TARGET_SNA (15U)
 * c04_NDef_Man_Auto: Enumeration of integer in interval [1...15] with enumerators
 *   I_C04_NDEF_MAN_AUTO_MANUAL (1U)
 *   I_C04_NDEF_MAN_AUTO_AUTO (2U)
 *   I_C04_NDEF_MAN_AUTO_SNA (15U)
 * c04_Presf_Frct_ST3: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D0 (0U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D1 (1U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D2 (2U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D3 (3U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D4 (4U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D5 (5U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D6 (6U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D7 (7U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D8 (8U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_0D9 (9U)
 *   I_C04_PRESF_FRCT_ST3_FRICT_1D0 (10U)
 *   I_C04_PRESF_FRCT_ST3_SNA (15U)
 * c04_Presf_Lvl_V2: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_PRESF_LVL_V2_NOLVL (0U)
 *   I_C04_PRESF_LVL_V2_LVL1 (1U)
 *   I_C04_PRESF_LVL_V2_LVL2 (2U)
 *   I_C04_PRESF_LVL_V2_LVL3 (3U)
 *   I_C04_PRESF_LVL_V2_LVL4 (4U)
 *   I_C04_PRESF_LVL_V2_LVL5 (5U)
 *   I_C04_PRESF_LVL_V2_LVL6 (6U)
 *   I_C04_PRESF_LVL_V2_LVL7 (7U)
 *   I_C04_PRESF_LVL_V2_LVL8 (8U)
 *   I_C04_PRESF_LVL_V2_SNA (15U)
 * c04_VehOpMode: Enumeration of integer in interval [0...15] with enumerators
 *   I_C04_VEHOPMODE_DRV (0U)
 *   I_C04_VEHOPMODE_DIAG (1U)
 *   I_C04_VEHOPMODE_REMSTART_PRECON (2U)
 *   I_C04_VEHOPMODE_ENG_RUN_CONT (3U)
 *   I_C04_VEHOPMODE_KEY_PARK (4U)
 *   I_C04_VEHOPMODE_REMSTART_BAT_CHRG (5U)
 *   I_C04_VEHOPMODE_AVP (6U)
 *   I_C04_VEHOPMODE_SDC (7U)
 *   I_C04_VEHOPMODE_SNA (15U)
 * c05_ADAS_ProfShort_ProfTyp: Enumeration of integer in interval [1...31] with enumerators
 *   I_C05_ADAS_PROFSHORT_PROFTYP_CURVATURE_LINEAR (1U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_ROUTE_NUMBER_TYPES (2U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_SLOPE_STEP (3U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_SLOPE_LINEAR (4U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_ROAD_ACCESSIBILITY (5U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_ROAD_CONDITION (6U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_VARIABLE_SPEED_SIGN_POSITION (7U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_HEADING_CHANGE_SPOT (8U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_MBC_SLA_LOCATION_TYPE (16U)
 *   I_C05_ADAS_PROFSHORT_PROFTYP_SNA (31U)
 * c05_DPC_Md_PT_HU: Enumeration of integer in interval [0...31] with enumerators
 *   I_C05_DPC_MD_PT_HU_INIT (0U)
 *   I_C05_DPC_MD_PT_HU_COMFORT (1U)
 *   I_C05_DPC_MD_PT_HU_ECO (2U)
 *   I_C05_DPC_MD_PT_HU_SPORT (3U)
 *   I_C05_DPC_MD_PT_HU_SPORT_PLUS (4U)
 *   I_C05_DPC_MD_PT_HU_MANUAL (5U)
 *   I_C05_DPC_MD_PT_HU_OFFROAD1 (6U)
 *   I_C05_DPC_MD_PT_HU_OFFROAD2 (7U)
 *   I_C05_DPC_MD_PT_HU_EDRIVE (8U)
 *   I_C05_DPC_MD_PT_HU_RACE (9U)
 *   I_C05_DPC_MD_PT_HU_BAT_LVL (10U)
 *   I_C05_DPC_MD_PT_HU_URBANCRUISEAMG (11U)
 *   I_C05_DPC_MD_PT_HU_ALLROAD (12U)
 *   I_C05_DPC_MD_PT_HU_MAX_RANGE (13U)
 *   I_C05_DPC_MD_PT_HU_SNA (31U)
 * c05_DPC_Md_Susp_V2: Enumeration of integer in interval [1...31] with enumerators
 *   I_C05_DPC_MD_SUSP_V2_ONROAD1URBANCRUISEAMG (1U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD2 (2U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD3 (3U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD4 (4U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD5 (5U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD6 (6U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD7 (7U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD8 (8U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD9 (9U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD10 (10U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD11 (11U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD12 (12U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD13 (13U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD14 (14U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD15 (15U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD16 (16U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD17 (17U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD18 (18U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD19 (19U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD20 (20U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD21 (21U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD22 (22U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD23 (23U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD24 (24U)
 *   I_C05_DPC_MD_SUSP_V2_ONROAD25 (25U)
 *   I_C05_DPC_MD_SUSP_V2_OFFROAD1 (26U)
 *   I_C05_DPC_MD_SUSP_V2_OFFROAD2 (27U)
 *   I_C05_DPC_MD_SUSP_V2_OFFROAD3 (28U)
 *   I_C05_DPC_MD_SUSP_V2_ALLROAD (29U)
 *   I_C05_DPC_MD_SUSP_V2_SNA (31U)
 * c05_perc_0_31_3k333: Enumeration of integer in interval [0...31] with enumerators
 *   I_C05_PERC_0_31_3K333_SNA (31U)
 * c06_ADAS_MapVerYear: Enumeration of integer in interval [0...63] with enumerators
 *   I_C06_ADAS_MAPVERYEAR_SNA (63U)
 * c06_EVC_BodyStyle_ST3: Enumeration of integer in interval [0...63] with enumerators
 *   I_C06_EVC_BODYSTYLE_ST3_FW (0U)
 *   I_C06_EVC_BODYSTYLE_ST3_FV (1U)
 *   I_C06_EVC_BODYSTYLE_ST3_FC (2U)
 *   I_C06_EVC_BODYSTYLE_ST3_FS (3U)
 *   I_C06_EVC_BODYSTYLE_ST3_FA (4U)
 *   I_C06_EVC_BODYSTYLE_ST3_FR (5U)
 *   I_C06_EVC_BODYSTYLE_ST3_FT (12U)
 *   I_C06_EVC_BODYSTYLE_ST3_FX (13U)
 *   I_C06_EVC_BODYSTYLE_ST3_FH (15U)
 *   I_C06_EVC_BODYSTYLE_ST3_FZ (16U)
 *   I_C06_EVC_BODYSTYLE_ST3_FN (17U)
 *   I_C06_EVC_BODYSTYLE_ST3_OTHER (63U)
 * c06_EVC_VehLine_ST3: Enumeration of integer in interval [0...63] with enumerators
 *   I_C06_EVC_VEHLINE_ST3_BR223 (0U)
 *   I_C06_EVC_VEHLINE_ST3_BR231 (1U)
 *   I_C06_EVC_VEHLINE_ST3_BR214 (2U)
 *   I_C06_EVC_VEHLINE_ST3_BR206 (3U)
 *   I_C06_EVC_VEHLINE_ST3_BR222 (4U)
 *   I_C06_EVC_VEHLINE_ST3_BR166 (8U)
 *   I_C06_EVC_VEHLINE_ST3_BR207 (9U)
 *   I_C06_EVC_VEHLINE_ST3_BR463 (10U)
 *   I_C06_EVC_VEHLINE_ST3_BR217 (11U)
 *   I_C06_EVC_VEHLINE_ST3_BR232 (12U)
 *   I_C06_EVC_VEHLINE_ST3_BR213 (13U)
 *   I_C06_EVC_VEHLINE_ST3_BR238 (14U)
 *   I_C06_EVC_VEHLINE_ST3_BR173 (18U)
 *   I_C06_EVC_VEHLINE_ST3_BR167 (19U)
 *   I_C06_EVC_VEHLINE_ST3_BR177 (20U)
 *   I_C06_EVC_VEHLINE_ST3_BR190 (21U)
 *   I_C06_EVC_VEHLINE_ST3_BR257 (23U)
 *   I_C06_EVC_VEHLINE_ST3_BR258 (32U)
 *   I_C06_EVC_VEHLINE_ST3_BR290 (34U)
 *   I_C06_EVC_VEHLINE_ST3_BR447 (38U)
 *   I_C06_EVC_VEHLINE_ST3_BR253 (39U)
 *   I_C06_EVC_VEHLINE_ST3_BR292 (40U)
 *   I_C06_EVC_VEHLINE_ST3_BR252 (41U)
 *   I_C06_EVC_VEHLINE_ST3_BR247 (42U)
 *   I_C06_EVC_VEHLINE_ST3_BR118 (43U)
 *   I_C06_EVC_VEHLINE_ST3_BR907 (44U)
 *   I_C06_EVC_VEHLINE_ST3_BR910 (45U)
 *   I_C06_EVC_VEHLINE_ST3_BR470 (46U)
 *   I_C06_EVC_VEHLINE_ST3_BR293 (47U)
 *   I_C06_EVC_VEHLINE_ST3_BR243 (48U)
 *   I_C06_EVC_VEHLINE_ST3_BR298 (49U)
 *   I_C06_EVC_VEHLINE_ST3_BR226 (50U)
 *   I_C06_EVC_VEHLINE_ST3_BR236 (51U)
 *   I_C06_EVC_VEHLINE_ST3_BR239 (52U)
 *   I_C06_EVC_VEHLINE_ST3_BR254 (53U)
 *   I_C06_EVC_VEHLINE_ST3_BR294 (54U)
 *   I_C06_EVC_VEHLINE_ST3_BR295 (55U)
 *   I_C06_EVC_VEHLINE_ST3_BR296 (56U)
 *   I_C06_EVC_VEHLINE_ST3_BR297 (57U)
 *   I_C06_EVC_VEHLINE_ST3_OTHER (63U)
 * c06_Idx_0_to_63_1: Enumeration of integer in interval [0...63] with enumerators
 *   I_C06_IDX_0_TO_63_1_UNKNOWN (0U)
 *   I_C06_IDX_0_TO_63_1_NOT_DIGIT (1U)
 *   I_C06_IDX_0_TO_63_1_NOT_ROAD (2U)
 *   I_C06_IDX_0_TO_63_1_NOT_CALIB (3U)
 *   I_C06_IDX_0_TO_63_1_CURR_SEG (4U)
 *   I_C06_IDX_0_TO_63_1_STUB_ONLY (5U)
 *   I_C06_IDX_0_TO_63_1_THIS_PATH (6U)
 *   I_C06_IDX_0_TO_63_1_RES7 (7U)
 * c07_per_0to100_1_SNA: Enumeration of integer in interval [0...127] with enumerators
 *   I_C07_PER_0TO100_1_SNA_SNA (127U)
 * c08_EVC_Country_extended: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_EVC_COUNTRY_EXTENDED_DEU (0U)
 *   I_C08_EVC_COUNTRY_EXTENDED_DEU_IMPORT (1U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ALB (2U)
 *   I_C08_EVC_COUNTRY_EXTENDED_AZE (3U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BGR (4U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ARM (5U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MDA (6U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GEO (7U)
 *   I_C08_EVC_COUNTRY_EXTENDED_EST (8U)
 *   I_C08_EVC_COUNTRY_EXTENDED_RUS (9U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LVA (10U)
 *   I_C08_EVC_COUNTRY_EXTENDED_UKR (11U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LTU (12U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BLR (13U)
 *   I_C08_EVC_COUNTRY_EXTENDED_FIN (14U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ISL (15U)
 *   I_C08_EVC_COUNTRY_EXTENDED_HRV (16U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MKD (17U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MNE (18U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SRB (19U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BEL (20U)
 *   I_C08_EVC_COUNTRY_EXTENDED_DNK (21U)
 *   I_C08_EVC_COUNTRY_EXTENDED_FRA (22U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GRC (23U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GBR (24U)
 *   I_C08_EVC_COUNTRY_EXTENDED_IRL (25U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ITA (26U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SVN (27U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LUX (28U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MLT (29U)
 *   I_C08_EVC_COUNTRY_EXTENDED_NDL (30U)
 *   I_C08_EVC_COUNTRY_EXTENDED_AUT (31U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PRT (32U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SWE (33U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CHE (34U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ESP (35U)
 *   I_C08_EVC_COUNTRY_EXTENDED_NOR (36U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BIH (37U)
 *   I_C08_EVC_COUNTRY_EXTENDED_POL (38U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ROU (39U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CZE (40U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SVK (41U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TUR (42U)
 *   I_C08_EVC_COUNTRY_EXTENDED_HUN (43U)
 *   I_C08_EVC_COUNTRY_EXTENDED_EGY (44U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GAB (45U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CAF (46U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ETH (47U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ERI (48U)
 *   I_C08_EVC_COUNTRY_EXTENDED_DZA (49U)
 *   I_C08_EVC_COUNTRY_EXTENDED_AGO (50U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GMB (51U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GHA (52U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ZAF (53U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TZA (54U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TGO (55U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BEN (56U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TUN (57U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MRT (58U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SEN (59U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MLI (60U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BFA (61U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GNB (62U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GIN (63U)
 *   I_C08_EVC_COUNTRY_EXTENDED_STP (64U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GNQ (65U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CPV (66U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TCD (67U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CMR (68U)
 *   I_C08_EVC_COUNTRY_EXTENDED_KEN (69U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CAN (70U)
 *   I_C08_EVC_COUNTRY_EXTENDED_USA (71U)
 *   I_C08_EVC_COUNTRY_EXTENDED_USA_CKD (72U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SX (73U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CW (74U)
 *   I_C08_EVC_COUNTRY_EXTENDED_AW (75U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CRI (76U)
 *   I_C08_EVC_COUNTRY_EXTENDED_VGB (77U)
 *   I_C08_EVC_COUNTRY_EXTENDED_DOM (78U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GTM (79U)
 *   I_C08_EVC_COUNTRY_EXTENDED_HTI (80U)
 *   I_C08_EVC_COUNTRY_EXTENDED_HND (81U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CUB (82U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MEX (83U)
 *   I_C08_EVC_COUNTRY_EXTENDED_NIC (84U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PAN (85U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SLV (86U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BHS (87U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BRB (88U)
 *   I_C08_EVC_COUNTRY_EXTENDED_JAM (89U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BHR (90U)
 *   I_C08_EVC_COUNTRY_EXTENDED_QAT (91U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TWN (92U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CHN (93U)
 *   I_C08_EVC_COUNTRY_EXTENDED_HKG (94U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MAC (95U)
 *   I_C08_EVC_COUNTRY_EXTENDED_JPN (96U)
 *   I_C08_EVC_COUNTRY_EXTENDED_KOR (97U)
 *   I_C08_EVC_COUNTRY_EXTENDED_KWT (98U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MYS (99U)
 *   I_C08_EVC_COUNTRY_EXTENDED_OMN (100U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MNG (101U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SAU (102U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SGP (103U)
 *   I_C08_EVC_COUNTRY_EXTENDED_AE_AZ (104U)
 *   I_C08_EVC_COUNTRY_EXTENDED_THA (105U)
 *   I_C08_EVC_COUNTRY_EXTENDED_AE_DU (106U)
 *   I_C08_EVC_COUNTRY_EXTENDED_VNM (107U)
 *   I_C08_EVC_COUNTRY_EXTENDED_YEM (108U)
 *   I_C08_EVC_COUNTRY_EXTENDED_JOR (109U)
 *   I_C08_EVC_COUNTRY_EXTENDED_KHM (110U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PRK (111U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LAO (112U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LBN (113U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MDV (114U)
 *   I_C08_EVC_COUNTRY_EXTENDED_NPL (115U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PAK (116U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BGD (117U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PHL (118U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SYR (119U)
 *   I_C08_EVC_COUNTRY_EXTENDED_AUS (120U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CAYMAN (121U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PNG (122U)
 *   I_C08_EVC_COUNTRY_EXTENDED_NZL (123U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TTO (124U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LCA (125U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PYF (126U)
 *   I_C08_EVC_COUNTRY_EXTENDED_NCL (127U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TON (128U)
 *   I_C08_EVC_COUNTRY_EXTENDED_WSM (129U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ARG (130U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BOL (131U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BRA (132U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CHL (133U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ECU (134U)
 *   I_C08_EVC_COUNTRY_EXTENDED_GUY (135U)
 *   I_C08_EVC_COUNTRY_EXTENDED_COL (136U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PRY (137U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PER (138U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SUR (139U)
 *   I_C08_EVC_COUNTRY_EXTENDED_URY (140U)
 *   I_C08_EVC_COUNTRY_EXTENDED_VEN (141U)
 *   I_C08_EVC_COUNTRY_EXTENDED_AFG (142U)
 *   I_C08_EVC_COUNTRY_EXTENDED_W_JORDAN (143U)
 *   I_C08_EVC_COUNTRY_EXTENDED_KAZ (144U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MMR (145U)
 *   I_C08_EVC_COUNTRY_EXTENDED_KGZ (146U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BRN (147U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TJK (148U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LKA (149U)
 *   I_C08_EVC_COUNTRY_EXTENDED_TKM (150U)
 *   I_C08_EVC_COUNTRY_EXTENDED_UZB (151U)
 *   I_C08_EVC_COUNTRY_EXTENDED_PSE (152U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CYP_SOUTH (153U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CYP_NORTH (154U)
 *   I_C08_EVC_COUNTRY_EXTENDED_IND (155U)
 *   I_C08_EVC_COUNTRY_EXTENDED_IDN (156U)
 *   I_C08_EVC_COUNTRY_EXTENDED_IRQ (157U)
 *   I_C08_EVC_COUNTRY_EXTENDED_IRN (158U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ISR (159U)
 *   I_C08_EVC_COUNTRY_EXTENDED_UGA (160U)
 *   I_C08_EVC_COUNTRY_EXTENDED_COD (161U)
 *   I_C08_EVC_COUNTRY_EXTENDED_COG (162U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LBR (163U)
 *   I_C08_EVC_COUNTRY_EXTENDED_CIV (164U)
 *   I_C08_EVC_COUNTRY_EXTENDED_LBY (165U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MDG (166U)
 *   I_C08_EVC_COUNTRY_EXTENDED_COM (167U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MAR (168U)
 *   I_C08_EVC_COUNTRY_EXTENDED_NGA (169U)
 *   I_C08_EVC_COUNTRY_EXTENDED_NER (170U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MOZ (171U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ZWE (172U)
 *   I_C08_EVC_COUNTRY_EXTENDED_ZMB (173U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MWI (174U)
 *   I_C08_EVC_COUNTRY_EXTENDED_RWA (175U)
 *   I_C08_EVC_COUNTRY_EXTENDED_BDI (176U)
 *   I_C08_EVC_COUNTRY_EXTENDED_MUS (177U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SYC (178U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SLE (179U)
 *   I_C08_EVC_COUNTRY_EXTENDED_DJI (180U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SOM (181U)
 *   I_C08_EVC_COUNTRY_EXTENDED_SDN (182U)
 *   I_C08_EVC_COUNTRY_EXTENDED_OTHER (255U)
 * c08_ROE_0: Enumeration of integer in interval [0...6] with enumerators
 *   I_C08_ROE_0_IDLE (0U)
 *   I_C08_ROE_0_DTC_STATUS_CHANGE (1U)
 *   I_C08_ROE_0_OBSOLESCENCE_DATA (2U)
 *   I_C08_ROE_0_CONSUMABLE_DATA (3U)
 *   I_C08_ROE_0_AVAILABILITY_DATA (4U)
 *   I_C08_ROE_0_DIAG_SESSION_CHANGE (5U)
 *   I_C08_ROE_0_SECURITY_EVENT_NOTIFICATION (6U)
 * c08_TxDrvPosn: Enumeration of integer in interval [1...255] with enumerators
 *   I_C08_TXDRVPOSN_M1 (1U)
 *   I_C08_TXDRVPOSN_M2 (2U)
 *   I_C08_TXDRVPOSN_M3 (3U)
 *   I_C08_TXDRVPOSN_M4 (4U)
 *   I_C08_TXDRVPOSN_M5 (5U)
 *   I_C08_TXDRVPOSN_M6 (6U)
 *   I_C08_TXDRVPOSN_M7 (7U)
 *   I_C08_TXDRVPOSN_M8 (8U)
 *   I_C08_TXDRVPOSN_M9 (9U)
 *   I_C08_TXDRVPOSN_BLANK (32U)
 *   I_C08_TXDRVPOSN_D_AUTO_RADAR_RECUP (33U)
 *   I_C08_TXDRVPOSN_D_MAN_MIN_RECUP (34U)
 *   I_C08_TXDRVPOSN_D_MAN_DEFAULT_RECUP (35U)
 *   I_C08_TXDRVPOSN_D_MAN_MAX_RECUP (36U)
 *   I_C08_TXDRVPOSN_D_MAN_SPORT_RECUP (37U)
 *   I_C08_TXDRVPOSN_D1 (49U)
 *   I_C08_TXDRVPOSN_D2 (50U)
 *   I_C08_TXDRVPOSN_D3 (51U)
 *   I_C08_TXDRVPOSN_D4 (52U)
 *   I_C08_TXDRVPOSN_D5 (53U)
 *   I_C08_TXDRVPOSN_D6 (54U)
 *   I_C08_TXDRVPOSN_D7 (55U)
 *   I_C08_TXDRVPOSN_D8 (56U)
 *   I_C08_TXDRVPOSN_D9 (57U)
 *   I_C08_TXDRVPOSN_A (65U)
 *   I_C08_TXDRVPOSN_D (68U)
 *   I_C08_TXDRVPOSN_F (70U)
 *   I_C08_TXDRVPOSN_N (78U)
 *   I_C08_TXDRVPOSN_P (80U)
 *   I_C08_TXDRVPOSN_R (82U)
 *   I_C08_TXDRVPOSN_SNA (255U)
 * c08_V_0_25k4_0k1: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_V_0_25K4_0K1_SNA (255U)
 * c08_deg_0_358k5_1k417: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_DEG_0_358K5_1K417_UNKNOWN (254U)
 *   I_C08_DEG_0_358K5_1K417_SNA (255U)
 * c08_km_p_h_0_254_1: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_KM_P_H_0_254_1_SNA (255U)
 * c08_km_p_h_30_250_1_NoRcmnd: Enumeration of integer in interval [30...255] with enumerators
 *   I_C08_KM_P_H_30_250_1_NORCMND_NO_RCMND (251U)
 *   I_C08_KM_P_H_30_250_1_NORCMND_SNA (255U)
 * c08_perc_0_100_0k4: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_PERC_0_100_0K4_SNA (255U)
 * c08_perc_0_100_0k5: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_PERC_0_100_0K5_SNA (255U)
 * c09_ADAS_HwVer: Enumeration of integer in interval [0...511] with enumerators
 *   I_C09_ADAS_HWVER_UNKNOWN (0U)
 * c09_km_p_h_0_500_1: Enumeration of integer in interval [0...511] with enumerators
 *   I_C09_KM_P_H_0_500_1_SNA (511U)
 * c09_m_p_s_m12k8_89k2_0k2: Enumeration of integer in interval [0...511] with enumerators
 *   I_C09_M_P_S_M12K8_89K2_0K2_SNA (511U)
 * c09_ms_0_510_5: Enumeration of integer in interval [0...511] with enumerators
 *   I_C09_MS_0_510_5_OLDER (510U)
 *   I_C09_MS_0_510_5_SNA (511U)
 * c10_ADAS_CountryCode: Enumeration of integer in interval [0...1023] with enumerators
 *   I_C10_ADAS_COUNTRYCODE_ESC_CODE (0U)
 *   I_C10_ADAS_COUNTRYCODE_AFG (4U)
 *   I_C10_ADAS_COUNTRYCODE_ALB (8U)
 *   I_C10_ADAS_COUNTRYCODE_ATA (10U)
 *   I_C10_ADAS_COUNTRYCODE_DZA (12U)
 *   I_C10_ADAS_COUNTRYCODE_ASM (16U)
 *   I_C10_ADAS_COUNTRYCODE_AND (20U)
 *   I_C10_ADAS_COUNTRYCODE_AGO (24U)
 *   I_C10_ADAS_COUNTRYCODE_ATG (28U)
 *   I_C10_ADAS_COUNTRYCODE_AZE (31U)
 *   I_C10_ADAS_COUNTRYCODE_ARG (32U)
 *   I_C10_ADAS_COUNTRYCODE_AUS (36U)
 *   I_C10_ADAS_COUNTRYCODE_AUT (40U)
 *   I_C10_ADAS_COUNTRYCODE_BHS (44U)
 *   I_C10_ADAS_COUNTRYCODE_BHR (48U)
 *   I_C10_ADAS_COUNTRYCODE_BGD (50U)
 *   I_C10_ADAS_COUNTRYCODE_ARM (51U)
 *   I_C10_ADAS_COUNTRYCODE_BRB (52U)
 *   I_C10_ADAS_COUNTRYCODE_BEL (56U)
 *   I_C10_ADAS_COUNTRYCODE_BMU (60U)
 *   I_C10_ADAS_COUNTRYCODE_BTN (64U)
 *   I_C10_ADAS_COUNTRYCODE_BOL (68U)
 *   I_C10_ADAS_COUNTRYCODE_BIH (70U)
 *   I_C10_ADAS_COUNTRYCODE_BWA (72U)
 *   I_C10_ADAS_COUNTRYCODE_BVT (74U)
 *   I_C10_ADAS_COUNTRYCODE_BRA (76U)
 *   I_C10_ADAS_COUNTRYCODE_BLZ (84U)
 *   I_C10_ADAS_COUNTRYCODE_IOT (86U)
 *   I_C10_ADAS_COUNTRYCODE_SLB (90U)
 *   I_C10_ADAS_COUNTRYCODE_VGB (92U)
 *   I_C10_ADAS_COUNTRYCODE_BRN (96U)
 *   I_C10_ADAS_COUNTRYCODE_BGR (100U)
 *   I_C10_ADAS_COUNTRYCODE_MMR (104U)
 *   I_C10_ADAS_COUNTRYCODE_BDI (108U)
 *   I_C10_ADAS_COUNTRYCODE_BLR (112U)
 *   I_C10_ADAS_COUNTRYCODE_KHM (116U)
 *   I_C10_ADAS_COUNTRYCODE_CMR (120U)
 *   I_C10_ADAS_COUNTRYCODE_CAN (124U)
 *   I_C10_ADAS_COUNTRYCODE_CPV (132U)
 *   I_C10_ADAS_COUNTRYCODE_CYM (136U)
 *   I_C10_ADAS_COUNTRYCODE_CAF (140U)
 *   I_C10_ADAS_COUNTRYCODE_LKA (144U)
 *   I_C10_ADAS_COUNTRYCODE_TCD (148U)
 *   I_C10_ADAS_COUNTRYCODE_CHL (152U)
 *   I_C10_ADAS_COUNTRYCODE_CHN (156U)
 *   I_C10_ADAS_COUNTRYCODE_TWN (158U)
 *   I_C10_ADAS_COUNTRYCODE_CXR (162U)
 *   I_C10_ADAS_COUNTRYCODE_CCK (166U)
 *   I_C10_ADAS_COUNTRYCODE_COL (170U)
 *   I_C10_ADAS_COUNTRYCODE_COM (174U)
 *   I_C10_ADAS_COUNTRYCODE_MYT (175U)
 *   I_C10_ADAS_COUNTRYCODE_COG (178U)
 *   I_C10_ADAS_COUNTRYCODE_COD (180U)
 *   I_C10_ADAS_COUNTRYCODE_COK (184U)
 *   I_C10_ADAS_COUNTRYCODE_CRI (188U)
 *   I_C10_ADAS_COUNTRYCODE_HRV (191U)
 *   I_C10_ADAS_COUNTRYCODE_CUB (192U)
 *   I_C10_ADAS_COUNTRYCODE_CYP (196U)
 *   I_C10_ADAS_COUNTRYCODE_CZE (203U)
 *   I_C10_ADAS_COUNTRYCODE_BEN (204U)
 *   I_C10_ADAS_COUNTRYCODE_DNK (208U)
 *   I_C10_ADAS_COUNTRYCODE_DMA (212U)
 *   I_C10_ADAS_COUNTRYCODE_DOM (214U)
 *   I_C10_ADAS_COUNTRYCODE_ECU (218U)
 *   I_C10_ADAS_COUNTRYCODE_SLV (222U)
 *   I_C10_ADAS_COUNTRYCODE_GNQ (226U)
 *   I_C10_ADAS_COUNTRYCODE_ETH (231U)
 *   I_C10_ADAS_COUNTRYCODE_ERI (232U)
 *   I_C10_ADAS_COUNTRYCODE_EST (233U)
 *   I_C10_ADAS_COUNTRYCODE_FRO (234U)
 *   I_C10_ADAS_COUNTRYCODE_FLK (238U)
 *   I_C10_ADAS_COUNTRYCODE_SGS (239U)
 *   I_C10_ADAS_COUNTRYCODE_FJI (242U)
 *   I_C10_ADAS_COUNTRYCODE_FIN (246U)
 *   I_C10_ADAS_COUNTRYCODE_ALA (248U)
 *   I_C10_ADAS_COUNTRYCODE_FRA (250U)
 *   I_C10_ADAS_COUNTRYCODE_GUF (254U)
 *   I_C10_ADAS_COUNTRYCODE_PYF (258U)
 *   I_C10_ADAS_COUNTRYCODE_ATF (260U)
 *   I_C10_ADAS_COUNTRYCODE_DJI (262U)
 *   I_C10_ADAS_COUNTRYCODE_GAB (266U)
 *   I_C10_ADAS_COUNTRYCODE_GEO (268U)
 *   I_C10_ADAS_COUNTRYCODE_GMB (270U)
 *   I_C10_ADAS_COUNTRYCODE_PSE (275U)
 *   I_C10_ADAS_COUNTRYCODE_DEU (276U)
 *   I_C10_ADAS_COUNTRYCODE_GHA (288U)
 *   I_C10_ADAS_COUNTRYCODE_GIB (292U)
 *   I_C10_ADAS_COUNTRYCODE_KIR (296U)
 *   I_C10_ADAS_COUNTRYCODE_GRC (300U)
 *   I_C10_ADAS_COUNTRYCODE_GRL (304U)
 *   I_C10_ADAS_COUNTRYCODE_GRD (308U)
 *   I_C10_ADAS_COUNTRYCODE_GLP (312U)
 *   I_C10_ADAS_COUNTRYCODE_GUM (316U)
 *   I_C10_ADAS_COUNTRYCODE_GTM (320U)
 *   I_C10_ADAS_COUNTRYCODE_GIN (324U)
 *   I_C10_ADAS_COUNTRYCODE_GUY (328U)
 *   I_C10_ADAS_COUNTRYCODE_HTI (332U)
 *   I_C10_ADAS_COUNTRYCODE_HMD (334U)
 *   I_C10_ADAS_COUNTRYCODE_VAT (336U)
 *   I_C10_ADAS_COUNTRYCODE_HND (340U)
 *   I_C10_ADAS_COUNTRYCODE_HKG (344U)
 *   I_C10_ADAS_COUNTRYCODE_HUN (348U)
 *   I_C10_ADAS_COUNTRYCODE_ISL (352U)
 *   I_C10_ADAS_COUNTRYCODE_IND (356U)
 *   I_C10_ADAS_COUNTRYCODE_IDN (360U)
 *   I_C10_ADAS_COUNTRYCODE_IRN (364U)
 *   I_C10_ADAS_COUNTRYCODE_IRQ (368U)
 *   I_C10_ADAS_COUNTRYCODE_IRL (372U)
 *   I_C10_ADAS_COUNTRYCODE_ISR (376U)
 *   I_C10_ADAS_COUNTRYCODE_ITA (380U)
 *   I_C10_ADAS_COUNTRYCODE_CIV (384U)
 *   I_C10_ADAS_COUNTRYCODE_JAM (388U)
 *   I_C10_ADAS_COUNTRYCODE_JPN (392U)
 *   I_C10_ADAS_COUNTRYCODE_KAZ (398U)
 *   I_C10_ADAS_COUNTRYCODE_JOR (400U)
 *   I_C10_ADAS_COUNTRYCODE_KEN (404U)
 *   I_C10_ADAS_COUNTRYCODE_PRK (408U)
 *   I_C10_ADAS_COUNTRYCODE_KOR (410U)
 *   I_C10_ADAS_COUNTRYCODE_KWT (414U)
 *   I_C10_ADAS_COUNTRYCODE_KGZ (417U)
 *   I_C10_ADAS_COUNTRYCODE_LAO (418U)
 *   I_C10_ADAS_COUNTRYCODE_LBN (422U)
 *   I_C10_ADAS_COUNTRYCODE_LSO (426U)
 *   I_C10_ADAS_COUNTRYCODE_LVA (428U)
 *   I_C10_ADAS_COUNTRYCODE_LBR (430U)
 *   I_C10_ADAS_COUNTRYCODE_LBY (434U)
 *   I_C10_ADAS_COUNTRYCODE_LIE (438U)
 *   I_C10_ADAS_COUNTRYCODE_LTU (440U)
 *   I_C10_ADAS_COUNTRYCODE_LUX (442U)
 *   I_C10_ADAS_COUNTRYCODE_MAC (446U)
 *   I_C10_ADAS_COUNTRYCODE_MDG (450U)
 *   I_C10_ADAS_COUNTRYCODE_MWI (454U)
 *   I_C10_ADAS_COUNTRYCODE_MYS (458U)
 *   I_C10_ADAS_COUNTRYCODE_MDV (462U)
 *   I_C10_ADAS_COUNTRYCODE_MLI (466U)
 *   I_C10_ADAS_COUNTRYCODE_MLT (470U)
 *   I_C10_ADAS_COUNTRYCODE_MTQ (474U)
 *   I_C10_ADAS_COUNTRYCODE_MRT (478U)
 *   I_C10_ADAS_COUNTRYCODE_MUS (480U)
 *   I_C10_ADAS_COUNTRYCODE_MEX (484U)
 *   I_C10_ADAS_COUNTRYCODE_MCO (492U)
 *   I_C10_ADAS_COUNTRYCODE_MNG (496U)
 *   I_C10_ADAS_COUNTRYCODE_MDA (498U)
 *   I_C10_ADAS_COUNTRYCODE_MNE (499U)
 *   I_C10_ADAS_COUNTRYCODE_MSR (500U)
 *   I_C10_ADAS_COUNTRYCODE_MAR (504U)
 *   I_C10_ADAS_COUNTRYCODE_MOZ (508U)
 *   I_C10_ADAS_COUNTRYCODE_OMN (512U)
 *   I_C10_ADAS_COUNTRYCODE_NAM (516U)
 *   I_C10_ADAS_COUNTRYCODE_NRU (520U)
 *   I_C10_ADAS_COUNTRYCODE_NPL (524U)
 *   I_C10_ADAS_COUNTRYCODE_NLD (528U)
 *   I_C10_ADAS_COUNTRYCODE_ANT (530U)
 *   I_C10_ADAS_COUNTRYCODE_ABW (533U)
 *   I_C10_ADAS_COUNTRYCODE_NCL (540U)
 *   I_C10_ADAS_COUNTRYCODE_VUT (548U)
 *   I_C10_ADAS_COUNTRYCODE_NZL (554U)
 *   I_C10_ADAS_COUNTRYCODE_NIC (558U)
 *   I_C10_ADAS_COUNTRYCODE_NER (562U)
 *   I_C10_ADAS_COUNTRYCODE_NGA (566U)
 *   I_C10_ADAS_COUNTRYCODE_NIU (570U)
 *   I_C10_ADAS_COUNTRYCODE_NFK (574U)
 *   I_C10_ADAS_COUNTRYCODE_NOR (578U)
 *   I_C10_ADAS_COUNTRYCODE_MNP (580U)
 *   I_C10_ADAS_COUNTRYCODE_UMI (581U)
 *   I_C10_ADAS_COUNTRYCODE_FSM (583U)
 *   I_C10_ADAS_COUNTRYCODE_MHL (584U)
 *   I_C10_ADAS_COUNTRYCODE_PLW (585U)
 *   I_C10_ADAS_COUNTRYCODE_PAK (586U)
 *   I_C10_ADAS_COUNTRYCODE_PAN (591U)
 *   I_C10_ADAS_COUNTRYCODE_PNG (598U)
 *   I_C10_ADAS_COUNTRYCODE_PRY (600U)
 *   I_C10_ADAS_COUNTRYCODE_PER (604U)
 *   I_C10_ADAS_COUNTRYCODE_PHL (608U)
 *   I_C10_ADAS_COUNTRYCODE_PCN (612U)
 *   I_C10_ADAS_COUNTRYCODE_POL (616U)
 *   I_C10_ADAS_COUNTRYCODE_PRT (620U)
 *   I_C10_ADAS_COUNTRYCODE_GNB (624U)
 *   I_C10_ADAS_COUNTRYCODE_TLS (626U)
 *   I_C10_ADAS_COUNTRYCODE_PRI (630U)
 *   I_C10_ADAS_COUNTRYCODE_QAT (634U)
 *   I_C10_ADAS_COUNTRYCODE_REU (638U)
 *   I_C10_ADAS_COUNTRYCODE_ROU (642U)
 *   I_C10_ADAS_COUNTRYCODE_RUS (643U)
 *   I_C10_ADAS_COUNTRYCODE_RWA (646U)
 *   I_C10_ADAS_COUNTRYCODE_SHN (654U)
 *   I_C10_ADAS_COUNTRYCODE_KNA (659U)
 *   I_C10_ADAS_COUNTRYCODE_AIA (660U)
 *   I_C10_ADAS_COUNTRYCODE_LCA (662U)
 *   I_C10_ADAS_COUNTRYCODE_SPM (666U)
 *   I_C10_ADAS_COUNTRYCODE_VCT (670U)
 *   I_C10_ADAS_COUNTRYCODE_SMR (674U)
 *   I_C10_ADAS_COUNTRYCODE_STP (678U)
 *   I_C10_ADAS_COUNTRYCODE_SAU (682U)
 *   I_C10_ADAS_COUNTRYCODE_SEN (686U)
 *   I_C10_ADAS_COUNTRYCODE_SRB (688U)
 *   I_C10_ADAS_COUNTRYCODE_SYC (690U)
 *   I_C10_ADAS_COUNTRYCODE_SLE (694U)
 *   I_C10_ADAS_COUNTRYCODE_SGP (702U)
 *   I_C10_ADAS_COUNTRYCODE_SVK (703U)
 *   I_C10_ADAS_COUNTRYCODE_VNM (704U)
 *   I_C10_ADAS_COUNTRYCODE_SVN (705U)
 *   I_C10_ADAS_COUNTRYCODE_SOM (706U)
 *   I_C10_ADAS_COUNTRYCODE_ZAF (710U)
 *   I_C10_ADAS_COUNTRYCODE_ZWE (716U)
 *   I_C10_ADAS_COUNTRYCODE_ESP (724U)
 *   I_C10_ADAS_COUNTRYCODE_ESH (732U)
 *   I_C10_ADAS_COUNTRYCODE_SDN (736U)
 *   I_C10_ADAS_COUNTRYCODE_SUR (740U)
 *   I_C10_ADAS_COUNTRYCODE_SJM (744U)
 *   I_C10_ADAS_COUNTRYCODE_SWZ (748U)
 *   I_C10_ADAS_COUNTRYCODE_SWE (752U)
 *   I_C10_ADAS_COUNTRYCODE_CHE (756U)
 *   I_C10_ADAS_COUNTRYCODE_SYR (760U)
 *   I_C10_ADAS_COUNTRYCODE_TJK (762U)
 *   I_C10_ADAS_COUNTRYCODE_THA (764U)
 *   I_C10_ADAS_COUNTRYCODE_TGO (768U)
 *   I_C10_ADAS_COUNTRYCODE_TKL (772U)
 *   I_C10_ADAS_COUNTRYCODE_TON (776U)
 *   I_C10_ADAS_COUNTRYCODE_TTO (780U)
 *   I_C10_ADAS_COUNTRYCODE_ARE (784U)
 *   I_C10_ADAS_COUNTRYCODE_TUN (788U)
 *   I_C10_ADAS_COUNTRYCODE_TUR (792U)
 *   I_C10_ADAS_COUNTRYCODE_TKM (795U)
 *   I_C10_ADAS_COUNTRYCODE_TCA (796U)
 *   I_C10_ADAS_COUNTRYCODE_TUV (798U)
 *   I_C10_ADAS_COUNTRYCODE_UGA (800U)
 *   I_C10_ADAS_COUNTRYCODE_UKR (804U)
 *   I_C10_ADAS_COUNTRYCODE_MKD (807U)
 *   I_C10_ADAS_COUNTRYCODE_EGY (818U)
 *   I_C10_ADAS_COUNTRYCODE_GBR (826U)
 *   I_C10_ADAS_COUNTRYCODE_GGY (831U)
 *   I_C10_ADAS_COUNTRYCODE_JEY (832U)
 *   I_C10_ADAS_COUNTRYCODE_IMN (833U)
 *   I_C10_ADAS_COUNTRYCODE_TZA (834U)
 *   I_C10_ADAS_COUNTRYCODE_USA (840U)
 *   I_C10_ADAS_COUNTRYCODE_VIR (850U)
 *   I_C10_ADAS_COUNTRYCODE_BFA (854U)
 *   I_C10_ADAS_COUNTRYCODE_URY (858U)
 *   I_C10_ADAS_COUNTRYCODE_UZB (860U)
 *   I_C10_ADAS_COUNTRYCODE_VEN (862U)
 *   I_C10_ADAS_COUNTRYCODE_WLF (876U)
 *   I_C10_ADAS_COUNTRYCODE_WSM (882U)
 *   I_C10_ADAS_COUNTRYCODE_YEM (887U)
 *   I_C10_ADAS_COUNTRYCODE_ZMB (894U)
 *   I_C10_ADAS_COUNTRYCODE_SNA (1023U)
 * c10_PT4_PTCoor_DAS_Hlth_Stat: Enumeration of integer in interval [0...65535] with enumerators
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflMask 32768U (0b1000000000000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflPn 15
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflLn 1
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_TRUE (32768U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflMask 32768U (0b1000000000000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflPn 15
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PT4_PTCoor_DAS_Health_Stat_Invalid_ST3_BflLn 1
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_BflMask 32769U (0b1000000000000001)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_TRUE (1U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Basic_Avl_ST3_BflMask 32769U (0b1000000000000001)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_BflMask 32770U (0b1000000000000010)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_TRUE (2U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_PAx_Full_Avl_ST3_BflMask 32770U (0b1000000000000010)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_BflMask 32772U (0b1000000000000100)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_TRUE (4U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Basic_Avl_ST3_BflMask 32772U (0b1000000000000100)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_BflMask 32776U (0b1000000000001000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_TRUE (8U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Extended_Avl_ST3_BflMask 32776U (0b1000000000001000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_BflMask 32784U (0b1000000000010000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_TRUE (16U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAD_Full_Avl_ST3_BflMask 32784U (0b1000000000010000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_BflMask 32800U (0b1000000000100000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_TRUE (32U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Basic_Avl_ST3_BflMask 32800U (0b1000000000100000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_BflMask 32832U (0b1000000001000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_TRUE (64U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_HAP_Full_Avl_ST3_BflMask 32832U (0b1000000001000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_BflMask 32896U (0b1000000010000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_TRUE (128U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Basic_Avl_ST3_BflMask 32896U (0b1000000010000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_BflMask 33024U (0b1000000100000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_TRUE (256U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Extended_Avl_ST3_BflMask 33024U (0b1000000100000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_FALSE (0U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_BflMask 33280U (0b1000001000000000)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_TRUE (512U)
 *   c10_PT4_PTCoor_DAS_Hlth_Stat_SDC_Full_Avl_ST3_BflMask 33280U (0b1000001000000000)
 * c10_V_0_25k55_0k025: Enumeration of integer in interval [0...1023] with enumerators
 *   I_C10_V_0_25K55_0K025_SNA (1023U)
 * c10_WakeupRsn_ST3: Enumeration of integer in interval [0...1023] with enumerators
 *   I_C10_WAKEUPRSN_ST3_NETWORK (0U)
 *   I_C10_WAKEUPRSN_ST3_NW_MAIN (1U)
 *   I_C10_WAKEUPRSN_ST3_NW_HEADUNIT1 (11U)
 *   I_C10_WAKEUPRSN_ST3_NW_HEADUNIT2 (12U)
 *   I_C10_WAKEUPRSN_ST3_NW_PERIPHERY (13U)
 *   I_C10_WAKEUPRSN_ST3_NW_BODY1 (14U)
 *   I_C10_WAKEUPRSN_ST3_NW_CHASSIS (15U)
 *   I_C10_WAKEUPRSN_ST3_NW_RADAR_R (16U)
 *   I_C10_WAKEUPRSN_ST3_NW_RADAR_F (17U)
 *   I_C10_WAKEUPRSN_ST3_NW_OBD_PTI (18U)
 *   I_C10_WAKEUPRSN_ST3_NW_STEERING_WHEEL (19U)
 *   I_C10_WAKEUPRSN_ST3_NW_CPC (20U)
 *   I_C10_WAKEUPRSN_ST3_NW_ECM (21U)
 *   I_C10_WAKEUPRSN_ST3_NW_ENERGY (22U)
 *   I_C10_WAKEUPRSN_ST3_NW_INV (23U)
 *   I_C10_WAKEUPRSN_ST3_NW_TCM (24U)
 *   I_C10_WAKEUPRSN_ST3_NW_AEPU (25U)
 *   I_C10_WAKEUPRSN_ST3_NW_BODY2 (26U)
 *   I_C10_WAKEUPRSN_ST3_NW_BODY3 (27U)
 *   I_C10_WAKEUPRSN_ST3_NW_CAL_COC (28U)
 *   I_C10_WAKEUPRSN_ST3_NW_CAL_DL (29U)
 *   I_C10_WAKEUPRSN_ST3_NW_CAL_DR (30U)
 *   I_C10_WAKEUPRSN_ST3_NW_ECM_PERIPHERY1 (31U)
 *   I_C10_WAKEUPRSN_ST3_NW_ECM_PERIPHERY2 (32U)
 *   I_C10_WAKEUPRSN_ST3_NW_ENGINE_PT3 (33U)
 *   I_C10_WAKEUPRSN_ST3_NW_HAD_BACKUP (34U)
 *   I_C10_WAKEUPRSN_ST3_NW_HYBRID_PT3 (35U)
 *   I_C10_WAKEUPRSN_ST3_NW_LSM_F (36U)
 *   I_C10_WAKEUPRSN_ST3_NW_POWERTRAIN_PT3 (37U)
 *   I_C10_WAKEUPRSN_ST3_NW_PT_SENSOR_PT3 (38U)
 *   I_C10_WAKEUPRSN_ST3_NW_RVC_HSVL (39U)
 *   I_C10_WAKEUPRSN_ST3_NW_SPV (40U)
 *   I_C10_WAKEUPRSN_ST3_NW_SUSPENSION_F (41U)
 *   I_C10_WAKEUPRSN_ST3_NW_SUSPENSION_R (42U)
 *   I_C10_WAKEUPRSN_ST3_NW_EIS_BASE_GW (43U)
 *   I_C10_WAKEUPRSN_ST3_NW_EIS_GW_BASE (44U)
 *   I_C10_WAKEUPRSN_ST3_NW_AUXILIARY1 (45U)
 *   I_C10_WAKEUPRSN_ST3_NW_AUXILIARY2 (46U)
 *   I_C10_WAKEUPRSN_ST3_NW_DRIVE_UNIT (47U)
 *   I_C10_WAKEUPRSN_ST3_NW_INLET (48U)
 *   I_C10_WAKEUPRSN_ST3_NW_BODY4 (49U)
 *   I_C10_WAKEUPRSN_ST3_LIN_HVAC_F (115U)
 *   I_C10_WAKEUPRSN_ST3_LIN_HVAC_R (116U)
 *   I_C10_WAKEUPRSN_ST3_LIN_VCS (117U)
 *   I_C10_WAKEUPRSN_ST3_LIN_WPRA (118U)
 *   I_C10_WAKEUPRSN_ST3_LIN_IHTM_RC (119U)
 *   I_C10_WAKEUPRSN_ST3_LIN_PTC48_R (120U)
 *   I_C10_WAKEUPRSN_ST3_LIN_AQS (121U)
 *   I_C10_WAKEUPRSN_ST3_LIN_ECP2_1 (122U)
 *   I_C10_WAKEUPRSN_ST3_LIN_EXV1 (123U)
 *   I_C10_WAKEUPRSN_ST3_LIN_IHTM (124U)
 *   I_C10_WAKEUPRSN_ST3_LIN_EAC (125U)
 *   I_C10_WAKEUPRSN_ST3_LIN_EAC48 (126U)
 *   I_C10_WAKEUPRSN_ST3_LIN_PTC_HV (127U)
 *   I_C10_WAKEUPRSN_ST3_TERM_15 (128U)
 *   I_C10_WAKEUPRSN_ST3_TERM_54 (130U)
 *   I_C10_WAKEUPRSN_ST3_LIN_HFA (131U)
 *   I_C10_WAKEUPRSN_ST3_LIN_IBS (132U)
 *   I_C10_WAKEUPRSN_ST3_LIN_DOOR_HANDLE (133U)
 *   I_C10_WAKEUPRSN_ST3_LIN_LISB48 (134U)
 *   I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_POR (135U)
 *   I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_DIAG (136U)
 *   I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_TEST (137U)
 *   I_C10_WAKEUPRSN_ST3_CMN_ECU_RST_ERR (138U)
 *   I_C10_WAKEUPRSN_ST3_CMN_ETH_WAKEUPLINE (139U)
 *   I_C10_WAKEUPRSN_ST3_CMN_AFTERRUN (140U)
 *   I_C10_WAKEUPRSN_ST3_CRASH (141U)
 *   I_C10_WAKEUPRSN_ST3_LIN_VCI (142U)
 *   I_C10_WAKEUPRSN_ST3_LIN_CIS (143U)
 *   I_C10_WAKEUPRSN_ST3_EASY_ENTRY_ACTV (181U)
 *   I_C10_WAKEUPRSN_ST3_ERR_SEAT_HTVN (183U)
 *   I_C10_WAKEUPRSN_ST3_ERR_SEAT_CHM (184U)
 *   I_C10_WAKEUPRSN_ST3_VEHSL_EVENT (199U)
 *   I_C10_WAKEUPRSN_ST3_RLS (200U)
 *   I_C10_WAKEUPRSN_ST3_EF_KEY (201U)
 *   I_C10_WAKEUPRSN_ST3_RHU_FT (202U)
 *   I_C10_WAKEUPRSN_ST3_RHU_R (203U)
 *   I_C10_WAKEUPRSN_ST3_ICH_RQ (204U)
 *   I_C10_WAKEUPRSN_ST3_VPRZR_VN (205U)
 *   I_C10_WAKEUPRSN_ST3_PRECON (206U)
 *   I_C10_WAKEUPRSN_ST3_SOL_VN (207U)
 *   I_C10_WAKEUPRSN_ST3_EXTLGT_ACTV (208U)
 *   I_C10_WAKEUPRSN_ST3_INTLGT_ACTV (209U)
 *   I_C10_WAKEUPRSN_ST3_TSSR_ACTV (210U)
 *   I_C10_WAKEUPRSN_ST3_SEAT_HT_F_ACTV (211U)
 *   I_C10_WAKEUPRSN_ST3_SEAT_HT_R_ACTV (212U)
 *   I_C10_WAKEUPRSN_ST3_SEAT_VN_F_ACTV (213U)
 *   I_C10_WAKEUPRSN_ST3_SEAT_VN_R_ACTV (214U)
 *   I_C10_WAKEUPRSN_ST3_EHS_3S (215U)
 *   I_C10_WAKEUPRSN_ST3_T58D_POTI (216U)
 *   I_C10_WAKEUPRSN_ST3_DRB (217U)
 *   I_C10_WAKEUPRSN_ST3_BKRST_UNLK_RM (218U)
 *   I_C10_WAKEUPRSN_ST3_DL_SW2_PSD (219U)
 *   I_C10_WAKEUPRSN_ST3_DL_SW (220U)
 *   I_C10_WAKEUPRSN_ST3_BGC_SW (221U)
 *   I_C10_WAKEUPRSN_ST3_BKRST_RL_LK_UNLK (222U)
 *   I_C10_WAKEUPRSN_ST3_BKRST_RR_LK_UNLK (223U)
 *   I_C10_WAKEUPRSN_ST3_DL_CLS_LK_SW (224U)
 *   I_C10_WAKEUPRSN_ST3_DL_RLTCH (225U)
 *   I_C10_WAKEUPRSN_ST3_BKRST_3L_LK_UNLK (226U)
 *   I_C10_WAKEUPRSN_ST3_BKRST_3R_LK_UNLK (227U)
 *   I_C10_WAKEUPRSN_ST3_GAS_DR_SW (228U)
 *   I_C10_WAKEUPRSN_ST3_AILCF (229U)
 *   I_C10_WAKEUPRSN_ST3_AILCC (230U)
 *   I_C10_WAKEUPRSN_ST3_TRLR_ELEC_ACT (256U)
 *   I_C10_WAKEUPRSN_ST3_TRLR_DET (257U)
 *   I_C10_WAKEUPRSN_ST3_DL_LK (258U)
 *   I_C10_WAKEUPRSN_ST3_START_SW_PSD (259U)
 *   I_C10_WAKEUPRSN_ST3_RADIO_DATA (260U)
 *   I_C10_WAKEUPRSN_ST3_RLTCH_DR (261U)
 *   I_C10_WAKEUPRSN_ST3_PKBRKSW (263U)
 *   I_C10_WAKEUPRSN_ST3_KEYLESS_GO (264U)
 *   I_C10_WAKEUPRSN_ST3_PNM12 (265U)
 *   I_C10_WAKEUPRSN_ST3_PNM48 (266U)
 *   I_C10_WAKEUPRSN_ST3_BAT48_LOWCHARGE (267U)
 *   I_C10_WAKEUPRSN_ST3_PN14_IODM (270U)
 *   I_C10_WAKEUPRSN_ST3_PN14_REMSRV_STAT (271U)
 *   I_C10_WAKEUPRSN_ST3_PN14_DDP (272U)
 *   I_C10_WAKEUPRSN_ST3_PN14_LOWCHARGE (273U)
 *   I_C10_WAKEUPRSN_ST3_PN14_REMODHV12V (274U)
 *   I_C10_WAKEUPRSN_ST3_PN14_DLM (275U)
 *   I_C10_WAKEUPRSN_ST3_SDC_PN2_LOWCHARGE (276U)
 *   I_C10_WAKEUPRSN_ST3_SDC_PN2_REMODHV12V (277U)
 *   I_C10_WAKEUPRSN_ST3_DATA_EXCHG (280U)
 *   I_C10_WAKEUPRSN_ST3_INTERNET_CON (281U)
 *   I_C10_WAKEUPRSN_ST3_CMN_USER_DATA (282U)
 *   I_C10_WAKEUPRSN_ST3_CMN_SERV_LOCAL (290U)
 *   I_C10_WAKEUPRSN_ST3_CMN_SERV_REM (291U)
 *   I_C10_WAKEUPRSN_ST3_VEH_REAR_LOWERING (292U)
 *   I_C10_WAKEUPRSN_ST3_CMN_BTN_PSD (300U)
 *   I_C10_WAKEUPRSN_ST3_FLAP_PSD (301U)
 *   I_C10_WAKEUPRSN_ST3_CHADEMO (302U)
 *   I_C10_WAKEUPRSN_ST3_GBT (303U)
 *   I_C10_WAKEUPRSN_ST3_CMN_PROXIMITY (304U)
 *   I_C10_WAKEUPRSN_ST3_CTRL_PILOT (305U)
 *   I_C10_WAKEUPRSN_ST3_CMN_HV_DET (306U)
 *   I_C10_WAKEUPRSN_ST3_CMN_CHRG_TMR (307U)
 *   I_C10_WAKEUPRSN_ST3_TRCT_BAT_OP_STRATEGY (308U)
 *   I_C10_WAKEUPRSN_ST3_VTA (309U)
 *   I_C10_WAKEUPRSN_ST3_PDD (310U)
 *   I_C10_WAKEUPRSN_ST3_UNEQUAL_STRING_VOLT (311U)
 *   I_C10_WAKEUPRSN_ST3_MUTE_ACTV (312U)
 *   I_C10_WAKEUPRSN_ST3_VIDEO_RQ (313U)
 *   I_C10_WAKEUPRSN_ST3_ALARM_ACTV (314U)
 *   I_C10_WAKEUPRSN_ST3_RECIRC_AIR_RQ (315U)
 *   I_C10_WAKEUPRSN_ST3_TPM_SYNC (316U)
 *   I_C10_WAKEUPRSN_ST3_DI_DISP_RQ (320U)
 *   I_C10_WAKEUPRSN_ST3_DI_IND_RQ (321U)
 *   I_C10_WAKEUPRSN_ST3_HUD_RQ (322U)
 *   I_C10_WAKEUPRSN_ST3_MSG_DISP_RQ (325U)
 *   I_C10_WAKEUPRSN_ST3_ROOF_LMP_ON_RQ (326U)
 *   I_C10_WAKEUPRSN_ST3_IL_ON_RQ (327U)
 *   I_C10_WAKEUPRSN_ST3_SPS_APPL (328U)
 *   I_C10_WAKEUPRSN_ST3_PWC_WRAPPER (330U)
 *   I_C10_WAKEUPRSN_ST3_PW_SW (331U)
 *   I_C10_WAKEUPRSN_ST3_CLKS_SW (332U)
 *   I_C10_WAKEUPRSN_ST3_SEAT_SW (333U)
 *   I_C10_WAKEUPRSN_ST3_DL_REM_SW (334U)
 *   I_C10_WAKEUPRSN_ST3_TANK_UNLK_SW (335U)
 *   I_C10_WAKEUPRSN_ST3_SLTCH_DR (336U)
 *   I_C10_WAKEUPRSN_ST3_INSRLVR_SW (337U)
 *   I_C10_WAKEUPRSN_ST3_OUTSRLVR_SW (338U)
 *   I_C10_WAKEUPRSN_ST3_TRL_HTCH_SW (339U)
 *   I_C10_WAKEUPRSN_ST3_TSSR_R_RB_SW (340U)
 *   I_C10_WAKEUPRSN_ST3_CSL_SW (341U)
 *   I_C10_WAKEUPRSN_ST3_GEAR_SW (342U)
 *   I_C10_WAKEUPRSN_ST3_AD_SW (343U)
 *   I_C10_WAKEUPRSN_ST3_T2R_SW (344U)
 *   I_C10_WAKEUPRSN_ST3_HV_INTERLOCK_ERR (345U)
 *   I_C10_WAKEUPRSN_ST3_NFC (346U)
 *   I_C10_WAKEUPRSN_ST3_POLLING (347U)
 *   I_C10_WAKEUPRSN_ST3_TSL_P_PSD (348U)
 *   I_C10_WAKEUPRSN_ST3_STWHL_LVR_PSD (349U)
 *   I_C10_WAKEUPRSN_ST3_BAT14_DDP (350U)
 *   I_C10_WAKEUPRSN_ST3_BAT14_LOWCHARGE (351U)
 *   I_C10_WAKEUPRSN_ST3_BAT14_CHARGECURR (352U)
 *   I_C10_WAKEUPRSN_ST3_BAT14_IODM (353U)
 *   I_C10_WAKEUPRSN_ST3_BAT14_IODAVG (354U)
 *   I_C10_WAKEUPRSN_ST3_FOTA_TMR (400U)
 *   I_C10_WAKEUPRSN_ST3_RESERVE_3 (1020U)
 *   I_C10_WAKEUPRSN_ST3_RESERVE_2 (1021U)
 *   I_C10_WAKEUPRSN_ST3_RESERVE_1 (1022U)
 *   I_C10_WAKEUPRSN_ST3_SNA (1023U)
 * c10_m_0_510_1: Enumeration of integer in interval [0...1023] with enumerators
 *   I_C10_M_0_510_1_SNA (1023U)
 * c10_to_1022_1: Enumeration of integer in interval [0...1023] with enumerators
 *   I_C10_TO_1022_1_SNA (1023U)
 * c12_0_4094_1_SNA: Enumeration of integer in interval [0...4095] with enumerators
 *   I_C12_0_4094_1_SNA_SNA (4095U)
 * c12_km_p_h_0_409k4_0k1: Enumeration of integer in interval [0...4095] with enumerators
 *   I_C12_KM_P_H_0_409K4_0K1_SNA (4095U)
 * c12_rpm_0_16376_4: Enumeration of integer in interval [0...4095] with enumerators
 *   I_C12_RPM_0_16376_4_SNA (4095U)
 * c13_PresfAct_Adj_Rq: Enumeration of integer in interval [0...4294967295] with enumerators
 *   c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflMask 1U (0b00000000000000000000000000000001)
 *   c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflPn 0
 *   c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_TRUE (1U)
 *   c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflMask 1U (0b00000000000000000000000000000001)
 *   c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflPn 0
 *   c13_PresfAct_Adj_Rq_PresfAct1_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflMask 2U (0b00000000000000000000000000000010)
 *   c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflPn 1
 *   c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_TRUE (2U)
 *   c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflMask 2U (0b00000000000000000000000000000010)
 *   c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflPn 1
 *   c13_PresfAct_Adj_Rq_PresfAct2_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflMask 4U (0b00000000000000000000000000000100)
 *   c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflPn 2
 *   c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_TRUE (4U)
 *   c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflMask 4U (0b00000000000000000000000000000100)
 *   c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflPn 2
 *   c13_PresfAct_Adj_Rq_PresfAct3_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflMask 8U (0b00000000000000000000000000001000)
 *   c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflPn 3
 *   c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_TRUE (8U)
 *   c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflMask 8U (0b00000000000000000000000000001000)
 *   c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflPn 3
 *   c13_PresfAct_Adj_Rq_PresfAct4_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflMask 16U (0b00000000000000000000000000010000)
 *   c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflPn 4
 *   c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_TRUE (16U)
 *   c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflMask 16U (0b00000000000000000000000000010000)
 *   c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflPn 4
 *   c13_PresfAct_Adj_Rq_PresfAct5_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflMask 32U (0b00000000000000000000000000100000)
 *   c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflPn 5
 *   c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_TRUE (32U)
 *   c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflMask 32U (0b00000000000000000000000000100000)
 *   c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflPn 5
 *   c13_PresfAct_Adj_Rq_PresfAct6_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflMask 64U (0b00000000000000000000000001000000)
 *   c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflPn 6
 *   c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_TRUE (64U)
 *   c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflMask 64U (0b00000000000000000000000001000000)
 *   c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflPn 6
 *   c13_PresfAct_Adj_Rq_PresfAct7_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflMask 128U (0b00000000000000000000000010000000)
 *   c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflPn 7
 *   c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_TRUE (128U)
 *   c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflMask 128U (0b00000000000000000000000010000000)
 *   c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflPn 7
 *   c13_PresfAct_Adj_Rq_PresfAct8_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflMask 256U (0b00000000000000000000000100000000)
 *   c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflPn 8
 *   c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_TRUE (256U)
 *   c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflMask 256U (0b00000000000000000000000100000000)
 *   c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflPn 8
 *   c13_PresfAct_Adj_Rq_PresfAct9_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflMask 512U (0b00000000000000000000001000000000)
 *   c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflPn 9
 *   c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_TRUE (512U)
 *   c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflMask 512U (0b00000000000000000000001000000000)
 *   c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflPn 9
 *   c13_PresfAct_Adj_Rq_PresfAct10_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflMask 1024U (0b00000000000000000000010000000000)
 *   c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflPn 10
 *   c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_TRUE (1024U)
 *   c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflMask 1024U (0b00000000000000000000010000000000)
 *   c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflPn 10
 *   c13_PresfAct_Adj_Rq_PresfAct11_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflMask 2048U (0b00000000000000000000100000000000)
 *   c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflPn 11
 *   c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_TRUE (2048U)
 *   c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflMask 2048U (0b00000000000000000000100000000000)
 *   c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflPn 11
 *   c13_PresfAct_Adj_Rq_PresfAct12_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_FALSE (0U)
 *   c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflMask 4096U (0b00000000000000000001000000000000)
 *   c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflPn 12
 *   c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflLn 1
 *   c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_TRUE (4096U)
 *   c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflMask 4096U (0b00000000000000000001000000000000)
 *   c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflPn 12
 *   c13_PresfAct_Adj_Rq_PresfAct13_Adj_Rq_ST3_BflLn 1
 * c13_m_0_8190_1: Enumeration of integer in interval [0...8191] with enumerators
 *   I_C13_M_0_8190_1_SNA (8191U)
 * c14_rpm_0_16382_1: Enumeration of integer in interval [0...16383] with enumerators
 *   I_C14_RPM_0_16382_1_SNA (16383U)
 * c15_ADAS_RegionCode: Enumeration of integer in interval [0...32767] with enumerators
 *   I_C15_ADAS_REGIONCODE_UNKWN (0U)
 *   I_C15_ADAS_REGIONCODE_SNA (32767U)
 * c24_km_0_999999k9_0k1_Invld_SNA: Enumeration of integer in interval [0...16777215] with enumerators
 *   I_C24_KM_0_999999K9_0K1_INVLD_SNA_INVLD (16777214U)
 *   I_C24_KM_0_999999K9_0K1_INVLD_SNA_SNA (16777215U)
 * cDC_errorCode_ST3: Enumeration of integer in interval [0...254] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * cDC_keyStorageTask_ST3: Enumeration of integer in interval [0...2] with enumerators
 *   SSA_KEYSTORAGE_TASK_INITIAL (0U)
 *   SSA_KEYSTORAGE_TASK_CHECKSTATE (1U)
 *   SSA_KEYSTORAGE_TASK_CANCEL (2U)
 * cDC_keyStorageUseCase_ST3: Enumeration of integer in interval [0...1] with enumerators
 *   SSA_KEYSTORAGE_USECASE_CRYPTO (0U)
 *   SSA_KEYSTORAGE_USECASE_CERTIFICATES (1U)
 * cDC_syncState_ST3: Enumeration of integer in interval [0...2] with enumerators
 *   SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED (0U)
 *   SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_MASTER (1U)
 *   SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM (2U)
 * c_DC_VIN_Stat_ST3: Enumeration of integer in interval [0...2] with enumerators
 *   VIN_STATUS_NEW_VIN_RECEIVED (0U)
 *   VIN_STATUS_VIN_CORRECT_RECEIVED (1U)
 *   VIN_STATUS_VIN_NOT_RECEIVED (2U)
 *
 * Array Types:
 * ============
 * ARR_08_UInt_noSNA_17: Array with 17 element(s) of type c08_UInt_SNA_na
 * ARR_08_UInt_noSNA_32: Array with 32 element(s) of type c08_UInt_SNA_na
 * ARR_08_UInt_noSNA_64: Array with 64 element(s) of type c08_UInt_SNA_na
 * ARR_08_UInt_noSNA_7: Array with 7 element(s) of type c08_UInt_SNA_na
 * ARR_08_UInt_noSNA_8: Array with 8 element(s) of type c08_UInt_SNA_na
 *
 * Record Types:
 * =============
 * REC_ADAS_Meta_ST3: Record with elements
 *   ADAS_Meta_CountryCode_ST3 of type c10_ADAS_CountryCode
 *   ADAS_Meta_CycCnt_ST3 of type c02_0_3_1_nSNA
 *   ADAS_Meta_DrvSide_ST3 of type c01_Right_Left
 *   ADAS_Meta_HwVer_ST3 of type c09_ADAS_HwVer
 *   ADAS_Meta_MapProvid_ST3 of type c03_ADAS_MapProvid
 *   ADAS_Meta_MapVerQuar_ST3 of type c02_ADAS_MapVerQuar
 *   ADAS_Meta_MapVerYear_ST3 of type c06_ADAS_MapVerYear
 *   ADAS_Meta_ProtVer_Major_ST3 of type c02_0_3_1_nSNA
 *   ADAS_Meta_ProtVer_Minor_ST3 of type c04_0_15_1_SNA_na
 *   ADAS_Meta_ProtVer_MinorSub_ST3 of type c03_0_to_7_1_no_SNA
 *   ADAS_Meta_RegionCode_ST3 of type c15_ADAS_RegionCode
 *   ADAS_Meta_SpdUnits_ST3 of type c01_UnitVehSpd
 * REC_ADAS_Meta_ST3_b2mk60164reg2lw3ivnikdnou: Record with elements
 *   ADAS_Meta_CountryCode_ST3 of type c10_ADAS_CountryCode
 *   ADAS_Meta_RegionCode_ST3 of type c15_ADAS_RegionCode
 * REC_ADAS_Posn_ST3: Record with elements
 *   ADAS_Posn_Age_ST3 of type c09_ms_0_510_5
 *   ADAS_Posn_CurLane_ST3 of type c03_ADAS_Posn_CurLane
 *   ADAS_Posn_CycCnt_ST3 of type c02_0_3_1_nSNA
 *   ADAS_Posn_Idx_ST3 of type c03_ADAS_Posn_Idx
 *   ADAS_Posn_MsgTyp_ST3 of type c03_MsgTyp_1_to_7
 *   ADAS_Posn_Offset_ST3 of type c13_m_0_8190_1
 *   ADAS_Posn_PathIdx_ST3 of type c06_Idx_0_to_63_1
 *   ADAS_Posn_PosConfdc_ST3 of type c03_0_6_1
 *   ADAS_Posn_PosProbb_ST3 of type c05_perc_0_31_3k333
 *   ADAS_Posn_RelHead_ST3 of type c08_deg_0_358k5_1k417
 *   ADAS_Posn_Spd_ST3 of type c09_m_p_s_m12k8_89k2_0k2
 * REC_ADAS_Posn_ST3_7tu0j7cag3wthixhamscgyjyr: Record with elements
 *   ADAS_Posn_Age_ST3 of type c09_ms_0_510_5
 *   ADAS_Posn_Idx_ST3 of type c03_ADAS_Posn_Idx
 *   ADAS_Posn_Offset_ST3 of type c13_m_0_8190_1
 *   ADAS_Posn_PathIdx_ST3 of type c06_Idx_0_to_63_1
 *   ADAS_Posn_Spd_ST3 of type c09_m_p_s_m12k8_89k2_0k2
 * REC_ADAS_Profile_Short_CurvLn_ST3: Record with elements
 *   ADAS_ProfShort_AccurClass_CL_ST3 of type c02_0_3_1_nSNA
 *   ADAS_ProfShort_CtrlPoint_CL_ST3 of type c01_FalseTrue
 *   ADAS_ProfShort_CycCnt_CL_ST3 of type c02_0_3_1_nSNA
 *   ADAS_ProfShort_Dist1_CL_ST3 of type c10_m_0_510_1
 *   ADAS_ProfShort_MsgTyp_CL_ST3 of type c03_MsgTyp_1_to_7
 *   ADAS_ProfShort_Offset_CL_ST3 of type c13_m_0_8190_1
 *   ADAS_ProfShort_PathIdx_CL_ST3 of type c06_Idx_0_to_63_1
 *   ADAS_ProfShort_ReTr_CL_ST3 of type c01_FalseTrue
 *   ADAS_ProfShort_Updt_CL_ST3 of type c01_FalseTrue
 *   ADAS_ProfShort_Value0_CL_ST3 of type c10_to_1022_1
 *   ADAS_ProfShort_Value1_CL_ST3 of type c10_to_1022_1
 * REC_ADAS_Profile_Short_CurvLn_ST3_490g5rtcnid4ivawivkcosvcg: Record with elements
 *   ADAS_ProfShort_Dist1_CL_ST3 of type c10_m_0_510_1
 *   ADAS_ProfShort_Offset_CL_ST3 of type c13_m_0_8190_1
 *   ADAS_ProfShort_PathIdx_CL_ST3 of type c06_Idx_0_to_63_1
 *   ADAS_ProfShort_ReTr_CL_ST3 of type c01_FalseTrue
 *   ADAS_ProfShort_Value0_CL_ST3 of type c10_to_1022_1
 *   ADAS_ProfShort_Value1_CL_ST3 of type c10_to_1022_1
 * REC_Bckl_Sw_Fx_Stat_Pr5_ST3: Record with elements
 *   Rsrv1_Bckl_Sw_Fx_Stat_ST3 of type Rsrv04
 *   Bckl_Sw_D_Stat_ST3 of type c02_Bckl_Sw_Stat
 *   Bckl_Sw_FP_Stat_ST3 of type c02_Bckl_Sw_Stat
 *   CRC_Bckl_Sw_Fx_Stat_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_Bckl_Sw_Fx_Stat_Pr5_ST3 of type c08_0_255_1_SNA_na
 * REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx: Record with elements
 *   Bckl_Sw_D_Stat_ST3 of type c02_Bckl_Sw_Stat
 *   Bckl_Sw_FP_Stat_ST3 of type c02_Bckl_Sw_Stat
 * REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt: Record with elements
 *   Rsrv1_Bckl_Sw_Fx_Stat_ST3 of type Rsrv04
 *   Bckl_Sw_D_Stat_ST3 of type c02_Bckl_Sw_Stat
 *   Bckl_Sw_FP_Stat_ST3 of type c02_Bckl_Sw_Stat
 *   CRC_Bckl_Sw_Fx_Stat_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_Bckl_Sw_Fx_Stat_Pr5_ST3 of type c08_0_255_1_SNA_na
 * REC_CLkS_DrRltch_Stat_Pr5_ST3: Record with elements
 *   CRC_CLkS_DrRltch_Stat_Pr5_ST3 of type c16_CRC_woSNA
 *   DrRLtch_FL_Stat_ST3 of type c02_Dr_Stat
 *   DrRLtch_FR_Stat_ST3 of type c02_Dr_Stat
 *   DrRLtch_RL_Stat_ST3 of type c02_Dr_Stat
 *   DrRLtch_RR_Stat_ST3 of type c02_Dr_Stat
 *   SQC_CLkS_DrRltch_Stat_Pr5_ST3 of type c08_0_255_1_SNA_na
 * REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx: Record with elements
 *   DrRLtch_FL_Stat_ST3 of type c02_Dr_Stat
 *   DrRLtch_FR_Stat_ST3 of type c02_Dr_Stat
 * REC_DI_Odo_Pr5_ST3: Record with elements
 *   CRC_DI_Odo_Pr5_ST3 of type c16_CRC_woSNA
 *   Odo_ST3 of type c24_km_0_999999k9_0k1_Invld_SNA
 *   SQC_DI_Odo_Pr5_ST3 of type c08_0_255_1_SNA_na
 * REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   Odo_ST3 of type c24_km_0_999999k9_0k1_Invld_SNA
 * REC_DPC_Md_Rq_ESP_Pr5_ST3: Record with elements
 *   DPC_GlobalMd_Rq_ST3 of type c04_DPC_GlobalMd_Rq
 *   DPC_GlobalMd_TrgRq_ST3 of type c02_Ndef_False_True_ST3
 *   DPC_Md_eSPC_Carv_Rq_ST3 of type c02_NDef_On_Off
 *   DPC_Md_ABC_Preview_Rq_ST3 of type c02_NDef_On_Off
 *   DPC_Md_ESP_Rq_ST3 of type c04_DPC_Md_ESP_Rq_ST3
 *   DPC_Md_ExhstFlap_Rq_ST3 of type c03_DPC_Md_ExhaustFlap
 *   DPC_Md_Ht_Rq_ST3 of type c02_NDef_ECO_Comfort
 *   DPC_Md_PT_Rq_ST3 of type c05_DPC_Md_PT_HU
 *   DPC_Md_PwrFreeD_Plus_Rq_ST3 of type c02_NDef_On_Off
 *   DPC_Md_SSA_Rq_ST3 of type c02_DPC_Md_SSA
 *   DPC_Md_St_Rq_ST3 of type c03_DPC_Md_St
 *   DPC_Md_Susp_Rq_ST3 of type c05_DPC_Md_Susp_V2
 *   DPC_Md_SuspLvl_Rq_ST3 of type c03_m2_p3_1_Init
 *   DPC_Md_Tx_Rq_ST3 of type c04_NDef_Man_Auto
 *   Rsrv1_DPC_Md_Rq_ESP_Pr5_ST3 of type Rsrv05
 *   CRC_DPC_Md_Rq_ESP_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_DPC_Md_Rq_ESP_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   Rsrv2_DPC_Md_Rq_ESP_Pr5_ST3 of type Rsrv24
 * REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86: Record with elements
 *   DPC_Md_PT_Rq_ST3 of type c05_DPC_Md_PT_HU
 * REC_Develop8_Rq_RBTM_FL_ST3: Record with elements
 *   Develop_Rq_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_Develop8_Rq_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv: Record with elements
 *   Develop_Rq_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_Develop8_Rs_RBTM_FL_ST3: Record with elements
 *   Develop_Rs_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_Develop8_Rs_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv: Record with elements
 *   Develop_Rs_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_ELC_Lvr_Stat_Pr5_ST3: Record with elements
 *   CRC_ELC_Lvr_Stat_Pr5_ST3 of type c16_CRC_woSNA
 *   ELC_TurnIndLvr_Stat_ST3 of type c02_TurnIndLvr_Stat
 *   Rsrv1_ELC_Lvr_Stat_Pr5_ST3 of type Rsrv04
 *   SQC_ELC_Lvr_Stat_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   ELC_HiBmLvr_Stat_ST3 of type c02_HiBmLvr_Stat
 * REC_ELC_Lvr_Stat_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   ELC_TurnIndLvr_Stat_ST3 of type c02_TurnIndLvr_Stat
 * REC_EVC_CfgList_01_08_Pr5_ST3: Record with elements
 *   CRC_EVC_CfgList_01_08_Pr5_ST3 of type c16_CRC_woSNA
 *   EVC_CfgList_01_08_Stat_ST3 of type c02_EVC_Stat
 *   EVC_List01_BodyStyle_ST3 of type c06_EVC_BodyStyle_ST3
 *   EVC_List02_VehLine_ST3 of type c06_EVC_VehLine_ST3
 *   EVC_List03_StStyle_ST3 of type c02_StStyle
 *   EVC_List04_YrOfModf_2_ST3 of type c04_EVC_YrOfModf_2_ST3
 *   EVC_List05_YrOfModf_1_ST3 of type c04_EVC_YrOfModf_1_ST3
 *   EVC_List06_Country_ST3 of type c08_EVC_Country_extended
 *   EVC_List07_TxStyle_ST3 of type c04_EVC_TxStyle_ST3
 *   EVC_List08_HL_Style_ST3 of type c04_EVC_HL_Style_ST3
 *   SQC_EVC_CfgList_01_08_Pr5_ST3 of type c08_0_255_1_SNA_na
 * REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby: Record with elements
 *   EVC_List03_StStyle_ST3 of type c02_StStyle
 * REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw: Record with elements
 *   EVC_CfgList_01_08_Stat_ST3 of type c02_EVC_Stat
 *   EVC_List03_StStyle_ST3 of type c02_StStyle
 * REC_Ign_Stat_Pr5_ST3: Record with elements
 *   ISw_Stat_ST3 of type c03_ISw_Stat
 *   Veh_Op_Mode_ST3 of type c04_VehOpMode
 *   CRC_Ign_Stat_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_Ign_Stat_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   KG_StartSw_Psd_ST3 of type DC_BOOL
 * REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0: Record with elements
 *   ISw_Stat_ST3 of type c03_ISw_Stat
 * REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96: Record with elements
 *   ISw_Stat_ST3 of type c03_ISw_Stat
 *   Veh_Op_Mode_ST3 of type c04_VehOpMode
 *   CRC_Ign_Stat_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_Ign_Stat_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   KG_StartSw_Psd_ST3 of type DC_BOOL
 * REC_Meas_RBTM_FL_ST3: Record with elements
 *   Meas_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv: Record with elements
 *   Meas_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_ORC_Impact2_Pr5_ST3: Record with elements
 *   Impact_Y_ST3 of type DC_BOOL
 *   CRC_ORC_Impact2_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_ORC_Impact2_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   Impact_R1_ST3 of type DC_BOOL
 *   Impact_R2_ST3 of type DC_BOOL
 *   Impact_minor_ST3 of type DC_BOOL
 *   Impact_P_ST3 of type DC_BOOL
 *   VehPosn_ST3 of type c03_VehPos_ST3
 * REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   Impact_Y_ST3 of type DC_BOOL
 * REC_ORC_Impact3_Pr5_ST3: Record with elements
 *   Impact_F1_ST3 of type DC_BOOL
 *   Impact_F3_ST3 of type DC_BOOL
 *   Impact_RO_type1_ST3 of type DC_BOOL
 *   Impact_RO_type2_ST3 of type DC_BOOL
 *   CRC_ORC_Impact3_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_ORC_Impact3_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   Impact_F2_ST3 of type DC_BOOL
 *   Impact_S1_ST3 of type DC_BOOL
 *   Impact_S2_ST3 of type DC_BOOL
 *   Impact_X_ST3 of type DC_BOOL
 * REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19: Record with elements
 *   Impact_F1_ST3 of type DC_BOOL
 *   Impact_F3_ST3 of type DC_BOOL
 *   Impact_RO_type1_ST3 of type DC_BOOL
 *   Impact_RO_type2_ST3 of type DC_BOOL
 *   CRC_ORC_Impact3_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_ORC_Impact3_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   Impact_F2_ST3 of type DC_BOOL
 *   Impact_S1_ST3 of type DC_BOOL
 *   Impact_S2_ST3 of type DC_BOOL
 *   Impact_X_ST3 of type DC_BOOL
 * REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58: Record with elements
 *   Impact_X_ST3 of type DC_BOOL
 * REC_PT4_PTCoor4_Pr5_ST3: Record with elements
 *   CRC_PT4_PTCoor4_Pr5_ST3 of type c16_CRC_woSNA
 *   PT4_PTCoor_PT_Rdy_ST3 of type c02_PT_Rdy_V2
 *   SQC_PT4_PTCoor4_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   PT4_PTCoor_EngStartPN14_Stat_ST3 of type c03_EngStartPN14_Stat
 *   PT4_PTCoor_SSA_EngSp_ST3 of type c02_Ndef_False_True_ST3
 *   Rsrv1_PT4_PTCoor_PT_Rdy_Pr5_ST3 of type Rsrv01
 * REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby: Record with elements
 *   PT4_PTCoor_EngStartPN14_Stat_ST3 of type c03_EngStartPN14_Stat
 * REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   PT4_PTCoor_PT_Rdy_ST3 of type c02_PT_Rdy_V2
 * REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw: Record with elements
 *   PT4_PTCoor_PT_Rdy_ST3 of type c02_PT_Rdy_V2
 *   PT4_PTCoor_EngStartPN14_Stat_ST3 of type c03_EngStartPN14_Stat
 * REC_PT4_PTCoor9_Pr5_ST3: Record with elements
 *   CRC_PT4_PTCoor9_Pr5_ST3 of type c16_CRC_woSNA
 *   PT4_PTCoor_AccelPdlPosn_D_Raw_ST3 of type c08_perc_0_100_0k4
 *   PT4_PTCoor_KickDnSw_Psd_ST3 of type c02_Ndef_False_True_ST3
 *   PT4_PTCoor_SSA_StopWarn_ST3 of type c02_Ndef_False_True_ST3
 *   SQC_PT4_PTCoor9_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   PT4_PTCoor_EngRPM_ST3 of type c14_rpm_0_16382_1
 *   PT4_PTCoor_ClutchPdlPosn_CPC_ST3 of type c08_perc_0_100_0k5
 *   PT4_PTCoor_EcoRcmnd_VehHighSpd_ST3 of type c08_km_p_h_30_250_1_NoRcmnd
 *   PT4_PTCoor_EcoRcmnd_VehSpd_ST3 of type c08_km_p_h_30_250_1_NoRcmnd
 *   PT4_PTCoor_EmgPath_Enbl_ST3 of type c02_Ndef_False_True_ST3
 *   PT4_PTCoor_EmgPath_Volt_ST3 of type c08_V_0_25k4_0k1
 *   PT4_PTCoor_LHOM_PkLk_ST3 of type c02_Ndef_False_True_ST3
 *   Rsrv4_PT4_PTCoor9_Pr5_ST3 of type Rsrv27
 *   PT4_PTCoor_Accel_Md_ST3 of type c03_Accel_Md_ST3
 *   PT4_PTCoor_TxBurnOut_Stat_ST3 of type c02_TxBurnOut_Stat
 *   PT4_PTCoor_VehFixMaxSpd_ST3 of type c09_km_p_h_0_500_1
 *   PT4_PTCoor_ShftTcase_Enbl_ST3 of type c02_NDef_Off_On_ST3
 *   PT4_PTCoor_DAS_Health_Stat_ST3 of type c10_PT4_PTCoor_DAS_Hlth_Stat
 *   PT4_PTCoor_TrsmCtrl_OutRPM_ST3 of type c12_rpm_0_16376_4
 *   PT4_PTCoor_VEPM_DCDC_BuckSuprt_Stat_ST3 of type c03_DCDCBuckSuprtStat_ST3
 * REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u: Record with elements
 *   PT4_PTCoor_Accel_Md_ST3 of type c03_Accel_Md_ST3
 * REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3: Record with elements
 *   CRC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 of type c16_CRC_woSNA
 *   PT4_PTCoor_DrvPosn_Stat_ST3 of type c04_DrvPosn_ST3
 *   PT4_PTCoor_DrvPosn_Target_ST3 of type c04_DrvPosn_ST3
 *   PT4_PTCoor_Gr_ST3 of type c04_Gr
 *   SQC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   PT4_PTCoor_DrvPosn_Disp_Rq_ST3 of type c08_TxDrvPosn
 *   PT4_PTCoor_Gr_Target_ST3 of type c04_Gr_Target
 *   PT4_PTCoor_DrvPosn_N_Actv_ST3 of type c02_Inact_Act_ST3
 *   PT4_PTCoor_ShW_MnTrctAxl_D_Allowed_ST3 of type c02_Ndef_False_True_ST3
 *   PT4_PTCoor_ShW_MnTrctAxl_N_Allowed_ST3 of type c02_Ndef_False_True_ST3
 *   PT4_PTCoor_ShW_MnTrctAxl_P_Allowed_ST3 of type c02_Ndef_False_True_ST3
 *   PT4_PTCoor_ShW_MnTrctAxl_R_Allowed_ST3 of type c02_Ndef_False_True_ST3
 *   PT4_PTCoor_SSA_Standby_Stat_ST3 of type c02_SSA_Standby_Stat
 *   PT4_PTCoor_ShW_MnTrctAxl_P_Allow_Drv_ST3 of type c02_Ndef_False_True_ST3
 *   Rsrv1_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 of type Rsrv02
 * REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   PT4_PTCoor_DrvPosn_Stat_ST3 of type c04_DrvPosn_ST3
 * REC_PresfAct_Adj_Pr5_ST3: Record with elements
 *   PresfAct_Adj_Rq_ST3 of type c13_PresfAct_Adj_Rq
 *   Rsrv6_Presf_Adj_ST3 of type Rsrv08
 *   Presf_Lvl_ST3 of type c04_Presf_Lvl_V2
 *   Presf_Snd_Rq_ST3 of type c02_Presf_Snd
 *   PresfAccelReset_NotExcd_ST3 of type c02_Ndef_False_True_ST3
 *   Presf_Enbl_ST3 of type c02_false_true_sna
 *   Presf_Fric_Fctr_Lo_ST3 of type c02_false_true_sna
 *   PresfAct_TensSupp_Rq_ST3 of type c03_No_Lt_Rt_Both
 *   CRC_PresfAct_Adj_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_PresfAct_Adj_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   Presf_FricCoeff_Estim_ST3 of type c04_Presf_Frct_ST3
 * REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j: Record with elements
 *   PresfAct_Adj_Rq_ST3 of type c13_PresfAct_Adj_Rq
 *   Rsrv6_Presf_Adj_ST3 of type Rsrv08
 *   Presf_Lvl_ST3 of type c04_Presf_Lvl_V2
 *   Presf_Snd_Rq_ST3 of type c02_Presf_Snd
 *   PresfAccelReset_NotExcd_ST3 of type c02_Ndef_False_True_ST3
 *   Presf_Enbl_ST3 of type c02_false_true_sna
 *   Presf_Fric_Fctr_Lo_ST3 of type c02_false_true_sna
 *   PresfAct_TensSupp_Rq_ST3 of type c03_No_Lt_Rt_Both
 *   CRC_PresfAct_Adj_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_PresfAct_Adj_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   Presf_FricCoeff_Estim_ST3 of type c04_Presf_Frct_ST3
 * REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr: Record with elements
 *   Presf_Lvl_ST3 of type c04_Presf_Lvl_V2
 *   PresfAccelReset_NotExcd_ST3 of type c02_Ndef_False_True_ST3
 * REC_ROE_XX_ST3: Record with elements
 *   ROE_0 of type c08_ROE_0
 *   ROE_1 of type c08_UInt_SNA_na
 *   ROE_2 of type c08_UInt_SNA_na
 *   ROE_3 of type c08_UInt_SNA_na
 *   ROE_4 of type c08_UInt_SNA_na
 *   ROE_5 of type c08_UInt_SNA_na
 *   ROE_6 of type c08_UInt_SNA_na
 *   ROE_7 of type c08_UInt_SNA_na
 * REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv: Record with elements
 *   ROE_0 of type c08_ROE_0
 *   ROE_1 of type c08_UInt_SNA_na
 *   ROE_2 of type c08_UInt_SNA_na
 *   ROE_3 of type c08_UInt_SNA_na
 *   ROE_4 of type c08_UInt_SNA_na
 *   ROE_5 of type c08_UInt_SNA_na
 *   ROE_6 of type c08_UInt_SNA_na
 *   ROE_7 of type c08_UInt_SNA_na
 * REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4: Record with elements
 *   VehSpd8_ST3 of type c08_km_p_h_0_254_1
 *   CRC_VehSpd8_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_VehSpd8_Pr5_ST3 of type c08_0_255_1_SNA_na
 *
 *********************************************************************************************************************/


#define Ct_MBBL_ResetPreconditionChecker_START_SEC_CODE
#include "Ct_MBBL_ResetPreconditionChecker_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ct_MBBL_ResetPreconditionChecker_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_ResetPreconditionChecker_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_ResetPreconditionChecker_CODE) Ct_MBBL_ResetPreconditionChecker_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ct_MBBL_ResetPreconditionChecker_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Pp_MBBL_BootloaderPreconditions_CheckConditions
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CheckConditions> of PortPrototype <Pp_MBBL_BootloaderPreconditions>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_VehSpd8_Pr5_ST3_VehSpd8_Pr5_ST3(REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Pp_MBBL_BootloaderPreconditions_CheckConditions(boolean *resetAllowed, Dcm_NegativeResponseCodeType *errorCode)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_MBBL_BootloaderPreconditions_CheckConditions_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_ResetPreconditionChecker_CODE) Pp_MBBL_BootloaderPreconditions_CheckConditions(P2VAR(boolean, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) resetAllowed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) errorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_MBBL_BootloaderPreconditions_CheckConditions
 *********************************************************************************************************************/
  /* TO BE IMPLEMENTED */
  
  // REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96 locIgnStat;
  // REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4 locVehSpd;
   boolean locResetAllowed = TRUE;

  // if ((Rte_Read_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(&locIgnStat) == RTE_E_OK) && (locResetAllowed == TRUE))
  // {
  //   if (locIgnStat.ISw_Stat_ST3 <= I_C03_ISW_STAT_IGN_OFF)
  //   {
  //     locResetAllowed = FALSE;
  //     *errorCode = DCM_E_ENGINEISRUNNING;
  //   }
  // }

  // if ((Rte_Read_R_VehSpd8_Pr5_ST3_VehSpd8_Pr5_ST3(&locVehSpd) == RTE_E_OK) && (locResetAllowed == TRUE))
  // {
  //   if (locVehSpd.VehSpd8_ST3)
  //   {
  //     locResetAllowed = FALSE;
  //     *errorCode = DCM_E_VEHICLESPEEDTOOHIGH;
  //   }
  // }
   *resetAllowed = locResetAllowed;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Pp_MBBL_ResetPreconditions_CheckConditions
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CheckConditions> of PortPrototype <Pp_MBBL_ResetPreconditions>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_VehSpd8_Pr5_ST3_VehSpd8_Pr5_ST3(REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Pp_MBBL_ResetPreconditions_CheckConditions(boolean *resetAllowed, Dcm_NegativeResponseCodeType *errorCode)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_MBBL_ResetPreconditions_CheckConditions_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ct_MBBL_ResetPreconditionChecker_CODE) Pp_MBBL_ResetPreconditions_CheckConditions(P2VAR(boolean, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) resetAllowed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_CT_MBBL_RESETPRECONDITIONCHECKER_APPL_VAR) errorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_MBBL_ResetPreconditions_CheckConditions
 *********************************************************************************************************************/
  
  boolean locResetAllowed = TRUE;

  *resetAllowed = locResetAllowed;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ct_MBBL_ResetPreconditionChecker_STOP_SEC_CODE
#include "Ct_MBBL_ResetPreconditionChecker_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
