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
 *              File: vMem_30_Tc3xxInf01_Lcfg.c
 *   Generation Time: 2022-05-23 18:39:41
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


#define VMEM_30_TC3XXINF01_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vMem_30_Tc3xxInf01_Cfg.h"




/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
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
CONST(vMem_30_Tc3xxInf01_MemSectorType, VMEM_30_TC3XXINF01_CONST) vMem_30_Tc3xxInf01_MemSector[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AlternateAddress  EraseBurstSize  StartAddress  SectorSize  WriteBurstSize  NrOfSectors  PageSize  PhysicalSectorId  ProgramFlashId  RamAlignment        Referable Keys */
  { /*     0 */      0x80008000u,        524288u,  0x80008000u,     16384u,           256u,         11u,      32u,               0u,             0u,           1u }   /* [/ActiveEcuC/vMem/vMemInstance] */
};
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
CONST(vMem_30_Tc3xxInf01_vMemInstanceType, VMEM_30_TC3XXINF01_CONST) vMem_30_Tc3xxInf01_vMemInstance[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  MemSectorEndIdx  MemSectorLength  MemSectorStartIdx        Referable Keys */
  { /*     0 */ 0u,              1u,              1u,                0u }   /* [/ActiveEcuC/vMem/vMemInstance] */
};
#define VMEM_30_TC3XXINF01_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


