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
 *             File:  SchM_Adc.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Header of BSW Scheduler for BSW Module <Adc>
 *********************************************************************************************************************/
#ifndef SCHM_ADC_H
# define SCHM_ADC_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Adc_Type.h"

# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) SchM_Enter_Adc_KernelData(void);
FUNC(void, RTE_CODE) SchM_Exit_Adc_KernelData(void);
FUNC(void, RTE_CODE) SchM_Enter_Adc_SrcRegAccess(void);
FUNC(void, RTE_CODE) SchM_Exit_Adc_SrcRegAccess(void);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_ADC_H */
