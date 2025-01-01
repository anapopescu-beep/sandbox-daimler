/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Diagnostic module external interface
 *                 Declaration of functions, variables, and constants
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
 *  04.00.00   2018-09-11  visrie  ESCAN00100691    General rework
 *  04.01.00   2019-03-05  visrie  ESCAN00102341    No changes
 *                         visach  ESCAN00102368    No changes
 *  04.02.00   2019-08-01  visrcn  ESCAN00103927    Migrate implementation to MISRA 2012
 *  04.02.01   2019-10-08  visrcn  ESCAN00104279    No changes
 *  04.03.00   2020-05-07  visrie  FBL-1414         Added support for One-Step-Updater
 *  04.04.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *  04.05.00   2020-11-12  visrie  FBL-938          Added additional communication control types
 *  04.06.00   2021-01-21  visjdn  ESCAN00107631    Pipelined programming fails
 *  04.07.00   2021-05-14  visjdn  FBL-3365         Added/adapted MemMap sections
 *  04.08.00   2021-06-16  vishor  FBL-3564         No changes
 *  04.09.00   2021-10-12  vistmo  FBL-3901         Added support for Authentication service 0x29 and new NRC 0x34
 *  04.10.00   2022-01-14  vishor  FBL-4160         Support default implementation of NRC21
 *  04.11.00   2022-02-01  vistmo  FBL-4566         No changes
 *  04.12.00   2022-04-28  vishor  FBL-4311         Add support for OTA APIs
 *  04.12.01   2022-06-14  vishor  ESCAN00110534    Behavior after startup might not be correct
 *  04.12.02   2022-10-13  visjns  ESCAN00112693    No changes
 *  04.13.00   2022-11-17  visjns  FBL-6136         Add additional subfunction defines for service 29
 *                                 ESCAN00112998    No changes
 *  04.14.00   2022-11-30  vismix  FBL-6046         No changes
 *  04.15.00   2022-12-06  vistmo  FBL-6140         No changes
 **********************************************************************************************************************/

#ifndef FBL_DIAG_H
#define FBL_DIAG_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* OEM specific interface additions */
#include "fbl_diag_oem.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#define FBLDIAG_14229_CORE_VERSION           0x0415u
#define FBLDIAG_14229_CORE_RELEASE_VERSION   0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Diagnostic base timing */
#if !defined( kDiagCallCycle )
# define kDiagCallCycle    1u
#endif

/* Maximum segment size of all memory devices */
#define FBL_DIAG_SEGMENT_SIZE                   FBL_MAX_SEGMENT_SIZE

/* Generic helper macros */
#define GET_ID_HIGH(id)                         ((vuint8)(((id) >> 8u) & 0xFFu)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define GET_ID_LOW(id)                          ((vuint8)((id) & 0xFFu)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if defined( FBL_CW_ENABLE_DECLINED_REQUESTS )
# if !defined( FBL_DIAG_DECLINE_BUFFER_LENGTH )
#  define FBL_DIAG_DECLINE_BUFFER_LENGTH     8u  /** Buffer size to handle messages on additional connections. */
# endif
#endif

#if !defined( kBlockNrInvalid )
# define kBlockNrInvalid    0xFFu
#endif

/***********************************************************************************************************************
 *  Core state definitions
 **********************************************************************************************************************/

/* Bootloader states */
#define kFblDiagStateSessionDefault             0u
#define kFblDiagStateSessionExtended            1u
#define kFblDiagStateSessionProgramming         2u
#define kFblDiagStateFunctionalRequest          3u
#define kFblDiagStateDiagBufferLocked           4u
#define kFblDiagStateExecutePostHandler         5u
#define kFblDiagStateServiceInProgress          6u
#define kFblDiagStateRcrRpAllowed               7u
#define kFblDiagStateRcrRpInProgress            8u
#define kFblDiagStateSuppressPosRspMsg          9u
#define kFblDiagStateServiceHasSubfunction      10u
#define kFblDiagStateResponseProcessing         11u
#define kFblDiagStateTransferTypeFlash          12u
#define kFblDiagStateRespBufLockedByInit        13u
/* Reset handling */
#define kFblDiagStateWaitEcuReset               14u
#define kFblDiagStateEcuResetFctFinished        15u
#define kFblDiagStateResetMsgConfirmed          16u
/* Generic download handling */
#define kFblDiagStatePreconditionsChecked       17u
#define kFblDiagStateMemDriverInitialized       18u

#define kFblDiagLastCoreStateIdx                kFblDiagStateMemDriverInitialized

/* Number of states (Core and OEM) */
#define kFblDiagNumberOfStates                  ( kFblDiagLastOemStateIdx + 1u )
#define kFblDiagNumberOfDispatchStates          kFblDiagNumberOfStates

/* Diagnostic handling states */
#define FblDiagGetDefaultSession()              GetFblDiagState( kFblDiagStateSessionDefault )
#define FblDiagGetProgrammingSession()          GetFblDiagState( kFblDiagStateSessionProgramming )
#define FblDiagGetExtendedSession()             GetFblDiagState( kFblDiagStateSessionExtended )
#define FblDiagGetBufferLocked()                GetFblDiagState( kFblDiagStateDiagBufferLocked )
#define FblDiagGetExecutePostHandler()          GetFblDiagState( kFblDiagStateExecutePostHandler )
#define FblDiagGetRcrRpAllowed()                GetFblDiagState( kFblDiagStateRcrRpAllowed )
#define FblDiagGetRcrRpInProgress()             GetFblDiagState( kFblDiagStateRcrRpInProgress )
#define FblDiagGetResponseProcessing()          GetFblDiagState( kFblDiagStateResponseProcessing )
#define FblDiagGetSuppressPosRspMsg()           GetFblDiagState( kFblDiagStateSuppressPosRspMsg )
#define FblDiagGetServiceHasSubfunction()       GetFblDiagState( kFblDiagStateServiceHasSubfunction )
#define FblDiagGetServiceInProgress()           GetFblDiagState( kFblDiagStateServiceInProgress )
#define FblDiagGetFunctionalRequest()           GetFblDiagState( kFblDiagStateFunctionalRequest )
#define FblDiagGetTransferTypeFlash()           GetFblDiagState( kFblDiagStateTransferTypeFlash )
#define FblDiagGetRespBufLockedByInit()         GetFblDiagState( kFblDiagStateRespBufLockedByInit )
/* Reset handling states */
#define FblDiagGetWaitEcuReset()                GetFblDiagState( kFblDiagStateWaitEcuReset )
#define FblDiagGetEcuResetFctFinished()         GetFblDiagState( kFblDiagStateEcuResetFctFinished )
#define FblDiagGetResetMsgConfirmed()           GetFblDiagState( kFblDiagStateResetMsgConfirmed )
/* Generic download states */
#define FblDiagGetPreconditionsChecked()        GetFblDiagState( kFblDiagStatePreconditionsChecked )
#define FblDiagGetMemDriverInitialized()        GetFblDiagState( kFblDiagStateMemDriverInitialized )

/* Compatibility defines */
#define GetDiagDefaultSession()                 FblDiagGetDefaultSession()
#define GetDiagProgrammingSession()             FblDiagGetProgrammingSession()
#define GetDiagExtendedSession()                FblDiagGetExtendedSession()
#define GetDiagBufferLocked()                   FblDiagGetBufferLocked()
#define GetRcrRpInProgress()                    FblDiagGetRcrRpInProgress()
#define GetMemDriverInitialized()               FblDiagGetMemDriverInitialized()

/***********************************************************************************************************************
 *  State handling framework
 **********************************************************************************************************************/

#define FBL_DIAG_STATECHECK_ARRAYSIZE        (((kFblDiagNumberOfDispatchStates - 1u) / FBL_STATE_BITS) + 1u)

/* State access macros */
#define GetFblDiagState(state)               FBL_STATE_TEST(fblDiagStates, (state)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Diagnostic state handling */
/* Control macros */
#define FBL_DIAG_STATE_CHECK_COUNT  0u
#define FBL_DIAG_STATE_ADDCLR_COUNT 0u
#define FBL_DIAG_STATE_COUNT        (FBL_DIAG_STATE_CHECK_COUNT + FBL_DIAG_STATE_ADDCLR_COUNT)

/* State array build macros */
#define FBL_DIAG_STATE_ARRAYENTRY(mask, idx)    ((tFblStateBitmap)(((mask) >> ((idx) * FBL_STATE_BITS)) & kFblDiagStateMaskAll))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#if (FBL_DIAG_STATECHECK_ARRAYSIZE == 1u)
# define FBL_STATE_BUILDARRAYENTRIES(mask)      FBL_STATE_ARRAYENTRY(mask, 0u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif
#if (FBL_DIAG_STATECHECK_ARRAYSIZE == 2u)
# define FBL_STATE_BUILDARRAYENTRIES(mask)      FBL_STATE_ARRAYENTRY(mask, 0u), FBL_STATE_ARRAYENTRY(mask, 1u)   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif
#if (FBL_DIAG_STATECHECK_ARRAYSIZE == 3u)
# define FBL_STATE_BUILDARRAYENTRIES(mask)      FBL_STATE_ARRAYENTRY(mask, 0u), FBL_STATE_ARRAYENTRY(mask, 1u), FBL_STATE_ARRAYENTRY(mask, 2u)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif
#if (FBL_DIAG_STATECHECK_ARRAYSIZE == 4u)
# define STATE_BUILDARRAYENTRIES(mask)          FBL_STATE_ARRAYENTRY(mask, 0u), FBL_STATE_ARRAYENTRY(mask, 1u), FBL_STATE_ARRAYENTRY(mask, 2u), FBL_STATE_ARRAYENTRY(mask, 3u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif
#if (FBL_DIAG_STATECHECK_ARRAYSIZE > 4u)
# error "Invalid array size for state check!"
#endif

#define DIAG_STATE_BUILDARRAY(mask)             { DIAG_STATE_BUILDARRAYENTRIES(mask) }

/* State masks and access macros */
#define kFblDiagStateMaskAllLong                FBL_STATE_MULTIMASKLONG(0u, ((FBL_DIAG_STATECHECK_ARRAYSIZE * FBL_STATE_BITS) - 1u))

#define kFblDiagStateMask(state)                FBL_STATE_MASKLONG(state)   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define SetFblDiagState(state)                  FBL_STATE_SET(fblDiagStates, state)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define ClrFblDiagState(state)                  FBL_STATE_CLR(fblDiagStates, state)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/***********************************************************************************************************************
 *  Service handling
 **********************************************************************************************************************/


/* Diagnostic services */
#define kDiagSidDiagnosticSessionControl                 0x10u    /**< Service ID - Diagnostic session control */
#define kDiagSidEcuReset                                 0x11u    /**< Service ID - ECU reset */
#define kDiagSidClearDiagInfo                            0x14u    /**< Service ID - Clear Diagnostic Information */
#define kDiagSidReadDTCInformation                       0x19u    /**< Service ID - Read DTC information */
#define kDiagSidReadDataByIdentifier                     0x22u    /**< Service ID - Read data by Identifier */
#define kDiagSidSecurityAccess                           0x27u    /**< Service ID - Security Access */
#define kDiagSidCommunicationControl                     0x28u    /**< Service ID - Communication Control */
#define kDiagSidAuthentication                           0x29u    /**< Service ID - Authentication */
#define kDiagSidWriteDataByIdentifier                    0x2Eu    /**< Service ID - Write data by Identifier */
#define kDiagSidRoutineControl                           0x31u    /**< Service ID - Routine Control */
#define kDiagSidRequestDownload                          0x34u    /**< Service ID - Request Download */
#define kDiagSidTransferData                             0x36u    /**< Service ID - Transfer Data */
#define kDiagSidRequestTransferExit                      0x37u    /**< Service ID - Request Transfer Exit */
#define kDiagSidTesterPresent                            0x3Eu    /**< Service ID - Tester Present */
#define kDiagSidControlDTCSetting                        0x85u    /**< Service ID - Control DTC */
#define kDiagSidLinkControl                              0x87u    /**< Service ID - Link Control */

/* Response identifier service definition */
#define kDiagRidNegativeResponse                         0x7Fu    /**< Service ID - Negative response */

/* Diagnostic sub-services */
#define kDiagSuppressPosRspMsgIndicationBit              0x80u

/* DiagnosticSessionControl */
#define kDiagSubDefaultSession                           0x01u    /**< Subservice ID - Default session */
#define kDiagSubProgrammingSession                       0x02u    /**< Subservice ID - Programming session */
#define kDiagSubExtendedDiagSession                      0x03u    /**< Subservice ID - Extended session */

/* TesterPresent */
#define kDiagSubTesterPresent                            0x00u    /**< Subservice ID - Zero subfunction */

/* ECUReset */
#define kDiagSubHardReset                                0x01u    /**< Subservice ID - Hard reset */
#define kDiagSubKeyOffOnReset                            0x02u    /**< Subservice ID - Key Off/On reset */
#define kDiagSubSoftReset                                0x03u    /**< Subservice ID - Soft reset */

/* ReadDTCInformation */
#define kDiagSubReportDTCByStatusMask                    0x02u    /**< Subservice ID - Report DTC by status mask */

/* CommunicationControl */
#define kDiagSubEnableRxAndTx                            0x00u    /**< ControlType - Enable Rx and Tx */
#define kDiagSubEnableRxAndDisableTx                     0x01u    /**< ControlType - Enable Rx and Disable Tx */
#define kDiagSubDisableRxAndEnableTx                     0x02u    /**< ControlType - Disable Rx and Enable Tx */
#define kDiagSubDisableRxAndTx                           0x03u    /**< ControlType - Disable Rx and Tx */
#define kDiagSubEnableRxAndDisableTxEnhAddrInfo          0x04u    /**< ControlType - Enable Rx and Disable Tx with Enhanced Address Information */
#define kDiagSubEnableRxAndTxEnhAddrInfo                 0x05u    /**< ControlType - Enable Rx and Tx with Enhanced Address Information */
#define kDiagSubNormalCommunication                      0x01u    /**< Communication type - normal communication */
#define kDiagSubNmCommunication                          0x02u    /**< Communication type - network management communication */
#define kDiagSubNmAndNormalCommunication                 0x03u    /**< Communication type - network management and normal communication */

/* Authentication */
#define kFblDiagSubDeAuthenticate                        0x00u    /**< Subservice ID - Request to leave the authenticated state */
#define kFblDiagSubVerifyCertificateUnidir               0x01u    /**< Subservice ID - Initiate authentication by verifying the certificate */
#define kFblDiagSubVerifyCertificateBidir                0x02u    /**< Subservice ID - Request certificate verification and Proof of Ownership generation */
#define kFblDiagSubProofOfOwnership                      0x03u    /**< Subservice ID - Verify the Proof of Ownership from the client */
#define kFblDiagSubTransmitCertificate                   0x04u    /**< Subservice ID - Verify and handle certificate */
#define kFblDiagSubRequestChallengeForAuth               0x05u    /**< Subservice ID - Request challenge for authentication */
#define kFblDiagSubVerifyProofOfOwnership                0x06u    /**< Subservice ID - Verify proof of ownership */
#define kFblDiagSubVerifyProofOfOwnershipBidir           0x07u    /**< Subservice ID - Verify the client side POWN and provide server-side POWN */
#define kFblDiagSubAuthenticationConfiguration           0x08u    /**< Subservice ID - Indicates the authentication configuration of the server */

/* RoutineControl, routineControlType */
#define kDiagSubStartRoutine                             0x01u
#define kDiagSubStopRoutine                              0x02u
#define kDiagSubRequestRoutineResults                    0x03u

/***********************************************************************************************************************
 *  Error handling
 **********************************************************************************************************************/


/* Negative Response Codes */
#define kDiagErrorNone                                   0x00u
#define kDiagNrcGeneralReject                            0x10u
#define kDiagNrcServiceNotSupported                      0x11u
#define kDiagNrcSubFunctionNotSupported                  0x12u
#define kDiagNrcIncorrectMessageLengthOrInvalidFormat    0x13u
#define kDiagNrcResponseTooLong                          0x14u
#define kDiagNrcBusyRepeatRequest                        0x21u
#define kDiagNrcConditionsNotCorrect                     0x22u
#define kDiagNrcRequestSequenceError                     0x24u
#define kDiagNrcRequestOutOfRange                        0x31u
#define kDiagNrcSecurityAccessDenied                     0x33u
#define kDiagNrcAuthenticationRequired                   0x34u
#define kDiagNrcInvalidKey                               0x35u
#define kDiagNrcExceedNumberOfAttempts                   0x36u
#define kDiagNrcRequiredTimeDelayNotExpired              0x37u
#define kDiagNrcCertVerFailedInvalidTimePeriod           0x50u
#define kDiagNrcCertVerFailedInvalidSignature            0x51u
#define kDiagNrcCertVerFailedInvalidChainOfTrust         0x52u
#define kDiagNrcCertVerFailedInvalidType                 0x53u
#define kDiagNrcCertVerFailedInvalidFormat               0x54u
#define kDiagNrcCertVerFailedInvalidContent              0x55u
#define kDiagNrcCertVerFailedInvalidScope                0x56u
#define kDiagNrcCertVerFailedInvalidCertificateRevoked   0x57u
#define kDiagNrcOwnershipVerificationFailed              0x58u
#define kDiagNrcChallengeCalculationFailed               0x59u
#define kDiagNrcSettingAccessRightsFailed                0x5Au
#define kDiagNrcSessionKeyCreationDerivationFailed       0x5Bu
#define kDiagNrcConfigurationDataUsageFailed             0x5Cu
#define kDiagNrcDeAuthenticationFailed                   0x5Du
#define kDiagNrcUploadDownloadNotAccepted                0x70u
#define kDiagNrcTransferDataSuspended                    0x71u
#define kDiagNrcGeneralProgrammingFailure                0x72u
#define kDiagNrcWrongBlockSequenceCounter                0x73u
#define kDiagNrcIllegalByteCountInBlockTransfer          0x75u
#define kDiagNrcRcrResponsePending                       0x78u
#define kDiagNrcSubfunctionNotSupportedInActiveSession   0x7Eu
#define kDiagNrcServiceNotSupportedInActiveSession       0x7Fu
#define kDiagNrcVoltageTooHigh                           0x92u
#define kDiagNrcVoltageTooLow                            0x93u

/* Diagnostic exception setting macros */
#define DiagNRCGeneralReject()                           FblDiagSetError(kDiagNrcGeneralReject)
#define DiagNRCServiceNotSupported()                     FblDiagSetError(kDiagNrcServiceNotSupported)
#define DiagNRCSubFunctionNotSupported()                 FblDiagSetError(kDiagNrcSubFunctionNotSupported)
#define DiagNRCIncorrectMessageLengthOrInvalidFormat()   FblDiagSetError(kDiagNrcIncorrectMessageLengthOrInvalidFormat)
#define DiagNRCResponseTooLong()                         FblDiagSetError(kDiagNrcResponseTooLong)
#define DiagNRCBusyRepeatRequest()                       FblDiagSetError(kDiagNrcBusyRepeatRequest)
#define DiagNRCConditionsNotCorrect()                    FblDiagSetError(kDiagNrcConditionsNotCorrect)
#define DiagNRCRequestSequenceError()                    FblDiagSetError(kDiagNrcRequestSequenceError)
#define DiagNRCRequestOutOfRange()                       FblDiagSetError(kDiagNrcRequestOutOfRange)
#define DiagNRCSecurityAccessDenied()                    FblDiagSetError(kDiagNrcSecurityAccessDenied)
#define DiagNRCAuthenticationRequired()                  FblDiagSetError(kDiagNrcAuthenticationRequired)
#define DiagNRCInvalidKey()                              FblDiagSetError(kDiagNrcInvalidKey)
#define DiagNRCExceedNumberOfAttempts()                  FblDiagSetError(kDiagNrcExceedNumberOfAttempts)
#define DiagNRCRequiredTimeDelayNotExpired()             FblDiagSetError(kDiagNrcRequiredTimeDelayNotExpired)
#define DiagNRCCertVerFailedInvalidTimePeriod()          FblDiagSetError(kDiagNrcCertVerFailedInvalidTimePeriod)
#define DiagNRCCertVerFailedInvalidSignature()           FblDiagSetError(kDiagNrcCertVerFailedInvalidSignature)
#define DiagNRCCertVerFailedInvalidChainOfTrust()        FblDiagSetError(kDiagNrcCertVerFailedInvalidChainOfTrust)
#define DiagNRCCertVerFailedInvalidType()                FblDiagSetError(kDiagNrcCertVerFailedInvalidType)
#define DiagNRCCertVerFailedInvalidFormat()              FblDiagSetError(kDiagNrcCertVerFailedInvalidFormat)
#define DiagNRCCertVerFailedInvalidContent()             FblDiagSetError(kDiagNrcCertVerFailedInvalidContent)
#define DiagNRCCertVerFailedInvalidScope()               FblDiagSetError(kDiagNrcCertVerFailedInvalidScope)
#define DiagNRCCertVerFailedInvalidCertificateRevoked()  FblDiagSetError(kDiagNrcCertVerFailedInvalidCertificateRevoked)
#define DiagNRCOwnershipVerificationFailed()             FblDiagSetError(kDiagNrcOwnershipVerificationFailed)
#define DiagNRCChallengeCalculationFailed()              FblDiagSetError(kDiagNrcChallengeCalculationFailed)
#define DiagNRCSettingAccessRightsFailed()               FblDiagSetError(kDiagNrcSettingAccessRightsFailed)
#define DiagNRCSessionKeyCreationDerivationFailed()      FblDiagSetError(kDiagNrcSessionKeyCreationDerivationFailed)
#define DiagNRCConfigurationDataUsageFailed()            FblDiagSetError(kDiagNrcConfigurationDataUsageFailed)
#define DiagNRCDeAuthenticationFailed()                  FblDiagSetError(kDiagNrcDeAuthenticationFailed)
#define DiagNRCUploadDownloadNotAccepted()               FblDiagSetError(kDiagNrcUploadDownloadNotAccepted)
#define DiagNRCTransferDataSuspended()                   FblDiagSetError(kDiagNrcTransferDataSuspended)
#define DiagNRCGeneralProgrammingFailure()               FblDiagSetError(kDiagNrcGeneralProgrammingFailure)
#define DiagNRCWrongBlockSequenceCounter()               FblDiagSetError(kDiagNrcWrongBlockSequenceCounter)
#define DiagNRCIllegalByteCountInBlockTransfer()         FblDiagSetError(kDiagNrcIllegalByteCountInBlockTransfer)
#define DiagNRCRcrResponsePending()                      FblDiagSetError(kDiagNrcRcrResponsePending)
#define DiagNRCSubfunctionNotSupportedInActiveSession()  FblDiagSetError(kDiagNrcSubfunctionNotSupportedInActiveSession)
#define DiagNRCServiceNotSupportedInActiveSession()      FblDiagSetError(kDiagNrcServiceNotSupportedInActiveSession)
#define DiagNRCVoltageTooHigh()                          FblDiagSetError(kDiagNrcVoltageTooHigh)
#define DiagNRCVoltageTooLow()                           FblDiagSetError(kDiagNrcVoltageTooLow)

/* Access macros for user diagnostic call-backs */
/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define DiagPutResponseSId(a)    (DiagBuffer[0] = (a))
#define DiagGetRequestSId()      (DiagBuffer[0])

/***********************************************************************************************************************
 *  Data processing
 **********************************************************************************************************************/

#define kDiagSubNoEncryption              0x00u
#define kDiagSubNoCompression             0x00u
#define kDiagSubNoDataProcessing          ((kDiagSubNoCompression << 4u) | kDiagSubNoEncryption)

#define kDiagFmtEncryptionMask            0x0Fu
#define kDiagFmtCompressionMask           0xF0u

/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define FblDiagGetCompressionMode(m)      (((m) & kDiagFmtCompressionMask) >> 4u)
#define FblDiagGetEncryptionMode(m)       ((m) & kDiagFmtEncryptionMask)

/***********************************************************************************************************************
 *  Response processing
 **********************************************************************************************************************/

/* Parameter to the function FblDiagEcuReset() */
#define kDiagResetPutResponse                0x00u
#define kDiagResetNoResponse                 0x01u

/* Parameters for busy response handling function */
#define kNotForceSendResponsePending         0x00u
#define kForceSendResponsePending            0x01u
#define kForceSendRpIfNotInProgress          0x02u

/* Sequence counter retry init number */
#if !defined( kDiagInitDataRetries )
# define kDiagInitDataRetries                0x03u
#endif

/* Read memory function for flash driver validation */
#define FblReadRam                           FblReadBlock

/***********************************************************************************************************************
 *  Timeout handling
 **********************************************************************************************************************/

/* Tester present timeout handling */
#if !defined( TESTER_PRESENT_TIMEOUT )
/** S3 timeout */
# define TESTER_PRESENT_TIMEOUT                 5000u
#endif

#define TimeoutTesterValue()                    testerPresentTimeout
#define DecTimeoutTesterValue()                 ( testerPresentTimeout-- )
#define ResetTesterTimeout()                    ( testerPresentTimeout = (vuint16)( TESTER_PRESENT_TIMEOUT / kDiagCallCycle ))
#define StopTesterTimeout()                     ( testerPresentTimeout = 0u )

#if defined( FBL_ENABLE_SLEEPMODE )
/* Sleep mode handling */
# define kFblSleepDelayTime                     ((vuint32)( FBL_SLEEP_TIME / FBL_REPEAT_CALL_CYCLE ))
# define FblSleepCounterClear()                 ( sleepCounter = 0x00u )
# define FblSleepCounterReload()                ( sleepCounter = kFblSleepDelayTime )
# define FblDecSleepCounter()                   ( sleepCounter-- )
# define FblGetSleepCounter()                   ((vuint32) sleepCounter )
#endif

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

typedef tFblResult (*tFblDiagLengthCheck )( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
typedef tFblResult (*tFblDiagPreHandler )( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
typedef tFblResult (*tFblDiagMainHandler)( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
typedef tFblResult (*tFblDiagNrcHandler)( vuint32 serviceErrorMask );
typedef void       (*tFblDiagPostHandler)( vuint8 postParam );

typedef tFblAddress  tFblDiagAddr;
typedef vuint8       tFblDiagNrc;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* Initialization functions */
void        FblDiagInitPowerOn( void );
void        FblDiagInit( void );
void        FblDiagPostInit( void );
/* Error handling interface */
void        FblDiagSetError( vuint8 errorCode );
void        DiagProcessingDone( tCwDataLengthType dataLength );

/* Diagnostic task functions */
void        FblDiagTimerTask( void );
void        FblDiagStateTask( void );

/* Diagnostic response after reset handling */
void        FblDiagInitStartFromAppl( void );
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
void        FblDiagInitStartFromReset( vuint8 resetRequestType );
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */
#if defined( FBL_DIAG_ENABLE_CORE_OTA )
void        FblDiagInitStartFromOta(void);
#endif /* FBL_DIAG_ENABLE_CORE_OTA */

/* Memory handling functions */
V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * FblDiagMemGetActiveBuffer(void);

/* Callback functions from FblLib_Mem */
tFblResult  FblDiagMemPreWrite( void );
tFblResult  FblDiagMemPostWrite( void );

#if defined( FBL_DIAG_ENABLE_CORE_GETLASTERASEDBLK )
tFblLbtBlockNr FblDiagGetLastErasedBlock(void);
void FblDiagSetLastErasedBlock(tFblLbtBlockNr blockNr);
#endif /* FBL_DIAG_ENABLE_CORE_GETLASTERASEDBLK */

#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Start section to execute code from RAM */
#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
void        DiagExRCRResponsePending( vuint8 forceSend );

/* Response pending handling functions */
vuint8      FblRealTimeSupport( void );
void        FblRealTimeSupportVoid( void );

/* Communication wrapper API */
void        FblDiagRxStartIndication( void );
void        FblDiagRxIndication( vuint8* pbDiagBuffer, tCwDataLengthType rxDataLength );
vuint8*     FblDiagRxGetPhysBuffer( tCwDataLengthType rxDataLength );
vuint8*     FblDiagRxGetFuncBuffer( tCwDataLengthType rxDataLength );
void        FblDiagTxConfirmation( vuint8 cwMsgType );
void        FblDiagTxErrorIndication( vuint8 cwMsgType );
void        FblDiagRxErrorIndication( void );

#if defined( FBL_CW_ENABLE_DECLINED_REQUESTS )
void        FblDiagRxDeclineIndication(vuint8* pbDiagBuffer, tCwDataLengthType rxDataLength, vuint8 connectionIndex);
vuint8*     FblDiagRxGetDeclineBuffer(tCwDataLengthType rxDataLength, vuint8 connectionIndex);
void        FblDiagDeclineErrorIndication(vuint8 connectionIndex);
void        FblDiagDeclineTxConfirmation(vuint8 connectionIndex);
#endif

/* End section to execute code from RAM */
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 extern V_MEMRAM1       vuint8            V_MEMRAM2 V_MEMRAM3 * V_MEMRAM1 V_MEMRAM2 DiagBuffer;
V_MEMRAM0 extern V_MEMRAM1_NEAR  tCwDataLengthType V_MEMRAM2_NEAR DiagDataLength;
V_MEMRAM0 extern V_MEMRAM1_NEAR  vuint16           V_MEMRAM2_NEAR testerPresentTimeout;
V_MEMRAM0 extern V_MEMRAM1_NEAR  vuint8            V_MEMRAM2_NEAR diagServiceCurrent;
V_MEMRAM0 extern V_MEMRAM1_NEAR  tFblStateBitmap   V_MEMRAM2_NEAR fblDiagStates[FBL_STATE_INDEX(kFblDiagNumberOfStates - 1u) + 1u];

#if defined( FBL_ENABLE_SLEEPMODE )
V_MEMRAM0 extern V_MEMRAM1       vuint32           V_MEMRAM2      sleepCounter;
#endif
#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/


#if !(defined(FBL_ENABLE_SYSTEM_CHECK) || defined(FBL_DISABLE_SYSTEM_CHECK))
# error "Error in fbl_cfg.h: Usage of system check not defined"
#endif

#if !(defined(FBL_ENABLE_DEBUG_STATUS) || defined(FBL_DISABLE_DEBUG_STATUS))
# error "Error in fbl_cfg.h: Usage of debug support not defined"
#endif

#if !(defined(FBL_ENABLE_APPL_TASK) || defined(FBL_DISABLE_APPL_TASK))
# error "Error in fbl_cfg.h: Usage of application task function not defined"
#endif

#if !(defined(FBL_ENABLE_USERSUBFUNCTION) || defined(FBL_DISABLE_USERSUBFUNCTION))
# error "Error in fbl_cfg.h: Usage of diag user-subfunction call not defined"
#endif

#if !(defined(FBL_ENABLE_DATA_PROCESSING) || defined(FBL_DISABLE_DATA_PROCESSING))
# error "Error in fbl_cfg.h: Usage of data processing interface not defined"
#endif

#if !(defined(FBL_WATCHDOG_ON) || defined(FBL_WATCHDOG_OFF))
# error "Error in fbl_cfg.h: Usage of watchdog support not defined"
#endif

#if defined( FBL_WATCHDOG_ON) && !defined(FBL_WATCHDOG_TIME )
# error "Error in fbl_cfg.h: Watchdog trigger period not defined"
#endif

#if !(defined(FBL_ENABLE_FBL_START) || defined(FBL_DISABLE_FBL_START))
# error "Error in fbl_cfg.h: Usage of FblStart function not defined"
#endif

#if defined ( FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING )
# if !defined(SWM_DATA_MAX_NOAR)
#  error "Error in fbl_cfg.h: Number of supported download segments (SWM_DATA_MAX_NOAR) not defined"
# endif
#endif

#if !defined(FBL_HEADER_ADDRESS)
# error "Error in fbl_cfg.h: Start address of bootblock header not defined"
#endif

#if !defined(FBL_DIAG_BUFFER_LENGTH)
# error "Error in fbl_cfg.h: FBL_DIAG_BUFFER_LENGTH not defined"
#endif

#if ( FBL_DIAG_BUFFER_LENGTH < (FBL_MAX_SEGMENT_SIZE+2) )
# error "Error in fbl_cfg.: DiagBuffer size too small - modify FBL_DIAG_BUFFER_LENGTH"
#endif

#if defined( SEC_SECURITY_CLASS )
# if ( SEC_SECURITY_CLASS == SEC_CLASS_C ) || ( SEC_SECURITY_CLASS == SEC_CLASS_CCC )
#  if ( FBL_DIAG_BUFFER_LENGTH < (kSecSigLength+4) )
#   error "Error in fbl_cfg.h: DiagBuffer size too small - modify FBL_DIAG_BUFFER_LENGTH"
#  endif
# endif
#endif

/* Make sure OEM layer configures this module */
#if !defined( FBL_DIAG_ENABLE_CORE_READ_SECACCESSDELAY_FLAG ) && \
    !defined( FBL_DIAG_DISABLE_CORE_READ_SECACCESSDELAY_FLAG )
# error "OEM diagnostic module has to configure this setting"
#endif
#if !defined( FBL_DIAG_ENABLE_CORE_WRITE_SECACCESSDELAY_FLAG ) && \
    !defined( FBL_DIAG_DISABLE_CORE_WRITE_SECACCESSDELAY_FLAG )
# error "OEM diagnostic module has to configure this setting"
#endif

#if !defined(FBL_DIAG_TIME_P3MAX)
# error "Error in fbl_cfg.h: P2Star time not defined"
#endif

#if !defined(FLASH_SIZE)
# error "Error in fbl_cfg.h: Size of flash code buffer not defined"
#endif

#endif /* FBL_DIAG_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_DIAG.H
 **********************************************************************************************************************/
