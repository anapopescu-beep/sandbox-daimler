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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Cfg.h
 *   Generation Time: 2023-07-05 16:23:57
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
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
#define PDUR_DEV_ERROR_REPORT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_EXTENDED_ERROR_CHECKS STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRExtendedErrorChecks] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

#define PDUR_ERROR_NOTIFICATION STD_OFF

#define PDUR_MAIN_FUNCTION STD_OFF

#define PDUR_MULTICORE STD_OFF /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] */

#define PduR_PBConfigIdType uint32

 
 /*  DET Error define list  */ 
#define PDUR_FCT_CANTPRXIND 0x05u 
#define PDUR_FCT_CANTPTX 0x09u 
#define PDUR_FCT_CANTPTXCFM 0x08u 
#define PDUR_FCT_CANTPSOR 0x06u 
#define PDUR_FCT_CANTPCPYRX 0x04u 
#define PDUR_FCT_CANTPCPYTX 0x07u 
#define PDUR_FCT_CANTPCHPARA 0x0Bu 
#define PDUR_FCT_DCMTX 0x99u 
#define PDUR_FCT_DCMCHPARA 0x9Bu 
 /*   PduR_CanTpTpRxIndication  PduR_CanTpTransmit  PduR_CanTpTxConfirmation  PduR_CanTpStartOfReception  PduR_CanTpCopyRxData  PduR_CanTpCopyTxData  PduR_CanTpChangeParameter  PduR_DcmTransmit  PduR_DcmChangeParameter  */ 



/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3fa3fd23                       2u      /**< [RBTM_FL] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7f35c914                       0u      /**< [RBTM_FL] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8d2872fc                       0u      /**< [RBTM_FR] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_249a1158                       1u      /**< [RBTM_FL] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a0766459                       1u      /**< [RBTM_FR] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f76356d0                       2u      /**< [RBTM_FR] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxDest Handle IDs of handle space TpRxDest.
 * \brief Transport protocol Rx destination PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_6d2a29a5_Rx_a44b5ded_Rx 3u /**< [RBTM_FL] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_4810f84e_Rx_80d1f2da_Rx 4u /**< [RBTM_FL] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_1e46a9f5_Rx_03bff274_Rx 5u /**< [RBTM_FL] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_1f04509d_Rx_7beeea72_Rx 3u /**< [RBTM_FR] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_3a3e8176_Rx_4d07a2cf_Rx 4u /**< [RBTM_FR] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_6c68d0cd_Rx_8aa11052_Rx 5u /**< [RBTM_FR] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_1d96a036_Rx_19a79fac_Rx 0u /**< [RBTM_FL, RBTM_FR] */
#define PduRConf_PduRDestPdu_SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_38ac71dd_Rx_0e266b08_Rx 1u /**< [RBTM_FL, RBTM_FR] */
#define PduRConf_PduRDestPdu_SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_6efa2066_Rx_1a629478_Rx 2u /**< [RBTM_FL, RBTM_FR] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpRxSrc Handle IDs of handle space TpRxSrc.
 * \brief Transport protocol Rx source PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4d07a2cf                       4u      /**< [RBTM_FR] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7beeea72                       3u      /**< [RBTM_FR] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8aa11052                       5u      /**< [RBTM_FR] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_03bff274                       5u      /**< [RBTM_FL] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_80d1f2da                       4u      /**< [RBTM_FL] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a44b5ded                       3u      /**< [RBTM_FL] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0e266b08                       1u      /**< [RBTM_FL, RBTM_FR] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1a629478                       2u      /**< [RBTM_FL, RBTM_FR] */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_19a79fac                       0u      /**< [RBTM_FL, RBTM_FR] */
/**\} */

/**
 * \defgroup PduRHandleIdsTpTxDest Handle IDs of handle space TpTxDest.
 * \brief Transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_92b91e83_Tx 0u /**< [RBTM_FL] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_b783cf68_Tx 1u /**< [RBTM_FL] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_e1d59ed3_Tx 2u /**< [RBTM_FL] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_e09767bb_Tx 0u /**< [RBTM_FR] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_c5adb650_Tx 1u /**< [RBTM_FR] */
#define PduRConf_PduRDestPdu_SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_93fbe7eb_Tx 2u /**< [RBTM_FR] */
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

