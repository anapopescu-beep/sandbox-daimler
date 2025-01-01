#define VHSM_ENTRY_POINT_SOURCE
 
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/ 
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

extern void brsStartupEntry(void);
extern  unsigned char   OsCfg_Stack_OsCore0_Init_Dyn[];
extern  unsigned char   OsCfg_Hal_Core_OsCore0_VectorTable[];
#define VTOR            (*(volatile unsigned int *)0xE000ED08)
#  pragma section "vHsmEntryPoint"
void __interrupt() __frame() vHsmEntryPoint( void )
{  
    __setsp( OsCfg_Stack_OsCore0_Init_Dyn );
    
    /* Set VTOR, in case an updater was used an vector table currently points somewhere else. */   
    VTOR = (unsigned int)OsCfg_Hal_Core_OsCore0_VectorTable;

    brsStartupEntry();

    return;
}
#  pragma endsection

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsmEntryPoint.c
 *********************************************************************************************************************/
