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
 *              File: Os_Hal_Lcfg.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_LCFG_H
# define OS_HAL_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! OS-Core identifier */
#define OS_CORE_ID_0 OS_CORE_ID_0

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! OS-Core identifier.
 * \details Logical Core IDs for all cores, which are physically available.
 *          Notation: OS_CORE_ID_<X> = <Y>, where
 *            - X equals the ECUC core ID and
 *            - Y is a continuous core ID number running from 0 to OS_COREID_COUNT-1.
 */
typedef enum
{
  OS_CORE_ID_MASTER = 0,
  OS_CORE_ID_0 = 0, /* 0x00000001 - OsCore0 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COREID_COUNT = 1
} CoreIdType;


/*! Platform specific address type.
 *  \details This data type has the same bit width as a pointer. Therefore a conversion from this type into a
 *  pointer and vice versa is always valid. */
typedef uint32 Os_Hal_AddressType;

/*! Defines the type of the stack array.
 * Typically this type is mapped to the processors word type (unsigned int or Os_Hal_WordType). */
typedef uint32 Os_Hal_StackType;
#define OS_HAL_STACK_FILL_PATTERN (Os_Hal_StackType) 0xAAAAAAAAuL

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Lcfg.h
 *********************************************************************************************************************/
