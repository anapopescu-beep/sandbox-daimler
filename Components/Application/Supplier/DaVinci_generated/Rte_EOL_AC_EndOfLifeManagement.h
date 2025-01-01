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
 *             File:  Rte_EOL_AC_EndOfLifeManagement.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <EOL_AC_EndOfLifeManagement>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_EOL_AC_ENDOFLIFEMANAGEMENT_H
# define RTE_EOL_AC_ENDOFLIFEMANAGEMENT_H

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

# include "Rte_EOL_AC_EndOfLifeManagement_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8TriggerRequest;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;
extern VAR(u8StepNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedStep_u8StepNumber;
extern VAR(c04_Presf_Lvl_V2, RTE_VAR_NOINIT) Rte_CIL_psrPreSafeLvl_u8PreSafeLvl;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ObsolescenceDataBlockNumber_BlockNumber (0U)
#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_prrPreSafeLvl_u8PreSafeLvl (0U)
# endif


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_AC_EndOfLifeManagement_ObsolescenceDataBlockNumber_BlockNumber(UInt8 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_AC_EndOfLifeManagement_pseExecutionCounterBlockStatus_b8NVMBlockStatus(b8BooleanType data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_prrCustomerSpecific_b8IsTrigOffEventAllowed Rte_Read_EOL_AC_EndOfLifeManagement_prrCustomerSpecific_b8IsTrigOffEventAllowed
#  define Rte_Read_EOL_AC_EndOfLifeManagement_prrCustomerSpecific_b8IsTrigOffEventAllowed(data) (*(data) = Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCustomerSpecific_u8TriggerRequest Rte_Read_EOL_AC_EndOfLifeManagement_prrCustomerSpecific_u8TriggerRequest
#  define Rte_Read_EOL_AC_EndOfLifeManagement_prrCustomerSpecific_u8TriggerRequest(data) (*(data) = Rte_CIL_psrCustomerSpecific_u8TriggerRequest, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExecutedCycle_u8CycleNumber Rte_Read_EOL_AC_EndOfLifeManagement_prrExecutedCycle_u8CycleNumber
#  define Rte_Read_EOL_AC_EndOfLifeManagement_prrExecutedCycle_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExecutedStep_u8StepNumber Rte_Read_EOL_AC_EndOfLifeManagement_prrExecutedStep_u8StepNumber
#  define Rte_Read_EOL_AC_EndOfLifeManagement_prrExecutedStep_u8StepNumber(data) (*(data) = Rte_BFE_psrExecutedStep_u8StepNumber, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrPreSafeLvl_u8PreSafeLvl Rte_Read_EOL_AC_EndOfLifeManagement_prrPreSafeLvl_u8PreSafeLvl
#  define Rte_Read_EOL_AC_EndOfLifeManagement_prrPreSafeLvl_u8PreSafeLvl(data) (*(data) = Rte_CIL_psrPreSafeLvl_u8PreSafeLvl, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ObsolescenceDataBlockNumber_BlockNumber Rte_Write_EOL_AC_EndOfLifeManagement_ObsolescenceDataBlockNumber_BlockNumber
#  define Rte_Write_pseExecutionCounterBlockStatus_b8NVMBlockStatus Rte_Write_EOL_AC_EndOfLifeManagement_pseExecutionCounterBlockStatus_b8NVMBlockStatus


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclNvmServicesExecutionCounters_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)39, arg1))

/**********************************************************************************************************************
 * Rte_Pim (Per-Instance Memory)
 *********************************************************************************************************************/

#  ifndef RTE_MICROSAR_PIM_EXPORT
#   define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_PerInstanceMemory;

#   define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#   include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  endif

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_Pim_PerInstanceMemory() \
  (&Rte_EOL_PerInstanceMemory)
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define EOL_AC_EndOfLifeManagement_START_SEC_CODE
# include "EOL_AC_EndOfLifeManagement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_EOL_Autotest_CheckProductEndOfLifeComfort EOL_Autotest_CheckProductEndOfLifeComfort
#  define RTE_RUNNABLE_EOL_Autotest_CheckProductEndOfLifeHighForce EOL_Autotest_CheckProductEndOfLifeHighForce
#  define RTE_RUNNABLE_EOL_Autotest_CheckProductEndOfLifeLowForce EOL_Autotest_CheckProductEndOfLifeLowForce
#  define RTE_RUNNABLE_EOL_Autotest_CheckProductEndOfLifeMaxForce EOL_Autotest_CheckProductEndOfLifeMaxForce
#  define RTE_RUNNABLE_EOL_Get_Obsolescence_Data EOL_Get_Obsolescence_Data
#  define RTE_RUNNABLE_EOL_Init EOL_Init
#  define RTE_RUNNABLE_EOL_Write_Obsolescence_Data EOL_Write_Obsolescence_Data
#  define RTE_RUNNABLE_EOL_runMainFunction EOL_runMainFunction
#  define RTE_RUNNABLE_EOL_runSetDatasetIndex EOL_runSetDatasetIndex
# endif

FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Autotest_CheckProductEndOfLifeComfort(P2VAR(u8TestResultType, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Autotest_CheckProductEndOfLifeHighForce(P2VAR(u8TestResultType, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Autotest_CheckProductEndOfLifeLowForce(P2VAR(u8TestResultType, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Autotest_CheckProductEndOfLifeMaxForce(P2VAR(u8TestResultType, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Get_Obsolescence_Data(P2CONST(Impl_Obsolescense_Data, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_DATA) pObsData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Write_Obsolescence_Data(P2VAR(Impl_Obsolescense_Data, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pObsData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_runMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_runSetDatasetIndex(UInt8 u8DatasetIndex); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define EOL_AC_EndOfLifeManagement_STOP_SEC_CODE
# include "EOL_AC_EndOfLifeManagement_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_NvMService_AC3_SRBS_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_EOL_AC_ENDOFLIFEMANAGEMENT_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

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
