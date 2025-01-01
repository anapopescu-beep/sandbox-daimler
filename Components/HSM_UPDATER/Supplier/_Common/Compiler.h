/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Compiler.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This file provides the AUTOSAR compiler abstraction for the Tasking compiler
 *                   Supported compiler:           Tasking
 *                   Supported compiler version:   2.x / 3.x / 5.x / 6.x
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *      
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Georg Pfluegel                vispl         Vector Informatik
 *  Bilal Parvez                  visbpz        Vector Informatik
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2018-10-12  vispl                 created from a copy of CommonAsr_Tricore/Compiler.h version 2.2.0.
 *  01.00.01  2019-02-15  visbpz                Removed BETA ESCAN00101017.
 *  01.00.02  2019-02-28  visbpz                Removed old defines.
 *********************************************************************************************************************/

#ifndef COMPILER_H
# define COMPILER_H

/* PRQA S 3453 COMPILER_3453_TAG */ /* MD_MSR_19.7 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Compiler_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr_Arm32 CQComponent : Impl_CompAbstract_Tasking */
# define COMMONASR_ARM32_IMPL_COMPABSTRACT_VERSION 0x0100
# define COMMONASR_ARM32_IMPL_COMPABSTRACT_RELEASE_VERSION 0x00

# define COMPILER_VENDOR_ID    30u  /* SREQ00015523 */
# define COMPILER_MODULE_ID    198u /* SREQ00015523 */
 
/* AUTOSAR Software Specification Release Version Information */
/*            AUTOSAR Release 4.0 R3                          */
#   define COMPILER_AR_RELEASE_MAJOR_VERSION       (4u)
#   define COMPILER_AR_RELEASE_MINOR_VERSION       (0u)
#   define COMPILER_AR_RELEASE_REVISION_VERSION    (3u)

/* Component Version Information */
# define COMPILER_SW_MAJOR_VERSION       (1u)
# define COMPILER_SW_MINOR_VERSION       (0u)
# define COMPILER_SW_PATCH_VERSION       (2u) 

# ifndef _TASKING_C_ARM_
#  define _TASKING_C_ARM_
# endif

/* AUTOMATIC used for the declaration of local pointers */
# define AUTOMATIC

/* TYPEDEF shall be used within type definitions, where no memory qualifier can be specified.*/
# define TYPEDEF


/* NULL_PTR define with a void pointer to zero definition*/
# ifndef NULL_PTR
#  define NULL_PTR  ((void *)0)
# endif

/* INLINE  define for abstraction of the keyword inline*/
# define INLINE     inline

/* LOCAL_INLINE define for abstraction of the keyword inline in functions with "static" scope.
   Different compilers may require a different sequence of the keywords "static" and "inline" 
   if this is supported at all. */
# define LOCAL_INLINE    static inline

/* FUNC macro for the declaration and definition of functions, that ensures correct syntax of function declarations
   rettype     return type of the function
   memclass    classification of the function itself*/
# define FUNC(rettype, memclass) rettype memclass

/* FUNC_P2CONST macro for declaration and definition of functions returning a pointer to a constant, that ensures 
     correct syntax of function declarations.
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance 
   memclass    classification of the function itself*/
# define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype ptrclass * memclass

/* FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable, that ensures
     correct syntax of function declarations
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance 
   memclass    classification of the function itself*/
# define FUNC_P2VAR(rettype, ptrclass, memclass) rettype ptrclass * memclass

/* P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables
   ptrtype     type of the referenced variable memclass
   memclass    classification of the pointer’s variable itself
   ptrclass    defines the classification of the pointer’s distance
 */
# define P2VAR(ptrtype, memclass, ptrclass) memclass ptrtype ptrclass *

/* P2CONST macro for the declaration and definition of pointers in RAM pointing to constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define P2CONST(ptrtype, memclass, ptrclass) const memclass ptrtype ptrclass *

/* CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define CONSTP2VAR(ptrtype, memclass, ptrclass) memclass ptrtype ptrclass * const

/* CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define CONSTP2CONST(ptrtype, memclass, ptrclass) const memclass ptrtype ptrclass * const

/* P2FUNC macro for the type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   fctname     function name respectivly name of the defined type
 */
# define P2FUNC(rettype, ptrclass, fctname) rettype (ptrclass * fctname)

/* CONSTP2FUNC macro for the type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer distance
   fctname     function name respectively name of the defined type
 */
# define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (ptrclass * const fctname) /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* CONST macro for the declaration and definition of constants
   type        type of the constant
   memclass    classification of the constant itself
 */
# define CONST(type, memclass) const type memclass

/* VAR macro for the declaration and definition of variables
   vartype        type of the variable
   memclass    classification of the variable itself
 */
# define VAR(vartype, memclass) vartype memclass


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/* PRQA L:COMPILER_3453_TAG */

/****************************************************************************/
/*  MISRA deviations                                                        */
/****************************************************************************/
/* Justification for module-specific MISRA deviations:

MD_Compiler_19.10:
  Reason: Macro used in structures, which depend on used compiler and which do not allow brackets e.g. declaration of functions and variables.
  Risk: None atomic parameter lead to compile errors.
  Prevention: Used parameter is always atomic.

*/


#endif  /* COMPILER_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler.h
 *********************************************************************************************************************/
