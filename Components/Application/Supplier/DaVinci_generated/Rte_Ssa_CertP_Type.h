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
 *             File:  Rte_Ssa_CertP_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <Ssa_CertP>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SSA_CERTP_TYPE_H
# define RTE_SSA_CERTP_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef CERTP_PKI_ROLE_ROOT
#   define CERTP_PKI_ROLE_ROOT (1U)
#  endif

#  ifndef CERTP_PKI_ROLE_BACKEND
#   define CERTP_PKI_ROLE_BACKEND (2U)
#  endif

#  ifndef CERTP_PKI_ROLE_TESTER
#   define CERTP_PKI_ROLE_TESTER (3U)
#  endif

#  ifndef CERTP_PKI_ROLE_ECU
#   define CERTP_PKI_ROLE_ECU (4U)
#  endif

#  ifndef CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS
#   define CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS (5U)
#  endif

#  ifndef CERTP_PKI_ROLE_VARIANT_CODING
#   define CERTP_PKI_ROLE_VARIANT_CODING (7U)
#  endif

#  ifndef CERTP_PKI_ROLE_USER_CERT_FOR_CODING
#   define CERTP_PKI_ROLE_USER_CERT_FOR_CODING (9U)
#  endif

#  ifndef CERTP_PKI_ROLE_ROOT_CA_LINK_CERT
#   define CERTP_PKI_ROLE_ROOT_CA_LINK_CERT (10U)
#  endif

#  ifndef CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT
#   define CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT (11U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA
#   define CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA (12U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA
#   define CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA (13U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA
#   define CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA (14U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_ECU
#   define CERTP_PKI_ROLE_TRUST_MODEL_ECU (15U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA_LINK
#   define CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA_LINK (16U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA_LINK
#   define CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA_LINK (17U)
#  endif

#  ifndef CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA_LINK
#   define CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA_LINK (18U)
#  endif

#  ifndef CERTP_PKI_ROLE_PQC_ROOT_CA
#   define CERTP_PKI_ROLE_PQC_ROOT_CA (19U)
#  endif

#  ifndef CERTP_PKI_ROLE_PQC_BACKEND_CA
#   define CERTP_PKI_ROLE_PQC_BACKEND_CA (20U)
#  endif

#  ifndef CERTP_PKI_ROLE_PQC_TESTER
#   define CERTP_PKI_ROLE_PQC_TESTER (21U)
#  endif

#  ifndef CERTP_PKI_ROLE_PQC_ECU
#   define CERTP_PKI_ROLE_PQC_ECU (22U)
#  endif

#  ifndef CERTP_PKI_ROLE_INVALID
#   define CERTP_PKI_ROLE_INVALID (0U)
#  endif

#  ifndef CERTP_VER_OK
#   define CERTP_VER_OK (0U)
#  endif

#  ifndef CERTP_VER_INVALID_TIME_PERIOD
#   define CERTP_VER_INVALID_TIME_PERIOD (16U)
#  endif

#  ifndef CERTP_VER_INVALID_SIGNATURE
#   define CERTP_VER_INVALID_SIGNATURE (17U)
#  endif

#  ifndef CERTP_VER_INVALID_CHAIN_OF_TRUST
#   define CERTP_VER_INVALID_CHAIN_OF_TRUST (18U)
#  endif

#  ifndef CERTP_VER_INVALID_TYPE
#   define CERTP_VER_INVALID_TYPE (19U)
#  endif

#  ifndef CERTP_VER_INVALID_FORMAT
#   define CERTP_VER_INVALID_FORMAT (20U)
#  endif

#  ifndef CERTP_VER_INVALID_CONTENT
#   define CERTP_VER_INVALID_CONTENT (21U)
#  endif

#  ifndef CERTP_VER_INVALID_SCOPE
#   define CERTP_VER_INVALID_SCOPE (22U)
#  endif

#  ifndef CERTP_VER_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED
#   define CERTP_VER_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED (64U)
#  endif

#  ifndef CERTP_VER_PARSE_OK
#   define CERTP_VER_PARSE_OK (253U)
#  endif

#  ifndef CERTP_VER_PARSE_FAILED
#   define CERTP_VER_PARSE_FAILED (254U)
#  endif

#  ifndef CERTP_VER_NOT_PARSED
#   define CERTP_VER_NOT_PARSED (255U)
#  endif

#  ifndef CRYPTO_OPERATIONMODE_START
#   define CRYPTO_OPERATIONMODE_START (1U)
#  endif

#  ifndef CRYPTO_OPERATIONMODE_UPDATE
#   define CRYPTO_OPERATIONMODE_UPDATE (2U)
#  endif

#  ifndef CRYPTO_OPERATIONMODE_STREAMSTART
#   define CRYPTO_OPERATIONMODE_STREAMSTART (3U)
#  endif

#  ifndef CRYPTO_OPERATIONMODE_FINISH
#   define CRYPTO_OPERATIONMODE_FINISH (4U)
#  endif

#  ifndef CRYPTO_OPERATIONMODE_SINGLECALL
#   define CRYPTO_OPERATIONMODE_SINGLECALL (7U)
#  endif

#  ifndef CRYPTO_E_VER_OK
#   define CRYPTO_E_VER_OK (0U)
#  endif

#  ifndef CRYPTO_E_VER_NOT_OK
#   define CRYPTO_E_VER_NOT_OK (1U)
#  endif

#  ifndef E_NOT_OK
#   define E_NOT_OK (1U)
#  endif

#  ifndef E_SMALL_BUFFER
#   define E_SMALL_BUFFER (2U)
#  endif

#  ifndef E_ENTROPY_EXHAUSTION
#   define E_ENTROPY_EXHAUSTION (3U)
#  endif

#  ifndef E_KEY_READ_FAIL
#   define E_KEY_READ_FAIL (4U)
#  endif

#  ifndef E_KEY_NOT_AVAILABLE
#   define E_KEY_NOT_AVAILABLE (4U)
#  endif

#  ifndef E_KEY_NOT_VALID
#   define E_KEY_NOT_VALID (6U)
#  endif

#  ifndef E_JOB_CANCELED
#   define E_JOB_CANCELED (7U)
#  endif

#  ifndef E_KEY_EMPTY
#   define E_KEY_EMPTY (8U)
#  endif

#  ifndef RIGHTSM_USERROLE_ANYBODY
#   define RIGHTSM_USERROLE_ANYBODY (0U)
#  endif

#  ifndef RIGHTSM_USERROLE_SUPPLIER
#   define RIGHTSM_USERROLE_SUPPLIER (1U)
#  endif

#  ifndef RIGHTSM_USERROLE_DEV_ENHANCED
#   define RIGHTSM_USERROLE_DEV_ENHANCED (2U)
#  endif

#  ifndef RIGHTSM_USERROLE_PRODUCTION
#   define RIGHTSM_USERROLE_PRODUCTION (3U)
#  endif

#  ifndef RIGHTSM_USERROLE_AS_ENHANCED
#   define RIGHTSM_USERROLE_AS_ENHANCED (4U)
#  endif

#  ifndef RIGHTSM_USERROLE_AS_STANDARD
#   define RIGHTSM_USERROLE_AS_STANDARD (5U)
#  endif

#  ifndef RIGHTSM_USERROLE_AS_BASIC
#   define RIGHTSM_USERROLE_AS_BASIC (6U)
#  endif

#  ifndef RIGHTSM_USERROLE_INT_DIAG_TEST_TOOL
#   define RIGHTSM_USERROLE_INT_DIAG_TEST_TOOL (7U)
#  endif

#  ifndef RIGHTSM_USERROLE_EPTI_TEST_TOOL
#   define RIGHTSM_USERROLE_EPTI_TEST_TOOL (8U)
#  endif

#  ifndef SSA_KE_MAC_KEY
#   define SSA_KE_MAC_KEY (1U)
#  endif

#  ifndef SSA_KE_MAC_PROOF
#   define SSA_KE_MAC_PROOF (2U)
#  endif

#  ifndef SSA_KE_SIGNATURE_KEY
#   define SSA_KE_SIGNATURE_KEY (1U)
#  endif

#  ifndef SSA_KE_RANDOM_SEED_STATE
#   define SSA_KE_RANDOM_SEED_STATE (3U)
#  endif

#  ifndef SSA_KE_RANDOM_ALGORITHM
#   define SSA_KE_RANDOM_ALGORITHM (4U)
#  endif

#  ifndef SSA_KE_CIPHER_KEY
#   define SSA_KE_CIPHER_KEY (1U)
#  endif

#  ifndef SSA_KE_CIPHER_IV
#   define SSA_KE_CIPHER_IV (5U)
#  endif

#  ifndef SSA_KE_CIPHER_PROOF
#   define SSA_KE_CIPHER_PROOF (6U)
#  endif

#  ifndef SSA_KE_CIPHER_2NDKEY
#   define SSA_KE_CIPHER_2NDKEY (7U)
#  endif

#  ifndef SSA_KE_KEYEXCHANGE_BASE
#   define SSA_KE_KEYEXCHANGE_BASE (8U)
#  endif

#  ifndef SSA_KE_KEYEXCHANGE_PRIVKEY
#   define SSA_KE_KEYEXCHANGE_PRIVKEY (9U)
#  endif

#  ifndef SSA_KE_KEYEXCHANGE_OWNPUBKEY
#   define SSA_KE_KEYEXCHANGE_OWNPUBKEY (10U)
#  endif

#  ifndef SSA_KE_KEYEXCHANGE_SHAREDVALUE
#   define SSA_KE_KEYEXCHANGE_SHAREDVALUE (1U)
#  endif

#  ifndef SSA_KE_KEYEXCHANGE_ALGORITHM
#   define SSA_KE_KEYEXCHANGE_ALGORITHM (12U)
#  endif

#  ifndef SSA_KE_KEYDERIVATION_PASSWORD
#   define SSA_KE_KEYDERIVATION_PASSWORD (1U)
#  endif

#  ifndef SSA_KE_KEYDERIVATION_SALT
#   define SSA_KE_KEYDERIVATION_SALT (13U)
#  endif

#  ifndef SSA_KE_KEYDERIVATION_ITERATIONS
#   define SSA_KE_KEYDERIVATION_ITERATIONS (14U)
#  endif

#  ifndef SSA_KE_KEYDERIVATION_ALGORITHM
#   define SSA_KE_KEYDERIVATION_ALGORITHM (15U)
#  endif

#  ifndef SSA_KE_KEYGENERATE_KEY
#   define SSA_KE_KEYGENERATE_KEY (1U)
#  endif

#  ifndef SSA_KE_KEYGENERATE_SEED
#   define SSA_KE_KEYGENERATE_SEED (16U)
#  endif

#  ifndef SSA_KE_KEYGENERATE_ALGORITHM
#   define SSA_KE_KEYGENERATE_ALGORITHM (17U)
#  endif

#  ifndef SSA_KE_CERTIFICATE_DATA
#   define SSA_KE_CERTIFICATE_DATA (0U)
#  endif

#  ifndef TIMEM_IS_GREATER
#   define TIMEM_IS_GREATER (0U)
#  endif

#  ifndef TIMEM_IS_LESS
#   define TIMEM_IS_LESS (1U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SSA_CERTP_TYPE_H */
