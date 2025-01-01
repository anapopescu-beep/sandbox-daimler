
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*

*/
/* PRQA S 0288 -- */
/*!****************************************************************************

@details
   SPI Interface betwwen SBC and SPI components, module is in charge of:
   - initialise the SBC components
   - refresh the watchdog and diagnose the HW components
   - de-initialise the HW component

******************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "SBC.h"
#include "Rte_SBC.h"
#include "Os.h"
#include "EcuM.h"
#include "BswM.h"
#include "Dem.h"
/******************************************************************************
MODULE DEFINES
******************************************************************************/
/* SPI command length : 2 Bytes */
#define KU8_SPI_DRV_COMMAND_LENGTH ((uint8)2)
#define KU8_SPI_BUFFER_IDX_DATA ((uint8)0)
/* SPI buffer indexes */
#define KU8_SPI_BUFFER_IDX_ADDR ((uint8)1)
/* NM CAN ID */
#define KU8_SBC_IDE_EXTENDED           0x01
#define KU32_CTRL_SWK_IDx_CTRL         0x14420FFF
#define KU32_CTRL_SWK_MASK_IDx_CTRL    0x1FFFF000
#define KU32_CTRL_SWK_DATA_H_CTRL      0xFFFFFFFF
#define KU32_CTRL_SWK_DATA_L_CTRL      0xFFFFFFFF

#define SBC_Write_Bit                  0x80

/* SWK STAT */
#define SBC_SWK_STAT_SYNC_POS          0x06U
#define SBC_SWK_STAT_SYNC_MSK          0x01U

/* SUP STAT 0 */
#define SBC_SUP_STAT_0_POR_POS         0x07U
#define SBC_SUP_STAT_0_POR_MSK         0x01U
#define SBC_SUP_STAT_0_POR_Detected    0x01U
/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/
LOCAL void SBC_ClearStateAndReport(uint8 u8Response[KU8_SPI_DRV_COMMAND_LENGTH]);
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define SBC_START_SEC_VAR_INIT_16
#include "SBC_MemMap.h"
LOCAL const uint16 u16StatusSBC = KU16_ZERO;      /* SBC status : check errors */
LOCAL uint32 u32StatusInformationSBC = KU32_ZERO; /* SBC status information */
#define SBC_STOP_SEC_VAR_INIT_16
#include "SBC_MemMap.h"

#define SBC_START_SEC_VAR_INIT_8
#include "SBC_MemMap.h"
LOCAL uint8 u8CounterBaseRefreshWD = KU8_ZERO;                                /* SBC watchdog software Counter */
LOCAL uint8 u8SPIResponse[KU8_SPI_DRV_COMMAND_LENGTH] = {KU8_ZERO, KU8_ZERO}; /* SBC Response for all commands */
LOCAL uint8 u8BusCtrl0Register[KU8_SPI_DRV_COMMAND_LENGTH] = {KU8_ZERO, KU8_ZERO};
LOCAL uint8 u8MSCtrlRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {KU8_ZERO, KU8_ZERO}; /* Configure mode control register */
LOCAL uint8 u8SWKRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {KU8_ZERO, KU8_ZERO};    /* SWK Register */
LOCAL uint8 u8SPILocalResponse[KU8_SPI_DRV_COMMAND_LENGTH] = {KU8_ZERO, KU8_ZERO};

#define SBC_STOP_SEC_VAR_INIT_8
#include "SBC_MemMap.h"
/******************************************************************************
DEFINITION OF GLOBAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
#define SBC_START_SEC_CONST_16
#include "SBC_MemMap.h"
LOCAL const uint8 cu8HwCtrl0Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0x82, (uint8)0x41};                             //0x4082
LOCAL const uint8 cu8HwCtrl1Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0x8E, (uint8)0x00};                             //0x008E
LOCAL const uint8 cu8HwCtrl2Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0x8F, (uint8)0x00};                             //0x008F
/* LOCAL const uint8 cu8GPIOCtrlRegister[KU8_SPI_DRV_COMMAND_LENGTH]    = { (uint8)0x97, (uint8)0x04 }; QAC: Never used */ //0x0497
LOCAL const uint8 cu8WKCtrl0Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0x86, (uint8)0x00};                             //0x0086
LOCAL const uint8 cu8WKCtrl1Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0x87, (uint8)0x00};                             //0x0087
LOCAL const uint8 cu8TimerCtrlRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0x8C, (uint8)0x00};                           //0x008C
LOCAL const uint8 cu8PwmCtrlRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0x98, (uint8)0x00};                             //0x0098
LOCAL const uint8 cu8WdgRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0x83, (uint8)0x55};                                 //0x5583 -- wdg timer period: 500ms
LOCAL const uint8 cu8SwkCtrlRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xA0, (uint8)0x01};
/* Command constant to read and clear state registers */
LOCAL const uint8 cu8SupStat1Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xC0, (uint8)0x00};     //0x00C0;
LOCAL const uint8 cu8SupStat0Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xC1, (uint8)0x00};     //0x00C1;
LOCAL const uint8 cu8ThermalStatRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xC2, (uint8)0x00};  //0x00C2;
LOCAL const uint8 cu8DevStatRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xC3, (uint8)0x00};      //0x00C3;
LOCAL const uint8 cu8BusStatRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xC4, (uint8)0x00};      //0x00C4;
LOCAL const uint8 cu8WakeStat0Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xC6, (uint8)0x00};    //0x00C6;
LOCAL const uint8 cu8WakeStat1Register[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xC7, (uint8)0x00};    //0x00C7;
LOCAL const uint8 cu8GpioOcStatRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xD4, (uint8)0x00};   //0x00D4;
LOCAL const uint8 cu8GpioOlStatRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xD5, (uint8)0x00};   //0x00D5;
LOCAL const uint8 cu8FamProdStateRegister[KU8_SPI_DRV_COMMAND_LENGTH] = {(uint8)0xFE, (uint8)0x00}; //0x00FE;
/* Used for SPI autotest result */
LOCAL u8TestResultType u8ResultOfAutoTest;
#define SBC_STOP_SEC_CONST_16
#include "SBC_MemMap.h"

/******************************************************************************
DEFINITION OF GLOBAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
#define SBC_START_SEC_CODE
#include "SBC_MemMap.h"
/**************************************************************************
 Label: LOCAL void SBC_DetermineSBCErrors(uint8 u8Register,uint8 u8StatusRegister)
 Object: Determine and Check errors of SBC chip
 Parameters: none
 Return: none
**************************************************************************/

LOCAL void SBC_DetermineSBCErrors(const uint8 u8Register, const uint8 u8StatusRegister)
{

   /* Changes in one particular register were signaled so we need to extract the new information */
   switch (u8Register)
   {
   case (KU8_ID_GPIO_OL):
   {
      /* Register fields information currently not needed */
      break;
   }
   case (KU8_ID_GPIO_OC):
   {
      /* Register fields information currently not needed */
      break;
   }
   case (KU8_ID_SUP_STAT_1):
   {
      /* Extract VS under voltage detection status */
      if (((uint8)KU8_STATUS_VS_UV) == (u8StatusRegister & ((uint8)KU8_STATUS_VS_UV)))
      {
         /* VS under voltage detected */
         u32StatusInformationSBC |= KU8_MASK_VS_UNDER_VOLTAGE;
      }
      else
      {
         /* No VS under voltage detected */
      }
      break;
   }
   case (KU8_ID_WK_STAT_0_ID):
   {
      /* Can wake up detected */
      if (((uint8)KU8_STATUS_CAN_WU) == (u8StatusRegister & ((uint8)KU8_STATUS_CAN_WU)))
      {
         u32StatusInformationSBC |= KU8_MASK_CAN_WU;
      }
      else
      {
         /* No Can Wake up detected */
      }
      /* Register fields information currently not needed */
      break;
   }
   case (KU8_ID_WK_STAT_1_ID):
   {
      /* Register fields information currently not needed */
      break;
   }
   case (KU8_ID_BUS_STAT):
   {
      /* Register fields information currently not needed */
      break;
   }
   case (KU8_ID_DEV_STAT):
   {
      /* Extract WD_FAIL detection status */
      /* TODO: Improve watchdog fail detection based on WDG configuration : CFG1 */
      if ((((uint8)KU8_ZERO) != (u8StatusRegister & ((uint8)KU8_STATUS_WD_FAIL))))
      {
         /*Watchdog reset assumed occurred */
         u32StatusInformationSBC |= KU8_MASK_WATCHDOG_FAILURE;
      }
      else
      {
         /* No watchdog reset occured */
      }

      break;
   }
   case (KU8_ID_THERM_STAT):
   {
      /* Register fields information currently not needed */
      break;
   }
   case (KU8_ID_SUP_STAT_0):
   {
      /* Extract Power on Reset detection status */
      if (((uint8)KU8_STATUS_POR) == (u8StatusRegister & ((uint8)KU8_STATUS_POR)))
      {
         /* POR occured */
         u32StatusInformationSBC |= KU8_MASK_POWER_ON_RESET;
      }
      else
      {
         /* No POR */
      }
      /* Extract VCC1 Under-Voltage detection status */
      if (((uint8)KU8_STATUS_VCC1_UV) == (u8StatusRegister & ((uint8)KU8_STATUS_VCC1_UV)))
      {
         /* VCC1 under-voltage detected */
         u32StatusInformationSBC |= KU8_MASK_VCC1_UNDER_VOLTAGE;
      }
      else
      {
         /* No VCC1 under-voltage detected*/
      }
      break;
   }
   default:
   {
      /* Should not happen. Do nothing. */
      break;
   }
   }

#if defined(DEBUG_MODE_SBC_ERRORS_SPI_IF)
   if (KU8_TWO == u8Register && u8StatusRegister == 0x01)
   {

      /* Error is not Power on Reset (POR) */
      if (u8Register != KU8_ONE && u8StatusRegister != KU8_STATUS_POR)
      {
         DIO_SET_DBG3();
      }
      if (KU8_THREE == u8Register && u8StatusRegister == 0x20)
      {
         DIO_SET_DBG4();
      }
   }
   /* Just Power on reset (POR) */
   else
   {
      DIO_CLR_DBG3();
      DIO_CLR_DBG4();
   }
#endif
}
/**************************************************************************
Label: LOCAL void SBC_ClearStateAndReport(void)
Object: Clear the informations register and check errors of SBC chip
Parameters: none
Return: none
**************************************************************************/
/*************************************************************************
Errors check :
-------------------------------------------------------------------------------------
| Error         |  Register                |  Read/Write/read&clear| Data           |
----------------|--------------------------------------------------------------------
| see DATASHEET | KU8_REG_GPIOOL_STAT      |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_GPIOOC_STAT      |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_SUP_STAT_1       |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_WK_STAT_0        |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_WK_STAT_1        |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_BUS_STAT         |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_DEV_STAT         |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_THERMAL_STAT     |   1 (Read&Clear)      |  KU16_DEFAULT  |
| see DATASHEET | KU8_REG_SUP_STAT_0       |   1 (Read&Clear)      |  KU16_DEFAULT  |
-------------------------------------------------------------------------------------
**************************************************************************************/

LOCAL void SBC_ClearStateAndReport(uint8 u8Response[KU8_SPI_DRV_COMMAND_LENGTH])
{
   uint8 u8locReponse[KU8_SPI_DRV_COMMAND_LENGTH];
   u8locReponse[KU8_SPI_BUFFER_IDX_ADDR] = u8Response[KU8_SPI_BUFFER_IDX_ADDR];
   u8locReponse[KU8_SPI_BUFFER_IDX_DATA] = u8Response[KU8_SPI_BUFFER_IDX_DATA];

   /* Read & clear GPIO_OL_STAT register if necessary */
   if ((u8locReponse[KU8_SPI_BUFFER_IDX_DATA] & KU8_MASK_GPIO_OL) == KU8_MASK_GPIO_OL)
   {
      SBC_INIT_READ_SPI_ANSWER(&cu8GpioOlStatRegister[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_GPIO_OL, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
   }
   else
   {
      /* Do nothing*/
   }

   /* Read & clear GPIO_OC_STAT register if necessary */
   if ((u8locReponse[KU8_SPI_BUFFER_IDX_DATA] & KU8_MASK_GPIO_OC) == KU8_MASK_GPIO_OC)
   {
      SBC_INIT_READ_SPI_ANSWER(&cu8GpioOcStatRegister[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_GPIO_OC, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
   }
   else
   {
      /* Do nothing*/
   }

   /* Read & clear SUP_STAT_1 register if necessary */
   if ((u8locReponse[KU8_SPI_BUFFER_IDX_DATA] & KU8_MASK_SUP_STAT_1) == KU8_MASK_SUP_STAT_1)
   {
      SBC_INIT_READ_SPI_ANSWER(&cu8SupStat1Register[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_SUP_STAT_1, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
   }
   else
   {
      /* Do nothing*/
   }

   /* Read & clear WK_STAT_0 and 1 register if necessary */
   if ((u8locReponse[KU8_SPI_BUFFER_IDX_DATA] & KU8_MASK_WK_STAT) == KU8_MASK_WK_STAT)
   {
      /* Treatment WK_STAT_0 register */
      SBC_INIT_READ_SPI_ANSWER(&cu8WakeStat0Register[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_WK_STAT_0_ID, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
      /* Treatment WK_STAT_1 register */
      SBC_INIT_READ_SPI_ANSWER(&cu8WakeStat1Register[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_WK_STAT_1_ID, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
   }
   else
   {
      /* Do nothing*/
   }

   /* Read & clear BUS_STAT_0 register if necessary */
   if ((u8locReponse[KU8_SPI_BUFFER_IDX_DATA] & KU8_MASK_BUS_STAT) == KU8_MASK_BUS_STAT)
   {
      SBC_INIT_READ_SPI_ANSWER(&cu8BusStatRegister[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_BUS_STAT, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
   }
   else
   {
      /* Do nothing*/
   }

   /* Read & clear DEV_STAT register if necessary */
   if ((u8locReponse[KU8_SPI_BUFFER_IDX_DATA] & KU8_MASK_DEV_STAT) == KU8_MASK_DEV_STAT)
   {
      SBC_INIT_READ_SPI_ANSWER(&cu8DevStatRegister[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_DEV_STAT, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
   }
   else
   {
      /* Do nothing*/
   }

   /* Read & clear THERM_STAT register if necessary */
   if ((u8locReponse[KU8_SPI_BUFFER_IDX_DATA] & KU8_MASK_THERM_STAT) == KU8_MASK_THERM_STAT)
   {
      SBC_INIT_READ_SPI_ANSWER(&cu8ThermalStatRegister[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_THERM_STAT, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
   }
   else
   {
      /* Do nothing*/
   }

   /* Read & clear SUP_STAT register if necessary */
   if ((u8locReponse[KU8_SPI_BUFFER_IDX_DATA] & KU8_MASK_SUP_STAT_0) == KU8_MASK_SUP_STAT_0)
   {
      SBC_INIT_READ_SPI_ANSWER(&cu8SupStat0Register[KU8_SPI_BUFFER_IDX_DATA], &u8Response[KU8_SPI_BUFFER_IDX_DATA]);
      SBC_DetermineSBCErrors(KU8_ID_SUP_STAT_0, u8Response[KU8_SPI_BUFFER_IDX_ADDR]);
   }
   else
   {
      /* Do nothing*/
   }
   u8Response[KU8_SPI_BUFFER_IDX_ADDR] = u8locReponse[KU8_SPI_BUFFER_IDX_ADDR];
   u8Response[KU8_SPI_BUFFER_IDX_DATA] = u8locReponse[KU8_SPI_BUFFER_IDX_DATA];
}
/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/*!****************************************************************************
* @details
*     Initialization function of module SPI_IF
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*************************************************************************
Init sequence :
------------------------------------------------------------------------------
Register       |  Read/Write/read&clear| Data                                 |
------------------------------------------------------------------------------
WD_CTRL        |  1 (Write)             |  see SpiChannelConfig_PC on         |
   -> First command is Ewternal Watchdog configuration which is mandatory
               |                        |  Spi_Cfg.c                          |
------------------------------------------------------------------------------
HW_CTRL_2      |  1 (Write)             |  KU8_CONF_INIT_HW_CTRL_2_REG        |
HW_CTRL_1      |  1 (Write)             |  KU8_CONF_INIT_HW_CTRL_1_REG        |
HW_CTRL_0      |  1 (Write)             |  KU8_CONF_INIT_HW_CTRL_0_REG        |
SUP_STAT_0     |  0 (Read&Clear)        |  KU8_DEFAULT                        |
BUS_CTRL_0     |  1 (Write)             |  KU16_SET_CAN_BUS_CTRL_NORMAL_REG   |
WK_CTRL_0      |  1 (Write)             |  KU16_CONF_INIT_WK_CTRL_0_REG       |
WK_CTRL_1      |  1 (Write)             |  KU16_CONF_INIT_WK_CTRL_1_REG       |
TIMER_CTRL     |  1 (Write)             |  KU16_CONF_INIT_TIMER_CTRL_REG      |
PWM_CTRL       |  1 (Write)             |  KU16_CONF_INIT_PWM_CTRL_REG        |
M_S_CTRL       |  1 (Write)             |  KU16_CONF_SET_MODE_CTRL_NORMAL_REG |
FAM_PROD_STATE |  1 (Write)             |  KU16_DEFAULT                       |
------------------------------------------------------------------------------
**************************************************************************/
void SBC_Init(void)
{
   /*Local variable created to correct QAC issue 694423 */
   const uint8 u8LocalKU8_NO_RESET_CAUSE = (uint8)KU8_NO_RESET_CAUSE;

#if defined(DEBUG_MODE_INIT_TIME_SPI_IF)
   /* use to measured the initialization time */
   DIO_SET_DBG1();
#endif

   /* Refresh external Watchdog first  : ie see datasheet TLE9471-3ES */
   SBC_REFRESH_WDG_REQUEST(cu8WdgRegister);

   /* set control register HW_CTRL_2 */
   SBC_INIT_WRITE_SPI_DATA(&cu8HwCtrl2Register[KU8_SPI_BUFFER_IDX_DATA]);

   /* set control register HW_CTRL_1 */
   SBC_INIT_WRITE_SPI_DATA(&cu8HwCtrl1Register[KU8_SPI_BUFFER_IDX_DATA]);

   /* set control register HW_CTRL_0 */
   SBC_INIT_WRITE_SPI_DATA(&cu8HwCtrl0Register[KU8_SPI_BUFFER_IDX_DATA]);

   /* set control register GPIO_CTRL */
   SBC_INIT_WRITE_SPI_DATA(&cu8WKCtrl0Register[KU8_SPI_BUFFER_IDX_DATA]);

   /* set control register GPIO_CTRL */
   SBC_INIT_WRITE_SPI_DATA(&cu8WKCtrl1Register[KU8_SPI_BUFFER_IDX_DATA]);

   /* set control register GPIO_CTRL */
   SBC_INIT_WRITE_SPI_DATA(&cu8TimerCtrlRegister[KU8_SPI_BUFFER_IDX_DATA]);

   /* set control register GPIO_CTRL */
   SBC_INIT_WRITE_SPI_DATA(&cu8PwmCtrlRegister[KU8_SPI_BUFFER_IDX_DATA]);

   /* Set the SBC mode to Normal mode */
   u8MSCtrlRegister[KU8_SPI_BUFFER_IDX_DATA] = KU8_REG_MODE_SUPPLY_CTRL;
   u8MSCtrlRegister[KU8_SPI_BUFFER_IDX_ADDR] = KU8_NORMAL_MODE_SBC;
   SBC_INIT_WRITE_SPI_DATA(&u8MSCtrlRegister[KU8_SPI_BUFFER_IDX_DATA]);

   /* set CAN Mode to Normal CAN */
   u8BusCtrl0Register[KU8_SPI_BUFFER_IDX_DATA] = KU8_REG_BUS_CTRL;
   u8BusCtrl0Register[KU8_SPI_BUFFER_IDX_ADDR] = KU8_NORMAL_MODE_CAN;
   SBC_INIT_WRITE_SPI_DATA(&u8BusCtrl0Register[KU8_SPI_BUFFER_IDX_DATA]);

   /* Verify the SBC informations status bit field */
   SBC_INIT_READ_SPI_ANSWER(&cu8FamProdStateRegister[KU8_SPI_BUFFER_IDX_DATA], &u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA]);
   if ((u8SPILocalResponse[KU8_SPI_BUFFER_IDX_DATA] != u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA]) && (u8SPIResponse[KU8_SPI_BUFFER_IDX_ADDR] != u8LocalKU8_NO_RESET_CAUSE))
   {
      SBC_ClearStateAndReport(u8SPIResponse);
   }
   else
   {
      /* Do nothing*/
   }

   u8SPILocalResponse[KU8_SPI_BUFFER_IDX_ADDR] = u8SPIResponse[KU8_SPI_BUFFER_IDX_ADDR];
   u8SPILocalResponse[KU8_SPI_BUFFER_IDX_DATA] = u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA];

#if defined(DEBUG_MODE_INIT_TIME_SPI_IF)
   /* use to measured the initialization time */
   DIO_CLR_DBG1();
#endif
}

/*!****************************************************************************
* @details
*     Main function of module SPI_IF
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/***********************************************************************
Main sequence :
---------------------------------------------------------------------------
Register      |  Read/Write/read&clear | Data                             |
---------------------------------------------------------------------------
WD_CTRL       |  1 (Write)             |  KU8_CONF_WD_CTRL_REG            |
FAM_PROD_STATE|  0 (Read)              |  KU16_DEFAULT                    |
---------------------------------------------------------------------------
**************************************************************************/
void SBC_MainFunction(void)
{
   /*Local variable created to correct QAC issue 694423 */
   const uint8 u8LocalKU8_NO_RESET_CAUSE = (uint8)KU8_NO_RESET_CAUSE;
   const uint8 u8LocalKU8_MAX_COUNTER_REFRESH_WD = (uint8)KU8_MAX_COUNTER_REFRESH_WD;

   /* Refresh watchdog every 50ms -- This function is called every 10ms */
   if (u8CounterBaseRefreshWD > u8LocalKU8_MAX_COUNTER_REFRESH_WD)
   {
      /* Reset counter watchdog to refresh it */
      u8CounterBaseRefreshWD = KU8_ZERO;

      /* Refresh external watchdog */
      SBC_REFRESH_WDG_REQUEST(cu8WdgRegister);
   }
   else
   {
      /* Increment counter watchdog */
      u8CounterBaseRefreshWD++;
   }

   /* Read informations status register to obtain the SBC errors : ie use serial number read command for that */
   SBC_INIT_READ_SPI_ANSWER(&cu8FamProdStateRegister[KU8_SPI_BUFFER_IDX_DATA], &u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA]);
   if ((u8SPILocalResponse[KU8_SPI_BUFFER_IDX_DATA] != u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA]) && (u8SPIResponse[KU8_SPI_BUFFER_IDX_ADDR] != u8LocalKU8_NO_RESET_CAUSE))
   {
      SBC_ClearStateAndReport(u8SPIResponse);
   }
   else
   {
      /* Do nothing*/
   }
   u8SPILocalResponse[KU8_SPI_BUFFER_IDX_ADDR] = u8SPIResponse[KU8_SPI_BUFFER_IDX_ADDR];
   u8SPILocalResponse[KU8_SPI_BUFFER_IDX_DATA] = u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA];
}

/*!****************************************************************************
* @details
*     Shutdown function of module SPI_IF
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/***********************************************************************
Shutdown sequence :
-----------------------------------------------------------------------------
Register      |  Read/Write/read&clear | Data                               |
-----------------------------------------------------------------------------
WK_STAT_0     |  0 (Read&Clear)        |  KU8_DEFAULT                       |
WK_STAT_1     |  0 (Read&Clear)        |  KU8_DEFAULT                       |
BUS_CTRL_0    |  1 (Write)             |  KU16_SET_CAN_BUS_CTRL_WAKABLE_REG |
M_S_CTRL      |  1 (Write)             |  KU16_CONF_SET_MODE_CTRL_SLEEP_REG |
-----------------------------------------------------------------------------
**************************************************************************/
void SBC_Shutdown(void)
{
   /*Local variable created to correct QAC issue 694423 */
   const uint8 u8LocalKU8_NO_RESET_CAUSE = (uint8)KU8_NO_RESET_CAUSE;

    /* Read & clear the wake register 0 */
   SBC_INIT_READ_SPI_ANSWER(&cu8WakeStat0Register[KU8_SPI_BUFFER_IDX_DATA], &u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA]);
   if (u8LocalKU8_NO_RESET_CAUSE != u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA])
   {
      /* Clear flag wake on WK_STAT_0 register */
   }
   else
   {
      /* Do nothing*/
   }

   /* Read & clear the wake register 1 */
   SBC_INIT_READ_SPI_ANSWER(&cu8WakeStat1Register[KU8_SPI_BUFFER_IDX_DATA], &u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA]);
   if (u8LocalKU8_NO_RESET_CAUSE != u8SPIResponse[KU8_SPI_BUFFER_IDX_DATA])
   {
      /* Clear flag wake on WK_STAT_1 register */
   }
   else
   {
      /* Do nothing*/
   }

   /* Set CAN mode to Wake capable */
   u8BusCtrl0Register[KU8_SPI_BUFFER_IDX_DATA] = KU8_REG_BUS_CTRL;
   u8BusCtrl0Register[KU8_SPI_BUFFER_IDX_ADDR] = KU8_WAKE_CAPABLE_CAN;
   SBC_INIT_WRITE_SPI_DATA(&u8BusCtrl0Register[KU8_SPI_BUFFER_IDX_DATA]);

   /* set control register M_S_CTRL to Sleep mode */
   u8MSCtrlRegister[KU8_SPI_BUFFER_IDX_DATA] = KU8_REG_MODE_SUPPLY_CTRL;
   u8MSCtrlRegister[KU8_SPI_BUFFER_IDX_ADDR] = KU8_SLEEP_MODE_SBC;
   SBC_INIT_WRITE_SPI_DATA(&u8MSCtrlRegister[KU8_SPI_BUFFER_IDX_DATA]);
}

/*!****************************************************************************
* @details
*     Get the SBC reset causes
* @param[in]
*     none
* @param[out]
*     reset cause bit field
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void SBC_runGetResetCauses(uint16 *u16ResetCauses)
{
   *u16ResetCauses = u16StatusSBC;
}

/*!****************************************************************************
* @details
*     Get the SBC status information
* @param[in]
*     none
* @param[out]
*     status information bit field
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void SBC_GetSBCStatusInformation(uint32 *u32StatusInformation)
{
   *u32StatusInformation = u32StatusInformationSBC;
}

/*!****************************************************************************
* @details
*     Force external watchdog refresh
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void SBC_ForceExternalWatchdogReset(void)
{
   /* Trigger external watchdog 2 times.
     * Second trigger signal will meet the closed window leading to a watchdog reset:
     *  - Reset output RSTN low
     *  - SBC switches to SBC Restart
     */

   SuspendAllInterrupts();
   while (1)
      ;
}

/*!****************************************************************************
* @details
*     Spi Configuration Error Autotest Callback Notification.
* @param[in]
*     none
* @param[out]
*     none
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void SBC_SpiConfigurationHwError_Notification(void)
{
   Dem_UdsStatusByteType rcm_EventStatus = KU8_ZERO;

   u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* Returned status */
   (void)Dem_GetEventUdsStatus(DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR, &rcm_EventStatus);

   if ((DEM_UDS_STATUS_CDTC & rcm_EventStatus) == DEM_UDS_STATUS_CDTC)
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
}


void SBC_ServiceAutotest_GetTestResult(u8TestResultType * pu8TestResult) /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
{
   *pu8TestResult = u8ResultOfAutoTest;
}
#define SBC_STOP_SEC_CODE
#include "SBC_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/
