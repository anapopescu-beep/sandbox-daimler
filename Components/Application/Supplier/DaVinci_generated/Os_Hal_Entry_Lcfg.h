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
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Entry_Lcfg.h
 *   Generation Time: 2023-07-10 14:36:13
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_ENTRY_LCFG_H
# define OS_HAL_ENTRY_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"
# include "Os_Hal_Compiler.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_INTVEC_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXCVEC_CORE0_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE0_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE0_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_EXCVEC_CORE0_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_INTVEC_CORE0_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE0_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE0_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

# define OS_STOP_SEC_INTVEC_CORE0_CODE
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_ENTRY_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.h
 *********************************************************************************************************************/
