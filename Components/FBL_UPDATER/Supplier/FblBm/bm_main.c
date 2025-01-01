/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Main module of BM
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
 *  04.00.00   2019-10-10  vistmo  FBL-390          Adapt main function interface for vBaseEnv
 *  04.00.01   2019-11-05  visrie  ESCAN00104616    No changes
 *                                 ESCAN00104790    No changes
 *  05.00.00   2019-12-04  visrie  FBL-456          Added support for new FblLibSecBoot interface
 *                                 ESCAN00104644    Initialize DET module
 *                                 ESCAN00105176    Added support for VTT use case
 *  05.01.00   2020-01-13  visrie  ESCAN00104481    No changes
 *                                 FBL-953          No changes
 *  05.02.00   2020-02-28  vistbe  FBL-949          No changes
 *  06.00.00   2020-04-08  visrie  FBL-1016         Support of EcuM functions
 *  06.00.01   2020-04-08  visrie  ESCAN00106837    Compiler error: wrong argument type at FblSb_VerifySegments
 *  06.00.02   2020-10-28  visrcn  ESCAN00107189    Compiler error: Wrong definition for FblMain function
 *  06.01.00   2021-08-11  visrie  FBL-3394         Move default implementation of CheckReprogFlag into FblBm_Ap
 *                                                  Added/adapted MemMap sections
 *  06.02.00   2022-02-04  visrie  FBL-4602         Added support of new SecBoot API (VerifyHeaderRom)
 *  06.02.01   2022-04-06  vismix  ESCAN00111029    [MCMP only] Compiler error: Label FblDiagInitPowerOn is not defined
 *  06.03.00   2022-04-08  visrie  FBL-4126         No changes
 *  06.04.00   2022-04-11  vishor  FBL-4822         Add support for new MagicFlag value and Swap API
 *  06.04.01   2022-04-28  vismix  ESCAN00111741    SecureBoot for Bootloader not checked during reprogramming
 *                                                   request started by application
 *  06.05.00   2022-05-06  vishor  FBL-5148         Encapsulate call of FblInterruptDisable
 *  06.06.00   2022-07-13  vismix  FBL-5391         Add callout for missing optional dependency
 *  06.06.01   2022-08-04  visjns  ESCAN00112070    FblSb_VerifySegments is needlessly called twice.
 *  06.07.00   2022-11-07  vishor  FBL-4932         Adjust FBL LBT Check
 *  06.08.00   2022-11-30  visrie  FBL-6065         No changes
 **********************************************************************************************************************/

#define BM_MAIN_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

#include "fbl_main_types.h"
#include "bm_main.h"
#include "fbl_fsm.h"

#if defined( FBLBM_ENABLE_SECURE_BOOT )
# include "fbl_secboot.h"
#endif

#include "EcuM.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLBM_MAIN_VERSION != 0x0608u ) || \
    ( FBLBM_MAIN_RELEASE_VERSION != 0x00u )
# error "Error in BM_MAIN.C: Source and Header file are inconsistent!"
#endif

/* Interface version compatibility check: General callouts */
#if defined( FBLBM_AP_API_VERSION_MAJOR ) && \
    defined( FBLBM_AP_API_VERSION_MINOR )
#else
# error "Error in BM_MAIN.C: Interface version requirements not defined!"
#endif

#if ( FBLBM_AP_API_VERSION_MAJOR != FBLBM_API_VERSION_MAJOR ) || \
    ( FBLBM_AP_API_VERSION_MINOR > FBLBM_API_VERSION_MINOR )
# error "Error in BM_MAIN.C: Interface version compatibility check failed!"
#endif

/* Interface version compatibility check: platform-specific callouts */
#if defined( FBLBM_AP_HW_API_VERSION_MAJOR )
# if defined( FBLBM_AP_HW_API_VERSION_MINOR )
# else
#  error "Error in BM_MAIN.C: Interface version requirements not defined!"
# endif

# if ( FBLBM_AP_HW_API_VERSION_MAJOR != FBLBM_API_VERSION_MAJOR ) || \
     ( FBLBM_AP_HW_API_VERSION_MINOR > FBLBM_API_VERSION_MINOR )
#  error "Error in BM_MAIN.C: Interface version compatibility check failed!"
# endif
#endif

/* Interface version compatibility check: OEM-specific callouts */
#if defined( FBLBM_AP_OEM_API_VERSION_MAJOR )
# if defined( FBLBM_AP_OEM_API_VERSION_MINOR )
# else
#  error "Error in BM_MAIN.C: Interface version requirements not defined!"
# endif

# if ( FBLBM_AP_OEM_API_VERSION_MAJOR != FBLBM_API_VERSION_MAJOR ) || \
    ( FBLBM_AP_OEM_API_VERSION_MINOR > FBLBM_API_VERSION_MINOR )
#  error "Error in BM_MAIN.C: Interface version compatibility check failed!"
# endif
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( _MICROSOFT_C_VTT_ )
# define FBLBM_MAIN_ENABLE_VTT_USECASE
#endif /* _MICROSOFT_C_VTT_ */

/** Helper macro for filling state structures (enhance readability) */
#define FBLBM_SIZE_AND_ARRAY(array)   FBLBM_ARRAY_SIZE(array), (array)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if defined( FBLBM_ENABLE_SECURE_BOOT )
# if (!defined( FBLBM_DISABLE_USE_VERIFY_HEADER_ROM ) && \
     (  ( FBLSB_API_REFERENCE_VERSION_MAJOR > 0x02u ) || \
       (( FBLSB_API_REFERENCE_VERSION_MAJOR == 0x02u ) && ( FBLSB_API_REFERENCE_VERSION_MINOR >= 0x02u ))))
#  define FBLBM_ENABLE_USE_VERIFY_HEADER_ROM
# endif
#endif /* FBLBM_ENABLE_SECURE_BOOT */

/***********************************************************************************************************************
 *  TYPEDEFS, ENUMS
 **********************************************************************************************************************/

/** Bootmanager States */ /* PRQA S 3205 TAG_FblBmMain_3205_1 */ /* MD_FblBmMain_3205_UnusedIdentifiers */
typedef enum
{
   FBLBM_STATE_POWER_ON,                              /*  0 */
   FBLBM_STATE_INIT,                                  /*  1 */
   FBLBM_STATE_CHECK_FBL_VALIDITY,                    /*  2 */
   FBLBM_STATE_FAILSAFE_UPDATER_ENABLED,              /*  3 */
   FBLBM_STATE_FAILSAFE_UPDATER_SEARCH_INIT,          /*  4 */
   FBLBM_STATE_FAILSAFE_UPDATER_CHECK,                /*  5 */
   FBLBM_STATE_FAILSAFE_UPDATER_SEARCH_NEXT,          /*  6 */
   FBLBM_STATE_CALL_FAILSAFE_UPDATER,                 /*  7 */
   FBLBM_STATE_SECURE_BOOT_ENABLED,                   /*  8 */
   FBLBM_STATE_CHECK_KEY_AVAILABILITY,                /*  9 */
   FBLBM_STATE_CALL_FBL_INIT_KEY,                     /* 10 */
   FBLBM_STATE_INIT_FBL_MAC_ENABLED,                  /* 11 */
   FBLBM_STATE_CHECK_FBL_MAC_ERASED,                  /* 12 */
   FBLBM_STATE_CALL_FBL_INIT_CMAC,                    /* 13 */
   FBLBM_STATE_STAY_IN_BOOT_ENABLED,                  /* 14 */
   FBLBM_STATE_CHECK_APPL_START_FLAG,                 /* 15 */
   FBLBM_STATE_CHECK_FBL_LBT,                         /* 16 */
   FBLBM_STATE_CHECK_REPROG_FLAG,                     /* 17 */
   FBLBM_STATE_REPROG_LBT_ENABLED,                    /* 18 */
   FBLBM_STATE_CHECK_REPROG_LBT,                      /* 19 */
   FBLBM_STATE_TARGET_LIST_INIT,                      /* 20 */
   FBLBM_STATE_TARGET_CHECK,                          /* 21 */
   FBLBM_STATE_TARGET_LIST_NEXT,                      /* 22 */
   FBLBM_STATE_CALL_TARGET,                           /* 23 */
   FBLBM_STATE_CHECK_FBL_VERIFICATION,                /* 24 */
   FBLBM_STATE_CHECK_FBL_VERIFICATION_STAY_IN_BOOT,   /* 25 */
   FBLBM_STATE_CALL_FBL,                              /* 26 */
   FBLBM_STATE_CALL_FBL_STAY_IN_BOOT,                 /* 27 */
   FBLBM_STATE_CHECK_FBL_SEGMENTS,                    /* 28 */
   FBLBM_STATE_FAIL                                   /* 29 */
} tFblBmState;

/** Events for BM FSM: Only one Event "continue" */
typedef enum
{
   FBLBM_EVENT_CONTINUE = kFblFsmDefaultEvent_Count /* 4 */
} tFblBmEvent;
/* PRQA L:TAG_FblBmMain_3205_1 */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLBM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void FblBmDeinit(void);

/* Event Handlers */
static tFblFsmGuard FblBmState_PowerOn_Entry                (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
static tFblFsmGuard FblBmState_Init_Entry                   (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
static tFblFsmGuard FblBmState_CallFailsafeUpdater_Entry    (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY)
static tFblFsmGuard FblBmState_CallFblInitKey_Entry         (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */
#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
static tFblFsmGuard FblBmState_CallTarget_Entry             (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_BOOTTARGETLIST_SIZE > 0u */
static tFblFsmGuard FblBmState_CallFbl_Entry                (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
static tFblFsmGuard FblBmState_CallFblStayInBoot_Entry      (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */
#if defined( FBLBM_ENABLE_SECURE_BOOT )
static tFblFsmGuard FblBmState_CheckFblSegments             (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_ENABLE_SECURE_BOOT */
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
static tFblFsmGuard FblBmState_CallFblInitCmac_Entry        (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
static tFblFsmGuard FblBmState_Fail_Entry                   (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
/* Guards */
static tFblFsmGuard FblBmState_CheckFblValidity             (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
static tFblFsmGuard FblBmState_FailsafeUpdaterSearchInit    (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
static tFblFsmGuard FblBmState_FailsafeUpdaterCheck         (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
static tFblFsmGuard FblBmState_FailsafeUpdaterSearchNext    (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */
static tFblFsmGuard FblBmState_CheckKeyAvailability         (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
static tFblFsmGuard FblBmState_CheckFblMacErased            (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC*/
#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
static tFblFsmGuard FblBmState_CheckApplStartFlag           (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */
static tFblFsmGuard FblBmState_CheckReprogFlag              (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
static tFblFsmGuard FblBmState_CheckFblLbt                  (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
static tFblFsmGuard FblBmState_CheckReprogLbt               (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */
#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
static tFblFsmGuard FblBmState_TargetListInit               (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
static tFblFsmGuard FblBmState_TargetCheck                  (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
static tFblFsmGuard FblBmState_TargetListNext               (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);
#endif /* FBLBM_BOOTTARGETLIST_SIZE > 0u */
static tFblFsmGuard FblBmState_CheckFblVerification         (tFblFsmContextPtr const pFsmContext, tFblFsmEvent event);

#define FBLBM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLBM_HEADER_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/** BM header data for access from application software */
V_MEMROM0 V_MEMROM1 tFblBmHeader V_MEMROM2 FblBmHeader = /* PRQA S 1514 */ /* MD_FblBmMain_1514_BmHeader */
{
   FBLBM_HEADER_MAGIC_VALUE,
   FBLBM_HEADER_MAJOR_VERSION,
   FBLBM_HEADER_MINOR_VERSION,
   FBL_HEADER_ADDRESS,
#if defined( FBLBM_MAIN_ENABLE_FBL_START )
   (tFblStrtFct)FblStart,
#else
   (tFblStrtFct)V_NULL,
#endif
#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
   (tApplStrtFct)ApplStart,
#else
   (tApplStrtFct)V_NULL,
#endif
   0u, /* Checksum is not yet used */
   FBLBM_HEADER_END_MAGIC_VALUE
};
#define FBLBM_HEADER_STOP_SEC_CONST
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define FBLBM_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/** Block Info for the FBL block */
V_MEMRAM0 static V_MEMRAM1 tFblBmBlockInfo V_MEMRAM2 fblBmBlockInfo;

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
/** Local copy of FBL header structure */
V_MEMRAM0 static V_MEMRAM1 tFblHeader V_MEMRAM2 fblBmFblHeader; /* PRQA S 3218 */ /* MD_FBL_3218_FileScopeStatic */
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

/** Context Structure of the Finite State Machine (FSM) */
V_MEMRAM0 static V_MEMRAM1 tFblFsmContext V_MEMRAM2 g_BmFsmContext; /* PRQA S 3218 */ /* MD_FBL_3218_FileScopeStatic */

#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
/** Entry Point for Failsafe Updater */
V_MEMRAM0 static V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 g_BmFailsafeUpdaterBmHeader;
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */

#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
/** Counter for search for valid target */
V_MEMRAM0 static V_MEMRAM1 vuintx V_MEMRAM2 g_BmTargetListIndex;
/** Entry Point for target */
V_MEMRAM0 static V_MEMRAM1 tFblBmHdrHeader V_MEMRAM2 g_BmTargetBmHeader;
#endif /* FBLBM_BOOTTARGETLIST_SIZE > 0u */

/** Error Code */
V_MEMRAM0 static V_MEMRAM1 tFblBmError V_MEMRAM2 g_BmError;

#define FBLBM_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***** State machine *****/

#define FBLBM_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/** State PowerOn (0) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_PowerOn[] = {
   /* Initialize Memory and go directly to next step: Init
    */
   FBL_FSM_TRIGGER_ENTRY(FblBmState_PowerOn_Entry),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_INIT)
};

/** State Init (1) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_Init[] = {
   /* Call Init Routines
    * GOTO next step on continue-event
    */
   FBL_FSM_TRIGGER_ENTRY(FblBmState_Init_Entry),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_CHECK_FBL_VALIDITY)
};

/** State CheckFblValidity (2) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckFblValidity[] = {
   /* IF FBL is valid goto state CheckSecureBootEnabled
    * ELSE GOTO UpdaterEnabled
    */
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckFblValidity, FBLBM_STATE_SECURE_BOOT_ENABLED),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAILSAFE_UPDATER_ENABLED)
};

/** State FailsafeUpdaterEnabled (3) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_FailsafeUpdaterEnabled[] = {
   /* Configuration switch: If Updater support is enabled search for updater.
    * This state is reached when no valid FBL is available. This can only happen
    * if a FBL-update process is interrupted.
    */
#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_FAILSAFE_UPDATER_SEARCH_INIT)
#else /* FBLBM_ENABLE_UPDATER_FAILSAFE */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_FAIL)
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */
};

/** State FailsafeUpdaterSearchInit (4) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_FailsafeUpdaterSearchInit[] = {
#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_FailsafeUpdaterSearchInit, FBLBM_STATE_FAILSAFE_UPDATER_CHECK), /*  */
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State FailsafeUpdaterCheck (5) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_FailsafeUpdaterCheck[] = {
   /* If  a update is aborted e.g. due to power loss, the FBL may be already erased.
    * In this case: Search for a valid Updater and call it
    */
#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_FailsafeUpdaterCheck, FBLBM_STATE_CALL_FAILSAFE_UPDATER),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAILSAFE_UPDATER_SEARCH_NEXT),
#else /* FBLBM_ENABLE_UPDATER_FAILSAFE */
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */
};

/** State FailsafeUpdaterSearchNext (6) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_FailsafeUpdaterSearchNext[] = {
#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_FailsafeUpdaterSearchNext, FBLBM_STATE_FAILSAFE_UPDATER_CHECK),
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State CallFailsafeUpdater (7) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CallFailsafeUpdater[] = {
   /* Start the Updater
    */
#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
   FBL_FSM_TRIGGER_ENTRY(FblBmState_CallFailsafeUpdater_Entry),
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State SecureBootEnabled (8) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_SecureBootEnabled[] = {
    /* Configuration switch:
     * IF Secure Boot is enabled GOTO CheckKeyAvailability
     * ELSE skip this step
     */
#if defined( FBLBM_ENABLE_SECURE_BOOT )
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_CHECK_KEY_AVAILABILITY)
#else
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_CHECK_FBL_SEGMENTS)
#endif
};

/** State CheckKeyAvailability (9) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckKeyAvailability[] = {
    /* Check if a Key is already available. If not, FBL shall be called to initialize the key.
     */
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckKeyAvailability, FBLBM_STATE_INIT_FBL_MAC_ENABLED),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_CALL_FBL_INIT_KEY)
};

/** State CallFblInitKey (10) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CallFblInitKey[] = {
    /* Call FBL to initialize key */
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY)
   FBL_FSM_TRIGGER_ENTRY(FblBmState_CallFblInitKey_Entry),
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State InitFblCmacEnabled (11) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_InitFblMacEnabled[] = {
    /* Configuration switch:
     * IF Secure Boot is enabled GOTO CheckFblMacErased
     * ELSE skip this step
     */
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_CHECK_FBL_MAC_ERASED)
#else /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_CHECK_FBL_SEGMENTS)
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
};

/** State CheckFblMacErased (12) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckFblMacErased[] = {
    /* Check if a CMAC is available. If not, the FBL is probably written with a debugger and the CMAC area is in erased state. FBL shall be called to initialize the CMAC.
     */
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckFblMacErased, FBLBM_STATE_CALL_FBL_INIT_CMAC),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_CHECK_FBL_SEGMENTS)
#else /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_FAIL)
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */
};

/** State CallFblInitCmac (13) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CallFblInitCmac[] = {
   /* Call FBL and set Magicflag to make it init its CMAC. Shall be used only for debugging.
    */
#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
   FBL_FSM_TRIGGER_ENTRY(FblBmState_CallFblInitCmac_Entry),
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC*/
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State StayInBootEnabled (14) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_StayInBootEnabled[] = {
   /* Configuration Switch: If Stay in Boot is enabled, ApplStartMagicFlag must be evaluated to decide
    * if the application shall be started. Otherwise this can be skipped.
    */
#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT)
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_CHECK_APPL_START_FLAG)
#else /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_CHECK_FBL_LBT)
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */
 };

/** State CheckApplStartFlag (15) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckApplStartFlag[] = {
   /* Evaluate ApplStartMagicFlag to decide if the application shall be started.
    */
#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckApplStartFlag, FBLBM_STATE_CHECK_FBL_LBT),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_CHECK_FBL_VERIFICATION_STAY_IN_BOOT)
#else /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_FAIL)
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */
};

/** State CheckFblLbt (16) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckFblLbt[] = {
   /* Check validity and verification of FBL-LBT
    * If it can't be verified/validated, something went wrong: The FBL (which contains the FBL-LBT) is valid but
    * the LBT is not verified/valid => Fail
    */
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckFblLbt, FBLBM_STATE_REPROG_LBT_ENABLED),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State CheckReprogFlag (17) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckReprogFlag[] = {
   /* Check if Reprogramming Flag is set. If so, check if FBL is valid.
    */
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckReprogFlag, FBLBM_STATE_CHECK_FBL_VERIFICATION),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_STAY_IN_BOOT_ENABLED)
};

/** State ReprogLbtEnable (18) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_ReprogLbtEnabled[] = {
   /* Configuration Switch: If a reprogrammable LBT is used...
    */
#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
   FBL_FSM_TRIGGER_UNCONDITIONAL( FBLBM_STATE_CHECK_REPROG_LBT),
#else /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */
   FBL_FSM_TRIGGER_UNCONDITIONAL( FBLBM_STATE_TARGET_LIST_INIT)
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */
};

/** State CheckReprogLbt (19) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckReprogLbt[] = {
   /* Check validity/verification of the reprogrammable LBT. If it is not usable, the application can not be found.
    * Therefore the FBL is called as a fallback.
    */
#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckReprogLbt, FBLBM_STATE_TARGET_LIST_INIT),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_CHECK_FBL_VERIFICATION)
#else /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_FAIL)
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */
};

/** State TargetListInit (20) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_TargetListInit[] = {
   /* Prepare searching the target list
    */
#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_TargetListInit, FBLBM_STATE_TARGET_CHECK),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
#else /* FBLBM_BOOTTARGETLIST_SIZE == 0u */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_CHECK_FBL_VERIFICATION)
#endif /* FBLBM_BOOTTARGETLIST_SIZE == 0u */
};

/** State TargetCheck (21) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_TargetCheck[] = {
   /* Check one entry of the target list. If all conditions match, call the target.
    * Otherwise go to "Next"
    */
#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_TargetCheck, FBLBM_STATE_CALL_TARGET),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_TARGET_LIST_NEXT)
#else /* FBLBM_BOOTTARGETLIST_SIZE == 0u */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_FAIL)
#endif /* FBLBM_BOOTTARGETLIST_SIZE == 0u */
};

/** State TargetListNext (22) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_TargetListNext[] = {
   /* Get next element form target list
    */
#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_TargetListNext, FBLBM_STATE_TARGET_CHECK),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_CHECK_FBL_VERIFICATION)
#else /* FBLBM_BOOTTARGETLIST_SIZE == 0u */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_FAIL)
#endif /* FBLBM_BOOTTARGETLIST_SIZE == 0u */
};

/** State CallTarget (23) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CallTarget[] = {
   /* Start the application/updater
    */
#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
   FBL_FSM_TRIGGER_ENTRY(FblBmState_CallTarget_Entry),
#endif /* FBLBM_BOOTTARGETLIST_SIZE > 0u */
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State CheckFblVerification (24) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckFblVerification[] = {
   /* If verification (CMAC) of FBL is successful, call it. Otherwise go to Fail state
    */
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckFblVerification, FBLBM_STATE_CALL_FBL),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State CheckFblVerificationStayInBoot (25) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckFblVerificationStayInBoot[] = {
   /* If verification (CMAC) of FBL is successful, call it. Otherwise go to Fail state
    */
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckFblVerification, FBLBM_STATE_CALL_FBL_STAY_IN_BOOT),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State CallFbl (26) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CallFbl[] = {
   /* Start FBL */
   FBL_FSM_TRIGGER_ENTRY(FblBmState_CallFbl_Entry),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State CallFblStayInBoot (27) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CallFblStayInBoot[] = {
   /* Start FBL (StayInBoot)*/
#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT)
   FBL_FSM_TRIGGER_ENTRY(FblBmState_CallFblStayInBoot_Entry),
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
};

/** State CheckFblSegments (28) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_CheckFblSegments[] = {
   /* Check if FBL-Segments are valid.
    */
#if defined( FBLBM_ENABLE_SECURE_BOOT )
   FBL_FSM_TRIGGER_TRANSITION_ACTION(FBLBM_EVENT_CONTINUE, FblBmState_CheckFblSegments, FBLBM_STATE_CHECK_REPROG_FLAG),
   FBL_FSM_TRIGGER_TRANSITION(FBLBM_EVENT_CONTINUE, FBLBM_STATE_FAIL)
#else /* FBLBM_ENABLE_SECURE_BOOT */
   FBL_FSM_TRIGGER_UNCONDITIONAL(FBLBM_STATE_CHECK_REPROG_FLAG)
#endif /* FBLBM_ENABLE_SECURE_BOOT */
};

/** State Fail (29) */
V_MEMROM0 static V_MEMROM1 tFblFsmEventEntry V_MEMROM2 g_BmState_Fail[] = {
   /* Fail State
    */
   FBL_FSM_TRIGGER_ENTRY(FblBmState_Fail_Entry)
};

/** List of all States */
V_MEMROM0 static V_MEMROM1 tFblFsmStateDefinition V_MEMROM2 bmFsmStates[] = /* PRQA S 3218 */ /* MD_FBL_3218_FileScopeStatic */
{
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_PowerOn) },                          /*  0 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_Init) },                             /*  1 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckFblValidity) },                 /*  2 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_FailsafeUpdaterEnabled) },           /*  3 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_FailsafeUpdaterSearchInit) },        /*  4 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_FailsafeUpdaterCheck) },             /*  5 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_FailsafeUpdaterSearchNext) },        /*  6 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CallFailsafeUpdater) },              /*  7 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_SecureBootEnabled) },                /*  8 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckKeyAvailability) },             /*  9 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CallFblInitKey) },                   /* 10 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_InitFblMacEnabled) },                /* 11 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckFblMacErased) },                /* 12 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CallFblInitCmac) },                  /* 13 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_StayInBootEnabled) },                /* 14 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckApplStartFlag) },               /* 15 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckFblLbt) },                      /* 16 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckReprogFlag) },                  /* 17 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_ReprogLbtEnabled) },                 /* 18 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckReprogLbt) },                   /* 19 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_TargetListInit) },                   /* 20 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_TargetCheck) },                      /* 21 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_TargetListNext) },                   /* 22 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CallTarget) },                       /* 23 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckFblVerification) },             /* 24 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckFblVerificationStayInBoot) },   /* 25 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CallFbl) },                          /* 26 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CallFblStayInBoot) },                /* 27 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_CheckFblSegments) },                 /* 28 */
   { FBL_FSM_DEFAULT_STATE, FBLBM_SIZE_AND_ARRAY(g_BmState_Fail) }                              /* 29 */
};
#define FBLBM_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#define FBLBM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FblBmState_PowerOn_Entry
 *********************************************************************************************************************/
/*! \brief        Called directly on PowerOn
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_PowerOn_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   g_BmError = FBLBM_ERROR_NO_ERROR;

   FBLBM_CALLOUT_POWER_ON_PRE_HW();
   FBLBM_CALLOUT_POWER_ON_PRE_OEM();
   FBLBM_CALLOUT_POWER_ON_PRE();

#if !defined( FBLBM_MAIN_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON )
   /* Disable global interrupt handling */
   FblInterruptDisable(); /* PRQA S 1006 */ /* MD_FblBmMain_1006 */
#endif /* FBLBM_MAIN_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON */

#if defined( FBLBM_MAIN_ENABLE_VTT_USECASE )
#else
   /* Check if bootmanager header address is correctly configured in generation tool */
   /* PRQA S 0306 1 */ /* MD_FblBmMain_0306_FblBmHeader */
   assertFblGen(FblBmHeaderLocal == FblBmHeaderTable, kFblSysAssertParameterOutOfRange);
#endif /* FBL_MAIN_ENABLE_VTT_USECASE */

   /* Power on initialization of core modules */
   ClrWDInit();

   MemDriver_InitPowerOn();

#if !defined( FBLBM_ENABLE_STANDALONE_MODE )
   /* Initialize states of diagnostic layer */
   FblDiagInitPowerOn();
#endif

   /* Initialize intermediate access layer for LBT */
   FblLbtInitPowerOn();

#if defined( FBLBM_MAIN_ENABLE_HARDWARE_SWAP )
   /* Initialize hardware swap module */
   FblSwapInitPowerOn();
#endif

   /* Initialization callout */
   FBLBM_CALLOUT_POWER_ON_POST_HW();
   FBLBM_CALLOUT_POWER_ON_POST_OEM();
   FBLBM_CALLOUT_POWER_ON_POST();

   return kFblFsmGuard_True;
}

/**********************************************************************************************************************
 *  FblBmState_Init_Entry
 *********************************************************************************************************************/
/*! \brief        Called as a 2nd step after PowerOn
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_Init_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   /* Early initialization callout */
   FBLBM_CALLOUT_INIT_PRE_HW();
   FBLBM_CALLOUT_INIT_PRE_OEM();
   FBLBM_CALLOUT_INIT_PRE();

   /* Initialize and activate watchdog */
   FblInitWatchdog();
   /* Initialize Timer */
   FblTimerInit();

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
   EcuM_StartupTwo();
#else
   /* EcuM_StartupTwo is called by Bootloader
    * Modules which should be already available in the Bootmanager should be placed in INIT_ZERO or INIT_ONE phase
    */
#endif

#if defined( FBLBM_ENABLE_SECURE_BOOT )
   /* Initializes SecureBoot */
   FblSb_Init();
#endif /* FBLBM_ENABLE_SECURE_BOOT */

#if defined( FBLBM_MAIN_ENABLE_HARDWARE_SWAP )
   /* Execute the flash partition swap */
   (void)FblSwapActivate();
#endif /* FBLBM_MAIN_ENABLE_HARDWARE_SWAP */

   /* Late initialization callout */
   FBLBM_CALLOUT_INIT_POST_HW();
   FBLBM_CALLOUT_INIT_POST_OEM();
   FBLBM_CALLOUT_INIT_POST();

   return kFblFsmGuard_True;
}

#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
/**********************************************************************************************************************
 *  FblBmState_CallFailsafeUpdater_Entry
 *********************************************************************************************************************/
/*! \brief        Call a failsafe updater
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CallFailsafeUpdater_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   /* Disable Timer etc. */
   FblBmDeinit(); /* PRQA S 2987 */ /* MD_FBL_2987_RedundantCode */

   /* Call Failsafe Updater */
   FBLBM_CALLOUT_CALL_FAILSAFE_UPDATER(&g_BmFailsafeUpdaterBmHeader);

   /* This code is never reached */
   return kFblFsmGuard_True;
}
#endif /*  FBLBM_ENABLE_UPDATER_FAILSAFE */

#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY )
/**********************************************************************************************************************
 *  FblBmState_CallFblInitKey_Entry
 *********************************************************************************************************************/
/*! \brief        Call the FBL and set a magic flag to direct him to init the missing key
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CallFblInitKey_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   /* Disable Timer etc. */
   FblBmDeinit(); /* PRQA S 2987 */ /* MD_FBL_2987_RedundantCode */

   FblBmSetInitKeysMagicFlag();

   /* Call Fbl */
   FBLBM_CALLOUT_CALL_FBL_INIT_KEYS(&fblBmBlockInfo.bmHeader);

   /* This code is never reached */
   return kFblFsmGuard_True;
}
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY */

#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
/**********************************************************************************************************************
 *  FblBmState_CallTarget_Entry
 *********************************************************************************************************************/
/*! \brief        Call a target (Application, Updater)
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CallTarget_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
# endif

   /* Disable Timer etc. */
   FblBmDeinit(); /* PRQA S 2987 */ /* MD_FBL_2987_RedundantCode */

   /* Call Appl */
   FBLBM_CALLOUT_CALL_TARGET(&g_BmTargetBmHeader);

   /* This code is never reached */
   return kFblFsmGuard_True;
}
#endif/* FBLBM_BOOTTARGETLIST_SIZE > 0u */

#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
/**********************************************************************************************************************
 *  FblBmState_CallFblInitCmac_Entry
 *********************************************************************************************************************/
/*! \brief        Call the FBL to initialize the FBL-CMAC(s)
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CallFblInitCmac_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   /* Disable Timer etc. */
   FblBmDeinit(); /* PRQA S 2987 */ /* MD_FBL_2987_RedundantCode */

   FblBmSetInitCmacMagicFlag();

   /* Call Fbl */
   FBLBM_CALLOUT_CALL_FBL_INIT_CMAC(&fblBmBlockInfo.bmHeader);

   /* This code is never reached */
   return kFblFsmGuard_True;
}
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */

/**********************************************************************************************************************
 *  FblBmState_CallFbl_Entry
 *********************************************************************************************************************/
/*! \brief        Start the FBL
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CallFbl_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   /* Disable Timer etc. */
   FblBmDeinit(); /* PRQA S 2987 */ /* MD_FBL_2987_RedundantCode */

   /* Call Fbl */
   FBLBM_CALLOUT_CALL_FBL(&fblBmBlockInfo.bmHeader);

   /* This code is never reached */
   return kFblFsmGuard_True;
}

# if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
/**********************************************************************************************************************
 *  FblBmState_CallFblStayInBoot_Entry
 *********************************************************************************************************************/
/*! \brief        Start the FBL and set the magic flag that to check for a stay in boot message
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CallFblStayInBoot_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   /* Disable Timer etc. */
   FblBmDeinit(); /* PRQA S 2987 */ /* MD_FBL_2987_RedundantCode */

   FblBmSetStayInBootMagicFlag();

   /* Call Fbl */
   FBLBM_CALLOUT_CALL_FBL(&fblBmBlockInfo.bmHeader);

   /* This code is never reached */
   return kFblFsmGuard_True;
}
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */

#if defined( FBLBM_ENABLE_SECURE_BOOT )
/**********************************************************************************************************************
 *  FblBmState_CheckFblSegments
 *********************************************************************************************************************/
/*! \brief        Start check of FBL segments.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CheckFblSegments(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
# endif

   result = kFblFsmGuard_True;

# if defined( FBLBM_ENABLE_HEADER_VERIFICATION )
#  if defined( FBLBM_ENABLE_USE_VERIFY_HEADER_ROM )
   if (kFblOk != FblSb_VerifyHeaderRom(fblBmBlockInfo.logicalBlock.bmHeaderAddress, &fblBmBlockInfo.bmHeader))
#  else
   if (kFblOk != FblSb_VerifyHeader(&fblBmBlockInfo.bmHeader))
#  endif /* FBLBM_ENABLE_USE_VERIFY_HEADER_ROM */
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_FBL_FBLHEADER_FAILED;
   }
# else /* FBLBM_ENABLE_HEADER_VERIFICATION */
   if (kFblOk != FblSb_VerifySegments(&fblBmBlockInfo.bmHeader))
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_FBL_VERIFICATION_FAILED;
   }
# endif /* FBLBM_ENABLE_HEADER_VERIFICATION */

   return result;
}
#endif /* FBLBM_ENABLE_SECURE_BOOT */

/**********************************************************************************************************************
 *  FblBmState_Fail_Entry
 *********************************************************************************************************************/
/*! \brief        An error has happened.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_Fail_Entry(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   FBLBM_CALLOUT_FATAL_ERROR(g_BmError);

   return kFblFsmGuard_False;
}

/**********************************************************************************************************************
 *  FblBmCheckFblValidity
 *********************************************************************************************************************/
/*! \brief        Checks the Header and the validity (e.g.: Presence Pattern) of the FBL
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CheckFblValidity(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   result = kFblFsmGuard_True;

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
   /* Read FBL header from configured memory location */

   if (FblReadProm(FblBmHeader.fblHeaderAddress, (vuint8*) &fblBmFblHeader, sizeof(tFblHeader)) != sizeof(tFblHeader))
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_HEADER_READ_FAILED;
   }

   /* Check magic flag of the FBL header */
   if (kFblFsmGuard_True == result)
   {
      if (fblBmFblHeader.magicFlag != FBL_MAIN_HEADER_MAGIC_FLAG)
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_HEADER_MAGIC_FAILED;
      }
   }

   if (kFblFsmGuard_True == result)
   {
      /* Fill out the block descriptor for the FBL */
      fblBmBlockInfo.logicalBlock.blockStartAddress = fblBmFblHeader.fblStartAddress;
      fblBmBlockInfo.logicalBlock.blockLength = fblBmFblHeader.fblLength;
      fblBmBlockInfo.logicalBlock.bmHeaderAddress = (tFblAddress) fblBmFblHeader.bmHeader; /* PRQA S 0306 */ /* MD_FblBmMain_0306 */
      fblBmBlockInfo.logicalBlock.mandatoryType = TRUE;
      fblBmBlockInfo.logicalBlock.blockNr = 0x00u;

      /* Check if FBL is valid (e.g.: evaluate Presence Pattern) */
      if (kFblOk != FBLBM_CALLOUT_IS_VALIDBLOCK(FBLBMHDR_TARGET_FBL, &fblBmBlockInfo.logicalBlock))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_VALIDITY_FAILED;
      }
   }

#else

   /* Fill out the block descriptor for the FBL */
   fblBmBlockInfo.logicalBlock.blockStartAddress = FblHeader.fblStartAddress;
   fblBmBlockInfo.logicalBlock.blockLength = FblHeader.fblLength;
   fblBmBlockInfo.logicalBlock.bmHeaderAddress = (tFblAddress) FblHeader.bmHeader; /* PRQA S 0306 */ /* MD_FblBmMain_0306 */
   fblBmBlockInfo.logicalBlock.mandatoryType = TRUE;
   fblBmBlockInfo.logicalBlock.blockNr = 0x00u;


#endif /* FBLBM_ENABLE_STANDALONE_MODE */

   if (kFblFsmGuard_True == result) /* PRQA S 2991, 2995 */ /* MD_FblBmMain_2991_2995 */
   {
      if (FBLBMHDR_CHKHDR_OK != FblBmHdrGetBmHeader(FBLBMHDR_TARGET_FBL, fblBmBlockInfo.logicalBlock.bmHeaderAddress, &fblBmBlockInfo.bmHeader))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_FBL_BMHEADER_INCORRECT;
      }
   }

   return result;
}

#if defined( FBLBM_ENABLE_UPDATER_FAILSAFE )
/**********************************************************************************************************************
 *  FblBmState_FailsafeUpdaterSearchInit
 *********************************************************************************************************************/
/*! \brief        Prepare the search for an failsafe Updater.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBLBM_ENABLE_UPDATER_FAILSAFE
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_FailsafeUpdaterSearchInit(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   /* Get BmHeader address from callout. In case FBLBM_ENABLE_UPDATER_FAILSAFE is enabled, callout
    * FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT is requested to return the next possible location
    */
   if (kFblOk == FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_INIT())
   {
      result = kFblFsmGuard_True;
   }
   else
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_UPDATER_SEARCH_INIT_FAILED;
   }
   return result;
}

/**********************************************************************************************************************
 *  FblBmState_CheckFailsafeUpdater
 *********************************************************************************************************************/
/*! \brief        Check if failsafe updater is valid and can be verified.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBLBM_ENABLE_UPDATER_FAILSAFE
 *********************************************************************************************************************/
/* PRQA S 3673, 6010, 6030 1 */ /* MD_FBL_3673_PointerToConstParameter, MD_MSR_STPTH, MD_MSR_STCYC */
static tFblFsmGuard FblBmState_FailsafeUpdaterCheck(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;
   tFblBmBlockInfo blockInfo = { 0 };
   vuint32 headerAddress;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   result = kFblFsmGuard_True;
   if (kFblOk != FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_HEADER_ADDRESS(&headerAddress))
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_UPDATER_HEADER_ADDRESS;
   }

   /* Hint: The order of checks is different than checking an application because the FBL-LBT can not be used here */
   if (kFblFsmGuard_True == result)
   {
      blockInfo.bmHeader.bmTargetHandle = FBLBMHDR_TARGET_FBLUPDATER;
      blockInfo.bmHeader.bmBlockStartAddress = 0u;
      blockInfo.bmHeader.bmBlockLength = 1u;
      blockInfo.bmHeader.bmEntryAddress = 0u;

      /* Read BM header from flash */
      if (FblReadProm(headerAddress, (vuint8 *)&blockInfo.bmHeader, sizeof(tFblBmHdrHeader)) != sizeof(tFblBmHdrHeader))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_UPDATER_HEADER_READ_ERROR;
      }
   }

   /* Check for correct target handle */
   if (kFblFsmGuard_True == result)
   {
      if (blockInfo.bmHeader.bmTargetHandle != FBLBMHDR_TARGET_FBLUPDATER) /* PRQA S 2992,2996 */ /* MD_FblBmMain_2880_2992_2996_FlashRead */
      {
         result = kFblFsmGuard_False; /* PRQA S 2880 */ /* MD_FblBmMain_2880_2992_2996_FlashRead */
         g_BmError = FBLBM_ERROR_UPDATER_HEADER_TYPE;
      }
   }

   /* Check for consistency errors */
   if (kFblFsmGuard_True == result)
   {
      if ( kFblOk != FblBmHdrCheckConsistency(&blockInfo.bmHeader))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_UPDATER_HEADER_CONSISTENCY;
      }
   }

   /* Header seems to be OK, check if block is valid */
   if (kFblFsmGuard_True == result)
   {
      /* Initialize the logical block structure */
      blockInfo.logicalBlock.blockStartAddress = blockInfo.bmHeader.bmBlockStartAddress;
      blockInfo.logicalBlock.blockLength = blockInfo.bmHeader.bmBlockLength;

      if (kFblOk != FBLBM_CALLOUT_IS_VALIDBLOCK(blockInfo.bmHeader.bmTargetHandle, &blockInfo.logicalBlock))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_UPDATER_BLOCK_VALIDITY;
      }
   }

# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  if defined( FBLBM_ENABLE_HEADER_VERIFICATION )
   if (kFblFsmGuard_True == result)
   {
#   if defined( FBLBM_ENABLE_USE_VERIFY_HEADER_ROM )
      if (kFblOk != FblSb_VerifyHeaderRom(headerAddress, &blockInfo.bmHeader))
#   else
      if (kFblOk != FblSb_VerifyHeader(&blockInfo.bmHeader))
#   endif /* FBLBM_ENABLE_USE_VERIFY_HEADER_ROM */
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_UPDATER_HEADER_CMAC_VERIFY;
      }
   }
#  endif /* FBLBM_ENABLE_HEADER_VERIFICATION */

   if (kFblFsmGuard_True == result)
   {
      if (kFblOk != FblSb_VerifySegments(&blockInfo.bmHeader))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_UPDATER_VERIFY;
      }
   }
# endif /* FBLBM_ENABLE_SECURE_BOOT */

   if (kFblFsmGuard_True == result)
   {
      g_BmFailsafeUpdaterBmHeader = blockInfo.bmHeader;
   }

   return result;
}

/**********************************************************************************************************************
 *  FblBmState_FailsafeUpdaterSearchNext
 *********************************************************************************************************************/
/*! \brief        Get next possible location for a Failsafe Updater BmHeader
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBLBM_ENABLE_UPDATER_FAILSAFE
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_FailsafeUpdaterSearchNext(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   if (kFblOk == FBLBM_CALLOUT_SEARCH_FAILSAFE_UPDATER_NEXT())
   {
      result = kFblFsmGuard_True;
   }
   else
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_UPDATER_SEARCH_NEXT_FINISHED;
   }

   return result;
}
#endif /* FBLBM_ENABLE_UPDATER_FAILSAFE */

/**********************************************************************************************************************
 *  FblBmState_CheckKeyAvailability
 *********************************************************************************************************************/
/*! \brief        Check if Key is available for MAC verification. If not, the FBL is called to initialize the key.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CheckKeyAvailability(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

#if defined( FBLBM_ENABLE_SECURE_BOOT ) && \
    defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_KEY )
   if (FBLBM_KEY_IS_NOT_AVAILABLE == FBLBM_CALLOUT_GET_KEYEMPTY())
   {
      /* Key is not available */
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_KEY_NOT_AVAILABLE;
   }
   else
   {
      result = kFblFsmGuard_True;
   }
#else
   /* No key needed or not configured to be checked, return OK to proceed */
   result = kFblFsmGuard_True;
#endif
   return result;
}

#if defined( FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC )
/**********************************************************************************************************************
 *  FblBmState_CheckFblMacErased
 *********************************************************************************************************************/
/*! \brief        Check if a CMAC (even an invalid one) is written for the FBL - if not call FBL to write a CMAC.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CheckFblMacErased(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   if (FBLBM_MAC_IS_AVAILABLE == FBLBM_CALLOUT_GET_FBL_CMACERASED(&fblBmBlockInfo))
   {
      /* FBL-CMAC is already written */
      result = kFblFsmGuard_False;
   }
   else
   {
      /* FBL-CMAC is not yet written */
      result = kFblFsmGuard_True;
   }
   return result;
}
#endif /* FBLBM_ENABLE_SECBOOT_FBL_INIT_MAC */

#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
/**********************************************************************************************************************
 *  FblBmState_CheckApplStartFlag
 *********************************************************************************************************************/
/*! \brief        Check if the ApplStart flag is set
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBLBM_MAIN_ENABLE_STAY_IN_BOOT
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CheckApplStartFlag( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event )
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   if (FblBmChkApplStartMagicFlag())
   {
      FblBmClrMagicFlag();
      result = kFblFsmGuard_True;
   }
   else
   {
      result = kFblFsmGuard_False;
   }

   return result;
}
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */

/**********************************************************************************************************************
 *  FblBmState_CheckReprogFlag
 *********************************************************************************************************************/
/*! \brief        Check if Reprogramming Flag is set
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBL_DISABLE_STAY_IN_BOOT
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CheckReprogFlag(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   /* Check if there is a reprogramming request (e.g. UDS, XCP, MCMP, OTA) */
   if (FBLBM_CALLOUT_CHECKREPROGFLAG() == kFblOk)
   {
      /* Do not clear flag, as the Bootloader requires it as well */

      result = kFblFsmGuard_True;
   }
   else
   {
      result = kFblFsmGuard_False;
   }

   return result;
}

/**********************************************************************************************************************
 *  FblBmState_CheckFblLbt
 *********************************************************************************************************************/
/*! \brief        Check the validity and verification of the FBL-LBT
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673, 6010 1 */ /* MD_FBL_3673_PointerToConstParameter, MD_MSR_STPTH */
static tFblFsmGuard FblBmState_CheckFblLbt(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( FBLBM_ENABLE_STANDALONE_MODE )
   tFblFsmGuard result;

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
# endif

# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  if defined( FBLBM_ENABLE_FBLLBT_VERIFICATION )
   if (kFblOk != FblSb_VerifyFblLbt(&fblBmFblHeader))
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_LBT_VERIFY;
   }
   else
#  endif /* FBLBM_ENABLE_FBLLBT_VERIFICATION */
# endif /* FBLBM_ENABLE_SECURE_BOOT */
   {
      /* Validation of FBL-LBT successful: Use Fbl-LBT */
      FblLbtActivateLbtBlockByAddress((tFblAddress)fblBmFblHeader.pLogicalBlockTable); /* PRQA S 0306 */ /* MD_FblBmMain_0306 */

      /* Consistency check (BM-LBT <-> FBL-LBT) */
      /* Check if block count exceeds built-in maximum value */
      if (FblLbtGetBlockCount() > FBL_LBT_BLOCK_COUNT)
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_LBT_TOO_LARGE;
      }
      else
      {
         result = kFblFsmGuard_True;
      }
   }

   if (kFblFsmGuard_True != result)
   {
      /* Failure - switch back to internal LBT */
      FblLbtInitPowerOn();
   }

   return result;
#else
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
# endif

   return kFblFsmGuard_True;
#endif /* FBLBM_ENABLE_STANDALONE_MODE */
}

#if defined( FBL_LBT_ENABLE_REPROGRAMMABLE_LBT )
/**********************************************************************************************************************
 *  FblBmState_CheckReprogLbt
 *********************************************************************************************************************/
/*! \brief        Check if a Reprogrammable LBT is available. If so, use it.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *  \config       FBL_LBT_ENABLE_REPROGRAMMABLE_LBT
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CheckReprogLbt( tFblFsmContextPtr const pFsmContext, tFblFsmEvent event )
{
   tFblFsmGuard result;
   tFblBmBlockInfo blockInfo;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   result = kFblFsmGuard_True;

   /* Get Reprog-LBT from FBL-LBT */
   if (kFblOk != FblLbtGetBlockDescriptorByNr(FBL_LBT_LBT_BLOCK_NUMBER, &blockInfo.logicalBlock))
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_REPROG_LBT_DESCR;
   }

   if (kFblFsmGuard_True == result)
   {
      if (kFblOk != FBLBM_CALLOUT_IS_VALIDBLOCK(FBLBMHDR_TARGET_REPROGLBT, &blockInfo.logicalBlock))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_REPROG_LBT_INVALID;
      }
   }

   if (kFblFsmGuard_True == result)
   {
      if (FBLBMHDR_CHKHDR_OK != FblBmHdrGetBmHeader(FBLBMHDR_TARGET_REPROGLBT, blockInfo.logicalBlock.bmHeaderAddress, &blockInfo.bmHeader))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_REPROG_LBT_BMHEADER_INCORRECT;
      }
   }

# if defined( FBLBM_ENABLE_SECURE_BOOT )
#  if defined( FBLBM_ENABLE_HEADER_VERIFICATION )
   if (kFblFsmGuard_True == result)
   {
#   if defined( FBLBM_ENABLE_USE_VERIFY_HEADER_ROM )
      if (kFblOk != FblSb_VerifyHeaderRom(blockInfo.logicalBlock.bmHeaderAddress, &blockInfo.bmHeader))
#   else
      if (kFblOk != FblSb_VerifyHeader(&blockInfo.bmHeader))
#   endif /* FBLBM_ENABLE_USE_VERIFY_HEADER_ROM */
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_REPROG_LBT_VERIFY_HEADER;
      }
   }
#  endif/* FBLBM_ENABLE_HEADER_VERIFICATION */

   if (kFblFsmGuard_True == result)
   {
      if (kFblOk != FblSb_VerifySegments(&blockInfo.bmHeader))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_REPROG_LBT_VERIFY_SEGMENTS;
      }
   }
# endif /* FBLBM_ENABLE_SECURE_BOOT */

   if (kFblFsmGuard_True == result)
   {
      tFblLbtMagicFlag originalMagicFlag = FblLbtGetMagicFlag();

      FblLbtActivateLbtBlockByAddress(blockInfo.logicalBlock.blockStartAddress);

      if (originalMagicFlag != FblLbtGetMagicFlag())
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_REPROG_LBT_MAGIC_FLAG;
      }
      else if (FblLbtGetBlockCount() > FBL_LBT_BLOCK_COUNT)
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_REPROG_LBT_BLOCK_COUNT;
      }
      else
      {
         /* Nothing to do */
      }

      if (kFblFsmGuard_True != result)
      {
# if defined( FBLBM_ENABLE_STANDALONE_MODE )
         /* Use LBT from FblHeader, if this point is reached it was already verified and checked for consistency */
         FblLbtActivateLbtBlockByAddress((tFblAddress)fblBmFblHeader.pLogicalBlockTable);
# else /* FBLBM_ENABLE_STANDALONE_MODE */
         FblLbtInitPowerOn();
# endif /* FBLBM_ENABLE_STANDALONE_MODE */
      }
   }

   return result;
}
#endif /* FBL_LBT_ENABLE_REPROGRAMMABLE_LBT */

#if ( FBLBM_BOOTTARGETLIST_SIZE > 0u )
/**********************************************************************************************************************
 *  FblBmState_TargetListInit
 *********************************************************************************************************************/
/*! \brief        Prepare target list search. Get target list via callout
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_TargetListInit(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   g_BmTargetListIndex = 0u;
   result = kFblFsmGuard_True;

   return result;
}

/**********************************************************************************************************************
 *  FblBmState_TargetCheck
 *********************************************************************************************************************/
/*! \brief        Check validity and verification of a target and all its dependencies
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673, 6010, 6030, 6080 1 */ /* MD_FBL_3673_PointerToConstParameter, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
static tFblFsmGuard FblBmState_TargetCheck(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
#if defined( FBLBM_ENABLE_SECURE_BOOT )
   tFblResult fblSbResult;
#endif /* FBLBM_ENABLE_SECURE_BOOT */
   tFblFsmGuard result;
   tFblBmHdrTargetListEntry target;
   tFblBmHdrTargetHandle targetHandle;
   tFblBmBlockInfo blockInfoTarget = { 0 };
   tFblBmBlockInfo blockInfoDep;
   vuintx index;
   tFblBmHdrCheckBmHeaderResult findHeaderResult;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   target = FblBm_BootTargetList[g_BmTargetListIndex];
   targetHandle = target.target;
   result = kFblFsmGuard_True;

   /* Check Application validity */
   if (kFblOk != FBLBM_CALLOUT_CHECK_TARGET_VALIDITY(targetHandle))
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_TARGET_INVALID;
   }

   if (kFblFsmGuard_True == result)
   {
      if (FBLBMHDR_CHKHDR_OK != FblBmHdrFindValidHeader(targetHandle, &blockInfoTarget))
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_TARGET_NO_VALID_HEADER;
      }
   }

#if defined( FBLBM_ENABLE_SECURE_BOOT )
   if (kFblFsmGuard_True == result)
   {
# if defined( FBLBM_ENABLE_HEADER_VERIFICATION )
#  if defined( FBLBM_ENABLE_USE_VERIFY_HEADER_ROM )
      fblSbResult = FblSb_VerifyHeaderRom(blockInfoTarget.logicalBlock.bmHeaderAddress, &blockInfoTarget.bmHeader);
#  else
      fblSbResult = FblSb_VerifyHeader(&blockInfoTarget.bmHeader);
#  endif /* FBLBM_ENABLE_USE_VERIFY_HEADER_ROM */

      if (kFblOk == fblSbResult)
# endif /* FBLBM_ENABLE_HEADER_VERIFICATION */
      {
         fblSbResult = FblSb_VerifySegments(&blockInfoTarget.bmHeader);
      }
      if (kFblOk != fblSbResult)
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_TARGET_VERIFICATION_FAILED;
      }
   }
#endif /* FBLBM_ENABLE_SECURE_BOOT */

   if (kFblFsmGuard_True == result)
   {
      /* Check all Mandatory dependencies */
      for (index = 0u; index < target.dependenciesSize; index++)
      {
         targetHandle = target.dependencies[index].target;

         findHeaderResult = FblBmHdrFindValidHeader(targetHandle, &blockInfoDep);

         if (FBLBMHDR_CHKHDR_OK == findHeaderResult)
         {
#if defined( FBLBM_ENABLE_SECURE_BOOT )
# if defined( FBLBM_ENABLE_HEADER_VERIFICATION )
#  if defined( FBLBM_ENABLE_USE_VERIFY_HEADER_ROM )
            fblSbResult = FblSb_VerifyHeaderRom(blockInfoDep.logicalBlock.bmHeaderAddress, &blockInfoDep.bmHeader);
#  else
            fblSbResult = FblSb_VerifyHeader(&blockInfoDep.bmHeader);
#  endif /* FBLBM_ENABLE_USE_VERIFY_HEADER_ROM */

            if (kFblOk == fblSbResult)
# endif/* FBLBM_ENABLE_HEADER_VERIFICATION */
            {
               fblSbResult = FblSb_VerifySegments(&blockInfoDep.bmHeader);
            }
            if (kFblOk != fblSbResult)
            {
               result = kFblFsmGuard_False;
               g_BmError = FBLBM_ERROR_TARGET_DEP_VERIFY_FAILED;
            }
#endif /* FBLBM_ENABLE_SECURE_BOOT */
         }
         else
         {
            if (FBLBM_TARGET_TYPE_MANDATORY == target.dependencies[index].type)
            {
               result = kFblFsmGuard_False;
               g_BmError = FBLBM_ERROR_TARGET_DEP_MANDATORY_MISSING;
            }
            else
            {
               /* Ignore this block, it is optional */
               FBLBM_CALLOUT_IS_OPTIONALBLOCK(targetHandle, &blockInfoDep.logicalBlock);
            }
         }
         if (kFblFsmGuard_False == result)
         {
            break;
         }
      } /* END FOR */
   }

   /* Check if the target address is valid */
   if (kFblFsmGuard_True == result)
   {
      if (blockInfoTarget.bmHeader.bmEntryAddress == FBLBMHDR_ENTRY_ADDRESS_INVALID)      /* PRQA S 2962 */ /* MD_FBL_2962_UninitializedVariable */
      {
         result = kFblFsmGuard_False;
         g_BmError = FBLBM_ERROR_TARGET_INVALID_ADDRESS;
         assertFbl(0u, kFblSysAssertParameterOutOfRange);      /* PRQA S 2741, 4558 */ /* MD_FBL_2741_4558_Assert */
      }
   }

   if (kFblFsmGuard_True == result)
   {
      /* Store BmHeader of target */
      g_BmTargetBmHeader = blockInfoTarget.bmHeader;
   }

   return result;
}

/**********************************************************************************************************************
 *  FblBmState_TargetListNext
 *********************************************************************************************************************/
/*! \brief        Get next target entry from target list.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_TargetListNext(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

   g_BmTargetListIndex++;
   if (FBLBM_BOOTTARGETLIST_SIZE > g_BmTargetListIndex)
   {
      result = kFblFsmGuard_True;
   }
   else
   {
      /* End of list reached */
      result = kFblFsmGuard_False;
   }

   return result;
}
#endif /*  FBLBM_BOOTTARGETLIST_SIZE > 0u */

/**********************************************************************************************************************
 *  FblBmState_CheckFblVerification
 *********************************************************************************************************************/
/*! \brief        Check the verification (CMAC) of the FBL.
 *  \param[in]    pFsmContext Pointer to context of state machine
 *  \param[in]    event Event that caused handler execution
 *  \return       - kFblFsmGuard_True if transition to next configured state is allowed,
 *                - kFblFsmGuard_False otherwise (transition prohibited, check further event handlers)
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
static tFblFsmGuard FblBmState_CheckFblVerification(tFblFsmContextPtr const pFsmContext, tFblFsmEvent event)
{
   tFblFsmGuard result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pFsmContext;
   (void)event;
#endif

#if defined( FBLBM_ENABLE_SECURE_BOOT )
# if defined( FBLBM_ENABLE_FBLLBT_VERIFICATION )
   if (kFblOk != FblSb_VerifySegments(&fblBmBlockInfo.bmHeader))
   {
      result = kFblFsmGuard_False;
      g_BmError = FBLBM_ERROR_FBL_VERIFICATION_FAILED;
   }
   else
# else
   /* Segments are already verified during the LBT verification */
# endif /* FBLBM_ENABLE_FBLLBT_VERIFICATION */
#endif /* FBLBM_ENABLE_SECURE_BOOT */
   {
      result = kFblFsmGuard_True;
   }

   return result;
}

/**********************************************************************************************************************
 *  FblBmDeinit
 *********************************************************************************************************************/
/*! \brief        Deinitialize e.g. stop the timer before calling a target.
 *********************************************************************************************************************/
static void FblBmDeinit(void)
{
   FBLBM_CALLOUT_DEINIT_PRE_OEM();
   FBLBM_CALLOUT_DEINIT_PRE_HW();
   FBLBM_CALLOUT_DEINIT_PRE();

#if defined( FBL_WATCHDOG_ON )
   /* Synchronize watchdog before application start */
   ApplFblWDLong();
#endif /* FBL_WATCHDOG_ON */
   /* Stop timer to avoid a timer interrupt after application start */
   FblTimerStopp();

   FBLBM_CALLOUT_DEINIT_POST_OEM();
   FBLBM_CALLOUT_DEINIT_POST_HW();
   FBLBM_CALLOUT_DEINIT_POST();
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/*-- Bootmanager helper functions ----------------------------------------------------------------------------------------*/

#if defined( FBLBM_ENABLE_STANDALONE_MODE )
/***********************************************************************************************************************
 *  FblMemSetInteger
 **********************************************************************************************************************/
/*! \brief      Convert given integer value to big-endian byte array
 *  \param[in]  count Number of relevant bytes
 *  \param[in]  input Input value
 *  \param[out] buffer Pointer to output buffer
 **********************************************************************************************************************/
void FblMemSetInteger( vuintx count, vuint32 input, tFblMemRamData buffer)
{
   vuintx localCount;
   vuint32 localInput;

   /* Initialize variables */
   localCount = count;
   localInput = input;

   /* Loop relevant bytes */
   while (localCount > 0u)
   {
      localCount--;
      /* Store most significant byte first */
      buffer[localCount] = (vuint8) (localInput & 0xFFu);
      /* Shift in next byte */
      localInput >>= 8u;
   }
}

/***********************************************************************************************************************
 *  FblMemGetInteger
 **********************************************************************************************************************/
/*! \brief      Convert given big-endian byte array to integer value
 *  \param[in]  count Number of relevant bytes
 *  \param[in]  buffer Pointer to input buffer
 *  \return     Integer value
 **********************************************************************************************************************/
vuint32 FblMemGetInteger( vuintx count, tFblMemConstRamData buffer)
{
   vuint32 output;
   vuintx idx;

   output = 0u;
   idx = 0u;

   /* Loop relevant bytes */
   while (idx < count)
   {
      /* Most significant byte first */
      output <<= 8u;
      /* Add current byte */
      output |= (vuint32) buffer[idx];

      idx++;
   }

   return output;
}
#endif /* FBLBM_ENABLE_STANDALONE_MODE */

/*-- Main functions --------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  FblMain
 **********************************************************************************************************************/
/*! \brief        Initializes the system and runs the bootmanager.
 **********************************************************************************************************************/
/* PRQA S 5209 1 */ /* MD_FblBmMain_5209_Main */
void V_API_NEAR FblMain(void)
{
   /* Initialize state machine */
   FblFsmInitPowerOn();

   /* Start State Machine */
   g_BmFsmContext.stateDefinitions = bmFsmStates;
   g_BmFsmContext.stateCount = FBLBM_ARRAY_SIZE(bmFsmStates);
   FblFsmInit(&g_BmFsmContext, (tFblFsmState) FBLBM_STATE_POWER_ON);

   while (g_BmFsmContext.state != (tFblFsmState) FBLBM_STATE_FAIL)
   {
      /* Request next step */
      FblFsmTriggerEvent(&g_BmFsmContext, (tFblFsmEvent) FBLBM_EVENT_CONTINUE);
      FblFsmStateTask(&g_BmFsmContext);
   }

   FBLBM_CALLOUT_FATAL_ERROR(FBLBM_ERROR_END_OF_MAIN_REACHED);
}

#define FBLBM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( FBLBM_MAIN_ENABLE_FBL_START )
# define FBLBM_FBLSTART_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblStart
 **********************************************************************************************************************/
/*! \brief       Transition from application into flash boot loader
 *  \pre         Valid application program running
 *  \param[in]   channel Specify the channel of the reprogramming request (e.g. UDS, XCP, MCMP, OTA)
 *  \param[in]   pFblStartParam Pointer to OEM specific parameter structure
 *  \param[in]   length Length of OEM specific parameter structure [Bytes]
 **********************************************************************************************************************/
#  if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
/* PRQA S 3673 2 */ /* MD_FBL_3673_PointerToConstParameter */
void FblStart( FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_FIRST
   V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 * pFblStartParam, vuint8 length )
#  else
void FblStart( FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE_TYPE_ONLY )
#  endif /* FBL_MAIN_ENABLE_FBLSTART_PARAM */
{
# if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
   vuintx i;
# endif

# if !defined( FBLBM_MAIN_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON )
   FblInterruptDisable(); /* PRQA S 1006 */ /* MD_FblBmMain_1006 */
# endif /* FBLBM_MAIN_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON */

   /* Restore bootmanager context - e.g. small data area base registers */
   FblHwRestoreFblContext(); /* PRQA S 1006 */ /* MD_FblBmMain_1006 */

# if defined( FBLBM_MAIN_ENABLE_FBLSTART_PARAM )
   /* Copy parameter to reset safe variable */
   for (i = 0u; i < length; i++)
   {
      /* PRQA S 0316 1 */ /* MD_FblBmMain_0316 */
      ((volatile vuint8*)&fblBmFblStartParameter)[i] = ((vuint8*)pFblStartParam)[i];
   }
# endif /* FBLBM_MAIN_ENABLE_FBLSTART_PARAM */

#if defined( FBLBM_MAIN_ENABLE_FBLSTART_CHANNEL )
   fblBmFblStartChannel = FBLBM_MAIN_FBLSTART_CHANNEL_HANDLE;
#endif /* FBLBM_MAIN_ENABLE_FBLSTART_CHANNEL */

   /* Set FblStart magic flag
      Please pay attention: The FblStart magic flag does not use a shared memory area so that the buffer may overlap
      with the application stack. */
   FblBmSetFblStartMagicFlag();

   /* Generate reset */
   FBLBM_CALLOUT_RESET();
}
# define FBLBM_FBLSTART_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLBM_MAIN_ENABLE_FBL_START */

#if defined( FBLBM_MAIN_ENABLE_STAY_IN_BOOT )
# define FBLBM_APPLSTART_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  ApplStart
 **********************************************************************************************************************/
/*! \brief       Transition from flash boot loader into application
 *  \pre         Valid FBL program running
 *  \param[in]   pApplStartParam Pointer to OEM specific parameter structure
 *  \param[in]   length Length of OEM specific parameter structure [Bytes]
 **********************************************************************************************************************/
# if defined( FBLBM_MAIN_ENABLE_APPLSTART_PARAM )
/* PRQA S 3673 1 */ /* MD_FBL_3673_PointerToConstParameter */
void ApplStart( V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 * pApplStartParam, vuint8 length )
# else
void ApplStart( void )
# endif /* FBLBM_MAIN_ENABLE_APPLSTART_PARAM */
{
# if defined( FBLBM_MAIN_ENABLE_APPLSTART_PARAM )
   vuintx i;
# endif

# if !defined( FBLBM_MAIN_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON )
   FblInterruptDisable(); /* PRQA S 1006 */ /* MD_FblBmMain_1006 */
# endif /* FBLBM_MAIN_ENABLE_INTERRUPT_DISABLE_AT_POWER_ON */

   /* Restore bootmanager context - e.g. small data area base registers */
   FblHwRestoreFblContext(); /* PRQA S 1006 */ /* MD_FblBmMain_1006 */
# if defined( FBLBM_MAIN_ENABLE_APPLSTART_PARAM )
   /* Copy parameter to reset safe variable */
   for (i = 0u; i < length; i++)
   {
      /* PRQA S 0316 1 */ /* MD_FblBmMain_0316 */
      ((volatile vuint8*)&fblBmApplStartParameter)[i] = ((vuint8*)pApplStartParam)[i];
   }
# endif /* FBLBM_MAIN_ENABLE_APPLSTART_PARAM */

   /* Set ApplStart magic flag
      Please pay attention: The ApplStart magic flag does not use a shared memory area so that the buffer may overlap
      with the application stack. */
   FblBmSetApplStartMagicFlag();

   /* Generate reset */
   FBLBM_CALLOUT_RESET();
}
# define FBLBM_APPLSTART_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLBM_MAIN_ENABLE_STAY_IN_BOOT */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#if ( defined( FBLBM_ENABLE_HEADER_VERIFICATION ) && !defined( FBLBM_ENABLE_FBLLBT_VERIFICATION ) )   || \
   ( !defined( FBLBM_ENABLE_HEADER_VERIFICATION ) && defined( FBLBM_ENABLE_FBLLBT_VERIFICATION ) )
# error "Configuration not supported"
#endif

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblBmMain_0306:
      Reason:     Address conversion between integer values and pointers is required to allow for hardware independent
                  configuration and address range checks.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis.

   MD_FblBmMain_0306_FblBmHeader:
      Reason:     A memory address is compared to a configured value. The configured value is interpreted as an integer.
      Risk:       The comparison may fail due to different data types.
      Prevention: If this check fails, the configuration checks done by assertions have to verified manually.

   MD_FblBmMain_0316:
      Reason:     API is defined with pointer to void parameter, so pointer has to be casted to or from void.
      Risk:       Wrong data access or undefiend behavior for platforms where the byte alignment is not arbitrary.
      Prevention: Code inspection.

   MD_FblBmMain_1006:
      Reason:     Interrupts are enabled/disabled using assembler code.
      Risk:       The code is not portable for different compilers.
      Prevention: The assembler code provided by each FblHw module has to be tested.

   MD_FblBmMain_1514_BmHeader:
      Reason:     MISRA: The object FblBmHeader is only referenced by function ..., in the translation unit where it is defined
                  This object is exported globally to other modules.
      Risk:       Name space pollution
      Prevention: No Prevention necessary

   MD_FBL_2962_UninitializedVariable:
      Reason:     The variable is actually initialzed at runtime. The successive code will never be executed over not initialzed data.
      Risk:       Some potential case not detected during development can lead to read a content which is not valid.
      Prevention: Write robust code which doesn't allow to read a non initialzed content.

   MD_FBL_2987_RedundantCode:
      Reason:     QAC misinterprets the code which actually has side effects (i.e. hardware registers are written and read).
      Risk:       No identifiable risk
      Prevention: No prevention required.

   MD_FblBmMain_2991_2995:
      Reason:     The value of the if-controlling expression depends on the configuration.
      Risk:       No risk.
      Prevention: No prevention necessary.

   MD_FblBmMain_2880_2992_2996_FlashRead:
      Reason:     QAC does not interpret this correctly. The compared data is read from flash (and may therefore contain deviating values).
      Risk:       No risk.
      Prevention: No prevention required.

   MD_FblBmMain_3205_UnusedIdentifiers
      Reason:     Depending on the configuration some values of the enum definition are not referenced by the code.
                  For clarity theses values are not omitted but kept as a place holder.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FBL_3218_FileScopeStatic:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FBL_3673_PointerToConstParameter:
      Reason:     Many standards like AUTOSAR, ISO, but also OEM specifications specify the function prototypes without
                  const statement. We have to comply to this standards.
      Risk:       Unintended read or write access into memory location.
      Prevention: Code inspection focus on correct access to expected memory location

   MD_FBL_2741_4558_Assert:
      Reason: The assertion macro has been designed to have an invariant condition and not using bool variable.
      Risk: No identifiable risk. Assertion macro are disable in production code.
      Prevention: No prevention required.

   MD_FblBmMain_5209_Main:
      Reason:     The Vector standard API for main function follows ANSI C typical definition of main function returning int.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

 */

/***********************************************************************************************************************
 *  END OF FILE: BM_MAIN.C
 **********************************************************************************************************************/
