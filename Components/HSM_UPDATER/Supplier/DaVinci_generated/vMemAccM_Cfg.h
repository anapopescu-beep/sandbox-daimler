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
 *            Module: vMemAccM
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMemAccM_Cfg.h
 *   Generation Time: 2022-04-13 13:37:46
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2000612_D04
 *      Tool Version: DaVinci Configurator (beta) 5.24.30 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/** Protection against multiple inclusion ***************************************************************************/
#if !defined (VMEMACCM_CFG_H)
# define VMEMACCM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMemAccM_vMemCfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/* version information */
/* This is not the sub-package version but a compatibility version, which will only be updated if a change in the 
   generator (i.e. generated files) affects the implementation sub-package */
#define VMEMACCM_CFG_MAJOR_VERSION	3u 
#define VMEMACCM_CFG_MINOR_VERSION	2u 
#define VMEMACCM_CFG_PATCH_VERSION	0u 

   
/* API configuration */
# define VMEMACCM_VERSION_INFO_API STD_OFF
# define VMEMACCM_COMPARE_API STD_OFF
#define VMEMACCM_MULTI_PARTITION_SATELLITE              STD_OFF 
#define VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR_MASTER STD_OFF 


/* Length of internal buffer used for compare requests (Length is maximal configured size for read requests) */
# define VMEMACCM_BUFFER_LENGTH 64u
  
/* Module configuration */
# define VMEMACCM_DEV_ERROR_DETECT STD_OFF
# define VMEMACCM_DEV_ERROR_REPORT STD_OFF


/*  General define block */
#ifndef VMEMACCM_USE_DUMMY_STATEMENT
#define VMEMACCM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VMEMACCM_DUMMY_STATEMENT
#define VMEMACCM_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VMEMACCM_DUMMY_STATEMENT_CONST
#define VMEMACCM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VMEMACCM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VMEMACCM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VMEMACCM_ATOMIC_VARIABLE_ACCESS
#define VMEMACCM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VMEMACCM_PROCESSOR_TC397X_STEPB
#define VMEMACCM_PROCESSOR_TC397X_STEPB
#endif
#ifndef VMEMACCM_COMP_TASKING
#define VMEMACCM_COMP_TASKING
#endif
#ifndef VMEMACCM_GEN_GENERATOR_MSR
#define VMEMACCM_GEN_GENERATOR_MSR
#endif
#ifndef VMEMACCM_CPUTYPE_BITORDER_LSB2MSB
#define VMEMACCM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VMEMACCM_CONFIGURATION_VARIANT_PRECOMPILE
#define VMEMACCM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VMEMACCM_CONFIGURATION_VARIANT_LINKTIME
#define VMEMACCM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VMEMACCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VMEMACCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef VMEMACCM_CONFIGURATION_VARIANT
#define VMEMACCM_CONFIGURATION_VARIANT VMEMACCM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef VMEMACCM_POSTBUILD_VARIANT_SUPPORT
#define VMEMACCM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Address area identifiers */



/**
 * \defgroup vMemAccMHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define vMemAccMConf_vMemAccMAddressAreaConfiguration_vMemAccMAddressAreaConfiguration 0u
/**\} */

/* Variant configuration */
/* Following macros hold the available variant identifiers and the number of the available identifiers. */
#define VMEMACCM_VARIANT_ID_STARTUP            0x00u 

#define VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS 0x01u 

#define VMEMACCM_VARIANT_LENGTHOFNOVARIANT     0x01u 



#endif  /* VMEMACCM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: vMemAccM_Cfg.h
**********************************************************************************************************************/

