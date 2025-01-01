/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Ssa_FvM.c
 *        \brief  Freshness-value Manager of the Standard Security Architecture (Ssa).
 *
 *      \details  The Freshness-value Manager provides services to provide the freshness to the ECU.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Coding_MemoryStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Coding_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_DiagnosticSessionControlType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_InitMonitorReasonType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * RightsM_AuthenticationModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_BswM_ComModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_ChangeTickCountEventIdType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_OnOff_StateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_OperationModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_TickCountSyncStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Port Prototypes:
 * ================
 * CallbackInitMonitorForEvent_DTC_0xD12081
 *   Notifies that this event is cleared, or that the operation (monitoring) cycle restarts.
 *      Connect to corresponding event of Dem.
 *      Configuration Variant(s): Not in VSM.
 *
 * CallbackInitMonitorForEvent_DTC_0xD12087
 *   Notifies that this event is cleared, or that the operation (monitoring) cycle restarts.
 *      Connect to corresponding event of Dem.
 *      Configuration Variant(s): Not in VSM.
 *
 * FvM_Com_ReceiveTickCount
 *   Configuration Variant(s): Not in VSM.
 *
 * FvM_Com_ReceiveTickCountTimeout
 *   Configuration Variant(s): Not in VSM.
 *
 * FvM_Com_SendTickCount
 *   Configuration Variant(s): VSM and GW only.
 *
 * FvM_RealTimeClock
 *   Configuration Variant(s): VSM only.
 *
 * SecOC_FreshnessManagement
 *   Calculates the tick-count as freshness for Rx and Tx PDUs.
 *
 * SendChangeTickCountEvent
 *   Configuration Variant(s): Not in VSM.
 *
 * SendRealTimeOffsetCorrectionRequest
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_BswM_ComIndication
 *   Notifies each time a communication channel enters the state COMM_FULL_COMMUNICATION.
 *      Connect to BswM and create appropriate rule.
 *      Configuration Variant(s): VSM and GW only.
 *
 *
 * Operation Prototypes:
 * =====================
 * GetRxFreshness of Port Interface SecOC_FreshnessManagement
 *   This interface is used by the SecOC to obtain the current freshness value. This operation provides also a part of the Authentic-PDU data if configured.
 *
 * GetTxFreshness of Port Interface SecOC_FreshnessManagement
 *   This operation is used by the SecOC to obtain the freshness that corresponds to the freshnessValueId.
 *
 * GetTxFreshnessTruncData of Port Interface SecOC_FreshnessManagement
 *   This operation is used by the SecOC to obtain the freshness that corresponds to the freshnessValueId. The operation provides the freshness and also the truncated freshness that shall be placed into the Secured-IPDU.
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Coding_MemoryStatus
 *   Notifies the Ssa of memory status changes while storing or restoring the Variant Coding Data to or from non-volatile memory.
 *
 * Coding_Mode
 *   Notifies application about an ongoing, successful or failed coding attempt.
 *
 * RightsM_AuthenticationMode
 *   RIGHTSM_AUTHENTICATED - A Tester was successfully authenticated
 *      RIGHTSM_UNAUTHENTICATED - No tester was authenticated
 *
 * Ssa_MacKeyGeneration_State
 *   Notifies application of whether the generation of the symmetric MAC keys is OFF or ON.
 *
 *
 * Runnable Entities:
 * ==================
 * Ssa_FvM_ComModeChanged
 *   Function is called when it is notified that a communication channel enters the state COMM_FULL_COMMUNICATION.
 *      Configuration Variant(s): VSM and GW only.
 *
 * Ssa_FvM_Com_ReceiveTickCount
 *   Check if the received time is valid.
 *      If it is valid, update the Local Time Base.
 *      
 *      Function is called when the Time Base Signal is received.
 *      Configuration Variant(s): Not in VSM.
 *
 * Ssa_FvM_Com_ReceiveTickCountTimeout
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_FvM_InitMonitorForEvent_DTC_0xD12081
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_FvM_InitMonitorForEvent_DTC_0xD12087
 *   Configuration Variant(s): Not in VSM.
 *
 *********************************************************************************************************************/

#include "Rte_Ssa_FvM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Ssa_Cfg.h"
#include "Ssa_Utils.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_FvM_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
   include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#if !defined (SSA_FVM_LOCAL)                    /* COV_SSA_LOCAL */
# define SSA_FVM_LOCAL                                                static
#endif

#if !defined (SSA_FVM_LOCAL_INLINE)             /* COV_SSA_LOCAL_INLINE */
# define SSA_FVM_LOCAL_INLINE                                         LOCAL_INLINE
#endif

/*!
 * The percentage that the local tick-count of an ECU shall run slower than the nominal update frequency (SSA-IS-1553).
 */
/* If it is a slave ECU each FVM_TICK_COUNT_SKIP tick count is skipped. The resulting percentage
 * that the local tick-count runs slower is the inverse of the following value. */
#define FVM_TICK_COUNT_SKIP                                           (100u/SSA_FVM_PERCENTAGE_LOCAL_TICK_COUNT_SLOWDOWN)

/* The maximum reachable tick count for the local time base (using a 40bit counter) is 2n-2 (i.e. 0xffff ... fffe) (SSA-IS-61). */
#define FVM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL                        (0xFFFFFFFFFEULL)
/* Invalid (non-reachable) time base value (using a 40bit counter). */
#define FVM_LOCAL_TIME_BASE_INVALID_VALUE                             (0xFFFFFFFFFFULL)

/* Waiting time before the startup cycle. */
#define FVM_STARTUP_CYCLE_WAITING_TIME                                (5u)

/* The number of secured time messages sent directly after startup with a cycle time of 100 ms (SSA-IS-358). */
#define FVM_SEC_TIME_MSG_NUM_STARTUP                                  (SSA_FVM_SECURED_TICK_COUNT_STARTUP_CYCLE_DURATION / SSA_FVM_SECURED_TICK_COUNT_STARTUP_CYCLE_TIME)

/* The resulting cycle time of the secured time messages during startup is the multiplication of the following value
 * with the local tick-count's resolution. */
#define FVM_SEC_TIME_MSG_CYCLE_TIME_STARTUP                           (SSA_FVM_SECURED_TICK_COUNT_STARTUP_CYCLE_TIME / 10u)

/* After one second, the VSM shall send the secured tick-count message with a cycle time of 1000 milliseconds as long
 * as the VSM is operational (SSA-IS-359). */
/* The resulting cycle time of the secured time messages after startup is the multiplication of the following value
 * with the local tick-count's resolution. */
#define FVM_SEC_TIME_MSG_CYCLE_TIME_REGULAR                           (SSA_FVM_SECURED_TICK_COUNT_CYCLE_TIME / 10u)

/* Tick-count reception timer (re-)start value for counting down to 0 */
#define FVM_TICKCOUNT_RECEPTION_TIMEOUT                               (SSA_FVM_LOCAL_TICK_COUNT_SYNCHRONIZATION_TIMEOUT / 10u )
/* Tick-count reception COM timer (re-)start value for counting down to 1.
   Timer is started after a COM timeout event (hard-configured to 1000 ms by SWC description) has occurred,
   thus the user configured value is decreased by the COM timeout value. */
#define FVM_TICKCOUNT_RECEPTION_COM_TIMEOUT                           ((SSA_FVM_DEBOUNCE_TIME_DETECTION_MISSING_TICK_COUNT_MESSAGES / 10u) - 100u + 1u)
/* Tick-count authenticated reception timer (re-)start value for counting down to 0 */
#define FVM_TICKCOUNT_AUTHENTICATED_RECEPTION_TIMEOUT                 (SSA_FVM_DEBOUNCE_TIME_DETECTION_UNAUTHETICATED_TICK_COUNT_MESSAGES / 10u)
/* Tick-count acceptance timer (re-)start value for counting down to 0 */
#define FVM_TICKCOUNT_ACCEPTANCE_TIMEOUT                              (SSA_FVM_DEBOUNCE_TIME_DETECTION_REJECTED_TICK_COUNT_MESSAGES / 10u)

/* The maximum amount the local tick-count may be decremented shall be the configured percentage with respect to the
 * nominal update window of the secured tick-count (SSA-IS-1559). */
/* The maximum time span the local time is allowed to be turned back divided by 10ms. */
/* No division by 100, instead multiply time difference compared with this value by 100. */
#define FVM_MAX_SPAN_TURNING_LOCAL_TIME_BACK                          (FVM_SEC_TIME_MSG_CYCLE_TIME_REGULAR * SSA_FVM_PERCENTAGE_TURNING_BACK_LOCAL_TICK_COUNT)

/* Threshold for writing a security log event when time is set to future. */
#define FVM_DEBUG_THRESHOLD_SETTING_TIME_TO_FUTURE                    (6000uLL)

/* Divider for getting the required resolution (RTC resolution is given in microseconds). */
#define FVM_RTC_TO_LOCAL_TICK_COUNT_RESOLUTION_DIV                    ((uint16)(10000uL / SSA_FVM_RTC_RESOLUTION))

/* Check for division by zero caused by invalid configuration. */
#if ( SSA_FVM_RTC_RESOLUTION > 10000uL )  /* COV_MSR_CONFIG  XF */
# error "Combination of RTC resolution and local tick count resolution does not match!"
#endif

#define FVM_COMPENSATION_FOR_LOSS_OF_RTC_VALUE                        (8640000uLL)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define FvM_BitsToBytes(x)                                            (x>>(3u))

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* The following compile time assertions ensure the sizes of data types used within the FvM submodule
 * when calling RTE APIs expecting these data types. 
 * The assertions ensure that the size of these data types is consitent with respective buffer lengths defined in the Ssa.
 * For ASIL-D, the vector code analyzer checks the same conditions within the FvM_Init() function. */
/* PRQA S 3205, 3493 1 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
Ssa_CompileTimeAssert(sizeof(Ssa_Data6ByteType) == 6u, InvalidSizeOf_Ssa_Data6ByteType); /*lint !e506 */

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define Ssa_FvM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/*! Cycle counter used for the periodic sending of the secured time broadcast message. */
SSA_FVM_LOCAL VAR(uint16, Ssa_FvM_VAR_NOINIT) Ssa_FvM_CountDownSecTimeMsgCycle;
/*! Flag indicating the sending the secured time with short cycle time has been requested, */
SSA_FVM_LOCAL VAR(boolean, Ssa_FvM_VAR_NOINIT) Ssa_FvM_RequestForStartupCycle;
#endif /* ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)) */

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
/*! RTC correction value to simulate a re-alignment of the RTC after RTC value has been lost. */
SSA_FVM_LOCAL VAR(uint64, Ssa_FvM_VAR_NOINIT) Ssa_FvM_RtcCorrection;
#else
/*! Main cycle counter. */
SSA_FVM_LOCAL VAR(uint16, Ssa_FvM_VAR_NOINIT) Ssa_FvM_TickCount;
#endif /* (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) */

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_NORMAL) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
SSA_FVM_LOCAL VAR(uint16, Ssa_FvM_VAR_NOINIT) Ssa_FvM_TickCountAcceptanceTimeoutCounter;
SSA_FVM_LOCAL VAR(uint16, Ssa_FvM_VAR_NOINIT) Ssa_FvM_TickCountAuthReceptionTimeoutCounter;
SSA_FVM_LOCAL VAR(uint16, Ssa_FvM_VAR_NOINIT) Ssa_FvM_TickCountReceptionTimeoutCounter;
SSA_FVM_LOCAL VAR(uint16, Ssa_FvM_VAR_NOINIT) Ssa_FvM_TickCountReceptionComTimeoutCounter;
SSA_FVM_LOCAL VAR(uint64, Ssa_FvM_VAR_NOINIT) Ssa_FvM_DiffLastRejectedTickCount;
#endif

#define Ssa_FvM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define Ssa_FvM_START_SEC_CODE
#include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  FvM_SetLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * \brief       Sets the local time base.
 * \details     This functions sets the local time base (tick-count). This value is stored in NVRam block.
 * \param[in]   timeBase  The time base value to be set.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_SetLocalTimeBase(uint64 timeBase);

/**********************************************************************************************************************
 *  FvM_GetLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the local time base.
 * \details     This function provides the current local time base (tick-count).
 * \return      The current time base value.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_FVM_LOCAL_INLINE FUNC(uint64, Ssa_FvM_CODE) FvM_GetLocalTimeBase(void);

/**********************************************************************************************************************
 *  FvM_IncLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * \brief       Increments the local time base.
 * \details     This functions increases the local time base (tick count) by 1.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_IncLocalTimeBase(void);

/**********************************************************************************************************************
 *  FvM_GetLastSecuredTickCount()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the last accepted secured tick-count.
 * \details     This function provides the last accepted secured tick-count.
 * \return      The last accepted secured tick-count.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_FVM_LOCAL_INLINE FUNC(uint64, Ssa_FvM_CODE) FvM_GetLastSecuredTickCount(void);

/**********************************************************************************************************************
 *  FvM_CheckNewLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if a new received secured tick-count can be applied to set as new local time-base.
 * \details     -
 * \param[in]   newTimeBase     The newly received secured tick-count.
 * \param[out]  turningBack     TRUE if received tick-count is before the current local tick-count, else FALSE.
 * \param[out]  timeDifference  The time difference of the local tick-count to the received tick-count.
 * \return      TRUE  if checked tick-count can be set as new local-time base.
 *              FALSE if checked tick-count has to be discarded.
 * \pre         turningBack and timeDifference must be valid pointers
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_FVM_LOCAL_INLINE FUNC(boolean, Ssa_FvM_CODE) FvM_CheckNewLocalTimeBase(uint64 newTimeBase, P2VAR(boolean, AUTOMATIC, AUTOMATIC) turningBack, P2VAR(uint64, AUTOMATIC, AUTOMATIC) timeDifference);

/**********************************************************************************************************************
 *  FvM_CopyVarToArray()
 *********************************************************************************************************************/
/*!
 * \brief       Copies a value given by a variable to a byte array.
 * \details     This function copies the least significant byte from the 64 bit value to the lowest memory position of
 *              the byte array (index 0) and so on.
 * \param[in]   value         Buffer containing the value that shall be copied.
 * \param[out]  buffer        Pointer to the byte array where the variable value shall be stored to. It's size in bits
 *                            must be equal or greater than lengthInBit.
 * \param[in]   lengthInBit   Number of bits to be copied. It must be a multiple of 8 (bits) and not larger than 64 (bits).
 * \return      RTE_E_OK      Request successful.
 *              RTE_E_INVALID Request failed (lengthInBit invalid).
 * \pre         The size of the buffer referenced by the out parameter 'buffer' is at least of the bit size lengthInBit.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec       requires buffer != NULL_PTR;
 *             requires $lengthOf(buffer) >= FvM_BitsToBytes(lengthInBit);                                      \endspec
 */
SSA_FVM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_FvM_CODE) FvM_CopyVarToArray(uint64 value, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) buffer, uint32 lengthInBit);

/**********************************************************************************************************************
 *  FvM_Copy5BytesToArray()
 *********************************************************************************************************************/
/*!
 * \brief       Copies 5 lowest bytes of given 64 bit variable to a 5-byte array.
 * \details     -
 * \param[in]   value   Buffer containing the value that shall be copied.
 * \param[out]  buffer  Pointer to the byte array where the variable value shall be stored to. The buffer must be
 *                      of size 5 bytes.
 * \pre         buffer must be a valid pointer.
 *              The size of the buffer referenced by the out parameter 'buffer' is at least 5 bytes.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec       requires buffer != NULL_PTR;
 *             requires $lengthOf(buffer) >= 5;                                                                \endspec
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_Copy5BytesToArray(uint64 value, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) buffer);

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
 *  FvM_SendTimeMessage()
 *********************************************************************************************************************/
/*!
 * \brief       Send the time message.
 * \details     This function sends the time message. If ECU type is VSM it updates the local tick-count by the
 *              real-time clock before.
 * \return      RTE_E_OK          Request successful.
 *              E_NOT_OK          Request failed.
 *              RTE_E_UNCONNECTED Sub-call failed due to missing RTE connection.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_FVM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_FvM_CODE) FvM_SendTimeMessage(void);

#endif

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *  FvM_HandleTickCountTimeouts()
 *********************************************************************************************************************/
/*!
 * \brief       Handle timeouts related to the reception of the secured tick-count message.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_HandleTickCountTimeouts(void);

/**********************************************************************************************************************
 *  FvM_HandleTickCountTimeouts_CheckCounters()
 *********************************************************************************************************************/
/*!
 * \brief       Handle timeouts related to the reception of the secured tick-count message.
 * \details     This function is called from FvM_HandleTickCountTimeouts to evaluate the values of the timeout counters.
 * \param[out]  tickCountReceptionErrorTimeoutOccurred_Sync  Flag to store whether
 *                                                           Ssa_FvM_TickCountReceptionTimeoutCounter reached value 0.
 * \param[out]  tickCountReceptionErrorTimeoutOccurred_Dtc   Flag to store whether
 *                                                           Ssa_FvM_TickCountReceptionComTimeoutCounter reached value 1.
 * \param[out]  tickCountAcceptanceTimeoutOccurred_Dtc       Flag to store whether
 *                                                           Ssa_FvM_TickCountAuthReceptionTimeoutCounter reached value 0.
 * \param[out]  diffLastRejectedTickCount                    Pointer to the byte array where the value of
 *                                                           Ssa_FvM_DiffLastRejectedTickCount will be stored.
 *                                                           The buffer must be of size 5 bytes.
 * \pre         All provided pointers must be valid.
 *              The buffer referenced by diffLastRejectedTickCount must provide at least 5 bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_HandleTickCountTimeouts_CheckCounters(
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) tickCountReceptionErrorTimeoutOccurred_Sync,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) tickCountReceptionErrorTimeoutOccurred_Dtc,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) tickCountAcceptanceTimeoutOccurred_Dtc,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) diffLastRejectedTickCount);

#endif /* (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM) */

#define Ssa_FvM_STOP_SEC_CODE
#include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Dcm_DiagnosticSessionControlType: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Coding_MemoryStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   CODING_OK (0U)
 *   CODING_FAILED (1U)
 *   CODING_ACTIVE (2U)
 * Coding_ModeType: Enumeration of integer in interval [0...255] with enumerators
 *   CODING_OK (0U)
 *   CODING_FAILED (1U)
 *   CODING_ACTIVE (2U)
 * Dem_InitMonitorReasonType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_INIT_MONITOR_CLEAR (1U)
 *   DEM_INIT_MONITOR_RESTART (2U)
 *   DEM_INIT_MONITOR_REENABLED (3U)
 *   DEM_INIT_MONITOR_STORAGE_REENABLED (4U)
 * RightsM_AuthenticationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   RIGHTSM_UNAUTHENTICATED (0U)
 *   RIGHTSM_AUTHENTICATED (1U)
 * Ssa_BswM_ComModeType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_COM_OFF (0U)
 *   SSA_COM_ON (1U)
 * Ssa_ChangeTickCountEventIdType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_CHANGETICKCOUNTEVENTID_ACCEPTED (0U)
 *   SSA_CHANGETICKCOUNTEVENTID_ACCEPTED_THRESHOLD_EXCEEDED (1U)
 *   SSA_CHANGETICKCOUNTEVENTID_REJECTED (2U)
 *   SSA_CHANGETICKCOUNTEVENTID_ERROR_TIMEOUT (3U)
 *   SSA_CHANGETICKCOUNTEVENTID_UNDEFINED (4U)
 * Ssa_OnOff_StateType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_STATE_OFF (0U)
 *   SSA_STATE_ON (1U)
 * Ssa_OperationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_ACTIVE (0U)
 *   SSA_INACTIVE (1U)
 * Ssa_TickCountSyncStateType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED (0U)
 *   SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_MASTER (1U)
 *   SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM (2U)
 *
 * Array Types:
 * ============
 * Ssa_Data5ByteType: Array with 5 element(s) of type uint8
 * Ssa_Data6ByteType: Array with 6 element(s) of type uint8
 * freshnessValueType: Array with 8 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Ssa_LocalTickCountAndSyncStatusType: Record with elements
 *   LocalTickCount of type uint64
 *   SyncStatus of type Ssa_TickCountSyncStateType
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint64 *Rte_Pim_LastSecuredTickCount(void)
 *   uint64 *Rte_Pim_TickCount(void)
 *
 *********************************************************************************************************************/


#define Ssa_FvM_START_SEC_CODE
#include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_ComModeChanged
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <comMode> of PortPrototype <Ssa_BswM_ComIndication>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_ComModeChanged_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_FvM_CODE) Ssa_FvM_ComModeChanged(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_ComModeChanged
 *********************************************************************************************************************/
  /* #10 Reset counter for sent secured time messages so that the startup cycle interval for sending the secured time
   *     messages is applied. */
  Ssa_FvM_RequestForStartupCycle = TRUE;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_Com_ReceiveTickCount
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <tickCount> of PortPrototype <FvM_Com_ReceiveTickCount>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FvM_Com_ReceiveTickCount_tickCount(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data6ByteType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SendChangeTickCountEvent_Id(Ssa_ChangeTickCountEventIdType data)
 *   Std_ReturnType Rte_Write_SendChangeTickCountEvent_TickCount(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data5ByteType
 *   Std_ReturnType Rte_Write_SendRealTimeOffsetCorrectionRequest_Data(uint64 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   boolean Rte_IrvRead_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvFirstTickCountMessageAfterStartUpReceived(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvFirstTickCountMessageAfterStartUpReceived(boolean data)
 *   void Rte_IrvWrite_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvTickCountSyncState(Ssa_TickCountSyncStateType data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_FvM_ExclusiveArea(void)
 *   void Rte_Exit_FvM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_Com_ReceiveTickCount_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_FvM_CODE) Ssa_FvM_Com_ReceiveTickCount(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_Com_ReceiveTickCount
 *********************************************************************************************************************/
  uint64 secTimeBase;
  uint8 syncStatusInfo;
  Ssa_Data6ByteType localTimeBaseNotified = { 0u };

  /* #10 Read the notified tick-count value. */
  if (RTE_E_OK == Rte_Read_FvM_Com_ReceiveTickCount_tickCount((P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR))localTimeBaseNotified))
  {
    /* Clear timer but do not clear any DTC. By setting to 0 this timer is restarted when the COM timeout event is received. */
    Ssa_FvM_TickCountReceptionComTimeoutCounter = 0u;

    /* #20 Extract the synchronization status information. */
    syncStatusInfo = localTimeBaseNotified[0];
    /* #30 Build the tick-count value from the message data. */
    secTimeBase = (uint64)localTimeBaseNotified[1] << 32;
    secTimeBase |= (uint64)localTimeBaseNotified[2] << 24;
    secTimeBase |= (uint64)localTimeBaseNotified[3] << 16;
    secTimeBase |= (uint64)localTimeBaseNotified[4] << 8;
    secTimeBase |= (uint64)localTimeBaseNotified[5];

    /* #40 Check if authentication by BcTP was successful and if received tick-count is a valid value. */
    if (((syncStatusInfo & 0x01u) == 0x01u) || (secTimeBase > FVM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL))
    {
      /* #50 If authentication failed or the new secured time is not a valid tick-count value, discard the tick-count
       *     information. */

      /* #55 Set tick-count sync state. */
      Rte_IrvWrite_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvTickCountSyncState(SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED);

      /* #60 Start tick-count authenticated reception timer if not yet running and if an unauthenticated or invalid message has been received. */
      Rte_Enter_FvM_ExclusiveArea();
      if (Ssa_FvM_TickCountAuthReceptionTimeoutCounter == 0u)
      {
        Ssa_FvM_TickCountAuthReceptionTimeoutCounter = FVM_TICKCOUNT_AUTHENTICATED_RECEPTION_TIMEOUT;
      }
      Rte_Exit_FvM_ExclusiveArea();
    }
    else
    {
      uint64 dt = 0uLL;
      boolean turningBack = FALSE;

      /* #70 If authentication succeeded clear tick-count authenticated reception timer if an authenticated and valid tick-count message has been received. */
      Ssa_FvM_TickCountAuthReceptionTimeoutCounter = 0u;

      /* #80 Check if secured time is acceptable as new local time base. */
      if (FvM_CheckNewLocalTimeBase(secTimeBase, &turningBack, &dt) == FALSE)
      {
        Rte_Enter_FvM_ExclusiveArea();

        /* #90 Set tick-count sync state. */
        Rte_IrvWrite_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvTickCountSyncState(SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED);

        /* #100 Discard the secured tick-count information but keep the time difference. */
        Ssa_FvM_DiffLastRejectedTickCount = dt;

        /* Start tick-count acceptance timer if not yet running and if an authenticated message has been rejected. */
        if (Ssa_FvM_TickCountAcceptanceTimeoutCounter == 0u)
        {
          Ssa_FvM_TickCountAcceptanceTimeoutCounter = FVM_TICKCOUNT_ACCEPTANCE_TIMEOUT;
        }
        Rte_Exit_FvM_ExclusiveArea();
      }
      /* #120 Else, new tick-count is accepted: */
# if (SSA_FVM_UNLIMITED_TURNING_BACK_OF_TICK_COUNT == STD_OFF)           /* COV_SSA_DEBUG TX */
      else
# endif
      {
        /* #130 Set new local tick-count and store accepted tick-count value as previous tick-count for checking next
         *      tick-count message being received. */
        FvM_SetLocalTimeBase(secTimeBase);

        /* #140 Set local tick-count synchronization state. */
        Rte_IrvWrite_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvTickCountSyncState(((syncStatusInfo & 0x80u) == 0x80u) ? SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM : SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_MASTER);

        /* #150 Clear tick-count acceptance timer if an authenticated tick-count message has been accepted. */
        Ssa_FvM_TickCountAcceptanceTimeoutCounter = 0u;

        /* #155 Start tick-count reception timer. */
        Ssa_FvM_TickCountReceptionTimeoutCounter = FVM_TICKCOUNT_RECEPTION_TIMEOUT;

        /* #160 Check if tick count is set to future more than the configured threshold value. Inform TimeM of the about result. */
        if ((turningBack == FALSE)
          && (dt > FVM_DEBUG_THRESHOLD_SETTING_TIME_TO_FUTURE)
          && (Rte_IrvRead_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvFirstTickCountMessageAfterStartUpReceived() == TRUE))
        {
          Ssa_Data5ByteType deltaTimeChange = { 0 };
          FvM_Copy5BytesToArray(dt, deltaTimeChange);

          (void)Rte_Write_SendChangeTickCountEvent_TickCount(deltaTimeChange);
          (void)Rte_Write_SendChangeTickCountEvent_Id(SSA_CHANGETICKCOUNTEVENTID_ACCEPTED_THRESHOLD_EXCEEDED);
        }
        else
        {
          (void)Rte_Write_SendChangeTickCountEvent_Id(SSA_CHANGETICKCOUNTEVENTID_ACCEPTED);
        }
      }

      /* #170 Store that first tick-count message after start-up has been received. */
      Rte_IrvWrite_Ssa_FvM_Com_ReceiveTickCount_FvM_IrvFirstTickCountMessageAfterStartUpReceived(TRUE);
    }
  }

  /* PRQA S 6050 4 */ /* MD_MSR_STCAL */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_Com_ReceiveTickCountTimeout
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <state> of PortPrototype <FvM_Com_ReceiveTickCountTimeout>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_Com_ReceiveTickCountTimeout_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_FvM_CODE) Ssa_FvM_Com_ReceiveTickCountTimeout(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_Com_ReceiveTickCountTimeout
 *********************************************************************************************************************/
  /* On reception of the COM signal time-out event start the FvM's tick-count reception timeout timer if it has not
     been started yet. */
  if (Ssa_FvM_TickCountReceptionComTimeoutCounter == 0u)
  {
    /* Considered as atomic write operation. */
    Ssa_FvM_TickCountReceptionComTimeoutCounter = FVM_TICKCOUNT_RECEPTION_COM_TIMEOUT;
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif /* (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM) */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_GetRxFreshness
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetRxFreshness> of PortPrototype <FvM_FreshnessManagement>
 *   - triggered by server invocation for OperationPrototype <GetRxFreshness> of PortPrototype <SecOC_FreshnessManagement>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_FvM_ExclusiveArea(void)
 *   void Rte_Exit_FvM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_FvM_GetRxFreshness(uint16 freshnessValueId, const uint8 *truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument truncatedFreshnessValue: uint8* is of type freshnessValueType
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_FvM_FreshnessManagement_E_BUSY
 *   RTE_E_FvM_FreshnessManagement_E_NOT_OK
 *   RTE_E_FvM_FreshnessManagement_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_GetRxFreshness_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 3673 20 */ /* MD_SSA_PARAM_NOT_P2CONST */
/*!
 * \spec
 *    requires $lengthOf(freshnessValue) >= (FvM_BitsToBytes(*freshnessValueLength));
 *    requires $lengthOf(freshnessValue) >= sizeof(freshnessValueType);
 * \endspec
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_GetRxFreshness(uint16 freshnessValueId, P2CONST(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_GetRxFreshness (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((truncatedFreshnessValue == NULL_PTR)
    || (freshnessValue == NULL_PTR)
    || (freshnessValueLength == NULL_PTR))
  {
    retVal = RTE_E_SecOC_FreshnessManagement_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  /* #10 Allow only one verification attempt. */
  if (authVerifyAttempts < 1u)
  {
    /*@ assert $lengthOf(freshnessValue) >= sizeof(freshnessValueType); */

    /* #20 Get the local tick-count. */
    uint64 localTimeBase = FvM_GetLocalTimeBase();
    /* #30 Calculate the three most probable freshness values (t1, t2 and t3) and find out which value is nearest to the
     *     local tick-count. */
    /* #40 Calculate t1 = (local_tick_count & 0xFFFFFFFFFFFFFF00) | truncated_freshness_value[0] and check the distance. */
    uint64 t1 = (localTimeBase & 0xFFFFFFFFFFFFFF00uLL) | (uint64)(truncatedFreshnessValue[0]);
    uint64 windowLowerBorder = (localTimeBase > 0x80uLL) ? (localTimeBase - 0x80u) : 0uLL;
    if ((t1 >= windowLowerBorder) && (t1 < (localTimeBase + 0x80u)))
    {
      /* If it is t1 return t1 as Rx freshness value. */
      retVal = FvM_CopyVarToArray(t1, freshnessValue, *freshnessValueLength); /* VCA_SSA_FVM_FRESHNESS_VALUE_LENGTH */
    }
    else
    {
      /* #50 Calculate t2 = t1 + 0x100 and check the distance. */
      uint64 t2 = t1 + 0x100u;
      if (t2 < (localTimeBase + 0x80u))
      {
        /* Else if it is t2 return t2 as Rx freshness value. */
        retVal = FvM_CopyVarToArray(t2, freshnessValue, *freshnessValueLength); /* VCA_SSA_FVM_FRESHNESS_VALUE_LENGTH */
      }
      else
      {
        /* #60 Calculate t3 = t1 - 0x100 and check the distance. */
        uint64 t3 = (t1 > 0x100uLL) ? (t1 - 0x100u) : 0uLL;
        /* Else return t3 as Rx freshness value. */
        retVal = FvM_CopyVarToArray(t3, freshnessValue, *freshnessValueLength); /* VCA_SSA_FVM_FRESHNESS_VALUE_LENGTH */
      }
    }
  }
  else
  {
    retVal = RTE_E_SecOC_FreshnessManagement_E_NOT_OK;
  }

  SSA_DUMMY_STATEMENT(freshnessValueId);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(truncatedFreshnessValueLength);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_GetTxFreshness
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetTxFreshness> of PortPrototype <FvM_FreshnessManagement>
 *   - triggered by server invocation for OperationPrototype <GetTxFreshness> of PortPrototype <SecOC_FreshnessManagement>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_FvM_ExclusiveArea(void)
 *   void Rte_Exit_FvM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_FvM_GetTxFreshness(uint16 freshnessValueId, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_FvM_FreshnessManagement_E_BUSY
 *   RTE_E_FvM_FreshnessManagement_E_NOT_OK
 *   RTE_E_FvM_FreshnessManagement_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_GetTxFreshness_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3673 20 */ /* MD_SSA_PARAM_NOT_P2CONST */
/*!
 * \spec
 *    requires $lengthOf(freshnessValue) >= (FvM_BitsToBytes(*freshnessValueLength));
 *    requires $lengthOf(freshnessValue) >= sizeof(freshnessValueType);
 * \endspec
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_GetTxFreshness(uint16 freshnessValueId, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_GetTxFreshness (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  /* #5 Apply development error detection if enabled by configuration. */
  if ((freshnessValue == NULL_PTR)
    || (freshnessValueLength == NULL_PTR))
  {
    retVal = RTE_E_FvM_FreshnessManagement_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Copy the requested number of bytes of local time-base value to the memory location of the freshness value. */
    /*@ assert $lengthOf(freshnessValue) >= sizeof(freshnessValueType); */
    retVal = FvM_CopyVarToArray(FvM_GetLocalTimeBase(), freshnessValue, *freshnessValueLength); /* VCA_SSA_FVM_FRESHNESS_VALUE_LENGTH */
  }

  SSA_DUMMY_STATEMENT(freshnessValueId);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_GetTxFreshnessTruncData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetTxFreshnessTruncData> of PortPrototype <SecOC_FreshnessManagement>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_FvM_ExclusiveArea(void)
 *   void Rte_Exit_FvM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_FvM_GetTxFreshnessTruncData(uint16 freshnessValueId, uint8 *freshnessValue, uint32 *freshnessValueLength, uint8 *truncatedFreshnessValue, uint32 *truncatedFreshnessValueLength)
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *     Argument truncatedFreshnessValue: uint8* is of type freshnessValueType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecOC_FreshnessManagement_E_BUSY
 *   RTE_E_SecOC_FreshnessManagement_E_NOT_OK
 *   RTE_E_SecOC_FreshnessManagement_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_GetTxFreshnessTruncData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 3673 20 */ /* MD_SSA_PARAM_NOT_P2CONST */
/*!
 * \spec
 *    requires $lengthOf(freshnessValue) >= (FvM_BitsToBytes(*freshnessValueLength));
 *    requires $lengthOf(freshnessValue) >= sizeof(freshnessValueType);
 *    requires $lengthOf(truncatedFreshnessValue) >= (FvM_BitsToBytes(*truncatedFreshnessValueLength));
 *    requires $lengthOf(truncatedFreshnessValue) >= sizeof(freshnessValueType);
 * \endspec
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_GetTxFreshnessTruncData(uint16 freshnessValueId, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) freshnessValueLength, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) truncatedFreshnessValue, P2VAR(uint32, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) truncatedFreshnessValueLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_GetTxFreshnessTruncData (returns application error)
 *********************************************************************************************************************/
  uint8_least i;
  Std_ReturnType retVal;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  /* #5 Apply development error detection if enabled by configuration. */
  if ((freshnessValue == NULL_PTR)
    || (freshnessValueLength == NULL_PTR)
    || (truncatedFreshnessValue == NULL_PTR)
    || (truncatedFreshnessValueLength == NULL_PTR))
  {
    retVal = RTE_E_SecOC_FreshnessManagement_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  /* #10 The truncated freshness value length (in bits) must be a multiple of 8 and must no be larger than 64 (bits). */
  if (((*truncatedFreshnessValueLength & 0x07u) != 0u) || ((*truncatedFreshnessValueLength) > 64u))
  {
    retVal = RTE_E_SecOC_FreshnessManagement_E_NOT_OK;
  }
  else
  {
    /* #20 Get the Tx freshness value. */
    /*@ assert $lengthOf(freshnessValue) >= sizeof(freshnessValueType); */
    retVal = Ssa_FvM_GetTxFreshness(freshnessValueId, freshnessValue, freshnessValueLength); /* VCA_SSA_FVM_FRESHNESS_VALUE_LENGTH */
    if (retVal == RTE_E_OK)
    {
      /* #30 Truncate the Tx freshness value by discarding the most significant bytes and copy the remaining data in
       * reverse byte order to the memory location for the truncated freshness value. */
      /*@ assert $lengthOf(truncatedFreshnessValue) >= (FvM_BitsToBytes(*truncatedFreshnessValueLength)); */ /* VCA_SSA_FVM_BUFFER_ACCESS_AFTER_SPEC_AND_RUNTIME_CHECK */
      /* Cast is ok since (*truncatedFreshnessValueLength) <= 64u) */
      for (i = 0u; i < (uint8_least)((*truncatedFreshnessValueLength) >> 3u); i++) /* FETA_SSA_FVM_MONOTONIC_FOR_LOOP_UP_WITH_UPPER_BOUND_FROM_EXT_BUFFER */
      {
        /*@ assert i <= (FvM_BitsToBytes(*truncatedFreshnessValueLength)); */ /* VCA_SSA_FVM_BUFFER_ACCESS_AFTER_SPEC_AND_RUNTIME_CHECK */
        truncatedFreshnessValue[i] = freshnessValue[(*freshnessValueLength >> 3u) - ((uint32)i + 1u)]; /* VCA_SSA_FVM_BUFFER_ACCESS_AFTER_SPEC_AND_RUNTIME_CHECK */
      }
    }
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FvM_SendLocalTickCountAndSyncStatus_Data(const Ssa_LocalTickCountAndSyncStatusType *data)
 *   Std_ReturnType Rte_Write_SendRealTimeOffsetCorrectionRequest_Data(uint64 data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvCountUpSecTimeMsg(uint8 data)
 *   void Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvFirstTickCountMessageAfterStartUpReceived(boolean data)
 *   void Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvTickCountSyncState(Ssa_TickCountSyncStateType data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_RealTimeClock_Get(uint64 *rtcTickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Ssa_RealTimeClock_E_NOT_OK
 *   Std_ReturnType Rte_Call_FvM_RealTimeClock_Set(uint64 rtcTickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Ssa_RealTimeClock_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_Init_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_FvM_CODE) Ssa_FvM_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_Init
 *********************************************************************************************************************/

  /* #70 If ECU type is VSM set the local tick-count synchronization state to "synchronized to VSM",
   *     else to "not synchronized". */
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  Ssa_LocalTickCountAndSyncStatusType localTickCountAndSyncStatus = { 0ULL, SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM };
  Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvTickCountSyncState(SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM);
# else
  Ssa_LocalTickCountAndSyncStatusType localTickCountAndSyncStatus = { 0ULL, SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED };
  Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvTickCountSyncState(SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED);
  Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvFirstTickCountMessageAfterStartUpReceived(FALSE);
#endif /* (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) */

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
  Ssa_FvM_CountDownSecTimeMsgCycle = 0u;
  Rte_IrvWrite_Ssa_FvM_Init_FvM_IrvCountUpSecTimeMsg(0u);
  Ssa_FvM_RequestForStartupCycle = FALSE;
#endif /* ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)) */

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

  /* #80 If ECU type is VSM get the current real-time from the real-time clock (RTC). */
  if (Rte_Call_FvM_RealTimeClock_Get(&Ssa_FvM_RtcCorrection) == RTE_E_OK)
  {
    /* Reduce resolution of RTC to local tick count */
    Ssa_FvM_RtcCorrection /= FVM_RTC_TO_LOCAL_TICK_COUNT_RESOLUTION_DIV;
    /* #90 Check whether a loss for the real-time clock (RTC) value has to be compensated for (i.e. if it is smaller
    * than the local tick-count. */
    if ((Ssa_FvM_RtcCorrection + SSA_FVM_RTC_CORRECTION_TOLERANCE) < *Rte_Pim_TickCount()) /* PRQA S 2985 */ /* MD_SSA_REDUNDANT_OP */
    {
      uint64 diff = FVM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL - *Rte_Pim_TickCount();
      /* #100 Increase the local tick-count by the defined compensation value. */
      if (diff >= FVM_COMPENSATION_FOR_LOSS_OF_RTC_VALUE)
      {
        *Rte_Pim_TickCount() += FVM_COMPENSATION_FOR_LOSS_OF_RTC_VALUE;
        /* Inform TimeM on the changed tick-count for it has to adapt the real-time offset too. Set any value since without effect. */
        (void)Rte_Write_SendRealTimeOffsetCorrectionRequest_Data(FVM_COMPENSATION_FOR_LOSS_OF_RTC_VALUE);
      }
      else
      {
        *Rte_Pim_TickCount() = FVM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL;
        /* Inform TimeM on the changed tick-count for it has to adapt the real-time offset too. Set any value since without effect. */
        (void)Rte_Write_SendRealTimeOffsetCorrectionRequest_Data(diff);
      }

      /* #130 Set the RTC to the adjusted local tick-count and derive the RTC correction value that is applied to the
      * local tick-count from now on. */
      if (Rte_Call_FvM_RealTimeClock_Set(*Rte_Pim_TickCount() * FVM_RTC_TO_LOCAL_TICK_COUNT_RESOLUTION_DIV) != E_OK)
      {
        /* #132 If setting the RTC fails apply as correction the period that the local tick-count is in advance. */
        Ssa_FvM_RtcCorrection = *Rte_Pim_TickCount() - Ssa_FvM_RtcCorrection;
      }
      else
      {
        /* #134 If setting the RTC succeeds no correction has to be applied since RTC has been synchronized to the new
        local tick-count. */
        Ssa_FvM_RtcCorrection = 0uLL;
      }
    }
    else
    {
      Ssa_FvM_RtcCorrection = 0uLL;
    }
  }
  else
  {
    /* #150 If getting the real-time from RTC fails, set the RTC correction value to zero. */
    Ssa_FvM_RtcCorrection = 0uLL;
  }
#else
  Ssa_FvM_TickCount = 0U;
  Ssa_FvM_TickCountReceptionTimeoutCounter = 0u; /* is started with the acceptance of an tick-count */
  Ssa_FvM_TickCountReceptionComTimeoutCounter = 0u; /* is started with the reception of an timeout event coming from BcTp (coming from Com) */
  Ssa_FvM_TickCountAuthReceptionTimeoutCounter = 0U; /* is started with the reception of an unauthenticated tick-count */
  Ssa_FvM_TickCountAcceptanceTimeoutCounter = 0U; /* is started with the rejection of an authenticated tick-count */

#endif /* (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) */

  /* Write the local tick-count to the S/R buffer (in case the TimeM main function reading the buffer is called before
     the FvM main function writing the buffer.
     Sync state is not synchronized here. */
  localTickCountAndSyncStatus.LocalTickCount = *Rte_Pim_TickCount();
  (void)Rte_Write_FvM_SendLocalTickCountAndSyncStatus_Data(&localTickCountAndSyncStatus);

  /* Ensure type sizes once for the FvM submodule which calls RTE APIs expecting these data types:
   * Ssa_Data6ByteType must be an array with 6 element(s) of type uint8 */
  /*@ assert sizeof(Ssa_Data6ByteType) == 6u; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_InitMonitorForEvent_DTC_0xD12081
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitMonitorForEvent> of PortPrototype <CallbackInitMonitorForEvent_DTC_0xD12081>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_FvM_InitMonitorForEvent_DTC_0xD12081(Dem_InitMonitorReasonType InitMonitorReason)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackInitMonitorForEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_InitMonitorForEvent_DTC_0xD12081_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_InitMonitorForEvent_DTC_0xD12081(Dem_InitMonitorReasonType InitMonitorReason) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_InitMonitorForEvent_DTC_0xD12081 (returns application error)
 *********************************************************************************************************************/

  /* #10 Check that "init monitor reason" is "clear". */
  if (InitMonitorReason == DEM_INIT_MONITOR_CLEAR)
  {
    /* #20 Clear tick-count acceptance timer on clear event. */
    /* atomic operation */
    Ssa_FvM_TickCountAcceptanceTimeoutCounter = 0u;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_InitMonitorForEvent_DTC_0xD12087
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitMonitorForEvent> of PortPrototype <CallbackInitMonitorForEvent_DTC_0xD12087>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_FvM_InitMonitorForEvent_DTC_0xD12087(Dem_InitMonitorReasonType InitMonitorReason)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackInitMonitorForEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_InitMonitorForEvent_DTC_0xD12087_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_InitMonitorForEvent_DTC_0xD12087(Dem_InitMonitorReasonType InitMonitorReason) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_InitMonitorForEvent_DTC_0xD12087 (returns application error)
 *********************************************************************************************************************/

  /* #10 Check that "init monitor reason" is "clear". */
  if (InitMonitorReason == DEM_INIT_MONITOR_CLEAR)
  {
    /* #20 Clear tick-count reception COM timer on clear event. */
    /* atomic operation */
    Ssa_FvM_TickCountReceptionComTimeoutCounter = 0u;

    /* #30 Clear tick-count authenticated reception timer on clear event. */
    /* atomic operation */
    Ssa_FvM_TickCountAuthReceptionTimeoutCounter = 0u;
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_InitialTickCount_Set
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <FvM_InitialTickCount>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_FvM_ExclusiveArea(void)
 *   void Rte_Exit_FvM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_FvM_InitialTickCount_Set(uint64 tickCount)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_FvM_InitialTickCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_InitialTickCount_Set_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_InitialTickCount_Set(uint64 tickCount) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_InitialTickCount_Set (returns application error)
 *********************************************************************************************************************/
  /* #10 Set local time base. */
  FvM_SetLocalTimeBase(tickCount);
  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_LocalTickCountSyncStatus_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <FvM_LocalTickCountSyncStatus>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   Ssa_TickCountSyncStateType Rte_IrvRead_Ssa_FvM_LocalTickCountSyncStatus_Get_FvM_IrvTickCountSyncState(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_FvM_LocalTickCountSyncStatus_Get(Ssa_TickCountSyncStateType *syncState)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_FvM_LocalTickCountSyncStatus_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_LocalTickCountSyncStatus_Get_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_LocalTickCountSyncStatus_Get(P2VAR(Ssa_TickCountSyncStateType, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) syncState) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_LocalTickCountSyncStatus_Get (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_FvM_LocalTickCountSyncStatus_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
 /* #5 Apply development error detection if enabled by configuration. */
  if (syncState == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    /* #10 If ECU type is VSM provide as synchronization status always "synchronized to VSM". */
    *syncState = SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM;
#else
    /* #20 If ECU type is not VSM provide as synchronization status the current tick-count synchronization state. */
    *syncState = Rte_IrvRead_Ssa_FvM_LocalTickCountSyncStatus_Get_FvM_IrvTickCountSyncState();
#endif
    retVal = RTE_E_OK;
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_Mainfunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FvM_Com_SendTickCount_tickCount(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data6ByteType
 *   Std_ReturnType Rte_Write_FvM_SendLocalTickCountAndSyncStatus_Data(const Ssa_LocalTickCountAndSyncStatusType *data)
 *   Std_ReturnType Rte_Write_SendChangeTickCountEvent_Id(Ssa_ChangeTickCountEventIdType data)
 *   Std_ReturnType Rte_Write_SendChangeTickCountEvent_TickCount(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data5ByteType
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   uint8 Rte_IrvRead_Ssa_FvM_Mainfunction_FvM_IrvCountUpSecTimeMsg(void)
 *   Ssa_TickCountSyncStateType Rte_IrvRead_Ssa_FvM_Mainfunction_FvM_IrvTickCountSyncState(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Ssa_FvM_Mainfunction_FvM_IrvCountUpSecTimeMsg(uint8 data)
 *   void Rte_IrvWrite_Ssa_FvM_Mainfunction_FvM_IrvTickCountSyncState(Ssa_TickCountSyncStateType data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_RealTimeClock_Get(uint64 *rtcTickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Ssa_RealTimeClock_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_FvM_ExclusiveArea(void)
 *   void Rte_Exit_FvM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_Mainfunction_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_FvM_CODE) Ssa_FvM_Mainfunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_Mainfunction
 *********************************************************************************************************************/
  Ssa_LocalTickCountAndSyncStatusType localTickCountAndSyncStatus;

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)
  FvM_HandleTickCountTimeouts();

  /* #30 If ECU type is not VSM a tick might be periodically skipped depending on the defined slow-down. */
  Ssa_FvM_TickCount++;
  if (Ssa_FvM_TickCount == FVM_TICK_COUNT_SKIP)
  {
    Ssa_FvM_TickCount = 0u;
  }
  else
#endif /* ((SSA_ECU_TYPE == SSA_ECU_TYPE_NORMAL) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)) */
    /* #40 Increment the local time base (tick count) each time the main function is entered. */
  {
    FvM_IncLocalTimeBase();
  }

  /* #50 If ECU type is VSM or GATEWAY the secured time message is sent periodically. */
#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
  /* #60 Use a counter that is decremented each main loop, sent the tick-count broadcast message when the counter
  * value is fully counted down and reset the counter after the message is sent. */
  /* #62 Check if startup cycle (burst mode) for sending the secured time message is requested. */
  if (Ssa_FvM_RequestForStartupCycle == TRUE)
  {
    Ssa_FvM_RequestForStartupCycle = FALSE;
    /* #64 Reset counter for messages sent during the startup cycle. */
    Rte_IrvWrite_Ssa_FvM_Mainfunction_FvM_IrvCountUpSecTimeMsg(0u);
    /* #66 Shorten the remaining time period until startup cycle is applied. */
    if (Ssa_FvM_CountDownSecTimeMsgCycle > FVM_STARTUP_CYCLE_WAITING_TIME)
    {
      Ssa_FvM_CountDownSecTimeMsgCycle = FVM_STARTUP_CYCLE_WAITING_TIME;
    }
  }

  /* #68 Check if counter is fully counted down. */
  if (Ssa_FvM_CountDownSecTimeMsgCycle > 0u)
  {
    Ssa_FvM_CountDownSecTimeMsgCycle--;
  }
  else
  {
    /* #70 Update local tick-count by RTC and send the time message afterwards (by writing to S/R buffer). */
    /* Discard return value for two reasons:
    * - it is always RTE_E_OK except of if port is unconnected.
    * - sporadic errors (if there ever will be any) are compensated by the periodical sending of the tick-count. */
    (void)FvM_SendTimeMessage();
    /* #80 After successful sending and before resetting the count down value check for change from startup cycle
    * interval to regular cycle interval. */
    if (Rte_IrvRead_Ssa_FvM_Mainfunction_FvM_IrvCountUpSecTimeMsg() < FVM_SEC_TIME_MSG_NUM_STARTUP)
    {
      /* Increment counter for sent secured time messages. */
      Rte_IrvWrite_Ssa_FvM_Mainfunction_FvM_IrvCountUpSecTimeMsg(Rte_IrvRead_Ssa_FvM_Mainfunction_FvM_IrvCountUpSecTimeMsg() + 1u);
      /* Reset count down value. */
      Ssa_FvM_CountDownSecTimeMsgCycle = FVM_SEC_TIME_MSG_CYCLE_TIME_STARTUP - 1u;
    }
    else
    {
      /* Reset count down value. */
      Ssa_FvM_CountDownSecTimeMsgCycle = FVM_SEC_TIME_MSG_CYCLE_TIME_REGULAR - 1u;
    }
  }
#endif /* ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)) */

  /* Write the local tick-count to the S/R buffer. */
  localTickCountAndSyncStatus.LocalTickCount = FvM_GetLocalTimeBase();
  localTickCountAndSyncStatus.SyncStatus = Rte_IrvRead_Ssa_FvM_Mainfunction_FvM_IrvTickCountSyncState();
  (void)Rte_Write_FvM_SendLocalTickCountAndSyncStatus_Data(&localTickCountAndSyncStatus);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_FvM_SPduTxConfirmation
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SPduTxConfirmation> of PortPrototype <SecOC_FreshnessManagement>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_FvM_SPduTxConfirmation(uint16 freshnessValueId)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecOC_FreshnessManagement_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_SPduTxConfirmation_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_FvM_CODE) Ssa_FvM_SPduTxConfirmation(uint16 freshnessValueId) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_FvM_SPduTxConfirmation (returns application error)
 *********************************************************************************************************************/
  /* Parameter not used. */
  SSA_DUMMY_STATEMENT(freshnessValueId);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  /* #10 No action within this function. Always return successfully. */
  return RTE_E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ssa_FvM_STOP_SEC_CODE
#include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_FvM_START_SEC_CODE
#include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * FvM_SetLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_SetLocalTimeBase(uint64 timeBase)
{
  /* #10 If the passed tick-count value does not exceed the maximum tick-count value copy it to the memory address of the
   *     local tick-count within an exclusive area. Store the value as "last, accepted secured tick-count. */
  if (timeBase <= FVM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL)
  {
    Rte_Enter_FvM_ExclusiveArea();
    *Rte_Pim_TickCount() = timeBase;
    *Rte_Pim_LastSecuredTickCount() = timeBase;
    Rte_Exit_FvM_ExclusiveArea();
  }
}

/**********************************************************************************************************************
 * FvM_GetLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(uint64, Ssa_FvM_CODE) FvM_GetLocalTimeBase(void)
{
  uint64 localTimeBase;
  /* #10 Copy the stored local tick-count to a temporary buffer within an exclusive area. */
  Rte_Enter_FvM_ExclusiveArea();
  localTimeBase = *Rte_Pim_TickCount();
  Rte_Exit_FvM_ExclusiveArea();
  /* #20 Return the tick-count. */
  return localTimeBase;
}

/**********************************************************************************************************************
 * FvM_IncLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_IncLocalTimeBase(void)
{
  /* #10 Increment within an exclusive area the stored local tick-count as along as the maximum tick-count value is not reached. */
  Rte_Enter_FvM_ExclusiveArea();
  if (*Rte_Pim_TickCount() < FVM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL)
  {
    (*Rte_Pim_TickCount())++;
  }
  Rte_Exit_FvM_ExclusiveArea();
}

/**********************************************************************************************************************
 * FvM_GetLastSecuredTickCount()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(uint64, Ssa_FvM_CODE) FvM_GetLastSecuredTickCount(void)
{
  uint64 lastSecuredTickCount;
  /* #10 Copy the stored, last secured tick-count to a temporary buffer within an exclusive area. */
  Rte_Enter_FvM_ExclusiveArea();
  lastSecuredTickCount = *Rte_Pim_LastSecuredTickCount();
  Rte_Exit_FvM_ExclusiveArea();
  /* #20 Return the tick-count. */
  return lastSecuredTickCount;
}

/**********************************************************************************************************************
 * FvM_CheckNewLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(boolean, Ssa_FvM_CODE) FvM_CheckNewLocalTimeBase(uint64 newTimeBase, P2VAR(boolean, AUTOMATIC, AUTOMATIC) turningBack, P2VAR(uint64, AUTOMATIC, AUTOMATIC) timeDifference)
{
  /* maximum correction value for turning back local tick-count */
  uint64 limitCorrection = FVM_MAX_SPAN_TURNING_LOCAL_TIME_BACK;
  uint64 localTimeBase = FvM_GetLocalTimeBase();
  boolean isAcceptable = TRUE;

  /* SSA-IS-1555 If the received secure tick-count is smaller than the local tick-count, the Time
  Management module shall calculate the difference between the local tick-count and the
  received tick-count. */
  /* SSA-IS-1556 If this difference is less then a certain percentage of the difference between the local
  tick-count and the last accepted tick-count, the Time Management module shall set the
  received tick-count as new local tick count. */
  /* SSA-IS-1559 The maximum amount the local tick-count may be decremented shall be the configured
  percentage with respect to the nominal update window of the secured tick-count. */

  /* #10 Check if the received tick-count can be accepted as new local tick-count since the local tick-count must
  * not be turned back to much. */

  /* #20 Find out if local time base shall be turned back. */
  if (newTimeBase < localTimeBase)
  {
    uint64 diffSecTime;

    *turningBack = TRUE;
    /* #30 Calculate time difference (in ticks) between local time and new time (knowing that new time is smaller). */
    *timeDifference = localTimeBase - newTimeBase;
    /* #40 Calculate time difference (in ticks) between local time and last secured time. */
    diffSecTime = localTimeBase - FvM_GetLastSecuredTickCount();
    /* #50 Calculate maximum correction value for turning back local tick-count if secured time message "comes in earlier". */
    if (diffSecTime < FVM_SEC_TIME_MSG_CYCLE_TIME_REGULAR)
    {
      limitCorrection = (diffSecTime * SSA_FVM_PERCENTAGE_TURNING_BACK_LOCAL_TICK_COUNT);
    }
    /* #60 Check if turning back of the local time by more than the allowed amount.
     *     Accept in case of equality. */
    if ((*timeDifference * 100ULL) > limitCorrection)
    {
      isAcceptable = FALSE;
    }
  }
  else
  {
    *turningBack = FALSE;
    /* #70 Calculate time difference (in ticks) between new time and local time (knowing that new time is greater). */
    *timeDifference = newTimeBase - localTimeBase;
  }

  return  isAcceptable;
}

/**********************************************************************************************************************
 * FvM_CopyVarToArray()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_FvM_CODE) FvM_CopyVarToArray(uint64 value, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) buffer, uint32 lengthInBit)
{
  Std_ReturnType retVal = RTE_E_OK;
  /* #10 Check the length parameter. It must be a multiple of 8 (bits). */
  if((lengthInBit & 0x07u) != 0u)
  {
    retVal = RTE_E_INVALID;
  }
  /* #20 Check the length parameter: It must not be larger than 64 (bits). */
  else if (lengthInBit > 64u)
  {
    retVal = RTE_E_INVALID;
  }
  /* #30 Copy the data of the 64 bit value byte-by-byte to the target buffer. */
  else
  {
    uint8 i;
    uint32 idx = ((lengthInBit > 0u) ? ((lengthInBit >> 3) - 1u) : 0u);

    /* #40 Copy the least significant byte from the 64 bit value to the lowest memory position of the byte array
     * (index 0) and so on. */
    /*@ assert $lengthOf(buffer) >= FvM_BitsToBytes(lengthInBit); */ /* VCA_SSA_FVM_BUFFER_ACCESS_AFTER_SPEC_AND_RUNTIME_CHECK */
    for (i = 0u; i < (lengthInBit); i = i + 8u) /* FETA_SSA_FVM_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_OF_RESTRICTED_MAX_VALUE */
    {
      /*@ assert i <= lengthInBit; */ /* VCA_SSA_FVM_BUFFER_ACCESS_AFTER_SPEC_AND_RUNTIME_CHECK */
      /*@ assert idx <= FvM_BitsToBytes(lengthInBit); */ /* VCA_SSA_FVM_BUFFER_ACCESS_AFTER_SPEC_AND_RUNTIME_CHECK */
      buffer[idx] = (uint8)((value >> i) & 0xFFu); /* VCA_SSA_FVM_BUFFER_ACCESS_AFTER_SPEC_AND_RUNTIME_CHECK */
      idx--;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
* FvM_Copy5BytesToArray()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_Copy5BytesToArray(uint64 value, P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) buffer)
{
  /* #10 Copy the 5 lowest bytes byte-by-byte into the given byte array (high byte first). */
  buffer[0] = (uint8)((value >> 32) & 0xFFu);
  buffer[1] = (uint8)((value >> 24) & 0xFFu);
  buffer[2] = (uint8)((value >> 16) & 0xFFu);
  buffer[3] = (uint8)((value >> 8) & 0xFFu);
  buffer[4] = (uint8)(value & 0xFFu);
}

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
 * FvM_SendTimeMessage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_FvM_CODE) FvM_SendTimeMessage(void)
{
  Ssa_Data6ByteType secTimeBase = { 0u };
  uint64 localTimeBase;

# if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  uint64 currentRtcValue = 0uLL;
  boolean turningBack = FALSE;
  /* #10 If ECU type is VSM update the local tick-count by the real-time clock. */
  if (Rte_Call_FvM_RealTimeClock_Get(&currentRtcValue) == RTE_E_OK) /* local buffer of known size as required by callout API */
  {
    /* Reduce resolution of RTC to local tick count */
    currentRtcValue /= FVM_RTC_TO_LOCAL_TICK_COUNT_RESOLUTION_DIV;

    /* Apply RTC correction */
    currentRtcValue += Ssa_FvM_RtcCorrection;

    /* Discard new local tick-counts that would be rejected by the slaves ECU to avoid that the VSM becomes asynchronous. */
    /* Both return value are not used. */
    if (FvM_CheckNewLocalTimeBase(currentRtcValue, &turningBack, &localTimeBase) == TRUE)
    {
      FvM_SetLocalTimeBase(currentRtcValue);
    }
  }

  /* #20 If ECU type is VSM set the tick-count synchronization flag always to true. */
  secTimeBase[0] = 0x80u;
# else
  /* #30 If ECU type is not VSM set the tick-count synchronization flag to true only if ECU is synchronized to VSM. */
  secTimeBase[0] = (Rte_IrvRead_Ssa_FvM_Mainfunction_FvM_IrvTickCountSyncState() == SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM) ? 0x80u : 0x00u;
# endif /* (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) */

  /* #40 Get the current local tick-count. */
  localTimeBase = FvM_GetLocalTimeBase();

  /* #50 Fill the local tick-count byte-by-byte into an byte array (high byte first). */
  FvM_Copy5BytesToArray(localTimeBase, &secTimeBase[1]);

  /* #60 Send time messages by writing cerated byte message to S/R buffer. */
  return (Rte_Write_FvM_Com_SendTickCount_tickCount((P2CONST(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_DATA))secTimeBase));
}

#endif

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 * FvM_HandleTickCountTimeouts()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_HandleTickCountTimeouts(void)
{
  boolean tickCountReceptionErrorTimeoutOccurred_Sync = FALSE;
  boolean tickCountReceptionErrorTimeoutOccurred_Dtc = FALSE;
  boolean tickCountAcceptanceTimeoutOccurred_Dtc = FALSE;
  Ssa_Data5ByteType diffLastRejectedTickCount = { 0 };

  /* #10 Call FvM_HandleTickCountTimeouts_CheckCounters to set TimeoutOccurred flags according to counter value. */
  FvM_HandleTickCountTimeouts_CheckCounters(&tickCountReceptionErrorTimeoutOccurred_Sync, &tickCountReceptionErrorTimeoutOccurred_Dtc, &tickCountAcceptanceTimeoutOccurred_Dtc, diffLastRejectedTickCount);

  /* #20 Based on TimeoutOccurred flags, update the values of global variables. */
  if (tickCountReceptionErrorTimeoutOccurred_Sync)
  {
    /* set tick-count sync state */
    Rte_IrvWrite_Ssa_FvM_Mainfunction_FvM_IrvTickCountSyncState(SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED);
  }

  if (tickCountReceptionErrorTimeoutOccurred_Dtc)
  {
    /* inform TimeM which in turn might set a DTC or write a security log entry */
    (void)Rte_Write_SendChangeTickCountEvent_Id(SSA_CHANGETICKCOUNTEVENTID_ERROR_TIMEOUT);
  }

  if (tickCountAcceptanceTimeoutOccurred_Dtc)
  {
    /* inform TimeM which in turn might set a DTC or write a security log entry */
    (void)Rte_Write_SendChangeTickCountEvent_TickCount(diffLastRejectedTickCount);
    (void)Rte_Write_SendChangeTickCountEvent_Id(SSA_CHANGETICKCOUNTEVENTID_REJECTED);
  }
}

/**********************************************************************************************************************
 * FvM_HandleTickCountTimeouts_CheckCounters()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
SSA_FVM_LOCAL_INLINE FUNC(void, Ssa_FvM_CODE) FvM_HandleTickCountTimeouts_CheckCounters(
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) tickCountReceptionErrorTimeoutOccurred_Sync,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) tickCountReceptionErrorTimeoutOccurred_Dtc,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) tickCountAcceptanceTimeoutOccurred_Dtc,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) diffLastRejectedTickCount)
{
  Rte_Enter_FvM_ExclusiveArea();
  /* #10 If tick-count reception timeout counter has elapsed set synchronization state to "not synchronized. */
  if (Ssa_FvM_TickCountReceptionTimeoutCounter > 0U)
  {
    --Ssa_FvM_TickCountReceptionTimeoutCounter;
    if (Ssa_FvM_TickCountReceptionTimeoutCounter == 0U)
    {
      *tickCountReceptionErrorTimeoutOccurred_Sync = TRUE;
    }
  }

  /* #20 If tick-count reception COM timeout counter has elapsed inform TimeM about this.
         Counter remains 1 so that incoming COM timeout events do not restart this timer before a tick-count is received. */
  if (Ssa_FvM_TickCountReceptionComTimeoutCounter > 1U)
  {
    --Ssa_FvM_TickCountReceptionComTimeoutCounter;
    if (Ssa_FvM_TickCountReceptionComTimeoutCounter == 1U)
    {
      *tickCountReceptionErrorTimeoutOccurred_Dtc = TRUE;
    }
  }

  /* #30 If tick-count authenticated reception timeout counter has elapsed inform TimeM about this
   *     and set synchronization state to "not synchronized.*/
  if (Ssa_FvM_TickCountAuthReceptionTimeoutCounter > 0U)
  {
    Ssa_FvM_TickCountAuthReceptionTimeoutCounter--;
    if (Ssa_FvM_TickCountAuthReceptionTimeoutCounter == 0U)
    {
      *tickCountReceptionErrorTimeoutOccurred_Dtc = TRUE;
    }
  }

  /* #40 If tick-count acceptance timeout counter has elapsed inform TimeM about this
   *     and set synchronization state to "not synchronized. */
  if (Ssa_FvM_TickCountAcceptanceTimeoutCounter > 0U)
  {
    --Ssa_FvM_TickCountAcceptanceTimeoutCounter;
    if (Ssa_FvM_TickCountAcceptanceTimeoutCounter == 0U)
    {
      *tickCountAcceptanceTimeoutOccurred_Dtc = TRUE;
      FvM_Copy5BytesToArray(Ssa_FvM_DiffLastRejectedTickCount, diffLastRejectedTickCount);
    }
  }
  Rte_Exit_FvM_ExclusiveArea();
} /* PRQA S 6010 */ /* MD_SSA_PTH_CHECK_CONDITIONS */

#endif /* ((SSA_ECU_TYPE == SSA_ECU_TYPE_NORMAL) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)) */

#define Ssa_FvM_STOP_SEC_CODE
#include "Ssa_FvM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 **********************************************************************************************************************/

/* VCA_JUSTIFICATION_BEGIN

  \ID VCA_SSA_FVM_FRESHNESS_VALUE_LENGTH
    \DESCRIPTION    According to VCA, the following functions may be called outside their specification: 
                    - FvM_CopyVarToArray(value, freshnessValue, *freshnessValueLength), 
                      where 'value' is a 64 bit variable.
    \COUNTERMEASURE \N The called functions require that $lengthOf(freshnessValue) >= FvM_BitsToByte(*freshnessValueLength)
                    and/or that $lengthOf(freshnessValue) >= sizeof(freshnessValueType).
                    These requirements are enforced by assuming the same requirements for the callers
                    - Ssa_FvM_GetRxFreshness(),
                    - Ssa_FvM_GetTxFreshness() and
                    - Ssa_FvM_GetTxFreshnessTruncData()
                    themselves.

  \ID VCA_SSA_FVM_BUFFER_ACCESS_AFTER_SPEC_AND_RUNTIME_CHECK
    \DESCRIPTION  According to the VCA, the following violations may occur:
                    - Failing assertion: $lengthOf(buffer) >= lengthGivenInFunctionSpecification
                    - Failing assertion: index <= upperBound inside a for-loop
                    - Possible access out of bounds: buffer[index]
    \COUNTERMEASURE \N $lengthOf(buffer) >= lengthGivenInFunctionSpecification is guaranteed by a specification,
                    which is checked when the function is called.
                    Index is a local variable. The upper bound is given in the for-loop condition.
                    Thus, index <= upperBound is guaranteed by a runtime check.
                    upperBound is chosen as lengthGivenInFunctionSpecification.
                    Thus, also the access buffer[index] is valid.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  FETA JUSTIFICATIONS
 **********************************************************************************************************************/

/* FETA_JUSTIFICATION_BEGIN
  \ID FETA_SSA_FVM_MONOTONIC_FOR_LOOP_UP_WITH_UPPER_BOUND_FROM_EXT_BUFFER
    \DESCRIPTION  According to FETA loop may not terminate in function
                  - Ssa_FvM_GetTxFreshnessTruncData()
    \COUNTERMEASURE \N The here applied for loop uses as upper bound a parameter that is passed by a pointer to a
                       buffer from external as length information for a buffer that is also passed.
                       According the SMI-16 length and buffer need to be valid and consistent. This implies that the
                       length remains unchanged during loop execution. The loop's type of the counter variable is
                       appropriate for the loop's type of upper bound variable and is incremented once within
                       each single loop (strictly monotonically increasing).

  \ID FETA_SSA_FVM_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_OF_RESTRICTED_MAX_VALUE
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - FvM_CopyVarToArray()
    \COUNTERMEASURE \N The here applied for loop uses a variable as upper bound that remains unchanged during loop execution and that never exceeds 64.
                       The loop's type of the counter variable is appropriate for the loop's maximum value of upper bound and is incremented once by value 8
                       within each single loop (strictly monotonically increasing) until it reaches a value that makes the loop stop without any occurrences
                       of overflows due to the restricted maximum value of upper bound.
FETA_JUSTIFICATION_END */
