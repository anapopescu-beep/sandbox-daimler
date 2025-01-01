
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.2 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Supplier/PwmIf/project.pj $
*/
/* PRQA S 0288 -- */
/*!****************************************************************************

@details
   <Describes details of this module 'Template.c' file within overall
    context of component implementation>

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"

#include "Rte_PwmIf_Type.h"
#include "Rte_PwmIf.h"
#include "PwmIf.H"

#include "Pwm_17_GtmCcu6.h"
#include "Pwm_17_GtmCcu6_Cfg.h"

#include "Port.h"
#include "Port_Cfg.h"

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

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

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

#define PwmIf_START_SEC_CODE
#include "PwmIf_MemMap.h"

/*!****************************************************************************
* @details
*     Call Pwm service to update duty cycle for requested channel
* @param[in]
*     u8TargetChannel: The target�s channel among configured ones at Pwm level.
* @param[in]
*     u16DutyCycle: The PWM duty cycle order from zero to 0x8000 (for 100%).
* @return
*     none
* @constraints
*     none
* @invocation_criteria
*     none
******************************************************************************/
void PwmIf_SetDutyCycle(u8PwmChannelIdType cu8TargetChannel, UInt16 cu16DutyCycle)
{
   /* Call Pwm_SetDutyCycle API without any rework of parameters (processing is performed by Pwm MCAL module */
   Pwm_17_GtmCcu6_SetDutyCycle(cu8TargetChannel, cu16DutyCycle);
}

/*!****************************************************************************
* @details
*     Enable PWM
* @param[in]
*     cu8TargetChannel: The target�s channel among configured ones at Pwm level.
* @return
*     none
* @constraints
*     none
* @invocation_criteria
*     none
******************************************************************************/
void PwmIf_EnablePWM(u8PwmChannelIdType cu8TargetChannel)
{
   /* Test the target channel where the order shall be applied */
   switch (cu8TargetChannel)
   {
      case PWM_KU8_CH_ID_HB_P:
      Port_SetPinMode(PortConf_PortContainer_2_PORT_2_PIN_4, PORT_PIN_MODE_ALT7);
      break;

      case PWM_KU8_CH_ID_HB_N:
      Port_SetPinMode(PortConf_PortContainer_2_PORT_2_PIN_8, PORT_PIN_MODE_ALT1);
      break;

      default:
      /* This is an expected value of cu8TargetChannel argument. */
      /* The safest choice is to ignore this command */
      break;
   }
}

/*!****************************************************************************
* @details
*     Disable PWM
* @param[in]
*     cu8TargetChannel: The target�s channel among configured ones at Pwm level.
* @return
*     none
* @constraints
*     none
* @invocation_criteria
*     none
******************************************************************************/
void PwmIf_DisablePWM(u8PwmChannelIdType cu8TargetChannel)
{
   /* Test the target channel where the order shall be applied */
   switch (cu8TargetChannel)
   {
      case PWM_KU8_CH_ID_HB_P:
      Port_SetPinMode(PortConf_PortContainer_2_PORT_2_PIN_4, PORT_PIN_MODE_GPIO);
      break;

      case PWM_KU8_CH_ID_HB_N:
      Port_SetPinMode(PortConf_PortContainer_2_PORT_2_PIN_8, PORT_PIN_MODE_GPIO);
      break;

      default:
      /* This is an expected value of cu8TargetChannel argument. */
      /* The safest choice is to ignore this command */
      break;
   }
}

#define PwmIf_STOP_SEC_CODE
#include "PwmIf_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/
