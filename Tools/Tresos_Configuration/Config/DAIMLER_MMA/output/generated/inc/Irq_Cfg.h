
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
**  FILENAME  : Irq_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 8.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2021-05-16, 10:34:39      !!!IGNORE-LINE!!!                   **
**                                                                            **
**  GENERATOR : Build b191017-0938        !!!IGNORE-LINE!!!                   **
**                                                                            **
**  BSW MODULE DECRIPTION : Irq.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PC                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Irq configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : na                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/
#ifndef IRQ_CFG_H
#define IRQ_CFG_H




/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/************************* interrupt CATEGORY *********************************/
#define IRQ_CAT1                    (0)
#define IRQ_CAT2                    (1)
/************************* interrupt Type of Service **************************/
#define IRQ_TOS_CPU0                (0x0000)
#define IRQ_TOS_CPU1                (0x1000)
#define IRQ_TOS_CPU2                (0x1800)
#define IRQ_TOS_CPU3                (0x2000)
#define IRQ_TOS_CPU4                (0x2800)
#define IRQ_TOS_CPU5                (0x3000)
#define IRQ_TOS_DMA                 (0x0800)
/*
Container : IrqGeneralConfiguration
*/

/*
Configuration: IRQ_OS_ENABLE
- if TRUE, OSEK RTOS is used,
Both CAT1 and CAT2 interrupt categories can be configured
Any CAT2 interrupt priority should be greater than CAT1 interrupt priority
- if FALSE,OSEK RTOS is not used
Only CAT1 interrupt category can be configured
*/

#define IRQ_OSEK_ENABLE   (STD_OFF)


/*
Container : IrqGPTinterruptConfiguration
*/
/* GPT120 interrupt Category setting */
#define IRQ_GPT120_CARPEL_CAT       (IRQ_CAT1)
#define IRQ_GPT120_T2_CAT           (IRQ_CAT1)
#define IRQ_GPT120_T3_CAT           (IRQ_CAT1)
#define IRQ_GPT120_T4_CAT           (IRQ_CAT1)
#define IRQ_GPT120_T5_CAT           (IRQ_CAT1)
#define IRQ_GPT120_T6_CAT           (IRQ_CAT1)

/*  GPT120 interrupt Priority setting  */
#define IRQ_GPT120_CARPEL_PRIO      0x0
#define IRQ_GPT120_T2_PRIO          0x0
#define IRQ_GPT120_T3_PRIO          0x0
#define IRQ_GPT120_T4_PRIO          0x0
#define IRQ_GPT120_T5_PRIO          0x0
#define IRQ_GPT120_T6_PRIO          0x0

/* GPT120 interrupt type of service setting */
#define IRQ_GPT120_CARPEL_TOS       (IRQ_TOS_CPU0)
#define IRQ_GPT120_T2_TOS           (IRQ_TOS_CPU0)
#define IRQ_GPT120_T3_TOS           (IRQ_TOS_CPU0)
#define IRQ_GPT120_T4_TOS           (IRQ_TOS_CPU0)
#define IRQ_GPT120_T5_TOS           (IRQ_TOS_CPU0)
#define IRQ_GPT120_T6_TOS           (IRQ_TOS_CPU0)

/*
Container : IrqQspi interruptConfiguration
*/
/* Qspi Tx interrupt Category Setting*/
#define IRQ_QSPI0_TX_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_TX_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_TX_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_TX_CAT            (IRQ_CAT1)
#define IRQ_QSPI4_TX_CAT            (IRQ_CAT1)
#define IRQ_QSPI5_TX_CAT            (IRQ_CAT1)

/* Qspi Tx interrupt Priority Setting*/
#define IRQ_QSPI0_TX_PRIO           0x0
#define IRQ_QSPI1_TX_PRIO           0x0
#define IRQ_QSPI2_TX_PRIO           0x0
#define IRQ_QSPI3_TX_PRIO           0x0
#define IRQ_QSPI4_TX_PRIO           0x0
#define IRQ_QSPI5_TX_PRIO           0x0

/* Qspi Tx interrupt type of service Setting*/
#define IRQ_QSPI0_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI4_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI5_TX_TOS            (IRQ_TOS_CPU0)

/* Qspi Rx interrupt Category Setting*/
#define IRQ_QSPI0_RX_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_RX_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_RX_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_RX_CAT            (IRQ_CAT1)
#define IRQ_QSPI4_RX_CAT            (IRQ_CAT1)
#define IRQ_QSPI5_RX_CAT            (IRQ_CAT1)

/* Qspi Rx interrupt Priority Setting*/
#define IRQ_QSPI0_RX_PRIO           0x0
#define IRQ_QSPI1_RX_PRIO           0x0
#define IRQ_QSPI2_RX_PRIO           0x0
#define IRQ_QSPI3_RX_PRIO           0x0
#define IRQ_QSPI4_RX_PRIO           0x0
#define IRQ_QSPI5_RX_PRIO           0x0

/* Qspi Rx interrupt type of service Setting*/
#define IRQ_QSPI0_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI4_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI5_RX_TOS            (IRQ_TOS_CPU0)

/* Qspi Err interrupt Category Setting*/
#define IRQ_QSPI0_ERR_CAT           (IRQ_CAT1)
#define IRQ_QSPI1_ERR_CAT           (IRQ_CAT1)
#define IRQ_QSPI2_ERR_CAT           (IRQ_CAT1)
#define IRQ_QSPI3_ERR_CAT           (IRQ_CAT1)
#define IRQ_QSPI4_ERR_CAT           (IRQ_CAT1)
#define IRQ_QSPI5_ERR_CAT           (IRQ_CAT1)

/* Qspi Err interrupt Priority Setting*/
#define IRQ_QSPI0_ERR_PRIO          0x0
#define IRQ_QSPI1_ERR_PRIO          0x0
#define IRQ_QSPI2_ERR_PRIO          0x0
#define IRQ_QSPI3_ERR_PRIO          0x0
#define IRQ_QSPI4_ERR_PRIO          0x0
#define IRQ_QSPI5_ERR_PRIO          0x0

/* Qspi Err interrupt type of service Setting*/
#define IRQ_QSPI0_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_QSPI1_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_QSPI2_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_QSPI3_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_QSPI4_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_QSPI5_ERR_TOS           (IRQ_TOS_CPU0)

/* Qspi PT interrupt Category Setting*/
#define IRQ_QSPI0_PT_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_PT_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_PT_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_PT_CAT            (IRQ_CAT1)
#define IRQ_QSPI4_PT_CAT            (IRQ_CAT1)
#define IRQ_QSPI5_PT_CAT            (IRQ_CAT1)

/* Qspi PT interrupt Priority Setting*/
#define IRQ_QSPI0_PT_PRIO           0x0
#define IRQ_QSPI1_PT_PRIO           0x0
#define IRQ_QSPI2_PT_PRIO           0x0
#define IRQ_QSPI3_PT_PRIO           0x0
#define IRQ_QSPI4_PT_PRIO           0x0
#define IRQ_QSPI5_PT_PRIO           0x0

/* Qspi PT interrupt type of service Setting*/
#define IRQ_QSPI0_PT_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_PT_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_PT_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_PT_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI4_PT_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI5_PT_TOS            (IRQ_TOS_CPU0)

/* Qspi HC interrupt Category Setting*/
#define IRQ_QSPI2_HC_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_HC_CAT            (IRQ_CAT1)

/* Qspi HC interrupt Priority Setting*/
#define IRQ_QSPI2_HC_PRIO           0x0
#define IRQ_QSPI3_HC_PRIO           0x0

/* Qspi HC interrupt type of service Setting*/
#define IRQ_QSPI2_HC_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_HC_TOS            (IRQ_TOS_CPU0)

/* Qspi UD interrupt Category Setting*/
#define IRQ_QSPI0_UD_CAT            (IRQ_CAT1)
#define IRQ_QSPI1_UD_CAT            (IRQ_CAT1)
#define IRQ_QSPI2_UD_CAT            (IRQ_CAT1)
#define IRQ_QSPI3_UD_CAT            (IRQ_CAT1)
#define IRQ_QSPI4_UD_CAT            (IRQ_CAT1)
#define IRQ_QSPI5_UD_CAT            (IRQ_CAT1)

/* Qspi UD interrupt Priority Setting*/
#define IRQ_QSPI0_UD_PRIO           0x0
#define IRQ_QSPI1_UD_PRIO           0x0
#define IRQ_QSPI2_UD_PRIO           0x0
#define IRQ_QSPI3_UD_PRIO           0x0
#define IRQ_QSPI4_UD_PRIO           0x0
#define IRQ_QSPI5_UD_PRIO           0x0

/* Qspi UD interrupt type of service Setting*/
#define IRQ_QSPI0_UD_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI1_UD_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI2_UD_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI3_UD_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI4_UD_TOS            (IRQ_TOS_CPU0)
#define IRQ_QSPI5_UD_TOS            (IRQ_TOS_CPU0)

/*
Container : IrqDMAinterruptConfiguration
*/
/* DMA interrupt Category settings */
#define IRQ_DMA_CHANNEL0_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL100_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL101_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL102_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL103_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL104_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL105_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL106_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL107_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL108_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL109_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL10_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL110_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL111_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL112_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL113_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL114_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL115_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL116_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL117_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL118_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL119_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL11_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL120_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL121_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL122_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL123_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL124_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL125_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL126_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL127_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL12_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL13_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL14_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL15_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL16_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL17_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL18_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL19_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL1_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL20_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL21_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL22_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL23_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL24_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL25_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL26_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL27_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL28_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL29_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL2_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL30_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL31_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL32_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL33_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL34_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL35_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL36_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL37_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL38_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL39_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL3_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL40_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL41_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL42_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL43_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL44_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL45_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL46_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL47_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL48_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL49_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL4_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL50_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL51_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL52_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL53_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL54_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL55_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL56_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL57_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL58_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL59_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL5_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL60_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL61_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL62_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL63_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL64_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL65_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL66_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL67_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL68_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL69_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL6_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL70_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL71_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL72_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL73_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL74_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL75_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL76_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL77_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL78_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL79_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL7_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL80_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL81_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL82_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL83_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL84_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL85_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL86_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL87_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL88_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL89_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL8_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_CHANNEL90_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL91_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL92_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL93_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL94_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL95_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL96_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL97_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL98_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL99_SR_CAT     (IRQ_CAT1)
#define IRQ_DMA_CHANNEL9_SR_CAT      (IRQ_CAT1)
#define IRQ_DMA_ERR0_SR_CAT           (IRQ_CAT1)
#define IRQ_DMA_ERR1_SR_CAT           (IRQ_CAT1)
#define IRQ_DMA_ERR2_SR_CAT           (IRQ_CAT1)
#define IRQ_DMA_ERR3_SR_CAT           (IRQ_CAT1)

/* DMA interrupt Priority settings */
#define IRQ_DMA_CHANNEL0_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL100_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL101_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL102_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL103_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL104_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL105_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL106_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL107_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL108_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL109_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL10_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL110_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL111_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL112_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL113_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL114_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL115_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL116_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL117_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL118_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL119_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL11_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL120_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL121_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL122_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL123_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL124_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL125_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL126_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL127_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL12_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL13_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL14_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL15_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL16_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL17_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL18_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL19_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL1_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL20_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL21_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL22_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL23_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL24_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL25_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL26_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL27_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL28_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL29_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL2_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL30_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL31_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL32_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL33_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL34_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL35_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL36_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL37_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL38_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL39_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL3_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL40_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL41_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL42_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL43_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL44_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL45_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL46_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL47_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL48_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL49_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL4_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL50_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL51_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL52_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL53_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL54_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL55_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL56_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL57_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL58_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL59_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL5_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL60_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL61_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL62_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL63_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL64_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL65_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL66_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL67_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL68_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL69_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL6_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL70_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL71_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL72_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL73_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL74_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL75_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL76_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL77_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL78_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL79_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL7_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL80_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL81_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL82_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL83_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL84_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL85_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL86_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL87_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL88_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL89_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL8_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL90_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL91_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL92_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL93_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL94_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL95_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL96_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL97_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL98_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL99_SR_PRIO    0x0
#define IRQ_DMA_CHANNEL9_SR_PRIO    0x0
#define IRQ_DMA_ERR0_SR_PRIO          0x0
#define IRQ_DMA_ERR1_SR_PRIO          0x0
#define IRQ_DMA_ERR2_SR_PRIO          0x0
#define IRQ_DMA_ERR3_SR_PRIO          0x0

/* DMA interrupt type of service settings */
#define IRQ_DMA_CHANNEL0_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL100_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL101_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL102_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL103_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL104_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL105_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL106_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL107_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL108_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL109_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL10_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL110_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL111_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL112_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL113_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL114_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL115_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL116_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL117_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL118_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL119_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL11_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL120_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL121_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL122_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL123_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL124_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL125_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL126_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL127_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL12_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL13_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL14_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL15_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL16_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL17_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL18_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL19_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL1_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL20_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL21_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL22_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL23_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL24_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL25_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL26_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL27_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL28_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL29_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL2_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL30_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL31_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL32_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL33_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL34_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL35_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL36_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL37_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL38_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL39_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL3_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL40_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL41_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL42_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL43_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL44_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL45_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL46_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL47_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL48_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL49_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL4_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL50_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL51_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL52_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL53_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL54_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL55_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL56_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL57_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL58_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL59_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL5_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL60_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL61_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL62_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL63_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL64_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL65_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL66_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL67_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL68_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL69_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL6_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL70_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL71_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL72_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL73_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL74_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL75_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL76_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL77_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL78_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL79_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL7_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL80_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL81_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL82_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL83_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL84_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL85_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL86_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL87_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL88_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL89_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL8_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL90_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL91_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL92_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL93_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL94_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL95_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL96_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL97_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL98_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL99_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_CHANNEL9_SR_TOS     (IRQ_TOS_CPU0)
#define IRQ_DMA_ERR0_SR_TOS           (IRQ_TOS_CPU0)
#define IRQ_DMA_ERR1_SR_TOS           (IRQ_TOS_CPU0)
#define IRQ_DMA_ERR2_SR_TOS           (IRQ_TOS_CPU0)
#define IRQ_DMA_ERR3_SR_TOS           (IRQ_TOS_CPU0)


/*
Container : IrqGPSRGroupinterruptConfiguration
*/
/* GPSRGROUP0 interrupt Category Setting */
#define IRQ_GPSRGROUP0_SR0_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR1_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR2_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR3_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR4_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR5_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR6_CAT      (IRQ_CAT1)
#define IRQ_GPSRGROUP0_SR7_CAT      (IRQ_CAT1)

/* GPSRGROUP0 interrupt Priority Setting */
#define IRQ_GPSRGROUP0_SR0_PRIO     0x0
#define IRQ_GPSRGROUP0_SR1_PRIO     0x0
#define IRQ_GPSRGROUP0_SR2_PRIO     0x0
#define IRQ_GPSRGROUP0_SR3_PRIO     0x0
#define IRQ_GPSRGROUP0_SR4_PRIO     0x0
#define IRQ_GPSRGROUP0_SR5_PRIO     0x0
#define IRQ_GPSRGROUP0_SR6_PRIO     0x0
#define IRQ_GPSRGROUP0_SR7_PRIO     0x0

/* GPSRGROUP0 interrupt type of service Setting */
#define IRQ_GPSRGROUP0_SR0_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR1_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR2_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR3_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR4_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR5_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR6_TOS      (IRQ_TOS_CPU0)
#define IRQ_GPSRGROUP0_SR7_TOS      (IRQ_TOS_CPU0)







/*
Container : IrqFLEXRAYinterruptConfiguration
*/
/* FLEXRAY0 interrupt Category Setting */
#define IRQ_FLEXRAY0_IBusy_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_INT0_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_INT1_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_MBSC0_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_MBSC1_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_NewData0_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_NewData1_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_OBusy_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_TimerInt0_CAT         (IRQ_CAT1)
#define IRQ_FLEXRAY0_TimerInt1_CAT         (IRQ_CAT1)

/* FLEXRAY0 interrupt Priority Setting */
#define IRQ_FLEXRAY0_IBusy_PRIO         0x0
#define IRQ_FLEXRAY0_INT0_PRIO         0x0
#define IRQ_FLEXRAY0_INT1_PRIO         0x0
#define IRQ_FLEXRAY0_MBSC0_PRIO         0x0
#define IRQ_FLEXRAY0_MBSC1_PRIO         0x0
#define IRQ_FLEXRAY0_NewData0_PRIO         0x0
#define IRQ_FLEXRAY0_NewData1_PRIO         0x0
#define IRQ_FLEXRAY0_OBusy_PRIO         0x0
#define IRQ_FLEXRAY0_TimerInt0_PRIO         0x0
#define IRQ_FLEXRAY0_TimerInt1_PRIO         0x0

/* FLEXRAY0 interrupt type of service Setting */
#define IRQ_FLEXRAY0_IBusy_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_INT0_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_INT1_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_MBSC0_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_MBSC1_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_NewData0_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_NewData1_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_OBusy_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_TimerInt0_TOS         (IRQ_TOS_CPU0)
#define IRQ_FLEXRAY0_TimerInt1_TOS         (IRQ_TOS_CPU0)



/*
Container : Scu interrupt Configuration
*/
/* Scu interrupt Category Setting*/
#define IRQ_SCU_ERU_SR0_CAT         (IRQ_CAT1)
#define IRQ_SCU_ERU_SR1_CAT         (IRQ_CAT1)
#define IRQ_SCU_ERU_SR2_CAT         (IRQ_CAT1)
#define IRQ_SCU_ERU_SR3_CAT         (IRQ_CAT1)

/* Scu interrupt Priority Setting*/
#define IRQ_SCU_ERU_SR0_PRIO        0x0
#define IRQ_SCU_ERU_SR1_PRIO        0x0
#define IRQ_SCU_ERU_SR2_PRIO        0x0
#define IRQ_SCU_ERU_SR3_PRIO        0x0

/* Scu interrupt type of service Setting*/
#define IRQ_SCU_ERU_SR0_TOS         (IRQ_TOS_CPU0)
#define IRQ_SCU_ERU_SR1_TOS         (IRQ_TOS_CPU0)
#define IRQ_SCU_ERU_SR2_TOS         (IRQ_TOS_CPU0)
#define IRQ_SCU_ERU_SR3_TOS         (IRQ_TOS_CPU0)

/*
Container : IrqCCU6 interruptConfiguration
*/
/*CCU60 interrupt Category setting */
#define IRQ_CCU60_SR0_CAT           (IRQ_CAT1)
#define IRQ_CCU60_SR1_CAT           (IRQ_CAT1)
#define IRQ_CCU60_SR2_CAT           (IRQ_CAT1)
#define IRQ_CCU60_SR3_CAT           (IRQ_CAT1)

/*CCU60 interrupt Priority setting */
#define IRQ_CCU60_SR0_PRIO          0x0
#define IRQ_CCU60_SR1_PRIO          0x0
#define IRQ_CCU60_SR2_PRIO          0x0
#define IRQ_CCU60_SR3_PRIO          0x0

/*CCU60 interrupt type of service setting */
#define IRQ_CCU60_SR0_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU60_SR1_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU60_SR2_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU60_SR3_TOS           (IRQ_TOS_CPU0)

/*CCU61 interrupt Category setting */
#define IRQ_CCU61_SR0_CAT           (IRQ_CAT1)
#define IRQ_CCU61_SR1_CAT           (IRQ_CAT1)
#define IRQ_CCU61_SR2_CAT           (IRQ_CAT1)
#define IRQ_CCU61_SR3_CAT           (IRQ_CAT1)

/*CCU61 interrupt Priority setting */
#define IRQ_CCU61_SR0_PRIO          0xb4
#define IRQ_CCU61_SR1_PRIO          0x0
#define IRQ_CCU61_SR2_PRIO          0x0
#define IRQ_CCU61_SR3_PRIO          0x0

/*CCU61 interrupt type of service setting */
#define IRQ_CCU61_SR0_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU61_SR1_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU61_SR2_TOS           (IRQ_TOS_CPU0)
#define IRQ_CCU61_SR3_TOS           (IRQ_TOS_CPU0)

/*
Container : DMU interrupt Configuration
*/
/* DMU interrupt Category Setting*/
#define IRQ_DMU_FSI_CAT            (IRQ_CAT1)
#define IRQ_DMU_HOST_CAT            (IRQ_CAT1)

/* DMU interrupt Category Setting*/
#define IRQ_DMU_FSI_PRIO           0x0
#define IRQ_DMU_HOST_PRIO           0x0

/* DMU interrupt type of service Setting*/
#define IRQ_DMU_FSI_TOS            (IRQ_TOS_CPU0)
#define IRQ_DMU_HOST_TOS            (IRQ_TOS_CPU0)



/*
Container : IrqCaninterruptConfiguration
*/
/* CAN0 interrupt Category Setting */
#define IRQ_CAN0_SR0_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR10_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR11_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR12_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR13_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR14_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR15_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR1_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR2_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR3_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR4_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR5_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR6_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR7_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR8_CAT      (IRQ_CAT1)
#define IRQ_CAN0_SR9_CAT      (IRQ_CAT1)

/* CAN0 interrupt Priority Setting */
#define IRQ_CAN0_SR0_PRIO     0xf
#define IRQ_CAN0_SR10_PRIO     0x0
#define IRQ_CAN0_SR11_PRIO     0x0
#define IRQ_CAN0_SR12_PRIO     0x0
#define IRQ_CAN0_SR13_PRIO     0x0
#define IRQ_CAN0_SR14_PRIO     0x0
#define IRQ_CAN0_SR15_PRIO     0x0
#define IRQ_CAN0_SR1_PRIO     0xb
#define IRQ_CAN0_SR2_PRIO     0x11
#define IRQ_CAN0_SR3_PRIO     0xd
#define IRQ_CAN0_SR4_PRIO     0x0
#define IRQ_CAN0_SR5_PRIO     0x0
#define IRQ_CAN0_SR6_PRIO     0x0
#define IRQ_CAN0_SR7_PRIO     0x0
#define IRQ_CAN0_SR8_PRIO     0x0
#define IRQ_CAN0_SR9_PRIO     0x0

/* CAN0 interrupt type of service Setting */
#define IRQ_CAN0_SR0_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR10_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR11_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR12_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR13_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR14_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR15_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR1_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR2_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR3_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR4_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR5_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR6_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR7_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR8_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN0_SR9_TOS      (IRQ_TOS_CPU0)

/* CAN1 interrupt Category Setting */
#define IRQ_CAN1_SR0_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR10_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR11_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR12_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR13_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR14_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR15_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR1_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR2_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR3_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR4_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR5_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR6_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR7_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR8_CAT      (IRQ_CAT1)
#define IRQ_CAN1_SR9_CAT      (IRQ_CAT1)

/* CAN1 interrupt Priority Setting */
#define IRQ_CAN1_SR0_PRIO     0xe
#define IRQ_CAN1_SR10_PRIO     0x0
#define IRQ_CAN1_SR11_PRIO     0x0
#define IRQ_CAN1_SR12_PRIO     0x0
#define IRQ_CAN1_SR13_PRIO     0x0
#define IRQ_CAN1_SR14_PRIO     0x0
#define IRQ_CAN1_SR15_PRIO     0x0
#define IRQ_CAN1_SR1_PRIO     0xa
#define IRQ_CAN1_SR2_PRIO     0x10
#define IRQ_CAN1_SR3_PRIO     0xc
#define IRQ_CAN1_SR4_PRIO     0x0
#define IRQ_CAN1_SR5_PRIO     0x0
#define IRQ_CAN1_SR6_PRIO     0x0
#define IRQ_CAN1_SR7_PRIO     0x0
#define IRQ_CAN1_SR8_PRIO     0x0
#define IRQ_CAN1_SR9_PRIO     0x0

/* CAN1 interrupt type of service Setting */
#define IRQ_CAN1_SR0_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR10_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR11_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR12_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR13_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR14_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR15_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR1_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR2_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR3_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR4_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR5_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR6_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR7_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR8_TOS      (IRQ_TOS_CPU0)
#define IRQ_CAN1_SR9_TOS      (IRQ_TOS_CPU0)






/*
Container : Irq ADC configuration
*/
/*ADC0 interrupt Category setting */
#define IRQ_ADC0_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC0_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC0_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC0_SR3_CAT            (IRQ_CAT1)

/*ADC0 interrupt Priority setting */
#define IRQ_ADC0_SR0_PRIO           0x13
#define IRQ_ADC0_SR1_PRIO           0x0
#define IRQ_ADC0_SR2_PRIO           0x0
#define IRQ_ADC0_SR3_PRIO           0x0

/*ADC0 interrupt type of service setting */
#define IRQ_ADC0_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC0_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC0_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC0_SR3_TOS            (IRQ_TOS_CPU0)

/*ADC1 interrupt Category setting */
#define IRQ_ADC1_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC1_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC1_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC1_SR3_CAT            (IRQ_CAT1)

/*ADC1 interrupt Priority setting */
#define IRQ_ADC1_SR0_PRIO           0x0
#define IRQ_ADC1_SR1_PRIO           0x0
#define IRQ_ADC1_SR2_PRIO           0x0
#define IRQ_ADC1_SR3_PRIO           0x0

/*ADC1 interrupt type of service setting */
#define IRQ_ADC1_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC1_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC1_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC1_SR3_TOS            (IRQ_TOS_CPU0)







/*ADC8 interrupt Category setting */
#define IRQ_ADC8_SR0_CAT            (IRQ_CAT1)
#define IRQ_ADC8_SR1_CAT            (IRQ_CAT1)
#define IRQ_ADC8_SR2_CAT            (IRQ_CAT1)
#define IRQ_ADC8_SR3_CAT            (IRQ_CAT1)

/*ADC8 interrupt Priority setting */
#define IRQ_ADC8_SR0_PRIO           0x0
#define IRQ_ADC8_SR1_PRIO           0x0
#define IRQ_ADC8_SR2_PRIO           0x0
#define IRQ_ADC8_SR3_PRIO           0x0

/*ADC8 interrupt type of service setting */
#define IRQ_ADC8_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC8_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC8_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_ADC8_SR3_TOS            (IRQ_TOS_CPU0)





/*ADC CG0 interrupt Category setting */
#define IRQ_ADCCG0_SR0_CAT          (IRQ_CAT1)
#define IRQ_ADCCG0_SR1_CAT          (IRQ_CAT1)
#define IRQ_ADCCG0_SR2_CAT          (IRQ_CAT1)
#define IRQ_ADCCG0_SR3_CAT          (IRQ_CAT1)

/*ADC CG0 interrupt Priority setting */
#define IRQ_ADCCG0_SR0_PRIO         0x0
#define IRQ_ADCCG0_SR1_PRIO         0x0
#define IRQ_ADCCG0_SR2_PRIO         0x0
#define IRQ_ADCCG0_SR3_PRIO         0x0

/*ADC CG0 interrupt type of service setting */
#define IRQ_ADCCG0_SR0_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG0_SR1_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG0_SR2_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG0_SR3_TOS          (IRQ_TOS_CPU0)

/*ADC CG1 interrupt Category setting */
#define IRQ_ADCCG1_SR0_CAT          (IRQ_CAT1)
#define IRQ_ADCCG1_SR1_CAT          (IRQ_CAT1)
#define IRQ_ADCCG1_SR2_CAT          (IRQ_CAT1)
#define IRQ_ADCCG1_SR3_CAT          (IRQ_CAT1)

/*ADC CG1 interrupt Priority setting */
#define IRQ_ADCCG1_SR0_PRIO         0x0
#define IRQ_ADCCG1_SR1_PRIO         0x0
#define IRQ_ADCCG1_SR2_PRIO         0x0
#define IRQ_ADCCG1_SR3_PRIO         0x0

/*ADC CG1 interrupt type of service setting */
#define IRQ_ADCCG1_SR0_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG1_SR1_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG1_SR2_TOS          (IRQ_TOS_CPU0)
#define IRQ_ADCCG1_SR3_TOS          (IRQ_TOS_CPU0)


/*
Container : Irq GTM interruptConfiguration
*/
/* GTM AEI interrupt Category Setting */
#define IRQ_GTM_AEI_CAT             (IRQ_CAT1)

/* GTM AEI interrupt Priority Setting */
#define IRQ_GTM_AEI_PRIO            0x0

/* GTM AEI interrupt type of service Setting */
#define IRQ_GTM_AEI_TOS             (IRQ_TOS_CPU0)

/* GTM ARU interrupt Category Setting */
#define IRQ_GTM_ARU_SR0_CAT         (IRQ_CAT1)
#define IRQ_GTM_ARU_SR1_CAT         (IRQ_CAT1)
#define IRQ_GTM_ARU_SR2_CAT         (IRQ_CAT1)

/* GTM ARU interrupt Priority Setting */
#define IRQ_GTM_ARU_SR0_PRIO        0x0
#define IRQ_GTM_ARU_SR1_PRIO        0x0
#define IRQ_GTM_ARU_SR2_PRIO        0x0

/* GTM ARU interrupt type of service Setting */
#define IRQ_GTM_ARU_SR0_TOS         (IRQ_TOS_CPU0)
#define IRQ_GTM_ARU_SR1_TOS         (IRQ_TOS_CPU0)
#define IRQ_GTM_ARU_SR2_TOS         (IRQ_TOS_CPU0)

/* GTM BRC interrupt Category Setting */
#define IRQ_GTM_BRC_CAT             (IRQ_CAT1)

/* GTM BRC interrupt Priority Setting */
#define IRQ_GTM_BRC_PRIO            0x0

/* GTM BRC interrupt type of service Setting */
#define IRQ_GTM_BRC_TOS             (IRQ_TOS_CPU0)

/* GTM CMP interrupt Category Setting */
#define IRQ_GTM_CMP_CAT             (IRQ_CAT1)

/* GTM CMP interrupt Priority Setting */
#define IRQ_GTM_CMP_PRIO            0x0

/* GTM CMP interrupt type of service Setting */
#define IRQ_GTM_CMP_TOS             (IRQ_TOS_CPU0)

/* GTM SPE interrupt Category Setting */
#define IRQ_GTM_SPE0_CAT            (IRQ_CAT1)
#define IRQ_GTM_SPE1_CAT            (IRQ_CAT1)
#define IRQ_GTM_SPE2_CAT            (IRQ_CAT1)
#define IRQ_GTM_SPE3_CAT            (IRQ_CAT1)
#define IRQ_GTM_SPE4_CAT            (IRQ_CAT1)
#define IRQ_GTM_SPE5_CAT            (IRQ_CAT1)

/* GTM SPE interrupt Priority Setting */
#define IRQ_GTM_SPE0_PRIO           0x0
#define IRQ_GTM_SPE1_PRIO           0x0
#define IRQ_GTM_SPE2_PRIO           0x0
#define IRQ_GTM_SPE3_PRIO           0x0
#define IRQ_GTM_SPE4_PRIO           0x0
#define IRQ_GTM_SPE5_PRIO           0x0

/* GTM SPE interrupt type of service Setting */
#define IRQ_GTM_SPE0_TOS            (IRQ_TOS_CPU0)
#define IRQ_GTM_SPE1_TOS            (IRQ_TOS_CPU0)
#define IRQ_GTM_SPE2_TOS            (IRQ_TOS_CPU0)
#define IRQ_GTM_SPE3_TOS            (IRQ_TOS_CPU0)
#define IRQ_GTM_SPE4_TOS            (IRQ_TOS_CPU0)
#define IRQ_GTM_SPE5_TOS            (IRQ_TOS_CPU0)





/* GTM ERR interrupt Category Setting */
#define IRQ_GTM_ERR_SR_CAT          (IRQ_CAT1)

/* GTM ERR interrupt Priority Setting */
#define IRQ_GTM_ERR_SR_PRIO         0x0

/* GTM ERR interrupt type of service Setting */
#define IRQ_GTM_ERR_SR_TOS          (IRQ_TOS_CPU0)

/* GTM TIM0 interrupt Category Setting */

#define IRQ_GTM_TIM0_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM0_SR7_CAT        (IRQ_CAT1)

/* GTM TIM0 interrupt Priority Setting */
#define IRQ_GTM_TIM0_SR0_PRIO       0x0
#define IRQ_GTM_TIM0_SR1_PRIO       0x0
#define IRQ_GTM_TIM0_SR2_PRIO       0x0
#define IRQ_GTM_TIM0_SR3_PRIO       0x0
#define IRQ_GTM_TIM0_SR4_PRIO       0x0
#define IRQ_GTM_TIM0_SR5_PRIO       0x0
#define IRQ_GTM_TIM0_SR6_PRIO       0x0
#define IRQ_GTM_TIM0_SR7_PRIO       0x0

/* GTM TIM0 interrupt type of service Setting */
#define IRQ_GTM_TIM0_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM0_SR7_TOS        (IRQ_TOS_CPU0)
/* GTM TIM1 interrupt Category Setting */

#define IRQ_GTM_TIM1_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TIM1_SR7_CAT        (IRQ_CAT1)

/* GTM TIM1 interrupt Priority Setting */
#define IRQ_GTM_TIM1_SR0_PRIO       0x0
#define IRQ_GTM_TIM1_SR1_PRIO       0x0
#define IRQ_GTM_TIM1_SR2_PRIO       0x0
#define IRQ_GTM_TIM1_SR3_PRIO       0x0
#define IRQ_GTM_TIM1_SR4_PRIO       0x0
#define IRQ_GTM_TIM1_SR5_PRIO       0x0
#define IRQ_GTM_TIM1_SR6_PRIO       0x0
#define IRQ_GTM_TIM1_SR7_PRIO       0x0

/* GTM TIM1 interrupt type of service Setting */
#define IRQ_GTM_TIM1_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TIM1_SR7_TOS        (IRQ_TOS_CPU0)


/* GTM TOM0 interrupt Category Setting */

#define IRQ_GTM_TOM0_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM0_SR7_CAT        (IRQ_CAT1)

/* GTM TOM0 interrupt Priority Setting */
#define IRQ_GTM_TOM0_SR0_PRIO       0xfa
#define IRQ_GTM_TOM0_SR1_PRIO       0x0
#define IRQ_GTM_TOM0_SR2_PRIO       0x0
#define IRQ_GTM_TOM0_SR3_PRIO       0x0
#define IRQ_GTM_TOM0_SR4_PRIO       0x0
#define IRQ_GTM_TOM0_SR5_PRIO       0x0
#define IRQ_GTM_TOM0_SR6_PRIO       0x0
#define IRQ_GTM_TOM0_SR7_PRIO       0x0

/* GTM TOM0 interrupt type of service Setting */
#define IRQ_GTM_TOM0_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM0_SR7_TOS        (IRQ_TOS_CPU0)
/* GTM TOM1 interrupt Category Setting */

#define IRQ_GTM_TOM1_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR3_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR4_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR5_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR6_CAT        (IRQ_CAT1)
#define IRQ_GTM_TOM1_SR7_CAT        (IRQ_CAT1)

/* GTM TOM1 interrupt Priority Setting */
#define IRQ_GTM_TOM1_SR0_PRIO       0x0
#define IRQ_GTM_TOM1_SR1_PRIO       0x0
#define IRQ_GTM_TOM1_SR2_PRIO       0x0
#define IRQ_GTM_TOM1_SR3_PRIO       0x0
#define IRQ_GTM_TOM1_SR4_PRIO       0x0
#define IRQ_GTM_TOM1_SR5_PRIO       0x0
#define IRQ_GTM_TOM1_SR6_PRIO       0x0
#define IRQ_GTM_TOM1_SR7_PRIO       0x0

/* GTM TOM1 interrupt type of service Setting */
#define IRQ_GTM_TOM1_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR3_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR4_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR5_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR6_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_TOM1_SR7_TOS        (IRQ_TOS_CPU0)

/* GTM ATOM0 interrupt Category Setting */

#define IRQ_GTM_ATOM0_SR0_CAT        (IRQ_CAT1)
#define IRQ_GTM_ATOM0_SR1_CAT        (IRQ_CAT1)
#define IRQ_GTM_ATOM0_SR2_CAT        (IRQ_CAT1)
#define IRQ_GTM_ATOM0_SR3_CAT        (IRQ_CAT1)

/* GTM ATOM0 interrupt Priority Setting */
#define IRQ_GTM_ATOM0_SR0_PRIO       0x0
#define IRQ_GTM_ATOM0_SR1_PRIO       0x0
#define IRQ_GTM_ATOM0_SR2_PRIO       0x7b
#define IRQ_GTM_ATOM0_SR3_PRIO       0x0

/* GTM ATOM0 interrupt type of service Setting */
#define IRQ_GTM_ATOM0_SR0_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM0_SR1_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM0_SR2_TOS        (IRQ_TOS_CPU0)
#define IRQ_GTM_ATOM0_SR3_TOS        (IRQ_TOS_CPU0)



/*
Container : IrqSTMinterruptConfiguration
*/
/* STM0 interrupt Category Setting */
#define IRQ_STM0_SR0_CAT            (IRQ_CAT1)
#define IRQ_STM0_SR1_CAT            (IRQ_CAT1)

/* STM0 interrupt Priority Setting */
#define IRQ_STM0_SR0_PRIO           0x64
#define IRQ_STM0_SR1_PRIO           0x65

/* STM0 interrupt type of service Setting */
#define IRQ_STM0_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_STM0_SR1_TOS            (IRQ_TOS_CPU0)







/*
Container : IrqAsclin interruptConfiguration
*/
/* Asclin Tx interrupt Category Setting*/
#define IRQ_ASCLIN0_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN10_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN11_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN12_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN13_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN14_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN15_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN16_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN17_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN18_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN19_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN1_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN20_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN21_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN22_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN23_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN2_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN3_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN4_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN5_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN6_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN7_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN8_TX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN9_TX_CAT            (IRQ_CAT1)

/* Asclin Tx interrupt Priority Setting*/
#define IRQ_ASCLIN0_TX_PRIO           0x0
#define IRQ_ASCLIN10_TX_PRIO           0x0
#define IRQ_ASCLIN11_TX_PRIO           0x0
#define IRQ_ASCLIN12_TX_PRIO           0x0
#define IRQ_ASCLIN13_TX_PRIO           0x0
#define IRQ_ASCLIN14_TX_PRIO           0x0
#define IRQ_ASCLIN15_TX_PRIO           0x0
#define IRQ_ASCLIN16_TX_PRIO           0x0
#define IRQ_ASCLIN17_TX_PRIO           0x0
#define IRQ_ASCLIN18_TX_PRIO           0x0
#define IRQ_ASCLIN19_TX_PRIO           0x0
#define IRQ_ASCLIN1_TX_PRIO           0x55
#define IRQ_ASCLIN20_TX_PRIO           0x0
#define IRQ_ASCLIN21_TX_PRIO           0x0
#define IRQ_ASCLIN22_TX_PRIO           0x0
#define IRQ_ASCLIN23_TX_PRIO           0x0
#define IRQ_ASCLIN2_TX_PRIO           0x58
#define IRQ_ASCLIN3_TX_PRIO           0x0
#define IRQ_ASCLIN4_TX_PRIO           0x0
#define IRQ_ASCLIN5_TX_PRIO           0x0
#define IRQ_ASCLIN6_TX_PRIO           0x0
#define IRQ_ASCLIN7_TX_PRIO           0x0
#define IRQ_ASCLIN8_TX_PRIO           0x0
#define IRQ_ASCLIN9_TX_PRIO           0x0

/* Asclin Tx interrupt type of service Setting*/
#define IRQ_ASCLIN0_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN10_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN11_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN12_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN13_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN14_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN15_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN16_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN17_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN18_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN19_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN1_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN20_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN21_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN22_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN23_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN2_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN3_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN4_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN5_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN6_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN7_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN8_TX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN9_TX_TOS            (IRQ_TOS_CPU0)

/* Asclin Rx interrupt Category Setting*/
#define IRQ_ASCLIN0_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN10_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN11_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN12_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN13_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN14_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN15_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN16_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN17_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN18_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN19_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN1_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN20_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN21_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN22_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN23_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN2_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN3_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN4_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN5_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN6_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN7_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN8_RX_CAT            (IRQ_CAT1)
#define IRQ_ASCLIN9_RX_CAT            (IRQ_CAT1)

/* Asclin Rx interrupt Priority Setting*/
#define IRQ_ASCLIN0_RX_PRIO           0x0
#define IRQ_ASCLIN10_RX_PRIO           0x0
#define IRQ_ASCLIN11_RX_PRIO           0x0
#define IRQ_ASCLIN12_RX_PRIO           0x0
#define IRQ_ASCLIN13_RX_PRIO           0x0
#define IRQ_ASCLIN14_RX_PRIO           0x0
#define IRQ_ASCLIN15_RX_PRIO           0x0
#define IRQ_ASCLIN16_RX_PRIO           0x0
#define IRQ_ASCLIN17_RX_PRIO           0x0
#define IRQ_ASCLIN18_RX_PRIO           0x0
#define IRQ_ASCLIN19_RX_PRIO           0x0
#define IRQ_ASCLIN1_RX_PRIO           0x56
#define IRQ_ASCLIN20_RX_PRIO           0x0
#define IRQ_ASCLIN21_RX_PRIO           0x0
#define IRQ_ASCLIN22_RX_PRIO           0x0
#define IRQ_ASCLIN23_RX_PRIO           0x0
#define IRQ_ASCLIN2_RX_PRIO           0x59
#define IRQ_ASCLIN3_RX_PRIO           0x0
#define IRQ_ASCLIN4_RX_PRIO           0x0
#define IRQ_ASCLIN5_RX_PRIO           0x0
#define IRQ_ASCLIN6_RX_PRIO           0x0
#define IRQ_ASCLIN7_RX_PRIO           0x0
#define IRQ_ASCLIN8_RX_PRIO           0x0
#define IRQ_ASCLIN9_RX_PRIO           0x0

/* Asclin Rx interrupt type of service Setting*/
#define IRQ_ASCLIN0_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN10_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN11_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN12_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN13_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN14_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN15_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN16_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN17_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN18_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN19_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN1_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN20_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN21_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN22_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN23_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN2_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN3_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN4_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN5_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN6_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN7_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN8_RX_TOS            (IRQ_TOS_CPU0)
#define IRQ_ASCLIN9_RX_TOS            (IRQ_TOS_CPU0)

/* Asclin Err interrupt Category Setting*/
#define IRQ_ASCLIN0_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN10_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN11_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN12_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN13_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN14_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN15_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN16_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN17_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN18_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN19_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN1_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN20_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN21_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN22_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN23_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN2_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN3_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN4_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN5_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN6_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN7_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN8_ERR_CAT           (IRQ_CAT1)
#define IRQ_ASCLIN9_ERR_CAT           (IRQ_CAT1)

/* Asclin Err interrupt Priority Setting*/
#define IRQ_ASCLIN0_ERR_PRIO          0x0
#define IRQ_ASCLIN10_ERR_PRIO          0x0
#define IRQ_ASCLIN11_ERR_PRIO          0x0
#define IRQ_ASCLIN12_ERR_PRIO          0x0
#define IRQ_ASCLIN13_ERR_PRIO          0x0
#define IRQ_ASCLIN14_ERR_PRIO          0x0
#define IRQ_ASCLIN15_ERR_PRIO          0x0
#define IRQ_ASCLIN16_ERR_PRIO          0x0
#define IRQ_ASCLIN17_ERR_PRIO          0x0
#define IRQ_ASCLIN18_ERR_PRIO          0x0
#define IRQ_ASCLIN19_ERR_PRIO          0x0
#define IRQ_ASCLIN1_ERR_PRIO          0x57
#define IRQ_ASCLIN20_ERR_PRIO          0x0
#define IRQ_ASCLIN21_ERR_PRIO          0x0
#define IRQ_ASCLIN22_ERR_PRIO          0x0
#define IRQ_ASCLIN23_ERR_PRIO          0x0
#define IRQ_ASCLIN2_ERR_PRIO          0x5a
#define IRQ_ASCLIN3_ERR_PRIO          0x0
#define IRQ_ASCLIN4_ERR_PRIO          0x0
#define IRQ_ASCLIN5_ERR_PRIO          0x0
#define IRQ_ASCLIN6_ERR_PRIO          0x0
#define IRQ_ASCLIN7_ERR_PRIO          0x0
#define IRQ_ASCLIN8_ERR_PRIO          0x0
#define IRQ_ASCLIN9_ERR_PRIO          0x0

/* Asclin Err interrupt type of service Setting*/
#define IRQ_ASCLIN0_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN10_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN11_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN12_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN13_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN14_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN15_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN16_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN17_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN18_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN19_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN1_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN20_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN21_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN22_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN23_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN2_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN3_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN4_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN5_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN6_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN7_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN8_ERR_TOS           (IRQ_TOS_CPU0)
#define IRQ_ASCLIN9_ERR_TOS           (IRQ_TOS_CPU0)


/*
Container : Irq HSSL configuration
*/











/*
Container : Irq SENT configuration
*/
/*Sent interrupt Category setting */
#define IRQ_SENT_SR0_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR1_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR2_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR3_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR4_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR5_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR6_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR7_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR8_CAT            (IRQ_CAT1)
#define IRQ_SENT_SR9_CAT            (IRQ_CAT1)

/*Sent interrupt Priority setting */
#define IRQ_SENT_SR0_PRIO           0x5
#define IRQ_SENT_SR1_PRIO           0x0
#define IRQ_SENT_SR2_PRIO           0x0
#define IRQ_SENT_SR3_PRIO           0x0
#define IRQ_SENT_SR4_PRIO           0x0
#define IRQ_SENT_SR5_PRIO           0x0
#define IRQ_SENT_SR6_PRIO           0x0
#define IRQ_SENT_SR7_PRIO           0x0
#define IRQ_SENT_SR8_PRIO           0x0
#define IRQ_SENT_SR9_PRIO           0x0

/*Sent interrupt type of service setting */
#define IRQ_SENT_SR0_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR1_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR2_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR3_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR4_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR5_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR6_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR7_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR8_TOS            (IRQ_TOS_CPU0)
#define IRQ_SENT_SR9_TOS            (IRQ_TOS_CPU0)




/*
Container : I2C interrupt Configuration
*/
/* I2C interrupt Category Setting*/
#define IRQ_I2C_DTR_SR0_CAT         (IRQ_CAT1)
#define IRQ_I2C_DTR_SR1_CAT         (IRQ_CAT1)


#define IRQ_I2C_ERR_SR0_CAT         (IRQ_CAT1)
#define IRQ_I2C_ERR_SR1_CAT         (IRQ_CAT1)


#define IRQ_I2C_P_SR0_CAT           (IRQ_CAT1)
#define IRQ_I2C_P_SR1_CAT           (IRQ_CAT1)


/* I2C Dtr interrupt Priority Setting*/
#define IRQ_I2C_DTR_SR0_PRIO           0x0
#define IRQ_I2C_DTR_SR1_PRIO           0x0


/* I2C Err interrupt Priority Setting*/
#define IRQ_I2C_ERR_SR0_PRIO           0x0
#define IRQ_I2C_ERR_SR1_PRIO           0x0


/* I2C Protocol interrupt Priority Setting*/
#define IRQ_I2C_P_SR0_PRIO             0x0
#define IRQ_I2C_P_SR1_PRIO             0x0

/* I2C Err interrupt type of service setting */
#define IRQ_I2C_DTR_SR0_TOS           (IRQ_TOS_CPU0)
#define IRQ_I2C_DTR_SR1_TOS           (IRQ_TOS_CPU0)

/* I2C Err interrupt type of service setting */
#define IRQ_I2C_ERR_SR0_TOS           (IRQ_TOS_CPU0)
#define IRQ_I2C_ERR_SR1_TOS           (IRQ_TOS_CPU0)

/* I2C Err interrupt type of service setting */
#define IRQ_I2C_P_SR0_TOS           (IRQ_TOS_CPU0)
#define IRQ_I2C_P_SR1_TOS           (IRQ_TOS_CPU0)


#define IRQ_QSPI_EXIST              (STD_ON)
#define IRQ_QSPI0_EXIST             (STD_ON)
#define IRQ_QSPI1_EXIST             (STD_ON)
#define IRQ_QSPI2_EXIST             (STD_ON)
#define IRQ_QSPI3_EXIST             (STD_OFF)
#define IRQ_QSPI4_EXIST             (STD_OFF)
#define IRQ_QSPI5_EXIST             (STD_OFF)
#define IRQ_QSPI_HC_SRN_EXIST       (STD_OFF)


#define IRQ_CCU6_EXIST              (STD_ON)
#define IRQ_CCU60_EXIST             (STD_ON)
#define IRQ_CCU61_EXIST             (STD_ON)

#define IRQ_GPT12_EXIST               (STD_ON)
#define IRQ_GPT120_EXIST            (STD_ON)

#define IRQ_STM_EXIST               (STD_ON)
#define IRQ_STM0_EXIST              (STD_ON)
#define IRQ_STM1_EXIST              (STD_OFF)
#define IRQ_STM2_EXIST              (STD_OFF)
#define IRQ_STM3_EXIST              (STD_OFF)
#define IRQ_STM4_EXIST              (STD_OFF)
#define IRQ_STM5_EXIST              (STD_OFF)

#define IRQ_DMA_EXIST               (STD_ON)
#define IRQ_DMA_ERR0TO3_EXIST       (STD_ON)
#define IRQ_DMA_CH0TO15_EXIST       (STD_ON)
#define IRQ_DMA_CH16TO63_EXIST      (STD_ON)
#define IRQ_DMA_CH64TO127_EXIST     (STD_OFF)

#define IRQ_GETH_EXIST               (STD_OFF)
#define IRQ_GETH0_EXIST               (STD_OFF)
#define IRQ_GETH0_0_EXIST              (STD_OFF)
#define IRQ_GETH0_1_EXIST              (STD_OFF)
#define IRQ_GETH0_2_EXIST              (STD_OFF)
#define IRQ_GETH0_3_EXIST              (STD_OFF)
#define IRQ_GETH0_4_EXIST              (STD_OFF)
#define IRQ_GETH0_5_EXIST              (STD_OFF)
#define IRQ_GETH0_6_EXIST              (STD_OFF)
#define IRQ_GETH0_7_EXIST              (STD_OFF)
#define IRQ_GETH0_8_EXIST              (STD_OFF)
#define IRQ_GETH0_9_EXIST              (STD_OFF)

#define IRQ_GETH1_EXIST               (STD_OFF)


#define IRQ_CAN_EXIST               (STD_OFF)
#define IRQ_CAN0_EXIST              (STD_OFF)
#define IRQ_CAN1_EXIST              (STD_OFF)
#define IRQ_CAN2_EXIST              (STD_OFF)
#define IRQ_CAN3_EXIST              (STD_OFF)
#define IRQ_CAN4_EXIST              (STD_OFF)


#define IRQ_CAN0SRN0_EXIST              (STD_OFF)
#define IRQ_CAN0SRN1_EXIST              (STD_OFF)
#define IRQ_CAN0SRN2_EXIST              (STD_OFF)
#define IRQ_CAN0SRN3_EXIST              (STD_OFF)
#define IRQ_CAN0SRN4_EXIST              (STD_OFF)
#define IRQ_CAN0SRN5_EXIST              (STD_OFF)
#define IRQ_CAN0SRN6_EXIST              (STD_OFF)
#define IRQ_CAN0SRN7_EXIST              (STD_OFF)
#define IRQ_CAN0SRN8_EXIST              (STD_OFF)
#define IRQ_CAN0SRN9_EXIST              (STD_OFF)
#define IRQ_CAN0SRN10_EXIST             (STD_OFF)
#define IRQ_CAN0SRN11_EXIST             (STD_OFF)
#define IRQ_CAN0SRN12_EXIST             (STD_OFF)
#define IRQ_CAN0SRN13_EXIST             (STD_OFF)
#define IRQ_CAN0SRN14_EXIST             (STD_OFF)
#define IRQ_CAN0SRN15_EXIST             (STD_OFF)


#define IRQ_CAN1SRN0_EXIST              (STD_OFF)
#define IRQ_CAN1SRN1_EXIST              (STD_OFF)
#define IRQ_CAN1SRN2_EXIST              (STD_OFF)
#define IRQ_CAN1SRN3_EXIST              (STD_OFF)
#define IRQ_CAN1SRN4_EXIST              (STD_OFF)
#define IRQ_CAN1SRN5_EXIST              (STD_OFF)
#define IRQ_CAN1SRN6_EXIST              (STD_OFF)
#define IRQ_CAN1SRN7_EXIST              (STD_OFF)
#define IRQ_CAN1SRN8_EXIST              (STD_OFF)
#define IRQ_CAN1SRN9_EXIST              (STD_OFF)
#define IRQ_CAN1SRN10_EXIST             (STD_OFF)
#define IRQ_CAN1SRN11_EXIST             (STD_OFF)
#define IRQ_CAN1SRN12_EXIST             (STD_OFF)
#define IRQ_CAN1SRN13_EXIST             (STD_OFF)
#define IRQ_CAN1SRN14_EXIST             (STD_OFF)
#define IRQ_CAN1SRN15_EXIST             (STD_OFF)

#define IRQ_CAN2SRN0_EXIST              (STD_OFF)
#define IRQ_CAN2SRN1_EXIST              (STD_OFF)
#define IRQ_CAN2SRN2_EXIST              (STD_OFF)
#define IRQ_CAN2SRN3_EXIST              (STD_OFF)
#define IRQ_CAN2SRN4_EXIST              (STD_OFF)
#define IRQ_CAN2SRN5_EXIST              (STD_OFF)
#define IRQ_CAN2SRN6_EXIST              (STD_OFF)
#define IRQ_CAN2SRN7_EXIST              (STD_OFF)
#define IRQ_CAN2SRN8_EXIST              (STD_OFF)
#define IRQ_CAN2SRN9_EXIST              (STD_OFF)
#define IRQ_CAN2SRN10_EXIST             (STD_OFF)
#define IRQ_CAN2SRN11_EXIST             (STD_OFF)
#define IRQ_CAN2SRN12_EXIST             (STD_OFF)
#define IRQ_CAN2SRN13_EXIST             (STD_OFF)
#define IRQ_CAN2SRN14_EXIST             (STD_OFF)
#define IRQ_CAN2SRN15_EXIST             (STD_OFF)


#define IRQ_CAN3SRN0_EXIST              (STD_OFF)
#define IRQ_CAN3SRN1_EXIST              (STD_OFF)
#define IRQ_CAN3SRN2_EXIST              (STD_OFF)
#define IRQ_CAN3SRN3_EXIST              (STD_OFF)
#define IRQ_CAN3SRN4_EXIST              (STD_OFF)
#define IRQ_CAN3SRN5_EXIST              (STD_OFF)
#define IRQ_CAN3SRN6_EXIST              (STD_OFF)
#define IRQ_CAN3SRN7_EXIST              (STD_OFF)
#define IRQ_CAN3SRN8_EXIST              (STD_OFF)
#define IRQ_CAN3SRN9_EXIST              (STD_OFF)
#define IRQ_CAN3SRN10_EXIST             (STD_OFF)
#define IRQ_CAN3SRN11_EXIST             (STD_OFF)
#define IRQ_CAN3SRN12_EXIST             (STD_OFF)
#define IRQ_CAN3SRN13_EXIST             (STD_OFF)
#define IRQ_CAN3SRN14_EXIST             (STD_OFF)
#define IRQ_CAN3SRN15_EXIST             (STD_OFF)

#define IRQ_CAN4SRN0_EXIST              (STD_OFF)
#define IRQ_CAN4SRN1_EXIST              (STD_OFF)
#define IRQ_CAN4SRN2_EXIST              (STD_OFF)
#define IRQ_CAN4SRN3_EXIST              (STD_OFF)
#define IRQ_CAN4SRN4_EXIST              (STD_OFF)
#define IRQ_CAN4SRN5_EXIST              (STD_OFF)
#define IRQ_CAN4SRN6_EXIST              (STD_OFF)
#define IRQ_CAN4SRN7_EXIST              (STD_OFF)
#define IRQ_CAN4SRN8_EXIST              (STD_OFF)
#define IRQ_CAN4SRN9_EXIST              (STD_OFF)
#define IRQ_CAN4SRN10_EXIST             (STD_OFF)
#define IRQ_CAN4SRN11_EXIST             (STD_OFF)
#define IRQ_CAN4SRN12_EXIST             (STD_OFF)
#define IRQ_CAN4SRN13_EXIST             (STD_OFF)
#define IRQ_CAN4SRN14_EXIST             (STD_OFF)
#define IRQ_CAN4SRN15_EXIST             (STD_OFF)


#define IRQ_ADC_EXIST               (STD_OFF)
#define IRQ_ADC0_EXIST              (STD_OFF)
#define IRQ_ADC1_EXIST              (STD_OFF)
#define IRQ_ADC2_EXIST              (STD_OFF)
#define IRQ_ADC3_EXIST              (STD_OFF)
#define IRQ_ADC4_EXIST              (STD_OFF)
#define IRQ_ADC5_EXIST              (STD_OFF)
#define IRQ_ADC6_EXIST              (STD_OFF)
#define IRQ_ADC7_EXIST              (STD_OFF)
#define IRQ_ADC8_EXIST              (STD_OFF)
#define IRQ_ADC9_EXIST              (STD_OFF)
#define IRQ_ADC10_EXIST             (STD_OFF)
#define IRQ_ADC11_EXIST             (STD_OFF)
#define IRQ_ADCCG0_EXIST            (STD_OFF)
#define IRQ_ADCCG1_EXIST            (STD_OFF)



#define IRQ_FLEXRAY_EXIST           (STD_OFF)
#define IRQ_FLEXRAY0_EXIST          (STD_OFF)
#define IRQ_FLEXRAY1_EXIST          (STD_OFF)

#define IRQ_DMU_EXIST              (STD_ON)
#define IRQ_DMU_HOST_EXIST          (STD_ON)
#define IRQ_DMU_FSI_EXIST          (STD_ON)

#define IRQ_SCU_EXIST               (STD_ON)

#define IRQ_GPSRGROUP_EXIST         (STD_ON)
#define IRQ_GPSRGROUP0_EXIST        (STD_ON)
#define IRQ_GPSRGROUP1_EXIST        (STD_OFF)
#define IRQ_GPSRGROUP2_EXIST        (STD_OFF)
#define IRQ_GPSRGROUP3_EXIST        (STD_OFF)
#define IRQ_GPSRGROUP4_EXIST        (STD_OFF)
#define IRQ_GPSRGROUP5_EXIST        (STD_OFF)


/* Global macros that determines whether a module / SRN is in use or not
*/




#define IRQ_ASCLIN_EXIST              (STD_OFF)
#define IRQ_ASCLIN0_EXIST             (STD_OFF)
#define IRQ_ASCLIN1_EXIST             (STD_OFF)
#define IRQ_ASCLIN2_EXIST             (STD_OFF)
#define IRQ_ASCLIN3_EXIST             (STD_OFF)
#define IRQ_ASCLIN4_EXIST             (STD_OFF)
#define IRQ_ASCLIN5_EXIST             (STD_OFF)
#define IRQ_ASCLIN6_EXIST             (STD_OFF)
#define IRQ_ASCLIN7_EXIST             (STD_OFF)

#define IRQ_ASCLIN8_EXIST             (STD_OFF)
#define IRQ_ASCLIN9_EXIST             (STD_OFF)
#define IRQ_ASCLIN10_EXIST             (STD_OFF)
#define IRQ_ASCLIN11_EXIST             (STD_OFF)
#define IRQ_ASCLIN12_EXIST             (STD_OFF)
#define IRQ_ASCLIN13_EXIST             (STD_OFF)
#define IRQ_ASCLIN14_EXIST             (STD_OFF)
#define IRQ_ASCLIN15_EXIST             (STD_OFF)

#define IRQ_ASCLIN16_EXIST             (STD_OFF)
#define IRQ_ASCLIN17_EXIST             (STD_OFF)
#define IRQ_ASCLIN18_EXIST             (STD_OFF)
#define IRQ_ASCLIN19_EXIST             (STD_OFF)
#define IRQ_ASCLIN20_EXIST             (STD_OFF)
#define IRQ_ASCLIN21_EXIST             (STD_OFF)
#define IRQ_ASCLIN22_EXIST             (STD_OFF)
#define IRQ_ASCLIN23_EXIST             (STD_OFF)

/* Global macros that determines whether a module / SRN is in use or not
*/
#define IRQ_HSSL_EXIST              (STD_OFF)
#define IRQ_HSSL0_EXIST             (STD_OFF)
#define IRQ_HSSL1_EXIST             (STD_OFF)


#define IRQ_SENT_EXIST               (STD_OFF)

#define IRQ_DSADC_EXIST               (STD_OFF)

#define IRQ_DSADC_SRM0_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM1_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM2_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM3_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM4_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM5_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM6_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM7_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM8_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM9_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM10_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM11_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM12_EXIST             (STD_OFF)
#define IRQ_DSADC_SRM13_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA0_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA1_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA2_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA3_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA4_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA5_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA6_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA7_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA8_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA9_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA10_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA11_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA12_EXIST             (STD_OFF)
#define IRQ_DSADC_SRA13_EXIST             (STD_OFF)


#define IRQ_GTM_EXIST               (STD_ON)
#define IRQ_GTM_AEI_EXIST           (STD_ON)
#define IRQ_GTM_ARU_EXIST           (STD_ON)
#define IRQ_GTM_BRC_EXIST           (STD_ON)
#define IRQ_GTM_CMP_EXIST           (STD_ON)
#define IRQ_GTM_SPE_EXIST           (STD_ON)
#define IRQ_GTM_SPE0_EXIST           (STD_ON)
#define IRQ_GTM_SPE1_EXIST           (STD_ON)
#define IRQ_GTM_SPE2_EXIST           (STD_OFF)
#define IRQ_GTM_SPE3_EXIST           (STD_OFF)
#define IRQ_GTM_SPE4_EXIST           (STD_OFF)
#define IRQ_GTM_SPE5_EXIST           (STD_OFF)
#define IRQ_GTM_PSM0_EXIST          (STD_OFF)
#define IRQ_GTM_PSM1_EXIST          (STD_OFF)
#define IRQ_GTM_PSM2_EXIST          (STD_OFF)
#define IRQ_GTM_DPLL_EXIST          (STD_OFF)
#define IRQ_GTM_ERR_EXIST           (STD_ON)
#define IRQ_GTM_TIM0_EXIST          (STD_ON)
#define IRQ_GTM_TIM1_EXIST          (STD_ON)
#define IRQ_GTM_TIM2_EXIST          (STD_OFF)
#define IRQ_GTM_TIM3_EXIST          (STD_OFF)
#define IRQ_GTM_TIM4_EXIST          (STD_OFF)
#define IRQ_GTM_TIM5_EXIST          (STD_OFF)
#define IRQ_GTM_TIM6_EXIST          (STD_OFF)
#define IRQ_GTM_TIM7_EXIST          (STD_OFF)
#define IRQ_GTM_MCS0_EXIST          (STD_OFF)
#define IRQ_GTM_MCS1_EXIST          (STD_OFF)
#define IRQ_GTM_MCS2_EXIST          (STD_OFF)
#define IRQ_GTM_MCS3_EXIST          (STD_OFF)
#define IRQ_GTM_MCS4_EXIST          (STD_OFF)
#define IRQ_GTM_MCS5_EXIST          (STD_OFF)
#define IRQ_GTM_MCS6_EXIST          (STD_OFF)
#define IRQ_GTM_MCS7_EXIST          (STD_OFF)
#define IRQ_GTM_MCS8_EXIST          (STD_OFF)
#define IRQ_GTM_MCS9_EXIST          (STD_OFF)
#define IRQ_GTM_TOM0_EXIST          (STD_ON)
#define IRQ_GTM_TOM1_EXIST          (STD_ON)
#define IRQ_GTM_TOM2_EXIST          (STD_OFF)
#define IRQ_GTM_TOM3_EXIST          (STD_OFF)
#define IRQ_GTM_TOM4_EXIST          (STD_OFF)
#define IRQ_GTM_TOM5_EXIST          (STD_OFF)
#define IRQ_GTM_ATOM0_EXIST         (STD_ON)
#define IRQ_GTM_ATOM1_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM2_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM3_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM4_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM5_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM6_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM7_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM8_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM9_EXIST         (STD_OFF)
#define IRQ_GTM_ATOM10_EXIST        (STD_OFF)
#define IRQ_GTM_ATOM11_EXIST        (STD_OFF)
#define IRQ_GTM_MCSW_EXIST          (STD_OFF)


#define IRQ_I2C_EXIST               (STD_OFF)
#define IRQ_I2C0_EXIST          (STD_OFF)
#define IRQ_I2C1_EXIST          (STD_OFF)
/* IRQ_CFG_H */
#endif
