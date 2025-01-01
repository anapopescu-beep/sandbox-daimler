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
 *  01.00.00   2019-01-28  visrie  -                Initial version
 *  01.01.00   2019-02-18  vismvi  ESCAN00102171    Variable declared but never referenced
 *                         visrie  ESCAN00102310    Added callout to check reprogramming flag
 *  01.01.01   2019-03-07  visrie  ESCAN00102386    Fixed compiler error in ApplFbl_DetEntryHandler
 *                                 ESCAN00102399    Check NvPattern only for non-RAM blocks
 *  02.00.00   2019-05-02  visrie  ESCAN00102518    Added support to read block/application validity from NV-Memory
 *                                 ESCAN00102761    Added support for 3rd Party Tricore HSM
 *                                 ESCAN00103026    Provide BmHeader instead of StartAddress to ApplFblBmStartSoftware
 *  03.00.00   2019-07-17  visrie  ESCAN00103750    Removed target order list configuration
 *  03.01.00   2019-08-14  visrie  FBL-487          Exclude callouts if overwritten by OEM/HW layer
 *  03.01.01   2019-09-04  visrcn  ESCAN00103607    Memory qualifier mismatch
 *  04.00.00   2019-12-04  visrie  FBL-456          Updated to new LibSecBoot interface
 *                                 ESCAN00105135    Added support for new BRS API
 *  04.01.00   2020-01-16  visrie  FBL-524          Added support for vHsm SecBoot library
 *  05.00.00   2020-04-09  visrie  FBL-1016         Support new vBaseEnv, added support for VTT
 *  05.01.00   2020-04-29  vistmo  FBL-1584         Added OTA startup support
 *  05.02.00   2020-08-13  vistmo  FBL-1489         Added support for OTA swap activation
 *  05.02.01   2021-03-17  vishor  ESCAN00108386    ApplFblBmIsValidBlock implementation does not consider
 *                                                   all possible use cases
 *                                 FBL-3018         No changes
 *  05.03.00   2021-08-11  visrie  FBL-3394         Move default implementation of CheckReprogFlag into FblBm_Ap
 *  05.04.00   2021-09-17  visjdn  FBL-3865         Add default SecBoot implementation for GHS/Escrypt
 *  05.04.01   2022-04-06  vismix  FBL-4773         Support THUMB mode
 *  05.05.00   2022-04-07  vishor  FBL-4822         Add support for new MagicFlag value and Swap API
 *  05.05.01   2022-06-23  vismix  ESCAN00111879    Boot manager does not wait for HSM update recovery
 *  05.06.00   2022-07-13  vismix  FBL-5391         Add callout for missing optional dependency
 *  05.06.01   2022-11-29  vishor  ESCAN00112986    Compiler error: Undefined symbols
 *                                                   ApplFblPreMemDriver/ApplFblPostMemDriver
 **********************************************************************************************************************/

#define BM_AP_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "bm_ap.h"
#include "bm_main.h"
#include "fbl_inc.h"
#include "vMemAccM_Cfg.h"

#if defined( FBL_ENABLE_HARDWARE_SWAP )
# include "fbl_swap.h"
#endif

#include "fbl_main_types.h"

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
# include "Det.h"
#endif
#if defined( FBLBM_ENABLE_SECURE_BOOT )
# include "fbl_secboot.h"
#endif /* FBLBM_AP_ENABLE_3RD_PARTY_TRICORE_HSM_USED */
#  include "Csm.h"
#  include "CryIf.h"
#  include "Crypto_30_vHsm.h"
#  include "Crypto_30_LibCv.h"
# include "BrsHw.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLBM_AP_VERSION != 0x0506u ) || \
    ( FBLBM_AP_RELEASE_VERSION != 0x01u )
# error "Error in bm_ap.c: Source and Header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( _MICROSOFT_C_VTT_ )
# define FBLBM_AP_ENABLE_VTT_USECASE
#endif /* _MICROSOFT_C_VTT_ */

/* If no explicit LB for the LBT exists use the bootloader LB */
#if !defined( FBL_MTAB_LBT_BLOCK_NUMBER )
# define FBL_MTAB_LBT_BLOCK_NUMBER                       FBL_MTAB_BOOTLOADER_BLOCK_NUMBER
#endif /* FBL_MTAB_LBT_BLOCK_NUMBER */

/* Helper macro to get number of array entries */
#if defined( FBLBMAP_ARRAY_SIZE )
#else
# define FBLBMAP_ARRAY_SIZE(arr)                         (sizeof(arr) / sizeof((arr)[0])) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif


#define HT2HSMS (* ( (volatile vuint32 *)(Crypto_30_vHsm_GetHost2HsmAddressOfvHsmOfPCConfig() ) ) )
#define HSM2HTS (* ( (volatile vuint32 *)(Crypto_30_vHsm_GetHsm2HostAddressOfvHsmOfPCConfig() ) ) )

#define VHSMUPD_IPC_WAIT_MASK                       0x80000000uL
 

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLBMAP_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
V_MEMRAM0 static V_MEMRAM1 vuintx V_MEMRAM2 g_ApplFblBmSearchUpdaterHeaderIndex;
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */

#define FBLBMAP_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#  define FBLBMAP_RAMCODE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
static void ApplFblBmWaitForHsm(void);
#  define FBLBMAP_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#  define FBLBMAP_RAMCODE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplFblBmWaitForHsm
 **********************************************************************************************************************/
/*! \brief        Wait until vHSM is ready
 **********************************************************************************************************************/
static void ApplFblBmWaitForHsm(void)
{
   Std_ReturnType retVal;
   uint32 keyLength;
   uint32 hsm2host;
   uint32 host2hsm;

   /* Wait until vHsm has been started */
   do
   {
      /*Do nothing while waiting; do not trigger wdg in case of infinite loop*/
         __asm("nop");
   } while (HSM2HTS == 0u);

   FblLookForWatchdogVoid();

   /* When a vHsmUpd is pending */
   if ((HSM2HTS & (1uL << CRYPTO_30_VHSM_HSM2HOST_UPDATERRUNNING)) == (1uL << CRYPTO_30_VHSM_HSM2HOST_UPDATERRUNNING))
   {
/*#   error "Comment this line if vHsmUpdater is not used. If vHsmUpdater is used, please assign the value 
<vHsmUpd_Ext/vHsmUpd_ExtGeneral/vHsmUpd_ExtIpc/vHsmUpd_ExtIpcWaitMask> configured in the vHsm-updater to host2hsm below" */

      HT2HSMS = VHSMUPD_IPC_WAIT_MASK;
      /* Wait until vHsmUpd has been finished */
      do
      {
         FblLookForWatchdogVoid();
      } while ((HSM2HTS & ((1u << CRYPTO_30_VHSM_HSM2HOST_READY) | (1u << CRYPTO_30_VHSM_HSM2HOST_ACTIVE))) != ((1u << CRYPTO_30_VHSM_HSM2HOST_READY) | (1u << CRYPTO_30_VHSM_HSM2HOST_ACTIVE)));
   };

   FblLookForWatchdogVoid();

   /* Wait until vHsm is ready */
   Crypto_30_vHsm_WaitForHsmRam();
}
#  define FBLBMAP_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define FBLBMAP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  ApplFblBmPowerOnPre
 **********************************************************************************************************************/
/*! \brief        Initialization callout
 **********************************************************************************************************************/
void ApplFblBmPowerOnPre( void )
{

}

/***********************************************************************************************************************
 *  ApplFblBmPowerOnPost
 **********************************************************************************************************************/
/*! \brief        Initialization callout
 **********************************************************************************************************************/
void ApplFblBmPowerOnPost( void )
{

}

/***********************************************************************************************************************
 *  ApplFblBmInitPre
 **********************************************************************************************************************/
/*! \brief        Initialization callout
 **********************************************************************************************************************/
void ApplFblBmInitPre( void )
{
# if defined( BRS_FBL_LEGACY )
#  if defined( BRSHW_PREINIT_AVAILABLE )
   /* HW specific pre-initialization. */
   BrsHwPreInitPowerOn();
#  endif /* BRSHW_PREINIT_AVAILABLE */

#  if defined( BRS_ENABLE_WATCHDOG )
   /* Disable Watchdog */
   BrsHwWatchdogInitPowerOn();
#  endif /* BRS_ENABLE_WATCHDOG */

#  if defined( BRS_ENABLE_PLLCLOCKS )
   /* Initialize the PLLs. */
   BrsHwPllInitPowerOn();
#  endif /* BRS_ENABLE_PLLCLOCKS */

#  if defined( BRSHW_DISABLE_ECC_AVAILABLE )
   /* Disable Flash ECC error reporting. */
   BrsHwDisableEccErrorReporting();
#  endif /* BRSHW_DISABLE_ECC_AVAILABLE */

#  if defined( FBL_ENABLE_PRE_TIMERINIT )
   /* Timer is stopped by mode switch and has to be re-initialized. */
   FblTimerInit();
#  endif /* FBL_ENABLE_PRE_TIMERINIT */
# endif /* BRS_FBL_LEGACY */
}

/***********************************************************************************************************************
 *  ApplFblBmInitPost
 **********************************************************************************************************************/
/*! \brief        Initialization callout
 **********************************************************************************************************************/
void ApplFblBmInitPost( void )
{
   /* Wait until vHSM is ready */
   ApplFblBmWaitForHsm();
   
#if defined( FBLBM_ENABLE_SECURE_BOOT )
   if (executeTestcode == kFblOk) /* Testcode to initialize RAM key, to simulate written key */
   {
      Std_ReturnType retVal;
      uint8 version[3u] = {0u};
      uint32 versionLength = sizeof( version );
      Crypto_VerifyResultType result = CRYPTO_E_VER_NOT_OK;
      const uint8 key[16u] = {0u};
      uint8 mac[16u] = {0u};
      const uint8 data[16u] = {0u};
      uint32 length = sizeof( mac );

      /* Get the Version of the vHsm Firmware */
      retVal = Crypto_30_vHsm_KeyElementGet( CryptoConf_CryptoKey_vHsm_Info, CRYPTO_KE_CUSTOM_VHSM_VERSION, version, &versionLength );

      /* Fill the key used for the CMAC and set it to valid */
      retVal |= Csm_KeyElementSet( CsmConf_CsmKey_CsmKey_SymmetricKey, CRYPTO_KE_MAC_KEY, key, sizeof( key ) );
      retVal |= Csm_KeySetValid( CsmConf_CsmKey_CsmKey_SymmetricKey );

      /* Generate the CMAC with the software implementation on the vHsm */
      retVal |= Csm_MacGenerate( CsmConf_CsmJob_CsmJob_MacGen_Key1, CRYPTO_OPERATIONMODE_SINGLECALL, data, sizeof( data ), mac, &length );
      retVal |= Csm_MacVerify( CsmConf_CsmJob_CsmJob_MacVer_Key1, CRYPTO_OPERATIONMODE_SINGLECALL, data, sizeof( data ), mac, sizeof( mac ) * 8u, &result );

      if (retVal != E_OK)
      {
         while (1u)
         {
            ;
         }
      }
   }
#endif /* FBLBM_ENABLE_SECURE_BOOT */
}

#if defined( FBLBM_AP_CALLOUT_RESET )
/***********************************************************************************************************************
 *  ApplFblBmReset
 **********************************************************************************************************************/
/*! \brief        Issue Reset
 **********************************************************************************************************************/
void ApplFblBmReset(void)
{
   /* Reset ECU */
   BrsHwSoftwareResetECU();
}
#endif /* FBLBM_AP_CALLOUT_RESET */

#if defined( FBLBM_AP_CALLOUT_CHECK_TARGET_VALIDITY )
/***********************************************************************************************************************
 *  ApplFblBmCheckTargetValidity
 **********************************************************************************************************************/
/*! \brief        Checks the validity of the target (Usually: Is the Application Validity Presence Pattern set)
 *  \param[in]    targetHandle Target handle (e.g. Bootloader, Application, Updater)
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
tFblResult ApplFblBmCheckTargetValidity(tFblBmHdrTargetHandle targetHandle)
{
   tFblResult result;
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
   vuint8 blockNo;
   tBlockDescriptor blockDescriptor;
   vuint8 device;
# else
   vuint8 applValidity;
# endif

   /* Check overall application validity for Application target */
   if (targetHandle == FBLBMHDR_TARGET_APPL)
   {
      result = kFblFailed;

# if defined( FBL_ENABLE_PRESENCE_PATTERN )
      /* Check if any PP for appl validity is set */
      blockNo = 0u;

      while ((blockNo < FblLbtGetBlockCount()) && (result != kFblOk))
      {
         if (kFblOk == FblLbtGetBlockDescriptorByNr(blockNo, &blockDescriptor))
         {
            if (kFblOk == FblMemGetDeviceByRange(blockDescriptor.blockStartAddress, blockDescriptor.blockLength, &device))
            {
#  if defined( kMioDeviceRam )
               /* Do not check the presence pattern for RAM */
               if (device != kMioDeviceRam)
#  endif
               {
                  result = FblNvPatternGet(&blockDescriptor, kFblNvPatternId_ApplValidity);
               }
            }
         }

         /* Prepare index for next loop */
         blockNo++;
      }
# else
      /* Read validity from NV-memory */
      if (ApplFblNvReadApplValidity(&applValidity) == kFblOk)
      {
         if (applValidity == kFblApplicationValid)
         {
            result = kFblOk;
         }
      }
# endif
   }
   else
   {
      /* For all other targets, no overall validity is necessary */
      result = kFblOk;
   }

   return result;
}
#endif /* FBLBM_AP_CALLOUT_CHECK_TARGET_VALIDITY */


#if defined( FBLBM_AP_CALLOUT_IS_VALIDBLOCK )
/***********************************************************************************************************************
 *  ApplFblBmIsValidBlock
 **********************************************************************************************************************/
/*! \brief        Checks the preconditions of a specific target
 *  \param[in]    targetHandle Target handle (e.g. Bootloader, Application)
 *  \param[in]    pLogicalBlock Pointer to current logical block
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmIsValidBlock(tFblBmHdrTargetHandle targetHandle,
   const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * pLogicalBlock)
{
   tFblResult result;
# if defined( FBL_ENABLE_PRESENCE_PATTERN ) || defined( FBLBM_ENABLE_STANDALONE_MODE )
   vuint8 device;
# endif /* FBL_ENABLE_PRESENCE_PATTERN || FBLBM_ENABLE_STANDALONE_MODE */
# if !defined( FBL_ENABLE_PRESENCE_PATTERN )
   vuint8 validityFlags[kEepSizeValidityFlags];
   vuint8 validityMask;
   vuint8 byteIdx;
# endif /* !FBL_ENABLE_PRESENCE_PATTERN */

# if (!defined( FBLBM_ENABLE_STANDALONE_MODE ) || defined( FBL_ENABLE_PRESENCE_PATTERN ))
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)targetHandle;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */
# endif /* ( !FBLBM_ENABLE_STANDALONE_MODE || FBL_ENABLE_PRESENCE_PATTERN ) */

   result = kFblFailed;

# if defined( FBLBM_ENABLE_STANDALONE_MODE ) && !defined( FBL_ENABLE_PRESENCE_PATTERN)
#   error "If presence pattern is disabled special handling must be configured for the FBL because          \
           validity flags are not available for the FBL."
   /* Perform presence pattern check only for FBL, use NV validity flags for other blocks */
   if (targetHandle == FBLBMHDR_TARGET_FBL)
# endif /* FBLBM_ENABLE_STANDALONE_MODE && !FBL_ENABLE_PRESENCE_PATTERN */
# if defined( FBL_ENABLE_PRESENCE_PATTERN ) || defined( FBLBM_ENABLE_STANDALONE_MODE )
   {
      /* Check the presence pattern value */
      if (kFblOk == FblMemGetDeviceByRange(pLogicalBlock->blockStartAddress, pLogicalBlock->blockLength, &device))
      {
#  if defined( kMioDeviceRam )
         /* Do not check the presence pattern for RAM */
         if (device != kMioDeviceRam)
#  endif /* kMioDeviceRam */
         {
            result = FblNvPatternGetByBlockDescriptor(pLogicalBlock, kFblNvPatternId_BlockValidity );
         }
      }
   }
# endif /* FBL_ENABLE_PRESENCE_PATTERN || FBLBM_ENABLE_STANDALONE_MODE */
# if !defined( FBL_ENABLE_PRESENCE_PATTERN )
#  if defined( FBLBM_ENABLE_STANDALONE_MODE )
   /* Check NV validity flags if block other than FBL is checked */
   else
#  endif /* FBLBM_ENABLE_STANDALONE_MODE */
   {
      /* Calculate index and mask for validity bit of logical block */
      byteIdx = (pLogicalBlock->blockNr >> 0x03u);
      validityMask = (vuint8)(0x01u << (pLogicalBlock->blockNr & 0x07u));

      /* Read validity information from non-volatile memory */
      if (ApplFblNvReadValidityFlags(validityFlags) == kFblOk)
      {
         if ((validityFlags[byteIdx] & validityMask) == 0u)
         {
            /* Block is valid */
            result = kFblOk;
         }
      }
   }
# endif /* !FBL_ENABLE_PRESENCE_PATTERN */

   return result;
}
#endif /* FBLBM_AP_CALLOUT_IS_VALIDBLOCK */

#if defined( FBLBM_CALLOUT_IS_OPTIONALBLOCK )
/***********************************************************************************************************************
 *  ApplFblBmIsOptionalBlock
 **********************************************************************************************************************/
/*! \brief        Callout when logical block is optional and not present
 *  \param[in]    targetHandle Target handle (e.g. Bootloader, Application)
 *  \param[in]    pLogicalBlock Pointer to current logical block
 **********************************************************************************************************************/
void ApplFblBmIsOptionalBlock(tFblBmHdrTargetHandle targetHandle,
   const V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 * pLogicalBlock)
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)targetHandle;
   (void)pLogicalBlock;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */
}
#endif /* FBLBM_CALLOUT_IS_OPTIONALBLOCK */

#if defined( FBLBM_AP_CALLOUT_START_SOFTWARE )
/***********************************************************************************************************************
 *  ApplFblBmStartSoftware
 **********************************************************************************************************************/
/*! \brief       This function is called to start a software (e.g. Bootloader)
 *  \details     Please note: The function will never return because control is handed over to the running software.
 *  \param[in]   bmHeader Pointer to the targets BM Header structure, which shall be started
 **********************************************************************************************************************/
void ApplFblBmStartSoftware(const V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 V_MEMRAM3 * bmHeader)
{
# if defined( BRS_INSTRUCTION_SET_THUMB )
   JSR(bmHeader->bmEntryAddress | 1u);  /* PRQA S 0305 */ /* MD_FblBmAp_0305 */
# else
   JSR(bmHeader->bmEntryAddress);  /* PRQA S 0305 */ /* MD_FblBmAp_0305 */
# endif

# if defined( FBL_ENABLE_SYSTEM_CHECK )
   /* Code should never be reached */
   while (1u)
   {
      ;
   }
# endif /* FBL_ENABLE_SYSTEM_CHECK */
}
#endif /* FBLBM_AP_CALLOUT_START_SOFTWARE* */

#if defined( FBLBM_ENABLE_SECURE_BOOT )
# if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY )
#  if defined( FBLBM_AP_CALLOUT_GET_KEYEMPTY )
/***********************************************************************************************************************
 *  ApplFblBmGetKeyEmpty
 **********************************************************************************************************************/
/*! \brief        Checks if now keys has been programmed so far
 *  \return       FBLBM_KEY_IS_AVAILABLE      if the keys are already programmed
                  FBLBM_KEY_IS_NOT_AVAILABLE  else
 **********************************************************************************************************************/
tFblBmKeyEmptyResult ApplFblBmGetKeyEmpty( void )
{
   /* TODO_CUSTOMER: implement check if key is available here. This can be done by querying the HSM/SHE (depending
    * on the used hardware) or e.g. by checking a pattern in the flash which indicates that the FBL has written the key
    * into the Crypto.
    */
   tFblBmKeyEmptyResult result;

#    error "No default implementation for this variant available."
   /* Per default assume that the key is available */
   result = FBLBM_KEY_IS_AVAILABLE;

   return result;
}
#  endif /* FBLBM_AP_CALLOUT_GET_KEYEMPTY */
# endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */

# if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
#  if defined( FBLBM_AP_CALLOUT_GET_FBL_CMACERASED )
/***********************************************************************************************************************
 *  ApplFblBmGetFblCmacErased
 **********************************************************************************************************************/
/*! \brief        Checks if MACs for the FBL has been programmed so far
 *  \return       FBLBM_MAC_IS_AVAILABLE     If the MACs of the FBL are already written
 *                FBLBM_MAC_IS_NOT_AVAILABLE Else. E.g. because the FBL is just flashed by a debugger
 **********************************************************************************************************************/
tFblBmMacEmptyResult ApplFblBmGetFblCmacErased( const tFblBmBlockInfo * fblBlockInfo )
{
   /* TODO_CUSTOMER: implement check if CMAC is available here. This can be done by checking the CMAC content or e.g.
    * by checking a pattern in the flash which indicates that the FBL CMAC was already written
    */

   tFblBmMacEmptyResult result;


#    if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)fblBlockInfo;
#    endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   if (ApplFblSbIsInitialStartup() == kFblOk)
   {
      /* This is the first startup, the SecureBootSegments needs to be updated */
      result = FBLBM_MAC_IS_NOT_AVAILABLE;
   }
   else
   {
      result = FBLBM_MAC_IS_AVAILABLE;
   }

   return result;
}
#  endif /* FBLBM_AP_CALLOUT_GET_FBL_CMACERASED */
# endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
#endif /* FBLBM_ENABLE_SECURE_BOOT */

#if defined( FBLBM_AP_CALLOUT_CHECKREPROGFLAG )
/***********************************************************************************************************************
 *  ApplFblBmCheckReprogFlag
 **********************************************************************************************************************/
/*! \brief        Checks if a reprogramming request flag is set.
 *  \return       Result of operation
 *                   kFblOk when reprogramming request flag is set
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmCheckReprogFlag( void )
{
   tFblResult result = kFblFailed;
# if !defined( FBL_ENABLE_FBL_START )
   vuint8 progReqFlag = 0u;
# endif

# if defined( FBL_ENABLE_FBL_START )
   if (FblBmChkFblStartMagicFlag())
   {
      /* FblStart magic flag is set, do not clear flag as the Bootloader requires it as well */
      result = kFblOk;
   }
# else
   /* Check the reprogramming request flag */
   if (ApplFblNvReadProgReqFlag(&progReqFlag) == kFblOk)
   {
      if (progReqFlag == kEepFblReprogram)
      {
         /* UDS-Reprogramming flag is set, do not clear flag as the Bootloader requires it as well */
         result = kFblOk;
      }
#  if defined( FBL_ENABLE_XCP )
      else if (progReqFlag == kEepFblXcpProgram)
      {
         /* XCP-Reprogramming flag is set, do not clear flag as the Bootloader requires it as well */
         result = kFblOk;
      }
#  endif
#  if defined( FBL_ENABLE_OTA )
      else if (progReqFlag == kEepFblOtaReprogram)
      {
         /* OTA-Reprogramming flag is set, do not clear flag as the Bootloader requires it as well */
         result = kFblOk;
      }
#  endif
      else
      {
         /* Nothing to do */
      }
   }
# endif /* FBL_ENABLE_FBL_START */

# if defined( FBLBM_MAIN_ENABLE_MAGICFLAG ) &&  \
     defined( FBLBM_ENABLE_SECURE_BOOT ) &&     \
     defined( FBLBM_MAIN_ENABLE_HARDWARE_SWAP )
   if (FblBmChkSBUpdateMagicFlag())
   {
      /* Start FBL in case of secure boot update */
      result = kFblOk;
   }
# endif

   return result;
}
#endif /* FBLBM_AP_CALLOUT_CHECKREPROGFLAG */

#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT )
/***********************************************************************************************************************
 *  ApplFblBmSearchUpdaterHeaderInit
 **********************************************************************************************************************/
/*! \brief        Prepare search for updater BmHeader location
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmSearchUpdaterHeaderInit(void)
{
   g_ApplFblBmSearchUpdaterHeaderIndex = 0u;
   return kFblOk;
}
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT */

# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS )
/***********************************************************************************************************************
 *  ApplFblBmSearchUpdaterHeaderAddress
 **********************************************************************************************************************/
/*! \brief        Get address of possible location of a BmHeader for the Failsafe Updater
 *  \param[out]   headerAddress  Address where the BmHeader could possible be located
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmSearchUpdaterHeaderAddress(vuint32 * headerAddress)
{
   vuint32 offset = 0u;
   (* headerAddress) = FlashBlock[g_ApplFblBmSearchUpdaterHeaderIndex].begin + offset;
   return kFblOk;
}
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS */

# if defined( FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT )
/***********************************************************************************************************************
 *  ApplFblBmSearchUpdaterHeaderNext
 **********************************************************************************************************************/
/*! \brief        Get (next) possible location of a BmHeader for the Failsafe Updater
 *  \return       Result of operation
 *                   kFblOk when operation succeeded
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblBmSearchUpdaterHeaderNext(void)
{
   tFblResult result;

   g_ApplFblBmSearchUpdaterHeaderIndex++;

   if (g_ApplFblBmSearchUpdaterHeaderIndex < kNrOfFlashBlock)
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}
# endif /* FBLBM_AP_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT */
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */

#if defined( FBLBM_AP_CALLOUT_FATAL_ERROR )
/***********************************************************************************************************************
 *  ApplFblBmFatalError
 **********************************************************************************************************************/
/*! \brief       This function is called in case no valid starting software was found
 *  \details     Provide here some final tasks which shall be executed
 **********************************************************************************************************************/
void ApplFblBmFatalError(tFblBmError error)
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)error;
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

# if defined( FBL_ENABLE_SYSTEM_CHECK )
   /* Code should never be reached */
   while (1u)
   {
      ;
   }
# endif /* FBL_ENABLE_SYSTEM_CHECK */
}
#endif /* FBLBM_AP_CALLOUT_FATAL_ERROR */

/*-- Other callout functions -----------------------------------------------------------------------------------------*/

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
# if defined( FBL_ENABLE_ASSERTION )
/***********************************************************************************************************************
 *  ApplFblFatalError
 **********************************************************************************************************************/
/*! \brief       Will be called in case of an urecoverable error
 **********************************************************************************************************************/
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) )
{
   /* Change this variable in debugger in order to return to caller */
   volatile vuint8 stayInWhile = 1u;

#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorCode;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   while (0u != stayInWhile)
   {
      FblLookForWatchdogVoid();
   }
}
# endif /* FBL_ENABLE_ASSERTION */

# if (DET_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  ApplFbl_DetEntryHandler
 **********************************************************************************************************************/
/*! \brief       Called by DET module to check if a DET error is intended bootloader behavior or not.
 *  \param[in]   ModuleId Code number of the encountered assertion
 *  \param[in]   InstanceId Name of the affected module (Only if extended info is enabled)
 *  \param[in]   ApiId Line number where the assertion occurred (Only if extended info is enabled)
 *  \param[in]   ErrorId Line number where the assertion occurred (Only if extended info is enabled)
 *  \return      Report if error should be handed over to DET or not
 **********************************************************************************************************************/
#  if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
#  else
FUNC(boolean, DET_APPL_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
#  endif /* DET_AR_RELEASE_ */
{
#  if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
   Std_ReturnType result = E_OK;
   /* Use result value of E_NOT_OK to ignore the DET */
#  else
   boolean result = FALSE;
   /* Use result value of TRUE to ignore the DET */
#  endif /* DET_AR_RELEASE_ */

#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)ModuleId;
   (void)InstanceId;
   (void)ApiId;
   (void)ErrorId;
#  endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   return result;
}
# endif /* DET_ENABLED == STD_ON */

# if defined( FBL_MIO_ENABLE_HOOKS )
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
   Std_ReturnType retVal;

#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)device;
   (void)function;
#  endif
   /* TODO_CUSTOMER: Adapt this example implementation to project-specific needs/requirements */
   /* Suspend vHSM operations in data flash */
   opMode = CRYPTO_30_VHSM_DATAFLASH_START;
   retVal = Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);
   /* Suspend vHSM operations in code flash -> send it to RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_START;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}

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
   Std_ReturnType retVal;
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)device;
   (void)function;
#  endif
   /* TODO_CUSTOMER: Adapt this example implementation to project-specific needs/requirements */
   /* Get vHSM back from RAM loop */
   opMode = CRYPTO_30_VHSM_CODEFLASH_STOP;
   retVal = Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);
   /* Give vHSM access to data flash operations */
   opMode = CRYPTO_30_VHSM_DATAFLASH_STOP;
   retVal |= Csm_KeyElementSet(CsmConf_CsmKey_CsmKey_vHsm_Hardware, CRYPTO_KE_CUSTOM_VHSM_FLASH_OPERATION, &opMode, 1u);

   /* Simulate DET functionality in case of any error */
   assertFblUser(retVal == E_OK, kFblSysAssertDet);
}
# endif /* FBL_MIO_ENABLE_HOOKS */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

#define FBLBMAP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* module specific MISRA deviations:

   MD_FblBmAp_0305:
      Reason:     Boot manager needs to jump to a memory location to start a target/software.
      Risk:       Unintended jump to wrong memory location.
      Prevention: No prevention possible, address is defined by the corresponding target.

   MD_FblBmAp_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation-defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis. The correctness of the respective implementation is verified by runtime tests.

*/

/***********************************************************************************************************************
 *  END OF FILE: BM_AP.C
 **********************************************************************************************************************/
