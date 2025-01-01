/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                              All rights reserved.
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
LOCAL_INLINE FUNC(uint32, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetSectorIndex(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType Address);

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
LOCAL_INLINE FUNC(uint32, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetSectorIndex( /* PRQA S 3219 */ /* MD_CRC_2.1_StaticFunctionNotUsed */ /* COV_VMEM_30_TC3XXINF01_UTILITYCODE_UNUSED */
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType Address)
{
  uint32 sectorIndex = vMem_30_Tc3xxInf01_GetSizeOfMemSector();

  /* InstanceIds are set automatically and set to read-only by ComValidationLib during generation,
   * therefore the id corresponds to index */
  uint32 i;
  for (i = vMem_30_Tc3xxInf01_GetMemSectorStartIdxOfvMemInstance(InstanceId);
      i < vMem_30_Tc3xxInf01_GetMemSectorEndIdxOfvMemInstance(InstanceId);
      i++)
  {
    /* The address may be equal to the start address or even higher. It shall also be lower than the
     * end of the sector (batch). -1 takes care about overflows - the sector batch may be located
     * at the end of the address range. */
    if((Address >= vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(i)) &&
        (Address <= (vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(i) +
            (((vMem_30_Tc3xxInf01_AddressType)(vMem_30_Tc3xxInf01_GetNrOfSectorsOfMemSector(i)) * vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(i)) - 1u))))
    {
      sectorIndex = i;
      break;
    }
  }
  return sectorIndex;
}

# define VMEM_30_TC3XXINF01_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VMEM_30_TC3XXINF01_INTSHARED_H */

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Tc3xxInf01_IntShared.h
 *********************************************************************************************************************/
