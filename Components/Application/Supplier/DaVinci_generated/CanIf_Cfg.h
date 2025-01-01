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
 *            Module: CanIf
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Cfg.h
 *   Generation Time: 2023-07-10 14:36:03
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined(CANIF_CFG_H)
#define CANIF_CFG_H


/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/
#include "Can.h"




/**********************************************************************************************************************
  \def  Version defines
**********************************************************************************************************************/

#define CANIF_CFG5_VERSION                                 0x0504u
#define CANIF_CFG5_RELEASE_VERSION                         0x00u
#define IF_ASRIFCAN_GENTOOL_CFG5_MAJOR_VERSION             0x05u
#define IF_ASRIFCAN_GENTOOL_CFG5_MINOR_VERSION             0x04u
#define IF_ASRIFCAN_GENTOOL_CFG5_PATCH_VERSION             0x00u

#define CANIF_CFG5_GENERATOR_COMPATIBILITY_VERSION         0x0212u

/**********************************************************************************************************************
  \def  Switches
**********************************************************************************************************************/

#define CANIF_TRANSMIT_BUFFER                              STD_ON /* Signals if Tx-buffer is enabled at all in CanIf. The value is determined from parameter "CanIfPublicTxBuffering". */
#define CANIF_TRANSMIT_BUFFER_PRIO_BY_CANID                STD_ON
#define CANIF_TRANSMIT_BUFFER_FIFO                         STD_OFF
#define CANIF_BITQUEUE                                     STD_ON
#define CANIF_STATIC_FD_TXQUEUE                            STD_OFF
#define CANIF_WAKEUP_SUPPORT                               STD_ON
#define CANIF_WAKEUP_VALIDATION                            STD_ON
#define CANIF_WAKEUP_VALID_ALL_RX_MSGS                     STD_OFF
#define CANIF_WAKEUP_VALID_ONLY_NM_RX_MSGS                 STD_OFF
#define CANIF_CHECK_WAKEUP_CAN_RET_TYPE                    STD_OFF
#define CANIF_DEV_ERROR_DETECT                             STD_ON
#define CANIF_DEV_ERROR_REPORT                             STD_OFF
#define CANIF_TRANSMIT_CANCELLATION                        STD_OFF
#define CANIF_CANCEL_SUPPORT_API                           STD_ON
#define CANIF_VERSION_INFO_API                             STD_OFF
#define CANIF_DLC_CHECK                                    STD_OFF
#define CANIF_SUPPORT_NMOSEK_INDICATION                    STD_OFF
#define CANIF_TRCV_HANDLING                                STD_OFF
#define CANIF_TRCV_MAPPING                                 STD_OFF
#define CANIF_PN_TRCV_HANDLING                             STD_OFF
#define CANIF_EXTENDEDID_SUPPORT                           STD_ON
#define CANIF_SETDYNAMICTXID_API                           STD_OFF
#define CANIF_PN_WU_TX_PDU_FILTER                          STD_OFF
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_OFF
#define CANIF_RX_INDICATION_TYPE_I_IS_USED                 STD_OFF
#define CANIF_RX_INDICATION_TYPE_IV_IS_USED                STD_OFF
#define CANIF_CHANGE_BAUDRATE_SUPPORT                      STD_OFF
#define CANIF_SET_BAUDRATE_API                             STD_OFF
#define CANIF_META_DATA_RX_SUPPORT                         STD_OFF
#define CANIF_META_DATA_TX_SUPPORT                         STD_OFF
#define CANIF_J1939_DYN_ADDR_SUPPORT                       CANIF_J1939_DYN_ADDR_DISABLED
#define CANIF_MULTIPLE_CANDRV_SUPPORT                      STD_OFF
#define CANIF_RX_SEARCH_CONSIDER_MSG_TYPE                  STD_OFF
#define CANIF_ECUC_SAFE_BSW_CHECKS                         STD_ON
#define CANIF_EXTENDED_RAM_CHECK_SUPPORT                   STD_OFF
#define CANIF_DATA_CHECKSUM_RX_SUPPORT                     STD_OFF
#define CANIF_DATA_CHECKSUM_TX_SUPPORT                     STD_OFF
#define CANIF_SET_PDU_RECEPTION_MODE_SUPPORT               STD_OFF
#define CANIF_BUS_MIRRORING_SUPPORT                        STD_OFF
#define CANIF_ENABLE_SECURITY_EVENT_REPORTING              STD_OFF
#define CANIF_SUPPORT_CANDRV_ASR440                        STD_OFF
#define CANIF_SUPPORT_MULTIPARTITION                       STD_OFF

#define CANIF_SUPPRESS_EXTENDED_VERSION_CHECK

#ifndef CANIF_USE_DUMMY_STATEMENT
#define CANIF_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT
#define CANIF_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT_CONST
#define CANIF_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANIF_ATOMIC_VARIABLE_ACCESS
#define CANIF_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANIF_PROCESSOR_TC322L
#define CANIF_PROCESSOR_TC322L
#endif
#ifndef CANIF_COMP_TASKING
#define CANIF_COMP_TASKING
#endif
#ifndef CANIF_GEN_GENERATOR_MSR
#define CANIF_GEN_GENERATOR_MSR
#endif
#ifndef CANIF_CPUTYPE_BITORDER_LSB2MSB
#define CANIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#define CANIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_LINKTIME
#define CANIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANIF_CONFIGURATION_VARIANT
#define CANIF_CONFIGURATION_VARIANT CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANIF_POSTBUILD_VARIANT_SUPPORT
#define CANIF_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


#define CANIF_CPU_TYPE_SET_IN_ECUC_MODULE                  CPU_TYPE_32

/**********************************************************************************************************************
  \def  Search algorithm
**********************************************************************************************************************/
#define CANIF_SEARCH_ALGORITHM                             CANIF_LINEAR


/**********************************************************************************************************************
  \def  Configuration variant
**********************************************************************************************************************/
#define CANIF_CONFIG_VARIANT                               CANIF_CFGVAR_PRECOMPILETIME


/**********************************************************************************************************************
  Type definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
  \def  Tx-buffer - queue size type
**********************************************************************************************************************/
typedef uint8 CanIf_TxBufferSizeType;


/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
#include "CanIf_Types.h"

/**********************************************************************************************************************
  \def  Memory mapping keywords
**********************************************************************************************************************/
#define CANIF_XCFG                                         CANIF_CONST
#define CANIF_VAR_XCFG_NOINIT                              CANIF_VAR_NOINIT


/**********************************************************************************************************************
  \def  Invalid PDU handle
**********************************************************************************************************************/
#define CanIf_TxPduHnd_INVALID                             0xFFu
#define CanIf_RxPduHnd_INVALID                             0xFFu


/**********************************************************************************************************************
  \def  Tx-buffer - handling types
**********************************************************************************************************************/
#define CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID                                                             1u
#define CANIF_TXBUFFER_HANDLINGTYPE_FIFO                                                                    2u
#define CANIF_TXBUFFER_HANDLINGTYPE_NONE                                                                    3u



/**********************************************************************************************************************
  \def  CAN controller - symbolic handles
**********************************************************************************************************************/

#define CanIfConf_CanIfCtrlCfg_RBTM_FL_BODY3_180ddaa4                                               0u
#define CanIfConf_CanIfCtrlCfg_RBTM_FR_BODY3_2fec3d37                                               0u








/**********************************************************************************************************************
  \def  Tx PDU handles
**********************************************************************************************************************/

#define CanIfTxPduHnd_BeltAdj_FR_Stat_ST3_070be586_Tx                                               0u
#define CanIfTxPduHnd_BeltAdj_FL_Stat_ST3_df27ce55_Tx                                               0u
#define CanIfTxPduHnd_DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx                                     1u
#define CanIfTxPduHnd_DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx                                     1u
#define CanIfTxPduHnd_DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx                                     2u
#define CanIfTxPduHnd_DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx                                     2u
#define CanIfTxPduHnd_DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx                                     3u
#define CanIfTxPduHnd_DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx                                     3u
#define CanIfTxPduHnd_Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx                                           4u
#define CanIfTxPduHnd_Develop8_Rs_RBTM_FR_ST3_1a924f62_Tx                                           4u
#define CanIfTxPduHnd_ECU_Stat_RBTM_FR_ST3_430ba797_Tx                                              5u
#define CanIfTxPduHnd_ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx                                              5u
#define CanIfTxPduHnd_Meas8_RBTM_FL_ST3_a87f4b23_Tx                                                 6u
#define CanIfTxPduHnd_Meas8_RBTM_FR_ST3_492d97af_Tx                                                 6u
#define CanIfTxPduHnd_NM_RBTM_FR_ST3_d6dddcba_Tx                                                    7u
#define CanIfTxPduHnd_NM_RBTM_FL_ST3_8b5cec70_Tx                                                    7u
#define CanIfTxPduHnd_RBTM_FL_Stat_ST3_558a33d8_Tx                                                  8u
#define CanIfTxPduHnd_RBTM_FR_Stat_ST3_b20121fa_Tx                                                  8u
#define CanIfTxPduHnd_RBTM_FL_Tens_ST3_1446be6f_Tx                                                  9u
#define CanIfTxPduHnd_RBTM_FR_Tens_ST3_019feca0_Tx                                                  9u
#define CanIfTxPduHnd_ROE_RBTM_FL_ST3_e9956dfc_Tx                                                   10u
#define CanIfTxPduHnd_ROE_RBTM_FR_ST3_d7dfdf54_Tx                                                   10u


/**********************************************************************************************************************
  \def  Rx PDU handles (Rx indication function specific ones)
**********************************************************************************************************************/

/* These definitions can change at Post-build configuration time. Use them wisely. */
/* Assigned to: NULL_PTR*/
/* Assigned to: CanNm_RxIndication*/
#define CanIfRxPduHnd_RBTM_FL_BODY3NMNODE_032841d9_Rx                                               0u
#define CanIfRxPduHnd_RBTM_FL_BODY3NMNODE_032841d9_Rx_Left                                          0u
#define CanIfRxPduHnd_RBTM_FR_BODY3NMNODE_65b97d54_Rx                                               0u
#define CanIfRxPduHnd_RBTM_FR_BODY3NMNODE_65b97d54_Rx_Right                                         0u
/* Assigned to: CanTSyn_RxIndication*/
#define CanIfRxPduHnd_GTS_Main_CAN_ST3_007ffebc_Rx                                                  0u
#define CanIfRxPduHnd_GTS_Main_CAN_ST3_007ffebc_Rx_Left                                             0u
#define CanIfRxPduHnd_GTS_Main_CAN_ST3_007ffebc_Rx_Right                                            0u
/* Assigned to: CanTp_RxIndication*/
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx                                         0u
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx_Left                                    0u
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx_Right                                   0u
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx                                         1u
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx_Left                                    1u
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx_Right                                   1u
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx                                         2u
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx_Left                                    2u
#define CanIfRxPduHnd_DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx_Right                                   2u
#define CanIfRxPduHnd_DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx                                     3u
#define CanIfRxPduHnd_DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx_Left                                3u
#define CanIfRxPduHnd_DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx                                     4u
#define CanIfRxPduHnd_DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx_Left                                4u
#define CanIfRxPduHnd_DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx                                     5u
#define CanIfRxPduHnd_DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx_Left                                5u
#define CanIfRxPduHnd_DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx                                     3u
#define CanIfRxPduHnd_DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx_Right                               3u
#define CanIfRxPduHnd_DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx                                     4u
#define CanIfRxPduHnd_DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx_Right                               4u
#define CanIfRxPduHnd_DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx                                     5u
#define CanIfRxPduHnd_DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx_Right                               5u
/* Assigned to: PduR_CanIfRxIndication*/
#define CanIfRxPduHnd_ADAS_PREDICTION_ST3_7c36fc01_Rx                                               0u
#define CanIfRxPduHnd_ADAS_PREDICTION_ST3_7c36fc01_Rx_Left                                          0u
#define CanIfRxPduHnd_ADAS_PREDICTION_ST3_7c36fc01_Rx_Right                                         0u
#define CanIfRxPduHnd_EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx                                         1u
#define CanIfRxPduHnd_EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx_Left                                    1u
#define CanIfRxPduHnd_EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx_Right                                   1u
#define CanIfRxPduHnd_DIAG_Stat_ST3_7f697120_Rx                                                     2u
#define CanIfRxPduHnd_DIAG_Stat_ST3_7f697120_Rx_Left                                                2u
#define CanIfRxPduHnd_DIAG_Stat_ST3_7f697120_Rx_Right                                               2u
#define CanIfRxPduHnd_ELC_Lvr_Stat_ST3_secured_612a2882_Rx                                          3u
#define CanIfRxPduHnd_ELC_Lvr_Stat_ST3_secured_612a2882_Rx_Left                                     3u
#define CanIfRxPduHnd_ELC_Lvr_Stat_ST3_secured_612a2882_Rx_Right                                    3u
#define CanIfRxPduHnd_NTG_Master_Navi_ST3_1e826461_Rx                                               4u
#define CanIfRxPduHnd_NTG_Master_Navi_ST3_1e826461_Rx_Left                                          4u
#define CanIfRxPduHnd_NTG_Master_Navi_ST3_1e826461_Rx_Right                                         4u
#define CanIfRxPduHnd_DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx                                              5u
#define CanIfRxPduHnd_DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx_Left                                         5u
#define CanIfRxPduHnd_DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx_Right                                        5u
#define CanIfRxPduHnd_Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx                                       6u
#define CanIfRxPduHnd_Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx_Left                                  6u
#define CanIfRxPduHnd_Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx_Right                                 6u
#define CanIfRxPduHnd_BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx                                             7u
#define CanIfRxPduHnd_BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx_Left                                        7u
#define CanIfRxPduHnd_BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx_Right                                       7u
#define CanIfRxPduHnd_BeltAdj_FR_Stat_ST3_070be586_Rx                                               8u
#define CanIfRxPduHnd_BeltAdj_FR_Stat_ST3_070be586_Rx_Left                                          8u
#define CanIfRxPduHnd_RBTM_FR_Stat_ST3_b20121fa_Rx                                                  9u
#define CanIfRxPduHnd_RBTM_FR_Stat_ST3_b20121fa_Rx_Left                                             9u
#define CanIfRxPduHnd_ADAS_POSITION_ST3_bc4541a2_Rx                                                 10u
#define CanIfRxPduHnd_ADAS_POSITION_ST3_bc4541a2_Rx_Left                                            10u
#define CanIfRxPduHnd_ADAS_POSITION_ST3_bc4541a2_Rx_Right                                           10u
#define CanIfRxPduHnd_PresfAct_Adj_ST3_87d3ccaf_Rx                                                  11u
#define CanIfRxPduHnd_PresfAct_Adj_ST3_87d3ccaf_Rx_Left                                             11u
#define CanIfRxPduHnd_PresfAct_Adj_ST3_87d3ccaf_Rx_Right                                            11u
#define CanIfRxPduHnd_Develop8_Rq_RBTM_FL_ST3_fe216789_Rx                                           12u
#define CanIfRxPduHnd_Develop8_Rq_RBTM_FL_ST3_fe216789_Rx_Left                                      12u
#define CanIfRxPduHnd_BeltHdOvr_FL_State_ST3_b4846ceb_Rx                                            13u
#define CanIfRxPduHnd_BeltHdOvr_FL_State_ST3_b4846ceb_Rx_Left                                       13u
#define CanIfRxPduHnd_CLkS_Dr_State_ST3_27f55e1e_Rx                                                 14u
#define CanIfRxPduHnd_CLkS_Dr_State_ST3_27f55e1e_Rx_Left                                            14u
#define CanIfRxPduHnd_CLkS_Dr_State_ST3_27f55e1e_Rx_Right                                           14u
#define CanIfRxPduHnd_PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx                                       15u
#define CanIfRxPduHnd_PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx_Left                                  15u
#define CanIfRxPduHnd_PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx_Right                                 15u
#define CanIfRxPduHnd_DI_OdoSpeedometer_ST3_11e98e6f_Rx                                             16u
#define CanIfRxPduHnd_DI_OdoSpeedometer_ST3_11e98e6f_Rx_Left                                        16u
#define CanIfRxPduHnd_DI_OdoSpeedometer_ST3_11e98e6f_Rx_Right                                       16u
#define CanIfRxPduHnd_ADAS_PROFILE_SHORT_ST3_7ff16020_Rx                                            17u
#define CanIfRxPduHnd_ADAS_PROFILE_SHORT_ST3_7ff16020_Rx_Left                                       17u
#define CanIfRxPduHnd_ADAS_PROFILE_SHORT_ST3_7ff16020_Rx_Right                                      17u
#define CanIfRxPduHnd_Impact3_ST3_c1d5b894_Rx                                                       18u
#define CanIfRxPduHnd_Impact3_ST3_c1d5b894_Rx_Left                                                  18u
#define CanIfRxPduHnd_Impact3_ST3_c1d5b894_Rx_Right                                                 18u
#define CanIfRxPduHnd_PN14_Master_Stat1_ST3_56fd286b_Rx                                             19u
#define CanIfRxPduHnd_PN14_Master_Stat1_ST3_56fd286b_Rx_Left                                        19u
#define CanIfRxPduHnd_PN14_Master_Stat1_ST3_56fd286b_Rx_Right                                       19u
#define CanIfRxPduHnd_Impact2_ST3_e5526ccc_Rx                                                       20u
#define CanIfRxPduHnd_Impact2_ST3_e5526ccc_Rx_Left                                                  20u
#define CanIfRxPduHnd_Impact2_ST3_e5526ccc_Rx_Right                                                 20u
#define CanIfRxPduHnd_PT4_PTCoor4_ST3_59056fb4_Rx                                                   21u
#define CanIfRxPduHnd_PT4_PTCoor4_ST3_59056fb4_Rx_Left                                              21u
#define CanIfRxPduHnd_PT4_PTCoor4_ST3_59056fb4_Rx_Right                                             21u
#define CanIfRxPduHnd_SBeltTens_SP_Lvl_ST3_7cf5644e_Rx                                              22u
#define CanIfRxPduHnd_SBeltTens_SP_Lvl_ST3_7cf5644e_Rx_Left                                         22u
#define CanIfRxPduHnd_SBeltTens_SP_Lvl_ST3_7cf5644e_Rx_Right                                        22u
#define CanIfRxPduHnd_PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx                                           23u
#define CanIfRxPduHnd_PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx_Left                                      23u
#define CanIfRxPduHnd_PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx_Right                                     23u
#define CanIfRxPduHnd_VSS_TP_SharedSecret_ST3_70962814_Rx                                           24u
#define CanIfRxPduHnd_VSS_TP_SharedSecret_ST3_70962814_Rx_Left                                      24u
#define CanIfRxPduHnd_VSS_TP_SharedSecret_ST3_70962814_Rx_Right                                     24u
#define CanIfRxPduHnd_VSS_TP_Auth_ST3_1d67253f_Rx                                                   25u
#define CanIfRxPduHnd_VSS_TP_Auth_ST3_1d67253f_Rx_Left                                              25u
#define CanIfRxPduHnd_VSS_TP_Auth_ST3_1d67253f_Rx_Right                                             25u
#define CanIfRxPduHnd_VSS_TP_VIN_ST3_b3b4e778_Rx                                                    26u
#define CanIfRxPduHnd_VSS_TP_VIN_ST3_b3b4e778_Rx_Left                                               26u
#define CanIfRxPduHnd_VSS_TP_VIN_ST3_b3b4e778_Rx_Right                                              26u
#define CanIfRxPduHnd_VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx                                      27u
#define CanIfRxPduHnd_VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx_Left                                 27u
#define CanIfRxPduHnd_VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx_Right                                27u
#define CanIfRxPduHnd_VSS_TP_RealTmOffset_ST3_012f1a71_Rx                                           28u
#define CanIfRxPduHnd_VSS_TP_RealTmOffset_ST3_012f1a71_Rx_Left                                      28u
#define CanIfRxPduHnd_VSS_TP_RealTmOffset_ST3_012f1a71_Rx_Right                                     28u
#define CanIfRxPduHnd_Ign_Stat_ST3_secured_07d79dc2_Rx                                              29u
#define CanIfRxPduHnd_Ign_Stat_ST3_secured_07d79dc2_Rx_Left                                         29u
#define CanIfRxPduHnd_Ign_Stat_ST3_secured_07d79dc2_Rx_Right                                        29u
#define CanIfRxPduHnd_BeltAdj_FL_Stat_ST3_df27ce55_Rx                                               8u
#define CanIfRxPduHnd_BeltAdj_FL_Stat_ST3_df27ce55_Rx_Right                                         8u
#define CanIfRxPduHnd_RBTM_FL_Stat_ST3_558a33d8_Rx                                                  9u
#define CanIfRxPduHnd_RBTM_FL_Stat_ST3_558a33d8_Rx_Right                                            9u
#define CanIfRxPduHnd_Develop8_Rq_RBTM_FR_ST3_197eb912_Rx                                           12u
#define CanIfRxPduHnd_Develop8_Rq_RBTM_FR_ST3_197eb912_Rx_Right                                     12u
#define CanIfRxPduHnd_BeltHdOvr_FR_State_ST3_61b04b2f_Rx                                            13u
#define CanIfRxPduHnd_BeltHdOvr_FR_State_ST3_61b04b2f_Rx_Right                                      13u



/**********************************************************************************************************************
  \def  AUTOSAR Tx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfTxPduCfg_BeltAdj_FR_Stat_ST3_070be586_Tx                                     0u
#define CanIfConf_CanIfTxPduCfg_BeltAdj_FL_Stat_ST3_df27ce55_Tx                                     0u
#define CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx                           1u
#define CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx                           1u
#define CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx                           2u
#define CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx                           2u
#define CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx                           3u
#define CanIfConf_CanIfTxPduCfg_DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx                           3u
#define CanIfConf_CanIfTxPduCfg_Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx                                 4u
#define CanIfConf_CanIfTxPduCfg_Develop8_Rs_RBTM_FR_ST3_1a924f62_Tx                                 4u
#define CanIfConf_CanIfTxPduCfg_ECU_Stat_RBTM_FR_ST3_430ba797_Tx                                    5u
#define CanIfConf_CanIfTxPduCfg_ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx                                    5u
#define CanIfConf_CanIfTxPduCfg_Meas8_RBTM_FL_ST3_a87f4b23_Tx                                       6u
#define CanIfConf_CanIfTxPduCfg_Meas8_RBTM_FR_ST3_492d97af_Tx                                       6u
#define CanIfConf_CanIfTxPduCfg_NM_RBTM_FR_ST3_d6dddcba_Tx                                          7u
#define CanIfConf_CanIfTxPduCfg_NM_RBTM_FL_ST3_8b5cec70_Tx                                          7u
#define CanIfConf_CanIfTxPduCfg_RBTM_FL_Stat_ST3_558a33d8_Tx                                        8u
#define CanIfConf_CanIfTxPduCfg_RBTM_FR_Stat_ST3_b20121fa_Tx                                        8u
#define CanIfConf_CanIfTxPduCfg_RBTM_FL_Tens_ST3_1446be6f_Tx                                        9u
#define CanIfConf_CanIfTxPduCfg_RBTM_FR_Tens_ST3_019feca0_Tx                                        9u
#define CanIfConf_CanIfTxPduCfg_ROE_RBTM_FL_ST3_e9956dfc_Tx                                         10u
#define CanIfConf_CanIfTxPduCfg_ROE_RBTM_FR_ST3_d7dfdf54_Tx                                         10u


/**********************************************************************************************************************
  \def  AUTOSAR Rx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfRxPduCfg_ADAS_POSITION_ST3_bc4541a2_Rx                                       0u
#define CanIfConf_CanIfRxPduCfg_ADAS_PREDICTION_ST3_7c36fc01_Rx                                     1u
#define CanIfConf_CanIfRxPduCfg_ADAS_PROFILE_SHORT_ST3_7ff16020_Rx                                  2u
#define CanIfConf_CanIfRxPduCfg_Bckl_Sw_Fx_Stat_ST3_secured_b4b7136c_Rx                             3u
#define CanIfConf_CanIfRxPduCfg_BeltAdj_UI_Set_Rq_ST3_0cef232d_Rx                                   4u
#define CanIfConf_CanIfRxPduCfg_CLkS_Dr_State_ST3_27f55e1e_Rx                                       5u
#define CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtCAN_ST3_c34d4a41_Rx                               6u
#define CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_ExtEth_ST3_c52e42e8_Rx                               7u
#define CanIfConf_CanIfRxPduCfg_DIAG_RQ_GLOBAL_IntEth_ST3_dc07327b_Rx                               8u
#define CanIfConf_CanIfRxPduCfg_DIAG_Stat_ST3_7f697120_Rx                                           9u
#define CanIfConf_CanIfRxPduCfg_DI_OdoSpeedometer_ST3_11e98e6f_Rx                                   10u
#define CanIfConf_CanIfRxPduCfg_DPC_Md_Rq_ESP_d1_ST3_92dc8d11_Rx                                    11u
#define CanIfConf_CanIfRxPduCfg_ELC_Lvr_Stat_ST3_secured_612a2882_Rx                                12u
#define CanIfConf_CanIfRxPduCfg_EVC_CfgList_01_08_Pr5_ST3_2e9e0d1a_Rx                               13u
#define CanIfConf_CanIfRxPduCfg_GTS_Main_CAN_ST3_007ffebc_Rx                                        14u
#define CanIfConf_CanIfRxPduCfg_Ign_Stat_ST3_secured_07d79dc2_Rx                                    15u
#define CanIfConf_CanIfRxPduCfg_Impact2_ST3_e5526ccc_Rx                                             16u
#define CanIfConf_CanIfRxPduCfg_Impact3_ST3_c1d5b894_Rx                                             17u
#define CanIfConf_CanIfRxPduCfg_NTG_Master_Navi_ST3_1e826461_Rx                                     18u
#define CanIfConf_CanIfRxPduCfg_PN14_Master_Stat1_ST3_56fd286b_Rx                                   19u
#define CanIfConf_CanIfRxPduCfg_PT4_PTCoor4_ST3_59056fb4_Rx                                         20u
#define CanIfConf_CanIfRxPduCfg_PT4_PTCoor9_d1_BC_F_ST3_4460ebae_Rx                                 21u
#define CanIfConf_CanIfRxPduCfg_PT4_PTCoor_DrvPosn_Gear_ST3_aabed571_Rx                             22u
#define CanIfConf_CanIfRxPduCfg_PresfAct_Adj_ST3_87d3ccaf_Rx                                        23u
#define CanIfConf_CanIfRxPduCfg_SBeltTens_SP_Lvl_ST3_7cf5644e_Rx                                    24u
#define CanIfConf_CanIfRxPduCfg_VSS_TP_Auth_ST3_1d67253f_Rx                                         25u
#define CanIfConf_CanIfRxPduCfg_VSS_TP_RealTmOffset_ST3_012f1a71_Rx                                 26u
#define CanIfConf_CanIfRxPduCfg_VSS_TP_SecTickCount_Lvl2_ST3_2123eaf8_Rx                            27u
#define CanIfConf_CanIfRxPduCfg_VSS_TP_SharedSecret_ST3_70962814_Rx                                 28u
#define CanIfConf_CanIfRxPduCfg_VSS_TP_VIN_ST3_b3b4e778_Rx                                          29u
#define CanIfConf_CanIfRxPduCfg_BeltAdj_FL_Stat_ST3_df27ce55_Rx                                     30u
#define CanIfConf_CanIfRxPduCfg_BeltAdj_FR_Stat_ST3_070be586_Rx                                     30u
#define CanIfConf_CanIfRxPduCfg_BeltHdOvr_FL_State_ST3_b4846ceb_Rx                                  31u
#define CanIfConf_CanIfRxPduCfg_BeltHdOvr_FR_State_ST3_61b04b2f_Rx                                  31u
#define CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_ExtCAN_RQ_ST3_688ae269_Rx                           32u
#define CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_ExtCAN_RQ_ST3_72fbd255_Rx                           32u
#define CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_ExtEth_RQ_ST3_89267c36_Rx                           33u
#define CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_ExtEth_RQ_ST3_0a9e12f4_Rx                           33u
#define CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FL_03_IntEth_RQ_ST3_91813a5c_Rx                           34u
#define CanIfConf_CanIfRxPduCfg_DIAG_RBTM_FR_03_IntEth_RQ_ST3_fad47561_Rx                           34u
#define CanIfConf_CanIfRxPduCfg_Develop8_Rq_RBTM_FL_ST3_fe216789_Rx                                 35u
#define CanIfConf_CanIfRxPduCfg_Develop8_Rq_RBTM_FR_ST3_197eb912_Rx                                 35u
#define CanIfConf_CanIfRxPduCfg_RBTM_FL_BODY3NMNODE_032841d9_Rx                                     36u
#define CanIfConf_CanIfRxPduCfg_RBTM_FL_Stat_ST3_558a33d8_Rx                                        36u
#define CanIfConf_CanIfRxPduCfg_RBTM_FR_BODY3NMNODE_65b97d54_Rx                                     37u
#define CanIfConf_CanIfRxPduCfg_RBTM_FR_Stat_ST3_b20121fa_Rx                                        37u



/**********************************************************************************************************************
  \def  Tx buffer type
**********************************************************************************************************************/

#define CanIfTxBufferType                    BIT_QUEUE

/**********************************************************************************************************************
  \def  For ASR4.0.3/ASR4.2.2 compatibility - indirection macros
**********************************************************************************************************************/
#define  CanIf_RxIndication(Hrh, CanId, CanDlc, CanSduPtr) CanIf_RxIndicationAsr403((Hrh), (CanId), (CanDlc), (CanSduPtr)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */









/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/


/* Coded in RxPduCanId of table CanIf_RxPduConfig[] */
#define CANIF_MASKCODE_RANGE_FLAG                                                                   0x20000000u
#define CANIF_FD_FLAG                                                                               0x40000000u
#define CANIF_FD_FLAG_MASKOUT                                                                       0xBFFFFFFFu
#define CANIF_FD_FLAG_SHIFTPOS                                                                      30u
/* Coded in RxPduMask of table CanIf_RxPduConfig[] */
#define CANIF_STOP_FLAG                                                                             0x40000000u
#define CANIF_RANGE_FLAG                                                                            0x20000000u
#define CANIF_STOP_RANGE_FLAG                                                                       0x60000000u
#define CANIF_STOP_RANGE_FLAG_MASKOUT                                                               0x9FFFFFFFu


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCDataSwitches  CanIf Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_BUSOFFNOTIFICATIONFCTPTR                                                              STD_ON
#define CANIF_CANCONTROLLERIDUPTOLOWMAP                                                             STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLIDXOFCANCONTROLLERIDUPTOLOWMAP                                            STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLUSEDOFCANCONTROLLERIDUPTOLOWMAP                                           STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CONTROLLEROFCANCONTROLLERIDUPTOLOWMAP                                                 STD_OFF  /**< Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanControllerIdUpToLowMap.Controller' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBL                                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANCELTXFCTOFCANDRVFCTTBL                                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CancelTxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CancelTxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHANGEBAUDRATEFCTOFCANDRVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKBAUDRATEFCTOFCANDRVFCTTBL                                                        STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANDRVFCTTBL                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERERRORSTATEFCTOFCANDRVFCTTBL                                              STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerErrorStateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERRXERRORCOUNTEROFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerRxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_GETCONTROLLERTXERRORCOUNTEROFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.GetControllerTxErrorCounter' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLECONTROLLERFCTOFCANDRVFCTTBL                                             STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLEMAILBOXFCTOFCANDRVFCTTBL                                                STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKEXECUTEFCTOFCANDRVFCTTBL                                                      STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETBAUDRATEFCTOFCANDRVFCTTBL                                                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETCONTROLLERMODEFCTOFCANDRVFCTTBL                                                    STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_WRITEFCTOFCANDRVFCTTBL                                                                STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                                     STD_ON
#define CANIF_INVALIDHNDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                         STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfig.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' and Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfig.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' */
#define CANIF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                        STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                      STD_ON
#define CANIF_CANTRCVFCTTBL                                                                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEFLAGFCTOFCANTRCVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANTRCVFCTTBL                                                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CLEARTRCVWUFFLAGFCTOFCANTRCVFCTTBL                                                    STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETBUSWUREASONFCTOFCANTRCVFCTTBL                                                      STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETOPMODEFCTOFCANTRCVFCTTBL                                                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETOPMODEFCTOFCANTRCVFCTTBL                                                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETWAKEUPMODEFCTOFCANTRCVFCTTBL                                                       STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CTRLCONFIG                                                                            STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_FEATUREPNWUTXPDUFILTERENABLEDOFCTRLCONFIG                                             STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_J1939DYNADDROFFSETOFCTRLCONFIG                                                        STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_J1939DYNADDRSUPPORTOFCTRLCONFIG                                                       STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXDHRANDOMNUMBER1OFCTRLCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXDHRANDOMNUMBER2OFCTRLCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' and Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_CTRLMODEINDICATIONFCTPTR                                                              STD_ON
#define CANIF_CTRLSTATES                                                                            STD_ON
#define CANIF_CTRLMODEOFCTRLSTATES                                                                  STD_ON
#define CANIF_PDUMODEOFCTRLSTATES                                                                   STD_ON
#define CANIF_WAKEUPVALIDATIONSTATEOFCTRLSTATES                                                     STD_ON
#define CANIF_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'CanIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSION                                                         STD_ON
#define CANIF_GENERATORVERSION                                                                      STD_ON
#define CANIF_HXHOFFSET                                                                             STD_OFF  /**< Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' and Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'CanIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIG                                                                         STD_ON
#define CANIF_CTRLSTATESIDXOFMAILBOXCONFIG                                                          STD_ON
#define CANIF_MAILBOXTYPEOFMAILBOXCONFIG                                                            STD_ON
#define CANIF_PDUIDFIRSTOFMAILBOXCONFIG                                                             STD_ON
#define CANIF_PDUIDLASTOFMAILBOXCONFIG                                                              STD_ON
#define CANIF_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                         STD_ON
#define CANIF_TXBUFFERCFGOFMAILBOXCONFIG                                                            STD_ON
#define CANIF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                        STD_ON
#define CANIF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                                   STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIG                                                                 STD_ON
#define CANIF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                               STD_ON
#define CANIF_MAXWAKEUPSOURCES                                                                      STD_ON
#define CANIF_PDURXMODE                                                                             STD_OFF  /**< Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANIF_RXDHADJUST                                                                            STD_OFF  /**< Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' and Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' */
#define CANIF_RXINDICATIONFCTLIST                                                                   STD_ON
#define CANIF_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                                  STD_ON
#define CANIF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                               STD_ON
#define CANIF_RXPDUCONFIG                                                                           STD_ON
#define CANIF_CANIFRXPDUIDOFRXPDUCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigLeft.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRight.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_ISCANNMRXPDUOFRXPDUCONFIG                                                             STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigLeft.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRight.IsCanNmRxPdu' Reason: 'Wakeup validation only by CAN-Nm Rx-PDUs is deactivated.' */
#define CANIF_ISDATACHECKSUMRXPDUOFRXPDUCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigLeft.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRight.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_MSGTYPEOFRXPDUCONFIG                                                                  STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigLeft.MsgType' Reason: '"CanIfRxSearchConsiderMsgType" is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRight.MsgType' Reason: '"CanIfRxSearchConsiderMsgType" is deactivated.' */
#define CANIF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                                   STD_ON
#define CANIF_RXMETADATALENGTHOFRXPDUCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfigLeft.RxMetaDataLength' Reason: 'Rx meta data support is deactivated.' and Deactivateable: 'CanIf_RxPduConfigRight.RxMetaDataLength' Reason: 'Rx meta data support is deactivated.' */
#define CANIF_RXPDUCANIDOFRXPDUCONFIG                                                               STD_ON
#define CANIF_RXPDUDLCOFRXPDUCONFIG                                                                 STD_ON
#define CANIF_RXPDUMASKOFRXPDUCONFIG                                                                STD_ON
#define CANIF_UPPERPDUIDOFRXPDUCONFIG                                                               STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                                               STD_ON
#define CANIF_SIZEOFCTRLSTATES                                                                      STD_ON
#define CANIF_SIZEOFMAILBOXCONFIG                                                                   STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIG                                                           STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLIST                                                             STD_ON
#define CANIF_SIZEOFRXPDUCONFIG                                                                     STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASE                                                         STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                                               STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLIST                                                           STD_ON
#define CANIF_SIZEOFTXPDUCONFIG                                                                     STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEX                                                                 STD_ON
#define CANIF_SIZEOFTXQUEUE                                                                         STD_ON
#define CANIF_SIZEOFTXQUEUEFLAGS                                                                    STD_ON
#define CANIF_SIZEOFULTXPDUID2INTERNALTXPDUID                                                       STD_ON
#define CANIF_SIZEOFWAKEUPCONFIG                                                                    STD_ON
#define CANIF_TRANSCEIVERUPTOLOWMAP                                                                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CANTRCVFCTTBLIDXOFTRANSCEIVERUPTOLOWMAP                                               STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRANSCEIVEROFTRANSCEIVERUPTOLOWMAP                                                    STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToLowMap.Transceiver' Reason: 'CAN transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRANSCEIVERUPTOUPPERMAP                                                               STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' and Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_TRCVTOCTRLMAP                                                                         STD_OFF  /**< Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' and Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' */
#define CANIF_TXBUFFERFIFOCONFIG                                                                    STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig' Reason: 'Tx-buffer FIFO support is deactivated.' and Deactivateable: 'CanIf_TxBufferFifoConfig' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig.SizeOfOnePayloadEl' Reason: 'Tx-buffer FIFO support is deactivated.' and Deactivateable: 'CanIf_TxBufferFifoConfig.SizeOfOnePayloadEl' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBASE                                                               STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG                                                     STD_ON
#define CANIF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                               STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                         STD_ON
#define CANIF_TXQUEUEFLAGSENDIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                                 STD_ON
#define CANIF_TXQUEUEFLAGSSTARTIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                               STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                                                    STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdByteQueueConfig' Reason: 'Tx-buffer PRIO_BY_CANID support as BYTE_QUEUE is deactivated.' and Deactivateable: 'CanIf_TxBufferPrioByCanIdByteQueueConfig' Reason: 'Tx-buffer PRIO_BY_CANID support as BYTE_QUEUE is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                                              STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus' Reason: 'Tx-buffer PRIO_BY_CANID support as BYTE_QUEUE is deactivated.' and Deactivateable: 'CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus' Reason: 'Tx-buffer PRIO_BY_CANID support as BYTE_QUEUE is deactivated.' */
#define CANIF_TXCONFIRMATIONFCTLIST                                                                 STD_ON
#define CANIF_TXPDUCONFIG                                                                           STD_ON
#define CANIF_CANIDOFTXPDUCONFIG                                                                    STD_ON
#define CANIF_CANIDTXMASKOFTXPDUCONFIG                                                              STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfigLeft.CanIdTxMask' Reason: 'Tx meta data support is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRight.CanIdTxMask' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_CTRLSTATESIDXOFTXPDUCONFIG                                                            STD_ON
#define CANIF_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                                                      STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfigLeft.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRight.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' */
#define CANIF_ISPNWUTXPDUOFTXPDUCONFIG                                                              STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfigLeft.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRight.IsPnWuTxPdu' Reason: '"CanIfPnWakeupTxPduFilterSupport" is deactivated.' */
#define CANIF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                        STD_ON
#define CANIF_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                         STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                                 STD_ON
#define CANIF_TXMETADATALENGTHOFTXPDUCONFIG                                                         STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfigLeft.TxMetaDataLength' Reason: 'Tx meta data support is deactivated.' and Deactivateable: 'CanIf_TxPduConfigRight.TxMetaDataLength' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_TXPDULENGTHOFTXPDUCONFIG                                                              STD_ON
#define CANIF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                        STD_ON
#define CANIF_TXPDUQUEUEINDEX                                                                       STD_ON
#define CANIF_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                           STD_ON
#define CANIF_TXQUEUEOFTXPDUQUEUEINDEX                                                              STD_ON
#define CANIF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                          STD_ON
#define CANIF_TXPDUSTATIC2DYNAMICINDIRECTION                                                        STD_OFF  /**< Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' and Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' */
#define CANIF_TXQUEUE                                                                               STD_ON
#define CANIF_TXQUEUEFLAGS                                                                          STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOP                                                            STD_OFF  /**< Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx-buffer is deactivated.' and Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx-buffer is deactivated.' */
#define CANIF_ULRXPDUID2INTERNALRXPDUID                                                             STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_RXPDUCONFIGIDXOFULRXPDUID2INTERNALRXPDUID                                             STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_RXPDUCONFIGUSEDOFULRXPDUID2INTERNALRXPDUID                                            STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' and Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_ULTXPDUID2INTERNALTXPDUID                                                             STD_ON
#define CANIF_WAKEUPCONFIG                                                                          STD_ON
#define CANIF_CONTROLLERIDOFWAKEUPCONFIG                                                            STD_ON
#define CANIF_WAKEUPSOURCEOFWAKEUPCONFIG                                                            STD_ON
#define CANIF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                                                     STD_ON
#define CANIF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                                                      STD_ON
#define CANIF_WAKEUPVALIDATIONFCTPTR                                                                STD_ON
#define CANIF_PCCONFIG                                                                              STD_ON
#define CANIF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                                    STD_ON
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                           STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                                    STD_ON
#define CANIF_CTRLSTATESOFPCCONFIG                                                                  STD_ON
#define CANIF_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                               STD_ON
#define CANIF_GENERATORVERSIONOFPCCONFIG                                                            STD_ON
#define CANIF_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIGOFPCCONFIG                                                               STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                       STD_ON
#define CANIF_MAXWAKEUPSOURCESOFPCCONFIG                                                            STD_ON
#define CANIF_RXINDICATIONFCTLISTOFPCCONFIG                                                         STD_ON
#define CANIF_RXPDUCONFIGOFPCCONFIG                                                                 STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                     STD_ON
#define CANIF_SIZEOFCTRLSTATESOFPCCONFIG                                                            STD_ON
#define CANIF_SIZEOFMAILBOXCONFIGOFPCCONFIG                                                         STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                 STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLISTOFPCCONFIG                                                   STD_ON
#define CANIF_SIZEOFRXPDUCONFIGOFPCCONFIG                                                           STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                               STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBITQUEUECONFIGOFPCCONFIG                                     STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLISTOFPCCONFIG                                                 STD_ON
#define CANIF_SIZEOFTXPDUCONFIGOFPCCONFIG                                                           STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEXOFPCCONFIG                                                       STD_ON
#define CANIF_SIZEOFTXQUEUEFLAGSOFPCCONFIG                                                          STD_ON
#define CANIF_SIZEOFTXQUEUEOFPCCONFIG                                                               STD_ON
#define CANIF_SIZEOFULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                             STD_ON
#define CANIF_SIZEOFWAKEUPCONFIGOFPCCONFIG                                                          STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                                     STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIGOFPCCONFIG                                           STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                       STD_ON
#define CANIF_TXPDUCONFIGOFPCCONFIG                                                                 STD_ON
#define CANIF_TXPDUQUEUEINDEXOFPCCONFIG                                                             STD_ON
#define CANIF_TXQUEUEFLAGSOFPCCONFIG                                                                STD_ON
#define CANIF_TXQUEUEOFPCCONFIG                                                                     STD_ON
#define CANIF_ULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                                   STD_ON
#define CANIF_WAKEUPCONFIGOFPCCONFIG                                                                STD_ON
#define CANIF_WAKEUPVALIDATIONFCTPTROFPCCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCMinNumericValueDefines  CanIf Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CANIF_MIN_TXQUEUEFLAGS                                                                      0u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCMaxNumericValueDefines  CanIf Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CANIF_MAX_TXQUEUEFLAGS                                                                      4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCNoReferenceDefines  CanIf No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                      255u
#define CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                        255u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEnumExistsDefines  CanIf Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CANIF_EXISTS_TXBUFFERPRIOBYCANIDBITQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG                   STD_ON
#define CANIF_EXISTS_NO_TXBUFFERCFGOFMAILBOXCONFIG                                                  STD_ON
#define CANIF_EXISTS_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX                                               STD_ON
#define CANIF_EXISTS_NO_TXQUEUEOFTXPDUQUEUEINDEX                                                    STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEnumDefines  CanIf Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG                          0x00u
#define CANIF_NO_TXBUFFERCFGOFMAILBOXCONFIG                                                         0xFFu
#define CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX                                                      0x00u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIsReducedToDefineDefines  CanIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                  STD_OFF
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFMAILBOXCONFIG                                                    STD_OFF
#define CANIF_ISDEF_MAILBOXTYPEOFMAILBOXCONFIG                                                      STD_OFF
#define CANIF_ISDEF_PDUIDFIRSTOFMAILBOXCONFIG                                                       STD_OFF
#define CANIF_ISDEF_PDUIDLASTOFMAILBOXCONFIG                                                        STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                   STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGOFMAILBOXCONFIG                                                      STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                  STD_OFF
#define CANIF_ISDEF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                             STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                         STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                            STD_OFF
#define CANIF_ISDEF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                         STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                             STD_OFF
#define CANIF_ISDEF_RXPDUCANIDOFRXPDUCONFIG                                                         STD_OFF
#define CANIF_ISDEF_RXPDUDLCOFRXPDUCONFIG                                                           STD_OFF
#define CANIF_ISDEF_RXPDUMASKOFRXPDUCONFIG                                                          STD_OFF
#define CANIF_ISDEF_UPPERPDUIDOFRXPDUCONFIG                                                         STD_OFF
#define CANIF_ISDEF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                         STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                   STD_OFF
#define CANIF_ISDEF_TXQUEUEFLAGSENDIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                           STD_OFF
#define CANIF_ISDEF_TXQUEUEFLAGSSTARTIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                         STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLIST                                                           STD_OFF
#define CANIF_ISDEF_CANIDOFTXPDUCONFIG                                                              STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFTXPDUCONFIG                                                      STD_OFF
#define CANIF_ISDEF_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                  STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                   STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                           STD_OFF
#define CANIF_ISDEF_TXPDULENGTHOFTXPDUCONFIG                                                        STD_OFF
#define CANIF_ISDEF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                  STD_OFF
#define CANIF_ISDEF_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                     STD_OFF
#define CANIF_ISDEF_TXQUEUEOFTXPDUQUEUEINDEX                                                        STD_OFF
#define CANIF_ISDEF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                    STD_OFF
#define CANIF_ISDEF_ULTXPDUID2INTERNALTXPDUID                                                       STD_OFF
#define CANIF_ISDEF_CONTROLLERIDOFWAKEUPCONFIG                                                      STD_OFF
#define CANIF_ISDEF_WAKEUPSOURCEOFWAKEUPCONFIG                                                      STD_OFF
#define CANIF_ISDEF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                                               STD_OFF
#define CANIF_ISDEF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                                                STD_OFF
#define CANIF_ISDEF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                              STD_ON
#define CANIF_ISDEF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                     STD_ON
#define CANIF_ISDEF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                              STD_ON
#define CANIF_ISDEF_CTRLSTATESOFPCCONFIG                                                            STD_ON
#define CANIF_ISDEF_MAILBOXCONFIGOFPCCONFIG                                                         STD_ON
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                 STD_ON
#define CANIF_ISDEF_RXINDICATIONFCTLISTOFPCCONFIG                                                   STD_ON
#define CANIF_ISDEF_RXPDUCONFIGOFPCCONFIG                                                           STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                               STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBITQUEUECONFIGOFPCCONFIG                                     STD_ON
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                 STD_ON
#define CANIF_ISDEF_TXPDUCONFIGOFPCCONFIG                                                           STD_OFF
#define CANIF_ISDEF_TXPDUQUEUEINDEXOFPCCONFIG                                                       STD_ON
#define CANIF_ISDEF_TXQUEUEFLAGSOFPCCONFIG                                                          STD_ON
#define CANIF_ISDEF_TXQUEUEOFPCCONFIG                                                               STD_ON
#define CANIF_ISDEF_ULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                             STD_ON
#define CANIF_ISDEF_WAKEUPCONFIGOFPCCONFIG                                                          STD_ON
#define CANIF_ISDEF_WAKEUPVALIDATIONFCTPTROFPCCONFIG                                                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEqualsAlwaysToDefines  CanIf Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                    
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                  
#define CANIF_EQ2_CTRLSTATESIDXOFMAILBOXCONFIG                                                      
#define CANIF_EQ2_MAILBOXTYPEOFMAILBOXCONFIG                                                        
#define CANIF_EQ2_PDUIDFIRSTOFMAILBOXCONFIG                                                         
#define CANIF_EQ2_PDUIDLASTOFMAILBOXCONFIG                                                          
#define CANIF_EQ2_TXBUFFERCFGIDXOFMAILBOXCONFIG                                                     
#define CANIF_EQ2_TXBUFFERCFGOFMAILBOXCONFIG                                                        
#define CANIF_EQ2_TXBUFFERCFGUSEDOFMAILBOXCONFIG                                                    
#define CANIF_EQ2_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                                               
#define CANIF_EQ2_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                                           
#define CANIF_EQ2_RXINDICATIONFCTOFRXINDICATIONFCTLIST                                              
#define CANIF_EQ2_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                                           
#define CANIF_EQ2_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                                               
#define CANIF_EQ2_RXPDUCANIDOFRXPDUCONFIG                                                           
#define CANIF_EQ2_RXPDUDLCOFRXPDUCONFIG                                                             
#define CANIF_EQ2_RXPDUMASKOFRXPDUCONFIG                                                            
#define CANIF_EQ2_UPPERPDUIDOFRXPDUCONFIG                                                           
#define CANIF_EQ2_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                           
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                     
#define CANIF_EQ2_TXQUEUEFLAGSENDIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                             
#define CANIF_EQ2_TXQUEUEFLAGSSTARTIDXOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG                           
#define CANIF_EQ2_TXCONFIRMATIONFCTLIST                                                             
#define CANIF_EQ2_CANIDOFTXPDUCONFIG                                                                
#define CANIF_EQ2_CTRLSTATESIDXOFTXPDUCONFIG                                                        
#define CANIF_EQ2_ISTXPDUTRUNCATIONOFTXPDUCONFIG                                                    
#define CANIF_EQ2_MAILBOXCONFIGIDXOFTXPDUCONFIG                                                     
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                                             
#define CANIF_EQ2_TXPDULENGTHOFTXPDUCONFIG                                                          
#define CANIF_EQ2_UPPERLAYERTXPDUIDOFTXPDUCONFIG                                                    
#define CANIF_EQ2_TXQUEUEIDXOFTXPDUQUEUEINDEX                                                       
#define CANIF_EQ2_TXQUEUEOFTXPDUQUEUEINDEX                                                          
#define CANIF_EQ2_TXQUEUEUSEDOFTXPDUQUEUEINDEX                                                      
#define CANIF_EQ2_ULTXPDUID2INTERNALTXPDUID                                                         
#define CANIF_EQ2_CONTROLLERIDOFWAKEUPCONFIG                                                        
#define CANIF_EQ2_WAKEUPSOURCEOFWAKEUPCONFIG                                                        
#define CANIF_EQ2_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                                                 
#define CANIF_EQ2_WAKEUPTARGETMODULEOFWAKEUPCONFIG                                                  
#define CANIF_EQ2_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                                                (&(CanIf_BusOffNotificationFctPtr))
#define CANIF_EQ2_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                       CanIf_CanIfCtrlId2MappedTxBuffersConfig
#define CANIF_EQ2_CTRLMODEINDICATIONFCTPTROFPCCONFIG                                                (&(CanIf_CtrlModeIndicationFctPtr))
#define CANIF_EQ2_CTRLSTATESOFPCCONFIG                                                              CanIf_CtrlStates.raw
#define CANIF_EQ2_MAILBOXCONFIGOFPCCONFIG                                                           CanIf_MailBoxConfig
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                                                   CanIf_MappedTxBuffersConfig
#define CANIF_EQ2_RXINDICATIONFCTLISTOFPCCONFIG                                                     CanIf_RxIndicationFctList
#define CANIF_EQ2_RXPDUCONFIGOFPCCONFIG                                                             
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                                                 CanIf_TxBufferPrioByCanIdBase.raw
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBITQUEUECONFIGOFPCCONFIG                                       CanIf_TxBufferPrioByCanIdBitQueueConfig
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTOFPCCONFIG                                                   CanIf_TxConfirmationFctList
#define CANIF_EQ2_TXPDUCONFIGOFPCCONFIG                                                             
#define CANIF_EQ2_TXPDUQUEUEINDEXOFPCCONFIG                                                         CanIf_TxPduQueueIndex
#define CANIF_EQ2_TXQUEUEFLAGSOFPCCONFIG                                                            CanIf_TxQueueFlags.raw
#define CANIF_EQ2_TXQUEUEOFPCCONFIG                                                                 CanIf_TxQueue.raw
#define CANIF_EQ2_ULTXPDUID2INTERNALTXPDUIDOFPCCONFIG                                               CanIf_UlTxPduId2InternalTxPduId
#define CANIF_EQ2_WAKEUPCONFIGOFPCCONFIG                                                            CanIf_WakeUpConfig
#define CANIF_EQ2_WAKEUPVALIDATIONFCTPTROFPCCONFIG                                                  (&(CanIf_WakeUpValidationFctPtr))
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicInitializationPointers  CanIf Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanIf_Config_Left_Ptr                                                                       &(CanIf_PCConfig.Config_Left)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
#define CanIf_Config_Right_Ptr                                                                      &(CanIf_PCConfig.Config_Right)  /**< symbolic identifier which shall be used to initialize 'CanIf' */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCInitializationSymbols  CanIf Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanIf_Config_Left                                                                           CanIf_PCConfig.Config_Left  /**< symbolic identifier which could be used to initialize 'CanIf */
#define CanIf_Config_Right                                                                          CanIf_PCConfig.Config_Right  /**< symbolic identifier which could be used to initialize 'CanIf */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGeneral  CanIf General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANIF_CHECK_INIT_POINTER                                                                    STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANIF_FINAL_MAGIC_NUMBER                                                                    0x3C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanIf */
#define CANIF_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanIf' is not configured to be postbuild capable. */
#define CANIF_INIT_DATA                                                                             CANIF_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANIF_INIT_DATA_HASH_CODE                                                                   238716341  /**< the precompile constant to validate the initialization structure at initialization time of CanIf with a hashcode. The seed value is '0x3C1Eu' */
#define CANIF_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANIF_USE_INIT_POINTER                                                                      STD_ON  /**< STD_ON if the init pointer CanIf shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPBDataSwitches  CanIf Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_PBCONFIG                                                                              STD_OFF  /**< Deactivateable: 'CanIf_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCGetRootDataMacros  CanIf Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CanIf_GetRxPduConfigOfPCConfig()                                                            CanIf_ConfigDataPtr->RxPduConfigOfPCConfig
#define CanIf_GetTxPduConfigOfPCConfig()                                                            CanIf_ConfigDataPtr->TxPduConfigOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetConstantDuplicatedRootDataMacros  CanIf Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtrOfPCConfig()                                               (&(CanIf_BusOffNotificationFctPtr))  /**< the pointer to CanIf_BusOffNotificationFctPtr */
#define CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                      CanIf_CanIfCtrlId2MappedTxBuffersConfig  /**< the pointer to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetCtrlModeIndicationFctPtrOfPCConfig()                                               (&(CanIf_CtrlModeIndicationFctPtr))  /**< the pointer to CanIf_CtrlModeIndicationFctPtr */
#define CanIf_GetCtrlStatesOfPCConfig()                                                             CanIf_CtrlStates.raw  /**< the pointer to CanIf_CtrlStates */
#define CanIf_GetGeneratorCompatibilityVersionOfPCConfig()                                          0x0212u
#define CanIf_GetGeneratorVersionOfPCConfig()                                                       0x00050400u
#define CanIf_GetMailBoxConfigOfPCConfig()                                                          CanIf_MailBoxConfig  /**< the pointer to CanIf_MailBoxConfig */
#define CanIf_GetMappedTxBuffersConfigOfPCConfig()                                                  CanIf_MappedTxBuffersConfig  /**< the pointer to CanIf_MappedTxBuffersConfig */
#define CanIf_GetMaxWakeUpSourcesOfPCConfig()                                                       0u
#define CanIf_GetRxIndicationFctListOfPCConfig()                                                    CanIf_RxIndicationFctList  /**< the pointer to CanIf_RxIndicationFctList */
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                1u  /**< the number of accomplishable value elements in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetSizeOfCtrlStatesOfPCConfig()                                                       1u  /**< the number of accomplishable value elements in CanIf_CtrlStates */
#define CanIf_GetSizeOfMailBoxConfigOfPCConfig()                                                    3u  /**< the number of accomplishable value elements in CanIf_MailBoxConfig */
#define CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()                                            1u  /**< the number of accomplishable value elements in CanIf_MappedTxBuffersConfig */
#define CanIf_GetSizeOfRxIndicationFctListOfPCConfig()                                              5u  /**< the number of accomplishable value elements in CanIf_RxIndicationFctList */
#define CanIf_GetSizeOfRxPduConfigOfPCConfig()                                                      38u  /**< the number of accomplishable value elements in CanIf_RxPduConfig */
#define CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()                                          1u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetSizeOfTxBufferPrioByCanIdBitQueueConfigOfPCConfig()                                1u  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdBitQueueConfig */
#define CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()                                            4u  /**< the number of accomplishable value elements in CanIf_TxConfirmationFctList */
#define CanIf_GetSizeOfTxPduConfigOfPCConfig()                                                      11u  /**< the number of accomplishable value elements in CanIf_TxPduConfig */
#define CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()                                                  11u  /**< the number of accomplishable value elements in CanIf_TxPduQueueIndex */
#define CanIf_GetSizeOfTxQueueFlagsOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in CanIf_TxQueueFlags */
#define CanIf_GetSizeOfTxQueueOfPCConfig()                                                          11u  /**< the number of accomplishable value elements in CanIf_TxQueue */
#define CanIf_GetSizeOfUlTxPduId2InternalTxPduIdOfPCConfig()                                        11u  /**< the number of accomplishable value elements in CanIf_UlTxPduId2InternalTxPduId */
#define CanIf_GetSizeOfWakeUpConfigOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in CanIf_WakeUpConfig */
#define CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()                                                CanIf_TxBufferPrioByCanIdBase.raw  /**< the pointer to CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetTxBufferPrioByCanIdBitQueueConfigOfPCConfig()                                      CanIf_TxBufferPrioByCanIdBitQueueConfig  /**< the pointer to CanIf_TxBufferPrioByCanIdBitQueueConfig */
#define CanIf_GetTxConfirmationFctListOfPCConfig()                                                  CanIf_TxConfirmationFctList  /**< the pointer to CanIf_TxConfirmationFctList */
#define CanIf_GetTxPduQueueIndexOfPCConfig()                                                        CanIf_TxPduQueueIndex  /**< the pointer to CanIf_TxPduQueueIndex */
#define CanIf_GetTxQueueFlagsOfPCConfig()                                                           CanIf_TxQueueFlags.raw  /**< the pointer to CanIf_TxQueueFlags */
#define CanIf_GetTxQueueOfPCConfig()                                                                CanIf_TxQueue.raw  /**< the pointer to CanIf_TxQueue */
#define CanIf_GetUlTxPduId2InternalTxPduIdOfPCConfig()                                              CanIf_UlTxPduId2InternalTxPduId  /**< the pointer to CanIf_UlTxPduId2InternalTxPduId */
#define CanIf_GetWakeUpConfigOfPCConfig()                                                           CanIf_WakeUpConfig  /**< the pointer to CanIf_WakeUpConfig */
#define CanIf_GetWakeUpValidationFctPtrOfPCConfig()                                                 (&(CanIf_WakeUpValidationFctPtr))  /**< the pointer to CanIf_WakeUpValidationFctPtr */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDataMacros  CanIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtr()                                                         ((*(CanIf_GetBusOffNotificationFctPtrOfPCConfig())))
#define CanIf_GetMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index)              (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index)            (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetCtrlModeIndicationFctPtr()                                                         ((*(CanIf_GetCtrlModeIndicationFctPtrOfPCConfig())))
#define CanIf_GetCtrlModeOfCtrlStates(Index)                                                        (CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates)
#define CanIf_GetPduModeOfCtrlStates(Index)                                                         (CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates)
#define CanIf_GetWakeUpValidationStateOfCtrlStates(Index)                                           (CanIf_GetCtrlStatesOfPCConfig()[(Index)].WakeUpValidationStateOfCtrlStates)
#define CanIf_GetCtrlStatesIdxOfMailBoxConfig(Index)                                                (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].CtrlStatesIdxOfMailBoxConfig)
#define CanIf_GetMailBoxTypeOfMailBoxConfig(Index)                                                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].MailBoxTypeOfMailBoxConfig)
#define CanIf_GetPduIdFirstOfMailBoxConfig(Index)                                                   (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdFirstOfMailBoxConfig)
#define CanIf_GetPduIdLastOfMailBoxConfig(Index)                                                    (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdLastOfMailBoxConfig)
#define CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index)                                               (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgIdxOfMailBoxConfig)
#define CanIf_GetTxBufferCfgOfMailBoxConfig(Index)                                                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgOfMailBoxConfig)
#define CanIf_GetTxBufferHandlingTypeOfMailBoxConfig(Index)                                         (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferHandlingTypeOfMailBoxConfig)
#define CanIf_GetMailBoxConfigIdxOfMappedTxBuffersConfig(Index)                                     (CanIf_GetMappedTxBuffersConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfMappedTxBuffersConfig)
#define CanIf_GetRxIndicationFctOfRxIndicationFctList(Index)                                        (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationFctOfRxIndicationFctList)
#define CanIf_GetRxIndicationLayoutOfRxIndicationFctList(Index)                                     (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationLayoutOfRxIndicationFctList)
#define CanIf_GetRxIndicationFctListIdxOfRxPduConfig(Index)                                         (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxIndicationFctListIdxOfRxPduConfig)
#define CanIf_GetRxPduCanIdOfRxPduConfig(Index)                                                     (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduCanIdOfRxPduConfig)
#define CanIf_GetRxPduDlcOfRxPduConfig(Index)                                                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduDlcOfRxPduConfig)
#define CanIf_GetRxPduMaskOfRxPduConfig(Index)                                                      (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduMaskOfRxPduConfig)
#define CanIf_GetUpperPduIdOfRxPduConfig(Index)                                                     (CanIf_GetRxPduConfigOfPCConfig()[(Index)].UpperPduIdOfRxPduConfig)
#define CanIf_GetTxBufferPrioByCanIdBase(Index)                                                     (CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)])
#define CanIf_GetBitPos2TxPduIdOffsetOfTxBufferPrioByCanIdBitQueueConfig(Index)                     (CanIf_GetTxBufferPrioByCanIdBitQueueConfigOfPCConfig()[(Index)].BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdBitQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfig(Index)               (CanIf_GetTxBufferPrioByCanIdBitQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfig)
#define CanIf_GetTxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfig(Index)                       (CanIf_GetTxBufferPrioByCanIdBitQueueConfigOfPCConfig()[(Index)].TxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfig)
#define CanIf_GetTxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfig(Index)                     (CanIf_GetTxBufferPrioByCanIdBitQueueConfigOfPCConfig()[(Index)].TxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfig)
#define CanIf_GetTxConfirmationFctList(Index)                                                       (CanIf_GetTxConfirmationFctListOfPCConfig()[(Index)])
#define CanIf_GetCanIdOfTxPduConfig(Index)                                                          (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CanIdOfTxPduConfig)
#define CanIf_GetCtrlStatesIdxOfTxPduConfig(Index)                                                  (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CtrlStatesIdxOfTxPduConfig)
#define CanIf_IsIsTxPduTruncationOfTxPduConfig(Index)                                               ((CanIf_GetTxPduConfigOfPCConfig()[(Index)].IsTxPduTruncationOfTxPduConfig) != FALSE)
#define CanIf_GetMailBoxConfigIdxOfTxPduConfig(Index)                                               (CanIf_GetTxPduConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfTxPduConfig)
#define CanIf_GetTxConfirmationFctListIdxOfTxPduConfig(Index)                                       (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxConfirmationFctListIdxOfTxPduConfig)
#define CanIf_GetTxPduLengthOfTxPduConfig(Index)                                                    (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxPduLengthOfTxPduConfig)
#define CanIf_GetUpperLayerTxPduIdOfTxPduConfig(Index)                                              (CanIf_GetTxPduConfigOfPCConfig()[(Index)].UpperLayerTxPduIdOfTxPduConfig)
#define CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index)                                                 (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueIdxOfTxPduQueueIndex)
#define CanIf_GetTxQueueOfTxPduQueueIndex(Index)                                                    (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueOfTxPduQueueIndex)
#define CanIf_GetTxQueue(Index)                                                                     (CanIf_GetTxQueueOfPCConfig()[(Index)])
#define CanIf_GetTxQueueFlags(Index)                                                                (CanIf_GetTxQueueFlagsOfPCConfig()[(Index)])
#define CanIf_GetUlTxPduId2InternalTxPduId(Index)                                                   (CanIf_GetUlTxPduId2InternalTxPduIdOfPCConfig()[(Index)])
#define CanIf_GetControllerIdOfWakeUpConfig(Index)                                                  (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].ControllerIdOfWakeUpConfig)
#define CanIf_GetWakeUpSourceOfWakeUpConfig(Index)                                                  ((EcuM_WakeupSourceType)CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpSourceOfWakeUpConfig)
#define CanIf_GetWakeUpTargetAddressOfWakeUpConfig(Index)                                           (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpTargetAddressOfWakeUpConfig)
#define CanIf_GetWakeUpTargetModuleOfWakeUpConfig(Index)                                            (CanIf_GetWakeUpConfigOfPCConfig()[(Index)].WakeUpTargetModuleOfWakeUpConfig)
#define CanIf_GetWakeUpValidationFctPtr()                                                           ((*(CanIf_GetWakeUpValidationFctPtrOfPCConfig())))
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDeduplicatedDataMacros  CanIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanIf_GetGeneratorCompatibilityVersion()                                                    CanIf_GetGeneratorCompatibilityVersionOfPCConfig()
#define CanIf_GetGeneratorVersion()                                                                 CanIf_GetGeneratorVersionOfPCConfig()
#define CanIf_IsTxBufferCfgUsedOfMailBoxConfig(Index)                                               (((boolean)(CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index) != CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxBufferPrioByCanIdBitQueueConfig */
#define CanIf_GetMaxWakeUpSources()                                                                 CanIf_GetMaxWakeUpSourcesOfPCConfig()
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfig()                                          CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlStates()                                                                 CanIf_GetSizeOfCtrlStatesOfPCConfig()
#define CanIf_GetSizeOfMailBoxConfig()                                                              CanIf_GetSizeOfMailBoxConfigOfPCConfig()
#define CanIf_GetSizeOfMappedTxBuffersConfig()                                                      CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfRxIndicationFctList()                                                        CanIf_GetSizeOfRxIndicationFctListOfPCConfig()
#define CanIf_GetSizeOfRxPduConfig()                                                                CanIf_GetSizeOfRxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdBase()                                                    CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdBitQueueConfig()                                          CanIf_GetSizeOfTxBufferPrioByCanIdBitQueueConfigOfPCConfig()
#define CanIf_GetSizeOfTxConfirmationFctList()                                                      CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()
#define CanIf_GetSizeOfTxPduConfig()                                                                CanIf_GetSizeOfTxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxPduQueueIndex()                                                            CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()
#define CanIf_GetSizeOfTxQueue()                                                                    CanIf_GetSizeOfTxQueueOfPCConfig()
#define CanIf_GetSizeOfTxQueueFlags()                                                               CanIf_GetSizeOfTxQueueFlagsOfPCConfig()
#define CanIf_GetSizeOfUlTxPduId2InternalTxPduId()                                                  CanIf_GetSizeOfUlTxPduId2InternalTxPduIdOfPCConfig()
#define CanIf_GetSizeOfWakeUpConfig()                                                               CanIf_GetSizeOfWakeUpConfigOfPCConfig()
#define CanIf_IsTxQueueUsedOfTxPduQueueIndex(Index)                                                 (((boolean)(CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index) != CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxQueue */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSetDataMacros  CanIf Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanIf_SetCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates = (Value)
#define CanIf_SetPduModeOfCtrlStates(Index, Value)                                                  CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates = (Value)
#define CanIf_SetWakeUpValidationStateOfCtrlStates(Index, Value)                                    CanIf_GetCtrlStatesOfPCConfig()[(Index)].WakeUpValidationStateOfCtrlStates = (Value)
#define CanIf_SetTxBufferPrioByCanIdBase(Index, Value)                                              CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueue(Index, Value)                                                              CanIf_GetTxQueueOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueueFlags(Index, Value)                                                         CanIf_GetTxQueueFlagsOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCHasMacros  CanIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanIf_HasBusOffNotificationFctPtr()                                                         (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfig()                                                (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig()                   (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig()                 (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtr()                                                         (TRUE != FALSE)
#define CanIf_HasCtrlStates()                                                                       (TRUE != FALSE)
#define CanIf_HasCtrlModeOfCtrlStates()                                                             (TRUE != FALSE)
#define CanIf_HasPduModeOfCtrlStates()                                                              (TRUE != FALSE)
#define CanIf_HasWakeUpValidationStateOfCtrlStates()                                                (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersion()                                                    (TRUE != FALSE)
#define CanIf_HasGeneratorVersion()                                                                 (TRUE != FALSE)
#define CanIf_HasMailBoxConfig()                                                                    (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfMailBoxConfig()                                                     (TRUE != FALSE)
#define CanIf_HasMailBoxTypeOfMailBoxConfig()                                                       (TRUE != FALSE)
#define CanIf_HasPduIdFirstOfMailBoxConfig()                                                        (TRUE != FALSE)
#define CanIf_HasPduIdLastOfMailBoxConfig()                                                         (TRUE != FALSE)
#define CanIf_HasTxBufferCfgIdxOfMailBoxConfig()                                                    (TRUE != FALSE)
#define CanIf_HasTxBufferCfgOfMailBoxConfig()                                                       (TRUE != FALSE)
#define CanIf_HasTxBufferCfgUsedOfMailBoxConfig()                                                   (TRUE != FALSE)
#define CanIf_HasTxBufferHandlingTypeOfMailBoxConfig()                                              (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfig()                                                            (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfMappedTxBuffersConfig()                                          (TRUE != FALSE)
#define CanIf_HasMaxWakeUpSources()                                                                 (TRUE != FALSE)
#define CanIf_HasRxIndicationFctList()                                                              (TRUE != FALSE)
#define CanIf_HasRxIndicationFctOfRxIndicationFctList()                                             (TRUE != FALSE)
#define CanIf_HasRxIndicationLayoutOfRxIndicationFctList()                                          (TRUE != FALSE)
#define CanIf_HasRxPduConfig()                                                                      (CanIf_GetRxPduConfigOfPCConfig() != NULL_PTR)
#define CanIf_HasRxIndicationFctListIdxOfRxPduConfig()                                              (TRUE != FALSE)
#define CanIf_HasRxPduCanIdOfRxPduConfig()                                                          (TRUE != FALSE)
#define CanIf_HasRxPduDlcOfRxPduConfig()                                                            (TRUE != FALSE)
#define CanIf_HasRxPduMaskOfRxPduConfig()                                                           (TRUE != FALSE)
#define CanIf_HasUpperPduIdOfRxPduConfig()                                                          (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfig()                                          (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStates()                                                                 (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfig()                                                              (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctList()                                                        (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfig()                                                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBase()                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBitQueueConfig()                                          (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctList()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfig()                                                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndex()                                                            (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueue()                                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueFlags()                                                               (TRUE != FALSE)
#define CanIf_HasSizeOfUlTxPduId2InternalTxPduId()                                                  (TRUE != FALSE)
#define CanIf_HasSizeOfWakeUpConfig()                                                               (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBase()                                                          (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBitQueueConfig()                                                (TRUE != FALSE)
#define CanIf_HasBitPos2TxPduIdOffsetOfTxBufferPrioByCanIdBitQueueConfig()                          (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfig()                    (TRUE != FALSE)
#define CanIf_HasTxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfig()                            (TRUE != FALSE)
#define CanIf_HasTxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfig()                          (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctList()                                                            (TRUE != FALSE)
#define CanIf_HasTxPduConfig()                                                                      (CanIf_GetTxPduConfigOfPCConfig() != NULL_PTR)
#define CanIf_HasCanIdOfTxPduConfig()                                                               (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfTxPduConfig()                                                       (TRUE != FALSE)
#define CanIf_HasIsTxPduTruncationOfTxPduConfig()                                                   (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfTxPduConfig()                                                    (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListIdxOfTxPduConfig()                                            (TRUE != FALSE)
#define CanIf_HasTxPduLengthOfTxPduConfig()                                                         (TRUE != FALSE)
#define CanIf_HasUpperLayerTxPduIdOfTxPduConfig()                                                   (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndex()                                                                  (TRUE != FALSE)
#define CanIf_HasTxQueueIdxOfTxPduQueueIndex()                                                      (TRUE != FALSE)
#define CanIf_HasTxQueueOfTxPduQueueIndex()                                                         (TRUE != FALSE)
#define CanIf_HasTxQueueUsedOfTxPduQueueIndex()                                                     (TRUE != FALSE)
#define CanIf_HasTxQueue()                                                                          (TRUE != FALSE)
#define CanIf_HasTxQueueFlags()                                                                     (TRUE != FALSE)
#define CanIf_HasUlTxPduId2InternalTxPduId()                                                        (TRUE != FALSE)
#define CanIf_HasWakeUpConfig()                                                                     (TRUE != FALSE)
#define CanIf_HasControllerIdOfWakeUpConfig()                                                       (TRUE != FALSE)
#define CanIf_HasWakeUpSourceOfWakeUpConfig()                                                       (TRUE != FALSE)
#define CanIf_HasWakeUpTargetAddressOfWakeUpConfig()                                                (TRUE != FALSE)
#define CanIf_HasWakeUpTargetModuleOfWakeUpConfig()                                                 (TRUE != FALSE)
#define CanIf_HasWakeUpValidationFctPtr()                                                           (TRUE != FALSE)
#define CanIf_HasPCConfig()                                                                         (TRUE != FALSE)
#define CanIf_HasBusOffNotificationFctPtrOfPCConfig()                                               (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                      (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtrOfPCConfig()                                               (TRUE != FALSE)
#define CanIf_HasCtrlStatesOfPCConfig()                                                             (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersionOfPCConfig()                                          (TRUE != FALSE)
#define CanIf_HasGeneratorVersionOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasMailBoxConfigOfPCConfig()                                                          (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasMaxWakeUpSourcesOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListOfPCConfig()                                                    (TRUE != FALSE)
#define CanIf_HasRxPduConfigOfPCConfig()                                                            (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()                                (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStatesOfPCConfig()                                                       (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfigOfPCConfig()                                                    (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfigOfPCConfig()                                            (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctListOfPCConfig()                                              (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfigOfPCConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBaseOfPCConfig()                                          (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBitQueueConfigOfPCConfig()                                (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctListOfPCConfig()                                            (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfigOfPCConfig()                                                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndexOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueFlagsOfPCConfig()                                                     (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueOfPCConfig()                                                          (TRUE != FALSE)
#define CanIf_HasSizeOfUlTxPduId2InternalTxPduIdOfPCConfig()                                        (TRUE != FALSE)
#define CanIf_HasSizeOfWakeUpConfigOfPCConfig()                                                     (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseOfPCConfig()                                                (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBitQueueConfigOfPCConfig()                                      (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListOfPCConfig()                                                  (TRUE != FALSE)
#define CanIf_HasTxPduConfigOfPCConfig()                                                            (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndexOfPCConfig()                                                        (TRUE != FALSE)
#define CanIf_HasTxQueueFlagsOfPCConfig()                                                           (TRUE != FALSE)
#define CanIf_HasTxQueueOfPCConfig()                                                                (TRUE != FALSE)
#define CanIf_HasUlTxPduId2InternalTxPduIdOfPCConfig()                                              (TRUE != FALSE)
#define CanIf_HasWakeUpConfigOfPCConfig()                                                           (TRUE != FALSE)
#define CanIf_HasWakeUpValidationFctPtrOfPCConfig()                                                 (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIncrementDataMacros  CanIf Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanIf_IncCtrlModeOfCtrlStates(Index)                                                        CanIf_GetCtrlModeOfCtrlStates(Index)++
#define CanIf_IncPduModeOfCtrlStates(Index)                                                         CanIf_GetPduModeOfCtrlStates(Index)++
#define CanIf_IncWakeUpValidationStateOfCtrlStates(Index)                                           CanIf_GetWakeUpValidationStateOfCtrlStates(Index)++
#define CanIf_IncTxBufferPrioByCanIdBase(Index)                                                     CanIf_GetTxBufferPrioByCanIdBase(Index)++
#define CanIf_IncTxQueue(Index)                                                                     CanIf_GetTxQueue(Index)++
#define CanIf_IncTxQueueFlags(Index)                                                                CanIf_GetTxQueueFlags(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCDecrementDataMacros  CanIf Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanIf_DecCtrlModeOfCtrlStates(Index)                                                        CanIf_GetCtrlModeOfCtrlStates(Index)--
#define CanIf_DecPduModeOfCtrlStates(Index)                                                         CanIf_GetPduModeOfCtrlStates(Index)--
#define CanIf_DecWakeUpValidationStateOfCtrlStates(Index)                                           CanIf_GetWakeUpValidationStateOfCtrlStates(Index)--
#define CanIf_DecTxBufferPrioByCanIdBase(Index)                                                     CanIf_GetTxBufferPrioByCanIdBase(Index)--
#define CanIf_DecTxQueue(Index)                                                                     CanIf_GetTxQueue(Index)--
#define CanIf_DecTxQueueFlags(Index)                                                                CanIf_GetTxQueueFlags(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCAddDataMacros  CanIf Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define CanIf_AddCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_SetCtrlModeOfCtrlStates(Index, (CanIf_GetCtrlModeOfCtrlStates(Index) + Value))
#define CanIf_AddPduModeOfCtrlStates(Index, Value)                                                  CanIf_SetPduModeOfCtrlStates(Index, (CanIf_GetPduModeOfCtrlStates(Index) + Value))
#define CanIf_AddWakeUpValidationStateOfCtrlStates(Index, Value)                                    CanIf_SetWakeUpValidationStateOfCtrlStates(Index, (CanIf_GetWakeUpValidationStateOfCtrlStates(Index) + Value))
#define CanIf_AddTxBufferPrioByCanIdBase(Index, Value)                                              CanIf_SetTxBufferPrioByCanIdBase(Index, (CanIf_GetTxBufferPrioByCanIdBase(Index) + Value))
#define CanIf_AddTxQueue(Index, Value)                                                              CanIf_SetTxQueue(Index, (CanIf_GetTxQueue(Index) + Value))
#define CanIf_AddTxQueueFlags(Index, Value)                                                         CanIf_SetTxQueueFlags(Index, (CanIf_GetTxQueueFlags(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSubstractDataMacros  CanIf Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define CanIf_SubCtrlModeOfCtrlStates(Index, Value)                                                 CanIf_SetCtrlModeOfCtrlStates(Index, (CanIf_GetCtrlModeOfCtrlStates(Index) - Value))
#define CanIf_SubPduModeOfCtrlStates(Index, Value)                                                  CanIf_SetPduModeOfCtrlStates(Index, (CanIf_GetPduModeOfCtrlStates(Index) - Value))
#define CanIf_SubWakeUpValidationStateOfCtrlStates(Index, Value)                                    CanIf_SetWakeUpValidationStateOfCtrlStates(Index, (CanIf_GetWakeUpValidationStateOfCtrlStates(Index) - Value))
#define CanIf_SubTxBufferPrioByCanIdBase(Index, Value)                                              CanIf_SetTxBufferPrioByCanIdBase(Index, (CanIf_GetTxBufferPrioByCanIdBase(Index) - Value))
#define CanIf_SubTxQueue(Index, Value)                                                              CanIf_SetTxQueue(Index, (CanIf_GetTxQueue(Index) - Value))
#define CanIf_SubTxQueueFlags(Index, Value)                                                         CanIf_SetTxQueueFlags(Index, (CanIf_GetTxQueueFlags(Index) - Value))
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCIterableTypes  CanIf Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef uint8_least CanIf_CanIfCtrlId2MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_CtrlStates */
typedef uint8_least CanIf_CtrlStatesIterType;

/**   \brief  type used to iterate CanIf_MailBoxConfig */
typedef uint8_least CanIf_MailBoxConfigIterType;

/**   \brief  type used to iterate CanIf_MappedTxBuffersConfig */
typedef uint8_least CanIf_MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_RxIndicationFctList */
typedef uint8_least CanIf_RxIndicationFctListIterType;

/**   \brief  type used to iterate CanIf_RxPduConfig */
typedef uint8_least CanIf_RxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdBase */
typedef uint8_least CanIf_TxBufferPrioByCanIdBaseIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdBitQueueConfig */
typedef uint8_least CanIf_TxBufferPrioByCanIdBitQueueConfigIterType;

/**   \brief  type used to iterate CanIf_TxConfirmationFctList */
typedef uint8_least CanIf_TxConfirmationFctListIterType;

/**   \brief  type used to iterate CanIf_TxPduConfig */
typedef uint8_least CanIf_TxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TxPduQueueIndex */
typedef uint8_least CanIf_TxPduQueueIndexIterType;

/**   \brief  type used to iterate CanIf_TxQueue */
typedef uint8_least CanIf_TxQueueIterType;

/**   \brief  type used to iterate CanIf_TxQueueFlags */
typedef uint8_least CanIf_TxQueueFlagsIterType;

/**   \brief  type used to iterate CanIf_UlTxPduId2InternalTxPduId */
typedef uint8_least CanIf_UlTxPduId2InternalTxPduIdIterType;

/**   \brief  type used to iterate CanIf_WakeUpConfig */
typedef uint8_least CanIf_WakeUpConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCValueTypes  CanIf Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_GeneratorCompatibilityVersion */
typedef uint16 CanIf_GeneratorCompatibilityVersionType;

/**   \brief  value based type definition for CanIf_GeneratorVersion */
typedef uint32 CanIf_GeneratorVersionType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfMailBoxConfig */
typedef uint8 CanIf_CtrlStatesIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdFirstOfMailBoxConfig */
typedef uint8 CanIf_PduIdFirstOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdLastOfMailBoxConfig */
typedef uint8 CanIf_PduIdLastOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgIdxOfMailBoxConfig */
typedef uint8 CanIf_TxBufferCfgIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgOfMailBoxConfig */
typedef uint8 CanIf_TxBufferCfgOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgUsedOfMailBoxConfig */
typedef boolean CanIf_TxBufferCfgUsedOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferHandlingTypeOfMailBoxConfig */
typedef uint8 CanIf_TxBufferHandlingTypeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfMappedTxBuffersConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MaxWakeUpSources */
typedef uint8 CanIf_MaxWakeUpSourcesType;

/**   \brief  value based type definition for CanIf_RxIndicationFctListIdxOfRxPduConfig */
typedef uint8 CanIf_RxIndicationFctListIdxOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduCanIdOfRxPduConfig */
typedef uint32 CanIf_RxPduCanIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduDlcOfRxPduConfig */
typedef uint8 CanIf_RxPduDlcOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduMaskOfRxPduConfig */
typedef uint32 CanIf_RxPduMaskOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperPduIdOfRxPduConfig */
typedef PduIdType CanIf_UpperPduIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCtrlStates */
typedef uint8 CanIf_SizeOfCtrlStatesType;

/**   \brief  value based type definition for CanIf_SizeOfMailBoxConfig */
typedef uint8 CanIf_SizeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_SizeOfMappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfRxIndicationFctList */
typedef uint8 CanIf_SizeOfRxIndicationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfRxPduConfig */
typedef uint8 CanIf_SizeOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdBase */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdBaseType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdBitQueueConfig */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdBitQueueConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxConfirmationFctList */
typedef uint8 CanIf_SizeOfTxConfirmationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduConfig */
typedef uint8 CanIf_SizeOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduQueueIndex */
typedef uint8 CanIf_SizeOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueue */
typedef uint8 CanIf_SizeOfTxQueueType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueueFlags */
typedef uint8 CanIf_SizeOfTxQueueFlagsType;

/**   \brief  value based type definition for CanIf_SizeOfUlTxPduId2InternalTxPduId */
typedef uint8 CanIf_SizeOfUlTxPduId2InternalTxPduIdType;

/**   \brief  value based type definition for CanIf_SizeOfWakeUpConfig */
typedef uint8 CanIf_SizeOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdBitQueueConfig */
typedef uint8 CanIf_BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdBitQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfigType;

/**   \brief  value based type definition for CanIf_TxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfig */
typedef uint8 CanIf_TxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfigType;

/**   \brief  value based type definition for CanIf_TxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfig */
typedef uint8 CanIf_TxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfigType;

/**   \brief  value based type definition for CanIf_CanIdOfTxPduConfig */
typedef uint32 CanIf_CanIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfTxPduConfig */
typedef uint8 CanIf_CtrlStatesIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_IsTxPduTruncationOfTxPduConfig */
typedef boolean CanIf_IsTxPduTruncationOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfTxPduConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxConfirmationFctListIdxOfTxPduConfig */
typedef uint8 CanIf_TxConfirmationFctListIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxPduLengthOfTxPduConfig */
typedef uint8 CanIf_TxPduLengthOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperLayerTxPduIdOfTxPduConfig */
typedef PduIdType CanIf_UpperLayerTxPduIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxQueueIdxOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueIdxOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueUsedOfTxPduQueueIndex */
typedef boolean CanIf_TxQueueUsedOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueFlags */
typedef uint32 CanIf_TxQueueFlagsType;

/**   \brief  value based type definition for CanIf_UlTxPduId2InternalTxPduId */
typedef uint8 CanIf_UlTxPduId2InternalTxPduIdType;

/**   \brief  value based type definition for CanIf_ControllerIdOfWakeUpConfig */
typedef uint8 CanIf_ControllerIdOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_WakeUpSourceOfWakeUpConfig */
typedef uint8 CanIf_WakeUpSourceOfWakeUpConfigType;

/**   \brief  value based type definition for CanIf_WakeUpTargetAddressOfWakeUpConfig */
typedef uint8 CanIf_WakeUpTargetAddressOfWakeUpConfigType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCStructTypes  CanIf Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
/*! \spec weak type invariant () { 
 * (self.MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig < CanIf_GetSizeOfMappedTxBuffersConfig()) &&
 * (self.MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig < CanIf_GetSizeOfMappedTxBuffersConfig())
 * } */
typedef struct sCanIf_CanIfCtrlId2MappedTxBuffersConfigType
{
  CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig */
  CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig */
} CanIf_CanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_CtrlStates */
typedef struct sCanIf_CtrlStatesType
{
  CanIf_ControllerModeType CtrlModeOfCtrlStates;  /**< Controller mode. */
  CanIf_PduGetModeType PduModeOfCtrlStates;  /**< PDU mode state. */
  CanIf_WakeUpValidationStateType WakeUpValidationStateOfCtrlStates;  /**< Wake-up validation state. */
} CanIf_CtrlStatesType;

/**   \brief  type used in CanIf_MailBoxConfig */
/*! \spec weak type invariant () { 
 * (self.CtrlStatesIdxOfMailBoxConfig < CanIf_GetSizeOfCtrlStates()) &&
 * (!((self.TxBufferCfgIdxOfMailBoxConfig != CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG)) || ((( self.TxBufferCfgOfMailBoxConfig == CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG_TXBUFFERCFGOFMAILBOXCONFIG) && (self.TxBufferCfgIdxOfMailBoxConfig < CanIf_GetSizeOfTxBufferPrioByCanIdBitQueueConfig()))))
 * } */
typedef struct sCanIf_MailBoxConfigType
{
  CanIf_CtrlStatesIdxOfMailBoxConfigType CtrlStatesIdxOfMailBoxConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_PduIdFirstOfMailBoxConfigType PduIdFirstOfMailBoxConfig;  /**< "First" PDU mapped to mailbox. */
  CanIf_PduIdLastOfMailBoxConfigType PduIdLastOfMailBoxConfig;  /**< "Last" PDU mapped to mailbox. */
  CanIf_TxBufferCfgOfMailBoxConfigType TxBufferCfgOfMailBoxConfig;
  CanIf_TxBufferCfgIdxOfMailBoxConfigType TxBufferCfgIdxOfMailBoxConfig;  /**< the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdBitQueueConfig */
  CanIf_TxBufferHandlingTypeOfMailBoxConfigType TxBufferHandlingTypeOfMailBoxConfig;
  CanIf_MailBoxTypeType MailBoxTypeOfMailBoxConfig;  /**< Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused. */
} CanIf_MailBoxConfigType;

/**   \brief  type used in CanIf_MappedTxBuffersConfig */
/*! \spec weak type invariant () { 
 * (self.MailBoxConfigIdxOfMappedTxBuffersConfig < CanIf_GetSizeOfMailBoxConfig())
 * } */
typedef struct sCanIf_MappedTxBuffersConfigType
{
  CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType MailBoxConfigIdxOfMappedTxBuffersConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
} CanIf_MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_RxIndicationFctList */
typedef struct sCanIf_RxIndicationFctListType
{
  CanIf_RxIndicationFctType RxIndicationFctOfRxIndicationFctList;  /**< Rx indication function. */
  CanIf_RxIndicationLayoutType RxIndicationLayoutOfRxIndicationFctList;  /**< Layout of Rx indication function. */
} CanIf_RxIndicationFctListType;

/**   \brief  type used in CanIf_RxPduConfig */
/*! \spec weak type invariant () { 
 * (self.RxIndicationFctListIdxOfRxPduConfig < CanIf_GetSizeOfRxIndicationFctList())
 * } */
typedef struct sCanIf_RxPduConfigType
{
  CanIf_RxPduCanIdOfRxPduConfigType RxPduCanIdOfRxPduConfig;  /**< Rx-PDU: CAN identifier. */
  CanIf_RxPduMaskOfRxPduConfigType RxPduMaskOfRxPduConfig;  /**< Rx-PDU: CAN identifier mask. */
  CanIf_UpperPduIdOfRxPduConfigType UpperPduIdOfRxPduConfig;  /**< PDU ID defined by upper layer. */
  CanIf_RxIndicationFctListIdxOfRxPduConfigType RxIndicationFctListIdxOfRxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_RxIndicationFctList */
  CanIf_RxPduDlcOfRxPduConfigType RxPduDlcOfRxPduConfig;  /**< Rx-PDU length (DLC). */
} CanIf_RxPduConfigType;

/**   \brief  type used in CanIf_TxBufferPrioByCanIdBitQueueConfig */
/*! \spec weak type invariant () { 
 * (self.TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfig < CanIf_GetSizeOfTxBufferPrioByCanIdBase()) &&
 * (self.TxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfig < CanIf_GetSizeOfTxQueueFlags()) &&
 * (self.TxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfig < CanIf_GetSizeOfTxQueueFlags())
 * } */
typedef struct sCanIf_TxBufferPrioByCanIdBitQueueConfigType
{
  CanIf_BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdBitQueueConfigType BitPos2TxPduIdOffsetOfTxBufferPrioByCanIdBitQueueConfig;
  CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfigType TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdBitQueueConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase */
  CanIf_TxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfigType TxQueueFlagsEndIdxOfTxBufferPrioByCanIdBitQueueConfig;  /**< the end index of the 1:n relation pointing to CanIf_TxQueueFlags */
  CanIf_TxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfigType TxQueueFlagsStartIdxOfTxBufferPrioByCanIdBitQueueConfig;  /**< the start index of the 1:n relation pointing to CanIf_TxQueueFlags */
} CanIf_TxBufferPrioByCanIdBitQueueConfigType;

/**   \brief  type used in CanIf_TxPduConfig */
/*! \spec weak type invariant () { 
 * (self.CtrlStatesIdxOfTxPduConfig < CanIf_GetSizeOfCtrlStates()) &&
 * (self.MailBoxConfigIdxOfTxPduConfig < CanIf_GetSizeOfMailBoxConfig()) &&
 * (self.TxConfirmationFctListIdxOfTxPduConfig < CanIf_GetSizeOfTxConfirmationFctList())
 * } */
typedef struct sCanIf_TxPduConfigType
{
  CanIf_CanIdOfTxPduConfigType CanIdOfTxPduConfig;  /**< CAN identifier (16bit / 32bit). */
  CanIf_UpperLayerTxPduIdOfTxPduConfigType UpperLayerTxPduIdOfTxPduConfig;  /**< Upper layer handle-Id (8bit / 16bit). */
  CanIf_IsTxPduTruncationOfTxPduConfigType IsTxPduTruncationOfTxPduConfig;  /**< TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled */
  CanIf_CtrlStatesIdxOfTxPduConfigType CtrlStatesIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_MailBoxConfigIdxOfTxPduConfigType MailBoxConfigIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
  CanIf_TxConfirmationFctListIdxOfTxPduConfigType TxConfirmationFctListIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList */
  CanIf_TxPduLengthOfTxPduConfigType TxPduLengthOfTxPduConfig;  /**< Tx-PDU length. */
} CanIf_TxPduConfigType;

/**   \brief  type used in CanIf_TxPduQueueIndex */
/*! \spec weak type invariant () { 
 * (!((self.TxQueueIdxOfTxPduQueueIndex != CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX)) || ((( self.TxQueueOfTxPduQueueIndex == CANIF_TXQUEUE_TXQUEUEOFTXPDUQUEUEINDEX) && (self.TxQueueIdxOfTxPduQueueIndex < CanIf_GetSizeOfTxQueue()))))
 * } */
typedef struct sCanIf_TxPduQueueIndexType
{
  CanIf_TxQueueOfTxPduQueueIndexType TxQueueOfTxPduQueueIndex;
  CanIf_TxQueueIdxOfTxPduQueueIndexType TxQueueIdxOfTxPduQueueIndex;  /**< the index of the 0:1 relation pointing to CanIf_TxQueue */
} CanIf_TxPduQueueIndexType;

/**   \brief  type used in CanIf_WakeUpConfig */
typedef struct sCanIf_WakeUpConfigType
{
  CanIf_ControllerIdOfWakeUpConfigType ControllerIdOfWakeUpConfig;  /**< ControllerId of this wake-up source configuration */
  CanIf_WakeUpSourceOfWakeUpConfigType WakeUpSourceOfWakeUpConfig;  /**< Wake-up source identifier */
  CanIf_WakeUpTargetAddressOfWakeUpConfigType WakeUpTargetAddressOfWakeUpConfig;  /**< Target address of wake up source (driver independent handle Id): CAN controller (ControllerId)/CAN transceiver (TransceiverId) */
  CanIf_WakeUpTargetType WakeUpTargetModuleOfWakeUpConfig;  /**< Target module of wake-up source: CAN driver/CAN transceiver driver */
} CanIf_WakeUpConfigType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicStructTypes  CanIf Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates in the predefined variant Left */
typedef struct CanIf_CtrlStatesLeftStructSTag
{
  CanIf_CtrlStatesType RBTM_FL_BODY3_180ddaa4;
} CanIf_CtrlStatesLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates in the predefined variant Right */
typedef struct CanIf_CtrlStatesRightStructSTag
{
  CanIf_CtrlStatesType RBTM_FR_BODY3_2fec3d37;
} CanIf_CtrlStatesRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase in the predefined variant Left */
typedef struct CanIf_TxBufferPrioByCanIdBaseLeftStructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType BODY3_bccb160f;
} CanIf_TxBufferPrioByCanIdBaseLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase in the predefined variant Right */
typedef struct CanIf_TxBufferPrioByCanIdBaseRightStructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType BODY3_bccb160f;
} CanIf_TxBufferPrioByCanIdBaseRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue in the predefined variant Left */
typedef struct CanIf_TxQueueLeftStructSTag
{
  CanIf_TxPrioByCanIdBitQueueType BeltAdj_FL_Stat_ST3_df27ce55_Tx;
  CanIf_TxPrioByCanIdBitQueueType RBTM_FL_Stat_ST3_558a33d8_Tx;
  CanIf_TxPrioByCanIdBitQueueType Meas8_RBTM_FL_ST3_a87f4b23_Tx;
  CanIf_TxPrioByCanIdBitQueueType DIAG_RBTM_FL_03_IntEth_RS_ST3_de5e5f30_Tx;
  CanIf_TxPrioByCanIdBitQueueType DIAG_RBTM_FL_03_ExtCAN_RS_ST3_70f788c0_Tx;
  CanIf_TxPrioByCanIdBitQueueType DIAG_RBTM_FL_03_ExtEth_RS_ST3_5af4aefa_Tx;
  CanIf_TxPrioByCanIdBitQueueType Develop8_Rs_RBTM_FL_ST3_474b54d0_Tx;
  CanIf_TxPrioByCanIdBitQueueType ROE_RBTM_FL_ST3_e9956dfc_Tx;
  CanIf_TxPrioByCanIdBitQueueType ECU_Stat_RBTM_FL_ST3_b7e6aa56_Tx;
  CanIf_TxPrioByCanIdBitQueueType NM_RBTM_FL_ST3_8b5cec70_Tx;
  CanIf_TxPrioByCanIdBitQueueType RBTM_FL_Tens_ST3_1446be6f_Tx;
} CanIf_TxQueueLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue in the predefined variant Right */
typedef struct CanIf_TxQueueRightStructSTag
{
  CanIf_TxPrioByCanIdBitQueueType BeltAdj_FR_Stat_ST3_070be586_Tx;
  CanIf_TxPrioByCanIdBitQueueType RBTM_FR_Stat_ST3_b20121fa_Tx;
  CanIf_TxPrioByCanIdBitQueueType Meas8_RBTM_FR_ST3_492d97af_Tx;
  CanIf_TxPrioByCanIdBitQueueType DIAG_RBTM_FR_03_IntEth_RS_ST3_6c8422ac_Tx;
  CanIf_TxPrioByCanIdBitQueueType DIAG_RBTM_FR_03_ExtCAN_RS_ST3_d977ea77_Tx;
  CanIf_TxPrioByCanIdBitQueueType DIAG_RBTM_FR_03_ExtEth_RS_ST3_25545cfe_Tx;
  CanIf_TxPrioByCanIdBitQueueType Develop8_Rs_RBTM_FR_ST3_1a924f62_Tx;
  CanIf_TxPrioByCanIdBitQueueType ROE_RBTM_FR_ST3_d7dfdf54_Tx;
  CanIf_TxPrioByCanIdBitQueueType ECU_Stat_RBTM_FR_ST3_430ba797_Tx;
  CanIf_TxPrioByCanIdBitQueueType NM_RBTM_FR_ST3_d6dddcba_Tx;
  CanIf_TxPrioByCanIdBitQueueType RBTM_FR_Tens_ST3_019feca0_Tx;
} CanIf_TxQueueRightStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags in the predefined variant Left */
typedef struct CanIf_TxQueueFlagsLeftStructSTag
{
  CanIf_TxQueueFlagsType BODY3_bccb160f;
} CanIf_TxQueueFlagsLeftStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueueFlags in the predefined variant Right */
typedef struct CanIf_TxQueueFlagsRightStructSTag
{
  CanIf_TxQueueFlagsType BODY3_bccb160f;
} CanIf_TxQueueFlagsRightStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCUnionIndexAndSymbolTypes  CanIf Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access CanIf_CtrlStates in an index and symbol based style. */
typedef union CanIf_CtrlStatesUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_CtrlStatesType raw[1];
  CanIf_CtrlStatesLeftStructSType strLeft;
  CanIf_CtrlStatesRightStructSType strRight;
} CanIf_CtrlStatesUType;

/**   \brief  type to access CanIf_TxBufferPrioByCanIdBase in an index and symbol based style. */
typedef union CanIf_TxBufferPrioByCanIdBaseUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxBufferPrioByCanIdBaseType raw[1];
  CanIf_TxBufferPrioByCanIdBaseLeftStructSType strLeft;
  CanIf_TxBufferPrioByCanIdBaseRightStructSType strRight;
} CanIf_TxBufferPrioByCanIdBaseUType;

/**   \brief  type to access CanIf_TxQueue in an index and symbol based style. */
typedef union CanIf_TxQueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxPrioByCanIdBitQueueType raw[11];
  CanIf_TxQueueLeftStructSType strLeft;
  CanIf_TxQueueRightStructSType strRight;
} CanIf_TxQueueUType;

/**   \brief  type to access CanIf_TxQueueFlags in an index and symbol based style. */
typedef union CanIf_TxQueueFlagsUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  CanIf_TxQueueFlagsType raw[1];
  CanIf_TxQueueFlagsLeftStructSType strLeft;
  CanIf_TxQueueFlagsRightStructSType strRight;
} CanIf_TxQueueFlagsUType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootPointerTypes  CanIf Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanIf_BusOffNotificationFctPtr */
typedef P2CONST(CanIf_BusOffNotificationFctType, TYPEDEF, CANIF_CONST) CanIf_BusOffNotificationFctPtrPtrType;

/**   \brief  type used to point to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef P2CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, TYPEDEF, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfigPtrType;

/**   \brief  type used to point to CanIf_CtrlModeIndicationFctPtr */
typedef P2CONST(CanIf_CtrlModeIndicationFctType, TYPEDEF, CANIF_CONST) CanIf_CtrlModeIndicationFctPtrPtrType;

/**   \brief  type used to point to CanIf_CtrlStates */
typedef P2VAR(CanIf_CtrlStatesType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_CtrlStatesPtrType;

/**   \brief  type used to point to CanIf_MailBoxConfig */
typedef P2CONST(CanIf_MailBoxConfigType, TYPEDEF, CANIF_CONST) CanIf_MailBoxConfigPtrType;

/**   \brief  type used to point to CanIf_MappedTxBuffersConfig */
typedef P2CONST(CanIf_MappedTxBuffersConfigType, TYPEDEF, CANIF_CONST) CanIf_MappedTxBuffersConfigPtrType;

/**   \brief  type used to point to CanIf_RxIndicationFctList */
typedef P2CONST(CanIf_RxIndicationFctListType, TYPEDEF, CANIF_CONST) CanIf_RxIndicationFctListPtrType;

/**   \brief  type used to point to CanIf_RxPduConfig */
typedef P2CONST(CanIf_RxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_RxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdBase */
typedef P2VAR(CanIf_TxBufferPrioByCanIdBaseType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBasePtrType;

/**   \brief  type used to point to CanIf_TxBufferPrioByCanIdBitQueueConfig */
typedef P2CONST(CanIf_TxBufferPrioByCanIdBitQueueConfigType, TYPEDEF, CANIF_CONST) CanIf_TxBufferPrioByCanIdBitQueueConfigPtrType;

/**   \brief  type used to point to CanIf_TxConfirmationFctList */
typedef P2CONST(CanIf_TxConfirmationFctType, TYPEDEF, CANIF_CONST) CanIf_TxConfirmationFctListPtrType;

/**   \brief  type used to point to CanIf_TxPduConfig */
typedef P2CONST(CanIf_TxPduConfigType, TYPEDEF, CANIF_CONST) CanIf_TxPduConfigPtrType;

/**   \brief  type used to point to CanIf_TxPduQueueIndex */
typedef P2CONST(CanIf_TxPduQueueIndexType, TYPEDEF, CANIF_CONST) CanIf_TxPduQueueIndexPtrType;

/**   \brief  type used to point to CanIf_TxQueue */
typedef P2VAR(CanIf_TxPrioByCanIdBitQueueType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxQueuePtrType;

/**   \brief  type used to point to CanIf_TxQueueFlags */
typedef P2VAR(CanIf_TxQueueFlagsType, TYPEDEF, CANIF_VAR_NOINIT) CanIf_TxQueueFlagsPtrType;

/**   \brief  type used to point to CanIf_UlTxPduId2InternalTxPduId */
typedef P2CONST(CanIf_UlTxPduId2InternalTxPduIdType, TYPEDEF, CANIF_CONST) CanIf_UlTxPduId2InternalTxPduIdPtrType;

/**   \brief  type used to point to CanIf_WakeUpConfig */
typedef P2CONST(CanIf_WakeUpConfigType, TYPEDEF, CANIF_CONST) CanIf_WakeUpConfigPtrType;

/**   \brief  type used to point to CanIf_WakeUpValidationFctPtr */
typedef P2CONST(CanIf_WakeUpValidationFctType, TYPEDEF, CANIF_CONST) CanIf_WakeUpValidationFctPtrPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootValueTypes  CanIf Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanIf_PCConfig */
typedef struct sCanIf_PCConfigType
{
  CanIf_RxPduConfigPtrType RxPduConfigOfPCConfig;  /**< the pointer to CanIf_RxPduConfig */
  CanIf_TxPduConfigPtrType TxPduConfigOfPCConfig;  /**< the pointer to CanIf_TxPduConfig */
} CanIf_PCConfigType;

typedef CanIf_PCConfigType CanIf_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access CanIf_PCConfig in a symbol based style. */
typedef struct sCanIf_PCConfigsType
{
  CanIf_PCConfigType Config_Left;  /**< [Config_Left] */
  CanIf_PCConfigType Config_Right;  /**< [Config_Right] */
} CanIf_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfg         
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdBitQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[3];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[5];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigLeft
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigLeft
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigLeft[38];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfigRight
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfigRight
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  RxPduDlc                  Rx-PDU length (DLC).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfigRight[38];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBitQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBitQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BIT_QUEUE
  \details
  Element                       Description
  BitPos2TxPduIdOffset      
  TxBufferPrioByCanIdBaseIdx    the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxQueueFlagsEndIdx            the end index of the 1:n relation pointing to CanIf_TxQueueFlags
  TxQueueFlagsStartIdx          the start index of the 1:n relation pointing to CanIf_TxQueueFlags
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxBufferPrioByCanIdBitQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdBitQueueConfig[1];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[4];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigLeft
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigLeft
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigLeft[11];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfigRight
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfigRight
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle-Id (8bit / 16bit).
  IsTxPduTruncation           TRUE: Truncation of Tx-PDU is enabled, FALSE: Truncation of Tx-PDU is disabled
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
  TxPduLength                 Tx-PDU length.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfigRight[11];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle-Id to corresponding Tx buffer handle-Id. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element       Description
  TxQueue   
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[11];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_UlTxPduId2InternalTxPduId
**********************************************************************************************************************/
/** 
  \var    CanIf_UlTxPduId2InternalTxPduId
  \brief  Indirection table - Upper layer Tx-PduId to internal one.
*/ 
#define CANIF_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_UlTxPduId2InternalTxPduIdType, CANIF_CONST) CanIf_UlTxPduId2InternalTxPduId[11];
#define CANIF_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_WakeUpConfig
  \brief  Wake-up source configuration
  \details
  Element                Description
  ControllerId           ControllerId of this wake-up source configuration
  WakeUpSource           Wake-up source identifier
  WakeUpTargetAddress    Target address of wake up source (driver independent handle Id): CAN controller (ControllerId)/CAN transceiver (TransceiverId)
  WakeUpTargetModule     Target module of wake-up source: CAN driver/CAN transceiver driver
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_WakeUpConfigType, CANIF_CONST) CanIf_WakeUpConfig[1];
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_WakeUpValidationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_WakeUpValidationFctType, CANIF_CONST) CanIf_WakeUpValidationFctPtr;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element                  Description
  CtrlMode                 Controller mode.
  PduMode                  PDU mode state.
  WakeUpValidationState    Wake-up validation state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx bit queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueFlags
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueFlags
  \brief  Variable declaration - Tx bit queue flags.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanIf_TxQueueFlagsUType, CANIF_VAR_NOINIT) CanIf_TxQueueFlags;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CANIF_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_PCConfig
  \details
  Element        Description
  RxPduConfig    the pointer to CanIf_RxPduConfig
  TxPduConfig    the pointer to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanIf_PCConfigsType, CANIF_CONST) CanIf_PCConfig;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "CanIf_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/




#endif  /* CANIF_CFG_H */
/**********************************************************************************************************************
  END OF FILE: CanIf_Cfg.h
**********************************************************************************************************************/


