/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Watchdog functions
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
 *  03.00.00   2018-02-09  visach  ESCAN00097885    Rework configuration
 *  03.01.00   2019-08-13  vistbe  FBL-370          Added support for generic MCMP slave
 *  03.02.00   2019-11-01  visrcn  FBL-512          Perform MISRA analysis
 *  03.03.00   2022-01-20  visstn  FBL-4299         Encapsulate ApplFblWDInit call + Update to MISRA2012
 **********************************************************************************************************************/

#define FBL_WD_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLWD_VERSION != 0x0303u ) || \
    ( FBLWD_RELEASE_VERSION != 0x00u )
# error "Error in fbl_wd.c: Source and header file are inconsistent!"
#endif

#if ( FBLWD_VERSION != _FBLWD_VERSION ) || \
    ( FBLWD_RELEASE_VERSION != _FBLWD_RELEASE_VERSION )
# error "Error in fbl_wd.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

# if !defined( kFblGenericEventMargin )
#  define kFblGenericEventMargin (kFblDiagTimeP2Star/2u) /**< Default value for P2 retransmit timings. */
# endif

#  define PerformGenericEventAction()        \
   {                                         \
      if (GetRcrRpInProgress())              \
      {                                      \
         FblCwRetransmitRP();                \
         SetP2Timer(kFblDiagTimeP2Star);     \
      }                                      \
   }


/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define FBLWD_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

V_MEMRAM0 V_MEMRAM1 vuint16 V_MEMRAM2 P2Timer;     /**< P2 timeout timer, mapped to wdGenericEventTimer in header file */

V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 WDInitFlag;   /**< Watchdog initialized flag */

#if defined( FBL_WATCHDOG_ON )
/* PRQA S 1514 1 */ /* MD_FblWd_1514 */
V_MEMRAM0 V_MEMRAM1 tWdTime V_MEMRAM2 WDTimer;     /**< Counts timer events until next watchdog triggering */
#endif /* FBL_WATCHDOG_ON */

/***********************************************************************************************************************
 *  EXTERNAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#if defined( FBL_WATCHDOG_ON )
#endif /* FBL_WATCHDOG_ON */
#define FBLWD_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define FBLWD_INIT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblInitWatchdog
 **********************************************************************************************************************/
/*! \brief      Initialize module
 *  \return     Reports if initialization was successful.
 **********************************************************************************************************************/
void V_API_NEAR FblInitWatchdog( void )
{
   wdGenericEventTimer = 0x00u;
   SetWDInit();

#if defined( FBL_DEF_ENABLE_NON_KB_MAIN )
# if defined( FBL_WATCHDOG_ON )
   ApplFblWDInit();
# endif /* FBL_WATCHDOG_ON */
#endif /* FBL_DEF_ENABLE_NON_KB_MAIN */
}
#define FBLWD_INIT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLWD_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblLookForWatchdogVoid
 **********************************************************************************************************************/
/*! \brief       Polling of watchdog during longer operations.
 *  \details     This function executes watchdog and timer handling code from RAM. Depending on the Bootloader
 *               configuration, additionally some communication tasks can be handled by this function. The return
 *               value of FblLookForWatchdog() is not returned by this function so it could be used by libraries which
 *               expect a void return value.
 *  \pre         Watchdog code was copied to RAM, watchdog handling is initialized.
 **********************************************************************************************************************/
void V_API_NEAR FblLookForWatchdogVoid( void )
{
   (void)FblLookForWatchdog();
}
#define FBLWD_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLWD_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  FblLookForWatchdog
 **********************************************************************************************************************/
/*! \brief       Polling of watchdog during longer operations.
 *  \details     This function executes watchdog and timer handling code from RAM. Depending on the Bootloader
 *               configuration, additionally some communication tasks can be handled by this function.
 *  \pre         Watchdog code was copied to RAM, watchdog handling is initialized.
 *  \return      FBL_NO_TRIGGER if no timer/watchdog expired, FBL_TM_TRIGGERED if the millisecond timer expired,
 *               FBL_WD_TRIGGERED if watchdog handling code was called.
 **********************************************************************************************************************/
__indirect vuint8 FblLookForWatchdog( void ) /* PRQA S 6080 */ /* MD_MSR_STMIF */
{
   vuint8 retValue = FBL_NO_TRIGGER;

   if (GetWDInit()) /* Check if watchdog already initialized */
   {
      if (FblTimerGet() != 0x00u)
      {
         FblTimerReset();
         retValue |= FBL_TM_TRIGGERED;

         if (wdGenericEventTimer > 0x00u)
         {
            wdGenericEventTimer--;
            if (wdGenericEventTimer < kFblGenericEventMargin)
            {
               PerformGenericEventAction();
            }
         }

# if defined( FBL_WATCHDOG_ON )
         if (WDTimer != 0x00u)
         {
            WDTimer--;
            if (WDTimer == 0x00u)
            {
               ApplFblWDTrigger();
               WDTimer = FBL_WATCHDOG_TIME;
               retValue |= FBL_WD_TRIGGERED;
            }
         }
# endif /* FBL_WATCHDOG_ON */

         /* Check if the FBL or FD (erase/write) is active */
         if (0u != FblCwIsTimerTaskAllowed())
         {
            /* the FBL is active, this task can now be called e.g. from the FLASH */
            FblCwTimerTask();
         }


# if defined( FBL_WD_TIMER_TASK )
         /* Execute configurable timer task
            Task is not active until timer and watchdog have been initialized
            Has to be executed from RAM or a lock mechanism needs to be implemented in macro to prevent execution while flash
            operations are active  */
         FBL_WD_TIMER_TASK();
# endif /* FBL_WD_TIMER_TASK */
      } /* if (FblTimerGet() != 0x00u) */
   } /* if (GetWDInit()) */

   /* Check if the FBL or FD (erase/write) is active */
   if (0u != FblCwIsStateTaskAllowed())
   {
      /* the FBL is active, this task can now be called e.g. from FLASH */
      FblCwStateTask();
   }

# if defined( FBL_WD_STATE_TASK )
   /* Execute configurable state task
      Task is active immediately and will be executed on every function call
      Has to be executed from RAM or a lock mechanism needs to be implemented in macro to prevent execution while flash
      operations are active  */
   FBL_WD_STATE_TASK();
# endif /* FBL_WD_STATE_TASK */

   return retValue;
}
#define FBLWD_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* module specific MISRA deviations:

   MD_FblWd_1514:
     Reason:     The variable is used by other modules and can't be declared static.
     Risk:       Name conflicts.
     Prevention: Compile and link of the different variants in the component and integration test.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_WD.C
 **********************************************************************************************************************/
