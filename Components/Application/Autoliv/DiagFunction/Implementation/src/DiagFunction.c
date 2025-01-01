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
 *             File:  DiagFunction.c
 *           Config:  S:\Tools\Vector_configuration\Workspace\Daimler MMA/S:/Tools/Vector_configuration/Workspace/Daimler MMA/StartApplication.dpa
 *        SW-C Type:  DiagFunction
 *  Generation Time:  2024-02-19 13:19:52
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  C-Code implementation template for SW-C <DiagFunction>
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
 * DataPrimitiveType_uint16
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * DataPrimitiveType_uint32
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * DataPrimitiveType_uint8
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_SesCtrlType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Erase_All_Start_StatusPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Erase_All_Start_StatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_UdsStatusByteType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_ASR42_BlockIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * NvM_ASR42_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
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
 * REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt
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
 * StbM_TimeBaseStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * UInt16
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * UInt32
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * UInt8
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * b8AlgorithmFlagsStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * b8BooleanType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * b8DefectStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * b8IsActiveDiagSessionType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * b8IsCarAccelerationLowType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * b8IsCarCrankingActiveType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * b8IsCarCrashDetectedType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * b8PyroActivationStatusType
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
 * c04_RBTM_ActvClient
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
 * c06_RBTM_LVL_Rq
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * c06_RBTM_Lvl_Stat
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
 * c10_RBTM_Fct_Precond
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
 * s16AccelerationPedalPositionRateType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16AccelerationType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16AngleRateType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16BeltPosition_degType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16BeltPosition_mmType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16BrakePressureRateType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16HWAngleType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16HWRateType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16InternalTemperature_deg_Type
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s16MotorPowerOrderType
 *   SInt16 represents integers with a minimum value of -32768 and a maximum value 
 *      of 32767. The order-relation on sint16 is: x < y if y - x is positive.
 *      sint16 has a lexical representation consisting of an optional sign followed
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12678, +10000, 2500
 *
 * s32BeltSpeed_deg_sType
 *   sint32 represents integers with a minimum value of -2147483648 and a maximum 
 *      value of 2147483647. The order-relation on sint32 is: x < y if y - x is
 *      positive. sint32 has a lexical representation consisting of an optional sign 
 *      allowed by a finite-length sequence of decimal digits (#x30-#x39). If the 
 *      sign is omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12688778, +10000, 250098675.
 *
 * s32BeltSpeed_mm_sType
 *   sint32 represents integers with a minimum value of -2147483648 and a maximum 
 *      value of 2147483647. The order-relation on sint32 is: x < y if y - x is
 *      positive. sint32 has a lexical representation consisting of an optional sign 
 *      allowed by a finite-length sequence of decimal digits (#x30-#x39). If the 
 *      sign is omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12688778, +10000, 250098675.
 *
 * s32MotorCurrentInmAType
 *   sint32 represents integers with a minimum value of -2147483648 and a maximum 
 *      value of 2147483647. The order-relation on sint32 is: x < y if y - x is
 *      positive. sint32 has a lexical representation consisting of an optional sign 
 *      allowed by a finite-length sequence of decimal digits (#x30-#x39). If the 
 *      sign is omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12688778, +10000, 250098675.
 *
 * s32OrderValueType
 *   sint32 represents integers with a minimum value of -2147483648 and a maximum 
 *      value of 2147483647. The order-relation on sint32 is: x < y if y - x is
 *      positive. sint32 has a lexical representation consisting of an optional sign 
 *      allowed by a finite-length sequence of decimal digits (#x30-#x39). If the 
 *      sign is omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, -12688778, +10000, 250098675.
 *
 * s8MotorCurrentInAType
 *   sint8 represents integers with a minimum value of -128 and a maximum value of 127.
 *      The order-relation on sint8 is: x < y if y - x is positive.
 *      sint8 has a lexical representation consisting of an optional sign followed 
 *      by a finite-length sequence of decimal digits (#x30-#x39). If the sign is 
 *      omitted, "+" is assumed. 
 *      
 *      For example: -1, 0, 12678, +10000.
 *
 * u16BoostPWMOrderType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16BrakePressureType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16CalibBlockIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16CurrentInLSBType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16InternalTemperatureType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16Resistance_mOhmType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16SampledSignalType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16StepDurationType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16VehicleSpeedType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u16VoltageType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * u32AecGroupsType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * u32DeficiencyLevelType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * u32InternalCounterType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * u32ModeMaskType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * u32RelativeSystemTimeType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * u32ResetCauseType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * u32ResetReasonNotificationStatusType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * u32ResetReasonNotificationType
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * u8AccelerationPedalPositionType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8AecCommandType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8AecIdentifierType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8AecStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8AutoTestIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8BatteryVoltageSurveyStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8BeltParkingAuthorizationStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8BeltSlackStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8CanNmStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8ClkStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8CycleNumberType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8DoorSwitchStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8EccErrorStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8EccErrorType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8EsmEventIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8EsmStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8HapticRequestType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8JobTypesListType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8KlemmenStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8MemoryClusterType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8ModeStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8MotorStageStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8OrdersListType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8PreCrashRequestType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8PreCrashSeverityLevelType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8PwmChannelIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8RetractionStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8SeverityLevelType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8StepNumberType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8TensioningStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8TestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8TriggeringSourceType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8VelocityTargetType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8WdgTestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * u8lBuckleSwitchStatusType
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
 * P_ROE
 *   Response on Event (degraded)
 *
 * R_DI_Odo_Pr5_ST3
 *   DriverInformation Odometer (degraded)
 *
 * R_Sec_Event_ST3
 *   Security event
 *
 *
 * Data Element Prototypes:
 * ========================
 * ROE_XX_ST3 of Port Interface IG_ROE_XX_ST3_4ewk6hdthg4k2abg4vkvktubw
 *   SHORT: Response on Event
 *      LONG: Response on Event (degraded)
 *
 * BltSlckDec_Md_XX_Stat_ST3 of Port Interface IF_BltSlckDec_Md_XX_Stat_ST3
 *   SHORT: Belt slack decreasing mode front left state
 *      LONG: Belt slack decreasing mode front left state
 *
 * DI_Odo_Pr5_ST3 of Port Interface IG_DI_Odo_Pr5_ST3_dqmkbik4b90gceqe8t96kp3yd
 *   SHORT: DriverInformation Odometer
 *      LONG: DriverInformation Odometer (degraded)
 *
 * PS_Curve_FL_Stat_ST3 of Port Interface IF_PS_Curve_FL_Stat_ST3
 *   SHORT: PreSafe Curve mode state front left
 *
 * PS_Curve_FR_Stat_ST3 of Port Interface IF_PS_Curve_FR_Stat_ST3
 *   SHORT: PreSafe Curve mode state front right
 *
 * Data of Port Interface IF_Sec_Event_ST3
 *   SHORT: Security event
 *      LONG: Security event
 *
 *
 * Operation Prototypes:
 * =====================
 * ReadAbsoluteSystemTime of Port Interface icsSystemTime
 *   To read the absolute system time (time elapsed since the initial ECU programming)
 *      
 *      COVERS: PRO_SF05_3449
 *
 *********************************************************************************************************************/

#include "Rte_DiagFunction.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "vstdlib.h"
#include "Nvp_Generated.h"
#include "NvM.h"
#include "SchM_Fee.h"
#include "SchM_Fls_17_Dmu.h"
#include "DiagFunction_Public.h"
#include "StbM.h"
#include "CanTSyn.h"
#include "common.h"
#include "IfxDmu_reg.h"
#include "IfxCbs_reg.h"
#include "IfxCbs_regdef.h"
#include "Csm.h"
#include "Csm_Cfg.h"
#include "DIA.h"

/*************************************************************************
Declaration of macros
*************************************************************************/

#define ECU_SN_BLOCK_SIZE           12u
#define SEATBELT_SN_BLOCK_SIZE      13u
#define ECU_SIDE_RBTM_FR            0x99u

#define DETECT_ECU_SIDE(ecuLocation) (ecuLocation==ECU_SIDE_RBTM_FR) ? "RBTMFR174" : "RBTMFL174"
#define EXPORTED_DIAG_VARIANT(ecuLocation) (ecuLocation==ECU_SIDE_RBTM_FR) ? "RBTMFR174 V090" : "RBTMFL174 V090"
#define HW_PART_NUMBER(ecuLocation) (ecuLocation==ECU_SIDE_RBTM_FR) ? "1749018500" : "1749018400"
#define FblInvert16Bit(x)        ((uint16)((x) ^ ((uint16)0xFFFFu)))

#define SWHW_SWSW_MISSMATCH         0x06

#define DIAG_ROUTINE_SUCCESFULL     0x00u

#define ODOMETER_LOW_RES_CONVERSION 160u

/* ROE */
#define SWCDIAG_NOT_INITIALIZED                                       0x00u /*!< used to give #SwcDiag_Status a data value in its definition. */
#define SWCDIAG_INITIALIZED                                           0xA9u /*!< used to initialize #SwcDiag_Status in ::SwcDiag_Init and for testing
                                                                                 module initialization later. */
#define DIAG_NOTCOMPLETEDLASTCLEAR 0x10u
#define DIAG_DTC_REPORT_MARSK      0x09u
#define SWCDIAG_ROELITE_FIFO_SIZE                                    8u /*!< RoE Queue Size. */
#define SWCDIAG_ROELITE_ENTRY_SIZE                                   8u /*!< Max byte number of dynamic data queued for RoE responses, here equals RoE PDU Size. */
#define SWCDIAG_ROE_DTCSTATUSCHANGE                                  1u
#define SWCDIAG_ROE_AVAILABILITY_DATA                                4u
#define SWCDIAG_ROE_DIAGSESSIONCHANGE                                5u

#define SWCDIAG_AVAILABILITY_CAT_IDX                                  2 /*!< Used to index Availability Data Category in RoE PDUs. */
/*! Used to index Obsolescence and Consumable Data Block Number in RoE PDUs. */
#define SWCDIAG_CONSUMABLE_BLOCK_IDX                                  1
#define SWCDIAG_CONSUMABLE_REPLACE_IDX                                2 /*!< Used to reference the starting index of replaced data in Obsolescence and
                                                                             Consumable Data RoE PDUs. */

#define SWCDIAG_PRIO_EMPTY                                            0u /*!< Signifies an empty slot in #SwcDiag_RoEPDUPriority. */
#define SWCDIAG_PRIO_BUSY                                             2u /*!< Signifies a busy slot in #SwcDiag_RoEPDUPriority (being written or being
                                                                              sent. */
#define SWCDIAG_PRIO_FIRST_NEXT                                       1u /*!< Used to initialize #SwcDiag_NextPriority, also to test
                                                                              #SwcDiag_RoEPDUPriority for having odd values. */
#define SWCDIAG_PRIO_STEP                                             2u /*!< Used to increment #SwcDiag_NextPriority. */
#define SWCDIAG_PRIO_OVFL_THRESHOLD                                   0x8000u /*!< Used to test if priorities inside #SwcDiag_RoEPDUPriority have
                                                                                   overflowed. (refer to \ref overflow) */

#define SWCDIAG_ROE_KIND_IDX                                          0    /*!< Used to index RoE Kind byte in RoE PDUs. */
#define SWCDIAG_ROE_FILL_BYTE                                         0x00 /*!< Used to fill unused bytes in RoE PDUs. */

#define SWCDIAG_ROE_SESSION_IDX                                       1 /*!< Used to index Diagnostic Session byte in RoE PDUs */
#define SWCDIAG_INITIAL_SESSION                                       0 /*!< Used to initialize #SwcDiag_LastSession. (See ::SwcDiag_Init detailed*/

#define SWCDIAG_DTC_1STBYTE_IDX                                      2 /*!< Used to index DTC Byte 1 in RoE PDUs. */
#define SWCDIAG_DTC_2NDBYTE_IDX                                      3 /*!< Used to index DTC Byte 2 in RoE PDUs. */
#define SWCDIAG_DTC_3RDBYTE_IDX                                      4 /*!< Used to index DTC Byte 3 in RoE PDUs. */
#define SWCDIAG_DTC_STATUSMASK_IDX                                   5 /*!< Used to index DTC Status Byte in RoE PDUs. */

#define SWCDIAG_200MS_IN_MAIN_CYCLES                                 10U

/*! Inference of Rte Mode FULL_COMMUNICATION. */
#define SWCDIAG_FULL_COMMUNICATION                                   RTE_MODE_CommunicationMode_COMM_FULL_COMMUNICATION


/* definition for counter location in NVP */
#define KU8_COMFORT_COUNTER_LOC		(uint8)0
#define KU8_LOW_FORCE_COUNTER_LOC	(uint8)1
#define KU8_HIGH_FORCE_COUNTER_LOC	(uint8)2
#define KU8_MAX_FORCE_COUNTER_LOC	(uint8)3
#define KU8_ACTIV_REQ_COUNTER_LOC	(uint8)4

/*Make sure that address matches the one defined on FBL side, where FBL version is written*/
#define DIAG_FBL_SW_VERSION_LOCATION    0xA006BC60

#define DIAG_NR_OF_LOGICAL_BLOCKS       0x03u
#define DIAG_SIZE_OF_REPROG_ATTEMPTS    0x04u

/* Definitions for Erase All Routine */
#define ERASE_ALL_ARRAY_INDEX_1  0u
#define ERASE_ALL_ARRAY_INDEX_2  1u
#define ERASE_ALL_ARRAY_INDEX_3  2u
#define ERASE_ALL_ARRAY_INDEX_4  3u
#define ERASE_ALL_ARRAY_INDEX_5  4u
#define ERASE_ALL_ARRAY_INDEX_6  5u
#define ERASE_ALL_ARRAY_INDEX_7  6u
#define ERASE_ALL_ARRAY_INDEX_8  7u
#define ERASE_ALL_ARRAY_INDEX_9  8u
#define ERASE_ALL_ARRAY_INDEX_10 9u
#define ERASE_ALL_ARRAY_INDEX_11 10u
#define ERASE_ALL_ARRAY_INDEX_12 11u

/* 01A2 - ECU Trust Model CSR Supplier Signature */
#define CSR_SUPPLIER_PUBLIC_KEY_LEADING_BYTES_SIZE 1u
#define CSR_SUPPLIER_PUBLIC_KEY_SIZE 129u
#define CSR_SUPPLIER_SIGNATURE_LEADING_BYTES_SIZE 1u
#define CSR_SUPPLIER_SIGNATURE_SIZE 129u
#define CSR_SUPPLIER_SIGNATURE_BLOCK_SIZE 258u

/*************************************************************************
LOCAL variables declaration
*************************************************************************/

/* 01A2 - ECU Trust Model CSR Supplier Signature */
static uint8 u8CSRSupplierSignature[CSR_SUPPLIER_SIGNATURE_BLOCK_SIZE];
NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_StorageType NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_RamBlockData;
const NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_StorageType NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_DefaultData = {0U};

/* Flag to describe the NvM Queue Status for the large DIDs */
static boolean DIA_bIsNvmQueued = B_FALSE;

/* ROE */
/*! Holds initialization status of SwcDiag */
static VAR(uint8, SWCDIAG_VAR_INIT) SwcDiag_Status = SWCDIAG_NOT_INITIALIZED;

/*! the next priority that will be assigned to a newly queued or replaced RoE entry, refer to \ref qalgo for more
 * details. */
static VAR(uint16, SWCDIAG_VAR_NOINIT) SwcDiag_NextPriority;
static VAR(uint16, SWCDIAG_VAR_NOINIT) SwcDiag_RoePDUTimer; /*!< Timer to fulfill the minimum interval requirement of RoE PDU Sending. */

static VAR(uint16, SWCDIAG_VAR_NOINIT) SwcDiag_RoEPDUPriority[SWCDIAG_ROELITE_FIFO_SIZE];
/*! RoE PDUs Buffer */
static VAR(uint8, SWCDIAG_VAR_NOINIT) SwcDiag_RoEPDUQueue[SWCDIAG_ROELITE_FIFO_SIZE][SWCDIAG_ROELITE_ENTRY_SIZE];

typedef enum{
    UCB_DBG_None_e,
    UCB_DBG_Lock_e,
    UCB_DBG_Unlock_e,
}UCB_DBG_t;

static uint8 ecuName[] = "RBTMFL174";
static uint8 HSMPartNo[] ="1749025702";

tAppCommonData DiagCommonData =
{
   /* ECU hardware version (year, week, patch level, uint8 encoded)        *
    * Example: year = 2012, week = 14, patch level = 0                     *
    * DID: F150                                                            */
   { 23u, 17u, 1u },

   /* Hardware supplier information (defined by Daimler for each supplier) *
    * Example: Vector = 0x008B                                             *
    * Autoliv = 0x0077                                                     *
    * DID: F154                                                            */
   { 0x00u, 0x77 },

   /* DID F155                                                             *
    * Software Supplier information                                        *
    * Vector = 0x008B;                                                     *
    * Autoliv = 0x0077                                                     *
    * Hsm = 0x008B                                                         */
   { 0x00, 0x8B },
   { 0x00, 0x77 },
   { 0x00, 0x8B },

   /* Hardware part number (ASCII encoded)                                 *
    * DID: F111, business unit specific                                    */
   /* Value now set during init, based on NVM block and side               */
   { "0000000000" },

   /* Application software part number                                     *
    * DID: F121, business unit specific                                    */
   { "1749025500" },

   /* FBL software part number                                             *
    * DID: F121, business unit specific                                    */
   { "1749041800" },

   /* Application software version (year, week, patch level, uint8 encoded)*
    * Example: year = 2012, week = 14, patch level = 0                     *
    * DID: F151                                                            
    * Modify SW Version from const below, since this will be inited       *
    * by that value (stDiag_Appl_SW_Version)                               */
   { 24u, 03u, 01u },

   /* Boot software version (year, week, patch level, uint8 encoded)       *
    * Example: year = 2012, week = 14, patch level = 0                     *
    * DID: F153
    * Modify SW Version from const bellow, since this will be inited       *
    * by that value pDiag_FBL_SW_Version                                   */
   { 23u, 31u, 01u },

   /* 0xF100                                                               *
    * Active diagnostic information:                                       *
    * Active diagnostic status: 0=Application, 1=Boot                      *
    * Active diagnostic variant                                            *
    * Active diagnostic version                                            */
   { 0x00, 0x02, 0x0A },

    /* F18C - ECU serial number                                            */    
    &NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData,

    /* 0xF10D App DDS version                                              *
     * Year:Month:Patch                                                    */
   { 20u, 1u },

    /* 0xF10D Boot DDS version                                             *
     * Year:Month:Patch                                                    */
   { 20u, 1u },

    /* EF00 - Ecu Extract Information                                      *
     * Ecu extract Version: {major, minor, patch}                          *
     * XDIS Version                                                        *
     * Export date                                                         *
     * ECU Name                                                            */
    {
        { 0x23u, 0x29u, 0x00u },
        { 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u },
        { "2023 07 20" },
        { "RBTMFL174                     "}
    },

    /* 0xEF01 Candela Extract Version *KEEP SPACES*                        *
     * Diagnostic Extract DDM Version *KEEP SPACES*                        *
     * Diagnostic Extract Version                                          *
     * Exported Diagnostic Variant                                         */
    {   { "14 SP 1   " },
        { "14 SP 1   " },
        { 0x06u, 0x09u, 0x04u },
        { "RBTMFL174 V090                "}
    },

    /* 0xEF03 Standard Application SW Package Version                      *
     * Standard Application uC Identification *KEEP SPACES*                *
     * Standard Application SW Package Build Version                       *
     * Standard Application Autosar Platform                               */
    {   { 0x24, 0x03u, 0x01u },
        { "TC322LP             " },
        { 0x00 },
        { 0x00 }
    },

    /* 0xEF05 Minimum software version                                     */
    { 0u, 0u, 0u },

    /* 0xF103 Hardware supplier information                                */
    { "0077" },

    /* 0x0340 Unique seatbelt serialnubmer                                 */
    &NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_RamBlockData,

   /* ECU Name                                                             *
    * DID: F104                                                            */
   ecuName
};

static tFblMetadata DiagFblMetadataFbl;
static tFblMetadata DiagFblMetadataApp;
static tFblMetadata DiagFblMetadataHsm;
static UCB_DBG_t UCB_DBG_Do_en = UCB_DBG_None_e;
static uint8 HSM_Version_au8[3u] = {0u};

/**************************************************************************
External variables/const
**************************************************************************/

const tFblMetadata NvMBlock_FblMetaData_DefaultValue = 
{
    /*FpStatusInfo*/
    0xFF,
    /*Fingeprint*/
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    /*ProgAttempts*/
    {0xFFFF},
    /*CRC*/    
    {0xFF, 0xFF, 0xFF, 0xFF},
    /*SwVersion*/    
    {0xFF, 0xFF, 0xFF},
    /*SwPartNumber*/
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    /*SwSupplierInformation*/
    {0xFF, 0xFF},
    /*MinimumSoftwareVersion*/
    {0x00, 0x00, 0x00},    
    /*Cmac*/
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    /*CRCWritten*/    
    {0xFF, 0xFF, 0xFF, 0xFF},
    /*SegmentCount*/
    0xFF,
    /*SegmentAddrList*/
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    /*SegmentLengthList*/
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}
};

#define APPL_SWVERSIONS_START_SEC_CONST
#include "MemMap.h"
const tGeneralVersion stDiag_Appl_SW_Version = {24u, 15u, 00u};
#define APPL_SWVERSIONS_STOP_SEC_CONST
#include "MemMap.h"

const tGeneralVersion * pDiag_FBL_SW_Version = DIAG_FBL_SW_VERSION_LOCATION;

static StbM_SyncRecordTableBlockType MeasurementSets[12];
static uint8 MeasurementSet_Index = 0;
static uint8 MeasurementSet_LastIndex = 0;

/*! State variable for writing the whole NVM. */
static VAR(uint8, DiagFunction_VAR_NOINIT) DiagFunction_NvmWriteAll_Status;
static VAR(uint8, DiagFunction_VAR_NOINIT) DiagFunction_WriteAllFlag;

/**************************************************************************
External Functions
**************************************************************************/

extern FUNC(void, Ssa_Coding_CODE) CodingAppl_Copy(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) targetBuf, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) dataBuf, uint32_least dataLength);
extern FUNC(boolean, Ssa_Coding_CODE) Coding_CompareData(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) buffer1, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) buffer2, uint32 size);

/**************************************************************************
Local Functions
**************************************************************************/

static FUNC(Std_ReturnType, DiagFunction_CODE) ConditionCheckRead_General(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode);
static void DiagCopyVectorToAddress(uint8 * destination, uint8 * source, uint8 size);
static uint8 DiagConvert2BCD(uint8 hexData);
static uint32 dflash_erase(uint32 addr, uint32 cnt);
static uint32 dflash_program(uint32 addr, uint32* pmem);
static FUNC(void, SWCDIAG_CODE) QueueDTCRoEEntry(CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) entry);
static FUNC(boolean, SWCDIAG_CODE) QueueAvailabilityRoEEntry(CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) entry);
static FUNC(boolean, SWCDIAG_CODE) QueueCnsmblObslscncRoEEntry(CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) entry);
static FUNC(boolean, SWCDIAG_CODE) QueueRoEEntry(CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) entry);
static FUNC(void, SWCDIAG_CODE) ProcessRoeQueue(void);
static boolean DiagReadMetaData(void);

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
 * DataPrimitiveType_uint16: Integer in interval [0...65535]
 * DataPrimitiveType_uint32: Integer in interval [0...4294967295]
 * DataPrimitiveType_uint8: Integer in interval [0...255]
 * Dcm_NegativeResponseCodeType: Integer in interval [0...255]
 * Dcm_OpStatusType: Integer in interval [0...64]
 * Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType: Integer in interval [0...255]
 * Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType: Integer in interval [0...255]
 * Dcm_SesCtrlType: Integer in interval [0...126]
 * Dcm_StartDataOut_Routine_Erase_All_Start_StatusPrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Erase_All_Start_StatusType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoPrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusPrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoPrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultPrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoPrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType: Integer in interval [0...255]
 * Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType: Integer in interval [0...255]
 * Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType: Integer in interval [0...255]
 * Dem_UdsStatusByteType: Integer in interval [0...255]
 * NvM_ASR42_BlockIdType: Integer in interval [0...65535]
 * NvM_ASR42_RequestResultType: Integer in interval [0...255]
 * NvM_RequestResultType: Integer in interval [0...8]
 * Rsrv04: Integer in interval [0...15]
 * Rsrv08: Integer in interval [0...255]
 * StbM_TimeBaseStatusType: Integer in interval [0...63]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 * b8AlgorithmFlagsStatusType: Integer in interval [0...255]
 * b8BooleanType: Integer in interval [0...255]
 * b8DefectStatusType: Integer in interval [0...255]
 * b8IsActiveDiagSessionType: Integer in interval [0...255]
 * b8IsCarAccelerationLowType: Integer in interval [0...255]
 * b8IsCarCrankingActiveType: Integer in interval [0...255]
 * b8IsCarCrashDetectedType: Integer in interval [0...255]
 * b8PyroActivationStatusType: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * c01_FalseTrue: Integer in interval [0...1]
 * c02_Bckl_Sw_Stat: Integer in interval [0...3]
 * c02_BeltHdOvr_Stat: Integer in interval [0...3]
 * c02_Dr_Stat: Integer in interval [1...3]
 * c02_EVC_Stat: Integer in interval [1...3]
 * c02_Inactv_Silent_Actv_ST3: Integer in interval [0...3]
 * c02_Ndef_False_True_ST3: Integer in interval [1...3]
 * c02_Off_On: Integer in interval [0...3]
 * c02_Off_Stage1_Stage2: Integer in interval [0...3]
 * c02_PT_Rdy_V2: Integer in interval [0...3]
 * c02_Presf_Disp_Rq: Integer in interval [0...1]
 * c02_Presf_Snd: Integer in interval [0...3]
 * c02_StStyle: Integer in interval [1...3]
 * c02_TransMd_Stat: Integer in interval [0...3]
 * c02_TurnIndLvr_Stat: Integer in interval [0...3]
 * c02_false_true_sna: Integer in interval [0...3]
 * c03_ADAS_Posn_Idx: Integer in interval [0...3]
 * c03_Accel_Md_ST3: Integer in interval [0...7]
 * c03_EngStartPN14_Stat: Integer in interval [0...7]
 * c03_ISw_Stat: Integer in interval [0...7]
 * c03_MsgTyp_1_to_7: Integer in interval [1...7]
 * c03_No_Lt_Rt_Both: Integer in interval [0...7]
 * c03_PN14_ProdMd_Stat_ST3: Integer in interval [0...7]
 * c03_PN14_TDP_Sw_Stat: Integer in interval [0...7]
 * c04_DrvPosn_ST3: Integer in interval [1...15]
 * c04_Presf_Frct_ST3: Integer in interval [0...15]
 * c04_Presf_Lvl_V2: Integer in interval [0...15]
 * c04_RBTM_ActvClient: Integer in interval [0...15]
 * c04_VehOpMode: Integer in interval [0...15]
 * c05_ADAS_ProfShort_ProfTyp: Integer in interval [1...31]
 * c05_DPC_Md_PT_HU: Integer in interval [0...31]
 * c06_Idx_0_to_63_1: Integer in interval [0...63]
 * c06_RBTM_LVL_Rq: Integer in interval [0...63]
 * c06_RBTM_Lvl_Stat: Integer in interval [0...63]
 * c08_0_255_1_SNA_na: Integer in interval [0...255]
 * c08_ROE_0: Integer in interval [0...6]
 * c08_UInt_SNA_na: Integer in interval [0...255]
 * c08_km_p_h_0_254_1: Integer in interval [0...255]
 * c09_m_p_s_m12k8_89k2_0k2: Integer in interval [0...511]
 * c09_ms_0_510_5: Integer in interval [0...511]
 * c10_ADAS_CountryCode: Integer in interval [0...1023]
 * c10_RBTM_Fct_Precond: Integer in interval [0...65535]
 * c10_V_0_25k55_0k025: Integer in interval [0...1023]
 * c10_WakeupRsn_ST3: Integer in interval [0...1023]
 * c10_m_0_510_1: Integer in interval [0...1023]
 * c10_to_1022_1: Integer in interval [0...1023]
 * c12_0_4094_1_SNA: Integer in interval [0...4095]
 * c12_km_p_h_0_409k4_0k1: Integer in interval [0...4095]
 * c13_PresfAct_Adj_Rq: Integer in interval [0...4294967295]
 * c13_m_0_8190_1: Integer in interval [0...8191]
 * c15_ADAS_RegionCode: Integer in interval [0...32767]
 * c16_CRC_woSNA: Integer in interval [0...65535]
 * c24_km_0_999999k9_0k1_Invld_SNA: Integer in interval [0...16777215]
 * dtRef_VOID: DataReference
 * s16AccelerationPedalPositionRateType: Integer in interval [-32768...32767]
 * s16AccelerationType: Integer in interval [-32768...32767]
 * s16AngleRateType: Integer in interval [-32768...32767]
 * s16BeltPosition_degType: Integer in interval [-32768...32767]
 * s16BeltPosition_mmType: Integer in interval [-32768...32767]
 * s16BrakePressureRateType: Integer in interval [-32768...32767]
 * s16HWAngleType: Integer in interval [-32768...32767]
 * s16HWRateType: Integer in interval [-32768...32767]
 * s16InternalTemperature_deg_Type: Integer in interval [-32768...32767]
 * s16MotorPowerOrderType: Integer in interval [-32768...32767]
 * s32BeltSpeed_deg_sType: Integer in interval [-2147483648...2147483647]
 * s32BeltSpeed_mm_sType: Integer in interval [-2147483648...2147483647]
 * s32MotorCurrentInmAType: Integer in interval [-2147483648...2147483647]
 * s32OrderValueType: Integer in interval [-2147483648...2147483647]
 * s8MotorCurrentInAType: Integer in interval [-128...127]
 * sint16: Integer in interval [-32768...32767] (standard type)
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * u16BoostPWMOrderType: Integer in interval [0...65535]
 * u16BrakePressureType: Integer in interval [0...65535]
 * u16CalibBlockIdType: Integer in interval [0...65535]
 * u16CurrentInLSBType: Integer in interval [0...65535]
 * u16InternalTemperatureType: Integer in interval [0...65535]
 * u16Resistance_mOhmType: Integer in interval [0...65535]
 * u16SampledSignalType: Integer in interval [0...65535]
 * u16StepDurationType: Integer in interval [0...65535]
 * u16VehicleSpeedType: Integer in interval [0...65535]
 * u16VoltageType: Integer in interval [0...65535]
 * u32AecGroupsType: Integer in interval [0...4294967295]
 * u32DeficiencyLevelType: Integer in interval [0...4294967295]
 * u32InternalCounterType: Integer in interval [0...4294967295]
 * u32ModeMaskType: Integer in interval [0...4294967295]
 * u32RelativeSystemTimeType: Integer in interval [0...4294967295]
 * u32ResetCauseType: Integer in interval [0...4294967295]
 * u32ResetReasonNotificationStatusType: Integer in interval [0...4294967295]
 * u32ResetReasonNotificationType: Integer in interval [0...4294967295]
 * u8AccelerationPedalPositionType: Integer in interval [0...255]
 * u8AecCommandType: Integer in interval [0...255]
 * u8AecIdentifierType: Integer in interval [0...255]
 * u8AecStatusType: Integer in interval [0...255]
 * u8AutoTestIdType: Integer in interval [0...255]
 * u8BatteryVoltageSurveyStatusType: Integer in interval [0...255]
 * u8BeltParkingAuthorizationStateType: Integer in interval [0...255]
 * u8BeltSlackStatusType: Integer in interval [0...255]
 * u8CanNmStateType: Integer in interval [0...255]
 * u8ClkStatusType: Integer in interval [0...255]
 * u8CycleNumberType: Integer in interval [0...255]
 * u8DoorSwitchStatusType: Integer in interval [0...255]
 * u8EccErrorStatusType: Integer in interval [0...255]
 * u8EccErrorType: Integer in interval [0...255]
 * u8EsmEventIdType: Integer in interval [0...255]
 * u8EsmStateType: Integer in interval [0...255]
 * u8HapticRequestType: Integer in interval [0...255]
 * u8JobTypesListType: Integer in interval [0...255]
 * u8KlemmenStatusType: Integer in interval [0...255]
 * u8MemoryClusterType: Integer in interval [0...255]
 * u8ModeStatusType: Integer in interval [0...255]
 * u8MotorStageStatusType: Integer in interval [0...255]
 * u8OrdersListType: Integer in interval [0...255]
 * u8PreCrashRequestType: Integer in interval [0...255]
 * u8PreCrashSeverityLevelType: Integer in interval [0...255]
 * u8PwmChannelIdType: Integer in interval [0...255]
 * u8RetractionStatusType: Integer in interval [0...255]
 * u8SeverityLevelType: Integer in interval [0...255]
 * u8StepNumberType: Integer in interval [0...255]
 * u8TensioningStateType: Integer in interval [0...255]
 * u8TestResultType: Integer in interval [0...255]
 * u8TriggeringSourceType: Integer in interval [0...255]
 * u8VelocityTargetType: Integer in interval [0...255]
 * u8WdgTestResultType: Integer in interval [0...255]
 * u8lBuckleSwitchStatusType: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * ARR_08_UInt_noSNA_7: Array with 7 element(s) of type c08_UInt_SNA_na
 * Dcm_Data1000ByteType: Array with 1000 element(s) of type uint8
 * Dcm_Data10ByteType: Array with 10 element(s) of type uint8
 * Dcm_Data1270ByteType: Array with 1270 element(s) of type uint8
 * Dcm_Data12ByteType: Array with 12 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data20ByteType: Array with 20 element(s) of type uint8
 * Dcm_Data2540ByteType: Array with 2540 element(s) of type uint8
 * Dcm_Data254ByteType: Array with 254 element(s) of type uint8
 * Dcm_Data258ByteType: Array with 258 element(s) of type uint8
 * Dcm_Data2613ByteType: Array with 2613 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data30ByteType: Array with 30 element(s) of type uint8
 * Dcm_Data381ByteType: Array with 381 element(s) of type uint8
 * Dcm_Data3ByteType: Array with 3 element(s) of type uint8
 * Dcm_Data4092ByteType: Array with 4092 element(s) of type uint8
 * Dcm_Data48ByteType: Array with 48 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_Data508ByteType: Array with 508 element(s) of type uint8
 * Dcm_Data8ByteType: Array with 8 element(s) of type uint8
 * Dcm_StartFlexibleInArrayData_Routine_PreCheckProgrammingDependencies_Start_Pre_Check_InformationsType: Array with 4064 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Impl_Current_and_Threshold: Record with elements
 *   Current_Value of type uint16
 *   Threshold_Green_to_Yellow of type uint16
 *   Threshold_Yellow_to_Red of type uint16
 * Impl_Obsolescense_Data: Record with elements
 *   BSR of type Impl_Current_and_Threshold
 *   Haptic_Warning of type Impl_Current_and_Threshold
 *   PRE_SAFE_LVL_4_5 of type Impl_Current_and_Threshold
 *   PRE_CRASH of type Impl_Current_and_Threshold
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
 * REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw: Record with elements
 *   PT4_PTCoor_PT_Rdy_ST3 of type c02_PT_Rdy_V2
 *   PT4_PTCoor_EngStartPN14_Stat_ST3 of type c03_EngStartPN14_Stat
 * REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u: Record with elements
 *   PT4_PTCoor_Accel_Md_ST3 of type c03_Accel_Md_ST3
 * REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh: Record with elements
 *   PT4_PTCoor_DrvPosn_Stat_ST3 of type c04_DrvPosn_ST3
 * REC_PreSafeRecInputType: Record with elements
 *   u8TensioningStateType of type u8TensioningStateType
 *   u8BuckleStateType of type c02_Bckl_Sw_Stat
 *   u8PresafeLevelType of type c04_Presf_Lvl_V2
 *   bImpactXType of type DC_BOOL
 *   u8TensSuppType of type c03_No_Lt_Rt_Both
 *   bRoEventType1 of type DC_BOOL
 *   bRoEventType2 of type DC_BOOL
 *   u8IgnStat of type c03_ISw_Stat
 *   u8BeltHdOvStat of type c02_BeltHdOvr_Stat
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
 * REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt: Record with elements
 *   CRC_SBeltTens_SP_Lvl_Pr5_ST3 of type c16_CRC_woSNA
 *   RBTMFL_SP_Lvl_Rq_ST35 of type c06_RBTM_LVL_Rq
 *   RBTMFR_SP_Lvl_Rq_ST35 of type c06_RBTM_LVL_Rq
 *   Rsrv0_SBeltTens_SP_Lvl_Pr5_ST3 of type Rsrv04
 *   SQC_SBeltTens_SP_Lvl_Pr5_ST3 of type c08_0_255_1_SNA_na
 * REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4: Record with elements
 *   VehSpd8_ST3 of type c08_km_p_h_0_254_1
 *   CRC_VehSpd8_Pr5_ST3 of type c16_CRC_woSNA
 *   SQC_VehSpd8_Pr5_ST3 of type c08_0_255_1_SNA_na
 * StbM_SyncRecordTableBlockType: Record with elements
 *   GlbSeconds of type uint32
 *   GlbNanoSeconds of type uint32
 *   TimeBaseStatus of type StbM_TimeBaseStatusType
 *   VirtualLocalTimeLow of type uint32
 *   RateDeviation of type sint16
 *   LocSeconds of type uint32
 *   LocNanoSeconds of type uint32
 *   PathDelay of type uint32
 * StbM_TimeStampType: Record with elements
 *   timeBaseStatus of type StbM_TimeBaseStatusType
 *   nanoseconds of type uint32
 *   seconds of type uint32
 *   secondsHi of type uint16
 * StbM_UserDataType: Record with elements
 *   userDataLength of type uint8
 *   userByte0 of type uint8
 *   userByte1 of type uint8
 *   userByte2 of type uint8
 * stAbsoluteSystemTimeType: Record with elements
 *   u32SystemTimeInSec of type UInt32
 *   u8SystemTimeOffset of type UInt8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint8 *Rte_Pim_CustomerSettings(void)
 *     Returnvalue: uint8* is of type Dcm_Data4092ByteType
 *   uint8 *Rte_Pim_DiagnosticTraceMemory(void)
 *     Returnvalue: uint8* is of type Dcm_Data12ByteType
 *   uint8 *Rte_Pim_ISO_15675_2_BlockSize(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *   uint8 *Rte_Pim_ISO_15675_2_STmin(void)
 *     Returnvalue: uint8* is of type Dcm_Data1ByteType
 *
 *********************************************************************************************************************/


#define DiagFunction_START_SEC_CODE
#include "DiagFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ActiveDiagnosticInformation_Read_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActiveDiagnosticInformation_Read_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_ActiveDiagnosticInformation_Read_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- DID 0xF100 Active Diagnostic Information ------------------------------------------------------------------- */
/**
* \brief
*     DID F100
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ActiveDiagnosticInformation_Read_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActiveDiagnosticInformation_Read_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_ActiveDiagnosticInformation_Read_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F100
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.ActiveDiagnosticInformation[0];
        Data[1] = DiagCommonData.ActiveDiagnosticInformation[1];
        Data[2] = DiagCommonData.ActiveDiagnosticInformation[2];
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ActiveDiagnosticInformation_Read_Session>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActiveDiagnosticInformation_Read_Session_DCM_E_PENDING
 *   RTE_E_DataServices_ActiveDiagnosticInformation_Read_Session_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F100
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ActiveDiagnosticInformation_Read_Session_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ActiveDiagnosticInformation_Read_Session>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DCMServices_GetSesCtrlType(Dcm_SesCtrlType *SesCtrlType)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DCMServices_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ActiveDiagnosticInformation_Read_Session_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ActiveDiagnosticInformation_Read_Session_DCM_E_PENDING
 *   RTE_E_DataServices_ActiveDiagnosticInformation_Read_Session_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ActiveDiagnosticInformation_Read_Session_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F100
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ActiveDiagnosticInformation_Read_Session_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ActiveDiagnosticInformation_Read_Session_ReadData (returns application error)
 *********************************************************************************************************************/

    return Rte_Call_DCMServices_GetSesCtrlType(Data);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xF100 Active Diagnostic Information ------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x010B Adjust ISO 15765-2 BS and STmin Parameter -------------------------------------------------------------------------------------- */
/**
* \brief
*     DID 010B
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0272]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 010B
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0272]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))RtePim_ISO_15675_2_BlockSize(), 1U);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 010B
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0273]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_WriteData (returns application error)
 *********************************************************************************************************************/

    /* TO BE IMPLEMENTED: Write in NVM */
    Std_ReturnType retVal = RTE_E_OK;

    if (!Coding_CompareData(Data, RtePim_ISO_15675_2_BlockSize(), 1U))
    {
        CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))RtePim_ISO_15675_2_BlockSize(), Data, 1U);
    }

    *ErrorCode = DCM_E_POSITIVERESPONSE;
    return E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 010B
* \param
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0272]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 010B
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0272]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))RtePim_ISO_15675_2_STmin(), 1U);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_DCM_E_PENDING
 *   RTE_E_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 010B
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0273]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_WriteData (returns application error)
 *********************************************************************************************************************/

    /* TO BE IMPLEMENTED: Write in NVM */
    Std_ReturnType retVal = RTE_E_OK;

    if (!Coding_CompareData(Data, RtePim_ISO_15675_2_STmin(), 1U))
    {
        CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))RtePim_ISO_15675_2_STmin(), Data, 1U);
    }

    *ErrorCode = DCM_E_POSITIVERESPONSE;
    return E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_BSR_Counter_read_Read_BSR_Counter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BSR_Counter_read_Read_BSR_Counter_DCM_E_PENDING
 *   RTE_E_DataServices_BSR_Counter_read_Read_BSR_Counter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead_doc
 *********************************************************************************************************************/
/* ------------------------------------------------------------------------------- DID 0x0243 BSR Counter ------------------------------------------------------------------------------------------------------------ */
/**
* \brief
*     DID 0243
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0028 ]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_BSR_Counter_read_Read_BSR_Counter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BSR_Counter_read_Read_BSR_Counter_DCM_E_PENDING
 *   RTE_E_DataServices_BSR_Counter_read_Read_BSR_Counter_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0027, DSG_DIA_MMA_0035, DSG_DIA_MMA_0036 ]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = U32_GET_LOW_BYTE(NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_COMFORT_COUNTER_LOC]);
        Data[1] = U32_GET_LOW_MIDDLE_BYTE(NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_COMFORT_COUNTER_LOC]);
        Data[2] = U32_GET_HIGH_MIDDLE_BYTE(NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_COMFORT_COUNTER_LOC]);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0x0243 BSR Counter --------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID  DID 0xF153 Boot Software Version Information---------------------------------------------------------------------- */
/**
* \brief
*     DID F153
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0248, DSG_DIA_MMA_0249]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F153
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0248, DSG_DIA_MMA_0249]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuBootSoftwareVersion.Patch; /* Patch level */
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_BootSoftwareVersion_Read_Boot_SW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_week_DCM_E_PENDING
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F153
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0248, DSG_DIA_MMA_0249]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_BootSoftwareVersion_Read_Boot_SW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_week_DCM_E_PENDING
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F153
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0248, DSG_DIA_MMA_0249]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuBootSoftwareVersion.Minor; /* Week */
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_BootSoftwareVersion_Read_Boot_SW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_year_DCM_E_PENDING
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F153
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0248, DSG_DIA_MMA_0249]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_BootSoftwareVersion_Read_Boot_SW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_year_DCM_E_PENDING
 *   RTE_E_DataServices_BootSoftwareVersion_Read_Boot_SW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0248, DSG_DIA_MMA_0249]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuBootSoftwareVersion.Major; /* Year */
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Current_Operating_Time_Read_Current_Operating_Time>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Current_Operating_Time_Read_Current_Operating_Time_DCM_E_PENDING
 *   RTE_E_DataServices_Current_Operating_Time_Read_Current_Operating_Time_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead_doc
 *********************************************************************************************************************/
/* ------------------------------------------------------------------------------- DID 0x0133 Current Operating Time ---------------------------------------------------------------------- */
/**
* \brief
*     DID 0133
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0230, DSG_DIA_MMA_0231]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Current_Operating_Time_Read_Current_Operating_Time>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(StbM_TimeStampType *timeStampPtr, StbM_UserDataType *userDataPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_NOT_OK, RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Current_Operating_Time_Read_Current_Operating_Time_DCM_E_PENDING
 *   RTE_E_DataServices_Current_Operating_Time_Read_Current_Operating_Time_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 0133
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0230, DSG_DIA_MMA_0231]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret = E_NOT_OK;

   StbM_TimeStampType timeStamp;
   StbM_UserDataType userData;

   if (NULL_PTR != Data)
   {
       ret = Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(&timeStamp, &userData);

       /* convert to miliseconds */
       timeStamp.seconds = timeStamp.seconds * 1000u;

       Data[3] = timeStamp.seconds;
       Data[2] = timeStamp.seconds >> 8;
       Data[1] = timeStamp.seconds >> 16;
       Data[0] = timeStamp.seconds >> 24;
   }
   else
   {
       ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Current_Operating_Time_Read_Operating_Time_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Current_Operating_Time_Read_Operating_Time_Status_DCM_E_PENDING
 *   RTE_E_DataServices_Current_Operating_Time_Read_Operating_Time_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Current_Operating_Time_Read_Operating_Time_Status>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(StbM_TimeStampType *timeStampPtr, StbM_UserDataType *userDataPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_NOT_OK, RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Current_Operating_Time_Read_Operating_Time_Status_DCM_E_PENDING
 *   RTE_E_DataServices_Current_Operating_Time_Read_Operating_Time_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret = E_NOT_OK;

   StbM_TimeStampType timeStamp;
   StbM_UserDataType userData;

   if (NULL_PTR != Data)
   {
       ret = Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(&timeStamp, &userData);

       Data[0] = timeStamp.timeBaseStatus;
   }
   else
   {
       ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_DCM_E_PENDING
 *   RTE_E_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 0138
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0283]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

   return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(c02_Off_On *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_DCM_E_PENDING
 *   RTE_E_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 0138
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0283]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData (returns application error)
 *********************************************************************************************************************/

   c02_Off_On BltSlckDecMD;

   (void)Rte_Read_DiagFunction_R_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(&BltSlckDecMD);

   Data[0] = BltSlckDecMD;

   return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Customer_Settings_Read_PS_Curve_Stat>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Customer_Settings_Read_PS_Curve_Stat_DCM_E_PENDING
 *   RTE_E_DataServices_Customer_Settings_Read_PS_Curve_Stat_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 0138
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0283]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Customer_Settings_Read_PS_Curve_Stat>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(c02_Off_Stage1_Stage2 *data)
 *   Std_ReturnType Rte_Read_R_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3(c02_Off_Stage1_Stage2 *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Customer_Settings_Read_PS_Curve_Stat_DCM_E_PENDING
 *   RTE_E_DataServices_Customer_Settings_Read_PS_Curve_Stat_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 0138
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0283]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData (returns application error)
 *********************************************************************************************************************/

   c02_Off_Stage1_Stage2 PSCurve;

   /*Read needed signals*/
   if (ECU_SIDE_RBTM_FR == NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
   {
      (void)Rte_Read_DiagFunction_R_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3(&PSCurve);
   }
   else
   {
      (void)Rte_Read_DiagFunction_R_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(&PSCurve);
   }

   /*Prepare diagnostic response*/
   Data[0] = PSCurve;

   return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_DCM_E_PENDING
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0x0138 Customer Settings -------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF10D DDS Package Release ------------------------------------------------------------------------------------------------------ */
/**
* \brief
*     DID F10D
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_DCM_E_PENDING
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F10D
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.AppDDSVersion[1];

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_DCM_E_PENDING
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F10D
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_DCM_E_PENDING
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F10D
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.AppDDSVersion[0]; /* 2020 */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_DCM_E_PENDING
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F10D
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_DCM_E_PENDING
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F10D
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.BootDDSVersion[1];

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_DCM_E_PENDING
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F10D
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_DCM_E_PENDING
 *   RTE_E_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F10D
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.BootDDSVersion[0]; /* 2020 */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_CANdela_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xF10D DDS Package Release ------------------------------------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------------- DID 0xEF01 Diagnostic Extract Version ------------------------------------------------------------------------------------------ */
/**
* \brief
*     DID EF01
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_CANdela_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.DiagnosticExtractInformation.CandelaVersion[0], 10u);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_DDM_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_DDM_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.DiagnosticExtractInformation.DiagnosticExtractDDMVersion[0], 10u);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.DiagnosticExtractInformation.DiagnosticExtractVersion.Major;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.DiagnosticExtractInformation.DiagnosticExtractVersion.Minor;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.DiagnosticExtractInformation.DiagnosticExtractVersion.Patch;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data30ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF01
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.DiagnosticExtractInformation.ExportedDiagnosticVersion[0], 30u );
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xEF01 Diagnostic Extract Version ---------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x0102 Diagnostic Trace Memory ------------------------------------------------------------------------------------------------------------ */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data12ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        CodingAppl_Copy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_DiagnosticTraceMemory(), 12U);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data12ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData (returns application error)
 *********************************************************************************************************************/

    /* TO BE IMPLEMENTED: Write in NVM */
    Std_ReturnType retVal = RTE_E_OK;

    if (!Coding_CompareData(Data, Rte_Pim_DiagnosticTraceMemory(), 12U))
    {
        CodingAppl_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_DiagnosticTraceMemory(), Data, 12U);
    }

    *ErrorCode = DCM_E_POSITIVERESPONSE;
    return E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_DCM_E_PENDING
 *   RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0x0102 Diagnostic Trace Memory -------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF103 Dump of Vedoc Relevant Information --------------------------------------------------------------------------------- */
/**
* \brief
*     DID F103
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0285]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data48ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_DCM_E_PENDING
 *   RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F103
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0285]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        /* HW PART NO:(A)1749018500 in ASCII -> decimal */
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.EcuHardwarePartNumber[0],10u);

        /* Constant "0" ASCII */
        Data[10] = '0';

        /* HW Supplier Identification (Hex to ASCII)*/
        DiagCopyVectorToAddress( &Data[11], &DiagCommonData.HardwareSupplierIdentification[0],4u);

        /* ECU Serial Number */
        DiagCopyVectorToAddress( &Data[15], DiagCommonData.EcuSerialNumber, sizeof(NVP_BLOCK_ID_AEE_TRACEABILITY_RamBlockData));
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_DCM_E_PENDING
 *   RTE_E_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F103
* \param
*     DataLength - Size of the diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0285]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 27u;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ECU_Name_Read_Diagnostic_ECU_Name>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xEF00 ECU Extract Version ------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF104 ECU Name ---------------------------------------------------------------------------------------------------------------------- */
/**
* \brief
*     DID F104
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ECU_Name_Read_Diagnostic_ECU_Name>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1000ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F104
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.EcuName[0], 9u);
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_ECU_Name_Read_Diagnostic_ECU_Name>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F104
* \param
*     DataLength - Length of the diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 9U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Global_Time_Sync_Measured_Values_Read_GTSM>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_DCM_E_PENDING
 *   RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Global_Time_Sync_Measured_Values_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Global_Time_Sync_Measured_Values_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Global_Time_Sync_Measured_Values_Read_GTSM>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Global_Time_Sync_Measured_Values_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2613ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_DCM_E_PENDING
 *   RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Global_Time_Sync_Measured_Values_ReadData_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0261, DSG_DIA_MMA_0262]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Global_Time_Sync_Measured_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Global_Time_Sync_Measured_Values_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;
    StbM_SyncRecordTableHeadType TimeRecordingHead = {0, 0, 0};

    if (NULL_PTR != Data)
    {
        ret = E_OK;

        /* Data Count variable */
        int dataCount = 0;

        /* Clear the buffer first, 200 bytes as per CDD file */
        /* MSS 21001-337: All bytes of the data section shall be initialized with the value 172 (= 0xAC). */
        VStdMemSet(Data, 0xAC, 201);

        /*Source Domain Information for Interpretation set to 0xFF*/
        Data[dataCount++] = (uint8)0xFF;

        /* Header Section - 22 bytes */
        /* Measurement data structure type (1 byte). This element shall be set to '2' due to MSS21001 V3 */
        Data[dataCount++] = (uint8)2;

        StbM_GetSyncTimeRecordHead(0, &TimeRecordingHead);

        /* HWfrequency (4 bytes), as obtained from the the StbM (Header element HWfrequency that is obtained via StbM_GetSyncTimeRecordHead) */
        /* 80 Mhz */
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWfrequency >> 24);
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWfrequency >> 16);
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWfrequency >> 8);
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWfrequency);

        /* HWprescalerLo (2 bytes), the two least significant bytes of Header element HWprescaler (that is obtained via StbM_GetSyncTimeRecordHead)*/
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWprescaler >> 8);
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWprescaler);

        /* ECU software version (3 bytes), that shall allow to identify the ECU software version (year/week/patch level): most significant byte: year, lesser significant byte: week, least significant byte: patch level */
        Data[dataCount++] = DiagCommonData.EcuAppSoftwareVersion.Major;
        Data[dataCount++] = DiagCommonData.EcuAppSoftwareVersion.Minor;
        Data[dataCount++] = DiagCommonData.EcuAppSoftwareVersion.Patch;

        /* Version of StbM module (3 bytes) */
        Data[dataCount++] = (uint8)STBM_SW_MAJOR_VERSION;
        Data[dataCount++] = (uint8)STBM_SW_MINOR_VERSION;
        Data[dataCount++] = (uint8)STBM_SW_PATCH_VERSION;

        /* Version of EthTSyn module (3 bytes) */
        Data[dataCount++] = (uint8)0xAC; /* N/A */
        Data[dataCount++] = (uint8)0xAC; /* N/A */
        Data[dataCount++] = (uint8)0xAC; /* N/A */

        /* Version of CanTSyn module (3 bytes) */
        Data[dataCount++] = (uint8)CANTSYN_SW_MAJOR_VERSION;
        Data[dataCount++] = (uint8)CANTSYN_SW_MINOR_VERSION;
        Data[dataCount++] = (uint8)CANTSYN_SW_PATCH_VERSION;

        /* Version of FrTSyn module (3 bytes) */
        Data[dataCount++] = (uint8)0xAC; /* N/A */
        Data[dataCount++] = (uint8)0xAC; /* N/A */
        Data[dataCount++] = (uint8)0xAC; /* N/A */

        /* Data Section */
        /* Index (1 byte) */
        Data[dataCount++] = MeasurementSet_LastIndex;

        /* Check if we have valid data */
        if ((uint8)(MeasurementSets[0].GlbSeconds) != 0xAC)
        {
            /* Block 0 - Type 1     (23 bytes) */
            /* GlbSeconds           (4 bytes) */
            Data[dataCount++] = (uint8)(MeasurementSets[0].GlbSeconds >> 24);
            Data[dataCount++] = (uint8)(MeasurementSets[0].GlbSeconds >> 16);
            Data[dataCount++] = (uint8)(MeasurementSets[0].GlbSeconds >> 8);
            Data[dataCount++] = (uint8)(MeasurementSets[0].GlbSeconds);

            /* GlbNanoSeconds       (4 bytes) */
            Data[dataCount++] = (uint8)(MeasurementSets[0].GlbNanoSeconds >> 24);
            Data[dataCount++] = (uint8)(MeasurementSets[0].GlbNanoSeconds >> 16);
            Data[dataCount++] = (uint8)(MeasurementSets[0].GlbNanoSeconds >> 8);
            Data[dataCount++] = (uint8)(MeasurementSets[0].GlbNanoSeconds);

            /* TimeBaseStatus       (1 byte) */
            Data[dataCount++] = (uint8)(MeasurementSets[0].TimeBaseStatus);

            /* VirtualLocalTimeLow  (4 bytes) */
            Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 24);
            Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 16);
            Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 8);
            Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow);

            /* RateDeviation        (2 bytes) */
            Data[dataCount++] = (uint8)(MeasurementSets[0].RateDeviation >> 8);
            Data[dataCount++] = (uint8)(MeasurementSets[0].RateDeviation);

            /* LocSeconds           (4 bytes) */
            Data[dataCount++] = (uint8)(MeasurementSets[0].LocSeconds >> 24);
            Data[dataCount++] = (uint8)(MeasurementSets[0].LocSeconds >> 16);
            Data[dataCount++] = (uint8)(MeasurementSets[0].LocSeconds >> 8);
            Data[dataCount++] = (uint8)(MeasurementSets[0].LocSeconds);

            /* LocNanoSeconds       (4 bytes) */
            Data[dataCount++] = (uint8)(MeasurementSets[0].LocNanoSeconds >> 24);
            Data[dataCount++] = (uint8)(MeasurementSets[0].LocNanoSeconds >> 16);
            Data[dataCount++] = (uint8)(MeasurementSets[0].LocNanoSeconds >> 8);
            Data[dataCount++] = (uint8)(MeasurementSets[0].LocNanoSeconds);
        }

        /* Block 1-12 - Type 2  (14 bytes) */
        for (int i = 1; i <= 11; i++)
        {
            /* Check if we have valid data */
            if ((uint8)(MeasurementSets[i].GlbSeconds) != 0xAC)
            {

                /* GLSecondsLo          (1 byte)	(Bit 7..4):	Low Nibble of LocSeconds
                                                    (Bit 3..0):	Low Nibble of GlbSeconds */
                Data[dataCount++] = (uint8)(((MeasurementSets[i].LocSeconds & 0x0F) << 4) | (MeasurementSets[i].GlbSeconds & 0x0F));

                /* GNanoSecondsPart     (3 bytes): Bit 29-6 of GlbNanoSeconds */
                Data[dataCount++] = (uint8)(((MeasurementSets[i].GlbNanoSeconds) >> 22));
                Data[dataCount++] = (uint8)(((MeasurementSets[i].GlbNanoSeconds) >> 14));
                Data[dataCount++] = (uint8)(((MeasurementSets[i].GlbNanoSeconds) >> 6));

                /* TimeBaseStatus       (1 byte): TimeBaseStatus */
                Data[dataCount++] = (uint8)(MeasurementSets[i].TimeBaseStatus);

                /* VirtualLocalTimeLow  (4 bytes): HWcounter */
                Data[dataCount++] = (uint8)(MeasurementSets[i].VirtualLocalTimeLow >> 24);
                Data[dataCount++] = (uint8)(MeasurementSets[i].VirtualLocalTimeLow >> 16);
                Data[dataCount++] = (uint8)(MeasurementSets[i].VirtualLocalTimeLow >> 8);
                Data[dataCount++] = (uint8)(MeasurementSets[i].VirtualLocalTimeLow);

                /* RateDeviation        (2 bytes): RateDeviation */
                Data[dataCount++] = (uint8)(MeasurementSets[i].RateDeviation >> 8);
                Data[dataCount++] = (uint8)(MeasurementSets[i].RateDeviation);

                /* LNanoSecondsPart     (3 bytes): Bit 29-6 of LocNanoSeconds */
                Data[dataCount++] = (uint8)(((MeasurementSets[i].LocNanoSeconds) >> 22));
                Data[dataCount++] = (uint8)(((MeasurementSets[i].LocNanoSeconds) >> 14));
                Data[dataCount++] = (uint8)(((MeasurementSets[i].LocNanoSeconds) >> 6));
            }
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Global_Time_Sync_Measured_Values_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Global_Time_Sync_Measured_Values_Read_GTSM>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Global_Time_Sync_Measured_Values_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_DCM_E_PENDING
 *   RTE_E_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Global_Time_Sync_Measured_Values_ReadDataLength_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     DataLength - Size of the Diagnostic Buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0261, DSG_DIA_MMA_0262]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Global_Time_Sync_Measured_Values_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Global_Time_Sync_Measured_Values_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 201U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Partnumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Partnumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData (returns application error)
 *********************************************************************************************************************/
  DiagCopyVectorToAddress( &Data[0], &HSMPartNo[0u],10u);
  /* Read also HSM Version here in order to not call csm in every runnable related to HSM Version */
  uint8 HSM_Version_length;
  Csm_KeyElementGet(CsmConf_CsmKey_Key_Custom_HSM_Version,1u,HSM_Version_au8,&HSM_Version_length);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Partnumber>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0u] = HSM_Version_au8[2u];
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0u] = HSM_Version_au8[1u];
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0u] = HSM_Version_au8[0u];
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0u] = HSM_Version_au8[2u];
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData (returns application error)
 *********************************************************************************************************************/
  Data[0u] = HSM_Version_au8[1u];
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData (returns application error)
 *********************************************************************************************************************/

  Data[0u] = HSM_Version_au8[0u];
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0x0220 HW Input -------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF154 Hardware Supplier Identification ----------------------------------------------------------------------------- */
/**
* \brief
*     DID F154
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F154
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuHardwareSupplierInformation[0];
        Data[1] = DiagCommonData.EcuHardwareSupplierInformation[1];
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HardwareVersion_Read_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HardwareVersion_Read_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_HardwareVersion_Read_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xF154 Hardware Supplier Identification -------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF150 Hardware Version Information ---------------------------------------------------------------- */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HardwareVersion_Read_HW_patch_level_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HardwareVersion_Read_HW_patch_level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HardwareVersion_Read_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HardwareVersion_Read_HW_patch_level_DCM_E_PENDING
 *   RTE_E_DataServices_HardwareVersion_Read_HW_patch_level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_patch_level_ReadData_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0244, DSG_DIA_MMA_0245]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_patch_level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_patch_level_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = NVP_BLOCK_ID_HW_VERSION_RamBlockData.NVP_au8HwVersion[2]; /* Patch level */
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HardwareVersion_Read_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HardwareVersion_Read_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_HardwareVersion_Read_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HardwareVersion_Read_HW_week_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HardwareVersion_Read_HW_week>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HardwareVersion_Read_HW_week_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HardwareVersion_Read_HW_week_DCM_E_PENDING
 *   RTE_E_DataServices_HardwareVersion_Read_HW_week_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_week_ReadData_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0244, DSG_DIA_MMA_0245]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_week_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_week_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = NVP_BLOCK_ID_HW_VERSION_RamBlockData.NVP_au8HwVersion[1]; /* Week */
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_HardwareVersion_Read_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HardwareVersion_Read_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_HardwareVersion_Read_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_HardwareVersion_Read_HW_year_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_HardwareVersion_Read_HW_year>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_HardwareVersion_Read_HW_year_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_HardwareVersion_Read_HW_year_DCM_E_PENDING
 *   RTE_E_DataServices_HardwareVersion_Read_HW_year_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_year_ReadData_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0244, DSG_DIA_MMA_0245]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_HardwareVersion_Read_HW_year_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_HardwareVersion_Read_HW_year_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = NVP_BLOCK_ID_HW_VERSION_RamBlockData.NVP_au8HwVersion[0]; /* Year */
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_DCM_E_PENDING
 *   RTE_E_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0x0240 Internal Ecu Information ----------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF111 Hardware Part Number Daimler Cars & Vans ---------------------------------------------------------------- */
/**
* \brief
*     DID F111
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data10ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_DCM_E_PENDING
 *   RTE_E_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F111
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.EcuHardwarePartNumber[0], 10u);
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_DCM_E_PENDING
 *   RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xF111 Hardware Part Number Daimler Cars & Vans ---------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF121 Software Part Number Daimler Cars & Vans ---------------------------------------------------------- */
/**
* \brief
*     DID F121
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1270ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_DCM_E_PENDING
 *   RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0u], &DiagCommonData.EcuBootSoftwarePartNumber[0u], 10u);
        DiagCopyVectorToAddress( &Data[10u], &DiagCommonData.EcuAppSoftwarePartNumber[0u], 10u);
        DiagCopyVectorToAddress( &Data[20u], &HSMPartNo[0u], 10u);
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_DCM_E_PENDING
 *   RTE_E_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F121
* \param
*     DataLength - Lenght of the diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_MercedesCarGroupHardware_Read_Software_Part_Number_ReadDataLength (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != DataLength)
   {
      *DataLength = 30U;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Minimum_Software_Version_Read_Minimum_Software_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xF121 Software Part Number Daimler Cars & Vans ---------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xEF05 Minimum Software Version ---------------------------------------------------------------------------------------------------------- */
/**
* \brief
*     DID EF05
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Minimum_Software_Version_Read_Minimum_Software_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data381ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF05
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.MinimumSoftwareVersion.Major;
        Data[1] = DiagCommonData.MinimumSoftwareVersion.Minor;
        Data[2] = DiagCommonData.MinimumSoftwareVersion.Patch;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Minimum_Software_Version_Read_Minimum_Software_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF05
* \param
*     DataLength - Length of the diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 3U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_DCM_E_PENDING
 *   RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead_doc
 *********************************************************************************************************************/
/* ------------------------------------------------------------------------------- DID 0x0244 PRE-SAFE Counter ---------------------------------------------------------------------------------------------------- */

/**
* \brief
*     Here write function descriptions.
* \param
*     ErrorCode - Pointer to errorCode
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0025 ]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_DCM_E_PENDING
 *   RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0024, DSG_DIA_MMA_0033 ]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData (returns application error)
 *********************************************************************************************************************/
//NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData
    Std_ReturnType ret = E_NOT_OK;
    uint16 u16CounterRequest = KU16_ZERO;
    uint16 u16CounterLowF = KU16_ZERO;
    uint16 u16CounterHighF = KU16_ZERO;
    uint16 u16CounterMaxF = KU16_ZERO;

    u16CounterRequest = (uint16)NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_ACTIV_REQ_COUNTER_LOC];
    u16CounterLowF = (uint16)NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_LOW_FORCE_COUNTER_LOC];
    u16CounterHighF = (uint16)NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_HIGH_FORCE_COUNTER_LOC];
    u16CounterMaxF = (uint16)NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_MAX_FORCE_COUNTER_LOC];

    if (NULL_PTR != Data)
    {
        Data[KU8_ZERO]	= U16_GET_LOW_BYTE(u16CounterRequest);
        Data[KU8_ONE]	= U16_GET_HIGH_BYTE(u16CounterRequest);
        Data[KU8_TWO]	= U16_GET_LOW_BYTE(u16CounterLowF);
        Data[KU8_THREE]	= U16_GET_HIGH_BYTE(u16CounterLowF);
        Data[KU8_FOUR]	= U16_GET_LOW_BYTE(u16CounterHighF);
        Data[KU8_FIVE]	= U16_GET_HIGH_BYTE(u16CounterHighF);
        Data[KU8_SIX]	= U16_GET_LOW_BYTE(u16CounterMaxF);
        Data[KU8_SEVEN]	= U16_GET_HIGH_BYTE(u16CounterMaxF);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_DCM_E_PENDING
 *   RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     DataLength - Pointer to diagnostic data length
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0026, DSG_DIA_MMA_0034 ]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 8U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_Execution_Counters_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData(const uint8 *Data, uint16 DataLength, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data8ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_DCM_E_PENDING
 *   RTE_E_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0254, DSG_DIA_MMA_0255]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData (returns application error)
 *********************************************************************************************************************/
	NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_COMFORT_COUNTER_LOC] = KU32_ZERO;
	NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_LOW_FORCE_COUNTER_LOC] = KU32_ZERO;
	NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_HIGH_FORCE_COUNTER_LOC] = KU32_ZERO;
	NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_MAX_FORCE_COUNTER_LOC] = KU32_ZERO;
	NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_ACTIV_REQ_COUNTER_LOC] = KU32_ZERO;

    /* Notify NVM of changes in the ram mirror */
    (void)Rte_Call_NvMService_Execution_Counters_SetRamBlockStatus(TRUE);

    return E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_PreCheckProgrammingDependencies_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_PreCheckProgrammingDependencies_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_PreCheckProgrammingDependencies_Start(const uint8 *Pre_Check_Informations, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType *routineInfo, Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType *Dependencies_Verification_Check_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Pre_Check_Informations: uint8* is of type Dcm_StartFlexibleInArrayData_Routine_PreCheckProgrammingDependencies_Start_Pre_Check_InformationsType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PreCheckProgrammingDependencies_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_PreCheckProgrammingDependencies_Start(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Pre_Check_Informations, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Dependencies_Verification_Check_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_PreCheckProgrammingDependencies_Start (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ReadFingerprint_Read_Software_Fingerprint_s>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_DCM_E_PENDING
 *   RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0x0242 PRE-SAFE Recorder 2 --------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF15B Software Fingerprint --------------------------------------------------------------------------------------------- */
/**
* \brief
*     DID F15B
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0279]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ReadFingerprint_Read_Software_Fingerprint_s>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2540ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_DCM_E_PENDING
 *   RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F15B
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0279]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
    /**********************************************************************************************************************
     * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
     * Symbol: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData (returns application error)
     *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

    Rte_Call_NvMService_FblMetaData_GetErrorStatus(&errorStatus);
    if (NVM_REQ_PENDING != errorStatus)
    {
        if (NULL_PTR != Data)
        {
            if (0xFF == DiagFblMetadataFbl.FpStatusInfo)
            {
                DiagFblMetadataFbl.FpStatusInfo = SWHW_SWSW_MISSMATCH;
            }

            if (0xFF == DiagFblMetadataApp.FpStatusInfo)
            {
                DiagFblMetadataApp.FpStatusInfo = SWHW_SWSW_MISSMATCH;
            }

            if (0xFF == DiagFblMetadataHsm.FpStatusInfo)
            {
                DiagFblMetadataHsm.FpStatusInfo = SWHW_SWSW_MISSMATCH;
            }

            Data[0] = DiagFblMetadataFbl.FpStatusInfo;
            DiagCopyVectorToAddress(&Data[1], &DiagFblMetadataFbl.Fingeprint, 19u);

            Data[20] = DiagFblMetadataApp.FpStatusInfo;
            DiagCopyVectorToAddress(&Data[21], &DiagFblMetadataApp.Fingeprint, 19u);

            Data[40] = DiagFblMetadataHsm.FpStatusInfo;
            DiagCopyVectorToAddress(&Data[41], &DiagFblMetadataHsm.Fingeprint, 19u);

            ret = E_OK;
        }
        else
        {
            ret = RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_E_NOT_OK;
        }
    }
    else
    {
        ret = RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_DCM_E_PENDING;
        OpStatus = RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_DCM_E_PENDING;
    }

    return ret;

    /**********************************************************************************************************************
     * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
     *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_ReadFingerprint_Read_Software_Fingerprint_s>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_DCM_E_PENDING
 *   RTE_E_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F15B
* \param
*     DataLength - Length of the diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0279]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 60u;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_DCM_E_PENDING
 *   RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xF15B Software Fingerprint --------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x0100 Reprogramming Attempt Counter ---------------------------------------------------------------------------------------------------- */
/**
* \brief
*     DID 0100
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0270]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

   return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data508ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_DCM_E_PENDING
 *   RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 0100
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0270]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
    /**********************************************************************************************************************
     * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
     * Symbol: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData (returns application error)
     *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;
    uint16 cntValue_u16;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

    Rte_Call_NvMService_FblMetaData_GetErrorStatus(&errorStatus);

    if (NVM_REQ_PENDING != errorStatus)
    {
        if (NULL_PTR != Data)
        {
            /* Compute number of reprogramming attempts for bootloader block */
            cntValue_u16 = FblInvert16Bit(DiagFblMetadataFbl.ProgAttempts);
            Data[1] = (uint8)(cntValue_u16 >> 8);
            Data[0] = (uint8)(cntValue_u16);

            /* Max number of reprogramming attempts */
            Data[2] = 0x00;
            Data[3] = 0x00;

            /* Compute number of reprogramming attempts for application block */
            cntValue_u16 = FblInvert16Bit(DiagFblMetadataApp.ProgAttempts);
            Data[5] = (uint8)(cntValue_u16 >> 8);
            Data[4] = (uint8)(cntValue_u16);

            /* Max number of reprogramming attempts */
            Data[6] = 0x00;
            Data[7] = 0x00;

            /* Compute number of reprogramming attempts for application block */
            cntValue_u16 = FblInvert16Bit(DiagFblMetadataHsm.ProgAttempts);
            Data[9] = (uint8)(cntValue_u16 >> 8);
            Data[8] = (uint8)(cntValue_u16);

            /* Max number of reprogramming attempts */
            Data[10] = 0x00;
            Data[11] = 0x00;

            ret = E_OK;
        }
        else
        {
            ret = RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_E_NOT_OK;
        }
    }
    else
    {
        ret = RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_DCM_E_PENDING;
        OpStatus = RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_DCM_E_PENDING;
    }

    return ret;

    /**********************************************************************************************************************
     * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
     *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_DCM_E_PENDING
 *   RTE_E_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 0100
* \param
*     DataLength - Length of the diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0270]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = DIAG_NR_OF_LOGICAL_BLOCKS * DIAG_SIZE_OF_REPROG_ATTEMPTS;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0x0100 Reprogramming Attempt Counter ---------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF155 Software Supplier Identification ------------------------------------------------------------------------ */
/**
* \brief
*     DID F155
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data254ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F155
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuBootSoftwareSupplierInformation[0];
        Data[1] = DiagCommonData.EcuBootSoftwareSupplierInformation[1];
        Data[2] = DiagCommonData.EcuAppSoftwareSupplierInformation[0];
        Data[3] = DiagCommonData.EcuAppSoftwareSupplierInformation[1];
        Data[4] = DiagCommonData.EcuHsmSoftwareSupplierInformation[0];
        Data[5] = DiagCommonData.EcuHsmSoftwareSupplierInformation[1];
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F155
* \param
*     DataLength - Length of the diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 6U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_DCM_E_PENDING
 *   RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xF155 Software Supplier Identification -------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF151 Software Version Information -------------------------------------------------------------------- */
/**
* \brief
*     DID F151
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0246, DSG_DIA_MMA_0247]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data381ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_DCM_E_PENDING
 *   RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0246, DSG_DIA_MMA_0247]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;
    uint8 HSM_Version_length;

    Csm_KeyElementGet(CsmConf_CsmKey_Key_Custom_HSM_Version,1u,HSM_Version_au8,&HSM_Version_length);

    if (NULL_PTR != Data)
    {
        /* Boot */
        Data[0] = DiagCommonData.EcuBootSoftwareVersion.Major; /* Year */
        Data[1] = DiagCommonData.EcuBootSoftwareVersion.Minor; /* Week */
        Data[2] = DiagCommonData.EcuBootSoftwareVersion.Patch;  /* Patch level */

        /* App */
        Data[3] = DiagCommonData.EcuAppSoftwareVersion.Major; /* Year */
        Data[4] = DiagCommonData.EcuAppSoftwareVersion.Minor; /* Week */
        Data[5] = DiagCommonData.EcuAppSoftwareVersion.Patch;  /* Patch level */        

        /* Hsm */
        Data[6] = HSM_Version_au8[0]; /* Year */
        Data[7] = HSM_Version_au8[1]; /* Week */
        Data[8] = HSM_Version_au8[2];  /* Patch level */
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_DCM_E_PENDING
 *   RTE_E_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     DataLength - Size of the Diagnostic Buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0246, DSG_DIA_MMA_0247]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 9U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.StandardApplicationSWPackageInformation.StandardApplicationAutosarPlatform;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.StandardApplicationSWPackageInformation.StandardApplicationuCIdentification[0], 20u);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.StandardApplicationSWPackageInformation.StandardApplicationSWPackageBuildVersion;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.StandardApplicationSWPackageInformation.StandardApplicationSWPackageVersion.Major;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.StandardApplicationSWPackageInformation.StandardApplicationSWPackageVersion.Minor;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.StandardApplicationSWPackageInformation.StandardApplicationSWPackageVersion.Patch;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_DCM_E_PENDING
 *   RTE_E_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID EF03
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0276]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuAppSoftwareSupplierInformation[0];
        Data[1] = DiagCommonData.EcuAppSoftwareSupplierInformation[1];

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_DCM_E_PENDING
 *   RTE_E_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xEF03 Standard Application SW Package Information --------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF131 Supported Configuration Mechanisms ------------------------------------------------------------------------------------------------- */
/**
* \brief
*     DID F131
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0278]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_DCM_E_PENDING
 *   RTE_E_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID F131
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0278]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x0A;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Synchronize_to_Non_volatile_Memory_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Synchronize_to_Non_volatile_Memory_Start(Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Synchronize_to_Non_volatile_Memory_Start_doc
 *********************************************************************************************************************/
/**
* \brief
*     RID 0281
* \param
*     OpStatus - Operation status
*     routineInfo - Routine Info
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0281]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Synchronize_to_Non_volatile_Memory_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Synchronize_to_Non_volatile_Memory_Start (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_PENDING;
    uint8 RequestResultPtr;

    *routineInfo = DIAGFUNCTION_ROUTINE_STOPPED_WITHOUT_RESULTS;

    if ((OpStatus == DCM_INITIAL) || (OpStatus == DCM_PENDING))
    {

        if(DiagFunction_NvmWriteAll_Status == DIAGFUNCTION_NVM_WRITEALL_STATE_IDLE)
        {
            DiagFunction_WriteAllFlag = DIAGFUNCTION_NVMWRITEALL_FLAG_IDLE;
            DiagFunction_NvmWriteAll_Status = DIAGFUNCTION_NVM_WRITEALL_STATE_START;
        }
        else if ((DiagFunction_NvmWriteAll_Status == DIAGFUNCTION_NVM_WRITEALL_STATE_START) ||
          (DiagFunction_NvmWriteAll_Status == DIAGFUNCTION_NVM_WRITEALL_STATE_PENDING))
        {
                uint8 nvmRetVal;
                nvmRetVal =  NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &RequestResultPtr);

                if ((nvmRetVal == E_OK) && (RequestResultPtr != NVM_REQ_PENDING))
                {
                    if(DiagFunction_NvmWriteAll_Status == DIAGFUNCTION_NVM_WRITEALL_STATE_START)
                    {
                        NvM_WriteAll();

                        DiagFunction_NvmWriteAll_Status = DIAGFUNCTION_NVM_WRITEALL_STATE_PENDING;

                        DiagFunction_WriteAllFlag = DIAGFUNCTION_NVMWRITEALL_FLAG_TRIGGERED;

                    }
                    else /*DIAGFUNCTION_NVM_WRITEALL_STATE_PENDING */
                    {
                        if(RequestResultPtr == NVM_REQ_OK)
                        {
                            /* writing has finished */
                            *routineInfo = DIAGFUNCTION_ROUTINE_COMPLETED_SUCCESSFULLY;
                            DiagFunction_NvmWriteAll_Status = DIAGFUNCTION_NVM_WRITEALL_STATE_IDLE;

                            DiagFunction_WriteAllFlag = DIAGFUNCTION_ROUTINE_COMPLETED_SUCCESSFULLY;
                            retVal = RTE_E_OK;
                        }
                        else
                        {
                            /* Storing the NVM data has failed. */
                            DiagFunction_NvmWriteAll_Status = DIAGFUNCTION_NVM_WRITEALL_STATE_IDLE;
                            retVal = RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_E_NOT_OK;
                            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                        }
                    }
                }
                else if((nvmRetVal == E_OK) && (RequestResultPtr == NVM_REQ_PENDING))
                {
                       *routineInfo = DIAGFUNCTION_ROUTINE_IN_PROGRESS;
                       retVal = RTE_E_OK;
                }
                else
                {
                    /* Storing the NVM data has failed. */
                    DiagFunction_NvmWriteAll_Status = DIAGFUNCTION_NVM_WRITEALL_STATE_IDLE;
                    retVal = RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_E_NOT_OK;
                    *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                }

        }
    }
    else /* OpStatus == DCM_CANCEL */
    {
      /* If NvM_WriteAll has already been called, just ignore the result. Data may have been written or not. */
      DiagFunction_NvmWriteAll_Status = DIAGFUNCTION_NVM_WRITEALL_STATE_IDLE;
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      retVal = RTE_E_OK;
    }

    return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_System_Time_read_Read_System_time_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_System_Time_read_Read_System_time>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_System_Time_read_Read_System_time_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_System_Time_read_Read_System_time_DCM_E_PENDING
 *   RTE_E_DataServices_System_Time_read_Read_System_time_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_System_Time_read_Read_System_time_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0xF131 Supported Configuration Mechanisms ------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x02EA SystemTime ---------------------------------------------------------------------------------------------------- */
/**
* \brief
*     DID 02EA
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0275]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_System_Time_read_Read_System_time_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_System_Time_read_Read_System_time_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_System_Time_read_Read_System_time_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_System_Time_read_Read_System_time>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(StbM_TimeStampType *timeStampPtr, StbM_UserDataType *userDataPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_NOT_OK, RTE_E_GlobalTime_Slave_GTD_BODY3_0_14e64f11_E_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_System_Time_read_Read_System_time_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_System_Time_read_Read_System_time_DCM_E_PENDING
 *   RTE_E_DataServices_System_Time_read_Read_System_time_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_System_Time_read_Read_System_time_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 02EA
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0275]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_System_Time_read_Read_System_time_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_System_Time_read_Read_System_time_ReadData (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;

   StbM_TimeStampType timeStamp;
   StbM_UserDataType userData;

    if (NULL_PTR != Data)
    {
       ret = Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(&timeStamp, &userData);

       Data[3] = DiagConvert2BCD((uint8)timeStamp.seconds);
       Data[2] = DiagConvert2BCD((uint8)(timeStamp.seconds >> 8));
       Data[1] = DiagConvert2BCD((uint8)(timeStamp.seconds >> 16));
       Data[0] = DiagConvert2BCD((uint8)(timeStamp.seconds >> 24));
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_DCM_E_PENDING
 *   RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 01A2
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0293]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data258ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_DCM_E_PENDING
 *   RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 01A2
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0293]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != Data)
   {
      VStdMemCpy(Data, &NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_RamBlockData, sizeof(NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_RamBlockData));
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_DCM_E_PENDING
 *   RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 01A2
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0293]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret = E_NOT_OK;

   if (NULL_PTR != DataLength)
   {  
      VStdMemCpy(u8CSRSupplierSignature, &NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_RamBlockData, sizeof(NVP_BLOCK_ID_CSR_SUPPLIER_SIGNATURE_RamBlockData));
      *DataLength = CSR_SUPPLIER_PUBLIC_KEY_LEADING_BYTES_SIZE + u8CSRSupplierSignature[0] + CSR_SUPPLIER_SIGNATURE_LEADING_BYTES_SIZE + u8CSRSupplierSignature[CSR_SUPPLIER_PUBLIC_KEY_LEADING_BYTES_SIZE + u8CSRSupplierSignature[0]];
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData(const uint8 *Data, uint16 DataLength, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data258ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_DCM_E_PENDING
 *   RTE_E_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 01A2
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0294]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret;
   NvM_RequestResultType errorStatus;
   uint16 u16DataLength = 0;
 
   if (B_FALSE == DIA_bIsNvmQueued)
   {
      if ((Data[0] > (CSR_SUPPLIER_PUBLIC_KEY_SIZE - CSR_SUPPLIER_PUBLIC_KEY_LEADING_BYTES_SIZE)) || (Data[CSR_SUPPLIER_PUBLIC_KEY_LEADING_BYTES_SIZE + Data[0]] > (CSR_SUPPLIER_SIGNATURE_SIZE - CSR_SUPPLIER_SIGNATURE_LEADING_BYTES_SIZE)))
      {
         *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
         ret = E_NOT_OK;
      }
      else
      {
         u16DataLength = CSR_SUPPLIER_PUBLIC_KEY_LEADING_BYTES_SIZE + Data[0] + CSR_SUPPLIER_SIGNATURE_LEADING_BYTES_SIZE + Data[CSR_SUPPLIER_PUBLIC_KEY_LEADING_BYTES_SIZE + Data[0]];

         if (u16DataLength != DataLength)
         {
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
         }
         else
         {
            ret = E_OK;
         }

         if (ret == E_OK)
         {
            VStdMemCpy(&u8CSRSupplierSignature[0], Data, DataLength);

            if (DataLength < CSR_SUPPLIER_SIGNATURE_BLOCK_SIZE)
            {
               VStdMemSet(&u8CSRSupplierSignature[CSR_SUPPLIER_SIGNATURE_BLOCK_SIZE], 0x00, CSR_SUPPLIER_SIGNATURE_BLOCK_SIZE - DataLength);
            }

            ret = Rte_Call_NvMService_CSR_Supplier_Signature_WriteBlock(Data);

            DIA_bIsNvmQueued = B_TRUE;
         }
      }
      
   }
   
   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead_doc
 *********************************************************************************************************************/

/* ------------------------------------------------------------------------------- End of DID 0x02EA SystemTime --------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x010A Vehicle Odometer in Low Resolution ------------------------------------------------------------------------- */
/**
* \brief
*     DID 010A
* \param
*     ErrorCode - Error Code
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0271]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

   return ConditionCheckRead_General(OpStatus, ErrorCode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3(REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh *data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_DCM_E_PENDING
 *   RTE_E_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData_doc
 *********************************************************************************************************************/
/**
* \brief
*     DID 010A
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0271]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret = E_NOT_OK;
   c24_km_0_999999k9_0k1_Invld_SNA odometerValue;
   uint16 odometerValueInLowRes;

   (void)Rte_Read_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3(&odometerValue);

   /* Conversion is least significant 2 bytes of Odometer scaled to 16Km/bit, bus odometer is in 10th of a Km */
   odometerValueInLowRes =  odometerValue / ODOMETER_LOW_RES_CONVERSION;

   if (NULL_PTR != Data)
   {
      Data[0] = odometerValueInLowRes >> 8;
      Data[1] = odometerValueInLowRes;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagFunction_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_FblMetaData_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_FblMetaData_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_FblMetaData_SetDataIndex(uint8 DataIndex)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC3_SRBS_DS_Defs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagFunction_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DiagFunction_CODE) DiagFunction_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagFunction_Init
 *********************************************************************************************************************/

    /*Read application logical block signature (0 - bootlaoder, 1 - application)*/
    Rte_Call_NvMService_FblMetaData_SetDataIndex(KU8_ONE);
    Rte_Call_NvMService_FblMetaData_ReadBlock(&DiagFblMetadataApp);

    /* Set Ecu Name based on ECU Location */
    DiagCopyVectorToAddress(&ecuName, DETECT_ECU_SIDE(NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation), 9u);
    DiagCopyVectorToAddress(&DiagCommonData.EcuExtractInformation.ECUName, DETECT_ECU_SIDE(NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation), 30u);
    DiagCopyVectorToAddress(&DiagCommonData.DiagnosticExtractInformation.ExportedDiagnosticVersion, EXPORTED_DIAG_VARIANT(NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation), 30u);

    /* Set HW part number based on ECU Location */
    DiagCopyVectorToAddress(&DiagCommonData.EcuHardwarePartNumber, HW_PART_NUMBER(NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation), 10u);

    /*Copy SW Version (Appl and BL) from code const and write into general structure*/
    DiagCopyVectorToAddress(&DiagCommonData.EcuAppSoftwareVersion, &stDiag_Appl_SW_Version, sizeof(stDiag_Appl_SW_Version));
    DiagCopyVectorToAddress(&DiagCommonData.EcuBootSoftwareVersion, pDiag_FBL_SW_Version, sizeof(tGeneralVersion));

    /* Init everything with 0xAC */
    VStdMemSet(MeasurementSets, 0xAC, sizeof(MeasurementSets));

    /* initialize NvmWriteAll state & flag*/
    DiagFunction_NvmWriteAll_Status = DIAGFUNCTION_NVM_WRITEALL_STATE_IDLE;
    DiagFunction_WriteAllFlag = DIAGFUNCTION_NVMWRITEALL_FLAG_IDLE;

    /* ROE */
    for(uint8 loopIdx = 0; loopIdx < SWCDIAG_ROELITE_ENTRY_SIZE; loopIdx++)
    {
        SwcDiag_RoEPDUPriority[loopIdx] = SWCDIAG_PRIO_EMPTY;
    }

    SwcDiag_NextPriority = SWCDIAG_PRIO_FIRST_NEXT;
    SwcDiag_RoePDUTimer = SWCDIAG_200MS_IN_MAIN_CYCLES;
    SwcDiag_Status = SWCDIAG_INITIALIZED;

    /*Set Hardware PN based on NVM value and side*/
    if (ECU_SIDE_RBTM_FR == NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
    {
        VStdMemCpy(DiagCommonData.EcuHardwarePartNumber, NVP_BLOCK_ID_HW_PARTNUMBER_RamBlockData.NVP_au8FRHardwarePartnumber, sizeof(DiagCommonData.EcuHardwarePartNumber));
    }
    else
    {
        VStdMemCpy(DiagCommonData.EcuHardwarePartNumber, NVP_BLOCK_ID_HW_PARTNUMBER_RamBlockData.NVP_au8FLHardwarePartnumber, sizeof(DiagCommonData.EcuHardwarePartNumber));
    }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagFunction_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_ROE_ROE_XX_ST3(const REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv *data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_CommunicationModeMSI_Mode(uint8 *previousMode, uint8 *nextMode)
 *   Modes of Rte_ModeType_CommunicationMode:
 *   - RTE_MODE_CommunicationMode_COMM_FULL_COMMUNICATION
 *   - RTE_MODE_CommunicationMode_COMM_NO_COMMUNICATION
 *   - RTE_MODE_CommunicationMode_COMM_SILENT_COMMUNICATION
 *   - RTE_TRANSITION_CommunicationMode
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagFunction_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DiagFunction_CODE) DiagFunction_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagFunction_MainFunction
 *********************************************************************************************************************/
    static boolean isMetaDataRead = FALSE;

    if(SwcDiag_Status == SWCDIAG_INITIALIZED)
    {
        Rte_ModeType_CommunicationMode dummy;
        Rte_ModeType_CommunicationMode commMode = RTE_MODE_CommunicationMode_COMM_NO_COMMUNICATION;
        (void)Rte_Mode_DiagFunction_CommunicationModeMSI_Mode(&dummy, &commMode);             /* VCA_SWCDIAG_EXT_FUNC_CALL_RTE_MODE */

        if(SwcDiag_RoePDUTimer != SWCDIAG_200MS_IN_MAIN_CYCLES)
        {
            SwcDiag_RoePDUTimer++;
        }
        else if (commMode == SWCDIAG_FULL_COMMUNICATION)
        {
            /* this is done here and not at the first if(commMode == FULL_COMMUNICATION) in order to:
                    * 1. Not block the processing of the conditions on sending
                    * 2. Diagnostic session is added to the queue. */
            ProcessRoeQueue();
        }
        else
        {
            /* do nothing */
        }
    }

    if(FALSE == isMetaDataRead)
    {
        isMetaDataRead = DiagReadMetaData();
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagFunction_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SyncTimeRecordBlock> of PortPrototype <StbM_MeasurementNotification_GTD_BODY3_0_14e64f11>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType DiagFunction_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock(const StbM_SyncRecordTableBlockType *syncRecordTableBlock)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_E_NOT_OK
 *   RTE_E_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagFunction_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) DiagFunction_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock(P2CONST(StbM_SyncRecordTableBlockType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) syncRecordTableBlock) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagFunction_StbM_MeasurementNotification_GTD_BODY3_0_14e64f11_SyncTimeRecordBlock (returns application error)
 *********************************************************************************************************************/

    /* fill the buffer */
    MeasurementSets[MeasurementSet_Index] = *syncRecordTableBlock;

    /* store the last index */
    MeasurementSet_LastIndex = MeasurementSet_Index;

    /* we only have 12 measurement sets, reset the index */
    if (MeasurementSet_Index < 11)
    {
        MeasurementSet_Index++;
    }
    else
    {
        MeasurementSet_Index = 0;
    }

    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagFunction_runReadGlobalTime
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadAbsoluteSystemTime> of PortPrototype <pseSystemTime>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void DiagFunction_runReadGlobalTime(stAbsoluteSystemTimeType *pstAbsoluteSystemTime)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagFunction_runReadGlobalTime_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DiagFunction_CODE) DiagFunction_runReadGlobalTime(P2VAR(stAbsoluteSystemTimeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) pstAbsoluteSystemTime) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagFunction_runReadGlobalTime
 *********************************************************************************************************************/

	if ((uint8)(MeasurementSets[0].GlbSeconds) != 0xAC)
	{
		pstAbsoluteSystemTime->u32SystemTimeInSec = MeasurementSets[MeasurementSet_LastIndex].GlbSeconds;
	}
	else
	{
		pstAbsoluteSystemTime->u32SystemTimeInSec = KU32_MAX;
	}

	pstAbsoluteSystemTime->u8SystemTimeOffset = KU8_ZERO;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoELight_DTCStatusChanged_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DTCStatusChanged> of PortPrototype <CallbackDTCStatusChange>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_ROE_ROE_XX_ST3(const REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv *data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_DiagFunction_ExclusiveArea(void)
 *   void Rte_Exit_DiagFunction_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoELight_DTCStatusChanged_Callback(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackDTCStatusChange_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoELight_DTCStatusChanged_Callback_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     DTC
*     DTCStatusOld
*     DTCStatusNew
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0215, DSG_DIA_MMA_0216]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) RoELight_DTCStatusChanged_Callback(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoELight_DTCStatusChanged_Callback (returns application error)
 *********************************************************************************************************************/
    Std_ReturnType returnValue = E_NOT_OK;
    uint8 dtcRoeEntry_au8[SWCDIAG_ROELITE_ENTRY_SIZE];

    if(SwcDiag_Status == SWCDIAG_INITIALIZED)
    {
        returnValue = E_OK;

        /* we first verify that this is not caused by a service 0x14 (Clear DTC) call */
        if((DTCStatusNew & DIAG_NOTCOMPLETEDLASTCLEAR) == 0u)  /* DSWC_0085 */
        {
            if((DTCStatusOld & DIAG_DTC_REPORT_MARSK) != (DTCStatusNew & DIAG_DTC_REPORT_MARSK))
            {
                dtcRoeEntry_au8[0] = 0x01u;/* type = DTC Status change */
                dtcRoeEntry_au8[1] = 0x09u; /* status availability mask = DTC status change */
                dtcRoeEntry_au8[2] = (uint8)(DTC >> 16);
                dtcRoeEntry_au8[3] = (uint8)(DTC >> 8);
                dtcRoeEntry_au8[4] = (uint8)DTC;
                dtcRoeEntry_au8[5] = (uint8)DTCStatusNew;
                dtcRoeEntry_au8[6] = SWCDIAG_ROE_FILL_BYTE;
                dtcRoeEntry_au8[7] = SWCDIAG_ROE_FILL_BYTE;

                QueueDTCRoEEntry(dtcRoeEntry_au8);
            }
        }
    }

  return returnValue;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoELite_AvailabilityDataHandler
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <AvailabilityDataCategory> of PortPrototype <R_AvailabilityDataHandler>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_AvailabilityDataHandler_AvailabilityDataCategory(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_ROE_ROE_XX_ST3(const REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv *data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_DiagFunction_ExclusiveArea(void)
 *   void Rte_Exit_DiagFunction_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoELite_AvailabilityDataHandler_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     Data - Pointer to diagnostic data buffer
*     OpStatus - Operation status
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0259]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DiagFunction_CODE) RoELite_AvailabilityDataHandler(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoELite_AvailabilityDataHandler
 *********************************************************************************************************************/

   uint8 entry[SWCDIAG_ROELITE_ENTRY_SIZE];
   uint8 AvailabilityDataCategory;

   Rte_Read_R_AvailabilityDataHandler_AvailabilityDataCategory(&AvailabilityDataCategory);

   entry[0] = I_C08_ROE_0_AVAILABILITY_DATA;
   entry[1] = 0x00; /* TBD: Function Number (BSR, PRE-SAFE) */
   entry[2] = AvailabilityDataCategory;
   entry[3] = SWCDIAG_ROE_FILL_BYTE;
   entry[4] = SWCDIAG_ROE_FILL_BYTE;
   entry[5] = SWCDIAG_ROE_FILL_BYTE;
   entry[6] = SWCDIAG_ROE_FILL_BYTE;
   entry[7] = SWCDIAG_ROE_FILL_BYTE;

   (void)QueueAvailabilityRoEEntry(entry);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoELite_ObsolescenceDataHandler
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <BlockNumber> of PortPrototype <ObsolescenceDataBlockNumber>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ObsolescenceDataBlockNumber_BlockNumber(UInt8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_P_ROE_ROE_XX_ST3(const REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_If_Obsolescence_Data_Get_Data(const Impl_Obsolescense_Data *pObsData)
 *     Synchronous Server Invocation. Timeout: None
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_DiagFunction_ExclusiveArea(void)
 *   void Rte_Exit_DiagFunction_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoELite_ObsolescenceDataHandler_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     None
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0258]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DiagFunction_CODE) RoELite_ObsolescenceDataHandler(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoELite_ObsolescenceDataHandler
 *********************************************************************************************************************/
    uint8 roe_ObsolescenceDataBlockNumber;
    Impl_Obsolescense_Data roe_ObsolescenceDataValues;
    uint8 entry[SWCDIAG_ROELITE_ENTRY_SIZE];

    Rte_Read_DiagFunction_ObsolescenceDataBlockNumber_BlockNumber(&roe_ObsolescenceDataBlockNumber);
    Rte_Call_If_Obsolescence_Data_Get_Data(&roe_ObsolescenceDataValues);


    if ((roe_ObsolescenceDataBlockNumber == (uint8)0x00) && (roe_ObsolescenceDataValues.BSR.Current_Value == roe_ObsolescenceDataValues.BSR.Threshold_Yellow_to_Red))
    {
        entry[0] = I_C08_ROE_0_OBSOLESCENCE_DATA;
        entry[1] = 0x00; /* BSR */
        entry[2] = (uint8)(roe_ObsolescenceDataValues.BSR.Current_Value >> 8);
        entry[3] = (uint8)roe_ObsolescenceDataValues.BSR.Current_Value;
        entry[4] = (uint8)(roe_ObsolescenceDataValues.BSR.Threshold_Green_to_Yellow >> 8);
        entry[5] = (uint8)roe_ObsolescenceDataValues.BSR.Threshold_Green_to_Yellow;
        entry[6] = (uint8)(roe_ObsolescenceDataValues.BSR.Threshold_Yellow_to_Red >> 8);
        entry[7]= (uint8)roe_ObsolescenceDataValues.BSR.Threshold_Yellow_to_Red;


        (void)QueueCnsmblObslscncRoEEntry(entry);
    }
    else if ((roe_ObsolescenceDataBlockNumber == (uint8)0x01) && (roe_ObsolescenceDataValues.Haptic_Warning.Current_Value == roe_ObsolescenceDataValues.Haptic_Warning.Threshold_Yellow_to_Red))
    {
        entry[0] = I_C08_ROE_0_OBSOLESCENCE_DATA;
        entry[1] = 0x01; /* Haptic Warning */
        entry[2] = (uint8)(roe_ObsolescenceDataValues.Haptic_Warning.Current_Value >> 8);
        entry[3] = (uint8)roe_ObsolescenceDataValues.Haptic_Warning.Current_Value;
        entry[4] = (uint8)(roe_ObsolescenceDataValues.Haptic_Warning.Threshold_Green_to_Yellow >> 8);
        entry[5] = (uint8)roe_ObsolescenceDataValues.Haptic_Warning.Threshold_Green_to_Yellow;
        entry[6] = (uint8)(roe_ObsolescenceDataValues.Haptic_Warning.Threshold_Yellow_to_Red >> 8);
        entry[7] = (uint8)roe_ObsolescenceDataValues.Haptic_Warning.Threshold_Yellow_to_Red;

        (void)QueueCnsmblObslscncRoEEntry(entry);
    }
    else if ((roe_ObsolescenceDataBlockNumber == (uint8)0x02) && (roe_ObsolescenceDataValues.PRE_SAFE_LVL_4_5.Current_Value == roe_ObsolescenceDataValues.PRE_SAFE_LVL_4_5.Threshold_Yellow_to_Red))
    {
        entry[0] = I_C08_ROE_0_OBSOLESCENCE_DATA;
        entry[1] = 0x02; /* Pre-Safe Level 4-5 */
        entry[2] = (uint8)(roe_ObsolescenceDataValues.PRE_SAFE_LVL_4_5.Current_Value >> 8);
        entry[3] = (uint8)roe_ObsolescenceDataValues.PRE_SAFE_LVL_4_5.Current_Value;
        entry[4] = (uint8)(roe_ObsolescenceDataValues.PRE_SAFE_LVL_4_5.Threshold_Green_to_Yellow >> 8);
        entry[5] = (uint8)roe_ObsolescenceDataValues.PRE_SAFE_LVL_4_5.Threshold_Green_to_Yellow;
        entry[6] = (uint8)(roe_ObsolescenceDataValues.PRE_SAFE_LVL_4_5.Threshold_Yellow_to_Red >> 8);
        entry[7] = (uint8)roe_ObsolescenceDataValues.PRE_SAFE_LVL_4_5.Threshold_Yellow_to_Red;

        (void)QueueCnsmblObslscncRoEEntry(entry);
    }
    else if ((roe_ObsolescenceDataBlockNumber == (uint8)0x03) && (roe_ObsolescenceDataValues.PRE_CRASH.Current_Value == roe_ObsolescenceDataValues.PRE_CRASH.Threshold_Yellow_to_Red))
    {
        entry[0] = I_C08_ROE_0_OBSOLESCENCE_DATA;
        entry[1] = 0x03; /* Pre-Crash */
        entry[2] = (uint8)(roe_ObsolescenceDataValues.PRE_CRASH.Current_Value >> 8);
        entry[3] = (uint8)roe_ObsolescenceDataValues.PRE_CRASH.Current_Value;
        entry[4] = (uint8)(roe_ObsolescenceDataValues.PRE_CRASH.Threshold_Green_to_Yellow >> 8);
        entry[5] = (uint8)roe_ObsolescenceDataValues.PRE_CRASH.Threshold_Green_to_Yellow;
        entry[6] = (uint8)(roe_ObsolescenceDataValues.PRE_CRASH.Threshold_Yellow_to_Red >> 8);
        entry[7] = (uint8)roe_ObsolescenceDataValues.PRE_CRASH.Threshold_Yellow_to_Red;

        (void)QueueCnsmblObslscncRoEEntry(entry);
    }
    else
    {
        /* Do nothing */
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


/**********************************************************************************************************************
 *
 * Runnable Entity Name: DiagSessionChangeCallback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RegisterData> of PortPrototype <ConsumableAndObsolescenceDataCSI>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 * 
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   DiagSessionChangeCallback (Dcm_SesCtrlType formerState, Dcm_SesCtrlType newState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *  
 * 
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagSessionChangeCallback_doc
 *********************************************************************************************************************/

/**
* \brief
*     Here write function descriptions.
* \param
*     formerState
*     newState
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0260]
**/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DCM_CALLOUT_CODE) DiagSessionChangeCallback(Dcm_SesCtrlType formerState, Dcm_SesCtrlType newState)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: DiagSessionChangeCallback
 *********************************************************************************************************************/

    if(newState != formerState)
    {
        uint8_least loopIdx;
        Rte_Enter_DiagFunction_ExclusiveArea();
        for (loopIdx = 0; (loopIdx < SWCDIAG_ROELITE_FIFO_SIZE); loopIdx++)
        {
            /* It checks if a previous entry exists in the queue and updates it */
            if ((SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_ROE_KIND_IDX] == SWCDIAG_ROE_DIAGSESSIONCHANGE)
                    && ((SwcDiag_RoEPDUPriority[loopIdx] & SWCDIAG_PRIO_FIRST_NEXT) == SWCDIAG_PRIO_FIRST_NEXT))
            {
                SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_ROE_SESSION_IDX] = newState;
                SwcDiag_RoEPDUPriority[loopIdx] = SwcDiag_NextPriority;
                SwcDiag_NextPriority = SwcDiag_NextPriority + SWCDIAG_PRIO_STEP;
                formerState = newState;
                break;
            }
        }
        Rte_Exit_DiagFunction_ExclusiveArea();
        /* If the session is not queued, then prepare the Entry and queue it */
        if (loopIdx >= SWCDIAG_ROELITE_FIFO_SIZE)
        {
            boolean queued;
            uint8 entry[SWCDIAG_ROELITE_ENTRY_SIZE];

            entry[0] = SWCDIAG_ROE_DIAGSESSIONCHANGE;
            entry[1] = newState;
            entry[2] = SWCDIAG_ROE_FILL_BYTE;
            entry[3] = SWCDIAG_ROE_FILL_BYTE;
            entry[4] = SWCDIAG_ROE_FILL_BYTE;
            entry[5] = SWCDIAG_ROE_FILL_BYTE;
            entry[6] = SWCDIAG_ROE_FILL_BYTE;
            entry[7] = SWCDIAG_ROE_FILL_BYTE;

            queued = QueueRoEEntry(entry);
            if (queued == TRUE)
            {
                formerState = newState;
            }
        }
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoELite_SecureEventNotification
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Data> of PortPrototype <R_Sec_Event_ST3>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_Sec_Event_ST3_Data(c08_UInt_SNA_na *data)
 *     Argument data: c08_UInt_SNA_na* is of type ARR_08_UInt_noSNA_7
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_DiagFunction_ExclusiveArea(void)
 *   void Rte_Exit_DiagFunction_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoELite_SecureEventNotification_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, DiagFunction_CODE) RoELite_SecureEventNotification(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoELite_SecureEventNotification
 *********************************************************************************************************************/

    if (SwcDiag_Status == SWCDIAG_INITIALIZED)
    {
        Std_ReturnType returnValue;
        uint8 entry[SWCDIAG_ROELITE_ENTRY_SIZE];
        ARR_08_UInt_noSNA_7 roe_SecureEventNotification;

        returnValue = Rte_Read_DiagFunction_R_Sec_Event_ST3_Data(roe_SecureEventNotification);

        if(returnValue == E_OK)
        {
            entry[0] = I_C08_ROE_0_SECURITY_EVENT_NOTIFICATION;
            entry[1] = roe_SecureEventNotification[0];
            entry[2] = roe_SecureEventNotification[1];
            entry[3] = roe_SecureEventNotification[2];
            entry[4] = roe_SecureEventNotification[3];
            entry[5] = roe_SecureEventNotification[4];
            entry[6] = roe_SecureEventNotification[5];
            entry[7] = roe_SecureEventNotification[6];

            (void)QueueRoEEntry(entry);
        }
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_Erase_All_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Erase_All_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_Erase_All_Start(Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoType *routineInfo, Dcm_StartDataOut_Routine_Erase_All_Start_StatusType *Status, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Erase_All_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Erase_All_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Erase_All_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_Erase_All_Start_doc
 *********************************************************************************************************************
/**
* \brief
*     Here write function descriptions.
* \param
*
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0292]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) RoutineServices_Routine_Erase_All_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Erase_All_Start_StatusType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_Erase_All_Start (returns application error)
 *********************************************************************************************************************/
  
   /* Erase EXECUTION_COUNTERS Block */
   NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[ERASE_ALL_ARRAY_INDEX_1] = KU32_ZERO;
   NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[ERASE_ALL_ARRAY_INDEX_2] = KU32_ZERO;
   NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[ERASE_ALL_ARRAY_INDEX_3] = KU32_ZERO;
   NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[ERASE_ALL_ARRAY_INDEX_4] = KU32_ZERO;
   NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[ERASE_ALL_ARRAY_INDEX_5] = KU32_ZERO;

   /* Notify NVM of changes in the RAM Mirror */
   (void)Rte_Call_NvMService_Execution_Counters_SetRamBlockStatus(TRUE);

   /* Erase MEASUREMENT_FRAME_12_CONFIG Block */
   NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData.NVP_u32MeasFrame12RAMAddress = KU32_ZERO;
   NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_RamBlockData.NVP_u8BlockSize = KU8_ZERO;

   /* Notify NVM of changes in the RAM Mirror */
   (void)Rte_Call_NvMService_Measurement_Frame_12_Config_SetRamBlockStatus(TRUE);

   /* Erase SYSTEM_CONTEXT_0 Block */
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_3] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_4] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_5] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_6] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_7] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_8] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_9] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_10] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_11] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_0_RamBlockData.SystemContextData0[ERASE_ALL_ARRAY_INDEX_12] = KU8_ZERO;

   /* Notify NVM of changes in the RAM Mirror */
   (void)Rte_Call_NvMService_System_Context_0_SetRamBlockStatus(TRUE);

   /* Erase SYSTEM_CONTEXT_1 Block */
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_3] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_4] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_5] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_6] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_7] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_8] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_9] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_10] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_11] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_1_RamBlockData.SystemContextData1[ERASE_ALL_ARRAY_INDEX_12] = KU8_ZERO;

   /* Notify NVM of changes in the RAM Mirror */
   (void)Rte_Call_NvMService_System_Context_1_SetRamBlockStatus(TRUE);

   /* Erase SYSTEM_CONTEXT_2 Block */
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_3] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_4] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_5] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_6] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_7] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_8] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_9] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_10] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_11] = KU8_ZERO;
   NVP_BLOCK_ID_SYSTEM_CONTEXT_2_RamBlockData.SystemContextData2[ERASE_ALL_ARRAY_INDEX_12] = KU8_ZERO;

   /* Notify NVM of changes in the RAM Mirror */
   (void)Rte_Call_NvMService_System_Context_2_SetRamBlockStatus(TRUE);

   /* Erase PRE_SAFE_RECORDER_1 Block */
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStart[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStart[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStop[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8EcuTemperatureStop[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8LocalVoltageStart[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8LocalVoltageStop[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStart[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStart[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderState[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderState[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStop[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8PreSafeRecorderStop[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_3] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_4] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_5] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_3] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_4] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_5] = KU8_ZERO;

   /* Notify NVM of changes in the RAM Mirror */
   (void)Rte_Call_NvMService_Pre_Safe_Recorder_1_SetRamBlockStatus(TRUE);

   /* Erase PRE_SAFE_RECORDER_2 Block */
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStart[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStart[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStop[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8EcuTemperatureStop[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8LocalVoltageStart[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8LocalVoltageStop[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStart[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStart[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderState[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderState[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStop[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8PreSafeRecorderStop[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_3] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_4] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStart[ERASE_ALL_ARRAY_INDEX_5] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_1] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_2] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_3] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_4] = KU8_ZERO;
   NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_RamBlockData.NVP_au8SystemTimeStop[ERASE_ALL_ARRAY_INDEX_5] = KU8_ZERO;

   /* Notify NVM of changes in the RAM Mirror */
   (void)Rte_Call_NvMService_Pre_Safe_Recorder_2_SetRamBlockStatus(TRUE);

   /* Erase TESTS_PARAM Block */
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32CheckMotorOrderMediumMaxDuration = KU32_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32MotorCurrentMediumMaxDuration = KU32_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32SWThermalProtectionValidationThrs = KU32_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u32SWThermalProtectionDeskillingThrs = KU32_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16OverCurrentProtectionStop = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestLowThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestHighThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorDisconnectedVoltageThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentHighResetTime = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentMediumResetTime = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentMediumResetTime = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinSCMaxDropVoltage = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CheckMotorOrderHighMaxDuration = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentHighMaxDuration = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CheckMotorOrderHighResetTime = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CheckMotorOrderMediumResetTime = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MOSFETinOCMinDropVoltage = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16DelayAfterCycleExecutionOrPOR = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16DelayAfterCycleExecutionOrPOR_UV = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CrankingOffConfirmationDelay = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CrankingOutOfDateDelay = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16CheckMotorOrderResetTime = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorCurrentResetTime = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorSCCurrentThrsMin = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MotorDisengagementMinTemp = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_s16MotorDisengagementMaxPowerOrder = KS16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_s16MotorDisengagementMinPowerOrder = KS16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16MinDiffVoltageToValidateBatterySurvey = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HSSWRegTestInitThreshold = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HSSWRegTestHighThreshold = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HSSWRegTestLowThreshold = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HSSWRegTestDeadTime = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16TemperatureSensorLowThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16TemperatureSensorHighThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_s8MotorSCMaxDutyCycle = KS8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_s8MotorSCMinDutyCycle = KS8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8HSSWRegMaxTries = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8PreliminaryBoosterMaxTries = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToValidateMotorSC = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8MOSFETinOCMaxTries = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16ADCLowVoltageThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16ADCMiddleLowVoltageThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16ADCMiddleHighVoltageThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16ADCHighVoltageThrs = KU16_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8MotorCurrentHighThrs = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8MotorCurrentMediumThrs  = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8CheckMotorOrderHighThrs = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8checkMotorOrderMediumThrs = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8SWThermalProtecDecStep = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToValidateMotorBlocked = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToDeskillMotorBlocked = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToDeskillMotorSC = KU8_ZERO;
   NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u8NbOccurenceToValidateBatteryVoltage = KU8_ZERO;

   /* Notify NVM of changes in the Ram Mirror */
   (void)Rte_Call_NvMService_Tests_Param_SetRamBlockStatus(TRUE);

   /* Erase WARM_RESET Block */
   NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCause = KU32_ZERO;
   NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCounter = KU32_ZERO;

   /* Notify NVM of changes in the Ram Mirror */
   (void)Rte_Call_NvMService_Warm_Reset_SetRamBlockStatus(TRUE);

   DIAGFUNCTION_DUMMY_STATEMENT(OpStatus);

   *ErrorCode = DCM_E_POSITIVERESPONSE;

   *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;

   return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RoutineServices_Routine_Force_External_WDG_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Force_External_WDG_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType RoutineServices_Routine_Force_External_WDG_Start(Dcm_OpStatusType OpStatus, Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoType *routineInfo, Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusType *Status, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Force_External_WDG_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Force_External_WDG_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Force_External_WDG_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_Force_External_WDG_Start_doc
 *********************************************************************************************************************/
/**
* \brief
*     Here write function descriptions.
* \param
*
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0291]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) RoutineServices_Routine_Force_External_WDG_Start(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Status, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RoutineServices_Routine_Force_External_WDG_Start (returns application error)
 *********************************************************************************************************************/
   
   RCM_runLaunchExtWdgTest();

   DIAGFUNCTION_DUMMY_STATEMENT(OpStatus);

   *ErrorCode = DCM_E_POSITIVERESPONSE;

   *routineInfo = KU8_ROUTINE_SUCCESSFULLY_COMPLETED;

   return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution(DataPrimitiveType_uint16 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Snapshot_DataServices_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution (returns application error)
 *********************************************************************************************************************/
   Std_ReturnType ret = E_NOT_OK;
   c24_km_0_999999k9_0k1_Invld_SNA odometerValue;
   uint16 odometerValueInLowRes;

   (void)Rte_Read_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3(&odometerValue);

   /* Conversion is least significant 2 bytes of Odometer scaled to 16Km/bit, bus odometer is in 10th of a Km */
   odometerValueInLowRes =  odometerValue / ODOMETER_LOW_RES_CONVERSION;

   if (NULL_PTR != Data)
   {
      Data[0] = odometerValueInLowRes;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time(DataPrimitiveType_uint32 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0x133_Current_Operating_Time_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time(P2VAR(DataPrimitiveType_uint32, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Snapshot_DataServices_Data_DID_0x133_Current_Operating_Time (returns application error)
 *********************************************************************************************************************/
   Std_ReturnType ret = E_NOT_OK;

   StbM_TimeStampType timeStamp;
   StbM_UserDataType userData;

   if (NULL_PTR != Data)
   {
      ret = Rte_Call_GlobalTime_Slave_GTD_BODY3_0_14e64f11_GetCurrentTime(&timeStamp, &userData);

      /* convert to miliseconds */
      timeStamp.seconds = timeStamp.seconds * 1000u;

      Data[0] = timeStamp.seconds;
      
      }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Snapshot_DataServices_Data_DID_0xfd05_Root_Causes
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <Snapshot_DataServices_Data_DID_0xfd05_Root_Causes>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Snapshot_DataServices_Data_DID_0xfd05_Root_Causes(DataPrimitiveType_uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_Data_DID_0xfd05_Root_Causes_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Snapshot_DataServices_Data_DID_0xfd05_Root_Causes_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) Snapshot_DataServices_Data_DID_0xfd05_Root_Causes(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Snapshot_DataServices_Data_DID_0xfd05_Root_Causes (returns application error)
 *********************************************************************************************************************/

   Std_ReturnType ret = E_NOT_OK;
   uint8 u8AecId;

   (void)Rte_Read_DiagFunction_prrSnapshotData_u8SnapshotAecId(&u8AecId);

   if (NULL_PTR != Data)
   {
      Data[0] = u8AecId;
      ret = E_OK;
   }
   else
   {
      ret = E_NOT_OK;
   }

   return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Synchronize_to_Non_volatile_Memory_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Synchronize_to_Non_volatile_Memory_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Synchronize_to_Non_volatile_Memory_RequestResults_doc
 *********************************************************************************************************************/
/**
* \brief
*     RID 0245
* \param
*     routineInfo - Routine Information
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0281]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) Synchronize_to_Non_volatile_Memory_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Synchronize_to_Non_volatile_Memory_RequestResults (returns application error)
 *********************************************************************************************************************/

  if(DiagFunction_NvmWriteAll_Status == DIAGFUNCTION_NVMWRITEALL_FLAG_TRIGGERED)
  {
       *routineInfo = DIAGFUNCTION_ROUTINE_IN_PROGRESS;
  }
  else if (DiagFunction_WriteAllFlag = DIAGFUNCTION_NVMWRITEALL_FLAG_COMPLETED)
  {
     *routineInfo = DIAGFUNCTION_ROUTINE_COMPLETED_SUCCESSFULLY;
  }
  else
  {
      *routineInfo = DIAGFUNCTION_ROUTINE_STOPPED_WITHOUT_RESULTS;
  }

  DIAGFUNCTION_DUMMY_STATEMENT(OpStatus);
  DIAGFUNCTION_DUMMY_STATEMENT(ErrorCode);

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Synchronize_to_Non_volatile_Memory_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Synchronize_to_Non_volatile_Memory_Stop(Dcm_OpStatusType OpStatus, Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Synchronize_to_Non_volatile_Memory_Stop_doc
 *********************************************************************************************************************/
/**
* \brief
*     RID 0245
* \param
*     routineInfo - Routine Information
*     OpStatus - Operation status
*     ErrorCode - Error Code
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0281]
**/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, DiagFunction_CODE) Synchronize_to_Non_volatile_Memory_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Synchronize_to_Non_volatile_Memory_Stop (returns application error)
 *********************************************************************************************************************/

   uint8 nvmRetVal,RequestResultPtr;

   nvmRetVal =  NvM_GetErrorStatus(NvMConf___MultiBlockRequest, &RequestResultPtr);

   if(RequestResultPtr == NVM_REQ_PENDING)
   {
        /* stopped without results */
       DiagFunction_WriteAllFlag = DIAGFUNCTION_NVMWRITEALL_FLAG_STOPPED_WITHOUT_RESULTS;
   }

   NvM_CancelWriteAll();

   *routineInfo = DIAGFUNCTION_ROUTINE_COMPLETED_SUCCESSFULLY;

   DIAGFUNCTION_DUMMY_STATEMENT(OpStatus);
   DIAGFUNCTION_DUMMY_STATEMENT(ErrorCode);

   return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DiagFunction_STOP_SEC_CODE
#include "DiagFunction_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * QueueRoEEntry()
 *********************************************************************************************************************/
/*!
 * \brief     Queues an RoE entry.
 * \details   Finds an empty place in the buffer and queues the passed entry.
 * \param[in] entry the entry to be queued.
 * \return    TRUE if queuing is successful, FALSE otherwise.
 * \context   TASK
 * \reentrant FALSE
 * \pre       -
 * \trace     DSGN-SwcDiag22958
 *********************************************************************************************************************/
static FUNC(boolean, SWCDIAG_CODE) QueueRoEEntry(CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) entry)
{
    boolean foundFlag = FALSE;
      uint8_least loopIdxNextPrio;
      uint8_least loopIdxSlotEntry;

      /* The if statement inside has a single condition, so the overhead from blocking the critical section for the worst case
      * is arguably better than entering and exiting it 8 times for the worst case.
      */
     Rte_Enter_DiagFunction_ExclusiveArea();
      for (loopIdxNextPrio = 0; (loopIdxNextPrio < SWCDIAG_ROELITE_FIFO_SIZE); loopIdxNextPrio++)
      {
        if (SwcDiag_RoEPDUPriority[loopIdxNextPrio] == SWCDIAG_PRIO_EMPTY)
        {
          SwcDiag_RoEPDUPriority[loopIdxNextPrio] = SWCDIAG_PRIO_BUSY;
          foundFlag = TRUE;
          break;
        }
      }
     Rte_Exit_DiagFunction_ExclusiveArea();
      if (foundFlag == TRUE)
      {
        /* Assign the entry to the first empty slot in queue */
        for (loopIdxSlotEntry = 0; loopIdxSlotEntry < SWCDIAG_ROELITE_ENTRY_SIZE; loopIdxSlotEntry++)
        {
          SwcDiag_RoEPDUQueue[loopIdxNextPrio][loopIdxSlotEntry] = entry[loopIdxSlotEntry];
        }
      Rte_Enter_DiagFunction_ExclusiveArea();
        SwcDiag_RoEPDUPriority[loopIdxNextPrio] = SwcDiag_NextPriority;
        SwcDiag_NextPriority = SwcDiag_NextPriority + SWCDIAG_PRIO_STEP;
      Rte_Exit_DiagFunction_ExclusiveArea();
      }
      return foundFlag;
}

/**********************************************************************************************************************
 * QueueDTCRoEEntry()
 *********************************************************************************************************************/
/*!
 * \brief     Queues a DTC RoE entry.
 * \details   Queues a DTC RoE entry, it also checks if a previous entry for the same DTC exists in the queue
 *            and updates it.
 * \param[in] entry the entry to be queued.
 * \context   TASK
 * \reentrant TRUE for different DTC.
 * \pre       -
 * \trace     DSGN-SwcDiag22949, DSGN-SwcDiag22958
 *********************************************************************************************************************/
static FUNC(void, SWCDIAG_CODE) QueueDTCRoEEntry(CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) entry)
{
  uint8_least loopIdx;

  Rte_Enter_DiagFunction_ExclusiveArea();

  for (loopIdx = 0; (loopIdx < SWCDIAG_ROELITE_FIFO_SIZE); loopIdx++)
  {
    /* It checks if a previous entry for the same DTC exists in the queue and updates it */
    if (((SwcDiag_RoEPDUPriority[loopIdx] & SWCDIAG_PRIO_FIRST_NEXT) == SWCDIAG_PRIO_FIRST_NEXT)
      && (SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_ROE_KIND_IDX] == SWCDIAG_ROE_DTCSTATUSCHANGE)
      && (SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_DTC_1STBYTE_IDX] == entry[SWCDIAG_DTC_1STBYTE_IDX])
      && (SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_DTC_2NDBYTE_IDX] == entry[SWCDIAG_DTC_2NDBYTE_IDX])
      && (SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_DTC_3RDBYTE_IDX] == entry[SWCDIAG_DTC_3RDBYTE_IDX]))
    {
      SwcDiag_RoEPDUPriority[loopIdx] = SwcDiag_NextPriority;
      SwcDiag_NextPriority = SwcDiag_NextPriority + SWCDIAG_PRIO_STEP;
      SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_DTC_STATUSMASK_IDX] = entry[SWCDIAG_DTC_STATUSMASK_IDX];
      break;
    }
  }
  Rte_Exit_DiagFunction_ExclusiveArea();

  /* Otherwise, queues a DTC RoE entry */
  if (loopIdx >= SWCDIAG_ROELITE_FIFO_SIZE)
  {
    (void)QueueRoEEntry(entry);
  }
}

/**********************************************************************************************************************
 * QueueAvailabilityRoEEntry()
 *********************************************************************************************************************/
/*!
 * \brief     Queues an Availability Data RoE entry.
 * \details   Queues a Consumable or Obsolescence Data RoE entry, it also checks if a previous entry for the same
 *            function number block number exists in the queue and updates it.
 * \param[in] entry the entry to be queued.
 * \return    TRUE if queuing is successful, FALSE otherwise.
 * \context   TASK
 * \reentrant TRUE for different function numbers.
 * \config    SWCDIAG_AVAILABILITY_FUNCTIONS is lager than 0 and SWCDIAG_STAR3_SUPPORT is on.
 * \pre       -
 * \trace     DSGN-SwcDiag22951, DSGN-SwcDiag22958
 *********************************************************************************************************************/
static FUNC(boolean, SWCDIAG_CODE) QueueAvailabilityRoEEntry(CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) entry)
{
  boolean foundFlag = FALSE;
  uint8_least loopIdx;

  /* The critical section is around the entire loop and not entered and exited in the loop before and after
  * each test because the overhead from blocking the critical section for the worst case (i.e. looping on all 8
  * values) is arguably better than entering and exiting it 8 times for the worst case.
  */
  Rte_Enter_DiagFunction_ExclusiveArea();
  for (loopIdx = 0; (loopIdx < SWCDIAG_ROELITE_FIFO_SIZE); loopIdx++)
  {
    /* The Kind and function number are tested before the priority because in case of a full queue they are more
    * likely to be false, which is the case where we care most about decreasing the execution time of the code
    * inside the critical section */
    if ((SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_ROE_KIND_IDX] == SWCDIAG_ROE_AVAILABILITY_DATA)
# if (SWCDIAG_AVAILABILITY_FUNCTIONS > 1)
      && (SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_AVAILABILITY_FN_IDX] == entry[SWCDIAG_AVAILABILITY_FN_IDX])
# endif /* SWCDIAG_AVAILABILITY_FUNCTIONS */
      && (((SwcDiag_RoEPDUPriority[loopIdx]) & SWCDIAG_PRIO_FIRST_NEXT) == SWCDIAG_PRIO_FIRST_NEXT))
    {
      SwcDiag_RoEPDUPriority[loopIdx] = SwcDiag_NextPriority;
      SwcDiag_NextPriority = SwcDiag_NextPriority + SWCDIAG_PRIO_STEP;
      SwcDiag_RoEPDUQueue[loopIdx][SWCDIAG_AVAILABILITY_CAT_IDX] = entry[SWCDIAG_AVAILABILITY_CAT_IDX];
      foundFlag = TRUE;
      break;
    }
  }
  Rte_Exit_DiagFunction_ExclusiveArea();
  if (foundFlag == FALSE)
  {
    foundFlag = QueueRoEEntry(entry);
  }
  return foundFlag;
}

/**********************************************************************************************************************
 * QueueCnsmblObslscncRoEEntry()
 *********************************************************************************************************************/
/*!
 * \brief     Queues a Consumable or Obsolescence Data RoE entry.
 * \details   Queues a Consumable or Obsolescence Data RoE entry, it also checks if a previous entry for the same
 *            type and block number exists in the queue and updates it.
 * \param[in] entry the entry to be queued.
 * \return    TRUE if queuing is successful, FALSE otherwise.
 * \context   TASK
 * \reentrant TRUE for different block numbers of equal kind.
 * \config    SWCDIAG_CONSUMABLE_IF_ENABLED is on and SWCDIAG_STAR3_SUPPORT is on.
 * \pre       -
 * \trace     DSGN-SwcDiag22953, DSGN-SwcDiag22958
 *********************************************************************************************************************/
static FUNC(boolean, SWCDIAG_CODE) QueueCnsmblObslscncRoEEntry(CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) entry)
{
  boolean foundFlag = FALSE;
  uint8_least loopIdxNextPrio;
  uint8_least loopIdxSlotEntry;

  /* The first Critical section is around the entire loop and not entered and exited in the loop before and after
  * each test because the overhead from blocking the critical section for the worst case (i.e. looping on all 8
  * values) is arguably better than entering and exiting it 8 times for the worst case.
  */
  Rte_Enter_DiagFunction_ExclusiveArea();
  for (loopIdxNextPrio = 0; (loopIdxNextPrio < SWCDIAG_ROELITE_FIFO_SIZE); loopIdxNextPrio++)
  {
    if ((SwcDiag_RoEPDUQueue[loopIdxNextPrio][SWCDIAG_ROE_KIND_IDX] == entry[SWCDIAG_ROE_KIND_IDX])
      && (SwcDiag_RoEPDUQueue[loopIdxNextPrio][SWCDIAG_CONSUMABLE_BLOCK_IDX] == entry[SWCDIAG_CONSUMABLE_BLOCK_IDX])
      && (((SwcDiag_RoEPDUPriority[loopIdxNextPrio]) & SWCDIAG_PRIO_FIRST_NEXT) == SWCDIAG_PRIO_FIRST_NEXT))
    {
      SwcDiag_RoEPDUPriority[loopIdxNextPrio] = SWCDIAG_PRIO_BUSY;
      foundFlag = TRUE;
      break;
    }
  }
  Rte_Exit_DiagFunction_ExclusiveArea();

  if (foundFlag == TRUE)
  {
    /* If found flag is set, it means that a match entry has been found in the queue and should be updated */
    for (loopIdxSlotEntry = SWCDIAG_CONSUMABLE_REPLACE_IDX; loopIdxSlotEntry < SWCDIAG_ROELITE_ENTRY_SIZE; loopIdxSlotEntry++)
    {
      SwcDiag_RoEPDUQueue[loopIdxNextPrio][loopIdxSlotEntry] = entry[loopIdxSlotEntry];
    }
    Rte_Enter_DiagFunction_ExclusiveArea();
    SwcDiag_RoEPDUPriority[loopIdxNextPrio] = SwcDiag_NextPriority;
    SwcDiag_NextPriority = SwcDiag_NextPriority + SWCDIAG_PRIO_STEP;
    Rte_Exit_DiagFunction_ExclusiveArea();
  }

  else
  {
    /* Otherwise, queues a Consumable or Obsolescence Data RoE entry */
    foundFlag = QueueRoEEntry(entry);
  }
  return foundFlag;
}

/**********************************************************************************************************************
 * ProcessRoeQueue()
 *********************************************************************************************************************/
/*!
 * \brief     Sends the first-in RoE Entry.
 * \details   Sends the first-in RoE Entry and dequeues it and resets #SwcDiag_RoePDUTimer if it was successfully sent.
 * \context   TASK
 * \reentrant FALSE
 * \pre       communication is on, and enough time has passed since the last sending.
 * \trace     DSGN-SwcDiag22958
 *********************************************************************************************************************/
static FUNC(void, SWCDIAG_CODE) ProcessRoeQueue(void)
{
    uint8_least loopIdx;
    uint8_least oldestIdx = 0;
    uint16_least oldestPrio = 0;
    /* initialized to FALSE to check if there is any entry to send */
    boolean oldestPrioInitialized = FALSE;

    Rte_Enter_DiagFunction_ExclusiveArea();
    for (loopIdx = 0; loopIdx < SWCDIAG_ROELITE_FIFO_SIZE; loopIdx++)
    {
        if ((SwcDiag_RoEPDUPriority[loopIdx] & SWCDIAG_PRIO_FIRST_NEXT) == SWCDIAG_PRIO_FIRST_NEXT)
        {
            if ((oldestPrioInitialized != TRUE)
                    ||((oldestPrio > SwcDiag_RoEPDUPriority[loopIdx]) && ((uint16)(oldestPrio - SwcDiag_RoEPDUPriority[loopIdx]) < SWCDIAG_PRIO_OVFL_THRESHOLD)))
            {
                /* the second condition is to handle the case of overflow of the priority, if the difference is too big
            * (bigger than half of the range of data type) it's detected as an overflow and in that case the bigger
            * value will be considered the older one */
                oldestPrio = SwcDiag_RoEPDUPriority[loopIdx];
                oldestIdx = loopIdx;
                oldestPrioInitialized = TRUE;
            }
        }
    }
    if (oldestPrioInitialized == TRUE)
    {
        /* set the entry to busy so that it's not processed in other contexts */
        SwcDiag_RoEPDUPriority[oldestIdx] = SWCDIAG_PRIO_BUSY;                           /* VCA_SWCDIAG_ROE_PDU_PRIO_WRITE */
    }

    Rte_Exit_DiagFunction_ExclusiveArea();

    if (oldestPrioInitialized == TRUE)
    {
        Std_ReturnType returnValue;
        SwcDiag_RoERecordType sentRecord;
        sentRecord.ROE_0 = SwcDiag_RoEPDUQueue[oldestIdx][0];
        sentRecord.ROE_1 = SwcDiag_RoEPDUQueue[oldestIdx][1];
        sentRecord.ROE_2 = SwcDiag_RoEPDUQueue[oldestIdx][2];
        sentRecord.ROE_3 = SwcDiag_RoEPDUQueue[oldestIdx][3];
        sentRecord.ROE_4 = SwcDiag_RoEPDUQueue[oldestIdx][4];
        sentRecord.ROE_5 = SwcDiag_RoEPDUQueue[oldestIdx][5];
        sentRecord.ROE_6 = SwcDiag_RoEPDUQueue[oldestIdx][6];
        sentRecord.ROE_7 = SwcDiag_RoEPDUQueue[oldestIdx][7];

        returnValue = Rte_Write_DiagFunction_P_ROE_ROE_XX_ST3(&sentRecord);

        if (returnValue == E_OK)
        {
            /* Set the priority to empty if sending the saved entry was successful */
            SwcDiag_RoEPDUPriority[oldestIdx] = SWCDIAG_PRIO_EMPTY;                         /* VCA_SWCDIAG_ROE_PDU_PRIO_WRITE */
            /* we start the timer at 1 because we count from 1 to SWCDIAG_200MS_IN_MAIN_CYCLES */
            SwcDiag_RoePDUTimer = 1u;
        }
        else
        {
            /* sending not successful, revert the priority to its original value */
            SwcDiag_RoEPDUPriority[oldestIdx] = (uint16)oldestPrio;                          /* VCA_SWCDIAG_ROE_PDU_PRIO_WRITE */
        }
    }
}

static FUNC(Std_ReturnType, DiagFunction_CODE) ConditionCheckRead_General(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) ErrorCode)
{
    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != ErrorCode)
    {
        *ErrorCode = DCM_E_POSITIVERESPONSE;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}

/*Static function used to copy vectors to an address*/
static void DiagCopyVectorToAddress(uint8 * destination, uint8 * source, uint8 size)
{
   uint8 i;
   
   if((NULL_PTR != destination) && (NULL_PTR != source))
   {
        for(i = 0; i < size; i++)
        {
            destination[i]=source[i];
        }
   }
}

/* Static function used to convert from hex to BCD */
static uint8 DiagConvert2BCD(uint8 hexData)
{
    uint8 bcdHigh, bcdLow, bcdData = 0;

    bcdHigh = hexData / 10;
    bcdLow = hexData % 10;
    bcdData = (bcdHigh << 4) + bcdLow;

    return bcdData;
}

/* static function used to erase the dflash */
static uint32 dflash_erase(uint32 addr, uint32 cnt)
{
    if (!cnt)
        return 1u; /* Stop operation if no sector */

    /* Erase sector */
    *(volatile uint32 *)(0xAF00AA50) = (uint32) addr;
    *(volatile uint32 *)(0xAF00AA58) = (uint32) cnt;
    *(volatile uint32 *)(0xAF00AAA8) = (uint32) 0x80;
    *(volatile uint32 *)(0xAF00AAA8) = (uint32) 0x50;
    __dsync();

    return  0u;
}

/* static function used to program the dflash */
static uint32 dflash_program(uint32 addr, uint32* pmem)
{
    volatile uint32 i;
    volatile uint32 low32bit, high32bit;

    /* Enter page mode */
    *(volatile uint32 *)(0xAF005554) = 0x5D;
    __dsync();

    if ( ((DMU_HF_STATUS.U & 0x00100000) == 0) || ((DMU_HF_ERRSR.U & 0x07) != 0) )
        return 1u; /* Stop operation if error */

    if(UCB_DBG_Do_en == UCB_DBG_Lock_e)
    {
        i = 0;
        while (i < 0x8) /* Load page */
        {
            low32bit = pmem[i];
            high32bit = pmem[i + 1];
            *(volatile uint32 *)(0xAF0055F0) = low32bit;
            __dsync();
            *(volatile uint32 *)(0xAF0055F4) = high32bit;
            __dsync();
            i += 2;
        }
        /* Write burst */
        *(volatile uint32 *)(0xAF00AA50) = (uint32) addr;
        *(volatile uint32 *)(0xAF00AA58) = (uint32) 0x00;
        *(volatile uint32 *)(0xAF00AAA8) = (uint32) 0xA0;
        *(volatile uint32 *)(0xAF00AAA8) = (uint32) 0xA6;
        __dsync();
    }
    else if(UCB_DBG_Do_en == UCB_DBG_Unlock_e)
    {
        /* Load page */
        low32bit = pmem[0];
        high32bit = pmem[1];
        *(volatile uint32 *)(0xAF0055F0) = low32bit;
        __dsync();
        *(volatile uint32 *)(0xAF0055F4) = high32bit;
        __dsync();

        /* Write page */
        *(volatile uint32 *)(0xAF00AA50) = (uint32) addr;
        *(volatile uint32 *)(0xAF00AA58) = (uint32) 0x00;
        *(volatile uint32 *)(0xAF00AAA8) = (uint32) 0xA0;
        *(volatile uint32 *)(0xAF00AAA8) = (uint32) 0xAA;
        __dsync();
    }
    else
    {

    }

 return 0u;
}

static boolean DiagReadMetaData()
{
    static boolean allMetaDataRead = FALSE, fblMetaDataRead = FALSE;
    boolean jobOngoing = FALSE;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

    Rte_Call_NvMService_FblMetaData_GetErrorStatus(&errorStatus);
    if (NVM_REQ_PENDING != errorStatus)
    {
        if (FALSE == fblMetaDataRead)
        {
            Rte_Call_NvMService_FblMetaData_SetDataIndex(KU8_ZERO);
            Rte_Call_NvMService_FblMetaData_ReadBlock(&DiagFblMetadataFbl);
            fblMetaDataRead = TRUE;
            jobOngoing = TRUE;
        }

        if ((FALSE == allMetaDataRead) && (jobOngoing == FALSE))
        {
            Rte_Call_NvMService_FblMetaData_SetDataIndex(KU8_TWO);
            Rte_Call_NvMService_FblMetaData_ReadBlock(&DiagFblMetadataHsm);
            allMetaDataRead = TRUE;
        }
    }
    return allMetaDataRead;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0xF10B ECU Configuration --------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xEF00 ECU Extract Version ----------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != ErrorCode)
    {
        /* Identification Type; constant 0x00 */
        Data[0] = 0x00;

        /* Copy XDIS version*/
        DiagCopyVectorToAddress( &Data[1], &DiagCommonData.EcuExtractInformation.XDISVersion[0], 10u);
        
        /* Copy Generation Time*/
        DiagCopyVectorToAddress( &Data[11], &DiagCommonData.EcuExtractInformation.GenerationTime[0], 10u);
        
        /* Copy ECUName*/
        DiagCopyVectorToAddress( &Data[21], &DiagCommonData.EcuExtractInformation.ECUName[0], 30u);
    
        /* Copy checksum */
        VStdMemSet( &Data[51], 0, 200u);
 
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0], DiagCommonData.EcuSerialNumber, sizeof(DiagCommonData.EcuSerialNumber));
        VStdMemSet (&Data[12], 0, 21);
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        DiagCopyVectorToAddress( &Data[0], DiagCommonData.UniqueSeatbeltSerialNumber, sizeof(DiagCommonData.UniqueSeatbeltSerialNumber));
        VStdMemSet (&Data[13], 0, 15);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0xF103 Dump of Vedoc Relevant Information --------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF18C Ecu Serial Number Data Identifier ------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ReadDataLength)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 33U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ReadDataLength_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0xF130 Reprogramming capabilities --------------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x0340 SeatBelt Serial Number ---------------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Get_Certificate_Entry_Start)  *******/

  return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Get_Certificate_Entry_Start_doc)  ********/


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_MajorVersion_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuExtractInformation.Version.Major; /* Major */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Reprogramming_capabilities_Read_DeltaUpdateSupport_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_Block_ReadDataLength_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_MajorVersion_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Reprogramming_capabilities_Read_DeltaAlgorithm_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Availability_Data_Read_Availability_Data_of_System_or_Function_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_Block_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0xFF;
        Data[1] = 0xFF;
        Data[2] = 0x00;
        Data[3] = 0x00;
        Data[4] = 0x00;
        Data[5] = 0x00;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Consumable_Data_Read_Consumable_Data_Block_ReadDataLength)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 6U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_PatchVersion_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Consumable_Data_Read_Consumable_Data_Block_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End RID 0x0203 Check Reprogramming Preconditions  -------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x0141 Consumable Data --------------------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        /* Identification Type; constant 0x00 */
        Data[0] = 0x00;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_Block_ReadDataLength)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 6U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_CANoutput2_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        /* Copy Export Date*/
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.EcuExtractInformation.ExportDate[0], 10u);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Reprogramming_capabilities_Read_OFR_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Reprogramming_capabilities_Read_OFR_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* OFR Not supported */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_input_Read_Neues_Bitfeld_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_ECU_Name_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_MinorVersion_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_MinorVersion_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Reprogramming_capabilities_Read_DeltaUpdateSupport_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* Update not supported */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Reprogramming_capabilities_Read_DeltaAlgorithm_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        /* Copy checksum */
        VStdMemSet( &Data[0], 0, 200u);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_MinorVersion_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Availability_Data_Read_Availability_Data_of_System_or_Function_ReadDataLength)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 1U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        /* Copy XDIS version*/
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.EcuExtractInformation.XDISVersion[0], 10u);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Reprogramming_capabilities_Read_OFR_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_MajorVersion_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_MinorVersion_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuExtractInformation.Version.Minor; /* Minor */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Reprogramming_capabilities_Read_DeltaUpdateSupport_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Consumable_Data_Read_Consumable_Data_Block_ReadDataLength_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_ECU_Name_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        /* Copy ECUName*/
        DiagCopyVectorToAddress( &Data[0], &DiagCommonData.EcuExtractInformation.ECUName[0], 30u);

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_CANoutput2_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Availability_Data_Read_Availability_Data_of_System_or_Function_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0x010B Adjust ISO 15765-2 BS and STmin Parameter --------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ConditioCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0xF10B ECU Configuration --------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xEF00 ECU Extract Version ----------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Consumable_Data_Read_Consumable_Data_Block_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Availability_Data_Read_Availability_Data_of_System_or_Function_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_ECU_Name_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Reprogramming_capabilities_Read_DeltaUpdateSupport_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Availability_Data_Read_Availability_Data_of_System_or_Function_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Reprogramming_capabilities_Read_DeltaAlgorithm_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0x0120 Reprogramming Resume Information -------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0xF130 Reprogramming capabilities ----------------------------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ConditioCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_PatchVersion_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_CANoutput2_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_Block_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_PatchVersion_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = DiagCommonData.EcuExtractInformation.Version.Patch; /* Patch */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Reprogramming_capabilities_Read_DeltaAlgorithm_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0X4E;  /* N */
        Data[1] = 0x6F;  /* o */
        Data[2] = 0x20;  /*   */
        Data[3] = 0x44;  /* D */
        Data[4] = 0x65;  /* e */
        Data[5] = 0x6C;  /* l */
        Data[6] = 0x74;  /* t */
        Data[7] = 0x61;  /* a */
        Data[8] = 0x20;  /*   */
        Data[9] = 0x41;  /* A */
        Data[10] = 0x6C; /* l */
        Data[11] = 0x67; /* g */
        Data[12] = 0x6F; /* o */
        Data[13] = 0x72; /* r */
        Data[14] = 0x69; /* i */
        Data[15] = 0x74; /* t */
        Data[16] = 0x68; /* h */
        Data[17] = 0x6D; /* m */
        Data[18] = 0x20; /*   */
        Data[19] = 0x49; /* I */
        Data[20] = 0x6D; /* m */
        Data[21] = 0x70; /* p */
        Data[22] = 0x6C; /* l */
        Data[23] = 0x65; /* e */
        Data[24] = 0x6D; /* m */
        Data[25] = 0x65; /* e */
        Data[26] = 0x6E; /* n */
        Data[27] = 0x74; /* t */
        Data[28] = 0x65; /* e */
        Data[29] = 0x64; /* d */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_Block_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0xEF05 Minimum Software Version ------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x0140 Obsolescence Data  -------------------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Consumable_Data_Read_Consumable_Data_Block_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Consumable_Data_Read_Consumable_Data_Block_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00;
        Data[1] = 0x01;
        Data[2] = 0x02;
        Data[3] = 0x03;
        Data[4] = 0x04;
        Data[5] = 0x05;
        Data[6] = 0x06;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Availability_Data_Read_Availability_Data_of_System_or_Function_ReadDataLength_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_CANoutput2_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_input_Read_Neues_Bitfeld_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_ECU_Name_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_PatchVersion_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_Block_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_MajorVersion_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_input_Read_Neues_Bitfeld_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_input_Read_Neues_Bitfeld_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Reprogramming_capabilities_Read_OFR_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Global_Time_Sync_Measured_Values_Read_Source_Domain_Information_for_Interpretation_ConditionCheckRead_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Global_Time_Sync_Measured_Values_Read_Global_Time_Sync_Measured_Values_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0xF104 ECU Name ----------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x0107 Global Time Sync Measured Values ------------------------------------------------------------------------------------------------ */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Global_Time_Sync_Measured_Values_Read_Global_Time_Sync_Measured_Values_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Global_Time_Sync_Measured_Values_Read_Source_Domain_Information_for_Interpretation_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Global_Time_Sync_Measured_Values_Read_Source_Domain_Information_for_Interpretation_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Global_Time_Sync_Measured_Values_Read_Global_Time_Sync_Measured_Values_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;
    StbM_SyncRecordTableHeadType TimeRecordingHead = {0, 0, 0};

    if (NULL_PTR != Data)
    {
        ret = E_OK;

        /* Data Count variable */
        int dataCount = 0;

        /* Clear the buffer first, 200 bytes as per CDD file */
        /* MSS 21001-337: All bytes of the data section shall be initialized with the value 172 (= 0xAC). */
        // VStdMemSet(Data, 0xAC, 200);

        /* Header Section - 22 bytes */
        /* Measurement data structure type (1 byte). This element shall be set to '2' due to MSS21001 V3 */
        Data[dataCount++] = 2;

        StbM_GetSyncTimeRecordHead(0, &TimeRecordingHead);

        /* HWfrequency (4 bytes), as obtained from the the StbM (Header element HWfrequency that is obtained via StbM_GetSyncTimeRecordHead) */
        /* 80 Mhz */
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWfrequency >> 24);
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWfrequency >> 16);
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWfrequency >> 8);
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWfrequency);

        /* HWprescalerLo (2 bytes), the two least significant bytes of Header element HWprescaler (that is obtained via StbM_GetSyncTimeRecordHead)*/
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWprescaler >> 8);
        Data[dataCount++] = (uint8)(TimeRecordingHead.HWprescaler);

        /* ECU software version (3 bytes), that shall allow to identify the ECU software version (year/week/patch level): most significant byte: year, lesser significant byte: week, least significant byte: patch level */
        Data[dataCount++] = DiagCommonData.EcuAppSoftwareVersion.Major;
        Data[dataCount++] = DiagCommonData.EcuAppSoftwareVersion.Minor;
        Data[dataCount++] = DiagCommonData.EcuAppSoftwareVersion.Patch;

        /* Version of StbM module (3 bytes) */
        Data[dataCount++] = STBM_SW_MAJOR_VERSION;
        Data[dataCount++] = STBM_SW_MINOR_VERSION;
        Data[dataCount++] = STBM_SW_PATCH_VERSION;

        /* Version of EthTSyn module (3 bytes) */
        Data[dataCount++] = 0xAC; /* N/A */
        Data[dataCount++] = 0xAC; /* N/A */
        Data[dataCount++] = 0xAC; /* N/A */

        /* Version of CanTSyn module (3 bytes) */
        Data[dataCount++] = CANTSYN_SW_MAJOR_VERSION;
        Data[dataCount++] = CANTSYN_SW_MINOR_VERSION;
        Data[dataCount++] = CANTSYN_SW_PATCH_VERSION;

        /* Version of FrTSyn module (3 bytes) */
        Data[dataCount++] = 0xAC; /* N/A */
        Data[dataCount++] = 0xAC; /* N/A */
        Data[dataCount++] = 0xAC; /* N/A */

        /* Data Section */
        /* Index (1 byte) */
        Data[dataCount++] = MeasurementSet_LastIndex;

        /* Block 0 - Type 1     (23 bytes) */
        /* GlbSeconds           (4 bytes) */
        Data[dataCount++] = (uint8)(MeasurementSets[0].GlbSeconds >> 24);
        Data[dataCount++] = (uint8)(MeasurementSets[0].GlbSeconds >> 16);
        Data[dataCount++] = (uint8)(MeasurementSets[0].GlbSeconds >> 8);
        Data[dataCount++] = (uint8)(MeasurementSets[0].GlbSeconds);

        /* GlbNanoSeconds       (4 bytes) */
        Data[dataCount++] = (uint8)(MeasurementSets[0].GlbNanoSeconds >> 24);
        Data[dataCount++] = (uint8)(MeasurementSets[0].GlbNanoSeconds >> 16);
        Data[dataCount++] = (uint8)(MeasurementSets[0].GlbNanoSeconds >> 8);
        Data[dataCount++] = (uint8)(MeasurementSets[0].GlbNanoSeconds);

        /* TimeBaseStatus       (1 byte) */
        Data[dataCount++] = (uint8)(MeasurementSets[0].TimeBaseStatus);

        /* VirtualLocalTimeLow  (4 bytes) */
        Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 24);
        Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 16);
        Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 8);
        Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow);

        /* RateDeviation        (2 bytes) */
        Data[dataCount++] = (uint8)(MeasurementSets[0].RateDeviation >> 8);
        Data[dataCount++] = (uint8)(MeasurementSets[0].RateDeviation);

        /* LocSeconds           (4 bytes) */
        Data[dataCount++] = (uint8)(MeasurementSets[0].LocSeconds >> 24);
        Data[dataCount++] = (uint8)(MeasurementSets[0].LocSeconds >> 16);
        Data[dataCount++] = (uint8)(MeasurementSets[0].LocSeconds >> 8);
        Data[dataCount++] = (uint8)(MeasurementSets[0].LocSeconds);

        /* LocNanoSeconds       (4 bytes) */
        Data[dataCount++] = (uint8)(MeasurementSets[0].LocNanoSeconds >> 24);
        Data[dataCount++] = (uint8)(MeasurementSets[0].LocNanoSeconds >> 16);
        Data[dataCount++] = (uint8)(MeasurementSets[0].LocNanoSeconds >> 8);
        Data[dataCount++] = (uint8)(MeasurementSets[0].LocNanoSeconds);

        /* Block 1-12 - Type 2  (14 bytes) */
        for (int i=1; i <= 11; i++)
        {
            /* GLSecondsLo          (1 byte)	(Bit 7..4):	Low Nibble of LocSeconds
			                                    (Bit 3..0):	Low Nibble of GlbSeconds */
            Data[dataCount++] = (uint8)((MeasurementSets[i].LocSeconds & 0xF0) | (MeasurementSets[i].GlbSeconds & 0x0F));

            /* GNanoSecondsPart     (3 bytes): Bit 29-6 of GlbNanoSeconds */
            Data[dataCount++] = (uint8)(((MeasurementSets[i].GlbNanoSeconds) >> 22));
            Data[dataCount++] = (uint8)(((MeasurementSets[i].GlbNanoSeconds) >> 14));
            Data[dataCount++] = (uint8)(((MeasurementSets[i].GlbNanoSeconds) >> 6));

            /* TimeBaseStatus       (1 byte): TimeBaseStatus */
            Data[dataCount++] = (uint8)(MeasurementSets[i].TimeBaseStatus);

            /* VirtualLocalTimeLow  (4 bytes): HWcounter */
            Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 24);
            Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 16);
            Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow >> 8);
            Data[dataCount++] = (uint8)(MeasurementSets[0].VirtualLocalTimeLow);

            /* RateDeviation        (2 bytes): RateDeviation */
            Data[dataCount++] = (uint8)(MeasurementSets[0].RateDeviation >> 8);
            Data[dataCount++] = (uint8)(MeasurementSets[0].RateDeviation);

            /* LNanoSecondsPart     (3 bytes): Bit 29-6 of LocNanoSeconds */
            Data[dataCount++] = (uint8)(((MeasurementSets[i].LocNanoSeconds) >> 22));
            Data[dataCount++] = (uint8)(((MeasurementSets[i].LocNanoSeconds) >> 14));
            Data[dataCount++] = (uint8)(((MeasurementSets[i].LocNanoSeconds) >> 6));
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Global_Time_Sync_Measured_Values_Read_Source_Domain_Information_for_Interpretation_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        VStdMemSet(Data, 0xFF, sizeof(Data));

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Global_Time_Sync_Measured_Values_Read_Global_Time_Sync_Measured_Values_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ReadDataLength)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 22U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00;
        Data[1] = 0x00;
        Data[2] = 0x00;
        Data[3] = 0x00;
        Data[4] = 0x00;
        Data[5] = 0x00;
        Data[6] = 0x00;
        Data[7] = 0x00;
        Data[8] = 0x00;
        Data[9] = 0x00;
        Data[10] = 0x00;
        Data[11] = 0x00;
        Data[12] = 0x00;
        Data[13] = 0x00;
        Data[14] = 0x00;
        Data[15] = 0x00;
        Data[16] = 0x00;
        Data[17] = 0x00;
        Data[18] = 0x00;
        Data[19] = 0x00;
        Data[20] = 0x00;
        Data[21] = 0x00;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ReadDataLength_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00;
        Data[1] = 0x00;
        Data[2] = 0x00;
        Data[3] = 0x00;
        Data[4] = 0x00;
        Data[5] = 0x00;
        Data[6] = 0x00;
        Data[7] = 0x00;
        Data[8] = 0x00;
        Data[9] = 0x00;
        Data[10] = 0x00;
        Data[11] = 0x00;
        Data[12] = 0x00;
        Data[13] = 0x00;
        Data[14] = 0x00;
        Data[15] = 0x00;
        Data[16] = 0x00;
        Data[17] = 0x00;
        Data[18] = 0x00;
        Data[19] = 0x00;
        Data[20] = 0x00;
        Data[21] = 0x00;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ReadDataLength_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ReadDataLength)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != DataLength)
    {
        *DataLength = 22U;
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_WriteData)  */

    /* TO BE IMPLEMENTED */
    return E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_WriteData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0x0241 PRE-SAFE Recorder 1 --------------------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_WriteData)  */

    /* TO BE IMPLEMENTED */
    return E_OK;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0x0244 PRE-SAFE Counter --------------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x0241 PRE-SAFE Recorder 1 ------------------------------------------------------------------------------------------------ */

/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Threshold_Green_to_Yellow_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Threshold_Yellow_to_Red_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Current_Value_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Current_Value_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Current_Value_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Threshold_Yellow_to_Red_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Threshold_Green_to_Yellow_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Threshold_Green_to_Yellow_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Threshold_Yellow_to_Red_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Threshold_Yellow_to_Red_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Current_Value_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0xFF;
        Data[1] = 0xFF;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_RaceStart_Threshold_Green_to_Yellow_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0xFF;
        Data[1] = 0xFF;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0xFF;
        Data[1] = 0xFF;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0xFF;
        Data[1] = 0xFF;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0xFF;
        Data[1] = 0xFF;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DiagSessionChangeCallback_doc)  ***********************/


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */
        Data[1] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif


#if 0
/***  Start of saved code (symbol: runnable implementation:DiagSessionChangeCallback)  **********************/
   REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv roe_DiagSessionChange;

   roe_DiagSessionChange.ROE_0 = I_C08_ROE_0_DIAG_SESSION_CHANGE;
   roe_DiagSessionChange.ROE_1 = newState;
   roe_DiagSessionChange.ROE_2 = 0x00u;
   roe_DiagSessionChange.ROE_3 = 0x00u;
   roe_DiagSessionChange.ROE_4 = 0x00u;
   roe_DiagSessionChange.ROE_5 = 0x00u;
   roe_DiagSessionChange.ROE_6 = 0x00u;
   roe_DiagSessionChange.ROE_7 = 0x00u;

   (void)Rte_Write_DiagFunction_P_ROE_ROE_XX_ST3(&roe_DiagSessionChange);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_CANoutput2_ReadData_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_CANoutput1_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00;

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_CANoutput2_ReadData_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_CANoutput1_ConditionCheckRead_doc)  */

/* ------------------------------------------------------------------------------- End of DID 0x0200 Can Input  --------------------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------------- DID 0x0210 Can Output  -------------------------------------------------------------------------------------------- */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DiagSessionChangeCallback_doc)  ***********************/

/**
* \brief
*     Here write function descriptions.
* \param
*     formerState
*     newState
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0260]
**/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_CANoutput2_ReadData_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_CANoutput1_ConditionCheckRead)  */

    return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData)  */

    Std_ReturnType ret = E_NOT_OK;

    if (NULL_PTR != Data)
    {
        Data[0] = 0x00; /* dummy - to be implemented correctly */

        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_CANoutput1_ReadData_doc)  */

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead_doc)  */


/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);;

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_CAN_output_Read_CANoutput2_ReadData_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead)  */

  return ConditionCheckRead_General(OpStatus, ErrorCode);

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: documentation area:DiagSessionChangeCallback_doc)  ***********************/

/**
* \brief
*     Here write function descriptions.
* \param
*     formerState
*     newState
* \exception
*     Here write function exceptions. 
* \pre
*     Here write function pre conditions.
* \post
*     Here write function post conditions.
* \return
*     Standard return type
*   [COVERS: DSG_DIA_MMA_0260]
**/

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: runnable implementation:DataServices_Check_Reprogramming_Preconditions_Routine_Start)  */

    /*Set routine info to succesfull*/
    routineInfo[0] = DIAG_ROUTINE_SUCCESFULL;

    /*No unfulfilled preconditions*/
    Number_of_Unfulfilled_Preconditions[0] = 0u;

    return RTE_E_OK;

/***  End of saved code  ************************************************************************************/
#endif

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
