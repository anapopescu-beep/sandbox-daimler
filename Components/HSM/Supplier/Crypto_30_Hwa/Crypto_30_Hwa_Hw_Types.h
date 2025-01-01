/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Crypto_30_Hwa_Hw_Types.h
 *        \brief  vHsm hardware abstraction platform types
 *
 *      \details  This files defines types for the hardware specific implementation.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_HWA_HW_TYPES_H)
# define CRYPTO_30_HWA_HW_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Crypto_30_Hwa_Hw_Cfg.h"
# include "Csm_Types.h"

# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* do not use this section */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
  uint32 hwKeyslot;
  uint32 hwContext;
  uint32 cipherMode;
} Crypto_30_Hwa_WorkSpaceAES128_custom;

typedef struct
{
  uint32 hwKeyslot;
  uint32 hwContext;
  uint32 cipherMode;
  uint8 key[CRYPTO_30_HWA_AES_KEY_SIZE];
} Crypto_30_Hwa_WorkSpaceGCM_custom;

typedef struct
{
  uint32 hwKeyslot;
  uint32 hwContext;
  uint32 cipherMode;
} Crypto_30_Hwa_WorkSpaceGCMSIV_custom;

typedef struct
{
  uint32 hwKeyslot;
  uint32 hwContext;
  uint32 cipherMode;
} Crypto_30_Hwa_WorkSpaceCMACAES_custom;

typedef struct
{
  uint8 dummy;
} Crypto_30_Hwa_WorkSpaceSHA256_custom;

typedef struct
{
  uint8 dummy;
} Crypto_30_Hwa_WorkSpaceSignature_custom;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* do not use this section */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* do not use this section */

#endif /* CRYPTO_30_HWA_HW_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Hw_Types.h
 *********************************************************************************************************************/
