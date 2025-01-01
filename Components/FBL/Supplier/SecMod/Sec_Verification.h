/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the verification component of the HIS security module - Signature verification
 *
 *  \description  Offers signature/checksum verification interface
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

#ifndef SEC_VERIFICATION_H
#define SEC_VERIFICATION_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec_Inc.h"

/* Required for security class DDD with CRC and CRC type in verification parameter */
#include "Sec_Crc.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Verification return codes */
#define SECM_VER_OK        0x00u /**< Verification successful              */
#define SECM_VER_ERROR     0x01u /**< Error occured during verification    */
#define SECM_VER_CRC       0x02u /**< CRC verification failed              */
#define SECM_VER_SIG       0x04u /**< MAC/Signature verification failed    */

/* Verification states (as defined by SecM222 (V1.1)) */
#define kHashInit          0x01u /**< Init signature verification       */
#define kHashCompute       0x02u /**< Computation state                 */
#define kHashFinalize      0x03u /**< Finalize hash (not implemented)   */
#define kSigVerify         0x04u /**< Final tasks                       */

/* Remap verification states */
#define SEC_HASH_NONE      0x00u         /**< Marker for invalid verification state */
#define SEC_HASH_INIT      kHashInit     /**< Init signature verification           */
#define SEC_HASH_COMPUTE   kHashCompute  /**< Computation state                     */
#define SEC_HASH_FINALIZE  kHashFinalize /**< Finalize hash (not implemented)       */
#define SEC_SIG_VERIFY     kSigVerify    /**< Final tasks                           */
#define SEC_CRC_RESTORE    5u            /**< Restore context                       */

/* Masks for operations to be carried out by verification primitives */
#define SEC_UPDATE_OPERATION_DEFAULT         0x00u /**< Initialization and update with intra-segment data   */
#define SEC_UPDATE_OPERATION_ADDRESS_LENGTH  0x01u /**< Update with address and length of segments          */
#define SEC_UPDATE_OPERATION_INTER_SEGMENT   0x02u /**< Update with inter-segment data                      */
#define SEC_UPDATE_OPERATION_VERIFICATION    0x04u /**< Verification against given signature/checksum       */

/** Null pointer for data length (currentDataLength) */
#define SEC_DATA_LENGTH_NULL     ((V_MEMRAM1 SecM_SizeType V_MEMRAM2 V_MEMRAM3 *)V_NULL)
/** Null pointer for verification key */
#define SEC_VERIFY_KEY_NULL      ((SecM_VerifyKeyType)V_NULL)

/**********************************************************************************************************************/

/* Compatibility remapping of configuration defines */

#if defined( SEC_VER_ENABLE_CRC_TOTAL )
# ifndef SEC_ENABLE_CRC_TOTAL
/** Enable CRC total calculation in SecM_Verification */
#  define SEC_ENABLE_CRC_TOTAL
# endif
#endif /* SEC_VER_ENABLE_CRC_TOTAL */
#if defined( SEC_VER_DISABLE_CRC_TOTAL )
# ifndef SEC_DISABLE_CRC_TOTAL
/** Disable CRC total calculation in SecM_Verification */
#  define SEC_DISABLE_CRC_TOTAL
# endif
#endif /* SEC_VER_DISABLE_CRC_TOTAL */

#if defined( SEC_VER_ENABLE_LENGTH_AND_ADDRESS_INPUT )
# ifndef SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH
/** Include address and length information of segments in checksum calculation of SecM_Verification */
#  define SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH
# endif
#endif /* SEC_VER_ENABLE_LENGTH_AND_ADDRESS_INPUT */
#if defined( SEC_VER_DISABLE_LENGTH_AND_ADDRESS_INPUT )
# ifndef SEC_DISABLE_VERIFICATION_ADDRESS_LENGTH
/** Do not include address and length information of segments in checksum calculation of SecM_Verification */
#  define SEC_DISABLE_VERIFICATION_ADDRESS_LENGTH
# endif
#endif /* SEC_VER_DISABLE_LENGTH_AND_ADDRESS_INPUT */

#if defined( SECM_VER_SIG_OFFSET )
# ifndef SEC_VER_SIG_OFFSET
/** Offset of signature value in verification data provided to SecM_Verification */
#  define SEC_VER_SIG_OFFSET  SECM_VER_SIG_OFFSET
# endif
#endif /* SECM_VER_SIG_OFFSET */
#if defined( SECM_VER_CRC_OFFSET )
# ifndef SEC_VER_CRC_OFFSET
/** Offset of CRC value in verification data provided to SecM_Verification */
#  define SEC_VER_CRC_OFFSET  SECM_VER_CRC_OFFSET
# endif
#endif /* SECM_VER_CRC_OFFSET */

/**********************************************************************************************************************/

/* Size definitions for checksum/signature values */
/** Size of MD5 hash */
#define SEC_SIZE_HASH_MD5              16u
/** Size of SHA-1 hash */
#define SEC_SIZE_HASH_SHA1             20u
/** Size of SHA-224 hash */
#define SEC_SIZE_HASH_SHA224           28u
/** Size of SHA-256 hash */
#define SEC_SIZE_HASH_SHA256           32u
/** Size of SHA-384 hash */
#define SEC_SIZE_HASH_SHA384           48u
/** Size of SHA-512 hash */
#define SEC_SIZE_HASH_SHA512           64u
/** Size of RIPEMD-160 hash */
#define SEC_SIZE_HASH_RMD160           20u
/** Size of AES CMAC */
#define SEC_SIZE_CMAC_AES              16u
/** Size of RSA-512 signature */
#define SEC_SIZE_SIG_RSA512            64u
/** Size of RSA-1024 signature */
#define SEC_SIZE_SIG_RSA1024           128u
/** Size of RSA-1536 signature */
#define SEC_SIZE_SIG_RSA1536           192u
/** Size of RSA-2048 signature */
#define SEC_SIZE_SIG_RSA2048           256u
/** Size of RSA-3072 signature */
#define SEC_SIZE_SIG_RSA3072           384u
/** Size of RSA-4096 signature */
#define SEC_SIZE_SIG_RSA4096           512u
/** Size of EC-DSA / Curve25519 (Ed25519) signature */
#define SEC_SIZE_SIG_ECDSA_CURVE25519  64u
/** Size of EC-DSA / Curve P224 signature */
#define SEC_SIZE_SIG_ECDSA_CURVEP224   56u
/** Size of EC-DSA / Curve P256 signature */
#define SEC_SIZE_SIG_ECDSA_CURVEP256   64u
/** Size of EC-DSA / Curve P384 signature */
#define SEC_SIZE_SIG_ECDSA_CURVEP384   96u
/** Default value for vendor specific checksum */
#if defined( SEC_SIZE_CHECKSUM_VENDOR )
#else
# define SEC_SIZE_CHECKSUM_VENDOR      1u
#endif /* SEC_SIZE_CHECKSUM_VENDOR */
/** Size of EC-DSA / Curve25519 (Ed25519) key */
#define SEC_SIZE_KEY_ECDSA_CURVE25519  32u
/** Size of EC-DSA / Curve P256 key */
#define SEC_SIZE_KEY_ECDSA_CURVEP256   64u

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* Types specified by HIS specification */

/** Type of parameter passed to SecM_InitVerification */
typedef SecM_ConstVoidPtrType   SecM_VerifyInitType;
/** Type of parameter passed to SecM_DeinitVerification */
typedef SecM_ConstVoidPtrType   SecM_VerifyDeinitType;

/* Pointer types for function calls from external application */
typedef SecM_StatusType SEC_CALL_TYPE (*pSecInitVerificationFct)     (SecM_VerifyInitType init);
typedef SecM_StatusType SEC_CALL_TYPE (*pSecDeinitVerificationFct)   (SecM_VerifyDeinitType deinit);
typedef SecM_StatusType SEC_CALL_TYPE (*pSecVerificationFct)         (V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
typedef SecM_StatusType SEC_CALL_TYPE (*pSecVerifySignatureFct)      (V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);

/**********************************************************************************************************************/

/* Configuration of verification primitives */

/** Operation to be carried out during verification */
typedef struct
{
   pSecVerifySignatureFct  pFunction;     /**< Pointer to verification function (SecM_VerifySignature compatible) */
   SecM_LengthType         length;        /**< Length of digest (e.g. checksum or signature) */
   SecM_LengthFastType     offset;        /**< Offset of digest in verification data */
   SecM_ByteType           mask;          /**< Masks for operations to be carried out (see SEC_UPDATE_OPERATION_* for details) */
} SecM_VerifyOperationType;

/** Config for verification primitive */
typedef struct
{
   V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 V_MEMROM3 * pOperation; /**< Verification operation */
   V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 *  pContext;   /**< Verification parameter passed to function, used to hold context
                                                                         *   Remark: Members currentHash and currentDataLength have to be set by caller
                                                                         *   either to provide
                                                                         *   - An explicit workspace or use the default ((SecM_ResultBufferType)SEC_DEFAULT_WORKSPACE, SEC_DEFAULT_WORKSPACE_SIZE)
                                                                         *   - An explicit data length variable or ignore it as not required (SEC_DATA_LENGTH_NULL) */
} SecM_VerifyConfigType;

/** Configuration list of verification primitives including contexts */
typedef struct
{
   SecM_VerifyConfigType   pPrimitives;   /**< Pointers to list of primitive operations and contexts */
   SecM_ByteFastType       count;         /**< Number of list entries */
} SecM_VerifyConfigListType;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( __cplusplus )
extern "C" {
#endif

/* Functions specified by HIS specification */

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

void            SecM_InitPowerOnVerification ( void );
SecM_StatusType SecM_InitVerification        ( SecM_VerifyInitType init );
SecM_StatusType SecM_DeinitVerification      ( SecM_VerifyDeinitType deinit );

/**********************************************************************************************************************/

/* Helper functions */

#if defined( SEC_ENABLE_VERIFICATION_DATA_LENGTH )
void SecM_UpdateDataLength                   ( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam );
#endif /* SEC_ENABLE_VERIFICATION_DATA_LENGTH */
#if defined( SEC_ENABLE_VERIFICATION_WRAPPER )
SecM_StatusType SecM_VerificationWrapper     ( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList );
#endif /* SEC_ENABLE_VERIFICATION_WRAPPER */
SecM_StatusType SecM_VerificationBase(V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam,
   const V_MEMRAM1 SecM_VerifyConfigListType V_MEMRAM2 V_MEMRAM3 * pCfgList);

/* Verification functions */

#if defined( SEC_ENABLE_CRC_TOTAL ) || \
    defined( SEC_ENABLE_CRC_WRITTEN )
SecM_StatusType SecM_VerifyChecksumCrc(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
#endif /* SEC_ENABLE_CRC_TOTAL || SEC_ENABLE_CRC_WRITTEN */

#if defined( SEC_ENABLE_VERIFY_CRC )
SecM_StatusType SecM_VerifyCrc(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId);
#endif /* SEC_ENABLE_VERIFY_CRC */
#if defined( SEC_ENABLE_VERIFY_HASH )
SecM_StatusType SecM_VerifyHash(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId);
#endif /* SEC_ENABLE_VERIFY_HASH */
#if defined( SEC_ENABLE_VERIFY_MAC )
SecM_StatusType SecM_VerifyMac(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId);
#endif /* SEC_ENABLE_VERIFY_MAC */
#if defined( SEC_ENABLE_VERIFY_SIGNATURE )
SecM_StatusType SecM_VerifySig(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam, SecM_WordType primitiveId);
#endif /* SEC_ENABLE_VERIFY_SIGNATURE */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( __cplusplus )
} /* extern "C" */
#endif

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#if ( SEC_VERIFY_BYTES > 0xFFFFu )
# error "Error in configuration: SEC_VERIFY_BYTES exceeds valid range"
#endif /* SEC_VERIFY_BYTES */

#endif /* SEC_VERIFICATION_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC_VERIFICATION.H
 **********************************************************************************************************************/
