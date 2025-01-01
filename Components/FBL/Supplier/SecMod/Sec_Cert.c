/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - Certificate handling through AUTOSAR KeyM
 *
 *  \description  Offers certificates handling interface
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#define SEC_CERT_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec_Cert.h"

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  SecM_InitCert
 **********************************************************************************************************************/
/*! \brief         Initialize security certificate module, if enabled through configuration.
 **********************************************************************************************************************/
void SecM_InitCert( void )
{
#if defined( SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS )
   SecM_WaitCertAsync();
#endif /* SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS */
}

#if defined( SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS )
/***********************************************************************************************************************
 *  SecM_WaitCertAsync
 **********************************************************************************************************************/
/*! \brief         In case of initialization, wait until KeyM module is initialized. Otherwise, wait until KeyM async
                    functions are completed.
 **********************************************************************************************************************/
void SecM_WaitCertAsync( void )
{
   do
   {
      KeyM_MainFunction();
      SEC_WATCHDOG_TRIGGER( SEC_WATCHDOG_TRIGGER_FNC_PTR ); /* PRQA S 2880 */ /* MD_MSR_Unreachable */
   } while ( KeyM_Cert_IsBusy() == TRUE );
}

/***********************************************************************************************************************
 *  SecM_ServiceCertificate
 **********************************************************************************************************************/
/*! \brief         Executes a specific service for a certificate and waits until the KeyM finished the service.
 *  \param[in]     service The type of service the key manager has to perform
 *  \param[in]     certNamePtr Pointer to an array that defines the name of the certificate to be updated
 *  \param[in]     certNameLength Specifies the number of bytes in CertNamePtr
 *  \param[in]     requestData Information that comes along with the request
 *  \param[in]     requestDataLength Length of data in the RequestData array
 *  \param[out]    responseData Data returned by the function
 *  \param[in]     responseDataLength Max number of bytes available in ResponseDataPtr
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
/* PRQA S 6060 4 */ /* MD_MSR_STPAR */
SecM_StatusType SecM_ServiceCertificate( SecM_ByteType service,
   SecM_ConstRamDataType certNamePtr, SecM_WordType certNameLength,
   SecM_ConstRamDataType requestData, SecM_WordType requestDataLength,
   SecM_RamDataType responseData, SecM_WordType responseDataLength )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_ServiceCertificate(service, certNamePtr, certNameLength, requestData, requestDataLength, responseData, responseDataLength) == E_OK)
   {
      result = SECM_OK;
      SecM_WaitCertAsync();
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_VerifyCertificate
 **********************************************************************************************************************/
/*! \brief         Verifies the requested certificate and waits until the KeyM finished the verification.
 *  \param[in]     certId Holds the identifier of the lower certificate in the chain
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_VerifyCertificate( SecM_ShortType certId )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_VerifyCertificate(certId) == E_OK)
   {
      result = SECM_OK;
      SecM_WaitCertAsync();
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_SetCertificate
 **********************************************************************************************************************/
/*! \brief         Provides the certificate data to the key management module to temporarily store the certificate,
                    and if successful, calls for verification of stored certificate with SecM_VerifyCertificate.
 *  \param[in]     certId Holds the identifier of the certificate
 *  \param[in]     certificateDataPtr Pointer to a structure that provides the certificate data
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_SetCertificate( SecM_ShortType certId,
   const V_MEMRAM1 SecM_CertDataType V_MEMRAM2 V_MEMRAM3 * certificateDataPtr )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_SetCertificate(certId, certificateDataPtr) == E_OK)
   {
      if (SecM_VerifyCertificate(certId) == E_OK)
      {
         result = SECM_OK;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_GetCertificate
 **********************************************************************************************************************/
/*! \brief         This function provides the certificate data.
 *  \param[in]     certId Holds the identifier of the certificate
 *  \param[in,out] certificateDataPtr Pointer to a structure that provides the certificate data
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_GetCertificate( SecM_ShortType certId,
   V_MEMRAM1 SecM_CertDataType V_MEMRAM2 V_MEMRAM3 * certificateDataPtr )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_GetCertificate(certId, certificateDataPtr) == E_OK)
   {
      result = SECM_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_CertGetStatus
 **********************************************************************************************************************/
/*! \brief         This function provides the status of a certificate.
 *  \param[in]     certId Holds the identifier of the certificate
 *  \param[out]    status Provides the status of the certificate
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_CertGetStatus( SecM_ShortType certId, SecM_RamDataType status )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_CertGetStatus(certId, status) == E_OK)
   {
      result = SECM_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_CertDelete
 **********************************************************************************************************************/
/*! \brief         Deletes certificate from certificate slot.
 *  \param[in]     certId Holds the identifier of the certificate
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_CertDelete( SecM_ShortType certId )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_CertDelete(certId) == E_OK)
   {
      result = SECM_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_CertElementGet
 **********************************************************************************************************************/
/*! \brief         Provides the content of a specific certificate element.
 *  \param[in]     certId Holds the identifier of the last certificate in the chain
 *  \param[in]     certElementId Specifies the ElementId where the data shall be read from
 *  \param[out]    certElementData Pointer to a data buffer allocated by the caller of this function
 *  \param[in,out] certElementDataLength Pointer to a value that contains the maximum data length of the buffer.
 *                  The data length will be overwritten with the actual length of data
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_CertElementGet( SecM_ShortType certId, SecM_ShortType certElementId,
   SecM_RamDataType certElementData, SecM_RamWordType certElementDataLength )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_CertElementGet(certId, certElementId, certElementData, certElementDataLength) == E_OK)
   {
      result = SECM_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_CertElementGetFirst
 **********************************************************************************************************************/
/*! \brief         Provide first part of data from certificate element.
 *  \param[in]     certId Holds the identifier of the last certificate in the chain
 *  \param[in]     certElementId Specifies the ElementId where the data shall be read from
 *  \param[in,out] certElementIterator Pointer to a structure that is allocated and maintained by the caller
 *  \param[out]    certElementData Pointer to a data buffer allocated by the caller of this function
 *  \param[in,out] certElementDataLength Pointer to a value that contains the maximum data length of the buffer.
 *                  The data length will be overwritten with the actual length of data
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_CertElementGetFirst( SecM_ShortType certId, SecM_ShortType certElementId,
   V_MEMRAM1 SecM_CertElementIteratorType V_MEMRAM2 V_MEMRAM3 * certElementIterator,
   SecM_RamDataType certElementData, SecM_RamWordType certElementDataLength )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_CertElementGetFirst(certId, certElementId, certElementIterator, certElementData, certElementDataLength) == E_OK)
   {
      result = SECM_OK;
   }

   return result;
}

/***********************************************************************************************************************
 *  SecM_CertElementGetNext
 **********************************************************************************************************************/
/*! \brief         Provide next set of data from certificate element, if a set of data located in a certificate
                    element should be read sequentialy.
 *  \pre           The function KeyM_CertElementGetFirst() has been called
 *  \param[in,out] certElementIterator  Pointer to a structure that is allocated by the caller and used by the function
 *  \param[out]    certElementData Pointer to a data buffer allocated by the caller of this function
 *  \param[in,out] certElementDataLength Pointer to a value that contains the maximum data length of the buffer.
 *                  The data length will be overwritten with the actual length of data
 *  \return        SECM_OK if successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_CertElementGetNext( V_MEMRAM1 SecM_CertElementIteratorType V_MEMRAM2 V_MEMRAM3 * certElementIterator,
   SecM_RamDataType certElementData, SecM_RamWordType certElementDataLength )
{
   SecM_StatusType result = SECM_NOT_OK;

   if (KeyM_CertElementGetNext(certElementIterator, certElementData, certElementDataLength) == E_OK)
   {
      result = SECM_OK;
   }

   return result;
}
#endif /* SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  END OF FILE: SEC_VERIFICATION.C
 **********************************************************************************************************************/
