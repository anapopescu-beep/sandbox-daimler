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
$Revision: 1.2.2.7 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/ATM/Quality_Assurance/Static_Analysis/project.pj $
 */
/**
 *  @defgroup TEMPLATE_FILES_Group_Example Group_Example_Name_In_Document
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
 ******************************************************************************/
#include "Rte_ATM_AC_AutoTestManager.h"
#include "common.h"


#include "ATM_public.h"
#include "ATM_private.h"

#include "Nvp_Generated.h"
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *    Define for reinitialize the step period index
 */
#define U16_GET_STEP_PERIOD(index)   (castStartupSequentialList[(index)].u16StepPeriod)
/**
 * \brief
 *    Define for autotest ID
 */
#define U8_GET_AEC_ID(index)   (castATMConfig[index].u8AecIdentifier)
/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
/*************************************************************************
LOCAL variables declaration
*************************************************************************/
#define ATM_AC_AutoTestManager_START_SEC_VAR_8
#include "ATM_AC_AutoTestManager_MemMap.h"

/*QAC_WARNING S 2022 3 */ /* A tentative definition is being used. Is it appropriate to include an explicit initializer ? */
                   /* This array will be initialized during Init function and will not be accessed until
                    * the init function execution */
/**
 * \brief
 *       This array contains the status of each test (RAM)
 * \var
 *        uint8 atm_au8AtStatuses
 */
LOCAL uint8 atm_au8AtStatuses[ATM_KU8_NB_OF_AUTOTEST];

/* QAC_WARNING S 2022 1 */
/**
 * \brief
 *       This variable represents the cyclic task counter. Range : [0..4]
 *      Initialized by ATM_Init
 * \var
 *        uint8 atm_u8CurrentTask
 */
LOCAL uint8 atm_u8CurrentTask;

/* QAC_WARNING S 2022 1 */
/**
 * \brief
 *       Indexes the "castStartupList" array during the start-up test sequence
 *       over several execution of the main function. This array is browsed once,
 *       after what main function will follow the cyclic list of test. Range : [0..255]
 *       Initialized by ATM_Init
 * \var
 *        uint8 atm_u8StartupTestIndex
 */
LOCAL uint8 atm_u8StartupTestIndex;
/* QAC_WARNING S 2022 1 */
/**
 * \brief
 *       Loop indexes the "castCyclicList" array over several execution of the
        main function, only after the completion of the start-up test sequence. Range : [0..255]
      Initialized by ATM_Init
 * \var
 *        uint8 atm_u8CyclicTestIndex
 */
LOCAL uint8 atm_u8CyclicTestIndex;


#define ATM_AC_AutoTestManager_STOP_SEC_VAR_8
#include "ATM_AC_AutoTestManager_MemMap.h"

#define ATM_AC_AutoTestManager_START_SEC_VAR_16
#include "ATM_AC_AutoTestManager_MemMap.h"
/**
 * \brief
 *       This variable is used only during the start-up sequence to count the period between
 *     execution step of tests (if executed during several steps).
 *   Initialized by ATM_Init
 * \var
 *        uint16 atm_u16StartupPeriodCnt
 */
LOCAL uint16 atm_u16StartupPeriodCnt;

/* QAC_WARNING S 2022 1 */ /* Initialized by ATM_Init */
/**
 * \brief
 *       This variable represents the cycle decade counter. Range : [0..59000]
 *    Initialized by ATM_Init
 * \var
 *        uint16 atm_u16CurrentDecade
 */
LOCAL uint16 atm_u16CurrentDecade;

#define ATM_AC_AutoTestManager_STOP_SEC_VAR_16
#include "ATM_AC_AutoTestManager_MemMap.h"
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
#define ATM_AC_AutoTestManager_START_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"
/* QAC_WARNING S 3417 ++ */ /* The comma operator has been used outside a 'for' statement. */
/* QAC_WARNING S 3426 ++ */ /* Right hand side of comma expression has no side effect and its value is not used.*/
                     /* Theses messages concern the RTE macros execution (generated) */

/**
* \brief
*     Consecutively:
* - checks if an auto-test execution is compliant with the ECU mode (according to its parameters)
* - executes it (if compliant), or ignore it (if not compliant)
* - update the AEC status according to the test result (if executed)
* \param[in]
*     uint8 cu8AutotestID
* \exception
*     None.
* \pre
*     None.
* \post
*     None.
* \return
*     void
**/
LOCAL void atm_executeAutoTest(const uint8 cu8AutotestID)
{
   /* To get System context from MMG module */
   u8ModeStatusType u8InhibitingContextStatus;

   /* To store the auto-test results before notification and storage */
   u8TestResultType u8ReturnedAutoTestStatus;

   /* Index of the inhibiting modes combination */
   uint8 u8InhibModesIndex;

   /* Get the combination of inhibition modes which is applicable for this autotest */
   u8InhibModesIndex = castATMConfig[cu8AutotestID].u8InhibIndex;

   /* Get the current system context status of this auto test */
   Rte_Call_pclModeManagement_CheckModeStatus(cau32InhibitingModes[u8InhibModesIndex], &u8InhibitingContextStatus);

   /* Check if the auto test has to be executed regarding its running contexts */
   if (KU8_MODE_STATUS_ON == u8InhibitingContextStatus)
   {
      /* The current mode is not compliant with the test execution. */
      /* Status becomes NOT DECIDED */
      /* and auto test is not scheduled */
      atm_au8AtStatuses[cu8AutotestID] =  KU8_ATM_TEST_NOT_DECIDED;
   }
   else
   {
      /* Execute the Auto-test */
      u8ReturnedAutoTestStatus = castATMConfig[cu8AutotestID].pfAutotestCallback();

      /* Manage the test result */
      switch (u8ReturnedAutoTestStatus)
      {
      case KU8_ATM_TEST_OK:
         /* Store the result */
         atm_au8AtStatuses[cu8AutotestID] = u8ReturnedAutoTestStatus;
         /* Update the associated Event status accordingly */
         Rte_Call_pclAecStatus_SetAecEvent(U8_GET_AEC_ID(cu8AutotestID), (u8AecCommandType)KU8_AEC_PASSED);
         break;

      case KU8_ATM_TEST_NOK:
         /* Store the result */
         atm_au8AtStatuses[cu8AutotestID] = u8ReturnedAutoTestStatus;
         /* Update the associated Event status accordingly */
         Rte_Call_pclAecStatus_SetAecEvent(U8_GET_AEC_ID(cu8AutotestID), (u8AecCommandType)KU8_AEC_FAILED);
         break;

      case KU8_ATM_TEST_NOT_DECIDED:
      case KU8_ATM_TEST_BAD_CONDITIONS:
         /* Result not determined: Do not notify ERH */
         /* Store the result */
         atm_au8AtStatuses[cu8AutotestID] = u8ReturnedAutoTestStatus;
         break;

      default:
         /* This is an auto-test fault (returned invalid result) : do nothing */
         break;
      } /* End switch */
   }
}

/**
* \brief
*     sub-function of ATM_runMainFunction to check if a test is enabled according to 2 criteria.
* - the presence of a no null call back function in the configuration
* - the NVP configuration
* If this last case, the AEC status is updated as if the test was passed!
* \param[in]
*     uint8 cu8AutotestID
* \exception
*     None.
* \pre
*     None.
* \post
*     None.
* \return
*     void
**/
/* [COVERS: DSG_ATM_0052;] */
LOCAL boolean atm_isAutoTestEnabled(const uint8 cu8AutotestID)
{
   /* To return the result */
   boolean bReturn;

   /* Check if an auto test callback is defined */
   if (KPF_NULL != castATMConfig[cu8AutotestID].pfAutotestCallback)
   {

      /* Check if the auto test is activated */
      if (B_TRUE == NVP_BLOCK_ID_ATM_ENABLE_PARAM_RamBlockData.NVP_au8AutoTestsActivation[cu8AutotestID])
      {
         /* The test is enabled */
         bReturn = B_TRUE;
      }
      else
      {
         /* Auto test is considered as successful in order to avoid to disturb the ECU functioning */
         atm_au8AtStatuses[cu8AutotestID] = KU8_ATM_TEST_OK;

         /* Notify DEM */
         /* The auto-test has succeeded, so notify "passed" */
         /* The first parameter is the ERG fault identifier */
         /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
         /* QAC warning due to comma operator into RTE macro */
         /* QAC_WARNING S 3426 3 */ /* Right hand side of comma expression has no side effect and its value is not used.*/
         /* QAC does not recognize RTE macros */
         /* Update the associated Event status accordingly */
         Rte_Call_pclAecStatus_SetAecEvent(U8_GET_AEC_ID(cu8AutotestID), (u8AecCommandType)KU8_AEC_PASSED);

         /* The test is disabled by the configuration */
         bReturn = B_FALSE;
      }
   }
   else
   {
      /* The test is disabled since the call back function is not defined */
      bReturn = B_FALSE;
   }
   return bReturn;
}

/**
* \brief
*     Startup auto test phase
*
* - Execute auto test only if enabled
* - If status = OK, then go to next startup auto test at next ATM Main time slot
* - For critical auto tests:
*    - If status = NOK and if ONE_SHOT_ABORT, then startup phase is frozeen
*    - If status = NOK and if ONE_SHOT_RETRY, then retry auto test execution
*                              until OK at next ATM Main time slot
* - For NOT critical auto tests:
*   - If status = NOK and if ONE_SHOT, then go to next startup auto test
*                             at next ATM Main time slot
* \param
*     void
* \exception
*     None.
* \pre
*     None.
* \post
*     None.
* \return
*     void
**/
LOCAL void atm_PlayOneShotTests(void)
{
   /* ID to execute in the current state */
   uint8 u8AutotestID;
   /* [COVERS: DSG_ATM_0001] */
   /* If start-up test sequence is in progress, go over the tests which are disabled */
   /* QAC_WARNING S 3415 2 */ /* Expression with possible side effects, but it needs to be evaluated inside while */
   while ((atm_u8StartupTestIndex < ATM_KU8_NB_OF_STARTUP_AUTO_TESTS) && (B_TRUE != atm_isAutoTestEnabled(castStartupSequentialList[atm_u8StartupTestIndex].u8TestIndex)))
   {
      /* Go over this disabled test */
      atm_u8StartupTestIndex++;
   }

   if (atm_u8StartupTestIndex < ATM_KU8_NB_OF_STARTUP_AUTO_TESTS)
   {
      /* The startup test sequence is still being in progress */
      if (KU16_ZERO == atm_u16StartupPeriodCnt)
      {
         /* Get the attributes of current startup sequence element */
         u8AutotestID = castStartupSequentialList[atm_u8StartupTestIndex].u8TestIndex;

         /* Execute the auto test function */
         atm_executeAutoTest(u8AutotestID);

         /* According to the result of the auto test */
         switch (atm_au8AtStatuses[u8AutotestID])
         {
         case KU8_ATM_TEST_OK:
            /* Go to next test only when successful result has been returned */
            atm_u8StartupTestIndex++;
            /* Do not respect any delay before the first step of the next autotest */
            atm_u16StartupPeriodCnt = (uint16) 0u;
            break;

         case KU8_ATM_TEST_NOK:
            if (KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_ABORT == castStartupSequentialList[atm_u8StartupTestIndex].u8Type)
            {
               /* Never retry this test after failure, and definitively freeze the start-up test sequence */
               atm_u16StartupPeriodCnt = KU16_MAX;
            }
            else if((KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT == castStartupSequentialList[atm_u8StartupTestIndex].u8Type)
                  || (KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_DECIDED == castStartupSequentialList[atm_u8StartupTestIndex].u8Type))
            {
               /* Test is played only once so Go to next test */
               atm_u8StartupTestIndex++;
               /* Do not respect any delay before the first step of the next autotest */
               atm_u16StartupPeriodCnt = (uint16) 0u;
            }
            else /* ONE_SHOT_RETRY */
            {
               /* Retry this test after failure + configured inter-step delay */
               atm_u16StartupPeriodCnt = U16_GET_STEP_PERIOD(atm_u8StartupTestIndex);
            }
            break;

         case KU8_ATM_TEST_BAD_CONDITIONS:
            if (KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT_DECIDED == castStartupSequentialList[atm_u8StartupTestIndex].u8Type)
            {
               /* Test is not retried any more so Go to next test */
               atm_u8StartupTestIndex++;
               /* Do not respect any delay before the first step of the next autotest */
               atm_u16StartupPeriodCnt = (uint16) 0u;
            }
            else if(KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT == castStartupSequentialList[atm_u8StartupTestIndex].u8Type)
            {
               /* Test is played only once so Go to next test */
               atm_u8StartupTestIndex++;
               /* Do not respect any delay before the first step of the next autotest */
               atm_u16StartupPeriodCnt = (uint16) 0u;
            }
            else /* ONE_SHOT_RETRY or ONE_SHORT_ABORT */
            {
               /* Retry this test after failure + configured inter-step delay */
               atm_u16StartupPeriodCnt = U16_GET_STEP_PERIOD(atm_u8StartupTestIndex);
            }
            break;

         default:  /* not decided */
            if (KU8_AUTO_TEST_CONFIG_TYPE_ONE_SHOT == castStartupSequentialList[atm_u8StartupTestIndex].u8Type)
            {
               /* Test is played only once so Go to next test */
               atm_u8StartupTestIndex++;
               /* Do not respect any delay before the first step of the next autotest */
               atm_u16StartupPeriodCnt = (uint16) 0u;
            }
            else
            {
               /* Reload the period counter (between steps of the same test) */
               atm_u16StartupPeriodCnt = U16_GET_STEP_PERIOD(atm_u8StartupTestIndex);
            }
            break;
         }
      }
      else if (KU16_MAX == atm_u16StartupPeriodCnt)
      {
         /* Do nothing as the start-up test sequence is definitively frozen since a "one shot" test result is NOK */
      }
      else
      {
         /* Count down the delay before the current test next step */
         atm_u16StartupPeriodCnt--;
      }
   }
   else
   {
      /* Do nothing as the startup test sequence is no more in progress */
   }

   /* Synchronization test: Wait for last task time slot to allow the cyclic execution of tests */
   if (    (atm_u8StartupTestIndex >= ATM_KU8_NB_OF_STARTUP_AUTO_TESTS)
         && ((KU16_CFG_MAX_TASK - KU16_ONE) == atm_u8CurrentTask))
   {
      /* Definitively allow the cyclic execution of tests for this function next execution */
      atm_u8StartupTestIndex++;
      /* Initialize index now used to browse the running cyclic task (no longer used to browse the startup cyclic task) */
      atm_u8CyclicTestIndex = 0u;
   }
   else
   {
      /* Do nothing as the startup sequence is not yet finished */
   }
}

/**
* \brief
*     Running Auto test phase
*
* - Execute auto test only if enabled
* - If status = OK, then go to next startup auto test at next ATM Main time slot
* - For critical auto tests:
*    - If status = NOK and if ONE_SHOT_ABORT, then startup phase is frozen
*    - If status = NOK and if ONE_SHOT_RETRY, then retry auto test execution
*                              until OK at next ATM Main time slot
* - For NOT critical auto tests:
*    - If status = NOK and if ONE_SHOT, then go to next startup auto test
*                              at next ATM Main time slot
* \param[in]
*      const stCyclicListEltType
* \param[in,out]
*      cpstCyclicList
*      \brief Pointer to the head of the cyclic list constant to play
* \exception
*     None.
* \pre
*     None.
* \post
*     None.
* \return
*     void
**/
LOCAL void atm_PlayCyclicTests(const stCyclicListEltType *const cpstCyclicList)
{
   /* ID to execute in the current state */
   uint8 u8AutotestID;
   /* [COVERS: DSG_ATM_0002] */
   /* After the start-up sequence: run only periodic tests according their time slot allocation: */
   /* Parse all tests, and executed the enabled ones which config match with current time slot */
   while (KU16_ZERO != (cpstCyclicList + atm_u8CyclicTestIndex)->u16Period)
   {
      /* Period and offset shall match to the current period counter */
      if ((uint16)((cpstCyclicList + atm_u8CyclicTestIndex)->u8Offset) == (atm_u16CurrentDecade % ((cpstCyclicList + atm_u8CyclicTestIndex)->u16Period)))
      {
         /* Get the attributes of current startup sequence element */
         u8AutotestID = (cpstCyclicList + atm_u8CyclicTestIndex)->u8TestIndex;

         /* Test if the execution is enabled */
         if (B_TRUE == atm_isAutoTestEnabled(u8AutotestID))
         {
            atm_executeAutoTest(u8AutotestID);
         }
         else
         {
            /* Do nothing as the auto test is disabled */
         }
      }
      else
      {
         /* This time slot does not correspond to the periodicity and offset of this auto test */
         /* So it is not the moment to run this auto test => Do nothing */
      }
      atm_u8CyclicTestIndex++;
   }
   /* Prepare indexes for next main function execution */
   if (KU8_ZERO == (cpstCyclicList + atm_u8CyclicTestIndex)->u8Offset)
   {
      /* Restart the whole list */
      atm_u8CyclicTestIndex = 0u;
      /* Consider next decade number */
      atm_u16CurrentDecade = (atm_u16CurrentDecade + (uint16)1u) % KU16_CFG_MAX_DECADE;
   }
   else
   {
      /* Continue with the following task sub-list */
      atm_u8CyclicTestIndex++;
   }
}

#define ATM_AC_AutoTestManager_STOP_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"
/**************************************************************************
}
Exported Functions
**************************************************************************/

#define ATM_AC_AutoTestManager_START_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"
/**
 * \brief
 *    The function ATM_AC_AutoTestManager_ATM_runInit is the memory initialization function for
 *    the ATM module.
 *     - The initialization value of the status of each auto test is  KU8_ATM_TEST_NOT_DECIDED.
 *     - The state and cycle counters of the state machine are initialized to 0
 * \param
 *     void
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     void
 **/
 void ATM_Init(void)
 {
    u8AutoTestIdType u8IdxAutotest;
    /* [COVERS: DSG_ATM_0003] */
    /* Initialization of all the tests statuses */
    for (u8IdxAutotest = (u8AutoTestIdType)0; u8IdxAutotest < (ATM_KU8_NB_OF_AUTOTEST); u8IdxAutotest++)
    {
       atm_au8AtStatuses [u8IdxAutotest] = KU8_ATM_TEST_NOT_DECIDED;
    }

    /* Used during ATM STARTUP phase */
    /* Initialization of indexes to browse lists of tests */
    atm_u8StartupTestIndex = KU8_ZERO;
    atm_u8CyclicTestIndex = KU8_ZERO;

    /* Initialization of the timer counters */
    atm_u16StartupPeriodCnt = KU16_ZERO;
    atm_u16CurrentDecade = KU16_ZERO;
    atm_u8CurrentTask = KU8_ZERO;

    /* Execute a specific function */
    Cfg_SpecificFunction_Init_ATM();
}

 /**
  * \brief
  *    Not used.
  * \param
  *     void
  * \exception
  *     None.
  * \pre
  *     None.
  * \post
  *     None.
  * \return
  *     void
  **/
 void ATM_Shutdown(void)
{
    /* Nothing to do for the moment */

    /* Execute a specific function */
    Cfg_SpecificFunction_Shutdown_ATM();
}

 /**
* \brief
*    The function ATM_MainFunction is the main entry point executed periodically by the Scheduler or OS.
* \param
*     void
* \exception
*     None.
* \pre
*     None.
* \post
*     None.
* \return
*     void
**/

/*               ATM Scheduler                  */

 void ATM_runMainFunction(void)
 {
    /* Execute a specific function */
    Cfg_SpecificFunction_StartMain_ATM();
    /* [COVERS: DSG_ATM_0005; DSG_ATM_0006; DSG_ATM_0007; DSG_ATM_0008; DSG_ATM_0009; DSG_ATM_0010; DSG_ATM_0011; DSG_ATM_0012; DSG_ATM_0013; DSG_ATM_0014 ] */
    /* [COVERS: DSG_ATM_0015; DSG_ATM_0016; DSG_ATM_0017; DSG_ATM_0018; DSG_ATM_0019; DSG_ATM_0020; DSG_ATM_0021; DSG_ATM_0022; DSG_ATM_0023; DSG_ATM_0024] */
    /* [COVERS: DSG_ATM_0025; DSG_ATM_0026; DSG_ATM_0027; DSG_ATM_0028; DSG_ATM_0029; DSG_ATM_0030; DSG_ATM_0031; DSG_ATM_0032; DSG_ATM_0033; DSG_ATM_0034; DSG_ATM_0035;] */
    /* [COVERS: DSG_ATM_0036; DSG_ATM_0037; DSG_ATM_0038; DSG_ATM_0039; DSG_ATM_0040; DSG_ATM_0041; DSG_ATM_0042; DSG_ATM_0043; DSG_ATM_0044; DSG_ATM_0045; DSG_ATM_0046 ] */
    /* Process separately the startup auto-tests sequence, and periodic test execution applicable only after the startup sequence */
    if (atm_u8StartupTestIndex < (ATM_KU8_NB_OF_STARTUP_AUTO_TESTS + 1u))
    {
       /* During ATM STARTUP phase:
        * Startup auto tests are sequentially executed one after one,
        * in the order defined by the startup list castStartupList,
        * until the ATM_KU8_NB_OF_STARTUP_AUTO_TESTS.
        * If a critical startup auto test is not successful,
        * the ATM STARTUP phase is suspended
        * => if ONE_SHOT_RETRY: this auto test is launched until successful result
        * => if ONE_SHOT_ABORT: this auto test is no more launched
        * Not critical (ONE_SHOT configured) auto test
        * do never freeze the ATM STARTUP phase, even if failed result. */
       /* [COVERS: DSG_ATM_0001] */
       /* ATM Cyclic Tests applicable in start-up phase are run in parallel */
       /* [COVERS: DSG_ATM_0047] */
       atm_PlayCyclicTests(castStartupCyclicList);
       /* Execution of a step from the ATM Startup sequence */
       atm_PlayOneShotTests();
    }
    else
    {
       /* [COVERS: DSG_ATM_0002] */
       /* Run cyclic tests which are applicable only if the Startup phase is finished */
       atm_PlayCyclicTests(castRunningCyclicList);
    }

    /* next time slot becomes current one (Loop cycle counter)
     * Note: Even if the start-up sequence do not use the 'atm_u8CurrentTask' variable, it is updated
     *       all the time from the start-up to remain synchronized with the schedule table. */
    atm_u8CurrentTask = (uint8) ((atm_u8CurrentTask + 1u) % (uint8)KU16_CFG_MAX_TASK);

    /* Execute a specific function */
    Cfg_SpecificFunction_EndMain_ATM();
 }

 /**
  * \brief
  *    The function ATM_runGetTestResult allows any module to get the test result of any auto test, identified by Auto test ID to get the last test
  *    result executed by ATM independently of AEC status ("live" status).
  * \param[in]
  *     uint8 u8AutoTestId
  *     /brief This variable is the identifier for the Autotest.
  * \param[in,out]
  *     uint8 u8TestResult
  *    /brief This variable is the reported status of the Autotest.
  *         This variable can have the values below :
  *         1 KU8_ATM_TEST_OK
  *         2 KU8_ATM_TEST_NOK
  *         4 KU8_ATM_TEST_NOT_DECIDED
  *         8 KU8_ATM_TEST_NON_EXISTENT
  *         Any other value is a fault case.
  * \exception
  *     None.
  * \pre
  *     None.
  * \post
  *     None.
  * \return
  *     void
 **/
/* The parameter 'u8AutoTestId' is never modified and so it could be declared with the 'const' qualifier. */
                    /* The parameter 'u8TestResult' is never modified and so it could be declared with the 'const' qualifier. */
                    /* These functions are auto-generated by System Desk wherein with it's not possible to insert the 'const' qualifier. */
 void ATM_runGetTestResult (u8AutoTestIdType u8AutoTestId, u8TestResultType *u8TestResult)
 {
    /* [COVERS: DSG_ATM_0004] */
    /* Check ID exists */
    if (ATM_KU8_NB_OF_AUTOTEST <= u8AutoTestId)
    {
       /* This is a fault case : Nonexistent ID passed as parameter */
       *u8TestResult = KU8_ATM_TEST_NON_EXISTENT;
    }
    else
    {
       /* Return the last test result (OK or NOK), or NOT_DECIDED if
        no result has been returned yet by the autotest */
       *u8TestResult = atm_au8AtStatuses[u8AutoTestId];
    }


 }

 /**
* \brief
*    The function aims at returning the last critical Autotest Id
* \param[in,out]
*     UInt8 u8AutoTestId
* \exception
*     None.
* \pre
*     None.
* \post
*     None.
* \return
*     void
 **/
 void ATM_runGetLastCriticalAutotestId (UInt8 *u8AutoTestId)
{
    *u8AutoTestId = castStartupSequentialList[ATM_KU8_NB_OF_STARTUP_AUTO_TESTS - KU8_ONE].u8TestIndex;
}

#define ATM_AC_AutoTestManager_STOP_SEC_CODE
#include "ATM_AC_AutoTestManager_MemMap.h"

/* QAC_WARNING S 3417 -- */
/* QAC_WARNING S 3426 -- */

/* end of file */
