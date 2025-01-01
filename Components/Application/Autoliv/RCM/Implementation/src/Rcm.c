
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version: 
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.1.17.2.6 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/RCM/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup RCM.c RCM
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */
 
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Common.h"
#include "Config.h"
#include "Nvp_Generated.h"

#include "Mcu.h"
#include "Smu.h"
#include "IfxScu_reg.h"
#include "IfxScu_bf.h"
#include "IfxMtu_reg.h"

#include "SBC.h"

#include "Rte_RCM_AC_ResetCauseManagement.h"
#include "Rcm.h"

#include "NVP_Stubs.h"
#include "RCM_Callout_Stubs.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

#define KU32_RESET_COUNTER_MAX                        ((uint32)0xFFFFFFFE)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_START_SEC_VAR_UNSPECIFIED
#include "RCM_AC_ResetCauseManagement_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * @ingroup RCM
 * \brief
 *		Variable to store the detected reset reason.
 */
static u32ResetCauseType rcm_u32ResetCause = KU32_ZERO;

/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_STOP_SEC_VAR_UNSPECIFIED
#include "RCM_AC_ResetCauseManagement_MemMap.h"

/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_RESET_NOTIFICATIONS_START_SEC_VAR_NOINIT
#include "MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/**
 * @ingroup RCM
 * \brief
 *		Software reset reasons flags.
 */
uint8 __RCM_au8ResetNotification[KU32_MAX_RESET_NOTIFICATION];

/**
 * @ingroup RCM
 * \brief
 *		Mirror data to validate data integrity.
 */
uint8 __RCM_au8ResetNotification_XOR[KU32_MAX_RESET_NOTIFICATION];

/**
 * @ingroup RCM
 * \brief
 *		External watchdog test result.
 */
uint8 __RCM_u8ExternalWdgFailed;

/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_RESET_NOTIFICATIONS_STOP_SEC_VAR_NOINIT
#include "MemMap.h"

/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_START_SEC_CONST_UNSPECIFIED
#include "RCM_AC_ResetCauseManagement_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/**
 * \brief
 *		Based on Os ticks: 1 tick = 25ns.
 * \remarks
 *		5s = 200000000 ticks.
 */
#define KU32_LPIT_CH2_RST_VALUE           ((uint32) 200000000)

/**
 * \brief
 *		LPIT register address, offset and values.
 *		Timer Control Register for channel 2 Address (Base LPIT reg @ + 0x28 + (channel x 0x20)
 *    TCTRL1 Address : Base LPIT reg @ + 0x28 + (1 x 0x20) = Base LPIT reg @ + 0x48
 */
#define KU32_LPIT_REG_ADDR_TCTRL2         ((uint32) LPIT0_BASEADDR + (uint32)0x48)

/**
 * \brief
 *		TCTRL1 Cleared value.
 */
#define KU32_LPIT_REG_TCTRL2_CLEARED      ((uint32) 0x00000000)

/**
 * \brief
 *		TCTRL1 configured : Stop on interupt (bit 17) and channel enabled (bit 0).
 */
#define KU32_LPIT_REG_TCTRL2_CFG          ((uint32) 0x00020001)

/**
 * \brief
 *		Timer Value Register for channel 2 Address (Base LPIT reg @ + 0x20 + (channel x 0x20).
 *		TVAL1 Address : Base LPIT reg @ + 0x20 + (1 x 0x20) = Base LPIT reg @ + 0x40
 */
#define KU32_LPIT_REG_ADDR_TVAL2          ((uint32) LPIT0_BASEADDR + (uint32)0x40)

/**
 * \brief
 *		Module Interrupt Enable Register Address (Base LPIT reg @ + 0x10.
 *		MIER Address : Base LPIT reg @ + 0x10
 */
#define KU32_LPIT_REG_ADDR_MIER           ((uint32) LPIT0_BASEADDR + (uint32)0x10)

/**
 * \brief
 *		Enable channel 2 interupt (bit 2).
*/
#define KU32_LPIT_REG_MIER_EI_CH2         ((uint32) 0x00000004)

/**
 * \brief
 *		Set Timer Enable Register Address (Base LPIT reg @ + 0x14.
 *		SETTEN Address : Base LPIT reg @ + 0x14
*/
#define KU32_LPIT_REG_ADDR_SETTEN         ((uint32) LPIT0_BASEADDR + (uint32)0x14)

/**
 * \brief
 *		Enable timer channel 2 (bit 2).
*/
#define KU32_LPIT_REG_SETTEN_EN_CH2       ((uint32) 0x00000004)

/**
 * \brief
 *		Module Status Register Address (Base LPIT reg @ + 0x0C.
 *		MSR Address : Base LPIT reg @ + 0x0C
*/
#define KU32_LPIT_REG_ADDR_MSR            ((uint32) LPIT0_BASEADDR + (uint32)0x0C)

/**
 * \brief
 *		Clear timer channel 2 interrupt flag (bit 2).
 */
#define KU32_LPIT_REG_MSR_CLR_IT_CH2      ((uint32) 0x00000004)

/**
 * \brief
 *		Clear Timer Enable Register (Base LPIT reg @ + 0x18.
 *		CLRTEN Address : Base LPIT reg @ + 0x18
 */
#define KU32_LPIT_REG_ADDR_CLRTEN         ((uint32) LPIT0_BASEADDR + (uint32)0x18)

/**
 * \brief
 *		Clear timer 2 enable (bit 2).
*/
#define KU32_LPIT_REG_CLRTEN_CLR_CH2_EN   ((uint32) 0x00000004)

typedef enum
{
    RcmCpu_Index_0 = 0,  /**< \brief CPU 0 */
    RcmCpu_Index_none    /**< \brief None of the CPU */
} RcmCpu_Index;

typedef enum
{
    RcmCpu_ResourceCpu_0    = RcmCpu_Index_0,    /**< \brief CPU 0 */
    RcmCpu_ResourceCpu_none = RcmCpu_Index_none  /**< \brief None of the CPU */
} RcmCpu_ResourceCpu; 

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_STOP_SEC_CONST_UNSPECIFIED
#include "RCM_AC_ResetCauseManagement_MemMap.h"
/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

RcmCpu_ResourceCpu RcmCpu_getCoreIndex(void)
{
    Ifx_CPU_CORE_ID reg;
    reg.U = __mfcr(CPU_CORE_ID);
    return (RcmCpu_ResourceCpu)reg.B.CORE_ID;
}

void RcmScuWdt_clearCpuEndinitInline(Ifx_SCU_WDTCPU *watchdog, uint16 password)
{
    if (watchdog->CON0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        watchdog->CON0.U = (1 << IFX_SCU_WDTCPU_CON0_ENDINIT_OFF) |
                           (0 << IFX_SCU_WDTCPU_CON0_LCK_OFF) |
                           (password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                           (watchdog->CON0.B.REL << IFX_SCU_WDTCPU_CON0_REL_OFF);
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    watchdog->CON0.U = (0 << IFX_SCU_WDTCPU_CON0_ENDINIT_OFF) |
                       (1 << IFX_SCU_WDTCPU_CON0_LCK_OFF) |
                       (password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                       (watchdog->CON0.B.REL << IFX_SCU_WDTCPU_CON0_REL_OFF);

    /* read back ENDINIT and wait until it has been cleared */
    while (watchdog->CON0.B.ENDINIT == 1)
    {}
}

uint16 RcmScuWdt_getCpuWatchdogPasswordInline(Ifx_SCU_WDTCPU *watchdog)
{
    uint16 password;

    /* Read Password from CON0 register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */
    password  = watchdog->CON0.B.PW;
    password ^= 0x003F;

    return password;
} 

void RcmScuWdt_setCpuEndinitInline(Ifx_SCU_WDTCPU *watchdog, uint16 password)
{
    if (watchdog->CON0.B.LCK)
    {
        /* see Table 1 (Pass.word Access Bit Pattern Requirements) */
        watchdog->CON0.U = (1 << IFX_SCU_WDTCPU_CON0_ENDINIT_OFF) |
                           (0 << IFX_SCU_WDTCPU_CON0_LCK_OFF) |
                           (password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                           (watchdog->CON0.B.REL << IFX_SCU_WDTCPU_CON0_REL_OFF);
    }

    /* Set ENDINT and set LCK bit in Config_0 register */
    watchdog->CON0.U = (1 << IFX_SCU_WDTCPU_CON0_ENDINIT_OFF) |
                       (1 << IFX_SCU_WDTCPU_CON0_LCK_OFF) |
                       (password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                       (watchdog->CON0.B.REL << IFX_SCU_WDTCPU_CON0_REL_OFF);

    /* read back ENDINIT and wait until it has been set */
    while (watchdog->CON0.B.ENDINIT == 0)
    {}
} 

void RcmScuRcu_clearColdResetStatus(void)
{
    uint16 password;

    password = RcmScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[RcmCpu_getCoreIndex()]);
    RcmScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[RcmCpu_getCoreIndex()], password);
    /* Clear Cold Reset status */
    MODULE_SCU.RSTCON2.B.CLRC = 1U;
    RcmScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[RcmCpu_getCoreIndex()], password);
}

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_START_SEC_CODE
#include "RCM_AC_ResetCauseManagement_MemMap.h"

/**
* \brief
*     Count warm reset events.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
static void rcm_runCountWarmReset(void)
{
   uint32 u32ResetCause;
   u32ResetCause = rcm_u32ResetCause & (KU32_RESET_CAUSE_UNKNOWN
         | KU32_CRYSTAL_FAILURE_MASK
         | KU32_PLL_FAILURE_MASK
         | KU32_ECC_RAM_MASK
         | KU32_ECC_PFLASH_MASK
         | KU32_OS_EXCEPTION_MASK
         | KU32_INVALID_INTERRUPT_MASK
         | KU32_ECC_UNIDENTIFIED_MASK
         | KU32_ECC_E2P_MASK
         | KU32_STACK_OVERFLOW_MASK
         | KU32_EXTERNAL_WDG_MASK);
   /* check if either a warm reset was detected or reset cause unknown */
   if ((KU32_ZERO !=u32ResetCause)||(KU32_ZERO==rcm_u32ResetCause))
   {
      /* warm reset detected */
      /* update cause */
      NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCause   = u32ResetCause;
      /* update counter */
      /* 0xFFFFFFFE reserved for maximum value 0xFFFFFFFF for empty record */
      /* replace with single macro */
      if (NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCounter < KU32_RESET_COUNTER_MAX)
      {
         NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCounter++;
      }
      /* initial cnt val FFFFFFFFh, set to 1 */
      else if( NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCounter == KU32_MAX )
      {
         NVP_BLOCK_ID_WARM_RESET_RamBlockData.NVP_u32WarmResetCounter = KU32_ONE;
      }
      else
      {}
      /* Notification to record the WarmReset Block during the shutdown */
      (void)Rte_Call_pclNvmServicesWarmReset_SetRamBlockStatus(TRUE);

   }
   else
   {}

}

/**
* \brief
*     Main initialization function for the reset cause analysis.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void RCM_runConfirmResetCause(void)
{
   uint8 u8Index;
   /* -------------------------------------------------------------------- */
   /* Finish reset cause analysis                                          */
   /* -------------------------------------------------------------------- */
   /* If the determineResetCause indicates a POR */
   if ( KU32_POWER_ON_RESET_MASK == (rcm_u32ResetCause & KU32_POWER_ON_RESET_MASK) )
   {
      /* If the SCM indicates a KL30/KL30bg Lost */
      if( B_TRUE == __RCM_au8ResetNotification[KU32_BATTERY_LOSS_NOTIFICATION] )
      {
         /* Set the Battery lost flag and reset the POR flag */
         rcm_u32ResetCause |= KU32_BATTERY_LOSS_MASK;
         rcm_u32ResetCause &= (uint32)(~KU32_POWER_ON_RESET_MASK);
      }
      else
      {
         /* Do Nothing */
      }
   }
   else
   {
      /* Do nothing */
   }
   /* -------------------------------------------------------------------- */
   /* Prepare next reset analysis                                          */
   /* -------------------------------------------------------------------- */

   /* Clear RCM_SSR (Sticky System Reset Status Register) flags */
   RcmScuRcu_clearColdResetStatus();

   /* Reset RAM NO INIT data */
   for ( u8Index=KU8_ZERO ; u8Index < KU32_MAX_RESET_NOTIFICATION ; u8Index++ )
   {
      __RCM_au8ResetNotification    [u8Index] = KU8_FALSE;
      __RCM_au8ResetNotification_XOR[u8Index] = KU8_TRUE;

   }
   /* Save if warm reset */
   rcm_runCountWarmReset();

   /* Enable PFLASH ECC related interrupt */
   SRC_SMU0.B.SRE = 1;
}

/**
* \brief
*     Function called only one time during Init Sequence before SCM init function.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void RCM_runDetermineResetCause(void)
{
   Mcu_RawResetType u32StickySRSRegister; /* RCM_SSRS register */
   uint32           u32SBCStatusInformation;
   uint8            u8Index;
   boolean          bIsRamNoInitValid;

   rcm_u32ResetCause = KU32_RESET_CAUSE_UNKNOWN;

   /* Init assumption : RAM NO INIT status is ok */
   bIsRamNoInitValid = B_TRUE;

   /* -------------------------------------------------------------------- */
   /* Start reset cause analysis                                           */
   /* -------------------------------------------------------------------- */
   /* Get the SBC status information from SBC ( for external watchdog, POR, LV...) */
   SBC_GetSBCStatusInformation(&u32SBCStatusInformation);

   /* Shadow register */
   /* Mcu module clears RCM_SSRS status flags once read.(However for multiple calls of the two standard
    * APIs (Mcu_GetResetRawValue and Mcu_GetResetReason) the return value is always the same */
   u32StickySRSRegister = Mcu_GetResetRawValue();


   /******** Resets triggered by Hardware ********/
   /* Check POR flag from SBC */
   if (KU32_ZERO != (u32SBCStatusInformation & KU8_MASK_POWER_ON_RESET))
   {
      rcm_u32ResetCause |= KU32_POWER_ON_RESET_MASK;
   }
   /* Check battery voltage status from SBC */
   else if (KU32_ZERO != (u32SBCStatusInformation & KU8_MASK_VS_UNDER_VOLTAGE))
   {
      rcm_u32ResetCause |= KU32_BATTERY_LOSS_MASK;
   }
   else if ((KU32_ZERO != (u32SBCStatusInformation & KU8_MASK_WATCHDOG_FAILURE))
		 || (KU32_ZERO != (u32StickySRSRegister & MCU_SW_RESET)))
   {
      /* Check RAM NO INIT data integrity */
	   for (u8Index = KU8_ZERO; u8Index < KU32_MAX_RESET_NOTIFICATION; u8Index++)
	   {
         if (__RCM_au8ResetNotification[u8Index] != ((uint8) (~(__RCM_au8ResetNotification_XOR[u8Index]))))
         {
			   /* Invalid Data content on at least on byte */
            bIsRamNoInitValid = B_FALSE;
         }
         else
         {
            /* Nothing to do */
		   }
	   }
		/* before using the RAM No Init content, make sure that it is valid */
		if ((B_TRUE != bIsRamNoInitValid))
		{
			/* warm reset */
		}
		else
		{
		   /* Invalid Interrupt */
			if ( B_TRUE == __RCM_au8ResetNotification[KU32_INVALID_INTERRUPT_NOTIFICATION])
			{
			   rcm_u32ResetCause |= KU32_INVALID_INTERRUPT_MASK;
			}
			/* OS error */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_OS_EXCEPTION_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_OS_EXCEPTION_MASK;
			}
			/* Reset triggered by the Internal WDG Test  */
			else if (B_TRUE == __RCM_au8ResetNotification[KU32_SW_WDG_TEST_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_SW_WDG_TEST_MASK;
			}
			/* Reset occurs due to Machine Exception due to RAM ECC error */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_ECC_RAM_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_ECC_RAM_MASK;
			}
			/* Reset occurs due to Machine Exception due to PFLASH ECC error */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_ECC_PFLASH_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_ECC_PFLASH_MASK;
			}
			/* Reset occurs due to Machine Exception due to PFLASH E2P error */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_ECC_E2P_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_ECC_E2P_MASK;
			}
			/* Reset occurs due to Machine Exception due to an unidentified ECC */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_ECC_UNIDENTIFIED_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_ECC_UNIDENTIFIED_MASK;
			}
			/* Reset occurs due to Machine Exception due to a machine exception error but not an ECC */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_MACHINE_EXCEPTION_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_OS_EXCEPTION_MASK;
			}
			/* Reset triggered by a hardReset (11 01) diagnostic request */
			else if (B_TRUE == __RCM_au8ResetNotification[KU32_DIAG_HARD_RESET_NOTIFICATION])
			{
				/* Diagnostic reset cause */
				rcm_u32ResetCause |= KU32_SW_RESET_MASK;
			}
			/* Check whether the RAM No Init indicates a Diagnostic SW reset (11 03) */
			else if (B_TRUE == __RCM_au8ResetNotification[KU32_DIAG_SOFT_RESET_NOTIFICATION])
			{
				/* Diagnostic reset cause */
				rcm_u32ResetCause |= KU32_SW_RESET_MASK;
			}
			/* Reset triggered by entering in programming session. BTLD Reset */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_BTLD_RESET_NOTIFICATION])
			{
				/* Reset occurs due to programming requesting. */
				rcm_u32ResetCause |= KU32_BTLD_RESET_MASK;
			}
			/* Reset occurs due to a stack overflow. */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_STACK_OVERFLOW_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_STACK_OVERFLOW_MASK;
			}
			/* Reset occurs due to a RAM data corruption */
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_RAM_DATA_CORRUPTED_NOTIFICATION])
			{
				rcm_u32ResetCause |= KU32_RAM_DATA_CORRUPTED;
			}
			else if ( B_TRUE == __RCM_au8ResetNotification[KU32_PLL_LOCK_LOSS_NOTIFICATION])
			{
				/* PLL failure reset */
				rcm_u32ResetCause |= KU32_PLL_FAILURE_MASK;
			}
			/* If no notification received : Unexpected external WDG */
			else
			{
				rcm_u32ResetCause |= KU32_EXTERNAL_WDG_MASK;
			}
		}
   }
   else if (KU32_ZERO != (u32SBCStatusInformation & KU8_MASK_CAN_WU))
   {
	   rcm_u32ResetCause |= KU32_WAKE_UP_EVENT_MASK;
   }
}

/**
* \brief
*     This function will provide the reset reason to the application.
* \param
*     u32ResetCauseType * pu32ResetCause
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void RCM_runGetResetCause(u32ResetCauseType * pu32ResetCause)
{
   /* QAC_WARNING S 0310 2 */ /* Casting to different object pointer type. */
   /* QAC_WARNING S 3305 1 */ /* Pointer cast to stricter alignment. */
   if ( ((uint32 *) KPU8_NULL) != pu32ResetCause)
   {
      *pu32ResetCause = rcm_u32ResetCause;
   }
   else
   {
      /* Nothing to do */
   }
}

/**
* \brief
*     Software reset flags updater.
* \param
*  u32ResetReasonNotificationType u32ResetCauseNotification
*
*  u32ResetReasonNotificationStatusType u32ResetCauseStatus
*
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void RCM_runNotifyResetCause(u32ResetReasonNotificationType u32ResetCauseNotification,
  u32ResetReasonNotificationStatusType u32ResetCauseStatus)
{
   b8BooleanType b8Data       = KU8_ZERO;
   b8BooleanType b8DataMirror = KU8_ZERO;

   if(KU32_RESET_CAUSE_INACTIVE == u32ResetCauseStatus)
   {
      b8Data         = KU8_FALSE;
      b8DataMirror   = KU8_TRUE ;
   }
   else if(KU32_RESET_CAUSE_ACTIVE == u32ResetCauseStatus)
   {
      b8Data         = KU8_TRUE ;
      b8DataMirror   = KU8_FALSE;
   }
   else
   {
      /* Nothing to do : invalid argument */
   }

   /* Check if 2nd argument has been validated before processing*/
   if ( (KU8_TRUE == b8Data) || (KU8_FALSE == b8Data) )
   {
      if ( KU32_MAX_RESET_NOTIFICATION > u32ResetCauseNotification)
      {
         __RCM_au8ResetNotification[u32ResetCauseNotification]     = b8Data;
         __RCM_au8ResetNotification_XOR[u32ResetCauseNotification] = b8DataMirror;
      }
      else
      {
         /* Nothing to do : invalid argument */
      }

   }
   else
   {
      /* Nothing to do : invalid argument */
   }

}

/**
* \brief
*     Function that launches a test of the external watchdog.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void RCM_runLaunchExtWdgTest(void)
{
   /* Notify resetCause*/
   RCM_runNotifyResetCause(KU32_SW_WDG_TEST_NOTIFICATION, KU32_RESET_CAUSE_ACTIVE);
   /* Force reset by external watchdog */
   SBC_ForceExternalWatchdogReset();
}

/**
* \brief
*     Function that checks watchdog test result.
* \param
*     u8WdgTestResultType *pu8WdgTestResult
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void RCM_runGetTestResult (P2VAR(u8WdgTestResultType, AUTOMATIC, RTE_APPL_DATA) pu8WdgTestResult)
{
   if(NULL_PTR != pu8WdgTestResult)
   {
      /* Check if external WDG Test has failed */
      if(__RCM_u8ExternalWdgFailed == KU8_WDG_TEST_FAILED)
      {
         /* Signal error */
         *pu8WdgTestResult = KU8_WDG_TEST_FAILED;

         /* Reset External WDG test result */
         /*__RCM_u8ExternalWdgFailed = KU8_WDG_TEST_PASSED;*/
      }
      else
      {
         *pu8WdgTestResult = KU8_WDG_TEST_PASSED;
      }
   }
   else
   {
      /* Do nothing */
   }
}

/**
* \brief
*     Function that checks watchdog test interruption.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     None.
**/
void OS_ISR_RCM_ExtWDTest(void)
{
   __RCM_u8ExternalWdgFailed = KU8_WDG_TEST_FAILED;
}
/**
* \brief
*     Function that clears alarms and inits SMU.
* \param
*     None.
* \exception
*     None.
* \pre
*     Must be called during the init phase.
* \post
*     None.
* \return
*     None.
**/
void RCM_PreInit(void)
{
   uint16 password;
   password = RcmScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[RcmCpu_getCoreIndex()]);
   RcmScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[RcmCpu_getCoreIndex()], password);

   /* enable MTU */
   MTU_CLC.U = 0x0U;
   /* clear errors */
   MTU_MC0_ECCD.U = 0U;
   MTU_MC1_ECCD.U = 0U;
   MTU_MC2_ECCD.U = 0U;
   MTU_MC3_ECCD.U = 0U;
   MTU_MC4_ECCD.U = 0U;
   MTU_MC34_ECCD.U = 0U;
   MTU_MC40_ECCD.U = 0U;
   MTU_MC41_ECCD.U = 0U;
   MTU_MC62_ECCD.U = 0U;
   MTU_MC63_ECCD.U = 0U;
   MTU_MC66_ECCD.U = 0U;
   MTU_MC68_ECCD.U = 0U;
   MTU_MC70_ECCD.U = 0U;
   MTU_MC72_ECCD.U = 0U;
   MTU_MC73_ECCD.U = 0U;
   MTU_MC74_ECCD.U = 0U;
   MTU_MC75_ECCD.U = 0U;
   MTU_MC76_ECCD.U = 0U;
   MTU_MC77_ECCD.U = 0U;
   MTU_MC78_ECCD.U = 0U;
   /* disable MTU */
   MTU_CLC.U = 0x3U;
   RcmScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[RcmCpu_getCoreIndex()], password);

   Smu_Init(&Smu_Config);
   Smu_ActivateRunState(SMU_START_STATE);
}
/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_STOP_SEC_CODE
#include "RCM_AC_ResetCauseManagement_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/




















