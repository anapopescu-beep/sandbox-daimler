
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2020)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Dio_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 8.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2021-05-13, 16:56:22         !!!IGNORE-LINE!!!                **
**                                                                            **
**  GENERATOR : Build b191017-0938             !!!IGNORE-LINE!!!              **
**                                                                            **
**  BSW MODULE DECRIPTION : Dio.bmd                                           **
**                                                                            **
**  VARIANT   : Variant LT                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Dio configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Dio Driver, AUTOSAR Release 4.2.2     **
**                     and AUTOSAR Release 4.4.0                              **
**                                                                            **
** MAY BE CHANGED BY USER : no                                                **
**                                                                            **
*******************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H
/*
Notes:
- The runtime configuration is handled by the Port Driver Module.
- The configuration and usage of the DIO Driver Module is adapted to
the microcontroller and ECU.

*/

/*Version check macros */
#define DIO_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_AR_RELEASE_MINOR_VERSION     (4U)
#define DIO_AR_RELEASE_REVISION_VERSION  (0U)


#define DIO_SW_MAJOR_VERSION  (20U)
#define DIO_SW_MINOR_VERSION  (0U)
#define DIO_SW_PATCH_VERSION  (1U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*                          Container: DioGeneral                            */
/*

Pre-processor switch to enable/disable detection of Development errors.
- if defined ON, Development error detection is enabled
- if defined OFF, Development error detection is disabled
*/
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/*
Pre-Compiler switch to include the API Dio_GetVersionInfo()
- if defined ON, Dio_GetVersionInfo API available
- if defined OFF, Dio_GetVersionInfo API not available
*/
#define DIO_VERSION_INFO_API                (STD_OFF)

/*
Pre-Compiler switch to include the API Dio_FlipChannel()
- if defined ON, Dio_FlipChannel API available
- if defined OFF, Dio_FlipChannel API not available
*/
#define DIO_FLIP_CHANNEL_API                (STD_ON)

#define DIO_MASKED_WRITE_PORT_API           (STD_OFF)
/*
Pre-Compiler switch to include the Safety Check
*/

#define DIO_SAFETY_ENABLE                (STD_ON)

/* The following macros are available only if development error detection
is enabled */
/* Definition to specify the ports available on the microcontroller
Bit value = 0 implies the port is not available
Bit value = 1 implies the port is available
Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 */
#define DIO_PORTS_AVAILABLE_00_31           (0x00b0cc05U)

/* Definition to specify the ports available on the microcontroller
Bit value = 0 implies the port is not available
Bit value = 1 implies the port is available
Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 31 is for Port 63 */
#define DIO_PORTS_AVAILABLE_32_63           (0x00000102U)

/* Definition to specify the ports that are read only ports on the microcontroller
Bit value = 0 implies the port readable/writable
Bit value = 1 implies the port is read only port
Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 */
#define DIO_PORTS_READONLY_00_31             (0x00000000U)

/* Definition to specify the ports that are read only ports on the microcontroller
Bit value = 0 implies the port readable/writable
Bit value = 1 implies the port is read only port
Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 31 is for Port 63 */
#define DIO_PORTS_READONLY_32_63             (0x00000100U)

/* Value of the most significant pin on the port
Note: In case of no pins on a port, the value is kept 0 */
#define DIO_PORT_0_MSPIN                     (0U)
#define DIO_PORT_1_MSPIN                     (0U)
#define DIO_PORT_2_MSPIN                     (8U)
#define DIO_PORT_3_MSPIN                     (0U)
#define DIO_PORT_4_MSPIN                     (0U)
#define DIO_PORT_5_MSPIN                     (0U)
#define DIO_PORT_6_MSPIN                     (0U)
#define DIO_PORT_7_MSPIN                     (0U)
#define DIO_PORT_8_MSPIN                     (0U)
#define DIO_PORT_9_MSPIN                     (0U)
#define DIO_PORT_10_MSPIN                     (6U)
#define DIO_PORT_11_MSPIN                     (12U)
#define DIO_PORT_12_MSPIN                     (0U)
#define DIO_PORT_13_MSPIN                     (0U)
#define DIO_PORT_14_MSPIN                     (5U)
#define DIO_PORT_15_MSPIN                     (3U)
#define DIO_PORT_16_MSPIN                     (0U)
#define DIO_PORT_17_MSPIN                     (0U)
#define DIO_PORT_18_MSPIN                     (0U)
#define DIO_PORT_19_MSPIN                     (0U)
#define DIO_PORT_20_MSPIN                     (14U)
#define DIO_PORT_21_MSPIN                     (7U)
#define DIO_PORT_22_MSPIN                     (0U)
#define DIO_PORT_23_MSPIN                     (1U)
#define DIO_PORT_24_MSPIN                     (0U)
#define DIO_PORT_25_MSPIN                     (0U)
#define DIO_PORT_26_MSPIN                     (0U)
#define DIO_PORT_27_MSPIN                     (0U)
#define DIO_PORT_28_MSPIN                     (0U)
#define DIO_PORT_29_MSPIN                     (0U)
#define DIO_PORT_30_MSPIN                     (0U)
#define DIO_PORT_31_MSPIN                     (0U)
#define DIO_PORT_32_MSPIN                     (0U)
#define DIO_PORT_33_MSPIN                     (10U)
#define DIO_PORT_34_MSPIN                     (0U)
#define DIO_PORT_35_MSPIN                     (0U)
#define DIO_PORT_36_MSPIN                     (0U)
#define DIO_PORT_37_MSPIN                     (0U)
#define DIO_PORT_38_MSPIN                     (0U)
#define DIO_PORT_39_MSPIN                     (0U)
#define DIO_PORT_40_MSPIN                     (5U)
/* Macro to define the maximum port available */
#define MAX_AVAILABLE_PORT                  (40U)

/* Values to mask the undefined port pins within a port */
#define DIO_MASK_ALL_PINS_PORT0             (0x0001U)
#define DIO_MASK_ALL_PINS_PORT1             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT2             (0x01ffU)
#define DIO_MASK_ALL_PINS_PORT3             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT4             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT5             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT6             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT7             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT8             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT9             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT10             (0x0060U)
#define DIO_MASK_ALL_PINS_PORT11             (0x1e4cU)
#define DIO_MASK_ALL_PINS_PORT12             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT13             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT14             (0x002bU)
#define DIO_MASK_ALL_PINS_PORT15             (0x000fU)
#define DIO_MASK_ALL_PINS_PORT16             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT17             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT18             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT19             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT20             (0x7b04U)
#define DIO_MASK_ALL_PINS_PORT21             (0x00c0U)
#define DIO_MASK_ALL_PINS_PORT22             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT23             (0x0002U)
#define DIO_MASK_ALL_PINS_PORT24             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT25             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT26             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT27             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT28             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT29             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT30             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT31             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT32             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT33             (0x07f0U)
#define DIO_MASK_ALL_PINS_PORT34             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT35             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT36             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT37             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT38             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT39             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT40             (0x0030U)
#define DIO_MASK_ALL_PINS_PORT41             (0x0000U)

#define DIO_MAX_VALID_PORT_PIN_ID                  (0x285U)

/* Macro to define the No of channel groups configured */
#define DIO_CHANNELGROUPCOUNT               (1U)


/*******************************************************************************
**                           Global Symbols                                   **
*******************************************************************************/

/*
Symbolic names for DIO Channels, Port & Channel groups
*/

/*
Symbolic names for Channels
*/
#define DIO_CHANNEL_0_0                    ((Dio_ChannelType)0x000)
#define DIO_CHANNEL_2_0                    ((Dio_ChannelType)0x020)
#define DIO_CHANNEL_2_1                    ((Dio_ChannelType)0x021)
#define DIO_CHANNEL_2_2                    ((Dio_ChannelType)0x022)
#define DIO_CHANNEL_2_3                    ((Dio_ChannelType)0x023)
#define DIO_CHANNEL_2_4                    ((Dio_ChannelType)0x024)
#define DIO_CHANNEL_2_5                    ((Dio_ChannelType)0x025)
#define DIO_CHANNEL_2_6                    ((Dio_ChannelType)0x026)
#define DIO_CHANNEL_2_7                    ((Dio_ChannelType)0x027)
#define DIO_CHANNEL_2_8                    ((Dio_ChannelType)0x028)
#define DIO_CHANNEL_10_5                    ((Dio_ChannelType)0x0a5)
#define DIO_CHANNEL_10_6                    ((Dio_ChannelType)0x0a6)
#define DIO_CHANNEL_11_2                    ((Dio_ChannelType)0x0b2)
#define DIO_CHANNEL_11_3                    ((Dio_ChannelType)0x0b3)
#define DIO_CHANNEL_11_6                    ((Dio_ChannelType)0x0b6)
#define DIO_CHANNEL_11_9                    ((Dio_ChannelType)0x0b9)
#define DIO_CHANNEL_11_10                    ((Dio_ChannelType)0x0ba)
#define DIO_CHANNEL_11_11                    ((Dio_ChannelType)0x0bb)
#define DIO_CHANNEL_11_12                    ((Dio_ChannelType)0x0bc)
#define DIO_CHANNEL_14_0                    ((Dio_ChannelType)0x0e0)
#define DIO_CHANNEL_14_1                    ((Dio_ChannelType)0x0e1)
#define DIO_CHANNEL_14_3                    ((Dio_ChannelType)0x0e3)
#define DIO_CHANNEL_14_5                    ((Dio_ChannelType)0x0e5)
#define DIO_CHANNEL_15_0                    ((Dio_ChannelType)0x0f0)
#define DIO_CHANNEL_15_1                    ((Dio_ChannelType)0x0f1)
#define DIO_CHANNEL_15_2                    ((Dio_ChannelType)0x0f2)
#define DIO_CHANNEL_15_3                    ((Dio_ChannelType)0x0f3)
#define DIO_CHANNEL_20_2                    ((Dio_ChannelType)0x142)
#define DIO_CHANNEL_20_8                    ((Dio_ChannelType)0x148)
#define DIO_CHANNEL_20_9                    ((Dio_ChannelType)0x149)
#define DIO_CHANNEL_20_11                    ((Dio_ChannelType)0x14b)
#define DIO_CHANNEL_20_12                    ((Dio_ChannelType)0x14c)
#define DIO_CHANNEL_20_13                    ((Dio_ChannelType)0x14d)
#define DIO_CHANNEL_20_14                    ((Dio_ChannelType)0x14e)
#define DIO_CHANNEL_21_6                    ((Dio_ChannelType)0x156)
#define DIO_CHANNEL_21_7                    ((Dio_ChannelType)0x157)
#define DIO_CHANNEL_23_1                    ((Dio_ChannelType)0x171)
#define DIO_CHANNEL_33_4                    ((Dio_ChannelType)0x214)
#define DIO_CHANNEL_33_5                    ((Dio_ChannelType)0x215)
#define DIO_CHANNEL_33_6                    ((Dio_ChannelType)0x216)
#define DIO_CHANNEL_33_7                    ((Dio_ChannelType)0x217)
#define DIO_CHANNEL_33_8                    ((Dio_ChannelType)0x218)
#define DIO_CHANNEL_33_9                    ((Dio_ChannelType)0x219)
#define DIO_CHANNEL_33_10                    ((Dio_ChannelType)0x21a)
#define DIO_CHANNEL_40_4                    ((Dio_ChannelType)0x284)
#define DIO_CHANNEL_40_5                    ((Dio_ChannelType)0x285)
/*
Symbolic names for DIO ports
*/
#define DIO_PORT_0                          ((Dio_PortType)0)
#define DIO_PORT_2                          ((Dio_PortType)2)
#define DIO_PORT_10                          ((Dio_PortType)10)
#define DIO_PORT_11                          ((Dio_PortType)11)
#define DIO_PORT_14                          ((Dio_PortType)14)
#define DIO_PORT_15                          ((Dio_PortType)15)
#define DIO_PORT_20                          ((Dio_PortType)20)
#define DIO_PORT_21                          ((Dio_PortType)21)
#define DIO_PORT_23                          ((Dio_PortType)23)
#define DIO_PORT_33                          ((Dio_PortType)33)
#define DIO_PORT_40                          ((Dio_PortType)40)

/*
User Defined Symbolic Names for the DIO Ports, Channels & Channel Groups
*/
/*
DIO PORT : (DioPort_0)
*/
#ifndef DioConf_DioPort_DioPort_0
#define DioConf_DioPort_DioPort_0 (DIO_PORT_33)
#endif
/* DIO Channel : (DioChannel_LED) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DioChannel_LED
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DioChannel_LED (DIO_CHANNEL_33_4)
#endif
/* DIO Channel : (DioChannel_1) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DioChannel_1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DioChannel_1 (DIO_CHANNEL_33_6)
#endif
/* DIO Channel : (DioChannel_2) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_DioChannel_2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_DioChannel_2 (DIO_CHANNEL_33_7)
#endif
/* DIO Channel : (STB2) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_STB2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_STB2 (DIO_CHANNEL_33_10)
#endif
/*DIO Channel Group : DioChGrpId_P33_0*/
/* To prevent double declaration */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannelGroup_DioChannelGroup_LED
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannelGroup_DioChannelGroup_LED (&Dio_Config.Dio_ChannelGroupConfigPtr[0])
#endif
/*
DIO PORT : (DioPort_1)
*/
#ifndef DioConf_DioPort_DioPort_1
#define DioConf_DioPort_DioPort_1 (DIO_PORT_20)
#endif
/* DIO Channel : (TRB_LED) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_TRB_LED
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_TRB_LED (DIO_CHANNEL_20_11)
#endif
/*
DIO PORT : (DioPort_2)
*/
#ifndef DioConf_DioPort_DioPort_2
#define DioConf_DioPort_DioPort_2 (DIO_PORT_2)
#endif
/* DIO Channel : (OCU_CHANNEL_PIN) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_OCU_CHANNEL_PIN
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_OCU_CHANNEL_PIN (DIO_CHANNEL_2_5)
#endif
/*
DIO PORT : (DioPort_3)
*/
#ifndef DioConf_DioPort_DioPort_3
#define DioConf_DioPort_DioPort_3 (DIO_PORT_10)
#endif
/* DIO Channel : (STB) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_STB
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_STB (DIO_CHANNEL_10_6)
#endif



/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
#include "Dio_MemMap.h"

extern const struct Dio_ConfigType Dio_Config; 
#define DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
Dio_Memmap.h header is included without safegaurd.*/
#include "Dio_MemMap.h"
/*******************************************************************************
**                      Global Data Type                                      **
*******************************************************************************/
/* End of DIO_CFG_H */
#endif
