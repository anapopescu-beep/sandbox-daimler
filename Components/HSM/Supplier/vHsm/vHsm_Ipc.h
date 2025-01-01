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
/*!        \file  vHsm_Ipc.h
 *        \brief  Vector Hardware Security Module Firmware (vHsm)
 *
 *      \details  Inter-processor communication between Host and Vector Hardware Security Module Firmware.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_IPC_H)
# define VHSM_IPC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm.h"
# include "vHsm_Cfg.h"
# include "vHsm_Types.h"
# include "vHsm_Ipc_Types.h"
# include "vHsm_Api.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* API services IDs */
# define VHSM_IPC_SID_TRANSMITJOBRESPONSE                             (0x80u)
# define VHSM_IPC_SID_RECEIVEJOBREQUEST                               (0x81u)
# define VHSM_IPC_SID_ISJOBREQUESTAVAILABLE                           (0x82u)
# define VHSM_IPC_SID_ISBUFFERVALID                                   (0x83u)

/* Development error types */
# define VHSM_IPC_E_NO_ERROR                                          (0xFFu)
# define VHSM_IPC_E_PARAM_POINTER                                     (0x81u)
# define VHSM_IPC_E_INVALID_CHANNEL                                   (0x82u)
# define VHSM_IPC_E_CANNOT_ALLOCATE_JOBRESPONSE_BUFFER                (0x83u)
# define VHSM_IPC_E_CANNOT_COPY_JOBREQUEST_DATA                       (0x84u)
# define VHSM_IPC_E_POINTER_NOT_IN_WHITELIST                          (0x85u)
# define VHSM_IPC_E_PARAM_HANDLE                                      (0x86u)

# define VHSM_CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION                     (0x00000100u)

# define VHSM_CRYPTO_JOBTYPE_DESERIALIZED_BUF_SIZE                    (104u)
# define VHSM_CRYPTO_JOBRESULTTYPE_SERIALIZED_BUF_SIZE                (12u)

# define VHSM_KEYM_JOBTYPE_DESERIALIZED_BUF_SIZE                      (36u)
# define VHSM_KEYM_JOBRESULTTYPE_SERIALIZED_BUF_SIZE                  (4u)

# define VHSM_MEM_ALLOW_READ                                          (1u)
# define VHSM_MEM_ALLOW_READWRITE                                     (3u)

# if (VHSM_IPC_PROTOCOL_VERSION == 3u)
#  define VHSM_IPC3_CRYPTOJOB_MAXPTRMASK                              (0x070303FFu)
#  define VHSM_IPC3_KEYMJOB_MAXPTRMASK                                (0x010103FFu)

#  define VHSM_IPC3_CRYPTOJOB_INPUTPTRMAX                             (3u)
#  define VHSM_IPC3_CRYPTOJOB_OUTPUTPTRMAX                            (2u)
#  define VHSM_IPC3_CRYPTOJOB_KEYIDMAX                                (2u)

#  define VHSM_IPC3_KEYMJOB_INPUTPTRMAX                               (1u)
#  define VHSM_IPC3_KEYMJOB_OUTPUTPTRMAX                              (1u)
#  define VHSM_IPC3_KEYMJOB_KEYIDMAX                                  (2u)

#  define VHSM_IPC3_JOB_INPUTPTR_MAX                                  (0x03u)
#  define VHSM_IPC3_JOB_OUTPUTPTR_MAX                                 (0x02u)
#  define VHSM_IPC3_JOB_KEYIDS_MAX                                    (0x02u)
#  define VHSM_IPC3_JOB_CONSTDATA_MAX                                 (0x0fu)
#  define VHSM_IPC3_INVALIDSERIVCEPATTERN                             (0xFFFFFFFFuL)
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# if VHSM_SETTING_ENABLE_API_GET_IPC_ADDRESS == STD_ON
#  define vHsm_Ipc_ChangeInstance(index)                              vHsm_Ipc_MemoryPtr=vHsm_Hal_GetIpcAddress(((uint32)index), vHsm_GetMemoryOfIpcInstance(((uint32)index)))
# else
#  define vHsm_Ipc_ChangeInstance(index)                              vHsm_Ipc_MemoryPtr=vHsm_GetMemoryOfIpcInstance((index))
# endif

# define vHsm_Ipc_GetMemoryPtr8(offset)                               (&(((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Ipc_MemoryPtr)[offset]))
# define vHsm_Ipc_GetMemoryValue32(offset)                            (*(volatile uint32*)&(((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_Ipc_MemoryPtr)[offset]))

# define vHsm_Ipc_EnterRamExec()                                      vHsm_Ipc_SetRamExecFlag(1u)
# define vHsm_Ipc_LeaveRamExec()                                      vHsm_Ipc_SetRamExecFlag(0u)
# define vHsm_Ipc_EndRamExec()                                        vHsm_Ipc_SetEndRamExecFlag(0u)
# define vHsm_Ipc_IsRamExecEndReached()                               vHsm_Ipc_GetEndRamExecFlag()

# define vHsm_Ipc_HsmReady()                                          vHsm_Ipc_SetReadyFlag(0xDEADBEEFU)
# define vHsm_Ipc_HsmNotReady()                                       vHsm_Ipc_SetReadyFlag(0U)

# define vHsm_Ipc_GetStackProtectionCanaryPE1Ptr()                    (vHsm_Ipc_GetMemoryPtr8(vHsm_Ipc_MemoryLayout.stackProtectionCanaryPE1Offset))
# define vHsm_Ipc_GetStackProtectionCanaryPE2Ptr()                    (vHsm_Ipc_GetMemoryPtr8(vHsm_Ipc_MemoryLayout.stackProtectionCanaryPE2Offset))

# define vHsm_Ipc_GetSeedPtr()                                        (vHsm_Ipc_GetMemoryPtr8(vHsm_Ipc_MemoryLayout.seedOffset))
# define vHsm_Ipc_GetSeedSize()                                       (16u)

# define vHsm_Ipc_GetRxChannelBuffer(channelId)                       (vHsm_Ipc_GetMemoryPtr8(vHsm_Ipc_MemoryLayout.rxChannelMemoryLayout[channelId].bufferOffset))

# define vHsm_Ipc_GetRxChannelWriteIdx(channelId)                     (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.rxChannelMemoryLayout[channelId].writeIdxOffset))

# define vHsm_Ipc_GetRxChannelReadIdx(channelId)                      (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.rxChannelMemoryLayout[channelId].readIdxOffset))

# define vHsm_Ipc_GetTxChannelBuffer(channelId)                       (vHsm_Ipc_GetMemoryPtr8(vHsm_Ipc_MemoryLayout.txChannelMemoryLayout[channelId].bufferOffset))

# define vHsm_Ipc_GetTxChannelWriteIdx(channelId)                     (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.txChannelMemoryLayout[channelId].writeIdxOffset))

# define vHsm_Ipc_GetTxChannelReadIdx(channelId)                      (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.txChannelMemoryLayout[channelId].readIdxOffset))

# define vHsm_Ipc_SetDetReportFlag(value)                             (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.detReportFlagOffset) = (value))
# define vHsm_Ipc_SetDetModuleId(value)                               (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.detModuleIdOffset) = (value))
# define vHsm_Ipc_SetDetInstanceId(value)                             (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.detInstanceIdOffset) = (value))
# define vHsm_Ipc_SetDetApiId(value)                                  (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.detApiIdOffset) = (value))
# define vHsm_Ipc_SetDetErrorId(value)                                (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.detErrorIdOffset) = (value))

# define vHsm_Ipc_SetRamExecFlag(value)                               (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.ramExecFlagOffset) = (value))
# define vHsm_Ipc_GetEndRamExecFlag()                                 ((boolean)vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.endRamExecFlagOffset))
# define vHsm_Ipc_SetEndRamExecFlag(value)                            (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.endRamExecFlagOffset) = (value))

# define vHsm_Ipc_SetReadyFlag(value)                                 (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.readyFlagOffset) = (value))

# define vHsm_Ipc_GetStackProtectionCanaryPE1()                       (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.stackProtectionCanaryPE1Offset))
# define vHsm_Ipc_GetStackProtectionCanaryPE2()                       (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.stackProtectionCanaryPE2Offset))

# define vHsm_Ipc_GetSeed()                                           (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.seedOffset))

# define vHsm_Ipc_vHsmProtocolVersion()                               (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.protocolInfoOffset))
# define vHsm_Ipc_DriverProtocolVersion()                             (vHsm_Ipc_GetMemoryValue32(vHsm_Ipc_MemoryLayout.protocolInfoOffset + 4u))

/*! Serialize a uint32 to the IPC buffer with the offset */
# define vHsm_Serialize_Uint32(rVal, bufPtr, offset)                  (*(P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))(&(((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(bufPtr))[(offset)]))) = (uint32)(rVal)

/*! Serialize a pointer to the IPC buffer with the offset */
# define vHsm_Serialize_Ptr32(rVal, bufPtr, offset)                   (*(P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))(&(((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(bufPtr))[(offset)]))) = (uint32)(rVal)

/*! Deserialize a uint32 to the IPC buffer with the offset */
# define vHsm_Deserialize_Uint32(bufPtr, offset)                      (*(P2CONST(uint32, AUTOMATIC, VHSM_APPL_VAR))(&(((P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))(bufPtr))[(offset)])))

/*! Deserialize a pointer to the IPC buffer with the offset */
# define vHsm_Deserialize_Ptr32(bufPtr, offset)                       (*(P2CONST(uint32, AUTOMATIC, VHSM_APPL_VAR))(&(((P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))(bufPtr))[(offset)])))

/*
 * Mapping of Job Ids
 * 0x00000000-0x0000FFFF: Jobs from Csm located inside vHsm
 * 0x1x000000-0x1x00FFFF: Jobs from Csm located on Application Core (external request) (x stands for IPC instance)
 * 0x20000000-0x2000FFFF: Jobs from vHsm_Api which are created dynamically
 * 0x30000000-0x3000FFFF: reserved for future use
 */
# define vHsm_Ipc_MaskIpcChannelToJobId(jobId)                        (VHSM_API_EXTERNAL_JOB_FLAG | ((uint32)(((uint8)vHsm_Ipc_Idx & 0x0FuL)) << 24u) | (jobId))
# define vHsm_Ipc_UnmaskIpcChannelFromJobId(jobId)                    ((jobId) & 0x00FFFFFFu)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef void(*vHsm_Ipc_JobRequest_RxFctType)(
  vHsm_JobObjectIdType jobObjectId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) jobRequestBuffer);

typedef void(*vHsm_Ipc_JobResponse_TxFctType)(
  vHsm_JobObjectIdType jobObjectId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) jobRequestBuffer);

typedef boolean(*vHsm_Ipc_CheckCryptoJobBuffersValidFctType)(
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr,
  vHsm_JobObjectIdType jobObjectId);

typedef boolean(*vHsm_Ipc_CheckKeyMJobBuffersValidFctType)(
  P2VAR(vHsm_KeyM_JobType, AUTOMATIC, VHSM_APPL_VAR) jobPtr,
  vHsm_JobObjectIdType jobObjectId);

typedef struct vHsm_Ipc_JobKindInfoTypeStruct
{
  uint8 processKind;
  vHsm_Ipc_JobResponse_TxFctType txFct;
  uint32 jobRequestBufferSize;
  uint32 jobResponseBufferSize;
} vHsm_Ipc_JobKindInfoType;

# if (VHSM_IPC_PROTOCOL_VERSION == 3u)
typedef struct
{
  uint8 numOfInputs;
  uint8 numOfOutputs;
  uint8 numOfKeys;
  uint8 numOfConst;
  uint32 ptrMask;
  Crypto_ServiceInfoType service;
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) inputPtr[VHSM_IPC3_JOB_INPUTPTR_MAX];
  uint32 inputLength[VHSM_IPC3_JOB_INPUTPTR_MAX];
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) outputPtr[VHSM_IPC3_JOB_OUTPUTPTR_MAX];
  uint32 outputLength[VHSM_IPC3_JOB_OUTPUTPTR_MAX];
  uint32 keyIds[VHSM_IPC3_JOB_KEYIDS_MAX];
  uint32 constData[VHSM_IPC3_JOB_CONSTDATA_MAX];
} vHsm_Ipc3_Content;

typedef Std_ReturnType(*vHsm_Ipc3_CalloutCheckPtrMask_Type)(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData);

typedef void(*vHsm_Ipc3_Factories_Type)(
  P2CONST(vHsm_Ipc3_Content, AUTOMATIC, VHSM_APPL_VAR) parsedData,
  vHsm_JobObjectIdType jobObjectId);

typedef struct vHsm_Ipc3_GenericFunctionsTypeStruct
{
  vHsm_Ipc3_CalloutCheckPtrMask_Type ptrCallout;
  vHsm_Ipc3_Factories_Type factoryCallout;
} vHsm_Ipc3_GenericFunctionsType;

# else /* (VHSM_IPC_PROTOCOL_VERSION == 2u) */

typedef struct vHsm_Ipc2_FunctionsTypeStruct
{
  vHsm_Ipc_JobRequest_RxFctType rxFct;
  vHsm_Ipc_CheckCryptoJobBuffersValidFctType checkFctCrypto;
  vHsm_Ipc_CheckKeyMJobBuffersValidFctType checkFctKeyM;
} vHsm_Ipc2_GenericFunctionsType;
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_VAR_NOINIT_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) vHsm_Ipc_MemoryPtr;

# define VHSM_STOP_SEC_VAR_NOINIT_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_START_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(uint8, VHSM_VAR_NOINIT) vHsm_Ipc_Idx;

# define VHSM_STOP_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(vHsm_Ipc_MemoryLayoutType, VHSM_CONST) vHsm_Ipc_MemoryLayout;
extern CONST(vHsm_Ipc_JobKindInfoType, VHSM_CONST) vHsm_Ipc_JobKindInfo[VHSM_NR_OF_JOBREQUESTKINDS];
# define VHSM_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  vHsm_Ipc_Init()
 *********************************************************************************************************************/
/*! \brief         Init the IPC
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Ipc_Init(void);

/**********************************************************************************************************************
 *  vHsm_Ipc_TransmitJobResponse()
 *********************************************************************************************************************/
/*! \brief         Transmit the job response
 *  \details       -
 *  \param[in]     jobObjectId      Id of the object
 *  \param[in]     jobResponseBufferSize   Size of the available buffer for the job response
 *  \return        E_OK           Response has been sent successful
 *  \return        E_NOT_OK       Response has not been sent successful
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE for differend job object ids
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Ipc_TransmitJobResponse(
  vHsm_JobObjectIdType jobObjectId,
  uint32 jobResponseBufferSize);

/**********************************************************************************************************************
 *  vHsm_Ipc_DetReportError()
 *********************************************************************************************************************/
/*! \brief         Report a DET error to the ipc which can be evaluated by the application.
 *  \details       The last occurred DET error is stored in IPC.
 *  \param[in]     moduleId      Module where the error happened
 *  \param[in]     instanceId    Instance where the error happened
 *  \param[in]     apiId         API where the error happened
 *  \param[in]     errorId       IError which happened
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Ipc_DetReportError(
  uint16 moduleId,
  uint8 instanceId,
  uint8 apiId,
  uint8 errorId);

/**********************************************************************************************************************
 *  vHsm_Ipc_MainFunction()
 *********************************************************************************************************************/
/*! \brief         Process the Ipc and check if there are new jobs available which shall be processed.
 *  \details       -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Ipc_MainFunction(void);

/**********************************************************************************************************************
 *  vHsm_Ipc_FetchJobs()
 *********************************************************************************************************************/
/*! \brief         Fetch the jobs from the IPC and mark them as pending
 *  \details       -
 *  \param[in]     callContext    Call context from where the function has been called
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Ipc_FetchJobs(vHsm_CallContextType callContext);

/**********************************************************************************************************************
 *  vHsm_Ipc_StartJobObjectTask()
 *********************************************************************************************************************/
/*! \brief       Function which starts the task
 *  \details     This is either done by triggering an event or calling ActivateTask
 *  \pre         -
 *  \param[in]   jobObjectId     Id of the job object
 *  \context     ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Ipc_StartJobObjectTask(vHsm_JobObjectIdType jobObjectId);

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_IPC_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Ipc.h
 *********************************************************************************************************************/
