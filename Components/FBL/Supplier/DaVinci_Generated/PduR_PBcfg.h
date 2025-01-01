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
 *            Module: PduR
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_PBcfg.h
 *   Generation Time: 2023-07-05 16:23:59
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/



#if !defined (PDUR_PBCFG_H)
# define PDUR_PBCFG_H
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* \trace SPEC-1238 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPBDataSwitches  PduR Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'PduR_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PDUR_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'PduR_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PDUR_PBPARTITIONCONFIGOFPBCONFIG                                                            STD_OFF  /**< Deactivateable: 'PduR_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PDUR_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'PduR_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PDUR_PBPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'PduR_PBPartitionConfigRBTM_FL' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' and Deactivateable: 'PduR_PBPartitionConfigRBTM_FR' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPBIsReducedToDefineDefines  PduR Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define PDUR_ISDEF_LTCONFIGIDXOFPBCONFIG                                                            STD_OFF
#define PDUR_ISDEF_PBPARTITIONCONFIGOFPBCONFIG                                                      STD_OFF
#define PDUR_ISDEF_PCCONFIGIDXOFPBCONFIG                                                            STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  PduRPBEqualsAlwaysToDefines  PduR Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define PDUR_EQ2_LTCONFIGIDXOFPBCONFIG                                                              
#define PDUR_EQ2_PBPARTITIONCONFIGOFPBCONFIG                                                        
#define PDUR_EQ2_PCCONFIGIDXOFPBCONFIG                                                              
/** 
  \}
*/ 



/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
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
  \defgroup  PduRPBGetRootDataMacros  PduR Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define PduR_GetLTConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'PduR_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PduR_GetPBPartitionConfigOfPBConfig()                                                         /**< Deactivateable: 'PduR_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PduR_GetPCConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'PduR_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPBHasMacros  PduR Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define PduR_HasPBConfig()                                                                            /**< Deactivateable: 'PduR_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PduR_HasLTConfigIdxOfPBConfig(partitionIndex)                                                 /**< Deactivateable: 'PduR_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PduR_HasPBPartitionConfigOfPBConfig()                                                         /**< Deactivateable: 'PduR_PBConfig.PBPartitionConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PduR_HasPCConfigIdxOfPBConfig(partitionIndex)                                                 /**< Deactivateable: 'PduR_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PduR_HasPBPartitionConfig()                                                                   /**< Deactivateable: 'PduR_PBPartitionConfigRBTM_FL' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' and Deactivateable: 'PduR_PBPartitionConfigRBTM_FR' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPBIterableTypes  PduR Iterable Types (POST_BUILD)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  PduRPBValueTypes  PduR Value Types (POST_BUILD)
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
  \defgroup  PduRPBPartitionRootPointer  PduR Partition Root Pointer (POST_BUILD)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  PduRPBRootValueTypes  PduR Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif  /* PDUR_PBCFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_PBcfg.h
 *********************************************************************************************************************/

