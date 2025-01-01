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

#ifndef SEC_CERT_H
#define SEC_CERT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

# include "Sec_Inc.h"

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if defined( SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS )
typedef KeyM_CertDataType            SecM_CertDataType;
typedef KeyM_CertElementIteratorType SecM_CertElementIteratorType;
#endif /* SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS )
# define SECM_CERTIFICATE_VALID                    KEYM_CERTIFICATE_VALID
# define SECM_CERTIFICATE_INVALID                  KEYM_CERTIFICATE_INVALID
# define SECM_CERTIFICATE_NOT_PARSED               KEYM_CERTIFICATE_NOT_PARSED
# define SECM_CERTIFICATE_PARSED_NOT_VALIDATED     KEYM_CERTIFICATE_PARSED_NOT_VALIDATED
# define SECM_CERTIFICATE_NOT_AVAILABLE            KEYM_CERTIFICATE_NOT_AVAILABLE
# define SECM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL   KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL
# define SECM_E_CERTIFICATE_SIGNATURE_FAIL         KEYM_E_CERTIFICATE_SIGNATURE_FAIL
# define SECM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST
# define SECM_E_CERTIFICATE_INVALID_TYPE           KEYM_E_CERTIFICATE_INVALID_TYPE
# define SECM_E_CERTIFICATE_INVALID_FORMAT         KEYM_E_CERTIFICATE_INVALID_FORMAT
# define SECM_E_CERTIFICATE_INVALID_CONTENT        KEYM_E_CERTIFICATE_INVALID_CONTENT
# define SECM_E_CERTIFICATE_REVOKED                KEYM_E_CERTIFICATE_REVOKED
# define SECM_E_NO_PERIOD_VALIDITY_CHECK           KEYM_E_NO_PERIOD_VALIDITY_CHECK
#endif /* SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

void SecM_InitCert( void );
#if defined( SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS )
void SecM_WaitCertAsync( void );
SecM_StatusType SecM_ServiceCertificate( SecM_ByteType service,
   SecM_ConstRamDataType certNamePtr, SecM_WordType certNameLength,
   SecM_ConstRamDataType requestData, SecM_WordType requestDataLength,
   SecM_RamDataType responseData, SecM_WordType responseDataLength );
SecM_StatusType SecM_VerifyCertificate( SecM_ShortType certId );
SecM_StatusType SecM_SetCertificate( SecM_ShortType certId,
   const V_MEMRAM1 SecM_CertDataType V_MEMRAM2 V_MEMRAM3 * certificateDataPtr );
SecM_StatusType SecM_GetCertificate( SecM_ShortType certId,
   V_MEMRAM1 SecM_CertDataType V_MEMRAM2 V_MEMRAM3 * certificateDataPtr );
SecM_StatusType SecM_CertGetStatus( SecM_ShortType certId, SecM_RamDataType status );
SecM_StatusType SecM_CertDelete( SecM_ShortType certId );
SecM_StatusType SecM_CertElementGet( SecM_ShortType certId, SecM_ShortType certElementId,
   SecM_RamDataType certElementData, SecM_RamWordType certElementDataLength );
SecM_StatusType SecM_CertElementGetFirst( SecM_ShortType certId, SecM_ShortType certElementId,
   V_MEMRAM1 SecM_CertElementIteratorType V_MEMRAM2 V_MEMRAM3 * certElementIterator,
   SecM_RamDataType certElementData, SecM_RamWordType certElementDataLength );
SecM_StatusType SecM_CertElementGetNext( V_MEMRAM1 SecM_CertElementIteratorType V_MEMRAM2 V_MEMRAM3 * certElementIterator,
   SecM_RamDataType certElementData, SecM_RamWordType certElementDataLength );
#endif /* SEC_ENABLE_CERTIFICATE_OPERATION_ACCESS */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SEC_CERT_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC_VERIFICATION.H
 **********************************************************************************************************************/
