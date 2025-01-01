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
/*!        \file  vHsm_Hal.c
 *        \brief  vHsm platform hardware abstractions
 *
 *      \details  This implements the hardware access functions which are used by the platform code.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_HAL_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm_Hal.h"
#include "vHsm.h"

#include "IFX_HSM.h"
#include "core_cm3.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HSM software reset password */
#define VHSM_HAL_HW_RSTPWD                                               (0x55AA00FFu)

/*! Cache settings */
#define VHSM_HAL_HW_CACHE_BLOCK_SIZE                                     (16U)
#define VHSM_HAL_HW_CACHE_START_OF_BLOCK_MASK                            (0xFFFFFFF0U)
#define VHSM_HAL_HW_CACHE_END_OF_BLOCK_MASK                              (0x0000000FU)

/* Mask is applied to the HOST2HSM register when checking if the IPC is initialized */
#ifndef VHSM_HAL_HOST2HSM_MASK /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
#define VHSM_HAL_HOST2HSM_MASK                                           (0xFFFFFF00u)
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VHSM_HAL_LOCAL) /* COV_VHSM_HAL_LOCAL_DEFINE */
# define VHSM_HAL_LOCAL                                               static
#endif

#if !defined (VHSM_HAL_LOCAL_INLINE) /* COV_VHSM_HAL_LOCAL_DEFINE */
# define VHSM_HAL_LOCAL_INLINE                                        LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VHSM_HAL_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Hal_Bridge_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the Infineon AURIX TC3xx HSM Bridge.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_HAL_LOCAL_INLINE FUNC(void, VHSM_HAL_CODE) vHsm_Hal_Bridge_Init(void);

/**********************************************************************************************************************
 *  vHsm_Hal_Bridge_SetWindow()
 *********************************************************************************************************************/
/*! \brief       Set the base address of the 64k Single Access Window.
 *  \details     The Single Access Window is a part of the bridge to access host memory.
 *  \param[in]   hostAddress   Valid host memory address.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_HAL_LOCAL_INLINE FUNC(void, VHSM_HAL_CODE) vHsm_Hal_Bridge_SetWindow(uint32 hostAddress);

/**********************************************************************************************************************
 *  vHsm_Hal_Bridge_RemapUint32Ptr()
 *********************************************************************************************************************/
/*! \brief       Remaps a host address to the 64k window address on HSM side.
 *  \details     -
 *  \note        This does NOT set the 64k single access window.
 *  \param[in]   hostPtr  Pointer to a host memory address.
 *  \return      Converted address to access the host memory via Single Access Window if the address is in the window.
 *               Otherwise returns NULL_PTR.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_HAL_LOCAL_INLINE
  FUNC(P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR), VHSM_HAL_CODE) vHsm_Hal_Bridge_RemapUint32Ptr(
  P2CONST(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR) hostPtr);

/**********************************************************************************************************************
 *  vHsm_Hal_Bridge_RemapUint8Ptr()
 *********************************************************************************************************************/
/*! \brief       Remaps a host address to the 64k window address on HSM side.
 *  \details     -
 *  \note        This does NOT set the 64k single access window.
 *  \param[in]   hostPtr  Pointer to a host memory address.
 *  \return      Converted address to access the host memory via Single Access Window if the address is in the window.
 *               Otherwise returns NULL_PTR.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_HAL_LOCAL_INLINE
  FUNC(P2VAR(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR), VHSM_HAL_CODE) vHsm_Hal_Bridge_RemapUint8Ptr(
  P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR) hostPtr);

/**********************************************************************************************************************
 *  vHsm_Hal_Cache_CleanData()
 *********************************************************************************************************************/
/*! \brief       Cleans (evicts) all block from the ARM Cortex-M3 cache that correspond to the data buffer.
 *  \details     -
 *  \param[in]   dataPtr    Valid pointer to data buffer.
 *  \param[in]   dataLen    Valid length of data buffer dataPtr.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_HAL_LOCAL_INLINE FUNC(void, VHSM_HAL_CODE) vHsm_Hal_Cache_CleanData(
  P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_DATA) dataPtr,
  uint32 dataLen);

/**********************************************************************************************************************
 *  vHsm_Hal_InvalidateCache()
 *********************************************************************************************************************/
/*! \brief         Invalidate cache blockwise or at once.
 *  \details       -
 *  \pre           -
 *  \param[in]     jobInputOutput     The jobs primitive input output data.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
VHSM_HAL_LOCAL FUNC(void, VHSM_HAL_CODE) vHsm_Hal_InvalidateCache(
  P2CONST(Crypto_JobPrimitiveInputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput);

#define VHSM_HAL_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_HAL_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Hal_Bridge_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_HAL_LOCAL_INLINE FUNC(void, VHSM_HAL_CODE) vHsm_Hal_Bridge_Init(void)
{
  /* Clear HSM to host register */
  HSM_BRIDGE->HSM2HTS = 0u; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */

  /* Reset error flags in bridge */
  HSM_BRIDGE->ERRCTRL = 0xffffffffu; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */

  /* Enable Bridge error reporting, report all possible events */
  HSM_BRIDGE->ERRIE = 0xffffffffu; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
} /* vHsm_Hal_Bridge_Init() */

/**********************************************************************************************************************
 *  vHsm_Hal_Bridge_SetWindow()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_HAL_LOCAL_INLINE FUNC(void, VHSM_HAL_CODE) vHsm_Hal_Bridge_SetWindow(uint32 hostAddress)
{
  HSM_BRIDGE->SAHBASE = (hostAddress & 0xFFFF0000u); /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
} /* vHsm_Hal_Bridge_SetWindow() */

/**********************************************************************************************************************
 *  vHsm_Hal_Bridge_RemapUint32Ptr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_HAL_LOCAL_INLINE
  FUNC(P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR), VHSM_HAL_CODE) vHsm_Hal_Bridge_RemapUint32Ptr(
  P2CONST(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR) hostPtr)
{
  P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR) ret = NULL_PTR;

  if (((uint32)hostPtr & 0xFFFF0000u) == HSM_BRIDGE->SAHBASE) /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  {
    ret = (P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_VAR))(((uint32)hostPtr & 0x0000FFFFu) | (uint32)HSM_BRIDGE->SAHMEM); /* PRQA S 0306, 0303 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS, MD_VHSM_HAL_0303_REGISTER_ACCESS */
  }

  return ret;
} /* vHsm_Hal_Bridge_RemapUint32Ptr() */

/**********************************************************************************************************************
 *  vHsm_Hal_Bridge_RemapUint8Ptr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_HAL_LOCAL_INLINE
FUNC(P2VAR(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR), VHSM_HAL_CODE) vHsm_Hal_Bridge_RemapUint8Ptr(
  P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR) hostPtr)
{
  P2VAR(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR) ret = NULL_PTR;

  if (((uint32)hostPtr & 0xFFFF0000u) == HSM_BRIDGE->SAHBASE) /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  {
    ret = (P2VAR(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR))(((uint32)hostPtr & 0x0000FFFFu) | (uint32)HSM_BRIDGE->SAHMEM); /* PRQA S 0306, 0303 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS, MD_VHSM_HAL_0303_REGISTER_ACCESS */
  }

  return ret;
} /* vHsm_Hal_Bridge_RemapUint8Ptr() */

/*********************************************************************************************************************
 *  vHsm_Hal_Cache_CleanData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_HAL_LOCAL_INLINE FUNC(void, VHSM_HAL_CODE) vHsm_Hal_Cache_CleanData(
  P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_DATA) dataPtr,
  uint32 dataLen)
{
  uint32 startAddress;
  uint32 endAddress;

  /* PRQA S 0306 2 */ /* MD_VHSM_HAL_0306_CHECK_MEMORY_LAYOUT */
  startAddress = ((uint32)dataPtr & VHSM_HAL_HW_CACHE_START_OF_BLOCK_MASK);
  endAddress = (((uint32)dataPtr + dataLen) | VHSM_HAL_HW_CACHE_END_OF_BLOCK_MASK);

  while(endAddress > startAddress)
  {
    HSM_CACHE->CACHE_BC = startAddress; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
    startAddress += VHSM_HAL_HW_CACHE_BLOCK_SIZE;
  }
} /* vHsm_Hal_Cache_CleanData() */

/*********************************************************************************************************************
 *  vHsm_Hal_InvalidateCache()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_HAL_LOCAL FUNC(void, VHSM_HAL_CODE) vHsm_Hal_InvalidateCache(
  P2CONST(Crypto_JobPrimitiveInputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput)
{
  /* Calculate inputlength length sum */
  uint32 inputlengthSum = jobInputOutput->inputLength + jobInputOutput->secondaryInputLength + jobInputOutput->tertiaryInputLength;

  /* Clean cache blocks or whole cache */
  /* In case of datasizes > 4K, we only need a cache clear and do not iterate over single cache blocks */
  if ( inputlengthSum >= 4096u )
  {
    HSM_CACHE->CACHE_AC = 0xff; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  }
  else
  {
    if (NULL_PTR != jobInputOutput->inputPtr)
    {
      vHsm_Hal_Cache_CleanData(jobInputOutput->inputPtr, jobInputOutput->inputLength);
    }
    if (NULL_PTR != jobInputOutput->secondaryInputPtr)
    {
      vHsm_Hal_Cache_CleanData(jobInputOutput->secondaryInputPtr, jobInputOutput->secondaryInputLength);
    }
    if (NULL_PTR != jobInputOutput->tertiaryInputPtr)
    {
      vHsm_Hal_Cache_CleanData(jobInputOutput->tertiaryInputPtr, jobInputOutput->tertiaryInputLength);
    }
  }
}

#define VHSM_HAL_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_HAL_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Hal_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_Init(void)
{
#if (VHSM_HAL_APPLICATION_GENERATE_NOISE == STD_ON)
  uint32 randomSeed;

  /* Provide a random seed value to application cores so they can generate noise while HSM is booting */
  if (vHsm_MemRand((P2VAR(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR))&randomSeed, sizeof( randomSeed )) == E_OK)
  {
    HSM_BRIDGE->HSM2HTS = randomSeed; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  }
#endif /* (VHSM_HAL_APPLICATION_GENERATE_NOISE == STD_ON) */

} /* vHsm_Hal_Init() */

/**********************************************************************************************************************
 *  vHsm_Hal_SystemInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_SystemInit(void)
{
  SuspendAllInterrupts();

  /* Configure interrupts */
  NVIC_ClearPendingIRQ(BridgeErr_IRQn);
  NVIC_ClearPendingIRQ(TRNG_IRQn);
  NVIC_ClearPendingIRQ(Bridge_IRQn);
  NVIC_ClearPendingIRQ(TIM1_IRQn);
  NVIC_DisableIRQ(TIM0_IRQn);

  /* Enable Bridge Service Interrupt here! (CAT1) */
  NVIC_EnableIRQ(Bridge_IRQn);
  /* Enable Timer1 Interrupt  (CAT2) */
  NVIC_EnableIRQ(TIM1_IRQn);

  NVIC_EnableIRQ(BridgeErr_IRQn);

  NVIC_DisableIRQ(SensInt_IRQn);
  NVIC_DisableIRQ(ExtInt_IRQn);

  ResumeAllInterrupts();
} /* vHsm_Hal_SystemInit() */

/**********************************************************************************************************************
 *  vHsm_Hal_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_InitMemory(void)
{
  /* Nothing to do here */
} /* vHsm_Hal_InitMemory() */

/**********************************************************************************************************************
 *  vHsm_Hal_StartApplicationCores()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_StartApplicationCores(void)
{
  vHsm_Hal_HardwareUnitsIterType unitIdx;

  /* Reset status to host, also disable noise generation if it was enabled before */
  HSM_BRIDGE->HSM2HTS = 0u; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */

  /* Start application cores, release waiting SSW */
  HSM_BRIDGE->HSM2HTF = 1u; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */

  for (unitIdx = 0u; unitIdx < vHsm_Hal_GetSizeOfHardwareUnits(); unitIdx++)
  {
    /* Set ACTIVE and READY flags */
    VHSM_HAL_HSM2HOST(unitIdx) = (VHSM_HAL_VHSM_READY | VHSM_HAL_VHSM_ACTIVE); /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  }
} /* vHsm_Hal_StartApplicationCores() */

/**********************************************************************************************************************
 *  vHsm_Hal_StartupCallout()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_StartupCallout(void)
{
  /* Init the bridge module */
  vHsm_Hal_Bridge_Init(); /* PRQA S 2987 */ /* MD_VHSM_HAL_2987_HARDWARE_ACCESS */

  vHsm_Hal_HardwareUnitsIterType unitIdx;

  for (unitIdx = 0u; unitIdx < vHsm_Hal_GetSizeOfHardwareUnits(); unitIdx++)
  {
    /* Clear Hsm2Host register */
    VHSM_HAL_HSM2HOST(unitIdx) = 0u; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
    /* Set ACTIVE flag */
    VHSM_HAL_HSM2HOST(unitIdx) = VHSM_HAL_VHSM_ACTIVE; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  }
} /* vHsm_Hal_StartupCallout() */

/**********************************************************************************************************************
 *  vHsm_Hal_HandleResetInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_HandleResetInfo(void)
{
  /* No implementation yet */

} /* vHsm_Hal_HandleResetInfo() */

#if (VHSM_HAL_CALLOUT_GETCODEFLASHADDRESS == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_GetCodeFlashAddr()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR), VHSM_HAL_CODE) vHsm_Hal_GetCodeFlashAddr(
  P2CONST(uint8, AUTOMATIC, VHSM_HAL_APPL_VAR) offset)
{
  return offset;
} /* vHsm_Hal_GetCodeFlashAddr() */
#endif /* (VHSM_HAL_CALLOUT_GETCODEFLASHADDRESS == STD_ON) */

#if (VHSM_HAL_CALLOUT_PREPAREJOBDATA == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_PrepareCryptoJobData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_PrepareCryptoJobData(
  P2VAR(Crypto_JobPrimitiveInputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* #10 Remap output pointers for access via 64k single access window from HSM side */
  jobInputOutput->outputPtr = vHsm_Hal_Bridge_RemapUint8Ptr(jobInputOutput->outputPtr);
  jobInputOutput->outputLengthPtr = vHsm_Hal_Bridge_RemapUint32Ptr(jobInputOutput->outputLengthPtr);
  jobInputOutput->secondaryOutputPtr = vHsm_Hal_Bridge_RemapUint8Ptr(jobInputOutput->secondaryOutputPtr);
  jobInputOutput->secondaryOutputLengthPtr = vHsm_Hal_Bridge_RemapUint32Ptr(jobInputOutput->secondaryOutputLengthPtr);
  jobInputOutput->verifyPtr = vHsm_Hal_Bridge_RemapUint8Ptr(jobInputOutput->verifyPtr);

  /* #20 Invalidate cache for access to input data */
  vHsm_Hal_InvalidateCache(jobInputOutput);

} /* vHsm_Hal_PrepareCryptoJobData() */

/**********************************************************************************************************************
 *  vHsm_Hal_PrepareCryptoJobDataWithoutLengths()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_PrepareCryptoJobDataWithoutLengths(
  P2VAR(Crypto_JobPrimitiveInputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput)
{
  /* #10 Remap output pointers for access via 64k single access window from HSM side */
  jobInputOutput->outputPtr = vHsm_Hal_Bridge_RemapUint8Ptr(jobInputOutput->outputPtr);
  jobInputOutput->secondaryOutputPtr = vHsm_Hal_Bridge_RemapUint8Ptr(jobInputOutput->secondaryOutputPtr);

  /* #20 Invalidate cache for access to input data */
  vHsm_Hal_InvalidateCache(jobInputOutput);

}/* vHsm_Hal_PrepareCryptoJobDataWithoutLengths */

/**********************************************************************************************************************
 *  vHsm_Hal_PrepareKeyMJobData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_PrepareKeyMJobData(
  P2VAR(vHsm_KeyM_InputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  /* #10 Remap the output pointers for access via 64k single access window from HSM side */
  jobInputOutput->outputPtr = vHsm_Hal_Bridge_RemapUint8Ptr(jobInputOutput->outputPtr);
  jobInputOutput->outputLengthPtr = vHsm_Hal_Bridge_RemapUint32Ptr(jobInputOutput->outputLengthPtr);

  /* #20 Invalidate cache for access to input data */
  if (NULL_PTR != jobInputOutput->inputPtr)
  {
    vHsm_Hal_Cache_CleanData(jobInputOutput->inputPtr, jobInputOutput->inputLength);
  }
} /* vHsm_Hal_PrepareKeyMJobData() */

/**********************************************************************************************************************
 *  vHsm_Hal_PrepareKeyMJobDataWithoutLengths()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_PrepareKeyMJobDataWithoutLengths(
  P2VAR(vHsm_KeyM_InputOutputType, AUTOMATIC, VHSM_HAL_APPL_VAR) jobInputOutput)
{
  /* #10 Remap the output pointers for access via 64k single access window from HSM side */
  jobInputOutput->outputPtr = vHsm_Hal_Bridge_RemapUint8Ptr(jobInputOutput->outputPtr);

  /* #20 Invalidate cache for access to input data */
  if (NULL_PTR != jobInputOutput->inputPtr)
  {
    vHsm_Hal_Cache_CleanData(jobInputOutput->inputPtr, jobInputOutput->inputLength);
  }
} /* vHsm_Hal_PrepareKeyMJobDataWithoutLengths */
#endif /* (VHSM_HAL_CALLOUT_PREPAREJOBDATA == STD_ON) */

#if (VHSM_HAL_CALLOUT_GETIPCADDRESS == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_GetIpcAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_DATA), VHSM_HAL_CODE) vHsm_Hal_GetIpcAddress(
  uint32 index,
  P2VAR(uint32, AUTOMATIC, VHSM_HAL_APPL_DATA) address) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  VHSM_HAL_DUMMY_STATEMENT(index); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* Set the 64k single access window of the bridge to the IPC address */
  vHsm_Hal_Bridge_SetWindow((uint32)address); /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_CHECK_MEMORY_LAYOUT */
  /* Return the modified address pointing to the window */
  return vHsm_Hal_Bridge_RemapUint32Ptr(address);
} /* vHsm_Hal_GetIpcAddress() */
#endif /* (VHSM_HAL_CALLOUT_GETIPCADDRESS == STD_ON) */

/**********************************************************************************************************************
 *  vHsm_Hal_ApplicationIpcInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VHSM_HAL_CODE) vHsm_Hal_ApplicationIpcInit(
  vHsm_IpcInstanceIterType ipc)
{
  boolean retVal = FALSE;

  /* Check Host2Hsm if ipc is initialized */
  /* The HOST2HSM register needs to be initilized to zero once at the very beginning during the host startup */
  /* This is because on some hardware revisions the register might not be zero at startup */
  if((VHSM_HAL_HOST2HSM(ipc) & (VHSM_HAL_HOST2HSM_MASK | VHSM_HAL_IPC_INIT(ipc))) == VHSM_HAL_IPC_INIT(ipc)) /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  {
    retVal = TRUE;
  }

  return retVal;
} /* vHsm_Hal_ApplicationIpcInit */

#if (VHSM_HAL_CALLOUT_DEBUGGERPRESENCE == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_IsDebuggerPresent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, VHSM_HAL_CODE) vHsm_Hal_IsDebuggerPresent(void)
{
  return ((HSM_BRIDGE->ERRCTRL & ERRCTRL_XDBG_Msk) == ERRCTRL_XDBG_Msk); /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
} /* vHsm_Hal_IsDebuggerPresent */
#endif /* (VHSM_HAL_CALLOUT_DEBUGGERPRESENCE == STD_ON) */

#define VHSM_HAL_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSM_HAL_START_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_HAL_CALLOUT_TRIGGERSOFTWARERESET == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_TriggerSoftwareReset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_TriggerSoftwareReset(void) /* COV_VHSM_HAL_TRIGGER_SOFTWARE_RESET */
{
  vHsm_Hal_HardwareUnitsIterType unitIdx;
  volatile boolean loop = TRUE;

  for (unitIdx = 0u; unitIdx < vHsm_Hal_GetSizeOfHardwareUnits(); unitIdx++)
  {
    /* Clear Hsm2Host register */
    VHSM_HAL_HSM2HOST(unitIdx) = 0u; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  }

  /* Trigger software reset */
  HSM_BRIDGE->RSTPWD = VHSM_HAL_HW_RSTPWD; /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */
  HSM_BRIDGE->RSTCTRL = (RSTCTRL_SYSRST_Msk | RSTCTRL_APPRST_Msk); /* PRQA S 0306 */ /* MD_VHSM_HAL_0306_REGISTER_ACCESS */

  while (loop)
  {
    /* If reset was not successful stay here */
  }
} /* vHsm_Hal_TriggerSoftwareReset() */
#endif /* (VHSM_HAL_CALLOUT_TRIGGERSOFTWARERESET == STD_ON) */

#if (VHSM_HAL_CALLOUT_MANAGECODEFLASHACCESS == STD_ON) /* COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  vHsm_Hal_EnableCodeFlashAccess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_EnableCodeFlashAccess(void)
{

} /* vHsm_Hal_EnableCodeFlashAccess() */

/**********************************************************************************************************************
 *  vHsm_Hal_DisableCodeFlashAccess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_HAL_CODE) vHsm_Hal_DisableCodeFlashAccess(void)
{

} /* vHsm_Hal_DisableCodeFlashAccess() */
#endif /* (VHSM_HAL_CALLOUT_MANAGECODEFLASHACCESS == STD_ON) */

#define VHSM_HAL_STOP_SEC_RAMCODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Module specific MISRA deviations

MD_VHSM_HAL_0306_REGISTER_ACCESS:
Reason:     Access to registers of the hardware using an address.
Risk:       Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention: vHsm for specific hardware (pointer size type can not differ). Valid memory access with correct address covered by code review.

MD_VHSM_HAL_0303_REGISTER_ACCESS:
Reason:     Addressing memory mapped registers or other hardware specific feature requires casting a pointer type to
            an integral type. This is a usual pattern for MCAL (Micro Controller Abstraction Layer) software.
Risk:       Unintended read or write access into memory location.
Prevention: Code inspection focus on correct access to expected memory location.

MD_VHSM_HAL_2987_HARDWARE_ACCESS:
Reason:     Function call produces no side effects and is redundant. This is because QAC does not identify sideeffects for a register access.
Risk:       No risk.
Prevention: Code review, tests.

MD_VHSM_HAL_0306_CHECK_MEMORY_LAYOUT:
Reason:     Cast needed to evaluate if the pointer address is located in a specific memory region.
Risk:       Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
Prevention: vHsm for specific hardware(32 - Bit platforms) (pointer size type can not differ). Valid memory access ensured by code review and test.

MD_VHSM_3630_GLOBAL_TYPE:
Reason:     The struct implemenation is visible globally.
Risk:       None.
Prevention: None.
 */

/* COV_JUSTIFICATION_BEGIN

\ID COV_VHSM_HAL_NOTESTING
\ACCEPT           X
\REASON           Function is not covered because it is an interrupt handler or would trigger an reset.
\PREVENTION       Covered by code review and manual tests.

\ID COV_VHSM_HAL_TRIGGER_SOFTWARE_RESET
\ACCEPT           X
\REASON           Software reset can not be covered during the automated testsuite, because the coverage data will be lost.
\PREVENTION       Covered by code review and manual tests

\ID COV_VHSM_HAL_LOCAL_DEFINE
\ACCEPT           XF
\ACCEPT           TX
\ACCEPT           XX
\REASON           Ensures that LOCAL and LOCAL_INLINE are always set if not set yet from outside.

\ID COV_VHSM_HAL_HARDWARE_DEPENDENT_FEATURE
\ACCEPT           XF
\ACCEPT           TX
\REASON           Feature is not supported on some platforms and will not be enabled on those.
\PREVENTION       Covered by code review and tests. The configuration cannot be changed by the user.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Hal.c
 *********************************************************************************************************************/
