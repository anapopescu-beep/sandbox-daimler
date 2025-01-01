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
 *             File:  SchM_SecOC.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Header of BSW Scheduler for BSW Module <SecOC>
 *********************************************************************************************************************/
#ifndef SCHM_SECOC_H
# define SCHM_SECOC_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_SecOC_Type.h"

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */

# define SECOC_START_SEC_CODE
# include "SecOC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, SECOC_CODE) SecOC_MainFunctionRx(void); /* PRQA S 3451, 3449 */ /* MD_Rte_3451, MD_Rte_3449 */
FUNC(void, SECOC_CODE) SecOC_MainFunctionTx(void); /* PRQA S 3451, 3449 */ /* MD_Rte_3451, MD_Rte_3449 */

# define SECOC_STOP_SEC_CODE
# include "SecOC_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_RXSTATE() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_RXSTATE() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Enter_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE() SuspendAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */

# define SchM_Exit_SecOC_SECOC_EXCLUSIVE_AREA_TXSTATE() ResumeAllInterrupts()  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */


# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_SECOC_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
