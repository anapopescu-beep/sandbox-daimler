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
 *             File:  BeltTensionerFunction.c
 *           Config:  S:\Tools\Vector_configuration\Workspace\Daimler MMA/S:/Tools/Vector_configuration/Workspace/Daimler MMA/StartApplication.dpa
 *        SW-C Type:  BeltTensionerFunction
 *  Generation Time:  2021-10-26 17:23:54
 *
 *        Generator:  MICROSAR RTE Generator Version 4.24.0
 *                    RTE Core Version 1.24.0
 *          License:  PAI981
 *
 *      Description:  C-Code implementation template for SW-C <BeltTensionerFunction>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
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
 * Rsrv04
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
 * c01_FalseTrue
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
 * c02_Inactv_Silent_Actv_ST3
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
 * c02_false_true_sna
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
 * c04_DrvPosn_ST3
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
 * c06_Idx_0_to_63_1
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
 * c08_ROE_0
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
 * c08_km_p_h_0_254_1
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * c24_km_0_999999k9_0k1_Invld_SNA
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 *
 * Port Prototypes:
 * ================
 * P_PS_Curve_FL_Stat_ST3
 *   PreSafe Curve mode state front left
 *
 * P_RBTM_FL_Disp_Rq_ST3
 *   Presafe display request front left
 *
 * P_RBTM_FL_Tgl_ST3
 *   Presafe Togglebit
 *
 * P_RevBltTns_FL_SafeCyc_Actv_ST3
 *   Reversible belt tensioner front left safety tensioning cycle active
 *
 * R_ADAS_Meta_ST3
 *   ADAS meta data (degraded)
 *
 * R_ADAS_Posn_ST3
 *   ADAS Position (degraded)
 *
 * R_ADAS_Prediction_MsgTyp_ST3
 *   ADAS Prediction: Message Type
 *
 * R_ADAS_ProfShort_ProfTyp_ST3
 *   Profile Short Message: Profile Type
 *
 * R_ADAS_Profile_Short_CurvLn_ST3
 *   ADAS short profile Curvature Linear (degraded)
 *
 * R_Bckl_Sw_Fx_Stat_Pr5_ST3
 *   Bckl Sw Fx state ST3 (degraded)
 *
 * R_BeltHdOvr_XX_Stat_ST3
 *   Belt hand over state
 *
 * R_ELC_Lvr_Stat_Pr5_ST3
 *   Exterior light lever state (degraded)
 *
 * R_EVC_CfgList_01_08_Pr5_ST3
 *   EVC Cfg List 01 08 Pr 5 ST3 (degraded)
 *
 * R_Ign_Stat_Pr5_ST3
 *   Ignition state (degraded)
 *
 * R_Navi_RouteGuidance_Stat_ST3
 *   Navigation route guidance state
 *
 * R_ORC_Impact3_Pr5_ST3
 *   ORC Impact 3 ST3 (degraded)
 *
 * R_PS_Curve_FL_Rq_HU_ST3
 *   PreSafe Curve mode request from headunit front left
 *
 * R_PresfAct_Adj_Pr5_ST3
 *   Presf Actuator adjustment ST3 (degraded)
 *
 * R_RevBltTns_FR_SafeCyc_Actv_ST3
 *   Reversible belt tensioner front right safety tensioning cycle active
 *
 *
 * Data Element Prototypes:
 * ========================
 * PS_Curve_FL_Stat_ST3 of Port Interface IF_PS_Curve_FL_Stat_ST3
 *   SHORT: PreSafe Curve mode state front left
 *
 * RBTM_FL_Disp_Rq_ST3 of Port Interface IF_RBTM_FL_Disp_Rq_ST3
 *   SHORT: Presafe display request front left
 *      LONG: Presafe display request front left
 *
 * RBTM_FL_Tgl_ST3 of Port Interface IF_RBTM_FL_Tgl_ST3
 *   SHORT: Presafe Togglebit
 *      LONG: Presafe Togglebit
 *
 * RevBltTns_FL_SafeCyc_Actv_ST3 of Port Interface IF_RevBltTns_FL_SafeCyc_Actv_ST3
 *   SHORT: Reversible belt tensioner front left safety tensioning cycle active
 *      LONG: Reversible belt tensioner front left safety tensioning cycle active
 *
 * ADAS_Meta_ST3 of Port Interface IG_ADAS_Meta_ST3_5t037gwmf9dl2hvml0jpnv9dy
 *   SHORT: ADAS meta data
 *      LONG: ADAS meta data (degraded)
 *
 * ADAS_Posn_ST3 of Port Interface IG_ADAS_Posn_ST3_7s6pzau51nozrnxlccvr1dqvq
 *   SHORT: ADAS Position
 *      LONG: ADAS Position (degraded)
 *
 * ADAS_Prediction_MsgTyp_ST3 of Port Interface IF_ADAS_Prediction_MsgTyp_ST3
 *   SHORT: ADAS Prediction: Message Type
 *      LONG: ADAS Prediction: Message Type
 *
 * ADAS_ProfShort_ProfTyp_ST3 of Port Interface IF_ADAS_ProfShort_ProfTyp_ST3
 *   SHORT: Profile Short Message: Profile Type
 *      LONG: Profile Short Message: Profile Type
 *
 * ADAS_Profile_Short_CurvLn_ST3 of Port Interface IG_ADAS_Profile_Short_CurvLn_ST3_81w1wno7bbxberhwp2jcfr8tz
 *   SHORT: ADAS short profile Curvature Linear
 *      LONG: ADAS short profile Curvature Linear (degraded)
 *
 * Bckl_Sw_Fx_Stat_Pr5_ST3 of Port Interface IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact
 *   SHORT: Bckl Sw Fx state ST3
 *      LONG: Bckl Sw Fx state ST3 (degraded)
 *
 * BeltHdOvr_XX_Stat_ST3 of Port Interface IF_BeltHdOvr_XX_Stat_ST3
 *   SHORT: Belt hand over state
 *      LONG: Belt hand over state
 *
 * ELC_Lvr_Stat_Pr5_ST3 of Port Interface IG_ELC_Lvr_Stat_Pr5_ST3_7k1u3p95ebi3423irpcsvtgpy
 *   SHORT: Exterior light lever state
 *      LONG: Exterior light lever state (degraded)
 *
 * EVC_CfgList_01_08_Pr5_ST3 of Port Interface IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2
 *   SHORT: EVC Cfg List 01 08 Pr 5 ST3
 *      LONG: EVC Cfg List 01 08 Pr 5 ST3 (degraded)
 *
 * Ign_Stat_Pr5_ST3 of Port Interface IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b
 *   SHORT: Ignition state
 *      LONG: Ignition state (degraded)
 *
 * Navi_RouteGuidance_Stat_ST3 of Port Interface IF_Navi_RouteGuidance_Stat_ST3
 *   SHORT: Navigation route guidance state
 *      LONG: Navigation route guidance state
 *
 * ORC_Impact3_Pr5_ST3 of Port Interface IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv
 *   SHORT: ORC Impact 3 ST3
 *      LONG: ORC Impact 3 ST3 (degraded)
 *
 * PS_Curve_FL_Rq_HU_ST3 of Port Interface IF_PS_Curve_FL_Rq_HU_ST3
 *   SHORT: PreSafe Curve mode request from headunit front left
 *
 * PresfAct_Adj_Pr5_ST3 of Port Interface IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2
 *   SHORT: Presf Actuator adjustment ST3
 *      LONG: Presf Actuator adjustment ST3 (degraded)
 *
 * RevBltTns_FR_SafeCyc_Actv_ST3 of Port Interface IF_RevBltTns_FR_SafeCyc_Actv_ST3
 *   SHORT: Reversible belt tensioner front right safety tensioning cycle active
 *      LONG: Reversible belt tensioner front right safety tensioning cycle active
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

#include "Rte_BeltTensionerFunction.h"


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
 * Rsrv04: Integer in interval [0...15]
 * Rsrv08: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * c03_ADAS_Posn_Idx: Integer in interval [0...3]
 * c08_0_255_1_SNA_na: Integer in interval [0...255]
 * c08_UInt_SNA_na: Integer in interval [0...255]
 * c16_CRC_woSNA: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * c01_FalseTrue: Enumeration of integer in interval [0...1] with enumerators
 *   I_C01_FALSETRUE_FALSE (0U)
 *   I_C01_FALSETRUE_TRUE (1U)
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
 * c02_Dr_Stat: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_DR_STAT_CLS (1U)
 *   I_C02_DR_STAT_OPN (2U)
 *   I_C02_DR_STAT_SNA (3U)
 * c02_EVC_Stat: Enumeration of integer in interval [1...3] with enumerators
 *   I_C02_EVC_STAT_PROG (1U)
 *   I_C02_EVC_STAT_REQ (2U)
 *   I_C02_EVC_STAT_SNA (3U)
 * c02_Inactv_Silent_Actv_ST3: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_INACTV_SILENT_ACTV_ST3_INACTIVE (0U)
 *   I_C02_INACTV_SILENT_ACTV_ST3_SILENT (1U)
 *   I_C02_INACTV_SILENT_ACTV_ST3_ACTIVE (2U)
 *   I_C02_INACTV_SILENT_ACTV_ST3_SNA (3U)
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
 * c02_false_true_sna: Enumeration of integer in interval [0...3] with enumerators
 *   I_C02_FALSE_TRUE_SNA_FALSE (0U)
 *   I_C02_FALSE_TRUE_SNA_TRUE (1U)
 *   I_C02_FALSE_TRUE_SNA_SNA (3U)
 * c03_Accel_Md_ST3: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ACCEL_MD_ST3_NORMAL_ACCLRN_MODE (0U)
 *   I_C03_ACCEL_MD_ST3_OPTMD_FULL_LOAD_WO_OVR_TRQ (1U)
 *   I_C03_ACCEL_MD_ST3_OPTMD_FULL_LOAD_WITH_OVR_TRQ (2U)
 *   I_C03_ACCEL_MD_ST3_RACESTRT_PHASE_WO_OVR_TRQ (3U)
 *   I_C03_ACCEL_MD_ST3_RACESTRT_PHASE_WITH_OVR_TRQ (4U)
 *   I_C03_ACCEL_MD_ST3_RACESTRT_ACCLN_WO_OVR_TRQ (5U)
 *   I_C03_ACCEL_MD_ST3_RACESTRT_ACCLN_WITH_OVR_TRQ (6U)
 *   I_C03_ACCEL_MD_ST3_SNA (7U)
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
 * c04_DrvPosn_ST3: Enumeration of integer in interval [1...15] with enumerators
 *   I_C04_DRVPOSN_ST3_D (1U)
 *   I_C04_DRVPOSN_ST3_N (2U)
 *   I_C04_DRVPOSN_ST3_R (3U)
 *   I_C04_DRVPOSN_ST3_P (4U)
 *   I_C04_DRVPOSN_ST3_SNA (15U)
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
 * c06_Idx_0_to_63_1: Enumeration of integer in interval [0...63] with enumerators
 *   I_C06_IDX_0_TO_63_1_UNKNOWN (0U)
 *   I_C06_IDX_0_TO_63_1_NOT_DIGIT (1U)
 *   I_C06_IDX_0_TO_63_1_NOT_ROAD (2U)
 *   I_C06_IDX_0_TO_63_1_NOT_CALIB (3U)
 *   I_C06_IDX_0_TO_63_1_CURR_SEG (4U)
 *   I_C06_IDX_0_TO_63_1_STUB_ONLY (5U)
 *   I_C06_IDX_0_TO_63_1_THIS_PATH (6U)
 *   I_C06_IDX_0_TO_63_1_RES7 (7U)
 * c08_ROE_0: Enumeration of integer in interval [0...6] with enumerators
 *   I_C08_ROE_0_IDLE (0U)
 *   I_C08_ROE_0_DTC_STATUS_CHANGE (1U)
 *   I_C08_ROE_0_OBSOLESCENCE_DATA (2U)
 *   I_C08_ROE_0_CONSUMABLE_DATA (3U)
 *   I_C08_ROE_0_AVAILABILITY_DATA (4U)
 *   I_C08_ROE_0_DIAG_SESSION_CHANGE (5U)
 *   I_C08_ROE_0_SECURITY_EVENT_NOTIFICATION (6U)
 * c08_km_p_h_0_254_1: Enumeration of integer in interval [0...255] with enumerators
 *   I_C08_KM_P_H_0_254_1_SNA (255U)
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
 * c15_ADAS_RegionCode: Enumeration of integer in interval [0...32767] with enumerators
 *   I_C15_ADAS_REGIONCODE_UNKWN (0U)
 *   I_C15_ADAS_REGIONCODE_SNA (32767U)
 * c24_km_0_999999k9_0k1_Invld_SNA: Enumeration of integer in interval [0...16777215] with enumerators
 *   I_C24_KM_0_999999K9_0K1_INVLD_SNA_INVLD (16777214U)
 *   I_C24_KM_0_999999K9_0K1_INVLD_SNA_SNA (16777215U)
 *
 * Array Types:
 * ============
 * ARR_08_UInt_noSNA_7: Array with 7 element(s) of type c08_UInt_SNA_na
 *
 * Record Types:
 * =============
 * REC_ADAS_Meta_ST3_b2mk60164reg2lw3ivnikdnou: Record with elements
 *   ADAS_Meta_CountryCode_ST3 of type c10_ADAS_CountryCode
 *   ADAS_Meta_RegionCode_ST3 of type c15_ADAS_RegionCode
 * REC_ADAS_Posn_ST3_7tu0j7cag3wthixhamscgyjyr: Record with elements
 *   ADAS_Posn_Age_ST3 of type c09_ms_0_510_5
 *   ADAS_Posn_Idx_ST3 of type c03_ADAS_Posn_Idx
 *   ADAS_Posn_Offset_ST3 of type c13_m_0_8190_1
 *   ADAS_Posn_PathIdx_ST3 of type c06_Idx_0_to_63_1
 *   ADAS_Posn_Spd_ST3 of type c09_m_p_s_m12k8_89k2_0k2
 * REC_ADAS_Profile_Short_CurvLn_ST3_490g5rtcnid4ivawivkcosvcg: Record with elements
 *   ADAS_ProfShort_Dist1_CL_ST3 of type c10_m_0_510_1
 *   ADAS_ProfShort_Offset_CL_ST3 of type c13_m_0_8190_1
 *   ADAS_ProfShort_PathIdx_CL_ST3 of type c06_Idx_0_to_63_1
 *   ADAS_ProfShort_ReTr_CL_ST3 of type c01_FalseTrue
 *   ADAS_ProfShort_Value0_CL_ST3 of type c10_to_1022_1
 *   ADAS_ProfShort_Value1_CL_ST3 of type c10_to_1022_1
 * REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx: Record with elements
 *   Bckl_Sw_D_Stat_ST3 of type c02_Bckl_Sw_Stat
 *   Bckl_Sw_FP_Stat_ST3 of type c02_Bckl_Sw_Stat
 * REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt: Record with elements
 *   Rsrv1_Bckl_Sw_Fx_Stat_ST3 of type Rsrv04
 *   Bckl_Sw_D_Stat_ST3 of type c02_Bckl_Sw_Stat
 *   Bckl_Sw_FP_Stat_ST3 of type c02_Bckl_Sw_Stat
 *   CRC_Bckl_Sw_Fx_Stat_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_Bckl_Sw_Fx_Stat_Pr5_ST3 of type c08_0_255_1_SNA_na
 * REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx: Record with elements
 *   DrRLtch_FL_Stat_ST3 of type c02_Dr_Stat
 *   DrRLtch_FR_Stat_ST3 of type c02_Dr_Stat
 * REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   Odo_ST3 of type c24_km_0_999999k9_0k1_Invld_SNA
 * REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86: Record with elements
 *   DPC_Md_PT_Rq_ST3 of type c05_DPC_Md_PT_HU
 * REC_Develop8_Rq_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv: Record with elements
 *   Develop_Rq_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Develop_Rq_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_Develop8_Rs_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv: Record with elements
 *   Develop_Rs_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Develop_Rs_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_ELC_Lvr_Stat_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   ELC_TurnIndLvr_Stat_ST3 of type c02_TurnIndLvr_Stat
 * REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby: Record with elements
 *   EVC_List03_StStyle_ST3 of type c02_StStyle
 * REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw: Record with elements
 *   EVC_CfgList_01_08_Stat_ST3 of type c02_EVC_Stat
 *   EVC_List03_StStyle_ST3 of type c02_StStyle
 * REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0: Record with elements
 *   ISw_Stat_ST3 of type c03_ISw_Stat
 * REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96: Record with elements
 *   ISw_Stat_ST3 of type c03_ISw_Stat
 *   Veh_Op_Mode_ST3 of type c04_VehOpMode
 *   CRC_Ign_Stat_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_Ign_Stat_Pr5_ST3 of type c08_0_255_1_SNA_na
 *   KG_StartSw_Psd_ST3 of type DC_BOOL
 * REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv: Record with elements
 *   Meas_RBTM_FL_01 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_02 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_03 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_04 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_05 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_06 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_07 of type c08_UInt_SNA_na
 *   Meas_RBTM_FL_08 of type c08_UInt_SNA_na
 * REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   Impact_Y_ST3 of type DC_BOOL
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
 * REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby: Record with elements
 *   PT4_PTCoor_EngStartPN14_Stat_ST3 of type c03_EngStartPN14_Stat
 * REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   PT4_PTCoor_PT_Rdy_ST3 of type c02_PT_Rdy_V2
 * REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u: Record with elements
 *   PT4_PTCoor_Accel_Md_ST3 of type c03_Accel_Md_ST3
 * REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   PT4_PTCoor_DrvPosn_Stat_ST3 of type c04_DrvPosn_ST3
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


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96 *Rte_Pim_IgnStatBuffer(void)
 *
 *********************************************************************************************************************/


#define BeltTensionerFunction_START_SEC_CODE
#include "BeltTensionerFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BeltTensionerFunction_E2E
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Ign_Stat_Pr5_ST3> of PortPrototype <R_Ign_Stat_Pr5_ST3>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3(c02_Presf_Disp_Rq data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BeltTensionerFunction_E2E_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BeltTensionerFunction_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BeltTensionerFunction_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BeltTensionerFunction_CODE) BeltTensionerFunction_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BeltTensionerFunction_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: BeltTensionerFunction_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_ADAS_Meta_ST3_ADAS_Meta_ST3(REC_ADAS_Meta_ST3_b2mk60164reg2lw3ivnikdnou *data)
 *   Std_ReturnType Rte_Read_R_ADAS_Posn_ST3_ADAS_Posn_ST3(REC_ADAS_Posn_ST3_7tu0j7cag3wthixhamscgyjyr *data)
 *   Std_ReturnType Rte_Read_R_ADAS_Prediction_MsgTyp_ST3_ADAS_Prediction_MsgTyp_ST3(c03_MsgTyp_1_to_7 *data)
 *   Std_ReturnType Rte_Read_R_ADAS_ProfShort_ProfTyp_ST3_ADAS_ProfShort_ProfTyp_ST3(c05_ADAS_ProfShort_ProfTyp *data)
 *   Std_ReturnType Rte_Read_R_ADAS_Profile_Short_CurvLn_ST3_ADAS_Profile_Short_CurvLn_ST3(REC_ADAS_Profile_Short_CurvLn_ST3_490g5rtcnid4ivawivkcosvcg *data)
 *   Std_ReturnType Rte_Read_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt *data)
 *   Std_ReturnType Rte_Read_R_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3(c02_BeltHdOvr_Stat *data)
 *   Std_ReturnType Rte_Read_R_ELC_Lvr_Stat_Pr5_ST3_ELC_Lvr_Stat_Pr5_ST3(REC_ELC_Lvr_Stat_Pr5_ST3_9t50popkpz30is106xpis1iyh *data)
 *   Std_ReturnType Rte_Read_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw *data)
 *   Std_ReturnType Rte_Read_R_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96 *data)
 *   Std_ReturnType Rte_Read_R_Navi_RouteGuidance_Stat_ST3_Navi_RouteGuidance_Stat_ST3(c02_Inactv_Silent_Actv_ST3 *data)
 *   Std_ReturnType Rte_Read_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19 *data)
 *   Std_ReturnType Rte_Read_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3(c02_Off_Stage1_Stage2 *data)
 *   Std_ReturnType Rte_Read_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j *data)
 *   Std_ReturnType Rte_Read_R_RevBltTns_FR_SafeCyc_Actv_ST3_RevBltTns_FR_SafeCyc_Actv_ST3(c02_Ndef_False_True_ST3 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(c02_Off_Stage1_Stage2 data)
 *   Std_ReturnType Rte_Write_P_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3(c02_Presf_Disp_Rq data)
 *   Std_ReturnType Rte_Write_P_RBTM_FL_Tgl_ST3_RBTM_FL_Tgl_ST3(DC_BOOL data)
 *   Std_ReturnType Rte_Write_P_RevBltTns_FL_SafeCyc_Actv_ST3_RevBltTns_FL_SafeCyc_Actv_ST3(c02_Ndef_False_True_ST3 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: BeltTensionerFunction_Main_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, BeltTensionerFunction_CODE) BeltTensionerFunction_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: BeltTensionerFunction_Main
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define BeltTensionerFunction_STOP_SEC_CODE
#include "BeltTensionerFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
