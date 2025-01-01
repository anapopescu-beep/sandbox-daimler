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
 *            Module: vHsmUpd_Ext
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vHsmUpd_Ext_Cfg.h
 *   Generation Time: 2022-05-23 14:13:54
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


#if !defined (VHSMUPD_EXT_CFG_H)
#define VHSMUPD_EXT_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef VHSMUPD_EXT_USE_DUMMY_STATEMENT
#define VHSMUPD_EXT_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSMUPD_EXT_DUMMY_STATEMENT
#define VHSMUPD_EXT_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSMUPD_EXT_DUMMY_STATEMENT_CONST
#define VHSMUPD_EXT_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSMUPD_EXT_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VHSMUPD_EXT_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VHSMUPD_EXT_ATOMIC_VARIABLE_ACCESS
#define VHSMUPD_EXT_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VHSMUPD_EXT_PROCESSOR_TC397X_STEPB
#define VHSMUPD_EXT_PROCESSOR_TC397X_STEPB
#endif
#ifndef VHSMUPD_EXT_COMP_TASKING
#define VHSMUPD_EXT_COMP_TASKING
#endif
#ifndef VHSMUPD_EXT_GEN_GENERATOR_MSR
#define VHSMUPD_EXT_GEN_GENERATOR_MSR
#endif
#ifndef VHSMUPD_EXT_CPUTYPE_BITORDER_LSB2MSB
#define VHSMUPD_EXT_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VHSMUPD_EXT_CONFIGURATION_VARIANT_PRECOMPILE
#define VHSMUPD_EXT_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VHSMUPD_EXT_CONFIGURATION_VARIANT_LINKTIME
#define VHSMUPD_EXT_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VHSMUPD_EXT_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VHSMUPD_EXT_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef VHSMUPD_EXT_CONFIGURATION_VARIANT
#define VHSMUPD_EXT_CONFIGURATION_VARIANT VHSMUPD_EXT_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef VHSMUPD_EXT_POSTBUILD_VARIANT_SUPPORT
#define VHSMUPD_EXT_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Microsar Define Block for Boolean and Integers */
#define VHSMUPD_EXT_RETRY_COUNTER                                                                   0u 
#define VHSMUPD_EXT_ENABLE_USER_COMPARE_MECHANISM                                                   STD_ON 
#define VHSMUPD_EXT_DECRYPTION_RAM_BUFFER_SIZE                                                      256u 
#define VHSMUPD_EXT_PLATFORM_PAGESIZE                                                               32uL 
#define VHSMUPD_EXT_HEADER_LOCATION_A                                                               0x800D3EC0uL 
#define VHSMUPD_EXT_HEADER_LOCATION_B                                                               0x800D3EC0uL 
#define VHSMUPD_EXT_UPDATE_HEADER_FIX_ADDRESS                                                       STD_ON 
#define VHSMUPD_EXT_FIRST_HEADER_ADDRESS                                                            0x00000000uL 
#define VHSMUPD_EXT_NUMBER_OF_POSSIBLE_HEADERS                                                      1uL 
#define VHSMUPD_EXT_UPDATE_HEADER_VARIABLE_ADDRESS                                                  STD_OFF 
#define VHSMUPD_EXT_IPC_HSM_TO_HOST                                                                 0xF0040034uL 
#define VHSMUPD_EXT_IPC_HOST_TO_HSM                                                                 0xF0040038uL 
#define VHSMUPD_EXT_IPC_WAIT_MASK                                                                   0x80000000uL 

/* Symbolic Name Define Block */
#define vHsmUpd_ExtConf_vHsmUpd_ExtPartitions_Partition_MainActive                                  0u 
#define vHsmUpd_ExtConf_vHsmUpd_ExtModules_vHsmUpd_ExtModule_vHsmFw                                 0u 
#define vHsmUpd_ExtConf_vHsmUpd_ExtRegion_vHsmUpd_ExtRegion_vHsmFw                                  0u 
#define vHsmUpd_ExtConf_vHsmUpd_ExtModuleType_vHsmUpd_ExtvHsmFirmware                               0u 
#define vHsmUpd_ExtConf_vHsmUpd_ExtModuleType_vHsmUpd_ExtvHsmUpd                                    1u 
#define vHsmUpd_ExtConf_vHsmUpd_ExtPartitionType_vHsmUpd_ExtMainActive                              0u 
#define vHsmUpd_ExtConf_vHsmUpd_ExtPartitionType_vHsmUpd_ExtAlternativeActive                       1u 



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpd_ExtPCDataSwitches  vHsmUpd_Ext Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VHSMUPD_EXT_DECRYPTIONRAMBUFFERSIZEOFGENERAL                                                STD_ON
#define VHSMUPD_EXT_ENABLEUSERCOMPAREMECHANISMOFGENERAL                                             STD_ON
#define VHSMUPD_EXT_EXPECTEDCOMPATIBILITYVERSION                                                    STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSMUPD_EXT_FINALMAGICNUMBER                                                                STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VHSMUPD_EXT_FIRSTHEADERADDRESSOFUPDATEHEADERVARIABLEADDRESS                                 STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_FirstHeaderAddressOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define VHSMUPD_EXT_FWSTARTOFGENERAL                                                                STD_ON
#define VHSMUPD_EXT_GENERATORCOMPATIBILITYVERSION                                                   STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSMUPD_EXT_HEADERLOCATION_AOFUPDATEHEADERFIXADDRESS                                        STD_ON
#define VHSMUPD_EXT_HEADERLOCATION_BOFUPDATEHEADERFIXADDRESS                                        STD_ON
#define VHSMUPD_EXT_HOSTTOHSMOFIPC                                                                  STD_ON
#define VHSMUPD_EXT_HSMTOHOSTOFIPC                                                                  STD_ON
#define VHSMUPD_EXT_INITDATAHASHCODE                                                                STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VHSMUPD_EXT_MODULETYPE                                                                      STD_ON
#define VHSMUPD_EXT_IDOFMODULETYPE                                                                  STD_ON
#define VHSMUPD_EXT_MODULES                                                                         STD_ON
#define VHSMUPD_EXT_MODULEIDOFMODULES                                                               STD_ON
#define VHSMUPD_EXT_MODULETYPEREFOFMODULES                                                          STD_ON
#define VHSMUPD_EXT_MODULETYPEREFVALIDOFMODULES                                                     STD_ON
#define VHSMUPD_EXT_PARTITIONGROUPREFIDXOFMODULES                                                   STD_ON
#define VHSMUPD_EXT_NUMBEROFPOSSIBLEHEADERSOFUPDATEHEADERVARIABLEADDRESS                            STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_NumberOfPossibleHeadersOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define VHSMUPD_EXT_PARTITIONGROUP                                                                  STD_ON
#define VHSMUPD_EXT_PARTITIONREFINDENDIDXOFPARTITIONGROUP                                           STD_ON
#define VHSMUPD_EXT_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP                                         STD_ON
#define VHSMUPD_EXT_PARTITIONREFINDUSEDOFPARTITIONGROUP                                             STD_ON
#define VHSMUPD_EXT_PARTITIONREF                                                                    STD_ON
#define VHSMUPD_EXT_PARTITIONREFIND                                                                 STD_ON
#define VHSMUPD_EXT_PARTITIONTYPE                                                                   STD_ON
#define VHSMUPD_EXT_PARTITONTYPEIDOFPARTITIONTYPE                                                   STD_ON
#define VHSMUPD_EXT_PARTITIONS                                                                      STD_ON
#define VHSMUPD_EXT_ADDRESSAREAREFOFPARTITIONS                                                      STD_ON
#define VHSMUPD_EXT_PARTITIONIDOFPARTITIONS                                                         STD_ON
#define VHSMUPD_EXT_PARTITIONTYPEREFIDXOFPARTITIONS                                                 STD_ON
#define VHSMUPD_EXT_PARTITIONTYPEREFUSEDOFPARTITIONS                                                STD_ON
#define VHSMUPD_EXT_PLATFORMPAGESIZEOFGENERAL                                                       STD_ON
#define VHSMUPD_EXT_REGION                                                                          STD_ON
#define VHSMUPD_EXT_IDOFREGION                                                                      STD_ON
#define VHSMUPD_EXT_LENGTHOFREGION                                                                  STD_ON
#define VHSMUPD_EXT_MODULEREFOFREGION                                                               STD_ON
#define VHSMUPD_EXT_SEGMENTENDIDXOFREGION                                                           STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentEndIdx' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define VHSMUPD_EXT_SEGMENTSTARTIDXOFREGION                                                         STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentStartIdx' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define VHSMUPD_EXT_SEGMENTUSEDOFREGION                                                             STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentUsed' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define VHSMUPD_EXT_STARTADDRESSOFREGION                                                            STD_ON
#define VHSMUPD_EXT_RETRYCOUNTEROFGENERAL                                                           STD_ON
#define VHSMUPD_EXT_SEGMENT                                                                         STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_Segment' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSMUPD_EXT_LENGTHOFSEGMENT                                                                 STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_Segment.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSMUPD_EXT_STARTADDRESSOFSEGMENT                                                           STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_Segment.StartAddress' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSMUPD_EXT_SIZEOFMODULETYPE                                                                STD_ON
#define VHSMUPD_EXT_SIZEOFMODULES                                                                   STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONGROUP                                                            STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONREF                                                              STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONREFIND                                                           STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONTYPE                                                             STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONS                                                                STD_ON
#define VHSMUPD_EXT_SIZEOFREGION                                                                    STD_ON
#define VHSMUPD_EXT_WAITMASKOFIPC                                                                   STD_ON
#define VHSMUPD_EXT_PCCONFIG                                                                        STD_ON
#define VHSMUPD_EXT_DECRYPTIONRAMBUFFERSIZEOFGENERALOFPCCONFIG                                      STD_ON
#define VHSMUPD_EXT_ENABLEUSERCOMPAREMECHANISMOFGENERALOFPCCONFIG                                   STD_ON
#define VHSMUPD_EXT_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSMUPD_EXT_FINALMAGICNUMBEROFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VHSMUPD_EXT_FIRSTHEADERADDRESSOFUPDATEHEADERVARIABLEADDRESSOFPCCONFIG                       STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.FirstHeaderAddressOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define VHSMUPD_EXT_FWSTARTOFGENERALOFPCCONFIG                                                      STD_ON
#define VHSMUPD_EXT_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                         STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSMUPD_EXT_HEADERLOCATION_AOFUPDATEHEADERFIXADDRESSOFPCCONFIG                              STD_ON
#define VHSMUPD_EXT_HEADERLOCATION_BOFUPDATEHEADERFIXADDRESSOFPCCONFIG                              STD_ON
#define VHSMUPD_EXT_HOSTTOHSMOFIPCOFPCCONFIG                                                        STD_ON
#define VHSMUPD_EXT_HSMTOHOSTOFIPCOFPCCONFIG                                                        STD_ON
#define VHSMUPD_EXT_INITDATAHASHCODEOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VHSMUPD_EXT_MODULETYPEOFPCCONFIG                                                            STD_ON
#define VHSMUPD_EXT_MODULESOFPCCONFIG                                                               STD_ON
#define VHSMUPD_EXT_NUMBEROFPOSSIBLEHEADERSOFUPDATEHEADERVARIABLEADDRESSOFPCCONFIG                  STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.NumberOfPossibleHeadersOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define VHSMUPD_EXT_PARTITIONGROUPOFPCCONFIG                                                        STD_ON
#define VHSMUPD_EXT_PARTITIONREFINDOFPCCONFIG                                                       STD_ON
#define VHSMUPD_EXT_PARTITIONREFOFPCCONFIG                                                          STD_ON
#define VHSMUPD_EXT_PARTITIONTYPEOFPCCONFIG                                                         STD_ON
#define VHSMUPD_EXT_PARTITIONSOFPCCONFIG                                                            STD_ON
#define VHSMUPD_EXT_PLATFORMPAGESIZEOFGENERALOFPCCONFIG                                             STD_ON
#define VHSMUPD_EXT_REGIONOFPCCONFIG                                                                STD_ON
#define VHSMUPD_EXT_RETRYCOUNTEROFGENERALOFPCCONFIG                                                 STD_ON
#define VHSMUPD_EXT_SIZEOFMODULETYPEOFPCCONFIG                                                      STD_ON
#define VHSMUPD_EXT_SIZEOFMODULESOFPCCONFIG                                                         STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONGROUPOFPCCONFIG                                                  STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONREFINDOFPCCONFIG                                                 STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONREFOFPCCONFIG                                                    STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONTYPEOFPCCONFIG                                                   STD_ON
#define VHSMUPD_EXT_SIZEOFPARTITIONSOFPCCONFIG                                                      STD_ON
#define VHSMUPD_EXT_SIZEOFREGIONOFPCCONFIG                                                          STD_ON
#define VHSMUPD_EXT_WAITMASKOFIPCOFPCCONFIG                                                         STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCNoReferenceDefines  vHsmUpd_Ext No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define VHSMUPD_EXT_NO_PARTITIONREFINDENDIDXOFPARTITIONGROUP                                        255u
#define VHSMUPD_EXT_NO_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP                                      255u
#define VHSMUPD_EXT_NO_PARTITIONTYPEREFIDXOFPARTITIONS                                              255u
#define VHSMUPD_EXT_NO_SEGMENTENDIDXOFREGION                                                        255u
#define VHSMUPD_EXT_NO_SEGMENTSTARTIDXOFREGION                                                      255u
#define VHSMUPD_EXT_NO_EXPECTEDCOMPATIBILITYVERSION                                                 65535u
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCIsReducedToDefineDefines  vHsmUpd_Ext Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VHSMUPD_EXT_ISDEF_IDOFMODULETYPE                                                            STD_OFF
#define VHSMUPD_EXT_ISDEF_MODULEIDOFMODULES                                                         STD_OFF
#define VHSMUPD_EXT_ISDEF_MODULETYPEREFOFMODULES                                                    STD_OFF
#define VHSMUPD_EXT_ISDEF_MODULETYPEREFVALIDOFMODULES                                               STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONGROUPREFIDXOFMODULES                                             STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONREFINDENDIDXOFPARTITIONGROUP                                     STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP                                   STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONREFINDUSEDOFPARTITIONGROUP                                       STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONREF                                                              STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONREFIND                                                           STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITONTYPEIDOFPARTITIONTYPE                                             STD_OFF
#define VHSMUPD_EXT_ISDEF_ADDRESSAREAREFOFPARTITIONS                                                STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONIDOFPARTITIONS                                                   STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONTYPEREFIDXOFPARTITIONS                                           STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONTYPEREFUSEDOFPARTITIONS                                          STD_OFF
#define VHSMUPD_EXT_ISDEF_IDOFREGION                                                                STD_OFF
#define VHSMUPD_EXT_ISDEF_LENGTHOFREGION                                                            STD_OFF
#define VHSMUPD_EXT_ISDEF_MODULEREFOFREGION                                                         STD_OFF
#define VHSMUPD_EXT_ISDEF_SEGMENTENDIDXOFREGION                                                     STD_OFF
#define VHSMUPD_EXT_ISDEF_SEGMENTSTARTIDXOFREGION                                                   STD_OFF
#define VHSMUPD_EXT_ISDEF_SEGMENTUSEDOFREGION                                                       STD_OFF
#define VHSMUPD_EXT_ISDEF_STARTADDRESSOFREGION                                                      STD_OFF
#define VHSMUPD_EXT_ISDEF_LENGTHOFSEGMENT                                                           STD_OFF
#define VHSMUPD_EXT_ISDEF_STARTADDRESSOFSEGMENT                                                     STD_OFF
#define VHSMUPD_EXT_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                    STD_OFF
#define VHSMUPD_EXT_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                STD_OFF
#define VHSMUPD_EXT_ISDEF_FIRSTHEADERADDRESSOFUPDATEHEADERVARIABLEADDRESSOFPCCONFIG                 STD_OFF
#define VHSMUPD_EXT_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                   STD_OFF
#define VHSMUPD_EXT_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                STD_OFF
#define VHSMUPD_EXT_ISDEF_MODULETYPEOFPCCONFIG                                                      STD_ON
#define VHSMUPD_EXT_ISDEF_MODULESOFPCCONFIG                                                         STD_ON
#define VHSMUPD_EXT_ISDEF_NUMBEROFPOSSIBLEHEADERSOFUPDATEHEADERVARIABLEADDRESSOFPCCONFIG            STD_OFF
#define VHSMUPD_EXT_ISDEF_PARTITIONGROUPOFPCCONFIG                                                  STD_ON
#define VHSMUPD_EXT_ISDEF_PARTITIONREFINDOFPCCONFIG                                                 STD_ON
#define VHSMUPD_EXT_ISDEF_PARTITIONREFOFPCCONFIG                                                    STD_ON
#define VHSMUPD_EXT_ISDEF_PARTITIONTYPEOFPCCONFIG                                                   STD_ON
#define VHSMUPD_EXT_ISDEF_PARTITIONSOFPCCONFIG                                                      STD_ON
#define VHSMUPD_EXT_ISDEF_REGIONOFPCCONFIG                                                          STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCEqualsAlwaysToDefines  vHsmUpd_Ext Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VHSMUPD_EXT_EQ2_IDOFMODULETYPE                                                              
#define VHSMUPD_EXT_EQ2_MODULEIDOFMODULES                                                           
#define VHSMUPD_EXT_EQ2_MODULETYPEREFOFMODULES                                                      
#define VHSMUPD_EXT_EQ2_MODULETYPEREFVALIDOFMODULES                                                 
#define VHSMUPD_EXT_EQ2_PARTITIONGROUPREFIDXOFMODULES                                               
#define VHSMUPD_EXT_EQ2_PARTITIONREFINDENDIDXOFPARTITIONGROUP                                       
#define VHSMUPD_EXT_EQ2_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP                                     
#define VHSMUPD_EXT_EQ2_PARTITIONREFINDUSEDOFPARTITIONGROUP                                         
#define VHSMUPD_EXT_EQ2_PARTITIONREF                                                                
#define VHSMUPD_EXT_EQ2_PARTITIONREFIND                                                             
#define VHSMUPD_EXT_EQ2_PARTITONTYPEIDOFPARTITIONTYPE                                               
#define VHSMUPD_EXT_EQ2_ADDRESSAREAREFOFPARTITIONS                                                  
#define VHSMUPD_EXT_EQ2_PARTITIONIDOFPARTITIONS                                                     
#define VHSMUPD_EXT_EQ2_PARTITIONTYPEREFIDXOFPARTITIONS                                             
#define VHSMUPD_EXT_EQ2_PARTITIONTYPEREFUSEDOFPARTITIONS                                            
#define VHSMUPD_EXT_EQ2_IDOFREGION                                                                  
#define VHSMUPD_EXT_EQ2_LENGTHOFREGION                                                              
#define VHSMUPD_EXT_EQ2_MODULEREFOFREGION                                                           
#define VHSMUPD_EXT_EQ2_SEGMENTENDIDXOFREGION                                                       
#define VHSMUPD_EXT_EQ2_SEGMENTSTARTIDXOFREGION                                                     
#define VHSMUPD_EXT_EQ2_SEGMENTUSEDOFREGION                                                         
#define VHSMUPD_EXT_EQ2_STARTADDRESSOFREGION                                                        
#define VHSMUPD_EXT_EQ2_LENGTHOFSEGMENT                                                             
#define VHSMUPD_EXT_EQ2_STARTADDRESSOFSEGMENT                                                       
#define VHSMUPD_EXT_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                      
#define VHSMUPD_EXT_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                  
#define VHSMUPD_EXT_EQ2_FIRSTHEADERADDRESSOFUPDATEHEADERVARIABLEADDRESSOFPCCONFIG                   
#define VHSMUPD_EXT_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                     
#define VHSMUPD_EXT_EQ2_INITDATAHASHCODEOFPCCONFIG                                                  
#define VHSMUPD_EXT_EQ2_MODULETYPEOFPCCONFIG                                                        vHsmUpd_Ext_ModuleType
#define VHSMUPD_EXT_EQ2_MODULESOFPCCONFIG                                                           vHsmUpd_Ext_Modules
#define VHSMUPD_EXT_EQ2_NUMBEROFPOSSIBLEHEADERSOFUPDATEHEADERVARIABLEADDRESSOFPCCONFIG              
#define VHSMUPD_EXT_EQ2_PARTITIONGROUPOFPCCONFIG                                                    vHsmUpd_Ext_PartitionGroup
#define VHSMUPD_EXT_EQ2_PARTITIONREFINDOFPCCONFIG                                                   vHsmUpd_Ext_PartitionRefInd
#define VHSMUPD_EXT_EQ2_PARTITIONREFOFPCCONFIG                                                      vHsmUpd_Ext_PartitionRef
#define VHSMUPD_EXT_EQ2_PARTITIONTYPEOFPCCONFIG                                                     vHsmUpd_Ext_PartitionType
#define VHSMUPD_EXT_EQ2_PARTITIONSOFPCCONFIG                                                        vHsmUpd_Ext_Partitions
#define VHSMUPD_EXT_EQ2_REGIONOFPCCONFIG                                                            vHsmUpd_Ext_Region
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCSymbolicInitializationPointers  vHsmUpd_Ext Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vHsmUpd_Ext_Config_Ptr                                                                      NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vHsmUpd_Ext' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCInitializationSymbols  vHsmUpd_Ext Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vHsmUpd_Ext_Config                                                                          NULL_PTR  /**< symbolic identifier which could be used to initialize 'vHsmUpd_Ext */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCGeneral  vHsmUpd_Ext General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VHSMUPD_EXT_CHECK_INIT_POINTER                                                              STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VHSMUPD_EXT_FINAL_MAGIC_NUMBER                                                              0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vHsmUpd_Ext */
#define VHSMUPD_EXT_INDIVIDUAL_POSTBUILD                                                            STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vHsmUpd_Ext' is not configured to be postbuild capable. */
#define VHSMUPD_EXT_INIT_DATA                                                                       VHSMUPD_EXT_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VHSMUPD_EXT_INIT_DATA_HASH_CODE                                                             422300611  /**< the precompile constant to validate the initialization structure at initialization time of vHsmUpd_Ext with a hashcode. The seed value is '0xFF1Eu' */
#define VHSMUPD_EXT_USE_ECUM_BSW_ERROR_HOOK                                                         STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VHSMUPD_EXT_USE_INIT_POINTER                                                                STD_OFF  /**< STD_ON if the init pointer vHsmUpd_Ext shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpd_ExtPBDataSwitches  vHsmUpd_Ext Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VHSMUPD_EXT_PBCONFIG                                                                        STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VHSMUPD_EXT_LTCONFIGIDXOFPBCONFIG                                                           STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VHSMUPD_EXT_PCCONFIGIDXOFPBCONFIG                                                           STD_OFF  /**< Deactivateable: 'vHsmUpd_Ext_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPBIsReducedToDefineDefines  vHsmUpd_Ext Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VHSMUPD_EXT_ISDEF_LTCONFIGIDXOFPBCONFIG                                                     STD_OFF
#define VHSMUPD_EXT_ISDEF_PCCONFIGIDXOFPBCONFIG                                                     STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPBEqualsAlwaysToDefines  vHsmUpd_Ext Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VHSMUPD_EXT_EQ2_LTCONFIGIDXOFPBCONFIG                                                       
#define VHSMUPD_EXT_EQ2_PCCONFIGIDXOFPBCONFIG                                                       
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
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
  \defgroup  vHsmUpd_ExtPCGetRootDataMacros  vHsmUpd_Ext Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vHsmUpd_Ext_GetExpectedCompatibilityVersionOfPCConfig()                                       /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_Ext_GetFinalMagicNumberOfPCConfig()                                                   /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_Ext_GetFirstHeaderAddressOfUpdateHeaderVariableAddressOfPCConfig()                    /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.FirstHeaderAddressOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define vHsmUpd_Ext_GetGeneratorCompatibilityVersionOfPCConfig()                                      /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_Ext_GetInitDataHashCodeOfPCConfig()                                                   /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_Ext_GetNumberOfPossibleHeadersOfUpdateHeaderVariableAddressOfPCConfig()               /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.NumberOfPossibleHeadersOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCGetConstantDuplicatedRootDataMacros  vHsmUpd_Ext Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vHsmUpd_Ext_GetDecryptionRamBufferSizeOfGeneralOfPCConfig()                                 256u
#define vHsmUpd_Ext_IsEnableUserCompareMechanismOfGeneralOfPCConfig()                               (((TRUE)) != FALSE)
#define vHsmUpd_Ext_GetFwStartOfGeneralOfPCConfig()                                                 vHsmUpd_FirmwareStart
#define vHsmUpd_Ext_GetHeaderLocation_AOfUpdateHeaderFixAddressOfPCConfig()                         0x800D3EC0u
#define vHsmUpd_Ext_GetHeaderLocation_BOfUpdateHeaderFixAddressOfPCConfig()                         0x800D3EC0u
#define vHsmUpd_Ext_GetHostToHsmOfIpcOfPCConfig()                                                   0xF0040038u
#define vHsmUpd_Ext_GetHsmToHostOfIpcOfPCConfig()                                                   0xF0040034u
#define vHsmUpd_Ext_GetModuleTypeOfPCConfig()                                                       vHsmUpd_Ext_ModuleType  /**< the pointer to vHsmUpd_Ext_ModuleType */
#define vHsmUpd_Ext_GetModulesOfPCConfig()                                                          vHsmUpd_Ext_Modules  /**< the pointer to vHsmUpd_Ext_Modules */
#define vHsmUpd_Ext_GetPartitionGroupOfPCConfig()                                                   vHsmUpd_Ext_PartitionGroup  /**< the pointer to vHsmUpd_Ext_PartitionGroup */
#define vHsmUpd_Ext_GetPartitionRefIndOfPCConfig()                                                  vHsmUpd_Ext_PartitionRefInd  /**< the pointer to vHsmUpd_Ext_PartitionRefInd */
#define vHsmUpd_Ext_GetPartitionRefOfPCConfig()                                                     vHsmUpd_Ext_PartitionRef  /**< the pointer to vHsmUpd_Ext_PartitionRef */
#define vHsmUpd_Ext_GetPartitionTypeOfPCConfig()                                                    vHsmUpd_Ext_PartitionType  /**< the pointer to vHsmUpd_Ext_PartitionType */
#define vHsmUpd_Ext_GetPartitionsOfPCConfig()                                                       vHsmUpd_Ext_Partitions  /**< the pointer to vHsmUpd_Ext_Partitions */
#define vHsmUpd_Ext_GetPlatformPagesizeOfGeneralOfPCConfig()                                        32u
#define vHsmUpd_Ext_GetRegionOfPCConfig()                                                           vHsmUpd_Ext_Region  /**< the pointer to vHsmUpd_Ext_Region */
#define vHsmUpd_Ext_GetRetryCounterOfGeneralOfPCConfig()                                            0u
#define vHsmUpd_Ext_GetSizeOfModuleTypeOfPCConfig()                                                 2u  /**< the number of accomplishable value elements in vHsmUpd_Ext_ModuleType */
#define vHsmUpd_Ext_GetSizeOfModulesOfPCConfig()                                                    1u  /**< the number of accomplishable value elements in vHsmUpd_Ext_Modules */
#define vHsmUpd_Ext_GetSizeOfPartitionGroupOfPCConfig()                                             1u  /**< the number of accomplishable value elements in vHsmUpd_Ext_PartitionGroup */
#define vHsmUpd_Ext_GetSizeOfPartitionRefIndOfPCConfig()                                            1u  /**< the number of accomplishable value elements in vHsmUpd_Ext_PartitionRefInd */
#define vHsmUpd_Ext_GetSizeOfPartitionRefOfPCConfig()                                               1u  /**< the number of accomplishable value elements in vHsmUpd_Ext_PartitionRef */
#define vHsmUpd_Ext_GetSizeOfPartitionTypeOfPCConfig()                                              2u  /**< the number of accomplishable value elements in vHsmUpd_Ext_PartitionType */
#define vHsmUpd_Ext_GetSizeOfPartitionsOfPCConfig()                                                 1u  /**< the number of accomplishable value elements in vHsmUpd_Ext_Partitions */
#define vHsmUpd_Ext_GetSizeOfRegionOfPCConfig()                                                     1u  /**< the number of accomplishable value elements in vHsmUpd_Ext_Region */
#define vHsmUpd_Ext_GetWaitMaskOfIpcOfPCConfig()                                                    0x80000000u
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCGetDataMacros  vHsmUpd_Ext Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vHsmUpd_Ext_GetIdOfModuleType(Index)                                                        (vHsmUpd_Ext_GetModuleTypeOfPCConfig()[(Index)].IdOfModuleType)
#define vHsmUpd_Ext_GetModuleIdOfModules(Index)                                                     (vHsmUpd_Ext_GetModulesOfPCConfig()[(Index)].ModuleIdOfModules)
#define vHsmUpd_Ext_GetModuleTypeRefOfModules(Index)                                                (vHsmUpd_Ext_GetModulesOfPCConfig()[(Index)].ModuleTypeRefOfModules)
#define vHsmUpd_Ext_IsModuleTypeRefValidOfModules(Index)                                            ((vHsmUpd_Ext_GetModulesOfPCConfig()[(Index)].ModuleTypeRefValidOfModules) != FALSE)
#define vHsmUpd_Ext_GetPartitionGroupRefIdxOfModules(Index)                                         (vHsmUpd_Ext_GetModulesOfPCConfig()[(Index)].PartitionGroupRefIdxOfModules)
#define vHsmUpd_Ext_GetPartitionRefIndEndIdxOfPartitionGroup(Index)                                 (vHsmUpd_Ext_GetPartitionGroupOfPCConfig()[(Index)].PartitionRefIndEndIdxOfPartitionGroup)
#define vHsmUpd_Ext_GetPartitionRefIndStartIdxOfPartitionGroup(Index)                               (vHsmUpd_Ext_GetPartitionGroupOfPCConfig()[(Index)].PartitionRefIndStartIdxOfPartitionGroup)
#define vHsmUpd_Ext_GetPartitionRef(Index)                                                          (vHsmUpd_Ext_GetPartitionRefOfPCConfig()[(Index)])
#define vHsmUpd_Ext_GetPartitionRefInd(Index)                                                       (vHsmUpd_Ext_GetPartitionRefIndOfPCConfig()[(Index)])
#define vHsmUpd_Ext_GetPartitonTypeIdOfPartitionType(Index)                                         (vHsmUpd_Ext_GetPartitionTypeOfPCConfig()[(Index)].PartitonTypeIdOfPartitionType)
#define vHsmUpd_Ext_GetAddressAreaRefOfPartitions(Index)                                            (vHsmUpd_Ext_GetPartitionsOfPCConfig()[(Index)].AddressAreaRefOfPartitions)
#define vHsmUpd_Ext_GetPartitionIdOfPartitions(Index)                                               (vHsmUpd_Ext_GetPartitionsOfPCConfig()[(Index)].PartitionIdOfPartitions)
#define vHsmUpd_Ext_GetPartitionTypeRefIdxOfPartitions(Index)                                       (vHsmUpd_Ext_GetPartitionsOfPCConfig()[(Index)].PartitionTypeRefIdxOfPartitions)
#define vHsmUpd_Ext_GetIdOfRegion(Index)                                                            (vHsmUpd_Ext_GetRegionOfPCConfig()[(Index)].IdOfRegion)
#define vHsmUpd_Ext_GetLengthOfRegion(Index)                                                        (vHsmUpd_Ext_GetRegionOfPCConfig()[(Index)].LengthOfRegion)
#define vHsmUpd_Ext_GetModuleRefOfRegion(Index)                                                     (vHsmUpd_Ext_GetRegionOfPCConfig()[(Index)].ModuleRefOfRegion)
#define vHsmUpd_Ext_GetSegmentEndIdxOfRegion(Index)                                                   /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentEndIdx' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define vHsmUpd_Ext_GetSegmentStartIdxOfRegion(Index)                                                 /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentStartIdx' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define vHsmUpd_Ext_IsSegmentUsedOfRegion(Index)                                                      /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentUsed' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define vHsmUpd_Ext_GetStartAddressOfRegion(Index)                                                  (vHsmUpd_Ext_GetRegionOfPCConfig()[(Index)].StartAddressOfRegion)
#define vHsmUpd_Ext_GetLengthOfSegment(Index)                                                         /**< Deactivateable: 'vHsmUpd_Ext_Segment.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsmUpd_Ext_GetStartAddressOfSegment(Index)                                                   /**< Deactivateable: 'vHsmUpd_Ext_Segment.StartAddress' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCGetDeduplicatedDataMacros  vHsmUpd_Ext Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vHsmUpd_Ext_GetDecryptionRamBufferSizeOfGeneral()                                           vHsmUpd_Ext_GetDecryptionRamBufferSizeOfGeneralOfPCConfig()
#define vHsmUpd_Ext_IsEnableUserCompareMechanismOfGeneral()                                         vHsmUpd_Ext_IsEnableUserCompareMechanismOfGeneralOfPCConfig()
#define vHsmUpd_Ext_GetExpectedCompatibilityVersion()                                                 /**< Deactivateable: 'vHsmUpd_Ext_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_Ext_GetFinalMagicNumber()                                                             /**< Deactivateable: 'vHsmUpd_Ext_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_Ext_GetFirstHeaderAddressOfUpdateHeaderVariableAddress()                              /**< Deactivateable: 'vHsmUpd_Ext_FirstHeaderAddressOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define vHsmUpd_Ext_GetFwStartOfGeneral()                                                           vHsmUpd_Ext_GetFwStartOfGeneralOfPCConfig()
#define vHsmUpd_Ext_GetGeneratorCompatibilityVersion()                                                /**< Deactivateable: 'vHsmUpd_Ext_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_Ext_GetHeaderLocation_AOfUpdateHeaderFixAddress()                                   vHsmUpd_Ext_GetHeaderLocation_AOfUpdateHeaderFixAddressOfPCConfig()
#define vHsmUpd_Ext_GetHeaderLocation_BOfUpdateHeaderFixAddress()                                   vHsmUpd_Ext_GetHeaderLocation_BOfUpdateHeaderFixAddressOfPCConfig()
#define vHsmUpd_Ext_GetHostToHsmOfIpc()                                                             vHsmUpd_Ext_GetHostToHsmOfIpcOfPCConfig()
#define vHsmUpd_Ext_GetHsmToHostOfIpc()                                                             vHsmUpd_Ext_GetHsmToHostOfIpcOfPCConfig()
#define vHsmUpd_Ext_GetInitDataHashCode()                                                             /**< Deactivateable: 'vHsmUpd_Ext_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_Ext_GetNumberOfPossibleHeadersOfUpdateHeaderVariableAddress()                         /**< Deactivateable: 'vHsmUpd_Ext_NumberOfPossibleHeadersOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define vHsmUpd_Ext_IsPartitionRefIndUsedOfPartitionGroup(Index)                                    (((boolean)(vHsmUpd_Ext_GetPartitionRefIndStartIdxOfPartitionGroup(Index) != VHSMUPD_EXT_NO_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to vHsmUpd_Ext_PartitionRefInd */
#define vHsmUpd_Ext_IsPartitionTypeRefUsedOfPartitions(Index)                                       (((boolean)(vHsmUpd_Ext_GetPartitionTypeRefIdxOfPartitions(Index) != VHSMUPD_EXT_NO_PARTITIONTYPEREFIDXOFPARTITIONS)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to vHsmUpd_Ext_PartitionType */
#define vHsmUpd_Ext_GetPlatformPagesizeOfGeneral()                                                  vHsmUpd_Ext_GetPlatformPagesizeOfGeneralOfPCConfig()
#define vHsmUpd_Ext_GetRetryCounterOfGeneral()                                                      vHsmUpd_Ext_GetRetryCounterOfGeneralOfPCConfig()
#define vHsmUpd_Ext_GetSizeOfModuleType()                                                           vHsmUpd_Ext_GetSizeOfModuleTypeOfPCConfig()
#define vHsmUpd_Ext_GetSizeOfModules()                                                              vHsmUpd_Ext_GetSizeOfModulesOfPCConfig()
#define vHsmUpd_Ext_GetSizeOfPartitionGroup()                                                       vHsmUpd_Ext_GetSizeOfPartitionGroupOfPCConfig()
#define vHsmUpd_Ext_GetSizeOfPartitionRef()                                                         vHsmUpd_Ext_GetSizeOfPartitionRefOfPCConfig()
#define vHsmUpd_Ext_GetSizeOfPartitionRefInd()                                                      vHsmUpd_Ext_GetSizeOfPartitionRefIndOfPCConfig()
#define vHsmUpd_Ext_GetSizeOfPartitionType()                                                        vHsmUpd_Ext_GetSizeOfPartitionTypeOfPCConfig()
#define vHsmUpd_Ext_GetSizeOfPartitions()                                                           vHsmUpd_Ext_GetSizeOfPartitionsOfPCConfig()
#define vHsmUpd_Ext_GetSizeOfRegion()                                                               vHsmUpd_Ext_GetSizeOfRegionOfPCConfig()
#define vHsmUpd_Ext_GetWaitMaskOfIpc()                                                              vHsmUpd_Ext_GetWaitMaskOfIpcOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCHasMacros  vHsmUpd_Ext Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vHsmUpd_Ext_HasDecryptionRamBufferSizeOfGeneral()                                           (TRUE != FALSE)
#define vHsmUpd_Ext_HasEnableUserCompareMechanismOfGeneral()                                        (TRUE != FALSE)
#define vHsmUpd_Ext_HasExpectedCompatibilityVersion()                                                 /**< Deactivateable: 'vHsmUpd_Ext_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_Ext_HasFinalMagicNumber()                                                             /**< Deactivateable: 'vHsmUpd_Ext_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_Ext_HasFirstHeaderAddressOfUpdateHeaderVariableAddress()                              /**< Deactivateable: 'vHsmUpd_Ext_FirstHeaderAddressOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define vHsmUpd_Ext_HasFwStartOfGeneral()                                                           (TRUE != FALSE)
#define vHsmUpd_Ext_HasGeneratorCompatibilityVersion()                                                /**< Deactivateable: 'vHsmUpd_Ext_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_Ext_HasHeaderLocation_AOfUpdateHeaderFixAddress()                                   (TRUE != FALSE)
#define vHsmUpd_Ext_HasHeaderLocation_BOfUpdateHeaderFixAddress()                                   (TRUE != FALSE)
#define vHsmUpd_Ext_HasHostToHsmOfIpc()                                                             (TRUE != FALSE)
#define vHsmUpd_Ext_HasHsmToHostOfIpc()                                                             (TRUE != FALSE)
#define vHsmUpd_Ext_HasInitDataHashCode()                                                             /**< Deactivateable: 'vHsmUpd_Ext_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_Ext_HasModuleType()                                                                 (TRUE != FALSE)
#define vHsmUpd_Ext_HasIdOfModuleType()                                                             (TRUE != FALSE)
#define vHsmUpd_Ext_HasModules()                                                                    (TRUE != FALSE)
#define vHsmUpd_Ext_HasModuleIdOfModules()                                                          (TRUE != FALSE)
#define vHsmUpd_Ext_HasModuleTypeRefOfModules()                                                     (TRUE != FALSE)
#define vHsmUpd_Ext_HasModuleTypeRefValidOfModules()                                                (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionGroupRefIdxOfModules()                                              (TRUE != FALSE)
#define vHsmUpd_Ext_HasNumberOfPossibleHeadersOfUpdateHeaderVariableAddress()                         /**< Deactivateable: 'vHsmUpd_Ext_NumberOfPossibleHeadersOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define vHsmUpd_Ext_HasPartitionGroup()                                                             (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionRefIndEndIdxOfPartitionGroup()                                      (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionRefIndStartIdxOfPartitionGroup()                                    (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionRefIndUsedOfPartitionGroup()                                        (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionRef()                                                               (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionRefInd()                                                            (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionType()                                                              (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitonTypeIdOfPartitionType()                                              (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitions()                                                                 (TRUE != FALSE)
#define vHsmUpd_Ext_HasAddressAreaRefOfPartitions()                                                 (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionIdOfPartitions()                                                    (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionTypeRefIdxOfPartitions()                                            (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionTypeRefUsedOfPartitions()                                           (TRUE != FALSE)
#define vHsmUpd_Ext_HasPlatformPagesizeOfGeneral()                                                  (TRUE != FALSE)
#define vHsmUpd_Ext_HasRegion()                                                                     (TRUE != FALSE)
#define vHsmUpd_Ext_HasIdOfRegion()                                                                 (TRUE != FALSE)
#define vHsmUpd_Ext_HasLengthOfRegion()                                                             (TRUE != FALSE)
#define vHsmUpd_Ext_HasModuleRefOfRegion()                                                          (TRUE != FALSE)
#define vHsmUpd_Ext_HasSegmentEndIdxOfRegion()                                                        /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentEndIdx' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define vHsmUpd_Ext_HasSegmentStartIdxOfRegion()                                                      /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentStartIdx' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define vHsmUpd_Ext_HasSegmentUsedOfRegion()                                                          /**< Deactivateable: 'vHsmUpd_Ext_Region.SegmentUsed' Reason: 'the optional indirection is deactivated because SegmentUsedOfRegion is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define vHsmUpd_Ext_HasStartAddressOfRegion()                                                       (TRUE != FALSE)
#define vHsmUpd_Ext_HasRetryCounterOfGeneral()                                                      (TRUE != FALSE)
#define vHsmUpd_Ext_HasSegment()                                                                      /**< Deactivateable: 'vHsmUpd_Ext_Segment' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsmUpd_Ext_HasLengthOfSegment()                                                              /**< Deactivateable: 'vHsmUpd_Ext_Segment.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsmUpd_Ext_HasStartAddressOfSegment()                                                        /**< Deactivateable: 'vHsmUpd_Ext_Segment.StartAddress' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsmUpd_Ext_HasSizeOfModuleType()                                                           (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfModules()                                                              (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionGroup()                                                       (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionRef()                                                         (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionRefInd()                                                      (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionType()                                                        (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitions()                                                           (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfRegion()                                                               (TRUE != FALSE)
#define vHsmUpd_Ext_HasWaitMaskOfIpc()                                                              (TRUE != FALSE)
#define vHsmUpd_Ext_HasPCConfig()                                                                   (TRUE != FALSE)
#define vHsmUpd_Ext_HasDecryptionRamBufferSizeOfGeneralOfPCConfig()                                 (TRUE != FALSE)
#define vHsmUpd_Ext_HasEnableUserCompareMechanismOfGeneralOfPCConfig()                              (TRUE != FALSE)
#define vHsmUpd_Ext_HasExpectedCompatibilityVersionOfPCConfig()                                       /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_Ext_HasFinalMagicNumberOfPCConfig()                                                   /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_Ext_HasFirstHeaderAddressOfUpdateHeaderVariableAddressOfPCConfig()                    /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.FirstHeaderAddressOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define vHsmUpd_Ext_HasFwStartOfGeneralOfPCConfig()                                                 (TRUE != FALSE)
#define vHsmUpd_Ext_HasGeneratorCompatibilityVersionOfPCConfig()                                      /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsmUpd_Ext_HasHeaderLocation_AOfUpdateHeaderFixAddressOfPCConfig()                         (TRUE != FALSE)
#define vHsmUpd_Ext_HasHeaderLocation_BOfUpdateHeaderFixAddressOfPCConfig()                         (TRUE != FALSE)
#define vHsmUpd_Ext_HasHostToHsmOfIpcOfPCConfig()                                                   (TRUE != FALSE)
#define vHsmUpd_Ext_HasHsmToHostOfIpcOfPCConfig()                                                   (TRUE != FALSE)
#define vHsmUpd_Ext_HasInitDataHashCodeOfPCConfig()                                                   /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsmUpd_Ext_HasModuleTypeOfPCConfig()                                                       (TRUE != FALSE)
#define vHsmUpd_Ext_HasModulesOfPCConfig()                                                          (TRUE != FALSE)
#define vHsmUpd_Ext_HasNumberOfPossibleHeadersOfUpdateHeaderVariableAddressOfPCConfig()               /**< Deactivateable: 'vHsmUpd_Ext_PCConfig.NumberOfPossibleHeadersOfUpdateHeaderVariableAddress' Reason: 'Parameter is not configured!' */
#define vHsmUpd_Ext_HasPartitionGroupOfPCConfig()                                                   (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionRefIndOfPCConfig()                                                  (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionRefOfPCConfig()                                                     (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionTypeOfPCConfig()                                                    (TRUE != FALSE)
#define vHsmUpd_Ext_HasPartitionsOfPCConfig()                                                       (TRUE != FALSE)
#define vHsmUpd_Ext_HasPlatformPagesizeOfGeneralOfPCConfig()                                        (TRUE != FALSE)
#define vHsmUpd_Ext_HasRegionOfPCConfig()                                                           (TRUE != FALSE)
#define vHsmUpd_Ext_HasRetryCounterOfGeneralOfPCConfig()                                            (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfModuleTypeOfPCConfig()                                                 (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfModulesOfPCConfig()                                                    (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionGroupOfPCConfig()                                             (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionRefIndOfPCConfig()                                            (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionRefOfPCConfig()                                               (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionTypeOfPCConfig()                                              (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfPartitionsOfPCConfig()                                                 (TRUE != FALSE)
#define vHsmUpd_Ext_HasSizeOfRegionOfPCConfig()                                                     (TRUE != FALSE)
#define vHsmUpd_Ext_HasWaitMaskOfIpcOfPCConfig()                                                    (TRUE != FALSE)
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
  \defgroup  vHsmUpd_ExtPBGetRootDataMacros  vHsmUpd_Ext Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vHsmUpd_Ext_GetLTConfigIdxOfPBConfig()                                                        /**< Deactivateable: 'vHsmUpd_Ext_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsmUpd_Ext_GetPCConfigIdxOfPBConfig()                                                        /**< Deactivateable: 'vHsmUpd_Ext_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPBHasMacros  vHsmUpd_Ext Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vHsmUpd_Ext_HasPBConfig()                                                                     /**< Deactivateable: 'vHsmUpd_Ext_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsmUpd_Ext_HasLTConfigIdxOfPBConfig()                                                        /**< Deactivateable: 'vHsmUpd_Ext_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsmUpd_Ext_HasPCConfigIdxOfPBConfig()                                                        /**< Deactivateable: 'vHsmUpd_Ext_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
 *********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpd_ExtPCIterableTypes  vHsmUpd_Ext Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vHsmUpd_Ext_ModuleType */
typedef uint8_least vHsmUpd_Ext_ModuleTypeIterType;

/**   \brief  type used to iterate vHsmUpd_Ext_Modules */
typedef uint8_least vHsmUpd_Ext_ModulesIterType;

/**   \brief  type used to iterate vHsmUpd_Ext_PartitionGroup */
typedef uint8_least vHsmUpd_Ext_PartitionGroupIterType;

/**   \brief  type used to iterate vHsmUpd_Ext_PartitionRef */
typedef uint8_least vHsmUpd_Ext_PartitionRefIterType;

/**   \brief  type used to iterate vHsmUpd_Ext_PartitionRefInd */
typedef uint8_least vHsmUpd_Ext_PartitionRefIndIterType;

/**   \brief  type used to iterate vHsmUpd_Ext_PartitionType */
typedef uint8_least vHsmUpd_Ext_PartitionTypeIterType;

/**   \brief  type used to iterate vHsmUpd_Ext_Partitions */
typedef uint8_least vHsmUpd_Ext_PartitionsIterType;

/**   \brief  type used to iterate vHsmUpd_Ext_Region */
typedef uint8_least vHsmUpd_Ext_RegionIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCValueTypes  vHsmUpd_Ext Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vHsmUpd_Ext_DecryptionRamBufferSizeOfGeneral */
typedef uint16 vHsmUpd_Ext_DecryptionRamBufferSizeOfGeneralType;

/**   \brief  value based type definition for vHsmUpd_Ext_EnableUserCompareMechanismOfGeneral */
typedef boolean vHsmUpd_Ext_EnableUserCompareMechanismOfGeneralType;

/**   \brief  value based type definition for vHsmUpd_Ext_FwStartOfGeneral */
typedef uint32 vHsmUpd_Ext_FwStartOfGeneralType;

/**   \brief  value based type definition for vHsmUpd_Ext_HeaderLocation_AOfUpdateHeaderFixAddress */
typedef uint32 vHsmUpd_Ext_HeaderLocation_AOfUpdateHeaderFixAddressType;

/**   \brief  value based type definition for vHsmUpd_Ext_HeaderLocation_BOfUpdateHeaderFixAddress */
typedef uint32 vHsmUpd_Ext_HeaderLocation_BOfUpdateHeaderFixAddressType;

/**   \brief  value based type definition for vHsmUpd_Ext_HostToHsmOfIpc */
typedef uint32 vHsmUpd_Ext_HostToHsmOfIpcType;

/**   \brief  value based type definition for vHsmUpd_Ext_HsmToHostOfIpc */
typedef uint32 vHsmUpd_Ext_HsmToHostOfIpcType;

/**   \brief  value based type definition for vHsmUpd_Ext_IdOfModuleType */
typedef uint8 vHsmUpd_Ext_IdOfModuleTypeType;

/**   \brief  value based type definition for vHsmUpd_Ext_ModuleIdOfModules */
typedef uint8 vHsmUpd_Ext_ModuleIdOfModulesType;

/**   \brief  value based type definition for vHsmUpd_Ext_ModuleTypeRefOfModules */
typedef uint32 vHsmUpd_Ext_ModuleTypeRefOfModulesType;

/**   \brief  value based type definition for vHsmUpd_Ext_ModuleTypeRefValidOfModules */
typedef boolean vHsmUpd_Ext_ModuleTypeRefValidOfModulesType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionGroupRefIdxOfModules */
typedef uint8 vHsmUpd_Ext_PartitionGroupRefIdxOfModulesType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionRefIndEndIdxOfPartitionGroup */
typedef uint8 vHsmUpd_Ext_PartitionRefIndEndIdxOfPartitionGroupType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionRefIndStartIdxOfPartitionGroup */
typedef uint8 vHsmUpd_Ext_PartitionRefIndStartIdxOfPartitionGroupType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionRefIndUsedOfPartitionGroup */
typedef boolean vHsmUpd_Ext_PartitionRefIndUsedOfPartitionGroupType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionRef */
typedef uint32 vHsmUpd_Ext_PartitionRefType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionRefInd */
typedef uint8 vHsmUpd_Ext_PartitionRefIndType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitonTypeIdOfPartitionType */
typedef uint8 vHsmUpd_Ext_PartitonTypeIdOfPartitionTypeType;

/**   \brief  value based type definition for vHsmUpd_Ext_AddressAreaRefOfPartitions */
typedef uint32 vHsmUpd_Ext_AddressAreaRefOfPartitionsType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionIdOfPartitions */
typedef uint8 vHsmUpd_Ext_PartitionIdOfPartitionsType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionTypeRefIdxOfPartitions */
typedef uint8 vHsmUpd_Ext_PartitionTypeRefIdxOfPartitionsType;

/**   \brief  value based type definition for vHsmUpd_Ext_PartitionTypeRefUsedOfPartitions */
typedef boolean vHsmUpd_Ext_PartitionTypeRefUsedOfPartitionsType;

/**   \brief  value based type definition for vHsmUpd_Ext_PlatformPagesizeOfGeneral */
typedef uint8 vHsmUpd_Ext_PlatformPagesizeOfGeneralType;

/**   \brief  value based type definition for vHsmUpd_Ext_IdOfRegion */
typedef uint8 vHsmUpd_Ext_IdOfRegionType;

/**   \brief  value based type definition for vHsmUpd_Ext_LengthOfRegion */
typedef uint32 vHsmUpd_Ext_LengthOfRegionType;

/**   \brief  value based type definition for vHsmUpd_Ext_ModuleRefOfRegion */
typedef uint32 vHsmUpd_Ext_ModuleRefOfRegionType;

/**   \brief  value based type definition for vHsmUpd_Ext_StartAddressOfRegion */
typedef uint32 vHsmUpd_Ext_StartAddressOfRegionType;

/**   \brief  value based type definition for vHsmUpd_Ext_RetryCounterOfGeneral */
typedef uint8 vHsmUpd_Ext_RetryCounterOfGeneralType;

/**   \brief  value based type definition for vHsmUpd_Ext_SizeOfModuleType */
typedef uint8 vHsmUpd_Ext_SizeOfModuleTypeType;

/**   \brief  value based type definition for vHsmUpd_Ext_SizeOfModules */
typedef uint8 vHsmUpd_Ext_SizeOfModulesType;

/**   \brief  value based type definition for vHsmUpd_Ext_SizeOfPartitionGroup */
typedef uint8 vHsmUpd_Ext_SizeOfPartitionGroupType;

/**   \brief  value based type definition for vHsmUpd_Ext_SizeOfPartitionRef */
typedef uint8 vHsmUpd_Ext_SizeOfPartitionRefType;

/**   \brief  value based type definition for vHsmUpd_Ext_SizeOfPartitionRefInd */
typedef uint8 vHsmUpd_Ext_SizeOfPartitionRefIndType;

/**   \brief  value based type definition for vHsmUpd_Ext_SizeOfPartitionType */
typedef uint8 vHsmUpd_Ext_SizeOfPartitionTypeType;

/**   \brief  value based type definition for vHsmUpd_Ext_SizeOfPartitions */
typedef uint8 vHsmUpd_Ext_SizeOfPartitionsType;

/**   \brief  value based type definition for vHsmUpd_Ext_SizeOfRegion */
typedef uint8 vHsmUpd_Ext_SizeOfRegionType;

/**   \brief  value based type definition for vHsmUpd_Ext_WaitMaskOfIpc */
typedef uint32 vHsmUpd_Ext_WaitMaskOfIpcType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpd_ExtPCStructTypes  vHsmUpd_Ext Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vHsmUpd_Ext_ModuleType */
typedef struct svHsmUpd_Ext_ModuleTypeType
{
  vHsmUpd_Ext_IdOfModuleTypeType IdOfModuleType;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtModuleType/vHsmUpd_ExtModuleTypeId. */
} vHsmUpd_Ext_ModuleTypeType;

/**   \brief  type used in vHsmUpd_Ext_Modules */
typedef struct svHsmUpd_Ext_ModulesType
{
  vHsmUpd_Ext_ModuleTypeRefOfModulesType ModuleTypeRefOfModules;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModules/vHsmUpd_ExtModuleTypeRef. */
  vHsmUpd_Ext_ModuleTypeRefValidOfModulesType ModuleTypeRefValidOfModules;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModules/vHsmUpd_ExtModuleTypeRef. */
  vHsmUpd_Ext_ModuleIdOfModulesType ModuleIdOfModules;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModules/vHsmUpd_ExtModuleId. */
  vHsmUpd_Ext_PartitionGroupRefIdxOfModulesType PartitionGroupRefIdxOfModules;  /**< the index of the 1:1 relation pointing to one of vHsmUpd_Ext_PartitionGroup */
} vHsmUpd_Ext_ModulesType;

/**   \brief  type used in vHsmUpd_Ext_PartitionGroup */
typedef struct svHsmUpd_Ext_PartitionGroupType
{
  vHsmUpd_Ext_PartitionRefIndEndIdxOfPartitionGroupType PartitionRefIndEndIdxOfPartitionGroup;  /**< the end index of the 0:n relation pointing to vHsmUpd_Ext_PartitionRefInd */
  vHsmUpd_Ext_PartitionRefIndStartIdxOfPartitionGroupType PartitionRefIndStartIdxOfPartitionGroup;  /**< the start index of the 0:n relation pointing to vHsmUpd_Ext_PartitionRefInd */
} vHsmUpd_Ext_PartitionGroupType;

/**   \brief  type used in vHsmUpd_Ext_PartitionType */
typedef struct svHsmUpd_Ext_PartitionTypeType
{
  vHsmUpd_Ext_PartitonTypeIdOfPartitionTypeType PartitonTypeIdOfPartitionType;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtPartitionType/vHsmUpd_ExtPartitonTypeId. */
} vHsmUpd_Ext_PartitionTypeType;

/**   \brief  type used in vHsmUpd_Ext_Partitions */
typedef struct svHsmUpd_Ext_PartitionsType
{
  vHsmUpd_Ext_AddressAreaRefOfPartitionsType AddressAreaRefOfPartitions;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitions/vHsmUpd_ExtAddressAreaRef. */
  vHsmUpd_Ext_PartitionIdOfPartitionsType PartitionIdOfPartitions;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitions/vHsmUpd_ExtPartitionId. */
  vHsmUpd_Ext_PartitionTypeRefIdxOfPartitionsType PartitionTypeRefIdxOfPartitions;  /**< the index of the 0:1 relation pointing to vHsmUpd_Ext_PartitionType */
} vHsmUpd_Ext_PartitionsType;

/**   \brief  type used in vHsmUpd_Ext_Region */
typedef struct svHsmUpd_Ext_RegionType
{
  vHsmUpd_Ext_LengthOfRegionType LengthOfRegion;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion/vHsmUpd_ExtLength. */
  vHsmUpd_Ext_ModuleRefOfRegionType ModuleRefOfRegion;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion/vHsmUpd_ExtModuleRef. */
  vHsmUpd_Ext_StartAddressOfRegionType StartAddressOfRegion;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion/vHsmUpd_ExtStartAddress. */
  vHsmUpd_Ext_IdOfRegionType IdOfRegion;  /**< Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion/vHsmUpd_ExtRegionId. */
} vHsmUpd_Ext_RegionType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCRootPointerTypes  vHsmUpd_Ext Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vHsmUpd_Ext_ModuleType */
typedef P2CONST(vHsmUpd_Ext_ModuleTypeType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_ModuleTypePtrType;

/**   \brief  type used to point to vHsmUpd_Ext_Modules */
typedef P2CONST(vHsmUpd_Ext_ModulesType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_ModulesPtrType;

/**   \brief  type used to point to vHsmUpd_Ext_PartitionGroup */
typedef P2CONST(vHsmUpd_Ext_PartitionGroupType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionGroupPtrType;

/**   \brief  type used to point to vHsmUpd_Ext_PartitionRef */
typedef P2CONST(vHsmUpd_Ext_PartitionRefType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionRefPtrType;

/**   \brief  type used to point to vHsmUpd_Ext_PartitionRefInd */
typedef P2CONST(vHsmUpd_Ext_PartitionRefIndType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionRefIndPtrType;

/**   \brief  type used to point to vHsmUpd_Ext_PartitionType */
typedef P2CONST(vHsmUpd_Ext_PartitionTypeType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionTypePtrType;

/**   \brief  type used to point to vHsmUpd_Ext_Partitions */
typedef P2CONST(vHsmUpd_Ext_PartitionsType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionsPtrType;

/**   \brief  type used to point to vHsmUpd_Ext_Region */
typedef P2CONST(vHsmUpd_Ext_RegionType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_RegionPtrType;

/**   \brief  type used to point to vHsmUpd_Ext_FwStartOfGeneralOfPCConfig */
typedef P2CONST(vHsmUpd_Ext_FwStartOfGeneralType, TYPEDEF, VHSMUPD_EXT_CONST) vHsmUpd_Ext_FwStartOfGeneralOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsmUpd_ExtPCRootValueTypes  vHsmUpd_Ext Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vHsmUpd_Ext_PCConfig */
typedef struct svHsmUpd_Ext_PCConfigType
{
  uint8 vHsmUpd_Ext_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vHsmUpd_Ext_PCConfigType;

typedef vHsmUpd_Ext_PCConfigType vHsmUpd_Ext_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmUpd_ExtPBValueTypes  vHsmUpd_Ext Value Types (POST_BUILD)
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
  \defgroup  vHsmUpd_ExtPBRootValueTypes  vHsmUpd_Ext Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  vHsmUpd_Ext_ModuleType
**********************************************************************************************************************/
/** 
  \var    vHsmUpd_Ext_ModuleType
  \brief  Contains parameters of /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtModuleType.
  \details
  Element    Description
  Id         Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtModuleType/vHsmUpd_ExtModuleTypeId.
*/ 
#define VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsmUpd_Ext_ModuleTypeType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_ModuleType[2];
#define VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsmUpd_Ext_Modules
**********************************************************************************************************************/
/** 
  \var    vHsmUpd_Ext_Modules
  \brief  Contains parameters of /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModules.
  \details
  Element                 Description
  ModuleTypeRef           Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModules/vHsmUpd_ExtModuleTypeRef.
  ModuleTypeRefValid      Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModules/vHsmUpd_ExtModuleTypeRef.
  ModuleId                Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModules/vHsmUpd_ExtModuleId.
  PartitionGroupRefIdx    the index of the 1:1 relation pointing to one of vHsmUpd_Ext_PartitionGroup
*/ 
#define VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsmUpd_Ext_ModulesType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_Modules[1];
#define VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsmUpd_Ext_PartitionGroup
**********************************************************************************************************************/
/** 
  \var    vHsmUpd_Ext_PartitionGroup
  \brief  Contains parameters of /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitionGroup.
  \details
  Element                    Description
  PartitionRefIndEndIdx      the end index of the 0:n relation pointing to vHsmUpd_Ext_PartitionRefInd
  PartitionRefIndStartIdx    the start index of the 0:n relation pointing to vHsmUpd_Ext_PartitionRefInd
*/ 
#define VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsmUpd_Ext_PartitionGroupType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionGroup[1];
#define VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsmUpd_Ext_PartitionRef
**********************************************************************************************************************/
/** 
  \var    vHsmUpd_Ext_PartitionRef
  \brief  Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitionGroup/vHsmUpd_ExtPartitionRef.
*/ 
#define VHSMUPD_EXT_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsmUpd_Ext_PartitionRefType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionRef[1];
#define VHSMUPD_EXT_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsmUpd_Ext_PartitionRefInd
**********************************************************************************************************************/
/** 
  \var    vHsmUpd_Ext_PartitionRefInd
  \brief  the indexes of the 1:1 sorted relation pointing to vHsmUpd_Ext_PartitionRef
*/ 
#define VHSMUPD_EXT_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsmUpd_Ext_PartitionRefIndType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionRefInd[1];
#define VHSMUPD_EXT_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsmUpd_Ext_PartitionType
**********************************************************************************************************************/
/** 
  \var    vHsmUpd_Ext_PartitionType
  \brief  Contains parameters of /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtPartitionType.
  \details
  Element           Description
  PartitonTypeId    Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtPartitionType/vHsmUpd_ExtPartitonTypeId.
*/ 
#define VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsmUpd_Ext_PartitionTypeType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionType[2];
#define VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsmUpd_Ext_Partitions
**********************************************************************************************************************/
/** 
  \var    vHsmUpd_Ext_Partitions
  \brief  Contains parameters of /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitions.
  \details
  Element                Description
  AddressAreaRef         Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitions/vHsmUpd_ExtAddressAreaRef.
  PartitionId            Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitions/vHsmUpd_ExtPartitionId.
  PartitionTypeRefIdx    the index of the 0:1 relation pointing to vHsmUpd_Ext_PartitionType
*/ 
#define VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsmUpd_Ext_PartitionsType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_Partitions[1];
#define VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsmUpd_Ext_Region
**********************************************************************************************************************/
/** 
  \var    vHsmUpd_Ext_Region
  \brief  Contains parameters of /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion.
  \details
  Element         Description
  Length          Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion/vHsmUpd_ExtLength.
  ModuleRef       Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion/vHsmUpd_ExtModuleRef.
  StartAddress    Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion/vHsmUpd_ExtStartAddress.
  Id              Contains values of DefinitionRef: /MICROSAR/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion/vHsmUpd_ExtRegionId.
*/ 
#define VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsmUpd_Ext_RegionType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_Region[1];
#define VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/




 
#define VHSMUPD_EXT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsmUpd_FirmwareStart()
 *********************************************************************************************************************/
/*! \brief       Function to jump to vHsm Firmware. The Label must be defined in the linker script.
 *  \details     Call to this function will never return
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, VHSMUPD_EXT_CODE) vHsmUpd_FirmwareStart(void);

#define VHSMUPD_EXT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */





#endif /* VHSMUPD_EXT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Cfg.h
 *********************************************************************************************************************/

