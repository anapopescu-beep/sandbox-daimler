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
 *            Module: vLinkGen
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_Cfg.h
 *   Generation Time: 2022-09-22 10:43:14
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#ifndef VLINKGEN_CFG_H
# define VLINKGEN_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "vBrsCfg.h"

/**********************************************************************************************************************
 *  USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define VLINKGEN_CFG_MAJOR_VERSION                   2u
/*! Configuration minor version identification. */
# define VLINKGEN_CFG_MINOR_VERSION                   5u

/* Number of entries for different initialization tables */
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS      1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS        1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS 1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS      2u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS       1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS        7u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS        1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS      1u 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS 1u 
# define VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS            1u 
# define VLINKGEN_CFG_NUM_INIT_ONE_GROUPS             8u 
# define VLINKGEN_CFG_NUM_INIT_TWO_GROUPS             1u 
# define VLINKGEN_CFG_NUM_INIT_THREE_GROUPS           1u 
# define VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS      1u 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#endif /* VLINKGEN_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_Cfg.h
 *********************************************************************************************************************/
