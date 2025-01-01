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
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_LibCv_Cfg.c
 *   Generation Time: 2023-11-29 15:42:21
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
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
#include "Crypto_30_LibCv_Encrypt.h"
#include "Crypto_30_LibCv_Hash.h"
#include "Crypto_30_LibCv_KeyGenerate.h"
#include "Crypto_30_LibCv_MacGenerate.h"
#include "Crypto_30_LibCv_MacVerify.h"
#include "Crypto_30_LibCv_RandomGenerate.h"
#include "Crypto_30_LibCv_SignatureGenerate.h"
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
CONST(Crypto_30_LibCv_AesDecryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesDecrypt[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.AesDecrypt             },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio.primWS.AesDecrypt    },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio] */
  { /*     2 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Dec.primWS.AesDecrypt }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Dec] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_AesEncrypt
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_AesEncrypt
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_AesEncryptType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_AesEncrypt[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.AesEncrypt             },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio.primWS.AesEncrypt    },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio] */
  { /*     2 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Enc.primWS.AesEncrypt }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Enc] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_CmacAesGenerate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_CmacAesGenerate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_CmacAesGenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesGenerate[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                     Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.CmacAesGenerate             },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio.primWS.CmacAesGenerate    },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio] */
  { /*     2 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Mac.primWS.CmacAesGenerate }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Mac] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_CmacAesVerify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_CmacAesVerify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_CmacAesVerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_CmacAesVerify[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.CmacAesVerify          },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio.primWS.CmacAesVerify }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_DRBGAES
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_DRBGAES
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_DRBGAESType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_DRBGAES[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                          Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.DRBGAES          },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio.primWS.DRBGAES }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_EcP256Verify
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_EcP256Verify
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_EcP256VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_EcP256Verify[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                  Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.EcP256Verify             },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_KeyM.primWS.EcP256Verify        },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_KeyM] */
  { /*     2 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Sig.primWS.EcP256Verify }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_Ed25519Generate
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_Ed25519Generate
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_Ed25519GenerateType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519Generate[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                         Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.Ed25519Generate }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
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
CONST(Crypto_30_LibCv_Ed25519VerifyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Ed25519Verify[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                                   Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.Ed25519Verify             },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Sig.primWS.Ed25519Verify }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig] */
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
CONST(Crypto_30_LibCv_InitValueType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_InitValue[1067] = {  /* PRQA S 1514, 1533, 0612, 0613 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index     InitValue      Referable Keys */
  /*     0 */        35u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     1 */       228u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     2 */       245u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     3 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     4 */        37u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     5 */       147u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     6 */        31u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     7 */       229u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     8 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*     9 */       193u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*    10 */       172u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*    11 */       104u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*    12 */        23u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*    13 */        96u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*    14 */        19u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*    15 */        99u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  /*    16 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128] */
  /*    17 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    18 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    19 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    20 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  /*    21 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    22 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    23 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    24 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    25 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    26 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    27 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    28 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    29 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    30 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    31 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    32 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    33 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    34 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    35 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    36 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  /*    37 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Proof] */
  /*    38 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Proof] */
  /*    39 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Proof] */
  /*    40 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Proof] */
  /*    41 */       146u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    42 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    43 */        42u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    44 */        76u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    45 */       146u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    46 */        59u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    47 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    48 */        33u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    49 */       126u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /* Index     InitValue      Referable Keys */
  /*    50 */        27u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    51 */       176u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    52 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    53 */       141u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    54 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    55 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    56 */        27u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  /*    57 */        83u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    58 */       112u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    59 */       101u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    60 */       122u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    61 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    62 */        97u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    63 */       108u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    64 */        69u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    65 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    66 */        87u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    67 */       111u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    68 */       109u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    69 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    70 */       115u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    71 */        97u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    72 */       117u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  /*    73 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    74 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    75 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    76 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    77 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    78 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    79 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    80 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    81 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    82 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    83 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    84 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    85 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    86 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    87 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    88 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  /*    89 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    90 */       130u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    91 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    92 */       141u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    93 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    94 */       130u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    95 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    96 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    97 */       160u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    98 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*    99 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /* Index     InitValue      Referable Keys */
  /*   100 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   101 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   102 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   103 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   104 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   105 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   106 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   107 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   108 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   109 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   110 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   111 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   112 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   113 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   114 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   115 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   116 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   117 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   118 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   119 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   120 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   121 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   122 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   123 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   124 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   125 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   126 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   127 */        14u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   128 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   129 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   130 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   131 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   132 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   133 */        12u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   134 */         7u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   135 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   136 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   137 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   138 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   139 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   140 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   141 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   142 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   143 */        32u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   144 */        23u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   145 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   146 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   147 */        56u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   148 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   149 */        54u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /* Index     InitValue      Referable Keys */
  /*   150 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   151 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   152 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   153 */        51u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   154 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   155 */        54u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   156 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   157 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   158 */        90u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   159 */        24u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   160 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   161 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   162 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   163 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   164 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   165 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   166 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   167 */        51u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   168 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   169 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   170 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   171 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   172 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   173 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   174 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   175 */        90u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   176 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   177 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   178 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   179 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   180 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   181 */        14u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   182 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   183 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   184 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   185 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   186 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   187 */        12u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   188 */         7u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   189 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   190 */        66u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   191 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   192 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   193 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   194 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   195 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   196 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   197 */        52u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   198 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   199 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /* Index     InitValue      Referable Keys */
  /*   200 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   201 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   202 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   203 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   204 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   205 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   206 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   207 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   208 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   209 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   210 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   211 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   212 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   213 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   214 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   215 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   216 */        33u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   217 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   218 */        30u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   219 */       241u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   220 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   221 */       228u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   222 */       197u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   223 */       179u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   224 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   225 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   226 */       209u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   227 */       249u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   228 */       232u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   229 */        84u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   230 */       126u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   231 */        87u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   232 */       210u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   233 */       166u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   234 */        41u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   235 */       127u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   236 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   237 */       175u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   238 */       162u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   239 */        58u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   240 */       241u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   241 */       104u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   242 */       230u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   243 */        40u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   244 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   245 */       241u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   246 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   247 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   248 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   249 */       195u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /* Index     InitValue      Referable Keys */
  /*   250 */       163u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   251 */       129u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   252 */       153u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   253 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   254 */       129u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   255 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   256 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   257 */        23u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   258 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   259 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   260 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   261 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   262 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   263 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   264 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   265 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   266 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   267 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   268 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   269 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   270 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   271 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   272 */       101u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   273 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   274 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   275 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   276 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   277 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   278 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   279 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   280 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   281 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   282 */        23u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   283 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   284 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   285 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   286 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   287 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   288 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   289 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   290 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   291 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   292 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   293 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   294 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   295 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   296 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   297 */       107u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   298 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   299 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /* Index     InitValue      Referable Keys */
  /*   300 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   301 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   302 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   303 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   304 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   305 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   306 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   307 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   308 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   309 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   310 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   311 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   312 */        14u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   313 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   314 */        22u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   315 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   316 */        20u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   317 */       128u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   318 */       221u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   319 */        69u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   320 */        88u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   321 */       204u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   322 */       132u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   323 */       204u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   324 */        10u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   325 */       193u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   326 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   327 */       213u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   328 */        24u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   329 */       236u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   330 */       166u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   331 */        69u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   332 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   333 */        91u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   334 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   335 */        20u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   336 */        54u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   337 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   338 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   339 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   340 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   341 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   342 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   343 */        19u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   344 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   345 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   346 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   347 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   348 */         8u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   349 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /* Index     InitValue      Referable Keys */
  /*   350 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   351 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   352 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   353 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   354 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   355 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   356 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   357 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   358 */        14u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   359 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   360 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   361 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   362 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   363 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   364 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   365 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   366 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   367 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   368 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   369 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   370 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   371 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   372 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   373 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   374 */        31u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   375 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   376 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   377 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   378 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   379 */        35u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   380 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   381 */        24u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   382 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   383 */        22u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   384 */       128u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   385 */        20u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   386 */        95u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   387 */       134u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   388 */       107u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   389 */       171u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   390 */       107u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   391 */       135u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   392 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   393 */       237u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   394 */        44u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   395 */       245u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   396 */        71u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   397 */       112u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   398 */       223u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   399 */       205u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /* Index     InitValue      Referable Keys */
  /*   400 */       161u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   401 */        64u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   402 */       123u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   403 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   404 */       176u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   405 */       171u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   406 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   407 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   408 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   409 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   410 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   411 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   412 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   413 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   414 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   415 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   416 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   417 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   418 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   419 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   420 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   421 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   422 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   423 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   424 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   425 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   426 */       144u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   427 */       226u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   428 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   429 */        60u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   430 */        24u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   431 */       123u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   432 */       173u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   433 */       164u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   434 */        30u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   435 */       113u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   436 */       198u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   437 */       202u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   438 */       219u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   439 */       123u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   440 */       132u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   441 */       202u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   442 */       229u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   443 */        62u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   444 */       216u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   445 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   446 */       153u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   447 */         8u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   448 */        21u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   449 */         9u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /* Index     InitValue      Referable Keys */
  /*   450 */        60u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   451 */       207u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   452 */        98u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   453 */       244u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   454 */       206u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   455 */        60u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   456 */       129u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   457 */        21u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   458 */       156u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   459 */       116u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   460 */       135u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   461 */       180u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   462 */       118u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   463 */       121u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   464 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   465 */       253u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   466 */        11u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   467 */       136u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   468 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   469 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   470 */       155u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   471 */        41u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   472 */       109u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   473 */        40u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   474 */       219u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   475 */       186u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   476 */        20u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   477 */       205u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   478 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   479 */        88u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   480 */        51u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   481 */        27u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   482 */        90u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   483 */       163u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   484 */        36u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   485 */       128u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   486 */        62u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   487 */       142u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   488 */        70u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   489 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  /*   490 */       251u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   491 */       187u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   492 */       240u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   493 */        79u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   494 */       120u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   495 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   496 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   497 */        39u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   498 */       107u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   499 */       147u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /* Index     InitValue      Referable Keys */
  /*   500 */        19u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   501 */        88u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   502 */       235u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   503 */       237u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   504 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   505 */        33u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   506 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   507 */       225u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   508 */       249u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   509 */        58u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   510 */       149u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   511 */        89u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   512 */       133u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   513 */       221u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   514 */       247u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   515 */       188u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   516 */        32u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   517 */       136u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   518 */       219u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   519 */       136u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   520 */       197u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   521 */       135u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  /*   522 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF] */
  /*   523 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   524 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   525 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   526 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   527 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   528 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   529 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   530 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   531 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   532 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   533 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   534 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   535 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   536 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   537 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   538 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  /*   539 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   540 */       130u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   541 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   542 */       106u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   543 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   544 */       130u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   545 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   546 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   547 */       160u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   548 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   549 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /* Index     InitValue      Referable Keys */
  /*   550 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   551 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   552 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   553 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   554 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   555 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   556 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   557 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   558 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   559 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   560 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   561 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   562 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   563 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   564 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   565 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   566 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   567 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   568 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   569 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   570 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   571 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   572 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   573 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   574 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   575 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   576 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   577 */        14u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   578 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   579 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   580 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   581 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   582 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   583 */        12u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   584 */         7u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   585 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   586 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   587 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   588 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   589 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   590 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   591 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   592 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   593 */        32u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   594 */        23u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   595 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   596 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   597 */        56u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   598 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   599 */        54u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /* Index     InitValue      Referable Keys */
  /*   600 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   601 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   602 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   603 */        51u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   604 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   605 */        54u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   606 */        52u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   607 */        51u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   608 */        90u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   609 */        24u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   610 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   611 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   612 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   613 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   614 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   615 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   616 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   617 */        51u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   618 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   619 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   620 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   621 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   622 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   623 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   624 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   625 */        90u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   626 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   627 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   628 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   629 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   630 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   631 */        14u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   632 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   633 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   634 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   635 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   636 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   637 */        12u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   638 */         7u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   639 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   640 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   641 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   642 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   643 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   644 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   645 */        49u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   646 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   647 */        52u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   648 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   649 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /* Index     InitValue      Referable Keys */
  /*   650 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   651 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   652 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   653 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   654 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   655 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   656 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   657 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   658 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   659 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   660 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   661 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   662 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   663 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   664 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   665 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   666 */        33u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   667 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   668 */        62u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   669 */        75u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   670 */        91u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   671 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   672 */        73u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   673 */       252u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   674 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   675 */       193u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   676 */       226u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   677 */        70u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   678 */       164u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   679 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   680 */       149u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   681 */       221u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   682 */       141u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   683 */       146u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   684 */        45u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   685 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   686 */       243u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   687 */        20u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   688 */       135u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   689 */       216u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   690 */       169u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   691 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   692 */       241u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   693 */       192u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   694 */       246u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   695 */        37u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   696 */        10u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   697 */         9u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   698 */        79u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   699 */       173u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /* Index     InitValue      Referable Keys */
  /*   700 */       163u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   701 */       119u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   702 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   703 */       117u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   704 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   705 */        23u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   706 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   707 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   708 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   709 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   710 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   711 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   712 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   713 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   714 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   715 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   716 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   717 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   718 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   719 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   720 */       101u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   721 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   722 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   723 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   724 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   725 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   726 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   727 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   728 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   729 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   730 */        23u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   731 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   732 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   733 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   734 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   735 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   736 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   737 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   738 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   739 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   740 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   741 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   742 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   743 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   744 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   745 */       107u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   746 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   747 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   748 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   749 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /* Index     InitValue      Referable Keys */
  /*   750 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   751 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   752 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   753 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   754 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   755 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   756 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   757 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   758 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   759 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   760 */        14u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   761 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   762 */        22u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   763 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   764 */        20u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   765 */        95u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   766 */       134u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   767 */       107u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   768 */       171u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   769 */       107u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   770 */       135u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   771 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   772 */       237u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   773 */        44u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   774 */       245u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   775 */        71u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   776 */       112u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   777 */       223u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   778 */       205u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   779 */       161u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   780 */        64u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   781 */       123u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   782 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   783 */       176u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   784 */       171u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   785 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   786 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   787 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   788 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   789 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   790 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   791 */        19u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   792 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   793 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   794 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   795 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   796 */         8u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   797 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   798 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   799 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /* Index     InitValue      Referable Keys */
  /*   800 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   801 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   802 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   803 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   804 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   805 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   806 */        14u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   807 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   808 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   809 */        85u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   810 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   811 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   812 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   813 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   814 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   815 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   816 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   817 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   818 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   819 */         2u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   820 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   821 */        48u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   822 */        15u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   823 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   824 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   825 */        43u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   826 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   827 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   828 */         4u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   829 */         1u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   830 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   831 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   832 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   833 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   834 */       131u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   835 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   836 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   837 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   838 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   839 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   840 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   841 */        11u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   842 */        52u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   843 */        98u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   844 */       153u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   845 */       234u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   846 */       255u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   847 */       187u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   848 */        10u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   849 */       220u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /* Index     InitValue      Referable Keys */
  /*   850 */       213u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   851 */        60u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   852 */       114u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   853 */       154u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   854 */        40u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   855 */       228u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   856 */       153u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   857 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   858 */        59u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   859 */       142u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   860 */        80u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   861 */       238u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   862 */       161u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   863 */        62u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   864 */        31u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   865 */        30u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   866 */       159u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   867 */       233u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   868 */       136u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   869 */       232u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   870 */       102u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   871 */        45u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   872 */         5u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   873 */        64u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   874 */       224u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   875 */       249u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   876 */       242u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   877 */        30u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   878 */       186u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   879 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   880 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   881 */       182u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   882 */       113u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   883 */       195u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   884 */        91u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   885 */        91u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   886 */        35u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   887 */        64u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   888 */       139u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   889 */        53u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   890 */       108u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   891 */       229u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   892 */        34u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   893 */       198u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   894 */       104u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   895 */       183u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   896 */       152u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   897 */       194u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   898 */        83u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   899 */       118u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /* Index     InitValue      Referable Keys */
  /*   900 */        80u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   901 */       235u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   902 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   903 */       192u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   904 */        13u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  /*   905 */         0u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_Algorithm_X25519] */
  /*   906 */        63u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   907 */       125u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   908 */       217u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   909 */        93u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   910 */        27u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   911 */        81u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   912 */       165u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   913 */       162u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   914 */        66u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   915 */        54u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   916 */        61u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   917 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   918 */       108u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   919 */       199u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   920 */        61u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   921 */        19u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   922 */       205u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   923 */       147u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   924 */       180u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   925 */       175u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   926 */       156u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   927 */        10u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   928 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   929 */       231u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   930 */       225u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   931 */        59u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   932 */       235u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   933 */        74u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   934 */       198u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   935 */       211u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   936 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   937 */       211u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*   938 */       112u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   939 */         6u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   940 */       151u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   941 */       134u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   942 */       216u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   943 */       225u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   944 */        27u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   945 */       254u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   946 */        98u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   947 */       231u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   948 */       145u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   949 */        61u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /* Index     InitValue      Referable Keys */
  /*   950 */        65u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   951 */       225u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   952 */        50u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   953 */       120u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   954 */       111u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   955 */         8u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   956 */       169u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   957 */       234u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   958 */       117u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   959 */       217u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   960 */        96u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   961 */       112u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   962 */       162u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   963 */        25u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   964 */       248u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   965 */        96u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   966 */         9u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   967 */       240u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   968 */       166u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   969 */        47u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  /*   970 */         3u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519] */
  /*   971 */       240u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   972 */        45u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   973 */        92u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   974 */        21u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   975 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   976 */       217u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   977 */       143u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   978 */       205u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   979 */        92u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   980 */       244u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   981 */       217u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   982 */        68u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   983 */       215u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   984 */       172u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   985 */        87u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   986 */       146u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   987 */        19u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   988 */       172u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   989 */       253u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   990 */       225u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   991 */       149u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   992 */        90u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   993 */        87u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   994 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   995 */       218u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   996 */       145u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   997 */       100u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   998 */        93u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*   999 */       148u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /* Index     InitValue      Referable Keys */
  /*  1000 */        37u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*  1001 */       170u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*  1002 */        98u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  /*  1003 */       215u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1004 */        62u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1005 */       218u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1006 */       171u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1007 */       115u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1008 */        34u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1009 */        81u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1010 */       150u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1011 */       202u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1012 */        12u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1013 */       127u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1014 */        39u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1015 */       225u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1016 */       219u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1017 */       225u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1018 */        33u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1019 */        32u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1020 */       110u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1021 */       202u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1022 */        64u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1023 */       141u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1024 */       189u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1025 */        82u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1026 */        25u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1027 */       215u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1028 */       178u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1029 */       161u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1030 */       238u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1031 */        99u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1032 */       233u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1033 */        54u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1034 */       247u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  /*  1035 */       146u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1036 */        18u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1037 */        42u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1038 */        76u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1039 */       146u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1040 */        59u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1041 */        57u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1042 */        33u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1043 */       126u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1044 */        27u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1045 */       176u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1046 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1047 */       141u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1048 */       105u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1049 */        29u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /* Index     InitValue      Referable Keys */
  /*  1050 */        27u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  /*  1051 */       198u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1052 */       154u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1053 */       147u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1054 */       194u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1055 */       229u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1056 */       223u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1057 */        17u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1058 */        66u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1059 */       240u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1060 */       193u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1061 */       121u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1062 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1063 */        22u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1064 */        16u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1065 */        51u,  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  /*  1066 */        97u   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
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
  NvBlockIdx             the index of the 0:1 relation pointing to Crypto_30_LibCv_NvBlock
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Key[54] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    KeyElementsEndIdx  KeyElementsStartIdx  NvBlockIdx                                Referable Keys */
  { /*     0 */                2u,                  0u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_PduKeysMac] */
  { /*     1 */                7u,                  2u,                                 0u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_TRNG] */
  { /*     2 */                9u,                  7u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1] */
  { /*     3 */               10u,                  9u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelBackendPeer] */
  { /*     4 */               13u,                 10u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Custom] */
  { /*     5 */               14u,                 13u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelIntermediatePeer] */
  { /*     6 */               16u,                 14u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_AesRamKey] */
  { /*     7 */               17u,                 16u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelEcuPeer] */
  { /*     8 */               19u,                 17u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Decrypt] */
  { /*     9 */               21u,                 19u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_PT4_PTCoor4] */
  { /*    10 */               23u,                 21u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Encrypt] */
  { /*    11 */               25u,                 23u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_VehSpd_8] */
  { /*    12 */               26u,                 25u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Mac] */
  { /*    13 */               27u,                 26u,                                 6u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_BackendCert] */
  { /*    14 */               28u,                 27u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelRoot] */
  { /*    15 */               30u,                 28u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer] */
  { /*    16 */               31u,                 30u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Signature] */
  { /*    17 */               32u,                 31u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelBackend] */
  { /*    18 */               34u,                 32u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx] */
  { /*    19 */               35u,                 34u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelIntermediate] */
  { /*    20 */               37u,                 35u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx] */
  { /*    21 */               39u,                 37u,                                 5u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Info] */
  { /*    22 */               40u,                 39u,                                 5u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SecurityAccessPublicKey] */
  { /*    23 */               45u,                 40u,                                 5u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RandomSeed] */
  { /*    24 */               47u,                 45u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx] */
  { /*    25 */               49u,                 47u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx] */
  { /*    26 */               50u,                 49u,                                 7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RootCert] */
  { /*    27 */               51u,                 50u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_Cert_Root] */
  { /*    28 */               53u,                 51u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx] */
  { /*    29 */               54u,                 53u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_ECC_Intermediate] */
  { /*    30 */               59u,                 54u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretExchangeKey] */
  { /*    31 */               60u,                 59u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_ECC_Root] */
  { /*    32 */               61u,                 60u,                                 2u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretHash] */
  { /*    33 */               62u,                 61u,                                 5u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelPrivateEcu_LiveKey] */
  { /*    34 */               63u,                 62u,                                 5u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuPublic_LiveKey] */
  { /*    35 */               64u,                 63u,                                 5u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuPublicCsr_StagingKey] */
  { /*    36 */               66u,                 64u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_Authentication] */
  { /*    37 */               68u,                 66u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_VIN] */
  { /*    38 */               70u,                 68u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RealTime] */
  { /*    39 */               72u,                 70u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TickCount] */
  { /*    40 */               73u,                 72u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SignatureRamKey] */
  { /*    41 */               75u,                 73u,                                 1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_Ign_Stat] */
  { /*    42 */               76u,                 75u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SignatureRamKey_replacementAuthority] */
  { /*    43 */               79u,                 76u,                                 5u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelPrivateEcuUnique_StagingKey] */
  { /*    44 */               80u,                 79u,                                 3u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelBackendCert_inHSM] */
  { /*    45 */               81u,                 80u,                                 4u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelRootCert_inHSM] */
  { /*    46 */               82u,                 81u,                                 3u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelIntermediateCert_inHSM] */
  { /*    47 */               83u,                 82u,                                 3u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuCert_inHSM] */
  { /*    48 */               86u,                 83u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPrivateKey] */
  { /*    49 */               89u,                 86u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPublicKey] */
    /* Index    KeyElementsEndIdx  KeyElementsStartIdx  NvBlockIdx                                Referable Keys */
  { /*    50 */               90u,                 89u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_Signature_Ed25519] */
  { /*    51 */               91u,                 90u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_SecurityAccess_Ed25519] */
  { /*    52 */               93u,                 91u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_Decrypt_Aes128] */
  { /*    53 */               94u,                 93u, CRYPTO_30_LIBCV_NO_NVBLOCKIDXOFKEY }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHSM_Custom_HSM_Version] */
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
CONST(Crypto_30_LibCv_KeyElementInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfo[47] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id     InitValueEndIdx                                     InitValueStartIdx                                     Length  MaskedBits  Read                        Write                             Referable Keys */
  { /*     0 */    1u,                                                16u,                                                   0u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_nonPersisting] */
  { /*     1 */    2u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,     4u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_MacKey_Hash_nonPersisting] */
  { /*     2 */    3u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x01u, CRYPTO_30_LIBCV_RA_DENIED , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128] */
  { /*     3 */    4u,                                                17u,                                                  16u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128] */
  { /*     4 */ 3015u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_PrivateString] */
  { /*     5 */ 3016u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_AdditionalInput] */
  { /*     6 */ 3018u,                                                21u,                                                  17u,     4u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_DENIED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Reseed_Counter] */
  { /*     7 */    1u,                                                37u,                                                  21u,    16u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Key] */
  { /*     8 */    2u,                                                41u,                                                  37u,     4u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Mac_Proof] */
  { /*     9 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key] */
  { /*    10 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Cipher_Key] */
  { /*    11 */    5u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Cipher_IV] */
  { /*    12 */    6u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    48u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Cipher_Proof] */
  { /*    13 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Cipher_Key] */
  { /*    14 */    5u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Cipher_IV] */
  { /*    15 */    1u,                                                57u,                                                  41u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_DENIED , CRYPTO_30_LIBCV_WA_DENIED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Decrypt_Key] */
  { /*    16 */    5u,                                                73u,                                                  57u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_DENIED , CRYPTO_30_LIBCV_WA_DENIED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_IV] */
  { /*    17 */    1u,                                                89u,                                                  73u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_DENIED , CRYPTO_30_LIBCV_WA_DENIED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_FirmwareUpdate_Internal_Key] */
  { /*    18 */    0u,                                               490u,                                                  89u,   600u,      0x03u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_BackendCert] */
  { /*    19 */ 3021u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_Info_Uid] */
  { /*    20 */ 3023u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x03u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_Info_ErrorLog] */
  { /*    21 */    1u,                                               522u,                                                 490u,    32u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SecurityAccesPublicKey] */
  { /*    22 */    3u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    20u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Seed] */
  { /*    23 */    4u,                                               523u,                                                 522u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF] */
  { /*    24 */  999u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,   209u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/CryptoKeyElement_DummyWorkaround_RandomSeedSize] */
  { /*    25 */ 3017u,                                               539u,                                                 523u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_Random_Nonce] */
  { /*    26 */    0u,                                               905u,                                                 539u,   600u,      0x03u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_RootCert] */
  { /*    27 */    0u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,  1500u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyM_CertificateData] */
  { /*    28 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_SharedValue] */
  { /*    29 */    8u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_Base] */
  { /*    30 */    9u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_PrivKey] */
  { /*    31 */   10u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*    32 */   12u,                                               906u,                                                 905u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyExchange_Algorithm_X25519] */
  { /*    33 */    2u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,     4u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_SharedSecretHash] */
  { /*    34 */    1u,                                               938u,                                                 906u,    32u,      0x01u, CRYPTO_30_LIBCV_RA_DENIED , CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelPrivateEcu_LiveKey] */
  { /*    35 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelEcuPublic_LiveKey] */
  { /*    36 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModelEcuPublicCsr_StagingKey] */
  { /*    37 */    1u,                                               970u,                                                 938u,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_DENIED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  { /*    38 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x01u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyGenerate_Key] */
  { /*    39 */   17u,                                               971u,                                                 970u,     1u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519] */
  { /*    40 */    0u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,  1000u,      0x03u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/CryptoKeyElement_Cert_wPersist] */
  { /*    41 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Ssa_TrustModel_Csr_Key_NonPersisting_Element] */
  { /*    42 */    1u,                                              1003u,                                                 971u,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  { /*    43 */    1u,                                              1035u,                                                1003u,    32u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  { /*    44 */    1u,                                              1051u,                                                1035u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  { /*    45 */    5u,                                              1067u,                                                1051u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  { /*    46 */    1u, CRYPTO_30_LIBCV_NO_INITVALUEENDIDXOFKEYELEMENTINFO, CRYPTO_30_LIBCV_NO_INITVALUESTARTIDXOFKEYELEMENTINFO,     3u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeyElements/vHsm_Version] */
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
  Element               Description
  Id                
  KeyStorageEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyElementInfoIdx     the index of the 1:1 relation pointing to Crypto_30_LibCv_KeyElementInfo
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyElementsType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElements[94] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id     KeyStorageEndIdx  KeyStorageStartIdx  KeyElementInfoIdx        Referable Keys */
  { /*     0 */    1u,            6696u,              6680u,                0u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_PduKeysMac, Ssa_PduKeysMac__Ssa_MacKey_nonPersisting] */
  { /*     1 */    2u,            6704u,              6700u,                1u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_PduKeysMac, Ssa_PduKeysMac__Ssa_MacKey_Hash_nonPersisting] */
  { /*     2 */    3u,              36u,                 4u,                2u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_TRNG, vHsm_TRNG__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128] */
  { /*     3 */    4u,            5917u,              5916u,                3u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_TRNG, vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128] */
  { /*     4 */ 3015u,            5940u,              5924u,                4u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_TRNG, vHsm_TRNG__Crypto_30_LibCv_Random_PrivateString] */
  { /*     5 */ 3016u,            5960u,              5944u,                5u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_TRNG, vHsm_TRNG__Crypto_30_LibCv_Random_AdditionalInput] */
  { /*     6 */ 3018u,              44u,                40u,                6u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_TRNG, vHsm_TRNG__Crypto_30_LibCv_Random_Reseed_Counter] */
  { /*     7 */    1u,             176u,               160u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Key] */
  { /*     8 */    2u,             184u,               180u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1, SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Proof] */
  { /*     9 */    1u,            8488u,              8456u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelBackendPeer, KeyM_SigVerifyKey_TrustModelBackendPeer__Crypto_30_LibCv_Signature_Key] */
  { /*    10 */    1u,            8300u,              8284u,               10u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Custom, vHsm_Custom__Crypto_30_LibCv_Cipher_Key] */
  { /*    11 */    5u,            8320u,              8304u,               11u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Custom, vHsm_Custom__Crypto_30_LibCv_Cipher_IV] */
  { /*    12 */    6u,            8372u,              8324u,               12u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Custom, vHsm_Custom__Crypto_30_LibCv_Cipher_Proof] */
  { /*    13 */    1u,            6640u,              6608u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelIntermediatePeer, KeyM_SigVerifyKey_TrustModelIntermediatePeer__Crypto_30_LibCv_Signature_Key] */
  { /*    14 */    1u,            8432u,              8416u,               13u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_AesRamKey, Ssa_AesRamKey__Ssa_Cipher_Key] */
  { /*    15 */    5u,            8452u,              8436u,               14u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_AesRamKey, Ssa_AesRamKey__Ssa_Cipher_IV] */
  { /*    16 */    1u,            6676u,              6644u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelEcuPeer, KeyM_SigVerifyKey_TrustModelEcuPeer__Crypto_30_LibCv_Signature_Key] */
  { /*    17 */    1u,            8392u,              8376u,               15u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Decrypt, vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_Decrypt_Key] */
  { /*    18 */    5u,            8412u,              8396u,               16u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Decrypt, vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_IV] */
  { /*    19 */    1u,             204u,               188u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_PT4_PTCoor4, SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Key] */
  { /*    20 */    2u,             212u,               208u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_PT4_PTCoor4, SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Proof] */
  { /*    21 */    1u,            6284u,              6268u,               17u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Encrypt, vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_Internal_Key] */
  { /*    22 */    5u,            6304u,              6288u,               16u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Encrypt, vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_IV] */
  { /*    23 */    1u,             232u,               216u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_VehSpd_8, SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Key] */
  { /*    24 */    2u,             240u,               236u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_VehSpd_8, SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Proof] */
  { /*    25 */    1u,            6324u,              6308u,               17u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Mac, vHsm_FirmwareUpdate_Mac__vHsm_FirmwareUpdate_Internal_Key] */
  { /*    26 */    0u,            5308u,              4708u,               18u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_BackendCert, Ssa_BackendCert__Ssa_BackendCert] */
  { /*    27 */    1u,            6532u,              6500u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelRoot, KeyM_SigVerifyKey_TrustModelRoot__Crypto_30_LibCv_Signature_Key] */
  { /*    28 */    1u,             260u,               244u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Key] */
  { /*    29 */    2u,             268u,               264u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer, SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Proof] */
  { /*    30 */    1u,            6360u,              6328u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Signature, vHsm_FirmwareUpdate_Signature__Crypto_30_LibCv_Signature_Key] */
  { /*    31 */    1u,            6568u,              6536u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelBackend, KeyM_SigVerifyKey_TrustModelBackend__Crypto_30_LibCv_Signature_Key] */
  { /*    32 */    1u,             288u,               272u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Key] */
  { /*    33 */    2u,             296u,               292u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx, SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Proof] */
  { /*    34 */    1u,            6604u,              6572u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelIntermediate, KeyM_SigVerifyKey_TrustModelIntermediate__Crypto_30_LibCv_Signature_Key] */
  { /*    35 */    1u,             316u,               300u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Key] */
  { /*    36 */    2u,             324u,               320u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx, SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Proof] */
  { /*    37 */ 3021u,            4524u,              4508u,               19u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Info, vHsm_Info__vHsm_Info_Uid] */
  { /*    38 */ 3023u,            4560u,              4528u,               20u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Info, vHsm_Info__vHsm_Info_ErrorLog] */
  { /*    39 */    1u,            4596u,              4564u,               21u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SecurityAccessPublicKey, Ssa_SecurityAccessPublicKey__Ssa_SecurityAccesPublicKey] */
  { /*    40 */    3u,            5984u,              5964u,               22u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RandomSeed, Ssa_RandomSeed__Crypto_30_LibCv_Random_Seed] */
  { /*    41 */    4u,            5989u,              5988u,               23u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RandomSeed, Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF] */
  { /*    42 */  999u,            6205u,              5996u,               24u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RandomSeed, Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize] */
  { /*    43 */ 3017u,            6228u,              6212u,               25u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RandomSeed, Ssa_RandomSeed__Ssa_Random_Nonce] */
  { /*    44 */ 3018u,            4504u,              4500u,                6u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RandomSeed, Ssa_RandomSeed__Crypto_30_LibCv_Random_Reseed_Counter] */
  { /*    45 */    1u,             344u,               328u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Key] */
  { /*    46 */    2u,             352u,               348u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx, SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Proof] */
  { /*    47 */    1u,             372u,               356u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Key] */
  { /*    48 */    2u,             380u,               376u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx, SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Proof] */
  { /*    49 */    0u,            5912u,              5312u,               26u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RootCert, Ssa_RootCert__Ssa_RootCert] */
    /* Index    Id     KeyStorageEndIdx  KeyStorageStartIdx  KeyElementInfoIdx        Referable Keys */
  { /*    50 */    0u,            8208u,              6708u,               27u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_Cert_Root, KeyM_Cert_Root__Crypto_30_LibCv_KeyM_CertificateData] */
  { /*    51 */    1u,             400u,               384u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Key] */
  { /*    52 */    2u,             408u,               404u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx, SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Proof] */
  { /*    53 */    1u,            8244u,              8212u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_ECC_Intermediate, KeyM_ECC_Intermediate__Crypto_30_LibCv_Signature_Key] */
  { /*    54 */    1u,            6396u,              6364u,               28u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretExchangeKey, Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_SharedValue] */
  { /*    55 */    8u,            6416u,              6400u,               29u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretExchangeKey, Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Base] */
  { /*    56 */    9u,            6452u,              6420u,               30u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretExchangeKey, Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_PrivKey] */
  { /*    57 */   10u,            6488u,              6456u,               31u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretExchangeKey, Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*    58 */   12u,            6493u,              6492u,               32u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretExchangeKey, Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519] */
  { /*    59 */    1u,            8280u,              8248u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_ECC_Root, KeyM_ECC_Root__Crypto_30_LibCv_Signature_Key] */
  { /*    60 */    2u,             444u,               440u,               33u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretHash, Ssa_SharedSecretHash__Ssa_SharedSecretHash] */
  { /*    61 */    1u,            4632u,              4600u,               34u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelPrivateEcu_LiveKey, Ssa_TrustModelPrivateEcu_LiveKey__Ssa_TrustModelPrivateEcu_LiveKey] */
  { /*    62 */    1u,            4668u,              4636u,               35u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuPublic_LiveKey, Ssa_TrustModelEcuPublic_LiveKey__Ssa_TrustModelEcuPublic_LiveKey] */
  { /*    63 */    1u,            4496u,              4464u,               36u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuPublicCsr_StagingKey, Ssa_TrustModelEcuPublicCsr_StagingKey__Ssa_TrustModelEcuPublicCsr_StagingKey] */
  { /*    64 */    1u,              64u,                48u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_Authentication, Ssa_Authentication__Ssa_Mac_Key] */
  { /*    65 */    2u,              72u,                68u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_Authentication, Ssa_Authentication__Ssa_Mac_Proof] */
  { /*    66 */    1u,             148u,               132u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_VIN, Ssa_VIN__Ssa_Mac_Key] */
  { /*    67 */    2u,             156u,               152u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_VIN, Ssa_VIN__Ssa_Mac_Proof] */
  { /*    68 */    1u,              92u,                76u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RealTime, Ssa_RealTime__Ssa_Mac_Key] */
  { /*    69 */    2u,             100u,                96u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RealTime, Ssa_RealTime__Ssa_Mac_Proof] */
  { /*    70 */    1u,             120u,               104u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TickCount, Ssa_TickCount__Ssa_Mac_Key] */
  { /*    71 */    2u,             128u,               124u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TickCount, Ssa_TickCount__Ssa_Mac_Proof] */
  { /*    72 */    1u,            6264u,              6232u,                9u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SignatureRamKey, Ssa_SignatureRamKey__Crypto_30_LibCv_Signature_Key] */
  { /*    73 */    1u,             428u,               412u,                7u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_Ign_Stat, SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Key] */
  { /*    74 */    2u,             436u,               432u,                8u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_Ign_Stat, SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Proof] */
  { /*    75 */    1u,            8568u,              8536u,               37u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SignatureRamKey_replacementAuthority, Ssa_SignatureRamKey_replacementAuthority__Crypto_30_LibCv_Signature_Key_replacementAuthority] */
  { /*    76 */    1u,            4704u,              4672u,               38u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelPrivateEcuUnique_StagingKey, Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Key] */
  { /*    77 */   10u,            8524u,              8492u,               31u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelPrivateEcuUnique_StagingKey, Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*    78 */   17u,            8529u,              8528u,               39u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelPrivateEcuUnique_StagingKey, Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519] */
  { /*    79 */    0u,            1448u,               448u,               40u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelBackendCert_inHSM, Ssa_TrustModelBackendCert_inHSM__CryptoKeyElement_Cert_wPersist] */
  { /*    80 */    0u,            4460u,              3460u,               40u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelRootCert_inHSM, Ssa_TrustModelRootCert_inHSM__CryptoKeyElement_Cert_wPersist] */
  { /*    81 */    0u,            2452u,              1452u,               40u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelIntermediateCert_inHSM, Ssa_TrustModelIntermediateCert_inHSM__CryptoKeyElement_Cert_wPersist] */
  { /*    82 */    0u,            3456u,              2456u,               40u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuCert_inHSM, Ssa_TrustModelEcuCert_inHSM__CryptoKeyElement_Cert_wPersist] */
  { /*    83 */    1u,            8604u,              8572u,               41u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPrivateKey, Ssa_TrustModel_Ecu_CsrPrivateKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element] */
  { /*    84 */   10u,            8640u,              8608u,               31u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPrivateKey, Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*    85 */   17u,            8645u,              8644u,               39u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPrivateKey, Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519] */
  { /*    86 */    1u,            8684u,              8652u,               41u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPublicKey, Ssa_TrustModel_Ecu_CsrPublicKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element] */
  { /*    87 */   10u,            8720u,              8688u,               31u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPublicKey, Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyExchange_OwnPubKey] */
  { /*    88 */   17u,            8725u,              8724u,               39u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPublicKey, Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519] */
  { /*    89 */    1u,            8764u,              8732u,               42u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_Signature_Ed25519, CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key] */
  { /*    90 */    1u,            8840u,              8808u,               43u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_SecurityAccess_Ed25519, CryptoKey_Fbl_SecurityAccess_Ed25519__Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key] */
  { /*    91 */    1u,            8784u,              8768u,               44u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_Decrypt_Aes128, CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key] */
  { /*    92 */    5u,            8804u,              8788u,               45u },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_Decrypt_Aes128, CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv] */
  { /*    93 */    1u,            8847u,              8844u,               46u }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHSM_Custom_HSM_Version, vHSM_Custom_HSM_Version__vHsm_Version] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_KeyGenEd25519
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_KeyGenEd25519
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyGenEd25519Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyGenEd25519[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                       Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.KeyGenEd25519 }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_NvBlock
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_NvBlock
  \brief  Contains parameters of /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock.
  \details
  Element               Description
  Crc                   Calculated CRC over layout of the block
  Descriptor            Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockDescriptor.
  KeyStorageEndIdx      the end index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  KeyStorageStartIdx    the start index of the 1:n relation pointing to Crypto_30_LibCv_KeyStorage
  Length                Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockLength.
  ConsistencyLevel      Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockConsistencyLevel.
  Id                    Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockId.
  Processing            Contains values of DefinitionRef: /MICROSAR/Crypto_30_LibCv/Crypto/CryptoNvStorage/CryptoNvBlock/CryptoNvBlockProcessing.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_NvBlockType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_NvBlock[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Crc          Descriptor                                                  KeyStorageEndIdx  KeyStorageStartIdx  Length  ConsistencyLevel                             Id  Processing                                     Referable Keys */
  { /*     0 */ 0x1EC858E9u, NvMConf_NvMBlockDescriptor_Keys_Deferred                  ,              44u,                 0u,    70u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 0u, CRYPTO_30_LIBCV_NV_PROCESSING_DEFERRED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage] */
  { /*     1 */ 0x42222547u, NvMConf_NvMBlockDescriptor_Keys_Deferred_SecOC            ,             436u,                44u,   400u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 1u, CRYPTO_30_LIBCV_NV_PROCESSING_DEFERRED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage] */
  { /*     2 */ 0x2BEB6CB6u, NvMConf_NvMBlockDescriptor_Keys_Deferred_SharedSecretHash ,             444u,               436u,    16u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 2u, CRYPTO_30_LIBCV_NV_PROCESSING_DEFERRED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SharedSecretHash, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage] */
  { /*     3 */ 0xB3CC3C61u, NvMConf_NvMBlockDescriptor_Keys_Deferred_TrustModel_NoRoot,            3456u,               444u,  3018u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 3u, CRYPTO_30_LIBCV_NV_PROCESSING_DEFERRED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage] */
  { /*     4 */ 0xB4BEF1E9u, NvMConf_NvMBlockDescriptor_Keys_Deferred_TrustModel_Root  ,            4460u,              3456u,  1010u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 4u, CRYPTO_30_LIBCV_NV_PROCESSING_DEFERRED  },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_Root, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage] */
  { /*     5 */ 0x092A2B7Bu, NvMConf_NvMBlockDescriptor_Keys_Immediate                 ,            4704u,              4460u,   280u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 5u, CRYPTO_30_LIBCV_NV_PROCESSING_IMMEDIATE },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage] */
  { /*     6 */ 0x3E867637u, NvMConf_NvMBlockDescriptor_Keys_Immediate_BackendCert     ,            5308u,              4704u,   922u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 6u, CRYPTO_30_LIBCV_NV_PROCESSING_IMMEDIATE },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_BackendCert, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage] */
  { /*     7 */ 0x4F14D239u, NvMConf_NvMBlockDescriptor_Keys_Immediate_RootCert        ,            5912u,              5308u,   922u, CRYPTO_30_LIBCV_NV_CONSISTENCY_LEVEL_DETECT, 7u, CRYPTO_30_LIBCV_NV_PROCESSING_IMMEDIATE }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_RootCert, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage] */
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
  Element               Description
  WorkspaceLength       Holds the length of the workspace.
  AesDecryptIdx         the index of the 0:1 relation pointing to Crypto_30_LibCv_AesDecrypt
  AesEncryptIdx         the index of the 0:1 relation pointing to Crypto_30_LibCv_AesEncrypt
  CmacAesGenerateIdx    the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesGenerate
  CmacAesVerifyIdx      the index of the 0:1 relation pointing to Crypto_30_LibCv_CmacAesVerify
  DRBGAESIdx            the index of the 0:1 relation pointing to Crypto_30_LibCv_DRBGAES
  EcP256VerifyIdx       the index of the 0:1 relation pointing to Crypto_30_LibCv_EcP256Verify
  Ed25519GenerateIdx    the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Generate
  Ed25519VerifyIdx      the index of the 0:1 relation pointing to Crypto_30_LibCv_Ed25519Verify
  KeyGenEd25519Idx      the index of the 0:1 relation pointing to Crypto_30_LibCv_KeyGenEd25519
  QueueIdx              the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue
  SHA256Idx             the index of the 0:1 relation pointing to Crypto_30_LibCv_SHA256
  SHA512Idx             the index of the 0:1 relation pointing to Crypto_30_LibCv_SHA512
  WorkspaceAddr         Holds the address of the workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_ObjectInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    WorkspaceLength                                         AesDecryptIdx                                 AesEncryptIdx                                 CmacAesGenerateIdx                                 CmacAesVerifyIdx                                 DRBGAESIdx                                 EcP256VerifyIdx                                 Ed25519GenerateIdx                                 Ed25519VerifyIdx                                 KeyGenEd25519Idx                                 QueueIdx  SHA256Idx                                 SHA512Idx                                 WorkspaceAddr                                                                                               Referable Keys */
  { /*     0 */ sizeof(Crypto_30_LibCv_WS_vHsm_LibCv_Type)            ,                                           0u,                                           0u,                                                0u,                                              0u,                                        0u,                                             0u,                                                0u,                                              0u,                                              0u,       0u,                                       0u,                                       0u, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_vHsm_LibCv             },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Verify, KeyGenEd25519] */
  { /*     1 */ sizeof(Crypto_30_LibCv_WS_vHsm_LibCv_HighPrio_Type)   ,                                           1u,                                           1u,                                                1u,                                              1u,                                        1u, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENED25519IDXOFOBJECTINFO,       1u,                                       1u,                                       1u, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio    },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES] */
  { /*     2 */ sizeof(Crypto_30_LibCv_WS_vHsm_LibCv_KeyM_Type)       , CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO,                                             1u, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENED25519IDXOFOBJECTINFO,       2u, CRYPTO_30_LIBCV_NO_SHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_SHA512IDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_vHsm_LibCv_KeyM        },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_KeyM, EcP256Verify] */
  { /*     3 */ sizeof(Crypto_30_LibCv_WS_vHsm_LibCv_vHsmUpd_Dec_Type),                                           2u, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENED25519IDXOFOBJECTINFO,       3u, CRYPTO_30_LIBCV_NO_SHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_SHA512IDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Dec },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Dec, AesDecrypt] */
  { /*     4 */ sizeof(Crypto_30_LibCv_WS_vHsm_LibCv_vHsmUpd_Enc_Type), CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO,                                           2u, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENED25519IDXOFOBJECTINFO,       4u, CRYPTO_30_LIBCV_NO_SHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_SHA512IDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Enc },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Enc, AesEncrypt] */
  { /*     5 */ sizeof(Crypto_30_LibCv_WS_vHsm_LibCv_vHsmUpd_Mac_Type), CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO,                                                2u, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ECP256VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_ED25519VERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_KEYGENED25519IDXOFOBJECTINFO,       5u, CRYPTO_30_LIBCV_NO_SHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_SHA512IDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Mac },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Mac, CmacAesGenerate] */
  { /*     6 */ sizeof(Crypto_30_LibCv_WS_vHsm_LibCv_vHsmUpd_Sig_Type), CRYPTO_30_LIBCV_NO_AESDECRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_AESENCRYPTIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESGENERATEIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_CMACAESVERIFYIDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_DRBGAESIDXOFOBJECTINFO,                                             2u, CRYPTO_30_LIBCV_NO_ED25519GENERATEIDXOFOBJECTINFO,                                              1u, CRYPTO_30_LIBCV_NO_KEYGENED25519IDXOFOBJECTINFO,       6u, CRYPTO_30_LIBCV_NO_SHA256IDXOFOBJECTINFO, CRYPTO_30_LIBCV_NO_SHA512IDXOFOBJECTINFO, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Sig }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig, Ed25519Verify, EcP256Verify] */
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
CONST(Crypto_30_LibCv_ObjectInfoIndType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoInd[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ObjectInfoInd      Referable Keys */
  /*     0 */             0u,  /* [AesDecrypt] */
  /*     1 */             1u,  /* [AesDecrypt] */
  /*     2 */             3u,  /* [AesDecrypt] */
  /*     3 */             0u,  /* [AesEncrypt] */
  /*     4 */             1u,  /* [AesEncrypt] */
  /*     5 */             4u,  /* [AesEncrypt] */
  /*     6 */             0u,  /* [SHA256] */
  /*     7 */             1u,  /* [SHA256] */
  /*     8 */             0u,  /* [SHA512] */
  /*     9 */             1u,  /* [SHA512] */
  /*    10 */             0u,  /* [KeyGenEd25519] */
  /*    11 */             0u,  /* [CmacAesGenerate] */
  /*    12 */             1u,  /* [CmacAesGenerate] */
  /*    13 */             5u,  /* [CmacAesGenerate] */
  /*    14 */             0u,  /* [CmacAesVerify] */
  /*    15 */             1u,  /* [CmacAesVerify] */
  /*    16 */             0u,  /* [DRBGAES] */
  /*    17 */             1u,  /* [DRBGAES] */
  /*    18 */             0u,  /* [Ed25519Generate] */
  /*    19 */             0u,  /* [Ed25519Verify] */
  /*    20 */             6u,  /* [Ed25519Verify] */
  /*    21 */             0u,  /* [EcP256Verify] */
  /*    22 */             2u,  /* [EcP256Verify] */
  /*    23 */             6u   /* [EcP256Verify] */
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
CONST(Crypto_30_LibCv_PrimitiveFctType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFct[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIndEndIdx  ObjectInfoIndStartIdx  Dispatch                                        Referable Keys */
  { /*     0 */                  3u,                    0u, Crypto_30_LibCv_Dispatch_AesDecrypt      },  /* [AesDecrypt] */
  { /*     1 */                  6u,                    3u, Crypto_30_LibCv_Dispatch_AesEncrypt      },  /* [AesEncrypt] */
  { /*     2 */                  8u,                    6u, Crypto_30_LibCv_Dispatch_SHA256          },  /* [SHA256] */
  { /*     3 */                 10u,                    8u, Crypto_30_LibCv_Dispatch_SHA512          },  /* [SHA512] */
  { /*     4 */                 11u,                   10u, Crypto_30_LibCv_Dispatch_KeyGenEd25519   },  /* [KeyGenEd25519] */
  { /*     5 */                 14u,                   11u, Crypto_30_LibCv_Dispatch_CmacAesGenerate },  /* [CmacAesGenerate] */
  { /*     6 */                 16u,                   14u, Crypto_30_LibCv_Dispatch_CmacAesVerify   },  /* [CmacAesVerify] */
  { /*     7 */                 18u,                   16u, Crypto_30_LibCv_Dispatch_DRBGAES         },  /* [DRBGAES] */
  { /*     8 */                 19u,                   18u, Crypto_30_LibCv_Dispatch_Ed25519Generate },  /* [Ed25519Generate] */
  { /*     9 */                 21u,                   19u, Crypto_30_LibCv_Dispatch_Ed25519Verify   },  /* [Ed25519Verify] */
  { /*    10 */                 24u,                   21u, Crypto_30_LibCv_Dispatch_EcP256Verify    }   /* [EcP256Verify] */
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
CONST(Crypto_30_LibCv_PrimitiveInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfo[30] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Combined                                                                                                                                                                                    MaskedBits  PrimitiveFctIdx        Referable Keys */
  { /*     0 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                       ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     1 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))          ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     2 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                          ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     3 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                       ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     4 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))          ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     5 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                          ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     6 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                       ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     7 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))          ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     8 */ ((((uint32)CRYPTO_DECRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                          ,      0x00u,              0u },  /* [CRYPTO_DECRYPT] */
  { /*     9 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                       ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    10 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))          ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    11 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_ECB) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                          ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    12 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                       ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    13 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))          ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    14 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CBC) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                          ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    15 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                       ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    16 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_PADDING_PKCS7))          ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    17 */ ((((uint32)CRYPTO_ENCRYPT) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CTR) << 8) | ((uint32)CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS))                          ,      0x00u,              1u },  /* [CRYPTO_ENCRYPT] */
  { /*    18 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_256) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                 ,      0x00u,              2u },  /* [CRYPTO_HASH] */
  { /*    19 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_512) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                 ,      0x00u,              3u },  /* [CRYPTO_HASH] */
  { /*    20 */ ((((uint32)CRYPTO_KEYGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                           ,      0x01u,              4u },  /* [CRYPTO_KEYGENERATE] */
  { /*    21 */ ((((uint32)CRYPTO_MACGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                  ,      0x00u,              5u },  /* [CRYPTO_MACGENERATE] */
  { /*    22 */ ((((uint32)CRYPTO_MACVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_AES) << 16) | (((uint32)CRYPTO_ALGOMODE_CMAC) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                                    ,      0x00u,              6u },  /* [CRYPTO_MACVERIFY] */
  { /*    23 */ ((((uint32)CRYPTO_RANDOMGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_CUSTOM_CRYPTO_30_LIBCV_DRBG) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_AES))        ,      0x00u,              7u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*    24 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                     ,      0x00u,              8u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    25 */ ((((uint32)CRYPTO_SIGNATUREGENERATE) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))                    ,      0x00u,              8u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*    26 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))                      ,      0x00u,              9u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    27 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET))                       ,      0x00u,              9u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    28 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ED25519) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_512))                      ,      0x00u,              9u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*    29 */ ((((uint32)CRYPTO_SIGNATUREVERIFY) << 24) | (((uint32)CRYPTO_ALGOFAM_ECCNIST) << 16) | (((uint32)CRYPTO_ALGOMODE_CUSTOM_CRYPTO_30_LIBCV_P256R1) << 8) | ((uint32)CRYPTO_ALGOFAM_SHA2_256)),      0x00u,             10u }   /* [CRYPTO_SIGNATUREVERIFY] */
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
  { /*     0 */                                                          20u,                                                            18u },  /* [CRYPTO_HASH] */
  { /*     1 */                                                          22u,                                                            21u },  /* [CRYPTO_MACGENERATE] */
  { /*     2 */                                                          23u,                                                            22u },  /* [CRYPTO_MACVERIFY] */
  { /*     3 */                                                          18u,                                                             9u },  /* [CRYPTO_ENCRYPT] */
  { /*     4 */                                                           9u,                                                             0u },  /* [CRYPTO_DECRYPT] */
  { /*     5 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_AEADENCRYPT] */
  { /*     6 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_AEADDECRYPT] */
  { /*     7 */                                                          26u,                                                            24u },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*     8 */                                                          30u,                                                            26u },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*     9 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERINCREMENT] */
  { /*    10 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERREAD] */
  { /*    11 */                                                          24u,                                                            23u },  /* [CRYPTO_RANDOMGENERATE] */
  { /*    12 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_RANDOMSEED] */
  { /*    13 */                                                          21u,                                                            20u },  /* [CRYPTO_KEYGENERATE] */
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
  Crypto_30_LibCv_SHA256
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_SHA256
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_SHA256Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_SHA256[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                         Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.SHA256          },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio.primWS.SHA256 }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_SHA512
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_SHA512
  \details
  Element      Description
  Workspace
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_SHA512Type, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_SHA512[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Workspace                                                         Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv.primWS.SHA512          },  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  { /*     1 */ &Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio.primWS.SHA512 }   /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio] */
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
VAR(Crypto_30_LibCv_BufferLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLength[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Verify, KeyGenEd25519] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_KeyM, EcP256Verify] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Dec, AesDecrypt] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Enc, AesEncrypt] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Mac, CmacAesGenerate] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig, Ed25519Verify, EcP256Verify] */

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
VAR(Crypto_30_LibCv_DriverObjectStateType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectState[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Verify, KeyGenEd25519] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_KeyM, EcP256Verify] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Dec, AesDecrypt] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Enc, AesEncrypt] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Mac, CmacAesGenerate] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig, Ed25519Verify, EcP256Verify] */

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
  /*     0 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_PduKeysMac] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_TRNG] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelBackendPeer] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Custom] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelIntermediatePeer] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_AesRamKey] */
  /*     7 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelEcuPeer] */
  /*     8 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Decrypt] */
  /*     9 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_PT4_PTCoor4] */
  /*    10 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Encrypt] */
  /*    11 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_VehSpd_8] */
  /*    12 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Mac] */
  /*    13 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_BackendCert] */
  /*    14 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelRoot] */
  /*    15 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer] */
  /*    16 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_FirmwareUpdate_Signature] */
  /*    17 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelBackend] */
  /*    18 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx] */
  /*    19 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_SigVerifyKey_TrustModelIntermediate] */
  /*    20 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx] */
  /*    21 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHsm_Info] */
  /*    22 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SecurityAccessPublicKey] */
  /*    23 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RandomSeed] */
  /*    24 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx] */
  /*    25 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx] */
  /*    26 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RootCert] */
  /*    27 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_Cert_Root] */
  /*    28 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx] */
  /*    29 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_ECC_Intermediate] */
  /*    30 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretExchangeKey] */
  /*    31 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/KeyM_ECC_Root] */
  /*    32 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SharedSecretHash] */
  /*    33 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelPrivateEcu_LiveKey] */
  /*    34 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuPublic_LiveKey] */
  /*    35 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuPublicCsr_StagingKey] */
  /*    36 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_Authentication] */
  /*    37 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_VIN] */
  /*    38 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_RealTime] */
  /*    39 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TickCount] */
  /*    40 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SignatureRamKey] */
  /*    41 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/SSA_SecOC_Int_MacVerify_Ign_Stat] */
  /*    42 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_SignatureRamKey_replacementAuthority] */
  /*    43 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelPrivateEcuUnique_StagingKey] */
  /*    44 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelBackendCert_inHSM] */
  /*    45 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelRootCert_inHSM] */
  /*    46 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelIntermediateCert_inHSM] */
  /*    47 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModelEcuCert_inHSM] */
  /*    48 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPrivateKey] */
  /*    49 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/Ssa_TrustModel_Ecu_CsrPublicKey] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_Signature_Ed25519] */
  /*    51 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_SecurityAccess_Ed25519] */
  /*    52 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/CryptoKey_Fbl_Decrypt_Aes128] */
  /*    53 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoKeys/vHSM_Custom_HSM_Version] */

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
VAR(Crypto_30_LibCv_KeyStorageType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStorage[8848];  /* PRQA S 1514, 1533, 0612, 0613 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure, MD_CSL_BigStructure */
  /* Index        Referable Keys */
  /*     0 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*     1 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*     2 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*     3 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*     4 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*   ... */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*    35 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*    36 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Reseed_Counter__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*    37 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Reseed_Counter__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*    38 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Reseed_Counter__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*    39 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Reseed_Counter__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*    40 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*   ... */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*    43 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred] */
  /*    44 */  /* [Ssa_Authentication__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    45 */  /* [Ssa_Authentication__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    46 */  /* [Ssa_Authentication__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    47 */  /* [Ssa_Authentication__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    48 */  /* [Ssa_Authentication__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [Ssa_Authentication__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    63 */  /* [Ssa_Authentication__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    64 */  /* [Ssa_Authentication__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    65 */  /* [Ssa_Authentication__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    66 */  /* [Ssa_Authentication__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    67 */  /* [Ssa_Authentication__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    68 */  /* [Ssa_Authentication__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [Ssa_Authentication__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    71 */  /* [Ssa_Authentication__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    72 */  /* [Ssa_RealTime__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    73 */  /* [Ssa_RealTime__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    74 */  /* [Ssa_RealTime__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    75 */  /* [Ssa_RealTime__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    76 */  /* [Ssa_RealTime__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [Ssa_RealTime__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    91 */  /* [Ssa_RealTime__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    92 */  /* [Ssa_RealTime__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    93 */  /* [Ssa_RealTime__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    94 */  /* [Ssa_RealTime__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    95 */  /* [Ssa_RealTime__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    96 */  /* [Ssa_RealTime__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [Ssa_RealTime__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*    99 */  /* [Ssa_RealTime__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   100 */  /* [Ssa_TickCount__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   101 */  /* [Ssa_TickCount__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   102 */  /* [Ssa_TickCount__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   103 */  /* [Ssa_TickCount__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   104 */  /* [Ssa_TickCount__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [Ssa_TickCount__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   119 */  /* [Ssa_TickCount__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   120 */  /* [Ssa_TickCount__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   121 */  /* [Ssa_TickCount__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /* Index        Referable Keys */
  /*   122 */  /* [Ssa_TickCount__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   123 */  /* [Ssa_TickCount__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   124 */  /* [Ssa_TickCount__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [Ssa_TickCount__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   127 */  /* [Ssa_TickCount__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   128 */  /* [Ssa_VIN__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   129 */  /* [Ssa_VIN__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   130 */  /* [Ssa_VIN__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   131 */  /* [Ssa_VIN__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   132 */  /* [Ssa_VIN__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [Ssa_VIN__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   147 */  /* [Ssa_VIN__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   148 */  /* [Ssa_VIN__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   149 */  /* [Ssa_VIN__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   150 */  /* [Ssa_VIN__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   151 */  /* [Ssa_VIN__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   152 */  /* [Ssa_VIN__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [Ssa_VIN__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   155 */  /* [Ssa_VIN__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   156 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   157 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   158 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   159 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   160 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   175 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   176 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   177 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   178 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   179 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   180 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   183 */  /* [SSA_SecOC_Int_MacVerify_PN14_Master_Stat1__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   184 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   185 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   186 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   187 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   188 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   203 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   204 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   205 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   206 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   207 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   208 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   211 */  /* [SSA_SecOC_Int_MacVerify_PT4_PTCoor4__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   212 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   213 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   214 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /* Index        Referable Keys */
  /*   215 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   216 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   231 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   232 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   233 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   234 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   235 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   236 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   239 */  /* [SSA_SecOC_Int_MacVerify_VehSpd_8__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   240 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   241 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   242 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   243 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   244 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   259 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   260 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   261 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   262 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   263 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   264 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   267 */  /* [SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   268 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   269 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   270 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   271 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   272 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   287 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   288 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   289 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   290 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   291 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   292 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   295 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   296 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   297 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   298 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   299 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   300 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   315 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   316 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   317 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   318 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   319 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /* Index        Referable Keys */
  /*   320 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   323 */  /* [SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   324 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   325 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   326 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   327 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   328 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   343 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   344 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   345 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   346 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   347 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   348 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   351 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   352 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   353 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   354 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   355 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   356 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   371 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   372 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   373 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   374 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   375 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   376 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   379 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   380 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   381 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   382 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   383 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   384 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   399 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   400 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   401 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   402 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   403 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   404 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   407 */  /* [SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   408 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   409 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   410 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   411 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   412 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   427 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /* Index        Referable Keys */
  /*   428 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   429 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Proof__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   430 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Proof__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   431 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Proof__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   432 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   ... */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   435 */  /* [SSA_SecOC_Int_MacVerify_Ign_Stat__Ssa_Mac_Proof__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SecOC] */
  /*   436 */  /* [Ssa_SharedSecretHash__Ssa_SharedSecretHash__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SharedSecretHash] */
  /*   437 */  /* [Ssa_SharedSecretHash__Ssa_SharedSecretHash__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SharedSecretHash] */
  /*   438 */  /* [Ssa_SharedSecretHash__Ssa_SharedSecretHash__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SharedSecretHash] */
  /*   439 */  /* [Ssa_SharedSecretHash__Ssa_SharedSecretHash__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SharedSecretHash] */
  /*   440 */  /* [Ssa_SharedSecretHash__Ssa_SharedSecretHash__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SharedSecretHash] */
  /*   ... */  /* [Ssa_SharedSecretHash__Ssa_SharedSecretHash__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SharedSecretHash] */
  /*   443 */  /* [Ssa_SharedSecretHash__Ssa_SharedSecretHash__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_SharedSecretHash] */
  /*   444 */  /* [Ssa_TrustModelBackendCert_inHSM__CryptoKeyElement_Cert_wPersist__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*   445 */  /* [Ssa_TrustModelBackendCert_inHSM__CryptoKeyElement_Cert_wPersist__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*   446 */  /* [Ssa_TrustModelBackendCert_inHSM__CryptoKeyElement_Cert_wPersist__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*   447 */  /* [Ssa_TrustModelBackendCert_inHSM__CryptoKeyElement_Cert_wPersist__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*   448 */  /* [Ssa_TrustModelBackendCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*   ... */  /* [Ssa_TrustModelBackendCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  1447 */  /* [Ssa_TrustModelBackendCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  1448 */  /* [Ssa_TrustModelIntermediateCert_inHSM__CryptoKeyElement_Cert_wPersist__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  1449 */  /* [Ssa_TrustModelIntermediateCert_inHSM__CryptoKeyElement_Cert_wPersist__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  1450 */  /* [Ssa_TrustModelIntermediateCert_inHSM__CryptoKeyElement_Cert_wPersist__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  1451 */  /* [Ssa_TrustModelIntermediateCert_inHSM__CryptoKeyElement_Cert_wPersist__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  1452 */  /* [Ssa_TrustModelIntermediateCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*   ... */  /* [Ssa_TrustModelIntermediateCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  2451 */  /* [Ssa_TrustModelIntermediateCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  2452 */  /* [Ssa_TrustModelEcuCert_inHSM__CryptoKeyElement_Cert_wPersist__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  2453 */  /* [Ssa_TrustModelEcuCert_inHSM__CryptoKeyElement_Cert_wPersist__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  2454 */  /* [Ssa_TrustModelEcuCert_inHSM__CryptoKeyElement_Cert_wPersist__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  2455 */  /* [Ssa_TrustModelEcuCert_inHSM__CryptoKeyElement_Cert_wPersist__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  2456 */  /* [Ssa_TrustModelEcuCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*   ... */  /* [Ssa_TrustModelEcuCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  3455 */  /* [Ssa_TrustModelEcuCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_NoRoot] */
  /*  3456 */  /* [Ssa_TrustModelRootCert_inHSM__CryptoKeyElement_Cert_wPersist__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_Root] */
  /*  3457 */  /* [Ssa_TrustModelRootCert_inHSM__CryptoKeyElement_Cert_wPersist__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_Root] */
  /*  3458 */  /* [Ssa_TrustModelRootCert_inHSM__CryptoKeyElement_Cert_wPersist__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_Root] */
  /*  3459 */  /* [Ssa_TrustModelRootCert_inHSM__CryptoKeyElement_Cert_wPersist__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_Root] */
  /*  3460 */  /* [Ssa_TrustModelRootCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_Root] */
  /*   ... */  /* [Ssa_TrustModelRootCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_Root] */
  /*  4459 */  /* [Ssa_TrustModelRootCert_inHSM__CryptoKeyElement_Cert_wPersist__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Deferred_TrustModel_Root] */
  /*  4460 */  /* [Ssa_TrustModelEcuPublicCsr_StagingKey__Ssa_TrustModelEcuPublicCsr_StagingKey__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4461 */  /* [Ssa_TrustModelEcuPublicCsr_StagingKey__Ssa_TrustModelEcuPublicCsr_StagingKey__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4462 */  /* [Ssa_TrustModelEcuPublicCsr_StagingKey__Ssa_TrustModelEcuPublicCsr_StagingKey__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4463 */  /* [Ssa_TrustModelEcuPublicCsr_StagingKey__Ssa_TrustModelEcuPublicCsr_StagingKey__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4464 */  /* [Ssa_TrustModelEcuPublicCsr_StagingKey__Ssa_TrustModelEcuPublicCsr_StagingKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*   ... */  /* [Ssa_TrustModelEcuPublicCsr_StagingKey__Ssa_TrustModelEcuPublicCsr_StagingKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4495 */  /* [Ssa_TrustModelEcuPublicCsr_StagingKey__Ssa_TrustModelEcuPublicCsr_StagingKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4496 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Reseed_Counter__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4497 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Reseed_Counter__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /* Index        Referable Keys */
  /*  4498 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Reseed_Counter__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4499 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Reseed_Counter__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4500 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*   ... */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4503 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Reseed_Counter__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4504 */  /* [vHsm_Info__vHsm_Info_Uid__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4505 */  /* [vHsm_Info__vHsm_Info_Uid__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4506 */  /* [vHsm_Info__vHsm_Info_Uid__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4507 */  /* [vHsm_Info__vHsm_Info_Uid__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4508 */  /* [vHsm_Info__vHsm_Info_Uid__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*   ... */  /* [vHsm_Info__vHsm_Info_Uid__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4523 */  /* [vHsm_Info__vHsm_Info_Uid__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4524 */  /* [vHsm_Info__vHsm_Info_ErrorLog__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4525 */  /* [vHsm_Info__vHsm_Info_ErrorLog__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4526 */  /* [vHsm_Info__vHsm_Info_ErrorLog__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4527 */  /* [vHsm_Info__vHsm_Info_ErrorLog__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4528 */  /* [vHsm_Info__vHsm_Info_ErrorLog__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*   ... */  /* [vHsm_Info__vHsm_Info_ErrorLog__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4559 */  /* [vHsm_Info__vHsm_Info_ErrorLog__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4560 */  /* [Ssa_SecurityAccessPublicKey__Ssa_SecurityAccesPublicKey__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4561 */  /* [Ssa_SecurityAccessPublicKey__Ssa_SecurityAccesPublicKey__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4562 */  /* [Ssa_SecurityAccessPublicKey__Ssa_SecurityAccesPublicKey__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4563 */  /* [Ssa_SecurityAccessPublicKey__Ssa_SecurityAccesPublicKey__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4564 */  /* [Ssa_SecurityAccessPublicKey__Ssa_SecurityAccesPublicKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*   ... */  /* [Ssa_SecurityAccessPublicKey__Ssa_SecurityAccesPublicKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4595 */  /* [Ssa_SecurityAccessPublicKey__Ssa_SecurityAccesPublicKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4596 */  /* [Ssa_TrustModelPrivateEcu_LiveKey__Ssa_TrustModelPrivateEcu_LiveKey__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4597 */  /* [Ssa_TrustModelPrivateEcu_LiveKey__Ssa_TrustModelPrivateEcu_LiveKey__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4598 */  /* [Ssa_TrustModelPrivateEcu_LiveKey__Ssa_TrustModelPrivateEcu_LiveKey__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4599 */  /* [Ssa_TrustModelPrivateEcu_LiveKey__Ssa_TrustModelPrivateEcu_LiveKey__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4600 */  /* [Ssa_TrustModelPrivateEcu_LiveKey__Ssa_TrustModelPrivateEcu_LiveKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*   ... */  /* [Ssa_TrustModelPrivateEcu_LiveKey__Ssa_TrustModelPrivateEcu_LiveKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4631 */  /* [Ssa_TrustModelPrivateEcu_LiveKey__Ssa_TrustModelPrivateEcu_LiveKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4632 */  /* [Ssa_TrustModelEcuPublic_LiveKey__Ssa_TrustModelEcuPublic_LiveKey__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4633 */  /* [Ssa_TrustModelEcuPublic_LiveKey__Ssa_TrustModelEcuPublic_LiveKey__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4634 */  /* [Ssa_TrustModelEcuPublic_LiveKey__Ssa_TrustModelEcuPublic_LiveKey__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4635 */  /* [Ssa_TrustModelEcuPublic_LiveKey__Ssa_TrustModelEcuPublic_LiveKey__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4636 */  /* [Ssa_TrustModelEcuPublic_LiveKey__Ssa_TrustModelEcuPublic_LiveKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*   ... */  /* [Ssa_TrustModelEcuPublic_LiveKey__Ssa_TrustModelEcuPublic_LiveKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4667 */  /* [Ssa_TrustModelEcuPublic_LiveKey__Ssa_TrustModelEcuPublic_LiveKey__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4668 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4669 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Key__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4670 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Key__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4671 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Key__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4672 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*   ... */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4703 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Key__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate] */
  /*  4704 */  /* [Ssa_BackendCert__Ssa_BackendCert__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_BackendCert] */
  /*  4705 */  /* [Ssa_BackendCert__Ssa_BackendCert__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_BackendCert] */
  /*  4706 */  /* [Ssa_BackendCert__Ssa_BackendCert__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_BackendCert] */
  /* Index        Referable Keys */
  /*  4707 */  /* [Ssa_BackendCert__Ssa_BackendCert__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_BackendCert] */
  /*  4708 */  /* [Ssa_BackendCert__Ssa_BackendCert__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_BackendCert] */
  /*   ... */  /* [Ssa_BackendCert__Ssa_BackendCert__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_BackendCert] */
  /*  5307 */  /* [Ssa_BackendCert__Ssa_BackendCert__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_BackendCert] */
  /*  5308 */  /* [Ssa_RootCert__Ssa_RootCert__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_RootCert] */
  /*  5309 */  /* [Ssa_RootCert__Ssa_RootCert__WrittenLength__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_RootCert] */
  /*  5310 */  /* [Ssa_RootCert__Ssa_RootCert__Valid__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_RootCert] */
  /*  5311 */  /* [Ssa_RootCert__Ssa_RootCert__Extension__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_RootCert] */
  /*  5312 */  /* [Ssa_RootCert__Ssa_RootCert__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_RootCert] */
  /*   ... */  /* [Ssa_RootCert__Ssa_RootCert__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_RootCert] */
  /*  5911 */  /* [Ssa_RootCert__Ssa_RootCert__Data__, /ActiveEcuC/Crypto_30_LibCv/CryptoNvStorage/CryptoNvBlock_Immediate_RootCert] */
  /*  5912 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__WrittenLength__, RAM_KEY] */
  /*  5913 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__WrittenLength__, RAM_KEY] */
  /*  5914 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__Valid__, RAM_KEY] */
  /*  5915 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__Extension__, RAM_KEY] */
  /*  5916 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__Data__, RAM_KEY] */
  /*  5917 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__AlignDummy__, RAM_KEY] */
  /*   ... */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__AlignDummy__, RAM_KEY] */
  /*  5919 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128__AlignDummy__, RAM_KEY] */
  /*  5920 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_PrivateString__WrittenLength__, RAM_KEY] */
  /*  5921 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_PrivateString__WrittenLength__, RAM_KEY] */
  /*  5922 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_PrivateString__Valid__, RAM_KEY] */
  /*  5923 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_PrivateString__Extension__, RAM_KEY] */
  /*  5924 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*  5939 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_PrivateString__Data__, RAM_KEY] */
  /*  5940 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_AdditionalInput__WrittenLength__, RAM_KEY] */
  /*  5941 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_AdditionalInput__WrittenLength__, RAM_KEY] */
  /*  5942 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_AdditionalInput__Valid__, RAM_KEY] */
  /*  5943 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_AdditionalInput__Extension__, RAM_KEY] */
  /*  5944 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*  5959 */  /* [vHsm_TRNG__Crypto_30_LibCv_Random_AdditionalInput__Data__, RAM_KEY] */
  /*  5960 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Seed__WrittenLength__, RAM_KEY] */
  /*  5961 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Seed__WrittenLength__, RAM_KEY] */
  /*  5962 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Seed__Valid__, RAM_KEY] */
  /*  5963 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Seed__Extension__, RAM_KEY] */
  /*  5964 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*  5983 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Seed__Data__, RAM_KEY] */
  /*  5984 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF__WrittenLength__, RAM_KEY] */
  /*  5985 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF__WrittenLength__, RAM_KEY] */
  /*  5986 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF__Valid__, RAM_KEY] */
  /*  5987 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF__Extension__, RAM_KEY] */
  /*  5988 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF__Data__, RAM_KEY] */
  /*  5989 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF__AlignDummy__, RAM_KEY] */
  /*   ... */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF__AlignDummy__, RAM_KEY] */
  /*  5991 */  /* [Ssa_RandomSeed__Crypto_30_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF__AlignDummy__, RAM_KEY] */
  /*  5992 */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__WrittenLength__, RAM_KEY] */
  /*  5993 */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__WrittenLength__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  5994 */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__Valid__, RAM_KEY] */
  /*  5995 */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__Extension__, RAM_KEY] */
  /*  5996 */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__Data__, RAM_KEY] */
  /*  6204 */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__Data__, RAM_KEY] */
  /*  6205 */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__AlignDummy__, RAM_KEY] */
  /*   ... */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__AlignDummy__, RAM_KEY] */
  /*  6207 */  /* [Ssa_RandomSeed__CryptoKeyElement_DummyWorkaround_RandomSeedSize__AlignDummy__, RAM_KEY] */
  /*  6208 */  /* [Ssa_RandomSeed__Ssa_Random_Nonce__WrittenLength__, RAM_KEY] */
  /*  6209 */  /* [Ssa_RandomSeed__Ssa_Random_Nonce__WrittenLength__, RAM_KEY] */
  /*  6210 */  /* [Ssa_RandomSeed__Ssa_Random_Nonce__Valid__, RAM_KEY] */
  /*  6211 */  /* [Ssa_RandomSeed__Ssa_Random_Nonce__Extension__, RAM_KEY] */
  /*  6212 */  /* [Ssa_RandomSeed__Ssa_Random_Nonce__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_RandomSeed__Ssa_Random_Nonce__Data__, RAM_KEY] */
  /*  6227 */  /* [Ssa_RandomSeed__Ssa_Random_Nonce__Data__, RAM_KEY] */
  /*  6228 */  /* [Ssa_SignatureRamKey__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6229 */  /* [Ssa_SignatureRamKey__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6230 */  /* [Ssa_SignatureRamKey__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  6231 */  /* [Ssa_SignatureRamKey__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  6232 */  /* [Ssa_SignatureRamKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_SignatureRamKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6263 */  /* [Ssa_SignatureRamKey__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6264 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_Internal_Key__WrittenLength__, RAM_KEY] */
  /*  6265 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_Internal_Key__WrittenLength__, RAM_KEY] */
  /*  6266 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_Internal_Key__Valid__, RAM_KEY] */
  /*  6267 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_Internal_Key__Extension__, RAM_KEY] */
  /*  6268 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_Internal_Key__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_Internal_Key__Data__, RAM_KEY] */
  /*  6283 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_Internal_Key__Data__, RAM_KEY] */
  /*  6284 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_IV__WrittenLength__, RAM_KEY] */
  /*  6285 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_IV__WrittenLength__, RAM_KEY] */
  /*  6286 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_IV__Valid__, RAM_KEY] */
  /*  6287 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_IV__Extension__, RAM_KEY] */
  /*  6288 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_IV__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_IV__Data__, RAM_KEY] */
  /*  6303 */  /* [vHsm_FirmwareUpdate_Encrypt__vHsm_FirmwareUpdate_IV__Data__, RAM_KEY] */
  /*  6304 */  /* [vHsm_FirmwareUpdate_Mac__vHsm_FirmwareUpdate_Internal_Key__WrittenLength__, RAM_KEY] */
  /*  6305 */  /* [vHsm_FirmwareUpdate_Mac__vHsm_FirmwareUpdate_Internal_Key__WrittenLength__, RAM_KEY] */
  /*  6306 */  /* [vHsm_FirmwareUpdate_Mac__vHsm_FirmwareUpdate_Internal_Key__Valid__, RAM_KEY] */
  /*  6307 */  /* [vHsm_FirmwareUpdate_Mac__vHsm_FirmwareUpdate_Internal_Key__Extension__, RAM_KEY] */
  /*  6308 */  /* [vHsm_FirmwareUpdate_Mac__vHsm_FirmwareUpdate_Internal_Key__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_FirmwareUpdate_Mac__vHsm_FirmwareUpdate_Internal_Key__Data__, RAM_KEY] */
  /*  6323 */  /* [vHsm_FirmwareUpdate_Mac__vHsm_FirmwareUpdate_Internal_Key__Data__, RAM_KEY] */
  /*  6324 */  /* [vHsm_FirmwareUpdate_Signature__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6325 */  /* [vHsm_FirmwareUpdate_Signature__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6326 */  /* [vHsm_FirmwareUpdate_Signature__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  6327 */  /* [vHsm_FirmwareUpdate_Signature__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  6328 */  /* [vHsm_FirmwareUpdate_Signature__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_FirmwareUpdate_Signature__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6359 */  /* [vHsm_FirmwareUpdate_Signature__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  6360 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_SharedValue__WrittenLength__, RAM_KEY] */
  /*  6361 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_SharedValue__WrittenLength__, RAM_KEY] */
  /*  6362 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_SharedValue__Valid__, RAM_KEY] */
  /*  6363 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_SharedValue__Extension__, RAM_KEY] */
  /*  6364 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*  6395 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_SharedValue__Data__, RAM_KEY] */
  /*  6396 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Base__WrittenLength__, RAM_KEY] */
  /*  6397 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Base__WrittenLength__, RAM_KEY] */
  /*  6398 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Base__Valid__, RAM_KEY] */
  /*  6399 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Base__Extension__, RAM_KEY] */
  /*  6400 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*  6415 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Base__Data__, RAM_KEY] */
  /*  6416 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_PrivKey__WrittenLength__, RAM_KEY] */
  /*  6417 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_PrivKey__WrittenLength__, RAM_KEY] */
  /*  6418 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_PrivKey__Valid__, RAM_KEY] */
  /*  6419 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_PrivKey__Extension__, RAM_KEY] */
  /*  6420 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*  6451 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_PrivKey__Data__, RAM_KEY] */
  /*  6452 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  6453 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  6454 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Valid__, RAM_KEY] */
  /*  6455 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Extension__, RAM_KEY] */
  /*  6456 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  6487 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  6488 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519__WrittenLength__, RAM_KEY] */
  /*  6489 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519__WrittenLength__, RAM_KEY] */
  /*  6490 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519__Valid__, RAM_KEY] */
  /*  6491 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519__Extension__, RAM_KEY] */
  /*  6492 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519__Data__, RAM_KEY] */
  /*  6493 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519__AlignDummy__, RAM_KEY] */
  /*   ... */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519__AlignDummy__, RAM_KEY] */
  /*  6495 */  /* [Ssa_SharedSecretExchangeKey__Crypto_30_LibCv_KeyExchange_Algorithm_X25519__AlignDummy__, RAM_KEY] */
  /*  6496 */  /* [KeyM_SigVerifyKey_TrustModelRoot__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6497 */  /* [KeyM_SigVerifyKey_TrustModelRoot__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6498 */  /* [KeyM_SigVerifyKey_TrustModelRoot__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  6499 */  /* [KeyM_SigVerifyKey_TrustModelRoot__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  6500 */  /* [KeyM_SigVerifyKey_TrustModelRoot__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_SigVerifyKey_TrustModelRoot__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6531 */  /* [KeyM_SigVerifyKey_TrustModelRoot__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6532 */  /* [KeyM_SigVerifyKey_TrustModelBackend__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6533 */  /* [KeyM_SigVerifyKey_TrustModelBackend__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6534 */  /* [KeyM_SigVerifyKey_TrustModelBackend__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  6535 */  /* [KeyM_SigVerifyKey_TrustModelBackend__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  6536 */  /* [KeyM_SigVerifyKey_TrustModelBackend__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_SigVerifyKey_TrustModelBackend__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6567 */  /* [KeyM_SigVerifyKey_TrustModelBackend__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  6568 */  /* [KeyM_SigVerifyKey_TrustModelIntermediate__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6569 */  /* [KeyM_SigVerifyKey_TrustModelIntermediate__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6570 */  /* [KeyM_SigVerifyKey_TrustModelIntermediate__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  6571 */  /* [KeyM_SigVerifyKey_TrustModelIntermediate__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  6572 */  /* [KeyM_SigVerifyKey_TrustModelIntermediate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_SigVerifyKey_TrustModelIntermediate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6603 */  /* [KeyM_SigVerifyKey_TrustModelIntermediate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6604 */  /* [KeyM_SigVerifyKey_TrustModelIntermediatePeer__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6605 */  /* [KeyM_SigVerifyKey_TrustModelIntermediatePeer__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6606 */  /* [KeyM_SigVerifyKey_TrustModelIntermediatePeer__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  6607 */  /* [KeyM_SigVerifyKey_TrustModelIntermediatePeer__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  6608 */  /* [KeyM_SigVerifyKey_TrustModelIntermediatePeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_SigVerifyKey_TrustModelIntermediatePeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6639 */  /* [KeyM_SigVerifyKey_TrustModelIntermediatePeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6640 */  /* [KeyM_SigVerifyKey_TrustModelEcuPeer__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6641 */  /* [KeyM_SigVerifyKey_TrustModelEcuPeer__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  6642 */  /* [KeyM_SigVerifyKey_TrustModelEcuPeer__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  6643 */  /* [KeyM_SigVerifyKey_TrustModelEcuPeer__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  6644 */  /* [KeyM_SigVerifyKey_TrustModelEcuPeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_SigVerifyKey_TrustModelEcuPeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6675 */  /* [KeyM_SigVerifyKey_TrustModelEcuPeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  6676 */  /* [Ssa_PduKeysMac__Ssa_MacKey_nonPersisting__WrittenLength__, RAM_KEY] */
  /*  6677 */  /* [Ssa_PduKeysMac__Ssa_MacKey_nonPersisting__WrittenLength__, RAM_KEY] */
  /*  6678 */  /* [Ssa_PduKeysMac__Ssa_MacKey_nonPersisting__Valid__, RAM_KEY] */
  /*  6679 */  /* [Ssa_PduKeysMac__Ssa_MacKey_nonPersisting__Extension__, RAM_KEY] */
  /*  6680 */  /* [Ssa_PduKeysMac__Ssa_MacKey_nonPersisting__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_PduKeysMac__Ssa_MacKey_nonPersisting__Data__, RAM_KEY] */
  /*  6695 */  /* [Ssa_PduKeysMac__Ssa_MacKey_nonPersisting__Data__, RAM_KEY] */
  /*  6696 */  /* [Ssa_PduKeysMac__Ssa_MacKey_Hash_nonPersisting__WrittenLength__, RAM_KEY] */
  /*  6697 */  /* [Ssa_PduKeysMac__Ssa_MacKey_Hash_nonPersisting__WrittenLength__, RAM_KEY] */
  /*  6698 */  /* [Ssa_PduKeysMac__Ssa_MacKey_Hash_nonPersisting__Valid__, RAM_KEY] */
  /*  6699 */  /* [Ssa_PduKeysMac__Ssa_MacKey_Hash_nonPersisting__Extension__, RAM_KEY] */
  /*  6700 */  /* [Ssa_PduKeysMac__Ssa_MacKey_Hash_nonPersisting__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_PduKeysMac__Ssa_MacKey_Hash_nonPersisting__Data__, RAM_KEY] */
  /*  6703 */  /* [Ssa_PduKeysMac__Ssa_MacKey_Hash_nonPersisting__Data__, RAM_KEY] */
  /*  6704 */  /* [KeyM_Cert_Root__Crypto_30_LibCv_KeyM_CertificateData__WrittenLength__, RAM_KEY] */
  /*  6705 */  /* [KeyM_Cert_Root__Crypto_30_LibCv_KeyM_CertificateData__WrittenLength__, RAM_KEY] */
  /*  6706 */  /* [KeyM_Cert_Root__Crypto_30_LibCv_KeyM_CertificateData__Valid__, RAM_KEY] */
  /*  6707 */  /* [KeyM_Cert_Root__Crypto_30_LibCv_KeyM_CertificateData__Extension__, RAM_KEY] */
  /*  6708 */  /* [KeyM_Cert_Root__Crypto_30_LibCv_KeyM_CertificateData__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_Cert_Root__Crypto_30_LibCv_KeyM_CertificateData__Data__, RAM_KEY] */
  /*  8207 */  /* [KeyM_Cert_Root__Crypto_30_LibCv_KeyM_CertificateData__Data__, RAM_KEY] */
  /*  8208 */  /* [KeyM_ECC_Intermediate__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  8209 */  /* [KeyM_ECC_Intermediate__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  8210 */  /* [KeyM_ECC_Intermediate__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  8211 */  /* [KeyM_ECC_Intermediate__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  8212 */  /* [KeyM_ECC_Intermediate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_ECC_Intermediate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  8243 */  /* [KeyM_ECC_Intermediate__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  8244 */  /* [KeyM_ECC_Root__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  8245 */  /* [KeyM_ECC_Root__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  8246 */  /* [KeyM_ECC_Root__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  8247 */  /* [KeyM_ECC_Root__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  8248 */  /* [KeyM_ECC_Root__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_ECC_Root__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  8279 */  /* [KeyM_ECC_Root__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  8280 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Key__WrittenLength__, RAM_KEY] */
  /*  8281 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Key__WrittenLength__, RAM_KEY] */
  /*  8282 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Key__Valid__, RAM_KEY] */
  /*  8283 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Key__Extension__, RAM_KEY] */
  /*  8284 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Key__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Key__Data__, RAM_KEY] */
  /*  8299 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Key__Data__, RAM_KEY] */
  /*  8300 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_IV__WrittenLength__, RAM_KEY] */
  /*  8301 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_IV__WrittenLength__, RAM_KEY] */
  /*  8302 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_IV__Valid__, RAM_KEY] */
  /*  8303 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_IV__Extension__, RAM_KEY] */
  /*  8304 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_IV__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_IV__Data__, RAM_KEY] */
  /*  8319 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_IV__Data__, RAM_KEY] */
  /*  8320 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Proof__WrittenLength__, RAM_KEY] */
  /*  8321 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Proof__WrittenLength__, RAM_KEY] */
  /*  8322 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Proof__Valid__, RAM_KEY] */
  /*  8323 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Proof__Extension__, RAM_KEY] */
  /*  8324 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Proof__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Proof__Data__, RAM_KEY] */
  /*  8371 */  /* [vHsm_Custom__Crypto_30_LibCv_Cipher_Proof__Data__, RAM_KEY] */
  /*  8372 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_Decrypt_Key__WrittenLength__, RAM_KEY] */
  /*  8373 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_Decrypt_Key__WrittenLength__, RAM_KEY] */
  /*  8374 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_Decrypt_Key__Valid__, RAM_KEY] */
  /*  8375 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_Decrypt_Key__Extension__, RAM_KEY] */
  /*  8376 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_Decrypt_Key__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_Decrypt_Key__Data__, RAM_KEY] */
  /*  8391 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_Decrypt_Key__Data__, RAM_KEY] */
  /*  8392 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_IV__WrittenLength__, RAM_KEY] */
  /*  8393 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_IV__WrittenLength__, RAM_KEY] */
  /*  8394 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_IV__Valid__, RAM_KEY] */
  /*  8395 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_IV__Extension__, RAM_KEY] */
  /*  8396 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_IV__Data__, RAM_KEY] */
  /*   ... */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_IV__Data__, RAM_KEY] */
  /*  8411 */  /* [vHsm_FirmwareUpdate_Decrypt__vHsm_FirmwareUpdate_IV__Data__, RAM_KEY] */
  /*  8412 */  /* [Ssa_AesRamKey__Ssa_Cipher_Key__WrittenLength__, RAM_KEY] */
  /*  8413 */  /* [Ssa_AesRamKey__Ssa_Cipher_Key__WrittenLength__, RAM_KEY] */
  /*  8414 */  /* [Ssa_AesRamKey__Ssa_Cipher_Key__Valid__, RAM_KEY] */
  /*  8415 */  /* [Ssa_AesRamKey__Ssa_Cipher_Key__Extension__, RAM_KEY] */
  /*  8416 */  /* [Ssa_AesRamKey__Ssa_Cipher_Key__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_AesRamKey__Ssa_Cipher_Key__Data__, RAM_KEY] */
  /*  8431 */  /* [Ssa_AesRamKey__Ssa_Cipher_Key__Data__, RAM_KEY] */
  /*  8432 */  /* [Ssa_AesRamKey__Ssa_Cipher_IV__WrittenLength__, RAM_KEY] */
  /*  8433 */  /* [Ssa_AesRamKey__Ssa_Cipher_IV__WrittenLength__, RAM_KEY] */
  /*  8434 */  /* [Ssa_AesRamKey__Ssa_Cipher_IV__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  8435 */  /* [Ssa_AesRamKey__Ssa_Cipher_IV__Extension__, RAM_KEY] */
  /*  8436 */  /* [Ssa_AesRamKey__Ssa_Cipher_IV__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_AesRamKey__Ssa_Cipher_IV__Data__, RAM_KEY] */
  /*  8451 */  /* [Ssa_AesRamKey__Ssa_Cipher_IV__Data__, RAM_KEY] */
  /*  8452 */  /* [KeyM_SigVerifyKey_TrustModelBackendPeer__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  8453 */  /* [KeyM_SigVerifyKey_TrustModelBackendPeer__Crypto_30_LibCv_Signature_Key__WrittenLength__, RAM_KEY] */
  /*  8454 */  /* [KeyM_SigVerifyKey_TrustModelBackendPeer__Crypto_30_LibCv_Signature_Key__Valid__, RAM_KEY] */
  /*  8455 */  /* [KeyM_SigVerifyKey_TrustModelBackendPeer__Crypto_30_LibCv_Signature_Key__Extension__, RAM_KEY] */
  /*  8456 */  /* [KeyM_SigVerifyKey_TrustModelBackendPeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*   ... */  /* [KeyM_SigVerifyKey_TrustModelBackendPeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  8487 */  /* [KeyM_SigVerifyKey_TrustModelBackendPeer__Crypto_30_LibCv_Signature_Key__Data__, RAM_KEY] */
  /*  8488 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  8489 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  8490 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Valid__, RAM_KEY] */
  /*  8491 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Extension__, RAM_KEY] */
  /*  8492 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  8523 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  8524 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__WrittenLength__, RAM_KEY] */
  /*  8525 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__WrittenLength__, RAM_KEY] */
  /*  8526 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Valid__, RAM_KEY] */
  /*  8527 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Extension__, RAM_KEY] */
  /*  8528 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Data__, RAM_KEY] */
  /*  8529 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*   ... */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*  8531 */  /* [Ssa_TrustModelPrivateEcuUnique_StagingKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*  8532 */  /* [Ssa_SignatureRamKey_replacementAuthority__Crypto_30_LibCv_Signature_Key_replacementAuthority__WrittenLength__, RAM_KEY] */
  /*  8533 */  /* [Ssa_SignatureRamKey_replacementAuthority__Crypto_30_LibCv_Signature_Key_replacementAuthority__WrittenLength__, RAM_KEY] */
  /*  8534 */  /* [Ssa_SignatureRamKey_replacementAuthority__Crypto_30_LibCv_Signature_Key_replacementAuthority__Valid__, RAM_KEY] */
  /*  8535 */  /* [Ssa_SignatureRamKey_replacementAuthority__Crypto_30_LibCv_Signature_Key_replacementAuthority__Extension__, RAM_KEY] */
  /*  8536 */  /* [Ssa_SignatureRamKey_replacementAuthority__Crypto_30_LibCv_Signature_Key_replacementAuthority__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_SignatureRamKey_replacementAuthority__Crypto_30_LibCv_Signature_Key_replacementAuthority__Data__, RAM_KEY] */
  /*  8567 */  /* [Ssa_SignatureRamKey_replacementAuthority__Crypto_30_LibCv_Signature_Key_replacementAuthority__Data__, RAM_KEY] */
  /*  8568 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__WrittenLength__, RAM_KEY] */
  /*  8569 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__WrittenLength__, RAM_KEY] */
  /*  8570 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Valid__, RAM_KEY] */
  /*  8571 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Extension__, RAM_KEY] */
  /*  8572 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Data__, RAM_KEY] */
  /*  8603 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Data__, RAM_KEY] */
  /*  8604 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  8605 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  8606 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Valid__, RAM_KEY] */
  /*  8607 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Extension__, RAM_KEY] */
  /*  8608 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  8639 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  8640 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__WrittenLength__, RAM_KEY] */
  /*  8641 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__WrittenLength__, RAM_KEY] */
  /*  8642 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Valid__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  8643 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Extension__, RAM_KEY] */
  /*  8644 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Data__, RAM_KEY] */
  /*  8645 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*   ... */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*  8647 */  /* [Ssa_TrustModel_Ecu_CsrPrivateKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*  8648 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__WrittenLength__, RAM_KEY] */
  /*  8649 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__WrittenLength__, RAM_KEY] */
  /*  8650 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Valid__, RAM_KEY] */
  /*  8651 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Extension__, RAM_KEY] */
  /*  8652 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Data__, RAM_KEY] */
  /*  8683 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Ssa_TrustModel_Csr_Key_NonPersisting_Element__Data__, RAM_KEY] */
  /*  8684 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  8685 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__WrittenLength__, RAM_KEY] */
  /*  8686 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Valid__, RAM_KEY] */
  /*  8687 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Extension__, RAM_KEY] */
  /*  8688 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*   ... */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  8719 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyExchange_OwnPubKey__Data__, RAM_KEY] */
  /*  8720 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__WrittenLength__, RAM_KEY] */
  /*  8721 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__WrittenLength__, RAM_KEY] */
  /*  8722 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Valid__, RAM_KEY] */
  /*  8723 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Extension__, RAM_KEY] */
  /*  8724 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__Data__, RAM_KEY] */
  /*  8725 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*   ... */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*  8727 */  /* [Ssa_TrustModel_Ecu_CsrPublicKey__Crypto_30_LibCv_KeyGenerate_Algorithm_Ed25519__AlignDummy__, RAM_KEY] */
  /*  8728 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__WrittenLength__, RAM_KEY] */
  /*  8729 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__WrittenLength__, RAM_KEY] */
  /*  8730 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Valid__, RAM_KEY] */
  /*  8731 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Extension__, RAM_KEY] */
  /*  8732 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Data__, RAM_KEY] */
  /*  8763 */  /* [CryptoKey_Fbl_Signature_Ed25519__Crypto_30_LibCv_Fbl_Signature_Ed25519_Key__Data__, RAM_KEY] */
  /*  8764 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__WrittenLength__, RAM_KEY] */
  /*  8765 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__WrittenLength__, RAM_KEY] */
  /*  8766 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Valid__, RAM_KEY] */
  /*  8767 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Extension__, RAM_KEY] */
  /*  8768 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Data__, RAM_KEY] */
  /*  8783 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Key__Data__, RAM_KEY] */
  /*  8784 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__WrittenLength__, RAM_KEY] */
  /*  8785 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__WrittenLength__, RAM_KEY] */
  /*  8786 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Valid__, RAM_KEY] */
  /*  8787 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Extension__, RAM_KEY] */
  /*  8788 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Data__, RAM_KEY] */
  /*  8803 */  /* [CryptoKey_Fbl_Decrypt_Aes128__Crypto_30_LibCv_Fbl_Decrypt_Aes128_Iv__Data__, RAM_KEY] */
  /*  8804 */  /* [CryptoKey_Fbl_SecurityAccess_Ed25519__Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key__WrittenLength__, RAM_KEY] */
  /*  8805 */  /* [CryptoKey_Fbl_SecurityAccess_Ed25519__Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key__WrittenLength__, RAM_KEY] */
  /* Index        Referable Keys */
  /*  8806 */  /* [CryptoKey_Fbl_SecurityAccess_Ed25519__Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key__Valid__, RAM_KEY] */
  /*  8807 */  /* [CryptoKey_Fbl_SecurityAccess_Ed25519__Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key__Extension__, RAM_KEY] */
  /*  8808 */  /* [CryptoKey_Fbl_SecurityAccess_Ed25519__Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Fbl_SecurityAccess_Ed25519__Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key__Data__, RAM_KEY] */
  /*  8839 */  /* [CryptoKey_Fbl_SecurityAccess_Ed25519__Crypto_30_LibCv_Fbl_SecurityAccess_Ed25519_Key__Data__, RAM_KEY] */
  /*  8840 */  /* [vHSM_Custom_HSM_Version__vHsm_Version__WrittenLength__, RAM_KEY] */
  /*  8841 */  /* [vHSM_Custom_HSM_Version__vHsm_Version__WrittenLength__, RAM_KEY] */
  /*  8842 */  /* [vHSM_Custom_HSM_Version__vHsm_Version__Valid__, RAM_KEY] */
  /*  8843 */  /* [vHSM_Custom_HSM_Version__vHsm_Version__Extension__, RAM_KEY] */
  /*  8844 */  /* [vHSM_Custom_HSM_Version__vHsm_Version__Data__, RAM_KEY] */
  /*   ... */  /* [vHSM_Custom_HSM_Version__vHsm_Version__Data__, RAM_KEY] */
  /*  8846 */  /* [vHSM_Custom_HSM_Version__vHsm_Version__Data__, RAM_KEY] */
  /*  8847 */  /* [vHSM_Custom_HSM_Version__vHsm_Version__AlignDummy__, RAM_KEY] */

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
VAR(Crypto_30_LibCv_LockType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Lock[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Verify, KeyGenEd25519] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_KeyM, EcP256Verify] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Dec, AesDecrypt] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Enc, AesEncrypt] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Mac, CmacAesGenerate] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig, Ed25519Verify, EcP256Verify] */

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
  /*     0 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_KeyM] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Dec] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Enc] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Mac] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_vHsm_LibCv
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_vHsm_LibCv
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_vHsm_LibCv_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_vHsm_LibCv;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_vHsm_LibCv_HighPrio_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_vHsm_LibCv_HighPrio;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_vHsm_LibCv_KeyM
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_vHsm_LibCv_KeyM
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_KeyM.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_vHsm_LibCv_KeyM_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_vHsm_LibCv_KeyM;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Dec
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Dec
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Dec.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_vHsm_LibCv_vHsmUpd_Dec_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Dec;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Enc
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Enc
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Enc.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_vHsm_LibCv_vHsmUpd_Enc_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Enc;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Mac
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Mac
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Mac.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_vHsm_LibCv_vHsmUpd_Mac_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Mac;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Sig
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Sig
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_vHsm_LibCv_vHsmUpd_Sig_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_vHsm_LibCv_vHsmUpd_Sig;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(Crypto_30_LibCv_WrittenLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLength[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES, Ed25519Generate, Ed25519Verify, EcP256Verify, KeyGenEd25519] */
  /*     1 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_HighPrio, AesEncrypt, AesDecrypt, SHA256, SHA512, CmacAesGenerate, CmacAesVerify, DRBGAES] */
  /*     2 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_KeyM, EcP256Verify] */
  /*     3 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Dec, AesDecrypt] */
  /*     4 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Enc, AesEncrypt] */
  /*     5 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Mac, CmacAesGenerate] */
  /*     6 */  /* [/ActiveEcuC/Crypto_30_LibCv/CryptoDriverObjects/vHsm_LibCv_vHsmUpd_Sig, Ed25519Verify, EcP256Verify] */

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


#define CRYPTO_30_LIBCV_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
/**********************************************************************************************************************
 *  Function Group ReadFromBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_SecOC
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_SecOC(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_SecOC, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_SharedSecretHash
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_SharedSecretHash(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_SharedSecretHash, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_TrustModel_NoRoot
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_TrustModel_NoRoot(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_TrustModel_NoRoot, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_TrustModel_Root
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Deferred_TrustModel_Root(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_TrustModel_Root, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate_BackendCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate_BackendCert(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate_BackendCert, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate_RootCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_ReadFrom_CryptoNvBlock_Immediate_RootCert(P2CONST(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_DATA) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_ReadFromBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate_RootCert, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Function Group WriteToBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_SecOC
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_SecOC(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_SecOC, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_SharedSecretHash
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_SharedSecretHash(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_SharedSecretHash, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_TrustModel_NoRoot
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_TrustModel_NoRoot(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_TrustModel_NoRoot, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_TrustModel_Root
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Deferred_TrustModel_Root(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_TrustModel_Root, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate_BackendCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate_BackendCert(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate_BackendCert, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate_RootCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_WriteTo_CryptoNvBlock_Immediate_RootCert(P2VAR(void, AUTOMATIC, CRYPTO_30_LIBCV_APPL_VAR) NvMBuffer)
{
  return Crypto_30_LibCv_NvBlock_WriteToBlock((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate_RootCert, NvMBuffer);  /* SBSW_CRYPTO_30_LIBCV_FORWARDING_AND_ACCESS_TO_NVBUFFER */
}

/**********************************************************************************************************************
 *  Function Group InitBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_SecOC
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_SecOC(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_SecOC);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_SharedSecretHash
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_SharedSecretHash(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_SharedSecretHash);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_TrustModel_NoRoot
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_TrustModel_NoRoot(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_TrustModel_NoRoot);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_TrustModel_Root
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Deferred_TrustModel_Root(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_TrustModel_Root);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate_BackendCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate_BackendCert(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate_BackendCert);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate_RootCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Init_CryptoNvBlock_Immediate_RootCert(void)
{
  return Crypto_30_LibCv_NvBlock_Init((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate_RootCert);
}

/**********************************************************************************************************************
 *  Function Group CallbackBlock
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate, ServiceId, JobResult);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred, ServiceId, JobResult);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_SecOC
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_SecOC(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_SecOC, ServiceId, JobResult);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_SharedSecretHash
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_SharedSecretHash(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_SharedSecretHash, ServiceId, JobResult);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_TrustModel_NoRoot
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_TrustModel_NoRoot(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_TrustModel_NoRoot, ServiceId, JobResult);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_TrustModel_Root
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Deferred_TrustModel_Root(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Deferred_TrustModel_Root, ServiceId, JobResult);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate_BackendCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate_BackendCert(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate_BackendCert, ServiceId, JobResult);
}

/**********************************************************************************************************************
 *  Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate_RootCert
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_LIBCV_CODE) Crypto_30_LibCv_NvBlock_Callback_CryptoNvBlock_Immediate_RootCert(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult)
{
  return Crypto_30_LibCv_NvBlock_Callback((Crypto_30_LibCv_SizeOfNvBlockType)CryptoConf_CryptoNvBlock_CryptoNvBlock_Immediate_RootCert, ServiceId, JobResult);
}

#define CRYPTO_30_LIBCV_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_LibCv_Cfg.c
 *********************************************************************************************************************/
