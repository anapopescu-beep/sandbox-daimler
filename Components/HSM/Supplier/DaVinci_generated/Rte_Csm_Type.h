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
 *             File:  Rte_Csm_Type.h
 *           Config:  vHsmConfig.dpa
 *      ECU-Project:  vHsmConfig
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200336
 *
 *      Description:  Application types header file for SW-C <Csm>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CSM_TYPE_H
# define RTE_CSM_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

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

#  ifndef E_NOT_OK
#   define E_NOT_OK (1U)
#  endif

#  ifndef CRYPTO_E_BUSY
#   define CRYPTO_E_BUSY (2U)
#  endif

#  ifndef CRYPTO_E_ENTROPY_EXHAUSTED
#   define CRYPTO_E_ENTROPY_EXHAUSTED (4U)
#  endif

#  ifndef CRYPTO_E_KEY_READ_FAIL
#   define CRYPTO_E_KEY_READ_FAIL (6U)
#  endif

#  ifndef CRYPTO_E_KEY_WRITE_FAIL
#   define CRYPTO_E_KEY_WRITE_FAIL (7U)
#  endif

#  ifndef CRYPTO_E_KEY_NOT_AVAILABLE
#   define CRYPTO_E_KEY_NOT_AVAILABLE (8U)
#  endif

#  ifndef CRYPTO_E_KEY_NOT_VALID
#   define CRYPTO_E_KEY_NOT_VALID (9U)
#  endif

#  ifndef CRYPTO_E_KEY_SIZE_MISMATCH
#   define CRYPTO_E_KEY_SIZE_MISMATCH (10U)
#  endif

#  ifndef CRYPTO_E_JOB_CANCELED
#   define CRYPTO_E_JOB_CANCELED (12U)
#  endif

#  ifndef CRYPTO_E_KEY_EMPTY
#   define CRYPTO_E_KEY_EMPTY (13U)
#  endif

#  ifndef CRYPTO_E_VER_OK
#   define CRYPTO_E_VER_OK (0U)
#  endif

#  ifndef CRYPTO_E_VER_NOT_OK
#   define CRYPTO_E_VER_NOT_OK (1U)
#  endif

#  ifndef CRYPTO_KE_MAC_KEY
#   define CRYPTO_KE_MAC_KEY (1U)
#  endif

#  ifndef CRYPTO_KE_MAC_PROOF
#   define CRYPTO_KE_MAC_PROOF (2U)
#  endif

#  ifndef CRYPTO_KE_SIGNATURE_KEY
#   define CRYPTO_KE_SIGNATURE_KEY (1U)
#  endif

#  ifndef CRYPTO_KE_SIGNATURE_CURVETYPE
#   define CRYPTO_KE_SIGNATURE_CURVETYPE (29U)
#  endif

#  ifndef CRYPTO_KE_RANDOM_SEED_STATE
#   define CRYPTO_KE_RANDOM_SEED_STATE (3U)
#  endif

#  ifndef CRYPTO_KE_RANDOM_ALGORITHM
#   define CRYPTO_KE_RANDOM_ALGORITHM (4U)
#  endif

#  ifndef CRYPTO_KE_CIPHER_KEY
#   define CRYPTO_KE_CIPHER_KEY (1U)
#  endif

#  ifndef CRYPTO_KE_CIPHER_IV
#   define CRYPTO_KE_CIPHER_IV (5U)
#  endif

#  ifndef CRYPTO_KE_CIPHER_PROOF
#   define CRYPTO_KE_CIPHER_PROOF (6U)
#  endif

#  ifndef CRYPTO_KE_CIPHER_2NDKEY
#   define CRYPTO_KE_CIPHER_2NDKEY (7U)
#  endif

#  ifndef CRYPTO_KE_KEYEXCHANGE_BASE
#   define CRYPTO_KE_KEYEXCHANGE_BASE (8U)
#  endif

#  ifndef CRYPTO_KE_KEYEXCHANGE_PRIVKEY
#   define CRYPTO_KE_KEYEXCHANGE_PRIVKEY (9U)
#  endif

#  ifndef CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY
#   define CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY (10U)
#  endif

#  ifndef CRYPTO_KE_KEYEXCHANGE_SHAREDVALUE
#   define CRYPTO_KE_KEYEXCHANGE_SHAREDVALUE (1U)
#  endif

#  ifndef CYRPTO_KE_KEYEXCHANGE_SHAREDVALUE
#   define CYRPTO_KE_KEYEXCHANGE_SHAREDVALUE (1U)
#  endif

#  ifndef CRYPTO_KE_KEYEXCHANGE_ALGORITHM
#   define CRYPTO_KE_KEYEXCHANGE_ALGORITHM (12U)
#  endif

#  ifndef CRYPTO_KE_KEYEXCHANGE_CURVETYPE
#   define CRYPTO_KE_KEYEXCHANGE_CURVETYPE (29U)
#  endif

#  ifndef CRYPTO_KE_KEYDERIVATION_PASSWORD
#   define CRYPTO_KE_KEYDERIVATION_PASSWORD (1U)
#  endif

#  ifndef CRYPTO_KE_KEYDERIVATION_SALT
#   define CRYPTO_KE_KEYDERIVATION_SALT (13U)
#  endif

#  ifndef CRYPTO_KE_KEYDERIVATION_ITERATIONS
#   define CRYPTO_KE_KEYDERIVATION_ITERATIONS (14U)
#  endif

#  ifndef CRYPTO_KE_KEYDERIVATION_ALGORITHM
#   define CRYPTO_KE_KEYDERIVATION_ALGORITHM (15U)
#  endif

#  ifndef CRYPTO_KE_KEYDERIVATION_CURVETYPE
#   define CRYPTO_KE_KEYDERIVATION_CURVETYPE (29U)
#  endif

#  ifndef CRYPTO_KE_KEYGENERATE_KEY
#   define CRYPTO_KE_KEYGENERATE_KEY (1U)
#  endif

#  ifndef CRYPTO_KE_KEYGENERATE_SEED
#   define CRYPTO_KE_KEYGENERATE_SEED (16U)
#  endif

#  ifndef CRYPTO_KE_KEYGENERATE_ALGORITHM
#   define CRYPTO_KE_KEYGENERATE_ALGORITHM (17U)
#  endif

#  ifndef CRYPTO_KE_KEYGENERATE_CURVETYPE
#   define CRYPTO_KE_KEYGENERATE_CURVETYPE (29U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_DATA
#   define CRYPTO_KE_CERTIFICATE_DATA (0U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_PARSING_FORMAT
#   define CRYPTO_KE_CERTIFICATE_PARSING_FORMAT (18U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_CURRENT_TIME
#   define CRYPTO_KE_CERTIFICATE_CURRENT_TIME (19U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_VERSION
#   define CRYPTO_KE_CERTIFICATE_VERSION (20U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_SERIALNUMBER
#   define CRYPTO_KE_CERTIFICATE_SERIALNUMBER (21U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_SIGNATURE_ALGORITHM
#   define CRYPTO_KE_CERTIFICATE_SIGNATURE_ALGORITHM (22U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_ISSUER
#   define CRYPTO_KE_CERTIFICATE_ISSUER (23U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE
#   define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE (24U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER
#   define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER (25U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_SUBJECT
#   define CRYPTO_KE_CERTIFICATE_SUBJECT (26U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY
#   define CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY (1U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_EXTENSIONS
#   define CRYPTO_KE_CERTIFICATE_EXTENSIONS (27U)
#  endif

#  ifndef CRYPTO_KE_CERTIFICATE_SIGNATURE
#   define CRYPTO_KE_CERTIFICATE_SIGNATURE (28U)
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
#   define E_KEY_NOT_AVAILABLE (5U)
#  endif

#  ifndef E_KEY_NOT_VALID
#   define E_KEY_NOT_VALID (6U)
#  endif

#  ifndef E_JOB_CANCELED
#   define E_JOB_CANCELED (7U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CSM_TYPE_H */
