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
 *            Module: Crypto_30_LibCv
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_LibCv_Cfg.c
 *   Generation Time: 2023-07-05 16:23:55
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_LibCv_Cfg.h"
#include "Crypto_30_LibCv.h"
#include "Crypto_30_LibCv_Services.h"
/* PRQA S 0759 EOF */ /* MD_CSL_18.4 */
/*lint -e91 */
#include "Crypto_30_LibCv_Decrypt.h"
#include "Crypto_30_LibCv_Hash.h"
#include "Crypto_30_LibCv_RandomGenerate.h"
#include "Crypto_30_LibCv_SignatureVerify.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYPTO_30_LIBCV_LOCAL)
# define CRYPTO_30_LIBCV_LOCAL static
#endif

#if !defined (CRYPTO_30_LIBCV_LOCAL_INLINE)
# define CRYPTO_30_LIBCV_LOCAL_INLINE LOCAL_INLINE
#endif




/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Crypto_30_LibCv_AesDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_AesDecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesDecrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                             Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes.primWS.AesDecrypt }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Ed25519Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Ed25519Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_Ed25519VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519Verify[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                            Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv.primWS.Ed25519Verify }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_FamilyToHashMapping
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_FamilyToHashMappingType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_FamilyToHashMapping[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     FamilyToHashMapping               Referable Keys */
  /*     0 */ 0xFFu                        ,  /* [CRYPTO_ALGOFAM_NOT_SET] */
  /*     1 */ 0xFFu                        ,  /* [CRYPTO_ALGOFAM_SHA1] */
  /*     2 */ 0xFFu                        ,  /* [CRYPTO_ALGOFAM_SHA2_224] */
  /*     3 */ 0xFFu                        ,  /* [CRYPTO_ALGOFAM_SHA2_256] */
  /*     4 */ VSECPRIM_DIGEST_SHA2_384     ,  /* [CRYPTO_ALGOFAM_SHA2_384] */
  /*     5 */ VSECPRIM_DIGEST_SHA2_512     ,  /* [CRYPTO_ALGOFAM_SHA2_512] */
  /*     6 */ VSECPRIM_DIGEST_SHA2_512_224 ,  /* [CRYPTO_ALGOFAM_SHA2_512_224] */
  /*     7 */ VSECPRIM_DIGEST_SHA2_512_256    /* [CRYPTO_ALGOFAM_SHA2_512_256] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Fips186
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Fips186
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_Fips186Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Fips186[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                          Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv.primWS.Fips186     },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng.primWS.Fips186 }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Hash
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Hash
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_HashType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Hash[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                   Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_Crypto_30_LibCv.primWS.Hash }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_InitValue
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_InitValueType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_InitValue[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitValue      Referable Keys */
  /*     0 */         0u   /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Key
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Key
  \details
  Element                Description
  KeyElementsEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
  KeyElementsStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyElements
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Key[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    KeyElementsEndIdx  KeyElementsStartIdx        Referable Keys */
  { /*     0 */                1u,                  0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Signature_Ed25519] */
  { /*     1 */                3u,                  1u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Decrypt_Aes128] */
  { /*     2 */                5u,                  3u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Fips186] */
  { /*     3 */                6u,                  5u }   /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_HashDummy] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElementInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElementInfo
  \details
  Element              Description
  Id               
  InitValueEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  InitValueStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_InitValue
  Length           
  MaskedBits           contains bitcoded the boolean data of Crypto_30_LibCv_OnceOfKeyElementInfo, Crypto_30_LibCv_PartialOfKeyElementInfo, Crypto_30_LibCv_PersistOfKeyElementInfo
  Read             
  Write            
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyElementInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfo[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  InitValueEndIdx                                     InitValueStartIdx                                     Length  MaskedBits  Read                        Write                             Referable Keys */
  { /*     0 */ 1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  { /*     1 */ 1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  { /*     2 */ 5u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  { /*     3 */ 3u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    20u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Seed] */
  { /*     4 */ 4u,                                                 1u,                                                   0u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1] */
  { /*     5 */ 1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    20u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED }   /* [/ActiveEcuC/Crypto/CryptoKeyElements/Crypto_30_LibCv_Hash_Result] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyElements
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyElements
  \details
  Element                            Description
  Id                             
  KeyElementInfoIdx                  the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyElementInfo
  KeyStorageEndIdx                   the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageExtensionIdx             the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx                 the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageValidIdx                 the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageWrittenLengthEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageWrittenLengthStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyElementsType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElements[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  KeyElementInfoIdx  KeyStorageEndIdx  KeyStorageExtensionIdx  KeyStorageStartIdx  KeyStorageValidIdx  KeyStorageWrittenLengthEndIdx  KeyStorageWrittenLengthStartIdx        Referable Keys */
  { /*     0 */ 1u,                0u,              36u,                     3u,                 4u,                 2u,                            2u,                              0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Signature_Ed25519, CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  { /*     1 */ 1u,                1u,              56u,                    39u,                40u,                38u,                           38u,                             36u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Decrypt_Aes128, CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  { /*     2 */ 5u,                2u,              76u,                    59u,                60u,                58u,                           58u,                             56u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Decrypt_Aes128, CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  { /*     3 */ 3u,                3u,             100u,                    79u,                80u,                78u,                           78u,                             76u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Fips186, CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Seed] */
  { /*     4 */ 4u,                4u,             105u,                   103u,               104u,               102u,                          102u,                            100u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Fips186, CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1] */
  { /*     5 */ 1u,                5u,             129u,                   108u,               109u,               107u,                          107u,                            105u }   /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_HashDummy, CryptoKey_Fbl_HashDummy__Crypto_30_LibCv_Hash_Result] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfo
  \details
  Element                     Description
  WorkspaceLength             Holds the length of the workspace.
  AesDecryptIdx               the index of the 0:1 relation pointing to Crypto_30_LibCv_AesDecrypt
  Ed25519VerifyIdx            the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Verify
  Fips186Idx                  the index of the 0:1 relation pointing to Crypto_30_LibCv_Fips186
  HashIdx                     the index of the 0:1 relation pointing to Crypto_30_LibCv_Hash
  QueueIdx                    the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue
  RandomSeedBufferEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  RandomSeedBufferStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_RandomSeedBuffer
  WorkspaceAddr               Holds the address of the workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_ObjectInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    WorkspaceLength                                      AesDecryptIdx                                 Ed25519VerifyIdx                                 Fips186Idx                                 HashIdx                                 QueueIdx  RandomSeedBufferEndIdx                                 RandomSeedBufferStartIdx                                 WorkspaceAddr                                                                                            Referable Keys */
  { /*     0 */ sizeof(Crypto_30_LibCv_WS_Crypto_30_LibCv_Type)    , CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO,                                              0u,                                        0u,                                     0u,       0u,                                                   21u,                                                      0u, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_Crypto_30_LibCv     },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA512, Fips186, Ed25519Verify] */
  { /*     1 */ sizeof(Crypto_30_LibCv_WS_Crypto_30_LibCv_Aes_Type),                                           0u, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_FIPS186IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_HASHIDXOFOBJECTINFO,       1u, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERENDIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_RANDOMSEEDBUFFERSTARTIDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes },  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes, AesDecrypt] */
  { /*     2 */ sizeof(Crypto_30_LibCv_WS_Crypto_30_LibCv_Rng_Type), CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO,                                        1u, CRYPTO_30_LIBCV_NO_HASHIDXOFOBJECTINFO,       2u,                                                   42u,                                                     21u, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng, Fips186] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_ObjectInfoInd
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_ObjectInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Crypto_30_LibCv_ObjectInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_ObjectInfoIndType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoInd[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ObjectInfoInd      Referable Keys */
  /*     0 */             1u,  /* [AesDecrypt] */
  /*     1 */             0u,  /* [SHA512] */
  /*     2 */             0u,  /* [Fips186] */
  /*     3 */             2u,  /* [Fips186] */
  /*     4 */             0u   /* [Ed25519Verify] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveFct
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveFct
  \details
  Element                  Description
  ObjectInfoIndEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  ObjectInfoIndStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_ObjectInfoInd
  Dispatch             
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveFctType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFct[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIndEndIdx  ObjectInfoIndStartIdx  Dispatch                                      Referable Keys */
  { /*     0 */                  1u,                    0u, Crypto_30_LibCv_Dispatch_AesDecrypt    },  /* [AesDecrypt] */
  { /*     1 */                  2u,                    1u, Crypto_30_LibCv_Dispatch_Hash          },  /* [SHA512] */
  { /*     2 */                  4u,                    2u, Crypto_30_LibCv_Dispatch_Fips186       },  /* [Fips186] */
  { /*     3 */                  5u,                    4u, Crypto_30_LibCv_Dispatch_Ed25519Verify }   /* [Ed25519Verify] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveInfo
  \details
  Element            Description
  Combined       
  MaskedBits         contains bitcoded the boolean data of Crypto_30_LibCv_ContextOfPrimitiveInfo, Crypto_30_LibCv_DefaultRandomSourceOfPrimitiveInfo
  PrimitiveFctIdx    the index of the 1:1 relation pointing to Crypto_30_LibCv_PrimitiveFct
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfo[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Combined                                                                                                                                                                          MaskedBits  PrimitiveFctIdx        Referable Keys */
  { /*     0 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                             ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     1 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7)),      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     2 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     3 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                             ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     4 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7)),      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     5 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     6 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                             ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     7 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7)),      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     8 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     9 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_512) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                       ,      0x00u,              1u },  /* [CRYPTO_HASH] */
  { /*    10 */ ((((uint32)CRYPTO_RANDOMGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_RNG) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                  ,      0x00u,              2u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*    11 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))             ,      0x00u,              3u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    12 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))            ,      0x00u,              3u }   /* [CRYPTO_SIGNATUREVERIFY] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_PrimitiveServiceInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_PrimitiveServiceInfo
  \details
  Element                  Description
  PrimitiveInfoEndIdx      the end index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
  PrimitiveInfoStartIdx    the start index of the 0:n relation pointing to Crypto_30_LibCv_PrimitiveInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_PrimitiveServiceInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveServiceInfo[20] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PrimitiveInfoEndIdx                                           PrimitiveInfoStartIdx                                                 Referable Keys */
  { /*     0 */                                                          10u,                                                             9u },  /* [CRYPTO_HASH] */
  { /*     1 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_MACGENERATE] */
  { /*     2 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_MACVERIFY] */
  { /*     3 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_ENCRYPT] */
  { /*     4 */                                                           9u,                                                             0u },  /* [CRYPTO_DECRYPT] */
  { /*     5 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_AEADENCRYPT] */
  { /*     6 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_AEADDECRYPT] */
  { /*     7 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*     8 */                                                          13u,                                                            11u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*     9 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERINCREMENT] */
  { /*    10 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERREAD] */
  { /*    11 */                                                          11u,                                                            10u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*    12 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_RANDOMSEED] */
  { /*    13 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYGENERATE] */
  { /*    14 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYDERIVE] */
  { /*    15 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYEXCHANGECALCPUBVAL] */
  { /*    16 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_KEYEXCHANGECALCSECRET] */
  { /*    17 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_CERTIFICATEPARSE] */
  { /*    18 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_CERTIFICATEVERIFY] */
  { /*    19 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO }   /* [CRYPTO_KEYSETVALID] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_BufferLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_BufferLength
  \brief  Buffer which holds the current seed of the Fips186 algorithm to restore the needed workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_BufferLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLength[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA512, Fips186, Ed25519Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes, AesDecrypt] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng, Fips186] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_DriverObjectState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_DriverObjectState
  \brief  State of the current workspace usage.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_DriverObjectStateType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectState[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA512, Fips186, Ed25519Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes, AesDecrypt] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng, Fips186] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyLock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyLock
  \brief  Stores locking counter of each key
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_KeyLockUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyLock;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Signature_Ed25519] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Decrypt_Aes128] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_Fips186] */
  /*     3 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Fbl_HashDummy] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyStorage
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_KeyStorageType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStorage[129];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__WrittenLength__, RAM_KEY] */
  /*     1 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__WrittenLength__, RAM_KEY] */
  /*     2 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Valid__, RAM_KEY] */
  /*     3 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Extension__, RAM_KEY] */
  /*     4 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Data__, RAM_KEY] */
  /*    35 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Data__, RAM_KEY] */
  /*    36 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__WrittenLength__, RAM_KEY] */
  /*    37 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__WrittenLength__, RAM_KEY] */
  /*    38 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Valid__, RAM_KEY] */
  /*    39 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Extension__, RAM_KEY] */
  /*    40 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Data__, RAM_KEY] */
  /*    55 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Data__, RAM_KEY] */
  /*    56 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__WrittenLength__, RAM_KEY] */
  /*    57 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__WrittenLength__, RAM_KEY] */
  /*    58 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Valid__, RAM_KEY] */
  /*    59 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Extension__, RAM_KEY] */
  /*    60 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Data__, RAM_KEY] */
  /*    75 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Data__, RAM_KEY] */
  /*    76 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Seed__WrittenLength__, RAM_KEY] */
  /*    77 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Seed__WrittenLength__, RAM_KEY] */
  /*    78 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Seed__Valid__, RAM_KEY] */
  /*    79 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Seed__Extension__, RAM_KEY] */
  /*    80 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*    99 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*   100 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__WrittenLength__, RAM_KEY] */
  /*   101 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__WrittenLength__, RAM_KEY] */
  /*   102 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__Valid__, RAM_KEY] */
  /*   103 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__Extension__, RAM_KEY] */
  /*   104 */  /* [CryptoKey_Fbl_Fips186__Crypto_30_LibCv_Random_Algorithm_Fips186_Sha1__Data__, RAM_KEY] */
  /*   105 */  /* [CryptoKey_Fbl_HashDummy__Crypto_30_LibCv_Hash_Result__WrittenLength__, RAM_KEY] */
  /*   106 */  /* [CryptoKey_Fbl_HashDummy__Crypto_30_LibCv_Hash_Result__WrittenLength__, RAM_KEY] */
  /*   107 */  /* [CryptoKey_Fbl_HashDummy__Crypto_30_LibCv_Hash_Result__Valid__, RAM_KEY] */
  /*   108 */  /* [CryptoKey_Fbl_HashDummy__Crypto_30_LibCv_Hash_Result__Extension__, RAM_KEY] */
  /*   109 */  /* [CryptoKey_Fbl_HashDummy__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_HashDummy__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */
  /*   128 */  /* [CryptoKey_Fbl_HashDummy__Crypto_30_LibCv_Hash_Result__Data__, RAM_KEY] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Lock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Lock
  \brief  Id of job that currently occupies the workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_LockType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Lock[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA512, Fips186, Ed25519Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes, AesDecrypt] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng, Fips186] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Queue
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Queue
  \brief  Acts as job queue for all driver objects.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_QueueUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Queue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_RandomSeedBuffer
**********************************************************************************************************************/
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_RandomSeedBufferUType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_RandomSeedBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  /*    20 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv] */
  /*    21 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng] */
  /*   ... */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng] */
  /*    41 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_Crypto_30_LibCv
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Aes_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Aes;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_Crypto_30_LibCv_Rng_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_Crypto_30_LibCv_Rng;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_WrittenLength
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_WrittenLength
  \brief  Holds the length which needs to be written in a next step for some algorithms.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WrittenLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLength[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv, SHA512, Fips186, Ed25519Verify] */
  /*     1 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Aes, AesDecrypt] */
  /*     2 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/Crypto_30_LibCv_Rng, Fips186] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_LibCv_Cfg.c
 *********************************************************************************************************************/
