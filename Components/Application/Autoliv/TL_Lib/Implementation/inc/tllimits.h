/******************************************************************************
*
* FILE:
*   tllimits.h         
*
* RELATED FILES:
*
* DESCRIPTION:
*   Implementation platform dependent limits definitions
*   for MPC5xx / Diab Compiler               
*   
*
* HISTORY:
*   2003/09/15  - Initial Revision
*                 (F. Lünstroth)
*   
* AUTHOR(S)
*   F. Lünstroth
*
* dSPACE GmbH, Technologiepark 25, 33100 Paderborn, Germany
*
* $Workfile: tllimits.h $ $Revision: 1.1.2.2 $ $Date: 2018/09/20 09:19:50CEST $ $Author: Andreea Negrea (andreea.negrea) $
******************************************************************************/

#ifndef __tllimits_h__
#define __tllimits_h__


#define BIG_ENDIAN
#define ALIGN 4
#define MCU_MPC5XX
#define COMP_DIAB


#define INT8MAX                 127
#define INT8MIN                 (-INT8MAX -1)
#define INT16MAX                32767
#define INT16MIN                (-INT16MAX -1)
#define INT32MAX                2147483647L
#define INT32MIN                (-INT32MAX -1L)

#define UINT8MAX                255
#define UINT8MIN                0
#define UINT16MAX               65535
#define UINT16MIN               0
#define UINT32MAX               4294967295L
#define UINT32MIN               0

#define FLOAT32MAX				3.40282347E+38F
#define FLOAT32MIN				-3.40282347E+38F
#define FLOAT64MAX				1.7976931348623157E+308
#define FLOAT64MIN				-1.7976931348623157E+308


#endif
