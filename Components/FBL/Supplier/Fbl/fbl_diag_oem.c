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
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  10.00.00   2020-10-14  viscb   FBL-2177         DRECU2020-01 adaptions, input verification and encrypted download
 *  10.01.00   2021-01-19  viscb   ESCAN00108071    PreCheckProgrammingDependencies returns sw-sw mismatch for if
 *                                                  logical block is no programmed
 *                         viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - response for programming session request is sent before transition
 *                                                    - Adapted interface for secure boot
 *                                                    - Logical block access by index value
 *  10.01.01   2021-02-02  viscb   ESCAN00108445    QM release
 *  10.01.02   2021-04-21  viscb   ESCAN00108537    RoutineControl -verifyMemoryContents
 *                                 ESCAN00108093    Logical block can be verified with signature of other logical block
 *                                 ESCAN00108139    No changes
 *                                 FBL-3360         Added/adapted MemMap sections
 *  10.01.03   2021-05-28  viscb   ESCAN00109398    Send NRC 36h when invalid key is received
 *                                 ESCAN00109400    Initialize reprogramming states in SecurityAccess-requestSeed
 *  10.01.04   2021-06.07  viscb   ESCAN00109435    Diag buffer ptr is not updated in function ReqTransferExitMainHandler
 *                                 ESCAN00109437    No changes
 *  10.02.00   2021-07-09  vishor  FBL-3567         Add support for Csm-based suspend/resume
 *                                 ESCAN00107081    Resumable programming at RoutineControl - checkMemory fails
 *  10.02.01   2021-08-26  visjdn  ESCAN00109069    RoutineControl shall not support NRC GeneralProgrammingFailure
 *  10.02.02   2021-10-27  visrie  ESCAN00109153    [DemoAppl] Pos. Response for Programmingsession has to be send
 *                                                   from Application
 *  10.03.00   2022-03-15  vishor  FBL-4621         MB MMA Rework
 *                                 ESCAN00110728    Download of encrypted application fails after restart
 *                                 ESCAN00110898    Wrong configuration is not detected
 *                                 ESCAN00110960    Download with incorrect signature is accepted
 *                                 ESCAN00111146    Resumable programming fails for interruption after first
 *                                                   RequestDownload
 *                                 ESCAN00111396    [Demo Appl only] missing code for ProgRequest flag
 *  10.04.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00110486    No changes
 *  10.04.01   2022-06-27  vismix  ESCAN00112173    Logical block 0 gets validated after resuming an interrupted download
 *                                                   at RoutineControl - checkMemory
 *                                 ESCAN00112160    Incorrect routineStatus info in positive response of
 *                                                   RoutineControl - checkMemory
 *  10.04.02   2022-08-26  vismix  FBL-5754         Fix multiple issues
 *                                 ESCAN00112447    Wrong NRC is send if service PreCheckProgrammingDependencies is
 *                                                   send with a wrong length
 *                                 ESCAN00112459    Routine Control - PreCheckDependencies is not accepted in
 *                                                   Default Session
 *  10.04.03   2023-01-09  vismix  ESCAN00112744    FblDiagRCStartVerifyMemoryContentMainHandler always reports correct CRC
 *                                                   OR FblDiagRCStartCsumMainHandler always reports wrong CRC
 *                                 ESCAN00113013    Resumable Programming fails in configurations with multiple logical blocks
 *                                 ESCAN00113078    Reprogramming process state is not correctly updated to
 *                                                   "Reprogramming started"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Common Bootloader includes */
#include "fbl_inc.h"
/* Core Diagnostic interface and global symbols */
#include "fbl_diag_core.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/
/* Diagnostic OEM module version check */
#if ( FBLDIAG_14229_DAIMLER_VERSION != 0x1004u ) || \
    ( FBLDIAG_14229_DAIMLER_RELEASE_VERSION != 0x03u )
# error "Error in fbl_diag_oem.c: Source and header file are inconsistent!"
#endif

#if ( FBLDIAG_14229_DAIMLER_VERSION != _FBLDIAG_OEM_VERSION ) || \
    ( FBLDIAG_14229_DAIMLER_RELEASE_VERSION != _FBLDIAG_OEM_RELEASE_VERSION )
# error "Error in fbl_diag_oem.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  PLAUSIBILITY CHECKS OF CONFIGURATION SETTINGS
 **********************************************************************************************************************/

/* Either Output- or Pipelined verification is supported */
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT ) && \
    defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
# error "Output verification and pipelined verification mustn't be combined."
#endif
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT ) || \
    defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
#else
# error "At least one verification method must be activated."
#endif

#if defined( FBL_ENABLE_WRAPPER_NV )
# if (( kEepSizeSegmentLengthList < (kDiagFmtFixedAddrSize * SWM_DATA_MAX_NOAR) ) || \
     ( kEepSizeSegmentAddrList < (kDiagFmtFixedLengthSize * SWM_DATA_MAX_NOAR) ))
#  error "Error in WrapNv_Cfg.h: Configuration error (kEepSizeSegmentLists too small)"
# endif
# if (kEepSizeSegmentLengthList != kEepSizeSegmentAddrList)
#  error "Error in WrapNv_Cfg.h: Configuration error (kEepSizeSegmentAddrList and kEepSizeSegmentLists must be of the same size)"
# endif
#endif /* FBL_ENABLE_WRAPPER_NV */

#if ( FBL_DIAG_DDS_VERSION == FBL_DIAG_DDS_R01_01_2020_01 )
# if defined( FBL_MEM_ENABLE_VERIFY_PROCESSED ) || !defined( FBL_MEM_ENABLE_VERIFY_INPUT)
#  error "If flash download specification DDS_R01_01_2020_01 is selected, input verification must be selected"
# endif
#elif ( FBL_DIAG_DDS_VERSION == FBL_DIAG_DDS_R01_01_2016_06 )
# if defined( FBL_MEM_ENABLE_VERIFY_INPUT ) || !defined(FBL_MEM_ENABLE_VERIFY_PROCESSED)
#  error "If flash download specification DDS_R01_01_2016_06 is selected, processed verification must be selected"
# endif
#else
# error "No valid download specification version selected"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  State handling
 **********************************************************************************************************************/

/* Download sequence states */
#define FblDiagSetSecurityKeyAllowed()                 SetFblDiagState( kFblDiagStateSecurityKey )
#define FblDiagClrSecurityKeyAllowed()                 ClrFblDiagState( kFblDiagStateSecurityKey )
#define FblDiagSetSecurityUnlock()                     SetFblDiagState( kFblDiagStateSecurityAccess )
#define FblDiagClrSecurityUnlock()                     ClrFblDiagState( kFblDiagStateSecurityAccess )
#define FblDiagSetFingerprintValid()                   SetFblDiagState( kFblDiagStateFingerprintValid )
#define FblDiagClrFingerprintValid()                   ClrFblDiagState( kFblDiagStateFingerprintValid )
#define FblDiagSetTransferDataAllowed()                SetFblDiagState( kFblDiagStateTransferDataAllowed )
#define FblDiagClrTransferDataAllowed()                ClrFblDiagState( kFblDiagStateTransferDataAllowed )
#define FblDiagSetPreCheckProgDepFailed()              SetFblDiagState( kFblDiagStatePreCheckProgDepFailed )
#define FblDiagClrPreCheckProgDepFailed()              ClrFblDiagState( kFblDiagStatePreCheckProgDepFailed )

/* Additional macros for FBL state flag access */
#define FblDiagSetTransferDataSucceeded()              SetFblDiagState( kFblDiagStateTransferDataSucceeded )
#define FblDiagClrTransferDataSucceeded()              ClrFblDiagState( kFblDiagStateTransferDataSucceeded )
#define FblDiagSetEraseSucceeded()                     SetFblDiagState( kFblDiagStateEraseSucceeded)
#define FblDiagClrEraseSucceeded()                     ClrFblDiagState( kFblDiagStateEraseSucceeded)
#define FblDiagSetCheckMemoryAllowed()                 SetFblDiagState( kFblDiagStateCheckMemoryAllowed )
#define FblDiagClrCheckMemoryAllowed()                 ClrFblDiagState( kFblDiagStateCheckMemoryAllowed )
#define FblDiagSetCheckMemorySucceeded()               SetFblDiagState( kFblDiagStateCheckMemorySucceeded )
#define FblDiagClrCheckMemorySucceeded()               ClrFblDiagState( kFblDiagStateCheckMemorySucceeded )

#define FblDiagSetDeltaDownload()                      SetFblDiagState( kFblDiagStateDelta )
#define FblDiagClrDeltaDownload()                      ClrFblDiagState( kFblDiagStateDelta )

#define FblDiagSetPlatformMsgWindow()                  SetFblDiagState( kFblDiagStatePlatformMsgWindow )
#define FblDiagClrPlatformMsgWindow()                  ClrFblDiagState( kFblDiagStatePlatformMsgWindow )


/***********************************************************************************************************************
 *  Local constants
 **********************************************************************************************************************/

#define kFblDiagInitSequenceNum                        0x01u

/* General Daimler specific defines */
#define kFblDiagLengthFmtDC                            0x04u
#define kFblDiagAddrFmtDC                              0x04u
#define CheckLengthFormat(lengthFormat)                (((lengthFormat) == kFblDiagLengthFmtDC) ? kFblOk:kFblFailed)
#define CheckAddrFormat(addrFormat)                    (((addrFormat) == kFblDiagAddrFmtDC) ? kFblOk:kFblFailed)

/* Flag for delta flashing enabled in eraseMemory (logical block number) */
#define kFblDiagDeltaDownloadEnabled                   0x80u
#define kFblDiagLogicalBlockMask                       FblInvert8Bit(kFblDiagDeltaDownloadEnabled)

/* RoutineControl status for eraseMemory */
#define kFblDiagEraseSucceeded                         0x00u
#define kFblDiagEraseFailed                            0x01u

#if !defined(kSecSigSize)
# define kSecSigSize 0u
#endif

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
/* Reserve memory for snapshot of security module */
# if !defined(kFblDiagSecSnapshotSize )
#  define kFblDiagSecSnapshotSize 0x500u
# endif
# if !defined(kDiagSecPipeSnapshotSize)
/* Reserve memory for snapshot of pipelined verification */
#  define kDiagSecPipeSnapshotSize 0x20u
# endif
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

/* Set segemnt counter back in case of NRC */
#define FblDiagRestoreSegmentCnt()                     {                                   \
                                                          segmentCount--;                  \
                                                       }

#if defined( FBL_ENABLE_UNALIGNED_DATA_TRANSFER )
   /* Report full diagnostic buffer size */
# define FBL_DIAG_RESPONSE_BUFFER_SIZE FBL_DIAG_BUFFER_LENGTH
#else
   /* Calculate buffer size so that a multiple of the diagnostic buffer size + 2 is reported */
# define FBL_DIAG_RESPONSE_BUFFER_SIZE ((((FBL_DIAG_SEGMENT_SIZE - 1u) ^ 0xFFFFFFFFu) & (FBL_DIAG_BUFFER_LENGTH - 2u)) + 2u)
#endif /* FBL_ENABLE_UNALIGNED_DATA_TRANSFER */

#if( FBL_DIAG_RESPONSE_BUFFER_SIZE >= 0x1000000u )
# define FBL_DIAG_RESPONSE_BUFFER_LFI 4u
#elif( FBL_DIAG_RESPONSE_BUFFER_SIZE >= 0x10000u )
# define FBL_DIAG_RESPONSE_BUFFER_LFI 3u
#else
# define FBL_DIAG_RESPONSE_BUFFER_LFI 2u
#endif

/***********************************************************************************************************************
 *  TYPEDEFS AND STRUCTURES FOR INTERNAL USE
 **********************************************************************************************************************/

typedef enum
{
   kFblRsNoResume,
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   kFblRsDynamicResume,
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
   kFblRsSectorResume
}tResumeReqState;

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
/** State information for resumable programming */
typedef enum
{
   kFblRsInitial,
   kFblRsBlockErased,
   kFblRsSnapshotCreated,
   kFblRsMemoryChecked
}tResumeStatus;

/** Information structure for resumable programming */
typedef struct
{
   tFblAddress    resumeAddress;
   tResumeStatus  resumeStatus;
   tFblLbtBlockNr resumeBlockNo;
   vuint8         resumeFpStatus;   /* Currently not used */
   vuint32        secModSnapshotLength;
   vuint8         secModSnapshot[kFblDiagSecSnapshotSize];
# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   vuint32        secModPipeSnapshotLength;
   vuint8         secModPipeSnapshot[kDiagSecPipeSnapshotSize];
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */
   vuint8         libMemSnapshot[FBL_MEM_SNAPSHOT_SIZE(SWM_DATA_MAX_NOAR)];
}tResumeState;
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

static tFblResult FblDiagDownloadCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
static tFlashStatus FblDiagGetEraseState( void );
#endif
static tFblResult FblDiagInitMemDriver(void);
static tFblResult FblDiagBlockStartIndication(vuint8 blockNr );
static tFblResult FblDiagSegmentStartIndication(const vuint8 *pbDiagData, tFblAddress transferAddParam );

static void FblDiagSessionControlParamInit(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* NRC handler functions */
static tFblResult FblDiagProcessServiceNrc(vuint32 serviceErrorMask);
static tFblResult FblDiagProcessSubfunctionNrc(vuint32 serviceErrorMask);
static tFblResult FblDiagProcessSubparamNrc(vuint32 serviceErrorMask);
static tFblResult FblDiagProcessRoutineNrc(vuint32 serviceErrorMask);

/* Length check functions */
static tFblResult FblDiagNoneLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Diagnostic service processing functions */

/* Session handling */
static tFblResult FblDiagDefaultSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagExtendedSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagProgrammingSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Reset */
static tFblResult FblDiagEcuResetMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );

/* ReadDataByIdentifier */
static tFblResult FblDiagReadDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );

/* CommunicationControl */
static tFblResult FblDiagCommCtrlMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );

/* SecurityAccess */
static void FblDiagSecAccResetStates(vuint8 *pbDiagData);
static tFblResult FblDiagSecAccessSeedMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
static tFblResult FblDiagSecAccessKeyMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );

/* WriteDataByIdentifier*/
static tFblResult FblDiagWriteFingerprintMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
#if (FBLCW_CHANGE_PARAMETER == STD_ON)
static tFblResult FblDiagWriteIsoTpBlockSizeSTminMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
#endif

/* RoutineControl */
static tFblResult FblDiagRCStartCsumMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartCheckProgPrecondMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
static tFblResult FblDiagRCStartCtrlFailSafeReactionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStopCtrlFailSafeReactionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartVerifyMemoryContentMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartPrepVehicleSystForReprogMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartPreChkProgDependMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartEraseMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartCheckComptDependenciesMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Data Transfer */
static tFblResult FblDiagRequestDownloadMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
static void       FblDiagRequestDownloadSendResponse(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
static tFblResult FblDiagInitBlockAndCheckRange( tFblAddress segmentAddress, tFblLength segmentLength, vuint8 blockResumeStateIdx );
#endif
static tFblResult FblDiagTransferDataMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );
static tFblResult FblDiagReqTransferExitMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );

static tFblResult FblDiagTesterPresentMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );

static tFblResult FblDiagControlDTCMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen );

/* Service pre-handler functions */
static tFblResult FblDiagDefaultPreHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
static tFblResult FblDiagCheckRequestDownloadResumeState(V_MEMRAM1 tResumeReqState V_MEMRAM2 V_MEMRAM3 * resumeRequestState,
   tCwDataLengthType diagReqDataLen);
static void       FblDiagResetBlockResume( tResumeState * pBlockResumeState );
static void       FblDiagInitBlockResume( tFblLbtBlockNr blockNo, tResumeState * pBlockResumeState );
static vuint16    FblDiagFindResumeSection( tFblAddress address );

static tFblResult FblDiagCreateSnapshot( tResumeState * pBlockResumeState, tFblAddress newResumeAddress );
static tFblResult FblDiagRestoreSnapshot( V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * block,
                                          V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * segment,
                                          tResumeState * pBlockResumeState );
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

#if defined( FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC ) && defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
static SecM_StatusType FblDiagOfrLightWrapper(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
#endif

#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* RAM mirror of fingerprint status */
V_MEMRAM0 V_MEMRAM1      vuint8                V_MEMRAM2        fingerprintStatus;
#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 static V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2      verifyParam;
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      retryCounter;                              /**< Counter for TransferData retries   */

/* Temporary data used during download in TransferData */
V_MEMRAM0 static V_MEMRAM1 FL_SegmentInfoType   V_MEMRAM2      downloadSegmentList[SWM_DATA_MAX_NOAR]; /* PRQA S 3218 */ /* MD_FblDiag_3218 */

#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
/** Verification information to be transmitted to security module - pipelined verification */
V_MEMRAM0 static V_MEMRAM1 SecM_SignatureParamType    V_MEMRAM2 pipeSigParam; /* PRQA S 3218 */ /* MD_FblDiag_3218 */
/** Length of already verified data */
V_MEMRAM0 static V_MEMRAM1 vuint32                    V_MEMRAM2 pipeSigDataLength; /* PRQA S 3218 */ /* MD_FblDiag_3218 */
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

/* PRQA S 3218 3 */ /* MD_FblDiag_3218 */
V_MEMRAM0 static V_MEMRAM1 SecM_SignatureParamType      V_MEMRAM2 sigParam;
V_MEMRAM0 static V_MEMRAM1 SecM_RamBufferType           V_MEMRAM2 sigKeyParam;
V_MEMRAM0 static V_MEMRAM1 SecM_ByteType                V_MEMRAM2 sigKeyBuf[SEC_SIZE_KEY_ECDSA_CURVE25519];

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
V_MEMRAM0 static V_MEMRAM1 tFblAddress          V_MEMRAM2      transferAddress;         /**< Actual transfer address            */
#endif
V_MEMRAM0 static V_MEMRAM1 tFblLength           V_MEMRAM2      transferRemainder;       /**< Number of remaining transfer bytes */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      expectedSequenceCnt;     /**< Block sequence counter             */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      currentSequenceCnt;      /**< Current Block sequence counter     */

/* Transfer block information */
V_MEMRAM0 static V_MEMRAM1 tBlockDescriptor     V_MEMRAM2      downloadBlockDescriptor;

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
V_MEMRAM0 static V_MEMRAM1 vuintx               V_MEMRAM2      platformWindowCnt;
#endif

#if defined( FBL_ENABLE_OTA )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2                    lastErasedBlock;
#endif /* FBL_ENABLE_OTA */

#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
# define FBLDIAG_RAM_START_SEC_VAR_NOINIT
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap*/
V_MEMRAM0 static V_MEMRAM1 tResumeState        V_MEMRAM2 blockResumeStates[kDiagNrOfResumeStates];
# define FBLDIAG_RAM_STOP_SEC_VAR_NOINIT
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap*/
#endif

/***********************************************************************************************************************
 *  Diagnostic handler function call table
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Subfunction table configuration
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** Sub-function defintion for Default Session (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_DefaultSession[] = { kDiagSubDefaultSession };
/** Sub-function defintion for Programming Session (02) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_ProgSession[] = { kDiagSubProgrammingSession };
/** Sub-function defintion for Extended Session (03) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_ExtendedSession[] = { kDiagSubExtendedDiagSession };

/** Sub-function definition for Diagnostic Session Control service (10) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableSessionControl[] =
{
   /* DefaultSession (01)*/
   {
      kFblDiagSubtableDsc_DefaultSession,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagDefaultSessionMainHandler
   },
   /* ProgrammingSession (02) */
   {
      kFblDiagSubtableDsc_ProgSession,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagProgrammingSessionMainHandler
   },
   /* ExtendedSession (03)*/
   {

      kFblDiagSubtableDsc_ExtendedSession,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagExtendedSessionMainHandler
   }
};

/** Sub-function definition for Hard Reset sub-function (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableEcuReset_HardReset[] = { kDiagSubHardReset };

/** Sub-function definition for ECU Reset service (11) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableEcuReset[] =
{
   /* Hard Reset (01) */
   {
      kFblDiagSubtableEcuReset_HardReset,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionProgramming|kFblDiagOptionSessionExtended|kFblDiagOptionFunctionalRequest),
      kDiagRqlEcuReset,
      (tFblDiagLengthCheck)0u,
      FblDiagEcuResetMainHandler
   }
};

/** Sub-function definition for Request Seed sub-function */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_Seed[] = { kDiagSubRequestSeed };
/** Sub-function definition for Send Key sub-function (configurable) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_Key[]  = { kDiagSubSendKey     };

/** Sub-function definition for Security Access service (27) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableSecAccess[] =
{
   /* Request Seed (11) */
   {
      kFblDiagSubtableSecAccess_Seed,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlSecurityAccessSeed,
      (tFblDiagLengthCheck)0u,
      FblDiagSecAccessSeedMainHandler
   }
   /* Send Key (12) */
  ,{
      kFblDiagSubtableSecAccess_Key,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      1u,
      FblDiagNoneLengthCheck,
      FblDiagSecAccessKeyMainHandler
   }
};

/** Sub-function definition for EnableRxAndEnableTx sub-function (00) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableCommControl_EnRxEnTx[]   = { kDiagSubEnableRxAndTx };
/** Sub-function definition for EnableRxAndDisableTx sub-function */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableCommControl_EnaRxDisTx[]   = { kDiagSubEnableRxAndDisableTx };

/** Sub-function defintion for Communication Control service (28) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableCommControl[] =
{
   /* Enable Rx and Tx (00) */
   {
      kFblDiagSubtableCommControl_EnRxEnTx,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlCommunicationControl,
      (tFblDiagLengthCheck)0u,
      FblDiagCommCtrlMainHandler
   }
   /* Enable Rx and Disable TX (01) */
  ,{
      kFblDiagSubtableCommControl_EnaRxDisTx,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlCommunicationControl,
      (tFblDiagLengthCheck)0u,
      FblDiagCommCtrlMainHandler
   }
};

/** Sub-function definition for write fingerprint data identifier (F15A) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtable_Write_Fingerprint[] = { kDiagWriteFingerprintIdHigh, kDiagWriteFingerprintIdLow   };
/** Sub-function definition for adjust ISO parameter data identifier (010B) */
#if (FBLCW_CHANGE_PARAMETER == STD_ON)
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtable_Write_IsoTpParam[]  = { kDiagWriteBlockSizeSTminHigh, kDiagWriteBlockSizeSTminLow };
#endif

V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtable_WriteDataById[] =
{
   /* Write Fingerprint (F15A) */
   {
      kFblDiagSubtable_Write_Fingerprint,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest|kFblDiagOptionSecuredService),
      kDiagRqlWriteDataByIdentifierFingerPrint,
      (tFblDiagLengthCheck)0u,
      FblDiagWriteFingerprintMainHandler,
   }
#if (FBLCW_CHANGE_PARAMETER == STD_ON)
   /* Adjust ISO BlockSize and STmin Parameter (010B) */
  ,{
      kFblDiagSubtable_Write_IsoTpParam,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlWriteDataByIdentifierIsoTpBlockSizeSTmin,
      (tFblDiagLengthCheck)0u,
      FblDiagWriteIsoTpBlockSizeSTminMainHandler,
   }
#endif /* (FBLCW_CHANGE_PARAMETER == STD_ON) */
};

/** Sub-function / RID definition for checksum verification (010202) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartChecksum[] = { kDiagSubStartRoutine, kDiagRoutineIdChecksumHigh, kDiagRoutineIdChecksumLow  };
/** Sub-function / RID definition for CheckReprogrammingPreconditions (010203) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartProgPrecond[] = { kDiagSubStartRoutine, kDiagRoutineIdCheckProgPrecondHigh, kDiagRoutineIdCheckProgPrecondLow  };
/** Sub-function / RID definition for ControlFailSafeReactions - Start (010204) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartCtrlFailSafeReaction[] = { kDiagSubStartRoutine, kDiagRoutineIdCFailSafeReactionHigh, kDiagRoutineIdCFailSafeReactionLow };
/** Sub-function / RID definition for ControlFailSafeReactions - Stop (020204) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StopCtrlFailSafeReaction[] = { kDiagSubStopRoutine,  kDiagRoutineIdCFailSafeReactionHigh, kDiagRoutineIdCFailSafeReactionLow };
/** Sub-function / RID definition for VerifyMemoryContent (010205) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartVerifyMemoryContent[] = { kDiagSubStartRoutine,  kDiagRoutineIdVerifyMemoryContentHigh, kDiagRoutineIdVerifyMemoryContentLow };
/** Sub-function / RID definition for PrepareVehicleSystemsForReprogramming (010206) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartPrepVehicleSystForReprog[] = { kDiagSubStartRoutine,  kDiagRoutineIdPrepVecicleSystForReprogHigh, kDiagRoutineIdPrepVecicleSystForReprogLow };
/** Sub-function / RID definition for PreCheckProgrammingDependencies (010207) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartPreChkProgDepend[] = { kDiagSubStartRoutine,  kDiagRoutineIdPreChkProgDependHigh, kDiagRoutineIdPreChkProgDependLow };
/** Sub-function / RID definition for EraseMemory (01FF00) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartErase[] = { kDiagSubStartRoutine, kDiagRoutineIdEraseMemoryHigh, kDiagRoutineIdEraseMemoryLow     };
/** Sub-function / RID definition for CheckProgrammingDependencies (01FF01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartChkProgDep[] = { kDiagSubStartRoutine, kDiagRoutineIdCheckProgDepHigh, kDiagRoutineIdCheckProgDepLow  };

V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableRC[] =
{
   /* CheckMemory (010202) */
   {
      kFblDiagSubtableRC_StartChecksum,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest|kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlCheckRoutine,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCsumMainHandler
   },
   /* CheckProgrammingPreconditions (010203) */
   {
      kFblDiagSubtableRC_StartProgPrecond,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlChkProgPrecond,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCheckProgPrecondMainHandler
   },
   /* ControlFailSafeReactions - Start (010204) */
   {
      kFblDiagSubtableRC_StartCtrlFailSafeReaction,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlFailSafeReactStart,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCtrlFailSafeReactionMainHandler
   },
   /* ControlFailSafeReactions - Stop (020204) */
   {
      kFblDiagSubtableRC_StopCtrlFailSafeReaction,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlFailSafeReactStop,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStopCtrlFailSafeReactionMainHandler
   },
   /* VerifyMemoryContent (010205) */
   {
      kFblDiagSubtableRC_StartVerifyMemoryContent,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlVerifyMemoryContent,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartVerifyMemoryContentMainHandler
   },
   /* PrepareVehicleSystemsForReprogramming (010206) */
   {
      kFblDiagSubtableRC_StartPrepVehicleSystForReprog,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlPrepVehicleSystForReprog,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartPrepVehicleSystForReprogMainHandler
   },
   /* PreCheckProgrammingDependencies (010207) */
   {
      kFblDiagSubtableRC_StartPreChkProgDepend,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlPreChkProgDepend,
      FblDiagNoneLengthCheck,
      FblDiagRCStartPreChkProgDependMainHandler
   },
   /* EraseMemory (01FF00) */
   {
      kFblDiagSubtableRC_StartErase,
      (kFblDiagOptionSecuredService|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlEraseRoutine,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartEraseMainHandler
   },
   /* CheckProgrammingDependencies (01FF01) */
   {
      kFblDiagSubtableRC_StartChkProgDep,
      (kFblDiagOptionSecuredService|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineCheckComptDependencies,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCheckComptDependenciesMainHandler
   }
};

 /** Sub-function definition for Zero sub-function (00) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableTesterPresent_ZeroSubfunction[] = { kDiagSubTesterPresent      };

/** Sub-function definition for Tester Present service (3E) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableTesterPresent[] =
{
   /* Zero sub-function (00) */
   {
      kFblDiagSubtableTesterPresent_ZeroSubfunction,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlTesterPresent,
      (tFblDiagLengthCheck)0u,
      FblDiagTesterPresentMainHandler
   }
};

/** Sub-function definition for Control DTC - On sub-function (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableControlDtc_OnSubfunction[]  = { kDiagSubDtcOn  };
/** Sub-function definition for Control DTC - Off sub-function (02) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableControlDtc_OffSubfunction[] = { kDiagSubDtcOff };

V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableControlDtc[] =
{
   /* On sub-function (01) */
   {
      kFblDiagSubtableControlDtc_OnSubfunction,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlControlDTCSetting,
      (tFblDiagLengthCheck)0u,
      FblDiagControlDTCMainHandler
   }
   /* Off sub-function (02) */
  ,{
      kFblDiagSubtableControlDtc_OffSubfunction,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlControlDTCSetting,
      (tFblDiagLengthCheck)0u,
      FblDiagControlDTCMainHandler
   }
};

/***********************************************************************************************************************
 *  Main service table configuration
 **********************************************************************************************************************/

/** Table of supported diagnostic servcies */
V_MEMROM0 V_MEMROM1 tFblDiagServiceTable V_MEMROM2 kFblDiagServiceTable[] =
{
   /*Diagnostic Session Control (10) */
   {
      kDiagSidDiagnosticSessionControl,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionServiceIsSubfunction|kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableSessionControl),
      ARRAY_SIZE(kFblDiagSubtableDsc_DefaultSession),
      kFblDiagSubtableSessionControl,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagSessionControlPostHandler
   },
   /* EcuReset (11) */
   {
      kDiagSidEcuReset,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionServiceIsSubfunction|kFblDiagOptionFunctionalRequest),
      kDiagRqlEcuReset,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableEcuReset),
      ARRAY_SIZE(kFblDiagSubtableEcuReset_HardReset),
      kFblDiagSubtableEcuReset,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* ReadDataByIdentifier (0x22) */
   {
      kDiagSidReadDataByIdentifier,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlReadDataByIdentifier,
      FblDiagNoneLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagReadDataByIdMainHandler,
      FblDiagProcessSubparamNrc,
      FblDiagDefaultPostHandler
   },
   /* SecurityAccess (27) */
   {
      kDiagSidSecurityAccess,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest|kFblDiagOptionServiceIsSubfunction),
      kDiagRqlSecurityAccessSeed,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableSecAccess),
      ARRAY_SIZE(kFblDiagSubtableSecAccess_Seed),
      kFblDiagSubtableSecAccess,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* CommunicationControl (28) */
   {
      kDiagSidCommunicationControl,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionServiceIsSubfunction|kFblDiagOptionFunctionalRequest),
      kDiagRqlCommunicationControl,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableCommControl),
      ARRAY_SIZE(kFblDiagSubtableCommControl_EnRxEnTx),
      kFblDiagSubtableCommControl,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* WriteDataByIdentifier (2E) */
   {
      kDiagSidWriteDataByIdentifier,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionFunctionalRequest),
      kDiagRqlMinWriteDataByIdentifier,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtable_WriteDataById),
      ARRAY_SIZE(kFblDiagSubtable_Write_Fingerprint),
      kFblDiagSubtable_WriteDataById,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubparamNrc,
      FblDiagDefaultPostHandler
   },
   /* RoutineControl (31) */
   {
      kDiagSidRoutineControl,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionServiceIsSubfunction|kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControl,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableRC),
      ARRAY_SIZE(kFblDiagSubtableRC_StartChecksum),
      kFblDiagSubtableRC,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessRoutineNrc,
      FblDiagDefaultPostHandler
   },
   /* RequestDownload (34) */
   {
      kDiagSidRequestDownload,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionSecuredService|kFblDiagOptionFunctionalRequest),
      kDiagRqlRequestDownloadMemSize,
      FblDiagNoneLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagRequestDownloadMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* TransferData (36) */
   {
      kDiagSidTransferData,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionSecuredService|kFblDiagOptionFunctionalRequest),
      (kDiagRqlTransferData + 1u),
      FblDiagNoneLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagTransferDataMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* RequestTransferExit (37) */
   {
      kDiagSidRequestTransferExit,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionSecuredService|kFblDiagOptionFunctionalRequest),
      kDiagRqlRequestTransferExit,
      FblDiagNoneLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagReqTransferExitMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* TesterPresent (3E) */
   {
      kDiagSidTesterPresent,
      (kFblDiagOptionSessionDefault|kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionServiceIsSubfunction|kFblDiagOptionFunctionalRequest),
      kDiagRqlTesterPresent,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableTesterPresent),
      ARRAY_SIZE(kFblDiagSubtableTesterPresent_ZeroSubfunction),
      kFblDiagSubtableTesterPresent,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* ControlDTCSetting (85) */
   {
      kDiagSidControlDTCSetting,
      (kFblDiagOptionSessionExtended|kFblDiagOptionSessionProgramming|kFblDiagOptionServiceIsSubfunction|kFblDiagOptionFunctionalRequest),
      kDiagRqlControlDTCSetting,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableControlDtc),
      ARRAY_SIZE(kFblDiagSubtableControlDtc_OnSubfunction),
      kFblDiagSubtableControlDtc,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   }
};

/** Size of service table */
V_MEMROM0 V_MEMROM1 vuintx V_MEMROM2 kSizeOfServiceTable = ARRAY_SIZE(kFblDiagServiceTable);

#define FBLDIAG_STOP_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  FblDiagDownloadCheck
 **********************************************************************************************************************/
/*! \brief       Verify the downloaded flashware.
 *  \details     Uses the configured security module to verify if the download has been done correctly and
 *               the data is allowed to be downloaded. Also calculates CRC total if enabled.
 *  \pre         Logical block or flash driver has to be downloaded completely.
 *  \param[in]   pbDiagData Pointer to data in the diagBuffer (without SID).
 *  \param[in]   diagReqDataLen Length of data (without SID).
 *  \return      Verification result supplied by the security module.
 **********************************************************************************************************************/
/* PRQA S 6010, 6030 1 */  /* MD_MSR_STPTH */
static tFblResult FblDiagDownloadCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblMemBlockVerifyData verifyData;
   tFblMemVerifyStatus  verifyErrorCode;
   tFblResult result;
   vuint8 crcWrittenBuffer[kSecCRCSize];
   vuintx idx;
#if defined( SEC_ENABLE_CRC_TOTAL )
   vuint8 crcTotalBuffer[kSecCRCSize];
#endif
   vuint8 const * expectedCrc = &pbDiagData[kDiagLocFmtRoutineOption + SEC_VERIFY_CLASS_CCC_VERIFY_SIZE + kSecLenInfoLength];

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   result = kFblOk;

   /* Initialize verification parameter structure */
   verifyParam.crcTotal = 0u;

#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   verifyData.verifyDataPipe.length = kSecCRCSize;
   verifyData.verifyDataPipe.data = crcWrittenBuffer;

   verifyData.verifyDataOutput.length  = 0u;
   verifyData.verifyDataOutput.data    = (V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *)V_NULL;
#else
   /* Pipelined verification not supported */
   verifyData.verifyDataPipe.length = 0u;
   verifyData.verifyDataPipe.data   = (V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *)V_NULL;

   /* CRC check is performed on programmed data */
   verifyData.verifyDataOutput.length  = kSecCRCSize;
   verifyData.verifyDataOutput.data    = crcWrittenBuffer;

#endif
#if defined( FBL_MEM_ENABLE_VERIFY_INPUT )
   /* Signature verification is performed on input data */
   verifyData.verifyDataInput.length   = kSecSigSize;
   verifyData.verifyDataInput.data     = &pbDiagData[kDiagLocFmtRoutineOption + SEC_VER_SIG_OFFSET ];
#endif
#if defined( FBL_MEM_ENABLE_VERIFY_PROCESSED )
   /* Signature verification is performed on processed data */
   verifyData.verifyDataProcessed.length  = kSecSigSize;
   verifyData.verifyDataProcessed.data    = &pbDiagData[kDiagLocFmtRoutineOption + SEC_VER_SIG_OFFSET];
#endif
   /* Handle LibMem state flags and perform state checks */
   if (FblMemBlockVerify(&verifyData, &verifyErrorCode) != kFblMemStatus_Ok)
   {
      if (verifyErrorCode == SECM_OK)
      {
         /* If no verification error code is provided, return general error */
         verifyErrorCode = SECM_VER_ERROR;
      }
   }

   if (verifyErrorCode == SECM_OK)
   {
      /* Compare calculated CRC with expected one */
      for (idx = 0u; idx < kSecCRCSize; idx++)
      {
         if (crcWrittenBuffer[idx] != expectedCrc[idx])
         {
            verifyErrorCode = SECM_VER_CRC;
            break;
         }
      }
   }

   /* Write CRC calculated over written data to NVM */
   if (kFblOk != ApplFblCRCWrittenValueWrite(downloadBlockDescriptor, crcWrittenBuffer))
   {
      verifyErrorCode = SECM_VER_ERROR;
   }

#if defined( FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC )
   if (verifyErrorCode == SECM_OK)
   {
      /* Trigger calculation of OFR light CMAC and writing of CMAC to NVM */
# if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
      if (kFblOk != ApplFblOutputCalculateOfrLightCmac(downloadBlockDescriptor.blockNr, &verifyParam))
      {
         verifyErrorCode = SECM_VER_ERROR;
      }
# else /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
      if (kFblOk != ApplFblPipelinedFinalizeOfrLightCmac(downloadBlockDescriptor.blockNr))
      {
         verifyErrorCode = SECM_VER_ERROR;
      }
# endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
   }
#endif /* FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC */
   pbDiagData[kDiagLocFmtRoutineStatus] = verifyErrorCode;

   /* Check results */
   if (verifyErrorCode != SECM_OK)
   {
      /* Reprogramming process state, memory check not successful */
      SetReprogProcessState(fingerprintStatus, kDiagFpStatMemCheckFailed);
      (void)ApplFblWriteFpStatusInfo(downloadBlockDescriptor, &fingerprintStatus);

      result = kFblFailed;
   }

   if (result == kFblOk)
   {
#if defined( SEC_ENABLE_CRC_TOTAL )
      /* Store CRC total in nv-memory. */
      FblMemSetInteger(sizeof(SecM_CRCType), verifyParam.crcTotal, crcTotalBuffer);
      (void)ApplFblCRCTotalValueWrite(downloadBlockDescriptor, crcTotalBuffer);
#endif
      /* Call validation function, set logical block validity  */
      result = ApplFblValidateBlock(downloadBlockDescriptor);
      if (result == kFblOk)
      {
         /* Generate CMAC of currently downloaded block */
         result = ApplFblUpdateBlockMac(&downloadBlockDescriptor, &verifyParam.segmentList);
      }

      if (result == kFblOk)
      {
         result = ApplFblWriteSegmentList(downloadBlockDescriptor.blockNr, &verifyParam.segmentList);
      }

      if (result != kFblOk)
      {
         /* Return verification status in routineStatus   */
         pbDiagData[kDiagLocFmtRoutineStatus] = kDiagCheckVerificationFailed;
      }
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
      /* With the successful verification the previous resume information can be discarded */
      for (idx = 0u; idx < kDiagNrOfResumeStates; idx++)
      {
         FblMemInvalidateSnapshot(blockResumeStates[idx].libMemSnapshot, FBL_MEM_SNAPSHOT_SIZE(SWM_DATA_MAX_NOAR));
         FblMemInvalidateSnapshot(blockResumeStates[idx].secModSnapshot, kFblDiagSecSnapshotSize);
# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
         FblMemInvalidateSnapshot(blockResumeStates[idx].secModPipeSnapshot, kDiagSecPipeSnapshotSize);
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */
      }
#endif   /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
   }

   return result;
}

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
/***********************************************************************************************************************
 *  FblDiagGetEraseState
 **********************************************************************************************************************/
/*! \brief       This function checks if the current logical block is erased.
 *  \details     If the memoryStatus flag of fingerprint status indicates
 *               "erased", an additional user callback is called in order to
 *               make sure, that the erase routine actually can be omitted.
 *  \return      kFlashErased if block is already erased, kFlashNotErased if block is not erased
 **********************************************************************************************************************/
static tFlashStatus FblDiagGetEraseState( void )
{
   tFlashStatus status;

   status = kFlashNotErased;

   /* Check if the memory status flag indicates "erased" */
   if (ApplFblReadFpStatusInfo(downloadBlockDescriptor, &fingerprintStatus) == kFblOk)
   {
      if ((fingerprintStatus & kDiagFpStatMemErased) == kDiagFpStatMemErased )
      {
         /* Invoke callback */
         status = ApplFblGetBlockErased(downloadBlockDescriptor);
      }
   }
   return status;
}
#endif   /* FBL_ENABLE_FLASH_ERASED_DETECTION */

/***********************************************************************************************************************
 *  FblDiagInitMemDriver
 **********************************************************************************************************************/
/*! \brief       Copy memory driver(s) into RAM and perform intializations
 *  \pre         Memory drivers are availale in ROM
 *  \return      Verification result supplied by the security module.
 **********************************************************************************************************************/
static tFblResult FblDiagInitMemDriver(void)
{
   IO_ErrorType flashErrorCode;
   tFblResult   result;

   /* Existing flashCode is no longer valid */
   FblDiagClrMemDriverInitialized();

   /* Turn on programming voltage (if necessary) */
   ApplFblSetVfp();

   /* Copy memory driver code into RAM buffer */
   FblCwSetOfflineMode();
   flashErrorCode = MemDriver_InitSync(V_NULL);
   FblCwSetOnlineMode();

   if (flashErrorCode != IO_E_OK)
   {
      /* Memory driver initialization failure */
      FblErrStatSetFlashDrvVersion();
      FblErrStatSetError(FBL_ERR_FLASHCODE_INIT_FAILED);
      FblErrStatSetFlashDrvError(flashErrorCode);
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
   else
   {
      /* Set Memory driver initialization flag */
      FblDiagSetMemDriverInitialized();
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagBlockStartIndication
 **********************************************************************************************************************/
/*! \brief       Indicate start of a new block (just before first segment)
 *  \details     Block may consist of one or more segments
 *  \pre         FblMemInitPowerOn executed before
 *  \param[in]   blockNr Logical block number
 *  \return      Result of operation
 **********************************************************************************************************************/
static tFblResult FblDiagBlockStartIndication(vuint8 blockNr)
{
   tFblResult result;
   tFblDiagNrc libMemResult;
   tFblMemBlockInfo blockInfo;
   tBlockDescriptor blockDescriptor;

   result = FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor);

   if (result == kFblOk)
   {
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
      blockInfo.verifyRoutineOutput.function = (tFblMemVerifyFctOutput)blockDescriptor.verifyOutput;  /* PRQA S 0313 */ /* MD_FblDiagOem_0313 */
      blockInfo.verifyRoutineOutput.param    = (V_MEMRAM1 tFblMemVerifyParamOutput V_MEMRAM2 V_MEMRAM3 *)&verifyParam;
#else
      blockInfo.verifyRoutineOutput.function = (tFblMemVerifyFctOutput)V_NULL;
      blockInfo.verifyRoutineOutput.param    = (V_MEMRAM1 tFblMemVerifyParamOutput V_MEMRAM2 V_MEMRAM3 *)V_NULL;
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */

#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
      /* Configure pipelined verification */
# if defined( FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC )
      /* PRQA S 0313 1 */ /* MD_FblDiagOem_0313 */
      blockInfo.verifyRoutinePipe.function = FblDiagOfrLightWrapper;
# else /* FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC */
      /* PRQA S 0313 1 */ /* MD_FblDiagOem_0313 */
      blockInfo.verifyRoutinePipe.function = (tFblMemVerifyFctInput)blockDescriptor.verifyPipelined;
# endif /* FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC */
      blockInfo.verifyRoutinePipe.param = (V_MEMRAM1 tFblMemVerifyParamInput V_MEMRAM2 V_MEMRAM3 *)&pipeSigParam;
      /* Force use of internal workspace */
      pipeSigParam.currentHash.sigResultBuffer = (SecM_ResultBufferType)0u;
      pipeSigParam.currentHash.length = SEC_DEFAULT_WORKSPACE_SIZE;
      pipeSigParam.currentDataLength = &pipeSigDataLength;
#else
      /* Pipelined verification not supported */
      blockInfo.verifyRoutinePipe.function   = (tFblMemVerifyFctInput)V_NULL;
      blockInfo.verifyRoutinePipe.param      = (V_MEMRAM1 tFblMemVerifyParamInput V_MEMRAM2 V_MEMRAM3 *)V_NULL;
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */
#if defined( FBL_MEM_ENABLE_VERIFY_INPUT )
      blockInfo.verifyRoutineInput.function  = (tFblMemVerifyFctInput)blockDescriptor.verifyInput; /* PRQA S 0313 */ /* MD_FblDiagOem_0313 */
      blockInfo.verifyRoutineInput.param     = &sigParam;
#else
      blockInfo.verifyRoutineInput.function  = (tFblMemVerifyFctInput)V_NULL;
      blockInfo.verifyRoutineInput.param     = (V_MEMRAM1 tFblMemVerifyParamInput V_MEMRAM2 V_MEMRAM3 *)V_NULL;
#endif
#if defined( FBL_MEM_ENABLE_VERIFY_PROCESSED )
      blockInfo.verifyRoutineProcessed.function  = (tFblMemVerifyFctInput)blockDescriptor.verifyProcessed; /* PRQA S 0313 */ /* MD_FblDiagOem_0313 */
      blockInfo.verifyRoutineProcessed.param     = &sigParam;
#else
      blockInfo.verifyRoutineProcessed.function  = (tFblMemVerifyFctInput)V_NULL;
      blockInfo.verifyRoutineProcessed.param     = (V_MEMRAM1 tFblMemVerifyParamInput V_MEMRAM2 V_MEMRAM3 *)V_NULL;
#endif

      /* Download segment information */
      verifyParam.segmentList.segmentInfo = downloadSegmentList;

      blockInfo.segmentList = &verifyParam.segmentList;
      blockInfo.maxSegments = SWM_DATA_MAX_NOAR;

      /* Specify reader function for ROM/Flash data */
      blockInfo.readFct = (tFblMemVerifyReadFct)FblReadProm;

      blockInfo.targetAddress = downloadBlockDescriptor.blockStartAddress;
      blockInfo.targetLength = downloadBlockDescriptor.blockLength;
      blockInfo.logicalAddress = downloadBlockDescriptor.blockStartAddress;
      blockInfo.logicalLength = downloadBlockDescriptor.blockLength;

      sigKeyParam.size = ApplFblReadVerificationKey(sigKeyBuf);
      if (sigKeyParam.size > 0u)
      {
         /* Replace the original key */
         sigKeyParam.data = sigKeyBuf;
         sigParam.key = (SecM_VerifyKeyType)(&sigKeyParam); /* PRQA S 0314 */ /* MD_FblDiagOem_0314_Key */
      }
      /* Indicate the start of flash driver- or log. block download */
      libMemResult = FblMemRemapStatus(FblMemBlockStartIndication(&blockInfo));
      /* Check if FblLib_Mem reported an error */
      if (libMemResult != kDiagErrorNone)
      {
         /* Segment counter has already been increased - set back to old value */
         FblDiagRestoreSegmentCnt();

         FblDiagSetError(libMemResult);
         result = kFblFailed;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagSegmentStartIndication
 **********************************************************************************************************************/
/*! \brief      Indicate start of a new segment
 *  \details    Prepare segment structure and call LibMem
 *              Update verification with logical address and length if configured
 *              Initialize data processing if configured
 *  \pre        FblMemBlockStartIndication executed before
 *  \param[in]  pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]  transferAddrParam Transfer address parameter of RequestDownload service
 *  \return     kFblOk: function processed successfully, kFblFailed: Failure occured during processing.
 **********************************************************************************************************************/
static tFblResult FblDiagSegmentStartIndication(const vuint8 *pbDiagData, tFblAddress transferAddParam )
{
   tFblMemSegmentInfo currentSegment;
   tFblResult result;

   currentSegment.dataFormat     = pbDiagData[kDiagLocFmtSubparam];
   currentSegment.targetLength   = transferRemainder;
   currentSegment.logicalLength  = transferRemainder;

   (void)FblDiagSegmentNext();

   /* Initialize error status address */
   FblErrStatSetAddress(transferAddParam);

   /* Store address information of requestDownload for signature verification */
   currentSegment.targetAddress  = transferAddParam;
   currentSegment.type           = kFblMemType_ROM;
   currentSegment.logicalAddress = transferAddParam;

   /* Indicate start of new segment */
   result = FblMemRemapStatus(FblMemSegmentStartIndication(&currentSegment));
   if (result != kDiagErrorNone)
   {
      /* Segment counter has already been increased - set back to old value */
      FblDiagRestoreSegmentCnt();

      FblDiagSetError(result);
      result = kFblFailed;
   }
   else
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  ROUTINES TO MANAGE DIAGNOSTIC SERVICES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagSessionControlParamInit
 **********************************************************************************************************************/
/*! \brief         Initialization of session control request response.
 *  \param[in,out] pbDiagData Pointer to data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 **********************************************************************************************************************/
static void FblDiagSessionControlParamInit(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

#if defined( FBL_ENABLE_PIPELINED_PROGRAMMING )
   if (FblMemTaskIsPending())
   {
      FblMemTask();
   }
#endif

   /* Reset internal states */
   FblDiagClrPreconditionsChecked();
   FblDiagClrSecurityKeyAllowed();
   FblDiagClrSecurityUnlock();
   FblDiagClrFingerprintValid();
   FblDiagClrMemDriverInitialized();
   FblDiagClrEraseSucceeded();
   FblDiagClrTransferDataAllowed();
   FblDiagClrTransferDataSucceeded();
   FblDiagClrCheckMemoryAllowed();

   transferRemainder = 0u;

#if defined( FBL_ENABLE_OTA )
   lastErasedBlock = kBlockNrInvalid;
#endif /* FBL_ENABLE_OTA */

   /* Initialize security module */
   (void)ApplFblSecurityInit();

   /* Diagnostic session timing */
   pbDiagData[kDiagLocFmtSubparam + 1u] = (vuint8)((kDiagSessionTimingP2 >> 8u) & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 2u] = (vuint8)(kDiagSessionTimingP2 & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 3u] = (vuint8)((kDiagSessionTimingP2Star >> 8u) & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 4u] = (vuint8)(kDiagSessionTimingP2Star & 0xFFu);

   /* Disable tester present timeout monitoring */
   StopTesterTimeout();
}

/***********************************************************************************************************************
 *  FblDiagOemInit
 **********************************************************************************************************************/
/*! \brief       Initialize module variables
 **********************************************************************************************************************/
void FblDiagOemInit(void)
{
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   tFblAddress tmpAddress;
   vuintx idx;

# if defined ( FBL_ENABLE_STATUS_BACKUP )
   (void)ApplFblRestoreStatus(blockResumeStates, sizeof(blockResumeStates));  /* PRQA S 0315 */ /* MD_FblDiagOem_0315 */
# endif
   /*
    * After PowerOn/Reset, resume status information is initialized only if no resume information of a
    * previously interrupted download is available.
    */
   for (idx = 0u; idx < kDiagNrOfResumeStates; idx++)
   {
      if(   (blockResumeStates[idx].resumeStatus != kFblRsBlockErased)
         && (blockResumeStates[idx].resumeStatus != kFblRsMemoryChecked))
      {
         if (FblDiagGetSnapshotInfo( &tmpAddress ) != kFblOk )
         {
            FblDiagInitBlockResume(0u, &blockResumeStates[idx]);
         }
      }
   }
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

   expectedSequenceCnt = 0u;

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
   /* Open time window for platform message reception */
   FblDiagSetPlatformMsgWindow();
   platformWindowCnt = FBL_START_DELAY;

   /* Lock buffer to avoid diag communication while identity could be switched */
   FblDiagSetBufferLocked();
#endif
}

#if defined( FBL_DIAG_ENABLE_OEM_DEINIT )
/***********************************************************************************************************************
 *  FblDiagOemDeinit
 **********************************************************************************************************************/
/*! \brief       Do de-initialzations after shutdown request
 **********************************************************************************************************************/
void FblDiagOemDeinit(void)
{
# if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
#  if defined ( FBL_ENABLE_STATUS_BACKUP )
   (void)ApplFblSaveStatus(blockResumeStates, sizeof(blockResumeStates));  /* PRQA S 0315 */ /* MD_FblDiagOem_0315 */
#  endif
# endif  /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
}
#endif /* FBL_DIAG_ENABLE_OEM_DEINIT  */

#if defined( FBL_DIAG_ENABLE_OEM_SPS_REQUEST )
/***********************************************************************************************************************
*  FblDiagOemPrepareSpsRequest
**********************************************************************************************************************/
/*! \brief      Starts programming session if the Bootloader is called from the application.
*  \details     This function prepares a programming session request and starts the diagnostic processing
*               of this request after the real request has been received by the application software. The suppress
*               positive response bit is set so that no positive response is sent by the service handler. The positive
*               response needs to be sent before the transition to bootloader.
*  \param[out]  pDiagBuffer Pointer to DiagBuffer
*  \param[out]  pDiagDataLength Size of programming session request in DiagBuffer [bytes]
**********************************************************************************************************************/
void FblDiagOemPrepareSpsRequest(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pDiagBuffer, V_MEMRAM1 tCwDataLengthType V_MEMRAM2 V_MEMRAM3 *pDiagDataLength)
{
   /* Prepare DiagBuffer for DiagnosticSessionControl service, do not sent positive response */
   pDiagBuffer[kDiagFmtSubparam] = (kDiagSubProgrammingSession | kDiagSuppressPosRspMsgIndicationBit);
   *pDiagDataLength = kDiagRqlDiagnosticSessionControl;
}
#endif /* FBL_DIAG_ENABLE_OEM_SPS_REQUEST */

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
/***********************************************************************************************************************
 *  FblDiagOemTimerTask
 **********************************************************************************************************************/
/*! \brief       This function handles the FBL Bootloader timeout
 *  \details     When a timeout occurs the application is started.
 **********************************************************************************************************************/
void FblDiagOemTimerTask(void)
{
   /* Check if timer should be decremented */
   if (platformWindowCnt > 0u)
   {
      platformWindowCnt--;
      if (platformWindowCnt == 0u)
      {
         /* Unlock buffer to enable diagnostic communication */
         FblDiagClrBufferLocked();

         /* Time expired, platform message is no longer accepted */
         FblDiagClrPlatformMsgWindow();
      }
   }
}
#endif /* FBL_ENABLE_MULTIPLE_PLATFORMS */

/***********************************************************************************************************************
 *  FblDiagProcessServiceNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done in CheckSubServiceTable() are mapped to NRCs in this function. This function is
 *               called for services with sub functions.
 *  \pre         Service available (serviceInfo initialized)
 *  \param[in]   ServiceErrorMask Mask with error indication for correct NRC
 *  \return      Always kFblOk
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblDiagProcessServiceNrc(vuint32 serviceErrorMask)
{
   /* Session support check */
   if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
   {
      DiagNRCServiceNotSupportedInActiveSession();
   }
   /* Security access on service level */
   else if ((serviceErrorMask & kFblDiagServiceSecAccessFailure) == kFblDiagServiceSecAccessFailure)
   {
      DiagNRCSecurityAccessDenied();
   }
   /* Minimum length check */
   else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
   }
   /* Condition check failed */
   else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
   {
      /* Set NRC here if no NRC has been set in user callback function. */
      if (DiagGetError() == kDiagErrorNone)
      {
         DiagNRCConditionsNotCorrect();
      }
   }
   /* Remaining, uncovered errors */
   else
   {
      DiagNRCGeneralReject();
   }

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagProcessSubfunctionNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done in CheckSubServiceTable() are mapped to NRCs in this function. This function is
 *               called for services with sub functions.
 *  \pre         Service available (serviceInfo initialized)
 *  \param[in]   ServiceErrorMask Mask with error indication for correct NRC
 *  \return      Always kFblOk
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
static tFblResult FblDiagProcessSubfunctionNrc(vuint32 serviceErrorMask)
{
   /* Check service level */
   /* Session support check */
   if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
   {
      DiagNRCServiceNotSupportedInActiveSession();
   }
   /* Security access on service level */
   else if ((serviceErrorMask & kFblDiagServiceSecAccessFailure) == kFblDiagServiceSecAccessFailure)
   {
      DiagNRCSecurityAccessDenied();
   }
   /* Minimum length check */
   else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
   }
   /* Check subfunction level */
   else if ((serviceErrorMask &  kFblDiagSubfunctionNotFound) == kFblDiagSubfunctionNotFound)
   {
      /* Failure returned, but no error set. */
      /* Means, subfunction not supported.   */
#if defined( FBL_ENABLE_USERSUBFUNCTION )
      /* Subfunction not found in check
       * Call user handler to manage its own subfunction */
      FblDiagSetRcrRpAllowed();

      /* Call user handler to manage its own subfunction */
      ApplDiagUserSubFunction(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
      /* Subfunction not supported */
      DiagNRCSubFunctionNotSupported();
#endif
   }
   else if ((serviceErrorMask & kFblDiagSubfuncSessionFailure) == kFblDiagSubfuncSessionFailure)
   {
      /* For subfunctions send 0x7E */
      DiagNRCSubfunctionNotSupportedInActiveSession();
   }
   else if ((serviceErrorMask & kFblDiagSubfuncSecAccessFailure) == kFblDiagSubfuncSecAccessFailure)
   {
      /* Security level not correct */
      DiagNRCSecurityAccessDenied();
   }
   else if ((serviceErrorMask & kFblDiagSubparamNotFound) == kFblDiagSubparamNotFound)
   {
      /* Subfunction not supported. */
      DiagNRCRequestOutOfRange();
   }
   /* Pending length checks */
   else if ((serviceErrorMask & (kFblDiagServiceLenFailure | kFblDiagSubMinLenFailure | kFblDiagSubLenFailure)) != 0u)
   {
      /* Length is incorrect. Set neg. response and exit */
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
   }
   /* Condition check failed */
   else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
   {
      /* Set NRC here if no NRC has been set in user callback function. */
      if (DiagGetError() == kDiagErrorNone)
      {
         DiagNRCConditionsNotCorrect();
      }
   }
   /* Remaining, uncovered errors */
   else
   {
      DiagNRCGeneralReject();
   }

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagProcessSubparamNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done in CheckSubServiceTable() are mapped to NRCs in this function. This function is
 *               called for services with sub parameters.
 *  \pre         Service available (serviceInfo initialized)
 *  \param[in]   ServiceErrorMask Mask with error indication for correct NRC
 *  \return      Always kFblOk
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static tFblResult FblDiagProcessSubparamNrc(vuint32 serviceErrorMask)
{
   /* Check service level */
   /* Session support check */
   if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
   {
      DiagNRCServiceNotSupportedInActiveSession();
   }
   /* Minimum length check */
   else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
   }
   /* Security access on service level */
   else if ((serviceErrorMask & kFblDiagServiceSecAccessFailure) == kFblDiagServiceSecAccessFailure)
   {
      DiagNRCSecurityAccessDenied();
   }
   /* Check for services with subparameters (e.g. WDBID) */
   /* Now processing the individual errors */
   else if ((serviceErrorMask & kFblDiagSubLenFailure) == kFblDiagSubLenFailure)
   {
      /* Length is incorrect. Set neg. response and exit */
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
   }
   else if ((serviceErrorMask & kFblDiagSubfuncSessionFailure) == kFblDiagSubfuncSessionFailure)
   {
      /* Session failure or not a subfunction -> send ROOR. */
      DiagNRCRequestOutOfRange();
   }
   else if ((serviceErrorMask & kFblDiagSubparamNotFound) == kFblDiagSubparamNotFound)
   {
#if defined( FBL_ENABLE_USERSUBFUNCTION )
      /* Subfunction not found in check
       * Call user handler to manage its own subfunction */
      FblDiagSetRcrRpAllowed();

      /* Call user handler to manage its own subfunction */
      ApplDiagUserSubFunction(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
      /* Not a subfunction -> send ROOR. */
      DiagNRCRequestOutOfRange();
#endif
   }
   else if ((serviceErrorMask & kFblDiagSubfuncSecAccessFailure) == kFblDiagSubfuncSecAccessFailure)
   {
      DiagNRCSecurityAccessDenied();
   }
   /* Condition check failed */
   else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
   {
      /* Set NRC here if no NRC has been set in user callback function. */
      if (DiagGetError() == kDiagErrorNone)
      {
         DiagNRCConditionsNotCorrect();
      }
   }
   else
   {
      /* Failure returned, but no error set. */
      /* Means, subfunction not supported.   */

      /* Not a subfunction -> send ROOR. */
      DiagNRCRequestOutOfRange();
   }

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagProcessRoutineNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done in CheckSubServiceTable() are mapped to NRCs in this function. This function is
 *               called for services with sub functions.
 *  \pre         Service available (serviceInfo initialized)
 *  \param[in]   ServiceErrorMask Mask with error indication for correct NRC
 *  \return      Always kFblOk
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
static tFblResult FblDiagProcessRoutineNrc(vuint32 serviceErrorMask)
{
   /* Check service level */
   /* Session support check */
   if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
   {
      DiagNRCServiceNotSupportedInActiveSession();
   }
   /* Security access on service level */
   else if ((serviceErrorMask & kFblDiagServiceSecAccessFailure) == kFblDiagServiceSecAccessFailure)
   {
      DiagNRCSecurityAccessDenied();
   }
   /* Minimum length check */
   else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
   }
   /* Check if sub-parameter is supported */
   else if ((serviceErrorMask & kFblDiagSubparamNotFound) == kFblDiagSubparamNotFound)
   {
#if defined( FBL_ENABLE_USERSUBFUNCTION )
      /* Subfunction not found in check
         * Call user handler to manage its own subfunction */
      FblDiagSetRcrRpAllowed();

      /* Call user handler to manage its own subfunction */
      ApplDiagUserSubFunction(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
      DiagNRCRequestOutOfRange();
#endif
   }

   /* Check if RID is supported in active session */
   else if((serviceErrorMask & kFblDiagSubparamSessionFailure) == kFblDiagSubparamSessionFailure)
   {
      DiagNRCRequestOutOfRange();
   }
   /* Check for security access (RID level) */
   else if ((serviceErrorMask & kFblDiagSubparamSecAccessFailure) == kFblDiagSubparamSecAccessFailure)
   {
      DiagNRCSecurityAccessDenied();
   }
   /* Check if sub-function is supported */
   else if ((serviceErrorMask & (kFblDiagSubfunctionNotFound | kFblDiagSubTableNotFound)) != 0u)
   {
#if defined( FBL_ENABLE_USERSUBFUNCTION )
      /* Subfunction not found in check
         * Call user handler to manage its own subfunction */
      FblDiagSetRcrRpAllowed();

      /* Call user handler to manage its own subfunction */
      ApplDiagUserSubFunction(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
      DiagNRCSubFunctionNotSupported();
#endif
   }
   /* Subfunction supported in active session? */
   else if ((serviceErrorMask & kFblDiagSubfuncSessionFailure) == kFblDiagSubfuncSessionFailure)
   {
      /* For subfunctions send 0x7E */
      DiagNRCSubfunctionNotSupportedInActiveSession();
   }
   /* Check for security access on subfunction level */
   else if ((serviceErrorMask & kFblDiagSubfuncSecAccessFailure) == kFblDiagSubfuncSecAccessFailure)
   {
      /* Security level not correct */
      DiagNRCSecurityAccessDenied();
   }
   /* Min length check and total length check */
   else if ((serviceErrorMask & (kFblDiagSubMinLenFailure | kFblDiagSubLenFailure)) != 0u)
   {
      /* Length is incorrect. Set neg. response and exit */
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
   }
   /* Condition check failed */
   else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
   {
      /* Set NRC here if no NRC has been set in user callback function. */
      if (DiagGetError() == kDiagErrorNone)
      {
         DiagNRCConditionsNotCorrect();
      }
   }
   /* Remaining, uncovered errors */
   else
   {
      DiagNRCGeneralReject();
   }

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagNoneLengthCheck
 **********************************************************************************************************************/
/*! \brief         Lenght check function with actually no check implementation.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        Always kFblOk
 **********************************************************************************************************************/
/* PRQA S 3673 1*/ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagNoneLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Nothing to do here. Length check should be done in corresponding user callback function. */
   return kFblOk;
}

/***********************************************************************************************************************
 *  Diagnostic main handler service functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagDefaultSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Default session request service handler.
 *  \param[in,out] *pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Always kFblOk
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagDefaultSessionMainHandler (vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   vuint8 responseFlag;
#endif /* FBL_ENABLE_REPONSE_AFTER_RESET */

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Request for reset/FBL-shutdown in the confirmation of RCR-RP message */
   FblDiagSetWaitEcuReset();

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   /* Send response pending before reset */
   DiagExRCRResponsePending(kForceSendResponsePending);

   /* Set flag for response after reset */
   responseFlag = RESET_RESPONSE_SDS_REQUIRED;
   (void)ApplFblWriteResetResponseFlag(&responseFlag);

   /* Save target address */
   if (FblCwSaveResponseAddress() != kFblOk)
   {
      /* If clause is necessary here to process return value or macro. However,
         there is currently no strategy to handle this error.
      */
   }
#else
   /* Prepare response and reset states */
   FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);

   /* Send response */
   DiagProcessingDone(kDiagRslDiagnosticSessionControl);
#endif
   FblDiagSetEcuResetFctFinished();

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagExtendedSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Extended session request service handler.
 *  \param[in,out] *pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Result: Always kFblOk.
 **********************************************************************************************************************/
static tFblResult FblDiagExtendedSessionMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;

   /* Send response pending */
   DiagExRCRResponsePending(kForceSendResponsePending);
   /* Download can be performed in extended session -> check reprogramming conditions */
   if (ApplFblCheckProgConditions() == kFblOk)
   {
      /* Prepare response and reset states */
      FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);

      /* Change to extended session */
      FblDiagSetExtendedSession();

      /* Initialize segment counter */
      FblDiagSegmentInit();

      DiagProcessingDone(kDiagRslDiagnosticSessionControl);
      result = kFblOk;
   }
   else
   {
      /* Check of programming conditions failed */
      FblErrStatSetError(FBL_ERR_FLASH_PROG_CONDITIONS);
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagProgrammingSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Programming session request service handler.
 *  \param[in,out] *pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Result: kFblOk if reprogramming conditions are fullfilled, kFblFailed if not.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagProgrammingSessionMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;


   /* Check reprogramming conditions */
   if (ApplFblCheckProgConditions() == kFblOk)
   {
      /* Prepare response and reset states */
      FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);

      /* Change to programming session */
      FblDiagSetProgrammingSession();

      /* Initialize segment counter */
      FblDiagSegmentInit();

      DiagProcessingDone(kDiagRslDiagnosticSessionControl);
      result = kFblOk;
   }
   else
   {
      /* Check of programming conditions failed */
      FblErrStatSetError(FBL_ERR_FLASH_PROG_CONDITIONS);
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagEcuResetMainHandler
 **********************************************************************************************************************/
/*! \brief         Function manages the EcuReset service request
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        Result: Always kFblOk.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagEcuResetMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   vuint8 responseFlag;
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Request for reset/FBL-shutdown in the confirmation of RCR-RP message */
   FblDiagSetWaitEcuReset();

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   /* Send response pending before reset */
   DiagExRCRResponsePending(kForceSendResponsePending);

   /* Set flag for response after reset */
   responseFlag = RESET_RESPONSE_ECURESET_REQUIRED;
   (void)ApplFblWriteResetResponseFlag(&responseFlag);

   /* Save target address */
   if (FblCwSaveResponseAddress() != kFblOk)
   {
      /* If clause is necessary here to process return value or macro. However,
         there is currently no strategy to handle this error.
      */
   }
#else
   /* Send response */
   DiagProcessingDone(kDiagRslEcuReset);
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */
   FblDiagSetEcuResetFctFinished();

   return kFblOk;
}

/***********************************************************************************************************************
*  FblDiagSecAccResetStates
**********************************************************************************************************************/
/*! \brief        Reset reprogramming states according to DRECU-III-576
*  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
**********************************************************************************************************************/
static void FblDiagSecAccResetStates( vuint8 *pbDiagData )
{
   vuint8 * localPbDiagData;
   vuint8 tmpSeedBuffer[kSecSeedLength];
   vuintx i;

   localPbDiagData = pbDiagData;
   /* Copy seed into local buffer, the diagnostic buffer may be changed */
   for (i = 0u; i < kSecSeedLength; i++)
   {
      tmpSeedBuffer[i] = localPbDiagData[kDiagLocFmtSeedKeyStart + i];
   }

   /* Clear reprogramming states, see DRECU-III-576 */
   (void)FblMemInit();
   localPbDiagData = FblDiagMemGetActiveBuffer();

   FblDiagClrFingerprintValid();
   FblDiagClrEraseSucceeded();
   FblDiagClrTransferDataAllowed();
   FblDiagClrTransferDataSucceeded();
   FblDiagClrCheckMemoryAllowed();
   FblDiagClrCheckMemorySucceeded();

   downloadBlockDescriptor.blockStartAddress = 0u;
   downloadBlockDescriptor.blockLength = 0u;

   /* Restore seed */
   for (i = 0u; i < kSecSeedLength; i++)
   {
      localPbDiagData[kDiagLocFmtSeedKeyStart + i] = tmpSeedBuffer[i];
   }
}

/***********************************************************************************************************************
 *  FblDiagSecAccessSeedMainHandler
 **********************************************************************************************************************/
/*! \brief         Request Seed request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagSecAccessSeedMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

    result = kFblOk;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
   if (GetSecurityAccessDelay() > 0u)
   {
      DiagNRCRequiredTimeDelayNotExpired();
      result = kFblFailed;
   }
#endif

#if ( SYSSERVICE_SECMODHIS_VERSION >= 0x0300u )
   /* Cancel all SecM jobs if security access is performed anew, for example if the download is restarted */
   SecM_CancelAllJobs();
#endif

   if (result == kFblOk)
   {
      /* Check if security is already unlocked */
      if (FblDiagGetSecurityUnlock())
      {
         vuintx i;

         /* ECU already unlocked, send zero-seed */
         for (i = 0u; i < kSecSeedLength; i++)
         {
            pbDiagData[kDiagLocFmtSeedKeyStart + i] = 0u;
         }
      }
      else
      {
         /* Generate seed by application function */
         if (ApplFblSecuritySeed() == kFblOk)
         {
            /* Accept security key next */
            FblDiagSetSecurityKeyAllowed();
         }
         else
         {
            /* Error occurred during seed computation */
            FblErrStatSetError(FBL_ERR_SEED_GENERATION_FAILED);
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }

   if (result == kFblOk)
   {
      FblDiagSecAccResetStates(pbDiagData);

      /* Init memory driver */
      if (!FblDiagGetMemDriverInitialized())
      {
         DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

         result = FblDiagInitMemDriver();
      }
      if (result == kFblOk)
      {
         /* Send positive response if all tasks have been done successfully */
         DiagProcessingDone((tCwDataLengthType)kDiagRslSecurityAccessSeed);
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagSecAccessKeyMainHandler
 **********************************************************************************************************************/
/*! \brief         Send Key request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagSecAccessKeyMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
#endif

   if (diagReqDataLen != kDiagRqlSecurityAccessKey)
   {
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
      /* If a security key is expected but the request length is not correct, set delay flag    *
       * in NV-memory but do not activate delay timer.                                          */
      if (FblDiagGetSecurityKeyAllowed())
      {
         /* Send response pending for following NV-access */
         DiagExRCRResponsePending(kForceSendRpIfNotInProgress);
         if (!ApplFblGetSecAccessDelayFlag())
         {
            (void)ApplFblSetSecAccessDelayFlag();
         }
      }
#endif
      result = kFblFailed;
      /* Send NRC 0x13 - incorrectMessageLength */
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
   }
   /* Check preconditions for key processing */
   else if ((!FblDiagGetSecurityKeyAllowed())
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
      || (GetSecurityAccessDelay() > 0u)
#endif
      )
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {

      /* Send response pending */
      DiagExRCRResponsePending(kForceSendRpIfNotInProgress);
      /* Reset sequence */
      FblDiagClrSecurityKeyAllowed();

      /* Check security access key in application function */
      result = ApplFblSecurityKey();
      if (result != kFblOk)
      {
         result = kFblFailed;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* Too many invalid security attempts, enable security access delay */
         SetSecurityAccessDelay();
         if (!ApplFblGetSecAccessDelayFlag())
         {
            (void)ApplFblSetSecAccessDelayFlag();
         }
#endif
#if (FBL_DIAG_DDS_VERSION == FBL_DIAG_DDS_R01_01_2016_06)
         DiagNRCInvalidKey();
#else
         DiagNRCExceedNumberOfAttempts();
#endif
      }
      else
      {
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         if (ApplFblGetSecAccessDelayFlag())
         {
            (void)ApplFblClrSecAccessDelayFlag();
         }
#endif
         /* Security access successful, clear security access delay flag */
         FblDiagSetSecurityUnlock();
      }

      if (result == kFblOk)
      {
         DiagProcessingDone(kDiagRslSecurityAccessKey);
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagCommCtrlMainHandler
 **********************************************************************************************************************/
/*! \brief         Communication Control request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagCommCtrlMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   /* Check communication type */
   if (pbDiagData[kDiagLocFmtSubparam + 0x01u] != kDiagSubNormalCommunication)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else
   {
      /* Simply transmit a positive response message with subfunction parameter */
      DiagProcessingDone(kDiagRslCommunicationControl);
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagWriteFingerprintMainHandler
 **********************************************************************************************************************/
/*! \brief         WriteDataByIdentifier service, handling of fingerprint and identification data.
 *  \pre           Request only accepted after successful security access procedure.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagWriteFingerprintMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   /* Call notification routine to store fingerprint in non-volatile memory */
   if (ApplFblStoreFingerprint(&pbDiagData[kDiagLocFmtDataRecord]) == kFblOk)
   {
      FblDiagSetFingerprintValid();

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
      /* Reset states of potential previous download sequence */
      /* Must be done here because if the FBL is still in its current session, the tester *
       * may not send a programmingSession request again.                                 */
      FblDiagClrTransferDataAllowed();
#endif
   }

   /* Send positive response */
   DiagProcessingDone(kDiagRslWriteDataByIdentifier);

   return kFblOk;
}

#if (FBLCW_CHANGE_PARAMETER == STD_ON)
/***********************************************************************************************************************
 *  FblDiagWriteIsoTpBlockSizeSTminMainHandler
 **********************************************************************************************************************/
/*! \brief         WriteDataByIdentifier service, handling of Blocksize and STmin.
 *  \pre           Request only accepted after successful start programming session procedure
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagWriteIsoTpBlockSizeSTminMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   vuint8 stMin;
   tFblResult result;

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
# endif

   /* Supported values */
   /* BS:      0x00 - 0xFF (all)*/
   /* STmin:   0x00 - 0x7F, 0xF1 - 0xF9 */
   stMin = pbDiagData[kDiagLocFmtSubparam+3];
   if (  ((stMin >= 0x80u) && (stMin <= 0xF0u)) || (stMin >= 0xFAu) )
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else
   {
      (void)FblCw_ChangeParameter(TP_BS, pbDiagData[kDiagLocFmtSubparam + 2u]);
      (void)FblCw_ChangeParameter(TP_STMIN, pbDiagData[kDiagLocFmtSubparam + 3u]);

      /* Send positive response */
      DiagProcessingDone(kDiagRslWriteDataByIdentifier);
      result = kFblOk;
   }

   return result;
}
#endif /* (FBLCW_CHANGE_PARAMETER == STD_ON) */

/***********************************************************************************************************************
 *  FblDiagRCStartCsumMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Check Memory.
 *  \pre           Data to be checked has been downloaded to the corresponding memory.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
static tFblResult FblDiagRCStartCsumMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;
   tFblDiagNrc libMemResult;
   vuint8 * localPbDiagData;
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   vuintx idx;
   tFblAddress segmentEndAddress;
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   result = kFblOk;
   localPbDiagData = pbDiagData;
    /* Check if number of CRC bytes parameter is supported */
   if (localPbDiagData[kDiagLocFmtRoutineOption + kSecSigSize] != kSecCRCSize)
   {
      /* Invalid format */
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      result = kFblFailed;
   }
   else
   {
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
      /* Check if internal states have to be modified in order to resume the download at checkMemory */
      if ((blockResumeStates[kDiagResumeInfoDynamicIdx].resumeStatus == kFblRsSnapshotCreated) &&
         (FblDiagGetResumeInfRequested()))
      {
         /* Reinit FblLib_Mem to make sure status variables are set correctly */
         (void)FblMemInit();
         localPbDiagData = FblDiagMemGetActiveBuffer();

         /* Restore states */
         if (FblDiagRestoreSnapshot(V_NULL, V_NULL, &blockResumeStates[kDiagResumeInfoDynamicIdx]) == kFblOk)
         {
            segmentCount = verifyParam.segmentList.nrOfSegments;
            FblDiagSetTransferDataSucceeded();
         }
         else
         {
            /* Snapshot could not be restored */
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }

         if (result == kFblOk)
         {
            /* Restore downloadBlockDescriptor */
            if (kFblOk != FblLbtGetBlockDescriptorByNr(blockResumeStates[kDiagResumeInfoDynamicIdx].resumeBlockNo, &downloadBlockDescriptor))
            {
               DiagNRCConditionsNotCorrect();
               result = kFblFailed;
            }
         }

         if (result == kFblOk)
         {
            FblDiagInitBlockResume(downloadBlockDescriptor.blockNr, &blockResumeStates[kDiagResumeInfoDynamicIdx]);

            /* Check state flags */
            if (!FblDiagGetFingerprintValid())
            {
               DiagNRCRequestSequenceError();
               result = kFblFailed;
            }
            else
            {
               FblDiagSetCheckMemoryAllowed();
            }
         }
      }
      else
      {
         /* Create snapshot in order to resume with checkMemory if download is interrupted here
            Any previous snapshot may be at a lower address within the resume section and hence
            would lead to an unnecessary reprogramming although the download is completely
            finished.
            The snapshot should be created only if a download has been done before.
            */

         if ((!FblDiagGetFingerprintValid()) || (!FblDiagGetTransferDataSucceeded()))
         {
            DiagNRCRequestSequenceError();
            result = kFblFailed;
         }
         else
         {
            segmentEndAddress = downloadSegmentList[segmentCount - 1u].targetAddress + downloadSegmentList[segmentCount - 1u].length;
            (void)FblDiagCreateSnapshot(&blockResumeStates[kDiagResumeInfoDynamicIdx], segmentEndAddress);
         }
      }
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

      if (result == kFblOk)  /* PRQA S 2991, 2995 */ /* MD_FblDiagOem_2991_2995 */
      {
         /* RoutineControl-checkMemory is accepted only after successful RequestTransferExit
          * service or resume with checkMemory */
         if (!FblDiagGetCheckMemoryAllowed())
         {
            DiagNRCRequestSequenceError();
            result = kFblFailed;
         }
         else
         {
            libMemResult = FblMemRemapStatus(FblMemBlockEndIndication());
            if (libMemResult != kDiagErrorNone)
            {
               FblDiagSetError(libMemResult);
               result = kFblFailed;
            }
         }
      }
   }

   if (result == kFblOk)
   {
      /* Start response pending handling */
      DiagExRCRResponsePending(kForceSendResponsePending);

      /* Check download */
      (void)SecM_InitVerification(V_NULL);

      if (FblDiagDownloadCheck(localPbDiagData, diagReqDataLen) != kFblOk)
      {
         /* Check memory failed, clear state flag */
         FblDiagClrCheckMemorySucceeded();
      }
      else
      {
         /* Check memory was successful, set state flag */
         FblDiagSetCheckMemorySucceeded();
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
         for (idx = 0u; idx < kDiagNrOfResumeStates; idx++)
         {
            blockResumeStates[idx].resumeStatus = kFblRsMemoryChecked;
         }
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
      }
      (void)SecM_DeinitVerification(V_NULL);

      /* Set routine info to successfully completed */
      localPbDiagData[kDiagLocFmtRoutineInfo] = kDiagRoutineInfoSuccessful;

      /* CheckMemory request is no longer accepted for this block after successful validation */
      FblDiagClrCheckMemoryAllowed();
      /* Send positive response */
      DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
   }
   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartCheckProgPrecondMainHandler
 **********************************************************************************************************************/
/*! \brief         Check Programming Preconditions service function
 *  \details       This service is optional cand can be used for a manual check of programming preconditions by a
 *                 diagnostic test tool.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully,  kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartCheckProgPrecondMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   /* Check for preconditions - response should be prepared in callback function */
   (void)ApplFblCheckProgPreconditions(pbDiagData, diagReqDataLen);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagRCStartEraseMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Erase Memory.
 *  \pre           Fingerprint is available, memory driver initialized.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
static tFblResult FblDiagRCStartEraseMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;
   tFblMemBlockInfo blockInfo;
   vuint16 progAttempts;
   tFblMemStatus memStatus;
   vuint8 * localPbDiagData;
   tFblLbtBlockIndex localBlockIndex;
   tBlockDescriptor localBlockDesc;
# if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   tFlashStatus erasedStatus = kFlashNotErased;
#endif
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   vuintx idx;
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   result = kFblOk;
   localPbDiagData = pbDiagData;
   /* Only one addressFormatIdentifier is supported */
   if (localPbDiagData[kDiagLocFmtRoutineOption] != kDiagEraseMemoryALFI)
   {
      /* ALFI is invalid, send ROOR */
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else
   {
      /* Check if logical block number is valid */
      localBlockIndex = localPbDiagData[kDiagLocFmtRoutineOption + 1u];
      localBlockIndex &= kFblDiagLogicalBlockMask;

      if (
#if !defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
            /* PRQA S 3415 3 */ /* MD_FblDiagOem_3415 */
            ((localPbDiagData[kDiagLocFmtRoutineOption + 1u] & kFblDiagDeltaDownloadEnabled) == kFblDiagDeltaDownloadEnabled) ||
#endif
            (FblLbtGetBlockDescriptorByIndex(localBlockIndex, &localBlockDesc) != kFblOk)
         )
      {
         FblErrStatSetError(FBL_ERR_LBT_BLOCK_INDEX_EXCEEDED);
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
      }
      else
      {
         /* Prevent overwriting of FBL, block type boot is not accepted for flash erase */
         if (localBlockDesc.blockType == kBlockTypeBoot)
         {
            DiagNRCRequestOutOfRange();
            result = kFblFailed;
         }
      }
   }

   /* Do not allow erase if a pre-check was performed and this pre-check was not successful */
   if (FblDiagGetPreCheckProgDepFailed())
   {
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }

   if (result == kFblOk)
   {
      /* Send response pending to get more time for nv-memory access */
      DiagExRCRResponsePending(kForceSendResponsePending);
      /* Check if number of programming attempts is restricted ( != 0 ) */
      if (localBlockDesc.maxProgAttempts != 0u)
      {
         /* Read programming attempt counter */
         (void)ApplFblGetProgAttempts(localBlockDesc, &progAttempts);

         /* Request is not accepted if attempts exceed configured limit */
         if (progAttempts >= localBlockDesc.maxProgAttempts)
         {
            /* Set the nearest matching error status code */
            FblErrStatSetError(FBL_ERR_FLASH_PROG_CONDITIONS);

            /* Send NRC 0x22 if maximum of attempts is reached */
            DiagNRCConditionsNotCorrect();

            /* Reject the programming attempt */
            result = kFblFailed;
         }
      }
   }

   /* Check state flags */
   if ( (result == kFblOk) &&
        ((!FblDiagGetFingerprintValid()) || (!FblDiagGetMemDriverInitialized())))
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }

   if (result == kFblOk)
   {
      /* Initialize error status block number */
      FblErrStatSetBlockNr((tFblLbtBlockNr)localBlockIndex);

#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
      /* Check for delta-download */
      if ((localPbDiagData[kDiagLocFmtRoutineOption + 1u] & kFblDiagDeltaDownloadEnabled) == kFblDiagDeltaDownloadEnabled)
      {
         FblDiagSetDeltaDownload();
      }
      else
#endif
      {
         FblDiagClrDeltaDownload();
      }

      /* Reset internal states */
      FblDiagClrTransferDataSucceeded();
      FblDiagClrCheckMemorySucceeded();

#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
      if (!FblDiagGetDeltaDownload())
#endif
      {
         /* Invalidate application before erase procedure */
         if (ApplFblInvalidateBlock(localBlockDesc) != kFblOk)
         {
            /* Send NRC 0x22 if some internal fault conditions occur, (e.g. memory access error, etc) */
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }
   if (result == kFblOk)
   {
      downloadBlockDescriptor = localBlockDesc;
      FblDiagClrCheckMemoryAllowed();
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
      /* With the erase request the previous resume information can be discarded */
      for (idx = 0u; idx < kDiagNrOfResumeStates; idx++)
      {
         FblMemInvalidateSnapshot(blockResumeStates[idx].libMemSnapshot, FBL_MEM_SNAPSHOT_SIZE(SWM_DATA_MAX_NOAR));
         FblMemInvalidateSnapshot(blockResumeStates[idx].secModSnapshot, kFblDiagSecSnapshotSize);
# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
         FblMemInvalidateSnapshot(blockResumeStates[idx].secModPipeSnapshot, kDiagSecPipeSnapshotSize);
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */
         FblDiagInitBlockResume(downloadBlockDescriptor.blockNr, &blockResumeStates[idx]);
      }
#endif   /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
      /* Reinit FblLib_Mem to make sure status variables are set correctly */
      (void)FblMemInit();
      FblDiagClrTransferDataAllowed();
      FblDiagClrTransferDataSucceeded();

      localPbDiagData = FblDiagMemGetActiveBuffer();
      /* Prepare response */
      localPbDiagData[kDiagLocFmtSubparam] = kDiagSubStartRoutine;
      localPbDiagData[kDiagLocFmtRoutineIdHigh] = kDiagRoutineIdEraseMemoryHigh;
      localPbDiagData[kDiagLocFmtRoutineIdLow] = kDiagRoutineIdEraseMemoryLow;

      /* Set routine info to successfully completed */
      localPbDiagData[kDiagLocFmtRoutineInfo] = kDiagRoutineInfoSuccessful;
      /* Clear error indication in response */
      localPbDiagData[kDiagLocFmtRoutineStatus] = kFblDiagEraseSucceeded;

#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
      if (!FblDiagGetDeltaDownload())
#endif
      {
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
         /* Determine the flash memory status               *
          * Programming attempt counter increment only if   *
          * flash is not erased.                            */
         erasedStatus = FblDiagGetEraseState();

         if (erasedStatus == kFlashNotErased)
#endif
         {
            /* Increment programming attempt counter */
            (void)ApplFblIncProgAttempts(downloadBlockDescriptor);
         }
      }
      blockInfo.targetAddress = downloadBlockDescriptor.blockStartAddress;
      blockInfo.targetLength = downloadBlockDescriptor.blockLength;

      /* Reprogramming process state - erase started */
      SetReprogProcessState(fingerprintStatus, kDiagFpStatEraseStarted);
      (void)ApplFblWriteFpStatusInfo(downloadBlockDescriptor, &fingerprintStatus);

      /* Erase memory if required */
#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
      if (!FblDiagGetDeltaDownload())
#endif
      {
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
         if (erasedStatus == kFlashErased)
         {
            memStatus = kFblMemStatus_Ok;
         }
         else
#endif
         {
            memStatus = FblMemBlockEraseIndication(&blockInfo);
         }

         if (memStatus == kFblMemStatus_Ok)
         {
            /* Memory successfully erased */
            FblDiagSetEraseSucceeded();    /* Memory erased successfully */

#if defined( FBL_ENABLE_OTA )
            lastErasedBlock = downloadBlockDescriptor.blockNr;
#endif

            /* Set fingerprint status "erased", set compatibility mismatch,  clear appl valid status */
            fingerprintStatus = (kDiagFpStatMemErased | kDiagFpStatSwSwMismatch | kDiagFpStatSwHwMismatch);

            /* Init structure for new download */
            FblDiagSegmentInit();
            /* Adjust the size of the logical block according to presence pattern size. */
            (void)ApplFblAdjustLbtBlockData(&downloadBlockDescriptor);
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
            /* Create only dynamic snapshot because sector snapshot would lead to another erase attempt */
            blockResumeStates[kDiagResumeInfoDynamicIdx].resumeStatus = kFblRsBlockErased;
            blockResumeStates[kDiagResumeInfoDynamicIdx].resumeFpStatus = fingerprintStatus;
#endif   /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
         }
         else
         {
            /* Clear fingerprint status "erased", set compatibility mismatch, clear appl valid status */
            fingerprintStatus = (kDiagFpStatSwSwMismatch | kDiagFpStatSwHwMismatch);

            FblDiagClrEraseSucceeded();

            /* Check result and set corresponding routine status */
            switch (memStatus)
            {
               case kFblMemStatus_VoltageTooHigh:
               {
                  localPbDiagData[kDiagLocFmtRoutineStatus] = kFblCondVoltageTooHigh;
                  break;
               }
               case kFblMemStatus_VoltageTooLow:
               {
                  localPbDiagData[kDiagLocFmtRoutineStatus] = kFblCondVoltageTooLow;
                  break;
               }
               case kFblMemStatus_TemperatureTooHigh:
               {
                  localPbDiagData[kDiagLocFmtRoutineStatus] = kFblCondTemperatureTooHigh;
                  break;
               }
               case kFblMemStatus_TemperatureTooLow:
               {
                  localPbDiagData[kDiagLocFmtRoutineStatus] = kFblCondTemperatureTooLow;
                  break;
               }

               default:
               {
                  localPbDiagData[kDiagLocFmtRoutineStatus] = kFblDiagEraseFailed;
                  break;
               }
            }
         }
         /* Update NV-memory fingerprint status */
         SetReprogProcessState(fingerprintStatus, kDiagFpStatEraseFinished);
         (void)ApplFblWriteFpStatusInfo(downloadBlockDescriptor, &fingerprintStatus);
      } /* if !FblDiagGetDeltaDownload())  */
#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
      else
      {
         FblDiagSetEraseSucceeded();
      }
#endif

      /* Send response */
      DiagProcessingDone(kDiagRslRoutineControlEraseRoutine);
   } /* if (result == kFblOk) */
   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartCtrlFailSafeReactionMainHandler
 **********************************************************************************************************************/
/*! \brief         Call the user function to restart the fail safe functionality
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartCtrlFailSafeReactionMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   return ApplFblControlFailSafeReaction(pbDiagData, diagReqDataLen);
}

/***********************************************************************************************************************
 *  FblDiagRCStopCtrlFailSafeReactionMainHandler
 **********************************************************************************************************************/
/*! \brief         Call the user function to suppress the fail safe functionality
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStopCtrlFailSafeReactionMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   return ApplFblControlFailSafeReaction(pbDiagData, diagReqDataLen);
}

/***********************************************************************************************************************
 *  FblDiagRCStartVerifyMemoryContentMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Verify Memory Content
 *  \details       Performs CRC32 verification of programmed logical block without dependency to download sequence
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */  /* MD_MSR_STPTH, MD_MSR_STMIF */
static tFblResult FblDiagRCStartVerifyMemoryContentMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   FL_SegmentInfoType localDownloadSegments[SWM_DATA_MAX_NOAR];
   SecM_VerifyParamType localVerifyParam;
   tFblLbtBlockIndex localBlockIndex;
   tBlockDescriptor localBlockDesc;
   tFblMemVerifyFctOutput verifyFct;
   SecM_StatusType verificationResult;
   tFblResult result;
   vuint8 crcBuffer[kSecCRCSize];
   vuint8 const * expectedCrc;
   vuintx idx;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   /* Check if logical block number is valid */
   localBlockIndex = pbDiagData[kDiagLocFmtRoutineIdLow + 1u];

   /* Initialize expected CRC from DiagData */
   expectedCrc = &pbDiagData[kDiagLocFmtRoutineIdLow + 4u];

   if (FblLbtGetBlockDescriptorByIndex(localBlockIndex, &localBlockDesc) != kFblOk)
   {
      FblErrStatSetError(FBL_ERR_LBT_BLOCK_INDEX_EXCEEDED);
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   /* Bootloader block is not accepted for CRC verification */
   else if (localBlockDesc.blockType == kBlockTypeBoot)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   /* Check if number of CRC-bytes are supported */
   else if ((pbDiagData[kDiagLocFmtRoutineIdLow + 2u] != 0u) || (pbDiagData[kDiagLocFmtRoutineIdLow + 3u] != kSecCRCSize))
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   /* Check if logical block is valid */
   else if (ApplFblIsValidBlock(localBlockDesc.blockNr) != kFblOk)
   {
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
   else
   {
      DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

      /* Initialize verification parameters */
      localVerifyParam.segmentList.segmentInfo = localDownloadSegments;

      result = ApplFblReadSegmentList(localBlockDesc.blockNr, &localVerifyParam.segmentList);
   }

   if (result == kFblOk)
   {
      localVerifyParam.blockStartAddress = localBlockDesc.blockStartAddress;
      localVerifyParam.blockLength = localBlockDesc.blockLength;

      /* Initialize verification parameters */
      localVerifyParam.verificationData = crcBuffer;
      localVerifyParam.crcTotal = 0u;
      localVerifyParam.readMemory = (tFblMemVerifyReadFct)FblReadProm;
      localVerifyParam.wdTriggerFct = FblLookForWatchdogVoid;

      verifyFct = (tFblMemVerifyFctOutput)localBlockDesc.verifyOutput; /* PRQA S 0313 */ /* MD_FblDiagOem_0313 */

      if (verifyFct != ((tFblMemVerifyFctOutput)V_NULL) )
      {
         /* Compute CRC/hash of logical block */
         verificationResult = verifyFct(&localVerifyParam);

         /* Prepare response */
         pbDiagData[kDiagLocFmtRoutineInfo] = kDiagRoutineInfoSuccessful;

         /* Result:
          * bit 0: General Failure 0 - passed, 1 - failed
            bit 1: Verification result: 0 - passed,  1 - failed
            bit 2: Read/Write memory check: 0 - passed, 1 - failed
          */

         if (verificationResult == SECM_OK)
         {
            verificationResult = SECM_VER_OK;

            /* Compare calculated CRC with expected one */
            for (idx = 0u; idx < kSecCRCSize; idx++)
            {
               if (crcBuffer[idx] != expectedCrc[idx])
               {
                  pbDiagData[kDiagLocFmtRoutineInfo + 1u] = kDiagCrcErrorCRCCheckFailed;
                  verificationResult = SECM_VER_CRC;
                  break;
               }
            }

            if (verificationResult == SECM_VER_OK)
            {
               pbDiagData[kDiagLocFmtRoutineInfo + 1u] = kDiagCheckVerificationPassed;
            }
         }
         else
         {
            /*  */
            pbDiagData[kDiagLocFmtRoutineInfo + 1u] = kDiagCheckVerificationGeneralError;
         }

         DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
      }
      else
      {
         /* If no output verification routine is available, the logical block memory cannot be verified */
         DiagNRCConditionsNotCorrect();
         result = kFblFailed;
      }
   }
   else
   {
      if ( DiagGetError() == kDiagErrorNone )
      {
         DiagNRCConditionsNotCorrect();
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartPrepVehicleSystForReprogMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Prepare vehicle systems for reprogramming
 *  \details       Set all ECUs belonging to certain vehicle systems to a defined state
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartPrepVehicleSystForReprogMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   return ApplFblPrepVehicleSystForReprog(pbDiagData, diagReqDataLen);
}

/***********************************************************************************************************************
 *  FblDiagRCStartPreChkProgDependMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Pre-check programming dependencies
 *  \details       Service function performs the dependencies check with local and requested version information
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartPreChkProgDependMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;

   result = ApplFblPreChkProgDependencies(pbDiagData, diagReqDataLen);

   if (result == kFblOk)
   {
      if (pbDiagData[kDiagLocFmtRoutineStatus] != kDiagDependencyCheckOk)
      {
         /* Data in pre-check indicate incompatible versions, do not allow erase */
         FblDiagSetPreCheckProgDepFailed();
      }
   }
   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartCheckComptDependenciesMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Check Compatibility Dependencies.
 *  \details       Starts compatibility checks between HW/SW and SW/SW.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartCheckComptDependenciesMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   tFblLbtBlockCount blockCount;
   tBlockDescriptor blockDesc = {0};
   vuintx idx;
   vuint8 fpStatus;
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;
#endif

   result = kFblOk;
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   /* Update diagnostic state flag in case of resumable programming */
   blockCount = FblLbtGetBlockCount();
   fpStatus = 0u;
   for (idx = 0u; idx < blockCount; idx++)
   {
      /* Read fingerprint status from NVM */
      blockDesc.blockNr = (tFblLbtBlockNr)idx;
      if (ApplFblReadFpStatusInfo(blockDesc, &fpStatus) == kFblOk)
      {
         /* Check if any block contains the state 'check memory succeeded' */
         if ((fpStatus & 0xF0u) == kDiagFpStatMemCheckSucceeded)
         {
            FblDiagSetCheckMemorySucceeded();
            break;
         }
      }
   }
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

   /* Check state flags */
   if (!FblDiagGetCheckMemorySucceeded())
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
      /* Current fingerprint is handled and no longer used */
      FblDiagClrFingerprintValid();

      /* Reset internal states */
      FblDiagClrTransferDataSucceeded();

      /* Set routine info to successfully completed */
      pbDiagData[kDiagLocFmtRoutineInfo] = kDiagRoutineInfoSuccessful;
      pbDiagData[kDiagLocFmtRoutineStatus] = ApplFblCheckProgDependencies();

      if (pbDiagData[kDiagLocFmtRoutineStatus] == kDiagDependencyCheckOk)
      {
         if (ApplFblValidateApp() != kFblOk)
         {
            /* internal check routine error */
            pbDiagData[kDiagLocFmtRoutineStatus] = kDiagCheckDependenciesFailed;
         }
      }

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
      /* Download finished, reset all resume states */
      for (idx = 0u; idx < kDiagNrOfResumeStates; idx++)
      {
         blockResumeStates[idx].resumeStatus = kFblRsInitial;
      }
#endif

      /* Send positive response */
      DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
   }
   return result;
}

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
/***********************************************************************************************************************
 *  FblDiagCheckRequestDownloadResumeState
 **********************************************************************************************************************/
/*! \brief        Check if current RequestDownload request is resuming a previously interrupted download
 *  \param[in,out] resumeRequestState Pointer to resume state used by caller
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6030, 6050, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
static tFblResult FblDiagCheckRequestDownloadResumeState(V_MEMRAM1 tResumeReqState V_MEMRAM2 V_MEMRAM3 * resumeRequestState,
   tCwDataLengthType diagReqDataLen)
{
   tFblResult  result;
   tFblAddress validAddress;
   tFblMemBlockInfo     blockInfo;
   vuint8 *    localPbDiagData;
   vuintx idx;
   vuint16 activeResumeSection;

   result = kFblOk;

   if (FblDiagGetResumeInfRequested())
   {
      (void)FblDiagMemGetActiveBuffer();

      if (blockResumeStates[kDiagResumeInfoDynamicIdx].resumeStatus == kFblRsSnapshotCreated)
      {
         *resumeRequestState = kFblRsDynamicResume;
         result = FblDiagInitBlockAndCheckRange(transferAddress, transferRemainder, kDiagResumeInfoDynamicIdx);

         if (result == kFblOk)
         {
            result = FblDiagGetSnapshotInfo(&validAddress);
         }

         if ((result != kFblOk) ||
            (validAddress == ((downloadBlockDescriptor.blockStartAddress + downloadBlockDescriptor.blockLength) - 1u)))
         {
            /* Send NRC 0x24 because RoutineControl - CheckMemory is expected next */
            DiagNRCRequestSequenceError();
            result = kFblFailed;
         }
         else
         {
            /* Reinit FblLib_Mem to restart with erase indication */
            (void)FblMemInit();

            /* Set erase succeeded to ensure that segment is started from dynamic snapshot */
            FblDiagSetEraseSucceeded();

            result = FblDiagRestoreSnapshot(V_NULL, V_NULL, &blockResumeStates[kDiagResumeInfoDynamicIdx]);
            FblDiagResetBlockResume(&blockResumeStates[kDiagResumeInfoDynamicIdx]);

            if (result == kFblOk)
            {
               segmentCount = verifyParam.segmentList.nrOfSegments;
            }
            else
            {
               DiagNRCUploadDownloadNotAccepted();
            }
         }
      }
      else if (blockResumeStates[kDiagResumeInfoSectorIdx].resumeStatus == kFblRsSnapshotCreated)
      {
         *resumeRequestState = kFblRsSectorResume;
         result = FblDiagInitBlockAndCheckRange(transferAddress, transferRemainder, kDiagResumeInfoSectorIdx);

         if (result == kFblOk)
         {
            /* Check if address corresponds to end address of logical block                        *
            * In this case the request is not accepted because the download is already completed .*/
            result = FblDiagGetSnapshotInfo(&validAddress);
         }

         if ((result != kFblOk) ||
            (validAddress == ((downloadBlockDescriptor.blockStartAddress + downloadBlockDescriptor.blockLength) - 1u)))
         {
            /* Send NRC 0x24 because RoutineControl - CheckMemory is expected next */
            DiagNRCRequestSequenceError();
            result = kFblFailed;
         }
         else
         {
            /* Send response pending to get more time for nv-memory access */
            DiagExRCRResponsePending(kForceSendResponsePending);

            /* Prepare information to erase last resume section (blockResumeState.resumeAddress ) */
            activeResumeSection = FblDiagFindResumeSection(blockResumeStates[kDiagResumeInfoSectorIdx].resumeAddress);
            blockInfo.targetAddress = FblResumeSectionTable[activeResumeSection].begin;
            blockInfo.targetLength = (FblResumeSectionTable[activeResumeSection].end -
               FblResumeSectionTable[activeResumeSection].begin) + 1u;

            /* Increment programming attempt counter */
            (void)ApplFblIncProgAttempts(downloadBlockDescriptor);

            /* Reinit FblLib_Mem to restart with erase indication */
            (void)FblMemInit();
            localPbDiagData = FblDiagMemGetActiveBuffer();

            if (FblMemBlockEraseIndication(&blockInfo) != kFblMemStatus_Ok)
            {
               DiagNRCUploadDownloadNotAccepted();
               result = kFblFailed;
            }
            else
            {
               FblDiagSetEraseSucceeded();    /* Memory erased successfully */
               /* Restore states */
               result = (vuint8)FblDiagRestoreSnapshot(V_NULL, V_NULL, &blockResumeStates[kDiagResumeInfoSectorIdx]);
               FblDiagResetBlockResume(&blockResumeStates[kDiagResumeInfoSectorIdx]);

               if (result == kFblOk)
               {
                  segmentCount = verifyParam.segmentList.nrOfSegments + 1u;
                  FblDiagRequestDownloadSendResponse(localPbDiagData, diagReqDataLen);
               }
               else
               {
                  DiagNRCUploadDownloadNotAccepted();
               }
            }
         }
      }
      else
      {
         /* ResumeInfRequested is set for kFblRsSnapshotCreated only, should be impossible */
         assertFblUser(0u, kFblOemAssertSnapshotCreateError);  /* PRQA S 2741, 4558 */ /* MD_FblDiag_2741_ConstantExpression, MD_FblDiag_4558 */
      }
   }
   /* Resume information was not requested or could not provided because no valid snapshot exists yet */
   else if (blockResumeStates[kDiagResumeInfoDynamicIdx].resumeStatus == kFblRsBlockErased)
   {
      *resumeRequestState = kFblRsDynamicResume;

      if (FblDiagInitBlockAndCheckRange(transferAddress, transferRemainder, kDiagResumeInfoDynamicIdx) == kFblOk)
      {
         /* Restore fingerprint value */
         fingerprintStatus = blockResumeStates[kDiagResumeInfoDynamicIdx].resumeFpStatus;

         for (idx = 0u; idx < kDiagNrOfResumeStates; idx++)
         {
            /* Resume programming with first RequestDownload of logical block */
            FblDiagInitBlockResume(blockResumeStates[idx].resumeBlockNo, &blockResumeStates[idx]);
            FblDiagSetEraseSucceeded();
         }
      }
      else
      {
         result = kFblFailed;
      }
   }
   /* Resume information was not requested. requestDownload but no transferData has been received yet */
   else if (blockResumeStates[kDiagResumeInfoSectorIdx].resumeStatus == kFblRsBlockErased)
   {
      *resumeRequestState = kFblRsSectorResume;

      if ((FblDiagInitBlockAndCheckRange(transferAddress, transferRemainder, kDiagResumeInfoSectorIdx) == kFblOk) ||
         (blockResumeStates[kDiagResumeInfoSectorIdx].resumeAddress == transferAddress))
      {
         FblDiagSetEraseSucceeded();    /* Memory erased successfully */
                                        /* Restore states */
         result = (vuint8)FblDiagRestoreSnapshot(V_NULL, V_NULL, &blockResumeStates[kDiagResumeInfoSectorIdx]);
         FblDiagResetBlockResume(&blockResumeStates[kDiagResumeInfoSectorIdx]);

         if (result == kFblOk)
         {
            localPbDiagData = FblDiagMemGetActiveBuffer();
            segmentCount = verifyParam.segmentList.nrOfSegments + 1u;
            FblDiagRequestDownloadSendResponse(localPbDiagData, diagReqDataLen);
         }
         else
         {
            DiagNRCUploadDownloadNotAccepted();
         }
      }
      else
      {
         DiagNRCRequestSequenceError();
         result = kFblFailed;
      }
   }
   else
   {
      *resumeRequestState = kFblRsNoResume;
   }

   return result;
}
#endif /* #if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING ) */

/***********************************************************************************************************************
 *  FblDiagRequestDownloadMainHandler
 **********************************************************************************************************************/
/*! \brief         Request download service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF  */
static tFblResult FblDiagRequestDownloadMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if !defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   tFblAddress          transferAddress;
#endif
   tFblResult           result;
   tResumeReqState      resumeRequestState;
   FL_SegmentInfoType const * segment;
   vuint8             * localPbDiagData;
#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
   tBlockDescriptor  localBlockDesc;
   vuint16           progAttempts;
#endif

   result = kFblOk;
   resumeRequestState = kFblRsNoResume;
   localPbDiagData = pbDiagData;
   /* Check ALFI and data format identifier */
   if ((localPbDiagData[kDiagLocFmtFormatOffset] != (kDiagFmtAddrValue | kDiagFmtLengthValue))
#if defined( FBL_ENABLE_DATA_PROCESSING)
#else
      || (localPbDiagData[kDiagLocFmtSubparam] != kDiagSubNoDataProcessing)
#endif
      )
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else
   {
      /* Full length check */
      if (diagReqDataLen != (kDiagRqlRequestDownload + kDiagFmtFixedAddrSize + kDiagFmtFixedLengthSize))
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
         result = kFblFailed;
      }
   }

   if (result == kFblOk)
   {
      /* Extract address and length from request */
      transferAddress = (tFblAddress)FblMemGetInteger(kDiagFmtFixedAddrSize, &localPbDiagData[kDiagLocFmtAddrOffset]);
      transferRemainder = (tFblLength)FblMemGetInteger(kDiagFmtFixedLengthSize, &localPbDiagData[kDiagLocFmtAddrOffset + kDiagFmtFixedAddrSize]);

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
      /* Ensure that only downloads are accepted which start and end in same resume section */
      if (FblDiagFindResumeSection(transferAddress) != FblDiagFindResumeSection((transferAddress + transferRemainder) - 1u))
      {
         result = kFblFailed;
         DiagNRCRequestOutOfRange();
      }
      else
      {
         result = FblDiagCheckRequestDownloadResumeState(&resumeRequestState, diagReqDataLen);
         localPbDiagData = FblDiagMemGetActiveBuffer();
      }
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */
   }
   if ((result == kFblOk) && (resumeRequestState != kFblRsSectorResume)) /* PRQA S 2995 */ /* MD_FblDiagOem_2991_2995 */
   {
#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
      /* Some stream output implementations (e.g. delta download) prohibit previous erase */
      if (FblDiagGetDeltaDownload())
      {
         /* Send response pending to get more time for nv-memory access */
         DiagExRCRResponsePending(kForceSendResponsePending);

         if (FblLbtGetBlockDescriptorByAddressLength(transferAddress, transferRemainder, &localBlockDesc) != kFblOk)
         {
            /* Block number not found in LBT */
            DiagNRCRequestOutOfRange();
            result = kFblFailed;
         }
         else
         {
            /* Check programming attempt counter for requested logical block */
            if (localBlockDesc.maxProgAttempts != 0u)
            {
               (void)ApplFblGetProgAttempts(localBlockDesc, &progAttempts);
               if (progAttempts >= localBlockDesc.maxProgAttempts)
               {
                  /* Set the nearest matching error status code */
                  FblErrStatSetError(FBL_ERR_FLASH_PROG_CONDITIONS);

                  /* Send NRC 0x22 if maximum of attempts is reached */
                  DiagNRCConditionsNotCorrect();

                  /* Reject the programming attempt */
                  result = kFblFailed;
               }
            }
         }

         if (result == kFblOk)
         {
            /* Check state flags */
            if ((!FblDiagGetFingerprintValid()) || (!FblDiagGetMemDriverInitialized()))
            {
               DiagNRCRequestSequenceError();
               result = kFblFailed;
            }
         }
         if (result == kFblOk)
         {
            /* Reset internal states */
            FblDiagClrTransferDataSucceeded();
            FblDiagClrCheckMemorySucceeded();

            /* Block still has to be valid */

            /* Check if current block is valid */
            if (ApplFblIsValidBlock(localBlockDesc.blockNr) != kFblOk)
            {
               DiagNRCConditionsNotCorrect();
               result = kFblFailed;
            }
         }

         if (result == kFblOk)
         {
            /* Invalidate application before download */
            if (ApplFblInvalidateBlock(localBlockDesc) != kFblOk)
            {
               DiagNRCConditionsNotCorrect();
               result = kFblFailed;
            }
            else
            {
               downloadBlockDescriptor = localBlockDesc;
               FblDiagClrCheckMemoryAllowed();
            }
         }
      }
#endif /* FBL_MEM_ENABLE_STREAM_OUTPUT */

      /* Verify addresses (address must be in the area described by downloadBlockDescriptor)       */
      /* As long as the logical block has not been erased, any requested address range is regarded *
       * as invalid and a requestOutOfRange is sent as response.                                   */

      if (result == kFblOk)  /* PRQA S 2991, 2995 */ /* MD_FblDiagOem_2991_2995 */
      {
         if ((!FblDiagGetEraseSucceeded())  /* PRQA S 3415 2 */ /* MD_FblDiagOem_3415 */
            || (FblLbtCheckRangeContained(transferAddress, transferRemainder,
               downloadBlockDescriptor.blockStartAddress, downloadBlockDescriptor.blockLength) != kFblOk))
         {
            FblErrStatSetError(FBL_ERR_LBT_ADDR_MISMATCH);
            DiagNRCRequestOutOfRange();
            result = kFblFailed;
         }
         else
         {
            /* Check if requested segment overlaps with previously downloaded data */
            if (segmentCount > 0u)
            {
               /* Get address and length of previous segment*/
               segment = &verifyParam.segmentList.segmentInfo[segmentCount - 1u];

               if ((transferAddress <= segment->transferredAddress)
                  || ((transferAddress - segment->transferredAddress) < segment->length)
                  )
               {
                  /* New segment is not in order or overlaps previous one */
                  DiagNRCRequestOutOfRange();
                  result = kFblFailed;
               }
            }
         }
      }

      /* PRQA S 2991, 2995 3 */ /* MD_FblDiagOem_2991_2995 */
      if (result == kFblOk)
      {
         if (resumeRequestState == kFblRsNoResume)
         {
            /* Check other conditions */
            if (FblDiagGetTransferDataAllowed())
            {
               /* Send Nrc 0x22 when a download is currently in progress */
               DiagNRCConditionsNotCorrect();
               result = kFblFailed;
            }
            else
            {
               if (!FblDiagGetFingerprintValid())
               {
                  DiagNRCUploadDownloadNotAccepted();
                  result = kFblFailed;
               }
            }
         }
      }

      if (result == kFblOk)
      {
         /* Check state flags */
         if ((!FblDiagGetMemDriverInitialized())
            || ((!FblDiagGetEraseSucceeded())
#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
            && (!FblDiagGetDeltaDownload())
#endif /* FBL_MEM_ENABLE_STREAM_OUTPUT */
            )
            || (segmentCount >= SWM_DATA_MAX_NOAR))
         {
            FblErrStatSetError(FBL_ERR_TOO_MANY_SEGMENTS_IN_MODULE);
            DiagNRCUploadDownloadNotAccepted();
            result = kFblFailed;
         }
      }

      if (result == kFblOk)
      {
         /* Initialize internal states */
         FblDiagClrTransferDataAllowed(); /* PRQA S 2985 */ /* MD_FblDiagOem_2985 */
         FblDiagClrTransferDataSucceeded();

         /* Start of first segment of flash driver or flash data? */
         if (segmentCount == 0u)
         {
            result = FblDiagBlockStartIndication(downloadBlockDescriptor.blockNr);
         }
      }

      if (result == kFblOk)
      {
         /* Indicate start of new segment */
         result = FblDiagSegmentStartIndication(localPbDiagData, transferAddress);
      }

      if (result == kFblOk)
      {
         localPbDiagData = FblDiagMemGetActiveBuffer();
         FblDiagRequestDownloadSendResponse(localPbDiagData, diagReqDataLen);
      }
   }
   return result;
}

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
/***********************************************************************************************************************
 *  FblDiagInitBlockAndCheckRange
 **********************************************************************************************************************/
/*! \brief         Function initializes the download block descriptor structure and checks if requested address
 *                 is within the address range of this block.
 *  \pre           The block resume state is initialized
 *  \param[in]     segmentAddress Start address of segment
 *  \param[in]     segmentLength Length of segment in bytes
 *  \param[in]     blockResumeStateIdx Index of resume state indication used for getting block descriptor
 *..\return        kFblOk: Logical block is known and segment is within logical block bounds. kFblFailed: Other
 **********************************************************************************************************************/
static tFblResult FblDiagInitBlockAndCheckRange( tFblAddress segmentAddress, tFblLength segmentLength, vuint8 blockResumeStateIdx )
{
   tFblResult result;

   /* Re-initialize logical block information */
   if (FblLbtGetBlockDescriptorByNr(blockResumeStates[blockResumeStateIdx].resumeBlockNo, &downloadBlockDescriptor) == kFblOk)
   {
      /* Adjust the size of the logical block according to presence pattern size. */
      (void)ApplFblAdjustLbtBlockData( &downloadBlockDescriptor );

      /* Initialize error status block number */
      FblErrStatSetBlockNr(downloadBlockDescriptor.blockNr);

      /* Check if requested address range matches with logical block */
      if (FblLbtCheckRangeContained(segmentAddress, segmentLength,
            downloadBlockDescriptor.blockStartAddress, downloadBlockDescriptor.blockLength) != kFblOk)
      {
         FblErrStatSetError(FBL_ERR_LBT_ADDR_MISMATCH);
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
      }
      else
      {
         result = kFblOk;
      }
   }
   else
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }

   return result;
}
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

/***********************************************************************************************************************
 *  FblDiagRequestDownloadSendResponse
 **********************************************************************************************************************/
/*! \brief         Function sends positive response for RequestDownload service
 *  \pre           May be called for received RequestDownload service requests only
 *  \param[in,out] pbDiagData Pointer to diagnostic data (without SID), unused
 *  \param[in]     diagReqDataLen Length of diagnostic request, unused
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static void FblDiagRequestDownloadSendResponse( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   vuint8 * localPbDiagData;
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   if ((segmentCount <= 1u) || (blockResumeStates[kDiagResumeInfoSectorIdx].resumeStatus == kFblRsInitial))
   {
      /* Create snapshot for first request download of logical block or if    *
       * interrupted download is resumed.                                     */
      (void)FblDiagCreateSnapshot(&blockResumeStates[kDiagResumeInfoSectorIdx], transferAddress);
      /* Overwrite resume status of sector snapshot because block will count as erased (fingerprint status
       * not "resprogramming started" yet) to allow resume from this snapshot */
      blockResumeStates[kDiagResumeInfoSectorIdx].resumeStatus = kFblRsBlockErased;
      blockResumeStates[kDiagResumeInfoSectorIdx].resumeBlockNo = downloadBlockDescriptor.blockNr;
   }
   else
   {
      /* Make sure that a snapshot is created if new transfer address lies behind current *
       * resume section end address                                                       */
      ApplFblMemCheckpointIndication(transferAddress);
   }

   FblDiagResetBlockResume(&blockResumeStates[kDiagResumeInfoDynamicIdx]);
#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

   /* Init expected sequence counter for TransferData */
   expectedSequenceCnt = kFblDiagInitSequenceNum;
   /* Init current sequence counter for TransferData */
   currentSequenceCnt = kFblDiagInitSequenceNum;

   /* Initialize the number of retries allowed for a specific block in TransferData */
   retryCounter = kDiagInitDataRetries;

   localPbDiagData = FblDiagMemGetActiveBuffer();

   /* Allow now reception of TransferData */
   FblDiagSetTransferDataAllowed();
   FblDiagClrTransferDataSucceeded();
   FblDiagClrCheckMemoryAllowed();

   /* Prepare response */
   localPbDiagData[kDiagLocFmtSubparam] = (FBL_DIAG_RESPONSE_BUFFER_LFI << 4u);
   FblMemSetInteger(FBL_DIAG_RESPONSE_BUFFER_LFI, FBL_DIAG_RESPONSE_BUFFER_SIZE, &localPbDiagData[kDiagLocFmtSubparam + 1u]);

   DiagProcessingDone(kDiagRslRequestDownload + FBL_DIAG_RESPONSE_BUFFER_LFI);
}

/***********************************************************************************************************************
 *  FblDiagTransferDataMainHandler
 **********************************************************************************************************************/
/*! \brief         TransferData service function;
 *  \pre           TransferData must be enabled by RequestDownload service
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673, 6010, 6030 1 */ /* MD_MSR_Rule8.13, MD_MSR_STPTH, MD_MSR_STCYC */
static tFblResult FblDiagTransferDataMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblMemStatus memStatus;
   tFblResult result;
   tFblResult bscRetryResult;
   tFblLength transferDataLength;

   result = kFblOk;
   bscRetryResult = kFblFailed;

   /* Check state flags */
   if (!FblDiagGetTransferDataAllowed())
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
      if ((diagReqDataLen <= (kDiagRqlTransferData)) ||
#if defined( FBL_ENABLE_UNALIGNED_DATA_TRANSFER )
         (diagReqDataLen > (tTpDataType)(FBL_DIAG_BUFFER_LENGTH - 1u))
#else
         (diagReqDataLen > (tTpDataType)(((FBL_DIAG_BUFFER_LENGTH - 2u) & ~(FBL_DIAG_SEGMENT_SIZE - 1u)) + 1u))
#endif /* FBL_ENABLE_UNALIGNED_DATA_TRANSFER */
         )
      {
         /* Requested transfer length is larger than indicated data length */
         FblDiagClrTransferDataAllowed();

         DiagNRCIncorrectMessageLengthOrInvalidFormat();
         result = kFblFailed;
      }
   }

   if (result == kFblOk)
   {
      /* Check if the requested sequence number is expected */
      if (pbDiagData[kDiagLocFmtSubparam] != expectedSequenceCnt)
      {
         /* Check if sequence number corresponds to a retry */
         if (pbDiagData[kDiagLocFmtSequenceCnt] == currentSequenceCnt)
         {
            /* Handle the retries here */
            /* If max number of retries exceeded */
            if (retryCounter == 0u)
            {
               DiagNRCTransferDataSuspended();
               FblDiagClrTransferDataAllowed();
               result = kFblFailed;
            }
            else
            {
               retryCounter--;

               /* Repetition of last transferData request                        */
               /* Simply send a positive response without loading data to memory */
               DiagProcessingDone(kDiagRslTransferData);
               bscRetryResult = kFblOk;
            }
         }
         else /* Sequence number is not for a retry */
         {
            /* Send a WrongSequenceError */
            DiagNRCWrongBlockSequenceCounter();
            FblDiagClrTransferDataAllowed();
            result = kFblFailed;
         }
      }
      else /* Sequence number is equal to the one expected */
      {
         /* Re-initialize retry counter in case a correct sequence number was received */
         retryCounter = kDiagInitDataRetries;
      }
   }

   if ((result == kFblOk) && (bscRetryResult == kFblFailed))
   {
      /* Memorize current counter */
      currentSequenceCnt = expectedSequenceCnt;

      /* Set memory status "programmed" just before flash programming starts */
      if ((fingerprintStatus & kDiagFpStatMemErased) == kDiagFpStatMemErased)
      {
         /* Clear "erased" status */
         fingerprintStatus &= FblInvert8Bit(kDiagFpStatMemErased);

         /* ReprogrammingProcessState, reprogramming started */
         SetReprogProcessState(fingerprintStatus, kDiagFpStatReprogStarted);

         DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

         /* Update NV-memory */
         if ((tFblResult)ApplFblWriteFpStatusInfo(downloadBlockDescriptor, &fingerprintStatus) != kFblOk)
         {
            /* If it is not possible to clear the erased status, data download is not accepted */
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING)
   /* TransferData received, set sector snapshot to created in all cases because now resume should not be possible
    * without having requested resume information previously */
   blockResumeStates[kDiagResumeInfoSectorIdx].resumeStatus = kFblRsSnapshotCreated;
#endif

   if ((result == kFblOk) && (bscRetryResult == kFblFailed))
   {
      /* Length without sequence counter byte */
      transferDataLength = (tFblLength)diagReqDataLen - 1u;

      memStatus = FblMemDataIndication(DiagBuffer, kDiagFmtDataOffset, transferDataLength);

      /* Caution: Depending on configuration, DiagBuffer pointer may change. */
      (void)FblDiagMemGetActiveBuffer();

      if (memStatus == kFblMemStatus_Ok)
      {
         /* Sequence counter value of next transferData request */
         expectedSequenceCnt++;
         DiagProcessingDone(kDiagRslTransferData);
      }
      else
      {
         FblDiagClrTransferDataAllowed();
         result = kFblFailed;

         /* Analyze result and send corresponding negative response */
         switch (memStatus)
         {
            case kFblMemStatus_VoltageTooHigh:
            {
               FblDiagSetError(kDiagNrcVoltageTooHigh);
               break;
            }
            case kFblMemStatus_VoltageTooLow:
            {
               FblDiagSetError(kDiagNrcVoltageTooLow);
               break;
            }
            case kFblMemStatus_TemperatureTooHigh:
            {
               FblDiagSetError(kDiagNrcGeneralProgrammingFailure);
               break;
            }
            case kFblMemStatus_TemperatureTooLow:
            {
               FblDiagSetError(kDiagNrcGeneralProgrammingFailure);
               break;
            }

            default:
            {
               FblDiagSetError(FblMemRemapStatus(memStatus));
               break;
            }
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagReqTransferExitMainHandler
 **********************************************************************************************************************/
/*! \brief         RequestTransferExit service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagReqTransferExitMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   tFblResult result;
   tFblDiagNrc libMemResult;
   V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 dummyParameter;
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
   tFblAddress segmentEndAddress;
   tFblAddress blockEndAddress;
#endif
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
#endif

   result = kFblOk;
   /* Check sequence for service ID */
   if (!FblDiagGetTransferDataAllowed())
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }

   if (result == kFblOk)
   {
      /* Total length check - must be done here to be compliant to the ISO check sequence */
      if (diagReqDataLen != kDiagRqlRequestTransferExit)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
         result = kFblFailed;
      }
      else
      {
         libMemResult = FblMemRemapStatus(FblMemSegmentEndIndication(&dummyParameter));

         /* Update diag buffer pointer. Consider that pbDiagData is no longer up to date afterwards */
         (void)FblDiagMemGetActiveBuffer();

         if (libMemResult != kDiagErrorNone)
         {
            /* In case of pipelined programming, a memory condition check issue
             * of the previous TransferData write operation may be returned here.
             */
            if ( (libMemResult == (tFblDiagNrc)kFblMemStatus_VoltageTooHigh) ||
                 (libMemResult == (tFblDiagNrc)kFblMemStatus_VoltageTooLow) ||
                 (libMemResult == (tFblDiagNrc)kFblMemStatus_TemperatureTooHigh) ||
                 (libMemResult == (tFblDiagNrc)kFblMemStatus_TemperatureTooLow)
               )
            {
               /* The only supported NRC is 0x72 - generalProgramming failure */
               DiagNRCGeneralProgrammingFailure();
            }
            else
            {
               FblDiagSetError(libMemResult);
            }
            result = kFblFailed;
         }
      }
   }

   if (result == kFblOk)
   {
      /* Reset internal states */
      FblDiagClrTransferDataAllowed();

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
      /* Create snapshot if last byte of logical block has been programmed */
      segmentEndAddress = downloadSegmentList[segmentCount - 1u].targetAddress + (downloadSegmentList[segmentCount - 1u].length - 1u);
      blockEndAddress = downloadBlockDescriptor.blockStartAddress + (downloadBlockDescriptor.blockLength - 1u);

      if (blockEndAddress == segmentEndAddress)
      {
         /* If logical block is full, no more data can be downloaded to this block, create sector snapshot */
         (void)FblDiagCreateSnapshot(&blockResumeStates[kDiagResumeInfoSectorIdx], segmentEndAddress + 1u);
      }
      /* Always create dynamic snapshot after transfer exit */
      (void)FblDiagCreateSnapshot(&blockResumeStates[kDiagResumeInfoDynamicIdx], segmentEndAddress + 1u);
#endif

      /* TransferData was successful, set state flag */
      FblDiagSetTransferDataSucceeded();
      FblDiagSetCheckMemoryAllowed();
      DiagProcessingDone(kDiagRslRequestTransferExit);
   }
   return result;
}

/***********************************************************************************************************************
 *  FblDiagTesterPresentMainHandler
 **********************************************************************************************************************/
/*! \brief         FblTesterPresent service function.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagTesterPresentMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   DiagProcessingDone(kDiagRslTesterPresent);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagControlDTCMainHandler
 **********************************************************************************************************************/
/*! \brief         ControlDTCSetting service function.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
static tFblResult FblDiagControlDTCMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Simply transmit a positive response message with subfunction parameter */
   DiagProcessingDone(kDiagRslControlDTCSetting);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagReadDataByIdMainHandler - 14229 specific
 **********************************************************************************************************************/
/*! \brief         ReadDataByIdentifier service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagReadDataByIdMainHandler( vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen )
{
   ApplFblReadDataByIdentifier(pbDiagData, diagReqDataLen);

   return kFblOk;
}

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
/***********************************************************************************************************************
 *  FblDiagCheckPlatformMsg
 **********************************************************************************************************************/
/*! \brief       Checks and evaluates the contents of the platform (architecture) message
 *  \pre         CAN hardware has to be initialized before call. May only be called after a special message was received
 *  \param[in]   PduInfoPtr Pointer to received pdu (data and length)
 *  \return      Check result. kFblOk if the start message has been accepted and configuration switch is required.
 **********************************************************************************************************************/
vuint8 FblDiagCheckPlatformMsg(P2CONST(PduInfoType, AUTOMATIC, FBLPLATFORMMESSAGE_APPL_DATA) PduInfoPtr)
{
   vuint8 result;
   P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) newConfig;

   result = kFblFailed;

   /* Check supported platform */
   if ((PduInfoPtr->SduDataPtr[0] >= 1u) && (PduInfoPtr->SduDataPtr[0] <= (kNrOfConfigInitPtrs )))
   {
      /* Unlock diagnostic buffer */
      FblDiagClrBufferLocked();

      /* Platform message received - close acceptance window */
      FblDiagClrPlatformMsgWindow();

      /* Initialize the requested identity */
      newConfig = ApplFblPlatformToConfigPtr(PduInfoPtr->SduDataPtr[0]);
      if (activeCwConfiguration != newConfig)
      {
         activeCwConfiguration = newConfig;
         result = kFblOk;
      }
   }

   return result;
}
#endif /* FBL_ENABLE_MULTIPLE_PLATFORMS */

/***********************************************************************************************************************
 *  FblDiagMemPreWrite
 **********************************************************************************************************************/
/*! \brief       Perform actions directly before memory driver write.
 *  \details     Switch communication wrapper into offline mode.
 *  \return      kFblOk if write operation can continue, kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblDiagMemPreWrite( void )
{
   FblCwSetOfflineMode();

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagMemPostWrite
 **********************************************************************************************************************/
/*! \brief       Perform actions directly after memory driver write.
 *  \details     Switch communication wrapper into online mode.
 *  \return      kFblOk if operation can continue, kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblDiagMemPostWrite( void )
{
   FblCwSetOnlineMode();

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagMemPreErase
 **********************************************************************************************************************/
/*! \brief       Perform actions directly before memory driver erase.
 *  \details     Switch communication wrapper into offline mode.
 *  \return      kFblOk if write operation can continue, kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblDiagMemPreErase( void )
{
   FblCwSetOfflineMode();

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagMemPostErase
 **********************************************************************************************************************/
/*! \brief       Perform actions directly after memory driver erase.
 *  \details     Switch communication wrapper into online mode.
 *  \return      kFblOk if operation can continue, kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblDiagMemPostErase( void )
{
   FblCwSetOnlineMode();

   return kFblOk;
}

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
/***********************************************************************************************************************
 *  FblDiagResetBlockResume
 **********************************************************************************************************************/
/*! \brief          Reset of block resume information structure
 *  \details        This function the current state but does not clear the block number
 *  \param[in,out]  pBlockResumeState Pointer to block resume state variable used by caller
 **********************************************************************************************************************/
static void FblDiagResetBlockResume( tResumeState * pBlockResumeState )
{
   FblDiagClrResumeInfRequested();

   pBlockResumeState->resumeStatus       = kFblRsInitial;  /* Initial state */
   pBlockResumeState->resumeFpStatus     = 0u;
}

/***********************************************************************************************************************
 *  FblDiagInitBlockResume
 **********************************************************************************************************************/
/*! \brief          Initialization of block resume information structure
 *  \details        This function is called from RoutineControl - eraseMemory to initialize the resume information
 *                  of the corresponding block.
 *  \param[in]      blockNo Logical block whose resume state shall be initialized
 *  \param[in,out]  pBlockResumeState Pointer to block resume state variable used by caller
 **********************************************************************************************************************/
static void FblDiagInitBlockResume( tFblLbtBlockNr blockNo, tResumeState * pBlockResumeState )
{
   tBlockDescriptor blockDescriptor;

   FblDiagResetBlockResume(pBlockResumeState);
   pBlockResumeState->resumeBlockNo = blockNo;

   (void)FblLbtGetBlockDescriptorByNr(blockNo, &blockDescriptor);

   /* Initialize resume section index based on start address of logical block */
   pBlockResumeState->resumeAddress = blockDescriptor.blockStartAddress;
}

/***********************************************************************************************************************
 *  FblDiagFindResumeSection
 **********************************************************************************************************************/
/*! \brief       Find index of resume section for given address
 *  \details     If no section is found, return -1
 *  \param[in]   address Memory address to be checked for resume section index
 *  \return      Index of resume section
 **********************************************************************************************************************/
static vuint16 FblDiagFindResumeSection( tFblAddress address )
{
   vuint16 section;

   (void)FblLookForWatchdog();

   for (section = 0u; section < kNrOfResumeSections; section++)
   {
      if (   (address >= FblResumeSectionTable[section].begin)
          && (address <= FblResumeSectionTable[section].end)
         )
      {
         break;
      }
   }

   assertFblInternal((section < kNrOfResumeSections), kFblOemAssertInvalidError);

   return section;
}

/***********************************************************************************************************************
 *  FblDiagCreateSnapshot
 **********************************************************************************************************************/
/*! \brief          Create a sanapshot of current download states
 *  \param[in,out]  pBlockResumeState Pointer to resume state supposed to hold the snapshot
 *  \param[in]      newResumeAddress Next resume address to be reported/remembered
 *  \return      kFblOk if snapshot has been correctly stored, kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblDiagCreateSnapshot( tResumeState * pBlockResumeState, tFblAddress newResumeAddress )
{
   tFblResult result;
   tFblMemStatus memResult;

   result = kFblOk;

#if ( SYSSERVICE_SECMODHIS_VERSION >= 0x0300u )
   memResult = FblMemCreateSnapshot(pBlockResumeState->libMemSnapshot, FBL_MEM_SNAPSHOT_SIZE(SWM_DATA_MAX_NOAR));
   assertFblUser((memResult == kFblMemStatus_Ok), kFblOemAssertSnapshotCreateError);

   if (memResult != kFblMemStatus_Ok)
   {
      result = kFblFailed;
   }
# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   if (result == kFblOk)
   {
      pBlockResumeState->secModPipeSnapshotLength = kDiagSecPipeSnapshotSize;
      if (SecM_SaveContext_VerifyClassDDD(pBlockResumeState->secModPipeSnapshot, &pBlockResumeState->secModPipeSnapshotLength) != SECM_OK)
      {
         result = kFblFailed;
      }
   }
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED*/
   if (result == kFblOk)
   {
      pBlockResumeState->secModSnapshotLength = kFblDiagSecSnapshotSize;

      if (SecM_SaveContext_VerifySignature(pBlockResumeState->secModSnapshot, &pBlockResumeState->secModSnapshotLength) == SECM_OK)
      {
         pBlockResumeState->resumeStatus = kFblRsSnapshotCreated;
         pBlockResumeState->resumeFpStatus = fingerprintStatus;
         pBlockResumeState->resumeAddress = newResumeAddress;
      }
      else
      {
         result = kFblFailed;
      }
   }
#else /* SYSSERVICE_SECMODHIS_VERSION >= 0x0300u */

   if (sizeof(pBlockResumeState->secModSnapshot) < sigParam.currentHash.length)
   {
      result = kFblFailed;
   }

# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   if (sizeof(pBlockResumeState->secModPipeSnapshot) < pipeSigParam.currentHash.length)
   {
      result = kFblFailed;
   }
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

   if (result == kFblOk)
   {
      memResult = FblMemCreateSnapshot(pBlockResumeState->libMemSnapshot, sizeof(pBlockResumeState->libMemSnapshot));
      assertFblUser((memResult == kFblMemStatus_Ok), kFblOemAssertSnapshotCreateError);
      if (memResult == kFblMemStatus_Ok)
      {
         (void)MEMCPY(pBlockResumeState->secModSnapshot, sigParam.currentHash.sigResultBuffer,   /* PRQA S 0314, 0326 */ /* MD_FblDiagOem_0314_0326_MemCpy */
            sigParam.currentHash.length);
# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
         /* PRQA S 0314, 0326 1 */ /* MD_FblDiagOem_0314_0326_MemCpy */
         (void)MEMCPY(pBlockResumeState->secModPipeSnapshot, pipeSigParam.currentHash.sigResultBuffer, pipeSigParam.currentHash.length);
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */
         pBlockResumeState->resumeStatus = kFblRsSnapshotCreated;
         pBlockResumeState->resumeFpStatus = fingerprintStatus;
         pBlockResumeState->resumeAddress = newResumeAddress;
      }
      else
      {
         result = kFblFailed;
      }
   }
#endif /* SYSSERVICE_SECMODHIS_VERSION >= 0x0300u */

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRestoreSnapshot
 **********************************************************************************************************************/
/*! \brief          Restore a previously taken snapshot when an interrupted download sequence is resumed
 *  \param[in,out]  block Pointer to block used for snapshot restoration
 *  \param[in,out]  segment Pointer to segment information structure
 *  \param[in]      pBlockResumeState Pointer to resume state containing snapshot
 *  \return         kFblOk if snapshot has been correctly restored, kFblFailed otherwise
 **********************************************************************************************************************/
static tFblResult FblDiagRestoreSnapshot( V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * block,
                                          V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * segment,
                                          tResumeState * pBlockResumeState )
{
   tFblResult result;

#if ( SYSSERVICE_SECMODHIS_VERSION >= 0x0300u )
   result = kFblOk;

   if (FblMemRestoreSnapshot(pBlockResumeState->libMemSnapshot, block, segment) != kFblMemStatus_Ok)
   {
      result = kFblFailed;
   }
# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   if (result == kFblOk)
   {
      if (SecM_RestoreContext_VerifyClassDDD(pBlockResumeState->secModPipeSnapshot, pBlockResumeState->secModPipeSnapshotLength) != SECM_OK)
      {
         result = kFblFailed;
      }
   }
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED*/
   if (result == kFblOk)
   {
      if (SecM_RestoreContext_VerifySignature(pBlockResumeState->secModSnapshot, pBlockResumeState->secModSnapshotLength) != SECM_OK)
      {
         result = kFblFailed;
      }
   }
#else /* SYSSERVICE_SECMODHIS_VERSION >= 0x0300u */
   result = kFblFailed;

   if (FblMemRestoreSnapshot( pBlockResumeState->libMemSnapshot, block, segment) == kFblMemStatus_Ok )
   {
      (void)MEMCPY(sigParam.currentHash.sigResultBuffer, pBlockResumeState->secModSnapshot,  /* PRQA S 0314, 0326 */ /* MD_FblDiagOem_0314_0326_MemCpy */
         sigParam.currentHash.length);
# if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
      /* PRQA S 0314, 0326 1*/ /* MD_FblDiagOem_0314_0326_MemCpy */
      (void)MEMCPY(pipeSigParam.currentHash.sigResultBuffer, pBlockResumeState->secModPipeSnapshot, pipeSigParam.currentHash.length);
# endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

      result = kFblOk;
   }
#endif /* SYSSERVICE_SECMODHIS_VERSION >= 0x0300u */

   if (result == kFblOk)
   {
      /* Restore fingerprint value */
      fingerprintStatus = pBlockResumeState->resumeFpStatus;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagGetSnapshotInfo
 **********************************************************************************************************************/
/*! \brief          Get last valid programmed address
 *  \param[in,out]  validAddress Pointer to resume address used by caller
 *  \return         kFblOk if snapshot information is valid,
 *                  kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult FblDiagGetSnapshotInfo( V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * validAddress )
{
   tFblResult result;
   vuintx idx;

   result = kFblFailed;

   /* Iterate through snapshots, ordered by precedence. Start with dynamic snapshot */
   for (idx = 0u; (idx < kDiagNrOfResumeStates) && (result == kFblFailed); idx++)
   {
      if (FblMemGetSnapshotInfo( blockResumeStates[idx].libMemSnapshot, validAddress ) == kFblMemStatus_Ok )
      {
         result = kFblOk;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblMemCheckpointIndication
 **********************************************************************************************************************/
/*! \brief       Check if end of resume section has been reached
 *  \details     This function is called from LibMem to check if a resume section has been completed.
 *               If the end of a resume section has been reached, a state snapshot is created.
 *  \param[in]   validAddress Last written address
 *  \return      kFblOk if resume snapshot has been stored
 **********************************************************************************************************************/
void ApplFblMemCheckpointIndication(tFblAddress validAddress)
{
   tFblResult result;
   vuint16 lastResumeSection;

   lastResumeSection = FblDiagFindResumeSection(blockResumeStates[kDiagResumeInfoSectorIdx].resumeAddress);

   /* Check if end address of current resume section has been reached */
   if (validAddress >= FblResumeSectionTable[lastResumeSection].end)
   {
      /* Create snapshot of current states */
      result = FblDiagCreateSnapshot(&blockResumeStates[kDiagResumeInfoSectorIdx], validAddress);

      assertFblInternal((result == kFblOk), kFblOemAssertSnapshotCreateError);
   }
}

/***********************************************************************************************************************
 *  FblDiagGetResumeBlockNo
 **********************************************************************************************************************/
/*! \brief          Return logical block number if resume information exists
 *  \details        This function is called by ReadDataByIdentifier to get the current logical block number
 *  \param[in,out]  resumeBlockNo Pointer to active resume block used by caller
 *  \param[in,out]  resumeStartAddr Pointer to active resume address used by caller
 *  \return         kFblOk Resume state was created after a resumable step
 *                  kFblFailed Otherwise
 **********************************************************************************************************************/
tFblResult FblDiagGetResumeBlockNo( tFblLbtBlockNr *resumeBlockNo, tFblAddress *resumeStartAddr )
{
   tFblResult result;
   vuintx idx;

   result = kFblFailed;

   /* Get start address from last snapshot, start with dynamic snapshot */
   for (idx = 0u; (idx < kDiagNrOfResumeStates) && (result == kFblFailed); idx++)
   {
      if (blockResumeStates[idx].resumeStatus != kFblRsInitial)
      {
         /* At least one Snapshot has been created, return block number */
         *resumeBlockNo = blockResumeStates[idx].resumeBlockNo;
         *resumeStartAddr = blockResumeStates[idx].resumeAddress;
         result = kFblOk;
      }
      else
      {
         /* Resume block number not available */
         *resumeBlockNo = kBlockNrInvalid;
         *resumeStartAddr = 0uL;
      }
   }

   return result;
}

#endif /* FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING */

#if defined( FBL_ENABLE_OTA )
/***********************************************************************************************************************
*  FblDiagGetLastErasedBlock
**********************************************************************************************************************/
/*! \brief       Returns last erased logical block or kBlockNrInvalid if no block has been erased yet.
**********************************************************************************************************************/
vuint8 FblDiagGetLastErasedBlock(void)
{
   return lastErasedBlock;
}

/***********************************************************************************************************************
 *  FblDiagSetLastErasedBlock
 **********************************************************************************************************************/
/*! \brief       Sets last erased logical block.
 *  \param[in]   blockNr Block number of last erased logical block
 **********************************************************************************************************************/
void FblDiagSetLastErasedBlock(vuint8 blockNr)
{
   lastErasedBlock = blockNr;
}
#endif /* FBL_ENABLE_OTA */

#if defined( FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC ) && defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
/***********************************************************************************************************************
 *  FblDiagOfrLightWrapper
 **********************************************************************************************************************/
/*! \brief       Function to feed pipelined verification data to CMAC calculation for OFR light
 *  \param[in]   pVerifyParam Pointer to verification parameters
 *  \return      SECM_OK: Verification and CMAC update successful; Other: Verification and CMAC update failed
 **********************************************************************************************************************/
static SecM_StatusType FblDiagOfrLightWrapper(V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam)
{
   SecM_StatusType result;
   /* PRQA S 0313 1 */  /* MD_FblDiagOem_0313 */
   tFblMemVerifyFctInput verifyFunction = (tFblMemVerifyFctInput)downloadBlockDescriptor.verifyPipelined;

   result = verifyFunction(pVerifyParam);

   if (result == SECM_OK)
   {
      result = ApplFblPipelinedCalculateOfrLightCmac(pVerifyParam);
   }

   return result;
}
#endif /* FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC && FBL_MEM_ENABLE_VERIFY_PIPELINED */

/***********************************************************************************************************************
* Diagnostic pre handler service functions
**********************************************************************************************************************/

/***********************************************************************************************************************
*  FblDiagDefaultPreHandler
**********************************************************************************************************************/
/*! \brief         Pre-handler function to call ApplFblCheckConditions()
*  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
*  \param[in]     diagReqDataLen Length of data (without SID)
*  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
*********************************************************************************************************************/
static tFblResult FblDiagDefaultPreHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   return ApplFblCheckConditions(pbDiagData, diagReqDataLen);
}

#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
* Diagnostic post handler service functions
**********************************************************************************************************************/

/* Start section to execute code from RAM */
#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap*/

/***********************************************************************************************************************
*  FblDiagDefaultPostHandler
**********************************************************************************************************************/
/*! \brief       Can be used to switch to next state AFTER successful transmission of the service, e.g. EcuReset.
*  \param[in]   postParam Parameter indicating service response.
**********************************************************************************************************************/
void FblDiagDefaultPostHandler(vuint8 postParam)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)postParam;
#endif

   /* Unlock diagnostic connection in default session */
   if (FblDiagGetDefaultSession())
   {
      FblCwResetResponseAddress();
   }
}

/***********************************************************************************************************************
*  FblDiagSessionControlPostHandler
**********************************************************************************************************************/
/*! \brief       Set the BS and STmin with default value after successful transmission of the service 0x10 Session Control
*  \param[in]   postParam Parameter indicating service response.
**********************************************************************************************************************/
void FblDiagSessionControlPostHandler(vuint8 postParam)
{
   if ((postParam == kDiagPostPosResponse) || (postParam == kDiagPostNoResponse))
   {
      /* Use the default Block Size and STmin parameter */
#if (FBLCW_CHANGE_PARAMETER == STD_ON)
      (void)FblCw_ResetParameter();
#endif
   }

   /* Unlock diagnostic connection in default session */
   if (FblDiagGetDefaultSession())
   {
      FblCwResetResponseAddress();
   }
}

/* Stop section to execute code from RAM */
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblDiagOem_0313:
      Reason:     Signature/checksum verification functions are stored as void pointers as actual type is not known at
                  configuration time.
      Risk:       Function signature not compatible with expected type.
      Prevention: Integrator has to take care the configured functions match with the expected signature.

   MD_FblDiagOem_0314_Key:
      Reason:     The key param has a void pointer and an SecM_RamBufferType is cast to pointer void.
      Risk:       No risk, because the underlying pointer type is known and the cast is safe.
      Prevention: No prevention necessary.

   MD_FblDiagOem_0314_0326_MemCpy:
      Reason:     The copy function have a void pointer as a function parameter and an integer is casted to pointer void.
      Risk:       No risk, because the underlying pointer type is known and the cast is safe.
      Prevention: No prevention necessary.

   MD_FblDiagOem_0315:
      Reason:     The implicit conversion from a pointer to object type to a pointer to void is used calling function
      ApplFblSaveStatus that allows pointers to different object types as parameter.
      Risk:       No risk, because the underlying pointer type is known and the cast is safe.
      Prevention: No prevention necessary.

   MD_FblDiagOem_2985:
      Reason:     Result can vary in different configurations.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblDiagOem_2991_2995:
      Reason:     The value of the if-controlling expression depends on the configuration.
      Risk:       No risk.
      Prevention: No prevention necessary.

   MD_FblDiagOem_3415:
      Reason:     If condition relies on lazy evaluation, second argument only executed if initial condition is/isnot fullfilled.
      Risk:       No identifiable risk.
      Prevention: No prevention required.
*/
/***********************************************************************************************************************
 *  END OF FILE: FBL_DIAG_OEM.C
 **********************************************************************************************************************/
