/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/* double include prevention */
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

# include "Rte.h"
# ifdef RTE_CORE
/**********************************************************************************************************************
 * Type definitions for mode management
 *********************************************************************************************************************/
typedef EventMaskType Rte_EventMaskType;
# endif /* defined(RTE_CORE) */

/* PRQA S 1039 EOF */ /* MD_Rte_1039 */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Csm_DataPtr
typedef uint8 * Csm_DataPtr;

# define Rte_TypeDef_Csm_LengthPtr
typedef uint32 * Csm_LengthPtr;

# define Rte_TypeDef_Csm_const_DataPtr
typedef const uint8 * Csm_const_DataPtr;

# define Rte_TypeDef_KeyM_CertDataPointerType
typedef uint8 * KeyM_CertDataPointerType;

# define Rte_TypeDef_KeyM_ConstDataPtrType
typedef const uint8 * KeyM_ConstDataPtrType;

# define Rte_TypeDef_KeyM_CryptoKeyDataType
typedef uint8 * KeyM_CryptoKeyDataType;

# define Rte_TypeDef_KeyM_DataPtrType
typedef uint8 * KeyM_DataPtrType;

# define Rte_TypeDef_KeyM_LengthPtrType
typedef uint32 * KeyM_LengthPtrType;

# define Rte_TypeDef_KeyM_const_CryptoKeyDataType
typedef const uint8 * KeyM_const_CryptoKeyDataType;

# define Rte_TypeDef_Ssa_ConstDataPtr
typedef const uint8 * Ssa_ConstDataPtr;

# define Rte_TypeDef_Ssa_DataPtr
typedef uint8 * Ssa_DataPtr;

# define Rte_TypeDef_Ssa_LengthPtr
typedef uint32 * Ssa_LengthPtr;

# define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

# define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

# define Rte_TypeDef_CertP_RawCertBufferType
typedef uint8 CertP_RawCertBufferType[910];

# define Rte_TypeDef_Coding_VINDataType
typedef uint8 Coding_VINDataType[17];

# define Rte_TypeDef_Csm_DataType_MacAesCmacAuth
typedef uint8 Csm_DataType_MacAesCmacAuth[27];

# define Rte_TypeDef_Csm_DataType_MacAesCmacRealTimeOffset
typedef uint8 Csm_DataType_MacAesCmacRealTimeOffset[19];

# define Rte_TypeDef_Csm_DataType_MacAesCmacTickCount
typedef uint8 Csm_DataType_MacAesCmacTickCount[13];

# define Rte_TypeDef_Csm_DataType_MacAesCmacVin
typedef uint8 Csm_DataType_MacAesCmacVin[24];

# define Rte_TypeDef_Csm_DecryptDataType_AES128Decrypt
typedef uint8 Csm_DecryptDataType_AES128Decrypt[80];

# define Rte_TypeDef_Csm_DecryptDataType_AES128DecryptWithPadding
typedef uint8 Csm_DecryptDataType_AES128DecryptWithPadding[1056];

# define Rte_TypeDef_Csm_DecryptResultType_AES128Decrypt
typedef uint8 Csm_DecryptResultType_AES128Decrypt[80];

# define Rte_TypeDef_Csm_DecryptResultType_AES128DecryptWithPadding
typedef uint8 Csm_DecryptResultType_AES128DecryptWithPadding[1056];

# define Rte_TypeDef_Csm_HashDataType_Sha2_512
typedef uint8 Csm_HashDataType_Sha2_512[8192];

# define Rte_TypeDef_Csm_HashResultType_Sha2_512
typedef uint8 Csm_HashResultType_Sha2_512[64];

# define Rte_TypeDef_Csm_KeyDataType_CsmKey_Ssa_SignatureRamKey_replacementAuthority
typedef uint8 Csm_KeyDataType_CsmKey_Ssa_SignatureRamKey_replacementAuthority[32];

# define Rte_TypeDef_Csm_KeyDataType_CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey
typedef uint8 Csm_KeyDataType_CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey[32];

# define Rte_TypeDef_Csm_KeyDataType_CsmKey_Ssa_TrustModelEcuPublic_LiveKey
typedef uint8 Csm_KeyDataType_CsmKey_Ssa_TrustModelEcuPublic_LiveKey[32];

# define Rte_TypeDef_Csm_KeyDataType_CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey
typedef uint8 Csm_KeyDataType_CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey[32];

# define Rte_TypeDef_Csm_KeyDataType_CsmKey_Ssa_TrustModelPrivateEcu_LiveKey
typedef uint8 Csm_KeyDataType_CsmKey_Ssa_TrustModelPrivateEcu_LiveKey[32];

# define Rte_TypeDef_Csm_KeyDataType_CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey
typedef uint8 Csm_KeyDataType_CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey[32];

# define Rte_TypeDef_Csm_KeyDataType_CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey
typedef uint8 Csm_KeyDataType_CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey[32];

# define Rte_TypeDef_Csm_KeyDataType_KeyM_SigVerifyKey_TrustModelEcuPeer
typedef uint8 Csm_KeyDataType_KeyM_SigVerifyKey_TrustModelEcuPeer[32];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_AesRamKey
typedef uint8 Csm_KeyDataType_Ssa_AesRamKey[16];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_Authentication
typedef uint8 Csm_KeyDataType_Ssa_Authentication[16];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_BackendCert
typedef uint8 Csm_KeyDataType_Ssa_BackendCert[600];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_RandomSeed
typedef uint8 Csm_KeyDataType_Ssa_RandomSeed[209];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_RealTime
typedef uint8 Csm_KeyDataType_Ssa_RealTime[16];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_RootCert
typedef uint8 Csm_KeyDataType_Ssa_RootCert[600];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_SecurityAccessPublicKey
typedef uint8 Csm_KeyDataType_Ssa_SecurityAccessPublicKey[32];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_SharedSecretHash
typedef uint8 Csm_KeyDataType_Ssa_SharedSecretHash[4];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_SharedSecretKeyExchange
typedef uint8 Csm_KeyDataType_Ssa_SharedSecretKeyExchange[32];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_SigPubKey_ReplacementAuthority
typedef uint8 Csm_KeyDataType_Ssa_SigPubKey_ReplacementAuthority[32];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_SignatureRamKey
typedef uint8 Csm_KeyDataType_Ssa_SignatureRamKey[32];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_TickCount
typedef uint8 Csm_KeyDataType_Ssa_TickCount[16];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelEcuCsrPublicKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelEcuCsrPublicKey[32];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelEcuLivePublicKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelEcuLivePublicKey[32];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelTempPublicKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelTempPublicKey[32];

# define Rte_TypeDef_Csm_KeyDataType_Ssa_VIN
typedef uint8 Csm_KeyDataType_Ssa_VIN[16];

# define Rte_TypeDef_Csm_MacGenerateDataType_MacGenAesCmac
typedef uint8 Csm_MacGenerateDataType_MacGenAesCmac[27];

# define Rte_TypeDef_Csm_MacGenerateResultType_MacGenAesCmac
typedef uint8 Csm_MacGenerateResultType_MacGenAesCmac[16];

# define Rte_TypeDef_Csm_MacVerifyCompareType_MacVerifyAesCmac
typedef uint8 Csm_MacVerifyCompareType_MacVerifyAesCmac[8];

# define Rte_TypeDef_Csm_MacVerifyDataType_MacVerifyAesCmac
typedef uint8 Csm_MacVerifyDataType_MacVerifyAesCmac[27];

# define Rte_TypeDef_Csm_PublicValueDataType_CsmKey_Ssa_SignatureRamKey_replacementAuthority
typedef uint8 Csm_PublicValueDataType_CsmKey_Ssa_SignatureRamKey_replacementAuthority[32];

# define Rte_TypeDef_Csm_PublicValueDataType_CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey
typedef uint8 Csm_PublicValueDataType_CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey[32];

# define Rte_TypeDef_Csm_PublicValueDataType_CsmKey_Ssa_TrustModelEcuPublic_LiveKey
typedef uint8 Csm_PublicValueDataType_CsmKey_Ssa_TrustModelEcuPublic_LiveKey[32];

# define Rte_TypeDef_Csm_PublicValueDataType_CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey
typedef uint8 Csm_PublicValueDataType_CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey[32];

# define Rte_TypeDef_Csm_PublicValueDataType_CsmKey_Ssa_TrustModelPrivateEcu_LiveKey
typedef uint8 Csm_PublicValueDataType_CsmKey_Ssa_TrustModelPrivateEcu_LiveKey[32];

# define Rte_TypeDef_Csm_PublicValueDataType_CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey
typedef uint8 Csm_PublicValueDataType_CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey[32];

# define Rte_TypeDef_Csm_PublicValueDataType_CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey
typedef uint8 Csm_PublicValueDataType_CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey[32];

# define Rte_TypeDef_Csm_PublicValueDataType_KeyM_SigVerifyKey_TrustModelEcuPeer
typedef uint8 Csm_PublicValueDataType_KeyM_SigVerifyKey_TrustModelEcuPeer[32];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_AesRamKey
typedef uint8 Csm_PublicValueDataType_Ssa_AesRamKey[16];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_Authentication
typedef uint8 Csm_PublicValueDataType_Ssa_Authentication[16];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_BackendCert
typedef uint8 Csm_PublicValueDataType_Ssa_BackendCert[600];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_RandomSeed
typedef uint8 Csm_PublicValueDataType_Ssa_RandomSeed[209];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_RealTime
typedef uint8 Csm_PublicValueDataType_Ssa_RealTime[16];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_RootCert
typedef uint8 Csm_PublicValueDataType_Ssa_RootCert[600];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_SecurityAccessPublicKey
typedef uint8 Csm_PublicValueDataType_Ssa_SecurityAccessPublicKey[32];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_SharedSecretHash
typedef uint8 Csm_PublicValueDataType_Ssa_SharedSecretHash[4];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_SharedSecretKeyExchange
typedef uint8 Csm_PublicValueDataType_Ssa_SharedSecretKeyExchange[32];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_SignatureRamKey
typedef uint8 Csm_PublicValueDataType_Ssa_SignatureRamKey[32];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_TickCount
typedef uint8 Csm_PublicValueDataType_Ssa_TickCount[16];

# define Rte_TypeDef_Csm_PublicValueDataType_Ssa_VIN
typedef uint8 Csm_PublicValueDataType_Ssa_VIN[16];

# define Rte_TypeDef_Csm_RandomGenerateResultType_Random
typedef uint8 Csm_RandomGenerateResultType_Random[32];

# define Rte_TypeDef_Csm_RandomGenerateResultType_Random_TRNG
typedef uint8 Csm_RandomGenerateResultType_Random_TRNG[32];

# define Rte_TypeDef_Csm_SeedDataTypeCsmKey_Ssa_SignatureRamKey_replacementAuthority
typedef uint8 Csm_SeedDataTypeCsmKey_Ssa_SignatureRamKey_replacementAuthority[32];

# define Rte_TypeDef_Csm_SeedDataTypeCsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey
typedef uint8 Csm_SeedDataTypeCsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey[32];

# define Rte_TypeDef_Csm_SeedDataTypeCsmKey_Ssa_TrustModelEcuPublic_LiveKey
typedef uint8 Csm_SeedDataTypeCsmKey_Ssa_TrustModelEcuPublic_LiveKey[32];

# define Rte_TypeDef_Csm_SeedDataTypeCsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey
typedef uint8 Csm_SeedDataTypeCsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey[32];

# define Rte_TypeDef_Csm_SeedDataTypeCsmKey_Ssa_TrustModelPrivateEcu_LiveKey
typedef uint8 Csm_SeedDataTypeCsmKey_Ssa_TrustModelPrivateEcu_LiveKey[32];

# define Rte_TypeDef_Csm_SeedDataTypeCsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey
typedef uint8 Csm_SeedDataTypeCsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey[32];

# define Rte_TypeDef_Csm_SeedDataTypeCsmKey_Ssa_TrustModel_Ecu_CsrPublicKey
typedef uint8 Csm_SeedDataTypeCsmKey_Ssa_TrustModel_Ecu_CsrPublicKey[32];

# define Rte_TypeDef_Csm_SeedDataTypeKeyM_SigVerifyKey_TrustModelEcuPeer
typedef uint8 Csm_SeedDataTypeKeyM_SigVerifyKey_TrustModelEcuPeer[32];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_AesRamKey
typedef uint8 Csm_SeedDataTypeSsa_AesRamKey[16];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_Authentication
typedef uint8 Csm_SeedDataTypeSsa_Authentication[16];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_BackendCert
typedef uint8 Csm_SeedDataTypeSsa_BackendCert[600];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_RandomSeed
typedef uint8 Csm_SeedDataTypeSsa_RandomSeed[209];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_RealTime
typedef uint8 Csm_SeedDataTypeSsa_RealTime[16];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_RootCert
typedef uint8 Csm_SeedDataTypeSsa_RootCert[600];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_SecurityAccessPublicKey
typedef uint8 Csm_SeedDataTypeSsa_SecurityAccessPublicKey[32];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_SharedSecretHash
typedef uint8 Csm_SeedDataTypeSsa_SharedSecretHash[4];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_SharedSecretKeyExchange
typedef uint8 Csm_SeedDataTypeSsa_SharedSecretKeyExchange[32];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_SignatureRamKey
typedef uint8 Csm_SeedDataTypeSsa_SignatureRamKey[32];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_TickCount
typedef uint8 Csm_SeedDataTypeSsa_TickCount[16];

# define Rte_TypeDef_Csm_SeedDataTypeSsa_VIN
typedef uint8 Csm_SeedDataTypeSsa_VIN[16];

# define Rte_TypeDef_Csm_SignatureGenerateDataType_SigGenEd25519
typedef uint8 Csm_SignatureGenerateDataType_SigGenEd25519[129];

# define Rte_TypeDef_Csm_SignatureGenerateResultType_SigGenEd25519
typedef uint8 Csm_SignatureGenerateResultType_SigGenEd25519[64];

# define Rte_TypeDef_Csm_SignatureVerifyCompareType_SigVerifyEd25519_SSA
typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519_SSA[64];

# define Rte_TypeDef_Csm_SignatureVerifyCompareType_SigVerifyEd25519ph_SyncAsync
typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519ph_SyncAsync[64];

# define Rte_TypeDef_Csm_SignatureVerifyCompareType_SigVerifyEd25519ph_SyncAsync_HWA
typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519ph_SyncAsync_HWA[64];

# define Rte_TypeDef_Csm_SignatureVerifyDataType_SigVerifyEd25519_SSA
typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519_SSA[8192];

# define Rte_TypeDef_Csm_SignatureVerifyDataType_SigVerifyEd25519ph_SyncAsync
typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519ph_SyncAsync[8192];

# define Rte_TypeDef_Csm_SignatureVerifyDataType_SigVerifyEd25519ph_SyncAsync_HWA
typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519ph_SyncAsync_HWA[8192];

# define Rte_TypeDef_DataArrayType_uint8_2
typedef uint8 DataArrayType_uint8_2[2];

# define Rte_TypeDef_Dcm_Data1000ByteType
typedef uint8 Dcm_Data1000ByteType[1000];

# define Rte_TypeDef_Dcm_Data1002ByteType
typedef uint8 Dcm_Data1002ByteType[1002];

# define Rte_TypeDef_Dcm_Data1024ByteType
typedef uint8 Dcm_Data1024ByteType[1024];

# define Rte_TypeDef_Dcm_Data1058ByteType
typedef uint8 Dcm_Data1058ByteType[1058];

# define Rte_TypeDef_Dcm_Data1073ByteType
typedef uint8 Dcm_Data1073ByteType[1073];

# define Rte_TypeDef_Dcm_Data10ByteType
typedef uint8 Dcm_Data10ByteType[10];

# define Rte_TypeDef_Dcm_Data1160ByteType
typedef uint8 Dcm_Data1160ByteType[1160];

# define Rte_TypeDef_Dcm_Data1270ByteType
typedef uint8 Dcm_Data1270ByteType[1270];

# define Rte_TypeDef_Dcm_Data1275ByteType
typedef uint8 Dcm_Data1275ByteType[1275];

# define Rte_TypeDef_Dcm_Data12ByteType
typedef uint8 Dcm_Data12ByteType[12];

# define Rte_TypeDef_Dcm_Data144ByteType
typedef uint8 Dcm_Data144ByteType[144];

# define Rte_TypeDef_Dcm_Data15ByteType
typedef uint8 Dcm_Data15ByteType[15];

# define Rte_TypeDef_Dcm_Data16ByteType
typedef uint8 Dcm_Data16ByteType[16];

# define Rte_TypeDef_Dcm_Data17ByteType
typedef uint8 Dcm_Data17ByteType[17];

# define Rte_TypeDef_Dcm_Data18ByteType
typedef uint8 Dcm_Data18ByteType[18];

# define Rte_TypeDef_Dcm_Data1ByteType
typedef uint8 Dcm_Data1ByteType[1];

# define Rte_TypeDef_Dcm_Data2002ByteType
typedef uint8 Dcm_Data2002ByteType[2002];

# define Rte_TypeDef_Dcm_Data2004ByteType
typedef uint8 Dcm_Data2004ByteType[2004];

# define Rte_TypeDef_Dcm_Data20ByteType
typedef uint8 Dcm_Data20ByteType[20];

# define Rte_TypeDef_Dcm_Data22ByteType
typedef uint8 Dcm_Data22ByteType[22];

# define Rte_TypeDef_Dcm_Data233ByteType
typedef uint8 Dcm_Data233ByteType[233];

# define Rte_TypeDef_Dcm_Data240ByteType
typedef uint8 Dcm_Data240ByteType[240];

# define Rte_TypeDef_Dcm_Data2540ByteType
typedef uint8 Dcm_Data2540ByteType[2540];

# define Rte_TypeDef_Dcm_Data254ByteType
typedef uint8 Dcm_Data254ByteType[254];

# define Rte_TypeDef_Dcm_Data258ByteType
typedef uint8 Dcm_Data258ByteType[258];

# define Rte_TypeDef_Dcm_Data2613ByteType
typedef uint8 Dcm_Data2613ByteType[2613];

# define Rte_TypeDef_Dcm_Data28ByteType
typedef uint8 Dcm_Data28ByteType[28];

# define Rte_TypeDef_Dcm_Data2ByteType
typedef uint8 Dcm_Data2ByteType[2];

# define Rte_TypeDef_Dcm_Data3006ByteType
typedef uint8 Dcm_Data3006ByteType[3006];

# define Rte_TypeDef_Dcm_Data3060ByteType
typedef uint8 Dcm_Data3060ByteType[3060];

# define Rte_TypeDef_Dcm_Data30ByteType
typedef uint8 Dcm_Data30ByteType[30];

# define Rte_TypeDef_Dcm_Data320ByteType
typedef uint8 Dcm_Data320ByteType[320];

# define Rte_TypeDef_Dcm_Data32ByteType
typedef uint8 Dcm_Data32ByteType[32];

# define Rte_TypeDef_Dcm_Data33ByteType
typedef uint8 Dcm_Data33ByteType[33];

# define Rte_TypeDef_Dcm_Data381ByteType
typedef uint8 Dcm_Data381ByteType[381];

# define Rte_TypeDef_Dcm_Data3ByteType
typedef uint8 Dcm_Data3ByteType[3];

# define Rte_TypeDef_Dcm_Data4004ByteType
typedef uint8 Dcm_Data4004ByteType[4004];

# define Rte_TypeDef_Dcm_Data4008ByteType
typedef uint8 Dcm_Data4008ByteType[4008];

# define Rte_TypeDef_Dcm_Data4080ByteType
typedef uint8 Dcm_Data4080ByteType[4080];

# define Rte_TypeDef_Dcm_Data4092ByteType
typedef uint8 Dcm_Data4092ByteType[4092];

# define Rte_TypeDef_Dcm_Data4095ByteType
typedef uint8 Dcm_Data4095ByteType[4095];

# define Rte_TypeDef_Dcm_Data40ByteType
typedef uint8 Dcm_Data40ByteType[40];

# define Rte_TypeDef_Dcm_Data420ByteType
typedef uint8 Dcm_Data420ByteType[420];

# define Rte_TypeDef_Dcm_Data48ByteType
typedef uint8 Dcm_Data48ByteType[48];

# define Rte_TypeDef_Dcm_Data4ByteType
typedef uint8 Dcm_Data4ByteType[4];

# define Rte_TypeDef_Dcm_Data508ByteType
typedef uint8 Dcm_Data508ByteType[508];

# define Rte_TypeDef_Dcm_Data510ByteType
typedef uint8 Dcm_Data510ByteType[510];

# define Rte_TypeDef_Dcm_Data5ByteType
typedef uint8 Dcm_Data5ByteType[5];

# define Rte_TypeDef_Dcm_Data64ByteType
typedef uint8 Dcm_Data64ByteType[64];

# define Rte_TypeDef_Dcm_Data6ByteType
typedef uint8 Dcm_Data6ByteType[6];

# define Rte_TypeDef_Dcm_Data7ByteType
typedef uint8 Dcm_Data7ByteType[7];

# define Rte_TypeDef_Dcm_Data80ByteType
typedef uint8 Dcm_Data80ByteType[80];

# define Rte_TypeDef_Dcm_Data8ByteType
typedef uint8 Dcm_Data8ByteType[8];

# define Rte_TypeDef_Dcm_DataDID_FD2F_EcuLocationData_ArrayType
typedef uint8 Dcm_DataDID_FD2F_EcuLocationData_ArrayType[1];

# define Rte_TypeDef_Dcm_SsaDslBufferType
typedef uint8 Dcm_SsaDslBufferType[8195];

# define Rte_TypeDef_Dcm_StartFlexibleInArrayData_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Tester_AuthenticationType
typedef uint8 Dcm_StartFlexibleInArrayData_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Tester_AuthenticationType[4004];

# define Rte_TypeDef_Dcm_StartFlexibleInArrayData_Routine_Enhance_Access_Rights_Start_Enhanced_Rights_CertificateType
typedef uint8 Dcm_StartFlexibleInArrayData_Routine_Enhance_Access_Rights_Start_Enhanced_Rights_CertificateType[2002];

# define Rte_TypeDef_Dcm_StartFlexibleInArrayData_Routine_Evaluate_Data_Verification_Certificate_Start_Data_Verification_CertificateType
typedef uint8 Dcm_StartFlexibleInArrayData_Routine_Evaluate_Data_Verification_Certificate_Start_Data_Verification_CertificateType[2002];

# define Rte_TypeDef_Dcm_StartFlexibleInArrayData_Routine_PreCheckProgrammingDependencies_Start_Pre_Check_InformationsType
typedef uint8 Dcm_StartFlexibleInArrayData_Routine_PreCheckProgrammingDependencies_Start_Pre_Check_InformationsType[4064];

# define Rte_TypeDef_Dcm_StartFlexibleInArrayData_Routine_Replace_Certificates_Start_CertificatesType
typedef uint8 Dcm_StartFlexibleInArrayData_Routine_Replace_Certificates_Start_CertificatesType[4008];

# define Rte_TypeDef_Dcm_StartFlexibleInArrayData_Routine_Replace_Trust_model_Certificates_Start_Trust_CertificatesType
typedef uint8 Dcm_StartFlexibleInArrayData_Routine_Replace_Trust_model_Certificates_Start_Trust_CertificatesType[3006];

# define Rte_TypeDef_Dcm_StartFlexibleInArrayData_Routine_Replace_Trust_model_Root_Certificate_Start_CertificatesType
typedef uint8 Dcm_StartFlexibleInArrayData_Routine_Replace_Trust_model_Root_Certificate_Start_CertificatesType[2004];

# define Rte_TypeDef_Dcm_StartFlexibleInArrayData_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_CertificatesType
typedef uint8 Dcm_StartFlexibleInArrayData_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_CertificatesType[3006];

# define Rte_TypeDef_Dcm_StartFlexibleOutArrayData_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Authentication_ResultType
typedef uint8 Dcm_StartFlexibleOutArrayData_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Authentication_ResultType[3006];

# define Rte_TypeDef_Dcm_StartFlexibleOutArrayData_Routine_Certificate_Self_Check_Start_Verification_ResultType
typedef uint8 Dcm_StartFlexibleOutArrayData_Routine_Certificate_Self_Check_Start_Verification_ResultType[18];

# define Rte_TypeDef_Dcm_StartFlexibleOutArrayData_Routine_Check_Reprogramming_Preconditions_Start_List_of_PreconditionsType
typedef uint8 Dcm_StartFlexibleOutArrayData_Routine_Check_Reprogramming_Preconditions_Start_List_of_PreconditionsType[100];

# define Rte_TypeDef_Dcm_StartFlexibleOutArrayData_Routine_Get_Certificate_Entry_Start_Certificate_ContentType
typedef uint8 Dcm_StartFlexibleOutArrayData_Routine_Get_Certificate_Entry_Start_Certificate_ContentType[64];

# define Rte_TypeDef_Dcm_StartFlexibleOutArrayData_Routine_Trust_Model_Generate_Key_Pair_Start_Trust_Model_ECU_CSRType
typedef uint8 Dcm_StartFlexibleOutArrayData_Routine_Trust_Model_Generate_Key_Pair_Start_Trust_Model_ECU_CSRType[1002];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[5];

# define Rte_TypeDef_KeyM_CertificateDataType_Ssa_TrustModelBackendCert
typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelBackendCert[1000];

# define Rte_TypeDef_KeyM_CertificateDataType_Ssa_TrustModelBackendPeerCert
typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelBackendPeerCert[1000];

# define Rte_TypeDef_KeyM_CertificateDataType_Ssa_TrustModelEcuCert
typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelEcuCert[1000];

# define Rte_TypeDef_KeyM_CertificateDataType_Ssa_TrustModelEcuCsr
typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelEcuCsr[1000];

# define Rte_TypeDef_KeyM_CertificateDataType_Ssa_TrustModelEcuPeerCert
typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelEcuPeerCert[1000];

# define Rte_TypeDef_KeyM_CertificateDataType_Ssa_TrustModelIntermediateCert
typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelIntermediateCert[1000];

# define Rte_TypeDef_KeyM_CertificateDataType_Ssa_TrustModelIntermediatePeerCert
typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelIntermediatePeerCert[1000];

# define Rte_TypeDef_KeyM_CertificateDataType_Ssa_TrustModelRootCert
typedef uint8 KeyM_CertificateDataType_Ssa_TrustModelRootCert[1000];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer_002[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo_002[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SigAlgoId_002[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoAlgo_002[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version_002[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId_002[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints_002[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_keyUsage_002[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole_002[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId_002[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureAlgorithm_002[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_signatureValue_002[65];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject[30];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject_002[30];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter_002[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotBefore_002[13];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Issuer_004[10];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SigAlgoId_004[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoAlgo_004[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SubjectPublicKeyInfoKey_004[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version_004[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_keyUsage_004[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_pkiRole_004[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureAlgorithm_004[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_signatureValue_004[65];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_subject_004[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter_004[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotBefore_004[13];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer_005[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo_005[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SigAlgoId_005[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoAlgo_005[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version_005[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId_005[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_keyUsage_005[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole_006[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu_005[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId_005[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID[170];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID_005[170];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureAlgorithm_005[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_signatureValue_005[65];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject[30];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject_005[30];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter_005[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotBefore_005[13];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Issuer_008[10];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SerialNo_008[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SigAlgoId_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoAlgo_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_SubjectPublicKeyInfoKey_008[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_Version_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_authKeyId_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_007[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid1_007[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid2_007[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_extKeyUsage_oid3_007[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_keyUsage_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_pkiRole_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_specialEcu_007[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_subKeyId_008[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_ext_uniqueECUID_007[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureAlgorithm_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_signatureValue_008[65];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_subject_008[10];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotAfter_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCsr_validityNotBefore_008[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Issuer_006[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SigAlgoId_006[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoAlgo_006[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SubjectPublicKeyInfoKey_006[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version_006[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_keyUsage_006[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_uniqueECUID_006[12];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureAlgorithm_006[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_signatureValue_006[65];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_subject_006[48];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter_006[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotBefore_006[13];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer_003[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo_003[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SigAlgoId_003[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoAlgo_003[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version_003[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId_003[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_keyUsage_003[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole_003[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId_003[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureAlgorithm_003[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_signatureValue_003[65];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject[30];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject_003[30];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter_003[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotBefore_003[13];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Issuer_007[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SigAlgoId_007[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoAlgo_007[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SubjectPublicKeyInfoKey_007[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version_007[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_keyUsage_007[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_pkiRole_005[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureAlgorithm_007[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_signatureValue_007[65];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_subject_007[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotBefore_007[13];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo[16];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_SigAlgoId[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoAlgo[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey[33];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId_009
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId_009[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage[2];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_pkiRole[1];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId[20];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureAlgorithm[3];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_signatureValue[65];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject[30];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter[15];

# define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotBefore[13];

# define Rte_TypeDef_KeyM_SharedSecretType
typedef uint8 KeyM_SharedSecretType[32];

# define Rte_TypeDef_RightsM_AuthenticationBroadcastType
typedef uint8 RightsM_AuthenticationBroadcastType[20];

# define Rte_TypeDef_RightsM_ChallengeEcuType
typedef uint8 RightsM_ChallengeEcuType[32];

# define Rte_TypeDef_RightsM_IssuerType
typedef uint8 RightsM_IssuerType[15];

# define Rte_TypeDef_RightsM_SerialNumberType
typedef uint8 RightsM_SerialNumberType[16];

# define Rte_TypeDef_SecLog_AclVersionType
typedef uint8 SecLog_AclVersionType[11];

# define Rte_TypeDef_SecLog_AuthenticationContentType
typedef uint8 SecLog_AuthenticationContentType[18];

# define Rte_TypeDef_SecLog_LogDataEvnt10_FailedPduMacVerifType
typedef uint8 SecLog_LogDataEvnt10_FailedPduMacVerifType[128];

# define Rte_TypeDef_SecLog_LogDataEvnt11_SecOrAuthBootType
typedef uint8 SecLog_LogDataEvnt11_SecOrAuthBootType[59];

# define Rte_TypeDef_SecLog_LogDataEvnt12_ChangeOfVinType
typedef uint8 SecLog_LogDataEvnt12_ChangeOfVinType[76];

# define Rte_TypeDef_SecLog_LogDataEvnt13_AclReplacementType
typedef uint8 SecLog_LogDataEvnt13_AclReplacementType[95];

# define Rte_TypeDef_SecLog_LogDataEvnt1_FailedCertVerifType
typedef uint8 SecLog_LogDataEvnt1_FailedCertVerifType[176];

# define Rte_TypeDef_SecLog_LogDataEvnt2_SucCertVerifType
typedef uint8 SecLog_LogDataEvnt2_SucCertVerifType[244];

# define Rte_TypeDef_SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType
typedef uint8 SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType[391];

# define Rte_TypeDef_SecLog_LogDataEvnt4_AuthBySecAccessType
typedef uint8 SecLog_LogDataEvnt4_AuthBySecAccessType[68];

# define Rte_TypeDef_SecLog_LogDataEvnt5_SucDiagServiceExecType
typedef uint8 SecLog_LogDataEvnt5_SucDiagServiceExecType[138];

# define Rte_TypeDef_SecLog_LogDataEvnt6_RightsMgmtType
typedef uint8 SecLog_LogDataEvnt6_RightsMgmtType[216];

# define Rte_TypeDef_SecLog_LogDataEvnt7_SigVerifType
typedef uint8 SecLog_LogDataEvnt7_SigVerifType[94];

# define Rte_TypeDef_SecLog_LogDataEvnt8_TickCountDateAndTimeType
typedef uint8 SecLog_LogDataEvnt8_TickCountDateAndTimeType[232];

# define Rte_TypeDef_SecLog_LogDataEvnt9_SecOcMisconfigType
typedef uint8 SecLog_LogDataEvnt9_SecOcMisconfigType[62];

# define Rte_TypeDef_SecLog_LogFailedMacVerifCount_ExceededThType
typedef uint8 SecLog_LogFailedMacVerifCount_ExceededThType[200];

# define Rte_TypeDef_SecLog_VinType
typedef uint8 SecLog_VinType[17];

# define Rte_TypeDef_Ssa_Data1024ByteType
typedef uint8 Ssa_Data1024ByteType[1024];

# define Rte_TypeDef_Ssa_Data12ByteType
typedef uint8 Ssa_Data12ByteType[12];

# define Rte_TypeDef_Ssa_Data15ByteType
typedef uint8 Ssa_Data15ByteType[15];

# define Rte_TypeDef_Ssa_Data20ByteType
typedef uint8 Ssa_Data20ByteType[20];

# define Rte_TypeDef_Ssa_Data2ByteType
typedef uint8 Ssa_Data2ByteType[2];

# define Rte_TypeDef_Ssa_Data30ByteType
typedef uint8 Ssa_Data30ByteType[30];

# define Rte_TypeDef_Ssa_Data32ByteType
typedef uint8 Ssa_Data32ByteType[32];

# define Rte_TypeDef_Ssa_Data4092ByteType
typedef uint8 Ssa_Data4092ByteType[4092];

# define Rte_TypeDef_Ssa_Data5ByteType
typedef uint8 Ssa_Data5ByteType[5];

# define Rte_TypeDef_Ssa_Data64ByteType
typedef uint8 Ssa_Data64ByteType[64];

# define Rte_TypeDef_Ssa_Data6ByteType
typedef uint8 Ssa_Data6ByteType[6];

# define Rte_TypeDef_Ssa_Data7ByteType
typedef uint8 Ssa_Data7ByteType[7];

# define Rte_TypeDef_Ssa_Data8ByteType
typedef uint8 Ssa_Data8ByteType[8];

# define Rte_TypeDef_freshnessValueType
typedef uint8 freshnessValueType[8];

# define Rte_TypeDef_CertP_BerElementType
typedef struct
{
  boolean validContent;
  uint16 elemDataIdx;
  uint16 elemDataLength;
} CertP_BerElementType;

# define Rte_TypeDef_Idt_codingData
typedef struct
{
  uint8 SarDataStorageStatus;
  uint32 MaxNumberOfSARWriteCycles;
  uint32 NumberOfSARWriteCycles;
} Idt_codingData;

# define Rte_TypeDef_Impl_Current_and_Threshold
typedef struct
{
  uint16 Current_Value;
  uint16 Threshold_Green_to_Yellow;
  uint16 Threshold_Yellow_to_Red;
} Impl_Current_and_Threshold;

# define Rte_TypeDef_KeyM_CertDataType
typedef struct
{
  uint32 certDataLength;
  KeyM_CertDataPointerType certData;
} KeyM_CertDataType;

# define Rte_TypeDef_SecLog_LogEntryCtrlDataType
typedef struct
{
  uint16 writeIdx;
  uint16 lengthContent;
  uint16 thresholdWarning;
} SecLog_LogEntryCtrlDataType;

# define Rte_TypeDef_StbM_OffsetRecordTableHeadType
typedef struct
{
  uint8 OffsetTimeDomain;
} StbM_OffsetRecordTableHeadType;

# define Rte_TypeDef_StbM_PortIdType
typedef struct
{
  uint64 clockIdentity;
  uint16 portNumber;
} StbM_PortIdType;

# define Rte_TypeDef_StbM_SyncRecordTableHeadType
typedef struct
{
  uint8 SynchronizedTimeDomain;
  uint32 HWfrequency;
  uint32 HWprescaler;
} StbM_SyncRecordTableHeadType;

# define Rte_TypeDef_StbM_TimeStampShortType
typedef struct
{
  uint32 nanoseconds;
  uint32 seconds;
} StbM_TimeStampShortType;

# define Rte_TypeDef_StbM_UserDataType
typedef struct
{
  uint8 userDataLength;
  uint8 userByte0;
  uint8 userByte1;
  uint8 userByte2;
} StbM_UserDataType;

# define Rte_TypeDef_StbM_VirtualLocalTimeType
typedef struct
{
  uint32 nanosecondsLo;
  uint32 nanosecondsHi;
} StbM_VirtualLocalTimeType;

# define Rte_TypeDef_TimeM_DateTimeType
typedef struct
{
  uint16 year;
  uint8 month;
  uint8 day;
  uint8 hour;
  uint8 minute;
  uint8 second;
} TimeM_DateTimeType;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint16 ComM_UserHandleType;

# define Rte_TypeDef_Csm_ConfigIdType
typedef uint16 Csm_ConfigIdType;

# define Rte_TypeDef_DC_BOOL
typedef boolean DC_BOOL;

# define Rte_TypeDef_DT_uint8
typedef uint8 DT_uint8;

# define Rte_TypeDef_DataPrimitiveType_uint16
typedef uint16 DataPrimitiveType_uint16;

# define Rte_TypeDef_DataPrimitiveType_uint32
typedef uint32 DataPrimitiveType_uint32;

# define Rte_TypeDef_DataPrimitiveType_uint8
typedef uint8 DataPrimitiveType_uint8;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Cycle_Execution_Start_Executed_CyclePrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Cycle_Execution_Start_Executed_CyclePrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Cycle_Execution_Start_Executed_CycleType
typedef Dcm_RequestDataOut_Routine_Cycle_Execution_Start_Executed_CyclePrimitiveType Dcm_RequestDataOut_Routine_Cycle_Execution_Start_Executed_CycleType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Cycle_Execution_Start_routineInfoType
typedef Dcm_RequestDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType Dcm_RequestDataOut_Routine_Cycle_Execution_Start_routineInfoType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_Post_Production_FlagPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_Post_Production_FlagPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_Post_Production_FlagType
typedef Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_Post_Production_FlagPrimitiveType Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_Post_Production_FlagType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoType
typedef Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType Dcm_RequestDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType
typedef Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType Dcm_RequestDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_BSR_Start_ResultPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Trigger_BSR_Start_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_BSR_Start_ResultType
typedef Dcm_RequestDataOut_Routine_Trigger_BSR_Start_ResultPrimitiveType Dcm_RequestDataOut_Routine_Trigger_BSR_Start_ResultType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_BSR_Start_routineInfoType
typedef Dcm_RequestDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType Dcm_RequestDataOut_Routine_Trigger_BSR_Start_routineInfoType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType
typedef Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultPrimitiveType Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType
typedef Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType
typedef Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultPrimitiveType Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType
typedef uint8 Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType
typedef Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_ConfigurationPrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_ConfigurationPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_ConfigurationType
typedef Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_ConfigurationPrimitiveType Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_ConfigurationType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_TaskPrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_TaskPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_TaskType
typedef Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_TaskPrimitiveType Dcm_StartDataIn_Routine_Authenticate_Diagnostic_User_or_Tester_Start_TaskType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Cycle_Execution_Start_CyclePrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Cycle_Execution_Start_CyclePrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Cycle_Execution_Start_CycleType
typedef Dcm_StartDataIn_Routine_Cycle_Execution_Start_CyclePrimitiveType Dcm_StartDataIn_Routine_Cycle_Execution_Start_CycleType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_EntryPrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_EntryPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_EntryType
typedef Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_EntryPrimitiveType Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_EntryType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_IdentificationPrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_IdentificationPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_IdentificationType
typedef Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_IdentificationPrimitiveType Dcm_StartDataIn_Routine_Get_Certificate_Entry_Start_In_Certificate_IdentificationType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signatureArrayType
typedef uint8 Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signatureArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signature_new_RootArrayType
typedef uint8 Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signature_new_RootArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagPrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagType
typedef Dcm_StartDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagPrimitiveType Dcm_StartDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_PreSafe_DurationPrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_PreSafe_DurationPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_PreSafe_DurationType
typedef Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_PreSafe_DurationPrimitiveType Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_PreSafe_DurationType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_Type_of_tensioning_cyclePrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_Type_of_tensioning_cyclePrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_Type_of_tensioning_cycleType
typedef Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_Type_of_tensioning_cyclePrimitiveType Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_Type_of_tensioning_cycleType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Data_SignatureArrayType
typedef uint8 Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Data_SignatureArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Date_and_TimeArrayType
typedef uint8 Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Date_and_TimeArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Encrypted_Nonce_and_Shared_SecretArrayType
typedef uint8 Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Encrypted_Nonce_and_Shared_SecretArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Ephemeral_VSM_Public_KeyArrayType
typedef uint8 Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Ephemeral_VSM_Public_KeyArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_CountArrayType
typedef uint8 Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_CountArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_Count_OffsetArrayType
typedef uint8 Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_Count_OffsetArrayType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Verify_Signature_Start_Data_to_be_checkedPrimitiveType
typedef uint8 Dcm_StartDataIn_Routine_Verify_Signature_Start_Data_to_be_checkedPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Verify_Signature_Start_Data_to_be_checkedType
typedef Dcm_StartDataIn_Routine_Verify_Signature_Start_Data_to_be_checkedPrimitiveType Dcm_StartDataIn_Routine_Verify_Signature_Start_Data_to_be_checkedType;

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Verify_Signature_Start_Signature_ValueArrayType
typedef uint8 Dcm_StartDataIn_Routine_Verify_Signature_Start_Signature_ValueArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Authenticate_Diagnostic_User_or_Tester_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Certificate_Self_Check_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Certificate_Self_Check_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Certificate_Self_Check_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Certificate_Self_Check_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Certificate_Self_Check_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsType
typedef Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsPrimitiveType Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Clear_Resource_Consumption_Data_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Cycle_Execution_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Cycle_Execution_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Enhance_Access_Rights_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Erase_All_Start_StatusPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Erase_All_Start_StatusPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Erase_All_Start_StatusType
typedef Dcm_StartDataOut_Routine_Erase_All_Start_StatusPrimitiveType Dcm_StartDataOut_Routine_Erase_All_Start_StatusType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Erase_All_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Evaluate_Data_Verification_Certificate_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusType
typedef Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusPrimitiveType Dcm_StartDataOut_Routine_Force_External_WDG_Start_StatusType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Force_External_WDG_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_EntryPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_EntryPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_EntryType
typedef Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_EntryPrimitiveType Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_EntryType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_IdentificationPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_IdentificationPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_IdentificationType
typedef Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_IdentificationPrimitiveType Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Out_Certificate_IdentificationType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Get_Certificate_Entry_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType
typedef Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultPrimitiveType Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_Dependencies_Verification_Check_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_PreCheckProgrammingDependencies_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Certificates_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Replace_Certificates_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Certificates_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Replace_Certificates_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Replace_Certificates_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Certificates_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Replace_Certificates_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Certificates_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Replace_Certificates_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Replace_Certificates_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Replace_Trust_model_Certificates_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Replace_Trust_model_Root_Certificate_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Reset_VINDataIdentifier_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Reset_VINDataIdentifier_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Reset_VINDataIdentifier_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Reset_VINDataIdentifier_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Reset_VINDataIdentifier_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagType
typedef Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagPrimitiveType Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_NonceArrayType
typedef uint8 Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_NonceArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_BSR_Start_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trigger_BSR_Start_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_BSR_Start_ResultType
typedef Dcm_StartDataOut_Routine_Trigger_BSR_Start_ResultPrimitiveType Dcm_StartDataOut_Routine_Trigger_BSR_Start_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_BSR_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Trigger_BSR_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType
typedef Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultPrimitiveType Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType
typedef Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultPrimitiveType Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_CSR_SignatureArrayType
typedef uint8 Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_CSR_SignatureArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Verify_Signature_Start_Verification_ResultPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Verify_Signature_Start_Verification_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Verify_Signature_Start_Verification_ResultType
typedef Dcm_StartDataOut_Routine_Verify_Signature_Start_Verification_ResultPrimitiveType Dcm_StartDataOut_Routine_Verify_Signature_Start_Verification_ResultType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Verify_Signature_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StartDataOut_Routine_Verify_Signature_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Verify_Signature_Start_routineInfoType
typedef Dcm_StartDataOut_Routine_Verify_Signature_Start_routineInfoPrimitiveType Dcm_StartDataOut_Routine_Verify_Signature_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StopDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagPrimitiveType
typedef uint8 Dcm_StopDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagPrimitiveType;

# define Rte_TypeDef_Dcm_StopDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagType
typedef Dcm_StopDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagPrimitiveType Dcm_StopDataIn_Routine_Status_of_Post_Production_Flag_Start_In_Post_Production_FlagType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StopDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Cycle_Execution_Start_routineInfoType
typedef Dcm_StopDataOut_Routine_Cycle_Execution_Start_routineInfoPrimitiveType Dcm_StopDataOut_Routine_Cycle_Execution_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagPrimitiveType
typedef uint8 Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagPrimitiveType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagType
typedef Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagPrimitiveType Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_Out_Post_Production_FlagType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoType
typedef Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoPrimitiveType Dcm_StopDataOut_Routine_Status_of_Post_Production_Flag_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType
typedef Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoPrimitiveType Dcm_StopDataOut_Routine_Synchronize_to_Non_volatile_Memory_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StopDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Trigger_BSR_Start_routineInfoType
typedef Dcm_StopDataOut_Routine_Trigger_BSR_Start_routineInfoPrimitiveType Dcm_StopDataOut_Routine_Trigger_BSR_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StopDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType
typedef Dcm_StopDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoPrimitiveType Dcm_StopDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType
typedef uint8 Dcm_StopDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType;

# define Rte_TypeDef_Dcm_StopDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType
typedef Dcm_StopDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoPrimitiveType Dcm_StopDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType;

# define Rte_TypeDef_Dem_DTCGroupType
typedef uint32 Dem_DTCGroupType;

# define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;

# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;

# define Rte_TypeDef_Dem_RatioIdType
typedef uint16 Dem_RatioIdType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_KeyM_CertElementIdType
typedef uint16 KeyM_CertElementIdType;

# define Rte_TypeDef_KeyM_CertificateIdType
typedef uint16 KeyM_CertificateIdType;

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

# define Rte_TypeDef_Rsrv01
typedef uint8 Rsrv01;

# define Rte_TypeDef_Rsrv02
typedef uint8 Rsrv02;

# define Rte_TypeDef_Rsrv04
typedef uint8 Rsrv04;

# define Rte_TypeDef_Rsrv05
typedef uint8 Rsrv05;

# define Rte_TypeDef_Rsrv08
typedef uint8 Rsrv08;

# define Rte_TypeDef_Rsrv24
typedef uint32 Rsrv24;

# define Rte_TypeDef_Rsrv27
typedef uint32 Rsrv27;

# define Rte_TypeDef_StbM_CustomerIdType
typedef uint16 StbM_CustomerIdType;

# define Rte_TypeDef_StbM_RateDeviationType
typedef sint16 StbM_RateDeviationType;

# define Rte_TypeDef_StbM_SynchronizedTimeBaseType
typedef uint16 StbM_SynchronizedTimeBaseType;

# define Rte_TypeDef_StbM_TimeDiffType
typedef sint32 StbM_TimeDiffType;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;

# define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;

# define Rte_TypeDef_b8DefectStatusType
typedef uint8 b8DefectStatusType;

# define Rte_TypeDef_b8IsActiveDiagSessionType
typedef uint8 b8IsActiveDiagSessionType;

# define Rte_TypeDef_c02_0_3_1_nSNA
typedef uint8 c02_0_3_1_nSNA;

# define Rte_TypeDef_c02_ADAS_MapVerQuar
typedef uint8 c02_ADAS_MapVerQuar;

# define Rte_TypeDef_c02_Navi_MPP_ResetRsn_ST3
typedef uint8 c02_Navi_MPP_ResetRsn_ST3;

# define Rte_TypeDef_c03_0_to_7_1_no_SNA
typedef uint8 c03_0_to_7_1_no_SNA;

# define Rte_TypeDef_c03_ADAS_Posn_Idx
typedef uint8 c03_ADAS_Posn_Idx;

# define Rte_TypeDef_c04_0_15_1_SNA_na
typedef uint8 c04_0_15_1_SNA_na;

# define Rte_TypeDef_c07_0_111_1_SNA
typedef uint8 c07_0_111_1_SNA;

# define Rte_TypeDef_c08_0_254_1_SNA_255
typedef uint8 c08_0_254_1_SNA_255;

# define Rte_TypeDef_c08_0_255_1_SNA_na
typedef uint8 c08_0_255_1_SNA_na;

# define Rte_TypeDef_c08_UInt_SNA_na
typedef uint8 c08_UInt_SNA_na;

# define Rte_TypeDef_c08_degC_m40_85_0k5
typedef uint8 c08_degC_m40_85_0k5;

# define Rte_TypeDef_c08_km_p_h_0_250_1_Blank
typedef uint8 c08_km_p_h_0_250_1_Blank;

# define Rte_TypeDef_c08_m_1d6_2d87_0d005
typedef uint8 c08_m_1d6_2d87_0d005;

# define Rte_TypeDef_c13_A_m409k6_409k4_0k1
typedef uint16 c13_A_m409k6_409k4_0k1;

# define Rte_TypeDef_c16_CRC_woSNA
typedef uint16 c16_CRC_woSNA;

# define Rte_TypeDef_c16_SeatBeltHdOvr_FctAvlStat_ST3
typedef uint16 c16_SeatBeltHdOvr_FctAvlStat_ST3;

# define Rte_TypeDef_c24_km_0_999999k9_0k1_Invld_SNA
typedef uint32 c24_km_0_999999k9_0k1_Invld_SNA;

# define Rte_TypeDef_cDC_tickCount_ST3
typedef uint64 cDC_tickCount_ST3;

# define Rte_TypeDef_freshnessValueLengthType
typedef uint32 freshnessValueLengthType;

# define Rte_TypeDef_s16AccelerationPedalPositionRateType
typedef sint16 s16AccelerationPedalPositionRateType;

# define Rte_TypeDef_s16AccelerationType
typedef sint16 s16AccelerationType;

# define Rte_TypeDef_s16AngleRateType
typedef sint16 s16AngleRateType;

# define Rte_TypeDef_s16BeltPosition_degType
typedef sint16 s16BeltPosition_degType;

# define Rte_TypeDef_s16BeltPosition_mmType
typedef sint16 s16BeltPosition_mmType;

# define Rte_TypeDef_s16BrakePressureRateType
typedef sint16 s16BrakePressureRateType;

# define Rte_TypeDef_s16HWAngleType
typedef sint16 s16HWAngleType;

# define Rte_TypeDef_s16HWRateType
typedef sint16 s16HWRateType;

# define Rte_TypeDef_s16InternalTemperature_deg_Type
typedef sint16 s16InternalTemperature_deg_Type;

# define Rte_TypeDef_s16MotorPowerOrderType
typedef sint16 s16MotorPowerOrderType;

# define Rte_TypeDef_s32BeltSpeed_deg_sType
typedef sint32 s32BeltSpeed_deg_sType;

# define Rte_TypeDef_s32BeltSpeed_mm_sType
typedef sint32 s32BeltSpeed_mm_sType;

# define Rte_TypeDef_s32MotorCurrentInmAType
typedef sint32 s32MotorCurrentInmAType;

# define Rte_TypeDef_s32OrderValueType
typedef sint32 s32OrderValueType;

# define Rte_TypeDef_s8MotorCurrentInAType
typedef sint8 s8MotorCurrentInAType;

# define Rte_TypeDef_u16BoostPWMOrderType
typedef uint16 u16BoostPWMOrderType;

# define Rte_TypeDef_u16BrakePressureType
typedef uint16 u16BrakePressureType;

# define Rte_TypeDef_u16CurrentInLSBType
typedef uint16 u16CurrentInLSBType;

# define Rte_TypeDef_u16InternalTemperatureType
typedef uint16 u16InternalTemperatureType;

# define Rte_TypeDef_u16Resistance_mOhmType
typedef uint16 u16Resistance_mOhmType;

# define Rte_TypeDef_u16SampledSignalType
typedef uint16 u16SampledSignalType;

# define Rte_TypeDef_u16StepDurationType
typedef uint16 u16StepDurationType;

# define Rte_TypeDef_u16VehicleSpeedType
typedef uint16 u16VehicleSpeedType;

# define Rte_TypeDef_u16VoltageType
typedef uint16 u16VoltageType;

# define Rte_TypeDef_u32DeficiencyLevelType
typedef uint32 u32DeficiencyLevelType;

# define Rte_TypeDef_u32InternalCounterType
typedef uint32 u32InternalCounterType;

# define Rte_TypeDef_u32RelativeSystemTimeType
typedef uint32 u32RelativeSystemTimeType;

# define Rte_TypeDef_u8AccelerationPedalPositionType
typedef uint8 u8AccelerationPedalPositionType;

# define Rte_TypeDef_u8MemoryClusterType
typedef uint8 u8MemoryClusterType;

# define Rte_TypeDef_u8SeverityLevelType
typedef uint8 u8SeverityLevelType;

# define Rte_TypeDef_u8StepNumberType
typedef uint8 u8StepNumberType;

# define Rte_TypeDef_u8VelocityTargetType
typedef uint8 u8VelocityTargetType;

# define Rte_TypeDef_BswM_ESH_KillAllRun
typedef uint8 BswM_ESH_KillAllRun;

# define Rte_TypeDef_BswM_ESH_Mode
typedef uint8 BswM_ESH_Mode;

# define Rte_TypeDef_BswM_ESH_RunRequest
typedef uint8 BswM_ESH_RunRequest;

# define Rte_TypeDef_CertP_PkiRoleType
typedef uint8 CertP_PkiRoleType;

# define Rte_TypeDef_CertP_VerificationResultType
typedef uint8 CertP_VerificationResultType;

# define Rte_TypeDef_Coding_MemoryStatusType
typedef uint8 Coding_MemoryStatusType;

# define Rte_TypeDef_Coding_ModeType
typedef uint8 Coding_ModeType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_Crypto_OperationModeType
typedef uint8 Crypto_OperationModeType;

# define Rte_TypeDef_Crypto_ResultType
typedef uint8 Crypto_ResultType;

# define Rte_TypeDef_Crypto_VerifyResultType
typedef uint8 Crypto_VerifyResultType;

# define Rte_TypeDef_Csm_KeyElementEnumType
typedef uint32 Csm_KeyElementEnumType;

# define Rte_TypeDef_Csm_ResultType
typedef uint8 Csm_ResultType;

# define Rte_TypeDef_Csm_VerifyResultType
typedef uint8 Csm_VerifyResultType;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;

# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;

# define Rte_TypeDef_Dcm_ModeRapidPowerShutDownType
typedef uint8 Dcm_ModeRapidPowerShutDownType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType_1
typedef uint8 Dcm_NegativeResponseCodeType_1;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Dcm_OpStatusType_1
typedef uint8 Dcm_OpStatusType_1;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;

# define Rte_TypeDef_Dem_ASR42_EventStatusExtendedType
typedef uint8 Dem_ASR42_EventStatusExtendedType;

# define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;

# define Rte_TypeDef_Dem_DTCOriginType
typedef uint16 Dem_DTCOriginType;

# define Rte_TypeDef_Dem_DTCSeverityType
typedef uint8 Dem_DTCSeverityType;

# define Rte_TypeDef_Dem_DTRControlType
typedef uint8 Dem_DTRControlType;

# define Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;

# define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;

# define Rte_TypeDef_Dem_EventStatusExtendedType
typedef uint8 Dem_EventStatusExtendedType;

# define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;

# define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;

# define Rte_TypeDef_Dem_InitMonitorReasonType
typedef uint8 Dem_InitMonitorReasonType;

# define Rte_TypeDef_Dem_IumprDenomCondIdType
typedef uint8 Dem_IumprDenomCondIdType;

# define Rte_TypeDef_Dem_IumprDenomCondStatusType
typedef uint8 Dem_IumprDenomCondStatusType;

# define Rte_TypeDef_Dem_IumprReadinessGroupType
typedef uint8 Dem_IumprReadinessGroupType;

# define Rte_TypeDef_Dem_MonitorStatusType
typedef uint8 Dem_MonitorStatusType;

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;

# define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;

# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;

# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;

# define Rte_TypeDef_KeyM_CertificateStatusType
typedef uint8 KeyM_CertificateStatusType;

# define Rte_TypeDef_KeyM_CsrEncodingType
typedef uint8 KeyM_CsrEncodingType;

# define Rte_TypeDef_KeyM_ResultType
typedef uint8 KeyM_ResultType;

# define Rte_TypeDef_KeyM_ServiceCertificateType
typedef uint8 KeyM_ServiceCertificateType;

# define Rte_TypeDef_NvM_ASR42_BlockIdType
typedef uint16 NvM_ASR42_BlockIdType;

# define Rte_TypeDef_NvM_ASR42_RequestResultType
typedef uint8 NvM_ASR42_RequestResultType;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_RightsM_ACL_BitMaskType
typedef uint32 RightsM_ACL_BitMaskType;

# define Rte_TypeDef_RightsM_AuthenticationModeType
typedef uint8 RightsM_AuthenticationModeType;

# define Rte_TypeDef_RightsM_AuthenticationStateType
typedef uint8 RightsM_AuthenticationStateType;

# define Rte_TypeDef_RightsM_DiagnosticUserRoleType
typedef uint8 RightsM_DiagnosticUserRoleType;

# define Rte_TypeDef_SecOC_VerificationResultType
typedef uint8 SecOC_VerificationResultType;

# define Rte_TypeDef_Ssa_ChangeTickCountEventIdType
typedef uint8 Ssa_ChangeTickCountEventIdType;

# define Rte_TypeDef_Ssa_IgnitionStatus_Prim
typedef uint8 Ssa_IgnitionStatus_Prim;

# define Rte_TypeDef_Ssa_KeyElementType
typedef uint32 Ssa_KeyElementType;

# define Rte_TypeDef_Ssa_KeyStorageTaskType
typedef uint8 Ssa_KeyStorageTaskType;

# define Rte_TypeDef_Ssa_KeyStorageUseCaseType
typedef uint8 Ssa_KeyStorageUseCaseType;

# define Rte_TypeDef_Ssa_OnOff_StateType
typedef uint8 Ssa_OnOff_StateType;

# define Rte_TypeDef_Ssa_OpStatusType
typedef uint8 Ssa_OpStatusType;

# define Rte_TypeDef_Ssa_OperationModeType
typedef uint8 Ssa_OperationModeType;

# define Rte_TypeDef_Ssa_PostProductionStatusType
typedef uint8 Ssa_PostProductionStatusType;

# define Rte_TypeDef_Ssa_PowernetMgmtStateType
typedef uint8 Ssa_PowernetMgmtStateType;

# define Rte_TypeDef_Ssa_ThresholdExceededType
typedef uint8 Ssa_ThresholdExceededType;

# define Rte_TypeDef_Ssa_TickCountSyncStateType
typedef uint8 Ssa_TickCountSyncStateType;

# define Rte_TypeDef_Ssa_TrustModelChainState_Type
typedef uint8 Ssa_TrustModelChainState_Type;

# define Rte_TypeDef_Ssa_VinStoreStateType
typedef uint8 Ssa_VinStoreStateType;

# define Rte_TypeDef_StbM_CloneConfigType
typedef uint8 StbM_CloneConfigType;

# define Rte_TypeDef_StbM_MasterConfigType
typedef uint8 StbM_MasterConfigType;

# define Rte_TypeDef_StbM_TimeBaseNotificationType
typedef uint32 StbM_TimeBaseNotificationType;

# define Rte_TypeDef_StbM_TimeBaseStatusType
typedef uint8 StbM_TimeBaseStatusType;

# define Rte_TypeDef_TimeM_CompareOperatorType
typedef uint8 TimeM_CompareOperatorType;

# define Rte_TypeDef_TimeM_RealTimeChangeReasonType
typedef uint8 TimeM_RealTimeChangeReasonType;

# define Rte_TypeDef_VIN_Status
typedef uint8 VIN_Status;

# define Rte_TypeDef_WdgMMode
typedef uint8 WdgMMode;

# define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;

# define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;

# define Rte_TypeDef_b8AlgorithmFlagsStatusType
typedef uint8 b8AlgorithmFlagsStatusType;

# define Rte_TypeDef_b8BooleanType
typedef uint8 b8BooleanType;

# define Rte_TypeDef_b8IsCarAccelerationLowType
typedef uint8 b8IsCarAccelerationLowType;

# define Rte_TypeDef_b8IsCarCrankingActiveType
typedef uint8 b8IsCarCrankingActiveType;

# define Rte_TypeDef_b8IsCarCrashDetectedType
typedef uint8 b8IsCarCrashDetectedType;

# define Rte_TypeDef_b8PyroActivationStatusType
typedef uint8 b8PyroActivationStatusType;

# define Rte_TypeDef_c01_FalseTrue
typedef uint8 c01_FalseTrue;

# define Rte_TypeDef_c01_Right_Left
typedef uint8 c01_Right_Left;

# define Rte_TypeDef_c01_UnitVehSpd
typedef uint8 c01_UnitVehSpd;

# define Rte_TypeDef_c02_Bckl_Sw_Stat
typedef uint8 c02_Bckl_Sw_Stat;

# define Rte_TypeDef_c02_BeltHdOvr_Stat
typedef uint8 c02_BeltHdOvr_Stat;

# define Rte_TypeDef_c02_DPC_Md_SSA
typedef uint8 c02_DPC_Md_SSA;

# define Rte_TypeDef_c02_Dr_Stat
typedef uint8 c02_Dr_Stat;

# define Rte_TypeDef_c02_EVC_Stat
typedef uint8 c02_EVC_Stat;

# define Rte_TypeDef_c02_HiBmLvr_Stat
typedef uint8 c02_HiBmLvr_Stat;

# define Rte_TypeDef_c02_Inact_Act_ST3
typedef uint8 c02_Inact_Act_ST3;

# define Rte_TypeDef_c02_Inactv_Silent_Actv_ST3
typedef uint8 c02_Inactv_Silent_Actv_ST3;

# define Rte_TypeDef_c02_NDef_ECO_Comfort
typedef uint8 c02_NDef_ECO_Comfort;

# define Rte_TypeDef_c02_NDef_Off_On_ST3
typedef uint8 c02_NDef_Off_On_ST3;

# define Rte_TypeDef_c02_NDef_On_Off
typedef uint8 c02_NDef_On_Off;

# define Rte_TypeDef_c02_Ndef_False_True_ST3
typedef uint8 c02_Ndef_False_True_ST3;

# define Rte_TypeDef_c02_Off_On
typedef uint8 c02_Off_On;

# define Rte_TypeDef_c02_Off_Stage1_Stage2
typedef uint8 c02_Off_Stage1_Stage2;

# define Rte_TypeDef_c02_PT_Rdy_V2
typedef uint8 c02_PT_Rdy_V2;

# define Rte_TypeDef_c02_Presf_Disp_Rq
typedef uint8 c02_Presf_Disp_Rq;

# define Rte_TypeDef_c02_Presf_Snd
typedef uint8 c02_Presf_Snd;

# define Rte_TypeDef_c02_SSA_Standby_Stat
typedef uint8 c02_SSA_Standby_Stat;

# define Rte_TypeDef_c02_StStyle
typedef uint8 c02_StStyle;

# define Rte_TypeDef_c02_TransMd_Stat
typedef uint8 c02_TransMd_Stat;

# define Rte_TypeDef_c02_TurnIndLvr_Stat
typedef uint8 c02_TurnIndLvr_Stat;

# define Rte_TypeDef_c02_TxBurnOut_Stat
typedef uint8 c02_TxBurnOut_Stat;

# define Rte_TypeDef_c02_false_true_sna
typedef uint8 c02_false_true_sna;

# define Rte_TypeDef_c03_0_6_1
typedef uint8 c03_0_6_1;

# define Rte_TypeDef_c03_ADAS_MapProvid
typedef uint8 c03_ADAS_MapProvid;

# define Rte_TypeDef_c03_ADAS_Posn_CurLane
typedef uint8 c03_ADAS_Posn_CurLane;

# define Rte_TypeDef_c03_Accel_Md_ST3
typedef uint8 c03_Accel_Md_ST3;

# define Rte_TypeDef_c03_DCDCBuckSuprtStat_ST3
typedef uint8 c03_DCDCBuckSuprtStat_ST3;

# define Rte_TypeDef_c03_DPC_Md_ExhaustFlap
typedef uint8 c03_DPC_Md_ExhaustFlap;

# define Rte_TypeDef_c03_DPC_Md_St
typedef uint8 c03_DPC_Md_St;

# define Rte_TypeDef_c03_EngStartPN14_Stat
typedef uint8 c03_EngStartPN14_Stat;

# define Rte_TypeDef_c03_ISw_Stat
typedef uint8 c03_ISw_Stat;

# define Rte_TypeDef_c03_MsgTyp_1_to_7
typedef uint8 c03_MsgTyp_1_to_7;

# define Rte_TypeDef_c03_No_Lt_Rt_Both
typedef uint8 c03_No_Lt_Rt_Both;

# define Rte_TypeDef_c03_PN14_ProdMd_Stat_ST3
typedef uint8 c03_PN14_ProdMd_Stat_ST3;

# define Rte_TypeDef_c03_PN14_TDP_Sw_Stat
typedef uint8 c03_PN14_TDP_Sw_Stat;

# define Rte_TypeDef_c03_VehPos_ST3
typedef uint8 c03_VehPos_ST3;

# define Rte_TypeDef_c03_m2_p3_1_Init
typedef uint8 c03_m2_p3_1_Init;

# define Rte_TypeDef_c04_DPC_GlobalMd_Rq
typedef uint8 c04_DPC_GlobalMd_Rq;

# define Rte_TypeDef_c04_DPC_Md_ESP_Rq_ST3
typedef uint8 c04_DPC_Md_ESP_Rq_ST3;

# define Rte_TypeDef_c04_DrvPosn_ST3
typedef uint8 c04_DrvPosn_ST3;

# define Rte_TypeDef_c04_EVC_HL_Style_ST3
typedef uint8 c04_EVC_HL_Style_ST3;

# define Rte_TypeDef_c04_EVC_TxStyle_ST3
typedef uint8 c04_EVC_TxStyle_ST3;

# define Rte_TypeDef_c04_EVC_YrOfModf_1_ST3
typedef uint8 c04_EVC_YrOfModf_1_ST3;

# define Rte_TypeDef_c04_EVC_YrOfModf_2_ST3
typedef uint8 c04_EVC_YrOfModf_2_ST3;

# define Rte_TypeDef_c04_Gr
typedef uint8 c04_Gr;

# define Rte_TypeDef_c04_Gr_Target
typedef uint8 c04_Gr_Target;

# define Rte_TypeDef_c04_NDef_Man_Auto
typedef uint8 c04_NDef_Man_Auto;

# define Rte_TypeDef_c04_Presf_Frct_ST3
typedef uint8 c04_Presf_Frct_ST3;

# define Rte_TypeDef_c04_Presf_Lvl_V2
typedef uint8 c04_Presf_Lvl_V2;

# define Rte_TypeDef_c04_RBTM_ActvClient
typedef uint8 c04_RBTM_ActvClient;

# define Rte_TypeDef_c04_VehOpMode
typedef uint8 c04_VehOpMode;

# define Rte_TypeDef_c05_ADAS_ProfShort_ProfTyp
typedef uint8 c05_ADAS_ProfShort_ProfTyp;

# define Rte_TypeDef_c05_DPC_Md_PT_HU
typedef uint8 c05_DPC_Md_PT_HU;

# define Rte_TypeDef_c05_DPC_Md_Susp_V2
typedef uint8 c05_DPC_Md_Susp_V2;

# define Rte_TypeDef_c05_perc_0_31_3k333
typedef uint8 c05_perc_0_31_3k333;

# define Rte_TypeDef_c06_ADAS_MapVerYear
typedef uint8 c06_ADAS_MapVerYear;

# define Rte_TypeDef_c06_EVC_BodyStyle_ST3
typedef uint8 c06_EVC_BodyStyle_ST3;

# define Rte_TypeDef_c06_EVC_VehLine_ST3
typedef uint8 c06_EVC_VehLine_ST3;

# define Rte_TypeDef_c06_Idx_0_to_63_1
typedef uint8 c06_Idx_0_to_63_1;

# define Rte_TypeDef_c06_RBTM_LVL_Rq
typedef uint8 c06_RBTM_LVL_Rq;

# define Rte_TypeDef_c06_RBTM_Lvl_Stat
typedef uint8 c06_RBTM_Lvl_Stat;

# define Rte_TypeDef_c07_per_0to100_1_SNA
typedef uint8 c07_per_0to100_1_SNA;

# define Rte_TypeDef_c08_EVC_Country_extended
typedef uint8 c08_EVC_Country_extended;

# define Rte_TypeDef_c08_ROE_0
typedef uint8 c08_ROE_0;

# define Rte_TypeDef_c08_TxDrvPosn
typedef uint8 c08_TxDrvPosn;

# define Rte_TypeDef_c08_V_0_25k4_0k1
typedef uint8 c08_V_0_25k4_0k1;

# define Rte_TypeDef_c08_deg_0_358k5_1k417
typedef uint8 c08_deg_0_358k5_1k417;

# define Rte_TypeDef_c08_km_p_h_0_254_1
typedef uint8 c08_km_p_h_0_254_1;

# define Rte_TypeDef_c08_km_p_h_30_250_1_NoRcmnd
typedef uint8 c08_km_p_h_30_250_1_NoRcmnd;

# define Rte_TypeDef_c08_perc_0_100_0k4
typedef uint8 c08_perc_0_100_0k4;

# define Rte_TypeDef_c08_perc_0_100_0k5
typedef uint8 c08_perc_0_100_0k5;

# define Rte_TypeDef_c09_ADAS_HwVer
typedef uint16 c09_ADAS_HwVer;

# define Rte_TypeDef_c09_km_p_h_0_500_1
typedef uint16 c09_km_p_h_0_500_1;

# define Rte_TypeDef_c09_m_p_s_m12k8_89k2_0k2
typedef uint16 c09_m_p_s_m12k8_89k2_0k2;

# define Rte_TypeDef_c09_ms_0_510_5
typedef uint32 c09_ms_0_510_5;

# define Rte_TypeDef_c10_ADAS_CountryCode
typedef uint16 c10_ADAS_CountryCode;

# define Rte_TypeDef_c10_PT4_PTCoor_DAS_Hlth_Stat
typedef uint16 c10_PT4_PTCoor_DAS_Hlth_Stat;

# define Rte_TypeDef_c10_RBTM_Fct_Precond
typedef uint16 c10_RBTM_Fct_Precond;

# define Rte_TypeDef_c10_V_0_25k55_0k025
typedef uint16 c10_V_0_25k55_0k025;

# define Rte_TypeDef_c10_WakeupRsn_ST3
typedef uint16 c10_WakeupRsn_ST3;

# define Rte_TypeDef_c10_m_0_510_1
typedef uint16 c10_m_0_510_1;

# define Rte_TypeDef_c10_to_1022_1
typedef uint16 c10_to_1022_1;

# define Rte_TypeDef_c12_0_4094_1_SNA
typedef uint16 c12_0_4094_1_SNA;

# define Rte_TypeDef_c12_km_p_h_0_409k4_0k1
typedef uint16 c12_km_p_h_0_409k4_0k1;

# define Rte_TypeDef_c12_rpm_0_16376_4
typedef uint16 c12_rpm_0_16376_4;

# define Rte_TypeDef_c13_PresfAct_Adj_Rq
typedef uint32 c13_PresfAct_Adj_Rq;

# define Rte_TypeDef_c13_m_0_8190_1
typedef uint16 c13_m_0_8190_1;

# define Rte_TypeDef_c14_rpm_0_16382_1
typedef uint16 c14_rpm_0_16382_1;

# define Rte_TypeDef_c15_ADAS_RegionCode
typedef uint16 c15_ADAS_RegionCode;

# define Rte_TypeDef_cDC_errorCode_ST3
typedef uint8 cDC_errorCode_ST3;

# define Rte_TypeDef_cDC_keyStorageTask_ST3
typedef uint8 cDC_keyStorageTask_ST3;

# define Rte_TypeDef_cDC_keyStorageUseCase_ST3
typedef uint8 cDC_keyStorageUseCase_ST3;

# define Rte_TypeDef_cDC_syncState_ST3
typedef uint8 cDC_syncState_ST3;

# define Rte_TypeDef_c_DC_VIN_Stat_ST3
typedef uint8 c_DC_VIN_Stat_ST3;

# define Rte_TypeDef_u16CalibBlockIdType
typedef uint16 u16CalibBlockIdType;

# define Rte_TypeDef_u32AecGroupsType
typedef uint32 u32AecGroupsType;

# define Rte_TypeDef_u32ModeMaskType
typedef uint32 u32ModeMaskType;

# define Rte_TypeDef_u32ResetCauseType
typedef uint32 u32ResetCauseType;

# define Rte_TypeDef_u32ResetReasonNotificationStatusType
typedef uint32 u32ResetReasonNotificationStatusType;

# define Rte_TypeDef_u32ResetReasonNotificationType
typedef uint32 u32ResetReasonNotificationType;

# define Rte_TypeDef_u8AecCommandType
typedef uint8 u8AecCommandType;

# define Rte_TypeDef_u8AecIdentifierType
typedef uint8 u8AecIdentifierType;

# define Rte_TypeDef_u8AecStatusType
typedef uint8 u8AecStatusType;

# define Rte_TypeDef_u8AutoTestIdType
typedef uint8 u8AutoTestIdType;

# define Rte_TypeDef_u8BatteryVoltageSurveyStatusType
typedef uint8 u8BatteryVoltageSurveyStatusType;

# define Rte_TypeDef_u8BeltParkingAuthorizationStateType
typedef uint8 u8BeltParkingAuthorizationStateType;

# define Rte_TypeDef_u8BeltSlackStatusType
typedef uint8 u8BeltSlackStatusType;

# define Rte_TypeDef_u8CanNmStateType
typedef uint8 u8CanNmStateType;

# define Rte_TypeDef_u8ClkStatusType
typedef uint8 u8ClkStatusType;

# define Rte_TypeDef_u8CycleNumberType
typedef uint8 u8CycleNumberType;

# define Rte_TypeDef_u8DoorSwitchStatusType
typedef uint8 u8DoorSwitchStatusType;

# define Rte_TypeDef_u8EccErrorStatusType
typedef uint8 u8EccErrorStatusType;

# define Rte_TypeDef_u8EccErrorType
typedef uint8 u8EccErrorType;

# define Rte_TypeDef_u8EsmEventIdType
typedef uint8 u8EsmEventIdType;

# define Rte_TypeDef_u8EsmStateType
typedef uint8 u8EsmStateType;

# define Rte_TypeDef_u8HapticRequestType
typedef uint8 u8HapticRequestType;

# define Rte_TypeDef_u8JobTypesListType
typedef uint8 u8JobTypesListType;

# define Rte_TypeDef_u8KlemmenStatusType
typedef uint8 u8KlemmenStatusType;

# define Rte_TypeDef_u8ModeStatusType
typedef uint8 u8ModeStatusType;

# define Rte_TypeDef_u8MotorStageStatusType
typedef uint8 u8MotorStageStatusType;

# define Rte_TypeDef_u8OrdersListType
typedef uint8 u8OrdersListType;

# define Rte_TypeDef_u8PreCrashRequestType
typedef uint8 u8PreCrashRequestType;

# define Rte_TypeDef_u8PreCrashSeverityLevelType
typedef uint8 u8PreCrashSeverityLevelType;

# define Rte_TypeDef_u8PwmChannelIdType
typedef uint8 u8PwmChannelIdType;

# define Rte_TypeDef_u8RetractionStatusType
typedef uint8 u8RetractionStatusType;

# define Rte_TypeDef_u8TensioningStateType
typedef UInt8 u8TensioningStateType;

# define Rte_TypeDef_u8TestResultType
typedef uint8 u8TestResultType;

# define Rte_TypeDef_u8TriggeringSourceType
typedef uint8 u8TriggeringSourceType;

# define Rte_TypeDef_u8WdgTestResultType
typedef uint8 u8WdgTestResultType;

# define Rte_TypeDef_u8lBuckleSwitchStatusType
typedef uint8 u8lBuckleSwitchStatusType;

# define Rte_TypeDef_ARR_08_UInt_noSNA_17
typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_17[17];

# define Rte_TypeDef_ARR_08_UInt_noSNA_32
typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_32[32];

# define Rte_TypeDef_ARR_08_UInt_noSNA_64
typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_64[64];

# define Rte_TypeDef_ARR_08_UInt_noSNA_7
typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_7[7];

# define Rte_TypeDef_ARR_08_UInt_noSNA_8
typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_8[8];

# define Rte_TypeDef_Dcm_Data192ByteType
typedef DT_uint8 Dcm_Data192ByteType[192];

# define Rte_TypeDef_Dcm_Data96ByteType
typedef DT_uint8 Dcm_Data96ByteType[96];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signatureType
typedef Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signatureArrayType Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signatureType[64];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signature_new_RootType
typedef Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signature_new_RootArrayType Dcm_StartDataIn_Routine_Replace_Trust_model_Root_Certificate_Start_signature_new_RootType[64];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Data_SignatureType
typedef Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Data_SignatureArrayType Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Data_SignatureType[64];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Date_and_TimeType
typedef Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Date_and_TimeArrayType Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Date_and_TimeType[7];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Encrypted_Nonce_and_Shared_SecretType
typedef Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Encrypted_Nonce_and_Shared_SecretArrayType Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Encrypted_Nonce_and_Shared_SecretType[80];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Ephemeral_VSM_Public_KeyType
typedef Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Ephemeral_VSM_Public_KeyArrayType Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Ephemeral_VSM_Public_KeyType[32];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_CountType
typedef Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_CountArrayType Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_CountType[5];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_Count_OffsetType
typedef Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_Count_OffsetArrayType Dcm_StartDataIn_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Tick_Count_OffsetType[5];

# define Rte_TypeDef_Dcm_StartDataIn_Routine_Verify_Signature_Start_Signature_ValueType
typedef Dcm_StartDataIn_Routine_Verify_Signature_Start_Signature_ValueArrayType Dcm_StartDataIn_Routine_Verify_Signature_Start_Signature_ValueType[64];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_NonceType
typedef Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_NonceArrayType Dcm_StartDataOut_Routine_Synchronize_Secured_System_Date_and_Time_Start_NonceType[32];

# define Rte_TypeDef_Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_CSR_SignatureType
typedef Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_CSR_SignatureArrayType Dcm_StartDataOut_Routine_Trust_Model_Generate_Key_Pair_Start_CSR_SignatureType[64];

# define Rte_TypeDef_PreSafeCyclesLevel_AssociatedCounterDataType
typedef DT_uint8 PreSafeCyclesLevel_AssociatedCounterDataType[11];

# define Rte_TypeDef_PreSafeCyclesLevel_HapticDataType
typedef DT_uint8 PreSafeCyclesLevel_HapticDataType[24];

# define Rte_TypeDef_PreSafeCyclesLevel_LibraryDataType
typedef DT_uint8 PreSafeCyclesLevel_LibraryDataType[736];

# define Rte_TypeDef_SecLog_CtrlDataType
typedef SecLog_LogEntryCtrlDataType SecLog_CtrlDataType[13];

# define Rte_TypeDef_CalibrationIdentifications_StorageType
typedef struct
{
  Dcm_Data1ByteType NumberOfDataItems;
  Dcm_Data17ByteType CalibrationIdentification;
} CalibrationIdentifications_StorageType;

# define Rte_TypeDef_CertP_TimeType
typedef struct
{
  boolean validContent;
  TimeM_DateTimeType dateTime;
} CertP_TimeType;

# define Rte_TypeDef_Coding_StorageType
typedef struct
{
  Coding_VINDataType VIN;
  uint8 attributes;
} Coding_StorageType;

# define Rte_TypeDef_Impl_Obsolescense_Data
typedef struct
{
  Impl_Current_and_Threshold BSR;
  Impl_Current_and_Threshold Haptic_Warning;
  Impl_Current_and_Threshold PRE_SAFE_LVL_4_5;
  Impl_Current_and_Threshold PRE_CRASH;
} Impl_Obsolescense_Data;

# define Rte_TypeDef_KeyM_CertificateType_Ssa_TrustModelBackendCert
typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelBackendCert certData;
} KeyM_CertificateType_Ssa_TrustModelBackendCert;

# define Rte_TypeDef_KeyM_CertificateType_Ssa_TrustModelBackendPeerCert
typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelBackendPeerCert certData;
} KeyM_CertificateType_Ssa_TrustModelBackendPeerCert;

# define Rte_TypeDef_KeyM_CertificateType_Ssa_TrustModelEcuCert
typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelEcuCert certData;
} KeyM_CertificateType_Ssa_TrustModelEcuCert;

# define Rte_TypeDef_KeyM_CertificateType_Ssa_TrustModelEcuCsr
typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelEcuCsr certData;
} KeyM_CertificateType_Ssa_TrustModelEcuCsr;

# define Rte_TypeDef_KeyM_CertificateType_Ssa_TrustModelEcuPeerCert
typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelEcuPeerCert certData;
} KeyM_CertificateType_Ssa_TrustModelEcuPeerCert;

# define Rte_TypeDef_KeyM_CertificateType_Ssa_TrustModelIntermediateCert
typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelIntermediateCert certData;
} KeyM_CertificateType_Ssa_TrustModelIntermediateCert;

# define Rte_TypeDef_KeyM_CertificateType_Ssa_TrustModelIntermediatePeerCert
typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelIntermediatePeerCert certData;
} KeyM_CertificateType_Ssa_TrustModelIntermediatePeerCert;

# define Rte_TypeDef_KeyM_CertificateType_Ssa_TrustModelRootCert
typedef struct
{
  uint32 certDataLength;
  KeyM_CertificateDataType_Ssa_TrustModelRootCert certData;
} KeyM_CertificateType_Ssa_TrustModelRootCert;

# define Rte_TypeDef_PreSafeCyclesLevel_StorageType
typedef struct
{
  Dcm_Data12ByteType Presafe1;
  Dcm_Data12ByteType Presafe2;
  Dcm_Data12ByteType Presafe3;
  Dcm_Data12ByteType Presafe4;
  Dcm_Data12ByteType Presafe5;
  Dcm_Data12ByteType Presafe6;
  Dcm_Data12ByteType Presafe7;
  Dcm_Data12ByteType Presafe8;
  Dcm_Data12ByteType Presafe9;
  Dcm_Data12ByteType Presafe10;
  Dcm_Data12ByteType Presafe11;
  Dcm_Data12ByteType Presafe12;
  Dcm_Data12ByteType Presafe13;
  Dcm_Data12ByteType Presafe14;
  Dcm_Data12ByteType Curve1;
  Dcm_Data12ByteType Curve2;
  Dcm_Data12ByteType Curve3;
  Dcm_Data12ByteType Curve4;
  PreSafeCyclesLevel_HapticDataType Haptic1;
  PreSafeCyclesLevel_HapticDataType Haptic2;
  PreSafeCyclesLevel_HapticDataType Haptic3;
  PreSafeCyclesLevel_HapticDataType Haptic4;
  PreSafeCyclesLevel_LibraryDataType Library;
  Dcm_Data2ByteType TimeoutPresafe5;
  Dcm_Data2ByteType DurationHaptic1;
  Dcm_Data2ByteType DurationHaptic2;
  Dcm_Data2ByteType DurationHaptic3;
  Dcm_Data2ByteType DurationHaptic4;
  Dcm_Data1ByteType HapticType;
  Dcm_Data1ByteType PRESAFEAccelerationTimeout;
  Dcm_Data1ByteType Haptic1AccelerationTimeout;
  Dcm_Data1ByteType APIAccelerationTimeout;
  PreSafeCyclesLevel_AssociatedCounterDataType AssociatedCounter;
} PreSafeCyclesLevel_StorageType;

# define Rte_TypeDef_REC_ADAS_Meta_ST3
typedef struct
{
  c10_ADAS_CountryCode ADAS_Meta_CountryCode_ST3;
  c02_0_3_1_nSNA ADAS_Meta_CycCnt_ST3;
  c01_Right_Left ADAS_Meta_DrvSide_ST3;
  c09_ADAS_HwVer ADAS_Meta_HwVer_ST3;
  c03_ADAS_MapProvid ADAS_Meta_MapProvid_ST3;
  c02_ADAS_MapVerQuar ADAS_Meta_MapVerQuar_ST3;
  c06_ADAS_MapVerYear ADAS_Meta_MapVerYear_ST3;
  c02_0_3_1_nSNA ADAS_Meta_ProtVer_Major_ST3;
  c04_0_15_1_SNA_na ADAS_Meta_ProtVer_Minor_ST3;
  c03_0_to_7_1_no_SNA ADAS_Meta_ProtVer_MinorSub_ST3;
  c15_ADAS_RegionCode ADAS_Meta_RegionCode_ST3;
  c01_UnitVehSpd ADAS_Meta_SpdUnits_ST3;
} REC_ADAS_Meta_ST3;

# define Rte_TypeDef_REC_ADAS_Meta_ST3_b2mk60164reg2lw3ivnikdnou
typedef struct
{
  c10_ADAS_CountryCode ADAS_Meta_CountryCode_ST3;
  c15_ADAS_RegionCode ADAS_Meta_RegionCode_ST3;
} REC_ADAS_Meta_ST3_b2mk60164reg2lw3ivnikdnou;

# define Rte_TypeDef_REC_ADAS_Posn_ST3
typedef struct
{
  c09_ms_0_510_5 ADAS_Posn_Age_ST3;
  c03_ADAS_Posn_CurLane ADAS_Posn_CurLane_ST3;
  c02_0_3_1_nSNA ADAS_Posn_CycCnt_ST3;
  c03_ADAS_Posn_Idx ADAS_Posn_Idx_ST3;
  c03_MsgTyp_1_to_7 ADAS_Posn_MsgTyp_ST3;
  c13_m_0_8190_1 ADAS_Posn_Offset_ST3;
  c06_Idx_0_to_63_1 ADAS_Posn_PathIdx_ST3;
  c03_0_6_1 ADAS_Posn_PosConfdc_ST3;
  c05_perc_0_31_3k333 ADAS_Posn_PosProbb_ST3;
  c08_deg_0_358k5_1k417 ADAS_Posn_RelHead_ST3;
  c09_m_p_s_m12k8_89k2_0k2 ADAS_Posn_Spd_ST3;
} REC_ADAS_Posn_ST3;

# define Rte_TypeDef_REC_ADAS_Posn_ST3_7tu0j7cag3wthixhamscgyjyr
typedef struct
{
  c09_ms_0_510_5 ADAS_Posn_Age_ST3;
  c03_ADAS_Posn_Idx ADAS_Posn_Idx_ST3;
  c13_m_0_8190_1 ADAS_Posn_Offset_ST3;
  c06_Idx_0_to_63_1 ADAS_Posn_PathIdx_ST3;
  c09_m_p_s_m12k8_89k2_0k2 ADAS_Posn_Spd_ST3;
} REC_ADAS_Posn_ST3_7tu0j7cag3wthixhamscgyjyr;

# define Rte_TypeDef_REC_ADAS_Profile_Short_CurvLn_ST3
typedef struct
{
  c02_0_3_1_nSNA ADAS_ProfShort_AccurClass_CL_ST3;
  c01_FalseTrue ADAS_ProfShort_CtrlPoint_CL_ST3;
  c02_0_3_1_nSNA ADAS_ProfShort_CycCnt_CL_ST3;
  c10_m_0_510_1 ADAS_ProfShort_Dist1_CL_ST3;
  c03_MsgTyp_1_to_7 ADAS_ProfShort_MsgTyp_CL_ST3;
  c13_m_0_8190_1 ADAS_ProfShort_Offset_CL_ST3;
  c06_Idx_0_to_63_1 ADAS_ProfShort_PathIdx_CL_ST3;
  c01_FalseTrue ADAS_ProfShort_ReTr_CL_ST3;
  c01_FalseTrue ADAS_ProfShort_Updt_CL_ST3;
  c10_to_1022_1 ADAS_ProfShort_Value0_CL_ST3;
  c10_to_1022_1 ADAS_ProfShort_Value1_CL_ST3;
} REC_ADAS_Profile_Short_CurvLn_ST3;

# define Rte_TypeDef_REC_ADAS_Profile_Short_CurvLn_ST3_490g5rtcnid4ivawivkcosvcg
typedef struct
{
  c10_m_0_510_1 ADAS_ProfShort_Dist1_CL_ST3;
  c13_m_0_8190_1 ADAS_ProfShort_Offset_CL_ST3;
  c06_Idx_0_to_63_1 ADAS_ProfShort_PathIdx_CL_ST3;
  c01_FalseTrue ADAS_ProfShort_ReTr_CL_ST3;
  c10_to_1022_1 ADAS_ProfShort_Value0_CL_ST3;
  c10_to_1022_1 ADAS_ProfShort_Value1_CL_ST3;
} REC_ADAS_Profile_Short_CurvLn_ST3_490g5rtcnid4ivawivkcosvcg;

# define Rte_TypeDef_REC_Bckl_Sw_Fx_Stat_Pr5_ST3
typedef struct
{
  Rsrv04 Rsrv1_Bckl_Sw_Fx_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_D_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_FP_Stat_ST3;
  c16_CRC_woSNA CRC_Bckl_Sw_Fx_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_Bckl_Sw_Fx_Stat_Pr5_ST3;
} REC_Bckl_Sw_Fx_Stat_Pr5_ST3;

# define Rte_TypeDef_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx
typedef struct
{
  c02_Bckl_Sw_Stat Bckl_Sw_D_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_FP_Stat_ST3;
} REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx;

# define Rte_TypeDef_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt
typedef struct
{
  Rsrv04 Rsrv1_Bckl_Sw_Fx_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_D_Stat_ST3;
  c02_Bckl_Sw_Stat Bckl_Sw_FP_Stat_ST3;
  c16_CRC_woSNA CRC_Bckl_Sw_Fx_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_Bckl_Sw_Fx_Stat_Pr5_ST3;
} REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt;

# define Rte_TypeDef_REC_CLkS_DrRltch_Stat_Pr5_ST3
typedef struct
{
  c16_CRC_woSNA CRC_CLkS_DrRltch_Stat_Pr5_ST3;
  c02_Dr_Stat DrRLtch_FL_Stat_ST3;
  c02_Dr_Stat DrRLtch_FR_Stat_ST3;
  c02_Dr_Stat DrRLtch_RL_Stat_ST3;
  c02_Dr_Stat DrRLtch_RR_Stat_ST3;
  c08_0_255_1_SNA_na SQC_CLkS_DrRltch_Stat_Pr5_ST3;
} REC_CLkS_DrRltch_Stat_Pr5_ST3;

# define Rte_TypeDef_REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx
typedef struct
{
  c02_Dr_Stat DrRLtch_FL_Stat_ST3;
  c02_Dr_Stat DrRLtch_FR_Stat_ST3;
} REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx;

# define Rte_TypeDef_REC_DI_Odo_Pr5_ST3
typedef struct
{
  c16_CRC_woSNA CRC_DI_Odo_Pr5_ST3;
  c24_km_0_999999k9_0k1_Invld_SNA Odo_ST3;
  c08_0_255_1_SNA_na SQC_DI_Odo_Pr5_ST3;
} REC_DI_Odo_Pr5_ST3;

# define Rte_TypeDef_REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh
typedef struct
{
  c24_km_0_999999k9_0k1_Invld_SNA Odo_ST3;
} REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh;

# define Rte_TypeDef_REC_DPC_Md_Rq_ESP_Pr5_ST3
typedef struct
{
  c04_DPC_GlobalMd_Rq DPC_GlobalMd_Rq_ST3;
  c02_Ndef_False_True_ST3 DPC_GlobalMd_TrgRq_ST3;
  c02_NDef_On_Off DPC_Md_eSPC_Carv_Rq_ST3;
  c02_NDef_On_Off DPC_Md_ABC_Preview_Rq_ST3;
  c04_DPC_Md_ESP_Rq_ST3 DPC_Md_ESP_Rq_ST3;
  c03_DPC_Md_ExhaustFlap DPC_Md_ExhstFlap_Rq_ST3;
  c02_NDef_ECO_Comfort DPC_Md_Ht_Rq_ST3;
  c05_DPC_Md_PT_HU DPC_Md_PT_Rq_ST3;
  c02_NDef_On_Off DPC_Md_PwrFreeD_Plus_Rq_ST3;
  c02_DPC_Md_SSA DPC_Md_SSA_Rq_ST3;
  c03_DPC_Md_St DPC_Md_St_Rq_ST3;
  c05_DPC_Md_Susp_V2 DPC_Md_Susp_Rq_ST3;
  c03_m2_p3_1_Init DPC_Md_SuspLvl_Rq_ST3;
  c04_NDef_Man_Auto DPC_Md_Tx_Rq_ST3;
  Rsrv05 Rsrv1_DPC_Md_Rq_ESP_Pr5_ST3;
  c16_CRC_woSNA CRC_DPC_Md_Rq_ESP_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_DPC_Md_Rq_ESP_Pr5_ST3;
  Rsrv24 Rsrv2_DPC_Md_Rq_ESP_Pr5_ST3;
} REC_DPC_Md_Rq_ESP_Pr5_ST3;

# define Rte_TypeDef_REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86
typedef struct
{
  c05_DPC_Md_PT_HU DPC_Md_PT_Rq_ST3;
} REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86;

# define Rte_TypeDef_REC_Develop8_Rq_RBTM_FL_ST3
typedef struct
{
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_01;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_02;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_03;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_04;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_05;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_06;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_07;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_08;
} REC_Develop8_Rq_RBTM_FL_ST3;

# define Rte_TypeDef_REC_Develop8_Rq_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv
typedef struct
{
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_01;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_02;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_03;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_04;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_05;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_06;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_07;
  c08_UInt_SNA_na Develop_Rq_RBTM_FL_08;
} REC_Develop8_Rq_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv;

# define Rte_TypeDef_REC_Develop8_Rq_RBTM_FR_ST3
typedef struct
{
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_01;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_02;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_03;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_04;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_05;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_06;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_07;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_08;
} REC_Develop8_Rq_RBTM_FR_ST3;

# define Rte_TypeDef_REC_Develop8_Rq_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv
typedef struct
{
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_01;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_02;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_03;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_04;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_05;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_06;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_07;
  c08_UInt_SNA_na Develop_Rq_RBTM_FR_08;
} REC_Develop8_Rq_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv;

# define Rte_TypeDef_REC_Develop8_Rs_RBTM_FL_ST3
typedef struct
{
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_01;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_02;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_03;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_04;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_05;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_06;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_07;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_08;
} REC_Develop8_Rs_RBTM_FL_ST3;

# define Rte_TypeDef_REC_Develop8_Rs_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv
typedef struct
{
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_01;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_02;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_03;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_04;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_05;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_06;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_07;
  c08_UInt_SNA_na Develop_Rs_RBTM_FL_08;
} REC_Develop8_Rs_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv;

# define Rte_TypeDef_REC_Develop8_Rs_RBTM_FR_ST3
typedef struct
{
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_01;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_02;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_03;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_04;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_05;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_06;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_07;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_08;
} REC_Develop8_Rs_RBTM_FR_ST3;

# define Rte_TypeDef_REC_Develop8_Rs_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv
typedef struct
{
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_01;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_02;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_03;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_04;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_05;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_06;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_07;
  c08_UInt_SNA_na Develop_Rs_RBTM_FR_08;
} REC_Develop8_Rs_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv;

# define Rte_TypeDef_REC_ELC_Lvr_Stat_Pr5_ST3
typedef struct
{
  c16_CRC_woSNA CRC_ELC_Lvr_Stat_Pr5_ST3;
  c02_TurnIndLvr_Stat ELC_TurnIndLvr_Stat_ST3;
  Rsrv04 Rsrv1_ELC_Lvr_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_ELC_Lvr_Stat_Pr5_ST3;
  c02_HiBmLvr_Stat ELC_HiBmLvr_Stat_ST3;
} REC_ELC_Lvr_Stat_Pr5_ST3;

# define Rte_TypeDef_REC_ELC_Lvr_Stat_Pr5_ST3_9t50popkpz30is106xpis1iyh
typedef struct
{
  c02_TurnIndLvr_Stat ELC_TurnIndLvr_Stat_ST3;
} REC_ELC_Lvr_Stat_Pr5_ST3_9t50popkpz30is106xpis1iyh;

# define Rte_TypeDef_REC_EVC_CfgList_01_08_Pr5_ST3
typedef struct
{
  c16_CRC_woSNA CRC_EVC_CfgList_01_08_Pr5_ST3;
  c02_EVC_Stat EVC_CfgList_01_08_Stat_ST3;
  c06_EVC_BodyStyle_ST3 EVC_List01_BodyStyle_ST3;
  c06_EVC_VehLine_ST3 EVC_List02_VehLine_ST3;
  c02_StStyle EVC_List03_StStyle_ST3;
  c04_EVC_YrOfModf_2_ST3 EVC_List04_YrOfModf_2_ST3;
  c04_EVC_YrOfModf_1_ST3 EVC_List05_YrOfModf_1_ST3;
  c08_EVC_Country_extended EVC_List06_Country_ST3;
  c04_EVC_TxStyle_ST3 EVC_List07_TxStyle_ST3;
  c04_EVC_HL_Style_ST3 EVC_List08_HL_Style_ST3;
  c08_0_255_1_SNA_na SQC_EVC_CfgList_01_08_Pr5_ST3;
} REC_EVC_CfgList_01_08_Pr5_ST3;

# define Rte_TypeDef_REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby
typedef struct
{
  c02_StStyle EVC_List03_StStyle_ST3;
} REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby;

# define Rte_TypeDef_REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw
typedef struct
{
  c02_EVC_Stat EVC_CfgList_01_08_Stat_ST3;
  c02_StStyle EVC_List03_StStyle_ST3;
} REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw;

# define Rte_TypeDef_REC_Ign_Stat_Pr5_ST3
typedef struct
{
  c03_ISw_Stat ISw_Stat_ST3;
  c04_VehOpMode Veh_Op_Mode_ST3;
  c16_CRC_woSNA CRC_Ign_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_Ign_Stat_Pr5_ST3;
  DC_BOOL KG_StartSw_Psd_ST3;
} REC_Ign_Stat_Pr5_ST3;

# define Rte_TypeDef_REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0
typedef struct
{
  c03_ISw_Stat ISw_Stat_ST3;
} REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0;

# define Rte_TypeDef_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96
typedef struct
{
  c03_ISw_Stat ISw_Stat_ST3;
  c04_VehOpMode Veh_Op_Mode_ST3;
  c16_CRC_woSNA CRC_Ign_Stat_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_Ign_Stat_Pr5_ST3;
  DC_BOOL KG_StartSw_Psd_ST3;
} REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96;

# define Rte_TypeDef_REC_Meas_RBTM_FL_ST3
typedef struct
{
  c08_UInt_SNA_na Meas_RBTM_FL_01;
  c08_UInt_SNA_na Meas_RBTM_FL_02;
  c08_UInt_SNA_na Meas_RBTM_FL_03;
  c08_UInt_SNA_na Meas_RBTM_FL_04;
  c08_UInt_SNA_na Meas_RBTM_FL_05;
  c08_UInt_SNA_na Meas_RBTM_FL_06;
  c08_UInt_SNA_na Meas_RBTM_FL_07;
  c08_UInt_SNA_na Meas_RBTM_FL_08;
} REC_Meas_RBTM_FL_ST3;

# define Rte_TypeDef_REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv
typedef struct
{
  c08_UInt_SNA_na Meas_RBTM_FL_01;
  c08_UInt_SNA_na Meas_RBTM_FL_02;
  c08_UInt_SNA_na Meas_RBTM_FL_03;
  c08_UInt_SNA_na Meas_RBTM_FL_04;
  c08_UInt_SNA_na Meas_RBTM_FL_05;
  c08_UInt_SNA_na Meas_RBTM_FL_06;
  c08_UInt_SNA_na Meas_RBTM_FL_07;
  c08_UInt_SNA_na Meas_RBTM_FL_08;
} REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv;

# define Rte_TypeDef_REC_Meas_RBTM_FR_ST3
typedef struct
{
  c08_UInt_SNA_na Meas_RBTM_FR_01;
  c08_UInt_SNA_na Meas_RBTM_FR_02;
  c08_UInt_SNA_na Meas_RBTM_FR_03;
  c08_UInt_SNA_na Meas_RBTM_FR_04;
  c08_UInt_SNA_na Meas_RBTM_FR_05;
  c08_UInt_SNA_na Meas_RBTM_FR_06;
  c08_UInt_SNA_na Meas_RBTM_FR_07;
  c08_UInt_SNA_na Meas_RBTM_FR_08;
} REC_Meas_RBTM_FR_ST3;

# define Rte_TypeDef_REC_Meas_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv
typedef struct
{
  c08_UInt_SNA_na Meas_RBTM_FR_01;
  c08_UInt_SNA_na Meas_RBTM_FR_02;
  c08_UInt_SNA_na Meas_RBTM_FR_03;
  c08_UInt_SNA_na Meas_RBTM_FR_04;
  c08_UInt_SNA_na Meas_RBTM_FR_05;
  c08_UInt_SNA_na Meas_RBTM_FR_06;
  c08_UInt_SNA_na Meas_RBTM_FR_07;
  c08_UInt_SNA_na Meas_RBTM_FR_08;
} REC_Meas_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv;

# define Rte_TypeDef_REC_ORC_Impact2_Pr5_ST3
typedef struct
{
  DC_BOOL Impact_Y_ST3;
  c16_CRC_woSNA CRC_ORC_Impact2_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_ORC_Impact2_Pr5_ST3;
  DC_BOOL Impact_R1_ST3;
  DC_BOOL Impact_R2_ST3;
  DC_BOOL Impact_minor_ST3;
  DC_BOOL Impact_P_ST3;
  c03_VehPos_ST3 VehPosn_ST3;
} REC_ORC_Impact2_Pr5_ST3;

# define Rte_TypeDef_REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh
typedef struct
{
  DC_BOOL Impact_Y_ST3;
} REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh;

# define Rte_TypeDef_REC_ORC_Impact3_Pr5_ST3
typedef struct
{
  DC_BOOL Impact_F1_ST3;
  DC_BOOL Impact_F3_ST3;
  DC_BOOL Impact_RO_type1_ST3;
  DC_BOOL Impact_RO_type2_ST3;
  c16_CRC_woSNA CRC_ORC_Impact3_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_ORC_Impact3_Pr5_ST3;
  DC_BOOL Impact_F2_ST3;
  DC_BOOL Impact_S1_ST3;
  DC_BOOL Impact_S2_ST3;
  DC_BOOL Impact_X_ST3;
} REC_ORC_Impact3_Pr5_ST3;

# define Rte_TypeDef_REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19
typedef struct
{
  DC_BOOL Impact_F1_ST3;
  DC_BOOL Impact_F3_ST3;
  DC_BOOL Impact_RO_type1_ST3;
  DC_BOOL Impact_RO_type2_ST3;
  c16_CRC_woSNA CRC_ORC_Impact3_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_ORC_Impact3_Pr5_ST3;
  DC_BOOL Impact_F2_ST3;
  DC_BOOL Impact_S1_ST3;
  DC_BOOL Impact_S2_ST3;
  DC_BOOL Impact_X_ST3;
} REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19;

# define Rte_TypeDef_REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58
typedef struct
{
  DC_BOOL Impact_X_ST3;
} REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58;

# define Rte_TypeDef_REC_PT4_PTCoor4_Pr5_ST3
typedef struct
{
  c16_CRC_woSNA CRC_PT4_PTCoor4_Pr5_ST3;
  c02_PT_Rdy_V2 PT4_PTCoor_PT_Rdy_ST3;
  c08_0_255_1_SNA_na SQC_PT4_PTCoor4_Pr5_ST3;
  c03_EngStartPN14_Stat PT4_PTCoor_EngStartPN14_Stat_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_SSA_EngSp_ST3;
  Rsrv01 Rsrv1_PT4_PTCoor_PT_Rdy_Pr5_ST3;
} REC_PT4_PTCoor4_Pr5_ST3;

# define Rte_TypeDef_REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby
typedef struct
{
  c03_EngStartPN14_Stat PT4_PTCoor_EngStartPN14_Stat_ST3;
} REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby;

# define Rte_TypeDef_REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh
typedef struct
{
  c02_PT_Rdy_V2 PT4_PTCoor_PT_Rdy_ST3;
} REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh;

# define Rte_TypeDef_REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw
typedef struct
{
  c02_PT_Rdy_V2 PT4_PTCoor_PT_Rdy_ST3;
  c03_EngStartPN14_Stat PT4_PTCoor_EngStartPN14_Stat_ST3;
} REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw;

# define Rte_TypeDef_REC_PT4_PTCoor9_Pr5_ST3
typedef struct
{
  c16_CRC_woSNA CRC_PT4_PTCoor9_Pr5_ST3;
  c08_perc_0_100_0k4 PT4_PTCoor_AccelPdlPosn_D_Raw_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_KickDnSw_Psd_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_SSA_StopWarn_ST3;
  c08_0_255_1_SNA_na SQC_PT4_PTCoor9_Pr5_ST3;
  c14_rpm_0_16382_1 PT4_PTCoor_EngRPM_ST3;
  c08_perc_0_100_0k5 PT4_PTCoor_ClutchPdlPosn_CPC_ST3;
  c08_km_p_h_30_250_1_NoRcmnd PT4_PTCoor_EcoRcmnd_VehHighSpd_ST3;
  c08_km_p_h_30_250_1_NoRcmnd PT4_PTCoor_EcoRcmnd_VehSpd_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_EmgPath_Enbl_ST3;
  c08_V_0_25k4_0k1 PT4_PTCoor_EmgPath_Volt_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_LHOM_PkLk_ST3;
  Rsrv27 Rsrv4_PT4_PTCoor9_Pr5_ST3;
  c03_Accel_Md_ST3 PT4_PTCoor_Accel_Md_ST3;
  c02_TxBurnOut_Stat PT4_PTCoor_TxBurnOut_Stat_ST3;
  c09_km_p_h_0_500_1 PT4_PTCoor_VehFixMaxSpd_ST3;
  c02_NDef_Off_On_ST3 PT4_PTCoor_ShftTcase_Enbl_ST3;
  c10_PT4_PTCoor_DAS_Hlth_Stat PT4_PTCoor_DAS_Health_Stat_ST3;
  c12_rpm_0_16376_4 PT4_PTCoor_TrsmCtrl_OutRPM_ST3;
  c03_DCDCBuckSuprtStat_ST3 PT4_PTCoor_VEPM_DCDC_BuckSuprt_Stat_ST3;
} REC_PT4_PTCoor9_Pr5_ST3;

# define Rte_TypeDef_REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u
typedef struct
{
  c03_Accel_Md_ST3 PT4_PTCoor_Accel_Md_ST3;
} REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u;

# define Rte_TypeDef_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3
typedef struct
{
  c16_CRC_woSNA CRC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3;
  c04_DrvPosn_ST3 PT4_PTCoor_DrvPosn_Stat_ST3;
  c04_DrvPosn_ST3 PT4_PTCoor_DrvPosn_Target_ST3;
  c04_Gr PT4_PTCoor_Gr_ST3;
  c08_0_255_1_SNA_na SQC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3;
  c08_TxDrvPosn PT4_PTCoor_DrvPosn_Disp_Rq_ST3;
  c04_Gr_Target PT4_PTCoor_Gr_Target_ST3;
  c02_Inact_Act_ST3 PT4_PTCoor_DrvPosn_N_Actv_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_D_Allowed_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_N_Allowed_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_P_Allowed_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_R_Allowed_ST3;
  c02_SSA_Standby_Stat PT4_PTCoor_SSA_Standby_Stat_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_ShW_MnTrctAxl_P_Allow_Drv_ST3;
  Rsrv02 Rsrv1_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3;
} REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3;

# define Rte_TypeDef_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh
typedef struct
{
  c04_DrvPosn_ST3 PT4_PTCoor_DrvPosn_Stat_ST3;
} REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh;

# define Rte_TypeDef_REC_PreSafeRecInputType
typedef struct
{
  u8TensioningStateType u8TensioningStateType;
  c02_Bckl_Sw_Stat u8BuckleStateType;
  c04_Presf_Lvl_V2 u8PresafeLevelType;
  DC_BOOL bImpactXType;
  c03_No_Lt_Rt_Both u8TensSuppType;
  DC_BOOL bRoEventType1;
  DC_BOOL bRoEventType2;
  c03_ISw_Stat u8IgnStat;
  c02_BeltHdOvr_Stat u8BeltHdOvStat;
} REC_PreSafeRecInputType;

# define Rte_TypeDef_REC_PresfAct_Adj_Pr5_ST3
typedef struct
{
  c13_PresfAct_Adj_Rq PresfAct_Adj_Rq_ST3;
  Rsrv08 Rsrv6_Presf_Adj_ST3;
  c04_Presf_Lvl_V2 Presf_Lvl_ST3;
  c02_Presf_Snd Presf_Snd_Rq_ST3;
  c02_Ndef_False_True_ST3 PresfAccelReset_NotExcd_ST3;
  c02_false_true_sna Presf_Enbl_ST3;
  c02_false_true_sna Presf_Fric_Fctr_Lo_ST3;
  c03_No_Lt_Rt_Both PresfAct_TensSupp_Rq_ST3;
  c16_CRC_woSNA CRC_PresfAct_Adj_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_PresfAct_Adj_Pr5_ST3;
  c04_Presf_Frct_ST3 Presf_FricCoeff_Estim_ST3;
} REC_PresfAct_Adj_Pr5_ST3;

# define Rte_TypeDef_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j
typedef struct
{
  c13_PresfAct_Adj_Rq PresfAct_Adj_Rq_ST3;
  Rsrv08 Rsrv6_Presf_Adj_ST3;
  c04_Presf_Lvl_V2 Presf_Lvl_ST3;
  c02_Presf_Snd Presf_Snd_Rq_ST3;
  c02_Ndef_False_True_ST3 PresfAccelReset_NotExcd_ST3;
  c02_false_true_sna Presf_Enbl_ST3;
  c02_false_true_sna Presf_Fric_Fctr_Lo_ST3;
  c03_No_Lt_Rt_Both PresfAct_TensSupp_Rq_ST3;
  c16_CRC_woSNA CRC_PresfAct_Adj_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_PresfAct_Adj_Pr5_ST3;
  c04_Presf_Frct_ST3 Presf_FricCoeff_Estim_ST3;
} REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j;

# define Rte_TypeDef_REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr
typedef struct
{
  c04_Presf_Lvl_V2 Presf_Lvl_ST3;
  c02_Ndef_False_True_ST3 PresfAccelReset_NotExcd_ST3;
} REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr;

# define Rte_TypeDef_REC_ROE_XX_ST3
typedef struct
{
  c08_ROE_0 ROE_0;
  c08_UInt_SNA_na ROE_1;
  c08_UInt_SNA_na ROE_2;
  c08_UInt_SNA_na ROE_3;
  c08_UInt_SNA_na ROE_4;
  c08_UInt_SNA_na ROE_5;
  c08_UInt_SNA_na ROE_6;
  c08_UInt_SNA_na ROE_7;
} REC_ROE_XX_ST3;

# define Rte_TypeDef_REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv
typedef struct
{
  c08_ROE_0 ROE_0;
  c08_UInt_SNA_na ROE_1;
  c08_UInt_SNA_na ROE_2;
  c08_UInt_SNA_na ROE_3;
  c08_UInt_SNA_na ROE_4;
  c08_UInt_SNA_na ROE_5;
  c08_UInt_SNA_na ROE_6;
  c08_UInt_SNA_na ROE_7;
} REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv;

# define Rte_TypeDef_REC_SBeltTens_SP_Lvl_Pr5_ST3
typedef struct
{
  c16_CRC_woSNA CRC_SBeltTens_SP_Lvl_Pr5_ST3;
  c06_RBTM_LVL_Rq RBTMFL_SP_Lvl_Rq_ST35;
  c06_RBTM_LVL_Rq RBTMFR_SP_Lvl_Rq_ST35;
  Rsrv04 Rsrv0_SBeltTens_SP_Lvl_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_SBeltTens_SP_Lvl_Pr5_ST3;
} REC_SBeltTens_SP_Lvl_Pr5_ST3;

# define Rte_TypeDef_REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt
typedef struct
{
  c16_CRC_woSNA CRC_SBeltTens_SP_Lvl_Pr5_ST3;
  c06_RBTM_LVL_Rq RBTMFL_SP_Lvl_Rq_ST35;
  c06_RBTM_LVL_Rq RBTMFR_SP_Lvl_Rq_ST35;
  Rsrv04 Rsrv0_SBeltTens_SP_Lvl_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_SBeltTens_SP_Lvl_Pr5_ST3;
} REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt;

# define Rte_TypeDef_REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4
typedef struct
{
  c08_km_p_h_0_254_1 VehSpd8_ST3;
  c16_CRC_woSNA CRC_VehSpd8_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_VehSpd8_Pr5_ST3;
} REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4;

# define Rte_TypeDef_ReleaseCyclesBSRAndPresafe_StorageType
typedef struct
{
  Dcm_Data12ByteType Soft;
  Dcm_Data12ByteType Hard1;
  Dcm_Data12ByteType Hard2;
  Dcm_Data12ByteType Hard3;
  Dcm_Data96ByteType Library;
} ReleaseCyclesBSRAndPresafe_StorageType;

# define Rte_TypeDef_RightsM_AuthNonceType
typedef struct
{
  Ssa_Data32ByteType data;
  boolean validated;
} RightsM_AuthNonceType;

# define Rte_TypeDef_RightsM_NonceType
typedef struct
{
  Ssa_Data32ByteType data;
  uint64 timestamp;
  boolean isValid;
} RightsM_NonceType;

# define Rte_TypeDef_RightsM_SecuritySettingsType
typedef struct
{
  Ssa_Data32ByteType testerPublicKey;
  RightsM_SerialNumberType testerSerialNumber;
  RightsM_IssuerType testerIssuer;
  RightsM_DiagnosticUserRoleType diagnosticUserRole;
  boolean restrictedAuthentication;
} RightsM_SecuritySettingsType;

# define Rte_TypeDef_SecOC_VerificationStatusType
typedef struct
{
  uint16 freshnessValueID;
  SecOC_VerificationResultType verificationStatus;
  uint16 secOCDataId;
} SecOC_VerificationStatusType;

# define Rte_TypeDef_Ssa_FailedMacVerifCounterEventType
typedef struct
{
  uint16 PduId;
  Ssa_ThresholdExceededType ThresholdExcceded;
} Ssa_FailedMacVerifCounterEventType;

# define Rte_TypeDef_Ssa_IgnitionStatusType
typedef struct
{
  Ssa_IgnitionStatus_Prim ISw_Stat_ST3;
} Ssa_IgnitionStatusType;

# define Rte_TypeDef_Ssa_LocalTickCountAndSyncStatusType
typedef struct
{
  uint64 LocalTickCount;
  Ssa_TickCountSyncStateType SyncStatus;
} Ssa_LocalTickCountAndSyncStatusType;

# define Rte_TypeDef_Ssa_OdometerRecordType
typedef struct
{
  c24_km_0_999999k9_0k1_Invld_SNA Odo_ST3;
} Ssa_OdometerRecordType;

# define Rte_TypeDef_StbM_EthTimeMasterMeasurementType
typedef struct
{
  uint16 sequenceId;
  StbM_PortIdType sourcePortId;
  StbM_VirtualLocalTimeType syncEgressTimestamp;
  StbM_TimeStampShortType preciseOriginTimestamp;
  sint64 correctionField;
} StbM_EthTimeMasterMeasurementType;

# define Rte_TypeDef_StbM_EthTimeSlaveMeasurementType
typedef struct
{
  uint16 sequenceId;
  StbM_PortIdType sourcePortId;
  StbM_VirtualLocalTimeType syncIngressTimestamp;
  StbM_TimeStampShortType preciseOriginTimestamp;
  sint64 correctionField;
  uint32 pDelay;
  StbM_VirtualLocalTimeType referenceLocalTimestamp;
  StbM_TimeStampShortType referenceGlobalTimestamp;
} StbM_EthTimeSlaveMeasurementType;

# define Rte_TypeDef_StbM_OffsetRecordTableBlockType
typedef struct
{
  uint32 GlbSeconds;
  uint32 GlbNanoSeconds;
  StbM_TimeBaseStatusType TimeBaseStatus;
} StbM_OffsetRecordTableBlockType;

# define Rte_TypeDef_StbM_PdelayInitiatorMeasurementType
typedef struct
{
  uint16 sequenceId;
  StbM_PortIdType requestPortId;
  StbM_PortIdType responsePortId;
  StbM_VirtualLocalTimeType requestOriginTimestamp;
  StbM_VirtualLocalTimeType responseReceiptTimestamp;
  StbM_TimeStampShortType requestReceiptTimestamp;
  StbM_TimeStampShortType responseOriginTimestamp;
  StbM_VirtualLocalTimeType referenceLocalTimestamp;
  StbM_TimeStampShortType referenceGlobalTimestamp;
  uint32 pdelay;
} StbM_PdelayInitiatorMeasurementType;

# define Rte_TypeDef_StbM_PdelayResponderMeasurementType
typedef struct
{
  uint16 sequenceId;
  StbM_PortIdType requestPortId;
  StbM_PortIdType responsePortId;
  StbM_VirtualLocalTimeType requestReceiptTimestamp;
  StbM_VirtualLocalTimeType responseOriginTimestamp;
  StbM_VirtualLocalTimeType referenceLocalTimestamp;
  StbM_TimeStampShortType referenceGlobalTimestamp;
} StbM_PdelayResponderMeasurementType;

# define Rte_TypeDef_StbM_SyncRecordTableBlockType
typedef struct
{
  uint32 GlbSeconds;
  uint32 GlbNanoSeconds;
  StbM_TimeBaseStatusType TimeBaseStatus;
  uint32 VirtualLocalTimeLow;
  sint16 RateDeviation;
  uint32 LocSeconds;
  uint32 LocNanoSeconds;
  uint32 PathDelay;
} StbM_SyncRecordTableBlockType;

# define Rte_TypeDef_StbM_TimeStampType
typedef struct
{
  StbM_TimeBaseStatusType timeBaseStatus;
  uint32 nanoseconds;
  uint32 seconds;
  uint16 secondsHi;
} StbM_TimeStampType;

# define Rte_TypeDef_TensioningCycleBSR_StorageType
typedef struct
{
  Dcm_Data12ByteType BSR1;
  Dcm_Data12ByteType BSR2;
  Dcm_Data12ByteType BSR3;
  Dcm_Data192ByteType Library;
  Dcm_Data1ByteType AfterBuckle;
  Dcm_Data1ByteType AfterMd;
  Dcm_Data1ByteType PwtDelay;
  Dcm_Data1ByteType BSR1AccelerationTimeout;
  Dcm_Data1ByteType AssociatedCounterBSR;
} TensioningCycleBSR_StorageType;

# define Rte_TypeDef_TimeM_RealTimeOffsetType
typedef struct
{
  uint64 tickCountOffset;
  TimeM_DateTimeType dateTimeReference;
} TimeM_RealTimeOffsetType;

# define Rte_TypeDef_VehicleEquipment_StorageType
typedef struct
{
  Dcm_Data1ByteType Equipment1;
  Dcm_Data1ByteType Equipment2;
  Dcm_Data1ByteType Equipment3;
  Dcm_Data1ByteType Equipment4;
  Dcm_Data1ByteType Equipment5;
  Dcm_Data1ByteType Equipment6;
  Dcm_Data1ByteType Reserved1;
  Dcm_Data1ByteType Reserved2;
  Dcm_Data2ByteType Uberspannungsabbruchschwelle;
  Dcm_Data2ByteType Uberspannungsbereichsschwelle;
  Dcm_Data2ByteType Unterspannungsbereichsschwelle;
  Dcm_Data2ByteType Unterspannungsabbruchschwelle;
} VehicleEquipment_StorageType;

# define Rte_TypeDef_ZZZ_VehicleEquipment_Development_StorageType
typedef struct
{
  Dcm_Data2ByteType Bitfield;
  Dcm_Data1ByteType Zykluszeit_Messtechnik;
} ZZZ_VehicleEquipment_Development_StorageType;

# define Rte_TypeDef_stAbsoluteSystemTimeType
typedef struct
{
  UInt32 u32SystemTimeInSec;
  UInt8 u8SystemTimeOffset;
} stAbsoluteSystemTimeType;

# define Rte_TypeDef_Ssa_VerifyResultPtr
typedef Crypto_VerifyResultType * Ssa_VerifyResultPtr;

# define Rte_TypeDef_CertP_ParsedCertStructureType
typedef struct
{
  CertP_VerificationResultType verificationResult;
  uint16 parsedCertLength;
  CertP_BerElementType signedCertData;
  uint8 version;
  CertP_BerElementType serialNumber;
  CertP_BerElementType certSignatureAlgOID;
  CertP_BerElementType issuer;
  CertP_TimeType validNotBefore;
  CertP_TimeType validNotAfter;
  CertP_BerElementType subject;
  CertP_BerElementType publicKey;
  CertP_BerElementType subjectKeyIdentifier;
  CertP_BerElementType authorityKeyIdentifier;
  uint16 keyUsage;
  uint8 basicConstraints;
  CertP_PkiRoleType pkiRole;
  RightsM_DiagnosticUserRoleType userRole;
  CertP_BerElementType targetECU;
  CertP_BerElementType targetVIN;
  CertP_BerElementType nonce;
  uint8 prodQualifier;
  CertP_BerElementType uniqueEcuId;
  CertP_BerElementType service;
  CertP_BerElementType holderIssuer;
  CertP_BerElementType holderSerialNumber;
  CertP_BerElementType signatureAlgorithmOID;
  CertP_BerElementType signature;
  uint8 specialECU;
  CertP_BerElementType targetSubjectKeyIdentifier;
} CertP_ParsedCertStructureType;

# define Rte_TypeDef_RightsM_DiagChannelDataType
typedef struct
{
  uint8 currentDiagnosticChannel;
  RightsM_AuthenticationStateType authentication_State;
  uint8 authentication_ExpectedTask;
  RightsM_ChallengeEcuType authentication_ChallengeEcu;
  uint16 authenticationTimeoutTimer;
  boolean defaultSessionRequestFlag;
  RightsM_SecuritySettingsType securitySettings;
} RightsM_DiagChannelDataType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_NvM_ASR42_DstPtrType
typedef void * NvM_ASR42_DstPtrType;

#  define Rte_TypeDef_NvM_ASR42_SrcPtrType
typedef const void * NvM_ASR42_SrcPtrType;

#  define Rte_TypeDef_NvM_DstPtrType
typedef void * NvM_DstPtrType;

#  define Rte_TypeDef_NvM_SrcPtrType
typedef const void * NvM_SrcPtrType;

#  define Rte_TypeDef_Csm_EncryptDataType_AES128Encrypt
typedef uint8 Csm_EncryptDataType_AES128Encrypt[64];

#  define Rte_TypeDef_Csm_EncryptResultType_AES128Encrypt
typedef uint8 Csm_EncryptResultType_AES128Encrypt[80];

#  define Rte_TypeDef_Csm_KeyDataType_KeyM_SigVerifyKey_TrustModelEcu
typedef uint8 Csm_KeyDataType_KeyM_SigVerifyKey_TrustModelEcu[32];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_EcuCert
typedef uint8 Csm_KeyDataType_Ssa_EcuCert[600];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_PrivateEcuKey
typedef uint8 Csm_KeyDataType_Ssa_PrivateEcuKey[32];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_SharedSecret
typedef uint8 Csm_KeyDataType_Ssa_SharedSecret[32];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelEcuCsrPrivateKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelEcuCsrPrivateKey[32];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelEcuLivePrivateKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelEcuLivePrivateKey[32];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelEcuStagingPrivateKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelEcuStagingPrivateKey[32];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelEcuStagingPublicKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelEcuStagingPublicKey[32];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelPrivateEcuKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelPrivateEcuKey[32];

#  define Rte_TypeDef_Csm_KeyDataType_Ssa_TrustModelPrivateEcuUniqueKey
typedef uint8 Csm_KeyDataType_Ssa_TrustModelPrivateEcuUniqueKey[32];

#  define Rte_TypeDef_Csm_MacGenerateResultType_MacGenAesCmacTrunc
typedef uint8 Csm_MacGenerateResultType_MacGenAesCmacTrunc[8];

#  define Rte_TypeDef_Csm_PublicValueDataType_KeyM_SigVerifyKey_TrustModelEcu
typedef uint8 Csm_PublicValueDataType_KeyM_SigVerifyKey_TrustModelEcu[32];

#  define Rte_TypeDef_Csm_PublicValueDataType_Ssa_TrustModelEcuLivePublicKey
typedef uint8 Csm_PublicValueDataType_Ssa_TrustModelEcuLivePublicKey[32];

#  define Rte_TypeDef_Csm_PublicValueDataType_Ssa_TrustModelEcuStagingPrivateKey
typedef uint8 Csm_PublicValueDataType_Ssa_TrustModelEcuStagingPrivateKey[32];

#  define Rte_TypeDef_Csm_PublicValueDataType_Ssa_TrustModelPrivateEcuKey
typedef uint8 Csm_PublicValueDataType_Ssa_TrustModelPrivateEcuKey[32];

#  define Rte_TypeDef_Csm_PublicValueDataType_Ssa_TrustModelPrivateEcuUniqueKey
typedef uint8 Csm_PublicValueDataType_Ssa_TrustModelPrivateEcuUniqueKey[32];

#  define Rte_TypeDef_Csm_PublicValueDataType_Ssa_TrustModelTempPublicKey
typedef uint8 Csm_PublicValueDataType_Ssa_TrustModelTempPublicKey[32];

#  define Rte_TypeDef_Csm_SeedDataTypeKeyM_SigVerifyKey_TrustModelEcu
typedef uint8 Csm_SeedDataTypeKeyM_SigVerifyKey_TrustModelEcu[32];

#  define Rte_TypeDef_Csm_SeedDataTypeSsa_TrustModelEcuLivePublicKey
typedef uint8 Csm_SeedDataTypeSsa_TrustModelEcuLivePublicKey[32];

#  define Rte_TypeDef_Csm_SeedDataTypeSsa_TrustModelEcuStagingPrivateKey
typedef uint8 Csm_SeedDataTypeSsa_TrustModelEcuStagingPrivateKey[32];

#  define Rte_TypeDef_Csm_SeedDataTypeSsa_TrustModelPrivateEcuKey
typedef uint8 Csm_SeedDataTypeSsa_TrustModelPrivateEcuKey[32];

#  define Rte_TypeDef_Csm_SeedDataTypeSsa_TrustModelPrivateEcuUniqueKey
typedef uint8 Csm_SeedDataTypeSsa_TrustModelPrivateEcuUniqueKey[32];

#  define Rte_TypeDef_Csm_SeedDataTypeSsa_TrustModelTempPublicKey
typedef uint8 Csm_SeedDataTypeSsa_TrustModelTempPublicKey[32];

#  define Rte_TypeDef_Csm_SeedDataType_Ssa_RandomSeed
typedef uint8 Csm_SeedDataType_Ssa_RandomSeed[209];

#  define Rte_TypeDef_Csm_SignatureGenerateDataType_SigGenEd25519ph
typedef uint8 Csm_SignatureGenerateDataType_SigGenEd25519ph[8192];

#  define Rte_TypeDef_Csm_SignatureGenerateResultType_SigGenEd25519ph
typedef uint8 Csm_SignatureGenerateResultType_SigGenEd25519ph[64];

#  define Rte_TypeDef_Csm_SignatureVerifyCompareType_SigVerifyEd25519
typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519[64];

#  define Rte_TypeDef_Csm_SignatureVerifyCompareType_SigVerifyEd25519ph
typedef uint8 Csm_SignatureVerifyCompareType_SigVerifyEd25519ph[64];

#  define Rte_TypeDef_Csm_SignatureVerifyDataType_SigVerifyEd25519
typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519[8192];

#  define Rte_TypeDef_Csm_SignatureVerifyDataType_SigVerifyEd25519ph
typedef uint8 Csm_SignatureVerifyDataType_SigVerifyEd25519ph[8192];

#  define Rte_TypeDef_Dcm_Data255ByteType
typedef uint8 Dcm_Data255ByteType[255];

#  define Rte_TypeDef_Dcm_Data512ByteType
typedef uint8 Dcm_Data512ByteType[512];

#  define Rte_TypeDef_Dcm_DataDID_F18C_BeltAssemblySerialNumberData_ArrayType
typedef uint8 Dcm_DataDID_F18C_BeltAssemblySerialNumberData_ArrayType[20];

#  define Rte_TypeDef_Dcm_DataDID_FD03_AEETraceabilityNumberData_ArrayType
typedef uint8 Dcm_DataDID_FD03_AEETraceabilityNumberData_ArrayType[12];

#  define Rte_TypeDef_Dcm_DataDID_FD8B_BeltAssemblyManufDateData_ArrayType
typedef uint8 Dcm_DataDID_FD8B_BeltAssemblyManufDateData_ArrayType[3];

#  define Rte_TypeDef_Dcm_DataDID_FD8C_BeltAssemblySerialNumberData_ArrayType
typedef uint8 Dcm_DataDID_FD8C_BeltAssemblySerialNumberData_ArrayType[10];

#  define Rte_TypeDef_Dem_ASR42_MaxDataValueType
typedef uint8 Dem_ASR42_MaxDataValueType[1];

#  define Rte_TypeDef_Dem_ASR42_MaxDataValueType_1
typedef uint8 Dem_ASR42_MaxDataValueType_1[1];

#  define Rte_TypeDef_Dem_ASR42_MaxDataValueType_2
typedef uint8 Dem_ASR42_MaxDataValueType_2[1];

#  define Rte_TypeDef_Dem_ASR42_MaxDataValueType_3
typedef uint8 Dem_ASR42_MaxDataValueType_3[1];

#  define Rte_TypeDef_Dem_ASR42_MaxDataValueType_4
typedef uint8 Dem_ASR42_MaxDataValueType_4[1];

#  define Rte_TypeDef_Dem_MaxDataValueTypeAlv
typedef uint8 Dem_MaxDataValueTypeAlv[5];

#  define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_pkiRole[1];

#  define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_pkiRole[1];

#  define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_pkiRole[1];

#  define Rte_TypeDef_KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId
typedef uint8 KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_authKeyId[1];

#  define Rte_TypeDef_Ssa_DataToBeSignedType
typedef uint8 Ssa_DataToBeSignedType[4092];

#  define Rte_TypeDef_SwcDiag_ExtTesterDataArrayType
typedef uint8 SwcDiag_ExtTesterDataArrayType[1];

#  define Rte_TypeDef_SwcDiag_OdometerDataArrayType
typedef uint8 SwcDiag_OdometerDataArrayType[2];

#  define Rte_TypeDef_SwcDiag_SecurityEventDataArrayType
typedef uint8 SwcDiag_SecurityEventDataArrayType[7];

#  define Rte_TypeDef_SwcDiag_TimestampDataArrayType
typedef uint8 SwcDiag_TimestampDataArrayType[5];

#  define Rte_TypeDef_COM_C04_Sig121
typedef uint8 COM_C04_Sig121;

#  define Rte_TypeDef_DAI_boolean
typedef boolean DAI_boolean;

#  define Rte_TypeDef_DC_U16
typedef uint16 DC_U16;

#  define Rte_TypeDef_DC_U8
typedef uint8 DC_U8;

#  define Rte_TypeDef_DT_SInt32
typedef sint32 DT_SInt32;

#  define Rte_TypeDef_DT_Uint16
typedef uint16 DT_Uint16;

#  define Rte_TypeDef_DT_Uint32
typedef uint32 DT_Uint32;

#  define Rte_TypeDef_Dcm_ASR42_ProtocolType
typedef uint8 Dcm_ASR42_ProtocolType;

#  define Rte_TypeDef_Dcm_ASR42_SecLevelType
typedef uint8 Dcm_ASR42_SecLevelType;

#  define Rte_TypeDef_Dcm_ASR42_SesCtrlType
typedef uint8 Dcm_ASR42_SesCtrlType;

#  define Rte_TypeDef_Dem_ASR42_DTCFormatType
typedef uint8 Dem_ASR42_DTCFormatType;

#  define Rte_TypeDef_Dem_ASR42_DTCFormatType_1
typedef uint8 Dem_ASR42_DTCFormatType_1;

#  define Rte_TypeDef_Dem_ASR42_DTCFormatType_2
typedef uint8 Dem_ASR42_DTCFormatType_2;

#  define Rte_TypeDef_Dem_ASR42_DTCFormatType_3
typedef uint8 Dem_ASR42_DTCFormatType_3;

#  define Rte_TypeDef_Dem_ASR42_DTCFormatType_4
typedef uint8 Dem_ASR42_DTCFormatType_4;

#  define Rte_TypeDef_Dem_ASR42_DebounceResetStatusType
typedef uint8 Dem_ASR42_DebounceResetStatusType;

#  define Rte_TypeDef_Dem_ASR42_EventIdType
typedef uint16 Dem_ASR42_EventIdType;

#  define Rte_TypeDef_Dem_ASR42_EventStatusExtendedType_1
typedef uint8 Dem_ASR42_EventStatusExtendedType_1;

#  define Rte_TypeDef_Dem_ASR42_EventStatusExtendedType_2
typedef uint8 Dem_ASR42_EventStatusExtendedType_2;

#  define Rte_TypeDef_Dem_ASR42_EventStatusExtendedType_3
typedef uint8 Dem_ASR42_EventStatusExtendedType_3;

#  define Rte_TypeDef_Dem_ASR42_EventStatusExtendedType_4
typedef uint8 Dem_ASR42_EventStatusExtendedType_4;

#  define Rte_TypeDef_Dem_ASR42_EventStatusType
typedef uint8 Dem_ASR42_EventStatusType;

#  define Rte_TypeDef_Dem_DTCOriginTypeALV
typedef uint8 Dem_DTCOriginTypeALV;

#  define Rte_TypeDef_Dem_DebouncingStateType_1
typedef uint8 Dem_DebouncingStateType_1;

#  define Rte_TypeDef_Dem_DebouncingStateType_2
typedef uint8 Dem_DebouncingStateType_2;

#  define Rte_TypeDef_Dem_DebouncingStateType_3
typedef uint8 Dem_DebouncingStateType_3;

#  define Rte_TypeDef_Dem_DebouncingStateType_4
typedef uint8 Dem_DebouncingStateType_4;

#  define Rte_TypeDef_Dem_EventIdType9999
typedef uint16 Dem_EventIdType9999;

#  define Rte_TypeDef_Dem_EventIdType_1
typedef uint16 Dem_EventIdType_1;

#  define Rte_TypeDef_Dem_EventIdType_2
typedef uint16 Dem_EventIdType_2;

#  define Rte_TypeDef_Dem_EventIdType_3
typedef uint16 Dem_EventIdType_3;

#  define Rte_TypeDef_Dem_EventIdType_4
typedef uint16 Dem_EventIdType_4;

#  define Rte_TypeDef_Dem_EventIdType_5
typedef uint16 Dem_EventIdType_5;

#  define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;

#  define Rte_TypeDef_Dem_UdsStatusByteType1
typedef uint8 Dem_UdsStatusByteType1;

#  define Rte_TypeDef_Dem_UdsStatusByteType_1
typedef uint8 Dem_UdsStatusByteType_1;

#  define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

#  define Rte_TypeDef_Ssa_BswM_ComModeType
typedef uint8 Ssa_BswM_ComModeType;

#  define Rte_TypeDef_Ssa_BusOdometerTyp
typedef uint32 Ssa_BusOdometerTyp;

#  define Rte_TypeDef_SwcDiag_AvailabilityCategoryType
typedef uint8 SwcDiag_AvailabilityCategoryType;

#  define Rte_TypeDef_SwcDiag_BlockNumberType
typedef uint8 SwcDiag_BlockNumberType;

#  define Rte_TypeDef_SwcDiag_BusOdometerType
typedef uint32 SwcDiag_BusOdometerType;

#  define Rte_TypeDef_SwcDiag_CnsmblObslscncType
typedef uint16 SwcDiag_CnsmblObslscncType;

#  define Rte_TypeDef_SwcDiag_ExtTesterStatusType
typedef uint8 SwcDiag_ExtTesterStatusType;

#  define Rte_TypeDef_SwcDiag_FunctionNumberType
typedef uint8 SwcDiag_FunctionNumberType;

#  define Rte_TypeDef_SwcDiag_IgnitionStatusType
typedef uint8 SwcDiag_IgnitionStatusType;

#  define Rte_TypeDef_SwcDiag_ProductionModeType
typedef uint8 SwcDiag_ProductionModeType;

#  define Rte_TypeDef_SwcDiag_RoELitePDUKindType
typedef uint8 SwcDiag_RoELitePDUKindType;

#  define Rte_TypeDef_SwcDiag_TransportationModeType
typedef uint8 SwcDiag_TransportationModeType;

#  define Rte_TypeDef_SwcDiag_VehicleStartupType
typedef uint8 SwcDiag_VehicleStartupType;

#  define Rte_TypeDef_SwcDiag_VoltageType
typedef uint16 SwcDiag_VoltageType;

#  define Rte_TypeDef_c01_bit_dummy
typedef boolean c01_bit_dummy;

#  define Rte_TypeDef_c02_NotActv_Actv_SNA
typedef uint8 c02_NotActv_Actv_SNA;

#  define Rte_TypeDef_c02_WakeUp_Stat
typedef uint8 c02_WakeUp_Stat;

#  define Rte_TypeDef_c03_Off_On_Chng_Idle_ST3
typedef uint8 c03_Off_On_Chng_Idle_ST3;

#  define Rte_TypeDef_c07_na_0_to_127_1
typedef uint8 c07_na_0_to_127_1;

#  define Rte_TypeDef_c08_0_254_1
typedef uint8 c08_0_254_1;

#  define Rte_TypeDef_c08_Platform_Stat
typedef uint8 c08_Platform_Stat;

#  define Rte_TypeDef_c08_WU_REASON_ECUx
typedef uint8 c08_WU_REASON_ECUx;

#  define Rte_TypeDef_c08_na_0_to_255_1
typedef uint8 c08_na_0_to_255_1;

#  define Rte_TypeDef_c08_perc_0_254_1
typedef uint8 c08_perc_0_254_1;

#  define Rte_TypeDef_c09_na_0_to_511_1
typedef uint16 c09_na_0_to_511_1;

#  define Rte_TypeDef_c10_WU_REASON_ECUx
typedef uint16 c10_WU_REASON_ECUx;

#  define Rte_TypeDef_c10_na_0_to_1023_1
typedef uint16 c10_na_0_to_1023_1;

#  define Rte_TypeDef_c11_0_2046_1
typedef uint16 c11_0_2046_1;

#  define Rte_TypeDef_c12_na_0_to_4095_1
typedef uint16 c12_na_0_to_4095_1;

#  define Rte_TypeDef_c16_0_65533_1
typedef uint16 c16_0_65533_1;

#  define Rte_TypeDef_c16_0_65535_1_SNA_na
typedef uint16 c16_0_65535_1_SNA_na;

#  define Rte_TypeDef_c16_CRC_woSNA_1
typedef uint16 c16_CRC_woSNA_1;

#  define Rte_TypeDef_c24_na_0_to_16777215_1
typedef uint32 c24_na_0_to_16777215_1;

#  define Rte_TypeDef_dtRef_
typedef uint8 dtRef_;

#  define Rte_TypeDef_sint16_s16
typedef sint16 sint16_s16;

#  define Rte_TypeDef_u32ChecksumType
typedef uint32 u32ChecksumType;

#  define Rte_TypeDef_u8CAN_ByteType
typedef uint8 u8CAN_ByteType;

#  define Rte_TypeDef_uint8_u8
typedef uint8 uint8_u8;

#  define Rte_TypeDef_ARR_08_UInt_noSNA_49
typedef c08_UInt_SNA_na ARR_08_UInt_noSNA_49[49];

#  define Rte_TypeDef_DC_U16_ARRAY_128
typedef DC_U16 DC_U16_ARRAY_128[128];

#  define Rte_TypeDef_DT_Ssa_Data7ByteType
typedef uint8_u8 DT_Ssa_Data7ByteType[7];

#  define Rte_TypeDef_DT_U8N_3k
typedef uint8_u8 DT_U8N_3k[3000];

#  define Rte_TypeDef_Rte_DT_ARR_Dyn_08_UInt_noSNA_55_1
typedef c08_UInt_SNA_na Rte_DT_ARR_Dyn_08_UInt_noSNA_55_1[55];

#  define Rte_TypeDef_Rte_DT_ARR_Dyn_08_UInt_noSNA_800_1
typedef c08_UInt_SNA_na Rte_DT_ARR_Dyn_08_UInt_noSNA_800_1[800];

#  define Rte_TypeDef_ARR_Dyn_08_UInt_noSNA_55
typedef struct
{
  uint8 SIZE;
  Rte_DT_ARR_Dyn_08_UInt_noSNA_55_1 ARRAY_ELEMENT;
} ARR_Dyn_08_UInt_noSNA_55;

#  define Rte_TypeDef_ARR_Dyn_08_UInt_noSNA_800
typedef struct
{
  uint16 SIZE;
  Rte_DT_ARR_Dyn_08_UInt_noSNA_800_1 ARRAY_ELEMENT;
} ARR_Dyn_08_UInt_noSNA_800;

#  define Rte_TypeDef_REC_COM_C04_SGR01_P05
typedef struct
{
  DT_Uint32 COM_C04_Sig004;
  c16_CRC_woSNA_1 CRC_COM_C04_SGR01_P05;
  c08_0_255_1_SNA_na SQC_COM_C04_SGR01_P05;
} REC_COM_C04_SGR01_P05;

#  define Rte_TypeDef_REC_COM_C04_SGR01_P05_a8oh4dpz9at39a7d7s3b6v4b3
typedef struct
{
  DT_Uint32 COM_C04_Sig004;
  c16_CRC_woSNA_1 CRC_COM_C04_SGR01_P05;
  c08_0_255_1_SNA_na SQC_COM_C04_SGR01_P05;
} REC_COM_C04_SGR01_P05_a8oh4dpz9at39a7d7s3b6v4b3;

#  define Rte_TypeDef_REC_COM_C04_Sig110
typedef struct
{
  c02_NotActv_Actv_SNA E_COM_C04_Sig110_0;
  c03_Off_On_Chng_Idle_ST3 E_COM_C04_Sig110_1;
} REC_COM_C04_Sig110;

#  define Rte_TypeDef_REC_COM_C04_Sig110_71njeubj9ico1p8v4pmslfcno
typedef struct
{
  c02_NotActv_Actv_SNA E_COM_C04_Sig110_0;
  c03_Off_On_Chng_Idle_ST3 E_COM_C04_Sig110_1;
} REC_COM_C04_Sig110_71njeubj9ico1p8v4pmslfcno;

#  define Rte_TypeDef_REC_COM_C04_Sig111
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig111_0;
  c10_to_1022_1 E_COM_C04_Sig111_1;
  c11_0_2046_1 E_COM_C04_Sig111_3;
  c16_0_65533_1 E_COM_C04_Sig111_2;
} REC_COM_C04_Sig111;

#  define Rte_TypeDef_REC_COM_C04_Sig111_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig111_0;
  c10_to_1022_1 E_COM_C04_Sig111_1;
  c11_0_2046_1 E_COM_C04_Sig111_3;
  c16_0_65533_1 E_COM_C04_Sig111_2;
} REC_COM_C04_Sig111_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_COM_C04_Sig112
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig112_0;
  c10_to_1022_1 E_COM_C04_Sig112_1;
  c11_0_2046_1 E_COM_C04_Sig112_2;
  c16_0_65533_1 E_COM_C04_Sig112_3;
} REC_COM_C04_Sig112;

#  define Rte_TypeDef_REC_COM_C04_Sig112_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig112_0;
  c10_to_1022_1 E_COM_C04_Sig112_1;
  c11_0_2046_1 E_COM_C04_Sig112_2;
  c16_0_65533_1 E_COM_C04_Sig112_3;
} REC_COM_C04_Sig112_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_COM_C04_Sig113
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig113_0;
  c10_to_1022_1 E_COM_C04_Sig113_1;
  c11_0_2046_1 E_COM_C04_Sig113_2;
  c16_0_65533_1 E_COM_C04_Sig113_3;
} REC_COM_C04_Sig113;

#  define Rte_TypeDef_REC_COM_C04_Sig113_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig113_0;
  c10_to_1022_1 E_COM_C04_Sig113_1;
  c11_0_2046_1 E_COM_C04_Sig113_2;
  c16_0_65533_1 E_COM_C04_Sig113_3;
} REC_COM_C04_Sig113_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_COM_C04_Sig115
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig115_0;
  c10_to_1022_1 E_COM_C04_Sig115_1;
  c11_0_2046_1 E_COM_C04_Sig115_2;
  c16_0_65533_1 E_COM_C04_Sig115_3;
} REC_COM_C04_Sig115;

#  define Rte_TypeDef_REC_COM_C04_Sig115_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig115_0;
  c10_to_1022_1 E_COM_C04_Sig115_1;
  c11_0_2046_1 E_COM_C04_Sig115_2;
  c16_0_65533_1 E_COM_C04_Sig115_3;
} REC_COM_C04_Sig115_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_COM_C04_Sig117
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig117_0;
  c10_to_1022_1 E_COM_C04_Sig117_1;
  c11_0_2046_1 E_COM_C04_Sig117_2;
  c16_0_65533_1 E_COM_C04_Sig117_3;
} REC_COM_C04_Sig117;

#  define Rte_TypeDef_REC_COM_C04_Sig117_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig117_0;
  c10_to_1022_1 E_COM_C04_Sig117_1;
  c11_0_2046_1 E_COM_C04_Sig117_2;
  c16_0_65533_1 E_COM_C04_Sig117_3;
} REC_COM_C04_Sig117_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_COM_C04_Sig118
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig118_0;
  c10_to_1022_1 E_COM_C04_Sig118_1;
  c11_0_2046_1 E_COM_C04_Sig118_2;
  c16_0_65533_1 E_COM_C04_Sig118_3;
} REC_COM_C04_Sig118;

#  define Rte_TypeDef_REC_COM_C04_Sig118_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig118_0;
  c10_to_1022_1 E_COM_C04_Sig118_1;
  c11_0_2046_1 E_COM_C04_Sig118_2;
  c16_0_65533_1 E_COM_C04_Sig118_3;
} REC_COM_C04_Sig118_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_COM_C04_Sig119
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig119_0;
  c10_to_1022_1 E_COM_C04_Sig119_1;
  c11_0_2046_1 E_COM_C04_Sig119_2;
  c16_0_65533_1 E_COM_C04_Sig119_3;
} REC_COM_C04_Sig119;

#  define Rte_TypeDef_REC_COM_C04_Sig119_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig119_0;
  c10_to_1022_1 E_COM_C04_Sig119_1;
  c11_0_2046_1 E_COM_C04_Sig119_2;
  c16_0_65533_1 E_COM_C04_Sig119_3;
} REC_COM_C04_Sig119_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_COM_C04_Sig120
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig120_0;
  c10_to_1022_1 E_COM_C04_Sig120_1;
  c11_0_2046_1 E_COM_C04_Sig120_2;
  c16_0_65533_1 E_COM_C04_Sig120_3;
} REC_COM_C04_Sig120;

#  define Rte_TypeDef_REC_COM_C04_Sig120_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig120_0;
  c10_to_1022_1 E_COM_C04_Sig120_1;
  c11_0_2046_1 E_COM_C04_Sig120_2;
  c16_0_65533_1 E_COM_C04_Sig120_3;
} REC_COM_C04_Sig120_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_COM_C0X_Sig110
typedef struct
{
  c02_NotActv_Actv_SNA E_COM_C04_Sig110_0;
  c03_Off_On_Chng_Idle_ST3 E_COM_C04_Sig110_1;
} REC_COM_C0X_Sig110;

#  define Rte_TypeDef_REC_COM_C0X_Sig110_71njeubj9ico1p8v4pmslfcno
typedef struct
{
  c02_NotActv_Actv_SNA E_COM_C04_Sig110_0;
  c03_Off_On_Chng_Idle_ST3 E_COM_C04_Sig110_1;
} REC_COM_C0X_Sig110_71njeubj9ico1p8v4pmslfcno;

#  define Rte_TypeDef_REC_E_COM_C04_Sig114_0
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig114_0;
  c10_to_1022_1 E_COM_C04_Sig114_1;
  c11_0_2046_1 E_COM_C04_Sig114_3;
  c16_0_65533_1 E_COM_C04_Sig114_2;
} REC_E_COM_C04_Sig114_0;

#  define Rte_TypeDef_REC_E_COM_C04_Sig114_0_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig114_0;
  c10_to_1022_1 E_COM_C04_Sig114_1;
  c11_0_2046_1 E_COM_C04_Sig114_3;
  c16_0_65533_1 E_COM_C04_Sig114_2;
} REC_E_COM_C04_Sig114_0_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_Meas_Eth_ECU4_Base_Layer_Heartbeat
typedef struct
{
  c08_0_254_1 Sequence_Counter;
  c08_0_254_1 Link_Drop_Counter;
  c16_0_65535_1_SNA_na Rx_Status;
  c16_0_65535_1_SNA_na Rx_Error_Counter;
  c16_0_65535_1_SNA_na CRC_Error_Counter;
  c16_0_65535_1_SNA_na Frame_Counter;
  c08_0_254_1 Temperature;
  c16_0_65535_1_SNA_na Port_Activation_Status;
  c16_0_65535_1_SNA_na PMA_PMD_Status;
  ARR_08_UInt_noSNA_49 Reserved;
} REC_Meas_Eth_ECU4_Base_Layer_Heartbeat;

#  define Rte_TypeDef_REC_PT4_PTCoor4_Pr5_ST3_a1o7mhv0xy8ny0vccjf09ttgc
typedef struct
{
  c16_CRC_woSNA CRC_PT4_PTCoor4_Pr5_ST3;
  c02_PT_Rdy_V2 PT4_PTCoor_PT_Rdy_ST3;
  c08_0_255_1_SNA_na SQC_PT4_PTCoor4_Pr5_ST3;
  c03_EngStartPN14_Stat PT4_PTCoor_EngStartPN14_Stat_ST3;
  c02_Ndef_False_True_ST3 PT4_PTCoor_SSA_EngSp_ST3;
  Rsrv01 Rsrv1_PT4_PTCoor_PT_Rdy_Pr5_ST3;
} REC_PT4_PTCoor4_Pr5_ST3_a1o7mhv0xy8ny0vccjf09ttgc;

#  define Rte_TypeDef_REC_REC_COM_C04_Sig116
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig116_0;
  c10_to_1022_1 E_COM_C04_Sig116_1;
  c11_0_2046_1 E_COM_C04_Sig116_2;
  c16_0_65533_1 E_COM_C04_Sig116_3;
} REC_REC_COM_C04_Sig116;

#  define Rte_TypeDef_REC_REC_COM_C04_Sig116_euk2owpx15avykqntci714wbp
typedef struct
{
  c07_per_0to100_1_SNA E_COM_C04_Sig116_0;
  c10_to_1022_1 E_COM_C04_Sig116_1;
  c11_0_2046_1 E_COM_C04_Sig116_2;
  c16_0_65533_1 E_COM_C04_Sig116_3;
} REC_REC_COM_C04_Sig116_euk2owpx15avykqntci714wbp;

#  define Rte_TypeDef_REC_VehSpd8_Pr5_ST3
typedef struct
{
  c08_km_p_h_0_254_1 VehSpd8_ST3;
  c16_CRC_woSNA CRC_VehSpd8_Pr5_ST3;
  c08_0_255_1_SNA_na SQC_VehSpd8_Pr5_ST3;
} REC_VehSpd8_Pr5_ST3;

#  define Rte_TypeDef_SwcDiag_BusIgnitionStatusRecordType
typedef struct
{
  SwcDiag_IgnitionStatusType ISw_Stat_ST3;
} SwcDiag_BusIgnitionStatusRecordType;

#  define Rte_TypeDef_SwcDiag_OdometerRecordType
typedef struct
{
  SwcDiag_BusOdometerType Odo_ST3;
} SwcDiag_OdometerRecordType;

#  define Rte_TypeDef_SwcDiag_RoERecordType
typedef struct
{
  SwcDiag_RoELitePDUKindType ROE_0;
  uint8 ROE_1;
  uint8 ROE_2;
  uint8 ROE_3;
  uint8 ROE_4;
  uint8 ROE_5;
  uint8 ROE_6;
  uint8 ROE;
  uint8 ROE_7;
} SwcDiag_RoERecordType;

#  define Rte_TypeDef_SwcDiag_VehicleStartupRecordType
typedef struct
{
  SwcDiag_VehicleStartupType PT4_PTCoor_EngStartPN14_Stat_ST3;
} SwcDiag_VehicleStartupRecordType;

#  define Rte_TypeDef_Csm_VerifyResultPtr
typedef Csm_VerifyResultType * Csm_VerifyResultPtr;

#  define Rte_TypeDef_REC_ARR_16_Meas_Eth_ECU_4_Heartbeat
typedef REC_Meas_Eth_ECU4_Base_Layer_Heartbeat REC_ARR_16_Meas_Eth_ECU_4_Heartbeat[16];

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(ARR_08_UInt_noSNA_7, RTE_CONST) Rte_XDIS_6146w3b2vgdunnu49c413rpbf_ARR_08_UInt_noSNA_7;

extern CONST(Coding_VINDataType, RTE_CONST) Rte_Ssa_Init_VIN_Coding_VINDataType;

extern CONST(KeyM_SharedSecretType, RTE_CONST) Rte_Ssa_Init_Zero_32Byte_KeyM_SharedSecretType;

extern CONST(RightsM_AuthenticationBroadcastType, RTE_CONST) Rte_Ssa_Init_Zero_20Byte_RightsM_AuthenticationBroadcastType;

extern CONST(Ssa_Data12ByteType, RTE_CONST) Rte_Ssa_Init_Zero_12Byte_Ssa_Data12ByteType;

extern CONST(Ssa_Data5ByteType, RTE_CONST) Rte_Ssa_Init_Zero_5Byte_Ssa_Data5ByteType;

extern CONST(Ssa_Data6ByteType, RTE_CONST) Rte_Ssa_Init_Zero_6Byte_Ssa_Data6ByteType;

extern CONST(Ssa_Data7ByteType, RTE_CONST) Rte_Ssa_Init_Zero_7Byte_Ssa_Data7ByteType;

extern CONST(Ssa_Data8ByteType, RTE_CONST) Rte_Ssa_Init_ComSignal_8Byte_Ssa_Data8ByteType;

extern CONST(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, RTE_CONST) Rte_XDIS_38xd6mxe7w4h211xfx307v7jd_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx;

extern CONST(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, RTE_CONST) Rte_XDIS_by5k2ulzqy4hav7734lki195k_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt;

extern CONST(REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, RTE_CONST) Rte_XDIS_5tgkwvedu4465t8unm4y2yblo_REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx;

extern CONST(REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_6b75pabydagdo3iwsn1mn0uh1_REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh;

extern CONST(REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86, RTE_CONST) Rte_XDIS_2akyi0yafm6v4b7rnlmtzqky2_REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86;

extern CONST(REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby, RTE_CONST) Rte_XDIS_69fckmg12bk5g7417pzn53395_REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby;

extern CONST(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, RTE_CONST) Rte_XDIS_7tqm5jy9oba0thvws62i3l28n_REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw;

extern CONST(REC_Ign_Stat_Pr5_ST3, RTE_CONST) Rte_Const_Ign_Stat_InitVal_REC_Ign_Stat_Pr5_ST3;

extern CONST(REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0, RTE_CONST) Rte_XDIS_cfagkw6zyn9r952v5onwpwdur_REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0;

extern CONST(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, RTE_CONST) Rte_XDIS_8ptnmozvvqneybwnb1dteqblf_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96;

extern CONST(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, RTE_CONST) Rte_XDIS_9fnatjo7ibmc7ug14uhxholnb_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96;

extern CONST(REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_6l5b88fcuqpu2imoz1fzls07a_REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh;

extern CONST(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19, RTE_CONST) Rte_XDIS_7frhrem3wt9j2oidbosrki6rx_REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19;

extern CONST(REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58, RTE_CONST) Rte_XDIS_ayiqyrhz0dpk9ygbqo5e5w1f7_REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58;

extern CONST(REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby, RTE_CONST) Rte_XDIS_9yh6bo4rxot1fkk0920219751_REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby;

extern CONST(REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_1j2e7ey8q28fsybvpbxfqeop8_REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh;

extern CONST(REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, RTE_CONST) Rte_XDIS_9h6oqehaueepowg2tijus0mir_REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw;

extern CONST(REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u, RTE_CONST) Rte_XDIS_86xn4hwzmz58ui3sqboz24rhd_REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u;

extern CONST(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_8ocy3iwo1ditemd6qwphg7b7i_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh;

extern CONST(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_bjxptj1w89so7fpxm4dpms8ww_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh;

extern CONST(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, RTE_CONST) Rte_XDIS_1lex2znuqx5p6s5yy1dyffpdg_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j;

extern CONST(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, RTE_CONST) Rte_XDIS_dw79s45ha1z03s9jiw4xye2p4_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j;

extern CONST(REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr, RTE_CONST) Rte_XDIS_klz6op2k9wci74l4e72gktkb_REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr;

extern CONST(REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, RTE_CONST) Rte_XDIS_4wiqeqoz18rz4k73xcp12oii1_REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt;

extern CONST(REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4, RTE_CONST) Rte_XDIS_dj45cy8ua216iwtra2tj416zq_REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4;

extern CONST(SecOC_VerificationStatusType, RTE_CONST) Rte_C_SecOC_VerificationStatusType_0;

extern CONST(SecOC_VerificationStatusType, RTE_CONST) Rte_Ssa_Init_SecOcVerificationState_SecOC_VerificationStatusType;

extern CONST(Ssa_IgnitionStatusType, RTE_CONST) Rte_Ssa_Init_IgnitionStatus_Ssa_IgnitionStatusType;

extern CONST(Ssa_LocalTickCountAndSyncStatusType, RTE_CONST) Rte_Ssa_Init_LocalTickCountAndSyncStatus_Ssa_LocalTickCountAndSyncStatusType;

extern CONST(Ssa_OdometerRecordType, RTE_CONST) Rte_Ssa_Init_BusOdometerRecord_Ssa_OdometerRecordType;

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# include "Rte_DataHandleType.h"

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Calibration component and SW-C local calibration parameters
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVariant;
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVersion;

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint64, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_TimeM_NvM_TimeM_LocalTimeBase_DefaultValue;
extern CONST(Ssa_TrustModelChainState_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_KeyM_NvM_KeyM_TrustModelChainOfTrustState_DefaultValue;
extern CONST(Ssa_PostProductionStatusType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_PostProductionStatus_DefaultValue;
extern CONST(SecLog_AclVersionType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_AclVersion_DefaultValue;
extern CONST(SecLog_CtrlDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_SecLog_NvM_SecLog_CtrlData_DefaultValue;
extern CONST(Idt_codingData, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_Cal_CodingDataInit;
extern CONST(Coding_StorageType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_Coding_Coding_Storage_DefaultValue;
extern CONST(RightsM_NonceType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_Nonce_DefaultValue;
extern CONST(TimeM_RealTimeOffsetType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_TimeM_NvM_TimeM_RealTimeOffset_DefaultValue;

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_TrustModel_Pim_RealTime_Unix;
extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_FvM_LastSecuredTickCount;
extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_FvM_TickCount;
extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCount;
extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCountMirror;
extern VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCountValueToBeStoredToNvM;
extern VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Cdd_MBBL_EcuStatHandler_NetworkRepeatMessageState;
extern VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_PerInstanceMemory;
extern VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PIM_OldCodingState;
extern VAR(Ssa_TrustModelChainState_Type, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_KeyM_KeyMTrustModelChainOfTrustState;
extern VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatus;
extern VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatusMirror;
extern VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatusMirror2;
extern VAR(Dcm_Data4092ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_CustomerSettings;
extern VAR(Dcm_Data12ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_DiagnosticTraceMemory;
extern VAR(Dcm_Data1ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_ISO_15675_2_BlockSize;
extern VAR(Dcm_Data1ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_ISO_15675_2_STmin;
extern VAR(SecLog_AclVersionType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMAclVersion;
extern VAR(SecLog_LogDataEvnt10_FailedPduMacVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt10_FailedPduMacVerif;
extern VAR(SecLog_LogDataEvnt10_FailedPduMacVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt10_FailedPduMacVerif_Mirror;
extern VAR(SecLog_LogDataEvnt11_SecOrAuthBootType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt11_SecOrAuthBoot;
extern VAR(SecLog_LogDataEvnt11_SecOrAuthBootType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt11_SecOrAuthBoot_Mirror;
extern VAR(SecLog_LogDataEvnt12_ChangeOfVinType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt12_ChangeOfVin;
extern VAR(SecLog_LogDataEvnt12_ChangeOfVinType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt12_ChangeOfVin_Mirror;
extern VAR(SecLog_LogDataEvnt13_AclReplacementType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt13_AclReplacement;
extern VAR(SecLog_LogDataEvnt13_AclReplacementType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt13_AclReplacement_Mirror;
extern VAR(SecLog_LogDataEvnt1_FailedCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt1_FailedCertVerif;
extern VAR(SecLog_LogDataEvnt1_FailedCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt1_FailedCertVerif_Mirror;
extern VAR(SecLog_LogDataEvnt2_SucCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt2_SucCertVerif;
extern VAR(SecLog_LogDataEvnt2_SucCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt2_SucCertVerif_Mirror;
extern VAR(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights;
extern VAR(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror;
extern VAR(SecLog_LogDataEvnt4_AuthBySecAccessType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt4_AuthBySecAccess;
extern VAR(SecLog_LogDataEvnt4_AuthBySecAccessType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt4_AuthBySecAccess_Mirror;
extern VAR(SecLog_LogDataEvnt5_SucDiagServiceExecType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt5_SucDiagServiceExec;
extern VAR(SecLog_LogDataEvnt5_SucDiagServiceExecType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt5_SucDiagServiceExec_Mirror;
extern VAR(SecLog_LogDataEvnt6_RightsMgmtType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt6_RightsMgmt;
extern VAR(SecLog_LogDataEvnt6_RightsMgmtType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt6_RightsMgmt_Mirror;
extern VAR(SecLog_LogDataEvnt7_SigVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt7_SigVerif;
extern VAR(SecLog_LogDataEvnt7_SigVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt7_SigVerif_Mirror;
extern VAR(SecLog_LogDataEvnt8_TickCountDateAndTimeType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt8_TickCountDateAndTime;
extern VAR(SecLog_LogDataEvnt8_TickCountDateAndTimeType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt8_TickCountDateAndTime_Mirror;
extern VAR(SecLog_LogDataEvnt9_SecOcMisconfigType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt9_SecOcMisconfig;
extern VAR(SecLog_LogDataEvnt9_SecOcMisconfigType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt9_SecOcMisconfig_Mirror;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh1;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh1_Mirror;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh2;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh2_Mirror;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh3;
extern VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh3_Mirror;
extern VAR(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_BeltTensionerFunction_IgnStatBuffer;
extern VAR(CalibrationIdentifications_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_CalibrationID;
extern VAR(CalibrationIdentifications_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_CalibrationID_Mirror;
extern VAR(Idt_codingData, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PIM_CodingData;
extern VAR(PreSafeCyclesLevel_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PreSafeCyclesLevel;
extern VAR(PreSafeCyclesLevel_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PreSafeCyclesLevel_Mirror;
extern VAR(ReleaseCyclesBSRAndPresafe_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ReleaseCyclesBsrAndPreSafe;
extern VAR(ReleaseCyclesBSRAndPresafe_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ReleaseCyclesBsrAndPreSafe_Mirror;
extern VAR(TensioningCycleBSR_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_TensioningCycleBSR;
extern VAR(TensioningCycleBSR_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_TensioningCycleBSR_Mirror;
extern VAR(VehicleEquipment_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_VehicleEquipment;
extern VAR(VehicleEquipment_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_VehicleEquipment_Mirror;
extern VAR(ZZZ_VehicleEquipment_Development_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ZZZ_VehicleEquipment_Development;
extern VAR(ZZZ_VehicleEquipment_Development_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ZZZ_VehicleEquipment_Development_Mirror;
extern VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CodingVIN;
extern VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CodingVINMirror;
extern VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CurrentVIN;
extern VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CurrentVINMirror;
extern VAR(RightsM_NonceType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMNonce;
extern VAR(RightsM_NonceType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMNonceMirror;
extern VAR(TimeM_RealTimeOffsetType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_RealTimeOffset;
extern VAR(TimeM_RealTimeOffsetType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_RealTimeOffsetMirror;

#  define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# endif


/**********************************************************************************************************************
 * Buffer definitions for implicit access to S/R port elements
 *********************************************************************************************************************/

# define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

typedef struct
{
  Rte_DE_u8CycleNumberType Rte_prrExecutedCycle_u8CycleNumber;
} Rte_tsRB_BFS_AC_BeltFunctionSelection_BFS_runBeltFunctionSelection; /* PRQA S 0779 */ /* MD_MSR_Rule5.2 */

/* PRQA S 0750 L1 */ /* MD_MSR_Union */
typedef union
{
  Rte_tsRB_BFS_AC_BeltFunctionSelection_BFS_runBeltFunctionSelection Rte_BFS_AC_BeltFunctionSelection_BFS_runBeltFunctionSelection;
} Rte_tuRB_OsTask_ALV_BeltFunctionAlgo;
/* PRQA L:L1 */

typedef struct
{
  Rte_tuRB_OsTask_ALV_BeltFunctionAlgo Rte_RB;
} Rte_tsOsTask_ALV_BeltFunctionAlgo;

# define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned int Rte_BitType;
/**********************************************************************************************************************
 * type and extern declarations of RTE internal variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

# define RTE_STATE_UNINIT     (0U)
# define RTE_STATE_SCHM_START (1U)
# define RTE_STATE_SCHM_INIT  (2U)
# define RTE_STATE_INIT       (3U)

# ifdef RTE_CORE

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern P2CONST(SchM_ConfigType, AUTOMATIC, RTE_CONST) Rte_VarCfgPtr;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVariant; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVersion; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(uint64, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_TimeM_NvM_TimeM_LocalTimeBase_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Ssa_TrustModelChainState_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_KeyM_NvM_KeyM_TrustModelChainOfTrustState_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Ssa_PostProductionStatusType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_PostProductionStatus_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(SecLog_AclVersionType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_AclVersion_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(SecLog_CtrlDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_SecLog_NvM_SecLog_CtrlData_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Idt_codingData, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_Cal_CodingDataInit; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(Coding_StorageType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_Coding_Coding_Storage_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(RightsM_NonceType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_Nonce_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */
extern CONST(TimeM_RealTimeOffsetType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_TimeM_NvM_TimeM_RealTimeOffset_DefaultValue; /* PRQA S 3408, 3449, 3451 */ /* MD_Rte_3408, MD_Rte_3449, MD_Rte_3451 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8StepNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedStep_u8StepNumber; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFS_psrSelectedCycle_u8CycleNumber; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8PreActivationFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8PreConditionsFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c02_Off_On, RTE_VAR_NOINIT) Rte_CIL_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c02_Off_Stage1_Stage2, RTE_VAR_NOINIT) Rte_CIL_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c02_Presf_Disp_Rq, RTE_VAR_NOINIT) Rte_CIL_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c02_Off_Stage1_Stage2, RTE_VAR_NOINIT) Rte_CIL_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c04_RBTM_ActvClient, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c10_RBTM_Fct_Precond, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c04_RBTM_ActvClient, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c10_RBTM_Fct_Precond, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c02_Presf_Disp_Rq, RTE_VAR_NOINIT) Rte_CIL_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c06_RBTM_Lvl_Stat, RTE_VAR_NOINIT) Rte_CIL_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c06_RBTM_Lvl_Stat, RTE_VAR_NOINIT) Rte_CIL_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8PreCrashSeverityLevelType, RTE_VAR_NOINIT) Rte_CIL_prrCrashSeverityLevel_u8PreCrashSeverityLevel; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8lBuckleSwitchStatusType, RTE_VAR_NOINIT) Rte_CIL_psrBuckleDoorSwitch_u8BuckleSwitch; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCANInputBlockStatus_b8NVMBlockStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8IsCarAccelerationLowType, RTE_VAR_NOINIT) Rte_CIL_psrCarAcceleration_b8IsCarAccelerationLow; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8HardReleaseRequest; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8IsCarCrankingActiveType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8PreCrashRequestEnable; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8SignalRelInhibition; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8BeltSlackStatusType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8BeltSlackStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8HapticRequestType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8HapticRequest; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8TriggerRequest; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrEngStartStatus_b8EngStartStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrExtTestPres_b8ExtTesterPresent; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(c04_Presf_Lvl_V2, RTE_VAR_NOINIT) Rte_CIL_psrPreSafeLvl_u8PreSafeLvl; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrProdModeStatus_b8TriggerProdModeStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrTransportationModeStatus_b8TransportationModeStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(BswM_ESH_KillAllRun, RTE_VAR_NOINIT) Rte_Cdd_MBBL_ResetExecutor_Request_ESH_KillAllRunRequest_requestedMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_DIA_psePresafeDisplay_b8TriggerPreSafeRequestStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_EOL_ObsolescenceDataBlockNumber_BlockNumber; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_EOL_pseExecutionCounterBlockStatus_b8NVMBlockStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_ERH_psrAECsBlockStatus_b8NVMBlockStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_ERH_psrDTCConfirmed_b8DTCConfirmed; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_ERH_psrSnapshotData_u8SnapshotAecId; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_MMG_AvailabilityDataHandler_AvailabilityDataCategory; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle0_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle1_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle10_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle11_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle12_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle13_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle14_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle15_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle16_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle17_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle18_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle19_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle2_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle20_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle21_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle22_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle23_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle24_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle25_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle26_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle27_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle28_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle3_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle4_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle5_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle6_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle7_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle8_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle9_b8CycleValidity; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_PMP_isrSupBatStatus_b8SupBatStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8PreActivationFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8PreConditionsFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8IsCarAccelerationLowType, RTE_VAR_NOINIT) Rte_PRE_psrTrigOFF_b8IsCarAccelerationLow; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8TriggerFlag; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_u8TriggeringSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_SFR_psrBeltStackAntipatina_b8BeltStack; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Coding_VINDataType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_Coding_ReceiveVIN_VIN; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Ssa_BcTp_Coding_ReceiveVINTimeout_state; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Ssa_Data6ByteType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_FvM_ReceiveTickCount_tickCount; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Ssa_BcTp_FvM_ReceiveTickCountTimeout_state; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(KeyM_SharedSecretType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(RightsM_AuthenticationBroadcastType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(SecOC_VerificationStatusType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Ssa_Data12ByteType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Ssa_LocalTickCountAndSyncStatusType, RTE_VAR_NOINIT) Rte_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Ssa_ChangeTickCountEventIdType, RTE_VAR_NOINIT) Rte_Ssa_FvM_SendChangeTickCountEvent_Id; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Ssa_Data5ByteType, RTE_VAR_NOINIT) Rte_Ssa_FvM_SendChangeTickCountEvent_TickCount; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Ssa_Data7ByteType, RTE_VAR_NOINIT) Rte_Ssa_SecLog_SecLog_EventNotification_Data; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

typedef struct
{
  Rte_BitType Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack : 1;
  Rte_BitType Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack : 1;
  Rte_BitType Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack : 1;
} Rte_AckFlagsType;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_AckFlagsType, RTE_VAR_NOINIT) Rte_AckFlags;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

typedef struct
{
  Rte_BitType Rte_RxTimeout_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx : 1;
  Rte_BitType Rte_RxTimeout_BeltAdjFunction_R_PT4_PTCoor9_Pr5_ST3_PT4_PTCoor9_Pr5_ST3 : 1;
  Rte_BitType Rte_RxTimeout_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx : 1;
  Rte_BitType Rte_RxTimeout_CIL_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3 : 1;
  Rte_BitType Rte_RxTimeout_CIL_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3 : 1;
  Rte_BitType Rte_RxTimeout_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx : 1;
  Rte_BitType Rte_RxTimeout_Graph_3c51f51b5e8aaf813b8f9a89a7827e7c_BeltHdOvr_XX_Stat_ST3 : 1;
  Rte_BitType Rte_RxTimeout_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx : 1;
  Rte_BitType Rte_RxTimeout_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx : 1;
  Rte_BitType Rte_RxTimeout_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx : 1;
  Rte_BitType Rte_RxTimeout_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx : 1;
  Rte_BitType Rte_RxTimeout_VehSpd_Disp_ST3_4922a2fd_Rx : 1;
} Rte_RxTimeoutFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_RxTimeoutFlagsType, RTE_VAR_ZERO_INIT) Rte_RxTimeoutFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Buffer for inter-runnable variables
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(s16MotorPowerOrderType, RTE_VAR_NOINIT) Rte_Irv_BFE_s16MotorPowerOrder; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(s32OrderValueType, RTE_VAR_NOINIT) Rte_Irv_BFE_s32FirstOrderValue; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(s32OrderValueType, RTE_VAR_NOINIT) Rte_Irv_BFE_s32OrderIncrementValue; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u16StepDurationType, RTE_VAR_NOINIT) Rte_Irv_BFE_u16StepDuration; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8MotorStageStatusType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8MotorStageStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8OrdersListType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8OrderType; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8VelocityTargetType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8VelocityTarget; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint16, RTE_VAR_NOINIT) Rte_Irv_BaseFunction_NmTimer; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_Irv_CIL_b8CarCrashDetected; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_CIL_b8PreCrashRequestEnable; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8ActvLvlSignal; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8lBuckleSwitchStatusType, RTE_VAR_NOINIT) Rte_Irv_CIL_u8BuckleStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8FctPrecond_ProfileNotImplemented; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8RequestSource; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_DIA_u8DiagRequestedCycle; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_MMG_b8PreSafeRecorder1Update; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_MMG_b8PreSafeRecorder2Update; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u32DeficiencyLevelType, RTE_VAR_NOINIT) Rte_Irv_PMP_u32DeficiencyLevel; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u32ResetCauseType, RTE_VAR_NOINIT) Rte_Irv_RCM_u8ResetCause; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_SCM_u8CurrentTensioningState; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_SCM_u8LastTensioningSituation; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvCountUpSecTimeMsg; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvFirstTickCountMessageAfterStartUpReceived; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Ssa_TickCountSyncStateType, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Ssa_TickCountSyncStateType, RTE_VAR_NOINIT) Rte_Irv_Ssa_TimeM_TimeM_IrvTickCountSyncState; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * RTE internal IOC replacement
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Queue[1];

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_NOINIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[1];

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/




# endif /* defined(RTE_CORE) */

/**********************************************************************************************************************
 * extern declaration of RTE Update Flags for optimized macro implementation
 *********************************************************************************************************************/
typedef struct
{
  Rte_BitType Rte_RxUpdate_MMG_prrAECsBlockStatus_b8NVMBlockStatus : 1;
  Rte_BitType Rte_RxUpdate_MMG_prrCANInputBlockStatus_b8NVMBlockStatus : 1;
  Rte_BitType Rte_RxUpdate_MMG_prrExecutionCountersBlockStatus_b8NVMBlockStatus : 1;
} Rte_RxUpdateFlagsType;

# define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_RxUpdateFlags;

# define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
