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
 *            Module: vBRS
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to -
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ..\Include\SchM_Fls_17_Dmu.h
 *   Generation Time: 2020-04-24 07:47:28
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: -
 *      Tool Version: DaVinci Configurator  5.21.24
 *
 *
 *********************************************************************************************************************/

#ifndef SCHM_FLS_17_DMU_H
# define SCHM_FLS_17_DMU_H

# include "Os.h"

void Fls_17_Dmu_MainFunction(void);

# define SchM_Enter_Fls_17_Dmu_Init() SuspendAllInterrupts()
# define SchM_Exit_Fls_17_Dmu_Init() ResumeAllInterrupts()

# define SchM_Enter_Fls_17_Dmu_Erase() SuspendAllInterrupts()
# define SchM_Exit_Fls_17_Dmu_Erase() ResumeAllInterrupts()

# define SchM_Enter_Fls_17_Dmu_Write() SuspendAllInterrupts()
# define SchM_Exit_Fls_17_Dmu_Write() ResumeAllInterrupts()

# define SchM_Enter_Fls_17_Dmu_Main() SuspendAllInterrupts()
# define SchM_Exit_Fls_17_Dmu_Main() ResumeAllInterrupts()

# define SchM_Enter_Fls_17_Dmu_ResumeErase() SuspendAllInterrupts()
# define SchM_Exit_Fls_17_Dmu_ResumeErase() ResumeAllInterrupts()

# define SchM_Enter_Fls_17_Dmu_UserContentCount() SuspendAllInterrupts()
# define SchM_Exit_Fls_17_Dmu_UserContentCount() ResumeAllInterrupts()

#endif /* SCHM_FLS_17_DMU_H */
