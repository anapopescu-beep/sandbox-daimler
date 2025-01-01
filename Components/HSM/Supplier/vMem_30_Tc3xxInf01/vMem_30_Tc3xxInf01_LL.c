/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vMem_30_Tc3xxInf01_LL.c
 *        \brief  vMem_30_Tc3xxInf01 LowLevel source file
 *
 *      \details  See vMem_30_Tc3xxInf01_LL.h
 *
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_LL_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vMem_30_Tc3xxInf01_LL.h"
#include "vMem_30_Tc3xxInf01_Cfg.h"
#include "vMem_30_Tc3xxInf01_Callout.h"
#include "SchM_vMem_30_Tc3xxInf01.h"
#include "vMem_30_Tc3xxInf01_Extended_Func.h"

#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#if (VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API == STD_ON)
# include "Os.h"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  HARDWARE SOFTWARE INTERFACE (HSI)
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/**********************************************************************************************************************
 *  DMU registers
 *********************************************************************************************************************/
/*! Base address of SRI slave interface (DMU) - Register Address Space */
#define VMEM_30_TC3XXINF01_FLASH_DMU_CMD_BASE         0xF8040000UL
/*! DMU Register Offsets (from base address) */
#define VMEM_30_TC3XXINF01_STATUS_ADDR                0x0010UL                /*!< Offset to Flash Status Register (HF_STATUS) */
#define VMEM_30_TC3XXINF01_OPERATION_ADDR             0x0018UL                /*!< Offset to Flash Operation Register (HF_OPERATION) */
#define VMEM_30_TC3XXINF01_ERRSER_ADDR                0x0034UL                /*!< Offset to Error Status Register (HF_ERRSER) */

/*! HF_STATUS - Flash status register bit masks */
#define VMEM_30_TC3XXINF01_STATUS_D0BUSY              0x00000001UL            /*!< DF0 busy flag */
#define VMEM_30_TC3XXINF01_STATUS_D1BUSY              0x00000002UL            /*!< DF1 busy flag */
#define VMEM_30_TC3XXINF01_STATUS_P0BUSY              0x00000004UL            /*!< PF0 busy flag */
#define VMEM_30_TC3XXINF01_STATUS_P1BUSY              0x00000008UL            /*!< PF1 busy flag */
#define VMEM_30_TC3XXINF01_STATUS_P2BUSY              0x00000010UL            /*!< PF2 busy flag */
#define VMEM_30_TC3XXINF01_STATUS_P3BUSY              0x00000020UL            /*!< PF3 busy flag */
#define VMEM_30_TC3XXINF01_STATUS_P4BUSY              0x00000040UL            /*!< PF4 busy flag */
#define VMEM_30_TC3XXINF01_STATUS_P5BUSY              0x00000080UL            /*!< PF5 busy flag */

#define VMEM_30_TC3XXINF01_STATUS_PFPAGE              0x00200000UL            /*!< PFlash in page mode */
#define VMEM_30_TC3XXINF01_STATUS_DFPAGE              0x00100000UL            /*!< DFlash in page mode */

/*! HF_OPERATION - Flash operation register bit masks */
#define VMEM_30_TC3XXINF01_OPERATION_PROG             0x00000001UL            /*!< Programming state bit */
#define VMEM_30_TC3XXINF01_OPERATION_ERASE            0x00000002UL            /*!< Erase state bit */

/*! HF_ERRSR - Error status register bit masks */
#define VMEM_30_TC3XXINF01_ERRSR_NOERROR             0x00000000uL            /*!< No error indicated */
#define VMEM_30_TC3XXINF01_ERRSR_OPER                0x00000001UL            /*!< Flash operation error */
#define VMEM_30_TC3XXINF01_ERRSR_SQER                0x00000002UL            /*!< Command sequence error */
#define VMEM_30_TC3XXINF01_ERRSR_PROER               0x00000004UL            /*!< Protection error */
#define VMEM_30_TC3XXINF01_ERRSR_PVER                0x00000008UL            /*!< Program verify error */
#define VMEM_30_TC3XXINF01_ERRSR_EVER                0x00000010UL            /*!< Erase verify error */
#define VMEM_30_TC3XXINF01_ERRSR_ADER                0x00000020UL            /*!< SRI bus address ECC error - currently not used */
#define VMEM_30_TC3XXINF01_ERRSR_ORIER               0x00000040UL            /*!< Original error (uncorrectable ECC error) - currently not used */

/*! Flash status register - combined busy flags */
#define VMEM_30_TC3XXINF01_STATUS_BUSY    ( VMEM_30_TC3XXINF01_STATUS_D0BUSY | VMEM_30_TC3XXINF01_STATUS_D1BUSY | VMEM_30_TC3XXINF01_STATUS_P0BUSY | VMEM_30_TC3XXINF01_STATUS_P1BUSY | VMEM_30_TC3XXINF01_STATUS_P2BUSY | VMEM_30_TC3XXINF01_STATUS_P3BUSY | VMEM_30_TC3XXINF01_STATUS_P4BUSY | VMEM_30_TC3XXINF01_STATUS_P5BUSY )
/*! Flash status register - combined program/erase error flags */
#define VMEM_30_TC3XXINF01_ERRSR_ERROR    ( VMEM_30_TC3XXINF01_ERRSR_OPER | VMEM_30_TC3XXINF01_ERRSR_SQER | VMEM_30_TC3XXINF01_ERRSR_PROER | VMEM_30_TC3XXINF01_ERRSR_PVER | VMEM_30_TC3XXINF01_ERRSR_EVER )

/**********************************************************************************************************************
 *  DMU registers: Host Command Sequence Interpreter
 *********************************************************************************************************************/
/*! Base address of Host Command Sequence Interpreter */
#define VMEM_30_TC3XXINF01_PROG_BASE_ADDRESS         0xAF000000u            /*!< Base address for all flash programming command. */

/*! Command Sequences for Flash Control */
/* Reset to read mode */
#define VMEM_30_TC3XXINF01_RESET_TO_READ_ADDR            0x5554u             /*!< Address offset for Reset To Read command. */
#define VMEM_30_TC3XXINF01_RESET_TO_READ_DATA              0xF0u             /*!< Reset To Read command value. */

/* Enter page mode */
#define VMEM_30_TC3XXINF01_ENTER_PAGE_MODE_ADDR          0x5554u             /*!< Address offset for Enter Page Mode command. */
#define VMEM_30_TC3XXINF01_ENTER_PAGE_MODE_DATA            0x50u             /*!< Enter Page Mode - PFlash command value. */

/* Load page */
#define VMEM_30_TC3XXINF01_LOAD_PAGE_ADDR                0x55F0u             /*!< Address offset for Load Page command. */

/* Clear status */
#define VMEM_30_TC3XXINF01_CLEAR_STATUS_ADDR             0x5554u             /*!< Address offset for Clear Status command. */
#define VMEM_30_TC3XXINF01_CLEAR_STATUS_DATA               0xFAu             /*!< Clear status command value. */

/* Write page/erase/replace sector */
#define VMEM_30_TC3XXINF01_PROG_STEP1_ADDR               0xAA50u             /*!< Address offset for prog command - step 1. */
#define VMEM_30_TC3XXINF01_PROG_STEP2_ADDR               0xAA58u             /*!< Address offset for prog command - step 2. */
#define VMEM_30_TC3XXINF01_PROG_STEP3_ADDR               0xAAA8u             /*!< Address offset for prog command - step 3.*/
#define VMEM_30_TC3XXINF01_PROG_STEP4_ADDR               0xAAA8u             /*!< Address offset for prog command - step 4. */
#define VMEM_30_TC3XXINF01_WRITE_STEP2_DATA                0x00u             /*!< Write - Step 2 command value. */
#define VMEM_30_TC3XXINF01_WRITE_STEP3_DATA                0xA0u             /*!< Write - Step 3 command value. */
#define VMEM_30_TC3XXINF01_WRITE_STEP4_DATA                0xAAu             /*!< Write - Step 4 command value. */
#define VMEM_30_TC3XXINF01_WRITE_BURST_STEP4_DATA          0xA6u             /*!< Write Burst - Step 4 command value. */
#define VMEM_30_TC3XXINF01_ERASE_STEP3_DATA                0x80u             /*!< Erase - Step 3 command value. */
#define VMEM_30_TC3XXINF01_ERASE_STEP4_DATA                0x50u             /*!< Erase - Step 4 command value. */
#define VMEM_30_TC3XXINF01_ERASE_VERIFY_STEP2_DATA         0x00u             /*!< Erase verify - Step 2 command value. */
#define VMEM_30_TC3XXINF01_ERASE_VERIFY_STEP3_DATA         0x80u             /*!< Erase verify - Step 3 command value. */
#define VMEM_30_TC3XXINF01_ERASE_VERIFY_SR_STEP4_DATA      0x5Fu             /*!< Erase verify logical sector range - Step 4 command value. */
#define VMEM_30_TC3XXINF01_ERASE_VERIFY_PAGE_STEP4_DATA    0x56u             /*!< Erase verify page - Step 4 command value. */
#define VMEM_30_TC3XXINF01_REPLACE_SECTOR_STEP2_DATA       0x00u             /*!< Replace logical sector - Step 2 command value. */
#define VMEM_30_TC3XXINF01_REPLACE_SECTOR_STEP3_DATA       0xA0u             /*!< Replace logical sector - Step 3 command value. */
#define VMEM_30_TC3XXINF01_REPLACE_SECTOR_STEP4_DATA       0xACu             /*!< Replace logical sector - Step 4 command value. */

/**********************************************************************************************************************
 *  SCU registers
 *********************************************************************************************************************/
/*! Defines needed for determining the active address region */
#define VMEM_30_TC3XXINF01_SCU_BASE                 0xF0036000UL             /*!< Base address of the System Control Unit (SCU) */
/* Register offset from SCU base address */
#define VMEM_30_TC3XXINF01_SWAPCTRL_ADDR                0x014CUL             /*!< Offset to Alternate Address Control Register (SWAPCTRL) */
/*! SWAPCTRL register bit masks */
#define VMEM_30_TC3XXINF01_REGION_A_ACTIVE          0x00000001UL             /*!< Address region A active (B inactive) */
#define VMEM_30_TC3XXINF01_REGION_B_ACTIVE          0x00000002UL             /*!< Address region B active (A inactive) */

/**********************************************************************************************************************
 *  HSM Bridge registers
 *********************************************************************************************************************/
#ifdef VHSM_CODE /* COV_VMEM_30_TC3XXINF01_USECASE */
# define VMEM_30_TC3XXINF01_HSM_BRIDGE              0xF0040000uL            /*!< Address for HSM Bridge */
# define VMEM_30_TC3XXINF01_HSM_SAHBASE_OFFSET      0x000000C0uL            /*!< Offset from Bridge */
# define VMEM_30_TC3XXINF01_HSM_SAHMEM_OFFSET       0x00010000uL            /*!< Offset from Bridge */
#endif

/**********************************************************************************************************************
 *  UCB registers
 *********************************************************************************************************************/
/*! Defines needed for (read) access of UCB, to retrieve redundant sector information */
#define VMEM_30_TC3XXINF01_UCB_BASE                 0xAF400000UL             /*!< Base address of the User Configuration Block (UCB) */
/*! UCB register offset (from base address) */
#define VMEM_30_TC3XXINF01_REDSECP_ADDR             0x1800UL                 /*!< Offset to Redundancy Information for PFlash */

/* REDSEC register bit masks */
#define VMEM_30_TC3XXINF01_REDSECP_FAIL             0x8000UL                 /*!< FAIL, Entry unavailable */
#define VMEM_30_TC3XXINF01_REDSECP_USED             0x4000UL                 /*!< USED, Entry used */
#define VMEM_30_TC3XXINF01_REDSECP_SECTOR_ADDRESS   0x3FUL                   /*!< Address of defective Sector in 1024KiB block */

#define VMEM_30_TC3XXINF01_REDSECP_PFLASH_STEP      0x40UL                   /*!< Address step between Redsed entries per PFlash Bank */
#define VMEM_30_TC3XXINF01_REDSECP_PSECTOR_STEP     0x10UL                   /*!< Address step between Redsed entries per physical sector */
#define VMEM_30_TC3XXINF01_REDSECP_SECOND_ENTRY     0x8UL                    /*!< Offset to second entry of Redsec */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS: compiler abstraction
 *********************************************************************************************************************/
/* vMem_30_Tc3xxInf01 knows four compilers and their abstraction. For all other compilers the integrator
 * is responsible to define the required abstraction out of the vMem_30_Tc3xxInf01 component. */
#ifndef VMEM_30_TC3XXINF01_DSYNC /* COV_VMEM_30_TC3XXINF01_COMPILER */
# if defined _GNU_C_TRICORE_ /* COV_VMEM_30_TC3XXINF01_COMPILER */
#  include "intrinsics.h"
#  define VMEM_30_TC3XXINF01_DSYNC _dsync
# elif defined _TASKING_C_TRICORE_ /* COV_VMEM_30_TC3XXINF01_COMPILER */
#  define VMEM_30_TC3XXINF01_DSYNC __dsync
# elif defined _GREENHILLS_C_TRICORE_ /* COV_VMEM_30_TC3XXINF01_COMPILER */
#  include "intrinsics.h"
#  define VMEM_30_TC3XXINF01_DSYNC __dsync
# elif defined _DIAB_C_TRICORE_ /* COV_VMEM_30_TC3XXINF01_COMPILER */
#  include "asm.h"
#  define VMEM_30_TC3XXINF01_DSYNC _dsync
# else
#  error "For Integrator: unknown compiler, VMEM_30_TC3XXINF01_DSYNC must be defined outside of the vMem_30_Tc3xxInf01."
# endif
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (VMEM_30_TC3XXINF01_TEST_ENV) /* COV_MEM_30_TC3XXINF01_TESTING */
# if (VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API == STD_OFF)
/* Programming command macro. */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#  define vMem_30_Tc3xxInf01_CommandCycle(addr, data)      vMem_30_Tc3xxInf01_LLWriteRegister(VMEM_30_TC3XXINF01_PROG_BASE_ADDRESS, addr, data)
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#  define vMem_30_Tc3xxInf01_GetUcbRedSec(offset)   vMem_30_Tc3xxInf01_LLReadRegister(VMEM_30_TC3XXINF01_UCB_BASE, VMEM_30_TC3XXINF01_REDSECP_ADDR + offset) /*!< Redundancy Information (REDSEC) */
#  define vMem_30_Tc3xxInf01_GetDmuHFStatus()      vMem_30_Tc3xxInf01_LLReadRegister(VMEM_30_TC3XXINF01_FLASH_DMU_CMD_BASE, VMEM_30_TC3XXINF01_STATUS_ADDR)  /*!< Flash Status Register (HF_STATUS) */
#  define vMem_30_Tc3xxInf01_GetDmuHFOperation()   vMem_30_Tc3xxInf01_LLReadRegister(VMEM_30_TC3XXINF01_FLASH_DMU_CMD_BASE, VMEM_30_TC3XXINF01_OPERATION_ADDR)  /*!< Flash Operation Register (HF_OPERATION) */
#  define vMem_30_Tc3xxInf01_GetDmuHFErrsr()       vMem_30_Tc3xxInf01_LLReadRegister(VMEM_30_TC3XXINF01_FLASH_DMU_CMD_BASE, VMEM_30_TC3XXINF01_ERRSER_ADDR)  /*!< Error Status Register (HF_ERRSER) */
#  define vMem_30_Tc3xxInf01_GetScuSwapCtrl()       vMem_30_Tc3xxInf01_LLReadRegister(VMEM_30_TC3XXINF01_SCU_BASE, VMEM_30_TC3XXINF01_SWAPCTRL_ADDR)  /*!< Alternate Address Control Register (SWAPCTRL) */

# else
/* Programming command macro. */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#  define vMem_30_Tc3xxInf01_CommandCycle(addr, data)      osWritePeripheral32(OS_MEM_AREA_VMEM_30_TC3XXINF01_REG_HCSI, VMEM_30_TC3XXINF01_PROG_BASE_ADDRESS + addr, data)
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#  define vMem_30_Tc3xxInf01_GetUcbRedSec(offset)   osReadPeripheral32(OS_MEM_AREA_VMEM_30_TC3XXINF01_REG_UCB, VMEM_30_TC3XXINF01_UCB_BASE + VMEM_30_TC3XXINF01_REDSECP_ADDR + offset) /*!< Redundancy Information (REDSEC) */
#  define vMem_30_Tc3xxInf01_GetDmuHFStatus()      osReadPeripheral32(OS_MEM_AREA_VMEM_30_TC3XXINF01_REG_DMU, VMEM_30_TC3XXINF01_FLASH_DMU_CMD_BASE + VMEM_30_TC3XXINF01_STATUS_ADDR)  /*!< Flash Status Register (HF_STATUS) */
#  define vMem_30_Tc3xxInf01_GetDmuHFOperation()   osReadPeripheral32(OS_MEM_AREA_VMEM_30_TC3XXINF01_REG_DMU, VMEM_30_TC3XXINF01_FLASH_DMU_CMD_BASE + VMEM_30_TC3XXINF01_OPERATION_ADDR)  /*!< Flash Operation Register (HF_OPERATION) */
#  define vMem_30_Tc3xxInf01_GetDmuHFErrsr()       osReadPeripheral32(OS_MEM_AREA_VMEM_30_TC3XXINF01_REG_DMU, VMEM_30_TC3XXINF01_FLASH_DMU_CMD_BASE + VMEM_30_TC3XXINF01_ERRSER_ADDR)  /*!< Error Status Register (HF_ERRSER) */
#  define vMem_30_Tc3xxInf01_GetScuSwapCtrl()       osReadPeripheral32(OS_MEM_AREA_VMEM_30_TC3XXINF01_REG_SCU, VMEM_30_TC3XXINF01_SCU_BASE + VMEM_30_TC3XXINF01_SWAPCTRL_ADDR)  /*!< Alternate Address Control Register (SWAPCTRL) */
# endif
#endif
/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (VMEM_30_TC3XXINF01_LOCAL) /* COV_VMEM_30_TC3XXINF01_COMPATIBILITY */
# define VMEM_30_TC3XXINF01_LOCAL static
#endif

#if !defined (VMEM_30_TC3XXINF01_LOCAL_INLINE) /* COV_VMEM_30_TC3XXINF01_COMPATIBILITY */
# define VMEM_30_TC3XXINF01_LOCAL_INLINE LOCAL_INLINE
#endif

typedef struct
{
  vMem_30_Tc3xxInf01_AddressType                currentAddress;     /*!< Stores address */
  vMem_30_Tc3xxInf01_LengthType                 remainingLength;    /*!< Stores length */
  vMem_30_Tc3xxInf01_ConstDataPtrType           inBuffer;           /*!< Stores buffer for write jobs */
  vMem_30_Tc3xxInf01_LengthType                 nrSectors;          /*!< Stores the number of sectors (to be erased) */
  vMem_30_Tc3xxInf01_MemSectorIterType          sectorIndex;        /*!< Stores the sector (batch) index = physical sector */
  boolean                                       isBurst;            /*!< Stores information if burst is used or not (only used for write) */
} vMem_30_Tc3xxInf01_CommonJobParamType;                            /*!< Stores the base information about the current job */

typedef struct
{
  vMem_30_Tc3xxInf01_JobResultType        currentJobResult;     /*!< Stores current job result */
  vMem_30_Tc3xxInf01_JobType              currentJob;           /*!< Stores type of current job */
  vMem_30_Tc3xxInf01_CommonJobParamType   currentJobParameter;  /*!< Stores the base information about the current job */
  vMem_30_Tc3xxInf01_AddressType          currentErrorResult;   /*!< Stores extended error information about the current job */
} vMem_30_Tc3xxInf01_WorkSpaceType;                             /*!< Stores information about current job */

typedef P2FUNC(boolean, VMEM_30_TC3XXINF01_CODE, vMem_30_Tc3xxInf01_StateFunctionPtr) (void); /*!< State function pointer type */

typedef P2CONST(uint8, AUTOMATIC, VMEM_30_TC3XXINF01_APPL_VAR) vMem_30_Tc3xxInf01_ReadBufferPtrType;
typedef P2VAR(uint8, AUTOMATIC, VMEM_30_TC3XXINF01_APPL_VAR) vMem_30_Tc3xxInf01_WriteBuffer8PtrType;
typedef P2VAR(uint32, AUTOMATIC, VMEM_30_TC3XXINF01_APPL_VAR) vMem_30_Tc3xxInf01_WriteBuffer32PtrType;

#if (VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API == STD_OFF)
/*!< Register access type */
typedef volatile vMem_30_Tc3xxInf01_AddressType vMem_30_Tc3xxInf01_RegAccessType;
/*!< Pointer to a register */
typedef P2VAR(vMem_30_Tc3xxInf01_RegAccessType, AUTOMATIC, VMEM_30_TC3XXINF01_APPL_VAR) vMem_30_Tc3xxInf01_RegPtrType;
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VMEM_30_TC3XXINF01_LOCAL VAR(vMem_30_Tc3xxInf01_StateFunctionPtr, VMEM_30_TC3XXINF01_VAR_NOINIT) vMem_30_Tc3xxInf01_NextStatePtr; /*!< Holds the current state. */
VMEM_30_TC3XXINF01_LOCAL VAR(vMem_30_Tc3xxInf01_WorkSpaceType, VMEM_30_TC3XXINF01_VAR_NOINIT) vMem_30_Tc3xxInf01_WorkSpace; /*!< Holds the information about current job. */
VMEM_30_TC3XXINF01_LOCAL VAR(vMem_30_Tc3xxInf01_AddressRegionType, VMEM_30_TC3XXINF01_VAR_NOINIT) vMem_30_Tc3xxInf01_ActiveAddressRegion;  /*!< Stores the information which address region/bank is active */

#define VMEM_30_TC3XXINF01_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(vMemAccM_vMemHwSpecificFuncPtr, AUTOMATIC) vMem_30_Tc3xxInf01_HwSpecificFunctions[VMEM_30_TC3XXINF01_EXTENDED_FUNCTION_COUNT] = { 
  &vMem_30_Tc3xxInf01_GetActiveAddressRegion,
  &vMem_30_Tc3xxInf01_ReplaceLogicalSector,
  &vMem_30_Tc3xxInf01_GetLastErrorState
};

#define VMEM_30_TC3XXINF01_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLStateIdle()
 *********************************************************************************************************************/
/*! \brief       Implements the idle state.
 *  \details     -
 *  \return      TRUE, if the MainFunction shall return; FALSE, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateIdle(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLStateErasePolling()
 *********************************************************************************************************************/
/*! \brief       Implements the erase polling state.
 *  \details     -
 *  \return      TRUE, if the MainFunction shall return; FALSE, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateErasePolling(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLStateWritePageModePolling()
 *********************************************************************************************************************/
/*!
 *  \brief       Implements the write page mode polling state.
 *  \details     -
 *  \return      TRUE, if the MainFunction shall return; FALSE, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateWritePageModePolling(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLStateReplaceSector()
 *********************************************************************************************************************/
/*!
 *  \brief       Implements the replace logical sector state, in particular performs the replace logical sector
 *               command sequence.
 *  \details     When this state is reached, it was already checked (synchronously), that sector is replaceable.
 *  \return      TRUE: the MainFunction shall return.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateReplaceSector(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLStateFinalizePolling()
 *********************************************************************************************************************/
/*! \brief       Implements the finalize polling state.
 *  \details     -
 *  \return      TRUE, if the MainFunction shall return; FALSE, otherwise
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateFinalizePolling(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLGetCommandResult()
 *********************************************************************************************************************/
/*! \brief       Checks whether command is successfully executed or error is reported by hardware.
 *  \details     -
 *  \return      VMEM_JOB_OK: command is executed; VMEM_JOB_FAILED: hardware indicated error; VMEM_JOB_PENDING hardware
 *               is still busy.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(vMem_30_Tc3xxInf01_JobResultType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLGetCommandResult(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLTryJobSetup()
 *********************************************************************************************************************/
/*! \brief       Checks job result, and if not pending, stores job parameters for jobs read, write and erase.
 *  \details     Exclusive area is entered and exited within this function. It is first checked, whether the job result is
 *               pending. If it is not pending the job parameters are stored and job result is set to pending.
 *  \param[in]   Job                 Job that has just been accepted.
 *  \param[in]   TargetAddress       NV memory address to write to.
 *  \param[in]   SourceAddressPtr    application pointer to buffer with data to write to nv memory.
 *  \param[in]   Length              Length to write.
 *  \param[in]   SectorIndex         Index of sector for given requested address.
 *  \param[in]   IsBurst             Is burst or not (only relevant for write; for erase and read FALSE can always be used)
 *  \return      TRUE job has been set up, FALSE otherwise.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLTryJobSetup(
  vMem_30_Tc3xxInf01_JobType Job,
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_ConstDataPtrType SourceAddressPtr,
  vMem_30_Tc3xxInf01_LengthType Length,
  vMem_30_Tc3xxInf01_MemSectorIterType SectorIndex,
  boolean IsBurst
  );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLFinalizeJob()
 *********************************************************************************************************************/
/*!
 *  \brief       Finalizes a (successful or unsuccessful) job, sets job result and next state to idle.
 *  \details     -
 *  \param[in]   JobResult
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLFinalizeJob(vMem_30_Tc3xxInf01_JobResultType JobResult);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLGetSectorIndex()
 *********************************************************************************************************************/
/*!
 *  \brief       Searches for the passed address within the configuration.
 *  \details     -
 *  \param[in]   InstanceId
 *  \param[in]   Address
 *  \return      Index to the sector batch, or an out of range value.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(vMem_30_Tc3xxInf01_MemSectorIterType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLGetSectorIndex(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType Address
  );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLResetToRead()
 *********************************************************************************************************************/
/*!
 *  \brief       Resets flash states to read mode.
 *  \details     Resets the addressed command sequence interpreter to its initial state.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLResetToRead(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLClearStatusCommand()
 *********************************************************************************************************************/
/*!
 *  \brief       Clears operation and error flags in flash module
 *  \details     The error flags (SQER, PROER, PVER, EVER) in Flash status register are cleared. Additionally, the write status bits
 *               (PROG, ERASE) are cleared.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLClearStatusCommand(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLVerifyErase()
 *********************************************************************************************************************/
/*!
 * \brief      Executes clear status and the verify erase command sequence.
 * \details    -
 * \param[in]  Address  Address for which the verify erase command sequence shall be executed. Must be page or sector
 *                      aligned depending on length.
 * \param[in]  VerifyEraseLength  Length is either number of sectors, or zero for verify erase page
 * \param[in]  VerifyEraseCommand  Command for verify erase page or verify erase sector range.
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLVerifyErase(
  vMem_30_Tc3xxInf01_AddressType Address,
  vMem_30_Tc3xxInf01_LengthType VerifyEraseLength,
  vMem_30_Tc3xxInf01_LengthType VerifyEraseCommand
  );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLPageBlankCheck()
 *********************************************************************************************************************/
/*!
 * \brief      Checks whether the page at current Address is blank, i.e. erased.
 * \details    -
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLPageBlankCheck(void);

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLReplaceLogicalSector()
 *********************************************************************************************************************/
/*!
 * \brief      Triggers the replacement of the requested sector.
 * \details    Checks whether the sector is replaceable and in that case triggers the replacement of the requested
 *             sector. Parameter checks are done within vMem_30_Tc3xxInf01_ReplaceLogicalSector.
 * \param[in]  InstanceId  ID of the related vMem_30_Tc3xxInf01 instance, must be valid.
 * \param[in]  ReqSpecificData  Pointer to a variable of type vMem_30_Tc3xxInf01_ReplaceSectorType.
 *                                 Contains the address of the sector which shall be replaced.
 *                                 After job is processed contains information, if sector is replaceable, or why not.
 * \return      E_OK job accepted, E_NOT_OK otherwise (only in case runtime pending check fails).
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLReplaceLogicalSector(
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
    vMem_30_Tc3xxInf01_ReplaceSectorPtrType ReqSpecificData
  );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLGetRedundantSectorInfo()
 *********************************************************************************************************************/
/*!
 * \brief      Returns the information whether the requested sector is replaceable or not.
 * \details    Uses the global variable vMem_30_Tc3xxInf01_WorkSpace to retrieve sector index in order to compute
 *             correct offset for RedSec register. If first redundant sector is not available, second redundant sector
 *             is checked.
 * \param[in]  SectorIndex  Index of (physical) sector in array of sectors.
 * \param[in]  Address  Address of sector to be replaced.
 * \return     VMEM_30_TC3XXINF01_NO_REDUNDANT_SECTOR_AVAILABLE - sector cannot be replaced
 *             VMEM_30_TC3XXINF01_SECTOR_IS_REPLACEMENT_SECTOR - sector cannot be replaced
 *             VMEM_30_TC3XXINF01_SECTOR_REPLACEABLE - sector can be replaced
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(vMem_30_Tc3xxInf01_RedundantSectorInfoType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLGetRedundantSectorInfo(
  vMem_30_Tc3xxInf01_AddressType SectorIndex,
  vMem_30_Tc3xxInf01_AddressType Address
    );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLEvaluateRedSecRegister()
 *********************************************************************************************************************/
/*!
 * \brief      Returns the information whether the requested sector is replaceable or not.
 * \details    Performs read access of UCB register to check whether sector can be replaced or not. If redundant sector
 *             is used, compares addresses (of requested sector and in Redsec) to check whether requested sector is
 *             already replacement sector.
 * \param[in]  RegisterOffset  Offset within register Redsec (depends on sector index).
 * \param[in]  SectorIndex  Index of (physical) sector in array of sectors.
 * \param[in]  Address  Address of sector to be replaced.
 * \return     VMEM_30_TC3XXINF01_NO_REDUNDANT_SECTOR_AVAILABLE - sector cannot be replaced
 *             VMEM_30_TC3XXINF01_SECTOR_IS_REPLACEMENT_SECTOR - sector cannot be replaced
 *             VMEM_30_TC3XXINF01_SECTOR_REPLACEABLE - sector can be replaced
 * \pre        -
 * \context    TASK
 * \reentrant  FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL FUNC(vMem_30_Tc3xxInf01_RedundantSectorInfoType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLEvaluateRedSecRegister(
  vMem_30_Tc3xxInf01_AddressType RegisterOffset,
  vMem_30_Tc3xxInf01_AddressType SectorIndex,
  vMem_30_Tc3xxInf01_AddressType Address
  );

#if (VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API == STD_OFF)
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLReadRegister()
 *********************************************************************************************************************/
/*!
 *  \brief       Reads the register specified via BaseAddress and Offset memory mapped.
 *  \details     -
 *  \param[in]   BaseAddress
 *  \param[in]   Offset
 *  \config      VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(vMem_30_Tc3xxInf01_AddressType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLReadRegister(
  vMem_30_Tc3xxInf01_AddressType BaseAddress,
  vMem_30_Tc3xxInf01_AddressType Offset
  );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLWriteRegister()
 *********************************************************************************************************************/
/*!
 *  \brief       Writes the register specified via BaseAddress and Offset memory mapped.
 *  \details     -
 *  \param[in]   BaseAddress
 *  \param[in]   Offset
 *  \param[in]   Data
 *  \config      VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API disabled
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLWriteRegister(
  vMem_30_Tc3xxInf01_AddressType BaseAddress,
  vMem_30_Tc3xxInf01_AddressType Offset,
  vMem_30_Tc3xxInf01_AddressType Data
  );
#endif

#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLEraseRangeCheck()
 *********************************************************************************************************************/
/*!
 *  \brief       Checks that the requested erase range is within sector batch (=physical sector).
 *  \details     -
 *  \param[in]   SectorIndex
 *  \param[in]   Address
 *  \param[in]   Length
 *  \return      TRUE erase range is valid, FALSE otherwise.
 *  \config      VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLEraseRangeCheck(
  vMem_30_Tc3xxInf01_MemSectorIterType SectorIndex,
  vMem_30_Tc3xxInf01_AddressType Address,
  vMem_30_Tc3xxInf01_LengthType Length
  );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLSectorAddressCheck()
 *********************************************************************************************************************/
/*!
 * \brief        Checks that the passed address is aligned to a sector address
 * \details      -
 *  \param[in]   InstanceId
 *  \param[in]   Address
 *  \return      TRUE address is valid, FALSE otherwise.
 *  \config      VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLSectorAddressCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType Address
  );

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLIsPlatformAlignedForWordAccess()
 *********************************************************************************************************************/
/*!
 * \brief       Checks that the passed address is aligned to the TriCore specific alignment, i.e. 2 Byte.
 * \details     -
 * \param[in]   value to check for 2-Byte alignment
 * \return      TRUE value is aligned, FALSE otherwise.
 * \config      VMEM_30_TC3XXINF01_DEV_ERROR_DETECT enabled.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLIsPlatformAlignedForWordAccess(uint32 Value);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * vMem_30_Tc3xxInf01_LLStateIdle
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateIdle(void)
{
  boolean wait = TRUE;
  /* #10 Check if a new job has been accepted. */
  if(vMem_30_Tc3xxInf01_WorkSpace.currentJobResult == VMEM_JOB_PENDING)
  {
    /* #20 Asynchronous job available: go to first state of job and return FALSE (first job state shall be processed). */
    wait = FALSE;
    switch(vMem_30_Tc3xxInf01_WorkSpace.currentJob)
    {
    case VMEM_30_TC3XXINF01_ERASE_JOB:
      vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateErasePolling;
      break;
    case VMEM_30_TC3XXINF01_WRITE_JOB:
      vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateWritePageModePolling;
      break;
    case VMEM_30_TC3XXINF01_REPLACE_JOB:
      vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateReplaceSector;
      break;
    default: /* COV_VMEM_30_TC3XXINF01_DEFAULT */
      /* nothing to do, no valid job found, state remains IDLE */
      break;
    }
  }
  return wait;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLStateErasePolling
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateErasePolling(void)
{
  boolean retVal = TRUE;
  /* #10 Get result from last command. */
  vMem_30_Tc3xxInf01_JobResultType commandResult = vMem_30_Tc3xxInf01_LLGetCommandResult();
  /* #11 In case of an error go directly to finalize state  */
  if(commandResult == VMEM_JOB_FAILED) /* COV_VMEM_30_TC3XXINF01_ERROR_CHECK */
  {
    vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateFinalizePolling;
    retVal = FALSE;
  }
  /* #20 Otherwise, if hardware is no longer busy, start verify erased logical sector sequence */
  else if (commandResult == VMEM_JOB_OK)
  {
    /* #30 Issue verify erase sector range command sequence */
    vMem_30_Tc3xxInf01_LLVerifyErase(vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.currentAddress,
        vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.nrSectors, VMEM_30_TC3XXINF01_ERASE_VERIFY_SR_STEP4_DATA);

    /* #40 Next state is finalize polling */
    vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateFinalizePolling;
  }
  else
  {
    /* #50 Hardware is still busy */
  }
  return retVal;
}

/**********************************************************************************************************************
 * vMem_30_Tc3xxInf01_LLStateWritePageModePolling
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateWritePageModePolling(void)
{
  boolean retVal = TRUE;

  /* #10 In case of an error go directly to finalize state  */
  if ((vMem_30_Tc3xxInf01_GetDmuHFErrsr() & (VMEM_30_TC3XXINF01_ERRSR_SQER | VMEM_30_TC3XXINF01_ERRSR_PROER)) != 0x00u) /* COV_VMEM_30_TC3XXINF01_ERROR_CHECK */
  {
    vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateFinalizePolling;
    retVal = FALSE;
  }
  /* #20 Otherwise, if PFlash is in Page Mode, load and write the page */
  else if((vMem_30_Tc3xxInf01_GetDmuHFStatus() & VMEM_30_TC3XXINF01_STATUS_PFPAGE) != 0x00u) /* COV_VMEM_30_TC3XXINF01_HW_BUSY_CHECK */
  {
    vMem_30_Tc3xxInf01_LengthType i;
    /* At this point we assume the parameters are valid (parameter checks within the API ensures that). */
    uint32 flashWriteSize = vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.remainingLength;
    vMem_30_Tc3xxInf01_AddressType flashWriteCommand = VMEM_30_TC3XXINF01_WRITE_STEP4_DATA;

    /* #30 Unlock endinit for PFlash */
    vMem_30_Tc3xxInf01_Unlock(VMEM_30_TC3XXINF01_SYSTEM);

    /* #40 Load data - address differs for every second word */
    for (i = 0u; i < (flashWriteSize / 4u); i++)
    {
      /* #50 There is no critical section needed for this write access of vMem_30_Tc3xxInf01_WorkSpace (Reason: this state function is only called within
       * MainFunction. By then the job result is pending and no other job, that could interrupt, will be accepted.) */
      VMEM_30_TC3XXINF01_DSYNC();
      vMem_30_Tc3xxInf01_CommandCycle((VMEM_30_TC3XXINF01_LOAD_PAGE_ADDR + ((i & 1u) * 4u)), /* PRQA S 0316, 0311 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr, MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */ /* SBSW_vMem_RegisterAccess */
          ((vMem_30_Tc3xxInf01_WriteBuffer32PtrType)(vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.inBuffer))[i]);
      VMEM_30_TC3XXINF01_DSYNC();
    }

    /* Check if burst mode is used */
    if(vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.isBurst == TRUE)
    {
      flashWriteCommand = VMEM_30_TC3XXINF01_WRITE_BURST_STEP4_DATA;
    }
    /* #60 Write data */
    VMEM_30_TC3XXINF01_DSYNC();
    vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP1_ADDR, vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.currentAddress);
    VMEM_30_TC3XXINF01_DSYNC();
    vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP2_ADDR, VMEM_30_TC3XXINF01_WRITE_STEP2_DATA);
    VMEM_30_TC3XXINF01_DSYNC();
    vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP3_ADDR, VMEM_30_TC3XXINF01_WRITE_STEP3_DATA);
    VMEM_30_TC3XXINF01_DSYNC();
    vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP4_ADDR, flashWriteCommand);
    VMEM_30_TC3XXINF01_DSYNC();

    /* #70 Lock endinit for PFlash */
    vMem_30_Tc3xxInf01_Lock(VMEM_30_TC3XXINF01_SYSTEM);

    /* #80 Next state is finalize polling */
    vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateFinalizePolling;

  }
  /* #90 If PFlash is not in Page Mode, yet, remain in this state and check again in next MainFunction */
  else
  {
    /* Flash is not in Page Mode, yet. */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLStateReplaceSector
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateReplaceSector(void)
{
  /* #10 Erase all pending error flags */
  vMem_30_Tc3xxInf01_LLClearStatusCommand();

  /* #20 Unlock endinit for PFlash */
  vMem_30_Tc3xxInf01_Unlock(VMEM_30_TC3XXINF01_SYSTEM);

  /* #30 Issue Replace logical sector command */
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP1_ADDR, vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.currentAddress);
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP2_ADDR, VMEM_30_TC3XXINF01_REPLACE_SECTOR_STEP2_DATA);
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP3_ADDR, VMEM_30_TC3XXINF01_REPLACE_SECTOR_STEP3_DATA);
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP4_ADDR, VMEM_30_TC3XXINF01_REPLACE_SECTOR_STEP4_DATA);
  VMEM_30_TC3XXINF01_DSYNC();

  /* #40 Lock endinit for PFlash */
  vMem_30_Tc3xxInf01_Lock(VMEM_30_TC3XXINF01_SYSTEM);

  /* #50 Next state is finalize polling */
  vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateFinalizePolling;

  /* #60 MainFunction shall return in any case to wait for the command to be executed. */
  return TRUE;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLStateFinalizePolling
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLStateFinalizePolling(void)
{
  /* #10 Get result from last command. */
  vMem_30_Tc3xxInf01_JobResultType commandResult = vMem_30_Tc3xxInf01_LLGetCommandResult();
  if(commandResult == VMEM_JOB_FAILED) /* COV_VMEM_30_TC3XXINF01_ERROR_CHECK */
  {
    /* #20 Finalize job unsuccessful in case of Error */
    vMem_30_Tc3xxInf01_LLFinalizeJob(commandResult);
  }
  else if (commandResult == VMEM_JOB_OK)
  {
    /* #30 Finalize job successful if there is no error and hardware is no longer busy. */
    vMem_30_Tc3xxInf01_LLFinalizeJob(commandResult);
  }
  else
  {
    /* #40 Hardware is still busy */
  }
  /* #50 Return TRUE in any case: next job is not performed in this MainFunction. */
  return TRUE;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLGetCommandResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(vMem_30_Tc3xxInf01_JobResultType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLGetCommandResult(void)
{
  vMem_30_Tc3xxInf01_JobResultType retVal = VMEM_JOB_PENDING;
  vMem_30_Tc3xxInf01_AddressType operationState = vMem_30_Tc3xxInf01_GetDmuHFOperation();
  vMem_30_Tc3xxInf01_AddressType busyState = vMem_30_Tc3xxInf01_GetDmuHFStatus();
  vMem_30_Tc3xxInf01_AddressType errorState = vMem_30_Tc3xxInf01_GetDmuHFErrsr();
  
  /* #10 Fail if sequence or protection error. */
  if((errorState & (VMEM_30_TC3XXINF01_ERRSR_SQER | VMEM_30_TC3XXINF01_ERRSR_PROER)) != 0x00u)
  {
    retVal = VMEM_JOB_FAILED;
  }
  /* #20 Check if program/replace sector/(verify) erase command was accepted. */
  else if(((operationState & (VMEM_30_TC3XXINF01_OPERATION_PROG | VMEM_30_TC3XXINF01_OPERATION_ERASE)) != 0x00u)) /* COV_VMEM_30_TC3XXINF01_HW_BUSY_CHECK */
  {
    /* #30 Check if busy bits are reset by hardware. */
    if((busyState & VMEM_30_TC3XXINF01_STATUS_BUSY) == 0x00u)
    {
      /* #40 If no error is indicated by hardware command has been successfully executed. */
      if((errorState & VMEM_30_TC3XXINF01_ERRSR_ERROR) == 0x00u)
      {
        retVal = VMEM_JOB_OK;
      }
      /* #50 Fail otherwise. */
      else
      {
        retVal = VMEM_JOB_FAILED;
      }
    }
    /* #60 Detect hardware failures causing hardware to stay BUSY by checking for operation error.  */
    else if((errorState & VMEM_30_TC3XXINF01_ERRSR_OPER) != 0x00u) /* COV_VMEM_30_TC3XXINF01_ERROR_CHECK */
    {
      retVal = VMEM_JOB_FAILED;
    }
    else
    {
      /* No error, but hardware is still busy. */
    }
  }
  else
  {
    /* Command has not been accepted, yet. */
  }

  vMem_30_Tc3xxInf01_WorkSpace.currentErrorResult = errorState;
  return retVal;
}


/**********************************************************************************************************************
 * vMem_30_Tc3xxInf01_LLTryJobSetup
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLTryJobSetup(
  vMem_30_Tc3xxInf01_JobType Job,
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_ConstDataPtrType SourceAddressPtr,
  vMem_30_Tc3xxInf01_LengthType Length,
  vMem_30_Tc3xxInf01_MemSectorIterType SectorIndex,
  boolean IsBurst
  )
{
  boolean jobAccepted = FALSE;
  /* #10 Enter critical section (Reason: the setting of current job parameters must not be interrupted by
   * another job request). */
  SchM_Enter_vMem_30_Tc3xxInf01_VMEM_30_TC3XXINF01_EXCLUSIVE_AREA_0();
  /* #20 Implement a second pending check (runtime, always available) */
  if (vMem_30_Tc3xxInf01_WorkSpace.currentJobResult != VMEM_JOB_PENDING)
  {
    /* #30 Set job result to pending. */
    vMem_30_Tc3xxInf01_WorkSpace.currentJobResult = VMEM_JOB_PENDING;
    /* #40 Save all job input parameter of the current job. */
    vMem_30_Tc3xxInf01_WorkSpace.currentJob = Job;
    vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.currentAddress    = TargetAddress;
    vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.inBuffer          = SourceAddressPtr;
    vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.remainingLength   = Length;
    vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.isBurst           = IsBurst;
    vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.sectorIndex       = SectorIndex;
    vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.nrSectors         = Length / vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(SectorIndex);
    jobAccepted = TRUE;
  }
  /* #50 Leave critical section */
  SchM_Exit_vMem_30_Tc3xxInf01_VMEM_30_TC3XXINF01_EXCLUSIVE_AREA_0();

  return jobAccepted;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 * vMem_30_Tc3xxInf01_LLFinalizeJob
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLFinalizeJob(vMem_30_Tc3xxInf01_JobResultType JobResult)
{
  /* #10 Reset hardware status */
  if (vMem_30_Tc3xxInf01_WorkSpace.currentJob == VMEM_30_TC3XXINF01_WRITE_JOB)
  {
    vMem_30_Tc3xxInf01_LLResetToRead();
  }
  vMem_30_Tc3xxInf01_LLClearStatusCommand(); 

  /* #20 Set job result to failed and next state to idle */
  /* #30 There is no critical section needed for this write access of vMem_30_Tc3xxInf01_WorkSpace (Reason: this local function is only called within
   * MainFunction. The job result is set to not pending, at the latest point possible within the job.) */
  vMem_30_Tc3xxInf01_WorkSpace.currentJobResult = JobResult;
  vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateIdle;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLGetSectorIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(vMem_30_Tc3xxInf01_MemSectorIterType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLGetSectorIndex(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, vMem_30_Tc3xxInf01_AddressType Address)
{
  vMem_30_Tc3xxInf01_MemSectorIterType sectorIndex;
  for (sectorIndex = vMem_30_Tc3xxInf01_GetMemSectorStartIdxOfvMemInstance(InstanceId); sectorIndex < (vMem_30_Tc3xxInf01_GetMemSectorEndIdxOfvMemInstance(InstanceId) - 1u); sectorIndex++)
  {
    /* The address may be equal to the start address or even higher. It shall also be lower than the
     * end of the sector (batch). -1 takes care about overflows - the sector batch may be located
     * at the end of the address range. */
    if((Address >= vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(sectorIndex)) &&
      (Address <= (vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(sectorIndex) +
          (((vMem_30_Tc3xxInf01_AddressType)(vMem_30_Tc3xxInf01_GetNrOfSectorsOfMemSector(sectorIndex)) * vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(sectorIndex)) - 1u))))
    {
      break;
    }
  }
  return sectorIndex;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLResetToRead()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLResetToRead(void)
{
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_RESET_TO_READ_ADDR, VMEM_30_TC3XXINF01_RESET_TO_READ_DATA);
  VMEM_30_TC3XXINF01_DSYNC();
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLClearStatusCommand()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLClearStatusCommand(void)
{
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_CLEAR_STATUS_ADDR, VMEM_30_TC3XXINF01_CLEAR_STATUS_DATA);
  VMEM_30_TC3XXINF01_DSYNC();
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLVerifyErase()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLVerifyErase(
  vMem_30_Tc3xxInf01_AddressType Address,
  vMem_30_Tc3xxInf01_LengthType VerifyEraseLength,
  vMem_30_Tc3xxInf01_LengthType VerifyEraseCommand
  )
{
  /* #10 Erase all pending error flags */
  vMem_30_Tc3xxInf01_LLClearStatusCommand();

  /* #20 Verify if sector range is erased */
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP1_ADDR, Address);
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP2_ADDR, VerifyEraseLength);
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP3_ADDR, VMEM_30_TC3XXINF01_ERASE_VERIFY_STEP3_DATA);
  VMEM_30_TC3XXINF01_DSYNC();
  vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP4_ADDR, VerifyEraseCommand);
  VMEM_30_TC3XXINF01_DSYNC();
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLPageBlankCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLPageBlankCheck(void)
{
  vMem_30_Tc3xxInf01_LLVerifyErase(vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.currentAddress,
      VMEM_30_TC3XXINF01_ERASE_VERIFY_STEP2_DATA, VMEM_30_TC3XXINF01_ERASE_VERIFY_PAGE_STEP4_DATA);

  do
  {
  } while (vMem_30_Tc3xxInf01_LLGetCommandResult() == VMEM_JOB_PENDING);

  switch (vMem_30_Tc3xxInf01_WorkSpace.currentErrorResult & VMEM_30_TC3XXINF01_ERRSR_ERROR)
  {
    case VMEM_30_TC3XXINF01_ERRSR_NOERROR:
      vMem_30_Tc3xxInf01_WorkSpace.currentJobResult = VMEM_JOB_OK;
      break;
    case VMEM_30_TC3XXINF01_ERRSR_EVER:
      vMem_30_Tc3xxInf01_WorkSpace.currentJobResult = VMEM_MEM_NOT_BLANK;
      break;
  default:
      vMem_30_Tc3xxInf01_WorkSpace.currentJobResult = VMEM_JOB_FAILED;
      break;
  }
  vMem_30_Tc3xxInf01_LLClearStatusCommand();
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLReplaceLogicalSector()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLReplaceLogicalSector(
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
    vMem_30_Tc3xxInf01_ReplaceSectorPtrType ReqSpecificData
  )
{
  Std_ReturnType retVal = E_NOT_OK;
  /* PRQA S 0316 1 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
  vMem_30_Tc3xxInf01_AddressType targetAddress = ((vMem_30_Tc3xxInf01_ReplaceSectorPtrType)ReqSpecificData)->TargetAddress;
  vMem_30_Tc3xxInf01_MemSectorIterType sectorIndex = vMem_30_Tc3xxInf01_LLGetSectorIndex(InstanceId, targetAddress);

  /* #10 Try to set up the job. */
  if(vMem_30_Tc3xxInf01_LLTryJobSetup(VMEM_30_TC3XXINF01_REPLACE_JOB, targetAddress, NULL_PTR,
      vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(sectorIndex), sectorIndex, FALSE) == TRUE)
  {
    /* #20 Get redundant sector info. */
    /* PRQA S 0316 1 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
    ((vMem_30_Tc3xxInf01_ReplaceSectorPtrType)ReqSpecificData)->RedundantSectorInfo = vMem_30_Tc3xxInf01_LLGetRedundantSectorInfo(sectorIndex, targetAddress);
    /* #30 If sector is not replaceable finalize job unsuccessful. */
    /* PRQA S 0316 1 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
    if (((vMem_30_Tc3xxInf01_ReplaceSectorPtrType)ReqSpecificData)->RedundantSectorInfo != VMEM_30_TC3XXINF01_SECTOR_REPLACEABLE)
    {
      vMem_30_Tc3xxInf01_LLFinalizeJob(VMEM_JOB_FAILED);
    }

    /*#40 Job was accepted, even if sector cannot be replaced. */
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLGetRedundantSectorInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(vMem_30_Tc3xxInf01_RedundantSectorInfoType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLGetRedundantSectorInfo(
  vMem_30_Tc3xxInf01_AddressType SectorIndex,
  vMem_30_Tc3xxInf01_AddressType Address
    )
{
  vMem_30_Tc3xxInf01_RedundantSectorInfoType redundantSectorInfo;

  /* #10 Compute register offset for Redsec with sector index. */
  vMem_30_Tc3xxInf01_AddressType registerOffset =
      (vMem_30_Tc3xxInf01_GetProgramFlashIdOfMemSector(SectorIndex) * VMEM_30_TC3XXINF01_REDSECP_PFLASH_STEP) +
      (vMem_30_Tc3xxInf01_GetPhysicalSectorIdOfMemSector(SectorIndex) * VMEM_30_TC3XXINF01_REDSECP_PSECTOR_STEP);

  /* #20 Evaluate first redundant sector entry of Redsec register. */
  redundantSectorInfo = vMem_30_Tc3xxInf01_LLEvaluateRedSecRegister(registerOffset, SectorIndex, Address);

  /* #30 If first redundant sector is not available */
  if (redundantSectorInfo == VMEM_30_TC3XXINF01_NO_REDUNDANT_SECTOR_AVAILABLE)
  {
    /* #40 Evaluate second redundant sector entry of Redsec register. */
    redundantSectorInfo = vMem_30_Tc3xxInf01_LLEvaluateRedSecRegister(registerOffset + VMEM_30_TC3XXINF01_REDSECP_SECOND_ENTRY, SectorIndex, Address);
  }
  return redundantSectorInfo;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLEvaluateRedSecRegister()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL FUNC(vMem_30_Tc3xxInf01_RedundantSectorInfoType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLEvaluateRedSecRegister(
    vMem_30_Tc3xxInf01_AddressType RegisterOffset,
    vMem_30_Tc3xxInf01_AddressType SectorIndex,
    vMem_30_Tc3xxInf01_AddressType Address
  )
{
  vMem_30_Tc3xxInf01_RedundantSectorInfoType redundantSectorInfo;

  /* #10 Read the information from register Redsec. */
  vMem_30_Tc3xxInf01_AddressType redsecInfo = vMem_30_Tc3xxInf01_GetUcbRedSec(RegisterOffset);

  /* #20 If redundancy is FAIL, redundant sector is not available. */
  if((redsecInfo & VMEM_30_TC3XXINF01_REDSECP_FAIL) == VMEM_30_TC3XXINF01_REDSECP_FAIL)
  {
    redundantSectorInfo = VMEM_30_TC3XXINF01_NO_REDUNDANT_SECTOR_AVAILABLE;
  }
  /* #30 Otherwise if redundancy is USED  */
  else if((redsecInfo & VMEM_30_TC3XXINF01_REDSECP_USED) == VMEM_30_TC3XXINF01_REDSECP_USED)
  {
    /* #40 Compute the index of the logical sector within the phyiscal sector (range 0-63) */
    /* The logicalSectorIndex is needed to check, whether the sector is already a replacement sector. */
    vMem_30_Tc3xxInf01_AddressType logicalSectorIndex = (Address - vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(SectorIndex)) /
        (vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(SectorIndex));
    /* #50 and if requested sector is used, sector is already replacement sector. */
    if((redsecInfo & VMEM_30_TC3XXINF01_REDSECP_SECTOR_ADDRESS) == logicalSectorIndex)
    {
      redundantSectorInfo = VMEM_30_TC3XXINF01_SECTOR_IS_REPLACEMENT_SECTOR;
    }
    /*#60 Otherwise redundant sector is simply not available. */
    else
    {
      redundantSectorInfo = VMEM_30_TC3XXINF01_NO_REDUNDANT_SECTOR_AVAILABLE;
    }
  }
  /* #70 Otherwise sector can be replaced. */
  else
  {
    redundantSectorInfo = VMEM_30_TC3XXINF01_SECTOR_REPLACEABLE;
  }
  return redundantSectorInfo;
}

#if (VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API == STD_OFF)
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLReadRegister()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(vMem_30_Tc3xxInf01_AddressType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLReadRegister(
  vMem_30_Tc3xxInf01_AddressType BaseAddress,
  vMem_30_Tc3xxInf01_AddressType Offset
  )
{
  return *((vMem_30_Tc3xxInf01_RegPtrType)(BaseAddress + Offset)); /* PRQA S 0303 */ /* MD_vMem_30_Tc3xxInf01_RegisterAccess */
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLWriteRegister()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLWriteRegister(
  vMem_30_Tc3xxInf01_AddressType BaseAddress,
  vMem_30_Tc3xxInf01_AddressType Offset,
  vMem_30_Tc3xxInf01_AddressType Data
  )
{
  /* #10 Depending on Usecase */
#ifndef VHSM_CODE /* COV_VMEM_30_TC3XXINF01_USECASE */
  /* #20 Writes the data to the register specified by BaseAddress and Offset */
  /* PRQA S 0303 1 */ /* MD_vMem_30_Tc3xxInf01_RegisterAccess */
  *((vMem_30_Tc3xxInf01_RegPtrType)(BaseAddress + Offset)) = ((vMem_30_Tc3xxInf01_AddressType) (Data));
#else
  /* #30 Or prepare Host access through HSM Bridge - access window enabled */
  /* PRQA S 0303 1 */ /* MD_vMem_30_Tc3xxInf01_RegisterAccess */
  *((vMem_30_Tc3xxInf01_RegPtrType)
      (VMEM_30_TC3XXINF01_HSM_BRIDGE + VMEM_30_TC3XXINF01_HSM_SAHBASE_OFFSET)) = (BaseAddress & 0xFFFF0000u);

  /* #40 Write specific address in 16K base address */
  /* PRQA S 0303 1 */ /* MD_vMem_30_Tc3xxInf01_RegisterAccess */
  *((vMem_30_Tc3xxInf01_RegPtrType)
      ((Offset & 0x0000FFFFu) | (VMEM_30_TC3XXINF01_HSM_BRIDGE + VMEM_30_TC3XXINF01_HSM_SAHMEM_OFFSET))) = Data;

  /* #50 Wait for DSYNC */
  VMEM_30_TC3XXINF01_DSYNC();
#endif
}
#endif

#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLEraseRangeCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLEraseRangeCheck(
  vMem_30_Tc3xxInf01_MemSectorIterType SectorIndex,
  vMem_30_Tc3xxInf01_AddressType Address,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* #10 Check that given erase address range is within sector batch */
  return ((Address + Length) <= (vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(SectorIndex)
            + (vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(SectorIndex) * (vMem_30_Tc3xxInf01_AddressType)(vMem_30_Tc3xxInf01_GetNrOfSectorsOfMemSector(SectorIndex)))))
            ? TRUE : FALSE ;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLSectorAddressCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLSectorAddressCheck(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
  vMem_30_Tc3xxInf01_AddressType Address
  )
{
  boolean retVal = FALSE;
  uint32 sectorIndex = vMem_30_Tc3xxInf01_LLGetSectorIndex(InstanceId, Address);
  if(sectorIndex < vMem_30_Tc3xxInf01_GetMemSectorEndIdxOfvMemInstance(InstanceId)) /* COV_VMEM_30_TC3XXINF01_SECTOR_INDEX */
  {
    /* StartAddress of SectorBatch is not always aligned to SectorSize. Take offset into account for alignment check. */
    retVal = (((Address - vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(sectorIndex)) %
        vMem_30_Tc3xxInf01_GetSectorSizeOfMemSector(sectorIndex)) == 0u) ? TRUE : FALSE ;
  }
  return retVal;
}


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLIsPlatformAlignedForWordAccess()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VMEM_30_TC3XXINF01_LOCAL_INLINE FUNC(boolean, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLIsPlatformAlignedForWordAccess(uint32 Value)
{
  const uint32 cpuAlignment = 2;
  return ((Value % cpuAlignment) == 0u) ? TRUE : FALSE ;
}

#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLRead
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLRead(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, /* PRQA S 3206 */ /* MD_vMem_30_Tc3xxInf01_UnusedParam */
  vMem_30_Tc3xxInf01_AddressType SourceAddress,
  vMem_30_Tc3xxInf01_DataPtrType TargetAddressPtr,
  vMem_30_Tc3xxInf01_LengthType Length)
{
  Std_ReturnType retVal = E_NOT_OK;
  /* We already know InstanceId and SourceAddress is valid, because of parameter checks in core. */
  vMem_30_Tc3xxInf01_MemSectorIterType sectorIndex = vMem_30_Tc3xxInf01_LLGetSectorIndex(InstanceId, SourceAddress);

  /* #10 Try to setup the job */
  if(vMem_30_Tc3xxInf01_LLTryJobSetup(VMEM_30_TC3XXINF01_READ_JOB, SourceAddress, TargetAddressPtr, Length, sectorIndex, FALSE) == TRUE)
  {
    vMem_30_Tc3xxInf01_LengthType index;
    vMem_30_Tc3xxInf01_WriteBuffer8PtrType userBufferTyped = (vMem_30_Tc3xxInf01_WriteBuffer8PtrType)TargetAddressPtr; /* PRQA S 0316 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
    vMem_30_Tc3xxInf01_ReadBufferPtrType sourceBuffer;

    /* #20 Re-map read address in case of alternate mapping, i.e. if address region B is active. */
    if(vMem_30_Tc3xxInf01_ActiveAddressRegion == VMEM_30_TC3XXINF01_ADDRESS_REGION_B)
    {
      vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.currentAddress += vMem_30_Tc3xxInf01_GetAlternateAddressOfMemSector(sectorIndex)
        - vMem_30_Tc3xxInf01_GetStartAddressOfMemSector(sectorIndex);
    }

    sourceBuffer = (vMem_30_Tc3xxInf01_ReadBufferPtrType)vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.currentAddress; /* PRQA S 0306 */ /* MD_vMem_30_Tc3xxInf01_FlashReadAccess */

    /* #30 Perform read synchronously bytewise */
    for(index = 0u; index < Length; index++)
    {
      userBufferTyped[index] = sourceBuffer[index];
    }

    vMem_30_Tc3xxInf01_WorkSpace.currentJobResult = VMEM_JOB_OK;
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLWrite
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLWrite(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, /* PRQA S 3206 */ /* MD_vMem_30_Tc3xxInf01_UnusedParam */
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_ConstDataPtrType SourceAddressPtr,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;

#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (vMem_30_Tc3xxInf01_LLIsPlatformAlignedForWordAccess((uint32) SourceAddressPtr) == FALSE) /* PRQA S 0326 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_BUFFER_ALIGNMENT;
  }
  else
#endif
  {
    /* InstanceId and SourceAddress is valid, because of parameter checks in core. */
    vMem_30_Tc3xxInf01_MemSectorIterType sectorIndex = vMem_30_Tc3xxInf01_LLGetSectorIndex(InstanceId, TargetAddress);

    /* Note: in case burst settings are not configured, generated writeBurstSize = pageSize */
    boolean isBurst =  (Length > vMem_30_Tc3xxInf01_GetPageSizeOfMemSector(sectorIndex)) ? TRUE : FALSE ;
    if(((isBurst == TRUE) && ((TargetAddress % vMem_30_Tc3xxInf01_GetWriteBurstSizeOfMemSector(sectorIndex)) == 0u))
        || (isBurst == FALSE))
    {
      if(vMem_30_Tc3xxInf01_LLTryJobSetup(VMEM_30_TC3XXINF01_WRITE_JOB, TargetAddress, SourceAddressPtr, Length, sectorIndex, isBurst) == TRUE)
      {
        vMem_30_Tc3xxInf01_LLClearStatusCommand(); 

        vMem_30_Tc3xxInf01_Unlock(VMEM_30_TC3XXINF01_SYSTEM);

        VMEM_30_TC3XXINF01_DSYNC();
        vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_ENTER_PAGE_MODE_ADDR, VMEM_30_TC3XXINF01_ENTER_PAGE_MODE_DATA);
        VMEM_30_TC3XXINF01_DSYNC();

        vMem_30_Tc3xxInf01_Lock(VMEM_30_TC3XXINF01_SYSTEM);
        retVal = E_OK;
      }
    }
  }

#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    /*  Error found, depending on configuration report the error or invoke DUMMY_STATEMENT. */
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_WRITE, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId);
#endif

  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLErase
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLErase(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, /* PRQA S 3206 */ /* MD_vMem_30_Tc3xxInf01_UnusedParam */
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_LengthType Length
  )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  /* We already know InstanceId and SourceAddress is valid, because of parameter checks in core. */
  vMem_30_Tc3xxInf01_MemSectorIterType sectorIndex = vMem_30_Tc3xxInf01_LLGetSectorIndex(InstanceId, TargetAddress);

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  /* Erase range check */
  if (vMem_30_Tc3xxInf01_LLEraseRangeCheck(sectorIndex, TargetAddress, Length) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }
  else
#endif
  {
    /* #10 Try to setup the job */
    if(vMem_30_Tc3xxInf01_LLTryJobSetup(VMEM_30_TC3XXINF01_ERASE_JOB, TargetAddress, NULL_PTR, Length, sectorIndex, FALSE) == TRUE)
    {
      /* #20 Erase all pending error flags */
      vMem_30_Tc3xxInf01_LLClearStatusCommand(); 

      /* #30 Unlock endinit for PFlash */
      vMem_30_Tc3xxInf01_Unlock( VMEM_30_TC3XXINF01_SYSTEM );

      /* #40 Erase sector range */
      VMEM_30_TC3XXINF01_DSYNC();
      vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP1_ADDR, TargetAddress);
      VMEM_30_TC3XXINF01_DSYNC();
      vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP2_ADDR, vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.nrSectors);
      VMEM_30_TC3XXINF01_DSYNC();
      vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP3_ADDR, VMEM_30_TC3XXINF01_ERASE_STEP3_DATA);
      VMEM_30_TC3XXINF01_DSYNC();
      vMem_30_Tc3xxInf01_CommandCycle(VMEM_30_TC3XXINF01_PROG_STEP4_ADDR, VMEM_30_TC3XXINF01_ERASE_STEP4_DATA);
      VMEM_30_TC3XXINF01_DSYNC();

      /* #50 Lock endinit for PFlash */
      vMem_30_Tc3xxInf01_Lock( VMEM_30_TC3XXINF01_SYSTEM );
      retVal = E_OK;
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    /*  Error found, depending on configuration report the error or invoke DUMMY_STATEMENT. */
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_ERASE, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId);
#endif
  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLIsBlank
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLIsBlank(
  vMem_30_Tc3xxInf01_InstanceIdType InstanceId, /* PRQA S 3206 */ /* MD_vMem_30_Tc3xxInf01_UnusedParam */
  vMem_30_Tc3xxInf01_AddressType TargetAddress,
  vMem_30_Tc3xxInf01_LengthType Length) /* PRQA S 3206 */ /* MD_vMem_30_Tc3xxInf01_UnusedParam */
{
  Std_ReturnType retVal = E_NOT_OK;
  
  vMem_30_Tc3xxInf01_MemSectorIterType sectorIndex = vMem_30_Tc3xxInf01_LLGetSectorIndex(InstanceId, TargetAddress);
  if(vMem_30_Tc3xxInf01_LLTryJobSetup(VMEM_30_TC3XXINF01_ISBLANK_JOB, TargetAddress, NULL_PTR, Length, sectorIndex, FALSE) == TRUE )
  {
    vMem_30_Tc3xxInf01_LLPageBlankCheck();
    retVal = E_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 * vMem_30_Tc3xxInf01_LLGetJobResult
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(vMem_30_Tc3xxInf01_JobResultType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLGetJobResult(
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId) /* PRQA S 3206 */ /* MD_vMem_30_Tc3xxInf01_UnusedParam */
{
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(InstanceId);
  return vMem_30_Tc3xxInf01_WorkSpace.currentJobResult;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLProcessing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLProcessing(void)
{
  boolean wait;
  do
  {
    wait = vMem_30_Tc3xxInf01_NextStatePtr(); /* SBSW_vMem_Statemachine */
  } while (wait == FALSE);
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_LLInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_LLInit(void)
{
  /* #10 Reset states */
  /* #20 There is no critical section needed during initialization (Reason: no jobs will be accepted, before module is initialized) */
  Std_ReturnType retVal;
  vMem_30_Tc3xxInf01_WorkSpace.currentJob = VMEM_30_TC3XXINF01_NO_JOB;
  vMem_30_Tc3xxInf01_WorkSpace.currentJobParameter.remainingLength = 0;
  vMem_30_Tc3xxInf01_WorkSpace.currentJobResult = VMEM_JOB_OK;

  /* #30 Fall back to read mode by default */
  vMem_30_Tc3xxInf01_LLResetToRead();
  vMem_30_Tc3xxInf01_LLClearStatusCommand();

  /* #40 Determine active address region with corresponding public service. */
  /* GetActiveAddressRegion does not use parameter InstanceId and SizeOfData. */
  retVal = vMem_30_Tc3xxInf01_GetActiveAddressRegion(0, (vMem_30_Tc3xxInf01_DataPtrType)(&vMem_30_Tc3xxInf01_ActiveAddressRegion), 0); /* PRQA S 0314 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */

  vMem_30_Tc3xxInf01_NextStatePtr = vMem_30_Tc3xxInf01_LLStateIdle;

  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetActiveAddressRegion
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetActiveAddressRegion( /* PRQA S 1505 */ /* MD_vMem_30_Tc3xxInf01_ExtendedApi */
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId, /* PRQA S 3206 */ /* MD_vMem_30_Tc3xxInf01_UnusedParam */
    vMem_30_Tc3xxInf01_DataPtrType ReqSpecificData,
    uint32 SizeOfData /* PRQA S 3206 */ /* MD_vMem_30_Tc3xxInf01_SizeOfData */
    )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  /* #10 Null pointer check */
  if (ReqSpecificData == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 No error: read Alternate Address Control Register and determine if region A or B is active. */
    if((vMem_30_Tc3xxInf01_GetScuSwapCtrl() & VMEM_30_TC3XXINF01_REGION_A_ACTIVE) == VMEM_30_TC3XXINF01_REGION_A_ACTIVE) /* COV_VMEM_30_TC3XXINF01_ADDRESS_REGION */
    {
      *((vMem_30_Tc3xxInf01_AddressRegionType*)ReqSpecificData) = VMEM_30_TC3XXINF01_ADDRESS_REGION_A; /* COV_VMEM_30_TC3XXINF01_ADDRESS_REGION */ /* PRQA S 0316 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */ /* SBSW_vMem_UserPointer */
      retVal = E_OK;
    }
    else if((vMem_30_Tc3xxInf01_GetScuSwapCtrl() & VMEM_30_TC3XXINF01_REGION_B_ACTIVE) == VMEM_30_TC3XXINF01_REGION_B_ACTIVE) /* COV_VMEM_30_TC3XXINF01_ADDRESS_REGION */
    {
      *((vMem_30_Tc3xxInf01_AddressRegionType*)ReqSpecificData) = VMEM_30_TC3XXINF01_ADDRESS_REGION_B; /* PRQA S 0316 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */ /* SBSW_vMem_UserPointer */
      retVal = E_OK;
    }
    else /* COV_VMEM_30_TC3XXINF01_ADDRESS_REGION */
    {
      /* Invalid data in register, nothing to do. */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    /*#30 Error found, depending on configuration report the error or invoke DUMMY_STATEMENT. */
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_GET_ACTIVE_ADDRESS_REGION, errorId);
  }
#else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId);
#endif

  /* The signature of the extended hardware specific functionality is defined by the vMemAccM. For this service the parameter InstanceId and
   * SizeOfData are not needed: InstanceId is not needed in vMem_30_Tc3xxInf01, since there is only one instance. The SizeOfData is not needed
   * for this service, since ReqSpecificData is only a pointer to a variable, not an array.
   */
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(InstanceId);
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(SizeOfData);
  return retVal;
}

/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_ReplaceLogicalSector
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_ReplaceLogicalSector(
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
    vMem_30_Tc3xxInf01_DataPtrType ReqSpecificData,
    uint32 SizeOfData
    )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (ReqSpecificData == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else if (SizeOfData != sizeof(vMem_30_Tc3xxInf01_ReplaceSectorType))
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else if (InstanceId >= vMem_30_Tc3xxInf01_GetSizeOfvMemInstance())
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_WorkSpace.currentJobResult == VMEM_JOB_PENDING)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  /* PRQA S 0316 1 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
  else if(vMem_30_Tc3xxInf01_LLSectorAddressCheck(InstanceId, ((vMem_30_Tc3xxInf01_ReplaceSectorPtrType)ReqSpecificData)->TargetAddress) == FALSE)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_ADDRESS;
  }

  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #60 If Checks passed attempt the sector replacement for the requested address. */
    /* PRQA S 0316 1 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
    retVal = vMem_30_Tc3xxInf01_LLReplaceLogicalSector(InstanceId, (vMem_30_Tc3xxInf01_ReplaceSectorPtrType)ReqSpecificData);
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_REPLACE_LOGICAL_SECTOR, errorId);
  }
# else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId);
# endif

  /* The signature of the extended hardware specific functionality is defined by the vMemAccM. For this service the parameters InstanceId
   * and SizeOfData are not needed if Development Error Checks are disabled.
   */
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(InstanceId);
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(SizeOfData);
  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/**********************************************************************************************************************
 *  vMem_30_Tc3xxInf01_GetLastErrorState
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VMEM_30_TC3XXINF01_CODE) vMem_30_Tc3xxInf01_GetLastErrorState(
    vMem_30_Tc3xxInf01_InstanceIdType InstanceId,
    vMem_30_Tc3xxInf01_DataPtrType ReqSpecificData,
    uint32 SizeOfData
    )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = VMEM_30_TC3XXINF01_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
# if (VMEM_30_TC3XXINF01_DEV_ERROR_DETECT == STD_ON)
  if (ReqSpecificData == NULL_PTR)
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_POINTER;
  }
  else if (SizeOfData != sizeof(vMem_30_Tc3xxInf01_ErrorStateType))
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_LENGTH;
  }
  else if (InstanceId >= vMem_30_Tc3xxInf01_GetSizeOfvMemInstance())
  {
    errorId = VMEM_30_TC3XXINF01_E_PARAM_INSTANCE_ID;
  }
  else if (vMem_30_Tc3xxInf01_WorkSpace.currentJobResult == VMEM_JOB_PENDING)
  {
    errorId = VMEM_30_TC3XXINF01_E_PENDING;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* PRQA S 0316 1 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
    ((vMem_30_Tc3xxInf01_ErrorStateType*)ReqSpecificData)->currentJob = vMem_30_Tc3xxInf01_WorkSpace.currentJob;
    /* PRQA S 0316 1 */ /* MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr */
    ((vMem_30_Tc3xxInf01_ErrorStateType*)ReqSpecificData)->currentErrorState = vMem_30_Tc3xxInf01_WorkSpace.currentErrorResult;
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (VMEM_30_TC3XXINF01_DEV_ERROR_REPORT == STD_ON)
  if (errorId != VMEM_30_TC3XXINF01_E_NO_ERROR)
  {
    (void)Det_ReportError(VMEM_30_TC3XXINF01_MODULE_ID, VMEM_30_TC3XXINF01_INSTANCE_ID_DET, VMEM_30_TC3XXINF01_SID_GET_LAST_ERROR_STATE, errorId);
  }
# else
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(errorId);
# endif

  /* The signature of the extended hardware specific functionality is defined by the vMemAccM. For this service the parameters InstanceId
   * and SizeOfData are not needed if Development Error Checks are disabled.
   */
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(InstanceId);
  VMEM_30_TC3XXINF01_DUMMY_STATEMENT(SizeOfData);
  return retVal;
}

#define VMEM_30_TC3XXINF01_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:

  MD_vMem_30_Tc3xxInf01_RegisterAccess: rule 11.4
    Reason:     vMem accesses memory mapped registers. Depending on configuration this is done via the OS peripheral access API,
                or it is done directly, which involves a cast between a pointer to a volatile object and an integral type.
    Risk:       Size of pointer type is hardware specific - not compatible between platforms. Invalid memory access.
    Prevention: No prevention.

  MD_vMem_30_Tc3xxInf01_UnusedParam: rule 2.7
    Reason:     There are vMem driver supporting multiple instances. However, the module vMem_30_Tc3xxInf01 consists of only one instance
                and thus does not use the parameter InstanceId.
                The vMem_30_Tc3xxInf01_LLIsBlank interface to the core component is actually defined by the core and cannot be modified by the
                low-level implementation.
    Risk:       No risk.
    Prevention: No prevention.

  MD_vMem_30_Tc3xxInf01_SizeOfData: rule 2.7
    Reason:     The signature of the hardware specific functions is defined within the vMemAccM. The module vMem_30_Tc3xxInf01 does
                not need the parameter SizeOfData in its extended functionality vMem_30_Tc3xxInf01_GetActiveAddressRegion.
    Risk:       No risk.
    Prevention: No prevention.

  MD_vMem_30_Tc3xxInf01_VoidPtrTypedPtr: rule 11.4, 11.5, 11.6, 11.8, dir 1.1
    Reason:     vMem accepts untyped void pointers in its hardware specific functionality, to provide a compatible interface for different hardware 
                specific function implementations: one may get a structure of type A, the other of type B etc. With a void pointer interface the
                signature of all the functions keeps the same as can be used in one typed function pointer array.
                In the hardware specific functionality GetActiveAddressRegion the vMem performs a cast of the void pointer to a pointer to vMem_30_Tc3xxInf01_AddressRegionType,
                so it can write the currently active address region to the referenced object. The user of this functionality has to make sure, that the referenced
                object is of type vMem_30_Tc3xxInf01_AddressRegionType. During initialization the components calls its own service to get the active address region
                and for this performs a cast from a pointer to object type to a pointer to void.
                vMem also accepts void pointers for user buffers. During a write job vMem has to split the passed buffer into words.
                Therefore, the buffer is cast to a pointer of type uint32.
    Risk:       No risk.
    Prevention: Component tests ensures that the vMem accesses the referenced object correctly.

  MD_vMem_30_Tc3xxInf01_ExtendedApi: rule 8.7
    Reason:     vMem implements extended API which can be called by upper layers. Some of the involved objects/functions are only referenced in
                the defining translation unit. This was a design decision.
    Risk:       No risk.
    Prevention: No prevention.

  MD_vMem_30_Tc3xxInf01_FlashReadAccess: rule 11.4
    Reason:     vMem directly reads from flash via memory mapped read. The conversion between pointer and an integral type is required to access the 
                FLASH address/target address which is defined as unsigned long.
    Risk:       If the object referenced by TargetAddressPtr is of wrong type, the behavior is undefined.
    Prevention: Component tests ensures that the vMem accesses the referenced object correctly.
                User must ensure that TargetAddressPtr is valid.
*/

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_vMem_RegisterAccess
 \DESCRIPTION The function accesses a hardware register of TC39XB using a pointer access.
 \COUNTERMEASURE \T TCASE-761406, TCASE-761407, TCASE-792681
                    (The code inspection and tests on hardware ensure that the memory location referenced contains the registers
                    with the same structure as specified in hardware software interface.)
\ID SBSW_vMem_Statemachine
 \DESCRIPTION Function pointer call: vMem LowLevel sub module implements the state machine. The next state will always be saved
              as a function pointer and setup by current state -> the state knows the follower state(s) and setup the function pointer.
 \COUNTERMEASURE \N The LowLevel sub module is responsible for correctness. Component tests and review shall help to detect issues.

SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION

Code Coverage:

\ID COV_VMEM_30_TC3XXINF01_DEFAULT
 \ACCEPT X
 \REASON [COV_MSR_MISRA]

\ID COV_VMEM_30_TC3XXINF01_ERROR_CHECK
 \ACCEPT XF
 \REASON vMem_30_Tc3xxInf01 checks whether error flags are set by hardware. Since hardware failure cannot be simulated this is not covered.

\ID COV_VMEM_30_TC3XXINF01_HW_BUSY_CHECK
 \ACCEPT TX
 \REASON vMem_30_Tc3xxInf01 checks whether flags on hardware are set, to indicate that hardware is still busy processing last command sequences.

\ID COV_VMEM_30_TC3XXINF01_SECTOR_INDEX
 \ACCEPT TF
 \ACCEPT TX
 \REASON vMem_30_Tc3xxInf01 finds index of sector for passed address. Since sectors are sorted in ascending order of start address,
         the passed address is always bigger than the compared start address.

\ID COV_VMEM_30_TC3XXINF01_ADDRESS_REGION
 \ACCEPT TX
 \ACCEPT XX
 \ACCEPT X
 \REASON vMem_30_Tc3xxInf01 provides a service to check which address region (A or B) is active. Since vMem_30_Tc3xxInf01 is not able
         to perform a swap of the address regions, yet, address region A is always active by default.

Variant coverage:

\ID COV_VMEM_30_TC3XXINF01_COMPATIBILITY
 \ACCEPT TX
 \REASON COV_MSR_COMPATIBILITY

\ID COV_VMEM_30_TC3XXINF01_COMPILER
 \ACCEPT TX 
 \ACCEPT XF
 \ACCEPT XX
 \REASON vMem_30_Tc3xxInf01 has to use the dsync function. Its definition depends on the compiler. vMem_30_Tc3xxInf01 knows four compilers. Tests are performed with GNU.

\ID COV_VMEM_30_TC3XXINF01_USECASE
 \ACCEPT TX
 \ACCEPT XF
 \REASON vMem_30_Tc3xxInf01 default use case is the HOST (TriCore) system. The build-environment shall decide whether the component is used in different use case HSM (ARM).

\ID COV_MEM_30_TC3XXINF01_TESTING
 \ACCEPT TX
 \REASON vMem_30_Tc3xxInf01 provides the replace logical sector feature. Repeatable tests for this cannot be executed on hardware.
         Therefore, the register access is routed via the test suite.
         The test cases for replace logical sector use a device stub instead of actually accessing hardware registers.
         All other test cases are executed on hardware and the registers are accessed using the LLReadRegister, LLWriteRegister functions
         or the OS Peripheral API, depending on the switch VMEM_30_TC3XXINF01_USE_PERIPHERAL_ACCESS_API.

END_COVERAGE_JUSTIFICATION
*/

/**********************************************************************************************************************
 *  END OF FILE: vMem_30_Tc3xxInf01_LL.c
 *********************************************************************************************************************/
