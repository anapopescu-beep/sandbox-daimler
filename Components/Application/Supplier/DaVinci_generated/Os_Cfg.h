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
 *            Module: Os
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Cfg.h
 *   Generation Time: 2024-02-15 10:45:17
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_CFG_H
# define OS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define OS_CFG_MAJOR_VERSION                    (2u)

/*! Configuration minor version identification. */
# define OS_CFG_MINOR_VERSION                    (71u)

/*! Defines which platform is used. */
# define OS_CFG_PLATFORM_TRICOREAURIX     (STD_ON)

/*! Defines which derivative group is configured. */
# define OS_CFG_DERIVATIVEGROUP_TC32XL     (STD_ON)

/*! Defines which derivative is configured. */
# define OS_CFG_DERIVATIVE_TC322L     (STD_ON)

/*! Defines which compiler is configured. */
# define OS_CFG_COMPILER_TASKING     (STD_ON)

/*! Defines whether access macros to get context related information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_PARAMETERACCESS              (STD_OFF)

/*! Defines whether access macros to get service ID information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_GETSERVICEID                 (STD_OFF)

/*! Defines whether the pre-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_PRETASKHOOK                      (STD_ON)

/*! Defines whether the post-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_POSTTASKHOOK                     (STD_OFF)

/*! Defines whether the OS shall call the panic hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PANICHOOK                        (STD_OFF)

/*! Defines whether the system startup hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOK_SYSTEM               (STD_OFF)

/*! Defines whether the system shutdown hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOK_SYSTEM              (STD_ON)

/*! Defines whether the system error hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOK_SYSTEM                 (STD_ON)

/*! Defines whether the system protection hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK_SYSTEM            (STD_OFF)

/*! Defines whether backward compatibility defines are needed (STD_ON) or not (STD_OFF). */
# define OS_CFG_PERIPHERAL_COMPATIBILITY         (STD_OFF)

/*! Defines whether interrupt only use case is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_INTERRUPT_ONLY                   (STD_OFF)

/* OS application modes */
# define DONOTCARE     ((AppModeType)0)
# define OS_APPMODE_NONE     ((AppModeType)0)
# define OSDEFAULTAPPMODE     ((AppModeType)1)
# define OS_APPMODE_ANY     ((AppModeType)255)

/*! Defines whether EVENT is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_EVENT                            (STD_ON)

/* Event masks */
# define Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_3ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_5ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_5ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_1000ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_100ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_1ms     ((EventMaskType)8uLL)
# define Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_250ms     ((EventMaskType)16uLL)
# define Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_2ms     ((EventMaskType)32uLL)
# define Rte_Ev_Cyclic_BeltFunctionAlgo_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_BeltFunctionAlgo_2ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic_BeltFunctionSelection_10msA     ((EventMaskType)4uLL)
# define Rte_Ev_Cyclic_OsTask_ALV_BeltFunctionAlgo_0_10ms     ((EventMaskType)8uLL)
# define Rte_Ev_Cyclic_OsTask_ALV_BeltFunctionsExec_0_10msA     ((EventMaskType)16uLL)
# define Rte_Ev_OnEntry_ApplTask_Core0_LowPrio_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_EXTENDED_SESSION     ((EventMaskType)64uLL)
# define Rte_Ev_Run_AdcIf_AdcIf_MainFunction     ((EventMaskType)4uLL)
# define Rte_Ev_Run_BFE_BFE_runExecuteStandardSteps     ((EventMaskType)32uLL)
# define Rte_Ev_Run_BFE_BFE_runExecuteStandardStepsA     ((EventMaskType)64uLL)
# define Rte_Ev_Run_BaseFunction_BaseFunction_Main     ((EventMaskType)128uLL)
# define Rte_Ev_Run_Cdd_MBBL_EcuStatHandler_DiagSessionChange_ExitExtendedSession     ((EventMaskType)256uLL)
# define Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution     ((EventMaskType)512uLL)
# define Rte_Ev_Run_DIA_DIA_cyclicProcessingTask     ((EventMaskType)1024uLL)
# define Rte_Ev_Run_DiagFunction_DiagFunction_MainFunction     ((EventMaskType)2048uLL)
# define Rte_Ev_Run_DiagFunction_RoELite_AvailabilityDataHandler     ((EventMaskType)4096uLL)
# define Rte_Ev_Run_DiagFunction_RoELite_ObsolescenceDataHandler     ((EventMaskType)8192uLL)
# define Rte_Ev_Run_DiagFunction_RoELite_SecureEventNotification     ((EventMaskType)16384uLL)
# define Rte_Ev_Run_SBC_SBC_MainFunction     ((EventMaskType)8uLL)
# define Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveDiagnosticAuthentication     ((EventMaskType)1uLL)
# define Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveRealTimeOffset     ((EventMaskType)2uLL)
# define Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveSharedSecret     ((EventMaskType)4uLL)
# define Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCount     ((EventMaskType)8uLL)
# define Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCountTimeout     ((EventMaskType)32768uLL)
# define Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVIN     ((EventMaskType)16uLL)
# define Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVINTimeout     ((EventMaskType)65536uLL)
# define Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive     ((EventMaskType)131072uLL)
# define Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive_Timeout     ((EventMaskType)262144uLL)
# define Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCount     ((EventMaskType)524288uLL)
# define Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCountTimeout     ((EventMaskType)1048576uLL)
# define Rte_Ev_Run_Ssa_KeyM_Ssa_KeyM_Com_VehicleSharedSecretNotification     ((EventMaskType)2097152uLL)
# define Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_Com_ReceiveBroadcastAuthentication     ((EventMaskType)4194304uLL)
# define Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_DiagnosticSessionChangeIndication     ((EventMaskType)8388608uLL)
# define Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_IgnitionStatusChanged     ((EventMaskType)16777216uLL)
# define Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast     ((EventMaskType)33554432uLL)
# define Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_Com_ReceiveRealTimeOffset     ((EventMaskType)67108864uLL)
# define Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_PowernetMgmtStateChanged     ((EventMaskType)134217728uLL)
# define Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_ReceiveChangeTickCountEvent     ((EventMaskType)268435456uLL)

/* Software counter timing macros */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Cfg.h
 *********************************************************************************************************************/

