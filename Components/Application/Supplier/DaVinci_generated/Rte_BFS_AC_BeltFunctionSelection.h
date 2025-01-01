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
 *             File:  Rte_BFS_AC_BeltFunctionSelection.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <BFS_AC_BeltFunctionSelection>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_BFS_AC_BELTFUNCTIONSELECTION_H
# define RTE_BFS_AC_BELTFUNCTIONSELECTION_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_BFS_AC_BeltFunctionSelection_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFS_psrSelectedCycle_u8CycleNumber;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8PreActivationFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8PreConditionsFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_u8TriggeringSource;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_b8InterruptFlag;
extern VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_b8TriggerFlag;
extern VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_u8TriggeringSource;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_prrAlgo01_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo01_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo01_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo01_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo01_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo02_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo02_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo02_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo02_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo02_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo03_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo03_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo03_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo03_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo03_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo04_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo04_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo04_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo04_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo04_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo05_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo05_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo05_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo05_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo05_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo06_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo06_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo06_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo06_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo06_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo07_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo07_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo07_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo07_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo07_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo08_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo08_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo08_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo08_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo08_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo09_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo09_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo09_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo09_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo09_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo10_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo10_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo10_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo10_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo10_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo11_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo11_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo11_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo11_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo11_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo12_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo12_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo12_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo12_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo12_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo13_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo13_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo13_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo13_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo13_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo14_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo14_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo14_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo14_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo14_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo15_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo15_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo15_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo15_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo15_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo16_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo16_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo16_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo16_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo16_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo17_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo17_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo17_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo17_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo17_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo18_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo18_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo18_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo18_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo18_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo19_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo19_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo19_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo19_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo19_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo20_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo20_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo20_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo20_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo20_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo21_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo21_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo21_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo21_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo21_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo22_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo22_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo22_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo22_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo22_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo23_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo23_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo23_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo23_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo23_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo24_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo24_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo24_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo24_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo24_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo25_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo25_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo25_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo25_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo25_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo26_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo26_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo26_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo26_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo26_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo27_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo27_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo27_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo27_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo27_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo28_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo28_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo28_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo28_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo28_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo29_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo29_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo29_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo29_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo29_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo30_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo31_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo32_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo33_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo34_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo34_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo34_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo34_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo34_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo35_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo35_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo35_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo35_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo35_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo36_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo36_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo36_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo36_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo36_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo37_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo37_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo37_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo37_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo37_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo38_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo38_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo38_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo38_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo38_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_psrSelectedCycle_u8CycleNumber (255U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_tsOsTask_ALV_BeltFunctionAlgo, RTE_VAR_NOINIT) Rte_OsTask_ALV_BeltFunctionAlgo; /* PRQA S 0759 */ /* MD_MSR_Union */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_IRead_<r>_<p>_<d>
 * Rte_IStatus_<r>_<p>_<d>
 * Rte_IFeedback_<r>_<p>_<d>
 * Rte_IWrite_<r>_<p>_<d>
 * Rte_IWriteRef_<r>_<p>_<d>
 * Rte_IInvalidate_<r>_<p>_<d>
 *********************************************************************************************************************/


#  define Rte_IRead_BFS_runBeltFunctionSelection_prrExecutedCycle_u8CycleNumber() \
  (Rte_OsTask_ALV_BeltFunctionAlgo.Rte_RB.Rte_BFS_AC_BeltFunctionSelection_BFS_runBeltFunctionSelection.Rte_prrExecutedCycle_u8CycleNumber.value)


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_prrAlgo01_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo01_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo01_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE1_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo01_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo01_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo01_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE1_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo01_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo01_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo01_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE1_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo02_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo02_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo02_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE2_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo02_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo02_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo02_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE2_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo02_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo02_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo02_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE2_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo03_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo03_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo03_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE3_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo03_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo03_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo03_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE3_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo03_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo03_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo03_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE3_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo04_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo04_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo04_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE4_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo04_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo04_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo04_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE4_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo04_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo04_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo04_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE4_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo05_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo05_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo05_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE5_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo05_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo05_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo05_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE5_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo05_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo05_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo05_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE5_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo06_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo06_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo06_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE6_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo06_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo06_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo06_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE6_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo06_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo06_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo06_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE6_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo07_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo07_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo07_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE7_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo07_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo07_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo07_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE7_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo07_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo07_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo07_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE7_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo08_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo08_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo08_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE8_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo08_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo08_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo08_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE8_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo08_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo08_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo08_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE8_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo09_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo09_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo09_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE9_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo09_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo09_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo09_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE9_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo09_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo09_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo09_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE9_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo10_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo10_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo10_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE10_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo10_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo10_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo10_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE10_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo10_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo10_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo10_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE10_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo11_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo11_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo11_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE11_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo11_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo11_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo11_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE11_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo11_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo11_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo11_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE11_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo12_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo12_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo12_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE12_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo12_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo12_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo12_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE12_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo12_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo12_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo12_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE12_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo13_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo13_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo13_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE13_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo13_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo13_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo13_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE13_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo13_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo13_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo13_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE13_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo14_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo14_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo14_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE14_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo14_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo14_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo14_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE14_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo14_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo14_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo14_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE14_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo15_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE15_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo15_Flags_b8PreActivationFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_b8PreActivationFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_b8PreActivationFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE15_b8PreActivationFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo15_Flags_b8PreConditionsFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_b8PreConditionsFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_b8PreConditionsFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE15_b8PreConditionsFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo15_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE15_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo15_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo15_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE15_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo16_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo16_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo16_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE16_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo16_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo16_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo16_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE16_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo16_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo16_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo16_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE16_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo17_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo17_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo17_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE17_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo17_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo17_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo17_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE17_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo17_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo17_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo17_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE17_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo18_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo18_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo18_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE18_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo18_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo18_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo18_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE18_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo18_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo18_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo18_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_PRE18_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo19_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo19_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo19_Flags_b8InterruptFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA10_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo19_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo19_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo19_Flags_b8TriggerFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA10_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo19_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo19_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo19_Flags_u8TriggeringSource(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA10_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo20_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo20_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo20_Flags_b8InterruptFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA11_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo20_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo20_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo20_Flags_b8TriggerFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA11_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo20_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo20_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo20_Flags_u8TriggeringSource(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA11_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo21_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo21_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo21_Flags_b8InterruptFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA20_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo21_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo21_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo21_Flags_b8TriggerFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA20_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo21_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo21_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo21_Flags_u8TriggeringSource(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA20_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo22_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo22_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo22_Flags_b8InterruptFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA21_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo22_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo22_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo22_Flags_b8TriggerFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA21_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo22_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo22_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo22_Flags_u8TriggeringSource(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA21_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo23_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo23_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo23_Flags_b8InterruptFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA30_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo23_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo23_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo23_Flags_b8TriggerFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA30_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo23_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo23_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo23_Flags_u8TriggeringSource(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA30_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo24_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo24_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo24_Flags_b8InterruptFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA31_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo24_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo24_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo24_Flags_b8TriggerFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA31_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo24_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo24_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo24_Flags_u8TriggeringSource(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA31_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo25_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo25_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo25_Flags_b8InterruptFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA40_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo25_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo25_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo25_Flags_b8TriggerFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA40_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo25_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo25_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo25_Flags_u8TriggeringSource(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA40_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo26_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo26_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo26_Flags_b8InterruptFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA41_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo26_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo26_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo26_Flags_b8TriggerFlag(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA41_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo26_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo26_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo26_Flags_u8TriggeringSource(data) (*(data) = Rte_HWA_psrAlgo_Flags_HWA41_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo27_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo27_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo27_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR1_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo27_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo27_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo27_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR1_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo27_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo27_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo27_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR1_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo28_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo28_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo28_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR2_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo28_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo28_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo28_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR2_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo28_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo28_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo28_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR2_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo29_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo29_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo29_Flags_b8InterruptFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR3_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo29_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo29_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo29_Flags_b8TriggerFlag(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR3_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo29_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo29_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo29_Flags_u8TriggeringSource(data) (*(data) = Rte_PRE_psrAlgo_Flags_BSR3_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo30_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo30_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo30_Flags_b8InterruptFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo30_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo30_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo30_Flags_b8TriggerFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_SMO_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo30_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo30_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo30_Flags_u8TriggeringSource(data) (*(data) = Rte_SFR_psrAlgo_Flags_SMO_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo31_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo31_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo31_Flags_b8InterruptFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo31_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo31_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo31_Flags_b8TriggerFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_HRD_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo31_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo31_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo31_Flags_u8TriggeringSource(data) (*(data) = Rte_SFR_psrAlgo_Flags_HRD_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo32_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo32_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo32_Flags_b8InterruptFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo32_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo32_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo32_Flags_b8TriggerFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_BCK_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo32_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo32_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo32_Flags_u8TriggeringSource(data) (*(data) = Rte_SFR_psrAlgo_Flags_BCK_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo33_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo33_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo33_Flags_b8InterruptFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo33_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo33_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo33_Flags_b8TriggerFlag(data) (*(data) = Rte_SFR_psrAlgo_Flags_PAT_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo33_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo33_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo33_Flags_u8TriggeringSource(data) (*(data) = Rte_SFR_psrAlgo_Flags_PAT_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo34_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo34_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo34_Flags_b8InterruptFlag(data) (*(data) = Rte_PRO_psrAlgo_Flags_PRO1_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo34_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo34_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo34_Flags_b8TriggerFlag(data) (*(data) = Rte_PRO_psrAlgo_Flags_PRO1_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo34_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo34_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo34_Flags_u8TriggeringSource(data) (*(data) = Rte_PRO_psrAlgo_Flags_PRO1_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo35_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo35_Flags_b8InterruptFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo35_Flags_b8InterruptFlag(data) (*(data) = Rte_PRO_psrAlgo_Flags_PRO2_b8InterruptFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo35_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo35_Flags_b8TriggerFlag
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo35_Flags_b8TriggerFlag(data) (*(data) = Rte_PRO_psrAlgo_Flags_PRO2_b8TriggerFlag, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo35_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo35_Flags_u8TriggeringSource
#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo35_Flags_u8TriggeringSource(data) (*(data) = Rte_PRO_psrAlgo_Flags_PRO2_u8TriggeringSource, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrAlgo36_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo36_Flags_b8InterruptFlag

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo36_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo36_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo36_Flags_b8TriggerFlag

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo36_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo36_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo36_Flags_u8TriggeringSource

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo36_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo37_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo37_Flags_b8InterruptFlag

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo37_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo37_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo37_Flags_b8TriggerFlag

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo37_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo37_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo37_Flags_u8TriggeringSource

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo37_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo38_Flags_b8InterruptFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo38_Flags_b8InterruptFlag

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo38_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo38_Flags_b8TriggerFlag Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo38_Flags_b8TriggerFlag

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo38_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo38_Flags_u8TriggeringSource Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo38_Flags_u8TriggeringSource

#  define Rte_Read_BFS_AC_BeltFunctionSelection_prrAlgo38_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_psrSelectedCycle_u8CycleNumber Rte_Write_BFS_AC_BeltFunctionSelection_psrSelectedCycle_u8CycleNumber
#  define Rte_Write_BFS_AC_BeltFunctionSelection_psrSelectedCycle_u8CycleNumber(data) (Rte_BFS_psrSelectedCycle_u8CycleNumber = (data), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define BFS_AC_BeltFunctionSelection_START_SEC_CODE
# include "BFS_AC_BeltFunctionSelection_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_BFS_runBeltFunctionSelection BFS_runBeltFunctionSelection
# endif

FUNC(void, BFS_AC_BeltFunctionSelection_CODE) BFS_runBeltFunctionSelection(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define BFS_AC_BeltFunctionSelection_STOP_SEC_CODE
# include "BFS_AC_BeltFunctionSelection_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_BFS_AC_BELTFUNCTIONSELECTION_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
