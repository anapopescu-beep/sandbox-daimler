/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_ApiInternal.h
 *        \brief  Internal used Api to minimize dependencies to the LibCv driver
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_APIINTERNAL_H)
# define VHSM_APIINTERNAL_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "vHsm_Api.h"

# include "Crypto_30_LibCv.h"
# include "Crypto_30_LibCv_Services.h"
# include "Crypto_30_LibCv_KeyManagement.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* Persisting */
# define vHsm_Api_NvM_Persist                                         Crypto_30_LibCv_NvM_Persist

/* Key storage access */
# define vHsm_Api_SetKeyStorage                                       Crypto_30_LibCv_SetKeyStorage
# define vHsm_Api_GetKeyStorage                                       Crypto_30_LibCv_GetKeyStorage
# define vHsm_Api_GetKeyStorageDirectAccess                           Crypto_30_LibCv_GetAddrKeyStorage
# define vHsm_Api_KeyStorageOffsetType                                Crypto_30_LibCv_KeyStorageEndIdxOfKeyElementsType
# define vHsm_Api_GetKeyStorageStartIdxOfKeyElements                  Crypto_30_LibCv_GetKeyStorageStartIdxOfKeyElements
# define vHsm_Api_GetKeyStorageWrittenLengthStartIdxOfKeyElements     Crypto_30_LibCv_GetKeyStorageWrittenLengthStartIdxOfKeyElements

/* Key element set */
# define vHsm_Api_KeyElementSetInternalStandard                       Crypto_30_LibCv_KeyElementSetInternalStandard
# define vHsm_Api_KeyElementSetInternal                               Crypto_30_LibCv_Local_KeyElementSetInternal

/* Other key element stuff */
# define vHsm_Api_SetKeyElementStateByMask                            Crypto_30_LibCv_SetKeyElementStateByMask
# define vHsm_Api_SetKeyElementValid(elementIndex)                    Crypto_30_LibCv_SetKeyElementStateByMask(elementIndex, CRYPTO_30_LIBCV_KEYELEMENTSTATE_VALID_MASK);
# define vHsm_Api_KeyElementsIterType                                 Crypto_30_LibCv_KeyElementsIterType
# define vHsm_Api_GetKeyElementLength                                 Crypto_30_LibCv_GetKeyElementLength
# define vHsm_Api_GetKeyElementsStartIdxOfKey                         Crypto_30_LibCv_GetKeyElementsStartIdxOfKey
# define vHsm_Api_GetKeyElementsEndIdxOfKey                           Crypto_30_LibCv_GetKeyElementsEndIdxOfKey
# define vHsm_Api_GetKeyElementState                                  Crypto_30_LibCv_GetKeyElementState
# define vHsm_Api_ClearKeyElementStateByMask                          Crypto_30_LibCv_ClearKeyElementStateByMask
# define vHsm_Api_GetIdOfKeyElements                                  Crypto_30_LibCv_GetIdOfKeyElements
# define vHsm_Api_IsPersistOfKeyElementInfo                           Crypto_30_LibCv_IsPersistOfKeyElementInfo
# define vHsm_Api_GetKeyElementInfoIdxOfKeyElements                   Crypto_30_LibCv_GetKeyElementInfoIdxOfKeyElements
# define vHsm_Api_GetSizeOfKey                                        Crypto_30_LibCv_GetSizeOfKey
# define vHsm_Api_GetKeyStorageEndIdxOfKeyElements                    Crypto_30_LibCv_GetKeyStorageEndIdxOfKeyElements
# define vHsm_Api_SetWrittenLength(elementIndex, keyElementLength)    Crypto_30_LibCv_SetKeyStorage(Crypto_30_LibCv_GetKeyStorageWrittenLengthStartIdxOfKeyElements(elementIndex), (uint8)((keyElementLength >> 8u) & 0xFFu)); \
                                                                      Crypto_30_LibCv_SetKeyStorage(Crypto_30_LibCv_GetKeyStorageWrittenLengthStartIdxOfKeyElements(elementIndex) + 1u, (uint8)(keyElementLength & 0xFFu));
# define vHsm_Api_IsKeyElementValid                                   Crypto_30_LibCv_IsKeyElementValid

# define VHSM_ALIGNMENT_MASK_32BIT                                    (sizeof(uint32) - 1u)
# define VHSM_IS_PTR_32BIT_ALIGNED(ptr)                               (((uint32)ptr & VHSM_ALIGNMENT_MASK_32BIT) == 0u)
# define VHSM_IS_PTR_NOT_32BIT_ALIGNED(ptr)                           (((uint32)ptr & VHSM_ALIGNMENT_MASK_32BIT) != 0u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_APIINTERNAL_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_ApiInternal.h
 *********************************************************************************************************************/
