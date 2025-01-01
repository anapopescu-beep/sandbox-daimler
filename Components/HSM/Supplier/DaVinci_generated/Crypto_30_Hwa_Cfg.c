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
 *            Module: Crypto_30_Hwa
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_Hwa_Cfg.c
 *   Generation Time: 2023-04-04 15:31:22
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_Hwa_Cfg.h"
#include "Crypto_30_Hwa.h"
#include "vSecPrim.h"
/* PRQA S 1533 EOF */ /* MD_CSL_ObjectOnlyAccessedOnce */
/* PRQA S 0759 EOF */ /* MD_MSR_Union */



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL)
# define CRYPTO_30_HWA_LOCAL static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE)
# define CRYPTO_30_HWA_LOCAL_INLINE LOCAL_INLINE
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
  Crypto_30_Hwa_AesDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_AesDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_AesDecryptType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesDecrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                         Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.AesDecrypt }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_AesEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_AesEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_AesEncryptType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesEncrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                         Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.AesEncrypt }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_AesGcmDecrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_AesGcmDecrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_AesGcmDecryptType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesGcmDecrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                            Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.AesGcmDecrypt }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_AesGcmEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_AesGcmEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_AesGcmEncryptType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_AesGcmEncrypt[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                            Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.AesGcmEncrypt }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_CmacAesGenerate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_CmacAesGenerate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_CmacAesGenerateType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_CmacAesGenerate[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                       Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio.CmacAesGenerate },  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa_HighPrio] */
  { /*     1 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.CmacAesGenerate          }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_CmacAesVerify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_CmacAesVerify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_CmacAesVerifyType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_CmacAesVerify[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                     Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio.CmacAesVerify },  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa_HighPrio] */
  { /*     1 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.CmacAesVerify          }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_Ed25519Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_Ed25519Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_Ed25519GenerateType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_Ed25519Generate[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                              Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.Ed25519Generate }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_Ed25519Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_Ed25519Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_Ed25519VerifyType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_Ed25519Verify[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                            Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.Ed25519Verify }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_FamilyToHashMapping
**********************************************************************************************************************/
#define CRYPTO_30_HWA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_FamilyToHashMappingType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_FamilyToHashMapping[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     FamilyToHashMapping               Referable Keys */
  /*     0 */ 0xFFu                        ,  /* [CRYPTO_ALGOFAM_NOT_SET] */
  /*     1 */ VSECPRIM_DIGEST_SHA1         ,  /* [CRYPTO_ALGOFAM_SHA1] */
  /*     2 */ VSECPRIM_DIGEST_SHA2_224     ,  /* [CRYPTO_ALGOFAM_SHA2_224] */
  /*     3 */ VSECPRIM_DIGEST_SHA2_256     ,  /* [CRYPTO_ALGOFAM_SHA2_256] */
  /*     4 */ VSECPRIM_DIGEST_SHA2_384     ,  /* [CRYPTO_ALGOFAM_SHA2_384] */
  /*     5 */ VSECPRIM_DIGEST_SHA2_512     ,  /* [CRYPTO_ALGOFAM_SHA2_512] */
  /*     6 */ VSECPRIM_DIGEST_SHA2_512_224 ,  /* [CRYPTO_ALGOFAM_SHA2_512_224] */
  /*     7 */ VSECPRIM_DIGEST_SHA2_512_256    /* [CRYPTO_ALGOFAM_SHA2_512_256] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_KeyMap
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_KeyMap
  \brief  Contains keys of Crypto_30_Hwa, accessible by external KeyId reduced by offset of 30000.
  \details
  Element                  Description
  AggregatedCryptoKeyId
  KeyId                
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_KeyMapType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_KeyMap[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AggregatedCryptoKeyId  KeyId         Referable Keys */
  { /*     0 */ 0xFFFFFFFFu          , 30001u },  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoKeys/CryptoKey_Fbl_Fips186] */
  { /*     1 */ 0xFFFFFFFFu          , 30002u },  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoKeys/CryptoKey_Fbl_HashDummy] */
  { /*     2 */ 0xFFFFFFFFu          , 30004u },  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoKeys/RomKey0] */
  { /*     3 */ 0xFFFFFFFFu          , 30005u }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoKeys/vHsm_Hal_Hardware] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_ObjectInfo
  \details
  Element               Description
  MaskedBits            contains bitcoded the boolean data of Crypto_30_Hwa_AesDecryptUsedOfObjectInfo, Crypto_30_Hwa_AesEncryptUsedOfObjectInfo, Crypto_30_Hwa_AesGcmDecryptUsedOfObjectInfo, Crypto_30_Hwa_AesGcmEncryptUsedOfObjectInfo, Crypto_30_Hwa_CmacAesGenerateUsedOfObjectInfo, Crypto_30_Hwa_CmacAesVerifyUsedOfObjectInfo, Crypto_30_Hwa_Ed25519GenerateUsedOfObjectInfo, Crypto_30_Hwa_Ed25519VerifyUsedOfObjectInfo, Crypto_30_Hwa_TrngUsedOfObjectInfo
  AesDecryptIdx         the index of the 0:1 relation pointing to Crypto_30_Hwa_AesDecrypt
  AesEncryptIdx         the index of the 0:1 relation pointing to Crypto_30_Hwa_AesEncrypt
  AesGcmDecryptIdx      the index of the 0:1 relation pointing to Crypto_30_Hwa_AesGcmDecrypt
  AesGcmEncryptIdx      the index of the 0:1 relation pointing to Crypto_30_Hwa_AesGcmEncrypt
  CmacAesGenerateIdx    the index of the 0:1 relation pointing to Crypto_30_Hwa_CmacAesGenerate
  CmacAesVerifyIdx      the index of the 0:1 relation pointing to Crypto_30_Hwa_CmacAesVerify
  Ed25519GenerateIdx    the index of the 0:1 relation pointing to Crypto_30_Hwa_Ed25519Generate
  Ed25519VerifyIdx      the index of the 0:1 relation pointing to Crypto_30_Hwa_Ed25519Verify
  TrngIdx               the index of the 0:1 relation pointing to Crypto_30_Hwa_Trng
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_ObjectInfoType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_ObjectInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  AesDecryptIdx                               AesEncryptIdx                               AesGcmDecryptIdx                               AesGcmEncryptIdx                               CmacAesGenerateIdx  CmacAesVerifyIdx  Ed25519GenerateIdx                               Ed25519VerifyIdx                               TrngIdx                                     Referable Keys */
  { /*     0 */    0x0018u, CRYPTO_30_HWA_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_HWA_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_HWA_NO_AESGCMDECRYPTIDXOFOBJECTINFO, CRYPTO_30_HWA_NO_AESGCMENCRYPTIDXOFOBJECTINFO,                 0u,               0u, CRYPTO_30_HWA_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_HWA_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_HWA_NO_TRNGIDXOFOBJECTINFO },  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa_HighPrio] */
  { /*     1 */    0x01FFu,                                         0u,                                         0u,                                            0u,                                            0u,                 1u,               1u,                                              0u,                                            0u,                                   0u }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_Trng
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_Trng
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_Hwa_TrngType, CRYPTO_30_HWA_CONST) Crypto_30_Hwa_Trng[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                   Referable Keys */
  { /*     0 */ &Crypto_30_Hwa_UnionWS_vHsm_Hwa.Trng }   /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */
};
#define CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_DriverObjectState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_DriverObjectState
  \brief  State of the current workspace usage.
*/ 
#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_Hwa_DriverObjectStateUType, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_DriverObjectState;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa_HighPrio] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */

#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_Lock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_Lock
  \brief  Id of job that currently occupies the workspace
*/ 
#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_Hwa_LockUType, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_Lock;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa_HighPrio] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa] */

#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_UnionWS_vHsm_Hwa
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_UnionWS_vHsm_Hwa
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa.
*/ 
#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_Hwa_UnionWS_vHsm_Hwa_Type, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_UnionWS_vHsm_Hwa;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio
**********************************************************************************************************************/
/** 
  \var    Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_Hwa/CryptoDriverObjects/vHsm_Hwa_HighPrio.
*/ 
#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio_Type, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_UnionWS_vHsm_Hwa_HighPrio;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */





/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Cfg.c
 *********************************************************************************************************************/
