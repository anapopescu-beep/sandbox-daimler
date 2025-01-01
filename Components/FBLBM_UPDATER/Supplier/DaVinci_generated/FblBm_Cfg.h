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
 *            Module: FblBm
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblBm_Cfg.h
 *   Generation Time: 2023-07-26 17:07:23
 *           Project: CBD2000614_fblbm_Upd - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (FBLBM_CFG_H)
# define FBLBM_CFG_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Configuration major version identification */ 
# define FBLBM_CFG_MAJOR_VERSION 2u 
/* Configuration minor version identification */ 
# define FBLBM_CFG_MINOR_VERSION 2u 
/* Defines how a corrupted bootloader is handled */ 
# define FBLBM_ENABLE_UPDATER_FAILSAFE 
/* Defines how missing keys are handled */ 
# define FBLBM_DISABLE_SECBOOT_FBL_INIT_KEY 
/* Defines how a missing bootloader mac is handled */ 
# define FBLBM_DISABLE_SECBOOT_FBL_INIT_MAC 
/* Defines whether secure boot is enabled or disabled */ 
# define FBLBM_DISABLE_SECURE_BOOT 
/* Defines whether stand-alone mode is enabled or disabled */ 
# define FBLBM_DISABLE_STANDALONE_MODE 
/* Defines the start address of the header */ 
# define FBLBM_HEADER_ADDRESS 0xA0034300u 
/* Defines size of the boottarget list */ 
# define FBLBM_BOOTTARGETLIST_SIZE 0u 
/* Defines build context */ 
# define FBLBM_INSTANCE_UPDATER 
/* Defines configuration files to be included */ 
# define FBLBM_DISABLE_GENERIC_CONFIGURATION 
# define FBLBM_DISABLE_HARDWARE_CONFIGURATION 
# define FBLBM_DISABLE_OEM_CONFIGURATION 
/* If enabled it is possible to verify the header structure separately */ 
# define FBLBM_DISABLE_HEADER_VERIFICATION 
/* If enabled it is possible to verify the LBT of the FBL separately */ 
# define FBLBM_DISABLE_FBLLBT_VERIFICATION 

/* General define block */
# ifndef FBLBM_USE_DUMMY_STATEMENT
#  define FBLBM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef FBLBM_DUMMY_STATEMENT
#  define FBLBM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef FBLBM_DUMMY_STATEMENT_CONST
#  define FBLBM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
# endif
# ifndef FBLBM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#  define FBLBM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
# endif
# ifndef FBLBM_ATOMIC_VARIABLE_ACCESS
#  define FBLBM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
# endif
# ifndef FBLBM_PROCESSOR_TC322L
#  define FBLBM_PROCESSOR_TC322L
# endif
# ifndef FBLBM_COMP_TASKING
#  define FBLBM_COMP_TASKING
# endif
# ifndef FBLBM_GEN_GENERATOR_MSR
#  define FBLBM_GEN_GENERATOR_MSR
# endif
# ifndef FBLBM_CPUTYPE_BITORDER_LSB2MSB
#  define FBLBM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
# endif
# ifndef FBLBM_CONFIGURATION_VARIANT_PRECOMPILE
#  define FBLBM_CONFIGURATION_VARIANT_PRECOMPILE 1
# endif
# ifndef FBLBM_CONFIGURATION_VARIANT_LINKTIME
#  define FBLBM_CONFIGURATION_VARIANT_LINKTIME 2
# endif
# ifndef FBLBM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#  define FBLBM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
# endif
# ifndef FBLBM_CONFIGURATION_VARIANT
#  define FBLBM_CONFIGURATION_VARIANT FBLBM_CONFIGURATION_VARIANT_PRECOMPILE
# endif
# ifndef FBLBM_POSTBUILD_VARIANT_SUPPORT
#  define FBLBM_POSTBUILD_VARIANT_SUPPORT STD_OFF
# endif


/**********************************************************************************************************************
 *  USER CONFIG FILE
 *********************************************************************************************************************/



#endif /* FBLBM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: FblBm_Cfg.h
 *********************************************************************************************************************/
