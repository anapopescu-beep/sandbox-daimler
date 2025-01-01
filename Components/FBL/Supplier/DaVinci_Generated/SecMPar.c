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
 *            Module: Smh
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecMPar.c
 *   Generation Time: 2023-07-05 16:23:55
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#define SECMPAR_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec.h"
#include "Csm.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
/* PRQA  S 3218 EOF */ /* MD_SecMPar_3218 */
#define SECM_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_AesKey[2] =
{
  { /*  AesKeyValue  */ 
    V_NULL, 
    16u, 
    1u
  }, 
  { /*  AesIvValue  */ 
    V_NULL, 
    16u, 
    5u
  }
};
V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_SmhKey_SecurityAccess[1] =
{
  { /*  SmhKeyValue_SecurityAccess  */ 
    V_NULL, 
    32u, 
    1u
  }
};
V_MEMROM0 static V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 SecM_KeyValueList_SmhKey_Verification[1] =
{
  { /*  SmhKeyValue_Verification  */ 
    V_NULL, 
    32u, 
    1u
  }
};

V_MEMROM0 static V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 verifyConfigSmhSecurityClassDDDConfig[1] =
{
  { /*  SmhSecurityClassDDDConfig  */ 
    SecM_VerifyCrc32, 
    SEC_SIZE_CHECKSUM_CRC_32, 
    0x00000000u, 
    SEC_UPDATE_OPERATION_VERIFICATION
  }
};
V_MEMROM0 static V_MEMROM1 SecM_VerifyOperationType V_MEMROM2 verifyConfigSmhSecurityClassCCCConfig[1] =
{
  { /*  SmhSecurityClassCCCConfig  */ 
    SmhSecurityClassCCC_Ed25519Sha512, 
    SEC_SIZE_SIG_ECDSA_CURVE25519, 
    0x00000000u, 
    ( SEC_UPDATE_OPERATION_VERIFICATION | SEC_UPDATE_OPERATION_ADDRESS_LENGTH )
  }
};

#define SECM_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SECM_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 static V_MEMRAM1 SecM_ByteType V_MEMRAM2 SecM_DigestBuffer_SmhSecurityClassCCCConfig[SEC_SIZE_HASH_SHA512];


#define SECM_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SECM_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SECM_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


V_MEMROM0 V_MEMROM1 SecM_CryptographicKeyType V_MEMROM2 SecM_CryptographicKeys[3] =
{
  { /*  AesKey  */ 
    2u, 
    SecM_KeyValueList_AesKey
  }, 
  { /*  SmhKey_SecurityAccess  */ 
    1u, 
    SecM_KeyValueList_SmhKey_SecurityAccess
  }, 
  { /*  SmhKey_Verification  */ 
    1u, 
    SecM_KeyValueList_SmhKey_Verification
  }
};

V_MEMROM0 V_MEMROM1 SecM_DecPrimitiveType V_MEMROM2 SecM_DecryptionPrimitives[1] =
{
  { /*  SmhDecryptionConfig  */ 
    SecM_DecryptionJob, 
    SmhConf_SmhJob_SmhJob_AesDecryption
  }
};

/* PRQA S 0313 CRCPRIM_TAG */ /* MD_SecMPar_0313 */
V_MEMROM0 V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 SecM_CrcPrimitives[1] =
{
  { /*  SmhSecurityClassDDDConfig  */ 
    SEC_CRC32, 
    (SecM_CRCFunctionGenericType)SecM_ComputeCrc32, 
    SEC_SIZE_CHECKSUM_CRC_32, 
    TRUE, 
    FALSE
  }
};
/* PRQA L:CRCPRIM_TAG */




V_MEMROM0 V_MEMROM1 SecM_RamDataType V_MEMROM2 SecM_SignaturePrimitivesContextBuffs[1] =
{ /*  SmhSecurityClassCCCConfig  */ 
  V_NULL
};

V_MEMROM0 V_MEMROM1 SecM_SigPrimitiveType V_MEMROM2 SecM_SignaturePrimitives[1] =
{
  { /*  SmhSecurityClassCCCConfig  */ 
    SmhConf_SmhJob_SmhJob_SignatureVerify_Ed25519Sha512, 
    SmhConf_SmhJob_SmhJob_Sha512, 
    SecM_DigestBuffer_SmhSecurityClassCCCConfig, 
    SEC_SIZE_HASH_SHA512, 
    0u, 
    V_NULL, 
    FALSE
  }
};



/* PRQA S 0315 JOBINFO_TAG */ /* MD_SecMPar_0315 */
V_MEMROM0 V_MEMROM1 SecM_JobInfoType V_MEMROM2 SecM_JobInfo[6] =
{
  { /*  SmhJob_AesDecryption  */ 
    SECM_DECRYPTION, 
    CsmConf_CsmJob_CsmJob_DecryptionAes128PkcsCbc, 
    CsmConf_CsmKey_CsmKey_Fbl_Decrypt_Aes128_01, 
    SmhConf_SmhCryptographicKeys_AesKey, 
    SEC_KEY_TYPE_AES, 
    V_NULL
  }, 
  { /*  SmhJob_RandomGenerate  */ 
    SECM_RANDOMGENERATE, 
    CsmConf_CsmJob_CsmJob_RandomGenerate, 
    CsmConf_CsmKey_CsmKey_Fbl_Rng_Fips186, 
    SEC_INVALID_SMH_KEY_ID, 
    SEC_KEY_TYPE_NONE, 
    V_NULL
  }, 
  { /*  SmhJob_RandomSeed  */ 
    SECM_RANDOMSEED, 
    SEC_INVALID_CSM_JOB_ID, 
    CsmConf_CsmKey_CsmKey_Fbl_Rng_Fips186, 
    SEC_INVALID_SMH_KEY_ID, 
    SEC_KEY_TYPE_NONE, 
    V_NULL
  }, 
  { /*  SmhJob_Sha512  */ 
    SECM_HASH, 
    CsmConf_CsmJob_CsmJob_Sha512, 
    CsmConf_CsmKey_CsmKey_Fbl_HashDummy_01, 
    SEC_INVALID_SMH_KEY_ID, 
    SEC_KEY_TYPE_NONE, 
    V_NULL
  }, 
  { /*  SmhJob_SignatureVerify_Ed25519Sha512  */ 
    SECM_SIGNATUREVERIFY, 
    CsmConf_CsmJob_CsmJob_SigAsymVer_Ed25519Sha512, 
    CsmConf_CsmKey_CsmKey_Fbl_Signature_Ed25519_01, 
    SmhConf_SmhCryptographicKeys_SmhKey_Verification, 
    SEC_KEY_TYPE_SYMMETRIC, 
    V_NULL
  }, 
  { /*  SmhJob_SecurityAccessVerify_Ed25519Sha512  */ 
    SECM_SIGNATUREVERIFY, 
    CsmConf_CsmJob_CsmJob_SecurityAccess_Ed25519Sha512, 
    CsmConf_CsmKey_CsmKey_Fbl_SecurityAccess_Ed25519, 
    SmhConf_SmhCryptographicKeys_SmhKey_SecurityAccess, 
    SEC_KEY_TYPE_SYMMETRIC, 
    V_NULL
  }
};
/* PRQA L:JOBINFO_TAG */

#define SECM_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SECM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/* Decryption functions */
SecM_StatusType DecryptAes128 ( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock,
   const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam)
{
   return SecM_DecryptionUpdate(pInBlock, pOutBlock, pDecParam, SmhConf_SmhDecryption_SmhDecryptionConfig);
}


SecM_StatusType SecM_VerifyCrc32( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   SecM_StatusType result = SECM_NOT_OK;
   /* Special Workspace handling for CRC */
   static SecM_CRC32ParamType  crc32Param;
   {
      if (pVerifyParam->sigState == SEC_HASH_INIT)
      {
         /* Set internal default workspace */
         pVerifyParam->currentHash.sigResultBuffer = (SecM_ResultBufferType)&crc32Param; /* PRQA S 0306 */ /* MD_SecVerification_0306 */
         pVerifyParam->currentHash.length = sizeof(crc32Param);

      }

      result = SecM_VerifyCrc(pVerifyParam, SmhConf_SmhStreamVerificationCrc_SmhSecurityClassDDDConfig);
   }
   return result;
}

SecM_StatusType SmhSecurityClassCCC_Ed25519Sha512( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   return SecM_VerifySig(pVerifyParam, SmhConf_SmhStreamVerificationSignature_SmhSecurityClassCCCConfig);
}


SecM_StatusType SecM_VerificationClassDDD_Crc32( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   SecM_SignatureParamType    verifyContext[1];
   SecM_VerifyConfigListType  config;

   config.pPrimitives.pOperation = verifyConfigSmhSecurityClassDDDConfig;
   config.pPrimitives.pContext   = verifyContext;
   config.count                  = 1;

   return SecM_VerificationBase(pVerifyParam, &config);
}

SecM_StatusType SecM_VerificationClassCCC_Ed25519Sha512( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam )
{
   SecM_SignatureParamType    verifyContext[1];
   SecM_VerifyConfigListType  config;

   config.pPrimitives.pOperation = verifyConfigSmhSecurityClassCCCConfig;
   config.pPrimitives.pContext   = verifyContext;
   config.count                  = 1;

   return SecM_VerificationBase(pVerifyParam, &config);
}



#define SECM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_SecMPar_0313:
      Reason:     Signature/checksum verification functions are stored as void pointers as actual type is not known at
                  configuration time.
      Risk:       Function signature not compatible with expected type.
      Prevention: Integrator has to take care the configured functions match with the expected signature.

   MD_SecMPar_0315:
      Reason:     The implicit conversion from a pointer to object type to a pointer to void is used to allows pointers 
                  to different object types as parameter.
      Risk:       No risk, because the underlying pointer type is known and the cast is safe.
      Prevention: No prevention necessary.

   MD_SecMPar_3218:
      Reason:     The local variables of this module are kept at a central location for a better overview and maintenance.
      Risk:       Scope is larger than required (whole file instead of one function). Some other function could access
                  the variable.
      Prevention: Restrict the functionality in this module to the intended purpose. Don't add functions which shall not
                  be able to access the local data buffers.

*/
