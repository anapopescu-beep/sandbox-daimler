/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Diagnostic module external interface - OEM specific extension
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
 *  10.01.00   2021-01-19  viscb   ESCAN00108071    No changes
 *                         viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - response for programming session request is sent before transition
 *                                                    - Adapted interface for secure boot
 *                                                    - Logical block access by index value
 *  10.01.01   2021-02-02  viscb   ESCAN00108445    QM release
 *  10.01.02   2021-04-21  viscb   ESCAN00108537    No changes
 *                                 ESCAN00108093    Logical block can be verified with signature of other logical block
 *                                 ESCAN00108139    Routine Control - Prepare Vehicle Systems For Reprogramming
 *                                                   (0x0206) expects one byte too much
 *                                 FBL-3360         Added/adapted MemMap sections
 *  10.01.03   2021-05-28  viscb   ESCAN00109398    No changes
 *                                 ESCAN00109400    No changes
 *  10.01.04   2021-06.07  viscb   ESCAN00109435    No changes
 *                                 ESCAN00109437    Routine Control - Prepare Vehicle Systems For Reprogramming length
 *  10.02.00   2021-07-09  vishor  FBL-3567         Add support for Csm-based suspend/resume
 *                                 ESCAN00107081    Resumable programming at RoutineControl - checkMemory fails
 *  10.02.01   2021-08-26  visjdn  ESCAN00109069    No changes
 *  10.02.02   2021-10-27  visrie  ESCAN00109153    No changes
 *  10.03.00   2022-03-15  vishor  FBL-4621         MB MMA Rework
 *                                 ESCAN00110728    No changes
 *                                 ESCAN00110898    No changes
 *                                 ESCAN00110960    No changes
 *                                 ESCAN00111146    No changes
 *                                 ESCAN00111396    No changes
 *  10.04.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00110486    DFI 0x02 for production encryption is not accepted
 *  10.04.01   2022-06-27  vismix  ESCAN00112173    No changes
 *                                 ESCAN00112160    No changes
 *  10.04.02   2022-08-26  vismix  FBL-5754         Fix multiple issues
 *                                 ESCAN00112447    No changes
 *                                 ESCAN00112459    No changes
 *  10.04.03   2023-01-09  vismix  ESCAN00112744    No changes
 *                                 ESCAN00113013    No changes
 *                                 ESCAN00113078    No changes
 **********************************************************************************************************************/

#ifndef FBL_DIAG_OEM_H
#define FBL_DIAG_OEM_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : FblDiag_14229_Daimler CQComponent : Implementation */
#define FBLDIAG_14229_DAIMLER_VERSION              0x1004u
#define FBLDIAG_14229_DAIMLER_RELEASE_VERSION      0x03u

#define FBL_VERSION                                _VECTOR_SIP_VERSION
#define FBL_RELEASE_VERSION                        _VECTOR_SIP_RELEASE_VERSION
#define FBL_BUGFIX_VERSION                         _VECTOR_SIP_RELEASE_VERSION

/* Reference interface version */
/** Major interface version identifies incompatible changes */
#define FBL_DIAGCORE_API_REFERENCE_VERSION_MAJOR   0x04u
/** Minor interface version identifies backward compatible changes */
#define FBL_DIAGCORE_API_REFERENCE_VERSION_MINOR   0x01u
/** Release interface version identifies cosmetic changes */
#define FBL_DIAGCORE_API_REFERENCE_VERSION_RELEASE 0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
#if (!defined(FBL_ENABLE_SEC_ACCESS_DELAY) && !defined(FBL_DISABLE_SEC_ACCESS_DELAY))
# define FBL_ENABLE_SEC_ACCESS_DELAY
#endif

#if (!defined(FBL_ENABLE_MULTIPLE_PLATFORMS) && !defined(FBL_DISABLE_MULTIPLE_PLATFORMS))
# define FBL_DISABLE_MULTIPLE_PLATFORMS
#endif

/***********************************************************************************************************************
 *  Diagnostic configuration switches
 **********************************************************************************************************************/
# define FBL_ENABLE_TRANSFER_VERIFICATION_CHECK

/* Select featureset from diagnostic core */
#define FBL_DIAG_DISABLE_CORE_GETBLOCKNR
#define FBL_DIAG_ENABLE_CORE_SEGMENTHANDLING
#define FBL_DIAG_ENABLE_OEM_INIT
#define FBL_DIAG_ENABLE_14229_2013
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
# if defined( FBL_ENABLE_STATUS_BACKUP )
#  define FBL_DIAG_ENABLE_OEM_DEINIT
# endif
#endif

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
# define FBL_DIAG_ENABLE_OEM_TIMERTASK
#endif

#define FBL_DIAG_ENABLE_CORE_READ_SECACCESSDELAY_FLAG
#define FBL_DIAG_ENABLE_CORE_WRITE_SECACCESSDELAY_FLAG

#define FBL_DIAG_DISABLE_CORE_PREWRITE
#define FBL_DIAG_DISABLE_CORE_POSTWRITE

#define FBL_DIAG_ENABLE_SERVICE_PREHANDLER
#define FBL_DIAG_ENABLE_SERVICE_POSTHANDLER

#if !defined( FBL_DIAG_ENABLE_OEM_SPS_REQUEST ) && !defined( FBL_DIAG_DISABLE_OEM_SPS_REQUEST )
/* Initialize programming session request data from application on diag_oem layer */
# define FBL_DIAG_ENABLE_OEM_SPS_REQUEST
#endif

#ifndef kDiagCallCycle
# define kDiagCallCycle     1u
#endif

/* Posthandler function configuration */
#define kFblDiagResponseResetPostHandler                 FblDiagDefaultPostHandler
#define kFblDiagResponseSdsPostHandler                   FblDiagSessionControlPostHandler

/* ControlDTCSetting */
#define kDiagSubDtcOn                                    0x01u
#define kDiagSubDtcOff                                   0x02u

/* RoutineControl, RoutineIdentifier */
/* OEM specific RoutineControl, RoutineIdentifier */
#define kDiagRoutineIdChecksum                           0x0202u
#define kDiagRoutineIdChecksumHigh                       GET_ID_HIGH( kDiagRoutineIdChecksum )
#define kDiagRoutineIdChecksumLow                        GET_ID_LOW( kDiagRoutineIdChecksum )

#define kDiagRoutineIdCheckProgPrecond                   0x0203u
#define kDiagRoutineIdCheckProgPrecondHigh               GET_ID_HIGH( kDiagRoutineIdCheckProgPrecond )
#define kDiagRoutineIdCheckProgPrecondLow                GET_ID_LOW( kDiagRoutineIdCheckProgPrecond )

#define kDiagRoutineIdCFailSafeReaction                  0x0204u
#define kDiagRoutineIdCFailSafeReactionHigh              GET_ID_HIGH( kDiagRoutineIdCFailSafeReaction )
#define kDiagRoutineIdCFailSafeReactionLow               GET_ID_LOW( kDiagRoutineIdCFailSafeReaction )

#define kDiagRoutineIdVerifyMemoryContent                0x0205u
#define kDiagRoutineIdVerifyMemoryContentHigh            GET_ID_HIGH( kDiagRoutineIdVerifyMemoryContent )
#define kDiagRoutineIdVerifyMemoryContentLow             GET_ID_LOW( kDiagRoutineIdVerifyMemoryContent )

#define kDiagRoutineIdPrepVecicleSystForReprog           0x0206u
#define kDiagRoutineIdPrepVecicleSystForReprogHigh       GET_ID_HIGH( kDiagRoutineIdPrepVecicleSystForReprog )
#define kDiagRoutineIdPrepVecicleSystForReprogLow        GET_ID_LOW( kDiagRoutineIdPrepVecicleSystForReprog )

#define kDiagRoutineIdPreChkProgDepend                   0x0207u
#define kDiagRoutineIdPreChkProgDependHigh               GET_ID_HIGH( kDiagRoutineIdPreChkProgDepend )
#define kDiagRoutineIdPreChkProgDependLow                GET_ID_LOW( kDiagRoutineIdPreChkProgDepend )

#define kDiagRoutineIdEraseMemory                        0xFF00u
#define kDiagRoutineIdEraseMemoryHigh                    GET_ID_HIGH( kDiagRoutineIdEraseMemory )
#define kDiagRoutineIdEraseMemoryLow                     GET_ID_LOW( kDiagRoutineIdEraseMemory )

#define kDiagRoutineIdCheckProgDep                       0xFF01u
#define kDiagRoutineIdCheckProgDepHigh                   GET_ID_HIGH( kDiagRoutineIdCheckProgDep )
#define kDiagRoutineIdCheckProgDepLow                    GET_ID_LOW( kDiagRoutineIdCheckProgDep )

/* RequestDownload, DataIdentifier */
#define kDiagFmtLengthMask                               0xF0u
#define kDiagFmtAddrMask                                 0x0Fu

#define kDiagFmtAddrValue                                0x04u
#define kDiagFmtLengthValue                              0x40u

#define kDiagFmtFixedAddrSize                            0x04u
#define kDiagFmtFixedLengthSize                          0x04u

/* Diagnostic service index to diagnostic parameters. */
/* This index shall only be used with the pointer to diag-buffer */
/* that was passed to the function as a parameter.               */
/* NOTE:  You MUST NOT use the kDiagLocFmtXxx with the global DiagBuffer!!! */
#define kDiagLocFmtSubparam                              0x00u                               /**< Position of DID */
#define kDiagLocFmtSubfunction                           0x00u                               /**< Position of Subfunction */
#define kDiagLocFmtDataIdHigh                            0x00u                               /**< Position of data identifier (MSB) */
#define kDiagLocFmtDataIdLow                             (kDiagLocFmtDataIdHigh + 1u)        /**< Position of data identifier (LSB) */
#define kDiagLocFmtSubFctDataIdHigh                      (kDiagLocFmtSubfunction + 1u)       /**< Position of data identifier (MSB) for a subfunction */
#define kDiagLocFmtSubFctDataIdLow                       (kDiagLocFmtSubFctDataIdHigh + 1u)  /**< Position of data identifier (LSB) for a subfunction */
#define kDiagLocFmtDataRecord                            (kDiagLocFmtDataIdLow + 1u)         /**< Position of record data identifier */
#define kDiagLocFmtSequenceCnt                           0x00u                               /**< Position of sequence counter */
#define kDiagLocFmtDataOffset                            (kDiagLocFmtSequenceCnt + 1u)       /**< Offset to download data in TransferData frame */
#define kDiagLocFmtFormatOffset                          0x01u
#define kDiagLocFmtNegResponse                           (kDiagLocFmtSubparam + 1u)          /**< Position of negative response code */
#define kDiagLocFmtAddrOffset                            0x02u
#define kDiagLocFmtRoutineIdHigh                         (kDiagLocFmtSubparam + 1u)          /**< RoutineControl service formats */
#define kDiagLocFmtRoutineIdLow                          (kDiagLocFmtRoutineIdHigh + 1u)
#define kDiagLocFmtRoutineOption                         (kDiagLocFmtRoutineIdLow + 1u)
#define kDiagLocFmtRoutineInfo                           (kDiagLocFmtRoutineIdLow + 1u)
#define kDiagLocFmtRoutineStatus                         (kDiagLocFmtRoutineInfo + 1u)
#define kDiagLocFmtStartAddress                          (kDiagLocFmtRoutineIdLow + 1u)
#define kDiagLocFmtStopAddress                           (kDiagLocFmtStartAddress+FBL_ADDRESSLEN)
#define kDiagLocFmtChecksumHigh                          (kDiagLocFmtStopAddress+FBL_ADDRESSLEN)
#define kDiagLocFmtChecksumLow                           (kDiagLocFmtChecksumHigh + 1u)
#define kDiagLocFmtSeedKeyStart                          (kDiagLocFmtSubparam + 1u)          /**< Start index of seed/key value */

/* Data identifier for ReadDataByIdentifier service */
#define kDiagDataIdProgrammingAttemptCounter             0x0100u
#define kDiagDataIdIsoTpBlockSizeSTminParameter          0x010Bu
#define kDiagDataIdReprogrammingErrorStatus              0x010Eu
#define kDiagDataIdReprogrammingResumeInfo               0x0120u
#define kDiagDataIdIsoTpBandwithControlParameter         0x012Bu
#define kDiagDataIdActiveDiagnosticInformation           0xF100u
#define kDiagDataIdEcuName                               0xF104u
#define kDiagDataIdMercedHardwarePartNumber              0xF111u
#define kDiagDataIdMercedTruckHardwarePartNumber         0xF116u
#define kDiagDataIdFreightlinerHardwarePartNumber        0xF117u
#define kDiagDataIdMercedSoftwarePartNumber              0xF121u
#define kDiagDataIdMercedTruckSoftwarePartNumber         0xF126u
#define kDiagDataIdFreightlinerSoftwarePartNumber        0xF127u
#define kDiagDataIdHardwareVersionInformation            0xF150u
#define kDiagDataIdSoftwareVersionInformation            0xF151u
#define kDiagDataIdBootSoftwareVersionInformation        0xF153u
#define kDiagDataIdHardwareSupplierInformation           0xF154u
#define kDiagDataIdSoftwareSupplierInformation           0xF155u
#define kDiagDataIdWriteSoftwareFingerprint              0xF15Au
#define kDiagDataIdReadSoftwareFingerprint               0xF15Bu
#define kDiagDataIdStandardBootloaderSoftwareInformation 0xEF02u
#define kDiagDataIdMinimumSoftwareVersion                0xEF05u
#define kDiagDataIdDiagnosticSpecificationInformation    0xF10Du
#define kDiagDataIdDiagnosticSpecVersionInformationSDD   0xF1A2u

/* Data identifier for WriteDataByIdentifier service */
#define kDiagWriteFingerprintIdHigh                      GET_ID_HIGH(kDiagDataIdWriteSoftwareFingerprint)
#define kDiagWriteFingerprintIdLow                       GET_ID_LOW(kDiagDataIdWriteSoftwareFingerprint)

#define kDiagWriteBlockSizeSTminHigh                     GET_ID_HIGH(kDiagDataIdIsoTpBlockSizeSTminParameter)
#define kDiagWriteBlockSizeSTminLow                      GET_ID_LOW(kDiagDataIdIsoTpBlockSizeSTminParameter)

/* RoutineControl response codes */

/* routineInfo */
#define kDiagRoutineInfoSuccessful                       0x00u
#define kDiagRoutineInfoInProgress                       0x01u
#define kDiagRoutineInfoStopped                          0x02u

#define kDiagCheckVerificationFailed                     0x01u
#define kDiagCheckDependenciesFailed                     0x01u
#define kDiagGapFillFailed                               0x80u
#define kDiagLbtInvalid                                  0x40u

/* RoutineControl - verifyMemoryContents response codes */
#define kDiagCheckVerificationPassed                     0x00u
#define kDiagCheckVerificationGeneralError               0x01u
#define kDiagCrcErrorCRCCheckFailed                      0x02u

/* Module Dependency check return values */
#define kDiagDependencyCheckOk                           0x00u
#define kDiagDependencyCheckFailedSwHw                   0x02u
#define kDiagDependencyCheckFailedSwSw                   0x03u
#define kDiagDependencyCheckFailedBlkNotValid            0x04u
#define kDiagDependencyCheckFailedDowngrade              0x05u

/* Fingerprint status information */
#define kDiagFpStatApplValid                             0x01u
#define kDiagFpStatSwSwMismatch                          0x02u
#define kDiagFpStatSwHwMismatch                          0x04u
#define kDiagFpStatMemErased                             0x08u
#define kDiagFpStatMemProgrammed                         0x00u

/* Reprogramming process state of fingerprint status */
#define kDiagFpStatMask                                  0x70u
#define kDiagFpStatEraseStarted                          0x10u
#define kDiagFpStatEraseFinished                         0x20u
#define kDiagFpStatReprogStarted                         0x30u
#define kDiagFpStatMemCheckSucceeded                     0x40u
#define kDiagFpStatMemCheckFailed                        0x50u
#define kDiagFpStatCompatCheckFailed                     0x60u
#define kDiagFpStatOk                                    0x00u

#define ClrReprogProcessState(val)                       ((val) &= FblInvert8Bit(kDiagFpStatMask))
#define SetReprogProcessState(val, newState)             {                                \
                                                            ClrReprogProcessState(val);   \
                                                            (val) |= (newState);          \
                                                         }

/* Get the RAM mirror of fingerprint status */
#define GetFingerprintStatus()                           (fingerprintStatus)

/* -- Defines length of service request         -- */
/* -- (if applicable; excluding the Service-ID. -- */
#define kDiagRqlDiagnosticSessionControl                  (0x01u+kDiagRqlDiagnosticSessionControlParameter)
#define kDiagRqlEcuReset                                   0x01u
#define kDiagRqlSecurityAccessSeed                        (0x01u+kDiagRqlSecurityAccessSeedParameter)
#define kDiagRqlSecurityAccessKey                         (0x01u+kDiagRqlSecurityAccessKeyParameter)
#define kDiagRqlCommunicationControl                       0x02u
#define kDiagRqlReadDataByIdentifier                       0x02u
#define kDiagRqlWriteDataByIdentifier                      0x02u
#define kDiagRqlMinWriteDataByIdentifier                  (kDiagRqlWriteDataByIdentifier + 1u)
#define kDiagRqlWriteDataByIdentifierFingerPrint          (kDiagRqlWriteDataByIdentifier + \
                                                                      kDiagRqlWriteDataByIdentifierFingerPrintParameter)
#define kDiagRqlWriteDataByIdentifierSoftwareId           (kDiagRqlWriteDataByIdentifier + \
                                                                      kDiagRqlWriteDataByIdentifierSoftwareIdParameter)
#if (FBLCW_CHANGE_PARAMETER == STD_ON)
# define kDiagRqlWriteDataByIdentifierIsoTpBlockSizeSTmin (kDiagRqlWriteDataByIdentifier + \
                                                                      kDiagRqlWriteDataByIdentifierIsoTpBlockSizeSTminParameter)
#endif

#define kDiagRqlRoutineControl                           0x03u
#define kDiagRqlRoutineControlCheckRoutine               (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineControlCheckRoutineParameter)
#define kDiagRqlRoutineControlChkProgPrecond             (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineControlChkProgPrecondParameter)
#define kDiagRqlRoutineControlFailSafeReactStart         (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineControlFailSafeReactStartParameter)
#define kDiagRqlRoutineControlFailSafeReactStop          (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineControlFailSafeReactStopParameter)
#define kDiagRqlRoutineControlVerifyMemoryContent        (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineControlVerifyMemoryContentParameter)
#define kDiagRqlRoutineControlPrepVehicleSystForReprog   (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineControlPrepVehicleSystForReprogParameter)
#define kDiagRqlRoutineControlPreChkProgDepend           (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineControlPreChkProgDependParameter)

#define kDiagRqlRoutineControlEraseRoutine               (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineControlEraseRoutineParameter)
#define kDiagRqlRoutineCheckComptDependencies            (kDiagRqlRoutineControl + \
                                                          kDiagRqlRoutineCheckComptDependenciesParameter)

#define kDiagRqlRequestDownload                           0x02u  /* (SId) + DFI + ALFI */
#define kDiagRqlRequestDownloadMemSize                   (kDiagRqlRequestDownload + \
                                                          kDiagRqlRequestDownloadMinMemMinSize) /* + min mem addr + min mem size  */
#define kDiagRqlRequestUpload                             0x02u  /* + Memory address and size OEM-specific */
#define kDiagRqlTransferData                              0x01u  /* + Download data */
#define kDiagRqlRequestTransferExit                      (0x00u+kDiagRqlRequestTransferExitParameter)
#define kDiagRqlTesterPresent                             0x01u
#define kDiagRqlControlDTCSetting                        (0x01u+kDiagRqlControlDTCSettingParameter)

/* -- Defines for response length codes         -- */
/* -- (if applicable; excluding the Service-ID. -- */
#define kDiagRslDiagnosticSessionControl                 (0x01u+kDiagRslDiagnosticSessionControlParameter)
#define kDiagRslEcuReset                                 (0x01u+kDiagRslEcuResetParameter)
#define kDiagRslSecurityAccessSeed                       (0x01u+kDiagRslSecurityAccessSeedParameter)
#define kDiagRslSecurityAccessKey                        (0x01u+kDiagRslSecurityAccessKeyParameter)
#define kDiagRslCommunicationControl                      0x01u
#define kDiagRslReadDataByIdentifier                      0x02u
#define kDiagRslWriteDataByIdentifier                     0x02u
#define kDiagRslRoutineControlEraseRoutine               (0x04u+kDiagRslRoutineControlEraseRoutineParameter)
#define kDiagRslRoutineControlCheckRoutine               (0x04u+kDiagRslRoutineControlCheckRoutineParameter)
#define kDiagRslRequestDownload                           0x01u /* + maxNumberOfBlockLength */
#define kDiagRslTransferData                             (0x01u+kDiagRslTransferDataParameter)
#define kDiagRslRequestTransferExit                      (0x00u+kDiagRslRequestTransferExitParameter)
#define kDiagRslTesterPresent                             0x01u
#define kDiagRslControlDTCSetting                         0x01u

/* Diagnostic service format definitions */
#define kDiagFmtServiceId                                0x00u                            /**< Position of service id             */
#define kDiagFmtpbDiagData                               0x01u                            /**< Access parameter to remove serice ID */
#define kDiagFmtSubparam                                 (kDiagFmtServiceId + 1u)         /**< Position of DID                    */
#define kDiagFmtDataIdHigh                               (kDiagFmtServiceId + 1u)         /**< Position of data identifier (MSB)  */
#define kDiagFmtDataIdLow                                (kDiagFmtDataIdHigh + 1u)        /**< Position of data identifier (LSB)  */
#define kDiagFmtSubFctDataIdHigh                         (kDiagFmtSubparam + 1u)          /**< Position of data identifier (MSB)  */
#define kDiagFmtSubFctDataIdLow                          (kDiagFmtSubFctDataIdHigh + 1u)  /**< Position of data identifier (LSB)  */
#define kDiagFmtDataRecord                               (kDiagFmtDataIdLow + 1u)         /**< Position of record data identifier */
#define kDiagFmtSequenceCnt                              (kDiagFmtServiceId + 1u)         /**< Position of sequence counter       */
#define kDiagFmtDataOffset                               (kDiagFmtSequenceCnt + 1u)       /**< Offset to download data in TransferData frame */
#define kDiagFmtFormatOffset                             0x02u
#define kDiagFmtNegResponse                              (kDiagFmtSubparam + 1u)          /**< Position of negative response code */
#define kDiagFmtAddrOffset                               0x03u
#define kDiagFmtRoutineIdHigh                            (kDiagFmtSubparam + 1u)          /**< RoutineControl service formats     */
#define kDiagFmtRoutineIdLow                             (kDiagFmtRoutineIdHigh + 1u)
#define kDiagFmtRoutineOption                            (kDiagFmtRoutineIdLow + 1u)
#define kDiagFmtRoutineInfo                              (kDiagFmtRoutineIdLow + 1u)
#define kDiagFmtRoutineStatus                            (kDiagFmtRoutineInfo + 1u)
#define kDiagFmtStartAddress                             (kDiagFmtRoutineIdLow + 1u)
#define kDiagFmtStopAddress                              (kDiagFmtStartAddress + 4u)
#define kDiagFmtChecksumHigh                             (kDiagFmtStopAddress + 4u)
#define kDiagFmtChecksumLow                              (kDiagFmtChecksumHigh + 1u)
#define kDiagFmtSeedKeyStart                             (kDiagFmtSubparam + 1u)          /**< Start index of seed/key value      */

/* Defines for address and length format identifier */
#if !defined(kDiagEraseMemoryALFI)
# define kDiagEraseMemoryALFI                            0x01u
#endif

/* Threshold timer for P2 to trigger an RCR-RP */
#ifndef kFblDiagP2MinThreshold
# define kFblDiagP2MinThreshold                          (kDiagSessionTimingP2/2)
#endif

/* Threshold timer for P2-Star to trigger an RCR-RP */
#ifndef kFblDiagP2StarMinThreshold
# define kFblDiagP2StarMinThreshold                      (kDiagSessionTimingP2StarRaw/2)
#endif

/* Defines for bootloader state flags */
#define kFblDiagStateFingerprintValid                    ( kFblDiagLastCoreStateIdx + 1u ) /**< WriteFingerprint received */
#define kFblDiagStateTransferDataAllowed                 ( kFblDiagLastCoreStateIdx + 2u ) /**< RequestDownload received->TransferData allowed */
#define kFblDiagStateSecurityKey                         ( kFblDiagLastCoreStateIdx + 3u ) /**< Valid seed indicated. Key now allowed */
#define kFblDiagStateSecurityAccess                      ( kFblDiagLastCoreStateIdx + 4u ) /**< SecurityAccess successfully passed */
#define kFblDiagStateCheckMemorySucceeded                ( kFblDiagLastCoreStateIdx + 5u ) /**< Check memory successfully */
#define kFblDiagStateTransferDataSucceeded               ( kFblDiagLastCoreStateIdx + 6u ) /**< TransferData successfully */
#define kFblDiagStateEraseSucceeded                      ( kFblDiagLastCoreStateIdx + 7u ) /**< Flash Erase successfully  */
#define kFblDiagStateTransferExitAllowed                 ( kFblDiagLastCoreStateIdx + 8u ) /**< TransferData received->RequestTransferExit allowed */
#define kFblDiagStatePreCheckProgDepFailed               ( kFblDiagLastCoreStateIdx + 9u ) /**< Pre-Check Programming Dependencies->EraseMemory not allowed */

/* Resumable downlod */
#define kFblDiagStateResumeInfRequested                  ( kFblDiagLastCoreStateIdx + 10u ) /**< Status of resumable programming */
#define kFblDiagStateDelta                               ( kFblDiagLastCoreStateIdx + 11u )/**< Delta download requested */

/* Multiple platforms */
#define kFblDiagStatePlatformMsgWindow                   ( kFblDiagLastCoreStateIdx + 12u )/**< Status of platform message window */

#define kFblDiagStateCheckMemoryAllowed                  ( kFblDiagLastCoreStateIdx + 13u )/**< ReqTransferExit received -> checkMemory allowed */
#define kFblDiagLastOemStateIdx                            kFblDiagStateCheckMemoryAllowed

/* Macros to access the current diag state */

/* Macros for state flag access */
#define FblDiagGetFingerprintValid()                     GetFblDiagState( kFblDiagStateFingerprintValid )
#define FblDiagGetSecurityKeyAllowed()                   GetFblDiagState( kFblDiagStateSecurityKey )
#define FblDiagGetSecurityUnlock()                       GetFblDiagState( kFblDiagStateSecurityAccess )
#define FblDiagGetTransferDataAllowed()                  GetFblDiagState( kFblDiagStateTransferDataAllowed )
#define FblDiagGetTransferDataSucceeded()                GetFblDiagState( kFblDiagStateTransferDataSucceeded )
#define FblDiagGetEraseSucceeded()                       GetFblDiagState( kFblDiagStateEraseSucceeded)
#define FblDiagGetCheckMemorySucceeded()                 GetFblDiagState( kFblDiagStateCheckMemorySucceeded )
#define FblDiagGetPreCheckProgDepFailed()                GetFblDiagState( kFblDiagStatePreCheckProgDepFailed )
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
# define FblDiagGetResumeInfRequested()                  GetFblDiagState( kFblDiagStateResumeInfRequested )
# define FblDiagSetResumeInfRequested()                  SetFblDiagState( kFblDiagStateResumeInfRequested )
# define FblDiagClrResumeInfRequested()                  ClrFblDiagState( kFblDiagStateResumeInfRequested )
#endif
#define FblDiagGetDeltaDownload()                        GetFblDiagState( kFblDiagStateDelta )
#define FblDiagGetPlatformMsgWindow()                    GetFblDiagState( kFblDiagStatePlatformMsgWindow )
#define FblDiagGetCheckMemoryAllowed()                   GetFblDiagState( kFblDiagStateCheckMemoryAllowed )

#if defined( FBL_ENABLE_DEBUG_STATUS )
/* Error codes for error status reporting */
# define FBL_ERR_NONE                                    0x00u

# define FBL_ERR_FLASH_ERASE_ERROR                       0x10u
# define FBL_ERR_FLASH_PROG_ERROR                        0x11u
# define FBL_ERR_FLASH_PROG_CONDITIONS                   0x12u

# define FBL_ERR_APPL_OVERLAPPING                        0x20u
# define FBL_ERR_APPL_NOT_ALIGNED                        0x21u
# define FBL_ERR_TOO_MANY_SEGMENTS_IN_MODULE             0x22u
# define FBL_ERR_NO_MEMORY_REGION_FOUND                  0x23u
# define FBL_ERR_SEED_GENERATION_FAILED                  0x24u
# define FBL_ERR_GAP_FILL                                0x25u
# define FBL_ERR_VERIFICATION                            0x26u
# define FBL_ERR_DATA_OVERFLOW                           0x27u

# define FBL_ERR_FLASHCODE_INIT_FAILED                   0x30u
# define FBL_ERR_FLASHCODE_EXCEEDS_MEMORY                0x31u
# define FBL_ERR_FLASHCODE_NOT_ACCEPTED                  0x32u

# define FBL_ERR_LBT_MISSING_INVALID_FORMAT              0x40u
# define FBL_ERR_LBT_ADDR_MISMATCH                       0x41u
# define FBL_ERR_LBT_BLOCK_INDEX_EXCEEDED                0x42u
# define FBL_ERR_LBT_NOT_REPROGRAMMABLE                  0x43u
# define FBL_ERR_LBT_BLOCK_INDEX_ILLEGAL                 0x44u

/* Macros for error status reporting */
# define FblErrStatSetSId(id)                            (errStatLastServiceId = (id))
# define FblErrStatSetState(state)                       (errStatFblStates = (state))
# define FblErrStatSetFlashDrvError(error)               (errStatFlashDrvErrorCode = (error))
# define FblErrStatSetFlashDrvVersion()                  { \
                                                            errStatFlashDrvVersion[0] = flashCode[0]; \
                                                            errStatFlashDrvVersion[1] = flashCode[1]; \
                                                            errStatFlashDrvVersion[2] = flashCode[3]; \
                                                         }
# define FblErrStatSetError(error)                       (errStatErrorCode = (error))
# define FblErrStatSetBlockNr(blockNumber)               (errStatDescriptor.blockNr = (blockNumber))
# define FblErrStatSetAddress(address)                   (errStatDescriptor.blockStartAddress = (address))
#else
# define FblErrStatSetSId(id)
# define FblErrStatSetState(state)
# define FblErrStatSetFlashDrvError(error)
# define FblErrStatSetFlashDrvVersion()
# define FblErrStatSetError(error)
# define FblErrStatSetBlockNr(blockNr)
# define FblErrStatSetAddress(address)
#endif

/* Macros for tester present timer */
#define DIAG_CALL_CYCLE                                  kDiagCallCycle

#ifndef TESTER_PRESENT_TIMEOUT
# define TESTER_PRESENT_TIMEOUT                          5000u
#endif

#define InitTesterTimeoutLong()                          (testerPresentTimeout = (vuint16)(TESTER_PRESENT_TIMEOUT_LONG/DIAG_CALL_CYCLE))

/* Sequence counter retry init number */
# define kDiagInitDataRetries                            0x05u

/* Error state function, removed if not defined */
#if !defined(FblErrStatSetAddress)
# define FblErrStatSetAddress(address)
#endif
#if !defined(FblErrStatSetError)
# define FblErrStatSetError(errNo)
#endif
#if !defined(FblErrStatSetSId)
# define FblErrStatSetSId(SId)
#endif

/* Macros for security access */
#define kDiagSubSecTypeMask                              0x7Fu
#define kDiagSubRequestSeed                              0x11u
#define kDiagSubSendKey                                  0x12u
#define kSecSeedLength                                   SEC_SEED_LENGTH
#define kSecKeyLength                                    SEC_KEY_LENGTH

/* Verification constants */
#define kSecSigSizeCCC                                   SEC_VERIFY_CLASS_CCC_VERIFY_SIZE
#define kSecSigSize                                      kSecSigSizeCCC
#define kSecCRCSize                                      SEC_SIZE_CHECKSUM_CRC

#define kSecLenInfoLength                                0x01u /* Length information for CRC-length in request */
#define kSecCRCLength                                    (kSecLenInfoLength + kSecCRCSize)
#define kSecSigLength                                    kSecSigSize

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
# define kSecMaxInvalidKeys                              0x01u
# if !defined( FBL_SEC_ACCESS_DELAY_TIME )
#  define FBL_SEC_ACCESS_DELAY_TIME                      10000u
# endif
#endif

/* Access macros for user diagnostic call-backs */

/* -- Defines for additional length codes for optional request parameters -- */
/* -- only if applicable; excluding the Service-ID.                       -- */
#define kDiagRqlDiagnosticSessionControlParameter           0x00u
#define kDiagRqlSecurityAccessSeedParameter                 0x00u
#define kDiagRqlSecurityAccessKeyParameter                  kSecKeyLength
#define kDiagRqlWriteDataByIdentifierFingerPrintParameter   0x13u
#if (FBLCW_CHANGE_PARAMETER == STD_ON)
# define kDiagRqlWriteDataByIdentifierIsoTpBlockSizeSTminParameter 0x02u
#endif
#define kDiagRqlRoutineControlEraseRoutineParameter         0x02u
#define kDiagRqlRoutineControlCheckRoutineParameter         (kSecSigLength + kSecCRCLength)
#define kDiagRqlRequestTransferExitParameter                0x00u
#define kDiagRqlRoutineControlFailSafeReactStartParameter   0x01u
#define kDiagRqlRoutineControlFailSafeReactStopParameter    0x01u /* No routine option byte with this routine */

#define kDiagRqlRoutineControlVerifyMemoryContentParameter  0x07u
#define kDiagRqlRoutineControlPrepVehicleSystForReprogParameter   0x02u
#define kDiagRqlRoutineControlPreChkProgDependParameter     0x02u

#define kDiagRqlRoutineCheckComptDependenciesParameter      0x00u
#define kDiagRqlRoutineControlChkProgPrecondParameter       0x00u
#define kDiagRqlControlDTCSettingParameter                  0x00u
#define kDiagRqlCheckProgPreconditions                      0x03u
#define kDiagRqlRequestDownloadMinMemMinSize                0x02u /* min memory address (1 byte) + min memory size (1 byte) */

/* -- Defines for additional length codes for optional response parameters -- */
/* -- only if applicable; excluding the Service-ID.                        -- */
#define kDiagRslEcuResetParameter                           0x00u
#define kDiagRslDiagnosticSessionControlParameter           0x04u
#define kDiagRslSecurityAccessSeedParameter                 kSecSeedLength
#define kDiagRslSecurityAccessKeyParameter                  0x00u
#define kDiagRslRoutineControlEraseRoutineParameter         0x01u
#define kDiagRslRoutineControlCheckRoutineParameter         0x01u
#define kDiagRslTransferDataParameter                       0x00u
#define kDiagRslRequestTransferExitParameter                0x00u

#define kFblCanTpRxSduCount   sizeof(CanTp_RxSduCfg) / sizeof(CanTp_RxSduCfgType)

/* RoutineStatus codes for RoutineControl - eraseMemory positive response */
#define kFblCondOk                                          0x00u
#define kFblCondGeneralError                                0x01u
#define kFblCondVoltageTooHigh                              0x02u
#define kFblCondVoltageTooLow                               0x03u
#define kFblCondTemperatureTooHigh                          0x04u
#define kFblCondTemperatureTooLow                           0x05u

/* Special values for indices into logical block table */
#define kBlockNrInvalid                                     0xFFu

#define kDiagResumeInfoDynamicIdx                           0x00u
#define kDiagResumeInfoSectorIdx                            0x01u
#define kDiagNrOfResumeStates                               (kDiagResumeInfoSectorIdx + 1u)

/***********************************************************************************************************************
*  Data processing
**********************************************************************************************************************/

#define kDiagSubDevelopmentEncryption                       0x01u
#define kDiagSubProductionEncryption                        0x02u
#define kDiagSubDefaultCompression                          0x01u

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
void FblDiagSessionControlPostHandler( vuint8 postParam );
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLDIAG_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
vuint8 FblDiagCheckPlatformMsg(P2CONST(PduInfoType, AUTOMATIC, FBLPLATFORMMESSAGE_APPL_DATA) PduInfoPtr);
#endif  /* FBL_ENABLE_MULTIPLE_PLATFORMS    */

tFblResult FblDiagMemPreErase( void );
tFblResult FblDiagMemPostErase( void );

#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
tFblResult FblDiagGetResumeBlockNo( tFblLbtBlockNr *resumeBlockNo, tFblAddress *resumeStartAddr );
tFblResult FblDiagGetSnapshotInfo( V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * validAddress );
#endif

#if defined( FBL_ENABLE_OTA )
vuint8 FblDiagGetLastErasedBlock(void);
void FblDiagSetLastErasedBlock(vuint8 blockNr);
#endif /* FBL_ENABLE_OTA */

#define FBLDIAG_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLDIAG_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 extern V_MEMRAM1_NEAR vuint8             V_MEMRAM2_NEAR flashState;
V_MEMRAM0 extern V_MEMRAM1_NEAR vuint8             V_MEMRAM2_NEAR diagSessionCurrent;

#if defined( FBL_ENABLE_DEBUG_STATUS )
/* Variables for error status reporting */
V_MEMRAM0 extern V_MEMRAM1      vuint16            V_MEMRAM2      errStatErrorCode;
V_MEMRAM0 extern V_MEMRAM1      vuint16            V_MEMRAM2      errStatFblStates;
V_MEMRAM0 extern V_MEMRAM1      vuint8             V_MEMRAM2      errStatLastServiceId;
V_MEMRAM0 extern V_MEMRAM1      vuint8             V_MEMRAM2      errStatFlashDrvVersion[3];
V_MEMRAM0 extern V_MEMRAM1      vuint16            V_MEMRAM2      errStatFlashDrvErrorCode;
V_MEMRAM0 extern V_MEMRAM1      tBlockDescriptor   V_MEMRAM2      errStatDescriptor;
#endif

V_MEMRAM0 extern V_MEMRAM1 vuint8  V_MEMRAM2 fingerprintStatus;

#define FBLDIAG_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* FBL_DIAG_OEM_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_DIAG_OEM.H
 **********************************************************************************************************************/
