/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Library containing common functionality for memory programming:
 *                - Erase of memory region
 *                - Data processing (e.g. decryption and decompression)
 *                - Segmentation and alignment
 *                - Signature / checksum verification over RAM contents
 *                - Pipelined programming
 *
 *                Used by OEM dependent diagnostics to program incoming download data.
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
 *  01.00.00   2012-03-23  visjhg  -                Initial release
 *  01.00.01   2012-03-26  visjhg  -                Added description to file header
 *  01.01.00   2012-04-05  visjhg  ESCAN00057963    No changes
 *                                                  Changes and optimizations after code review
 *  01.02.00   2012-04-27  visjhg  ESCAN00058452    Added support for processed length
 *                                 ESCAN00058453    Removed fbl_mem_cfg.h include
 *                                 ESCAN00058621    No changes
 *  01.03.00   2012-06-22  visjhg  ESCAN00059475    No changes
 *                                 ESCAN00059477    No changes
 *  01.04.00   2013-02-01  visjhg  ESCAN00064290    Extensions for multi processor systems (pass-through)
 *                                                   Rework of block start indication interface
 *                                                   Pass additional info in structure
 *                         visjhg  ESCAN00064292    Added block erase
 *                         visjhg  ESCAN00064296    Preamble length switchable at runtime
 *                         visjhg  ESCAN00064301    Added signature verification on ROM contents
 *                                                   Rework of block verify interface
 *                                                   Keep track of segment history (structure provided externally)
 *                         visjhg  -                Added additional error codes for new functionality
 *                         visjhg  ESCAN00061335    No changes
 *                         visjhg  ESCAN00064333    No changes
 *                         visjhg  ESCAN00061764    No changes
 *                         visjhg  ESCAN00061814    No changes
 *                         visjhg  ESCAN00064338    Added post handler for SegmentEndIndication
 *                         visach  ESCAN00062919    Adapted comments to use Doxygen
 *                         visjhg  ESCAN00064334    Added interface to remap error codes to OEM dependent value
 *                         visjhg  ESCAN00064339    Segmented data processing: data produced during one cycle may be
 *                                                   smaller than buffer size
 *                         visjhg  ESCAN00064330    Explicit resume of suspended operation
 *                                                   Added state "suspend pending"
 *                                                   Added active operation check
 *                         visjhg  ESCAN00064343    Added support for multiple input sources
 *                         visjhg  -                Added additional error codes for new functionality
 *                         visjhg  -                Additional integration time checks
 *                         visjhg  ESCAN00064543    No changes
 *                         visjhg  ESCAN00064720    Replaced __ApplFblMemCheckDfi by __ApplFblMemIsDataProcessingRequired
 *  01.05.00   2013-04-10  visjhg  ESCAN00064871    No changes
 *                         visjhg  ESCAN00064890    No changes
 *                         visjhg  -                No changes
 *                         visjhg  ESCAN00065830    No changes
 *                         visjhg  ESCAN00066375    No changes
 *                         visjhg  ESCAN00066377    Encapsulate erase functionality
 *                         visjhg  ESCAN00066379    Added interface version compatibility check
 *                         visjhg  ESCAN00066380    Exported FblMemInit
 *  01.06.00   2013-07-22  visase  ESCAN00066743    No changes
 *                         visjhg  ESCAN00067433    Added FblMemDeinit
 *                                                  Updated interface version
 *                         visjhg  ESCAN00068321    Force response pending for erase operation
 *                         visjhg  ESCAN00069161    Added pipelined verification
 *                                                   Rework of block start and verify interface
 *                                                   Changed verification configuration options and error codes
 *                                                   Updated interface version (incompatible changes)
 *                         visjhg  ESCAN00069190    No changes
 *  01.07.00   2013-08-16  visjhg  ESCAN00069507    No changes
 *                         visjhg  ESCAN00069803    Updated interface version (enable/disable verification at run-time)
 *                                 ESCAN00069781    No changes
 *                                 ESCAN00069797    No changes
 *                         visjhg  ESCAN00069843    No changes
 *  02.00.00   2013-12-12  visjhg  ESCAN00069945    No changes
 *                         visjhg  ESCAN00072568    Error / status for BlockStartVerifyInit replaced by SegmentStartVerifyInit
 *                         visjhg  ESCAN00071344    No changes
 *                         visjhg  ESCAN00072569    Raised major version to match API version
 *                         visjhg  ESCAN00072156    No changes
 *                         visjhg  ESCAN00072570    No changes
 *                         visjhg  ESCAN00072631    No changes
 *  02.01.00   2014-03-12  visjhg  ESCAN00073504    Changed signature of input verification function type
 *                         visjhg  ESCAN00074066    No changes
 *  02.02.00   2014-05-09  visjhg  ESCAN00075225    No changes
 *                         visjhg  -                Removed some integration time checks
 *  03.00.00   2015-03-03  visjhg  -                Changed compatibility remapping for extended status (SegmentStartVerifyInit)
 *                         visjhg  ESCAN00076591    Updated interface version  (support for external stream output)
 *                         visjhg  ESCAN00077689    No changes
 *                         visjhg  ESCAN00077891    No changes
 *                         visjhg  ESCAN00081491    Added support for resumable programming
 *                         visjhg  ESCAN00081494    Added support for verification on processed input data
 *                         visjhg  ESCAN00081493    Added selective pipelined programming (forced flush when disabled)
 *  03.01.00   2015-04-23  visjhg  ESCAN00082572    No changes
 *                         visjhg  ESCAN00082605    Added support for reporting of progress information
 *                         visjhg  ESCAN00082606    Added support for gap fill (requires ordered segments)
 *  03.01.01   2015-04-27  visjhg  ESCAN00082700    No changes
 *  03.01.02   2015-05-27  visjhg  ESCAN00083138    No changes
 *  03.01.03   2015-06-13  visjhg  ESCAN00083358    No changes
 *                         visjhg  ESCAN00083390    No changes
 *                         visjhg  ESCAN00083391    No changes
 *                         visjhg  ESCAN00083392    Updated interface version
 *  03.02.00   2015-07-21  visjhg  ESCAN00084101    No changes
 *                         visjhg  ESCAN00084102    Added parameter type structure for stream processing
 *  03.02.01   2015-08-19  visjhg  ESCAN00084279    No changes
 *                         visjhg  ESCAN00084559    No changes
 *                         visjhg  ESCAN00084560    No changes
 *  03.02.02   2015-09-04  visjhg  ESCAN00084994    No changes
 *  04.00.00   2015-09-17  visjhg  ESCAN00085249    Support combination of input and processed verification
 *                                                  Updated interface version
 *                         visjhg  ESCAN00085250    No changes
 *                         visjhg  ESCAN00085251    No changes
 *  04.01.00   2016-04-01  visjhg  ESCAN00087997    Updated interface version
 *                         visjhg  ESCAN00088935    No changes
 *  04.02.00   2016-10-06  visjhg  ESCAN00090120    No changes
 *                         vishrf  ESCAN00091253    No changes
 *  04.02.01   2017-05-31  visjhg  ESCAN00094695    No changes
 *                         visjhg  ESCAN00095201    No changes
 *                         visjhg  ESCAN00095356    No changes
 *                         visjhg  -                Updated interface version
 *  04.03.00   2017-07-26  visjhg  ESCAN00095772    No changes
 *                         visjhg  ESCAN00095774    Added FblMemFlushInputData
 *                                                  Updated interface version
 *                         visjhg  ESCAN00095683    Place FblMemResumeIndication in RAMCODE section
 *                         visjhg  ESCAN00096075    No changes
 *  04.03.01   2017-08-07  visjhg  ESCAN00096209    No changes
 *  04.04.00   2018-08-22  visjhg  ESCAN00100464    No changes
 *                         visjhg  ESCAN00097115    No changes
 *                         visjhg  ESCAN00100482    Updated interface version (addition of __ApplFblMemConditionCheck)
 *  04.04.01   2018-09-25  visjhg  ESCAN00100850    Updated interface version (preamble for MCMP download use-case)
 *  04.05.00   2018-11-30  visjhg  ESCAN00101500    Added custom error codes to tFblMemStatus
 *                                                  Updated interface version
 *  04.05.01   2019-01-23  visjhg  ESCAN00101568    No changes
 *  04.05.02   2019-08-20  vistbe  ESCAN00103967    Updated interface version
 *  04.05.03   2019-10-02  visrie  ESCAN00104203    Fixed resumable pipelined verification
 *  04.06.00   2019-10-29  vistmo  FBL-813          Migration to MISRA 2012
 *  04.06.01   2020-03-18  visrie  ESCAN00105683    No changes
 *  04.06.02   2020-05-11  visjdn  ESCAN00105967    No changes
 *  04.06.03   2020-07-03  vistmo  ESCAN00106050    No changes
 *  04.07.00   2021-04-12  vishor  FBL-2187         Added/adapted MemMap sections
 *  04.08.00   2021-06-11  visjdn  FBL-3560         Add support for more than 256 download segments
 *  04.09.00   2021-07-09  vishor  FBL-3442         Add option to avoid abortion of verification procedure in case of error
 *                                                  Updated MISRA justifications
 *  04.09.01   2021-11-05  vishor  ESCAN00110663    No changes
 *  04.10.00   2022-05-02  vishor  FBL-5067         No changes
 *  04.10.01   2022-08-03  vismix  ESCAN00112185    No changes
 **********************************************************************************************************************/

#ifndef FBL_MEM_H
#define FBL_MEM_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblLib_Mem CQComponent : Implementation */
#define FBLLIB_MEM_VERSION            0x0410u
#define FBLLIB_MEM_RELEASE_VERSION    0x01u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBL_MEM_API_VERSION_MAJOR     0x04u
/** Minor interface version identifies backward compatible changes */
#define FBL_MEM_API_VERSION_MINOR     0x07u
/** Release interface version identifies cosmetic changes */
#define FBL_MEM_API_VERSION_RELEASE   0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_mem_oem.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/**
   Check for pending operations
   Enter task on states "pending", "suspend pending" and "suspended"
   Condition equals
      ( (fblMemProgState == kFblMemProgState_Pending) || (fblMemProgState == kFblMemProgState_Checkpoint)
        || (fblMemProgState == kFblMemProgState_SuspendPending) || (fblMemProgState == kFblMemProgState_Suspended) )
*/
#define FblMemTaskIsPending()    (fblMemProgState >= kFblMemProgState_Suspended)
/**
   Check for active operations
   Condition equals
      ( (fblMemProgState == kFblMemProgState_Pending) || (fblMemProgState == kFblMemProgState_Checkpoint)
        || (fblMemProgState == kFblMemProgState_SuspendPending) )
*/
#define FblMemTaskIsActive()     (fblMemProgState >= kFblMemProgState_SuspendPending)

/** Default source handle */
#define FBL_MEM_SOURCE_HANDLE_DEFAULT  0u

#if defined( FBL_MEM_SOURCE_COUNT )
# if (FBL_MEM_SOURCE_COUNT > 1u)
#  if defined( FBL_MEM_ENABLE_MULTI_SOURCE )
#  else
/** Multiple input sources */
#   define FBL_MEM_ENABLE_MULTI_SOURCE
#  endif /* FBL_MEM_ENABLE_MULTI_SOURCE */
# endif /* FBL_MEM_SOURCE_COUNT > 1u */
#endif /* FBL_MEM_SOURCE_COUNT */

/* No additional remapping required, simply cast to expected type */
# define FblMemRemapStatus(status)   ((FBL_MEM_STATUS_TYPE)(status))

#if defined( FBL_MEM_PROC_SEGMENTATION )
#else
/** Set data processing segmentation to default value */
# define FBL_MEM_PROC_SEGMENTATION     FBL_MEM_PROC_BUFFER_SIZE
#endif /* FBL_MEM_PROC_SEGMENTATION */

#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
# if defined( FBL_MEM_VERIFY_PIPELINED_JOB_COUNT )
# else
#  define FBL_MEM_VERIFY_PIPELINED_JOB_COUNT       1u
# endif
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

/*-- Compatibility remapping of configuration switches-----------------------*/
#if defined( FBL_ENABLE_TRANSFER_DATA_CHECKSUM ) 
# if defined( FBL_MEM_ENABLE_VERIFY_INPUT )
# else
#  define FBL_MEM_ENABLE_VERIFY_INPUT
# endif /* FBL_MEM_ENABLE_VERIFY_INPUT */
# if defined( FBL_MEM_ENABLE_ADDRESS_LENGTH_CHECKSUM )
#  if defined( FBL_MEM_ENABLE_VERIFY_INPUT_ADDRESS_LENGTH )
#  else
#   define FBL_MEM_ENABLE_VERIFY_INPUT_ADDRESS_LENGTH
#  endif /* FBL_MEM_ENABLE_VERIFY_INPUT_ADDRESS_LENGTH */
# endif /* FBL_MEM_ENABLE_ADDRESS_LENGTH_CHECKSUM */
#endif /* FBL_ENABLE_TRANSFER_DATA_CHECKSUM || FBL_ENABLE_TRANSFER_VERIFY_CHECK */


#if defined( FBL_ENABLE_GAP_FILL )
# if defined( FBL_MEM_ENABLE_GAP_FILL) || \
     defined( FBL_MEM_DISABLE_GAP_FILL )
/* Gap fill handling explicitly defined outside */
# else
#  define FBL_MEM_ENABLE_GAP_FILL
# endif /* FBL_MEM_ENABLE_GAP_FILL */
#endif /* FBL_ENABLE_GAP_FILL */


/*-- Remap configuration switches--------------------------------------------*/
#if ( defined( FBL_MEM_ENABLE_VERIFY_INPUT ) && \
      defined( FBL_MEM_ENABLE_VERIFY_INPUT_ADDRESS_LENGTH ) ) || \
    ( defined( FBL_MEM_ENABLE_VERIFY_PROCESSED ) && \
      defined( FBL_MEM_ENABLE_VERIFY_PROCESSED_ADDRESS_LENGTH ) ) || \
    ( defined( FBL_MEM_ENABLE_VERIFY_PIPELINED ) && \
      defined( FBL_MEM_ENABLE_VERIFY_PIPELINED_ADDRESS_LENGTH ) )
/** On-the-fly verification includes address and length information */
# define FBL_MEM_ENABLE_VERIFY_ADDRESS_LENGTH
/** Size of address and length information  */
# define FBL_MEM_VERIFY_ADDRESS_LENGTH_SIZE           4u
/** Size of address and length information  */
# define FBL_MEM_VERIFY_ADDRESS_LENGTH_BUFFER_SIZE    (2u * FBL_MEM_VERIFY_ADDRESS_LENGTH_SIZE)
#endif /* (FBL_MEM_ENABLE_VERIFY_INPUT && FBL_MEM_ENABLE_VERIFY_INPUT_ADDRESS_LENGTH) || (FBL_MEM_ENABLE_VERIFY_PIPELINED && FBL_MEM_ENABLE_VERIFY_PIPELINED_ADDRESS_LENGTH) */

#if defined( FBL_ENABLE_PIPELINED_PROGRAMMING ) || \
    defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
/** Pipelined operation */
# define FBL_MEM_ENABLE_PIPELINING
#endif /* FBL_ENABLE_PIPELINED_PROGRAMMING || FBL_MEM_ENABLE_VERIFY_PIPELINED */

#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT ) || \
    defined( FBL_MEM_ENABLE_GAP_FILL )
# if defined( FBL_MEM_ENABLE_SEGMENT_HANDLING ) || \
     defined( FBL_MEM_DISABLE_SEGMENT_HANDLING )
/* Segment handling explicitly defined outside
   If segments are required by signature/checksum verification on output data
   but segment handlings is disabled the correct segments have to be handled outside! */
# else
/** Segment handling required for signature/checksum verification on output data */
#  define FBL_MEM_ENABLE_SEGMENT_HANDLING
# endif /* FBL_MEM_ENABLE_SEGMENT_HANDLING */
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT || FBL_MEM_ENABLE_GAP_FILL */

#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )     || \
    defined( FBL_MEM_ENABLE_VERIFY_INPUT )      || \
    defined( FBL_MEM_ENABLE_VERIFY_PROCESSED )  || \
    defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )  || \
    defined( FBL_MEM_ENABLE_SEGMENT_HANDLING )  || \
    defined( FBL_ENABLE_PROCESSED_DATA_LENGTH ) || \
    defined( FBL_MEM_ENABLE_STREAM_OUTPUT )     || \
    defined( FBL_MEM_ENABLE_GAP_FILL )          || \
    defined( FBL_MEM_ENABLE_PROGRESS_INFO )
/** Persistent storage of block information */
# define FBL_MEM_ENABLE_GLOBAL_BLOCK_INFO
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT || FBL_MEM_ENABLE_VERIFY_INPUT || FBL_MEM_ENABLE_VERIFY_PIPELINED || FBL_MEM_ENABLE_SEGMENT_HANDLING || FBL_MEM_ENABLE_PASSTHROUGH || FBL_ENABLE_PROCESSED_DATA_LENGTH || FBL_MEM_ENABLE_STREAM_OUTPUT || FBL_MEM_ENABLE_GAP_FILL || FBL_MEM_ENABLE_PROGRESS_INFO */

/*
   Allow overwrite of certain data types or defines by using
   FBL_MEM_VERIFY_<type>_OVERWRITE defines / macros
*/
/*-- On-the-fly verification ------------------------------------------------*/
#if defined( FBL_MEM_VERIFY_OK_OVERWRITE )
#define FBL_MEM_VERIFY_OK                       (FBL_MEM_VERIFY_OK_OVERWRITE)
#else
#define FBL_MEM_VERIFY_OK                       (tFblMemVerifyStatus)(SECM_OK)
#endif
#if defined( FBL_MEM_VERIFY_STATE_INIT_OVERWRITE )
#define FBL_MEM_VERIFY_STATE_INIT               (FBL_MEM_VERIFY_STATE_INIT_OVERWRITE)
#else
#define FBL_MEM_VERIFY_STATE_INIT               kHashInit
#endif
#if defined( FBL_MEM_VERIFY_STATE_COMPUTE_OVERWRITE )
#define FBL_MEM_VERIFY_STATE_COMPUTE            (FBL_MEM_VERIFY_STATE_COMPUTE_OVERWRITE)
#else
#define FBL_MEM_VERIFY_STATE_COMPUTE            kHashCompute
#endif
#if defined( FBL_MEM_VERIFY_STATE_FINALIZE_OVERWRITE )
#define FBL_MEM_VERIFY_STATE_FINALIZE           (FBL_MEM_VERIFY_STATE_FINALIZE_OVERWRITE)
#else
#define FBL_MEM_VERIFY_STATE_FINALIZE           kHashFinalize
#endif
#if defined( FBL_MEM_VERIFY_STATE_VERIFY_OVERWRITE )
#define FBL_MEM_VERIFY_STATE_VERIFY             (FBL_MEM_VERIFY_STATE_VERIFY_OVERWRITE)
#else
#define FBL_MEM_VERIFY_STATE_VERIFY             kSigVerify
#endif

/*-- Error handling ---------------------------------------------------------*/

/* Helper macros for status definitions */
#define FBL_MEM_STATUS_NAME(name)         kFblMemStatus_ ## name /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#define FBL_MEM_STATUS_DEFINE(name)       FBL_MEM_STATUS_ ## name /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */

#if defined( FBL_MEM_ENABLE_STATUS_OVERWRITE )
/** Overwrite error codes by OEM dependent value */
# define FBL_MEM_STATUS_DEFINITION(name)  FBL_MEM_STATUS_NAME(name) = FBL_MEM_STATUS_DEFINE(name)
#else
/** Use automatically numbered error codes */
# define FBL_MEM_STATUS_DEFINITION(name)  FBL_MEM_STATUS_NAME(name)
#endif /* FBL_MEM_ENABLE_STATUS_OVERWRITE */

#if defined( FBL_MEM_ENABLE_STATUS_OVERWRITE ) 



#  if defined( FBL_MEM_STATUS_ProgramOverflow )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_ProgramOverflow             FBL_MEM_STATUS_Failed
#  endif


#  if defined( FBL_MEM_STATUS_VerifyCompute )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_VerifyCompute
#  endif

#  if defined( FBL_MEM_STATUS_VerifyFinalize )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_VerifyFinalize
#  endif

#  if defined( FBL_MEM_STATUS_SegmentStartVerifyInit )
#  else
#   if defined( FBL_MEM_STATUS_BlockStartVerifyInit )
/* Compatibility remapping (API < 2.2.0) */
#    define FBL_MEM_STATUS_SegmentStartVerifyInit     FBL_MEM_STATUS_BlockStartVerifyInit
#   else
#    error Status overwrite value missing: FBL_MEM_STATUS_SegmentStartVerifyInit
#   endif
#  endif
#  if defined( FBL_MEM_EXT_STATUS_BlockStartVerifyInit )
/* Compatibility remapping (API < 2.2.0) */
#   define FBL_MEM_EXT_STATUS_SegmentStartVerifyInit(status)      FBL_MEM_EXT_STATUS_BlockStartVerifyInit(status)
#  endif

#  if defined( FBL_MEM_STATUS_BlockEndVerifyFinalize )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_BlockEndVerifyFinalize
#  endif

#  if defined( FBL_MEM_STATUS_BlockVerifyInputVerify )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_BlockVerifyInputVerify
#  endif

#  if defined( FBL_MEM_STATUS_BlockVerifyPipeVerify )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_BlockVerifyPipeVerify
#  endif

#  if defined( FBL_MEM_STATUS_BlockVerifyOutputVerify )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_BlockVerifyOutputVerify
#  endif

#  if defined( FBL_MEM_STATUS_BlockStartParam )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_BlockStartParam
#  endif

#  if defined( FBL_MEM_STATUS_SegmentStartVerifyCompute )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_SegmentStartVerifyCompute
#  endif

#  if defined( FBL_MEM_STATUS_DataProc )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_DataProc
#  endif

#  if defined( FBL_MEM_STATUS_DataProcConsume )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_DataProcConsume
#  endif

#  if defined( FBL_MEM_STATUS_DataProcDeinit )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_DataProcDeinit
#  endif

#  if defined( FBL_MEM_STATUS_SegmentStartStreamOutInit )
#  else
/* Status code not defined: remap to data processing code */
#   define FBL_MEM_STATUS_SegmentStartStreamOutInit   FBL_MEM_STATUS_SegmentStartDataProcInit
#  endif

#  if defined( FBL_MEM_STATUS_StreamOutput )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_StreamOutput                FBL_MEM_STATUS_Failed
#  endif

#  if defined( FBL_MEM_STATUS_StreamOutputConsume )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_StreamOutputConsume         FBL_MEM_STATUS_Failed
#  endif

#  if defined( FBL_MEM_STATUS_StreamOutputOverflow )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_StreamOutputOverflow        FBL_MEM_STATUS_Failed
#  endif

#  if defined( FBL_MEM_STATUS_StreamOutputDeinit )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_StreamOutputDeinit          FBL_MEM_STATUS_Failed
#  endif

#  if defined( FBL_MEM_STATUS_DriverResumeWrite )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_DriverResumeWrite           FBL_MEM_STATUS_Failed
#  endif

#  if defined( FBL_MEM_STATUS_DriverRemainder )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_DriverRemainder             FBL_MEM_STATUS_Failed
#  endif

#  if defined( FBL_MEM_STATUS_BlockEraseSequence )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_BlockEraseSequence
#  endif

#  if defined( FBL_MEM_STATUS_EraseOutsideFbt )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_EraseOutsideFbt
#  endif

#  if defined( FBL_MEM_STATUS_EraseDriverNotReady )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_EraseDriverNotReady
#  endif

# if defined( __ApplFblMemPreErase )
#  if defined( FBL_MEM_STATUS_ErasePreErase )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_ErasePreErase
#  endif
# else
#  if defined( FBL_MEM_STATUS_ErasePreErase )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_ErasePreErase               FBL_MEM_STATUS_Failed
#  endif
# endif /* FBL_MEM_ENABLE_ERASE && __ApplFblMemPreErase */

# if defined( __ApplFblMemPostErase )
#  if defined( FBL_MEM_STATUS_ErasePostErase )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_ErasePostErase
#  endif
# else
#  if defined( FBL_MEM_STATUS_ErasePostErase )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_ErasePostErase              FBL_MEM_STATUS_Failed
#  endif
# endif /* FBL_MEM_ENABLE_ERASE && __ApplFblMemPostErase */

# if defined( __ApplFblMemDriverReady )
#  if defined( FBL_MEM_STATUS_EraseDriverNotReady )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_EraseDriverNotReady
#  endif
# else
#  if defined( FBL_MEM_STATUS_EraseDriverNotReady )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_EraseDriverNotReady         FBL_MEM_STATUS_Failed
#  endif
# endif /* FBL_MEM_ENABLE_ERASE && __ApplFblMemDriverReady */

#  if defined( FBL_MEM_STATUS_SegmentStartSegmentCount )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_SegmentStartSegmentCount
#  endif

# if defined( __ApplFblMemPostSegmentEnd )
#  if defined( FBL_MEM_STATUS_SegmentEndPost )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_SegmentEndPost
#  endif
# else
#  if defined( FBL_MEM_STATUS_SegmentEndPost )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_SegmentEndPost              FBL_MEM_STATUS_Failed
#  endif
# endif /* __ApplFblMemPostSegmentEnd */

# if defined( __ApplFblMemDriverReady )
#  if defined( FBL_MEM_STATUS_ProgramDriverNotReady )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_ProgramDriverNotReady
#  endif
# else
#  if defined( FBL_MEM_STATUS_ProgramDriverNotReady )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_ProgramDriverNotReady       FBL_MEM_STATUS_Failed
#  endif
# endif /* __ApplFblMemDriverReady */

# if defined( __ApplFblMemPreWrite )
#  if defined( FBL_MEM_STATUS_ProgramPreWrite )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_ProgramPreWrite
#  endif
# else
#  if defined( FBL_MEM_STATUS_ProgramPreWrite )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_ProgramPreWrite             FBL_MEM_STATUS_Failed
#  endif
# endif /* __ApplFblMemPreWrite */

# if defined( __ApplFblMemPostWrite )
#  if defined( FBL_MEM_STATUS_ProgramPostWrite )
#  else
#   error Status overwrite value missing: FBL_MEM_STATUS_ProgramPostWrite
#  endif
# else
#  if defined( FBL_MEM_STATUS_ProgramPostWrite )
#  else
/* Status code not required: remap to default */
#   define FBL_MEM_STATUS_ProgramPostWrite            FBL_MEM_STATUS_Failed
#  endif
# endif /* __ApplFblMemPostWrite */

#endif /* FBL_MEM_ENABLE_STATUS_OVERWRITE || FBL_MEM_ENABLE_STATUS_REMAPPING */

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
/*-- Resumable programming --------------------------------------------------*/

/** Number of magic values used for snapshot validation */
# if defined( FBL_ENABLE_SYSTEM_CHECK )
#  define FBL_MEM_SNAPSHOT_MAGIC_COUNT    2u
# else
#  define FBL_MEM_SNAPSHOT_MAGIC_COUNT    0u
# endif /* FBL_ENABLE_SYSTEM_CHECK */

# if defined( FBL_MEM_ENABLE_GLOBAL_BLOCK_INFO )
#  define FBL_MEM_SNAPSHOT_BLOCK_INFO     sizeof(tFblMemBlockInfo)
# else
#  define FBL_MEM_SNAPSHOT_BLOCK_INFO     0u
# endif /* FBL_MEM_ENABLE_GLOBAL_BLOCK_INFO */

# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
#  define FBL_MEM_SNAPSHOT_VERIFY_PIPELINED_LIST         sizeof(tFblMemVerifyPipeList)
# else
#  define FBL_MEM_SNAPSHOT_VERIFY_PIPELINED_LIST         0u
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

# if defined( FBL_MEM_ENABLE_SEGMENT_HANDLING )
#  define FBL_MEM_SNAPSHOT_SEGMENT_LIST(segmentCount)             \
   (                                                              \
      /* Segment list */                                          \
      sizeof(tFblMemSegmentList)                                  \
      /* Segment list entries */                                  \
    + ((segmentCount) * sizeof(tFblMemSegmentListEntry))          \
   )
# else
#  define FBL_MEM_SNAPSHOT_SEGMENT_LIST(segmentCount)    0u
# endif /* FBL_MEM_ENABLE_SEGMENT_HANDLING */

# if defined( FBL_MEM_ENABLE_PROGRESS_INFO )
#  define FBL_MEM_SNAPSHOT_PROGRESS_INFO                          \
   (                                                              \
      /* Progress information */                                  \
      sizeof(tFblMemProgressInfo)                                 \
      /* Additional members of internal progress information */   \
    + (3u * sizeof(vuint32))                                      \
   )
# else
#  define FBL_MEM_SNAPSHOT_PROGRESS_INFO                 0u
# endif /* FBL_MEM_ENABLE_PROGRESS_INFO */

/** Approximate minimum size of snapshot buffer */
# define FBL_MEM_SNAPSHOT_SIZE(segmentCount)                      \
   (                                                              \
      /* Alignment reserve */                                     \
      sizeof(vuint32)                                             \
      /* Size information, allowed indications, error status */   \
    + (3u * sizeof(vuint32))                                      \
      /* Magic values */                                          \
    + (FBL_MEM_SNAPSHOT_MAGIC_COUNT * sizeof(vuint32))            \
      /* External segment info */                                 \
    + sizeof(tFblMemSegmentInfo)                                  \
      /* Progress information */                                  \
    + FBL_MEM_SNAPSHOT_PROGRESS_INFO                              \
      /* Additional members of internal segment info */           \
    + (9u * sizeof(vuint32))                                      \
      /* Block info */                                            \
    + FBL_MEM_SNAPSHOT_BLOCK_INFO                                 \
      /* Pipelined verification info */                           \
    + FBL_MEM_SNAPSHOT_VERIFY_PIPELINED_LIST                      \
      /* Segment list */                                          \
    + FBL_MEM_SNAPSHOT_SEGMENT_LIST(segmentCount)                 \
   )
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING*/

/* Options for extended verification API */
#define FBL_MEM_VERIFY_INPUT_OPT          0u
#define FBL_MEM_VERIFY_PROC_OPT           1u
#define FBL_MEM_VERIFY_PIPE_OPT           2u
#define FBL_MEM_VERIFY_OUTPUT_OPT         3u

#define FBL_MEM_CHK_OPTION(a, b)          (( a & (1u << b) ) != 0u)

#define FBL_MEM_OPT_INPUT_MASK            (1u << FBL_MEM_VERIFY_INPUT_OPT)
#define FBL_MEM_OPT_PROC_MASK             (1u << FBL_MEM_VERIFY_PROC_OPT)
#define FBL_MEM_OPT_Pipe_MASK             (1u << FBL_MEM_VERIFY_PIPE_OPT)
#define FBL_MEM_OPT_OUTPUT_MASK           (1u << FBL_MEM_VERIFY_OUTPUT_OPT)

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/
/*-- On-the-fly verification ------------------------------------------------*/
#if defined( FBL_MEM_VERIFY_STATUS_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_STATUS_TYPE_OVERWRITE             tFblMemVerifyStatus;
#else
typedef SecM_StatusType                                  tFblMemVerifyStatus;
#endif /* FBL_MEM_VERIFY_STATUS_TYPE_OVERWRITE */
#if defined( FBL_MEM_VERIFY_PARAM_TYPE_INPUT_OVERWRITE )
typedef FBL_MEM_VERIFY_PARAM_TYPE_INPUT_OVERWRITE        tFblMemVerifyParamInput;
#else
typedef SecM_SignatureParamType                          tFblMemVerifyParamInput;
#endif /* FBL_MEM_VERIFY_PARAM_TYPE_INPUT_OVERWRITE */
#if defined( FBL_MEM_VERIFY_PARAM_TYPE_OUTPUT_OVERWRITE )
typedef FBL_MEM_VERIFY_PARAM_TYPE_OUTPUT_OVERWRITE       tFblMemVerifyParamOutput;
#else
typedef SecM_VerifyParamType                             tFblMemVerifyParamOutput;
#endif /* FBL_MEM_VERIFY_PARAM_TYPE_OUTPUT_OVERWRITE */
#if defined( FBL_MEM_VERIFY_LENGTH_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_LENGTH_TYPE_OVERWRITE             tFblMemVerifyLength;
#else
typedef SecM_LengthType                                  tFblMemVerifyLength;
#endif /* FBL_MEM_VERIFY_LENGTH_TYPE_OVERWRITE */
#if defined( FBL_MEM_VERIFY_SIZE_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_SIZE_TYPE_OVERWRITE               tFblMemVerifySize;
#else
typedef SecM_SizeType                                    tFblMemVerifySize;
#endif /* FBL_MEM_VERIFY_SIZE_TYPE_OVERWRITE */
#if defined( FBL_MEM_VERIFY_ADDRESS_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_ADDRESS_TYPE_OVERWRITE            tFblMemVerifyAddr;
#else
typedef SecM_AddrType                                    tFblMemVerifyAddr;
#endif /* FBL_MEM_VERIFY_ADDRESS_TYPE_OVERWRITE */
#if defined( FBL_MEM_VERIFY_DATA_PTR_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_DATA_PTR_TYPE_OVERWRITE           tFblMemVerifyDataPtr;
#else
typedef V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *           tFblMemVerifyDataPtr;
#endif /* FBL_MEM_VERIFY_DATA_PTR_TYPE_OVERWRITE */
#if defined( FBL_MEM_VERIFY_WD_FCT_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_WD_FCT_TYPE_OVERWRITE             tFblMemVerifyWdFct;
#else
typedef FL_WDTriggerFctType                              tFblMemVerifyWdFct;
#endif /* FBL_MEM_VERIFY_WD_FCT_TYPE_OVERWRITE */
#if defined( FBL_MEM_VERIFY_READ_FCT_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_READ_FCT_TYPE_OVERWRITE           tFblMemVerifyReadFct;
#else
typedef FL_ReadMemoryFctType                             tFblMemVerifyReadFct;
#endif /* FBL_MEM_VERIFY_READ_FCT_TYPE_OVERWRITE */
#if defined( FBL_MEM_VERIFY_FCT_INPUT_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_FCT_INPUT_TYPE_OVERWRITE(tFblMemVerifyFctInput);
#else
typedef FBL_CALL_TYPE tFblMemVerifyStatus (*tFblMemVerifyFctInput) (V_MEMRAM1 tFblMemVerifyParamInput V_MEMRAM2 V_MEMRAM3 *fp);
#endif /* FBL_MEM_VERIFY_FCT_INPUT_TYPE_OVERWRITE */
#if defined( FBL_MEM_VERIFY_FCT_OUTPUT_TYPE_OVERWRITE )
typedef FBL_MEM_VERIFY_FCT_OUTPUT_TYPE_OVERWRITE(tFblMemVerifyFctOutput);
#else
typedef FBL_CALL_TYPE tFblMemVerifyStatus (*tFblMemVerifyFctOutput) (V_MEMRAM1 tFblMemVerifyParamOutput V_MEMRAM2 V_MEMRAM3 *fp);
#endif /* FBL_MEM_VERIFY_FCT_OUTPUT_TYPE_OVERWRITE */

#if defined( FBL_MEM_SEGMENT_LIST_TYPE_OVERWRITE )
typedef FBL_MEM_SEGMENT_LIST_TYPE_OVERWRITE              tFblMemSegmentList;
#else
typedef FL_SegmentListType                               tFblMemSegmentList;
#endif /* FBL_MEM_SEGMENT_LIST_TYPE_OVERWRITE */
#if defined( FBL_MEM_SEGMENT_LIST_ENTRY_TYPE_OVERWRITE )
typedef FBL_MEM_SEGMENT_LIST_ENTRY_TYPE_OVERWRITE        tFblMemSegmentListEntry;
#else
typedef FL_SegmentInfoType                               tFblMemSegmentListEntry;
#endif /* FBL_MEM_SEGMENT_LIST_ENTRY_TYPE_OVERWRITE */

/* Options type for extended verification API */
typedef vuint8 tFblMemVerifyOption;

/** Error codes reported by FblMem routines */
typedef enum
{
   /* Define status codes: kFblMemStatus_<name> */
   /* Default */
   FBL_MEM_STATUS_DEFINITION(Ok)                            /* 0x00 */
   ,FBL_MEM_STATUS_DEFINITION(Failed)                       /* 0x01 */
   /* BlockErase indication */
   ,FBL_MEM_STATUS_DEFINITION(BlockEraseSequence)           /* 0x02 */
   /* BlockStart indication */
   ,FBL_MEM_STATUS_DEFINITION(BlockStartSequence)           /* 0x03 */
   ,FBL_MEM_STATUS_DEFINITION(BlockStartParam)              /* 0x04 */
   /* BlockEnd indication */
   ,FBL_MEM_STATUS_DEFINITION(BlockEndSequence)             /* 0x05 */
   ,FBL_MEM_STATUS_DEFINITION(BlockEndVerifyFinalize)       /* 0x06 */
   /* BlockVerify */
   ,FBL_MEM_STATUS_DEFINITION(BlockVerifySequence)          /* 0x07 */
   ,FBL_MEM_STATUS_DEFINITION(BlockVerifyInputVerify)       /* 0x08 */
   ,FBL_MEM_STATUS_DEFINITION(BlockVerifyProcessedVerify)   /* 0x09 */
   ,FBL_MEM_STATUS_DEFINITION(BlockVerifyPipeVerify)        /* 0x0A */
   ,FBL_MEM_STATUS_DEFINITION(BlockVerifyOutputVerify)      /* 0x0B */
   /* SegmentStart indication */
   ,FBL_MEM_STATUS_DEFINITION(SegmentStartSequence)         /* 0x0C */
   ,FBL_MEM_STATUS_DEFINITION(SegmentStartDataProcInit)     /* 0x0D */
   ,FBL_MEM_STATUS_DEFINITION(SegmentStartStreamOutInit)    /* 0x0E */
   ,FBL_MEM_STATUS_DEFINITION(SegmentStartVerifyInit)       /* 0x0F */
   ,FBL_MEM_STATUS_DEFINITION(SegmentStartVerifyCompute)    /* 0x10 */
   ,FBL_MEM_STATUS_DEFINITION(SegmentStartSegmentCount)     /* 0x11 */
   /* SegmentEnd indication */
   ,FBL_MEM_STATUS_DEFINITION(SegmentEndSequence)           /* 0x12 */
   ,FBL_MEM_STATUS_DEFINITION(SegmentEndInsufficientData)   /* 0x13 */
   ,FBL_MEM_STATUS_DEFINITION(SegmentEndPost)               /* 0x14 */
   /* Data indication */
   ,FBL_MEM_STATUS_DEFINITION(DataIndSequence)              /* 0x15 */
   ,FBL_MEM_STATUS_DEFINITION(DataIndParam)                 /* 0x16 */
   ,FBL_MEM_STATUS_DEFINITION(DataIndOverflow)              /* 0x17 */
   /* Data processing */
   ,FBL_MEM_STATUS_DEFINITION(DataProc)                     /* 0x18 */
   ,FBL_MEM_STATUS_DEFINITION(DataProcConsume)              /* 0x19 */
   ,FBL_MEM_STATUS_DEFINITION(DataProcDeinit)               /* 0x1A */
   /* Stream output */
   ,FBL_MEM_STATUS_DEFINITION(StreamOutput)                 /* 0x1B */
   ,FBL_MEM_STATUS_DEFINITION(StreamOutputConsume)          /* 0x1C */
   ,FBL_MEM_STATUS_DEFINITION(StreamOutputOverflow)         /* 0x1D */
   ,FBL_MEM_STATUS_DEFINITION(StreamOutputDeinit)           /* 0x1E */
   /* Memory driver */
   ,FBL_MEM_STATUS_DEFINITION(DriverResumeWrite)            /* 0x1F */
   ,FBL_MEM_STATUS_DEFINITION(DriverWrite)                  /* 0x20 */
   ,FBL_MEM_STATUS_DEFINITION(DriverErase)                  /* 0x21 */
   ,FBL_MEM_STATUS_DEFINITION(DriverRemainder)              /* 0x22 */
   ,FBL_MEM_STATUS_DEFINITION(DriverSuspendWrite)           /* 0x23 */
   /* Programming operation */
   ,FBL_MEM_STATUS_DEFINITION(ProgramOverflow)              /* 0x24 */
   ,FBL_MEM_STATUS_DEFINITION(ProgramOutsideFbt)            /* 0x25 */
   ,FBL_MEM_STATUS_DEFINITION(ProgramUnalignedAddress)      /* 0x26 */
   ,FBL_MEM_STATUS_DEFINITION(ProgramDriverNotReady)        /* 0x27 */
   ,FBL_MEM_STATUS_DEFINITION(ProgramPreWrite)              /* 0x28 */
   ,FBL_MEM_STATUS_DEFINITION(ProgramPostWrite)             /* 0x29 */
   /* Erase operation */
   ,FBL_MEM_STATUS_DEFINITION(EraseOutsideFbt)              /* 0x2A */
   ,FBL_MEM_STATUS_DEFINITION(EraseDriverNotReady)          /* 0x2B */
   ,FBL_MEM_STATUS_DEFINITION(ErasePreErase)                /* 0x2C */
   ,FBL_MEM_STATUS_DEFINITION(ErasePostErase)               /* 0x2D */
   /* On-the-fly verification */
   ,FBL_MEM_STATUS_DEFINITION(VerifyCompute)                /* 0x2E */
   ,FBL_MEM_STATUS_DEFINITION(VerifyFinalize)               /* 0x2F */
   /* Pass-through */
   ,FBL_MEM_STATUS_DEFINITION(PassThroughLocal)             /* 0x30 */
   ,FBL_MEM_STATUS_DEFINITION(PassThroughRemote)            /* 0x31 */
#if defined( FBL_MEM_STATUS_ConditionCheck0 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck0)              /* 0x32 */
#endif /* FBL_MEM_STATUS_ConditionCheck0 */
#if defined( FBL_MEM_STATUS_ConditionCheck1 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck1)              /* 0x33 */
#endif /* FBL_MEM_STATUS_ConditionCheck1 */
#if defined( FBL_MEM_STATUS_ConditionCheck2 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck2)              /* 0x34 */
#endif /* FBL_MEM_STATUS_ConditionCheck2 */
#if defined( FBL_MEM_STATUS_ConditionCheck3 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck3)              /* 0x35 */
#endif /* FBL_MEM_STATUS_ConditionCheck3 */
#if defined( FBL_MEM_STATUS_ConditionCheck4 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck4)              /* 0x36 */
#endif /* FBL_MEM_STATUS_ConditionCheck4 */
#if defined( FBL_MEM_STATUS_ConditionCheck5 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck5)              /* 0x37 */
#endif /* FBL_MEM_STATUS_ConditionCheck5 */
#if defined( FBL_MEM_STATUS_ConditionCheck6 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck6)              /* 0x38 */
#endif /* FBL_MEM_STATUS_ConditionCheck6 */
#if defined( FBL_MEM_STATUS_ConditionCheck7 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck7)              /* 0x39 */
#endif /* FBL_MEM_STATUS_ConditionCheck7 */
#if defined( FBL_MEM_STATUS_ConditionCheck8 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck8)              /* 0x3A */
#endif /* FBL_MEM_STATUS_ConditionCheck8 */
#if defined( FBL_MEM_STATUS_ConditionCheck9 )
   ,FBL_MEM_STATUS_DEFINITION(ConditionCheck9)              /* 0x3B */
#endif /* FBL_MEM_STATUS_ConditionCheck9 */
} tFblMemStatus;

/** Memory type */
typedef enum
{
   kFblMemType_RAM = 0u,   /* Volatile memory      */
   kFblMemType_ROM         /* Non-volatile memory  */
} tFblMemType;

/** State of programming operation */
typedef enum
{
   kFblMemProgState_Idle = 0u,
   kFblMemProgState_Error,
   kFblMemProgState_Suspended,
   kFblMemProgState_SuspendPending,
   kFblMemProgState_Checkpoint,
   kFblMemProgState_Pending
} tFblMemProgState;

/** Pointer type to byte data in RAM */
typedef V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *        tFblMemRamData;
/** Pointer type to constant byte data in RAM */
typedef const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *  tFblMemConstRamData;

/** Data format identifier */
typedef vuint8 tFblMemDfi;

/** Input verification routine */
typedef struct
{
   tFblMemVerifyFctInput      function;
   V_MEMRAM1 tFblMemVerifyParamInput   V_MEMRAM2 V_MEMRAM3 * param;
} tFblMemVerifyRoutineInput;

/** Output verification routine */
typedef struct
{
   tFblMemVerifyFctOutput     function;
   V_MEMRAM1 tFblMemVerifyParamOutput  V_MEMRAM2 V_MEMRAM3 * param;
} tFblMemVerifyRoutineOutput;

/** Information passed in block erase / start indication */
typedef struct
{
   tFblAddress                targetAddress;          /**< Target address (erase operation) */
   tFblLength                 targetLength;           /**< Target length (erase operation) */
   /* Used for signature verification */
   tFblAddress                logicalAddress;         /**< Logical address (verification operation) */
   tFblLength                 logicalLength;          /**< Logical length (verification operation) */
   tFblMemVerifyRoutineInput  verifyRoutineInput;     /**< On-the-fly verification on input data */
   tFblMemVerifyRoutineInput  verifyRoutineProcessed; /**< On-the-fly verification on processed data */
   tFblMemVerifyRoutineInput  verifyRoutinePipe;      /**< Pipelined verification on output data */
   tFblMemVerifyRoutineOutput verifyRoutineOutput;    /**< Verification on output data */
   tFblMemVerifyReadFct       readFct;                /**< Memory read function, used by pipelined and output verification */
   V_MEMRAM1 tFblMemSegmentList V_MEMRAM2 V_MEMRAM3 * segmentList; /**< List of programmed segments, used by output verification */
   vuint32                    maxSegments;            /**< Maximum number of entries in segment list */
} tFblMemBlockInfo;

/** Verification data */
typedef struct
{
   tFblMemRamData data;    /**< Pointer to verification data (signature/checksum) */
   tFblLength     length;  /**< Length of verification data */
} tFblMemVerifyData;

/** Information passed in block verify */
typedef struct
{
   tFblMemVerifyData    verifyDataInput;     /**< On-the-fly verification on input data      */
   tFblMemVerifyData    verifyDataProcessed; /**< On-the-fly verification on processed data  */
   tFblMemVerifyData    verifyDataPipe;      /**< Pipelined verification on output data      */
   tFblMemVerifyData    verifyDataOutput;    /**< Verification on output data                */
} tFblMemBlockVerifyData;

/** Information passed in segment start indication */
typedef struct
{
   tFblAddress    targetAddress;    /* Target address (program operation)        */
   tFblLength     targetLength;     /* Target length (program operation)         */
   /* Used for signature verification */
   tFblAddress    logicalAddress;   /* Logical address (verification operation)  */
   tFblLength     logicalLength;    /* Logical length (verification operation)   */
   /* Handling info */
   tFblMemType    type;             /* Type (RAM / ROM)                          */
   tFblMemDfi     dataFormat;       /* Data format identifier (data processing)  */
} tFblMemSegmentInfo;

/** Return type for watchdog trigger */
#if defined( FBL_MEM_TRIGGER_STATUS_OVERWRITE )
typedef FBL_MEM_TRIGGER_STATUS_OVERWRITE  tFblMemTriggerStatus;
#else
typedef vuint8                            tFblMemTriggerStatus;
#endif

/** Input source handle */
typedef vuintx tFblMemInputSource;

#if defined( FBL_MEM_ENABLE_PROGRESS_INFO )
/** Operation types reported in progress information */
typedef enum
{
   kFblMemProgressType_Erase,       /**< Erase operation */
   kFblMemProgressType_Program,     /**< Programming operation (may include gap fill) */
   kFblMemProgressType_GapFill,     /**< Concluding gap fill operation */
   kFblMemProgressType_Verify,      /**< Verification operation */
   kFblMemProgressType_Undefined    /**< Undefined, used internally */
} tFblMemProgressType;

/** Progress information */
typedef struct
{
   tFblMemProgressType  type;             /**< Operation type */
   tFblAddress          logicalAddress;   /**< Logical block address */
   vuint32              segmentCount;     /**< Segment count
                                               Typically zero for erase and verification,
                                               segment index for programming and
                                               index of last segment incremented by one for concluding gap fill */
   vuint8               totalProgress;    /**< Total operation progress (current block) */
   vuint8               partialProgress;  /**< Partial operation progress */
} tFblMemProgressInfo;
#endif /* FBL_MEM_ENABLE_PROGRESS_INFO */

#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
typedef struct
{
   tFblAddress                baseAddress;      /**< Address of base memory region allowed to be modified */
   tFblLength                 baseLength;       /**< Length of base memory region allowed to be modified  */
   tFblAddress                address;          /**< Current programming address (based on previously produced length) */
   tFblLength                 length;           /**< Current programming remainder (based on previously produced length) */
   tFblMemConstRamData        inputData;        /**< Pointer to input data buffer */
   tFblMemRamData             outputData;       /**< Pointer to output data buffer (not used for stream output) */
   void (* watchdog)(void);                     /**< Watchdog trigger function */
   tFblLength                 inputLength;      /**< Length of input data */
   tFblLength                 outputSize;       /**< Size of output data buffer (not used for stream output) */
   tFblLength                 consumedLength;   /**< Number of consumed input data bytes */
   tFblLength                 producedLength;   /**< Number of produced output data bytes (stream output: directly programmed to memory) */
   vuint8                     mode;             /**< Applied data processing mode*/
} tFblMemStreamProcessing;
#endif /* FBL_MEM_ENABLE_STREAM_OUTPUT */

/*-- Resumable programming --------------------------------------------------*/
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
/** Structure of a pipelined verification job */
typedef struct
{
   tFblAddress address; /**< Address of the pipelined verification job */
   tFblLength length;   /**< Length of the pipelined verification job */
   vuintx segmentIndex; /**< Segment of the pipelined verification job */
   vuint8 type;         /**< Type of the pipelined verification job */
#  if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED_ADDRESS_LENGTH )
   vuint8 buffer[FBL_MEM_VERIFY_ADDRESS_LENGTH_BUFFER_SIZE];   /**< Buffer containing the address and length for the signature */
#  endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED_ADDRESS_LENGTH */
} tFblMemVerifyPipeInfo;

typedef struct
{
   vuintx count;           /**< Number of available pipelined verification jobs */
   tFblMemVerifyPipeInfo info[FBL_MEM_VERIFY_PIPELINED_JOB_COUNT]; /**< List of pipelined verification jobs */
} tFblMemVerifyPipeList;
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

#define FBLLIB_MEM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( __cplusplus )
extern "C" {
#endif

tFblMemRamData FblMemInitPowerOn( void );
tFblMemRamData FblMemInitPowerOnExt( tFblLength preambleLen, tFblMemInputSource sourceHandle );
tFblMemRamData FblMemInit( void );
void FblMemDeinit( void );
tFblMemRamData FblMemGetActiveBuffer( void );
tFblMemStatus FblMemBlockEraseIndication( const V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * block );
tFblMemStatus FblMemBlockStartIndication( V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * block );
tFblMemStatus FblMemBlockEndIndication( void );
tFblMemStatus FblMemBlockVerify( const V_MEMRAM1 tFblMemBlockVerifyData V_MEMRAM2 V_MEMRAM3 * verifyData,
   V_MEMRAM1 tFblMemVerifyStatus V_MEMRAM2 V_MEMRAM3 * verifyResult );
tFblMemStatus FblMemBlockVerifyExtended( const V_MEMRAM1 tFblMemBlockVerifyData V_MEMRAM2 V_MEMRAM3 * verifyData,
   V_MEMRAM1 tFblMemVerifyStatus V_MEMRAM2 V_MEMRAM3 * verifyResult, const tFblMemVerifyOption option );
tFblMemStatus FblMemSegmentStartIndication( const V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * segment );
tFblMemStatus FblMemSegmentEndIndication( V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 * writeLength );
tFblMemStatus FblMemDataIndication( tFblMemConstRamData buffer, tFblLength offset, tFblLength length );
void FblMemTask( void );
void FblMemFlushInputData( void );

/* Low level memory operations */
tFblMemStatus FblMemEraseRegion( tFblAddress eraseAddress, tFblLength eraseLength );
tFblMemStatus FblMemProgramBuffer( tFblAddress programAddress,V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 * programLength,
   tFblMemRamData programData );

/* Helper functions */
void FblMemSetInteger( vuintx count, vuint32 input, tFblMemRamData buffer );
vuint32 FblMemGetInteger( vuintx count, tFblMemConstRamData buffer );

#if defined( FBL_MEM_ENABLE_MULTI_SOURCE )
void FblMemLockInputSource( tFblMemInputSource sourceHandle );
#endif


#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
void FblMemInvalidateSnapshot( tFblMemRamData snapshotBuffer, tFblLength snapshotSize );
tFblMemStatus FblMemCreateSnapshot( tFblMemRamData snapshotBuffer, tFblLength snapshotSize );
tFblMemStatus FblMemRestoreSnapshot( tFblMemRamData snapshotBuffer,
   V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * block, V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * segment );
tFblMemStatus FblMemGetSnapshotInfo( tFblMemRamData snapshotBuffer, V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * validAddress );

/***********************************************************************************************************************
 *  ApplFblMemCheckpointIndication
 **********************************************************************************************************************/
/*! \brief         Callout function used to indicate checkpoint for possible snapshot creation
 *  \details       Is executed on every crossing of a flash block boundary.
 *                 When a snapshot of the current programming state should be created the callout has to use the API
 *                 function FblMemCreateSnapshot, providing a sufficiently large buffer to hold the snapshot.
 *                 In case FblMemCreateSnapshot reports an error, FblLib_Mem will continue the programming operation,
 *                 but the caller may have to remember the error condition to initiate required measures (e.g. report
 *                 error, abort programming, invalidate internal snapshot state).
 *  \param[out]    validAddress  Last successfully programmed address (last address of flash block)
 **********************************************************************************************************************/
extern void ApplFblMemCheckpointIndication( tFblAddress validAddress );
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING*/

#define FBLLIB_MEM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLLIB_MEM_RAMCODE_START_SEC_CODE_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void FblMemResumeIndication( void );
#if defined( FBL_MEM_ENABLE_PIPELINING )
void FblMemRxNotification( void );
#endif /* FBL_MEM_ENABLE_PIPELINING */

#define FBLLIB_MEM_RAMCODE_STOP_SEC_CODE_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( __cplusplus )
} /* extern "C" */
#endif

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLLIB_MEM_START_SEC_VAR_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 extern V_MEMRAM1 tFblMemProgState V_MEMRAM2 fblMemProgState;

#define FBLLIB_MEM_STOP_SEC_VAR_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

/* Plausibility checks of configuration settings *****************************/
/*-- Integration time -------------------------------------------------------*/




















/*-- Compatibility remapping of configuration switches-----------------------*/



/*-- Compile time -----------------------------------------------------------*/
#if defined( FBL_ENABLE_PIPELINED_PROGRAMMING ) || \
    defined( FBL_ENABLE_ADAPTIVE_DATA_TRANSFER_RCRRP )
# if defined( FBL_MEM_WRITE_SEGMENTATION )
# else
#  error Write segmentation not defined
# endif
# if defined( FBL_ENABLE_UNALIGNED_DATA_TRANSFER )
# else
#  if ( (FBL_MEM_WRITE_SEGMENTATION & (FBL_MAX_SEGMENT_SIZE - 1u)) != 0u )
#   error Write segmentation has to be multiple of segment size
#  endif
# endif /* FBL_ENABLE_UNALIGNED_DATA_TRANSFER */
#endif /* FBL_ENABLE_PIPELINED_PROGRAMMING || FBL_ENABLE_ADAPTIVE_DATA_TRANSFER_RCRRP */

# if defined( FBL_ENABLE_PIPELINED_PROGRAMMING )
#  if defined( FBL_MEM_PIPE_PROG_BUFFER_COUNT )
#   if ( FBL_MEM_PIPE_PROG_BUFFER_COUNT < 2 )
#    error Number of pipelined programming buffers has to be at least two
#   endif
#  endif /* FBL_MEM_PIPE_PROG_BUFFER_COUNT */
# endif /* FBL_ENABLE_PIPELINED_PROGRAMMING */

#if defined( FBL_ENABLE_DATA_PROCESSING )
# if defined( FBL_MEM_PROC_BUFFER_SIZE )
# else
#  error Data processing buffer size not defined
# endif
# if ( FBL_MEM_PROC_SEGMENTATION > 0xFFFFu )
#  error Data processing segmentation exceeds interface constraints
# endif
# if ( FBL_MEM_PROC_SEGMENTATION > FBL_MEM_PROC_BUFFER_SIZE )
#  error Data processing segmentation exceeds buffer size
# endif
# if ( FBL_MEM_PROC_SEGMENTATION == FBL_MEM_PROC_BUFFER_SIZE )
# else
# endif
#endif /* FBL_ENABLE_DATA_PROCESSING */

#if defined( FBL_MEM_ENABLE_VERIFY_INPUT ) || \
    defined( FBL_MEM_ENABLE_VERIFY_PROCESSED )
# if defined( FBL_MEM_SIG_RESULT_BUFFER_SIZE )
# else
#  error Signature result buffer size not defined
# endif
#endif /* FBL_MEM_ENABLE_VERIFY_INPUT || FBL_MEM_ENABLE_VERIFY_PROCESSED */

#if defined( FBL_MEM_BUFFER_SIZE )
#else
# error Input buffer size not defined
#endif /* FBL_MEM_BUFFER_SIZE */

#if defined( FBL_MEM_DEFAULT_PREAMBLE_LENGTH )
#else
# error Default preamble length not defined
#endif /* FBL_MEM_DEFAULT_PREAMBLE_LENGTH */

#if defined( FBL_MEM_MAX_PREAMBLE_LENGTH )
#else
# error Maximum preamble length not defined
#endif /* FBL_MEM_MAX_PREAMBLE_LENGTH */

#if defined( FBL_MEM_WD_TRIGGER_DEFAULT )
#else
# error Default watchdog trigger return code not defined
#endif /* FBL_MEM_WD_TRIGGER_DEFAULT */


#if defined( FBL_MEM_ENABLE_STATUS_OVERWRITE ) 
# if defined( FBL_MEM_STATUS_Ok ) && \
     defined( FBL_MEM_STATUS_Failed )
# else
#  error Status overwrite or remapping enabled, but actual values missing
# endif
#endif /* FBL_MEM_ENABLE_STATUS_OVERWRITE || FBL_MEM_ENABLE_STATUS_REMAPPING */

#if defined( FBL_MEM_STATUS_Ok ) || \
    defined( FBL_MEM_STATUS_Failed )
# if defined( FBL_MEM_ENABLE_STATUS_OVERWRITE ) 
# else
#  error Status values defined, but neither status overwrite nor remapping enabled
# endif
#endif /* FBL_MEM_STATUS_Ok || FBL_MEM_STATUS_Failed */

#if defined( FBL_MEM_ENABLE_EXT_STATUS )
# if defined( FBL_MEM_EXT_STATUS_Ok ) && \
     defined( FBL_MEM_EXT_STATUS_Failed )
# else
#  error Extended status enabled, but actual macros missing
# endif
#endif /* FBL_MEM_ENABLE_EXT_STATUS */

#if defined( FBL_MEM_EXT_STATUS_Ok ) || \
    defined( FBL_MEM_EXT_STATUS_Failed )
# if defined( FBL_MEM_ENABLE_EXT_STATUS )
# else
#  error Extended status macros defined, but feature not enabled
# endif
#endif /* FBL_MEM_EXT_STATUS_Ok || FBL_MEM_EXT_STATUS_Failed */


#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
# if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
#  error Combination of stream output with resumable programming not supported
# endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
# if defined( FBL_MEM_ENABLE_VERIFY_PROCESSED )
#  error Combination of stream output with processed verification not supported
# endif /* FBL_MEM_ENABLE_VERIFY_PROCESSED */
# if defined( __ApplFblMemIsStreamOutputRequired )
# else
#  error Stream output enabled, but data format check not specified
# endif
#endif /* FBL_MEM_ENABLE_STREAM_OUTPUT */

#if defined( FBL_MEM_ENABLE_PROGRESS_INFO )
# if defined( FBL_ENABLE_PROCESSED_DATA_LENGTH)
#  error Combination of progress information with processed data length not supported
# endif /* FBL_ENABLE_PROCESSED_DATA_LENGTH */
# if defined( __ApplFblMemReportProgress )
# else
#  error Progress information enabled, but report callout not specified
# endif /* __ApplFblMemReportProgress */
#endif /* FBL_MEM_ENABLE_PROGRESS_INFO */

#endif /* FBL_MEM_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_MEM.H
 **********************************************************************************************************************/
