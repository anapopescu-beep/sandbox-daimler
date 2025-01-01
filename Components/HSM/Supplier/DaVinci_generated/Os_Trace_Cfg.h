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
 *              File: Os_Trace_Cfg.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TRACE_CFG_H
# define OS_TRACE_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether ORTI is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ORTI                             (STD_OFF)

/*! Defines whether ORTI tracing is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ORTI_ADDITIONAL                  (STD_OFF)

/*! Defines whether Vector timing hooks are active (STD_ON) or not (STD_OFF). */
# define OS_CFG_OSTIMINGHOOKS                    (STD_OFF)

/*! Defines whether ARTI tracing is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ARTI                             (STD_OFF)

/*! Defines whether ARTI hooks are active (STD_ON) or not (STD_OFF). */
# define OS_CFG_ARTI_HOOKS_APPLICATION           (STD_OFF)
# define OS_CFG_ARTI_HOOKS_TASK                  (STD_OFF)
# define OS_CFG_ARTI_HOOKS_CAT2ISR               (STD_OFF)
# define OS_CFG_ARTI_HOOKS_SPINLOCK              (STD_OFF)
# define OS_CFG_ARTI_HOOKS_PROTECTIONHOOK        (STD_OFF)
# define OS_CFG_ARTI_HOOKS_SERVICECALLS          (STD_OFF)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  OS_CALL_ARTI_TRACE()
 **********************************************************************************************************************/
/*! \brief This macro needs to be generated as the third parameter of macro ARTI_TRACE (currently 'Os') shall contain
 *         OS instance short name. That parameter can't be set by macro as it will be concatenated with other parameters 
 *         to the function name of the ARTI tracing function.
 */
# define OS_CALL_ARTI_TRACE(_className, osCoreId, _eventName, eventParameter)

#endif /* OS_TRACE_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Trace_Cfg.h
 *********************************************************************************************************************/
