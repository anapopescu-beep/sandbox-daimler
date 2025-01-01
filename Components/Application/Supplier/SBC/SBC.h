
#ifndef SBC_H_
#define SBC_H_ 1

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
*******************************************************************************

Overview of the interfaces:
   SPI Interface between SBC and SPI

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*

*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SBC_cfg.h"


#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/* Definition of value reset cause in specific register */
/* SUP_STAT_1 */
#define KU8_STATUS_VS_UV               0x40 /* VS Under-Voltage */
#define KU8_STATUS_VCC1_OV             0x02 /* VCC1 Over-Voltage */
/* SUP_STAT_0 */
#define KU8_STATUS_POR                 0x80 /* Power on Reset */
#define KU8_STATUS_VCC2_OT             0x10 /* VCC2 Over Temperature */
#define KU8_STATUS_VCC2_UV             0x08 /* VCC2 Under-Voltage */
#define KU8_STATUS_VCC1_SC             0x04 /* VCC1 Short Circuit */
#define KU8_STATUS_VCC1_UV             0x01 /* VCC1 Under-Voltage */
/* THERM_STAT */
#define KU8_STATUS_TDS2_OT             0x04 /* Thermal shutdown detection 2 */
#define KU8_STATUS_TDS1_OT             0x02 /* Thermal shutdown detection 1 */

/* BUS_STAT*/
#define KU8_STATUS_CAN_FAIL            0x06 /* CAN fail status */
#define KU8_STATUS_VCAN_UV             0x01 /* Under-Voltage CAN bus supply */

/* DEV_STAT*/
#define KU8_STATUS_WD_FAIL_1x          0x40 /* 1xWatchdog Fail  */
#define KU8_STATUS_WD_FAIL             0x01 /* 1xWatchdog Fail  */

/* WK_STAT_0*/
#define KU8_STATUS_CAN_WU              0x20 /* Can wake up */


/* Mask for all individual status information provided by the SBC registers
 * Note: To be extended with any needed ones */

#define KU8_MASK_CAN_WU                       ((uint32) 0x10)
#define KU8_MASK_VS_UNDER_VOLTAGE             ((uint32) 0x08)
#define KU8_MASK_POWER_ON_RESET               ((uint32) 0x04)
#define KU8_MASK_VCC1_UNDER_VOLTAGE           ((uint32) 0x02)
#define KU8_MASK_WATCHDOG_FAILURE             ((uint32) 0x01)

#define KU8_REG_BUS_CTRL                      ((uint8)0x84)
#define KU8_NORMAL_MODE_CAN                   ((uint8)0x03)
#define KU8_WAKE_CAPABLE_CAN                  ((uint8)0x01)
#define KU8_SWK_CAPABLE_CAN                   ((uint8)0x05)
#define KU8_NORMAL_MODE_CAN_WITH_SWK          ((uint8)0x07)

#define KU8_REG_MODE_SUPPLY_CTRL              ((uint8)0x81)
#define KU8_NORMAL_MODE_SBC                   ((uint8)0x08)
#define KU8_SLEEP_MODE_SBC                    ((uint8)0x41)


/* Specific definition of SBC chip */
#define KU8_MAX_COUNTER_REFRESH_WD     0x03 /* Max counter to refresh external watchdog */

/* ================================================================================ */
/* =============   Selective Wake Status Registers Enumerations        ============ */
/* ================================================================================ */



/* --------------------------------  SWK_STAT  ------------------------------------ */

typedef enum
{
    SBC_SYNC_NOT_SYNCHRONOUS                = 0x00U,
    SBC_SYNC_VALID_FRAME_RECEIVED
};

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
void SBC_Init(void);
void SBC_MainFunction(void);
void SBC_Shutdown(void);
void SBC_runGetResetCauses(uint16 * u16ResetCauses);
void SBC_GetSBCStatusInformation(uint32 * u32StatusInformation);
void SBC_ForceExternalWatchdogReset(void);
void SBC_SpiConfigurationHwError_Notification(void);
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _TEMPLATE_H_ */
