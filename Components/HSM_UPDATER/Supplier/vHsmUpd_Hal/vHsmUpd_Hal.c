/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsmUpd_Hal.c
 *        \brief  vHsmUpd_Hal source file
 *
 *      \details  see vHsmUpd_Hal.h
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

#define VHSMUPD_HAL_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsmUpd_Hal.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Check the version of vHsmUpd header file */
#if (  (VHSMUPD_HAL_SW_MAJOR_VERSION != (1u)) \
    || (VHSMUPD_HAL_SW_MINOR_VERSION != (0u)) \
    || (VHSMUPD_HAL_SW_PATCH_VERSION != (1u)) )
# error "Vendor specific version numbers of vHsmUpd_Hal.c and vHsmUpd_Hal.h are inconsistent"
#endif


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if !defined (VHSMUPD_HAL_LOCAL) /* COV_VHSMUPD_HAL_COMPATIBILITY */
# define VHSMUPD_HAL_LOCAL static
#endif

#if !defined (VHSMUPD_HAL_LOCAL_INLINE) /* COV_VHSMUPD_HAL_COMPATIBILITY */
# define VHSMUPD_HAL_LOCAL_INLINE LOCAL_INLINE
#endif

typedef enum
{
  VHSMUPD_HAL_PENDING,
  VHSMUPD_HAL_FAIL,
  VHSMUPD_HAL_OK
} vHsmUpd_Hal_PFlashResult;

/**********************************************************************************************************************
 *  HARDWARE SOFTWARE INTERFACE (HSI)
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

/**********************************************************************************************************************
 *  DMU registers
 *********************************************************************************************************************/
#define VHSMUPD_HAL_START_SEC_CONST_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Base address of SRI slave interface (DMU) - Register Address Space */
VHSMUPD_HAL_LOCAL CONST(uint32, VHSMUPD_HAL_CONST) vHsmUpd_Sri_Base = 0xF8040000u; /* PRQA S 3218 */ /* MD_vHsmUpd_Hal_HSI */

VHSMUPD_HAL_LOCAL CONST(uint32, VHSMUPD_HAL_CONST) vHsmUpd_Hal_PFlashErrOff  = 0x34u; /*!< Error Register Offset */ /* PRQA S 3218 */ /* MD_vHsmUpd_Hal_HSI */
VHSMUPD_HAL_LOCAL CONST(uint32, VHSMUPD_HAL_CONST) vHsmUpd_Hal_PflashOperOff = 0x18u; /*!< Operation Status Offset */ /* PRQA S 3218 */ /* MD_vHsmUpd_Hal_HSI */
VHSMUPD_HAL_LOCAL CONST(uint32, VHSMUPD_HAL_CONST) vHsmUpd_Hal_PFlashStatOff = 0x10u; /*!< PFlash Status Offset */ /* PRQA S 3218 */ /* MD_vHsmUpd_Hal_HSI */

#define VHSMUPD_HAL_STOP_SEC_CONST_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HF_STATUS - Flash status register bit masks */
#define VHSMUPD_HAL_D0BUSY              0x00000001u            /*!< DF0 busy flag */
#define VHSMUPD_HAL_P0BUSY              0x00000004u            /*!< PF0 busy flag */
#define VHSMUPD_HAL_P1BUSY              0x00000008u            /*!< PF1 busy flag */
#define VHSMUPD_HAL_P2BUSY              0x00000010u            /*!< PF2 busy flag */
#define VHSMUPD_HAL_P3BUSY              0x00000020u            /*!< PF3 busy flag */
#define VHSMUPD_HAL_P4BUSY              0x00000040u            /*!< PF4 busy flag */
#define VHSMUPD_HAL_P5BUSY              0x00000080u            /*!< PF5 busy flag */

/*! HF_OPERATION - Flash operation register bit masks */
#define VHSMUPD_HAL_OPPROG              0x00000001u            /*!< Programming state bit */
#define VHSMUPD_HAL_OPERASE             0x00000002u            /*!< Erase state bit */

/*! HF_ERRSR - Error status register bit masks */
#define VHSMUPD_HAL_OPER_ERR            0x00000001u            /*!< Flash operation error */
#define VHSMUPD_HAL_SEQ_ERR             0x00000002u            /*!< Command sequence error */
#define VHSMUPD_HAL_PROT_ERR            0x00000004u            /*!< Protection error */
#define VHSMUPD_HAL_PVER                0x00000008u            /*!< Program verify error */
#define VHSMUPD_HAL_EVER                0x00000010u            /*!< Erase verify error */

/*! Flash status register - combined busy flags */
#define VHSMUPD_HAL_FLASHBUSY    ( VHSMUPD_HAL_D0BUSY | VHSMUPD_HAL_P0BUSY | VHSMUPD_HAL_P1BUSY | VHSMUPD_HAL_P2BUSY | VHSMUPD_HAL_P3BUSY | VHSMUPD_HAL_P4BUSY | VHSMUPD_HAL_P5BUSY )
/*! Flash status register - combined program/erase error flags */
#define VHSMUPD_HAL_ERROR    ( VHSMUPD_HAL_OPER_ERR | VHSMUPD_HAL_SEQ_ERR | VHSMUPD_HAL_PROT_ERR  | VHSMUPD_HAL_PVER | VHSMUPD_HAL_EVER )

/**********************************************************************************************************************
 *  HSM BRIDGE registers
 *********************************************************************************************************************/
#define VHSMUPD_HAL_START_SEC_CONST_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VHSMUPD_HAL_LOCAL CONST(uint32, VHSMUPD_HAL_CONST) vHsmUpd_Hal_HSMBRIDGE = 0xF0040000uL;  /*!< Base address of HSM Bridge */ /* PRQA S 3218 */ /* MD_vHsmUpd_Hal_HSI */
VHSMUPD_HAL_LOCAL CONST(uint32, VHSMUPD_HAL_CONST) vHsmUpd_Hal_SAHBASE = 0x000000C0uL;    /*!< Single Access to Host access Offset */ /* PRQA S 3218 */ /* MD_vHsmUpd_Hal_HSI */
VHSMUPD_HAL_LOCAL CONST(uint32, VHSMUPD_HAL_CONST) vHsmUpd_Hal_SAHMEM = 0x00010000uL;     /*!< Memory Windows for Host access Offset */ /* PRQA S 3218 */ /* MD_vHsmUpd_Hal_HSI */

#define VHSMUPD_HAL_STOP_SEC_CONST_32
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VHSMUPD_HAL_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS: compiler abstraction
 *********************************************************************************************************************/
#ifndef VHSMUPD_HAL_DSYNC /* COV_VHSMUPD_HAL_COMPILER */
# if defined _TASKING_C_TRICORE_ /* COV_VHSMUPD_HAL_COMPILER */
#  define VHSMUPD_HAL_DSYNC __asm("dsb")
# else
#  error "Compiler abstraction missing for VHSMUPD_HAL_DSYNC."
# endif
#endif


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vHsmUpd_WritePflashCommand
 *********************************************************************************************************************/
/*! \brief       Writes to the PFlash command interpreter through the HSM Bridge.
 *  \details     -
 *  \param[in]   address interpreted as command sequence.
 *  \param[in]   data of the command sequence.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSMUPD_HAL_LOCAL_INLINE FUNC(void, VHSMUPD_HAL_CODE) vHsmUpd_WritePflashCommand(uint32 address, uint32 data);

/**********************************************************************************************************************
 *  vHsmUpd_ReadPflashStatus
 *********************************************************************************************************************/
/*! \brief       Reads the current PFlash status.
 *  \details     -
 *  \param[in]   address (offset) of the PFlash status register to read.
 *  \return      uint32 the content of the specified register within DMU.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSMUPD_HAL_LOCAL_INLINE FUNC(uint32, VHSMUPD_HAL_CODE) vHsmUpd_ReadPflashStatus(uint32 address);

/**********************************************************************************************************************
 *  vHsmUpd_Hal_ProcessPFlashOp
 *********************************************************************************************************************/
/*! \brief       Processes the current PFlash command sequence synchronous.
 *  \details     -
 *  \return      The result of the latest PFlash Operation. In this case always a BlankCheck.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSMUPD_HAL_LOCAL FUNC(vHsmUpd_Hal_PFlashResult, VHSMUPD_HAL_CODE) vHsmUpd_Hal_ProcessPFlashOp(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vHsmUpd_WritePflashCommand
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSMUPD_HAL_LOCAL_INLINE FUNC(void, VHSMUPD_HAL_CODE) vHsmUpd_WritePflashCommand(uint32 address, uint32 data)
{
  /* #10 Prepare Host access through HSM Bridge - access window enabled */
  *((volatile uint32*)(vHsmUpd_Hal_HSMBRIDGE + vHsmUpd_Hal_SAHBASE)) = (address & 0xFFFF0000u); /* PRQA S 0303 */ /* MD_vHsmUpd_Hal_RegisterAccess */

  /* #20 Write specific address in 16K base address */
  *((volatile uint32*) ((address & 0x0000FFFFu) | (vHsmUpd_Hal_HSMBRIDGE + vHsmUpd_Hal_SAHMEM))) = data; /* PRQA S 0303 */ /* MD_vHsmUpd_Hal_RegisterAccess */

  /* #30 Wait for DSYNC */
  VHSMUPD_HAL_DSYNC; /* PRQA S 1006 */ /* MD_vHsmUpd_Hal_DSB */
}

/**********************************************************************************************************************
 *  vHsmUpd_ReadPflashStatus
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSMUPD_HAL_LOCAL_INLINE FUNC(uint32, VHSMUPD_HAL_CODE) vHsmUpd_ReadPflashStatus(uint32 address)
{
  /* #10 Get the content of the given offset register of the DMU */
  return *((volatile uint32*)(vHsmUpd_Sri_Base + address)); /* PRQA S 0303 */ /* MD_vHsmUpd_Hal_RegisterAccess */
}

/**********************************************************************************************************************
 *  vHsmUpd_BlankCheck
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
 */
VHSMUPD_HAL_LOCAL FUNC(vHsmUpd_Hal_PFlashResult, VHSMUPD_HAL_CODE) vHsmUpd_Hal_ProcessPFlashOp(void)
{
  vHsmUpd_Hal_PFlashResult retVal = VHSMUPD_HAL_PENDING;

  do
  {
    /* #10 Fail if sequence or protection error. */
    if((vHsmUpd_ReadPflashStatus(vHsmUpd_Hal_PFlashErrOff) & (VHSMUPD_HAL_SEQ_ERR | VHSMUPD_HAL_PROT_ERR )) != 0x00u)
    {
      retVal = VHSMUPD_HAL_FAIL;
    }
    /* #20 Check if program/(verify) erase command was accepted. */
    else if(((vHsmUpd_ReadPflashStatus(vHsmUpd_Hal_PflashOperOff) & (VHSMUPD_HAL_OPPROG | VHSMUPD_HAL_OPERASE)) != 0x00u))
    {
      /* #30 Check if busy bits are reset by hardware. */
      if((vHsmUpd_ReadPflashStatus(vHsmUpd_Hal_PFlashStatOff) & VHSMUPD_HAL_FLASHBUSY) == 0x00u)
      {
        /* #40 If no error is indicated by hardware command has been successfully executed. */
        if((vHsmUpd_ReadPflashStatus(vHsmUpd_Hal_PFlashErrOff) & VHSMUPD_HAL_ERROR) == 0x00u)
        {
          retVal = VHSMUPD_HAL_OK;
        }
        /* #50 Fail otherwise. */
        else
        {
          retVal = VHSMUPD_HAL_FAIL;
        }
      }
      /* #60 Detect hardware failures causing hardware to stay BUSY by checking for operation error.  */
      else if((vHsmUpd_ReadPflashStatus(vHsmUpd_Hal_PFlashErrOff) & VHSMUPD_HAL_OPER_ERR) != 0x00u)
      {
        retVal = VHSMUPD_HAL_FAIL;
      }
      else
      {
        /* No error, but hardware is still busy. */
      }
    }
    else
    {
      /* Command has not been accepted, yet. */
    }
  } while ( retVal == VHSMUPD_HAL_PENDING );

  /* #70 Finalize job unsuccessful in case flash is not erased or any other error is indicated by hardware */
  if((vHsmUpd_ReadPflashStatus(vHsmUpd_Hal_PFlashErrOff) & VHSMUPD_HAL_ERROR) != 0x00u)
  {
    retVal = VHSMUPD_HAL_FAIL;
  }
  /* #80 Otherwise set job result to OK */
  else
  {
    retVal = VHSMUPD_HAL_OK;
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
*  vHsmUpd_Hal_IsBlank()
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, VHSMUPD_HAL_CODE) vHsmUpd_Hal_IsBlank(uint32 address)
{
  /* #10 Reset Status */
  vHsmUpd_WritePflashCommand(0xAF005554u, 0x000000FAu);

  /* #20 Blank Check */
  vHsmUpd_WritePflashCommand(0xAF00AA50u, address);
  vHsmUpd_WritePflashCommand(0xAF00AA58u, 0u);
  vHsmUpd_WritePflashCommand(0xAF00AAA8u, 0x80u);
  vHsmUpd_WritePflashCommand(0xAF00AAA8u, 0x56u);

  /* #30 Get Result of BlankCheck Operation */
  return ((vHsmUpd_Hal_ProcessPFlashOp() == VHSMUPD_HAL_OK) ? TRUE : FALSE);
}

#define VHSMUPD_HAL_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:

   MD_vHsmUpd_Hal_RegisterAccess: rule 11.4
    Reason:     vHsmUpd_Hal directly accesses memory mapped registers. This involves a cast between a pointer to a volatile object and an integral type.
    Risk:       Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
    Prevention: No prevention.

  MD_vHsmUpd_Hal_HSI: rule 8.9
    Reason:     The specified HSI could be used more local (not on file level). HSI documentation rules mandatory.
    Risk:       Specified register will be used where not allowed, e.g. in other functions.
    Prevention: Code review and tests verify that the register are used correctly.

  MD_vHsmUpd_Hal_DSB: rule 1.2
    Reason:     The vHsmUpd must use the compiler specific assembler instruction to synchronize the instruction execution with data written.
    Risk:       No Risk.
    Prevention: No prevention.
*/

/* START_COVERAGE_JUSTIFICATION

Variant coverage:

\ID COV_VHSMUPD_HAL_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VHSMUPD_HAL_COMPILER
 \ACCEPT TX
 \REASON vHsmUpd_Hal has to use the dsync function. Its definition depends on the compiler.
         vHsmUpd_Hal knows the tasking compiler.

END_COVERAGE_JUSTIFICATION
*/

/**********************************************************************************************************************
 *  END OF FILE: vHsmUpd_Hal.c
 *********************************************************************************************************************/
