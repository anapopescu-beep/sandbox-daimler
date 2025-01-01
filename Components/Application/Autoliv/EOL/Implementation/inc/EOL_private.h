/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the component EOL, part of the package <Package name>.
These are globally visible.
This file is intended to be included in a package header file;
all components should include the package header file instead of this file.

Current revision: $Revision: 1.1.1.2.2.2 $
Checked in:       $Date: 2023/01/05 12:09:56CET $

*************************************************************************/

#ifndef EOL_PRIVATE_H_
#define EOL_PRIVATE_H_

#include "Std_Types.h"

/*************************************************************************
Declaration of constants
*************************************************************************/
/* LEVEL OF FUNCTIONS */
/**
 * \brief
 * 		EOL comfort ID
 */
#define KU8_EOL_COMFORT_LEVEL                            ((uint8)0x00)
/**
 * \brief
 * 		EOL low force ID
 */
#define KU8_EOL_LOW_FORCE_LEVEL                          ((uint8)0x01)
/**
 * \brief
 * 		EOL high force ID
 */
#define KU8_EOL_HIGH_FORCE_LEVEL                         ((uint8)0x02)
/**
 * \brief
 * 		EOL max force ID
 */
#define KU8_EOL_MAX_FORCE_LEVEL                          ((uint8)0x03)
/**
 * \brief
 * 		EOL request ID
 */
#define KU8_EOL_REQUEST_COUNTER_LEVEL                    ((uint8)0x04)
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
Declaration of constant data
*************************************************************************/

/*************************************************************************
Declaration of functions
*************************************************************************/

#endif /* EOL_PRIVATE_H_ */

/*************************************************************************
Evolution of the component

Created by : Pierre-Olivier.Pilot

$Log: EOL_private.h  $
Revision 1.1.1.2.2.2 2023/01/05 12:09:56CET Stefan Dominte (stefan.dominte) 
Request counter added
Revision 1.1.1.2.2.1 2022/05/30 11:56:03EEST Stefan Dominte (stefan.dominte) 
New implementation for EOL counters
Revision 1.1.1.2 2017/02/24 10:47:56EET michael.pastor 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:18:14CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:26:20CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/EOL/Implementation/inc/project.pj
Revision 1.1 2016/10/05 18:26:20CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/EOL/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:02CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/EOL/Implementation/inc/project.pj
Revision 1.1 2016/09/20 09:48:06CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/EOL/Implementation/inc/inc.pj
Revision 1.3 2016/06/01 15:54:33CEST Maxime Bourdon (maxime.bourdon) 
DIA ASR 4 migration completion
Revision 1.2 2015/11/03 10:21:50CET Maxime Bourdon (mbourdon) 
RTE files inclusion clean up
Revision 1.1 2015/10/14 15:11:14CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/_EOL/inc/project.pj
Revision 1.1 2015/04/20 10:03:20CEST Pierre-Olivier Pilot (ppilot) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/_EOL/inc/project.pj
*************************************************************************/

/* end of file */

