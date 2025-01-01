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
/*!        \file  Ssa_TimeM.c
 *        \brief  Time Manager of the Standard Security Architecture (Ssa).
 *
 *      \details  The Time Manager provides services to provide the time to the ECU.
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
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
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
 * Ssa_PowernetMgmtStateType
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
 * TimeM_CompareOperatorType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * TimeM_RealTimeChangeReasonType
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
 * DTC_0xD12081
 *   Set an Event Status to failed if for the configured timespan tick-count messages were received and authenticated but not accepted due to turning back beyond the allowed amount.
 *      Connect to corresponding event of Dem.
 *
 * DTC_0xD12087
 *   Set an Event Status to failed if for the configured timespan tick-count messages were received but could not be authenticated or were not received at all.
 *      Connect to corresponding event of Dem.
 *
 * DataServices_DID_018A_TickCount
 *   Reads local tick-count and passes it to given data parameter.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_DID_018D_Real_Time_Offset
 *   Reads the date and time reference of the real-time offset and passes it to given data parameter.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_DID_018D_TickCount
 *   Reads the tick-count offset of the real-time offset and passes it to given data parameter.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime
 *   Reads the secured date and time and passes it in GeneralizedTime format to given data parameter.
 *      Connect to corresponding Dcm port.
 *
 * NvMService_RealTimeOffset
 *   Controlling the NvM Block which stores the real time offset.
 *      Connect to NvM block storing the real time offset.
 *
 * NvMService_TickCount
 *   Controlling the NvM Block which stores the tick count.
 *      Connect to NvM block storing the tick count.
 *
 * ReceiveChangeTickCountEvent
 *   Configuration Variant(s): Not in VSM.
 *
 * ReceiveRealTimeOffsetCorrectionRequest
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_TimeM_OperationMode
 *   The operation of the TimeM main function is controlled by the modes set at this service port.
 *      E.g. connect to BswM and create appropriate rule.
 *
 * TimeM_Com_ReceiveRealTimeOffset
 *   Configuration Variant(s): Not in VSM.
 *
 * TimeM_Com_SendRealTimeOffset
 *   Configuration Variant(s): VSM and GW only.
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
 * Ssa_TimeM_Com_ReceiveRealTimeOffset
 *   Update the local offset value.
 *      
 *      Function is called when the Offset signal is received. The offset signal is sent with the VSM broadcast message.
 *      Configuration Variant(s): Not in VSM.
 *
 * Ssa_TimeM_Init
 *   Init function of TimeM
 *
 * Ssa_TimeM_Mainfunction
 *   Is called cyclically every 10 milliseconds.
 *      Updates the Local Time Base.
 *      
 *      VSM:
 *      When the Time Base signal should be sent:
 *      Get RTC time, update Local Time Base and call Com_SendSignal.
 *      
 *
 * Ssa_TimeM_ReceiveChangeTickCountEvent
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_TimeM_ReceiveRealTimeOffsetCorrectionRequest
 *   Configuration Variant(s): VSM only.
 *
 *
 * Per-Instance Memory:
 * ====================
 * TickCount
 *   Stores the current TickCount.
 *
 * TickCountMirror
 *   Used as mirror before writing with NvM.
 *
 * TickCountValueToBeStoredToNvM
 *   This value is used to store the tickcount at the time the NvM WriteRequest is set.
 *
 *********************************************************************************************************************/

#include "Rte_Ssa_TimeM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Ssa_Cfg.h"
#include "Ssa_Utils.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_TimeM_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
   include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#if !defined (SSA_TIMEM_LOCAL)                                  /* COV_SSA_LOCAL */
# define SSA_TIMEM_LOCAL                                              static
#endif

#if !defined (SSA_TIMEM_LOCAL_INLINE)                           /* COV_SSA_LOCAL_INLINE */
# define SSA_TIMEM_LOCAL_INLINE                                       LOCAL_INLINE
#endif

#if !defined (TIMEM_NVAMBLOCK_STATUS_RESTORED_TO_DEFAULT)   /* COV_SSA_OVERWRITEABLE TX */
# define TIMEM_NVRAMBLOCK_STATUS_RESTORED_TO_DEFAULT                  NVM_REQ_RESTORED_FROM_ROM
#endif

/* The maximum reachable tick count for the local time base (using a 40bit counter) is 2n-2 (i.e. 0xffff ... fffe) (SSA-IS-61). */
#define TIMEM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL                      (0xFFFFFFFFFEULL)

/*! The start offset time resp. the cycle time for sending the real-time offset broadcast message.
 *  Given as number of main function cycles. */
#define TIMEM_RTO_MSG_START_OFFSET_TIME                               (300u)     /**< The first RTO broadcast message is sent 3s after startup. */
#define TIMEM_RTO_MSG_CYCLE_TIME                                      (1000u)    /**< The RTO broadcast message is sent periodically every 10s. */

/*! TimeM Real-Time Offset Write Block States. */
#define TIMEM_REAL_TIME_OFFSET_WRITE_BLOCK_STATE_IDLE                 (0u)  /**< Idle. */
#define TIMEM_REAL_TIME_OFFSET_WRITE_BLOCK_STATE_WRITE_REQUESTED      (1u)  /**< The writing of the real time offset NVRam block has been requested. */

/*! Origin of new time used for writing the security log event "Change of tick-count or date and time. */
#define TIMEM_ORIGIN_NEW_TIME_TICKCOUNT_NVM_DEFAULT                   ((uint8)0x00u)
#define TIMEM_ORIGIN_NEW_TIME_REALTIME_OFFSET_NVM_DEFAULT             ((uint8)0x01u)
#define TIMEM_ORIGIN_NEW_TIME_TICKCOUNT_BROADCAST                     ((uint8)0x02u)
#define TIMEM_ORIGIN_NEW_TIME_REALTIME_OFFSET_BROADCAST               ((uint8)0x03u)
#define TIMEM_ORIGIN_NEW_TIME_REALTIME_SET_BASED_ON_NOTBEFORE         ((uint8)0x04u)
#define TIMEM_ORIGIN_NEW_TIME_REALTIME_SET_BASED_ON_NONCE             ((uint8)0x05u)
#define TIMEM_ORIGIN_NEW_TIME_INITIALIZE_BY_ROUTINE_CONTROL           ((uint8)0x06u)
#define TIMEM_ORIGIN_NEW_TIME_TICKCOUNT_BROADCAST_ATTEMPT_TURN_BACK   ((uint8)0x07u)

/*! Time set to past value used for direction of time change when writing the security log event
 *  "Change of tick-count or date and time. */
#define TIMEM_TIME_SET_TO_PAST                                        ((uint8)0x80u)

#define TIMEM_SIZEOF_TICKCOUNT_IN_BYTES                               (5u)

/*! The number of days in February when being in a leap year. */
#define TIMEM_DAYS_IN_FEBRUARY_LEAPYEAR                               (29u)

/*! TimeM NVM Write states. */
#define TIMEM_NVM_WRITE_STATE_IDLE                                    (0u)
#define TIMEM_NVM_WRITE_STATE_START                                   (1u)
#define TIMEM_NVM_WRITE_STATE_PENDING                                 (2u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

#define TimeM_Minutes2Seconds(minutes)                                ((minutes)*60u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define TimeM_Hours2Minutes(hours)                                    ((hours)*60u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define TimeM_Days2Hours(days)                                        ((days)*24u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define TimeM_Seconds2Ticks(seconds)                                  ((seconds)*100u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define TimeM_Minutes2Ticks(minutes)                                  (TimeM_Seconds2Ticks(TimeM_Minutes2Seconds((minutes)))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define TimeM_Hours2Ticks(hours)                                      (TimeM_Minutes2Ticks(TimeM_Hours2Minutes((hours)))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define TimeM_Days2Ticks(days)                                        (TimeM_Hours2Ticks(TimeM_Days2Hours((days)))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define TimeM_IsRealTimeOffSetValid(realTimeOffset)                   ((TimeM_IsDateTimeValid(&((realTimeOffset).dateTimeReference))) && ((realTimeOffset).tickCountOffset <= TIMEM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* The following compile time assertions ensure the sizes of data types used within the TimeM submodule
 * when calling RTE APIs expecting these data types.
 * The assertions ensure that the size of these data types is consistent with respective buffer lengths defined in the Ssa.
 * For ASIL-D, the vector code analyzer checks the same conditions within the TimeM_Init() function. */
/* PRQA S 3205, 3493 2 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
Ssa_CompileTimeAssert(sizeof(Ssa_Data5ByteType) == 5u, InvalidSizeOf_Ssa_Data5ByteType); /*lint !e506 */
Ssa_CompileTimeAssert(sizeof(Ssa_Data12ByteType) == 12u, InvalidSizeOf_Ssa_Data12ByteType); /*lint !e506 */

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define Ssa_TimeM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/*! Cycle counter used for the periodic sending of the secured real-time offset broadcast message. */
SSA_TIMEM_LOCAL VAR(uint16, Ssa_TimeM_VAR_NOINIT) TimeM_CountDownRealTimeOffsetMsgCycle;
#endif

SSA_TIMEM_LOCAL VAR(boolean, Ssa_TimeM_VAR_NOINIT) TimeM_RealTimeOffsetNvmWriteRequested;
/*! The state of writing the real-time offset NVRam block. */
SSA_TIMEM_LOCAL VAR(uint8, Ssa_TimeM_VAR_NOINIT) TimeM_RealTimeOffsetNvmWriteState;
SSA_TIMEM_LOCAL VAR(boolean, Ssa_TimeM_VAR_NOINIT) TimeM_TickCountNvmWriteRequested;
/*! The state of writing the tick-count NVRam block. */
SSA_TIMEM_LOCAL VAR(uint8, Ssa_TimeM_VAR_NOINIT) TimeM_TickCountNvmWriteState;

/*! Storing the tick-count offset of the real-time offset for the duration of service DID_018D_RealTimeOffset. */
SSA_TIMEM_LOCAL VAR(Ssa_Data5ByteType, Ssa_TimeM_VAR_NOINIT) TimeM_TickCountOffsetDiag;   /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */

#define Ssa_TimeM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define Ssa_TimeM_START_SEC_CONST_UNSPECIFIED
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Array containing the number of days per each month. */
SSA_TIMEM_LOCAL CONST(uint8, Ssa_TimeM_CONST) TimeM_DaysNonLeapYear[12] = { 31u, 28u, 31u, 30u, 31u, 30u, 31u, 31u, 30u, 31u, 30u, 31u };   /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */

#define Ssa_TimeM_STOP_SEC_CONST_UNSPECIFIED
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define Ssa_TimeM_START_SEC_CODE
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TimeM_Copy5BytesToArray()
 *********************************************************************************************************************/
/*!
 * \brief       Copies 5 lowest bytes of given 64 bit variable to a 5-byte array.
 * \details     -
 * \param[in]   value   Buffer containing the value that shall be copied.
 * \param[out]  buffer  Pointer to the byte array where the variable value shall be stored to. The buffer must be
 *                      of size 5 bytes.
 * \pre         buffer must be a valid pointer and reference a buffer of at least 5 bytes.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec        requires $lengthOf(buffer) >= 5;                                                               \endspec
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_Copy5BytesToArray(uint64 value, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) buffer);

/**********************************************************************************************************************
 *  TimeM_SetLocalTimeBase()
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
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_SetLocalTimeBase(uint64 timeBase);

/**********************************************************************************************************************
 *  TimeM_GetLocalTimeBase()
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
SSA_TIMEM_LOCAL_INLINE FUNC(uint64, Ssa_TimeM_CODE) TimeM_GetLocalTimeBase(void);

/**********************************************************************************************************************
 *  TimeM_SetRealTimeOffset()
 *********************************************************************************************************************/
/*!
 * \brief       Sets the real-time offset.
 * \details     This function sets the real-time offset data that consists of an offset value in seconds and an
 *              absolute date/time information.
 * \param[in]   realTimeOffset A pointer to the memory location where the real-time offset data is stored.
 * \pre         realTimeOffset must be a valid pointer.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_SetRealTimeOffset(P2CONST(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffset);

/**********************************************************************************************************************
 *  TimeM_GetRealTimeOffset()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the real-time offset.
 * \details     This function provides the real-time offset data that consists of an offset value in seconds and an
 *              absolute date/time information.
 * \param[out]  realTimeOffset  A pointer to the memory location where the real time offset data shall be stored.
 * \pre         realTimeOffset must be a valid pointer.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_GetRealTimeOffset(P2VAR(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffset);

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
 *  TimeM_PackOffsetBroadcastMessage()
 *********************************************************************************************************************/
/*!
 * \brief       Packs the real time offset broadcast message.
 * \details     This function packs the real time offset data into a byte stream for broadcasting.
 * \param[out]  packedData    A pointer to the memory location where the packed data shall be stored.
 * \pre         packedData must be a valid pointer and reference a buffer of at least 12 bytes.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_PackOffsetBroadcastMessage(P2VAR(uint8, AUTOMATIC, AUTOMATIC) packedData);
#endif

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_NORMAL) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
 *  TimeM_UnpackOffsetBroadcastMessage()
 *********************************************************************************************************************/
/*!
 * \brief       Unpacks the real time offset broadcast message.
 * \details     This function unpacks the broadcasted byte stream into the real time offset data structure.
 * \param[in]   packedData      A pointer to the memory location where the packed data is stored.
 * \param[out]  realTimeOffset  A pointer to the memory location where the real time offset data shall be stored.
 * \pre         realTimeOffset must be a valid pointer.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_UnpackOffsetBroadcastMessage(
  P2CONST(uint8, AUTOMATIC, AUTOMATIC) packedData,
  P2VAR(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffset);
#endif

/**********************************************************************************************************************
 *  TimeM_GetDaysOfMonth()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the number of days for the given month.
 * \details     This function shall be used to retrieve the number of the given month depending on the year.
 * \param[in]   month        The month. Range [0:11].
 * \param[in]   year         The year. Range [0:65535].
 * \return      The number of days of the month.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL_INLINE FUNC(uint8, Ssa_TimeM_CODE) TimeM_GetDaysOfMonth(uint8 month, uint16 year);

/**********************************************************************************************************************
 *  TimeM_CalcTickCountDifference()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the number ticks between two dates.
 * \details     This function shall be used to retrieve the time difference in ticks between lowDateTime and highDateTime.
 * \param[in]   lowDateTime     Holds a pointer to the memory location where date/time information is stored.
 * \param[in]   highDateTime    Holds a pointer to the memory location where date/time information is stored.
 * \param[out]  tickDifference  Number of ticks Range [0:4].
 * \pre         All provided pointers must be valid.
 *              The buffer referenced by tickDifference must provide at least 5 bytes.
 *              lowDateTime needs to be less than highDateTime.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL FUNC(void, Ssa_TimeM_CODE) TimeM_CalcTickCountDifference(
  P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) lowDateTime,
  P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) highDateTime,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) tickDifference);

/**********************************************************************************************************************
 *  TimeM_CalcRealTime()
 *********************************************************************************************************************/
/*!
 * \brief       Calculates the real time from the local time base and from the date/time calibration information.
 * \details     This function shall be used to calculate the real time from the local time base and from the
 *              date-time calibration information.
 * \param[in]   localTimeBase   The local time base.
 * \param[in]   realTimeOffset  Holds a pointer to the memory location where the real time offset information
 *                              is stored.
 * \param[out]  dateTimeOut     Holds a pointer to the memory location where the calculated real time information
 *                              shall be stored.
 * \return      RTE_E_OK:   request successful
 *              else:       request failed
 * \pre         All provided pointers must be valid.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL FUNC(Std_ReturnType, Ssa_TimeM_CODE) TimeM_CalcRealTime(
  uint64 localTimeBase,
  P2CONST(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffset,
  P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) dateTimeOut);

/**********************************************************************************************************************
 *  TimeM_IsDateTimeValid()
 *********************************************************************************************************************/
/*!
 * \brief       Checks whether the format of the date time input data is valid or not.
 * \details     This functions checks whether the format of the input date time data is valid. It does not check
 *              whether the date time information is plausible.
 * \param[in]   dateTime  Holds a pointer to the memory location where date/time information is stored.
 * \return      TRUE      The format of the date time data is valid.
 *              FALSE     The format of the date time data is NOT valid.
 * \pre         dateTime must be a valid pointer.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL_INLINE FUNC(boolean, Ssa_TimeM_CODE) TimeM_IsDateTimeValid(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) dateTime);

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
 *  TimeM_BroadcastRealTimeOffset()
 *********************************************************************************************************************/
/*!
 * \brief       Broadcasts the real-time offset.
 * \details     -
 * \return      RTE_E_OK          Request successful.
 *              E_NOT_OK          Request failed.
 *              RTE_E_UNCONNECTED Sub-call failed due to missing RTE connection.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_TimeM_CODE) TimeM_BroadcastRealTimeOffset(void);
#endif

/**********************************************************************************************************************
 *  TimeM_HandleRealTimeOffset()
 *********************************************************************************************************************/
 /*!
  * \brief       Writes the real-time offset NVRam block if requested.
  * \details     -
  * \pre         -
  * \context     TASK
  * \reentrant   FALSE
  * \synchronous TRUE
  */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_HandleRealTimeOffset(void);

/**********************************************************************************************************************
 *  TimeM_HandleTickCount()
 *********************************************************************************************************************/
 /*!
  * \brief       Writes the tick-count NVRam block if requested, else it sets
                 the RAM block status in order to mark the RAM block as changed.
  * \details     -
  * \pre         -
  * \context     TASK
  * \reentrant   FALSE
  * \synchronous TRUE
  */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_HandleTickCount(void);

/**********************************************************************************************************************
 *  TimeM_HandleNvm()
 *********************************************************************************************************************/
/*!
 * \brief       Writes the real-time offset NVRam block and the tick-count NVRam block if requested, else it sets
                the RAM block status in order to mark the RAM block as changed.
 * \details     This function calls TimeM_HandleRealTimeOffset() and TimeM_HandleTickCount().
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_HandleNvm(void);

/**********************************************************************************************************************
 *  TimeM_FormatAccordingToGeneralizedTime()
 *********************************************************************************************************************/
/*!
 * \brief       Transforms the format of the provided dateTime to the GeneralizedTime format.
 * \details     -
 * \param[in]   dateTime        Holds a pointer to the memory location where date/time information is stored.
 * \param[out]  generalizedTime Holds a pointer to the memory location where reformatted date/time information is stored.
 *                              The buffer size must be equal or greater than 15 bytes.
 * \pre         All provided pointers must be valid.
 *              The buffer referenced by generalizedTime must provide at least 15 bytes.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL FUNC(void, Ssa_TimeM_CODE) TimeM_FormatAsGeneralizedTime(
  P2CONST(TimeM_DateTimeType, AUTOMATIC, AUTOMATIC) dateTime,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) generalizedTime);

/**********************************************************************************************************************
*  TimeM_LogTimeChange()
*********************************************************************************************************************/
/*!
 * \brief       Writes a security log entry for a time change.
 * \details     -
 * \param[in]   realTimeOffsetOld       Stored real time offset. Value must be valid.
 * \param[in]   localTickCountOld       Stored localtickCount.
 * \param[in]   realTime                Pointer to the memory location which stores the current real-time.
 * \param[in]   contextDateTimeChange    Context in which data/time is changed.
 * \param[in]   logTickCountDiff        Define if tick-count diff shall be calculated and logged
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK otherwise.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_TIMEM_LOCAL FUNC(Std_ReturnType, Ssa_TimeM_CODE) TimeM_LogTimeChange(
  P2CONST(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffsetOld,
  uint64 localTickCountOld,
  P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) realTime,
  uint8 contextDateTimeChange,
  boolean logTickCountDiff);

#define Ssa_TimeM_STOP_SEC_CODE
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
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
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...254] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...64] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 *   DCM_FORCE_RCRRP_NOT_OK (64U)
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * RightsM_AuthenticationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   RIGHTSM_UNAUTHENTICATED (0U)
 *   RIGHTSM_AUTHENTICATED (1U)
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
 * Ssa_PowernetMgmtStateType: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_PN14_TDP_SW_STAT_CLS (0U)
 *   I_C03_PN14_TDP_SW_STAT_PRE_RESET (1U)
 *   I_C03_PN14_TDP_SW_STAT_RESET (2U)
 *   I_C03_PN14_TDP_SW_STAT_PRE_OPN (3U)
 *   I_C03_PN14_TDP_SW_STAT_OPN (4U)
 *   I_C03_PN14_TDP_SW_STAT_SNA (7U)
 * Ssa_TickCountSyncStateType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED (0U)
 *   SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_MASTER (1U)
 *   SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM (2U)
 * TimeM_CompareOperatorType: Enumeration of integer in interval [0...255] with enumerators
 *   TIMEM_IS_GREATER (0U)
 *   TIMEM_IS_LESS (1U)
 * TimeM_RealTimeChangeReasonType: Enumeration of integer in interval [0...255] with enumerators
 *   TIMEM_REALTIMECHANGEREASON_NOTBEFORE (0U)
 *   TIMEM_REALTIMECHANGEREASON_NONCE (1U)
 *
 * Array Types:
 * ============
 * Dcm_Data15ByteType: Array with 15 element(s) of type uint8
 * Dcm_Data5ByteType: Array with 5 element(s) of type uint8
 * Dcm_Data6ByteType: Array with 6 element(s) of type uint8
 * Ssa_Data12ByteType: Array with 12 element(s) of type uint8
 * Ssa_Data5ByteType: Array with 5 element(s) of type uint8
 * Ssa_Data7ByteType: Array with 7 element(s) of type uint8
 *
 * Record Types:
 * =============
 * Ssa_LocalTickCountAndSyncStatusType: Record with elements
 *   LocalTickCount of type uint64
 *   SyncStatus of type Ssa_TickCountSyncStateType
 * TimeM_DateTimeType: Record with elements
 *   year of type uint16
 *   month of type uint8
 *   day of type uint8
 *   hour of type uint8
 *   minute of type uint8
 *   second of type uint8
 * TimeM_RealTimeOffsetType: Record with elements
 *   tickCountOffset of type uint64
 *   dateTimeReference of type TimeM_DateTimeType
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   uint64 *Rte_Pim_TickCount(void)
 *   uint64 *Rte_Pim_TickCountMirror(void)
 *   uint64 *Rte_Pim_TickCountValueToBeStoredToNvM(void)
 *   TimeM_RealTimeOffsetType *Rte_Pim_RealTimeOffset(void)
 *   TimeM_RealTimeOffsetType *Rte_Pim_RealTimeOffsetMirror(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   uint64 Rte_CData_NvM_TimeM_LocalTimeBase_DefaultValue(void)
 *   TimeM_RealTimeOffsetType *Rte_CData_NvM_TimeM_RealTimeOffset_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define Ssa_TimeM_START_SEC_CODE
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( SSA_ECU_TYPE != SSA_ECU_TYPE_VSM )

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_Com_ReceiveRealTimeOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <realTimeOffset> of PortPrototype <TimeM_Com_ReceiveRealTimeOffset>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_TimeM_Com_ReceiveRealTimeOffset_realTimeOffset(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data12ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, const uint8 *deltaTimeChange)
 *     Argument deltaTimeChange: uint8* is of type Ssa_Data5ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_Com_ReceiveRealTimeOffset_doc
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
  */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_Com_ReceiveRealTimeOffset(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_Com_ReceiveRealTimeOffset
 *********************************************************************************************************************/
  Ssa_Data12ByteType realTimeOffsetNotified;

  /* #10 Read the notified real time offset value. */
  if (RTE_E_OK == Rte_Read_TimeM_Com_ReceiveRealTimeOffset_realTimeOffset((P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))realTimeOffsetNotified))
  {
    TimeM_RealTimeOffsetType realTimeOffset, realTimeOffsetStored;

    /* #20 Unpack the received broadcast message to get new realTimeOffset. */
    TimeM_UnpackOffsetBroadcastMessage(realTimeOffsetNotified, &realTimeOffset);

    /* #30 Get stored real time offset. */
    TimeM_GetRealTimeOffset(&realTimeOffsetStored);

    /* #40 Check if the real-time offset has changed. */
    if ((realTimeOffsetStored.tickCountOffset != realTimeOffset.tickCountOffset)
      || (realTimeOffsetStored.dateTimeReference.second != realTimeOffset.dateTimeReference.second)
      || (realTimeOffsetStored.dateTimeReference.minute != realTimeOffset.dateTimeReference.minute)
      || (realTimeOffsetStored.dateTimeReference.hour != realTimeOffset.dateTimeReference.hour)
      || (realTimeOffsetStored.dateTimeReference.day != realTimeOffset.dateTimeReference.day)
      || (realTimeOffsetStored.dateTimeReference.month != realTimeOffset.dateTimeReference.month)
      || (realTimeOffsetStored.dateTimeReference.year != realTimeOffset.dateTimeReference.year))
    {
      /* #50 Consistency check of realTimeOffsetStored and realTimeOffset. */
      if (TimeM_IsRealTimeOffSetValid(realTimeOffset))
      {
        uint8 contextDateTimeChange = TIMEM_ORIGIN_NEW_TIME_REALTIME_OFFSET_BROADCAST;
        TimeM_DateTimeType realTime = { 0 };
        uint64 tickCountDummy;
        boolean logTickCountDiff = FALSE;

        /* #60 Set the new real-time offset value. */
        TimeM_SetRealTimeOffset(&realTimeOffset);

        /* #70 Request for writing the real-time offset NVRAm block and the tick-count NVRam block in the main function. */
        Rte_Enter_TimeM_ExclusiveArea();
        TimeM_RealTimeOffsetNvmWriteRequested = TRUE;
        TimeM_TickCountNvmWriteRequested = TRUE;
        /* Store current TickCount that shall be written to NvM */
        *Rte_Pim_TickCountValueToBeStoredToNvM() = *Rte_Pim_TickCount();
        Rte_Exit_TimeM_ExclusiveArea();

        /* #80 For logging, a tick count value greater than or equal to both offset tick counts is needed. */
        tickCountDummy = (realTimeOffset.tickCountOffset > realTimeOffsetStored.tickCountOffset) ? realTimeOffset.tickCountOffset : realTimeOffsetStored.tickCountOffset;

        /* #90 Calculate new real-time (used for logging the tick-count difference) only if old real-time offset is valid. */
        if (TimeM_IsRealTimeOffSetValid(realTimeOffsetStored))
        {
          logTickCountDiff = TRUE;

          /* #100 Calculate new real-time. */
          /* The calculation of the tickCountDummy ensures that CalcRealTime does not fail. */
          (void)TimeM_CalcRealTime(tickCountDummy, &realTimeOffset, (P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTime);
        }

        /* #110 Write the security log event "change tick-count or date and time". */
        /* The consistency checks above (50) and the calculation of the tickCountDummy ensure that LogTimeChange does not fail. */
        (void)TimeM_LogTimeChange(
          &realTimeOffsetStored,
          tickCountDummy,
          (P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTime,
          contextDateTimeChange,
          logTickCountDiff);
      }
    }
  }
  /* PRQA S 6050 4 */ /* MD_MSR_STCAL */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif /* ( SSA_ECU_TYPE != SSA_ECU_TYPE_VSM ) */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_018A_TickCount>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018A_TickCount_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018A_TickCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018A_TickCount_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_018A_TickCount>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   Ssa_TickCountSyncStateType Rte_IrvRead_Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData_TimeM_IrvTickCountSyncState(void)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data6ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018A_TickCount_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018A_TickCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data6ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018A_TickCount_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint64 localTimeBase;

    /* #10 Get current local tick count. */
    localTimeBase = TimeM_GetLocalTimeBase();

#if ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM )
    /* #20 If ECU type is VSM set the tick-count synchronization flag always to true. */
    Data[0] = 0x80u;
#else
    switch (Rte_IrvRead_Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData_TimeM_IrvTickCountSyncState()) {
    case SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM:
      Data[0] = 0x80u;
      break;
    case SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_MASTER:
      Data[0] = 0x40u;
      break;
    default:
      Data[0] = 0x00u;
      break;
    }
#endif
    /* #40 Fill the local tick-count byte-by-byte into the output buffer (high byte first). */
    TimeM_Copy5BytesToArray(localTimeBase, &Data[1]);
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_018D_Real_Time_Offset>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018D_Real_Time_Offset_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018D_Real_Time_Offset_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018D_Real_Time_Offset_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_018D_Real_Time_Offset>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018D_Real_Time_Offset_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018D_Real_Time_Offset_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data15ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018D_Real_Time_Offset_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {

    TimeM_RealTimeOffsetType realTimeOffset;

    /* #10 Read the stored real-time offset. */
    TimeM_GetRealTimeOffset(&realTimeOffset);

    /* #20 Change format of the dataTimeReference to GeneralizedTime and output it. */
    TimeM_FormatAsGeneralizedTime(&realTimeOffset.dateTimeReference, Data);

    /* #30 Store the tick-count offset byte-by-byte (high byte first) in a static buffer for data consistency reasons
     *     during execution of the complete diagnostic service. */
    TimeM_Copy5BytesToArray(realTimeOffset.tickCountOffset, TimeM_TickCountOffsetDiag);
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_018D_TickCount>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018D_TickCount_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018D_TickCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018D_TickCount_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_018D_TickCount>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018D_TickCount_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018D_TickCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data5ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018D_TickCount_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {

    /* #10 Fill the previously stored tick-count into the output buffer. */
    Data[0] = TimeM_TickCountOffsetDiag[0];
    Data[1] = TimeM_TickCountOffsetDiag[1];
    Data[2] = TimeM_TickCountOffsetDiag[2];
    Data[3] = TimeM_TickCountOffsetDiag[3];
    Data[4] = TimeM_TickCountOffsetDiag[4];
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_DCM_E_PENDING
 *   RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_DCM_E_PENDING
 *   RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data15ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    TimeM_DateTimeType realTime = { 0u };

    /* #10 Get the current real-time. */
    /* The function Ssa_TimeM_RealTime_Get() is reentrant. */
    retVal = Ssa_TimeM_RealTime_Get((P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTime);

    if (retVal == RTE_E_OK)
    {
      /* #20 Output format according to Generalized Time: YYYYMMDDHHMMSSZ. */
      TimeM_FormatAsGeneralizedTime(&realTime, Data);
    }
  }
  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Ssa_TimeM_Init_TimeM_IrvTickCountSyncState(Ssa_TickCountSyncStateType data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_InitialTickCount_Set(uint64 tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_InitialTickCount_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, const uint8 *deltaTimeChange)
 *     Argument deltaTimeChange: uint8* is of type Ssa_Data5ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_RealTimeOffset_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_TickCount_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_Init_doc
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

FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_Init
 *********************************************************************************************************************/

  NvM_RequestResultType nvmReqRes = NVM_REQ_NOT_OK;
  const Ssa_Data5ByteType defaultLogEntryData = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
  /* #10 Get the error status of the tick-count NVRam block. */
  if (Rte_Call_NvMService_TickCount_GetErrorStatus(&nvmReqRes) == RTE_E_OK)
  {
    /* #20 If the NVRAM block status indicates that the RAM block has be restored to default
     *     write the security log informing that the default value is set for the local tick-count. */
    if (nvmReqRes == TIMEM_NVRAMBLOCK_STATUS_RESTORED_TO_DEFAULT)
    {
      /* The default value is loaded. */
      /* Write security log. */
      (void)Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(TIMEM_ORIGIN_NEW_TIME_TICKCOUNT_NVM_DEFAULT | TIMEM_TIME_SET_TO_PAST, defaultLogEntryData);
    }
  }
  /* #30 Get the error status of the real-time offset NVRam block. */
  if (Rte_Call_NvMService_RealTimeOffset_GetErrorStatus(&nvmReqRes) == RTE_E_OK)
  {
    /* #40 If the NVRAM block status indicates that the RAM block has be restored to default
     *     write the security log informing that the default value is set for the real-time offset. */
    if (nvmReqRes == TIMEM_NVRAMBLOCK_STATUS_RESTORED_TO_DEFAULT)
    {
      /* The default value is loaded. */
      /* Write security log. */
      (void)Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(TIMEM_ORIGIN_NEW_TIME_REALTIME_OFFSET_NVM_DEFAULT | TIMEM_TIME_SET_TO_PAST, defaultLogEntryData);
    }
  }

  /* #50 Set the local tick-count to the real-time tick-count offset if it is smaller. */
  if (*Rte_Pim_TickCount() < Rte_Pim_RealTimeOffset()->tickCountOffset)
  {
    *Rte_Pim_TickCount() = Rte_Pim_RealTimeOffset()->tickCountOffset;
  }

  /* #60 If the RealTimeOffSet is not valid, set it to the default values. */
  if (!TimeM_IsRealTimeOffSetValid(*Rte_Pim_RealTimeOffset()))
  {
    /* If loaded value is not valid, set to default value. */
    Rte_Pim_RealTimeOffset()->dateTimeReference = Rte_CData_NvM_TimeM_RealTimeOffset_DefaultValue()->dateTimeReference;
    Rte_Pim_RealTimeOffset()->tickCountOffset = Rte_CData_NvM_TimeM_RealTimeOffset_DefaultValue()->tickCountOffset;
  }

  /* #70 If the TickCount is not valid, set it to the default value. */
  if (*Rte_Pim_TickCount() > TIMEM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL)
  {
    /* If set value is not valid, set to default value. */
    *Rte_Pim_TickCount() = Rte_CData_NvM_TimeM_LocalTimeBase_DefaultValue();
  }

  /* #80 Set tick-count to FvM */
  (void)Rte_Call_FvM_InitialTickCount_Set(*Rte_Pim_TickCount());

  /* #90  Initialize all static variables to reasonable values. */
  TimeM_RealTimeOffsetNvmWriteRequested = FALSE;
  TimeM_RealTimeOffsetNvmWriteState = TIMEM_NVM_WRITE_STATE_IDLE;
  TimeM_TickCountNvmWriteRequested = FALSE;
  TimeM_TickCountNvmWriteState = TIMEM_NVM_WRITE_STATE_IDLE;

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
  /* #100 If ECU type is VSM, initialize the counter used for sending the RTO message with the start offset. */
  TimeM_CountDownRealTimeOffsetMsgCycle = TIMEM_RTO_MSG_START_OFFSET_TIME - 1u;
#endif /* ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)) */

  /* Ensure type sizes once for the TimeM submodule which calls RTE APIs expecting these data types:
   * Ssa_Data5ByteType must be an array with 5 element(s) of type uint8
   * Ssa_Data12ByteType must be an array with 12 element(s) of type uint8 */
  /*@ assert sizeof(Ssa_Data5ByteType) == 5u; */
  /*@ assert sizeof(Ssa_Data12ByteType) == 12u; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_Mainfunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReceiveLocalTickCountAndSyncStatus_Data(Ssa_LocalTickCountAndSyncStatusType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_TimeM_Com_SendRealTimeOffset_realTimeOffset(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data12ByteType
 *
 * Mode Interfaces:
 * ================
 *   Ssa_OperationModeType Rte_Mode_Ssa_TimeM_OperationMode_Mode(void)
 *   Modes of Rte_ModeType_Ssa_OperationMode:
 *   - RTE_MODE_Ssa_OperationMode_SSA_ACTIVE
 *   - RTE_MODE_Ssa_OperationMode_SSA_INACTIVE
 *   - RTE_TRANSITION_Ssa_OperationMode
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_Ssa_TimeM_Mainfunction_TimeM_IrvTickCountSyncState(Ssa_TickCountSyncStateType data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_RealTimeOffset_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_RealTimeOffset_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_TickCount_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_TickCount_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_TickCount_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_Mainfunction_doc
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
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_Mainfunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_Mainfunction
 *********************************************************************************************************************/

  /* #5 The main loop is in operation only if the operation mode is SSA_ACTIVE. */
  if (Rte_Mode_Ssa_TimeM_OperationMode_Mode() == RTE_MODE_Ssa_OperationMode_SSA_ACTIVE) /* PRQA S 2741 */ /* MD_SSA_CTRLEXPR_ALWAYS_TRUE_OR_ALWAYS_FALSE */ /*lint !e506 */ /* COV_TIMEM_OPMODE_INACTIVE */
  {
    Ssa_LocalTickCountAndSyncStatusType localTickCountAndSyncStatus;
    /* #55 Get tick-count from FvM */
    if (Rte_Read_ReceiveLocalTickCountAndSyncStatus_Data(&localTickCountAndSyncStatus) == RTE_E_OK)
    {
      TimeM_SetLocalTimeBase(localTickCountAndSyncStatus.LocalTickCount);
      Rte_IrvWrite_Ssa_TimeM_Mainfunction_TimeM_IrvTickCountSyncState(localTickCountAndSyncStatus.SyncStatus);
    }

    /* #100 If ECU type is VSM the real-time offset message is sent periodically. */
#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
    /* #110 Use a counter that is decremented each main loop, sent the real-time offset broadcast message when the counter
     *      value is fully counted down and reset the counter after the message is sent. */
    if (TimeM_CountDownRealTimeOffsetMsgCycle > 0u)
    {
      TimeM_CountDownRealTimeOffsetMsgCycle--;
    }
    else
    {
      /* #120 Update local tick-count by RTC and send the time message afterwards. */
      if (TimeM_BroadcastRealTimeOffset() == RTE_E_OK)
      {
        /* #130 After successful sending and before resetting the count down value check for change from startup cycle
        * interval to regular cycle interval. */
        /* Reset count down value. */
        TimeM_CountDownRealTimeOffsetMsgCycle = TIMEM_RTO_MSG_CYCLE_TIME - 1u;
      }
      else
      {
        /* #135 When sending the RTO message failed try again in next main function call. */
      }
    }
#endif /* ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)) */

    /* #140 Check if writing the real-time offset or tick-count NVRam block has been requested. */
    TimeM_HandleNvm();
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_PowernetMgmtStateChanged
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <PN14_DDP_Sw_Stat_ST3> of PortPrototype <Ssa_PowernetMgmtState>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Ssa_PowernetMgmtState_PN14_DDP_Sw_Stat_ST3(Ssa_PowernetMgmtStateType *data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_PowernetMgmtStateChanged_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_PowernetMgmtStateChanged(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_PowernetMgmtStateChanged
 *********************************************************************************************************************/

  Ssa_PowernetMgmtStateType perMgmtState = I_C03_PN14_TDP_SW_STAT_SNA; /* PRQA S 2981 */ /* MD_SSA_REDUNDANT_INITIALIZATION */

  /* #10 Read the signaled power management state. If it is PRE-OPEN request for writing the tick-count NVRam block. */
  (void)Rte_Read_Ssa_PowernetMgmtState_PN14_DDP_Sw_Stat_ST3(&perMgmtState); /* PRQA S 3417, 3426 */ /* MD_SSA_MICROSAR_OS */

  if (perMgmtState == I_C03_PN14_TDP_SW_STAT_PRE_OPN)
  {
    Rte_Enter_TimeM_ExclusiveArea();
    TimeM_TickCountNvmWriteRequested = TRUE;
    /* Store current TickCount that shall be written to NvM */
    *Rte_Pim_TickCountValueToBeStoredToNvM() = *Rte_Pim_TickCount();
    Rte_Exit_TimeM_ExclusiveArea();
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_RealTime_Compare
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Compare> of PortPrototype <TimeM_RealTime>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_RealTime_Compare(const TimeM_DateTimeType *t1, TimeM_CompareOperatorType compareOp, const TimeM_DateTimeType *t2, boolean *result)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TimeM_RealTime_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_RealTime_Compare_doc
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

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_RealTime_Compare(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t1, TimeM_CompareOperatorType compareOp, P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t2, P2VAR(boolean, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_RealTime_Compare (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_TimeM_RealTime_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((t1 == NULL_PTR) || (t2 == NULL_PTR) || (result == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t1Local = t1;
    P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) t2Local = t2;
    retVal = RTE_E_OK;

    switch (compareOp) {
      /* #10 To calculate IS LESS just switch the parameters and calculate IS GREATER. */
    case TIMEM_IS_LESS:
      /* After switching t1 and t2 calculate IS GREATER */
      t1Local = t2;
      t2Local = t1;
      /* Fall through. */

    /* #20 Check for a valid compare operator and return TRUE if first given date and time is after (later than) the second given date and time. */
      /* PRQA S 2003 1 */ /* MD_SSA_SWITCH_FALLTHROUGH */
    case TIMEM_IS_GREATER:
      if (t1Local->year < t2Local->year)
      {
        *result = FALSE;
      }
      else if (t1Local->year > t2Local->year)
      {
        *result = TRUE;
      }
      else if (t1Local->month < t2Local->month)
      {
        *result = FALSE;
      }
      else if (t1Local->month > t2Local->month)
      {
        *result = TRUE;
      }
      else if (t1Local->day < t2Local->day)
      {
        *result = FALSE;
      }
      else if (t1Local->day > t2Local->day)
      {
        *result = TRUE;
      }
      else if (t1Local->hour < t2Local->hour)
      {
        *result = FALSE;
      }
      else if (t1Local->hour > t2Local->hour)
      {
        *result = TRUE;
      }
      else if (t1Local->minute < t2Local->minute)
      {
        *result = FALSE;
      }
      else if (t1Local->minute > t2Local->minute)
      {
        *result = TRUE;
      }
      else if (t1Local->second <= t2Local->second)
      {
        *result = FALSE;
      }
      else
      {
        *result = TRUE;
      }
      break;

    default:
      retVal = E_NOT_OK;
      break;
    }
  }

  return retVal;
  /* PRQA S 6030, 6080 4 */ /* MD_MSR_STCYC, MD_SSA_MIF_CHECK_CONDITIONS */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_RealTime_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <TimeM_RealTime>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_RealTime_Get(TimeM_DateTimeType *realTime)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TimeM_RealTime_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_RealTime_Get_doc
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

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_RealTime_Get(P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) realTime) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_RealTime_Get (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_TimeM_RealTime_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (realTime == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    TimeM_RealTimeOffsetType realTimeOffset;

    /* #10 Get stored real time offset. */
    TimeM_GetRealTimeOffset(&realTimeOffset);

    /* #20 Calculate real time from current local time base and stored real time offset and store it at the given memory location. */
    retVal = TimeM_CalcRealTime(TimeM_GetLocalTimeBase(), &realTimeOffset, realTime);
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_RealTime_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <TimeM_RealTime>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, const uint8 *deltaTimeChange)
 *     Argument deltaTimeChange: uint8* is of type Ssa_Data5ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_RealTime_Set(const TimeM_DateTimeType *realTime, TimeM_RealTimeChangeReasonType changeReason)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TimeM_RealTime_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_RealTime_Set_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_RealTime_Set(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) realTime, TimeM_RealTimeChangeReasonType changeReason) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_RealTime_Set (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_TimeM_RealTime_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (realTime == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    TimeM_RealTimeOffsetType realTimeOffsetStored;
    TimeM_RealTimeOffsetType realTimeOffset;

    /* #10 Get stored real time offset before overwriting it. */
    TimeM_GetRealTimeOffset(&realTimeOffsetStored);

    /* #20 Get current local time base as tick-count offset value.*/
    realTimeOffset.tickCountOffset = TimeM_GetLocalTimeBase();

    /* #30 Consistency check of time data. */
    /* The second check ensures that TimeM_CalcRealTime, called in TimeM_LogTimeChange, does not fail, since this would result in a failure of logging the time change. */
    if ((TimeM_IsDateTimeValid(realTime)) && (realTimeOffset.tickCountOffset <= TIMEM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL))
    {
      uint8 contextDateTimeChange = (changeReason == TIMEM_REALTIMECHANGEREASON_NONCE) ? TIMEM_ORIGIN_NEW_TIME_REALTIME_SET_BASED_ON_NONCE : TIMEM_ORIGIN_NEW_TIME_REALTIME_SET_BASED_ON_NOTBEFORE;
      boolean logTickCountDiff = FALSE;

      retVal = RTE_E_OK;

      /* #40 Set new real time offset. */
      realTimeOffset.dateTimeReference = *realTime;
      TimeM_SetRealTimeOffset(&realTimeOffset);

      /* #50 Request for writing the real-time offset and tick-count NVM blocks. */
      Rte_Enter_TimeM_ExclusiveArea();
      TimeM_RealTimeOffsetNvmWriteRequested = TRUE;
      TimeM_TickCountNvmWriteRequested = TRUE;
      /* Store current TickCount that shall be written to NvM */
      *Rte_Pim_TickCountValueToBeStoredToNvM() = *Rte_Pim_TickCount();
      Rte_Exit_TimeM_ExclusiveArea();

      /* Check if stored real-time offset, that is needed for logging the tick-count difference, is valid. */
      if ((TimeM_IsRealTimeOffSetValid(realTimeOffsetStored)) && (realTimeOffsetStored.tickCountOffset <= realTimeOffset.tickCountOffset))
      {
        logTickCountDiff = TRUE;
      }

      /* #60 Write the security log event "change tick-count or date and time". */
      /* The consistency checks above (30) ensure that LogTimeChange does not fail. */
      (void)TimeM_LogTimeChange(
        &realTimeOffsetStored,
        realTimeOffset.tickCountOffset,
        realTime,
        contextDateTimeChange, logTickCountDiff);
    }
  }

  return retVal;
  /* PRQA S 6050 4 */ /* MD_MSR_STCAL */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if ( SSA_ECU_TYPE != SSA_ECU_TYPE_VSM )

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_ReceiveChangeTickCountEvent
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Id> of PortPrototype <ReceiveChangeTickCountEvent>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReceiveChangeTickCountEvent_Id(Ssa_ChangeTickCountEventIdType *data)
 *   Std_ReturnType Rte_Read_ReceiveChangeTickCountEvent_TickCount(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data5ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, const uint8 *deltaTimeChange)
 *     Argument deltaTimeChange: uint8* is of type Ssa_Data5ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DTC_0xD12081_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *   Std_ReturnType Rte_Call_DTC_0xD12087_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_ReceiveChangeTickCountEvent_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_ReceiveChangeTickCountEvent(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_ReceiveChangeTickCountEvent
 *********************************************************************************************************************/

  Ssa_ChangeTickCountEventIdType eventId = SSA_CHANGETICKCOUNTEVENTID_UNDEFINED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #10 Read the received ChangeTickCountOrDateAndTime event identifier (and if needed the tick-count value). */
  (void)Rte_Read_ReceiveChangeTickCountEvent_Id(&eventId); /* PRQA S 3417, 3426 */ /* MD_SSA_MICROSAR_OS */

  switch (eventId)
  {
  case SSA_CHANGETICKCOUNTEVENTID_ACCEPTED_THRESHOLD_EXCEEDED:
  {
    Ssa_Data5ByteType acceptedTickCount = { 0 };
    /* Read accepted tick-count */
    (void)Rte_Read_ReceiveChangeTickCountEvent_TickCount(acceptedTickCount);
    /* #30 If event is TICKCOUNT_ACCEPTED_THRESHOLD_EXCEEDED write suitable security log. */
    (void)Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(TIMEM_ORIGIN_NEW_TIME_TICKCOUNT_BROADCAST, acceptedTickCount);
  }
  /* fall through */
  case SSA_CHANGETICKCOUNTEVENTID_ACCEPTED:  /* PRQA S 2003 */ /* MD_SSA_SWITCH_FALLTHROUGH */
    /* #20 If event is TICKCOUNT_ACCEPTED set DEM event status for DTC 0x12081 to "passed" */
    (void)Rte_Call_DTC_0xD12081_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    (void)Rte_Call_DTC_0xD12087_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    break;

  case SSA_CHANGETICKCOUNTEVENTID_ERROR_TIMEOUT:
    (void)Rte_Call_DTC_0xD12087_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    break;

  case SSA_CHANGETICKCOUNTEVENTID_REJECTED:
  {
    Ssa_Data5ByteType rejectedTickCount = { 0 };
    /* Read rejected tick-count */
    (void)Rte_Read_ReceiveChangeTickCountEvent_TickCount(rejectedTickCount);
    /* #40 If event is TICKCOUNT_REJECTED write suitable security log and set DEM event status for DTC 0x12081 to "failed". */
    (void)Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(TIMEM_ORIGIN_NEW_TIME_TICKCOUNT_BROADCAST_ATTEMPT_TURN_BACK | TIMEM_TIME_SET_TO_PAST, rejectedTickCount);
    (void)Rte_Call_DTC_0xD12081_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    (void)Rte_Call_DTC_0xD12087_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    break;
  }

  default:
    /* discard event, no action */
    break;
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif /* (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM) */

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_ReceiveRealTimeOffsetCorrectionRequest
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Data> of PortPrototype <ReceiveRealTimeOffsetCorrectionRequest>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReceiveRealTimeOffsetCorrectionRequest_Data(uint64 *data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_ReceiveRealTimeOffsetCorrectionRequest_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_TimeM_CODE) Ssa_TimeM_ReceiveRealTimeOffsetCorrectionRequest(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_ReceiveRealTimeOffsetCorrectionRequest
 *********************************************************************************************************************/
  uint64 correctionValue;

  /* #10 Read the compensation value sent from  FvM. */
  if (Rte_Read_ReceiveRealTimeOffsetCorrectionRequest_Data(&correctionValue) == RTE_E_OK)
  {
    Rte_Enter_TimeM_ExclusiveArea();
    /* #20 Increase the real-time offset tick-count by the received compensation value but restrict it to the allowed
     *     maximum value (as robustness measure). */
    Rte_Pim_RealTimeOffset()->tickCountOffset += correctionValue;

    if (Rte_Pim_RealTimeOffset()->tickCountOffset > TIMEM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL)
    {
      Rte_Pim_RealTimeOffset()->tickCountOffset = TIMEM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL;
    }
    Rte_Exit_TimeM_ExclusiveArea();

    /* #30 Request for writing the real-time offset NVRam block and the tick-count NVRam block. */
    Rte_Enter_TimeM_ExclusiveArea();
    TimeM_RealTimeOffsetNvmWriteRequested = TRUE;
    TimeM_TickCountNvmWriteRequested = TRUE;
    /* Store current TickCount that shall be written to NvM */
    *Rte_Pim_TickCountValueToBeStoredToNvM() = *Rte_Pim_TickCount();
    Rte_Exit_TimeM_ExclusiveArea();
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif /* (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_TickCount_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <TimeM_TickCount>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_TickCount_Get(uint64 *tickCount)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TimeM_TickCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_TickCount_Get_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_TickCount_Get(P2VAR(uint64, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) tickCount) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_TickCount_Get (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_TimeM_TickCount_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (tickCount == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Copy the local tick-count value to the passed memory location. */
    *tickCount = TimeM_GetLocalTimeBase();
    retVal = RTE_E_OK;
  }
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_TimeRawData_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <TimeM_TimeRawData>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_TimeRawData_Get(uint8 *dateTimeOffset, uint8 *tickCountOffset, uint8 *tickCount)
 *     Argument dateTimeOffset: uint8* is of type Ssa_Data7ByteType
 *     Argument tickCountOffset: uint8* is of type Ssa_Data5ByteType
 *     Argument tickCount: uint8* is of type Ssa_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TimeM_TimeRawData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_TimeRawData_Get_doc
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
/*!
 * \spec
 *    requires $lengthOf(dateTimeOffset) >= sizeof(Ssa_Data7ByteType);
 *    requires $lengthOf(tickCountOffset) >= sizeof(Ssa_Data5ByteType);
 *    requires $lengthOf(tickCount) >= sizeof(Ssa_Data5ByteType);
 * \endspec
 */
/* PRQA S 3673 5 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_TimeRawData_Get(P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) dateTimeOffset, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) tickCountOffset, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) tickCount) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_TimeRawData_Get (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_TimeM_TimeRawData_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((dateTimeOffset == NULL_PTR) || (tickCountOffset == NULL_PTR) || (tickCount == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
#if ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM )
    TimeM_RealTimeOffsetType realTimeOffset;
    /* #10 Get stored real time offset. */
    TimeM_GetRealTimeOffset(&realTimeOffset);
    /* #20 Fill the date and time offset buffer. */
    /*@ assert  $lengthOf(dateTimeOffset) >= sizeof(Ssa_Data7ByteType); */ /* VCA_SSA_TIMEM_LENGTH_SPECIFIED_IN_FCT_CALL */
    dateTimeOffset[0] = (uint8)(realTimeOffset.dateTimeReference.year >> 8);
    dateTimeOffset[1] = (uint8)(realTimeOffset.dateTimeReference.year & 0xFFu);
    dateTimeOffset[2] = realTimeOffset.dateTimeReference.month;
    dateTimeOffset[3] = realTimeOffset.dateTimeReference.day;
    dateTimeOffset[4] = realTimeOffset.dateTimeReference.hour;
    dateTimeOffset[5] = realTimeOffset.dateTimeReference.minute;
    dateTimeOffset[6] = realTimeOffset.dateTimeReference.second;
    /* #30 Fill the tick count offset buffer. */
    /*@ assert $lengthOf(tickCountOffset) >= sizeof(Ssa_Data5ByteType); */ /* VCA_SSA_TIMEM_LENGTH_SPECIFIED_IN_FCT_CALL */
    TimeM_Copy5BytesToArray(realTimeOffset.tickCountOffset, tickCountOffset);

    /* #40 Get local tick-count. */
    /* Use already existing local variable. */
    realTimeOffset.tickCountOffset = TimeM_GetLocalTimeBase();
    /* #50 Fill tick count buffer. */
    /*@ assert $lengthOf(tickCount) >= sizeof(Ssa_Data5ByteType); */ /* VCA_SSA_TIMEM_LENGTH_SPECIFIED_IN_FCT_CALL */
    TimeM_Copy5BytesToArray(realTimeOffset.tickCountOffset, tickCount);

    retVal = RTE_E_OK;
#else
    SSA_DUMMY_STATEMENT(dateTimeOffset);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT(tickCountOffset); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT(tickCount);       /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

    /* retVal already set */
#endif /* ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM ) */
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_TimeRawData_ResetLocalTickCount
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetLocalTickCount> of PortPrototype <TimeM_TimeRawData>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_TimeRawData_ResetLocalTickCount(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TimeM_TimeRawData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_TimeRawData_ResetLocalTickCount_doc
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

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_TimeRawData_ResetLocalTickCount(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_TimeRawData_ResetLocalTickCount (returns application error)
 *********************************************************************************************************************/

#if ( SSA_ECU_TYPE != SSA_ECU_TYPE_VSM )
  Std_ReturnType ret;

  /* #10 Reset local tick count. */
  uint64 localTickCount =  0uLL;
  ret = Rte_Call_FvM_InitialTickCount_Set(localTickCount);
  if (ret == RTE_E_OK)
  {
    TimeM_SetLocalTimeBase(localTickCount);
  }

  /* #20 Request for writing the real-time offset and the tick-count NVRam block. */
  Rte_Enter_TimeM_ExclusiveArea();
  TimeM_RealTimeOffsetNvmWriteRequested = TRUE;
  TimeM_TickCountNvmWriteRequested = TRUE;
  /* Store current TickCount that shall be written to NvM */
  *Rte_Pim_TickCountValueToBeStoredToNvM() = *Rte_Pim_TickCount();
  Rte_Exit_TimeM_ExclusiveArea();
  return ret;
#else
  return E_NOT_OK;
#endif /* ( SSA_ECU_TYPE != SSA_ECU_TYPE_VSM ) */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_TimeM_TimeRawData_Set
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <TimeM_TimeRawData>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_InitialTickCount_Set(uint64 tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_InitialTickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_TimeM_ExclusiveArea(void)
 *   void Rte_Exit_TimeM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_TimeM_TimeRawData_Set(const uint8 *dateTimeOffset, const uint8 *tickCountOffset, const uint8 *tickCount)
 *     Argument dateTimeOffset: uint8* is of type Ssa_Data7ByteType
 *     Argument tickCountOffset: uint8* is of type Ssa_Data5ByteType
 *     Argument tickCount: uint8* is of type Ssa_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_TimeM_TimeRawData_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_TimeRawData_Set_doc
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
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_TimeM_CODE) Ssa_TimeM_TimeRawData_Set(P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) dateTimeOffset, P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) tickCountOffset, P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) tickCount) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_TimeM_TimeRawData_Set (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_TimeM_TimeRawData_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((dateTimeOffset == NULL_PTR) || (tickCountOffset == NULL_PTR) || (tickCount == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
#if ( SSA_ECU_TYPE != SSA_ECU_TYPE_VSM )
    TimeM_DateTimeType realTime = { 0 };
    TimeM_RealTimeOffsetType realTimeOffset, realTimeOffsetOld;
    uint64 localTickCount, localTickCountOld;
    retVal = RTE_E_FvM_InitialTickCount_E_NOT_OK;

    /* #10 Get stored real-time offset before overwriting. */
    TimeM_GetRealTimeOffset(&realTimeOffsetOld);
    /* #20 Get local tick count before overwriting. */
    localTickCountOld = TimeM_GetLocalTimeBase();

    /* Date and time offset. */
    realTimeOffset.dateTimeReference.year = (uint16)(((uint16)dateTimeOffset[0] << 8u) | dateTimeOffset[1]);
    realTimeOffset.dateTimeReference.month = dateTimeOffset[2];
    realTimeOffset.dateTimeReference.day = dateTimeOffset[3];
    realTimeOffset.dateTimeReference.hour = dateTimeOffset[4];
    realTimeOffset.dateTimeReference.minute = dateTimeOffset[5];
    realTimeOffset.dateTimeReference.second = dateTimeOffset[6];
    /* Tick count offset. */
    realTimeOffset.tickCountOffset = (uint64)tickCountOffset[0] << 32;
    realTimeOffset.tickCountOffset |= (uint64)tickCountOffset[1] << 24;
    realTimeOffset.tickCountOffset |= (uint64)tickCountOffset[2] << 16;
    realTimeOffset.tickCountOffset |= (uint64)tickCountOffset[3] << 8;
    realTimeOffset.tickCountOffset |= (uint64)tickCountOffset[4];
    /* Set new local tick count. */
    localTickCount = (uint64)tickCount[0] << 32;
    localTickCount |= (uint64)tickCount[1] << 24;
    localTickCount |= (uint64)tickCount[2] << 16;
    localTickCount |= (uint64)tickCount[3] << 8;
    localTickCount |= (uint64)tickCount[4];

    /* #30 Consistency check of time data. */
      /* The second checks for the tickCounts ensure that TimeM_CalcRealTime and TimeM_LogTimeChange do not fail. */

    if (TimeM_IsRealTimeOffSetValid(realTimeOffset) && (realTimeOffset.tickCountOffset <= localTickCount))
    {
      uint8 contextDateTimeChange = TIMEM_ORIGIN_NEW_TIME_INITIALIZE_BY_ROUTINE_CONTROL;
      boolean logTickCountDiff = FALSE;

      retVal = RTE_E_OK;

      /* #40 Set new real-time offset. */
      TimeM_SetRealTimeOffset(&realTimeOffset);
      /* #50 Set new localTickCount in TimeM and FvM. */
      (void)Rte_Call_FvM_InitialTickCount_Set(localTickCount);
      TimeM_SetLocalTimeBase(localTickCount);

      /* #60 Request for writing the real-time offset and the tick-count NVRam block. */
      Rte_Enter_TimeM_ExclusiveArea();
      TimeM_RealTimeOffsetNvmWriteRequested = TRUE;
      TimeM_TickCountNvmWriteRequested = TRUE;
      /* Store current TickCount that shall be written to NvM */
      *Rte_Pim_TickCountValueToBeStoredToNvM() = *Rte_Pim_TickCount();
      Rte_Exit_TimeM_ExclusiveArea();

      /* #70 Calculate new real-time (used for logging the tick-count difference) only if old real-time offset is valid. */
      if (TimeM_IsRealTimeOffSetValid(realTimeOffsetOld) && (realTimeOffsetOld.tickCountOffset <= localTickCountOld))
      {
        logTickCountDiff = TRUE;
        /* The consistency checks (30) ensure that CalcRealTime does not fail. */
        (void)TimeM_CalcRealTime(localTickCount, &realTimeOffset, (P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTime);
      }

      /* #80 Write security log. */
      /* The consistency checks above (30) ensure that LogTimeChange does not fail. */
      (void)TimeM_LogTimeChange(
        &realTimeOffsetOld,
        localTickCountOld,
        (P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTime,
        contextDateTimeChange,
        logTickCountDiff);
    }
#else
    SSA_DUMMY_STATEMENT_CONST(dateTimeOffset); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT_CONST(tickCountOffset); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT_CONST(tickCount); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

    retVal = E_NOT_OK;
#endif /* ( SSA_ECU_TYPE != SSA_ECU_TYPE_VSM ) */
  }

  return retVal;
  /* PRQA S 6050 4 */ /* MD_MSR_STCAL */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ssa_TimeM_STOP_SEC_CODE
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_TimeM_START_SEC_CODE
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * TimeM_Copy5BytesToArray()
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_Copy5BytesToArray(uint64 value, P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) buffer)
{
  /* #10 Copy the 5 lowest bytes byte-by-byte into the given byte array (high byte first). */
  buffer[0] = (uint8)((value >> 32) & 0xFFu);
  buffer[1] = (uint8)((value >> 24) & 0xFFu);
  buffer[2] = (uint8)((value >> 16) & 0xFFu);
  buffer[3] = (uint8)((value >> 8) & 0xFFu);
  buffer[4] = (uint8)(value & 0xFFu);
}

/**********************************************************************************************************************
 * TimeM_SetLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_SetLocalTimeBase(uint64 timeBase)
{
  /* #10 If the passed tick-count value does not exceed the maximum tick-count value copy it to the memory address of the
   * local tick-count within an exclusive area. */
  if (timeBase <= TIMEM_LOCAL_TIME_BASE_MAX_TICK_COUNT_VAL)
  {
    Rte_Enter_TimeM_ExclusiveArea();
    *Rte_Pim_TickCount() = timeBase;
    Rte_Exit_TimeM_ExclusiveArea();
  }
}

/**********************************************************************************************************************
 * TimeM_GetLocalTimeBase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_TIMEM_LOCAL_INLINE FUNC(uint64, Ssa_TimeM_CODE) TimeM_GetLocalTimeBase(void)
{
  uint64 localTimeBase;
  /* #10 Copy the stored local tick-count to a temporary buffer within an exclusive area. */
  Rte_Enter_TimeM_ExclusiveArea();
  localTimeBase = *Rte_Pim_TickCount();
  Rte_Exit_TimeM_ExclusiveArea();
  /* #20 Return the tick-count. */
  return localTimeBase;
}

/**********************************************************************************************************************
 * TimeM_SetRealTimeOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_SetRealTimeOffset(P2CONST(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffset)
{
  /* #10 Copy the given real-time offset to the stored real-time offset within an exclusive area. */
  Rte_Enter_TimeM_ExclusiveArea();
  *Rte_Pim_RealTimeOffset() = *realTimeOffset;
  Rte_Exit_TimeM_ExclusiveArea();
}

/**********************************************************************************************************************
 * TimeM_GetRealTimeOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_GetRealTimeOffset(P2VAR(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffset)
{
  /* #10 Copy the stored real-time offset to the given memory location within an exclusive area. */
  Rte_Enter_TimeM_ExclusiveArea();
  *realTimeOffset = *Rte_Pim_RealTimeOffset();
  Rte_Exit_TimeM_ExclusiveArea();
}

/**********************************************************************************************************************
 * TimeM_PackOffsetBroadcastMessage()
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
#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_PackOffsetBroadcastMessage(P2VAR(uint8, AUTOMATIC, AUTOMATIC) packedData)
{
  TimeM_RealTimeOffsetType realTimeOffset = { 0u };

  /* Get stored real time offset . */
  TimeM_GetRealTimeOffset(&realTimeOffset);

  /* SSA-IS-1498 ... This "real-time offset" is made up of a date/time information in generalized time format
  (date/time offset) and the local tick-count of the VSM at the time, this date/time
  information was set at the VSM (tick-count offset). */
  /* SSA-IS-1625 The date time information shall consist of seven bytes containing the following
  information in binary encoding:
  Byte 0 .. 1 the year
  Byte 2  the month
  Byte 3  the day
  Byte 4  the hours
  Byte 5  the minutes
  Byte 6  the seconds */

  /* #10 Fill the data of real-time offset data structure into the data buffer.
   *   Byte 0 .. 1  the year
   *   Byte 2       the month
   *   Byte 3       the day
   *   Byte 4       the hours
   *   Byte 5       the minutes
   *   Byte 6       the seconds
   *   Byte 7 .. 11 the tick-count offset
   *   The packed data follow the rule: High byte first. */

  packedData[0] = (uint8)(realTimeOffset.dateTimeReference.year >> 8);
  packedData[1] = (uint8)(realTimeOffset.dateTimeReference.year & 0xFFu);
  packedData[2] = realTimeOffset.dateTimeReference.month;
  packedData[3] = realTimeOffset.dateTimeReference.day;
  packedData[4] = realTimeOffset.dateTimeReference.hour;
  packedData[5] = realTimeOffset.dateTimeReference.minute;
  packedData[6] = realTimeOffset.dateTimeReference.second;
  TimeM_Copy5BytesToArray(realTimeOffset.tickCountOffset, &packedData[7]);
}
#endif

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_NORMAL) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
 * TimeM_UnpackOffsetBroadcastMessage()
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
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_UnpackOffsetBroadcastMessage(P2CONST(uint8, AUTOMATIC, AUTOMATIC) packedData, P2VAR(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffset)
{
  /* SSA-IS-1498 ... This "real-time offset" is made up of a date/time information in generalized time format
  (date/time offset) and the local tick-count of the VSM at the time, this date/time
  information was set at the VSM (tick-count offset). */
  /* SSA-IS-1625 The date time information shall consist of seven bytes containing the following
  information in binary encoding:
  Byte 0 .. 1 the year
  Byte 2  the month
  Byte 3  the day
  Byte 4  the hours
  Byte 5  the minutes
  Byte 6  the seconds */

  /* #10 Fill the date time information and the tick-count offset into the real-time offset data structure.
     *   Byte 0 .. 1  the year
     *   Byte 2       the month
     *   Byte 3       the day
     *   Byte 4       the hours
     *   Byte 5       the minutes
     *   Byte 6       the seconds
     *   Byte 7 .. 11 the tick-count offset
     *   The packed data follow the rule: High byte first. */
  realTimeOffset->dateTimeReference.year = (uint16)(((uint16)packedData[0] << 8) | (uint16)packedData[1]);
  realTimeOffset->dateTimeReference.month = packedData[2];
  realTimeOffset->dateTimeReference.day = packedData[3];
  realTimeOffset->dateTimeReference.hour = packedData[4];
  realTimeOffset->dateTimeReference.minute = packedData[5];
  realTimeOffset->dateTimeReference.second = packedData[6];
  realTimeOffset->tickCountOffset = (uint64)packedData[7] << 32;
  realTimeOffset->tickCountOffset |= (uint64)packedData[8] << 24;
  realTimeOffset->tickCountOffset |= (uint64)packedData[9] << 16;
  realTimeOffset->tickCountOffset |= (uint64)packedData[10] << 8;
  realTimeOffset->tickCountOffset |= (uint64)packedData[11];
}
#endif

/**********************************************************************************************************************
 * TimeM_GetDaysOfMonth()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_TIMEM_LOCAL_INLINE FUNC(uint8, Ssa_TimeM_CODE) TimeM_GetDaysOfMonth(uint8 month, uint16 year)
{
  boolean isLeapYearAndFebruary = FALSE;
  uint8 daysOfMonth;

  /* #10 Check if considered month is a February. */
  if (month == 1u)
  {
    /* #20 It's February: Check for leap year. */
    if (((year % 4u) == 0u) && (((year % 100u) != 0u) || ((year % 400u) == 0u)))
    {
      isLeapYearAndFebruary = TRUE;
    }
  }

  /* #30 Depending on if it is a leap year return the number of days of the month. */
  if (isLeapYearAndFebruary == TRUE)
  {
    daysOfMonth = TIMEM_DAYS_IN_FEBRUARY_LEAPYEAR;
  }
  else
  {
    daysOfMonth = TimeM_DaysNonLeapYear[month % 12u];
  }
  return daysOfMonth;
}

/**********************************************************************************************************************
 * TimeM_CalcTickCountDifference()
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
  */
SSA_TIMEM_LOCAL FUNC(void, Ssa_TimeM_CODE) TimeM_CalcTickCountDifference(
  P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) lowDateTime,
  P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) highDateTime,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) tickDifference)
{
  uint16 year;
  uint8 month;
  uint64 lowTicks, highTicks;
  uint16 year_high = highDateTime->year;
  /* modulo operation is needed for FETA justification */
  uint8 month_high = (uint8)(highDateTime->month - 1u) % 12u;

  /* Use low year and month as zero time point. */
  /* #10 Calculate low time difference to zero time point in ticks */
  lowTicks = TimeM_Days2Ticks((uint64)lowDateTime->day);
  lowTicks += TimeM_Hours2Ticks((uint64)lowDateTime->hour);
  lowTicks += TimeM_Minutes2Ticks((uint64)lowDateTime->minute);
  lowTicks += TimeM_Seconds2Ticks((uint64)lowDateTime->second);

  /* #20 Calculate high time difference to zero time point in ticks */
  highTicks = 0u;
  year = lowDateTime->year;
  /* modulo operation is needed for FETA justification */
  month = (uint8)(lowDateTime->month - 1u) % 12u; /* Transform Range[1:12] to Range[0:11] */
  /* Add ticks for each month between the two dates (year and month)*/
  while ((year < year_high) || ((year == year_high) && (month < month_high))) /* FETA_WHILE_LOOP_CALC_TICK_COUNT_DIFFERENCE */
  {
    highTicks += TimeM_Days2Ticks((uint64)TimeM_GetDaysOfMonth(month, year));

    /*  Update month. */
    month = (month + 1u) % 12u;
    /* Check if a new year starts. */
    if ((year < year_high) && (month == 0u))
    {
      /* It is a new year. Update year. Prevent year value overrun is not required due to comparison with highDateTime->year. */
      ++year;
    }
  }
  highTicks += TimeM_Days2Ticks((uint64)highDateTime->day);
  highTicks += TimeM_Hours2Ticks((uint64)highDateTime->hour);
  highTicks += TimeM_Minutes2Ticks((uint64)highDateTime->minute);
  highTicks += TimeM_Seconds2Ticks((uint64)highDateTime->second);

  /* #30 Calculate absolute difference between the two times. */
  TimeM_Copy5BytesToArray(highTicks - lowTicks, tickDifference);
}

/**********************************************************************************************************************
 * TimeM_CalcRealTime()
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
 */
SSA_TIMEM_LOCAL FUNC(Std_ReturnType, Ssa_TimeM_CODE) TimeM_CalcRealTime(
  uint64 localTimeBase,
  P2CONST(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffset,
  P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) dateTimeOut)
{
  Std_ReturnType ret = RTE_E_OK;
  uint64 localTimeBaseTmp = localTimeBase;

  /* Copy the reference dateTime to the return value. */
  *dateTimeOut = realTimeOffset->dateTimeReference;
  /* Transform range for day from 1-31 -> 0-30 and for month from 1-12 -> 0-11 for the following calculations. */
  dateTimeOut->day -= 1u;
  dateTimeOut->month -= 1u;

  /* #10 The local time base must not be smaller than the tick-count offset value.*/
  if (localTimeBaseTmp >= realTimeOffset->tickCountOffset)
  {
    /* #20 Correct local time base by tick-count offset. */
    localTimeBaseTmp -= realTimeOffset->tickCountOffset;

    /* #30 Reduce resolution for the local time base to seconds. */
    localTimeBaseTmp = (localTimeBaseTmp + (50uLL)) / (100uLL);

    /* #40 Add second part of the reference dateTime to the local time base.*/
    localTimeBaseTmp += dateTimeOut->second;
    dateTimeOut->second = (uint8)(localTimeBaseTmp % 60u);
    /* localTimeBaseTmp now representing minutes. */
    localTimeBaseTmp /= 60u;

    /* #50 Add minutes part of the reference dateTime to the local time base.*/
    localTimeBaseTmp += dateTimeOut->minute;
    dateTimeOut->minute = (uint8)(localTimeBaseTmp % 60u);
    /* localTimeBaseTmp now representing hours. */
    localTimeBaseTmp /= 60u;

    /* #60 Add hours part of the reference dateTime to the local time base.*/
    localTimeBaseTmp += dateTimeOut->hour;
    dateTimeOut->hour = (uint8)(localTimeBaseTmp % 24u);
    /* localTimeBaseTmp now representing days. */
    localTimeBaseTmp /= 24u;

    while (localTimeBaseTmp > 0u) /* FETA_MONOTONIC_WHILE_LOOP_DOWN */
    {
      /* #80 Get the number of days of the considered month and year. */
      uint8 daysToEndOfMonth = (uint8)(TimeM_GetDaysOfMonth(dateTimeOut->month, dateTimeOut->year) - dateTimeOut->day);

      /* #90 Check if a month or more is to add. */
      if (localTimeBaseTmp >= daysToEndOfMonth)
      {
        /* #100 Update month. */
        dateTimeOut->month = (dateTimeOut->month + 1u) % 12u;
        /* #110 Check if a new year starts. */
        if ((dateTimeOut->month == 0u) && (dateTimeOut->year != 0xFFFFu))
        {
          /* #120 It is a new year. Update year. Prevent year value overrun. */
          ++dateTimeOut->year;
        }
        /* #130 Update day. */
        dateTimeOut->day = 0u;
        /* #140 Update remaining days. */
        localTimeBaseTmp -= daysToEndOfMonth;
      }
      else
      {
        /* #150 Month and year stay unchanged. Finally correct the day. */
        dateTimeOut->day += (uint8)localTimeBaseTmp;
        /* #160 Set remaining days to zero in order to leave the loop. */
        localTimeBaseTmp = 0u;
      }
    }
  }
  else
  {
    /* Real-time can't be calculated. */
    ret = RTE_E_INVALID;
  }

  /* Transform range for day from 0-30 -> 1-31 and for month from 0-11 -> 1-12. */
  dateTimeOut->day += 1u;
  dateTimeOut->month += 1u;

  return ret;
}

/**********************************************************************************************************************
 * TimeM_IsDateTimeValid()
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
 */
SSA_TIMEM_LOCAL_INLINE FUNC(boolean, Ssa_TimeM_CODE) TimeM_IsDateTimeValid(P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) dateTime)
{
  boolean ret = FALSE;

  /* #10 Following ranges must be met for valid date/time:
   * second in [0:59]
   * minute in [0:59]
   * hour   in [0:23]
   * day    in [1:x], x = 28,29,30 or 31 depending on month and year
   * month  in [1:12]
   * year   in [0:65535]. */

  /* 20 Check the second, the minute and the hour. */
  if ((dateTime->second > 59u) || (dateTime->minute > 59u) || (dateTime->hour > 23u))
  {
    /* invalid */
  }
  /* 20 Check the month. */
  else if ((dateTime->month < 1u) || (dateTime->month >12u))
  {
    /* invalid */
  }
  /* #30 No need to check the year since there is no limitation within the range of used variable type. */
  else
  {
    /* #40 In order to check the day value get the number of days for the considered month and year. */
    uint8 daysOfMonth = TimeM_GetDaysOfMonth((uint8)(dateTime->month - 1u), dateTime->year);
    /* #45 Check the day. */
    if ((dateTime->day < 1u) || (dateTime->day > daysOfMonth))
    {
      /* invalid */
    }
    else
    {
      ret = TRUE;
    }
  }
  return ret;
}

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
 * TimeM_BroadcastRealTimeOffset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_TIMEM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_TimeM_CODE) TimeM_BroadcastRealTimeOffset(void)
{
  Ssa_Data12ByteType TimeM_RealTimeOffsetBroadcastMessage;
  /* #10 Pack real-time offset broadcast message. */
  TimeM_PackOffsetBroadcastMessage(TimeM_RealTimeOffsetBroadcastMessage);
  /* #20 Send real-time offset broadcast message. */
  return Rte_Write_TimeM_Com_SendRealTimeOffset_realTimeOffset((P2CONST(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA))TimeM_RealTimeOffsetBroadcastMessage);
}
#endif

/**********************************************************************************************************************
 * TimeM_HandleRealTimeOffset()
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
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_HandleRealTimeOffset(void)
{
  Std_ReturnType ret;
  NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

  /* #10 If the writing of real-time offset NVRAM block has been requested and if writing is not ongoing copy the
   *     real-time offset RAM block to a RAM block mirror. Then start the writing of the RAM block mirror to the NVM. */
  if ((TimeM_RealTimeOffsetNvmWriteRequested == TRUE) && (TimeM_RealTimeOffsetNvmWriteState == TIMEM_NVM_WRITE_STATE_IDLE))
  {
    Rte_Enter_TimeM_ExclusiveArea();
    *Rte_Pim_RealTimeOffsetMirror() = *Rte_Pim_RealTimeOffset();
    TimeM_RealTimeOffsetNvmWriteRequested = FALSE;
    TimeM_RealTimeOffsetNvmWriteState = TIMEM_NVM_WRITE_STATE_START;
    Rte_Exit_TimeM_ExclusiveArea();
  }

  /* #20 Check that writing to NVM has been started or is pending.*/
  if (TimeM_RealTimeOffsetNvmWriteState != TIMEM_NVM_WRITE_STATE_IDLE)
  {
    /* #30 Get status of NVRAM block. */
    ret = Rte_Call_NvMService_RealTimeOffset_GetErrorStatus(&errorStatus);
    if ((ret == E_OK) && (errorStatus != NVM_REQ_PENDING))
    {
      /* #40 Write NV block if it has been started and do not change back to idle state as long as NVRAM block status is pending . */
      if (TimeM_RealTimeOffsetNvmWriteState == TIMEM_NVM_WRITE_STATE_START)
      {
        if (Rte_Call_NvMService_RealTimeOffset_WriteBlock((dtRef_const_VOID)(Rte_Pim_RealTimeOffsetMirror())) == E_OK) /* PRQA S 0314 */ /* MD_SSA_P2VOID_CAST */
        {
          TimeM_RealTimeOffsetNvmWriteState = TIMEM_NVM_WRITE_STATE_PENDING;
        }
      }
      /* must be TIMEM_NVM_WRITE_STATE_PENDING */
      else
      {
        TimeM_RealTimeOffsetNvmWriteState = TIMEM_NVM_WRITE_STATE_IDLE;
      }
    }
  }
  else
  {
    /* no action */
  }
}

/**********************************************************************************************************************
 * TimeM_HandleTickCount()
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
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_HandleTickCount(void)
{
  Std_ReturnType ret;
  NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

  /* #10 If the writing of tick-count NVRAM block has been requested and if writing is not ongoing copy the
*     tick-count RAM block to a RAM block mirror. Then start the writing of the RAM block mirror to the NVM. */
  if ((TimeM_TickCountNvmWriteRequested == TRUE) && (TimeM_TickCountNvmWriteState == TIMEM_NVM_WRITE_STATE_IDLE))
  {
    Rte_Enter_TimeM_ExclusiveArea();
    /* Write the tickCount of the time at which the write request was started to the Mirror, since the current tickcount can have been changed meanwhile. */
    *Rte_Pim_TickCountMirror() = *Rte_Pim_TickCountValueToBeStoredToNvM();
    TimeM_TickCountNvmWriteRequested = FALSE;
    TimeM_TickCountNvmWriteState = TIMEM_NVM_WRITE_STATE_START;
    Rte_Exit_TimeM_ExclusiveArea();
  }

  if (TimeM_TickCountNvmWriteState != TIMEM_NVM_WRITE_STATE_IDLE)
  {
    /* #20 Get status of NVRAM block. */
    ret = Rte_Call_NvMService_TickCount_GetErrorStatus(&errorStatus);
    if ((ret == E_OK) && (errorStatus != NVM_REQ_PENDING))
    {
      /* #30 Write NV block if it has been started and do not change back to idle state as long as NVRAM block status is pending . */
      if (TimeM_TickCountNvmWriteState == TIMEM_NVM_WRITE_STATE_START)
      {
        if (Rte_Call_NvMService_TickCount_WriteBlock((dtRef_const_VOID)(Rte_Pim_TickCountMirror())) == E_OK) /* PRQA S 0314 */ /* MD_SSA_P2VOID_CAST */
        {
          TimeM_TickCountNvmWriteState = TIMEM_NVM_WRITE_STATE_PENDING;
        }
      }
      /* must be TIMEM_NVM_WRITE_STATE_PENDING */
      else
      {
        TimeM_TickCountNvmWriteState = TIMEM_NVM_WRITE_STATE_IDLE;
      }
    }
  }
  else
  {
    /* #40 In IDLE state (which is the default state)  mark the tick-count NVRam block as changed so that it will be
     *     written during ECU shut-down. */
    (void)Rte_Call_NvMService_TickCount_SetRamBlockStatus(TRUE);
  }
}

/**********************************************************************************************************************
 * TimeM_HandleNvm()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_TIMEM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) TimeM_HandleNvm(void)
{
  /* #10 Call TimeM_HandleTickCount() to write the tick-count NVRam block if requested. */
  TimeM_HandleTickCount();
  /* #20 Call TimeM_HandleRealTimeOffset() to write the real-time offset NVRam block if requested. */
  TimeM_HandleRealTimeOffset();
}

/**********************************************************************************************************************
 *  TimeM_FormatAccordingToGeneralizedTime()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_TIMEM_LOCAL FUNC(void, Ssa_TimeM_CODE) TimeM_FormatAsGeneralizedTime(
  P2CONST(TimeM_DateTimeType, AUTOMATIC, AUTOMATIC) dateTime,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) generalizedTime)
{
  /* #10 Format date and time according to format of the Generalized Time: YYYYMMDDHHMMSSZ. */
  uint16 rest = dateTime->year;
  /* Year: YYYY */
  generalizedTime[0] = (uint8)((rest / 1000u) + 0x30u);
  rest %= 1000u;
  generalizedTime[1] = (uint8)((rest / 100u) + 0x30u);
  rest %= 100u;
  generalizedTime[2] = (uint8)((rest / 10u) + 0x30u);
  rest %= 10u;
  generalizedTime[3] = (uint8)(rest + 0x30u);
  /* Month: MM */
  generalizedTime[4] = (uint8)((dateTime->month / 10u) + 0x30u);
  generalizedTime[5] = (uint8)((dateTime->month % 10u) + 0x30u);
  /* Day: DD */
  generalizedTime[6] = (uint8)((dateTime->day / 10u) + 0x30u);
  generalizedTime[7] = (uint8)((dateTime->day % 10u) + 0x30u);
  /* Hour: HH */
  generalizedTime[8] = (uint8)((dateTime->hour / 10u) + 0x30u);
  generalizedTime[9] = (uint8)((dateTime->hour % 10u) + 0x30u);
  /* Minute: MM */
  generalizedTime[10] = (uint8)((dateTime->minute / 10u) + 0x30u);
  generalizedTime[11] = (uint8)((dateTime->minute % 10u) + 0x30u);
  /* Second: SS */
  generalizedTime[12] = (uint8)((dateTime->second / 10u) + 0x30u);
  generalizedTime[13] = (uint8)((dateTime->second % 10u) + 0x30u);
  /* UTC: Z */
  generalizedTime[14] = (uint8)0x5Au;
}

/**********************************************************************************************************************
*  TimeM_LogTimeChange()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
*/
SSA_TIMEM_LOCAL FUNC(Std_ReturnType, Ssa_TimeM_CODE) TimeM_LogTimeChange(
  P2CONST(TimeM_RealTimeOffsetType, AUTOMATIC, AUTOMATIC) realTimeOffsetOld,
  uint64 localTickCountOld,
  P2CONST(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_DATA) realTime,
  uint8 contextDateTimeChange,
  boolean logTickCountDiff)
{
  Std_ReturnType retVal;
  TimeM_DateTimeType realTimeOld;
  boolean timeSetToPast = FALSE;
  uint8 tickCountDifference[TIMEM_SIZEOF_TICKCOUNT_IN_BYTES] = { 0xFFu, 0xFFu, 0xFFu, 0xFFu, 0xFFu };
  uint8 contextDateTimeChangeLog = contextDateTimeChange;

  if (logTickCountDiff)
  {
    /* #10 Calculate old real-time. */
    retVal = TimeM_CalcRealTime(localTickCountOld, realTimeOffsetOld, (P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTimeOld);
    if (retVal == RTE_E_OK)
    {
      /* #20 Find out direction of time change. */
      (void)Ssa_TimeM_RealTime_Compare(realTime, TIMEM_IS_LESS, (P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTimeOld, &timeSetToPast);
      /* #30 Calculate TickCountDifference. */
      if (timeSetToPast == TRUE)
      {
        /* Time set to past. */
        contextDateTimeChangeLog |= TIMEM_TIME_SET_TO_PAST;
        TimeM_CalcTickCountDifference(realTime, (P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTimeOld, tickCountDifference);
      }
      else
      {
        TimeM_CalcTickCountDifference((P2VAR(TimeM_DateTimeType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR))&realTimeOld, realTime, tickCountDifference);
      }
    }
  }
  /* #40 Write security log. */
  retVal = Rte_Call_SecLog_ChangeTickCountOrDateAndTimeEvent_ChangeTickCountOrDateAndTime(contextDateTimeChangeLog, tickCountDifference);
  return retVal;
}

#define Ssa_TimeM_STOP_SEC_CODE
#include "Ssa_TimeM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

    \ID  VCA_SSA_TIMEM_LENGTH_SPECIFIED_IN_FCT_CALL
      \DESCRIPTION      According to VCA, the following assertion is possibly violated:
                          $lengthOf(<parameter>) >= <specified size>.
      \COUNTERMEASURE   \N A specification ensures that when the function is called,
                        $lengthOf(<parameter>) >= <specified size> holds.

 VCA_JUSTIFICATION_END */


/***********************************************************************************************************************
 *  FETA JUSTIFICATIONS
 **********************************************************************************************************************/
/* FETA_JUSTIFICATION_BEGIN

  \ID FETA_MONOTONIC_WHILE_LOOP_DOWN
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - TimeM_CalcRealTime()
    \COUNTERMEASURE \N The here applied while loop has the counter variable localTimeBaseTmp that is strictly monotonically
                       decreasing since always a value greater 0 is assigned by TimeM_GetDaysOfMonth to variable
                       daysToEndOfMonth which decrements the counter variable in each single loop.
                       The loop's lower bound is 0 and remains unchanged during loop execution.
                       A wrap around of localTimeBaseTmp (i.e. a negative value interpreted as positive value) is
                       prevented by a comparison against daysToEndOfMonth before decrementing. In this case the loop is
                       finished by setting daysToEndOfMonth to 0.

  \ID FETA_WHILE_LOOP_CALC_TICK_COUNT_DIFFERENCE
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - TimeM_CalcTickCountDifference()
    \COUNTERMEASURE \N The here applied while loop has two counter variables year and month.
                       The type of both counter variables are appropriate for the upper bound variables that they are compared with.
                       Both upper bounds remain unchanged during complete loop execution.
                       As long as it is year < year_high, year is incremented once within 12 loop cycles.
                       Then, as long as it is year == year_high and month < month_high month is incremented within each loop cycle.
                       Both month and month_high are restricted to values < 12 by modulo 12 operation, so the condition is  month < month_high
                       is reachable. So finally loop finishes.
FETA_JUSTIFICATION_END */
