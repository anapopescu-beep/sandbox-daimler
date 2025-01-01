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
 *            Module: SecOC
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecOC_Cfg.h
 *   Generation Time: 2023-07-10 14:36:03
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (SECOC_CFG_H)
# define SECOC_CFG_H
 
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "SecOC_Types.h"
 
/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef SECOC_USE_DUMMY_STATEMENT
#define SECOC_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SECOC_DUMMY_STATEMENT
#define SECOC_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SECOC_DUMMY_STATEMENT_CONST
#define SECOC_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SECOC_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SECOC_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SECOC_ATOMIC_VARIABLE_ACCESS
#define SECOC_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SECOC_PROCESSOR_TC322L
#define SECOC_PROCESSOR_TC322L
#endif
#ifndef SECOC_COMP_TASKING
#define SECOC_COMP_TASKING
#endif
#ifndef SECOC_GEN_GENERATOR_MSR
#define SECOC_GEN_GENERATOR_MSR
#endif
#ifndef SECOC_CPUTYPE_BITORDER_LSB2MSB
#define SECOC_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SECOC_CONFIGURATION_VARIANT_PRECOMPILE
#define SECOC_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SECOC_CONFIGURATION_VARIANT_LINKTIME
#define SECOC_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SECOC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SECOC_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SECOC_CONFIGURATION_VARIANT
#define SECOC_CONFIGURATION_VARIANT SECOC_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SECOC_POSTBUILD_VARIANT_SUPPORT
#define SECOC_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* SecOC APIs */
#define SECOC_COMMUNICATION_INTERFACE     STD_ON  /**< /ActiveEcuC/PduR/SecOc[0:PduRCommunicationInterface] */
#define SECOC_TRANSPORT_PROTOCOL          STD_OFF  /**< /ActiveEcuC/PduR/SecOc[0:PduRTransportProtocol] */
#define SECOC_VERSION_INFO_API            STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCVersionInfoApi] */

#define SECOC_DEV_ERROR_DETECT            STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCSafeBswChecks] || /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCDevErrorDetect] */
#define SECOC_DEV_ERROR_REPORT            STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCDevErrorDetect] */

#define SECOC_TRIGGER_TRANSMIT_API        STD_OFF  /**< /ActiveEcuC/PduR/SecOc[0:PduRTriggertransmit] */
#define SECOC_TX_CONFIRMATION_API         STD_OFF  /**< /ActiveEcuC/PduR/SecOc[0:PduRTxConfirmation] */

#define SECOC_USE_GET_RX_FRESHNESS_API    STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseGetRxFreshness] */
#define SECOC_USE_GET_RX_FRESHNESS_AUTH_DATA_API  STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseGetRxFreshnessAuthData] */
#define SECOC_USE_GET_TX_FRESHNESS_API    STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseGetTxFreshness] */
#define SECOC_USE_GET_TX_FRESHNESS_TRUNC_DATA_API STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseGetTxFreshnessTruncData] */

#define SECOC_CANCEL_TRANSMIT_API         STD_OFF  /**< /ActiveEcuC/PduR/SecOc[0:PduRCancelTransmit] */

#define SECOC_IGNORE_VERIFICATION_RESULT  STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOcIgnoreVerificationResult] */

#define SECOC_CUSTOM_AUTHENTICATION_API  STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableCustomAuthenticationAPI] */

#define SECOC_PROPAGATE_ONLY_FINAL_VERIFICATION_STATUS STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCPropagateOnlyFinalVerificationStatus] */

#define SECOC_RETRY_FAILED_TRANSMIT_REQUEST STD_ON  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCRetryFailedTransmitRequest]*/

#define SECOC_USE_MSB_ALIGNED_TRUNCATED_FRESHNESS_VALUE_IN_FVM STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCUseMSBAlignedTruncatedFreshnessValueInFvM]*/

#define SECOC_NONE                        0
#define SECOC_CFUNC                       1
#define SECOC_RTE                         2

#define SECOC_ENABLE_FORCED_PASS_OVERRIDESTATUS STD_OFF  /**< /ActiveEcuC/SecOC/SecOCGeneral[0:SecOCEnableForcedPassOverride] */
 
#define SECOC_TRUNC_AUTHENTIC_DATA_SIZE_RXPDUS 3
#define SECOC_TRUNC_AUTHENTIC_DATA_SIZE_TXPDUS 0

#define SECOC_TRUNC_FRESHNESS_SIZE_RXPDUS      8
#define SECOC_TRUNC_FRESHNESS_SIZE_TXPDUS      8

#define SECOC_FRESHNESS_SIZE_RXPDUS      8
#define SECOC_FRESHNESS_SIZE_TXPDUS      8
 
#define SECOC_MESSAGE_LINKER_SIZE_RXPDUS 0

#define SECOC_DEFAULT_AUTHENTICATION_INFORMATION_PATTERN 0
 



/**
 * \defgroup SecOCHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define SecOCConf_SecOCRxSecuredPdu_Bckl_Sw_Fx_Stat_ST3_secured_b672d5e7_Rx 0u /**< [PostBuildInvariantValuesModelView] */
#define SecOCConf_SecOCRxSecuredPdu_ELC_Lvr_Stat_ST3_secured_7bad7996_Rx 1u   /**< [PostBuildInvariantValuesModelView] */
#define SecOCConf_SecOCRxSecuredPdu_Ign_Stat_ST3_secured_87afaf29_Rx  2u      /**< [PostBuildInvariantValuesModelView] */
/**\} */






 
/* User Config File Start */

/* User Config File End */

 
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
 
 #endif  /* SECOC_CFG_H */
/**********************************************************************************************************************
  END OF FILE: SecOC_Cfg.h
**********************************************************************************************************************/
