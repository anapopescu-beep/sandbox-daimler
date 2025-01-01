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
 *            Module: CanTp
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTp_Cfg.h
 *   Generation Time: 2023-07-05 16:23:55
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined(CANTP_CFG_H)
#define CANTP_CFG_H

/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */

#include "ComStack_Types.h"

/* Definition of feature switches in the library delivered */
#ifndef CANTP_USE_DUMMY_STATEMENT
#define CANTP_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTP_DUMMY_STATEMENT
#define CANTP_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTP_DUMMY_STATEMENT_CONST
#define CANTP_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANTP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANTP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANTP_ATOMIC_VARIABLE_ACCESS
#define CANTP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANTP_PROCESSOR_TC322L
#define CANTP_PROCESSOR_TC322L
#endif
#ifndef CANTP_COMP_TASKING
#define CANTP_COMP_TASKING
#endif
#ifndef CANTP_GEN_GENERATOR_MSR
#define CANTP_GEN_GENERATOR_MSR
#endif
#ifndef CANTP_CPUTYPE_BITORDER_LSB2MSB
#define CANTP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANTP_CONFIGURATION_VARIANT_PRECOMPILE
#define CANTP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANTP_CONFIGURATION_VARIANT_LINKTIME
#define CANTP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANTP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANTP_CONFIGURATION_VARIANT
#define CANTP_CONFIGURATION_VARIANT CANTP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANTP_POSTBUILD_VARIANT_SUPPORT
#define CANTP_POSTBUILD_VARIANT_SUPPORT STD_ON
#endif


/* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
 /*  Version information  */ 
#define CANTP_CFG_GEN_MAJOR_VERSION                                            5u 
#define CANTP_CFG_GEN_MINOR_VERSION                                            0u 
#define CANTP_CFG_GEN_PATCH_VERSION                                            0u 

 /*  Global defines  */ 
#define CANTP_VERSION_INFO_API                                                 STD_OFF 
#define CANTP_DEV_ERROR_DETECT                                                 STD_OFF 
#define CANTP_DEV_ERROR_REPORT                                                 STD_OFF 
#define CANTP_TC                                                               STD_OFF 
#define CANTP_RC                                                               STD_OFF 
#define CANTP_INVALID_HDL                                                      ((PduIdType) 255u) 
#define CANTP_TASK_CYCLE                                                       5u 

 /*  Global constant defines  */ 
#define CANTP_MAX_FRAME_LENGTH                                                 8u 
#define CANTP_MAX_PAYLOAD_LENGTH                                               7u 
#define CANTP_MAX_PDU_METADATA_LENGTH                                          0u 
#define CANTP_MAX_SDU_METADATA_LENGTH                                          0u 
#define CANTP_NUM_RX_CHANNELS                                                  CanTp_GetSizeOfRxState() 
#define CANTP_NUM_RX_SDUS                                                      6 
#define CANTP_NUM_TX_CHANNELS                                                  CanTp_GetSizeOfTxState() 
#define CANTP_NUM_TX_SDUS                                                      3 
#define CANTP_SIZEOF_PDULENGTHTYPE                                             2 

 /*  Communication Type  */ 
#define CANTP_MODE_FULL_DUPLEX                                                 1u 
#define CANTP_MODE_HALF_DUPLEX                                                 0u 
#define CANTP_TATYPE_FUNCTIONAL                                                1u 
#define CANTP_TATYPE_PHYSICAL                                                  0u 

 /*  CanTp Adress Format  */ 
#define CANTP_ADDRESS_FORMAT_CUSTOM                                            5u 
#define CANTP_ADDRESS_FORMAT_EXTENDED                                          1u 
#define CANTP_ADDRESS_FORMAT_MIXED11                                           2u 
#define CANTP_ADDRESS_FORMAT_MIXED29                                           4u 
#define CANTP_ADDRESS_FORMAT_NORMALFIXED                                       3u 
#define CANTP_ADDRESS_FORMAT_STANDARD                                          0u 

 /*  Can Type  */ 
#define CANTP_CANTYPE_CAN20                                                    0u 
#define CANTP_CANTYPE_CANFD                                                    1u 

 /*  Vector-CanTp extended capabilities  */ 
#define CANTP_GENERATOR_COMPATIBILITY_VERSION                                  0x00086838u                                                    /* Extended error detection capabilities */ 
#define CANTP_CAN20_PADDING_ACTIVE                                             STD_ON 
#define CANTP_HAVE_PADDING_BYTE                                                STD_OFF 
#define CANTP_PADDING_PATTERN                                                  0x00u                                                          /* Padding byte to be used for the Tx side if CANTP_HAVE_PADDING_BYTE is ON */ 
#define CANTP_DYN_CHANNEL_ASSIGNMENT                                           STD_OFF 
#define CANTP_STANDARD_ADDRESSING                                              STD_ON 
#define CANTP_EXTENDED_ADDRESSING                                              STD_OFF 
#define CANTP_MIXED11_ADDRESSING                                               STD_OFF 
#define CANTP_MIXED29_ADDRESSING                                               STD_ON 
#define CANTP_NORMALFIXED_ADDRESSING                                           STD_ON 
#define CANTP_CUSTOM_ADDRESSING                                                STD_OFF 
#define CANTP_SINGLE_RX_BUFFER_OPTIMIZED                                       STD_OFF 
#define CANTP_RXTX_MAINFUNCTION_API                                            STD_OFF 
#define CANTP_CONSTANT_BS                                                      STD_ON 
#define CANTP_REJECT_FC_WITH_RES_STMIN                                         STD_OFF 
#define CANTP_USE_ONLY_FIRST_FC                                                STD_OFF 
#define CANTP_ENABLE_CHANGE_PARAM                                              STD_ON 
#define CANTP_ENABLE_READ_PARAM                                                STD_ON 
#define CANTP_ONLY_NOTIFY_INFORMED_APPL                                        STD_ON 
#define CANTP_TRANSMIT_QUEUE                                                   STD_OFF 
#define CANTP_SUPPORT_LONG_FF                                                  STD_ON 
#define CANTP_PDUR_API_AR_VERSION                                              0x412 
#define CANTP_SYNC_TRANSMIT                                                    STD_ON 
#define CANTP_SUPPORT_CANFD                                                    STD_ON 
#define CANTP_STMIN_BY_APPL                                                    STD_OFF 
#define CANTP_DCM_REQUEST_DETECT                                               STD_OFF 
#define CANTP_GENERIC_CONNECTIONS                                              STD_OFF 
#define CanTp_ApplStartSeparationTime                                           /*  mapping of user defined function to internal name  */  

 /*  CanTp Lower Layer  */ 
#define CANTP_LOLAYER_CANIF                                                    STD_ON 
#define CANTP_LOLAYER_TC                                                       STD_OFF 
#define CanTp_CanIfCancelTransmit(Dir, SduId, PduId)                            
#define CanTp_CanIfTransmit(Dir, SduId, PduId, Data)                           (CanIf_Transmit((PduId),(Data))) 


/* PRQA L:MACROS_3453 */



/* -----------------------------------------------------------------------------
    &&&~ Pre-Compile optimized configuration
 ----------------------------------------------------------------------------- */
 




/* -----------------------------------------------------------------------------
    &&&~ Rx Sdu Handle IDs
----------------------------------------------------------------------------- */
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_64c01817 0u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_e35239dd 0u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_4a102435 1u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_84669b72 1u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_44714e59 2u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_dbf7577d 2u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_036251db 3u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_530d12e8 3u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_690fe637 4u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_b14888e8 4u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_6f7c1760 5u 
#define CanTpConf_CanTpRxNSdu_CanTpRxNSdu_b61ae5cc 5u 

 
/* -----------------------------------------------------------------------------
    &&&~ Tx Sdu Handle IDs
----------------------------------------------------------------------------- */
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_036251db 0u 
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_530d12e8 0u 
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_690fe637 1u 
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_b14888e8 1u 
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_6f7c1760 2u 
#define CanTpConf_CanTpTxNSdu_CanTpTxNSdu_b61ae5cc 2u 


/* -----------------------------------------------------------------------------
    &&&~ Rx Pdu IDs
 ----------------------------------------------------------------------------- */
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_5cdfcb87 0u 
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_ebeac4b1 0u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_7e251f75     0u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_c9101043     0u 
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_0d718dab 1u 
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_619ae506 1u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2f8b5959     1u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_436031f4     1u 
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_69e55a14 2u 
#define CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_8d1b8033 2u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4b1f8ee6     2u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_afe154c1     2u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_42fcb720     3u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_a8dd74b8     3u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2dd5cd3e     4u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_4461701a     4u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_29880c5f     5u 
#define CanTpConf_CanTpRxNPdu_CanTpRxNPdu_68607596     5u 


/* -----------------------------------------------------------------------------
    &&&~ TxConfirmation Pdu IDs
 ----------------------------------------------------------------------------- */
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_7e251f75 0u 
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_c9101043 0u 
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_5cdfcb87     0u 
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_ebeac4b1     0u 
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_2f8b5959 1u 
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_436031f4 1u 
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_0d718dab     1u 
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_619ae506     1u 
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_4b1f8ee6 2u 
#define CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_afe154c1 2u 
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_69e55a14     2u 
#define CanTpConf_CanTpTxNPdu_CanTpTxNPdu_8d1b8033     2u 




 /**********************************************************************************************************************
 * MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTpPCDataSwitches  CanTp Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANTP_CALCBS                                                                                STD_ON
#define CANTP_COMPATIBILITYVERSION                                                                  STD_ON
#define CANTP_DYNFCPARAMETERS                                                                       STD_ON
#define CANTP_FINALMAGICNUMBER                                                                      STD_OFF  /**< Deactivateable: 'CanTp_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANTP_INITDATAHASHCODE                                                                      STD_OFF  /**< Deactivateable: 'CanTp_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANTP_LOLAYERFCTS                                                                           STD_OFF  /**< Deactivateable: 'CanTp_LoLayerFcts' Reason: 'A function table is not required, since just one lower layer exists.' */
#define CANTP_CANCELTRANSMITFCTOFLOLAYERFCTS                                                        STD_OFF  /**< Deactivateable: 'CanTp_LoLayerFcts.CancelTransmitFct' Reason: 'A function table is not required, since just one lower layer exists.' */
#define CANTP_TRANSMITFCTOFLOLAYERFCTS                                                              STD_OFF  /**< Deactivateable: 'CanTp_LoLayerFcts.TransmitFct' Reason: 'A function table is not required, since just one lower layer exists.' */
#define CANTP_RXCHANNELMAP                                                                          STD_OFF  /**< Deactivateable: 'CanTp_RxChannelMap' Reason: 'Dynamic Channel Assignment is disabled' and Deactivateable: 'CanTp_RxChannelMap' Reason: 'Dynamic Channel Assignment is disabled' */
#define CANTP_RXPDUMAP                                                                              STD_ON
#define CANTP_ADDRESSINGFORMATOFRXPDUMAP                                                            STD_ON
#define CANTP_GENERICCONNECTIONOFRXPDUMAP                                                           STD_ON
#define CANTP_PDUMETADATALENGTHOFRXPDUMAP                                                           STD_ON
#define CANTP_RXSDUCFGINDENDIDXOFRXPDUMAP                                                           STD_ON
#define CANTP_RXSDUCFGINDSTARTIDXOFRXPDUMAP                                                         STD_ON
#define CANTP_RXSDUCFGINDUSEDOFRXPDUMAP                                                             STD_ON
#define CANTP_TXSDUCFGINDENDIDXOFRXPDUMAP                                                           STD_ON
#define CANTP_TXSDUCFGINDSTARTIDXOFRXPDUMAP                                                         STD_ON
#define CANTP_TXSDUCFGINDUSEDOFRXPDUMAP                                                             STD_ON
#define CANTP_RXSDUCFG                                                                              STD_ON
#define CANTP_BLOCKSIZEOFRXSDUCFG                                                                   STD_ON
#define CANTP_CANTYPEOFRXSDUCFG                                                                     STD_ON
#define CANTP_CHANNELMODEOFRXSDUCFG                                                                 STD_ON
#define CANTP_GENERICCONNECTIONOFRXSDUCFG                                                           STD_ON
#define CANTP_LOLAYERFCTSIDXOFRXSDUCFG                                                              STD_OFF  /**< Deactivateable: 'CanTp_RxSduCfgRBTM_FL.LoLayerFctsIdx' Reason: 'All indirection targets are deactivated in all variants.' and Deactivateable: 'CanTp_RxSduCfgRBTM_FR.LoLayerFctsIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define CANTP_LOLAYERTXFCPDUIDOFRXSDUCFG                                                            STD_ON
#define CANTP_NAROFRXSDUCFG                                                                         STD_ON
#define CANTP_NBROFRXSDUCFG                                                                         STD_ON
#define CANTP_NCROFRXSDUCFG                                                                         STD_ON
#define CANTP_PDUMETADATALENGTHOFRXSDUCFG                                                           STD_ON
#define CANTP_PDURRXSDUIDOFRXSDUCFG                                                                 STD_ON
#define CANTP_RXADDRESSOFRXSDUCFG                                                                   STD_ON
#define CANTP_RXADDRESSINGFORMATOFRXSDUCFG                                                          STD_ON
#define CANTP_RXMAXPAYLOADLENGTHOFRXSDUCFG                                                          STD_ON
#define CANTP_RXPADDINGACTIVATIONOFRXSDUCFG                                                         STD_ON
#define CANTP_RXPDUIDOFRXSDUCFG                                                                     STD_ON
#define CANTP_RXTATYPEOFRXSDUCFG                                                                    STD_ON
#define CANTP_RXWFTMAXOFRXSDUCFG                                                                    STD_ON
#define CANTP_STMINOFRXSDUCFG                                                                       STD_ON
#define CANTP_SDUMETADATALENGTHOFRXSDUCFG                                                           STD_ON
#define CANTP_TXFCADDRESSOFRXSDUCFG                                                                 STD_ON
#define CANTP_TXFCPDUCONFIRMATIONPDUIDOFRXSDUCFG                                                    STD_ON
#define CANTP_TXSDUCFGIDXOFRXSDUCFG                                                                 STD_ON
#define CANTP_TXSDUCFGUSEDOFRXSDUCFG                                                                STD_ON
#define CANTP_UPLAYERFCTSRXIDXOFRXSDUCFG                                                            STD_OFF  /**< Deactivateable: 'CanTp_RxSduCfgRBTM_FL.UpLayerFctsRxIdx' Reason: 'the optional indirection is deactivated because UpLayerFctsRxUsedOfRxSduCfg is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanTp_RxSduCfgRBTM_FR.UpLayerFctsRxIdx' Reason: 'the optional indirection is deactivated because UpLayerFctsRxUsedOfRxSduCfg is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANTP_UPLAYERFCTSRXUSEDOFRXSDUCFG                                                           STD_OFF  /**< Deactivateable: 'CanTp_RxSduCfgRBTM_FL.UpLayerFctsRxUsed' Reason: 'the optional indirection is deactivated because UpLayerFctsRxUsedOfRxSduCfg is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanTp_RxSduCfgRBTM_FR.UpLayerFctsRxUsed' Reason: 'the optional indirection is deactivated because UpLayerFctsRxUsedOfRxSduCfg is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANTP_RXSDUCFGIND                                                                           STD_ON
#define CANTP_RXSDUSNV2HDL                                                                          STD_ON
#define CANTP_RXSDUCFGIDXOFRXSDUSNV2HDL                                                             STD_ON
#define CANTP_RXSDUCFGUSEDOFRXSDUSNV2HDL                                                            STD_ON
#define CANTP_RXSTATE                                                                               STD_ON
#define CANTP_SIZEOFCALCBS                                                                          STD_ON
#define CANTP_SIZEOFDYNFCPARAMETERS                                                                 STD_ON
#define CANTP_SIZEOFRXPDUMAP                                                                        STD_ON
#define CANTP_SIZEOFRXSDUCFG                                                                        STD_ON
#define CANTP_SIZEOFRXSDUCFGIND                                                                     STD_ON
#define CANTP_SIZEOFRXSDUSNV2HDL                                                                    STD_ON
#define CANTP_SIZEOFRXSTATE                                                                         STD_ON
#define CANTP_SIZEOFTXSDUCFG                                                                        STD_ON
#define CANTP_SIZEOFTXSDUCFGIND                                                                     STD_ON
#define CANTP_SIZEOFTXSDUSNV2HDL                                                                    STD_ON
#define CANTP_SIZEOFTXSEMAPHORES                                                                    STD_ON
#define CANTP_SIZEOFTXSTATE                                                                         STD_ON
#define CANTP_TXCHANNELMAP                                                                          STD_OFF  /**< Deactivateable: 'CanTp_TxChannelMap' Reason: 'Dynamic Channel Assignment is disabled' and Deactivateable: 'CanTp_TxChannelMap' Reason: 'Dynamic Channel Assignment is disabled' */
#define CANTP_TXQUEUE                                                                               STD_OFF  /**< Deactivateable: 'CanTp_TxQueue' Reason: 'Transmit Queue is disabled' and Deactivateable: 'CanTp_TxQueue' Reason: 'Transmit Queue is disabled' */
#define CANTP_TXSDUCFG                                                                              STD_ON
#define CANTP_CANTYPEOFTXSDUCFG                                                                     STD_ON
#define CANTP_CHANNELMODEOFTXSDUCFG                                                                 STD_ON
#define CANTP_LOLAYERFCTSIDXOFTXSDUCFG                                                              STD_OFF  /**< Deactivateable: 'CanTp_TxSduCfgRBTM_FL.LoLayerFctsIdx' Reason: 'All indirection targets are deactivated in all variants.' and Deactivateable: 'CanTp_TxSduCfgRBTM_FR.LoLayerFctsIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define CANTP_LOLAYERTXPDUIDOFTXSDUCFG                                                              STD_ON
#define CANTP_NASOFTXSDUCFG                                                                         STD_ON
#define CANTP_NBSOFTXSDUCFG                                                                         STD_ON
#define CANTP_NCSOFTXSDUCFG                                                                         STD_ON
#define CANTP_PDUMETADATALENGTHOFTXSDUCFG                                                           STD_ON
#define CANTP_PDURTXSDUIDOFTXSDUCFG                                                                 STD_ON
#define CANTP_RXFCADDRESSOFTXSDUCFG                                                                 STD_ON
#define CANTP_RXFCPDUIDOFTXSDUCFG                                                                   STD_ON
#define CANTP_RXSDUCFGIDXOFTXSDUCFG                                                                 STD_ON
#define CANTP_RXSDUCFGUSEDOFTXSDUCFG                                                                STD_ON
#define CANTP_SDUMETADATALENGTHOFTXSDUCFG                                                           STD_ON
#define CANTP_TRANSMITCANCELLATIONOFTXSDUCFG                                                        STD_ON
#define CANTP_TXADDRESSOFTXSDUCFG                                                                   STD_ON
#define CANTP_TXADDRESSINGFORMATOFTXSDUCFG                                                          STD_ON
#define CANTP_TXMAXPAYLOADLENGTHOFTXSDUCFG                                                          STD_ON
#define CANTP_TXPADDINGACTIVATIONOFTXSDUCFG                                                         STD_ON
#define CANTP_TXPDUCONFIRMATIONPDUIDOFTXSDUCFG                                                      STD_ON
#define CANTP_TXTATYPEOFTXSDUCFG                                                                    STD_ON
#define CANTP_UPLAYERFCTSTXIDXOFTXSDUCFG                                                            STD_OFF  /**< Deactivateable: 'CanTp_TxSduCfgRBTM_FL.UpLayerFctsTxIdx' Reason: 'the optional indirection is deactivated because UpLayerFctsTxUsedOfTxSduCfg is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanTp_TxSduCfgRBTM_FR.UpLayerFctsTxIdx' Reason: 'the optional indirection is deactivated because UpLayerFctsTxUsedOfTxSduCfg is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANTP_UPLAYERFCTSTXUSEDOFTXSDUCFG                                                           STD_OFF  /**< Deactivateable: 'CanTp_TxSduCfgRBTM_FL.UpLayerFctsTxUsed' Reason: 'the optional indirection is deactivated because UpLayerFctsTxUsedOfTxSduCfg is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'CanTp_TxSduCfgRBTM_FR.UpLayerFctsTxUsed' Reason: 'the optional indirection is deactivated because UpLayerFctsTxUsedOfTxSduCfg is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CANTP_TXSDUCFGIND                                                                           STD_ON
#define CANTP_TXSDUSNV2HDL                                                                          STD_ON
#define CANTP_TXSDUCFGIDXOFTXSDUSNV2HDL                                                             STD_ON
#define CANTP_TXSDUCFGUSEDOFTXSDUSNV2HDL                                                            STD_ON
#define CANTP_TXSEMAPHORES                                                                          STD_ON
#define CANTP_TXSTATE                                                                               STD_ON
#define CANTP_UPLAYERFCTSRX                                                                         STD_OFF  /**< Deactivateable: 'CanTp_UpLayerFctsRx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTp_UpLayerFctsRx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTP_UPLAYERFCTSTX                                                                         STD_OFF  /**< Deactivateable: 'CanTp_UpLayerFctsTx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'CanTp_UpLayerFctsTx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANTP_PCCONFIG                                                                              STD_ON
#define CANTP_CALCBSOFPCCONFIG                                                                      STD_ON
#define CANTP_COMPATIBILITYVERSIONOFPCCONFIG                                                        STD_ON
#define CANTP_DYNFCPARAMETERSOFPCCONFIG                                                             STD_ON
#define CANTP_FINALMAGICNUMBEROFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanTp_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANTP_INITDATAHASHCODEOFPCCONFIG                                                            STD_OFF  /**< Deactivateable: 'CanTp_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANTP_RXPDUMAPOFPCCONFIG                                                                    STD_ON
#define CANTP_RXSDUCFGINDOFPCCONFIG                                                                 STD_ON
#define CANTP_RXSDUCFGOFPCCONFIG                                                                    STD_ON
#define CANTP_RXSDUSNV2HDLOFPCCONFIG                                                                STD_ON
#define CANTP_RXSTATEOFPCCONFIG                                                                     STD_ON
#define CANTP_SIZEOFCALCBSOFPCCONFIG                                                                STD_ON
#define CANTP_SIZEOFDYNFCPARAMETERSOFPCCONFIG                                                       STD_ON
#define CANTP_SIZEOFRXPDUMAPOFPCCONFIG                                                              STD_ON
#define CANTP_SIZEOFRXSDUCFGINDOFPCCONFIG                                                           STD_ON
#define CANTP_SIZEOFRXSDUCFGOFPCCONFIG                                                              STD_ON
#define CANTP_SIZEOFRXSDUSNV2HDLOFPCCONFIG                                                          STD_ON
#define CANTP_SIZEOFRXSTATEOFPCCONFIG                                                               STD_ON
#define CANTP_SIZEOFTXSDUCFGINDOFPCCONFIG                                                           STD_ON
#define CANTP_SIZEOFTXSDUCFGOFPCCONFIG                                                              STD_ON
#define CANTP_SIZEOFTXSDUSNV2HDLOFPCCONFIG                                                          STD_ON
#define CANTP_SIZEOFTXSEMAPHORESOFPCCONFIG                                                          STD_ON
#define CANTP_SIZEOFTXSTATEOFPCCONFIG                                                               STD_ON
#define CANTP_TXSDUCFGINDOFPCCONFIG                                                                 STD_ON
#define CANTP_TXSDUCFGOFPCCONFIG                                                                    STD_ON
#define CANTP_TXSDUSNV2HDLOFPCCONFIG                                                                STD_ON
#define CANTP_TXSEMAPHORESOFPCCONFIG                                                                STD_ON
#define CANTP_TXSTATEOFPCCONFIG                                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCMinNumericValueDefines  CanTp Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CANTP_MIN_CALCBS                                                                            0u
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCMaxNumericValueDefines  CanTp Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CANTP_MAX_CALCBS                                                                            255u
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCNoReferenceDefines  CanTp No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANTP_NO_RXSDUCFGINDENDIDXOFRXPDUMAP                                                        255u
#define CANTP_NO_RXSDUCFGINDSTARTIDXOFRXPDUMAP                                                      255u
#define CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP                                                        255u
#define CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP                                                      255u
#define CANTP_NO_TXSDUCFGIDXOFRXSDUCFG                                                              255u
#define CANTP_NO_RXSDUCFGIDXOFRXSDUSNV2HDL                                                          255u
#define CANTP_NO_RXSDUCFGIDXOFTXSDUCFG                                                              255u
#define CANTP_NO_TXSDUCFGIDXOFTXSDUSNV2HDL                                                          255u
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCEnumExistsDefines  CanTp Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CANTP_EXISTS_NORMAL_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                   STD_ON
#define CANTP_EXISTS_EXTENDED_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                 STD_OFF
#define CANTP_EXISTS_MIXED11_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                  STD_OFF
#define CANTP_EXISTS_NORMALFIXED_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                              STD_OFF
#define CANTP_EXISTS_MIXED29_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                  STD_OFF
#define CANTP_EXISTS_CUSTOM_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                   STD_OFF
#define CANTP_EXISTS_CAN20_CANTYPEOFRXSDUCFG                                                        STD_ON
#define CANTP_EXISTS_CANFD_CANTYPEOFRXSDUCFG                                                        STD_OFF
#define CANTP_EXISTS_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG                                              STD_ON
#define CANTP_EXISTS_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG                                              STD_ON
#define CANTP_EXISTS_NORMAL_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                 STD_ON
#define CANTP_EXISTS_EXTENDED_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                               STD_OFF
#define CANTP_EXISTS_MIXED11_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                STD_OFF
#define CANTP_EXISTS_NORMALFIXED_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                            STD_OFF
#define CANTP_EXISTS_MIXED29_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                STD_OFF
#define CANTP_EXISTS_CUSTOM_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                 STD_OFF
#define CANTP_EXISTS_PHYSICAL_RXTATYPEOFRXSDUCFG                                                    STD_ON
#define CANTP_EXISTS_FUNCTIONAL_RXTATYPEOFRXSDUCFG                                                  STD_ON
#define CANTP_EXISTS_CANFD_PHYSICAL_RXTATYPEOFRXSDUCFG                                              STD_ON
#define CANTP_EXISTS_CANFD_FUNCTIONAL_RXTATYPEOFRXSDUCFG                                            STD_ON
#define CANTP_EXISTS_CAN20_CANTYPEOFTXSDUCFG                                                        STD_ON
#define CANTP_EXISTS_CANFD_CANTYPEOFTXSDUCFG                                                        STD_OFF
#define CANTP_EXISTS_HALF_DUPLEX_CHANNELMODEOFTXSDUCFG                                              STD_OFF
#define CANTP_EXISTS_FULL_DUPLEX_CHANNELMODEOFTXSDUCFG                                              STD_ON
#define CANTP_EXISTS_NORMAL_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                 STD_ON
#define CANTP_EXISTS_EXTENDED_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                               STD_OFF
#define CANTP_EXISTS_MIXED11_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                STD_OFF
#define CANTP_EXISTS_NORMALFIXED_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                            STD_OFF
#define CANTP_EXISTS_MIXED29_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                STD_OFF
#define CANTP_EXISTS_CUSTOM_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                 STD_OFF
#define CANTP_EXISTS_PHYSICAL_TXTATYPEOFTXSDUCFG                                                    STD_ON
#define CANTP_EXISTS_FUNCTIONAL_TXTATYPEOFTXSDUCFG                                                  STD_OFF
#define CANTP_EXISTS_CANFD_PHYSICAL_TXTATYPEOFTXSDUCFG                                              STD_ON
#define CANTP_EXISTS_CANFD_FUNCTIONAL_TXTATYPEOFTXSDUCFG                                            STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCEnumDefines  CanTp Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CANTP_NORMAL_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP                                          0x00u
#define CANTP_CAN20_CANTYPEOFRXSDUCFG                                                               0x00u
#define CANTP_HALF_DUPLEX_CHANNELMODEOFRXSDUCFG                                                     0x00u
#define CANTP_FULL_DUPLEX_CHANNELMODEOFRXSDUCFG                                                     0x01u
#define CANTP_NORMAL_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG                                        0x00u
#define CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG                                                           0x00u
#define CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG                                                         0x01u
#define CANTP_CANFD_PHYSICAL_RXTATYPEOFRXSDUCFG                                                     0x00u
#define CANTP_CANFD_FUNCTIONAL_RXTATYPEOFRXSDUCFG                                                   0x01u
#define CANTP_CAN20_CANTYPEOFTXSDUCFG                                                               0x00u
#define CANTP_FULL_DUPLEX_CHANNELMODEOFTXSDUCFG                                                     0x01u
#define CANTP_NORMAL_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG                                        0x00u
#define CANTP_PHYSICAL_TXTATYPEOFTXSDUCFG                                                           0x00u
#define CANTP_CANFD_PHYSICAL_TXTATYPEOFTXSDUCFG                                                     0x00u
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCIsReducedToDefineDefines  CanTp Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANTP_ISDEF_ADDRESSINGFORMATOFRXPDUMAP                                                      STD_ON
#define CANTP_ISDEF_GENERICCONNECTIONOFRXPDUMAP                                                     STD_ON
#define CANTP_ISDEF_PDUMETADATALENGTHOFRXPDUMAP                                                     STD_ON
#define CANTP_ISDEF_RXSDUCFGINDENDIDXOFRXPDUMAP                                                     STD_OFF
#define CANTP_ISDEF_RXSDUCFGINDSTARTIDXOFRXPDUMAP                                                   STD_OFF
#define CANTP_ISDEF_RXSDUCFGINDUSEDOFRXPDUMAP                                                       STD_ON
#define CANTP_ISDEF_TXSDUCFGINDENDIDXOFRXPDUMAP                                                     STD_OFF
#define CANTP_ISDEF_TXSDUCFGINDSTARTIDXOFRXPDUMAP                                                   STD_OFF
#define CANTP_ISDEF_TXSDUCFGINDUSEDOFRXPDUMAP                                                       STD_OFF
#define CANTP_ISDEF_BLOCKSIZEOFRXSDUCFG                                                             STD_OFF
#define CANTP_ISDEF_CANTYPEOFRXSDUCFG                                                               STD_ON
#define CANTP_ISDEF_CHANNELMODEOFRXSDUCFG                                                           STD_OFF
#define CANTP_ISDEF_GENERICCONNECTIONOFRXSDUCFG                                                     STD_ON
#define CANTP_ISDEF_LOLAYERTXFCPDUIDOFRXSDUCFG                                                      STD_OFF
#define CANTP_ISDEF_NAROFRXSDUCFG                                                                   STD_OFF
#define CANTP_ISDEF_NBROFRXSDUCFG                                                                   STD_OFF
#define CANTP_ISDEF_NCROFRXSDUCFG                                                                   STD_OFF
#define CANTP_ISDEF_PDUMETADATALENGTHOFRXSDUCFG                                                     STD_ON
#define CANTP_ISDEF_PDURRXSDUIDOFRXSDUCFG                                                           STD_OFF
#define CANTP_ISDEF_RXADDRESSOFRXSDUCFG                                                             STD_ON
#define CANTP_ISDEF_RXADDRESSINGFORMATOFRXSDUCFG                                                    STD_ON
#define CANTP_ISDEF_RXMAXPAYLOADLENGTHOFRXSDUCFG                                                    STD_ON
#define CANTP_ISDEF_RXPADDINGACTIVATIONOFRXSDUCFG                                                   STD_ON
#define CANTP_ISDEF_RXPDUIDOFRXSDUCFG                                                               STD_OFF
#define CANTP_ISDEF_RXTATYPEOFRXSDUCFG                                                              STD_OFF
#define CANTP_ISDEF_RXWFTMAXOFRXSDUCFG                                                              STD_OFF
#define CANTP_ISDEF_STMINOFRXSDUCFG                                                                 STD_ON
#define CANTP_ISDEF_SDUMETADATALENGTHOFRXSDUCFG                                                     STD_ON
#define CANTP_ISDEF_TXFCADDRESSOFRXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_TXFCPDUCONFIRMATIONPDUIDOFRXSDUCFG                                              STD_OFF
#define CANTP_ISDEF_TXSDUCFGIDXOFRXSDUCFG                                                           STD_OFF
#define CANTP_ISDEF_TXSDUCFGUSEDOFRXSDUCFG                                                          STD_OFF
#define CANTP_ISDEF_RXSDUCFGIND                                                                     STD_OFF
#define CANTP_ISDEF_RXSDUCFGIDXOFRXSDUSNV2HDL                                                       STD_OFF
#define CANTP_ISDEF_RXSDUCFGUSEDOFRXSDUSNV2HDL                                                      STD_ON
#define CANTP_ISDEF_CANTYPEOFTXSDUCFG                                                               STD_ON
#define CANTP_ISDEF_CHANNELMODEOFTXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_LOLAYERTXPDUIDOFTXSDUCFG                                                        STD_OFF
#define CANTP_ISDEF_NASOFTXSDUCFG                                                                   STD_ON
#define CANTP_ISDEF_NBSOFTXSDUCFG                                                                   STD_ON
#define CANTP_ISDEF_NCSOFTXSDUCFG                                                                   STD_ON
#define CANTP_ISDEF_PDUMETADATALENGTHOFTXSDUCFG                                                     STD_ON
#define CANTP_ISDEF_PDURTXSDUIDOFTXSDUCFG                                                           STD_OFF
#define CANTP_ISDEF_RXFCADDRESSOFTXSDUCFG                                                           STD_ON
#define CANTP_ISDEF_RXFCPDUIDOFTXSDUCFG                                                             STD_OFF
#define CANTP_ISDEF_RXSDUCFGIDXOFTXSDUCFG                                                           STD_OFF
#define CANTP_ISDEF_RXSDUCFGUSEDOFTXSDUCFG                                                          STD_ON
#define CANTP_ISDEF_SDUMETADATALENGTHOFTXSDUCFG                                                     STD_ON
#define CANTP_ISDEF_TRANSMITCANCELLATIONOFTXSDUCFG                                                  STD_ON
#define CANTP_ISDEF_TXADDRESSOFTXSDUCFG                                                             STD_ON
#define CANTP_ISDEF_TXADDRESSINGFORMATOFTXSDUCFG                                                    STD_ON
#define CANTP_ISDEF_TXMAXPAYLOADLENGTHOFTXSDUCFG                                                    STD_ON
#define CANTP_ISDEF_TXPADDINGACTIVATIONOFTXSDUCFG                                                   STD_ON
#define CANTP_ISDEF_TXPDUCONFIRMATIONPDUIDOFTXSDUCFG                                                STD_OFF
#define CANTP_ISDEF_TXTATYPEOFTXSDUCFG                                                              STD_ON
#define CANTP_ISDEF_TXSDUCFGIND                                                                     STD_OFF
#define CANTP_ISDEF_TXSDUCFGIDXOFTXSDUSNV2HDL                                                       STD_OFF
#define CANTP_ISDEF_TXSDUCFGUSEDOFTXSDUSNV2HDL                                                      STD_ON
#define CANTP_ISDEF_CALCBSOFPCCONFIG                                                                STD_ON
#define CANTP_ISDEF_DYNFCPARAMETERSOFPCCONFIG                                                       STD_ON
#define CANTP_ISDEF_RXPDUMAPOFPCCONFIG                                                              STD_ON
#define CANTP_ISDEF_RXSDUCFGINDOFPCCONFIG                                                           STD_ON
#define CANTP_ISDEF_RXSDUCFGOFPCCONFIG                                                              STD_OFF
#define CANTP_ISDEF_RXSDUSNV2HDLOFPCCONFIG                                                          STD_ON
#define CANTP_ISDEF_RXSTATEOFPCCONFIG                                                               STD_ON
#define CANTP_ISDEF_TXSDUCFGINDOFPCCONFIG                                                           STD_ON
#define CANTP_ISDEF_TXSDUCFGOFPCCONFIG                                                              STD_OFF
#define CANTP_ISDEF_TXSDUSNV2HDLOFPCCONFIG                                                          STD_ON
#define CANTP_ISDEF_TXSEMAPHORESOFPCCONFIG                                                          STD_ON
#define CANTP_ISDEF_TXSTATEOFPCCONFIG                                                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCEqualsAlwaysToDefines  CanTp Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANTP_EQ2_ADDRESSINGFORMATOFRXPDUMAP                                                        CANTP_NORMAL_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP
#define CANTP_EQ2_GENERICCONNECTIONOFRXPDUMAP                                                       FALSE
#define CANTP_EQ2_PDUMETADATALENGTHOFRXPDUMAP                                                       0u
#define CANTP_EQ2_RXSDUCFGINDENDIDXOFRXPDUMAP                                                       
#define CANTP_EQ2_RXSDUCFGINDSTARTIDXOFRXPDUMAP                                                     
#define CANTP_EQ2_RXSDUCFGINDUSEDOFRXPDUMAP                                                         TRUE
#define CANTP_EQ2_TXSDUCFGINDENDIDXOFRXPDUMAP                                                       
#define CANTP_EQ2_TXSDUCFGINDSTARTIDXOFRXPDUMAP                                                     
#define CANTP_EQ2_TXSDUCFGINDUSEDOFRXPDUMAP                                                         
#define CANTP_EQ2_BLOCKSIZEOFRXSDUCFG                                                               
#define CANTP_EQ2_CANTYPEOFRXSDUCFG                                                                 CANTP_CAN20_CANTYPEOFRXSDUCFG
#define CANTP_EQ2_CHANNELMODEOFRXSDUCFG                                                             
#define CANTP_EQ2_GENERICCONNECTIONOFRXSDUCFG                                                       FALSE
#define CANTP_EQ2_LOLAYERTXFCPDUIDOFRXSDUCFG                                                        
#define CANTP_EQ2_NAROFRXSDUCFG                                                                     
#define CANTP_EQ2_NBROFRXSDUCFG                                                                     
#define CANTP_EQ2_NCROFRXSDUCFG                                                                     
#define CANTP_EQ2_PDUMETADATALENGTHOFRXSDUCFG                                                       0u
#define CANTP_EQ2_PDURRXSDUIDOFRXSDUCFG                                                             
#define CANTP_EQ2_RXADDRESSOFRXSDUCFG                                                               255u
#define CANTP_EQ2_RXADDRESSINGFORMATOFRXSDUCFG                                                      CANTP_NORMAL_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG
#define CANTP_EQ2_RXMAXPAYLOADLENGTHOFRXSDUCFG                                                      7u
#define CANTP_EQ2_RXPADDINGACTIVATIONOFRXSDUCFG                                                     TRUE
#define CANTP_EQ2_RXPDUIDOFRXSDUCFG                                                                 
#define CANTP_EQ2_RXTATYPEOFRXSDUCFG                                                                
#define CANTP_EQ2_RXWFTMAXOFRXSDUCFG                                                                
#define CANTP_EQ2_STMINOFRXSDUCFG                                                                   0u
#define CANTP_EQ2_SDUMETADATALENGTHOFRXSDUCFG                                                       0u
#define CANTP_EQ2_TXFCADDRESSOFRXSDUCFG                                                             255u
#define CANTP_EQ2_TXFCPDUCONFIRMATIONPDUIDOFRXSDUCFG                                                
#define CANTP_EQ2_TXSDUCFGIDXOFRXSDUCFG                                                             
#define CANTP_EQ2_TXSDUCFGUSEDOFRXSDUCFG                                                            
#define CANTP_EQ2_RXSDUCFGIND                                                                       
#define CANTP_EQ2_RXSDUCFGIDXOFRXSDUSNV2HDL                                                         
#define CANTP_EQ2_RXSDUCFGUSEDOFRXSDUSNV2HDL                                                        TRUE
#define CANTP_EQ2_CANTYPEOFTXSDUCFG                                                                 CANTP_CAN20_CANTYPEOFTXSDUCFG
#define CANTP_EQ2_CHANNELMODEOFTXSDUCFG                                                             CANTP_FULL_DUPLEX_CHANNELMODEOFTXSDUCFG
#define CANTP_EQ2_LOLAYERTXPDUIDOFTXSDUCFG                                                          
#define CANTP_EQ2_NASOFTXSDUCFG                                                                     21u
#define CANTP_EQ2_NBSOFTXSDUCFG                                                                     101u
#define CANTP_EQ2_NCSOFTXSDUCFG                                                                     301u
#define CANTP_EQ2_PDUMETADATALENGTHOFTXSDUCFG                                                       0u
#define CANTP_EQ2_PDURTXSDUIDOFTXSDUCFG                                                             
#define CANTP_EQ2_RXFCADDRESSOFTXSDUCFG                                                             255u
#define CANTP_EQ2_RXFCPDUIDOFTXSDUCFG                                                               
#define CANTP_EQ2_RXSDUCFGIDXOFTXSDUCFG                                                             
#define CANTP_EQ2_RXSDUCFGUSEDOFTXSDUCFG                                                            TRUE
#define CANTP_EQ2_SDUMETADATALENGTHOFTXSDUCFG                                                       0u
#define CANTP_EQ2_TRANSMITCANCELLATIONOFTXSDUCFG                                                    FALSE
#define CANTP_EQ2_TXADDRESSOFTXSDUCFG                                                               255u
#define CANTP_EQ2_TXADDRESSINGFORMATOFTXSDUCFG                                                      CANTP_NORMAL_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG
#define CANTP_EQ2_TXMAXPAYLOADLENGTHOFTXSDUCFG                                                      7u
#define CANTP_EQ2_TXPADDINGACTIVATIONOFTXSDUCFG                                                     TRUE
#define CANTP_EQ2_TXPDUCONFIRMATIONPDUIDOFTXSDUCFG                                                  
#define CANTP_EQ2_TXTATYPEOFTXSDUCFG                                                                CANTP_PHYSICAL_TXTATYPEOFTXSDUCFG
#define CANTP_EQ2_TXSDUCFGIND                                                                       
#define CANTP_EQ2_TXSDUCFGIDXOFTXSDUSNV2HDL                                                         
#define CANTP_EQ2_TXSDUCFGUSEDOFTXSDUSNV2HDL                                                        TRUE
#define CANTP_EQ2_CALCBSOFPCCONFIG                                                                  CanTp_CalcBS
#define CANTP_EQ2_DYNFCPARAMETERSOFPCCONFIG                                                         CanTp_DynFCParameters
#define CANTP_EQ2_RXPDUMAPOFPCCONFIG                                                                CanTp_RxPduMap
#define CANTP_EQ2_RXSDUCFGINDOFPCCONFIG                                                             CanTp_RxSduCfgInd
#define CANTP_EQ2_RXSDUCFGOFPCCONFIG                                                                
#define CANTP_EQ2_RXSDUSNV2HDLOFPCCONFIG                                                            CanTp_RxSduSnv2Hdl
#define CANTP_EQ2_RXSTATEOFPCCONFIG                                                                 CanTp_RxState
#define CANTP_EQ2_TXSDUCFGINDOFPCCONFIG                                                             CanTp_TxSduCfgInd
#define CANTP_EQ2_TXSDUCFGOFPCCONFIG                                                                
#define CANTP_EQ2_TXSDUSNV2HDLOFPCCONFIG                                                            CanTp_TxSduSnv2Hdl
#define CANTP_EQ2_TXSEMAPHORESOFPCCONFIG                                                            CanTp_TxSemaphores
#define CANTP_EQ2_TXSTATEOFPCCONFIG                                                                 CanTp_TxState
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCSymbolicInitializationPointers  CanTp Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanTp_Config_RBTM_FL_Ptr                                                                    &(CanTp_PCConfig.Config_RBTM_FL)  /**< symbolic identifier which shall be used to initialize 'CanTp' */
#define CanTp_Config_RBTM_FR_Ptr                                                                    &(CanTp_PCConfig.Config_RBTM_FR)  /**< symbolic identifier which shall be used to initialize 'CanTp' */
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCInitializationSymbols  CanTp Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanTp_Config_RBTM_FL                                                                        CanTp_PCConfig.Config_RBTM_FL  /**< symbolic identifier which could be used to initialize 'CanTp */
#define CanTp_Config_RBTM_FR                                                                        CanTp_PCConfig.Config_RBTM_FR  /**< symbolic identifier which could be used to initialize 'CanTp */
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCGeneral  CanTp General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANTP_CHECK_INIT_POINTER                                                                    STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANTP_FINAL_MAGIC_NUMBER                                                                    0x231Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanTp */
#define CANTP_INDIVIDUAL_POSTBUILD                                                                  STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanTp' is not configured to be postbuild capable. */
#define CANTP_INIT_DATA                                                                             CANTP_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANTP_INIT_DATA_HASH_CODE                                                                   1051930821  /**< the precompile constant to validate the initialization structure at initialization time of CanTp with a hashcode. The seed value is '0x231Eu' */
#define CANTP_USE_ECUM_BSW_ERROR_HOOK                                                               STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANTP_USE_INIT_POINTER                                                                      STD_ON  /**< STD_ON if the init pointer CanTp shall be used. */
/** 
  \}
*/ 


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
  \defgroup  CanTpPCGetRootDataMacros  CanTp Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define CanTp_GetRxSduCfgOfPCConfig()                                                               CanTp_ConfigDataPtr->RxSduCfgOfPCConfig
#define CanTp_GetTxSduCfgOfPCConfig()                                                               CanTp_ConfigDataPtr->TxSduCfgOfPCConfig
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCGetConstantDuplicatedRootDataMacros  CanTp Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanTp_GetCalcBSOfPCConfig()                                                                 CanTp_CalcBS  /**< the pointer to CanTp_CalcBS */
#define CanTp_GetCompatibilityVersionOfPCConfig()                                                   550968u
#define CanTp_GetDynFCParametersOfPCConfig()                                                        CanTp_DynFCParameters  /**< the pointer to CanTp_DynFCParameters */
#define CanTp_GetRxPduMapOfPCConfig()                                                               CanTp_RxPduMap  /**< the pointer to CanTp_RxPduMap */
#define CanTp_GetRxSduCfgIndOfPCConfig()                                                            CanTp_RxSduCfgInd  /**< the pointer to CanTp_RxSduCfgInd */
#define CanTp_GetRxSduSnv2HdlOfPCConfig()                                                           CanTp_RxSduSnv2Hdl  /**< the pointer to CanTp_RxSduSnv2Hdl */
#define CanTp_GetRxStateOfPCConfig()                                                                CanTp_RxState  /**< the pointer to CanTp_RxState */
#define CanTp_GetSizeOfCalcBSOfPCConfig()                                                           6u  /**< the number of accomplishable value elements in CanTp_CalcBS */
#define CanTp_GetSizeOfDynFCParametersOfPCConfig()                                                  6u  /**< the number of accomplishable value elements in CanTp_DynFCParameters */
#define CanTp_GetSizeOfRxPduMapOfPCConfig()                                                         6u  /**< the number of accomplishable value elements in CanTp_RxPduMap */
#define CanTp_GetSizeOfRxSduCfgIndOfPCConfig()                                                      6u  /**< the number of accomplishable value elements in CanTp_RxSduCfgInd */
#define CanTp_GetSizeOfRxSduCfgOfPCConfig()                                                         6u  /**< the number of accomplishable value elements in CanTp_RxSduCfg */
#define CanTp_GetSizeOfRxSduSnv2HdlOfPCConfig()                                                     6u  /**< the number of accomplishable value elements in CanTp_RxSduSnv2Hdl */
#define CanTp_GetSizeOfRxStateOfPCConfig()                                                          6u  /**< the number of accomplishable value elements in CanTp_RxState */
#define CanTp_GetSizeOfTxSduCfgIndOfPCConfig()                                                      3u  /**< the number of accomplishable value elements in CanTp_TxSduCfgInd */
#define CanTp_GetSizeOfTxSduCfgOfPCConfig()                                                         3u  /**< the number of accomplishable value elements in CanTp_TxSduCfg */
#define CanTp_GetSizeOfTxSduSnv2HdlOfPCConfig()                                                     3u  /**< the number of accomplishable value elements in CanTp_TxSduSnv2Hdl */
#define CanTp_GetSizeOfTxSemaphoresOfPCConfig()                                                     3u  /**< the number of accomplishable value elements in CanTp_TxSemaphores */
#define CanTp_GetSizeOfTxStateOfPCConfig()                                                          3u  /**< the number of accomplishable value elements in CanTp_TxState */
#define CanTp_GetTxSduCfgIndOfPCConfig()                                                            CanTp_TxSduCfgInd  /**< the pointer to CanTp_TxSduCfgInd */
#define CanTp_GetTxSduSnv2HdlOfPCConfig()                                                           CanTp_TxSduSnv2Hdl  /**< the pointer to CanTp_TxSduSnv2Hdl */
#define CanTp_GetTxSemaphoresOfPCConfig()                                                           CanTp_TxSemaphores  /**< the pointer to CanTp_TxSemaphores */
#define CanTp_GetTxStateOfPCConfig()                                                                CanTp_TxState  /**< the pointer to CanTp_TxState */
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCGetDataMacros  CanTp Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanTp_GetCalcBS(Index)                                                                      (CanTp_GetCalcBSOfPCConfig()[(Index)])
#define CanTp_GetDynFCParameters(Index)                                                             (CanTp_GetDynFCParametersOfPCConfig()[(Index)])
#define CanTp_GetRxSduCfgIndEndIdxOfRxPduMap(Index)                                                 (CanTp_GetRxPduMapOfPCConfig()[(Index)].RxSduCfgIndEndIdxOfRxPduMap)
#define CanTp_GetRxSduCfgIndStartIdxOfRxPduMap(Index)                                               (CanTp_GetRxPduMapOfPCConfig()[(Index)].RxSduCfgIndStartIdxOfRxPduMap)
#define CanTp_GetTxSduCfgIndEndIdxOfRxPduMap(Index)                                                 (CanTp_GetRxPduMapOfPCConfig()[(Index)].TxSduCfgIndEndIdxOfRxPduMap)
#define CanTp_GetTxSduCfgIndStartIdxOfRxPduMap(Index)                                               (CanTp_GetRxPduMapOfPCConfig()[(Index)].TxSduCfgIndStartIdxOfRxPduMap)
#define CanTp_GetBlockSizeOfRxSduCfg(Index)                                                         (CanTp_GetRxSduCfgOfPCConfig()[(Index)].BlockSizeOfRxSduCfg)
#define CanTp_GetChannelModeOfRxSduCfg(Index)                                                       (CanTp_GetRxSduCfgOfPCConfig()[(Index)].ChannelModeOfRxSduCfg)
#define CanTp_GetLoLayerTxFcPduIdOfRxSduCfg(Index)                                                  (CanTp_GetRxSduCfgOfPCConfig()[(Index)].LoLayerTxFcPduIdOfRxSduCfg)
#define CanTp_GetNArOfRxSduCfg(Index)                                                               (CanTp_GetRxSduCfgOfPCConfig()[(Index)].NArOfRxSduCfg)
#define CanTp_GetNBrOfRxSduCfg(Index)                                                               (CanTp_GetRxSduCfgOfPCConfig()[(Index)].NBrOfRxSduCfg)
#define CanTp_GetNCrOfRxSduCfg(Index)                                                               (CanTp_GetRxSduCfgOfPCConfig()[(Index)].NCrOfRxSduCfg)
#define CanTp_GetPduRRxSduIdOfRxSduCfg(Index)                                                       (CanTp_GetRxSduCfgOfPCConfig()[(Index)].PduRRxSduIdOfRxSduCfg)
#define CanTp_GetRxPduIdOfRxSduCfg(Index)                                                           (CanTp_GetRxSduCfgOfPCConfig()[(Index)].RxPduIdOfRxSduCfg)
#define CanTp_GetRxTaTypeOfRxSduCfg(Index)                                                          (CanTp_GetRxSduCfgOfPCConfig()[(Index)].RxTaTypeOfRxSduCfg)
#define CanTp_GetRxWftMaxOfRxSduCfg(Index)                                                          (CanTp_GetRxSduCfgOfPCConfig()[(Index)].RxWftMaxOfRxSduCfg)
#define CanTp_GetTxFcPduConfirmationPduIdOfRxSduCfg(Index)                                          (CanTp_GetRxSduCfgOfPCConfig()[(Index)].TxFcPduConfirmationPduIdOfRxSduCfg)
#define CanTp_GetTxSduCfgIdxOfRxSduCfg(Index)                                                       (CanTp_GetRxSduCfgOfPCConfig()[(Index)].TxSduCfgIdxOfRxSduCfg)
#define CanTp_GetRxSduCfgInd(Index)                                                                 (CanTp_GetRxSduCfgIndOfPCConfig()[(Index)])
#define CanTp_GetRxSduCfgIdxOfRxSduSnv2Hdl(Index)                                                   (CanTp_GetRxSduSnv2HdlOfPCConfig()[(Index)].RxSduCfgIdxOfRxSduSnv2Hdl)
#define CanTp_GetRxState(Index)                                                                     (CanTp_GetRxStateOfPCConfig()[(Index)])
#define CanTp_GetLoLayerTxPduIdOfTxSduCfg(Index)                                                    (CanTp_GetTxSduCfgOfPCConfig()[(Index)].LoLayerTxPduIdOfTxSduCfg)
#define CanTp_GetPduRTxSduIdOfTxSduCfg(Index)                                                       (CanTp_GetTxSduCfgOfPCConfig()[(Index)].PduRTxSduIdOfTxSduCfg)
#define CanTp_GetRxFcPduIdOfTxSduCfg(Index)                                                         (CanTp_GetTxSduCfgOfPCConfig()[(Index)].RxFcPduIdOfTxSduCfg)
#define CanTp_GetRxSduCfgIdxOfTxSduCfg(Index)                                                       (CanTp_GetTxSduCfgOfPCConfig()[(Index)].RxSduCfgIdxOfTxSduCfg)
#define CanTp_GetTxPduConfirmationPduIdOfTxSduCfg(Index)                                            (CanTp_GetTxSduCfgOfPCConfig()[(Index)].TxPduConfirmationPduIdOfTxSduCfg)
#define CanTp_GetTxSduCfgInd(Index)                                                                 (CanTp_GetTxSduCfgIndOfPCConfig()[(Index)])
#define CanTp_GetTxSduCfgIdxOfTxSduSnv2Hdl(Index)                                                   (CanTp_GetTxSduSnv2HdlOfPCConfig()[(Index)].TxSduCfgIdxOfTxSduSnv2Hdl)
#define CanTp_GetTxSemaphores(Index)                                                                (CanTp_GetTxSemaphoresOfPCConfig()[(Index)])
#define CanTp_GetTxState(Index)                                                                     (CanTp_GetTxStateOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCGetDeduplicatedDataMacros  CanTp Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanTp_GetCompatibilityVersion()                                                             CanTp_GetCompatibilityVersionOfPCConfig()
#define CanTp_GetAddressingFormatOfRxPduMap(Index)                                                  CANTP_NORMAL_ADDRESSING_ADDRESSINGFORMATOFRXPDUMAP
#define CanTp_IsGenericConnectionOfRxPduMap(Index)                                                  (((FALSE)) != FALSE)
#define CanTp_GetPduMetadataLengthOfRxPduMap(Index)                                                 0u
#define CanTp_IsRxSduCfgIndUsedOfRxPduMap(Index)                                                    (((TRUE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanTp_RxSduCfgInd */
#define CanTp_IsTxSduCfgIndUsedOfRxPduMap(Index)                                                    (((boolean)(CanTp_GetTxSduCfgIndStartIdxOfRxPduMap(Index) != CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to CanTp_TxSduCfgInd */
#define CanTp_GetCanTypeOfRxSduCfg(Index)                                                           CANTP_CAN20_CANTYPEOFRXSDUCFG
#define CanTp_IsGenericConnectionOfRxSduCfg(Index)                                                  (((FALSE)) != FALSE)
#define CanTp_GetPduMetadataLengthOfRxSduCfg(Index)                                                 0u
#define CanTp_GetRxAddressOfRxSduCfg(Index)                                                         255u
#define CanTp_GetRxAddressingFormatOfRxSduCfg(Index)                                                CANTP_NORMAL_ADDRESSING_RXADDRESSINGFORMATOFRXSDUCFG
#define CanTp_GetRxMaxPayloadLengthOfRxSduCfg(Index)                                                7u
#define CanTp_IsRxPaddingActivationOfRxSduCfg(Index)                                                (((TRUE)) != FALSE)
#define CanTp_GetSTminOfRxSduCfg(Index)                                                             0u
#define CanTp_GetSduMetadataLengthOfRxSduCfg(Index)                                                 0u
#define CanTp_GetTxFcAddressOfRxSduCfg(Index)                                                       255u
#define CanTp_IsTxSduCfgUsedOfRxSduCfg(Index)                                                       (((boolean)(CanTp_GetTxSduCfgIdxOfRxSduCfg(Index) != CANTP_NO_TXSDUCFGIDXOFRXSDUCFG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanTp_TxSduCfg */
#define CanTp_IsRxSduCfgUsedOfRxSduSnv2Hdl(Index)                                                   (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanTp_RxSduCfg */
#define CanTp_GetSizeOfCalcBS()                                                                     CanTp_GetSizeOfCalcBSOfPCConfig()
#define CanTp_GetSizeOfDynFCParameters()                                                            CanTp_GetSizeOfDynFCParametersOfPCConfig()
#define CanTp_GetSizeOfRxPduMap()                                                                   CanTp_GetSizeOfRxPduMapOfPCConfig()
#define CanTp_GetSizeOfRxSduCfg()                                                                   CanTp_GetSizeOfRxSduCfgOfPCConfig()
#define CanTp_GetSizeOfRxSduCfgInd()                                                                CanTp_GetSizeOfRxSduCfgIndOfPCConfig()
#define CanTp_GetSizeOfRxSduSnv2Hdl()                                                               CanTp_GetSizeOfRxSduSnv2HdlOfPCConfig()
#define CanTp_GetSizeOfRxState()                                                                    CanTp_GetSizeOfRxStateOfPCConfig()
#define CanTp_GetSizeOfTxSduCfg()                                                                   CanTp_GetSizeOfTxSduCfgOfPCConfig()
#define CanTp_GetSizeOfTxSduCfgInd()                                                                CanTp_GetSizeOfTxSduCfgIndOfPCConfig()
#define CanTp_GetSizeOfTxSduSnv2Hdl()                                                               CanTp_GetSizeOfTxSduSnv2HdlOfPCConfig()
#define CanTp_GetSizeOfTxSemaphores()                                                               CanTp_GetSizeOfTxSemaphoresOfPCConfig()
#define CanTp_GetSizeOfTxState()                                                                    CanTp_GetSizeOfTxStateOfPCConfig()
#define CanTp_GetCanTypeOfTxSduCfg(Index)                                                           CANTP_CAN20_CANTYPEOFTXSDUCFG
#define CanTp_GetChannelModeOfTxSduCfg(Index)                                                       CANTP_FULL_DUPLEX_CHANNELMODEOFTXSDUCFG
#define CanTp_GetNAsOfTxSduCfg(Index)                                                               21u
#define CanTp_GetNBsOfTxSduCfg(Index)                                                               101u
#define CanTp_GetNCsOfTxSduCfg(Index)                                                               301u
#define CanTp_GetPduMetadataLengthOfTxSduCfg(Index)                                                 0u
#define CanTp_GetRxFcAddressOfTxSduCfg(Index)                                                       255u
#define CanTp_IsRxSduCfgUsedOfTxSduCfg(Index)                                                       (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanTp_RxSduCfg */
#define CanTp_GetSduMetadataLengthOfTxSduCfg(Index)                                                 0u
#define CanTp_IsTransmitCancellationOfTxSduCfg(Index)                                               (((FALSE)) != FALSE)
#define CanTp_GetTxAddressOfTxSduCfg(Index)                                                         255u
#define CanTp_GetTxAddressingFormatOfTxSduCfg(Index)                                                CANTP_NORMAL_ADDRESSING_TXADDRESSINGFORMATOFTXSDUCFG
#define CanTp_GetTxMaxPayloadLengthOfTxSduCfg(Index)                                                7u
#define CanTp_IsTxPaddingActivationOfTxSduCfg(Index)                                                (((TRUE)) != FALSE)
#define CanTp_GetTxTaTypeOfTxSduCfg(Index)                                                          CANTP_PHYSICAL_TXTATYPEOFTXSDUCFG
#define CanTp_IsTxSduCfgUsedOfTxSduSnv2Hdl(Index)                                                   (((TRUE)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanTp_TxSduCfg */
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCSetDataMacros  CanTp Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanTp_SetCalcBS(Index, Value)                                                               CanTp_GetCalcBSOfPCConfig()[(Index)] = (Value)
#define CanTp_SetDynFCParameters(Index, Value)                                                      CanTp_GetDynFCParametersOfPCConfig()[(Index)] = (Value)
#define CanTp_SetRxState(Index, Value)                                                              CanTp_GetRxStateOfPCConfig()[(Index)] = (Value)
#define CanTp_SetTxSemaphores(Index, Value)                                                         CanTp_GetTxSemaphoresOfPCConfig()[(Index)] = (Value)
#define CanTp_SetTxState(Index, Value)                                                              CanTp_GetTxStateOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCHasMacros  CanTp Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanTp_HasCalcBS()                                                                           (TRUE != FALSE)
#define CanTp_HasCompatibilityVersion()                                                             (TRUE != FALSE)
#define CanTp_HasDynFCParameters()                                                                  (TRUE != FALSE)
#define CanTp_HasRxPduMap()                                                                         (TRUE != FALSE)
#define CanTp_HasAddressingFormatOfRxPduMap()                                                       (TRUE != FALSE)
#define CanTp_HasGenericConnectionOfRxPduMap()                                                      (TRUE != FALSE)
#define CanTp_HasPduMetadataLengthOfRxPduMap()                                                      (TRUE != FALSE)
#define CanTp_HasRxSduCfgIndEndIdxOfRxPduMap()                                                      (TRUE != FALSE)
#define CanTp_HasRxSduCfgIndStartIdxOfRxPduMap()                                                    (TRUE != FALSE)
#define CanTp_HasRxSduCfgIndUsedOfRxPduMap()                                                        (TRUE != FALSE)
#define CanTp_HasTxSduCfgIndEndIdxOfRxPduMap()                                                      (TRUE != FALSE)
#define CanTp_HasTxSduCfgIndStartIdxOfRxPduMap()                                                    (TRUE != FALSE)
#define CanTp_HasTxSduCfgIndUsedOfRxPduMap()                                                        (TRUE != FALSE)
#define CanTp_HasRxSduCfg()                                                                         (CanTp_GetRxSduCfgOfPCConfig() != NULL_PTR)
#define CanTp_HasBlockSizeOfRxSduCfg()                                                              (TRUE != FALSE)
#define CanTp_HasCanTypeOfRxSduCfg()                                                                (TRUE != FALSE)
#define CanTp_HasChannelModeOfRxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasGenericConnectionOfRxSduCfg()                                                      (TRUE != FALSE)
#define CanTp_HasLoLayerTxFcPduIdOfRxSduCfg()                                                       (TRUE != FALSE)
#define CanTp_HasNArOfRxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasNBrOfRxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasNCrOfRxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasPduMetadataLengthOfRxSduCfg()                                                      (TRUE != FALSE)
#define CanTp_HasPduRRxSduIdOfRxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasRxAddressOfRxSduCfg()                                                              (TRUE != FALSE)
#define CanTp_HasRxAddressingFormatOfRxSduCfg()                                                     (TRUE != FALSE)
#define CanTp_HasRxMaxPayloadLengthOfRxSduCfg()                                                     (TRUE != FALSE)
#define CanTp_HasRxPaddingActivationOfRxSduCfg()                                                    (TRUE != FALSE)
#define CanTp_HasRxPduIdOfRxSduCfg()                                                                (TRUE != FALSE)
#define CanTp_HasRxTaTypeOfRxSduCfg()                                                               (TRUE != FALSE)
#define CanTp_HasRxWftMaxOfRxSduCfg()                                                               (TRUE != FALSE)
#define CanTp_HasSTminOfRxSduCfg()                                                                  (TRUE != FALSE)
#define CanTp_HasSduMetadataLengthOfRxSduCfg()                                                      (TRUE != FALSE)
#define CanTp_HasTxFcAddressOfRxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasTxFcPduConfirmationPduIdOfRxSduCfg()                                               (TRUE != FALSE)
#define CanTp_HasTxSduCfgIdxOfRxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasTxSduCfgUsedOfRxSduCfg()                                                           (TRUE != FALSE)
#define CanTp_HasRxSduCfgInd()                                                                      (TRUE != FALSE)
#define CanTp_HasRxSduSnv2Hdl()                                                                     (TRUE != FALSE)
#define CanTp_HasRxSduCfgIdxOfRxSduSnv2Hdl()                                                        (TRUE != FALSE)
#define CanTp_HasRxSduCfgUsedOfRxSduSnv2Hdl()                                                       (TRUE != FALSE)
#define CanTp_HasRxState()                                                                          (TRUE != FALSE)
#define CanTp_HasSizeOfCalcBS()                                                                     (TRUE != FALSE)
#define CanTp_HasSizeOfDynFCParameters()                                                            (TRUE != FALSE)
#define CanTp_HasSizeOfRxPduMap()                                                                   (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduCfg()                                                                   (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduCfgInd()                                                                (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduSnv2Hdl()                                                               (TRUE != FALSE)
#define CanTp_HasSizeOfRxState()                                                                    (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduCfg()                                                                   (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduCfgInd()                                                                (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduSnv2Hdl()                                                               (TRUE != FALSE)
#define CanTp_HasSizeOfTxSemaphores()                                                               (TRUE != FALSE)
#define CanTp_HasSizeOfTxState()                                                                    (TRUE != FALSE)
#define CanTp_HasTxSduCfg()                                                                         (CanTp_GetTxSduCfgOfPCConfig() != NULL_PTR)
#define CanTp_HasCanTypeOfTxSduCfg()                                                                (TRUE != FALSE)
#define CanTp_HasChannelModeOfTxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasLoLayerTxPduIdOfTxSduCfg()                                                         (TRUE != FALSE)
#define CanTp_HasNAsOfTxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasNBsOfTxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasNCsOfTxSduCfg()                                                                    (TRUE != FALSE)
#define CanTp_HasPduMetadataLengthOfTxSduCfg()                                                      (TRUE != FALSE)
#define CanTp_HasPduRTxSduIdOfTxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasRxFcAddressOfTxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasRxFcPduIdOfTxSduCfg()                                                              (TRUE != FALSE)
#define CanTp_HasRxSduCfgIdxOfTxSduCfg()                                                            (TRUE != FALSE)
#define CanTp_HasRxSduCfgUsedOfTxSduCfg()                                                           (TRUE != FALSE)
#define CanTp_HasSduMetadataLengthOfTxSduCfg()                                                      (TRUE != FALSE)
#define CanTp_HasTransmitCancellationOfTxSduCfg()                                                   (TRUE != FALSE)
#define CanTp_HasTxAddressOfTxSduCfg()                                                              (TRUE != FALSE)
#define CanTp_HasTxAddressingFormatOfTxSduCfg()                                                     (TRUE != FALSE)
#define CanTp_HasTxMaxPayloadLengthOfTxSduCfg()                                                     (TRUE != FALSE)
#define CanTp_HasTxPaddingActivationOfTxSduCfg()                                                    (TRUE != FALSE)
#define CanTp_HasTxPduConfirmationPduIdOfTxSduCfg()                                                 (TRUE != FALSE)
#define CanTp_HasTxTaTypeOfTxSduCfg()                                                               (TRUE != FALSE)
#define CanTp_HasTxSduCfgInd()                                                                      (TRUE != FALSE)
#define CanTp_HasTxSduSnv2Hdl()                                                                     (TRUE != FALSE)
#define CanTp_HasTxSduCfgIdxOfTxSduSnv2Hdl()                                                        (TRUE != FALSE)
#define CanTp_HasTxSduCfgUsedOfTxSduSnv2Hdl()                                                       (TRUE != FALSE)
#define CanTp_HasTxSemaphores()                                                                     (TRUE != FALSE)
#define CanTp_HasTxState()                                                                          (TRUE != FALSE)
#define CanTp_HasPCConfig()                                                                         (TRUE != FALSE)
#define CanTp_HasCalcBSOfPCConfig()                                                                 (TRUE != FALSE)
#define CanTp_HasCompatibilityVersionOfPCConfig()                                                   (TRUE != FALSE)
#define CanTp_HasDynFCParametersOfPCConfig()                                                        (TRUE != FALSE)
#define CanTp_HasRxPduMapOfPCConfig()                                                               (TRUE != FALSE)
#define CanTp_HasRxSduCfgIndOfPCConfig()                                                            (TRUE != FALSE)
#define CanTp_HasRxSduCfgOfPCConfig()                                                               (TRUE != FALSE)
#define CanTp_HasRxSduSnv2HdlOfPCConfig()                                                           (TRUE != FALSE)
#define CanTp_HasRxStateOfPCConfig()                                                                (TRUE != FALSE)
#define CanTp_HasSizeOfCalcBSOfPCConfig()                                                           (TRUE != FALSE)
#define CanTp_HasSizeOfDynFCParametersOfPCConfig()                                                  (TRUE != FALSE)
#define CanTp_HasSizeOfRxPduMapOfPCConfig()                                                         (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduCfgIndOfPCConfig()                                                      (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduCfgOfPCConfig()                                                         (TRUE != FALSE)
#define CanTp_HasSizeOfRxSduSnv2HdlOfPCConfig()                                                     (TRUE != FALSE)
#define CanTp_HasSizeOfRxStateOfPCConfig()                                                          (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduCfgIndOfPCConfig()                                                      (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduCfgOfPCConfig()                                                         (TRUE != FALSE)
#define CanTp_HasSizeOfTxSduSnv2HdlOfPCConfig()                                                     (TRUE != FALSE)
#define CanTp_HasSizeOfTxSemaphoresOfPCConfig()                                                     (TRUE != FALSE)
#define CanTp_HasSizeOfTxStateOfPCConfig()                                                          (TRUE != FALSE)
#define CanTp_HasTxSduCfgIndOfPCConfig()                                                            (TRUE != FALSE)
#define CanTp_HasTxSduCfgOfPCConfig()                                                               (TRUE != FALSE)
#define CanTp_HasTxSduSnv2HdlOfPCConfig()                                                           (TRUE != FALSE)
#define CanTp_HasTxSemaphoresOfPCConfig()                                                           (TRUE != FALSE)
#define CanTp_HasTxStateOfPCConfig()                                                                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCIncrementDataMacros  CanTp Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanTp_IncCalcBS(Index)                                                                      CanTp_GetCalcBS(Index)++
#define CanTp_IncDynFCParameters(Index)                                                             CanTp_GetDynFCParameters(Index)++
#define CanTp_IncRxState(Index)                                                                     CanTp_GetRxState(Index)++
#define CanTp_IncTxSemaphores(Index)                                                                CanTp_GetTxSemaphores(Index)++
#define CanTp_IncTxState(Index)                                                                     CanTp_GetTxState(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCDecrementDataMacros  CanTp Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanTp_DecCalcBS(Index)                                                                      CanTp_GetCalcBS(Index)--
#define CanTp_DecDynFCParameters(Index)                                                             CanTp_GetDynFCParameters(Index)--
#define CanTp_DecRxState(Index)                                                                     CanTp_GetRxState(Index)--
#define CanTp_DecTxSemaphores(Index)                                                                CanTp_GetTxSemaphores(Index)--
#define CanTp_DecTxState(Index)                                                                     CanTp_GetTxState(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCAddDataMacros  CanTp Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define CanTp_AddCalcBS(Index, Value)                                                               CanTp_SetCalcBS(Index, (CanTp_GetCalcBS(Index) + Value))
#define CanTp_AddDynFCParameters(Index, Value)                                                      CanTp_SetDynFCParameters(Index, (CanTp_GetDynFCParameters(Index) + Value))
#define CanTp_AddRxState(Index, Value)                                                              CanTp_SetRxState(Index, (CanTp_GetRxState(Index) + Value))
#define CanTp_AddTxSemaphores(Index, Value)                                                         CanTp_SetTxSemaphores(Index, (CanTp_GetTxSemaphores(Index) + Value))
#define CanTp_AddTxState(Index, Value)                                                              CanTp_SetTxState(Index, (CanTp_GetTxState(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCSubstractDataMacros  CanTp Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define CanTp_SubCalcBS(Index, Value)                                                               CanTp_SetCalcBS(Index, (CanTp_GetCalcBS(Index) - Value))
#define CanTp_SubDynFCParameters(Index, Value)                                                      CanTp_SetDynFCParameters(Index, (CanTp_GetDynFCParameters(Index) - Value))
#define CanTp_SubRxState(Index, Value)                                                              CanTp_SetRxState(Index, (CanTp_GetRxState(Index) - Value))
#define CanTp_SubTxSemaphores(Index, Value)                                                         CanTp_SetTxSemaphores(Index, (CanTp_GetTxSemaphores(Index) - Value))
#define CanTp_SubTxState(Index, Value)                                                              CanTp_SetTxState(Index, (CanTp_GetTxState(Index) - Value))
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

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTpLTDataSwitches  CanTp Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANTP_LTCONFIG                                                                              STD_OFF  /**< Deactivateable: 'CanTp_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanTpPBDataSwitches  CanTp Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANTP_PBCONFIG                                                                              STD_OFF  /**< Deactivateable: 'CanTp_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANTP_LTCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CanTp_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANTP_PCCONFIGIDXOFPBCONFIG                                                                 STD_OFF  /**< Deactivateable: 'CanTp_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 


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


#endif /* CANTP_CFG_H */
