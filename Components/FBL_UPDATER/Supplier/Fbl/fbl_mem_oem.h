/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        OEM dependent configuration for FblLib_Mem
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  TEMPLATE REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2012-03-23  visjhg  -                Initial release
 *  01.00.01   2012-03-26  visjhg  -                Additional comments
 *  01.01.00   2012-04-05  visjhg  -                Changes after code review
 *  01.02.00   2012-04-27  visjhg  -                Updated type casts in macros using ternary operator
 *  01.04.00   2013-02-01  visach  ESCAN00062919    Adapted comments to use Doxygen
 *                         visach  -                Correct macro __ApplFblMemDriverReady
 *                         visjhg  ESCAN00064292    Added pre and post handlers for erase routine
 *                         visjhg  ESCAN00064296    Renamed default preamble length define
 *                         visjhg  ESCAN00064301    Split verify functions for RAM and ROM verification
 *                         visjhg  ESCAN00064333    Differentiate watchdog trigger w/ and w/o status
 *                         visjhg  ESCAN00064334    Added interface to remap error codes to OEM dependent value
 *                         visjhg  -                Added additional error codes for new functionality
 *                         visjhg  ESCAN00064720    Replaced __ApplFblMemCheckDfi by __ApplFblMemIsDataProcessingRequired
 *  01.05.00   2013-04-10  visjhg  ESCAN00066379    Added interface version compatibility check
 *                         visjhg  ESCAN00066377    Added additional error codes for new functionality
 *  01.06.00   2013-07-22  visjhg  ESCAN00067433    Updated interface version (added FblMemDeinit)
 *                         visjhg  ESCAN00069161    Updated interface version (added pipelined verification)
 *                                                   Changed verification error codes
 *  01.07.00   2013-08-16  visjhg  ESCAN00069803    Updated interface version (enable/disable verification at run-time)
 *                         visjhg  -                Corrected name of parameter type overwrite
 *  02.00.00   2013-12-12  visjhg  ESCAN00072568    Updated interface version (initialize verification in segment start)
 *                                                   Error / status for BlockStartVerifyInit replaced by SegmentStartVerifyInit
 *                         visjhg  ESCAN00072569    Raised major version to match API version
 *  02.01.00   2014-03-12  visjhg  ESCAN00073504    Corrected overwrite macro names for verification functions
 *  03.00.00   2015-03-03  visjhg  ESCAN00076591    Added support for external stream output
 *                                                   Added __ApplFblMemIsStreamOutputRequired
 *                                                   Added additional error codes
 *                                                   Updated interface version
 *                         visjhg  ESCAN00081493    Added __ApplFblMemIsPipelinedProgrammingDisabled
 *  03.01.00   2015-04-23  visjhg  ESCAN00082606    Added __ApplFblMemReportProgress
 *  03.01.03   2015-06-15  visjhg  ESCAN00083392    Added FBL_MEM_ENABLE_VERIFY_OUTPUT_FULL_BLOCK_LENGTH
 *                                                  Added SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH check
 *                                                  Updated interface version
 *  03.02.00   2015-07-21  visjhg  ESCAN00084102    Updated interface version (parameter type structure for stream processing)
 *  04.00.00   2015-09-17  visjhg  ESCAN00085249    Updated interface version (explicit parameters for processed verification)
 *                         visjhg  ESCAN00085250    Run-time decision whether address and length info is included in verification
 *                                                  Added __ApplFblMemVerifyInputIsAddressAndLengthIncluded,
 *                                                   __ApplFblMemVerifyProcessedIsAddressAndLengthIncluded and
 *                                                   __ApplFblMemVerifyPipelinedIsAddressAndLengthIncluded
 *                         visjhg  ESCAN00085251    Pass external segment info to __ApplFblMemIsPipelinedProgrammingDisabled
 *  04.01.00   2016-04-01  visjhg  ESCAN00087997    Added __ApplFblMemEnterCriticalSection and __ApplFblMemLeaveCriticalSection
 *                                                  Updated interface version
 *  04.02.01   2017-05-31  visjhg  -                Removed deprecated SEC_VER_DISABLE_LENGTH_AND_ADDRESS_INPUT
 *                                                  Updated interface version
 *  04.03.00   2017-07-06  visjhg  ESCAN00095774    Added FblMemFlushInputData
 *                                                  Updated interface version
 *  04.04.00   2018-08-22  visjhg  ESCAN00100482    Added hook __ApplFblMemConditionCheck
 *                                                  Updated interface version
 *  04.04.01   2018-09-25  visjhg  ESCAN00100850    Matching preamble length for MCMP download use-case
 *                                                  Updated interface version
 *  04.05.00   2018-11-30  visjhg  ESCAN00101500    Added custom error codes (typically used by __ApplFblMemConditionCheck)
 *                                                  Updated interface version
 *  04.05.02   2019-08-20  vistbe  ESCAN00103967    Updated interface version
 *  04.06.00   2019-10-29  vistmo  FBL-813          Migration to MISRA 2012
 *  04.07.00   2021-04-12  vishor  FBL-2187         No changes
 *  04.08.00   2021-06-11  visjdn  FBL-3560         No changes
 *  04.09.00   2021-07-09  vishor  FBL-3442         Updated MISRA justifications
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  10.00.00   2020-10-14  viscb   FBL-2177         DRECU2020-01 adaptions, input verification and encrypted download
 *  10.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *  10.01.01   2021-02-02  viscb   ESCAN00108445    QM release
 *  10.01.02   2021-04-21  viscb   ESCAN00108537    No changes
 *                                 ESCAN00108093    No changes
 *                                 ESCAN00108139    No changes
 *                                 FBL-3360         No changes
 *  10.01.03   2021-05-28  viscb   ESCAN00109398    No changes
 *                                 ESCAN00109400    No changes
 *  10.01.04   2021-06.07  viscb   ESCAN00109435    No changes
 *                                 ESCAN00109437    No changes
 *  10.02.00   2021-07-09  vishor  FBL-3567         No changes
 *                                 ESCAN00107081    No changes
 *  10.02.01   2021-08-26  visjdn  ESCAN00109069    No changes
 *  10.02.02   2021-10-27  visrie  ESCAN00109153    No changes
 *  10.03.00   2022-03-15  vishor  FBL-4621         No changes
 *                                 ESCAN00110728    No changes
 *                                 ESCAN00110898    No changes
 *                                 ESCAN00110960    No changes
 *                                 ESCAN00111146    No changes
 *                                 ESCAN00111396    No changes
 *  10.04.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00110486    No changes
 *  10.04.01   2022-06-27  vismix  ESCAN00112173    No changes
 *                                 ESCAN00112160    No changes
 *  10.04.02   2022-08-26  vismix  FBL-5754         No changes
 *                                 ESCAN00112447    No changes
 *                                 ESCAN00112459    No changes
 *  10.04.03   2023-01-09  vismix  ESCAN00112744    No changes
 *                                 ESCAN00113013    No changes
 *                                 ESCAN00113078    No changes
 **********************************************************************************************************************/

#ifndef FBL_MEM_OEM_H
#define FBL_MEM_OEM_H

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* PRQA S 3453 TAG_FblMemOem_3453_1 */ /* MD_MSR_FctLikeMacro */
/* PRQA S 0602, 0603 TAG_FblMemOem_0602_0603_1 */ /* MD_FblMemOem_0602_0603 */

/*-- Version information ----------------------------------------------------*/

/* Reference interface version */
/** Major interface version identifies incompatible changes */
#define FBL_MEM_API_REFERENCE_VERSION_MAJOR     0x04u
/** Minor interface version identifies backward compatible changes */
#define FBL_MEM_API_REFERENCE_VERSION_MINOR     0x07u
/** Release interface version identifies cosmetic changes */
#define FBL_MEM_API_REFERENCE_VERSION_RELEASE   0x00u

/*-- Buffer configuration ---------------------------------------------------*/

/** Input buffer size */
#define FBL_MEM_BUFFER_SIZE               FBL_DIAG_BUFFER_LENGTH

/** Preamble length for UDS download */
#define FBL_MEM_PREAMBLE_LENGTH_UDS       2u
/** Preamble length for MCMP download */
#define FBL_MEM_PREAMBLE_LENGTH_MCMP      1u

/** Preamble length of default source */
#if defined( FBL_MEM_SOURCE_PREAMBLE_LENGTH )
/* Allow override for non-standard use-cases */
#else
# if defined( MCMP_MEM_MODE_DYNAMIC )
/* Mixed download over UDS and MCMP
   UDS is default source */
#  define FBL_MEM_SOURCE_PREAMBLE_LENGTH   FBL_MEM_PREAMBLE_LENGTH_UDS
# elif defined( MCMP_MEM_MODE_SLAVE )
/* MCMP-only download */
#  define FBL_MEM_SOURCE_PREAMBLE_LENGTH   FBL_MEM_PREAMBLE_LENGTH_MCMP
# else
/* UDS-only download */
#  define FBL_MEM_SOURCE_PREAMBLE_LENGTH   FBL_MEM_PREAMBLE_LENGTH_UDS
# endif /* MCMP_MEM_MODE_ */
#endif /* FBL_MEM_SOURCE_PREAMBLE_LENGTH */

/** Length of default preamble */
#define FBL_MEM_DEFAULT_PREAMBLE_LENGTH   FBL_MEM_SOURCE_PREAMBLE_LENGTH
/** Maximum preamble length */
#define FBL_MEM_MAX_PREAMBLE_LENGTH       FBL_MEM_SOURCE_PREAMBLE_LENGTH

#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
/* Allow override in configuration */
# if defined( __ApplFblMemIsDataProcessingRequired )
# else
/** Check whether specific data format identifier implies the need for data processing */
#  define __ApplFblMemIsDataProcessingRequired(dataFormat) \
   ((tFblResult)((kDiagSubNoDataProcessing == (dataFormat)) ? kFblFailed : kFblOk))
# endif /* __ApplFblMemIsDataProcessingRequired */
/* Allow override in configuration */
# if defined( __ApplFblMemIsStreamOutputRequired )
# else
/** Check whether specific data format identifier implies the need for stream output */
#  define __ApplFblMemIsStreamOutputRequired(dataFormat) \
   (FblDiagGetDeltaDownload() ? kFblOk : kFblFailed)
# endif /* __ApplFblMemIsStreamOutputRequired */
# if defined( FBL_MEM_ENABLE_SELECTIVE_PIPELINED_PROGRAMMING )
/* Allow override in configuration */
#  if defined( __ApplFblMemIsPipelinedProgrammingDisabled )
#  else
/** Check whether pipelined programming has to be disabled for specific block / segment / data format identifier */
/* Disables pipelining for stream output (e.g. delta download) */
#   define __ApplFblMemIsPipelinedProgrammingDisabled(pBlockInfo, pSegmentInfo) \
      ((tFblResult)((kFblOk == __ApplFblMemIsStreamOutputRequired((pSegmentInfo)->input.dataFormat)) ?  kFblOk : kFblFailed))
#  endif /* __ApplFblMemIsPipelinedProgrammingDisabled */
# endif /* FBL_MEM_ENABLE_SELECTIVE_PIPELINED_PROGRAMMING */

#else
/** Check whether specific data format identifier implies the need for data processing */
# define __ApplFblMemIsDataProcessingRequired(dataFormat) \
   ((tFblResult)((kDiagSubNoDataProcessing == (dataFormat)) ? kFblFailed : kFblOk))
# define __ApplFblMemIsStreamOutputRequired(dataFormat)      kFblFailed

#endif /* FBL_MEM_ENABLE_STREAM_OUTPUT */

/*-- Verification -----------------------------------------------------------*/
#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
# define FBL_MEM_ENABLE_SEGMENT_HANDLING
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

/*-- On-the-fly verification ------------------------------------------------*/
#if defined( SEC_ENABLE_VERIFICATION_ADDRESS_LENGTH )
/** Include address and length info in on-the-fly calculation */
# define FBL_MEM_ENABLE_VERIFY_INPUT_ADDRESS_LENGTH
# define FBL_MEM_ENABLE_VERIFY_PROCESSED_ADDRESS_LENGTH
#endif
/** Calculate CRC total over complete block
    Otherwise start of block until last address of last segment is covered */
#define FBL_MEM_ENABLE_VERIFY_OUTPUT_FULL_BLOCK_LENGTH

/** Size of temporary verification result buffer */
#define FBL_MEM_SIG_RESULT_BUFFER_SIZE                   kDiagSigBufLength

/*-- Memory driver ----------------------------------------------------------*/
/*
   Check conditions just before and after executing memory operations
   Return kFblMemStatus_Ok when conditions are fulfilled or set custom return code when not
   E.g. check for programming voltage and set NRC 0x92 (kDiagNrcVoltageTooHigh) or 0x93 (kDiagNrcVoltageTooLow)
   Remove macro if not applicable
*/
#define __ApplFblMemConditionCheck()               ApplFblMemConditionCheck()

/*
   Perform actions directly before and after memory driver write
*/
#define __ApplFblMemPreWrite()                     FblDiagMemPreWrite()
#define __ApplFblMemPostWrite()                    FblDiagMemPostWrite()
/*
   Perform actions directly before and after memory driver erase
*/
#define __ApplFblMemPreErase()                     FblDiagMemPreErase()
#define __ApplFblMemPostErase()                    FblDiagMemPostErase()

/*-- Watchdog ---------------------------------------------------------------*/
/* Default return code */
#define FBL_MEM_WD_TRIGGER_DEFAULT                 (FBL_NO_TRIGGER)
/*
   Overwrite status type returned by watchdog trigger function
*/
#define FBL_MEM_TRIGGER_STATUS_OVERWRITE           vuint8
/*
   Default watchdog trigger
*/
#define __ApplFblMemWdTrigger()                    FblLookForWatchdog()
/*
   Watchdog trigger including adaptive generation of RCR-RP
*/
#define __ApplFblMemAdaptiveRcrRp()                FblRealTimeSupport()
/*
   Forced generation of RCR-RP (hint: use kForceSendRpIfNotInProgress if available)
*/
#define __ApplFblMemForcedRcrRp()                  DiagExRCRResponsePending(kForceSendRpIfNotInProgress)

/* Pass watchdog trigger with extended status result to data processing */
#define FBL_MEM_ENABLE_EXT_TRIGGER_DATA_PROC
/* Pass watchdog trigger with extended status result to signature verification over input data */
#define FBL_MEM_ENABLE_EXT_TRIGGER_INPUT_VERIFY
/* Pass watchdog trigger with extended status result to signature verification over output data */
#define FBL_MEM_ENABLE_EXT_TRIGGER_OUTPUT_VERIFY
/*-- Critical sections ------------------------------------------------------*/
/* Allow override in configuration */
#if defined( __ApplFblMemEnterCriticalSection )
#else
/** Enter critical section */
#  define __ApplFblMemEnterCriticalSection()
#endif /* __ApplFblMemEnterCriticalSection */

/* Allow override in configuration */
#if defined( __ApplFblMemLeaveCriticalSection )
#else
/** Leave critical section */
#  define __ApplFblMemLeaveCriticalSection()
#endif /* __ApplFblMemLeaveCriticalSection */

/*-- Error handling ---------------------------------------------------------*/
/** Overwrite error codes by OEM dependent value */
#define FBL_MEM_ENABLE_STATUS_OVERWRITE
/* Enable interface to remap error codes to OEM dependent value */
#define FBL_MEM_DISABLE_STATUS_REMAPPING
/* OEM dependent status type */
#define FBL_MEM_STATUS_TYPE                           vuint8

#if defined( FBL_MEM_ENABLE_STATUS_OVERWRITE ) || \
    defined( FBL_MEM_ENABLE_STATUS_REMAPPING )
/* Default */
# define FBL_MEM_STATUS_Ok                            kDiagErrorNone
# define FBL_MEM_STATUS_Failed                        kDiagNrcConditionsNotCorrect
/* BlockErase indication */
# define FBL_MEM_STATUS_BlockEraseSequence            kDiagNrcRequestSequenceError
/* BlockStart indication */
# define FBL_MEM_STATUS_BlockStartSequence            kDiagNrcRequestOutOfRange
# define FBL_MEM_STATUS_BlockStartParam               kDiagNrcConditionsNotCorrect
/* BlockEnd indication */
# define FBL_MEM_STATUS_BlockEndSequence              kDiagNrcRequestSequenceError
# define FBL_MEM_STATUS_BlockEndVerifyFinalize        kDiagNrcGeneralProgrammingFailure
/* BlockVerify */
# define FBL_MEM_STATUS_BlockVerifySequence           kDiagNrcRequestSequenceError
# define FBL_MEM_STATUS_BlockVerifyInputVerify        kDiagNrcGeneralReject
# define FBL_MEM_STATUS_BlockVerifyProcessedVerify    kDiagNrcGeneralReject
# define FBL_MEM_STATUS_BlockVerifyPipeVerify         kDiagNrcGeneralReject
# define FBL_MEM_STATUS_BlockVerifyOutputVerify       kDiagNrcGeneralReject
/* SegmentStart indication */
# define FBL_MEM_STATUS_SegmentStartSequence          kDiagNrcRequestOutOfRange
# define FBL_MEM_STATUS_SegmentStartDataProcInit      kDiagNrcRequestOutOfRange
# define FBL_MEM_STATUS_SegmentStartStreamOutInit     kDiagNrcUploadDownloadNotAccepted
# define FBL_MEM_STATUS_SegmentStartVerifyInit        kDiagNrcConditionsNotCorrect
# define FBL_MEM_STATUS_SegmentStartVerifyCompute     kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_SegmentStartSegmentCount      kDiagNrcRequestOutOfRange
/* SegmentEnd indication */
# define FBL_MEM_STATUS_SegmentEndSequence            kDiagNrcRequestSequenceError
# define FBL_MEM_STATUS_SegmentEndInsufficientData    kDiagNrcRequestSequenceError
# define FBL_MEM_STATUS_SegmentEndPost                kDiagNrcGeneralProgrammingFailure
/* Data indication */
# define FBL_MEM_STATUS_DataIndSequence               kDiagNrcRequestSequenceError
# define FBL_MEM_STATUS_DataIndParam                  kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_DataIndOverflow               kDiagNrcTransferDataSuspended
/* Data processing */
# define FBL_MEM_STATUS_DataProc                      kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_DataProcConsume               kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_DataProcDeinit                kDiagNrcConditionsNotCorrect
/* Stream output */
# define FBL_MEM_STATUS_StreamOutput                  kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_StreamOutputConsume           kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_StreamOutputOverflow          kDiagNrcTransferDataSuspended
# define FBL_MEM_STATUS_StreamOutputDeinit            kDiagNrcConditionsNotCorrect
/* Memory driver */
# define FBL_MEM_STATUS_DriverResumeWrite             kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_DriverWrite                   kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_DriverErase                   kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_DriverRemainder               kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_DriverSuspendWrite            kDiagNrcGeneralProgrammingFailure
/* Programming operation */
# define FBL_MEM_STATUS_ProgramOverflow               kDiagNrcTransferDataSuspended
# define FBL_MEM_STATUS_ProgramOutsideFbt             kDiagNrcTransferDataSuspended
# define FBL_MEM_STATUS_ProgramUnalignedAddress       kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_ProgramDriverNotReady         kDiagNrcRequestSequenceError
# define FBL_MEM_STATUS_ProgramPreWrite               kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_ProgramPostWrite              kDiagNrcGeneralProgrammingFailure
/* Erase operation */
# define FBL_MEM_STATUS_EraseOutsideFbt               kDiagNrcRequestOutOfRange
# define FBL_MEM_STATUS_EraseDriverNotReady           kDiagNrcConditionsNotCorrect
# define FBL_MEM_STATUS_ErasePreErase                 kDiagNrcConditionsNotCorrect
# define FBL_MEM_STATUS_ErasePostErase                kDiagNrcConditionsNotCorrect
/* On-the-fly verification */
# define FBL_MEM_STATUS_VerifyCompute                 kDiagNrcGeneralProgrammingFailure
# define FBL_MEM_STATUS_VerifyFinalize                kDiagNrcGeneralProgrammingFailure
/* Pass-through */
# define FBL_MEM_STATUS_PassThroughLocal              kDiagNrcConditionsNotCorrect
# define FBL_MEM_STATUS_PassThroughRemote             kDiagNrcConditionsNotCorrect
/* Condition check for memory operations */
/* Unique codes for voltage and temperature states */
/* States are not mapped to NRCs because they are used for routine status information */
# define FBL_MEM_STATUS_VoltageTooHigh                0x32u
# define FBL_MEM_STATUS_VoltageTooLow                 0x33u
# define FBL_MEM_STATUS_TemperatureTooHigh            0x34u
# define FBL_MEM_STATUS_TemperatureTooLow             0x35u

# define FBL_MEM_STATUS_ConditionCheck0
# define FBL_MEM_STATUS_ConditionCheck1
# define FBL_MEM_STATUS_ConditionCheck2
# define FBL_MEM_STATUS_ConditionCheck3

#endif /* FBL_MEM_ENABLE_STATUS_OVERWRITE || FBL_MEM_ENABLE_STATUS_REMAPPING */

#define ConditionCheck0 VoltageTooHigh
#define ConditionCheck1 VoltageTooLow
#define ConditionCheck2 TemperatureTooHigh
#define ConditionCheck3 TemperatureTooLow

#if defined( FBL_ENABLE_DEBUG_STATUS )
/** Enable extended error status handling */
# define FBL_MEM_ENABLE_EXT_STATUS

/* Default */
# define FBL_MEM_EXT_STATUS_Ok(status)
# define FBL_MEM_EXT_STATUS_Failed(status)
/* BlockErase indication */
# define FBL_MEM_EXT_STATUS_BlockEraseSequence(status)
/* BlockStart indication */
# define FBL_MEM_EXT_STATUS_BlockStartSequence(status)
# define FBL_MEM_EXT_STATUS_BlockStartParam(status)
/* BlockEnd indication */
# define FBL_MEM_EXT_STATUS_BlockEndSequence(status)
# define FBL_MEM_EXT_STATUS_BlockEndVerifyFinalize(status)
/* BlockVerify */
# define FBL_MEM_EXT_STATUS_BlockVerifySequence(status)
# define FBL_MEM_EXT_STATUS_BlockVerifySigVerify(status)
# define FBL_MEM_EXT_STATUS_BlockVerifyInputVerify(status)
# define FBL_MEM_EXT_STATUS_BlockVerifyProcessedVerify(status)
# define FBL_MEM_EXT_STATUS_BlockVerifyPipeVerify(status)
# define FBL_MEM_EXT_STATUS_BlockVerifyOutputVerify(status)
/* SegmentStart indication */
# define FBL_MEM_EXT_STATUS_SegmentStartSequence(status)
# define FBL_MEM_EXT_STATUS_SegmentStartDataProcInit(status)
# define FBL_MEM_EXT_STATUS_SegmentStartStreamOutInit(status)
# define FBL_MEM_EXT_STATUS_SegmentStartVerifyInit(status)
# define FBL_MEM_EXT_STATUS_SegmentStartVerifyCompute(status)
# define FBL_MEM_EXT_STATUS_SegmentStartSegmentCount(status)   FblErrStatSetError(FBL_ERR_TOO_MANY_SEGMENTS_IN_MODULE)
/* SegmentEnd indication */
# define FBL_MEM_EXT_STATUS_SegmentEndSequence(status)
# define FBL_MEM_EXT_STATUS_SegmentEndInsufficientData(status)
# define FBL_MEM_EXT_STATUS_SegmentEndPost(status)
/* Data indication */
# define FBL_MEM_EXT_STATUS_DataIndSequence(status)
# define FBL_MEM_EXT_STATUS_DataIndParam(status)
# define FBL_MEM_EXT_STATUS_DataIndOverflow(status)            FblErrStatSetState(FBL_ERR_DATA_OVERFLOW)
/* Data processing */
# define FBL_MEM_EXT_STATUS_DataProc(status)
# define FBL_MEM_EXT_STATUS_DataProcConsume(status)
# define FBL_MEM_EXT_STATUS_DataProcDeinit(status)
/* Stream output */
# define FBL_MEM_EXT_STATUS_StreamOutput(status)
# define FBL_MEM_EXT_STATUS_StreamOutputConsume(status)
# define FBL_MEM_EXT_STATUS_StreamOutputOverflow(status)
# define FBL_MEM_EXT_STATUS_StreamOutputDeinit(status)
/* Memory driver */
# define FBL_MEM_EXT_STATUS_DriverResumeWrite(status)
/* Status contains flash driver error code */
# define FBL_MEM_EXT_STATUS_DriverWrite(status)                { FblErrStatSetFlashDrvError(status); FblErrStatSetError(FBL_ERR_FLASH_PROG_ERROR); }
# define FBL_MEM_EXT_STATUS_DriverErase(status)                { FblErrStatSetFlashDrvError(status); FblErrStatSetError(FBL_ERR_FLASH_ERASE_ERROR); }
# define FBL_MEM_EXT_STATUS_DriverRemainder(status)
# define FBL_MEM_EXT_STATUS_DriverSuspendWrite(status)
/* Programming operation */
# define FBL_MEM_EXT_STATUS_ProgramOverflow(status)            FblErrStatSetState(FBL_ERR_DATA_OVERFLOW)
# define FBL_MEM_EXT_STATUS_ProgramOutsideFbt(status)          FblErrStatSetError(FBL_ERR_NO_MEMORY_REGION_FOUND)
# define FBL_MEM_EXT_STATUS_ProgramUnalignedAddress(status)    FblErrStatSetError(FBL_ERR_FLASH_PROG_ERROR)
# define FBL_MEM_EXT_STATUS_ProgramDriverNotReady(status)      FblErrStatSetError(FBL_ERR_FLASHCODE_INIT_FAILED)
# define FBL_MEM_EXT_STATUS_ProgramPreWrite(status)
# define FBL_MEM_EXT_STATUS_ProgramPostWrite(status)
/* Erase operation */
# define FBL_MEM_EXT_STATUS_EraseOutsideFbt(status)            FblErrStatSetError(FBL_ERR_NO_MEMORY_REGION_FOUND)
# define FBL_MEM_EXT_STATUS_EraseDriverNotReady(status)        FblErrStatSetError(FBL_ERR_FLASHCODE_INIT_FAILED)
# define FBL_MEM_EXT_STATUS_ErasePreErase(status)
# define FBL_MEM_EXT_STATUS_ErasePostErase(status)
/* On-the-fly verification */
# define FBL_MEM_EXT_STATUS_VerifyCompute(status)
# define FBL_MEM_EXT_STATUS_VerifyFinalize(status)
/* Pass-through */
# define FBL_MEM_EXT_STATUS_PassThroughLocal(status)
# define FBL_MEM_EXT_STATUS_PassThroughRemote(status)
/* Custom status codes */
# define FBL_MEM_EXT_STATUS_ConditionCheck0(status)
# define FBL_MEM_EXT_STATUS_ConditionCheck1(status)
# define FBL_MEM_EXT_STATUS_ConditionCheck2(status)
# define FBL_MEM_EXT_STATUS_ConditionCheck3(status)

/* Extended info: status contains current address */
# define FBL_MEM_EXT_STATUS_ProgramAddress(status)             FblErrStatSetAddress(status)
# define FBL_MEM_EXT_STATUS_EraseAddress(status)               FblErrStatSetAddress(status)
#endif /* FBL_ENABLE_DEBUG_STATUS */

/* PRQA L:TAG_FblMemOem_0602_0603_1 */
/* PRQA L:TAG_FblMemOem_3453_1 */

#endif /* FBL_MEM_OEM_H */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* module specific MISRA deviations:

   MD_FblMemOem_0602_0603:
      Reason: Usage of reserved identifiers with leading underscores is accepted for compatibility reasons.
      Risk: Name conflicts.
      Prevention: Compile and link of the different variants in the component and integration test.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_MEM_OEM.H
 **********************************************************************************************************************/
