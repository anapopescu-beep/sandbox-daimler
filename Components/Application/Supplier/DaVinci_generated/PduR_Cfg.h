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
 *            Module: PduR
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Cfg.h
 *   Generation Time: 2023-07-10 14:36:06
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_TC322L
#define PDUR_PROCESSOR_TC322L
#endif
#ifndef PDUR_COMP_TASKING
#define PDUR_COMP_TASKING
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif



#define PDUR_DEV_ERROR_DETECT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_EXTENDED_ERROR_CHECKS STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRExtendedErrorChecks] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

#define PDUR_ERROR_NOTIFICATION STD_OFF

#define PDUR_MAIN_FUNCTION STD_OFF

#define PDUR_MULTICORE STD_OFF /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] */

#define PduR_PBConfigIdType uint32

 
 /*  DET Error define list  */ 
#define PDUR_FCT_CANIFRXIND 0x01u 
#define PDUR_FCT_CANIFTX 0x09u 
#define PDUR_FCT_CANIFTXCFM 0x02u 
#define PDUR_FCT_CANNMRXIND 0x11u 
#define PDUR_FCT_CANNMTX 0x19u 
#define PDUR_FCT_CANNMTXCFM 0x12u 
#define PDUR_FCT_CANNMTT 0x13u 
#define PDUR_FCT_CANTPRXIND 0x05u 
#define PDUR_FCT_CANTPTX 0x09u 
#define PDUR_FCT_CANTPTXCFM 0x08u 
#define PDUR_FCT_CANTPSOR 0x06u 
#define PDUR_FCT_CANTPCPYRX 0x04u 
#define PDUR_FCT_CANTPCPYTX 0x07u 
#define PDUR_FCT_COMTX 0x89u 
#define PDUR_FCT_COMCTX 0x8Au 
#define PDUR_FCT_DCMTX 0x99u 
#define PDUR_FCT_DCMCTX 0x9Au 
#define PDUR_FCT_IPDUMRXIND 0xA1u 
#define PDUR_FCT_IPDUMTX 0xA9u 
#define PDUR_FCT_IPDUMTXCFM 0xA2u 
#define PDUR_FCT_SECOCRXIND 0x71u 
#define PDUR_FCT_SECOCTX 0x79u 
#define PDUR_FCT_SECOCTXCFM 0x72u 
 /*   PduR_CanIfIfRxIndication  PduR_CanIfTransmit  PduR_CanIfTxConfirmation  PduR_CanNmIfRxIndication  PduR_CanNmTransmit  PduR_CanNmTxConfirmation  PduR_CanNmTriggerTransmit  PduR_CanTpTpRxIndication  PduR_CanTpTransmit  PduR_CanTpTxConfirmation  PduR_CanTpStartOfReception  PduR_CanTpCopyRxData  PduR_CanTpCopyTxData  PduR_ComTransmit  PduR_ComCancelTransmit  PduR_DcmTransmit  PduR_DcmCancelTransmit  PduR_IpduMIfRxIndication  PduR_IpduMTransmit  PduR_IpduMTxConfirmation  PduR_SecOCIfRxIndication  PduR_SecOCTransmit  PduR_SecOCTxConfirmation  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_BeltAdj_FL_Stat_ST3_71e5093a_Rx_9982cecc_Rx 34u  /**< [Right] */
#define PduRConf_PduRDestPdu_BeltAdj_FR_Stat_ST3_2b5906f9_Rx_f252e81e_Rx 34u  /**< [Left] */
#define PduRConf_PduRDestPdu_BeltHdOvr_FL_State_ST3_0b4fb3a9_Rx_11170208_Rx 35u /**< [Left] */
#define PduRConf_PduRDestPdu_BeltHdOvr_FR_State_ST3_09789cac_Rx_4c2f4fea_Rx 35u /**< [Right] */
#define PduRConf_PduRDestPdu_Develop8_Rq_RBTM_FL_ST3_0a7cffe6_Rx_c2dcef25_Rx 36u /**< [Left] */
#define PduRConf_PduRDestPdu_Develop8_Rq_RBTM_FR_ST3_d1911cf7_Rx_73b8d236_Rx 36u /**< [Right] */
#define PduRConf_PduRDestPdu_RBTM_FL_Stat_ST3_d76d14af_Rx_16ae0594_Rx 37u     /**< [Right] */
#define PduRConf_PduRDestPdu_RBTM_FR_Stat_ST3_8dd11b6c_Rx_7234ddac_Rx 37u     /**< [Left] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_ADAS_POSITION_ST3_1ca04d74_Rx_fa09a036_Rx 0u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ADAS_PREDICTION_ST3_1de136c9_Rx_0518217c_Rx 3u   /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ADAS_PREDICTION_ST3_6_262b63d1_Rx        1u      /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ADAS_PREDICTION_ST3_7_512c5347_Rx        2u      /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx     4u      /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx    5u      /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ADAS_PROFILE_SHORT_ST3_894b8265_Rx_e0198081_Rx 6u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx          7u      /**< [Left, Right] */
#define PduRConf_PduRDestPdu_Bckl_Sw_Fx_Stat_ST3_secured_62272d37_Rx_79ab8c0b_Rx 8u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_BeltAdj_UI_Set_Rq_ST3_7be22993_Rx_350798fb_Rx 9u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_CLkS_Dr_State_ST3_74337ed5_Rx_0fa9281f_Rx 10u    /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ComIPduPnc_EIRA_CAN_Rx_cca0f11f_Rx_bb7efc37_Rx 26u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_DIAG_Stat_ST3_d3ec8369_Rx_65d40bec_Rx    11u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_DI_OdoSpeedometer_ST3_0665a232_Rx_3e9512b9_Rx 12u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_DPC_Md_Rq_ESP_d1_ST3_5573a8b2_Rx_ee8d9c90_Rx 13u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ELC_Lvr_Stat_ST3_d97bab99_Rx             14u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_ELC_Lvr_Stat_ST3_secured_29d2456c_Rx_d27a099a_Rx 15u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_EVC_CfgList_01_08_Pr5_ST3_be03dd9d_Rx_4b27d50a_Rx 16u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_Ign_Stat_ST3_1e3dc39f_Rx                 17u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_Ign_Stat_ST3_secured_fb0d4f19_Rx_f57d7485_Rx 18u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_Impact2_ST3_e5526ccc_Rx                  19u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_Impact3_ST3_993f4b56_Rx_7842cc32_Rx      20u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_NTG_Master_Navi_ST3_1032e485_Rx_8a45ba67_Rx 21u  /**< [Left, Right] */
#define PduRConf_PduRDestPdu_PN14_Master_Stat1_ST3_69644078_Rx_a0c57bb3_Rx 22u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_PT4_PTCoor4_ST3_868ca7d3_Rx_a7894e67_Rx  23u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_PT4_PTCoor9_d1_BC_F_ST3_f2a4ec1b_Rx_470e8c8b_Rx 24u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_PT4_PTCoor_DrvPosn_Gear_ST3_f70358bf_Rx_3ba6bace_Rx 25u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_PresfAct_Adj_ST3_81976f17_Rx_7d3a747f_Rx 27u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_SBeltTens_SP_Lvl_ST3_73b20851_Rx_c609bb6e_Rx 28u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_VSS_TP_Auth_ST3_29a0d419_Rx_c76c8221_Rx  29u     /**< [Left, Right] */
#define PduRConf_PduRDestPdu_VSS_TP_RealTmOffset_ST3_d6d134b3_Rx_9136979d_Rx 30u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_VSS_TP_SecTickCount_Lvl2_ST3_c0c3ca3b_Rx_13123c17_Rx 31u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_VSS_TP_SharedSecret_ST3_6d7ca724_Rx_44cfb2dc_Rx 32u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_VSS_TP_VIN_ST3_f7ab6516_Rx_da8efc5d_Rx   33u     /**< [Left, Right] */
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4c2f4fea                       35u     /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_16ae0594                       37u     /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_73b8d236                       36u     /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7234ddac                       37u     /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9982cecc                       34u     /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_11170208                       35u     /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c2dcef25                       36u     /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f252e81e                       34u     /**< [Left] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0fa9281f                       10u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3ba6bace                       26u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3e9512b9                       13u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4b27d50a                       17u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6e617592                       7u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7d3a747f                       27u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8a45ba67                       22u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9e880434                       5u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_27f93d01                       2u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_44cfb2dc                       32u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_65d40bec                       12u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_79ab8c0b                       8u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_470e8c8b                       25u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7842cc32                       21u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_13123c17                       31u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_22492bdd                       20u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_350798fb                       9u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0518217c                       1u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9136979d                       30u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a0c57bb3                       23u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a7894e67                       24u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ae29c120                       15u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_bb7efc37                       11u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c9c2269b                       18u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c76c8221                       29u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c609bb6e                       28u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d1b2606a                       3u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d27a099a                       16u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d645a86c                       4u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_da8efc5d                       33u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e0198081                       6u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ee8d9c90                       14u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f57d7485                       19u     /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fa09a036                       0u      /**< [Left, Right] */
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2c5f6cda                       4u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2db65a34                       2u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3fa3fd23                       10u     /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7f35c914                       8u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8d2872fc                       8u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_25bb0169                       7u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_45e6f19d                       5u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_78db9cf2                       4u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_140ec449                       2u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_249a1158                       9u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_981fdebc                       1u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0892c3c5                       0u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4459b19c                       0u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_9690baaa                       5u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_074527d1                       6u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a0766459                       9u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a9321799                       6u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b7de4975                       1u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d98cd95c                       3u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_dedcc96f                       3u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_efc3e236                       7u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f76356d0                       10u     /**< [Right] */
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_BeltAdj_FL_Stat_ST3_71e5093a_Tx          0u      /**< [Left] */
#define PduRConf_PduRDestPdu_BeltAdj_FR_Stat_ST3_2b5906f9_Tx          0u      /**< [Right] */
#define PduRConf_PduRDestPdu_Develop8_Rs_RBTM_FL_ST3_711f265e_Tx      1u      /**< [Left] */
#define PduRConf_PduRDestPdu_Develop8_Rs_RBTM_FR_ST3_aaf2c54f_Tx      1u      /**< [Right] */
#define PduRConf_PduRDestPdu_ECU_Stat_RBTM_FL_ST3_42655720_Tx         2u      /**< [Left] */
#define PduRConf_PduRDestPdu_ECU_Stat_RBTM_FR_ST3_9988b431_Tx         2u      /**< [Right] */
#define PduRConf_PduRDestPdu_Meas8_RBTM_FL_ST3_b4f3e350_Tx            3u      /**< [Left] */
#define PduRConf_PduRDestPdu_Meas8_RBTM_FR_ST3_6f1e0041_Tx            3u      /**< [Right] */
#define PduRConf_PduRDestPdu_NM_RBTM_FL_ST3_0cdf2d0f_Tx_78db9cf2_Tx   4u      /**< [Left] */
#define PduRConf_PduRDestPdu_NM_RBTM_FR_ST3_d30f04ec_Tx_2c5f6cda_Tx   4u      /**< [Right] */
#define PduRConf_PduRDestPdu_RBTM_FL_Stat_ST3_d76d14af_Tx             5u      /**< [Left] */
#define PduRConf_PduRDestPdu_RBTM_FL_Tens_ST3_49d8a970_Tx             6u      /**< [Left] */
#define PduRConf_PduRDestPdu_RBTM_FR_Stat_ST3_8dd11b6c_Tx             5u      /**< [Right] */
#define PduRConf_PduRDestPdu_RBTM_FR_Tens_ST3_1364a6b3_Tx             6u      /**< [Right] */
#define PduRConf_PduRDestPdu_ROE_RBTM_FL_ST3_75ad963a_Tx              7u      /**< [Left] */
#define PduRConf_PduRDestPdu_ROE_RBTM_FR_ST3_ae40752b_Tx              7u      /**< [Right] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx_a44b5ded_Rx 3u /**< [Left] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx_80d1f2da_Rx 4u /**< [Left] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx_03bff274_Rx 5u /**< [Left] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx_7beeea72_Rx 3u /**< [Right] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx_4d07a2cf_Rx 4u /**< [Right] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx_8aa11052_Rx 5u /**< [Right] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx 0u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx 1u /**< [Left, Right] */
#define PduRConf_PduRDestPdu_SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx 2u /**< [Left, Right] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4d07a2cf                       4u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7beeea72                       3u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8aa11052                       5u      /**< [Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_03bff274                       5u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_80d1f2da                       4u      /**< [Left] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a44b5ded                       3u      /**< [Left] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0e266b08                       1u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1a629478                       2u      /**< [Left, Right] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_19a79fac                       0u      /**< [Left, Right] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx 0u /**< [Left] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx 1u /**< [Left] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx 2u /**< [Left] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx 0u /**< [Right] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx 1u /**< [Right] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx 2u /**< [Right] */
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

