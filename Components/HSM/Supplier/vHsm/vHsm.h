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
/*!        \file  vHsm.h
 *        \brief  vHsm header file
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2017-12-15  vistof  -             Initial version
 *                        visfpt                Hardware support for CMAC
 *                        vismsl                Concept work
 *                        viscwu                Concept work
 *  01.01.00  2018-03-12  vistof  STORYC-4214   Feature Completion:
 *                                              Fixed Secure Boot
 *                                              Fixed Bundling protocol
 *                                              Added input validation
 *                                              Added tracing
 *                                              Added support for modifying option bytes
 *                                              Removed ModeM
 *                                              Fixed switching to RAM loop
 *                                              Added Upgrade Protection Disable Mechanism
 *                                              Added support for write-once keys
 *                                              Added support for deleting keys
 *                                              Added support for error log
 *                                              Added support for DET forwarding
 *                                              Fixed: application cores do not start when debugger is not attached.
 *                                              Rework of Nvm to use pages
 *                                              Reset safe Nvm
 *                                              Support configuration without Nvm usage
 *                                              Added configurable mapping for keys and channels
 *                                              Added configurable response IPIR channel
 *                                              Added support lazy persisting keys
 *                                              Divided vHsm Firmware into subcomponents (Core, Hal, Custom)
 *                                              Configurable memory boundaries
 *                                              Added support for F1H 6M
 *                        visfpt                Added hardware support for AES
 *                        vismsl                Rework of Ipc
 *  01.02.00  2018-06-21  visjhi  STORYC-5512   Introduce a preconfigured Key Storage Concept
 *                                STORYC-5514   Provide a mechanism to randomly initialize keys during first boot
 *  02.00.00  2018-08-22  vistof  ESCAN00100323 Fixed Input/Output data validation is vulnerable to address range overflows
 *                                ESCAN00100324 Fixed RAM-loop may be located in ROM due to inlining depending on compiler settings
 *                                STORYC-6212   Added support for IPC Protocol Version 2
 *                                ESCAN00101288 Fixed Missing check for readability of input length pointers
 *            2018-09-25  visrpp  STORYC-6655   Processing of crypto jobs from multiple cores
 *            2018-10-08  visrpp  STORYC-6697   MISRA-C:2012 Compliance
 *  02.00.01  2018-10-10  vistof  ESCAN00100982 Possible buffer overflow when issuing too many secure boot verification jobs
 *            2018-10-16  vistof  ESCAN00101036 Nvm will not persist keys correctly
 *  02.00.02  2018-10-25  vistof  ESCAN00101147 Nvm overrides keys when multiple keys containing the same key elements are referenced in the same NvmPage
 *  02.01.00  2018-11-22  visjhi  STORYC-7128   Split API to internal and external parts
 *            2019-03-21  vistof  STORYC-6982   Changes in the Nvm Layout configuration can be detected and will trigger a reset of the Nvm to the init values.
 *                                STORYC-6984   Added command to repersist the whole keystorage
 *                                ESCAN00101245 Fixed Missing check of the cryptoKeyId during crypto job processing
 *                                ESCAN00101287 Fixed Missing check for correct alignment of input length pointers
 *                                STORYC-7021   CMAC processing optimization
 *                                STORYC-7356   Create local copy of the outputLengthPtr content
 *                                STORYC-7340   Added support for Crypto_KeyElementCopyPartial API
 *                                STORYC-7357   Added error log for failed secure boot
 *                                STORYC-7142   Support redirection of input/output buffers from/to key elements
 *                                STORYC-7077   Added vHsm Firmware Update Service
 *                                ESCAN00101675 Fixed: Temporary jobs do not have distinct jobIds
 *                                STORYC-7832   Forward all KeyM functions to the configured drivers and not just to the LibCv.
 *                                ESCAN00102372 Fixed: Secure Software Download expects the address and size in the finish call
 *                                STORYC-7831   Remove input/output length restriction of 64k bytes
 *                                STORYC-7894   Introduce Secure Boot Group and Segments
 *                                STORYC-5507   Allow Parallel and Sequential Boot decsision at runtime
 *                                STORYC-7895   Update Secure Boot Group through passed Segment List with Signature
 *                                STORYC-7911   Added Freedom of interference for jobIds of different sources
 *                                ESCAN00102580 Initialization of application RAM from HSM core is unsuccessful
 *                                ESCAN00101543 Overwork OutputLengthPtr Handling
 *            2019-03-25  visrpp  ESCAN00102615 Fixed: SHE Keys can only be written once
 *  02.01.01  2019-05-06  vistof  ESCAN00103015 Secure Boot: Secure Boot always fails and CMAC is not calculated on first startup
 *                                ESCAN00103064 Secure Boot: Result of external triggered secure boot group verification not updated correctly
 *                                ESCAN00103073 Secure Boot: Disabled secure boot segments are always processed
 *                                              as sequential when CRYPTO_ALGOMODE_CUSTOM_SECURE_BOOT_FORCE_SEQUENTIAL is used
 *                                ESCAN00103093 Secure Boot: The result of signature verification during secure boot update is not updated and segments with wrong hash are ignored
 *                                STORYC-8331   Make restriction of Jump to Updater configurable
 *  02.01.02  2019-07-01  vistof  ESCAN00103294 Added possibility to restrict key usage to HSM
 *                                STORYC-8753   Option to generate random values to IPC at startup
 *  02.01.03  2019-07-08  vistof  ESCAN00103654 Compiler error: Internal Only keys can not be used when no hardware key is referenced
 *                                ESCAN00103658 KeyId of redirection jobs is not correctly checked for validity
 *  03.00.00  2019-08-02  vistof  HSM-228       Use Nvm handling of Crypto_30_LibCv and AUTOSAR NvM
 *                                HSM-428       Support multiple custom drivers
 *  03.00.01  2019-09-13  vistof  ESCAN00104300 Secure Boot Segment always needs a key element with id=1 during secure boot update/software download
 *                                ESCAN00104288 Not all NvM Block are automatically persisted on startup which may lead to a reset loop after first startup
 *  03.01.00  2019-09-24  vistof  ESCAN00104472 Fix error log handling when no init value is configured in the error log element
 *                                HSM-476       Added support for cyclic secure boot verification
 *                                HSM-474       Added support for event log
 *                                ESCAN00104584 The output length is not adapted during KeyElementGet of the vHsm version
 *                                ESCAN00105549 Det errors cause an exception when IPC was not yet initialized
 *  04.00.00  2019-12-06  vistof  HSM-589       Added support for OS
 *                                HSM-519       Job Processing in ISR
 *                                HSM-21        Support generator based configuration of MainFunction, Inits and Exclusive Areas
 *                                HSM-606       Added config option to prohibit address changes during secure software update
 *                                ESCAN00105348 Secure boot segment information (except CMAC) is set to initial values at each startup
 *                                ESCAN00105405 Dereference of NULL_PTR in case an error occurs during firmware update
 *                                HSM-697       Extend Secure Boot Key Usage Prohibition
 *                                HSM-753       Add support for forced sequential on first secure boot processing
 *  04.01.00  2020-04-21  vistof  HSM-760       Optimization of data structures
 *                                              Remove NvM_init from vHsm_Nvm_Init
 *  04.02.00  2020-05-27  vistof  HSM-896       Add option to skip alignment check on supported platforms
 *                                ESCAN00106483 vHsm_Api_KeyElementSet_Unchecked does not mark the key element as modified
 *                                              which prevents persisting during KeyValidSet
 *  04.02.01  2020-06-16  vistof  ESCAN00106605 EventLog does not persist the last 8 bytes
 *                                ESCAN00106632 Not persisted EventLog is not correctly initialized
 *  05.00.00  2020-06-19  visdil  HSM-848       Disallow key usage during runtime
 *                                HSM-912       Use Csm Jobs inside vHsm
 *                                HSM-990       Adapt Crypto_JobType according to new AUTOSAR specification
 *                                HSM-947       Add Helperfunction to enter Ramloop
 *                                HSM-339       Remove Write-Once key handling
 *                                HSM-1136      vHsm Ram Loop Controlling
 *                        vistof  HSM-850       Store secure boot info directly in NvM
 *                                HSM-846       Use Hash for SecureBoot
 *                                ESCAN00106856 KeyUsage is prevented due to partly uninitialized vHsm_State.vHsm_KeyUsageRestriction array
 *                                ESCAN00107035 Padding during event log writing will lead to memory corruption
 *  05.00.01  2020-09-24  visdil  ESCAN00107469 vHsm_PostApplicationStart_Callout instead of vHsm_PreApplicationStart_Callout called before StartApplicationCore
 *            2020-12-11  vistof  ESCAN00107588 Compiler warning: Missing braces around initializer
 *                                ESCAN00107586 Compiler warning: Variable "jobObjectId" is possibly uninitialized
 *                                ESCAN00107617 Compiler Error: jobRedirectionInfoRef member does not exist if redirection is disabled in Csm
 *                                ESCAN00107633 Secure Boot fails or ends in exception if configured address can only be accessed by a hardware window
 *                                ESCAN00108048 vHsm indicates running out of RAM few instructions too early
 *                                ESCAN00108046 Usage restriction of Driver objects used for parallel secure boot is not removed after secure boot is finished
 *                                ESCAN00108097 Memory Corruption during restriction of parallel channels used for secure boot
 *                                ESCAN00108118 Declaration of vHsm_PreRamLoop_Callout() maps the function to RAM although implementation is mapped to ROM
 *  06.00.00  2021-01-18  visdil  HSM-1322      vHsm_Core: Dynamic serialization (IPCv3)
 *                                HSM-1474      vHsm_Core: Provide jobs for persisting operations
 *                                HSM-1073      vHsm_Core: Allow temporarily deactivation of Driver Objects inside HSM
 *                                HSM-1210      vHsm_Core: Takeover and Verify Rollback ID from Segment Table
 *                        vistof  HSM-894       Trigger interrupts only for async jobs
 *  06.00.01  2021-04-06  vistof  ESCAN00109039 Performance Improvement
 *  07.00.00  2021-07-26  visfnn  HSM-1767      Support callout before jumping to Updater
 *                        vistof  HSM-1644      Secure boot: Support external Segment List verification and Multi partition
 *                        vismhh  HSM-1716      vHsm_Core: Evaluate the external ISR mask-parameter provided by the caller
 *                                HSM-1718      vHsm_Core: Implement IPC initialization via external ISR trigger
 *                        vismhh  HSM-1785      Support save/restore context
 *                        vistof  ESCAN00109971 Secure Boot request for parallel processed group via interrupt processed channel or in OS use-case can cause issues
 *                                ESCAN00109977 Secure Boot parallel processing does not work as expected
 *                                ESCAN00110046 Fix Compiler error: Missing vHsm_Local_DetChecksServiceValues() and vHsm_Core_UpdateJobState()
 *  08.00.00  2021-11-19  visfnn  HSM-1984      Add vHsm_StartApplicationCores_Callout
 *                        vistof  ESCAN00110722 The option vHsmSecureBootForcedSequentialProcessingOnFirstVerification has no effect
 *                                ESCAN00110855 Secure Boot Update is not calculated on buffered data
 *                                ESCAN00111028 Secure Software Download is not calculated on buffered data
 *                                HSM-2173      Add new APIs for Hwa_Base for accessing keys
 *                                HSM-2204      Add more restrictive checks for Key APIs with two keyIds to enable more detailed key usage restrictions via custom drivers
 *                                ESCAN00111417 Confirmation mode does not work as expected when inactive partition is checked
 *                                HSM-2308      Forward KeyElementCopyPartial() API also to other crypto drivers which support the API
 *********************************************************************************************************************/

#if !defined (VHSM_H)
# define VHSM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Types.h"
# include "vHsm_Cfg.h"
# include "vHsm_Api.h"
# include "vHsm_Log.h"
# include "vHsm_Cbk.h"
# include "Csm.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define VHSM_VERSION                                                 (0x0800u)
# define VHSM_RELEASE_VERSION                                         (0x00u)

/* Vendor and module identification */
# define VHSM_VENDOR_ID                                               (30u)
# define VHSM_MODULE_ID                                               (255u)
# define VHSM_INSTANCE_ID                                             (0u)

/* AUTOSAR Software Specification Version Information */
# define VHSM_AR_RELEASE_MAJOR_VERSION                                (0x04)
# define VHSM_AR_RELEASE_MINOR_VERSION                                (0x03)
# define VHSM_AR_RELEASE_REVISION_VERSION                             (0x00)

/* Component Version Information */
/* No u suffix is used for shift operator because some compilers may have problems */
# define VHSM_SW_MAJOR_VERSION                                        (VHSM_VERSION >> 8)
# define VHSM_SW_MINOR_VERSION                                        (VHSM_VERSION & 0x00FFu)
# define VHSM_SW_PATCH_VERSION                                        (VHSM_RELEASE_VERSION)

/* Magic pattern to indicate that the reset vectors shall be changed before the PE-Cores are started */
# define VHSM_RESET_INFO_MAGICPATTERN                                 (0xDEADCAFEu)

# define VHSM_INVALID_IPC_CHANNEL                                     (0xFFu)

# define VHSM_HSM2HOST_ACTIVE                                         (0u)
# define VHSM_HSM2HOST_READY                                          (1u)

# define VHSM_HOST2HSM_IPC_INITIALIZED                                (0u)

# define VHSM_DEACTIVATEJOBOBJECTS_SECUREBOOT                         ((uint8)(4u))
# define VHSM_DEACTIVATEJOBOBJECTS_RESTRICTCHANNEL                    ((uint8)(2u))
# define VHSM_DEACTIVATEJOBOBJECTS_API                                ((uint8)(1u))

# define VHSM_CLEAR_WHOLE_CACHE                                       (0xFFFFFFFFu)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

# if (VHSM_SETTING_ENABLE_API_GET_CODE_FLASH_ADDRESS == STD_OFF) /* COV_VHSM_VTT */
#  define vHsm_Hal_GetCodeFlashAddr(x)                                ((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(x))
# endif

/* Backward compatibility Defines for old function names */
# define vHsm_Main                                                    vHsm_Init

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
  uint32 resetVectorPe1;
  uint32 resetVectorPe2;
  boolean changePending;
}vHsm_ResetVectorInfoType;

typedef struct
{
  uint32 magicPattern;
  vHsm_ResetVectorInfoType resetVectorInfo;
  uint8 softResetCounter;
  uint8 queueTop;
}vHsm_ResetInfoType;

# if (VHSM_SECURE_BOOT == STD_ON)
typedef struct
{
  boolean groupFinished[vHsm_GetSizeOfSecureBootGroup()];
  Crypto_VerifyResultType groupResult[vHsm_GetSizeOfSecureBootGroup()];
  boolean segmentFinished[vHsm_GetSizeOfSecureBootSegment()];
  Crypto_VerifyResultType segmentResult[vHsm_GetSizeOfSecureBootSegment()];
}vHsm_SecureBootStateType;
# endif

typedef struct
{
# if (VHSM_SECURE_BOOT == STD_ON)
  vHsm_SecureBootStateType vHsm_SecureBootState;
# endif
  boolean vHsm_IpcInitialized[vHsm_GetSizeOfIpcInstance()];
  boolean vHsm_SecureBootEndIndicationFlag;
  boolean vHsm_SecureBootDoneFlag;
  boolean vHsm_StayInRamFlag;
  uint8 vHsm_StayInRamIpcChannel;
  boolean vHsm_Loop;
  boolean vHsm_DataflashPeLock;
  boolean vHsm_ErrorLogProcessing;
  boolean vHsm_DisableSoftReset;
  boolean vHsm_JumpToUpdaterFlag;
  boolean vHsm_SuccessfulFirmwareUpdateFlag;
  boolean vHsm_CyclicVerificationFlag;
  Crypto_VerifyResultType vHsm_SecureBootResult;
  uint8 vHsm_KeyUsageRestriction[vHsm_GetSizeOfKeyInfo()];
}vHsm_StateType;

typedef uint32 vHsm_JobObjectIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# if (VHSM_GENERATE_RANDOM_STACK_PROTECTION_CANARY == STD_ON)
#  define VHSM_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(uint32, VHSM_VAR_INIT) __stack_chk_guard; /* PRQA S 0602 */ /* MD_VHSM_0602_STACK_PROTECTION */
#  define VHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif

# define VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(vHsm_StateType, VHSM_VAR_NOINIT) vHsm_State;

# define VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_START_SEC_RESET_INFO_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
extern VAR(vHsm_ResetInfoType, VHSM_VAR_NOINIT) vHsm_ResetInfo;
# define VHSM_STOP_SEC_RESET_INFO_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_RAMCODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  vHsm_RamLoop()
 *********************************************************************************************************************/
/*! \brief       Function to keep the vHsm in a loop running in RAM
 *  \details     When the application cores need to write code flash, the vHsm Firmware has to be executed on the RAM.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Do not call manually! Only declared external to make sure function is linked to Ram.
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_RamLoop(void);

# if (VHSM_ENABLE_RAM_LOOP_CALLOUT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_RamLoop_Callout()
 *********************************************************************************************************************/
/*! \brief       Function which is called during the RAM loop. This function must be mapped to RAM.
 *  \details     This can be used to process flags of the hardware e.g. allow application cores to access the code flash.
 *  \return      E_OK           HSM stays in RAM execution.
 *  \return      E_NOT_OK       HSM will leave RAM execution
 *                              Note that E_NOT_OK will lead the HSM to leave RAM execution. Ensure that Application is
 *                              not writing flash when E_NOT_OK is returned from this callout.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_RamLoop_Callout(void);
# endif

/**********************************************************************************************************************
 *  vHsm_TriggerSoftwareReset()
 *********************************************************************************************************************/
/*! \brief         Trigger a software reset
 *  \details       -
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_TriggerSoftwareReset(void);

# define VHSM_STOP_SEC_RAMCODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_PreRamLoop_Callout()
 *********************************************************************************************************************/
/*! \brief       Function which is called before the RAM loop.
 *  \details     This function can be used to prevent the vHsm from entering the RAM loop.
 *  \return      E_OK           Allow the vHsm to enter RAM loop.
 *  \return      E_NOT_OK       Prevent the vHsm from entering the RAM loop.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_PreRamLoop_Callout(void);

/**********************************************************************************************************************
 *  vHsm_TriggerSoftwareResetWithIpcClearing()
 *********************************************************************************************************************/
/*! \brief         Trigger a software reset including clearing of IPC
 *  \details       -
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_TriggerSoftwareResetWithIpcClearing(void);

/**********************************************************************************************************************
 *  vHsm_MemRand()
 *********************************************************************************************************************/
/*! \brief         Generate a random number
 *  \details       Uses the HAL to generate a random number
 *  \param[out]    dstPtr     Pointer to the buffer to store the generated random data
 *  \param[in]     length     Number of random bytes which shall be generated
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_MemRand(
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) dstPtr,
  uint32 length);

/**********************************************************************************************************************
 *  vHsm_WriteErrorLog()
 *********************************************************************************************************************/
/*! \brief         Write an error entry to the Key Storage
 *  \details       The error entry consists of an id and a data value which will be placed at the beginning
 *                 of the memory space of the key element. The older entries will be moved to the back.
 *                 If there is not enough space for old elements, they will be discard.
 *  \param[in]     errorId                 Id of the error
 *  \param[in]     errorData               Data of the error. VHSM_LOG_DATA_NO_ERROR_DATA indicates not data.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_WriteErrorLog(
  uint32 errorId,
  uint32 errorData);

/**********************************************************************************************************************
 *  vHsm_StartupCallout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called during startup at the very beginning.
 *  \details       This function is called from the startup code. Ram does not need to be initialized at this point.
 *  \context       TASK
 *  \pre           -
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_StartupCallout(void);

# if (VHSM_NVM_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_FirstStartup_Callout()
 *********************************************************************************************************************/
/*! \brief       Callout which indicates the first startup of the vHsm Firmware.
 *  \details     -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_FirstStartup_Callout(void);
# endif

/**********************************************************************************************************************
 *  vHsm_SystemInit_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called during startup of the vHsm
 *  \details       This function is called from vHsm_Main at the beginning and can be used to initialize the Clock of the vHsm.
 *  \context       TASK
 *  \pre           -
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_SystemInit_Callout(void);

/**********************************************************************************************************************
 *  vHsm_InitOne_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called to initialize memory
 *  \details       -
 *  \context       TASK
 *  \pre           -
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_InitOne_Callout(void);

/**********************************************************************************************************************
 *  vHsm_InitTwo_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called to initialize modules before Nvm read all
 *  \details       -
 *  \context       TASK
 *  \pre           -
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_InitTwo_Callout(void);

/**********************************************************************************************************************
 *  vHsm_InitThree_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called to initialize modules after NvM read all
 *  \details       -
 *  \context       TASK
 *  \pre           -
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_InitThree_Callout(void);

/**********************************************************************************************************************
 *  vHsm_StartApplicationCores_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called to start the application cores and set the vHsm ready flag.
 *  \details       Mostly the HSM core is started first (after secure boot is processed). The application cores
 *                 wait for the Hsm core to become started. Additionally the Host application waits for the vHSM bootup
 *                 before the communication over the IPC is initialized. Therefore the HSM ready flag is set in this
 *                 callout (Bit 0 in HSM to Host register).
 *  \context       TASK
 *  \pre           -
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_StartApplicationCores_Callout(void);

/**********************************************************************************************************************
 *  vHsm_NvMainFunctions_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called to trigger the main functions needed to process the NvM
 *  \details       -
 *  \context       ANY
 *  \pre           -
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_NvMainFunctions_Callout(void);

/**********************************************************************************************************************
 *  vHsm_MainFunctionCyclic_Callout()
 *********************************************************************************************************************/
/*! \brief         Callout which is called cyclically during the mainloop
 *  \details       -
 *  \context       ANY
 *  \pre           -
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_MainFunctionCyclic_Callout(void);

/**********************************************************************************************************************
 *  __stack_chk_fail()
 *********************************************************************************************************************/
/*! \brief         Will be called when stack smashing is detected. the function must never return!
 *  \details       -
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) __stack_chk_fail(void); /* PRQA S 0602 */ /* MD_VHSM_0602_STACK_PROTECTION */

# if (VHSM_OS_SUPPORT == STD_OFF)
#  if (VHSM_GENERATE_RANDOM_STACK_PROTECTION_CANARY == STD_ON)
/**********************************************************************************************************************
 *  __ghs_get_stack_chk_guard_address()
 *********************************************************************************************************************/
/*! \brief         Used to provide the function which will return the address to the stack guard
 *  \details       This function is needed by the compiler when compiled with stack protection enabled
 *  \return        Address of the stack canary
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR), VHSM_CODE) __ghs_get_stack_chk_guard_address(void); /* PRQA S 0602 */ /* MD_VHSM_0602_STACK_PROTECTION */
#  endif
# endif

/**********************************************************************************************************************
 *  vHsm_Init()
 *********************************************************************************************************************/
/*! \brief       Initializes the vHsm
 *  \details     Initiate the startup procedure that takes place before the OS is started. In context of this function
 *               all variables of the vHsm are initialized and the driver init lists are called before finally the OS
 *               is started.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Specification of module initialization
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Init(void);

/***********************************************************************************************************************
 *  vHsm_StartupTwo()
 **********************************************************************************************************************/
/*! \brief       Completes the startup phase.
 *  \details     Implements the startup phase where the OS is already running.
 *               This function should be scheduled by a task directly after StartOS() and only be called once.
 *  \pre         vHsm_Init must be called before.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        vHsm invokes this method at end of vHsm_Init if no OS is present.
 **********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_StartupTwo(void);

/**********************************************************************************************************************
 *  vHsm_MainFunction()
 *********************************************************************************************************************/
/*! \fn          vHsm_MainFunction
 *  \brief       This function performs cyclic operations of the vHsm
 *  \details     The vHsm_MainFunction shall handle asynchronous requests like parallel secure boot, entering a ram
 *               loop or jumping to booloader
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Declared and called by SchM.
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  vHsm_TriggerSoftwareReset_Callout()
 **********************************************************************************************************************/
/*! \brief       Callout which must perform a reset
 *  \details     Before performing the actual reset,
 *               the user can implement custom behaviour to handle e.g. inform the host core about the pending reset.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
 FUNC(void, VHSM_CODE) vHsm_TriggerSoftwareReset_Callout(void);

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm.h
 *********************************************************************************************************************/
