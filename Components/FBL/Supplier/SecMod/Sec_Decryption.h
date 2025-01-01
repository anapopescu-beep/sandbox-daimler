/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - Decryption
 *
 *  \description  Offers API for decryption and encryption
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#ifndef SEC_DECRYPTION_H
#define SEC_DECRYPTION_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec_Inc.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/**********************************************************************************************************************/

/** Default value for operation mode */
#define SEC_DECRYPTION_MODE_DEFAULT                0x00u

/** Bit mask for implicit / explicit initialization vector */
#define SEC_DECRYPTION_MODE_IV                     0x01u

/* Modifiers for operation mode */
/** Initialize operation on first call */
#define SEC_DECRYPTION_MODE_INIT                   0x10u
/** Finalize operation on last call */
#define SEC_DECRYPTION_MODE_FINALIZE               0x20u

/* Compatibility defines for decryption/encryption primitive identifiers passes in data format identifier
 * Not relevant any more, configuration settings used instead */
/** AES 128 primitive using PKCS7 padding, CBC mode and implicit initialization vector (= 0) */
#define SEC_DECRYPTION_MODE_AES_128_PKCS_CBC      SEC_DECRYPTION_MODE_DEFAULT
/** AES 128 primitive using PKCS7 padding, CBC mode and explicit initialization vector */
#define SEC_DECRYPTION_MODE_AES_128_PKCS_CBC_IV   (SEC_DECRYPTION_MODE_DEFAULT | SEC_DECRYPTION_MODE_IV)
/** AES 192 primitive using PKCS7 padding, CBC mode and implicit initialization vector (= 0) */
#define SEC_DECRYPTION_MODE_AES_192_PKCS_CBC      SEC_DECRYPTION_MODE_DEFAULT
/** AES 192 primitive using PKCS7 padding, CBC mode and explicit initialization vector */
#define SEC_DECRYPTION_MODE_AES_192_PKCS_CBC_IV   (SEC_DECRYPTION_MODE_DEFAULT | SEC_DECRYPTION_MODE_IV)
/** AES 256 primitive using PKCS7 padding, CBC mode and implicit initialization vector (= 0) */
#define SEC_DECRYPTION_MODE_AES_256_PKCS_CBC      SEC_DECRYPTION_MODE_DEFAULT
/** AES 256 primitive using PKCS7 padding, CBC mode and explicit initialization vector */
#define SEC_DECRYPTION_MODE_AES_256_PKCS_CBC_IV   (SEC_DECRYPTION_MODE_DEFAULT | SEC_DECRYPTION_MODE_IV)

/** Block size of AES primitive */
# define SEC_DECRYPTION_BLOCK_SIZE_AES             0x10u
/** Compatibility define of block size */
# define SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC    SEC_DECRYPTION_BLOCK_SIZE_AES

/**********************************************************************************************************************/

/* Remap compile-time switches */

#if defined( SEC_ENABLE_DECRYPTION ) || defined( SEC_ENABLE_ENCRYPTION )
# define SEC_ENABLE_SECURITY_CLASS_AAA
#endif /* SEC_ENABLE_DECRYPTION || SEC_ENABLE_ENCRYPTION */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* Types specified by HIS specification */
#if defined( SEC_ENABLE_DECRYPTION ) || defined( SEC_ENABLE_ENCRYPTION )
/** Type of parameter passed to SecM_InitDecryption */
typedef SecM_ConstVoidPtrType   SecM_DecInitType;
/** Type of parameter passed to SecM_DeinitDecryption */
typedef SecM_ConstVoidPtrType   SecM_DecDeinitType;

/* Pointer types for API-functions */
typedef SecM_StatusType SEC_CALL_TYPE (* pSecInitDecryptionFct)( SecM_DecInitType init );
typedef SecM_StatusType SEC_CALL_TYPE (* pSecDeinitDecryptionFct)( SecM_DecDeinitType deinit );
typedef SecM_StatusType SEC_CALL_TYPE (* pSecDecryptionFct)( V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * inBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * outBlock,
   const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * decParam );
#endif  /* SEC_ENABLE_DECRYPTION || SEC_ENABLE_ENCRYPTION */
/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_DECRYPTION ) || defined( SEC_ENABLE_ENCRYPTION )
/* Functions specified by HIS specification */
SecM_StatusType SecM_InitDecryption( SecM_DecInitType init );
SecM_StatusType SecM_DeinitDecryption( SecM_DecDeinitType deinit );
SecM_StatusType SecM_Decryption( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock,
   V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam );
SecM_StatusType SecM_InitEncryption( SecM_DecInitType init );
SecM_StatusType SecM_DeinitEncryption( SecM_DecDeinitType deinit );
SecM_StatusType SecM_Encryption( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock,
   V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pEncParam );
/* Helper functions */
SecM_StatusType SecM_DecryptionUpdate(const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock,
   const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam,
   SecM_WordType smhId);
#endif /* SEC_ENABLE_DECRYPTION || SEC_ENABLE_ENCRYPTION */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( __cplusplus )
} /* extern "C" */
#endif

#endif /* SEC_DECRYPTION_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC_DECRYPTION.H
 **********************************************************************************************************************/
