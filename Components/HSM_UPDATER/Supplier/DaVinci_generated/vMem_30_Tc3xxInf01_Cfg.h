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
 *            Module: vMem_30_Tc3xxInf01
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMem_30_Tc3xxInf01_Cfg.h
 *   Generation Time: 2022-05-23 18:39:40
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

#if !defined (VMEM_30_TC3XXINF01_CFG_H)
# define VMEM_30_TC3XXINF01_CFG_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"

/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/

/*! \brief Version defines of generator version */
# define VMEM_30_TC3XXINF01_CFG_MAJOR_VERSION        2uL
# define VMEM_30_TC3XXINF01_CFG_MINOR_VERSION        0uL
# define VMEM_30_TC3XXINF01_CFG_PATCH_VERSION        0uL

/*! \brief Version defines that are used to check the compatibility of the generated data */
# define VMEM_30_TC3XXINF01_CFG_COMP_MAJOR_VERSION   1uL
# define VMEM_30_TC3XXINF01_CFG_COMP_MINOR_VERSION   4uL
# define VMEM_30_TC3XXINF01_CFG_COMP_PATCH_VERSION   0uL


/**********************************************************************************************************************
 *  GENERAL DEFINE BLOCK
 *********************************************************************************************************************/

#ifndef VMEM_30_TC3XXINF01_USE_DUMMY_STATEMENT
#define VMEM_30_TC3XXINF01_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VMEM_30_TC3XXINF01_DUMMY_STATEMENT
#define VMEM_30_TC3XXINF01_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VMEM_30_TC3XXINF01_DUMMY_STATEMENT_CONST
#define VMEM_30_TC3XXINF01_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VMEM_30_TC3XXINF01_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VMEM_30_TC3XXINF01_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VMEM_30_TC3XXINF01_ATOMIC_VARIABLE_ACCESS
#define VMEM_30_TC3XXINF01_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VMEM_30_TC3XXINF01_PROCESSOR_TC397X_STEPB
#define VMEM_30_TC3XXINF01_PROCESSOR_TC397X_STEPB
#endif
#ifndef VMEM_30_TC3XXINF01_COMP_TASKING
#define VMEM_30_TC3XXINF01_COMP_TASKING
#endif
#ifndef VMEM_30_TC3XXINF01_GEN_GENERATOR_MSR
#define VMEM_30_TC3XXINF01_GEN_GENERATOR_MSR
#endif
#ifndef VMEM_30_TC3XXINF01_CPUTYPE_BITORDER_LSB2MSB
#define VMEM_30_TC3XXINF01_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT_PRECOMPILE
#define VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT_LINKTIME
#define VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT
#define VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT VMEM_30_TC3XXINF01_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef VMEM_30_TC3XXINF01_POSTBUILD_VARIANT_SUPPORT
#define VMEM_30_TC3XXINF01_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! \brief Enables / disables development error detection */
#ifndef VMEM_30_TC3XXINF01_DEV_ERROR_DETECT
# define VMEM_30_TC3XXINF01_DEV_ERROR_DETECT         STD_OFF
#endif

/*! \brief Enables / disables development error reporting (enabled whenever error detection is configured) */
#ifndef VMEM_30_TC3XXINF01_DEV_ERROR_REPORT
# define VMEM_30_TC3XXINF01_DEV_ERROR_REPORT         STD_OFF
#endif

/* \brief Enables / disables the version information API (VMEM_30_TC3XXINF01_GetVersionInfo) */
#ifndef VMEM_30_TC3XXINF01_VERSION_INFO_API
# define VMEM_30_TC3XXINF01_VERSION_INFO_API         STD_OFF
#endif

/* Add here additional general GLOBAL CONSTANT MACROS */


/*! \brief Enables / disables the usage of the APIs provided by OS to access memory mapped registers. */
#ifndef VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API
# define VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API STD_OFF
#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_Tc3xxInf01PCDataSwitches  vMem_30_Tc3xxInf01 Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VMEM_30_TC3XXINF01_FINALMAGICNUMBER                           STD_OFF  /**< Deactivateable: 'vMem_30_Tc3xxInf01_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_TC3XXINF01_INITDATAHASHCODE                           STD_OFF  /**< Deactivateable: 'vMem_30_Tc3xxInf01_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_TC3XXINF01_MEMSECTOR                                  STD_ON
#define VMEM_30_TC3XXINF01_ALTERNATEADDRESSOFMEMSECTOR                STD_ON
#define VMEM_30_TC3XXINF01_ERASEBURSTSIZEOFMEMSECTOR                  STD_ON
#define VMEM_30_TC3XXINF01_NROFSECTORSOFMEMSECTOR                     STD_ON
#define VMEM_30_TC3XXINF01_PAGESIZEOFMEMSECTOR                        STD_ON
#define VMEM_30_TC3XXINF01_PHYSICALSECTORIDOFMEMSECTOR                STD_ON
#define VMEM_30_TC3XXINF01_PROGRAMFLASHIDOFMEMSECTOR                  STD_ON
#define VMEM_30_TC3XXINF01_RAMALIGNMENTOFMEMSECTOR                    STD_ON
#define VMEM_30_TC3XXINF01_SECTORSIZEOFMEMSECTOR                      STD_ON
#define VMEM_30_TC3XXINF01_STARTADDRESSOFMEMSECTOR                    STD_ON
#define VMEM_30_TC3XXINF01_WRITEBURSTSIZEOFMEMSECTOR                  STD_ON
#define VMEM_30_TC3XXINF01_SIZEOFMEMSECTOR                            STD_ON
#define VMEM_30_TC3XXINF01_SIZEOFVMEMINSTANCE                         STD_ON
#define VMEM_30_TC3XXINF01_VMEMINSTANCE                               STD_ON
#define VMEM_30_TC3XXINF01_IDOFVMEMINSTANCE                           STD_ON
#define VMEM_30_TC3XXINF01_MEMSECTORENDIDXOFVMEMINSTANCE              STD_ON
#define VMEM_30_TC3XXINF01_MEMSECTORLENGTHOFVMEMINSTANCE              STD_ON
#define VMEM_30_TC3XXINF01_MEMSECTORSTARTIDXOFVMEMINSTANCE            STD_ON
#define VMEM_30_TC3XXINF01_PCCONFIG                                   STD_ON
#define VMEM_30_TC3XXINF01_FINALMAGICNUMBEROFPCCONFIG                 STD_OFF  /**< Deactivateable: 'vMem_30_Tc3xxInf01_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_TC3XXINF01_INITDATAHASHCODEOFPCCONFIG                 STD_OFF  /**< Deactivateable: 'vMem_30_Tc3xxInf01_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEM_30_TC3XXINF01_MEMSECTOROFPCCONFIG                        STD_ON
#define VMEM_30_TC3XXINF01_SIZEOFMEMSECTOROFPCCONFIG                  STD_ON
#define VMEM_30_TC3XXINF01_SIZEOFVMEMINSTANCEOFPCCONFIG               STD_ON
#define VMEM_30_TC3XXINF01_VMEMINSTANCEOFPCCONFIG                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCIsReducedToDefineDefines  vMem_30_Tc3xxInf01 Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VMEM_30_TC3XXINF01_ISDEF_ALTERNATEADDRESSOFMEMSECTOR          STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_ERASEBURSTSIZEOFMEMSECTOR            STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_NROFSECTORSOFMEMSECTOR               STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_PAGESIZEOFMEMSECTOR                  STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_PHYSICALSECTORIDOFMEMSECTOR          STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_PROGRAMFLASHIDOFMEMSECTOR            STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_RAMALIGNMENTOFMEMSECTOR              STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_SECTORSIZEOFMEMSECTOR                STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_STARTADDRESSOFMEMSECTOR              STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_WRITEBURSTSIZEOFMEMSECTOR            STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_IDOFVMEMINSTANCE                     STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_MEMSECTORENDIDXOFVMEMINSTANCE        STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_MEMSECTORLENGTHOFVMEMINSTANCE        STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_MEMSECTORSTARTIDXOFVMEMINSTANCE      STD_OFF
#define VMEM_30_TC3XXINF01_ISDEF_MEMSECTOROFPCCONFIG                  STD_ON
#define VMEM_30_TC3XXINF01_ISDEF_VMEMINSTANCEOFPCCONFIG               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCEqualsAlwaysToDefines  vMem_30_Tc3xxInf01 Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VMEM_30_TC3XXINF01_EQ2_ALTERNATEADDRESSOFMEMSECTOR            
#define VMEM_30_TC3XXINF01_EQ2_ERASEBURSTSIZEOFMEMSECTOR              
#define VMEM_30_TC3XXINF01_EQ2_NROFSECTORSOFMEMSECTOR                 
#define VMEM_30_TC3XXINF01_EQ2_PAGESIZEOFMEMSECTOR                    
#define VMEM_30_TC3XXINF01_EQ2_PHYSICALSECTORIDOFMEMSECTOR            
#define VMEM_30_TC3XXINF01_EQ2_PROGRAMFLASHIDOFMEMSECTOR              
#define VMEM_30_TC3XXINF01_EQ2_RAMALIGNMENTOFMEMSECTOR                
#define VMEM_30_TC3XXINF01_EQ2_SECTORSIZEOFMEMSECTOR                  
#define VMEM_30_TC3XXINF01_EQ2_STARTADDRESSOFMEMSECTOR                
#define VMEM_30_TC3XXINF01_EQ2_WRITEBURSTSIZEOFMEMSECTOR              
#define VMEM_30_TC3XXINF01_EQ2_IDOFVMEMINSTANCE                       
#define VMEM_30_TC3XXINF01_EQ2_MEMSECTORENDIDXOFVMEMINSTANCE          
#define VMEM_30_TC3XXINF01_EQ2_MEMSECTORLENGTHOFVMEMINSTANCE          
#define VMEM_30_TC3XXINF01_EQ2_MEMSECTORSTARTIDXOFVMEMINSTANCE        
#define VMEM_30_TC3XXINF01_EQ2_MEMSECTOROFPCCONFIG                    vMem_30_Tc3xxInf01_MemSector
#define VMEM_30_TC3XXINF01_EQ2_VMEMINSTANCEOFPCCONFIG                 vMem_30_Tc3xxInf01_vMemInstance
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCSymbolicInitializationPointers  vMem_30_Tc3xxInf01 Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vMem_30_Tc3xxInf01_Config_Ptr                                 NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vMem_30_Tc3xxInf01' */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCInitializationSymbols  vMem_30_Tc3xxInf01 Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vMem_30_Tc3xxInf01_Config                                     NULL_PTR  /**< symbolic identifier which could be used to initialize 'vMem_30_Tc3xxInf01 */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCGeneral  vMem_30_Tc3xxInf01 General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VMEM_30_TC3XXINF01_CHECK_INIT_POINTER                         STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VMEM_30_TC3XXINF01_FINAL_MAGIC_NUMBER                         0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vMem_30_Tc3xxInf01 */
#define VMEM_30_TC3XXINF01_INDIVIDUAL_POSTBUILD                       STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vMem_30_Tc3xxInf01' is not configured to be postbuild capable. */
#define VMEM_30_TC3XXINF01_INIT_DATA                                  VMEM_30_TC3XXINF01_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VMEM_30_TC3XXINF01_INIT_DATA_HASH_CODE                        315243738  /**< the precompile constant to validate the initialization structure at initialization time of vMem_30_Tc3xxInf01 with a hashcode. The seed value is '0xFF1Eu' */
#define VMEM_30_TC3XXINF01_USE_ECUM_BSW_ERROR_HOOK                    STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VMEM_30_TC3XXINF01_USE_INIT_POINTER                           STD_OFF  /**< STD_ON if the init pointer vMem_30_Tc3xxInf01 shall be used. */
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
  \defgroup  vMem_30_Tc3xxInf01PCGetConstantDuplicatedRootDataMacros  vMem_30_Tc3xxInf01 Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()                   vMem_30_Tc3xxInf01_MemSector  /**< the pointer to vMem_30_Tc3xxInf01_MemSector */
#define vMem_30_Tc3xxInf01_GetSizeOfMemSectorOfPCConfig()             1u  /**< the number of accomplishable value elements in vMem_30_Tc3xxInf01_MemSector */
#define vMem_30_Tc3xxInf01_GetSizeOfvMemInstanceOfPCConfig()          1u  /**< the number of accomplishable value elements in vMem_30_Tc3xxInf01_vMemInstance */
#define vMem_30_Tc3xxInf01_GetvMemInstanceOfPCConfig()                vMem_30_Tc3xxInf01_vMemInstance  /**< the pointer to vMem_30_Tc3xxInf01_vMemInstance */
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCGetDataMacros  vMem_30_Tc3xxInf01 Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vMem_30_Tc3xxInf01_GetAlternateAddressOfMemSector(Index)      (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].AlternateAddressOfMemSector)
#define vMem_30_Tc3xxInf01_GetEraseBurstSizeOfMemSector(Index)        (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].EraseBurstSizeOfMemSector)
#define vMem_30_Tc3xxInf01_GetNrOfSectorsOfMemSector(Index)           (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].NrOfSectorsOfMemSector)
#define vMem_30_Tc3xxInf01_GetPageSizeOfMemSector(Index)              (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].PageSizeOfMemSector)
#define vMem_30_Tc3xxInf01_GetPhysicalSectorIdOfMemSector(Index)      (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].PhysicalSectorIdOfMemSector)
#define vMem_30_Tc3xxInf01_GetProgramFlashIdOfMemSector(Index)        (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].ProgramFlashIdOfMemSector)
#define vMem_30_Tc3xxInf01_GetRamAlignmentOfMemSector(Index)          (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].RamAlignmentOfMemSector)
#define vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(Index)            (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].SectorSizeOfMemSector)
#define vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(Index)          (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].StartAddressOfMemSector)
#define vMem_30_Tc3xxInf01_GetWriteBurstSizeOfMemSector(Index)        (vMem_30_Tc3xxInf01_GetMemSectorOfPCConfig()[(Index)].WriteBurstSizeOfMemSector)
#define vMem_30_Tc3xxInf01_GetIdOfvMemInstance(Index)                 (vMem_30_Tc3xxInf01_GetvMemInstanceOfPCConfig()[(Index)].IdOfvMemInstance)
#define vMem_30_Tc3xxInf01_GetMemSectorEndIdxOfvMemInstance(Index)    (vMem_30_Tc3xxInf01_GetvMemInstanceOfPCConfig()[(Index)].MemSectorEndIdxOfvMemInstance)
#define vMem_30_Tc3xxInf01_GetMemSectorLengthOfvMemInstance(Index)    (vMem_30_Tc3xxInf01_GetvMemInstanceOfPCConfig()[(Index)].MemSectorLengthOfvMemInstance)
#define vMem_30_Tc3xxInf01_GetMemSectorStartIdxOfvMemInstance(Index)  (vMem_30_Tc3xxInf01_GetvMemInstanceOfPCConfig()[(Index)].MemSectorStartIdxOfvMemInstance)
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCGetDeduplicatedDataMacros  vMem_30_Tc3xxInf01 Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vMem_30_Tc3xxInf01_GetSizeOfMemSector()                       vMem_30_Tc3xxInf01_GetSizeOfMemSectorOfPCConfig()
#define vMem_30_Tc3xxInf01_GetSizeOfvMemInstance()                    vMem_30_Tc3xxInf01_GetSizeOfvMemInstanceOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCHasMacros  vMem_30_Tc3xxInf01 Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vMem_30_Tc3xxInf01_HasMemSector()                             (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasAlternateAddressOfMemSector()           (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasEraseBurstSizeOfMemSector()             (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasNrOfSectorsOfMemSector()                (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasPageSizeOfMemSector()                   (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasPhysicalSectorIdOfMemSector()           (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasProgramFlashIdOfMemSector()             (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasRamAlignmentOfMemSector()               (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasSectorSizeOfMemSector()                 (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasStartAddressOfMemSector()               (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasWriteBurstSizeOfMemSector()             (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasSizeOfMemSector()                       (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasSizeOfvMemInstance()                    (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasvMemInstance()                          (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasIdOfvMemInstance()                      (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasMemSectorEndIdxOfvMemInstance()         (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasMemSectorLengthOfvMemInstance()         (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasMemSectorStartIdxOfvMemInstance()       (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasPCConfig()                              (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasMemSectorOfPCConfig()                   (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasSizeOfMemSectorOfPCConfig()             (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasSizeOfvMemInstanceOfPCConfig()          (TRUE != FALSE)
#define vMem_30_Tc3xxInf01_HasvMemInstanceOfPCConfig()                (TRUE != FALSE)
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
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_Tc3xxInf01PCIterableTypes  vMem_30_Tc3xxInf01 Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vMem_30_Tc3xxInf01_MemSector */
typedef uint8_least vMem_30_Tc3xxInf01_MemSectorIterType;

/**   \brief  type used to iterate vMem_30_Tc3xxInf01_vMemInstance */
typedef uint8_least vMem_30_Tc3xxInf01_vMemInstanceIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCValueTypes  vMem_30_Tc3xxInf01 Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vMem_30_Tc3xxInf01_AlternateAddressOfMemSector */
typedef uint32 vMem_30_Tc3xxInf01_AlternateAddressOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_EraseBurstSizeOfMemSector */
typedef uint32 vMem_30_Tc3xxInf01_EraseBurstSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_NrOfSectorsOfMemSector */
typedef uint8 vMem_30_Tc3xxInf01_NrOfSectorsOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_PageSizeOfMemSector */
typedef uint8 vMem_30_Tc3xxInf01_PageSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_PhysicalSectorIdOfMemSector */
typedef uint8 vMem_30_Tc3xxInf01_PhysicalSectorIdOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_ProgramFlashIdOfMemSector */
typedef uint8 vMem_30_Tc3xxInf01_ProgramFlashIdOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_RamAlignmentOfMemSector */
typedef uint8 vMem_30_Tc3xxInf01_RamAlignmentOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_SectorSizeOfMemSector */
typedef uint16 vMem_30_Tc3xxInf01_SectorSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_StartAddressOfMemSector */
typedef uint32 vMem_30_Tc3xxInf01_StartAddressOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_WriteBurstSizeOfMemSector */
typedef uint16 vMem_30_Tc3xxInf01_WriteBurstSizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_SizeOfMemSector */
typedef uint8 vMem_30_Tc3xxInf01_SizeOfMemSectorType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_SizeOfvMemInstance */
typedef uint8 vMem_30_Tc3xxInf01_SizeOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_IdOfvMemInstance */
typedef uint8 vMem_30_Tc3xxInf01_IdOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_MemSectorEndIdxOfvMemInstance */
typedef uint8 vMem_30_Tc3xxInf01_MemSectorEndIdxOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_MemSectorLengthOfvMemInstance */
typedef uint8 vMem_30_Tc3xxInf01_MemSectorLengthOfvMemInstanceType;

/**   \brief  value based type definition for vMem_30_Tc3xxInf01_MemSectorStartIdxOfvMemInstance */
typedef uint8 vMem_30_Tc3xxInf01_MemSectorStartIdxOfvMemInstanceType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vMem_30_Tc3xxInf01PCStructTypes  vMem_30_Tc3xxInf01 Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vMem_30_Tc3xxInf01_MemSector */
typedef struct svMem_30_Tc3xxInf01_MemSectorType
{
  vMem_30_Tc3xxInf01_AlternateAddressOfMemSectorType AlternateAddressOfMemSector;  /**< Alternate address used for read jobs in case of alternate address map. */
  vMem_30_Tc3xxInf01_EraseBurstSizeOfMemSectorType EraseBurstSizeOfMemSector;  /**< Burst size for erase jobs, if configured. Otherwise sector size */
  vMem_30_Tc3xxInf01_StartAddressOfMemSectorType StartAddressOfMemSector;  /**< Physical start address of the first sector. */
  vMem_30_Tc3xxInf01_SectorSizeOfMemSectorType SectorSizeOfMemSector;  /**< Size of this sector in bytes. */
  vMem_30_Tc3xxInf01_WriteBurstSizeOfMemSectorType WriteBurstSizeOfMemSector;  /**< Burst size for write jobs, if configured. Otherwise page size */
  vMem_30_Tc3xxInf01_NrOfSectorsOfMemSectorType NrOfSectorsOfMemSector;  /**< Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize. */
  vMem_30_Tc3xxInf01_PageSizeOfMemSectorType PageSizeOfMemSector;  /**< Size of one page of this sector in bytes. */
  vMem_30_Tc3xxInf01_PhysicalSectorIdOfMemSectorType PhysicalSectorIdOfMemSector;  /**< Unique Identifier of Physical Sector within Program Flash Bank. */
  vMem_30_Tc3xxInf01_ProgramFlashIdOfMemSectorType ProgramFlashIdOfMemSector;  /**< Unique Identifier of Program Flash Bank. */
  vMem_30_Tc3xxInf01_RamAlignmentOfMemSectorType RamAlignmentOfMemSector;  /**< In order to perform write jobs correctly, a device might require a specific alignment of the data buffer. */
} vMem_30_Tc3xxInf01_MemSectorType;

/**   \brief  type used in vMem_30_Tc3xxInf01_vMemInstance */
typedef struct svMem_30_Tc3xxInf01_vMemInstanceType
{
  vMem_30_Tc3xxInf01_IdOfvMemInstanceType IdOfvMemInstance;  /**< Unique numeric identifier of the instance, used to distinguish between vMem instances. */
  vMem_30_Tc3xxInf01_MemSectorEndIdxOfvMemInstanceType MemSectorEndIdxOfvMemInstance;  /**< the end index of the 1:n relation pointing to vMem_30_Tc3xxInf01_MemSector */
  vMem_30_Tc3xxInf01_MemSectorLengthOfvMemInstanceType MemSectorLengthOfvMemInstance;  /**< the number of relations pointing to vMem_30_Tc3xxInf01_MemSector */
  vMem_30_Tc3xxInf01_MemSectorStartIdxOfvMemInstanceType MemSectorStartIdxOfvMemInstance;  /**< the start index of the 1:n relation pointing to vMem_30_Tc3xxInf01_MemSector */
} vMem_30_Tc3xxInf01_vMemInstanceType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCRootPointerTypes  vMem_30_Tc3xxInf01 Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vMem_30_Tc3xxInf01_MemSector */
typedef P2CONST(vMem_30_Tc3xxInf01_MemSectorType, TYPEDEF, VMEM_30_TC3XXINF01_CONST) vMem_30_Tc3xxInf01_MemSectorPtrType;

/**   \brief  type used to point to vMem_30_Tc3xxInf01_vMemInstance */
typedef P2CONST(vMem_30_Tc3xxInf01_vMemInstanceType, TYPEDEF, VMEM_30_TC3XXINF01_CONST) vMem_30_Tc3xxInf01_vMemInstancePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vMem_30_Tc3xxInf01PCRootValueTypes  vMem_30_Tc3xxInf01 Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vMem_30_Tc3xxInf01_PCConfig */
typedef struct svMem_30_Tc3xxInf01_PCConfigType
{
  uint8 vMem_30_Tc3xxInf01_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vMem_30_Tc3xxInf01_PCConfigType;

typedef vMem_30_Tc3xxInf01_PCConfigType vMem_30_Tc3xxInf01_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

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
  vMem_30_Tc3xxInf01_MemSector
**********************************************************************************************************************/
/** 
  \var    vMem_30_Tc3xxInf01_MemSector
  \brief  Configuration description of a programmable sector or sector batch.
  \details
  Element             Description
  AlternateAddress    Alternate address used for read jobs in case of alternate address map.
  EraseBurstSize      Burst size for erase jobs, if configured. Otherwise sector size
  StartAddress        Physical start address of the first sector.
  SectorSize          Size of this sector in bytes.
  WriteBurstSize      Burst size for write jobs, if configured. Otherwise page size
  NrOfSectors         Number of continuous sectors with identical values for vMemSectorSize and vMemPageSize.
  PageSize            Size of one page of this sector in bytes.
  PhysicalSectorId    Unique Identifier of Physical Sector within Program Flash Bank.
  ProgramFlashId      Unique Identifier of Program Flash Bank.
  RamAlignment        In order to perform write jobs correctly, a device might require a specific alignment of the data buffer.
*/ 
#define VMEM_30_TC3XXINF01_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_Tc3xxInf01_MemSectorType, VMEM_30_TC3XXINF01_CONST) vMem_30_Tc3xxInf01_MemSector[1];
#define VMEM_30_TC3XXINF01_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMem_30_Tc3xxInf01_vMemInstance
**********************************************************************************************************************/
/** 
  \var    vMem_30_Tc3xxInf01_vMemInstance
  \brief  List of all configured vMem instances.
  \details
  Element              Description
  Id                   Unique numeric identifier of the instance, used to distinguish between vMem instances.
  MemSectorEndIdx      the end index of the 1:n relation pointing to vMem_30_Tc3xxInf01_MemSector
  MemSectorLength      the number of relations pointing to vMem_30_Tc3xxInf01_MemSector
  MemSectorStartIdx    the start index of the 1:n relation pointing to vMem_30_Tc3xxInf01_MemSector
*/ 
#define VMEM_30_TC3XXINF01_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMem_30_Tc3xxInf01_vMemInstanceType, VMEM_30_TC3XXINF01_CONST) vMem_30_Tc3xxInf01_vMemInstance[1];
#define VMEM_30_TC3XXINF01_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif /* VMEM_30_TC3XXINF01_CFG_H */
