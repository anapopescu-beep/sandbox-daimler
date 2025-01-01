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
 *             File:  Rte_PwmIf_Type.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application types header file for SW-C <PwmIf>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_PWMIF_TYPE_H
# define RTE_PWMIF_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef PWM_KU8_CH_ID_HB_P
#   define PWM_KU8_CH_ID_HB_P (0U)
#  endif

#  ifndef PWM_KU8_CH_ID_HB_N
#   define PWM_KU8_CH_ID_HB_N (1U)
#  endif

#  ifndef PWM_KU8_CH_ID_BOOST_DRIVER
#   define PWM_KU8_CH_ID_BOOST_DRIVER (2U)
#  endif

#  ifndef PWM_KU8_CH_ID_BOOST_CP
#   define PWM_KU8_CH_ID_BOOST_CP (3U)
#  endif

#  ifndef PWM_KU8_CH_ID_MAX
#   define PWM_KU8_CH_ID_MAX (4U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_PWMIF_TYPE_H */
