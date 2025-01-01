/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_Tc3xxInf01_IntShared.h
 *        \brief  Internal shared code for vMem_30_Tc3xxInf01.
 *      \details  Code that may be useful for all subcomponents of vMem_30_Tc3xxInf01.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VMEM_30_TC3XXINF01_INTSHARED_H)
# define VMEM_30_TC3XXINF01_INTSHARED_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vMem_30_Tc3xxInf01_Types.h"
# include "vMem_30_Tc3xxInf01_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEM_30_TC3XXINF01_INTSHARED_LOCAL) /* COV_VMEM_30_TC3XXINF01_COMPATIBILITY */
# define VMEM_30_TC3XXINF01_INTSHARED_LOCAL static
#endif

#if !defined (VMEM_30_TC3XXINF01_INTSHARED_LOCAL_INLINE) /* COV_VMEM_30_TC3XXINF01_COMPATIBILITY */
# define VMEM_30_TC3XXINF01_INTSHARED_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define VMEM_30_TC3XXINF01_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetSectorIndex()
 *********************************************************************************************************************/
/*!
 * \brief       Searches for the passed address within the configuration and determined index of sector (batch) in
 *              configuration structure.
 * \details     -
 * \param[in]   InstanceId        ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]   Address           NV memory address which shall be found within configured sector structure.
 * \return      Index to the sector batch, or an out of range value.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_INTSHARED_LOCAL_INLINE FUNC(uint32, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetSectorIndex(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType Address);
  
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetSectorEndAddress()
 *********************************************************************************************************************/
/*!
 * \brief       Calculates the sector batch end address of the given sector or sector batch.
 * \details     -
 * \param[in]   SectorIndex  Index of the given sector or sector batch.
 * \return      End address of the sector or sector batch.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_INTSHARED_LOCAL_INLINE FUNC(vMem_30_Tc3xxInf01_AddressType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetSectorEndAddress(
  vMem_30_Tc3xxInf01_MemSectorIterType SectorIndex
);

/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetSectorIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_INTSHARED_LOCAL_INLINE FUNC(uint32, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetSectorIndex( /* PRQA S 3219 */ /* MD_CRC_2.1_StaticFunctionNotUsed */ /* COV_VMEM_30_TC3XXINF01_UTILITYCODE_UNUSED */
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType Address)
{
  vMem_30_Tc3xxInf01_MemSectorIterType result = vMem_30_Tc3xxInf01_GetSizeOfMemSector();
  vMem_30_Tc3xxInf01_MemSectorIterType sectorIndex;
  vMem_30_Tc3xxInf01_MemSectorStartIdxOfvMemInstanceType sectorStartIndex =
      vMem_30_Tc3xxInf01_GetMemSectorStartIdxOfvMemInstance(InstanceId);
  vMem_30_Tc3xxInf01_MemSectorEndIdxOfvMemInstanceType sectorEndIndex =
      vMem_30_Tc3xxInf01_GetMemSectorEndIdxOfvMemInstance(InstanceId);

  for (sectorIndex = sectorStartIndex; sectorIndex < sectorEndIndex; sectorIndex++)
  {
    /* The address may be equal to the start address or even higher. It shall also be lower than the
     * end of the sector (batch). -1 takes care about overflows - the sector batch may be located
     * at the end of the address range. */
    vMem_30_Tc3xxInf01_AddressType sectorBatchStartAddress =
        vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(sectorIndex);
    vMem_30_Tc3xxInf01_AddressType sectorBatchEndAddress = vMem_30_Tc3xxInf01_GetSectorEndAddress(sectorIndex);

    if ((Address >= sectorBatchStartAddress) && (Address <= sectorBatchEndAddress))
    {
      result = sectorIndex;
      break;
    }
  }
  return result;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetSectorEndAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_INTSHARED_LOCAL_INLINE FUNC(vMem_30_Tc3xxInf01_AddressType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetSectorEndAddress( /* PRQA S 3219 */ /* MD_CRC_2.1_StaticFunctionNotUsed */ /* COV_VMEM_30_TC3XXINF01_UTILITYCODE_UNUSED */
  vMem_30_Tc3xxInf01_MemSectorIterType SectorIndex
)
{
  vMem_30_Tc3xxInf01_AddressType sectorBatchEndAddress;
  vMem_30_Tc3xxInf01_AddressType sectorBatchStartAddress =
      vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(SectorIndex);
  vMem_30_Tc3xxInf01_NrOfSectorsOfMemSectorType sectorBatchNumberOfSectors =
      vMem_30_Tc3xxInf01_GetNrOfSectorsOfMemSector(SectorIndex);
  vMem_30_Tc3xxInf01_SectorSizeOfMemSectorType sectorSize =
      vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(SectorIndex);
  vMem_30_Tc3xxInf01_LengthType sectorBatchSize;

  sectorBatchSize = (vMem_30_Tc3xxInf01_LengthType)sectorBatchNumberOfSectors * sectorSize;
  sectorBatchEndAddress = sectorBatchStartAddress + ((vMem_30_Tc3xxInf01_AddressType)sectorBatchSize - 1u);

  return sectorBatchEndAddress;
}

# define VMEM_30_TC3XXINF01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_TC3XXINF01_INTSHARED_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Tc3xxInf01_IntShared.h
 *********************************************************************************************************************/
