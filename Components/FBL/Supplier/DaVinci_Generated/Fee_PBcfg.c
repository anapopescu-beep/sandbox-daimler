/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2021)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Fee_PBCfg.c                                                 **
**                                                                            **
**  VERSION     : 12.0.0                                                      **
**                                                                            **
**  DATE, TIME  : 2024-03-21, 15:01:18   !!!IGNORE-LINE!!!                **
**                                                                            **
**  GENERATOR   : Build b191017-0938                                        **
**                                                                            **
**  BSW MODULE DECRIPTION : Fee.bmd                                           **
**                                                                            **
**  VARIANT     : Variant PB                                                  **
**                                                                            **
**  PLATFORM    : Infineon AURIX2G                                            **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION :  Fee configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Fee Driver,                           **
**                     AUTOSAR Release 4.2.2 and 4.4.0                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include Fee Module Header File */
#include "Fee.h"
/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* Allocate space for state data variables in RAM */
#define FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"

/* Fee State Variable structure */
/*MISRA2012_RULE_8_7_JUSTIFICATION: Fee_StateVar has not been declared as static
as this structure is being passed to the Fee.c file. It has scope beyond the 
file.*/
/*MISRA2012_RULE_8_4_JUSTIFICATION: MISRA is assuming as a function but it 
branches out as assembly equivalent or compiler routine..*/
Fee_StateDataType Fee_StateVar;
#define FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"


/* User configured logical block initialization structure */
#define FEE_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"
/*[cover parentID={01870B59-CB19-45ea-8F7F-F16AC029FB7A}][/cover]*/ 
static const Fee_BlockType Fee_BlockConfig[] =
{
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    4U, /* Block number */
    1U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    8U, /* Block number */
    32U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    12U, /* Block number */
    66U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    16U, /* Block number */
    4U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    17U, /* Block number */
    4U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    20U, /* Block number */
    33U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    24U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    28U, /* Block number */
    14U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    32U, /* Block number */
    145U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    33U, /* Block number */
    145U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    34U, /* Block number */
    145U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    36U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    40U, /* Block number */
    96U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    44U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    48U, /* Block number */
    12U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    52U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    56U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    60U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    64U, /* Block number */
    1012U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    68U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    72U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    76U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    80U, /* Block number */
    1012U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    84U, /* Block number */
    38U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    88U, /* Block number */
    1U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    96U, /* Block number */
    1012U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    100U, /* Block number */
    44U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    104U, /* Block number */
    55U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    112U, /* Block number */
    1012U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    128U, /* Block number */
    12U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    144U, /* Block number */
    20U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    160U, /* Block number */
    13U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    176U, /* Block number */
    50U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    192U, /* Block number */
    1U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    208U, /* Block number */
    130U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    224U, /* Block number */
    61U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    240U, /* Block number */
    78U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    256U, /* Block number */
    97U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    272U, /* Block number */
    178U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    288U, /* Block number */
    246U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    304U, /* Block number */
    393U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    320U, /* Block number */
    70U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    336U, /* Block number */
    140U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    352U, /* Block number */
    218U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    368U, /* Block number */
    96U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    384U, /* Block number */
    234U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    400U, /* Block number */
    64U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    416U, /* Block number */
    202U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    432U, /* Block number */
    202U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    448U, /* Block number */
    202U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    464U, /* Block number */
    18U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    480U, /* Block number */
    10U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    496U, /* Block number */
    20U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    512U, /* Block number */
    12U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    528U, /* Block number */
    16U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    544U, /* Block number */
    235U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    560U, /* Block number */
    146U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    576U, /* Block number */
    1075U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    592U, /* Block number */
    5U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    608U, /* Block number */
    20U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    624U, /* Block number */
    5U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    640U, /* Block number */
    30U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    672U, /* Block number */
    14U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    688U, /* Block number */
    22U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    704U, /* Block number */
    99U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    712U, /* Block number */
    9U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    716U, /* Block number */
    8U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    720U, /* Block number */
    422U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    784U, /* Block number */
    1164U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    788U, /* Block number */
    10U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    792U, /* Block number */
    4U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1104U, /* Block number */
    42U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1120U, /* Block number */
    40U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1136U, /* Block number */
    8U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1152U, /* Block number */
    23U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1168U, /* Block number */
    23U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1184U, /* Block number */
    23U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1200U, /* Block number */
    23U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1216U, /* Block number */
    23U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1232U, /* Block number */
    23U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1248U, /* Block number */
    130U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1264U, /* Block number */
    20U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1280U, /* Block number */
    11U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1312U, /* Block number */
    9U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1328U, /* Block number */
    23U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1344U, /* Block number */
    34U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1360U, /* Block number */
    6U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1376U, /* Block number */
    6U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1392U, /* Block number */
    22U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1408U, /* Block number */
    11U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1424U, /* Block number */
    23U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1440U, /* Block number */
    3U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1448U, /* Block number */
    24U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1472U, /* Block number */
    24U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1496U, /* Block number */
    48U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1544U, /* Block number */
    44U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1588U, /* Block number */
    3U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1612U, /* Block number */
    11U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1628U, /* Block number */
    14U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1644U, /* Block number */
    11U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1680U, /* Block number */
    14U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1692U, /* Block number */
    14U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1708U, /* Block number */
    14U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    1712U, /* Block number */
    5U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1716U, /* Block number */
    42U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1760U, /* Block number */
    5U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1768U, /* Block number */
    12U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    1788U, /* Block number */
    260U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_IMMEDIATE_DATA, /* Block type is Immediate */
    1792U, /* Block number */
    22U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
};
const Fee_ConfigType Fee_Config =
{  
  /* Fee State Data Structure */
  &Fee_StateVar,
  /* Pointer to logical block configurations */
  &Fee_BlockConfig[0],

/*MISRA2012_RULE_11_3_JUSTIFICATION:  The warning is coming for NULL_PTR defined by 
AUTOSAR. The function pointer is being allocated NULL_PTR as the particular 
function will not be required. The function is correctly getting assigned to NULL VALUE*/

  /* Fee Job end notification API */
  (Fee_NotifFunctionPtrType)NULL_PTR,

/*MISRA2012_RULE_11_3_JUSTIFICATION:  The warning is coming for NULL_PTR defined by 
AUTOSAR. The function pointer is being allocated NULL_PTR as the particular 
function will not be required. The function is correctly getting assigned to NULL VALUE*/

  /* Fee Job error notification API */
  (Fee_NotifFunctionPtrType)NULL_PTR,

/*MISRA2012_RULE_11_3_JUSTIFICATION:  The warning is coming for NULL_PTR defined by 
AUTOSAR. The function pointer is being allocated NULL_PTR as the particular 
function will not be required. The function is correctly getting assigned to NULL VALUE*/
/*MISRA2012_RULE_11_3_JUSTIFICATION:  The warning is coming for NULL_PTR defined by 
AUTOSAR. The function pointer is being allocated NULL_PTR as the particular 
function will not be required. The function is correctly getting assigned to NULL VALUE*/
  /* Fee threshold value */
  200U,
  /* Number of blocks configured */
  109U,
  {
    /* Keep the unconfigured blocks */
    FEE_UNCONFIG_BLOCK_KEEP,
    /* Restart Garbage Collection during initialization */
    FEE_GC_RESTART_INIT,
    /* Erase Suspend feature is disabled */
    FEE_ERASE_SUSPEND_DISABLED,
    
    /* Reserved */
    0U
  },


/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  
  /* Fee NVM Illegal State notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,

/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  
  /* Fee QS Illegal State notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,
/*MISRA2012_RULE_11_3_JUSTIFICATION: Pointers are accessing the correct memory 
range locations. Out of bounds checks were checked during functional verification. */
  /* QS Hardening Error notification */
  (Fee_NotifFunctionPtrType)NULL_PTR,
  /* Erase All feature is disabled */
  (boolean)FALSE


};

#define FEE_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"
