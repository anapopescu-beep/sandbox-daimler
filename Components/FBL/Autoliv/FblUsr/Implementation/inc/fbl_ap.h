/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Diagnostic services supported in boot mode
 *                 Declaration of functions, variables, and constants
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
 *  01.00.00   2017-08-03  viscb                    Initial implementation based on FblKbApi_Frame_DC
 *  01.01.00   2017-10-26  viscb   ESCAN00097220    Prototype for ApplFblBusSleep
 *  01.02.00   2017-12-21  visach  ESCAN00097825    Removed TpTargetAddress callbacks
 *  01.03.00   2018-07-31  viscb   ESCAN00100246    Added ComM callout functions
 *  01.04.00   2018-11-29  viscb   ESCAN00101419    Callout function for memory condition check
 *                                 ESCAN00101485    Added callout function ApplFblStateTask()
 *  02.00.00   2020-10-14  viscb   FBL-2177         Development version, DRECU2020-01 adaptions
 *  02.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Added memdriver callouts
 *  02.01.01   2021-02-02  viscb   ESCAN00108448    QM release
 *  02.02.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
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


#ifndef FBL_AP_H
#define FBL_AP_H

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi CQComponent : Implementation */
#define FBLKBAPI_VERSION                           0x0211u
#define FBLKBAPI_RELEASE_VERSION                   0x00u

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_Daimler CQComponent : Implementation */
#define FBLKBAPI_DAIMLER_VERSION                     0x0305u
#define FBLKBAPI_DAIMLER_RELEASE_VERSION             0x03u

/* ##V_CFG_MANAGEMENT ##CQProject : FblKbApi_Frame_Daimler CQComponent : Implementation */
#define FBLKBAPI_FRAME_DAIMLER_VERSION               0x0202u
#define FBLKBAPI_FRAME_DAIMLER_RELEASE_VERSION       0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if ( DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
# define FBL_CW_CFG_PTR activeCwConfiguration
#endif

#if defined( FBL_ENABLE_DATA_PROCESSING )
# if !defined( GetOemProcessingModeSupported )
/* Accept compression and encryption */
#  define GetOemProcessingModeSupported(m) (GetOemCompressionMode((m)) || GetOemEncryptionMode((m)))
# endif /* GetOemProcessingModeSupported */

# if !defined( GetOemCompressionMode )
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
/* Accept default compression routine */
#   define GetOemCompressionMode(m)   (FblDiagGetCompressionMode(m) >= kDiagSubDefaultCompression)
#  else
/* No compression routine supported */
#   define GetOemCompressionMode(m)   (0 != 0)
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
# endif /* GetOemCompressionMode */

# if !defined( GetOemEncryptionMode )
#  if defined( FBL_ENABLE_ENCRYPTION_MODE )
/* Accept default encryption routine*/
#   define GetOemEncryptionMode(m)     ((FblDiagGetEncryptionMode(m) == kDiagSubDevelopmentEncryption) || \
                                       (FblDiagGetEncryptionMode(m) == kDiagSubProductionEncryption))
#  else
/* No encryption routine supported */
#   define GetOemEncryptionMode(m)    (0 != 0)
#  endif /* FBL_ENABLE_ENCRYPTION_MODE */
# endif /* GetOemEncryptionMode */
#endif /* FBL_ENABLE_DATA_PROCESSING */
# define FRTRCV_CHANNEL_EN_0           ((vuint8)  0u)
# define FRTRCV_CHANNEL_STBN_0         ((vuint8)  1u)
# define FRTRCV_CHANNEL_ERRN_0         ((vuint8)  2u)

# define FRTRCV_TJA1080_PULSEWIDTHUS   ((vuint8)  2u)
# define FRTRCV_TJA1080_DELAYWIDTHUS   ((vuint8) 80u)
# define FRTRCV_TJA1080_COUNTER        ((vuint8) 15u)
# define FRTRCV_STATUS_INVERT_MASK     ((vuint16) 0xFFFFu)

typedef struct
{
  vuint8   TrcvPinEN;
  vuint8   TrcvPinSTBN;
  vuint8   TrcvPinERRN;
} FrTrcvChannelType;

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

void ApplFblInit( void );
void ApplFblStartup( vuint8 initposition );
tFblResult ApplFblCheckProgConditions( void );
void ApplTrcvrNormalMode( void );
void ApplTrcvrSleepMode( void );
void ApplFblSetVfp( void );
void ApplFblResetVfp( void );
void ApplFblReset( void );

vuint8 ApplFblSecurityInit( void );
#define FBLAP_RAMCODE_START_SEC_CODE_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
vuint8 ApplFblSecuritySeedInit( void );
#define FBLAP_RAMCODE_STOP_SEC_CODE_EXPORT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
vuint8 ApplFblSecuritySeed( void );
vuint8 ApplFblSecurityKey( void );

#if defined( FBL_ENABLE_DATA_PROCESSING )
tFblResult ApplFblInitDataProcessing( tProcParam * procParam );
tFblResult ApplFblDataProcessing( tProcParam * procParam );
tFblResult ApplFblDeinitDataProcessing( tProcParam * procParam );
#endif
#if defined( FBL_ENABLE_APPL_TASK ) || \
    defined( FBL_ENABLE_APPL_TIMER_TASK )
void ApplFblTask( void );
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_TIMER_TASK */
#if defined( FBL_ENABLE_APPL_TASK ) ||\
    defined( FBL_ENABLE_APPL_STATE_TASK )
void ApplFblStateTask( void );
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_STATE_TASK */

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
FUNC_P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) ApplFblPlatformToConfigPtr( vuint8 platform );
#endif

vuint8 ApplFblCwWakeUp( void );
void ApplFblCwBusSleepMode( void );
/* Remapping of the BRS SetWakeupEvent call */
#define ECUM_STUB_SETWAKEUPEVENT_CALLOUT
#define BrsTestsuite_EcuM_SetWakeupEvent_Callout ApplFblSetWakeupEvent
extern void ApplFblSetWakeupEvent( vuint32 WakeupSource_t );
void ApplFblTrcvDelay( vuint8 delay );
void ApplFblTrcvPhyTrcvInit( const vuint8 FrTrcv_TrcvIdx );
vuint8 ApplFblTrcvPhySetMode( const vuint8 FrTrcv_TrcvIdx, const vuint8 FrTrcv_TrcvMode );
vuint8 ApplFblTrcvPhyGetMode( const vuint8 FrTrcv_TrcvIdx, vuint8 *FrTrcv_TrcvModePtr );
vuint8 ApplFblTrcvPhyReadStatusWord( const vuint8 FrTrcv_TrcvIdx, vuint16 *TrcvStatusWord );
void ApplFblCanBusOff( void );

#if defined( FBL_ENABLE_SLEEPMODE )
void ApplFblBusSleep( void );
#endif /* FBL_ENABLE_SLEEPMODE */

# if ( FBLCW_MODULE_COMM == STD_ON )
#  define FBLAP_RAMCODE_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, FBLCW_CODE) ApplFbl_ComM_NoComModeEntered(NetworkHandleType channel);
FUNC(void, FBLCW_CODE) ApplFbl_ComM_SilentComModeEntered(NetworkHandleType channel);
FUNC(void, FBLCW_CODE) ApplFbl_ComM_FullComModeEntered(NetworkHandleType channel);
#  define FBLAP_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif

# if defined( FBL_ENABLE_MULTIPLE_NODES )
#if defined( FBL_ENABLE_MULTIPLE_NODES ) || \
    defined( FBL_ENABLE_CAN_CONFIGURATION) || \
    defined( FBL_CW_ENABLE_MULTIPLE_NODES )
void ApplFblCanParamInit( void );
#endif
# endif

/* LibMem callout functions */

tFblResult ApplFblMemPreErase( void );
tFblResult ApplFblMemPreWrite( void );
tFblMemStatus ApplFblMemConditionCheck( void );

#if defined( FBL_MIO_ENABLE_HOOKS )
void ApplFblPreMemDriver( vuint8 device, vuint8 function );
#endif /* FBL_MIO_ENABLE_HOOKS */
#if defined( FBL_MIO_ENABLE_HOOKS )
void ApplFblPostMemDriver( vuint8 device, vuint8 function );
#endif /* FBL_MIO_ENABLE_HOOKS */

#if defined( FBL_ENABLE_STATUS_BACKUP )
tFblResult ApplFblSaveStatus( const V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 * source, vuint32 length );
tFblResult ApplFblRestoreStatus( const V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 * dest, vuint32 length );
#endif   /* FBL_ENABLE_STATUS_BACKUP */

#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
tFblResult ApplFblInitStreamOutput( V_MEMRAM1 tFblMemStreamProcessing V_MEMRAM2 V_MEMRAM3 * streamParam );
tFblResult ApplFblStreamOutput( V_MEMRAM1 tFblMemStreamProcessing V_MEMRAM2 V_MEMRAM3 * streamParam );
tFblResult ApplFblFinalizeStreamOutput( V_MEMRAM1 tFblMemStreamProcessing V_MEMRAM2 V_MEMRAM3 * streamParam );
tFblResult ApplFblDeinitStreamOutput( V_MEMRAM1 tFblMemStreamProcessing V_MEMRAM2 V_MEMRAM3 * streamParam );
#endif /* FBL_MEM_ENABLE_STREAM_OUTPUT */

/* Additional functions depending on hardware platform requirements */

#if defined( FBL_ENABLE_ASSERTION )
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) );
#endif
/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_COMMON_DATA )
/* Process data shared between application and Bootloader */
V_MEMROM0 extern V_MEMROM1 tFblCommonData fblCommonData;
extern const uint8 HSMPartNo[];
#endif /* FBL_ENABLE_COMMON_DATA */

#if ( DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
/** Pointer to select active ECU of a multiple identity configuration */
extern P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) activeCwConfiguration;

# if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
V_MEMROM0 extern V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfConfigInitPtrs;
# endif /* FBL_ENABLE_MULTIPLE_PLATFORMS */

#endif /* DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON */


#endif /* FBL_AP_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_AP.H
 **********************************************************************************************************************/
