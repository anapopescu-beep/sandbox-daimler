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
 *             File:  Rte_KeyM_Type.h
 *           Config:  vHsmConfig.dpa
 *      ECU-Project:  vHsmConfig
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200336
 *
 *      Description:  Application types header file for SW-C <KeyM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_KEYM_TYPE_H
# define RTE_KEYM_TYPE_H

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

#  ifndef KEYM_CSR_ENCODING_NONE
#   define KEYM_CSR_ENCODING_NONE (0U)
#  endif

#  ifndef KEYM_CSR_ENCODING_DER
#   define KEYM_CSR_ENCODING_DER (1U)
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

#  ifndef KEYM_SERVICE_CERT_REQUEST_CSR
#   define KEYM_SERVICE_CERT_REQUEST_CSR (1U)
#  endif

#  ifndef KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR
#   define KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR (2U)
#  endif

#  ifndef KEYM_SERVICE_CERT_SET_ROOT
#   define KEYM_SERVICE_CERT_SET_ROOT (3U)
#  endif

#  ifndef KEYM_SERVICE_CERT_UPDATE_ROOT
#   define KEYM_SERVICE_CERT_UPDATE_ROOT (4U)
#  endif

#  ifndef KEYM_SERVICE_CERT_SET_INTERMEDIATE
#   define KEYM_SERVICE_CERT_SET_INTERMEDIATE (5U)
#  endif

#  ifndef KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE
#   define KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE (6U)
#  endif

#  ifndef KEYM_SERVICE_CERT_UPDATE_CRL
#   define KEYM_SERVICE_CERT_UPDATE_CRL (7U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_KEYM_TYPE_H */
