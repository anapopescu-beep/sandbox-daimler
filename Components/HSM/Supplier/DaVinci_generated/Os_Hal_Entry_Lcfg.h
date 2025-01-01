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
 *              File: Os_Hal_Entry_Lcfg.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
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
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/
#define OS_START_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

OS_HAL_CONST_ATTRIBUTE_DECLARATION
(
  Os_Hal_VectorTableEntryType,
  OS_CONST,
  OS_HAL_SECTION_ATTRIBUTE("OsCore0_VectorTable_Section"),
  OsCfg_Hal_Core_OsCore0_VectorTable[513]
);

#define OS_STOP_SEC_INTVEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_START_SEC_INTVEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_STOP_SEC_INTVEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */





/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_INTVEC_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

#define OS_STOP_SEC_INTVEC_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_EXCVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_EXCVEC_CORE0_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_EXCVEC_CORE0_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

#define OS_STOP_SEC_EXCVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern uint8 _OS_INTVEC_CORE0_CODE_START[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */
extern uint8 _OS_INTVEC_CORE0_CODE_END[];                       /* PRQA S 0289, 1002, 3449, 3451, 3684 */ /* MD_Os_Dir1.1_0289_LinkerSymbol, MD_Os_Rule1.2_1002, MD_Os_Rule8.5_3449_LinkerSymbol, MD_Os_Rule8.5_3451_LinkerSymbol, MD_Os_Rule8.11_3684_LinkerSymbol */

#define OS_STOP_SEC_INTVEC_CORE0_CODE
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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
