/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: EcuM
 *           Program: 
 *          Customer: 
 *       Expiry Date: 2023-04-09
 *    License Scope : The usage is restricted to PAI194
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Callout_Stubs.c
 *   Generation Time: 2021-06-10 20:28:38
 *           Project: StartApplication - Version 1.0
 *          Delivery: PAI194
 *      Tool Version: DaVinci Configurator (beta) 5.23.10 S-3
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
#define ECUM_CALLOUT_STUBS_SOURCE
#include "EcuM.h"
#include "SBC.h"
#define ECUM_PRIVATE_CFG_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */



/**********************************************************************************************************************
 *  All configured EcuM Wakeup Sources (as bitmasks) for usage in Callouts
 *********************************************************************************************************************/
/*
 * ECUM_WKSOURCE_NONE                                             (EcuM_WakeupSourceType)(0x00000000uL) 
 * ECUM_WKSOURCE_ALL_SOURCES                                      (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL)) 
 * ECUM_WKSOURCE_POWER                                            (EcuM_WakeupSourceType)(1uL) 
 * ECUM_WKSOURCE_RESET                                            (EcuM_WakeupSourceType)(2uL) 
 * ECUM_WKSOURCE_INTERNAL_RESET                                   (EcuM_WakeupSourceType)(4uL) 
 * ECUM_WKSOURCE_INTERNAL_WDG                                     (EcuM_WakeupSourceType)(8uL) 
 * ECUM_WKSOURCE_EXTERNAL_WDG                                     (EcuM_WakeupSourceType)(16uL) 
 * ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6 (EcuM_WakeupSourceType)(32uL) 
 */

/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/
#include "Crypto_30_vHsm.h" 
#include "Crypto_30_LibCv.h" 
#include "CryIf.h" 
#include "Csm.h" 
#include "IpduM.h" 
#include "SecOC.h" 
#include "PduR.h" 
#include "ComM.h" 
#include "Det.h" 
#include "Rte_Main.h" 
#include "BswM.h" 
#include "CanIf.h" 
#include "CanTp.h" 
#include "Dcm.h" 
#include "Dem.h" 
#include "Com.h" 
#include "CanSM_EcuM.h" 
#include "Can.h" 
#include "CanNm.h" 
#include "Nm.h" 
#include "E2EXf.h" 
#include "Mcu.h" 
#include "Nvp_Generated.h"
#include "SchM_Fee.h"
#include "SchM_Fls_17_Dmu.h"
#include "MemIf_Types.h"
#include "NvM.h"
#include "KeyM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#if !defined(_MICROSOFT_C_VTT_) && (CRYPTO_30_VHSM_INTERRUPT_MODE == STD_ON)
#include "Crypto_30_vHsm_Cfg.h"
#include "tc3xx_hsm_bridge.h"

/* Service request register, taken from IfxSrc_regdef.h */
typedef struct _Ifx_SRC_SRCR_Bits
{
  unsigned int SRPN : 8;        /**< \brief [7:0] Service Request Priority Number (rw) */
  unsigned int reserved_8 : 2;  /**< \brief Reserved */
  unsigned int SRE : 1;         /**< \brief [10:10] Service Request Enable (rw) */
  unsigned int TOS : 3;         /**< \brief [13:11] Type of Service Control (rw) */
  unsigned int reserved_14 : 2; /**< \brief Reserved */
  unsigned int ECC : 5;         /**< \brief [20:16] ECC (rwh) */
  unsigned int reserved_21 : 3; /**< \brief Reserved */
  unsigned int SRR : 1;         /**< \brief [24:24] Service Request Flag (rh) */
  unsigned int CLRR : 1;        /**< \brief [25:25] Request Clear Bit (w) */
  unsigned int SETR : 1;        /**< \brief [26:26] Request Set Bit (w) */
  unsigned int IOV : 1;         /**< \brief [27:27] Interrupt Trigger Overflow Bit (rh) */
  unsigned int IOVCLR : 1;      /**< \brief [28:28] Interrupt Trigger Overflow Clear Bit (w) */
  unsigned int SWS : 1;         /**< \brief [29:29] SW Sticky Bit (rh) */
  unsigned int SWSCLR : 1;      /**< \brief [30:30] SW Sticky Clear Bit (w) */
  unsigned int reserved_31 : 1; /**< \brief Reserved */
} Ifx_SRC_SRCR_Bits;

/* Service request register, taken from IfxSrc_regdef.h */
typedef union {
  unsigned int U;      /**< \brief Unsigned access */
  signed int I;        /**< \brief Signed access */
  Ifx_SRC_SRCR_Bits B; /**< \brief Bitfield access */
} Ifx_SRC_SRCR;

/* HSM Service Request, taken from IfxSrc_reg.h */
#define SRC_HSM0 (*(volatile Ifx_SRC_SRCR *)0xF0038870u)
#endif /* !defined(VTT) && (CRYPTO_30_VHSM_INTERRUPT_MODE == STD_ON) */

/* NVP Block: ECU Location */
#define NVM_BLOCK_ECU_LOCATION_ID (NvMConf_NvMBlockDescriptor_NVP_BLOCK_ID_ECU_LOCATION)

#define ECU_SIDE_RBTM_FR          (0x99u)



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/

FUNC(void, ECUM_CODE) EcuM_ErrorHook(Std_ReturnType reason) /* COV_ECUM_CALLOUT */ /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ErrorHook>                         DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)reason;     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_ErrorHook() */
  
  /* In case of an inconsistent configuration data, abort initialization here */
  if(reason == ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT)
  {
    while(1)
    {
    }
  }
  
# if(ECUM_NUMBER_OF_CORES > 1)
  /* In case of an invalid coreId, returned by the OS */
  if(reason == ECUM_E_HOOK_INVALID_COREID)
  {
    while(1)
    {
    }
  }
# endif
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_ErrorHook() */




/**********************************************************************************************************************
 *  CALLOUTS FROM THE SHUTDOWN PHASE
 *********************************************************************************************************************/



FUNC(void, ECUM_CODE) EcuM_OnGoOffOne(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffOne>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_OnGoOffOne() */
  Rte_Stop();
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_OnGoOffOne() */

FUNC(void, ECUM_CODE) EcuM_ShutdownOS(Std_ReturnType ErrCode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ShutdownOS>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_ShutdownOS() */
#if ( ECUM_NUMBER_OF_CORES > 1 )
  if(GetCoreID() == ECUM_CORE_ID_BSW)
  {
  ShutdownAllCores(ErrCode);
  }
#else
  ShutdownOS(ErrCode);
#endif
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_ShutdownOS() */

FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffTwo>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_OnGoOffTwo() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_OnGoOffTwo() */

FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SwitchOff>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

  //#ifdef _MICROSOFT_C_VTT_
  //Mcu_PerformReset();
  //#endif

  SBC_Shutdown();
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_SwitchOff() */

FUNC(void, ECUM_CODE) EcuM_AL_Reset(EcuM_ResetType Reset) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_Reset>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  //uint8 waitCounter = 0;

  //Mcu_PerformReset();
  /* Code here should never be reached. While loop is here just to wait for external watchdog reset in case primary reset path fails. */
  //while (1)
  //{
    //waitCounter++;
//#ifdef _MICROSOFT_C_VTT_
    //CANoeAPI_ConsumeTicks(1);
//#endif
  //}

  if(Reset == EcuMConf_EcuMResetMode_ECUM_RESET_MCU)
  {
    Mcu_PerformReset();
  }
  else if(Reset == EcuMConf_EcuMResetMode_ECUM_RESET_WDG)
  {
    SBC_ForceExternalWatchdogReset();
  }
  else
  {
    /* No other reset mechanisms supported currently */
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_Reset() */



/**********************************************************************************************************************
 *  CALLOUTS FROM THE STARTUP PHASE
 *********************************************************************************************************************/


/**********************************************************************************************************************
* EcuM_AL_DriverInitZero
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero(void) 
{
  uint8 RequestResultPtr;

  Crypto_30_vHsm_InitMemory();
  Crypto_30_LibCv_InitMemory();
  CryIf_InitMemory();
  Csm_InitMemory();
  IpduM_InitMemory();
  SecOC_InitMemory();
  PduR_InitMemory();
  ComM_InitMemory();
  Det_InitMemory();
  Rte_InitMemory();
  BswM_InitMemory();
  Det_Init( Det_Config_Ptr );
  CanIf_InitMemory();
  CanTp_InitMemory();
  Dcm_InitMemory();
  Dem_InitMemory();
  Com_InitMemory();
  CanSM_InitMemory();
  Can_InitMemory();
  Dem_PreInit( Dem_Config_Ptr );
  CanNm_InitMemory();
  Nm_InitMemory();
  E2EXf_InitMemory();
  KeyM_InitMemory();

  Mcu_Init(&Mcu_Config ); /* Mcu init needed here because mem stack is initialized below */
  
  /* Initialize NVM at DriverInitZero because EECU location needs to be known before starting up the system */
  Fls_17_Dmu_Init(&Fls_17_Dmu_Config);
  Fee_Init(&Fee_Config);
  NvM_Init();

  while(Fee_GetStatus() != MEMIF_IDLE)
  {
    Fee_MainFunction();
    Fls_17_Dmu_MainFunction();
  }

  NvM_ReadBlock((NvM_BlockIdType)NVM_BLOCK_ECU_LOCATION_ID, &NVP_BLOCK_ID_ECU_LOCATION_RamBlockData);

  do
  {
    NvM_MainFunction();
    Fee_MainFunction();
    Fls_17_Dmu_MainFunction();
    NvM_GetErrorStatus((NvM_BlockIdType)NVM_BLOCK_ECU_LOCATION_ID, &RequestResultPtr);
  } while (RequestResultPtr == NVM_REQ_PENDING);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitZero>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverInitZero  */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
* EcuM_AL_DriverInitOne_Left
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_Left(void)
{
  if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
  {
      PduR_PreInit( PduR_Config_Right_Ptr );
      BswM_PreInit( BswM_Config_Right_Ptr );
  }
  else
  {
      PduR_PreInit( PduR_Config_Left_Ptr );
      BswM_PreInit( BswM_Config_Left_Ptr );
  }

  E2EXf_Init( NULL_PTR );

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_Left>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverInitOne  */

  Mcu_InitClock( 0u );
  while( Mcu_GetPllStatus() != MCU_PLL_LOCKED );
  Mcu_DistributePllClock();
#if !defined(_MICROSOFT_C_VTT_) && (CRYPTO_30_VHSM_INTERRUPT_MODE == STD_ON)
  /* Enable interrupts from HSM */
  HSM_BRIDGE->HSM2HTF = 0xFFFFFFFFu;
  HSM_BRIDGE->HSM2HTIE = 0xFFFFFFFFu; // HSM2HTIE, enable Interrupts from Bridge to Host
  __enable();
#endif /* !defined(VTT) && (CRYPTO_30_VHSM_INTERRUPT_MODE == STD_ON) */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
* EcuM_AL_DriverInitOne_Right
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_Right(void)
{
    EcuM_AL_DriverInitOne_Left();
}

#if (ECUM_SLEEPMODELIST == STD_ON)
/**********************************************************************************************************************
* EcuM_AL_DriverRestartList
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList(void) 
{
  /* DriverRestartList will not be called () because no sleepmode is configured - So don't use this function! */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverRestartList  */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif




FUNC(void, ECUM_CODE) EcuM_StartOS(AppModeType appMode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartOS>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_StartOS() */
#if ( ECUM_NUMBER_OF_CORES > 1 )
  uint8 coreId;
  StatusType status;
  if(GetCoreID()==ECUM_CORE_ID_STARTUP)
  {
    for(coreId=0; coreId < ECUM_NUMBER_OF_CORES; coreId++)
    {
      if(coreId!=ECUM_CORE_ID_STARTUP)
      {
        StartCore(coreId, &status); /* SBSW_ECUM_ADRESSPARAMETER_TOOS */
      }
    }
  }
#endif

  /* Start OS must be called for each core */
  StartOS(appMode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StartOS() */

FUNC(void, ECUM_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_AL_SetProgrammableInterrupts() */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_SetProgrammableInterrupts() */

#if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
FUNC(EcuM_GlobalConfigRefType, ECUM_CODE) EcuM_DeterminePbConfiguration(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DeterminePbConfiguration>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_DeterminePbConfiguration() */
   EcuM_GlobalConfigRefType globalConfig;

   if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
   {
       globalConfig =  &EcuM_GlobalConfigRoot.Right;
   }
   else
   {
       globalConfig =  &EcuM_GlobalConfigRoot.Left;
   }

   return globalConfig;
  
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_DeterminePbConfiguration() */
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
FUNC(void, ECUM_CODE) EcuM_GptStartClock(Gpt_ChannelType GptChannel, Gpt_ModeType Mode, Gpt_ValueType Value)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptStartClock>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptStartClock() */

  Gpt_EnableNotification(GptChannel);
  Gpt_StartTimer(GptChannel, Value);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptStartClock() */
#endif




/**********************************************************************************************************************
 *  CALLOUTS FROM THE SLEEP PHASE
 *********************************************************************************************************************/



#if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
FUNC(void, ECUM_CODE) EcuM_WaitForSlaveCores(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_WaitForSlaveCores>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_WaitForSlaveCores() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_WaitForSlaveCores() */
#endif

#if(ECUM_SLEEPMODELIST == STD_ON)

FUNC(void, ECUM_CODE) EcuM_GenerateRamHash(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GenerateRamHash>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GenerateRamHash() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GenerateRamHash() */

FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckRamHash>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_CheckRamHash() */
  
  return (1u);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckRamHash() */

FUNC(void, ECUM_CODE) EcuM_McuSetMode(Mcu_ModeType McuMode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_McuSetMode>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_McuSetMode() */
  Mcu_SetMode(McuMode);
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_McuSetMode() */

#if(ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
FUNC(void, ECUM_CODE) EcuM_SleepActivity(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_SleepActivity>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_SleepActivity() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_SleepActivity() */
#endif

FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_EnableWakeupSources>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_EnableWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_EnableWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DisableWakeupSources>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_DisableWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_DisableWakeupSources() */
#endif

FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource) /* COV_ECUM_CALLOUT */
{
#if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
  /* Do not remove the following function call. It is necessary for the CheckWakeup timeout mechanism */
  EcuM_StartCheckWakeup(wakeupSource);
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
  if((ECUM_ALARM_WKSOURCE & wakeupSource) != 0u)
  {
    EcuM_AlarmCheckWakeup();
  }
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckWakeup>                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
  {
      if ((wakeupSource & ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727) != 0)
      {
        (void)CanIf_CheckWakeup(ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727);
        CanSM_PreventBusSleepAtStartUp(ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727);
      }
  }
  else
  {
      if ((wakeupSource & ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6) != 0)
      {
        (void)CanIf_CheckWakeup(ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6);
        CanSM_PreventBusSleepAtStartUp(ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6);
      }
  }

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckWakeup() */

#if ((ECUM_ALARM_CLOCK_PRESENT == STD_ON) && (ECUM_SLEEPMODELIST == STD_ON))
FUNC(void, ECUM_CODE) EcuM_GptSetNormal(Gpt_ChannelType GptChannel, Gpt_ModeType Mode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptSetNormal>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptSetNormal() */

  Gpt_EnableNotification(GptChannel);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptSetNormal() */

FUNC(void, ECUM_CODE) EcuM_GptSetSleep(Gpt_ChannelType GptChannel, Gpt_ModeType Mode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptSetSleep>                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptSetSleep() */

  Gpt_EnableWakeup(GptChannel);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptSetSleep() */
#endif



/**********************************************************************************************************************
 *  CALLOUTS FROM THE UP PHASE
 *********************************************************************************************************************/

#if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)

FUNC(void, ECUM_CODE) EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartWakeupSources>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
  {
      if ((wakeupSource & ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727) != 0)
      {
        /* Channel handle can be found in ComM_Cfg.h */
        (void)CanSM_StartWakeupSources(ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727);
      }
  }
  else
  {
      if ((wakeupSource & ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6) != 0)
      {
        /* Channel handle can be found in ComM_Cfg.h */
        (void)CanSM_StartWakeupSources(ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6);
      }
  }

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StartWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StopWakeupSources>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
  {
      if ((wakeupSource & ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727) != 0)
      {
        (void)CanSM_StopWakeupSources(ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727, ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727);
      }
  }
  else
  {
      if ((wakeupSource & ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6) != 0)
      {
        (void)CanSM_StopWakeupSources(ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6, ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6);
      }
  }

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StopWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckValidation>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  if (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation == ECU_SIDE_RBTM_FR)
  {
      if (((wakeupSource & ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727) != 0))
      {
        (void)CanIf_CheckValidation(ECUM_WKSOURCE_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727);
      }
  }
  else
  {
      if (((wakeupSource & ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6) != 0))
      {
        (void)CanIf_CheckValidation(ECUM_WKSOURCE_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6);
      }
  }

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckValidation() */

#endif



#if (ECUM_BSW_ERROR_HOOK == STD_ON)
/**********************************************************************************************************************
 *  Errorhook for BSW errors during initialization
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_BswErrorHook(uint16 BswModuleId, uint8 ErrorId) /* PRQA S 3206 */ /* MD_EcuM_3206 */ /* COV_ECUM_CALLOUT */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_BswErrorHook>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)BswModuleId;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  (void)ErrorId;      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_BswErrorHook() */
  
  if(BswModuleId == ECUM_MODULE_ID)
  {
    /* Abort initialization per default if the EcuM has reported an BswError */
    while(1)
    {
    }
  }

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_BswErrorHook() */
#endif

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: ECUM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


