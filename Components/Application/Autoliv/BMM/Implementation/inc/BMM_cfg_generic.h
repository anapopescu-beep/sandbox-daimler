#ifndef I_BMM_CONFIG
#define I_BMM_CONFIG 1

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
   This file defines the configuration information in the package BMM

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.1.3.2.3 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/BMM/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *		The clock of timer used for BRS function in Hz.
 */
#define BMM_CFG_TIMER_INPUT_CLK                (80000000ul)

/**
 * \brief
 *		Defines the average belt bobbin perimeter in mm.
 */
#define BMM_S16_BOBBIN_PERIMETER_IN_MM_CFG     ((sint32)168)

/**
 * \brief
 *		Configuration parameter which defines the number of pairs of poles
 * 		present on the magnetic wheel.
 */
#define BMM_NB_PAIRS_OF_POLES_CFG              (18uL)

/**
 * \brief
 *		 Configuration of the period overflow threshold in milliseconds:
 * - If an hall A or hall B period exceed this value, the bobbin speed will be
 *   considered as null.
 *   This value set-up shall be determined regarding the acceptable response
 *   time of any algorithm which would need to use the bobbin speed information.
 *   This means that the accuracy of very low speed measures is not usable
 *   while it can requires many seconds to be evaluated, waiting for magnetic
 *   pole to go over hall sensors. *
 * - This parameter corresponds to the 16 bits timer's full range, which
 *   will be to tried to be approximated thru the timer's prescaler
 *   initialization (Scale optimization in accordance with expected relevant
 *   period measures)
 */
#define BMM_PERIOD_MAX_MS                      (1000uL*(360uL/BMM_NB_PAIRS_OF_POLES_CFG))

/**
 * \brief
 *		Macro to enable pyro detection feature.
 */
#define BMM_ENABLE_PYRO_DETECTION              1

/**
 * \brief
 *		Macro to enable lowest and highest positions detection feature.
 */
#define BMM_ENABLE_MAX_POS_MONITORING          1
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/
/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* I_BMM_CONFIG */
