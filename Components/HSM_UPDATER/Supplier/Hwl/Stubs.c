#define STUBS_SOURCE
 
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/ 
#include "Std_Types.h"
#include "vstdlib.h"
#include "Os.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#  pragma section "vHsmRamCode"
#  pragma call far
Std_ReturnType Det_ReportError(
  uint16 ModuleId,
  uint8 InstanceId,
  uint8 ApiId,
  uint8 ErrorId)
{
  volatile boolean loop1=TRUE;
  while(loop1);
  return E_OK;
}
#  pragma call default
#  pragma endsection

FUNC(void, OS_VHSM_HAL_EXTERNALREQUESTISR_CODE) Os_Isr_vHsm_Hal_ExternalRequestIsr(void)
{
  
}

/**********************************************************************************************************************
 *  END OF FILE: main.c
 *********************************************************************************************************************/
