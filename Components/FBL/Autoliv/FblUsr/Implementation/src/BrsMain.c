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
#else
  #include "CANoeAPI.h"
  #include <stdio.h>
  #include "Os.h"
#endif

#if defined (BRS_ENABLE_CAN_SUPPORT)
  #include BRS_DRVCAN_HEADER_FILENAME
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

/**********************************************************************************************************************
 *  DEFINITION + MACROS
 *********************************************************************************************************************/

#define BRSHW_DISABLE_ECC_AVAILABLE

/**********************************************************************************************************************
 *  GLOBAL VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONST VARIABLES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL VARIABLES
 *********************************************************************************************************************/

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

# if defined (BRS_ENABLE_FBL_SUPPORT)
#  if defined (BRSHW_DISABLE_ECC_AVAILABLE)
  BrsHwDisableEccErrorReporting();
#  endif
# endif

#if !defined (BRS_FBL_NO_ECUMINIT) && !defined (BRS_FBL_WITH_ECUMINIT) && !defined (_MICROSOFT_C_VTT_)
# if !defined (BRS_ENABLE_PREFER_PLL_WATCHDOG_INIT)
  /* If preferred feature is acivated, initialization will take place in BrsMain_MemoryInit_StageOne_Hook(). */
#  if defined (BRS_ENABLE_WATCHDOG)
  //BrsHwWatchdogInitPowerOn();
#  endif
# endif /*!BRS_ENABLE_PREFER_PLL_WATCHDOG_INIT*/
#endif /*!BRS_FBL_NO_ECUMINIT&&!BRS_FBL_WITH_ECUMINIT&&!_MICROSOFT_C_VTT_*/

}


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
  BrsHwDisableInterruptAtPowerOn();

# if (BRS_CPU_CORE_AMOUNT>1)
  if (BrsHw_GetCore() == BRSHW_INIT_CORE_ID)
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


# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_START_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
void SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(void)
{
  /* Protects against task interruptions -> no locking needed, because all main functions are on same task */
}

void SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(void)
{
  /* Protects against task interruptions -> no locking needed, because all main functions are on same task */
}
# if defined (BRS_ENABLE_FBL_SUPPORT)
  #define BRS_STOP_SEC_RAM_CODE
  #include "Brs_MemMap.h"
# endif
