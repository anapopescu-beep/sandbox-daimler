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
 *          Customer: Mercedes Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: AURIX TC399
 *    License Scope : The usage is restricted to CBD2000612_D04
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_Cfg.h
 *   Generation Time: 2022-04-13 13:52:50
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2000612_D04
 *      Tool Version: DaVinci Configurator (beta) 5.24.30 SP1
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

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
# define VLINKGEN_CFG_MINOR_VERSION                   3u

/* Number of entries for different initialization tables */
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS      1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS        1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS 1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS      2uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS       1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS        7uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS        1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS      1uL 
# define VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS 1uL 
# define VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS            1uL 
# define VLINKGEN_CFG_NUM_INIT_ONE_GROUPS             7uL 
# define VLINKGEN_CFG_NUM_INIT_TWO_GROUPS             1uL 
# define VLINKGEN_CFG_NUM_INIT_THREE_GROUPS           1uL 
# define VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS      1uL 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#endif /* VLINKGEN_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_Cfg.h
 *********************************************************************************************************************/
