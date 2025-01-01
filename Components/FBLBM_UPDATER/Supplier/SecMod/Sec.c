/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 **********************************************************************************************************************/

#define SEC_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module configuration settings */
#include "Sec_Inc.h"

/* Global definitions for security module */
#include "Sec_Types.h"

#include "Sec.h"

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

#if ( SYSSERVICE_SECMODHIS_VERSION != 0x0313u ) || \
    ( SYSSERVICE_SECMODHIS_RELEASE_VERSION != 0x00u )
# error "Error in SecM.c: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_KEY_TIMEOUT ) && ( SEC_KEY_TIMEOUT != 0x00u )
/** Timer for validity of seed value */
V_MEMRAM0 V_MEMRAM1 SecM_ShortType V_MEMRAM2 secTimer;
#endif

#define SECM_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void SecM_TimerTask( void );

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  SecM_TimerTask
 **********************************************************************************************************************/
/*! \brief         Handle all timer related task
 *  \details       Called with period of SEC_CALL_CYCLE ms
 **********************************************************************************************************************/
static void SecM_TimerTask( void )
{
   /* Count down key timer */
   SecM_DecrKeyTimer(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  SecM_InitPowerOn
 **********************************************************************************************************************/
/*! \brief         Initialize security module
 *  \param[in]     initParam Initialization parameters (unused - reserved for future use)
 *  \return        SECM_OK if initialization successful
 *                 SECM_NOT_OK otherwise
 **********************************************************************************************************************/
SecM_StatusType SecM_InitPowerOn( SecM_InitType initParam )
{
   SecM_StatusType result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 1 */ /* MD_MSR_DummyStmt */
   (void)initParam;
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   result = SECM_OK;

   SecM_InitPowerOnCRC();
   SecM_InitPowerOnVerification();

   return result;
}

/***********************************************************************************************************************
 *  SecM_Init
 **********************************************************************************************************************/
/*! \brief         Initialization of external modules for use in SecM.
 **********************************************************************************************************************/
void SecM_Init( void )
{
   SecM_InitCert();
}

/***********************************************************************************************************************
 *  SecM_Task
 **********************************************************************************************************************/
/*! \brief         Cyclic task of security module
 *  \details       Called with period of SEC_CALL_CYCLE ms
 **********************************************************************************************************************/
void SecM_Task( void )
{
   /* PRQA S 2987 1 */ /* MD_Sec_2987 */
   SecM_TimerTask();
}

/***********************************************************************************************************************
 *  SecM_GetInteger
 **********************************************************************************************************************/
/*! \brief      Convert given big-endian byte array to integer value
 *  \param[in]  count Number of relevant bytes
 *  \param[in]  buffer Pointer to input buffer
 *  \return     Integer value
 **********************************************************************************************************************/
SecM_WordType SecM_GetInteger( SecM_ByteFastType count, SecM_ConstRamDataType buffer )
{
   SecM_WordType output;
   SecM_ByteFastType index;

   output = 0u;
   index = 0u;

   /* Loop relevant bytes */
   while (index < count)
   {
      /* Most significant byte first */
      output <<= 8u;
      /* Add current byte */
      output |= (SecM_WordType)buffer[index];

      index++;
   }

   return output;
}

/***********************************************************************************************************************
 *  SecM_SetInteger
 **********************************************************************************************************************/
/*! \brief      Convert given integer value to big-endian byte array
 *  \param[in]  count Number of relevant bytes
 *  \param[in]  input Input value
 *  \param[out] buffer Pointer to output buffer
 **********************************************************************************************************************/
void SecM_SetInteger( SecM_ByteFastType count, SecM_WordType input, SecM_RamDataType buffer )
{
   SecM_ByteFastType index;
   SecM_WordType localInput;

   /* Loop relevant bytes */
   index = count;
   localInput = input;
   while (index > 0u)
   {
      index--;
      /* Store most significant byte first */
      buffer[index] = (SecM_ByteType)(localInput & 0xFFu);
      /* Shift in next byte */
      localInput >>= 8u;
   }
}

/***********************************************************************************************************************
 *  SecM_CopyBuffer
 **********************************************************************************************************************/
/*! \brief      Copy from two byte arrays
 *  \param[in]  input Pointer to input buffer
 *  \param[out] output Pointer to output buffer
 *  \param[in]  count Number of relevant bytes
 **********************************************************************************************************************/
void SecM_CopyBuffer( SecM_ConstRamDataType input, SecM_RamDataType output, SecM_ShortType count )
{
   SecM_ShortType index;

   /* Byte-wise copy */
   for (index = 0u; index < count; index++)
   {
      output[index] = input[index];
   }
}

/**********************************************************************************************************************
 *  SecM_InitBuffer
**********************************************************************************************************************/
/*! \brief      Initialize a buffer
 *  \param[in]  buff Pointer to the buffer
 *  \param[in]  size Size to be assigned to the buffer
**********************************************************************************************************************/
void SecM_InitBuffer(SecM_RamBufferProcessingPtrType buff, SecM_ShortType size)
{
   buff->pos = 0u;
   buff->size = size;
}

/**********************************************************************************************************************
 *  SecM_AccumulateBuffer
**********************************************************************************************************************/
/*! \brief         Handles a buffer in accumulation mode, accumulating bytes until the buffer is full.
 *  \param[in]     buff Pointer to the buffer
 *  \param[in,out] src Pointer to source data
 *  \param[in]     size Number of bytes in input. When the function is called the number of available input bytes
 *                   must be passed. When the function ends, the amount of copied bytes in the buffer is returned.
**********************************************************************************************************************/
SecM_BufferRetType SecM_AccumulateBufferStore(SecM_RamBufferProcessingPtrType buff, SecM_ConstRamDataType src,
   SecM_RamShortType size)
{
   SecM_BufferRetType result = SEC_BUFF_OK;

   if (buff->size == buff->pos)
   {
      /* Buffer is already full. No bytes can be copied */
      result = SEC_BUFF_FULL;
      *size = 0u;
   }
   else if (*size > (buff->size - buff->pos))
   {
      /* Data to be copied is larger, copy only possible bytes */
      *size = (buff->size - buff->pos);
      SecM_CopyBuffer(src, &buff->buffer[buff->pos], *size);
      buff->pos += *size;
      result = SEC_BUFF_FULL;
   }
   else
   {
      /* Data to be copied is less than available space */
      if (*size == (buff->size - buff->pos))
      {
         result = SEC_BUFF_FULL;
      }
      SecM_CopyBuffer(src, &buff->buffer[buff->pos], *size);
      buff->pos += *size;
   }

   return result;
}

/**********************************************************************************************************************
 *  SecM_FifoBufferStore
**********************************************************************************************************************/
/*! \brief         Handles a buffer in FIFO mode. Extra data which overflow the FIFO is passed as output.
 *  \param[in]     buff Pointer to the buffer
 *  \param[in]     src Pointer to source data
 *  \param[in,out] srcSize Number of bytes in input. When the function is called the number of available input bytes
 *                   must be passed. When the function ends, the amount of copied bytes in the buffer is returned.
 *  \param[out]    flushBuff Pointer to output data. Data which overflows the buffer during an inserition operation
 *                   is placed here.
 *  \param[out]    flushSize Size of flushed data
**********************************************************************************************************************/
SecM_BufferRetType SecM_FifoBufferStore(SecM_RamBufferProcessingPtrType buff, SecM_ConstRamDataType src,
   SecM_RamShortType srcSize, SecM_RamDataType flushBuff, SecM_RamShortType flushSize)
{
   SecM_BufferRetType result = SEC_BUFF_OK;

   if ((buff->size - buff->pos) >= *srcSize)
   {
      /* There is enough space for the data without flushing operations */
      SecM_CopyBuffer(src, &buff->buffer[buff->pos], *srcSize);
      buff->pos += *srcSize;
      *flushSize = 0u;
   }
   else
   {
      /* The data to be stored is larger than the free remaining space */
      SecM_ShortType localTransferSize;
      SecM_ShortType srcIdx;

      /* Calculate how many bytes need to be copied */
      localTransferSize = (*srcSize < buff->size) ? *srcSize : buff->size;
      srcIdx = (*srcSize <= buff->size) ? 0u : (*srcSize - buff->size);
      /* Flush existing data */
      if (localTransferSize < buff->size)
      {
         SecM_CopyBuffer(buff->buffer, flushBuff, (localTransferSize - (buff->size - buff->pos)));
         *flushSize = (localTransferSize - (buff->size - buff->pos));
         SecM_CopyBuffer(&buff->buffer[(localTransferSize - (buff->size - buff->pos))], buff->buffer, (buff->size - (localTransferSize - (buff->size - buff->pos))));
         buff->pos -= (localTransferSize - (buff->size - buff->pos));
      }
      else
      {
         SecM_CopyBuffer(buff->buffer, flushBuff, buff->size);
         *flushSize = buff->pos;
         buff->pos = 0u;
      }
      /* Copy new data */
      SecM_CopyBuffer(&src[srcIdx], &buff->buffer[buff->pos], localTransferSize);
      buff->pos += localTransferSize;
      *srcSize = localTransferSize;
   }

   return result;
}

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_Sec_2987:
      Reason:     The function has side effects only on some configurations
      Risk:       No risk.
      Prevention: No prevention.

*/

/***********************************************************************************************************************
 *  END OF FILE: SEC.C
 **********************************************************************************************************************/
