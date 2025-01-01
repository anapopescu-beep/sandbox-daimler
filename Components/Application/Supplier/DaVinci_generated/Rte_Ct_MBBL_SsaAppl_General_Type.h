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
 *             File:  Rte_Ct_MBBL_SsaAppl_General_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <Ct_MBBL_SsaAppl_General>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CT_MBBL_SSAAPPL_GENERAL_TYPE_H
# define RTE_CT_MBBL_SSAAPPL_GENERAL_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef KEYM_CERTIFICATE_VALID
#   define KEYM_CERTIFICATE_VALID (0U)
#  endif

#  ifndef KEYM_CERTIFICATE_INVALID
#   define KEYM_CERTIFICATE_INVALID (1U)
#  endif

#  ifndef KEYM_CERTIFICATE_NOT_PARSED
#   define KEYM_CERTIFICATE_NOT_PARSED (2U)
#  endif

#  ifndef KEYM_CERTIFICATE_PARSED_NOT_VALIDATED
#   define KEYM_CERTIFICATE_PARSED_NOT_VALIDATED (3U)
#  endif

#  ifndef KEYM_CERTIFICATE_NOT_AVAILABLE
#   define KEYM_CERTIFICATE_NOT_AVAILABLE (4U)
#  endif

#  ifndef KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL
#   define KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL (5U)
#  endif

#  ifndef KEYM_E_CERTIFICATE_SIGNATURE_FAIL
#   define KEYM_E_CERTIFICATE_SIGNATURE_FAIL (6U)
#  endif

#  ifndef KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST
#   define KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST (7U)
#  endif

#  ifndef KEYM_E_CERTIFICATE_INVALID_TYPE
#   define KEYM_E_CERTIFICATE_INVALID_TYPE (8U)
#  endif

#  ifndef KEYM_E_CERTIFICATE_INVALID_FORMAT
#   define KEYM_E_CERTIFICATE_INVALID_FORMAT (9U)
#  endif

#  ifndef KEYM_E_CERTIFICATE_INVALID_CONTENT
#   define KEYM_E_CERTIFICATE_INVALID_CONTENT (10U)
#  endif

#  ifndef KEYM_E_CERTIFICATE_REVOKED
#   define KEYM_E_CERTIFICATE_REVOKED (11U)
#  endif

#  ifndef KEYM_RT_OK
#   define KEYM_RT_OK (0U)
#  endif

#  ifndef KEYM_RT_NOT_OK
#   define KEYM_RT_NOT_OK (1U)
#  endif

#  ifndef KEYM_RT_KEY_CERT_INVALID
#   define KEYM_RT_KEY_CERT_INVALID (2U)
#  endif

#  ifndef KEYM_RT_KEY_CERT_WRITE_FAIL
#   define KEYM_RT_KEY_CERT_WRITE_FAIL (3U)
#  endif

#  ifndef KEYM_RT_KEY_CERT_UPDATE_FAIL
#   define KEYM_RT_KEY_CERT_UPDATE_FAIL (4U)
#  endif

#  ifndef KEYM_RT_CERT_INVALID_CHAIN_OF_TRUST
#   define KEYM_RT_CERT_INVALID_CHAIN_OF_TRUST (5U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  ifndef SSA_KEYSTORAGE_TASK_INITIAL
#   define SSA_KEYSTORAGE_TASK_INITIAL (0U)
#  endif

#  ifndef SSA_KEYSTORAGE_TASK_CHECKSTATE
#   define SSA_KEYSTORAGE_TASK_CHECKSTATE (1U)
#  endif

#  ifndef SSA_KEYSTORAGE_TASK_CANCEL
#   define SSA_KEYSTORAGE_TASK_CANCEL (2U)
#  endif

#  ifndef SSA_KEYSTORAGE_USECASE_CRYPTO
#   define SSA_KEYSTORAGE_USECASE_CRYPTO (0U)
#  endif

#  ifndef SSA_KEYSTORAGE_USECASE_CERTIFICATES
#   define SSA_KEYSTORAGE_USECASE_CERTIFICATES (1U)
#  endif

#  ifndef SSA_KEYSTORAGE_USECASE_TRUST_MODEL_CERTIFICATES
#   define SSA_KEYSTORAGE_USECASE_TRUST_MODEL_CERTIFICATES (2U)
#  endif

#  ifndef SSA_KEYSTORAGE_USECASE_TRUST_MODEL_ROOT_CERTIFICATE
#   define SSA_KEYSTORAGE_USECASE_TRUST_MODEL_ROOT_CERTIFICATE (3U)
#  endif

#  ifndef SSA_KEYSTORAGE_USECASE_RNG_SEED_STATE
#   define SSA_KEYSTORAGE_USECASE_RNG_SEED_STATE (4U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CT_MBBL_SSAAPPL_GENERAL_TYPE_H */
