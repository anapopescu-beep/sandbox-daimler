/*************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

**************************************************************************

This file defines the information (interfaces, definitions and data) provided
by the component <Component name>, part of the package <Package name>.
These are globally visible.  
This file is intended to be included in a package header file; 
all components should include the package header file instead of this file.

Current revision: $ $
Checked in:       $ $

*************************************************************************/

#ifndef I_MATH
#define I_MATH 1

#include "common.h"
#include "Std_Types.h"

/*************************************************************************
Declaration of constants
*************************************************************************/

/*************************************************************************
Declaration of variables
*************************************************************************/

/*************************************************************************
Declaration of macros
*************************************************************************/

/* Possible values for sizes of table's elements (stInterpolationParam_Type->u8TableTypes) */
#define KU8_X_TYPE_MSK              ((uint8)0x07)
#define KU8_X8                      ((uint8)0x00)
#define KU8_X16_BIndian             ((uint8)0x01)
#define KU8_X16_LIndian             ((uint8)0x02)
#define KU8_X32_BIndian             ((uint8)0x03)
#define KU8_X32_LIndian             ((uint8)0x04)

#define KU8_Y_TYPE_MSK              ((uint8)0x70)
#define KU8_Y8                      ((uint8)0x00)
#define KU8_Y16_BIndian             ((uint8)0x10)
#define KU8_Y16_LIndian             ((uint8)0x20)
#define KU8_Y32_BIndian             ((uint8)0x30)
#define KU8_Y32_LIndian             ((uint8)0x40)
#define KU8_Y32_TypeRShift          ((uint8)4)

#define KU8_XY_TYPE_MASK_NB_VAL     ((uint8)8)

/* Option flags access macros (stInterpolationParam_Type->u8Flags) */
#define KU8_IN_RANGE_MNGT_MSK       ((uint8)0x03)
#define KU8_IN_RANGE_LINEAR_INTER   ((uint8)0x00)
#define KU8_IN_RANGE_LOWER_INTER    ((uint8)0x01)
#define KU8_IN_RANGE_UPPER_INTER    ((uint8)0x02)

#define KU8_BELOW_RANGE_UPPER_INTER ((uint8)0x04)

#define KU8_OVER_RANGE_LOWER_INTER  ((uint8)0x08)

/*************************************************************************
Declaration of types
*************************************************************************/
typedef struct
{
   const uint8 *pu8X;
   const uint8 *pu8Y;
   uint8 u8NbPos;
   uint8 u8TableTypes;
   uint8 u8Flags;
} stInterpolationParam_Type;

/*************************************************************************
Declaration of variables
*************************************************************************/

/*************************************************************************
Declaration of constant data
*************************************************************************/

/*************************************************************************
Declaration of functions
*************************************************************************/
extern uint32 u32InterpolateFromTable(const uint32 u32XI, const stInterpolationParam_Type * const pstParam);

#endif   /* I_MATH */

/*************************************************************************
Evolution of the component

Created by :

$Log: Math.h  $
Revision 1.1 2021/09/27 13:20:53CEST Septimiu Vintila (septimiu.vintila) 
Initial revision
Member added to project e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Supplier/_Common/project.pj
Revision 1.1.1.2 2017/02/24 10:52:37EET michael.pastor 
MAJ PP4G R3.1E from Explo since 15/02/2017
Revision 1.1.1.1 2017/02/15 17:21:54CET Michael Pastor (michael.pastor) 
Check In modified already present files
Revision 1.1 2016/10/05 18:28:46CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Extended/PP4G_R31E/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/10/05 18:28:46CEST Maxime Bourdon (maxime.bourdon) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/PP4G_Extended/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/10/05 10:13:37CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_02/Core/Components/Application/TL_Lib/Implementation/inc/project.pj
Revision 1.1 2016/09/20 09:48:12CEST Michael Pastor (michael.pastor) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/Automation/PropagationProject_R3.0M/PP4G/Platform_Mainstream_Phase_01/Core/Components/Application/TL_Lib/Implementation/inc/inc.pj
Revision 1.3 2015/11/03 11:39:22CET Maxime Bourdon (maxime.bourdon) 
Add Std_types.h inclusion
Revision 1.2 2015/11/03 11:37:53CET Maxime Bourdon (mbourdon) 
RTE inclusion files clean up
Revision 1.1 2015/10/13 15:53:02CEST Cedric Sauvage (csauvage) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Exploration/AUTOSAR/RTE_Benchmark/ETAS/Development_View/Source/Application/OPT_GENERIC/inc/project.pj
Revision 1.1 2014/10/23 11:13:15CEST Sebastien Claveau (sclaveau) 
Initial revision
Member added to project e:/MKSProjects/err_generic/Platform/ECU_PP_4G/Mainstream/Phase_01/Development_View/Source/Application/OPT_GENERIC/inc/project.pj

*************************************************************************/

/* end of file */
