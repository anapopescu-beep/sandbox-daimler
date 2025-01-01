/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

COMPONENT BRS

Current revision: $Revision: 1.1 $
Checked in:       $Date: 2021/10/04 07:14:25CEST $

**************************************************************************

Overview of the component :
   Evaluates the belt Displacement (in millimeters and in degrees of the
   bobbin rotation) and the belt speed (in millimeters per seconds and
   in degrees of the bobbin rotation per seconds).

------------------------------------------------------------------------
*************************************************************************/

/*************************************************************************
Packages inclusion
*************************************************************************/
#include "Rte_BMM_AC_BeltMovementMonitoring.h"
#include "common.h"
#include "config.h"
#include "BMM.h"
#include "BMM_cfg_generic.h"
#include "Nvp_Generated.h"


/*************************************************************************
Intra-package inclusions
*************************************************************************/


/* MCAL inclusions allowed for IO-HW abstraction component */
#include "Port_Cfg.h"
#include "Dio.h"
#include "Ftm_Common_Types.h"
#include "StdRegMacros.h"
#include "Reg_eSys_Ftm.h"
#include "Reg_eSys_PCC.h"
/*************************************************************************
Declaration of types
*************************************************************************/

/* Type for belt position in the native counting unit of hall sensors event
 * (unit = 5° rotation in case of 18 pairs of poles) */
typedef sint16     s16PositionType;

/* Type for period length in the hardware timer counting step unit
 * (unit = period of timer's input prescaled clock = timer overflow time / timer counting range) */
typedef uint32     u32PeriodType;

typedef enum Bmm_InternalStateTag
{
   Uninit = 0u,
   Run,
   Downgraded_Hall_A,
   Downgraded_Hall_B,
   Shutdown
}bmm_InternalStateType;

typedef struct
{
   bmm_InternalStateType eCurrent;
   bmm_InternalStateType ePrevious;
}bmm_stInternalStateType;

typedef enum Bmm_PeriodTypesTag
{
   KU8_RISING_A = 0u,
   KU8_FALLING_A,
   KU8_RISING_B,
   KU8_FALLING_B,
   KU8_NUMBER_OF_PERIOD_TYPES
}bmm_PeriodTypesType;

/* Single edge algo structure definition */
typedef struct
{
   uint32 u32CurrentPeriod;
   uint16 u16TmrVal;
   uint8  u8TmrOvfl;
}bmm_stSingleEdgeData;

/*************************************************************************
Private inclusion
*************************************************************************/
/* Local function prototypes */
#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

LOCAL sint16 bmm_UpdatePosition(const uint8 u8HSLevel, const uint8 u8ReleaseValue);
LOCAL void bmm_ReadSpeed(const sint32 s32SpeedFactor, sint32 * const ps32Speed);
LOCAL void bmm_ReadSpeedSingleEdge(const sint32 s32SpeedFactor, sint32 * const ps32Speed);

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/*************************************************************************
Declaration of macros
*************************************************************************/

#define KU8_BMM_TIMER_INDEX				         FTM_1
#define KU8_BMM_HES_CHANNEL_A				         FTM_0_CH_6
#define KU8_BMM_HES_CHANNEL_B				         FTM_0_CH_7


/* Number of high pulses and low pulses (that is to say falling edge and
 * rising edge) occurring on one hall effect sensor channel (A or B)
 * during a hall A or hall B signal's period if the direction do not change. */
#define  KS16_NB_PULSE_PER_PERIOD               ((s16PositionType)4)

/* Position difference corresponding to a hall signal's period caused by a
 * constant belt releasing displacement */
#define  KS16_RELEASE_DT_POSITION_IN_PERIOD     ((s16PositionType)4)

/* Position difference corresponding to a hall signal's period caused by a
 * constant belt tensioning displacement */
#define  KS16_TENSION_DT_POSITION_IN_PERIOD     ((s16PositionType)-4)

/* Position difference corresponding to a hall signal's period caused by
 * both releasing and tensioning displacements that cancel each other */
#define  KS16_NULL_DT_POSITION_IN_PERIOD        ((s16PositionType)0)

/* Number of degrees rotation in a complete turn, for unit conversion */
#define  KS16_NB_DEGREES_PER_TURN               ((sint16)360)

/* Number of degrees rotation per same edge */
#define KU8_DEGREES_PER_EDGE 				         ((uint8)5)

/* Number of north+south poles couples */
#define  KS16_NB_PAIRS_OF_POLES_CFG             ((sint16)BMM_NB_PAIRS_OF_POLES_CFG)

/* Number of milliseconds in a seconds, for unit conversion */
#define  NB_MS_IN_S                             (1000uL)
#define  KU32_NB_MS_IN_S                        ((uint32) NB_MS_IN_S)

/* The 16 bits hardware timer range */
#define  HARD_TIMER_RANGE                       (0x10000uL)

/* The software timer full range: Correspond to a 24 bits timer, made with a combination of the hardware 16 bits timer and
 * the overflow 8 bits counter. */
#define  SOFT_TIMER_RANGE                       (0x100u * HARD_TIMER_RANGE)

/* The hardware timer half range. Timer counter value at timer overflow period's middle. */
#define  KU16_HARD_TIMER_HALF_RANGE             ((uint16)0x8000)

/* The period max configuration parameter converted into core clock lsb, knowing that the core clocks directly the Timer1 */
#define NB_CLK_IN_PERIOD                        ((BMM_CFG_TIMER_INPUT_CLK/NB_MS_IN_S)*BMM_PERIOD_MAX_MS)

/* Macro used to retrieve the current timer counter value */
#define U16_COUNTER_VALUE					         (REG_READ16(FTM_CNT_ADDR32(KU8_BMM_TIMER_INDEX)))
#define KU16_RESET_COUNTER                      ((uint16)0)

#define BMM_ENABLE_WRITE_PROTECTION		    REG_BIT_SET32(FTM_FMS_ADDR32(KU8_BMM_TIMER_INDEX), FTM_FMS_WPEN_MASK_U32)
#define BMM_DISABLE_WRITE_PROTECTION		if(REG_BIT_GET32(FTM_FMS_ADDR32(KU8_BMM_TIMER_INDEX), FTM_FMS_WPEN_MASK_U32) != KU32_ZERO)\
											{\
												REG_BIT_SET32(FTM_MODE_ADDR32(KU8_BMM_TIMER_INDEX), FTM_MODE_WPDIS_MASK_U32);\
											}\
                                          else\
                                 {\
                                    /* Do nothing */\
                                 }



#define BMM_CONFIGURE_TIMER_MOD				REG_WRITE32(FTM_MOD_ADDR32(KU8_BMM_TIMER_INDEX), 0x0000FFFF)

/* FTM 1 Channel 6/7 configuration registers */
/* Channel interup Enable
 * MSB = 0 |
 * MSA = 0 |
 * ELSB = 1|
 * ELSA = 1|-> Rising and falling edges capture
 * */
#define BMM_TIMER_CH_CFG               ((uint32) (KU32_ZERO | FTM_CSC_CHIE_MASK_U32 |FTM_CSC_ELSB_MASK_U32 | FTM_CSC_ELSA_MASK_U32) )

/* Enable / Disable hall A/B monitoring */
#define BMM_ENABLE_HALL_A_MONITORING   (REG_WRITE32(FTM_CSC_ADDR32(KU8_BMM_TIMER_INDEX, KU8_BMM_HES_CHANNEL_A), BMM_TIMER_CH_CFG))
#define BMM_ENABLE_HALL_B_MONITORING   (REG_WRITE32(FTM_CSC_ADDR32(KU8_BMM_TIMER_INDEX, KU8_BMM_HES_CHANNEL_B), BMM_TIMER_CH_CFG))
#define BMM_DISABLE_HALL_A_MONITORING  (REG_WRITE32(FTM_CSC_ADDR32(KU8_BMM_TIMER_INDEX, KU8_BMM_HES_CHANNEL_A), KU32_ZERO))
#define BMM_DISABLE_HALL_B_MONITORING  (REG_WRITE32(FTM_CSC_ADDR32(KU8_BMM_TIMER_INDEX, KU8_BMM_HES_CHANNEL_B), KU32_ZERO))
/* In case of both hall sensor faulty, disable the timer */
#define BMM_DISABLE_TIMER              (REG_WRITE32(FTM_SC_ADDR32(KU8_BMM_TIMER_INDEX), (KU32_ZERO | FTM_SC_CLKS_NO_CLOCKS_U32)))

/* Hall A and B interupt bit management macros */
#define BMM_TST_EVENT_HALL_A     (REG_BIT_GET32(FTM_CSC_ADDR32(KU8_BMM_TIMER_INDEX, KU8_BMM_HES_CHANNEL_A), FTM_CSC_CHF_MASK_U32))
#define BMM_CLR_EVENT_HALL_A     (REG_BIT_CLEAR32(FTM_CSC_ADDR32(KU8_BMM_TIMER_INDEX, KU8_BMM_HES_CHANNEL_A), FTM_CSC_CHF_MASK_U32))
#define BMM_TST_EVENT_HALL_B     (REG_BIT_GET32(FTM_CSC_ADDR32(KU8_BMM_TIMER_INDEX, KU8_BMM_HES_CHANNEL_B), FTM_CSC_CHF_MASK_U32))
#define BMM_CLR_EVENT_HALL_B     (REG_BIT_CLEAR32(FTM_CSC_ADDR32(KU8_BMM_TIMER_INDEX, KU8_BMM_HES_CHANNEL_B), FTM_CSC_CHF_MASK_U32))

/* FTM 1 timer overflow bit management macros */
#define BMM_TST_EVENT_FTM1_TOF   (REG_BIT_GET32(FTM_SC_ADDR32(KU8_BMM_TIMER_INDEX),FTM_SC_TOF_MASK_U32))
#define BMM_CLR_EVENT_FTM1_TOF   (REG_BIT_CLEAR32(FTM_SC_ADDR32(KU8_BMM_TIMER_INDEX),FTM_SC_TOF_MASK_U32))


/* Macro to get the hall sensor "A" output level, among STD_LOW and STD_HIGH */
#define DIO_HALL_A                            (Dio_ReadChannel(DioConf_DioChannel_DioChannel_HALL_A))

/* Macro to get the hall sensor "B" output level, among STD_LOW and STD_HIGH */
#define DIO_HALL_B                            (Dio_ReadChannel(DioConf_DioChannel_DioChannel_HALL_B))

#define BMM_EXPECTED_TMR_PRESCALER  (NB_CLK_IN_PERIOD/SOFT_TIMER_RANGE)

/* FTM only support power of 2 prescaler. We round up the computed value to the nearest upper one */
#if(BMM_EXPECTED_TMR_PRESCALER == 1)
   #define EXPECTED_PRESCALER ((uint32) 1)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV1_U32
#elif((BMM_EXPECTED_TMR_PRESCALER > 1) && (BMM_EXPECTED_TMR_PRESCALER <= 2))
   #define EXPECTED_PRESCALER ((uint32) 2)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV2_U32
#elif((BMM_EXPECTED_TMR_PRESCALER > 2) && (BMM_EXPECTED_TMR_PRESCALER <= 4))
   #define EXPECTED_PRESCALER ((uint32) 4)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV4_U32
#elif((BMM_EXPECTED_TMR_PRESCALER > 4) && (BMM_EXPECTED_TMR_PRESCALER <= 8))
   #define EXPECTED_PRESCALER ((uint32) 8)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV8_U32
#elif((BMM_EXPECTED_TMR_PRESCALER > 8) && (BMM_EXPECTED_TMR_PRESCALER <= 16))
   #define EXPECTED_PRESCALER ((uint32) 16)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV16_U32
#elif((BMM_EXPECTED_TMR_PRESCALER > 16) && (BMM_EXPECTED_TMR_PRESCALER <= 32))
   #define EXPECTED_PRESCALER ((uint32) 32)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV32_U32
#elif((BMM_EXPECTED_TMR_PRESCALER > 32) && (BMM_EXPECTED_TMR_PRESCALER <= 64))
   #define EXPECTED_PRESCALER ((uint32) 64)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV64_U32
#elif((BMM_EXPECTED_TMR_PRESCALER > 64) && (BMM_EXPECTED_TMR_PRESCALER <= 128))
   #define EXPECTED_PRESCALER ((uint32) 128)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV128_U32
#else
   #define EXPECTED_PRESCALER ((uint32) 128)
   #define BMM_FTM_SC_PS   FTM_SC_PS_DIV128_U32
#endif

/* Compute the counting frequency in Hz and kHz */
#define NB_US_IN_MS                           (1000uL)
#define NB_US_IN_S                            (1000000uL)
#define KU32_NB_US_IN_MS                      ((uint32)NB_US_IN_MS)
#define KU32_NB_LSB_IN_S                      ((uint32)(BMM_CFG_TIMER_INPUT_CLK/EXPECTED_PRESCALER))
#define KS32_NB_LSB_IN_S                      ((sint32)(BMM_CFG_TIMER_INPUT_CLK/EXPECTED_PRESCALER))
#define KS32_NB_LSB_IN_S_SINGLE_EDGE          ((sint32) (KS32_NB_LSB_IN_S/KU8_FOUR))
#define KU32_NB_LSB_IN_MS                     (KU32_NB_LSB_IN_S / KU32_NB_MS_IN_S)

#if (BMM_ENABLE_PYRO_DETECTION == 1)

/* The required number of previous consecutive positive pulses (on same or different channels)
 * fulfilling the duration criteria, to validate the pyro firing detection when the criteria
 * if fulfilled again. */
#define KU8_REQUIRED_NB_OF_PYRO_DETECT        ((uint8)1)

/* Counter for the duration where a pyro activation notification shall be latched, knowing that the
 * duration is a configuration parameter and that this counter is decremented in the timer overflow interrupt */
#define KU16_PYRO_PRESENT_RELOAD              ((uint16)((KU32_NB_LSB_IN_S * KU16_PYRO_ACTIVATED_TIME_OUT) / (HARD_TIMER_RANGE * NB_MS_IN_S))-1u)

/* Pyro presence counter value to be reached to clear the presence flag */
#define KU16_PYRO_PRESENCE_ELAPSED            ((uint16)0)

#endif

#define BMM_ENABLE_TIMER (REG_WRITE32(FTM_SC_ADDR32(KU8_BMM_TIMER_INDEX), (KU32_ZERO | FTM_SC_CLKS_SYS_CLOCK_U32 | FTM_SC_TOIE_ENABLE_U32 | BMM_FTM_SC_PS)))

/* HES Fault detection */
#define BMM_SENSORS_OK                        ((uint8) 0)
#define BMM_HALL_A_ERROR                      ((uint8) 1)
#define BMM_HALL_B_ERROR                      ((uint8) 2)
#define BMM_BOTH_SENSORS_ERROR                ((uint8) 3)

/*************************************************************************
 LOCAL constant data declaration
**************************************************************************/

/*************************************************************************
LOCAL variables declaration
*************************************************************************/

/* QAC_WARNING S 2022 ++ */ /* A tentative definition used without explicit initializer. */
                     /* All of these variables are initialized during Init function
                      * and will not be used before its execution. */

#define BMM_AC_BeltMovementMonitoring_START_SEC_VAR_16
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

/* Ecpl Bobbin Speed Threshold NVP parameter converted into timer value. */
LOCAL uint16 u16CplTimerCntThrs;

/* Time counter used to latch pyro detection flag during 2s */
LOCAL uint16 u16PyroPresentCounter;

/* Necessary for belt position monitoring and evaluation */
/* ----------------------------------------------------- */

/* Belt displacement in number of input edge count (combining hall A and
 * hall B channels for rising and falling edges).
 * = 0 at initialization (the belt has never moved yet = force null speed)
 * > 0 after a releasing belt move
 * < 0 after a tensioning belt move */
LOCAL volatile s16PositionType s16CurrentPosition;

/* Necessary for belt speed monitoring and evaluation */
/* -------------------------------------------------- */

/* Remember the bobbin position at last occurrence of each kind of edge marking
 * a period begin. */
LOCAL s16PositionType as16Positions[KU8_NUMBER_OF_PERIOD_TYPES];

/* s16CurrentPulseCnt value delta between begin and end of the last completed period */
LOCAL volatile s16PositionType s16LastPeriodDisplacement;

/* Remember the timer's values which have been captured on last occurrence of
 * each kind of edge marking a period begin. */
LOCAL volatile uint16 au16Captures[KU8_NUMBER_OF_PERIOD_TYPES];

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_VAR_16
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

#define BMM_AC_BeltMovementMonitoring_START_SEC_VAR_32
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/* Last completed period duration. This "Last" period is supposed to be either
 * between rising edges or between falling edges, occurred either on the hall A
 * or on the hall B channel. The duration is given in timer's counter lsb and
 * depends from hardware clock and timer prescaller configuration. */
LOCAL volatile u32PeriodType u32LastPeriodLength;

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_VAR_32
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"



#if (BMM_ENABLE_PYRO_DETECTION == 1)

/* Necessary for pyro firing detection management */
/* ---------------------------------------------- */

#define BMM_AC_BeltMovementMonitoring_START_SEC_VAR_8
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/* The pyro firing detection flag */
LOCAL volatile b8PyroActivationStatusType bPyroDetected;

/* Local pyro device status */
LOCAL b8PyroActivationStatusType b8IsPyroActivated;

/* Count the number of consecutive times a period length has been below
 * the pyro speed detection threshold */
LOCAL uint8 u8PyroDetectCnt;

/* BMM internal state base on hall effect sensor AEC */
/* B_TRUE: HES pulse counting disabled => speed = 0 and belt position = the last value measured */
/* B_FALSE: HES pulse counting enabled => nominal case*/
LOCAL uint8 u8BMMDowngradedState;

/* Count independently for each kind of input capture edge (regarding polarity
 * and sensor source) the number of times the timer has overflowed during the
 * period. */
LOCAL volatile uint8 au8Overflows[KU8_NUMBER_OF_PERIOD_TYPES];

/* Expected type of period to be computed on next capture interrupt if the
 * displacement direction does not change. */
LOCAL volatile bmm_PeriodTypesType u8NextPeriodType;


/* Semaphore to ensure the consistency of variables modified under interrupts
 * and read for speed evaluation */
LOCAL volatile boolean bNewEvent;

/* BMM internal state */
LOCAL bmm_stInternalStateType bmm_State = {Uninit, Uninit};

/* Check if all critical auto tests are done and passed */
LOCAL volatile boolean bCriticalNok = B_FALSE;

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_VAR_8
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

#endif

/* Single edge algorithm data structure */
LOCAL volatile bmm_stSingleEdgeData stSingleEdgeData = {KU32_ZERO, KU16_ZERO, KU8_ZERO};

#if (BMM_ENABLE_MAX_POS_MONITORING == 1)

#define BMM_AC_BeltMovementMonitoring_START_SEC_VAR_16
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

/* The lowest and highest value of s16CurrentPosition since reset */
LOCAL s16PositionType s16LowestPosition;
LOCAL s16PositionType s16HighestPosition;

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_VAR_16
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

#endif

/* QAC_WARNING S 2022 -- */

/**************************************************************************
Local Functions
**************************************************************************/
#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

 /* [COVERS: DSG_BMM_00031] */
/* FTM 1 CH6/CH7 Dual Edge capture ISR */
void OS_ISR_BMM_HES_IT(void)
{
   uint16 u16Capture;
   sint16 s16Pos;
   uint8 u8StateA;
   uint8 u8StateB;

   /* Retrieve hall sensors outputs levels */
   u8StateA = DIO_HALL_A;
   u8StateB = DIO_HALL_B;

   /* Get Counter value */
   u16Capture = U16_COUNTER_VALUE;

   /* Hall A interrupt (FTM1 CH6) - Rising edge */
   if( BMM_TST_EVENT_HALL_A != KU32_ZERO )
   {
      /* Clear Channel ISR flag */
      BMM_CLR_EVENT_HALL_A;

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
   if( BMM_TST_EVENT_HALL_B != KU32_ZERO )
   {
      /* Clear Channel ISR flag */
      BMM_CLR_EVENT_HALL_B;

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

/* [COVERS: DSG_BMM_00032] */
/* FTM 1 overflow ISR */
void OS_ISR_BMM_TimerOverflow(void)
{
   /* Clear FTM1 TOF bit */
   if( BMM_TST_EVENT_FTM1_TOF != KU32_ZERO)
   {
      BMM_CLR_EVENT_FTM1_TOF;
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

      /* Check if pyro detection has been notified to clients, and latch time out shall be managed */
      if (KB8_PYRO_DEVICE_ACTIVATED == b8IsPyroActivated)
      {
         /* 2s timeout has elapsed -> indicates pyro device is no more activated and reload counter */
         if (KU16_PYRO_PRESENCE_ELAPSED == u16PyroPresentCounter)
         {
            b8IsPyroActivated = KB8_PYRO_DEVICE_NOT_ACTIVATED;
         }
         else
         {
            /* Decrement counter to latch pyro detection */
            u16PyroPresentCounter--;
         }
      }
      else
      {
        /* Do nothing */
      }

      /* Notify the the variable update under interrupts. */
      bNewEvent = B_TRUE;
   }
   else
   {
      /* Do nothing */
   }
}

/**************************************************************************
Label:
Object: Sub function to increment or decrement current position on hall
        sensor edge. Detect Highest and lowest position exceeding and
        update if necessary.
Parameters: u8HSLevel = The hall output level to be considered
                        (STD_LOW / STD_HIGH).
            u8ReleaseValue = The expected output level for release direction
                             (STD_LOW / STD_HIGH).
Return: The just updated position.
[COVERS:]
***************************************************************************
Inputs validation conditions:
**********************************************************************EDC*/
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

/*DC***********************************************************************
Detailed Conception for the function                          bmm_ReadSpeed
***************************************************************************
Label:

Object: Computes the belt displacement speed in degrees per seconds, or in millimetres per seconds.

Parameters: ps32Speed: Pointer to write the bobbin rotation speed
            s32SpeedFactor: multiplication factor used to compute the rotation speed
            in degrees per seconds, or in millimetres per seconds.

Return: NA

[COVERS: ]
***************************************************************************
Inputs validation conditions:
**********************************************************************EDC*/
LOCAL void bmm_ReadSpeed(const sint32 s32SpeedFactor, sint32 * const ps32Speed)
{
   bmm_PeriodTypesType u8NextType;
   u32PeriodType u32LastPeriodLengthCopy;
   u32PeriodType u32NextPeriodLength;
   u32PeriodType u32LongestPeriod;
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
      u32LastPeriodLengthCopy = u32LastPeriodLength;
      /* QAC_WARNING S 3345 4 */ /* Statement contains more than one access to objects that are volatile. */
                         /* Any partial modification (inconsistency) is protected by this 'redo' loop. */
      /* Computes actual (partial) length of the expected next period. */
      u8NextType = u8NextPeriodType;
      u8OverFlowCnt = au8Overflows[u8NextType];
      u16Capture = au16Captures[u8NextType];
      u32NextPeriodLength = ((u8OverFlowCnt * HARD_TIMER_RANGE) + U16_COUNTER_VALUE) - u16Capture;
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

   /* QAC_WARNING S 0506 ++ */ /* Possible dereference of NULL pointer. */
                      /* Service usage : ps32Speed argument always point a container for speed result. */
   switch (s16LastPeriodDisplacementCopy)
   {
   case KS16_RELEASE_DT_POSITION_IN_PERIOD:
      /* QAC_WARNING S 3103 5 */ /* Result of signed division or remainder operation may be implementation defined. */
                         /* Even if they are signed, operands of the division are positive. */
      /* Computes the positive speed (for releasing) from the most relevant period between last and next one. */
      *ps32Speed = s32SpeedFactor / ((sint32)u32LongestPeriod);
      break;

   case KS16_TENSION_DT_POSITION_IN_PERIOD:
      /* QAC_WARNING S 3103 5 */ /* Result of signed division or remainder operation may be implementation defined. */
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
   /* QAC_WARNING S 0506 -- */
}

LOCAL void bmm_ReadSpeedSingleEdge(const sint32 s32SpeedFactor, sint32 * const ps32Speed)
{
   s16PositionType s16LastPeriodDisplacementCopy;
   u32PeriodType u32LastPeriodLengthCopy;
   u32PeriodType u32NextPeriodLength;
   u32PeriodType u32LongestPeriod;
   uint8 u8OverFlowCnt;
   uint16 u16Capture;

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
      /* QAC_WARNING S 3345 4 */ /* Statement contains more than one access to objects that are volatile. */
                         /* Any partial modification (inconsistency) is protected by this 'redo' loop. */
      /* Computes actual (partial) length of the expected next period. */
      u8OverFlowCnt = stSingleEdgeData.u8TmrOvfl;
      u16Capture = stSingleEdgeData.u16TmrVal;
      u32NextPeriodLength = ((u8OverFlowCnt * HARD_TIMER_RANGE) + U16_COUNTER_VALUE) - u16Capture;
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

   /* QAC_WARNING S 0506 ++ */ /* Possible dereference of NULL pointer. */
                         /* Service usage : ps32Speed argument always point a container for speed result. */
   switch (s16LastPeriodDisplacementCopy)
   {
   case KS16_RELEASE_DT_POSITION_IN_PERIOD:
      /* QAC_WARNING S 3103 5 */ /* Result of signed division or remainder operation may be implementation defined. */
                         /* Even if they are signed, operands of the division are positive. */
      /* Computes the positive speed (for releasing) from the most relevant period between last and next one. */
      *ps32Speed = s32SpeedFactor / ((sint32)u32LongestPeriod);
      break;

   case KS16_TENSION_DT_POSITION_IN_PERIOD:
       /* QAC_WARNING S 3103 5 */ /* Result of signed division or remainder operation may be implementation defined. */
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
   /* QAC_WARNING S 0506 -- */
}

/*COVERS: DSG_BMM_00004; DSG_BMM_00005; DSG_BMM_00006; DSG_BMM_00007; */
EXPORTED void BMM_runMainFunction(void)
{
   uint16 u16FilteredHESAInputVoltage_lsb;
   uint16 u16FilteredHESBInputVoltage_lsb;
   uint8 u8HesState = BMM_SENSORS_OK;
   b8IsCarCrashDetectedType b8CarCrashStatus;
   uint8 u8CriticalMode;

   /* Check Crash CAN signal to trigger the PYRO */
   Rte_Read_prrCustomerSpecific_b8IsCarCrashDetected(&b8CarCrashStatus);

   if(B_TRUE == b8CarCrashStatus)
   {
      bPyroDetected = KB8_PYRO_DEVICE_ACTIVATED;
   }
   else
   {
      /* Nothing to do */
   }

   /* Check both Hall sensors speratly and update BMM state based on the result */
   /* Get the filtered physical value measured of Hall Effect Sensor A from ASM */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Call_pclHBS_A_V_raw_Get_100ms (& u16FilteredHESAInputVoltage_lsb);

   /* Get the filtered physical value measured of Hall Effect Sensor B from ASM */
   /* QAC_WARNING S 3426 1 */ /* QAC_WARNING S 3417 1 */ /* warnings due to use of Rte_Call macro */
   Rte_Call_pclHBS_B_V_raw_Get_100ms (& u16FilteredHESBInputVoltage_lsb);

   if( (u16FilteredHESAInputVoltage_lsb > NVP_u16HESTestHighThrs) ||
       (u16FilteredHESAInputVoltage_lsb <= NVP_u16HESTestLowThrs) )
   {
      /* One of the HES input voltage is out of range : return NOK */
      u8HesState |= BMM_HALL_A_ERROR;
   }
   else
   {
      /* Nothind to do */
   }
   

   if( (u16FilteredHESBInputVoltage_lsb > NVP_u16HESTestHighThrs) ||
       (u16FilteredHESBInputVoltage_lsb <= NVP_u16HESTestLowThrs) )
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
            BMM_DISABLE_WRITE_PROTECTION
            BMM_ENABLE_TIMER;
            BMM_ENABLE_HALL_A_MONITORING;
            BMM_ENABLE_WRITE_PROTECTION;
         }
         else if ( Downgraded_Hall_B == bmm_State.ePrevious )
         {
            BMM_DISABLE_WRITE_PROTECTION
            BMM_ENABLE_TIMER;
            BMM_ENABLE_HALL_B_MONITORING;
            BMM_ENABLE_WRITE_PROTECTION;
         }
         else if ( Shutdown == bmm_State.ePrevious )
         {
            BMM_DISABLE_WRITE_PROTECTION
            BMM_ENABLE_HALL_A_MONITORING;
            BMM_ENABLE_HALL_B_MONITORING;
            BMM_ENABLE_TIMER;
            BMM_ENABLE_WRITE_PROTECTION;
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
      BMM_DISABLE_WRITE_PROTECTION
      BMM_DISABLE_HALL_A_MONITORING;
      BMM_ENABLE_WRITE_PROTECTION;
      break;

   case BMM_HALL_B_ERROR:
      bmm_State.eCurrent = Downgraded_Hall_B;
      BMM_DISABLE_WRITE_PROTECTION
      BMM_DISABLE_HALL_B_MONITORING;
      BMM_ENABLE_WRITE_PROTECTION;
      break;

   case BMM_BOTH_SENSORS_ERROR:
      bmm_State.eCurrent = Shutdown;
      BMM_DISABLE_WRITE_PROTECTION
      BMM_DISABLE_HALL_A_MONITORING;
      BMM_DISABLE_HALL_B_MONITORING;
      BMM_DISABLE_TIMER;
      BMM_ENABLE_WRITE_PROTECTION;
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

/**************************************************************************
Exported Functions
**************************************************************************/

/* QAC_WARNING S 3335 ++ */ /* No function declaration. Implicit declaration inserted: 'extern int _asm();'. */
/* QAC_WARNING S 3200 ++ */ /* '_asm' returns a value which is not being used. */
/* QAC_WARNING S 3209 ++ */ /* returns a value which is always ignored. */
                     /* This module includes several times the disable and enable interrupts macros which
                      * can only be implemented in assembler, while the COSMIC "asm" directive generates
                      * QAC messages above. */

/* QAC_WARNING S 3227 ++ */ /* The parameter is never modified and so it could be declared with the 'const' qualifier. */
                     /* Exported functions shall match with the generated prototypes in RTE. */

/****************************************************************************
Label:
Object: Initialize:
        - The variable for current position to zero.
        - The variable for current displacement direction corresponding
          to none.
        - Configure the hardware timer 1 module
Parameters: void

Return: NA
****************************************************************************/
/*COVERS: DSG_BMM_00001; DSG_BMM_00002; DSG_BMM_00003*/
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

   /* By default, the pyro presence counter is armed */
   u16PyroPresentCounter = KU16_PYRO_PRESENT_RELOAD;

   /* Adapt Ecpl Bobbin Speed Threshold from microseconds (NVP parameter format) to the timer scale (timer counter lsb).
    * - Note intermediate operation performed on 32 bits, allowing any 16 bits NVP parameter value without overflow
    *   during the multiplication. */
   u16CplTimerCntThrs = (uint16)(((uint32)NVP_u16CplBobbinSpeedThrs * KU32_NB_LSB_IN_MS) / KU32_NB_US_IN_MS);
#endif

   /* initialize all single edge data field to 0 */
   stSingleEdgeData.u32CurrentPeriod = KU32_ZERO;
   stSingleEdgeData.u16TmrVal = KU16_ZERO;
   stSingleEdgeData.u8TmrOvfl = KU8_ZERO;

   /*Disable write protection in order to configure timer*/
   BMM_DISABLE_WRITE_PROTECTION;

   /* Reset FTM 1 Counter value */
   REG_WRITE16(FTM_CNT_ADDR32(KU8_BMM_TIMER_INDEX), KU16_RESET_COUNTER);

   BMM_CONFIGURE_TIMER_MOD;

   /* falling and rising edge capture on both channels  */
   BMM_ENABLE_HALL_A_MONITORING;
   BMM_ENABLE_HALL_B_MONITORING;

   /* Status and Control configuration */
   BMM_ENABLE_TIMER;

   BMM_CLR_EVENT_FTM1_TOF;
   /*REG_WRITE32(FTM_CNT_ADDR32(KU8_BMM_TIMER_INDEX), 0x00008000);*/

   /*Enable write protection in order to secure configuration of timer*/
   BMM_ENABLE_WRITE_PROTECTION;

   /* Module initialization completed */
   bmm_State.eCurrent = Run;
}

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

#if (BMM_ENABLE_PYRO_DETECTION == 1)

#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/**************************************************************************
Label:
Object: Returns the status of the detection of the pyro device firing, using the magnetic wheel
Parameters: pbIsPyroActivated = The pyro activation status, latched 2s after detection.
Return: NONE
[COVERS: DSG_BMM_00017; DSG_BMM_00018; DSG_BMM_00019; DSG_BMM_00020; DSG_BMM_00021; DSG_BMM_00022]
**************************************************************************/
/* QAC_WARNING S 3227 3 */ /* The parameter is never modified and so it could be declared with the 'const' qualifier. */
                    /* The function prototype is defined at RTE level, the 'const' qualifier can't be added. */
EXPORTED void BMM_runGetPyroActivationStatus(b8PyroActivationStatusType * pb8PyroActivationStatus)
{
   /* Check if eCPL is activated by NVP configuration */
   if (B_TRUE == NVP_b8IseCplActivated)
   {
   /* Check the pyro evaluation made under interrupt */
      if (KB8_PYRO_DEVICE_ACTIVATED == bPyroDetected)
      {
         b8IsPyroActivated = KB8_PYRO_DEVICE_ACTIVATED;

         /* Acknowledge the pyro. detection indication */
         u8PyroDetectCnt = KU8_ZERO;
         bPyroDetected = KB8_PYRO_DEVICE_NOT_ACTIVATED;
         u16PyroPresentCounter = KU16_PYRO_PRESENT_RELOAD;
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
   /* eCPL is disabled by NVP configuration */
   else
   {
      /* Deactivate Emergency braking sequence whatever the pyro detection is */
      *(pb8PyroActivationStatus) = KB8_PYRO_DEVICE_NOT_ACTIVATED;
   }
}

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

#endif

#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/****************************************************************************
Label:
Object: Computes the belt bobbin displacement in rotation degrees
Parameters: ps16Payout: Pointer to write the belt bobbin displacement in rotation degrees.

Return: NA
[COVERS: DSG_BMM_00009]
***************************************************************************/
/* QAC_WARNING S 3227 3 */ /* The parameter is never modified and so it could be declared with the 'const' qualifier. */
                    /* The function prototype is defined at RTE level, the 'const' qualifier can't be added. */
EXPORTED void BMM_runGetPositionFromT0_deg(s16BeltPosition_degType * ps16BeltPosition_deg)
{
   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 360) / (36 * 2) = 10800.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   /* QAC_WARNING S 4120 10 */ /* Implicit conversion: complex expression of integral type to wider type. */
                       /* Force intermediate multiply on wider container to avoid overflow */
   /* QAC_WARNING S 0506 8 */ /* Possible dereference of NULL pointer. */
                       /* Use of this service assumes that the argument points an instantiated variable */
   /* QAC_WARNING S 3103 5 */ /* Result of signed division or remainder operation may be implementation defined. */
                       /* The round made for the result of the signed division do not impact the relevance
                        * of this result. */
   /* Converts current position from edge count to degrees */
   *ps16BeltPosition_deg = (sint16)(((sint32)s16CurrentPosition * (sint32)KS16_NB_DEGREES_PER_TURN) / ((sint32)KS16_NB_PAIRS_OF_POLES_CFG * (sint32)KS16_NB_PULSE_PER_PERIOD));
}

/************************************************************************
Label:
Object: Computes the belt bobbin displacement in millimeters
Parameters: ps16Payout: Pointer to write the belt bobbin displacement in millimeters

Return: NA
[COVERS: DSG_BMM_00010]
***************************************************************************/
/* QAC_WARNING S 3227 3 */ /* The parameter is never modified and so it could be declared with the 'const' qualifier. */
                    /* The function prototype is defined at RTE level, the 'const' qualifier can't be added. */
EXPORTED void BMM_runGetPositionFromT0_mm(s16BeltPosition_mmType * ps16BeltPosition_mm)
{
   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 168) / (36 * 2) = 5040.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   /* QAC_WARNING S 4120 10 */ /* Implicit conversion: complex expression of integral type to wider type. */
                        /* Force intermediate multiply on wider container to avoid overflow */
   /* QAC_WARNING S 0506 8 */ /* Possible dereference of NULL pointer. */
                       /* Use of this service assumes that the argument points an instantiated variable */
   /* QAC_WARNING S 3103 5 */ /* Result of signed division or remainder operation may be implementation defined. */
                       /* The round made for the result of the signed division do not impact the relevance
                        * of this result. */
   /* Converts current position from edge count to degrees */
   *ps16BeltPosition_mm = (sint16)(((sint32)s16CurrentPosition * (sint32)BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG) / ((sint32)KS16_NB_PAIRS_OF_POLES_CFG * (sint32)KS16_NB_PULSE_PER_PERIOD));
}

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

#if (BMM_ENABLE_MAX_POS_MONITORING == 1)

#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/***************************************************************************
Label:
Object: Computes the belt bobbin displacement in degrees
Parameters: ps16BeltRelativePosition_deg: Pointer to write the belt bobbin displacement in millimeters

Return: NA
[COVERS: DSG_BMM_00011]
***********************************************************************/
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
   /* QAC_WARNING S 4120 10 */ /* Implicit conversion: complex expression of integral type to wider type. */
                       /* Force intermediate multiply on wider container to avoid overflow */
   /* QAC_WARNING S 0506 4 */ /* Possible dereference of NULL pointer. */
                       /* Use of this service assumes that the argument points an instantiated variable */
   /* QAC_WARNING S 3103 2 */ /* Result of signed division or remainder operation may be implementation defined. */
                       /* Not applicable since (s16CurPos - s16LowPos) will always be positive */
   *ps16BeltPosition_deg = (sint16)( ( ((sint32)s16CurPos - s16LowPos) * KS16_NB_DEGREES_PER_TURN) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
}

/***************************************************************************
Label:
Object: Computes the belt bobbin displacement in millimeters
Parameters: ps16BeltRelativePosition_deg: Pointer to write the belt bobbin displacement in millimeters

Return: NA
[COVERS: DSG_BMM_00012]
***********************************************************************/
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
   /* QAC_WARNING S 4120 10 */ /* Implicit conversion: complex expression of integral type to wider type. */
                       /* Force intermediate multiply on wider container to avoid overflow */
   /* QAC_WARNING S 0506 4 */ /* Possible dereference of NULL pointer. */
                       /* Use of this service assumes that the argument points an instantiated variable */
   /* QAC_WARNING S 3103 2 */ /* Result of signed division or remainder operation may be implementation defined. */
                       /* Not applicable since (s16CurPos - s16LowPos) will always be positive */
   *ps16BeltPosition_mm = (sint16)( ( ((sint32)s16CurPos - s16LowPos) * BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
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
   /* QAC_WARNING S 4120 10 */ /* Implicit conversion: complex expression of integral type to wider type. */
                        /* Force intermediate multiply on wider container to avoid overflow */
   /* QAC_WARNING S 0506 6 */ /* Possible dereference of NULL pointer. */
                       /* Use of this service assumes that the argument points an instantiated variable */
   /* QAC_WARNING S 3103 4 */ /* Result of signed division or remainder operation may be implementation defined. */
                       /* The round made for the result of the signed division do not impact the relevance
                        * of the min result, while the max result is not even concerned (always positive). */
   *ps16BeltPosition_min_deg = (sint16)(((sint32)s16LowestPosition * KS16_NB_DEGREES_PER_TURN) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
   *ps16BeltPosition_max_deg = (sint16)(((sint32)s16HighestPosition * KS16_NB_DEGREES_PER_TURN) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
}

/***************************************************************************
Label:
Object: Computes the minimum and maximum positions in millimeters
Parameters: ps16BeltRelativePosition_deg: Pointer to write the belt bobbin displacement in millimeters

Return: NA
[COVERS: DSG_BMM_00014]
***********************************************************************/
EXPORTED void BMM_runGetPositionRange_mm(s16BeltPosition_mmType * ps16BeltPosition_min_mm, s16BeltPosition_mmType * ps16BeltPosition_max_mm)
{
   /* An overflow can never occur. Consider a belt length of 10m. This is a very large value than the reality.
    * Regarding DES_SWRS_BDS_11 requirement, the default belt bobbin perimeter is 0.168m. Thus, the maximum number
    * of rotation that the bobbin can make is 10/0.168 = 30 rotations. If we take into account that there is 72 pulses
    * in one rotation (1 pulse = 5° => 72 pulse = 360°), the maximum value of “s16CurrentPulseCnt” parameter
    * is 30 * 72 = 2160. When replacing all constants in the formula: *ps16Payout = (2160 * 168) / (36 * 2) = 5040.
    * The operation result is always less that 32767 (sint16 maximal value) => No need of bounds check. */
   /* QAC_WARNING S 4120 10 */ /* Implicit conversion: complex expression of integral type to wider type. */
                        /* Force intermediate multiply on wider container to avoid overflow */
   /* QAC_WARNING S 0506 6 */ /* Possible dereference of NULL pointer. */
                        /* Use of this service assumes that the argument points an instantiated variable */
   /* QAC_WARNING S 3103 4 */ /* Result of signed division or remainder operation may be implementation defined. */
                       /* The round made for the result of the signed division do not impact the relevance
                        * of the min result, while the max result is not even concerned (always positive). */
   *ps16BeltPosition_min_mm = (sint16)(((sint32)s16LowestPosition * BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
   *ps16BeltPosition_max_mm = (sint16)(((sint32)s16HighestPosition * BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG) / (KS16_NB_PAIRS_OF_POLES_CFG * KS16_NB_PULSE_PER_PERIOD));
}

#define BMM_AC_BeltMovementMonitoring_STOP_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"

#endif

#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/***************************************************************************
Label:
Object: Computes the bobbin rotation speed in degrees per second
Parameters: ps32Speed: Pointer to write the bobbin rotation speed in degrees per second

Return: NA
[COVERS: DSG_BMM_00015]
***********************************************************************/
/* QAC_WARNING S 3227 3 */ /* The parameter is never modified and so it could be declared with the 'const' qualifier. */
                    /* The function prototype is defined at RTE level, the 'const' qualifier can't be added. */
EXPORTED void BMM_runGetSpeed_deg_s(s32BeltSpeed_deg_sType * ps32BeltSpeed_deg_s)
{
   bmm_ReadSpeed((KS16_NB_DEGREES_PER_TURN * KS32_NB_LSB_IN_S) / KS16_NB_PAIRS_OF_POLES_CFG, ps32BeltSpeed_deg_s);
}

FUNC(void, RTE_CODE) BMM_runGetSpeed_SingleEdge_deg_s (P2VAR(s32BeltSpeed_deg_sType, AUTOMATIC, RTE_APPL_DATA) ps32BeltSpeed_SE_deg_s)
{
   bmm_ReadSpeedSingleEdge((KS16_NB_DEGREES_PER_TURN * KS32_NB_LSB_IN_S_SINGLE_EDGE) / KS16_NB_PAIRS_OF_POLES_CFG, ps32BeltSpeed_SE_deg_s);
}

/***************************************************************************
Label:
Object: Computes the bobbin rotation speed in millimeters per second
Parameters: ps32Speed: Pointer to write the bobbin rotation speed in millimeters per second

Return: NA
[COVERS: DSG_BMM_00016]
***********************************************************************/
/* QAC_WARNING S 3227 3 */ /* The parameter is never modified and so it could be declared with the 'const' qualifier. */
                    /* The function prototype is defined at RTE level, the 'const' qualifier can't be added. */
EXPORTED void BMM_runGetSpeed_mm_s(s32BeltSpeed_mm_sType * ps32BeltSpeed_mm_s)
{
   bmm_ReadSpeed((BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG * KS32_NB_LSB_IN_S) / KS16_NB_PAIRS_OF_POLES_CFG, ps32BeltSpeed_mm_s);
}

/*DC***********************************************************************
Detailed Conception for the function            BMM_runDisableHBSMonitoring
***************************************************************************
Label:
Object: Disable all capture and overflow interrupts.
        Disable the timer peripheral.
Parameters: none
Return: none
[COVERS: DSG_BMM_00029]
***************************************************************************
Inputs validation conditions:
**********************************************************************EDC*/
EXPORTED void BMM_runDisableHBSMonitoring ( void )
{   
   /* Set the BMM state to downgraded */
   u8BMMDowngradedState = B_TRUE;
}

/*DC***********************************************************************
Detailed Conception for the function             BMM_runEnableHBSMonitoring
***************************************************************************
Label:
Object: Enable all capture and overflow interrupts.
        Enable the timer peripheral.
Parameters: none
Return: none
[COVERS: DSG_BMM_00030]
***************************************************************************
Inputs validation conditions:
**********************************************************************EDC*/
EXPORTED void BMM_runEnableHBSMonitoring ( void )
{
   /* Set the BMM state back to normal */
   u8BMMDowngradedState = B_FALSE;
}



#define BMM_AC_BeltMovementMonitoring_START_SEC_CODE
#include "BMM_AC_BeltMovementMonitoring_MemMap.h"
/*************************************************************************
Evolution of the component

Created by : S. CLAVEAU

$Log: BMM.c  $
Revision 1.1 2021/10/04 07:14:25CEST Lucian Ardeleanu (lucian.ardeleanu) 
Initial revision
Member added to project e:/MKSProjects/SBE/Exploration/Python_Workspace/Automate_line_number_script/Executables/source_files/project.pj
Revision 1.1.1.16.1.15 2021/02/02 12:56:36EET Anca Vulpe (anca.vulpe) 
update traceability
Revision 1.1.1.16.1.14 2021/01/12 13:22:24EET Anca Vulpe (anca.vulpe) 
Add design
Revision 1.1.1.16.1.13 2020/12/11 11:25:33EET Razvan Badiu (razvan.badiu) 
velocity port
Revision 1.1.1.16.1.12 2020/09/22 15:38:07EEST Anca Vulpe (anca.vulpe) 
BMM improvement
Revision 1.1.1.16.1.11 2020/09/16 14:00:46EEST Razvan Badiu (razvan.badiu) 
remove unused pin for lower power consumption
Revision 1.1.1.16.1.10 2020/09/01 15:43:09EEST Anca Vulpe (anca.vulpe) 
BMM improvement (Integrate mainstream algorithm)
Revision 1.1.1.16.1.9 2020/08/13 09:07:02EEST Vlad Chioveanu (vlad.chioveanu) 
Update traceability
Revision 1.1.1.16.1.8 2020/08/12 11:57:41EEST Vlad Chioveanu (vlad.chioveanu) 
Update traceability
Revision 1.1.1.16.1.7 2020/08/04 16:25:58EEST Gheorghita Brasoveanu (gheorghita.brasovean) 
Exclusion Markers for UT
Revision 1.1.1.16.1.6 2020/07/15 10:55:43EEST Anca Vulpe (anca.vulpe) 
Remove QAC warnings
Revision 1.1.1.16.1.5 2020/07/15 10:47:15EEST Anca Vulpe (anca.vulpe) 
Remove QAC warnings
Revision 1.1.1.16.1.4 2020/07/15 10:18:29EEST Anca Vulpe (anca.vulpe) 
Remove QAC warnings
Revision 1.1.1.16.1.3 2020/07/10 12:38:42EEST Anca Vulpe (anca.vulpe) 
QAC update
Revision 1.1.1.16.1.2 2020/06/05 10:14:09EEST Dan Dustinta (dan.dustinta) 
ecpl Adaptations
Revision 1.1.1.16.1.1 2020/05/07 10:27:06EEST Anca Vulpe (anca.vulpe) 
Fix cast
Revision 1.1.1.16 2018/06/25 20:01:31EEST Arthur Mahe (arthur.mahe) 
Update variable definition
Revision 1.1.1.15 2018/06/25 16:30:44CEST Arthur Mahe (arthur.mahe) 
Update variable definition for min max range
Revision 1.1.1.14 2018/06/25 15:24:46CEST Arthur Mahe (arthur.mahe) 
Reviex update
Revision 1.1.1.13 2018/06/20 11:05:45CEST Arthur Mahe (arthur.mahe) 
Bug fixing for memory map and delete useless functions
Revision 1.1.1.12 2018/05/28 15:10:50CEST Arthur Mahe (arthur.mahe) 
New belt speed computation
Revision 1.1.1.11 2018/05/03 16:12:29CEST Arthur Mahe (arthur.mahe) 
Add current position
Revision 1.1.1.10 2018/05/02 14:11:33CEST Arthur Mahe (arthur.mahe) 
New position and min max range position computation
Revision 1.1.1.9 2018/04/20 14:28:25CEST Arthur Mahe (arthur.mahe) 
Min Maw range update
Revision 1.1.1.8 2018/04/06 16:50:40CEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
Fix FTM clock configuration => No clock
Revision 1.1.1.7 2017/12/22 13:31:34CET Bogdan Giura (bogdan.giura) 
Implemented the speed and pyro functionality
Revision 1.1.1.5 2017/06/01 12:37:51EEST Cedric Sauvage (cedric.sauvage) 
Compilation mistakes fixed
HBS sensors supplied
Revision 1.1.1.4 2017/06/01 03:10:25CEST Zoltan Nemes (zoltan.nemes) 
Implemented Belt Monitoring using Quadrature Decoder. Only position is read correctly. Speed is stubbed with temporary value.
Revision 1.1.1.3 2017/05/25 17:32:12EEST Zoltan Nemes (zoltan.nemes) 
Adapted code to different hardware timer.
Revision 1.1.1.2 2017/02/24 10:46:34EET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:17:07CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:25:31CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/BMM/Implementation/src/project.pj
Revision 1.1 2016/10/05 18:25:31CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/BMM/Implementation/src/project.pj
Revision 1.1 2016/10/05 10:12:50CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/BMM/Implementation/src/project.pj
Revision 1.1 2016/09/20 09:48:04CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/BMM/Implementation/src/src.pj
Revision 1.10 2016/09/05 10:37:24CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Revision 1.9 2016/09/05 10:27:08CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Replace by P R Q A in comments
Revision 1.8 2016/09/05 10:01:58CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove all P R Q As
P R Q A is replaced by QAC_WARNING
Revision 1.7 2016/07/15 14:53:07CEST Stefan Dragan (stefan.dragan) 
Issue 415737, Integrate Issue 364795-Enable/Disable HES interrupt when AEC is qualified
Revision 1.6 2016/06/13 19:03:31EEST Stefan Dragan (stdragan) 
Integrated revision 1.7 from R2.3M
Revision 1.5 2016/06/07 13:52:52EEST Audrey Vache (avache) 
Memory mapping implementation
Revision 1.4 2016/05/17 15:24:13CEST Maxime Bourdon (mbourdon) 
completion of ASR4 migration
Revision 1.3 2015/11/06 14:11:16CET Maxime Bourdon (mbourdon) 
Pass ATM Autotests calls through RTE + includes clean up
Revision 1.2 2015/11/03 10:21:35CET Maxime Bourdon (mbourdon) 
RTE files inclusion clean up
Revision 1.1 2015/10/15 14:46:27CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_BMM/src/project.pj
Revision 1.6 2014/12/09 08:47:48CET Sebastien Claveau (sclaveau) 
Update comments
Revision 1.5 2014/12/08 17:00:29CET Sebastien Claveau (sclaveau) 
Update for QAC 8.2 (messages + all metrics req.)
Revision 1.4 2014/10/22 15:06:05CEST Sebastien Claveau (sclaveau) 
Modify code regarding BMM peer review workbook.
Revision 1.3 2014/09/12 10:21:22CEST Sebastien Claveau (sclaveau) 
Fix or justify QAC results
Revision 1.2 2014/09/08 15:21:08CEST Sebastien Claveau (sclaveau) 
Remove second argument of BMM_runGetPyroActivationStatus.
Revision 1.1 2014/09/05 15:07:37CEST Sebastien Claveau (sclaveau) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_BMM/src/project.pj
Initial revision

*************************************************************************/

/* end of file */
