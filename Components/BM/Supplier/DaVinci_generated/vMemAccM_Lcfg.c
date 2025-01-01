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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vMemAccM_Lcfg.c
 *   Generation Time: 2023-07-17 14:11:52
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


/* macro identifying this compilation unit */
#define VMEMACCM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "vMemAccM_Types.h"
#include "vMemAccM_IntCfg.h"


/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

extern CONST(vMemAccM_vMemApiType, VMEMACCM_CONST) vMem_30_Fbl_FunctionPointerTable; 


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
  JobEndNotification            Notification that will be called upon asynchronous job completion.
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMemAccM_AddressAreaType, VMEMACCM_CONST) vMemAccM_AddressArea[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AddressAreaVariantEndIdx  AddressAreaVariantLength  AddressAreaVariantStartIdx  Priority  ReadLength  JobEndNotification        Referable Keys */
  { /*     0 */                       1u,                       1u,                         0u,       0u,        64u, NULL_PTR           }   /* [/ActiveEcuC/vMemAccM/Active_AddressArea] */
};
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
CONST(vMemAccM_AddressAreaVariantType, VMEMACCM_CONST) vMemAccM_AddressAreaVariant[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  SubAddressAreaEndIdx  SubAddressAreaLength  SubAddressAreaStartIdx        Referable Keys */
  { /*     0 */ 0u,                   1u,                   1u,                     0u }   /* [/ActiveEcuC/vMemAccM/Active_AddressArea] */
};
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
  Element                   Description
  PhysicalStartAddress      Physical start address of SubAddressArea
  VirtualEndAddress         Virtual end address of SubAddressArea
  VirtualStartAddress       Virtual start address of SubAddressArea
  NumberOfSectors           Number of sectors of SubAddressArea
  SectorSize                Size of a sector in bytes
  UsePageBurst              vMem page/ write burst shall be used or not.
  UseSectorBurst            vMem sector/ erase burst shall be used or not.
  NumberOfEraseRetries      Number of erase retries in case of a failed vMem job
  NumberOfWriteRetries      Number of write retries in case of a failed vMem job
  PageBurstRamAlignment     Alignment for page burst ram - Zero if not configured
  PageBurstSize             Size of page burst in bytes - Zero if not configured
  PageSize                  Size of a page in bytes
  SectorBurstSize           Size of sector burst in bytes - Zero if not configured
  SynchronizationGroupId    Id of the synchronization group. All SubAddressAreas within one group must be synchronized
  vMemTableIndex            Index pointing to the entry within the configured vMem table.
  HardwareId                Numeric identifier of vMem hardware, used in hardware specific requests
  vMemInstanceId            Numeric identifier of vMem instance, used as parameter in vMem API
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMemAccM_SubAddressAreaType, VMEMACCM_CONST) vMemAccM_SubAddressArea[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PhysicalStartAddress  VirtualEndAddress  VirtualStartAddress  NumberOfSectors  SectorSize  UsePageBurst  UseSectorBurst  NumberOfEraseRetries  NumberOfWriteRetries  PageBurstRamAlignment  PageBurstSize  PageSize  SectorBurstSize  SynchronizationGroupId  vMemTableIndex  HardwareId                  vMemInstanceId        Referable Keys */
  { /*     0 */          2684633088u,       2690514943u,         2684633088u,            359u,     16384u,        FALSE,          FALSE,                   0u,                   0u,                    0u,            0u,      32u,              0u,                     0u, 0u            , VMEMACCM_VMEM_VMEMINSTANCE, 0u             }   /* [/ActiveEcuC/vMemAccM/Active_AddressArea/NoVariant] */
};
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vMemAccM_vMemPointerTable
**********************************************************************************************************************/
/** 
  \var    vMemAccM_vMemPointerTable
  \brief  Table containing all vMem function table pointers.
*/ 
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vMemAccM_ConstvMemApiPtrType, VMEMACCM_CONST) vMemAccM_vMemPointerTable[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     vMemPointerTable                   */
  /*     0 */ &vMem_30_Fbl_FunctionPointerTable 
};
#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES: MULTI PARTITION USE CASE: PARTITION LOCAL DATA
**********************************************************************************************************************/
/* Master variables, visible only for multi partition master, local RAM. */
#define VMEMACCM_START_SEC_VAR_INIT_32BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */



#define VMEMACCM_STOP_SEC_VAR_INIT_32BIT
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/* Each partition accesses the NV RAM access token via a pointer to abstract from actual symbol/ address. */
#define VMEMACCM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */






#define VMEMACCM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

#define VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */


#define VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES: MULTI PARTITION USE CASE: MULTI PARTITION GLOBAL DATA
**********************************************************************************************************************/
/* Master variables published to all partitions. */


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


/**********************************************************************************************************************
  END OF FILE: vMemAccM_Lcfg.c
**********************************************************************************************************************/

