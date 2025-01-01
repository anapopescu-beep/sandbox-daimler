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
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
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
FUNC(void, RTE_CODE) SchM_Init(P2CONST(SchM_ConfigType, AUTOMATIC, RTE_CONST) ConfigPtr);
FUNC(void, RTE_CODE) SchM_Start(void);
FUNC(void, RTE_CODE) SchM_StartTiming(void);
FUNC(void, RTE_CODE) SchM_Deinit(void);

/* RTE Life-Cycle API */
FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void);
FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void);

/* Extended Life-Cycle API */
FUNC(void, RTE_CODE) Rte_InitMemory(void);


# ifdef RTE_CORE
/* RTE internal IOC replacements */
FUNC(Std_ReturnType, RTE_CODE) Rte_IocSend_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(CONST(uint8, RTE_CONST) data0);
FUNC(Std_ReturnType, RTE_CODE) Rte_IocReceive_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0);
FUNC(Std_ReturnType, RTE_CODE) Rte_IocPeek_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0);
FUNC(Std_ReturnType, RTE_CODE) Rte_IocSend_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(CONST(uint8, RTE_CONST) data0);
FUNC(Std_ReturnType, RTE_CODE) Rte_IocReceive_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0);
FUNC(Std_ReturnType, RTE_CODE) Rte_IocPeek_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0);
/* RTE mode management prototypes */
FUNC(Rte_EventMaskType, RTE_CODE) Rte_GetModeExitEventMask_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode);
FUNC(Rte_EventMaskType, RTE_CODE) Rte_GetModeEntryEventMask_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode);
FUNC(Rte_EventMaskType, RTE_CODE) Rte_GetModeEntryEventMask_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType mode);
# endif

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RTE_MAIN_H */
