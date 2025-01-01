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
 *              File: Os_Cfg.h
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

#ifndef OS_CFG_H
# define OS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define OS_CFG_MAJOR_VERSION                    (2u)

/*! Configuration minor version identification. */
# define OS_CFG_MINOR_VERSION                    (65u)

/*! Defines which platform is used. */
# define OS_CFG_PLATFORM_ARM     (STD_ON)

/*! Defines which derivative group is configured. */
# define OS_CFG_DERIVATIVEGROUP_GENERIC_CORTEXM_MP     (STD_ON)

/*! Defines which derivative is configured. */
# define OS_CFG_DERIVATIVE_TC322L     (STD_ON)

/*! Defines which compiler is configured. */
# define OS_CFG_COMPILER_TASKING     (STD_ON)

/*! Defines whether access macros to get context related information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_PARAMETERACCESS              (STD_OFF)

/*! Defines whether access macros to get service ID information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_GETSERVICEID                 (STD_OFF)

/*! Defines whether the pre-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_PRETASKHOOK                      (STD_OFF)

/*! Defines whether the post-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_POSTTASKHOOK                     (STD_OFF)

/*! Defines whether the OS shall call the panic hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PANICHOOK                        (STD_ON)

/*! Defines whether the system startup hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOK_SYSTEM               (STD_ON)

/*! Defines whether the system shutdown hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOK_SYSTEM              (STD_ON)

/*! Defines whether the system error hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOK_SYSTEM                 (STD_ON)

/*! Defines whether the system protection hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK_SYSTEM            (STD_OFF)

/*! Defines whether backward compatibility defines are needed (STD_ON) or not (STD_OFF). */
# define OS_CFG_PERIPHERAL_COMPATIBILITY         (STD_OFF)

/*! Defines whether interrupt only use case is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_INTERRUPT_ONLY                   (STD_OFF)

/* OS application modes */
# define DONOTCARE     ((AppModeType)0)
# define OS_APPMODE_NONE     ((AppModeType)0)
# define OSDEFAULTAPPMODE     ((AppModeType)1)
# define OS_APPMODE_ANY     ((AppModeType)255)

/*! Defines whether EVENT is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_EVENT                            (STD_ON)

/* Event masks */
# define Rte_Ev_Cyclic2_vHsmMainFunctionTask_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Run1_Crypto_30_LibCv_Crypto_30_LibCv_MainFunction     ((EventMaskType)2uLL)
# define Rte_Ev_Run1_Csm_Csm_MainFunction     ((EventMaskType)4uLL)
# define Rte_Ev_Run1_KeyM_KeyM_MainFunction     ((EventMaskType)8uLL)
# define Rte_Ev_Run1_NvM_NvM_MainFunction     ((EventMaskType)16uLL)
# define Rte_Ev_RunS1_Csm_Csm_MainFunction     ((EventMaskType)32uLL)
# define Rte_Ev_RunS1_KeyM_KeyM_MainFunction     ((EventMaskType)64uLL)
# define Rte_Ev_RunS1_NvM_NvM_MainFunction     ((EventMaskType)128uLL)

/* Software counter timing macros */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Cfg.h
 *********************************************************************************************************************/

