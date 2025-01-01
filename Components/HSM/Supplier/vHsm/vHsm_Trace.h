/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_Trace.h
 *        \brief  header file for the trace macros
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_TRACE_H)
# define VHSM_TRACE_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define VHSM_TRACE_IDENTIFIER                                        ("VHSM")

# if ( (VHSM_TRACE_INFO == STD_ON)    \
     || (VHSM_TRACE_WARNING == STD_ON) \
     || (VHSM_TRACE_DEBUG == STD_ON)   \
     || (VHSM_TRACE_ERROR == STD_ON))
#  define VHSM_TRACE_USED
# endif

# define VHSM_TRACETYPE_INFO                                          (0x00u)
# define VHSM_TRACETYPE_DEBUG                                         (0x01u)
# define VHSM_TRACETYPE_WARNING                                       (0x02u)
# define VHSM_TRACETYPE_ERROR                                         (0x03u)
# define VHSM_TRACETYPE_NONE                                          (0x04u)
typedef uint8 vHsm_TraceType;

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

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef VHSM_TRACE_USED
/**********************************************************************************************************************
 *  vHsm_Trace()
 *********************************************************************************************************************/
/*! \brief       Print text to the debug console
 *  \details     Uses the capability of the MULTI debugger to print text to the debugger console using printf from stdio.h
 *  \param[in]   traceType          One of those values: VHSM_TRACETYPE_INFO, VHSM_TRACETYPE_DEBUG,
 *                                  VHSM_TRACETYPE_WARNING, VHSM_TRACETYPE_ERROR, VHSM_TRACETYPE_NONE
 *  \param[in]   format             Format string
 *  \param[in]   ...                Variable argument list containing the arguments for the format string
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
extern FUNC(void, VHSM_CODE) vHsm_Trace(vHsm_TraceType traceType, P2CONST(char, AUTOMATIC, VHSM_APPL_VAR) format, ...);
# else
/* Define vHsm_Trace to nothing from outside in case special compiler flags are incompatible with to provided macro definitions */
#  if !defined(vHsm_Trace) /* COV_VHSM_PLATFORM_SPECIFIC_TRACING */
#   if (defined(WIN32) || defined(__TASKING__)) /* COV_VHSM_PLATFORM_SPECIFIC_TRACING */
#    define vHsm_Trace(...)                                           /* PRQA S 1030 */ /* MD_VHSM_1030_TRACE_VARIADIC_MACRO */
#   elif defined(__ghs__) /* COV_VHSM_PLATFORM_SPECIFIC_TRACING */
#    define vHsm_Trace(args...)                                       /* PRQA S 1030 */ /* MD_VHSM_1030_TRACE_VARIADIC_MACRO */
#   else
#    define vHsm_Trace(ARGS...)                                       /* PRQA S 1030 */ /* MD_VHSM_1030_TRACE_VARIADIC_MACRO */
#   endif
#  endif
# endif

# if (VHSM_TRACE_KEY_STORAGE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Trace_PrintKeyStorage()
 *********************************************************************************************************************/
 /*! \brief      Print the content of the keystorage to the console
 *  \details     -
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Trace_PrintKeyStorage(void);
# endif

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_TRACE_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Trace.h
 *********************************************************************************************************************/
