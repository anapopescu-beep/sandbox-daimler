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
 *            Module: vHsm_Hal
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vHsm_Hal_Cfg.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (VHSM_HAL_CFG_H)
#define VHSM_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef VHSM_HAL_USE_DUMMY_STATEMENT
#define VHSM_HAL_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSM_HAL_DUMMY_STATEMENT
#define VHSM_HAL_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSM_HAL_DUMMY_STATEMENT_CONST
#define VHSM_HAL_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSM_HAL_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VHSM_HAL_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VHSM_HAL_ATOMIC_VARIABLE_ACCESS
#define VHSM_HAL_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VHSM_HAL_PROCESSOR_TC322L
#define VHSM_HAL_PROCESSOR_TC322L
#endif
#ifndef VHSM_HAL_COMP_TASKING
#define VHSM_HAL_COMP_TASKING
#endif
#ifndef VHSM_HAL_GEN_GENERATOR_MSR
#define VHSM_HAL_GEN_GENERATOR_MSR
#endif
#ifndef VHSM_HAL_CPUTYPE_BITORDER_LSB2MSB
#define VHSM_HAL_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VHSM_HAL_CONFIGURATION_VARIANT_PRECOMPILE
#define VHSM_HAL_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VHSM_HAL_CONFIGURATION_VARIANT_LINKTIME
#define VHSM_HAL_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VHSM_HAL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VHSM_HAL_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif



/* Microsar Define Block for Boolean and Integers */
#define VHSM_HAL_APPLICATION_GENERATE_NOISE                                                         STD_OFF 
#define VHSM_HAL_PROVIDE_ISRS                                                                       STD_ON 

#define VHSM_HAL_VHSM_INTERRUPT_MODE                                                                STD_ON
#define VHSM_HAL_CATEGORY_1                                                                         0x00000000u
#define VHSM_HAL_CATEGORY_2                                                                         0x00000001u
#define VHSM_HAL_VHSM_ISR_FOR_PROCESSING                                                            VHSM_HAL_CATEGORY_1


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vHsm_HalPCDataSwitches  vHsm_Hal Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VHSM_HAL_APPLICATIONGENERATENOISEOFGENERAL                                                  STD_ON
#define VHSM_HAL_EXPECTEDCOMPATIBILITYVERSION                                                       STD_OFF  /**< Deactivateable: 'vHsm_Hal_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSM_HAL_FINALMAGICNUMBER                                                                   STD_OFF  /**< Deactivateable: 'vHsm_Hal_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VHSM_HAL_GENERATORCOMPATIBILITYVERSION                                                      STD_OFF  /**< Deactivateable: 'vHsm_Hal_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSM_HAL_HARDWAREUNITS                                                                      STD_ON
#define VHSM_HAL_HARDWAREUNITIDOFHARDWAREUNITS                                                      STD_ON
#define VHSM_HAL_HOST2HSMOFHARDWAREUNITS                                                            STD_ON
#define VHSM_HAL_HSM2HOSTOFHARDWAREUNITS                                                            STD_ON
#define VHSM_HAL_IPCIDOFHARDWAREUNITS                                                               STD_ON
#define VHSM_HAL_REQUESTSETADDRESSOFHARDWAREUNITS                                                   STD_ON
#define VHSM_HAL_RESPONSEADDRESSOFHARDWAREUNITS                                                     STD_ON
#define VHSM_HAL_RESPONSECLEARADDRESSOFHARDWAREUNITS                                                STD_ON
#define VHSM_HAL_RESPONSECLEARVALUEOFHARDWAREUNITS                                                  STD_ON
#define VHSM_HAL_INITDATAHASHCODE                                                                   STD_OFF  /**< Deactivateable: 'vHsm_Hal_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VHSM_HAL_INTERRUPTMODEOFSCHEDULING                                                          STD_ON
#define VHSM_HAL_ISRFORPROCESSINGOFSCHEDULING                                                       STD_ON
#define VHSM_HAL_PROVIDEISRSOFGENERAL                                                               STD_ON
#define VHSM_HAL_SIZEOFHARDWAREUNITS                                                                STD_ON
#define VHSM_HAL_PCCONFIG                                                                           STD_ON
#define VHSM_HAL_APPLICATIONGENERATENOISEOFGENERALOFPCCONFIG                                        STD_ON
#define VHSM_HAL_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                             STD_OFF  /**< Deactivateable: 'vHsm_Hal_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSM_HAL_FINALMAGICNUMBEROFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'vHsm_Hal_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VHSM_HAL_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                            STD_OFF  /**< Deactivateable: 'vHsm_Hal_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSM_HAL_HARDWAREUNITSOFPCCONFIG                                                            STD_ON
#define VHSM_HAL_INITDATAHASHCODEOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'vHsm_Hal_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VHSM_HAL_INTERRUPTMODEOFSCHEDULINGOFPCCONFIG                                                STD_ON
#define VHSM_HAL_ISRFORPROCESSINGOFSCHEDULINGOFPCCONFIG                                             STD_ON
#define VHSM_HAL_PROVIDEISRSOFGENERALOFPCCONFIG                                                     STD_ON
#define VHSM_HAL_SIZEOFHARDWAREUNITSOFPCCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCNoReferenceDefines  vHsm_Hal No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define VHSM_HAL_NO_EXPECTEDCOMPATIBILITYVERSION                                                    65535u
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCIsReducedToDefineDefines  vHsm_Hal Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VHSM_HAL_ISDEF_HARDWAREUNITIDOFHARDWAREUNITS                                                STD_OFF
#define VHSM_HAL_ISDEF_HOST2HSMOFHARDWAREUNITS                                                      STD_OFF
#define VHSM_HAL_ISDEF_HSM2HOSTOFHARDWAREUNITS                                                      STD_OFF
#define VHSM_HAL_ISDEF_IPCIDOFHARDWAREUNITS                                                         STD_OFF
#define VHSM_HAL_ISDEF_REQUESTSETADDRESSOFHARDWAREUNITS                                             STD_OFF
#define VHSM_HAL_ISDEF_RESPONSEADDRESSOFHARDWAREUNITS                                               STD_OFF
#define VHSM_HAL_ISDEF_RESPONSECLEARADDRESSOFHARDWAREUNITS                                          STD_OFF
#define VHSM_HAL_ISDEF_RESPONSECLEARVALUEOFHARDWAREUNITS                                            STD_OFF
#define VHSM_HAL_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                       STD_OFF
#define VHSM_HAL_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                   STD_OFF
#define VHSM_HAL_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                      STD_OFF
#define VHSM_HAL_ISDEF_HARDWAREUNITSOFPCCONFIG                                                      STD_ON
#define VHSM_HAL_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                   STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCEqualsAlwaysToDefines  vHsm_Hal Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VHSM_HAL_EQ2_HARDWAREUNITIDOFHARDWAREUNITS                                                  
#define VHSM_HAL_EQ2_HOST2HSMOFHARDWAREUNITS                                                        
#define VHSM_HAL_EQ2_HSM2HOSTOFHARDWAREUNITS                                                        
#define VHSM_HAL_EQ2_IPCIDOFHARDWAREUNITS                                                           
#define VHSM_HAL_EQ2_REQUESTSETADDRESSOFHARDWAREUNITS                                               
#define VHSM_HAL_EQ2_RESPONSEADDRESSOFHARDWAREUNITS                                                 
#define VHSM_HAL_EQ2_RESPONSECLEARADDRESSOFHARDWAREUNITS                                            
#define VHSM_HAL_EQ2_RESPONSECLEARVALUEOFHARDWAREUNITS                                              
#define VHSM_HAL_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                         
#define VHSM_HAL_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                     
#define VHSM_HAL_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                        
#define VHSM_HAL_EQ2_HARDWAREUNITSOFPCCONFIG                                                        vHsm_Hal_HardwareUnits
#define VHSM_HAL_EQ2_INITDATAHASHCODEOFPCCONFIG                                                     
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCSymbolicInitializationPointers  vHsm_Hal Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vHsm_Hal_Config_Ptr                                                                         NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vHsm_Hal' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCInitializationSymbols  vHsm_Hal Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vHsm_Hal_Config                                                                             NULL_PTR  /**< symbolic identifier which could be used to initialize 'vHsm_Hal */
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCGeneral  vHsm_Hal General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VHSM_HAL_CHECK_INIT_POINTER                                                                 STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VHSM_HAL_FINAL_MAGIC_NUMBER                                                                 0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vHsm_Hal */
#define VHSM_HAL_INDIVIDUAL_POSTBUILD                                                               STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vHsm_Hal' is not configured to be postbuild capable. */
#define VHSM_HAL_INIT_DATA                                                                          VHSM_HAL_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VHSM_HAL_INIT_DATA_HASH_CODE                                                                -255404535  /**< the precompile constant to validate the initialization structure at initialization time of vHsm_Hal with a hashcode. The seed value is '0xFF1Eu' */
#define VHSM_HAL_USE_ECUM_BSW_ERROR_HOOK                                                            STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VHSM_HAL_USE_INIT_POINTER                                                                   STD_OFF  /**< STD_ON if the init pointer vHsm_Hal shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vHsm_HalPBDataSwitches  vHsm_Hal Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VHSM_HAL_PBCONFIG                                                                           STD_OFF  /**< Deactivateable: 'vHsm_Hal_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VHSM_HAL_LTCONFIGIDXOFPBCONFIG                                                              STD_OFF  /**< Deactivateable: 'vHsm_Hal_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VHSM_HAL_PCCONFIGIDXOFPBCONFIG                                                              STD_OFF  /**< Deactivateable: 'vHsm_Hal_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPBIsReducedToDefineDefines  vHsm_Hal Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VHSM_HAL_ISDEF_LTCONFIGIDXOFPBCONFIG                                                        STD_OFF
#define VHSM_HAL_ISDEF_PCCONFIGIDXOFPBCONFIG                                                        STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPBEqualsAlwaysToDefines  vHsm_Hal Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VHSM_HAL_EQ2_LTCONFIGIDXOFPBCONFIG                                                          
#define VHSM_HAL_EQ2_PCCONFIGIDXOFPBCONFIG                                                          
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
  \defgroup  vHsm_HalPCGetRootDataMacros  vHsm_Hal Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vHsm_Hal_GetExpectedCompatibilityVersionOfPCConfig()                                          /**< Deactivateable: 'vHsm_Hal_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_Hal_GetFinalMagicNumberOfPCConfig()                                                      /**< Deactivateable: 'vHsm_Hal_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_Hal_GetGeneratorCompatibilityVersionOfPCConfig()                                         /**< Deactivateable: 'vHsm_Hal_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_Hal_GetInitDataHashCodeOfPCConfig()                                                      /**< Deactivateable: 'vHsm_Hal_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCGetConstantDuplicatedRootDataMacros  vHsm_Hal Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vHsm_Hal_IsApplicationGenerateNoiseOfGeneralOfPCConfig()                                    (((FALSE)) != FALSE)
#define vHsm_Hal_GetHardwareUnitsOfPCConfig()                                                       vHsm_Hal_HardwareUnits  /**< the pointer to vHsm_Hal_HardwareUnits */
#define vHsm_Hal_IsInterruptModeOfSchedulingOfPCConfig()                                            (((TRUE)) != FALSE)
#define vHsm_Hal_GetIsrForProcessingOfSchedulingOfPCConfig()                                        VHSM_HAL_CATEGORY_1
#define vHsm_Hal_IsProvideISRsOfGeneralOfPCConfig()                                                 (((TRUE)) != FALSE)
#define vHsm_Hal_GetSizeOfHardwareUnitsOfPCConfig()                                                 1u  /**< the number of accomplishable value elements in vHsm_Hal_HardwareUnits */
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCGetDataMacros  vHsm_Hal Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vHsm_Hal_GetHardwareUnitIDOfHardwareUnits(Index)                                            (vHsm_Hal_GetHardwareUnitsOfPCConfig()[(Index)].HardwareUnitIDOfHardwareUnits)
#define vHsm_Hal_GetHost2HsmOfHardwareUnits(Index)                                                  (vHsm_Hal_GetHardwareUnitsOfPCConfig()[(Index)].Host2HsmOfHardwareUnits)
#define vHsm_Hal_GetHsm2HostOfHardwareUnits(Index)                                                  (vHsm_Hal_GetHardwareUnitsOfPCConfig()[(Index)].Hsm2HostOfHardwareUnits)
#define vHsm_Hal_GetIPCIDOfHardwareUnits(Index)                                                     (vHsm_Hal_GetHardwareUnitsOfPCConfig()[(Index)].IPCIDOfHardwareUnits)
#define vHsm_Hal_GetRequestSetAddressOfHardwareUnits(Index)                                         (vHsm_Hal_GetHardwareUnitsOfPCConfig()[(Index)].RequestSetAddressOfHardwareUnits)
#define vHsm_Hal_GetResponseAddressOfHardwareUnits(Index)                                           (vHsm_Hal_GetHardwareUnitsOfPCConfig()[(Index)].ResponseAddressOfHardwareUnits)
#define vHsm_Hal_GetResponseClearAddressOfHardwareUnits(Index)                                      (vHsm_Hal_GetHardwareUnitsOfPCConfig()[(Index)].ResponseClearAddressOfHardwareUnits)
#define vHsm_Hal_GetResponseClearValueOfHardwareUnits(Index)                                        (vHsm_Hal_GetHardwareUnitsOfPCConfig()[(Index)].ResponseClearValueOfHardwareUnits)
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCGetDeduplicatedDataMacros  vHsm_Hal Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vHsm_Hal_IsApplicationGenerateNoiseOfGeneral()                                              vHsm_Hal_IsApplicationGenerateNoiseOfGeneralOfPCConfig()
#define vHsm_Hal_GetExpectedCompatibilityVersion()                                                    /**< Deactivateable: 'vHsm_Hal_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_Hal_GetFinalMagicNumber()                                                                /**< Deactivateable: 'vHsm_Hal_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_Hal_GetGeneratorCompatibilityVersion()                                                   /**< Deactivateable: 'vHsm_Hal_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_Hal_GetInitDataHashCode()                                                                /**< Deactivateable: 'vHsm_Hal_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_Hal_IsInterruptModeOfScheduling()                                                      vHsm_Hal_IsInterruptModeOfSchedulingOfPCConfig()
#define vHsm_Hal_GetIsrForProcessingOfScheduling()                                                  vHsm_Hal_GetIsrForProcessingOfSchedulingOfPCConfig()
#define vHsm_Hal_IsProvideISRsOfGeneral()                                                           vHsm_Hal_IsProvideISRsOfGeneralOfPCConfig()
#define vHsm_Hal_GetSizeOfHardwareUnits()                                                           vHsm_Hal_GetSizeOfHardwareUnitsOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCHasMacros  vHsm_Hal Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vHsm_Hal_HasApplicationGenerateNoiseOfGeneral()                                             (TRUE != FALSE)
#define vHsm_Hal_HasExpectedCompatibilityVersion()                                                    /**< Deactivateable: 'vHsm_Hal_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_Hal_HasFinalMagicNumber()                                                                /**< Deactivateable: 'vHsm_Hal_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_Hal_HasGeneratorCompatibilityVersion()                                                   /**< Deactivateable: 'vHsm_Hal_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_Hal_HasHardwareUnits()                                                                 (TRUE != FALSE)
#define vHsm_Hal_HasHardwareUnitIDOfHardwareUnits()                                                 (TRUE != FALSE)
#define vHsm_Hal_HasHost2HsmOfHardwareUnits()                                                       (TRUE != FALSE)
#define vHsm_Hal_HasHsm2HostOfHardwareUnits()                                                       (TRUE != FALSE)
#define vHsm_Hal_HasIPCIDOfHardwareUnits()                                                          (TRUE != FALSE)
#define vHsm_Hal_HasRequestSetAddressOfHardwareUnits()                                              (TRUE != FALSE)
#define vHsm_Hal_HasResponseAddressOfHardwareUnits()                                                (TRUE != FALSE)
#define vHsm_Hal_HasResponseClearAddressOfHardwareUnits()                                           (TRUE != FALSE)
#define vHsm_Hal_HasResponseClearValueOfHardwareUnits()                                             (TRUE != FALSE)
#define vHsm_Hal_HasInitDataHashCode()                                                                /**< Deactivateable: 'vHsm_Hal_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_Hal_HasInterruptModeOfScheduling()                                                     (TRUE != FALSE)
#define vHsm_Hal_HasIsrForProcessingOfScheduling()                                                  (TRUE != FALSE)
#define vHsm_Hal_HasProvideISRsOfGeneral()                                                          (TRUE != FALSE)
#define vHsm_Hal_HasSizeOfHardwareUnits()                                                           (TRUE != FALSE)
#define vHsm_Hal_HasPCConfig()                                                                      (TRUE != FALSE)
#define vHsm_Hal_HasApplicationGenerateNoiseOfGeneralOfPCConfig()                                   (TRUE != FALSE)
#define vHsm_Hal_HasExpectedCompatibilityVersionOfPCConfig()                                          /**< Deactivateable: 'vHsm_Hal_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_Hal_HasFinalMagicNumberOfPCConfig()                                                      /**< Deactivateable: 'vHsm_Hal_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_Hal_HasGeneratorCompatibilityVersionOfPCConfig()                                         /**< Deactivateable: 'vHsm_Hal_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_Hal_HasHardwareUnitsOfPCConfig()                                                       (TRUE != FALSE)
#define vHsm_Hal_HasInitDataHashCodeOfPCConfig()                                                      /**< Deactivateable: 'vHsm_Hal_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_Hal_HasInterruptModeOfSchedulingOfPCConfig()                                           (TRUE != FALSE)
#define vHsm_Hal_HasIsrForProcessingOfSchedulingOfPCConfig()                                        (TRUE != FALSE)
#define vHsm_Hal_HasProvideISRsOfGeneralOfPCConfig()                                                (TRUE != FALSE)
#define vHsm_Hal_HasSizeOfHardwareUnitsOfPCConfig()                                                 (TRUE != FALSE)
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
  \defgroup  vHsm_HalPBGetRootDataMacros  vHsm_Hal Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vHsm_Hal_GetLTConfigIdxOfPBConfig()                                                           /**< Deactivateable: 'vHsm_Hal_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsm_Hal_GetPCConfigIdxOfPBConfig()                                                           /**< Deactivateable: 'vHsm_Hal_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPBHasMacros  vHsm_Hal Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vHsm_Hal_HasPBConfig()                                                                        /**< Deactivateable: 'vHsm_Hal_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsm_Hal_HasLTConfigIdxOfPBConfig()                                                           /**< Deactivateable: 'vHsm_Hal_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsm_Hal_HasPCConfigIdxOfPBConfig()                                                           /**< Deactivateable: 'vHsm_Hal_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
  \defgroup  vHsm_HalPCIterableTypes  vHsm_Hal Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vHsm_Hal_HardwareUnits */
typedef uint8_least vHsm_Hal_HardwareUnitsIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCValueTypes  vHsm_Hal Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vHsm_Hal_ApplicationGenerateNoiseOfGeneral */
typedef boolean vHsm_Hal_ApplicationGenerateNoiseOfGeneralType;

/**   \brief  value based type definition for vHsm_Hal_HardwareUnitIDOfHardwareUnits */
typedef uint8 vHsm_Hal_HardwareUnitIDOfHardwareUnitsType;

/**   \brief  value based type definition for vHsm_Hal_Host2HsmOfHardwareUnits */
typedef uint32 vHsm_Hal_Host2HsmOfHardwareUnitsType;

/**   \brief  value based type definition for vHsm_Hal_Hsm2HostOfHardwareUnits */
typedef uint32 vHsm_Hal_Hsm2HostOfHardwareUnitsType;

/**   \brief  value based type definition for vHsm_Hal_IPCIDOfHardwareUnits */
typedef uint8 vHsm_Hal_IPCIDOfHardwareUnitsType;

/**   \brief  value based type definition for vHsm_Hal_RequestSetAddressOfHardwareUnits */
typedef uint32 vHsm_Hal_RequestSetAddressOfHardwareUnitsType;

/**   \brief  value based type definition for vHsm_Hal_ResponseAddressOfHardwareUnits */
typedef uint32 vHsm_Hal_ResponseAddressOfHardwareUnitsType;

/**   \brief  value based type definition for vHsm_Hal_ResponseClearAddressOfHardwareUnits */
typedef uint32 vHsm_Hal_ResponseClearAddressOfHardwareUnitsType;

/**   \brief  value based type definition for vHsm_Hal_ResponseClearValueOfHardwareUnits */
typedef uint8 vHsm_Hal_ResponseClearValueOfHardwareUnitsType;

/**   \brief  value based type definition for vHsm_Hal_InterruptModeOfScheduling */
typedef boolean vHsm_Hal_InterruptModeOfSchedulingType;

/**   \brief  value based type definition for vHsm_Hal_IsrForProcessingOfScheduling */
typedef uint32 vHsm_Hal_IsrForProcessingOfSchedulingType;

/**   \brief  value based type definition for vHsm_Hal_ProvideISRsOfGeneral */
typedef boolean vHsm_Hal_ProvideISRsOfGeneralType;

/**   \brief  value based type definition for vHsm_Hal_SizeOfHardwareUnits */
typedef uint8 vHsm_Hal_SizeOfHardwareUnitsType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsm_HalPCStructTypes  vHsm_Hal Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vHsm_Hal_HardwareUnits */
typedef struct svHsm_Hal_HardwareUnitsType
{
  vHsm_Hal_Host2HsmOfHardwareUnitsType Host2HsmOfHardwareUnits;  /**< Host to Hsm communication register */
  vHsm_Hal_Hsm2HostOfHardwareUnitsType Hsm2HostOfHardwareUnits;  /**< Hsm to Host communication register */
  vHsm_Hal_RequestSetAddressOfHardwareUnitsType RequestSetAddressOfHardwareUnits;  /**< Address of request interrupt register */
  vHsm_Hal_ResponseAddressOfHardwareUnitsType ResponseAddressOfHardwareUnits;  /**< Response interrupt register address */
  vHsm_Hal_ResponseClearAddressOfHardwareUnitsType ResponseClearAddressOfHardwareUnits;  /**< Address of request clear register */
  vHsm_Hal_HardwareUnitIDOfHardwareUnitsType HardwareUnitIDOfHardwareUnits;  /**< ID of hardware unit */
  vHsm_Hal_IPCIDOfHardwareUnitsType IPCIDOfHardwareUnits;  /**< IPC ID */
  vHsm_Hal_ResponseClearValueOfHardwareUnitsType ResponseClearValueOfHardwareUnits;  /**< Value to clear request clear register */
} vHsm_Hal_HardwareUnitsType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCRootPointerTypes  vHsm_Hal Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vHsm_Hal_HardwareUnits */
typedef P2CONST(vHsm_Hal_HardwareUnitsType, TYPEDEF, VHSM_HAL_CONST) vHsm_Hal_HardwareUnitsPtrType;

/**   \brief  type used to point to vHsm_Hal_IsrForProcessingOfSchedulingOfPCConfig */
typedef P2CONST(vHsm_Hal_IsrForProcessingOfSchedulingType, TYPEDEF, VHSM_HAL_CONST) vHsm_Hal_IsrForProcessingOfSchedulingOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsm_HalPCRootValueTypes  vHsm_Hal Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vHsm_Hal_PCConfig */
typedef struct svHsm_Hal_PCConfigType
{
  uint8 vHsm_Hal_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vHsm_Hal_PCConfigType;

typedef vHsm_Hal_PCConfigType vHsm_Hal_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsm_HalPBValueTypes  vHsm_Hal Value Types (POST_BUILD)
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
  \defgroup  vHsm_HalPBRootValueTypes  vHsm_Hal Root Value Types (POST_BUILD)
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
  vHsm_Hal_HardwareUnits
**********************************************************************************************************************/
/** 
  \var    vHsm_Hal_HardwareUnits
  \details
  Element                 Description
  Host2Hsm                Host to Hsm communication register
  Hsm2Host                Hsm to Host communication register
  RequestSetAddress       Address of request interrupt register
  ResponseAddress         Response interrupt register address
  ResponseClearAddress    Address of request clear register
  HardwareUnitID          ID of hardware unit
  IPCID                   IPC ID
  ResponseClearValue      Value to clear request clear register
*/ 
#define VHSM_HAL_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_Hal_HardwareUnitsType, VHSM_HAL_CONST) vHsm_Hal_HardwareUnits[1];
#define VHSM_HAL_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
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








#endif /* VHSM_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Hal_Cfg.h
 *********************************************************************************************************************/

