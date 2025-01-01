/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the configuration of the scheduler.
This file is to be included only by this component.

Current revision: $Revision: 1.1.2.5 $
Checked in:       $Date: 2021/02/02 16:11:51CET $

*************************************************************************/

#ifndef I_COMPILER
#define I_COMPILER 1

/*************************************************************************
Declaration of constants
*************************************************************************/
//#include "Rte_UserCfg.h"
/*************************************************************************
Declaration of macros
*************************************************************************/
//#define LOCAL  static
#define STATIC static
#define DEM_STATIC static

/* Stubbing of non-integrated SW components */

#define KU8_NB_INTERP_PTS_MOTOR_RESIST             ((uint8) 7)
#define KU8_NB_STEPS                               ((uint8) 80)
#define KU8_NVP_CYCLE_SIZE                         ((uint8) 12)
#define KU8_NVP_BLOCK_STEP_SIZE                    ((uint8) 8)
#define KU8_NVP_FOLLOWING_CYCLE_ID                 ((uint8) 3)

/* NVP Process Mode status */
#define KU8_NVP_PROCESS_MODE_INACTIVE              ((uint8)0x55)
#define KU8_NVP_PROCESS_MODE_ACTIVE                ((uint8)0xAA)

/* NVP ECU lock/unlock status */
#define KU8_ECU_UNLOCK                             ((uint8)0xAA) /* B_TRUE  */
#define KU8_ECU_LOCK                               ((uint8)0x55) /* B_FALSE */

/* resolution of Temperature MCU slope in NVP */
#define KU16_NVP_MCU_SLOPE_RES                     ((uint16) 1000)

/* Default Temperature MCU Slope for default NVP values */
#define KU16_DEFAULT_TEMPERATURE_MCU_SLOPE         ((uint16) 5220)

/* Full scale for temperature */
#define KU16_FULL_SCALE_TEMPERATURE_MV             ((uint16) 5000)
#define KU16_FULL_SCALE_TEMPERATURE_LSB                        ((uint16) 1024)

/* Reference point for temperature sensor */
#define KU16_REFERENCE_TEMPERATURE_MV              ((uint16) 2250)
#define KU16_REFERENCE_TEMPERATURE_DEG             ((uint16) 150)

/* Sensor's typical temperature slop in uV/degree C (value as provided by Freescale reference manual) */
#define KU32_TYP_SLOPE_UV_PER_DEG                  ((uint32) 5220u)
/* Temperature sensor's reference temperature in degree C (only temperature where Freescale ensure the sensor output level) */
#define KU16_REF_TEMP_DEG                          ((uint16) 150u)
/* Temperature sensor output in mV at its reference temperature (as calibrated in factory by Freescale) */
#define KU16_REF_TEMP_MV                           ((uint16) 2250u)

/* Checksums table indexes */
#define NVP_KU8_PROCESS_CKS_ID                                    ((uint8)    0)
#define NVP_KU8_AUTOLIV_CAL_CKS_ID                                ((uint8)    1)
#define NVP_KU8_CAR_MAKER_CAL_CKS_ID                              ((uint8)    2)
#define NVP_KU8_NB_CKS_CONFIGURED                                 ((uint8)    3)

/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
Declaration of variables
*************************************************************************/

/*************************************************************************
Declaration of constant data
*************************************************************************/

/*************************************************************************
Declaration of functions
*************************************************************************/
#endif    /* I_COMPILER */

/*************************************************************************
Evolution of the component

Created by : C. REDON

$Log: compiler.h  $
Revision 1.1.2.5 2021/02/02 16:11:51CET Gheorghita Brasoveanu (gheorghita.brasovean) 
UnitTest installation update
Revision 1.1.4.2 2020/03/09 05:12:09EET Reymond Zhang (reymond.zhang) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/PP4G_APP_Generic/Phase_01/View_CIP/Tools/UnitTesting/Workspace/mockup/AUTOSAR_4_2/include/project.pj
Revision 1.1 2020/01/05 08:47:47CST Reymond Zhang (reymond.zhang) 
Initial revision
Member added to project e:/MKSProjects/SBE/PP/GWM_VV7/Phase_01/View_Development/Tools/UnitTesting/Workspace/mockup/AUTOSAR_4_2/include/project.pj
Revision 1.1.2.1 2019/12/30 14:35:01CST Benson Ji (benson.ji) 
add code for dem
Revision 1.1 2017/01/31 21:40:28CST michael.pastor 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_03/View_Development/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/11/25 14:32:38CET Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_054/Platform_Mainstream_Phase_01/Dev_View/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:37CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/09/20 09:48:12CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/TL_Lib/Implementation/inc/inc.pj
Revision 1.7 2016/08/01 13:27:14CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0 415769 - from R2.3 383485 - NVP checksum
Architecture updates:
- New service in NVP module used to compute all NVP checksums.
- New link between DIA and NVP to trigg the checksum computation.
- New auto test : NVP checksum.
- New link betwen NVP and ATM to call the NVP checksum auto test by a server.
- New AEC : NVP checksum.
Impacted SW components: ATM, DIA, ERH, MCU and NVP.
Revision 1.6 2016/06/29 17:58:40CEST Stefan Dragan (stdragan) 
Integrate revision 1.13 from R2.3M- Deactivate PWM AT if process mode
Revision 1.5 2016/06/23 14:49:42EEST Stefan Dragan (stdragan) 
Removed "KU32_REF_TEMP_UV" because is used only by PMP
Revision 1.4 2016/06/17 11:56:59EEST Maxime Bourdon (mbourdon) 
Provide PMP services to DIA
Revision 1.3 2016/06/01 15:54:34CEST Maxime Bourdon (mbourdon) 
DIA ASR 4 migration completion
Revision 1.2 2016/05/23 14:16:47CEST Maxime Bourdon (mbourdon) 
DIA migration to ASR 4.0.3
Revision 1.1 2015/10/21 14:31:26CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/OPT_GENERIC/inc/project.pj
Revision 1.12 2014/05/21 08:51:03CEST Cedric Sauvage (csauvage) 
STM integ
Revision 1.11 2014/05/19 17:32:56CEST Sabine Flechelle (sflechelle) 
Issue_143099 - New BSR private library for configuration
Create BSR_Config.h to contain calibrations
Revision 1.10 2014/05/16 15:00:34CEST Sabine Flechelle (sflechelle) 
Issue_155104 - Update size of NVP step block
BFE_TestHarness.mdl rev 1.15
Cycle size and step are configurable.
Size of NVP Step block becomes 8 bytes.
Revision 1.9 2014/05/16 12:17:35CEST Cedric Sauvage (csauvage)
SCM API stubb removed (since SCM is now available)
Revision 1.8 2014/05/07 14:32:12CEST Sebastien Claveau (sclaveau) 
CAN TP and DCM first integration
Revision 1.7 2014/05/06 15:01:14CEST Sabine Flechelle (sflechelle) 
Issue_143068 - Schedule Belt Functions components
Schedule the periodic runnables of new components:
BFE, BFS, BPA, BSR, EOL, MMG, PAL-A, PAL-S, PCM, PRE, PRO, SFR
Revision 1.6 2014/05/05 16:36:17CEST Cedric Sauvage (csauvage) 
Integration of E2P stack
Revision 1.5 2014/04/30 15:36:57CEST Francois.Gilbert (fgilbert)
Default definition of main function of PCM deleted
Revision 1.4 2014/04/28 10:34:52CEST Temel Demirel (tdemirel) 
ATM/ERH modules integration
Revision 1.3 2014/04/23 14:40:46CEST Francois.Gilbert (fgilbert) 
Suppression of eval_board and automatic wake up  switches
EOL and VDA functions removed from void list
Revision 1.2 2014/04/17 12:28:23CEST Claude Redon (credon) 
SystemDesk - Correction of DIA (& CAN) design + RTE generation
Revision 1.1 2014/04/15 07:55:57CEST Claude Redon (credon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/OPT_GENERIC/inc/project.pj

*************************************************************************/

/* end of file */
