/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module
 *
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
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  03.00.00   2020-03-03  visrie  PRFBL-3          Major rework to support CSM API
 *  03.00.01   2020-03-24  visrie  ESCAN00105926    Fixed encapsulation in Sec_Verification.c::SecM_VerifyMac
 *                                 ESCAN00105940    Fixed operation mode handling in Sec_Verification.c::SecM_VerifyMac
 *  03.00.02   2020-06-29  vistbe  ESCAN00106708    Compiler error: #elif with no expression in Sec_Crc.h
 *  03.00.03   2020-08-20  vistbe  ESCAN00107093    Seed generation fails
 *  03.01.00   2020-09-18  visrie  FBL-2125         Readded asymmetric configuration
 *                                 ESCAN00107432    Compiler error: SecM_CryptographicKeys is not defined
 *  03.02.00   2020-11-26  vistbe  FBL-2379         Add APIs for Key handling
 *                                 ESCAN00108033    Compiler error: incompatible function declaration/implementation
 *                                 ESCAN00108025    The FBL responds always NRC$10 on RequestTransferExit
 *  03.02.01   2020-12-09  visrie  ESCAN00108099    Key is not set to valid after copy
 *                                 ESCAN00108100    Multiple calls to SecM_GenerateSeed fails
 *  03.03.00   2021-02-02  vistbe  FBL-2959         Add support for AEADEncrypt
 *  03.04.00   2021-03-30  vistmo  FBL-2845         Add MD5 option
 *                                                  Added/adapted MemMap sections
 *  03.05.00   2021-05-19  vistbe  FBL-3247         Improvements (without CSM or CRC)
 *  03.06.00   2021-06-15  visjdn  FBL-3562         Add support for more than 256 download segments
 *  03.07.00   2021-07-09  vistbe  FBL-3565         Add support for save/restore context
 *  03.08.00   2021-09-08  vishor  FBL-2881         Add support of private keys for RSA decryption
 *  03.09.00   2021-12-16  vistbe  FBL-4473         Support of ECDSA curves
 *  03.10.00   2022-02-09  vishor  FBL-4669         Add support of PBKDF2
 *  03.11.00   2022-05-27  vistmo  FBL-5109         Support AES-GCM encryption/decryption
 *  03.11.01   2022-06-23  vishor  ESCAN00112143    Decryption with AES GCM fails
 *  03.12.00   2022-07-25  vistmo  FBL-5489         Make SeedKey optional
 *                                 ESCAN00112410    Compiler error: argument of type "void *" is incompatible with
 *                                                   parameter of type "uint32"
 *  03.12.01   2022-08-03  vishor  ESCAN00112392    Missing produced decrypted data when AES-GCM is used
 *  03.12.02   2022-09-08  vistmo  ESCAN00112104    Compiler error: Symbol SecM_JobDecryptionAEADParam is undefined
 *             2022-09-08  vistmo  ESCAN00112434    Compiler error: SecMPar.c: 'SecM_DecryptionJob' : undeclared identifier
 *             2022-09-08  vistmo  ESCAN00112113    Signature verification cannot be repeated
 *  03.13.00   2022-11-22  visjns  FBL-6128         Add support for KeyM certificates handling
 **********************************************************************************************************************/

#ifndef SEC_H
#define SEC_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : SysService_SecModHis CQComponent : Implementation */
# define SYSSERVICE_SECMODHIS_VERSION              0x0313u
# define SYSSERVICE_SECMODHIS_RELEASE_VERSION      0x00u

/** API compatible to HIS security module specification 1.1 */
#define SECM_HIS_SECURITY_MODULE_VERSION           0x010100uL

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module configuration settings */
#include "Sec_Inc.h"

/* API dependent includes */
#include "Sec_Job.h"
#include "Sec_Crc.h"
#include "Sec_Decryption.h"
#include "Sec_SeedKey.h"
#include "Sec_Verification.h"
#include "Sec_Cert.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( SEC_KEY_TIMEOUT ) && ( SEC_KEY_TIMEOUT != 0x00u )
/** Start key timer (seed value valid until timer runs out) */
# define  SecM_StartKeyTimer()   (secTimer = (SEC_KEY_TIMEOUT / SEC_CALL_CYCLE))
/** Stop key timer (invalidate seed value) */
# define  SecM_StopKeyTimer()    (secTimer = 0u)
/** Get value of key timer */
# define  SecM_GetKeyTimer()     (secTimer)

/** Decrement key timer if active (> 0) */
# define  SecM_DecrKeyTimer() \
   if (secTimer > 0u)         \
   {                          \
      secTimer--;             \
   }
#else
/* Key timer not used, seed validity never expires */
# define  SecM_StartKeyTimer()
# define  SecM_StopKeyTimer()
# define  SecM_GetKeyTimer()     (1u)
# define  SecM_DecrKeyTimer()
#endif

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/** Parameter type passed to SecM_InitPowerOn */
typedef SecM_ConstVoidPtrType   SecM_InitType;

/** Pointer type for function calls from external application */
typedef void SEC_CALL_TYPE (* pSecTaskFct)( void );

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_KEY_TIMEOUT ) && ( SEC_KEY_TIMEOUT != 0x00u )
V_MEMRAM0 extern V_MEMRAM1 SecM_ShortType V_MEMRAM2 secTimer;
#endif

#define SECM_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( __cplusplus )
extern "C" {
#endif

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

SecM_StatusType SecM_InitPowerOn( SecM_InitType initParam );
void SecM_Init( void );
void SecM_Task( void );
SecM_WordType SecM_GetInteger( SecM_ByteFastType count, SecM_ConstRamDataType buffer );
void SecM_SetInteger( SecM_ByteFastType count, SecM_WordType input, SecM_RamDataType buffer );
void SecM_CopyBuffer( SecM_ConstRamDataType input, SecM_RamDataType output, SecM_ShortType count );
void SecM_InitBuffer( SecM_RamBufferProcessingPtrType buff, SecM_ShortType size );
SecM_BufferRetType SecM_AccumulateBufferStore( SecM_RamBufferProcessingPtrType buff, SecM_ConstRamDataType src,
   SecM_RamShortType size );
SecM_BufferRetType SecM_FifoBufferStore( SecM_RamBufferProcessingPtrType buff, SecM_ConstRamDataType src,
   SecM_RamShortType srcSize, SecM_RamDataType flushBuff, SecM_RamShortType flushSize );

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( __cplusplus )
} /* extern "C" */
#endif

#endif /* SEC_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC.H
 **********************************************************************************************************************/
