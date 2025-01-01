/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm.c
 *        \brief  Main source file
 *
 *      \details  Main entry point of the HSM firmware.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define VHSM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm.h"
#include "vHsm_Core.h"
#include "vHsm_Ipc.h"
#include "vHsm_JobProcessor.h"
#include "vHsm_KeyM.h"
#include "vHsm_Trace.h"
#include "vHsm_Nvm.h"
#include "vHsm_Core_Custom.h"
#include "SchM_vHsm.h"

#include "vHsm_Hal.h"
#include "CryIf.h"
#if (VHSM_OS_SUPPORT == STD_ON)
# include "Rte_Main.h"
#endif

#include "vHsm_ApiInternal.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* vendor specific version information is BCD coded */
#if ((VHSM_SW_MAJOR_VERSION != (0x08)) \
    || (VHSM_SW_MINOR_VERSION != (0x00)) \
    || (VHSM_SW_PATCH_VERSION != (0x00)))
# error "Vendor specific version numbers of vHsm.c and vHsm.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

#if defined (_IAR_C_ARM32_) /* COV_VHSM_PLATFORM_SPECIFIC_VHSMNORETURN */
# define VHSM_NORETURN                                                __attribute__((noreturn))
#else
# define VHSM_NORETURN
#endif
/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(vHsm_StateType, VHSM_VAR_NOINIT) vHsm_State;
#define VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_GENERATE_RANDOM_STACK_PROTECTION_CANARY == STD_ON)
# define VHSM_START_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(uint32, VHSM_VAR_INIT) __stack_chk_guard = 0xdb31a25cuL; /* PRQA S 0602, 1514 */ /* MD_VHSM_0602_STACK_PROTECTION, MD_VHSM_ONE_USAGE */
# define VHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

#define VHSM_START_SEC_RESET_INFO_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(vHsm_ResetInfoType, VHSM_VAR_NOINIT) vHsm_ResetInfo; /* PRQA S 1514 */ /* MD_VHSM_ONE_USAGE */
#define VHSM_STOP_SEC_RESET_INFO_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_InitState()
 *********************************************************************************************************************/
/*! \brief       The function initializes the state of the vHsm
 *  \details     Initialize component variables at power up.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_InitState(void);

/**********************************************************************************************************************
 *  vHsm_InitMemory()
 *********************************************************************************************************************/
/*! \brief       The function initializes the global variables of the vHsm
 *  \details     Initialize component variables at power up.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_InitMemory(void);

/**********************************************************************************************************************
 *  vHsm_InitIpc()
 *********************************************************************************************************************/
/*! \brief       Sets the values inside the IPC to the start state
 *  \details     -
 *  \pre         IPC memory is initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_InitIpc(void);

#if (VHSM_RANDOMINIT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_InitializeRandomKeys()
 *********************************************************************************************************************/
/*! \brief       Initializes selected keys with a random value if it is not valid yet
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_InitializeRandomKeys(void);
#endif

/**********************************************************************************************************************
 *  vHsm_HandleRamLoop()
 *********************************************************************************************************************/
/*! \brief       Handle requests to go into the RAM loop to enable code flash access on application core
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_HandleRamLoop(void);

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_InitIpc()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_InitIpc(void)
{
#if (VHSM_GENERATE_RANDOM_IPC_VALUES == STD_ON)
  /* #10 Provide random data to the application cores */
  (void)vHsm_MemRand((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Ipc_GetStackProtectionCanaryPE1Ptr(), 4u); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
  (void)vHsm_MemRand((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Ipc_GetStackProtectionCanaryPE2Ptr(), 4u); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
  (void)vHsm_MemRand(vHsm_Ipc_GetSeedPtr(), vHsm_Ipc_GetSeedSize()); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
#endif

  /* #15 Init protocol version */
  vHsm_Ipc_vHsmProtocolVersion() = VHSM_CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION; /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */

  /* #20 Set ready flag */
  vHsm_Ipc_HsmReady(); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
}

/**********************************************************************************************************************
 *  vHsm_InitState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_InitState(void)
{
  uint32 cryIfKeyId;
#if (VHSM_SECURE_BOOT == STD_ON)
  vHsm_SecureBootSegmentIterType segment;
  vHsm_SecureBootGroupIterType group;
#endif
  uint8 ipc;

  /* #10 Initialize the global state */
  vHsm_State.vHsm_SecureBootEndIndicationFlag = FALSE;
  vHsm_State.vHsm_SecureBootDoneFlag = FALSE;
  vHsm_State.vHsm_StayInRamFlag = FALSE;
  vHsm_State.vHsm_Loop = TRUE;
  vHsm_State.vHsm_DataflashPeLock = FALSE;
  vHsm_State.vHsm_ErrorLogProcessing = FALSE;
  vHsm_State.vHsm_DisableSoftReset = FALSE;
  vHsm_State.vHsm_JumpToUpdaterFlag = FALSE;
  vHsm_State.vHsm_SuccessfulFirmwareUpdateFlag = FALSE;
  vHsm_State.vHsm_SecureBootResult = CRYPTO_E_VER_OK;

  for (cryIfKeyId = 0u; cryIfKeyId < vHsm_GetSizeOfKeyInfo(); cryIfKeyId++)
  {
    vHsm_State.vHsm_KeyUsageRestriction[cryIfKeyId] = 0u;
#if (VHSM_INTERNALONLYKEYS == STD_ON)
    if (vHsm_IsInternalOnlyOfKeyInfo(cryIfKeyId) == TRUE)
    {
      vHsm_State.vHsm_KeyUsageRestriction[cryIfKeyId] |= VHSM_KEY_USAGE_INTERNAL_ONLY;
    }
#endif
  }

#if (VHSM_SECURE_BOOT == STD_ON)
  for (segment = 0u; segment < vHsm_GetSizeOfSecureBootSegment(); segment++)
  {
    vHsm_State.vHsm_SecureBootState.segmentFinished[segment] = FALSE;
    vHsm_State.vHsm_SecureBootState.segmentResult[segment] = CRYPTO_E_VER_OK;
  }

  for (group = 0u; group < vHsm_GetSizeOfSecureBootGroup(); group++)
  {
    vHsm_State.vHsm_SecureBootState.groupFinished[group] = FALSE;
    vHsm_State.vHsm_SecureBootState.groupResult[group] = CRYPTO_E_VER_OK;
  }
#endif

  for (ipc = 0u; ipc < vHsm_GetSizeOfIpcInstance(); ipc++)
  {
    vHsm_State.vHsm_IpcInitialized[ipc] = FALSE;
  }
}

#if (VHSM_RANDOMINIT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_InitializeRandomKeys()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_InitializeRandomKeys(void)
{
  Std_ReturnType retVal = E_OK;
  vHsm_Api_SizeOfKeyElementsType elementIndex;
  vHsm_RandomInitIterType randomInitIndex;

  /* #10 Interate over configured keys */
  for (randomInitIndex = 0u; randomInitIndex < vHsm_GetSizeOfRandomInit(); randomInitIndex++)
  {
    /* #11 Check if key element is part of key (get the key) */
    if (vHsm_Api_Local_KeyElementSearch(vHsm_GetKeyOfRandomInit(randomInitIndex),
      vHsm_GetKeyElementOfRandomInit(randomInitIndex), &elementIndex) == E_OK)
    {
      /* #12 Check if the key element is not already valid */
      if (vHsm_Api_IsKeyElementValid(elementIndex) == FALSE)
      {
        uint32 keyElementLength = vHsm_Api_GetKeyElementLength(elementIndex);

        /* #20 Generate random data directly into key element storage */
        retVal |= vHsm_MemRand(
          vHsm_Api_GetAddrKeyStorage(vHsm_Api_GetKeyStorageStartIdxOfKeyElements(elementIndex)),
          keyElementLength);

        /* #21 Set the key element written length */
        vHsm_Api_SetKeyStorage(vHsm_Api_GetKeyStorageWrittenLengthStartIdxOfKeyElements(elementIndex), (uint8)((keyElementLength >> 8) & 0xFFu));
        vHsm_Api_SetKeyStorage((vHsm_Api_GetKeyStorageWrittenLengthStartIdxOfKeyElements(elementIndex) + 1u), (uint8)(keyElementLength));

        /* #22 Set the only the key element to valid and persist */
        (void)vHsm_Api_SetKeyElementValidAndPersist(vHsm_GetKeyOfRandomInit(randomInitIndex), vHsm_GetKeyElementOfRandomInit(randomInitIndex), TRUE);
      }
    }
  }

  return retVal;
}
#endif /* (VHSM_RANDOMINIT == STD_ON) */

/**********************************************************************************************************************
 *  vHsm_HandleRamLoop()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_HandleRamLoop(void)
{
  /* #10 Check if ramloop shall be entered */
  if (vHsm_State.vHsm_StayInRamFlag == FALSE)
  {
    /* Do nothing */
  }
  else if (vHsm_State.vHsm_StayInRamIpcChannel == VHSM_INVALID_IPC_CHANNEL)
  {
    /* Channel has not been set yet, check it in next mainfunction call again. */
  }
  else
  {
    uint8 vHsm_Ipc_Idx_Tmp;

    /* #20 Enter exclusive area to avoid interrupts */
    SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_1();

    /* Safe current ipc instance */
    vHsm_Ipc_Idx_Tmp = vHsm_Ipc_Idx;

    /* Restore the Ipc index of the job which has sent the vHsm to the ram loop */
    vHsm_Ipc_Idx = vHsm_State.vHsm_StayInRamIpcChannel;

    vHsm_State.vHsm_StayInRamFlag = FALSE;

    /* #30 Go into the RAM loop and enable the application to modify the code flash */
    vHsm_RamLoop();

    /* Clear the job ipc instance */
    vHsm_State.vHsm_StayInRamIpcChannel = VHSM_INVALID_IPC_CHANNEL;

    /* Restore the old ipc instance */
    vHsm_Ipc_Idx = vHsm_Ipc_Idx_Tmp;

    /* #40 Exit exclusive area to enable interrupts */
    SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_1();
  }
}

/**********************************************************************************************************************
 *  vHsm_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_InitMemory(void)
{
#if (VHSM_LOG == STD_ON)
  /* #10 Initialize EventLog memory which is not initialized by Nvm */
  vHsm_LogEventIterType logEventId;
  for (logEventId = 0u; logEventId < vHsm_GetSizeOfLogEvent(); logEventId++)
  {
    if (vHsm_GetNvProcessingOfLogEvent(logEventId) == VHSM_NV_PROCESSING_NONE)
    {
      VStdMemClr(vHsm_Log_GetMemory(logEventId, 0u), (uint32)(((vHsm_Log_GetMaxEntrySize(logEventId))*vHsm_GetMaxEntriesOfLogEvent(logEventId)) + sizeof(vHsm_Log_MngtType))); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    }
  }
#endif
}

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE_NOINLINE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_MainFunction()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_MainFunction(void)
{
  vHsm_IpcInstanceIterType ipc;

  for (ipc = 0u; ipc < vHsm_GetSizeOfIpcInstance(); ipc++)
  {
    /* #120 Process the job in the IPC if there is one available */
    if (vHsm_State.vHsm_IpcInitialized[ipc] == FALSE)
    {
      if (vHsm_Hal_ApplicationIpcInit(ipc) == TRUE)
      {
        vHsm_Ipc_Idx = (uint8)ipc;
        vHsm_Ipc_ChangeInstance(ipc);
        vHsm_InitIpc(); /* PRQA S 2987 */ /* MD_VHSM_2987_IPC_INIT */
        vHsm_State.vHsm_IpcInitialized[ipc] = TRUE;
        vHsm_Ipc_MainFunction();
      }
    }
    else
    {
      vHsm_Ipc_Idx = (uint8)ipc;
      vHsm_Ipc_ChangeInstance(ipc);
      vHsm_Ipc_MainFunction();
    }
  }

  /* #140 Call the Core Main Function */
  vHsm_Core_MainFunction();

  /* #150 Call the other Main Functions */
  vHsm_MainFunctionCyclic_Callout();

  /* #170 Check if transition to RAM loop shall be made */
  if (vHsm_PreRamLoop_Callout() == E_OK)
  {
    vHsm_HandleRamLoop();
  }

#if (VHSM_FIRMWARE_UPDATE == STD_ON)
  if (vHsm_State.vHsm_JumpToUpdaterFlag == TRUE)
  {
# if (VHSM_SECURE_BOOT == STD_ON)
    if (vHsm_Core_SecureBoot_IsProcessing() == FALSE)
# endif
    {
      /* Clear the flags */
      vHsm_State.vHsm_SuccessfulFirmwareUpdateFlag = FALSE;
      vHsm_State.vHsm_JumpToUpdaterFlag = FALSE;

      /* Call firmware update callout */
      vHsm_FirmwareUpdate_PreJmpToUpdater_Callout();

      /* Jump to updater. This call will never return */
      vHsm_GetUpdaterAddressOfFirmwareUpdate()();
    }
  }
#endif
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

#define VHSM_STOP_SEC_CODE_NOINLINE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSM_START_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_TriggerSoftwareReset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_TriggerSoftwareReset(void) /* COV_VHSM_MAIN */
{
  if (vHsm_State.vHsm_DisableSoftReset == FALSE)
  {
    /* #20 Increment the software reset counter */
    vHsm_ResetInfo.softResetCounter = (uint8)(vHsm_ResetInfo.softResetCounter + 1u);

    /* #40 Trigger the software reset */
    vHsm_TriggerSoftwareReset_Callout();
  }
}

/**********************************************************************************************************************
 *  vHsm_RamLoop()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_RamLoop(void)
{
  /* #10 Get the offset for the ram execution flag and store it to a RAM variable to avoid access to the code flash */
#if(VHSM_ENABLE_RAM_LOOP_CALLOUT == STD_ON)
  Std_ReturnType stayInRam;
#endif
  uint32 endRamExecFlagOffsetTmp = vHsm_Ipc_MemoryLayout.endRamExecFlagOffset;
  uint32 ramExecFlagOffsetTmp = vHsm_Ipc_MemoryLayout.ramExecFlagOffset;

#if(VHSM_SETTING_ENABLE_API_CODE_FLASH_ACCESS == STD_ON)
  /* #20 Allow the code flash write access from the application core */
  vHsm_Hal_EnableCodeFlashAccess();
#endif

  /* change back to ipc channel that sent vHsm to ram */
  vHsm_Ipc_ChangeInstance(vHsm_State.vHsm_StayInRamIpcChannel);

  /* #30 Indicate that the vHsm is now running in Ram */
  vHsm_Ipc_GetMemoryValue32(ramExecFlagOffsetTmp) = 1u; /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */

  /* #40 Wait until the application has finished the code flash write access */
  while (vHsm_Ipc_GetMemoryValue32(endRamExecFlagOffsetTmp) != 1u) /* PRQA S 0310, 3305 */ /* MD_VHSM_SERIALIZATION_MACRO */
  {
#if(VHSM_ENABLE_RAM_LOOP_CALLOUT == STD_ON)
    stayInRam = vHsm_RamLoop_Callout();
    if (stayInRam == E_NOT_OK)
    {
      /* exit ramloop */
      break;
    }
#endif
  }

#if(VHSM_SETTING_ENABLE_API_CODE_FLASH_ACCESS == STD_ON)
  /* #50 Deny the code flash write access from the application core */
  vHsm_Hal_DisableCodeFlashAccess();
#endif

  /* #60 Indicate that the vHsm is no longer in the RAM loop */
  vHsm_Ipc_LeaveRamExec(); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
}

#define VHSM_STOP_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Init(void)
{
  /* #10 Perform hardware dependent init */
  vHsm_SystemInit_Callout();
  vHsm_Hal_SystemInit();

  /* #60 Init the memory of the vHsm */
  vHsm_InitState();
  vHsm_InitMemory(); /* PRQA S 2987 */ /* MD_VHSM_2987_INIT_MEMORY */ /*lint !e522 */
  vHsm_Core_InitMemory();

  /* #70 Init the memory of other modules */
  vHsm_InitOne_Callout();

  /* #71 Init Hal */
  vHsm_Hal_Init();

#if (VHSM_OS_SUPPORT == STD_ON)
  /* #80 Start OS */
  StartOS(OSDEFAULTAPPMODE);
#else
# if (VHSM_GENERATE_RANDOM_STACK_PROTECTION_CANARY == STD_ON)
  /*  Compile with -Xstack-protection (DiabData) or -stack-protection (Greenhills) to enable stack protection. */
  /* #85 Generate a random stack canary used by the stack protection */
  (void)vHsm_MemRand((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))__ghs_get_stack_chk_guard_address(), 4u); /* PRQA S 0310 2 */ /* MD_VHSM_0310_API_SPECIFIC_CAST */
# endif

  /* #86 Call vHsm_StartupTwo if there is no Os (now protected by the stack protection) */
  vHsm_StartupTwo();
#endif
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  vHsm_StartupTwo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *

 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_StartupTwo(void)
{

#if (VHSM_OS_SUPPORT == STD_ON)
  /* #20 Init SchM */
  SchM_Init();
#endif

  /* #25 Init before Nvm ReadAll */
  vHsm_InitTwo_Callout();

  /* #30 Init the vHsm Core driver */
  vHsm_Core_Init(); /*lint !e522 */

  /* #100 Init the KeyM */
  vHsm_KeyM_Init();

  /* #120 Init the Ipc */
  vHsm_Ipc_Init();

#if (VHSM_NVM_USED == STD_ON)
  /* #240 Process the Nvm */
  if (vHsm_NvM_Init() != E_OK)
  {
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "An error occurred during the key storage initialization!\n");
    /* #245 Trigger a software reset if an error occurred during Nvm processing */
    vHsm_TriggerSoftwareResetWithIpcClearing(); /*lint !e522 */
  }
#else /* (VHSM_NVM_USED == STD_ON) */
  vHsm_Trace(VHSM_TRACETYPE_INFO, "This configuration does not contain any Nvm data. Keys will not be persisted!\n");
#endif /* (VHSM_NVM_USED == STD_ON) */

  /* #247 Init after Nvm ReadAll */
  vHsm_InitThree_Callout();

#if (VHSM_RANDOMINIT == STD_ON)
  /* #248 Initialize keys with random values */
  if (vHsm_InitializeRandomKeys() != E_OK)
  {
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "An error occurred during the random key initialization!\n");
    /* #249 Trigger a software reset if an error occurred during random init */
    vHsm_TriggerSoftwareResetWithIpcClearing(); /*lint !e522 */
  }
#endif

  /* #250 Set secure protected keys to invalid */
  vHsm_KeyM_PrepareSecureProtectedKeyStates();

  /* #260 Check if there is some information available after a software reset */
  vHsm_Hal_HandleResetInfo();

#if (VHSM_SECURE_BOOT == STD_ON)
  /* #270 Initialize Secure Boot */
    vHsm_Core_SecureBoot_Init();
# if (VHSM_ENABLE_SECURE_BOOT_AUTOSTART == STD_ON)
  /* - #271 Perform auto start of Secure Boot groups */
  if (vHsm_Core_SecureBoot_AutostartGroups() != E_OK)
  {
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "Secure Boot has not been started correctly\n");
    /* #275 Trigger software reset if secure boot could not be initialized */
    vHsm_TriggerSoftwareResetWithIpcClearing(); /*lint !e522 */
  }
# endif
#endif

  /* #300 Enable request interrupt */
  vHsm_Hal_EnableInterruptSource(0xFFFFFFFFu);

  /* #301 Start application cores */
  vHsm_StartApplicationCores_Callout();

  /* #310 Call Mainfunction in an endless loop if there is no Os */
#if (VHSM_OS_SUPPORT == STD_OFF)
  while (vHsm_State.vHsm_Loop)
  {
    vHsm_MainFunction();
  }
#endif
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  __stack_chk_fail()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
 VHSM_NORETURN FUNC(void, VHSM_CODE)  __stack_chk_fail(void) /* COV_VHSM_STACK_PROTECTION */ /* PRQA S 0602 2 */ /* MD_VHSM_0602_STACK_PROTECTION */
{
  /* A stack overflow occurred */

  /* #10 Print trace that stack overflow occurred */
  vHsm_Trace(VHSM_TRACETYPE_ERROR, "Stack smashing detected!\n");

  /* #20 Write the occurrence of the stack overflow to the error log */
  (void)vHsm_WriteErrorLog(VHSM_LOG_ID_STACKPROTECTION, VHSM_LOG_DATA_NO_ERROR_DATA);

  /* #30 Trigger reset */
  vHsm_TriggerSoftwareResetWithIpcClearing(); /* COV_VHSM_STACK_PROTECTION */ /*lint !e522 */
}

#if (VHSM_OS_SUPPORT == STD_OFF)
# if (VHSM_GENERATE_RANDOM_STACK_PROTECTION_CANARY == STD_ON)
/**********************************************************************************************************************
 *  __ghs_get_stack_chk_guard_address()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR), VHSM_CODE) __ghs_get_stack_chk_guard_address(void) /* PRQA S 0602 */ /* MD_VHSM_0602_STACK_PROTECTION */
{
  /* #10 Return the address of the variable containing the stack canary */
  return &__stack_chk_guard;
}
# endif
#endif

/**********************************************************************************************************************
 *  vHsm_TriggerSoftwareResetWithIpcClearing()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_TriggerSoftwareResetWithIpcClearing(void) /* COV_VHSM_MAIN */
{
  uint8 ipc;
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) currentPtr = vHsm_Ipc_MemoryPtr;

  /* #10 Write a message to the debugger console */
  vHsm_Trace(VHSM_TRACETYPE_INFO, "Perform Software Reset\n");

  /* #30 Clear the ready flag in the IPC */
  /* Set the ready flag inside the IPC */
  for (ipc = 0u; ipc < vHsm_GetSizeOfIpcInstance(); ipc++)
  {
    if (vHsm_State.vHsm_IpcInitialized[ipc] == TRUE)
    {
      vHsm_Ipc_ChangeInstance(ipc);
      vHsm_Ipc_HsmNotReady(); /* PRQA S 0310, 3305 */ /* MD_VHSM_IPC_MACRO */
    }
  }

  /* #40 Trigger the software reset */
  vHsm_TriggerSoftwareReset();

  vHsm_Ipc_MemoryPtr = currentPtr;
}

/**********************************************************************************************************************
 *  vHsm_MemRand()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_MemRand(
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) dstPtr,
  uint32 length)
{
  Std_ReturnType retVal;
  uint32 lengthTmp = length;

  /* #10 Call the random generate csm job */
  retVal = Csm_RandomGenerate(vHsm_GetRandomCsmJobRefOfGeneral(), dstPtr, &lengthTmp);

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_WriteErrorLog()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_WriteErrorLog(
  uint32 errorId,
  uint32 errorData)
{
  Std_ReturnType retVal = E_NOT_OK;

#if(VHSM_ERRORLOGEVENTLOGREFOFGENERAL == STD_ON)
  /* #10 Check if this is not a recursive call */
  if (vHsm_State.vHsm_ErrorLogProcessing == FALSE)
  {
    vHsm_State.vHsm_ErrorLogProcessing = TRUE;
    /* #20 Call the core to write the error log */
    retVal = vHsm_Core_WriteErrorLog(errorId, errorData);
    vHsm_State.vHsm_ErrorLogProcessing = FALSE;
  }
  else
  {
    /* #30 Write the error to the debugger console */
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "Error during error log\n");
  }
#else
  VHSM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(errorData); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
#endif

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_StartupCallout()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_StartupCallout(void)
{
  /* #10 Call startup callout in Hal */
  vHsm_Hal_StartupCallout();
}

/**********************************************************************************************************************
 *  vHsm_ExternalIsr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_ExternalIsr(
  vHsm_CallContextType callContext,
  uint32 mask)
{

  vHsm_IpcInstanceIterType ipc;
  uint8 vHsm_Ipc_Idx_Tmp;
#if (VHSM_INTERRUPT_MODE == STD_OFF) || (VHSM_SETTING_ENABLE_IPC_INIT_VIA_INTERRUPT == STD_ON)
  uint32 index = 1u;
#endif

  /* #10 Store current ipc channel index to be able to restore it later */
  vHsm_Ipc_Idx_Tmp = vHsm_Ipc_Idx;

  /* #20 iterate over all ipc instances */
  for (ipc = 0u; ipc < vHsm_GetSizeOfIpcInstance(); ipc++)
  {
#if (VHSM_INTERRUPT_MODE == STD_ON) && (VHSM_SETTING_ENABLE_IPC_INIT_VIA_INTERRUPT == STD_OFF)
    /* #21 Check if IPC is already initialized */
    if (vHsm_State.vHsm_IpcInitialized[ipc] == TRUE)
    {
      vHsm_Ipc_Idx = (uint8)ipc;
      vHsm_Ipc_ChangeInstance(ipc);

      /* #22 Fetch job from IPC */
      vHsm_Ipc_FetchJobs(callContext);
    }
#else
    /* #23 Check if mask is valid */
    if ((mask & index) == index)
    {
      vHsm_Ipc_Idx = (uint8)ipc;
      vHsm_Ipc_ChangeInstance(ipc);

      /* #24 Check if IPC is already initialized */
      if (vHsm_State.vHsm_IpcInitialized[ipc] == FALSE)
      {
        /* #25 Initialize IPC */
        vHsm_InitIpc(); /* PRQA S 2987 */ /* MD_VHSM_2987_IPC_INIT */
        vHsm_State.vHsm_IpcInitialized[ipc] = TRUE;
      }

# if (VHSM_INTERRUPT_MODE == STD_ON)
      /* #26 Fetch job from IPC */
      vHsm_Ipc_FetchJobs(callContext);
# endif
    }
    index *= 2u; /* PRQA S 2983 */ /* MD_VHSM_2983_REDUNDANT_ASSIGNMENT */
#endif
  }

  /* #40 Restore the old ipc index */
  vHsm_Ipc_Idx = vHsm_Ipc_Idx_Tmp;
  vHsm_Ipc_ChangeInstance(vHsm_Ipc_Idx_Tmp);

#if (VHSM_INTERRUPT_MODE == STD_OFF)
  VHSM_DUMMY_STATEMENT(callContext); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
#endif

#if (VHSM_SETTING_ENABLE_IPC_INIT_VIA_INTERRUPT == STD_OFF)
  VHSM_DUMMY_STATEMENT(mask); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
#endif
}

/**********************************************************************************************************************
 *  vHsm_InternalIsr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_InternalIsr(
  uint32 mask)
{
#if (VHSM_OS_SUPPORT == STD_ON)
  vHsm_JobObjectIdType jobObjectId;

  /* ----- Implementation ----------------------------------------------- */

  for (jobObjectId = 0u; jobObjectId < vHsm_GetSizeOfJobObjects(); jobObjectId++)
  {
    /* #10 Check if a job is pending */
    if (vHsm_GetStateOfJobObjects(jobObjectId) == VHSM_JOB_STATE_PENDING)
    {
      /* #11 Check if the call context is correct */
# if (vHsm_GetIsrForProcessingOfScheduling() == VHSM_CATEGORY_2)
      if (vHsm_IsIsrProcessingOfJobObjectInfo(jobObjectId) == TRUE)
      {
        vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_PROCESSING);
        /* fetching was done from ISR and this is an ISR job. Process it. */
        /* #12 Process the received job */
        vHsm_JobProcessor_Execute(jobObjectId);
      }
      else
# endif
      {
        /* #13 Instruct the OS to start the corresponding task */
        vHsm_SetStateOfJobObjects(jobObjectId, VHSM_JOB_STATE_ACTIVATED);
        vHsm_Ipc_StartJobObjectTask(jobObjectId);
      }
    }
  }
#endif

  VHSM_DUMMY_STATEMENT(mask); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
}

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \exclusivearea vHsm_VHSM_EXCLUSIVE_AREA_0
 *                Protects the vHsm driver objects on locking and freeing. IPC, DETs and
 *                vHsm_JobObjects protection is done with this exclusive area.
 * \protects      vHsm_JobObjectInfo, vHsm_JobObjects, vHsm_Ipc_Idx, vHsm_State.vHsm_StayInRamIpcChannel, vHsm_State.vHsm_StayInRamFlag, detReportFlagOffset, detModuleIdOffset, detInstanceIdOffset, detApiIdOffset, detErrorIdOffset
 * \usedin        vHsm_Ipc_ReceiveJobRequest(), vHsm_Ipc_TransmitJobResponse(), vHsm_Ipc_DetReportError(), vHsm_JobProcessor_MainFunction
 * \exclude       -
 * \length        SHORT usually not more than 20 LOC, one time around 50 LOC
 * \endexclusivearea

 * \exclusivearea vHsm_VHSM_EXCLUSIVE_AREA_1
 *                Protects the vHsm RamLoop from beeing interrupted by interrupts to prevent code flash access.
 * \protects      -
 * \usedin        vHsm_HandleRamLoop()
 * \exclude       -
 * \length        LONG while performing the RAMLOOP
 * \endexclusivearea
 */

/**********************************************************************************************************************
 * Module specific MISRA deviations
 *********************************************************************************************************************/
/* Module specific MISRA deviations:

MD_VHSM_0306_CHECK_MEMORY_LAYOUT:
Reason:       Cast needed to evaluate if the pointer address is located in a specific memory region.
Risk:         Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention:   vHsm for specific hardware(32 - Bit platforms) (pointer size type can not differ). Valid memory access ensured by code review and test

MD_VHSM_0306_API_SPECIFIC_CAST:
Reason:       API expects a specific pointer type as input. Therefore the data type needs to be casted.
Risk:         Writing or reading of invalid memory
Prevention:   Covered by code review and tests.

MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST:
Reason:       Secureboot expects a specific pointer type as input. Therefore the data type needs to be casted.
Risk:         Writing or reading of invalid memory
Prevention:   Covered by code review and tests.

MD_VHSM_0306_POINTERCAST:
Reason:       Cast needed to evaluate if the pointer address is aligned on 32 - Bit or located in a specific memory region.
Risk:         Size of pointer type is hardware specific - not compatible between platforms.Invalid memory access.
Prevention:   vHsm for specific hardware(32 - Bit platforms) (pointer size type can not differ). Valid memory access ensured by code review and test

MD_VHSM_0306_IPC_ADDRESS:
Reason:       Cast needed to cast an arbitrary input (linker symbol or address or pointer) to the necessary pointer type
Risk:         Size of pointer type is hardware specific - not compatible between platforms.Invalid memory access.
Prevention:   vHsm for specific hardware(32 - Bit platforms) (pointer size type can not differ). Valid memory access ensured by code review and test

MD_VHSM_0306_REGISTER_ACCESS:
Reason:       Access to registers of the hardware using an address.
Risk:         Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention:   Preconfiguration for specific hardware platforms. Also the correct addresses must be ensured by the user in the configuration.

MD_VHSM_0310_API_SPECIFIC_CAST:
Reason:       API expects a specific pointer type as input. Therefore the structure needs to be casted.
Risk:         Wrong interpretation of the data.
Prevention:   Correct interpretation of the input covered by code review and test.

MD_VHSM_SERIALIZATION_MACRO:
Reason:       Cast needed in order to have a platform independent IPC on shared memory for different architectures
Risk:         Writing or reading of invalid memory
Prevention:   Covered by code review and tests.

MD_VHSM_SERIALIZATION_PTR_MACRO:
Reason:       Cast needed in order to have a platform independent IPC on shared memory. Ptr needs to be transferred by their address.
Risk:         Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention:   vHsm for specific hardware(32 - Bit platforms) (pointer size type can not differ). Valid memory access ensured by code review and test

MD_VHSM_0310_KEYELEMENT_CONTENT:
Reason:       The content of a key element which is an uint8 array has to be copied to e.g. a uint32 value.
Risk:         Wrong interpretation of the data.
Prevention:   Covered by code review and tests on hardware.

MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS:
Reason:       The content of a uint32 array is accessed as uint8 and boolean. Cast is therefore needed.
Risk:         Wrong interpretation of the data.
Prevention:   Covered by code review and tests.

MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT:
Reason:       Secureboot memory is generated es uint32 array, and all accesses with multiple indices of 4 are valid and properly aligned.
Risk:         Wrong interpretation of the data.
Prevention:   Correct interpretation of the input covered by code review and test.

MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP:
Reason:       Value is ORed with default assigned E_OK which is 0. The result is always the right hand operand.
Risk:         None
Prevention:   Code review and tests. The statement depends on enabled/disabled code parts.

MD_VHSM_2995_CONDITION_FALSE_IN_OTHER_CONFIGS:
Reason: These conditions can not be false for some configs.
Risk: None.
Prevention: ECO would detect coverage leaks.

MD_VHSM_2996_CONDITION_TRUE_IN_OTHER_CONFIGS:
Reason: These conditions can not be true for some configs.
Risk: None.
Prevention: ECO would detect coverage leaks.

MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS:
Reason: These conditions can not be false for some configs (storage in csm off).
Risk: None.
Prevention: ECO would detect coverage leaks.

MD_VHSM_2996_2992_SECUREBOOT_CONDITION_TRUE_IN_OTHER_CONFIGS:
Reason: These conditions can not be true for some configs (storage in csm off).
Risk: None.
Prevention: ECO would detect coverage leaks.

MD_VHSM_2985_SECUREBOOT_ASSIGNMENT_NOT_SAME_IN_OTHER_CONFIGS:
Reason: This assignment can be always that of the left-hand operand for some configs (storage in csm off).
Risk: None.
Prevention: ECO would detect coverage leaks.

MD_VHSM_IPC_MACRO:
Reason:       Cast needed in order to have a platform independent IPC on shared memory for different architectures
Risk:         Writing or reading of invalid memory
Prevention:   Covered by code review and tests.

MD_VHSM_KEYELEMENTIDSGET_BUFFER:
Reason:       Cast needed in order to use the IPC which is only able to handle uint8 pointers.
Risk:         Writing or reading of invalid/unaligned memory
Prevention:   Covered by code review and tests. The buffers have to be given aligned by the API specification on the driver side. The IPC itself uses always aligned buffers in case the input data has to be buffered.

MD_VHSM_0488_STD_LIB:
Reason:       Macro contained in standard lib.
Risk:         Memory corruption
Prevention:   Covered by code review and tests.

MD_VHSM_0602_STACK_PROTECTION:
Reason:       Identifier is reserved for the STD library. The library is not used, therefore the stack canary has to be defined in the code to be useful.
Risk:         None
Prevention:   Covered by code review and tests.

MD_VHSM_1030_TRACE_VARIADIC_MACRO:
Reason:       Variadic macros are not allowed
Risk:         Compiler does not support variadic macros
Prevention:   Covered by code review and tests.

MD_VHSM_5140_TRACE_VARIADIC_FUNCTION:
Reason:       Variadic macros are not allowed
Risk:         Compiler does not support variadic macros
Prevention:   Covered by code review and tests.

MD_VHSM_3217_JOB_POINTER:
Reason:       Job declaration needs to be at a wider scope.
Risk:         Invalid pointer access.
Prevention:   Covered by code review and tests.

MD_VHSM_3315_CONFIG_DEPENDENT_CASES:
Reason:       Multiple cases are available but not included to due specific configuration
Risk:         -
Prevention:   -

MD_VHSM_3393_STD_LIB:
Reason:       Implicit precedence may be not easy to understand.
Risk:         Wrong implicit precedence
Prevention:   Covered by code review and tests.

MD_VHSM_ONE_USAGE:
Reason:       Variable might be used only in one function but is declared on file level to ease up reading and ensure memory mapping and compiler abstraction.
Risk:         Could be accidentally used by another function
Prevention:   Covered by code review and tests.

MD_VHSM_1337_TRACE_VARIADIC_FUNCTION:
Reason:       Variadic functions shall be avoided but are needed for the tracing feature.
Risk:         Use of unsafe functions
Prevention:   Covered by tests with compiler and debugger. Only a debug feature, production code is not allowed to have tracing enabled.
              Tracing and inclusion of stdio.h is completely disablebel.

MD_VHSM_5124_STDIO:
Reason:       stdio.h is needed to print debug traces to the debugger console
Risk:         Not all debugger support this feature
Prevention:   Covered by tests with compiler and debugger. Only a debug feature, production code is not allowed to have tracing enabled.
              Tracing and inclusion of stdio.h is completely disablebel.

MD_VHSM_5130_STDIO:
Reason:       stdio.h is needed to print debug traces to the debugger console
Risk:         Not all debugger support this feature
Prevention:   Covered by tests with compiler and debugger. Only a debug feature, Production code is not allowed to have tracing enabled.
Tracing and   inclusion of stdio.h is completely disablebel.

MD_VHSM_3218_WORKSPACE_VAR:
Reason:       Workspace variables have to be static, although they are only accessed in one function.
Risk:         None
Prevention:   Tests on hardware and review

MD_VHSM_NON_TERMINATING:
Reason:       Loop is designed to run forever.
Risk:         None
Prevention:   -

MD_VHSM_2812_DET_CHECK_NULLPOINTER
Reason:       Length pointer is dereferences to check its value
Risk:         Dereferencing a null pointer
Prevention:   Code review and tests. Pointer is checked in if-statement before.

MD_VHSM_2983_REDUNDANT_ASSIGNMENT
Reason:     Redundant assignment in last cycle of for loop.
Risk:       None
Prevention: N/A

MD_VHSM_2987_IPC_INIT:
Reason:       MISRA detects the function has no side effects
Risk:         None
Prevention:   Code review and tests. The functions sets the ready flag in the IPC and has therefore side effects.

MD_VHSM_2987_INIT_MEMORY
Reason:       Function is detected without side effects when no log is available
Risk:         -
Prevention:   -

MD_VHSM_3219_INLINE_FUNCT:
Reason:     This function is inlined and therefore it has to be implemented here. The function is not used by all configurations of the implementation.
Risk:       None.
Prevention: None.

MD_VHSM_0311_CSM_JOB_AS_VAR:
Reason:     Parameter has to be casted to var to modify it although it is defined as const.
Risk:       Var access to const data.
Prevention: TmpJob always creates variables instead of const data. Therefore access via var is always possible. Covered by code review and component test.

MD_VHSM_TOOL_FALSE_POSITIVE:
Reason:     The QAC tool reports a false positive
Risk:       None
Prevention: Code review and tests. Messages may be deactivated globally in the future.

MD_VHSM_3415_SIDE_EFFECTS:
Reason: Functions at right hand of || or && are defined to have no side-effects. Avoiding this deviation would degrade code structure without benefits (nesting of if clauses)
Risk: A function HAS side effects, leading to unexpected behavior, if call is omitted.
Prevention: Review; Make sure that the output of the function is not used when the operand of the left hand side is false.

MD_VHSM_3415_NO_SIDE_EFFECTS:
Reason: Functions at right hand of || or && are defined to have no side-effects. Avoiding this deviation would degrade code structure without benefits (nesting of if clauses)
Risk: A function HAS side effects, leading to unexpected behavior, if call is omitted.
Prevention: The function which is called (Compare Memory) does not has side effects

MD_VHSM_NO_BREAK_IN_SWITCH:
Reason:     No break in a single case of a switch statement. Assumption is that if we have three input pointers then we have also two inputs.
Risk:       If the code is refactored or adapted, this may lead to a problem if it is not considered.
Prevention: Code Review.

MD_VHSM_IPC3_SHIFTVALUES_SIGNEDTYPECONVERSION:
Reason:     IPC3 feature shifts multiple values together into one uint32 at the serialization. Deserializing this values require the conversion.
Risk:       If the code is refactored or adapted, this may lead to a problem if it is not considered.
Prevention: Code Review.

MD_VHSM_6060_STPAR:
Reason:     Performance of the code is ranked higher than the metric threshold.
Risk:       Stack usage too high for target uC.
Prevention: Test of resulting code on target uC, user has to check stack usage in project context.

MD_HSM_3225_STACK_VAR_STORAGE_DURATION:
Reason:     A pointer to a stack variable of the function is provided to via a parameter to the caller.
Risk:       Stack and therefore the variable will go out of scope and the variable shall not be accessed anymore.
Prevention: Only FINISH call is happening afterwards. No data is used there anymore. Stack variable is therefore not used.
            Also the pointer is overwritten with NULL_PTR to avoid passing a pointer to the stack.

 */

/* COV_JUSTIFICATION_BEGIN

\ID COV_VHSM_LOCAL_DEFINE
\ACCEPT TX
\REASON VHSM_LOCAL is never defined externally.

\ID COV_VHSM_MISRA_ADDITIONAL_STATEMENT
\ACCEPT X
\REASON This else or default statements are required by MISRA but cannot be reached in code. The statement is captured by upper API.

\ID COV_VHSM_PROTWRITE_MACRO
\ACCEPT XF
\ACCEPT XX
\REASON Writing the register requires a special register write sequence. The missing conditions in the sequence can not be stimulated.
\PREVENTION Covered by code review and tests

\ID COV_VHSM_AES_WAIT
\ACCEPT XF
\REASON This code is usually not executed because the AES engine is too fast to trigger the wait.
\PREVENTION Covered by code review and tests

\ID COV_VHSM_BREAK_LOOP
\ACCEPT TX
\ACCEPT TF tx tf
\REASON Because of a break in the for loop, the exit condition will never be reached.
\PREVENTION Covered by code review and tests

\ID COV_VHSM_SECUREBOOT_KEY_CHECK
\ACCEPT TX
\REASON Because of a already checked existence of the key as secureboot segment key or group key the condition will never be false.
\PREVENTION Covered by code review

\ID COV_VHSM_UPGP_MACRO
\ACCEPT XF
\ACCEPT XX
\REASON Writing the UPGP register requires a special register write sequence. The missing conditions in the sequence can not be stimulated.
\PREVENTION Covered by code review and tests

\ID COV_VHSM_STACK_PROTECTION
\ACCEPT X
\ACCEPT XX
\REASON The stack protection can not be tested with the test suite, because the function must never return.
\PREVENTION Covered by code review and tests

\ID COV_VHSM_MAIN
\ACCEPT X
\REASON The main function is the first entry point. The coverage analysis can only evaluate the coverage from the function vHsm_MainProtected().
\PREVENTION Covered by code review and tests

\ID COV_VHSM_TRIGGER_SOFTWARE_RESET
\ACCEPT XX
\REASON Triggering a software reset with the hardware register prevents further debugging. Therefore a breakpoint is set in the exact same spot which uses the debugger to reset the system.
\PREVENTION Covered by code review and tests

\ID COV_VHSM_CASE_DEFAULT
\ACCEPT X
\REASON The default case is sometimes never reached because not supported cases are not forwarded to this function because of DET checks.
\PREVENTION Covered by code review and tests

\ID COV_VHSM_TRACE_OCCURRENCE
\ACCEPT X
\REASON The default case is sometimes never reached because the tracing is not tied to configuration parameters to avoid dependencies.
\PREVENTION Covered by code review and tests

\ID COV_VHSM_WRITE_ONCE_KEY_ALWAYS_AVAILABLE
\ACCEPT TX
\REASON The Key will always be found in the LibCv key storage, because it is checked before, that it is referenced as write once key
\PREVENTION Covered by code review and tests

\ID COV_VHSM_CUSTOM_KEY_ELEMENTS
\ACCEPT TX
\REASON The Crypto needs custom key elements, which could be defined in other modules as well.

\ID COV_VHSM_CUSTOM_KEY_ELEMENT_VALUE
\ACCEPT TX
\REASON The Crypto needs custom key elements, which could be defined in other modules as well.

\ID COV_VHSM_CUSTOM_ALGORITHM
\ACCEPT TX
\REASON The Crypto needs custom algorithm and algorithm mode defines, which could be defined in other modules as well.

\ID COV_VHSM_PLATFORM_SPECIFIC_TRACING
\ACCEPT TX
\ACCEPT XF
\ACCEPT XF xf xf
\REASON In order to use tracing on specific target platforms, the syntax of variadic macros are different as well as needed preprocessor defines prior to includeing stdio.h and stdarg.h

\ID COV_VHSM_PLATFORM_SPECIFIC_VHSMNORETURN
\ACCEPT TX
\ACCEPT XF
\REASON Some compiler require noreturn attribute before __stack_chk_fail() which will not return due to reset.

\ID COV_VHSM_NON_TERMINATING
\ACCEPT XF
\REASON The testsuite can not work if the vHsm Firmware stays in an endless loop. Therefore the loop will always be left.

\ID COV_VHSM_AES_DEC_OUTPUT_DATA
\ACCEPT TX
\REASON The AES always outputs data during decryption finish

\ID COV_VHSM_AES_ENC_OUTPUT_DATA_DUMMY
\ACCEPT XF tf xf
\REASON The AES never outputs data during encryption finish in the case when dummy data is used

\ID COV_CSM_NON_RTE
\ACCEPT TX
\ACCEPT XF
\REASON Ensures the variable or error code define exists if the CSM is used without RTE.

\ID COV_CSM_USER_DEFINES
\ACCEPT TX
\ACCEPT XF
\REASON Ensures the variable or error code define exists if the CSM is used.

\ID COV_VHSM_VTT
\ACCEPT XF
\REASON Needed for VTT execution

\ID COV_VHSM_INTERNAL_ISR_NOT_CALLED
\ACCEPT X
\REASON The API is only needed and called when OS support is enabled. Because it is an interface API, it always needs to be present.

\ID COV_VHSM_COMPARE_INTERNAL_MANDATORY
\ACCEPT TX
\REASON Secure software download or setting a tag needs at least a group configured with compare internal tag. This is also enforced via validation and therefore this needs to be justified.

\ID COV_VHSM_MEMMAP_EXAMPLE
\ACCEPT TX xf tx tx tx
\ACCEPT TX xf tx
\ACCEPT TX
\REASON Examples for different compilers are given in the MemMap file. Project is only compiled with one compiler in all configs.

\ID COV_VHSM_PARTITION_ALWAYS_FOUND
\ACCEPT TX
\REASON There is a validation in place, that makes sure that there is always an inactive partition for an active partition.


COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: vHsm.c
 *********************************************************************************************************************/
