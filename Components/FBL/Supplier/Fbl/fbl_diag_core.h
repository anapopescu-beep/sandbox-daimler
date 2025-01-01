/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Diagnostic services supported in boot mode
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
 *  04.01.00   2019-03-05  visrie  ESCAN00102341    Removed duplicated function
 *                         visach  ESCAN00102368    No changes
 *  04.02.00   2019-08-01  visrcn  ESCAN00103927    No changes
 *  04.02.01   2019-10-08  visrcn  ESCAN00104279    No changes
 *  04.03.00   2020-05-07  visrie  FBL-1414         Added support for One-Step-Updater
 *  04.04.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *  04.05.00   2020-11-12  visrie  FBL-938          No changes
 *  04.06.00   2021-01-21  visjdn  ESCAN00107631    No changes
 *  04.07.00   2021-05-14  visjdn  FBL-3365         Added/adapted MemMap sections
 *  04.08.00   2021-06-16  vishor  FBL-3564         Added support for more than 256 download segments
 *  04.09.00   2021-10-12  vistmo  FBL-3901         No changes
 *  04.10.00   2022-01-14  vishor  FBL-4160         No changes
 *  04.11.00   2022-02-01  vistmo  FBL-4566         No changes
 *  04.12.00   2022-04-28  vishor  FBL-4311         No changes
 *  04.12.01   2022-06-14  vishor  ESCAN00110534    Behavior after startup might not be correct
 *  04.12.02   2022-10-13  visjns  ESCAN00112693    No changes
 *  04.13.00   2022-11-17  visjns  FBL-6136         No changes
 *                                 ESCAN00112998    No changes
 *  04.14.00   2022-11-30  vismix  FBL-6046         Support connection dependent diag buffer sizes
 *  04.15.00   2022-12-06  vistmo  FBL-6142         Add support for 29 00 ISO Service
 **********************************************************************************************************************/

#ifndef FBL_DIAG_CORE_H
#define FBL_DIAG_CORE_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblDiag_14229_Core CQComponent : Implementation */
#define FBLDIAG_14229_COREINT_VERSION           0x0415u
#define FBLDIAG_14229_COREINT_RELEASE_VERSION   0x00u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBL_DIAGCORE_API_VERSION_MAJOR    0x04u
/** Minor interface version identifies backward compatible changes */
#define FBL_DIAGCORE_API_VERSION_MINOR    0x12u
/** Release interface version identifies cosmetic changes */
#define FBL_DIAGCORE_API_VERSION_RELEASE  0x00u

/***********************************************************************************************************************
 *  Session handling
 **********************************************************************************************************************/

#define kFblDiagOptionSessionDefault         0x01u       /**< Service is supported in default session */
#define kFblDiagOptionSessionExtended        0x02u       /**< Service is supported in extended session */
#define kFblDiagOptionSessionProgramming     0x04u       /**< Service is supported in programming session */
#define kFblDiagOptionSecuredService         0x08u       /**< Service is secured by security access */
#define kFblDiagOptionServiceIsSubfunction   0x10u       /**< Service uses a UDS sub-function */
#define kFblDiagOptionFunctionalRequest      0x20u       /**< Service is supported by functional requests */

/***********************************************************************************************************************
 *  State handling
 **********************************************************************************************************************/

#define kDiagStateNone                       0x00u

/* Diagnostic session states handling */
#define FblDiagClrDiagSession()              FBL_STATE_MULTICLR(fblDiagStates, kFblDiagStateSessionDefault, kFblDiagStateSessionProgramming)

/* Session control macros */
#define kFblDiagStateMaskSessionDefault      kFblDiagStateMask(kFblDiagStateSessionDefault)
#define FblDiagSetDefaultSession()                 \
{                                                  \
   FblDiagClrDiagSession();                        \
   SetFblDiagState(kFblDiagStateSessionDefault);   \
}  /* PRQA S 3458 */ /* MD_MSR_19.4 */

#define kFblDiagStateMaskSessionExtended     kFblDiagStateMask(kFblDiagStateSessionExtended)

#define FblDiagSetExtendedSession()                   \
{                                                  \
   FblDiagClrDiagSession();                        \
   SetFblDiagState(kFblDiagStateSessionExtended);  \
}  /* PRQA S 3458 */ /* MD_MSR_19.4 */

#define kFblDiagStateMaskSessionProgramming  kFblDiagStateMask(kFblDiagStateSessionProgramming)
#define FblDiagSetProgrammingSession()                   \
{                                                     \
   FblDiagClrDiagSession();                           \
   SetFblDiagState(kFblDiagStateSessionProgramming);  \
}  /* PRQA S 3458 */ /* MD_MSR_19.4 */

/* Bit masks to handle session checks */
#define kFblDiagStateMaskSession          (kFblDiagStateMaskSessionDefault|kFblDiagStateMaskSessionExtended|kFblDiagStateMaskSessionProgramming)
#define GetCurrentSession()               (vuint8)(fblDiagStates[0] & kFblDiagStateMaskSession)

/* Helper macro to get number of array entries */
#define ARRAY_SIZE(arr)                   (sizeof(arr) / sizeof((arr)[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Diagnostic handling states */
#define FblDiagClrDefaultSession()        ClrFblDiagState( kFblDiagStateSessionDefault )
#define FblDiagClrProgrammingSession()    ClrFblDiagState( kFblDiagStateSessionProgramming )
#define FblDiagClrExtendedSession()       ClrFblDiagState( kFblDiagStateSessionExtended )
#define FblDiagSetBufferLocked()          SetFblDiagState( kFblDiagStateDiagBufferLocked )
#define FblDiagClrBufferLocked()          ClrFblDiagState( kFblDiagStateDiagBufferLocked )
#define FblDiagSetExecutePostHandler()    SetFblDiagState( kFblDiagStateExecutePostHandler )
#define FblDiagClrExecutePostHandler()    ClrFblDiagState( kFblDiagStateExecutePostHandler )
#define FblDiagSetRcrRpAllowed()          SetFblDiagState( kFblDiagStateRcrRpAllowed )
#define FblDiagClrRcrRpAllowed()          ClrFblDiagState( kFblDiagStateRcrRpAllowed )
#define FblDiagSetRcrRpInProgress()       SetFblDiagState( kFblDiagStateRcrRpInProgress )
#define FblDiagClrRcrRpInProgress()       ClrFblDiagState( kFblDiagStateRcrRpInProgress )
#define FblDiagSetResponseProcessing()    SetFblDiagState( kFblDiagStateResponseProcessing )
#define FblDiagClrResponseProcessing()    ClrFblDiagState( kFblDiagStateResponseProcessing )
#define FblDiagSetSuppressPosRspMsg()     SetFblDiagState( kFblDiagStateSuppressPosRspMsg )
#define FblDiagClrSuppressPosRspMsg()     ClrFblDiagState( kFblDiagStateSuppressPosRspMsg )
#define FblDiagSetServiceHasSubfunction() SetFblDiagState( kFblDiagStateServiceHasSubfunction )
#define FblDiagClrServiceHasSubfunction() ClrFblDiagState( kFblDiagStateServiceHasSubfunction )
#define FblDiagSetServiceInProgress()     SetFblDiagState( kFblDiagStateServiceInProgress )
#define FblDiagClrServiceInProgress()     ClrFblDiagState( kFblDiagStateServiceInProgress )
#define FblDiagSetFunctionalRequest()     SetFblDiagState( kFblDiagStateFunctionalRequest )
#define FblDiagClrFunctionalRequest()     ClrFblDiagState( kFblDiagStateFunctionalRequest )
#define FblDiagSetTransferTypeFlash()     SetFblDiagState( kFblDiagStateTransferTypeFlash )
#define FblDiagClrTransferTypeFlash()     ClrFblDiagState( kFblDiagStateTransferTypeFlash )
#define FblDiagSetRespBufLockedByInit()   SetFblDiagState( kFblDiagStateRespBufLockedByInit )
#define FblDiagClrRespBufLockedByInit()   ClrFblDiagState( kFblDiagStateRespBufLockedByInit )
/* Reset handling states */
#define FblDiagSetWaitEcuReset()                   \
{                                                  \
   SetFblDiagState( kFblDiagStateWaitEcuReset );   \
   ResetEcuResetTimeout();                         \
}  /* PRQA S 3458 */ /* MD_MSR_19.4 */
#define FblDiagClrWaitEcuReset()                   \
{                                                  \
   ClrFblDiagState( kFblDiagStateWaitEcuReset );   \
   StopEcuResetTimeout();                          \
}  /* PRQA S 3458 */ /* MD_MSR_19.4 */
#define FblDiagSetEcuResetFctFinished()   SetFblDiagState( kFblDiagStateEcuResetFctFinished )
#define FblDiagClrEcuResetFctFinished()   ClrFblDiagState( kFblDiagStateEcuResetFctFinished )
#define FblDiagSetResetMsgConfirmed()     SetFblDiagState( kFblDiagStateResetMsgConfirmed )
#define FblDiagClrResetMsgConfirmed()     ClrFblDiagState( kFblDiagStateResetMsgConfirmed )
/* Generic download states */
#define FblDiagSetPreconditionsChecked()  SetFblDiagState( kFblDiagStatePreconditionsChecked )
#define FblDiagClrPreconditionsChecked()  ClrFblDiagState( kFblDiagStatePreconditionsChecked )
#define FblDiagSetMemDriverInitialized()  SetFblDiagState( kFblDiagStateMemDriverInitialized )
#define FblDiagClrMemDriverInitialized()  ClrFblDiagState( kFblDiagStateMemDriverInitialized )

/***********************************************************************************************************************
 *  Timeout handling
 **********************************************************************************************************************/

/* Diagnostic session timing */
#define kDiagSessionTimingP2                 ( kFblDiagTimeP2 * FBL_REPEAT_CALL_CYCLE )
#define kDiagSessionTimingP2StarRaw          ( kFblDiagTimeP2Star * FBL_REPEAT_CALL_CYCLE )
#define kDiagSessionTimingP2Star             ( kDiagSessionTimingP2StarRaw / 10u )

/* Threshold timer for P2 to trigger an RCR-RP */
#if !defined( kFblDiagP2MinThreshold )
# define kFblDiagP2MinThreshold              ( kDiagSessionTimingP2 / 2u )
#endif

/* Threshold timer for P2-Star to trigger an RCR-RP */
#if !defined( kFblDiagP2StarMinThreshold )
# define kFblDiagP2StarMinThreshold          ( kDiagSessionTimingP2StarRaw / 2u )
#endif

/* Security access delay */
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
# if !defined(kSecMaxInvalidKeys)
#  define kSecMaxInvalidKeys           0x03u
# endif
# define kSecSecurityAccessDelay       ((vuint32) FBL_SEC_ACCESS_DELAY_TIME )
#endif

/* ECU shutdown handling */
/* Maximum wait time for ECU reset request */
#if defined( kCwMaxWaitTimeEcuResetRequest )
# define kFblDiagMaxWaitTimeEcuResetRequest     (kCwMaxWaitTimeEcuResetRequest / FBL_REPEAT_CALL_CYCLE)
#else
# define kFblDiagMaxWaitTimeEcuResetRequest     kFblDiagTimeP2Star
#endif

/* ECU reset handling */
#if !defined( kFblDiagSubReset )
# define kFblDiagSubReset                       kDiagSubHardReset
#endif

/* Macros to access the ecuReset timer value */
#define TimeoutEcuResetValue()                  ecuResetTimeout
#define DecTimeoutEcuResetValue()              (ecuResetTimeout--)
#define ResetEcuResetTimeout()                 (ecuResetTimeout = (vuint16)(kFblDiagMaxWaitTimeEcuResetRequest/kDiagCallCycle))
#define StopEcuResetTimeout()                  (ecuResetTimeout = 0u)

/* Security functions */
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/* Security access delay handling */
# define SetSecurityAccessDelay()      (secSecurityAccessDelay = (vuint32)(kSecSecurityAccessDelay / kDiagCallCycle))
# define GetSecurityAccessDelay()      (secSecurityAccessDelay)
# define DecSecurityAccessDelay()      (secSecurityAccessDelay--)
# define ClrSecurityAccessDelay()      (secSecurityAccessDelay = 0u)
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

/* Error handling */
/* Access macros */
#define DiagClrError()                    ( diagErrorCode = kDiagErrorNone )  /**< Clear error status */
#define DiagGetError()                    ( diagErrorCode )                   /**< Get error (NRC) code */

#if defined ( FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING )
/* Segment handling macros */
#define kSwmOutOfRange           0xFFFFFFFFuL
#define FblDiagSegmentInit()     (segmentCount = 0uL)   /**< Initialize segment counter */
#endif /* FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING */

#if defined( FBL_DIAG_ENABLE_OEM_SERVICENOTIFICATION )
/* Service Response Notifications Param */
# define kFblDiagServiceNotificationStart  0x00u        /**< A new service reception started */
# define kFblDiagServiceNotificationEnd    0x01u        /**< A service processing ended */
#endif

/* Response state handling */
/* Access macros */
#define DiagSetNoResponse()               ( diagResponseFlag |= kDiagPutNoResponse )   /**< Do not send a response */
#define DiagGetNoResponse()               ( diagResponseFlag & kDiagPutNoResponse )    /**< Check if a response should be sent */

#define kDiagResponseIdle                 0x00u             /**< Response not yet configured */
#define kDiagResponseRequested            FBL_BIT0          /**< Response should be sent */
#define kDiagPutNoResponse                FBL_BIT1          /**< No response should be sent */
#define kDiagPutNoFuncResponse            FBL_BIT2          /**< No response should be sent for functional requests */
#define kDiagPutPosResponse               FBL_BIT3          /**< Positive response requested */
#define kDiagPutNegResponse               FBL_BIT4          /**< Negative response requested - supersedes positive response request */
#define kDiagRepeatResponse               FBL_BIT7          /**< Response should be repeated */

/* Parameter for post-handler::diagPostParam  */
#define kDiagPostPosResponse              0x00u             /**< No error - positive response */
#define kDiagPostNegResponse              0x01u             /**< NRC set - negative response */
#define kDiagPostFailedResponse           0x02u             /**< Retry to send response */
#define kDiagPostRcrRp                    0x03u             /**< RCRRP sent */
#define kDiagPostNoResponse               0x04u             /**< No response to be sent */

/* Service handling macros */
/* Return values of service checks - used as bit mask*/

#define kFblDiagServiceOk                 0x00000000u    /**< No error found during service check */
#define kFblDiagServiceErrorMask          0xFFFFFFFEu    /**< All bits which indicate an error */
#define kFblDiagServiceLevelErrors        0x0000FFFEu    /**< Bits which indicate errors on service level checks */
#define kFblDiagSubTableNotFound          0x00000001u    /**< No sub table has to be evaluated */
#define kFblDiagGeneralFailure            0x00000002u    /**< Unspecified receive failure */
#define kFblDiagServiceNotFound           0x00000100u    /**< Service is not supported */
#define kFblDiagServiceNoFuncSupport      0x00000200u    /**< Service mustn't be received functionally */
#define kFblDiagServiceSessionFailure     0x00000400u    /**< Service is not allowed in current session */
#define kFblDiagServiceMinLenFailure      0x00000800u    /**< Length check against service table failed */
#define kFblDiagServiceSecAccessFailure   0x00001000u    /**< Security access is needed for this service */
#define kFblDiagServiceLenFailure         0x00002000u    /**< Dynamic length check failed */

#define kFblDiagSubfunctionNotFound       0x00010000u    /**< Sub-function not found */
#define kFblDiagSubparamNotFound          0x00020000u    /**< Sub-param or routine identifier not found */
#define kFblDiagSubNoFuncSupport          0x00040000u    /**< Sub table entry is not supported functionally */
#define kFblDiagSubfuncSessionFailure     0x00080000u    /**< Sub-function is not allowed in current session */
#define kFblDiagSubparamSessionFailure    0x00100000u    /**< Sub-param or routine identifier not found */
#define kFblDiagSubMinLenFailure          0x00200000u    /**< Sub table entry minimum length check failed */
#define kFblDiagSubfuncSecAccessFailure   0x00400000u    /**< Security access is needed for this sub-function table entry */
#define kFblDiagSubparamSecAccessFailure  0x00800000u    /**< Security access is needed for this sub-param table entry */
#define kFblDiagSubLenFailure             0x01000000u    /**< Dynamic length check failed */

#define kFblDiagServicePrehandlerFailure  0x10000000u    /**< Pre-handler function returned a failure */

/***********************************************************************************************************************
 *  DATA TYPE DEFINITIONS
 **********************************************************************************************************************/

/** Structure definition for subfunction parameter check */
typedef struct tagSubFctInfoTable
{
   /** Pointer to subfunction ID table */
   V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3  *subFctParamIdTable;
   /** Session support, length check and security level configuration */
   vuint8                     sessionSupport;
   /** Service length. If special length check is not set, fixed check against this value. */
   tCwDataLengthType          serviceLen;
   /** Selects main handler function */
   vsintx                     mainInstanceHandlerIdx;
} tSubFctInfoTable;

typedef struct tagFblDiagServiceSubTable
{
   /** Pointer to subfunction ID table */
   V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3  *subTableParamTable;
   /** Service option bit field */
   vuint32              serviceOptions;
   /** Service length parameter. Minimum length in case a special check or subtable is used, otherwise absolute length. */
   tCwDataLengthType    serviceLength;
   /** Length check function for dynamic length checks */
   tFblDiagLengthCheck  serviceLengthCheck;
   /** Service main handler function. */
   tFblDiagMainHandler  serviceMainHandler;
} tFblDiagServiceSubTable;

/** Diagnostic service definition */
typedef struct tagFblDiagServiceTable
{
   /** Service ID */
   vuint8               serviceId;
   /** Service option bit field */
   vuint32              serviceOptions;
   /** Service length parameter. Minimum length in case a special check or subtable is used, otherwise absolute length.
       If a sub-table is used, the length of the sub-table parameter definition has to be covered. */
   tCwDataLengthType    serviceLength;
   /** Length check function for dynamic length checks */
   tFblDiagLengthCheck  serviceLengthCheck;
   /** Number of entries in sub-table (sub-function or sub-parameter table) */
   vuintx               subTableLength;
   /** Number of identification bytes to identify sub-table entry */
   vuintx               subTableIdLength;
   /** Link to service sub table */
   V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3 * serviceSubTable;
#if defined( FBL_DIAG_ENABLE_SERVICE_PREHANDLER )
   /** Pre-handler function to insert service specific pre-checks */
   tFblDiagPreHandler   servicePreHandler;
#endif /* FBL_DIAG_ENABLE_SERVICE_PREHANDLER */
   /** Service main handler function. Will be used as fallback function in case a sub-table is defined and
       no sub-table entry is found. */
   tFblDiagMainHandler  serviceMainHandler;
   /** Service NRC handler function. Maps error states of internal checks to NRCs */
   tFblDiagNrcHandler   serviceNrcHandler;
#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
   tFblDiagPostHandler  servicePostHandler;
#endif /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */
} tFblDiagServiceTable;

/***********************************************************************************************************************
 *  LOCAL DATA - visible in core and OEM layer, but not in other bootloader modules
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 extern V_MEMRAM1_NEAR vuint8          V_MEMRAM2_NEAR diagResponseFlag;
V_MEMRAM0 extern V_MEMRAM1 vuint16              V_MEMRAM2      ecuResetTimeout;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
V_MEMRAM0 extern V_MEMRAM1 vuint32              V_MEMRAM2      secSecurityAccessDelay;
#endif
V_MEMRAM0 extern V_MEMRAM1 vuint8               V_MEMRAM2      diagErrorCode;
#if defined( FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING )
V_MEMRAM0 extern V_MEMRAM1 vuint32              V_MEMRAM2      segmentCount;
#endif /* FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING */

#if defined( FBL_DIAG_ENABLE_DYNAMIC_P2_HANDLING )
V_MEMRAM0 extern V_MEMRAM1 vuint16 V_MEMRAM2 fblDiagTimeP2Max;    /**< P2 base value */
#endif /* FBL_DIAG_ENABLE_DYNAMIC_P2_HANDLING */
#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLDIAG_START_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* Data - implemented in OEM layer */
/* PRQA S 3684 2 */ /* MD_FblDiag_3684 */
V_MEMROM0 extern V_MEMROM1 tFblDiagServiceTable V_MEMROM2      kFblDiagServiceTable[];
V_MEMROM0 extern V_MEMROM1 vuintx V_MEMROM2 kSizeOfServiceTable;
V_MEMROM0 extern V_MEMROM1 vuintx V_MEMROM2 kSizeOfMainHandlerTable;
#define FBLDIAG_STOP_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/
#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if defined( FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING )
vuint32 FblDiagSegmentNext(void);
#endif /* FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING */

#if defined( FBL_DIAG_ENABLE_CORE_GETBLOCKFROMADDR )

# define FblGetBlockNrFromAddress(blockAddress, blockLength, pLogicalBlock) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
   FblLbtGetBlockDescriptorByAddressLength(blockAddress, blockLength, pLogicalBlock)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif /* FBL_DIAG_ENABLE_CORE_GETBLOCKFROMADDR */
#if defined( FBL_DIAG_ENABLE_CORE_GETBLOCKFROMID )
# define FblGetBlockNrFromIndex(blockIndex, pLogicalBlockNr) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
   FblLbtGetBlockNrByIndex(blockIndex, pLogicalBlockNr)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
tFblResult FblGetNrFromBlockTable(V_MEMROM1 tBlockDescriptor V_MEMROM2 V_MEMROM3 * pBlockTable, vuint8 noOfBlocks,
   tFblLbtBlockIndex blockIndex, vuint8 * pLogicalBlockNr);
#endif /* FBL_DIAG_ENABLE_CORE_GETBLOCKFROMID */
#if defined( FBL_DIAG_ENABLE_CORE_MAX_TDBLOCKLENGTH )
tCwDataLengthType FblDiagGetMaxTransferDataBlockLength(void);
vuint8 FblDiagSetMaxTransferDataBlockLength(vuint8 * pbDiagBuffer, vuint8 minLfi);
#endif /* FBL_DIAG_ENABLE_CORE_MAX_TDBLOCKLENGTH */

void FblDiagEcuReset( void );
#if defined( FBL_DIAG_ENABLE_OEM_INITPOWERON )
void FblDiagOemInitPowerOn(void);
#endif /* FBL_DIAG_ENABLE_OEM_INITPOWERON */
#if defined( FBL_DIAG_ENABLE_OEM_INIT )
void FblDiagOemInit(void);
#endif /* FBL_DIAG_ENABLE_OEM_INIT */
#if defined( FBL_DIAG_ENABLE_OEM_POSTINIT )
void FblDiagOemPostInit(void);
#endif /* FBL_DIAG_ENABLE_OEM_POSTINIT */
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
# if defined( FBL_DIAG_ENABLE_OEM_SDS_RESPONSE )
void FblDiagOemPrepareSdsResponse(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pDiagBuffer, V_MEMRAM1 tCwDataLengthType V_MEMRAM2 V_MEMRAM3 *pDiagDataLength);
# endif /* FBL_DIAG_ENABLE_OEM_SDS_RESPONSE */
# if defined( FBL_DIAG_ENABLE_OEM_RR_RESPONSE )
void FblDiagOemPrepareRrResponse(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pDiagBuffer, V_MEMRAM1 tCwDataLengthType V_MEMRAM2 V_MEMRAM3 *pDiagDataLength);
# endif /* FBL_DIAG_ENABLE_OEM_RR_RESPONSE */
#endif /* FLB_ENABLE_RESPONSE_AFTER_RESET */
#if defined( FBL_DIAG_ENABLE_OEM_SPS_REQUEST )
void FblDiagOemPrepareSpsRequest(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pDiagBuffer, V_MEMRAM1 tCwDataLengthType V_MEMRAM2 V_MEMRAM3 *pDiagDataLength);
#endif /* FBL_DIAG_ENABLE_OEM_SPS_REQUEST */
#if defined( FBL_DIAG_ENABLE_CORE_OTA )
void FblDiagOemPrepareOtaResponse(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pDiagBuffer, V_MEMRAM1 tCwDataLengthType V_MEMRAM2 V_MEMRAM3 *pResponseLength);
#endif /* FBL_DIAG_ENABLE_CORE_OTA */
#if defined( FBL_DIAG_ENABLE_OEM_DEINIT )
void FblDiagOemDeinit(void);
#endif /* FBL_DIAG_ENABLE_OEM_DEINIT */
#if defined( FBL_DIAG_ENABLE_OEM_STATETASK )
void FblDiagOemStateTask(void);
#endif /* FBL_DIAG_ENABLE_OEM_STATETASK */
#if defined( FBL_DIAG_ENABLE_OEM_TIMERTASK )
void FblDiagOemTimerTask(void);
#endif /* FBL_DIAG_ENABLE_OEM_TIMERTASK */
#if defined( FBL_DIAG_ENABLE_OEM_SERVICENOTIFICATION )
void FblDiagOemServiceReceptionNotification(vuint8 notificationType);
#endif
#if defined( FBL_DIAG_ENABLE_OEM_SESSION_TIMEOUT )
void FblDiagSessionTimeout(void);
#endif
#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
/* Diagnostic post-handler service functions */
/* Start section to execute code from RAM */
# define FBLDIAG_RAMCODE_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern void FblDiagDefaultPostHandler( vuint8 postParam );

# if defined( FBL_CW_ENABLE_DECLINED_REQUESTS ) && defined( FBL_DIAG_DISABLE_CORE_DECLINED_REQUESTS )
extern void FblDiagOem_ProcessDeclineRequest(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pDiagBuffer, V_MEMRAM1 tCwDataLengthType V_MEMRAM2 V_MEMRAM3 *pDiagDataLength);
# endif

/* End section to execute code from RAM */
# define FBLDIAG_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */

#endif /* FBL_DIAG_CORE_H */

/* module specific MISRA deviations:

   MD_FblDiag_0410:
      Reason: Makes the code more readable and maintainable.
      Risk: Makes the code more complicated to analyze and understand.
      Prevention: No prevention required.

   MD_FblDiag_2214:
      Reason: Assertion macros have to be disabled in production code and are used only for development.
      Risk: Assertion code may be enabled in production code unintentionally. If a assertion condition is unexpectedly
         false, the code is active. A problem may occur if the Macro is additionally changed from single statement
         to multiple statement.
      Prevention: Macro is not allowed to be changed without review. Development code is automatically disabled via
         configuration of project state "Production".

   MD_FblDiag_3109:
      Reason: Multi-line macros encapsulated in curly brackets to reduce side-effects. Results in empty statement after
       the closing bracket.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblDiag_3201:
      Reason: Function calls are not used in all configurations because if statement may be always true depending on
       the module's configuration.
      Risk: Unused statements could result in a compiler warning, slightly increased resource consumption because
       of 2 unused statements.
      Prevention: Ignore compiler warning if observed.

   MD_FblDiag_3218:
      Reason: Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk: Scope is larger than required (whole file instead of one function). Some other function could access the variable.
      Prevention: Take care that this deviation is used for constant data only (which cannot be modified).

   MD_FblDiag_3425:
      Reason: The WrapNv call uses the ternary operator to remap the return value of IO_E_OK to kFblOk. As both of
       them are defined to the value zero the remapping has no side affects.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblDiag_3684:
      Reason: Symbol definition of array is done without array size. This is done because the arrays are implemented
       by the OEM layer, but the interface has to be defined by the core layer.
      Risk: The compiler is not able to check array access bounds.
      Prevention: Array accesses have to be verified by code inspection.

   MD_FblDiag_1514_ExternalModuleAccess:
     Reason: Depending on the configuration extern access maybe required.
     Risk: Variable never used outside.
     Prevention: Declare statically instead of externally.

   MD_FblDiag_2741_ConstantExpression:
     Reason: This 'if' controlling expression is a constant expression because its value is hardcoded.
     Risk: Not changeable through runtime.
     Prevention: Dont use magic numbers.

   MD_FblDiag_2986_OperationRedundant:
     Reason: This is code is kept for supporting future stack updates and for better code readability.
     Risk: Redundant check.
     Prevention: The user shall check that the variable is used outside.

   MD_FblDiag_2991_2995_RedundantCondition:
     Reason: Condition is kept only because of code clarification and requirement tracking.
     Risk: No identifiable risk.
     Prevention: No prevention required.

   MD_FblDiag_4558:
     Reason: Value is used in a boolean expression.
     Risk: The Boolean logic does not behave as expected.
     Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_DIAG_CORE.H
 **********************************************************************************************************************/
