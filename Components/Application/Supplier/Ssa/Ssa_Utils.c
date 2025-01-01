/**********************************************************************************************************************
 *  COPYRIGHT
 *  ------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/*!        \file  Ssa_Utils.c
 *        \brief  Shared (library) code shared between multiple software components of the SSA.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Rte.h"
#include "Ssa_Cfg.h"
#include "Ssa_Utils.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define SSA_MEMCPY32ALIGN                                             (sizeof(uint32) - 1u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#define Ssa_Cdd_START_SEC_CODE
#include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Ssa_AsyncPreAction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_AsyncPreAction(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) state, /* PRQA S 3673 */ /* MD_SSA_PARAM_NOT_P2CONST */
  boolean isAsync)
{
  Std_ReturnType retVal = SSA_E_PENDING;

  if (isAsync == TRUE)
  {
    if (*state == SSA_ASYNC_STATE_IDLE)
    {
      *state = SSA_ASYNC_STATE_WAIT;
      retVal = E_OK;
    }
    /* If *state != SSA_ASYNC_STATE_IDLE, retVal remains PENDING. */
  }
  else
  {
    retVal = E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  Ssa_AsyncPostAction()
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
 *
 *
 *
 *
 */
FUNC(void, Ssa_Cdd_CODE) Ssa_AsyncPostAction(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) state,
  Std_ReturnType previouslyReturned,
  boolean isAsync)
{
  if (previouslyReturned == SSA_CRYPTO_E_BUSY)
  {
    /* CSM cannot currently process our request => try again */
    *state = SSA_ASYNC_STATE_IDLE;
  }
  else
  {
    if (isAsync == TRUE)
    {
      if (previouslyReturned == SSA_CRYPTO_E_QUEUE_FULL)
      {
        /* CSM cannot currently process our request => try again */
        *state = SSA_ASYNC_STATE_IDLE;
      }
      else if (previouslyReturned == E_OK)
      {
        /* CSM took our request => wait for the callback which brings us the result
         * and which might have already occurred.
         * State is either still WAIT or already READY. */
      }
      else
      {
        /* Other error code was returned */
        *state = SSA_ASYNC_STATE_FAILED;
      }
    }
    else
    {
      if (previouslyReturned == E_OK)
      {
        /* CSM finished the operation successfully */
        *state = SSA_ASYNC_STATE_READY;
      }
      else
      {
        /* Other error code was returned */
        *state = SSA_ASYNC_STATE_FAILED;
      }
    }
  }
}

/**********************************************************************************************************************
 *  Ssa_AsyncFinalize()
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
 *
 *
 *
 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_AsyncFinalize(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) state,
  boolean isAsync)
{
  Std_ReturnType retVal;

  if (*state == SSA_ASYNC_STATE_IDLE)
  {
    /* We need to try again. */
    retVal = SSA_E_PENDING;
  }
  else if ((isAsync == TRUE) && (*state == SSA_ASYNC_STATE_WAIT))
  {
    /* Waiting for callback */
    retVal = SSA_E_PENDING;
  }
  else if (*state == SSA_ASYNC_STATE_READY)
  {
    /* Callback returned successfully */
    *state = SSA_ASYNC_STATE_IDLE;
    retVal = E_OK;
  }
  else
  {
    /* Callback returned with error */
    *state = SSA_ASYNC_STATE_IDLE;
    retVal = E_NOT_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 * Ssa_Utils_ConvertSerialNumber()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Utils_ConvertSerialNumber(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) serialNumber_in,
  uint16 serialNumberLength_in,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) serialNumber_out,
  uint16 serialNumberLength_out)
{
  Std_ReturnType retVal = E_OK;
  uint16 leadingZeros = 0u, i;

  if (serialNumberLength_in > serialNumberLength_out)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    /* #10 Copy the serial number right-aligned into the output buffer of fixed size and prepend leading zeros if required. */
    /* prepend leading zeros */
    if (serialNumberLength_in < serialNumberLength_out)
    {
      leadingZeros = serialNumberLength_out - serialNumberLength_in;
    }

    /* copy the serial number from certificate,
     * also if leading zeroes is 0 because serialNumber_out might be different from serialNumber_in */
    for (i = 0; i < serialNumberLength_in; i++) /* FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
    {
      serialNumber_out[serialNumberLength_out - i - 1u] = serialNumber_in[serialNumberLength_in - i - 1u]; /* VCA_SSA_UTILS_WRITE_SERIAL_NUMBER */
    }

    if (leadingZeros != 0u)
    {
      Ssa_Utils_MemClr(serialNumber_out, leadingZeros); /* VCA_SSA_UTILS_LEADING_ZEROS_OF_SERIAL_NUMBER */
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Ssa_Utils_MemSet()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, Ssa_Cdd_CODE) Ssa_Utils_MemSet(P2VAR(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) targetDataBuf, uint8 data, uint16_least dataLength)
{
  uint16_least byteIdx;

  /* #10 Set each byte of the target data buffer to the given data value. */
  for (byteIdx = 0u; byteIdx < dataLength; byteIdx++) /* FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
  {
    targetDataBuf[byteIdx] = data; /* VCA_SSA_UTILS_WRITE_WITH_LENGTH_REQUIREMENT */
  }
}

/**********************************************************************************************************************
 * Ssa_Utils_MemCpy()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, Ssa_Cdd_CODE) Ssa_Utils_MemCpy(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) targetBuf,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) dataBuf,
  uint32_least dataLength)
{
  uint32_least byteIdx;

  /* #10 Copy data from input buffer to the target buffer byte-by-byte. */
  for (byteIdx = 0u; byteIdx < dataLength; byteIdx++) /* FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
  {
    targetBuf[byteIdx] = dataBuf[byteIdx]; /* VCA_SSA_UTILS_WRITE_WITH_LENGTH_REQUIREMENT */
  }
}

/**********************************************************************************************************************
 * Ssa_Utils_MemCpy32()
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
 */
FUNC(void, Ssa_Cdd_CODE) Ssa_Utils_MemCpy32(
  P2VAR(void, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) destination,
  P2CONST(void, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) source,
  uint32_least num)
{
  P2CONST(uint32, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) asrc = (P2CONST(uint32, AUTOMATIC, RTE_SSA_CDD_APPL_DATA))source; /* PRQA S 0316 */ /* MD_SSA_CPYFCT_PTRCAST */
  P2VAR(uint32, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) adst = (P2VAR(uint32, AUTOMATIC, RTE_SSA_CDD_APPL_VAR))destination;  /* PRQA S 0316 */ /* MD_SSA_CPYFCT_PTRCAST */
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA))source;    /* PRQA S 0316 */ /* MD_SSA_CPYFCT_PTRCAST */
  P2VAR(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_VAR))destination;     /* PRQA S 0316 */ /* MD_SSA_CPYFCT_PTRCAST */
  uint32_least i = 0u;

  /* #10 Check that 16 or more bytes shall be copied. */
  if (num >= 16u)
  {
    /* #20 Check that source and destination pointers are 32 bit aligned. */
    if (((((uint32)src) & SSA_MEMCPY32ALIGN) == 0u) && ((((uint32)dst) & SSA_MEMCPY32ALIGN) == 0u)) /* PRQA S 0306 */ /* MD_SSA_UTILS_11.3 */
    {
      /* #30 Copy 16 bytes data blocks 32bit-wise in a loop. */
      uint32_least asize = num / sizeof(uint32);
      uint32_least rem = num & SSA_MEMCPY32ALIGN;
      for (i = 0u; (i + 3u) < asize; i += 4u) /* FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
      {
        adst[i] = asrc[i];            /* VCA_SSA_UTILS_MEMCPY_32_ALIGNED */
        adst[i + 1u] = asrc[i + 1u];  /* VCA_SSA_UTILS_MEMCPY_32_ALIGNED */
        adst[i + 2u] = asrc[i + 2u];  /* VCA_SSA_UTILS_MEMCPY_32_ALIGNED */
        adst[i + 3u] = asrc[i + 3u];  /* VCA_SSA_UTILS_MEMCPY_32_ALIGNED */
      }

      while (i < asize) /* FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
      {
        adst[i] = asrc[i];            /* VCA_SSA_UTILS_MEMCPY_32_ALIGNED_REMAINDER */
        ++i;
      }
      i = num - rem;
    }
    /* #40 Else (not 32 bit aligned). */
    else
    {
      /* #50 Copy 16 bytes data blocks byte-wise in a loop. */
      for (i = 0u; (i + 15u) < num; i += 16u) /*lint !e440 */ /* FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
      {
        dst[i] = src[i];              /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 1u] = src[i + 1u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 2u] = src[i + 2u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 3u] = src[i + 3u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 4u] = src[i + 4u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 5u] = src[i + 5u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 6u] = src[i + 6u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 7u] = src[i + 7u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 8u] = src[i + 8u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 9u] = src[i + 9u];    /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 10u] = src[i + 10u];  /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 11u] = src[i + 11u];  /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 12u] = src[i + 12u];  /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 13u] = src[i + 13u];  /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 14u] = src[i + 14u];  /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
        dst[i + 15u] = src[i + 15u];  /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED */
      }
    }
  }
  /* #60 Copy the remaining data byte-wise. */
  while (i < num) /* FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
  {
    dst[i] = src[i];  /* VCA_SSA_UTILS_MEMCPY_32_UNALIGNED_REMAINDER */
    ++i;
  }
}

/**********************************************************************************************************************
 *  Ssa_Utils_MemCmp()
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
FUNC(boolean, Ssa_Cdd_CODE) Ssa_Utils_MemCmp(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) data1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) data2,
  uint16 dataLength)
{
  uint16 byteIdx;
  boolean isEqual = TRUE;
  /* #10 Compare both data buffers byte-by-byte. */
  for (byteIdx = 0u; byteIdx < dataLength; byteIdx++) /* FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
  {
    /* #20 Once there is a difference leave the function with negative result. */
    if (data1[byteIdx] != data2[byteIdx])
    {
      isEqual = FALSE;
    }
  }
  return isEqual;
}

/**********************************************************************************************************************
*  Ssa_Utils_MemCmp_WithLengths()
**********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
FUNC(boolean, Ssa_Cdd_CODE) Ssa_Utils_MemCmp_WithLengths(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) data1,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CDD_APPL_DATA) data2,
  uint16 dataLength1,
  uint32 dataLength2)
{
  boolean isEqual = TRUE;
  /* #5 Compare the length of the data buffers */
  if (dataLength1 != dataLength2)
  {
    isEqual = FALSE;
  }
  else
  {
    /* #10 Compare both data buffers byte-by-byte. */
    isEqual = Ssa_Utils_MemCmp(data1, data2, dataLength1);
  }
  return isEqual;
}

#define Ssa_Cdd_STOP_SEC_CODE
#include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  SAFEBSW JUSTIFICATIONS
 *********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

  \ID  VCA_SSA_UTILS_WRITE_WITH_LENGTH_REQUIREMENT
    \DESCRIPTION      According to VCA, write access to buffer[idx] may be out of bounds.
    \COUNTERMEASURE   \R The function has a requirement that ensures that $lengthOf(buffer) >= len.
                         idx is limited by a for loop to a value < len.
                         The write access is thus in bounds.

  \ID  VCA_SSA_UTILS_WRITE_SERIAL_NUMBER
    \DESCRIPTION      According to VCA, write access to serialNumber_out[serialNumberLength_out - i - 1u]
                      may be out of bounds.
    \COUNTERMEASURE   \R A surrounding for loop bounds the value of i to a value < serialNumberLength_in.
                      A check at the beginning of the function ensures that serialNumberLength_in <= serialNumberLength_out.
                      i is thus in the range [0, serialNumberLength_out - 1].
                      Therefore, serialNumberLength_out - i - 1u is in the range [0, serialNumberLength_out - 1].
                      Since a function requirement ensures that $lengthOf(serialNumber_out) >= serialNumberLength_out,
                      the access is valid.

  \ID  VCA_SSA_UTILS_LEADING_ZEROS_OF_SERIAL_NUMBER
    \DESCRIPTION      According to VCA, the following function call may be outside its specification:
                      Ssa_Utils_MemClr(serialNumber_out, leadingZeros);
    \COUNTERMEASURE   \R Ssa_Utils_MemClr is a function-like macro, so that finally Ssa_Utils_MemSet() is called.
                      The specification requires Ssa_Utils_MemSet(targetDataBuf, uint8 data, uint16_least dataLength)
                      to be called when targetDataBuf is a valid pointer and when the length of targetDataBuf is at
                      least dataLength.
                      In the justified position, this function is called with the parameter serialNumber_out as targetDataBuf
                      and with a local variable as length value. serialNumber_out is required to be a valid pointer
                      of length >= serialNumberLength_out.
                      When calling Ssa_Utils_MemSet, the value of the local variable passed on as dataLength is
                      bounded from above by the value of serialNumberLength_out.

  \ID  VCA_SSA_UTILS_MEMCPY_32_ALIGNED
    \DESCRIPTION      According to VCA, write access to adst[$range(i, i + 3u)] may be out of bounds.
    \COUNTERMEASURE   \R adst is an uint32 pointer to the buffer destination.
                         A runtime check ensures that the pointer is uint32-aligned.
                         A function requirement ensures that the buffer destination has a length >= num.
                         The maximum length asize of the buffer when considered as uint32 elements has been calculated
                         by dividing num by sizeof(uint32).
                         The loop condition ensures that i is < (asize - 3). The index can at most yield an index
                         of (i + 3), which is < num. The access is thus in bounds.

  \ID  VCA_SSA_UTILS_MEMCPY_32_ALIGNED_REMAINDER
    \DESCRIPTION      According to VCA, write access to adst[i] may be out of bounds.
    \COUNTERMEASURE   \R adst is an uint32 pointer to the buffer destination.
                         A runtime check ensures that the pointer is uint32-aligned.
                         A function requirement ensures that the buffer destination has a length >= num.
                         The maximum length asize of the buffer when considered as uint32 elements has been calculated
                         by dividing num by sizeof(uint32).
                         The loop condition ensures that i is < asize. The access is thus valid.

  \ID  VCA_SSA_UTILS_MEMCPY_32_UNALIGNED
    \DESCRIPTION      According to VCA, write access to dst[$range(i, i + 15u)] may be out of bounds.
    \COUNTERMEASURE   \R i is bounded by the loop condition to a value < (num - 15).
                         dst is an uint8 pointer that points to the buffer destination.
                         The function's requirements ensure that $lengthOf(destination) >= num.
                         Since the index calculation can at most yield an index of (i + 15), which is < num,
                         the access is in bounds.

  \ID  VCA_SSA_UTILS_MEMCPY_32_UNALIGNED_REMAINDER
    \DESCRIPTION      According to VCA, write access to dst[i] may be out of bounds.
    \COUNTERMEASURE   \R i is bounded by the loop condition to a value < num.
                         dst is an uint8 pointer that points to the buffer destination.
                         The function's requirements ensure that $lengthOf(destination) >= num.
                         The access is thus in bounds.

  VCA_JUSTIFICATION_END */

/* FETA_JUSTIFICATION_BEGIN
  \ID FETA_SSA_UTILS_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - Ssa_Utils_ConvertSerialNumber()
                  - Ssa_Utils_MemSet()
                  - Ssa_Utils_MemCpy()
                  - Ssa_Utils_MemCpy32()
                  - Ssa_Utils_MemCmp()
    \COUNTERMEASURE \N The here applied loop uses a variable as upper bound that remains unchanged during loop
                       execution. The loop's type of the counter variable is appropriate for the loop's type of upper
                       bound variable and is increased once within each single loop (strictly monotonically increasing)
                       until it reaches a value that makes the loop stop without any occurrences of overflows. This
                       is done by a comparison used as loop termination condition that considers the amount of the 
                       increment that is applied within each single loop.

FETA_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: Ssa_Utils.c
 **********************************************************************************************************************/
