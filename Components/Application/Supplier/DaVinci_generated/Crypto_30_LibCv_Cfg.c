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
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_LibCv_Cfg.c
 *   Generation Time: 2023-07-18 14:15:20
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
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
#include "Crypto_30_LibCv_Hash.h"



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
  /*     2 */ VSECPRIM_DIGEST_SHA2_224     ,  /* [CRYPTO_ALGOFAM_SHA2_224] */
  /*     3 */ VSECPRIM_DIGEST_SHA2_256     ,  /* [CRYPTO_ALGOFAM_SHA2_256] */
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
    /* Index    Workspace                                                               Referable Keys */
  { /*     0 */ &Crypto_30_LibCv_UnionWS_CryptoDriverObject_Ssa_Hash.primWS.Hash }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Ssa_Hash] */
};
#define CRYPTO_30_LIBCV_STOP_SEC_CONST_UNSPECIFIED
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
CONST(Crypto_30_LibCv_KeyType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_Key[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    KeyElementsEndIdx  KeyElementsStartIdx        Referable Keys */
  { /*     0 */                2u,                  0u }   /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Ssa_Hash] */
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
  Element       Description
  Id        
  Length    
  MaskedBits    contains bitcoded the boolean data of Crypto_30_LibCv_OnceOfKeyElementInfo, Crypto_30_LibCv_PartialOfKeyElementInfo, Crypto_30_LibCv_PersistOfKeyElementInfo
  Read      
  Write     
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_KeyElementInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElementInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  Length  MaskedBits  Read                        Write                             Referable Keys */
  { /*     0 */ 1u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED },  /* [/ActiveEcuC/Crypto/CryptoKeyElements/Ssa_Cipher_Key] */
  { /*     1 */ 5u,    16u,      0x00u, CRYPTO_30_LIBCV_RA_ALLOWED, CRYPTO_30_LIBCV_WA_ALLOWED }   /* [/ActiveEcuC/Crypto/CryptoKeyElements/Ssa_Cipher_IV] */
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
CONST(Crypto_30_LibCv_KeyElementsType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_KeyElements[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Id  KeyElementInfoIdx  KeyStorageEndIdx  KeyStorageExtensionIdx  KeyStorageStartIdx  KeyStorageValidIdx  KeyStorageWrittenLengthEndIdx  KeyStorageWrittenLengthStartIdx        Referable Keys */
  { /*     0 */ 1u,                0u,              20u,                     3u,                 4u,                 2u,                            2u,                              0u },  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Ssa_Hash, CryptoKey_Ssa_Hash__Ssa_Cipher_Key] */
  { /*     1 */ 5u,                1u,              40u,                    23u,                24u,                22u,                           22u,                             20u }   /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Ssa_Hash, CryptoKey_Ssa_Hash__Ssa_Cipher_IV] */
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
  Element            Description
  WorkspaceLength    Holds the length of the workspace.
  HashIdx            the index of the 0:1 relation pointing to Crypto_30_LibCv_Hash
  QueueIdx           the index of the 1:1 relation pointing to Crypto_30_LibCv_Queue
  WorkspaceAddr      Holds the address of the workspace.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Crypto_30_LibCv_ObjectInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    WorkspaceLength                                              HashIdx  QueueIdx  WorkspaceAddr                                                                                                    Referable Keys */
  { /*     0 */ sizeof(Crypto_30_LibCv_WS_CryptoDriverObject_Ssa_Hash_Type),      0u,       0u, (P2VAR(uint8, AUTOMATIC, CRYPTO_30_LIBCV_VAR_NOINIT))&Crypto_30_LibCv_UnionWS_CryptoDriverObject_Ssa_Hash }   /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Ssa_Hash, SHA512] */
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
CONST(Crypto_30_LibCv_ObjectInfoIndType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_ObjectInfoInd[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ObjectInfoInd      Referable Keys */
  /*     0 */             0u   /* [SHA512] */
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
CONST(Crypto_30_LibCv_PrimitiveFctType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveFct[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ObjectInfoIndEndIdx  ObjectInfoIndStartIdx  Dispatch                             Referable Keys */
  { /*     0 */                  1u,                    0u, Crypto_30_LibCv_Dispatch_Hash }   /* [SHA512] */
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
CONST(Crypto_30_LibCv_PrimitiveInfoType, CRYPTO_30_LIBCV_CONST) Crypto_30_LibCv_PrimitiveInfo[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Combined                                                                                                                                                   MaskedBits  PrimitiveFctIdx        Referable Keys */
  { /*     0 */ ((((uint32)CRYPTO_HASH) << 24) | (((uint32)CRYPTO_ALGOFAM_SHA2_512) << 16) | (((uint32)CRYPTO_ALGOMODE_NOT_SET) << 8) | ((uint32)CRYPTO_ALGOFAM_NOT_SET)),      0x00u,              0u }   /* [CRYPTO_HASH] */
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
  { /*     0 */                                                           1u,                                                             0u },  /* [CRYPTO_HASH] */
  { /*     1 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_MACGENERATE] */
  { /*     2 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_MACVERIFY] */
  { /*     3 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_ENCRYPT] */
  { /*     4 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_DECRYPT] */
  { /*     5 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_AEADENCRYPT] */
  { /*     6 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_AEADDECRYPT] */
  { /*     7 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SIGNATUREGENERATE] */
  { /*     8 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SIGNATUREVERIFY] */
  { /*     9 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERINCREMENT] */
  { /*    10 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_SECCOUNTERREAD] */
  { /*    11 */ CRYPTO_30_LIBCV_NO_PRIMITIVEINFOENDIDXOFPRIMITIVESERVICEINFO, CRYPTO_30_LIBCV_NO_PRIMITIVEINFOSTARTIDXOFPRIMITIVESERVICEINFO },  /* [CRYPTO_RANDOMGENERATE] */
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
VAR(Crypto_30_LibCv_BufferLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_BufferLength[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Ssa_Hash, SHA512] */

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
VAR(Crypto_30_LibCv_DriverObjectStateType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_DriverObjectState[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Ssa_Hash, SHA512] */

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
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoKeys/CryptoKey_Ssa_Hash] */

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
VAR(Crypto_30_LibCv_KeyStorageType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_KeyStorage[40];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_Key__WrittenLength__, RAM_KEY] */
  /*     1 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_Key__WrittenLength__, RAM_KEY] */
  /*     2 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_Key__Valid__, RAM_KEY] */
  /*     3 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_Key__Extension__, RAM_KEY] */
  /*     4 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_Key__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_Key__Data__, RAM_KEY] */
  /*    19 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_Key__Data__, RAM_KEY] */
  /*    20 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_IV__WrittenLength__, RAM_KEY] */
  /*    21 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_IV__WrittenLength__, RAM_KEY] */
  /*    22 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_IV__Valid__, RAM_KEY] */
  /*    23 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_IV__Extension__, RAM_KEY] */
  /*    24 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_IV__Data__, RAM_KEY] */
  /*   ... */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_IV__Data__, RAM_KEY] */
  /*    39 */  /* [CryptoKey_Ssa_Hash__Ssa_Cipher_IV__Data__, RAM_KEY] */

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
VAR(Crypto_30_LibCv_LockType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_Lock[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Ssa_Hash, SHA512] */

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
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Ssa_Hash] */

#define CRYPTO_30_LIBCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_LibCv_UnionWS_CryptoDriverObject_Ssa_Hash
**********************************************************************************************************************/
/** 
  \var    Crypto_30_LibCv_UnionWS_CryptoDriverObject_Ssa_Hash
  \brief  Union variable which acts as workspace for driver object /ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Ssa_Hash.
*/ 
#define CRYPTO_30_LIBCV_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_LibCv_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Crypto_30_LibCv_WS_CryptoDriverObject_Ssa_Hash_Type, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_UnionWS_CryptoDriverObject_Ssa_Hash;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
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
VAR(Crypto_30_LibCv_WrittenLengthType, CRYPTO_30_LIBCV_VAR_NOINIT) Crypto_30_LibCv_WrittenLength[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Crypto/CryptoDriverObjects/CryptoDriverObject_Ssa_Hash, SHA512] */

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
