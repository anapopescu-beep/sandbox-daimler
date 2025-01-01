/*
 * Std_Types.h
 *
 *  Created on: Aug 13, 2019
 *      Author: reymond.zhang
 */

#ifndef RTE_MOCKS_INCLUDE_STD_TYPES_H_
#define RTE_MOCKS_INCLUDE_STD_TYPES_H_

#include "Platform_Types.h"
#include "Compiler.h"

/* !LINKSTO Base.ASR403.STD007,1 */
#if (defined STD_HIGH)
#error STD_HIGH already defined
#endif

/** \brief physical state 5V or 3.3V  */
#define STD_HIGH 1U

#if (defined STD_LOW)
#error STD_LOW already defined
#endif

/** \brief physical state 0V */
#define STD_LOW 0U

/* !LINKSTO Base.ASR403.STD013,1 */
#if (defined STD_ACTIVE)
#error STD_ACTIVE already defined
#endif

/** \brief Autosar logical state 'active' */
#define STD_ACTIVE 1U

#if (defined STD_IDLE)
#error STD_IDLE already defined
#endif

/** \brief Autosar logical state 'idle' */
#define STD_IDLE 0U

/* !LINKSTO Base.ASR403.STD010,1 */
#if (defined STD_ON)
#error STD_ON already defined
#endif

/** \brief Autosar definition for 'on' */
#define STD_ON 1U

#if (defined STD_OFF)
#error STD_OFF already defined
#endif

/** \brief Autosar definition for 'off' */
#define STD_OFF 0U

#if (!defined STATUSTYPEDEFINED)
/** \brief Guard macro for type definition of StatusType */
#define STATUSTYPEDEFINED
/** \brief Definition StatusType (OSEK compliance) */
typedef unsigned char StatusType;
#endif

/** \brief Autosar standard API return type */
/* !LINKSTO Base.ASR403.STD005,1 */
typedef uint8 Std_ReturnType;

/* !LINKSTO Base.ASR403.STD006,1 */
#if (!defined E_OK)
/** \brief Constant for value OK of StatusType */
/* !LINKSTO Base.ASR403.STD011,1 */
#define E_OK 0U
#endif

#if (!defined E_NOT_OK)
/** \brief Constant for value NOT_OK of StatusType */
/* !LINKSTO Base.ASR403.STD011,1 */
#define E_NOT_OK 1U
#endif
 

#endif /* RTE_MOCKS_INCLUDE_STD_TYPES_H_ */
