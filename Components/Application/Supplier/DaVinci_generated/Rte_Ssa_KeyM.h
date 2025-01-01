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
 *             File:  Rte_Ssa_KeyM.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <Ssa_KeyM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_KEYM_H
# define RTE_SSA_KEYM_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Ssa_KeyM_Type.h"
# include "Rte_DataHandleType.h"

# include "Rte_Hook.h"


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_KeyM_ReplaceRootCertificate_isProductive (FALSE)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_KeyM_KeyM_Com_ReceiveSharedSecret_sharedSecret(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_KeyM_KeyM_Com_ReceiveSharedSecret_sharedSecret(P2VAR(KeyM_SharedSecretType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Issuer, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SerialNo, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_Version, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_authKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_basicConstraints, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_ext_subKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_subject, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendCert_validityNotAfter, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_Version, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_authKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_basicConstraints, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_ext_subKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_validityNotAfter, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Issuer, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SerialNo, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_Version, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_authKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_specialEcu, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_subKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_ext_uniqueECUID, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_subject, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuCert_validityNotAfter, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_Version, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_authKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_specialEcu, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_ext_subKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_validityNotAfter, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Issuer, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SerialNo, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_Version, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_authKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_basicConstraints, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_ext_subKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_subject, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediateCert_validityNotAfter, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_Version, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_validityNotAfter, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Issuer, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SerialNo, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_Version, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_basicConstraints, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_keyUsage, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_ext_subKeyId, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_subject, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_CertificateElementGet(P2VAR(KeyM_CertificateElementType_Ssa_TrustModelRootCert_validityNotAfter, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif


# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_KeyM_Com_ReceiveSharedSecret_sharedSecret Rte_Read_Ssa_KeyM_KeyM_Com_ReceiveSharedSecret_sharedSecret


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_KeyM_ReplaceRootCertificate_isProductive Rte_Write_Ssa_KeyM_KeyM_ReplaceRootCertificate_isProductive
#  define Rte_Write_Ssa_KeyM_KeyM_ReplaceRootCertificate_isProductive(data) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Switch_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Switch_Ssa_MacKeyGeneration_State_State Rte_Switch_Ssa_KeyM_Ssa_MacKeyGeneration_State_State
#  define Rte_Switch_Ssa_KeyM_Ssa_MacKeyGeneration_State_State(mode) (RTE_E_OK)


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_RandomGenerate(uint32 parg0, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_RandomGenerate(uint32 parg0, P2VAR(Csm_RandomGenerateResultType_Random_TRNG, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_Decrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_Decrypt(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(Csm_DecryptDataType_AES128Decrypt, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(Csm_DecryptResultType_AES128Decrypt, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementSet(uint32 parg0, uint32 keyElementId, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) keyPtr, uint32 keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementSet(uint32 parg0, uint32 keyElementId, P2CONST(Csm_KeyDataType_Ssa_AesRamKey, AUTOMATIC, RTE_CSM_APPL_DATA) keyPtr, uint32 keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeySetValid(uint32 parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementGet(uint32 parg0, uint32 keyElementId, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) keyPtr, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementGet(uint32 parg0, uint32 keyElementId, P2VAR(Csm_KeyDataType_Ssa_BackendCert, AUTOMATIC, RTE_CSM_APPL_VAR) keyPtr, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_RandomSeed(uint32 parg0, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) seedPtr, uint32 seedLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_RandomSeed(uint32 parg0, P2CONST(Csm_SeedDataTypeSsa_RandomSeed, AUTOMATIC, RTE_CSM_APPL_DATA) seedPtr, uint32 seedLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyExchangeCalcPubVal(uint32 parg0, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) publicValuePtr, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) publicValueLengthPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyExchangeCalcPubVal(uint32 parg0, P2VAR(Csm_PublicValueDataType_Ssa_SharedSecretKeyExchange, AUTOMATIC, RTE_CSM_APPL_VAR) publicValuePtr, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) publicValueLengthPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyExchangeCalcSecret(uint32 parg0, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) partnerPublicValuePtr, uint32 partnerPublicValueLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyExchangeCalcSecret(uint32 parg0, P2CONST(Csm_PublicValueDataType_Ssa_SharedSecretKeyExchange, AUTOMATIC, RTE_CSM_APPL_DATA) partnerPublicValuePtr, uint32 partnerPublicValueLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyElementCopy(uint32 parg0, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_KeyGenerate(uint32 parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_MacGenerate(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(uint8, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CSM_APPL_CODE) Csm_MacGenerate(uint32 parg0, Crypto_OperationModeType parg1, P2CONST(Csm_MacGenerateDataType_MacGenAesCmac, AUTOMATIC, RTE_CSM_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(Csm_MacGenerateResultType_MacGenAesCmac, AUTOMATIC, RTE_CSM_APPL_VAR) resultBuffer, P2VAR(uint32, AUTOMATIC, RTE_CSM_APPL_VAR) resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_CSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE) R_ICS_KeyStorage_ST3_StorePermanently(Ssa_KeyStorageUseCaseType keyStorageUseCase, Ssa_KeyStorageTaskType keyStorageTask); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_CT_MBBL_SSAAPPL_GENERAL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE) Ssa_onVedocInformation_called(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) dataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE) Ssa_onVedocInformation_called(P2VAR(Ssa_Data64ByteType, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_VAR) dataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_CT_MBBL_SSAAPPL_TRUSTMODEL_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_KEYM_APPL_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SerialNo_004(KeyM_CertificateIdType parg0, KeyM_CertElementIdType parg1, P2VAR(uint8, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_KEYM_APPL_CODE) KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SerialNo_004(KeyM_CertificateIdType parg0, KeyM_CertElementIdType parg1, P2VAR(KeyM_CertificateElementType_Ssa_TrustModelBackendPeerCert_SerialNo_004, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_KEYM_APPL_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SerialNo_006(KeyM_CertificateIdType parg0, KeyM_CertElementIdType parg1, P2VAR(uint8, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_KEYM_APPL_CODE) KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SerialNo_006(KeyM_CertificateIdType parg0, KeyM_CertElementIdType parg1, P2VAR(KeyM_CertificateElementType_Ssa_TrustModelEcuPeerCert_SerialNo_006, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_KEYM_APPL_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SerialNo_007(KeyM_CertificateIdType parg0, KeyM_CertElementIdType parg1, P2VAR(uint8, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_KEYM_APPL_CODE) KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SerialNo_007(KeyM_CertificateIdType parg0, KeyM_CertElementIdType parg1, P2VAR(KeyM_CertificateElementType_Ssa_TrustModelIntermediatePeerCert_SerialNo_007, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_KEYM_APPL_VAR) CertificateDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_KEYM_APPL_CODE) KeyM_CertGetStatus(KeyM_CertificateIdType parg0, P2VAR(KeyM_CertificateStatusType, AUTOMATIC, RTE_KEYM_APPL_VAR) Status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_KEYM_APPL_CODE) KeyM_VerifyCertificate(KeyM_CertificateIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_KEYM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CDD_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_Hash(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_SignatureGenerate(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_KeyElementCopy(uint32 keyId, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_KeyElementGet(uint32 keyId, uint32 keyElementId, Ssa_DataPtr keyPtr, Ssa_LengthPtr keyLengthPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_KeyElementSet(uint32 keyId, uint32 keyElementId, Ssa_ConstDataPtr keyPtr, uint32 keyLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_Csm_KeySetValid(uint32 keyId); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_KeyM_CsrElementSet(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, KeyM_CsrEncodingType EncodingType, Ssa_ConstDataPtr ElementData, uint32 ElementDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_KeyM_GetCertificate(KeyM_CertificateIdType CertId, Ssa_DataPtr CertData, Ssa_LengthPtr CertDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_KeyM_ServiceCertificate(KeyM_ServiceCertificateType Service, Ssa_ConstDataPtr CertNamePtr, uint32 CertNameLength, Ssa_ConstDataPtr RequestData, uint32 RequestDataLength, Ssa_DataPtr ResponseData, uint32 ResponseDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_CDD_APPL_CODE) Ssa_Cdd_KeyM_SetCertificate(KeyM_CertificateIdType CertId, Ssa_DataPtr CertData, uint32 CertDataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_CDD_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CERTP_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_AttributeCertificate_Parse(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_AttributeCertificate_Parse(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Compare(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData1, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert1, CertP_PkiRoleType pkiRole1, P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData2, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert2, CertP_PkiRoleType pkiRole2, P2VAR(boolean, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) isEqual); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Compare(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData1, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert1, CertP_PkiRoleType pkiRole1, P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData2, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCert2, CertP_PkiRoleType pkiRole2, P2VAR(boolean, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) isEqual); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Parse(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Parse(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, uint16 rawCertLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Verify(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert, P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer, CertP_PkiRoleType expectedPkiRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Verify(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert, P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer, CertP_PkiRoleType expectedPkiRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Verify_Extended(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert, P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer, CertP_PkiRoleType expectedPkiRole, P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_Certificate_Verify_Extended(P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertData, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) parsedCert, P2CONST(CertP_RawCertBufferType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) rawCertIssuer, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) parsedCertIssuer, CertP_PkiRoleType expectedPkiRole, P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) expectedNonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_ParseTime(P2CONST(uint8, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) data, uint16 dataLength, P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) dateTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CERTP_APPL_CODE) Ssa_CertP_ParseTime(P2CONST(Ssa_Data15ByteType, AUTOMATIC, RTE_SSA_CERTP_APPL_DATA) data, uint16 dataLength, P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_CERTP_APPL_VAR) dateTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_CERTP_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_VIN_Get(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) vin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_CODING_APPL_CODE) Ssa_Coding_VIN_Get(P2VAR(Coding_VINDataType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) vin); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_CODING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_RIGHTSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start(P2CONST(Dcm_Data2002ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole(P2VAR(RightsM_DiagnosticUserRoleType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) userRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask(P2VAR(RightsM_ACL_BitMaskType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) userRolesBitMask); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus(P2VAR(Ssa_PostProductionStatusType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) status); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) subjectKeyIdentifier); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier(P2CONST(Ssa_Data20ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) subjectKeyIdentifier); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_Nonce_Destroy(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_Nonce_Get(boolean generateNew, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_RIGHTSM_APPL_CODE) Ssa_RightsM_Nonce_Get(boolean generateNew, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_RIGHTSM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_FailedCertificateVerification(CertP_PkiRoleType pkiRole, CertP_VerificationResultType validationResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SuccessfulCertificateVerification(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) certId, CertP_PkiRoleType pkiRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SuccessfulCertificateVerification(P2CONST(RightsM_SerialNumberType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) certId, CertP_PkiRoleType pkiRole); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif
FUNC(Std_ReturnType, RTE_SSA_SECLOG_APPL_CODE) Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution(uint8 parg0, uint8 additionalInfo); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_SSA_SECLOG_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Compare(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t1, TimeM_CompareOperatorType compareOp, P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t2, P2VAR(boolean, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_RealTime_Get(P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) realTime); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_TimeRawData_ResetLocalTickCount(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_TimeRawData_Set(P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) dateTimeOffset, P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) tickCountOffset, P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  else
FUNC(Std_ReturnType, RTE_SSA_TIMEM_APPL_CODE) Ssa_TimeM_TimeRawData_Set(P2CONST(Ssa_Data7ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) dateTimeOffset, P2CONST(Ssa_Data5ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) tickCountOffset, P2CONST(Ssa_Data5ByteType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) tickCount); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
#  endif

#  define RTE_STOP_SEC_SSA_TIMEM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_CertP_Functions_AttributeCertificate_Parse Ssa_CertP_AttributeCertificate_Parse
#  define Rte_Call_CertP_Functions_Certificate_Compare Ssa_CertP_Certificate_Compare
#  define Rte_Call_CertP_Functions_Certificate_Parse Ssa_CertP_Certificate_Parse
#  define Rte_Call_CertP_Functions_Certificate_Verify Ssa_CertP_Certificate_Verify
#  define Rte_Call_CertP_Functions_Certificate_Verify_Extended Ssa_CertP_Certificate_Verify_Extended
#  define Rte_Call_CertP_Functions_ParseTime Ssa_CertP_ParseTime
#  define Rte_Call_Coding_VIN_Get Ssa_Coding_VIN_Get
#  define Rte_Call_CsmJobKeyExchangeCalcPubVal_KeyExchangeCalcPubVal(arg1, arg2, arg3) (RTE_E_UNCONNECTED)
#  define Rte_Call_CsmJobKeyExchangeCalcSecret_KeyExchangeCalcSecret(arg1, arg2, arg3) (RTE_E_UNCONNECTED)
#  define Rte_Call_CsmJobKeyGenerate_TrustModelEcuCsr_KeyGenerate(arg1) (RTE_E_UNCONNECTED)
#  define Rte_Call_CsmJobRandomSeed_RandomSeed(arg1, arg2, arg3) (RTE_E_UNCONNECTED)
#  define Rte_Call_CsmRandomGenerate_RandomGenerate(arg1, arg2) (Csm_RandomGenerate((uint32)33, arg1, arg2))
#  define Rte_Call_CsmSymAES128Decrypt_Decrypt(arg1, arg2, arg3, arg4) (Csm_Decrypt((uint32)25, (Crypto_OperationModeType)7, arg1, arg2, arg3, arg4))
#  define Rte_Call_CsmSymAES128DecryptWithPadding_Decrypt(arg1, arg2, arg3, arg4) (RTE_E_UNCONNECTED)
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_SerialNo_CertificateElementGet(arg1, arg2) (KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_SerialNo_004((KeyM_CertificateIdType)1, (KeyM_CertElementIdType)1, arg1, arg2))
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_SerialNo_CertificateElementGet(arg1, arg2) (KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_SerialNo_006((KeyM_CertificateIdType)4, (KeyM_CertElementIdType)1, arg1, arg2))
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_SerialNo_CertificateElementGet(arg1, arg2) (KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_SerialNo_007((KeyM_CertificateIdType)6, (KeyM_CertElementIdType)1, arg1, arg2))
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_CertificateElementGet
#  define Rte_Call_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_CertificateElementGet Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_CertificateElementGet
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelBackendCert_GetStatus(arg1) (KeyM_CertGetStatus((KeyM_CertificateIdType)0, arg1))
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelBackendPeerCert_GetStatus(arg1) (KeyM_CertGetStatus((KeyM_CertificateIdType)1, arg1))
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelEcuCert_GetStatus(arg1) (KeyM_CertGetStatus((KeyM_CertificateIdType)2, arg1))
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelEcuCert_VerifyCertificate() (KeyM_VerifyCertificate((KeyM_CertificateIdType)2))
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelEcuPeerCert_GetStatus(arg1) (KeyM_CertGetStatus((KeyM_CertificateIdType)4, arg1))
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelEcuPeerCert_VerifyCertificate() (KeyM_VerifyCertificate((KeyM_CertificateIdType)4))
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelIntermediateCert_GetStatus(arg1) (KeyM_CertGetStatus((KeyM_CertificateIdType)5, arg1))
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelIntermediatePeerCert_GetStatus(arg1) (KeyM_CertGetStatus((KeyM_CertificateIdType)6, arg1))
#  define Rte_Call_KeyMCertificate_Ssa_TrustModelRootCert_GetStatus(arg1) (KeyM_CertGetStatus((KeyM_CertificateIdType)7, arg1))
#  define Rte_Call_Key_AesRamKey_KeyElementSet(arg1, arg2, arg3) (Csm_KeyElementSet((uint32)37, arg1, arg2, arg3))
#  define Rte_Call_Key_AesRamKey_KeySetValid() (Csm_KeySetValid((uint32)37))
#  define Rte_Call_Key_BackendCert_KeyElementGet(arg1, arg2, arg3) (Csm_KeyElementGet((uint32)39, arg1, arg2, arg3))
#  define Rte_Call_Key_RandomSeed_KeySetValid() (Csm_KeySetValid((uint32)41))
#  define Rte_Call_Key_RandomSeed_RandomSeed(arg1, arg2) (Csm_RandomSeed((uint32)41, arg1, arg2))
#  define Rte_Call_Key_RootCert_KeyElementGet(arg1, arg2, arg3) (Csm_KeyElementGet((uint32)43, arg1, arg2, arg3))
#  define Rte_Call_Key_SharedSecretHash_KeyElementGet(arg1, arg2, arg3) (Csm_KeyElementGet((uint32)45, arg1, arg2, arg3))
#  define Rte_Call_Key_SharedSecretHash_KeyElementSet(arg1, arg2, arg3) (Csm_KeyElementSet((uint32)45, arg1, arg2, arg3))
#  define Rte_Call_Key_SharedSecretHash_KeySetValid() (Csm_KeySetValid((uint32)45))
#  define Rte_Call_Key_SharedSecretKeyExchange_KeyElementGet(arg1, arg2, arg3) (Csm_KeyElementGet((uint32)46, arg1, arg2, arg3))
#  define Rte_Call_Key_SharedSecretKeyExchange_KeyElementSet(arg1, arg2, arg3) (Csm_KeyElementSet((uint32)46, arg1, arg2, arg3))
#  define Rte_Call_Key_SharedSecretKeyExchange_KeyExchangeCalcPubVal(arg1, arg2) (Csm_KeyExchangeCalcPubVal((uint32)46, arg1, arg2))
#  define Rte_Call_Key_SharedSecretKeyExchange_KeyExchangeCalcSecret(arg1, arg2) (Csm_KeyExchangeCalcSecret((uint32)46, arg1, arg2))
#  define Rte_Call_Key_SharedSecretKeyExchange_KeySetValid() (Csm_KeySetValid((uint32)46))
#  define Rte_Call_Key_SignatureRamKey_KeyElementSet(arg1, arg2, arg3) (Csm_KeyElementSet((uint32)47, arg1, arg2, arg3))
#  define Rte_Call_Key_SignatureRamKey_KeySetValid() (Csm_KeySetValid((uint32)47))
#  define Rte_Call_Key_TrustModelEcuCsrPrivateKey_KeyElementCopy(arg1, arg2, arg3) (Csm_KeyElementCopy((uint32)15, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelEcuCsrPrivateKey_KeyGenerate() (Csm_KeyGenerate((uint32)15))
#  define Rte_Call_Key_TrustModelEcuCsrPrivateKey_KeySetValid() (Csm_KeySetValid((uint32)15))
#  define Rte_Call_Key_TrustModelEcuCsrPublicKey_KeyElementCopy(arg1, arg2, arg3) (Csm_KeyElementCopy((uint32)16, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelEcuCsrPublicKey_KeyElementGet(arg1, arg2, arg3) (Csm_KeyElementGet((uint32)16, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelEcuCsrPublicKey_KeySetValid() (Csm_KeySetValid((uint32)16))
#  define Rte_Call_Key_TrustModelEcuLivePrivateKey_KeySetValid() (Csm_KeySetValid((uint32)13))
#  define Rte_Call_Key_TrustModelEcuLivePublicKey_KeyElementGet(arg1, arg2, arg3) (Csm_KeyElementGet((uint32)9, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelEcuStagingPrivateKey_KeyElementCopy(arg1, arg2, arg3) (Csm_KeyElementCopy((uint32)11, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelEcuStagingPrivateKey_KeySetValid() (Csm_KeySetValid((uint32)11))
#  define Rte_Call_Key_TrustModelEcuStagingPublicKey_KeyElementCopy(arg1, arg2, arg3) (Csm_KeyElementCopy((uint32)8, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelEcuStagingPublicKey_KeySetValid() (Csm_KeySetValid((uint32)8))
#  define Rte_Call_Key_TrustModelRootReplacementKey_KeyElementGet(arg1, arg2, arg3) (Csm_KeyElementGet((uint32)5, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelTempPublicKey_KeyElementGet(arg1, arg2, arg3) (Csm_KeyElementGet((uint32)22, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelTempPublicKey_KeyElementSet(arg1, arg2, arg3) (Csm_KeyElementSet((uint32)22, arg1, arg2, arg3))
#  define Rte_Call_Key_TrustModelTempPublicKey_KeySetValid() (Csm_KeySetValid((uint32)22))
#  define Rte_Call_MacGen_PduKeysMac_MacGenerate(arg1, arg2, arg3, arg4) (Csm_MacGenerate((uint32)0, (Crypto_OperationModeType)7, arg1, arg2, arg3, arg4))
#  define Rte_Call_NvMService_KeyM_TrustModelChainOfTrustState_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)97, arg1))
#  define Rte_Call_NvMService_KeyM_TrustModelChainOfTrustState_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)97, arg1))
#  define Rte_Call_RC_Enhance_Access_Rights_Start Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start
#  define Rte_Call_RightsM_DiagnosticChannel_GetDiagnosticUserRole Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole
#  define Rte_Call_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask
#  define Rte_Call_RightsM_DiagnosticChannel_GetPostProductionStatus Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus
#  define Rte_Call_RightsM_EnhancedRights_VerifySubjectKeyIdentifier Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier
#  define Rte_Call_RightsM_Nonce_Destroy Ssa_RightsM_Nonce_Destroy
#  define Rte_Call_RightsM_Nonce_Get Ssa_RightsM_Nonce_Get
#  define Rte_Call_SecLog_FailedCertVerificationEvent_FailedCertificateVerification Ssa_SecLog_LogEvent_FailedCertificateVerification
#  define Rte_Call_SecLog_SuccessfulCertVerificationEvent_SuccessfulCertificateVerification Ssa_SecLog_LogEvent_SuccessfulCertificateVerification
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_InjectSeed_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)17, arg1))
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ReplaceCert_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)0, arg1))
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ReplaceTrustModeRootCert_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)11, arg1))
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ReplaceTrustModelCert_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)10, arg1))
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_TrustModelEcuSharedSecretDistribution_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)13, arg1))
#  define Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_TrustModelGenerateKeyPair_SuccessfulDiagServiceExecution(arg1) (Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution((uint8)16, arg1))
#  define Rte_Call_SsaCdd_Csm_Hash Ssa_Cdd_Csm_Hash
#  define Rte_Call_SsaCdd_Csm_SignatureGenerate Ssa_Cdd_Csm_SignatureGenerate
#  define Rte_Call_SsaCdd_Csm_SignatureVerify Ssa_Cdd_Csm_SignatureVerify
#  define Rte_Call_SsaCdd_Keys_KeyElementCopy Ssa_Cdd_Csm_KeyElementCopy
#  define Rte_Call_SsaCdd_Keys_KeyElementGet Ssa_Cdd_Csm_KeyElementGet
#  define Rte_Call_SsaCdd_Keys_KeyElementSet Ssa_Cdd_Csm_KeyElementSet
#  define Rte_Call_SsaCdd_Keys_KeySetValid Ssa_Cdd_Csm_KeySetValid
#  define Rte_Call_SsaCdd_TrustModel_CsrElementSet Ssa_Cdd_KeyM_CsrElementSet
#  define Rte_Call_SsaCdd_TrustModel_GetCertificate Ssa_Cdd_KeyM_GetCertificate
#  define Rte_Call_SsaCdd_TrustModel_ServiceCertificate Ssa_Cdd_KeyM_ServiceCertificate
#  define Rte_Call_SsaCdd_TrustModel_SetCertificate Ssa_Cdd_KeyM_SetCertificate
#  define Rte_Call_Ssa_KeyProc_GenerateKeyPair(arg1, arg2) (RTE_E_UNCONNECTED)
#  define Rte_Call_Ssa_KeyProc_PrepareKeyExchange(arg1, arg2) (RTE_E_UNCONNECTED)
#  define Rte_Call_Ssa_KeyStorage_StorePermanently R_ICS_KeyStorage_ST3_StorePermanently
#  define Rte_Call_Ssa_VeDocRelevantInfo_GetData Ssa_onVedocInformation_called
#  define Rte_Call_TimeM_RealTime_Compare Ssa_TimeM_RealTime_Compare
#  define Rte_Call_TimeM_RealTime_Get Ssa_TimeM_RealTime_Get
#  define Rte_Call_TimeM_TimeRawData_ResetLocalTickCount Ssa_TimeM_TimeRawData_ResetLocalTickCount
#  define Rte_Call_TimeM_TimeRawData_Set Ssa_TimeM_TimeRawData_Set

/**********************************************************************************************************************
 * Exclusive Areas
 *********************************************************************************************************************/

#  define Rte_Enter_KeyM_ExclusiveArea() SuspendAllInterrupts() /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#  define Rte_Exit_KeyM_ExclusiveArea() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


/**********************************************************************************************************************
 * Rte_CData (SW-C local calibration parameters)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT

#   define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(Ssa_TrustModelChainState_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_KeyM_NvM_KeyM_TrustModelChainOfTrustState_DefaultValue;

#   define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

#  define Rte_CData_NvM_KeyM_TrustModelChainOfTrustState_DefaultValue() (Rte_Ssa_KeyM_NvM_KeyM_TrustModelChainOfTrustState_DefaultValue)

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Ssa_TrustModelChainState_Type, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_KeyM_KeyMTrustModelChainOfTrustState;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_KeyMTrustModelChainOfTrustState() \
  (&Rte_Ssa_KeyM_KeyMTrustModelChainOfTrustState)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define Ssa_KeyM_START_SEC_CODE
# include "Ssa_KeyM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ssa_KeyM_Certificate_CheckTrustModelChainOfTrust Ssa_KeyM_Certificate_CheckTrustModelChainOfTrust
#  define RTE_RUNNABLE_Ssa_KeyM_Certificate_GetBackendSerialNumber Ssa_KeyM_Certificate_GetBackendSerialNumber
#  define RTE_RUNNABLE_Ssa_KeyM_Certificate_GetBackendSubject Ssa_KeyM_Certificate_GetBackendSubject
#  define RTE_RUNNABLE_Ssa_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey Ssa_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey
#  define RTE_RUNNABLE_Ssa_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey Ssa_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey
#  define RTE_RUNNABLE_Ssa_KeyM_Certificate_VerifyCertWithBackendCert Ssa_KeyM_Certificate_VerifyCertWithBackendCert
#  define RTE_RUNNABLE_Ssa_KeyM_Com_VehicleSharedSecretNotification Ssa_KeyM_Com_VehicleSharedSecretNotification
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_KeyExchangeCalcPubVal Ssa_KeyM_CsmCallbackNotification_KeyExchangeCalcPubVal
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_KeyExchangeCalcSecret Ssa_KeyM_CsmCallbackNotification_KeyExchangeCalcSecret
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_KeyGenerate_TrustModelEcuCsr Ssa_KeyM_CsmCallbackNotification_KeyGenerate_TrustModelEcuCsr
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_RandomGenerate Ssa_KeyM_CsmCallbackNotification_RandomGenerate
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_RandomSeed Ssa_KeyM_CsmCallbackNotification_RandomSeed
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_SignatureGenerate_TrustModelEcuCsr Ssa_KeyM_CsmCallbackNotification_SignatureGenerate_TrustModelEcuCsr
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_SignatureGenerate_TrustModelEcuLive Ssa_KeyM_CsmCallbackNotification_SignatureGenerate_TrustModelEcuLive
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_SignatureVerify Ssa_KeyM_CsmCallbackNotification_SignatureVerify
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_SignatureVerify_ReplacementAuthority Ssa_KeyM_CsmCallbackNotification_SignatureVerify_ReplacementAuthority
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_SignatureVerify_TrustModelBackend Ssa_KeyM_CsmCallbackNotification_SignatureVerify_TrustModelBackend
#  define RTE_RUNNABLE_Ssa_KeyM_CsmCallbackNotification_SignatureVerify_TrustModelTemp Ssa_KeyM_CsmCallbackNotification_SignatureVerify_TrustModelTemp
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_Backend_CA_Certificate_ConditionCheckRead Ssa_KeyM_DataServices_Backend_CA_Certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ConditionCheckRead Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ReadData Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadData Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadDataLength Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ReadData Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ConditionCheckRead Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ReadData Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Certificates_ConditionCheckRead Ssa_KeyM_DataServices_DID_0199_Certificates_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Certificates_ReadData Ssa_KeyM_DataServices_DID_0199_Certificates_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Certificates_ReadDataLength Ssa_KeyM_DataServices_DID_0199_Certificates_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Data_Signature_ConditionCheckRead Ssa_KeyM_DataServices_DID_0199_Data_Signature_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Data_Signature_ReadData Ssa_KeyM_DataServices_DID_0199_Data_Signature_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Nonce_ConditionCheckRead Ssa_KeyM_DataServices_DID_0199_Nonce_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_0199_Nonce_ReadData Ssa_KeyM_DataServices_DID_0199_Nonce_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadData Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadDataLength Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ConditionCheckRead Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadData Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadDataLength Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ConditionCheckRead Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadData Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadDataLength Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadDataLength
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead
#  define RTE_RUNNABLE_Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ReadData Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ReadData
#  define RTE_RUNNABLE_Ssa_KeyM_Init Ssa_KeyM_Init
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackend Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackend
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackendPeer Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackendPeer
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcu Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcu
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuCsr Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuCsr
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuPeer Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuPeer
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediate Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediate
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediatePeer Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediatePeer
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelRoot Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelRoot
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackend Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackend
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackendPeer Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackendPeer
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcu Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcu
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuCsr Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuCsr
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuPeer Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuPeer
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediate Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediate
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediatePeer Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediatePeer
#  define RTE_RUNNABLE_Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelRoot Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelRoot
#  define RTE_RUNNABLE_Ssa_KeyM_MainFunction Ssa_KeyM_MainFunction
#  define RTE_RUNNABLE_Ssa_KeyM_RoutineServices_Get_Certificate_Entry_Start Ssa_KeyM_RoutineServices_Get_Certificate_Entry_Start
#  define RTE_RUNNABLE_Ssa_KeyM_RoutineServices_Inject_Seed Ssa_KeyM_RoutineServices_Inject_Seed
#  define RTE_RUNNABLE_Ssa_KeyM_RoutineServices_Replace_Certificates Ssa_KeyM_RoutineServices_Replace_Certificates
#  define RTE_RUNNABLE_Ssa_KeyM_RoutineServices_Replace_Trust_model_Certificates Ssa_KeyM_RoutineServices_Replace_Trust_model_Certificates
#  define RTE_RUNNABLE_Ssa_KeyM_RoutineServices_Replace_Trust_model_Root_Certificate Ssa_KeyM_RoutineServices_Replace_Trust_model_Root_Certificate
#  define RTE_RUNNABLE_Ssa_KeyM_RoutineServices_Routine_Certificate_Self_Check Ssa_KeyM_RoutineServices_Routine_Certificate_Self_Check
#  define RTE_RUNNABLE_Ssa_KeyM_RoutineServices_Trust_Model_Generate_Key_Pair Ssa_KeyM_RoutineServices_Trust_Model_Generate_Key_Pair
#  define RTE_RUNNABLE_Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
# endif

FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_Certificate_CheckTrustModelChainOfTrust(P2VAR(Ssa_TrustModelChainState_Type, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) state); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_Certificate_GetBackendSerialNumber(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) serialNumber, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) serialNumberLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_Certificate_GetBackendSubject(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) backendSubject, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) dataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) data, uint16 dataLength, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) signature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) data, uint16 dataLength, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) signature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_Certificate_VerifyCertWithBackendCert(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) cert, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) parsedCertStructure, uint16 certLength, CertP_PkiRoleType expectedPkiRole, P2CONST(RightsM_AuthNonceType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) expectedNonce); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_Com_VehicleSharedSecretNotification(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_KeyExchangeCalcPubVal(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_KeyExchangeCalcSecret(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_KeyGenerate_TrustModelEcuCsr(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_RandomGenerate(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_RandomSeed(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_SignatureGenerate_TrustModelEcuCsr(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_SignatureGenerate_TrustModelEcuLive(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_SignatureVerify(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_SignatureVerify_ReplacementAuthority(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_SignatureVerify_TrustModelBackend(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_CsmCallbackNotification_SignatureVerify_TrustModelTemp(Csm_ResultType result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4092ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Certificates_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Data_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Nonce_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4008ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackend(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackendPeer(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcu(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuCsr(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuPeer(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediate(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediatePeer(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelRoot(KeyM_CertificateStatusType Result); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackend(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackendPeer(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcu(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuCsr(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuPeer(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediate(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediatePeer(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelRoot(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, Ssa_KeyM_CODE) Ssa_KeyM_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Get_Certificate_Entry_Start(uint8 Certificate_Identification_In, uint8 In_Certificate_Entry_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Certificate_identification_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Out_Certificate_Entry_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Certificate_Content_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Get_Certificate_Entry_Start(uint8 Certificate_Identification_In, uint8 In_Certificate_Entry_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Certificate_identification_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Out_Certificate_Entry_Out, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Certificate_Content_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Inject_Seed(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Ephemeral_Backend_Public_Key_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Data_Signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Encrypted_Seed_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Inject_Seed(P2CONST(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Ephemeral_Backend_Public_Key_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Data_Signature_In, P2CONST(Dcm_Data1058ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Encrypted_Seed_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Replace_Certificates(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Replace_Trust_model_Certificates(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Trust_Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Replace_Trust_model_Certificates(P2CONST(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Trust_Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Replace_Trust_model_Root_Certificate(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) signature_new_Root_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Replace_Trust_model_Root_Certificate(P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) signature_new_Root_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) signature_In, P2CONST(Dcm_Data2004ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo, P2VAR(Dcm_Data18ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CSR_Signature_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Trust_Model_ECU_CSR_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, P2VAR(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CSR_Signature_Out, P2VAR(Dcm_Data1002ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Trust_Model_ECU_CSR_Out, P2VAR(uint16, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Date_and_Time_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Tick_Count_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Tick_Count_Offset_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Ephemeral_VSM_Public_Key_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Data_Signature_In, P2CONST(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, Ssa_KeyM_CODE) Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(P2CONST(Dcm_Data7ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Date_and_Time_In, P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Tick_Count_In, P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Tick_Count_Offset_In, P2CONST(Dcm_Data80ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In, P2CONST(Dcm_Data32ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Ephemeral_VSM_Public_Key_In, P2CONST(Dcm_Data64ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Data_Signature_In, P2CONST(Dcm_Data3006ByteType, AUTOMATIC, RTE_SSA_KEYM_APPL_DATA) Certificates_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) Verification_Result_Out, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define Ssa_KeyM_STOP_SEC_CODE
# include "Ssa_KeyM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CertP_Functions_E_NOT_OK (1U)

#  define RTE_E_CertP_Functions_E_PENDING (10U)

#  define RTE_E_Coding_VIN_E_NOT_OK (1U)

#  define RTE_E_CsmDecrypt_AES128Decrypt_CSM_E_BUSY (2U)

#  define RTE_E_CsmDecrypt_AES128Decrypt_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmDecrypt_AES128Decrypt_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmDecrypt_AES128Decrypt_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmDecrypt_AES128Decrypt_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmDecrypt_AES128Decrypt_E_NOT_OK (1U)

#  define RTE_E_CsmDecrypt_AES128DecryptWithPadding_CSM_E_BUSY (2U)

#  define RTE_E_CsmDecrypt_AES128DecryptWithPadding_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmDecrypt_AES128DecryptWithPadding_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmDecrypt_AES128DecryptWithPadding_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmDecrypt_AES128DecryptWithPadding_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmDecrypt_AES128DecryptWithPadding_E_NOT_OK (1U)

#  define RTE_E_CsmJobKeyExchangeCalcPubVal_CSM_E_BUSY (2U)

#  define RTE_E_CsmJobKeyExchangeCalcPubVal_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmJobKeyExchangeCalcPubVal_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmJobKeyExchangeCalcPubVal_E_NOT_OK (1U)

#  define RTE_E_CsmJobKeyExchangeCalcSecret_CSM_E_BUSY (2U)

#  define RTE_E_CsmJobKeyExchangeCalcSecret_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmJobKeyExchangeCalcSecret_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmJobKeyExchangeCalcSecret_E_NOT_OK (1U)

#  define RTE_E_CsmJobKeyGenerate_CSM_E_BUSY (2U)

#  define RTE_E_CsmJobKeyGenerate_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmJobKeyGenerate_E_NOT_OK (1U)

#  define RTE_E_CsmJobRandomSeed_CSM_E_BUSY (2U)

#  define RTE_E_CsmJobRandomSeed_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_AesRamKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_AesRamKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_AesRamKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_AesRamKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_AesRamKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_AesRamKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_BackendCert_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_BackendCert_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_BackendCert_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_BackendCert_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_BackendCert_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_BackendCert_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_RandomSeed_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_RandomSeed_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_RootCert_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_RootCert_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_RootCert_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_RootCert_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_RootCert_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_RootCert_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretHash_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretHash_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretHash_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretHash_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretHash_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretHash_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretHash_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretHash_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretKeyExchange_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretKeyExchange_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretKeyExchange_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretKeyExchange_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretKeyExchange_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretKeyExchange_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretKeyExchange_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_SharedSecretKeyExchange_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_SigPubKey_ReplacementAuthority_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_SigPubKey_ReplacementAuthority_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_SigPubKey_ReplacementAuthority_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_SigPubKey_ReplacementAuthority_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_SigPubKey_ReplacementAuthority_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_SigPubKey_ReplacementAuthority_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPrivateKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPrivateKey_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPrivateKey_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPrivateKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPrivateKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPrivateKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPrivateKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPublicKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPublicKey_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPublicKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPublicKey_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPublicKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPublicKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPublicKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuCsrPublicKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuLivePrivateKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuLivePrivateKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuLivePublicKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuLivePublicKey_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuLivePublicKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuLivePublicKey_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuLivePublicKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuLivePublicKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPrivateKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPrivateKey_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPrivateKey_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPrivateKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPrivateKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPrivateKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPrivateKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPublicKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPublicKey_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPublicKey_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPublicKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPublicKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPublicKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelEcuStagingPublicKey_E_NOT_OK (1U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelTempPublicKey_CSM_E_BUSY (2U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelTempPublicKey_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelTempPublicKey_CSM_E_KEY_NOT_AVAILABLE (8U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelTempPublicKey_CSM_E_KEY_READ_FAIL (6U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelTempPublicKey_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelTempPublicKey_CSM_E_KEY_WRITE_FAIL (7U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelTempPublicKey_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmKeyManagement_Ssa_TrustModelTempPublicKey_E_NOT_OK (1U)

#  define RTE_E_CsmMacGenerate_MacGenAesCmac_CSM_E_BUSY (2U)

#  define RTE_E_CsmMacGenerate_MacGenAesCmac_CSM_E_KEY_EMPTY (13U)

#  define RTE_E_CsmMacGenerate_MacGenAesCmac_CSM_E_KEY_NOT_VALID (9U)

#  define RTE_E_CsmMacGenerate_MacGenAesCmac_CSM_E_KEY_SIZE_MISMATCH (10U)

#  define RTE_E_CsmMacGenerate_MacGenAesCmac_CSM_E_SMALL_BUFFER (3U)

#  define RTE_E_CsmMacGenerate_MacGenAesCmac_E_NOT_OK (1U)

#  define RTE_E_CsmRandomGenerate_Random_CSM_E_BUSY (2U)

#  define RTE_E_CsmRandomGenerate_Random_CSM_E_ENTROPY_EXHAUSTION (4U)

#  define RTE_E_CsmRandomGenerate_Random_E_NOT_OK (1U)

#  define RTE_E_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_E_NOT_OK (1U)

#  define RTE_E_DataServices_Backend_CA_Certificate_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Backend_CA_Certificate_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0198_Root_Replacement_Key_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0198_Root_Replacement_Key_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK (1U)

#  define RTE_E_DataServices_Root_CA_Certificate_Read_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Root_CA_Certificate_Read_E_NOT_OK (1U)

#  define RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_E_NOT_OK (1U)

#  define RTE_E_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_SerialNo_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_SerialNo_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_SerialNo_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_SerialNo_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_SerialNo_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_SerialNo_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_SerialNo_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_SerialNo_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_SerialNo_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_SerialNo_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_SerialNo_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_SerialNo_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_SerialNo_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_SerialNo_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_SerialNo_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_KEYM_E_KEY_CERT_INVALID (6U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelBackendCert_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelBackendPeerCert_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuCert_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuCert_KEYM_E_BUSY (2U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuCert_KEYM_E_CERT_INVALID_CHAIN_OF_TRUST (11U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuCert_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuCert_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuCert_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuPeerCert_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuPeerCert_KEYM_E_BUSY (2U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuPeerCert_KEYM_E_CERT_INVALID_CHAIN_OF_TRUST (11U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuPeerCert_KEYM_E_KEY_CERT_EMPTY (10U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuPeerCert_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelEcuPeerCert_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelIntermediateCert_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelIntermediatePeerCert_E_NOT_OK (1U)

#  define RTE_E_KeyMCertificate_Ssa_TrustModelRootCert_E_NOT_OK (1U)

#  define RTE_E_KeyM_Certificate_E_NOT_OK (1U)

#  define RTE_E_KeyM_Certificate_E_PENDING (10U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_RightsM_DiagnosticChannel_E_NOT_OK (1U)

#  define RTE_E_RightsM_EnhancedRights_E_NOT_OK (1U)

#  define RTE_E_RightsM_Nonce_E_INVALID (3U)

#  define RTE_E_RightsM_Nonce_E_NOT_OK (1U)

#  define RTE_E_RightsM_Nonce_E_PENDING (10U)

#  define RTE_E_RoutineServices_Get_Certificate_Entry_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Get_Certificate_Entry_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Get_Certificate_Entry_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Inject_Seed_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Inject_Seed_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Inject_Seed_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Certificates_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Certificate_Self_Check_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Replace_Certificates_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_E_NOT_OK (1U)

#  define RTE_E_SecLog_FailedCertVerificationEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SuccessfulCertVerificationEvent_E_NOT_OK (1U)

#  define RTE_E_SecLog_SuccessfulDiagServiceExecutionEvent_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_CryptoInterface_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY (2U)

#  define RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_E_NOT_OK (1U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_BUSY (2U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_CERT_INVALID_CHAIN_OF_TRUST (9U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_EMPTY (8U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_READ_FAIL (7U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_SIZE_MISMATCH (4U)

#  define RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_PARAMETER_MISMATCH (5U)

#  define RTE_E_Ssa_KeyProc_E_NOT_OK (1U)

#  define RTE_E_Ssa_KeyProc_E_PENDING (2U)

#  define RTE_E_Ssa_KeyStorage_E_NOT_OK (1U)

#  define RTE_E_Ssa_KeyStorage_E_PENDING (2U)

#  define RTE_E_Ssa_VeDocRelevantInfo_E_NOT_OK (1U)

#  define RTE_E_TimeM_RealTime_E_NOT_OK (1U)

#  define RTE_E_TimeM_TimeRawData_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_KEYM_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
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
