/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup  Os_Hal_Derivative
 * \{
 *
 * \file
 * \brief  This file contains derivative specific information.
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 *********************************************************************************************************************/

#ifndef OS_HAL_DERIVATIVE_TC49X_CSRMINT_H
# define OS_HAL_DERIVATIVE_TC49X_CSRMINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/** TC49x_CSRM **/

/* STM module */
# define OS_HAL_TIMER_STM                            STD_OFF
# define OS_HAL_TIMER_CORESTM                        STD_ON

# define OS_HAL_TIMER_STM6_BASE                      (0xF8980000uL)
# define OS_HAL_INT_SRC_STM6_CH0_OFFSET              (0x1A8uL)
# define OS_HAL_INT_SRC_STM6_CH1_OFFSET              (0x1ACuL)


/* GPT module */
# define OS_HAL_TIMER_GPT                            STD_OFF


/* TriCore core module */
# define OS_HAL_CORE_18                              STD_ON

/* Interrupt router (IR) module */
# define OS_HAL_INTERRUPT_AURIXTC4XX_IR              STD_ON
# define OS_HAL_INTERRUPT_IR_BASE                    (0xF0030000uL)

/*! Defines the cyber security bitmask for the service request control register. */
# define OS_HAL_SRC_CS_MASK                          (0x800uL)



#endif /* OS_HAL_DERIVATIVE_TC49X_CSRMINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Derivative_TC49x_CSRMInt.h
 *********************************************************************************************************************/
