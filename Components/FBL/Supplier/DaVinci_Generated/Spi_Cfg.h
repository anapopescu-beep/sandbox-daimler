
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
**  FILENAME  : Spi_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 16.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2023-04-11, 10:26:18  !!!IGNORE-LINE!!!                   **
**                                                                            **
**  GENERATOR : Build b191017-0938       !!!IGNORE-LINE!!!                  **
**                                                                            **
**  BSW MODULE DECRIPTION : Spi.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Spi configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Spi Driver, AUTOSAR Release 4.2.2     **
**                     Specification of Spi Driver, AUTOSAR Release 4.4.0     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/* To avoid multiple inclusion of the header file more than once */
#ifndef SPI_CFG_H
#define SPI_CFG_H

/* Section to Generate Autosar Specific Version Information */
#define SPI_AR_RELEASE_MAJOR_VERSION          (4U)
#define SPI_AR_RELEASE_MINOR_VERSION          (4U)
#define SPI_AR_RELEASE_REVISION_VERSION       (0U)

/* Section to Generate Vendor Specific Version Information */
/* Vendor specific implementation version information      */
#define SPI_SW_MAJOR_VERSION                  (20U)
#define SPI_SW_MINOR_VERSION                  (0U)
#define SPI_SW_PATCH_VERSION                  (2U)
/* Pre-Compile parameters */
/* (Development Error)/(Default Error) Trace */

#define SPI_DEV_ERROR_DETECT                  (STD_OFF)
/* Runtime Error*/

#define SPI_RUNTIME_ERROR_DETECT                  (STD_OFF)


/* Safety error check */
#define SPI_SAFETY_ENABLE                  (STD_OFF)
/* Dem reporting  macros */
#define SPI_DEM_REPORT_DISABLED               (0U)
#define SPI_DEM_REPORT_ENABLED                (1U)
/* Dem Related Macros */
#define SPI_HW_ERROR_DEM_REPORT               (SPI_DEM_REPORT_DISABLED)
/* Kind of transmission available,
0 - Only Synchronous Transmission
1 - Only Asynchronous Transmission(Interrupt mode only)
2 - Both Sync and Async(Both Interrupt and Polling Mode) Transmission */

#define SPI_LEVEL_DELIVERED                   (2U)
/* Main function period - Used by application to poll the SPI Hw module */

#define SPI_MAIN_FUNCTION_PERIOD              (0U)
/* Kind of Channele buffers allowed
0 - Only Internal buffers allowed
1 - Only External buffers allowed
2 - Both Internal and External buffers allowed */

#define SPI_CHANNEL_BUFFERS_ALLOWED           (0U)
/* Specifies if the API Spi_Cancel() is available */

#define SPI_CANCEL_API                        (STD_OFF)
/* Specifies if the API Spi_GetHWUnitStatus() is available */

#define SPI_HW_STATUS_API                     (STD_OFF)
/* Specifies if the API Spi_ControlLoopBack() is available */
#define SPI_CONTROL_LOOPBACK_API                     (STD_OFF)
/* Specifies if the API Spi_GetVersionInfo() is available */

#define SPI_VERSION_INFO_API                  (STD_OFF)
/* Specifies if Sequences can be interrupted during
transmission. For Level = 0, its value is STD_OFF by default */

#define SPI_INTERRUPTIBLE_SEQ_ALLOWED         (STD_OFF)
/* Configuration Options:
SPI Sequence Interruptible Options */
#define SPI_SEQ_INT_FALSE                     ((uint8)0U)
#define SPI_SEQ_INT_TRUE                      ((uint8)1U)
/* Specifies if concurrent transmission of synchronous
sequences are allowed. For Level = 1, its value is STD_OFF by default */

#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  (STD_OFF)
/* Maximum QSPI Hw units available */

#define SPI_MAX_HW_UNIT                       (3U)
#define SPI_SYNC_BUS                          (0U)
#define SPI_ASYNC_BUS                         (1U)
/* Is QSPI0 Used */
#define SPI_HW_QSPI0_USED                     (STD_OFF)
/* Is QSPI1 Used */
#define SPI_HW_QSPI1_USED                     (STD_ON)
/* Index for QSPI1module */
#define SPI_QSPI1_INDEX                       (1U)
/* Sync/Async */
#define SPI_QSPI1_HWTYPE                      (SPI_SYNC_BUS)
/* Is QSPI2 Used */
#define SPI_HW_QSPI2_USED                     (STD_OFF)
/* Timeout value to wait for trail delay to be completed.
Should be atleast greater than the Trail delay
(also to avoid possible infinite loops) */
#define SPI_DELAY_TIMEOUT                     (0xFFFFFFFEU)
/* SPI Module is enabled,
Module does not enter sleep mode upon sleep request */
#define SPI_CLK_SLEEP_DISABLE                 (0x00000008U)
/* SPI Module is enabled,
Module enters sleep mode upon sleep request         */
#define SPI_CLK_SLEEP_ENABLE                  (0x00000000U)
/* Job Delimiter, marks end of Job */
#define SPI_JOB_DELIMITER                     ((uint16)0xFFFFU)
/* Sequence Delimiter, marks end of Sequence */
#define SPI_SEQUENCE_DELIMITER                ((uint8)0xFFU)
/* Channel Delimiter, marks the end of channel */
#define SPI_CHANNEL_DELIMITER                 ((uint8)0xFFU)
/* QSPI HW Delimiter, marks the end of QSPI module */
#define SPI_QSPI_HW_DELIMITER                 ((uint8)0xFFU)

#define SPI_IB_BUFFER_SIZE_CORE0           (4U)

/* Job Queue Length for QSPI1 */


#define SPI_JOB_QUEUE_LENGTH_QSPI0            (0U)
/* Job Queue Length for QSPI1 */
#define SPI_JOB_QUEUE_LENGTH_QSPI1            (2U)
/* Job Queue Length for QSPI2 */
#define SPI_JOB_QUEUE_LENGTH_QSPI2            (0U)
/* QSPI Channel Index */
#define SPI_QSPI_CHANNEL0                     ((uint8)0U)
#define SPI_QSPI_CHANNEL1                     ((uint8)1U)
#define SPI_QSPI_CHANNEL2                     ((uint8)2U)
#define SPI_QSPI_CHANNEL3                     ((uint8)3U)
#define SPI_QSPI_CHANNEL4                     ((uint8)4U)
#define SPI_QSPI_CHANNEL5                     ((uint8)5U)
#define SPI_QSPI_CHANNEL6                     ((uint8)6U)
#define SPI_QSPI_CHANNEL7                     ((uint8)7U)
#define SPI_QSPI_CHANNEL8                     ((uint8)8U)
#define SPI_QSPI_CHANNEL9                     ((uint8)9U)
#define SPI_QSPI_CHANNEL10                    ((uint8)10U)
#define SPI_QSPI_CHANNEL11                    ((uint8)11U)
#define SPI_QSPI_CHANNEL12                    ((uint8)12U)
#define SPI_QSPI_CHANNEL13                    ((uint8)13U)
#define SPI_QSPI_CHANNEL14                    ((uint8)14U)
#define SPI_QSPI_CHANNEL15                    ((uint8)15U)
/* Number of IB channels on Async Hw */
/*Kernel 1*/


#define SPI_NUM_IB_CHANNELS_CORE0            (1U)


#define SPI_CORE0_ENABLE     STD_ON

/* Number of EB channels */
/*kernel 1*/

#define SPI_NUM_EB_CHANNELS_CORE0            (0U)

#define SPI_DMA_MAX_TCS_NUM_QSPI1 (0U)
/* Indicates no CS to be done */
#define SPI_CS_VIA_HW_OR_NONE                 (0xFFFFU)
#define SPI_PARITY_EVEN                       (0U)
#define SPI_PARITY_ODD                        (1U)
#define SPI_PARITY_UNUSED                     (2U)
/* Configuration Options:
Selection of Channel Buffer Type */
/* EB Buffer Channel Type */
#define SPI_EB_CHANNEL                        (0U)
/* IB Buffer Channel Type */
#define SPI_IB_CHANNEL                        (1U)
/* Invalid DMA channel */
#define SPI_DMA_CHNL_INVALID                  (0xFFU)
/* Sequence ID *//* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */

#define SpiConf_SpiSequence_SpiSequence_WDG_REFRESH      (0U)
/* Job ID */
#define SpiConf_SpiJob_SpiJob_0      (0U)
/* Channel ID *//* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */

#define SpiConf_SpiChannel_SpiChannel_WDG      (0U)
/*Physical sequence ID*/
/* Physical Job ID *//* Channel ID *//*end Physical*/


#define SPI_SEQUENCE_COUNT_CORE0      1U


#define SPI_JOB_COUNT_CORE0       1U
#define SPI_QSPI1_CORE          0

#define SPI_INIT_DEINIT_API_MODE              SPI_MCAL_SUPERVISOR


#define SPI_RUN_TIME_API_MODE                 SPI_MCAL_SUPERVISOR
#define SPI_MCAL_SUPERVISOR                   (0U)
#define SPI_MCAL_USER1                        (1U)

#define SPI_INIT_CHECK_API                        (STD_OFF)
#define SPI_MULTICORE_ERROR_DETECT                        (STD_OFF)
#endif  /* SPI_CFG_H */
/* End Of File */
