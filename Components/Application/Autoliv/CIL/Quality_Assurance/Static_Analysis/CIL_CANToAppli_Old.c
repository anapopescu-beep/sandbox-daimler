
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
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.6.1.43 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/CIL/Quality_Assurance/Static_Analysis/project.pj $
 */
/**
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_CIL_AC_CommunicationInteractionLayer.h"
#include "common.h"
#include "Appl_Cbk.h"
#include "Nvp_Cfg.h"
#include "CIL.h"
#include "NVP_Stubs.h"
#include "Cdd_MBBL_EcuStatHandler.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 * 		Impact_RO_type_ST3 FALSE value
 */
#define KU8_CIL_FALSE_ImpactRoTrigger   ((uint8) 0x00)
/**
 * \brief
 * 		Impact_RO_type_ST3 TRUE value
 */
#define KU8_CIL_TRUE_ImpactRoTrigger   ((uint8) 0x01)
/*
 * All inhibit conditions : all cycles MMG, tensioning cycles MMG, ignition, PresfEnb, PresfTensSupp, Acclow300ms, Bckl_Sw, cycles BSR MMG, ImpactXandY;
 * 	bit :                                   7 |           6 |            5 |                4 |            3 |         2 |                      1 |                             0 |
 * 	inhibStatus:        UNUSED                |   Bckl_Sw   |   Acclow300ms|     PresfTensSupp|   PresfEnable|   Ignition|  inhibit all cycles MMG|  inhibit tensioning cycles MMG|
 *
 * 	bit :                                  15 |          14 |             13 |               12 |           11 |        10   |                      9 |         8 |
 * 	inhibStatus:                             x|            x|DrvPosInhibition|  Powertrain ready|  Belthandover|InhibAfterORC|dtc inhibit for presafe |  Impact X |                                                                               |                       API NA|
 */
/**
 * \brief
 * 		Index of inhibit because of tensioning cycles MMG
 */
#define KU8_CIL_InhibitionOfTensioning          (1u)
/**
 * \brief
 * 		Index of inhibit because of all cycles MMG
 */
#define KU8_CIL_InhibitionOfAllCycles           (2u)
/**
 * \brief
 * 		Index of inhibit because of Ignition signal
 */
#define KU8_CIL_IgnitionInhibiton               (4u)
/**
 * \brief
 * 		Index of inhibit because of Presf_Enbl signal
 */
#define KU8_CIL_DTCInhibitionOfAPI              (8u)
/**
 * \brief
 * 		Index of inhibit because of TensSupp signal
 */
#define KU8_CIL_TensSuppInhibition              (16u)
/**
 * \brief
 * 		Index of inhibit because of AccLow signal
 */
#define KU8_CIL_AccLowInhibition                (32u)
/**
 * \brief
 * 		Index of inhibit because of Bckl_SW signal
 */
#define KU8_CIL_Bckl_Sw_Inhibition              (64u)
/**
 * \brief
 * 		Index of delay belt slack decresing mode transition
 */
#define KU8_CIL_DelayModeTransition              (128u)
/**
 * \brief
 * 		Index of inhibit because of Impact X or Y signals
 */
#define KU8_CIL_InhibitionOfImpactX             (256u)
/**
 * \brief
 * 		Index of inhibit because of DTC for PRE-safe cycles
 */
#define KU8_CIL_DTCInhibitionOfPRESAFE           (512u)
/**
 * \brief
 * 		Index of inhibit because of ORC execution
 */
#define KU8_CIL_InhibitionAfterORC            (1024u)
/**
 * \brief
 * 		Index of inhibit to split resuming conditions for BSR
 */
#define KU8_CIL_ResumingInhibitionOfBSR              (2048u)
/**
 * \brief
 * 		Index of inhibit because of Pt Coor Ready signal
 */
#define KU8_CIL_PTReadyInhibition                (4096u)
/**
 * \brief
 * 		Index of inhibit
 */
#define KU8_CIL_DelayBuckleSwitch                (8192u)
/**
 * \brief
 * 		Index of inhibit because of DTC for BSR cycles
 */
#define KU8_CIL_DTCInhibitionOfBSR               (16384u)
/**
 * \brief
 * 		Index of inhibit because of DTC for ORC cycle
 */
#define KU8_CIL_DTCInhibitionOfORC               (32768u)
/**
 * \brief
 * 		Pre-Safe inhibition mask 
 */
#define KU16_CIL_PRESAFE_INHIB_MASK             ((uint16) 0x0757)

/**
 * \brief
 * 		Release inhibition mask 
 */
#define KU16_CIL_REL_INHIB_MASK                 ((uint16) 0x0500)
/**
 * \brief
 * 		BSR inhibition mask 
 */
#define KU16_CIL_BSR_INHIB_MASK                 ((uint16) 0x4501)
/**
 * \brief
 * 		BSR inhibition mask
 */
#define KU16_CIL_ORC_INHIB_MASK                 ((uint16) 0x8457)
/*
 * All abort conditions : all cycles MMG, tensioning cycles MMG, ignition, PresfEnb, PresfTensSupp, API SNA, Bckl_Sw, ImpactXandY;
 * 	bit :                                   7 |           6 |            5 |                4 |            3 |         2 |                      1 |                             0 |
 * 	abortStatus:                     Impact X |Bckl_Sw      |API SNA value |     PresfTensSupp|   PresfEnable|   Ignition|  inhibit all cycles MMG|  inhibit tensioning cycles MMG|
 *
 * 	bit :                                  15 |          14 |           13 |               12 |           11 |        10 |                      9 |                             8 |
 * 	abortStatus:                             x|            x|             x|                 x|             x|TIMEOUT API|      DTC presafe       |               PRE-SAFE SNA    |                                                                               |                       API NA|
 */
/**
 * \brief
 * 		Index of aborting because of tensioning cycles MMG
 */
#define KU8_CIL_AbortingOfTensioning          (1u)
/**
 * \brief
 * 		Index of aborting because of all cycles MMG
 */
#define KU8_CIL_AbortingOfAllCycles           (2u)
/**
 * \brief
 * 		Index of aborting because of Ignition signal
 */
#define KU8_CIL_IgnitionAborting              (4u)
/**
 * \brief
 * 		Index of aborting because of Presf_Enbl signal
 */
#define KU8_CIL_PresfEnableAborting           (8u)
/**
 * \brief
 * 		Index of aborting because of TensSupp signal
 */
#define KU8_CIL_TensSuppAborting              (16u)
/**
 * \brief
 * 		Index of aborting because of API signal SNA 
 */
#define KU8_CIL_ApiSNAAborting                (32u)
/**
 * \brief
 * 		Index of aborting because of Bckl_SW signal
 */
#define KU8_CIL_Bckl_Sw_Aborting              (64u)
/**
 * \brief
 * 		Index of aborting because of Impact X or Y signals
 */
#define KU8_CIL_AbortingOfImpactX            (128u)
/**
 * \brief
 * 		Index of aborting because of Impact X or Y signals
 */
#define KU8_CIL_PresafeSNAAborting           (512u)
/**
 * \brief
 * 		Index of aborting because of DTC for PResafe
 */
#define KU8_CIL_PresafeDTCAborting           (1024u)
/**
 * \brief
 * 		Index of aborting because of DTC for PResafe
 */
#define KU8_CIL_APIDTCAbort                  (2048u)
/**
 * \brief
 * 		Index of inhibit because of DTC for PRE-safe cycles
 */
#define KU8_CIL_BeltHdOvrAbortion             (4096u)
/**
 * \brief
 * 		Index of inhibit because of DTC for PRE-safe cycles
 */
#define KU8_CIL_DrvPosAbortion                 (8192u)
/**
 * \brief
 * 		Index of aborting because of DTC for ORC
 */
#define KU8_CIL_ORCDTCAborting                 (16384u)
/**
 * \brief
 * 		Pre-Safe abortion mask 
 */
#define KU16_CIL_PRESAFE_ABORT_MASK           ((uint16) 0x6DF)

/**
 * \brief
 * 		Release abortion mask 
 */
#define KU16_CIL_REL_ABORT_MASK               ((uint16) 0x00)
/**
 * \brief
 * 		BSR abortion mask 
 */
#define KU16_CIL_BSR_ABORT_MASK               ((uint16) 0x30C3)
/**
 * \brief
 * 		ORC abortion mask
 */
#define KU16_CIL_ORC_ABORT_MASK               ((uint16) 0x4057)
/**
 * \brief
 * 		Macro used for bit clearing inhibition status
 */
#define CIL_SET_INHIB_MASK_OFF(mask)           U16_BIT_CLEAR(CIL_u16InhibitionStatus, (mask))
/**
 * \brief
 * 		Macro used for bit setting inhibition status
 */
#define CIL_SET_INHIB_MASK_ON(mask)            U16_BIT_SET(CIL_u16InhibitionStatus, (mask))
/**
 * \brief
 * 		Macro used for bit clearing aborting status
 */
#define CIL_SET_ABORT_MASK_OFF(mask)           U16_BIT_CLEAR(CIL_u16AbortionStatus, (mask))
/**
 * \brief
 * 		Macro used for bit setting aborting status
 */
#define CIL_SET_ABORT_MASK_ON(mask)            U16_BIT_SET(CIL_u16AbortionStatus, (mask))
/**
 * \brief
 * 		Macro used for checking if Profile is enable in vehicle equipment
 */
#define CIL_VAL_PROFILE_ENABLE(pos)				(uint32)((KU8_ONE)<<((pos)-1))

/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
/**
 * \brief
 *    This variable is used for holding the BltSlck signal
 * \remarks
 *    None.
 */
LOCAL uint8 cil_u8BltSlckDec = I_C02_OFF_ON_ON;
/**
 * \brief
 *		This variable is used for holding the Impact 2 frame
 * \remarks
 *		None.
 */
LOCAL REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh cil_stImpactSignalsStatus2 = {KB_ZERO};
/**
 * \brief
 *		This variable is used for holding the Impact 3 frame
 * \remarks
 *		None.
 */
LOCAL REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19 cil_stImpactSignalsStatus3 = {KU8_ZERO, KU8_ZERO, KU8_CIL_FALSE_ImpactRoTrigger, KU8_CIL_FALSE_ImpactRoTrigger, KU16_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO, KU8_ZERO};
/**
 * \brief
 *		This variable is used for holding the type of executed HWA
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8ExecHAPTIC_TYPE = KU8_CIL_FIXED_HWA;
/**
 * \brief
 *		This variable is used for holding the activation request cycle
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8PreSafeActivationRequest = KU8_NO_CYCLE;
/**
 * \brief
 *		This variable is used for holding the activation request cycle
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8ORC1ActivationRequest = KU8_NO_CYCLE;
/**
 * \brief
 *		This variable is used for holding the activation request cycle
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8ORC2ActivationRequest = KU8_NO_CYCLE;

/**
 * \brief
 *		This variable is used for holding the data of Ign Stat Signal
 * \remarks
 *		None.
 */
LOCAL c03_ISw_Stat cil_u8IgnitionSignal = I_C03_ISW_STAT_SNA;

LOCAL c03_ISw_Stat cil_u8PreviousIgnitionSignal = I_C03_ISW_STAT_SNA;
/**
 * \brief
 *		This variable is used for holding the status of a new ingnition run cycle
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8NewIgnRunCycle = KU8_FALSE;
/**
 * \brief
 *    This variable is used for holding the status of a new ingnition POWER cycle
 * \remarks
 *    None.
 */
static volatile uint8 cil_u8NewIgnPowerCycle = KU8_FALSE;
/**
 * \brief
 *		This variable is used for holding the tensioning aborted status
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8TensioningAbortedStatus = KU8_FALSE;
/**
 * \brief
 *		This variable is used for not resuming the ORC request
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8ORC1Request = KU8_ZERO;
/**
 * \brief
 *		This variable is used for not resuming the ORC request
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8ORC2Request = KU8_ZERO;
/**
 * \brief
 *		This variable is used for mapping profile activation
 * \remarks
 *		None.
 */
LOCAL const uint8 cil_auProfileRequestMap[KU8_TWENTY_SIX] = {/* 0 */     KU8_NO_CYCLE,
		/* 1 Tensioning 1*/		I_C04_PRESF_LVL_V2_LVL1,
		/* 2 Haptik warning 1*/	I_C04_PRESF_LVL_V2_LVL2,
		/* 3 Tensioning 2*/		I_C04_PRESF_LVL_V2_LVL3,
		/* 4 Tensioning 3*/		I_C04_PRESF_LVL_V2_LVL4,
		/* 5 tensioning 4*/		I_C04_PRESF_LVL_V2_LVL5,
		/* 6 tensioning 5*/		I_C04_PRESF_LVL_V2_LVL6,
		/* 7 tensioning 6*/		I_C04_PRESF_LVL_V2_LVL7,
		/* 8 tensioning 7*/		I_C04_PRESF_LVL_V2_LVL8,
		/* 9 tensioning 8*/		I_C06_RBTM_LVL_RQ_PROFILE9,
		/* 10 tensioning 9*/	I_C06_RBTM_LVL_RQ_PROFILE10,
		/* 11 tensioning 10*/	I_C06_RBTM_LVL_RQ_PROFILE11,
		/* 12 tensioning 11*/	I_C06_RBTM_LVL_RQ_PROFILE12,
		/* 13 tensioning 12*/	I_C06_RBTM_LVL_RQ_PROFILE13,
		/* 14 tensioning 13*/	I_C06_RBTM_LVL_RQ_PROFILE14,
		/* 15 tensioning 14*/	I_C06_RBTM_LVL_RQ_PROFILE15,
		/* 16 haptik warning 2*/	I_C06_RBTM_LVL_RQ_PROFILE16,
		/* 17 haptik warning 3*/	I_C06_RBTM_LVL_RQ_PROFILE17,
		/* 18 haptik warning 4*/	I_C06_RBTM_LVL_RQ_PROFILE18,
		/* 19 BSR1*/	I_C06_RBTM_LVL_RQ_PROFILE19,
		/* 20 BSR2*/	I_C06_RBTM_LVL_RQ_PROFILE20,
		/* 21 BSR3*/	I_C06_RBTM_LVL_RQ_PROFILE21,
		/* 22 PreSafe Curve 1*/	I_C06_RBTM_LVL_RQ_PROFILE22,
		/* 23 PreSafe Curve 1*/	I_C06_RBTM_LVL_RQ_PROFILE23,
		/* 24 PreSafe Curve 1*/	I_C06_RBTM_LVL_RQ_PROFILE24,
		/* 25 PreSafe Curve 1*/	I_C06_RBTM_LVL_RQ_PROFILE25,};
/**
 * \brief
 *		This variable is used for extra set of priorities for cycles
 * \remarks
 *		None.
 */
/* [COVERS: DSG_CIL_0010] */
LOCAL const uint8 CIL_u8SourcePrio[KU8_TWENTY_SEVEN] = {/* NO_CYCLE */		KU8_ZERO,
		/* PRE-Safe level 1 */		KU8_TWO,
		/* PRE-Safe level 2 */		KU8_ONE,
		/* PRE-Safe level 3 */	KU8_THREE,
		/* PRE-Safe level 4 */	KU8_FOUR,
		/* PRE-Safe level 5 */	KU8_FIVE,
		/* PRE-Safe level 6 */	KU8_SIX,
		/* PRE-Safe level 7 */	KU8_SEVEN,
		/* PRE-Safe level 8 */	KU8_EIGHT,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* API */ KU8_ZERO,
		/* UNUSED */ KU8_ZERO
} ;
/**
 * \brief
 *		This variable store the value of repetition of haptic profile
 * \remarks
 *		None.
 */
LOCAL uint16 cil_u16HWACounter = KU16_ZERO;
/**
 * \brief
 *		This variable store if BSR is started or not
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8BSRBuckleStarted = KU8_FALSE;
/**
 * \brief
 *		This variable store if BSR is started or not
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8BSRBeltSlackStarted = KU8_FALSE;
/**
 * \brief
 *		This Boolean indicates if HWA1 phase is started
 * \remarks
 *		None.
 */
LOCAL boolean CIL_bHWA1PhaseStarted = B_FALSE;
/**
 * \brief
 *		This Boolean indicates if HWA0 phase is started
 * \remarks
 *		None.
 */
LOCAL boolean CIL_bHWA0PhaseStarted = B_FALSE;
/**
 * \brief
 *		This variable is used to notify if Pre-safe is requested over API
 * \remarks
 *		None.
 */
LOCAL boolean CIL_bPresfAbortApi = B_FALSE;
/**
 * \brief
 *		This holds the tensioning status to be send to presafe recorder
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8TensioningStartedPR = KU8_FALSE;
/**
 * \brief
 *		This holds the tensioning status to be send to presafe recorder
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8TensioningStarted = KU8_FALSE;
/**
 * \brief
 *		This holds the input values for Presafe recorder
 * \remarks
 *		None.
 */
LOCAL REC_PreSafeRecInputType cil_stInputSignalsPresfRec = {KU8_TENSIONING_NONE,I_C02_BCKL_SW_STAT_SNA,I_C04_PRESF_LVL_V2_NOLVL,KU8_ZERO,I_C03_NO_LT_RT_BOTH_NO,KU8_ZERO,KU8_ZERO,I_C03_ISW_STAT_IGN_LOCK, I_C02_BELTHDOVR_STAT_SNA};
/**
 * \brief
 *		This holds flag to see if emergency release after BSR has been executed or not
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8EmergencyRelease = KU8_FALSE;
/**
 * \brief
 *		This holds counter for Acceleration Timeout inhibition
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8AccLowCounter = KU8_ZERO;
/**
 * \brief
 *		This holds counter for power train signal inhibition of BSR after buckle switch
 * \remarks
 *		None.
 */
LOCAL uint16 cil_u16PowertrainDelayCounter = KU16_ZERO;
/**
 * \brief
 *		This holds counter for delay after buckle switch till BSR1
 * \remarks
 *		None.
 */
LOCAL uint16 cil_u16BuckleSwitchDelayCounter = KU16_ZERO;
/**
 * \brief
 *		This holds counter ffor delay after mode transition switch till BSR1
 * \remarks
 *		None.
 */
LOCAL uint16 cil_u16ModeTransitionDelayCounter = KU16_ZERO;
/**
 * \brief
 *		This holds value for acceleartion time delay ( depending of the request )
 * \remarks
 *		None.
 */
LOCAL uint8 cil_u8AccelerationTimeout = KU8_THIRTY;
/**
 * \brief
 *		This holds counter for emergency release after BSR1
 * \remarks
 *		None.
 */
LOCAL uint16 cil_u16EmergencyReleaseCounter = KU16_ZERO;
/**
 * \brief
 *		This holds presafe 5 instead of level 8 request source (API,PRESAFE,ORC)
 * \remarks
 *		None.
 */
LOCAL c04_RBTM_ActvClient cil_u8Presafe5specialRequestSource = I_C04_RBTM_ACTVCLIENT_NONE;
/**
 * \brief
 *		This holds counter forPRESAFE 5 instead of level 8 timeout
 * \remarks
 *		None.
 */
LOCAL uint16 cil_u16Presafe5Timeout = KU16_ZERO;

/**
 * \brief
 *		This holds haptic warning repetition time
 * \remarks
 *		None.
 */
LOCAL uint16 CIL_u16HWARepetitionTime = ((uint16)KU16_ONEHUNDRED);

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/
/**
 * \brief
 *		This variable holds the status of the profile inhibition causes
 * \remarks
 *		None.
 */
/* [COVERS: DSG_CIL_0019] */
uint16 CIL_u16InhibitionStatus = KU16_ZERO;
/**
 * \brief
 *		This variable stores the current requested cycle, old requested cycle,
 *		request source (API or Pre-safe) and inhibition status (true or false)
 * \remarks
 *		None.
 */
/* [COVERS: DSG_CIL_0020] */
CIL_ManageCycle CIL_stManagedCycle = {I_C04_RBTM_ACTVCLIENT_NONE,KU8_NO_CYCLE, KU8_NO_CYCLE, FALSE} ;
/**
 * \brief
 *		This variable stores PS Curve information received from CAN
 * \remarks
 *		None.
 */
c02_Off_Stage1_Stage2 CIL_u8PSCurve = I_C02_OFF_STAGE1_STAGE2_STAGE1;
/**
 * \brief
 *		This variable indicates if Timeout is present for Presafe frame
 * \remarks
 *		None.
 */
boolean CIL_bTimeoutError_Presf = B_FALSE;
/**
 * \brief
 *		This variable indicates if Timeout is present for Buckle frame
 * \remarks
 *		None.
 */
boolean CIL_bTimeoutError_Bckl = B_FALSE;
/**
 * \brief
 *    This variable indicates if Timeout is present for API
 * \remarks
 *    None.
 */
boolean CIL_bTimeoutError_API = B_FALSE;
/**
 * \brief
 *    This variable indicates if Timeout is present for
 * \remarks
 *    None.
 */
boolean CIL_bTimeoutError_BHR = B_FALSE;
/**
 * \brief
 *    This variable indicates if Timeout is present for
 * \remarks
 *    None.
 */
boolean CIL_bTimeoutError_BHL = B_FALSE;
/**
 * \brief
 *    This variable indicates if Timeout is present for Ignition frame
 * \remarks
 *    None.
 */
boolean CIL_bTimeoutError_Ign = B_FALSE;
/**
 * \brief
 *    This variable indicates if Timeout is present for Powertrain frame
 * \remarks
 *    None.
 */
boolean CIL_bTimeoutError_PwTrain = B_FALSE;
/**
 * \brief
 *    This variable indicates if Timeout is present for  frame
 * \remarks
 *    None.
 */
boolean CIL_bTimeoutError_OdoS = B_FALSE;
/**
 * \brief
 *    This variable indicates if Timeout is present for BeltAdj frame
 * \remarks
 *    None.
 */
boolean CIL_bTimeoutError_BeltAdj = B_FALSE;
/**
 *		This holds the belt hand over frame status
 * \remarks
 *		None.
 */
c02_BeltHdOvr_Stat cil_u8BeltHandover = I_C02_BELTHDOVR_STAT_SNA;

/**
 * \brief
 *		This holds the powertrain signal group
 * \remarks
 *		None.
 */
REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw cil_stPTCoor4Pr5St3 = {I_C02_PT_RDY_V2_SNA, I_C03_ENGSTARTPN14_STAT_SNA};
/**
 * \brief
 *    This holds the evcCfg signal group
 * \remarks
 *    None.
 */
REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw cil_evcCfgList0108 = {I_C02_EVC_STAT_SNA, I_C02_EVC_STAT_SNA};
/**
 * \brief
 *    This variable is used for holding the data of Presf Act Adj CAN frame
 * \remarks
 *    None.
 */
REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j cil_stPresfActAdjFrame = {KU32_ZERO, KU8_ZERO, I_C04_PRESF_LVL_V2_NOLVL, KU8_ZERO, KU8_ZERO, I_C02_FALSE_TRUE_SNA_SNA, KU8_ZERO, I_C04_PRESF_LVL_V2_SNA, KU16_ZERO, KU8_ZERO, KU8_ZERO};
/**
 * \brief
 *    This holds the buckle frame status
 * \remarks
 *    None.
 */
REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt stBcklSwStatFrame = {KU8_ZERO, I_C02_BCKL_SW_STAT_SNA, I_C02_BCKL_SW_STAT_SNA, KU16_ZERO, KU8_ZERO};
/**
 * \brief
 *    This variable is used for holding the data of Ign Stat CAN frame
 * \remarks
 *    None.
 */
REC_Ign_Stat_Pr5_ST3 cil_stIgnStatFrame = {I_C03_ISW_STAT_SNA , KU8_ZERO, KU16_ZERO, KU8_ZERO, KB_ZERO};
/**
 * \brief
 *    This variable is used for holding the data of Bckl Sw Stat CAN signal
 * \remarks
 *    None.
 */
c02_Bckl_Sw_Stat cil_u8BcklSwStatSignal = I_C02_BCKL_SW_STAT_SNA;
/**
 * \brief
 *    This holds the belt hand over frame status
 * \remarks
 *    None.
 */
REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh cil_stPTCoorDrvPos = {I_C04_DRVPOSN_ST3_SNA};
/**
 * \brief
 *    This variable store value of the API interface frame
 * \remarks
 *    None.
 */
// ??? INIT values NOK
REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt cil_stAPIInterface ={KU16_MAX,KU8_MAX,KU8_MAX,KU8_MAX,KU8_MAX};
/**
 * \brief
 *		This variable is used for not resuming the LVL8 request
 * \remarks
 *		None.
 */
uint8 cil_u8PRESAFERequest = KU8_FALSE;
/**
 * \brief
 *		This variable is used for not resuming the LVL8  request
 * \remarks
 *		None.
 */
uint8 cil_u8APIRequest = KU8_FALSE;

/**
 * \brief
 *		This variable is used for holding the API activation request cycle
 * \remarks
 *		None.
 */
uint8 cil_u8APIActivationRequest = KU8_NO_CYCLE;
/**
 * \brief
 *		This variable holds the status of the profile abortion causes
 * \remarks
 *		None.
 */
/* [COVERS: DSG_CIL_0065] */
uint16 CIL_u16AbortionStatus = KU16_ZERO;
/**
 * \brief
 *    This variable holds the counter of notifications for presafe frame
 * \remarks
 *    None.
 */
uint8 cil_u8CounterNotifPresf = KU8_ZERO;
/**
 * \brief
 *    This variable holds the counter of notifications for buckle frame
 * \remarks
 *    None.
 */
uint8 cil_u8CounterNotifBckl = KU8_ZERO;
/**
 * \brief
 *    This variable holds the counter of notifications for belthandover left frame
 * \remarks
 *    None.
 */
uint8 cil_u8CounterNotifBltL = KU8_ZERO;
/**
 * \brief
 *    This variable holds the counter of notifications for belthandover right frame
 * \remarks
 *    None.
 */
uint8 cil_u8CounterNotifBltR = KU8_ZERO;
/**
 * \brief
 *    This variable holds the counter of notifications for powertrain frame
 * \remarks
 *    None.
 */
uint8 cil_u8CounterNotifPwt = KU8_ZERO;
/**
 * \brief
 *    This variable is used for holding the data of ProdMd Sw Stat CAN signal
 * \remarks
 *    None.
 */
c03_PN14_ProdMd_Stat_ST3 cil_u8ProdMdSwStatSignal = I_C03_PN14_PRODMD_STAT_ST3_SNA;
/**
 * \brief
 *    This variable is used for holding the data of TransMd Sw Stat CAN signal
 * \remarks
 *    None.
 */
c02_TransMd_Stat cil_u8TransMdSwStatSignal = I_C02_TRANSMD_STAT_SNA;
/**
 * \brief
 *    This variable indicates if Timeout is present for Diag frame
 * \remarks
 *    None.
 */
boolean CIL_bTimeoutError_ExtTest = B_TRUE;
uint8 cil_u8ExtTestPres;
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
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * \brief
 *     The function is called by cil_ManageInputSignals to manage the starting profile conditions and setting inhibition causes
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
/* [COVERS: DSG_CIL_0019] */
LOCAL void cil_ManageInhibitConditions(void)
{
	/* [COVERS: DSG_CIL_0061, DSG_CIL_0062] */
	uint8 u8ContextStatus = KU8_MODE_STATUS_OFF;
	uint32 u32AECGroupStatus = KU32_ZERO;
	uint8 u8ExecutedCycle = KU8_NO_CYCLE;

	/* Get AEC Group status from ERH */
	Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

	/*  Check Cycle in tensioning inhibition from MMG (Index0) */
	(void)Rte_Call_pclModeManagement_CheckModeStatus(KU32_CIL_MASK_TENS_INHIBITING_MODES, &u8ContextStatus);
	/* [COVERS: DSG_CIL_0068; DSG_CIL_0269] */
	if((KU8_MODE_STATUS_OFF != u8ContextStatus) ||
			(KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_STEERING_CONFIG)) )
	{
		CIL_SET_INHIB_MASK_ON (KU8_CIL_InhibitionOfTensioning);
	}
	else
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_InhibitionOfTensioning);
	}

	/* Check All cycle inhibition from MMG (Index1) */
	(void)Rte_Call_pclModeManagement_CheckModeStatus(KU32_CIL_MASK_ALL_INHIBITING_MODES, &u8ContextStatus);

	if(KU8_MODE_STATUS_OFF != u8ContextStatus)
	{
		/* [COVERS: DSG_CIL_0067] */
		CIL_SET_INHIB_MASK_ON (KU8_CIL_InhibitionOfAllCycles);
	}
	else
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_InhibitionOfAllCycles);
	}

	/* Check Ignition inhibition (Index2) */
	if(I_C03_ISW_STAT_IGN_ON == cil_stIgnStatFrame.ISw_Stat_ST3)
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_IgnitionInhibiton);
	}
	else
	{
		/* [COVERS: DSG_CIL_0056] */
		CIL_SET_INHIB_MASK_ON (KU8_CIL_IgnitionInhibiton);
	}

	/* Check DTC API inhibition (Index3) */
	if(KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_API))
	{
		CIL_SET_INHIB_MASK_ON (KU8_CIL_DTCInhibitionOfAPI);
	}
	else
	{
		CIL_SET_INHIB_MASK_OFF(KU8_CIL_DTCInhibitionOfAPI);
	}

	/* Check Presf_TensSupp inhibition (Index4) SNA */
	if(I_C03_NO_LT_RT_BOTH_NO == cil_stPresfActAdjFrame.PresfAct_TensSupp_Rq_ST3)
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_TensSuppInhibition);
		cil_stInputSignalsPresfRec.u8TensSuppType = I_C03_NO_LT_RT_BOTH_NO;
	}
	else if(I_C03_NO_LT_RT_BOTH_BOTH == cil_stPresfActAdjFrame.PresfAct_TensSupp_Rq_ST3)
	{
		/* [COVERS: DSG_CIL_0129] */
		CIL_SET_INHIB_MASK_ON (KU8_CIL_TensSuppInhibition);
		cil_stInputSignalsPresfRec.u8TensSuppType = I_C03_NO_LT_RT_BOTH_LEFT;
	}
	else
	{
		if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
		{
			if(I_C03_NO_LT_RT_BOTH_LEFT == cil_stPresfActAdjFrame.PresfAct_TensSupp_Rq_ST3)
			{
				/* [COVERS: DSG_CIL_0129] */
				CIL_SET_INHIB_MASK_ON (KU8_CIL_TensSuppInhibition);
				cil_stInputSignalsPresfRec.u8TensSuppType = I_C03_NO_LT_RT_BOTH_LEFT;
			}
			else
			{
				CIL_SET_INHIB_MASK_OFF (KU8_CIL_TensSuppInhibition);
				cil_stInputSignalsPresfRec.u8TensSuppType = I_C03_NO_LT_RT_BOTH_NO;
			}

		}
		else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
		{
			if(I_C03_NO_LT_RT_BOTH_RIGHT == cil_stPresfActAdjFrame.PresfAct_TensSupp_Rq_ST3)
			{
				/* [COVERS: DSG_CIL_0129] */
				CIL_SET_INHIB_MASK_ON(KU8_CIL_TensSuppInhibition);
				cil_stInputSignalsPresfRec.u8TensSuppType = I_C03_NO_LT_RT_BOTH_LEFT;
			}
			else
			{
				CIL_SET_INHIB_MASK_OFF (KU8_CIL_TensSuppInhibition);
				cil_stInputSignalsPresfRec.u8TensSuppType = I_C03_NO_LT_RT_BOTH_NO;
			}
		}
		else
		{
			/*Nothing to do*/
		}
	}


	/* [COVERS: DSG_CIL_0055; DSG_CIL_0251; DSG_CIL_0252; DSG_CIL_0253] */
	if (I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER == CIL_stManagedCycle.u8RequestSource)
	{
		cil_u8AccelerationTimeout = ((uint16)(NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8APIAccelerationTimeout));
	}
	else if( ( I_C04_RBTM_ACTVCLIENT_PRESAFE == CIL_stManagedCycle.u8RequestSource) && (I_C04_PRESF_LVL_V2_LVL2 != CIL_stManagedCycle.u8CurrentRequestedCycle) && (KU8_NO_CYCLE != CIL_stManagedCycle.u8CurrentRequestedCycle))
	{
		cil_u8AccelerationTimeout = ((uint16)(NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8PRESAFEAccelerationTimeout));
	}
	else if( ( I_C04_RBTM_ACTVCLIENT_PRESAFE == CIL_stManagedCycle.u8RequestSource) && (I_C04_PRESF_LVL_V2_LVL2 == CIL_stManagedCycle.u8CurrentRequestedCycle) )
	{
		cil_u8AccelerationTimeout = ((uint16)(NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8Haptic1AccelerationTimeout));
	}
	else if( ( KU8_TRUE == cil_u8BSRBuckleStarted) || (KU8_TRUE == cil_u8BSRBeltSlackStarted) )
	{
		cil_u8AccelerationTimeout = ((uint16)(NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8BSR1AccelerationTimeout));
	}
	else
	{
		/* Nothing to do - keep last value */
	}

	/* Check Acceleration Low inhibition (Index5) */
	/* [COVERS: DSG_CIL_0161] */
	if( (KU8_TWO == cil_stPresfActAdjFrame.PresfAccelReset_NotExcd_ST3) ||
			(B_TRUE == CIL_bTimeoutError_Presf) ||
			(I_C02_FALSE_TRUE_SNA_SNA == cil_stPresfActAdjFrame.PresfAccelReset_NotExcd_ST3) )
	{
		if (cil_u8AccLowCounter <= cil_u8AccelerationTimeout)
		{
			cil_u8AccLowCounter++;
			CIL_SET_INHIB_MASK_ON (KU8_CIL_AccLowInhibition);
		}
		else
		{
			CIL_SET_INHIB_MASK_OFF (KU8_CIL_AccLowInhibition);
		}
	}
	else
	{
		cil_u8AccLowCounter = KU8_ZERO;
		CIL_SET_INHIB_MASK_ON (KU8_CIL_AccLowInhibition);
	}

	/* [COVERS: DSG_CIL_0254] */
	(void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);
	if (KU8_CIL_BSR_CYCLE == u8ExecutedCycle)
	{
		cil_u8EmergencyRelease = KU8_ONE;
		cil_u16EmergencyReleaseCounter = KU16_ZERO;
	}
	else if (KU8_ONE == cil_u8EmergencyRelease)
	{
		cil_u8EmergencyRelease = KU8_TWO;
	}
	else
	{
		/* Nothing to do */
	}

	if( (KU8_TWO == cil_u8EmergencyRelease) &&
			(KU16_ZERO != (CIL_u16InhibitionStatus & KU8_CIL_AccLowInhibition)))
	{
		if (cil_u16EmergencyReleaseCounter <= KU16_CIL_EMERGENCY_RELEASE)
		{
			cil_u16EmergencyReleaseCounter++;
		}
		else
		{
			CIL_SET_INHIB_MASK_OFF (KU8_CIL_AccLowInhibition);
		}
	}

	/* Check Bckl_Sw inhibition (Index6) */
	if(I_C02_BCKL_SW_STAT_OK == cil_u8BcklSwStatSignal)
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_Bckl_Sw_Inhibition);
	}
	else
	{
		/* [COVERS: DSG_CIL_0057, DSG_CIL_0058] */
		CIL_SET_INHIB_MASK_ON (KU8_CIL_Bckl_Sw_Inhibition);
	}

	/* Check Impact XY inhibition (Index7) */
	if(KU8_ZERO == cil_stImpactSignalsStatus3.Impact_X_ST3)
	{
		/* Crash until a new ignition cycle */
		if (KU8_TRUE == cil_u8NewIgnRunCycle)
		{
			CIL_SET_INHIB_MASK_OFF (KU8_CIL_InhibitionOfImpactX);
		}
	}
	else
	{
		/* [COVERS: DSG_CIL_0063, DSG_CIL_0064] */
		CIL_SET_INHIB_MASK_ON (KU8_CIL_InhibitionOfImpactX);
	}

	/* Check special PRESAFE inhibiton conditions are qualified */
	/* [COVERS: DSG_CIL_0378; DSG_CIL_0779] */
    /* [COVERS: DSG_CIL_0054] */
	if( (KU32_ZERO != (u32AECGroupStatus & (KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION | KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE | KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION)) ) ||
			(KU8_ZERO != NVP_stVehicleEquipmentData.PreSafeFuncActivation) ||
            (I_C02_FALSE_TRUE_SNA_TRUE != cil_stPresfActAdjFrame.Presf_Enbl_ST3) )
	{
		CIL_SET_INHIB_MASK_ON (KU8_CIL_DTCInhibitionOfPRESAFE);
	}
	else
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_DTCInhibitionOfPRESAFE);
	}

	/* Check execution of Presafe level 8 or ORC or API*/
	/* [COVERS: DSG_CIL_0162] */
	if(KU8_PRECRASH_SEVERITY_LEVEL_7 == u8ExecutedCycle)
	{
		CIL_SET_INHIB_MASK_ON (KU8_CIL_InhibitionAfterORC);
	}
	else
	{
		/* Crash until a new ignition cycle */
		if (KU8_TRUE == cil_u8NewIgnRunCycle)
		{
            /* issue 819539 */
            cil_u8TensioningAbortedStatus = KU8_FALSE;
            CIL_SET_INHIB_MASK_OFF (KU8_CIL_InhibitionAfterORC);
            if (I_C04_RBTM_ACTVCLIENT_POSTCRASH == CIL_stManagedCycle.u8RequestSource)
            {
               CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_NONE;
               CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
               CIL_stManagedCycle.u8CurrentRequestedCycle = KU8_NO_CYCLE;
               cil_u8TensioningStarted = KU8_FALSE;
            }
		}
	}

	/* [COVERS: DSG_CIL_0174] */
	if(I_C02_PT_RDY_V2_PT_RDY != cil_stPTCoor4Pr5St3.PT4_PTCoor_PT_Rdy_ST3)
	{
		CIL_SET_INHIB_MASK_ON (KU8_CIL_PTReadyInhibition);
		cil_u16PowertrainDelayCounter = KU8_ZERO;
	}
	else
	{
		if (cil_u16PowertrainDelayCounter <= KU16_CIL_POWERTRAIN_DELAY)
		{
			cil_u16PowertrainDelayCounter++;
			CIL_SET_INHIB_MASK_ON (KU8_CIL_PTReadyInhibition);
		}
		else
		{
			CIL_SET_INHIB_MASK_OFF (KU8_CIL_PTReadyInhibition);
		}
	}

	/* Check Cycle for BSR from MMG inhibition (Index8) */
	(void)Rte_Call_pclModeManagement_CheckModeStatus(KU32_CIL_MASK_BSR_INHIBITING_MODES, &u8ContextStatus);
	/* Check special BSR inhibiton conditions are qualified: */
	/* [COVERS: DSG_CIL_0378; DSG_CIL_0069] */
	/* [COVERS: DSG_CIL_0175; DSG_CIL_0264] */
	if(  (I_C04_RBTM_ACTVCLIENT_PRESAFE == CIL_stManagedCycle.u8RequestSource) ||
			(KU8_MODE_STATUS_OFF != u8ContextStatus) ||
			(KU8_ZERO != NVP_stVehicleEquipmentData.BSRActivation) )
	{
		CIL_SET_INHIB_MASK_ON (KU8_CIL_DTCInhibitionOfBSR);
	}
	else
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_DTCInhibitionOfBSR);
	}

	/* Check context for Measured KL30 battery voltage */
	(void)Rte_Call_pclModeManagement_CheckModeStatus(MMG_KU32_MASK_AEC_INHIB_ALL_CYCLES, &u8ContextStatus);
	/* [COVERS: DSG_CIL_0176; DSG_CIL_0378] */
	if( (KU8_MODE_STATUS_OFF != u8ContextStatus) ||
			(I_C04_DRVPOSN_ST3_R == cil_stPTCoorDrvPos.PT4_PTCoor_DrvPosn_Stat_ST3) ||
			((KU8_ZERO == NVP_stVehicleEquipmentData.BltHandOverAvailabiliy)&& (I_C02_BELTHDOVR_STAT_RETRACT != cil_u8BeltHandover))/* YES */ ||
            ( KU32_ZERO != (u32AECGroupStatus & (KU32_AEC_GROUP_MASK_TIMEOUT_BH_R|KU32_AEC_GROUP_MASK_TIMEOUT_BH_L ))) )
	{
		CIL_SET_INHIB_MASK_ON (KU8_CIL_ResumingInhibitionOfBSR);
	}
	else
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_ResumingInhibitionOfBSR);
	}

	/* Check special ORC inhibiton conditions are qualified*/
	/* [COVERS: DSG_CIL_0378; DSG_CIL_0781] */
	if((KU32_ZERO != (u32AECGroupStatus & (KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION | KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION)) ) ||
			(KU8_ZERO != NVP_stVehicleEquipmentData.ORCPreSafe8Activation) )
	{
		CIL_SET_INHIB_MASK_ON (KU8_CIL_DTCInhibitionOfORC);
	}
	else
	{
		CIL_SET_INHIB_MASK_OFF (KU8_CIL_DTCInhibitionOfORC);
	}

	if( (I_C02_BCKL_SW_STAT_OK == cil_u8BcklSwStatSignal) && (KU8_TRUE == cil_u8BSRBuckleStarted) )
	{
		if (cil_u16BuckleSwitchDelayCounter <= KU16_CIL_AFTER_BUCKLE_DELAY)
		{
			cil_u16BuckleSwitchDelayCounter++;
			CIL_SET_INHIB_MASK_ON (KU8_CIL_DelayBuckleSwitch);
		}
		else
		{
			CIL_SET_INHIB_MASK_OFF (KU8_CIL_DelayBuckleSwitch);
		}
	}
	else
	{
		cil_u16BuckleSwitchDelayCounter = KU8_ZERO;
	}

	/* [COVERS: DSG_CIL_0263;] */
	if( (I_C02_OFF_ON_ON == NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode) && (KU8_TRUE == cil_u8BSRBeltSlackStarted) )
	{
		if (cil_u16ModeTransitionDelayCounter <= KU16_CIL_AFTER_MD_DELAY)
		{
			cil_u16ModeTransitionDelayCounter++;
			CIL_SET_INHIB_MASK_ON (KU8_CIL_DelayModeTransition);
		}
		else
		{
			CIL_SET_INHIB_MASK_OFF (KU8_CIL_DelayModeTransition);
		}
	}
	else
	{
		cil_u16ModeTransitionDelayCounter = KU8_ZERO;
	}


	if (KU16_ZERO != (CIL_u16InhibitionStatus & KU16_CIL_REL_INHIB_MASK) )
	{
		Rte_Write_psrCustomerSpecific_b8SignalRelInhibition(KU8_TRUE);
	}
	else
	{
		Rte_Write_psrCustomerSpecific_b8SignalRelInhibition(KU8_FALSE);
	}

}

/**
 * \brief
 *     The function is called by cil_ManageInputSignals to manage the aborting conditions
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
/* [COVERS: DSG_CIL_0065] */
LOCAL void cil_ManageAbortingConditions(void)
{
	uint8 u8ContextStatus = KU8_MODE_STATUS_OFF;
	uint32 u32AECGroupStatus = KU32_ZERO;

	/* Check Cycle in tensioning aborting from MMG (Index0) */
	(void)Rte_Call_pclModeManagement_CheckModeStatus(KU32_CIL_MASK_TENS_ABORTING_MODES, &u8ContextStatus);

	/* [COVERS: DSG_CIL_0071] */
	if(KU8_MODE_STATUS_OFF != u8ContextStatus)
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_AbortingOfTensioning);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_AbortingOfTensioning);
	}

	/* Check All cycle aborting from MMG (Index1) */
	/* [COVERS: DSG_CIL_0070] */
	(void)Rte_Call_pclModeManagement_CheckModeStatus(KU32_CIL_MASK_ALL_ABORTING_MODES, &u8ContextStatus);

	if(KU8_MODE_STATUS_OFF != u8ContextStatus)
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_AbortingOfAllCycles);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_AbortingOfAllCycles);
	}

	/* Check Ignition aborting (Index2) */
	/* [COVERS: DSG_CIL_0056] */
	if(I_C03_ISW_STAT_IGN_ON != cil_stIgnStatFrame.ISw_Stat_ST3)
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_IgnitionAborting);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_IgnitionAborting);
	}

	/* Check Presf_Enbl aborting (Index3) */
	/* [COVERS: DSG_CIL_0054] */
	if(I_C02_FALSE_TRUE_SNA_TRUE != cil_stPresfActAdjFrame.Presf_Enbl_ST3)
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_PresfEnableAborting);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_PresfEnableAborting);
	}

	/* Check Presf_TensSupp aborting (Index4) */
	if(I_C03_NO_LT_RT_BOTH_BOTH == cil_stPresfActAdjFrame.PresfAct_TensSupp_Rq_ST3)
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_TensSuppAborting);
	}
	else
	{
		if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
		{
			if(I_C03_NO_LT_RT_BOTH_LEFT == cil_stPresfActAdjFrame.PresfAct_TensSupp_Rq_ST3)
			{
				CIL_SET_ABORT_MASK_ON (KU8_CIL_TensSuppAborting);
			}
			else
			{
				CIL_SET_ABORT_MASK_OFF (KU8_CIL_TensSuppAborting); 
			}

		}
		else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
		{
			if(I_C03_NO_LT_RT_BOTH_RIGHT == cil_stPresfActAdjFrame.PresfAct_TensSupp_Rq_ST3)
			{
				CIL_SET_ABORT_MASK_ON (KU8_CIL_TensSuppAborting);
			}
			else
			{
				CIL_SET_ABORT_MASK_OFF (KU8_CIL_TensSuppAborting); 
			}
		}
		else
		{
			/* QAC */
		}
	}

	/* Check API SNA aborting(Index 5) */
	if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
	{
		if(I_C06_RBTM_LVL_RQ_SNA == cil_stAPIInterface.RBTMFL_SP_Lvl_Rq_ST35)
		{
			CIL_SET_ABORT_MASK_ON (KU8_CIL_ApiSNAAborting); 
		}
		else
		{
			CIL_SET_ABORT_MASK_OFF (KU8_CIL_ApiSNAAborting);
		}
	}
	else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
	{
		if(I_C06_RBTM_LVL_RQ_SNA == cil_stAPIInterface.RBTMFR_SP_Lvl_Rq_ST35)
		{
			CIL_SET_ABORT_MASK_ON (KU8_CIL_ApiSNAAborting); 
		}
		else
		{
			CIL_SET_ABORT_MASK_OFF (KU8_CIL_ApiSNAAborting);
		}
	}
	else
	{
		/* QAC */
	}

	/* Check Bckl_Sw aborting (Index6) */
	if(I_C02_BCKL_SW_STAT_OK != cil_u8BcklSwStatSignal)
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_Bckl_Sw_Aborting);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_Bckl_Sw_Aborting);
	}

	/* Check Impact X aborting (Index7) */
	if(KU8_ONE == cil_stImpactSignalsStatus3.Impact_X_ST3)
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_AbortingOfImpactX);
	}
	else
	{
		/* Crash until a new ignition cycle */
		if (KU8_TRUE == cil_u8NewIgnRunCycle)
		{
			CIL_SET_ABORT_MASK_OFF (KU8_CIL_AbortingOfImpactX);
		}
	}

	/* [COVERS: DSG_CIL_0160] */
	if(I_C04_PRESF_LVL_V2_SNA == cil_stPresfActAdjFrame.Presf_Lvl_ST3)
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_PresafeSNAAborting);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_PresafeSNAAborting);
	}

	/* Get AEC group status */
	(void)Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);
	/* [COVERS: DSG_CIL_0786] */
	/* Check if PRE SFAE inhibition DTC are qualified: */
	if(KU32_ZERO != (u32AECGroupStatus & (KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION|KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE|KU32_AEC_GROUP_MASK_TIMEOUT_PRESAFE|KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION)) )
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_PresafeDTCAborting);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_PresafeDTCAborting);
	}

	/* Check if PRE SFAE inhibition DTC are qualified: */
	/* [COVERS: DSG_CIL_0785] */
	if((B_TRUE == CIL_bTimeoutError_API ) ||
       (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_API)) )
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_APIDTCAbort);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_APIDTCAbort);
	}

	/* [COVERS: DSG_CIL_0383] */
	if (KU8_ZERO == NVP_stVehicleEquipmentData.BltHandOverAvailabiliy) /* YES */
	{
		if (I_C02_BELTHDOVR_STAT_RETRACT != cil_u8BeltHandover)
		{
			CIL_SET_ABORT_MASK_ON (KU8_CIL_BeltHdOvrAbortion);
		}
		else
		{
			CIL_SET_ABORT_MASK_OFF (KU8_CIL_BeltHdOvrAbortion);
		}
	}
	else /* NO */
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_BeltHdOvrAbortion);
	}

	/* [COVERS: DSG_CIL_0382] */
	if( (I_C04_DRVPOSN_ST3_R == cil_stPTCoorDrvPos.PT4_PTCoor_DrvPosn_Stat_ST3) ||
			(I_C04_RBTM_ACTVCLIENT_PRESAFE == CIL_stManagedCycle.u8RequestSource))
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_DrvPosAbortion);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_DrvPosAbortion);
	}

	/* [COVERS: DSG_CIL_0784] */
	if(KU32_ZERO != (u32AECGroupStatus & (KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION|KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION)) )
	{
		CIL_SET_ABORT_MASK_ON (KU8_CIL_ORCDTCAborting);
	}
	else
	{
		CIL_SET_ABORT_MASK_OFF (KU8_CIL_ORCDTCAborting);
	}
}
/**
 * \brief
 *     Function used to update the input signals
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void cil_ManageInputSignals(void)
{
    u8AecStatusType u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;
    
   /*Determine if a new ignition run cycle happens */
   /* [COVERS: DSG_CIL_0163] */
   if( (cil_u8IgnitionSignal != cil_stIgnStatFrame.ISw_Stat_ST3) && (I_C03_ISW_STAT_IGN_LOCK == cil_stIgnStatFrame.ISw_Stat_ST3) )
   {
      cil_u8NewIgnRunCycle = KU8_TRUE;
   }
   else
   {
      cil_u8NewIgnRunCycle = KU8_FALSE;
   }
   cil_u8IgnitionSignal = cil_stIgnStatFrame.ISw_Stat_ST3;

   /* [COVERS: DSG_CIL_0007] */
   if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
   {
      /* API signal */
      /* Check diff from SNA -> no profile mapped */
      if( (I_C06_RBTM_LVL_RQ_SNA == cil_stAPIInterface.RBTMFL_SP_Lvl_Rq_ST35) ||
            (I_C06_RBTM_LVL_RQ_PROFILE25 < cil_stAPIInterface.RBTMFL_SP_Lvl_Rq_ST35) )
      {
         /* Nothing to do - No update on request*/
      }
      else
      {
         /* [COVERS: DSG_CIL_0130] */
         cil_u8APIActivationRequest = cil_auProfileRequestMap[cil_stAPIInterface.RBTMFL_SP_Lvl_Rq_ST35];
      }
      /* [COVERS: DSG_CIL_0009, DSG_CIL_0016] */
      (void)Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3(&CIL_u8PSCurve);
   }
   /* [COVERS: DSG_CIL_0007] */
   else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
   {
      /* API signal */
      /* Check diff from SNA -> no profile mapped */
      if( (I_C06_RBTM_LVL_RQ_SNA == cil_stAPIInterface.RBTMFR_SP_Lvl_Rq_ST35) ||
            (I_C06_RBTM_LVL_RQ_PROFILE25 < cil_stAPIInterface.RBTMFR_SP_Lvl_Rq_ST35) )
      {
         /* Nothing to do - No update on request*/
      }
      else
      {
         /* [COVERS: DSG_CIL_0131] */
         cil_u8APIActivationRequest = cil_auProfileRequestMap[cil_stAPIInterface.RBTMFR_SP_Lvl_Rq_ST35];
      }
      /* [COVERS: DSG_CIL_0009] */
      (void)Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3(&CIL_u8PSCurve);
   }
   else
   {
      /* QAC */
   }

   /* Manage API Request with LVL 8 no resuming */
   if( (I_C04_PRESF_LVL_V2_LVL8 == cil_u8APIActivationRequest) &&
         ( KU16_ZERO != (CIL_u16InhibitionStatus & (KU16_CIL_API_INHIB_MASK^KU8_CIL_InhibitionAfterORC))) )
   {
      cil_u8APIRequest = KU8_TRUE;
      cil_u8APIActivationRequest = KU8_NO_CYCLE;
   }
   else if( (I_C04_PRESF_LVL_V2_LVL8 == cil_u8APIActivationRequest) &&
         ( KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_API_INHIB_MASK)) &&
         (KU8_TRUE == cil_u8APIRequest))
   {
      /* keep NO resuming */
      cil_u8APIActivationRequest = KU8_NO_CYCLE;
   }
   else
   {
      /* Clear */
      cil_u8APIRequest = KU8_FALSE;
   }

   /* Check if no SNA -> no profile mapped */
   if ( (I_C04_PRESF_LVL_V2_SNA == cil_stPresfActAdjFrame.Presf_Lvl_ST3) ||
         (I_C04_PRESF_LVL_V2_LVL8 < cil_stPresfActAdjFrame.Presf_Lvl_ST3) )
   {
      /* nothing to do - No update for profile request */
      /* issue 816503 */
   }
   else
   {
      /* [COVERS: DSG_CIL_0075; DSG_CIL_0266] */
      cil_u8PreSafeActivationRequest = cil_auProfileRequestMap[cil_stPresfActAdjFrame.Presf_Lvl_ST3];

      /* Manage PRE-SAFE Request with LVL 8 no resuming */
      if( (I_C04_PRESF_LVL_V2_LVL8 == cil_u8PreSafeActivationRequest) &&
            ( KU16_ZERO != (CIL_u16InhibitionStatus & (KU16_CIL_PRESAFE_INHIB_MASK^KU8_CIL_InhibitionAfterORC))) )
      {
         /* If profile is inhibited - will be ignored */
         cil_u8PRESAFERequest = KU8_TRUE;
         cil_u8PreSafeActivationRequest = KU8_NO_CYCLE;
      }
      else if( (I_C04_PRESF_LVL_V2_LVL8 == cil_u8PreSafeActivationRequest) &&
            ( KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK)) &&
            (KU8_TRUE == cil_u8PRESAFERequest))
      {
         /* if conditions for inhibition dissapear */
         /* keep NO resuming */
         cil_u8PreSafeActivationRequest = KU8_NO_CYCLE;
      }
      else
      {
         /* Clear */
         cil_u8PRESAFERequest = KU8_FALSE;
      }
   }

   /* [COVERS: DSG_CIL_0266] */
   /* Manage ORC request */
   if (KU8_CIL_TRUE_ImpactRoTrigger == cil_stImpactSignalsStatus3.Impact_RO_type1_ST3)
   {
      if (KU8_FALSE == cil_u8ORC1Request)
      {
         cil_u8ORC1ActivationRequest = I_C04_PRESF_LVL_V2_LVL8;
      }
   }
   else
   {
      cil_u8ORC1ActivationRequest = KU8_NO_CYCLE;
      cil_u8ORC1Request = KU8_FALSE;
   }

   if(KU8_CIL_TRUE_ImpactRoTrigger == cil_stImpactSignalsStatus3.Impact_RO_type2_ST3)
   {
      if (KU8_FALSE == cil_u8ORC2Request)
      {
         cil_u8ORC2ActivationRequest = I_C04_PRESF_LVL_V2_LVL8;
      }
   }
   else
   {
      cil_u8ORC2ActivationRequest = KU8_NO_CYCLE;
      cil_u8ORC2Request = KU8_FALSE;
   }

   /* No resuming if ORC request inhibited*/
   if( (I_C04_PRESF_LVL_V2_LVL8 == cil_u8ORC1ActivationRequest) &&
         ( KU16_ZERO != (CIL_u16InhibitionStatus & KU16_CIL_ORC_INHIB_MASK)) )
   {
      cil_u8ORC1ActivationRequest = KU8_NO_CYCLE;
      cil_u8ORC1Request = KU8_TRUE;
   }

   if( (I_C04_PRESF_LVL_V2_LVL8 == cil_u8ORC2ActivationRequest) &&
         ( KU16_ZERO != (CIL_u16InhibitionStatus & KU16_CIL_ORC_INHIB_MASK)) )
   {
      cil_u8ORC2ActivationRequest = KU8_NO_CYCLE;
      cil_u8ORC2Request = KU8_TRUE;
   }


   /* Decide BSR after inhibition update to be resumed corectly*/

   /* [COVERS: DSG_CIL_0007] */
   if(KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION)
   {
      /* Buckle signal */
      /* [COVERS: DSG_CIL_0378] */
      if (KU8_ONE == NVP_stVehicleEquipmentData.VehicleSteeringConfig) /* Left hand drive vehicle */
      {
         /* [COVERS: DSG_CIL_0268] */
         if( (I_C02_BCKL_SW_STAT_NOT == cil_u8BcklSwStatSignal) &&
               (I_C02_BCKL_SW_STAT_OK == stBcklSwStatFrame.Bckl_Sw_D_Stat_ST3) &&
               (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_BSR_INHIB_MASK) ) &&
               (I_C02_OFF_ON_ON == NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode) )
         {
            cil_u8BSRBuckleStarted = KU8_TRUE;
         }
         cil_u8BcklSwStatSignal = stBcklSwStatFrame.Bckl_Sw_D_Stat_ST3;
      }
      /* [COVERS: DSG_CIL_0378] */
      else if (KU8_ZERO == NVP_stVehicleEquipmentData.VehicleSteeringConfig) /* Right hand drive vehicle */
      {
         /* [COVERS: DSG_CIL_0268] */
         if( (I_C02_BCKL_SW_STAT_NOT == cil_u8BcklSwStatSignal) &&
               (I_C02_BCKL_SW_STAT_OK == stBcklSwStatFrame.Bckl_Sw_FP_Stat_ST3) &&
               (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_BSR_INHIB_MASK)) &&
               (I_C02_OFF_ON_ON == NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode) )
         {
            cil_u8BSRBuckleStarted = KU8_TRUE;
         }
         /* [COVERS: DSG_CIL_0017] */
         cil_u8BcklSwStatSignal = stBcklSwStatFrame.Bckl_Sw_FP_Stat_ST3;
      }
   }
   /* [COVERS: DSG_CIL_0007] */
   else if(KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)
   {
      /* Buckle signal */
      /* [COVERS: DSG_CIL_0378] */
      if (KU8_ONE == NVP_stVehicleEquipmentData.VehicleSteeringConfig) /* Left hand drive vehicle */
      {
         /* [COVERS: DSG_CIL_0268] */
         if( (I_C02_BCKL_SW_STAT_NOT == cil_u8BcklSwStatSignal) &&
               (I_C02_BCKL_SW_STAT_OK == stBcklSwStatFrame.Bckl_Sw_FP_Stat_ST3) &&
               (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_BSR_INHIB_MASK) ) &&
               (I_C02_OFF_ON_ON == NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode) )
         {
            cil_u8BSRBuckleStarted = KU8_TRUE;
         }
         /* [COVERS: DSG_CIL_0017] */
         cil_u8BcklSwStatSignal = stBcklSwStatFrame.Bckl_Sw_FP_Stat_ST3;
      }
      /* [COVERS: DSG_CIL_0378] */
      else if (KU8_ZERO == NVP_stVehicleEquipmentData.VehicleSteeringConfig) /* Right hand drive vehicle */
      {
         /* [COVERS: DSG_CIL_0268] */
         if( (I_C02_BCKL_SW_STAT_NOT == cil_u8BcklSwStatSignal) &&
               (I_C02_BCKL_SW_STAT_OK == stBcklSwStatFrame.Bckl_Sw_D_Stat_ST3) &&
               (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_BSR_INHIB_MASK) ) &&
               (I_C02_OFF_ON_ON == NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode) )
         {
            cil_u8BSRBuckleStarted = KU8_TRUE;
         }
         /* [COVERS: DSG_CIL_0007] */
         cil_u8BcklSwStatSignal = stBcklSwStatFrame.Bckl_Sw_D_Stat_ST3;
      }
   }
   else
   {
      /* QAC */
   }

   /* [COVERS: DSG_CIL_0255; DSG_CIL_0261; DSG_CIL_0262] */
   /* If no timeout and  no SNA */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_BELT_ADJ_AEC_CFG, &u8AECStatus);

   if((I_C02_OFF_ON_SNA != cil_u8BltSlckDec) && (ERH_KU8_AEC_QUALIFIED_STATUS_MASK  != (u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))) /* CHECK DTC */
   {
      /* [COVERS: DSG_CIL_0268] */
      if( (I_C02_OFF_ON_OFF == NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode) && (I_C02_OFF_ON_ON == cil_u8BltSlckDec) &&
            ( (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_BSR_INHIB_MASK))) &&
            (I_C02_BCKL_SW_STAT_OK == cil_u8BcklSwStatSignal ) )
      {
         cil_u8BSRBeltSlackStarted = KU8_TRUE;
      }

      if(NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode != cil_u8BltSlckDec)
      {
         NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8BeltSlkDecMode = cil_u8BltSlckDec;
         (void)Rte_Write_psrCANInputBlockStatus_b8NVMBlockStatus(KU8_TRUE);
      }
   }

   /* [COVERS: DSG_CIL_0309; DSG_CIL_0310; DSG_CIL_0311] */
   if (I_C02_OFF_STAGE1_STAGE2_SNA != CIL_u8PSCurve)
   {
	   if(NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8PSCurveConfig != CIL_u8PSCurve)
	   {
		   NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8PSCurveConfig = CIL_u8PSCurve;
		   (void)Rte_Write_psrCANInputBlockStatus_b8NVMBlockStatus(KU8_TRUE);
	   }
   }

   /* Compute Inhibition conditions */
   cil_ManageInhibitConditions();

   /* Compute Abortion conditions */
   cil_ManageAbortingConditions();

   (void)Rte_IrvWrite_CIL_runCANToAppli_u8BuckleStatus(cil_u8BcklSwStatSignal);   // to do remove?

   cil_stInputSignalsPresfRec.bImpactXType= cil_stImpactSignalsStatus3.Impact_X_ST3;
   cil_stInputSignalsPresfRec.u8BuckleStateType = cil_u8BcklSwStatSignal;
   cil_stInputSignalsPresfRec.u8PresafeLevelType = cil_stPresfActAdjFrame.Presf_Lvl_ST3;
   cil_stInputSignalsPresfRec.bRoEventType1 = cil_stImpactSignalsStatus3.Impact_RO_type1_ST3;
   cil_stInputSignalsPresfRec.bRoEventType2 = cil_stImpactSignalsStatus3.Impact_RO_type2_ST3;
   cil_stInputSignalsPresfRec.u8IgnStat = cil_stIgnStatFrame.ISw_Stat_ST3;
   cil_stInputSignalsPresfRec.u8BeltHdOvStat = cil_u8BeltHandover;

   /* [COVERS: DSG_CIL_0004] */
   /* Send presafe lvl to EOL module in order to increment Request counter*/
   Rte_Write_psrPreSafeLvl_u8PreSafeLvl(cil_stPresfActAdjFrame.Presf_Lvl_ST3);
}
/**
 * \brief
 *     The function is called by CIL_runCANToAppli to trigger haptic repetition
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void cil_ManageHapticRepetition(const uint8 u8CycleRequest)
{
	uint8 u8ExecutedCycle = KU8_NO_CYCLE;
	static uint8 u8HWAExecuted = KU8_ZERO;

	/* If non fixed duration when no action is requested end.
	 * If fixed duration do function
	 */
	(void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);

	/* [COVERS: DSG_CIL_0011, DSG_CIL_0152; DSG_CIL_0177; DSG_CIL_0178] */
	switch(u8ExecutedCycle)
	{
	case KU8_CIL_HWA10_CYCLE :
		CIL_u16HWARepetitionTime = ((uint16)(NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u16DurationHaptic1)/KU16_TEN);
		CIL_bHWA0PhaseStarted = B_TRUE;
		u8HWAExecuted = I_C04_PRESF_LVL_V2_LVL2;
		break;
	case KU8_CIL_HWA20_CYCLE :
		CIL_u16HWARepetitionTime = ((uint16)(NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u16DurationHaptic2)/KU16_TEN);
		CIL_bHWA0PhaseStarted = B_TRUE;
		u8HWAExecuted = I_C06_RBTM_LVL_RQ_PROFILE16;
		break;
	case KU8_CIL_HWA30_CYCLE :
		CIL_u16HWARepetitionTime = ((uint16)(NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u16DurationHaptic3)/KU16_TEN);
		CIL_bHWA0PhaseStarted = B_TRUE;
		u8HWAExecuted = I_C06_RBTM_LVL_RQ_PROFILE17;
		break;
	case KU8_CIL_HWA40_CYCLE :
		CIL_u16HWARepetitionTime = ((uint16)(NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u16DurationHaptic4)/KU16_TEN);
		CIL_bHWA0PhaseStarted = B_TRUE;
		u8HWAExecuted = I_C06_RBTM_LVL_RQ_PROFILE18;
		break;
	case KU8_CIL_HWA11_CYCLE:
	case KU8_CIL_HWA21_CYCLE:
	case KU8_CIL_HWA31_CYCLE:
	case KU8_CIL_HWA41_CYCLE:
		if (B_TRUE == CIL_bHWA0PhaseStarted)
		{
			CIL_bHWA1PhaseStarted = B_TRUE;
			CIL_bHWA0PhaseStarted = B_FALSE;
		}
		break;
	default :
		/* [COVERS: DSG_CIL_0267] */
		if (KU8_TRUE == cil_u8TensioningAbortedStatus)
		{
			CIL_bHWA0PhaseStarted = B_FALSE;
			cil_u16HWACounter = KU16_ZERO;
		}
		break;
	}

	switch (u8CycleRequest)
	{
	case I_C04_PRESF_LVL_V2_LVL2:
	case I_C06_RBTM_LVL_RQ_PROFILE16:
	case I_C06_RBTM_LVL_RQ_PROFILE17:
	case I_C06_RBTM_LVL_RQ_PROFILE18:
		/* Nothing to do */
		if( (u8HWAExecuted != u8CycleRequest) && (CIL_u16HWARepetitionTime <= cil_u16HWACounter) )
		{
			CIL_bHWA1PhaseStarted = B_FALSE;
			cil_u16HWACounter = KU16_ZERO;
			(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
		}
		break;
	default :
		/* Any other requests */
		/* [COVERS: DSG_CIL_0287] */
		if( (cil_u8ExecHAPTIC_TYPE == KU8_CIL_FIXED_HWA) && (CIL_u16HWARepetitionTime <= cil_u16HWACounter)) /* Because ending HWA after X Seconds */ /* Execution is over */
		{
			CIL_bHWA1PhaseStarted = B_FALSE;
			cil_u16HWACounter = KU16_ZERO;
			(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
		}
		/* [COVERS: DSG_CIL_0288] */
		else if ( (cil_u8ExecHAPTIC_TYPE == KU8_CIL_NON_FIXED_HWA) && (KU8_NO_CYCLE == u8CycleRequest))
		{
			/* Stop HWA regardless of the elapsed time */
			CIL_bHWA1PhaseStarted = B_FALSE;
			cil_u16HWACounter = KU16_ZERO;
			(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
		}
		/* [COVERS: DSG_CIL_0288] */
		else if ( (cil_u8ExecHAPTIC_TYPE == KU8_CIL_NON_FIXED_HWA) && (CIL_u16HWARepetitionTime <= cil_u16HWACounter))
		{
			CIL_bHWA1PhaseStarted = B_FALSE;
			cil_u16HWACounter = KU16_ZERO;
			(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
		}
		else if (KU8_NO_CYCLE != u8CycleRequest) 
		{
			/* Issue 816541; 813743 */
			CIL_bHWA1PhaseStarted = B_FALSE;
			cil_u16HWACounter = KU16_ZERO;
			(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
		}
		else
		{
			/*Nothing to do */
		}
		break;
	}

	if (B_TRUE == CIL_bHWA1PhaseStarted)
	{
		/* [COVERS: DSG_CIL_0011, DSG_CIL_0077] */
		if( (CIL_u16HWARepetitionTime >= cil_u16HWACounter) && (KU8_FALSE == cil_u8TensioningAbortedStatus) )
		{
			if (B_TRUE == CIL_bHWA1PhaseStarted)
			{
				cil_u16HWACounter++;
			}
		}
		else
		{
			/* [COVERS: DSG_CIL_0037] */
			(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
		}
	}
}
/**
 * \brief
 *     Function used to manage the aborting conditions
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
/* [COVERS: DSG_CIL_0065;DSG_CIL_0070; DSG_CIL_0071; DSG_CIL_0160; DSG_CIL_0382; DSG_CIL_0183; DSG_CIL_0784; DSG_CIL_0785; DSG_CIL_0786 */
LOCAL void cil_AbortProfiles(void)
{

	if (KU8_TRUE == cil_u8TensioningAbortedStatus)
	{
		(void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_TRUE);
		(void)Rte_Write_psrCustomerSpecific_b8PreCrashRequestEnable(KU8_FALSE);
		(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
	}
	else
	{
		/* nothing to do */
	}

	/* [COVERS: DSG_CIL_0267] */
	if( (KU8_TRUE == cil_u8TensioningAbortedStatus)&&
			(
					( (KU16_ZERO == (CIL_u16AbortionStatus & KU16_CIL_API_ABORT_MASK)) && (I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER == CIL_stManagedCycle.u8RequestSource) ) ||
					( (KU16_ZERO == (CIL_u16AbortionStatus & KU16_CIL_PRESAFE_ABORT_MASK)) && (I_C04_RBTM_ACTVCLIENT_PRESAFE == CIL_stManagedCycle.u8RequestSource) )
			) )
	{
		cil_u8TensioningAbortedStatus = KU8_FALSE;
	}


}
/**
 * \brief
 *     Function used to manage the aborting conditions
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
/* [COVERS: DSG_CIL_0180; DSG_CIL_0179] */
LOCAL void cil_RequestTensioning(const uint8 u8Level)
{
	uint8 u8ExecutedCycle = KU8_NO_CYCLE;
	uint8 u8ExecutedStep = KU8_NO_STEP;
	uint8 u8Aux = KU8_MAX;
	uint8 u8lastconfiguredStep = KU8_NO_STEP;

	if (KU8_MAX != u8Level)
	{
		/* [COVERS: DSG_CIL_0244] */
		if( (KU8_PRECRASH_SEVERITY_LEVEL_4 == u8Level) &&
				( (I_C04_PRESF_LVL_V2_LVL8 == CIL_stManagedCycle.u8CurrentRequestedCycle) ||
						( (KU8_NO_CYCLE == CIL_stManagedCycle.u8CurrentRequestedCycle) && (I_C04_PRESF_LVL_V2_LVL8 == CIL_stManagedCycle.u8OldRequestedCycle) ) ) )
		{
			if( (KU16_CIL_TIMEOUT_PRESAFE_5 >= cil_u16Presafe5Timeout) && (cil_u8Presafe5specialRequestSource == CIL_stManagedCycle.u8RequestSource) )
			{
				cil_u16Presafe5Timeout++;
			}
			if (cil_u8Presafe5specialRequestSource != CIL_stManagedCycle.u8RequestSource)
			{
				cil_u16Presafe5Timeout = KU16_ZERO;
			}
			cil_u8Presafe5specialRequestSource = CIL_stManagedCycle.u8RequestSource;
		}
		else
		{
			cil_u16Presafe5Timeout = KU16_ZERO;
		}

		(void)Rte_Read_prrStepNumber_u8StepNumber(&u8ExecutedStep);
		(void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);

		if (KU8_TRUE == cil_u8TensioningStarted) 
		{
			if( (KU8_PRECRASH_SEVERITY_LEVEL_BSR_1 == u8ExecutedCycle) ||
					(KU8_PRECRASH_SEVERITY_LEVEL_BSR_2 == u8ExecutedCycle) ||
					(KU8_PRECRASH_SEVERITY_LEVEL_BSR_3 == u8ExecutedCycle) )
			{
				(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(KU8_NO_PRECRASH_SEVERITY_LEVEL);
			}

			if ( (u8Level != u8ExecutedCycle) && (KU8_NO_CYCLE != u8ExecutedCycle))
			{
				(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(u8Level);
			}
			else
			{
				if( (KU8_PRECRASH_SEVERITY_LEVEL_7 == u8Level) ||
						( (KU8_PRECRASH_SEVERITY_LEVEL_4 == u8Level) &&
								( (I_C04_PRESF_LVL_V2_LVL8 == CIL_stManagedCycle.u8CurrentRequestedCycle) ||
										( (KU8_NO_CYCLE == CIL_stManagedCycle.u8CurrentRequestedCycle) && (I_C04_PRESF_LVL_V2_LVL8 == CIL_stManagedCycle.u8OldRequestedCycle) ) ) ))
				{
					for(u8Aux = KU8_NVP_CYCLE_SIZE - KU8_ONE; u8Aux >= KU8_NVP_START_CYCLES, (KU8_NO_STEP==u8lastconfiguredStep) ; u8Aux--)
					{
						if (NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[(u8Level*KU8_NVP_CYCLE_SIZE) + u8Aux] != KU8_NO_STEP)
						{
							u8lastconfiguredStep = u8Aux;
						}
					}

					if (NVP_BLOCK_ID_CYCLE_0_RamBlockData.NVP_au8BeltProfilesDefinitions[((u8Level*KU8_NVP_CYCLE_SIZE) + u8lastconfiguredStep)] == u8ExecutedStep)
					{
						(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(KU8_NO_PRECRASH_SEVERITY_LEVEL);
					}
				}
			}


			/*Stop presafe 5 after timeout */
			if( (KU16_CIL_TIMEOUT_PRESAFE_5 <= cil_u16Presafe5Timeout) && (cil_u16Presafe5Timeout!= KU16_ZERO) )
			{
				(void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_TRUE);
				(void)Rte_Write_psrCustomerSpecific_b8PreCrashRequestEnable(KU8_FALSE);
			}
		}
		else
		{
			if( (KU8_PRECRASH_SEVERITY_LEVEL_4 == u8Level) &&
					( (I_C04_PRESF_LVL_V2_LVL8 == CIL_stManagedCycle.u8CurrentRequestedCycle) ||
							( (KU8_NO_CYCLE == CIL_stManagedCycle.u8CurrentRequestedCycle) && (I_C04_PRESF_LVL_V2_LVL8 == CIL_stManagedCycle.u8OldRequestedCycle) ) ) &&
							(KU16_CIL_TIMEOUT_PRESAFE_5 <= cil_u16Presafe5Timeout) &&
							(cil_u8Presafe5specialRequestSource == CIL_stManagedCycle.u8RequestSource) )
			{
				/* nothing to do if there is no requested other than PRESAFE 8 */
				/*Stop presafe 5 after timeout */

				if( (KU16_CIL_TIMEOUT_PRESAFE_5 <= cil_u16Presafe5Timeout) && (cil_u16Presafe5Timeout!= KU16_ZERO) )
				{
					(void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_TRUE);
					(void)Rte_Write_psrCustomerSpecific_b8PreCrashRequestEnable(KU8_FALSE);
				}
			}
			else
			{
				(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(u8Level);
			}
		}
	}
}
/**
 * \brief
 *     Function used to decide which profile to be triggered
 * \param
 *     [IN] uint8 u8CycleRequest: which cycle is requested
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void cil_TriggerProfiles(const uint8 u8CycleRequest)
{
	uint8 u8CycleValidityStatus = KU8_FALSE;
	uint8 u8ExecutedCycle = KU8_NO_CYCLE;
	uint32 u32AECGroupStatus = KU32_ZERO;

	(void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);

	/* [COVERS: DSG_CIL_0033] */
	(void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_FALSE);
	/* [COVERS: DSG_CIL_0034] */
	(void)Rte_Write_psrCustomerSpecific_b8PreCrashRequestEnable(KU8_TRUE);

	(void)Rte_IrvWrite_CIL_runCANToAppli_u8FctPrecond_ProfileNotImplemented(KU8_FALSE);
	/* Get AEC group status */
	Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

	switch (u8CycleRequest)
	{
	case KU8_NO_CYCLE:
	{
		if (KU16_ZERO == (CIL_u16InhibitionStatus & KU8_CIL_AccLowInhibition))
		{
			if (KU8_TRUE == cil_u8TensioningAbortedStatus)   /* Because 1 s HWA */
			{
				(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_NO_HAPTIC_REQUEST);
			}
			else
			{
				/* Nothing to do */
			}
			cil_u8TensioningAbortedStatus = KU8_FALSE;

			/* Handle here? Add pre-safe enable for ending the tensioning */
			if( (I_C04_RBTM_ACTVCLIENT_PRESAFE == CIL_stManagedCycle.u8RequestSource ) &&
					(I_C02_FALSE_TRUE_SNA_SNA == cil_stPresfActAdjFrame.Presf_Enbl_ST3) &&
					( (I_C04_PRESF_LVL_V2_LVL1 == CIL_stManagedCycle.u8OldRequestedCycle) ||
							(I_C04_PRESF_LVL_V2_LVL3 == CIL_stManagedCycle.u8OldRequestedCycle) ||
							(I_C04_PRESF_LVL_V2_LVL4 == CIL_stManagedCycle.u8OldRequestedCycle) ||
							(I_C04_PRESF_LVL_V2_LVL5 == CIL_stManagedCycle.u8OldRequestedCycle) ||
							(I_C04_PRESF_LVL_V2_LVL6 == CIL_stManagedCycle.u8OldRequestedCycle) ||
							(I_C04_PRESF_LVL_V2_LVL7 == CIL_stManagedCycle.u8OldRequestedCycle) ) )
			{
				/* Nothing to do => Keep tensioning */
			}/* Tensioning should not end */
			else
			{
				/* [COVERS: DSG_CIL_0066, DSG_CIL_0032,DSG_CIL_0162] */                                                                                
				if( (I_C04_PRESF_LVL_V2_LVL8 != CIL_stManagedCycle.u8OldRequestedCycle) || (KU16_ZERO == (CIL_u16InhibitionStatus & KU8_CIL_InhibitionAfterORC ) ) ) /* Issue 817742 */
				{
					(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_TRUE);

					(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(KU8_NO_PRECRASH_SEVERITY_LEVEL);
				}
				else
				{
					/* Nothing to do - issue 817742 */
				}

				/* Special check*/
				CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_NONE;
				if (KU8_NO_CYCLE != CIL_stManagedCycle.u8CurrentRequestedCycle)
				{
					CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
					CIL_stManagedCycle.u8CurrentRequestedCycle = KU8_NO_CYCLE;
					/* [COVERS: DSG_CIL_0181] */
					(void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_NO_CYCLE);
				}
				else
				{
					/* Nothing to do */
				}
			}

			if ((cil_stPresfActAdjFrame.Presf_Lvl_ST3 != I_C04_PRESF_LVL_V2_NOLVL) &&
					(cil_stPresfActAdjFrame.Presf_Lvl_ST3 != I_C04_PRESF_LVL_V2_LVL2) )
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
			else
			{
				if (KU16_ZERO != (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK) )
				{
					if(cil_stPresfActAdjFrame.Presf_Lvl_ST3 == I_C04_PRESF_LVL_V2_NOLVL)
					{
						if ((KU8_TRUE == cil_u8TensioningStartedPR) && (KU8_NO_CYCLE == u8ExecutedCycle))
						{
							cil_u8TensioningStartedPR = KU8_FALSE;
							cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_END;
						}
					}
					else
					{
						cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_NONE;
					}
				}		
			}
		}
		else
		{
			if(cil_stPresfActAdjFrame.Presf_Lvl_ST3 == I_C04_PRESF_LVL_V2_NOLVL)
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_NONE;
			}

			/*Nothing*/
		}

		cil_RequestTensioning(u8ExecutedCycle);
	}
	break;
	case I_C04_PRESF_LVL_V2_LVL1:

		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035;DSG_CIL_0078] */
		(void)Rte_Read_prrEnableCycle0_b8CycleValidity(&u8CycleValidityStatus);
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL1))) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0048, DSG_CIL_0031] */

			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_1);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			if (KU8_TENSIONING_START == cil_stInputSignalsPresfRec.u8TensioningStateType)
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
		}
		break;

	case I_C04_PRESF_LVL_V2_LVL2: /* HWA1 */
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035] */
		(void)Rte_Read_prrEnableCycle18_b8CycleValidity(&u8CycleValidityStatus);
		if(KU8_TRUE == u8CycleValidityStatus)
		{
			(void)Rte_Read_prrEnableCycle19_b8CycleValidity(&u8CycleValidityStatus);
			/* [COVERS: DSG_CIL_0378] */
			if( (KU8_TRUE == u8CycleValidityStatus) &&
					( KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL2))) &&
					( ((KU8_ZERO == NVP_stVehicleEquipmentData.HWALeftActivation) && (KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION) ) ||
							((KU8_ZERO == NVP_stVehicleEquipmentData.HWARightActivation) && (KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)) ) )
			{

				(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
				(void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_FALSE);
				/* [COVERS: DSG_CIL_0049] */
				(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_HAPTIC_REQUEST_0);
				/* [COVERS: DSG_CIL_0284] */
				cil_u8ExecHAPTIC_TYPE = ((uint8)(NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u8HapticType & KU8_ONE));
				if (B_TRUE == CIL_bHWA0PhaseStarted)
				{
					(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(KU8_NO_PRECRASH_SEVERITY_LEVEL);
				}
			}
			else
			{
				(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			}
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;
	case I_C04_PRESF_LVL_V2_LVL3:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035] */
		(void)Rte_Read_prrEnableCycle1_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				( KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL3))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0050, DSG_CIL_0031] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_2);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			if (KU8_TENSIONING_START == cil_stInputSignalsPresfRec.u8TensioningStateType)
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
		}
		break;

	case I_C04_PRESF_LVL_V2_LVL4:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035] */
		(void)Rte_Read_prrEnableCycle2_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				( KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL4))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0051, DSG_CIL_0031] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_3);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			if (KU8_TENSIONING_START == cil_stInputSignalsPresfRec.u8TensioningStateType)
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
		}
		break;

	case I_C04_PRESF_LVL_V2_LVL5:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle3_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL5))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0052] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_4);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C04_PRESF_LVL_V2_LVL6:
		/* Read cycle validity*/
		(void)Rte_Read_prrEnableCycle4_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378; DSG_CIL_0780] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL6))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX)) && (KU8_PRECRASH_SEVERITY_LEVEL_5 == u8ExecutedCycle)) ) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0157] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_5);
		}
		else
		{
			if (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX))
			{
				(void)Rte_Read_prrEnableCycle3_b8CycleValidity(&u8CycleValidityStatus);
				/* [COVERS: DSG_CIL_0378] */
				if( (KU8_TRUE == u8CycleValidityStatus) &&
						(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL5))) )
				{
					(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
					/* [COVERS: DSG_CIL_0052; DSG_CIL_0199] */
					cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_4);
				}
				else
				{
					(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
				}
			}
			else
			{
				(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			}
		}
		break;

	case I_C04_PRESF_LVL_V2_LVL7:
		/* Read cycle validity*/
		(void)Rte_Read_prrEnableCycle5_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378; DSG_CIL_0780] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL7))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX)) && (KU8_PRECRASH_SEVERITY_LEVEL_6 == u8ExecutedCycle)) ) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0158] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_6);
		}
		else
		{
			if (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX))
			{
				(void)Rte_Read_prrEnableCycle3_b8CycleValidity(&u8CycleValidityStatus);
				/* [COVERS: DSG_CIL_0378] */
				if( (KU8_TRUE == u8CycleValidityStatus) &&
						(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL5))) )
				{
					(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
					/* [COVERS: DSG_CIL_0052; DSG_CIL_0242] */
					cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_4);
				}
				else
				{
					(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
				}
			}
			else
			{
				(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			}
		}
		break;

	case I_C04_PRESF_LVL_V2_LVL8:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle6_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378; DSG_CIL_0780] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL8))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX)) && (KU8_PRECRASH_SEVERITY_LEVEL_7 == u8ExecutedCycle)) ) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0159] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_7);
		}
		else
		{
			if (KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_MAX))
			{
				(void)Rte_Read_prrEnableCycle3_b8CycleValidity(&u8CycleValidityStatus);
				/* [COVERS: DSG_CIL_0378] */
				if( (KU8_TRUE == u8CycleValidityStatus) &&
						(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C04_PRESF_LVL_V2_LVL5))) )
				{
					(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
					/* [COVERS: DSG_CIL_0052; DSG_CIL_0243] */
					cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_4);
				}
				else
				{
					(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
				}
			}
			else
			{
				(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			}
		}

		if(I_C04_RBTM_ACTVCLIENT_POSTCRASH == CIL_stManagedCycle.u8RequestSource)
		{
			if ((cil_stPresfActAdjFrame.Presf_Lvl_ST3 != I_C04_PRESF_LVL_V2_NOLVL) &&
					(cil_stPresfActAdjFrame.Presf_Lvl_ST3 != I_C04_PRESF_LVL_V2_LVL2) )
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE9:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle7_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE9))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0164] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_8);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE10:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle8_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE10))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0165] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_9);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE11:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle9_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE11))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0166] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_10);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE12:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle10_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE12))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0167] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_11);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE13:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle11_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE13))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0168] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_12);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE14:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle12_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE14))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0169] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_13);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE15:
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031] */
		(void)Rte_Read_prrEnableCycle13_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE15))) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0170] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_14);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE16: /* HWA2 */
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035; DSG_CIL_0245] */
		(void)Rte_Read_prrEnableCycle20_b8CycleValidity(&u8CycleValidityStatus);
		if(KU8_TRUE == u8CycleValidityStatus)
		{
			(void)Rte_Read_prrEnableCycle21_b8CycleValidity(&u8CycleValidityStatus);
			/* [COVERS: DSG_CIL_0378] */
			if( (KU8_TRUE == u8CycleValidityStatus) &&
					( KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE16))) &&
					( ((KU8_ZERO == NVP_stVehicleEquipmentData.HWALeftActivation) && (KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION) ) ||
							((KU8_ZERO == NVP_stVehicleEquipmentData.HWARightActivation) && (KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)) ) )
			{

				(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
				(void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_FALSE);
				/* [COVERS: DSG_CIL_0049] */
				(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_HAPTIC_REQUEST_2);
				/* [COVERS: DSG_CIL_0284] */
				cil_u8ExecHAPTIC_TYPE = (uint8)(KU8_TWO == ((uint8)(NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u8HapticType & KU8_TWO)));
				if (B_TRUE == CIL_bHWA0PhaseStarted)
				{
					(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(KU8_NO_PRECRASH_SEVERITY_LEVEL);
				}
			}
			else
			{
				(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			}
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE17: /* HWA3 */
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035; DSG_CIL_0246] */
		(void)Rte_Read_prrEnableCycle22_b8CycleValidity(&u8CycleValidityStatus);
		if(KU8_TRUE == u8CycleValidityStatus)
		{
			(void)Rte_Read_prrEnableCycle23_b8CycleValidity(&u8CycleValidityStatus);
			/* [COVERS: DSG_CIL_0378] */
			if( (KU8_TRUE == u8CycleValidityStatus) &&
					( KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE17))) &&
					( ((KU8_ZERO == NVP_stVehicleEquipmentData.HWALeftActivation) && (KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION) ) ||
							((KU8_ZERO == NVP_stVehicleEquipmentData.HWARightActivation) && (KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)) ) )
			{

				(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
				(void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_FALSE);
				/* [COVERS: DSG_CIL_0049] */
				(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_HAPTIC_REQUEST_4);
				/* [COVERS: DSG_CIL_0284] */
				cil_u8ExecHAPTIC_TYPE = (uint8)(KU8_FOUR == ((uint8)(NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u8HapticType & KU8_FOUR)));
				if (B_TRUE == CIL_bHWA0PhaseStarted)
				{
					(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(KU8_NO_PRECRASH_SEVERITY_LEVEL);
				}
			}
			else
			{
				(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			}
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE18: /* HWA3 */
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035; DSG_CIL_0247] */
		(void)Rte_Read_prrEnableCycle24_b8CycleValidity(&u8CycleValidityStatus);
		if(KU8_TRUE == u8CycleValidityStatus)
		{
			(void)Rte_Read_prrEnableCycle25_b8CycleValidity(&u8CycleValidityStatus);
			/* [COVERS: DSG_CIL_0378] */
			if( (KU8_TRUE == u8CycleValidityStatus) &&
					( KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE18))) &&
					( ((KU8_ZERO == NVP_stVehicleEquipmentData.HWALeftActivation) && (KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION) ) ||
							((KU8_ZERO == NVP_stVehicleEquipmentData.HWARightActivation) && (KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION)) ) )
			{

				(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
				(void)Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected(KU8_FALSE);
				/* [COVERS: DSG_CIL_0049] */
				(void)Rte_Write_psrCustomerSpecific_u8HapticRequest(KU8_HAPTIC_REQUEST_6);
				/* [COVERS: DSG_CIL_0284] */
				cil_u8ExecHAPTIC_TYPE = (uint8)(KU8_EIGHT == ((uint8)(NVP_BLOCK_ID_HAPTIC_CONFIG_MB_RamBlockData.NVP_u8HapticType & KU8_EIGHT)));
				if (B_TRUE == CIL_bHWA0PhaseStarted)
				{
					(void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(KU8_NO_PRECRASH_SEVERITY_LEVEL);
				}
			}
			else
			{
				(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			}
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;
	case I_C06_RBTM_LVL_RQ_PROFILE19: /* BSR 1 */
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031; DSG_CIL_0248] */
		(void)Rte_Read_prrEnableCycle26_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE19))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) && (KU8_PRECRASH_SEVERITY_LEVEL_BSR_1 == u8ExecutedCycle)) ) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0170] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_BSR_1);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE20: /* BSR 2 */
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031; DSG_CIL_0249] */
		(void)Rte_Read_prrEnableCycle27_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE20))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) && (KU8_PRECRASH_SEVERITY_LEVEL_BSR_2 == u8ExecutedCycle)) ) )
		{

			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0170] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_BSR_2);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE21: /* BSR 3*/
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035, DSG_CIL_0031; DSG_CIL_0250] */
		(void)Rte_Read_prrEnableCycle28_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE21)))  &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) && (KU8_PRECRASH_SEVERITY_LEVEL_BSR_3 == u8ExecutedCycle)) ) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0170] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_BSR_3);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE22: /* PRE-SAFE CURVE 1*/
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035] */
		(void)Rte_Read_prrEnableCycle14_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				( KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE22))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) && (KU8_PRECRASH_SEVERITY_LEVEL_15 == u8ExecutedCycle)) ) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0021, DSG_CIL_0031] */
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_15);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			if (KU8_TENSIONING_START == cil_stInputSignalsPresfRec.u8TensioningStateType)
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE23: /* PRE-SAFE CURVE 2*/
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035] */
		(void)Rte_Read_prrEnableCycle15_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		u8CycleValidityStatus = KU8_TRUE;
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE23))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) && (KU8_PRECRASH_SEVERITY_LEVEL_16 == u8ExecutedCycle)) ) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0171]*/
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_16);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			if (KU8_TENSIONING_START == cil_stInputSignalsPresfRec.u8TensioningStateType)
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE24: /* PRE-SAFE CURVE 3*/
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035] */
		(void)Rte_Read_prrEnableCycle16_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE24))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) && (KU8_PRECRASH_SEVERITY_LEVEL_17 == u8ExecutedCycle)) ) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0172]*/
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_17);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			if(KU8_TENSIONING_START == cil_stInputSignalsPresfRec.u8TensioningStateType)
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
		}
		break;

	case I_C06_RBTM_LVL_RQ_PROFILE25: /* PRE-SAFE CURVE 4*/
		/* Read cycle validity*/
		/* [COVERS: DSG_CIL_0035] */
		(void)Rte_Read_prrEnableCycle17_b8CycleValidity(&u8CycleValidityStatus);
		/* [COVERS: DSG_CIL_0378] */
		if( (KU8_TRUE == u8CycleValidityStatus) &&
				(KU32_ZERO == (NVP_stVehicleEquipmentData.PreSafeCycleActivation & CIL_VAL_PROFILE_ENABLE(I_C06_RBTM_LVL_RQ_PROFILE25))) &&
				( (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) ||
						((KU32_ZERO != (u32AECGroupStatus & KU32_AEC_GROUP_MASK_EOL_COMFORT)) && (KU8_PRECRASH_SEVERITY_LEVEL_18 == u8ExecutedCycle)) ) )
		{
			(void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
			/* [COVERS: DSG_CIL_0173]*/
			cil_RequestTensioning(KU8_PRECRASH_SEVERITY_LEVEL_18);
		}
		else
		{
			(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
			if (KU8_TENSIONING_START == cil_stInputSignalsPresfRec.u8TensioningStateType)
			{
				cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
			}
		}
		break;
	default :
		/* [COVERS: DSG_CIL_0053] */
		(void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
		(void)Rte_IrvWrite_CIL_runCANToAppli_u8FctPrecond_ProfileNotImplemented(KU8_TRUE);
		if ((cil_stPresfActAdjFrame.Presf_Lvl_ST3 != I_C04_PRESF_LVL_V2_NOLVL) &&
				(cil_stPresfActAdjFrame.Presf_Lvl_ST3 != I_C04_PRESF_LVL_V2_LVL2) )
		{
			cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
		}
		else
		{
			cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_NONE;
		}
		break;
	}

	cil_ManageHapticRepetition(u8CycleRequest);
}
#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/**
 * \brief
 *     CIL periodic main function used to update transmitted frames signals values
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_runCANToAppli(void)
{
   uint8 u8ExecutedCycle = KU8_NO_CYCLE;
   uint32 u32AECGroupStatus = KU32_ZERO;

   (void)Rte_Read_prrCycleNumber_u8CycleNumber(&u8ExecutedCycle);
   (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_NONE);
   (void)Rte_IrvWrite_CIL_runCANToAppli_u8RequestSource(CIL_stManagedCycle.u8RequestSource);

   cil_ManageInputSignals();

   /* Send Ignition status to ERH for debounce Ignition Power cycle */
   /* [COVERS: DSG_CIL_0304] */
   if (KU8_TRUE == cil_u8NewIgnPowerCycle)
   {
	   Rte_Write_psrIgnitionStatus_b8TriggerIgnitionStatus(KU8_TRUE);
   }
   else
   {
	   Rte_Write_psrIgnitionStatus_b8TriggerIgnitionStatus(KU8_FALSE);

   }

   /* Send Ignition status to ERH  and MMG for Storage/enable conditions*/
   /* [COVERS: DSG_CIL_0314] */
   if(I_C03_ISW_STAT_IGN_ON == cil_stIgnStatFrame.ISw_Stat_ST3)
   {
	   Rte_Write_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition(KU8_TRUE);
   }
   else
   {
	   Rte_Write_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition(KU8_FALSE);
   }



   /* Send Production Mode status to ERH for storage condition SC5 - Transportation Mode */
   /* [COVERS: DSG_CIL_0315] */
   if((I_C02_TRANSMD_STAT_OFF == cil_u8TransMdSwStatSignal) || (I_C02_TRANSMD_STAT_TEMP_OFF == cil_u8TransMdSwStatSignal))
   {
	   Rte_Write_psrTransportationModeStatus_b8TransportationModeStatus(KU8_TRUE);
   }
   else if(I_C02_TRANSMD_STAT_ACTV == cil_u8TransMdSwStatSignal)
   {
	   Rte_Write_psrTransportationModeStatus_b8TransportationModeStatus(KU8_FALSE);
   }
   else
   {
      /* do nothing */
   }



   /* Send Production Mode status to ERH for storage condition SC5 - Transportation Mode */
   /* [COVERS: DSG_CIL_0316] */
   if((I_C03_ENGSTARTPN14_STAT_NO_COMBUSTIONSTART_RQ == cil_stPTCoor4Pr5St3.PT4_PTCoor_EngStartPN14_Stat_ST3) || (I_C03_ENGSTARTPN14_STAT_AUTO_START_PN_SUP_RQ == cil_stPTCoor4Pr5St3.PT4_PTCoor_EngStartPN14_Stat_ST3))
   {
	   Rte_Write_psrEngStartStatus_b8EngStartStatus(KU8_TRUE);
   }
   else if((I_C03_ENGSTARTPN14_STAT_CUSTOMER_START_RQ == cil_stPTCoor4Pr5St3.PT4_PTCoor_EngStartPN14_Stat_ST3) || (I_C03_ENGSTARTPN14_STAT_AUTO_START_NO_PN_SUP_RQ == cil_stPTCoor4Pr5St3.PT4_PTCoor_EngStartPN14_Stat_ST3))
   {
	   Rte_Write_psrEngStartStatus_b8EngStartStatus(KU8_FALSE);
   }
   else
   {
      /* do nothing */
   }

   /* Send Production Mode status to ERH for storage condition SC12 - Production Mode */
   /* [COVERS: DSG_CIL_0317] */
   if(I_C03_PN14_PRODMD_STAT_ST3_OFF == cil_u8ProdMdSwStatSignal)
   {
	   Rte_Write_psrProdModeStatus_b8TriggerProdModeStatus(KU8_TRUE);
   }
   else if((I_C03_PN14_PRODMD_STAT_ST3_ON == cil_u8ProdMdSwStatSignal) || (I_C03_PN14_PRODMD_STAT_ST3_SF01 == cil_u8ProdMdSwStatSignal) ||
		   (I_C03_PN14_PRODMD_STAT_ST3_SF02 == cil_u8ProdMdSwStatSignal) || (I_C03_PN14_PRODMD_STAT_ST3_SF03 == cil_u8ProdMdSwStatSignal))
   {
	   Rte_Write_psrProdModeStatus_b8TriggerProdModeStatus(KU8_FALSE);
   }
   else
   {
      /* do nothing */
   }



   /* issue 816503 */


   if( (KU8_NO_CYCLE == CIL_stManagedCycle.u8CurrentRequestedCycle) &&
         (KU16_ZERO != (CIL_u16InhibitionStatus & KU8_CIL_InhibitionOfImpactX )))
   {
      cil_u8TensioningStarted = KU8_FALSE;
      /* [COVERS: DSG_CIL_0181] */
      (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_NO_CYCLE);
      CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_NONE;
      (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_NONE);
   }

   if( (KU8_NO_CYCLE == CIL_stManagedCycle.u8CurrentRequestedCycle) &&
         (KU16_ZERO != (CIL_u16InhibitionStatus & KU8_CIL_InhibitionAfterORC )) )
   {
      /* to do issue - replayed ORC level 8 */
      if (KU8_NO_CYCLE == u8ExecutedCycle)
      {

         cil_u8TensioningStarted = KU8_FALSE;
         cil_u8TensioningAbortedStatus = KU8_FALSE;
      }
      /* [COVERS: DSG_CIL_0181] */
      (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_NO_CYCLE);
      CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_NONE;
      (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_NONE);
   }

   switch(CIL_stManagedCycle.u8RequestSource)
   {
   case I_C04_RBTM_ACTVCLIENT_NONE: /* Nothing was requested before */
      if( (KU8_NO_CYCLE != cil_u8ORC1ActivationRequest) || (KU8_NO_CYCLE != cil_u8ORC2ActivationRequest))
      {
         CIL_stManagedCycle.bInhibitionStatus = (boolean)( (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK) != KU16_ZERO);
         if ( KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_ORC_INHIB_MASK) )
         {
            CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_POSTCRASH;
            CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
            CIL_stManagedCycle.u8CurrentRequestedCycle = I_C04_PRESF_LVL_V2_LVL8;
            cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_START;
         }
         else
         {
        	 /* [COVERS: DSG_CIL_0181] */
        	 (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_ONE);
        	 if ( KU16_ZERO != (CIL_u16InhibitionStatus & KU16_CIL_ORC_INHIB_MASK) )
        	 {
        		 cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
        	 }
         }
      }
      else
      {
         if(KU8_NO_CYCLE != cil_u8PreSafeActivationRequest )
         {
            CIL_stManagedCycle.bInhibitionStatus = (boolean)( (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK) != KU16_ZERO);
            if ( KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK))
            {
               CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_PRESAFE;
               CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
               CIL_stManagedCycle.u8CurrentRequestedCycle = cil_u8PreSafeActivationRequest;
               if(CIL_stManagedCycle.u8CurrentRequestedCycle != I_C04_PRESF_LVL_V2_LVL2)
               {
                  cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_START;
               }
               else
               {
                  cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_NONE;
               }
            }
            else
            {
               Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
               cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
               (void)Rte_IrvWrite_CIL_runCANToAppli_u8RequestSource(I_C04_RBTM_ACTVCLIENT_PRESAFE);
            }
            /* [COVERS: DSG_CIL_0181] */
            (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_TWO);
         }
         else
         {
            /* [COVERS: DSG_CIL_0378] */
            if ( (KU8_NO_CYCLE != cil_u8APIActivationRequest) && (B_FALSE == CIL_bPresfAbortApi) )
            {
               CIL_stManagedCycle.bInhibitionStatus = ( (CIL_u16InhibitionStatus & KU16_CIL_API_INHIB_MASK) != KU16_ZERO);
               if ((KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_API_INHIB_MASK)) && (KU8_ZERO == NVP_stVehicleEquipmentData.APIActivation))
               {
                  CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER;
                  CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
                  CIL_stManagedCycle.u8CurrentRequestedCycle = cil_u8APIActivationRequest;
               }
               else
               {
                  (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
                  (void)Rte_IrvWrite_CIL_runCANToAppli_u8RequestSource(I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER);
               }
               /* [COVERS: DSG_CIL_0181] */
               (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_ONE);
            }
            else
            {
               /* WHY ? */
               if ( (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_ORC_INHIB_MASK)) && (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_REL_INHIB_MASK)))
               {
                  (void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_TRUE);
               }
               (void)Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel(KU8_NO_PRECRASH_SEVERITY_LEVEL);
               CIL_stManagedCycle.bInhibitionStatus = KU8_ZERO;
               if (KU8_NO_CYCLE == cil_u8APIActivationRequest )
               {
                  CIL_bPresfAbortApi = B_FALSE;
               }
               else
               {
                  /* Nothing to do */
               }
               /* [COVERS: DSG_CIL_0181] */
               (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_NO_CYCLE);
            }
         }
      }
      break;
   case I_C04_RBTM_ACTVCLIENT_POSTCRASH:
      if ( (KU16_ZERO != (CIL_u16AbortionStatus & KU16_CIL_ORC_ABORT_MASK)) && (KU8_FALSE == cil_u8TensioningAbortedStatus) )
      {
         cil_u8TensioningAbortedStatus = KU8_TRUE;
         (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_NONE);
         cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_ABORT;
      }
         if((KU8_NO_CYCLE == u8ExecutedCycle) && (KU8_FALSE == cil_u8TensioningAbortedStatus))
      {
         cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_END;
      }
      break;
   case I_C04_RBTM_ACTVCLIENT_PRESAFE: /* Something on presafe was requested || ORC has the highest prio */
      if( ((KU8_NO_CYCLE == cil_u8ORC1ActivationRequest) && (KU8_NO_CYCLE == cil_u8ORC2ActivationRequest)) ||
            ( ( KU16_ZERO != (CIL_u16InhibitionStatus & KU16_CIL_ORC_INHIB_MASK)) && ( (KU8_NO_CYCLE != cil_u8ORC1ActivationRequest) || (KU8_NO_CYCLE != cil_u8ORC2ActivationRequest))))
      {
         if (cil_u8PreSafeActivationRequest != CIL_stManagedCycle.u8CurrentRequestedCycle)
         {
            if( ( KU8_NO_CYCLE == cil_u8PreSafeActivationRequest) || (CIL_u8SourcePrio[cil_u8PreSafeActivationRequest] >= CIL_u8SourcePrio[CIL_stManagedCycle.u8CurrentRequestedCycle]) )
            {
               CIL_stManagedCycle.bInhibitionStatus = (boolean)( (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK) != KU16_ZERO);
               if ( (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK)) ||
                     ( KU8_NO_CYCLE == cil_u8PreSafeActivationRequest ))
               {
                  CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
                  CIL_stManagedCycle.u8CurrentRequestedCycle = cil_u8PreSafeActivationRequest;
                  if (KU8_NO_CYCLE != cil_u8PreSafeActivationRequest) /* new request after another request that is ended ( max time) */
                  {
                     cil_u8TensioningStarted = KU8_FALSE;
                  }
               }
               else
               {
                  (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
                  cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
               }
            }
         }
         else
         {
            if ( (KU16_ZERO != (CIL_u16AbortionStatus & KU16_CIL_PRESAFE_ABORT_MASK)) && (KU8_FALSE == cil_u8TensioningAbortedStatus) )
            {
               cil_u8TensioningAbortedStatus = KU8_TRUE;
               cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_ABORT;
            }
         }
      }
      else
      {
         CIL_stManagedCycle.bInhibitionStatus = (boolean)( (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK) != KU16_ZERO);
         CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_POSTCRASH;
         CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
         CIL_stManagedCycle.u8CurrentRequestedCycle = I_C04_PRESF_LVL_V2_LVL8;
         /* [COVERS: DSG_CIL_0181] */
         (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_ONE);
         cil_u8TensioningStarted = KU8_FALSE;
      }
      break;
   case I_C04_RBTM_ACTVCLIENT_SERVICE_PROVIDER:
      if( ((KU8_NO_CYCLE == cil_u8ORC1ActivationRequest) && (KU8_NO_CYCLE == cil_u8ORC2ActivationRequest)) ||
            ( ( KU16_ZERO != (CIL_u16InhibitionStatus & KU16_CIL_ORC_INHIB_MASK)) && ( (KU8_NO_CYCLE != cil_u8ORC1ActivationRequest) || (KU8_NO_CYCLE != cil_u8ORC2ActivationRequest))))
      {
         if (((KU8_NO_CYCLE == cil_u8PreSafeActivationRequest) ||
               ( (CIL_u8SourcePrio[cil_u8PreSafeActivationRequest] < CIL_u8SourcePrio[cil_u8APIActivationRequest]) && (cil_u8PreSafeActivationRequest!= KU8_NO_CYCLE) ) )  &&
               (B_FALSE == CIL_bPresfAbortApi) )
         {
            if (cil_u8APIActivationRequest != CIL_stManagedCycle.u8CurrentRequestedCycle)
            {
               CIL_stManagedCycle.bInhibitionStatus = ( (CIL_u16InhibitionStatus & KU16_CIL_API_INHIB_MASK) != KU16_ZERO);
               if( (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_API_INHIB_MASK) ) ||
                     (KU8_NO_CYCLE == cil_u8APIActivationRequest) )
               {
                  CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
                  CIL_stManagedCycle.u8CurrentRequestedCycle = cil_u8APIActivationRequest;
                  if (KU8_NO_CYCLE != cil_u8APIActivationRequest) /* new request after another request that is ended ( max time) */
                  {
                     cil_u8TensioningStarted = KU8_FALSE;
                  }
               }
               else
               {
                  (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
               }
            }
            else
            {
               if ( (KU16_ZERO != (CIL_u16AbortionStatus & KU16_CIL_API_ABORT_MASK)) && (KU8_FALSE == cil_u8TensioningAbortedStatus) )
               {
                  cil_u8TensioningAbortedStatus = KU8_TRUE;
               }
            }
         }
         else if( (CIL_u8SourcePrio[cil_u8PreSafeActivationRequest] >= CIL_u8SourcePrio[cil_u8APIActivationRequest]) )
         {
            CIL_bPresfAbortApi = B_TRUE;
            CIL_stManagedCycle.bInhibitionStatus = (boolean)( (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK) != KU16_ZERO);
            if ( (KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK)) )
            {
               CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_PRESAFE;
               CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
               CIL_stManagedCycle.u8CurrentRequestedCycle = cil_u8PreSafeActivationRequest;
               if(CIL_stManagedCycle.u8CurrentRequestedCycle != I_C04_PRESF_LVL_V2_LVL2)
               {
                  cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_START;
               }
               else
               {
                  cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_NONE;
               }
               cil_u8TensioningStarted = KU8_FALSE;
            }
            else
            {
               (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_REJECTED);
               cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_INHIBIT;
            }
            /* [COVERS: DSG_CIL_0181] */
            (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_TWO);
         }
      }
      else
      {
         CIL_stManagedCycle.bInhibitionStatus = (boolean)( (CIL_u16InhibitionStatus & KU16_CIL_PRESAFE_INHIB_MASK) != KU16_ZERO);
         CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_POSTCRASH;
         CIL_stManagedCycle.u8OldRequestedCycle = CIL_stManagedCycle.u8CurrentRequestedCycle;
         CIL_stManagedCycle.u8CurrentRequestedCycle = I_C04_PRESF_LVL_V2_LVL8;
         cil_u8TensioningStarted = KU8_FALSE;
      }
      break;
   default :
      CIL_stManagedCycle.u8RequestSource = I_C04_RBTM_ACTVCLIENT_NONE;
      CIL_stManagedCycle.u8CurrentRequestedCycle = KU8_NO_CYCLE;
      CIL_stManagedCycle.u8OldRequestedCycle = KU8_NO_CYCLE;
      CIL_stManagedCycle.bInhibitionStatus = FALSE;
      cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_NONE;
      /* [COVERS: DSG_CIL_0181] */
      (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_NO_CYCLE);
      break;
   }

   /* Compute flag for entire process profile % release */
   if(     (KU8_CIL_SMO_CYCLE != u8ExecutedCycle) &&
         (KU8_NO_CYCLE != u8ExecutedCycle ) &&
         (KU8_CIL_PAT_CYCLE != u8ExecutedCycle) &&
         (I_C04_RBTM_ACTVCLIENT_NONE != CIL_stManagedCycle.u8RequestSource) )
   {
      if (( I_C04_RBTM_ACTVCLIENT_PRESAFE == CIL_stManagedCycle.u8RequestSource))
      {
         cil_u8TensioningStartedPR = KU8_TRUE;
      }
      cil_u8TensioningStarted = KU8_TRUE;
   }
   else if(  (KU8_CIL_SMO_CYCLE == u8ExecutedCycle) &&
         (KU8_TRUE == cil_u8TensioningStarted) &&
         (KU8_FALSE == cil_u8TensioningAbortedStatus))
   {
      if (KU8_TRUE == cil_u8TensioningStartedPR)
      {
         cil_u8TensioningStartedPR = KU8_FALSE;
         if(cil_stInputSignalsPresfRec.u8TensioningStateType != KU8_TENSIONING_ABORT)
         {
            if(CIL_stManagedCycle.u8OldRequestedCycle != I_C04_PRESF_LVL_V2_LVL2)
            {
               cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_END;
            }
         }
         else
         {
            cil_stInputSignalsPresfRec.u8TensioningStateType = KU8_TENSIONING_NONE;
         }
      }
      cil_u8TensioningStarted = KU8_FALSE;
      cil_u8BSRBuckleStarted = KU8_FALSE;
      cil_u8BSRBeltSlackStarted = KU8_FALSE;
      /* [COVERS: DSG_CIL_0181] */
      (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_NO_CYCLE);
   }
   else if (  (KU8_CIL_SMO_CYCLE == u8ExecutedCycle) &&
         ( (KU8_TRUE == cil_u8BSRBuckleStarted) || (KU8_TRUE == cil_u8BSRBeltSlackStarted) ) )
   {
      cil_u8BSRBuckleStarted = KU8_FALSE;
      cil_u8BSRBeltSlackStarted = KU8_FALSE;
      (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_NO_CYCLE);
   }
   else
   {
      /* Nothing to do */
   }


   /* [COVERS: DSG_CIL_0059, DSG_CIL_0060, DSG_CIL_0036, DSG_CIL_0268] */
   /* Manage BSR request and fix issue 815844; 816835; 817690 */
   if(KU8_CIL_BSR_CYCLE == u8ExecutedCycle) /* if requested by API to ensure it is not aborted */
   {
      (void)Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch(KU8_BUCKLE_SWITCH_CLOSED);
   }
   else
   {
      /* Only open it if was not closed before = BSR is not executed*/
      (void)Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch(KU8_BUCKLE_SWITCH_OPENED);
   }

	/* Get AEC group status */
	(void)Rte_Call_pclAecStatus_GetAecGroupsStatus(&u32AECGroupStatus);

   if((KU16_ZERO == (CIL_u16InhibitionStatus & KU16_CIL_BSR_INHIB_MASK) ) && ( (KU8_TRUE == cil_u8BSRBuckleStarted) || (KU8_TRUE == cil_u8BSRBeltSlackStarted) ))/* general conditions */
   {
      if( ((KU8_TRUE == cil_u8BSRBuckleStarted) && (KU16_ZERO == (CIL_u16InhibitionStatus & (KU8_CIL_DelayBuckleSwitch|KU8_CIL_ResumingInhibitionOfBSR|KU8_CIL_PTReadyInhibition))) && (KU32_ZERO == (u32AECGroupStatus & KU32_AEC_GROUP_MASK_TIMEOUT_POWERTRAIN)) ) ||
            ((KU8_TRUE == cil_u8BSRBeltSlackStarted) && (KU16_ZERO == (CIL_u16InhibitionStatus & (KU8_CIL_DelayModeTransition|KU8_CIL_ResumingInhibitionOfBSR))) ) )
      {
         (void)Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch(KU8_BUCKLE_SWITCH_CLOSED);
         /* [COVERS: DSG_CIL_0181] */
         (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_ONE);
      }
      else
      {
         /* nothing to do */
      }

      (void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
      if (I_C04_RBTM_ACTVCLIENT_NONE == Rte_IrvRead_CIL_runAppliToCAN_u8RequestSource())
      {
         (void)Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(I_C06_RBTM_LVL_STAT_NONE);
      }
   }

   if( ( (KU8_TRUE == cil_u8BSRBuckleStarted) || (KU8_TRUE == cil_u8BSRBeltSlackStarted) )
         &&
         (KU8_CIL_BSR_CYCLE == u8ExecutedCycle)
         &&
         (KU16_ZERO != (CIL_u16AbortionStatus & KU16_CIL_BSR_ABORT_MASK) ) )
   {
      (void)Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch(KU8_BUCKLE_SWITCH_NOT_DEFINED);
      (void)Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow(KU8_FALSE);
      cil_u8BSRBuckleStarted = KU8_FALSE;
      cil_u8BSRBeltSlackStarted = KU8_FALSE;
   }

   cil_TriggerProfiles(CIL_stManagedCycle.u8CurrentRequestedCycle);
   cil_AbortProfiles();

   /* Extra check for presafe request when LVL 8 is requested and inhibitted -
    * TO DO : Use only interface Rte_Read_prrPreSafeLvl_u8PreSafeLvl */
   if(KU8_TRUE == cil_u8PRESAFERequest)
   {
      /* [COVERS: DSG_CIL_0181] */
      (void)Rte_Write_psrCustomerSpecific_u8TriggerRequest(KU8_TWO);
   }
}
/**
 * \brief
 *     Function called to read the Input signals for PreSafe Recoreder
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_runGetInputSignalPresafeRecorderInfo(REC_PreSafeRecInputType* pustPreSafeRecInput)
{
	*pustPreSafeRecInput =  cil_stInputSignalsPresfRec;
}
/**
 * \brief
 *     Function called when Timeout Error is received on Presafe frame
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_Presafe_TimeoutError(void)
{
	CIL_bTimeoutError_Presf = B_TRUE;
}

/**
 * \brief
 *     Function called when Timeout Error is recived on Buckle frame
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_Buckle_TimeoutError(void)
{
	CIL_bTimeoutError_Bckl = B_TRUE;
}

/**
 * \brief
 *     Function called when Timeout Error is received on API
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_API_TimeoutError(void)
{
	CIL_bTimeoutError_API = B_TRUE;
}

/**
 * \brief
 *     Function called when Timeout Error is received
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_BltHandoverLeft_TimeoutError(void)
{
	CIL_bTimeoutError_BHL = B_TRUE;
}

/**
 * \brief
 *     Function called when Timeout Error is received on frame
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_BltHandoverRight_TimeoutError(void)
{
	CIL_bTimeoutError_BHR = B_TRUE;
}
/**
 * \brief
 *     Function called when Timeout Error is received on Ignition frame
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_Ignition_TimeoutError(void)
{
	CIL_bTimeoutError_Ign = B_TRUE;
}

/**
 * \brief
 *     Function called when Timeout Error is received on Powertrain
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_Powertrain_TimeoutError(void)
{
	CIL_bTimeoutError_PwTrain = B_TRUE;
}
/**
 * \brief
 *     Function called when Timeout Error is received on Odospeedometer
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_Odospeedometer_TimeoutError (void)
{
	CIL_bTimeoutError_OdoS = B_TRUE;
}
/**
 * \brief
 *     Function called when Timeout Error is received on BeltADj frame
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_BeltAdj_TimeoutError(void)
 {
   CIL_bTimeoutError_BeltAdj = B_TRUE;
 }

void CIL_ExtTest_Pres_TimeoutError(void)
{
	/* [COVERS: DSG_CIL_0312] */
	Rte_Write_CIL_AC_CommunicationInteractionLayer_psrExtTestPres_b8ExtTesterPresent (B_TRUE);
}
/**
 * \brief
 *     Function called when a new Bckl_Sw_Fx_Stat_Pr5_ST3 message is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx(void)
{
	/* [COVERS: DSG_CIL_0006, DSG_CIL_0042, DSG_CIL_0043] */
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* Read Bckl_Sw_Fx_ST3 frame signals values only when we receive new data */
	cil_u8ImplausibleData_Buckle = Rte_Read_CIL_AC_CommunicationInteractionLayer_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(&stBcklSwStatFrame);

	/* Trigger the reset of the timeout varible when we receive new data */
	CIL_bTimeoutError_Bckl = B_FALSE;

   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_BUCKLE_AEC_CFG, &cil_u8AECStatus);

   /* [COVERS: DSG_CIL_0302] */
   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      cil_u8CounterNotifBckl ++;
   }


}
/**
 * \brief
 *     Function called when a new Ign_Stat_Pr5_ST3 message is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx(void)
{
	/* Read Ign_Stat_ST3 frame signals values only when we receive new data */
	/* [COVERS: DSG_CIL_0002, DSG_CIL_0005, DSG_CIL_0041] */
	cil_u8ImplausibleData_Ignition = Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(&cil_stIgnStatFrame);

	/* Trigger the reset of the timeout varible when we receive new data */
	CIL_bTimeoutError_Ign = B_FALSE;

	/* Trigger the handling of the Ign signal needed by the EcuStatHandler */
	IgnStatReception(cil_u8ImplausibleData_Ignition ,cil_stIgnStatFrame);

	/*Determine if a new ignition POWER cycle happens */
	if(I_C03_ISW_STAT_IGN_OFF == cil_stIgnStatFrame.ISw_Stat_ST3)
	{
	   cil_u8PreviousIgnitionSignal = cil_stIgnStatFrame.ISw_Stat_ST3;
	}

   if((I_C03_ISW_STAT_IGN_OFF == cil_u8PreviousIgnitionSignal) && (I_C03_ISW_STAT_IGN_ON == cil_stIgnStatFrame.ISw_Stat_ST3))
   {
      cil_u8NewIgnPowerCycle = KU8_TRUE;
   }
   else
   {
      cil_u8NewIgnPowerCycle = KU8_FALSE;
      cil_u8PreviousIgnitionSignal = cil_stIgnStatFrame.ISw_Stat_ST3;
   }


}
/**
 * \brief
 *     Function called when a new ORC_Impact2_Pr5_ST3 message is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx(void)
{
	/* Read Impact2_ST3 frame signals values only when we receive new data */
	/* [COVERS: DSG_CIL_0008, DSG_CIL_0201] */
	(void)Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(&cil_stImpactSignalsStatus2);
}
/**
 * \brief
 *     Function called when a new ORC_Impact3_Pr5_ST3 message is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx(void)
{
	/* Read Impact3_ST3 frame signals values only when we receive new data */
	/* [COVERS: DSG_CIL_0003, DSG_CIL_0148, DSG_CIL_0044, DSG_CIL_0045, DSG_CIL_0046, DSG_CIL_0047, DSG_CIL_0200] */
	cil_u8ImplausibleData_ORC = Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(&cil_stImpactSignalsStatus3);
}
/**
 * \brief
 *     Function called when a new PresfAct_Adj_Pr5_ST3 message is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/

void CIL_ComNotification_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx(void)
{
	/* [COVERS: DSG_CIL_0001, DSG_CIL_0004, DSG_CIL_0040, DSG_CIL_0038, DSG_CIL_0039, DSG_CIL_0128, DSG_CIL_0270] */
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

   /* Read PresfAct_Adj_ST3 frame signals values only when we receive new data */
	cil_u8ImplausibleData_Presafe = Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(&cil_stPresfActAdjFrame);

   /* Trigger the reset of the timeout varible when we receive new data */
   CIL_bTimeoutError_Presf = B_FALSE;

   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_PRESAFE_AEC_CFG, &cil_u8AECStatus);

   /* [COVERS: DSG_CIL_0302] */
   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      cil_u8CounterNotifPresf ++;
   }


}
/**
 * \brief
 *     Function called when a new SBeltTens_SP_Lvl_Pr5_ST3 message is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx(void)
{
	/* Read API Interface frame signals values only when we receive new data */
	/* [COVERS: DSG_CIL_0121, DSG_CIL_0202] */
	cil_u8ImplausibleData_API = Rte_Read_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3(&cil_stAPIInterface);

	/* Trigger the reset of the timeout variable when we receive new data */
	CIL_bTimeoutError_API = B_FALSE;
}
/**
 * \brief
 *     Function called when a new PT4_PTCoor4_Pr5_ST3 message is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx(void)
{
	/* [COVERS: DSG_CIL_0156] */
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

	/* Read PT coor 4 St3 frame */
	(void)Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(&cil_stPTCoor4Pr5St3);

	/* Trigger the reset of the timeout varible when we receive new data */
	CIL_bTimeoutError_PwTrain = B_FALSE;

   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_POWERTRAIN_AEC_CFG, &cil_u8AECStatus);

   /* [COVERS: DSG_CIL_0302] */
   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      cil_u8CounterNotifPwt ++;
   }
}
/**
 * \brief
 *     Function called when a new PTCoor_DrvPosn_Gear_Pr5_ST3 message is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx(void)
{
	/* Read driving position frame */
	/* [COVERS: DSG_CIL_0153] */
	(void)Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(&cil_stPTCoorDrvPos);
}
/**
 * \brief
 *     Function called when a new BeltHdOvr_FR_Stat_ST3 signal is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx(void)
{
   /* [COVERS: DSG_CIL_0154, DSG_CIL_0203] */
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

	/* Read belt hand over signals */
	(void)Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3(&cil_u8BeltHandover);

	/* Trigger the reset of the timeout varible when we receive new data */
	CIL_bTimeoutError_BHR = B_FALSE;

   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_BLTHD_R_AEC_CFG, &cil_u8AECStatus);

   /* [COVERS: DSG_CIL_0302] */
   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      cil_u8CounterNotifBltR ++;
   }
}
/**
 * \brief
 *     Function called when a new BeltHdOvr_FL_Stat_ST3 signal is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_BeltHdOvr_FL_Stat_ST3_3489841d_Rx(void)
{
   /* [COVERS: DSG_CIL_0154, DSG_CIL_0204] */
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;

	/* Read belt hand over signals */
	(void)Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3(&cil_u8BeltHandover);

	/* Trigger the reset of the timeout varible when we receive new data */
	CIL_bTimeoutError_BHL = B_FALSE;

   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_BLTHD_L_AEC_CFG, &cil_u8AECStatus);

   /* [COVERS: DSG_CIL_0302] */
   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      cil_u8CounterNotifBltL ++;
   }
}
/**
 * \brief
 *     Function called when a new EVC_CfgList_01_08_Pr5_ST3 signal group is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx(void)
{
   /* Read belt hand over signals */
   /* [COVERS: DSG_CIL_0155, DSG_CIL_0205, DSG_CIL_0269] */
   (void)Rte_Read_CIL_AC_CommunicationInteractionLayer_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(&cil_evcCfgList0108);

   if((I_C02_EVC_STAT_SNA != cil_evcCfgList0108.EVC_List03_StStyle_ST3) &&
         (NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8SteeringWheelConfig != cil_evcCfgList0108.EVC_List03_StStyle_ST3))
   {
      NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8SteeringWheelConfig = cil_evcCfgList0108.EVC_List03_StStyle_ST3;

      (void)Rte_Write_psrCANInputBlockStatus_b8NVMBlockStatus(KU8_TRUE);
   }
   else
   {
      /* do nothing */
   }
}
/**
 * \brief
 *     Function called when a new DI_Odo_Pr5_ST3 signal is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/

void CIL_ComNotification_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx(void)
{
	/* [COVERS: DSG_CIL_0271] */
	CIL_bTimeoutError_OdoS = B_FALSE;
}
/**
 * \brief
 *     Function called when a new BeltAdj signal is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/

void CIL_ComNotification_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx(void)
{
   /* [COVERS: DSG_CIL_0255] */
   (void)Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3(&cil_u8BltSlckDec);

   /* [COVERS: DSG_CIL_0308] */
   CIL_bTimeoutError_BeltAdj = B_FALSE;
}
/**
 * \brief
 *     Function called when a new ProdMd signal is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_ProdMd_Stat_ST3_be2b5dfe_Rx(void)
{
   /* [COVERS: DSG_CIL_0317] */
   (void)Rte_Read_R_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3(&cil_u8ProdMdSwStatSignal);
}
/**
 * \brief
 *     Function called when a new TransMd signal is received.
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
void CIL_ComNotification_PN14_TransMd_Stat_ST3_2208da29_Rx(void)
{
   /* [COVERS: DSG_CIL_0315] */
   (void)Rte_Read_R_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3(&cil_u8TransMdSwStatSignal);
}


void CIL_ComNotification_ExtTest_Pres_ST3_7e50ca1d_Rx (void)
{
	/* [COVERS: DSG_CIL_0313] */
	Rte_Write_CIL_AC_CommunicationInteractionLayer_psrExtTestPres_b8ExtTesterPresent (B_FALSE);
}

#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"
/******************************************************************************
End Of File
 *****************************************************************************/
