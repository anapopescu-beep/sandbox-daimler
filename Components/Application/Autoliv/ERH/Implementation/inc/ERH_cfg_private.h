/*************************************************************************

*************************************************************************/

#ifndef ERH_PRIVATE_CFG
#define ERH_PRIVATE_CFG 1

#include "Std_Types.h"

/*************************************************************************
 Other components external interface inclusion **
*************************************************************************/

/*************************************************************************
 Declaration of types
*************************************************************************/

/*************************************************************************
 Declaration of macros
*************************************************************************/
 
/*************************************************************************
 Declaration of constants
*************************************************************************/
/**
 * \brief
 *      Struct used for AECs configuration
 */
typedef struct
{
   uint16 u16AECDeskillThrs;           /* To store the AEC deskill threshold */
   uint16 u16AECQualificationThrs;     /* To store the AEC qualification threshold */
   uint8 u8AECGroup;                   /* To store the AEC group (HW, battery, motor etc.) */
   uint8 u8ReservedByte1;              /* Reserved Byte for future update */
   uint8 u8ReservedByte2;              /* Reserved Byte for future update */
   uint8 u8ReservedByte3;              /* Reserved Byte for future update */
} erh_stAECConfigurationType;

/*************************************************************************
 Declaration of constants
*************************************************************************/

/*************************************************************************
 Exported function prototypes
*************************************************************************/

#endif   /* I_ERH_CONFIG */

/*************************************************************************

*************************************************************************/

/* end of file */
