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
 *            Module: Os
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Counter_Cfg.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_COUNTER_CFG_H 
# define OS_COUNTER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether any counter uses SW increment (STD_ON) or not (STD_OFF) */
# define OS_CFG_COUNTER_SW_USED                  (STD_OFF)

/*! Defines whether any counter uses PIT (STD_ON) or not (STD_OFF) */
# define OS_CFG_COUNTER_PIT_USED                 (STD_ON)

/*! Defines whether any counter uses High Resolution (STD_ON) or not (STD_OFF) */
# define OS_CFG_COUNTER_HRT_USED                 (STD_OFF)

/*! Defines whether any counter uses FRT as PIT (STD_ON) or not (STD_OFF) */
# define OS_CFG_COUNTER_PFRT_USED                (STD_OFF)

/*! Number of counter jobs: SystemTimer */
# define OS_CFG_NUM_COUNTER_SYSTEMTIMER_JOBS     (1u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_COUNTER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Counter_Cfg.h
 *********************************************************************************************************************/
