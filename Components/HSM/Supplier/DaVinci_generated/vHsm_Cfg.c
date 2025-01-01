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
 *            Module: vHsm
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vHsm_Cfg.c
 *   Generation Time: 2023-08-16 13:28:24
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#define VHSM_CFG_SOURCE


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm_Cfg.h"
#include "vHsm.h"
#include "vHsm_Ipc.h"
#include "Csm_Cfg.h"
#include "CryIf_Cfg.h"
#include "SchM_vHsm.h"
#include "Fee.h"
#include "Crypto_30_LibCv.h"
#include "Crypto_30_vHsm_Core.h"
#include "Crypto_30_vHsm_Custom.h"
#include "Crypto_30_KeyM.h"
#include "Crypto_30_Hwa.h"
#include "vHsm_JobProcessor.h"



/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (STATIC)
# define STATIC static
#endif

#if !defined (VHSM_LOCAL)
# define VHSM_LOCAL static
#endif

#if !defined (VHSM_LOCAL_INLINE)
# define VHSM_LOCAL_INLINE LOCAL_INLINE
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
  vHsm_ChannelInfo
**********************************************************************************************************************/
/** 
  \var    vHsm_ChannelInfo
  \brief  Contains attributes per Channel, accessible by external CryIfChannelId
  \details
  Element               Description
  DriverObjectRef   
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to vHsm_CryptoFunctions
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_ChannelInfoType, VHSM_CONST) vHsm_ChannelInfo[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DriverObjectRef                                       CryptoFunctionsIdx        Referable Keys */
  { /*     0 */ CryptoConf_CryptoDriverObject_vHsm_Core             ,                 1u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Core] */
  { /*     1 */ CryptoConf_CryptoDriverObject_vHsm_Hwa              ,                 4u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Hwa] */
  { /*     2 */ CryptoConf_CryptoDriverObject_vHsm_Hwa_HighPrio     ,                 4u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Hwa_HighPrio] */
  { /*     3 */ CryptoConf_CryptoDriverObject_Crypto_30_KeyM        ,                 3u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyM] */
  { /*     4 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_KeyM       ,                 0u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyM_LibCv] */
  { /*     5 */ CryptoConf_CryptoDriverObject_vHsm_KeyManagement    ,                 1u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyManagement] */
  { /*     6 */ CryptoConf_CryptoDriverObject_vHsm_LibCv            ,                 0u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv] */
  { /*     7 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_HighPrio   ,                 0u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_HighPrio] */
  { /*     8 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_vHsmUpd_Dec,                 0u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Dec] */
  { /*     9 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_vHsmUpd_Enc,                 0u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Enc] */
  { /*    10 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_vHsmUpd_Mac,                 0u },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Mac] */
  { /*    11 */ CryptoConf_CryptoDriverObject_vHsm_LibCv_vHsmUpd_Sig,                 0u }   /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Sig] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_CoreKey
**********************************************************************************************************************/
/** 
  \var    vHsm_CoreKey
  \brief  Contains keys of vHsm_Core, accessible by external KeyId reduced by offset of 30000.
  \details
  Element                  Description
  AggregatedCryptoKeyId
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_CoreKeyType, VHSM_CONST) vHsm_CoreKey[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    AggregatedCryptoKeyId                 Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_vHsm_Info },  /* [/ActiveEcuC/vHsm_Core/CryptoKeys/vHsmInfo] */
  { /*     1 */ 0xFFFFFFFFu                    },  /* [/ActiveEcuC/vHsm_Core/CryptoKeys/vHsmSecureBootGroupInfo] */
  { /*     2 */ 0xFFFFFFFFu                    }   /* [/ActiveEcuC/vHsm_Core/CryptoKeys/vHsmLog] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_CryptoFunctions
**********************************************************************************************************************/
/** 
  \var    vHsm_CryptoFunctions
  \details
  Element                  Description
  CancelJob            
  CertificateParse     
  CertificateVerify    
  KeyCopy              
  KeyDerive            
  KeyElementCopy       
  KeyElementCopyPartial
  KeyElementGet        
  KeyElementIdsGet     
  KeyElementSet        
  KeyExchangeCalcPubVal
  KeyExchangeCalcSecret
  KeyGenerate          
  KeyValidSet          
  ProcessJob           
  RandomSeed           
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_CryptoFunctionsType, VHSM_CONST) vHsm_CryptoFunctions[5] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CancelJob                        CertificateParse                        CertificateVerify                        KeyCopy                        KeyDerive                        KeyElementCopy                        KeyElementCopyPartial                  KeyElementGet                        KeyElementIdsGet                        KeyElementSet                        KeyExchangeCalcPubVal                        KeyExchangeCalcSecret                        KeyGenerate                        KeyValidSet                        ProcessJob                        RandomSeed                              Referable Keys */
  { /*     0 */ Crypto_30_LibCv_CancelJob      , Crypto_30_LibCv_CertificateParse      , Crypto_30_LibCv_CertificateVerify      , Crypto_30_LibCv_KeyCopy      , Crypto_30_LibCv_KeyDerive      , Crypto_30_LibCv_KeyElementCopy      , Crypto_30_LibCv_KeyElementCopyPartial, Crypto_30_LibCv_KeyElementGet      , Crypto_30_LibCv_KeyElementIdsGet      , Crypto_30_LibCv_KeyElementSet      , Crypto_30_LibCv_KeyExchangeCalcPubVal      , Crypto_30_LibCv_KeyExchangeCalcSecret      , Crypto_30_LibCv_KeyGenerate      , Crypto_30_LibCv_KeyValidSet      , Crypto_30_LibCv_ProcessJob      , Crypto_30_LibCv_RandomSeed       },  /* [Crypto_30_LibCv] */
  { /*     1 */ Crypto_30_vHsm_Core_CancelJob  , Crypto_30_vHsm_Core_CertificateParse  , Crypto_30_vHsm_Core_CertificateVerify  , Crypto_30_vHsm_Core_KeyCopy  , Crypto_30_vHsm_Core_KeyDerive  , Crypto_30_vHsm_Core_KeyElementCopy  , vHsm_Core_KeyElementCopyPartial      , Crypto_30_vHsm_Core_KeyElementGet  , Crypto_30_vHsm_Core_KeyElementIdsGet  , Crypto_30_vHsm_Core_KeyElementSet  , Crypto_30_vHsm_Core_KeyExchangeCalcPubVal  , Crypto_30_vHsm_Core_KeyExchangeCalcSecret  , Crypto_30_vHsm_Core_KeyGenerate  , Crypto_30_vHsm_Core_KeyValidSet  , Crypto_30_vHsm_Core_ProcessJob  , Crypto_30_vHsm_Core_RandomSeed   },  /* [Crypto_30_vHsm_Core] */
  { /*     2 */ Crypto_30_vHsm_Custom_CancelJob, Crypto_30_vHsm_Custom_CertificateParse, Crypto_30_vHsm_Custom_CertificateVerify, Crypto_30_vHsm_Custom_KeyCopy, Crypto_30_vHsm_Custom_KeyDerive, Crypto_30_vHsm_Custom_KeyElementCopy, vHsm_Core_KeyElementCopyPartial      , Crypto_30_vHsm_Custom_KeyElementGet, Crypto_30_vHsm_Custom_KeyElementIdsGet, Crypto_30_vHsm_Custom_KeyElementSet, Crypto_30_vHsm_Custom_KeyExchangeCalcPubVal, Crypto_30_vHsm_Custom_KeyExchangeCalcSecret, Crypto_30_vHsm_Custom_KeyGenerate, Crypto_30_vHsm_Custom_KeyValidSet, Crypto_30_vHsm_Custom_ProcessJob, Crypto_30_vHsm_Custom_RandomSeed },  /* [Crypto_30_vHsm_Custom] */
  { /*     3 */ Crypto_30_KeyM_CancelJob       , Crypto_30_KeyM_CertificateParse       , Crypto_30_KeyM_CertificateVerify       , Crypto_30_KeyM_KeyCopy       , Crypto_30_KeyM_KeyDerive       , Crypto_30_KeyM_KeyElementCopy       , vHsm_Core_KeyElementCopyPartial      , Crypto_30_KeyM_KeyElementGet       , Crypto_30_KeyM_KeyElementIdsGet       , Crypto_30_KeyM_KeyElementSet       , Crypto_30_KeyM_KeyExchangeCalcPubVal       , Crypto_30_KeyM_KeyExchangeCalcSecret       , Crypto_30_KeyM_KeyGenerate       , Crypto_30_KeyM_KeyValidSet       , Crypto_30_KeyM_ProcessJob       , Crypto_30_KeyM_RandomSeed        },  /* [Crypto_30_KeyM] */
  { /*     4 */ Crypto_30_Hwa_CancelJob        , Crypto_30_Hwa_CertificateParse        , Crypto_30_Hwa_CertificateVerify        , Crypto_30_Hwa_KeyCopy        , Crypto_30_Hwa_KeyDerive        , Crypto_30_Hwa_KeyElementCopy        , vHsm_Core_KeyElementCopyPartial      , Crypto_30_Hwa_KeyElementGet        , Crypto_30_Hwa_KeyElementIdsGet        , Crypto_30_Hwa_KeyElementSet        , Crypto_30_Hwa_KeyExchangeCalcPubVal        , Crypto_30_Hwa_KeyExchangeCalcSecret        , Crypto_30_Hwa_KeyGenerate        , Crypto_30_Hwa_KeyValidSet        , Crypto_30_Hwa_ProcessJob        , Crypto_30_Hwa_RandomSeed         }   /* [Crypto_30_Hwa] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_DriverObjectMapping
**********************************************************************************************************************/
/** 
  \var    vHsm_DriverObjectMapping
  \brief  Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmIpc/vHsmIpcInstance/vHsmDriverObjectMapping.
*/ 
#define VHSM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_DriverObjectMappingType, VHSM_CONST) vHsm_DriverObjectMapping[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     DriverObjectMapping                                       Referable Keys */
  /*     0 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_KeyManagement  ,  /* [/ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance[0:vHsmDriverObjectMapping], /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance, /ActiveEcuC/CryIf/Crypto_30_vHsm_KeyManagement] */
  /*     1 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_HighPrio ,  /* [/ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance[1:vHsmDriverObjectMapping], /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance, /ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_HighPrio] */
  /*     2 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_KeyM_LibCv     ,  /* [/ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance[2:vHsmDriverObjectMapping], /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance, /ActiveEcuC/CryIf/Crypto_30_vHsm_KeyM_LibCv] */
  /*     3 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_Core           ,  /* [/ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance[3:vHsmDriverObjectMapping], /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance, /ActiveEcuC/CryIf/Crypto_30_vHsm_Core] */
  /*     4 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv          ,  /* [/ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance[4:vHsmDriverObjectMapping], /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance, /ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv] */
  /*     5 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_Hwa_HighPrio   ,  /* [/ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance[5:vHsmDriverObjectMapping], /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance, /ActiveEcuC/CryIf/Crypto_30_vHsm_Hwa_HighPrio] */
  /*     6 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_Hwa               /* [/ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance[6:vHsmDriverObjectMapping], /ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance, /ActiveEcuC/CryIf/Crypto_30_vHsm_Hwa] */
};
#define VHSM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_IpcInstance
**********************************************************************************************************************/
/** 
  \var    vHsm_IpcInstance
  \brief  Contains parameters of /MICROSAR/vHsm/vHsmIpc/vHsmIpcInstance.
  \details
  Element    Description
  Memory 
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_IpcInstanceType, VHSM_CONST) vHsm_IpcInstance[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Memory                                                                                      Referable Keys */
  { /*     0 */ (vHsm_Ipc_MemoryPtrType)0xB0000000  /* PRQA S 0306 */ /* MD_VHSM_0306_IPC_ADDRESS */ }   /* [/ActiveEcuC/vHsm/vHsmIpc/vHsmIpcInstance, /ActiveEcuC/vHsm/vHsmIpc] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_JobObjectInfo
**********************************************************************************************************************/
/** 
  \var    vHsm_JobObjectInfo
  \brief  Contains attributes per Key, accessible by external KeyId
  \details
  Element          Description
  MaskedBits       contains bitcoded the boolean data of vHsm_EventTriggeredOfJobObjectInfo, vHsm_IsrProcessingOfJobObjectInfo
  SchedEventRef    Event that needs to be triggered to activate Task.
  SchedTaskRef     Task in which channel shall be processed.
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_JobObjectInfoType, VHSM_CONST) vHsm_JobObjectInfo[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MaskedBits  SchedEventRef  SchedTaskRef           Referable Keys */
  { /*     0 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Core] */
  { /*     1 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Hwa] */
  { /*     2 */      0x00u, 0u           , Ostask_HighPrio },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_Hwa_HighPrio] */
  { /*     3 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyM] */
  { /*     4 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyM_LibCv] */
  { /*     5 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_KeyManagement] */
  { /*     6 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv] */
  { /*     7 */      0x00u, 0u           , Ostask_HighPrio },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_HighPrio] */
  { /*     8 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Dec] */
  { /*     9 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Enc] */
  { /*    10 */      0x00u, 0u           , OsTask          },  /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Mac] */
  { /*    11 */      0x00u, 0u           , OsTask          }   /* [/ActiveEcuC/CryIf/Crypto_30_vHsm_LibCv_vHsmUpd_Sig] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_KeyInfo
**********************************************************************************************************************/
/** 
  \var    vHsm_KeyInfo
  \brief  Contains attributes per Key, accessible by external KeyId
  \details
  Element               Description
  CryptoKeyId       
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to vHsm_CryptoFunctions
  MaskedBits            contains bitcoded the boolean data of vHsm_InternalOnlyOfKeyInfo, vHsm_RoutedOfKeyInfo
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_KeyInfoType, VHSM_CONST) vHsm_KeyInfo[62] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CryptoKeyId                                                                     CryptoFunctionsIdx  MaskedBits        Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Decrypt_Aes128                             ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Decrypt_Aes128] */
  { /*     1 */ CryptoConf_CryptoKey_CryptoKey_Fbl_HashDummy                                  ,                 4u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_HashDummy] */
  { /*     2 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Fips186                                    ,                 4u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Rng_Fips186] */
  { /*     3 */ CryptoConf_CryptoKey_CryptoKey_Fbl_SecurityAccess_Ed25519                     ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_SecurityAccess_Ed25519] */
  { /*     4 */ CryptoConf_CryptoKey_CryptoKey_Fbl_Signature_Ed25519                          ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Fbl_Signature_Ed25519] */
  { /*     5 */ CryptoConf_CryptoKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA                  ,                 3u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA] */
  { /*     6 */ CryptoConf_CryptoKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA                  ,                 3u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA] */
  { /*     7 */ CryptoConf_CryptoKey_Ssa_SignatureRamKey_replacementAuthority                 ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_SignatureRamKey_replacementAuthority] */
  { /*     8 */ CryptoConf_CryptoKey_Ssa_TrustModelBackendCert_inHSM                          ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelBackendCert_inHSM] */
  { /*     9 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuCert_inHSM                              ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelEcuCert_inHSM] */
  { /*    10 */ CryptoConf_CryptoKey_Ssa_TrustModelIntermediateCert_inHSM                     ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelIntermediateCert_inHSM] */
  { /*    11 */ CryptoConf_CryptoKey_Ssa_TrustModelPrivateEcuUnique_StagingKey                ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey] */
  { /*    12 */ CryptoConf_CryptoKey_Ssa_TrustModelRootCert_inHSM                             ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModelRootCert_inHSM] */
  { /*    13 */ CryptoConf_CryptoKey_Ssa_TrustModel_Ecu_CsrPrivateKey                         ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey] */
  { /*    14 */ CryptoConf_CryptoKey_Ssa_TrustModel_Ecu_CsrPublicKey                          ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey] */
  { /*    15 */ CryptoConf_CryptoKey_vHsm_Info                                                ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/CryIfKey_vHsm_Info] */
  { /*    16 */ CryptoConf_CryptoKey_KeyM_Cert_Root                                           ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_Cert_Root] */
  { /*    17 */ CryptoConf_CryptoKey_KeyM_ECC_Intermediate                                    ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_ECC_Intermediate] */
  { /*    18 */ CryptoConf_CryptoKey_KeyM_ECC_Root                                            ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_ECC_Root] */
  { /*    19 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackend                      ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelBackend] */
  { /*    20 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackendPeer                  ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelBackendPeer] */
  { /*    21 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelEcuPeer                      ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelEcuPeer] */
  { /*    22 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediate                 ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelIntermediate] */
  { /*    23 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer             ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelIntermediatePeer] */
  { /*    24 */ CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelRoot                         ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/KeyM_SigVerifyKey_TrustModelRoot] */
  { /*    25 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx   ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx] */
  { /*    26 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx   ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx] */
  { /*    27 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx   ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx] */
  { /*    28 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx] */
  { /*    29 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx] */
  { /*    30 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer] */
  { /*    31 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_Ign_Stat                         ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_Ign_Stat] */
  { /*    32 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_PN14_Master_Stat1] */
  { /*    33 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                      ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_PT4_PTCoor4] */
  { /*    34 */ CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_VehSpd_8                         ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/SSA_SecOC_Int_MacVerify_VehSpd_8] */
  { /*    35 */ CryptoConf_CryptoKey_Ssa_AesRamKey                                            ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_AesRamKey] */
  { /*    36 */ CryptoConf_CryptoKey_Ssa_Authentication                                       ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_Authentication] */
  { /*    37 */ CryptoConf_CryptoKey_Ssa_BackendCert                                          ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_BackendCert] */
  { /*    38 */ CryptoConf_CryptoKey_Ssa_PduKeysMac                                           ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_PduKeysMac] */
  { /*    39 */ CryptoConf_CryptoKey_Ssa_RandomSeed                                           ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_RandomSeed] */
  { /*    40 */ CryptoConf_CryptoKey_Ssa_RealTime                                             ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_RealTime] */
  { /*    41 */ CryptoConf_CryptoKey_Ssa_RootCert                                             ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_RootCert] */
  { /*    42 */ CryptoConf_CryptoKey_Ssa_SecurityAccessPublicKey                              ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_SecurityAccessPublicKey] */
  { /*    43 */ CryptoConf_CryptoKey_Ssa_SharedSecretExchangeKey                              ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_SharedSecretExchangeKey] */
  { /*    44 */ CryptoConf_CryptoKey_Ssa_SharedSecretHash                                     ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_SharedSecretHash] */
  { /*    45 */ CryptoConf_CryptoKey_Ssa_SignatureRamKey                                      ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_SignatureRamKey] */
  { /*    46 */ CryptoConf_CryptoKey_Ssa_TickCount                                            ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_TickCount] */
  { /*    47 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuPublicCsr_StagingKey                    ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_TrustModelEcuPublicCsr_StagingKey] */
  { /*    48 */ CryptoConf_CryptoKey_vHsm_Custom                                              ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/vHsm_Custom] */
  { /*    49 */ CryptoConf_CryptoKey_Ssa_TrustModelEcuPublic_LiveKey                          ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_TrustModelEcuPublic_LiveKey] */
    /* Index    CryptoKeyId                                                                     CryptoFunctionsIdx  MaskedBits        Referable Keys */
  { /*    50 */ CryptoConf_CryptoKey_Ssa_TrustModelPrivateEcu_LiveKey                         ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_TrustModelPrivateEcu_LiveKey] */
  { /*    51 */ CryptoConf_CryptoKey_Ssa_VIN                                                  ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/Ssa_VIN] */
  { /*    52 */ CryptoConf_CryptoKey_vHSM_Custom_HSM_Version                                  ,                 2u,      0x01u },  /* [/ActiveEcuC/CryIf/vHSM_Custom_HSM_Version] */
  { /*    53 */ CryptoConf_CryptoKey_vHsm_Hal_Hardware                                        ,                 4u,      0x00u },  /* [/ActiveEcuC/CryIf/vHsm_Hardware] */
  { /*    54 */ CryptoConf_CryptoKey_vHsmInfo                                                 ,                 1u,      0x00u },  /* [/ActiveEcuC/CryIf/vHsm_Info] */
  { /*    55 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Decrypt                              ,                 0u,      0x02u },  /* [/ActiveEcuC/CryIf/vHsm_FirmwareUpdate_Decrypt] */
  { /*    56 */ CryptoConf_CryptoKey_vHsmLog                                                  ,                 1u,      0x00u },  /* [/ActiveEcuC/CryIf/vHsm_Log] */
  { /*    57 */ CryptoConf_CryptoKey_RomKey0                                                  ,                 4u,      0x00u },  /* [/ActiveEcuC/CryIf/vHsm_RomKey0] */
  { /*    58 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Encrypt                              ,                 0u,      0x02u },  /* [/ActiveEcuC/CryIf/vHsm_FirmwareUpdate_Encrypt] */
  { /*    59 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Mac                                  ,                 0u,      0x02u },  /* [/ActiveEcuC/CryIf/vHsm_FirmwareUpdate_Mac] */
  { /*    60 */ CryptoConf_CryptoKey_vHsm_TRNG                                                ,                 0u,      0x00u },  /* [/ActiveEcuC/CryIf/vHsm_TRNG] */
  { /*    61 */ CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Signature                            ,                 0u,      0x00u }   /* [/ActiveEcuC/CryIf/vHsm_FirmwareUpdate_Signature] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_MemoryArea
**********************************************************************************************************************/
/** 
  \var    vHsm_MemoryArea
  \brief  Memory to which vHsm allows access.
  \details
  Element    Description
  Start      Start address of area
  Stop       Stop address of area
  Type       Access type of area
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_MemoryAreaType, VHSM_CONST) vHsm_MemoryArea[8] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Start        Stop         Type                              Referable Keys */
  { /*     0 */ 0xF0050000u, 0xF005FFFFu, VHSM_MEMORY_AREA_READWRITE },  /* [/ActiveEcuC/vHsm/vHsmGeneral/TC3xx_HostAccessWindow] */
  { /*     1 */ 0x90000000u, 0x9011FFFFu, VHSM_MEMORY_AREA_READ      },  /* [/ActiveEcuC/vHsm/vHsmGeneral/TC3xx_LMURAM_cached_HSM] */
  { /*     2 */ 0x50000000u, 0x7FFFFFFFu, VHSM_MEMORY_AREA_READ      },  /* [/ActiveEcuC/vHsm/vHsmGeneral/TC3xx_CPU0_CPU1_CPU2] */
  { /*     3 */ 0x30000000u, 0x41FFFFFFu, VHSM_MEMORY_AREA_READ      },  /* [/ActiveEcuC/vHsm/vHsmGeneral/TC3xx_CPU3_CPU4] */
  { /*     4 */ 0x10000000u, 0x1FFFFFFFu, VHSM_MEMORY_AREA_READ      },  /* [/ActiveEcuC/vHsm/vHsmGeneral/TC3xx_CPU5] */
  { /*     5 */ 0xB0000000u, 0xB011FFFFu, VHSM_MEMORY_AREA_READWRITE },  /* [/ActiveEcuC/vHsm/vHsmGeneral/TC3xx_LMURAM_noncached] */
  { /*     6 */ 0x80040000u, 0x80FFFFFFu, VHSM_MEMORY_AREA_READ      },  /* [/ActiveEcuC/vHsm/vHsmGeneral/TC3xx_PFLASH_cached] */
  { /*     7 */ 0xA0040000u, 0xA0FFFFFFu, VHSM_MEMORY_AREA_READ      }   /* [/ActiveEcuC/vHsm/vHsmGeneral/TC3xx_PFLASH_noncached] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_RandomInit
**********************************************************************************************************************/
/** 
  \var    vHsm_RandomInit
  \brief  Contains parameters of /MICROSAR/vHsm/vHsmKeyMapping/vHsmRandomInit.
  \details
  Element       Description
  Key           Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmKeyMapping/vHsmRandomInit/vHsmRandomInitKey.
  KeyElement    Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmKeyMapping/vHsmRandomInit/vHsmRandomInitKeyElement.
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_RandomInitType, VHSM_CONST) vHsm_RandomInit[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Key                             KeyElement                                       Referable Keys */
  { /*     0 */ CryptoConf_CryptoKey_vHsm_Info, CryptoConf_CryptoKeyElement_vHsm_Info_Uid }   /* [/ActiveEcuC/vHsm/vHsmKeyMapping/UID, /ActiveEcuC/vHsm/vHsmKeyMapping] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_SchedulableEntities
**********************************************************************************************************************/
/** 
  \var    vHsm_SchedulableEntities
  \details
  Element                      Description
  ScheduledChannelsEndIdx      the end index of the 1:n relation pointing to vHsm_ScheduledChannels
  ScheduledChannelsStartIdx    the start index of the 1:n relation pointing to vHsm_ScheduledChannels
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_SchedulableEntitiesType, VHSM_CONST) vHsm_SchedulableEntities[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    ScheduledChannelsEndIdx  ScheduledChannelsStartIdx        Referable Keys */
  { /*     0 */                      2u,                        0u },  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_HighPrio] */
  { /*     1 */                     12u,                        2u }   /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_ScheduledChannels
**********************************************************************************************************************/
#define VHSM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(vHsm_ScheduledChannelsType, VHSM_CONST) vHsm_ScheduledChannels[12] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ScheduledChannels                                            Referable Keys */
  /*     0 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_HighPrio    ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_HighPrio] */
  /*     1 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_Hwa_HighPrio      ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_HighPrio] */
  /*     2 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_vHsmUpd_Mac ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*     3 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_KeyM_LibCv        ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*     4 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv             ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*     5 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_KeyManagement     ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*     6 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_Core              ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*     7 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_vHsmUpd_Dec ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*     8 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_Hwa               ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*     9 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_vHsmUpd_Enc ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*    10 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_KeyM              ,  /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
  /*    11 */ CryIfConf_CryIfChannel_Crypto_30_vHsm_LibCv_vHsmUpd_Sig    /* [/ActiveEcuC/vHsm/vHsmScheduling/vHsmSchedulableEntities_Unmapped] */
};
#define VHSM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_JobObjects
**********************************************************************************************************************/
/** 
  \var    vHsm_JobObjects
  \details
  Element             Description
  IpcChannel      
  JobRetVal       
  CancelFlag      
  IpcInstance     
  IpcMapping      
  ProcessKind     
  RedirectionFlags
  UsageRestriction
  ValidRequestFlag
  JobData         
  JobRequestId    
  JobRequestKind  
  LocalOutput     
  ProcessingType  
  State           
*/ 
#define VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(vHsm_JobObjectsType, VHSM_VAR_NOINIT) vHsm_JobObjects[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_RestrictedChannels
**********************************************************************************************************************/
/** 
  \var    vHsm_RestrictedChannels
  \brief  Array with size of Channels to allow restrict channel usage from outside due to internal needs.
*/ 
#define VHSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(vHsm_RestrictedChannelsType, VHSM_VAR_NOINIT) vHsm_RestrictedChannels[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define VHSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



#define VHSM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
CONST(vHsm_Ipc_MemoryLayoutType, VHSM_CONST) vHsm_Ipc_MemoryLayout =
{
  /* protocolInformationOffset */
  0u,
  /* rxChannelMemoryLayout[VHSM_IPC_NUM_RX_CHANNELS] */
  {
    { vHsm_Ipc_GetRxChannelWriteIndexOffset(0u), vHsm_Ipc_GetRxChannelReadIndexOffset(0u), vHsm_Ipc_GetRxChannelBufferOffset(0u) },
    { vHsm_Ipc_GetRxChannelWriteIndexOffset(1u), vHsm_Ipc_GetRxChannelReadIndexOffset(1u), vHsm_Ipc_GetRxChannelBufferOffset(1u) }  
  },
  /* txChannelMemoryLayout[VHSM_IPC_NUM_TX_CHANNELS] */
  {
    { vHsm_Ipc_GetTxChannelWriteIndexOffset(0u), vHsm_Ipc_GetTxChannelReadIndexOffset(0u), vHsm_Ipc_GetTxChannelBufferOffset(0u) },
    { vHsm_Ipc_GetTxChannelWriteIndexOffset(1u), vHsm_Ipc_GetTxChannelReadIndexOffset(1u), vHsm_Ipc_GetTxChannelBufferOffset(1u) }  
  },
  vHsm_Ipc_GetGlobalInfoOffset() + (0u),  /* stackProtectionCanaryPE1Offset */  
  vHsm_Ipc_GetGlobalInfoOffset() + (4u),  /* stackProtectionCanaryPE2Offset */  
  vHsm_Ipc_GetGlobalInfoOffset() + (8u),  /* seedOffset */                      
  vHsm_Ipc_GetGlobalInfoOffset() + (12u), /* detModuleIdOffset */               
  vHsm_Ipc_GetGlobalInfoOffset() + (16u), /* detInstanceIdOffset */             
  vHsm_Ipc_GetGlobalInfoOffset() + (20u), /* detApiIdOffset */                  
  vHsm_Ipc_GetGlobalInfoOffset() + (24u), /* detErrorIdOffset */                
  vHsm_Ipc_GetGlobalInfoOffset() + (28u), /* readyFlagOffset */                 
  vHsm_Ipc_GetGlobalInfoOffset() + (32u), /* endRamExecFlagOffset */            
  vHsm_Ipc_GetGlobalInfoOffset() + (36u), /* ramExecFlagOffset */               
  vHsm_Ipc_GetGlobalInfoOffset() + (40u)  /* detReportFlag */                   
};
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/



 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


#define VHSM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_MemMap */
/*lint -restore */
/**********************************************************************************************************************
  TaskMainFunction
**********************************************************************************************************************/
/**********************************************************************************************************************
* vHsm_MainFunction_vHsmSchedulableEntities_HighPrio
**********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_MainFunction_vHsmSchedulableEntities_HighPrio(void)
{
  vHsm_JobProcessor_MainFunction(vHsmConf_vHsmSchedulableEntities_vHsmSchedulableEntities_HighPrio);
}

/**********************************************************************************************************************
* vHsm_MainFunction_vHsmSchedulableEntities_Unmapped
**********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_MainFunction_vHsmSchedulableEntities_Unmapped(void)
{
  vHsm_JobProcessor_MainFunction(vHsmConf_vHsmSchedulableEntities_vHsmSchedulableEntities_Unmapped);
}

#define VHSM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
 *  END OF FILE: vHsm_Cfg.c
 *********************************************************************************************************************/
