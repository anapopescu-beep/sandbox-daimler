/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent nonvolatile memory access routines
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
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
 *  02.00.00   2019-03-12  visrie  ESCAN00102453    Added support for LibNvPattern, LibLbtAccess and SecureBoot
 *  03.00.00   2020-10-14  viscb   FBL-2177         DRECU2020-01 adaptions, additional callout functions
 *  03.01.00   2021-01-19  viscb   ESCAN00107756    No changes
 *                         viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Adapted interface for secure boot
 *                                                    - Simplified updater integration
 *                                                    - Added support for OTA
 *                                                    - Added support for downgrade protection
 *                                                    - Migration to MISRA 2012
 *  03.01.01   2021-02-02  viscb   ESCAN00108450    QM release
 *  03.02.00   2021-04-21  viscb   ESCAN00108552    No changes
 *                         viscb   ESCAN00108672    No changes
 *                         viscb   ESCAN00108921    No changes
 *  03.03.00   2022-03-16  vishor  FBL-4621         No changes
 *                                 ESCAN00110813    No changes
 *                                 ESCAN00110836    No changes
 *  03.04.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00111479    No changes
 *  03.04.01   2022-08-31  visjns  FBL-5754         Programming attempts check fails with OTA update
 *  03.04.02   2022-12-15  visjdn  ESCAN00112522    No changes
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2018-09-14  visrie  ESCAN00100739    Added support for FblLib_NvPattern
 *                                                  Removed unused code
 *                         viscb   ESCAN00101418    Callout function for memory condition check
 *                         visach  ESCAN00101686    No changes
 *  02.01.00   2019-02-26  visrie  ESCAN00102257    Added additional callout functions
 *  02.01.01   2019-09-23  visrie  FBL-452          No changes
 *  02.02.00   2019-12-05  visrie  FBL-458          Added FblMio callout functions
 *  02.03.00   2020-05-07  visrie  FBL-1414         Added callout functions for One-Step-Updater
 *  02.03.01   2020-06-02  visjdn  ESCAN00106533    No changes
 *  02.03.02   2020-09-14  visrcn  FBL-2257         No changes
 *  02.03.03   2020-11-23  visrcn  FBL-2564         No changes
 *  02.03.04   2021-03-19  visjdn  FBL-2916         No changes
 *  02.04.00   2021-05-25  vishor  FBL-3165         MISRA corrections and justifications
 *  02.05.00   2021-06-15  visrie  FBL-3591         No changes
 *  02.06.00   2021-07-15  visjdn  FBL-3381         Re-mapping of EcuM_SetWakeupEvent
 *  02.07.00   2021-07-23  visrie  FBL-3822         No changes
 *  02.08.00   2021-09-14  visjdn  FBL-2859         No changes
 *  02.09.00   2021-10-12  vistmo  FBL-3901         Add authentication callbacks
 *  02.10.00   2021-10-15  visrie  FBL-3945         Remove content of ApplFblStartApplication
 *  02.10.01   2021-11-12  vishor  ESCAN00110133    Compiler error: Unknown symbols
 *                                                   ApplFblSave/RestoreStatusSector/Dynamic
 *  02.10.02   2022-06-27  visrie  FBL-4694         No changes
 *  02.10.03   2022-10-20  visjns  FBL-5452         No changes
 *  02.11.00   2022-12-22  vistbe  FBL-5691         No changes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY (KbFbl_apOem.h)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2019-03-12  visrie  ESCAN00102454    Added support for LibNvPattern, LibLbtAccess and SecureBoot
 *  02.00.01   2019-04-29  viscb   ESCAN00102998    No changes
 *  03.00.00   2020-10-06  viscb   FBL-2177         DRECU2020-01 adaptions, data processing
 *  03.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Simplified updater integration
 *                                                    - Added support for OTA
 *                                                    - Added support for downgrade protection
 *                                                    - Migration to MISRA 2012
 *  03.01.01   2021-02-02  viscb   ESCAN00108447    QM release
 *  03.02.00   2021-04-21  viscb   ESCAN00108550    No changes
 *                                 ESCAN00108549    No changes
 *                                 ESCAN00108532    No changes
 *                                 ESCAN00108591    No changes
 *  03.03.00   2021-07-12  vishor  FBL-3567         No changes
 *  03.03.01   2021-08-24  vishor  ESCAN00109880    No changes
 *  03.03.02   2021-08-27  vishor  ESCAN00109972    No changes
 *  03.03.03   2021-10-19  vistmo  ESCAN00110504    No changes
 *  03.03.04   2021-11-19  visjdn  ESCAN00108780    [XCP] Bootloader does not process XCP messages
 *  03.04.00   2022-03-16  vishor  FBL-4621         No changes
 *                                 ESCAN00107629    No changes
 *                                 ESCAN00110835    No changes
 *                                 ESCAN00110881    No changes
 *  03.05.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00112002    No changes
 *  03.05.01   2022-06-23  vishor  ESCAN00112105    No changes
 *                                 ESCAN00112155    No changes
 *  03.05.02   2022-08-29  visjns  ESCAN00112404    No changes
 *                                 ESCAN00112298    No changes
 *  03.05.03   2022-12-12  vismix  ESCAN00112835    No changes
 **********************************************************************************************************************/


#ifndef FBL_APNV_H
#define FBL_APNV_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_FrameNv_Daimler CQComponent : Implementation */
#define FBLKBAPI_FRAMENV_DAIMLER_VERSION             0x0304u
#define FBLKBAPI_FRAMENV_DAIMLER_RELEASE_VERSION     0x02u


/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
#endif /* FBL_ENABLE_PRESENCE_PATTERN */


/* Application software information */
#define kApplInfoSizeSwVersion                  0x03u
#define kApplInfoSizeSwPartNumber               0x0Au
#define kApplInfoSizeSwSupplierInformation      0x02u
#define kApplInfoSizeSwInfo                     (kApplInfoSizeSwVersion+    \
                                                 kApplInfoSizeSwPartNumber+ \
                                                 kApplInfoSizeSwSupplierInformation)
#define kApplSizeDDSPackageReleaseAppl          0x02u
#define kApplInfoSizeDowngradeProtVersion       0x03u
#define kApplInfoSizeVerificationKeyState       0x01u
#define kApplInfoSizeVerificationKey            0x20u
#define kApplInfoSizeSwCompatibility            0x02u
#define kApplInfoSizeHwCompatibilityCounter     0x01u

#define kApplInfoOffsetSwVersion                0x00u
#define kApplInfoOffsetSwPartNumber             (kApplInfoSizeSwVersion)
#define kApplInfoOffsetSwSupplierInformation    (kApplInfoOffsetSwPartNumber + kApplInfoSizeSwPartNumber)
#define kApplInfoOffsetDDSPackageRelField       (kApplInfoOffsetSwSupplierInformation + kApplInfoSizeSwSupplierInformation)

/* Downgrade Protection Version */
#define kApplInfoOffsetDowngradeProtVersion    (kApplInfoOffsetDDSPackageRelField + kApplSizeDDSPackageReleaseAppl)

/* Verification key information */
#define kApplInfoOffsetVerificationKeyState     (kApplInfoOffsetDowngradeProtVersion + kApplInfoSizeDowngradeProtVersion)
#define kApplInfoOffsetVerificationKey          (kApplInfoOffsetVerificationKeyState + kApplInfoSizeVerificationKeyState)

/* Application compatibility information */
#define kApplInfoOffsetSwCompatibility          (kApplInfoOffsetVerificationKey + kApplInfoSizeVerificationKey)
#define kApplInfoOffsetHwCompatibilityCounter   (kApplInfoOffsetSwCompatibility + kApplInfoSizeSwCompatibility)
#define kApplInfoOffsetHwCompatibilityField     (kApplInfoOffsetHwCompatibilityCounter + kApplInfoSizeHwCompatibilityCounter)

/* from upd_oem_ap.c */
#define kApplInfoSizeHwCompatibility            0x02u
#define kApplInfoNumberHwCompatibilityEntries   0x03u

#define applInfoHdrLength                       (kApplInfoSizeSwVersion + \
                                                kApplInfoSizeSwPartNumber + \
                                                kApplInfoSizeSwSupplierInformation + \
                                                kApplSizeDDSPackageReleaseAppl + \
                                                kApplInfoSizeDowngradeProtVersion + \
                                                kApplInfoSizeVerificationKeyState + \
                                                kApplInfoSizeVerificationKey + \
                                                kApplInfoSizeSwCompatibility + \
                                                kApplInfoSizeHwCompatibilityCounter + \
                                                (kApplInfoSizeHwCompatibility * kApplInfoNumberHwCompatibilityEntries))


/** Status information about verification key update in logical block */
#define kApplInfoVerificationKeyNone            0x00u
#define kApplInfoVerificationKeyPresent         0x01u

/* -- Flash access macros -- */
#define ApplFblReadPromSwVersion(descriptor, buffer) \
   FblReadProm((descriptor).blockStartAddress+kApplInfoOffsetSwVersion, (buffer), kApplInfoSizeSwVersion)
#define ApplFblReadPromSwPartNumber(descriptor, buffer) \
   FblReadProm((descriptor).blockStartAddress+kApplInfoOffsetSwPartNumber, (buffer), kApplInfoSizeSwPartNumber)
#define ApplFblReadPromSwSupplierInformation(descriptor, buffer) \
   FblReadProm((descriptor).blockStartAddress+kApplInfoOffsetSwSupplierInformation, (buffer), kApplInfoSizeSwSupplierInformation)

/* This index should be used if a NV-Wrapper access macro *
 * with an ignored index is generated (e.g. for structs)  */
# define kFblWrapNvDefaultIndex 0x00u

/* -- NV-memory access macros -- */

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/* Security access delay flag macros */
# define ApplFblGetSecAccessDelayFlag() \
   (ApplFblRWSecurityAccessDelayFlag(kEepReadData, 0) == kEepSecAccessDelayActive)
# define ApplFblSetSecAccessDelayFlag() \
   ApplFblRWSecurityAccessDelayFlag(kEepWriteData, kEepSecAccessDelayActive)
# define ApplFblClrSecAccessDelayFlag() \
   ApplFblRWSecurityAccessDelayFlag(kEepWriteData, kEepSecAccessDelayInactive)
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

/* Reset response flag access macros */
#define ApplFblReadResetResponseFlag(buffer)             ApplFblNvReadResetResponseFlag(buffer)
#define ApplFblWriteResetResponseFlag(buffer)            ApplFblNvWriteResetResponseFlag(buffer)

/* EEPROM constants */
#define kEepValidateBlock                 0x01u
#define kEepInvalidateBlock               0x02u

#define kEepSecAccessDelayActive          0xC3u
#define kEepSecAccessDelayInactive        0x5Au

/* Magic number for valid application */
#define kFblApplicationValid              0x85u
#define kFblApplicationInvalid            0xFFu

/* Status of verification key in NvM */
#define kFblVerificationKeyPresent        kApplInfoVerificationKeyPresent

/* Secure boot */
#if defined( FBLBM_ENABLE_SECURE_BOOT )
# if defined( FBLSB_ENABLE_GENERATE_CMAC )
#  define ApplFblUpdateBlockMac(blockDesc, segmentList)  FblSb_UpdateBlockMac((blockDesc), (segmentList))
# endif
#endif
#if !defined( ApplFblUpdateBlockMac )
# define ApplFblUpdateBlockMac(block, segList)     (kFblOk)
#endif

#if defined( FBL_ENABLE_PRESENCE_PATTERN )
/* PRQA S 3453 6 */ /* MD_MSR_FctLikeMacro */
# define ApplFblChkModulePresence(bd)        FblNvPatternGet((bd), kFblNvPatternId_BlockValidity)
# define ApplFblSetModulePresence(bd)        FblNvPatternSet((bd), kFblNvPatternId_BlockValidity)
# define ApplFblClrModulePresence(bd)        FblNvPatternClr((bd), kFblNvPatternId_BlockValidity)
# define ApplFblChkApplPresence(bd)          FblNvPatternGet((bd), kFblNvPatternId_ApplValidity)
# define ApplFblSetApplPresence(bd)          FblNvPatternSet((bd), kFblNvPatternId_ApplValidity)
# define ApplFblClrApplPresence(bd)          FblNvPatternClr((bd), kFblNvPatternId_ApplValidity)
# if defined( FBL_ENABLE_OTA )
/* Activation Pending for activating partitions */
#  define ApplFblChkActivationPending(bd)    FblNvPatternGet((bd), kFblNvPatternId_ActivationPending)
#  define ApplFblSetActivationPending(bd)    FblNvPatternSet((bd), kFblNvPatternId_ActivationPending)
#  define ApplFblClrActivationPending(bd)    FblNvPatternClr((bd), kFblNvPatternId_ActivationPending)
/* Macros to get/set NvProperty values - only needed for OTA revision handling */
#  define ApplFblGetPartitionRev(bd, buffer) FblNvPatternGetProperty((bd), kFblNvProperty_PartitionRev, FBL_NVPATTERN_REVISION_SIZE, (buffer))
#  define ApplFblSetPartitionRev(bd, buffer) FblNvPatternSetProperty((bd), (buffer), kFblNvProperty_PartitionRev)
#  define ApplFblGetModuleRev(bd, buffer)    FblNvPatternGetProperty((bd), kFblNvProperty_ModuleRev, FBL_NVPATTERN_REVISION_SIZE, (buffer))
#  define ApplFblSetModuleRev(bd, buffer)    FblNvPatternSetProperty((bd), (buffer), kFblNvProperty_ModuleRev)
# endif /* FBL_ENABLE_OTA */
#endif /* FBL_ENABLE_PRESENCE_PATTERN */

#if defined( FBL_ENABLE_OTA ) && defined( VOTAM_USECASE_EXTENDED )
/* In case of OTA with extended use-case calculate OFR light CMAC if not explicitly disabled */
# if !defined( FBL_DISABLE_OFR_LIGHT_VERIFY_CMAC )
#  define FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC
# endif /* !FBL_DISABLE_OFR_LIGHT_VERIFY_CMAC */
#endif /* FBL_ENABLE_OTA && VOTAM_USECASE_EXTENDED */

/***********************************************************************************************************************
*  TYPEDEFS
**********************************************************************************************************************/

/* Position type definitions for different WrapNv-APIs */
#if defined( WRAPNV_USECASE_FEE ) || \
    defined( WRAPNV_USECASE_EA )  || \
    defined( WRAPNV_USECASE_NVM )
typedef uint16 WRAPNV_PositionType;
#else
typedef IO_PositionType WRAPNV_PositionType;
#endif

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

#if defined( FBL_CW_ENABLE_MULTIPLE_CONNECTIONS )
tFblResult ApplFblWriteDcmDslRxTesterSourceAddr(vuint8* buffer);
tFblResult ApplFblReadDcmDslRxTesterSourceAddr(vuint8* buffer);
#endif /* FBL_CW_ENABLE_MULTIPLE_CONNECTIONS */

tFblProgStatus ApplFblExtProgRequest( void );
tApplStatus ApplFblIsValidApp( void );
tFblResult ApplFblIsValidBlock( vuint8 blockNr );
tFblResult ApplFblValidateBlock( tBlockDescriptor blockDescriptor );
tFblResult ApplFblInvalidateBlock( tBlockDescriptor blockDescriptor );

tFblResult ApplFblStoreFingerprint( vuint8 * buffer );
void ApplFblErrorNotification( tFblErrorType errorType, tFblErrorCode errorCode );
tFblResult ApplFblAdjustLbtBlockData(tBlockDescriptor * blockDescriptor);
vuint16 ApplFblRWProgCounter( vuint8 mode, tBlockDescriptor blockDescriptor );
tFblResult ApplFblIncProgAttempts( tBlockDescriptor blockDescriptor );
tFblResult ApplFblGetProgAttempts( tBlockDescriptor blockDescriptor, V_MEMRAM1 vuint16 V_MEMRAM2 V_MEMRAM3 * progAttempts );
tFblLbtMaxProgAttempts ApplFblGetPromMaxProgAttempts(tFblLbtBlockNr blockNr);
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
vuint8 ApplFblRWSecurityAccessDelayFlag( vuint8 mode, vuint8 value );
#endif
tFblAddress ApplFblGetModuleHeaderAddress( vuint8 blockNr );
extern vuint8 ReadApplInfoHeader(vuint8 blockNr, vuint8 offset, vuint8* targetBuf, vuint8 size);

vuint8 ApplFblCheckHwSwCompatibility(vuint8 blockIdx);
vuint8 ApplFblCheckSwSwCompatibility(void);
tFblResult ApplFblDowngradeProtectionInit(void);
tFblResult ApplFblDowngradeProtectionCheck(void);
vuint8 ApplFblCheckProgDependencies( void );
vuint8 ApplFblPreChkProgDependencies( vuint8 * pbDiagData, tTpDataType diagReqDataLen );
tFblResult ApplFblValidateApp( void );
tFblResult ApplFblInvalidateApp(void);
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
tFlashStatus ApplFblGetBlockErased( tBlockDescriptor blockDescriptor );
#endif /* FBL_ENABLE_FLASH_ERASED_DETECTION */

tFblResult ApplFblWriteSegmentList( vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList );
tFblResult ApplFblReadSegmentList( vuint8 blockNr, V_MEMRAM1 FL_SegmentListType V_MEMRAM2 V_MEMRAM3 * segmentList );
tFblResult ApplFblReadFpStatusInfo(tBlockDescriptor descriptor, vuint8 * buffer);
tFblResult ApplFblWriteFpStatusInfo(tBlockDescriptor descriptor, vuint8 * buffer);
tFblResult ApplFblCRCWrittenValueWrite(tBlockDescriptor descriptor, vuint8 * buffer);
tFblResult ApplFblCRCTotalValueWrite(tBlockDescriptor descriptor, vuint8 * buffer);
SecM_LengthType ApplFblReadVerificationKey( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * key);
tFblResult ApplFblWriteVerificationKey( vuint8 blockNr );
#if defined( FBL_ENABLE_OTA )
Std_ReturnType ApplFblVerifyModule(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);
# if defined( FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC )
#  if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
tFblResult ApplFblOutputCalculateOfrLightCmac(tFblLbtBlockNr blockNr, const V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
#  else /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
SecM_StatusType ApplFblPipelinedCalculateOfrLightCmac(const V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam);
tFblResult ApplFblPipelinedFinalizeOfrLightCmac(tFblLbtBlockNr blockNr);
#  endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
# endif /* FBL_ENABLE_OFR_LIGHT_VERIFY_CMAC */
#endif /* FBL_ENABLE_OTA */
vuint32 ApplFblGetNvModuleId(tFblLbtBlockNr blockNr);
void ApplFblGetVin( vuint8 ** DataPtr, vuint16 * LenBytePtr);
void ApplFblGetDiagPowerMode (vuint8 * DiagPowerModePtr);

#endif   /* FBL_APNV_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_APNV.H
 **********************************************************************************************************************/
