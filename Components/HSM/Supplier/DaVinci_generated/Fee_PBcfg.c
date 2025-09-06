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
**  FILENAME    : Fee_PBCfg.c                                                 **
**                                                                            **
**  VERSION     : 3.0.0                                                       **
**                                                                            **
**  DATE, TIME  : 2023-08-16, 13:53:45   !!!IGNORE-LINE !!!               **
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
**  SPECIFICATION(S) : Specification of Fee Driver, AUTOSAR Release 4.2.2     **
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
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FEE_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
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
/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap Macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar 
naming convention, hence it goes beyond 32 characters.*/
#define FEE_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"

/* User configured logical block initialization structure */
#define FEE_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
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
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    16U, /* Block number */
    74U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    17U, /* Block number */
    74U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    32U, /* Block number */
    284U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    33U, /* Block number */
    284U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    64U, /* Block number */
    4U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    65U, /* Block number */
    4U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    192U, /* Block number */
    404U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    193U, /* Block number */
    404U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    208U, /* Block number */
    20U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    209U, /* Block number */
    20U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    224U, /* Block number */
    926U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    225U, /* Block number */
    926U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    240U, /* Block number */
    926U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    241U, /* Block number */
    926U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    256U, /* Block number */
    3022U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    257U, /* Block number */
    3022U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    272U, /* Block number */
    1014U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
  {
    0U, /* Block Cycle Count */
    (uint8)FEE_NORMAL_DATA,  /* Block type is Normal */
    273U, /* Block number */
    1014U, /* Fee Block Size */
/*MISRA2012_RULE_10_3_JUSTIFICATION: Exception MISRA 10_3 is not applicable
to the initializer {0} which may be used to initialize an aggregate.
Here it is defined as enum and first element initialized to 0.
*/
  },
};
/* MISRA2012_RULE_8_7_JUSTIFICATION: External linkage is needed as it is used
in more than one translation unit. */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Defined as per AUTOSAR */
/* Fee Global initialization structure. */
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
  18U,
  {
    /* Ignore the unconfigured blocks */
    FEE_UNCONFIG_BLOCK_IGNORE,
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
  /* Erase All feature is enabled */
  (boolean)TRUE

};

#define FEE_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
/*MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/*MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
guideline. */
#include "Fee_MemMap.h"
