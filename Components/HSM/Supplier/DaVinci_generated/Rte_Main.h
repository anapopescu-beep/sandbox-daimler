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
 *             File:  Rte_Main.h
 *           Config:  vHsmConfig.dpa
 *      ECU-Project:  vHsmConfig
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200336
 *
 *      Description:  Lifecycle Header File
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_MAIN_H
# define RTE_MAIN_H

# include "Rte.h"

# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* BSW Scheduler Life-Cycle API */
FUNC(void, RTE_CODE) SchM_Init(void);
FUNC(void, RTE_CODE) SchM_Deinit(void);

/* RTE Life-Cycle API */
FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void);

/* Extended Life-Cycle API */
FUNC(void, RTE_CODE) Rte_InitMemory(void);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RTE_MAIN_H */
