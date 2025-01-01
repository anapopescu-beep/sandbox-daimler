/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Ssa_Types.h
 *    Component:  Security_AsrSwcSsa_Daimler
 *       Module:  Ssa
 *    Generator:  -
 *
 *  Description:  Types of the Standard Security Architecture
 *
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#if !defined (SSA_TYPES_H)
# define SSA_TYPES_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Generic Verification Result Successful */
# define SSA_VER_RES_SUCCESSFUL                                                                                               (0X00u)

/*! Verification Results for diagnostic routine control service Authenticate Diagnostic User or Tester */
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY                                       SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_AUTHENTICATE_OWNERSHIP_VERIFIED_AUTHENTICATION_COMPLETE                                                  (0X01u)
# define SSA_VER_RES_AUTHENTICATE_DEAUTHENTICATION_SUCCESSFUL                                                                 (0X02u)
# define SSA_VER_RES_AUTHENTICATE_OWNERSHIP_VERIFIED_AUTHENTICATION_COMPLETE_CENTRAL_AUTHENTICATION_BROADCAST_TRIGGERED       (0X03u)
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFIED_TIME_SET                                                               (0X04u)
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                                         (0X10u)
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                                           (0X11u)
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                                      (0X12u)
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                                                (0X13u)
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                                              (0X14u)
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                                             (0X15u)
# define SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                                               (0X16u)
# define SSA_VER_RES_AUTHENTICATE_OWNERSHIP_VERIFICATION_FAILED                                                               (0X20u)
# define SSA_VER_RES_AUTHENTICATE_DEAUTHENTICATION_FAILED                                                                     (0X30u)
# define SSA_VER_RES_AUTHENTICATE_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED                                                  (0X40u)

/*! Verification Results for diagnostic service Authentication S29 */
# define SSA_VER_RES_AUTH_S29_REQUEST_ACCEPTED                                                                                SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_AUTH_S29_GENERAL_REJECT                                                                                  (0x01u)
# define SSA_VER_RES_AUTH_S29_AUTHENTICATION_CONFIGURATION_APCE                                                               (0x02u)
# define SSA_VER_RES_AUTH_S29_AUTHENTICATION_CONFIGURATION_ACR_WITH_ASYMMETRIC_CRYPTOGRAPHY                                   (0x03u)
# define SSA_VER_RES_AUTH_S29_AUTHENTICATION_CONFIGURATION_ACR_WITH_SYMMETRIC_CRYPTOGRAPHY                                    (0x04u)
# define SSA_VER_RES_AUTH_S29_DEAUTHENTICATION_SUCCESSFUL                                                                     (0x10u)
# define SSA_VER_RES_AUTH_S29_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY                                           (0x11u)
# define SSA_VER_RES_AUTH_S29_OWNERSHIP_VERIFIED_AUTHENTICATION_COMPLETE                                                      (0x12u)
# define SSA_VER_RES_AUTH_S29_CERTIFICATE_VERIFIED                                                                            (0x13u)
# define SSA_VER_RES_AUTH_S29_CHALLENGE_CALCULATION_FAILED                                                                    (0x31u)
# define SSA_VER_RES_AUTH_S29_SETTING_ACCESS_RIGHTS_FAILED                                                                    (0x32u)
# define SSA_VER_RES_AUTH_S29_SESSION_KEY_CREATION_DERIVATION_FAILED                                                          (0x33u)
# define SSA_VER_RES_AUTH_S29_CONFIGURATION_DATA_USAGE_FAILED                                                                 (0x34u)

/*! NRCs for Service 0x29 */
# define SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                                           (0x50u)
# define SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                                             (0x51u)
# define SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                                        (0x52u)
# define SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                                                  (0x53u)
# define SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                                                (0x54u)
# define SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                                               (0x55u)
# define SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                                                 (0x56u)
# define SSA_DCM_E_NRC_AUTH_S29_OWNERSHIP_VERIFICATION_FAILED                                                                 (0x58u)
# define SSA_DCM_E_NRC_AUTH_S29_DEAUTHENTICATION_FAILED                                                                       (0x5Du)

/*! Verification Results for diagnostic routine control service Enhance Access Rights */
# define SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFIFED_ACCESS_RIGHTS_ENHANCED                                       SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                                (0x10u)
# define SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                                  (0x11u)
# define SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                             (0x12u)
# define SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                                       (0x13u)
# define SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                                     (0x14u)
# define SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                                    (0x15u)
# define SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                                      (0x16u)

/*! Verification Results for diagnostic routine control service Certificate Self Check */
# define SSA_VER_RES_CERTSELFCHECK_VERIFICATION_SUCCESSFUL                                                                    SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_CERTSELFCHECK_PRIVATEKEY_IS_NOT_ACCESSIBLE                                                               (0x01u)
# define SSA_VER_RES_CERTSELFCHECK_ECU_CERTIFICATE_IS_NOT_ACCESSIBLE_OR_IS_INVALID                                            (0x02u)
# define SSA_VER_RES_CERTSELFCHECK_BACKEND_CERTIFICATE_IS_NOT_ACCESSIBLE_OR_IS_INVALID                                        (0x03u)
# define SSA_VER_RES_CERTSELFCHECK_ROOT_CERTIFICATE_IS_NOT_ACCESSIBLE_OR_IS_INVALID                                           (0x04u)
# define SSA_VER_RES_CERTSELFCHECK_ECU_CERTIFICATE_PRIVATE_KEY_DO_NOT_MATCH                                                   (0x05u)
# define SSA_VER_RES_CERTSELFCHECK_ECU_CERTIFICATE_CANNOT_BE_VERIFIED_BY_BACKEND_CERTIFICATE                                  (0x06u)
# define SSA_VER_RES_CERTSELFCHECK_BACKEND_CERTIFICATE_CANNOT_BE_VERIFIED_BY_ROOT_CERTIFICATE                                 (0x07u)
# define SSA_VER_RES_CERTSELFCHECK_PRIVATEKEY_SELF_SIGNED_IS_NOT_ACCESSIBLE                                                   (0x08u)
# define SSA_VER_RES_CERTSELFCHECK_ECU_CERTIFICATE_SELF_SIGNED_IS_NOT_ACCESSIBLE_OR_IS_INVALID                                (0x09u)
# define SSA_VER_RES_CERTSELFCHECK_TRUST_MODEL_ECU_CERTIFICATE_IS_NOT_ACCESSIBLE_OR_IS_INVALID                                (0x0Au)
# define SSA_VER_RES_CERTSELFCHECK_TRUST_MODEL_INTERMEDIATE_CERTIFICATE_IS_NOT_ACCESSIBLE_OR_IS_INVALID                       (0x0Bu)
# define SSA_VER_RES_CERTSELFCHECK_TRUST_MODEL_BACKEND_CERTIFICATE_IS_NOT_ACCESSIBLE_OR_IS_INVALID                            (0x0Cu)
# define SSA_VER_RES_CERTSELFCHECK_TRUST_MODEL_ROOT_CERTIFICATE_IS_NOT_ACCESSIBLE_OR_IS_INVALID                               (0x0Du)
# define SSA_VER_RES_CERTSELFCHECK_ECU_CERTIFICATE_SELF_SIGNED_PRIVATE_KEY_DO_NOT_MATCH                                       (0x0Eu)
# define SSA_VER_RES_CERTSELFCHECK_TRUST_MODEL_ECU_CERTIFICATE_PRIVATE_KEY_DO_NOT_MATCH                                       (0x0Fu)
# define SSA_VER_RES_CERTSELFCHECK_TRUST_MODEL_ECU_CERTIFICATE_CANNOT_BE_VERIFIED_BY_TRUST_MODEL_INTERMEDIATE_CERTIFICATE     (0x10u)
# define SSA_VER_RES_CERTSELFCHECK_TRUST_MODEL_INTERMEDIATE_CERTIFICATE_CANNOT_BE_VERIFIED_BY_TRUST_MODEL_BACKEND_CERTIFICATE (0x11u)
# define SSA_VER_RES_CERTSELFCHECK_TRUST_MODEL_BACKEND_CERTIFICATE_CANNOT_BE_VERIFIED_BY_TRUST_MODEL_ROOT_CERTIFICATE         (0x12u)

/*! Verification Results for diagnostic routine control service Replace Trust Model Certificates */
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_CERTIFICATES_VERIFIED_AND_REPLACED                                             SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                        (0x10u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                          (0x11u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                     (0x12u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                               (0x13u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                             (0x14u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                            (0x15u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                              (0x16u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_PRIVATEKEY_ECU_INVALID                                                         (0x20u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                    (0x30u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                      (0x31u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                 (0x32u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                           (0x33u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                         (0x34u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                        (0x35u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                          (0x36u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD               (0x40u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                 (0x41u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST            (0x42u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                      (0x43u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                    (0x44u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                   (0x45u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_CERTS_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                     (0x46u)

/*! Verification Results for diagnostic routine control service Replace Trust Model Root Certificate */
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_CERTIFICATE_VERIFIED_AND_REPLACED                                          SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                        (0x10u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                          (0x11u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                     (0x12u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                               (0x13u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                             (0x14u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                            (0x15u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                              (0x16u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_ENHANCED_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD        (0x20u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_ENHANCED_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE          (0x21u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_ENHANCED_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST     (0x22u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_ENHANCED_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE               (0x23u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_ENHANCED_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT             (0x24u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_ENHANCED_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT            (0x25u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_ENHANCED_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE              (0x26u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_REPLACEMENT_PACKAGE_INVALID_SIGNATURE                                      (0x30u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_EXISTING_ROOT_CERT_INVALID_STATE                                           (0x40u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_NO_RIGHTS_TO_PROCEED_FOR_THIS_ECU                                          (0x50u)
# define SSA_VER_RES_TRUST_MODEL_REPLACE_ROOT_CERT_NEW_ROOT_INVALID_SIGNATURE                                                 (0x60u)

/*! Verification Results for diagnostic routine control service Trust Model SecOC ECU Shared Secret Distribution */
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_CERTIFICATE_VERIFIED_SECOC_KEY_CALCULATED                                  SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                    (0x10u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                      (0x11u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                 (0x12u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                           (0x13u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                         (0x14u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                        (0x15u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                          (0x16u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_SECOC_KEY_GENERATION_FAILED                                                (0x20u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INVALID_ENCR_NONCE_OR_SHARED_SECRET                                        (0x30u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INVALID_DATA_SIGNATURE                                                     (0x40u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_TARGET_SKID_FROM_ENH_RIGHTS_UNEQUAL_TRUST_MODEL_VSM_CERTIFICATE_SKID       (0x41u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_TIME_SYNCHRONIZATION_FAILED                                                (0x50u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                (0x70u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                  (0x71u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST             (0x72u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                       (0x73u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                     (0x74u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                    (0x75u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                      (0x76u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD           (0x80u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE             (0x81u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST        (0x82u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                  (0x83u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                (0x84u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT               (0x85u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_DISTRIB_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                 (0x86u)

/*! Verification Results for diagnostic routine control service SecOC ECU Shared Secret Encryption
 *                                                              SecOC ECU TickCount Synchronization
 *                                                              Trust Model SecOC ECU Shared Secret Encryption and
 *                                                              Trust Model SecOC ECU TickCount Synchronization */
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_CERTIFICATE_VERIFIED_SECOC_KEY_CALCULATED                                  SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                    (0x10u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                      (0x11u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                 (0x12u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                           (0x13u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                         (0x14u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                        (0x15u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_ECU_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                          (0x16u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_GENERATION_OF_CAR_SPECIFIC_SECRET_FAILED                                   (0x20u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_NO_RIGHTS_TO_PROCEED_FOR_THIS_ECU                                          (0x30u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_TARGETVIN_UNEQUAL_LOCALVIN                                                 (0x31u) /*!< unused */
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_SIGNATURE_VERIFICATION_FAILED                                              (0x40u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                (0x70u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                  (0x71u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST             (0x72u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                       (0x73u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                     (0x74u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                    (0x75u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_BACKEND_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                      (0x76u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD           (0x80u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE             (0x81u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST        (0x82u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                  (0x83u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                (0x84u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT               (0x85u)
# define SSA_VER_RES_TRUST_MODEL_SECOC_CSS_ENCRYPT_INTERMEDIATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                 (0x86u)

/*! Verification Results for diagnostic routine control service Trust Model Generate Key Pair */
# define SSA_VER_RES_TRUST_MODEL_GENERATE_KEY_PAIR_SUCCESSFUL                                                                 SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_TRUST_MODEL_GENERATE_KEY_PAIR_COULD_NOT_CREATE_KEY_PAIR                                                  (0x10u)

/*! Verification Results for diagnostic routine control service Inject Seed */
# define SSA_VER_RES_INJECT_SEED_SUCCESSFULLY_SEEDED                                                                          SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_INJECT_SEED_INVALID_NONCE                                                                                (0x10u)
# define SSA_VER_RES_INJECT_SEED_INVALID_DATA_SIGNATURE                                                                       (0x20u)

/*! Verification Results for diagnostic routine control service Get Certificate Entry */
# define SSA_VER_RES_GET_CERTIFICATE_ENTRY_SUCCESSFULLY_READ                                                                  SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_GET_CERTIFICATE_ENTRY_CERTIFICATE_NOT_FOUND                                                              (0x01u)
# define SSA_VER_RES_GET_CERTIFICATE_ENTRY_CERTIFICATE_INVALID                                                                (0x02u)
# define SSA_VER_RES_GET_CERTIFICATE_ENTRY_ENTRY_IN_CERTIFICATE_NOT_AVAILABLE                                                 (0x03u)

/*! Verification Results for diagnostic routine control service Evaluate Data Verification Certificate */
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_CERTIFICATE_VERIFIED_SIGNATURE_VERIFICATION_KEY_ACCEPTED                            SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD                                 (0x10u)
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE                                   (0x11u)
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST                              (0x12u)
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE                                        (0x13u)
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT                                      (0x14u)
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT                                     (0x15u)
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE                                       (0x16u)
# define SSA_VER_RES_EVAL_DATA_VERIF_CERT_FAILED_TO_SYNCHRONIZE_TO_NON_VOLATILE_MEMORY                                        (0x20u) /*!< extension */

/*! Verification Results for diagnostic routine control service Verify Signature */
# define SSA_VER_RES_VERIFY_SIGNATURE_SIGNATURE_VERIFICATION_SUCCESSFUL                                                       SSA_VER_RES_SUCCESSFUL
# define SSA_VER_RES_VERIFY_SIGNATURE_SIGNATURE_VERIFICATION_FAILED_INVALID_SIGNATURE                                         (0x10u)
# define SSA_VER_RES_VERIFY_SIGNATURE_SIGNATURE_VERIFICATION_FAILED_NO_SIGNATURE_VERIFICATION_KEY_AVAILABLE                   (0x11u)
# define SSA_VER_RES_VERIFY_SIGNATURE_FAILED_TO_SYNCHRONIZE_TO_NON_VOLATILE_MEMORY                                            (0x20u)

#endif /* SSA_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Ssa_Types.h
 *********************************************************************************************************************/
