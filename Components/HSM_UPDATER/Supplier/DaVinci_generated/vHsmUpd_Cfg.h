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
 *            Module: vHsmUpd
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vHsmUpd_Cfg.h
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


#if !defined (VHSMUPD_CFG_H)
#define VHSMUPD_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vMemAccM_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef VHSMUPD_USE_DUMMY_STATEMENT
#define VHSMUPD_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSMUPD_DUMMY_STATEMENT
#define VHSMUPD_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSMUPD_DUMMY_STATEMENT_CONST
#define VHSMUPD_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSMUPD_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VHSMUPD_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VHSMUPD_ATOMIC_VARIABLE_ACCESS
#define VHSMUPD_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VHSMUPD_PROCESSOR_TC397X_STEPB
#define VHSMUPD_PROCESSOR_TC397X_STEPB
#endif
#ifndef VHSMUPD_COMP_TASKING
#define VHSMUPD_COMP_TASKING
#endif
#ifndef VHSMUPD_GEN_GENERATOR_MSR
#define VHSMUPD_GEN_GENERATOR_MSR
#endif
#ifndef VHSMUPD_CPUTYPE_BITORDER_LSB2MSB
#define VHSMUPD_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VHSMUPD_CONFIGURATION_VARIANT_PRECOMPILE
#define VHSMUPD_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VHSMUPD_CONFIGURATION_VARIANT_LINKTIME
#define VHSMUPD_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VHSMUPD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VHSMUPD_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif



#define VHSMUPD_PLATFORM_PAGESIZE                                                                   32uL
#define PLATFORM_PAGESIZE                                                                           VHSMUPD_PLATFORM_PAGESIZE


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpdPCDataSwitches  vHsmUpd Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VHSMUPD_ADDRESSAREAID                                                                       STD_ON
#define VHSMUPD_EXPECTEDCOMPATIBILITYVERSION                                                        STD_OFF  /**< Deactivateable: 'vHsmUpd_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSMUPD_FINALMAGICNUMBER                                                                    STD_OFF  /**< Deactivateable: 'vHsmUpd_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VHSMUPD_GENERATORCOMPATIBILITYVERSION                                                       STD_OFF  /**< Deactivateable: 'vHsmUpd_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSMUPD_INITDATAHASHCODE                                                                    STD_OFF  /**< Deactivateable: 'vHsmUpd_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VHSMUPD_PCCONFIG                                                                            STD_ON
#define VHSMUPD_ADDRESSAREAIDOFPCCONFIG                                                             STD_ON
#define VHSMUPD_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                              STD_OFF  /**< Deactivateable: 'vHsmUpd_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSMUPD_FINALMAGICNUMBEROFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'vHsmUpd_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VHSMUPD_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'vHsmUpd_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSMUPD_INITDATAHASHCODEOFPCCONFIG                                                          STD_OFF  /**< Deactivateable: 'vHsmUpd_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCNoReferenceDefines  vHsmUpd No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define VHSMUPD_NO_EXPECTEDCOMPATIBILITYVERSION                                                     65535u
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCIsReducedToDefineDefines  vHsmUpd Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VHSMUPD_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                        STD_OFF
#define VHSMUPD_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                    STD_OFF
#define VHSMUPD_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                       STD_OFF
#define VHSMUPD_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                    STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCEqualsAlwaysToDefines  vHsmUpd Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VHSMUPD_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                          
#define VHSMUPD_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                      
#define VHSMUPD_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                         
#define VHSMUPD_EQ2_INITDATAHASHCODEOFPCCONFIG                                                      
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCSymbolicInitializationPointers  vHsmUpd Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vHsmUpd_Config_Ptr                                                                          NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vHsmUpd' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCInitializationSymbols  vHsmUpd Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vHsmUpd_Config                                                                              NULL_PTR  /**< symbolic identifier which could be used to initialize 'vHsmUpd */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCGeneral  vHsmUpd General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VHSMUPD_CHECK_INIT_POINTER                                                                  STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VHSMUPD_FINAL_MAGIC_NUMBER                                                                  0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vHsmUpd */
#define VHSMUPD_INDIVIDUAL_POSTBUILD                                                                STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vHsmUpd' is not configured to be postbuild capable. */
#define VHSMUPD_INIT_DATA                                                                           VHSMUPD_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VHSMUPD_INIT_DATA_HASH_CODE                                                                 -1221853672  /**< the precompile constant to validate the initialization structure at initialization time of vHsmUpd with a hashcode. The seed value is '0xFF1Eu' */
#define VHSMUPD_USE_ECUM_BSW_ERROR_HOOK                                                             STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VHSMUPD_USE_INIT_POINTER                                                                    STD_OFF  /**< STD_ON if the init pointer vHsmUpd shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpdPBDataSwitches  vHsmUpd Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VHSMUPD_PBCONFIG                                                                            STD_OFF  /**< Deactivateable: 'vHsmUpd_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VHSMUPD_LTCONFIGIDXOFPBCONFIG                                                               STD_OFF  /**< Deactivateable: 'vHsmUpd_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VHSMUPD_PCCONFIGIDXOFPBCONFIG                                                               STD_OFF  /**< Deactivateable: 'vHsmUpd_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPBIsReducedToDefineDefines  vHsmUpd Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VHSMUPD_ISDEF_LTCONFIGIDXOFPBCONFIG                                                         STD_OFF
#define VHSMUPD_ISDEF_PCCONFIGIDXOFPBCONFIG                                                         STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPBEqualsAlwaysToDefines  vHsmUpd Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VHSMUPD_EQ2_LTCONFIGIDXOFPBCONFIG                                                           
#define VHSMUPD_EQ2_PCCONFIGIDXOFPBCONFIG                                                           
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
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
  \defgroup  vHsmUpdPCGetRootDataMacros  vHsmUpd Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vHsmUpd_GetExpectedCompatibilityVersionOfPCConfig()                                           /**< Deactivateable: 'vHsmUpd_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_GetFinalMagicNumberOfPCConfig()                                                       /**< Deactivateable: 'vHsmUpd_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_GetGeneratorCompatibilityVersionOfPCConfig()                                          /**< Deactivateable: 'vHsmUpd_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_GetInitDataHashCodeOfPCConfig()                                                       /**< Deactivateable: 'vHsmUpd_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCGetConstantDuplicatedRootDataMacros  vHsmUpd Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vHsmUpd_GetAddressAreaIDOfPCConfig()                                                        0u
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCGetDeduplicatedDataMacros  vHsmUpd Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vHsmUpd_GetAddressAreaID()                                                                  vHsmUpd_GetAddressAreaIDOfPCConfig()
#define vHsmUpd_GetExpectedCompatibilityVersion()                                                     /**< Deactivateable: 'vHsmUpd_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_GetFinalMagicNumber()                                                                 /**< Deactivateable: 'vHsmUpd_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_GetGeneratorCompatibilityVersion()                                                    /**< Deactivateable: 'vHsmUpd_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_GetInitDataHashCode()                                                                 /**< Deactivateable: 'vHsmUpd_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPCHasMacros  vHsmUpd Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vHsmUpd_HasAddressAreaID()                                                                  (TRUE != FALSE)
#define vHsmUpd_HasExpectedCompatibilityVersion()                                                     /**< Deactivateable: 'vHsmUpd_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_HasFinalMagicNumber()                                                                 /**< Deactivateable: 'vHsmUpd_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_HasGeneratorCompatibilityVersion()                                                    /**< Deactivateable: 'vHsmUpd_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_HasInitDataHashCode()                                                                 /**< Deactivateable: 'vHsmUpd_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_HasPCConfig()                                                                       (TRUE != FALSE)
#define vHsmUpd_HasAddressAreaIDOfPCConfig()                                                        (TRUE != FALSE)
#define vHsmUpd_HasExpectedCompatibilityVersionOfPCConfig()                                           /**< Deactivateable: 'vHsmUpd_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_HasFinalMagicNumberOfPCConfig()                                                       /**< Deactivateable: 'vHsmUpd_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_HasGeneratorCompatibilityVersionOfPCConfig()                                          /**< Deactivateable: 'vHsmUpd_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_HasInitDataHashCodeOfPCConfig()                                                       /**< Deactivateable: 'vHsmUpd_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
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
/** 
  \defgroup  vHsmUpdPBGetRootDataMacros  vHsmUpd Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vHsmUpd_GetLTConfigIdxOfPBConfig()                                                            /**< Deactivateable: 'vHsmUpd_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsmUpd_GetPCConfigIdxOfPBConfig()                                                            /**< Deactivateable: 'vHsmUpd_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpdPBHasMacros  vHsmUpd Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vHsmUpd_HasPBConfig()                                                                         /**< Deactivateable: 'vHsmUpd_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsmUpd_HasLTConfigIdxOfPBConfig()                                                            /**< Deactivateable: 'vHsmUpd_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsmUpd_HasPCConfigIdxOfPBConfig()                                                            /**< Deactivateable: 'vHsmUpd_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpdPCValueTypes  vHsmUpd Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vHsmUpd_AddressAreaID */
typedef uint8 vHsmUpd_AddressAreaIDType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpdPCRootValueTypes  vHsmUpd Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vHsmUpd_PCConfig */
typedef struct svHsmUpd_PCConfigType
{
  uint8 vHsmUpd_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vHsmUpd_PCConfigType;

typedef vHsmUpd_PCConfigType vHsmUpd_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpdPBValueTypes  vHsmUpd Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpdPBRootValueTypes  vHsmUpd Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


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








#endif /* VHSMUPD_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Cfg.h
 *********************************************************************************************************************/

