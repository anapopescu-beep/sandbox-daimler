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
/*!        \file  Crypto_30_Hwa_Random.c
 *        \brief  Crypto Hwa Random implementation
 *
 *      \details  This file implements Random Number Generation algorithm.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_RANDOM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Crypto_30_Hwa.h"
#include "Crypto_30_Hwa_Private.h"
#include "Crypto_30_Hwa_Hw_Cfg.h"
#include "Crypto_30_Hwa_Types.h"

#include "vstdlib.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (CRYPTO_30_HWA_LOCAL) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL                                               static
#endif

#if !defined (CRYPTO_30_HWA_LOCAL_INLINE) /* COV_CRYPTO_30_HWA_LOCAL_DEFINE */
# define CRYPTO_30_HWA_LOCAL_INLINE                                        LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)

typedef struct
{
  uint8 buffer[CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY_CEIL];
  uint8 read_idx;
  uint8 write_idx;
  uint8 count;
} Crypto_30_Hwa_TrngPrefetchRingbuf;

#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)

CRYPTO_30_HWA_LOCAL VAR(Crypto_30_Hwa_TrngPrefetchRingbuf, CRYPTO_30_HWA_VAR_NOINIT) Crypto_30_Hwa_TrngPrefetchBuf;

#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

#define CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CRYPTO_30_HWA_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if(CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngBufIncrement()
 *********************************************************************************************************************/
/*! \brief          Increment indices of the ring buffer by a certain amount of steps.
 *  \details        Increment is done considering ring buffer capacity.
 *  \param[in]      bufIndex           Index that is incremented.
 *  \param[in]      steps              Increment value by steps.
 *  \return         Incremented index value.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngBufIncrement(
  uint8 bufIndex,
  uint8 steps);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngBufWriteElement()
 *********************************************************************************************************************/
/*! \brief          Copy bytes into the ring buffer.
 *  \details        -
 *  \param[in]      srcPtr             Source to copy data from.
 *  \param[in]      length             Amount of data that should be written to buffer
 *  \pre            Must run in critical section/ exclusive area.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngBufWriteElement(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) srcPtr,
  uint8 length);

/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngBufReadElement()
 *********************************************************************************************************************/
/*! \brief          Copy bytes from the ring buffer.
 *  \details        -
 *  \param[in,out]  dstPtr             Destination to copy data to.
 *  \param[in,out]  lengthPtr          Amount of requested data and on return amount of actually read data.
 *  \pre            Must run in critical section/ exclusive area.
 *  \context        TASK
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngBufReadElement(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) lengthPtr);
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

#if(CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_MemRandSlicing()
 *********************************************************************************************************************/
/*! \brief          Splits data blocks according a threashold and sends it to the hardware
 *  \details        -
 *  \param[out]     dstPtr             Output buffer.
 *  \param[in]      length             Length of requested data to be copied into dstPtr
 *  \return         E_OK               Generation of random numbers was successful.
 *                  E_NOT_OK           Generation of random numbers failed.
 *  \pre            -
 *  \context        TASK
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *********************************************************************************************************************/
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_MemRandSlicing(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr,
  uint32 length);
#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

# define CRYPTO_30_HWA_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

# define CRYPTO_30_HWA_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_MemRandSlicing()
 **********************************************************************************************************************/
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
CRYPTO_30_HWA_LOCAL_INLINE FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_MemRandSlicing(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr,
  uint32 length)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (CRYPTO_30_HWA_DATA_SLICING == STD_ON)
  uint32 i;
  uint32 reminder = length % CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE_ROUNDED_TRNG;
#endif

  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
#if (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  Crypto_30_Hwa_Hw_TrngDisableIrq();
#endif
#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)
  if (Crypto_30_Hwa_Hw_IsTrngOn() == FALSE)
#endif
  {
    Crypto_30_Hwa_Hw_TrngRestart();
  }
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();

#if (CRYPTO_30_HWA_DATA_SLICING == STD_ON)
  /* Process multiples of CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE */
  for (i = 0; i < (length / CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE_ROUNDED_TRNG); ++i)
  {
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
    retVal |= Crypto_30_Hwa_Hw_MemRand(&dstPtr[i *  CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE_ROUNDED_TRNG], CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE_ROUNDED_TRNG);
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
  }

  /* Process not multiples of CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE */
  if (reminder > 0u)
  {
    SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
    retVal |= Crypto_30_Hwa_Hw_MemRand(&dstPtr[i *  CRYPTO_30_HWA_NON_PREEMPTIVE_CHUNK_SIZE_ROUNDED_TRNG], reminder);
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
  }

#else
  retVal = Crypto_30_Hwa_Hw_MemRand(dstPtr, length);
#endif /* (CRYPTO_30_HWA_DATA_SLICING == STD_ON) */

  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  Crypto_30_Hwa_Hw_TrngDisableGenerator();
#elif (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
  Crypto_30_Hwa_Hw_TrngEnableIrq();
#endif
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();

  return retVal;
}
#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngBufIncrement()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(uint8, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngBufIncrement(uint8 bufIndex, uint8 steps)
{
  return (uint8)((bufIndex + steps) % (uint8)(CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY_CEIL));
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngBufWriteElement()
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
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngBufWriteElement(
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) srcPtr,
  uint8 length)
{
  uint8 writeFromStart;
  uint8 writeToEnd;
  uint8 bytesToWrite;

  /* Calculate remaining capacity */
  bytesToWrite = (uint8)(CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY_CEIL - Crypto_30_Hwa_TrngPrefetchBuf.count);
  writeToEnd = (uint8)(CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY_CEIL - Crypto_30_Hwa_TrngPrefetchBuf.write_idx);

  /* If there are less free elements available in the buffer than we want to write, adapt the desired number of elements to write */
  if (length < bytesToWrite)
  {
    bytesToWrite = length;
  }

  /* If destination number is smaller than the number of free elements until the end of the buffer, adapt number of first bytes to write */
  if (bytesToWrite < writeToEnd)
  {
    writeToEnd = bytesToWrite;
  }
  /* Copy elements into the ring buffer */
  VStdLib_MemCpy(&(Crypto_30_Hwa_TrngPrefetchBuf.buffer[Crypto_30_Hwa_TrngPrefetchBuf.write_idx]), srcPtr, writeToEnd); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* Check if we have to perform second memcopy operation from the beginning of the buffer until the desired length is written. */
  writeFromStart = (uint8)(bytesToWrite - writeToEnd);
  if (writeFromStart > 0u)
  {
    VStdLib_MemCpy(&(Crypto_30_Hwa_TrngPrefetchBuf.buffer[0]), &(srcPtr[writeToEnd]), writeFromStart); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  }

  /* Increase the write index and count of the buffer according to its borders. */
  Crypto_30_Hwa_TrngPrefetchBuf.write_idx = Crypto_30_Hwa_TrngBufIncrement(Crypto_30_Hwa_TrngPrefetchBuf.write_idx, bytesToWrite);
  Crypto_30_Hwa_TrngPrefetchBuf.count = (uint8)(Crypto_30_Hwa_TrngPrefetchBuf.count + bytesToWrite);
}

/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngBufReadElement()
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
 */
CRYPTO_30_HWA_LOCAL_INLINE FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngBufReadElement(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) lengthPtr)
{
  uint8 readToEnd;
  uint8 readFromStart;
  uint8 tmpLength;

  /* Check if buffer is empty */
  if (Crypto_30_Hwa_TrngPrefetchBuf.count == 0u)
  {
    /* buffer empty. Nothing to read. */
    *lengthPtr = 0;
  }
  else
  {
    /* We have at least one element to read, check if buffer is full */
    /* Get number of elements from the current position of the read pointer until the end of buffer */
    readToEnd = (uint8)(CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY_CEIL - Crypto_30_Hwa_TrngPrefetchBuf.read_idx);

    /* If there are less bytes in the buffer than we want to read, adapt desired length */
    if (Crypto_30_Hwa_TrngPrefetchBuf.count < (*lengthPtr))
    {
      *lengthPtr = Crypto_30_Hwa_TrngPrefetchBuf.count;
    }

    /* If we want to read less bytes than there are available until the end of the buffer, adapt number of elements to read */
    if ((*lengthPtr) < readToEnd)
    {
      readToEnd = (uint8)(*lengthPtr);
    }

    /* Copy first n bytes from the ring buffer into the destination buffer */
    VStdLib_MemCpy(dstPtr, &(Crypto_30_Hwa_TrngPrefetchBuf.buffer[Crypto_30_Hwa_TrngPrefetchBuf.read_idx]), readToEnd);/* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

    /* Check if we have to perform a second memcopy. This one starts from index 0 until the remainder of the desired length is read */
    readFromStart = (uint8)((*lengthPtr) - readToEnd);
    if (readFromStart > 0u)
    {
      VStdLib_MemCpy(&(dstPtr[readToEnd]), &(Crypto_30_Hwa_TrngPrefetchBuf.buffer[0]), readFromStart); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    }

    tmpLength = (uint8)(*lengthPtr);

    /* Correct size to next full hardware block */
    if (((*lengthPtr) % CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES) > 0u)
    {
      tmpLength = (uint8)(tmpLength + (CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES - ((*lengthPtr) % CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES)));
    }

    /* Increment read pointer according to buffer borders */
    Crypto_30_Hwa_TrngPrefetchBuf.read_idx = Crypto_30_Hwa_TrngBufIncrement(Crypto_30_Hwa_TrngPrefetchBuf.read_idx, tmpLength);

    /* Decrement buffer size */
    Crypto_30_Hwa_TrngPrefetchBuf.count = (uint8)(Crypto_30_Hwa_TrngPrefetchBuf.count - (uint8)(*lengthPtr));
  }
}
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

# define CRYPTO_30_HWA_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
# define CRYPTO_30_HWA_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if(CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngProcessDataReady()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngProcessDataReady(void)
{
  uint32 length = CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES;
  uint8 data[CRYPTO_30_HWA_TRNG_BLOCK_LENGTH_BYTES];

  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();

  if (Crypto_30_Hwa_Hw_TrngGetData(&data[0], &length) == E_OK)
  {
    Crypto_30_Hwa_TrngBufWriteElement(&data[0], (uint8)length);

    if (Crypto_30_Hwa_TrngPrefetchBuf.count == CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY_CEIL)
    {
      Crypto_30_Hwa_Hw_TrngDisableGenerator();
    }
  }
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
}

#if (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_OFF) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngPrefetch()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngPrefetch(void)
{
  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();

  if (Crypto_30_Hwa_Hw_IsTrngOn() == TRUE)
  {
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();

    /* Check if data is ready by polling */
    Crypto_30_Hwa_TrngProcessDataReady();
  }
  else if (Crypto_30_Hwa_TrngPrefetchBuf.count < CRYPTO_30_HWA_TRNG_PREFETCH_CAPACITY_CEIL)
  {
    /* Start random number generation */
    Crypto_30_Hwa_Hw_TrngRestart();
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
  }
  else
  {
    SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
    /* Buffer is full and Trng is off */
  }
}
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCH_WITH_INTERRUPT == STD_OFF) */

/**********************************************************************************************************************
 *  Crypto_30_Hwa_InitTrngPrefetching()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_InitTrngPrefetching(void)
{
  /* Clear ring buffer */
  VStdLib_MemClr(&Crypto_30_Hwa_TrngPrefetchBuf, sizeof(Crypto_30_Hwa_TrngPrefetchRingbuf)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* Enable random number generation */
  Crypto_30_Hwa_Hw_TrngRestart();
}
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_TrngFinish()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_TrngFinish(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) dstPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_HWA_APPL_VAR) LengthPtr) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  uint32 bytesRead;
  uint32 bytesToRead;
  Std_ReturnType retval = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)
  bytesRead = *LengthPtr;

  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
  Crypto_30_Hwa_TrngBufReadElement(dstPtr, &bytesRead);
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();

  bytesToRead = (*LengthPtr - bytesRead);
#else
  bytesRead = 0;
  bytesToRead = *LengthPtr;
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

  /* Check if we need to get more data here because buffer was too small */
  if (bytesToRead > 0u)
  {
    retval = Crypto_30_Hwa_MemRandSlicing(&dstPtr[bytesRead], bytesToRead);
  }

#if (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON)
  /* if prefetcher is idle, enable it */
  SchM_Enter_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
  if (Crypto_30_Hwa_Hw_IsTrngOn() == FALSE)
  {
    Crypto_30_Hwa_Hw_TrngRestart();
  }
  SchM_Exit_Crypto_30_Hwa_CRYPTO_30_HWA_EXCLUSIVE_AREA_3();
#endif /* (CRYPTO_30_HWA_TRNG_PREFETCHING == STD_ON) */

  return retval;
} /* Crypto_30_Hwa_TrngFinish() */

#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

#if (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) /* COV_CRYPTO_30_HWA_HARDWARE_DEPENDENT_FEATURE */
/**********************************************************************************************************************
 *  Crypto_30_Hwa_ProcessTrngJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CRYPTO_30_HWA_CODE) Crypto_30_Hwa_ProcessTrngJob(
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_HWA_APPL_DATA) errorIdPtr,
  Crypto_30_Hwa_JobPtrType job)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* #10 Verify whether family is correct */
  if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_RNG)
  {
    /* [SWS_Crypto_00017] [SWS_Crypto_00020] START while IDLE or ACTIVE */
    if (((job->state == CRYPTO_JOBSTATE_IDLE) || (job->state == CRYPTO_JOBSTATE_ACTIVE))
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_START))
    {
      retVal = E_OK;
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* UPDATE while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_UPDATE)) /* [SWS_Crypto_00024] */
    {
      retVal = E_OK;
      Crypto_30_Hwa_UpdateJobState(retVal, job); /* SBSW_CRYPTO_30_HWA_FORWARDING_OF_JOB_PTR */
    }

    /* [SWS_Crypto_00023] FINISH while ACTIVE */
    if ((job->state == CRYPTO_JOBSTATE_ACTIVE)
      && Crypto_30_Hwa_IsJobMode(job, CRYPTO_OPERATIONMODE_FINISH)) /* [SWS_Crypto_00024] */
    {
      retVal = Crypto_30_Hwa_TrngFinish(job->jobPrimitiveInputOutput.outputPtr, job->jobPrimitiveInputOutput.outputLengthPtr);
      job->state = CRYPTO_JOBSTATE_IDLE; /* SBSW_CRYPTO_30_HWA_DIRECT_ACCESS_TO_JOB_STATE */
    }

    *errorIdPtr = CRYPTO_E_NO_ERROR;
  }

  return retVal;
} /* Crypto_30_Hwa_ProcessTrngJob() */
#endif /* (CRYPTO_30_HWA_PRIMITIVE_RNG == STD_ON) */

# define CRYPTO_30_HWA_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_Hwa_Random.c
 *********************************************************************************************************************/
