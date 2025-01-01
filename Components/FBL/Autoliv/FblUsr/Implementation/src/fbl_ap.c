/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent routines
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
 *  01.01.00   2017-10-26  viscb   ESCAN00097220    No changes
 *  01.02.00   2017-12-21  visach  ESCAN00097825    Removed TpTargetAddress callbacks
 *  01.03.00   2018-07-31  viscb   ESCAN00100246    Added ComM callout functions
 *  01.04.00   2018-11-29  viscb   ESCAN00101419    Callout function for memory condition check
 *                                 ESCAN00101485    Added callout function ApplFblStateTask()
 *  01.05.00   2019-01-17  viscb   ESCAN00101803    Support multiple platforms with MSR com stack
 *  02.00.00   2020-10-14  viscb   FBL-2177         DRECU2020-01 adaptions
 *  02.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Added memdriver callouts
 *  02.01.01   2021-02-02  viscb   ESCAN00108448    QM release
 *  02.02.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY (kbFbl_apAPI.c)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2018-09-14  visrie  ESCAN00100739    Added support for FblLib_NvPattern
 *                                                  Removed unused code
 *                         viscb   ESCAN00101418    Callout function for memory condition check
 *                         visach  ESCAN00101686    Added interface definition for vendor verification routine
 *  02.01.00   2019-02-26  visrie  ESCAN00102257    Added additional callout functions
 *  02.01.01   2019-09-23  visrie  FBL-452          Added support for FrArTp
 *  02.02.00   2019-12-05  visrie  FBL-458          Added FblMio callout functions
 *  02.03.00   2020-05-07  visrie  FBL-1414         Added callout functions for One-Step-Updater
 *  02.03.01   2020-06-02  visjdn  ESCAN00106533    Update to latest MISRA version
 *  02.03.02   2020-09-14  visrcn  FBL-2257         Add MISRA justifications
 *  02.03.03   2020-11-23  visrcn  FBL-2564         Add MISRA justifications
 *  02.03.04   2021-03-19  visjdn  FBL-2916         Add MISRA justifications
 *  02.04.00   2021-05-26  vishor  FBL-3165         MISRA corrections and justifications
 *  02.05.00   2021-06-15  visrie  FBL-3591         Provide default implementation for ApplFbl_DetEntryHandler
 *                                                  Add MISRA justifications
 *  02.06.00   2021-07-15  visjdn  FBL-3381         Re-mapping of EcuM_SetWakeupEvent
 *  02.07.00   2021-07-22  visrie  FBL-3822         Update to QAC9 Helix-2021
 *  02.08.00   2021-09-14  visjdn  FBL-2859         Add MISRA justifications
 *  02.09.00   2021-10-12  vistmo  FBL-3901         Add authentication callbacks
 *  02.10.00   2021-10-15  visrie  FBL-3945         Remove content of ApplFblStartApplication
 *  02.10.01   2021-11-12  vishor  ESCAN00110133    Compiler error: Unknown symbols
 *                                                   ApplFblSave/RestoreStatusSector/Dynamic
 *  02.10.02   2022-06-27  visrie  FBL-4694         Add MISRA justifications
 *  02.10.03   2022-10-20  visjns  FBL-5452         Add MISRA justifications
 *  02.11.00   2022-12-22  vistbe  FBL-5691         Add support for LZSS compression
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2019-03-12  visrie  ESCAN00102454    Added support for LibNvPattern, LibLbtAccess and SecureBoot
 *  02.00.01   2019-04-29  viscb   ESCAN00102998    Clear internal state flag for resume after erase
 *  03.00.00   2020-10-06  viscb   FBL-2177         DRECU2020-01 adaptions, data processing
 *  03.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Simplified updater integration
 *                                                    - Added support for OTA
 *                                                    - Added support for downgrade protection
 *                                                    - Migration to MISRA 2012
 *  03.01.01   2021-02-02  viscb   ESCAN00108447    QM release
 *  03.02.00   2021-04-21  viscb   ESCAN00108550    ReadDataByIdentifier returns incorrect data for requested meta data
 *                                 ESCAN00108549    Fingerprint status is not updated correctly
 *                                 ESCAN00108532    Signature verification of downloaded block fails
 *                                 ESCAN00108591    Application is not started after OFR swap
 *  03.03.00   2021-07-12  vishor  FBL-3567         Add support for Csm-based suspend/resume
 *  03.03.01   2021-08-24  vishor  ESCAN00109880    Resume information from OFR download is not invalidated in
 *                                                  case FBL download is started
 *  03.03.02   2021-08-27  vishor  ESCAN00109972    Compiler error: Incompatible type for
 *                                                  ApplFblNvWriteSegmentCount/ApplFblNvReadSegmentCount
 *  03.03.03   2021-10-19  vistmo  ESCAN00110504    Compiler error: 'SecM_CancelAllJobs' undefined
 *  03.03.04   2021-11-19  visjdn  ESCAN00108780    [XCP] Bootloader does not process XCP messages
 *  03.04.00   2022-03-16  vishor  FBL-4621         MB MMA Rework
 *                                 ESCAN00107629    Compressed and encrypted download stops with NRC 0x72 in service
 *                                                   Request Transfer Exit
 *                                 ESCAN00110835    Compiler error: kEepApplInconsistent not defined
 *                                 ESCAN00110881    Compiler error: identifier "consumedLen" and "producedLen"
 *                                                   are undefined
 *  03.05.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00112002    DID 0xEF02 - Standard Bootloader Software Information implemented
 *                                                   with wrong number of bytes
 *  03.05.01   2022-06-23  vishor  ESCAN00112105    AES IV is not extracted from downloaded data
 *                                 ESCAN00112155    Decryption is not correctly finalized during download
 *  03.05.02   2022-08-29  visjns  ESCAN00112404    Missing implementation of DID 0xEF05: Minimum Software Version
 *                                 ESCAN00112298    Programming attempts check fails with OTA update
 *  03.05.03   2022-12-12  vismix  ESCAN00112835    Access to programming attempt counter fails
 **********************************************************************************************************************/


#define FBL_AP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#if defined( FBL_APPL_ENABLE_BUSTYPE_FR)
# include "FrTrcv.h"
#endif
#if defined( FBL_ENABLE_COMPRESSION_MODE )
# if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR )
#  include "cmpr_inc.h"
# endif
# if defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
#  include "cmpr_lzma.h"
# endif
#endif

#include "BrsMain.h"
#include "BrsHw.h"
# include "Det.h"
# if (DET_ENABLED == STD_ON)
#  if defined( FBL_APPL_ENABLE_BUSTYPE_CAN )
#   include "Can.h"
#   include "CanIf.h"
#   include "CanTp.h"
#  endif
#  if defined( FBL_APPL_ENABLE_BUSTYPE_FR )
#    include "FrTp.h"
#    include "FrTp_Common.h"
#  endif
#  if defined( FBL_APPL_ENABLE_DOIP )
#   include "DoIP.h"
#  endif
# endif
#if defined( FBL_BM_ENABLE_BOOTMANAGER )
# include "fbl_bmtypes.h"
#endif

#include "Mcu.h"
#include "Port.h"

#include "Csm.h"
#include "Crypto_30_vHsm.h"
#include "Crypto_30_vHsm_Custom.h"

#if ( FBLKBAPI_DAIMLER_VERSION != 0x0305u ) || \
    ( FBLKBAPI_DAIMLER_RELEASE_VERSION != 0x03u )
#error "Error in FBL_APxx.C: Source and header file are inconsistent!"
#endif

#if ( FBLKBAPI_DAIMLER_VERSION != _FBLKBAPI_OEM_VERSION ) || \
    (FBLKBAPI_DAIMLER_RELEASE_VERSION != _FBLKBAPI_OEM_RELEASE_VERSION)
#error "Error in FBL_APxx.C: Source and V_VER.H are inconsistent!"
#endif

#if ( FBLKBAPI_VERSION != 0x0211u ) || \
    ( FBLKBAPI_RELEASE_VERSION != 0x00u )
# error "Error in FBL_APxx.C: Source and header file are inconsistent!"
#endif
#if ( FBLKBAPI_VERSION != _FBLKBAPI_VERSION ) || \
    ( FBLKBAPI_RELEASE_VERSION != _FBLKBAPI_RELEASE_VERSION )
# error "Error in FBL_APxx.C: Source and V_VER.H are inconsistent!"
#endif

#if ( FBLKBAPI_FRAME_DAIMLER_VERSION != 0x0202u ) || \
    ( FBLKBAPI_FRAME_DAIMLER_RELEASE_VERSION != 0x00u )
# error "Error in FBL_AP.C: Source and header file are inconsistent!"
#endif

#if ( FBLKBAPI_FRAME_DAIMLER_VERSION != _FBLKBAPI_FRAME_OEM_VERSION ) || \
    ( FBLKBAPI_FRAME_DAIMLER_RELEASE_VERSION != _FBLKBAPI_FRAME_OEM_RELEASE_VERSION )
# error "Error in FBL_AP.C: Source and header file are inconsistent!"
#endif

#define MODULE_P20 /*lint --e(923)*/ ((*(Ifx_P *)0xF003B400u))
#include "IfxPort_regdef.h"

#include "vstdlib.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

void __ldmstC(volatile void *addr, uint32 mask, uint32 data)
{
    *(volatile uint32 *)addr = (*(volatile uint32 *)addr & ~mask) | (mask & data);
}

#define __ldmst(a,b,c) __ldmstC(a,b,c)

void setPin(boolean val)
{
  if (val == TRUE)
  {
    MODULE_P20.OMR.U = 1U << 14;
  }
  else
  {
    MODULE_P20.OMR.U = ((1U << 16) | (0 << 0)) << 14;
  }
}

void IfxPort_setPinMode(Ifx_P *port, uint8 pinIndex, unsigned int mode)
{
  volatile Ifx_P_IOCR0 *iocr = &(port->IOCR0);
  uint8 iocrIndex = (pinIndex / 4);
  uint8 shift = (pinIndex & 0x3U) * 8;
  __ldmst(&iocr[iocrIndex].U, (0xFFUL << shift), (mode << shift));
}

void IfxPort_setPinModeOutput(Ifx_P *port, uint8 pinIndex, unsigned int mode, unsigned int index)
{
    IfxPort_setPinMode(port, pinIndex, (index | mode));
}
/* Service request register, taken from IfxSrc_regdef.h */
typedef struct _Ifx_SRC_SRCR_Bits
{
  unsigned int SRPN : 8;        /**< \brief [7:0] Service Request Priority Number (rw) */
  unsigned int reserved_8 : 2;  /**< \brief \internal Reserved */
  unsigned int SRE : 1;         /**< \brief [10:10] Service Request Enable (rw) */
  unsigned int TOS : 3;         /**< \brief [13:11] Type of Service Control (rw) */
  unsigned int reserved_14 : 2; /**< \brief \internal Reserved */
  unsigned int ECC : 5;         /**< \brief [20:16] ECC (rwh) */
  unsigned int reserved_21 : 3; /**< \brief \internal Reserved */
  unsigned int SRR : 1;         /**< \brief [24:24] Service Request Flag (rh) */
  unsigned int CLRR : 1;        /**< \brief [25:25] Request Clear Bit (w) */
  unsigned int SETR : 1;        /**< \brief [26:26] Request Set Bit (w) */
  unsigned int IOV : 1;         /**< \brief [27:27] Interrupt Trigger Overflow Bit (rh) */
  unsigned int IOVCLR : 1;      /**< \brief [28:28] Interrupt Trigger Overflow Clear Bit (w) */
  unsigned int SWS : 1;         /**< \brief [29:29] SW Sticky Bit (rh) */
  unsigned int SWSCLR : 1;      /**< \brief [30:30] SW Sticky Clear Bit (w) */
  unsigned int reserved_31 : 1; /**< \brief \internal Reserved */
} Ifx_SRC_SRCR_Bits;

/* Service request register, taken from IfxSrc_regdef.h */
typedef union {
  unsigned int U;      /**< \brief Unsigned access */
  signed int I;        /**< \brief Signed access */
  Ifx_SRC_SRCR_Bits B; /**< \brief Bitfield access */
} Ifx_SRC_SRCR;

void Platform_TogglePin(boolean state)
{
  setPin(state);
}


#if defined( FBL_ENABLE_DATA_PROCESSING )
/* Configuration check */
# if defined( FBL_ENABLE_ENCRYPTION_MODE )
#  if defined( SEC_ENABLE_DECRYPTION )
#  else
#   error "FBL_ENABLE_ENCRYPTION_MODE needs SEC_ENABLE_DECRYPTION to be configured."
#  endif /* SEC_ENABLE_DECRYPTION */
# endif /* FBL_ENABLE_ENCRYPTION_MODE */
#endif /* FBL_ENABLE_DATA_PROCESSING */

#if defined( FBL_ENABLE_DATA_PROCESSING )
# if defined( FBL_ENABLE_ENCRYPTION_MODE )
/* Handling of AES initialization vector
* Possible values:
* SEC_DECRYPTION_MODE_AES_128_PKCS_CBC_IV - Explicit IV included in data/ implicit constant IV
* SEC_DECRYPTION_MODE_AES_128_PKCS_CBC - Implicit IV of 0 used */
#  define SEC_MODE_AES  SEC_DECRYPTION_MODE_AES_128_PKCS_CBC

/* Origin of IV: Explicitly included in data or configured in implicit constant (decAesIv) */
#  define SEC_MODE_AES_IV_DATA         0u
#  define SEC_MODE_AES_IV_CONSTANT     1u
#  define SEC_MODE_AES_IV              SEC_MODE_AES_IV_DATA
# endif /* FBL_ENABLE_ENCRYPTION_MODE */
#endif /* FBL_ENABLE_DATA_PROCESSING */


#if defined( FBL_BM_ENABLE_BOOTMANAGER )
# ifndef kFblPresencePatternSize
#  define kFblPresencePatternSize     4u
# endif
# ifndef kFblPresencePattern
#  define kFblPresencePattern        {0x73u, 0x6Au, 0x29u, 0x3Eu}
# endif
#endif   /* FBL_BM_ENABLE_BOOTMANAGER  */

#define RBTM_FR_ID_NVM  0x99

/*vHsmUpdater relevant data*/

/* START: Data types taken from vHsmUpd_MemAb */
# define VHSMUPD_HEADER_TAG_SIZE            (16u)
# define VHSMUPD_SIGNATURE_SIZE             (16u)  /*!< Size of the cryptographic signature */

typedef vuint32 vHsmUpd_FirmwareVersionType; /*!< Type used for the firmware of the vHsm */
typedef vuint32 vHsmUpd_AddressType;
typedef vuint32 vHsmUpd_LengthType;

typedef struct
{
  vuint8 HeaderTag[VHSMUPD_HEADER_TAG_SIZE];                 /*!< Update header tag information */
  vuint8 VersionInfo[sizeof(vHsmUpd_FirmwareVersionType)];  /*!< The version info within the update header */
  vuint8 UpdateImageAddress[sizeof(vHsmUpd_AddressType)];   /*!< The address to the image in the update header */
  vuint8 UpdateImageLength[sizeof(vHsmUpd_LengthType)];     /*!< The length of the image in the update header */
  vuint8 Signature[VHSMUPD_SIGNATURE_SIZE];                  /*!< The MAC value of the update image */
} vHsmUpd_UpdateHeaderType; /*!< Type definition of the update header */
/* END: Data types taken from vHsmUpd_MemAb */

typedef struct {
uint8   au8FLHardwarePartnumber[10];
uint8   au8FRHardwarePartnumber[10];
}Hardware_Partnumber_Type; 

/* Needed to read the bytes correctly */
#if defined(FBL_CPUTYPE_BITORDER_LSB2MSB)
#  define CHECK_BITORDER(x) x=(((x>>24)&0xFF)|((x<<24)&0xFF000000)|((x>>8)&0xFF00)|((x<<8)&0xFF0000))
#else
#  define CHECK_BITORDER(x)
#endif


#define HT2HSMS (* ( (volatile vuint32 *)(Crypto_30_vHsm_GetHost2HsmAddressOfvHsmOfPCConfig() ) ) )
#define HSM2HTS (* ( (volatile vuint32 *)(Crypto_30_vHsm_GetHsm2HostAddressOfvHsmOfPCConfig() ) ) )
 
#define VHSMUPD_IPC_WAIT_MASK                       0x80000000uL
#define VHSMUPD_IPC_Initialized                     0x00000001uL

/* These states are available by the HSM2HTS register */
#define VHSMUPD_HSM2HOST_HOST_READY                 (1uL<<0uL)
#define VHSMUPD_HSM2HOST_HOST_AVAILABLE             (1uL<<1uL)
#define VHSMUPD_HSM2HOST_HOST_UPD_RUNNING           (1uL<<15uL)
#define VHSMUPD_HSM2HOST_HOST_SYNCH                 (1uL<<5uL)

/* These status are available only when the Ipc memeory is configured! */
#define VHSMUPD_UPDATE_NOT_STARTED                  0x00000001uL
#define VHSMUPD_UPDATE_IN_PROGRESS                  0x00000002uL
#define VHSMUPD_UPDATE_COMPLETED                    0x00000003uL

/* vHsmUpd timout to prevent ECU to get stuck if something goes wrong while updating the vHsm Firmware! */
#define VHSMUPD_UPDATE_TIMEOUT_MS                   15000u

/* Definition from the vHsm SIP */
#define CRYPTO_KE_CUSTOM_VHSM_FIRMWARE_UPDATE_START_UPDATER         (3038u)

#define BM_HEADER_SIZE 0x100u

#define HDR_MAGIC_PATTERN_SIZE 16
#define BLOCK_OFFSET BM_HEADER_SIZE
#define BYTES_TO_PROCESS_MAX 65536

#if defined (FLASH_BURST_SIZE_PFLASH)
#  define BYTES_TO_PROCESS FLASH_BURST_SIZE_PFLASH
#else
#  define BYTES_TO_PROCESS FLASH_SEGMENT_SIZE_PFLASH
#endif

#define SIGNATURE_SIZE 64u

/* Address information of where the vHsm firmware is located */

/* Address of the AURIX TC2xx vHsm sectors  */
#define HSM_FW_S16_ADDR 0x80060000ul

/* Size of the AURIX TC2xx vHsm sectors  */
#define HSM_FW_S16_S17_SIZE 0x20000ul

/* This is because the vHsmUpd expects 3 empty pages for PP and version  */
#define HSM_FW_PP_SIZE (3u* FLASH_SEGMENT_SIZE_PFLASH)

/* Generic address of the logical block */
#define HSM_FW_BASE_ADDR HSM_FW_S16_ADDR

/* Generic size of the dual sector logical block */
#define HSM_FW_BASE_SIZE HSM_FW_S16_S17_SIZE

/* It is assumed that the metadata space is a multiple of the page size */
#define METADATA_SECTORS 8u

/* Size of the segment at the end of the logical block where the FBL wirtes metadata like PP, MASK, Application validity, Secure Boot CMACs, etc. */
#define FBL_METADATA_SIZE (METADATA_SECTORS*FLASH_SEGMENT_SIZE_PFLASH)

/* number of sectors used for PP and MASK */
#define VHSMUPD_UPDATE_HEADER_PAGES 2u

/* Used for padding the page where the Update Header is allocated */
#define VHSMUPD_UPDATE_HEADER_PADDING_VALUE FBL_FLASH_DELETED

/*Make sure that address matches the one defined on Application side, where FBL version is written*/
#define FBL_APPLICATION_SW_VERSION_LOCATION 0xA00FFF00

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/* vHsmUpd timout to prevent ECU to get stuck if something goes wrong while updating the vHsm Firmware! */
vuint32 vHsmUpdMsCounter = 0;

V_MEMRAM0 V_MEMRAM1 vHsmUpd_UpdateHeaderType V_MEMRAM2  vHsmUpdUpdateHeader;

V_MEMRAM0 V_MEMRAM1 vuint32 V_MEMRAM2  vHsmUpdUpdateContainerSignatureAddr;

#  pragma section all "vHsmGlobalRamBuffer"
volatile uint16 d_dumy_for_align ;
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 tmpBuffer[2*BYTES_TO_PROCESS];
vuint32 tmpSize ;
vuint32 tmpCmacSize ;
#  pragma section all restore

#if defined( FBL_ENABLE_COMMON_DATA )

const uint8 ecuNameRight[] = "RBTMFR174";
static uint8 ecuName[10] = "RBTMFL174";
const uint8 HSMPartNo[] ="1749025702";


/* Common data structure definition                                        *
 * This information is shared with the application and has to be adapted   *
 * to ECU specific values. The data is also used in DIDs supported by the  *
 * Bootloader. */
V_MEMROM0 V_MEMROM1 tFblCommonData fblCommonData =
{
   /* ECU hardware version (year, week, patch level, uint8 encoded)        *
    * Example: year = 2012, week = 14, patch level = 0                     *
    * DID: F150                                                            */
   { 23u, 17u, 0u },

   /* Hardware supplier information (defined by Daimler for each supplier) *
    * Example: Vector = 0x008B                                             *
    * Autoliv = 0x0077                                                     *
    * DID: F154                                                            */
   { 0x00u, 0x77 },

   /* F155                                                                 *
    * Software Supplier information
    * Vector = 0x008B                                                      *
    * Autoliv = 0x0077                                                     */  
   {0x00, 0x8B},                                                 
   {0x00, 0x77},

   /* Hardware part number (ASCII encoded)                                 *
    * DID: F111, business unit specific                                    */
   /* Value now set during init, based on NVM block and side               */
   { "0000000000" },

   /* Application software part number                                     *
    * DID: F121, business unit specific                                    */
   {"1749025500"},

   /* FBL software part number                                             *
    * DID: F121, business unit specific                                    */
   {"1749041800"},

   /* Application software version (year, week, patch level, uint8 encoded)*
    * Example: year = 2012, week = 14, patch level = 0                     *
    * DID: F151                                                            *
    * ATTENTION: Value in table not used; read from ROM (if app            *
    * available) and populates this entry at startup                       */
   { 23u, 18u, 0u },

   /* Boot software version (year, week, patch level, uint8 encoded)       *
    * Example: year = 2012, week = 14, patch level = 0                     *
    * DID: F153                                                            *
    * ATTENTION: Init value below not used, but read from ROM at startup   *
    * and populated here (check stFbl_SW_Version)                          */
   { 0xFF, 0xFF, 0xFF },

   /* Standard Bootloader software information (BCD encoded)               *
    * Information is provided with the bootloader delivery.                *
    * DID: EF02                                                            */
   {
     { (vuint8)(FBL_VERSION>>8), (vuint8)FBL_VERSION, (vuint8)FBL_BUGFIX_VERSION },
     { 0u },
     { "TC322LP   " }
   },

   /* EF05 - Minimum Software Version                                      */
   { 23u, 31u, 0u},

   /* F10D - DDS Package Release Information                               */
   {  { 20u, 1u },
      { 20u, 1u }
   },

   /* F100                                                                 *
      Active diagnostic information:                                       *
    * Active diagnostic status: 0=Application, 1=Boot                      *
    * Active diagnostic variant                                            *
    * Active diagnostic version                                            */
   {0x01, 0x02, 0x05},

   /* ECU Name                                                             *
    * DID: F104                                                            */
   ecuName
};
#endif /* FBL_ENABLE_COMMON_DATA */

volatile uint8 flashDriverActive_u8;

#define FBL_SW_VERSIONS_START_SEC_CONST
#include"MemMap.h"
/*Replaces 'init' value from structure above*/
const tFblBootSoftwareVersion stFbl_SW_Version = {24u, 15u, 0u};
#define FBL_SW_VERSIONS_STOP_SEC_CONST
#include "MemMap.h"

const tFblAppSoftwareVersion * pAppl_SW_Version = FBL_APPLICATION_SW_VERSION_LOCATION;

static Hardware_Partnumber_Type HardwarePartnumber;

#if ( DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
/** Pointer to select active ECU of a multiple identity configuration */
P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) activeCwConfiguration;

# if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kNrOfConfigInitPtrs = sizeof(FblCw_PCConfigsType) / sizeof(FblCw_PCConfigType);
# endif /* FBL_ENABLE_MULTIPLE_PLATFORMS */
#endif /* DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/* Security Access status information */
V_MEMRAM0 static V_MEMRAM1 vuint8                  V_MEMRAM2 seedValid;
V_MEMRAM0 static V_MEMRAM1 SecM_EntropyPoolType    V_MEMRAM2 secEntropyPool;
/* PRQA S 3218 1 */ /* MD_FblKbApiOem_3218_FileScopeStatic */
V_MEMRAM0 static V_MEMRAM1 vuint8                  V_MEMRAM2 secEntropyInput[2];
V_MEMRAM0 static V_MEMRAM1 SecM_SeedStorageType    V_MEMRAM2 secSeedData;
/* PRQA S 3218 1 */ /* MD_FblKbApiOem_3218_FileScopeStatic */
V_MEMRAM0 static V_MEMRAM1 SecM_SeedKeyContextType V_MEMRAM2 secSeedContext;
V_MEMRAM0 static V_MEMRAM1 SecM_SeedType           V_MEMRAM2 seed;

#if defined( FBL_ENABLE_DATA_PROCESSING )
# if defined( FBL_ENABLE_ENCRYPTION_MODE )
#  if ( SEC_MODE_AES_IV == SEC_MODE_AES_IV_CONSTANT )
/* PRQA S 3218 1 */ /* MD_FblKbApiOem_3218_FileScopeStatic */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 decAesIv[SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC] =
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#  endif /* SEC_MODE_AES_IV == SEC_MODE_AES_IV_CONSTANT */

V_MEMRAM0 static V_MEMRAM1 tFblResult V_MEMRAM2 decInitializeState;
V_MEMRAM0 static V_MEMRAM1 tFblResult V_MEMRAM2 decFinalizeState;
/* Buffer for temporary input remainder */
/* PRQA S 3218 1 */ /* MD_FblKbApiOem_3218_FileScopeStatic */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 decTmpInBuffer[SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC];
/* Temporary input buffer usage */
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 decTmpInUsed;
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
/* Buffer for temporary output */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 decTmpOutBuffer[16u * SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC];
/* Temporary output buffer usage */
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 decTmpOutFree;
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 decTmpOutUsed;
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
# endif /* FBL_ENABLE_ENCRYPTION_MODE */
#endif /* FBL_ENABLE_DATA_PROCESSING */


#if defined( FBL_ENABLE_APPL_TASK )
static vuint16 flashlight;
#endif

#if defined( FBL_APPL_ENABLE_BUSTYPE_FR )

V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 wakeupDetected; /* PRQA S 3218 */ /* MD_FblKbApi_3218_FileScopeStatic */

/* These are the I/O pins used for Transceiver access. Adjust this to your needs */
V_MEMROM0 static V_MEMROM1 FrTrcvChannelType V_MEMROM2 FrTrcvChannel[] =
{
   {
      /* I/O used for Transceiver  */
      (vuint8)FRTRCV_CHANNEL_EN_0,
      (vuint8)FRTRCV_CHANNEL_STBN_0,
      (vuint8)FRTRCV_CHANNEL_ERRN_0,
   }
};
#endif /* FBL_APPL_ENABLE_BUSTYPE_FR */


/*vHsmUpdater relevant data*/
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 vHsmUpdMagicPatternPre[HDR_MAGIC_PATTERN_SIZE] = {0x56u, 0x45u, 0x43u, 0x5Fu, 0x48u, 0x44u, 0x52u, 0x5Fu, 0x48u, 0x53u, 0x4Du, 0x00u, 0x00u, 0x00u, 0x00u, 0x01u};

/* Patter used for the re-encryption */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 vHsmUpdMagicPatternPost[HDR_MAGIC_PATTERN_SIZE] = {0x56u, 0x45u, 0x43u, 0x5Fu, 0x45u, 0x50u, 0x50u, 0x5Fu, 0x48u, 0x53u, 0x4Du, 0x00u, 0x00u, 0x00u, 0x00u, 0x01u};

/* Presence pattern needed to flag a valid Update Header */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 vHsmUpd_NvPattern[] = {0x73u, 0x6Au, 0x25u, 0x3Eu};

/* This is the public key counterpart of the private key that was used by the HexView scritp to sign the firmware */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 TV_ED25519_PUBLICKEY[32] =
{
  0xECu, 0x17u, 0x2Bu, 0x93u, 0xADu, 0x5Eu, 0x56u, 0x3Bu, 0xF4u, 0x93u, 0x2Cu, 0x70u, 0xE1u, 0x24u, 0x50u, 0x34u,
  0xC3u, 0x54u, 0x67u, 0xEFu, 0x2Eu, 0xFDu, 0x4Du, 0x64u, 0xEBu, 0xF8u, 0x19u, 0x68u, 0x34u, 0x67u, 0xE2u, 0xBFu
};



/***********************************************************************************************************************
 *  EXTERNAL DATA
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  PROTOTYPES
 **********************************************************************************************************************/

static vuint8 AppFblDioReadChannel( vuint8 FrTrcv_TrcvPin );
static void AppFblDioWriteChannel( vuint8 FrTrcv_TrcvPin, vuint8 FrTrcv_TrcvPinLevel );

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblInit
 **********************************************************************************************************************/
/*! \brief       Function is called before any other FBL initialization
 **********************************************************************************************************************/
void ApplFblInit( void )
{

#if defined( BRS_FBL_LEGACY )
# if defined( BRS_ENABLE_WATCHDOG )
   /* Disable Watchdog */
   BrsHwWatchdogInitPowerOn();
# endif /* BRS_ENABLE_WATCHDOG */

  Mcu_Init( &Mcu_Config );
  Mcu_InitClock(0);
  while (MCU_PLL_LOCKED != Mcu_GetPllStatus());
  Mcu_DistributePllClock();
    
# if defined( BRSHW_DISABLE_ECC_AVAILABLE )
   /* Disable Flash ECC error reporting. */
   BrsHwDisableEccErrorReporting();
# endif /* BRSHW_DISABLE_ECC_AVAILABLE */

# if defined( FBL_ENABLE_PRE_TIMERINIT )
   /* Timer is stopped by mode switch and has to be re-initialized. */
   FblTimerInit();
# endif /* FBL_ENABLE_PRE_TIMERINIT */
#endif /* BRS_FBL_LEGACY */

  Port_Init( &Port_Config );

#  if defined( FBL_APPL_ENABLE_DOIP )
  /* perform reset of Ethernet Phy */
  Dio_WriteChannel(DioConf_DioChannel_DioChannel_ETHSWITCH_PHY_NRESET, STD_LOW);

  /* wait for about 1 ms (at 150 MHz) */
  {
    uint32 i;
    for (i = 0; i < 1500; i++)
    {
      BrsHwTime100NOP();
    }
  }

  /* get Ethernet Phy out of reset */
  Dio_WriteChannel(DioConf_DioChannel_DioChannel_ETHSWITCH_PHY_NRESET, STD_HIGH);

  /* enable Tx feature */
  Dio_WriteChannel(DioConf_DioChannel_DioChannel_ETHSWITCH_PHY_TXEN, STD_HIGH);
#  endif /* FBL_APPL_ENABLE_DOIP */
# ifdef VSWT_USED 
  /* Let the MQ5072 run (otherwise it will stay in reset - no communication would be possible) */
   Dio_WriteChannel(DioConf_DioChannel_DioChannel_ETHSWITCH_SW_RESET, 0);
   
  {
    uint32 i;
    for (i = 0; i < 15000; i++)
    {
      BrsHwTime100NOP();
    }
  }
  
   Dio_WriteChannel(DioConf_DioChannel_DioChannel_ETHSWITCH_SW_RESET, 1);

#endif
   /* Initialize NvM-Driver */
#if defined( WRAPNV_USECASE_FEE )
   WrapNv_Init();
#else
   //jivan
   (void)EepromDriver_InitSync(NULL);
#endif

#ifdef VSWT_USED
   vSwt_InitFlashedBlocks();
#endif 

#if defined( FBL_ENABLE_OTA )
   vOtaM_InitMemory();

   /* Return value will be forwarded from vOtaM_Appl_Init - react in case of any issue */
   if (vOtaM_Init() != E_OK)
   {
      /* PRQA S 2741,4558 1 */ /* MD_FblKbApiOem_2741_4558 */
      assertFblUser(0u, kFblSysAssertInitializationFailed);
   }
#else 
   /* Initialize handle of active area in case of OTA support disabled */
   MemDriver_SetAddressArea(0u);
#endif /* FBL_ENABLE_OTA */

#if defined( FBL_APPL_ENABLE_BUSTYPE_FR )
   /* Initialize the Flexray Transceiver */
   FrTrcv_InitMemory();
   FrTrcv_TrcvInit(FRTRCV_CHANNEL_IDX);
#endif
}

/***********************************************************************************************************************
 *  ApplFblStartup
 **********************************************************************************************************************/
/*! \brief       Bootloader initialization callback
 *  \details     This function is called during the Bootloader initialization if the application software is
 *               not started. It can be used to perform initializations which are not needed if the application
 *               software is started. Please note that the function is called several times with different
 *               initposition values. Timer and hardware can be accessed in post-init phase only.
 *  \param[in]   initposition Initialization state of Bootloader.
 **********************************************************************************************************************/
void ApplFblStartup( vuint8 initposition )
{
   static uint8 IdEcuLocation[3], calledOnce = 0;
   switch (initposition)
   {
      case (kFblInitPreCallback | kFblInitBaseInitialization):
      {
         break;
      }
      case (kFblInitPostCallback | kFblInitBaseInitialization):
      {
         /* Basic hardware initialization */
         ApplFblInit();

         break;
      }
      case (kFblInitPreCallback | kFblInitFblCommunication):
      {
#ifndef VSWT_USED
#if defined( FBL_ENABLE_OTA )
         vOtaM_Main();
#endif /* FBL_ENABLE_OTA */
#endif

#if ( DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON )
         /* TODO: Add some code to decide which variant should be selected,
            e.g. based on a NV-memory entry, pin value or other value.
         */
         // activeCwConfiguration = FblCw_Config_Left_Ptr;
         /* activeCwConfiguration = FblCw_Config_Right_Ptr; */
#endif /* DCM_POSTBUILD_VARIANT_SUPPORT == STD_ON */

         break;
      }
      case (kFblInitPostCallback | kFblInitFblCommunication):
      {
#ifdef VSWT_USED
#if defined( FBL_ENABLE_OTA )
         vOtaM_Main();
#endif /* FBL_ENABLE_OTA */
#endif
         break;
      }
      case (kFblInitPreCallback | kFblInitFblFinalize):
      {
         break;
      }
      case (kFblInitPostCallback | kFblInitFblFinalize):
      {
         ApplFblNvReadNVP_BLOCK_ID_HW_PARTNUMBER(&HardwarePartnumber);

         if(RBTM_FR_ID_NVM == activeEcuSide)
         {
            VStdMemCpy (ecuName,ecuNameRight, 10u);
            activeCwConfiguration = FblCw_Config_RBTM_FR_Ptr;
            VStdMemCpy (fblCommonData.EcuHardwarePartNumber, HardwarePartnumber.au8FRHardwarePartnumber,sizeof (fblCommonData.EcuHardwarePartNumber));

         }
         else
         {
            activeCwConfiguration = FblCw_Config_RBTM_FL_Ptr;
            VStdMemCpy (fblCommonData.EcuHardwarePartNumber, HardwarePartnumber.au8FLHardwarePartnumber,sizeof (fblCommonData.EcuHardwarePartNumber));
         }

         /*Copy sw versions from code flash to general structure*/
         VStdMemCpy(&fblCommonData.EcuBootSoftwareVersion, &stFbl_SW_Version, sizeof(tFblBootSoftwareVersion));
         VStdMemCpy(&fblCommonData.EcuAppSoftwareVersion, pAppl_SW_Version, sizeof(tFblAppSoftwareVersion));
         
#if defined(FBLBM_ENABLE_SECURE_BOOT)
         ApplFblSbStartup();
#endif
         (void)ApplFblDowngradeProtectionInit();
         break;
      }
      default:
      {
         /* PRQA S 2741,4558 1 */ /* MD_FblKbApiOem_2741_4558 */  
         assertFblInternal(0u, kFblSysAssertParameterOutOfRange);
         break; /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      }
   }
}


/***********************************************************************************************************************
 *  ApplFblCheckProgConditions
 **********************************************************************************************************************/
/*! \brief       This function is called after receiving the service request sessionControl ProgrammingSession to check
 *               the programming conditions like reprogramming counter, ambient temperature, programming voltage, etc.
 *  \return      If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblCheckProgConditions( void )
{
   /* TODO_CUSTOMER: Check programming environment like supply voltage, *
    * ambient temperature, etc. here.                         */

   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplTrcvrNormalMode
 **********************************************************************************************************************/
/*! \brief       Activate transceiver if necessary (e.g. pin configuration ENABLE = 1, _STDBY = 1)
 **********************************************************************************************************************/
void ApplTrcvrNormalMode( void )
{
#if defined( FBL_APPL_ENABLE_BUSTYPE_FR )
   (void)FrTrcv_SetTransceiverMode(FRTRCV_CHANNEL_IDX, FRTRCV_TRCVMODE_NORMAL);
#endif /* FBL_APPL_ENABLE_BUSTYPE_FR */
}

/***********************************************************************************************************************
 *  ApplTrcvrSleepMode
 **********************************************************************************************************************/
/*! \brief       Turn off the transceiver to enter sleep mode (e.g. pin configuration ENABLE = 1, _STDBY = 0)
 **********************************************************************************************************************/
void ApplTrcvrSleepMode( void )
{
#if defined( FBL_APPL_ENABLE_BUSTYPE_FR )
   (void)FrTrcv_SetTransceiverMode(FRTRCV_CHANNEL_IDX, FRTRCV_TRCVMODE_SLEEP);
#endif /* FBL_APPL_ENABLE_BUSTYPE_FR */
}

/***********************************************************************************************************************
 *  ApplFblSetVfp
 **********************************************************************************************************************/
/*! \brief       Function is called when the FBL enters programming mode.
 *  \details     Port bits have to be set so that the required programming voltage is available.
 **********************************************************************************************************************/
void ApplFblSetVfp( void )
{
   /* Set flash programming voltage */
#if defined( BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE )
   BrsHwSetVfp();
#endif
}

/***********************************************************************************************************************
 *  ApplFblResetVfp
 **********************************************************************************************************************/
/*! \brief       This function is called when the programming is done.
 **********************************************************************************************************************/
void ApplFblResetVfp( void )
{
   /* Reset flash programming voltage */
#if defined( BRSHW_VOLTAGE_FOR_FLASH_PROGRAMMING_AVAILABLE )
   BrsHwResetVfp();
#endif
}

/***********************************************************************************************************************
 *  ApplFblReset
 **********************************************************************************************************************/
/*! \brief       This function performs a reset.
 *  \details     The function will wait until the reset is performed. Please note: This function will
 *               never return to the calling code.
 **********************************************************************************************************************/
void ApplFblReset( void )
{
   uint8 *Reset_After_Programming_u8 = (uint8 *)0xB0001FFFu;

   /* Set a pattern in LMU0 so APP will know to wake up after flashing */
   *Reset_After_Programming_u8 = 0xAAu;
   
   /* Reset ECU */
   Mcu_PerformReset();
}

# define FBLAP_RAMCODE_START_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplFblSecuritySeedInit
 **********************************************************************************************************************/
/*! \brief       Initialize seed values.
 *  \return      Status of seed initialization
 **********************************************************************************************************************/
vuint8 ApplFblSecuritySeedInit( void )
{
   vuint16 hwTimer;

   /* Read current hardware timer value */
   hwTimer = FblGetTimerValue();

   /* Fill entropy pool */
   FblMemSetInteger(sizeof(hwTimer), (vuint32)hwTimer, secEntropyInput);
   (void)SecM_ProvideEntropy(&secEntropyPool, secEntropyInput, 2u);

   return kFblOk;
}
# define FBLAP_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  ApplFblSecurityInit
 **********************************************************************************************************************/
/*! \brief       Initialize security module.
 *  \return      Status of security module initialization
 **********************************************************************************************************************/
vuint8 ApplFblSecurityInit( void )
{
   /* Cancel active jobs when changing session to prevent jobs in crypto stack from being locked */
   SecM_CancelAllJobs();

   /* Initialize entropy pool and context variables */
   SecM_InitEntropy(&secEntropyPool);

   seed.entropyPool = &secEntropyPool;
   seed.data = (SecM_SeedBaseType *)secSeedData;

   /* PRQA S 0314 1 */ /* MD_FblKbApiOem_0314_VoidPtrTypedPtr */
   secEntropyPool.context = (SecM_VoidPtrType)&secSeedContext;
   secSeedContext.wdTriggerFct = (FL_WDTriggerFctType)FblRealTimeSupport; /* PRQA S 0313 */ /* MD_FblKbApiOem_0313 */
   secSeedContext.workspace.data = SEC_DEFAULT_WORKSPACE;
   secSeedContext.workspace.size = SEC_DEFAULT_WORKSPACE_SIZE;

   seedValid = 0u;

   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblSecuritySeed
 **********************************************************************************************************************/
/*! \brief       This function is called when the tester requests the security seed.
 *  \return      Status of seed generation
 **********************************************************************************************************************/
/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
vuint8 ApplFblSecuritySeed( void )
{
   vuint8 result;

   result = kFblOk;

   /* Check for optional pre-conditions before seed generation                *
    * Return kFblFailed if optional condtionas are not fulfilled              */

   /* A new seed is generated only if a seed has not been requested before.   *
    * Otherwise, the stored seed is sent again.                               */
   if (seedValid == 0u)
   {
      /* Ensure that seed has been initialized */
      while (secEntropyPool.fillLevel < SEC_ENTROPY_POOL_SIZE)
      {
         (void)ApplFblSecuritySeedInit();
      }

      /* Generate seed */
      result = SecM_GenerateSeed(&seed);
   }

   if (result == SECM_OK)
   {
      /* Copy seed value into DiagBuffer */
      /* PRQA S 0314 1 */ /* MD_FblKbApiOem_0314 */
      (void)MEMCPY(&DiagBuffer[kDiagFmtSubparam + 1u], (const void *)secSeedData, kSecSeedLength);

      seedValid = 1u;
   }

   return result;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblSecurityKey
 **********************************************************************************************************************/
/*! \brief       This function is called when the security key has been received from tester
 *  \return      Status of key verification
 **********************************************************************************************************************/
vuint8 ApplFblSecurityKey( void )
{
   vuint8 result;
   SecM_KeyStorageType keyData;
   SecM_KeyType key;
   SecM_ComputeKeyVendorParamType keyContext;

   /* Initialize variables */
   result = kFblFailed;

   /* Current seed is no longer valid */
   seedValid = 0u;

   /* PRQA S 0314 1 */ /* MD_FblKbApiOem_0314 */
   (void)MEMCPY(keyData, &DiagBuffer[kDiagFmtSeedKeyStart], kSecKeyLength);

   keyContext.wdTriggerFct = FblLookForWatchdogVoid;
   key.context = (SecM_VoidPtrType)&keyContext; /* PRQA S 0314 */ /* MD_FblKbApiOem_0314_VoidPtrTypedPtr */
   key.data    = keyData;

   /* Check key from tester */
   if (SecM_CompareKey(key, seed) == SECM_OK)
   {
      /* Key bytes accepted */
      result = kFblOk;
   }

   return result;
}

#if defined( FBL_ENABLE_DATA_PROCESSING )
/***********************************************************************************************************************
 *  ApplFblInitDataProcessing
 **********************************************************************************************************************/
/*! \brief         This function is called to initialize the application specific data processing function.
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblInitDataProcessing( tProcParam * procParam )
{
#if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
    defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )   || \
    defined( FBL_ENABLE_ENCRYPTION_MODE )
   tFblResult result;

   /* Initialize variables */
   result = kFblFailed;

   /* Check if data processing mode is supported */
   if (GetOemProcessingModeSupported(procParam->mode))
   {
      result = kFblOk;

# if defined( FBL_ENABLE_COMPRESSION_MODE )
      if (GetOemCompressionMode(procParam->mode))
      {
         /* Initialize decompression */
#  if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR )
         InitDecompressionVL();
#  elif defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
         result = CmprLzmaInit();
#  endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
      }
# endif /* FBL_ENABLE_COMPRESSION_MODE */

# if defined( FBL_ENABLE_ENCRYPTION_MODE )
      if ((result == kFblOk) && (GetOemEncryptionMode(procParam->mode))) /* PRQA S 2991, 2995 */ /* MD_FblKbApiOem_2991_2995 */
      {
         /* Initialize decryption */
         if (SecM_InitDecryption(V_NULL) != SECM_OK)
         {
            result = kFblFailed;
         }
         else
         {
            /* Initialize decryption on first run */
            decInitializeState = kFblOk;

            /* Prevent multiple finalization calls */
            decFinalizeState = kFblOk;

            decTmpInUsed = 0u;

#  if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
      defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
#   if defined( FBL_ENABLE_COMPRESSION_MODE )
            decTmpOutFree = sizeof(decTmpOutBuffer);
            decTmpOutUsed = 0u;
#   endif /* FBL_ENABLE_COMPRESSION_MODE */
#  endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
         }
      }
# endif /* FBL_ENABLE_ENCRYPTION_MODE */
   }

   return result;
#else
   /* Example implementation. Data not processed at all. */
   tFblResult result;

   result = kFblOk;

   return result;
#endif /* FBL_APPL_ENABLE_DE* */
}

/***********************************************************************************************************************
 *  ApplFblDataProcessing
 **********************************************************************************************************************/
/*! \brief         Data processing function.
 *  \pre           Data processing has to be initialized by call of ApplFblInitDataProcessing
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673, 6010, 6030, 6080 1 */ /* MD_FblKbApi_3673, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
tFblResult ApplFblDataProcessing( tProcParam * procParam )
{
#if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
    defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA ) || \
    defined( FBL_ENABLE_ENCRYPTION_MODE )
   tFblResult              result;
# if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
     defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )

#  if defined( FBL_ENABLE_COMPRESSION_MODE )
   tFblResult              lastCallByLibMem;
#   if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR )
   tCmprParam              cmprParam;
#   elif defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
   tProcParam              cmprParam;
   tFblResult              finalizeLzma;
#   endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
# endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */

# if defined( FBL_ENABLE_ENCRYPTION_MODE )
   vuint16                 index;
   tFblResult              finalize;

   SecM_DecInputParamType  decInBlock;
   SecM_DecOutputParamType decOutBlock;
   SecM_DecParamType       decParam;

   vuint16                 consumedLen = 0u;
   vuint16                 producedLen = 0u;
   vuint16                 localRemainder = 0u;
# endif /* FBL_ENABLE_ENCRYPTION_MODE */

   /* Initialize variables */
   result = kFblFailed;

# if defined( FBL_ENABLE_COMPRESSION_MODE )
   /* Last call by FblLib_Mem is done with length = 0 */
   if (procParam->dataLength == 0u)
   {
      lastCallByLibMem = kFblOk;
   }
   else
   {
      lastCallByLibMem = kFblFailed;
   }
# endif /* FBL_ENABLE_COMPRESSION_MODE && FBL_APPL_ENABLE_DECOMPRESSION_LZMA */

   /* Check if data format is supported */
   if (GetOemProcessingModeSupported(procParam->mode))
   {
      result = kFblOk;

# if defined( FBL_ENABLE_ENCRYPTION_MODE )
      /* Check if encryption mode is supported */
      if (GetOemEncryptionMode(procParam->mode))
      {
#  if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
      defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
#   if defined( FBL_ENABLE_COMPRESSION_MODE )
         /* Check the following:
          * - Compression did not consume all data during last cycle
          * - Not enough data is available for another decryption cycle
          * - This is the last call from the libmem and data is still available for decryption (applicable for AES-GCM) */
         if ((decTmpOutUsed > 0u)
            && (((lastCallByLibMem == kFblOk) && (decTmpInUsed == 0u)) ||
            (decTmpOutFree < SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC)))
         {
            /* No decryption during this cycle, only decompression of remainder from last cycle */
         }
         /* Check if input length is sufficient to decrypt data */
         else if ((lastCallByLibMem == kFblFailed) &&
            ((procParam->dataLength + decTmpInUsed) < SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC))
         {
            /* No decryption during this cycle, copy data to buffer and do not decompress. */
            consumedLen = procParam->dataLength;
            /* Temporarily store remainder */
            for (index = 0u; index < procParam->dataLength; index++)
            {
               decTmpInBuffer[index + decTmpInUsed] = procParam->dataBuffer[index];
            }
            decTmpInUsed += procParam->dataLength;
         }
         else
         {
#   endif /* FBL_ENABLE_COMPRESSION_MODE */
#  endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
            /* Pass watchdog trigger */
            /* PRQA S 0313 1 */ /* MD_FblKbApiOem_0313 */
            decParam.wdTriggerFct = (FL_WDTriggerFctType)FblLookForWatchdog;

            if (kFblOk == decInitializeState)
            {
               /* Only perform single initialization call */
               decInitializeState = kFblFailed;

               /* Set mode for initialization vector handling */
               decParam.mode = SEC_MODE_AES | SEC_DECRYPTION_MODE_INIT;

#   if ( SEC_MODE_AES_IV == SEC_MODE_AES_IV_CONSTANT )
               /* Initialize implicit constant IV */

               /* Copy IV constant to RAM buffer */
               for (index = 0u; index < sizeof(decAesIv); index++)
               {
                  decTmpInBuffer[index] = decAesIv[index];
               }

               decInBlock.DataBuffer = decTmpInBuffer;
               decInBlock.Length = sizeof(decAesIv);

               /* No actual data produced */
               decOutBlock.DataBuffer = procParam->dataOutBuffer;
               decOutBlock.Length = procParam->dataOutMaxLength;

               /* Perform decryption */
               if (SecM_DecryptionUpdate(&decInBlock, &decOutBlock, &decParam, decryptionConfig) != SECM_OK)
               {
                  result = kFblFailed;
               }

               /* Set mode for initialization vector handling */
               decParam.mode = SEC_MODE_AES;
#   endif /* SEC_MODE_AES_IV == SEC_MODE_AES_IV_CONSTANT */
            }
            else
            {
               /* Set mode for initialization vector handling */
               decParam.mode = SEC_MODE_AES;
            }

#   if ( SEC_MODE_AES_IV == SEC_MODE_AES_IV_CONSTANT )
            /* Check if initialization of explicit constant IV was successful */
            if (kFblOk == result)
#   endif /* SEC_MODE_AES_IV == SEC_MODE_AES_IV_CONSTANT */
            {
#  if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
      defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
#   if defined( FBL_ENABLE_COMPRESSION_MODE )
               /* Check if compression mode is supported */
               if (GetOemCompressionMode(procParam->mode))
               {
                  /* Place decryption output in temporary buffer */
                  decOutBlock.DataBuffer = &decTmpOutBuffer[decTmpOutUsed];
                  decOutBlock.Length = decTmpOutFree;
               }
               else
#   endif /* FBL_ENABLE_COMPRESSION_MODE */
#  endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
               {
                  /* Place decryption output in buffer provided by caller, use complete buffer */
                  decOutBlock.DataBuffer = procParam->dataOutBuffer;
                  decOutBlock.Length = procParam->dataOutMaxLength;
               }

               if (0u != decTmpInUsed)
               {
                  decInBlock.DataBuffer = decTmpInBuffer;

                  /* Special handling: If this is the last call and data is still available for decryption
                   * feed the remaining data to the decryption job (only applicable for AES-GCM) */
                  if (lastCallByLibMem == kFblOk)
                  {
                     decInBlock.Length = decTmpInUsed;
                     decTmpInUsed = 0u;
                  }
                  else
                  {
                     /* Calculate remaining space in decTmpInBuffer */
                     localRemainder = SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC - decTmpInUsed;

                     if (localRemainder > procParam->dataLength)
                     {
                        localRemainder = procParam->dataLength;

                        /* Do not decrypt as not enough input data is available */
                        decInBlock.Length = 0u;
                     }
                     else
                     {
                        /* Decrypt input data in decTmpInBuffer */
                        decInBlock.Length = SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC;
                     }

                     /* Copy input data until decTmpInBuffer full or no more input data available */
                     for (index = 0u; index < localRemainder; index++)
                     {
                        decTmpInBuffer[decTmpInUsed + index] = procParam->dataBuffer[index];
                     }

                     decTmpInUsed += localRemainder;
                     consumedLen = localRemainder;
                  }
               }
               else
               {
                  /* Use input data provided by caller */
                  decInBlock.DataBuffer = procParam->dataBuffer;
                  decInBlock.Length = procParam->dataLength;

                  /* Limit input size to output length (decryption module requires this internally) */
                  if (decOutBlock.Length < decInBlock.Length)
                  {
                     decInBlock.Length = decOutBlock.Length;
                  }

                  consumedLen = decInBlock.Length;

                  /* If this is the last call from the libmem feed the remaining decryption data, otherwise
                   * round down to next multiple of SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC and calculate remainder */
                  if (lastCallByLibMem == kFblOk)
                  {
                     decTmpInUsed = decInBlock.Length;
                  }
                  else
                  {
                     decTmpInUsed = decInBlock.Length & (SEC_DECRYPTION_BLOCK_SIZE_AES_PKCS_CBC - 1u);
                  }
                  decInBlock.Length -= decTmpInUsed;

                  /* Temporarily store remainder */
                  for (index = 0u; index < decTmpInUsed; index++)
                  {
                     decTmpInBuffer[index] = decInBlock.DataBuffer[decInBlock.Length + index];
                  }
               }

               /* If actual decryption is not called, no data will be consumed or produced
                * Finalize decryption in case no new input data is provided */
               if (lastCallByLibMem == kFblOk)
               {
                  decParam.mode |= SEC_DECRYPTION_MODE_FINALIZE;
                  finalize = decFinalizeState;
                  /* Prevent multiple finalization calls */
                  decFinalizeState = kFblFailed;
               }
               else
               {
                  finalize = kFblFailed;
               }

               if ((decInBlock.Length > 0u) || (kFblOk == finalize))
               {
                  /* Perform decryption */
                  if (SecM_Decryption(&decInBlock, &decOutBlock, &decParam) == SECM_OK)
                  {
                     producedLen = decOutBlock.Length;

                     if (0u != localRemainder)
                     {
                        /* Data from decTmpInBuffer has been processed, buffer no longer in use */
                        decTmpInUsed = 0u;
                     }
                  }
                  else
                  {
                     result = kFblFailed;
                  }
               }
            }
#  if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
      defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
#   if defined( FBL_ENABLE_COMPRESSION_MODE )
         }

         if (GetOemCompressionMode(procParam->mode))
         {
            decTmpOutUsed += producedLen;
            decTmpOutFree -= producedLen;

            /* Pass temporary output buffer to decompression */
#    if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR )
            cmprParam.inputBuffer = decTmpOutBuffer;
            cmprParam.inputLength = decTmpOutUsed;
#    elif defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
            cmprParam.dataBuffer = decTmpOutBuffer;
            cmprParam.dataLength = decTmpOutUsed;
#    endif /* FBL_APPL_ENABLE_DECOMPRESSION_VECTOR */
         }
         else
#   endif /* FBL_ENABLE_COMPRESSION_MODE */
#  endif /* FBL_APPL_ENABLE_DECOMPRESSION_VECTOR */
         {
            /* Resulting output length */
            procParam->dataOutLength = producedLen;
         }

         /* Update processed input length */
         procParam->dataLength = consumedLen;
      }
      else
# endif /* FBL_ENABLE_ENCRYPTION_MODE */
      {
# if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
     defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
         /* Directly pass input buffer to decompression */
#   if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR )
         cmprParam.inputBuffer = procParam->dataBuffer;
         cmprParam.inputLength = procParam->dataLength;
#   elif defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
         cmprParam.dataBuffer = procParam->dataBuffer;
         cmprParam.dataLength = procParam->dataLength;
#   endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
# endif /* FBL_APPL_ENABLE_DECOMPRESSION_VECTOR */
      }

# if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
     defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
      /* Check if compression mode is supported */
      if (GetOemCompressionMode(procParam->mode))
      {
         /* Check if optional decryption was successful */
         if (result == kFblOk)
         {
#   if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR )
            /* Initialize decompression variables */
            cmprParam.outputBuffer = procParam->dataOutBuffer;
            cmprParam.outputLength = procParam->dataOutMaxLength;

            /* Decompress block */
            if (DecompressBlockVL(&cmprParam) == kCmprOk)
#   elif defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
            /* Initialize decompression variables */
            cmprParam.dataOutBuffer = procParam->dataOutBuffer;
            cmprParam.dataOutMaxLength = procParam->dataOutMaxLength;
            cmprParam.wdTriggerFct = procParam->wdTriggerFct;

            finalizeLzma = kFblFailed;
#    if defined( FBL_ENABLE_ENCRYPTION_MODE )
            if (GetOemEncryptionMode(procParam->mode))
            {
               /* Check if the function was called with no new data and the encryption has been finalized */
               if ((decFinalizeState == kFblFailed) && (lastCallByLibMem == kFblOk))
               {
                  finalizeLzma = kFblOk;
               }
            }
            else
#    endif /* FBL_ENABLE_ENCRYPTION_MODE */
            {
               /* Check if the function was called with no new data */
               if (lastCallByLibMem == kFblOk)
               {
                  finalizeLzma = kFblOk;
               }
            }
            /* Finalize decompression in case no new input data is provided */
            if (finalizeLzma == kFblOk)
            {
               result = CmprLzmaDeinit(&cmprParam);
            }
            else
            {
               /* Check if there is new data for decompression */
               if (cmprParam.dataLength > 0u)
               {
                  result = CmprLzmaDecompress(&cmprParam);
               }
               else
               {
                  /* No decompression this time. Report no processed bytes to FblLib_Mem */
                  result = kFblOk;
                  cmprParam.dataOutLength = 0u;
               }
            }

            if (result == kFblOk)
#   endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
            {
#   if defined( FBL_ENABLE_ENCRYPTION_MODE )
               if (GetOemEncryptionMode(procParam->mode))
               {
#    if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR )
                  /* Update buffer usage */
                  decTmpOutUsed -= (vuint16)(cmprParam.inputLength);
                  decTmpOutFree += (vuint16)(cmprParam.inputLength);

                  /* Copy unprocessed temporary data to front */
                  for (index = 0u; index < decTmpOutUsed; index++)
                  {
                     decTmpOutBuffer[index] = decTmpOutBuffer[(vuint16)(cmprParam.inputLength) + index];
                  }
#    elif defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
                  /* Update buffer usage */
                  decTmpOutUsed -= cmprParam.dataLength;
                  decTmpOutFree += cmprParam.dataLength;

                  /* Copy unprocessed temporary data to front */
                  for (index = 0u; index < decTmpOutUsed; index++)
                  {
                     decTmpOutBuffer[index] = decTmpOutBuffer[cmprParam.dataLength + index];
                  }
#    endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
               }
               else
#   endif /* FBL_ENABLE_ENCRYPTION_MODE */
#   if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR )
               {
                  /* Processed input length */
                  procParam->dataLength = (vuint16)(cmprParam.inputLength);
               }

               /* Resulting output length */
               procParam->dataOutLength = (vuint16)(cmprParam.outputLength);
#   elif defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
               {
                  /* Processed input length */
                  procParam->dataLength = cmprParam.dataLength;
               }

               /* Resulting output length */
               procParam->dataOutLength = cmprParam.dataOutLength;
#   endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
            }
            else
            {
               result = kFblFailed;
            }
         }
      }
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
# endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
   }

   return result;
#else
   /* Example implementation. Data not processed at all. */
   tFblResult result;

   result = kFblOk;

   /* Calculate output length. Length will not change */
   if (procParam->dataLength > procParam->dataOutMaxLength)
   {
      procParam->dataOutLength = procParam->dataOutMaxLength;
   }
   else
   {
      procParam->dataOutLength = procParam->dataLength;
   }

   /* Update actually consumed length */
   procParam->dataLength = procParam->dataOutLength;

   /* Copy data from input to output buffer. */
   FblLookForWatchdogVoid();
   (void)MEMCPY(procParam->dataOutBuffer, procParam->dataBuffer, procParam->dataOutLength);

   return result;
#endif /* FBL_APPL_ENABLE_DE* */
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  ApplFblDeinitDataProcessing
 **********************************************************************************************************************/
/*! \brief         Deinitialize data processing function.
 *  \pre           Data processing has to be initialized by call of ApplFblInitDataProcessing
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblDeinitDataProcessing( tProcParam * procParam )
{
#if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
    defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )   || \
    defined( FBL_ENABLE_ENCRYPTION_MODE )
   tFblResult result;

   result = kFblOk;

/* FblLibMem makes sure that data has been processed completely */
# if defined( FBL_ENABLE_ENCRYPTION_MODE )
   if (GetOemEncryptionMode(procParam->mode))
   {
      if (SecM_DeinitDecryption(V_NULL) != SECM_OK)
      {
         result = kFblFailed;
      }
   }

#  if defined( FBL_APPL_ENABLE_DECOMPRESSION_VECTOR ) || \
      defined( FBL_APPL_ENABLE_DECOMPRESSION_LZMA )
#   if defined( FBL_ENABLE_COMPRESSION_MODE )
   /* Reset buffer usage */
   decTmpOutUsed = 0;
#   endif /* FBL_ENABLE_COMPRESSION_MODE */
#  endif /* FBL_APPL_ENABLE_DECOMPRESSION_ */
# endif /* FBL_ENABLE_ENCRYPTION_MODE */

   return result;
#else
   /* Example implementation. Data not processed at all. */
   tFblResult result;

   /* Conclude data processing in last round */
   result = ApplFblDataProcessing(procParam);

   return result;
#endif /* FBL_APPL_ENABLE_DE* */
}
#endif

#if defined( FBL_ENABLE_APPL_TASK ) || \
    defined( FBL_ENABLE_APPL_TIMER_TASK )
/***********************************************************************************************************************
 *  ApplFblTask
 **********************************************************************************************************************/
/*! \brief       1ms user task.
 *  \details     This function is called every millisecond if the Bootloader is in idle state. It is not called during
 *               flash operations.
 **********************************************************************************************************************/
void ApplFblTask( void )
{
   #if 0
   IfxPort_setPinModeOutput(&MODULE_P20, 14, 0x80, 0x80);
   static V_MEMRAM1 vuint16 V_MEMRAM2 flashlight;
   static Can_PduType dummy;
   static Std_ReturnType result = E_OK;
   //visiin- Tested
   flashlight++;
   Platform_TogglePin(TRUE);
   if (flashlight >= 500u)
   {
      
      Platform_TogglePin(FALSE);

      static uint8 myMsg[8];// = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
      myMsg[0] = 0xA7; /* Set first data byte to 0x04 */
      myMsg[1] = 0xA0; /* Set first data byte to 0x04 */
      myMsg[2] = 0xAA; /* Set first data byte to 0x04 */
      dummy.id = 0x32; /* ID of dummy message */
      dummy.length = sizeof(myMsg); /* Set message length to 8 */
      dummy.sdu = (uint8*)&myMsg[0];
      dummy.swPduHandle = 0;
      result = Can_Write(0, &dummy);
      flashlight=0;
   }
   #endif 
}


#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_TIMER_TASK */

#if defined( FBL_ENABLE_APPL_TASK ) ||\
    defined( FBL_ENABLE_APPL_STATE_TASK )
/***********************************************************************************************************************
 *  ApplFblStateTask
 **********************************************************************************************************************/
/*! \brief       Background user task.
 *  \details     This function is polled if the Bootloader is in idle state. It is not called during flash operations.
 **********************************************************************************************************************/
void ApplFblStateTask( void )
{
}
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_STATE_TASK */

#if defined( FBL_ENABLE_MULTIPLE_PLATFORMS )
/***********************************************************************************************************************
 *  ApplFblPlatformToConfigPtr
 **********************************************************************************************************************/
/*! \brief       Select the configuration according to the requested platform code
 *  \detail      This function is called after the platform message has been received. The value of the "platform"
 *               parameter corresponds to the platform code of the received message.
 *               This function has to map the platform code to one of the configured identities.
 *  \param[in]   platform Code of requested platform
 *  \return      Pointer to configuration
 **********************************************************************************************************************/
FUNC_P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) ApplFblPlatformToConfigPtr( vuint8 platform )
{
   /* ToDo: Convert platform code to initialization pointer    *
    * Current platform codes: 0: Idle                          *
    *                         1: STAR1                         *
    *                         2: STAR2                         *
    * value range: 1 <= platform <= Number of configured identities */

   /* Function must return a valid initialization pointer.     */

   P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) newConfig;

   switch (platform)
   {
      case 1u:
      {
         newConfig = FblCw_Config_Left_Ptr;
      }
      break;

      case 2u:
      {
         newConfig = FblCw_Config_Right_Ptr;
      }
      break;

      default:
      {
         /* Return default configuration */
         newConfig = FblCw_Config_Left_Ptr;
      }
      break;
   }
   return newConfig;
}
#endif /* FBL_ENABLE_MULTIPLE_PLATFORMS */

#if defined( FBL_ENABLE_BUSTYPE_CAN )
#if defined( FBL_ENABLE_MULTIPLE_NODES ) || \
    defined( FBL_ENABLE_CAN_CONFIGURATION) || \
    defined( FBL_CW_ENABLE_MULTIPLE_NODES )
/***********************************************************************************************************************
 *  ApplFblCanParamInit
 **********************************************************************************************************************/
/*! \brief       Overwrite default CAN parameters
 *  \details     This function is called before CAN controller initialization so that default initialization values
 *               can be overridden according to the boot mode.
 *               If this function is empty, the default/reset settings are used to initialize the CAN controller.
 *  \pre         fblCanIdTable has to be initialized with default/reset
 **********************************************************************************************************************/
void ApplFblCanParamInit( void )
{
}
#endif
#endif /* FBL_ENABLE_BUSTYPE_CAN */

/***********************************************************************************************************************
 *  ApplFblSetWakeupEvent
 **********************************************************************************************************************/
/*! \brief       Marks a wake-up event as pending if validation is required.
 *  \param[in]   EcuM_WakeupSource_t source of the wake-up event.
 **********************************************************************************************************************/
void ApplFblSetWakeupEvent( vuint32 WakeupSource_t )
{
#if defined( FBL_APPL_ENABLE_BUSTYPE_FR )
   wakeupDetected = TRUE;
#endif
}

#if defined( FBL_APPL_ENABLE_BUSTYPE_FR )
/***********************************************************************************************************************
 *  ApplFblCwWakeUp
 **********************************************************************************************************************/
/*! \brief       This call-back function is called if a wake-up condition is detected during sleep mode
 *  \pre         Transceiver in sleep mode
 *  \return      kFblOk if wake-up detected, otherwise kFblFailed
 **********************************************************************************************************************/
vuint8 ApplFblCwWakeUp( void )
{
   /* TODO: Insert your use-case specific wake-up mode implementation here. */
   tFblResult result;
   vuint16 i;


   /* Preset return value */
   result = kFblFailed;
   wakeupDetected = FALSE;

   /* Wait 2 ms */
   for (i = 0u; i < 1000u; i++)
   {
      ApplFblTrcvDelay(2u);
   }
   FrTrcv_MainFunction();
   if (wakeupDetected == TRUE)
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblTrcvDelay
 **********************************************************************************************************************/
/*! \brief       Function used to generate a small delay
 *  \param[in]   delay delay value
 **********************************************************************************************************************/
void ApplFblTrcvDelay( vuint8 delay )
{
   vuint8 i;
   /* Attention: The number of loop iterations has to be adjusted by the Integrator accordingly
                 to generate the correct timing for reading the bus Transceiver status word! */
   while (delay > (vuint8)0u)
   {
      (void)FblLookForWatchdog();
      i = FrTrcv_Config[0].FrTrcv_ReadOutWS;
      for(; i > (vuint8)0u; i--)
      {
         ;
      }
      delay--;
   }
}

/***********************************************************************************************************************
 *  AppFblDioReadChannel
 **********************************************************************************************************************/
/*! \brief       Service function to get the transceiver pin level
 *  \pre         Transceiver must be initialized
 *  \param[in]   FrTrcv_TrcvPin Transceiver pin
 *  \return      Returns the level of the transceiver pin
 **********************************************************************************************************************/
static vuint8 AppFblDioReadChannel( vuint8 FrTrcv_TrcvPin )
{
   vuint8 result = STD_HIGH;

   switch (FrTrcv_TrcvPin)
   {
      case FRTRCV_CHANNEL_EN_0:
      {
         /* ToDo: Add code to read pin state here */
         break;
      }
      case FRTRCV_CHANNEL_STBN_0:
      {
         /* ToDo: Add code to read pin state here */
         break;
      }
      case FRTRCV_CHANNEL_ERRN_0:
      {
         /* ToDo: Add code to read pin state here */
         break;
      }
      default:
      {
         break;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  AppFblDioWriteChannel
 **********************************************************************************************************************/
/*! \brief       Service function to set the transceiver pin level
 *  \pre         Transceiver must be initialized
 *  \param[in]   FrTrcv_TrcvPin Transceiver pin
 *  \param[in]   FrTrcv_TrcvPinLevel Transceiver level to be set
 **********************************************************************************************************************/
static void AppFblDioWriteChannel( vuint8 FrTrcv_TrcvPin, vuint8 FrTrcv_TrcvPinLevel )
{
   switch (FrTrcv_TrcvPin)
   {
      case FRTRCV_CHANNEL_EN_0:
      {
         if (STD_HIGH == FrTrcv_TrcvPinLevel)
         {
            /* ToDo: Set EN-pin to HIGH level here */
         }
         else
         {
            /* ToDo: Set EN-pin to LOW level here */
         }
         break;
      }
      case FRTRCV_CHANNEL_STBN_0:
      {
         if (STD_HIGH == FrTrcv_TrcvPinLevel)
         {
            /* ToDo: Set STBN.pin to HIGH level here */
         }
         else
         {
            /* ToDo: Set STBN-pin to LOW level here */
         }
         break;
      }
      case FRTRCV_CHANNEL_ERRN_0:
      {
         /* Do nothing, ERR-pin can not be written! */
         break;
      }
      default:
      {
         break;
      }
   }
}

/***********************************************************************************************************************
 *  ApplFblTrcvPhyTrcvInit
 **********************************************************************************************************************/
/*! \brief       Service function to initialize the FlexRay Transceiver
 *  \param[in]   FrTrcv_TrcvIdx The transceiver to be set into the requested mode
 **********************************************************************************************************************/
void ApplFblTrcvPhyTrcvInit( const vuint8 FrTrcv_TrcvIdx )
{
   /* If the Transceiver requires initialization, it can be done here */
}

/***********************************************************************************************************************
 *  ApplFblTrcvPhySetMode
 **********************************************************************************************************************/
/*! \brief       Service function to set the transceiver into a specific mode
 *  \pre         Transceiver must be initialized
 *  \param[in]   FrTrcv_TrcvIdx The transceiver to be set into the requested mode
 *  \param[in]   FrTrcv_TrcvMode The operation mode
 *  \return      BusTrcvErrorType: BUSTRCV_E_OK: Initialization was successful
 *               BUSTRCV_E_ERROR: Transceiver could not be initialized
 **********************************************************************************************************************/
vuint8 ApplFblTrcvPhySetMode( const vuint8 FrTrcv_TrcvIdx, const vuint8 FrTrcv_TrcvMode )
{
   /* Example implementation for the TJA1080 Flexray Transceiver */
   /* Modes are { Unknown, Normal, Standby, Sleep, Receiveonly } */
   V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 trcvPinEn[] =
   { (vuint8)STD_LOW, (vuint8)STD_HIGH, (vuint8)STD_LOW, (vuint8)STD_HIGH, (vuint8)STD_LOW };
   V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 trcvPinStbn[] =
   { (vuint8)STD_LOW, (vuint8)STD_HIGH, (vuint8)STD_LOW, (vuint8)STD_LOW, (vuint8)STD_HIGH };

   FrTrcv_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   /* Set the connected Transceiver to the requested mode */
   if ((vuint8)STD_HIGH == trcvPinStbn[FrTrcv_TrcvMode] )
   {
      AppFblDioWriteChannel(FrTrcvChannel[FrTrcv_TrcvIdx].TrcvPinSTBN, (vuint8)STD_HIGH);
      AppFblDioWriteChannel(FrTrcvChannel[FrTrcv_TrcvIdx].TrcvPinEN, trcvPinEn[FrTrcv_TrcvMode]);
      /* Give EN time to reach the mode control block */
      ApplFblTrcvDelay((vuint8)FRTRCV_TJA1080_DELAYWIDTHUS);
   }
   else
   {
      AppFblDioWriteChannel(FrTrcvChannel[FrTrcv_TrcvIdx].TrcvPinEN, trcvPinEn[FrTrcv_TrcvMode]);
      /* Give EN time to reach the mode control block */
      ApplFblTrcvDelay((vuint8)FRTRCV_TJA1080_DELAYWIDTHUS);
      AppFblDioWriteChannel(FrTrcvChannel[FrTrcv_TrcvIdx].TrcvPinSTBN, (vuint8)STD_LOW);
   }
   FrTrcv_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

   return((BusTrcvErrorType)BUSTRCV_E_OK);
}

/***********************************************************************************************************************
 *  ApplFblTrcvPhyGetMode
 **********************************************************************************************************************/
/*! \brief       Service function to get the status mode of the transceiver
 *  \param[in]   FrTrcv_TrcvIdx The transceiver to be set into the requested mode
 *  \param[in]   FrTrcv_TrcvMode The operation mode
 *  \return      BusTrcvErrorType: BUSTRCV_E_OK: Initialization was successful
 *                                 BUSTRCV_E_ERROR: Transceiver could not be initialized
 **********************************************************************************************************************/
vuint8 ApplFblTrcvPhyGetMode( const vuint8 FrTrcv_TrcvIdx, vuint8 *FrTrcv_TrcvModePtr )
{
   /* Example implementation for the TJA1080 Flexray Transceiver */
   V_MEMROM0 static V_MEMROM1 FrTrcv_TrcvModeType V_MEMROM2 FrTrcv_TrcvModeTable[] =
   { (FrTrcv_TrcvModeType)FRTRCV_TRCVMODE_STANDBY, (FrTrcv_TrcvModeType)FRTRCV_TRCVMODE_RECEIVEONLY,
    (FrTrcv_TrcvModeType)FRTRCV_TRCVMODE_SLEEP, (FrTrcv_TrcvModeType)FRTRCV_TRCVMODE_NORMAL };

   vuint8 kModeIdx;
   kModeIdx = (vuint8)0u;

   FrTrcv_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   if ((vuint8)STD_HIGH == AppFblDioReadChannel(FrTrcvChannel[FRTRCV_CHANNEL_IDX].TrcvPinSTBN) )
   {
      kModeIdx |= (vuint8)1u;
   }
   if ((vuint8)STD_HIGH == AppFblDioReadChannel(FrTrcvChannel[FRTRCV_CHANNEL_IDX].TrcvPinEN) )
   {
      kModeIdx |= (vuint8)2u;
   }
   FrTrcv_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

   *FrTrcv_TrcvModePtr = FrTrcv_TrcvModeTable[kModeIdx];
   return((BusTrcvErrorType)BUSTRCV_E_OK);
}

/***********************************************************************************************************************
 *  ApplFblTrcvPhyReadStatusWord
 **********************************************************************************************************************/
/*! \brief       Service function to read the TJA1080 status word
 *  \param[in]   FrTrcv_TrcvIdx The transceiver to be set into the requested mode
 *  \param[in]   FrTrcv_StatusWordType Status word from the transceiver
 *  \return      BUSTRCV_E_OK
 **********************************************************************************************************************/
vuint8 ApplFblTrcvPhyReadStatusWord( const vuint8 FrTrcv_TrcvIdx, vuint16 * TrcvStatusWord )
{
   /* Example implementation for the TJA1080 Flexray Transceiver */
   vuint8  cnt;
   FrTrcv_StatusWordType result;
   vuint8  TrcvEN;

   /* Initial state - no events */
   result = (FrTrcv_StatusWordType)0xFFFFu;

   FrTrcv_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   /* Preserve the current transceiver state */
   TrcvEN = AppFblDioReadChannel(FrTrcvChannel[FRTRCV_CHANNEL_IDX].TrcvPinEN);

   /* Create initial condition to read status word */
   cnt = FRTRCV_TJA1080_COUNTER;
   if ((vuint8)STD_HIGH == TrcvEN )
   {
      /* Correct initial EN state */
      cnt = (FRTRCV_TJA1080_COUNTER - 1u);
   }

   for( ; cnt > (vuint8)0u; cnt-- )
   {
      /* Timing is very important for reading the transceiver     */
      /* Interrupts shall be disabled                             */
      /* Total runtime for this loop should be around 60us - 80us */
      AppFblDioWriteChannel(FrTrcvChannel[FRTRCV_CHANNEL_IDX].TrcvPinEN, (vuint8)STD_LOW);
      ApplFblTrcvDelay((vuint8)FRTRCV_TJA1080_PULSEWIDTHUS);
      result <<= 1u;
      AppFblDioWriteChannel(FrTrcvChannel[FRTRCV_CHANNEL_IDX].TrcvPinEN, (vuint8)STD_HIGH);
      ApplFblTrcvDelay((vuint8)FRTRCV_TJA1080_PULSEWIDTHUS);
      if ((vuint8)STD_HIGH == AppFblDioReadChannel(FrTrcvChannel[FRTRCV_CHANNEL_IDX].TrcvPinERRN) )
      {
         result |= (FrTrcv_StatusWordType)1u;
      }
   }

   /* Restore previous transceiver state */
   AppFblDioWriteChannel(FrTrcvChannel[FRTRCV_CHANNEL_IDX].TrcvPinEN, TrcvEN);

   FrTrcv_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

   /* High-active flags have to be returned, the transceiver delivers low-active flags --> invert them */
   *TrcvStatusWord = result ^ (FrTrcv_StatusWordType)FRTRCV_STATUS_INVERT_MASK;

   return((BusTrcvErrorType)BUSTRCV_E_OK);
}
#endif /* FBL_APPL_ENABLE_BUSTYPE_FR */

#if defined( FBL_APPL_ENABLE_BUSTYPE_CAN )
/***********************************************************************************************************************
 *  ApplFblCanBusOff
 **********************************************************************************************************************/
/*! \brief       This call-back function is called if the CAN controller enters bus-off state.
 **********************************************************************************************************************/
void ApplFblCanBusOff( void )
{
   /* Bus off detected, issue ECU reset */
   ApplFblReset(); /* PRQA S 2987 */ /* MD_FblKbApiOem_2987_EmptyFunction */
}

#endif /* FBL_APPL_ENABLE_BUSTYPE_CAN */

# if defined( FBL_ENABLE_SLEEPMODE )
/***********************************************************************************************************************
 *  ApplFblBusSleep
 **********************************************************************************************************************/
/*! \brief       Indicates transition to bus silence.
 *  \details     By calling this function the FBL indicates the application
 *               that the bootloader can go to sleep (bus silence, no diagnostic requests).
 **********************************************************************************************************************/
void ApplFblBusSleep( void )
{
   /*Shutdown connections and prepare for shutdown*/
   FblCwShutdownRequest(kFblCwResetEcuTesterTimeout);
}
#endif /* FBL_ENABLE_SLEEPMODE */

# if ( FBLCW_MODULE_COMM == STD_ON )
#  define FBLAP_RAMCODE_START_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/***********************************************************************************************************************
 *  ApplFbl_ComM_SilentComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that silent communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
/* PRQA S 3206 1 */ /* MD_FblKbApi_3206 */
FUNC(void, FBLCW_CODE) ApplFbl_ComM_SilentComModeEntered(NetworkHandleType channel)
{
}

/***********************************************************************************************************************
 *  ApplFbl_ComM_NoComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that no communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
/* PRQA S 3206 1 */ /* MD_FblKbApi_3206 */
FUNC(void, FBLCW_CODE) ApplFbl_ComM_NoComModeEntered(NetworkHandleType channel)
{
}

/***********************************************************************************************************************
 *  ApplFbl_ComM_FullComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that full communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
/* PRQA S 3206 1 */ /* MD_FblKbApi_3206 */
FUNC(void, FBLCW_CODE) ApplFbl_ComM_FullComModeEntered(NetworkHandleType channel)
{
}
#  define FBLAP_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif

/***********************************************************************************************************************
 *  ApplFblMemPreErase
 **********************************************************************************************************************/
/*! \brief       Check for error before erasing NVM
 *  \return      kFblOk if PreErase operations are successful, kFblFailed if PreErase operations failed
 **********************************************************************************************************************/
tFblResult ApplFblMemPreErase( void )
{
   tFblResult result = kFblOk;

   /* Check for error condition (e.g. Voltage too high/low) */
   /* TODO_CUSTOMER check for voltage/temperature out of range
   if (voltageTooHigh)
   {
      DiagSetEraseErrorVoltageTooHigh();
      result = kFblFailed;
   }
   else if (voltageTooLow)
   {
      DiagSetEraseErrorVoltageTooLow();
      result = kFblFailed;
   }
   else if (tempTooHigh)
   {
      DiagSetEraseErrorTempTooHigh();
      result = kFblFailed;
   }
   else if (tempTooLow)
   {
      DiagSetEraseErrorTempTooLow();
      result = kFblFailed;
   }
   else
   {
   }*/

   return result;
}

/***********************************************************************************************************************
 *  ApplFblMemPreWrite
 **********************************************************************************************************************/
/*! \brief       Check for error before writing to NVM
 *  \return      kFblOk if PreWrite operations are successful, kFblFailed if PreWrite operations failed
 **********************************************************************************************************************/
tFblResult ApplFblMemPreWrite( void )
{
   tFblResult result = kFblOk;

   /* Check for error condition (e.g. Voltage too high/low) */
   /* TODO_CUSTOMER check for voltage out of range
   if (voltageTooHigh)
   {
      DiagSetError(kDiagNrcVoltageTooHigh);
      result = kFblFailed;
   }
   else if (voltageTooLow)
   {
      DiagSetError(kDiagNrcVoltageTooLow);
      result = kFblFailed;
   }
   else
   {
   }*/

   return result;
}

/***********************************************************************************************************************
 *  ApplFblMemConditionCheck
 **********************************************************************************************************************/
/*! \brief       Memory condition checks like programming voltage can be implemented here.
 *  \details     This function is called before AND after each memory operation, i.e. before and after erase- and write.
 *  \return      kFblMemStatus_Ok: Programming conditions OK
                 kFblMemStatus_XXX: Violated programming condition
 **********************************************************************************************************************/
tFblMemStatus ApplFblMemConditionCheck( void )
{
   tFblMemStatus checkResult;

   /*
    * Use the following return codes:
    * kFblMemStatus_Ok
    * kFblMemStatus_VoltageTooHigh
    * kFblMemStatus_VoltageTooLow
    * kFblMemStatus_TemperatureTooHigh
    * kFblMemStatus_TemperatureTooLow
    * */
   checkResult = kFblMemStatus_Ok;

   /*
    * Distinguish between erase and write with TransferDataAllowed flag
    * TransferDataAllowed is set only for write operations.
    */

   /* if (FblDiagGetTransferDataAllowed()) */
   {
      /* TODO_CUSTOMER: Check programming voltage */

      /* Voltage too high */
      /* checkResult = kFblMemStatus_VoltageTooHigh; */

      /* Voltage too low */
      /* checkResult = kFblMemStatus_VoltageTooLow; */

      /* TODO_CUSTOMER: Check MCU temperature */

      /* Temperature too high */
      /* checkResult = kFblMemStatus_TemperatureTooHigh; */

      /* Temperature too low */
      /* checkResult = kFblMemStatus_TemperatureTooLow; */
   }

   return checkResult;
}

#if defined( FBL_MIO_ENABLE_HOOKS )
/***********************************************************************************************************************
 *  ApplFblPreMemDriver
 **********************************************************************************************************************/
/*! \brief        Function is called before the memory driver is executed.
 *  \param[in]    device   Memory device, which is going to be used.
 *  \param[in]    function Function of the memory device, which is going to be called.
 **********************************************************************************************************************/
void ApplFblPreMemDriver( vuint8 device, vuint8 function )
{
   uint8 opMode;
   Std_ReturnType retVal = E_OK;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)device;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)function;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   flashDriverActive_u8 = 1u;

   /* Suspend vHSM operations in data flash */
   opMode = CRYPTO_30_VHSM_DATAFLASH_START;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);
   /* Suspend vHSM operations in code flash -> send it to RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_START;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}
#endif /* FBL_MIO_ENABLE_HOOKS */

#if defined( FBL_MIO_ENABLE_HOOKS )
/***********************************************************************************************************************
 *  ApplFblPostMemDriver
 **********************************************************************************************************************/
/*! \brief        Function is called after the memory driver has finished the operation.
 *  \param[in]    device   Memory device, which is going to be used.
 *  \param[in]    function Function of the memory device, which is going to be called.
 **********************************************************************************************************************/
void ApplFblPostMemDriver( vuint8 device, vuint8 function )
{
   uint8 opMode;
   Std_ReturnType retVal = E_OK;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)device;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
   (void)function;  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
#endif

   flashDriverActive_u8 = 0u;

   /* Get vHSM back from RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_STOP;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);
   /* Give vHSM access to data flash operations */
   opMode = CRYPTO_30_VHSM_DATAFLASH_STOP;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}
#endif /* FBL_MIO_ENABLE_HOOKS */


/* LIN specific call-back functions *******************************************/

#if ( TPLIN_VERSION < 0x0200u )
# if defined( DTL_ENABLE_DEBUG )
/***********************************************************************************************************************
 *  ApplDtlFatalError
 **********************************************************************************************************************/
/*! \brief       Indication of fatal errors detected by the diagnostic transport layer
 *  \param[in]   error error code
 **********************************************************************************************************************/
void ApplDtlFatalError( vuint8 error )
{
}
# endif /* DTL_ENABLE_DEBUG */
#else
# if defined ( DTL_ENABLE_ERROR_REPORT )
/**********************************************************************************************************************
 * ApplDtlFatalError
 *********************************************************************************************************************/
/*! \brief       Indicates fatal errors detected by the diagnostic transport layer.
 *  \details     Callback function for the application called by the DTL after a fatal error has been detected.
 *               This can be caused by an inconsistent configuration, an inconsistent internal state or the usage of a
 *               function parameter out of the allowed range. The call of the function must be observed during
 *               development.
 *  \param[in]   bApiId             Identifier of function in which the error was detected.
 *  \param[in]   bError             Error code of the detected error.
 *********************************************************************************************************************/
void ApplDtlFatalError(vuint8 bApiId, vuint8 bError)
{
}
# endif /* DTL_ENABLE_ERROR_REPORT */
#endif /* ( TPLIN_VERSION < 0x0200u ) */

#if defined( LIN_APISTYLE_VECTOR )
/***********************************************************************************************************************
 *  ApplLinWakeUp
 **********************************************************************************************************************/
/*! \brief       Notification of a transition to wakeup after reception or transmission of a wakeup frame
 **********************************************************************************************************************/
void ApplLinWakeUp( void )
{
}

/***********************************************************************************************************************
 *  ApplLinBusSleep
 **********************************************************************************************************************/
/*! \brief       Notification of a transition to sleep mode
 *  \details     The transition to sleep mode is performed after the transmission or reception
 *               of a sleep mode frame or after a bus idle timeout
 **********************************************************************************************************************/
void ApplLinBusSleep( void )
{
}
#endif

/* FblLibMem callback functions  ***********************************************/

#if defined( FBL_MEM_ENABLE_STREAM_OUTPUT )
/***********************************************************************************************************************
 *  ApplFblInitStreamOutput
 **********************************************************************************************************************/
/*! \brief         This function is called to initialize the application specific stream output function.
 *  \param[in,out] streamParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblInitStreamOutput( V_MEMRAM1 tFblMemStreamProcessing V_MEMRAM2 V_MEMRAM3 * streamParam )
{
   tFblResult result;

   /* Initialize variables */
   result = kFblFailed;


   return result;
}

/***********************************************************************************************************************
 *  ApplFblStreamOutput
 **********************************************************************************************************************/
/*! \brief         Stream output function.
 *  \pre           Stream output has to be initialized by call of ApplFblInitStreamOutput
 *  \param[in,out] streamParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblStreamOutput( V_MEMRAM1 tFblMemStreamProcessing V_MEMRAM2 V_MEMRAM3 * streamParam )
{
   tFblResult result;

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)streamParam;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
   result = kFblFailed;

   return result;
}

/***********************************************************************************************************************
 *  ApplFblFinalizeStreamOutput
 **********************************************************************************************************************/
/*! \brief         Finalize stream output function.
 *  \pre           Stream output has to be initialized by call of ApplFblInitStreamOutput
 *  \param[in,out] streamParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblFinalizeStreamOutput( V_MEMRAM1 tFblMemStreamProcessing V_MEMRAM2 V_MEMRAM3 * streamParam )
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)streamParam;
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   result = kFblFailed;

   return result;
}

/***********************************************************************************************************************
 *  ApplFblDeinitStreamOutput
 **********************************************************************************************************************/
/*! \brief         Deinitialize stream output function.
 *  \pre           Stream output has to be initialized by call of ApplFblInitStreamOutput
 *  \param[in,out] streamParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblDeinitStreamOutput( V_MEMRAM1 tFblMemStreamProcessing V_MEMRAM2 V_MEMRAM3 * streamParam )
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)streamParam;
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   result = kFblFailed;

   return result;
}
#endif /* FBL_MEM_ENABLE_STREAM_OUTPUT */

/* Status backup callback functions  *******************************************/
#if defined( FBL_ENABLE_STATUS_BACKUP )
/***********************************************************************************************************************
 *  ApplFblSaveStatus
 **********************************************************************************************************************/
/*! \brief       Save status information
 *  \details     This function copies the data from the given address to a specific memory
 *  \param[in]   sourec Pointer to source buffer
 *  \param[in]   length Number of bytes to copy
 *  \return      Result of operation (kFblOk/kFblFailed)
 **********************************************************************************************************************/
tFblResult ApplFblSaveStatus( const V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 * source, vuint32 length )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblRestoreStatus
 **********************************************************************************************************************/
/*! \brief       Restore status information
 *  \details     This function copies stored data to the given destination
 *  \param[in]   dest Pointer to destination buffer
 *  \param[in]   length Number of bytes to copy
 *  \return      Result of operation (kFblOk/kFblFailed)
 **********************************************************************************************************************/
tFblResult ApplFblRestoreStatus( const V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 * dest, vuint32 length )
{
   return kFblOk;
}
#endif   /* FBL_ENABLE_STATUS_BACKUP */

#if defined( FBL_ENABLE_ASSERTION )
/***********************************************************************************************************************
 *  ApplFblFatalError
 **********************************************************************************************************************/
/*! \brief       If the bootloader assertions are enabled, this function will be called in case an invalid bootloader
 *               state is encountered.
 *  \param[in]   errorCode Code number of the encountered assertion
 *  \param[in]   module Name of the affected module (Only if extended info is enabled)
 *  \param[in]   line Line number where the assertion occurred (Only if extended info is enabled)
 **********************************************************************************************************************/
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorCode; /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* TODO_CUSTOMER: This feature should be activated in development only. Please make sure this
            function isn't called in production code and assertions are disabled in GENy
            (set "Project State" to "Production (default)" or "Production (reduced tests)".
   */
   while (1)
   {
      ;
   }
}
#endif

#if (DET_ENABLED == STD_ON)
# define FBLAP_RAMCODE_START_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplFbl_DetEntryHandler
 **********************************************************************************************************************/
/*! \brief       Called by DET module to check if a DET error is intended bootloader behavior or not.
 *  \param[in]   ModuleId Code number of the encountered assertion
 *  \param[in]   InstanceId Name of the affected module (Only if extended info is enabled)
 *  \param[in]   ApiId Line number where the assertion occurred (Only if extended info is enabled)
 *  \param[in]   ErrorId Line number where the assertion occurred (Only if extended info is enabled)
 *  \return      Report if error should be handed over to DET or not (E_OK or FALSE depending on interface)
 **********************************************************************************************************************/
# if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
# else
FUNC(boolean, DET_APPL_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
# endif
{
# if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
   Std_ReturnType result = E_OK;
# else
   boolean result = FALSE;
# endif

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_DummyStmt */
   (void)InstanceId;
   (void)ApiId;
# endif

   switch (ModuleId)
   {
#  if defined( CANTP_MODULE_ID )
      case CANTP_MODULE_ID:
      {
         switch (ErrorId)
         {
            /* CAN TP errors which can be triggered from outside shouldn't trigger a DET. */
            case CANTP_E_PARAM_CONFIG:
            case CANTP_E_INVALID_RX_BUFFER:
            case CANTP_E_INVALID_RX_LENGTH:
            case CANTP_E_INVALID_TATYPE:
            case CANTP_E_INVALID_FRAME_TYPE:
            case CANTP_E_RX_TIMEOUT_AR:
            case CANTP_E_RX_TIMEOUT_BR:
            case CANTP_E_RX_TIMEOUT_CR:
            case CANTP_E_RX_INVALID_SN:
            case CANTP_E_RX_WFTMAX:
            case CANTP_E_RX_RESTART:
            case CANTP_E_TX_TIMEOUT_AS:
            case CANTP_E_TX_TIMEOUT_BS:
            case CANTP_E_TX_TIMEOUT_CS:
            case CANTP_E_TX_FC_OVFL:
            case CANTP_E_TX_INVALID_FS:
            case CANTP_E_TX_RES_STMIN:
            case CANTP_E_TX_TRANSMIT_ERROR:
            case CANTP_E_NO_ERROR:
            {
#   if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
               result = E_NOT_OK;
#   else
               result = TRUE;
#   endif
               break;
            }
            default:
            {
               /* Keep error */
               break;
            }
         }
         break;
      }
#  endif /* CANTP_MODULE_ID */
#  if defined( CAN_MODULE_ID )
      case CAN_MODULE_ID:
      {
         switch (ErrorId)
         {
            case CAN_E_DATALOST:
            {
#   if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
               result = E_NOT_OK;
#   else
               result = TRUE;
#   endif
               break;
            }
            default:
            {
               /* Keep error */
               break;
            }
         }
         break;
      }
#  endif /* CAN_MODULE_ID */
#  if defined( FRTP_MODULE_ID )
      case FRTP_MODULE_ID:
      {
         switch (ErrorId)
         {
            case FRTP_E_SEG_ERROR:
            case FRTP_E_UMSG_LENGTH_ERROR:
            case FRTP_E_NO_CHANNEL:
            {
#   if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
               result = E_NOT_OK;
#   else
               result = TRUE;
#   endif
               break;
            }
            default:
            {
               /* Keep error */
               break;
            }
         }
         break;
      }
#  endif /* FRTP_MODULE_ID */
#  if defined( DOIP_MODULE_ID )
      case DOIP_MODULE_ID:
      {
         switch (ErrorId)
         {
            case DOIP_E_NOBUFS:
            {
#   if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
               result = E_NOT_OK;
#   else
               result = TRUE;
#   endif
               break;
            }
            default:
            {
               /* Keep error */
               break;
            }
         }
         break;
      }
#  endif /* DOIP_MODULE_ID */
      default:
      {
         /* Unknown module. Keep error. */
         break;
      }
   }

   return result;
}
# define FBLAP_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

tFblResult ApplFblCheckForMagicPattern ( tBlockDescriptor blockDescriptor )
{
	tFblResult retVal;
	vuint8 * pBlockContent;
	vuint8 idx, buffer[HDR_MAGIC_PATTERN_SIZE];
	vuint32 signatureOffset, tmp;
	tFblBmHdrHeader * pBmHdrHeader;

	 /* Initialize variables */
	retVal = kFblOk;

	/* Prepare the pointer ro read the content of the current logical block */
	/* BLOCK_OFFSET is used to account for the BM header since it is configured to be allocated at the very beginning of the logical block */

	/* HSM-UPDATE-002-START */


	retVal = MemDriver_RReadSync(buffer, HDR_MAGIC_PATTERN_SIZE, blockDescriptor.blockStartAddress + BLOCK_OFFSET);


	if(retVal == kFblOk)
	{
		for( idx = 0 ; idx < HDR_MAGIC_PATTERN_SIZE ; idx++ )
		{
			if( vHsmUpdMagicPatternPre[idx] != buffer[idx] )
			{
				/* Magic Pattern doesn't match, it is not a vHsmUpd container! */
				retVal = kFblFailed;
				break;
			}
		}
	}


	if(retVal == kFblOk)
	{
		/* Get the information of the information fom PFLASH to fill the update header */
		VStdMemCpy((void *)vHsmUpdUpdateHeader.HeaderTag, (void *)vHsmUpdMagicPatternPost, VHSMUPD_HEADER_TAG_SIZE );


		retVal |= MemDriver_RReadSync(vHsmUpdUpdateHeader.VersionInfo, sizeof(vHsmUpd_FirmwareVersionType), blockDescriptor.blockStartAddress + BLOCK_OFFSET + HDR_MAGIC_PATTERN_SIZE);
		retVal |= MemDriver_RReadSync(&signatureOffset, sizeof(vHsmUpd_LengthType), blockDescriptor.blockStartAddress + BLOCK_OFFSET + HDR_MAGIC_PATTERN_SIZE + sizeof(vHsmUpd_FirmwareVersionType));


		/* Compute and store the address of the signature (this is the address of the signature of the vHSM Update Container, NOT the CMAC) */
		CHECK_BITORDER(signatureOffset);
		vHsmUpdUpdateContainerSignatureAddr =  blockDescriptor.blockStartAddress + BLOCK_OFFSET + signatureOffset;

		/* vHsmUpdUpdateHeader.Signature is the CMAC which will be ptovided by the vHsm so leave it empty! */

		pBmHdrHeader = blockDescriptor.bmHeaderAddress;

		/* The update container will be allocated at the beginning of the second sector of the logical block */
		/* NOTE: This code assumes the usage of a logical block with two identical size sectors */
		tmp = blockDescriptor.blockStartAddress +  (pBmHdrHeader->bmBlockLength >> 1u);
		/* tmp = HSM_FW_BASE_ADDR + HSM_FW_PP_SIZE;*/
		CHECK_BITORDER(tmp);
		VStdMemCpy((void *)vHsmUpdUpdateHeader.UpdateImageAddress, (void *)(&tmp),  sizeof(vHsmUpd_AddressType));
		
		tmp = vHsmUpdUpdateContainerSignatureAddr - (blockDescriptor.blockStartAddress + BLOCK_OFFSET + HDR_MAGIC_PATTERN_SIZE + sizeof(vHsmUpd_FirmwareVersionType) + sizeof(vHsmUpd_LengthType));
		/* tmp = HSM_FW_BASE_SIZE - HSM_FW_PP_SIZE; */
		CHECK_BITORDER(tmp);
		VStdMemCpy((void *)vHsmUpdUpdateHeader.UpdateImageLength, (void *)(&tmp),  sizeof(vHsmUpd_LengthType));
	}

	/* HSM-UPDATE-002-END */

	return retVal;
}

tFblResult ApplFblHsmReEncrypt( tBlockDescriptor blockDescriptor )
{
   tFblResult retVal = kFblOk;
   vuint32 idx, currentAddress, currentSize, remainingData, writeSize, writeAddr, bytesReceived, neededPages;
   tFblBmHdrHeader *pBmHdrHeader;

   /* HSM-UPDATE-003-START */

   retVal == kFblOk;
#if 0
	/* This key is private in the vHsm, it is not possible to initialize it on the host side */
	/* Initialization is done in the vHsm configuration with an init value  */

	/* This is the key that decrypts the data, it must match with the one used in the HexView scripts */
	retVal = Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_FirmwareUpdate_Decrypt,CRYPTO_KE_CIPHER_KEY, decryptKey, sizeof(decryptKey));

	if (retVal == kFblOk)
	{
		retVal = Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_FirmwareUpdate_Decrypt, CRYPTO_KE_CIPHER_IV, iv, sizeof(iv));
	}

	if (retVal == kFblOk)
	{
		retVal = Csm_KeySetValid(CsmConf_CsmKey_CsmKey_vHsm_FirmwareUpdate_Decrypt);
	}

#endif
   /* This is the public key used for signature verification */
   if (retVal == kFblOk)
   {
      retVal = Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_FirmwareUpdate_Signature, CRYPTO_KE_SIGNATURE_KEY, TV_ED25519_PUBLICKEY, sizeof(TV_ED25519_PUBLICKEY));
   }

   if (retVal == kFblOk)
   {
      retVal = Csm_KeySetValid(CsmConf_CsmKey_CsmKey_vHsm_FirmwareUpdate_Signature);
   }

   /* Cyber security initialized, now erase the flash sector where the re-encrypted version will be allocated */
   if (retVal == kFblOk)
   {
      FblLookForWatchdogVoid();
      /* NOTE: FOR THIS TO WORK THE vHsmHw LOGICAL BLOCK NEEDS TO HAVE 2 FALSH SECTORS ONE FOR THE DWONLOADED CONTAINER AND ONE FOR THE RE-ENCRYPTED!!! */
      /*       IF BOTH SECTORS ARE NOT SIMETRIC THIS CODE NEEDS ADAPTION */
      /* get the start address of the half of the logical block which has to match to the second flash sector */
      pBmHdrHeader = blockDescriptor.bmHeaderAddress;
      currentSize = (pBmHdrHeader->bmBlockLength >> 1u);
      /* Compute the address where the re-cryped data is going to be allocated */
      writeAddr = blockDescriptor.blockStartAddress + currentSize;

      /* NOTE: REMEMBER THAT IF YOU ALLOCATED A VERIFICATION CONTAINER AT THE END OF THE BLOCK YOU WILL ERASE IT, BUT AT THIS STAGE IT WAS ALREADY VERIFIED!!! */
      retVal = MemDriver_REraseSync(currentSize, writeAddr);
   }

   /* Compute the amount of data we are going to feed into the vHsm */
   remainingData = vHsmUpdUpdateContainerSignatureAddr - (blockDescriptor.blockStartAddress + BLOCK_OFFSET + HDR_MAGIC_PATTERN_SIZE + sizeof(vHsmUpd_FirmwareVersionType) + sizeof(vHsmUpd_LengthType));

   /* Compute the address where the compressed data starts */
   currentAddress = blockDescriptor.blockStartAddress + BLOCK_OFFSET + HDR_MAGIC_PATTERN_SIZE + sizeof(vHsmUpd_FirmwareVersionType) + sizeof(vHsmUpd_LengthType);

   /* reset byte counter */
   writeSize = 0;

   /* Service the Wdg */
   FblLookForWatchdogVoid();

   if (retVal == kFblOk)
   {
      tmpSize = sizeof(vHsmUpd_UpdateHeaderType);
      /* START:
                           input -> UpdContainerHeader
                 secondary input -> Update header */
      retVal = Csm_AEADEncrypt(
          CsmConf_CsmJob_CsmJob_vHsm_Fw_Update,
          CRYPTO_OPERATIONMODE_START,
          (blockDescriptor.blockStartAddress + BLOCK_OFFSET),
          (HDR_MAGIC_PATTERN_SIZE + sizeof(vHsmUpd_FirmwareVersionType) + sizeof(vHsmUpd_LengthType)),
          &vHsmUpdUpdateHeader,
          tmpSize,
          NULL_PTR, NULL_PTR,
          NULL_PTR, NULL_PTR);
   }

   while ((remainingData > 0u) && (E_OK == retVal))
   {
      if (remainingData >= BYTES_TO_PROCESS)
      {
         /* available segmentation chunk */
         currentSize = BYTES_TO_PROCESS;
         remainingData -= BYTES_TO_PROCESS;
      }
      else
      {
         /* remaining data, this is the last remaining data*/
         currentSize = remainingData;
         remainingData = 0u;
      }

      /* Service the Wdg */
      FblLookForWatchdogVoid();

      if (E_OK == retVal)
      {

         /* Compute the available buffer */
         tmpSize = sizeof(tmpBuffer) - writeSize;

         d_dumy_for_align = 0;

         /* UPDATE:
                         input -> Encrypted firmware
                  secondary input -> Re-crypted firmware */
         retVal = Csm_AEADEncrypt(
             CsmConf_CsmJob_CsmJob_vHsm_Fw_Update,
             CRYPTO_OPERATIONMODE_UPDATE,
             currentAddress,
             currentSize,
             NULL_PTR, 0,
             &tmpBuffer[writeSize],
             &tmpSize,
             NULL_PTR, NULL_PTR);
#if 0	
				if(tmpSize > (3*BYTES_TO_PROCESS))
				{
					/* Got more data that what we can hold in the buffer! */
					retVal = kFblFailed;
				}
#endif
         if (retVal == kFblOk)
         {
            writeSize += tmpSize;

            if (writeSize >= BYTES_TO_PROCESS)
            {
#if 0	
						if (writeAddr == 0x801E0200)
						{
							while (debugBreakPoint == 1)
							{
								/* To handle optimizations */
								debugDummyCounter++;
							}
						}
#endif

               FblLookForWatchdogVoid();

               /* write the re-cryped data to the  */
               retVal = MemDriver_RWriteSync(tmpBuffer, BYTES_TO_PROCESS, writeAddr);

               /* remove the already written data from the pending to write bytes */
               writeSize -= BYTES_TO_PROCESS;

               /* Shift the data to the beginning of the buffer */
               for (idx = 0; idx < writeSize; idx++)
               {
                  tmpBuffer[idx] = tmpBuffer[BYTES_TO_PROCESS + idx];
               }

               writeAddr += BYTES_TO_PROCESS;
            }
         }
      }

      /* increment the pinter by the process data size */
      currentAddress += currentSize;
   }

   if (retVal == kFblOk)
   {
      /* Compute the available buffer */
      tmpSize = sizeof(tmpBuffer) - writeSize;
      tmpCmacSize = VHSMUPD_SIGNATURE_SIZE;

      /* FINISH:
               secondary input  -> Signature over UpdContainer & encrypted firmware image
                 primary output -> last encrypted data
               secondary output -> CMAC */
      retVal = Csm_AEADEncrypt(
          CsmConf_CsmJob_CsmJob_vHsm_Fw_Update,
          CRYPTO_OPERATIONMODE_FINISH,
          NULL_PTR, 0, /* No new the payload */
          vHsmUpdUpdateContainerSignatureAddr, SIGNATURE_SIZE,
          &tmpBuffer[writeSize],
          &tmpSize,
          &vHsmUpdUpdateHeader.Signature[0],
          &tmpCmacSize);

      if (retVal == kFblOk)
      {
         writeSize += tmpSize;

         while ((writeSize > 0) && (retVal == kFblOk))
         {
            FblLookForWatchdogVoid();

            if (writeSize >= BYTES_TO_PROCESS)
            {
               /* remaining data are bigger or equal that the proccess size */

               FblLookForWatchdogVoid();

               /* Write the re-cryped data to program flash.  */
               retVal = MemDriver_RWriteSync(tmpBuffer, BYTES_TO_PROCESS, writeAddr);

               /* Remove the already written data from the pending to write bytes */
               writeSize -= BYTES_TO_PROCESS;

               /* Shift the data to the beginning of the buffer */
               for (idx = 0; idx < writeSize; idx++)
               {
                  tmpBuffer[idx] = tmpBuffer[BYTES_TO_PROCESS + idx];
               }

               writeAddr += BYTES_TO_PROCESS;
            }
            else if (writeSize >= FLASH_SEGMENT_SIZE_PFLASH)
            {
               /* Remaining data are bigger or equal that the flash page size. */

               FblLookForWatchdogVoid();

               /* write the re-cryped data to the  */
               retVal = MemDriver_RWriteSync(tmpBuffer, FLASH_SEGMENT_SIZE_PFLASH, writeAddr);

               /* Remove the already written data from the pending to write bytes. */
               writeSize -= FLASH_SEGMENT_SIZE_PFLASH;

               /* Shift the data to the beginning of the buffer. */
               for (idx = 0; idx < writeSize; idx++)
               {
                  tmpBuffer[idx] = tmpBuffer[FLASH_SEGMENT_SIZE_PFLASH + idx];
               }

               writeAddr += FLASH_SEGMENT_SIZE_PFLASH;
            }
            else
            {
               /* Remaining data is smaller than a flash page and needs padding. */
               for (idx = 0; idx < (FLASH_SEGMENT_SIZE_PFLASH - writeSize); idx++)
               {
                  tmpBuffer[writeSize + idx] = 0x00; /* padding value */
               }

               FblLookForWatchdogVoid();

               /* write the re-cryped data to program flash. */
               retVal = MemDriver_RWriteSync(tmpBuffer, FLASH_SEGMENT_SIZE_PFLASH, writeAddr);

               /* Not needed, but leaves the pointer at the very end. */
               writeAddr += writeSize;

               /* Make sure to stop the loop. */
               writeSize -= writeSize;
            }
         }
      }
   }

   if (retVal == kFblOk)
   {
      /* Write the Update Header and mark it as valid */

      /* Compute the amount of pages needed to allocate the Update header. */
      neededPages = (sizeof(vHsmUpd_UpdateHeaderType) / FLASH_SEGMENT_SIZE_PFLASH);

      if (sizeof(vHsmUpd_UpdateHeaderType) % FLASH_SEGMENT_SIZE_PFLASH != 0u)
      {
         /* one more sector needed */
         neededPages++;
      }

      /* Pages needed for the Update Header only. */
      tmpSize = neededPages;

      /* Fll the buffer with the padding value for update header. */
      VStdMemSet(tmpBuffer, VHSMUPD_UPDATE_HEADER_PADDING_VALUE, (tmpSize * FLASH_SEGMENT_SIZE_PFLASH));

      /* Load the Update Header to the buffer. */
      VStdMemCpy((void *)tmpBuffer, (void *)&vHsmUpdUpdateHeader.HeaderTag[0], sizeof(vHsmUpd_UpdateHeaderType));

      /* Fll the buffer with the padding value for presence patterns (one page). */
      VStdMemSet((void *)&tmpBuffer[tmpSize * FLASH_SEGMENT_SIZE_PFLASH], VHSMUPD_UPDATE_HEADER_PADDING_VALUE, FLASH_SEGMENT_SIZE_PFLASH);

      /* Load the presence pattern. */
      VStdMemCpy((void *)&tmpBuffer[tmpSize * FLASH_SEGMENT_SIZE_PFLASH], (void *)vHsmUpd_NvPattern, sizeof(vHsmUpd_NvPattern));

      /* Compute the amount of pages need by the patterns and the fbl metadata. */
      neededPages += (VHSMUPD_UPDATE_HEADER_PAGES + (FBL_METADATA_SIZE / FLASH_SEGMENT_SIZE_PFLASH));

      /* Compute the Update Header address. */
      writeAddr = (blockDescriptor.blockStartAddress + pBmHdrHeader->bmBlockLength - (neededPages * FLASH_SEGMENT_SIZE_PFLASH));

      /* Take the presence pattern page into account for writting! */
      tmpSize++;

      FblLookForWatchdogVoid();

      /* Write the Update header and presence patter and make sure the page of the MASK remains erased. */

      retVal = MemDriver_RWriteSync(tmpBuffer, (tmpSize * FLASH_SEGMENT_SIZE_PFLASH), writeAddr);
   }

   FblLookForWatchdogVoid();

   /* HSM-UPDATE-003-END */

   return retVal;
}

# define FBLAP_RAMCODE_START_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* This function needs to be executed from RAM! */
tFblResult ApplFblStartHsmUpdAndWait(void)
{
   /* HSM-UPDATE-004-START */
   /*Stop SBC trigger since it runs from codeflash*/
   flashDriverActive_u8 = 1u;

   /* assume the update is done within the timeout time. */
   tFblResult retVal = kFblOk;

   uint8 fpStatus_u8;
   uint8 blockFingerprintHsmSwitch[kEepSizeFingerprint];
   uint16 progAttempts_u16;
   uint8 swVersion[3];
   vuint8 nvBuffer[sizeof(vuint16)];

   /* Instruct the vHsm to jump to the vHsmUpd. */
   Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Info, CRYPTO_KE_CUSTOM_VHSM_FIRMWARE_UPDATE_START_UPDATER, tmpBuffer, sizeof(tmpBuffer));

   /* Set the wait Mask to tell the vHsmUpd that the host is running in RAM and ready for it to proceed with the vHsm firmware update process. */
   /* NOTE: Needed only in recovery mode so not here! it will be ignored by the vHsmUpd! */
   HT2HSMS = VHSMUPD_IPC_WAIT_MASK;

   /* Initialize the timeout couter */
   vHsmUpdMsCounter = VHSMUPD_UPDATE_TIMEOUT_MS;

   while (((HSM2HTS & VHSMUPD_HSM2HOST_HOST_UPD_RUNNING) != VHSMUPD_HSM2HOST_HOST_UPD_RUNNING))
   {
      /* Wait for the vHsmUpd to boot. */
      if ((FblLookForWatchdog() & FBL_TM_TRIGGERED) == FBL_TM_TRIGGERED)
      {
         if (vHsmUpdMsCounter > 0u)
         {
            /* Decrement the timeout counter of the vHsmUpd. */
            vHsmUpdMsCounter--;
         }
      }

      if (vHsmUpdMsCounter == 0u)
      {
         /* The update took more that the timeout so we stop waitting. */
         retVal = kFblFailed;
         break;
      }
   }

   if (retVal == kFblOk)
   {
      /* Initialize the timeout couter */
      vHsmUpdMsCounter = VHSMUPD_UPDATE_TIMEOUT_MS;
   }

   do
   {
      /* Wait in this RAM loop for the vHsmUpd to finish. */
      if ((FblLookForWatchdog() & FBL_TM_TRIGGERED) == FBL_TM_TRIGGERED)
      {
         if (vHsmUpdMsCounter > 0u)
         {
            /* Decrement the timeout counter of the vHsmUpd */
            vHsmUpdMsCounter--;
         }
      }

      if (vHsmUpdMsCounter == 0u)
      {
         /* The update took more that the timeout so we stop waiting. */
         retVal = kFblFailed;
         break;
      }

   } while (((HSM2HTS & VHSMUPD_HSM2HOST_HOST_UPD_RUNNING) == VHSMUPD_HSM2HOST_HOST_UPD_RUNNING));

   if (retVal == kFblOk)
   {
      /* Initialize the timeout couter. */
      vHsmUpdMsCounter = VHSMUPD_UPDATE_TIMEOUT_MS;
   }

   flashDriverActive_u8 = 0u;

   while (((HSM2HTS & VHSMUPD_HSM2HOST_HOST_AVAILABLE) != VHSMUPD_HSM2HOST_HOST_AVAILABLE))
   {
      /* Wait for the vHsm new software to be reachable again. */
      if ((FblLookForWatchdog() & FBL_TM_TRIGGERED) == FBL_TM_TRIGGERED)
      {
         if (vHsmUpdMsCounter > 0u)
         {
            /* Decrement the timeout counter of the vHsmUpd. */
            vHsmUpdMsCounter--;
         }
      }

      if (vHsmUpdMsCounter == 0u)
      {
         /* The update took more that the timeout so we stop waiting. */
         retVal = kFblFailed;
         break;
      }
   }

#if 0
	/* Disable the Flash Traps again as the vHsmUpd leaves them enabled */
	/* Disable Flash 0 traps */
	/* FLASH0_MARD */
	*((volatile vuint32*)0xF80020ACul) = 0x00008000ul;
	/* FLASH0_MARP */
	FblHwRegisterUnlock(FBL_WDT_CPU);
	*((volatile vuint32*)0xF80020A8ul) = 0x00008000ul;
	FblHwRegisterLock(FBL_WDT_CPU);
#endif

   HT2HSMS = VHSMUPD_IPC_Initialized;

   while (Crypto_30_vHsm_CheckForHsmReady())
   {
      /* Wait for the vHsm new software to be reachable again. */
      if ((FblLookForWatchdog() & FBL_TM_TRIGGERED) == FBL_TM_TRIGGERED)
      {
      }
   }

   while (((HSM2HTS & VHSMUPD_HSM2HOST_HOST_SYNCH) != VHSMUPD_HSM2HOST_HOST_SYNCH))
   {
      /* Wait for the vHsm new software be able to receive commands again. */
      if ((FblLookForWatchdog() & FBL_TM_TRIGGERED) == FBL_TM_TRIGGERED)
      {
      }
   }

   /*Switch fingerprint from appl to Hsm*/
   /*Set Fingeprint Status Information to Valid (0x01)*/
   fpStatus_u8 = kDiagFpStatApplValid;
   ApplFblNvWriteFpStatusInfo(2, &fpStatus_u8);

   /*Transfer fingerprint data from application block to bootloader block*/
   /*Read application stored fingeprint and transfer to boot fingerprint (1 - Application, 2 - HSM)*/
   ApplFblNvReadFingerprint(1, blockFingerprintHsmSwitch);
   ApplFblNvWriteFingerprint(2, blockFingerprintHsmSwitch);

   /*Handle Hsm prog attempts*/
   ApplFblNvReadProgAttempts(2, nvBuffer);
   progAttempts_u16 = (vuint16)FblMemGetInteger(sizeof(nvBuffer), nvBuffer);

   if(progAttempts_u16 > 0)
   {
      progAttempts_u16 = FblInvert16Bit(progAttempts_u16);
      progAttempts_u16++;
      progAttempts_u16 = FblInvert16Bit(progAttempts_u16);
   }

   FblMemSetInteger(sizeof(nvBuffer), progAttempts_u16, nvBuffer);
   ApplFblNvWriteProgAttempts(2, nvBuffer);

   ApplFblNvReadSwVersion(1 ,swVersion);
   ApplFblNvWriteSwVersion(2, swVersion);

   fpStatus_u8 = kDiagFpStatEraseStarted;

   swVersion[0] = 0xFF;
   swVersion[1] = 0xFF;
   swVersion[2] = 0xFF;

   /*Replace SW version and Status Info for application block*/
   ApplFblNvWriteFpStatusInfo(1, &fpStatus_u8);
   ApplFblNvWriteSwVersion(1, swVersion);

   /* HSM-UPDATE-004-END */

   return retVal;
}

# define FBLAP_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* module specific MISRA deviations:


   MD_FblKbApi_2889:
      Reason:     Multiple return paths are used to reduce code complexity, increase readability and reducing nesting level.
      Risk:       Some operations intended to conclude the function (e.g. states cleaning) can be unintentionally jumped.
      Prevention: Code inspection and runtime tests.

   MD_FblKbApi_3201:
      Reason: Configuration or platform specific dependent unreachable code.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3206:
      Reason:     Function is part of the bootloader API and the modification or not of the parameter is dependent on
                  configuration and/or platform.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApi_3218_FileScopeStatic:
      Reason: Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk: Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblKbApi_3325:
      Reason: This control expression is always true or false depend on configuration aspect and used platform specific
              implementation.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3353:
      Reason: Variable is set in an other function via call-by-reference.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApi_3673:
      Reason: Function is part of the bootloader API which provides the possibility to influence the bootloader behavior
              by modifying the output parameters. The provided default implementation of the function doesn't
              necessarily make use of all available parameters.
      Risk: The parameter value might be changed unintentionally, thus causing malfunction in the calling instance.
      Prevention: Provide detailed information about the API and its usage in the user documentation.

   MD_FblKbApiOem_0313:
      Reason:     The watchdog trigger function is stored as void pointers as actual type
      Risk:       Function signature not compatible with expected type.
      Prevention: No prevention required.

   MD_FblKbApiOem_0314:
      Reason:     Type conversion to void * is necessary to use the standard MEMCPY API
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_0314_VoidPtrTypedPtr:
      Reason:     SecM uses untyped void pointers for context.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_2741_4558:
      Reason:     Assertion macros have to be disabled in production code and are used only for development.
      Risk:       Assertion code may be enabled in production code unintentionally. If a assertion condition is unexpectedly
                  false, the code is active. A problem may occur if the Macro is additionally changed from single statement
                  to multiple statement.
      Prevention: Macro is not allowed to be changed without review. Development code is automatically disabled via
                  configuration of project state "Production".

   MD_FblKbApiOem_2742:
      Reason:     Compiler related constand expression to check actual size.
      Risk:       No risk.
      Prevention: No prevention required. (Note: assertions are disabled in production software).

   MD_FblKbApiOem_2985:
      Reason:     Macro SetReprogProcessState clears the reprogramming process state flags and then
                  assigns a value of 0.
      Risk:       No identifiable risk
      Prevention: No prevention required.

   MD_FblKbApiOem_2987_EmptyFunction:
      Reason:     Function is empty depending on configuration aspects and platform specific implementation.
      Risk:       Function implementation missing.
      Prevention: Code inspection and test in the component test.

   MD_FblKbApiOem_2991_2995:
      Reason:     Code is shared between different configurations. In other configurations,
                  the result of the comparison/logical operation is not invariant.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_3218_FileScopeStatic:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblKbApiOem_3425:
      Reason:     The WrapNv call uses the ternary operator to remap the return value of IO_E_OK to kFblOk.As both of
                  them are defined to the value zero the remapping has no side affects.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_4342_4521_ConfigurationEnumLengthCast:
      Reason:     The last element of an enum is used to determine the number of entries. This is required for
                  configurable code. The enum must have more than one entry - therefore it is always possible to
                  determine the last (length - 1) one.
      Risk:       No identifiable risk.
      Prevention: No prevention required.


*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_AP.C
 **********************************************************************************************************************/
