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
/*!        \file  vHsm_Hal_Public.h
 *        \brief  vHsm platform hardware abstraction library API
 *
 *      \details  This declares the hardware abstraction library API which is used by vHsm.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_HAL_PUBLIC_H)
# define VHSM_HAL_PUBLIC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "vHsm_Hal_HwCfg.h"
# include "vHsm_Hal_Cfg.h"
# include "vHsm_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Hsm2Host Status bits */
# define VHSM_HAL_VHSM_ACTIVE                                         ((uint32)1u << 0u)
# define VHSM_HAL_VHSM_READY                                          ((uint32)1u << 1u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* PRQA S 3453 5 */ /* MD_MSR_FctLikeMacro */
#define VHSM_HAL_IPC_INIT(ipc)                                       ((uint32)1u << (ipc))
#define VHSM_HAL_HOST2HSM(ipc)                                       (*((P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR))vHsm_Hal_GetHost2HsmOfHardwareUnits(ipc)))
#define VHSM_HAL_HSM2HOST(ipc)                                       (*((P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR))vHsm_Hal_GetHsm2HostOfHardwareUnits(ipc)))
#define VHSM_HAL_RESPONSE_INT(ipc)                                   (*((P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR))vHsm_Hal_GetResponseAddressOfHardwareUnits(ipc)))
#define VHSM_HAL_RESPONSE_CLEAR_VALUE(ipc)                           ((uint32)vHsm_Hal_GetResponseClearValueOfHardwareUnits(ipc))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct /* PRQA S 3630 */ /* MD_VHSM_3630_GLOBAL_TYPE */
{
  P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR) startAddressPtr;
  P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR) stopAddressPtr;
} vHsm_Hal_MemoryAreaConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_HAL_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Hal_Init()
 *********************************************************************************************************************/
/*! \brief         Initializes the vHsm Hardware Abstraction Library.
 *  \details       This function initializes the module vHsm_Hal. It initializes all variables and sets the
 *                 module state to initialized.
 *  \pre           Module is uninitialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_Init(void);

/**********************************************************************************************************************
 *  vHsm_Hal_SystemInit()
 *********************************************************************************************************************/
/*! \brief         Initialize the system hardware.
 *  \details       -
 *  \pre           Module is uninitialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_SystemInit(void);

/**********************************************************************************************************************
 *  vHsm_Hal_InitMemory()
 *********************************************************************************************************************/
/*! \brief         Initializes variables and memory areas that cannot be initialized with the startup code.
 *  \details       Initialize component variables at power up.
 *  \pre           Module is uninitialized.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_InitMemory(void);

/**********************************************************************************************************************
 *  vHsm_Hal_HandleResetInfo()
 *********************************************************************************************************************/
/*! \brief         Handle the reset Info and all actions which are related to it like changing the reset vectors.
 *  \details       After a software reset, the reset info may contain instruction which have to be performed
 *                 like changing reset vectors.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_HandleResetInfo(void);

/**********************************************************************************************************************
 *  vHsm_Hal_StartupCallout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called during startup at the very beginning.
 *  \details       This function is called from the startup code.
 *                 This is for special hardware initialization at the very beginning.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_StartupCallout(void);

/**********************************************************************************************************************
 *  vHsm_Hal_StartApplicationCores()
 *********************************************************************************************************************/
/*! \brief          Release/start the application cores
 *  \details        -
 *  \pre            -
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_StartApplicationCores(void);

#if (VHSM_HAL_CALLOUT_GETCODEFLASHADDRESS == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_GetCodeFlashAddr()
 *********************************************************************************************************************/
/*! \brief         Get the address of the code flash
 *  \details       Used for the VTT simulation to redirect the code flash address to the memory mapped file.
 *  \param[in]     offset              Pointer which represents the current code flash offset.
 *  \return        Pointer of the code flash offset.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR), VHSM_HAL_CODE) vHsm_Hal_GetCodeFlashAddr(
  P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR) offset);

#endif /* (VHSM_HAL_CALLOUT_GETCODEFLASHADDRESS == STD_ON) */

#if (VHSM_HAL_CALLOUT_PREPAREJOBDATA == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_PrepareCryptoJobData()
 *********************************************************************************************************************/
/*! \brief         Prepare input and output pointers in Crypto job for access from HSM side.
 *  \details       -
 *  \pre           -
 *  \param[in,out] jobInputOutput     The jobs primitive input output data.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_PrepareCryptoJobData(
  P2VAR(Crypto_JobPrimitiveInputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput);

/**********************************************************************************************************************
 *  vHsm_Hal_PrepareKeyMJobData()
 *********************************************************************************************************************/
/*! \brief         Prepare input and output pointers in KeyM job for access from HSM side.
 *  \details       -
 *  \pre           -
 *  \param[in,out] jobInputOutput     The jobs primitive input output data.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_PrepareKeyMJobData(
  P2VAR(vHsm_KeyM_InputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput);
#endif /* (VHSM_HAL_CALLOUT_PREPAREJOBDATA == STD_ON) */

#if (VHSM_HAL_CALLOUT_GETIPCADDRESS == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_GetIpcAddress()
 *********************************************************************************************************************/
/*! \brief         Get the address if the IPC.
 *  \details       This callout can be used by HAL to provide own IPC memory address or to rewrite the given address.
 *  \pre           -
 *  \param[in]     index       Index of the current IPC requested by the vHsm_Core
 *  \param[in,out] address     Memory address of the current IPC requested by the vHsm_Core
 *  \return        A pointer to the memory which shall be used for the chosen IPC index.
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_DATA), VHSM_HAL_CODE) vHsm_Hal_GetIpcAddress(
  uint32 index,
  P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_DATA) address);
#endif /* (VHSM_HAL_CALLOUT_GETIPCADDRESS == STD_ON) */

/**********************************************************************************************************************
 *  vHsm_Hal_TriggerInternalIrq()
 *********************************************************************************************************************/
/*! \brief         Trigger internal Cat2 interrupt
 *  \details       -
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE_ISR) vHsm_Hal_TriggerInternalIrq(void);

/**********************************************************************************************************************
 *  vHsm_Hal_ApplicationIpcInit()
 *********************************************************************************************************************/
/*! \brief          Checks if the IPC instance given by ipcIdx is initialized by application core
 *  \details        -
 *  \param[in]      ipc             IPC iterator
 *  \pre            -
 *  \return         TRUE  IPC instance has been initialized by application core
 *                  FALSE IPC instance has not been initialized by application core
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, VHSM_HAL_CODE) vHsm_Hal_ApplicationIpcInit(vHsm_IpcInstanceIterType ipc);

/**********************************************************************************************************************
 *  vHsm_Hal_EnableInterruptSource()
 *********************************************************************************************************************/
/*! \brief          Enables job request interrupts from host cores
 *  \details        -
 *  \param[in]      sources         bitmask to only enable interrupts for specific host cores
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_EnableInterruptSource(uint32 sources);

/**********************************************************************************************************************
 *  vHsm_Hal_DisableInterruptSource()
 *********************************************************************************************************************/
/*! \brief          Disables job request interrupts from host cores
 *  \details        -
 *  \param[in]      sources         bitmask to only disable interrupts for specific host cores
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_DisableInterruptSource(uint32 sources);

#if (VHSM_HAL_CALLOUT_DEBUGGERPRESENCE == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_IsDebuggerPresent()
 *********************************************************************************************************************/
/*! \brief          Checks whether a debugger is connected to the chip.
 *  \details        -
 *  \pre            -
 *  \return         TRUE  Debugger is present
 *                  FALSE Debugger is not present
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
FUNC(boolean, VHSM_HAL_CODE) vHsm_Hal_IsDebuggerPresent(void);
#endif /* (VHSM_HAL_CALLOUT_DEBUGGERPRESENCE == STD_ON) */

/**********************************************************************************************************************
 *  vHsm_Hal_InternalRequestIsr()
 **********************************************************************************************************************/
/*! \brief          Internal interrupt request handler
 *  \details        -
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
ISR(vHsm_Hal_InternalRequestIsr);

#if(VHSM_HAL_VHSM_ISR_FOR_PROCESSING == VHSM_HAL_CATEGORY_1) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_ExternalRequestIsr()
 **********************************************************************************************************************/
/*! \brief          Interrupt request handler for application interrupts not handled by Os
 *  \details        -
 *  \pre            -
 *  \context        ISR1
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
OS_ISR1(vHsm_Hal_ExternalRequestIsr);
#endif /* (vHsm_Hal_GetRequestIsrCategoryOfGeneral() == VHSM_HAL_CATEGORY_1) */

#if(VHSM_HAL_VHSM_ISR_FOR_PROCESSING == VHSM_HAL_CATEGORY_2) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_ExternalRequestIsr()
 **********************************************************************************************************************/
/*! \brief          Interrupt request handler for application interrupts handled by the Os
 *  \details        -
 *  \pre            -
 *  \context        ISR2
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
ISR(vHsm_Hal_ExternalRequestIsr);
#endif /* (vHsm_Hal_GetRequestIsrCategoryOfGeneral() == VHSM_HAL_CATEGORY_2) */

# define VHSM_HAL_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_HAL_START_SEC_RAMCODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_HAL_CALLOUT_TRIGGERSOFTWARERESET == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_TriggerSoftwareReset()
 *********************************************************************************************************************/
/*! \brief        Trigger a software reset.
 *  \details      -
 *  \pre          -
 *  \context      ANY
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_TriggerSoftwareReset(void);
#endif /* (VHSM_HAL_CALLOUT_TRIGGERSOFTWARERESET == STD_ON) */

#if (VHSM_HAL_CALLOUT_MANAGECODEFLASHACCESS == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_EnableCodeFlashAccess()
 *********************************************************************************************************************/
/*! \brief        Allow the write access to the code flash by the application core.
 *  \details      -
 *  \pre          -
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_EnableCodeFlashAccess(void);

/**********************************************************************************************************************
 *  vHsm_Hal_DisableCodeFlashAccess()
 *********************************************************************************************************************/
/*! \brief        Prevent the write access to the code flash by the application core.
 *  \details      -
 *  \pre          -
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_DisableCodeFlashAccess(void);
#endif /* (VHSM_HAL_CALLOUT_MANAGECODEFLASHACCESS == STD_ON) */

# define VHSM_HAL_STOP_SEC_RAMCODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_HAL_PUBLIC_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Hal_Public.h
 *********************************************************************************************************************/
