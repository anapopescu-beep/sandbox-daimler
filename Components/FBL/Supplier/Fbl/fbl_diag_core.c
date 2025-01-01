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
 *                         visach  ESCAN00102368    Support reset of security access attempt counter
 *  04.02.00   2019-08-01  visrcn  ESCAN00103927    Migrate implementation to MISRA 2012
 *  04.02.01   2019-10-08  visrcn  ESCAN00104279    Connection released after functional/suppressed tester present
 *  04.03.00   2020-05-07  visrie  FBL-1414         Added support for One-Step-Updater
 *  04.04.00   2020-07-13  visrie  FBL-2021         Added support for OTA
 *  04.05.00   2020-11-12  visrie  FBL-938          No changes
 *  04.06.00   2021-01-21  visjdn  ESCAN00107631    Pipelined programming fails
 *  04.07.00   2021-05-14  visjdn  FBL-3365         Added/adapted MemMap sections
 *  04.08.00   2021-06-16  vishor  FBL-3564         Added support for more than 256 download segments
 *  04.09.00   2021-10-12  vistmo  FBL-3901         No changes
 *  04.10.00   2022-01-14  vishor  FBL-4160         Support default implementation of NRC21
 *  04.11.00   2022-02-01  vistmo  FBL-4566         TP BlockSize parameters not preserved after one step updater completion
 *  04.12.00   2022-04-28  vishor  FBL-4311         Add support for OTA APIs
 *  04.12.01   2022-06-14  vishor  ESCAN00110534    Behavior after startup might not be correct
 *  04.12.02   2022-10-13  visjns  ESCAN00112693    Reset of Bootloader may be delayed
 *  04.13.00   2022-11-17  visjns  FBL-6136         Add additional subfunction defines for service 29
 *                                 ESCAN00112998    Response After Reset is not sent when Stay In Boot is enabled
 *  04.14.00   2022-11-30  vismix  FBL-6046         Support connection dependent diag buffer sizes
 *  04.15.00   2022-12-06  vistmo  FBL-6142         Add support for 29 00 ISO Service
 **********************************************************************************************************************/

#define FBL_DIAG_CORE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* Common Bootloader includes */
#include "fbl_inc.h"
#include "fbl_diag_core.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/
/* Diagnostic core module version check */
#if ((FBLDIAG_14229_COREINT_VERSION != 0x0415u) || \
     (FBLDIAG_14229_COREINT_RELEASE_VERSION != 0x00u))
# error "Error in fbl_diag_core.c: Source and header file are inconsistent!"
#endif
#if (( FBLDIAG_14229_COREINT_VERSION != FBLDIAG_14229_CORE_VERSION ) || \
     ( FBLDIAG_14229_COREINT_RELEASE_VERSION != FBLDIAG_14229_CORE_RELEASE_VERSION ))
# error "Error in fbl_diag_core.h: Header versions are inconsistent."
#endif
#if ((FBLDIAG_14229_CORE_VERSION != _FBLDIAG_14229_CORE_VERSION) || \
     (FBLDIAG_14229_CORE_RELEASE_VERSION != _FBLDIAG_14229_CORE_RELEASE_VERSION))
# error "Error in fbl_diag_core.c: Source and v_ver.h file are inconsistent!"
#endif

/* Interface version compatibility check */
#if defined( FBL_DIAGCORE_API_REFERENCE_VERSION_MAJOR ) && \
    defined( FBL_DIAGCORE_API_REFERENCE_VERSION_MINOR )
#else
#  error "Error in fbl_diag_core.c: Interface version requirements not defined!"
#endif

#if ( FBL_DIAGCORE_API_REFERENCE_VERSION_MAJOR != FBL_DIAGCORE_API_VERSION_MAJOR) || \
    ( FBL_DIAGCORE_API_REFERENCE_VERSION_MINOR > FBL_DIAGCORE_API_VERSION_MINOR)
# error "Error in fbl_diag_core.c: Interface version compatibility check failed!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Diagnostic states configuration checks */
#if( kFblDiagStateSessionDefault != 0u )  || \
   ( kFblDiagStateSessionExtended != 1u ) || \
   ( kFblDiagStateSessionProgramming != 2u )
# error "Session states must not be changed to different values."
#endif

/** Bit mask to check if response is already configured */
#define kDiagResponseActive               ( kDiagPutNoResponse  | kDiagPutPosResponse | kDiagPutNegResponse )

#if defined( FBL_DIAG_ENABLE_OEM_SESSIONCHECK_NRC )
#else
# define DiagNRCServiceCheckNotSucceeded() DiagNRCServiceNotSupportedInActiveSession() /**< Define configurable session check NRC */
#endif

#if !defined( FBL_DIAG_ENABLE_SPS_EXTENDED_SESSION ) && \
    !defined( FBL_DIAG_DISABLE_SPS_EXTENDED_SESSION )
# define FBL_DIAG_ENABLE_SPS_EXTENDED_SESSION
#endif
#if !defined( kDiagRqlSpsFromAppl )
# define kDiagRqlSpsFromAppl kDiagRqlDiagnosticSessionControl
#endif

/* Specific service responses */
/* RoutineControl status for eraseMemory */
#if !defined( kDiagEraseSucceeded )
# define kDiagEraseSucceeded                                0x00u                /**< Erase memory was started and succeeded */
#endif /* kDiagEraseSucceeded */
#if !defined( kDiagEraseFailed )
# define kDiagEraseFailed                                   0x01u                /**< Failure occurred after routine was started */
#endif /* kDiagEraseFailed */

/* Signature handling */
#if !defined(kSecSigSize)
# define kSecSigSize 0
#endif

/* Gap fill */
/* Buffer size for gap fill function */
#if ( FBL_MAX_SEGMENT_SIZE > 64u )
# define FILL_BUFFER_SIZE FBL_MAX_SEGMENT_SIZE
#else
# define FILL_BUFFER_SIZE 64u
#endif

#if defined( FBL_DIAG_ENABLE_TASK_LOCKS )
/* Flags indicate which task is currently running */
# define kFblDiagStateTaskRunning      FBL_BIT0    /**< State task active */
# define kFblDiagTimerTaskRunning      FBL_BIT1    /**< Timer task active */

# define SetDiagStateTaskRunning()     (diagTaskState |= kFblDiagStateTaskRunning)                                /**< Set running state of state task */
# define ClrFblDiagStateTaskRunning()  (diagTaskState &= FblInvert8Bit(kFblDiagStateTaskRunning))                 /**< Clear running state of state task */
# define GetDiagStateTaskRunning()     ((diagTaskState & kFblDiagStateTaskRunning) == kFblDiagStateTaskRunning)   /**< Return running state of state task */

# define SetDiagTimerTaskRunning()     (diagTaskState |= kFblDiagTimerTaskRunning)                                /**< Set running state of timer task */
# define ClrDiagTimerTaskRunning()     (diagTaskState &= FblInvert8Bit(kFblDiagTimerTaskRunning))                 /**< Clear running state of timer task */
# define GetDiagTimerTaskRunning()     ((diagTaskState & kFblDiagTimerTaskRunning) == kFblDiagTimerTaskRunning)   /**< Return running state of timer task */
#endif /* FBL_DIAG_ENABLE_TASK_LOCKS */

/***********************************************************************************************************************
 *  TYPEDEFS AND STRUCTURES FOR INTERNAL USE
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/
#define FBLDIAG_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/** Pointer to the data transfer buffer */
V_MEMRAM0 V_MEMRAM1      vuint8              V_MEMRAM2 V_MEMRAM3 * V_MEMRAM1 V_MEMRAM2 DiagBuffer;
/** Stores number of received data */
V_MEMRAM0 V_MEMRAM1_NEAR tCwDataLengthType   V_MEMRAM2_NEAR DiagDataLength;
/** Timer value for TesterPresent timeout */
V_MEMRAM0 V_MEMRAM1_NEAR vuint16             V_MEMRAM2_NEAR testerPresentTimeout;
/** Contains the currently processed diag service ID */
V_MEMRAM0 V_MEMRAM1_NEAR vuint8              V_MEMRAM2_NEAR diagServiceCurrent;
/** State bitmap array */
V_MEMRAM0 V_MEMRAM1_NEAR tFblStateBitmap     V_MEMRAM2_NEAR fblDiagStates[FBL_STATE_INDEX(kFblDiagNumberOfStates - 1u) + 1u];

#if defined( FBL_ENABLE_DEBUG_STATUS )
/* Variables for error status reporting */
V_MEMRAM0 V_MEMRAM1      vuint16          V_MEMRAM2      errStatErrorCode;          /**< Error status */
V_MEMRAM0 V_MEMRAM1      vuint16          V_MEMRAM2      errStatFblStates;          /**< FBL state flag */
V_MEMRAM0 V_MEMRAM1      vuint8           V_MEMRAM2      errStatLastServiceId;      /**< Last received service identifier */ /* PRQA S 1514 */ /* MD_FblDiag_1514_ExternalModuleAccess */
V_MEMRAM0 V_MEMRAM1      vuint8           V_MEMRAM2      errStatFlashDrvVersion[3]; /**< Flash driver version information */
V_MEMRAM0 V_MEMRAM1      vuint16          V_MEMRAM2      errStatFlashDrvErrorCode;  /**< Flash driver error code */
V_MEMRAM0 V_MEMRAM1      tBlockDescriptor V_MEMRAM2      errStatDescriptor;         /**< Error status block descriptor */
#endif

#if defined( FBL_CW_ENABLE_DECLINED_REQUESTS )
/** Receive and send buffers for addtional connections */ /* PRQA S 3218 1 */ /* MD_FblDiag_3218 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 additionalDiagnosticBuffer[kFblCwMaxNumDeclinedRequests][FBL_DIAG_DECLINE_BUFFER_LENGTH];
V_MEMRAM0 static V_MEMRAM1 tFblResult V_MEMRAM2 additionalDiagBufferUsed[kFblCwMaxNumDeclinedRequests];
#endif
#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
#define FBLDIAG_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      diagPostParam;
/** Buffer for response pending message */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      rcrrpBuffer[3];   /* PRQA S 3218 */ /* MD_FblDiag_3218 */

/** Diagnostic response length */
V_MEMRAM0 static V_MEMRAM1 tCwDataLengthType    V_MEMRAM2      diagResLen;

#if defined( FBL_DIAG_ENABLE_TASK_LOCKS )
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      diagTaskState;
#endif /* FBL_DIAG_ENABLE_TASK_LOCKS */

/** Pointer to current service's information table */
V_MEMRAM0 static V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3 * V_MEMRAM1 V_MEMRAM2 serviceInfo;
/** Pointer to current service's sub table */
V_MEMRAM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3 * V_MEMRAM1 V_MEMRAM2 subServiceInfo;

#if defined( FBL_DIAG_ENABLE_SERVICE_PREHANDLER )
/** Pre handler of current request */
V_MEMRAM0 static V_MEMRAM1 tFblDiagPreHandler V_MEMRAM2 fblDiagServicePreHandler;
#endif /* FBL_DIAG_ENABLE_SERVICE_PREHANDLER */
/** Main handler of current request */
V_MEMRAM0 static V_MEMRAM1 tFblDiagMainHandler V_MEMRAM2 fblDiagServiceMainHandler;
/** NRC handler of current request */
V_MEMRAM0 static V_MEMRAM1 tFblDiagNrcHandler V_MEMRAM2 fblDiagServiceNrcHandler;
#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
/** Post handler of current request */
V_MEMRAM0 static V_MEMRAM1 tFblDiagPostHandler V_MEMRAM2 fblDiagServicePostHandler;
/** Post handler for the Tester Present */
V_MEMRAM0 static V_MEMRAM1 tFblDiagPostHandler V_MEMRAM2 fblDiagServiceTesterPresentPostHandler;
#endif /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */

#if defined( FBL_DIAG_ENABLE_CORE_GETLASTERASEDBLK )
V_MEMRAM0 static V_MEMRAM1 tFblLbtBlockNr V_MEMRAM2 lastErasedBlock;
#endif /* FBL_DIAG_ENABLE_CORE_GETLASTERASEDBLK */

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET ) 
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 resetCauseRead;
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET || FBL_ENABLE_ONE_STEP_UPDATER */

/***********************************************************************************************************************
 *  LOCAL DATA - visible in core and OEM layer
 **********************************************************************************************************************/

/** Flag indicating the state of positive response */
V_MEMRAM0 V_MEMRAM1_NEAR vuint8          V_MEMRAM2_NEAR diagResponseFlag;
/** Diagnostic error code */
V_MEMRAM0 V_MEMRAM1 vuint8               V_MEMRAM2      diagErrorCode;

#if defined( FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING )
/* Temporary data used during download in TransferData */
/** Actual number of segments */
V_MEMRAM0 V_MEMRAM1 vuint32               V_MEMRAM2     segmentCount;
#endif /* FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING */

/** Reset timeout observation [ms] */
V_MEMRAM0 V_MEMRAM1 vuint16              V_MEMRAM2      ecuResetTimeout;
/* Sleep mode handling */
#if defined( FBL_ENABLE_SLEEPMODE )
/** Counter, determines when to sleep */
V_MEMRAM0 V_MEMRAM1 vuint32              V_MEMRAM2      sleepCounter;
#endif
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/** Security access delay [ms] */
V_MEMRAM0 V_MEMRAM1 vuint32              V_MEMRAM2      secSecurityAccessDelay;
#endif
#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EXTERNAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
static void       ChkSuppressPosRspMsgIndication(vuint8 *subparam);
static void       FblDiagDiscardReception(void);
static void       FblDiagResponseProcessor(void);

static V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3 * FblDiagGetServiceInfo(vuint8 receivedServiceId);

static vuint32 FblDiagCheckServiceTableEntry(V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3* pServiceInfo,
                                             vuint8 *pbDiagData,
                                             tCwDataLengthType diagReqDataLen);
static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3* FblDiagFindSubTableEntry(V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3* pServiceInfo,
                                        V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3* pServiceErrorMask,
                                        vuint8 *pbDiagData,
                                        tCwDataLengthType diagReqDataLen);
static vuint32 FblDiagCheckSubTableEntry(V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3* pSubtableInfo,
                                         vuint8 *pbDiagData,
                                         tCwDataLengthType diagReqDataLen);

static tFblResult FblDiagServiceProcessingTask(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

static tFblResult FblDiagDefaultNrcHandler(vuint32 serviceErrorMask);

static void FblDiagDeinit(void);
#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Start codeseg to be executed in RAM */
#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
static void FblDiagResetServiceFlags(void);
static void FblDiagConfirmation(void);
/* End section to execute code from RAM */
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  ROUTINES TO MANAGE DIAGNOSTIC SERVICES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Service support functions
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblEcuReset
 **********************************************************************************************************************/
/*! \brief       Start ECU reset.
 **********************************************************************************************************************/
void FblDiagEcuReset(void)
{
   /* Disable tester present timeout monitoring */
   StopTesterTimeout();

   /* Do not transmit response message */
   DiagSetNoResponse();
   FblDiagDeinit();
}

/***********************************************************************************************************************
 *  END OF DIAGNOSTIC SERVICE MANAGEMENT HANDLERS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  DIAGNOSTIC SUPPORT FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Global diagnostic support functions (OEM independent)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagSetError
 **********************************************************************************************************************/
/*! \brief       Sets the corresponding error code for the currently active service
 *  \param[in]   errorCode Negative response code
 **********************************************************************************************************************/
void FblDiagSetError( vuint8 errorCode )
{
   diagErrorCode = errorCode;

   /* No negative response for functional requests with these error codes */
   if (    (FblDiagGetFunctionalRequest())
        && (!FblDiagGetRcrRpInProgress())
        && (   (errorCode == kDiagNrcServiceNotSupported )
            || (errorCode == kDiagNrcSubFunctionNotSupported )
            || (errorCode == kDiagNrcRequestOutOfRange )
#if defined( FBL_DIAG_ENABLE_14229_2013 )
            || (errorCode == kDiagNrcSubfunctionNotSupportedInActiveSession)
            || (errorCode == kDiagNrcServiceNotSupportedInActiveSession)
#endif /* FBL_DIAG_ENABLE_14229_2013 */
           )
      )
   {
     DiagSetNoResponse();
   }
   else
   {
      /* Send negative response for all other cases */
      diagResponseFlag |= kDiagPutNegResponse;
   }
}
#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblRealTimeSupport
 **********************************************************************************************************************/
/*! \brief       Transmit busy messages and triggers the watchdog according to system timer.
 *  \pre         Diagnosis and communication stack must be initialized, diagnostic request has to be received.
 *  \return      FBL_NO_TRIGGER if no timer/watchdog expired, FBL_TM_TRIGGERED if the millisecond timer expired,
 *               FBL_WD_TRIGGERED if watchdog handling code was called.
 **********************************************************************************************************************/
vuint8 FblRealTimeSupport( void )
{
   vuint8 returnCode;

   returnCode = (vuint8)FblLookForWatchdog();
   DiagExRCRResponsePending(kNotForceSendResponsePending);
   return returnCode;
}

/***********************************************************************************************************************
 *  FblRealTimeSupportVoid
 **********************************************************************************************************************/
/*! \brief       Transmit busy messages and triggers the watchdog according to system timer.
 *  \pre         Diagnosis and communication stack must be initialized, diagnostic request has to be received.
 *  \return      None
 **********************************************************************************************************************/
void FblRealTimeSupportVoid( void )
{
   FblLookForWatchdogVoid();
   DiagExRCRResponsePending(kNotForceSendResponsePending);
}

/***********************************************************************************************************************
 *  DiagExRCRResponsePending
 **********************************************************************************************************************/
/*! \brief       Transmit a busy message if timer expires
 *  \details     (forceSend == kNotForceSendResponsePending) or if kForceSendResponsePending is passed.
 *  \param[in]   forceSend Determines if a message is sent independently from timer state
 **********************************************************************************************************************/
void DiagExRCRResponsePending( vuint8 forceSend )
{
   /* Only send response pending if service is in progress */
   if (FblDiagGetRcrRpAllowed())
   {
      /* Conditions to send an RCR-RP if P2-timer expired
       * or parameter contains kForceSendResponsePending */
      if ((forceSend == kForceSendResponsePending)
            || ((forceSend == kForceSendRpIfNotInProgress) && (!FblDiagGetRcrRpInProgress()))
            || (GetP2Timer() < (FblDiagGetRcrRpInProgress() ? kFblDiagP2StarMinThreshold : kFblDiagP2MinThreshold)) )
      {
         /* Prepare parameter for the Diag-confirmation function */
         diagPostParam = kDiagPostRcrRp;

         /* Prepare and transmit RCRRP buffer */
         rcrrpBuffer[0] = kDiagRidNegativeResponse;
         rcrrpBuffer[1] = diagServiceCurrent;
         rcrrpBuffer[2] = kDiagNrcRcrResponsePending;
         FblCwTransmitRP(rcrrpBuffer);

         /* Restart P2-Timer to P2* */
         SetP2Timer((vuint16)kFblDiagTimeP2Star);

         /* If response pending is transmitted and no response
          * is set, a positive response has to be transmitted anyway. */
         diagResponseFlag &= FblInvert8Bit(kDiagPutNoResponse);

         FblDiagSetRcrRpInProgress();
      }
   }
}
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblDiagMemGetActiveBuffer
 **********************************************************************************************************************/
/*! \brief       Function updates core Diagnostic buffer (DiagBuffer) and returns updated pbDiagData to handler
 *  \return      updated pbDiagData buffer used by diagnostic handler functions *
 **********************************************************************************************************************/
V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * FblDiagMemGetActiveBuffer(void)
{
   DiagBuffer = FblMemGetActiveBuffer();
   return &DiagBuffer[kDiagFmtpbDiagData];
}

/***********************************************************************************************************************
 *  Local diagnostic support functions (OEM independent)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  DiagProcessingDone
 **********************************************************************************************************************/
/*! \brief       Prepare positive response.
 *  \details     Prepares the positive response for the currently processed service.
 *  \pre         Service must be in progress
 *  \param[in]   dataLength Data length to be transmitted (excluding the service-id itself).
 **********************************************************************************************************************/
void DiagProcessingDone( tCwDataLengthType dataLength )
{
   diagResponseFlag |= kDiagPutPosResponse;
   diagResLen        = dataLength;
}

/***********************************************************************************************************************
 *  FblDiagDiscardReception
 **********************************************************************************************************************/
/*! \brief       Received diagnostic messages are discarded
 *  \details     Discards all messages which have been received during a service is processed.
 **********************************************************************************************************************/
static void FblDiagDiscardReception( void )
{
   FblDiagSetResponseProcessing();   /* Set flag for running response procedure */

   FblCwDiscardReception();
   FblDiagClrResponseProcessing();
}
#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Start codeseg to be executed in RAM */
#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblDiagResetServiceFlags
 **********************************************************************************************************************/
/*! \brief       Clear all status flags relevant for service handling.
 *  \pre         Service response shall be finished.
 **********************************************************************************************************************/
static void FblDiagResetServiceFlags( void )
{
   /* Clear negative response indicator */
   DiagClrError();

   /* Reset internal state in case no response was sent */
   FblDiagClrServiceInProgress();
   FblDiagClrRcrRpInProgress();
   /* Reset flag for functional request, default is physical request */
   FblDiagClrFunctionalRequest();
   FblDiagClrExecutePostHandler();
   /* Reset flag for suppress positive response bit */
   FblDiagClrSuppressPosRspMsg();

   /* diagResponse state back to idle */
   diagResponseFlag = kDiagResponseIdle;
}

/***********************************************************************************************************************
 *  FblDiagConfirmation
 **********************************************************************************************************************/
/*! \brief       Clear all status flags and conclude service transmission.
 *  \pre         Service response has been sent recently.
 **********************************************************************************************************************/
static void FblDiagConfirmation( void )
{
   /* Buffer is now available */
   FblDiagClrBufferLocked();
   /* Clear all diagnostic states */
   ClrP2Timer();

#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
   /* Check for a valid service indicator */
   if( FblDiagGetExecutePostHandler() && ( fblDiagServicePostHandler != (tFblDiagPostHandler)0u ))
   {
      /* Call the postHandler of the last received service */
      (*fblDiagServicePostHandler)( diagPostParam );
   }
#endif   /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */

   /* Clear all flags for service handling */
   FblDiagResetServiceFlags();

#if defined( FBL_DIAG_ENABLE_OEM_SERVICENOTIFICATION )
   /* Trigger a callback as soon as the service processing is finished  */
   FblDiagOemServiceReceptionNotification(kFblDiagServiceNotificationEnd);
#endif

   /* Restart the tester present timer if not in default session */
   if (FblDiagGetProgrammingSession() || FblDiagGetExtendedSession())
   {
      ResetTesterTimeout();
   }
}

/* End section to execute code from RAM */
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblDiagResponseProcessor
 **********************************************************************************************************************/
/*! \brief       Prepares response message and hands it over to ComWrapper.
 *  \details     Prepares either a positive or negative response. Depending on the response type,
 *               the service ID is set to SID + 0x40 or 0x7F.
 *  \pre         Current SID must be in DiagBuffer[0], diagErrorCode must be initialized.
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
static void FblDiagResponseProcessor( void )
{
   /* Service will be concluded under this condition */
   if(( diagResponseFlag & kDiagResponseActive ) != 0u )
   {
      /* Stop transmission of response pending messages */
      FblDiagClrRcrRpAllowed();
      ClrP2Timer();
      FblDiagClrRcrRpInProgress();

      /* Discard all service requests received during processing this one */
      FblDiagDiscardReception();
      FblErrStatSetSId( diagServiceCurrent );

      /* No repsonse on functional request has highest priority
       * Must be checked first. */
      if (( diagResponseFlag & kDiagPutNoFuncResponse ) != 0u )
      {
         /* Set response type */
         diagPostParam = kDiagPostNoResponse;

         /* Service conclusion */
         FblDiagConfirmation();

         /* Check if a reset shall be generated without message transmission */
         if (FblDiagGetWaitEcuReset())
         {
            /* If so, generate the reset immediately */
            FblDiagSetResetMsgConfirmed();
         }

         FblCwResetRxBlock();
      }
      else if(( diagResponseFlag & kDiagPutNegResponse) != 0u )
      {
         /* Set response type */
         diagPostParam = kDiagPostNegResponse;

         /* Prepare response message */
         DiagBuffer[kDiagFmtSubparam]     = diagServiceCurrent;
         DiagBuffer[kDiagFmtServiceId]    = kDiagRidNegativeResponse;
         DiagBuffer[kDiagFmtNegResponse]  = DiagGetError();

         assertFblUser(DiagGetError() != kDiagErrorNone, kFblSysAssertParameterOutOfRange);  /* PRQA S 2214 */ /* MD_FblDiag_2214 */
         FblCwTransmit(DiagBuffer, 3u, kFblCwTxCallNegResponse);

         /* diagResponse state back to idle */
         diagResponseFlag = kDiagResponseIdle;
      }
      else if (( diagResponseFlag & kDiagPutNoResponse ) != 0u )
      {
         /* Set response type */
         diagPostParam = kDiagPostNoResponse;

         /* Service conclusion */
         FblDiagConfirmation();

         /* Check if a reset shall be generated without message transmission */
         if (FblDiagGetWaitEcuReset())
         {
            /* If so, generate the reset immediately */
            FblDiagSetResetMsgConfirmed();
         }

         FblCwResetRxBlock();
      }
      else if ((diagResponseFlag & kDiagPutPosResponse) != 0u) /* PRQA S 2991, 2995 */ /* MD_FblDiag_2991_2995_RedundantCondition */
      {
         /* Set response type */
         diagPostParam = kDiagPostPosResponse;

         /* Transmit positive response if not suppressed */
         DiagBuffer[kDiagFmtServiceId] = (vuint8)(diagServiceCurrent + 0x40u);
         FblCwTransmit(DiagBuffer, (tCwDataLengthType)( diagResLen + 1u ), kFblCwTxCallPosResponse );

         /* diagResponse state back to idle */
         diagResponseFlag = kDiagResponseIdle;
      }
      else
      {
         /* This is an illegal state and should not occur */
         assertFblInternal(0u, kFblSysAssertParameterOutOfRange); /* PRQA S 2741, 2880, 4558 */ /* MD_FblDiag_2741_ConstantExpression, MD_MSR_Unreachable, MD_FblDiag_4558 */

         /* Set response type */
         diagPostParam = kDiagResponseIdle;
      }

      /* Should be an assertion */
      if( diagPostParam == kDiagPostRcrRp )
      {
        /* diagResponse state back to idle */
        diagResponseFlag = kDiagResponseIdle;
      }
   }
}

/***********************************************************************************************************************
 *  ChkSuppressPosRspMsgIndication
 **********************************************************************************************************************/
/*! \brief       This functions checks if a diagnostic response has to be sent.
 *  \details     If the request is received with Suppress Positive Response Bit (0x80), the response is cancelled.
 *  \param[in]   subparam Diagnostic sub-parameter
 **********************************************************************************************************************/
static void ChkSuppressPosRspMsgIndication( vuint8 *subparam )
{
   if (((*(subparam)) & (kDiagSuppressPosRspMsgIndicationBit)) != 0u)
   {
      /* Set internal flag to suppress positive response */
      DiagSetNoResponse();
      FblDiagSetSuppressPosRspMsg();

      /* Clear suppress bit in request message */
      (*(subparam)) &= FblInvert8Bit( kDiagSuppressPosRspMsgIndicationBit );
   }
}
#if defined( FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING )
/***********************************************************************************************************************
 *  FblDiagSegmentNext
 **********************************************************************************************************************/
/*! \brief       Keep track of segment counter
 *  \return      kSwmOutOfRange if maximum segment count exceeded, number of segments otherwise
 **********************************************************************************************************************/
vuint32 FblDiagSegmentNext( void )
{
   vuint32 result;

   /* Compare current used NOAR against max. value */
   if (segmentCount >= SWM_DATA_MAX_NOAR)
   {
      /* ALL PMA processed. Stop reading data */
      result =  kSwmOutOfRange;
   }
   else
   {
      /* Increment segment count */
      segmentCount++;

      result = segmentCount;
   }

   return result;
}
#endif /* FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING */

#if defined( FBL_DIAG_ENABLE_CORE_GETBLOCKFROMID )
/***********************************************************************************************************************
 *  FblGetNrFromBlockTable
 **********************************************************************************************************************/
/*! \brief       Get logical block number for a given block index
 *  \details     Get the number of the corresponding logical block for the given block index.
 *  \param[in]   pBlockTable Pointer to block table which should be evaluated
 *  \param[in]   noOfBlocks Number of blocks included in pBlockTable
 *  \param[in]   blockIndex Index of logical block
 *  \param[out]  pLogicalBlockNr Logical block number
 *  \return      kFblOk if blockIndex has been found, otherwise kFblFailed
 **********************************************************************************************************************/
tFblResult FblGetNrFromBlockTable(V_MEMROM1 tBlockDescriptor V_MEMROM2 V_MEMROM3 * pBlockTable, vuint8 noOfBlocks,
   tFblLbtBlockIndex blockIndex, vuint8 * pLogicalBlockNr)
{
   tFblResult result;
   vuint8 tempCount;

   /* Initialize variables */
   result = kFblFailed;
   *pLogicalBlockNr = 0xFFu;

   (void)FblLookForWatchdog();
   tempCount = 0u;
   /* Search logical block table for blockIndex */
   while ((result == kFblFailed) && (tempCount < noOfBlocks))
   {
      /* Check if requested index matches a logical block index */
      if (blockIndex == pBlockTable[tempCount].blockIndex)
      {
         result = kFblOk;
         *pLogicalBlockNr = tempCount;
      }

      /* Increment loop counter */
      tempCount++;
   }

   return result;
}
#endif /* FBL_DIAG_ENABLE_CORE_GETBLOCKFROMID */

#if defined( FBL_DIAG_ENABLE_CORE_MAX_TDBLOCKLENGTH )
/***********************************************************************************************************************
 *  FblDiagGetMaxTransferDataBlockLength
 **********************************************************************************************************************/
/*! \brief       Evaluate maximum TransferData block length for active connection
 *  \details     Length is the minimum of link payload length and configured diagnostic buffer size
 *  \return      TransferData block length applicable for active connection
 **********************************************************************************************************************/
tCwDataLengthType FblDiagGetMaxTransferDataBlockLength(void)
{
   tCwDataLengthType maxBlockLength;

   /* Get payload limit of active communication link */
   maxBlockLength = FblCwGetPayloadLimit();

   /* Limit block length to available diagnostic buffer size */
   if (FBL_DIAG_BUFFER_LENGTH < maxBlockLength)
   {
      maxBlockLength = (tCwDataLengthType)FBL_DIAG_BUFFER_LENGTH;
   }

# if defined( FBL_ENABLE_UNALIGNED_DATA_TRANSFER )
# else
   /* Align length to memory maximum memory segment size */
   maxBlockLength = ((maxBlockLength - 2u) & FblInvert32Bit(FBL_MAX_SEGMENT_SIZE - 1u)) + 2u;
# endif /* FBL_ENABLE_UNALIGNED_DATA_TRANSFER */

   return maxBlockLength;
}

/***********************************************************************************************************************
 *  FblDiagSetMaxTransferDataBlockLength
 **********************************************************************************************************************/
/*! \brief           Set the maximum TransferData block length for active connection and prepare UDS response
 *  \details         Considers the minimum LFI defined by customer
 *  \param[out]      pbDiagBuffer Pointer to LFI in diagnostic buffer. Used to store LFI + buffer size according to UDS
 *  \param[in]       minLfi Minimum value of LFI considered for filling the DiagBuffer, regardless of if the buffer
 *                    size can be encoded in 2 bytes
 *  \return          Calculated LFI value considering maximum block length and minimum LFI value defined by customer
 **********************************************************************************************************************/
vuint8 FblDiagSetMaxTransferDataBlockLength(vuint8 * pbDiagBuffer, vuint8 minLfi)
{
   vuint8 lengthFormat;
   tCwDataLengthType maxBlockLength;

   maxBlockLength = FblDiagGetMaxTransferDataBlockLength();

   /* Length format dependent on maximum block length */
   /* PRQA S 2880, 2992, 2996 7 */ /* MD_FblDiagCore_2880_2992_2996 */
   if (maxBlockLength > 0xFFFFFFu)
   {
      lengthFormat = 4u;
   }
   else if (maxBlockLength > 0xFFFFu)
   {
      lengthFormat = 3u;
   }
   else
   {
      /* Use at least two length bytes */
      lengthFormat = 2u;
   }

   /* LFI have to be a minimum size defined by customer */
   if (minLfi > lengthFormat)
   {
      lengthFormat = minLfi;
   }

   /* Prepare response */
   *pbDiagBuffer = (lengthFormat << 4u);
   FblMemSetInteger(lengthFormat, maxBlockLength, &pbDiagBuffer[1u]);

   return lengthFormat;
}
#endif /* FBL_DIAG_ENABLE_CORE_MAX_TDBLOCKLENGTH */

/***********************************************************************************************************************
 *  DIAGNOSTIC MODULE CONTROL ROUTINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Initialization handling of diagnostic module
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagInitPowerOn
 **********************************************************************************************************************/
/*! \brief       Initialize module variables
 **********************************************************************************************************************/
void FblDiagInitPowerOn(void)
{
   vuintx i;

   /* Initialize diagnostic states */
   for (i = 0u; i < (FBL_STATE_INDEX(kFblDiagNumberOfStates - 1u) + 1u); i++)
   {
      fblDiagStates[i] = (tFblStateBitmap)0x00u;
   }

   /* Initialize diagnostic variables */
   diagResponseFlag = kDiagResponseIdle;

   DiagClrError();

#if defined( FBL_DIAG_ENABLE_SERVICE_PREHANDLER )
   fblDiagServicePreHandler = (tFblDiagPreHandler)0u;
#endif /* FBL_DIAG_ENABLE_SERVICE_PREHANDLER */
   fblDiagServiceMainHandler = (tFblDiagMainHandler)0u;
   fblDiagServiceNrcHandler = (tFblDiagNrcHandler)0u;
#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
   fblDiagServicePostHandler = (tFblDiagPostHandler)0u;
#endif /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */

#if defined( FBL_DIAG_ENABLE_CORE_GETLASTERASEDBLK )
   lastErasedBlock = kBlockNrInvalid;
#endif /* FBL_DIAG_ENABLE_CORE_GETLASTERASEDBLK */

   /* Initialize diagnostic session */
   FblDiagSetDefaultSession();   /* PRQA S 3109 */ /* MD_FblDiag_3109 */

   /* Stop tester present timer */
   StopTesterTimeout();

   /* Clear timer for response pending transmission */
   ClrP2Timer();

   /* Make sure to turn off the programming voltage */
   ApplFblResetVfp();

   StopEcuResetTimeout();

#if defined( FBL_ENABLE_SLEEPMODE )
   /* Sleep Timer not running during startup */
   FblSleepCounterClear();
#endif /* FBL_ENABLE_SLEEPMODE */

#if defined( FBL_DIAG_ENABLE_TASK_LOCKS )
   diagTaskState = 0u;
#endif /* FBL_DIAG_ENABLE_TASK_LOCKS */

#if defined( FBL_CW_ENABLE_DECLINED_REQUESTS )
   for (i = 0u; i < kFblCwMaxNumDeclinedRequests; i++)
   {
     additionalDiagBufferUsed[i] = kFblFailed;
   }
#endif /* FBL_CW_ENABLE_DECLINED_REQUESTS */

#if defined( FBL_DIAG_ENABLE_OEM_INITPOWERON )
   /* OEM-specific initializations */
   FblDiagOemInitPowerOn();
#endif /* FBL_DIAG_ENABLE_OEM_INITPOWERON */
}

/***********************************************************************************************************************
 *  FblDiagInit
 **********************************************************************************************************************/
/*! \brief       Initialize diagnostic module
 *  \details     Sets the diagnostic module to default session and initializes depending modules. The diagnostic
 *               module is working from here, but NV-memory dependent features are not available in all configurations.
 **********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
void FblDiagInit(void)
{
   tCwDataLengthType requestLength = 0u;

   /* Get aligned diag buffer pointer from memory library */
   DiagBuffer = FblMemInitPowerOn();

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET ) 
   resetCauseRead = RESET_RESPONSE_NOT_REQUIRED;
   /* Check if reset has been caused by diagnostic service
    * StartDiagnosticSession (Default Session), EcuReset, or FBL returns from OSU */
   if ((kFblOk == ApplFblReadResetResponseFlag(&resetCauseRead))
      && (resetCauseRead != RESET_RESPONSE_NOT_REQUIRED))
   {

      {
# if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
         requestLength = kDiagRqlDiagnosticSessionControl + 1u;
# else /* FBL_ENABLE_RESPONSE_AFTER_RESET */
         /* FBL should only be able to be started from OSU */
         /* PRQA S 2214, 2741 1 */ /* MD_FblDiag_2214, MD_FblDiag_2741_ConstantExpression */
         assertFblInternal(0u, kFblSysAssertInitializationFailed);
# endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */
      }
   }
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET || FBL_ENABLE_ONE_STEP_UPDATER */

   /* Check if FBL has to respond to request received by application */
   if (FblMainGetStartFromAppl())
   {
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET ) 
      /* Check if FBL already received a response after reset request or returns from OSU */
      /* PRQA S 2214, 2741 1 */ /* MD_FblDiag_2214, MD_FblDiag_2741_ConstantExpression */
      assertFblInternal(requestLength == 0u, kFblSysAssertInitializationFailed);
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET || FBL_ENABLE_ONE_STEP_UPDATER*/

      requestLength = kDiagRqlSpsFromAppl + 1u;
   }
#if defined( FBL_DIAG_ENABLE_CORE_OTA )
   if (FblMainGetStartFromOta())
   {
      /* Check if FBL already received a response after reset request, returns from OSU or was started by application */
      /* PRQA S 2214, 2741 1 */ /* MD_FblDiag_2214, MD_FblDiag_2741_ConstantExpression */
      assertFblInternal(requestLength == 0u, kFblSysAssertInitializationFailed);

      requestLength = kDiagRqlStartFromOta + 1u;
   }
#endif /* FBL_DIAG_ENABLE_CORE_OTA */

   /* Immediately lock buffer if FBL has to respond to request received by application */
   if (FblDiagRxGetPhysBuffer(requestLength) == DiagBuffer)
   {
      FblDiagSetRespBufLockedByInit();
   }

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
# if defined( FBL_DIAG_ENABLE_CORE_READ_SECACCESSDELAY_FLAG )
   /* Pre-init security access delay status - no NV-memory available here */
   SetSecurityAccessDelay();
# endif /* FBL_DIAG_ENABLE_CORE_READ_SECACCESSDELAY_FLAG */
#endif

#if defined( FBL_ENABLE_DEBUG_STATUS )
   /* Initialize error status */
   ApplFblInitErrStatus();
#endif

#if defined ( FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING )
   /* Initialize segment counter */
   FblDiagSegmentInit();
#endif

   /* Initialize security module */
   (void)ApplFblSecurityInit();

   /* Init ComWrapper */
   FblCwSetTxInit();

#if defined( FBL_DIAG_ENABLE_OEM_INIT )
   /* OEM-specific initializations */
   FblDiagOemInit();
#endif /* FBL_DIAG_ENABLE_OEM_INIT */

#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )

   /* Get tester present configured service in the service table */
   serviceInfo = FblDiagGetServiceInfo(kDiagSidTesterPresent);

   /* Check if tester present is supported in service table */
   if (serviceInfo == (V_MEMROM1 tFblDiagServiceTable  V_MEMROM2 V_MEMROM3 *) V_NULL)
   {
      assertFblInternal(0u, kFblSysAssertParameterOutOfRange); /* PRQA S 2741, 4558 */ /* MD_FblDiag_2741_ConstantExpression, MD_FblDiag_4558 */
      fblDiagServiceTesterPresentPostHandler = (tFblDiagPostHandler)0u;
   }
   else
   {
      fblDiagServiceTesterPresentPostHandler = serviceInfo->servicePostHandler;
   }
#endif /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */
}

/***********************************************************************************************************************
 *  FblDiagPostInit
 **********************************************************************************************************************/
/*! \brief       Initialize diagnostic module
 *  \details     Finishes the initialization of the diagnostic module. NV-memory dependent initialization can
 *               be done here.
 **********************************************************************************************************************/
void FblDiagPostInit(void)
{
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
# if defined( FBL_DIAG_ENABLE_CORE_READ_SECACCESSDELAY_FLAG )
   /* Initialize security access delay timer after nv-memory access is possible. */
   if (!ApplFblGetSecAccessDelayFlag())
   {
      ClrSecurityAccessDelay();
   }
# endif /* FBL_DIAG_ENABLE_CORE_READ_SECACCESSDELAY_FLAG */
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET ) 
   if (resetCauseRead != RESET_RESPONSE_NOT_REQUIRED)
   {
      vuint8 resetCauseWrite = RESET_RESPONSE_NOT_REQUIRED;

      /* FBL started from reset or OSU
       * Clear flag before sending response to be ready for the next request */
      (void)ApplFblWriteResetResponseFlag(&resetCauseWrite); /* PRQA S 3425 */ /* MD_FblDiag_3425 */
      {
# if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
         /* Send response for StartDiagnosticSession or EcuReset request */
         FblDiagInitStartFromReset(resetCauseRead);
# endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */
      }
   }
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET || FBL_ENABLE_ONE_STEP_UPDATER */

   /* Send programming session request response */
   if (FblMainGetStartFromAppl())
   {
      /* FBL started from application */
      FblDiagInitStartFromAppl();
   }
#if defined( FBL_DIAG_ENABLE_CORE_OTA )
   /* Check if there is an OTA request */
   if (FblMainGetStartFromOta())
   {
      FblDiagInitStartFromOta();
   }
#endif /* FBL_DIAG_ENABLE_CORE_OTA */

#if defined( FBL_ENABLE_SLEEPMODE )
   /* Initialize sleep mode counter */
   FblSleepCounterReload();
#endif

#if defined( FBL_DIAG_ENABLE_OEM_POSTINIT )
   /* OEM-specific initializations */
   FblDiagOemPostInit();
#endif /* FBL_DIAG_ENABLE_OEM_POSTINIT */
}

/***********************************************************************************************************************
 *  FblDiagDeinit
 **********************************************************************************************************************/
/*! \brief       Function prepares for FBL shutdown on diagnostic service request.
 **********************************************************************************************************************/
static void FblDiagDeinit(void)
{
   /* Discard pending FblLib_Mem tasks */
   FblMemDeinit();

#if defined( FBL_DIAG_ENABLE_OEM_DEINIT )
   /* Shutdown OEM-specific service handling */
   FblDiagOemDeinit();
#endif /* FBL_DIAG_ENABLE_OEM_DEINIT */

   if (FblDiagGetProgrammingSession())
   {
      /* ECU programming mode is active */
      FblDiagClrProgrammingSession();
      if (FblDiagGetMemDriverInitialized())
      {
         /* Remove memory driver from RAM-buffer */
         FblCwSetOfflineMode();

         (void)MemDriver_DeinitSync((void*)V_NULL);

         FblCwSetOnlineMode();

         /* Reinitialize memory driver flash */
         FblDiagClrMemDriverInitialized();
      }

      /* Turn off programming voltage */
      ApplFblResetVfp();
   }

   FblDiagClrWaitEcuReset();   /* PRQA S 3109 */ /* MD_FblDiag_3109 */

   /* Clear all flags for service handling */
   FblDiagResetServiceFlags();

   /* Request shutdown from ComWrapper */
   FblCwShutdownRequest(kFblCwResetEcuRegularCase);
}

/***********************************************************************************************************************
 *  FblDiagServiceProcessingTask
 **********************************************************************************************************************/
/*! \brief       Service processing done in FblDiagStateTask
 *  \details     If a service should be processed, this function performs service processing tasks
 *  \param[in]   pbDiagData Pointer to data in the diagBuffer (without SID).
 *  \param[in]   diagReqDataLen Length of data (without SID).
 *  \return      Result of service processing
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblDiagServiceProcessingTask(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   vuint32 serviceProcessingErrors;

   /* Prepare control variable */
   serviceProcessingErrors = kFblDiagServiceOk;

   /* This is the initial call after reception of a service request */
   if (diagResponseFlag == kDiagResponseRequested)
   {
      /* Update security seed each time a service is received. */
      (void)ApplFblSecuritySeedInit();

      /* Advance service processing state to repeated service
       * This will ensure that the service handler will be
       * called until it has been concluded, e.g. by DiagProcessingDone() */
      diagResponseFlag = kDiagRepeatResponse;

      /* Search for a valid configured service in the service table */
      serviceInfo = FblDiagGetServiceInfo(diagServiceCurrent);

      /* Check if service is supported in service table */
      if (serviceInfo == (V_MEMROM1 tFblDiagServiceTable  V_MEMROM2 V_MEMROM3 *) V_NULL)
      {
         /* No service found. Default NRC handler will be invoked */
         serviceProcessingErrors = kFblDiagServiceNotFound;
         fblDiagServiceNrcHandler = FblDiagDefaultNrcHandler;
      }
      else
      {
         serviceProcessingErrors = FblDiagCheckServiceTableEntry(serviceInfo, pbDiagData, diagReqDataLen);
#if defined( FBL_DIAG_ENABLE_SERVICE_PREHANDLER )
         fblDiagServicePreHandler = serviceInfo->servicePreHandler;
#endif /* FBL_DIAG_ENABLE_SERVICE_PREHANDLER */
         fblDiagServiceMainHandler = serviceInfo->serviceMainHandler;
#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
         fblDiagServicePostHandler = serviceInfo->servicePostHandler;
#endif /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */
         fblDiagServiceNrcHandler = serviceInfo->serviceNrcHandler;

         /* Check if further sub-table tests have to be done. Sub-table tests are done only
            if no error on service level has been detected. */
         if ((serviceProcessingErrors & kFblDiagSubTableNotFound) == 0u)
         {
            subServiceInfo = FblDiagFindSubTableEntry(serviceInfo, &serviceProcessingErrors, pbDiagData, diagReqDataLen);

            /* Check if a matching sub-table has been found */
            if ((serviceProcessingErrors & kFblDiagSubTableNotFound) == kFblDiagSubTableNotFound)
            {
               /* If no sub-table is found, the service handler of the service can be invoked
                * in case there are no service level errors. This handler is already configured. */
               if ((serviceProcessingErrors & kFblDiagServiceLevelErrors) == 0u)
               {
                  if (fblDiagServiceMainHandler != (tFblDiagMainHandler)0u)
                  {
                     /* Remove sub-service level errors */
                     serviceProcessingErrors &= kFblDiagServiceLevelErrors;
                  }
               }
            }
            else
            {
               /* Check sub-table parameters */
               serviceProcessingErrors |= FblDiagCheckSubTableEntry(subServiceInfo, pbDiagData, diagReqDataLen);
               fblDiagServiceMainHandler = subServiceInfo->serviceMainHandler;
            }
         }
         else
         {
            /* No sub-table used. Remove error bit. */
            serviceProcessingErrors &= kFblDiagServiceLevelErrors;
         }

#if defined( FBL_DIAG_ENABLE_SERVICE_PREHANDLER )
         /* Use service pre-handler to check service preconditions. */
         if (((serviceProcessingErrors & kFblDiagServiceErrorMask) == 0u) && (fblDiagServicePreHandler != (tFblDiagPreHandler)V_NULL))
         {
            if ((*fblDiagServicePreHandler)(pbDiagData, diagReqDataLen) == kFblFailed)
            {
               serviceProcessingErrors |= kFblDiagServicePrehandlerFailure;
            }
         }
#endif /* FBL_DIAG_ENABLE_SERVICE_PREHANDLER */
      }
   }

   /* Call service main handler or NRC handler */
   if (serviceProcessingErrors == kFblDiagServiceOk)
   {
      /* Allow usage of response pending messages here */
      FblDiagSetRcrRpAllowed();

      /* Call main handler in case no error has been detected. */
      result = (*fblDiagServiceMainHandler)(pbDiagData, diagReqDataLen);
   }
   else
   {
      /* Call NRC handler. This handler is also called in case no service at all has been found. */
      result = (*fblDiagServiceNrcHandler)(serviceProcessingErrors);
   }

#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
   /* Diagnostic service has been processed. Post-handler needs to be invoked. */
   FblDiagSetExecutePostHandler();
#endif /* FBL_DIAG_ENABLE_SERVICS_POST_HANDLER */

   /* Finish service processing if service has been concluded before */
   FblDiagResponseProcessor();

   return result;
}

/***********************************************************************************************************************
 *  FblDiagStateTask
 **********************************************************************************************************************/
/*! \brief       This function handles the surveillance of the tester present timer.
 *  \details     When a timeout occurs the startup code of the FBL is executed.
 **********************************************************************************************************************/
void FblDiagStateTask( void )
{
#if defined( FBL_DIAG_ENABLE_TASK_LOCKS )
   if (!GetDiagStateTaskRunning())
   {
      SetDiagStateTaskRunning();
#endif /* FBL_DIAG_ENABLE_TASK_LOCKS */

      /* Diagnostic service dispatcher. Will be executed when a service has to be managed
       * No executed if the diagnostic service is waiting for a reset. */
      if ((!FblDiagGetWaitEcuReset()) && (diagResponseFlag != kDiagResponseIdle))
      {
         /* Call service task. Return value is not used but maintained for future use. */
         (void)FblDiagServiceProcessingTask(&DiagBuffer[kDiagFmtSubparam], (tCwDataLengthType)(DiagDataLength));
      }

#if defined( FBL_MEM_ENABLE_PIPELINING )
      /* Check that there is no reset request to decide on continuing stored FblLib_Mem operations */
      if (!FblDiagGetWaitEcuReset())
      {
         /* Resume stored FblLib_Mem operation */
         FblMemResumeIndication();
      }
#endif /* FBL_MEM_ENABLE_PIPELINING */

      /* Check for reset request
       * The following preconditions have to be fulfilled:
         * Reset message confirmed
         * Pre-reset function (e.g. flag written to NV-memory) has finished */
      if ((FblDiagGetWaitEcuReset()) && (FblDiagGetResetMsgConfirmed()) && (FblDiagGetEcuResetFctFinished())) /* PRQA S 0410 */ /* MD_FblDiag_0410 */
      {
         FblDiagDeinit();
      }

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
      /* Check if Security access delay counter close to expire */
      if (GetSecurityAccessDelay() == 1u)
      {
# if defined( FBL_DIAG_ENABLE_CORE_SECACCESSCOUNTER_RESET )
         /* Reset security access attempt counter after delay expired */
         vuint8 securityAccessDelayCounterReset;
         securityAccessDelayCounterReset = kDiagSecAccessResetValue;
         (void)ApplFblWriteSecAccessInvalidCount(&securityAccessDelayCounterReset);
# endif /* FBL_DIAG_ENABLE_CORE_SECACCESSCOUNTER_RESET */
# if defined( FBL_DIAG_ENABLE_CORE_WRITE_SECACCESSDELAY_FLAG )
         /* Clear security access delay flag */
         (void)ApplFblClrSecAccessDelayFlag();
# endif /* FBL_DIAG_ENABLE_CORE_WRITE_SECACCESSDELAY_FLAG */

            /* If so, conclude the decrement and check to clear the flag in EEPROM */
         ClrSecurityAccessDelay();
      }
#endif

#if defined( FBL_DIAG_ENABLE_OEM_STATETASK )
      FblDiagOemStateTask();
#endif /* FBL_DIAG_ENABLE_OEM_STATETASK */

#if defined( FBL_DIAG_ENABLE_TASK_LOCKS )
      /* Allow further task executions */
      ClrFblDiagStateTaskRunning();
   }
#endif /* FBL_DIAG_ENABLE_TASK_LOCKS */
}

/***********************************************************************************************************************
 *  Diagnostic tasks
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagTimerTask
 **********************************************************************************************************************/
/*! \brief       This function handles the surveillance of the tester present timer.
 *  \details     When a timeout occurs the startup code of the FBL is executed. Has to be executed from RAM
 *               if diagnostic functionality should be maintained while flashing, e.g. if pipelined programming
 *               is enabled.
 **********************************************************************************************************************/
void FblDiagTimerTask(void)
{
#if defined( FBL_DIAG_ENABLE_TASK_LOCKS )
   if (!GetDiagTimerTaskRunning())
   {
      SetDiagTimerTaskRunning();
#endif /* FBL_DIAG_ENABLE_TASK_LOCKS */
      /* Tester present timing */
      if (TimeoutTesterValue() != 0u)
      {
         DecTimeoutTesterValue();
         if (TimeoutTesterValue() == 0u)
         {
#if defined( FBL_DIAG_ENABLE_OEM_SESSION_TIMEOUT )
            FblDiagSessionTimeout();
#else
            /* Tester present timer expired, exit bootloader via reset */
            FblDiagEcuReset();
#endif
         }
      }

      /* ECU reset is pending */
      if (TimeoutEcuResetValue() != 0u)
      {
         DecTimeoutEcuResetValue();
         if (TimeoutEcuResetValue() == 0u)
         {
            /* ECU reset timer expired
             * Exit bootloader via Reset, but force no response!! */
            FblDiagEcuReset();
         }
      }


#if defined( FBL_ENABLE_SLEEPMODE )
            /* Sleep mode timer */
            if (FblGetSleepCounter() != 0u)
            {
               FblDecSleepCounter();
               if (FblGetSleepCounter() == 0u)
               {
                  ApplFblBusSleep();
                  FblSleepCounterReload();
               }
            }
#endif /* FBL_ENABLE_SLEEPMODE */

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
      /* Security access delay timing */
      if (GetSecurityAccessDelay() > 1u)
      {
         DecSecurityAccessDelay();
      }
#endif

#if defined( FBL_DIAG_ENABLE_OEM_TIMERTASK )
      FblDiagOemTimerTask();
#endif /* FBL_DIAG_ENABLE_OEM_TIMERTASK */

#if defined( FBL_DIAG_ENABLE_TASK_LOCKS )
      /* Allow further task executions */
      ClrDiagTimerTaskRunning();
   }
#endif /* FBL_DIAG_ENABLE_TASK_LOCKS */
}

/***********************************************************************************************************************
 *  Diagnostic kernel handling functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagDefaultNrcHandler
 **********************************************************************************************************************/
/*! \brief       This routine is called as default NRC handler
 *  \details     Called in case no service has been found. User services can be added here.
 *  \param[in]   serviceErrorMask Error bit mask of table check
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagDefaultNrcHandler(vuint32 serviceErrorMask)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)serviceErrorMask; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

#if defined( FBL_ENABLE_USERSERVICE )
   FblDiagSetRcrRpAllowed();
   ApplDiagUserService(&DiagBuffer[kDiagFmtSubparam], (tCwDataLengthType)(DiagDataLength));
#else
   DiagNRCServiceNotSupported();
#endif /* FBL_ENABLE_USERSERVICE */

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagFindSubTableEntry
 **********************************************************************************************************************/
/*! \brief       Find a suitable sub-table entry for the currently requested service
 *  \pre         Sub-table is available
 *  \param[in]   pServiceInfo Pointer to service descriptor
 *  \param[out]  pSubtableInfo Pointer to service descriptor
 *  \param[in]   pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]   diagReqDataLen Data length (without SID).
 *  \return      Sub service table
 **********************************************************************************************************************/
/* PRQA S 6010, 6030 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC */
static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3* FblDiagFindSubTableEntry(V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3* pServiceInfo,
                                        V_MEMRAM1 vuint32 V_MEMRAM2 V_MEMRAM3* pServiceErrorMask,
                                        vuint8 *pbDiagData,
                                        tCwDataLengthType diagReqDataLen)
{
   V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3* subTableEntry;
   vuint32 tempServiceErrorMask;

   vuintx subFunctionLength;
   vuintx subParamLength;

   vuintx subTableIndex;
   vuintx subTableIdIndex;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   /* Initialize variables */
   subTableIndex = 0u;
   subTableEntry = (V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3*)V_NULL;

   /* Add sub-table not found, sub-function not found and sub-param not found bits.
      If a matching entry is found, the bits will be removed. */
   *pServiceErrorMask |= (kFblDiagSubTableNotFound | kFblDiagSubfunctionNotFound | kFblDiagSubparamNotFound);

   /* Calculate comparison lengths */
   if ((pServiceInfo->serviceOptions & kFblDiagOptionServiceIsSubfunction) == kFblDiagOptionServiceIsSubfunction)
   {
      subFunctionLength = 1u;
      /* Sub-function may include suppress positive response bit */
      ChkSuppressPosRspMsgIndication(pbDiagData);
   }
   else
   {
      subFunctionLength = 0u;
   }
   subParamLength = pServiceInfo->subTableIdLength - subFunctionLength;

   /* Loop over all sub-table entries. While loop is terminated in case a table entry is found */
   while (((*pServiceErrorMask & kFblDiagSubTableNotFound) == kFblDiagSubTableNotFound) && (subTableIndex < pServiceInfo->subTableLength))
   {
      tempServiceErrorMask = kFblDiagServiceOk;
      subTableEntry = &pServiceInfo->serviceSubTable[subTableIndex];

      /* Check all sub table paramters */
      for (subTableIdIndex = 0u; subTableIdIndex < (subFunctionLength + subParamLength); subTableIdIndex++)
      {
         /* Compare table entries */
         if (subTableEntry->subTableParamTable[subTableIdIndex] != pbDiagData[kDiagLocFmtSubfunction + subTableIdIndex]) /* PRQA S 2986 */ /* MD_FblDiag_2986_OperationRedundant */
         {
            if (subTableIdIndex < subFunctionLength)
            {
               /* Sub-function not supported in this table entry */
               tempServiceErrorMask |= kFblDiagSubfunctionNotFound;
            }
            else
            {
               /* Sub-param not supported in this table entry */
               tempServiceErrorMask |= kFblDiagSubparamNotFound;
            }
         }
      }

      /* Do detail checks (for sub-functions and sub-parameters) */
      if ((tempServiceErrorMask & kFblDiagSubfunctionNotFound) != kFblDiagSubfunctionNotFound)
      {
         /* Matching sub-function found */
         *pServiceErrorMask &= FblInvert32Bit(kFblDiagSubfunctionNotFound);

         /* Sub-function has been found, do session check */
         if ((subTableEntry->serviceOptions & GetCurrentSession()) == 0u)
         {
            *pServiceErrorMask |= kFblDiagSubfuncSessionFailure;
            tempServiceErrorMask |= kFblDiagSubfuncSessionFailure;
         }
         /* Sub-function has been found, do security access check */
         if (((subTableEntry->serviceOptions & kFblDiagOptionSecuredService) == kFblDiagOptionSecuredService) && (!FblDiagGetSecurityUnlock()))
         {
            *pServiceErrorMask |= kFblDiagSubfuncSecAccessFailure;
            tempServiceErrorMask |= kFblDiagSubfuncSecAccessFailure;
         }
      }

      if ((tempServiceErrorMask & kFblDiagSubparamNotFound) != kFblDiagSubparamNotFound)
      {
         /* Matching sub-parameter found */
         *pServiceErrorMask &= FblInvert32Bit(kFblDiagSubparamNotFound);

         /* Sub-parameter has been found, do session check */
         if ((subTableEntry->serviceOptions & GetCurrentSession()) == 0u)
         {
            *pServiceErrorMask |= kFblDiagSubparamSessionFailure;
            tempServiceErrorMask |= kFblDiagSubparamSessionFailure;
         }
         /* Sub-parameter has been found, do security access check */
         if (((subTableEntry->serviceOptions & kFblDiagOptionSecuredService) == kFblDiagOptionSecuredService) && (!FblDiagGetSecurityUnlock()))
         {
            *pServiceErrorMask |= kFblDiagSubparamSecAccessFailure;
            tempServiceErrorMask |= kFblDiagSubparamSecAccessFailure;
         }
      }

      subTableIndex++;
      /* Store result to terminate loop */
      if ((tempServiceErrorMask & (kFblDiagSubfunctionNotFound | kFblDiagSubparamNotFound)) == 0u)
      {
         /* Only keep service level errors. Remove sub-table not found error */
         *pServiceErrorMask &= kFblDiagServiceLevelErrors;
         /* Add detected sub-table error bits. */
         *pServiceErrorMask |= tempServiceErrorMask;
      }
   }

   return subTableEntry;
}

/***********************************************************************************************************************
 *  FblDiagCheckSubTableEntry
 **********************************************************************************************************************/
/*! \brief       This function check the basic diagnostic states of the requested sub table entry
 *  \pre         Sub-table has been found for requested service
 *  \param[in]   pSubtableInfo Pointer to service descriptor
 *  \param[in]   pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]   diagReqDataLen Data length (without SID).
 *  \return      Error bit field
 **********************************************************************************************************************/
static vuint32 FblDiagCheckSubTableEntry(V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3* pSubtableInfo,
                                         vuint8 *pbDiagData,
                                         tCwDataLengthType diagReqDataLen)
{
   vuint32 result;

   /* Initialize varibles */
   result = kFblDiagServiceOk;

   /* Check if this sub-table entry is allowed functionally */
   if (FblDiagGetFunctionalRequest() && ((pSubtableInfo->serviceOptions & kFblDiagOptionFunctionalRequest) == 0u))
   {
      result |= kFblDiagSubNoFuncSupport;
   }
   /* Minimum length check based on table entry */
   if (diagReqDataLen < pSubtableInfo->serviceLength)
   {
      result |= kFblDiagSubMinLenFailure;
   }
   /* Complete length check. If a dynamic check is configured, use this check. */
   if (pSubtableInfo->serviceLengthCheck != (tFblDiagLengthCheck)0u)
   {
      if (pSubtableInfo->serviceLengthCheck(pbDiagData, diagReqDataLen) == kFblFailed)
      {
         result |= kFblDiagSubLenFailure;
      }
   }
   else
   {
      /* Match against length in table */
      if (pSubtableInfo->serviceLength != diagReqDataLen)
      {
         result |= kFblDiagSubLenFailure;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  CheckServiceTableEntry
 **********************************************************************************************************************/
/*! \brief       This function checks the basic diagnostic states of the requested service table entry
 *  \pre         Service has been found in service information table
 *  \param[in]   pServiceInfo Pointer to service descriptor
 *  \param[in]   pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]   diagReqDataLen Data length (without SID).
 *  \return      Error bit field
 **********************************************************************************************************************/
/* PRQA S 6010 1 */ /* MD_MSR_STPTH */
static vuint32 FblDiagCheckServiceTableEntry(V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3* pServiceInfo,
                                             vuint8 *pbDiagData,
                                             tCwDataLengthType diagReqDataLen)
{
   vuint32 result;

   /* Initialize variables */
   result = kFblDiagServiceOk;

   /* Check if a sub-table is present and if it can be processed */
   if (pServiceInfo->subTableLength == 0u)
   {
      result |= kFblDiagSubTableNotFound;
   }
   /* Check if the request length is not sufficient to check sub-table. If not, the sub-table cannot be identified. */
   if (diagReqDataLen < pServiceInfo->subTableIdLength)
   {
      result |= kFblDiagSubTableNotFound;
   }
   /* Check if this service is allowed functionally */
   if (FblDiagGetFunctionalRequest() && ((pServiceInfo->serviceOptions & kFblDiagOptionFunctionalRequest) == 0u))
   {
      result |= kFblDiagServiceNoFuncSupport;
   }
   /* Check session support */
   if ((pServiceInfo->serviceOptions & GetCurrentSession()) == 0u)
   {
      result |= kFblDiagServiceSessionFailure;
   }
   /* Minimum length check - done on service level */
   if (diagReqDataLen < pServiceInfo->serviceLength)
   {
      result |= kFblDiagServiceMinLenFailure;
   }
   /* Security Access on service level */
   if (((pServiceInfo->serviceOptions & kFblDiagOptionSecuredService) != 0u) && (!FblDiagGetSecurityUnlock()))
   {
      result |= kFblDiagServiceSecAccessFailure;
   }
   /* Complete length check. If a dynamic check is configured, use this check. */
   if (pServiceInfo->serviceLengthCheck != (tFblDiagLengthCheck)0u)
   {
      if (pServiceInfo->serviceLengthCheck(pbDiagData, diagReqDataLen) == kFblFailed)
      {
         result |= kFblDiagServiceLenFailure;
      }
   }
   else
   {
      /* Match against length in table (only if there is no sub-table) */
      if ((pServiceInfo->subTableLength == 0u) && (pServiceInfo->serviceLength != diagReqDataLen))
      {
         result |= kFblDiagServiceLenFailure;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagGetServiceInfo
 **********************************************************************************************************************/
/*! \brief       Find service table entry for received diagnostic service ID
 *  \param[in]   receivedServiceId UDS service ID of requested service
 *  \return      Pointer to service table. If no service has been found, return a NULL pointer
 **********************************************************************************************************************/
static V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3 * FblDiagGetServiceInfo(vuint8 receivedServiceId)
{
   V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3 * serviceTableEntry;
   vuintx serviceIndex;

   /* Initialize variables */
   serviceTableEntry = (V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3 *)V_NULL;

   /* Search for service information */
   for (serviceIndex = 0u; serviceIndex < kSizeOfServiceTable; serviceIndex++)
   {
      /* Check if service id matches id of current table entry */
      if (kFblDiagServiceTable[serviceIndex].serviceId == receivedServiceId)
      {
         /* Service ID matches */
         serviceTableEntry = &kFblDiagServiceTable[serviceIndex];
         break;
      }
   }

   return serviceTableEntry;
}

/***********************************************************************************************************************
 *  Callback functions from fbl_main
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagInitStartFromAppl
 **********************************************************************************************************************/
/*! \brief       Starts programming session if the Bootloader is called from the application.
 *  \details     This function prepares a programming session request and starts the diagnostic processing
 *               of this request after the real request has been received by the application software.
 **********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
void FblDiagInitStartFromAppl(void)
{
   FblCwSetRxBlock();

   if (FblDiagGetRespBufLockedByInit())
   {
      /* Diagnostic session control is processed */
      DiagBuffer[kDiagFmtServiceId] = kDiagSidDiagnosticSessionControl;

#if defined( FBL_DIAG_ENABLE_OEM_SPS_REQUEST )
      /* Use OEM function to prepare programming session request */
      FblDiagOemPrepareSpsRequest(DiagBuffer, &DiagDataLength);
#else
      /* Prepare DiagBuffer for DiagnosticSessionControl service */
      DiagBuffer[kDiagFmtSubparam] = kDiagSubProgrammingSession;
      DiagDataLength = kDiagRqlDiagnosticSessionControl;
#endif /* FBL_DIAG_ENABLE_OEM_SPS_REQUEST */

#if defined( FBL_DIAG_ENABLE_SPS_EXTENDED_SESSION )
      /* Set diagnostic session (extended session) */
      FblDiagSetExtendedSession();  /* PRQA S 3109 */ /* MD_FblDiag_3109 */
#endif /* FBL_DIAG_ENABLE_SPS_EXTENDED_SESSION */

      /* Activate tester present timer */
      ResetTesterTimeout();

      /* Prepare response message address */
      if (FblCwPrepareResponseAddress() == kFblOk)
      {
         /* Indicate prepared buffer */
         FblDiagRxStartIndication();
         FblDiagRxIndication(DiagBuffer, DiagDataLength + 1u);

         /* Preconditions already checked by application */
         FblDiagSetPreconditionsChecked();

         /* Dispatch prepared buffer */
         FblDiagStateTask();
      }
      else
      {  /* PRQA S 3201 */ /* MD_FblDiag_3201 */
         /* No address information found - cancel response */
         FblDiagConfirmation();
         FblCwResetRxBlock();
      }
   }
   else
   {
      FblCwResetRxBlock();
   }
}

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
/***********************************************************************************************************************
 *  FblDiagInitStartFromReset
 **********************************************************************************************************************/
/*! \brief       Process a reset request or default session request received before reset.
 *  \details     This function is called from FblInit() when the FBL is started from reset and the application is not
 *               valid or the application starts the FBL with a reprogramming request.
 *  \param[in]   resetRequestType RESET_RESPONSE_SDS_REQUIRED - Response for default session request
 *                                RESET_RESPONSE_ECURESET_REQUIRED - Response for ECU reset request
 *               No response otherwise
 **********************************************************************************************************************/
void FblDiagInitStartFromReset(vuint8 resetRequestType)
{
   FblCwSetRxBlock();

   if (FblDiagGetRespBufLockedByInit())
   {
      /* Set diagnostic session (default session) */
      FblDiagSetDefaultSession();   /* PRQA S 3109 */ /* MD_FblDiag_3109 */

      switch (resetRequestType)
      {
         case RESET_RESPONSE_SDS_REQUIRED:
         {
            /* Session control is processed */
            diagServiceCurrent = kDiagSidDiagnosticSessionControl;
# if defined( FBL_DIAG_ENABLE_OEM_SDS_RESPONSE )
            /* Use OEM function to prepare default session request response */
            FblDiagOemPrepareSdsResponse(DiagBuffer, &DiagDataLength);
# else
            /* Prepare DiagBuffer for DiagnosticSessionControl service */
            DiagBuffer[kDiagFmtSubparam] = kDiagSubDefaultSession;
            DiagDataLength = kDiagRqlDiagnosticSessionControl;

            /* Diagnostic session timing */
            DiagBuffer[kDiagFmtSubparam + 1u] = (vuint8)(kDiagSessionTimingP2 >> 8u);
            DiagBuffer[kDiagFmtSubparam + 2u] = (vuint8)(kDiagSessionTimingP2 & 0xFFu);
            DiagBuffer[kDiagFmtSubparam + 3u] = (vuint8)(kDiagSessionTimingP2Star >> 8u);
            DiagBuffer[kDiagFmtSubparam + 4u] = (vuint8)(kDiagSessionTimingP2Star & 0xFFu);
# endif /* FBL_DIAG_ENABLE_OEM_SDS_RESPONSE */

            /* Prepare response message address */
            if (FblCwPrepareResponseAddress() == kFblOk)
            {
# if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
               /* Configure service post handler to be called after response */
               FblDiagSetExecutePostHandler();
               fblDiagServicePostHandler = kFblDiagResponseSdsPostHandler;
# endif
               DiagProcessingDone(kDiagRslDiagnosticSessionControl);
               FblDiagResponseProcessor();
            }
            else
            {  /* PRQA S 3201 */ /* MD_FblDiag_3201 */
               /* No address information found - cancel response */
               FblDiagConfirmation();
               FblCwResetRxBlock();
            }

            break;
         }
         case RESET_RESPONSE_ECURESET_REQUIRED:
         {
            /* Reset request is processed */
            diagServiceCurrent = kDiagSidEcuReset;
# if defined( FBL_DIAG_ENABLE_OEM_RR_RESPONSE )
            /* Use OEM function to prepare default session request response */
            FblDiagOemPrepareRrResponse(DiagBuffer, &DiagDataLength);
# else
            /* Prepare DiagBuffer for EcuReset service */
            DiagBuffer[kDiagFmtSubparam] = kFblDiagSubReset;
            DiagDataLength = kDiagRqlEcuReset;
# endif /* FBL_DIAG_ENABLE_OEM_RR_RESPONSE */
            /* Prepare response message address */
            if (FblCwPrepareResponseAddress() == kFblOk)
            {
# if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
               /* Configure service post handler to be called after response */
               FblDiagSetExecutePostHandler();
               fblDiagServicePostHandler = kFblDiagResponseResetPostHandler;
# endif
               DiagProcessingDone(kDiagRslEcuReset);
               FblDiagResponseProcessor();
            }
            else
            {  /* PRQA S 3201 */ /* MD_FblDiag_3201 */
               /* No address information found - cancel response */
               FblDiagConfirmation();
               FblCwResetRxBlock();
            }

            break;
         }
         default:
         {
            /* No response or parameter not supported */
            FblDiagConfirmation();
            FblCwResetRxBlock();
            break;
         }
      }
   }
}
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */


#if defined( FBL_DIAG_ENABLE_CORE_OTA )
/***********************************************************************************************************************
 *  FblDiagInitStartFromOta
 **********************************************************************************************************************/
/*! \brief       Processes a OTA request received before reset.
 *  \details     This function prepares the response for the request which activated the OTA and restores the context.
 **********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
void FblDiagInitStartFromOta(void)
{
   FblCwSetRxBlock();

   if (FblDiagGetRespBufLockedByInit())
   {
      /* Preapre response buffer for OTA */
      FblDiagOemPrepareOtaResponse(DiagBuffer, &DiagDataLength);

      /* Activate tester present timer */
      ResetTesterTimeout();

      /* Prepare response message address */
      if (FblCwPrepareResponseAddress() == kFblOk)
      {
         /* Indicate prepared buffer */
         FblDiagRxStartIndication();
         FblDiagRxIndication(DiagBuffer, DiagDataLength + 1u);

         /* Preconditions already checked by application */
         FblDiagSetPreconditionsChecked();

         /* Dispatch prepared buffer */
         FblDiagStateTask();
      }
      else
      {
         /* Issue during response - cancel response */
         FblDiagConfirmation();
         FblCwResetRxBlock();
      }
   }
   else
   {
      FblCwResetRxBlock();
   }
}
#endif /* FBL_DIAG_ENABLE_CORE_OTA */
#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Start section to execute code from RAM */
#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Callback functions from Communication Wrapper
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  FblDiagRxStartIndication
 **********************************************************************************************************************/
/*! \brief       Data reception call-back function to start diagnostic service processing.
 *  \details     Indicates start of a frame to diagnostic module. Tester present timeout is stopped and
 *               the diagnostic layer is locked until the service is processed.
 **********************************************************************************************************************/
void FblDiagRxStartIndication(void)
{
   /* Halts the S3 timer while receiving a diagnostic message */
   StopTesterTimeout();

   /* Indicate an ongoing service processing */
   FblDiagSetServiceInProgress();

   DiagClrError();

#if defined( FBL_DIAG_ENABLE_OEM_SERVICENOTIFICATION )
   /* Trigger a callback as soon as a new service is received  */
   FblDiagOemServiceReceptionNotification(kFblDiagServiceNotificationStart);
#endif
   /* Reset handler functions */
#if defined( FBL_DIAG_ENABLE_SERVICE_PREHANDLER )
   fblDiagServicePreHandler = (tFblDiagPreHandler)0u;
#endif /* FBL_DIAG_ENABLE_SERVICE_PREHANDLER */
   fblDiagServiceMainHandler = (tFblDiagMainHandler)0u;
   fblDiagServiceNrcHandler = (tFblDiagNrcHandler)0u;
#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
   fblDiagServicePostHandler = FblDiagDefaultPostHandler;
#endif /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */
   serviceInfo = (V_MEMROM1 tFblDiagServiceTable V_MEMROM2 V_MEMROM3 *) V_NULL;
   subServiceInfo = (V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 V_MEMROM3 *) V_NULL;
}

/***********************************************************************************************************************
 *  FblDiagRxIndication
 **********************************************************************************************************************/
/*! \brief       Data reception call-back function to start diagnostic service processing.
 *  \details     Valid TesterPresent requests will simply start the S3 timer and will not be processed.
 *  \pre         TP reception successful
 *  \param[in]   pbDiagBuffer Pointer to diagnostic buffer
 *  \param[in]   rxDataLength number of bytes to be received
 **********************************************************************************************************************/
void FblDiagRxIndication(vuint8* pbDiagBuffer, tCwDataLengthType rxDataLength)
{
   /* Initialize diagBuffer and data length */
   DiagBuffer = pbDiagBuffer;
   DiagDataLength = rxDataLength - 1u;

   /* Reset P2 timer (initial timing) */
#if defined( FBL_DIAG_ENABLE_DYNAMIC_P2_HANDLING )
   SetP2Timer(fblDiagTimeP2Max);
#else
   SetP2Timer((vuint16)kFblDiagTimeP2);
#endif /* FBL_DIAG_ENABLE_DYNAMIC_P2_HANDLING */

   /* Handle functional TesterPresent request here */
   if (    (kDiagSidTesterPresent == DiagBuffer[kDiagFmtServiceId])
        && (kDiagSuppressPosRspMsgIndicationBit == DiagBuffer[kDiagFmtSubparam])
        && (kDiagRqlTesterPresent == DiagDataLength)
        && FblDiagGetFunctionalRequest()
      )
   {
#if defined( FBL_DIAG_ENABLE_SERVICE_POSTHANDLER )
      /* Configure service post handler to be called after response */
      FblDiagSetExecutePostHandler();
      fblDiagServicePostHandler = fblDiagServiceTesterPresentPostHandler;
#endif /* FBL_DIAG_ENABLE_SERVICE_POSTHANDLER */

      /* service processing is not in progress, release the diagBuffer */
      FblDiagConfirmation();
      FblCwResetRxBlock();
   }
   else
   {
      /* Set diagnostic service indication to start service processing */
      diagResponseFlag = kDiagResponseRequested;
      diagServiceCurrent = DiagBuffer[kDiagFmtServiceId];

#if defined( FBL_MEM_ENABLE_PIPELINING )
      if (FblMemTaskIsPending())
      {
         FblMemRxNotification();
      }
#endif
   }

#if defined( FBL_ENABLE_SLEEPMODE )
   /* Request received - reload sleep counter */
   FblSleepCounterReload();
#endif
}

/***********************************************************************************************************************
 *  FblDiagRxGetPhysBuffer
 **********************************************************************************************************************/
/*! \brief       Diagnostic buffer management function for physical requests.
 *  \param[in]   rxDataLength Number of bytes to be received
 *  \return      Pointer to diagnostic buffer
 **********************************************************************************************************************/
vuint8* FblDiagRxGetPhysBuffer(tCwDataLengthType rxDataLength)
{
   vuint8* result;

   /* Initialize variables */
   result = (vuint8*)V_NULL;

   /* Check request length and if buffer is free */
   if ((rxDataLength > 0u )
        && (FBL_DIAG_BUFFER_LENGTH >= rxDataLength)
        && (!FblDiagGetBufferLocked())
      )
   {
      /* Initialize state variables */
      FblDiagClrFunctionalRequest();

      /* Lock buffer  */
      FblDiagSetBufferLocked();

      /* Return diagnostic buffer */
      result = DiagBuffer;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRxGetFuncBuffer
 **********************************************************************************************************************/
/*! \brief       Diagnostic buffer management function for functional requests.
 *  \param[in]   rxDataLength Number of bytes to be received
 *  \return      Pointer to diagnostic buffer
 **********************************************************************************************************************/
vuint8* FblDiagRxGetFuncBuffer(tCwDataLengthType rxDataLength)
{
   /* Process functional request like physical request */
   vuint8* funcBuffer = FblDiagRxGetPhysBuffer(rxDataLength);

   /* Set functional request indication */
   if ((void*)V_NULL != funcBuffer)
   {
      FblDiagSetFunctionalRequest();
   }

   return funcBuffer;
}

/***********************************************************************************************************************
 *  FblDiagRxErrorIndication
 **********************************************************************************************************************/
/*! \brief       Indicates that an error has occurred during reception.
 *  \details     According to ISO-14229, now the S3 timer must be restarted.
 *  \pre         TP must been initialized
 **********************************************************************************************************************/
void FblDiagRxErrorIndication(void)
{
   /* Clear all other flags for service management */
   FblDiagConfirmation();
}

/***********************************************************************************************************************
 *  FblDiagTxErrorIndication
 **********************************************************************************************************************/
/*! \brief       Indicates that an error has occurred during transmission.
 *  \details     According to ISO-14229, now the S3 timer must be restarted.
 *  \pre         TP must been initialized
 *  \param[in]   cwMsgType Message type of indication, if it is a RCR-RP or normal message.
 *               The parameter type is defined in the CW-layer.
 **********************************************************************************************************************/
void FblDiagTxErrorIndication(vuint8 cwMsgType)
{
   /* Do not reset states for RCR-RP confirmation */
   if (cwMsgType != kFblCwMsgTypeRcrRp)
   {
      /* Clear all other flags for service management */
      FblDiagConfirmation();
   }
}

/***********************************************************************************************************************
 *  FblDiagTxConfirmation
 **********************************************************************************************************************/
/*! \brief       TP transmission call-back function.
 *  \pre         TP transmission successful
 *  \param[in]   cwMsgType Message type of indication, if it is a RCR-RP or normal message.
 *               The parameter type is defined in the CW-layer.
 **********************************************************************************************************************/
void FblDiagTxConfirmation(vuint8 cwMsgType)
{
   /* Do not reset states for RCR-RP confirmation */
   if (cwMsgType != kFblCwMsgTypeRcrRp)
   {
      /* Clear all other flags for service management */
      FblDiagConfirmation();
   }

   /* Diag wants to reset FBL after sending an RCR-RP */
   if (FblDiagGetWaitEcuReset())
   {
      FblDiagSetResetMsgConfirmed();
   }
}

#if defined( FBL_CW_ENABLE_DECLINED_REQUESTS )
/***********************************************************************************************************************
 *  FblDiagRxDeclineIndication
 **********************************************************************************************************************/
/*! \brief       Data reception callback function to process received data on additional connection
 *  \details     Valid TesterPresent requests will simply start the S3 timer and will not be processed.
 *  \pre         TP reception on additional tester channel successful
 *  \param[in]   pbDiagBuffer Pointer to diagnostic buffer
 *  \param[in]   rxDataLength number of bytes to be received
 *  \param[in]   connectionIndex Index of additional connection
 **********************************************************************************************************************/
void FblDiagRxDeclineIndication(vuint8* pbDiagBuffer, tCwDataLengthType rxDataLength, vuint8 connectionIndex)
{
   tCwDataLengthType messageLength;

# if defined( FBL_DIAG_DISABLE_CORE_DECLINED_REQUESTS )
   messageLength = rxDataLength;
   FblDiagOem_ProcessDeclineRequest((V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *)pbDiagBuffer, (V_MEMRAM1 tCwDataLengthType V_MEMRAM2 V_MEMRAM3 *)&messageLength);
# else
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)rxDataLength; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#  endif
   /* Store service ID */
   pbDiagBuffer[kDiagFmtSubparam] = pbDiagBuffer[kDiagFmtServiceId];

   /* Set negative response */
   pbDiagBuffer[kDiagFmtServiceId] = kDiagRidNegativeResponse;
   pbDiagBuffer[kDiagFmtNegResponse] = kDiagNrcBusyRepeatRequest;

   /* Set length of negative response */
   messageLength = 3u;
# endif /* !FBL_DIAG_DISABLE_CORE_DECLINED_REQUESTS */

   FblCwPduTransmitDeclinedRequest(pbDiagBuffer, messageLength, connectionIndex);
}

/***********************************************************************************************************************
 *  FblDiagRxGetDeclineBuffer
 **********************************************************************************************************************/
/*! \brief       Diagnostic buffer management function additional requests.
 *  \details     This function is called to provide a buffer which can be used to process requests on additional
 *               diagnostic connections.
 *  \param[in]   rxDataLength Number of bytes to be received
 *  \param[in]   connectionIndex Index of additional connection. Connection index is > 1, 0 is used for main connection.
 *  \return      Pointer to diagnostic buffer
 **********************************************************************************************************************/
vuint8* FblDiagRxGetDeclineBuffer(tCwDataLengthType rxDataLength, vuint8 connectionIndex)
{
   vuint8* result;

   /* Initialize variables */
   result = (vuint8*)V_NULL;

   if ((connectionIndex > 0u) &&
       (rxDataLength > 0u) &&
       (rxDataLength <= FBL_DIAG_DECLINE_BUFFER_LENGTH) &&
       (additionalDiagBufferUsed[connectionIndex - 1u] == kFblFailed)
      )
   {
      result = &additionalDiagnosticBuffer[connectionIndex - 1u][0u];
      additionalDiagBufferUsed[connectionIndex - 1u] = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagDeclineErrorIndication
 **********************************************************************************************************************/
/*! \brief       Indicates that an error has occurred during reception
 *  \param[in]   connectionIndex Connection index of additional connection. Always > 1
 **********************************************************************************************************************/
void FblDiagDeclineErrorIndication(vuint8 connectionIndex)
{
   /* Release locked buffer in case of error */
   additionalDiagBufferUsed[connectionIndex - 1u] = kFblFailed;
}

/***********************************************************************************************************************
 *  FblDiagDeclineTxConfirmation
 **********************************************************************************************************************/
/*! \brief       Indicates that a response has been succesfully sent
 *  \param[in]   connectionIndex Connection index of additional connection. Always > 1
 **********************************************************************************************************************/
void FblDiagDeclineTxConfirmation(vuint8 connectionIndex)
{
   /* Release locked buffer */
   additionalDiagBufferUsed[connectionIndex - 1u] = kFblFailed;
}

#endif /* FBL_CW_ENABLE_DECLINED_REQUESTS */

#if  defined( FBL_DIAG_ENABLE_CORE_GETLASTERASEDBLK )
/***********************************************************************************************************************
 *  FblDiagGetLastErasedBlock
 **********************************************************************************************************************/
/*! \brief       Get block number of last erased block
 *  \return      Number of last erased block
 **********************************************************************************************************************/
tFblLbtBlockNr FblDiagGetLastErasedBlock(void)
{
   return lastErasedBlock;
}

/***********************************************************************************************************************
 *  FblDiagSetLastErasedBlock
 **********************************************************************************************************************/
/*! \brief       Set block number of last erased block
 *  \param[in]   blockNr Number of last erased block
 **********************************************************************************************************************/
void FblDiagSetLastErasedBlock(tFblLbtBlockNr blockNr)
{
   lastErasedBlock = blockNr;
}
#endif /* FBL_DIAG_ENABLE_CORE_GETLASTERASEDBLK */

/* End section to execute code from RAM */
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Callback functions from FblLib_Mem
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if defined( FBL_DIAG_ENABLE_CORE_PREWRITE )
 /***********************************************************************************************************************
 *  FblDiagMemPreWrite
 **********************************************************************************************************************/
/*! \brief       Function performs actions before FblLibMem calls the memdriver write function.
 *  \return      kFblOk if PreWrite operations are successful, kFblFailed if PreWrite operations failed
 **********************************************************************************************************************/
tFblResult FblDiagMemPreWrite(void)
{
   FblCwSetOfflineMode();

   return kFblOk;
}
#endif /* FBL_DIAG_ENABLE_CORE_PREWRITE  */

#if defined( FBL_DIAG_ENABLE_CORE_POSTWRITE )
/***********************************************************************************************************************
 *  FblDiagMemPostWrite
 **********************************************************************************************************************/
/*! \brief       Checks if message is the platform message or not
 *  \return      kFblOk if post-write operations are successful, kFblFailed if post-write operations failed
 **********************************************************************************************************************/
tFblResult FblDiagMemPostWrite(void)
{
   FblCwSetOnlineMode();

   return kFblOk;
}
#endif /* FBL_DIAG_ENABLE_CORE_POSTWRITE  */
#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblDiagCore_2880_2992_2996:
      Reason:     QAC does not interpret this correctly. The compared data is read from another component which is not
                   available in this MISRA configuration.
      Risk:       No risk.
      Prevention: No prevention required.
 */

/***********************************************************************************************************************
 *  END OF FILE: FBL_DIAG_CORE.C
 **********************************************************************************************************************/
