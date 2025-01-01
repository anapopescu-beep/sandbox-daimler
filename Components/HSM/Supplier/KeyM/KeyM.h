/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  KeyM.h
 *         \unit  *
 *        \brief  KeyM header file
 *      \details  Implementation of AUTOSAR Key Manager
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2019-06-13  vismwe  STORYC-8641   Initial Creation
 *            2019-10-23  visivg  SEC-694       Added support for KeyM_GetCertificate
 *                                SEC-689       Added support for storing and updating certificates
 *                                SEC-696       Added support for verification of certificate chains
 *                                SEC-709       Prepared beta release
 *  01.01.00  2019-11-12  visivg  SEC-683       Support of iterable elements
 *                                ESCAN00104781 ServiceCertificateNotificationCallback is not called
 *                                ESCAN00104848 Parsing information and certificate status are not
 *                                              available after a new startup
 *                                SEC-802       Time Validation with STBM and Callout
 *                                SEC-502       Support NvM interface
 *                                SEC-833       KeyM Support CRL Certificate Type
 *  01.02.00  2020-01-13  visivg  SEC-698       Implement Startup Handling
 *  01.03.00  2020-01-20  visivg  SEC-501       Release of Component
 *  01.04.00  2020-02-27  visivg  SEC-1065      Release of Component Part 2
 *  01.04.01  2020-04-21  visivg  ESCAN00106088 Parsing certificate fails
 *                                ESCAN00106162 Valid certificate status after unsuccessful CSM request
 *  02.00.00  2020-05-07  visivg  SEC-942       Support CSR for EDDSA
 *  02.01.00  2020-05-13  visivg  ESCAN00106369 Unsupported PARSE_AND_TRUST for root certificate
 *                                SEC-940       Extend CSR support for ECDSA and RSA
 *                                SEC-1536      Provide second KeyM_ServiceCertificate API using ID instead of
 *                                              Cert name
 *  02.02.00  2020-06-08  visivg  SEC-1293      KeyM ASN1 parser shall support BMPString tag
 *                                SEC-1089      Support read only certificates
 *                                ESCAN00106686 Update service for working certificates fails
 *                                ESCAN00106687 Update service for CA certificates fails
 *                                ESCAN00106688 Startup handling blocks service request
 *  02.03.00  2020-07-22  visivg  SEC-1573      Dynamic issuer for certificates
 *                                SEC-1682      Certificate Dynamic Slot Mapping
 *                                SEC-1604      Support Generic Certificate Revocation
 *                                SEC-1799      Provide service to access certificate structures
 *                                              Provide service to access issuer certificate identifier
 *                                ESCAN00107181 Parsing of optional certificate elements fails
 *                                ESCAN00107151 Certificates of deferred blocks get persisted only once per ECU reset -
 *                                              Further modifications are lost
 *                                ESCAN00107182 Set and update service for intermediate rejected
 *                                ESCAN00107183 Startup handling for ROM certificates not provided
 *                                ESCAN00107193 Endless loop for invalid certificate length
 *                                ESCAN00107253 Invalid certificate after startup
 *                                ESCAN00107254 Callback notification is not called
 *  02.03.01  2020-07-22  visivg  ESCAN00107396 Compiler error: Usage of certificate revocation entries without
 *                                              certificates with storage type NvM or disabled service certificate
 *                                              function
 *                                ESCAN00107462 Certificate status is not updated after a new certificate revocation
 *                                              entry has been set
 *                                ESCAN00107538 Incorrect certificate status after asynchronous signature verification
 *                                              failure
 *                                ESCAN00107539 Incorrect certificate status after update service request
 *                                ESCAN00107542 Update service request for root certificate fails to set new certificate
 *                                              data
 *                                ESCAN00107540 Certificate subject check fails to notify invalid chain of trust
 *                                ESCAN00107541 Verification for intermediate and working ROM certificates fails
 *  03.00.00  2020-10-16  visivg  SEC-1118      Refactoring function structure
 *                                ESCAN00107646 Undocumented return codes in doxygen description of provided services
 *                                SEC-1818      Ignore certificate extensions that were not set/declared during
 *                                              configuration
 *                                SEC-1723      Add API to provide certificate hash
 *                                ESCAN00107840 Incorrect state machine handling after asynchronous signature
 *                                              verification failure
 *                                ESCAN00107970 Update service request fails for working group certificate
 *  03.01.00  2020-11-24  visivg  SEC-2072      Support synchronous parsing of a certificate
 *                                SEC-1823      Support OCSP Stapling
 *                                SEC-1825
 *                                SEC-1821
 *                                SEC-1974      Support extesionRequest in CSR
 *                                SEC-2373      Support extended reading of certificate elements
 *                                SEC-2397      Support flexible order of extensions
 *                                ESCAN00108493 Reading certificate data from NvM module's mirror to RAM block fails
 *                                ESCAN00108497 Service certificate callback notification is not called for CA update
 *                                              with invalid certificate chain
 *                                ESCAN00108735 Certificate group verification fails for unavailable dynamic
 *                                              optional issuer
 *                                ESCAN00108717 Certificate verify callback notification is not called for
 *                                              KeyM_VerifyCertificateChain() service request
 *                                ESCAN00108882 Dynamic group verification fails for partly dynamic certificate chain
 *                                ESCAN00108883 Parser fails for configured GeneralizedTime certificate element
 *                                ESCAN00108902 Signature verification fails for ECDSA signatures with r- and
 *                                              s-components smaller than max length
 *  03.02.00  2021-04-14  visivg  SEC-1830      Support KeyM to vHsm Adapter
 *                                SEC-1834
 *                                SEC-2590
 *                                SEC-2594
 *                                SEC-2592
 *                                SEC-1832
 *                                SEC-1836
 *                                ESCAN00109458 Overflow error: invalid array assignment in CSR generation
 *                                ESCAN00109466 Initiating a new certificate signing request without module
 *                                              initialization fails
 *                                ESCAN00109585 Startup handling fails to verify all certificates
 *                                ESCAN00109644 Parser does not fail for configured but unparsed mandatory
 *                                              certificate element
 *  03.02.01  2021-07-08  vismxe  SEC-3007      Migrate MISRA metric justifications to start of functions
 *                        visivg  ESCAN00109697 Invalid certificate element data is retrieved
 *  04.00.00  2021-08-13  visivg  SEC-1973      SafeBSW release
 *                        vismxe
 *                        visrpp
 *            2021-08-23  vismxe  SEC-3154      Update KeyM Error Code values according to AUTOSAR R20-11
 *                                ESCAN00109964 Don't allow ServiceCertificateById for ROM certificates
 *                                ESCAN00110062 Prevent endless loop in KeyM_Cert_ChainCpyToDataBuffer()
 *                        vismwe  ESCAN00110282 Revoked certificates can be used after startup due to failing
 *                                              persistence of certificate revocation entries (CRE)
 *            2021-09-22  visivg  ESCAN00110220 CSR generation may return with error or cause read-out-of-bounds
 *                                              for invalid certificate identifier
 *                                ESCAN00110221 Redirection of a remote service request may fail due to invalid
 *                                              certificate or group identifier
 *                                ESCAN00110275 CSR generation returns incorrect error code when Csm_KeyElementGet fails
 *                                ESCAN00110049 Cryptographic operations with Signature Verify might fail on
 *                                              certificates if during KeyM startup handling a certificate is revoked
 *                                ESCAN00110105 Certificates cannot be verified or updated until ECU reboot
 *                                ESCAN00110158 Unexpected OIDs / Read-out-of-bounds when creating a Certificate
 *                                              Signing Request caused by incomplete configuration
 *                                ESCAN00110113 Generation of certificate signing request fails
 *                                ESCAN00110307 Service for retrieving iterable certificate elements by index may
 *                                              return with size mismatch error for sufficiently large certificate
 *                                              element output buffer
 *                                ESCAN00110355 Write-out-of-bounds when dynamic group certificate is installed due
 *                                              to insufficiently large configured subject name max length
 *                                ESCAN00110314 Generation of CSR may be invalid and/or cause write-out-of-bounds
 *                                              due to insufficiently large configured parse nesting level
 *                                ESCAN00110316 Write-out-of-bounds during generation of certificate signing request
 *                                              due to invalid request data input length
 *                                ESCAN00110313 Possible write-out-of-bounds when certificate data with invalid data
 *                                              length is loaded from NvM during init-phase
 *                                ESCAN00110311 Write-out-of-bounds for invalid data length of certificate init values
 *                                ESCAN00110310 Initialization of NvBlock state fails due to incorrect block identifier
 *                                ESCAN00110296 Retrieving iterable element can return with error or cause unexpected
 *                                              read-out-of-bounds for invalid certificate identifier
 *                                ESCAN00110356 Possible write-out-of-bounds during dispatching of remote service for
 *                                              KeyM_VerifyCertificateChain due to invalid parameter
 *                                ESCAN00110302 Parsing of certificate revocation list may be incomplete
 *                                ESCAN00110300 Certificate revocation may be incomplete since only a single
 *                                              certificate revocation list for complete PKI supported
 *                                ESCAN00110372 Parsing of ECDSA certificate data fails for signature length that is
 *                                              not a multiple of 8
 *                                ESCAN00110376 Possible read-out-of-bounds when certificate structure is retrieved
 *                                              for ROM certificate
 *                                ESCAN00110480 Startup handling fails to verify all available certificate data with
 *                                              NvM storage type and initial values
 *                                ESCAN00110481 Update of a certificate in a dynamic group triggers unnecessary
 *                                              verification of other chains
 *                                ESCAN00110487 Certificate verification can fail due to revoked certificates within PKI
 *                                ESCAN00110490 Service to retrieve certificate structure does not return with error
 *                                              for optional structure type that is not contained in certificate data
 *                                ESCAN00110498 Parser does not check configured object identifier and accepts possible
 *                                              invalid data
 *                                ESCAN00110499 Parser ends in endless loop for configured optional element with object
 *                                              identifier and certificate element data without object identifier
 *                                ESCAN00110548 Missing NULL_PTR check for functions KeyM_GetCertificate and
 *                                              KeyM_VerifyCertificateChain
 *                                ESCAN00110593 Service for retrieving first iterable element does not return with
 *                                              error for elements without iteration
 *                                ESCAN00110607 Missing NULL_PTR check for function KeyM_InitCSR
 *                                ESCAN00110633 Retrieving of certificate element data fails for optional elements
 *                                              that are not contained in the certificate
 *                                ESCAN00110634 Redirection of OCSP service request to remote instance with invalid
 *                                              service causes module to stay in busy mode
 *                                ESCAN00110658 Parsing of certificate data can return with error and/or cause
 *                                              write-out-of-bounds due to insufficiently large configured parse
 *                                              nesting level
 *                                ESCAN00110670 Each certificate verification triggers writing of NvM block
 *  04.01.00  2021-11-17  visivg  SEC-3452      Provide certificate group verification callback notification
 *  04.01.01  2021-01-19  visivg  ESCAN00110724 Parsing of OCSP Response fails due to missing version of the 
 *                                              response syntax
 *                                ESCAN00111212 Service Certificate update request returns negative service result
 *  04.02.00  2022-02-16  visivg  SEC-3146      Support generic RAM slot sharing
 *                                SEC-3845      Retrieve certificate elements by structure type
 *                                SEC-3847      Extend dynamic group handling for RAM slot sharing
 *  04.02.01  2022-03-16  visivg  ESCAN00110754 Compiler warning: Conversion from 'KeyM_CertificateIdType' to 
 *                                              'KeyM_CertificateIterType' possible loss of data and conversion 
 *                                              from 'KeyM_CertificateGroupIdType' to 'KeyM_CertificateGroupExtIterType' 
 *                                              possible loss of data
 *                                ESCAN00111231 Certificate verification API call fails for certificates with 
 *                                              unavailable optional issuer
 **********************************************************************************************************************/
#if !defined KEYM_H
# define KEYM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "KeyM_Cfg.h"
# include "KeyM_Types.h"
# include "SchM_KeyM.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define KEYM_VENDOR_ID                                               (30u)
# define KEYM_MODULE_ID                                               (109u)

/* AUTOSAR Software specification version information */
# define KEYM_AR_RELEASE_MAJOR_VERSION                                (4u)
# define KEYM_AR_RELEASE_MINOR_VERSION                                (4u)
# define KEYM_AR_RELEASE_REVISION_VERSION                             (0u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define KEYM_SW_MAJOR_VERSION                                        (4u)
# define KEYM_SW_MINOR_VERSION                                        (2u)
# define KEYM_SW_PATCH_VERSION                                        (1u)

# define KEYM_INSTANCE_ID_DET                                         (0x00u)

/* ----- API service IDs ----- */
/* AUTOSAR APIs */
# define KEYM_SID_INIT                                                (0x01u) /*!< Service ID: KeyM_Init() */
# define KEYM_SID_DEINIT                                              (0x02u) /*!< Service ID: KeyM_Deinit() */
# define KEYM_SID_GET_VERSION_INFO                                    (0x03u) /*!< Service ID: KeyM_GetVersionInfo() */
# define KEYM_SID_START                                               (0x04u) /*!< Service ID: KeyM_Start() */
# define KEYM_SID_PREPARE                                             (0x05u) /*!< Service ID: KeyM_Prepare() */
# define KEYM_SID_UPDATE                                              (0x06u) /*!< Service ID: KeyM_Update() */
# define KEYM_SID_FINALIZE                                            (0x07u) /*!< Service ID: KeyM_Finalize() */
# define KEYM_SID_VERIFY                                              (0x08u) /*!< Service ID: KeyM_Verify() */
# define KEYM_SID_SERVICE_CERTIFICATE                                 (0x09u) /*!< Service ID: KeyM_ServiceCertificate() */
# define KEYM_SID_SET_CERTIFICATE                                     (0x0Au) /*!< Service ID: KeyM_SetCertificate() */
# define KEYM_SID_GET_CERTIFICATE                                     (0x0Bu) /*!< Service ID: KeyM_GetCertificate() */
# define KEYM_SID_VERIFY_CERTIFICATE                                  (0x0Cu) /*!< Service ID: KeyM_VerifyCertificate() */
# define KEYM_SID_VERIFY_CERTIFICATES                                 (0x0Du) /*!< Service ID: KeyM_VerifyCertificates() */
# define KEYM_SID_VERIFY_CERTIFICATE_CHAIN                            (0x0Eu) /*!< Service ID: KeyM_VerifyCertificateChain() */
# define KEYM_SID_CERT_ELEMENT_GET                                    (0x0Fu) /*!< Service ID: KeyM_CertElementGet() */
# define KEYM_SID_CERT_ELEMENT_GET_FIRST                              (0x10u) /*!< Service ID: KeyM_CertElementGetFirst() */
# define KEYM_SID_CERT_ELEMENT_GET_NEXT                               (0x11u) /*!< Service ID: KeyM_CertElementGetNext() */
# define KEYM_SID_CERT_GET_STATUS                                     (0x12u) /*!< Service ID: KeyM_CertGetStatus() */
# define KEYM_SID_MAIN_FUNCTION                                       (0x19u) /*!< Service ID: KeyM_MainFunction() */
# define KEYM_SID_MAIN_BACKGROUND_FUNCTION                            (0x1Au) /*!< Service ID: KeyM_MainBackgroundFunction() */
/* Vector APIs */
# define KEYM_SID_NVBLOCK_READFROMBLOCK                               (0x80u) /*!< Service ID: KeyM_NvBlock_ReadFromBlock() */
# define KEYM_SID_NVBLOCK_WRITETOBLOCK                                (0x81u) /*!< Service ID: KeyM_NvBlock_WriteToBlock() */
# define KEYM_SID_NVBLOCK_INIT                                        (0x82u) /*!< Service ID: KeyM_NvBlock_Init() */
# define KEYM_SID_NVBLOCK_CALLBACK                                    (0x83u) /*!< Service ID: KeyM_NvBlock_Callback() */
# define KEYM_SID_NVBLOCK_READFROM_CRE                                (0x84u) /*!< Service ID: KeyM_NvBlock_ReadFrom_CRE() */
# define KEYM_SID_NVBLOCK_WRITETO_CRE                                 (0x85u) /*!< Service ID: KeyM_NvBlock_WriteTo_CRE() */
# define KEYM_SID_NVBLOCK_INIT_CRE                                    (0x86u) /*!< Service ID: KeyM_NvBlock_Init_CRE() */
# define KEYM_SID_NVBLOCK_CALLBACK_CRE                                (0x87u) /*!< Service ID: KeyM_NvBlock_Callback_CRE() */
# define KEYM_SID_CERT_ELEMENT_GET_BY_INDEX                           (0x88u) /*!< Service ID: KeyM_CertificateElementGetByIndex() */
# define KEYM_SID_CERT_ELEMENT_GET_COUNT                              (0x89u) /*!< Service ID: KeyM_CertificateElementGetCount() */
# define KEYM_SID_CERT_INIT_CSR                                       (0x8Au) /*!< Service ID: KeyM_InitCSR() */
# define KEYM_SID_SERVICE_CERTIFICATE_BY_ID                           (0x8Bu) /*!< Service ID: KeyM_ServiceCertificateById() */
# define KEYM_SID_SET_CERTIFICATE_IN_GROUP                            (0x8Cu) /*!< Service ID: KeyM_SetCertificateInGroup() */
# define KEYM_SID_GET_GROUP_CERT_ID                                   (0x8Du) /*!< Service ID: KeyM_GetGroupCertId() */
# define KEYM_SID_VERIFY_GROUP                                        (0x8Eu) /*!< Service ID: KeyM_VerifyGroup() */
# define KEYM_SID_SET_CRE                                             (0x8Fu) /*!< Service ID: KeyM_SetCRE() */
# define KEYM_SID_CERT_STRUCTURE_GET                                  (0x90u) /*!< Service ID: KeyM_CertStructureGet() */
# define KEYM_SID_GET_ISSUER_CERT_ID                                  (0x91u) /*!< Service ID: KeyM_GetIssuerCertId() */
# define KEYM_SID_GET_CERT_HASH                                       (0x92u) /*!< Service ID: KeyM_GetCertHash() */
# define KEYM_SID_CSR_ELEMENT_SET                                     (0x93u) /*!< Service ID: KeyM_CsrElementSet() */
# define KEYM_SID_DISPATCH_REMOTE_JOB                                 (0x94u) /*!< Service ID: KeyM_DispatchRemoteJob() */
# define KEYM_SID_DISPATCH_REMOTE_KEYELEMENTSET                       (0x95u) /*!< Service ID: KeyM_DispatchRemoteKeyElementSet() */
# define KEYM_SID_DISPATCH_REMOTE_KEYELEMENTGET                       (0x96u) /*!< Service ID: KeyM_DispatchRemoteKeyElementGet() */
# define KEYM_SID_SET_CERTIFICATEWITHCONSTPTR                         (0x97u) /*!< Service ID: KeyM_SetCertificateWithConstPtr() */
# define KEYM_SID_VERIFY_CERTIFICATE_CHAINWITHCONSTPTR                (0x98u) /*!< Service ID: KeyM_VerifyCertificateChainWithConstPtr() */
# define KEYM_SID_CERT_SEARCHCERT                                     (0x99u) /*!< Service ID: KeyM_Cert_SearchCert() */
# define KEYM_SID_CERT_ISBUSY                                         (0x9Au) /*!< Service ID: KeyM_Cert_IsBusy() */
# define KEYM_SID_CALLBACKNOTIFICATIONSIGNATURE                       (0x9Bu) /*!< Service ID: KeyM_CallbackNotificationSignature() */
# define KEYM_SID_CERT_ELEMENT_GET_BY_STRUCTURETYPE                   (0x9Cu) /*!< Service ID: KeyM_CertElementGetByStructureType() */

/* Internal functions */
# define KEYM_SID_CERT_LOADCERTIFICATEINITVALUE                       (0xFEu) /*!< Service ID: KeyM_Cert_LoadCertificateInitValue() */

/* ----- Error codes ----- */
# define KEYM_E_NO_ERROR                                              (0x00u) /*!< used to check if no error occurred - use a value unequal to any error code */
# define KEYM_E_PARAM_POINTER                                         (0x01u) /*!< Error code: API service used with invalid pointer parameter (NULL) */
# define KEYM_E_SMALL_BUFFER                                          (0x02u) /*!< Error code: API service used with invalid parameter buffer length */
# define KEYM_E_UNINIT                                                (0x03u) /*!< Error code: API service used without module initialization */
# define KEYM_E_INIT_FAILED                                           (0x04u) /*!< Error code: The service KeyM_Init() is called while the module is already initialized  */
# define KEYM_E_WRITE_ACCESS_FAILED                                   (0x80u) /*!< Error code: API service used with disabled write access */
# define KEYM_E_CERTIFICATE_INIT_VALUE_INVALID_LENGTH                 (0x81u) /*!< Error code: Configured or provided certificate init value has invalid length */
# define KEYM_E_INVALID_CONFIGURATION                                 (0x82u) /*!< Error code: KeyM's configuration is inconsistent */

/* ----- Modes ----- */
# define KEYM_UNINIT                                                  (0x00u)
# define KEYM_INIT                                                    (0x01u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  KeyM_InitMemory()
 *********************************************************************************************************************/
/*! \brief         The function initializes variables, which cannot be initialized with the startup code.
 *  \details       Initialize component variables at power up.
 *  \pre           Module is uninitialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_InitMemory(void);

/**********************************************************************************************************************
 * KeyM_Init()
 *********************************************************************************************************************/
/*! \brief         Initializes the Key Manager.
 *  \details       This function initializes the KeyM module. It initializes all variables and sets the
 *                 module state to initialized.
 *  \param[in]     ConfigPtr             Pointer to the configuration set in VARIANT-POST-BUILD
 *  \pre           Interrupts are disabled.
 *                 Module is uninitialized.
 *  \note          ConfigPtr shall be a NULL_PTR, since a configuration of the KeyM at initialization
 *                 is currently not used.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Init(
  P2CONST(KeyM_ConfigType, AUTOMATIC, KEYM_APPL_DATA) ConfigPtr);

/**********************************************************************************************************************
 * KeyM_Deinit()
 *********************************************************************************************************************/
/*! \brief         Resets the Key Manager.
 *  \details       This function resets the KeyM module to the uninitialized state.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_Deinit(void);

# if (KEYM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 * KeyM_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief         Returns the version information.
 *  \details       KeyM_GetVersionInfo() Returns version information, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]    VersionInfo           Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        KEYM_VERSION_INFO_API == STD_ON
 *********************************************************************************************************************/
FUNC(void, KEYM_CODE) KeyM_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, KEYM_APPL_VAR) VersionInfo);
# endif /* (KEYM_VERSION_INFO_API == STD_ON) */

# if (KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_CRYPTO_KEY_SUBMODULE */
/**********************************************************************************************************************
 * KeyM_Start()
 *********************************************************************************************************************/
/*! \brief         Starts a session for key operations.
 *  \details       This function is optional and only used if the configuration item
 *                 KeyMCryptoKeyStartFinalizeFunctionEnabled is set to true. It intents to allow key
 *                 update operation.
 *  \param[in]     StartType                        Defines in which mode the key operation shall be executed.
 *  \param[in]     RequestData                      Information that comes along with the request, e.g. signature.
 *  \param[in]     RequestDataLength                Length of data in the RequestData array.
 *  \param[out]    ResponseData                     Data returned by the function.
 *  \param[in,out] ResponseDataLength               In: Max number of bytes available in ResponseData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Start operation successfully performed. Key update operations are
 *                                                  now allowed.
 *                 E_NOT_OK                         Start operation not accepted.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Start(
  KeyMStartType StartType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength);
# endif /* (KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON) */

# if (KEYM_CRYPTO_KEY_PREPARE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_CRYPTO_KEY_SUBMODULE */
/**********************************************************************************************************************
 * KeyM_Prepare()
 *********************************************************************************************************************/
/*! \brief         Prepare key update.
 *  \details       This function is used to prepare a key update operation. The main intent is to
 *                 provide information for the key operation to the key server. Other operations may
 *                 start the negotiation for a common secret that is used further to derive key
 *                 material. This function is only available if KeyMCryptoKeyPrepareFunctionEnabled
 *                 is set to TRUE.
 *  \param[in]     RequestData                      Information that comes along with the request.
 *  \param[in]     RequestDataLength                Length of data in the RequestData array.
 *  \param[out]    ResponseData                     Data returned by the function.
 *  \param[in,out] ResponseDataLength               In: Max number of bytes available in ResponseData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Service has been accepted and will be processed
 *                                                  internally. Results will be provided through a callback.
 *                 E_NOT_OK                         Service not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        KEYM_CRYPTO_KEY_PREPARE_FUNCTION_ENABLED == STD_ON
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Prepare(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength);
# endif /* (KEYM_CRYPTO_KEY_PREPARE_FUNCTION_ENABLED == STD_ON) */

/**********************************************************************************************************************
 * KeyM_Update()
 *********************************************************************************************************************/
/*! \brief         Initiate key update.
 *  \details       This function is used to initiate the key generation or update process.
 *  \param[in]     KeyNamePtr                       Pointer to an array that defines the name of the key to be updated.
 *  \param[in]     KeyNameLength                    Specifies the number of bytes in keyName. The value 0 indicates
 *                                                  that no keyName is provided within this function.
 *  \param[in]     RequestDataPtr                   Information that comes along with the request.
 *  \param[in]     RequestDataLength                Length of data in the RequestData array.
 *  \param[out]    ResultDataPtr                    Pointer to a data buffer used by the function to store results.
 *  \param[in]     ResultDataMaxLength              Max number of bytes available in ResultDataPtr.
 *  \return        E_OK                             Service has been accepted and will be processed
 *                                                  internally. Results will be provided through a callback
 *                 E_NOT_OK                         Service not accepted due to an internal error.
 *                 E_BUSY                           Service could not be accepted because another
 *                                                  operation is already ongoing. Try next time.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Update(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) KeyNamePtr,
  uint32 KeyNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestDataPtr,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResultDataPtr,
  uint32 ResultDataMaxLength);

# if (KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_CRYPTO_KEY_SUBMODULE */
/**********************************************************************************************************************
 * KeyM_Finalize()
 *********************************************************************************************************************/
/*! \brief         Finalize key update.
 *  \details       The function is used to finalize key update operations. It is typically used in
 *                 conjunction with the KeyM_Start operation and returns the key operation into the
 *                 idle mode. Further key prepare or update operations are not accepted until a new
 *                 KeyM_Start operation has been initialized. This function is only available if
 *                 KeyMCryptoKeyStartFinalizeFunctionEnabled is set to TRUE.
 *                 In addition, updated key material will be persisted and set into valid state (calling
 *                 Csm_KeySetValid).
 *  \param[in]     RequestDataPtr                   Information that comes along with the request.
 *  \param[in]     RequestDataLength                Length of data in the RequestData array.
 *  \param[out]    ResponseDataPtr                  Data returned by the function.
 *  \param[in,out] ResponseMaxDataLength            In: Max number of bytes available in ResponseData.
 *                                                  Out: Actual number of bytes in ResponseData or left
 *                                                  untouched if service runs in asynchronous mode and
 *                                                  function returns KEYM_E_OK.
 *  \return        E_OK                             Service has been accepted and will be processed
 *                                                  internally. Results will be provided through a callback
 *                 E_NOT_OK                         Service not accepted due to an internal error.
 *                 KEYM_E_BUSY                      Validation cannot be performed yet. KeyM is currently
 *                                                  busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \config        KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Finalize(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestDataPtr,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseDataPtr,
  uint32 ResponseMaxDataLength);
# endif /* (KEYM_CRYPTO_KEY_START_FINALIZE_FUNCTION_ENABLED == STD_ON) */

# if (KEYM_CRYPTO_KEY_VERIFY_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_CRYPTO_KEY_SUBMODULE */
/**********************************************************************************************************************
 * KeyM_Verify()
 *********************************************************************************************************************/
/*! \brief         Verify key material.
 *  \details       The key server requests to verify the provided keys. The key manager performs
 *                 operation on the assigned job and returns the result to the key server who verifies
 *                 if the results was provided with this key as expected. This function is only
 *                 available if KeyMCryptoKeyVerifyFunctionEnabled is set to TRUE.
 *  \param[in]     KeyNamePtr                       Points to an array that defines the name of the key to be updated.
 *  \param[in]     KeyNameLength                    Specifies the number of bytes in KeyNamePtr. The value 0 indicates
 *                                                  that no KeyNamePtr is provided within this function.
 *  \param[in]     RequestData                      Information that comes along with the request.
 *  \param[in]     RequestDataLength                Length of data in the RequestData array
 *  \param[out]    ResponseData                     Data returned by the function.
 *  \param[in,out] ResponseDataLength               In: Max number of bytes available in ResponseData.
 *                                                  Out: Actual number of bytes in ResponseData or left
 *                                                  untouched if service runs in asynchronous mode and
 *                                                  function returns KEYM_E_PENDING.
 *  \return        E_OK                             Operation was successfully performed. Result
 *                                                  information are available.
 *                 E_NOT_OK                         Operation not accepted due to an internal error.
 *                 KEYM_E_PENDING                   Operation runs in asynchronous mode, has been accepted and will
 *                                                  be processed internally. Results will be provided through callback.
 *                 KEYM_E_BUSY                      Validation cannot be performed yet. KeyM is currently
 *                                                  busy with other jobs (for asynchronous mode).
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_KEY_CERT_INVALID          Key operation cannot be performed because the key name is invalid.
 *                 KEYM_E_KEY_CERT_EMPTY            The key for this slot has not been set.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \config        KEYM_CRYPTO_KEY_VERIFY_FUNCTION_ENABLED == STD_ON
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Verify(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) KeyNamePtr,
  uint32 KeyNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength);
# endif /* (KEYM_CRYPTO_KEY_VERIFY_FUNCTION_ENABLED == STD_ON) */

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_ServiceCertificate()
 *********************************************************************************************************************/
/*! \brief         Handle certificate operation requests.
 *  \details       The key server requests an operation from the key client. The type specified in the first
 *                 parameter KeyM_ServiceCertificateType. Certificate operation requests are operated through
 *                 this function. This function is only available if the configuration parameter
 *                 KeyMServiceCertificateFunctionEnabled is set to TRUE.
 *  \param[in]     Service                              Provides the type of service the key manager has to perform.
 *  \param[in]     CertNamePtr                          Points to an array that defines the name of the certificate to
 *                                                      be updated
 *  \param[in]     CertNameLength                       Specifies the number of bytes in CertNamePtr. The value 0
 *                                                      indicates that no CertNamePtr is provided within this function.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \param[out]    ResponseData                         Data returned by the function.
 *  \param[in]     ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           RequestData and ResponseData must be valid pointers to user-provided buffers. Their respective length
 *                 values must not exceed the actual buffer lengths.
 *  \note          The parsing of a certificate and the verifying of certificate elements is performed synchronously
 *                 within this function.
 *                 In case of a KEYM_SERVICE_CERT_REQUEST_CSR service request, the KeyM can generate the
 *                 CertificationRequestInfo and the final CertificationRequest structure after all CSR elements were
 *                 previously set using KeyM_CsrElementSet. Since no data is passed as input information for this request,
 *                 the parameter RequestData needs be a valid pointer and the corresponding RequestDataLength parameter has to be zero.
 *                 If the CertificationRequestInfo is generated in a previous step using KeyM_InitCSR, this data is passed
 *                 to the input parameters RequestData and RequestDataLength to generate the final CertificationRequest structure.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \config        KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_ServiceCertificate(
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
# endif /* (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) */

/**********************************************************************************************************************
 * KeyM_SetCertificate()
 *********************************************************************************************************************/
/*! \brief         Temporarily store certificate.
 *  \details       This function provides the certificate data to the key management module to
 *                 temporarily store the certificate.
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertificateDataPtr               Pointer to a structure that provides the certificate data.
 *  \return        E_OK                             Certificate accepted.
 *                 E_NOT_OK                         Certificate could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           CertificateDataPtr->certData must be a valid, non-NULL pointer to a buffer of at least
 *                 CertificateDataPtr->certDataLength bytes.
 *  \note          The parsing of a certificate and the verifying of certificate elements is performed synchronously
 *                 within this function.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificate(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);

/**********************************************************************************************************************
 * KeyM_SetCertificateWithConstPtr()
 *********************************************************************************************************************/
/*! \brief         Temporarily store certificate.
 *  \details       This function is identical to KeyM_SetCertificate, but it accepts a const pointer to certificate
 *                 data.
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertificateDataPtr               Pointer to a structure that provides the certificate data.
 *  \return        E_OK                             Certificate accepted.
 *                 E_NOT_OK                         Certificate could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           CertificateDataPtr->certData must be a valid, non-NULL pointer to a buffer of at least
 *                 CertificateDataPtr->certDataLength bytes.
 *  \note          The parsing of a certificate and the verifying of certificate elements is performed synchronously
 *                 within this function.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificateWithConstPtr(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_SetCertificateInGroup()
 *********************************************************************************************************************/
/*! \brief         Set group certificate.
 *  \details       This function sets certificate data in a certificate group.
 *  \param[in]     GroupId                              Holds the identifier of the certificate group.
 *  \param[in]     RequestData                          Pointer to the certificate data.
 *  \param[in]     RequestDataLength                    Holds the length of the certificate data.
 *  \param[out]    CertId                               Holds the certificate identifier of the slot where data has
 *                                                      been installed.
 *  \return        E_OK                                 Certificate accepted.
 *                 E_NOT_OK                             Certificate could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           -
 *  \note          This function call can trigger a callback notification if an optional service certificate callback
 *                 <KeyM_ServiceCertificateCallbackNotification> is configured for the corresponding dynamic
 *                 certificate slot.
 *                 The parsing of a certificate and the verifying of certificate elements is performed synchronously
 *                 within this function.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCertificateInGroup(
  KeyM_CertificateGroupIdType GroupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) CertId);
# endif

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_GetGroupCertId()
 *********************************************************************************************************************/
/*! \brief         Get certificate identifier for previously set group certificates.
 *  \details       -
 *  \param[in]     GroupId                          Holds the identifier of the certificate group.
 *  \param[in]     SubjectCommonNameData            Pointer to the subject common name data.
 *  \param[in]     SubjectCommonNameDataLength      Holds the length of the subject common name data.
 *  \param[out]    CertId                           Holds the certificate identifier of the slot where data has been
 *                                                  installed.
 *  \return        E_OK                             Certificate identifier was successfully retrieved.
 *                 E_NOT_OK                         Referenced subject common name was not found within the group.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetGroupCertId(
  KeyM_CertificateGroupIdType GroupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SubjectCommonNameData,
  uint32 SubjectCommonNameDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) CertId);
# endif

/**********************************************************************************************************************
 * KeyM_GetCertificate()
 *********************************************************************************************************************/
/*! \brief         Provide certificate.
 *  \details       This function provides the certificate data.
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in,out] CertificateDataPtr               Provides a pointer to a certificate data structure. The buffer
 *                                                  located by the pointer in the structure shall be provided by the
 *                                                  caller of this function. The length information indicates the
 *                                                  maximum length of the buffer when the function is called. If
 *                                                  E_OK is returned, the length information indicates the actual
 *                                                  length of the certificate data in the buffer.
 *  \return        E_OK                             Certificate data available and provided.
 *                 E_NOT_OK                         Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH        Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Provided buffer for the certificate too small.
 *                 KEYM_E_KEY_CERT_EMPTY            No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_READ_FAIL        Certificate cannot be provided, access denied.
 *  \pre           CertificateDataPtr->certData must be a valid, non-NULL pointer to a buffer of at least
 *                 CertificateDataPtr->certDataLength bytes.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertificate(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr);

/**********************************************************************************************************************
 * KeyM_VerifyCertificate()
 *********************************************************************************************************************/
/*! \brief         Verify certificate.
 *  \details       This function verifies a certificate that was previously provided with
 *                 KeyM_SetCertificate() against already stored and provided certificates stored with
 *                 other certificate IDs.
 *  \param[in]     CertId                               Holds the identifier of the lower certificate in the chain.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
/* PRQA S 3449, 3451 2 */ /* MD_KEYM_DoubleDeclarationRte */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificate(
  KeyM_CertificateIdType CertId);

/**********************************************************************************************************************
 * KeyM_VerifyCertificates()
 *********************************************************************************************************************/
/*! \brief         Verify two certificates.
 *  \details       This function verifies two certificates that are stored and parsed internally against
 *                 each other. The certificate referenced with CertId was signed by the certificate
 *                 referenced with certUpperId. Only these two certificates are validated against each other.
 *  \param[in]     CertId                               Holds the identifier of the lower certificate in the chain.
 *  \param[in]     CertUpperId                          Holds the identifier of the upper certificate in the chain.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificates(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateIdType CertUpperId);

/**********************************************************************************************************************
 * KeyM_VerifyCertificateChain()
 *********************************************************************************************************************/
/*! \brief         Verify list of certificates.
 *  \details       This function performs a certificate verification against a list of certificates.
 *                 It is a pre-requisite that the certificate that shall be checked has already been
 *                 written with KeyM_SetCertificate() and that the root certificate is either in the list or
 *                 is already assigned to one of the other certificates.
 *  \param[in]     CertId                               Holds the identifier of the last certificate in the chain.
 *  \param[in]     certChainData                        This is a pointer to an array of certificates sorted according
 *                                                      to the order in the PKI.
 *  \param[in]     NumberOfCertificates                 Defines the number of certificates stored in the CertChainData
 *                                                      array.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           NumberOfCertificates must be valid in respect to the configured certificate chain depth.
 *                 certChainDta must reference at least NumberOfCertificates many elements. For all its entries e,
 *                 e->certData must be a valid, non-NULL pointer to a buffer of at least e->certDataLength bytes.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificateChain(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates);

/**********************************************************************************************************************
 * KeyM_VerifyCertificateChainWithConstPtr()
 *********************************************************************************************************************/
/*! \brief         Verify list of certificates.
 *  \details       This function is identical to KeyM_VerifyCertificateChain, but it accepts a const pointers to
 *                 certificate data.
 *  \param[in]     CertId                               Holds the identifier of the last certificate in the chain.
 *  \param[in]     certChainData                        This is a pointer to an array of certificates sorted according
 *                                                      to the order in the PKI.
 *  \param[in]     NumberOfCertificates                 Defines the number of certificates stored in the CertChainData
 *                                                      array.
 *  \return        E_OK                                 Certificate verification request accepted. Operation will be
 *                                                      performed in the background and response is given through a
 *                                                      callback.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_BUSY                          Validation cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_EMPTY                One of the certificate slots are empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   An upper certificate is not valid.
 *  \pre           NumberOfCertificates must be valid in respect to the configured certificate chain depth.
 *                 certChainDta must reference at least NumberOfCertificates many elements. For all its entries e,
 *                 e->certData must be a valid, non-NULL pointer to a buffer of at least e->certDataLength bytes.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyCertificateChainWithConstPtr(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates);

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
/**********************************************************************************************************************
 * KeyM_VerifyGroup()
 *********************************************************************************************************************/
/*! \brief         Verify previously set group certificates.
 *  \details       -
 *  \param[in]     GroupId                     Holds the identifier of the certificate group.
 *  \return        E_OK                        The verification of the certificate group was triggered successfully.
 *                 E_NOT_OK                    Certificate data is unavailable and no verification could be triggered.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_VerifyGroup(
  KeyM_CertificateGroupIdType GroupId);
# endif

/**********************************************************************************************************************
 * KeyM_CertElementGet()
 *********************************************************************************************************************/
/*! \brief         Provide certificate element.
 *  \details       Provides the content of a specific certificate element. The certificate configuration
 *                 defines how the certificate submodule can find the element, e.g. by providing the
 *                 object identifier (OID). This function is used to retrieve this information if only one
 *                 element is assigned to the respective OID.
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Specifies the ElementId where the data shall be read from.
 *  \param[out]    CertElementData                      Pointer to a data buffer allocated by the caller of this
 *                                                      function. If available, the function returns E_OK and
 *                                                      copies the data into this buffer.
 *  \param[in,out] CertElementDataLength                In: Pointer to a value that contains the maximum data
 *                                                      length of the CertElementData buffer.
 *                                                      Out: The data length will be overwritten with the actual
 *                                                      length of data placed to the buffer if the function returns
 *                                                      E_OK. Otherwise, it will be overwritten with the value zero.
 *  \return        E_OK                                 Element found and data provided in the buffer.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              The certificate is not valid or has not yet been verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
/* PRQA S 3449, 3451 5 */ /* MD_KEYM_DoubleDeclarationRte */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_CertElementGetByStructureType()
 *********************************************************************************************************************/
/*! \brief         Provide certificate element by certificate structure type.
 *  \details       -
 *  \param[in]     CertData                           Pointer to the certificate data.
 *  \param[in]     CertDataLength                     Holds the length of the certificate data.
 *  \param[in]     CertStructure                      Holds the certificate structure type.
 *  \param[out]    CertElementData                    Pointer to a valid buffer which will hold the data returned by the
 *                                                    function.
 *  \param[in,out] CertElementDataLength              In: Max number of bytes available in CertElementData.
 *                                                    Out: Actual number.
 *  \return        E_OK                               Element found and data provided in the buffer.
 *                 E_NOT_OK                           Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH          Certificate structure type is invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH      Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY              No certificate data available.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGetByStructureType(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertData,
  uint32 CertDataLength,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_CertElementGetFirst()
 *********************************************************************************************************************/
/*! \brief         Provide first part of data from certificate element.
 *  \details       This function is used to initialize the iterative extraction of a certificate data
 *                 element. It always retrieves the top element from the configured certificate
 *                 element and initializes the structure KeyM_CertElementIterator so that
 *                 consecutive data from this element can be read with KeyM_CertElementGetNext().
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Specifies the ElementId where the data shall be read from.
 *  \param[in,out] CertElementIterator                  Pointer to a structure that is allocated and maintained by
 *                                                      the caller. It shall not be destroyed or altered by the
 *                                                      application until all elements have been retrieved through
 *                                                      KeyM_CertElementGetNext().
 *  \param[out]    CertElementData                      Pointer to a data buffer allocated by the caller of this
 *                                                      function. If available, the function returns E_OK and
 *                                                      copies the data into this buffer.
 *  \param[in,out] CertElementDataLength                In: Pointer to a value that contains the maximum data
 *                                                      length of the CertElementData buffer.
 *                                                      Out: The data length will be overwritten with the actual
 *                                                      length of data placed to the buffer if the function returns
 *                                                      E_OK.
 *  \return        E_OK                                 Element found and data provided in the buffer.
 *                                                      The certElementIterator has been initialized accordingly.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully or
 *                                                      referenced certificate element is not iterable.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGetFirst(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_CertElementGetNext()
 *********************************************************************************************************************/
/*! \brief         Provide further data from certificate element.
 *  \details       This function provides further data from a certificate element, e.g. if a set of data
 *                 is located in one certificate element that shall be read one after another. This
 *                 function can only be called if the function KeyM_CertElementGetFirst() has been
 *                 called once before. It has to be assured, that the installed certificate data remains consistent
 *                 between calls of KeyM_CertElementGetFirst() and KeyM_CertElementGetNext as well as several calls of
 *                 KeyM_CertElementGetNext().
 *  \param[in,out] CertElementIterator             Pointer to a structure that is allocated by the caller and
 *                                                 used by the function. It shall not be destroyed or altered
 *                                                 by the application until all elements have been read from the list.
 *  \param[out]    CertElementData                 Pointer to a data buffer allocated by the caller of this
 *                                                 function. If available, the function returns E_OK and
 *                                                 copies the data into this buffer.
 *  \param[in,out] CertElementDataLength           In: Pointer to a value that contains the maximum
 *                                                 length of the CertElementData buffer.
 *                                                 Out: The data length will be overwritten with the actual
 *                                                 length of data placed to the buffer if the function returns E_OK.
 *  \return        E_OK                            Element found and data provided in the buffer.
 *                                                 The certElementIterator has been initialized accordingly.
 *                 E_NOT_OK                        Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH       Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY           No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID         Certificate is not valid or not verified successfully.
 *  \pre           The passed CertElementIterator must be an object that was previously retrieved via
 *                 KeyM_CertElementGetFirst().
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertElementGetNext(
  P2VAR(KeyM_CertElementIteratorType, AUTOMATIC, KEYM_APPL_VAR) CertElementIterator,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_CertGetStatus()
 *********************************************************************************************************************/
/*! \brief         Provides certificate status.
 *  \details       This function provides the status of a certificate.
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[out]    Status                               Provides the status of the certificate.
 *  \return        E_OK                                 Certificate status available and provided.
 *                 E_NOT_OK                             Status provisioning currently not possible.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate identifier is invalid.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
/* PRQA S 3449, 3451 3 */ /* MD_KEYM_DoubleDeclarationRte */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertGetStatus(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateStatusType, AUTOMATIC, KEYM_APPL_VAR) Status);

/**********************************************************************************************************************
 * KeyM_Cert_SearchCert()
 *********************************************************************************************************************/
/*! \brief         Search name of referenced certificate in configuration.
 *  \details       -
 *  \param[in]     certNamePtr     Pointer to a buffer that defines the name of the certificate.
 *  \param[in]     certNameLength  Name buffer length.
 *  \param[out]    certId          Holds the identifier of the certificate.
 *  \return        TRUE            Certificate with given name is available.
 *                 FALSE           Certificate with given name is not available.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(boolean, KEYM_CODE) KeyM_Cert_SearchCert(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) certNamePtr,
  uint32 certNameLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) certId);

/**********************************************************************************************************************
 * KeyM_CertificateElementGetByIndex()
 *********************************************************************************************************************/
/*! \brief         Provides data from an iterable certificate element.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the iterable certificate element.
 *  \param[in]     Index                                This is the index to the respective element in the list of
 *                                                      iterable elements.
 *  \param[out]    CertElementData                      Pointer to a data buffer for the iterable certificate element.
 *  \param[in,out] CertElementDataLength                In: Pointer to a value that contains the maximum data
 *                                                      length of the CertElementData buffer.
 *                                                      Out: The data length will be overwritten with the actual
 *                                                      length of data placed to the buffer if the function returns
 *                                                      E_OK.
 *  \return        E_OK                                 Element found and data provided in the buffer.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
/* PRQA S 3449, 3451 6 */ /* MD_KEYM_DoubleDeclarationRte */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetByIndex(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  uint16 Index,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);

/**********************************************************************************************************************
 * KeyM_CertificateElementGetCount()
 *********************************************************************************************************************/
/*! \brief         Provides the amount of iterable elements.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the certificate element.
 *  \param[out]    Count                                Total number of iterable certificate elements.
 *  \return        E_OK                                 Element found and number of element items provided.
 *                 E_NOT_OK                             Element data not found.
 *                 KEYM_E_PARAMETER_MISMATCH            Certificate ID or certificate element ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Provided buffer for the certificate element too small.
 *                 KEYM_E_KEY_CERT_EMPTY                No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_INVALID              Certificate is not valid or not verified successfully.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
/* PRQA S 3449, 3451 4 */ /* MD_KEYM_DoubleDeclarationRte */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertificateElementGetCount(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) Count);

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_InitCSR()
 *********************************************************************************************************************/
/*! \brief         Initializes request data for certificate signing request.
 *  \details       In order to perform a certificate signing request, the returned CertificationRequestInfo data has
 *                 to be passed in KeyM_ServiceCertificate() as RequestData.
 *  \param[in]     CertNamePtr                      Points to an array that defines the name of the certificate
 *  \param[in]     CertNameLength                   Specifies the number of bytes in CertNamePtr.
 *  \param[in]     CsrInfo                          Points to an array of request data objects
 *  \param[in]     numOfReqObjects                  Total number of available request objects.
 *  \param[out]    ResponseData                     CertificationRequestInfo in ASN.1.
 *  \param[in,out] ResponseDataLength               In: Max number of bytes available in ResponseData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             CertificationRequestInfo data structure was generated successfully.
 *                 E_NOT_OK                         Due to internal error, the CertificationRequestInfo data structure
 *                                                  could not be generated.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           CsrInfo must reference at least numOfReqObject many elements.
 *                 For each element of CsrInfo, dataPtr must point to a valid data buffer which is as least dataLength
 *                 bytes large.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_InitCSR(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(KeyM_CSRInfoType, AUTOMATIC, KEYM_APPL_DATA) CsrInfo,
  uint8 numOfReqObjects,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) ResponseDataLength);
# endif

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_CsrElementSet()
 *********************************************************************************************************************/
/*! \brief         Set certificate signing request element data.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the certificate element.
 *  \param[in]     EncodingType                         Holds the encoding type of the certificate element.
 *  \param[in]     ElementData                          Points to an array of element data.
 *  \param[in]     ElementDataLength                    Max number of bytes available in ElementData.
 *  \return        E_OK                                 CSR element was set successfully.
 *                 E_NOT_OK                             Due to internal error, the CSR element could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
 /* PRQA S 3449, 3451 5 */ /* MD_KEYM_DoubleDeclarationRte */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CsrElementSet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  KeyM_CsrEncodingType EncodingType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) ElementData,
  uint32 ElementDataLength);
# endif

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_ServiceCertificateById()
 *********************************************************************************************************************/
/*! \brief         Handle certificate operation requests.
 *  \details       The key server requests an operation from the key client. The type specified in the first
 *                 parameter KeyM_ServiceCertificateType. Certificate operation requests are operated through
 *                 this function. This function is only available if the configuration parameter
 *                 KeyMServiceCertificateFunctionEnabled is set to TRUE.
 *  \param[in]     Service                              Provides the type of service the key manager has to perform.
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \param[out]    ResponseData                         Data returned by the function.
 *  \param[in]     ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           RequestData and ResponseData must be valid pointers to user-provided buffers. Their respective length
 *                 values must not exceed the actual buffer lengths.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \config        KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_ServiceCertificateById(
  KeyM_ServiceCertificateType Service,
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
# endif /* (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) */

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
/**********************************************************************************************************************
 * KeyM_ServiceCertificateByIdRteAdpt()
 *********************************************************************************************************************/
/*! \brief         See doxygen of KeyM_ServiceCertificateById().
 *  \details       This function is a variant of KeyM_ServiceCertificateById() with a different parameter order.
 *                 This is necessary to provide a compatible interface to the RTE.
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     Service                              Provides the type of service the key manager has to perform.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \param[out]    ResponseData                         Data returned by the function.
 *  \param[in]     ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           RequestData and ResponseData must be valid pointers to user-provided buffers. Their respective length
 *                 values must not exceed the actual buffer lengths.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \config        KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON
 *********************************************************************************************************************/
 /* PRQA S 3449, 3451 5 */ /* MD_KEYM_DoubleDeclarationRte */
FUNC(Std_ReturnType, KEYM_CODE) KeyM_ServiceCertificateByIdRteAdpt(
  KeyM_CertificateIdType CertId,
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
# endif /* (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) */

# if (KEYM_CRE == STD_ON)
/**********************************************************************************************************************
 * KeyM_SetCRE()
 *********************************************************************************************************************/
/*! \brief         Set a certificate revocation entry.
 *  \details       -
 *  \param[in]     IssuerNameData                   Points to an array that defines the issuer common name of the
 *                                                  revoked certificate.
 *  \param[in]     IssuerNameDataLength             Length of issuer common name data.
 *  \param[in]     SerialNumberData                 Points to an array that defines the serial number of the revoked
 *                                                  certificate.
 *  \param[in]     SerialNumberDataLength           Length of serial number data.
 *  \return        E_OK                             Certificate revocation entry was appended successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate revocation entry could
 *                                                  not be appended.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        KEYM_CRE == STD_ON
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_SetCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength);
# endif

/**********************************************************************************************************************
 * KeyM_CertStructureGet()
 *********************************************************************************************************************/
/*! \brief         Retrieve certificate structure.
 *  \details       -
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertStructure                    Holds the certificate structure type.
 *  \param[out]    CertStructureData                Pointer to a valid buffer which will hold the data returned by the
 *                                                  function.
 *  \param[in,out] CertStructureDataLength          In: Max number of bytes available in CertStructureData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Certificate structure was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate structure could not be
 *                                                  retrieved.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_KEY_CERT_INVALID          The certificate is not valid or has not yet been verified.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_CertStructureGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength);

/**********************************************************************************************************************
 * KeyM_GetIssuerCertId()
 *********************************************************************************************************************/
/*! \brief         Get certificate identifier of issuer in upper hierarchy.
 *  \details       -
 *  \param[in]     CertId                Holds the certificate identifier.
 *  \param[out]    IssuerCertId          Holds the certificate identifier of the issuer this function returns.
 *  \return        E_OK                  Issuer's certificate identifier was retrieved successfully.
 *                 E_NOT_OK              Due to internal error, the issuer's certificate identifier could not be
 *                                       retrieved.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetIssuerCertId(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) IssuerCertId);

/**********************************************************************************************************************
 * KeyM_GetCertHash()
 *********************************************************************************************************************/
/*! \brief         Retrieve precomputed hash over certificate data.
 *  \details       -
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[out]    HashData                         Pointer to a valid buffer which will hold the data returned by the
 *                                                  function.
 *  \param[in,out] HashDataLength                   In: Max number of bytes available in HashData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Certificate hash was retrieved successfully.
 *                 E_NOT_OK                         Due to internal error, the certificate hash could not be
 *                                                  retrieved.
 *                 KEYM_E_BUSY                      Service cannot be performed yet. Certificate is locked by another
 *                                                  service request.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 *                 KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_INVALID          Certificate is not valid.
 *                 KEYM_E_KEY_CERT_EMPTY            Certificate slot is empty.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \note          The current implementation does not support a certificate locking mechanism. Therefore the
 *                 return code KEYM_E_BUSY is added only for future compliance. If a certificate update fails
 *                 and the persisted certificate data is re-loaded, the hash needs to be computed again. It is possible
 *                 that this function returns the hash of the invalid, updated certificate data if the hash computation
 *                 has not finished yet. To ensure the validity of the hash, check the status of the updated
 *                 certificate in advance. If after an update, the status is KEYM_CERTIFICATE_VALID, the hash retrieved
 *                 by this function is valid.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_GetCertHash(
  KeyM_CertificateIdType CertId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) HashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) HashDataLength);

/**********************************************************************************************************************
 * KeyM_DispatchRemoteJob()
 *********************************************************************************************************************/
/*! \brief         Dispatches remote Crypto job to KeyM service.
 *  \details       The dispatching functionality shall be only used by a custom Crypto driver on remote side
 *                 to enable remote service handling.
 *  \param[in]     job                     Pointer to the configuration of the job which is owned by the API user.
 *                                         Contains structures with job and primitive relevant information but also
 *                                         pointers to result buffers.
 *  \return        E_OK                                Remote service request was dispatched and processed successfully.
 *                 E_NOT_OK                            Due to an internal error, the remote service request could not
 *                                                     be dispatched or processed.
 *                 KEYM_E_PARAMETER_MISMATCH           Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH       Parameter size doesn't match.
 *                 KEYM_E_BUSY                         Service cannot be performed yet. KeyM is
 *                                                     currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY               Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST  Invalid chain of trust.
 *  \pre           job->jobPrimitiveInputOutput->{input | secondaryInput | tertiaryInput | output}Ptr must be non-NULL,
 *                 valid pointers and their respective length fields must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_DispatchRemoteJob(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);

/**********************************************************************************************************************
 * KeyM_DispatchRemoteKeyElementSet()
 *********************************************************************************************************************/
/*! \brief         Dispatches remote set key element request to KeyM service.
 *  \details       The dispatching functionality shall be only used by a custom Crypto driver on remote side
 *                 to enable remote service handling.
 *  \param[in]     cryptoKeyId                     Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId                    Holds the identifier of the key element which shall be set.
 *  \param[in]     keyPtr                          Holds the pointer to the user-owned key data which shall be set as
 *                                                 key element.
 *  \param[in]     keyLength                       Contains the length of the key element in bytes.
 *  \return        E_OK                            Remote service request was dispatched and processed successfully.
 *                 E_NOT_OK                        Due to an internal error, the remote service request could not
 *                                                 be dispatched or processed.
 *                 KEYM_E_PARAMETER_MISMATCH       Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Parameter size doesn't match.
 *  \pre           The length of the buffer passed as keyPtr must be at least keyLength bytes.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_DispatchRemoteKeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength);

/**********************************************************************************************************************
 * KeyM_DispatchRemoteKeyElementGet()
 *********************************************************************************************************************/
/*! \brief         Dispatches remote get key element request to KeyM service.
 *  \details       The dispatching functionality shall be only used by a custom Crypto driver on remote side
 *                 to enable remote service handling.
 *  \param[in]     cryptoKeyId                     Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId                    Holds the identifier of the key element which shall be set.
 *  \param[out]    keyPtr                          Holds the pointer to the user-owned memory location where the key
 *                                                 shall be copied to.
 *  \param[in,out] keyLengthPtr                    Holds a pointer to the memory location in which the output buffer length in
 *                                                 bytes is stored. On calling this function, this parameter shall contain the
 *                                                 buffer length in bytes of the keyPtr. When the request has finished, the
 *                                                 actual size of the written input bytes shall be stored.
 *  \return        E_OK                            Remote service request was dispatched and processed successfully.
 *                 E_NOT_OK                        Due to an internal error, the remote service request could not
 *                                                 be dispatched or processed.
 *                 KEYM_E_PARAMETER_MISMATCH       Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Provided buffer for the certificate too small.
 *                 KEYM_E_KEY_CERT_EMPTY           No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_READ_FAIL       Certificate cannot be provided, access denied.
 *  \pre           The length of the buffer passed as keyPtr must be at least *keyLengthPtr bytes.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_DispatchRemoteKeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);

/**********************************************************************************************************************
 * KeyM_MainFunction()
 *********************************************************************************************************************/
/*! \fn           FUNC(void, KEYM_CODE) KeyM_MainFunction(void).
 *  \brief        Main function of the module. Is called cyclically and handles asynchronous jobs.
 *  \details      This interface process the provided asynchronous jobs from the queue.
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \note         Declared and called by SchM.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * KeyM_MainBackgroundFunction()
 *********************************************************************************************************************/
/*! \fn           FUNC(void, KEYM_CODE) KeyM_MainBackgroundFunction(void).
 *  \brief        Main function for background tasks.
 *  \details      Function is called from a pre-emptive operating system when no other task
 *                operation is needed. Can be used for calling time consuming synchronous
 *                functions such as KeyM_KH_Update().
 *  \pre          -
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \note         Declared and called by SchM.
 *********************************************************************************************************************/

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EXCLUSIVE AREA DEFINITION
 **********************************************************************************************************************/
/*!
 * \exclusivearea KEYM_EXCLUSIVE_AREA_0
 * Ensures consistency of global RAM variables.
 * \protects KeyM_Cert_State, KeyM_Cert_CertId, KeyM_Cert_RequestId, KeyM_Cert_UpdateFlag
 *           KeyM_Cert_CallbackOccurred, KeyM_Cert_SignatureCallbackResult
 *           KeyM_MainFunctionLock, KeyM_Remote_TaskState, KeyM_Cert_GlobalState
 * \usedin   All functions provided by KeyM except of KeyM_GetVersionInfo(), KeyM_Start(), KeyM_Prepare(),
 *           KeyM_Update(), KeyM_Finalize(), KeyM_Verify()
 * \exclude  All API functions provided by KeyM.
 * \length   SHORT Read-Modify-Write operations and state variable handling.
 * \endexclusivearea
 */

/*!
 * \exclusivearea KEYM_EXCLUSIVE_AREA_1
 * Ensures consistency of global RAM variables.
 * It protects concurrent accesses to KeyM_CertStorage by KeyM and NVM, e.g. copy operations,
 * and accesses to KeyM_NvBlock_State used for NVM handling.
 * \protects KeyM_NvBlock_State, KeyM_CertStorage
 * \usedin   All API functions provided by KeyM that passes data to the KeyM that might be stored to NVM
 *           and callout functions from NVM that gets data to be stored:
 *           KeyM_ServiceCertificate(),
 *           KeyM_SetCertificate(),
 *           KeyM_SetCertificateWithConstPtr(),
 *           KeyM_SetCertificateInGroup(),
 *           KeyM_ServiceCertificateById(),
 *           KeyM_ServiceCertificateByIdRteAdpt(),
 *           KeyM_SetCRE(),
 *           KeyM_VerifyCertificate(),
 *           KeyM_VerifyCertificates(),
 *           KeyM_VerifyCertificateChain(),
 *           KeyM_VerifyCertificateChainWithConstPtr(),
 *           KeyM_VerifyGroup(),
 *           KeyM_MainFunction(),
 *           KeyM_MainBackgroundFunction(),
 *           KeyM_NvBlock_Callback(),
 *           KeyM_NvBlock_Callback_CRE(),
 *           KeyM_NvBlock_WriteToBlock(),
 *           KeyM_NvBlock_WriteTo_CRE(),
 *           KeyM_Cert_SetCRE()
 * \exclude  All API functions provided by KeyM.
 * \length   MEDIUM Large byte arrays with sizes up to the size of the certificates are copied.
 * \endexclusivearea
 */

#endif /* KEYM_H */
/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
