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
 *            Module: vBRS
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000614_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Source\EcuM.c
 *   Generation Time: 2022-02-21 13:41:16
 *           Project: CBD2000614_Upd - Version 1.0
 *          Delivery: CBD2000614_D04
 *      Tool Version: DaVinci Configurator (beta) 5.24.30 SP1
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
*  EXAMPLE CODE ONLY
*  -------------------------------------------------------------------------------------------------------------------
*  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
*  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
*  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
*  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
*  according to the state of the art before their use.
*********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "EcuM.h"

#include "Det.h"
#include "CryIf.h"
#include "Crypto_30_LibCv.h"
#include "Csm.h"
#include "Crypto_30_vHsm.h"
#include "vMemAccM.h"
#include "Mcu.h"
#include "Fls_17_Dmu.h"
#include "Fee.h"
#include "WrapNv.h"

/**********************************************************************************************************************
  PROTOTYPES OF EXTERN FUNCTIONS
**********************************************************************************************************************/
extern void FblMain(void);
 
/**********************************************************************************************************************
  PROTOTYPES OF LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/
void EcuM_Init(void)
{
  /* Module: Det / InitPhase: INIT_MEMORY */
  Det_InitMemory();
  /* Module: CryIf / InitPhase: INIT_MEMORY */
  CryIf_InitMemory();
  /* Module: Crypto / InitPhase: INIT_MEMORY */
  Crypto_30_LibCv_InitMemory();
  /* Module: Csm / InitPhase: INIT_MEMORY */
  Csm_InitMemory();
  /* Module: Crypto_vHsm / InitPhase: INIT_MEMORY */
  Crypto_30_vHsm_InitMemory();
  /* Module: vMemAccM / InitPhase: INIT_MEMORY */
  vMemAccM_InitMemory();
  /* Module: Det / InitPhase: INIT_ZERO */
  Det_Init(Det_Config_Ptr);
  /* Module: /Mcu/Mcu / InitPhase: INIT_ONE_EARLY */
  Mcu_Init(&Mcu_Config);
  Mcu_InitClock(0);while (MCU_PLL_LOCKED != Mcu_GetPllStatus());Mcu_DistributePllClock();
  /* Module: Fls / InitPhase: INIT_ONE */
  Fls_17_Dmu_Init(&Fls_17_Dmu_Config);
  /* Module: Fee / InitPhase: INIT_ONE_LATE */
  Fee_Init(&Fee_Config);

  FblMain();
}

void EcuM_StartupTwo(void)
{
  /* Module: Crypto / InitPhase: INIT_TWO_DRV */
  Crypto_30_LibCv_Init();
  /* Module: Crypto_vHsm / InitPhase: INIT_TWO_DRV */
  Crypto_30_vHsm_Init();
  /* Module: vMemAccM / InitPhase: INIT_TWO_DRV */
  vMemAccM_Init();
  /* Module: CryIf / InitPhase: INIT_TWO_IF */
  CryIf_Init();
  /* Module: Csm / InitPhase: INIT_TWO_SYS */
  Csm_Init();
  /* Module: WrapNv / InitPhase: INIT_TWO_SYS */
  WrapNv_Init();
}

void EcuM_Shutdown(void)
{
}

void EcuM_BswErrorHook(uint16 moduleId, uint8 errorId)
{
#if defined (ECUM_STUB_BSWERRORHOOK_CALLOUT)
  BrsTestsuite_EcuM_BswErrorHook_Callout(moduleId, errorId);
#endif
}

void EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource)
{
#if defined (ECUM_STUB_CHECKWAKEUP_CALLOUT)
  BrsTestsuite_EcuM_CheckWakeup_Callout(wakeupSource);
#endif
}

void EcuM_GeneratorCompatibilityError(uint16 moduleId, uint8 instanceId)
{
#if defined (ECUM_STUB_GENERATORCOMPATIBILITYERROR_CALLOUT)
  BrsTestsuite_EcuM_GeneratorCompatibilityError_Callout(moduleId, instanceId);
#endif
}

void EcuM_SetWakeupEvent(EcuM_WakeupSourceType wakeupSource)
{
#if defined (ECUM_STUB_SETWAKEUPEVENT_CALLOUT)
  BrsTestsuite_EcuM_SetWakeupEvent_Callout(wakeupSource);
#endif
}

void EcuM_ValidationWakeupEvent(EcuM_WakeupSourceType wakeupSource)
{
#if defined (ECUM_STUB_VALIDATIONWAKEUPEVENT_CALLOUT)
  BrsTestsuite_EcuM_ValidationWakeupEvent_Callout(wakeupSource);
#endif
}

