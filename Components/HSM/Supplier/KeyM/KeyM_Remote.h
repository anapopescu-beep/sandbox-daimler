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
/*!        \file  KeyM_Remote.h
 *         \unit  *
 *        \brief  Header file of remote service handling
 *      \details  Implementation of remote service handling
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined KEYM_REMOTE_H
# define KEYM_REMOTE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "KeyM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Remote task state */
# define KEYM_REMOTE_TASKSTATE_IDLE                                   (0x00u)
# define KEYM_REMOTE_TASKSTATE_BUSY                                   (0x01u)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern VAR(uint8, KEYM_VAR_NO_INIT) KeyM_Remote_TaskState;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define KEYM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectServiceCertificate()
 *********************************************************************************************************************/
 /*! \brief        Redirects service request of KeyM_ServiceCertificate to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     Service                              Provides the type of service the key manager has to perform.
 *  \param[in]     CertNamePtr                          Points to an array that defines the name of the certificate to
 *                                                      be updated
 *  \param[in]     CertNameLength                       Specifies the number of bytes in CertNamePtr. The value 0
 *                                                      indicates that no CertNamePtr is provided within this function.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \param[out]    ResponseData                         Data returned by the function.
 *  \param[in]     ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed
 *                                                      due to an internal error.
 *                 KEYM_E_BUSY                          KeyM is currently busy with other remote jobs.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectServiceCertificate(
  KeyM_CertificateIdType CertId,
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
# endif

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
#  if (KEYM_REMOTE_OCSPENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectServiceCertificateOCSP()
 *********************************************************************************************************************/
/*! \brief         Redirects OCSP service request of KeyM_ServiceCertificate to remote Crypto driver.
 *  \details       -
 *  \param[in]     Service                              Provides the type of service the key manager has to perform.
 *  \param[in]     CertNamePtr                          Points to an array that defines the name of the certificate to
 *                                                      be updated
 *  \param[in]     CertNameLength                       Specifies the number of bytes in CertNamePtr. The value 0
 *                                                      indicates that no CertNamePtr is provided within this function.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \param[out]    ResponseData                         Data returned by the function.
 *  \param[in]     ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed
 *                                                      due to an internal error.
 *                 KEYM_E_BUSY                          KeyM is currently busy with other remote jobs.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectServiceCertificateOCSP(
  KeyM_ServiceCertificateType Service,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) CertNamePtr,
  uint32 CertNameLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
#  endif
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_SERVICE_CERTIFICATE_FUNCTION_ENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE */
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectServiceCertificateById()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_ServiceCertificateById to remote Crypto driver.
 *  \details       -
 *  \param[in]     Service                              Provides the type of service the key manager has to perform.
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     RequestData                          Information that comes along with the request.
 *  \param[in]     RequestDataLength                    Length of data in the RequestData array.
 *  \param[out]    ResponseData                         Data returned by the function.
 *  \param[in]     ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *                                                      due to an internal error.
 *                 KEYM_E_BUSY                          KeyM is currently busy with other remote jobs.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectServiceCertificateById(
  KeyM_ServiceCertificateType Service,
  KeyM_CertificateIdType CertId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) ResponseData,
  uint32 ResponseDataLength);
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
# endif

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectSetCertificate()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_SetCertificate to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertificateDataPtr               Pointer to a structure that provides the certificate data.
 *  \return        E_OK                             Redirected remote service request successfully.
 *                 E_NOT_OK                         Redirection or processing of remote service failed.
 *                                                  due to an internal error.
 *  \pre           All provided pointers must be valid. In particular, also the pointer contained in CertificateDataPtr
 *                 must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectSetCertificate(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) CertificateDataPtr);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectGetCertificate()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_GetCertificate to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in,out] CertificateDataPtr               Provides a pointer to a certificate data structure. The buffer
 *                                                  located by the pointer in the structure shall be provided by the
 *                                                  caller of this function. The length information indicates the
 *                                                  maximum length of the buffer when the function is called. If
 *                                                  E_OK is returned, the length information indicates the actual
 *                                                  length of the certificate data in the buffer.
 *  \return        E_OK                             Redirected remote service request successfully.
 *                 E_NOT_OK                         Redirection or processing of remote service failed.
 *                                                  due to an internal error.
 *  \pre           All provided pointers must be valid. In particular, also the pointer contained in CertificateDataPtr
 *                 must be valid.
 *                 CertId must be a valid certId
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectGetCertificate(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertDataType, AUTOMATIC, KEYM_APPL_VAR) CertificateDataPtr);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectCertElementGet()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_CertElementGet to remote Crypto driver.
 *  \details       -
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
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertElementGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectCertificateElementGetByIndex()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_CertificateElementGetByIndex to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the iterable certificate element.
 *  \param[in]     Index                                This is the index to the respective element in the list of
 *                                                      iterable elements.
 *  \param[out]    CertElementData                      Pointer to a data buffer for the iterable certificate element.
 *  \param[in,out] CertElementDataLength                In: Pointer to a value that contains the maximum data
 *                                                      length of the CertificateElementData buffer.
 *                                                      Out: The data length will be overwritten with the actual
 *                                                      length of data placed to the buffer if the function returns
 *                                                      E_OK.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertificateElementGetByIndex(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  uint16 Index,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertElementData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertElementDataLength);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectCertificateElementGetCount()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_CertificateElementGetCount to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the certificate element.
 *  \param[out]    Count                                Total number of iterable certificate elements.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertificateElementGetCount(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  P2VAR(uint16, AUTOMATIC, KEYM_APPL_VAR) Count);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectSetCertificateInGroup()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_SetCertificateInGroup to remote Crypto driver.
 *  \details       -
 *  \param[in]     GroupId                              Holds the identifier of the certificate group.
 *  \param[in]     RequestData                          Pointer to the certificate data.
 *  \param[in]     RequestDataLength                    Holds the length of the certificate data.
 *  \param[out]    CertId                               Holds the certificate identifier of the slot where data has
 *                                                      been installed.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *                 KEYM_E_BUSY                          KeyM is currently busy with other remote jobs.
 *  \pre           All provided pointers must be valid.
 *                 groupId < KeyM_GetSizeOfCertificateGroup()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectSetCertificateInGroup(
  KeyM_CertificateGroupIdType GroupId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) RequestData,
  uint32 RequestDataLength,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) CertId);
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
# endif

# if (KEYM_CERTIFICATEGROUPUSEDOFCERTIFICATE == STD_ON)
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectVerifyGroup()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_VerifyGroup to remote Crypto driver.
 *  \details       -
 *  \param[in]     GroupId                               Holds the identifier of the certificate group.
 *  \return        E_OK                                  Redirected remote service request successfully.
 *                 E_NOT_OK                              Redirection or processing of remote service failed.
 *                 KEYM_E_BUSY                          KeyM is currently busy with other remote jobs.
 *  \pre           groupId must be a valid group ID, i.e., groupId < KeyM_GetSizeOfCertificateGroup()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectVerifyGroup(
  KeyM_CertificateGroupIdType GroupId);
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
# endif

# if (KEYM_CRE == STD_ON)
#  if (KEYM_REMOTE_CREENABLED == STD_ON) /* COV_KEYM_REQUIRED_FOR_SAFE*/
/**********************************************************************************************************************
 * KeyM_Remote_RedirectSetCRE()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_SetCRE to remote Crypto driver.
 *  \details       -
 *  \param[in]     IssuerNameData                   Points to an array that defines the issuer common name of the
 *                                                  revoked certificate.
 *  \param[in]     IssuerNameDataLength             Length of issuer common name data.
 *  \param[in]     SerialNumberData                 Points to an array that defines the serial number of the revoked
 *                                                  certificate.
 *  \param[in]     SerialNumberDataLength           Length of serial number data.
 *  \return        E_OK                             Redirected remote service request successfully.
 *                 E_NOT_OK                         Redirection or processing of remote service failed.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectSetCRE(
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) IssuerNameData,
  uint16 IssuerNameDataLength,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) SerialNumberData,
  uint16 SerialNumberDataLength);
#  endif
# endif

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectCertStructureGet()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_CertStructureGet to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[in]     CertStructure                    Holds the certificate structure type.
 *  \param[out]    CertStructureData                Data returned by the function.
 *  \param[in,out] CertStructureDataLength          In: Max number of bytes available in CertStructureData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Redirected remote service request successfully.
 *                 E_NOT_OK                         Redirection or processing of remote service failed.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertStructureGet(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateStructureType CertStructure,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) CertStructureData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) CertStructureDataLength);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectGetIssuerCertId()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_GetIssuerCertId to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                Holds the certificate identifier.
 *  \param[out]    IssuerCertId          Holds the certificate identifier of the issuer this function returns.
 *  \return        E_OK                  Redirected remote service request successfully.
 *                 E_NOT_OK              Redirection or processing of remote service failed.
 *  \pre           CertId must be a valid certificateID.
 *                 All provided pointers must be valid.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectGetIssuerCertId(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateIdType, AUTOMATIC, KEYM_APPL_VAR) IssuerCertId);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectGetCertHash()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_GetCertHash to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                           Holds the identifier of the certificate.
 *  \param[out]    HashData                         Data returned by the function.
 *  \param[in,out] HashDataLength                   In: Max number of bytes available in HashData.
 *                                                  Out: Actual number.
 *  \return        E_OK                             Redirected remote service request successfully.
 *                 E_NOT_OK                         Redirection or processing of remote service failed.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectGetCertHash(
  KeyM_CertificateIdType CertId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) HashData,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) HashDataLength);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_CERTIFICATE_SIGNING_REQUEST_ENABLED == STD_ON)
#  if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectCsrElementSet()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_CsrElementSet to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[in]     CertElementId                        Holds the identifier of the certificate element.
 *  \param[in]     EncodingType                         Holds the encoding type of the certificate element.
 *  \param[in]     ElementData                          Points to an array of element data.
 *  \param[in]     ElementDataLength                    Max number of bytes available in ElementData.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCsrElementSet(
  KeyM_CertificateIdType CertId,
  KeyM_CertElementIdType CertElementId,
  KeyM_CsrEncodingType EncodingType,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_DATA) ElementData,
  uint32 ElementDataLength);
#  endif /* KEYM_REMOTE_REDIRECTION_ENABLED */
# endif

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectCertGetStatus()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_CertGetStatus to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the certificate.
 *  \param[out]    Status                               Provides the status of the certificate.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *  \pre           All provided pointers must be valid.
 *                 CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectCertGetStatus(
  KeyM_CertificateIdType CertId,
  P2VAR(KeyM_CertificateStatusType, AUTOMATIC, KEYM_APPL_VAR) Status);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectVerifyCertificates()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_VerifyCertificates to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the lower certificate in the chain.
 *  \param[in]     CertUpperId                          Holds the identifier of the upper certificate in the chain.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *                 KEYM_E_BUSY                          KeyM is currently busy with other remote jobs.
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *                 CertUpperId must be a valid certificate ID, i.e., CertUpperId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectVerifyCertificates(
  KeyM_CertificateIdType CertId,
  KeyM_CertificateIdType CertUpperId);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectVerifyCertificate()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_VerifyCertificate to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the lower certificate in the chain.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *                 KEYM_E_BUSY                          KeyM is currently busy with other remote jobs.
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectVerifyCertificate(
  KeyM_CertificateIdType CertId);
# endif /* KEYM_REMOTE_REDIRECTION_ENABLED */

# if (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * KeyM_Remote_RedirectVerifyCertificateChain()
 *********************************************************************************************************************/
/*! \brief         Redirects service request of KeyM_VerifyCertificateChain to remote Crypto driver.
 *  \details       -
 *  \param[in]     CertId                               Holds the identifier of the last certificate in the chain.
 *  \param[in]     certChainData                        This is a pointer to an array of certificates sorted according
 *                                                      to the order in the PKI.
 *  \param[in]     NumberOfCertificates                 Defines the number of certificates stored in the CertChainData
 *                                                      array.
 *  \return        E_OK                                 Redirected remote service request successfully.
 *                 E_NOT_OK                             Redirection or processing of remote service failed.
 *                 KEYM_E_BUSY                          KeyM is currently busy with other remote jobs.
 *  \pre           CertId must be a valid certificate ID, i.e., CertId < KeyM_GetSizeOfCertificate()
 *                 certChainData and all contained certData pointers must be valid
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_RedirectVerifyCertificateChain(
  KeyM_CertificateIdType CertId,
  P2CONST(KeyM_ConstCertDataType, AUTOMATIC, KEYM_APPL_DATA) certChainData,
  uint8 NumberOfCertificates);
# endif /* (KEYM_REMOTE_REDIRECTION_ENABLED == STD_ON) */

# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_DispatchRemoteJob()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_DispatchRemoteJob.
 *  \details       Refer to KeyM_DispatchRemoteJob.
 *  \param[in]     job                     Pointer to the configuration of the job. Contains structures with job and
 *                                         primitive relevant information but also pointer to result buffers.
 *  \return        E_OK                                 Service data operation successfully accepted.
 *                 E_NOT_OK                             Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *                 KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                      currently busy with other jobs.
 *                 KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *                 KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_DispatchRemoteJob(
  P2CONST(Crypto_JobType, AUTOMATIC, KEYM_APPL_VAR) job);
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_DispatchRemoteKeyElementSet()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_DispatchRemoteKeyElementSet.
 *  \details       Refer to KeyM_DispatchRemoteKeyElementSet.
 *  \param[in]     cryptoKeyId                     Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId                    Holds the identifier of the key element which shall be set.
 *  \param[in]     keyPtr                          Holds the pointer to the key data which shall be set as key element.
 *  \param[in]     keyLength                       Contains the length of the key element in bytes.
 *  \return        E_OK                            Certificate accepted.
 *                 E_NOT_OK                        Certificate could not be set.
 *                 KEYM_E_PARAMETER_MISMATCH       Parameter does not match with expected value.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Parameter size doesn't match.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_DispatchRemoteKeyElementSet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  uint32 keyLength);
# endif /* KEYM_REMOTE_DISPATCHING_ENABLED */

# if (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) /* COV_KEYM_UNSUPPORTED */
/**********************************************************************************************************************
 * KeyM_Remote_DispatchRemoteKeyElementGet()
 *********************************************************************************************************************/
/*! \brief         Internal implementation of KeyM_DispatchRemoteKeyElementGet.
 *  \details       Refer to KeyM_DispatchRemoteKeyElementGet.
 *  \param[in]     cryptoKeyId                     Holds the identifier of the key whose key element shall be set.
 *  \param[in]     keyElementId                    Holds the identifier of the key element which shall be set.
 *  \param[out]    keyPtr                          Holds the pointer to the memory location where the key shall be copied to.
 *  \param[in,out] keyLengthPtr                    Holds a pointer to the memory location in which the output buffer length in
 *                                                 bytes is stored. On calling this function, this parameter shall contain the
 *                                                 buffer length in bytes of the keyPtr. When the request has finished, the
 *                                                 actual size of the written input bytes shall be stored.
 *  \return        E_OK                            Certificate data available and provided.
 *                 E_NOT_OK                        Operation not accepted due to an internal error.
 *                 KEYM_E_PARAMETER_MISMATCH       Certificate ID invalid.
 *                 KEYM_E_KEY_CERT_SIZE_MISMATCH   Provided buffer for the certificate too small.
 *                 KEYM_E_KEY_CERT_EMPTY           No certificate data available, the certificate slot is empty.
 *                 KEYM_E_KEY_CERT_READ_FAIL       Certificate cannot be provided, access denied.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, KEYM_CODE) KeyM_Remote_DispatchRemoteKeyElementGet(
  uint32 cryptoKeyId,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, KEYM_APPL_VAR) keyPtr,
  P2VAR(uint32, AUTOMATIC, KEYM_APPL_VAR) keyLengthPtr);
# endif /* (KEYM_REMOTE_DISPATCHING_ENABLED == STD_ON) */

# define KEYM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* KEYM_REMOTE_H */
/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/
