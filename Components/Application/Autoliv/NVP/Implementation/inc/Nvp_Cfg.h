/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the component NVP_CFG_H, part of the package NVP.
These are globally visible.
This file is intended to be included in a package header file;
all components should include the package header file instead of this file.

Current revision: $Revision: 1.2.4.6 $
Checked in:       $Date: 2023/07/18 14:02:31CEST $

*************************************************************************/
#ifndef NVP_CFG_H_
#define NVP_CFG_H_ 1

#include "Std_Types.h"
//#include "Config.h"
#include "common.h"
#include "Nvp_Generated.h"
#include "NvM_Cfg.h"

/*************************************************************************
Other components external interface inclusion
*************************************************************************/

/*************************************************************************
Declaration of constants
*************************************************************************/

/**** START_2 : Memories cluster list                                ****/
#define NVP_KU8_MEMORY_CLUSTER_MAX_LIMIT                          (        2u )
/**** END_2   : Memories cluster list                                ****/

/* Mask used to determine which auto-test is enabled for a block */
#define NVP_KU8_NO_AUTO_TEST_MASK                                 ((uint8) 0x00)
#define NVP_KU8_E2P_NOT_PROGRAMMED_AT_MASK                        ((uint8) 0x02)
#define NVP_u16CarAccelerationTimeout                             ((uint8) 0x00)

/* Cycles name and IDs  */
#define KU8_CYCLE_RESERVED          ((uint8) 254u)
#define KU8_NO_BELT_FUNCTION        ((uint8) 255u)
#define KU8_NB_OF_BELT_FUNCTION     ((uint8)  38u)

#define KU8_NB_OF_BELT_STEPS        ((uint8) 145u)
/* Stubbing of non-integrated SW components */
#define KU8_NB_STEPS                               ((uint8) 145)
#define KU8_NVP_CYCLE_SIZE                         ((uint8) 12)
#define KU8_NVP_BLOCK_STEP_SIZE                    ((uint8) 8)
#define KU8_NVP_FOLLOWING_CYCLE_ID                 ((uint8) 3)
#define KU8_NVP_START_CYCLES                       ((uint8) 4)
/* NVP Process Mode status */
#define KU8_NVP_PROCESS_MODE_INACTIVE              ((uint8)0x55)
#define KU8_NVP_PROCESS_MODE_ACTIVE                ((uint8)0xAA)
/* NVP ECU lock/unlock status */
#define KU8_ECU_UNLOCK                             ((uint8)0xAA) /* B_TRUE  */
#define KU8_ECU_LOCK                               ((uint8)0x55) /* B_FALSE */
/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

typedef uint8 (* tMemoryReadAddressFct)   (const uint16 u16StartAddress, const uint16 u16Length, uint8 * const pu8Data);
typedef uint8 (* tMemoryWriteAddressFct)  (const uint16 u16StartAddress, const  uint16 u16Length, const uint8 * const pu8Data);

/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    NVP Vehicle Equipment Configuration Data
 * \remarks
 *    NA
 */
typedef struct
{
   /* 0310 */
   /* Byte 0*/
   uint8 VehicleSteeringConfig : 1;
   uint8 BSRActivation : 1;
   uint8 BltHandOverAvailabiliy : 1;
   uint8 Reserved1 : 1;
   uint8 HWALeftActivation : 1;
   uint8 HWARightActivation : 1;
   uint8 APIActivation : 1;
   uint8 Reserved2 : 1;

   /* Bytes 1-4*/
   uint32 PreSafeCycleActivation;

   /* Byte 5 */
   uint8 ORCPreSafe8Activation : 1;
   uint8 StartUpActivation : 1;
   uint8 Reserved3 : 3;
   uint8 ReleaseOutOfMemory : 1;
   uint8 BSROutOfMemory : 1;
   uint8 PreSafeOutOfMemory : 1;

   /* Byte 6 */
   uint8 Reserved4 : 8;

   /* Byte 7 */
   uint8 Reserved5 : 8;

   /* Bytes 8-9 */
   uint16 UndervoltageAbort : 16;

   /* Bytes 10-11 */
   uint16 Undervoltage : 16;

   /* Bytes 12-13 */
   uint16 OvervoltageAbort : 16;

   /* Bytes 14-15 */
   uint16 Overvoltage : 16;

   /* 0311 */
   /* Byte 0*/
   uint8 MeasFrame1Activation : 1;
   uint8 MeasFrame2Activation : 1;
   uint8 MeasFrame3Activation : 1;
   uint8 MeasFrame4Activation : 1;
   uint8 MeasFrame5Activation : 1;
   uint8 MeasFrame6Activation : 1;
   uint8 MeasFrame7Activation : 1;
   uint8 MeasFrame8Activation : 1;

   /* Byte 1*/
   uint8 PreSafeFuncActivation : 1;
   uint8 DisplayMsgActivation : 1;
   uint8 CounterLimitActivation : 1;
   uint8 CRCFaultActivation : 1;
   uint8 Reserved6 : 4;

} nvp_stVehicleEquipmentData;
/*************************************************************************
Declaration of variables
*************************************************************************/
extern uint8 NVP_u8JobOnAddressStatus;
extern uint8 NVP_u8JobOnAddressErrorCode;
extern nvp_stVehicleEquipmentData NVP_stVehicleEquipmentData;

/*************************************************************************
Declaration of constant data
*************************************************************************/

/*************************************************************************
Declaration of functions
*************************************************************************/
extern void NVP_Init(void);

/*************************************************************************
Evolution of the component

Created by : C.Sauvage

$Log: Nvp_Cfg.h  $
Revision 1.2.4.6 2023/07/18 14:02:31CEST Andreea Negrea (andreea.negrea) 
Update LVL 8 no resuming conditions ;
Update cycle validity
Update inhbition for timeout presafe
Update Request counter read info when LVL 8 is inhibitted
Revision 1.2.4.5 2023/02/01 13:51:20EET Stefan Dominte (stefan.dominte) 
QAC fixes update for NVP module
Revision 1.2.4.4 2023/01/18 09:42:23EET Mirela Obada (mirela.obada) 
Update Tresholds for PowerVoltage autotests, add trigger case for OV/UV During tensioning, update aec preconditions
Revision 1.2.4.3 2022/08/08 12:46:37EEST Mihai Ianos (mihai.ianos) 
increased the number of steps to 145
Revision 1.2.4.2 2021/12/30 13:25:08EET Roberto Cristoi (roberto.cristoi) 
Initial revision
Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/NVP/Implementation/inc/project.pj
Revision 1.1.1.8.2.4 2021/07/20 16:45:08EEST Dan Dustinta (dan.dustinta) 
update cycle definition for P30
Revision 1.1.1.8.2.3 2020/10/30 15:59:17EET Andreea Negrea (andreea.negrea) 
Extend profile limit to 38 and add new 40 steps
Revision 1.1.1.8.2.2 2020/10/29 21:31:16EET Anca Vulpe (anca.vulpe) 
Add InPosition feature
Revision 1.1.1.8.2.1 2020/07/10 14:38:41EEST Dan Dustinta (dan.dustinta) 
update for NvM versioning mechanism
Revision 1.1.1.8 2018/06/18 14:58:07EEST Arthur Mahe (arthur.mahe) 
Change table calib index name
Revision 1.1.1.7 2018/06/15 11:50:24CEST Arthur Mahe (arthur.mahe) 
Update RTE for block length and block status functions
Revision 1.1.1.6 2017/05/03 15:59:57CEST Charlene Dibourg (charlene.dibourg) 
Add blocks RAM Start Addresses in the structure
Revision 1.1.1.5 2017/04/07 08:42:49CEST Charlene Dibourg (charlene.dibourg) 
Remove checksums tables and update u8BLockLength into  u16BLockLength
Revision 1.1.1.4 2017/03/30 16:02:58CEST Andrei Mestereaga (andrei.mestereaga) 
- Nvp_Cfg.h header added to BFE componenet (adding include directive to BFE_Config.h file)
 - All used deifinitions moved from compiler.h (used by Target Link libraries) to Nvp_Cfg.h file and Pmp_public.h file
Revision 1.1.1.3 2017/03/27 16:20:09EEST Charlene Dibourg (charlene.dibourg) 
Remove unused parameters
Revision 1.1.1.2 2017/02/24 09:50:08CET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:19:53CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:27:15CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/NVP/Implementation/inc/project.pj
Revision 1.1 2016/10/05 18:27:15CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/NVP/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:15CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/NVP/Implementation/inc/project.pj
Revision 1.2 2016/10/05 09:54:39CEST Audrey Vache (audrey.vache) 
migration from ETAS sandbox to Core one (diff from checkpt 1.5 to 1.6)
Revision 1.8 2016/09/29 18:37:24CEST Pierre-Olivier Pilot (pierre-olivier.pilot) 
Add a new look up table for belt functions
Revision 1.7 2016/09/15 14:51:10CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 446621 - Corrections of QAC warnings with level superior or equal to 6
Revision 1.6 2016/08/01 13:27:14CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0 415769 - from R2.3 383485 - NVP checksum
Architecture updates:
- New service in NVP module used to compute all NVP checksums.
- New link between DIA and NVP to trigg the checksum computation.
- New auto test : NVP checksum.
- New link betwen NVP and ATM to call the NVP checksum auto test by a server.
- New AEC : NVP checksum.
Impacted SW components: ATM, DIA, ERH, MCU and NVP.
Revision 1.5 2016/07/25 10:54:50CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0 429268 - NVP integration from R2.3
Integration of NVP files from SBE_PP4G_MAINSTREAM_023_VALID checkpoint.
Subs done in ADC, DIA, ERH and NVP.
Revision 1.4 2016/06/07 12:52:32CEST Audrey Vache (avache) 
Memory mapping implementation
Revision 1.3 2015/11/25 09:57:51CET Maxime Bourdon (mbourdon) 
Migration of NVP services at RTE level
Revision 1.2 2015/11/03 10:22:03CET Maxime Bourdon (mbourdon) 
RTE files inclusion clean up
Revision 1.1 2015/10/13 15:52:58CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_NVP/inc/project.pj
Revision 1.6 2015/09/22 16:57:54CEST Pierre-Olivier Pilot (ppilot) 
Add EEPROM Not Programmed Auto-test
Revision 1.5 2014/12/22 10:03:02CET Cedric Sauvage (csauvage) 
Add E2P layout control with Watermarks and Versioning data
Revision 1.4 2014/12/10 16:58:57CET Sebastien Claveau (sclaveau) 
Clean common.gen/h and update macro names
Revision 1.3 2014/05/21 16:21:19CEST Cedric Sauvage (csauvage) 
Add Priority column for blocks rows.
Update of the macro to generate the NVP in order to take into account this new parameter.
Revision 1.2 2014/05/16 08:11:58CEST Cedric Sauvage (csauvage) 
QAC analysis
Revision 1.1 2014/04/29 17:03:34CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_NVP/inc/project.pj


*************************************************************************/

/* end of file */

#endif /* NVP_CFG_H_ */
