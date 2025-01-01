/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file  File:  BrsMain.c
 *      Project:  Vector Basic Runtime System
 *       Module:  BrsMain
 *
 *  \brief Description:  Main file of BRS contains
 *                       - Main function (called from StartUpCode and calls stack entry EcuM_Init())
 *                       - Call of BrsHw HW initialization routines
 *                       - 1ms handler, with support of cycle functions with several cycle times
 *                       - Exception handling
 *                       - Default_Init_Task, Main and Background Task which can be used by the operating system
 *
 *  \attention Please note:
 *    The demo and example programs only show special aspects of the software. With regard to the fact
 *    that these programs are meant for demonstration purposes only, Vector Informatik liability shall be
 *    expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to BrsMain.h.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#define _BRSMAIN_C_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "BrsMain.h"

#if !defined (_MICROSOFT_C_VTT_)
  #include "BrsHw.h"
# if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
  #include "vBrs_Lcfg.h"
# endif
#else
  #include "CANoeAPI.h"
  #include <stdio.h>
  #include "Os.h"
#endif


#if defined (BRS_ENABLE_TESTSUITE_SUPPORT)
  #include "BrsTestsuite.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (BRSMAIN_VERSION != 0x0205u)
  #error "Header and source file are inconsistent!"
#endif
#if (BRSMAIN_BUGFIX_VERSION != 0x04u)
  #error "Different versions of bugfix in Header and Source used!"
#endif

/**********************************************************************************************************************
 *  CONFIGURATION CHECK
 *********************************************************************************************************************/
#if defined (BRS_ENABLE_OS_INTERRUPT_ONLY) && defined (BRS_ENABLE_OS_MULTICORESUPPORT)
  #error "OS MultiCore support is not supported together with OS INTERRUPT_ONLY UseCase!"
#endif

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
  #error "This file was filtered for SingleCore UseCase, but MultiCore UseCase is configured!"
#endif

/**********************************************************************************************************************
 *  DEFINITION + MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/
#if defined (BRS_ENABLE_1MS_HANDLER)
  #define BRSMAIN_CYCLIC_MAX_CALLBACKS 2u

  #define START_SEC_VAR_NOINIT_UNSPECIFIED
  #include "MemMap.h"
  typedef struct
  {
    void (*FunctionPointer[BRSMAIN_CYCLIC_MAX_CALLBACKS]) (void);
    uint8 FunctionCounter;
  }brsMain_Cyclic_Callbacks;
  #define STOP_SEC_VAR
  #include "MemMap.h"
#endif /*BRS_ENABLE_1MS_HANDLER*/


/**********************************************************************************************************************
 *  GLOBAL CONST VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/
#if defined (BRS_ENABLE_1MS_HANDLER)
  #define START_SEC_VAR_ZERO_INIT_16BIT
  #include "MemMap.h"
  /**
   * \var brsMain_CallCounter1ms
   *      Counter for calls of the function BrsMainCyclic1ms
   */
  static volatile uint16 brsMain_CallCounter1ms;

  /**
   * \var brsMain_CallCounter1sec
   *      Counter for 1000 calls of the function BrsMainCyclic1ms
   */
  static volatile uint16 brsMain_CallCounter1sec;
  #define STOP_SEC_VAR
  #include "MemMap.h"

  #define START_SEC_VAR_NOINIT_UNSPECIFIED
  #include "MemMap.h"
  static brsMain_Cyclic_Callbacks brsMain_Cyclic_Callbacks_Background;
  static brsMain_Cyclic_Callbacks brsMain_Cyclic_Callbacks_1ms;
  static brsMain_Cyclic_Callbacks brsMain_Cyclic_Callbacks_10ms;
  static brsMain_Cyclic_Callbacks brsMain_Cyclic_Callbacks_100ms;
  static brsMain_Cyclic_Callbacks brsMain_Cyclic_Callbacks_250ms;
  static brsMain_Cyclic_Callbacks brsMain_Cyclic_Callbacks_500ms;
  static brsMain_Cyclic_Callbacks brsMain_Cyclic_Callbacks_1000ms;
  #define STOP_SEC_VAR
  #include "MemMap.h"
#endif /*BRS_ENABLE_1MS_HANDLER*/

#if defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
  #define START_SEC_VAR_ZERO_INIT_32BIT
  #include "MemMap.h"
  static volatile uint32 brsMain_SuspendAllCounter;
  #define STOP_SEC_VAR
  #include "MemMap.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONST VARIABLES
 *********************************************************************************************************************/
# if defined (_MICROSOFT_C_VTT_)
  #define BRSMAIN_ERRORBUFFERSIZE  120
#endif

/**********************************************************************************************************************
 *  PROTOTYPES OF GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#if defined (BRS_FBL_NO_ECUMINIT)
extern void FblMain(void);
#endif

/**********************************************************************************************************************
 *  PROTOTYPES OF LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#if !defined (_MICROSOFT_C_VTT_)
# if defined (BRS_ENABLE_SUPPORT_LEDS)
void BrsMainWrapperTogglePinLED(void)
{
  BrsMainTogglePin(BRSMAIN_TOGGLEPIN_LED);
}
# endif

# if defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN)
void BrsMainWrapperTogglePinWD(void)
{
  BrsMainTogglePin(BRSMAIN_TOGGLEPIN_WD);
}
# endif

# if defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
void BrsMainWrapperTogglePinCustom(void)
{
  BrsMainTogglePin(BRSMAIN_TOGGLEPIN_CUSTOM);
}
# endif
#endif /*!_MICROSOFT_C_VTT_*/

/*****************************************************************************/
/* @brief      Main initialization routine.
 *             Contains initialisation of BRSModules and BrsMain specific initialization
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called from main
 *****************************************************************************/
void BrsMainInit(void)
{
#if defined (BRSMAIN_BRSMAININIT_CALLOUT)
  BrsTestsuite_BrsMain_BrsMainInit();
#endif


#if !defined (BRS_FBL_NO_ECUMINIT) && !defined (BRS_FBL_WITH_ECUMINIT) && !defined (_MICROSOFT_C_VTT_)
# if !defined (BRS_ENABLE_PREFER_PLL_WATCHDOG_INIT)
  /* If preferred feature is acivated, initialization will take place in BrsMain_MemoryInit_StageOne_Hook(). */
#  if defined (BRSHW_PREINIT_AVAILABLE)
  BrsHwPreInitPowerOn();
#  endif

#  if defined (BRS_ENABLE_WATCHDOG)
  BrsHwWatchdogInitPowerOn();
#  endif

#  if defined (BRS_ENABLE_PLLCLOCKS)
  BrsHwPllInitPowerOn();
#  endif
# endif /*!BRS_ENABLE_PREFER_PLL_WATCHDOG_INIT*/

# if defined (BRS_ENABLE_PORT)
  BrsHwPortInitPowerOn();
# endif

# if defined (BRS_ENABLE_FBL_SUPPORT)
#  if defined (BRSHW_DISABLE_ECC_AVAILABLE)
  BrsHwDisableEccErrorReporting();
#  endif
# endif
#endif /*!BRS_FBL_NO_ECUMINIT&&!BRS_FBL_WITH_ECUMINIT&&!_MICROSOFT_C_VTT_*/

#if defined (BRS_ENABLE_1MS_HANDLER)
  brsMain_CallCounter1ms = 0u;
  brsMain_CallCounter1sec = 0u;

  brsMain_Cyclic_Callbacks_Background.FunctionCounter = 0u;
  brsMain_Cyclic_Callbacks_1ms.FunctionCounter        = 0u;
  brsMain_Cyclic_Callbacks_10ms.FunctionCounter       = 0u;
  brsMain_Cyclic_Callbacks_100ms.FunctionCounter      = 0u;
  brsMain_Cyclic_Callbacks_250ms.FunctionCounter      = 0u;
  brsMain_Cyclic_Callbacks_500ms.FunctionCounter      = 0u;
  brsMain_Cyclic_Callbacks_1000ms.FunctionCounter     = 0u;
#endif /*BRS_ENABLE_1MS_HANDLER*/

#if !defined (_MICROSOFT_C_VTT_)
# if defined (BRS_ENABLE_SUPPORT_LEDS)
  BrsMainRegisterCyclic(BrsMainWrapperTogglePinLED, BRSMAIN_CYCLETIME_500MS);
# endif

# if defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN)
  BrsMainRegisterCyclic(BrsMainWrapperTogglePinWD, BRSMAIN_CYCLETIME_250MS);
# endif

# if defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
  BrsMainRegisterCyclic(BrsMainWrapperTogglePinCustom, BRSMAIN_CYCLETIME_1000MS);
# endif
#endif /*!_MICROSOFT_C_VTT_*/

#if defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
  brsMain_SuspendAllCounter = 0u;
#endif
}

#if defined (BRS_ENABLE_1MS_HANDLER)
/*****************************************************************************/
/* @brief      Routine to register cyclic callbacks.
 * @pre        Initialization of BrsMain was done threw call of BrsMainInit().
 * @param[in]  FunctionPointer has to be a pointer to a function of type
 *             void function(void).
 * @param[in]  Cycletime described the cycletime, the callback should be triggered.
 * @param[out] -
 * @return     -
 * @context    Function is called from modules that need cyclic callbacks.
 *****************************************************************************/
void BrsMainRegisterCyclic(void (*FunctionPointer)(void), brsMain_Cyclic_Cycletime Cycletime)
{
#if defined (BRSMAIN_BRSMAINREGISTERCYCLIC_CALLOUT)
  BrsTestsuite_BrsMain_BrsMainRegisterCyclic(FunctionPointer, Cycletime);
#endif

  switch (Cycletime)
  {
    case BRSMAIN_CYCLETIME_BACKGROUND:
      if (brsMain_Cyclic_Callbacks_Background.FunctionCounter >= BRSMAIN_CYCLIC_MAX_CALLBACKS)
        BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
      brsMain_Cyclic_Callbacks_Background.FunctionPointer[brsMain_Cyclic_Callbacks_Background.FunctionCounter] = FunctionPointer;
      brsMain_Cyclic_Callbacks_Background.FunctionCounter++;
      break;

    case BRSMAIN_CYCLETIME_1MS:
      if (brsMain_Cyclic_Callbacks_1ms.FunctionCounter >= BRSMAIN_CYCLIC_MAX_CALLBACKS)
        BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
      brsMain_Cyclic_Callbacks_1ms.FunctionPointer[brsMain_Cyclic_Callbacks_1ms.FunctionCounter] = FunctionPointer;
      brsMain_Cyclic_Callbacks_1ms.FunctionCounter++;
      break;

    case BRSMAIN_CYCLETIME_10MS:
      if (brsMain_Cyclic_Callbacks_10ms.FunctionCounter >= BRSMAIN_CYCLIC_MAX_CALLBACKS)
        BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
      brsMain_Cyclic_Callbacks_10ms.FunctionPointer[brsMain_Cyclic_Callbacks_10ms.FunctionCounter] = FunctionPointer;
      brsMain_Cyclic_Callbacks_10ms.FunctionCounter++;
      break;

    case BRSMAIN_CYCLETIME_100MS:
      if (brsMain_Cyclic_Callbacks_100ms.FunctionCounter >= BRSMAIN_CYCLIC_MAX_CALLBACKS)
        BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
      brsMain_Cyclic_Callbacks_100ms.FunctionPointer[brsMain_Cyclic_Callbacks_100ms.FunctionCounter] = FunctionPointer;
      brsMain_Cyclic_Callbacks_100ms.FunctionCounter++;
      break;

    case BRSMAIN_CYCLETIME_250MS:
      if (brsMain_Cyclic_Callbacks_250ms.FunctionCounter >= BRSMAIN_CYCLIC_MAX_CALLBACKS)
        BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
      brsMain_Cyclic_Callbacks_250ms.FunctionPointer[brsMain_Cyclic_Callbacks_250ms.FunctionCounter] = FunctionPointer;
      brsMain_Cyclic_Callbacks_250ms.FunctionCounter++;
      break;

    case BRSMAIN_CYCLETIME_500MS:
      if (brsMain_Cyclic_Callbacks_500ms.FunctionCounter >= BRSMAIN_CYCLIC_MAX_CALLBACKS)
        BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
      brsMain_Cyclic_Callbacks_500ms.FunctionPointer[brsMain_Cyclic_Callbacks_500ms.FunctionCounter] = FunctionPointer;
      brsMain_Cyclic_Callbacks_500ms.FunctionCounter++;
      break;

    case BRSMAIN_CYCLETIME_1000MS:
      if (brsMain_Cyclic_Callbacks_1000ms.FunctionCounter >= BRSMAIN_CYCLIC_MAX_CALLBACKS)
        BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
      brsMain_Cyclic_Callbacks_1000ms.FunctionPointer[brsMain_Cyclic_Callbacks_1000ms.FunctionCounter] = FunctionPointer;
      brsMain_Cyclic_Callbacks_1000ms.FunctionCounter++;
      break;

    default:
      BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
      break;
  }
}
#endif /*BRS_ENABLE_1MS_HANDLER*/

#if !defined (BRS_ENABLE_FBL_SUPPORT) && !defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
/*****************************************************************************/
/* @brief      InitTask to call EcuM_StartupTwo().
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    The task is started once by the OS.
 *****************************************************************************/
TASK(Default_Init_Task)
{
#if defined (BRSMAIN_DEFAULT_INIT_TASK_CALLOUT)
  BrsTestsuite_BrsMain_Default_Init_Task();
#endif

#if defined (BRS_ENABLE_OS_MULTICORESUPPORT)
  /* Workaround for RTE ESCAN00078832 */
  /* Use this code, if you get a Det Error at the end of Rte_Start() on MasterCore */
  /* Rte_Start() on the SlaveCores has to be called first, before Rte_Start() on MasterCore */
  /* SET THIS InitTask TO FULL PREEMPTIVE (OsTaskSchedule) within OsConfig! */
  /*while(Rte_InitState_1 != RTE_STATE_INIT)
  {
    (void)Schedule();
  }*/
#endif /*BRS_ENABLE_OS_MULTICORESUPPORT*/

#if defined (BRS_ENABLE_TESTSUITE_SUPPORT)
  BrsTestsuiteInit();
#endif

#if defined (BRS_ENABLE_HSM_SUPPORT)
  vHsm_StartupTwo();
#else
  EcuM_StartupTwo();
#endif

  (void)TerminateTask();
}

/*****************************************************************************/
/* @brief      InitTask to call Os_InitialEnableInterruptSources().
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    The task is started once by the OS. It is separated from
 *             Default_Init_Task() to allow the SafeContext partitioning UseCase.
 *****************************************************************************/
TASK(Default_Init_Task_Trusted)
{
#if defined (BRSMAIN_DEFAULT_INIT_TASK_TRUSTED_CALLOUT)
  BrsTestsuite_BrsMain_Default_Init_Task_Trusted();
#endif

  Os_InitialEnableInterruptSources(FALSE);

  (void)TerminateTask();
}

#endif /*!BRS_ENABLE_FBL_SUPPORT&&!BRS_ENABLE_OS_INTERRUPT_ONLY*/

#if defined (BRS_ENABLE_1MS_HANDLER)
/*****************************************************************************/
/* @brief      One millisecond handler for BrsMain
 *               - Executes retransmission of BRS TCC messages
 *               - Toggling of LED (alive signal)
 *               - BRS Test code (1s cyclic negative TCC response message)
 * @pre        Initialization of BrsMain was done threw call of BrsMainInit().
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Function is called each millisecond either from the main loop
 *             or from the BRS main task (TASK(mainTask))
 *****************************************************************************/
void BrsMainCyclic1ms(void)
{
  uint8 cycliccounter;

#if defined (BRSMAIN_BRSMAINCYCLIC1MS_CALLOUT)
  BrsTestsuite_BrsMain_BrsMainCyclic1ms();
#endif

  brsMain_CallCounter1ms++;

  for (cycliccounter=0u; cycliccounter<brsMain_Cyclic_Callbacks_1ms.FunctionCounter; cycliccounter++)
    brsMain_Cyclic_Callbacks_1ms.FunctionPointer[cycliccounter]();

  if (brsMain_CallCounter1ms %10 == 0)
  {
    for (cycliccounter=0u; cycliccounter<brsMain_Cyclic_Callbacks_10ms.FunctionCounter; cycliccounter++)
      brsMain_Cyclic_Callbacks_10ms.FunctionPointer[cycliccounter]();
  }

  if (brsMain_CallCounter1ms %100 == 0)
  {
    for (cycliccounter=0u; cycliccounter<brsMain_Cyclic_Callbacks_100ms.FunctionCounter; cycliccounter++)
      brsMain_Cyclic_Callbacks_100ms.FunctionPointer[cycliccounter]();
  }

  if (brsMain_CallCounter1ms %250 == 0)
  {
    for (cycliccounter=0u; cycliccounter<brsMain_Cyclic_Callbacks_250ms.FunctionCounter; cycliccounter++)
      brsMain_Cyclic_Callbacks_250ms.FunctionPointer[cycliccounter]();
  }

  if (brsMain_CallCounter1ms %500 == 0)
  {
    for (cycliccounter=0u; cycliccounter<brsMain_Cyclic_Callbacks_500ms.FunctionCounter; cycliccounter++)
      brsMain_Cyclic_Callbacks_500ms.FunctionPointer[cycliccounter]();
  }

  if (brsMain_CallCounter1ms %1000 == 0)
  {
    for (cycliccounter=0u; cycliccounter<brsMain_Cyclic_Callbacks_1000ms.FunctionCounter; cycliccounter++)
      brsMain_Cyclic_Callbacks_1000ms.FunctionPointer[cycliccounter]();
    brsMain_CallCounter1ms = 0u;
    brsMain_CallCounter1sec++;
  }
}

# if !defined (BRS_ENABLE_FBL_SUPPORT) && !defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
/*****************************************************************************/
/* @brief      BrsMainTask executes the 1 millisecond handler
 *             The function initiates calls to BrsMainCyclic1ms
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    The task is started once by the OS and activated by
 *             the OS event EvCyclicAlarm_1ms
 *****************************************************************************/
TASK(BrsMainTask)
{
  EventMaskType ev;

#if defined (BRSMAIN_BRSMAINTASK_CALLOUT)
  BrsTestsuite_BrsMain_BrsMainTask();
#endif

  (void)SetRelAlarm(BrsCyclicAlarm_1ms, OS_MS2TICKS_SystemTimer(1), OS_MS2TICKS_SystemTimer(1));

  for(;;)
  {
    (void)WaitEvent(BrsEvCyclicAlarm_1ms);
    (void)GetEvent(BrsMainTask, &ev);
    (void)ClearEvent(ev);
    if(ev & BrsEvCyclicAlarm_1ms)
    {
      /* 1ms event detected, call the ms handler */
      BrsMainCyclic1ms();
    }
  }
}

TASK(BrsMainBackgroundTask)
{
  uint8 cycliccounter;

#if defined (BRSMAIN_BRSMAINBACKGROUNDTASK_CALLOUT)
  BrsTestsuite_BrsMain_BrsMainBackgroundTask();
#endif

  for(;;)
  {
# if defined (_MICROSOFT_C_VTT_)
    CANoeAPI_ConsumeTicks(100);
# endif

    for (cycliccounter=0u; cycliccounter<brsMain_Cyclic_Callbacks_Background.FunctionCounter; cycliccounter++)
      brsMain_Cyclic_Callbacks_Background.FunctionPointer[cycliccounter]();

    (void)Schedule();
  }
}
# endif /*!BRS_ENABLE_FBL_SUPPORT&&!BRS_ENABLE_OS_INTERRUPT_ONLY*/
#endif /*BRS_ENABLE_1MS_HANDLER*/


#if defined (BRS_ENABLE_SUPPORT_LEDS)          || \
    defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN) || \
    defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
# if !defined (BRS_ENABLE_PORT)
  #define BRSHW_PORT_LOGIC_HIGH STD_HIGH
  #define BRSHW_PORT_LOGIC_LOW STD_LOW
# endif
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
/*****************************************************************************/
/* @brief      This API is used to toggle a PortPin.
 *             Per default, the following parameters are available:
 *               BRSMAIN_TOGGLEPIN_LED
 *               BRSMAIN_TOGGLEPIN_WD
 *               BRSMAIN_TOGGLEPIN_CUSTOM
 *             Depending pins must be configured and initialized within BrsHw.
 * @pre        -
 * @param[in]  Pin to be toggled
 * @param[out] -
 * @return     -
 * @context    Function is called from all modules to set or clear a PortPin
 *****************************************************************************/
void BrsMainTogglePin(brsMain_TogglePin Pin)
{
  #define START_SEC_VAR_NOINIT_UNSPECIFIED
  #include "MemMap.h"
#if defined (BRS_ENABLE_SUPPORT_LEDS)
  static uint8 BrsMain_ToggleSwitch_LED = BRSHW_PORT_LOGIC_HIGH;
#endif
#if defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN)
  static uint8 BrsMain_ToggleSwitch_WD = BRSHW_PORT_LOGIC_HIGH;
#endif
#if defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
  static uint8 BrsMain_ToggleSwitch_CUSTOM = BRSHW_PORT_LOGIC_HIGH;
#endif
  #define STOP_SEC_VAR
  #include "MemMap.h"

  switch (Pin)
  {
#if defined (BRS_ENABLE_SUPPORT_LEDS)
    case BRSMAIN_TOGGLEPIN_LED:
# if defined (BRS_ENABLE_PORT)
      BrsHwPort_SetLevel(BRSHW_PORT_LED, BrsMain_ToggleSwitch_LED & 0x01);
# else
      Dio_WriteChannel(BrsHw_DioChannel_ToggleLED, BrsMain_ToggleSwitch_LED & 0x01);
# endif
      BrsMain_ToggleSwitch_LED++;
      break;
#endif /*BRS_ENABLE_SUPPORT_LEDS*/
#if defined (BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN)
    case BRSMAIN_TOGGLEPIN_WD:
# if defined (BRS_ENABLE_PORT)
      BrsHwPort_SetLevel(BRSHW_PORT_TOGGLE_WD, BrsMain_ToggleSwitch_WD & 0x01);
# else
      Dio_WriteChannel(BrsHw_DioChannel_ToggleWdPin, BrsMain_ToggleSwitch_WD & 0x01);
# endif
      BrsMain_ToggleSwitch_WD++;
      break;
#endif /*BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN*/
#if defined (BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN)
    case BRSMAIN_TOGGLEPIN_CUSTOM:
# if defined (BRS_ENABLE_PORT)
      BrsHwPort_SetLevel(BRSHW_PORT_TOGGLE_CUSTOM, BrsMain_ToggleSwitch_CUSTOM & 0x01);
# else
      Dio_WriteChannel(BrsHw_DioChannel_ToggleCustomPin, BrsMain_ToggleSwitch_CUSTOM & 0x01);
# endif
      BrsMain_ToggleSwitch_CUSTOM++;
      break;
#endif /*BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN*/
    default:
      BrsMainExceptionHandler(kBrsIllegalParameter, BRSERROR_MODULE_BRSHW, (uint16)(__LINE__));
      break;
  }
}
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
#endif /*BRS_ENABLE_SUPPORT_LEDS||BRS_ENABLE_SUPPORT_TOGGLE_WD_PIN||BRS_ENABLE_SUPPORT_TOGGLE_CUSTOM_PIN*/

#if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CODE
  #include "Brs_MemMap.h"
#endif
/*****************************************************************************/
/* @brief      This is the central exeption handler of BRS.
 *             All BRS modules and all CANbedded specific fatal error handler will
 *             call this API in case an assertion has failed.
 * @pre        -
 * @param[in]  ErrorCode shall hold the caller specific error code (uint8)
 * @param[in]  ModuleCode shall describe the caller; please use the CI constant as parameter (uint8)
 * @param[in]  LineNumber shall be the line where the assertion has failed, or,
 *             if not available on caller location, the line where this API is
 *             called from
 * @param[out] -
 * @return     -
 * @context    This function implements an endless loop with locked interrupts.
 *             The recommendation is to set a breakpoint on top of this function
 *             to see if any assertion has failed during the code execution.
 *             Due to an assertion has failed and the endless loop runs with
 *             locked global interrupts there will be no life after the call ...
 *****************************************************************************/
void BrsMainExceptionHandler(uint8 ErrorCode, uint8 ModuleCode, uint16 LineNumber)
{
#if defined (BRSMAIN_BRSMAINEXCEPTIONHANDLER_CALLOUT)
  BrsTestsuite_BrsMain_BrsMainExceptionHandler();
#endif

#if defined (BRS_ENABLE_SAFECTXSUPPORT)
  while(1)
  {}

#else
# if defined (_MICROSOFT_C_VTT_)
  char error[BRSMAIN_ERRORBUFFERSIZE];

  sprintf_s(error, BRSMAIN_ERRORBUFFERSIZE, "BrsMainExceptionHandler Code: [0x%x] ModuleCode: [0x%x] LineNumber: [0x%x]", ErrorCode, ModuleCode, LineNumber);

  CANoeAPI_WriteString(error);
  ShutdownOS(0);

# else
  volatile uint8 BrsMain_Continue;
  BrsMain_Continue = 0;

#if !defined (BRS_ENABLE_FBL_SUPPORT) /* FBL is always running in polling mode with interrupts disabled */
  DisableAllInterrupts();
#endif

  while (BrsMain_Continue == 0)
  {
    /* Set BrsMain_Continue to 1 to continue here.
     *  If the debugger is not able to show the stack properly, this mechanism can be used to find the
     *  source of the exception. */
  }
# endif /*_MICROSOFT_C_VTT_*/
#endif /*BRS_ENABLE_SAFECTXSUPPORT*/
}
#if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
#endif

/*****************************************************************************/
/* @brief      This is just a wrapper to ease calls to
 *             BrsMainExceptionHandler() from assembler StartUpCode.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    This function will call BrsMainExceptionHandler() with the
 *             error code for reaching illegal assembler in StartUpCpde.
 *****************************************************************************/
void BrsMainExceptionStartup(void)
{
  BrsMainExceptionHandler(kBrsIllegalAssemblerReached, BRSERROR_MODULE_BRSSTARTUP, (uint16)0);
}

#if defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
  /* OS is configured for UseCase Interrupt Only (/MICROSAR/Os/OsOS/OsUseCase) */
/*****************************************************************************/
/* @brief      With OS UseCase "Interrupt Only" (/MICROSAR/Os/OsOS/OsUseCase),
 *             the default API SuspendAllInterrupts() is not functional.
 *             Instead, this wrapper function is handling nested calls and the
 *             alternative suspend API call.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Called by vBrs generated SchM stub in OS UseCase Interrupt Only.
 *****************************************************************************/
void BrsMainSuspendAllInterrupts(void)
{
  if (brsMain_SuspendAllCounter==0u)
  {
    DisableAllInterrupts();
  }

  brsMain_SuspendAllCounter++;
}

/*****************************************************************************/
/* @brief      With OS UseCase "Interrupt Only" (/MICROSAR/Os/OsOS/OsUseCase),
 *             the default API ResumeAllInterrupts() is not functional.
 *             Instead, this wrapper function is handling nested calls and the
 *             alternative resume API call.
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     -
 * @context    Called by vBrs generated SchM stub in OS UseCase Interrupt Only.
 *****************************************************************************/
void BrsMainResumeAllInterrupts(void)
{
  if (brsMain_SuspendAllCounter!=0u)
  {
    brsMain_SuspendAllCounter--;

    if (brsMain_SuspendAllCounter==0u)
    {
      EnableAllInterrupts();
    }
  }
}
#endif /*BRS_ENABLE_OS_INTERRUPT_ONLY*/

#if defined (BRS_ENABLE_FBL_SUPPORT)
  extern uint32 _brsExcVectRam_START;
#endif

/*****************************************************************************/
/*@brief      Main function
 * @pre        -
 * @param[in]  -
 * @param[out] -
 * @return     always 0 as the function is not expected to return
 * @context    Called by the startup code
 *****************************************************************************/
int main(void)
{
#if !defined (_MICROSOFT_C_VTT_)
# if (BRS_CPU_CORE_AMOUNT>1) || (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
  uint32 coreID = BrsHw_GetCore();
# endif
# if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u) && !defined (BRS_ENABLE_FBL_SUPPORT)
  uint32 i;
# endif
#endif /*!_MICROSOFT_C_VTT_*/

#if defined (BRSMAIN_MAIN_CALLOUT)
  BrsTestsuite_BrsMain_main();
#endif

#if !defined (_MICROSOFT_C_VTT_)
  BrsHwDisableInterruptAtPowerOn();

# if (BRSHW_SOURCECODE_TEMPLATE_VERSION >= 0x0103u)
#  if defined (BRS_ENABLE_FBL_SUPPORT)
  BrsHw_ExceptionTable_Init((uint32)&_brsExcVectRam_START, BRS_DEFINE_ADDRESS_UNUSED);
#  else
  for (i=0; i<BrsMain_CoreConfig_Size; i++)
  {
    if (BrsMain_CoreConfig[i].PhysicalCoreId == coreID)
    {
      BrsHw_ExceptionTable_Init((uint32)BrsMain_CoreConfig[i].ExcVecLabel, (uint32)BrsMain_CoreConfig[i].IntVecLabel);
      i=BrsMain_CoreConfig_Size+1;
    }
  }

  /* Check, if no valid core config was found */
  if (i==BrsMain_CoreConfig_Size)
    BrsMainExceptionHandler(kBrsInvalidCoreConfig, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));
#  endif
# endif /*BRSHW_SOURCECODE_TEMPLATE_VERSION>=0x0103u*/

# if (BRS_CPU_CORE_AMOUNT>1)
  if (coreID == BRSHW_INIT_CORE_ID)
# endif
#endif /*!_MICROSOFT_C_VTT_*/
  {
    BrsMainInit();
  }

#if defined (BRS_FBL_NO_ECUMINIT)
  FblMain();

#else
# if !defined (BRS_ENABLE_FBL_SUPPORT) || defined (_MICROSOFT_C_VTT_)
#  if defined (BRS_ENABLE_OS_INTERRUPT_ONLY)
  /* OS is configured for UseCase Interrupt Only (/MICROSAR/Os/OsOS/OsUseCase) */
  Os_InitInterruptOnly();
#  else
  Os_InitMemory();
  Os_Init();
#  endif
# endif

# if defined (BRS_ENABLE_HSM_SUPPORT)
  vHsm_Init();
# else
  EcuM_Init(); /* never returns */
# endif
#endif /*else BRS_FBL_NO_ECUMINIT*/

  BrsMainExceptionHandler(kBrsIllegalReturnFromMain, BRSERROR_MODULE_BRSMAIN, (uint16)(__LINE__));

  return 0;
}

/***********************************************************************************************************************
 *  Additional UserCode can be placed here
 **********************************************************************************************************************/

