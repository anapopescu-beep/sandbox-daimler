/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Cdd_MBBL_ResetExecutor_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <Cdd_MBBL_ResetExecutor>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_MBBL_RESETEXECUTOR_TYPE_H
# define RTE_CDD_MBBL_RESETEXECUTOR_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef RELEASED
#   define RELEASED (0U)
#  endif

#  ifndef REQUESTED
#   define REQUESTED (1U)
#  endif

#  ifndef EcuMConf_EcuMResetMode_ECUM_RESET_IO
#   define EcuMConf_EcuMResetMode_ECUM_RESET_IO (2U)
#  endif

#  ifndef EcuMConf_EcuMResetMode_ECUM_RESET_MCU
#   define EcuMConf_EcuMResetMode_ECUM_RESET_MCU (0U)
#  endif

#  ifndef EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP
#   define EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP (3U)
#  endif

#  ifndef EcuMConf_EcuMResetMode_ECUM_RESET_WDG
#   define EcuMConf_EcuMResetMode_ECUM_RESET_WDG (1U)
#  endif

#  ifndef ECUM_STATE_SLEEP
#   define ECUM_STATE_SLEEP (80U)
#  endif

#  ifndef ECUM_STATE_OFF
#   define ECUM_STATE_OFF (128U)
#  endif

#  ifndef ECUM_STATE_RESET
#   define ECUM_STATE_RESET (144U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_MBBL_RESETEXECUTOR_TYPE_H */
