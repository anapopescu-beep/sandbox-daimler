/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the module PAL.

These are globally visible.

Current revision: $Revision: 1.1.2.3 $
Checked in:       $Date: 2022/02/15 11:33:58CET $

*************************************************************************/
#ifndef PAL_V2_INC_PAL_PUBLIC_H_
#define PAL_V2_INC_PAL_PUBLIC_H_


/************************************************************************
Inclusions
*************************************************************************/
#include "common.h"
#include "Std_Types.h"

/************************************************************************
Declaration of constants
*************************************************************************/


/*************************************************************************
Declaration of macros
*************************************************************************/

/*************************************************************************
Declaration of types
*************************************************************************/

/*************************************************************************
Declaration of variables
*************************************************************************/

/*************************************************************************
Declaration of functions
*************************************************************************/
#define PAL_AC_PowerAbstractionLayer_START_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

#define PAL_AC_PowerAbstractionLayer_STOP_SEC_CODE
#include "PAL_AC_PowerAbstractionLayer_MemMap.h"

#endif /* PAL_V2_INC_PAL_PUBLIC_H_ */

/*************************************************************************
Evolution of the component

Created by : sabine.flechelle

$Log: PAL_public.h  $
Revision 1.1.2.3 2022/02/15 11:33:58CET Septimiu Vintila (septimiu.vintila) 
Fixes after review.
Revision 1.1.2.2 2021/12/24 10:29:05EET Septimiu Vintila (septimiu.vintila) 
Initial revision
Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/PAL/Implementation/inc/project.pj
Revision 1.1.1.3 2019/08/19 14:13:24EEST Hamza Zetti (hamza.zetti) 
Correcting warnings
Revision 1.1.1.2 2017/02/24 09:50:17CET michael.pastor 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:20:01CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:27:18CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/10/05 18:27:18CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:17CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/PAL/Implementation/inc/project.pj
Revision 1.1 2016/09/20 09:48:08CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/PAL/Implementation/inc/inc.pj
Revision 1.1 2016/09/19 14:53:05CEST Sabine Flechelle (sabine.flechelle) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_PAL/inc/project.pj

*************************************************************************/

/* end of file */
