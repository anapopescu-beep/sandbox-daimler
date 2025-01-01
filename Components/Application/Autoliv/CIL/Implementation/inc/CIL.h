
#ifndef CIL_H_
#define CIL_H_ 1

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
$Revision: 1.6.1.45 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/CIL/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Std_Types.h"
#include "Nvp_Generated.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 * 		ECU Location left
 */
#define KU8_CIL_ECU_SIDE_FRONT_LEFT                   ((uint8) 0x9C)
/**
 * \brief
 * 		ECU Location right
 */
#define KU8_CIL_ECU_SIDE_FRONT_RIGHT                  ((uint8) 0x99)
/**
 * \brief
 *       NVP ECU Location
 */
#define KU8_CIL_ECU_LOCATION                          (NVP_BLOCK_ID_ECU_LOCATION_RamBlockData.NVP_u8ECULocation)

/**
 * \brief
 * 		RBTM_FL PDU CAN Id
 */
#define KU32_CIL_RBTM_FL_CAN_ID                 	  ((uint32) 0x00000698u)
/**
 * \brief
 * 		RBTM_FR PDU CAN Id
 */
#define KU32_CIL_RBTM_FR_CAN_ID                 	  ((uint32) 0x00000699u)

/* DEFINES FOR BELT CYCLES PROFILES */
/**
 * \brief
 * 		HWA 1-1 cycle configuration
 */
#define KU8_CIL_HWA10_CYCLE                      	  KU8_BELT_FUNCTION_18
/**
 * \brief
 * 		HWA 1-2 cycle configuration
 */
#define KU8_CIL_HWA11_CYCLE                      	  KU8_BELT_FUNCTION_19
/**
 * \brief
 * 		HWA 1-1 cycle configuration
 */
#define KU8_CIL_HWA20_CYCLE                      	  KU8_BELT_FUNCTION_20
/**
 * \brief
 * 		HWA 1-2 cycle configuration
 */
#define KU8_CIL_HWA21_CYCLE                      	  KU8_BELT_FUNCTION_21
/**
 * \brief
 * 		HWA 1-1 cycle configuration
 */
#define KU8_CIL_HWA30_CYCLE                      	  KU8_BELT_FUNCTION_22
/**
 * \brief
 * 		HWA 1-2 cycle configuration
 */
#define KU8_CIL_HWA31_CYCLE                      	  KU8_BELT_FUNCTION_23
/**
 * \brief
 * 		HWA 1-1 cycle configuration
 */
#define KU8_CIL_HWA40_CYCLE                      	  KU8_BELT_FUNCTION_24
/**
 * \brief
 * 		HWA 1-2 cycle configuration
 */
#define KU8_CIL_HWA41_CYCLE                      	  KU8_BELT_FUNCTION_25
/**
 * \brief
 * 		BSR cycle configuration
 */
#define KU8_CIL_BSR_CYCLE                       	  KU8_BELT_FUNCTION_26
/**
 * \brief
 * 		SMO cycle configuration
 */
#define KU8_CIL_SMO_CYCLE                       	  KU8_BELT_FUNCTION_29
/**
 * \brief
 * 		PAT cycle configuration
 */
#define KU8_CIL_PAT_CYCLE                      	      KU8_BELT_FUNCTION_32
/**
 * \brief
 * 		Masks to get CIL Tensioning Aborting modes
 */
#define KU32_CIL_MASK_TENS_ABORTING_MODES           (MMG_KU32_MASK_AEC_INHIB_TENSIONING_CYCLES)
/**
 * \brief
 * 		Masks to get CIL Tensioning Inhibiting modes
 */
#define KU32_CIL_MASK_TENS_INHIBITING_MODES         (MMG_KU32_MASK_AEC_INHIB_TENSIONING_CYCLES|MMG_KU32_MASK_EOL_LOW_FORCE)
/**
 * \brief
 * 		Masks to get CIL All cycles Aborting modes
 */
#define KU32_CIL_MASK_ALL_ABORTING_MODES            (MMG_KU32_MASK_AEC_ECU_DEFECT_ALL_CYCLES )
/**
 * \brief
 * 		Masks to get CIL All cycles Inhibiting modes
 */
#define KU32_CIL_MASK_ALL_INHIBITING_MODES          (MMG_KU32_MASK_AEC_ECU_DEFECT_ALL_CYCLES | MMG_KU32_MASK_AEC_INHIB_ALL_CYCLES)
/**
 * \brief
 * 		Masks to get CIL BSR Inhibiting modes
 */
#define KU32_CIL_MASK_BSR_INHIBITING_MODES          (MMG_KU32_MASK_EOL_COMFORT|MMG_KU32_MASK_EOL_LOW_FORCE|MMG_KU32_MASK_AEC_ECU_DEFECT_ALL_CYCLES)
/* *
 *  brief
 * 		define for unused variable
 */
#define KU8_CIL_ACTV_LVL_UNUSED                    (26u)
/**
 * \brief
 * 		define for delay  PwtDelay : [0x00 ; 0xC8]
 * Default value :  1000ms(0x14), resolution : 50 ms
 * delay = ReadValue * 50 ms resolution / 10 (cyclic event 10 ms ))
 */
#define KU16_CIL_POWERTRAIN_DELAY                   ((uint16) ((NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8PwtDelay) * 5))
/**
 * \brief
 * 		define for delay  PwtDelay : [0x00 ; 0x64]
 * Default value :  1000ms(0x14), resolution : 50 ms
 * delay = ReadValue * 50 ms resolution / 10 (cyclic event 10 ms ))
 */
#define KU16_CIL_AFTER_BUCKLE_DELAY                   ((uint16) ((NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8AfterBuckle) * 5))
/**
 * \brief
 * 		define for delay  PwtDelay : [0x00 ; 0x32]
 * Default value :  100ms(0x02), resolution : 50 ms
 * delay = ReadValue * 50 ms resolution / 10 (cyclic event 10 ms ))
 */
#define KU16_CIL_AFTER_MD_DELAY                   ((uint16) ((NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u8AfterMd) * 5))
/**
 * \brief
 * 		define for delay  60 s = 60 000 / 10
 */
#define KU16_CIL_EMERGENCY_RELEASE                   ((uint16)6000)
/**
 * \brief
 * 		define for delay  TimeOutPresafe5 : [0x000A ; 0x0BB8]
 * Default value :  5000ms(0x1F4), resolution 10 ms
 */

#define KU16_CIL_TIMEOUT_PRESAFE_5            ((uint16)(NVP_BLOCK_ID_CYCLE_DELAYS_MB_RamBlockData.NVP_u16TimeoutPresafe5))
/**
 * \brief
 * 		HWA TYPE - FIXED
 */
#define KU8_CIL_FIXED_HWA                   ((uint8) 0x00)
/**
 * \brief
 * 		HWA TYPE - FIXED
 */
#define KU8_CIL_NON_FIXED_HWA               ((uint8) 0x01)
/**
 * \brief
 * 		API abortion mask
 */
#define KU16_CIL_API_ABORT_MASK               ((uint16) 0x8E3)
/**
 * \brief
 * 		API inhibition mask
 */
#define KU16_CIL_API_INHIB_MASK               ((uint16) 0x254B)
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/*! 
 *  \brief Manage cycle structure
 *
 */
typedef struct
{ 	
	/**
 	* \brief
 	*		Manage cycle structure request source element
 	*/
	c04_RBTM_ActvClient u8RequestSource;
	/**
 	* \brief
 	*		Manage cycle structure current requested cycle element
 	*/
	uint8 u8CurrentRequestedCycle;
	/**
 	* \brief
 	*		Manage cycle structure old request cycle element
 	*/
	uint8 u8OldRequestedCycle;
	/**
 	* \brief
 	*		Manage cycle structure inhibition status element
 	*/
	boolean bInhibitionStatus;
}CIL_ManageCycle;
/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

extern DC_BOOL CIL_bRBTMTgl;

extern c02_Off_Stage1_Stage2 CIL_u8PSCurve;

extern CIL_ManageCycle CIL_stManagedCycle;

extern c06_RBTM_Lvl_Stat CIL_u8Actv_Lvl;

extern c04_RBTM_ActvClient CIL_u8Actv_Client;

extern boolean CIL_bTimeoutError_Presf;

extern boolean CIL_bTimeoutError_Bckl;

extern boolean CIL_bTimeoutError_API;

extern boolean CIL_bTimeoutError_BHR;

extern boolean CIL_bTimeoutError_BHL;

extern boolean CIL_bTimeoutError_Ign;

extern boolean CIL_bTimeoutError_PwTrain;

extern boolean CIL_bTimeoutError_OdoS;

extern boolean CIL_bTimeoutError_BeltAdj;

extern uint16 CIL_u16InhibitionStatus;

extern uint8 cil_u8ImplausibleData_Presafe;

extern uint8 cil_u8ImplausibleData_Ignition;

extern uint8 cil_u8ImplausibleData_Buckle;

extern uint8 cil_u8ImplausibleData_ORC;

extern uint8 cil_u8ImplausibleData_API;

extern c02_BeltHdOvr_Stat cil_u8BeltHandover;

extern REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw cil_evcCfgList0108;

extern REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw cil_stPTCoor4Pr5St3;

extern REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j cil_stPresfActAdjFrame;

extern REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt stBcklSwStatFrame;

extern REC_Ign_Stat_Pr5_ST3 cil_stIgnStatFrame;

extern c02_Bckl_Sw_Stat cil_u8BcklSwStatSignal;

extern REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh cil_stPTCoorDrvPos;

extern REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt cil_stAPIInterface;

extern uint8 cil_u8PRESAFERequest;

extern uint8 cil_u8APIRequest;

extern uint8 cil_u8APIActivationRequest;

extern uint16 CIL_u16AbortionStatus;

extern uint8 cil_u8CounterNotifPresf;

extern uint8 cil_u8CounterNotifBckl;

extern uint8 cil_u8CounterNotifBltL;

extern uint8 cil_u8CounterNotifBltR;

extern uint8 cil_u8CounterNotifPwt;

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/
LOCAL boolean cil_Update_07Cx_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block01_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block02_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block03_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block04_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block05_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block06_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block07_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block08_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block09_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block10_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block11_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block12_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block13_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block14_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block15_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block16_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block17_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block18_InfosToSend(void);
LOCAL void cil_Update_07Cx_Block20_InfosToSend(void);
LOCAL void cil_Update_07Cx_IncorrectBlock_InfosToSend(void);
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _CIL_H_ */
