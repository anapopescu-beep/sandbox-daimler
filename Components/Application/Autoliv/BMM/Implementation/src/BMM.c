/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.1.16.2.12 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/BMM/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup BMM_AC_BeltMovementMonitoring BMM
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_BMM_AC_BeltMovementMonitoring.h"
#include "common.h"
#include "config.h"
#include "BMM.h"
#include "BMM_cfg_generic.h"
#include "Nvp_Generated.h"

/* MCAL inclusions allowed for IO-HW abstraction component */
#include "Port.h"
#include "Dio.h"
#include "IfxGpt12_reg.h"
#include "IfxSrc_reg.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *		Number of high pulses and low pulses (that is to say falling edge and
 * 		rising edge) occurring on one hall effect sensor channel (A or B)
 * 		during a hall A or hall B signal's period if the direction do not change.
 */
#define  KS16_NB_PULSE_PER_PERIOD               ((s16PositionType)4)

/**
 * \brief
 *		Position difference corresponding to a hall signal's period caused by a
 * 		constant belt releasing displacement.
 */
#define  KS16_RELEASE_DT_POSITION_IN_PERIOD     ((s16PositionType)4)

/**
 * \brief
 *		Position difference corresponding to a hall signal's period caused by a
 * 		constant belt tensioning displacement.
 */
#define  KS16_TENSION_DT_POSITION_IN_PERIOD     ((s16PositionType)-4)

/**
 * \brief
 *		Position difference corresponding to a hall signal's period caused by
 * 		both releasing and tensioning displacements that cancel each other.
 */
#define  KS16_NULL_DT_POSITION_IN_PERIOD        ((s16PositionType)0)

/**
 * \brief
 *		Number of degrees rotation in a complete turn, for unit conversion.
 */
#define  KS16_NB_DEGREES_PER_TURN               ((sint16)360)

/**
 * \brief
 *		Number of degrees rotation per same edge.
 */
#define KU8_DEGREES_PER_EDGE 				         ((uint8)5)

/**
 * \brief
 *		Number of north+south poles couples.
 */
#define  KS16_NB_PAIRS_OF_POLES_CFG             ((sint16)BMM_NB_PAIRS_OF_POLES_CFG)

/**
 * \brief
 *		Number of milliseconds in a seconds, for unit conversion.
 */
#define  NB_MS_IN_S                             (1000uL)
#define  KU32_NB_MS_IN_S                        ((uint32) NB_MS_IN_S)

/**
 * \brief
 *		The 16 bits hardware timer range.
 */
#define  HARD_TIMER_RANGE                       (0x10000uL)

/**
 * \brief
 *		The software timer full range: Correspond to a 24 bits timer, made with a combination of the hardware 16 bits timer and
 * 		the overflow 8 bits counter.
 */
#define  SOFT_TIMER_RANGE                       (0x100u * HARD_TIMER_RANGE)

/**
 * \brief
 *		The hardware timer half range. Timer counter value at timer overflow period's middle.
 */
#define  KU16_HARD_TIMER_HALF_RANGE             ((uint16)0x8000)

/**
 * \brief
 *		The period max configuration parameter converted into core clock lsb, knowing that the core clocks directly the Timer1.
 */
#define NB_CLK_IN_PERIOD                        ((BMM_CFG_TIMER_INPUT_CLK/NB_MS_IN_S)*BMM_PERIOD_MAX_MS)

/**
 * \brief
 *		Macro used to retrieve the current timer counter value.
 */
#define U16_COUNTER_VALUE       			    ((uint16)GPT120_T5.B.T5)
/**
 * \brief
 *		Macro used to retrieve the stored timer counter value.
 */
#define U16_COUNTER_VALUE_STATIC			    ((uint16)GPT120_CAPREL.B.CAPREL)
/**
 * \brief
 *		Macro used to retrieve the reset timer counter value.
 */
#define KU16_RESET_COUNTER                      ((uint16)0)

/**
 * \brief
 *		Macro to get the hall sensor "A" output level, among STD_LOW and STD_HIGH.
 */
#define DIO_HALL_A                            (Dio_ReadChannel(DioConf_DioChannel_HES_A))

/**
 * \brief
 *		Macro to get the hall sensor "B" output level, among STD_LOW and STD_HIGH.
 */
#define DIO_HALL_B                            (Dio_ReadChannel(DioConf_DioChannel_HES_B))

/**
 * \brief
 *		Macro used for timer prescaler value.
 */
#define BMM_EXPECTED_TMR_PRESCALER  (NB_CLK_IN_PERIOD/SOFT_TIMER_RANGE)

/**
 * \brief
 *		Macro used for timer prescaler value.
 */
#define EXPECTED_PRESCALER ((uint32) 128)

/**
 * \brief
 *		Compute the counting frequency in Hz and kHz.
 */
#define NB_US_IN_MS                           (1000uL)

/**
 * \brief
 *		Compute the counting frequency in Hz and kHz.
 */
#define NB_US_IN_S                            (1000000uL)

/**
 * \brief
 *		Compute the counting frequency in Hz and kHz.
 */
#define KU32_NB_US_IN_MS                      ((uint32)NB_US_IN_MS)

/**
 * \brief
 *		Compute the counting frequency in Hz and kHz.
 */
#define KU32_NB_LSB_IN_S                      ((uint32)(BMM_CFG_TIMER_INPUT_CLK/EXPECTED_PRESCALER))

/**
 * \brief
 *		Compute the counting frequency in Hz and kHz
 */
#define KS32_NB_LSB_IN_S                      ((sint32)(BMM_CFG_TIMER_INPUT_CLK/EXPECTED_PRESCALER))

/**
 * \brief
 *		Compute the counting frequency in Hz and kHz.
 */
#define KS32_NB_LSB_IN_S_SINGLE_EDGE          ((sint32) (KS32_NB_LSB_IN_S/KU8_FOUR))

/**
 * \brief
 *		Compute the counting frequency in Hz and kHz.
 */
#define KU32_NB_LSB_IN_MS                     (KU32_NB_LSB_IN_S / KU32_NB_MS_IN_S)

#if (BMM_ENABLE_PYRO_DETECTION == 1)

/**
 * \brief
 *		The required number of previous consecutive positive pulses (on same or different channels)
 * 		fulfilling the duration criteria, to validate the pyro firing detection when the criteria
 * 		if fulfilled again.
 */
#define KU8_REQUIRED_NB_OF_PYRO_DETECT        ((uint8)1)

#endif

/**
 * \brief
 *		HES Fault detection.
 */
#define BMM_SENSORS_OK                        ((uint8) 0)

/**
 * \brief
 *		HES Fault detection.
 */
#define BMM_HALL_A_ERROR                      ((uint8) 1)

/**
 * \brief
 *		HES Fault detection.
 */
#define BMM_HALL_B_ERROR                      ((uint8) 2)

/**
 * \brief
 *		HES Fault detection.
 */
#define BMM_BOTH_SENSORS_ERROR                ((uint8) 3)

/**
 * \brief
 *		Number of low speed configurations.
 */
#define KU8_BMM_LOW_SPEED_INC_HW_COUNTER_NB_OF_INTERVALS ((uint8)2u)

/**
 * \brief
 *		Low speed start thres.
 */
#define KU32_BMM_LOW_SPEED_INC_HW_COUNTER_START_THRS_1   ((uint32)1015808uL)

/**
 * \brief
 *		Low speed stop thres.
 */
#define KU32_BMM_LOW_SPEED_INC_HW_COUNTER_STOP_THRS_1    ((uint32)1245184uL)

/**
 * \brief
 *		Low speed factor 1.
 */
#define KU32_BMM_LOW_SPEED_INC_HW_COUNTER_FACTOR_1       ((uint32)0x400uL)

/**
 * \brief
 *		Low speed start thres.
 */
#define KU32_BMM_LOW_SPEED_INC_HW_COUNTER_START_THRS_2   ((uint32)1245199uL)

/**
 * \brief
 *		Low speed stop thres.
 */
#define KU32_BMM_LOW_SPEED_INC_HW_COUNTER_STOP_THRS_2    ((uint32)16773120uL)

/**
 * \brief
 *		Low speed factor 1.
 */
#define KU32_BMM_LOW_SPEED_INC_HW_COUNTER_FACTOR_2       ((uint32)0xffffuL)

/**
 * \brief
 *		Number of low speed configurations.
 */
#define KU8_BMM_LOW_SPEED_SE_INC_HW_COUNTER_NB_OF_INTERVALS ((uint8)2u)

/**
 * \brief
 *		Low speed start thres.
 */
#define KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_START_THRS_1   ((uint32)1015808uL)

/**
 * \brief
 *		Low speed stop thres.
 */
#define KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_STOP_THRS_1    ((uint32)1245184uL)

/**
 * \brief
 *		Low speed factor 1.
 */
#define KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_FACTOR_1       ((uint32)0x400ul)

/**
 * \brief
 *		Low speed start thres.
 */
#define KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_START_THRS_2   ((uint32)1245199uL)

/**
 * \brief
 *		Low speed stop thres.
 */
#define KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_STOP_THRS_2    ((uint32)16773120uL)

/**
 * \brief
 *		Low speed factor 1.
 */
#define KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_FACTOR_2       ((uint32)0xffffuL)
/******************************************************************************
MODULE TYPES
******************************************************************************/
/**
 * \brief
 *		Type for belt position in the native counting unit of hall sensors event
 * 		(unit = 5° rotation in case of 18 pairs of poles).
 */
typedef sint16     s16PositionType;

 /**
  * \brief
  *		Type for period length in the hardware timer counting step unit
 * (unit = period of timer's input prescaled clock = timer overflow time / timer counting range).
  */
typedef uint32     u32PeriodType;

/**
 * \brief
 *		Internal BMM state.
 */
typedef enum Bmm_InternalStateTag
{
   Uninit = 0u,
   Run,
   Downgraded_Hall_A,
   Downgraded_Hall_B,
   Shutdown
}bmm_InternalStateType;

/**
 * \brief
 *		Internal BMM states.
 */
typedef struct
{
   bmm_InternalStateType eCurrent;
   bmm_InternalStateType ePrevious;
}bmm_stInternalStateType;

/**
 * \brief
 *		Period types.
 */
typedef enum Bmm_PeriodTypesTag
{
   KU8_RISING_A = 0u,
   KU8_FALLING_A,
   KU8_RISING_B,
   KU8_FALLING_B,
   KU8_NUMBER_OF_PERIOD_TYPES
}bmm_PeriodTypesType;

/**
 * \brief
 *		Single edge algo structure definition.
 */
typedef struct
{
   uint32 u32CurrentPeriod;
   uint16 u16TmrVal;
   uint8  u8TmrOvfl;
}bmm_stSingleEdgeData;

/**
 * \brief
 *		Low speed counter configuration.
 */
typedef struct {
   uint32 u32LowSpeedStartIncHwCounterArr;
   uint32 u32LowSpeedStopIncHwCounterArr;
   uint32 u32LowSpeedHwCounterFactor;
} bmm_LowSpeedIncHwCounterType;

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
/* Local function prototypes */
#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

LOCAL sint16 bmm_UpdatePosition(const uint8 u8HSLevel, const uint8 u8ReleaseValue);
LOCAL void bmm_ReadSpeed(const sint32 s32SpeedFactor, sint32 * const ps32Speed);
LOCAL void bmm_ReadSpeedSingleEdge(const sint32 s32SpeedFactor, sint32 * const ps32Speed);

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define BMM_AC_BeltMovementMonitoring_START_SEC_VAR_INIT_UNSPECIFIED
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

/**
 * \brief
 *		Ecpl Bobbin Speed Threshold NVP parameter converted into timer value.
 * \remarks
 *		None.
 */
LOCAL uint16 u16CplTimerCntThrs;

/**
 * \brief
 *		Belt displacement in number of input edge count (combining hall A and
 * 		hall B channels for rising and falling edges).
 * 		= 0 at initialization (the belt has never moved yet = force null speed)
 * 		> 0 after a releasing belt move
 * 		< 0 after a tensioning belt move
 * \remarks
 *		None.
 */
LOCAL volatile s16PositionType s16CurrentPosition;

/**
 * \brief
 *		Remember the bobbin position at last occurrence of each kind of edge marking
 * 		a period begin.
 * \remarks
 *		None.
 */
LOCAL s16PositionType as16Positions[KU8_NUMBER_OF_PERIOD_TYPES];

/**
 * \brief
 *		Delta between begin and end of the last completed period.
 * \remarks
 *		None.
 */
LOCAL volatile s16PositionType s16LastPeriodDisplacement;

/**
 * \brief
 *		Remember the timer's values which have been captured on last occurrence of
 * 		each kind of edge marking a period begin.
 * \remarks
 *		None.
 */
LOCAL volatile uint16 au16Captures[KU8_NUMBER_OF_PERIOD_TYPES];

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL volatile s16BeltPosition_degType bmm_s16BeltPositionFromT0_deg;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL volatile s16BeltPosition_mmType bmm_s16BeltPositionFromT0_mm;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL volatile s16BeltPosition_degType bmm_s16BeltPositionFromMinPos_deg;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL volatile s16BeltPosition_mmType bmm_s16BeltPositionFromMinPos_mm;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL volatile s16BeltPosition_degType bmm_s16BeltPosition_min_deg;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL volatile s16BeltPosition_degType bmm_s16BeltPosition_max_deg;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL volatile s16BeltPosition_mmType bmm_s16BeltPosition_min_mm;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL volatile s16BeltPosition_mmType bmm_s16BeltPosition_max_mm;

/**
 * \brief
 *		Last completed period duration. This "Last" period is supposed to be either
 * 		between rising edges or between falling edges, occurred either on the hall A
 * 		or on the hall B channel. The duration is given in timer's counter lsb and
 * 		depends from hardware clock and timer prescaler configuration.
 * \remarks
 *		None.
 */
LOCAL volatile u32PeriodType u32LastPeriodLength;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL s32BeltSpeed_deg_sType bmm_s32BeltSpeed_deg_s;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL s32BeltSpeed_deg_sType bmm_s32BeltSpeed_SE_deg_s;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL s32BeltSpeed_mm_sType bmm_s32BeltSpeed_mm_s;

/**
 * \brief
 *		Variable used to store values passed by module services.
 * \remarks
 *		None.
 */
LOCAL s32BeltSpeed_deg_sType bmm_s32BeltSpeed_SE_mm_s;

/**
 * \brief
 *		Variable used in order to increase the timer value exponentially in case of belt deceleration.
 * \remarks
 *		None.
 */
LOCAL volatile uint32 bmm_u32LowSpeedHwCounterTotalOffset = KU32_ZERO;

/**
 * \brief
 *		Variable used in order to increase the timer value exponentially in case of belt deceleration.
 * \remarks
 *		None.
 */
LOCAL volatile uint32 bmm_u32LowSpeedSEHwCounterTotalOffset = KU32_ZERO;

/**
 * \brief
 *		Variable used to cap the timer value in case of belt deceleration.
 * \remarks
 *		None.
 */
LOCAL volatile uint32 bmm_u32StaticNextPeriodLength = KU32_ZERO;

/**
 * \brief
 *		Variable used to cap the timer value in case of belt deceleration.
 * \remarks
 *		None.
 */
LOCAL volatile uint32 bmm_u32StaticSENextPeriodLength = KU32_ZERO;

#if (BMM_ENABLE_PYRO_DETECTION == 1)
/**
 * \brief
 *		The pyro firing detection flag.
 * \remarks
 *		None.
 */
LOCAL volatile b8PyroActivationStatusType bPyroDetected;

/**
 * \brief
 *		Local pyro device status.
 * \remarks
 *		None.
 */
LOCAL b8PyroActivationStatusType b8IsPyroActivated;

/**
 * \brief
 *		Count the number of consecutive times a period length has been below
 * 		the pyro speed detection threshold
 * \remarks
 *		None.
 */
LOCAL uint8 u8PyroDetectCnt;

/**
 * \brief
 *		BMM internal state base on hall effect sensor AEC
 * 		B_TRUE: HES pulse counting disabled => speed = 0 and belt position = the last value measured
 * 		B_FALSE: HES pulse counting enabled => nominal case
 * \remarks
 *		None.
 */
LOCAL uint8 u8BMMDowngradedState;

/**
 * \brief
 *		Count independently for each kind of input capture edge (regarding polarity
 * 		and sensor source) the number of times the timer has overflowed during the
 * 		period.
 * \remarks
 *		None.
 */
LOCAL volatile uint8 au8Overflows[KU8_NUMBER_OF_PERIOD_TYPES];

/**
 * \brief
 *		Expected type of period to be computed on next capture interrupt if the
 * 		displacement direction does not change.
 * \remarks
 *		None.
 */
LOCAL volatile bmm_PeriodTypesType u8NextPeriodType;

/**
 * \brief
 *		Semaphore to ensure the consistency of variables modified under interrupts
 * 		and read for speed evaluation.
 * \remarks
 *		None.
 */
LOCAL volatile boolean bNewEvent;

/**
 * \brief
 *		BMM internal state.
 * \remarks
 *		None.
 */
LOCAL bmm_stInternalStateType bmm_State = {Uninit, Uninit};

/**
 * \brief
 *		Check if all critical auto tests are done and passed.
 * \remarks
 *		None.
 */
LOCAL volatile boolean bCriticalNok = B_FALSE;
#endif

/**
 * \brief
 *		Used to check intervals on which to increase the timer value exponentially.
 * \remarks
 *		None.
 */
LOCAL volatile uint8 bmm_u8TimerConfigI = KU8_ZERO;

/**
 * \brief
 *		Used to check intervals on which to increase the timer value exponentially.
 * \remarks
 *		None.
 */
LOCAL volatile uint8 bmm_u8SETimerConfigI = KU8_ZERO;

/**
 * \brief
 *		Single edge algorithm data structure.
 * \remarks
 *		None.
 */
LOCAL volatile bmm_stSingleEdgeData stSingleEdgeData = {KU32_ZERO, KU16_ZERO, KU8_ZERO};

#if (BMM_ENABLE_MAX_POS_MONITORING == 1)
/**
 * \brief
 *		The lowest and highest value of s16CurrentPosition since reset.
 * \remarks
 *		None.
 */
LOCAL s16PositionType s16LowestPosition;

/**
 * \brief
 *		The lowest and highest value of s16CurrentPosition since reset.
 * \remarks
 *		None.
 */
LOCAL s16PositionType s16HighestPosition;
#endif

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/**
 * \brief
 *		Low speed config.
 * \remarks
 *		None.
 */
LOCAL volatile bmm_LowSpeedIncHwCounterType bmm_tTimerConfig[KU8_BMM_LOW_SPEED_INC_HW_COUNTER_NB_OF_INTERVALS] = {
      {KU32_BMM_LOW_SPEED_INC_HW_COUNTER_START_THRS_1, KU32_BMM_LOW_SPEED_INC_HW_COUNTER_STOP_THRS_1, KU32_BMM_LOW_SPEED_INC_HW_COUNTER_FACTOR_1},
      {KU32_BMM_LOW_SPEED_INC_HW_COUNTER_START_THRS_2, KU32_BMM_LOW_SPEED_INC_HW_COUNTER_STOP_THRS_2, KU32_BMM_LOW_SPEED_INC_HW_COUNTER_FACTOR_2},
};
/**
 * \brief
 *		Low speed config.
 * \remarks
 *		None.
 */
LOCAL volatile bmm_LowSpeedIncHwCounterType bmm_tSETimerConfig[KU8_BMM_LOW_SPEED_SE_INC_HW_COUNTER_NB_OF_INTERVALS] = {
      {KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_START_THRS_1, KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_STOP_THRS_1, KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_FACTOR_1},
      {KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_START_THRS_2, KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_STOP_THRS_2, KU32_BMM_LOW_SPEED_SE_INC_HW_COUNTER_FACTOR_2},
};


/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

/**
* \brief
*     Sub function to increment or decrement current position on hall
*     sensor edge. Detect Highest and lowest position exceeding and
*     update if necessary.
* \param
*     u8HSLevel = The hall output level to be considered
*                 (STD_LOW / STD_HIGH).
*     u8ReleaseValue = The expected output level for release direction
*                      (STD_LOW / STD_HIGH).
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     The just updated position.
**/
LOCAL sint16 bmm_UpdatePosition(const uint8 u8HSLevel, const uint8 u8ReleaseValue)
{
   sint16 s16Position = s16CurrentPosition;

   if (u8HSLevel == u8ReleaseValue)
   {
      /* This is a releasing move. */
      /* Update the current position in number of pulses */
      s16Position++;


#if (BMM_ENABLE_MAX_POS_MONITORING == 1)
      /* Check if lowest position since reset shall be updated with current position */\
      if (s16Position > s16HighestPosition)
      {
         s16HighestPosition = s16Position;
      }
      else
      {
        /* The highest position shall not be updated */
      }
#endif

   }
   else
   {
     /* This is a tensioning move: */
     /* Update the current position in number of pulses */
      s16Position--;

#if (BMM_ENABLE_MAX_POS_MONITORING == 1)
      /* Check if lowest position since reset shall be updated with current position */\
      if (s16Position < s16LowestPosition)
      {
         s16LowestPosition = s16Position;
      }
      else
      {
         /* The lowest position shall not be updated */
      }
#endif

   }
   s16CurrentPosition = s16Position;

   return s16Position;
}

/**
* \brief
*    Computes the belt displacement speed in degrees per seconds, or in millimetres per seconds.
* \param
*     ps32Speed: Pointer to write the bobbin rotation speed
*     s32SpeedFactor: multiplication factor used to compute the rotation speed
*      				in degrees per seconds, or in millimetres per seconds.
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
LOCAL void bmm_ReadSpeed(const sint32 s32SpeedFactor, sint32 * const ps32Speed)
{
   u32PeriodType u32LastPeriodLengthCopy;
   u32PeriodType u32NextPeriodLength;
   u32PeriodType u32LongestPeriod;
   uint32 u32NextPeriodTempSum;
   s16PositionType s16LastPeriodDisplacementCopy;
   uint16 u16Capture;
   uint8 u8OverFlowCnt;
   bmm_PeriodTypesType u8NextType;

   /* Redo speed evaluation if the timer overflow or the capture interrupt has occurred during the speed evaluation.
    * - Note : Disabling interrupts is not possible while this do not freeze the timer. However, the timer counter
    *          register value must be consistent with variables updated by interrupts */
   do
   {
      /* Clear the capture and overflow interrupt detection flag. */
      bNewEvent = B_FALSE;
      /* Get the bobbin rotation in steps corresponding to the last measured period. */
      s16LastPeriodDisplacementCopy = s16LastPeriodDisplacement;
      /* Make a copy of the last measured period, to be independent from interrupt preemption when using the value. */
      u32LastPeriodLengthCopy = u32LastPeriodLength;
      /* Any partial modification (inconsistency) is protected by this 'redo' loop. */
      /* Computes actual (partial) length of the expected next period. */
      u8NextType = u8NextPeriodType;
      u8OverFlowCnt = au8Overflows[u8NextType];
      u16Capture = au16Captures[u8NextType];
      u32NextPeriodLength = ((u8OverFlowCnt * HARD_TIMER_RANGE) + U16_COUNTER_VALUE) - u16Capture;

      if(u32NextPeriodLength > bmm_tTimerConfig[0u].u32LowSpeedStartIncHwCounterArr)
      {
         u32NextPeriodTempSum = (u32NextPeriodLength+(bmm_u32LowSpeedHwCounterTotalOffset+bmm_tTimerConfig[bmm_u8TimerConfigI].u32LowSpeedHwCounterFactor));

         if((u32NextPeriodLength > bmm_tTimerConfig[bmm_u8TimerConfigI].u32LowSpeedStartIncHwCounterArr) &&
               (u32NextPeriodTempSum < bmm_tTimerConfig[bmm_u8TimerConfigI].u32LowSpeedStopIncHwCounterArr))
         {
            bmm_u32LowSpeedHwCounterTotalOffset += bmm_tTimerConfig[bmm_u8TimerConfigI].u32LowSpeedHwCounterFactor;
            u32NextPeriodLength = u32NextPeriodTempSum;
            bmm_u32StaticNextPeriodLength = u32NextPeriodTempSum;
         }
         else if(u32NextPeriodLength < bmm_tTimerConfig[bmm_u8TimerConfigI].u32LowSpeedStopIncHwCounterArr)
         {
            if(bmm_u32StaticNextPeriodLength > u32NextPeriodLength)
            {
               u32NextPeriodLength = bmm_u32StaticNextPeriodLength;
            }
            if (((KU8_BMM_LOW_SPEED_INC_HW_COUNTER_NB_OF_INTERVALS-KU8_ONE) > bmm_u8TimerConfigI) &&
                 (u32NextPeriodLength >= bmm_tTimerConfig[bmm_u8TimerConfigI].u32LowSpeedStartIncHwCounterArr))
            {
               bmm_u8TimerConfigI++;
            }
         }
         else
         {
            /* do nothing */
         }
      }
      else
      {

         bmm_u32LowSpeedHwCounterTotalOffset = KU32_ZERO;
         bmm_u32StaticNextPeriodLength = KU32_ZERO;
         bmm_u8TimerConfigI = 0u;
      }

   }
   while (bNewEvent != B_FALSE);

   /* Consider the longest period among latest and in progress */
   if (u32NextPeriodLength > u32LastPeriodLengthCopy)
   {
      u32LongestPeriod = u32NextPeriodLength;
   }
   else
   {
      u32LongestPeriod = u32LastPeriodLengthCopy;
   }
   /* Robustness: unexpected case where the period duration is null */
   if (KU32_ZERO == u32LongestPeriod)
   {
      /* Force null displacement then null speed and avoid null division */
      s16LastPeriodDisplacementCopy = KS16_NULL_DT_POSITION_IN_PERIOD;
   }
   else
   {
      /* Let the division by u32LongestPeriod to be done */
   }

   /* Service usage : ps32Speed argument always point a container for speed result. */
   switch (s16LastPeriodDisplacementCopy)
   {
   case KS16_RELEASE_DT_POSITION_IN_PERIOD:
      /* Even if they are signed, operands of the division are positive. */
      /* Computes the positive speed (for releasing) from the most relevant period between last and next one. */
      *ps32Speed = s32SpeedFactor / ((sint32)u32LongestPeriod);
      break;

   case KS16_TENSION_DT_POSITION_IN_PERIOD:
      /* Even if they are signed, operands of the division are positive. */
      /* Computes the negative speed (for tensioning) from the most relevant period between last and next one. */
      *ps32Speed = -(s32SpeedFactor / ((sint32)u32LongestPeriod));
      break;

   default:
      /* The direction moving was not constant during the last period and shall be confirmed (oscillation or direction change)
       * Consider the speed as null */
      *ps32Speed = 0;
      break;
   }

   /* Check if the BMM downgraded state is set */
   if( B_TRUE == u8BMMDowngradedState )
   {
      /* Return a speed value of 0 */
      *ps32Speed = 0;
   }
   else
   {
      /* Keep the computed one */
   }
}

/**
* \brief
*     Function will return the speed for a single edge
* \param
*     ps32Speed: Pointer to write the bobbin rotation speed
*     s32SpeedFactor: multiplication factor used to compute the rotation speed
*      				in degrees per seconds, or in millimetres per seconds.
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
LOCAL void bmm_ReadSpeedSingleEdge(const sint32 s32SpeedFactor, sint32 * const ps32Speed)
{
   u32PeriodType u32LastPeriodLengthCopy;
   u32PeriodType u32NextPeriodLength;
   u32PeriodType u32LongestPeriod;
   uint32 u32NextPeriodTempSum;
   s16PositionType s16LastPeriodDisplacementCopy;
   uint16 u16Capture;
   uint8 u8OverFlowCnt;
   /* Redo speed evaluation if the timer overflow or the capture interrupt has occurred during the speed evaluation.
    * - Note : Disabling interrupts is not possible while this do not freeze the timer. However, the timer counter
    *          register value must be consistent with variables updated by interrupts */
   do
   {
      /* Clear the capture and overflow interrupt detection flag. */
      bNewEvent = B_FALSE;
      /* Get the bobbin rotation in steps corresponding to the last measured period. */
      s16LastPeriodDisplacementCopy = s16LastPeriodDisplacement;
      /* Make a copy of the last measured period, to be independent from interrupt preemption when using the value. */
      u32LastPeriodLengthCopy = stSingleEdgeData.u32CurrentPeriod;
      /* Any partial modification (inconsistency) is protected by this 'redo' loop. */
      /* Computes actual (partial) length of the expected next period. */
      u8OverFlowCnt = stSingleEdgeData.u8TmrOvfl;
      u16Capture = stSingleEdgeData.u16TmrVal;

      u32NextPeriodLength = ((u8OverFlowCnt * HARD_TIMER_RANGE) + U16_COUNTER_VALUE) - u16Capture;

      if(u32NextPeriodLength > bmm_tSETimerConfig[0u].u32LowSpeedStartIncHwCounterArr)
      {
         u32NextPeriodTempSum = (u32NextPeriodLength+(bmm_u32LowSpeedSEHwCounterTotalOffset+bmm_tSETimerConfig[bmm_u8SETimerConfigI].u32LowSpeedHwCounterFactor));

         if((u32NextPeriodLength > bmm_tSETimerConfig[bmm_u8SETimerConfigI].u32LowSpeedStartIncHwCounterArr) &&
               (u32NextPeriodTempSum < bmm_tSETimerConfig[bmm_u8SETimerConfigI].u32LowSpeedStopIncHwCounterArr))
         {
            bmm_u32LowSpeedSEHwCounterTotalOffset += bmm_tSETimerConfig[bmm_u8SETimerConfigI].u32LowSpeedHwCounterFactor;
            u32NextPeriodLength = u32NextPeriodTempSum;
            bmm_u32StaticSENextPeriodLength = u32NextPeriodTempSum;
         }
         else if(u32NextPeriodLength < bmm_tSETimerConfig[bmm_u8SETimerConfigI].u32LowSpeedStopIncHwCounterArr)
         {
            if(bmm_u32StaticSENextPeriodLength > u32NextPeriodLength)
            {
               u32NextPeriodLength = bmm_u32StaticSENextPeriodLength;
            }
            if (((KU8_BMM_LOW_SPEED_SE_INC_HW_COUNTER_NB_OF_INTERVALS-KU8_ONE) > bmm_u8SETimerConfigI) &&
                  (u32NextPeriodLength >= bmm_tSETimerConfig[bmm_u8SETimerConfigI].u32LowSpeedStartIncHwCounterArr))
            {
               bmm_u8SETimerConfigI++;
            }
         }
         else
         {
            /* do nothing */
         }
      }
      else
      {

         bmm_u32LowSpeedSEHwCounterTotalOffset = KU32_ZERO;
         bmm_u32StaticSENextPeriodLength = KU32_ZERO;
         bmm_u8SETimerConfigI = 0u;
      }

   }
   while (bNewEvent != B_FALSE);

   /* Consider the longest period among latest and in progress */
   if (u32NextPeriodLength > u32LastPeriodLengthCopy)
   {
      u32LongestPeriod = u32NextPeriodLength;
   }
   else
   {
      u32LongestPeriod = u32LastPeriodLengthCopy;
   }
   /* Robustness: unexpected case where the period duration is null */
   if (KU32_ZERO == u32LongestPeriod)
   {
      /* Force null displacement then null speed and avoid null division */
      s16LastPeriodDisplacementCopy = KS16_NULL_DT_POSITION_IN_PERIOD;
   }
   else
   {
      /* Let the division by u32LongestPeriod to be done */
   }

   /* Service usage : ps32Speed argument always point a container for speed result. */
   switch (s16LastPeriodDisplacementCopy)
   {
   case KS16_RELEASE_DT_POSITION_IN_PERIOD:
      /* Even if they are signed, operands of the division are positive. */
      /* Computes the positive speed (for releasing) from the most relevant period between last and next one. */
      *ps32Speed = s32SpeedFactor / ((sint32)u32LongestPeriod);
      break;

   case KS16_TENSION_DT_POSITION_IN_PERIOD:
      /* Even if they are signed, operands of the division are positive. */
      /* Computes the negative speed (for tensioning) from the most relevant period between last and next one. */
      *ps32Speed = -(s32SpeedFactor / ((sint32)u32LongestPeriod));
      break;

   default:
      /* The direction moving was not constant during the last period and shall be confirmed (oscillation or direction change)
       * Consider the speed as null */
      *ps32Speed = 0;
      break;
   }

   /* Check if the BMM downgraded state is set */
   if( B_TRUE == u8BMMDowngradedState )
   {
      /* Return a speed value of 0 */
      *ps32Speed = 0;
   }
   else
   {
      /* Keep the computed one */
   }
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
* \brief
*     Interrupt triggered at each edge transition
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0021] */
void OS_ISR_BMM_HES_IT(void)
{
   uint16 u16Capture;
   sint16 s16Pos;
   uint8 u8StateA;
   uint8 u8StateB;
   static uint8 u8PrevStateA=0xFF;
   static uint8 u8PrevStateB=0xFF;

   /* Retrieve hall sensors outputs levels */
   u8StateA = DIO_HALL_A;
   u8StateB = DIO_HALL_B;

   /* Get Counter value */
   u16Capture = U16_COUNTER_VALUE_STATIC;

   /* Hall A interrupt (FTM1 CH6) - Rising edge */
   if( u8PrevStateA != u8StateA )
   {
	   u8PrevStateA = u8StateA;
      /* Predict next capture type if the direction do not change */
      /* and deduce the new current position */
      if ((uint8)STD_HIGH == u8StateB)
      {
         /* If current state is high, it may fall */
         u8NextPeriodType = KU8_FALLING_B;
         s16Pos = bmm_UpdatePosition(u8StateA, (uint8)STD_HIGH);
      }
      else
      {
         /* If current state is low, it may raise */
         u8NextPeriodType = KU8_RISING_B;
         s16Pos = bmm_UpdatePosition(u8StateA, (uint8)STD_LOW);
      }

      /* Process rising and falling edge separately */
      if ((uint8)STD_HIGH == u8StateA)
      {
         /* This is a falling edge capture: */
         /* QAC_WARNING S 3345 4 */ /* Statement contains more than one access to objects that are volatile. */
                             /* Not applicable while this interrupt function has highest priority among the users of concerned variables */
         /* The kind of period is rising edge on input capture A. */
         /* Computes the length of the just finished period */
         u32LastPeriodLength = (((au8Overflows[KU8_RISING_A] * HARD_TIMER_RANGE) + u16Capture) - au16Captures[KU8_RISING_A]);
         /* Remember the beginning position of this last finished period. */
         s16LastPeriodDisplacement = s16Pos - as16Positions[KU8_RISING_A];                                                                \
         /* Remember the data to be associated to the new period beginning (The belt position & the timer capture) */
         /* and reinitialize the overflow counter for new starting period */
         as16Positions[KU8_RISING_A] = s16Pos;
         au16Captures[KU8_RISING_A] = u16Capture;
         au8Overflows[KU8_RISING_A] = KU8_ZERO;
      }
      else
      {
         /* This is a falling edge capture: */
         /* QAC_WARNING S 3345 4 */ /* Statement contains more than one access to objects that are volatile. */
                             /* Not applicable while this interrupt function has highest priority among the users of concerned variables */
         /* The kind of period is falling edge on input capture A. */
         /* Computes the length of the just finished period */
         u32LastPeriodLength = (((au8Overflows[KU8_FALLING_A] * HARD_TIMER_RANGE) + u16Capture) - au16Captures[KU8_FALLING_A]);
         /* Remember the beginning position of this last finished period. */
         s16LastPeriodDisplacement = s16Pos - as16Positions[KU8_FALLING_A];                                                                \
         /* Remember the data to be associated to the new period beginning (The belt position & the timer capture) */
         /* and reinitialize the overflow counter for new starting period */
         as16Positions[KU8_FALLING_A] = s16Pos;
         au16Captures[KU8_FALLING_A] = u16Capture;
         au8Overflows[KU8_FALLING_A] = KU8_ZERO;
      }
   }
   else
   {
      /* Other Channel IT */
   }

   /* Hall B interrupt (FTM1 CH7) - Rising edge */
   if( u8PrevStateB != u8StateB )
   {
	   u8PrevStateB = u8StateB;
      /* Predict next capture type if the direction do not change */
      /* and deduce the new current position */
      if ((uint8)STD_HIGH == u8StateA)
      {
         /* If current state is high, it may fall */
         u8NextPeriodType = KU8_FALLING_A;
         s16Pos = bmm_UpdatePosition(u8StateB, (uint8)STD_LOW);
      }
      else
      {
         /* If current state is low, it may raise */
         u8NextPeriodType = KU8_RISING_A;
         s16Pos = bmm_UpdatePosition(u8StateB, (uint8)STD_HIGH);
      }
      /* Process rising and falling edge separately */
      if ((uint8)STD_HIGH == u8StateB)
      {
         /* This is a rising edge capture: */
         /* QAC_WARNING S 3345 4 */ /* Statement contains more than one access to objects that are volatile. */
                             /* Not applicable while this interrupt function has highest priority among the users of concerned variables */
         /* The kind of period is rising edge on input capture B. */
         /* Computes the length of the just finished period */
         u32LastPeriodLength = (((au8Overflows[KU8_RISING_B] * HARD_TIMER_RANGE) + u16Capture) - au16Captures[KU8_RISING_B]);
         /* Remember the beginning position of this last finished period. */
         s16LastPeriodDisplacement = s16Pos - as16Positions[KU8_RISING_B];                                                                \
         /* Remember the data to be associated to the new period beginning (The belt position & the timer capture) */
         /* and reinitialize the overflow counter for new starting period */
         as16Positions[KU8_RISING_B] = s16Pos;
         au16Captures[KU8_RISING_B] = u16Capture;
         au8Overflows[KU8_RISING_B] = KU8_ZERO;
      }
      else
      {
         /* This is a falling edge capture: */
         /* QAC_WARNING S 3345 4 */ /* Statement contains more than one access to objects that are volatile. */
                            /* Not applicable while this interrupt function has highest priority among the users of concerned variables */
         /* The kind of period is falling edge on input capture B. */
         /* Computes the length of the just finished period */
         u32LastPeriodLength = (((au8Overflows[KU8_FALLING_B] * HARD_TIMER_RANGE) + u16Capture) - au16Captures[KU8_FALLING_B]);
         /* Remember the beginning position of this last finished period. */
         s16LastPeriodDisplacement = s16Pos - as16Positions[KU8_FALLING_B];                                                                \
         /* Remember the data to be associated to the new period beginning (The belt position & the timer capture) */
         /* and reinitialize the overflow counter for new starting period */
         as16Positions[KU8_FALLING_B] = s16Pos;
         au16Captures[KU8_FALLING_B] = u16Capture;
         au8Overflows[KU8_FALLING_B] = KU8_ZERO;
      }
   }
   else
   {
      /* Other Channel IT */
   }

   /* Single edge algo ran on both ISR */
   stSingleEdgeData.u32CurrentPeriod = (((stSingleEdgeData.u8TmrOvfl * HARD_TIMER_RANGE) + u16Capture) - stSingleEdgeData.u16TmrVal);
   stSingleEdgeData.u16TmrVal = u16Capture;
   stSingleEdgeData.u8TmrOvfl = KU8_ZERO;

#if (BMM_ENABLE_PYRO_DETECTION == 1)
   if (bCriticalNok == B_TRUE)
      {
	   /* Compare this period to the pyro detection threshold */
	   if (u32LastPeriodLength >= u16CplTimerCntThrs)
	   {
		   /* Reset the number of consecutive pyro low periods */

		   u8PyroDetectCnt = KU8_ZERO;

	   }
	   /* Pyro low period recognized: */
	   /* Check the number of previous pryro recognitions */
	   else if (u8PyroDetectCnt >= KU8_REQUIRED_NB_OF_PYRO_DETECT)
	   {
		   /* Enough consecutive pyro low periods have be recognized
       * to validate the pyro firing detection. */
      bPyroDetected = KB8_PYRO_DEVICE_ACTIVATED;
   }
   else
   {
      /* Count this pyro low period recognition */
      u8PyroDetectCnt++;
   }
      }
#endif
   /* Notify the the variable update under interrupts. */
   bNewEvent = B_TRUE;
}

/**
* \brief
*     Interrupt triggered at Timer 5 overflow
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0022] */
void OS_ISR_BMM_HES_TOUT(void)
{
	/* Update the overflow counter associated to each type of counter.
	* Note : Even if a 4 occurrences loop is possible, prefer 4 distinct update
	* for minimum CPU load under interrupt. */
	if (KU8_MAX > au8Overflows[KU8_RISING_A])
	{
	 au8Overflows[KU8_RISING_A]++;
	}
	else
	{
	 /* While the overflow counter is already saturated, do not increment it */
	}
	if (KU8_MAX > au8Overflows[KU8_FALLING_A])
	{
	 au8Overflows[KU8_FALLING_A]++;
	}
	else
	{
	 /* While the overflow counter is already saturated, do not increment it */
	}
	if (KU8_MAX > au8Overflows[KU8_RISING_B])
	{
	 au8Overflows[KU8_RISING_B]++;
	}
	else
	{
	 /* While the overflow counter is already saturated, do not increment it */
	}
	if (KU8_MAX > au8Overflows[KU8_FALLING_B])
	{
	 au8Overflows[KU8_FALLING_B]++;
	}
	else
	{
	 /* While the overflow counter is already saturated, do not increment it */
	}

	/* Single edge algo overflow management  */
	if (KU8_MAX > stSingleEdgeData.u8TmrOvfl)
	{
	 stSingleEdgeData.u8TmrOvfl++;
	}
	else
	{
	 /* While the overflow counter is already saturated, do not increment it */
	}

	/* Notify the the variable update under interrupts. */
	bNewEvent = B_TRUE;
}


/**
* \brief
*     Cyclic function of the module, its scope is to verify the electronic integrity of the HAL sensors.
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
EXPORTED void BMM_runMainFunction(void)
{
   uint16 u16FilteredHESAInputVoltage_lsb;
   uint16 u16FilteredHESBInputVoltage_lsb;
   uint8 u8HesState = BMM_SENSORS_OK;
   b8IsCarCrashDetectedType b8CarCrashStatus;
   uint8 u8CriticalMode;

   /* Check both Hall sensors speratly and update BMM state based on the result */
   /* Get the filtered physical value measured of Hall Effect Sensor A from ASM */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Call_pclHBS_A_V_raw_Get_100ms (& u16FilteredHESAInputVoltage_lsb);

   /* Get the filtered physical value measured of Hall Effect Sensor B from ASM */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Call_pclHBS_B_V_raw_Get_100ms (& u16FilteredHESBInputVoltage_lsb);

   if( (u16FilteredHESAInputVoltage_lsb > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestHighThrs) ||
       (u16FilteredHESAInputVoltage_lsb <= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestLowThrs) )
   {
      /* One of the HES input voltage is out of range : return NOK */
      u8HesState |= BMM_HALL_A_ERROR;
   }
   else
   {
      /* Nothind to do */
   }
   

   if( (u16FilteredHESBInputVoltage_lsb > NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestHighThrs) ||
       (u16FilteredHESBInputVoltage_lsb <= NVP_BLOCK_ID_TESTS_PARAM_RamBlockData.NVP_u16HESTestLowThrs) )
   {
      u8HesState |= BMM_HALL_B_ERROR;
   }
   else
   {
      /* Nothing to do */
   }

   /* BMM FSM */
   switch (u8HesState)
   {
   case BMM_SENSORS_OK:
      bmm_State.eCurrent = Run;

      if( bmm_State.eCurrent != bmm_State.ePrevious )
      {
         /* Check previous state to recover the pulse monitoring on the correct hall sensor */
         if( Downgraded_Hall_A == bmm_State.ePrevious )
         {

         }
         else if ( Downgraded_Hall_B == bmm_State.ePrevious )
         {

         }
         else if ( Shutdown == bmm_State.ePrevious )
         {

         }
         else
         {
            /* Nothing to do, impossible case or memory corruption */
         }
      }
      else
      {
         /* Nothing to do */
      }
      break;

   case BMM_HALL_A_ERROR:
      bmm_State.eCurrent = Downgraded_Hall_A;

      break;

   case BMM_HALL_B_ERROR:
      bmm_State.eCurrent = Downgraded_Hall_B;

      break;

   case BMM_BOTH_SENSORS_ERROR:
      bmm_State.eCurrent = Shutdown;

      break;
   default:
      bmm_State.eCurrent = Shutdown;
      break;
   }

   bmm_State.ePrevious = bmm_State.eCurrent;

   Rte_Call_pclModeManagement_CheckModeStatus(MMG_KU32_MASK_CRITICAL_AT_NOK, &u8CriticalMode);
   if(KU8_MODE_STATUS_OFF == u8CriticalMode)
   {
   bCriticalNok = B_TRUE;
   }
}

/**
* \brief
*     Function will initialize the module variables and used HW
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0006] */
EXPORTED void BMM_runInit(void)
{
   u8BMMDowngradedState = B_FALSE;
   s16LowestPosition = KS16_ZERO;
   s16HighestPosition = KS16_ZERO;
   bPyroDetected = KU8_ZERO;
   b8IsPyroActivated = KU8_ZERO;
   s16LowestPosition = KS16_ZERO;
   s16HighestPosition = KS16_ZERO;

   /* Initialize position management variables */
   s16CurrentPosition = KS16_ZERO;
   s16LastPeriodDisplacement = KS16_ZERO;

   /* Initialize data of rising A period measure */
   as16Positions[KU8_RISING_A] = KS16_ZERO;
   au16Captures[KU8_RISING_A] = KU16_ZERO;
   au8Overflows[KU8_RISING_A] = KU8_ZERO;

   /* Initialize data of falling A period measure */
   as16Positions[KU8_FALLING_A] = KS16_ZERO;
   au16Captures[KU8_FALLING_A] = KU16_ZERO;
   au8Overflows[KU8_FALLING_A] = KU8_ZERO;

   /* Initialize data of rising B period measure */
   as16Positions[KU8_RISING_B] = KS16_ZERO;
   au16Captures[KU8_RISING_B] = KU16_ZERO;
   au8Overflows[KU8_RISING_B] = KU8_ZERO;

   /* Initialize data of falling B period measure */
   as16Positions[KU8_FALLING_B] = KS16_ZERO;
   au16Captures[KU8_FALLING_B] = KU16_ZERO;
   au8Overflows[KU8_FALLING_B] = KU8_ZERO;

   /* Initialize the last completed period duration (value does not matter while the belt move will not be 4 steps) */
   u32LastPeriodLength = KU32_ZERO;

   /* Initialization of expected next period information to valid type of period
    * from value range point of view [0..3] in the case it was used as array index in the
    * "ReadSpeed" service before first modification under capture interrupt.
    * On the other side, if it can't be predicted at initialization among the 4 types of
    * period, an arbitrary initialization does not matter while the belt move will not be
    * 4 steps (4 capture interrupts) and while the speed will be then forced to zero. */
   u8NextPeriodType = KU8_RISING_A;

#if (BMM_ENABLE_PYRO_DETECTION == 1)

   /* By default, pyro has not been detected yet */
   bPyroDetected = KB8_PYRO_DEVICE_NOT_ACTIVATED;
   b8IsPyroActivated  = KB8_PYRO_DEVICE_NOT_ACTIVATED;
   u8PyroDetectCnt = KU8_ZERO;

   /* Adapt Ecpl Bobbin Speed Threshold from microseconds (NVP parameter format) to the timer scale (timer counter lsb).
    * - Note intermediate operation performed on 32 bits, allowing any 16 bits NVP parameter value without overflow
    *   during the multiplication. */
   u16CplTimerCntThrs = (uint16)(((uint32)CALIB_BLOCK_ID_ECPL_OTHER_PARAM_RomBlockData.NVP_u16CplBobbinSpeedThrs * KU32_NB_LSB_IN_MS) / KU32_NB_US_IN_MS);
#endif

   /* initialize all single edge data field to 0 */
   stSingleEdgeData.u32CurrentPeriod = KU32_ZERO;
   stSingleEdgeData.u16TmrVal = KU16_ZERO;
   stSingleEdgeData.u8TmrOvfl = KU8_ZERO;

   /* Set pin P02.6 as ALT5 - GPT120_T3INA */
   Port_SetPinMode(PortConf_PortContainer_2_PORT_2_PIN_6, PORT_PIN_MODE_ALT5);

   /* Set pin P02.7 as ALT5 - GPT120_T3EUDA */
   Port_SetPinMode(PortConf_PortContainer_2_PORT_2_PIN_7, PORT_PIN_MODE_ALT5);

   /* Timer T3 in Incremental Interface Mode (Edge Detection Mode) */
   GPT120_T3CON.B.T3M = 7;

   /* Any transition (rising or falling edge) on any Tx input (TxIN or TxEUD). */
   GPT120_T3CON.B.T3I = 3;

   /* Enable automatic external direction control */
   GPT120_T3CON.B.T3UDE = 1;

   /* T5 prescaler = 2048 => 25.6us per counter tick */
   GPT120_T6CON.B.BPS2 = 3;
   GPT120_T5CON.B.T5I = 4;

   /* Capture into register CAPREL enabled */
   GPT120_T5CON.B.T5SC = 1;

   /* Timer counts up */
   GPT120_T5CON.B.T5UD = 0;

   /* Capture trigger from T3 input lines T3IN and/or T3EUD */
   GPT120_T5CON.B.CT3 = 1;

   /* Any transition (rising or falling edge) on T3IN or T3EUD */
   GPT120_T5CON.B.CI = 3;

   /* Start timers */
   GPT120_T3CON.B.T3R = 1;
   GPT120_T5CON.B.T5R = 1;

   /* Enable interrupt */
   SRC_GPT120T5.B.SRE = 1;
   SRC_GPT120CIRQ.B.SRE = 1;

   /* Module initialization completed */
   bmm_State.eCurrent = Run;
}


#if (BMM_ENABLE_PYRO_DETECTION == 1)

/**
* \brief
*     Function will get the pyro activation status
* \param
*     b8PyroActivationStatusType * pb8PyroActivationStatus: pointer to the pyro activation status
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
EXPORTED void BMM_runGetPyroActivationStatus(b8PyroActivationStatusType * pb8PyroActivationStatus)
{
   /* Check the pyro evaluation made under interrupt */
      if (KB8_PYRO_DEVICE_ACTIVATED == bPyroDetected)
      {
         b8IsPyroActivated = KB8_PYRO_DEVICE_ACTIVATED;

         /* Acknowledge the pyro. detection indication */
         u8PyroDetectCnt = KU8_ZERO;
         bPyroDetected = KB8_PYRO_DEVICE_NOT_ACTIVATED;
      }
      else
      {
        /* Pyro activation has not been detected by interrupts */
      }

      /* Return the appropriate value */
      /* QAC_WARNING S 0506 8 */ /* Possible dereference of NULL pointer. */
                         /* Use of this service assumes that the argument points an instantiated variable */
      *(pb8PyroActivationStatus) = b8IsPyroActivated;
}

#endif

/**
* \brief
*     Function will get the position from T0 in degrees
* \param
*     s16BeltPosition_degType * ps16BeltPosition_deg: pointer to the returned value
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0008] */
EXPORTED void BMM_runGetPositionFromT0_deg(s16BeltPosition_degType * ps16BeltPosition_deg)
{
   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 360) / (36 * 2) = 10800.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   /* Converts current position from edge count to degrees */
   bmm_s16BeltPositionFromT0_deg = (sint16)(((sint32)s16CurrentPosition * (sint32)KS16_NB_DEGREES_PER_TURN) / ((sint32)KS16_NB_PAIRS_OF_POLES_CFG * (sint32)KS16_NB_PULSE_PER_PERIOD));
   *ps16BeltPosition_deg = bmm_s16BeltPositionFromT0_deg;
}

/**
* \brief
*     Function will get the position from T0 in mm
* \param
*     s16BeltPosition_mmType * ps16BeltPosition_mm: pointer to the returned value
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0009] */
EXPORTED void BMM_runGetPositionFromT0_mm(s16BeltPosition_mmType * ps16BeltPosition_mm)
{
   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 168) / (36 * 2) = 5040.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   /* Converts current position from edge count to degrees */
   bmm_s16BeltPositionFromT0_mm  = (sint16)(((sint32)s16CurrentPosition * (sint32)BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG) / ((sint32)KS16_NB_PAIRS_OF_POLES_CFG * (sint32)KS16_NB_PULSE_PER_PERIOD));
   *ps16BeltPosition_mm = bmm_s16BeltPositionFromT0_mm;
}

#if (BMM_ENABLE_MAX_POS_MONITORING == 1)

/**
* \brief
*     Function will get the the minimum position in deg
* \param
*     s16BeltPosition_degType * ps16BeltPosition_deg: pointer to the returned value
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0010] */
EXPORTED void BMM_runGetPositionFromMinPos_deg(s16BeltPosition_degType * ps16BeltPosition_deg)
{
   /* Copy of current and lowest positions */
   sint16 s16LowPos;
   sint16 s16CurPos;

   /* Loop until the two variables used for computation are stable and consistent with each other,
    * considering the risk that a capture interrupt could modify both variable between their
    * respective use. */
   do
   {
      s16CurPos = s16CurrentPosition;
      s16LowPos = s16LowestPosition;
   }
   while (s16CurPos != s16CurrentPosition);

   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 360) / (36 * 2) = 10800.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   bmm_s16BeltPositionFromMinPos_deg = (sint16)( ( ((sint32)s16CurPos - s16LowPos) * KS16_NB_DEGREES_PER_TURN) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
   *ps16BeltPosition_deg = bmm_s16BeltPositionFromMinPos_deg;
}

/**
* \brief
*     Function will get the the minimum position in mm
* \param
*     s16BeltPosition_mmType * ps16BeltPosition_mm: pointer to the returned value
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0011] */
EXPORTED void BMM_runGetPositionFromMinPos_mm(s16BeltPosition_mmType * ps16BeltPosition_mm)
{
   /* Copy of current and lowest positions */
   sint16 s16LowPos;
   sint16 s16CurPos;

   /* Loop until the two variables used for computation are stable and consistent with each other,
    * considering the risk that a capture interrupt could modify both variable between their
    * respective use. */
   do
   {
      s16CurPos = s16CurrentPosition;
      s16LowPos = s16LowestPosition;
   }
   while (s16CurPos != s16CurrentPosition);

   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 168) / (36 * 2) = 5040.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   bmm_s16BeltPositionFromMinPos_mm = (sint16)( ( ((sint32)s16CurPos - s16LowPos) * BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
   *ps16BeltPosition_mm = bmm_s16BeltPositionFromMinPos_mm;
}

/***************************************************************************
Label:
Object: Computes the minimum and maximum positions in degrees
Parameters: ps16BeltRelativePosition_deg: Pointer to write the belt bobbin displacement in millimeters

Return: NA
[COVERS: DSG_BMM_00013]
***********************************************************************/
EXPORTED void BMM_runGetPositionRange_deg(s16BeltPosition_degType * ps16BeltPosition_min_deg, s16BeltPosition_degType * ps16BeltPosition_max_deg)
{
   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 360) / (36 * 2) = 10800.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   bmm_s16BeltPosition_min_deg = (sint16)(((sint32)s16LowestPosition * KS16_NB_DEGREES_PER_TURN) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
   bmm_s16BeltPosition_max_deg = (sint16)(((sint32)s16HighestPosition * KS16_NB_DEGREES_PER_TURN) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
   *ps16BeltPosition_min_deg = bmm_s16BeltPosition_min_deg;
   *ps16BeltPosition_max_deg = bmm_s16BeltPosition_max_deg;
}

/**
* \brief
*     Function will get the min and max value of the belt in mm
* \param
*     s16BeltPosition_mmType * ps16BeltPosition_min_mm: pointer to the min value
* \param
*     s16BeltPosition_mmType * ps16BeltPosition_max_mm: pointer to the max value
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0014, DSG_BMM_0015] */
EXPORTED void BMM_runGetPositionRange_mm(s16BeltPosition_mmType * ps16BeltPosition_min_mm, s16BeltPosition_mmType * ps16BeltPosition_max_mm)
{
   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 168) / (36 * 2) = 5040.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   bmm_s16BeltPosition_min_mm = (sint16)(((sint32)s16LowestPosition * BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
   bmm_s16BeltPosition_max_mm = (sint16)(((sint32)s16HighestPosition * BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
   *ps16BeltPosition_min_mm = bmm_s16BeltPosition_min_mm;
   *ps16BeltPosition_max_mm = bmm_s16BeltPosition_max_mm;
}
#endif

/**
* \brief
*     Function will compute current belt speed in deg
* \param
*     s32BeltSpeed_deg_sType * ps32BeltSpeed_deg_s: pointer to the speed value
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0016] */
EXPORTED void BMM_runGetSpeed_deg_s(s32BeltSpeed_deg_sType * ps32BeltSpeed_deg_s)
{
   sint32 s32TestLocalBeltSpeed = KS32_ZERO;

   bmm_ReadSpeed((KS16_NB_DEGREES_PER_TURN * KS32_NB_LSB_IN_S) / KS16_NB_PAIRS_OF_POLES_CFG, &bmm_s32BeltSpeed_deg_s);
   bmm_ReadSpeedSingleEdge((KS16_NB_DEGREES_PER_TURN * KS32_NB_LSB_IN_S_SINGLE_EDGE) / KS16_NB_PAIRS_OF_POLES_CFG, &bmm_s32BeltSpeed_SE_deg_s);
   if((bmm_s32BeltSpeed_deg_s == 0) && (bmm_s32BeltSpeed_SE_deg_s != 0))
   {
      s32TestLocalBeltSpeed = bmm_s32BeltSpeed_SE_deg_s;
   }
   else
   {
      s32TestLocalBeltSpeed = bmm_s32BeltSpeed_deg_s;
   }

   *ps32BeltSpeed_deg_s = s32TestLocalBeltSpeed;
}

/**
* \brief
*     Function will compute current belt speed from single edge in deg
* \param
*     s32BeltSpeed_deg_sType* ps32BeltSpeed_SE_deg_s: pointer to the speed value
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0029] */
EXPORTED void BMM_runGetSpeed_SingleEdge_deg_s (P2VAR(s32BeltSpeed_deg_sType, AUTOMATIC, RTE_APPL_DATA) ps32BeltSpeed_SE_deg_s)
{
   bmm_ReadSpeedSingleEdge((KS16_NB_DEGREES_PER_TURN * KS32_NB_LSB_IN_S_SINGLE_EDGE) / KS16_NB_PAIRS_OF_POLES_CFG, &bmm_s32BeltSpeed_SE_deg_s);
   *ps32BeltSpeed_SE_deg_s = bmm_s32BeltSpeed_SE_deg_s;
}

/**
* \brief
*     Function will compute current belt speed in mm
* \param
*     s32BeltSpeed_mm_sType * ps32BeltSpeed_mm_s: pointer to the value
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0017] */
EXPORTED void BMM_runGetSpeed_mm_s(s32BeltSpeed_mm_sType * ps32BeltSpeed_mm_s)
{
   sint32 s32LocalBeltSpeed = KS32_ZERO;

   bmm_ReadSpeed((BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG * KS32_NB_LSB_IN_S) / KS16_NB_PAIRS_OF_POLES_CFG, &bmm_s32BeltSpeed_mm_s);

   bmm_ReadSpeedSingleEdge((BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG * KS32_NB_LSB_IN_S_SINGLE_EDGE) / KS16_NB_PAIRS_OF_POLES_CFG, &bmm_s32BeltSpeed_SE_mm_s);

   if((bmm_s32BeltSpeed_mm_s == 0) && (bmm_s32BeltSpeed_SE_mm_s != 0))
   {
      s32LocalBeltSpeed = bmm_s32BeltSpeed_SE_mm_s;
   }
   else
   {
      s32LocalBeltSpeed = bmm_s32BeltSpeed_mm_s;
   }

   *ps32BeltSpeed_mm_s = s32LocalBeltSpeed;
}

/**
* \brief
*     Function will disable the HEs monitoring
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0019] */
EXPORTED void BMM_runDisableHBSMonitoring ( void )
{   
   /* Set the BMM state to downgraded */
   u8BMMDowngradedState = B_TRUE;
}

/**
* \brief
*     Function will enable the HES monitoring
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_BMM_0020] */
EXPORTED void BMM_runEnableHBSMonitoring ( void )
{
   /* Set the BMM state back to normal */
   u8BMMDowngradedState = B_FALSE;
}

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/
