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
 *              File: Com_Cfg.h
 *   Generation Time: 2023-07-10 14:36:08
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (COM_CFG_H)
# define COM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#ifndef COM_USE_DUMMY_STATEMENT
#define COM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT
#define COM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT_CONST
#define COM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COM_ATOMIC_VARIABLE_ACCESS
#define COM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COM_PROCESSOR_TC322L
#define COM_PROCESSOR_TC322L
#endif
#ifndef COM_COMP_TASKING
#define COM_COMP_TASKING
#endif
#ifndef COM_GEN_GENERATOR_MSR
#define COM_GEN_GENERATOR_MSR
#endif
#ifndef COM_CPUTYPE_BITORDER_LSB2MSB
#define COM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef COM_CONFIGURATION_VARIANT_PRECOMPILE
#define COM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COM_CONFIGURATION_VARIANT_LINKTIME
#define COM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COM_CONFIGURATION_VARIANT
#define COM_CONFIGURATION_VARIANT COM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COM_POSTBUILD_VARIANT_SUPPORT
#define COM_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


/* General */
#define COM_DEV_ERROR_DETECT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComSafeBswChecks] || /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_DEV_ERROR_REPORT                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS   STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComRetryFailedTransmitRequests] */

/* API */
#define COM_COMMUNICATION_INTERFACE          STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRCommunicationInterface] */
#define COM_TRANSPORT_PROTOCOL               STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTransportProtocol] */

#define COM_TRIGGER_TRANSMIT_API             STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTriggertransmit] */
#define COM_TX_CONFIRMATION_API              STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTxConfirmation] */
#define COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] */
#define COM_MAIN_FUNCTION_ROUTE_SIGNALS_API  STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComSignalGateway] || /ActiveEcuC/Com/ComGeneral[0:ComDescriptionGateway] */
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API    STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] */

#define COM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComVersionInfoApi] */

#define COM_SUPPORTED_IPDU_GROUPS            5u  /**< /ActiveEcuC/Com/ComGeneral[0:ComSupportedIPduGroups] */

#define COM_RXIMMEDIATEFCTPTRCACHE           STD_OFF
#define COM_RXIMMEDIATEFCTPTRCACHESIZE       0U

#define COM_STRICT_REPETITION_PERIOD         STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComStrictRepetitionPeriod] */
#define COM_MIXEDMODEPERIODICSUPPRESSION     STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMixedModePeriodicSuppression] */

/**
  \brief  Constants to compare floating-point values according to ISO C-99 standard.
  \details  -
    \{
*/
#define COM_FLT_EPSILON                      1E-5
#define COM_DBL_EPSILON                      1E-9
/**
  \}
*/




/**
 * \defgroup ComHandleIdsComRxSig Handle IDs of handle space ComRxSig.
 * \brief Rx Signals
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FL_01_ST3_60c4ffa1_Rx  180u    /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FL_02_ST3_27648571_Rx  181u    /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FL_03_ST3_1a04acc1_Rx  182u    /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FL_04_ST3_a82470d1_Rx  183u    /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FL_05_ST3_95445961_Rx  184u    /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FL_06_ST3_d2e423b1_Rx  185u    /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FL_07_ST3_ef840a01_Rx  186u    /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FL_08_ST3_6dd49dd0_Rx  187u    /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FR_01_ST3_b6e465c6_Rx  180u    /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FR_02_ST3_f1441f16_Rx  181u    /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FR_03_ST3_cc2436a6_Rx  182u    /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FR_04_ST3_7e04eab6_Rx  183u    /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FR_05_ST3_4364c306_Rx  184u    /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FR_06_ST3_04c4b9d6_Rx  185u    /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FR_07_ST3_39a49066_Rx  186u    /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rq_RBTM_FR_08_ST3_bbf407b7_Rx  187u    /**< [Right] */
#define ComConf_ComSignal_BeltHdOvr_FL_Stat_ST3_3489841d_Rx           179u    /**< [Left] */
#define ComConf_ComSignal_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx           179u    /**< [Right] */
#define ComConf_ComSignal_PS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx           188u    /**< [Left] */
#define ComConf_ComSignal_PS_Curve_FR_Rq_HU_ST3_90527677_Rx           188u    /**< [Right] */
#define ComConf_ComSignal_RevBltTns_FL_ComCyc_Actv_ST3_4c5f745f_Rx    189u    /**< [Right] */
#define ComConf_ComSignal_RevBltTns_FL_SafeCyc_Actv_ST3_b0efc754_Rx   190u    /**< [Right] */
#define ComConf_ComSignal_RevBltTns_FR_ComCyc_Actv_ST3_4c00d29e_Rx    189u    /**< [Left] */
#define ComConf_ComSignal_RevBltTns_FR_SafeCyc_Actv_ST3_5c8c6ad4_Rx   190u    /**< [Left] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComGroupSignal_ADAS_Meta_CountryCode_ST36_533f1e2d_Rx 0u      /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_CycCnt_ST36_bb9cdf27_Rx      1u      /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_DrvSide_ST36_22c578f2_Rx     2u      /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_HwVer_ST36_1eda5958_Rx       3u      /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_MapProvid_ST36_a95ee03c_Rx   4u      /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_MapVerQuar_ST36_c498289a_Rx  5u      /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_MapVerYear_ST36_03fbbba9_Rx  6u      /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_ProtVer_Major_ST36_db37cb7d_Rx 7u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_ProtVer_MinorSub_ST36_acb19add_Rx 8u /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_ProtVer_Minor_ST36_e4a5679f_Rx 9u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_RegionCode_ST36_9e8c91d6_Rx  10u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Meta_SpdUnits_ST36_b689c97b_Rx    11u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_Age_ST3_5a9b03e1_Rx          12u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_CurLane_ST3_a4b581c7_Rx      13u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_CycCnt_ST3_1a5fd650_Rx       14u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_Idx_ST3_77906c1b_Rx          15u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_MsgTyp_ST3_5cd85424_Rx       16u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_Offset_ST3_f95ee08b_Rx       17u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_PathIdx_ST3_767b1017_Rx      18u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_PosConfdc_ST3_48dd3431_Rx    19u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_PosProbb_ST3_8f4d30bf_Rx     20u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_RelHead_ST3_3452334b_Rx      21u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_Posn_Spd_ST3_89699595_Rx          22u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_AccurClass_CL_ST31_f1371770_Rx 27u /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_CtrlPoint_CL_ST31_6fbe8af5_Rx 28u /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_CycCnt_CL_ST31_a9579c2f_Rx 29u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_Dist1_CL_ST31_455ed63e_Rx 30u   /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_MsgTyp_CL_ST31_44c68e23_Rx 31u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_Offset_CL_ST31_58fcb916_Rx 32u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_PathIdx_CL_ST31_9989379b_Rx 33u /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_ReTr_CL_ST31_8166ae07_Rx 34u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_Updt_CL_ST31_31b6d4b3_Rx 35u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_Value0_CL_ST31_6c970c4b_Rx 36u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_ADAS_ProfShort_Value1_CL_ST31_7bec1808_Rx 37u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_Bckl_Sw_D_Stat_ST3_cb403d1d_Rx         38u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Bckl_Sw_FP_Stat_ST3_0736b261_Rx        39u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_Bckl_Sw_Fx_Stat_Pr5_ST3_e761a2ea_Rx 40u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_CLkS_DrRltch_Stat_Pr5_ST3_911c4673_Rx 44u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_DI_Odo_Pr5_ST3_ca96419c_Rx         51u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_ELC_Lvr_Stat_Pr5_ST3_0624156b_Rx   56u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_EVC_CfgList_01_08_Pr5_ST3_4f3aab12_Rx 61u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_Ign_Stat_Pr5_ST3_ef30f764_Rx       72u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_ORC_Impact2_Pr5_ST3_54ead0a9_Rx    78u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_ORC_Impact3_Pr5_ST3_20961dce_Rx    86u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_PT4_PTCoor4_Pr5_ST3_7d33cb58_Rx    100u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_b671dc67_Rx 107u /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_PresfAct_Adj_Pr5_ST3_901db976_Rx   122u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_CRC_SBeltTens_SP_Lvl_Pr5_ST3_ef88391d_Rx 133u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_DPC_Md_PT_Rq_ST3_221f27a4_Rx           54u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_DrRLtch_FL_Stat_ST3_ce64a199_Rx        45u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_DrRLtch_FR_Stat_ST3_f70310c2_Rx        46u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_DrRLtch_RL_Stat_ST3_d04b16d0_Rx        47u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_DrRLtch_RR_Stat_ST3_e92ca78b_Rx        48u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ELC_HiBmLvr_Stat_ST3_e6f8b687_Rx       57u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ELC_TurnIndLvr_Stat_ST3_16708a3c_Rx    58u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_CfgList_01_08_Stat_ST3_93476784_Rx 62u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_List01_BodyStyle_ST3_a3504531_Rx   63u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_List02_VehLine_ST3_bbfa2725_Rx     64u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_List03_StStyle_ST3_0f0d9336_Rx     65u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_List04_YrOfModf_2_ST3_3da05805_Rx  66u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_List05_YrOfModf_1_ST3_d468b344_Rx  67u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_List06_Country_ST3_82113093_Rx     68u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_List07_TxStyle_ST3_fcb30cad_Rx     69u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_EVC_List08_HL_Style_ST3_f988c239_Rx    70u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_ISw_Stat_ST3_20c6e8e0_Rx               73u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_F1_ST3_7aa87b43_Rx              87u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_F2_ST3_3d080193_Rx              88u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_F3_ST3_00682823_Rx              89u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_P_ST3_83cd5435_Rx               79u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_R1_ST3_350dbb96_Rx              80u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_R2_ST3_72adc146_Rx              81u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_RO_type1_ST3_6d14f528_Rx        90u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_RO_type2_ST3_2ab48ff8_Rx        91u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_S1_ST3_29b3e86b_Rx              92u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_S2_ST3_6e1392bb_Rx              93u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_X_ST3_5cefa915_Rx               94u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_Y_ST3_8edd3644_Rx               82u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Impact_minor_ST3_4534635b_Rx           83u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_KG_StartSw_Psd_ST3_b1980089_Rx         74u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Odo_ST3_657046b6_Rx                    52u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_Accel_Md_ST3_cd32fba3_Rx    106u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_DrvPosn_Disp_Rq_ST3_d775bf02_Rx 108u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_DrvPosn_N_Actv_ST3_209a5852_Rx 109u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_DrvPosn_Stat_ST3_af5d60f3_Rx 110u   /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_DrvPosn_Target_ST3_bba2a0e0_Rx 111u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_EngStartPN14_Stat_ST3_b3436bd4_Rx 101u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_Gr_ST3_dd0b905e_Rx          112u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_Gr_Target_ST3_b5aa8bc3_Rx   113u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_PT_Rdy_ST3_3039cfe2_Rx      102u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_SSA_EngSp_ST3_b458926e_Rx   103u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_SSA_Standby_Stat_ST3_3cbc753b_Rx 114u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_ShW_MnTrctAxl_D_Allowed_ST3_f3898bec_Rx 115u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_ShW_MnTrctAxl_N_Allowed_ST3_c9d6edca_Rx 116u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_ShW_MnTrctAxl_P_Allow_Drv_ST3_901488c0_Rx 117u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_ShW_MnTrctAxl_P_Allowed_ST3_873747a0_Rx 118u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PT4_PTCoor_ShW_MnTrctAxl_R_Allowed_ST3_e76bf2eb_Rx 119u /**< [Left, Right] */
#define ComConf_ComGroupSignal_PresfAccelReset_NotExcd_ST3_c7c4d546_Rx 123u   /**< [Left, Right] */
#define ComConf_ComGroupSignal_PresfAct_Adj_Rq_ST3_e5b37ffb_Rx        124u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_PresfAct_TensSupp_Rq_ST3_62b93d7a_Rx   125u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_Presf_Enbl_ST3_40bed323_Rx             126u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_Presf_FricCoeff_Estim_ST3_b142a105_Rx  127u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_Presf_Fric_Fctr_Lo_ST3_9b2a29ac_Rx     128u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_Presf_Lvl_ST3_dc8c82ac_Rx              129u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_Presf_Snd_Rq_ST3_6cb03b74_Rx           130u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_RBTMFL_SP_Lvl_Rq_ST35_1b9e7376_Rx      134u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_RBTMFR_SP_Lvl_Rq_ST35_dd3bbb43_Rx      135u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_Rsrv0_SBeltTens_SP_Lvl_Pr5_ST3_aa2f8d25_Rx 136u /**< [Left, Right] */
#define ComConf_ComGroupSignal_Rsrv1_Bckl_Sw_Fx_Stat_ST3_8584783a_Rx  41u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Rsrv1_ELC_Lvr_Stat_Pr5_ST3_f3d8e141_Rx 59u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Rsrv1_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_83426982_Rx 120u /**< [Left, Right] */
#define ComConf_ComGroupSignal_Rsrv1_PT4_PTCoor_PT_Rdy_Pr5_ST3_e7f327eb_Rx 104u /**< [Left, Right] */
#define ComConf_ComGroupSignal_Rsrv6_Presf_Adj_ST3_f21bcfa6_Rx        131u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_Bckl_Sw_Fx_Stat_Pr5_ST3_4b42e447_Rx 42u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_CLkS_DrRltch_Stat_Pr5_ST3_150acc51_Rx 49u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_DI_Odo_Pr5_ST3_b7af4600_Rx         53u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_ELC_Lvr_Stat_Pr5_ST3_0faa536b_Rx   60u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_EVC_CfgList_01_08_Pr5_ST3_cb2c2130_Rx 71u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_Ign_Stat_Pr5_ST3_aca0dae8_Rx       75u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_ORC_Impact2_Pr5_ST3_6ce0fba5_Rx    84u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_ORC_Impact3_Pr5_ST3_189c36c2_Rx    95u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_PT4_PTCoor4_Pr5_ST3_4539e054_Rx    105u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_940d6b76_Rx 121u /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_PresfAct_Adj_Pr5_ST3_9993ff76_Rx   132u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_SQC_SBeltTens_SP_Lvl_Pr5_ST3_4743c50e_Rx 137u  /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_Auth_0_ST3_8d2bd1cf_Rx          138u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_Auth_1_ST3_b04bf87f_Rx          139u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_Auth_2_ST3_f7eb82af_Rx          140u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_Auth_3_ST3_ca8bab1f_Rx          141u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_Auth_4_ST3_78ab770f_Rx          142u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_Auth_5_ST3_45cb5ebf_Rx          143u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_Auth_6_ST3_026b246f_Rx          144u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_Auth_7_ST3_3f0b0ddf_Rx          145u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_RealTmOffset_0_ST3_a2539a58_Rx  146u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_RealTmOffset_1_ST3_9f33b3e8_Rx  147u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_RealTmOffset_2_ST3_d893c938_Rx  148u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_RealTmOffset_3_ST3_e5f3e088_Rx  149u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_RealTmOffset_4_ST3_57d33c98_Rx  150u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_RealTmOffset_5_ST3_6ab31528_Rx  151u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_RealTmOffset_6_ST3_2d136ff8_Rx  152u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_RealTmOffset_7_ST3_10734648_Rx  153u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_0_ST3_dac5ba08_Rx 154u /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_1_ST3_e7a593b8_Rx 155u /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_2_ST3_a005e968_Rx 156u /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_3_ST3_9d65c0d8_Rx 157u /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_4_ST3_2f451cc8_Rx 158u /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_5_ST3_12253578_Rx 159u /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_6_ST3_55854fa8_Rx 160u /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_7_ST3_68e56618_Rx 161u /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SharedSecret_0_ST3_74e3db3b_Rx  162u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SharedSecret_1_ST3_4983f28b_Rx  163u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SharedSecret_2_ST3_0e23885b_Rx  164u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SharedSecret_3_ST3_3343a1eb_Rx  165u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SharedSecret_4_ST3_81637dfb_Rx  166u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SharedSecret_5_ST3_bc03544b_Rx  167u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SharedSecret_6_ST3_fba32e9b_Rx  168u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_SharedSecret_7_ST3_c6c3072b_Rx  169u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_VIN_0_ST3_fc3604d4_Rx           170u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_VIN_1_ST3_c1562d64_Rx           171u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_VIN_2_ST3_86f657b4_Rx           172u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_VIN_3_ST3_bb967e04_Rx           173u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_VIN_4_ST3_09b6a214_Rx           174u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_VIN_5_ST3_34d68ba4_Rx           175u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_VIN_6_ST3_7376f174_Rx           176u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VSS_TP_VIN_7_ST3_4e16d8c4_Rx           177u    /**< [Left, Right] */
#define ComConf_ComGroupSignal_VehPosn_ST3_ea170185_Rx                85u     /**< [Left, Right] */
#define ComConf_ComGroupSignal_Veh_Op_Mode_ST3_e0acb0c9_Rx            76u     /**< [Left, Right] */
#define ComConf_ComSignal_ADAS_Prediction_MsgTyp_ST36_11a04f12_Rx     23u     /**< [Left, Right] */
#define ComConf_ComSignal_ADAS_Prediction_MsgTyp_ST37_66a77f84_Rx     24u     /**< [Left, Right] */
#define ComConf_ComSignal_ADAS_ProfShort_ProfTyp_ST31_a96eaafe_Rx     25u     /**< [Left, Right] */
#define ComConf_ComSignal_ADAS_ProfShort_ProfTyp_ST331_eb463c84_Rx    26u     /**< [Left, Right] */
#define ComConf_ComSignal_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx         43u     /**< [Left, Right] */
#define ComConf_ComSignal_ComSignalPnc_EIRA_CAN_Rx                    50u     /**< [Left, Right] */
#define ComConf_ComSignal_DidA_ExtTest_Pres_ST3_7e50ca1d_Rx           55u     /**< [Left, Right] */
#define ComConf_ComSignal_Navi_RouteGuidance_Stat_ST3_ac3bae27_Rx     77u     /**< [Left, Right] */
#define ComConf_ComSignal_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx            96u     /**< [Left, Right] */
#define ComConf_ComSignal_PN14_ProdMd_Stat_ST3_be2b5dfe_Rx            97u     /**< [Left, Right] */
#define ComConf_ComSignal_PN14_SupBat_Volt_ST3_946fd9c6_Rx            98u     /**< [Left, Right] */
#define ComConf_ComSignal_PN14_TransMd_Stat_ST3_2208da29_Rx           99u     /**< [Left, Right] */
#define ComConf_ComSignal_VehSpd_Disp_ST3_4922a2fd_Rx                 178u    /**< [Left, Right] */
/**\} */

/**
 * \defgroup ComHandleIdsComTxSig Handle IDs of handle space ComTxSig.
 * \brief Tx Signals
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FL_01_ST3_7a76cd90_Tx  4u      /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FL_02_ST3_3dd6b740_Tx  5u      /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FL_03_ST3_00b69ef0_Tx  6u      /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FL_04_ST3_b29642e0_Tx  7u      /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FL_05_ST3_8ff66b50_Tx  8u      /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FL_06_ST3_c8561180_Tx  9u      /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FL_07_ST3_f5363830_Tx  10u     /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FL_08_ST3_7766afe1_Tx  11u     /**< [Left] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FR_01_ST3_ac5657f7_Tx  4u      /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FR_02_ST3_ebf62d27_Tx  5u      /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FR_03_ST3_d6960497_Tx  6u      /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FR_04_ST3_64b6d887_Tx  7u      /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FR_05_ST3_59d6f137_Tx  8u      /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FR_06_ST3_1e768be7_Tx  9u      /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FR_07_ST3_2316a257_Tx  10u     /**< [Right] */
#define ComConf_ComGroupSignal_Develop_Rs_RBTM_FR_08_ST3_a1463586_Tx  11u     /**< [Right] */
#define ComConf_ComGroupSignal_Meas_RBTM_FL_01_ST3_1999cf4b_Tx        13u     /**< [Left] */
#define ComConf_ComGroupSignal_Meas_RBTM_FL_02_ST3_5e39b59b_Tx        14u     /**< [Left] */
#define ComConf_ComGroupSignal_Meas_RBTM_FL_03_ST3_63599c2b_Tx        15u     /**< [Left] */
#define ComConf_ComGroupSignal_Meas_RBTM_FL_04_ST3_d179403b_Tx        16u     /**< [Left] */
#define ComConf_ComGroupSignal_Meas_RBTM_FL_05_ST3_ec19698b_Tx        17u     /**< [Left] */
#define ComConf_ComGroupSignal_Meas_RBTM_FL_06_ST3_abb9135b_Tx        18u     /**< [Left] */
#define ComConf_ComGroupSignal_Meas_RBTM_FL_07_ST3_96d93aeb_Tx        19u     /**< [Left] */
#define ComConf_ComGroupSignal_Meas_RBTM_FL_08_ST3_1489ad3a_Tx        20u     /**< [Left] */
#define ComConf_ComGroupSignal_Meas_RBTM_FR_01_ST3_6f6f342d_Tx        13u     /**< [Right] */
#define ComConf_ComGroupSignal_Meas_RBTM_FR_02_ST3_28cf4efd_Tx        14u     /**< [Right] */
#define ComConf_ComGroupSignal_Meas_RBTM_FR_03_ST3_15af674d_Tx        15u     /**< [Right] */
#define ComConf_ComGroupSignal_Meas_RBTM_FR_04_ST3_a78fbb5d_Tx        16u     /**< [Right] */
#define ComConf_ComGroupSignal_Meas_RBTM_FR_05_ST3_9aef92ed_Tx        17u     /**< [Right] */
#define ComConf_ComGroupSignal_Meas_RBTM_FR_06_ST3_dd4fe83d_Tx        18u     /**< [Right] */
#define ComConf_ComGroupSignal_Meas_RBTM_FR_07_ST3_e02fc18d_Tx        19u     /**< [Right] */
#define ComConf_ComGroupSignal_Meas_RBTM_FR_08_ST3_627f565c_Tx        20u     /**< [Right] */
#define ComConf_ComGroupSignal_ROE_0_RBTM_FL_ST3_7255ce21_Tx          28u     /**< [Left] */
#define ComConf_ComGroupSignal_ROE_0_RBTM_FR_ST3_418450d2_Tx          28u     /**< [Right] */
#define ComConf_ComGroupSignal_ROE_1_RBTM_FL_ST3_afc317a4_Tx          29u     /**< [Left] */
#define ComConf_ComGroupSignal_ROE_1_RBTM_FR_ST3_9c128957_Tx          29u     /**< [Right] */
#define ComConf_ComGroupSignal_ROE_2_RBTM_FL_ST3_12097b6a_Tx          30u     /**< [Left] */
#define ComConf_ComGroupSignal_ROE_2_RBTM_FR_ST3_21d8e599_Tx          30u     /**< [Right] */
#define ComConf_ComGroupSignal_ROE_3_RBTM_FL_ST3_cf9fa2ef_Tx          31u     /**< [Left] */
#define ComConf_ComGroupSignal_ROE_3_RBTM_FR_ST3_fc4e3c1c_Tx          31u     /**< [Right] */
#define ComConf_ComGroupSignal_ROE_4_RBTM_FL_ST3_b2eca4b7_Tx          32u     /**< [Left] */
#define ComConf_ComGroupSignal_ROE_4_RBTM_FR_ST3_813d3a44_Tx          32u     /**< [Right] */
#define ComConf_ComGroupSignal_ROE_5_RBTM_FL_ST3_6f7a7d32_Tx          33u     /**< [Left] */
#define ComConf_ComGroupSignal_ROE_5_RBTM_FR_ST3_5cabe3c1_Tx          33u     /**< [Right] */
#define ComConf_ComGroupSignal_ROE_6_RBTM_FL_ST3_d2b011fc_Tx          34u     /**< [Left] */
#define ComConf_ComGroupSignal_ROE_6_RBTM_FR_ST3_e1618f0f_Tx          34u     /**< [Right] */
#define ComConf_ComGroupSignal_ROE_7_RBTM_FL_ST3_0f26c879_Tx          35u     /**< [Left] */
#define ComConf_ComGroupSignal_ROE_7_RBTM_FR_ST3_3cf7568a_Tx          35u     /**< [Right] */
#define ComConf_ComSignal_Awake_Diag_Actv_RBTM_FL_ST3_5efe61d8_Tx     0u      /**< [Left] */
#define ComConf_ComSignal_Awake_Diag_Actv_RBTM_FR_ST3_822fa87a_Tx     0u      /**< [Right] */
#define ComConf_ComSignal_Awake_Ignition_On_RBTM_FL_ST3_49d22bbd_Tx   1u      /**< [Left] */
#define ComConf_ComSignal_Awake_Ignition_On_RBTM_FR_ST3_df6a9d63_Tx   1u      /**< [Right] */
#define ComConf_ComSignal_Awake_NwStart_RBTM_FL_ST3_393ce9b3_Tx       2u      /**< [Left] */
#define ComConf_ComSignal_Awake_NwStart_RBTM_FR_ST3_59fd792e_Tx       2u      /**< [Right] */
#define ComConf_ComSignal_BltSlckDec_Md_FL_Stat_ST3_e47e790a_Tx       3u      /**< [Left] */
#define ComConf_ComSignal_BltSlckDec_Md_FR_Stat_ST3_8538ecdf_Tx       3u      /**< [Right] */
#define ComConf_ComSignal_ECU_Id_RBTM_FL_ST3_b4de0ce2_Tx              12u     /**< [Left] */
#define ComConf_ComSignal_ECU_Id_RBTM_FR_ST3_765534d2_Tx              12u     /**< [Right] */
#define ComConf_ComSignal_NM_RBTM_FL_ST3_PNC_785a2d76_Tx              21u     /**< [Left] */
#define ComConf_ComSignal_NM_RBTM_FR_ST3_PNC_0103a546_Tx              21u     /**< [Right] */
#define ComConf_ComSignal_PS_Curve_FL_Stat_ST3_b0d41119_Tx            22u     /**< [Left] */
#define ComConf_ComSignal_PS_Curve_FR_Stat_ST3_36a2193c_Tx            22u     /**< [Right] */
#define ComConf_ComSignal_RBTMFL_Actv_Lvl_ST35_6199228f_Tx            23u     /**< [Left] */
#define ComConf_ComSignal_RBTMFL_SP_ActvClient_ST35_bec76928_Tx       24u     /**< [Left] */
#define ComConf_ComSignal_RBTMFL_SP_FctPrecond_Stat_ST35_bbfa2c80_Tx  25u     /**< [Left] */
#define ComConf_ComSignal_RBTMFR_Actv_Lvl_ST35_77991ccb_Tx            23u     /**< [Right] */
#define ComConf_ComSignal_RBTMFR_SP_ActvClient_ST35_1fd8ade4_Tx       24u     /**< [Right] */
#define ComConf_ComSignal_RBTMFR_SP_FctPrecond_Stat_ST35_ce5639ee_Tx  25u     /**< [Right] */
#define ComConf_ComSignal_RBTM_FL_Disp_Rq_ST3_c372540c_Tx             26u     /**< [Left] */
#define ComConf_ComSignal_RBTM_FL_Tgl_ST3_1fe530ed_Tx                 27u     /**< [Left] */
#define ComConf_ComSignal_RBTM_FR_Disp_Rq_ST3_4c4b9655_Tx             26u     /**< [Right] */
#define ComConf_ComSignal_RBTM_FR_Tgl_ST3_bb42027b_Tx                 27u     /**< [Right] */
#define ComConf_ComSignal_RevBltTns_FL_ComCyc_Actv_ST3_4c5f745f_Tx    36u     /**< [Left] */
#define ComConf_ComSignal_RevBltTns_FL_SafeCyc_Actv_ST3_b0efc754_Tx   37u     /**< [Left] */
#define ComConf_ComSignal_RevBltTns_FR_ComCyc_Actv_ST3_4c00d29e_Tx    36u     /**< [Right] */
#define ComConf_ComSignal_RevBltTns_FR_SafeCyc_Actv_ST3_5c8c6ad4_Tx   37u     /**< [Right] */
#define ComConf_ComSignal_WakeupRsn_RBTM_FL_ST3_91bb10a0_Tx           38u     /**< [Left] */
#define ComConf_ComSignal_WakeupRsn_RBTM_FR_ST3_6ec4195b_Tx           38u     /**< [Right] */
/**\} */




/**
 * \defgroup ComHandleIdscomRxSigGrp Handle IDs of handle space comRxSigGrp.
 * \brief Rx SignalGroups
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignalGroup_Develop8_Rq_RBTM_FL_ST3_48g6nu8rjjp9s4bhq1x3pz06u_6f2fac01_Rx 22u /**< [Left] */
#define ComConf_ComSignalGroup_Develop8_Rq_RBTM_FR_ST3_bcqj2sqez8u9spf5qxmu4a35u_86f26259_Rx 22u /**< [Right] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignalGroup_ADAS_Meta_ST3_40sly585w5zu8pqjwib3nr7y7_6_d1dcd94d_Rx 0u /**< [Left, Right] */
#define ComConf_ComSignalGroup_ADAS_Posn_ST3_cre9f2x2lehhx0k4gxnl4u9sg_7bfda340_Rx 1u /**< [Left, Right] */
#define ComConf_ComSignalGroup_ADAS_Profile_Short_CurvLn_ST3_96e9ejcafisp13h7moqj5malh_1_aac62a51_Rx 2u /**< [Left, Right] */
#define ComConf_ComSignalGroup_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx 3u /**< [Left, Right] */
#define ComConf_ComSignalGroup_CLkS_DrRltch_Stat_Pr5_ST3_7at68qvnk0r9npofyykyfq82v_10e0cb0e_Rx 4u /**< [Left, Right] */
#define ComConf_ComSignalGroup_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx 5u /**< [Left, Right] */
#define ComConf_ComSignalGroup_DPC_Md_Rq_ESP_Pr5_ST3_dcsny138uwpesz5bmssj1scqi_6b0a3c02_Rx 6u /**< [Left, Right] */
#define ComConf_ComSignalGroup_ELC_Lvr_Stat_Pr5_ST3_7b68ktfwrvsk1oyozi7cntryn_cd318e5f_Rx 7u /**< [Left, Right] */
#define ComConf_ComSignalGroup_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx 8u /**< [Left, Right] */
#define ComConf_ComSignalGroup_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx 9u /**< [Left, Right] */
#define ComConf_ComSignalGroup_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx 10u /**< [Left, Right] */
#define ComConf_ComSignalGroup_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx 11u /**< [Left, Right] */
#define ComConf_ComSignalGroup_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx 12u /**< [Left, Right] */
#define ComConf_ComSignalGroup_PT4_PTCoor9_Pr5_ST3_6r95o81sst3tk9w2lzz600cw3_5dfe4b97_Rx 13u /**< [Left, Right] */
#define ComConf_ComSignalGroup_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx 14u /**< [Left, Right] */
#define ComConf_ComSignalGroup_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx 15u /**< [Left, Right] */
#define ComConf_ComSignalGroup_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx 16u /**< [Left, Right] */
#define ComConf_ComSignalGroup_VSS_TP_Auth_ST3_6j4id7sghlvlbroli4wjozjik_2ac87786_Rx 17u /**< [Left, Right] */
#define ComConf_ComSignalGroup_VSS_TP_RealTmOffset_ST3_1t7vc44gftc0wv35k5kgc2in9_d3385ce4_Rx 18u /**< [Left, Right] */
#define ComConf_ComSignalGroup_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx 19u /**< [Left, Right] */
#define ComConf_ComSignalGroup_VSS_TP_SharedSecret_ST3_8pj4t8t4rm3tw3pk5hj7vonti_d9a21e4b_Rx 20u /**< [Left, Right] */
#define ComConf_ComSignalGroup_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx 21u /**< [Left, Right] */
/**\} */

/**
 * \defgroup ComHandleIdscomTxSigGrp Handle IDs of handle space comTxSigGrp.
 * \brief Tx SignalGroups
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignalGroup_Develop8_Rs_RBTM_FL_ST3_7jg1r8p1skn6yj1t9z2s157vt_a69dcfbb_Tx 0u /**< [Left] */
#define ComConf_ComSignalGroup_Develop8_Rs_RBTM_FR_ST3_5t18pq0a13t698v0vsj7yvmmm_aab2c7df_Tx 0u /**< [Right] */
#define ComConf_ComSignalGroup_Meas8_RBTM_FL_ST3_72jyquhuktrmjm0hkqempja37_23ddfefa_Tx 1u /**< [Left] */
#define ComConf_ComSignalGroup_Meas8_RBTM_FR_ST3_7ba3lhjy9fnhufd3n9dyw0p9p_19ed5f9c_Tx 1u /**< [Right] */
#define ComConf_ComSignalGroup_ROE_RBTM_FL_ST3_6e0rxnifai2txra0wamb18g4m_4feaeebf_Tx 2u /**< [Left] */
#define ComConf_ComSignalGroup_ROE_RBTM_FR_ST3_3f1btonh6ivdn6ytgyuu9rtt1_5c720902_Tx 2u /**< [Right] */
/**\} */




/**
 * \defgroup ComHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_20_54c591d6         0u      /**< [Left] */
#define ComConf_ComIPduGroup_RBTM_FL_BODY3_Rx_PNC_All_Active_46e8c3b2 1u      /**< [Left] */
#define ComConf_ComIPduGroup_RBTM_FL_BODY3_Tx_PNC_20_27dfe85c         2u      /**< [Left] */
#define ComConf_ComIPduGroup_RBTM_FL_BODY3_Tx_PNC_All_Active_e1dc74ba 3u      /**< [Left] */
#define ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_20_02b0f03d         0u      /**< [Right] */
#define ComConf_ComIPduGroup_RBTM_FR_BODY3_Rx_PNC_All_Active_592f1bcd 1u      /**< [Right] */
#define ComConf_ComIPduGroup_RBTM_FR_BODY3_Tx_PNC_20_71aa89b7         2u      /**< [Right] */
#define ComConf_ComIPduGroup_RBTM_FR_BODY3_Tx_PNC_All_Active_fe1bacc5 3u      /**< [Right] */
#define ComConf_ComIPduGroup_TxMess_RBTM_FL_BODY3_e804245a            4u      /**< [Left] */
#define ComConf_ComIPduGroup_TxMess_RBTM_FR_BODY3_dfe5c3c9            4u      /**< [Right] */
/**\} */

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

#endif  /* COM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg.h
**********************************************************************************************************************/

