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
 *              File: vHsmUpd_Ext_Cfg.c
 *   Generation Time: 2022-05-23 14:13:53
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

#define VHSMUPD_EXT_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Ext_Cfg.h"
#include "vHsmUpd_Ext.h"
#include "vMemAccM.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (VHSMUPD_EXT_LOCAL)
# define VHSMUPD_EXT_LOCAL static
#endif

#if !defined (VHSMUPD_EXT_LOCAL_INLINE)
# define VHSMUPD_EXT_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
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
CONST(vHsmUpd_Ext_ModuleTypeType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_ModuleType[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id        Referable Keys */
  { /*     0 */ 0u },  /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtvHsmFirmware, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModule_vHsmFw:vHsmUpd_ExtModuleTypeRef] */
  { /*     1 */ 1u }   /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtvHsmUpd, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes] */
};
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
CONST(vHsmUpd_Ext_ModulesType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_Modules[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ModuleTypeRef                                                  ModuleTypeRefValid  ModuleId  PartitionGroupRefIdx        Referable Keys */
  { /*     0 */ vHsmUpd_ExtConf_vHsmUpd_ExtModuleType_vHsmUpd_ExtvHsmFirmware,               TRUE,       0u,                   0u }   /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModule_vHsmFw, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion_vHsmFw:vHsmUpd_ExtModuleRef] */
};
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
CONST(vHsmUpd_Ext_PartitionGroupType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionGroup[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitionRefIndEndIdx  PartitionRefIndStartIdx        Referable Keys */
  { /*     0 */                    1u,                      0u }   /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitionGroup, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtModule_vHsmFw:vHsmUpd_ExtPartitionGroupRef] */
};
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
CONST(vHsmUpd_Ext_PartitionRefType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionRef[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PartitionRef                                                    Referable Keys */
  /*     0 */ vHsmUpd_ExtConf_vHsmUpd_ExtPartitions_Partition_MainActive    /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitionGroup[0:vHsmUpd_ExtPartitionRef], /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitionGroup, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/Partition_MainActive] */
};
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
CONST(vHsmUpd_Ext_PartitionRefIndType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionRefInd[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PartitionRefInd      Referable Keys */
  /*     0 */               0u   /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitionGroup] */
};
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
CONST(vHsmUpd_Ext_PartitionTypeType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_PartitionType[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PartitonTypeId        Referable Keys */
  { /*     0 */             0u },  /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtMainActive, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/Partition_MainActive:vHsmUpd_ExtPartitionTypeRef] */
  { /*     1 */             1u }   /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes/vHsmUpd_ExtAlternativeActive, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtTypes] */
};
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
CONST(vHsmUpd_Ext_PartitionsType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_Partitions[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AddressAreaRef                                                                  PartitionId  PartitionTypeRefIdx        Referable Keys */
  { /*     0 */ vMemAccMConf_vMemAccMAddressAreaConfiguration_vMemAccMAddressAreaConfiguration,          0u,                  0u }   /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/Partition_MainActive, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtPartitionGroup:vHsmUpd_ExtPartitionRef] */
};
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
CONST(vHsmUpd_Ext_RegionType, VHSMUPD_EXT_CONST) vHsmUpd_Ext_Region[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Length       ModuleRef                                                    StartAddress  Id        Referable Keys */
  { /*     0 */ 0x0002C000u, vHsmUpd_ExtConf_vHsmUpd_ExtModules_vHsmUpd_ExtModule_vHsmFw,  0x80008000u, 0u }   /* [/ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout/vHsmUpd_ExtRegion_vHsmFw, /ActiveEcuC/vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtCodeflashLayout] */
};
#define VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Ext_Cfg.c
 *********************************************************************************************************************/
