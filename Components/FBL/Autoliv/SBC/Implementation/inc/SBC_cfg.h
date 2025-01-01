
#ifndef SPIF_CFG_H_
#define SPIF_CFG_H_ 1

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
*******************************************************************************

Overview of the interfaces:
   Spi Interface configuration

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
#include "spi.h"
#include "common.h"
#include "Dio.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/* Use to measure initialization time */
/* #define DEBUG_MODE_INIT_TIME_SPI_IF */
/* Use to measure the refresh external watchdog time */
/* Use to detect SBC errors */
/* #define DEBUG_MODE_SBC_ERRORS_SPI_IF */
/* address of configuration registers */
#define KU8_REG_M_S_CTRL                          0x01   /* 000 0001 = M_S_CTRL register */
#define KU8_REG_HW_CTRL_0                         0x02   /* 000 0010 = HW_CTRL_0 register */
#define KU8_REG_BUS_CTRL_0                        0x04   /* 000 0100 = BUS_CTRL_0 register */
#define KU8_REG_WK_CTRL_0                         0x06   /* 000 0110 = WK_CTRL_0 register */
#define KU8_REG_WK_CTRL_1                         0x07   /* 000 0111 = WK_CTRL_1 register */
#define KU8_REG_TIMER_CTRL                        0x0C   /* 000 1100 = TIMER_CTRL register */
#define KU8_REG_HW_CTRL_1                         0x0E   /* 000 1110 = HW_CTRL_1 register */
#define KU8_REG_HW_CTRL_2                         0x0F   /* 000 1111 = HW_CTRL_2 register */
#define KU8_REG_GPIO_CTRL                         0x17   /* 001 0111 = GPIO_CTRL register */
#define KU8_REG_PWM_CTRL                          0x18   /* 001 1000 = PWM_CTRM register */
/* Address of state registers */                    
#define KU8_REG_SUP_STAT_1                        0x40   /* 100 0000 = SUP_STAT_1 register */
#define KU8_REG_SUP_STAT_0                        0x41   /* 100 0001 = SUP_STAT_0 register */
#define KU8_REG_THERMAL_STAT                      0x42   /* 100 0010 = THERMAL_STAT register */
#define KU8_REG_DEV_STAT                          0x43   /* 100 0011 = DEV_STAT register */
#define KU8_REG_BUS_STAT                          0x44   /* 100 0100 = BUS_STAT register */
#define KU8_REG_WK_STAT_0                         0x46   /* 100 0110 = WK_STAT_0 register */
#define KU8_REG_WK_STAT_1                         0x47   /* 100 0111 = WK_STAT_1 register */
#define KU8_REG_GPIOOC_STAT                       0x54   /* 101 0100 = GPIO_OC_STAT register */
#define KU8_REG_GPIOOL_STAT                       0x55   /* 101 0101 = GPIO_OL_STAT register */
#define KU8_REG_FAM_PROD_STAT                     0x7E   /* 111 1110 = FAM_PROD_STAT register */
/* Configuration data by SBC register */
#define KU16_CONF_INIT_HW_CTRL_1_REG              0x0010  /* 0000 0000b */
#define KU16_CONF_INIT_HW_CTRL_2_REG              0x0000  /* 0000 0000b */
#define KU16_CONF_INIT_HW_CTRL_0_REG              0x0040  /* 0100 0001b */
#define KU16_CONF_INIT_WK_CTRL_0_REG              0x0004  /* 0000 0100b */
#define KU16_CONF_INIT_WK_CTRL_1_REG              0x0000  /* 0000 0000b */
#define KU16_CONF_INIT_TIMER_CTRL_REG             0x0000  /* 0000 0000b */
#define KU16_CONF_INIT_PWM_CTRL_REG               0x0000  /* 0000 0000b */
#define KU16_CONF_INIT_GPIO_CTRL_REG              0x0004  /* 0000 0100b */
/* Change values of control registers */
#define KU16_SET_CAN_BUS_CTRL_NORMAL_REG          0x0003   /* 0000 0011b */
#define KU16_SET_CAN_BUS_CTRL_WAKABLE_REG         0x0001   /* 0000 0001b */
#define KU16_CONF_SET_MODE_CTRL_NORMAL_REG        0x0008   /* 0000 1000b */
#define KU16_CONF_SET_MODE_CTRL_SLEEP_REG         0x0041   /* 0100 0001b */
#define KU16_DEFAULT                              0x0000   /* 0000 0000b */
/* Selective Wake Control Registers */
#define KU8_REG_SWK_CTRL                          0x20     /* 0010 0000b */
#define KU8_REG_SWK_BTL0_CTRL                     0x21     /* 0010 0001b */
#define KU8_REG_SWK_BTL1_CTRL                     0x22     /* 0010 0010b */
#define KU8_REG_SWK_ID3_CTRL                      0x23     /* 0010 0011b */
#define KU8_REG_SWK_ID2_CTRL                      0x24     /* 0010 0100b */
#define KU8_REG_SWK_ID1_CTRL                      0x25     /* 0010 0101b */
#define KU8_REG_SWK_ID0_CTRL                      0x26     /* 0010 0110b */
#define KU8_REG_SWK_MASK_ID3_CTRL                 0x27     /* 0010 0111b */
#define KU8_REG_SWK_MASK_ID2_CTRL                 0x28     /* 0010 1000b */
#define KU8_REG_SWK_MASK_ID1_CTRL                 0x29     /* 0010 1001b */
#define KU8_REG_SWK_MASK_ID0_CTRL                 0x2A     /* 0010 1010b */
#define KU8_REG_SWK_DLC_CTRL                      0x2B     /* 0010 1011b */
#define KU8_REG_SWK_DATA7_CTRL                    0x2C     /* 0010 1100b */
#define KU8_REG_SWK_DATA6_CTRL                    0x2D     /* 0010 1101b */
#define KU8_REG_SWK_DATA5_CTRL                    0x2E     /* 0010 1110b */
#define KU8_REG_SWK_DATA4_CTRL                    0x2F     /* 0010 1111b */
#define KU8_REG_SWK_DATA3_CTRL                    0x30     /* 0011 0000b */
#define KU8_REG_SWK_DATA2_CTRL                    0x31     /* 0011 0001b */
#define KU8_REG_SWK_DATA1_CTRL                    0x32     /* 0011 0010b */
#define KU8_REG_SWK_DATA0_CTRL                    0x33     /* 0011 0011b */
#define KU8_REG_SWK_CAN_FD_CTRL                   0x34     /* 0011 0100b */
#define KU8_REG_SWK_OSC_TRIM_CTRL                 0x38     /* 0011 1000b */
#define KU8_REG_SWK_OPT_CTRL                      0x39     /* 0011 1001b */
#define KU8_REG_SWK_OSC_CAL_H_STAT                0x3A     /* 0011 1010b */
#define KU8_REG_SWK_OSC_CAL_L_STAT                0x3B     /* 0011 1011b */
#define KU8_REG_SWK_CDR_CTRL1                     0x3C     /* 0011 1100b */
#define KU8_REG_SWK_CDR_CTRL2                     0x3D     /* 0011 1101b */
#define KU8_REG_SWK_CDR_LIMIT_HIGH_CTRL           0x3E     /* 0011 1110b */
#define KU8_REG_SWK_CDR_LIMIT_LOW_CTRL            0x3F     /* 0011 1111b */
/* Read command register */
#define KU8_READ_CMD_REG                          0x00
/* Write command register */
#define KU8_WRITE_CMD_REG                         0x01
/* Read only command register */
#define KU8_RO_CMD_REG                            0x00
/* Read & clear command register */  
#define KU8_RC_CMD_REG                            0x01
/* Definition of Switch bits */
#define KU8_ADDRESS_FIELD                         KU8_POS_LOW_BYTE /* Switch to address */
#define KU8_DATA_FIELD                            KU8_POS_HIGH_BYTE /* Switch to data */
#define KU8_TYPE_CMD_FIELD                        KU8_BIT_7 /* Switch to type command */
#define KU8_MASK_ADDR_REGISTER                    0x7F /* Mask of address filter register */
#define KU8_NO_RESET_CAUSE                        0x00 /* No cause reset */


/********************************************************************************
If common.h do not contain the specific defines
********************************************************************************/
#define KU8_POS_LOW_BYTE                            ((uint8) 0)
#define KU8_POS_HIGH_BYTE                           ((uint8) 8)
#define KU16_MASK_BYTE_LOW                          ((uint16) 0x00FF)
#define KU16_MASK_BYTE_HIGH                         ((uint16) 0xFF00)
#define U16_GET_LOW_BYTE(_word)                     ((uint8)(((_word) & KU16_MASK_BYTE_LOW ) >> KU8_POS_LOW_BYTE ))
#define U16_GET_HIGH_BYTE(_word)                    ((uint8)(((_word) & KU16_MASK_BYTE_HIGH) >> KU8_POS_HIGH_BYTE))
#define U16_BIT_SET(reg, mask)                      ((reg) |= (mask))
#define U16_BIT_CLEAR(reg, mask)                    ((reg) &= ((mask)^((uint16)0xFFFF)))
#define KU8_BIT_0                                   ((uint8) 0)
#define KU8_BIT_1                                   ((uint8) 1)
#define KU8_BIT_2                                   ((uint8) 2)
#define KU8_BIT_3                                   ((uint8) 3)
#define KU8_BIT_4                                   ((uint8) 4)
#define KU8_BIT_5                                   ((uint8) 5)
#define KU8_BIT_6                                   ((uint8) 6)
#define KU8_BIT_7                                   ((uint8) 7)
#define KU8_BIT_8                                   ((uint8) 8)
#define KU8_BIT_9                                   ((uint8) 9)
#define KU8_BIT_10                                  ((uint8) 10)
#define KU8_BIT_11                                  ((uint8) 11)
#define KU8_BIT_12                                  ((uint8) 12)
#define KU8_BIT_13                                  ((uint8) 13)
#define KU8_BIT_14                                  ((uint8) 14)
#define KU8_BIT_15                                  ((uint8) 15)
#define KU8_BIT_16                                  ((uint8) 16)

/* Masks for all registers represented in the Status Information Field  */
#define KU8_MASK_GPIO_OL                      ((uint8) 0x80) /* KU8_MASK_BIT_7 */
#define KU8_MASK_GPIO_OC                      ((uint8) 0x40) /* KU8_MASK_BIT_6 */
#define KU8_MASK_SUP_STAT_1                   ((uint8) 0x20) /* KU8_MASK_BIT_5 */
#define KU8_MASK_WK_STAT                      ((uint8) 0x10) /* KU8_MASK_BIT_4 */
#define KU8_MASK_BUS_STAT                     ((uint8) 0x08) /* KU8_MASK_BIT_3 */
#define KU8_MASK_DEV_STAT                     ((uint8) 0x04) /* KU8_MASK_BIT_2 */
#define KU8_MASK_THERM_STAT                   ((uint8) 0x02) /* KU8_MASK_BIT_1 */
#define KU8_MASK_SUP_STAT_0                   ((uint8) 0x01) /* KU8_MASK_BIT_0 */

/* IDs for all registers represented in the Status Information Field  */
#define KU8_ID_GPIO_OL                      ((uint8) 1)
#define KU8_ID_GPIO_OC                      ((uint8) 2)
#define KU8_ID_SUP_STAT_1                   ((uint8) 3)
#define KU8_ID_WK_STAT_0_ID                 ((uint8) 4)
#define KU8_ID_WK_STAT_1_ID                 ((uint8) 5)
#define KU8_ID_BUS_STAT                     ((uint8) 6)
#define KU8_ID_DEV_STAT                     ((uint8) 7)
#define KU8_ID_THERM_STAT                   ((uint8) 8)
#define KU8_ID_SUP_STAT_0                   ((uint8) 9)

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

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
/* Macros for Read/Write/Refresh ext WD/Shutdown SBC command */
#define SBC_INIT_WRITE_SPI_DATA(command)             (void)Spi_WriteIB(SpiConf_SpiChannel_SpiChannel_WDG , command);\
                                                     (void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_WDG_REFRESH)

#define SBC_INIT_READ_SPI_ANSWER(command,response)   (void)Spi_WriteIB(SpiConf_SpiChannel_SpiChannel_WDG , command);\
                                                     (void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_WDG_REFRESH);\
                                                     (void)Spi_ReadIB(SpiConf_SpiChannel_SpiChannel_WDG , response)
                                                               
#define SBC_REFRESH_WDG_REQUEST(command)             (void)Spi_WriteIB(SpiConf_SpiChannel_SpiChannel_WDG, command);\
                                                     (void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_WDG_REFRESH)

#define SBC_SHUTDOWN_WRITE_SPI_DATA(command)         (void)Spi_WriteIB(SpiConf_SpiChannel_SpiChannel_WDG , command);\
                                                     (void)Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_WDG_REFRESH)
/* Macro to make SBC commands */
#define SPI_IF_MAKE_SBC_COMMAND(Addr, CmdType, Data) {((Addr << KU8_ADDRESS_FIELD)|(CmdType<<KU8_TYPE_CMD_FIELD)) , (Data << KU8_DATA_FIELD)}

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _TEMPLATE_H_ */
