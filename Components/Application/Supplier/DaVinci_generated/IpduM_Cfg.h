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
 *            Module: IpduM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: IpduM_Cfg.h
 *   Generation Time: 2023-07-10 14:36:06
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (IPDUM_CFG_H)
# define IPDUM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0785, 0786 EOF */ /* MD_CSL_DistinctIdentifiers */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Platform_Types.h"
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef IPDUM_USE_DUMMY_STATEMENT
#define IPDUM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef IPDUM_DUMMY_STATEMENT
#define IPDUM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef IPDUM_DUMMY_STATEMENT_CONST
#define IPDUM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef IPDUM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define IPDUM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef IPDUM_ATOMIC_VARIABLE_ACCESS
#define IPDUM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef IPDUM_PROCESSOR_TC322L
#define IPDUM_PROCESSOR_TC322L
#endif
#ifndef IPDUM_COMP_TASKING
#define IPDUM_COMP_TASKING
#endif
#ifndef IPDUM_GEN_GENERATOR_MSR
#define IPDUM_GEN_GENERATOR_MSR
#endif
#ifndef IPDUM_CPUTYPE_BITORDER_LSB2MSB
#define IPDUM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef IPDUM_CONFIGURATION_VARIANT_PRECOMPILE
#define IPDUM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef IPDUM_CONFIGURATION_VARIANT_LINKTIME
#define IPDUM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef IPDUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define IPDUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef IPDUM_CONFIGURATION_VARIANT
#define IPDUM_CONFIGURATION_VARIANT IPDUM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef IPDUM_POSTBUILD_VARIANT_SUPPORT
#define IPDUM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define IPDUM_DEV_ERROR_DETECT                 STD_ON  /**< /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMSafeBswChecks] || /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMDevErrorDetect] */
#define IPDUM_DEV_ERROR_REPORT                 STD_OFF  /**< /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMDevErrorDetect] */

#define IPDUM_LITTLE_ENDIAN                    0
#define IPDUM_BIG_ENDIAN                       1
#define IPDUM_HEADER_BYTE_ORDER                IPDUM_BIG_ENDIAN /**< /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMHeaderByteOrder] */

#define IPDUM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/IpduM/IpduMGeneral[0:IpduMVersionInfoApi] */
#define IPDUM_TRIGGER_TRANSMIT_API             STD_OFF  /**< /ActiveEcuC/PduR/IpduM[0:PduRTriggertransmit] */
#define IPDUM_TX_CONFIRMATION_API              STD_OFF  /**< /ActiveEcuC/PduR/IpduM[0:PduRTxConfirmation] */




/**
 * \defgroup IpduMHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define IpduMConf_IpduMRxIndication_IpduMRxIndication_17ccd7a3        1u      /**< [PostBuildInvariantValuesModelView] */
#define IpduMConf_IpduMRxIndication_IpduMRxIndication_33e88c66        0u      /**< [PostBuildInvariantValuesModelView] */
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

#endif  /* IPDUM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: IpduM_Cfg.h
**********************************************************************************************************************/

