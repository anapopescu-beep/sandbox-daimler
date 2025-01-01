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
 *            Module: Crypto_30_KeyM
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_KeyM_Cfg.h
 *   Generation Time: 2022-09-22 10:43:13
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (CRYPTO_30_KEYM_CFG_H)
#define CRYPTO_30_KEYM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CRYPTO_30_KEYM_USE_DUMMY_STATEMENT
#define CRYPTO_30_KEYM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_KEYM_DUMMY_STATEMENT
#define CRYPTO_30_KEYM_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_KEYM_DUMMY_STATEMENT_CONST
#define CRYPTO_30_KEYM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_KEYM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRYPTO_30_KEYM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CRYPTO_30_KEYM_ATOMIC_VARIABLE_ACCESS
#define CRYPTO_30_KEYM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CRYPTO_30_KEYM_PROCESSOR_TC322L
#define CRYPTO_30_KEYM_PROCESSOR_TC322L
#endif
#ifndef CRYPTO_30_KEYM_COMP_TASKING
#define CRYPTO_30_KEYM_COMP_TASKING
#endif
#ifndef CRYPTO_30_KEYM_GEN_GENERATOR_MSR
#define CRYPTO_30_KEYM_GEN_GENERATOR_MSR
#endif
#ifndef CRYPTO_30_KEYM_CPUTYPE_BITORDER_LSB2MSB
#define CRYPTO_30_KEYM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CRYPTO_30_KEYM_CONFIGURATION_VARIANT_PRECOMPILE
#define CRYPTO_30_KEYM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRYPTO_30_KEYM_CONFIGURATION_VARIANT_LINKTIME
#define CRYPTO_30_KEYM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRYPTO_30_KEYM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRYPTO_30_KEYM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRYPTO_30_KEYM_CONFIGURATION_VARIANT
#define CRYPTO_30_KEYM_CONFIGURATION_VARIANT CRYPTO_30_KEYM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRYPTO_30_KEYM_POSTBUILD_VARIANT_SUPPORT
#define CRYPTO_30_KEYM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Microsar Define Block for Boolean and Integers */
#define CRYPTO_30_KEYM_MAX_ENTRIES_CSR_INFO                                                         16u 

/* Symbolic Name Define Block */
#define CryptoConf_CryptoDriverObject_Crypto_30_KeyM                                                0u 
#define CryptoConf_CryptoKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA                                0u 
#define CryptoConf_CryptoKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA                                1u 

#define CRYPTO_30_KEYM_SERVICE_CERTIFICATE_ENABLED                                                  STD_ON
#define CRYPTO_30_KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED                                          STD_OFF


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_KeyMPCDataSwitches  Crypto_30_KeyM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_KEYM_EXPECTEDCOMPATIBILITYVERSION                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_KEYM_FINALMAGICNUMBER                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_KEYM_GENERATORCOMPATIBILITYVERSION                                                STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_KEYM_INITDATAHASHCODE                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_KEYM_MAXENTRIESCSRINFOOFGENERAL                                                   STD_ON
#define CRYPTO_30_KEYM_PCCONFIG                                                                     STD_ON
#define CRYPTO_30_KEYM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_KEYM_FINALMAGICNUMBEROFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_KEYM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_KEYM_INITDATAHASHCODEOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_KEYM_MAXENTRIESCSRINFOOFGENERALOFPCCONFIG                                         STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCNoReferenceDefines  Crypto_30_KeyM No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CRYPTO_30_KEYM_NO_EXPECTEDCOMPATIBILITYVERSION                                              65535u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCIsReducedToDefineDefines  Crypto_30_KeyM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_KEYM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                 STD_OFF
#define CRYPTO_30_KEYM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                             STD_OFF
#define CRYPTO_30_KEYM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                STD_OFF
#define CRYPTO_30_KEYM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                             STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCEqualsAlwaysToDefines  Crypto_30_KeyM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_KEYM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                   
#define CRYPTO_30_KEYM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                               
#define CRYPTO_30_KEYM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                  
#define CRYPTO_30_KEYM_EQ2_INITDATAHASHCODEOFPCCONFIG                                               
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCSymbolicInitializationPointers  Crypto_30_KeyM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Crypto_30_KeyM_Config_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Crypto_30_KeyM' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCInitializationSymbols  Crypto_30_KeyM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Crypto_30_KeyM_Config                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'Crypto_30_KeyM */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCGeneral  Crypto_30_KeyM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CRYPTO_30_KEYM_CHECK_INIT_POINTER                                                           STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CRYPTO_30_KEYM_FINAL_MAGIC_NUMBER                                                           0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Crypto_30_KeyM */
#define CRYPTO_30_KEYM_INDIVIDUAL_POSTBUILD                                                         STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Crypto_30_KeyM' is not configured to be postbuild capable. */
#define CRYPTO_30_KEYM_INIT_DATA                                                                    CRYPTO_30_KEYM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CRYPTO_30_KEYM_INIT_DATA_HASH_CODE                                                          487688352  /**< the precompile constant to validate the initialization structure at initialization time of Crypto_30_KeyM with a hashcode. The seed value is '0xFF1Eu' */
#define CRYPTO_30_KEYM_USE_ECUM_BSW_ERROR_HOOK                                                      STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CRYPTO_30_KEYM_USE_INIT_POINTER                                                             STD_OFF  /**< STD_ON if the init pointer Crypto_30_KeyM shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_KeyMPBDataSwitches  Crypto_30_KeyM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_KEYM_PBCONFIG                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_KEYM_LTCONFIGIDXOFPBCONFIG                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_KEYM_PCCONFIGIDXOFPBCONFIG                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_KeyM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPBIsReducedToDefineDefines  Crypto_30_KeyM Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_KEYM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                  STD_OFF
#define CRYPTO_30_KEYM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                  STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPBEqualsAlwaysToDefines  Crypto_30_KeyM Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_KEYM_EQ2_LTCONFIGIDXOFPBCONFIG                                                    
#define CRYPTO_30_KEYM_EQ2_PCCONFIGIDXOFPBCONFIG                                                    
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
  \defgroup  Crypto_30_KeyMPCGetRootDataMacros  Crypto_30_KeyM Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_KeyM_GetExpectedCompatibilityVersionOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_KeyM_GetFinalMagicNumberOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_KeyM_GetGeneratorCompatibilityVersionOfPCConfig()                                   /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_KeyM_GetInitDataHashCodeOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCGetConstantDuplicatedRootDataMacros  Crypto_30_KeyM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Crypto_30_KeyM_GetMaxEntriesCsrInfoOfGeneralOfPCConfig()                                    16u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCGetDeduplicatedDataMacros  Crypto_30_KeyM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Crypto_30_KeyM_GetExpectedCompatibilityVersion()                                              /**< Deactivateable: 'Crypto_30_KeyM_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_KeyM_GetFinalMagicNumber()                                                          /**< Deactivateable: 'Crypto_30_KeyM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_KeyM_GetGeneratorCompatibilityVersion()                                             /**< Deactivateable: 'Crypto_30_KeyM_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_KeyM_GetInitDataHashCode()                                                          /**< Deactivateable: 'Crypto_30_KeyM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_KeyM_GetMaxEntriesCsrInfoOfGeneral()                                              Crypto_30_KeyM_GetMaxEntriesCsrInfoOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPCHasMacros  Crypto_30_KeyM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_KeyM_HasExpectedCompatibilityVersion()                                              /**< Deactivateable: 'Crypto_30_KeyM_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_KeyM_HasFinalMagicNumber()                                                          /**< Deactivateable: 'Crypto_30_KeyM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_KeyM_HasGeneratorCompatibilityVersion()                                             /**< Deactivateable: 'Crypto_30_KeyM_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_KeyM_HasInitDataHashCode()                                                          /**< Deactivateable: 'Crypto_30_KeyM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_KeyM_HasMaxEntriesCsrInfoOfGeneral()                                              (TRUE != FALSE)
#define Crypto_30_KeyM_HasPCConfig()                                                                (TRUE != FALSE)
#define Crypto_30_KeyM_HasExpectedCompatibilityVersionOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_KeyM_HasFinalMagicNumberOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_KeyM_HasGeneratorCompatibilityVersionOfPCConfig()                                   /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_KeyM_HasInitDataHashCodeOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_KeyM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_KeyM_HasMaxEntriesCsrInfoOfGeneralOfPCConfig()                                    (TRUE != FALSE)
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
  \defgroup  Crypto_30_KeyMPBGetRootDataMacros  Crypto_30_KeyM Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_KeyM_GetLTConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_KeyM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_KeyM_GetPCConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_KeyM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_KeyMPBHasMacros  Crypto_30_KeyM Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_KeyM_HasPBConfig()                                                                  /**< Deactivateable: 'Crypto_30_KeyM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_KeyM_HasLTConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_KeyM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_KeyM_HasPCConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_KeyM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
  \defgroup  Crypto_30_KeyMPCValueTypes  Crypto_30_KeyM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Crypto_30_KeyM_MaxEntriesCsrInfoOfGeneral */
typedef uint8 Crypto_30_KeyM_MaxEntriesCsrInfoOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_KeyMPCRootValueTypes  Crypto_30_KeyM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Crypto_30_KeyM_PCConfig */
typedef struct sCrypto_30_KeyM_PCConfigType
{
  uint8 Crypto_30_KeyM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Crypto_30_KeyM_PCConfigType;

typedef Crypto_30_KeyM_PCConfigType Crypto_30_KeyM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_KeyMPBValueTypes  Crypto_30_KeyM Value Types (POST_BUILD)
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
  \defgroup  Crypto_30_KeyMPBRootValueTypes  Crypto_30_KeyM Root Value Types (POST_BUILD)
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








#endif /* CRYPTO_30_KEYM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_KeyM_Cfg.h
 *********************************************************************************************************************/

