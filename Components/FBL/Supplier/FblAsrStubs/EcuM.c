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
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: .\EcuM.c
 *   Generation Time: 2022-09-29 17:02:53
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D01
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
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

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "EcuM.h"
#include "Os.h"

#include "Can.h"
#include "CanIf.h"
#include "CanSM_EcuM.h"
#include "CanTp.h"
#include "ComM.h"
#include "CryIf.h"
#include "Csm.h"
#include "fbl_inc.h"
#include "Det.h"
#include "PduR.h"
#include "Crypto_30_LibCv.h"
#include "Crypto_30_vHsm.h"
#include "vMemAccM.h"
#include "Mcu.h"
#include "Fls_17_Dmu.h"
#include "Port.h"
#include "Fee.h"

#include "Dma.h"
#include "Spi.h"
#include "SBC.h"
#include "WrapNv.h"

/**********************************************************************************************************************
  PROTOTYPES OF EXTERN FUNCTIONS
**********************************************************************************************************************/
extern void FblMain(void);
 
/**********************************************************************************************************************
  TYPES
**********************************************************************************************************************/
typedef struct
{
  const Can_ConfigType * const CfgPtr_Can_Init;
  const CanIf_ConfigType * const CfgPtr_CanIf_Init;
  const CanSM_ConfigType * const CfgPtr_CanSM_Init;
  const CanTp_ConfigType * const CfgPtr_CanTp_Init;
  const ComM_ConfigType * const CfgPtr_ComM_Init;
  const FblCw_ConfigType * const CfgPtr_Dcm_Init;
  const PduR_PCConfigType * const CfgPtr_PduR_Init;
} EcuM_GlobalPBConfigType;

typedef EcuM_GlobalPBConfigType EcuM_GlobalConfigType;

typedef const EcuM_GlobalConfigType * EcuM_GlobalConfigRefType;

typedef struct
{
  EcuM_GlobalConfigType RBTM_FL;
  EcuM_GlobalConfigType RBTM_FR;
} EcuM_GlobalConfigRootType;

/**********************************************************************************************************************
  EXTERNAL VARIABLES
**********************************************************************************************************************/

uint8 activeEcuSide = 0;

/**********************************************************************************************************************
  LOCAL VARIABLES
**********************************************************************************************************************/
EcuM_GlobalConfigRootType EcuM_GlobalConfigRoot =
{
  {
    Can_Config_RBTM_FL_Ptr,
    CanIf_Config_RBTM_FL_Ptr,
    CanSM_Config_RBTM_FL_Ptr,
    CanTp_Config_RBTM_FL_Ptr,
    ComM_Config_RBTM_FL_Ptr,
    FblCw_Config_RBTM_FL_Ptr,
    PduR_Config_RBTM_FL_Ptr
  },
  {
    Can_Config_RBTM_FR_Ptr,
    CanIf_Config_RBTM_FR_Ptr,
    CanSM_Config_RBTM_FR_Ptr,
    CanTp_Config_RBTM_FR_Ptr,
    ComM_Config_RBTM_FR_Ptr,
    FblCw_Config_RBTM_FR_Ptr,
    PduR_Config_RBTM_FR_Ptr
  }
};

EcuM_GlobalConfigRefType EcuM_GlobalConfig_Ptr;

#define EcuM_LeftVariant EcuM_GlobalConfigRoot.RBTM_FL
#define EcuM_RightVariant EcuM_GlobalConfigRoot.RBTM_FR

#define RBTM_FR_ID_NVM  0x99

/**********************************************************************************************************************
  PROTOTYPES OF LOCAL FUNCTIONS
**********************************************************************************************************************/
EcuM_GlobalConfigRefType EcuM_DeterminePbConfiguration(void);

/**********************************************************************************************************************
  FUNCTION DEFINITIONS
**********************************************************************************************************************/
void EcuM_Init(void)
{
  /* Module: Can / InitPhase: INIT_MEMORY */
  Can_InitMemory();
  /* Module: CanIf / InitPhase: INIT_MEMORY */
  CanIf_InitMemory();
  /* Module: CanSM / InitPhase: INIT_MEMORY */
  CanSM_InitMemory();
  /* Module: CanTp / InitPhase: INIT_MEMORY */
  CanTp_InitMemory();
  /* Module: ComM / InitPhase: INIT_MEMORY */
  ComM_InitMemory();
  /* Module: CryIf / InitPhase: INIT_MEMORY */
  CryIf_InitMemory();
  /* Module: Csm / InitPhase: INIT_MEMORY */
  Csm_InitMemory();
  /* Module: Dcm / InitPhase: INIT_MEMORY */
  FblCw_InitMemory();
  /* Module: Det / InitPhase: INIT_MEMORY */
  Det_InitMemory();
  /* Module: PduR / InitPhase: INIT_MEMORY */
  PduR_InitMemory();
  /* Module: Crypto / InitPhase: INIT_MEMORY */
  Crypto_30_LibCv_InitMemory();
  /* Module: Crypto_vHsm / InitPhase: INIT_MEMORY */
  Crypto_30_vHsm_InitMemory();
  /* Module: vMemAccM / InitPhase: INIT_MEMORY */
  vMemAccM_InitMemory();
  /* Module: Det / InitPhase: INIT_ZERO */
  Det_Init(Det_Config_Ptr);
  /* Module: /Mcu/Mcu / InitPhase: INIT_ONE_EARLY */
  Mcu_Init(&Mcu_Config);
  Mcu_InitClock(0);while (MCU_PLL_LOCKED != Mcu_GetPllStatus());Mcu_DistributePllClock();
  
  Dma_Init(&Dma_Config);
  
  /* Module: /Port/Port / InitPhase: INIT_ONE_EARLY */
  Port_Init(&Port_Config);
  Spi_Init(&Spi_Config);
  SBC_Init();

  /* Module: Fls / InitPhase: INIT_ONE_EARLY */
  Fls_17_Dmu_Init(&Fls_17_Dmu_Config);
  /* Module: /Fee/Fee / InitPhase: INIT_ONE_LATE */
  Fee_Init(&Fee_Config);

  /* Module: CryIf / InitPhase: INIT_ONE */
  CryIf_Init();
  /* Module: Csm / InitPhase: INIT_ONE */
  Csm_Init();
  /* Module: Crypto / InitPhase: INIT_ONE */
  Crypto_30_LibCv_Init();
  /* Module: Crypto_vHsm / InitPhase: INIT_ONE */
  Crypto_30_vHsm_Init();
  /* Module: WrapNv / InitPhase: INIT_TWO_SYS */
  WrapNv_Init();
  
  FblMain();
}

void EcuM_StartupTwo(void)
{
  EcuM_GlobalConfig_Ptr = EcuM_DeterminePbConfiguration();
  /* Module: PduR / InitPhase: INIT_ONE */
  PduR_PreInit(EcuM_GlobalConfig_Ptr->CfgPtr_PduR_Init);
  /* Module: Can / InitPhase: INIT_TWO_DRV */
  Can_Init(EcuM_GlobalConfig_Ptr->CfgPtr_Can_Init);
  /* Module: vMemAccM / InitPhase: INIT_TWO_DRV */
  vMemAccM_Init();
  /* Module: CanIf / InitPhase: INIT_TWO_IF */
  CanIf_Init(EcuM_GlobalConfig_Ptr->CfgPtr_CanIf_Init);
  /* Module: PduR / InitPhase: INIT_TWO_COM */
  PduR_Init(EcuM_GlobalConfig_Ptr->CfgPtr_PduR_Init);
  /* Module: CanSM / InitPhase: INIT_TWO_SM */
  CanSM_Init(EcuM_GlobalConfig_Ptr->CfgPtr_CanSM_Init);
  /* Module: CanTp / InitPhase: INIT_TWO_TP */
  CanTp_Init(EcuM_GlobalConfig_Ptr->CfgPtr_CanTp_Init);
  /* Module: ComM / InitPhase: INIT_TWO_POST_NVMREADALL */
  ComM_PreInit(EcuM_GlobalConfig_Ptr->CfgPtr_ComM_Init);
  ComM_Init(EcuM_GlobalConfig_Ptr->CfgPtr_ComM_Init);
  ComM_PostInit();
  /* Module: Dcm / InitPhase: INIT_THREE */
  FblCw_Init(EcuM_GlobalConfig_Ptr->CfgPtr_Dcm_Init);
}

void EcuM_Shutdown(void)
{
}

EcuM_GlobalConfigRefType EcuM_DeterminePbConfiguration(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK Postbuild Selectable Support>
 *********************************************************************************************************************/
  volatile uint8 IdEcuLocation[3];
  volatile EcuM_GlobalConfigRefType cfg;

  ApplFblNvReadIdEcuLocation(IdEcuLocation);

  if(RBTM_FR_ID_NVM == IdEcuLocation[0])
  {
    cfg = &EcuM_RightVariant;
    activeEcuSide = RBTM_FR_ID_NVM;
  }
  else
  {
    cfg = &EcuM_LeftVariant;
    activeEcuSide = 0;
  }

  return cfg;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

/* Unrecognized User Blocks */
#if 0
#endif

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

