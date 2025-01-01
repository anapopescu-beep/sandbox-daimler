/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file is used to configure application to allow inclusion of project
specific configuration files.

Current revision: $Revision: 1.2.2.3 $
Checked in:       $Date: 2022/07/12 09:24:10CEST $

*************************************************************************/


#ifndef I_CONFIG
#define I_CONFIG 1

#include "Os.h"
/********* Define of target to be checked in all LLD files *********/
#define MCU_TYPE_S12Z


/* Generic options applicable to the current project implementation */
/* based on the current HW available */


/********** Global options that will impact many SW-C **************/

/* High Power : Port / Dio / PWM / Belt function stack */
#define PP4G_WITHOUT_HIGH_POWER              0 /* Just BTNs are managed     */
#define PP4G_WITH_HIGH_POWER                 1 /* HP feature is implemented */

#define PP4G_CFG_HIGH_POWER                  PP4G_WITH_HIGH_POWER

#if PP4G_CFG_HIGH_POWER == PP4G_WITH_HIGH_POWER

#define PP4G_SW_DRIVER_FOR_HP_DUALS_PWMS     0 /* Opposite PWMs CH are managed by SW (with Dead Time etc ) */
#define PP4G_HW_DRIVER_FOR_HP_DUALS_PWMS     1 /* Opposite PWMs CH are managed by external component       */

#define PP4G_CFG_DUALS_BOOST_PWMS            PP4G_SW_DRIVER_FOR_HP_DUALS_PWMS

#endif

/********** Define compiler specific DI/EI instruction *************/
#define DisableAllInterrupt()       SuspendAllInterrupts()
#define EnableAllInterrupt()        ResumeAllInterrupts()


/************* List of configuration file definition ***************/
/*  TIMER module */
#if 0
#define COMP_TIM_CFG    "Timer_cfg_generic.h"
/*  TIMER module */
#define COMP_SCH_CFG    "Scheduler_Cfg.h"
#define COMP_SCH_T_CFG  "Schedule_Table_Cfg.h"
/*  ATM module */
#define COMP_ATM_CFG    "ATM_cfg_generic.h"
#define COMP_ATE_CFG    "ATE_cfg_generic.h"
/*  PRT module */
#define COMP_PRT_CFG    "Port_Cfg.h"
/*  FLS module */
#define COMP_FLS_CFG    "Fls_Cfg.h"
/*  FEE module */
#define COMP_FEE_CFG    "Fee_Cfg.h"
/*  CAN module */
#define COMP_CAN_CFG    "CAN_cfg.h"
/*  BMM module */
#define COMP_BMM_CFG    "BMM_cfg_generic.h"
#endif
#endif

/*************************************************************************
Evolution of the component

Created by :

$Log: Config.h  $
Revision 1.2.2.3 2022/07/12 09:24:10CEST Mirela Obada (mirela.obada) 
Code implemantation to mange error detection mechanism.
Revision 1.2.2.2 2018/09/20 10:19:42EEST Andreea Negrea (andreea.negrea) 
Initial revision
Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/TL_Lib/Implementation/inc/project.pj
Revision 1.1.1.5 2017/04/05 16:31:39EEST Andrei Mestereaga (andrei.mestereaga) 
Disable / Enable interrupt macros changed to meet the AUTOSAR standard definitions
Revision 1.1.1.4 2017/03/31 15:22:47EEST Andrei Mestereaga (andrei.mestereaga) 
All asm instructions related to COSMIC compiler were suppressed from Confing.h file (TL_Lib)
Revision 1.1.1.3 2017/03/31 14:05:26EEST Andrei Mestereaga (andrei.mestereaga) 
Interrupt enable / disable defines were changed using the Rte enter / exit ciritcal section defines
BFE_AC_BeltFunctionExecution_CODE changed to RTE_CODE
Revision 1.1.1.2 2017/02/24 10:52:35EET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:21:53CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:28:45CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/10/05 18:28:45CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:37CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/09/20 09:48:12CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/TL_Lib/Implementation/inc/inc.pj
Revision 1.1 2015/10/13 18:21:55CEST Cedric Sauvage (cedric.sauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/OPT_GENERIC/inc/project.pj
Revision 1.7 2014/09/05 17:31:28CEST Sebastien Claveau (sclaveau) 
Rename BRS into BMM module
Revision 1.6 2014/06/16 07:24:49CEST Cedric Sauvage (csauvage) 
Integration of Low Power mode + CAN wake up
SW Workaround with ADC peripheral to be confirmed with Freescale later
ESM cleaned code
Add Post Run state in ESM
Synchronization between WDG refresh command (COP) and Shutdown Sequence
Add a new MCU API to de-init all peripherals
Register init for MCU Voltage domain VDDC/VDDX
Revision 1.5 2014/04/23 14:40:46CEST Francois.Gilbert (fgilbert) 
Suppression of eval_board and automatic wake up  switches
EOL and VDA functions removed from void list
Revision 1.4 2014/04/11 17:55:52CEST Herve Egnifi (hegnifi) 
Renaming of BDS opt into BRS opt to be compliant with new Modules names
Revision 1.3 2014/02/19 14:54:20CET Cedric Sauvage (csauvage) 
Add PWM boost options for PP4G (will be moved later in the Belt function stack)
Revision 1.2 2014/01/29 10:41:11CET Cedric Sauvage (csauvage) 
Some compil options added
Revision 1.1 2014/01/24 10:30:39CET Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/OPT_GENERIC/inc/project.pj


*************************************************************************/

/* end of file */
