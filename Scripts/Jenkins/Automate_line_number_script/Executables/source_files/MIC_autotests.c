/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

COMPONENT MCU_Registers

Current revision: $Revision: 1.1 $
Checked in:       $Date: 2021/10/04 07:14:25CEST $

**************************************************************************

Overview of the component : The MIC - Memory Integrity Control is designed
                            in order to control the MCU memory state and to apply
                            the backup strategy (if possible) in case of issue
                            detection

------------------------------------------------------------------------

Design document:
MIC - SW Module Design Document.docx

*************************************************************************/

/*************************************************************************
Packages inclusion
*************************************************************************/
#include "Rte_MIC_AC_MemoryIntegrityControl.h"
#include "Nvp_Generated.h"

/*************************************************************************
Intra-package inclusions
*************************************************************************/

/*************************************************************************
Private inclusion
*************************************************************************/

/*************************************************************************
Declaration of constants
*************************************************************************/

/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
LOCAL variables declaration
*************************************************************************/

/*************************************************************************
LOCAL constant data declaration
**************************************************************************/

/*************************************************************************
EXPORTED variables declaration
*************************************************************************/
extern boolean MIC_bECCErrFls;
/*************************************************************************
EXPORTED constant data declaration
**************************************************************************/

/**************************************************************************
Private Functions
**************************************************************************/

/**************************************************************************
Exported Functions
**************************************************************************/
#define MIC_AC_MemoryIntegrityControl_START_SEC_CODE
#include "MIC_AC_MemoryIntegrityControl_MemMap.h"

/**************************************************************************
Name : MIC_cbk_RunRamMemoryCorruption_Autotest
Object: This autotest aims at checking if an ECC was detected in RAM memory
area.
Parameters: None
Return:
 The test result (uint8):
   - KU8_ATM_TEST_OK
   - KU8_ATM_TEST_NOK
   - KU8_ATM_TEST_NOT_DECIDED
Constraints : None.
**************************************************************************/
/*COVERS: DSG_MIC_0004 */
void MIC_Autotest_RunRamMemoryCorruption(u8TestResultType * pu8TestResult)
{
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint32 u32ResetCause;

   /* Call service to get RAM ECC status */
   /* Architecture ensures that RCM reset cause determination has been done */
   /* at initialisation of software, before reading reset cause in this auto test */

   /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
                       /* QAC warning due to comma operator into RTE macro */
   /* QAC_WARNING S 3426 3 */ /* Right hand side of comma expression has no side effect and its value is not used.*/
                       /* QAC does not recognize RTE macros */
   Rte_Call_pclResetCause_GetResetCause(&u32ResetCause);

   /* If RAM ECC error is active -> autotest is failed */
   if ( (KU32_ECC_RAM_MASK == (u32ResetCause & KU32_ECC_RAM_MASK))
     || (KU32_RAM_DATA_CORRUPTED == (u32ResetCause & KU32_RAM_DATA_CORRUPTED)) )
   {
      /* Indicate autotest is failed */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

      /*Increment the RAM ECC Occurrence Number*/
      NVP_u32RAMECCOccurrenceNumber++;

      /* Notify that the ECC Counters Block has to be recorded in the EEPROM during the shutdown */
      /* (void) the return value is always E_OK because the block exist*/
      (void)Rte_Call_pclNvmServicesEccCounters_SetRamBlockStatus(TRUE);
   }
   else
   {
      /* Indicate autotest is successful */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**************************************************************************
Name : MIC_cbk_RunPFlashMemoryCorruption_Autotest
Object: This autotest aims at checking if an ECC was detected in PFLASH
 memory area.
Parameters: None
Return:
 The test result (uint8):
   - KU8_ATM_TEST_OK
   - KU8_ATM_TEST_NOK
   - KU8_ATM_TEST_NOT_DECIDED
Constraints : None.
**************************************************************************/
/*COVERS: DSG_MIC_0005 */
void MIC_Autotest_RunPFlashMemoryCorruption(u8TestResultType * pu8TestResult)
{
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint32 u32ResetCause;

   /* Call service to get PFLASH ECC status */
   /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
                       /* QAC warning due to comma operator into RTE macro */
   /* QAC_WARNING S 3426 3 */ /* Right hand side of comma expression has no side effect and its value is not used.*/
                       /* QAC does not recognize RTE macros */
   Rte_Call_pclResetCause_GetResetCause(&u32ResetCause);

   /* If PFLASH ECC error is active -> autotest is failed */
   if ( KU32_ECC_PFLASH_MASK == (u32ResetCause & KU32_ECC_PFLASH_MASK) )
   {
      /* Indicate autotest is failed */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

      /*Increment the PFLASH ECC Occurrence Number*/
      NVP_u32PFLASHECCOccurrenceNumber ++;

      /* Notify that the ECC Counters Block has to be recorded in the EEPROM during the shutdown */
      /* (void) the return value is always E_OK because the block exist*/
      (void)Rte_Call_pclNvmServicesEccCounters_SetRamBlockStatus(TRUE);
   }
   else
   {
      /* Indicate autotest is successful */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**************************************************************************
Name : MIC_cbk_RunTFlashMemoryCorruption_Autotest
Object: This autotest aims at checking if an ECC was detected in TFLASH
 memory area.
Parameters: None
Return:
 The test result (uint8):
   - KU8_ATM_TEST_OK
   - KU8_ATM_TEST_NOK
   - KU8_ATM_TEST_NOT_DECIDED
Constraints : None.
**************************************************************************/
/*COVERS: DSG_MIC_0006 */
void MIC_Autotest_RunTFlashMemoryCorruption(u8TestResultType * pu8TestResult)
{
/* CRE: Stubbed auto test since not implemented for P10 */
#if 0
   uint8 u8ResultOfAutoTest;
   uint8 u8TFlashEccStatus;
   uint32 *pu32TFLASHECCOccurrenceNumber = (uint32 *)&NVP_u32TFLASHECCOccurrenceNumber;
   uint8 *pu8ECCOccurrenceNumberAddress = (uint8 *)&NVP_u32RAMECCOccurrenceNumber;

   /* Call service to get TFLASH ECC status */
   Rte_Call_pclGetEccErrorStatus_GetEccError(KU8_ECC_ERROR_TFLASH,&u8TFlashEccStatus);

   /* If TFLASH ECC error is active -> autotest is failed */
   if(KU8_ECC_STATUS_ACTIVE == (u8TFlashEccStatus & KU8_ECC_STATUS_ACTIVE))
   {
      /* Indicate autotest is failed */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

      /*Increment the TFLASH ECC Occurrence Number*/
      (*pu32TFLASHECCOccurrenceNumber) ++;

      /* Notify that the ECC Counters Block has to be recorded in the EEPROM during the shutdown */
      Rte_Call_pclNvmServicesEccCounters_SetRamBlockStatus(TRUE);
   }
   else
   {
      /* Indicate autotest is successfull */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   return(u8ResultOfAutoTest);
#endif

   *pu8TestResult = KU8_ATM_TEST_OK;
}

/**************************************************************************
Name : MIC_Autotest_RunEepromMemoryCorruption
Object: This autotest aims at checking if an ECC was detected in DFLASH
 memory area.
Parameters: None
Return:
 The test result (uint8):
   - KU8_ATM_TEST_OK
   - KU8_ATM_TEST_NOK
   - KU8_ATM_TEST_NOT_DECIDED
Constraints : None.
**************************************************************************/
/*COVERS: DSG_MIC_0007 */
void MIC_Autotest_RunEepromMemoryCorruption(u8TestResultType * pu8TestResult)
{
   uint8 u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   uint32 u32ResetCause;
   /* QAC_WARNING S 0310 2 */ /* Casting to different object pointer type. */
                          /* The address value of the parameter must be cast to uint8 pointer to pass as parameter */

   /* Call service to get DFLASH ECC status */
   /* Architecture ensures that RCM reset cause determination has been done */
   /* at initialisation of software, before reading reset cause in this auto test */

   /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
                       /* QAC warning due to comma operator into RTE macro */
   /* QAC_WARNING S 3426 3 */ /* Right hand side of comma expression has no side effect and its value is not used.*/
                       /* QAC does not recognize RTE macros */
   Rte_Call_pclResetCause_GetResetCause(&u32ResetCause);

   /* If DFLASH ECC error is active -> autotest is failed */
   if (( KU32_ECC_E2P_MASK == (u32ResetCause & KU32_ECC_E2P_MASK) ) || (MIC_bECCErrFls == B_TRUE))
   {
      MIC_bECCErrFls = B_FALSE;

      /* Indicate autotest is failed */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;

      /*Increment the DFLASH ECC Occurrence Number*/
      NVP_u32DFLASHECCOccurrenceNumber ++;

      /* Notify that the ECC Counters Block has to be recorded in the EEPROM during the shutdown */
      /* (void) the return value is always E_OK because the block exist*/
      (void)Rte_Call_pclNvmServicesEccCounters_SetRamBlockStatus(TRUE);
   }
   else
   {
      /* Indicate autotest is successful */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}




#define MIC_AC_MemoryIntegrityControl_STOP_SEC_CODE
#include "MIC_AC_MemoryIntegrityControl_MemMap.h"

/*************************************************************************
Evolution of the component

Created by : Pierre-Olivier.Pilot

$Log: MIC_autotests.c  $
Revision 1.1 2021/10/04 07:14:25CEST Lucian Ardeleanu (lucian.ardeleanu) 
Initial revision
Member added to project e:/MKSProjects/SBE/Exploration/Python_Workspace/Automate_line_number_script/Executables/source_files/project.pj
Revision 1.1.1.5.1.3 2021/05/20 11:11:24EEST Razvan Badiu (razvan.badiu) 
ECC workaround
Revision 1.1.1.5.1.2 2020/07/30 10:10:42EEST Dan Dustinta (dan.dustinta) 
update traceability
Revision 1.1.1.5.1.1 2020/07/30 09:40:08EEST Dan Dustinta (dan.dustinta) 
update traceability for MIC
Revision 1.1.1.5 2017/04/27 17:50:43EEST Charlene Dibourg (charlene.dibourg) 
Use SetRamBlockStatus instead of WriteBlock (write EccCounters Nvm Block during shutdown)
Revision 1.1.1.4 2017/04/03 10:58:02CEST Charlene Dibourg (charlene.dibourg) 
Add EEprom Memory Corruption Autotest (no more as comment)
Revision 1.1.1.3 2017/03/27 15:17:34CEST Charlene Dibourg (charlene.dibourg) 
Add NvmServices and EepromMemoryCorruption Autotest
Revision 1.1.1.2 2017/02/24 09:49:34CET Michael Pastor (michael.pastor) 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:19:24CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:27:08CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/MIC/Implementation/src/project.pj
Revision 1.1 2016/10/05 18:27:08CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/MIC/Implementation/src/project.pj
Revision 1.1 2016/10/05 10:13:12CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/MIC/Implementation/src/project.pj
Revision 1.2 2016/10/05 09:55:17CEST Audrey Vache (audrey.vache) 
migration from ETAS sandbox to Core one (diff from checkpt 1.5 to 1.6)
Revision 1.9 2016/09/20 16:13:27CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 446133 - Correction of QAC levels inferior to 6
Revision 1.8 2016/09/05 10:40:27CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Revision 1.7 2016/09/05 10:28:43CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove P R Q A
Replace by P R Q A in comments
Revision 1.6 2016/09/05 10:02:45CEST Sabine Flechelle (sabine.flechelle) 
PP4G R3.0M 444498 - Remove all P R Q As
P R Q A is replaced by QAC_WARNING
Revision 1.5 2016/07/18 15:41:01CEST Stefan Dragan (stdragan) 
Issue 415738, Integrate Issue 364799-Implement strategy to manage ESM and CanNM state variables corruption
Revision 1.4 2016/06/07 13:51:59EEST Audrey Vache (avache) 
Memory mapping implementation
Revision 1.3 2015/11/25 09:57:50CET Maxime Bourdon (mbourdon) 
Migration of NVP services at RTE level
Revision 1.2 2015/11/06 14:11:27CET Maxime Bourdon (mbourdon) 
Pass ATM Autotests calls through RTE + includes clean up
Revision 1.1 2015/10/14 14:39:36CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_MIC/src/project.pj
Revision 1.4 2015/09/25 10:07:26CEST Pierre-Olivier Pilot (ppilot) 
Remove Stack Overflow Auto-test. The reset cause "stack overflow" is evaluated by the RCM auto-test which checked all warm reset cause.
Revision 1.3 2015/09/14 15:46:53CEST Pierre-Olivier Pilot (ppilot) 
Add stack Overflow auto-test:
This test aims at detecting when the stack pointer is outside the stack limit defined in the linker script file.
Revision 1.2 2015/09/08 17:29:45CEST Sabine Flechelle (sflechelle) 
Issue 215089 - Some memory corruption auto tests become startup but not critical
Concerned auto tests are:
- E2P memory corruption
- D Flash memory corruption
- T Flash memory corruption
But P Flash memory corruption stays in the list of critical auto tests.
Revision 1.1 2015/04/23 15:00:33CEST Pierre-Olivier Pilot (ppilot) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_MIC/src/project.pj


*************************************************************************/

/* end of file */
