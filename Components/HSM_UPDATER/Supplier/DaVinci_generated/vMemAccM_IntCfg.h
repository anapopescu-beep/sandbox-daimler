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
 *              File: vMemAccM_IntCfg.h
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
#if !defined (VMEMACCM_INTCFG_H)
# define VMEMACCM_INTCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMemAccM_vMemApi.h"
# include "vMemAccM_vMemCfg.h"
# include "vMemAccM_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vMemAccMPCDataSwitches  vMemAccM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VMEMACCM_ADDRESSAREA                                                                        STD_ON
#define VMEMACCM_ADDRESSAREAVARIANTENDIDXOFADDRESSAREA                                              STD_ON
#define VMEMACCM_ADDRESSAREAVARIANTLENGTHOFADDRESSAREA                                              STD_ON
#define VMEMACCM_ADDRESSAREAVARIANTSTARTIDXOFADDRESSAREA                                            STD_ON
#define VMEMACCM_INVALIDHNDOFADDRESSAREA                                                            STD_OFF  /**< Deactivateable: 'vMemAccM_AddressArea.InvalidHnd' Reason: 'the value of vMemAccM_InvalidHndOfAddressArea is always 'false' due to this, the array is deactivated.' */
#define VMEMACCM_PRIORITYOFADDRESSAREA                                                              STD_ON
#define VMEMACCM_READLENGTHOFADDRESSAREA                                                            STD_ON
#define VMEMACCM_ADDRESSAREAVARIANT                                                                 STD_ON
#define VMEMACCM_IDOFADDRESSAREAVARIANT                                                             STD_ON
#define VMEMACCM_SUBADDRESSAREAENDIDXOFADDRESSAREAVARIANT                                           STD_ON
#define VMEMACCM_SUBADDRESSAREALENGTHOFADDRESSAREAVARIANT                                           STD_ON
#define VMEMACCM_SUBADDRESSAREASTARTIDXOFADDRESSAREAVARIANT                                         STD_ON
#define VMEMACCM_FINALMAGICNUMBER                                                                   STD_OFF  /**< Deactivateable: 'vMemAccM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEMACCM_INITDATAHASHCODE                                                                   STD_OFF  /**< Deactivateable: 'vMemAccM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEMACCM_SIZEOFADDRESSAREA                                                                  STD_ON
#define VMEMACCM_SIZEOFADDRESSAREAVARIANT                                                           STD_ON
#define VMEMACCM_SIZEOFSUBADDRESSAREA                                                               STD_ON
#define VMEMACCM_SUBADDRESSAREA                                                                     STD_ON
#define VMEMACCM_HARDWAREIDOFSUBADDRESSAREA                                                         STD_ON
#define VMEMACCM_NUMBEROFERASERETRIESOFSUBADDRESSAREA                                               STD_ON
#define VMEMACCM_NUMBEROFSECTORSOFSUBADDRESSAREA                                                    STD_ON
#define VMEMACCM_NUMBEROFWRITERETRIESOFSUBADDRESSAREA                                               STD_ON
#define VMEMACCM_PAGEBURSTRAMALIGNMENTOFSUBADDRESSAREA                                              STD_ON
#define VMEMACCM_PAGEBURSTSIZEOFSUBADDRESSAREA                                                      STD_ON
#define VMEMACCM_PAGESIZEOFSUBADDRESSAREA                                                           STD_ON
#define VMEMACCM_PHYSICALSTARTADDRESSOFSUBADDRESSAREA                                               STD_ON
#define VMEMACCM_SECTORBURSTSIZEOFSUBADDRESSAREA                                                    STD_ON
#define VMEMACCM_SECTORSIZEOFSUBADDRESSAREA                                                         STD_ON
#define VMEMACCM_USEPAGEBURSTOFSUBADDRESSAREA                                                       STD_ON
#define VMEMACCM_USESECTORBURSTOFSUBADDRESSAREA                                                     STD_ON
#define VMEMACCM_VIRTUALENDADDRESSOFSUBADDRESSAREA                                                  STD_ON
#define VMEMACCM_VIRTUALSTARTADDRESSOFSUBADDRESSAREA                                                STD_ON
#define VMEMACCM_VMEMAPITABLEOFSUBADDRESSAREA                                                       STD_ON
#define VMEMACCM_VMEMINSTANCEIDOFSUBADDRESSAREA                                                     STD_ON
#define VMEMACCM_PCCONFIG                                                                           STD_ON
#define VMEMACCM_ADDRESSAREAOFPCCONFIG                                                              STD_ON
#define VMEMACCM_ADDRESSAREAVARIANTOFPCCONFIG                                                       STD_ON
#define VMEMACCM_FINALMAGICNUMBEROFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'vMemAccM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VMEMACCM_INITDATAHASHCODEOFPCCONFIG                                                         STD_OFF  /**< Deactivateable: 'vMemAccM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VMEMACCM_SIZEOFADDRESSAREAOFPCCONFIG                                                        STD_ON
#define VMEMACCM_SIZEOFADDRESSAREAVARIANTOFPCCONFIG                                                 STD_ON
#define VMEMACCM_SIZEOFSUBADDRESSAREAOFPCCONFIG                                                     STD_ON
#define VMEMACCM_SUBADDRESSAREAOFPCCONFIG                                                           STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCIsReducedToDefineDefines  vMemAccM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VMEMACCM_ISDEF_ADDRESSAREAVARIANTENDIDXOFADDRESSAREA                                        STD_OFF
#define VMEMACCM_ISDEF_ADDRESSAREAVARIANTLENGTHOFADDRESSAREA                                        STD_OFF
#define VMEMACCM_ISDEF_ADDRESSAREAVARIANTSTARTIDXOFADDRESSAREA                                      STD_OFF
#define VMEMACCM_ISDEF_PRIORITYOFADDRESSAREA                                                        STD_OFF
#define VMEMACCM_ISDEF_READLENGTHOFADDRESSAREA                                                      STD_OFF
#define VMEMACCM_ISDEF_IDOFADDRESSAREAVARIANT                                                       STD_OFF
#define VMEMACCM_ISDEF_SUBADDRESSAREAENDIDXOFADDRESSAREAVARIANT                                     STD_OFF
#define VMEMACCM_ISDEF_SUBADDRESSAREALENGTHOFADDRESSAREAVARIANT                                     STD_OFF
#define VMEMACCM_ISDEF_SUBADDRESSAREASTARTIDXOFADDRESSAREAVARIANT                                   STD_OFF
#define VMEMACCM_ISDEF_HARDWAREIDOFSUBADDRESSAREA                                                   STD_OFF
#define VMEMACCM_ISDEF_NUMBEROFERASERETRIESOFSUBADDRESSAREA                                         STD_OFF
#define VMEMACCM_ISDEF_NUMBEROFSECTORSOFSUBADDRESSAREA                                              STD_OFF
#define VMEMACCM_ISDEF_NUMBEROFWRITERETRIESOFSUBADDRESSAREA                                         STD_OFF
#define VMEMACCM_ISDEF_PAGEBURSTRAMALIGNMENTOFSUBADDRESSAREA                                        STD_OFF
#define VMEMACCM_ISDEF_PAGEBURSTSIZEOFSUBADDRESSAREA                                                STD_OFF
#define VMEMACCM_ISDEF_PAGESIZEOFSUBADDRESSAREA                                                     STD_OFF
#define VMEMACCM_ISDEF_PHYSICALSTARTADDRESSOFSUBADDRESSAREA                                         STD_OFF
#define VMEMACCM_ISDEF_SECTORBURSTSIZEOFSUBADDRESSAREA                                              STD_OFF
#define VMEMACCM_ISDEF_SECTORSIZEOFSUBADDRESSAREA                                                   STD_OFF
#define VMEMACCM_ISDEF_USEPAGEBURSTOFSUBADDRESSAREA                                                 STD_OFF
#define VMEMACCM_ISDEF_USESECTORBURSTOFSUBADDRESSAREA                                               STD_OFF
#define VMEMACCM_ISDEF_VIRTUALENDADDRESSOFSUBADDRESSAREA                                            STD_OFF
#define VMEMACCM_ISDEF_VIRTUALSTARTADDRESSOFSUBADDRESSAREA                                          STD_OFF
#define VMEMACCM_ISDEF_VMEMAPITABLEOFSUBADDRESSAREA                                                 STD_OFF
#define VMEMACCM_ISDEF_VMEMINSTANCEIDOFSUBADDRESSAREA                                               STD_OFF
#define VMEMACCM_ISDEF_ADDRESSAREAOFPCCONFIG                                                        STD_ON
#define VMEMACCM_ISDEF_ADDRESSAREAVARIANTOFPCCONFIG                                                 STD_ON
#define VMEMACCM_ISDEF_SUBADDRESSAREAOFPCCONFIG                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCEqualsAlwaysToDefines  vMemAccM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VMEMACCM_EQ2_ADDRESSAREAVARIANTENDIDXOFADDRESSAREA                                          
#define VMEMACCM_EQ2_ADDRESSAREAVARIANTLENGTHOFADDRESSAREA                                          
#define VMEMACCM_EQ2_ADDRESSAREAVARIANTSTARTIDXOFADDRESSAREA                                        
#define VMEMACCM_EQ2_PRIORITYOFADDRESSAREA                                                          
#define VMEMACCM_EQ2_READLENGTHOFADDRESSAREA                                                        
#define VMEMACCM_EQ2_IDOFADDRESSAREAVARIANT                                                         
#define VMEMACCM_EQ2_SUBADDRESSAREAENDIDXOFADDRESSAREAVARIANT                                       
#define VMEMACCM_EQ2_SUBADDRESSAREALENGTHOFADDRESSAREAVARIANT                                       
#define VMEMACCM_EQ2_SUBADDRESSAREASTARTIDXOFADDRESSAREAVARIANT                                     
#define VMEMACCM_EQ2_HARDWAREIDOFSUBADDRESSAREA                                                     
#define VMEMACCM_EQ2_NUMBEROFERASERETRIESOFSUBADDRESSAREA                                           
#define VMEMACCM_EQ2_NUMBEROFSECTORSOFSUBADDRESSAREA                                                
#define VMEMACCM_EQ2_NUMBEROFWRITERETRIESOFSUBADDRESSAREA                                           
#define VMEMACCM_EQ2_PAGEBURSTRAMALIGNMENTOFSUBADDRESSAREA                                          
#define VMEMACCM_EQ2_PAGEBURSTSIZEOFSUBADDRESSAREA                                                  
#define VMEMACCM_EQ2_PAGESIZEOFSUBADDRESSAREA                                                       
#define VMEMACCM_EQ2_PHYSICALSTARTADDRESSOFSUBADDRESSAREA                                           
#define VMEMACCM_EQ2_SECTORBURSTSIZEOFSUBADDRESSAREA                                                
#define VMEMACCM_EQ2_SECTORSIZEOFSUBADDRESSAREA                                                     
#define VMEMACCM_EQ2_USEPAGEBURSTOFSUBADDRESSAREA                                                   
#define VMEMACCM_EQ2_USESECTORBURSTOFSUBADDRESSAREA                                                 
#define VMEMACCM_EQ2_VIRTUALENDADDRESSOFSUBADDRESSAREA                                              
#define VMEMACCM_EQ2_VIRTUALSTARTADDRESSOFSUBADDRESSAREA                                            
#define VMEMACCM_EQ2_VMEMAPITABLEOFSUBADDRESSAREA                                                   
#define VMEMACCM_EQ2_VMEMINSTANCEIDOFSUBADDRESSAREA                                                 
#define VMEMACCM_EQ2_ADDRESSAREAOFPCCONFIG                                                          vMemAccM_AddressArea
#define VMEMACCM_EQ2_ADDRESSAREAVARIANTOFPCCONFIG                                                   vMemAccM_AddressAreaVariant
#define VMEMACCM_EQ2_SUBADDRESSAREAOFPCCONFIG                                                       vMemAccM_SubAddressArea
/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCSymbolicInitializationPointers  vMemAccM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vMemAccM_Config_Ptr                                                                         NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vMemAccM' */
/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCInitializationSymbols  vMemAccM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vMemAccM_Config                                                                             NULL_PTR  /**< symbolic identifier which could be used to initialize 'vMemAccM */
/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCGeneral  vMemAccM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VMEMACCM_CHECK_INIT_POINTER                                                                 STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VMEMACCM_FINAL_MAGIC_NUMBER                                                                 0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vMemAccM */
#define VMEMACCM_INDIVIDUAL_POSTBUILD                                                               STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vMemAccM' is not configured to be postbuild capable. */
#define VMEMACCM_INIT_DATA                                                                          VMEMACCM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VMEMACCM_INIT_DATA_HASH_CODE                                                                -3408576  /**< the precompile constant to validate the initialization structure at initialization time of vMemAccM with a hashcode. The seed value is '0xFF1Eu' */
#define VMEMACCM_USE_ECUM_BSW_ERROR_HOOK                                                            STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VMEMACCM_USE_INIT_POINTER                                                                   STD_OFF  /**< STD_ON if the init pointer vMemAccM shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  MULTI PARTITION GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define VMEMACCM_SINGLE_PARTITION                  0x00u 

#define VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS   0x01u 

#define VMEMACCM_MULTI_PARTITION_SINGLE_ACCESSOR   0x02u 

#define VMEMACCM_MULTI_PARTITION_PUBLISH_DATA_SIZE 0x0010u 

#define VMEMACCM_PARTITION_USECASE                 VMEMACCM_SINGLE_PARTITION 



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
  \defgroup  vMemAccMPCGetConstantDuplicatedRootDataMacros  vMemAccM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vMemAccM_GetAddressAreaOfPCConfig()                                                         vMemAccM_AddressArea  /**< the pointer to vMemAccM_AddressArea */
#define vMemAccM_GetAddressAreaVariantOfPCConfig()                                                  vMemAccM_AddressAreaVariant  /**< the pointer to vMemAccM_AddressAreaVariant */
#define vMemAccM_GetSizeOfAddressAreaOfPCConfig()                                                   1u  /**< the number of accomplishable value elements in vMemAccM_AddressArea */
#define vMemAccM_GetSizeOfAddressAreaVariantOfPCConfig()                                            1u  /**< the number of accomplishable value elements in vMemAccM_AddressAreaVariant */
#define vMemAccM_GetSizeOfSubAddressAreaOfPCConfig()                                                1u  /**< the number of accomplishable value elements in vMemAccM_SubAddressArea */
#define vMemAccM_GetSubAddressAreaOfPCConfig()                                                      vMemAccM_SubAddressArea  /**< the pointer to vMemAccM_SubAddressArea */
/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCGetDataMacros  vMemAccM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vMemAccM_GetAddressAreaVariantEndIdxOfAddressArea(Index)                                    (vMemAccM_GetAddressAreaOfPCConfig()[(Index)].AddressAreaVariantEndIdxOfAddressArea)
#define vMemAccM_GetAddressAreaVariantLengthOfAddressArea(Index)                                    (vMemAccM_GetAddressAreaOfPCConfig()[(Index)].AddressAreaVariantLengthOfAddressArea)
#define vMemAccM_GetAddressAreaVariantStartIdxOfAddressArea(Index)                                  (vMemAccM_GetAddressAreaOfPCConfig()[(Index)].AddressAreaVariantStartIdxOfAddressArea)
#define vMemAccM_GetPriorityOfAddressArea(Index)                                                    (vMemAccM_GetAddressAreaOfPCConfig()[(Index)].PriorityOfAddressArea)
#define vMemAccM_GetReadLengthOfAddressArea(Index)                                                  (vMemAccM_GetAddressAreaOfPCConfig()[(Index)].ReadLengthOfAddressArea)
#define vMemAccM_GetIdOfAddressAreaVariant(Index)                                                   (vMemAccM_GetAddressAreaVariantOfPCConfig()[(Index)].IdOfAddressAreaVariant)
#define vMemAccM_GetSubAddressAreaEndIdxOfAddressAreaVariant(Index)                                 (vMemAccM_GetAddressAreaVariantOfPCConfig()[(Index)].SubAddressAreaEndIdxOfAddressAreaVariant)
#define vMemAccM_GetSubAddressAreaLengthOfAddressAreaVariant(Index)                                 (vMemAccM_GetAddressAreaVariantOfPCConfig()[(Index)].SubAddressAreaLengthOfAddressAreaVariant)
#define vMemAccM_GetSubAddressAreaStartIdxOfAddressAreaVariant(Index)                               (vMemAccM_GetAddressAreaVariantOfPCConfig()[(Index)].SubAddressAreaStartIdxOfAddressAreaVariant)
#define vMemAccM_GetHardwareIdOfSubAddressArea(Index)                                               (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].HardwareIdOfSubAddressArea)
#define vMemAccM_GetNumberOfEraseRetriesOfSubAddressArea(Index)                                     (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].NumberOfEraseRetriesOfSubAddressArea)
#define vMemAccM_GetNumberOfSectorsOfSubAddressArea(Index)                                          (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].NumberOfSectorsOfSubAddressArea)
#define vMemAccM_GetNumberOfWriteRetriesOfSubAddressArea(Index)                                     (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].NumberOfWriteRetriesOfSubAddressArea)
#define vMemAccM_GetPageBurstRamAlignmentOfSubAddressArea(Index)                                    (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].PageBurstRamAlignmentOfSubAddressArea)
#define vMemAccM_GetPageBurstSizeOfSubAddressArea(Index)                                            (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].PageBurstSizeOfSubAddressArea)
#define vMemAccM_GetPageSizeOfSubAddressArea(Index)                                                 (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].PageSizeOfSubAddressArea)
#define vMemAccM_GetPhysicalStartAddressOfSubAddressArea(Index)                                     (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].PhysicalStartAddressOfSubAddressArea)
#define vMemAccM_GetSectorBurstSizeOfSubAddressArea(Index)                                          (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].SectorBurstSizeOfSubAddressArea)
#define vMemAccM_GetSectorSizeOfSubAddressArea(Index)                                               (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].SectorSizeOfSubAddressArea)
#define vMemAccM_IsUsePageBurstOfSubAddressArea(Index)                                              ((vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].UsePageBurstOfSubAddressArea) != FALSE)
#define vMemAccM_IsUseSectorBurstOfSubAddressArea(Index)                                            ((vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].UseSectorBurstOfSubAddressArea) != FALSE)
#define vMemAccM_GetVirtualEndAddressOfSubAddressArea(Index)                                        (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].VirtualEndAddressOfSubAddressArea)
#define vMemAccM_GetVirtualStartAddressOfSubAddressArea(Index)                                      (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].VirtualStartAddressOfSubAddressArea)
#define vMemAccM_GetvMemApiTableOfSubAddressArea(Index)                                             (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].vMemApiTableOfSubAddressArea)
#define vMemAccM_GetvMemInstanceIdOfSubAddressArea(Index)                                           (vMemAccM_GetSubAddressAreaOfPCConfig()[(Index)].vMemInstanceIdOfSubAddressArea)
/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCGetDeduplicatedDataMacros  vMemAccM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vMemAccM_GetSizeOfAddressArea()                                                             vMemAccM_GetSizeOfAddressAreaOfPCConfig()
#define vMemAccM_GetSizeOfAddressAreaVariant()                                                      vMemAccM_GetSizeOfAddressAreaVariantOfPCConfig()
#define vMemAccM_GetSizeOfSubAddressArea()                                                          vMemAccM_GetSizeOfSubAddressAreaOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCHasMacros  vMemAccM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vMemAccM_HasAddressArea()                                                                   (TRUE != FALSE)
#define vMemAccM_HasAddressAreaVariantEndIdxOfAddressArea()                                         (TRUE != FALSE)
#define vMemAccM_HasAddressAreaVariantLengthOfAddressArea()                                         (TRUE != FALSE)
#define vMemAccM_HasAddressAreaVariantStartIdxOfAddressArea()                                       (TRUE != FALSE)
#define vMemAccM_HasPriorityOfAddressArea()                                                         (TRUE != FALSE)
#define vMemAccM_HasReadLengthOfAddressArea()                                                       (TRUE != FALSE)
#define vMemAccM_HasAddressAreaVariant()                                                            (TRUE != FALSE)
#define vMemAccM_HasIdOfAddressAreaVariant()                                                        (TRUE != FALSE)
#define vMemAccM_HasSubAddressAreaEndIdxOfAddressAreaVariant()                                      (TRUE != FALSE)
#define vMemAccM_HasSubAddressAreaLengthOfAddressAreaVariant()                                      (TRUE != FALSE)
#define vMemAccM_HasSubAddressAreaStartIdxOfAddressAreaVariant()                                    (TRUE != FALSE)
#define vMemAccM_HasSizeOfAddressArea()                                                             (TRUE != FALSE)
#define vMemAccM_HasSizeOfAddressAreaVariant()                                                      (TRUE != FALSE)
#define vMemAccM_HasSizeOfSubAddressArea()                                                          (TRUE != FALSE)
#define vMemAccM_HasSubAddressArea()                                                                (TRUE != FALSE)
#define vMemAccM_HasHardwareIdOfSubAddressArea()                                                    (TRUE != FALSE)
#define vMemAccM_HasNumberOfEraseRetriesOfSubAddressArea()                                          (TRUE != FALSE)
#define vMemAccM_HasNumberOfSectorsOfSubAddressArea()                                               (TRUE != FALSE)
#define vMemAccM_HasNumberOfWriteRetriesOfSubAddressArea()                                          (TRUE != FALSE)
#define vMemAccM_HasPageBurstRamAlignmentOfSubAddressArea()                                         (TRUE != FALSE)
#define vMemAccM_HasPageBurstSizeOfSubAddressArea()                                                 (TRUE != FALSE)
#define vMemAccM_HasPageSizeOfSubAddressArea()                                                      (TRUE != FALSE)
#define vMemAccM_HasPhysicalStartAddressOfSubAddressArea()                                          (TRUE != FALSE)
#define vMemAccM_HasSectorBurstSizeOfSubAddressArea()                                               (TRUE != FALSE)
#define vMemAccM_HasSectorSizeOfSubAddressArea()                                                    (TRUE != FALSE)
#define vMemAccM_HasUsePageBurstOfSubAddressArea()                                                  (TRUE != FALSE)
#define vMemAccM_HasUseSectorBurstOfSubAddressArea()                                                (TRUE != FALSE)
#define vMemAccM_HasVirtualEndAddressOfSubAddressArea()                                             (TRUE != FALSE)
#define vMemAccM_HasVirtualStartAddressOfSubAddressArea()                                           (TRUE != FALSE)
#define vMemAccM_HasvMemApiTableOfSubAddressArea()                                                  (TRUE != FALSE)
#define vMemAccM_HasvMemInstanceIdOfSubAddressArea()                                                (TRUE != FALSE)
#define vMemAccM_HasPCConfig()                                                                      (TRUE != FALSE)
#define vMemAccM_HasAddressAreaOfPCConfig()                                                         (TRUE != FALSE)
#define vMemAccM_HasAddressAreaVariantOfPCConfig()                                                  (TRUE != FALSE)
#define vMemAccM_HasSizeOfAddressAreaOfPCConfig()                                                   (TRUE != FALSE)
#define vMemAccM_HasSizeOfAddressAreaVariantOfPCConfig()                                            (TRUE != FALSE)
#define vMemAccM_HasSizeOfSubAddressAreaOfPCConfig()                                                (TRUE != FALSE)
#define vMemAccM_HasSubAddressAreaOfPCConfig()                                                      (TRUE != FALSE)
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
  \defgroup  vMemAccMPCIterableTypes  vMemAccM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vMemAccM_AddressArea */
typedef uint8_least vMemAccM_AddressAreaIterType;

/**   \brief  type used to iterate vMemAccM_AddressAreaVariant */
typedef uint8_least vMemAccM_AddressAreaVariantIterType;

/**   \brief  type used to iterate vMemAccM_SubAddressArea */
typedef uint8_least vMemAccM_SubAddressAreaIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCValueTypes  vMemAccM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vMemAccM_AddressAreaVariantEndIdxOfAddressArea */
typedef uint8 vMemAccM_AddressAreaVariantEndIdxOfAddressAreaType;

/**   \brief  value based type definition for vMemAccM_AddressAreaVariantLengthOfAddressArea */
typedef uint8 vMemAccM_AddressAreaVariantLengthOfAddressAreaType;

/**   \brief  value based type definition for vMemAccM_AddressAreaVariantStartIdxOfAddressArea */
typedef uint8 vMemAccM_AddressAreaVariantStartIdxOfAddressAreaType;

/**   \brief  value based type definition for vMemAccM_PriorityOfAddressArea */
typedef uint8 vMemAccM_PriorityOfAddressAreaType;

/**   \brief  value based type definition for vMemAccM_ReadLengthOfAddressArea */
typedef uint8 vMemAccM_ReadLengthOfAddressAreaType;

/**   \brief  value based type definition for vMemAccM_IdOfAddressAreaVariant */
typedef uint8 vMemAccM_IdOfAddressAreaVariantType;

/**   \brief  value based type definition for vMemAccM_SubAddressAreaEndIdxOfAddressAreaVariant */
typedef uint8 vMemAccM_SubAddressAreaEndIdxOfAddressAreaVariantType;

/**   \brief  value based type definition for vMemAccM_SubAddressAreaLengthOfAddressAreaVariant */
typedef uint8 vMemAccM_SubAddressAreaLengthOfAddressAreaVariantType;

/**   \brief  value based type definition for vMemAccM_SubAddressAreaStartIdxOfAddressAreaVariant */
typedef uint8 vMemAccM_SubAddressAreaStartIdxOfAddressAreaVariantType;

/**   \brief  value based type definition for vMemAccM_SizeOfAddressArea */
typedef uint8 vMemAccM_SizeOfAddressAreaType;

/**   \brief  value based type definition for vMemAccM_SizeOfAddressAreaVariant */
typedef uint8 vMemAccM_SizeOfAddressAreaVariantType;

/**   \brief  value based type definition for vMemAccM_SizeOfSubAddressArea */
typedef uint8 vMemAccM_SizeOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_NumberOfEraseRetriesOfSubAddressArea */
typedef uint8 vMemAccM_NumberOfEraseRetriesOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_NumberOfSectorsOfSubAddressArea */
typedef uint8 vMemAccM_NumberOfSectorsOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_NumberOfWriteRetriesOfSubAddressArea */
typedef uint8 vMemAccM_NumberOfWriteRetriesOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_PageBurstRamAlignmentOfSubAddressArea */
typedef uint8 vMemAccM_PageBurstRamAlignmentOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_PageBurstSizeOfSubAddressArea */
typedef uint16 vMemAccM_PageBurstSizeOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_PageSizeOfSubAddressArea */
typedef uint8 vMemAccM_PageSizeOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_PhysicalStartAddressOfSubAddressArea */
typedef uint32 vMemAccM_PhysicalStartAddressOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_SectorBurstSizeOfSubAddressArea */
typedef uint32 vMemAccM_SectorBurstSizeOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_SectorSizeOfSubAddressArea */
typedef uint16 vMemAccM_SectorSizeOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_UsePageBurstOfSubAddressArea */
typedef boolean vMemAccM_UsePageBurstOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_UseSectorBurstOfSubAddressArea */
typedef boolean vMemAccM_UseSectorBurstOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_VirtualEndAddressOfSubAddressArea */
typedef uint32 vMemAccM_VirtualEndAddressOfSubAddressAreaType;

/**   \brief  value based type definition for vMemAccM_VirtualStartAddressOfSubAddressArea */
typedef uint32 vMemAccM_VirtualStartAddressOfSubAddressAreaType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vMemAccMPCStructTypes  vMemAccM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vMemAccM_AddressArea */
/*! \spec weak type invariant () { 
 * (self.AddressAreaVariantStartIdxOfAddressArea < vMemAccM_GetSizeOfAddressAreaVariant()) &&
 * (self.AddressAreaVariantEndIdxOfAddressArea < vMemAccM_GetSizeOfAddressAreaVariant())
 * } */
typedef struct svMemAccM_AddressAreaType
{
  vMemAccM_AddressAreaVariantEndIdxOfAddressAreaType AddressAreaVariantEndIdxOfAddressArea;  /**< the end index of the 1:n relation pointing to vMemAccM_AddressAreaVariant */
  vMemAccM_AddressAreaVariantLengthOfAddressAreaType AddressAreaVariantLengthOfAddressArea;  /**< the number of relations pointing to vMemAccM_AddressAreaVariant */
  vMemAccM_AddressAreaVariantStartIdxOfAddressAreaType AddressAreaVariantStartIdxOfAddressArea;  /**< the start index of the 1:n relation pointing to vMemAccM_AddressAreaVariant */
  vMemAccM_PriorityOfAddressAreaType PriorityOfAddressArea;  /**< Priority of AddressArea - determines which job is processed first */
  vMemAccM_ReadLengthOfAddressAreaType ReadLengthOfAddressArea;  /**< Maximal length that can be requested of underlying MemDrv for read requests */
} vMemAccM_AddressAreaType;

/**   \brief  type used in vMemAccM_AddressAreaVariant */
/*! \spec weak type invariant () { 
 * (self.SubAddressAreaStartIdxOfAddressAreaVariant < vMemAccM_GetSizeOfSubAddressArea()) &&
 * (self.SubAddressAreaEndIdxOfAddressAreaVariant < vMemAccM_GetSizeOfSubAddressArea())
 * } */
typedef struct svMemAccM_AddressAreaVariantType
{
  vMemAccM_IdOfAddressAreaVariantType IdOfAddressAreaVariant;  /**< Variant identifier. */
  vMemAccM_SubAddressAreaEndIdxOfAddressAreaVariantType SubAddressAreaEndIdxOfAddressAreaVariant;  /**< the end index of the 1:n relation pointing to vMemAccM_SubAddressArea */
  vMemAccM_SubAddressAreaLengthOfAddressAreaVariantType SubAddressAreaLengthOfAddressAreaVariant;  /**< the number of relations pointing to vMemAccM_SubAddressArea */
  vMemAccM_SubAddressAreaStartIdxOfAddressAreaVariantType SubAddressAreaStartIdxOfAddressAreaVariant;  /**< the start index of the 1:n relation pointing to vMemAccM_SubAddressArea */
} vMemAccM_AddressAreaVariantType;

/**   \brief  type used in vMemAccM_SubAddressArea */
typedef struct svMemAccM_SubAddressAreaType
{
  vMemAccM_PhysicalStartAddressOfSubAddressAreaType PhysicalStartAddressOfSubAddressArea;  /**< Physical start address of SubAddressArea */
  vMemAccM_SectorBurstSizeOfSubAddressAreaType SectorBurstSizeOfSubAddressArea;  /**< Size of sector burst in bytes - Zero if not configured */
  vMemAccM_VirtualEndAddressOfSubAddressAreaType VirtualEndAddressOfSubAddressArea;  /**< Virtual end address of SubAddressArea */
  vMemAccM_VirtualStartAddressOfSubAddressAreaType VirtualStartAddressOfSubAddressArea;  /**< Virtual start address of SubAddressArea */
  vMemAccM_PageBurstSizeOfSubAddressAreaType PageBurstSizeOfSubAddressArea;  /**< Size of page burst in bytes - Zero if not configured */
  vMemAccM_SectorSizeOfSubAddressAreaType SectorSizeOfSubAddressArea;  /**< Size of a sector in bytes */
  vMemAccM_UsePageBurstOfSubAddressAreaType UsePageBurstOfSubAddressArea;  /**< vMem page/ write burst shall be used or not. */
  vMemAccM_UseSectorBurstOfSubAddressAreaType UseSectorBurstOfSubAddressArea;  /**< vMem sector/ erase burst shall be used or not. */
  vMemAccM_NumberOfEraseRetriesOfSubAddressAreaType NumberOfEraseRetriesOfSubAddressArea;  /**< Number of erase retries in case of a failed vMem job */
  vMemAccM_NumberOfSectorsOfSubAddressAreaType NumberOfSectorsOfSubAddressArea;  /**< Number of sectors of SubAddressArea */
  vMemAccM_NumberOfWriteRetriesOfSubAddressAreaType NumberOfWriteRetriesOfSubAddressArea;  /**< Number of write retries in case of a failed vMem job */
  vMemAccM_PageBurstRamAlignmentOfSubAddressAreaType PageBurstRamAlignmentOfSubAddressArea;  /**< Alignment for page burst ram - Zero if not configured */
  vMemAccM_PageSizeOfSubAddressAreaType PageSizeOfSubAddressArea;  /**< Size of a page in bytes */
  vMemAccM_ConstvMemApiPtrType vMemApiTableOfSubAddressArea;  /**< Pointer to vMem API table with function pointers */
  vMemAccM_HwIdType HardwareIdOfSubAddressArea;  /**< Numeric identifier of vMem hardware, used in hardware specific requests */
  vMemAccM_vMemInstanceIdType vMemInstanceIdOfSubAddressArea;  /**< Numeric identifier of vMem instance, used as parameter in vMem API */
} vMemAccM_SubAddressAreaType;

/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCRootPointerTypes  vMemAccM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vMemAccM_AddressArea */
typedef P2CONST(vMemAccM_AddressAreaType, TYPEDEF, VMEMACCM_CONST) vMemAccM_AddressAreaPtrType;

/**   \brief  type used to point to vMemAccM_AddressAreaVariant */
typedef P2CONST(vMemAccM_AddressAreaVariantType, TYPEDEF, VMEMACCM_CONST) vMemAccM_AddressAreaVariantPtrType;

/**   \brief  type used to point to vMemAccM_SubAddressArea */
typedef P2CONST(vMemAccM_SubAddressAreaType, TYPEDEF, VMEMACCM_CONST) vMemAccM_SubAddressAreaPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vMemAccMPCRootValueTypes  vMemAccM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vMemAccM_PCConfig */
typedef struct svMemAccM_PCConfigType
{
  uint8 vMemAccM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vMemAccM_PCConfigType;

typedef vMemAccM_PCConfigType vMemAccM_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  MULTI PARTITION GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef uint32 vMemAccM_PublishRequestDataType;
typedef uint32 vMemAccM_NVRAMAccessTokenType;
typedef P2VAR(vMemAccM_NVRAMAccessTokenType, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_NVRAMAccessTokenPtrType;
typedef CONSTP2CONST(vMemAccM_NVRAMAccessTokenType, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_NVRAMAccessTokenConstPtrToConstType;

/* Always use uint32 to access the shared RAM. */
typedef uint32 vMemAccM_PublishPriorityType;
#if (VMEMACCM_PARTITION_USECASE == VMEMACCM_MULTI_PARTITION_MULTI_ACCESSORS)
typedef struct
{
  vMemAccM_PublishPriorityType Priority; /*!< Published priority the master shall use to synchronize the partitions. */
} vMemAccM_PartitionPublishRequestType;
#else
typedef uint32 vMemAccM_PublishJobType;
typedef uint32 vMemAccM_PublishAdressAreaIdType;
typedef uint32 vMemAccM_PublishAddressType;
typedef uint32 vMemAccM_PublishLengthType;
typedef uint32 vMemAccM_PublishJobResultType;

typedef P2VAR(uint32, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_PublishRequestDataPtrType;
typedef P2CONST(uint32, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_PublishRequestDataConstPtrType;

typedef struct
{
  vMemAccM_PublishPriorityType Priority; /*!< Published priority the master shall use to synchronize the partitions. */
  vMemAccM_PublishJobType JobType; /*!< Requested job type (write, read, etc.). */
  vMemAccM_PublishAdressAreaIdType AddressAreaId; /*!< Address area identifier. */
  vMemAccM_PublishAddressType Address; /*!< Virtual start address of the request. */
  vMemAccM_PublishRequestDataPtrType Data; /*!< Data to be written or pointer to write the read data to. */
  vMemAccM_PublishLengthType Length; /*!< Length of the published Data. */
  vMemAccM_PublishJobResultType Result; /*!< Signals to master "ready for processing" and signals back to partition "processing done". */
} vMemAccM_PartitionPublishRequestType;
#endif

typedef P2VAR(vMemAccM_PartitionPublishRequestType, AUTOMATIC, VMEMACCM_APPL_VAR) vMemAccM_PartitionPublishRequestPtrType;

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  vMemAccM_AddressArea
**********************************************************************************************************************/
/** 
  \var    vMemAccM_AddressArea
  \details
  Element                       Description
  AddressAreaVariantEndIdx      the end index of the 1:n relation pointing to vMemAccM_AddressAreaVariant
  AddressAreaVariantLength      the number of relations pointing to vMemAccM_AddressAreaVariant
  AddressAreaVariantStartIdx    the start index of the 1:n relation pointing to vMemAccM_AddressAreaVariant
  Priority                      Priority of AddressArea - determines which job is processed first
  ReadLength                    Maximal length that can be requested of underlying MemDrv for read requests
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMemAccM_AddressAreaType, VMEMACCM_CONST) vMemAccM_AddressArea[1];
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMemAccM_AddressAreaVariant
**********************************************************************************************************************/
/** 
  \var    vMemAccM_AddressAreaVariant
  \details
  Element                   Description
  Id                        Variant identifier.
  SubAddressAreaEndIdx      the end index of the 1:n relation pointing to vMemAccM_SubAddressArea
  SubAddressAreaLength      the number of relations pointing to vMemAccM_SubAddressArea
  SubAddressAreaStartIdx    the start index of the 1:n relation pointing to vMemAccM_SubAddressArea
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMemAccM_AddressAreaVariantType, VMEMACCM_CONST) vMemAccM_AddressAreaVariant[1];
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMemAccM_SubAddressArea
**********************************************************************************************************************/
/** 
  \var    vMemAccM_SubAddressArea
  \details
  Element                  Description
  PhysicalStartAddress     Physical start address of SubAddressArea
  SectorBurstSize          Size of sector burst in bytes - Zero if not configured
  VirtualEndAddress        Virtual end address of SubAddressArea
  VirtualStartAddress      Virtual start address of SubAddressArea
  PageBurstSize            Size of page burst in bytes - Zero if not configured
  SectorSize               Size of a sector in bytes
  UsePageBurst             vMem page/ write burst shall be used or not.
  UseSectorBurst           vMem sector/ erase burst shall be used or not.
  NumberOfEraseRetries     Number of erase retries in case of a failed vMem job
  NumberOfSectors          Number of sectors of SubAddressArea
  NumberOfWriteRetries     Number of write retries in case of a failed vMem job
  PageBurstRamAlignment    Alignment for page burst ram - Zero if not configured
  PageSize                 Size of a page in bytes
  vMemApiTable             Pointer to vMem API table with function pointers
  HardwareId               Numeric identifier of vMem hardware, used in hardware specific requests
  vMemInstanceId           Numeric identifier of vMem instance, used as parameter in vMem API
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vMemAccM_SubAddressAreaType, VMEMACCM_CONST) vMemAccM_SubAddressArea[1];
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES: MULTI PARTITION USE CASE: PARTITION LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES: MULTI PARTITION USE CASE: MULTI PARTITION GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES: MULTI PARTITION USE CASE: PARTITION LOCAL DATA
**********************************************************************************************************************/
/* Master variables, visible only for multi partition master, local RAM. */
#define VMEMACCM_START_SEC_VAR_INIT_32BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */ 



#define VMEMACCM_STOP_SEC_VAR_INIT_32BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */



#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

#define VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/* Each partition accesses the NV RAM access token via a pointer to abstract from actual symbol/ address. */
/* Each partition accesses its publish request variable via pointer to abstract from actual symbol/ address. */



#define VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES: MULTI PARTITION USE CASE: MULTI PARTITION GLOBAL DATA
**********************************************************************************************************************/
/* These declarations do not need a memory mapping section, they do not declare any variable, they
 * are just linker symbols == addresses. */
/* Multi partition slave only: 
 * - needs an extern declaration of the token, if a symbol was configured,
 * - needs an extern declaration of the variable, if a symbol was configured. */


/* Master variables published to all partitions. */


#endif  /* VMEMACCM_INTCFG_H */
/**********************************************************************************************************************
  END OF FILE: vMemAccM_IntCfg.h
**********************************************************************************************************************/

