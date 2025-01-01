/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the module PAL.

These are globally visible.

Current revision: $Revision: 1.1.3.5 $
Checked in:       $Date: 2022/07/08 13:27:19CEST $

*************************************************************************/

#ifndef PAL_V2_INC_PAL_PRIVATE_H_
#define PAL_V2_INC_PAL_PRIVATE_H_

/*************************************************************************
Inclusions
*************************************************************************/
#include "PAL_config.h"
#include "Std_Types.h"

/* Definition of masks used to store the state machine status for PAL component
 * Data used : PAL_u8ModeState
 * */
#define PAL_KU8_INIT_MODE_STATE                       ((uint8)0x00)
#define PAL_KU8_DIAGNOSTIC_MODE_STATE                 ((uint8)0x01)
#define PAL_KU8_IDLE_MODE_STATE                       ((uint8)0x02)
#define PAL_KU8_ACTIVATION_MODE_STATE                 ((uint8)0x04)
#define PAL_KU8_OFF_MODE_STATE                        ((uint8)0x08)
/* ADC full scale output value */
#define PAL_KU16_ADC_OUT_SCALE                    ((uint16) 1024u)

#define PAL_KU8_DEG_RANGE                         ((uint8)   135)

#define PAL_KU8_DEG_LOW_RANGE                     ((uint8)   40)

/* Macro to convert a ADC from temeprature output scale to lsb */
#define PAL_KS16_DEG_TO_ADC(adc_temp)  (uint16)((PAL_KU16_ADC_OUT_SCALE * (adc_temp + PAL_KU8_DEG_LOW_RANGE)) / PAL_KU8_DEG_RANGE)

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
Declaration of variables
*************************************************************************/
/* Global data used to know the state machine status for the PAL component */
extern uint8                              PAL_u8ModeState;

extern uint8                              PAL_u8FreeWheelingTimer;

extern const PAL_tTopologyConfiguration   PAL_kstHardWareTopology;

/*************************************************************************
Declaration of functions
*************************************************************************/
/* Internal function for auto test management */
extern void PAL_DisablePowerStage      (void);
extern void PAL_StartFreeWheelingState (void);

#endif /* PAL_V2_INC_PAL_PRIVATE_H_ */

/*************************************************************************
Evolution of the component

Created by : cedric.sauvage

$Log: PAL_private.h  $
Revision 1.1.3.5 2022/07/08 13:27:19CEST Stefan Dominte (stefan.dominte) 
PAL, PMP and AdcIf modules updated
Revision 1.1.3.4 2022/02/15 12:33:58EET Septimiu Vintila (septimiu.vintila) 
Fixes after review.
Revision 1.1.3.3 2022/01/17 07:48:12EET Septimiu Vintila (septimiu.vintila) 
Autotests and interfaces for PAL, PMP added
Revision 1.1.3.2 2021/09/27 14:18:17EEST Septimiu Vintila (septimiu.vintila) 
Initial revision
Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PAL/Implementation/inc/project.pj
Revision 1.1.1.2 2017/02/24 10:50:17EET michael.pastor 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:20:00CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:27:18CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/10/05 18:27:18CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:17CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/09/20 09:48:08CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/PAL/Implementation/inc/inc.pj
Revision 1.2 2015/11/03 10:22:04CET Maxime Bourdon (maxime.bourdon) 
RTE files inclusion clean up
Revision 1.1 2015/10/13 15:52:59CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_PAL/inc/project.pj
Revision 1.3 2015/06/22 16:14:40CEST Sabine Flechelle (sflechelle) 
Issue 196836 - Complete HSW auto test
To follow TF-H97
Create NVP _ u16HSSWRegTestInitThreshold
Add Free wheeling phase if cycle was aborted
Integration test OK: SW_IT_ATM_094
Revision 1.2 2015/04/23 10:31:36CEST Cedric Sauvage (csauvage) 
Code template update
Revision 1.1 2015/04/23 08:39:59CEST Cedric Sauvage (csauvage)
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_PAL/src/src.pj

*************************************************************************/

/* end of file */
