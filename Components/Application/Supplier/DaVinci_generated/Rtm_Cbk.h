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
 *            Module: Rtm
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Rtm_Cbk.h
 *   Generation Time: 2023-07-10 14:36:05
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined(RTM_CBK_H)
#define RTM_CBK_H

#include "Platform_Types.h"
#include "Rtm_Types.h"

typedef uint32 Rtm_TimestampType;

typedef struct
{
  uint32        prevActive;        /* Previously active measurement */
  uint32        intermediateTime;  /* Time of interruption */
  uint32        threadContext;     /* The context in which the MP is running. */
} Rtm_MeasurementPointInfoType;

typedef struct
{
  const uint32  targetRTFactor;     /* Factor to calculate Target Runtime percentile of this MP */
  const boolean interruptsDisabled; /* Defines if interrupts are disabled during MP execution. */
  const uint8   measurementType;
  const uint8   mpType;
  const uint16  taskRespTimeIdx;
  const uint16  coreId;             /* Assigned Core ID */
} Rtm_MeasurementPointConfigType;


#define RTM_START_SEC_CODE
#include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

Rtm_TimestampType Rtm_GetTimeMeasurement(void); 



#define RTM_STOP_SEC_CODE
#include "Rtm_MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif /* RTM_CBK_H */


