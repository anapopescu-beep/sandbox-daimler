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
 *             File:  SchM_Crypto_30_vHsm_Hal.h
 *           Config:  vHsmConfig.dpa
 *      ECU-Project:  vHsmConfig
 *
 *        Generator:  MICROSAR RTE Generator Version 4.21.0
 *                    RTE Core Version 1.21.0
 *          License:  Unknown license
 *
 *      Description:  Header of BSW Scheduler for BSW Module <Crypto_30_vHsm_Hal>
 *********************************************************************************************************************/
#ifndef SCHM_CRYPTO_30_VHSM_HAL_H
# define SCHM_CRYPTO_30_VHSM_HAL_H

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */

void vHsm_Hal_MainFunction(void); /* PRQA S 3451, 3449 */ /* MD_Rte_3451, MD_Rte_3449 */


# define SchM_Enter_Crypto_30_vHsm_Hal_VHSM_HAL_EXCLUSIVE_AREA_0() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
# define SchM_Exit_Crypto_30_vHsm_Hal_VHSM_HAL_EXCLUSIVE_AREA_0() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
# define SchM_Enter_Crypto_30_vHsm_Hal_VHSM_HAL_EXCLUSIVE_AREA_1() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
# define SchM_Exit_Crypto_30_vHsm_Hal_VHSM_HAL_EXCLUSIVE_AREA_1() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
# define SchM_Enter_Crypto_30_vHsm_Hal_VHSM_HAL_EXCLUSIVE_AREA_2() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
# define SchM_Exit_Crypto_30_vHsm_Hal_VHSM_HAL_EXCLUSIVE_AREA_2() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
# define SchM_Enter_Crypto_30_vHsm_Hal_VHSM_HAL_EXCLUSIVE_AREA_3() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
# define SchM_Exit_Crypto_30_vHsm_Hal_VHSM_HAL_EXCLUSIVE_AREA_3() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

#endif /* SCHM_CRYPTO_30_VHSM_HAL_H */

