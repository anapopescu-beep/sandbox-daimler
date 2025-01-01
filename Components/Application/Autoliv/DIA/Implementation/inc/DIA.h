#ifndef _DIA_H_
#define _DIA_H_ 1

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
*******************************************************************************

Overview of the interfaces:
   <Describes details of this header file>

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.11.13 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/

#include "Std_Types.h"
#include "common.h"
#include "Config.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *		Defined macro from H file.
 */

/* Constants used to check NvmWriteBlock Status */
#define KU8_WRITE_REQ_OK                             0x00U
#define KU8_WRITE_REQ_PENDING                        0x01U
#define KU8_WRITE_REQ_FAILED                         0x02U
#define KU8_WRITE_REQ_NV_INVALIDATED                 0x05U
#define KU8_WRITE_REQ_RESTORED_FROM_ROM              0x08U

#define KU16_BELT_FUNCTIONS_DISABLED_MASK                        ((uint16) 0x0000)
#define KU16_BELT_FUNCTIONS_ENABLED_MASK                         ((uint16) 0xFFFF)
#define KU8_BELT_FUNCTIONS_DISABLED                              ((uint8) 0x00)
#define KU8_BELT_FUNCTIONS_ENABLED                               ((uint8) 0x01)
#define KU8_BELT_FUNCTIONS_MIXED                                 ((uint8) 0x2)
#define KU8_BELT_FUNCTIONS_MASK_INCONSISTENT                     ((uint8) 0x3)

/* Index of all NVM Data Block to erase or check */
#define KU8_NVM_DATA_BLOCK_DTC_INDEX                             ((uint8)0)
#define KU8_NVM_DATA_BLOCK_EXECUTION_COUNTERS_INDEX_0            ((uint8)1)
#define KU8_NVM_DATA_BLOCK_EXECUTION_COUNTERS_INDEX_1            ((uint8)2)
#define KU8_NVM_DATA_BLOCK_SYSTEM_CONTEXT_0                      ((uint8)3)
/* QAC_WARNING S 0779 7*/ /* Macro name similar to KU8_NVM_DATA_BLOCK_SYSTEM_CONTEXT_0. */
/* QAC_WARNING S 0778 6*/ /* Macro name similar to KU8_NVM_DATA_BLOCK_SYSTEM_CONTEXT_0. */
#define KU8_NVM_DATA_BLOCK_SYSTEM_CONTEXT_1                      ((uint8)4)
/* QAC_WARNING S 0779 7*/ /* Macro name similar to KU8_NVM_DATA_BLOCK_SYSTEM_CONTEXT_1. */
/* QAC_WARNING S 0778 6*/ /* Macro name similar to KU8_NVM_DATA_BLOCK_SYSTEM_CONTEXT_1. */
#define KU8_NVM_DATA_BLOCK_SYSTEM_CONTEXT_2                      ((uint8)5)
#define KU8_NVM_DATA_BLOCK_WARM_RESET                            ((uint8)6)
#define KU8_NVM_DATA_BLOCK_ECC_COUNTERS                          ((uint8)7)
#define KU8_NVM_DATA_BLOCK_BLOCK_NUMBER                          ((uint8)8)

/* NVM Data Block status bit field */
#define KU8_NVM_BIT_POSITION_SYSTEM_CONTEXT                      ((uint8)0x01)
#define KU8_NVM_BIT_POSITION_EXECUTION_COUNTERS                  ((uint8)0x02)
#define KU8_NVM_BIT_POSITION_DTC                                 ((uint8)0x04)
#define KU8_NVM_BIT_POSITION_ECC_COUNTERS                        ((uint8)0x08)
#define KU8_NVM_BIT_POSITION_WARM_RESET                          ((uint8)0x10)

/* Maximum number of call by the DCM for service: DIA_runRidF703_AutolivCyclesStart
 * when the service status is pending. When the counter reaches this value, a
 * negative response is send */
/* DCM periodicity = 2 ms => LSB = 2 ms */
#define KU8_START_CYCLE_MAXIMUM_TRY                               ((uint8)7)

/* Size of the system context*/
#define KU8_SYSTEM_CONTEXT_SIZE                                   ((uint8)12)

/* Arguments position in the "31 01 FE 01" request data */
#define KU8_JOB_TYPE_POSITION                                     ((uint8)0)
#define KU8_JOB_PARAM_POSITION                                    ((uint8)1)
#define KU8_JOB_DATA_LENGTH                                       ((uint8)2)

/* Last byte of Routine Control positive response */
#define KU8_RINF_BYTE                                             ((uint8) 0xFF)

/* Warm reset cause */
#define KU8_WARM_RESET_CAUSE_RESPONSE_LENGTH                      ((uint8)1)
#define KU8_RESET_CAUSE_POR                                       ((uint8)1)
#define KU8_RESET_CAUSE_WAKEUP                                    ((uint8)2)
#define KU8_RESET_CAUSE_LOW_VOLTAGE                               ((uint8)3)
#define KU8_RESET_CAUSE_WD_TEST                                   ((uint8)4)

#define KU8_RESET_CAUSE_ERROR_STRATEGY                            ((uint8)0x10)
#define KU8_RESET_CAUSE_OS_EXCEPTION                              ((uint8)0x10)
#define KU8_RESET_CAUSE_RESET_BY_DIAG                             ((uint8)0x11)

#define KU8_RESET_CAUSE_INTERNAL_WATCHDOG                         ((uint8)0x12)

#define KU8_WARM_RESET_CAUSE_WD                                   ((uint8)0x80)
#define KU8_WARM_RESET_CAUSE_CRYSTAL                              ((uint8)0x81)
#define KU8_WARM_RESET_CAUSE_PLL                                  ((uint8)0x82)
#define KU8_RESET_CAUSE_RAM_ECC                                   ((uint8)0x83)
#define KU8_RESET_CAUSE_PFLASH_ECC                                ((uint8)0x84)
#define KU8_RESET_CAUSE_INVALID_INT                               ((uint8)0x85)
#define KU8_RESET_CAUSE_UNIDENTIFIED_ECC                          ((uint8)0x86)
#define KU8_RESET_CAUSE_BTLD                                      ((uint8)0x87)
#define KU8_RESET_CAUSE_STACK_OVERFLOW                            ((uint8)0x88)
#define KU8_RESET_CAUSE_RAM_DATA_CORRUPTED                        ((uint8)0x89)
#define KU8_RESET_CAUSE_E2P_ECC                                   ((uint8)0x8A)
#define KU8_RESET_CAUSE_EXTERNAL_WATCHDOG                         ((uint8)0x90)

#define KU8_WARM_RESET_CAUSE_UNKNOWN                              ((uint8)0xFF)
#define KU16_MAX_ALLOWED_STEPS_LENGTH                             ((uint16)0x140)

#define KU8_AEC_MASK                                              ((uint8)0x01)
#define KU8_NUMBER_OF_AEC_RGS                                     ((uint8)0x21)
#define KU8_DIA_NUMBER_OF_AEC                                     56u

#define KU8_ROUTINE_SUCCESSFULLY_COMPLETED                        0x00u
#define KU8_ROUTINE_IN_PROGRESS                                   0x01u
#define KU8_ROUTINE_STOPPED_WITHOUT_RESULTS                       0x02u
#define KU8_ROUTINE_NOT_SUPPORTED                                 0xFFu

#define KU8_THREE                                                 0x03u
#define KU16_THREE                                                0x0003u
#define KU16_ZERO                                                 0x0000u

#define KU16_PRESAFE_TRIGGER_COUNTER                              0x3C

#define KU8_TRIGGER_PRESAFE_ROUTINE_STARTED                       0x01
#define KU8_TRIGGER_PRESAFE_ROUTINE_STOPED                        0x02

/* Definition of the SW version length */
#define KU8_SW_VERSION_LENGTH                                     ((uint8)12)

/**
 * \brief
 * 		ECU Location left
 */
#define KU8_DIA_ECU_SIDE_FRONT_LEFT                   ((uint8) 0x9C)
/**
 * \brief
 * 		ECU Location right
 */
#define KU8_DIA_ECU_SIDE_FRONT_RIGHT                  ((uint8) 0x99)
/**
 * \brief
 *       NVP ECU Location
 */
#define KU8_DIA_ECU_LOCATION                          (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/*! \union TEMPLATE_FILES_Struct_Define TEMPLATE_FILES.h "inc/TEMPLATE_FILES.h"
 *  \brief This is a Struct description.
 *
 */
typedef enum
{
   TENSIONING_ROUTINE_NOT_RUNNING = 0,
   TENSIONING_ROUTINE_STARTED,
   TENSIONING_ROUTINE_DEBOUNCING,
   TENSIONING_ROUTINE_STOP,
   TENSIONING_ROUTINE_STOPPED
}en_TensioningRoutineStatus;

typedef struct
{
   en_TensioningRoutineStatus routineStatus;
   uint8 timeToRun;
   uint8 requestedCycle;
}st_TensioningCycleStarted;

typedef enum
{
   PROG_PRECOND_VEHICLE_SPEED = 0x05,
   PROG_PRECOND_CONTROL_ACTIVE,
   PROG_PRECOND_LOW_BATTERY_VOLTAGE = 0x0A,
   PROG_PRECOND_CRASH = 0xC0
}en_ProgrammingPreconditions;
/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

extern st_TensioningCycleStarted  DIA_stTensioningCycleStarted;

extern uint8 DIA_u8TriggerPreSafeRequest;

extern uint16 DIA_u16TriggerPreSafeCounter;

extern REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt stBckl_Sw_Fx_Stat;

extern c02_Bckl_Sw_Stat dia_u8BcklSwStatSignal;

extern uint8 DIA_u8ProgrammingPreconditionsList[4];
extern uint8 DIA_u8ActiveProgrammingPreconditions;
extern uint8 dia_u8RequestResult0302;
/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
extern uint8 DIA_runCheckProgrammingPreconditions(void);
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

/*****************************************************************************
Evolution of the component

 created by : T. DEMIREL

 $Log: DIA.h  $
 Revision 1.1.11.13 2024/02/01 13:24:00CET Madalina Serban (madalina.serban) 
 Fixed always in progress issue
 Revision 1.1.11.12 2024/01/05 14:12:43EET Emanuel Jivan (emanuel.jivan) 
 Implemented Check Programming Preconditions, including during programming session request.
 Revision 1.1.11.11 2023/07/24 10:07:10EEST Madalina Serban (madalina.serban) 
 Fixes after review
 Revision 1.1.11.10 2023/03/06 14:50:26EET Madalina Serban (madalina.serban) 
 Fix to return to default value after 3s
 Revision 1.1.11.9 2023/02/01 10:41:21EET Madalina Serban (madalina.serban) 
 Implementation for Presafe display request
 Revision 1.1.11.8 2023/01/10 11:44:52EET Emanuel Jivan (emanuel.jivan) 
 Updated diagnostics with V060 config, modified 0241 and 0200 format and added 22 FD01.
 Revision 1.1.11.7 2022/11/03 12:40:44EET Mirela Obada (mirela.obada) 
 Update for 4.0 diagnosis implementation
 Revision 1.1.11.6 2022/08/09 13:09:45EEST Emanuel Jivan (emanuel.jivan) 
 Implemented RID 0329 and 0330; added 50ms cyclic task.
 Revision 1.1.11.5 2022/07/14 17:19:01EEST Emanuel Jivan (emanuel.jivan) 
 Fixed 22 FE00, and F703 can now do pending.
 Revision 1.1.11.4 2022/07/12 13:55:14EEST Emanuel Jivan (emanuel.jivan) 
 DV UDS update.
 Revision 1.1.11.3 2022/03/25 15:06:52EET Emanuel Jivan (emanuel.jivan) 
 Updated code template, added tracebility in code and fixed tracebility in design.
 Revision 1.1.11.2 2022/01/11 11:50:16EET Andreea Negrea (andreea.negrea) 
 Initial revision
 Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/DIA/Implementation/inc/project.pj
 Revision 1.1.1.8.2.9 2021/08/02 15:26:32EEST Razvan Badiu (razvan.badiu) 
 

*****************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _DIA_H_ */


