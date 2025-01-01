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
/*!        \file  Crypto_30_Hwa_Types.h
 *        \brief  vHsm platform hardware abstraction library
 *
 *      \details  This implements the hardware abstraction library which is used by the vHsm Core.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#ifndef CRYPTO_30_HWA_TYPES_H
# define CRYPTO_30_HWA_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Crypto_30_Hwa_Hw_Types.h"

#if (CRYPTO_30_HWA_HARDWARE_PKC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
# include "vSecPrim.h"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) Crypto_30_Hwa_JobPtrType;

/* Workspaces */
/* AES */
typedef struct
{
  uint32 cryptoKeyId;
  uint32 bufferFillLevel;
  uint32 outputLength;
  uint32 driverObjectId;
  uint32 romKeyMapIndex;
  uint8 bufferOut[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES];
  uint8 buffer[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES];
  uint8 keySize;
  boolean bufferOutFull;
  P2CONST(Crypto_PrimitiveInfoType, CRYPTO_30_HWA_VAR_NOINIT, CRYPTO_30_HWA_APPL_DATA) primitiveInfo;
  Crypto_30_Hwa_WorkSpaceAES128_custom custom;
} Crypto_30_Hwa_WorkSpaceAES;

/* AEAD */
typedef struct
{
  uint32 buffer_used;                             /* number of bytes saved in buffer */
  uint32 H[CRYPTO_30_HWA_GHASH_WORDS_PER_BLOCK];  /* the hash subkey */
# if (CRYPTO_30_HWA_GHASH_SPEED_UP >= 4)          /* COV_CRYPTO_30_HWA_GHASH_SPEED_UP */
  uint32 M[256][4];                               /* the precomputation table */
# elif (CRYPTO_30_HWA_GHASH_SPEED_UP >= 1)        /* COV_CRYPTO_30_HWA_GHASH_SPEED_UP */
  uint32 M[16][4];                                /* the precomputation table */
# endif
  uint8 buffer[CRYPTO_30_HWA_GHASH_BLOCK_SIZE];   /* the input buffer */
  uint8 Y[CRYPTO_30_HWA_GHASH_BLOCK_SIZE];        /* the hash state buffer */
} Crypto_30_Hwa_GhashStruct;

/* Workspace structure for Polyval */
typedef struct
{
  Crypto_30_Hwa_GhashStruct wsGHash;
  uint32 fieldElement1[4];
  uint32 fieldElement2[4];
  uint8 tmp[CRYPTO_30_HWA_GHASH_BLOCK_SIZE];
} Crypto_30_Hwa_PolyvalStruct;

typedef struct
{
  uint32 cryptoKeyId;
  uint32 bufferFillLevel;
  uint32 outputLength;
  uint32 driverObjectId;
  uint32 romKeyMapIndex;
  uint32 processedLengthAad;
  uint32 processedLengthInput;
  uint8 buffer[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES];
  uint8 ivPadded[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES];
  boolean processingFinishedAad;
  P2CONST(Crypto_PrimitiveInfoType, CRYPTO_30_HWA_VAR_NOINIT, CRYPTO_30_HWA_APPL_DATA) primitiveInfo;
  Crypto_30_Hwa_WorkSpaceGCM_custom custom;
} Crypto_30_Hwa_WorkSpaceGCM;

typedef struct
{
  uint32 cryptoKeyId;
  uint32 driverObjectId;
  uint32 romKeyMapIndex;
  uint8 keyAuth[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES];
  uint8 keyCipher[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES];
  uint8 ghashValue[CRYPTO_30_HWA_GHASH_BLOCK_SIZE];
  uint8 tag[CRYPTO_30_HWA_GHASH_BLOCK_SIZE];
  uint8 nonce[CRYPTO_30_HWA_AESGCM_IV_LENGTH_BYTES];
  uint8 counterCtr[CRYPTO_30_HWA_AESGCMSIV_CTR_SIZE_BYTES];
  Crypto_VerifyResultType verify;
  Crypto_30_Hwa_PolyvalStruct polyvalStruct;
  P2CONST(Crypto_PrimitiveInfoType, CRYPTO_30_HWA_VAR_NOINIT, CRYPTO_30_HWA_APPL_DATA) primitiveInfo;
  Crypto_30_Hwa_WorkSpaceGCMSIV_custom custom;
} Crypto_30_Hwa_WorkSpaceGCMSIV;

/* CMAC */
typedef struct
{
  uint32 cryptoKeyId;
  uint32 bufferFillLevel;
  uint32 driverObjectId;
  uint32 romKeyMapIndex;
  P2CONST(uint8, CRYPTO_30_HWA_VAR_NOINIT, CRYPTO_30_HWA_APPL_DATA) remainingDataPtr;
  uint8 buffer[CRYPTO_30_HWA_AES_BLOCK_SIZE_BYTES];
# if (CRYPTO_30_HWA_HARDWARE_CMAC == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  uint8 k1[CRYPTO_30_HWA_AES_KEY_SIZE];
  uint8 k2[CRYPTO_30_HWA_AES_KEY_SIZE];
# endif
  P2CONST(Crypto_PrimitiveInfoType, CRYPTO_30_HWA_VAR_NOINIT, CRYPTO_30_HWA_APPL_DATA) primitiveInfo;
  Crypto_30_Hwa_WorkSpaceCMACAES_custom custom;
} Crypto_30_Hwa_WorkSpaceCMACAES;

/* SHA256 */
typedef struct
{
  uint32 totalLength;
  uint32 bufferFillLevel;
  uint32 driverObjectId;
  uint8 buffer[CRYPTO_30_HWA_HASH_BLOCK_SIZE_BYTES];
  P2CONST(Crypto_PrimitiveInfoType, CRYPTO_30_HWA_VAR_NOINIT, CRYPTO_30_HWA_APPL_DATA) primitiveInfo;
  Crypto_30_Hwa_WorkSpaceSHA256_custom custom;
} Crypto_30_Hwa_WorkSpaceSHA256;

/* Signature */
typedef struct
{
  Crypto_30_Hwa_WorkSpaceSHA256 sha256Workspace;
#if (CRYPTO_30_HWA_HARDWARE_PKC == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  vSecPrimType_WorkSpaceHash vSecPrim_HashWorkSpace;
#endif
  boolean contextSet;
  boolean contextProcessed;
  boolean signatureSet;
  boolean signatureProcessed;
  uint8 ed25519key[CRYPTO_30_HWA_EDDSA_ED25519_PUBLIC_KEY_SIZE_BYTES];
  uint8 signature[CRYPTO_30_HWA_SIGNATURE_SIZE_BYTES];
  uint8 context[CRYPTO_30_HWA_EDDSA_CONTEXT_MAX_SIZE_BYTE];
  uint8 privKeyHash[64u];
  uint32 contextLength;
  uint32 privKeyHashLength;
  Crypto_30_Hwa_WorkSpaceSignature_custom custom;
} Crypto_30_Hwa_WorkSpaceSignature;

/* Dummy Workspaces */
typedef struct
{
  uint8 dummy;
} Crypto_30_Hwa_WorkSpaceSHA512;

typedef struct
{
  uint8 dummy;
} Crypto_30_Hwa_WorkSpaceSHA1;

typedef struct
{
  uint8 dummy;
} Crypto_30_Hwa_WorkSpaceFIPS186;

typedef struct
{
  uint8 dummy;
} Crypto_30_Hwa_WorkSpaceTRNG;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* CRYPTO_30_HWA_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Types.h
 *********************************************************************************************************************/
