/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2020)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME   : Fls_17_Dmu.c                                                **
**                                                                           **
**  VERSION :  6.0.0                                                         **
**                                                                           **
**  DATE     :  2020-06-05                                                   **
**                                                                           **
**  VARIANT   : Variant PB                                                   **
**                                                                           **
**  PLATFORM  : Infineon AURIX2G                                             **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - functionality of Flash driver                           **
**                                                                           **
**  SPECIFICATION(S) : Specification of FLS Driver, AUTOSAR Release 4.2.2    **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* [cover parentID={CE0E1013-F855-45f6-A341-3134FAB115C5}][/cover] */
/* [cover parentID={325361F6-5AA1-4027-A491-D8A970E7FE8C}][/cover] */
/* [cover parentID={93231028-6942-4390-A06D-5ACF5EB86F2F}][/cover] */
/* [cover parentID={34C9BD42-7196-4ba0-B305-4C5EE582F134}][/cover] */

#include "IfxDmu_reg.h"
#include "IfxDmu_bf.h"
#include "IfxFsi_reg.h"

/* Inclusion of Flash header file */
/* [cover parentID={93E8BC5E-CDEC-4da2-9273-77E9147D1B32}][/cover] */
#include "Fls_17_Dmu.h"

/* Inclusion of Flash command cycles file */
#include "Fls_17_Dmu_ac.h"

#if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
#include "Mcal_SafetyError.h"
#endif


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

#ifndef FLS_17_DMU_AR_RELEASE_MAJOR_VERSION
#error "FLS_17_DMU_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#if ( FLS_17_DMU_AR_RELEASE_MAJOR_VERSION != 4U )
#error "FLS_17_DMU_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

/* [cover parentID={D5FA2170-40E5-46c9-A804-BFA8D0202805}][/cover] */
/*
    DRIVER VERSION CHECK FOR FLS MODULE INCLUSION
*/

#ifndef FLS_17_DMU_SW_MAJOR_VERSION
#error "FLS_17_DMU_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef FLS_17_DMU_SW_MINOR_VERSION
#error "FLS_17_DMU_SW_MINOR_VERSION is not defined. "
#endif

#ifndef FLS_17_DMU_SW_PATCH_VERSION
#error "FLS_17_DMU_SW_PATCH_VERSION is not defined. "
#endif

#if (FLS_17_DMU_SW_MAJOR_VERSION != 2U)
#error "FLS_17_DMU_SW_MAJOR_VERSION does not match."
#endif

#if (FLS_17_DMU_SW_MINOR_VERSION != 0U)
#error "FLS_17_DMU_SW_MINOR_VERSION does not match."
#endif

#if (FLS_17_DMU_SW_PATCH_VERSION != 0U)
#error "FLS_17_DMU_SW_PATCH_VERSION does not match."
#endif

/* [cover parentID={703AAC5B-F330-40d2-98BC-02D1C0CE7C27}]
[/cover]
*/
/*
    VERSION CHECK FOR DET MODULE INCLUSION
*/
#if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
(FLS_17_DMU_SAFETY_ENABLE == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
#error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
#error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#endif /* (FLS_DEV_ERROR_DETECT == STD_ON) */


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define FLS_ONE_VALUE                (1U)
#define FLS_THREE_VALUE              (3U)

#if(FLS_17_DMU_IFX_FEE_USED == STD_ON)
#define FLS_16BIT_MASK               (0x0000FFFFU)
#endif

/* Page size mask used for checking if address is page aligned*/
/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_PAGE_SIZE_MASK        (FLS_17_DMU_PAGE_SIZE-1U)

#if(FLS_17_DMU_IFX_FEE_USED == STD_ON)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_WL_SIZE_MASK          (512U-1U)
#endif

/* sequence error check */
#define FLS_SQER_ERROR        (0x00000002U)

/* Operational error */
#define FLS_OPER_ERROR              (0x00000001U)
/* Uncorrectable bit error */
#define FLS_BIT_ERROR               (0x00080000U)
/* Dflash busy status */
#define FLS_D1BUSY                  (0x00000002U)
/*SELD0 for Margin Select*/
#define FLS_DMU_SELD0_MASK          (0xFFFFFFFCU)

/*Timeout value for margin switch*/
/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_DMU_MARGIN_TIMEOUT      (2000U)

#if (FLS_17_DMU_USE_ERASESUSPEND == STD_ON)
#define FLS_RESUMEERASE_TIMEOUT     (500U)
#endif

/*Trap Disable*/
#define FLS_DMU_ECCC_TRAPDIS_MASK   (0xC0000000U)

/*Enable CLR the AERM bit*/
#define FLS_DMU_ECCC_CLR        (0x00000003U)

#if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
#define FLS_DMU_MODE_CHK            (0x00000003U)
#endif

#define FLS_DMU_ECCW_CLR            (0x3FFFFFFFU)

#if (FLS_17_DMU_INITCHECK_API == STD_ON)
/*Init Check registers*/
#define FLS_REG_CLR_CHK               (0xFFFFFFFFU)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_REG_COMM_CLRCHK           (uint8)(0xFF)
#define FLS_ERRSRREG_CLRCHK           (0x0000001FU)
#endif

/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_DMU_ECCW_CLR_CHK          (0xC0000000U)
#define FLS_DMU_ECCC_CLR_CHK          (0xC0000000U)
#define FLS_DMU_ERR_CLR               (0x0000003EU)


/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_DMU_SELD0_MASK_CHK        (0x00000003U)

/*
#define IFX_DMU_SF_ERRSR_OPER_MSK (0x1u)
#define IFX_DMU_SF_ERRSR_PVER_OFF (3u)
#define IFX_DMU_SF_ERRSR_PVER_MSK (0x1u)
#define IFX_DMU_SF_ECCC_TRAPDIS_MSK (0x3u)
*/

/*Init status for the API*/
#define FLS_INITIALIZED            ((uint32)1)

/* Word size - 4 bytes */
/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_WORD_SIZE              (4U)

/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_WORD_SIZE_MASK        (FLS_WORD_SIZE - 1U)

#if (FLS_17_DMU_USE_ERASESUSPEND == STD_ON)
#define SUSPEND_CLR_OFF            (0x2U)
#endif

/* Mask to check the Mod4K result */
#define FLS_MOD4K_MASK          (0x0FFFU)
/* Number of shifts to do division or multiplication by 4K -> 2^12 */
#define FLS_4KSHIFT_VAL          (12U)

#if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
(FLS_17_DMU_SAFETY_ENABLE == STD_ON)
#define FLS_17_DMU_BURST_PAGE_SHIFT (5U)
#define FLS_17_DMU_PAGE_SHIFT (3U)
#define FLS_17_DMU_MIN_MAINFUNC_CALL (2U)
#endif

/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_VERIFYSECTOR_CHK_VAL   (0xDEADBEEFU)

/*Read with hard margin selection value */
/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_READHARDMARGIN_VAL      (3U)

/*Tight0- Tight margin for 0 (low) level */
/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_TIGHT0MARGIN_VAL       (0xfffffeffU)

/*Hardening*/
#if(FLS_17_DMU_IFX_FEE_USED == STD_ON)
/*Mask to extract the TBE (3 bit error) status in FSI_HSMCOMM_2 */
#define FLS_COMM2TBE_MASK (0xE0U)

/* Register setting value for control gate voltage of 4.1V */
#define FLS_CTRLGATEVOLTAGE_VAL (0x20)

/* Mask to extract the result stored (5bits) in FSI_HSMCOMM_2.COMM2[4:0] */
#define FLS_FSIHSMCOMM2RES_MASK          ((uint8)(0x1FU))

#define FLS_DMU_HARDEN_PAGE_ALIGN      (0x8U)
#define FLS_DMU_HARDEN_WORD_ALIGN      (0xFFFFFFF7U)

/*Timeout for User Content Count*/
#define FLS_USRCONTENT_PAGE_TIMEOUT         (21000U)
#define FLS_USRCONTENT_WL_TIMEOUT         (100000U)
/* 8 bits shift value */
#define FLS_SHIFT8BITS_VAL          ((uint8)(8U))

#endif /*Hardening*/

/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_HSMCOMM_RESET_VAL         ((uint8)0x00)

#define FLS_SUSPEND_ERR_CLR        (0x2U)

/* Wordline fail count to be suported */
/* MISRA2012_RULE_2_5_JUSTIFICATION: Macro has been used so it is a false
warning*/
#define FLS_WL_FAIL_COUNT (2U)

#if (FLS_17_DMU_USE_ERASESUSPEND == STD_ON)
#define FLS_EVER_CHK ((uint8)(0x1))
#endif

/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macro defined for writing
data into the register address. No side effects foreseen by violating this MISRA rule. */
#define FLS_17_DMU_DF1_SFR_WRITE(RegAdd,Data) ((*(RegAdd)) = (uint32)(Data))

/*****************************************************************************
**                      Private Function Declarations                       **
*****************************************************************************/

#define FLS_17_DMU_START_SEC_CODE_QM_LOCAL
/* [cover parentID={4579FE20-92DA-4848-93DB-7AD4FD35DD50}][/cover] */
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}][/cover] */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}][/cover] */
/* [cover parentID={72DABBEB-F27B-4677-B6B4-B53F634341BA}][/cover] */
/* [cover parentID={EA0715EE-3E3C-4aac-A42E-4B5CFC96CEED}][/cover] */

/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */
#include "Fls_17_Dmu_MemMap.h"

static void Fls_lMainErase(void);

static void Fls_lMainWrite(void);

static void Fls_lMainRead(void);

static void Fls_lMainCompare(void);

static void Fls_lMainBlankCheck(void);

static void Fls_lErrorHandler(const uint8 JobType);

#if (FLS_17_DMU_IFX_FEE_USED == STD_ON)
static Std_ReturnType Fls_lLocalVerifyErase(
  const Fls_17_Dmu_AddressType TargetAddress,
  uint32 *const UnerasedWordlineAddressPtr,
  uint8 *const UnerasedWordlineCountPtr,
  const uint8 Sector, const uint32 value);
#if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
LOCAL_INLINE uint8 Fls_lHardenSafetyChk(
  const Fls_17_Dmu_AddressType TargetAddress,
  const uint8 AlignChk);
#endif
#endif

#if (FLS_17_DMU_IFX_FEE_USED == STD_ON)
static void Fls_lEverFlagChkFail(void);
#endif

#if (FLS_17_DMU_USE_ERASESUSPEND == STD_ON)
LOCAL_INLINE boolean Fls_lSpndTimeout(const uint32 TimeOutCount);
#endif

static void Fls_lMainWriteJobStart(const uint32 PhysicalAddress);

LOCAL_INLINE boolean Fls_lPverChk(void);

#if (FLS_17_DMU_INITCHECK_API == STD_ON)
static Std_ReturnType Fls_lInitCheck(void);
#endif

#if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON)|| \
(FLS_17_DMU_SAFETY_ENABLE == STD_ON)
LOCAL_INLINE uint8 Fls_lBusyDET_Read(
  const Fls_17_Dmu_StateType *const StatePtr);

LOCAL_INLINE uint8 Fls_lBusyDET_Write(const Fls_17_Dmu_StateType *const
                                      StatePtr);

LOCAL_INLINE uint8 Fls_lBusyDET_Erase(const Fls_17_Dmu_StateType *const
                                      StatePtr);

#if (FLS_17_DMU_COMPARE_API == STD_ON)
LOCAL_INLINE uint8 Fls_lBusyDET_Compare(
  const Fls_17_Dmu_StateType*const
  StatePtr);
#endif

static uint8 Fls_lUninitDET(const uint8 ServiceID);

static uint8 Fls_lTimeOutDET(const uint8 ServiceID);

LOCAL_INLINE void Fls_lCalculateWriteTimeoutCount(void);

#if (FLS_17_DMU_IFX_FEE_USED == STD_OFF)
LOCAL_INLINE Std_ReturnType Fls_lPageEraseCheck(
  uint32 *const AddrCheckPtr,
  const uint32 Length,
  const uint8 ServiceID);
#endif

LOCAL_INLINE Std_ReturnType Fls_lCheckEraseDet(
  const Fls_17_Dmu_AddressType TargetAddress,
  const Fls_17_Dmu_LengthType Length);

LOCAL_INLINE Std_ReturnType Fls_lCheckWriteDet(
  const Fls_17_Dmu_AddressType TargetAddress,
  const uint8 *const SourceAddressPtr,
  const Fls_17_Dmu_LengthType Length);

#if (FLS_17_DMU_IFX_FEE_USED == STD_OFF)
LOCAL_INLINE boolean Fls_lCheckWrittenPage(const uint32 PageLength);
#endif


/* API to check DET errors in Fls_Init API. */
static void Fls_lReportError(const uint8 Fls_Sid, const uint8 ErrorId);

#endif /* End of FLS_DEV_ERROR_DETECT, FLS_17_DMU_SAFETY_ENABLE */

/*Check for command sequence error*/
LOCAL_INLINE uint32 Fls_lChkSeqError(void);

/*Check for operational error */
LOCAL_INLINE uint32 Fls_lChkOperError(void);

/*Check for double bit errors (DBER) */
LOCAL_INLINE uint32 Fls_lChkBitErrors(void);

/* Return the Busy status of the Data Flash Bank */
/* FLASH0_FSR.U & (1U<< (1U + (Bank) ) */
LOCAL_INLINE uint32 Fls_lHWBusyCheck(void);

/* get the write mode , page mode or burst mode */
LOCAL_INLINE uint8 Fls_lGetWriteMode(void);

/* Get max read length according to the FLS mode */
LOCAL_INLINE Fls_17_Dmu_LengthType Fls_lGetReadModeLength(void);

LOCAL_INLINE MemIf_ModeType Fls_lSetDefaultMode(void);

#define FLS_17_DMU_STOP_SEC_CODE_QM_LOCAL
/* [cover parentID={EA0715EE-3E3C-4aac-A42E-4B5CFC96CEED}][/cover] */

/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
  guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */
#include "Fls_17_Dmu_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define FLS_17_DMU_START_SEC_VAR_CLEARED_QM_LOCAL_32
/* [cover parentID={EA0715EE-3E3C-4aac-A42E-4B5CFC96CEED}][/cover] */

/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
  guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */
#include "Fls_17_Dmu_MemMap.h"

/* MISRA2012_RULE_8_4_JUSTIFICATION: The variable declaration and
definition is correct and compatible.*/
const Fls_17_Dmu_ConfigType *Fls_ConfigPtr;

/* Initialize status. */
static uint32 Fls_17_Dmu_InitStatus;

/*MISRA2012_RULE_5_1_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_2_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/*MISRA2012_RULE_5_4_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Memmap macros are defined as per Autosar
naming convention, hence it goes beyond 32 characters.*/
#define FLS_17_DMU_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
/* [cover parentID={8A00BEA5-55E8-4faa-8270-04E4059138F6}]
[/cover]
*/
/* [cover parentID={EA0715EE-3E3C-4aac-A42E-4B5CFC96CEED}]
[/cover]
*/

/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
  guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */
#include "Fls_17_Dmu_MemMap.h"



/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define FLS_17_DMU_START_SEC_CODE_QM_LOCAL

/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
  guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Fls_17_Dmu_MemMap.h"
/*******************************************************************************
** Traceability     : [cover parentID={E35FF093-4D81-429d-87D5-8A59FAFBBEFE}] **
**                                                                            **
** Syntax : void Fls_17_Dmu_Init(const Fls_17_Dmu_ConfigType* const ConfigPtr)**
**                                                                            **
** Service ID: 0x00                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to configuration set                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function                        **
** Service for FLASH initialization. The Initialization function shall        **
** initialize all Flash relevant registers with the values of the structure   **
** referenced by the parameter ConfigPtr.                                     **
**                                                                            **
*******************************************************************************/
void Fls_17_Dmu_Init(const Fls_17_Dmu_ConfigType *const ConfigPtr)
/* [cover parentID={E35FF093-4D81-429d-87D5-8A59FAFBBEFE}]Fls_17_Dmu_Init
[/cover] */
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint32 BitChange;
  uint32 OperErrChk;

  if (ConfigPtr == NULL_PTR)

  {
    /* Report to DET */
    #if( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
    (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
    Fls_lReportError(FLS_17_DMU_SID_INIT, FLS_17_DMU_E_PARAM_CONFIG);
    #endif
  }

  #if( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  /* Check if the driver is BUSY */
  else if(ConfigPtr->FlsStateVarPtr->FlsJobType != FLS_17_DMU_NONE )
  {
    Fls_lReportError(FLS_17_DMU_SID_INIT,
                     FLS_17_DMU_E_BUSY);/* Report to DET */
  }
  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  /*Safety Error if HWbusy */
  else if(Fls_lHWBusyCheck() != 0U)
  {
       Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                                 FLS_17_DMU_SID_INIT, FLS_17_DMU_SE_HW_BUSY);
  }
  else if(DMU_SF_SUSPEND.B.SPND == 1U)
  {
    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_INIT, FLS_17_DMU_SE_INIT_FAILED);
  }
  /*If the mode is not set to Single ended sensing mode*/
  else if((DMU_SF_PROCONUSR.U & FLS_DMU_MODE_CHK) != 0U)
  {
    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_INIT, FLS_17_DMU_SE_INIT_FAILED);
  }
  #endif
  #endif
  else
  {
    /*  ------------------------------------------------------------------ **
    **                 Flash Module Initialization                         **
    **  ------------------------------------------------------------------ */
    /*
    Initialization of flash driver and its relevant registers
    */
    /* Store the configuration pointer */
    Fls_ConfigPtr = ConfigPtr;

    /* Reset the command sequencer */
    Fls_lResetReadCmdCycle();

    /*clear the previous errors*/
    Fls_lClearStatusCmdCycle();


    /* Clear the following Error flag masks */
    /* OPERM, SQERM, PVERM, EVERM */
    /*MISRA2012_RULE_11_4_JUSTIFICATION: Conversion between pointer to
      object and integer type is permitted for special function registers*/
    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
    the object types as the address of the SFR is being passed.
    MISRA2012_RULE_11_1_JUSTIFICATION: Pointer cast is required to match
    the object types for SFR.*/
    FLS_17_DMU_DF1_SFR_WRITE(\
                                       (volatile uint32 *)&DMU_SF_EER.U, 0U);

    /* Margin Read Selection is set as standard margin */
    /*As per hardware manual - "If a change between the standard and
     hard read margin setting is done, the system must wait a delay time
     hard tFL_MarginDel until the next read is requested."
     Therefore, the delay is not needed because there is no immediate read
     happening after the register is set-up.Read will happen as part of
     user request.*/
    /*MISRA2012_RULE_11_4_JUSTIFICATION: Conversion between pointer to
      object and integer type is permitted for special function registers*/
    BitChange = DMU_SF_MARGIN.U & FLS_DMU_SELD0_MASK;

    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
    the object types as the address of the register is being passed.
    MISRA2012_RULE_11_1_JUSTIFICATION: Pointer cast is required to match
    the object types.*/
    FLS_17_DMU_DF1_SFR_WRITE(\
                                       (volatile uint32 *)&DMU_SF_MARGIN.U, \
                                       BitChange);


    /* The uncorrectable ECC error trap is disabled and ECC status register
     is cleared to clear the errors. */
    /*MISRA2012_RULE_11_4_JUSTIFICATION: Conversion between pointer to
      object and integer type is permitted for special function registers*/
    BitChange = (DMU_SF_ECCC.U & FLS_DMU_ECCC_CLR_CHK);
    BitChange |= (FLS_DMU_ECCC_TRAPDIS_MASK | FLS_DMU_ECCC_CLR);

    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
    the object types as the address of the register is being passed.*/
    /*MISRA2012_RULE_11_1_JUSTIFICATION: Pointer cast is required to match
    the object types.*/
    FLS_17_DMU_DF1_SFR_WRITE(\
        (volatile uint32 *)&DMU_SF_ECCC.U, \
        BitChange);

    /*Enable the ECC correction*/
    BitChange = (DMU_SF_ECCW.U & FLS_DMU_ECCW_CLR);

    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
     the object types as the address of the register is being passed.*/
    FLS_17_DMU_DF1_SFR_WRITE(\
        (volatile uint32 *)&DMU_SF_ECCW.U, BitChange);

    /*Clear the suspend registers*/
    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
    the object types as the address of the register is being passed.*/
    FLS_17_DMU_DF1_SFR_WRITE(\
                    (volatile uint32 *)&DMU_SF_SUSPEND, FLS_SUSPEND_ERR_CLR);

    /*Reset the COMM1 and COMM2 values to system reset values*/
    FSI_HSMCOMM_1.U = FLS_HSMCOMM_RESET_VAL;
    FSI_HSMCOMM_2.U = FLS_HSMCOMM_RESET_VAL;

    /*  ------------------------------------------------------------------ **
    **                 Global Variable Initialization                      **
    **  ------------------------------------------------------------------ */
    /*
    After having finished the module initialization,
    the Flash Driver state shall be set to FLS_17_DMU_IDLE and and the jobs
    result shall be set to FLS_17_DMU_JOB_OK.
    */

    StatePtr = ConfigPtr->FlsStateVarPtr;

    /*Set JobResult to ok */
    StatePtr->FlsJobResult = MEMIF_JOB_OK;

    /* Setting the Jobtype to none */
    StatePtr->FlsJobType = FLS_17_DMU_NONE;

    StatePtr->NotifCaller = FLS_17_DMU_NO_JOB;

    /* Initialize Job Status */
    StatePtr->JobStarted.Write = 0U;
    StatePtr->JobStarted.Erase = 0U;

    /* Assign default mode */
    StatePtr->FlsMode = Fls_lSetDefaultMode();

    #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
    (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
    /* Enable timeout handling */
    StatePtr->FlsTimeoutControl = 1U;
    #endif

    /* Check for OPER */
    OperErrChk = Fls_lChkOperError();

    if(OperErrChk != 0U)
    {
      #if(FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
      /*Report runtime error for OPER*/
      Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                                          FLS_17_DMU_INSTANCE_ID,
                                          FLS_17_DMU_SID_INIT,
                                          FLS_17_DMU_E_INIT_FAILED);
      #endif
    }
    else
    {
      Fls_17_Dmu_InitStatus = FLS_INITIALIZED;
    }
  }
}/* End of Function: Fls_Init */


#if (FLS_17_DMU_INITCHECK_API == STD_ON)
/******************************************************************************
** Traceability   : [cover parentID={FABE1515-678B-4067-9C75-7DBE5B2AB39C}]  **
**                                                                           **
** Syntax         : Std_ReturnType Fls_17_Dmu_InitCheck                      **
**                              (                                            **
**                              const Fls_17_Dmu_ConfigType *const ConfigPtr **
**                              )                                            **
**                                                                           **
** Description    : This function verifies the initialization the FLS driver **
**                  in context to the core from where the API is invoked.    **
**                                                                           **
** [/cover]                                                                  **
**                                                                           **
** Service ID     : 0x2B                                                     **
**                                                                           **
** Sync/Async     : Synchronous                                              **
**                                                                           **
** Reentrancy     : Non Reentrant                                            **
**                                                                           **
** Parameters(in) : None                                                     **
**                                                                           **
** Parameters(out): None                                                     **
**                                                                           **
** Return value   : E_OK - Initialization comparison is success              **
**                  E_NOT_OK - Initialization comparison failed              **
**                                                                           **
******************************************************************************/
Std_ReturnType Fls_17_Dmu_InitCheck(const Fls_17_Dmu_ConfigType
                                    *const ConfigPtr)
/* [cover parentID={FABE1515-678B-4067-9C75-7DBE5B2AB39C}]Fls_17_Dmu_InitCheck
[/cover] */
{
  Std_ReturnType RetVal = E_NOT_OK;
  uint32 MarginCheck, EccEnableCheck, ErrStatusCheck,
         EccStatusCheck, EerStatusCheck,
         PverEverErrChk, ErrorChkStatus;
  uint8 HardenChkComm;

  if(ConfigPtr != NULL_PTR)
  {
    MarginCheck = ((uint32)DMU_SF_MARGIN.U & FLS_DMU_SELD0_MASK_CHK);
    EccEnableCheck = ((uint32)DMU_SF_ECCW.U & FLS_DMU_ECCW_CLR_CHK);
    /*MISRA2012_RULE_13_5_JUSTIFICATION: These are device registers and are
     declared with Volatile qualifier due to which the tool is giving
    MISRA 13.5.*/
    /*MISRA2012_RULE_1_3_JUSTIFICATION: The device registers are being used
     here with Volatile qualifier due to which the tool is giving
      MISRA 1.3.*/
    /*MISRA2012_RULE_13_2_JUSTIFICATION: The device registers are being
     accessed here. There is no side affect.*/
    ErrStatusCheck = (((uint32)DMU_SF_ECCS.U & FLS_REG_CLR_CHK) | \
                      ((uint32)DMU_SF_SUSPEND.U & FLS_REG_CLR_CHK));
    EerStatusCheck = ((uint32)DMU_SF_EER.U & FLS_REG_CLR_CHK);
    EccStatusCheck = ((uint32)DMU_SF_ECCC.U & FLS_REG_CLR_CHK);
    /*MISRA2012_RULE_13_5_JUSTIFICATION: These are device registers and are
     declared with Volatile qualifier due to which the tool is giving
     MISRA 13.5.*/
    /*MISRA2012_RULE_1_3_JUSTIFICATION: These are device registers and are
     declared with Volatile qualifier due to which the tool is giving
     MISRA 1.3.*/
    /*MISRA2012_RULE_13_2_JUSTIFICATION: These are device registers and are
     declared with Volatile qualifier due to which the tool is giving
     MISRA 13.2.*/
    HardenChkComm = (((uint8)FSI_HSMCOMM_1.U & FLS_REG_COMM_CLRCHK) |  \
                     ((uint8)FSI_HSMCOMM_2.U & FLS_REG_COMM_CLRCHK));

    PverEverErrChk = ((uint32)DMU_SF_ERRSR.U & FLS_ERRSRREG_CLRCHK);
    ErrorChkStatus = (ErrStatusCheck | PverEverErrChk | EccEnableCheck |
                      MarginCheck | HardenChkComm);

    if((Fls_ConfigPtr != NULL_PTR) && (Fls_ConfigPtr == ConfigPtr))
    {
      RetVal = Fls_lInitCheck();

      if(RetVal == E_OK)
      {
        if (0U != EerStatusCheck)
        {
          RetVal = E_NOT_OK;
        }
        else if (ErrorChkStatus != 0U)
        {
          RetVal = E_NOT_OK;
        }
        else if (FLS_DMU_ECCC_TRAPDIS_MASK != EccStatusCheck)
        {
          RetVal = E_NOT_OK;
        }
        else
        {
          /* Dummy else */
        }
      }
    }
    else
    {
      RetVal = E_NOT_OK;
    }
  }
  return(RetVal);
}



/*******************************************************************************
** Traceability   : [cover parentID={3A4253EB-DAF9-423b-A0FD-B1CB1AD5631E}]   **
**                                                                            **
** Syntax         : Std_ReturnType Fls_lInitCheck                             **
**                              (                                             **
**                                void                                        **
**                              )                                             **
**                                                                            **
** Description    : This function verifies the initialization the FLS driver  **
**                  in context to the core from where the API is invoked.     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID     : None                                                      **
**                                                                            **
** Sync/Async     : Synchronous                                               **
**                                                                            **
** Reentrancy     : Non Reentrant                                             **
**                                                                            **
** Parameters(in) : None                                                      **
**                                                                            **
** Parameters(out): None                                                      **
**                                                                            **
** Return value   : E_OK - Initialization comparison is success               **
**                  E_NOT_OK - Initialization comparison failed               **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Fls_lInitCheck(void)
{
  Std_ReturnType ReturnVal;
  const Fls_17_Dmu_StateType  *StatePtr;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  if((StatePtr->FlsJobResult != MEMIF_JOB_OK)
      || (StatePtr->FlsJobType != FLS_17_DMU_NONE))
  {
    ReturnVal = E_NOT_OK;
  }
  else if((StatePtr->JobStarted.Write != 0U)
          || (StatePtr->JobStarted.Erase != 0U)
        || (StatePtr->NotifCaller != FLS_17_DMU_NO_JOB)
          || (Fls_ConfigPtr->FlsDefaultMode != StatePtr->FlsMode) ||
          (Fls_17_Dmu_InitStatus != FLS_INITIALIZED)
      #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
          (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
      || (StatePtr->FlsTimeoutControl != 1U)
          #endif
       )
  {
    ReturnVal = E_NOT_OK;
  }
  else
  {
    ReturnVal = E_OK;
  }

  return(ReturnVal);

}
/* End of Fls_InitCheck */
/******************************************************************************/
#endif
/* End of #if (FLS_INITCHECK_API == STD_ON) */

/*******************************************************************************
** Traceability :[cover parentID={6959CDE2-07AD-4e69-807A-7C5952D7A7BD}]      **
**                                                                            **
** Syntax : void Fls_17_Dmu_GetVersionInfo(                                   **
                                 Std_VersionInfoType * const VersioninfoPtr ) **
**                                                                            **
** Service ID:     0x10                                                       **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      reentrant                                                 **
**                                                                            **
** Parameters (in): VersioninfoPtr : Pointer to where to store the version    **
**                                   information of this module.              **
**                                                                            **
** Parameters (out):VersioninfoPtr : Pointer to where to store the version    **
**                               information of this module.                  **
** Return value:    none                                                      **
**                                                                            **
** Description :    This service returns the version information of           **
**                  this module.                                              **
**                  The version information includes:                         **
**                  Module Id,Vendor Id , Vendor specific version numbers     **
**                                                                            **
*******************************************************************************/
#if (FLS_17_DMU_VERSION_INFO_API == STD_ON)
/* [cover parentID={D746F9C2-0E84-4b70-B3C7-602D35911049}]Fls_17_Dmu_GetVersionInfo
[/cover] */
void Fls_17_Dmu_GetVersionInfo(Std_VersionInfoType* const VersionInfoPtr)
{
  #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

  if ((VersionInfoPtr) == NULL_PTR)
  {

    Fls_lReportError(
      FLS_17_DMU_SID_GETVERSIONINFO,
      FLS_17_DMU_E_PARAM_POINTER
    );/* Report to  DET */

  }
  else
  #endif
  {
    /* Note that version info pointer is not checked for NULL as the user
     is supposed to send the memory allocated pointer */
    /* FLS Module ID */
    ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = FLS_17_DMU_MODULE_ID;
    /* FLS vendor ID */
    ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = FLS_17_DMU_VENDOR_ID;
    /* major version of FLS */
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =
      (uint8)FLS_17_DMU_SW_MAJOR_VERSION;
    /* minor version of FLS */
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =
      (uint8)FLS_17_DMU_SW_MINOR_VERSION;
    /* patch version of FLS */
    ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =
      (uint8)FLS_17_DMU_SW_PATCH_VERSION;
  }
}
#endif

/*******************************************************************************
** Traceability :[cover parentID={65778937-91C1-4192-98F4-8E9595BAC650}]      **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_Erase(                                  **
**                             const Fls_17_Dmu_AddressType TargetAddress,    **
**                             const Fls_17_Dmu_LengthType Length             **
**                                  )                                         **
**                                                                            **
** Service ID: 0x01                                                           **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  TargetAddress - Target address in Flash memory.         **
** This address offset will be added to the flash memory base address         **
**                    Length - Number of bytes to erase                       **
**                                                                            **
** Parameters (out): E_OK: command has been accepted                          **
**                   E_NOT_OK: command has not been accepted                  **
**                                                                            **
** Return value    : Std_ReturnType                                           **
**                                                                            **
** Description : This API Erases Flash. It copies the given parameters to     **
** driver internal variables, initiates the erase job, sets the driver status **
** to MEMIF_BUSY and job result to MEMIF_JOB_PENDING.                         **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_Erase( const Fls_17_Dmu_AddressType TargetAddress,
                                 const Fls_17_Dmu_LengthType Length)
/* [cover parentID={6C63C328-5CB0-4efe-A474-EB350526D552}]Fls_17_Dmu_Erase
[/cover] */
{
  Fls_17_Dmu_StateType*   StatePtr;
  uint32  PhysicalAddress;
  uint8            JobType;
  Std_ReturnType   ReturnValue;

  /* check for development error */

  #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  if(Fls_lCheckEraseDet(TargetAddress, Length) != E_OK)
  {

    ReturnValue = E_NOT_OK;
  }
  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  else if(DMU_SF_SUSPEND.B.SPND == 1U)
  {
    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_ERASE, FLS_17_DMU_SE_ILLGL_OPERTN);

    ReturnValue = E_NOT_OK;
  }
  #endif
  else
    /* FLS_DEV_ERROR_DETECT */
  #endif

  {
    /* Check for OPER error */
    if(Fls_lChkOperError() == 0U)
    {
      ReturnValue = E_OK;

      /* Initialise Local variables */
      StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

      /* Calculate the physical address from TargetAddress */
      PhysicalAddress = (uint32) (FLS_17_DMU_BASE_ADDRESS + TargetAddress);
      /* Set the physical address to be erased */
      StatePtr->FlsEraseAddress = PhysicalAddress;

      if((Length & FLS_MOD4K_MASK) == 0U)
      {
        /* Calculate the length in terms of number of 4K sectors*/
        StatePtr->FlsEraseNumSectors = (uint16) (Length >> FLS_4KSHIFT_VAL);
      }
      else
      {
        /* Calculate the length in terms of number of 4K sectors*/
        StatePtr->FlsEraseNumSectors =
          (uint16)((Length >> FLS_4KSHIFT_VAL) + FLS_ONE_VALUE);
      }

      StatePtr->FlsEraseNumSecPerCmd = (uint8)StatePtr->FlsEraseNumSectors;

      #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
      (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
      if (StatePtr->FlsTimeoutControl != 0U)
      {
        /* Update Timeout count for erase */
        StatePtr->FlsEraseTimeoutCycleCount =
          (uint32)(FLS_17_DMU_ERASE_TIME / Fls_ConfigPtr->FlsCallCycle);
        /* Increment by one as a safety precaution to avoid boundary errors */
        StatePtr->FlsEraseTimeoutCycleCount++;
      }
      #endif /* FLS_DEV_ERROR_DETECT == STD_ON */

      /* Check for hardware status */
      if(Fls_lHWBusyCheck() == 0U)
      {
        StatePtr->FlsEver = ((uint8)0x00);

        /*Set the Job Type*/
        JobType = FLS_17_DMU_ERASE;

        /* Set the flash job result to job pending */
        StatePtr->FlsJobResult = MEMIF_JOB_PENDING;

        /* Update the new job */
        StatePtr->FlsJobType = JobType ;
        /*Job type settings done*/

        /* Indicate that the ERASE Job has been started */
        StatePtr->JobStarted.Erase = 1U;

        Fls_lClearStatusCmdCycle();
        /* Execute the ERASE COMMAND CYCLES */

        Fls_lCallEraseCommand(StatePtr->FlsEraseAddress);

        /* Check for Sequence error */

        if(Fls_lChkSeqError() != 0U)
        {
          ReturnValue = E_NOT_OK;
          /* Report Runtime error code to DET */
          #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)

          Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                                  FLS_17_DMU_INSTANCE_ID,
                                  FLS_17_DMU_SID_ERASE,
                                  FLS_17_DMU_E_ERASE_FAILED);
          #endif

          Fls_lErrorHandler(FLS_17_DMU_ERASE);
        }
        /* Check for command sequence Timeout */

        else if (StatePtr->FlsTimeoutErr == FLS_17_DMU_ERASE)
        {
          /* Report Runtime error*/

          #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
           Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                                          FLS_17_DMU_INSTANCE_ID,
                                         FLS_17_DMU_SID_ERASE,
                                        FLS_17_DMU_E_ERASE_FAILED);
          #endif

          Fls_lErrorHandler(FLS_17_DMU_ERASE);

           ReturnValue = E_NOT_OK;
        }
        else
        {
          /* dummy else */
        }
      }
      else
      {
        #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
        Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_ERASE, FLS_17_DMU_SE_HW_BUSY);
        #endif
        ReturnValue = E_NOT_OK;
      }
    }
    else
    {

      #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
      Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                              FLS_17_DMU_INSTANCE_ID,
                              FLS_17_DMU_SID_ERASE,
                              FLS_17_DMU_E_ERASE_FAILED);
      #endif
      Fls_lErrorHandler(FLS_17_DMU_ERASE);
      /* Job cannot be started because of OPER error */
      ReturnValue = E_NOT_OK;
    }
  }
  return(ReturnValue);
}

/*******************************************************************************
** Traceability :[cover parentID={32E75AE9-D154-41ac-AC8E-FDA0064F594A}]      **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_Write(                                  **
**                           const Fls_AddressType TargetAddress,             **
**                                    const uint8 *const SourceAddressPtr,    **
**                              const Fls_LengthType Length                   **
**                                  )                                         **
**                                                                            **
** Service ID: 0x02                                                           **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :TargetAddress,SourceAddressPtr and Length                 **
**                                                                            **
** Parameters (out): E_OK: command has been accepted                          **
**                   E_NOT_OK: command has not been accepted                  **
**                                                                            **
** Return value    : Std_ReturnType                                           **
**                                                                            **
** Description : Writing to given flash address.                              **
** Service for writing one or more flash pages. This service copies the given **
** parameters to driver internal variables, initiate a Write job, set driver  **
** status to MEMIF_BUSY and job result to MEMIF_JOB_PENDING.                  **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_Write( const Fls_17_Dmu_AddressType TargetAddress,
                                 const uint8 *const SourceAddressPtr,
                                 const Fls_17_Dmu_LengthType Length
                               )
/* [cover parentID={56425B2B-6F8E-4a81-AAEF-6B0A60CA6988}]Fls_17_Dmu_Write
[/cover] */
{
  Fls_17_Dmu_StateType   *StatePtr;
  uint32 PhysicalAddress;
  uint32          *PageStartAddressPtr;
  Std_ReturnType  RetVal;
  uint8           WriteMode;
  uint8           JobType;

  /* Initialise Local variables */
  RetVal = E_OK;



  #if  ( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)


  if(Fls_lCheckWriteDet(TargetAddress, SourceAddressPtr,
                        Length) != E_OK)
  {

    RetVal = E_NOT_OK;
  }


  else if(Fls_lBusyDET_Write(Fls_ConfigPtr->FlsStateVarPtr) == 1U)
  {

    RetVal = E_NOT_OK;
  }
  else
  #endif
  {
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    /* PVER check for IFX FEE, clear FlsPver */
    #if(FLS_17_DMU_VER_ERROR_CHECK == STD_ON)
    #if(FLS_17_DMU_IFX_FEE_USED == STD_ON)
    StatePtr->FlsPver = 0U;
    #endif
    #endif

    /* Check OPER error status */

    if(Fls_lChkOperError() == 0U)
    {
      /*Check HW Busy*/

      if(Fls_lHWBusyCheck() == 0U)
      {
        /*Assign jobtype of Data Bank0 to write */


        JobType = FLS_17_DMU_WRITE;

        /* Determine the page start address */


        /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
           integer type is required to access the FLASH address/target address
            which is defined as unsigned long. */
        /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
          is required to access the FLASH address/target address which is
          defined as unsigned long by AUTOSAR. */
        /* MISRA2012_RULE_10_8_JUSTIFICATION: conversion between pointer and
           integer type is required to access the FLASH address/target
                                address which is defined as unsigned long. */
        PageStartAddressPtr = (uint32*)(FLS_17_DMU_BASE_ADDRESS  \
                                        + TargetAddress);
        /* Setting the PhysicalAddress to DF1 start address for Command cycle
                 execution */
        PhysicalAddress = FLS_17_DMU_BASE_ADDRESS;

        /*Job status setting done*/
        /*Set Job result*/
        /* 1. Set the flash job result to job pending */

        StatePtr->FlsJobResult = MEMIF_JOB_PENDING;

        /*By Default Setting the PageStartAddress to DataBank0 PageAddress */


        /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
        integer type is required to access the FLASH address/target address
        which is defined as unsigned long. */
        /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
           is required to access the FLASH address/target address which is
                 defined as unsigned long by AUTOSAR. */
        StatePtr->FlsWriteAddress = (uint32)PageStartAddressPtr;

        /* Assigning Length to global variable FlsWriteLength*/
        StatePtr->FlsWriteLength = Length;

        /* Assigning SourceAddressPtr to Global variable FlsWriteBufferPtr */
        StatePtr->FlsWriteBufferPtr = SourceAddressPtr;

        /* Update the new job  */
        StatePtr->FlsJobType = JobType;

        #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
        (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

        if (StatePtr->FlsTimeoutControl != 0U)
        {


          Fls_lCalculateWriteTimeoutCount();
        }
        #endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        /*End of StateVar variable setting*/


        #if  ( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
        (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
        #if (FLS_17_DMU_IFX_FEE_USED == STD_OFF)


        if(Fls_lPageEraseCheck
            (PageStartAddressPtr, Length, FLS_17_DMU_SID_WRITE) != E_OK)
        {

          Fls_lErrorHandler(FLS_17_DMU_WRITE);
          RetVal = E_NOT_OK;
        }
        else
        #endif /*FLS_17_DMU_IFX_FEE_USED*/
        #endif /* FLS_DEV_ERROR_DETECT */
        {
          /* Indicate that the WRITE Job has started */
          StatePtr->JobStarted.Write = 1U;
          /*Obtain the Mode (Page or Burst) */
          WriteMode = Fls_lGetWriteMode();

          Fls_lClearStatusCmdCycle();

          /* Execute the Write command sequence */
          Fls_lCallWriteCommand(PhysicalAddress, StatePtr, WriteMode);


          /* Check for Sequence error */
          if(Fls_lChkSeqError() != 0U)
          {

            /* Report Runtime error code to DET */
            #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)


            Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                                    FLS_17_DMU_INSTANCE_ID,
                                    FLS_17_DMU_SID_WRITE,
                                    FLS_17_DMU_E_WRITE_FAILED);
            #endif
            /* Call to Fls_lErrorHandler local function */


            Fls_lErrorHandler(FLS_17_DMU_WRITE);
            RetVal = E_NOT_OK;

          }
          /* Check for command cycle Timeout */

          else if (StatePtr->FlsTimeoutErr == FLS_17_DMU_WRITE)
          {

            #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
            Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                                    FLS_17_DMU_INSTANCE_ID,
                                    FLS_17_DMU_SID_WRITE,
                                    FLS_17_DMU_E_WRITE_FAILED);
            #endif

            /* Call to Fls_lErrorHandler local function */

            Fls_lErrorHandler(FLS_17_DMU_WRITE);

            RetVal = E_NOT_OK;

          }
          else
          {
            /* dummy else */
          }
        }
      }
      else
      {
        #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
        Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_WRITE, FLS_17_DMU_SE_HW_BUSY);
        #endif

        RetVal = E_NOT_OK;
      }
    }
    else
    {
      /* Report Runtime error code to DET */
      #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)

      Det_ReportRuntimeError((uint16)FLS_17_DMU_MODULE_ID,
                             FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_WRITE,
                             FLS_17_DMU_E_WRITE_FAILED);
      #endif
      /* Call to Fls_lErrorHandler local function */

      Fls_lErrorHandler(FLS_17_DMU_WRITE);

      RetVal = E_NOT_OK;
    }
  }

  return(RetVal);
}

#if (FLS_17_DMU_COMPARE_API == STD_ON)
/*******************************************************************************
** Traceability :[cover parentID={09A2E0A1-079D-41b3-B3A2-DBEDA142ABC2}]      **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_Compare(                                **
**                                 const Fls_17_Dmu_AddressType SourceAddress,**
**                                      const uint8 *const TargetAddressPtr,  **
**                                     const Fls_17_Dmu_LengthType Length     **
**                                    );                                      **
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :SourceAddress -  Source address in Flash memory.          **
** This address offset will be added to the flash memory base address.        **
**                  TargetAddressPtr - Pointer to target data buffer          **
**                  Length - Number of bytes to compare                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: command has been accepted                         **
**                    E_NOT_OK: command has not been accepted                 **
**                                                                            **
** Description : Service for comparing the contents of an area of flash memory**
** with that of an application data buffer. This service shall copy the given **
** parameters to driver internal variables, initiate a compare job, set the   **
** driver status to MEMIF_BUSY, set the job result to MEMIF_JOB_PENDING       **
** and return with E_OK.                                                      **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_Compare( const Fls_17_Dmu_AddressType SourceAddress,
                                   const uint8 *const TargetAddressPtr,
                                   const Fls_17_Dmu_LengthType Length
                                 )
/* [cover parentID={48F60B5E-23BE-42c9-856D-E572D4367401}]Fls_17_Dmu_Compare
[/cover] */
{
  Fls_17_Dmu_StateType   *StatePtr;
  uint32 PhysicalAddress;
  uint8           JobType;
  Std_ReturnType  ReturnValue;
  /* Initialise Local variables */

  ReturnValue = E_OK;

  /****************************** DET *****************************************/

  #if( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)


  if(Fls_lUninitDET(FLS_17_DMU_SID_COMPARE) == 1U)
  {

    ReturnValue = E_NOT_OK;
  }

  /*
   Checking whether given SourceAddress is valid or not
  */

  else if( SourceAddress >= FLS_17_DMU_TOTAL_SIZE )
  {

    Fls_lReportError(
      FLS_17_DMU_SID_COMPARE,
      FLS_17_DMU_E_PARAM_ADDRESS
    );/* Report to DET */


    ReturnValue = E_NOT_OK;
  }

  /*
  Check for Pointer to an application buffer
  */

  else if(TargetAddressPtr == NULL_PTR)
  {

    Fls_lReportError(
      FLS_17_DMU_SID_COMPARE,
      FLS_17_DMU_E_PARAM_DATA
    );/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  /*
   Checking whether given Length is valid or not
  */

  else if((Length == 0U) || (Length > (FLS_17_DMU_TOTAL_SIZE - SourceAddress)))
  {

    Fls_lReportError(
      FLS_17_DMU_SID_COMPARE,
      FLS_17_DMU_E_PARAM_LENGTH
    );/* Report to DET */

    ReturnValue = E_NOT_OK;
  }

  else if(Fls_lBusyDET_Compare(Fls_ConfigPtr->FlsStateVarPtr) == 1U)
  {

    ReturnValue = E_NOT_OK;
  }


  /*Check HW Busy*/
  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  else if(Fls_lHWBusyCheck() != 0U)
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_COMPARE, FLS_17_DMU_SE_HW_BUSY);

    ReturnValue = E_NOT_OK;
  }
  #endif
  else
  #endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    /**************************************************************************/
  {

    JobType = FLS_17_DMU_COMPARE;

    PhysicalAddress = (uint32)(FLS_17_DMU_BASE_ADDRESS + SourceAddress);
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    /* 1. Set the flash job result to job pending */
    StatePtr->FlsJobResult = MEMIF_JOB_PENDING;


    /*MISRA2012_RULE_11_8_JUSTIFICATION: Common global buffer is used for
     compare and read operation. Hence casting is done in such a way to match
     the fls read buffer pointer type.
    */
    StatePtr->FlsReadBufferPtr = (uint8 *)TargetAddressPtr;
    /* Assigning Length to Global variable FlsReadLength*/
    StatePtr->FlsReadLength = Length;
    StatePtr->FlsReadAddress = PhysicalAddress;

    /*3. Update the new job on affected banks */
    StatePtr->FlsJobType = JobType;
  }

  return(ReturnValue);
}
/* FLS_COMPARE_API == STD_ON */
#endif

#if (FLS_17_DMU_BLANK_CHECK_API == STD_ON)
/*******************************************************************************
** Traceability :  [cover parentID={A3F66C87-9D89-4f07-902F-2009EA91E6AB}]    **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_BlankCheck(                             **
**                           const Fls_17_Dmu_AddressType TargetAddress       **
**                                const Fls_17_Dmu_LengthType Length          **
**                                    );                                      **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :TargetAddress - Address in Flash memory from which the    **
**                   blank check should be started.                           **
**                  Length - Number of bytes to be checked for erase pattern  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: command has been accepted                         **
**                    E_NOT_OK: command has not been accepted                 **
**                                                                            **
** Description : This API is a Service is to verify, whether a given memory   **
** area has been erased but not (yet) programmed.                             **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_BlankCheck(
  const Fls_17_Dmu_AddressType TargetAddress,
  const Fls_17_Dmu_LengthType Length
)
/* [cover parentID={DF1893ED-5581-422c-A14F-1F4A3E1213C1}]Fls_17_Dmu_BlankCheck[/cover] */
{
  Fls_17_Dmu_StateType   *StatePtr;
  uint32 PhysicalAddress;
  uint8           JobType;
  Std_ReturnType  ReturnValue;

  /* Initialise Local variables */

  ReturnValue = E_OK;

  /****************************** DET ***************************************/

  #if( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)


  if(Fls_lUninitDET(FLS_17_DMU_SID_BLANKCHECK) == 1U)
  {

    ReturnValue = E_NOT_OK;
  }

  else if(TargetAddress >= FLS_17_DMU_TOTAL_SIZE)
  {

    Fls_lReportError(
      FLS_17_DMU_SID_BLANKCHECK,
      FLS_17_DMU_E_PARAM_ADDRESS
    );/* Report to DET */

    ReturnValue = E_NOT_OK;
  }

  /*   Checking whether given Length is valid or not  */
  else if(!(( Length >= FLS_ONE_VALUE) &&
            ( Length <= (FLS_17_DMU_TOTAL_SIZE - TargetAddress ))))
  {

    Fls_lReportError(
      FLS_17_DMU_SID_BLANKCHECK,
      FLS_17_DMU_E_PARAM_LENGTH
    );/* Report to DET */


    ReturnValue = E_NOT_OK;
  }

  else if (Fls_ConfigPtr->FlsStateVarPtr->FlsJobType != FLS_17_DMU_NONE)
  {

    Fls_lReportError(
      FLS_17_DMU_SID_BLANKCHECK,
      FLS_17_DMU_E_BUSY);/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

  else if(Fls_lHWBusyCheck() != 0U)
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_BLANKCHECK, FLS_17_DMU_SE_HW_BUSY);

    ReturnValue = E_NOT_OK;
  }
  #endif
  else
  #endif /* FLS_17_DMU_DEV_ERROR_DETECT == STD_ON */
    /*************************************************************************/
  {

    JobType = FLS_17_DMU_BLANKCHECK;
    PhysicalAddress = (uint32)(FLS_17_DMU_BASE_ADDRESS + TargetAddress);
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    /* 1. Set the flash job result to job pending */
    StatePtr->FlsJobResult = MEMIF_JOB_PENDING;

    /* Assigning Length to Global variable FlsReadLength*/

    StatePtr->FlsReadLength = Length;

    StatePtr->FlsReadAddress = PhysicalAddress;

    /*3. Update the new job  */
    StatePtr->FlsJobType = JobType;

  }
  return(ReturnValue);
}
/* FLS_BLANK_CHECK_API == STD_ON */
#endif


#if  (FLS_17_DMU_CANCEL_API  ==  STD_ON)
/*******************************************************************************
** Traceability :  [cover parentID={818E8AB7-EAE0-4743-8C20-7BB75D96CBA5}]    **
**                                                                            **
** Syntax : void Fls_17_Dmu_Cancel(Void)                                      **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** Service for Canceling an ongoing flash job.                                **
** Read and Compare jobs will be cancelled immediately. Write and Erase jobs  **
** will be cancelled in driver immediately but hardware might still be busy   **
** until the ongoing operation is completed for the already issued commands   **
*******************************************************************************/
void Fls_17_Dmu_Cancel(void)
/* [cover parentID={3F2C37E5-7D99-4666-9665-28F9BF259443}]Fls_17_Dmu_Cancel[/cover] */
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint8 JobType;
  boolean JobCanceled;


  #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  /* API called before initialization */


  if (Fls_lUninitDET(FLS_17_DMU_SID_CANCEL) == 0U)
  #endif
  {
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

    JobType = StatePtr->FlsJobType;
    JobCanceled = (boolean)FALSE;


    /* Cancel WRITE Job */
    if(FLS_17_DMU_WRITE == JobType)
    {
      /* Set the JobType to NONE;
         This shall be done before calling Fls_lUnLoadAccessCode() */

      StatePtr->FlsJobType = FLS_17_DMU_NONE;

      StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;
      JobCanceled = (boolean)TRUE;

      /* Resetting the internal variables */
      StatePtr->FlsWriteAddress = (uint32)FLS_17_DMU_TOTAL_SIZE;
      StatePtr->FlsWriteLength = 0U;
      StatePtr->FlsWriteBufferPtr = NULL_PTR;
    }


    /* Cancel ERASE Job */
    else if(FLS_17_DMU_ERASE == JobType)
    {
      /* Set the JobType to NONE*/

      StatePtr->FlsJobType = FLS_17_DMU_NONE;

      StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;
      JobCanceled = (boolean)TRUE;

      /* Resetting the internal variables */
      StatePtr->FlsEraseAddress = (uint32)FLS_17_DMU_TOTAL_SIZE;
      StatePtr->FlsEraseNumSectors = 0U;
      StatePtr->FlsEraseNumSecPerCmd = 0U;
    }

    else if((FLS_17_DMU_READ == JobType) || (FLS_17_DMU_COMPARE == JobType))
    {
      /* Cancel READ / COMPARE Job */
      /* Set the JobType to NONE */

      StatePtr->FlsJobType = FLS_17_DMU_NONE;

      StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;
      JobCanceled = (boolean)TRUE;

      /*Reset internal variables after cancellation*/
      StatePtr->FlsReadBufferPtr = NULL_PTR;
      StatePtr->FlsReadLength = 0U;
      StatePtr->FlsReadAddress = (uint32)FLS_17_DMU_TOTAL_SIZE;
    }


    else if(FLS_17_DMU_BLANKCHECK == JobType)
    {
      /* Set the JobType to NONE; */

      StatePtr->FlsJobType = FLS_17_DMU_NONE;

      StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;
      JobCanceled = (boolean)TRUE;

      /*Reset internal variables after cancellation*/
      StatePtr->FlsReadBufferPtr = NULL_PTR;
      StatePtr->FlsReadLength = 0U;
      StatePtr->FlsReadAddress = (uint32)FLS_17_DMU_TOTAL_SIZE;
    }
    else
    {
      /* Set the JobType to NONE */

      StatePtr->FlsJobType = FLS_17_DMU_NONE;
    }


    /* Reset JobStartStatus */
    StatePtr->JobStarted.Write = 0U;
    StatePtr->JobStarted.Erase = 0U;


    if((JobCanceled == (boolean)TRUE) &&
        (Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
      )
    {

      StatePtr->NotifCaller = FLS_17_DMU_CANCEL_JOB;

      /* FlsJobErrorNotificationPtr should be called */
      (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();

      StatePtr->NotifCaller = FLS_17_DMU_NO_JOB;
    }

  }

}

#endif /* #if (FLS_CANCEL_API == STD_ON) */

#if(FLS_17_DMU_IFX_FEE_USED == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID={2286DD54-0A69-45e6-ADFD-CC09F66B2688}]     **
**                                                                            **
** Syntax : void Fls_17_Dmu_CancelNonEraseJobs(void)                          **
**                                                                            **
** Service ID: 0x28                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** Service for Canceling an ongoing flash jobs except the erase job.          **
** Read and Compare jobs will be cancelled immediately. Write job             **
** will be cancelled in driver immediately but hardware might still be busy   **
** until the ongoing operation is completed for the already issued commands   **
*******************************************************************************/
void Fls_17_Dmu_CancelNonEraseJobs(void)
/* [cover parentID={2EFCDB48-187B-4d13-A230-B0C7BE5BFAEA}]Fls_17_Dmu_CancelNonEraseJobs
[/cover] */
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint8 JobType;
  boolean JobCanceled;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobType = StatePtr->FlsJobType;
  JobCanceled = (boolean)FALSE;


  /* Cancel WRITE Job */

  if(FLS_17_DMU_WRITE == JobType)
  {

    StatePtr->FlsJobType = FLS_17_DMU_NONE;

    /*
    Set the result of job as cancelled if it was marked as pending
    */
    StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;

    JobCanceled = (boolean)TRUE;

    /* Reset JobStart Status */
    StatePtr->JobStarted.Write = 0U;

  }
  /* Cancel READ / COMPARE / BlankCheck Job */

  else if((FLS_17_DMU_READ == JobType) || (FLS_17_DMU_COMPARE == JobType) || \
          (FLS_17_DMU_BLANKCHECK == JobType))
  {

    StatePtr->FlsJobType = FLS_17_DMU_NONE;

    StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;

    JobCanceled = (boolean)TRUE;
  }


  else
  {
    /* Reset JobType of Non-Erase Job */

    StatePtr->FlsJobType = ((JobType == FLS_17_DMU_ERASE) ?
                            FLS_17_DMU_ERASE : FLS_17_DMU_NONE);

  }

  /* Set the NotifCaller to Cancel Job */

  if((JobCanceled == (boolean)TRUE) &&
      (Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
    )
  {

    Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_CANCEL_JOB;
    /* FlsJobErrorNotificationPtr should be called */

    (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();

    Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
  }

}
#endif

/*******************************************************************************
** Traceability : [cover parentID={CB676030-CE4D-4b2d-B0FB-14DB3947C53D}]     **
**                                                                            **
** Syntax : void Fls_17_Dmu_SetMode(const MemIf_ModeType Mode)                **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : Mode MEMIF_MODE_SLOW:                                    **
**                        Slow read access                                    **
**                                                                            **
**                        MEMIF_MODE_FAST:                                    **
**                        Fast read access                                    **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This API sets the Flash driver's operation mode.             **
**               FAST or SLOW mode impacts only Read/Compare operations.      **
**               Based on the currently active mode, the number of bytes to be**
**               read from Flash in each call of Fls_17_Dmu_MainFunction is   **
**               taken from the configuration                                 **
*******************************************************************************/
#if  (FLS_17_DMU_SET_MODE_API  ==  STD_ON)
/* [cover parentID={887E1F26-1DC2-4b3d-967A-49E35D53B742}]Fls_17_Dmu_SetMode[/cover] */
void Fls_17_Dmu_SetMode(const MemIf_ModeType Mode)
{

  #if  ( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  uint8 JobType;

  if (Fls_lUninitDET(FLS_17_DMU_SID_SETMODE) == 0U)
  {
    JobType = Fls_ConfigPtr->FlsStateVarPtr->FlsJobType;
    /* Check if the driver is BUSY */

    if( JobType != FLS_17_DMU_NONE )
    {


      Fls_lReportError(FLS_17_DMU_SID_SETMODE,
                       FLS_17_DMU_E_BUSY);/* Report to DET */
    }
    #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

    else if ((MEMIF_MODE_SLOW != Mode) && (MEMIF_MODE_FAST != Mode))
    {

      Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_SETMODE,
                             FLS_17_DMU_SE_PARAM_INVLD);
    }
    #endif
    else
  #endif
    {
      Fls_ConfigPtr->FlsStateVarPtr->FlsMode = Mode;
    }

    #if  ( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
    (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  }
    #endif
}
#endif


/*******************************************************************************
** Traceability : [cover parentID={18730333-536B-494d-8FB0-10F16F44A4A0}]     **
**                                                                            **
** Syntax : void Fls_17_Dmu_MainFunction(void)                                **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** This service shall perform the processing of the flash read,write          **
**         and erase jobs                                                     **
*******************************************************************************/
/* CYCLOMATIC_Fls_17_Dmu_MainFunction_JUSTIFICATION: This Function has
 cyclomatic complexity greater than 15, as the OPER error check mandated by
 the hardware manual. This cannot be further broken down into local function.*/
void Fls_17_Dmu_MainFunction(void)
/* [cover parentID={BF6D9ACD-AC47-4231-A2B6-917D4FF7432D}][/cover] */
{
  const Fls_17_Dmu_StateType  *StatePtr;
  uint8 JobType;
  uint8 ErrorUninitFlag = 0U;
  uint32 OperStatusChk;

  #if  ( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  uint8 ErrorTimeoutFlag;
  /* API  called before initialization */


  ErrorUninitFlag = Fls_lUninitDET(FLS_17_DMU_SID_MAIN);



  if (ErrorUninitFlag == 0U)

  {


    ErrorTimeoutFlag = Fls_lTimeOutDET(FLS_17_DMU_SID_MAIN);
    if (ErrorTimeoutFlag == 0U)

  #else


  if((Fls_ConfigPtr == NULL_PTR) ||
      (FLS_INITIALIZED != Fls_17_Dmu_InitStatus))
  {


    ErrorUninitFlag = 1;
  }

  if (ErrorUninitFlag == 0U)
  #endif
    {
      StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
      JobType = StatePtr->FlsJobType;

      if( JobType != FLS_17_DMU_NONE)
      {
        OperStatusChk = ((uint32)DMU_SF_ERRSR.U & FLS_OPER_ERROR);
        /* Check for any Flash operation is ongoing? */


        if(( Fls_lHWBusyCheck() == 0U) || (OperStatusChk != 0U))
        {

          switch(JobType)
          {

            /**************************** ERASE *******************************/
            case FLS_17_DMU_ERASE:
            {
              /* Fls_Main_Erase operation should be called  */

              Fls_lMainErase();
            }
            break;
            /***************************** WRITE ******************************/
            case FLS_17_DMU_WRITE:
            {
              /* Fls_Main_Write operation should be called  */

              Fls_lMainWrite();
            }
            break;
            /*************************** READ *********************************/
            case FLS_17_DMU_READ:
            {
              /* Fls_Main_Read operation should be called  */

              Fls_lMainRead();
            }
            break;
            /*************************** COMPARE ******************************/
            case FLS_17_DMU_COMPARE:
            {
              /* Fls_Main_Compare operation should be called  */

              Fls_lMainCompare();
            }
            break;
            /***************************** BLANK CHECK ************************/
            case FLS_17_DMU_BLANKCHECK:
            {
              /* Fls_Main_BlankCheck operation should be called  */

              Fls_lMainBlankCheck();
            }
            break;
            default:
            {
              /* Do nothing - To avoid MISRA warning */
            }
            break;
          }
        }
      }
      #if  ( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
      (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
    }
      #endif
  }

}



/*******************************************************************************
** Traceability : [cover parentID={2A9A31FE-C2D1-47ca-9A22-3F281024F0A2}]     **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_Read(                                   **
**                              const Fls_17_Dmu_AddressType SourceAddress,   **
**                                   uint8 *const TargetAddressPtr,           **
**                              const Fls_17_Dmu_LengthType Length            **
**                                 );                                         **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : SourceAddress,TargetAddressPtr and Length                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :  E_OK: command has been accepted                         **
**                    E_NOT_OK: command has not been accepted                 **
**                                                                            **
** Description : Service for reading from flash memory. This service copies   **
** the given parameters to driver internal variables, set driver status to    **
** MEMIF_BUSY and job result to MEMIF_JOB_PENDING.                            **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_Read(const Fls_17_Dmu_AddressType SourceAddress,
                               uint8 *const TargetAddressPtr,
                               const Fls_17_Dmu_LengthType Length)
/* [cover parentID={F945E4D5-BEB5-4055-B6F7-33D2A6F0B2A4}]Fls_17_Dmu_Read
[/cover] */
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint32 PhysicalAddress;
  Std_ReturnType ReturnValue;
  uint8 JobType;

  /* Initialise Local variables */

  ReturnValue = (Std_ReturnType)E_OK;

  /**************************** DET ******************************************/


  #if  ( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  /*  API  called before initialization */

  if(Fls_lUninitDET(FLS_17_DMU_SID_READ) == 1U)
  {


    ReturnValue = E_NOT_OK;
  }
  /*  Checking whether given SourceAddress is valid or not */

  else if(SourceAddress >= (FLS_17_DMU_TOTAL_SIZE))
  {


    Fls_lReportError(FLS_17_DMU_SID_READ,
                     FLS_17_DMU_E_PARAM_ADDRESS);/* Report to DET*/

    ReturnValue = E_NOT_OK;


  }
  /*Check for Pointer to an application buffer*/

  else if(TargetAddressPtr == NULL_PTR)
  {

    Fls_lReportError(FLS_17_DMU_SID_READ,
                     FLS_17_DMU_E_PARAM_DATA);/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  /* Checking whether given Length is valid or not */

  else if((Length < FLS_ONE_VALUE) ||
          (Length > (FLS_17_DMU_TOTAL_SIZE - SourceAddress)))
  {

    Fls_lReportError(FLS_17_DMU_SID_READ,
                     FLS_17_DMU_E_PARAM_LENGTH);/* Report to DET */

    ReturnValue = E_NOT_OK;

  }


  else if(Fls_lBusyDET_Read(Fls_ConfigPtr->FlsStateVarPtr) == 1U)
  {

    ReturnValue = E_NOT_OK;
  }
  else
  #endif
    /*************************************************************************/
  {

    if(Fls_lHWBusyCheck() == 0U)
    {
      /*Assign jobtype to read */

      JobType = FLS_17_DMU_READ;
      PhysicalAddress = (uint32)(FLS_17_DMU_BASE_ADDRESS + SourceAddress);
      StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
      /* 2. Set the flash job result to job pending */
      StatePtr->FlsJobResult = MEMIF_JOB_PENDING;

      /* Assigning TargetAddressPtr to Global variable FlsReadBufferPtr */
      StatePtr->FlsReadBufferPtr = TargetAddressPtr;


      /* Assigning Length to Global variable FlsReadLength*/
      StatePtr->FlsReadLength = Length;

      StatePtr->FlsReadAddress = PhysicalAddress;

      /*3. Update the new job on affected banks */
      StatePtr->FlsJobType = JobType;
    }
    else
    {

      #if(FLS_17_DMU_SAFETY_ENABLE == STD_ON)
      Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_READ, FLS_17_DMU_SE_HW_BUSY);
      #endif

      ReturnValue = E_NOT_OK; /*HW is busy*/
    }
  }

  return(ReturnValue);
}

#if (FLS_17_DMU_GET_STATUS_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID={5C6365D7-79D7-459f-BEB7-A89C359F9399}]     **
**                                                                            **
** Syntax : MemIf_StatusType Fls_17_Dmu_GetStatus(void)                       **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  MemIf_StatusType - The state of the driver              **
**                                                                            **
** Description :                                                              **
** This service shall return the driver state synchronously                   **
*******************************************************************************/
MemIf_StatusType Fls_17_Dmu_GetStatus(void)
/* [cover parentID={59FF2D8F-716D-43e2-B59E-7D3D1A27A5DA}]Fls_17_Dmu_GetStatus
[/cover] */
{
  MemIf_StatusType ReturnValue;
  uint8 JobType;



  if((Fls_ConfigPtr == NULL_PTR) || (FLS_INITIALIZED != Fls_17_Dmu_InitStatus))
  {

    ReturnValue = MEMIF_UNINIT;
  }
  else
  {
    JobType = Fls_ConfigPtr->FlsStateVarPtr->FlsJobType;

    if((JobType != FLS_17_DMU_NONE))
    {

      ReturnValue = MEMIF_BUSY;
    }
    else
    {

      ReturnValue = MEMIF_IDLE;
    }
  }
  /*  Service shall return driver state synchronously. */
  return(ReturnValue);
} /* End of Function: Fls_GetStatus */


#endif

#if  (FLS_17_DMU_GET_JOB_RESULT_API  ==  STD_ON)
/*******************************************************************************
** Traceability : [cover parentID={FBF001A4-D07E-4b03-8FA8-5C020552B5D6}]     **
**                                                                            **
** Syntax : MemIf_JobResultType Fls_17_Dmu_GetJobResult(void)                 **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  MemIf_JobResultType  - The result of the last job       **
**                                                                            **
** Description :                                                              **
**         This service shall return the result of the last job synchronously **
*******************************************************************************/
MemIf_JobResultType Fls_17_Dmu_GetJobResult(void)
/* [cover parentID={BDC1DA1D-8384-4ca0-9EA1-AD0E33D37102}]Fls_17_Dmu_GetJobResult
[/cover] */
{

  MemIf_JobResultType RetVal;

  #if  ( FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  /*  API  called before initialization */



  if (Fls_lUninitDET(FLS_17_DMU_SID_GETJOBRESULT) != 0U)
  {

    RetVal = MEMIF_JOB_FAILED;
  }
  else
  #endif
  {

    RetVal = Fls_ConfigPtr->FlsStateVarPtr->FlsJobResult;
  }

  return(RetVal);
}
#endif
/*FLS_GET_JOB_RESULT_API == STD_ON */

#if (FLS_17_DMU_IFX_FEE_USED == STD_ON)
/*******************************************************************************
** Traceability :                                                             **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_ReadWordsSync(                          **
**                                const Fls_17_Dmu_AddressType SourceAddress, **
**                                            uint32 *const TargetAddressPtr, **
**                                    const uint32 Length                     **
**                                         )                                  **
**                                                                            **
** Service ID:  0x21                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : SourceAddress, TargetAddressPtr and Length               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Read successful                                    **
**                   E_NOT_OK: HW busy or read failed with ECC error          **
**                                                                            **
** Description : Service for reading word data from flash bank synchronously  **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_ReadWordsSync(
  const Fls_17_Dmu_AddressType SourceAddress,
  uint32 *const TargetAddressPtr,
  const uint32 Length)
/* [cover parentID={0E143A6B-82CC-4526-89DC-A33334872FB0}]Fls_17_Dmu_ReadWordsSync
[/cover] */
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint8 JobType;
  uint32 PhysicalAddress;
  Std_ReturnType RetVal;
  const uint32 *SrcPtr;
  uint32 *DestPtr;
  uint32 LengthChk;
  uint32 BitChange;


  RetVal = E_OK;

  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

  /*  Checking whether given SourceAddress is valid or not */

  if((SourceAddress >= (FLS_17_DMU_TOTAL_SIZE)) ||
      (((Fls_17_Dmu_AddressType)SourceAddress & FLS_WORD_SIZE_MASK) != 0U))
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_READSYNC, FLS_17_DMU_SE_PARAM_ADDRESS);

    RetVal = E_NOT_OK;
  }
  /*Check for Pointer to an application buffer*/

  else if(TargetAddressPtr == NULL_PTR)
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_READSYNC, FLS_17_DMU_E_PARAM_DATA);

    RetVal = E_NOT_OK;
  }
  /* Checking whether given Length is valid or not */

  else if((Length < FLS_ONE_VALUE) ||
          (Length > ((FLS_17_DMU_TOTAL_SIZE - SourceAddress) / FLS_WORD_SIZE)))
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_READSYNC, FLS_17_DMU_E_PARAM_LENGTH);

    RetVal = E_NOT_OK;
  }

  else if(Fls_lHWBusyCheck() != 0U)
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                       FLS_17_DMU_SID_READSYNC, FLS_17_DMU_SE_HW_BUSY);
    RetVal = E_NOT_OK;
  }
  else
  #endif
  {
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    JobType = StatePtr->FlsJobType;


    PhysicalAddress = (uint32)( FLS_17_DMU_BASE_ADDRESS + SourceAddress );

    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
    type is required to access the FLASH address/target address which
    is defined as unsigned long. */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
      is required to check the value of the address of data buffer alignment.*/
    SrcPtr = (uint32*)PhysicalAddress;

    DestPtr = (uint32*)TargetAddressPtr;

    LengthChk = (uint32)Length;


    /* Check if no operation ongoing */
    if(JobType == FLS_17_DMU_NONE)
    {
      /* Modify the GlobalVar JobType so that no new requests can be accepted on
      *the Bank till ReadSync is finished */
      StatePtr->FlsJobType = FLS_17_DMU_READSYNC;

      /*Clear the ECC status bits by writing DMU_SF_ECCC.CLR with 11b to clear
           AERM bit*/

      BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;

      /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
       the object types as the address of the register is being passed.*/
      FLS_17_DMU_DF1_SFR_WRITE(\
          (volatile uint32 *)&DMU_SF_ECCC.U, \
          BitChange);

      /*There is a delay of 2-3 cycles in the clearing of AERM bit*/
      NOP();
      NOP();
      NOP();


      /* Read the data */
      do
      {
        *DestPtr = *SrcPtr;
        /* Point to the next word */
        DestPtr++;
        /* Increment by one word */
        SrcPtr++;
        LengthChk--;
      }

      while(LengthChk > 0U);

      /* Restore the JobType with previous tasks */
      StatePtr->FlsJobType = FLS_17_DMU_NONE;

      /* Check for uncorrectable bit error */


      if(Fls_lChkBitErrors() != 0U)
      {
        /* Report Runtime error code to DET */



        #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)

        Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                                FLS_17_DMU_INSTANCE_ID,
                                FLS_17_DMU_SID_READSYNC,
                                FLS_17_DMU_E_READ_FAILED);
        #endif

        /* Return E_NOT_OK */
        RetVal = E_NOT_OK;
      }
    }
    else
    {

      #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
      Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_READSYNC, FLS_17_DMU_E_BUSY);
      #endif
      RetVal = E_NOT_OK;
    }
  }
  return(RetVal);
}


/*******************************************************************************
** Traceability : [cover parentID={071F2EBB-AF4C-4744-89F8-D802E4DDB976}]     **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_CompareWordsSync(                       **
**                              const Fls_17_Dmu_AddressType SourceAddress,   **
**                                     const uint32 *const TargetAddressPtr,  **
**                                     const uint32 Length);                  **
**                                                                            **
** Service ID: 0x22                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : SourceAddress - Source address in Flash memory.          **
**          This address offset is added to the flash memory base address     **
**                   TargetAddressPtr - Pointer to target data buffer         **
**                   Length - Number of words to be compared. It takes the    **
**                   value from 1 to Flash Size                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: Compare successful                                 **
**                   E_NOT_OK: HW busy or compare failed or ECC error         **
**                                                                            **
** Description : Service for comparing data from flash bank synchronously     **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_CompareWordsSync(
  const Fls_17_Dmu_AddressType SourceAddress,
  const uint32 *const TargetAddressPtr,
  const uint32 Length)
/* [cover parentID={EA54EE68-6A30-4a38-A981-DD82346FC1A1}]Fls_17_Dmu_CompareWordsSync
[/cover] */
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint8 JobType;

  uint32 PhysicalAddress;
  Std_ReturnType RetVal;
  const uint32 *SrcPtr;
  uint32 CompLen;
  uint32 BitChange;
  uint32 IndexTargetAddressPtr;


  RetVal = E_OK;

  IndexTargetAddressPtr = 0;

  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  /*  Checking whether given SourceAddress is valid or not */

  if((SourceAddress >= (FLS_17_DMU_TOTAL_SIZE)) ||
      (((uint32)SourceAddress & FLS_WORD_SIZE_MASK) != 0U))
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_COMPARESYNC,
                           FLS_17_DMU_SE_PARAM_ADDRESS);

    RetVal = E_NOT_OK;
  }
  /*Check for Pointer to an application buffer*/

  else if(TargetAddressPtr == NULL_PTR)
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_COMPARESYNC, FLS_17_DMU_SE_PARAM_DATA);

    RetVal = E_NOT_OK;
  }
  /* Checking whether given Length is valid or not */

  else if((Length < FLS_ONE_VALUE) ||
          (Length > ((FLS_17_DMU_TOTAL_SIZE - SourceAddress) / FLS_WORD_SIZE)))
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_COMPARESYNC, FLS_17_DMU_SE_PARAM_LENGTH);

    RetVal = E_NOT_OK;
  }/*Range Check Over*/


  else if(Fls_lHWBusyCheck() != 0U)/*HW Busy check*/
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_COMPARESYNC, FLS_17_DMU_SE_HW_BUSY);
    RetVal = E_NOT_OK;
  }
  else
  #endif
  {
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    JobType = StatePtr->FlsJobType;
    CompLen = Length;

    PhysicalAddress = (uint32)( FLS_17_DMU_BASE_ADDRESS + SourceAddress);

    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
           type is required to access the FLASH address/target address which
           is defined as unsigned long. */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
      is required to check the value of the address of data buffer alignment.
     */
    SrcPtr = (uint32*)PhysicalAddress;
    /* Check if no operation ongoing */

    if(JobType == FLS_17_DMU_NONE)
    {
      /* Modify the GlobalVar JobType so that no new requests can be accepted on
      the Bank till CompareSync is finished */

      StatePtr->FlsJobType = FLS_17_DMU_COMPARESYNC;

      /*Clear the ECC status bits by writing DMU_SF_ECCC.CLR with 11b to clear
              AERM bit*/


      BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;

      /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
       the object types as the address of the register is being passed.*/
      FLS_17_DMU_DF1_SFR_WRITE(\
          (volatile uint32 *)&DMU_SF_ECCC.U, \
          BitChange);

      /*There is a delay of 2-3 cycles in the clearing of AERM bit*/
      NOP();
      NOP();
      NOP();

      do
      {
        /* COMPARE THE FLASH DATA WITH THE BUFFER DATA (word Compare)*/
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
        array indexing used for FLASH address calculation and for subsequent
        traversal.The access range is within the flash address range.*/

        if( *(TargetAddressPtr + IndexTargetAddressPtr) != *SrcPtr )
        {

          RetVal = E_NOT_OK;


          CompLen = 0U;
        }
        else
        {


          IndexTargetAddressPtr++;
          SrcPtr++;
          CompLen--;
        }


      } while(CompLen > 0U);

      /* Restore the JobType with previous tasks */
      StatePtr->FlsJobType = FLS_17_DMU_NONE;

      /* Check for uncorrectable bit error */

      if(Fls_lChkBitErrors() != 0U)
      {

        #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)

        Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                                FLS_17_DMU_INSTANCE_ID,
                                FLS_17_DMU_SID_COMPARESYNC,
                                FLS_17_DMU_E_COMPARE_FAILED);
        #endif
        /* Return E_NOT_OK */
        RetVal = E_NOT_OK;

      }
    }
    else
    {

      #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
      Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_COMPARESYNC, FLS_17_DMU_SE_BUSY);
      #endif

      RetVal = E_NOT_OK;

    }
  }
  return(RetVal);

}


#if (FLS_17_DMU_IFX_NVM_PRESENT == STD_ON)
/*******************************************************************************
** Traceability :                                                             **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_VerifyErase(                            **
**                         const Fls_17_Dmu_AddressType TargetAddress         **
**                               ,uint32 *const UnerasedWordlineAddressPtr    **
**                               uint8 * const UnerasedWordlineCountPtr       **
**                               )                                            **
**                                                                            **
** Service ID: 0x23                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : TargetAddress                                            **
**                                                                            **
** Parameters (out): UnerasedWordlineAddressPtr,UnerasedWordlineCountPtr      **
**                                                                            **
** Return value    :  E_OK: Erase verification successful                     **
**                    E_NOT_OK: HW busy or erase verification failed          **
**                                                                            **
** Description : Service for verifying erase of a sector                      **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_VerifyErase(
  const Fls_17_Dmu_AddressType TargetAddress,
  uint32 *const UnerasedWordlineAddressPtr,
  uint8 * const UnerasedWordlineCountPtr )
/* [cover parentID={3C77357E-5460-46ff-A479-A216C527E574}]Fls_17_Dmu_VerifyErase
[/cover] */
{

  Std_ReturnType RetVal;


  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  const Fls_17_Dmu_StateType  *StatePtr;
  uint8 JobType;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobType = StatePtr->FlsJobType;

  /* Checking whether given TargetAddress is valid or not */

  if(((uint32)TargetAddress >= FLS_17_DMU_TOTAL_SIZE) ||
      ((TargetAddress & FLS_MOD4K_MASK ) != 0U))
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYERASE,
                           FLS_17_DMU_SE_PARAM_ADDRESS);

    RetVal = E_NOT_OK;
  }



  else if((UnerasedWordlineAddressPtr == NULL_PTR) ||
          (UnerasedWordlineCountPtr == NULL_PTR))
  {


    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYERASE, FLS_17_DMU_SE_PARAM_DATA);

    RetVal = E_NOT_OK;
  }

  else  if(JobType != FLS_17_DMU_NONE)/*Driver Busy*/
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYERASE, FLS_17_DMU_SE_BUSY);
    RetVal = E_NOT_OK;
  }

  else if(Fls_lHWBusyCheck() != 0U)/*HW Busy check*/
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYERASE, FLS_17_DMU_SE_HW_BUSY);
    RetVal = E_NOT_OK;
  }
  else
  {
  #endif


    RetVal = Fls_lLocalVerifyErase(TargetAddress, UnerasedWordlineAddressPtr,
                                   UnerasedWordlineCountPtr, 0U, 0U);
    #if(FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  }
    #endif
  return(RetVal);

}
#endif


/*******************************************************************************
** Traceability :  [cover parentID={73A7CFF7-D3A9-49ba-A186-E9AA3F27FC09}]    **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_VerifySectorErase                       **
**                                (const Fls_17_Dmu_AddressType TargetAddress,**
**                                 uint32 * const UnerasedWordlineAddressPtr  **
**                                 uint8 * const UnerasedWordlineCountPtr     **
**                               const uint8 Sector);                         **
**                                                                            **
** Service ID: 0x24                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : TargetAddress,Sector                                     **
**                                                                            **
** Parameters (out): UnerasedWordlineAddressPtr,UnerasedWordlineCountPtr      **
**                                                                            **
** Return value    :  E_OK: Erase verification successful                     **
**                    E_NOT_OK: HW busy or erase verification failed          **
**                                                                            **
** Description : Service for verifying erase of a sector                      **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_VerifySectorErase(
  const Fls_17_Dmu_AddressType TargetAddress,
  uint32 *const UnerasedWordlineAddressPtr,
  uint8 *const UnerasedWordlineCountPtr,
  const uint8 Sector)
/* [cover parentID={E4899288-DB87-4ef0-94EB-11BD01754497}]Fls_17_Dmu_VerifySectorErase
[/cover] */
{
  Std_ReturnType RetVal;

  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  const Fls_17_Dmu_StateType  *StatePtr;
  uint8 JobType;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobType = StatePtr->FlsJobType;

  /* Checking whether given TargetAddress is valid or not */

  if(((uint32)TargetAddress >= FLS_17_DMU_TOTAL_SIZE) ||
      ((TargetAddress & FLS_MOD4K_MASK ) != 0U))
  {
    /* Report Safety Error*/


    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYSECTORERASE,
                           FLS_17_DMU_SE_PARAM_ADDRESS);

    RetVal = E_NOT_OK;
  }


  else if((UnerasedWordlineAddressPtr == NULL_PTR) ||
          (UnerasedWordlineCountPtr == NULL_PTR))
  {
    /* Report Safety Error */
    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYSECTORERASE,
                           FLS_17_DMU_SE_PARAM_DATA);

    RetVal = E_NOT_OK;
  }
  /*FLS_17_DMU_NVMSECTOR_SIZE will always be a multiple of 4K*/

  else if(Sector >= (FLS_17_DMU_NVMSECTOR_SIZE / FLS_17_DMU_SUBSECTOR_SIZE))
  {
    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYSECTORERASE,
                           FLS_17_DMU_SE_PARAM_INVLD);
    RetVal = E_NOT_OK;
  }

  else  if(JobType != FLS_17_DMU_NONE)/*Driver Busy*/
  {
    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYSECTORERASE,
                           FLS_17_DMU_SE_BUSY);
    RetVal = E_NOT_OK;
  }

  else if(Fls_lHWBusyCheck() != 0U)/*HW Busy check*/
  {
    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_VERIFYSECTORERASE,
                           FLS_17_DMU_SE_HW_BUSY);
    RetVal = E_NOT_OK;
  }
  else
  {
  #endif


    RetVal = Fls_lLocalVerifyErase(TargetAddress, UnerasedWordlineAddressPtr,
                                   UnerasedWordlineCountPtr, Sector,
                                   FLS_VERIFYSECTOR_CHK_VAL);
    #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  }
    #endif
  return(RetVal);
}


/*******************************************************************************
** Traceability :  [cover parentID={EDD8E749-FB74-4f70-AA54-681738556B8D}]    **
**                                                                            **
** Syntax : Std_ReturnType Fls_lLocalVerifyErase                              **
**                            (const Fls_17_Dmu_AddressType TargetAddress,    **
**                                 uint32 * const UnerasedWordlineAddressPtr  **
**                                 uint8 * const UnerasedWordlineCountPtr     **
**                            const uint8 *Sector, const uint32 value)        **
**                                                                            **
** Service ID: 0x24                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : TargetAddress,Sector                                     **
**                                                                            **
** Parameters (out): UnerasedWordlineAddressPtr,UnerasedWordlineCountPtr,     **
**                                                                            **
**                                                                            **
** Return value    :  E_OK: Erase verification successful                     **
**                    E_NOT_OK: HW busy or erase verification failed          **
**                                                                            **
** Description : Service for verifying erase of a sector                      **
*******************************************************************************/
static Std_ReturnType Fls_lLocalVerifyErase(
  const Fls_17_Dmu_AddressType TargetAddress,
  uint32 *const UnerasedWordlineAddressPtr,
  uint8 *const UnerasedWordlineCountPtr,
  const uint8 Sector, const uint32 value)
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint32 PhysicalAddress;
  uint32 *SrcPtr;
  uint32 Length;
  uint32 UnerasableWLAddr;
  uint32 HFMarginBackUpVal;
  uint32 BitChange;
  uint16 TimeOutCountInitial;
  uint16 TimeOutResolution;
  uint16 TimeOutCount;
  uint16 MeasuredTicks;
  uint8 FailCount;
  uint8 CompareFail;
  uint8 JobType;
  Std_ReturnType RetVal;


  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobType = StatePtr->FlsJobType;

  RetVal = E_OK;

  /* Store the DMU_SF_MARGIN value so that it can be restored later */

  HFMarginBackUpVal = DMU_SF_MARGIN.U;


  if(value == FLS_VERIFYSECTOR_CHK_VAL)
  {


    FailCount = *UnerasedWordlineCountPtr;
  }
  #if (FLS_17_DMU_IFX_NVM_PRESENT == STD_ON)
  else
  {


    FailCount = 0U;
  }
  #endif

  /*Clear the ECC status bits by writing DMU_SF_ECCC.CLR with 11b to clear
                   AERM bit*/
  BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;

  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
   the object types as the address of the register is being passed.*/
  FLS_17_DMU_DF1_SFR_WRITE(\
      (volatile uint32 *)&DMU_SF_ECCC.U, \
      BitChange);

  /* If EVER bit is 1, then read has to be performed with tight margin for
  0-level. Switch to hard margin is done here instead of doing it just before
     read, because it takes 2us (tFL_MarginDel) for the switch over to happen.
     */
  BitChange = (DMU_SF_MARGIN.U | FLS_READHARDMARGIN_VAL)& \
              FLS_TIGHT0MARGIN_VAL;
  DMU_SF_MARGIN.U = BitChange;
  NOP();
  NOP();


  /*2us delay for margin switchover*/
    /* Get the Tick resolution */
    TimeOutResolution = Timer_DelayTickResolution();
    /* Calculate the Delay count */
  TimeOutCount = FLS_DMU_MARGIN_TIMEOUT / TimeOutResolution;
  /* Get the Initial count */
  TimeOutCountInitial = Timer_DelayGetTick();


  do
  {
    /* Calculate the elapsed Tick  */
    MeasuredTicks = Timer_DelayGetTick() -  TimeOutCountInitial;

  } while (TimeOutCount > MeasuredTicks);

  PhysicalAddress = FLS_17_DMU_BASE_ADDRESS + TargetAddress;


  if(value == FLS_VERIFYSECTOR_CHK_VAL)
  {

    SrcPtr =
      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
         integer type is required to access the FLASH address/target address
         which is defined as unsigned long. */
      /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
         is required to check the value of the address of data buffer alignment.
           */
      /* MISRA2012_RULE_10_8_JUSTIFICATION: conversion between pointer and
         integer type is required to access the FLASH address/target address
         which is defined as unsigned long. */

      (uint32 *)(PhysicalAddress + (uint32)(FLS_17_DMU_SUBSECTOR_SIZE * \
                                            Sector));

  }
  #if (FLS_17_DMU_IFX_NVM_PRESENT == STD_ON)
  else
  {
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
         type is required to access the FLASH address/target address which
              is defined as unsigned long. */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
      is required to check the value of the address of data buffer alignment.
      */


    SrcPtr = (uint32*)PhysicalAddress;
  }
  #endif

  /* Check if no operation ongoing */

  if(JobType == FLS_17_DMU_NONE)
  {
    /* Modify the GlobalVar JobType so that no new requests can be accepted on
                   the Bank till VerifyErase is finished */
    StatePtr->FlsJobType = FLS_17_DMU_VERIFYERASE;


    if(value == FLS_VERIFYSECTOR_CHK_VAL )
    {
      /* Data Flash Bank0 : Logical sector size-> 4K bytes*/


      Length = FLS_17_DMU_SUBSECTOR_SIZE;
    }
    #if (FLS_17_DMU_IFX_NVM_PRESENT == STD_ON)
    else
    {


      Length = FLS_17_DMU_NVMSECTOR_SIZE;
    }
    #endif

    /* Check if there is verify error during Erase operation */
    do
    {
      CompareFail = 0U;

      /* COMPARE THE FLASH DATA WITH zero (first 16 Bytes of the Wordline)*/

      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
       array indexing used for FLASH address calculation and for subsequent
       traversal.The access range is within the flash address range.*/


      if((*SrcPtr != 0U) || (*(SrcPtr + 1U) != 0U) || \
          (*(SrcPtr + 2U) != 0U) || (*(SrcPtr + 3U) != 0U) )
      {
        CompareFail = 1U;
      }


      if(Fls_lChkBitErrors() != 0U)
      {

        CompareFail = 1U;
      }

      if(CompareFail == 1U)
      {

        FailCount++;


        if(FailCount > FLS_WL_FAIL_COUNT)
        {

          RetVal = E_NOT_OK;

        }
        else
        {
          /* Update the Unerasable WL address */
          /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and
            integer type is required to access the FLASH address/target address
            which is defined as unsigned long. */
          /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to
             pointer is required to access the FLASH address/target address
             which is defined as unsigned long by AUTOSAR. */
          UnerasableWLAddr = (uint32)SrcPtr - FLS_17_DMU_BASE_ADDRESS;




          /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
          array indexing used for FLASH address calculation and for subsequent
          traversal.The access range is within the flash address range.*/
          /* MISRA2012_RULE_10_4_JUSTIFICATION: cast from uint8 to uint32
            is required to interface for storage of failed wordline address
            in the FEE buffer. The operation is working as expected.*/
          *(UnerasedWordlineAddressPtr + ((uint32)FailCount - 1U))
            = UnerasableWLAddr;

          /* increment SrcPtr to next wordline, divide by 4 for SrcPtr is
             uint32 ptr*/

          /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
          array indexing used for FLASH address calculation and for subsequent
          traversal.The access range is within the flash address range.*/
          SrcPtr += (FLS_17_DMU_WORDLINE_SIZE / FLS_WORD_SIZE);
          Length -= FLS_17_DMU_WORDLINE_SIZE;
        }
      }
      else
      {
        /* increment SrcPtr to next wordline, divide by 4 for SrcPtr is
           uint32 ptr*/


        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
        array indexing used for FLASH address calculation and for subsequent
        traversal.The access range is within the flash address range.*/
        SrcPtr += (FLS_17_DMU_WORDLINE_SIZE / FLS_WORD_SIZE);
        Length -= FLS_17_DMU_WORDLINE_SIZE;
      }

    } while((Length != 0U) && (FailCount <= FLS_WL_FAIL_COUNT));


    *UnerasedWordlineCountPtr = FailCount;

    /* Restore the JobType with previous tasks */
    StatePtr->FlsJobType = FLS_17_DMU_NONE;
  }
  else
  {

    RetVal = E_NOT_OK;

  }

  /*Restore the DMU_SF_MARGIN value that was backed-up earlier */
  DMU_SF_MARGIN.U = HFMarginBackUpVal;

  return(RetVal);
}



/*******************************************************************************
** Traceability :                                                             **
**                                                                            **
** Syntax : Fls_17_Dmu_Job_Type Fls_17_Dmu_GetNotifCaller(void)               **
**                                                                            **
** Service ID: 0x29                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  FLS Job that raised the notification                    **
**                                                                            **
** Description :                                                              **
** Ths function returns the FLS Job that raised the notification              **
*******************************************************************************/
Fls_17_Dmu_Job_Type Fls_17_Dmu_GetNotifCaller(void)
/* [cover parentID={519B41BB-BF62-462e-ABC6-1F035388EE0F}]Fls_17_Dmu_GetNotifCaller
[/cover] */
{

  return(Fls_ConfigPtr->FlsStateVarPtr->NotifCaller);


}

#endif /* FLS_17_DMU_IFX_FEE_USED == STD_ON */



#if (FLS_17_DMU_USE_ERASESUSPEND == STD_ON)
/*******************************************************************************
** Traceability :                                                             **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_SuspendErase(void)                      **
**                                                                            **
** Service ID: 0x25                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK - Erase suspend successful                         **
**                    E_NOT_OK - Erase suspend failed                         **
**                                                                            **
** Description :                                                              **
** Ths function suspends an ongoing erase of a sector.                        **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_SuspendErase(void)
/* [cover parentID={E62F23D2-A43A-4d8f-B76C-6DDA9D9A79F2}]Fls_17_Dmu_SuspendErase
[/cover] */
{
  Std_ReturnType RetVal;
  Fls_17_Dmu_StateType  *StatePtr;
  uint32 TimeOutCount;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  uint32 BitChange;



  if(DMU_SF_STATUS.B.D1BUSY != 1U)
  {

    RetVal = E_NOT_OK;
  }

  else if(DMU_SF_SUSPEND.B.SPND == 1U)
  {

    RetVal = E_OK;
  }
  else
  {
    BitChange = DMU_SF_SUSPEND.U | IFX_DMU_SF_SUSPEND_REQ_MSK;
    DMU_SF_SUSPEND.U = BitChange;

    TimeOutCount = FLS_17_DMU_ERASESUSPEND_TIMEOUT;
    do
    {
      TimeOutCount-- ;

      /*MISRA2012_RULE_13_5_JUSTIFICATION: These are device registers and are
      declared with Volatile qualifier due to which the tool is giving MISRA 13.5.
      */
    } while((TimeOutCount > 0U) && (DMU_SF_SUSPEND.B.REQ == 1U));


    if (TRUE == Fls_lSpndTimeout(TimeOutCount))
    {

      RetVal = E_NOT_OK;
    }

    else if(DMU_SF_SUSPEND.B.SPND != 1U)
    {
      /* Clear Suspend Error status */

      BitChange = DMU_SF_SUSPEND.U | SUSPEND_CLR_OFF;
      DMU_SF_SUSPEND.U = BitChange;

      RetVal = E_NOT_OK;
    }
    else
    {
      /*EVER check*/

      if((DMU_SF_ERRSR.B.EVER != 0U)
          && (StatePtr->FlsEver == (uint8)0))
      {
        StatePtr->FlsEver = FLS_EVER_CHK;
      }

      RetVal = E_OK;
      /* Set job status for the bank to None */

      StatePtr->FlsJobType = FLS_17_DMU_NONE;
      /* Reset JobStartStatus */
      StatePtr->JobStarted.Erase = 0U;
      /* Set the flash job result to job ok */
      StatePtr->FlsJobResult = MEMIF_JOB_OK;
    }
  }

  return RetVal;
}

/*******************************************************************************
** Traceability :  [cover parentID={0F3EBC6B-A3E5-452f-87AD-3D740F53F2C2}]    **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_ResumeErase ()                          **
**                                                                            **
** Service ID: 0x26                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK - Resume Erase successful                          **
**                    E_NOT_OK - Resume Erase failed                          **
**                                                                            **
** Description :                                                              **
** This function resumes an already suspended erase of a sector.              **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_ResumeErase (void)
/* [cover parentID={478A22CE-6897-4722-81AB-41264DBC1353}]Fls_17_Dmu_ResumeErase
[/cover] */
{
  Std_ReturnType RetVal;
  Fls_17_Dmu_StateType  *StatePtr;
  uint32 PhysicalAddress;
  uint16 TimeOutCount;
  uint32 BitChange;
  uint16 TimeOutCountInitial;
  uint16 TimeOutResolution;
  uint16 MeasuredTicks;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  RetVal = E_OK;


  if (Fls_lHWBusyCheck() != 0U)
  {
      #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

      Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_RESUMEERASE, FLS_17_DMU_SE_HW_BUSY);
      #endif
      RetVal = E_NOT_OK;
  }

   else  if(StatePtr->FlsJobType != FLS_17_DMU_NONE)/*Driver Busy*/
  {
      #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

      Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_RESUMEERASE, FLS_17_DMU_SE_BUSY);
      #endif
      RetVal = E_NOT_OK;
  }

  else if(DMU_SF_SUSPEND.B.SPND == 1U)
  {
    PhysicalAddress = Fls_ConfigPtr->FlsStateVarPtr->FlsEraseAddress;

    Fls_lClearStatusCmdCycle();

    /* Execute the Resume ERASE COMMAND CYCLES */

    Fls_lResumeEraseCmdCycle(PhysicalAddress);

    /*Timeout for the resume command to complete*/
    /* Get the Tick resolution */
    TimeOutResolution = Timer_DelayTickResolution();
    /* Calculate the Delay count */
    TimeOutCount = FLS_RESUMEERASE_TIMEOUT / TimeOutResolution;
    /* Get the Initial count */
    TimeOutCountInitial = Timer_DelayGetTick();

    do
    {
      /* Calculate the elapsed Tick  */
      MeasuredTicks = Timer_DelayGetTick() -  TimeOutCountInitial;

    } while ((DMU_SF_SUSPEND.B.SPND == 1U) && (TimeOutCount > MeasuredTicks));


    if(0U != Fls_lChkOperError())
    {
      #if(FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
      Det_ReportRuntimeError((uint16)FLS_17_DMU_MODULE_ID,
                                    FLS_17_DMU_INSTANCE_ID,
                                    FLS_17_DMU_SID_RESUMEERASE,
                                    FLS_17_DMU_E_RESUME_FAIL);
      #endif
      /* OPER error occured */
      RetVal = E_NOT_OK;
    }
    else
    {
      if(Fls_lChkSeqError() != 0U)/*SQER check*/
      {
        /* Clear the error status flags */
        BitChange = FLS_DMU_ERR_CLR;
        /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
        the object types as the address of the register is being passed.*/
        FLS_17_DMU_DF1_SFR_WRITE((volatile uint32 *)&DMU_SF_CLRE.U, \
                                     BitChange);
        #if(FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)

        Det_ReportRuntimeError((uint16)FLS_17_DMU_MODULE_ID,
                                     FLS_17_DMU_INSTANCE_ID,
                                     FLS_17_DMU_SID_RESUMEERASE,
                                     FLS_17_DMU_E_RESUME_FAIL);
        #endif

        RetVal = E_NOT_OK;
      }
      /*
        If timeout occurred, then give HW timeout error
      */
      else if((DMU_SF_SUSPEND.B.SPND == 1U) && (TimeOutCount < MeasuredTicks))
      {
        #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

        Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_RESUMEERASE, FLS_17_DMU_SE_HW_TIMEOUT);
        #endif
        /* If timeout happens and Suspend bit is not cleared return E_NOT_OK*/
        RetVal = E_NOT_OK;
      }
      else
      {
        /* Get the Tick resolution */
        TimeOutResolution = Timer_DelayTickResolution();
        /* Calculate the Delay count */
        TimeOutCount = (uint16)FLS_17_DMU_HWBUSY_DELAY / TimeOutResolution;
        /* Get the Initial count */
        TimeOutCountInitial = Timer_DelayGetTick();
        /* wait for 100ns */
        do
        {
          /* Calculate the elapsed Tick  */
          MeasuredTicks = Timer_DelayGetTick() -  TimeOutCountInitial;

        } while (TimeOutCount > MeasuredTicks);

        /* Restore the JobType with previous erase */
        StatePtr->FlsJobType = FLS_17_DMU_ERASE;
        /* Set the flash job result to job pending */
        StatePtr->FlsJobResult = MEMIF_JOB_PENDING;
        /*Indicate that the ERASE Job has been started */
        StatePtr->JobStarted.Erase = 1U;
      }
    }
  }
  else
  {
    /*MISRA*/
  }

  return RetVal;
}

#endif /* FLS_USE_ERASESUSPEND == STD_ON */

/*******************************************************************************
** Traceability :                                                             **
**                                                                            **
** Syntax : Std_ReturnType Fls_17_Dmu_GetOperStatus(void)                     **
**                                                                            **
** Service ID: 0x2A                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK - No OPER error                                    **
**                    E_NOT_OK - OPER error has occurred                      **
**                                                                            **
** Description : This function provides the OPER error status                 **
*******************************************************************************/
Std_ReturnType Fls_17_Dmu_GetOperStatus(void)
/* [cover parentID={284116EC-B6F7-4276-96FE-3AA60587BC9C}]Fls_17_Dmu_GetOperStatus
[/cover] */
{
  uint32 OPER_Status;
  Std_ReturnType RetVal;

  RetVal = E_OK;

  OPER_Status = ((uint32)DMU_SF_ERRSR.U & IFX_DMU_SF_ERRSR_OPER_MSK);

  if(0U != OPER_Status)
  {

    RetVal = E_NOT_OK;
  }

  return (RetVal);
}


/*******************************************************************************
** Traceability :                                                             **
**                                                                            **
** Syntax : void Fls_17_Dmu_ControlTimeoutDet(const uint8 Param)              **
**                                                                            **
** Service ID: 0x2B                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  Param  - Value for timeout                              **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : This is the function to disable and re-enable detection /    **
**               reporting of time-out DET                                    **
*******************************************************************************/
void Fls_17_Dmu_ControlTimeoutDet(const uint8 Param)
/* [cover parentID={E21C9DB9-FFE7-4807-9088-185BCAEBE945}]Fls_17_Dmu_ControlTimeoutDet[/cover] */
{

  #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
  (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

  if(Param > ((uint8)0x01))
  {
    #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                 FLS_17_DMU_SID_CONTROLTIMEOUTDET, FLS_17_DMU_SE_PARAM_INVLD);
    #endif
  }
  else
  {

    Fls_ConfigPtr->FlsStateVarPtr->FlsTimeoutControl = Param;
  }

  #else
  UNUSED_PARAMETER(Param);
  #endif
}

#if(FLS_17_DMU_IFX_FEE_USED == STD_ON)
/*******************************************************************************
** Traceability :  [cover parentID={685AB4B7-A883-439e-9AAD-040235A9CF46}]    **
**                                                                            **
** Syntax : Fls_17_Dmu_HardenType Fls_17_Dmu_IsHardeningRequired(             **
**                    const Fls_17_Dmu_AddressType TargetAddress,             **
**                    const uint8 AlignChk )                                  **
**                                                                            **
** Service ID: 0x2C                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  TargetAddress, AlignChk                                 **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Fls_17_Dmu_HardenType                                   **
**                                                                            **
** Description : The function checks whether the contents of memory at        **
                 requested wordline address needs hardening or not            **
*******************************************************************************/
Fls_17_Dmu_HardenType Fls_17_Dmu_IsHardeningRequired(
  const Fls_17_Dmu_AddressType TargetAddress,
  const uint8 AlignChk)
/* [cover parentID={ABEE16D0-CB28-422d-B3CE-FFA63C0990BB}]Fls_17_Dmu_IsHardeningRequired
[/cover] */
/* [cover parentID={6C804F97-3744-42d8-89E8-0845DA77B8D3}]Fls_17_Dmu_IsHardeningRequired
[/cover] */
{
  uint8 RetVal;
  uint8 ECCErrorStat;
  uint32 PhysicalAddress;
  uint32 CountDiff, BitChange = 0U, BitRestore;
  uint32 TimeOutType;
  uint32 TimeOutCount;
  uint32 TimeOutCountInitial;
  uint32 TimeOutResolution;
  uint32 MeasuredTicks;
  uint32 OperStatusChk;

  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

  if((Fls_lHardenSafetyChk(TargetAddress, AlignChk))
      == FLS_17_DMU_HARDENCHK_ERROR)
  {

    RetVal = FLS_17_DMU_HARDENCHK_ERROR;
  }
  else
  #endif
  {
    PhysicalAddress = FLS_17_DMU_BASE_ADDRESS + TargetAddress;

    /* Set the control gate voltage to 4.1V before executing the command */

    FSI_HSMCOMM_1.B.HSMCOMM1 = FLS_CTRLGATEVOLTAGE_VAL;

    BitRestore = DMU_SF_CONTROL.U;


    if(FLS_17_DMU_PAGE_HARDEN == AlignChk)
    {

      BitChange = ((uint32)DMU_SF_CONTROL.U | FLS_DMU_HARDEN_PAGE_ALIGN);
      TimeOutType = (uint32)FLS_USRCONTENT_PAGE_TIMEOUT;
    }
    else
    {

      BitChange = ((uint32)DMU_SF_CONTROL.U & FLS_DMU_HARDEN_WORD_ALIGN);
      TimeOutType = (uint32)FLS_USRCONTENT_WL_TIMEOUT;
    }

    FLS_17_DMU_DF1_SFR_WRITE(&DMU_SF_CONTROL.U,
        BitChange);

    Fls_lClearStatusCmdCycle();

    /* Execute the user content count command sequence */
    Fls_lUserContentCountCmdCycle(PhysicalAddress);

    /*Wait for 20us/100us*/

    /* Get the Tick resolution */
    TimeOutResolution = Timer_DelayTickResolution();
    /* Calculate the Delay count */
    TimeOutCount = TimeOutType / TimeOutResolution;
    /* Get the Initial count */
    TimeOutCountInitial = Timer_DelayGetTick();


    do
    {
      /* Calculate the elapsed Tick, consider lower 16bits to handle
      timer overflow */
      MeasuredTicks = ((Timer_DelayGetTick() -  TimeOutCountInitial) &
                      FLS_16BIT_MASK);
      OperStatusChk = ((uint32)DMU_SF_ERRSR.U & FLS_OPER_ERROR);

    } while ((Fls_lHWBusyCheck() != 0U) && (OperStatusChk != 1U)
          && (TimeOutCount > MeasuredTicks));

    /*Check for OPER*/
    if(Fls_lChkOperError() != 0U)
    {
      /*Harden fail due to OPER error*/
      RetVal = FLS_17_DMU_HARDENCHK_ERROR;

      #if(FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)

      Det_ReportRuntimeError((uint16)FLS_17_DMU_MODULE_ID,
                             FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_ISHARDENINGREQ,
                             FLS_17_DMU_E_HARDENCHK_FAIL);
      #endif
    }
    /* Check for timeout */
    else if(TimeOutCount <= MeasuredTicks)
    {
      #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)


      Mcal_ReportSafetyError((uint16)FLS_17_DMU_MODULE_ID,
                             FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_ISHARDENINGREQ,
                             FLS_17_DMU_SE_HW_TIMEOUT);
      #endif


      RetVal = FLS_17_DMU_HARDENCHK_ERROR;
    }
    /* Check for SQER */
    else if (Fls_lChkSeqError() != 0U)
    {
      RetVal = FLS_17_DMU_HARDENCHK_ERROR;
      /*Clear the SQER/PVER/EVER error*/
      BitChange = FLS_DMU_ERR_CLR;
      /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
       the object types as the address of the register is being passed.*/
      FLS_17_DMU_DF1_SFR_WRITE( \
                                      (volatile uint32 *)&DMU_SF_CLRE.U, \
                                      BitChange);

      #if(FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)


      Det_ReportRuntimeError((uint16)FLS_17_DMU_MODULE_ID,
                             FLS_17_DMU_INSTANCE_ID,
                             FLS_17_DMU_SID_ISHARDENINGREQ,
                             FLS_17_DMU_E_HARDENCHK_FAIL);
      #endif
    }

    else
    {

      /* Result (Difference in count of '1' bits) is returned as 13-bit unsigned
          integer with bits [7:0] in FSI_HSMCOMM_1.HSMCOMM1[7:0] and bits [12:8] in
          FSI_HSMCOMM_2.HSMCOMM2[4:0]. Ordering of the information is done and
          stored in CountDiff*/

      CountDiff = FSI_HSMCOMM_2.B.HSMCOMM2;

      CountDiff = (CountDiff & FLS_FSIHSMCOMM2RES_MASK) << FLS_SHIFT8BITS_VAL;


      CountDiff |= FSI_HSMCOMM_1.B.HSMCOMM1;

      /* Obtain the TBE (3 bit error) status after the command execution */

      ECCErrorStat = FSI_HSMCOMM_2.B.HSMCOMM2 & FLS_COMM2TBE_MASK;

      /* Hardening is required either if there is a difference in number of
         '1'-bits with tight margin for 0-level and the number of '1'-bits with
         tight margin for 1-level or with 3-bit ECC errors */

      if ((CountDiff > 1U) && (FLS_17_DMU_PAGE_HARDEN == AlignChk))
      {

        RetVal = FLS_17_DMU_HARDENCHK_REQRD;
      }

      else if((CountDiff > 2U) && (FLS_17_DMU_WORDLINE_HARDEN == AlignChk))
      {

        RetVal = FLS_17_DMU_HARDENCHK_REQRD;
      }

      else if(ECCErrorStat != 0U)
      {

        RetVal = FLS_17_DMU_HARDENCHK_REQRD;
      }
      else
      {

        RetVal = FLS_17_DMU_HARDENCHK_NOTREQD;
      }

      /*Clear the page alignment to restore the previosu status so that other
       operations are not affected*/
      FLS_17_DMU_DF1_SFR_WRITE(&DMU_SF_CONTROL.U,
          BitRestore);

      /*Reset the COMM1 and COMM2 values to system reset values*/
      FSI_HSMCOMM_1.U = FLS_HSMCOMM_RESET_VAL;
      FSI_HSMCOMM_2.U = FLS_HSMCOMM_RESET_VAL;

    } /*timeout, SQER*/

  } /*Range Check is OK*/

  return (RetVal);
}


#if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Traceability :  [cover parentID={DECD5BE2-41EA-45d4-8242-0388F4E97A67}]    **
**                                                                            **
** Syntax : LOCAL_INLINE uint8 Fls_lHardenSafetyChk(const                     **
**              Fls_17_Dmu_AddressType TargetAddress, const uint8 AlignChk)   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  TargetAddress, AlignChk                                 **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Fls_17_Dmu_HardenType                                   **
**                                                                            **
** Description : This function which will do the safety  and                  **
                 range check for the Fls_17_Dmu_IsHardeningRequired()         **
*******************************************************************************/
LOCAL_INLINE uint8 Fls_lHardenSafetyChk(
  const Fls_17_Dmu_AddressType TargetAddress, const uint8 AlignChk)
{
  uint8 RetVal;
  const Fls_17_Dmu_StateType  *StatePtr;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  RetVal = FLS_17_DMU_HARDENCHK_NOTREQD;
  /*Check the Target Address*/

  if(((uint32)TargetAddress) >= FLS_17_DMU_TOTAL_SIZE)
  {


    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                  FLS_17_DMU_SID_ISHARDENINGREQ, FLS_17_DMU_SE_PARAM_ADDRESS);

    RetVal = FLS_17_DMU_HARDENCHK_ERROR;
  }

  else if(((FLS_17_DMU_WORDLINE_HARDEN == AlignChk) &&
           ((TargetAddress & FLS_WL_SIZE_MASK) != 0U)) ||
          ((FLS_17_DMU_PAGE_HARDEN == AlignChk) &&
           ((TargetAddress & FLS_PAGE_SIZE_MASK) != 0U)))
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                  FLS_17_DMU_SID_ISHARDENINGREQ, FLS_17_DMU_SE_PARAM_ADDRESS);
    RetVal = FLS_17_DMU_HARDENCHK_ERROR;
  }

  else if((FLS_17_DMU_WORDLINE_HARDEN != AlignChk) &&
          (FLS_17_DMU_PAGE_HARDEN != AlignChk))
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                  FLS_17_DMU_SID_ISHARDENINGREQ, FLS_17_DMU_SE_PARAM_INVLD);
    RetVal = FLS_17_DMU_HARDENCHK_ERROR;
  }

  else if(Fls_lHWBusyCheck() != 0U)/*HW Busy check*/
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                      FLS_17_DMU_SID_ISHARDENINGREQ, FLS_17_DMU_SE_HW_BUSY);
    RetVal = FLS_17_DMU_HARDENCHK_ERROR;
  }

  else  if(StatePtr->FlsJobType != FLS_17_DMU_NONE)/*Driver Busy*/
  {

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                       FLS_17_DMU_SID_ISHARDENINGREQ, FLS_17_DMU_E_BUSY);
    RetVal = FLS_17_DMU_HARDENCHK_ERROR;
  }
  else
  {
    /*MISRA*/
  }

  return(RetVal);
}
#endif
#endif


/*******************************************************************************
** Traceability   : [cover parentID={37415CD4-E15C-4510-A1CC-22A5D72046F3}]   **
**                                                                            **
** Syntax : static void Fls_lMainErase(void)                                  **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : void                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the erase operation during Cyclic                   **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainErase(void)

{
  Fls_17_Dmu_StateType       *StatePtr;
  MemIf_JobResultType LastJobResult;
  uint32 BitChange;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  /* Check for operational error */
  if(Fls_lChkOperError() != 0U)
  {
    /* Erase Job fails due to hardware error */
    /* Report Runtime error code to DET */
    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)

    Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                            FLS_17_DMU_INSTANCE_ID,
                            FLS_17_DMU_SID_MAIN,
                            FLS_17_DMU_E_ERASE_FAILED);
    #endif
    /* Call Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_17_DMU_ERASE);
  }
  else if(DMU_SF_ERRSR.B.EVER != 0U)
  {
    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
    Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                          FLS_17_DMU_INSTANCE_ID,
                          FLS_17_DMU_SID_MAIN,
                          FLS_17_DMU_E_ERASE_FAILED);
    #endif
    /******************************** DET *************************************/
    #if ( FLS_17_DMU_IFX_FEE_USED ==  STD_OFF )
      #if((FLS_17_DMU_DEV_ERROR_DETECT == STD_ON )|| \
          (FLS_17_DMU_SAFETY_ENABLE == STD_ON))
        Fls_lReportError(FLS_17_DMU_SID_MAIN,FLS_17_DMU_E_VERIFY_ERASE_FAILED);
      #endif
      Fls_lErrorHandler(FLS_17_DMU_ERASE);
    #else
      Fls_lEverFlagChkFail();
    #endif
  }
  else
  {
    /* Set to JOB_OK if no warnings  */
    LastJobResult = MEMIF_JOB_OK;

    if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)
    {
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_ERASE_JOB;
      /* FlsJobEndNotificationPtr should be called */
      (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
    }
    /* Update the global status variables */
    StatePtr->FlsJobResult = LastJobResult;
    /* Clear the Erase Job */
    StatePtr->FlsJobType = FLS_17_DMU_NONE;
    /* Clear JobStarted bit for operation JobType */
    StatePtr->JobStarted.Erase = 0U;
  }
  /*Clear the OPER, SQER error*/
  BitChange = FLS_DMU_ERR_CLR;
  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
  the object types as the address of the register is being passed.*/
  FLS_17_DMU_DF1_SFR_WRITE((volatile uint32 *)&DMU_SF_CLRE.U, BitChange);
}

/*******************************************************************************
** Traceability :[cover parentID={2C50AC81-E6FE-45bc-BF8D-827C0A73DFF5}]      **
**                                                                            **
** Syntax : static void Fls_lEverFlagChkFail(void)                            **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : void                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the erase operation during Cyclic                   **
**               Job handling                                                 **
*******************************************************************************/
#if (FLS_17_DMU_IFX_FEE_USED == STD_ON)
static void Fls_lEverFlagChkFail(void)
{
  /* MISRA2012_RULE_8_13_JUSTIFICATION: pointer is updated
     so it is not declared const. */
  Fls_17_Dmu_StateType       *StatePtr;
  uint32 BitChange;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  StatePtr->JobStarted.Erase = 0U;

  /* Clear the failed Job  */
  StatePtr->FlsJobType = FLS_17_DMU_NONE;

  /* Update the global status variables */
  StatePtr->FlsJobResult = MEMIF_JOB_FAILED;


  if(Fls_ConfigPtr->FlsEraseVerifyErrNotifPtr != NULL_PTR)
  {
    Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_ERASE_JOB;

    /* Fls EVER Notification should be called */

    (Fls_ConfigPtr->FlsEraseVerifyErrNotifPtr)();
    Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
  }


  StatePtr->FlsEver = (uint8)0x00;

  /*Clear EVER error*/
  BitChange = FLS_DMU_ERR_CLR;
  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
   the object types as the address of the register is being passed.*/
  FLS_17_DMU_DF1_SFR_WRITE( \
                                  (volatile uint32 *)&DMU_SF_CLRE.U, \
                                  BitChange);
}
#endif

/*******************************************************************************
** Traceability :[cover parentID={F4367CF1-D6D3-45b3-BA3C-377009141D20}]      **
**                                                                            **
** Syntax : static void Fls_lMainRead(void)                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : void                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the Read operation during Cyclic                    **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainRead(void)

{
  Fls_17_Dmu_StateType       *StatePtr;
  Fls_17_Dmu_LengthType      ReadCount;
  MemIf_JobResultType LastJobResult;
  uint8               *SourcePtr;
  Fls_17_Dmu_LengthType      MaxRead;
  uint32    BitChange;
  /************* Initialise Local Variables *****************************/
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  /* Get max read length according to the FLS mode */
  MaxRead = Fls_lGetReadModeLength();

  /* Check whether the given length is greater than MAX_READ */

  if(StatePtr->FlsReadLength > MaxRead)
  {

    /* Load Max Byte to read in one cycle */
    ReadCount = MaxRead;
    /* Decrement the count from the total count to read */
    StatePtr->FlsReadLength = StatePtr->FlsReadLength - ReadCount;
  }
  else
  {


    ReadCount = StatePtr->FlsReadLength;
    StatePtr->FlsReadLength = 0U;
  }

  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
         type is required to access the FLASH address/target address which
         is defined as unsigned long. */
  /* Obtain the Read Address */
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
    is required to check the value of the address of data buffer alignment. */
  SourcePtr = (uint8 *)(StatePtr->FlsReadAddress);

  /*Clear the ECC status bits by writing DMU_SF_ECCC.CLR with 11b to clear
       AERM bit*/

  BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;

  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
   the object types as the address of the register is being passed.*/
  FLS_17_DMU_DF1_SFR_WRITE(\
      (volatile uint32 *)&DMU_SF_ECCC.U, \
      BitChange);

  /*There is a delay of 2-3 cycles in the setting of AERM bit*/
  NOP();
  NOP();
  NOP();

  do
  {
    /* READ DATA AND STORE THE DATA AT DESTINATION */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
          type is required to access the FLASH address/target address which
              is defined as unsigned long. */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
       is required to access the FLASH address/target address which is defined
            as unsigned long by AUTOSAR. */

    if( (ReadCount >= FLS_WORD_SIZE) && \
        ( (((uint32)SourcePtr & FLS_THREE_VALUE) == 0U) && \
          (((uint32)(StatePtr->FlsReadBufferPtr) & FLS_THREE_VALUE) == 0U))
      )
    {
      /* Perform Word Read to save runtime */
      /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
       the object types as the address of the register is being passed.*/


      *((uint32*)(StatePtr->FlsReadBufferPtr)) = *((uint32*)SourcePtr);

      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
      array indexing used for FLASH address calculation and for subsequent
      traversal.The access range is within the flash address range.*/
      (StatePtr->FlsReadBufferPtr) += FLS_WORD_SIZE;

      /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
      array indexing used for FLASH address calculation and for subsequent
      traversal.The access range is within the flash address range.*/
      SourcePtr += FLS_WORD_SIZE;
      ReadCount -= FLS_WORD_SIZE;
    }
    else
    {

      *(StatePtr->FlsReadBufferPtr) = *SourcePtr;
      (StatePtr->FlsReadBufferPtr)++;
      SourcePtr++;
      ReadCount--;
    }

  } while(((ReadCount)) > 0U);

  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
  type is required to access the FLASH address/target address which
  is defined as unsigned long. */
  /* Update the Read Address */
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
       is required to access the FLASH address/target address which is defined
       as unsigned long by AUTOSAR. */
  StatePtr->FlsReadAddress = (uint32)SourcePtr;

  /* Check for single bit or double bit error */


  if(Fls_lChkBitErrors() != 0U)
  {
    /* Report Runtime error code to DET */

    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)


    Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                            FLS_17_DMU_INSTANCE_ID,
                            FLS_17_DMU_SID_MAIN,
                            FLS_17_DMU_E_READ_FAILED);
    #endif
    /* Call to Fls_lErrorHandler local function */

    Fls_lErrorHandler(FLS_17_DMU_READ);
  }
  else
  {

    if(StatePtr->FlsReadLength == 0U)
    {

      /* Set Job Result to JOB OK if no warnings */
      LastJobResult = MEMIF_JOB_OK;
      /* 1. Clear the Job request */
      StatePtr->FlsJobType = FLS_17_DMU_NONE;

      /* 2. Update the global status variables */
      StatePtr->FlsJobResult = LastJobResult;


      if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)

      {

        Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_READ_JOB;
        /* FlsJobEndNotificationPtr should be called */
        (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
        Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
      }
    }
  }
}

/*******************************************************************************
** Traceability :[cover parentID={3C12F0A1-9B05-4de3-895F-F4268E9B4A9D}]      **
**                                                                            **
** Syntax : static void Fls_lMainCompare(void)                                **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : void                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the Compare operation during Cyclic                 **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainCompare(void)
{
  Fls_17_Dmu_StateType       *StatePtr;
  Fls_17_Dmu_LengthType      ReadCount;
  MemIf_JobResultType LastJobResult;
  uint8               *SourcePtr;
  Fls_17_Dmu_LengthType      MaxRead;
  uint32 BitChange;

  /************ Initialise Local variables ****************************/
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  LastJobResult = StatePtr->FlsJobResult;

  /* Get max read length according to the FLS mode */
  MaxRead = Fls_lGetReadModeLength();

  /* Check whether the given length is greater than MAX_READ */

  if(StatePtr->FlsReadLength > MaxRead)
  {


    /* Load Max Byte to read in one cycle */
    ReadCount = MaxRead;
    /* Decrement the count from the totalcount to read */
    StatePtr->FlsReadLength = StatePtr->FlsReadLength - ReadCount;
  }
  else
  {

    ReadCount = StatePtr->FlsReadLength;
    StatePtr->FlsReadLength = 0U;
  }

  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
         type is required to access the FLASH address/target address which
         is defined as unsigned long. */
  /* Obtain the address for the compare operation */
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
    is required to check the value of the address of data buffer alignment. */
  SourcePtr = (uint8 *)(StatePtr->FlsReadAddress);
  /**********************************************************************/
  /*Clear the ECC status bits by writing DMU_SF_ECCC.CLR with 11b to clear
             AERM bit*/
  BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;

  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
   the object types as the address of the register is being passed.*/
  FLS_17_DMU_DF1_SFR_WRITE(\
      (volatile uint32 *)&DMU_SF_ECCC.U, \
      BitChange);
  /*Clearing of AERM takes 2-3 cycles so NOP added*/
  NOP();
  NOP();
  NOP();


  do
  {
    /* Check if Address is word aligned */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
               type is required to access the FLASH address/target address which
               is defined as unsigned long. */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
    is required to access the FLASH address/target address which is defined
         as unsigned long by AUTOSAR. */

    if( (((uint32)SourcePtr & (FLS_WORD_SIZE - 1U)) == 0U) && \
        ((((uint32)(StatePtr->FlsReadBufferPtr) & (FLS_WORD_SIZE - 1U)) == 0U) && \
         (ReadCount >= FLS_WORD_SIZE)  )
      )
    {
      /* COMPARE THE FLASH DATA WITH THE BUFFER DATA (Word Compare) */
      /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
       the object types as the address of the register is being passed.*/

      if( *(uint32*)(StatePtr->FlsReadBufferPtr) != *(uint32*)SourcePtr )
      {


        LastJobResult = MEMIF_BLOCK_INCONSISTENT;
        /* No need to compare any more data */
        ReadCount = 0U;
      }
      else
      {

        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
        array indexing used for FLASH address calculation and for subsequent
        traversal.The access range is within the flash address range.*/
        StatePtr->FlsReadBufferPtr += FLS_WORD_SIZE;
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
        array indexing used for FLASH address calculation and for subsequent
        traversal.The access range is within the flash address range.*/
        SourcePtr += FLS_WORD_SIZE;
        ReadCount -= FLS_WORD_SIZE;
      }
    }
    else
    {
      /* COMPARE THE FLASH DATA WITH THE BUFFER DATA (Byte Compare)*/

      if( *(StatePtr->FlsReadBufferPtr) != *SourcePtr )
      {

        LastJobResult = MEMIF_BLOCK_INCONSISTENT;
        /* No need to compare any more data */
        ReadCount = 0U;

      }
      else
      {

        StatePtr->FlsReadBufferPtr++;
        SourcePtr++;
        ReadCount--;
      }
    }

  } while(ReadCount > 0U);

  /* Update the compare address */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
         type is required to access the FLASH address/target address which
         is defined as unsigned long. */
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
       is required to access the FLASH address/target address which is defined
       as unsigned long by AUTOSAR. */
  StatePtr->FlsReadAddress = (uint32)SourcePtr;

  /* Check if Non-correctable ECC error was present thus leading to failure */


  if(Fls_lChkBitErrors() != 0U)
  {
    /* Report Runtime error code to DET */
    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)


    Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                            FLS_17_DMU_INSTANCE_ID,
                            FLS_17_DMU_SID_MAIN,
                            FLS_17_DMU_E_COMPARE_FAILED);
    #endif
    /* Call to Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_17_DMU_COMPARE);
  }
  /* Check if block was inconsistent */


  else if(LastJobResult == MEMIF_BLOCK_INCONSISTENT)
  {
    /* Update the global status variables */
    StatePtr->FlsJobResult = LastJobResult;

    /* Clear the failed Job  */

    StatePtr->FlsJobType = FLS_17_DMU_NONE;

    /* Clear the errors status flags */
    BitChange = FLS_DMU_ERR_CLR;
    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
     the object types as the address of the register is being passed.*/
    FLS_17_DMU_DF1_SFR_WRITE( \
                                    (volatile uint32 *)&DMU_SF_CLRE.U, \
                                    BitChange);


    if(Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
    {
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_COMPARE_JOB;
      /* FlsJobErrorNotificationPtr should be called */

      (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
    }
  }
  /* No failures detected */
  else
  {
    /* Job completed */

    if ( StatePtr->FlsReadLength == 0U)
    {

      /* Update the result to JOB_OK if no warnings */
      LastJobResult = MEMIF_JOB_OK;

      /* 1. Update the Global Status variables */
      StatePtr->FlsJobResult = LastJobResult;
      /* 2. Clear the Job request */
      StatePtr->FlsJobType = FLS_17_DMU_NONE;


      if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)
      {
        Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_COMPARE_JOB;
        /* FlsJobEndNotificationPtr should be called */

        (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
        Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
      }

    }
    /* Job not yet completed */
    else
    {
      /* Avoid MISRA error */
    }
  }
}

/*******************************************************************************
** Traceability : [cover parentID={CD60BE4B-C8CF-47d3-96F3-176EB447E34B}]     **
**                                                                            **
** Syntax : static void Fls_lMainBlankCheck(void)                             **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : void                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the Blank Check operation during Cyclic             **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainBlankCheck(void)

{
  Fls_17_Dmu_StateType       *StatePtr;
  Fls_17_Dmu_LengthType      ReadCount;
  MemIf_JobResultType LastJobResult;
  uint8               *SourcePtr;
  Fls_17_Dmu_LengthType      MaxRead;
  uint32 BitChange;

  /************ Initialise Local variables ****************************/
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  LastJobResult = StatePtr->FlsJobResult;

  /* Get max read length according to the FLS mode */
  MaxRead = Fls_lGetReadModeLength();

  /* Check whether the given length is greater than MAX_READ */

  if(StatePtr->FlsReadLength > MaxRead)
  {
    /* Load Max Byte to read in one cycle */


    ReadCount = MaxRead;
    /* Decrement the count from the totalcount to read */
    StatePtr->FlsReadLength = StatePtr->FlsReadLength - ReadCount;
  }
  else
  {

    ReadCount = StatePtr->FlsReadLength;
    StatePtr->FlsReadLength = 0U;
  }
  /* Obtain the address for the Blank Check operation */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
         type is required to access the FLASH address/target address which
         is defined as unsigned long. */
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
       is required to access the FLASH address/target address which is defined
       as unsigned long by AUTOSAR. */
  SourcePtr = (uint8 *)(StatePtr->FlsReadAddress);
  /**********************************************************************/

  /*Clear the ECC status bits by writing DMU_SF_ECCC.CLR with 11b to clear
             AERM bit*/
  BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;

  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
  the object types as the address of the register is being passed.
  MISRA2012_RULE_11_1_JUSTIFICATION: Pointer cast is required to match
  the object types.*/
  FLS_17_DMU_DF1_SFR_WRITE(\
      (volatile uint32 *)&DMU_SF_ECCC.U, \
      BitChange);
  /*Clearing of AERM bits takes 2-3 cyles so added NOP*/
  NOP();
  NOP();
  NOP();
  do
  {
    /* Check if Address is word aligned */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
              type is required to access the FLASH address/target address which
              is defined as unsigned long. */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
     is required to access the FLASH address/target address which is defined
     as unsigned long by AUTOSAR. */

    if((((uint32)SourcePtr & (FLS_WORD_SIZE - 1U)) == 0U) &&
        (ReadCount >= FLS_WORD_SIZE))
    {
      /* Check if the flash data is in erased state? (Word Compare)*/
      /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
       the object types as the address of the register is being passed.*/

      if(FLS_17_DMU_DEFAULT_ERASEVALUE != *(uint32*)SourcePtr )
      {


        LastJobResult = MEMIF_BLOCK_INCONSISTENT;
        /* No need to compare any more data */
        ReadCount = 0U;
      }
      else
      {

        /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
         is required to access the FLASH address/target address which is defined
          as unsigned long by AUTOSAR. */
        /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
        array indexing used for FLASH address calculation and for subsequent
        traversal.The access range is within the flash address range.
        */

        SourcePtr += FLS_WORD_SIZE;
        ReadCount -= FLS_WORD_SIZE;
      }
    }
    else
    {
      /* Check if the flash data is in erased state? (Byte Compare)*/


      if( FLS_17_DMU_DEFAULT_ERASEVALUE != *SourcePtr )
      {
        LastJobResult = MEMIF_BLOCK_INCONSISTENT;
        /* No need to compare any more data */
        ReadCount = 0U;

      }
      else
      {

        SourcePtr++;
        ReadCount--;
      }
    }

  } while(ReadCount > 0U);

  /* Update the compare address */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
         type is required to access the FLASH address/target address which
         is defined as unsigned long. */
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from unsigned long to pointer
       is required to access the FLASH address/target address which is defined
       as unsigned long by AUTOSAR. */
  StatePtr->FlsReadAddress = (uint32)SourcePtr;



  /* Check if Non-correctable ECC error was present thus leading to failure */
  if(Fls_lChkBitErrors() != 0U)
  {

    /* Blank Check Job fails due to hardware error */
    /* Report Runtime error code to DET */
    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
    Det_ReportRuntimeError((uint16)FLS_17_DMU_MODULE_ID,
                           FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_MAIN,
                           FLS_17_DMU_E_BLANKCHECK_FAILED);
    #endif
    /* Call to Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_17_DMU_BLANKCHECK);
  }


  /* Check if block was inconsistent */
  else if(LastJobResult == MEMIF_BLOCK_INCONSISTENT)
  {


    /* Update the global status variables */
    StatePtr->FlsJobResult = LastJobResult;

    /* Clear the failed Job */
    StatePtr->FlsJobType = FLS_17_DMU_NONE;

    /* Clear the errors status flags */
    BitChange = FLS_DMU_ERR_CLR;
    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
     the object types as the address of the register is being passed.*/
    FLS_17_DMU_DF1_SFR_WRITE( \
                                    (volatile uint32 *)&DMU_SF_CLRE.U, \
                                    BitChange);


    if(Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
    {
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_BLANKCHECK_JOB;
      /* FlsJobErrorNotificationPtr should be called */

      (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
    }

  }
  /* No failures detected */
  else
  {
    /* Job completed */

    if ( StatePtr->FlsReadLength == 0U)
    {

      /* Update the result to JOB_OK if no warnings */
      LastJobResult = MEMIF_JOB_OK;

      /* 1. Update the Global Status variables */
      StatePtr->FlsJobResult = LastJobResult;

      /* 2. Clear the Job request */
      StatePtr->FlsJobType = FLS_17_DMU_NONE;



      if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)

      {
        Fls_ConfigPtr->FlsStateVarPtr->NotifCaller =
          FLS_17_DMU_BLANKCHECK_JOB;

        (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
        Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
      }

    }
    /* Job not yet completed */
    else
    {
      /* Avoid MISRA error */
    }
  }
}
/*******************************************************************************
** Traceability : [cover parentID={EF96175F-F994-4d9c-BD93-5CF8463F5CE5}]     **
**                                                                            **
** Syntax : static void Fls_lMainWrite(void)                                  **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : void                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the Write operation during Cyclic                   **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainWrite(void)

{
  Fls_17_Dmu_StateType       *StatePtr;
  MemIf_JobResultType LastJobResult;
  uint32     PhysicalAddress;
  boolean             Error;
  uint8               PageLength;
  uint32     BitChange;

  /******************* Initialise local variables ********************/
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  /* Setting the PhysicalAddress to uchached DF1 start address for Command cycle
    execution */

  PhysicalAddress = FLS_17_DMU_BASE_ADDRESS;

  /* Check for operational error */

  if(Fls_lChkOperError() != 0U)
  {
    /* FLS105: Write Job fails due to hardware error */
    /* Report Runtime error code to DET */

    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)


    Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                            FLS_17_DMU_INSTANCE_ID,
                            FLS_17_DMU_SID_MAIN,
                            FLS_17_DMU_E_WRITE_FAILED);
    #endif
    Error = (boolean)TRUE;
  }


  /* Check for Program verification error */
  #if(FLS_17_DMU_IFX_FEE_USED == STD_OFF)
  #if(FLS_17_DMU_VER_ERROR_CHECK == STD_ON)


  else if((boolean)TRUE == Fls_lPverChk())
  {
    Error = (boolean)TRUE;
    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)



    Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                            FLS_17_DMU_INSTANCE_ID,
                            FLS_17_DMU_SID_MAIN,
                            FLS_17_DMU_E_WRITE_FAILED);
    #endif
  }
  #endif  /* FLS_VER_ERROR_CHECK == STD_ON */
  #endif  /* FLS_17_DMU_IFX_FEE_USED == STD_OFF */
  else
  {

    if( Fls_lGetWriteMode() == FLS_17_DMU_PAGE_WRITE)
    {

      PageLength = FLS_17_DMU_PAGE_SIZE;
    }
    else
    {

      PageLength = FLS_17_DMU_BURST_PAGE_SIZE;
    }


    #if (FLS_17_DMU_IFX_FEE_USED == STD_OFF)
    #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
    (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
    /* Check for DFLASHx Page content equal to Source value */

    Error = Fls_lCheckWrittenPage((uint32)PageLength);
    #else
    Error = (boolean)FALSE;
    #endif /* FLS_17_DMU_DEV_ERROR_DETECT == STD_ON */
    #else
    Error = (boolean)FALSE;
    #endif /* FLS_17_DMU_IFX_FEE_USED == STD_OFF */

    /* PageStartAddress is incremented by PageLength bytes */
    StatePtr->FlsWriteAddress += PageLength;
    /* length is decremented by PageLength */
    StatePtr->FlsWriteLength -= PageLength;

    /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
     array indexing used for FLASH address calculation and for subsequent
       traversal.The access range is within the flash address range.*/
    StatePtr->FlsWriteBufferPtr = (StatePtr->FlsWriteBufferPtr + \
                                   PageLength);

  }


  if(Error == (boolean)FALSE)
  {


    /* Check for Program verification error */
    #if(FLS_17_DMU_IFX_FEE_USED == STD_ON)
    #if(FLS_17_DMU_VER_ERROR_CHECK == STD_ON)

    if ((boolean)TRUE == Fls_lPverChk())
    {
      /* update FlsPver to be used in CompareWordsSync */
      StatePtr->FlsPver = 1U;
    }
    #endif  /* FLS_VER_ERROR_CHECK == STD_ON */
    #endif  /* FLS_17_DMU_IFX_FEE_USED == STD_ON */

    /* Check for Flash write Job is finished completely  */

    if(StatePtr->FlsWriteLength == 0U)
    {
      #if(FLS_17_DMU_IFX_FEE_USED == STD_ON)

      if( StatePtr->FlsPver == 0U)
      #endif
      {


        /* Indicate Job successfully completed if no warnings seen till now */
        LastJobResult = MEMIF_JOB_OK;
        /* 1. Update the global status variables */
        StatePtr->FlsJobResult = LastJobResult;
        /* 2. Clear the Write Job */
        StatePtr->FlsJobType = FLS_17_DMU_NONE;
        /* 3. Clear the Write Job Started Status bit */
        StatePtr->JobStarted.Write = 0U;

        /* Clear the errors status flags */
        BitChange = FLS_DMU_ERR_CLR;
        /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
         the object types as the address of the register is being passed.*/
        FLS_17_DMU_DF1_SFR_WRITE( \
                                        (volatile uint32 *)&DMU_SF_CLRE.U, \
                                        BitChange);

        if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)
        {

          Fls_ConfigPtr->FlsStateVarPtr->NotifCaller =
            FLS_17_DMU_WRITE_JOB;
          /* FlsJobEndNotificationPtr should be called */

          (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
          Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
        }
      }
      #if(FLS_17_DMU_IFX_FEE_USED == STD_ON)
      else
      {
        #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
        Det_ReportRuntimeError( (uint16)FLS_17_DMU_MODULE_ID,
                                FLS_17_DMU_INSTANCE_ID,
                                FLS_17_DMU_SID_MAIN,
                                FLS_17_DMU_E_WRITE_FAILED);
        #endif

        /* Update the global status variables */
        StatePtr->FlsJobResult = MEMIF_JOB_FAILED;
        /* 2. Clear the Write Job */
        StatePtr->FlsJobType = FLS_17_DMU_NONE;
        /* 3. Clear the Write Job Started Status bit */
        StatePtr->JobStarted.Write = 0U;

        /* Clear the errors status flags */
        BitChange = FLS_DMU_ERR_CLR;
        /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
         the object types as the address of the register is being passed.*/
        FLS_17_DMU_DF1_SFR_WRITE( \
                                        (volatile uint32 *)&DMU_SF_CLRE.U, \
                                        BitChange);
        StatePtr->FlsPver = (uint8)0x00;


        if(Fls_ConfigPtr->FlsProgVerifyErrNotifPtr != NULL_PTR)
        {
          Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_WRITE_JOB;
          /* Fls PVER Notification should be called */

          (Fls_ConfigPtr->FlsProgVerifyErrNotifPtr)();
          Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
        }
      }
      #endif
    }
    else /*Write Operation not finished, writeLength not zero*/
    {
      #if (FLS_17_DMU_IFX_FEE_USED == STD_OFF)
      #if  (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON ) || \
      (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
      /* CHECK FOR DFLASHx PAGE IS ERASED */

      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
                 type is required to access the FLASH address/target address which
                     is defined as unsigned long. */
      /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
            is required to store the FLASH address/target address in state var
                  structure to perform easy arithmetic operations. */
      if(Fls_lPageEraseCheck((uint32 *)(StatePtr->FlsWriteAddress),
                             StatePtr->FlsWriteLength, FLS_17_DMU_SID_MAIN) != E_OK)
      {
        Error = (boolean)TRUE;

        Fls_lErrorHandler(FLS_17_DMU_WRITE);
      }
      /* Check needed only when DET is STD_ON */


      if(Error == (boolean)FALSE)
      #endif /* FLS_17_DMU_DEV_ERROR_DETECT == STD_ON */
      #endif /* FLS_17_DMU_IFX_FEE_USED == STD_OFF */
      {
        /* Start Write operation */

        Fls_lMainWriteJobStart(PhysicalAddress);
      }
    }
  }
  else
  {

    /* Call to Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_17_DMU_WRITE);
  }

}/* end of Fls_lMainWrite */

/*******************************************************************************
** Traceability : [cover parentID={DA20ED82-A382-4935-9DCA-2CB7DB807EFF}]     **
**                                                                            **
** Syntax : static void Fls_lMainWriteJobStart(const uint32 PhysicalAddress)  **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : Physical Address - Physical address for Write            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the Write operation during Cyclic                   **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainWriteJobStart(const uint32 PhysicalAddress)
{
  Fls_17_Dmu_StateType   *StatePtr;
  uint32                  SeqErr;
  uint8                   WriteMode;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  /* Mark that the Job has been started */
  StatePtr->JobStarted.Write = 1U;
  /* Obtain the write mode (Page or Burst) */
  WriteMode = Fls_lGetWriteMode();


  Fls_lClearStatusCmdCycle();

  /************* Call Write command sequence *************/
  Fls_lCallWriteCommand(PhysicalAddress, StatePtr, WriteMode);

  SeqErr = Fls_lChkSeqError();

  /* Check for Sequence error bit */

  if(SeqErr != 0U)
  {
    /* Report Runtime error code to DET */



    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
    Det_ReportRuntimeError((uint16)FLS_17_DMU_MODULE_ID,
                           FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_MAIN,
                           FLS_17_DMU_E_WRITE_FAILED);
    #endif
    /* Call to Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_17_DMU_WRITE);
  }
  /* Check for Command Cycle Timeout Error */

  else if (StatePtr->FlsTimeoutErr == FLS_17_DMU_WRITE)
  {
    #if (FLS_17_DMU_RUNTIME_ERROR_DETECT == STD_ON)
    Det_ReportRuntimeError((uint16)FLS_17_DMU_MODULE_ID,
                           FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_MAIN,
                           FLS_17_DMU_E_WRITE_FAILED);
    #endif

    /* Call to Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_17_DMU_WRITE);
  }
  else
  {
    /* dummy else */
  }
}



/*******************************************************************************
** Traceability   : [cover parentID={08821C81-62AE-44a8-A9FC-E8F21739A886}]   **
**                                                                            **
** Syntax : static void Fls_lErrorHandler(const uint8 JobType)                **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : JobType                                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine is called when error occurred during            **
**               flash operations                                             **
*******************************************************************************/
static void Fls_lErrorHandler(const uint8 JobType)
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint32 BitChange;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;


  if(JobType == FLS_17_DMU_ERASE)
  {

    StatePtr->JobStarted.Erase = 0U;
  }

  else if(JobType == FLS_17_DMU_WRITE)
  {

    StatePtr->JobStarted.Write = 0U;
  }
  else
  {
    /* Avoid MISRA 60 */
  }

  /* Clear the failed Job  */

  if(StatePtr->FlsJobType == JobType)
  {

    StatePtr->FlsJobType = FLS_17_DMU_NONE;
  }

  /* Update the global status variables */
  StatePtr->FlsJobResult = MEMIF_JOB_FAILED;

  /* Clear the errors status flags */
  BitChange = FLS_DMU_ERR_CLR;
  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
   the object types as the address of the register is being passed.*/
  FLS_17_DMU_DF1_SFR_WRITE( \
                                  (volatile uint32 *)&DMU_SF_CLRE.U, \
                                  BitChange);


  if(Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
  {

    Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = JobType;
    /* FlsJobErrorNotificationPtr should be called */
    (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();
    Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
  }
}

#if (FLS_17_DMU_USE_ERASESUSPEND == STD_ON)
/*******************************************************************************
** Traceability :[cover parentID={4A7C5E8C-7A6F-4153-8B12-08A01C465B1D}]      **
**                                                                            **
** Syntax: LOCAL_INLINE boolean Fls_lSpndTimeout(const uint32 TimeOutCount)   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : TimeOutCount - Value of the Timeout count                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : boolean                                                  **
**                                                                            **
** Description : This routine checks if erase suspend error or timeout error  **
**               occured                                                      **
*******************************************************************************/
LOCAL_INLINE boolean Fls_lSpndTimeout(const uint32 TimeOutCount)
{
  boolean RetVal;
  uint32 BitChange;


  if (DMU_SF_SUSPEND.B.ERR == 1U) /*Suspend Error*/
  {

    #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_SUSPENDERASE,
                           FLS_17_DMU_SE_SUSPNDERASE_FAIL);
    #endif
    /* Clear Suspend Error status */

    BitChange = DMU_SF_SUSPEND.U | SUSPEND_CLR_OFF;
    DMU_SF_SUSPEND.U = BitChange;

    RetVal = (boolean)TRUE;
  }

  else if (TimeOutCount == 0U) /*Timeout */
  {
    #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

    Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID,
                           FLS_17_DMU_SID_SUSPENDERASE,
                           FLS_17_DMU_SE_HW_TIMEOUT);
    #endif
    RetVal = (boolean)TRUE;
  }
  else
  {
    RetVal = (boolean)FALSE;
  }
  return (RetVal);
}
#endif

/*******************************************************************************
** Traceability : [cover parentID={D33AFD18-0DFE-461f-9059-2CA38024EFA0}]     **
**                                                                            **
** Syntax: LOCAL_INLINE boolean Fls_lPverChk(void)                            **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : boolean                                                  **
**                                                                            **
** Description : This routine checks if PVER error occured                    **
*******************************************************************************/
LOCAL_INLINE boolean Fls_lPverChk(void)
{
  uint32 TempFSR;
  boolean RetVal;

  TempFSR = (uint32)DMU_SF_ERRSR.U;


  if ((((TempFSR >> IFX_DMU_SF_ERRSR_PVER_OFF)) &
       IFX_DMU_SF_ERRSR_PVER_MSK) == 1U)
  {

    RetVal = (boolean)TRUE;
  }
  else
  {

    RetVal = (boolean)FALSE;
  }
  return (RetVal);
}

#if(FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
(FLS_17_DMU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID={92A72106-A5C8-4c69-A1F0-7D88AB31130E}]     **
**                                                                            **
** Syntax: LOCAL_INLINE uint8 Fls_lBusyDET_Read                               **
**                                ( const Fls_17_Dmu_StateType*const StatePtr)**
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StatePtr : FLS Global variable structure                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine detects if the new Read job can be accepted     **
*******************************************************************************/
LOCAL_INLINE uint8 Fls_lBusyDET_Read(const
                                     Fls_17_Dmu_StateType *const StatePtr )
{
  uint8 ErrorFlag;

  uint8 JobType;
  JobType = StatePtr->FlsJobType;
  ErrorFlag = 0U;

  /* No other job has been accepted */

  if(JobType != FLS_17_DMU_NONE)
  {

    Fls_lReportError(
      FLS_17_DMU_SID_READ,
      FLS_17_DMU_E_BUSY);/* Report to DET */
    ErrorFlag = 1U;
  }

  return(ErrorFlag);
}

#if (FLS_17_DMU_COMPARE_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID={250C5940-F4C3-47d7-985C-9D0B6AC86400}]     **
**                                                                            **
** Syntax: LOCAL_INLINE uint8 Fls_lBusyDET_Compare                            **
**                              ( const Fls_17_Dmu_StateType*const StatePtr)  **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StatePtr : FLS Global variable structure                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine detects if the new Compare job can be accepted  **
*******************************************************************************/
LOCAL_INLINE uint8 Fls_lBusyDET_Compare(
  const Fls_17_Dmu_StateType *const StatePtr )
{
  uint8 ErrorFlag;
  uint8 JobType;
  JobType = StatePtr->FlsJobType;
  ErrorFlag = 0U;

  /* No other job has been accepted */

  if(JobType != FLS_17_DMU_NONE)
  {

    Fls_lReportError(
      FLS_17_DMU_SID_COMPARE,
      FLS_17_DMU_E_BUSY);/* Report to DET */
    ErrorFlag = 1U;
  }

  return(ErrorFlag);
}
#endif

/*******************************************************************************
** Traceability     : [cover parentID={7C7AAF5E-BC04-4553-A68E-49C17D982385}] **
**                                                                            **
** Syntax: LOCAL_INLINE uint8 Fls_lBusyDET_Write                              **
**                            ( const Fls_17_Dmu_StateType*const StatePtr )   **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StatePtr : FLS Global variable structure                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine detects if the new Write job can be accepted    **
*******************************************************************************/
LOCAL_INLINE uint8 Fls_lBusyDET_Write(const Fls_17_Dmu_StateType *const
                                      StatePtr)
{
  uint8 ErrorFlag;
  uint8 JobType;
  JobType = StatePtr->FlsJobType;
  ErrorFlag = 0U;

  /* No other job has been accepted */

  if(JobType != FLS_17_DMU_NONE)
  {

    Fls_lReportError(
      FLS_17_DMU_SID_WRITE,
      FLS_17_DMU_E_BUSY);/* Report to DET */
    ErrorFlag = 1U;
  }

  return(ErrorFlag);
}

/*******************************************************************************
** Traceability :[cover parentID={9B354613-0325-464d-B420-5B6E956717DF}]      **
**                                                                            **
** Syntax: LOCAL_INLINE uint8 Fls_lBusyDET_Erase                              **
**                                ( const Fls_17_Dmu_StateType*const StatePtr)**
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StatePtr : FLS Global variable structure                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine detects if the new Erase job can be accepted    **
*******************************************************************************/
LOCAL_INLINE uint8 Fls_lBusyDET_Erase(const Fls_17_Dmu_StateType *const
                                      StatePtr)
{
  uint8 ErrorFlag;

  uint8 JobType;
  JobType = StatePtr->FlsJobType;
  ErrorFlag = 0U;

  /* No other job has been accepted */

  if(JobType != FLS_17_DMU_NONE)
  {

    Fls_lReportError(
      FLS_17_DMU_SID_ERASE,
      FLS_17_DMU_E_BUSY);/* Report to DET */
    ErrorFlag = 1U;
  }

  return(ErrorFlag);
}

/*******************************************************************************
** Traceability :     [cover parentID={744CAAD3-0ED4-46d3-AABB-8426E922A937}] **
**                                                                            **
** Syntax: static uint8 Fls_lUninitDET( const uint8 ServiceID )               **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : ServiceID - Service ID of the calling function           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine performs the UNINIT DET check                   **
*******************************************************************************/
static uint8 Fls_lUninitDET( const uint8 ServiceID )
{
  uint8 ErrorFlag;

  ErrorFlag = 0U;

  if((Fls_ConfigPtr == NULL_PTR) || (FLS_INITIALIZED != Fls_17_Dmu_InitStatus))
  {

    Fls_lReportError(ServiceID,
                     FLS_17_DMU_E_UNINIT);/* Report to DET */

    ErrorFlag = 1U;
  }

  return (ErrorFlag);
}

/*******************************************************************************
** Traceability :[cover parentID={98064BA1-6260-461c-8DA6-5730095C485C}]      **
**                                                                            **
** Syntax: static uint8 Fls_lTimeOutDET( const uint8 ServiceID )              **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : ServiceID - Service ID of the calling function           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine performs the TIMEOUT DET check                  **
*******************************************************************************/
static uint8 Fls_lTimeOutDET(const uint8 ServiceID)
{
  Fls_17_Dmu_StateType  *StatePtr;
  uint8 ErrorFlag;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  ErrorFlag = 0U;


  if (StatePtr->FlsTimeoutControl != 0U)
  {

    if(StatePtr->JobStarted.Erase != 0U)
    {

      if(StatePtr->FlsEraseTimeoutCycleCount == 0U)
      {

        ErrorFlag = 1U;
        StatePtr->JobStarted.Erase = 0U;
      }
      else
      {

        StatePtr->FlsEraseTimeoutCycleCount--;
      }
    }

    if(StatePtr->JobStarted.Write != 0U)
    {

      if(StatePtr->FlsWriteTimeoutCycleCount == 0U)
      {

        ErrorFlag = 1U;
        StatePtr->JobStarted.Write = 0U;
      }
      else
      {

        StatePtr->FlsWriteTimeoutCycleCount--;
      }
    }

    if(ErrorFlag == 1U)
    {
        /* Report timeout DET*/

        Fls_lReportError(ServiceID,
                                 FLS_17_DMU_E_TIMEOUT);/* Report to DET */

      /* Update the global status variables */

      StatePtr->FlsJobResult = MEMIF_JOB_FAILED;

      /*Error notification*/

      if(Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
      {

        Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = StatePtr->FlsJobType;

        /* FlsJobErrorNotificationPtr should be called */
        (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();

        Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_17_DMU_NO_JOB;
      }

      /* Clear the Job to make the status idle*/

      StatePtr->FlsJobType = FLS_17_DMU_NONE;

    }
  }

  return ErrorFlag;
}

#if (FLS_17_DMU_IFX_FEE_USED == STD_OFF)
/*******************************************************************************
** Traceability : [cover parentID={0AF7065F-764A-4500-8868-D525B020BE0A}]     **
**                                                                            **
** Syntax: LOCAL_INLINE boolean Fls_lCheckWrittenPage(const uint32 PageLength)**
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : PageLength                                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : TRUE - programing error , FALSE - No programming error   **
**                                                                            **
** Description : Checks if the page was written without errors                **
*******************************************************************************/
LOCAL_INLINE boolean Fls_lCheckWrittenPage(const uint32 PageLength)
{
  const Fls_17_Dmu_StateType   *StatePtr;
  const uint32          *PageStartAddressPtr;
  const uint32    *SourcePtr;
  uint32          Count;
  uint32 BitChange;
  boolean         Error;

  Count = 0U;
  Error = (boolean)FALSE;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
   the object types as the address of the register is being passed.*/
  SourcePtr = (const uint32 *)(StatePtr->FlsWriteBufferPtr);
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
         type is required to access the FLASH address/target address which
         is defined as unsigned long. */
  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
      is required to store the FLASH address/target address in state var
      structure to perform easy arithmetic operations. */
  PageStartAddressPtr = (uint32 *)(StatePtr->FlsWriteAddress);

  /*Clear the ECC status bits by writing DMU_SF_ECCC.CLR with 11b to clear
                   AERM bit*/
  BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;

  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
   the object types as the address of the register is being passed.*/
  FLS_17_DMU_DF1_SFR_WRITE(\
      (volatile uint32 *)&DMU_SF_ECCC.U, \
      BitChange);

  /*Clearing of AERM bit takes 2-3 cycles so added NOP*/
  NOP();
  NOP();
  NOP();

  do
  {

    if(*(PageStartAddressPtr) == *(SourcePtr))
    {

      Count++;

      PageStartAddressPtr++;

      SourcePtr++;
    }
    else
    {
      /*  If the block has been not completely reprogrammed  */
      /*         after Writing a Flash block.                       */
      #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
      (FLS_17_DMU_SAFETY_ENABLE == STD_ON)


      Fls_lReportError(FLS_17_DMU_SID_MAIN,
                       FLS_17_DMU_E_VERIFY_WRITE_FAILED);/* Report to DET */
      #endif
      /* Call to Fls_lErrorHandler local function */
      Error = (boolean)TRUE;
      /*Nothing more to compare */
      Count = (PageLength / FLS_WORD_SIZE);
    }
  }

  while(Count < (PageLength / FLS_WORD_SIZE));

  if(Error == (boolean)FALSE)
  {
    /* Check for Non-correctable ECC errors during the above check */

    if(Fls_lChkBitErrors() != 0U)
    {
      /* Report to DET */
      #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
      (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

      Fls_lReportError(FLS_17_DMU_SID_MAIN,
                       FLS_17_DMU_E_VERIFY_WRITE_FAILED);
      #endif
      Error = (boolean)TRUE;
    }
  }
  return Error;
}
#endif

/*******************************************************************************
** Traceability : [cover parentID={826D3BF0-AF5D-4c14-B1FD-99D81BCB4AB5}]     **
**                                                                            **
** Syntax: LOCAL_INLINE void Fls_lCalculateWriteTimeoutCount(void)            **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Calculates the write timeout count in terms of number of     **
**               main function calls.                                         **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Fls_lCalculateWriteTimeoutCount(void)
{
  Fls_17_Dmu_StateType   *StatePtr;
  uint32          Length;
  uint32          BurstCount;
  uint32          PageWriteCount;
  uint32          TotalWriteCycles;
  uint32          BytesToBrstAlign;

  TotalWriteCycles = 0U;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  Length = StatePtr->FlsWriteLength;

  /* Check burst-alignement. Result is zero if address is burst aligned */
  BytesToBrstAlign = (StatePtr->FlsWriteAddress) &
                     (FLS_17_DMU_BURST_PAGE_SIZE - 1U);

  /* Is the value of length greater than the PAGE Length ? */
  if(Length > FLS_17_DMU_PAGE_SIZE)
  {
    /*Check If the write address is aligned to burst size of 32 and length is
     less than or equal to burst size OR if the write address not burst aligned
     and length is less than the burst size*/
    if(((BytesToBrstAlign != 0U) && (Length <= FLS_17_DMU_BURST_PAGE_SIZE))
      ||(Length < FLS_17_DMU_BURST_PAGE_SIZE))
    {
      /*Calculate the required number of page write cycles */
      PageWriteCount =  (Length >> FLS_17_DMU_PAGE_SHIFT);
      TotalWriteCycles  = PageWriteCount;
    }
    /*Length is always greater than burst size */
    else if(BytesToBrstAlign != 0U)
    {
      /* Reduce the length by number of bytes required for address
      burst alignment */
      Length = Length - (FLS_17_DMU_BURST_PAGE_SIZE - BytesToBrstAlign);

      /*Calculate the number of burst cycles needed*/
      BurstCount = Length >> FLS_17_DMU_BURST_PAGE_SHIFT;
      /*Caclulate the number of page write command cycles */
      PageWriteCount = ((Length & (FLS_17_DMU_BURST_PAGE_SIZE - 1U))+
      (FLS_17_DMU_BURST_PAGE_SIZE - BytesToBrstAlign)) >> FLS_17_DMU_PAGE_SHIFT;

      TotalWriteCycles  = BurstCount + PageWriteCount;

    }
    /* Address is burst aligned and length is greater than or equal to 32 */
    else
    {
      /*Calculate the number of burst cycles needed*/
      BurstCount = Length >> FLS_17_DMU_BURST_PAGE_SHIFT;

      /*The remaining will be written page wise*/
      PageWriteCount = (Length & (FLS_17_DMU_BURST_PAGE_SIZE - 1U))
                       >> FLS_17_DMU_PAGE_SHIFT;

      TotalWriteCycles  = BurstCount + PageWriteCount;
    }
  }

  /* Update the time out count in proportion to the number of write
  command cycles if call cycle time is less than the write time for one burst*/
  if(Fls_ConfigPtr->FlsCallCycle < FLS_17_DMU_WRITE_TIME)
  {
    TotalWriteCycles =
    (((TotalWriteCycles * FLS_17_DMU_WRITE_TIME)/Fls_ConfigPtr->FlsCallCycle)+1U);
  }

  /* Extra count of two added since error checking will be done in the
   next call of the main function cycle. One more additional cycle will
   ensure that the checks are done and status are updated. */
  TotalWriteCycles += FLS_17_DMU_MIN_MAINFUNC_CALL;

  StatePtr->FlsWriteTimeoutCycleCount = TotalWriteCycles;
}

#if (FLS_17_DMU_IFX_FEE_USED == STD_OFF)
/*******************************************************************************
** Traceability :  [cover parentID={02694C60-A685-40e9-A517-AEACCDE8F330}]    **
**                                                                            **
** Syntax: LOCAL_INLINE Std_ReturnType Fls_lPageEraseCheck(                   **
**                                            uint32* const AddrCheckPtr,     **
**                                             const uint32  Length,          **
**                                            const uint8   ServiceID)        **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : AddrCheckPtr - address of the page, Length - page length **
**                   ServiceID - Service ID of the API for the DET            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - page was erased correctly                         **
**                   E_NOT_OK - Page was not erased correctly                 **
**                                                                            **
** Description : Checks if the page was erased correctly                      **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Fls_lPageEraseCheck(uint32 *const AddrCheckPtr,
    const uint32 Length,
    const uint8 ServiceID)
/* [cover parentID={AA2584EF-BA3C-44d2-A181-1597C23D5A0F}][/cover] */
{
  Std_ReturnType  RetVal;
  uint8           Loop;
  uint8           PageLength;
  uint8       IndexAddrCheckPtr;
  uint32 BitChange;

  RetVal = E_OK;

  Loop = 0U;

  IndexAddrCheckPtr = 0U;


  /*Clear the ECC status bits by writing DMU_SF_ECCC.CLR with 11b to clear
  AERM bit*/
  BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;

  /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
     the object types as the address of the register is being passed.*/
  FLS_17_DMU_DF1_SFR_WRITE((volatile uint32 *)&DMU_SF_ECCC.U,\
        BitChange);

  if( (Length <= (FLS_17_DMU_BURST_PAGE_SIZE - FLS_17_DMU_PAGE_SIZE)) ||
      /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
      is required to check the value of the address of data buffer alignment. */
      /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
          type is required to access the FLASH address/target address which
             is defined as unsigned long. */
      ((((uint32)AddrCheckPtr) & (FLS_17_DMU_BURST_PAGE_SIZE - 1U)) != 0U) )
  {

    PageLength = FLS_17_DMU_PAGE_SIZE;
  }
  else
  {

    PageLength = FLS_17_DMU_BURST_PAGE_SIZE;
  }

  do
  {
    /* MISRA2012_RULE_18_4_JUSTIFICATION: Pointer arithmetic other than
      array indexing used for FLASH address calculation and for subsequent
            traversal.The access range is within the flash address range.*/

    if((*(AddrCheckPtr + IndexAddrCheckPtr)) == 0U)
    {

      Loop++;
      IndexAddrCheckPtr++;
    }
    else
    {
      /*  Before Writing if block is not completely erased.*/
      /* Call to Fls_lErrorHandler local function */

      #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
      (FLS_17_DMU_SAFETY_ENABLE == STD_ON)


      Fls_lReportError(ServiceID,
                       FLS_17_DMU_E_VERIFY_ERASE_FAILED);/* Report to DET */
      #endif

      RetVal = E_NOT_OK; /* Return from FSunction */
    }
  } while((RetVal == E_OK) && (Loop < (PageLength / FLS_WORD_SIZE)));


  if(RetVal == E_OK)
  {
    /* Check for Non-correctable ECC errors during the above check */

    if(Fls_lChkBitErrors() != 0U)
    {
      /* Report to DET */

      #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON) || \
            (FLS_17_DMU_SAFETY_ENABLE == STD_ON)

      Fls_lReportError(ServiceID,
                         FLS_17_DMU_E_VERIFY_ERASE_FAILED);
      #endif
      RetVal = E_NOT_OK;
    }
  }

  return RetVal;
}
#endif

/*******************************************************************************
** Traceability :[cover parentID={F674110C-7572-4925-A85C-D7FBAA456FB0}]      **
**                                                                            **
** Syntax : LOCAL_INLINE Std_ReturnType Fls_lCheckEraseDet(                   **
**                             const Fls_17_Dmu_AddressType TargetAddress,    **
**                                  const  Fls_LengthType Length)             **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  TargetAddress and Length                                **
**                                                                            **
** Parameters (out): E_OK: No development Error detected                      **
**                   E_NOT_OK: development Error is detected                  **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description : This routine checks for development error for                **
**               Fls_17_Dmu_Erase API                                         **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Fls_lCheckEraseDet(
  const Fls_17_Dmu_AddressType TargetAddress,
  const Fls_17_Dmu_LengthType Length)
{
  const Fls_17_Dmu_StateType*   StatePtr;
  Std_ReturnType   ReturnValue;

  /* API called before initialization? */

  if(Fls_lUninitDET(FLS_17_DMU_SID_ERASE) == 1U)
  {


    ReturnValue = E_NOT_OK;
  }

  /* Checking whether given TargetAddress is valid or not */

  else if(((uint32)TargetAddress >= FLS_17_DMU_TOTAL_SIZE) ||
          ((TargetAddress & FLS_MOD4K_MASK ) != 0U))
  {
    /* Report to DET */




    Fls_lReportError(FLS_17_DMU_SID_ERASE, FLS_17_DMU_E_PARAM_ADDRESS);


    ReturnValue = E_NOT_OK;
  }

  /* Checking whether given Length is valid or not */


  else if((!(( Length >= FLS_ONE_VALUE) &&
             ( Length <= (FLS_17_DMU_TOTAL_SIZE - TargetAddress )))) ||
          ((Length & FLS_MOD4K_MASK) != 0U))
  {
    /* Report to DET */


    Fls_lReportError(FLS_17_DMU_SID_ERASE, FLS_17_DMU_E_PARAM_LENGTH);

    ReturnValue = E_NOT_OK;
  }
  else
  {
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;


    if(Fls_lBusyDET_Erase((const Fls_17_Dmu_StateType *)StatePtr) == 1U)
    {

      ReturnValue = E_NOT_OK;
    }
    else
    {

      ReturnValue = E_OK;
    }
  }

  return ReturnValue;
}

/*******************************************************************************
** Traceability   : [cover parentID={009ADDB2-72CC-462a-953E-CB33EFC755D0}]   **
**                                                                            **
** Syntax : LOCAL_INLINE Std_ReturnType Fls_lCheckWriteDet(                   **
**                                      const Fls_AddressType TargetAddress,  **
**                                       const uint8 *const SourceAddressPtr, **
**                                     const Fls_LengthType Length)           **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  TargetAddress, SourceAddressPtr and Length              **
**                                                                            **
** Parameters (out): E_OK: No development Error detected                      **
**                   E_NOT_OK: development Error is detected                  **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description : This routine checks for development error for                **
**               Fls_17_Dmu_Write API                                         **
*******************************************************************************/
LOCAL_INLINE Std_ReturnType Fls_lCheckWriteDet(
  const Fls_17_Dmu_AddressType TargetAddress,
  const uint8 *const SourceAddressPtr,
  const Fls_17_Dmu_LengthType Length)

{
  Std_ReturnType  RetVal;

  RetVal = E_OK;

  /* API called before initialization */


  if(Fls_lUninitDET(FLS_17_DMU_SID_WRITE) == 1U)
  {
    RetVal = E_NOT_OK;
  }
  /* Checking whether given TargetAddress is valid or not */



  else if((((uint32)TargetAddress >= FLS_17_DMU_TOTAL_SIZE)) ||
          ((TargetAddress & FLS_PAGE_SIZE_MASK) != 0U) )
  {


    /* Report to DET */
    Fls_lReportError(FLS_17_DMU_SID_WRITE, FLS_17_DMU_E_PARAM_ADDRESS);

    RetVal = E_NOT_OK;
  }
  /* Checking whether given Length is valid or not */


  else if((!(((uint32)Length >= FLS_ONE_VALUE) &&
             ((uint32)Length <= (FLS_17_DMU_TOTAL_SIZE - TargetAddress)))) ||
          ((Length & FLS_PAGE_SIZE_MASK) != 0U))
  {


    /* Report to DET */
    Fls_lReportError(FLS_17_DMU_SID_WRITE, FLS_17_DMU_E_PARAM_LENGTH);

    RetVal = E_NOT_OK;
  }
  /* Check for Pointer to an application buffer */

  /* MISRA2012_RULE_11_6_JUSTIFICATION: cast from pointer to unsigned long
  is required to check the value of the address of data buffer alignment.
  */
  /* MISRA2012_RULE_11_4_JUSTIFICATION: conversion between pointer and integer
         type is required to access the FLASH address/target address which
         is defined as unsigned long. */
  /* MISRA2012_RULE_10_4_JUSTIFICATION: cast from pointer to unsigned long
    is required to check the value of the address of data buffer alignment.
   The implicit conversion will only compare the value*/
  else if((SourceAddressPtr == NULL_PTR) || \
          (((uint32)SourceAddressPtr & FLS_WORD_SIZE_MASK) != 0))
  {


    /* Report to DET */
    Fls_lReportError(FLS_17_DMU_SID_WRITE, FLS_17_DMU_E_PARAM_DATA);

    RetVal = E_NOT_OK;
  }
  else
  {
    /* dummy else */
  }


  return RetVal;

}

#endif
/* FLS_17_DMU_DEV_ERROR_DETECT == STD_ON */

/*******************************************************************************
** Traceability :[cover parentID={A6F30336-23EC-46c9-A9FF-E59694FAAA03}]      **
**                                                                            **
** Syntax:LOCAL_INLINE uint8 Fls_lGetWriteMode(void);                         **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : FLS_17_DMU_PAGE_WRITE - Page write to be done            **
**                   FLS_17_DMU_BURST_WRITE - Burst write to be done          **
**                                                                            **
** Description : This function checks whether Burst Write can be performed or **
**               Page Write has to be performed                               **
*******************************************************************************/
LOCAL_INLINE uint8 Fls_lGetWriteMode(void)
{
  const Fls_17_Dmu_StateType   *StatePtr;
  uint8           RetVal;

  RetVal = FLS_17_DMU_BURST_WRITE;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  if((StatePtr->FlsWriteLength <=
      (FLS_17_DMU_BURST_PAGE_SIZE - FLS_17_DMU_PAGE_SIZE))
      || ((StatePtr->FlsWriteAddress
           & (FLS_17_DMU_BURST_PAGE_SIZE - 1U)) != 0U))
  {

    RetVal = FLS_17_DMU_PAGE_WRITE;
  }

  return RetVal;
}

/*******************************************************************************
** Traceability :[cover parentID={F5E03FEE-EA96-4893-BF64-DD240CF917AE}]      **
**                                                                            **
** Syntax:LOCAL_INLINE Fls_LengthType Fls_lGetReadModeLength(void);           **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : max read length as per read mode                         **
**                                                                            **
** Description : Get max read length according to the FLS mode                **
*******************************************************************************/
LOCAL_INLINE Fls_17_Dmu_LengthType Fls_lGetReadModeLength(void)
{
  const Fls_17_Dmu_StateType   *StatePtr;
  Fls_17_Dmu_LengthType  MaxRead;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  MaxRead = Fls_ConfigPtr->FlsFastRead;


  if(StatePtr->FlsMode == MEMIF_MODE_SLOW)
  {

    MaxRead = Fls_ConfigPtr->FlsSlowRead;
  }

  return MaxRead;
}

/*******************************************************************************
** Traceability : [cover parentID={ACA27314-E9B3-43c4-9C97-026F0C0AE667}]     **
**                                                                            **
** Syntax: LOCAL_INLINE uint32 Fls_lChkSeqError(void)                         **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Sequence bit of FSR                                      **
**                                                                            **
** Description : Checks for sequence error                                    **
*******************************************************************************/
LOCAL_INLINE uint32 Fls_lChkSeqError(void)
{
  uint32 RetVal;

  RetVal = ((uint32)DMU_SF_ERRSR.U & FLS_SQER_ERROR);

  return RetVal;
}

/*******************************************************************************
** Traceability :[cover parentID={3F153B3F-0CBA-46e9-B9F0-3D543008C486}]      **
**                                                                            **
** Syntax: LOCAL_INLINE uint32 Fls_lChkOperError(void)                        **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : operational error bit of FSR                             **
**                                                                            **
** Description : Checks for operational error                                 **
*******************************************************************************/
LOCAL_INLINE uint32 Fls_lChkOperError(void)
{
  uint32 RetVal;


  RetVal = ((uint32)DMU_SF_ERRSR.U & FLS_OPER_ERROR);

  if(RetVal != 0U)
  {
    RetVal = FLS_OPER_ERROR;


    if(Fls_ConfigPtr->FlsIllegalStateNotificationPtr != NULL_PTR)
    {
      /* FlsIllegalStateNotificationPtr should be called */

      (Fls_ConfigPtr->FlsIllegalStateNotificationPtr)();
    }
  }

  return (RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID={653BD8F9-D7EA-4a74-A8DB-5BDB014F51A3}]     **
**                                                                            **
** Syntax: LOCAL_INLINE uint32 Fls_lChkBitErrors(void)                        **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Non correctable bit of FSR                               **
**                                                                            **
** Description : Checks for double ECC errors                                 **
*******************************************************************************/
LOCAL_INLINE uint32 Fls_lChkBitErrors(void)
{
  uint32 RetVal;
  uint32 BitChange;


  RetVal = ((uint32)DMU_SF_ECCS.U & FLS_BIT_ERROR);


  if(RetVal != 0U)
  {

    /*Clear the ECC status by writing SF_ECCC.CLR with 11b*/
    BitChange = DMU_SF_ECCC.U | FLS_DMU_ECCC_CLR;
    /*MISRA2012_RULE_11_3_JUSTIFICATION: Pointer cast is required to match
    the object types as the address of the register is being passed.*/
    FLS_17_DMU_DF1_SFR_WRITE(\
        (volatile uint32 *)&DMU_SF_ECCC.U, \
        BitChange);
  }
  return RetVal;
}

/*******************************************************************************
** Traceability : [cover parentID={70FF10EA-9B50-4b20-AB23-C14CF3AB0F80}]     **
**                                                                            **
** Syntax: LOCAL_INLINE uint32 Fls_lHWBusyCheck(void)                         **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Busy bit of FSR                                          **
**                                                                            **
** Description : Checks for Busy status of the Data Flash Bank                **
*******************************************************************************/
LOCAL_INLINE uint32 Fls_lHWBusyCheck(void)
{
  uint32 RetVal;

  RetVal = ((uint32)DMU_SF_STATUS.U & FLS_D1BUSY);

  return RetVal;
}

/*******************************************************************************
** Traceability : [cover parentID={679709F3-4A7F-48d6-A544-BE382E28FF2F}]     **
**                                                                            **
** Syntax: LOCAL_INLINE MemIf_ModeType Fls_lSetDefaultMode(void)              **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : MemIf_ModeType                                           **
**                                                                            **
** Description : Returns the default mode of FLS driver                       **
*******************************************************************************/
LOCAL_INLINE MemIf_ModeType Fls_lSetDefaultMode(void)
{
  return (Fls_ConfigPtr->FlsDefaultMode);
}

#if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON)|| \
(FLS_17_DMU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Traceability   : [cover parentID={6D03B66B-576D-4850-ABCD-769EAFF88353}]   **
**                                                                            **
** Syntax          : LOCAL_INLINE void Fls_lReportError                       **
**                                (const uint8 Fls_Sid, const uint8 ErrorId)  **
**                                                                            **
** Description     : Function to report Safety Error and DET                  **
** [/cover]                                                                   **
**                                                                            **
** Service ID      : None                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Reentrant                                                **
**                                                                            **
** Parameters (in) : Fls_Sid - Service id of the caller API                   **
**                   ErrorId - ID of the error to be reported                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
*                                                                             **
*******************************************************************************/
static void Fls_lReportError(const uint8 Fls_Sid, const uint8 ErrorId)
{

  #if (FLS_17_DMU_DEV_ERROR_DETECT == STD_ON)
  Det_ReportError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID, Fls_Sid,
                  ErrorId);
  #endif

  #if (FLS_17_DMU_SAFETY_ENABLE == STD_ON)
  Mcal_ReportSafetyError(FLS_17_DMU_MODULE_ID, FLS_17_DMU_INSTANCE_ID, Fls_Sid,
                         ErrorId);
  #endif
}
#endif/*End of Fls_lReportError*/

#define FLS_17_DMU_STOP_SEC_CODE_QM_LOCAL
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header usage as per Autosar
  guideline. */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safeguard. It complies to Autosar guidelines. */
#include "Fls_17_Dmu_MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/