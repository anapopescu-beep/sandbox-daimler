/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: vLinkGen
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vLinkGen_Lcfg.h
 *   Generation Time: 2023-07-26 12:58:40
 *           Project: CBD2000614_fblbm_Upd - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

#ifndef VLINKGEN_LCFG_H
# define VLINKGEN_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"
# include "vLinkGen_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Definition of a generic memory area to be initialized. */
typedef struct
{
  /*! Start address of the memory area. */
  uint32 Start;
  /*! End address of the memory area. */
  uint32 End;
  /*! Core ID to perform the initialization. */
  uint32 Core;
  /*! ECC alignment of memory area in bytes. */
  uint32 Alignment;
} vLinkGen_MemArea;

/*! Definition of a generic initialization set. */
typedef struct
{
  /*! Number of memory areas in this set. */
  uint32 Num;
  /*! Table of generic memory areas. */
  const vLinkGen_MemArea *Areas;
} vLinkGen_MemAreaSet;

/*! Definition of a RAM memory area to be initialized with concrete data from ROM. */
typedef struct
{
  /*! Start address of the RAM memory area. */
  uint32 Start;
  /*! End address of the RAM memory area. */
  uint32 End;
  /*! Start address of the ROM memory area containing the init data. */
  uint32 Romstart;
  /*! End address of the ROM memory area containing the init data. */
  uint32 Romend;
  /*! Core ID to perform the initialization. */
  uint32 Core;
  /*! ECC alignment of memory area in bytes. */
  uint32 Alignment;
} vLinkGen_RamMemArea;

/*! Definition of a ROM to RAM initialization set. */
typedef struct
{
  /*! Number of memory areas in this set. */
  uint32 Num;
  /*! Table of ROM to RAM memory areas. */
  const vLinkGen_RamMemArea *Areas;
} vLinkGen_RamMemAreaSet;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* Extern declarations of start/limit address labels. */
extern uint8 _AppDataDefault_ROM_LIMIT[]; 
extern uint8 _AppDataDefault_ROM_START[]; 
extern uint8 _AppDataDefault_START[]; 
extern uint8 _STACK_C0_START[]; 
extern uint8 _UpdRamCodeSection_DSPR0_ROM_LIMIT[]; 
extern uint8 _UpdRamCodeSection_DSPR0_ROM_START[]; 
extern uint8 _UpdRamCodeSection_DSPR0_START[]; 
extern uint8 _UpdRamConstSection_ROM_LIMIT[]; 
extern uint8 _UpdRamConstSection_ROM_START[]; 
extern uint8 _UpdRamConstSection_START[]; 
extern uint8 _bss_START[]; 
extern uint8 _lc_ge_AppDataDefault[]; 
extern uint8 _lc_ge_STACK_C0[]; 
extern uint8 _lc_ge_UpdRamCodeSection_DSPR0[]; 
extern uint8 _lc_ge_UpdRamConstSection[]; 
extern uint8 _lc_ge_bss[]; 
extern uint8 _lc_ge_zbss[]; 
extern uint8 _zbss_START[]; 

/* Extern declarations of initialization tables. */
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_BLOCKS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Early_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_EARLY_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_BLOCKS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_HardReset_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_HARD_RESET_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_One_Blocks[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_BLOCKS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_One_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ONE_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Three_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_THREE_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Two_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_TWO_GROUPS]; 
extern const vLinkGen_MemArea vLinkGen_ZeroInit_Zero_Groups[VLINKGEN_CFG_NUM_ZERO_INIT_ZERO_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_HardReset_Groups[VLINKGEN_CFG_NUM_INIT_HARD_RESET_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_One_Groups[VLINKGEN_CFG_NUM_INIT_ONE_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_Three_Groups[VLINKGEN_CFG_NUM_INIT_THREE_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_Two_Groups[VLINKGEN_CFG_NUM_INIT_TWO_GROUPS]; 
extern const vLinkGen_RamMemArea vLinkGen_Init_Zero_Groups[VLINKGEN_CFG_NUM_INIT_ZERO_GROUPS]; 

/* Extern declarations of initialization structures. */
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Early_BlocksSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Early_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_HardReset_BlocksSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_HardReset_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_One_BlocksSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_One_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Three_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Two_GroupsSet; 
extern const vLinkGen_MemAreaSet vLinkGen_ZeroInit_Zero_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_HardReset_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_One_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_Three_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_Two_GroupsSet; 
extern const vLinkGen_RamMemAreaSet vLinkGen_Init_Zero_GroupsSet; 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* VLINKGEN_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vLinkGen_Lcfg.h
 *********************************************************************************************************************/
