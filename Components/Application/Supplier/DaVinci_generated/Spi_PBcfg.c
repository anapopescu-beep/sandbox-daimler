
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
**  FILENAME  : Spi_PBCfg.c                                                   **
**                                                                            **
**  VERSION   : 17.0.0                                                        **
**                                                                            **
**  DATE, TIME: 2023-07-11, 10:53:38  !!!IGNORE-LINE!!!                   **
**                                                                            **
**  GENERATOR : Build b191017-0938      !!!IGNORE-LINE!!!                   **
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

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Module header file */
#include "Spi.h"
/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/
/* MISRA2012_RULE_4_9_JUSTIFICATION: More readble as macros. Code coplexity
reduces as well. */
#define Spi_BaudRateAndClockParam(TQ,LB,Q,A,B,C,CPH,CPOL,PAREN)                \
(                                                                  \
(uint32)(                                                         \
((uint32)TQ << 16U)|((uint32)LB << 30U)|((uint32)Q)|\
((uint32)A << 6U)|((uint32)B << 8U)|         \
((uint32)C << 10U)|((uint32)CPH << 12U)|        \
((uint32)CPOL << 13U)|((uint32)PAREN << 14U)     \
)                                                         \
)
/* MISRA2012_RULE_4_9_JUSTIFICATION: More readble as macros. Code coplexity
reduces as well. */
#define Spi_IdleLeadTrailParam(IPRE,IDLE,LPRE,LEAD,TPRE,TRAIL,PARTYP)          \
(                                                                  \
(uint32)(                                                         \
((uint32)IPRE << 1U)|((uint32)IDLE << 4U)|    \
((uint32)LPRE << 7U)|((uint32)LEAD << 10U)|   \
((uint32)TPRE << 13U)|((uint32)TRAIL << 16U)| \
((uint32)PARTYP << 19U)            \
)                                                         \
)
/*******************************************************************************
**                      Extern Declaration                                    **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/******************* GLOBAL CONFIGURATION MEMMAP SECTION *********************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32

/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
    
          
            
  /*Sequence Index Lookup*/
  static const uint8 SequenceLookupIndex[1] =
{
  /* Physical index value for Sequence SpiSequence_WDG_REFRESH Sequence ID 0 */
  0U  
};

  /*Job Index Lookup*/
static const uint16 JobLookupIndex[1] =
{
  /* Physical index value for Job SpiJob_0 Job ID 0 */
  0U  
};

  /*Channel Index Lookup*/
static const uint8 ChannelLookupIndex[1] =
{
  /* Physical index value for channel SpiChannel_WDG channel ID 0 */
  0U  
};

  /* Linked list for the Job[s] assigned to the sequence[s] Physical*/

static const Spi_JobType SpiSequence_WDG_REFRESH_JobLinkPtr_Physical[] =
{
  0U, /* Physical index value for Job SpiJob_0 Job ID 0 */
  
  SPI_JOB_DELIMITER
};
  /* Linked list for the channel[s] assigned to the job[s] Physical */

static const Spi_ChannelType SpiJob_0_ChannelLinkPtr_Physical[] =
{
  0U, /* Physical index value for Channel SpiChannel_WDG Channel ID 0 */
  
  SPI_CHANNEL_DELIMITER
};
    /* Linked list of sequence[s] with Job[s] shared  */
static const Spi_SequenceType SpiSequence_WDG_REFRESH_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/******************* GLOBAL CONFIGURATION MEMMAP SECTION *********************/
  
    
 /******************* CORE0 SEQUENCE CONFIGURATION MEMMAP SECTION *************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"

static const Spi_SequenceConfigType Spi_kSequenceConfig_Core0[] =
{
        /* Sequence:SpiSequence_WDG_REFRESH */
  {
    SpiConf_SpiSequence_SpiSequence_WDG_REFRESH,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_WDG_REFRESH_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_WDG_REFRESH_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
        /* Hw Module Used (b000001)*/
    0x01U,
            }};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 SEQUENCE CONFIGURATION MEMMAP SECTION END *************/
    
/******************* CORE0 JOB CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"

static const Spi_JobConfigType Spi_kJobConfig_Core0[] =
{
      /* Synchronous Job[s] */
  /* Job:SpiJob_0 */
  {
    SpiConf_SpiJob_SpiJob_0,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 2000000.0Hz */
    (0x13U), (0x00U),          /* TQ , LoopBack */
    (0x01U), (0x00U),          /*  Q , A        */
    (0x00U), (0x01U),          /*  B , C        */
    (0x01U), (0x00U),          /*  CPH , CPOL   */
    (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
    (0U), (1U), /* IPRE,IDLE:   IdleA/B delay = 5.0E-8s */
    (0U), (7U), /* LPRE,LEAD:   Lead delay    = 5.0E-8s */
    (0U), (5U),/* TPRE, TRAIL: Trail delay   = 5.0E-8s */
    (1U)
    ),
    SpiJob_0_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)0U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
    /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL4 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  }};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 JOB CONFIGURATION MemMap SECTION END *************/
    
/******************* CORE0 CHANNEL CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"

static const Spi_ChannelConfigType Spi_kChannelConfig_Core0[] =
{
      /* Synchronous Chnl[s] QSPI1 core0*/
  /* Channel:SpiChannel_WDG */
  {
    0x00000000U,     /* Default data */
    0x0002U,         /* Number of Data Elements */
    SPI_IB_CHANNEL,  /* Internal Buffer Channel */
    0x08U,            /* LSB[7], DataWidth=8[6:0] */
    SpiConf_SpiChannel_SpiChannel_WDG
  }};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 JOB CONFIGURATION MemMap SECTION END *************/
      /******************* CORE0 QSPI1 CONFIGURATION MEMMAP SECTION *************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/* QSPI1 */

static const Spi_QspiHwConfigType Spi_kQspiHwConfigQSPI1 =
{
  0x00100000U,               /* Active CS Level, SSOC SFR value */
  0U,                        /* Queue length can be ignored for Sync */
  (uint8)SPI_DMA_CHNL_INVALID,   /* DMA Tx Channel */
  (uint8)SPI_DMA_CHNL_INVALID,   /* DMA Rx Channel */
  0U,                        /* DMA TCS value can be ignored for Sync */
  SPI_CLK_SLEEP_DISABLE,     /* Module Sleep disabled */
  (uint8)1U,                 /* Input class, MRIS bit field in PISEL SFR */
  1U,                         /* Max Sequence Count on the QSPI */
  0U,  /* External Demultiplexer feature is disabled */
  0U /* SLSO0 Strobe delay */
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 QSPI1 CONFIGURATION MemMap SECTION END *************/

/********************CORE0 RX/TX BUFFERS MEMMAP SECTION***********************/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/* Lookup table to hold the offset in buffer and total elements to be transferred for all IB channels.
Index - Represents channel number, 1st element - Offset in buffer, 2nd element - Total elements to be transmitted */

static const Spi_CoreChannelOffsetType Spi_ChannelOffsets_Core0[SPI_NUM_IB_CHANNELS_CORE0 +  SPI_NUM_EB_CHANNELS_CORE0 + 1U] =
{
{0, 2},  /* for IB channels SpiChannel_WDG */
/* Get the Channel Width */
  {0xFFFF, 0xFFFF}
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/********************CORE0 RX/TX BUFFERS MEMMAP SECTION***********************/
    
/******************* CORE0 Spi_Config_Core CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/* MISRA2012_RULE_8_7_JUSTIFICATION: Spi_Config_Core0 is used outside
* of this file and therefore it is not declared as static */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Agreed violation */

const Spi_CoreConfigType Spi_Config_Core0 =
{
  /* Sequence Configuration */
  Spi_kSequenceConfig_Core0,
  /* Job configuration */
  Spi_kJobConfig_Core0,
  /* Channel Configuration */
  Spi_kChannelConfig_Core0,
  Spi_ChannelOffsets_Core0,
  /* QSPI Hw configuration */
  {
    NULL_PTR,
    &Spi_kQspiHwConfigQSPI1,
    NULL_PTR,
    
  },
  /* Hw Map Index */      
  /*
  (000 QSPI not configured for core0)
  (001 QSPI configured as Sync for core0)
  (010 QSPI configured as Async for core0)
  (011 QSPI configured for core0)
  QSPI5 - 0
  QSPI4 - 0
  QSPI3 - 0
  QSPI2 - 0
  QSPI1 - 1
  QSPI0 - 0*/
  0x00008U,
  /* No. of Sequences configured */
  1U,
  /* No. of Jobs configured */
  1U,
  /* No. of Channels configured */
  1U
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"
/***************** CORE0 Spi_Config_Core CONFIGURATION MemMap SECTION END *************/
      
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"

const Spi_ConfigType Spi_Config =
{
  {
    &Spi_Config_Core0
  },
  SequenceLookupIndex,
  JobLookupIndex,
  ChannelLookupIndex,
  /*Total number of Sequence*/
  1U,
  /*Total number of Jobs*/
  1U,
  /*Total number of Channels*/
  1U,
  /*Sync Delay*/
  65535U
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
* because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
names
* because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
* this is due to inclusion of memmap.h to specify the location to which
* the variable has to be placed. */
#include "Spi_MemMap.h"/* End Of File */
