/****************************************************************************************************************************************************\
 *** 
 *** Simulink model       : BFE_TestHarness
 *** TargetLink subsystem : BFE_TestHarness/BFE_AC_BeltFunctionExecution
 *** Codefile             : tl_aux_defines_a.h
 ***
 *** Generation date: 2018-04-17 16:15:09
 ***
 *** TargetLink version      : 4.2 from 14-Oct-2016
 *** Code generator version  : Build Id 4.2.0.26 from 2016-10-17 16:31:48

\****************************************************************************************************************************************************/

#ifndef TL_AUX_DEFINES_A_H
#define TL_AUX_DEFINES_A_H


#include "common.h"
#include "BFE_Config.h"

/* results from
   BFE_AC_BeltFunctionExecution/BFE_AC_BeltFunctionExecution/BFE_runExecuteHighPowerStep/HP feature activated/CurrentRegulation/Preprocessor IF */
#ifdef BFE_MIL_MBD

/* results from
   BFE_AC_BeltFunctionExecution/BFE_AC_BeltFunctionExecution/BFE_runExecuteHighPowerStep/Preprocessor IF */
#ifdef BFE_CFG_OPT_HIGH_POWER
#define Sa24_Switch_AUX_a
#endif
 
/* BFE_CFG_OPT_HIGH_POWER */
#endif
 
/* BFE_MIL_MBD */

/* results from
   BFE_AC_BeltFunctionExecution/BFE_AC_BeltFunctionExecution/BFE_runExecuteHighPowerStep/HP feature activated/CurrentRegulation/Preprocessor IF
   BFE_AC_BeltFunctionExecution/BFE_AC_BeltFunctionExecution/BFE_runExecuteHighPowerStep/Preprocessor IF */
#ifdef Sa24_Switch_AUX_a
#define Sa24_Switch_AUX
#endif
 
/* Sa24_Switch_AUX_a */

/* results from
   BFE_AC_BeltFunctionExecution/BFE_AC_BeltFunctionExecution/BFE_runExecuteHighPowerStep/Preprocessor IF */
#ifdef BFE_CFG_OPT_HIGH_POWER
#define Sa24_Switch_AUX
#endif
 
/* BFE_CFG_OPT_HIGH_POWER */
#endif /* TL_AUX_DEFINES_A_H */
/*------------------------------------------------------------------------------------------------------------------*\
  END OF FILE
\*------------------------------------------------------------------------------------------------------------------*/
