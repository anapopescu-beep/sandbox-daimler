/*
 * Rte.h
 *
 *  Created on: Aug 13, 2019
 *      Author: reymond.zhang
 */

#ifndef MOCKS_RTE_H_
#define MOCKS_RTE_H_

#include "Std_Types.h"

#define RTE_E_OK 0U

#if (defined FUNC) /* to prevent double definition */
#error FUNC already defined
#endif /* if (defined FUNC) */
#define FUNC(rettype, memclass) rettype

#if (defined P2VAR) /* to prevent double definition */
#error P2VAR already defined
#endif /* if (defined P2VAR) */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

#if (defined P2CONST) /* to prevent double definition */
#error P2CONST already defined
#endif /* if (defined P2CONST) */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *

#if (defined P2FUNC) /* to prevent double definition */
#error P2FUNC already defined
#endif /* if (defined P2FUNC) */
#define P2FUNC(rettype, ptrclass, fctname) rettype (* fctname)

#if (defined CONST) /* to prevent double definition */
#error CONST already defined
#endif /* if (defined CONST) */
#define CONST(consttype, memclass) consttype const

#if (defined VAR) /* to prevent double definition */
#error VAR already defined
#endif /* if (defined VAR) */
#define VAR(vartype, memclass) vartype

#if (defined CONSTP2CONST)
#error CONSTP2CONST already defined
#endif
#define CONSTP2CONST(ptrtype, memclass, ptrclass) ptrtype const * const

/* CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define CONSTP2CONST(ptrtype, memclass, ptrclass) ptrtype const * const /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable, that ensures
     correct syntax of function declarations
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   memclass    classification of the function itself
 */
# define FUNC_P2VAR(rettype, ptrclass, memclass) rettype * /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables
   ptrtype     type of the referenced variable memory class
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
# define P2VAR(ptrtype, memclass, ptrclass) ptrtype * /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* NULL_PTR define with a void pointer to zero definition */
# ifndef NULL_PTR
#  define NULL_PTR ((void *)0)
# endif

#endif /* MOCKS_RTE_H_ */
