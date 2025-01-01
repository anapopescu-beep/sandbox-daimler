/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  fbl_cw.c
 *      Project:  FblWrapperCom_PduR
 *       Module:  Implementation
 *    Generator:  CFG5
 *
 *  Description:  Fbl Communication wrapper layer for MICROSAR ASR4
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define FBLCW_SOURCE

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "FblCw_Cfg.h"
#include "FblCw_Lcfg.h"
#include "FblCw_PBcfg.h"
#include "ComStack_Types.h"
#include "fbl_inc.h"

#if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON)
/* CAN */
# include "CanIf_CanTrcv.h"
# include FBLCW_CANDRV_HEADER_NAME /* PRQA S 0832 */ /* MD_FblCw_0832 */
# include "CanIf.h"
# include "CanTp.h"

/* Required for main function declarations */
# include FBLCW_CANSCHM_HEADER_NAME /* PRQA S 0832 */ /* MD_FblCw_0832 */
# include "SchM_CanIf.h"
# include "SchM_CanTp.h"

/* CanIf callout declarations */
# include "CanIf_Cfg.h"
# include "CanIf_Cdd.h"
#endif

#if ( FBLCW_MODULE_COMM == STD_ON )
# include "ComM_Private_Cfg.h"
# include "ComM.h"
# include "ComM_EcuMBswM.h"
#endif

#if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
# if ( FBLCW_MODULE_ETHSM == STD_ON )
#  include "EthIf.h"
#  include "EthSM.h"
#  include "SchM_EthIf.h"
#  include "SchM_EthSM.h"
#  include "TcpIp.h"
# endif /* FBLCW_MODULE_ETHSM == STD_ON */
# include "IpBase.h"
# include "SoAd.h"
# if ( FBLCW_MODULE_DOIP == STD_ON )
#  include "DoIP.h"
#  include "SchM_DoIP.h"
# endif /* FBLCW_MODULE_DOIP == STD_ON */
# if ( FBLCW_MODULE_DOIPINT == STD_ON )
#  include "DoIPInt.h"
#  include "SchM_DoIPInt.h"
# endif /* FBLCW_MODULE_DOIPINT == STD_ON */
# include "SchM_SoAd.h"
# include "SchM_TcpIp.h"
# if ( FBLCW_MODULE_VBSDAD == STD_ON )
#  include "vBsdAd.h"
#  include "SchM_vBsdAd.h"
# endif /* FBLCW_MODULE_VBSDAD == STD_ON */
#endif /* FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */

#if ( FBLCW_MODULE_CANSM == STD_ON )
# include "CanSM_Cbk.h"
# include "SchM_CanSM.h"
#endif

#if ( FBLCW_MODULE_CANNM == STD_ON )
# include "SchM_CanNm.h"
#endif

#if ( FBLCW_MODULE_FRSM == STD_ON )
# include "Fr.h"
# include "FrIf.h"
# include "FrIf_Priv.h"
# include "FrIf_Ext.h"
# include "FrSM.h"
# include "SchM_FrSM.h"
# if ( FBLCW_MODULE_FRTP == STD_ON )
#  include "SchM_FrTp.h"
# endif
# if ( FBLCW_MODULE_FRARTP == STD_ON )
#  include "SchM_FrArTp.h"
# endif

/* Interface definitions */
# include "BswM_FrSM.h"
#endif

#if ( FBLCW_MODULE_FRNM == STD_ON )
# include "Nm.h"
# include "FrNm.h"
# include "SchM_FrNm.h"
#endif

#if ( FBLCW_MODULE_XCP == STD_ON )
# include "SchM_Xcp.h"
#endif


#if ( FBLCW_MODULE_LINSM == STD_ON )
# include FBLCW_LINDRV_HEADER_NAME
# include "LinIf.h"
# if ( LINIF_SW_MAJOR_VERSION >= 10u )
#  include "LinIf_Int.h"
# endif
# include "LinSM.h"

/* Interface definitions */
# include "BswM_LinSM.h"
#endif

/* PDU Router */
#include "PduR.h"
#include "PduR_Dcm.h"
#include "Dcm_Cbk.h"
#if ( FBLCW_DEV_ERROR_DETECT == STD_ON )
# include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/
#if ( FBLWRAPPERCOM_PDUR_VERSION != 0x0604u ) || ( FBLWRAPPERCOM_PDUR_RELEASE_VERSION != 0x02u )
# error "Error in fbl_cw.c: Source and header file are inconsistent!"
#endif

#if ( FBLWRAPPERCOM_PDUR_VERSION != _FBLWRAPPERCOM_PDUR_VERSION ) || ( FBLWRAPPERCOM_PDUR_RELEASE_VERSION != _FBLWRAPPERCOM_PDUR_RELEASE_VERSION )
# error "Error in fbl_cw.c: Source and v_ver.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/* Defines to indicate the transmission state */
#define kFblCwTxStateIdle                    0x00u    /**< Idle state */
#define kFblCwTxStateRpInProgress            0x01u    /**< RP was forwarded, wait for the confirmation */
#define kFblCwTxStateTxInProgress            0x02u    /**< Final answer was sent, wait for the confirmation */
#define kFblCwTxStateRpPending               0x03u    /**< RP was not sent, try to send it again until timeout */
#define kFblCwTxStateTxPending               0x04u    /**< Final answer was not sent, try to send it again until timeout */
#define kFblCwTxStateTxPendingWaitForConf    0x05u    /**< Final answer could not be sent as previous transmission is still pending, try to send it again until timeout */

/* Flags indicate, which task is currently running */
#define kFblCwTaskRunning              FBL_BIT0                         /**< Task active */
#define kFblCwStateTaskRunning         (kFblCwTaskRunning | FBL_BIT1)   /**< State task active */
#define kFblCwTimerTaskRunning         (kFblCwTaskRunning | FBL_BIT2)   /**< Timer task active */

/* Defines for the Shutdown state */
#define kFblCwNoShutdownRequest        0x00u    /**< No pending shutdown request */
#define kFblCwShutdownRequested        0x01u    /**< Shutdown requested */
#define kFblCwShutdownFinished         0x02u    /**< Shutdown request finished */

/* Flags used to control the call to the CW layer
   Block state and timer tasks against each other as well */ /* PRQA S 3453 16 */ /* MD_MSR_FctLikeMacro */
#define SetCwTaskRunning()             (cwTaskState |= kFblCwTaskRunning)                          /**< Set running state of task (unspecified) */
#define ClrCwTaskRunning()             (cwTaskState &= FblInvert8Bit(kFblCwTaskRunning))           /**< Clear running state of task (unspecified) */
#define GetCwTaskRunning()             ((cwTaskState & kFblCwTaskRunning) == kFblCwTaskRunning)    /**< Return running state of task */
#define IsCwTaskAllowed()              ((cwTaskState & kFblCwTaskRunning) != kFblCwTaskRunning)    /**< Is task (unspecified) execution possible? Prevent nested execution */
#define GetCwTaskState()               (cwTaskState)                                               /**< Get current task state */
#define RestoreCwTaskState(state)      (cwTaskState = (state))                                     /**< Restore task state to given value */

#define SetCwStateTaskRunning()        (cwTaskState |= kFblCwStateTaskRunning)                              /**< Set running state of state task */
#define ClrCwStateTaskRunning()        (cwTaskState &= FblInvert8Bit(kFblCwStateTaskRunning))               /**< Clear running state of state task */
#define GetCwStateTaskRunning()        ((cwTaskState & kFblCwStateTaskRunning) == kFblCwStateTaskRunning)   /**< Return running state of state task */
#define IsCwStateTaskAllowed()         IsCwTaskAllowed()                                                    /**< Is state task execution possible? Prevent nested execution */

#define SetCwTimerTaskRunning()        (cwTaskState |= kFblCwTimerTaskRunning)                              /**< Set running state of timer task */
#define ClrCwTimerTaskRunning()        (cwTaskState &= FblInvert8Bit(kFblCwTimerTaskRunning))               /**< Clear running state of timer task */
#define GetCwTimerTaskRunning()        ((cwTaskState & kFblCwTimerTaskRunning) == kFblCwTimerTaskRunning)   /**< Return running state of timer task */
#define IsCwTimerTaskAllowed()         IsCwTaskAllowed()                                                    /**< Is timer task execution possible? Prevent nested execution */

#if ( FBLCW_QUEUED_REQUEST == STD_ON )
# define kFblCwMsgInProcess         FBL_BIT0
# define kFblCwMsgQueued            FBL_BIT1
# define kFblCwRxIndPending         FBL_BIT2
# define SetCwMsgInProcess()        (cwQueuedRequestFlags |= kFblCwMsgInProcess)
# define GetCwMsgInProcess()        ((cwQueuedRequestFlags & kFblCwMsgInProcess) == kFblCwMsgInProcess)
# define ClrCwMsgInProcess()        cwQueuedRequestFlags &= FblInvert8Bit(kFblCwMsgInProcess)
# define SetCwMsgQueued()           (cwQueuedRequestFlags |= kFblCwMsgQueued)
# define GetCwMsgQueued()           ((cwQueuedRequestFlags & kFblCwMsgQueued) == kFblCwMsgQueued)
# define ClrCwMsgQueued()           cwQueuedRequestFlags &= FblInvert8Bit(kFblCwMsgQueued)
# define SetCwRxIndPending()        (cwQueuedRequestFlags |= kFblCwRxIndPending)
# define GetCwRxIndPending()        ((cwQueuedRequestFlags & kFblCwRxIndPending) == kFblCwRxIndPending)
# define ClrCwRxIndPending()        cwQueuedRequestFlags &= FblInvert8Bit(kFblCwRxIndPending)

# if defined( FBL_CW_MAX_FPL_START_FRAME )
# else
#  if ( FBLCW_MODULE_FRSM == STD_ON )
#   define FBL_CW_MAX_FPL_START_FRAME       246  /**< Maximum payload length of start frame */
#  elif ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
#   define FBL_CW_MAX_FPL_START_FRAME       6    /**< Maximum payload length of start frame */
#  else
#   error "Error in fbl_cw.c: Maximum payload length has to be defined for configured bus type"
#  endif
# endif
#endif

#if ( FBLCW_KEY_SLOT_MODE == STD_ON )
/* FlexRay slot mode for schedule switch */
# define FBL_CW_KEY_SLOT_MODE                 0u        /**< FlexRay slot mode 'key slot' */
# define FBL_CW_ALL_SLOT_MODE                 1u        /**< FlexRay slot mode 'all slots' */
# define FBL_CW_ALL_SLOT_MODE_REQUESTED       2u        /**< FlexRay slot mode will be set 'all slots' */

/* FlexRay network status parameter values */
# ifndef FBL_CW_NW_STATUS_NORMAL
#  define FBL_CW_NW_STATUS_NORMAL    0x0001u   /**< Network status 'normal' */
# endif
# ifndef FBL_CW_NW_STATUS_BOOT
#  define FBL_CW_NW_STATUS_BOOT      0x1000u   /**< Network status 'boot' */
# endif

/* Timeout value for reception of first frame */
# ifndef FBL_CW_NW_STATUS_TIMEOUT
#  define FBL_CW_NW_STATUS_TIMEOUT   50u       /**< Network status timeout in [ms] */
# endif
#endif

/** Marker value for unassigned connection */
#define FBLCW_CONNECTION_UNASSIGNED   0xFFu

#if (FBLCW_DEV_ERROR_REPORT == STD_ON)
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define FblCw_Det_ReportError(ApiId, ErrorCode)    (void)Det_ReportError(FBLCW_MODULE_ID, 0, (ApiId), (ErrorCode))
#endif

#if ( FBLCW_MODULE_COMM == STD_ON )
/* Configuration checks */
# if ( FBLCW_NO_COMM_CHANNELS == 1u)
/* Assume that FBL uses first COMM channel */
#  if !defined( FBLCW_COMM_CHANNEL )
#   define FBLCW_COMM_CHANNEL 0u
#  endif
# endif /* FBLCW_NO_COMM_CHANNELS == 1u */
#endif /* FBLCW_MODULE_COMM == STD_ON */

#if !defined( FblCw_CheckRxPduAllowedInActiveConnection )
/* Check if received pdu is allowed by the current connection */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define FblCw_CheckRxPduAllowedInActiveConnection(pduId, connection)     ((connection) == FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo((pduId)))
#endif

#if ( FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_OFF ) && \
    ( FBLCW_DCMDSLBROADCASTGROUPINFO == STD_OFF )
/* Check if received pdu is allowed for the given connection index */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define FblCw_CheckRxPduAllowedInConnection(pduId, connectionIdx)        FblCw_CheckRxPduAllowedInActiveConnection((pduId), activeConnection[(connectionIdx)])
#else
/* Check if received pdu is allowed for the given connection index */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define FblCw_CheckRxPduAllowedInConnection(pduId, connectionIdx)        (FblCwInternalCheckRxPduAllowedInConnection((pduId), (connectionIdx)) == TRUE)
#endif

#if !defined( FblCw_CheckTxPduAllowedInActiveConnection )
/* Check if transmit pdu is allowed by the current connection */ /* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define FblCw_CheckTxPduAllowedInActiveConnection(pduId, connection)     ((connection) == FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolTxInfo((pduId)))
#endif




#if ( FBLCW_MODULE_LINSM == STD_ON )
# if !defined( LINSM_MASTERNODE_POSSIBLE )
/* This is an old LinSM module, which does not support LinSlaves */
#  define LINSM_MASTERNODE_POSSIBLE STD_ON
# endif
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#if (FBLCW_USE_INIT_POINTER == STD_ON)
# define FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

P2CONST(FblCw_ConfigType, FBLCW_VAR_ZERO_INIT, FBLCW_PBCFG) FblCw_ConfigDataPtr = NULL_PTR;

# define FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

#define FBLCW_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
#if ( FBLCW_BUSNMRXINDDATA == STD_ON )
V_MEMRAM0 static V_MEMRAM1 vuint32 V_MEMRAM2 cwRxIndCycleTimer;                  /**< Rx indication trigger timer */
#endif

#if ( FBLCW_MODULE_LINSM == STD_ON )
# if ( LINIF_SW_MAJOR_VERSION < 10u )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 linIfCycleCounter;
# else
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 linIfCycleCounter[FblCw_GetSizeOfLinIfChannelsParamOfPCConfig()];
# endif
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 linSmCycleCounter;
#endif /* FBLCW_MODULE_LINSM == STD_ON */

#if ( FBLCW_TASK_CYCLE > 1u )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cycleCounter;                        /**< Task cycle counter */
#endif
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cwTxState;                           /**< Transmission state */
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 cwTxTimer;                          /**< Timer value for transmission timeout */
V_MEMRAM0 static V_MEMRAM1 tCwDataLengthType V_MEMRAM2 cwTxPendingLength;        /**< Pending transmission length */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cwTaskState;                         /**< State of tasks */

#if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
V_MEMRAM0 static V_MEMRAM1 vuintx V_MEMRAM2 cwCanHardwareLoopTimer;              /**< Timer value for hardware loop timeout */
#endif

#if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 cwShutdownTimer;                    /**< Timer value for shutdown request  timeout */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cwShutdownState;                     /**< State of shutdown request */
#endif

/** Pointer to buffer holding current (pending) transmission data */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *V_MEMRAM1 V_MEMRAM2 cwTxPendingBuffer;

V_MEMRAM0 static V_MEMRAM1 PduInfoType V_MEMRAM2 rxPduPhys[kFblCwNumberOfRequests];                 /**< Information of physical Rx PDU */
V_MEMRAM0 static V_MEMRAM1 PduInfoType V_MEMRAM2 rxPduFunc;                                         /**< Information of functional Rx PDU */
/* PRQA S 3218 1 */ /* MD_FblCw_3218 */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 * rxBuffer[kFblCwNumberOfRequests];                     /**< Receive buffer (start address) */
V_MEMRAM0 static V_MEMRAM1 PduInfoType V_MEMRAM2 txPdu[kFblCwNumberOfRequests];                     /**< Information of Tx PDU */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 txBuffer[kFblCwRcrRpMsgLength];                         /**< Transmission buffer for RCR-RP */
V_MEMRAM0 static V_MEMRAM1 tCwDataLengthType V_MEMRAM2 rxDataLength[kFblCwNumberOfRequests];        /**< Number of bytes to be received */

V_MEMRAM0 static V_MEMRAM1 PduLengthType V_MEMRAM2 rxRemainingBufferSize[kFblCwNumberOfRequests];   /** Remaining bytes in receive buffer */
/** Active connection handle */
V_MEMRAM0 static V_MEMRAM1 FblCw_DcmDslConnectionInfoIterType V_MEMRAM2 activeConnection[kFblCwNumberOfRequests];

#if ( FBLCW_QUEUED_REQUEST == STD_ON )
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cwQueuedRequestBuffer[FBL_CW_MAX_FPL_START_FRAME];      /**< Buffer for queued requests */
V_MEMRAM0 static V_MEMRAM1 PduLengthType V_MEMRAM2 cwQueuedRequestLength;                           /**< Request length of the currently queued frame */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cwQueuedRequestFlags;                                   /**< Status flags of queued request algorithm */
V_MEMRAM0 static V_MEMRAM1 FblCw_DcmDslConnectionInfoIterType V_MEMRAM2 cwQueuedRequestConnection;  /**< Connection used by queued request */
#endif

#if ( FBLCW_MODULE_FRSM == STD_ON )
V_MEMRAM0 static V_MEMRAM1 vuintx V_MEMRAM2 cwWakeUpFlag;

# if ( FRIF_CUSTOM_JLE_SCHEDULING == STD_ON )
V_MEMRAM0 static V_MEMRAM1 vuint8            V_MEMRAM2 JLETimerCycle[FrIf_CommonMaxNumberOfClusters];
V_MEMRAM0 static V_MEMRAM1 vuint16           V_MEMRAM2 JLETimerOffset[FrIf_CommonMaxNumberOfClusters];
V_MEMRAM0 static V_MEMRAM1 boolean           V_MEMRAM2 JLETimerEnabled[FrIf_CommonMaxNumberOfClusters];
# endif

# if ( FBLCW_KEY_SLOT_MODE == STD_ON )
/* Variables used by CheckNwStatus */
V_MEMRAM0 static V_MEMRAM1 vuint8  V_MEMRAM2 cwAllSlots;                    /**< Status flag which keeps the current slot mode (single or all) */
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 cwNwStatusTimeoutCtr;          /**< Timeout counter for observation of network status timeout */
V_MEMRAM0 static V_MEMRAM1 vuint16 V_MEMRAM2 cwNwStatusTimeout;             /**< Timeout for observation of network status timeout */
# endif

#endif




#if ( FBLCW_MODULE_COMM == STD_ON )
/** ComM channel online status */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cwComMChannelIsOnline[FBLCW_NO_COMM_CHANNELS];
/** Mapping of ComM channels to diagnostic channels */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 cwDcmComMChannelMapping[FBLCW_MAXIMUM_SIZE_OF_DCM_DSL_CONNECTION_INFO];
/** Final step of ComM related initialization must be executed in first run on FblCw_StateTask to ensure it is
    executed after ComM_PostInit */
V_MEMRAM0 static V_MEMRAM1 boolean V_MEMRAM2 cwCommInitializationFinished;
#endif /* FBLCW_MODULE_COMM == STD_ON */

#define FBLCW_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLCW_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FblCwInternalTransmitRP
 *********************************************************************************************************************/
/*! \brief       Transmit internal data buffer with RCR-RP
 *  \pre         CW is initialized, internal data buffer filled with RCR-RP message
 *********************************************************************************************************************/
static void FblCwInternalTransmitRP(void);

#if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
# if ( FBLCW_MODULE_COMM == STD_OFF ) || \
     ( FBLCW_BAUDRATE_SWITCH == STD_ON )
/**********************************************************************************************************************
 *  FblCwCanIfSetMode
 *********************************************************************************************************************/
/*! \brief       Switch CAN interface mode and wait until applied
 *  \pre         CW is initialized
 *  \param[in]   controllerId The CAN interface controller ID
 *  \param[in]   mode The requested CAN interface mode
 *********************************************************************************************************************/
static void FblCwCanIfSetMode(uint8 controllerId, CanIf_ControllerModeType mode);
# endif /* FBLCW_MODULE_COMM == STD_OFF || FBLCW_BAUDRATE_SWITCH == STD_ON */
#endif /* FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */


#if ( FBLCW_MODULE_FRSM == STD_ON )
# if ( FRIF_CUSTOM_JLE_SCHEDULING == STD_ON )
/**********************************************************************************************************************
 *  FrIf_CustomJLEHandling
 *********************************************************************************************************************/
/*! \brief       Job execution list of the FlexRay Interface.
 *  \details     Call the function for the activation of the Rx or Tx task.
 *  \pre         Communication wrapper is initialized.
 *********************************************************************************************************************/
static void FrIf_CustomJLEHandling(void);
# endif
#endif

#if ( FBLCW_KEY_SLOT_MODE == STD_ON )
/**********************************************************************************************************************
 *  FblCwCheckNwStatus
 *********************************************************************************************************************/
/*! \brief        Retrieve and evaluate the network status parameter
 *  \details      This function retrieves and evaluates the network status parameter from the first two bytes of the
 *                first slot of the static segment. Based on the network status parameter either the bootloader or the
 *                application schedule (transition into the application) is executed.
 *  \pre          FblCw is initialized.
 *********************************************************************************************************************/
static void FblCwCheckNwStatus(void);
#endif

/**********************************************************************************************************************
  FblCwInternalMainFunctionTimerTask
**********************************************************************************************************************/
/*! \brief        Main function execution
 *  \details      This task function is used to execute the communication stack main functions.
 **********************************************************************************************************************/
static void FblCwInternalMainFunctionTimerTask(void);

#if ( FBLCW_QUEUED_REQUEST == STD_ON )
/**********************************************************************************************************************
  FblCwInternalQueuedRequestTask
 **********************************************************************************************************************/
/*! \brief        Processed queued request
 *  \details      This task function is used to process a queued request from the CW state task.
 **********************************************************************************************************************/
static void FblCwInternalQueuedRequestTask(void);
#endif

#if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
/**********************************************************************************************************************
  FblCwInternalEthShutdown
 **********************************************************************************************************************/
/*! \brief        Ethernet shutdown task
 *  \details      This task function is used to shutdown an ETH stack.
 **********************************************************************************************************************/
static void FblCwInternalEthShutdown(void);
#endif

/**********************************************************************************************************************
  FblCwInternalPendingTask
 **********************************************************************************************************************/
/*! \brief        Request pending task handling
 *  \details      Task function in case a request is pending.
 **********************************************************************************************************************/
static void FblCwInternalPendingTask(void);




#if (FBLCW_DECLINED_REQUESTS == STD_ON)
/**********************************************************************************************************************
  Dcm_StartOfReception_Decline
**********************************************************************************************************************/
/*! \brief        Handle messge which should be declined
 *  \details      This function is called to decline a message
 *  \param[in]    id                       Received PDU id
 *  \param[in]    TpSduLength              Length of request
 *  \param[in]    bufferSizePtr            Pointer to length of receive buffer
**********************************************************************************************************************/
static BufReq_ReturnType Dcm_StartOfReception_Decline(PduIdType id, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) bufferSizePtr);
#endif

#if ( FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_ON )
/**********************************************************************************************************************
  FblCwInternalCheckForConnectionGroup
**********************************************************************************************************************/
/*! \brief        Check whether requested connection acts as broadcast for the current connection
 *  \param[in]    requestedConnection      Handle of requested connection
 *  \param[in]    currentConnection        Handle of current connection
**********************************************************************************************************************/
static boolean FblCwInternalCheckForConnectionGroup(FblCw_DcmDslConnectionInfoIterType requestedConnection, FblCw_DcmDslConnectionInfoIterType currentConnection);
#endif

#if ( FBLCW_DCMDSLBROADCASTGROUPINFO == STD_ON )
/**********************************************************************************************************************
  FblCwInternalCheckForBroadcastGroup
**********************************************************************************************************************/
/*! \brief        Check whether current and requested connection are both part of the same connection group
 *  \param[in]    requestedConnection      Handle of requested connection
 *  \param[in]    currentConnection        Handle of current connection
**********************************************************************************************************************/
static boolean FblCwInternalCheckForBroadcastGroup(FblCw_DcmDslConnectionInfoIterType requestedConnection, FblCw_DcmDslConnectionInfoIterType currentConnection);
#endif

#if ( FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_ON ) || \
    ( FBLCW_DCMDSLBROADCASTGROUPINFO == STD_ON )
/**********************************************************************************************************************
  FblCwInternalCheckRxPduAllowedInConnection
**********************************************************************************************************************/
/*! \brief        Check if received pdu is allowed for the given connection index
 *  \param[in]    requestedPduId           Received PDU id
 *  \param[in]    connectionIdx            Index of connection (into activeConnection array)
**********************************************************************************************************************/
static boolean FblCwInternalCheckRxPduAllowedInConnection(PduIdType requestedPduId, uint8_least connectionIdx);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FblCwInternalTransmitRP
**********************************************************************************************************************/
static void FblCwInternalTransmitRP(void)
{
  if (activeConnection[FBL_CW_MAIN_REQUEST_INDEX] != FBLCW_CONNECTION_UNASSIGNED)
  {
    /* Continue when no previous transmission is pending */
    if (cwTxState == kFblCwTxStateIdle)
    {
      /* Setup internal buffer and length of RCR-RP */
      txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduLength = kFblCwRcrRpMsgLength;
      txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = txBuffer;

      /* Set type of message for confirmation dispatching */
      cwTxState = kFblCwTxStateRpInProgress;

      /* Transmit RCR-RP */
#if ( FBLCW_MODULE_COMM == STD_ON )
      if (FALSE == cwComMChannelIsOnline[cwDcmComMChannelMapping[activeConnection[FBL_CW_MAIN_REQUEST_INDEX]]])
      {
        cwTxTimer = kFblCwTxPendingTimeout;
        cwTxState = kFblCwTxStateRpPending;

        /* Store request length for retransmission */
        cwTxPendingLength = (tCwDataLengthType) kFblCwRcrRpMsgLength;
        cwTxPendingBuffer = txBuffer;
      }
      else
#endif /* FBLCW_MODULE_COMM == STD_ON */
      {
        if (PduR_DcmTransmit(FblCw_GetTxRemotePduIdOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]), &txPdu[FBL_CW_MAIN_REQUEST_INDEX]) != E_OK)
        {
          /* Transmission request failed. Retry in timer task, observed by timeout */
          cwTxTimer = kFblCwTxPendingTimeout;
          cwTxState = kFblCwTxStateRpPending;

          /* Store request length for retransmission */
          cwTxPendingLength = (tCwDataLengthType) kFblCwRcrRpMsgLength;
          cwTxPendingBuffer = txBuffer;
        }
      }
    }
  }
}

/**********************************************************************************************************************
  FblCwInternalMainFunctionTimerTask
**********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
static void FblCwInternalMainFunctionTimerTask(void)
{
#if ( FBLCW_MODULE_COMM == STD_ON )
  vuintx i;
#endif

#if ( FBLCW_MODULE_LINSM == STD_ON )
# if ( LINIF_SW_MAJOR_VERSION >= 10u )
  FblCw_LinIfChannelsParamIterType  idx;
# endif
#endif

#if ( FBLCW_BUSNMRXINDDATA == STD_ON )
  /* Special functionality to trigger dummy NM messages for passive channels */
  if (!GetDiagDefaultSession())
  {
    vuint32 j;
    FblCw_BusNmRxIndDataIterType idx;
    vuint8 pduBuff[FblCw_GetSizeOfPduBuff()];
    PduInfoType pduInfo;

    for(j = 0u; j < FblCw_GetSizeOfPduBuff(); j++)
    {
      pduBuff[j] = 0u;
    }

    cwRxIndCycleTimer++;
    if (cwRxIndCycleTimer >= FblCw_GetBusNmRxIndCycleMs())
    {
      cwRxIndCycleTimer = 0u;
      pduInfo.SduDataPtr = pduBuff;

      for(idx = 0u; idx < FblCw_GetSizeOfBusNmRxIndData(); idx++)
      {
        pduInfo.SduLength = FblCw_GetSduLengthOfBusNmRxIndData(idx);
        /* Trigger RX notification for all passive channels */
        FblCw_GetBusNmRxIndFctPtrOfBusNmRxIndData(idx)(FblCw_GetPduInfoOfBusNmRxIndData(idx), &pduInfo);
      }
    }
  }
#endif /* FBLCW_BUSNMRXINDDATA == STD_ON */

#if ( FBLCW_MODULE_LINSM == STD_ON )
# if ( LINIF_SW_MAJOR_VERSION < 10u )

  /* Call LinIf main function if configured call cycle has expired */
  linIfCycleCounter++;
  if (linIfCycleCounter >=  LinIf_GlobalTimeBaseMS)
  {
    LinIf_MainFunction();

#   if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
#    if defined ( LINIF_MAINFUNC_POSTPROCESSING_MANUAL_HANDLING )
      /* Inform upper layers after processing of all channels to reduce jitter */
      LinIf_MainFunctionPostProcessing();
#    endif
#   endif

    linIfCycleCounter = 0u;
  }

# else /* LINIF_SW_MAJOR_VERSION < 10u */

  /* Loop over all LinIf channels */
  for (idx = 0u; idx < FblCw_GetSizeOfLinIfChannelsParamOfPCConfig(); idx++)
  {
    linIfCycleCounter[idx]++;

    /* Call LinIf main function if configured call cycle has expired */
    if (linIfCycleCounter[idx] >= FblCw_GetLinIfClusterTimeBaseOfLinIfChannelsParam(idx))
    {
      LinIf_ChannelMainFunction(FblCw_GetLinIfChannelIdOfLinIfChannelsParam(idx));

#   if ( LINIF_NODETYPE_MASTER_SUPPORTED == STD_ON )
#    if ( LINIF_MAINFUNC_POSTPROCESSING_MANUAL_HANDLING == STD_ON )
      /* Inform upper layers after processing of all channels to reduce jitter.
       * The channel parameter does not have to be a master LIN channel because in this case nothing is done. */
      LinIf_MainFunctionPostProcessingExternal(FblCw_GetLinIfChannelIdOfLinIfChannelsParam(idx));
#    endif
#   endif

      linIfCycleCounter[idx] = 0u;
    }
  }

# endif /* LINIF_SW_MAJOR_VERSION < 10u */

  /* Call LinSM main function if configured call cycle has expired */
  linSmCycleCounter++;
  if (linSmCycleCounter >=  LINSM_MAIN_FUNCTION_PERIOD)
  {
    LinSM_MainFunction();
    linSmCycleCounter = 0u;
  }

#endif /* FBLCW_MODULE_LINSM == STD_ON */

  /* Execute communication stack tasks */
#if ( FBLCW_TASK_CYCLE > 1u )
  /* Call task functions with longer cycle time */
  cycleCounter++;

  if (cycleCounter >= FBLCW_TASK_CYCLE)
  {
    cycleCounter = 0u;
#else
  {
#endif
#if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
    /* CAN TP task */
    CanTp_MainFunction();
#endif
#if ( FBLCW_MODULE_CANNM == STD_ON )
    /* CAN Nm task */
    CanNm_MainFunction();
#endif
#if ( FBLCW_MODULE_CANSM == STD_ON )
    /* CAN SM task */
    CanSM_MainFunction();
#endif

#if ( FBLCW_MODULE_ETHSM == STD_ON )
    /* Ethernet tasks */
    EthIf_MainFunctionState();
    EthSM_MainFunction();
# if defined(FBLCW_ETHSWT_MAINFUNCTION)
    FBLCW_ETHSWT_MAINFUNCTION();
# endif
# if defined(FBLCW_ETHTRCV_MAINFUNCTION)
    FBLCW_ETHTRCV_MAINFUNCTION();
# endif
# if defined(FBLCW_ETHTRCV_MAINFUNCTION_LINKHANDLING)
    FBLCW_ETHTRCV_MAINFUNCTION_LINKHANDLING();
# endif
#endif /* FBLCW_MODULE_ETHSM == STD_ON */
#if ( FBLCW_MODULE_FRSM == STD_ON )
    /* FlexRay SM task */
    for (i = 0; i < FrIf_CommonMaxNumberOfClusters; i++)
    {
       FrSM_MainFunction((FrSM_SizeOfVarStructType)i);
    }

# if ( FBLCW_KEY_SLOT_MODE == STD_ON )
    /* Start timer */
    cwNwStatusTimeoutCtr++;
# endif
#endif /* FBLCW_MODULE_FRSM == STD_ON */

#if ( FBLCW_MODULE_COMM == STD_ON )
    /* Execute ComM main functions */
    for (i = 0u; i < FBLCW_NO_COMM_CHANNELS; i++)
    {
       ComM_MainFunction((NetworkHandleType)i);
    }
#endif
  }

  /* Ethernet tasks */
# if ( FBLCW_MODULE_SOAD == STD_ON )
  SoAd_MainFunction();
# endif
# if ( FBLCW_MODULE_DOIP == STD_ON )
  DoIP_MainFunction();
# endif
# if ( FBLCW_MODULE_DOIPINT == STD_ON )
  DoIPInt_MainFunction();
# endif
# if ( FBLCW_MODULE_TCPIP == STD_ON )
  TcpIp_MainFunction();
# endif

  /* XCP tasks */
#if ( FBLCW_MODULE_XCP == STD_ON )
  if (GetXcpEnabled())
  {
    Xcp_MainFunction();
# if ( FBLCW_MODULE_CANXCP == STD_ON )
    CanXcp_MainFunction();
# endif
# if ( FBLCW_MODULE_TCPIPXCP == STD_ON )
    TcpIpXcp_MainFunction();
# endif
# if ( FBLCW_MODULE_FRXCP == STD_ON )
    FrXcp_MainFunctionRx();
    FrXcp_MainFunctionTx();
# endif
  }
#endif /* FBLCW_MODULE_XCP == STD_ON */

#if ( FBLCW_EXISTS_CDD_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
  /* Complex device driver timer task(s) */
  FBL_CW_CDD_TIMER_TASK();
#endif
}

#if ( FBLCW_QUEUED_REQUEST == STD_ON )
/**********************************************************************************************************************
  FblCwInternalQueuedRequestTask
**********************************************************************************************************************/
static void FblCwInternalQueuedRequestTask(void)
{
  /* Ensure that request is handled on correct connection */
  activeConnection[FBL_CW_MAIN_REQUEST_INDEX] = cwQueuedRequestConnection;

  FblDiagRxStartIndication();

  /* Reinitialize data pointer */
  rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = FblDiagRxGetPhysBuffer((tCwDataLengthType) rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduLength);

  assertFbl((rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr != NULL_PTR), kFblSysAssertNoBufferAvailable);    /* PRQA S 2214 */ /* MD_FblAssert_Assertion */

  /* Check validity of data pointer */
  if (rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr != NULL_PTR)
  {
    if (GetCwRxIndPending())
    {
      /* If the indication is already pending, this should be a single frame */
      assertFbl((rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduLength == cwQueuedRequestLength), kFblSysAssertParameterOutOfRange);     /* PRQA S 2214 */ /* MD_FblAssert_Assertion */

      ClrCwRxIndPending();

      /* Copy queued Rx data to diag buffer */ /* PRQA S 0314 1 */ /* MD_FblCw_0314_MemCpy */
      (void) MEMCPY(rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr, cwQueuedRequestBuffer, cwQueuedRequestLength);

      /* Advance data pointer */
      rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = &rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr[cwQueuedRequestLength];

      /*
       * Set flag before call of FblDiagRxIndication() to account for special
       * case TesterPresent with SPRMIB.
       */
      SetCwMsgInProcess();

      /* Rx indication already pending. Dequeue message and start processing immediately */
      FblDiagRxIndication(DiagBuffer, rxDataLength[FBL_CW_MAIN_REQUEST_INDEX]);
    }
    else
    {
      /* Multi frame */
      /* Copy queued Rx data to diag buffer */ /* PRQA S 0314 1 */ /* MD_FblCw_0314_MemCpy */
      (void) MEMCPY(rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr, cwQueuedRequestBuffer, cwQueuedRequestLength);

      /* Advance data pointer */
      rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = &rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr[cwQueuedRequestLength];

      /* Adapt remaining buffer size */
      rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX] = (PduLengthType) FBL_DIAG_BUFFER_LENGTH - cwQueuedRequestLength;
    }

    ClrCwMsgQueued();
  }
  else
  {
    /* No buffer available, retry on next cycle. */
  }
}
#endif /* FBLCW_QUEUED_REQUEST == STD_ON */

#if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
/**********************************************************************************************************************
  FblCwInternalEthShutdown
**********************************************************************************************************************/
static void FblCwInternalEthShutdown(void)
{
  /* Check shutdown timer */
  if ((0u != cwShutdownTimer) && (kFblCwShutdownRequested == cwShutdownState))
  {
    /* Poll shutdown function and check if communication is shut down or if an error occured */
# if ( FBLCW_MODULE_DOIP == STD_ON )
    switch (DoIP_Shutdown())
# else
    switch (SoAd_Shutdown())
# endif
    {
      case E_OK:
      {
        /* Connections are shut down: perform a reset */
        cwShutdownState = kFblCwShutdownFinished;
        break;
      }
      case SOAD_E_INPROGRESS:
      {
        /* Shutdown is still in progress */
        break;
      }
      default:
      {
        /* Failed or invalid return value: perform a reset */
        cwShutdownState = kFblCwShutdownFinished;
        break;
      }
    }

    /* Timeout handling */
    cwShutdownTimer--;

    if (0u == cwShutdownTimer)
    {
      /* Shutdown timeout expired, perform a reset anyway */
      cwShutdownState = kFblCwShutdownFinished;
    }

    /* Shutdown sequence finished */
    if (kFblCwShutdownFinished == cwShutdownState)
    {
      /* Perform reset */
      FblSetShutdownRequest();

      /* Reset shutdown state and timer */
      cwShutdownState = kFblCwNoShutdownRequest;
      cwShutdownTimer = 0u;
    }
  }
}
#endif /* FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */

/**********************************************************************************************************************
  FblCwInternalPendingTask
**********************************************************************************************************************/
static void FblCwInternalPendingTask(void)
{
  vuint8 msgType;
  vuint8 newTxState;

  /* Message type and follow-up state differ depending on current state */
  if (kFblCwTxStateRpPending == cwTxState)
  {
    msgType = kFblCwMsgTypeRcrRp;
    newTxState = kFblCwTxStateRpInProgress;
  }
  else
  {
    msgType = kFblCwMsgTypeNormal;
    newTxState = kFblCwTxStateTxInProgress;
  }

  /* Check if the timer is expired */
  if (cwTxTimer == 0u)
  {
    /* Transmission timeout, reset state */
    cwTxState = kFblCwTxStateIdle;
    /* Report error */
    FblDiagTxErrorIndication(msgType);
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
    /* Clear message in process state */
    ClrCwMsgInProcess();
#endif /* FBLCW_QUEUED_REQUEST == STD_ON */
  }
  else
  {
    /* Remember current Tx state */
    vuint8 prevTxState = cwTxState;
    /* Change state before call to TpTransmit because indication may be triggered within the function */
    cwTxState = newTxState;

    /* Setup transmission data */
    txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduLength = (PduLengthType) cwTxPendingLength;
    txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = cwTxPendingBuffer;

#if ( FBLCW_MODULE_COMM == STD_ON )
    if (TRUE == cwComMChannelIsOnline[cwDcmComMChannelMapping[activeConnection[FBL_CW_MAIN_REQUEST_INDEX]]])
#endif
    {
      /* Retry transmission */
      if (PduR_DcmTransmit(FblCw_GetTxRemotePduIdOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]), &txPdu[FBL_CW_MAIN_REQUEST_INDEX]) != E_OK)
      {
        /* Still unsuccessful: revert to previous state */
        cwTxState = prevTxState;
      }
      else
      {
        /* Now successful. Stop the timer */
        cwTxTimer = 0u;
      }
#if ( FBLCW_TX_PROCESSING == FBLCW_POLLING )
      /* Immediate polling of Tx task */
      FBLCW_CAN_MAINFUNCTION_WRITE();
#endif
    }
#if ( FBLCW_MODULE_COMM == STD_ON )
    else
    {
      /* Revert to previous state */
      cwTxState = prevTxState;
    }
#endif
  }
}

#if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
# if ( FBLCW_MODULE_COMM == STD_OFF ) || \
     ( FBLCW_BAUDRATE_SWITCH == STD_ON )
/**********************************************************************************************************************
  FblCwCanIfSetMode
**********************************************************************************************************************/
static void FblCwCanIfSetMode(uint8 controllerId, CanIf_ControllerModeType mode)
{
  Std_ReturnType result;
  CanIf_ControllerModeType currentMode;

  /* Evaluate current controller mode */
  result = CanIf_GetControllerMode(controllerId, &currentMode);
  assertFblInternal((E_OK == result), kFblSysAssertParameterOutOfRange);        /* PRQA S 2214 */ /* MD_FblAssert_Assertion */

  /* Perform mode switch unless requested mode already active */
  if ((E_OK == result) && (mode != currentMode))
  {
    vuint16 maxWaitTime = kFblCwMaxWaitTime;
    /* Request new controller mode */
    result = CanIf_SetControllerMode(controllerId, mode);
    assertFblInternal((E_OK == result), kFblSysAssertParameterOutOfRange);      /* PRQA S 2214 */ /* MD_FblAssert_Assertion */

    while ((E_OK == result) && (mode != currentMode) && (maxWaitTime > 0u))
    {
      if (FBL_NO_TRIGGER != FblLookForWatchdog())
      {
        maxWaitTime--;
      }

      /* Perform mode switch handling */
      FBLCW_CAN_MAINFUNCTION_MODE();
      /* Re-evaluate current controller mode */
      result = CanIf_GetControllerMode(controllerId, &currentMode);
      assertFblInternal((E_OK == result), kFblSysAssertParameterOutOfRange);    /* PRQA S 2214 */ /* MD_FblAssert_Assertion */
    }
  }
}
# endif /* (FBLCW_MODULE_COMM == STD_OFF) || (FBLCW_BAUDRATE_SWITCH == STD_ON) */
#endif /* FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */





#if (FBLCW_DECLINED_REQUESTS == STD_ON)
/**********************************************************************************************************************
  Dcm_StartOfReception_Decline
**********************************************************************************************************************/
static BufReq_ReturnType Dcm_StartOfReception_Decline(PduIdType id, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) bufferSizePtr)
{
  BufReq_ReturnType result = BUFREQ_E_NOT_OK;
  uint8_least connectionIndex;

  for (connectionIndex = 1u; connectionIndex < kFblCwNumberOfRequests; connectionIndex++)
  {
    if (FBLCW_CONNECTION_UNASSIGNED == activeConnection[connectionIndex])
    {
      activeConnection[connectionIndex] = FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(id);
    }

    if (FblCw_CheckRxPduAllowedInConnection(id, connectionIndex))
    {
      if (TpSduLength <= FBL_DIAG_DECLINE_BUFFER_LENGTH)
      {
        rxPduPhys[connectionIndex].SduDataPtr = FblDiagRxGetDeclineBuffer((tCwDataLengthType) TpSduLength, connectionIndex);
        rxBuffer[connectionIndex] = rxPduPhys[connectionIndex].SduDataPtr;
        rxRemainingBufferSize[connectionIndex] = (PduLengthType) FBL_DIAG_DECLINE_BUFFER_LENGTH;

        activeConnection[connectionIndex] = FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(id);

        if (NULL_PTR != rxPduPhys[connectionIndex].SduDataPtr)
        {
          rxPduPhys[connectionIndex].SduLength = TpSduLength;
          *bufferSizePtr = rxRemainingBufferSize[connectionIndex];

          /* Store the number of bytes to be received */
          rxDataLength[connectionIndex] = TpSduLength;
          result = BUFREQ_OK;
        }
        else
        {
          /* No buffer available */
        }
      }
      else
      {
        result = BUFREQ_E_OVFL;
      }
      break;
    }
  }

  return result;
}
#endif /* FBLCW_DECLINED_REQUESTS == STD_ON */

#if ( FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_ON )
/**********************************************************************************************************************
  FblCwInternalCheckForConnectionGroup
**********************************************************************************************************************/
static boolean FblCwInternalCheckForConnectionGroup(FblCw_DcmDslConnectionInfoIterType requestedConnection, FblCw_DcmDslConnectionInfoIterType currentConnection)
{
  boolean result = FALSE;

  /* Is current connection part of a connection group? */
  if (FblCw_IsDcmDslConnectionGroupInfoIndUsedOfDcmDslConnectionInfo(currentConnection)) /* PRQA S 4304 */ /* MD_FblCw_4304_BooleanCast */
  {
    FblCw_DcmDslConnectionGroupInfoIndIterType  currentIdx;
    FblCw_DcmDslConnectionGroupInfoIndIterType  requestedIdx;
    FblCw_DcmDslConnectionGroupInfoIndType      currentGroup;

    /* Check whether current and requested connection are both part of the same connection group. */
    /* Loop all connection groups of which the current connection is a member. */
    for ( currentIdx = FblCw_GetDcmDslConnectionGroupInfoIndStartIdxOfDcmDslConnectionInfo(currentConnection);
          currentIdx < FblCw_GetDcmDslConnectionGroupInfoIndEndIdxOfDcmDslConnectionInfo(currentConnection);
          currentIdx++)
    {
      currentGroup = FblCw_GetDcmDslConnectionGroupInfoInd(currentIdx);

      /* Loop all connection groups of which the requested connection is a member. */
      for ( requestedIdx = FblCw_GetDcmDslConnectionGroupInfoIndStartIdxOfDcmDslConnectionInfo(requestedConnection);
            requestedIdx < FblCw_GetDcmDslConnectionGroupInfoIndEndIdxOfDcmDslConnectionInfo(requestedConnection);
            requestedIdx++)
      {
        /* Same connection group? */
        if (currentGroup == FblCw_GetDcmDslConnectionGroupInfoInd(requestedIdx))
        {
          result = TRUE;

          /* Leave loop as match was found. */
          break;
        }
      }

      /* Leave loop as match was found. */
      if (result == TRUE)
      {
        break;
      }
    }
  }

  return result;
}
#endif /* FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_ON */

#if ( FBLCW_DCMDSLBROADCASTGROUPINFO == STD_ON )
/**********************************************************************************************************************
  FblCwInternalCheckForBroadcastGroup
**********************************************************************************************************************/
static boolean FblCwInternalCheckForBroadcastGroup(FblCw_DcmDslConnectionInfoIterType requestedConnection, FblCw_DcmDslConnectionInfoIterType currentConnection)
{
  boolean result = FALSE;

  /* Preconditions for broadcast group match:
    * - Requested connection must be the broadcast reference of a broadcast group
    * - Current connection must be a surrogate reference of this broadcast group */
  /* PRQA S 4304 2 */ /* MD_FblCw_4304_BooleanCast */
  if ( FblCw_IsDcmDslBroadcastGroupInfoUsedOfDcmDslConnectionInfo(requestedConnection)
    && FblCw_IsDcmDslBroadcastGroupInfoIndUsedOfDcmDslConnectionInfo(currentConnection) )
  {
    FblCw_DcmDslBroadcastGroupInfoIndIterType currentIdx;
    FblCw_DcmDslBroadcastGroupInfoIdxOfDcmDslConnectionInfoType broadcastGroup;

    /* Evaluate broadcast group of requested connection. */
    broadcastGroup = FblCw_GetDcmDslBroadcastGroupInfoIdxOfDcmDslConnectionInfo(requestedConnection);

    /* Loop all broadcast groups of which the current connection is a member. */
    for ( currentIdx = FblCw_GetDcmDslBroadcastGroupInfoIndStartIdxOfDcmDslConnectionInfo(currentConnection);
          currentIdx < FblCw_GetDcmDslBroadcastGroupInfoIndEndIdxOfDcmDslConnectionInfo(currentConnection);
          currentIdx++)
    {
      /* Same broadcast group? */
      if (broadcastGroup == FblCw_GetDcmDslBroadcastGroupInfoInd(currentIdx))
      {
        result = TRUE;

        /* Leave loop as match was found. */
        break;
      }
    }
  }

  return result;
}
#endif /* FBLCW_DCMDSLBROADCASTGROUPINFO == STD_ON */

#if ( FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_ON ) || \
    ( FBLCW_DCMDSLBROADCASTGROUPINFO == STD_ON )
/**********************************************************************************************************************
  FblCwInternalCheckRxPduAllowedInConnection
**********************************************************************************************************************/
static boolean FblCwInternalCheckRxPduAllowedInConnection(PduIdType requestedPduId, uint8_least connectionIdx)
{
  boolean result;
  FblCw_DcmDslConnectionInfoIterType currentConnection;
  FblCw_DcmDslConnectionInfoIterType requestedConnection;

  /* Get connection handler. */
  currentConnection   = activeConnection[connectionIdx];

  /* Requested PDU directly associated with connection? */
  if (FblCw_CheckRxPduAllowedInActiveConnection(requestedPduId, currentConnection))
  {
    result = TRUE;
  }
  else
  {
    /* Evaluate connection of requested PDU. */
    requestedConnection = FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(requestedPduId);

# if ( FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_ON )
    /* Check whether current and requested connection are both part of the same connection group. */
    result = FblCwInternalCheckForConnectionGroup(requestedConnection, currentConnection);

    /* Skip broadcast groups if requested connection already matched a connection group. */
    if (result != TRUE)
# endif /* FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_ON */
    {
# if ( FBLCW_DCMDSLBROADCASTGROUPINFO == STD_ON )
      /* Check whether requested connection acts as broadcast for the current connection. */
      result = FblCwInternalCheckForBroadcastGroup(requestedConnection, currentConnection);
# endif /* FBLCW_DCMDSLBROADCASTGROUPINFO == STD_ON */
    }
  }

  return result;
}
#endif /* (FBLCW_DCMDSLCONNECTIONGROUPINFO == STD_ON) || (FBLCW_DCMDSLBROADCASTGROUPINFO == STD_ON) */

/**********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  FblCwTransmitRP
**********************************************************************************************************************/
void FblCwTransmitRP(const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data)
{
  /* Continue when no previous transmission is pending */
  if (cwTxState == kFblCwTxStateIdle)
  {
    vuintx i;
    /* Copy RCR-RP message to internal buffer, required for later retransmission */
    for (i = 0u; i < kFblCwRcrRpMsgLength; i++)
    {
      txBuffer[i] = data[i];
    }
    /* Trigger transmission */
    FblCwInternalTransmitRP();
  }
}

/**********************************************************************************************************************
  FblCwRetransmitRP
**********************************************************************************************************************/
void FblCwRetransmitRP(void)
{
  /* Trigger re-transmission */
  FblCwInternalTransmitRP();
}

/**********************************************************************************************************************
  FblCwTimerTask
**********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
void FblCwTimerTask(void)
{
  /* Check if communication wrapper is initialized */
  if (FblCw_IsInitialized())
  {
    /* Prevent nested task execution */
    if (IsCwTimerTaskAllowed())
    {
      SetCwTimerTaskRunning();



      FblCwInternalMainFunctionTimerTask();

      /* Active timeout indicates pending transmission operation */
      if (cwTxTimer != 0u)
      {
        /* Decrement timer */
        cwTxTimer--;

        /* Evaluate transmission state */
        switch (cwTxState)
        {
          case kFblCwTxStateIdle:
          case kFblCwTxStateRpInProgress:
          case kFblCwTxStateTxInProgress:
          {
            /* Timer is irrelevant in these states */
            cwTxTimer = 0u;
            break;
          }
          case kFblCwTxStateTxPendingWaitForConf:
          {
            /* Check if the timer is expired */
            if (cwTxTimer == 0u)
            {
              /* Transmission timeout, reset state */
              cwTxState = kFblCwTxStateIdle;
              /* Report error */
              FblDiagTxErrorIndication(kFblCwMsgTypeNormal);
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
              /* Clear message in process state */
              ClrCwMsgInProcess();
#endif /* FBLCW_QUEUED_REQUEST == STD_ON */
            }
            break;
          }
          case kFblCwTxStateRpPending:
          case kFblCwTxStateTxPending:
          {
            FblCwInternalPendingTask();
            break;
          }
          default:
          {
            /* Illegal state */
            cwTxState = kFblCwTxStateIdle;
            cwTxTimer = 0u;
            break;
          }
        }
      }

#if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
      FblCwInternalEthShutdown();
#endif

      /* Allow further task executions */
      ClrCwTimerTaskRunning();
    }
  }
}

/**********************************************************************************************************************
  FblCwStateTask
**********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
void FblCwStateTask(void)
{
#if ( FBLCW_MODULE_FRSM == STD_ON ) || \
    ( FBLCW_MODULE_COMM == STD_ON )
  vuintx i;
#endif /* FBLCW_MODULE_FRSM == STD_ON || FBLCW_MODULE_COMM == STD_ON */

  /* Check if communication wrapper is initialized */
  if (FblCw_IsInitialized())
  {
    /* Prevent nested task execution */
    if (IsCwStateTaskAllowed())
    {
      SetCwStateTaskRunning();

#if (FBLCW_MODULE_COMM == STD_ON)
      if (cwCommInitializationFinished == FALSE)
      {
        /* Perform final ComM related init steps (after ComM_PostInit) */
        for (i = 0u; i < FblCw_GetSizeOfDcmDslConnectionInfo(); i++)
        {
# if ( FBLCW_NO_COMM_CHANNELS == 1u)
          /* Only one ComM channel configured. Map all diagnostic channels to ComM channel 0 */
          cwDcmComMChannelMapping[i] = FBLCW_COMM_CHANNEL;
# else
          cwDcmComMChannelMapping[i] = FblCw_GetCwDcmComMChannelMapping(i);
# endif
        }

        /* Wake-up all configured ComM channels. Bootloader is configured to passive NM and shouldn't wake up other channels. */
        for (i = 0u; i < FBLCW_NO_COMM_CHANNELS; i++)
        {
          cwComMChannelIsOnline[i] = FALSE;
# if ( COMM_ENABLEDOFCHANNEL == STD_ON )
          if (ComM_IsEnabledOfChannel(i))
# endif /* COMM_ENABLEDOFCHANNEL == STD_ON */
          {
            (void)ComM_CommunicationAllowed((NetworkHandleType)i, TRUE);
            (void)ComM_EcuM_WakeUpIndication((NetworkHandleType)i);
          }
        }
        cwCommInitializationFinished = TRUE;
      }
#endif /* FBLCW_MODULE_COMM == STD_ON */

#if ( FBLCW_QUEUED_REQUEST == STD_ON )
      /* Check if a request is pending */
      if (GetCwMsgQueued() && (!GetCwMsgInProcess()))
      {
        FblCwInternalQueuedRequestTask();
      }
#endif

#if ( FBLCW_MODULE_LINSM == STD_ON )
      FBLCW_LIN_MAINFUNCTION_POLL();
#endif

#if ( FBLCW_TX_PROCESSING == FBLCW_POLLING)
      /* Remark: When interrupts are used, those have to be disabled until confirmation handling has been
         finished completely (avoid nested call of Tx task).
         This should be handled by the driver or the respective critical section (schedule manager)
         NOTE: Depending on configuration all interrupts are disabled (that means that e.g. a timer interrupt
         will also be affected)!
         */
      FBLCW_CAN_MAINFUNCTION_WRITE();
#endif

#if ( FBLCW_RX_PROCESSING == FBLCW_POLLING)
      /* Polling of CAN receive messages */
      FBLCW_CAN_MAINFUNCTION_READ();
#endif


#if ( FBLCW_MODULE_ETHSM == STD_ON )
      /* Ethernet tasks */
      EthIf_MainFunctionTx();
      EthIf_MainFunctionRx();
#endif /* FBLCW_MODULE_ETHSM == STD_ON */

#if ( FBLCW_MODULE_FRSM == STD_ON )
      for (i = 0; i < FrIf_CommonMaxNumberOfClusters; i++)
      {
# if ( FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON )
         FrIf_MainFunction();
# else
         FrIf_MainFunction((uint8)i);
# endif
      }

# if ( FRIF_CUSTOM_JLE_SCHEDULING == STD_ON )
      /* Start job list execution */
      FrIf_CustomJLEHandling();
# endif
#endif /* FBLCW_MODULE_FRSM == STD_ON */

#if ( FBLCW_EXISTS_CDD_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
      FBL_CW_CDD_STATE_TASK();
#endif

      /* Allow further task executions */
      ClrCwStateTaskRunning();
    }
  }
}

/**********************************************************************************************************************
  FblCwIdleTask
**********************************************************************************************************************/
void FblCwIdleTask(void)
{
#if ( FBLCW_BUSOFF_PROCESSING == FBLCW_POLLING )
  /* Polling of CAN error task */
   FBLCW_CAN_MAINFUNCTION_BUSOFF();
#endif

#if ( FBLCW_MODULE_FRSM == STD_ON )
  if (FblCwGetWakeUpEvent())
  {
    /* Check for wake-up event */
    if (kFblOk == ApplFblCwWakeUp())
    {
      /* Wakeup request received, start communication */
      (void) FrSM_RequestComMode(FrSM_ClusterConfig[0].NetworkHandleOfClusterConfig, COMM_FULL_COMMUNICATION);

      /* Set transceiver in normal mode */
      ApplTrcvrNormalMode();

      /* Clear flag to wait for wake-up event */
      FblCwClrWakeUpEvent();
    }
  }

# if ( FBLCW_KEY_SLOT_MODE == STD_ON )
  /* Call network status to determine if the application or bootloader schedule shall be executed */
  if (activeConnection[FBL_CW_MAIN_REQUEST_INDEX] != FBLCW_CONNECTION_UNASSIGNED)
  {
    FblCwCheckNwStatus();
  }
# endif /* FBLCW_KEY_SLOT_MODE == STD_ON */
#endif /* FBLCW_MODULE_FRSM == STD_ON */
}

/**********************************************************************************************************************
  FblCw_InitMemory
**********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_InitMemory(void)
{
  /* #10 Initialize all component _INIT_ variables. */
  FblCw_SetInitialized(FALSE);
#if (FBLCW_USE_INIT_POINTER == STD_ON)
  FblCw_ConfigDataPtr = NULL_PTR;
#endif

#if( FBLCW_MODULE_COMM == STD_ON )
  cwCommInitializationFinished = FALSE;
#endif /* FBLCW_MODULE_COMM == STD_ON */

}

/**********************************************************************************************************************
  FblCw_Init
**********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
**********************************************************************************************************************/
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(void, FBLCW_CODE) FblCw_Init(P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) config)
{
  uint8_least initializationIndex;

#if (FBLCW_USE_INIT_POINTER == STD_ON)
  assertFblInternal((config != NULL_PTR), kFblSysAssertParameterOutOfRange);    /* PRQA S 2214 */ /* MD_FblAssert_Assertion */
  FblCw_ConfigDataPtr = config;
#endif

#if ( FBLCW_MODULE_FRSM == STD_ON )
# if ( FBLCW_KEY_SLOT_MODE == STD_ON )
   /* If's a warm start the network timeout is equal S3 timeout
   * and starts in all slot mode */

  if (FblMainGetStartFromAppl())
  {
    cwNwStatusTimeout = (vuint16)( TESTER_PRESENT_TIMEOUT / FBLCW_TASK_CYCLE );
    /* Invoke state transition to full communication ("All Slots" mode) */
    cwAllSlots = FBL_CW_ALL_SLOT_MODE_REQUESTED;
  }
  else
  {
    cwNwStatusTimeout = ( FBL_CW_NW_STATUS_TIMEOUT / FBLCW_TASK_CYCLE );
    cwAllSlots = FBL_CW_KEY_SLOT_MODE;
  }
  cwNwStatusTimeoutCtr = 0u;
# endif /* FBLCW_KEY_SLOT_MODE == STD_ON */
  FblCwClrWakeUpEvent();
#endif /* FBLCW_MODULE_FRSM == STD_ON */

#if ( FBLCW_BUSNMRXINDDATA == STD_ON )
  cwRxIndCycleTimer = 0u;
#endif

  /* Init local variables */
#if ( FBLCW_TASK_CYCLE > 1u )
  cycleCounter = 0u;
#endif
#if ( FBLCW_MODULE_LINSM == STD_ON )
  /* Initialize linIfCycleCounter and linSmCycleCounter variable */
# if ( LINIF_SW_MAJOR_VERSION < 10u )
  linIfCycleCounter = 0u;
# else
  for (initializationIndex = 0u; initializationIndex < FblCw_GetSizeOfLinIfChannelsParamOfPCConfig(); initializationIndex++)
  {
    linIfCycleCounter[initializationIndex] = 0u;
  }
# endif
  linSmCycleCounter = 0u;
#endif
  cwTxTimer = 0u;
  cwTxState = kFblCwTxStateIdle;
  cwTaskState = 0u;

#if ( FBLCW_QUEUED_REQUEST == STD_ON )
  cwQueuedRequestFlags = 0;
#endif

#if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
  cwCanHardwareLoopTimer = 0u;
#endif

#if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
  cwShutdownState = kFblCwNoShutdownRequest;
  cwShutdownTimer = 0u;
#endif

  /* Initialize connection state variables */
  for (initializationIndex = 0u; initializationIndex < kFblCwNumberOfRequests; initializationIndex++)
  {
    activeConnection[initializationIndex] = FBLCW_CONNECTION_UNASSIGNED;
  }

#if defined( FBL_DEF_ENABLE_NON_KB_MAIN )
   /* Call standard transceiver initialization. */
   ApplTrcvrNormalMode();
#endif /* FBL_DEF_ENABLE_NON_KB_MAIN */

#if( FBLCW_MODULE_COMM == STD_OFF )
# if ( FBLCW_CANIFCTRLINFO == STD_ON )
  /* Switch all configured CAN controllers to online mode */
  {
    FblCw_CanIfCtrlInfoIterType canIfCtrlIdx;


    /* Switch all configured CAN controllers to online mode */
    for (canIfCtrlIdx = 0u; canIfCtrlIdx < FblCw_GetSizeOfCanIfCtrlInfo(); canIfCtrlIdx++)
    {
      uint8 currentChannel;
      currentChannel = FblCw_GetCanIfCtrlInfo(canIfCtrlIdx);

      FblCwCanIfSetMode(currentChannel, CANIF_CS_STARTED);


      {
        (void) CanIf_SetPduMode(currentChannel, CANIF_SET_ONLINE);
      }
    }
  }
# endif /* FBLCW_CANIFCTRLINFO == STD_ON */
#endif /* FBLCW_MODULE_COMM == STD_OFF */

#if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
# if ( CANTP_ENABLE_READ_PARAM == STD_ON )
  {
    FblCw_DcmDslConnectionInfoIterType dcmDslConnectionInfoIdx;
    for (dcmDslConnectionInfoIdx = 0u; dcmDslConnectionInfoIdx < FblCw_GetSizeOfDcmDslConnectionInfo(); dcmDslConnectionInfoIdx++)
    {
      if (FblCw_IsParameterInfoUsedOfDcmDslConnectionInfo(dcmDslConnectionInfoIdx)) /* PRQA S 4304 */ /* MD_FblCw_4304_BooleanCast */
      {
        FblCw_ParameterInfoIterType parameterInfoIdx;
        parameterInfoIdx = FblCw_GetParameterInfoIdxOfDcmDslConnectionInfo(dcmDslConnectionInfoIdx);

        (void) CanTp_ReadParameter(FblCw_GetCanTpIdOfParameterInfo(parameterInfoIdx), TP_BS, FblCw_GetAddrInitialBS(parameterInfoIdx));

        (void) CanTp_ReadParameter(FblCw_GetCanTpIdOfParameterInfo(parameterInfoIdx), TP_STMIN, FblCw_GetAddrInitialSTmin(parameterInfoIdx));

      }
    }
  }
# endif /* CANTP_ENABLE_READ_PARAM == STD_ON */
#endif /* FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */

  FblCw_SetInitialized(TRUE);
  FBLCW_DUMMY_STATEMENT_CONST(config);        /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
  FblCw_Deinit
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_Deinit(void)
{
#if ( FBLCW_MODULE_FRSM == STD_ON )
  vuintx i;
  /* Stop communication, set halt state */
  (void) FrSM_RequestComMode(FrSM_ClusterConfig[0].NetworkHandleOfClusterConfig, COMM_NO_COMMUNICATION);
  for (i = 0; i < FrIf_CommonMaxNumberOfClusters; i++)
  {
     FrSM_MainFunction((FrSM_SizeOfVarStructType)i);
  }
#endif /* FBLCW_MODULE_FRSM == STD_ON */
  FblCw_SetInitialized(FALSE);
}

/**********************************************************************************************************************
  FblCwPduTransmit
**********************************************************************************************************************/
void FblCwPduTransmit(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data, tCwDataLengthType length)
{
  /* Wait in case response pending is in progress */
  vuint16 maxWaitTime = kFblCwMaxWaitTime;

  /* Retransmit response in FblCwStateTask if necessary */
  while ((maxWaitTime > 0u) && (cwTxState != kFblCwTxStateIdle))
  {
    if (FBL_NO_TRIGGER != FblLookForWatchdog())
    {
      maxWaitTime--;
    }
  }

  /* Check if diagnostic buffer is still locked - may be released due to error indication. */
  if ((activeConnection[FBL_CW_MAIN_REQUEST_INDEX] != FBLCW_CONNECTION_UNASSIGNED) && (GetDiagBufferLocked()))
  {
    /* Setup timer for possible retransmission */
    cwTxTimer = kFblCwTxPendingTimeout;

    /* Store request data for possible retransmission */
    cwTxPendingLength = length;
    cwTxPendingBuffer = data;

    switch (cwTxState)
    {
        /* Previous transmission still in progress */
      case kFblCwTxStateRpInProgress:
      case kFblCwTxStateTxInProgress:
      {
        /* Setup state for retransmission */
        cwTxState = kFblCwTxStateTxPendingWaitForConf;
        break;
      }
        /* No previous transmission in progress or not started yet */
      default:
      {
        /* Setup transmission data */
        txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduLength = (PduLengthType) length;
        txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = data;

#if ( FBLCW_MODULE_COMM == STD_ON )
        if (TRUE == cwComMChannelIsOnline[cwDcmComMChannelMapping[activeConnection[FBL_CW_MAIN_REQUEST_INDEX]]])
#endif
        {
          /* Set type of message for confirmation dispatching */
          cwTxState = kFblCwTxStateTxInProgress;

          /* Transmit message */
          if (PduR_DcmTransmit(FblCw_GetTxRemotePduIdOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]), &txPdu[FBL_CW_MAIN_REQUEST_INDEX]) != E_OK)
          {
            /* Transmission request failed, setup state for retransmission */
            cwTxState = kFblCwTxStateTxPending;
          }
        }
#if ( FBLCW_MODULE_COMM == STD_ON )
        else
        {
          /* Transmission not possible, setup state for retransmission */
          cwTxState = kFblCwTxStateTxPending;
        }
#endif /* FBLCW_MODULE_COMM == STD_ON */
        break;
      }
    }
  }
  else
  {
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
    /* Clear messages in process state and queued */
    ClrCwMsgInProcess();
    ClrCwMsgQueued();
    ClrCwRxIndPending();
#endif
  }
#if ( FBLCW_TX_PROCESSING == FBLCW_POLLING )
  FBLCW_CAN_MAINFUNCTION_WRITE();
#endif
}


#if (FBLCW_DECLINED_REQUESTS == STD_ON)
/**********************************************************************************************************************
 FblCwPduTransmitDeclinedRequest
 *********************************************************************************************************************/
void FblCwPduTransmitDeclinedRequest(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data, tCwDataLengthType length, vuint8 connectionIndex)
{
  if (activeConnection[connectionIndex] != FBLCW_CONNECTION_UNASSIGNED)
  {
    /* Setup transmission data */
    txPdu[connectionIndex].SduLength = (PduLengthType) length;
    txPdu[connectionIndex].SduDataPtr = data;
    if (PduR_DcmTransmit(FblCw_GetTxRemotePduIdOfDcmDslConnectionInfo(activeConnection[connectionIndex]), &txPdu[connectionIndex]) != E_OK)
    {
      /* Inform diagnostics layer for all errors regarding frame handling and timeouts. */
      /* Caution: Diagnostic buffer is released by FblDiagRxErrorIndication() */
      FblDiagDeclineErrorIndication(connectionIndex);
      activeConnection[connectionIndex] = FBLCW_CONNECTION_UNASSIGNED;
    }
  }
}
#endif /* FBLCW_DECLINED_REQUESTS == STD_ON */

/**********************************************************************************************************************
  FblCwTxSetTargetAddress
 *********************************************************************************************************************/
void FblCwTxSetTargetAddress(FblCw_DcmDslConnectionInfoIterType targetAddress)
{
  /* Verify that parameter lies within valid range */
  if (targetAddress < FblCw_GetSizeOfDcmDslConnectionInfo())
  {
    /* Actual target defined in connection configuration */
    activeConnection[FBL_CW_MAIN_REQUEST_INDEX] = targetAddress;
  }
  else
  {
    /* Invalid parameter */
    activeConnection[FBL_CW_MAIN_REQUEST_INDEX] = FBLCW_CONNECTION_UNASSIGNED;
  }
}

/**********************************************************************************************************************
  FblCwGetResponseAddress
 *********************************************************************************************************************/
FblCw_DcmDslConnectionInfoIterType FblCwGetResponseAddress(void)
{
  return activeConnection[FBL_CW_MAIN_REQUEST_INDEX];
}

/**********************************************************************************************************************
  FblCwResetResponseAddress
 *********************************************************************************************************************/
void FblCwResetResponseAddress(void)
{
  /* Allow any connection */
  activeConnection[FBL_CW_MAIN_REQUEST_INDEX] = FBLCW_CONNECTION_UNASSIGNED;
}

/**********************************************************************************************************************
  FblCwPrepareResponseAddress
 *********************************************************************************************************************/
tFblResult FblCwPrepareResponseAddress(void)
{
  tFblResult result;
  FblCw_DcmDslConnectionInfoIterType connectionIndex;

#if defined( FBL_CW_ENABLE_MULTIPLE_CONNECTIONS )
  /* PRQA S 2880, 2741, 2742 1 */ /* MD_MSR_Unreachable, MD_FblCw_ConstValue, MD_FblCw_ConstValue */
  if (FblCw_GetSizeOfDcmDslConnectionInfo() > 1u)
  { /* PRQA S 2880 5 */ /* MD_MSR_Unreachable */
    vuint8 addressBuffer[sizeof(FblCw_RxTesterSourceAddressOfDcmDslConnectionInfo16BitType)];
    FblCw_RxTesterSourceAddressOfDcmDslConnectionInfoType addressOfDcmDslConnection;

    /* Read transport layer target address */
    result = ApplFblReadDcmDslRxTesterSourceAddr(addressBuffer);

    if (kFblOk == result)
    {
      result = kFblFailed;
      addressOfDcmDslConnection = (FblCw_RxTesterSourceAddressOfDcmDslConnectionInfoType) FblMemGetInteger(sizeof(FblCw_RxTesterSourceAddressOfDcmDslConnectionInfo16BitType), (tFblMemConstRamData) addressBuffer);

      /* Search for a connection. If no connection is found, the connection will be configured to "unassigned" by FblCwTxSetTargerAddress(). */
      for (connectionIndex = 0u; connectionIndex < FblCw_GetSizeOfDcmDslConnectionInfo(); connectionIndex++)
      {
        /* Check if addrss matches to a diagnostic connection */
        if (FblCw_GetRxTesterSourceAddressOfDcmDslConnectionInfo(connectionIndex) == addressOfDcmDslConnection)
        {
          /* Leave search loop if address has been found. */
          result = kFblOk;
          break;
        }
      }
    }
    else
    {
      /* Read error. Provide invalid connection index. */
      connectionIndex = FBLCW_CONNECTION_UNASSIGNED;
    }
  }
  else
  { /* PRQA S 2880 4 */ /* MD_MSR_Unreachable */
    /* Preset variable with index 0. This is the default connection for single connection setups. */
    connectionIndex = 0u;
    /* Initialize return value */
    result = kFblOk;
  }
#else
  /* Preset variable with index 0. This is the default connection for single connection setups. */
  connectionIndex = 0u;
  /* Initialize return value */
  result = kFblOk;
#endif /* FBL_CW_ENABLE_MULTIPLE_CONNECTIONS */

  /* Set target connection */
  FblCwTxSetTargetAddress(connectionIndex);

  return result;
}

/**********************************************************************************************************************
  FblCwSaveResponseAddress
 *********************************************************************************************************************/
tFblResult FblCwSaveResponseAddress(void)
{
  tFblResult result;

#if defined( FBL_CW_ENABLE_MULTIPLE_CONNECTIONS )
  /* PRQA S 2880, 2741, 2742 1 */ /* MD_MSR_Unreachable, MD_FblCw_ConstValue, MD_FblCw_ConstValue */
  if (FblCw_GetSizeOfDcmDslConnectionInfo() > 1u)
  { /* PRQA S 2880 5 */ /* MD_MSR_Unreachable */
    vuint8 addressBuffer[sizeof(FblCw_RxTesterSourceAddressOfDcmDslConnectionInfo16BitType)];

    FblMemSetInteger(sizeof(FblCw_RxTesterSourceAddressOfDcmDslConnectionInfo16BitType),
                     FblCw_GetRxTesterSourceAddressOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]),
                     addressBuffer);

    /* Write transport layer target address */
    result = ApplFblWriteDcmDslRxTesterSourceAddr(addressBuffer);
  }
  else
  { /* PRQA S 2880 1 */ /* MD_MSR_Unreachable */
    result = kFblOk;
  }
#else
  result = kFblOk;
#endif /* FBL_CW_ENABLE_MULTIPLE_CONNECTIONS */

  return result;
}

#if ( FBLCW_BAUDRATE_SWITCH == STD_ON )
/**********************************************************************************************************************
  FblCwCheckBaudrate
 *********************************************************************************************************************/
tFblResult FblCwCheckBaudrate(vuint32 baudrate)
{
  tFblResult result = kFblFailed;

# if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
  /* Baud rate switch only supported for CAN */
  if ((activeConnection[FBL_CW_MAIN_REQUEST_INDEX] != FBLCW_CONNECTION_UNASSIGNED)
     && (FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == FblCw_GetBusTypeOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX])))
  {
    if (baudrate < 0x10000u)
    {
      if (E_OK == CanIf_CheckBaudrate(FblCw_GetControllerOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]), (uint16)baudrate))
      {
        result = kFblOk;
      }
    }
  }
# endif /* FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */

  return result;
}

/**********************************************************************************************************************
  FblCwSwitchBaudrate
 *********************************************************************************************************************/
tFblResult FblCwSwitchBaudrate(vuint32 baudrate)
{
  tFblResult result = kFblFailed;

# if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
  /* Baud rate switch only supported for CAN */
  if ((activeConnection[FBL_CW_MAIN_REQUEST_INDEX] != FBLCW_CONNECTION_UNASSIGNED)
     && (FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == FblCw_GetBusTypeOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX])))
  {
    FblCwCanIfSetMode(FblCw_GetControllerOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]), CANIF_CS_STOPPED);

    if (baudrate < 0x10000u)
    {
      if (E_OK == CanIf_ChangeBaudrate(FblCw_GetControllerOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]), (uint16)baudrate))
      {
        result = kFblOk;
      }
    }

    FblCwCanIfSetMode(FblCw_GetControllerOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]), CANIF_CS_STARTED);
    (void) CanIf_SetPduMode((uint8)(FblCw_GetControllerOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX])), CANIF_SET_ONLINE);

  }
# endif /* FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */

  return result;
}
#endif /* FBLCW_BAUDRATE_SWITCH == STD_ON */

/**********************************************************************************************************************
  FblCwResetRxBlock
 *********************************************************************************************************************/
void FblCwResetRxBlock(void)
{
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
  /* Clear message in process state */
  ClrCwMsgInProcess();
#endif
}

/**********************************************************************************************************************
  FblCwGetPayloadLimit
 *********************************************************************************************************************/
tCwDataLengthType FblCwGetPayloadLimit(void)
{
  tCwDataLengthType payloadLimit;

  if (activeConnection[FBL_CW_MAIN_REQUEST_INDEX] == FBLCW_CONNECTION_UNASSIGNED)
  {
    payloadLimit = 0u;
  }
  else
  {
    payloadLimit = (tCwDataLengthType) FblCw_GetPayloadLimitOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]);
  }

  return payloadLimit;
}

/**********************************************************************************************************************
  Dcm_StartOfReception
**********************************************************************************************************************/
/* PRQA S 3673, 6030, 6080 2 */ /* MD_MSR_Rule8.13, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_StartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, FBLCW_APPL_DATA) info, PduLengthType TpSduLength,
                                                         P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) bufferSizePtr)
{
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = FBLCW_E_NO_ERROR;
#endif
  BufReq_ReturnType result = BUFREQ_E_NOT_OK;
  vuint8 *localBuffPtr = NULL_PTR;     /* PRQA S 2981 */ /* MD_FblCw_2981 */

  if (!FblCw_IsInitialized())
  {
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
    errorId = FBLCW_E_UNINIT;
#endif
  }
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  else if (id >= FblCw_GetSizeOfDcmDslProtocolRxInfo())
  {
    errorId = FBLCW_E_PARAM;
  }
# if (FBLCW_INVALIDHNDOFDCMDSLPROTOCOLRXINFO == STD_ON)
  else if (FblCw_IsInvalidHndOfDcmDslProtocolRxInfo(id))
  {
    errorId = FBLCW_E_PARAM;
  }
# endif
# if ( FBLCW_QUEUED_REQUEST == STD_ON )
  /* Check if a (physically addressed) message has already been queued */
  else if (GetCwMsgQueued())
  {
    /* No free buffer available, discard message and quit */
  }
# endif
  else
#endif /* FBLCW_DEV_ERROR_DETECT == STD_ON */
  {
    /* Assign connection in case there is no assigned connection */
    if (FBLCW_CONNECTION_UNASSIGNED == activeConnection[FBL_CW_MAIN_REQUEST_INDEX])
    {
      activeConnection[FBL_CW_MAIN_REQUEST_INDEX] = FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(id);
    }

    if (FblCw_CheckRxPduAllowedInConnection(id, FBL_CW_MAIN_REQUEST_INDEX))
    {
      switch (FblCw_GetAddrTypeOfDcmDslProtocolRxInfo(id))
      {
#if ( FBLCW_EXISTS_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON )
        case FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO:
        {
          /* Physical request */
          if (TpSduLength <= FBL_DIAG_BUFFER_LENGTH)
          {
# if ( FBLCW_QUEUED_REQUEST == STD_ON )
            /* Check if a request is already pending */
            if (GetCwMsgInProcess())
            {
              /* Enqueue new request (performed in Dcm_CopyRxData) */
              /* Note: Only the first message shall be queued - this is checked above! */
              localBuffPtr = cwQueuedRequestBuffer;
              rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX] = FBL_CW_MAX_FPL_START_FRAME;
              cwQueuedRequestConnection = FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(id);
            }
            else
# endif /* FBLCW_QUEUED_REQUEST == STD_ON */
            {
              localBuffPtr = FblDiagRxGetPhysBuffer((tCwDataLengthType) TpSduLength);
              rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX] = (PduLengthType) FBL_DIAG_BUFFER_LENGTH;
            }

            if(NULL_PTR != localBuffPtr)
            {
              rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = localBuffPtr;
              rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduLength = TpSduLength;
              *bufferSizePtr = rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX];

              /* Store the number of bytes to be received */
              rxDataLength[FBL_CW_MAIN_REQUEST_INDEX] = TpSduLength;
# if ( FBLCW_QUEUED_REQUEST == STD_ON )
              if (GetCwMsgInProcess())
              {
                /* Queued request, postpone indication */
              }
              else
# endif /* FBLCW_QUEUED_REQUEST == STD_ON */
              {
                rxBuffer[FBL_CW_MAIN_REQUEST_INDEX] = rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr;
                activeConnection[FBL_CW_MAIN_REQUEST_INDEX] = FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(id);
                /* Call receive indication function */
                FblDiagRxStartIndication();
              }
              result = BUFREQ_OK;
            }
            else
            {
               /* No buffer available */
            }
          }
          else
          {
            result = BUFREQ_E_OVFL;
          }
          break;
        }
#endif /* FBLCW_EXISTS_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON */
#if ( FBLCW_EXISTS_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON )
        case FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO:
        {
          if (TpSduLength <= FBL_DIAG_BUFFER_LENGTH)
          {
            /* Functional request */
            rxPduFunc.SduDataPtr = FblDiagRxGetFuncBuffer((tCwDataLengthType) TpSduLength);
            rxBuffer[FBL_CW_MAIN_REQUEST_INDEX] = rxPduFunc.SduDataPtr;
            rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX] = (PduLengthType) FBL_DIAG_BUFFER_LENGTH;

            *bufferSizePtr = rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX];

            result = BUFREQ_OK;
            if (NULL_PTR != rxPduFunc.SduDataPtr)
            {
              rxPduFunc.SduLength = TpSduLength;

              /* Store the number of bytes to be received */
              rxDataLength[FBL_CW_MAIN_REQUEST_INDEX] = TpSduLength;
              activeConnection[FBL_CW_MAIN_REQUEST_INDEX] = FblCw_GetDcmDslConnectionInfoIdxOfDcmDslProtocolRxInfo(id);
              /* Call receive indication function */
              FblDiagRxStartIndication();
            }
            else
            {
              /* Report valid buffer, but discard data and indication */
            }
          }
          else
          {
            result = BUFREQ_E_OVFL;
          }
          break;
        }
#endif /* FBLCW_EXISTS_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON */
        default:
        {
          /* PDU ID not supported */
          break;
        }
      }
    }
#if ( FBLCW_DECLINED_REQUESTS == STD_ON )
    /* Connection is currently locked to a different connection. */
    else
    {
      result = Dcm_StartOfReception_Decline(id, TpSduLength, bufferSizePtr);
    }
#endif /* FBLCW_DECLINED_REQUESTS == STD_ON */
  }

#if ( FBLCW_DEV_ERROR_DETECT == STD_ON )
  if (errorId != FBLCW_E_NO_ERROR)
  {
    FblCw_Det_ReportError(FBLCW_APIID_STARTOFRECEPTION, (errorId));
  }
#endif /* FBLCW_DEV_ERROR_DETECT == STD_ON */

  FBLCW_DUMMY_STATEMENT(info);  /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return result;
}

/**********************************************************************************************************************
  Dcm_CopyRxData
**********************************************************************************************************************/
/* PRQA S 3673, 6030, 6080 1 */ /* MD_MSR_Rule8.13, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_CopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, FBLCW_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) bufferSizePtr)
{
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = FBLCW_E_NO_ERROR;
#endif
  BufReq_ReturnType result = BUFREQ_E_NOT_OK;
  vuint8 state = GetCwTaskState();
  SetCwTaskRunning();

  if (!FblCw_IsInitialized())
  {
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
    errorId = FBLCW_E_UNINIT;
#endif
  }
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  else if (id >= FblCw_GetSizeOfDcmDslProtocolRxInfo())
  {
    errorId = FBLCW_E_PARAM;
  }
# if (FBLCW_INVALIDHNDOFDCMDSLPROTOCOLRXINFO == STD_ON)
  else if (FblCw_IsInvalidHndOfDcmDslProtocolRxInfo(id))
  {
    errorId = FBLCW_E_PARAM;
  }
# endif
#endif /* FBLCW_DEV_ERROR_DETECT == STD_ON */
  else
  {

    {
      if (FblCw_CheckRxPduAllowedInConnection(id, FBL_CW_MAIN_REQUEST_INDEX))
      {
        switch (FblCw_GetAddrTypeOfDcmDslProtocolRxInfo(id))
        {
#if (FBLCW_EXISTS_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON)
          case FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO:
          {
# if ( FBLCW_QUEUED_REQUEST == STD_ON )
            /* Check if a request is already pending */
            if (GetCwMsgInProcess())
            {
              /* Service handling active, check if a queued request is already pending */
              if (GetCwMsgQueued())
              {
                /* Only a single request message can be queued - deny copy. */
                *bufferSizePtr = 0u;
                result = BUFREQ_OK;
              }
              else
              {
                /* Ensure that requested length is not bigger than remaining length */
                /* PRQA S 2214 1 */ /* MD_FblAssert_Assertion */
                assertFblInternal((info->SduLength <= rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX]), kFblSysAssertParameterOutOfRange);

                /* Store single frame until current request has been finished */ /* PRQA S 0314 1 */ /* MD_FblCw_0314_MemCpy */
                (void) MEMCPY(rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr, info->SduDataPtr, info->SduLength);
                rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = &rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr[info->SduLength];
                rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX] -= info->SduLength;
                *bufferSizePtr = rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX];

                /* Store length of queued data (used for dequeuing) */
                cwQueuedRequestLength = info->SduLength;
                /* Remember queued frame */
                SetCwMsgQueued();
                result = BUFREQ_OK;
              }
            }
            else
# endif /* FBLCW_QUEUED_REQUEST == STD_ON */
            {
              if (NULL_PTR != rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr)
              {
                /* Ensure that requested length is not bigger than remaining length */
                if (info->SduLength <= rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX])
                {
                  /* Copy Rx data to diag buffer */ /* PRQA S 0314 1 */ /* MD_FblCw_0314_MemCpy */
                  (void) MEMCPY(rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr, info->SduDataPtr, info->SduLength);
                  rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = &rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr[info->SduLength];
                  rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX] -= info->SduLength;
                  *bufferSizePtr = rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX];

                  result = BUFREQ_OK;
                }
              }
              else
              {
                /* No valid buffer available */
              }
            }
            break;
          }
#endif /* FBLCW_EXISTS_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON */

#if ( FBLCW_EXISTS_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON )
          case FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO:
          {
            if (NULL_PTR != rxPduFunc.SduDataPtr)
            {
              /* Ensure that requested length is not bigger than remaining length */
              if (info->SduLength <= rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX])
              {
                /* Copy Rx data to diag buffer */ /* PRQA S 0314 1 */ /* MD_FblCw_0314_MemCpy */
                (void) MEMCPY(rxPduFunc.SduDataPtr, info->SduDataPtr, info->SduLength);
                rxPduFunc.SduDataPtr = &rxPduFunc.SduDataPtr[info->SduLength];
                rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX] -= info->SduLength;
                *bufferSizePtr = rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX];

                result = BUFREQ_OK;
              }
            }
            else
            {
              /* No buffer available for reception Report success, but discard data */
              *bufferSizePtr = rxRemainingBufferSize[FBL_CW_MAIN_REQUEST_INDEX];
              result = BUFREQ_OK;
            }
            break;
          }
#endif /* FBLCW_EXISTS_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON */
          default:
          {
            /* PDU ID not supported */
            break;
          }
        }
      }
#if ( FBLCW_DECLINED_REQUESTS == STD_ON )
      else
      {
        uint8_least connectionIndex;

        for (connectionIndex = 1u; connectionIndex < kFblCwNumberOfRequests; connectionIndex++)
        {
          if (FblCw_CheckRxPduAllowedInConnection(id, connectionIndex))
          {
            if (NULL_PTR != rxPduPhys[connectionIndex].SduDataPtr)
            {
              /* Ensure that requested length is not bigger than remaining length */
              if (info->SduLength <= rxRemainingBufferSize[connectionIndex])
              {
                /* Copy Rx data to diag buffer */ /* PRQA S 0314 1 */ /* MD_FblCw_0314_MemCpy */
                (void) MEMCPY(rxPduPhys[connectionIndex].SduDataPtr, info->SduDataPtr, info->SduLength);
                rxPduPhys[connectionIndex].SduDataPtr = &rxPduPhys[connectionIndex].SduDataPtr[info->SduLength];
                rxRemainingBufferSize[connectionIndex] -= info->SduLength;
                *bufferSizePtr = rxRemainingBufferSize[connectionIndex];

                result = BUFREQ_OK;
              }
            }
            else
            {
              /* No valid buffer available */
            }
            break;
          }
        }
      }
#endif /* FBLCW_DECLINED_REQUESTS == STD_ON */
    }
  }

  /* Restore previous task state */
  RestoreCwTaskState(state);

#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  if (errorId != FBLCW_E_NO_ERROR)
  {
    FblCw_Det_ReportError(FBLCW_APIID_COPYRXDATA, (errorId));
  }
#endif

  return result;
}

/**********************************************************************************************************************
  Dcm_CopyTxData
**********************************************************************************************************************/
/* PRQA S 3673, 6030, 6080 1 */ /* MD_MSR_Rule8.13, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_CopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
                                                   P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) availableDataPtr)
{
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = FBLCW_E_NO_ERROR;
#endif
  BufReq_ReturnType result = BUFREQ_E_NOT_OK;   /* PRQA S 3197 */ /* MD_FblCw_3197 */
  vuint8 state = GetCwTaskState();

  SetCwTaskRunning();
  if (!FblCw_IsInitialized())
  {
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
    errorId = FBLCW_E_UNINIT;
#endif
  }
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  else if (id >= FblCw_GetSizeOfDcmDslProtocolTxInfo())
  {
    errorId = FBLCW_E_PARAM;
  }
# if (FBLCW_INVALIDHNDOFDCMDSLPROTOCOLTXINFO == STD_ON)
  else if (FblCw_IsInvalidHndOfDcmDslProtocolTxInfo(id))
  {
    errorId = FBLCW_E_PARAM;
  }
# endif
  else
#endif /* FBLCW_DEV_ERROR_DETECT == STD_ON */
  {
    /* Retry not supported by TP_ISO10681 (will always pass TP_DATACONF) */
    if (retry != NULL_PTR)
    {
      assertFblInternal((retry->TpDataState == TP_DATACONF), kFblSysAssertParameterOutOfRange); /* PRQA S 2214 */ /* MD_FblAssert_Assertion */
    }

    if (FblCw_CheckTxPduAllowedInActiveConnection(id, activeConnection[FBL_CW_MAIN_REQUEST_INDEX]))
    {
      result = BUFREQ_OK;
      if (info->SduLength == 0u)
      {
        *availableDataPtr = txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduLength;
      }
      else
      {
        /* Ensure that requested length is not bigger than remaining length */
        if (info->SduLength <= txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduLength)
        {
          /* PRQA S 0314 1 */ /* MD_FblCw_0314_MemCpy */
          (void) MEMCPY(info->SduDataPtr, txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr, info->SduLength);
          txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr = &txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr[info->SduLength];
          txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduLength -= info->SduLength;
          *availableDataPtr = txPdu[FBL_CW_MAIN_REQUEST_INDEX].SduLength;
        }
        else
        {
          result = BUFREQ_E_NOT_OK;
        }
      }
    }
#if (FBLCW_DECLINED_REQUESTS == STD_ON)
    else
    {
      uint8_least connectionIndex;

      for (connectionIndex = 1u; connectionIndex < kFblCwNumberOfRequests; connectionIndex++)
      {
        if (FblCw_CheckTxPduAllowedInActiveConnection(id, activeConnection[connectionIndex]))
        {
          result = BUFREQ_OK;
          if (info->SduLength == 0u)
          {
            *availableDataPtr = txPdu[connectionIndex].SduLength;
          }
          else
          {
            /* Ensure that requested length is not bigger than remaining length */
            if (info->SduLength <= txPdu[connectionIndex].SduLength)
            {
              /* PRQA S 0314 1 */ /* MD_FblCw_0314_MemCpy */
              (void) MEMCPY(info->SduDataPtr, txPdu[connectionIndex].SduDataPtr, info->SduLength);
              txPdu[connectionIndex].SduDataPtr = &txPdu[connectionIndex].SduDataPtr[info->SduLength];
              txPdu[connectionIndex].SduLength -= info->SduLength;
              *availableDataPtr = txPdu[connectionIndex].SduLength;
            }
            else
            {
              result = BUFREQ_E_NOT_OK;
            }
          }
          break;
        }
      }
    }
#endif /* FBLCW_DECLINED_REQUESTS == STD_ON */
  }
  /* Restore previous task state */
  RestoreCwTaskState(state);

#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  if (errorId != FBLCW_E_NO_ERROR)
  {
    FblCw_Det_ReportError(FBLCW_APIID_COPYTXDATA, (errorId));
  }
#endif

  FBLCW_DUMMY_STATEMENT(id);    /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return result;
}

/**********************************************************************************************************************
  Dcm_TpRxIndication
**********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, FBLCW_CODE) Dcm_TpRxIndication(PduIdType id, Std_ReturnType result)
{
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = FBLCW_E_NO_ERROR;
#endif

  if (!FblCw_IsInitialized())
  {
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
    errorId = FBLCW_E_UNINIT;
#endif
  }
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  else if (id >= FblCw_GetSizeOfDcmDslProtocolRxInfo())
  {
    errorId = FBLCW_E_PARAM;
  }
# if (FBLCW_INVALIDHNDOFDCMDSLPROTOCOLRXINFO == STD_ON)
  else if (FblCw_IsInvalidHndOfDcmDslProtocolRxInfo(id))
  {
    errorId = FBLCW_E_PARAM;
  }
# endif
  else
#endif /* FBLCW_DEV_ERROR_DETECT == STD_ON */
  {
    if (FblCw_CheckRxPduAllowedInConnection(id, FBL_CW_MAIN_REQUEST_INDEX))
    {
      if (((FblCw_GetAddrTypeOfDcmDslProtocolRxInfo(id) == FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO) && (NULL_PTR != rxPduPhys[FBL_CW_MAIN_REQUEST_INDEX].SduDataPtr))
#if (FBLCW_EXISTS_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO == STD_ON)
         || ((FblCw_GetAddrTypeOfDcmDslProtocolRxInfo(id) == FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO) && (NULL_PTR != rxPduFunc.SduDataPtr))
#endif
        )
      {
        switch (result)
        {
          case NTFRSLT_OK:
          {
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
            /* Check if a request is already pending */
            if (GetCwMsgInProcess())
            {
              /* Service handling active, postpone indication (request is queued by Dcm_CopyRxData) */
              SetCwRxIndPending();
            }
            else
#endif /* FBLCW_QUEUED_REQUEST == STD_ON */
            {
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
              /*
               * Set flag before call of FblDiagRxIndication() to account for special
               * case TesterPresent with SPRMIB.
               */
              SetCwMsgInProcess();
#endif /* FBLCW_QUEUED_REQUEST == STD_ON */
              /* Reception successful, start service processing */
              FblDiagRxIndication(DiagBuffer, rxDataLength[FBL_CW_MAIN_REQUEST_INDEX]);
            }
            break;
          }
          case NTFRSLT_E_NOT_OK:
          case NTFRSLT_E_TIMEOUT_A:
          case NTFRSLT_E_TIMEOUT_BS:
          case NTFRSLT_E_TIMEOUT_CR:
          case NTFRSLT_E_WRONG_SN:
          case NTFRSLT_E_INVALID_FS:
          case NTFRSLT_E_UNEXP_PDU:
          case NTFRSLT_E_WFT_OVRN:
          {
            /* Inform diagnostics layer for all errors regarding frame handling and timeouts. */
            /* Caution: Diagnostic buffer is released by FblDiagRxErrorIndication() */
            FblDiagRxErrorIndication();
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
            /* In case of an error clear any queued messages */
            if (GetCwMsgQueued())
            {
               ClrCwMsgQueued();
            }
#endif /* FBLCW_QUEUED_REQUEST == STD_ON */
            break;
          }
          default:
          {
            /* Do not inform diagnostic layer for all other errors */
            break;
          }
        }
      }
    }
#if (FBLCW_DECLINED_REQUESTS == STD_ON)
    else
    {
      vuintx connectionIndex;

      for (connectionIndex = 1u; connectionIndex < kFblCwNumberOfRequests; connectionIndex++)
      {
        if (FblCw_CheckRxPduAllowedInConnection(id, connectionIndex))
        {
          switch (result)
          {
            case NTFRSLT_OK:
            {
              /* Reception successful, start service processing */
              FblDiagRxDeclineIndication(rxBuffer[connectionIndex], rxDataLength[connectionIndex], connectionIndex);
              break;
            }
            case NTFRSLT_E_NOT_OK:
            case NTFRSLT_E_TIMEOUT_A:
            case NTFRSLT_E_TIMEOUT_BS:
            case NTFRSLT_E_TIMEOUT_CR:
            case NTFRSLT_E_WRONG_SN:
            case NTFRSLT_E_INVALID_FS:
            case NTFRSLT_E_UNEXP_PDU:
            case NTFRSLT_E_WFT_OVRN:
            {
              /* Inform diagnostics layer for all errors regarding frame handling and timeouts. */
              /* Caution: Diagnostic buffer is released by FblDiagRxErrorIndication() */
              FblDiagDeclineErrorIndication(connectionIndex);
              activeConnection[connectionIndex] = FBLCW_CONNECTION_UNASSIGNED;
              break;
            }
            default:
            {
              /* Do not inform diagnostic layer for all other errors */
              break;
            }
          }
          break;
        }
      }
    }
#endif /* FBLCW_QUEUED_REQUEST == STD_ON */
  }

#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  if (errorId != FBLCW_E_NO_ERROR)
  {
    FblCw_Det_ReportError(FBLCW_APIID_TPRXINDICATION, (errorId));
  }
#endif

  FBLCW_DUMMY_STATEMENT(id);    /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
  Dcm_TpTxConfirmation
**********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(void, FBLCW_CODE) Dcm_TpTxConfirmation(PduIdType id, Std_ReturnType result)
{
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = FBLCW_E_NO_ERROR;
#endif

  if (!FblCw_IsInitialized())
  {
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
    errorId = FBLCW_E_UNINIT;
#endif
  }
#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  else if (id >= FblCw_GetSizeOfDcmDslProtocolTxInfo())
  {
    errorId = FBLCW_E_PARAM;
  }
# if (FBLCW_INVALIDHNDOFDCMDSLPROTOCOLTXINFO == STD_ON)
  else if (FblCw_IsInvalidHndOfDcmDslProtocolTxInfo(id))
  {
    errorId = FBLCW_E_PARAM;
  }
# endif
  else
#endif /* FBLCW_DEV_ERROR_DETECT == STD_ON */
  {
    if (FblCw_CheckTxPduAllowedInActiveConnection(id, activeConnection[FBL_CW_MAIN_REQUEST_INDEX]))
    {
      if (result == NTFRSLT_OK)
      {
        switch (cwTxState)
        {
          case kFblCwTxStateIdle:
          {
            break;
          }
          case kFblCwTxStateRpInProgress:
          {
            FblDiagTxConfirmation(kFblCwMsgTypeRcrRp);
            break;
          }
          case kFblCwTxStateTxInProgress:
          {
            FblDiagTxConfirmation(kFblCwMsgTypeNormal);
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
            /* Clear message in process state */
            ClrCwMsgInProcess();
#endif
            break;
          }
          case kFblCwTxStateTxPendingWaitForConf:
          {
            /* Further Tx request pending */
            cwTxState = kFblCwTxStateTxPending;
            break;
          }
          default:
          {
            /* Illegal state, always throw assertion */
            assertFblInternal(0u, kFblSysAssertParameterOutOfRange);    /* PRQA S 2214, 2741, 4558 */ /* MD_FblAssert_Assertion */
            break;
          }
        }

        /* Reset ComWrapper states, unless further request is pending */
        if (kFblCwTxStateTxPending != cwTxState)
        {
          cwTxState = kFblCwTxStateIdle;
          cwTxTimer = 0;
        }
      }
      else
      {
        switch (cwTxState)
        {
          case kFblCwTxStateRpInProgress:
          case kFblCwTxStateRpPending:
          {
            /* Error Condition */
            FblDiagTxErrorIndication(kFblCwMsgTypeRcrRp);
            break;
          }
          case kFblCwTxStateTxPendingWaitForConf:
          {
            /* Further Tx request pending */
            cwTxState = kFblCwTxStateTxPending;
            break;
          }
          default:
          {
            /* Error Condition */
            FblDiagTxErrorIndication(kFblCwMsgTypeNormal);
            /* Reset ComWrapper states */
            cwTxState = kFblCwTxStateIdle;
            cwTxTimer = 0;
#if ( FBLCW_QUEUED_REQUEST == STD_ON )
            /* Clear message in process state */
            ClrCwMsgInProcess();
#endif /* FBLCW_QUEUED_REQUEST == STD_ON */
            break;
          }
        }
      }
    }
#if (FBLCW_DECLINED_REQUESTS == STD_ON)
    else
    {
      uint8_least connectionIndex;

      for (connectionIndex = 1u; connectionIndex < kFblCwNumberOfRequests; connectionIndex++)
      {
        if (FblCw_CheckTxPduAllowedInActiveConnection(id, activeConnection[connectionIndex]))
        {
          FblDiagDeclineTxConfirmation(connectionIndex);
          activeConnection[connectionIndex] = FBLCW_CONNECTION_UNASSIGNED;
          break;
        }
      }
    }
#endif /* FBLCW_DECLINED_REQUESTS == STD_ON */
  }

#if (FBLCW_DEV_ERROR_DETECT == STD_ON)
  if (errorId != FBLCW_E_NO_ERROR)
  {
    FblCw_Det_ReportError(FBLCW_APIID_TPTXCONFIRMATION, (errorId));
  }
#endif

  FBLCW_DUMMY_STATEMENT(id);    /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

#define FBLCW_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
# define FBLCW_CAN_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ApplCanTimerStart
 *********************************************************************************************************************/
/*! \brief       Start timeout for hardware loop monitoring
 *  \param[in]   Controller     CAN channel handle
 *  \param[in]   source         Source handle of caller
 *  \note        The function is called by the CAN driver.
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FBLCW_APPLCANTIMERSTART(FBLCW_CAN_CHANNEL_CANTYPE_FIRST uint8 source)
{
  /* Start timeout for hardware loop Same timeout value used for all sources */
  cwCanHardwareLoopTimer = FBLCW_CAN_HARDWARE_LOOP_TIMEOUT;

# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  FBLCW_DUMMY_STATEMENT(Controller);    /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif /* C_MULTIPLE_RECEIVE_CHANNEL */
  FBLCW_DUMMY_STATEMENT(source);        /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
 *  ApplCanTimerLoop
 *********************************************************************************************************************/
/*! \brief       Decide whether a hardware loop continues or not
 *  \param[in]   Controller     CAN channel handle
 *  \param[in]   source         Source handle of caller
 *  \return      Can_ReturnType  CAN_NOT_OK (break) or CAN_OK (continue)
 *  \note        The function is called by the CAN driver.
 *********************************************************************************************************************/
FUNC(Can_ReturnType, FBLCW_CODE) FBLCW_APPLCANTIMERLOOP(FBLCW_CAN_CHANNEL_CANTYPE_FIRST uint8 source)
{
  Can_ReturnType result = CAN_OK;
  /* Handle timeout for hardware loop */
  if (0u != cwCanHardwareLoopTimer)
  {
    if (FBL_NO_TRIGGER != FblLookForWatchdog())
    {
      cwCanHardwareLoopTimer--;
    }
  }
  /* Timeout expired? */
  if (0u == cwCanHardwareLoopTimer)
  {
    /* Abort hardware loop */
    result = CAN_NOT_OK;
  }
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  FBLCW_DUMMY_STATEMENT(Controller);    /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif /* C_MULTIPLE_RECEIVE_CHANNEL */
  FBLCW_DUMMY_STATEMENT(source);        /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return result;
}

/**********************************************************************************************************************
 *  ApplCanTimerEnd
 *********************************************************************************************************************/
/*! \brief       Stop timeout of hardware loop monitoring
 *  \param[in]   Controller     CAN channel handle
 *  \param[in]   source         Source handle of caller
 *  \note        The function is called by the CAN driver.
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FBLCW_APPLCANTIMEREND(FBLCW_CAN_CHANNEL_CANTYPE_FIRST uint8 source)
{
  /* Stop timeout for hardware loop */
  cwCanHardwareLoopTimer = 0u;
# if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  FBLCW_DUMMY_STATEMENT(Controller);    /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
# endif /* C_MULTIPLE_RECEIVE_CHANNEL */
  FBLCW_DUMMY_STATEMENT(source);        /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
# define FBLCW_CAN_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define FBLCW_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  FblCw_ControllerBusOff
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_ControllerBusOff(uint8 controllerId)
{
  /* Call default bus-off handling */
  ApplFblCanBusOff();
  FBLCW_DUMMY_STATEMENT(controllerId);  /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/**********************************************************************************************************************
  FblCw_ControllerModeIndication
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_ControllerModeIndication(uint8 controllerId, CanIf_ControllerModeType controllerMode)
{
# if ( FBLCW_MODULE_CANSM == STD_ON )
  CanSM_ControllerModeIndication(controllerId, controllerMode);
# else
  FBLCW_DUMMY_STATEMENT(controllerId);  /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FBLCW_DUMMY_STATEMENT(controllerMode);        /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  /* Nothing to be done here Mode evaluated through call of CanIf_GetControllerMode */
# endif
}

/**********************************************************************************************************************
  FblCw_CheckTransceiverWakeFlagIndication
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_CheckTransceiverWakeFlagIndication(uint8 transceiverId)
{
  FBLCW_DUMMY_STATEMENT(transceiverId); /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  /* Nothing to be done here */
}

/**********************************************************************************************************************
  FblCw_ClearTrcvWufFlagIndication
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_ClearTrcvWufFlagIndication(uint8 transceiverId)
{
  FBLCW_DUMMY_STATEMENT(transceiverId); /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  /* Nothing to be done here */
}

/**********************************************************************************************************************
  FblCw_ConfirmPnAvailability
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_ConfirmPnAvailability(uint8 transceiverId)
{
  FBLCW_DUMMY_STATEMENT(transceiverId); /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  /* Nothing to be done here */
}

/**********************************************************************************************************************
  FblCw_TransceiverModeIndication
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_TransceiverModeIndication(uint8 transceiverId, CanTrcv_TrcvModeType transceiverMode)
{
  /* PRQA S 3112, 2983, 1338 2 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FBLCW_DUMMY_STATEMENT(transceiverId);
  FBLCW_DUMMY_STATEMENT(transceiverMode);
  /* Nothing to be done here */
}
# define FBLCW_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */

/* Configuration checks */
#if (FBLCW_CHANGE_PARAMETER == STD_ON)
# if ( FBLCW_EXISTS_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_OFF )
#  error "Error in CanTp_cfg.h: Feature is supported for CAN only"
# endif
# if (CANTP_ENABLE_READ_PARAM == STD_OFF)
#  error "Error in CanTp_cfg.h: Read parameter API must be enabled"
# endif
#endif /* FBLCW_CHANGE_PARAMETER == STD_ON */

#define FBLCW_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#if (FBLCW_CHANGE_PARAMETER == STD_ON)
/**********************************************************************************************************************
  FblCw_ChangeParameter
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ChangeParameter(TPParameterType parameter, uint16 value)
{
  FblCw_ParameterInfoIterType parameterInfoIdx;
  FblCw_BusTypeOfDcmDslConnectionInfoType connectionInfo;
  Std_ReturnType result;

  result = kFblFailed;
  if (activeConnection[FBL_CW_MAIN_REQUEST_INDEX] != FBLCW_CONNECTION_UNASSIGNED)
  {
    parameterInfoIdx = FblCw_GetParameterInfoIdxOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]);

# if defined( FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO ) || defined( FBLCW_FR_BUSTYPEOFDCMDSLCONNECTIONINFO )
    connectionInfo = FblCw_GetBusTypeOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]);
#  if defined( FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO )
    if (connectionInfo == FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO)
    {
      if ((parameter == TP_STMIN) || (parameter == TP_BS))
      {
        if (PduR_DcmChangeParameter(FblCw_GetPduRIdOfParameterInfo(parameterInfoIdx), parameter, value) == E_OK)
        {
          result = kFblOk;
        }
      }
    }
#  endif /* FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO */

#  if defined( FBLCW_FR_BUSTYPEOFDCMDSLCONNECTIONINFO )
    if (connectionInfo == FBLCW_FR_BUSTYPEOFDCMDSLCONNECTIONINFO)
    {
#   if ( FBLCW_MODULE_FRTP == STD_ON )
      if (parameter == TP_BC)
#   endif
#   if ( FBLCW_MODULE_FRARTP == STD_ON )
      if ((parameter == TP_BS) || (parameter == TP_STMIN))
#   endif
      {
        if (PduR_DcmChangeParameter(FblCw_GetPduRIdOfParameterInfo(parameterInfoIdx), parameter, value) == E_OK)
        {
          result = kFblOk;
        }
      }
    }
#  endif /* FBLCW_FR_BUSTYPEOFDCMDSLCONNECTIONINFO */
# else /* FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO || FBLCW_FR_BUSTYPEOFDCMDSLCONNECTIONINFO */
    if (PduR_DcmChangeParameter(FblCw_GetPduRIdOfParameterInfo(parameterInfoIdx), parameter, value) == E_OK)
    {
      result = kFblOk;
    }
# endif
  }

  return result;
}

/**********************************************************************************************************************
  FblCw_ResetParameter
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ResetParameter(void)
{
  FblCw_DcmDslConnectionInfoIterType dcmDslConnectionInfoIdx;
  FblCw_BusTypeOfDcmDslConnectionInfoType connectionInfo;

  for (dcmDslConnectionInfoIdx = 0u; dcmDslConnectionInfoIdx < FblCw_GetSizeOfDcmDslConnectionInfo(); dcmDslConnectionInfoIdx++)
  {
    if (FblCw_IsParameterInfoUsedOfDcmDslConnectionInfo(dcmDslConnectionInfoIdx)) /* PRQA S 4304 */ /* MD_FblCw_4304_BooleanCast */
    {
      FblCw_ParameterInfoIterType parameterInfoIdx;
      parameterInfoIdx = FblCw_GetParameterInfoIdxOfDcmDslConnectionInfo(dcmDslConnectionInfoIdx);
      connectionInfo = FblCw_GetBusTypeOfDcmDslConnectionInfo(dcmDslConnectionInfoIdx);

# if defined( FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO )
      if (connectionInfo == FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO)
      {
        (void)PduR_DcmChangeParameter(FblCw_GetPduRIdOfParameterInfo(parameterInfoIdx), TP_BS, FblCw_GetInitialBS(parameterInfoIdx));
        (void)PduR_DcmChangeParameter(FblCw_GetPduRIdOfParameterInfo(parameterInfoIdx), TP_STMIN, FblCw_GetInitialSTmin(parameterInfoIdx));
      }
# endif /* FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO */

# if defined( FBLCW_FR_BUSTYPEOFDCMDSLCONNECTIONINFO )
      if (connectionInfo == FBLCW_FR_BUSTYPEOFDCMDSLCONNECTIONINFO)
      {
#  if ( FBLCW_MODULE_FRTP == STD_ON )
        (void)PduR_DcmChangeParameter(FblCw_GetPduRIdOfParameterInfo(parameterInfoIdx), TP_BC, FblCw_GetInitialBC(parameterInfoIdx));
#  endif
#  if ( FBLCW_MODULE_FRARTP == STD_ON )
        (void)PduR_DcmChangeParameter(FblCw_GetPduRIdOfParameterInfo(parameterInfoIdx), TP_BS, FblCw_GetInitialBS(parameterInfoIdx));
        (void)PduR_DcmChangeParameter(FblCw_GetPduRIdOfParameterInfo(parameterInfoIdx), TP_STMIN, FblCw_GetInitialSTmin(parameterInfoIdx));
#  endif
      }
# endif /* FBLCW_FR_BUSTYPEOFDCMDSLCONNECTIONINFO */
    }
  }
  return kFblOk;
}

/**********************************************************************************************************************
  FblCw_ReadParameter
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ReadParameter(TPParameterType parameter, uint16 * value)
{
  tFblResult result;
  FblCw_BusTypeOfDcmDslConnectionInfoType connectionInfo;
  FblCw_ParameterInfoIterType parameterInfoIdx;

  result = kFblFailed;

# if defined( FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO )
  connectionInfo = FblCw_GetBusTypeOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]);
  if (connectionInfo == FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO)
  {
    if ((parameter == TP_STMIN) || (parameter == TP_BS))
    {
      parameterInfoIdx = FblCw_GetParameterInfoIdxOfDcmDslConnectionInfo(activeConnection[FBL_CW_MAIN_REQUEST_INDEX]);
      if (CanTp_ReadParameter(FblCw_GetCanTpIdOfParameterInfo(parameterInfoIdx), parameter, value) == E_OK)
      {
        result = kFblOk;
      }
    }
  }
# endif /* FBLCW_CAN_BUSTYPEOFDCMDSLCONNECTIONINFO */

  FBLCW_DUMMY_STATEMENT(parameter);        /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FBLCW_DUMMY_STATEMENT(value);        /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return result;
}
#endif /* FBLCW_CHANGE_PARAMETER == STD_ON */

#if ( FBLCW_MODULE_FRSM == STD_ON )
# if ( FRIF_CUSTOM_JLE_SCHEDULING == STD_ON )
/**********************************************************************************************************************
  FrIf_CustomJLEHandling
**********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static void FrIf_CustomJLEHandling(void)
{
  uint8 ClusterIdx;
  boolean isLastFrIfRxTaskForTp[FrIf_CommonMaxNumberOfClusters];

  for (ClusterIdx = 0u; ClusterIdx < FrIf_CommonMaxNumberOfClusters; ClusterIdx++)
  {
      isLastFrIfRxTaskForTp[ClusterIdx] = FALSE;
  }

  for (ClusterIdx = 0u; ClusterIdx < FrIf_CommonMaxNumberOfClusters; ClusterIdx++)
  {
    if (TRUE == JLETimerEnabled[ClusterIdx])
    {
      uint8 cycle;
      uint16 macroTicks;
      if (E_OK == FrIf_GetGlobalTime(ClusterIdx, &cycle, &macroTicks))
      {
        /* PRQA S 4394 1 */ /* MD_FblCw_4394_SignedCast */
        sint8_least diffCycle = (sint8_least) ((vuint8) ((JLETimerCycle[ClusterIdx] + 64u) - cycle) & 63u);
        if (32 < diffCycle)
        {
          diffCycle -= 64;
        }
        if (((0 == diffCycle) && (JLETimerOffset[ClusterIdx] <= macroTicks)) || (0 > diffCycle))
        {
#  if ( FBLCW_MODULE_FRNM == STD_ON )
          boolean isLastFrIfRxTaskForNm = FrIf_IsLastFrIfRxTaskForNm(ClusterIdx); /* PRQA S 1863, 4304 */ /* MD_FblCw_OtherComponentFinding, MD_FblCw_4304_BooleanCast */
#  endif
          isLastFrIfRxTaskForTp[ClusterIdx] = FrIf_IsLastFrIfRxTaskForTp(ClusterIdx); /* PRQA S 1863, 4304 */ /* MD_FblCw_OtherComponentFinding, MD_FblCw_4304_BooleanCast */

          /* Execute next job list entry */
#  if ( FRIF_CTRL_ENABLE_API_OPTIMIZATION == STD_ON )
          FrIf_JobListExec();
#  else
          FrIf_JobListExec(ClusterIdx);
#  endif

#  if ( FBLCW_MODULE_FRNM == STD_ON )
          if (TRUE == isLastFrIfRxTaskForNm)
          {
            FrNm_MainFunction_0();
          }
#  endif

        }
      }
    }
  }

  if (TRUE == isLastFrIfRxTaskForTp[0u])
  {
#  if ( FBLCW_MODULE_FRTP == STD_ON )
    FrTp_MainFunction();
#  endif
#  if ( FBLCW_MODULE_FRARTP == STD_ON )
    FrArTp_MainFunction();
#  endif
  }
}
#  define FBLCW_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define FBLCW_FR_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  FrIf_Enable_JLE_Timer
 *********************************************************************************************************************/
/*! \brief       Enable the JobListExecution timer for the given cluster
 *  \pre         Communication wrapper is initialized.
 *  \param[in]   ClusterIdx Index of the FlexRay cluster. Only 0 is allowed.
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_Enable_JLE_Timer(uint8 ClusterIdx)
{
  JLETimerEnabled[ClusterIdx] = TRUE;
}

/**********************************************************************************************************************
 *  FrIf_Disable_JLE_Timer
 *********************************************************************************************************************/
/*! \brief       Disable the JobListExecution timer for the given cluster
 *  \pre         Communication wrapper is initialized.
 *  \param[in]   ClusterIdx Index of the FlexRay cluster. Only 0 is allowed.
 *********************************************************************************************************************/
FUNC(void, FRIF_CODE) FrIf_Disable_JLE_Timer(uint8 ClusterIdx)
{
  JLETimerEnabled[ClusterIdx] = FALSE;
}

/**********************************************************************************************************************
 *  FrIf_Set_JLE_Timer
 *********************************************************************************************************************/
/*! \brief       Set the JobListExecution Timer for the given cluster
 *  \pre         Communication wrapper is initialized.
 *  \param[in]   ClusterIdx The index of the FlexRay cluster
 *  \param[in]   Cycle FlexRay Cycle for the next activation time of the JLE.
 *  \param[in]   MacrotickOffset FlexRay macrotick offset for the next activation time of the JLE.
 *  \param[in]   RepeatJLE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, FRIF_CODE) FrIf_Set_JLE_Timer(uint8 ClusterIdx, uint8 Cycle, uint16 MacrotickOffset, uint8 RepeatJLE)
{
  JLETimerCycle[ClusterIdx] = Cycle;
  JLETimerOffset[ClusterIdx] = MacrotickOffset;
  FBLCW_DUMMY_STATEMENT(RepeatJLE); /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return E_OK;
}
# else  /* FRIF_CUSTOM_JLE_SCHEDULING == STD_ON */
#  define FBLCW_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define FBLCW_FR_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* FRIF_CUSTOM_JLE_SCHEDULING == STD_ON */

/**********************************************************************************************************************
 *  BswM_FrSM_CurrentState
 *********************************************************************************************************************/
/*! \brief       Function called by FrSM to indicate its current state
 *  \param[in]   Network The FlexRay cluster that the indicated state corresponds to
 *  \param[in]   CurrentState The current state of the FlexRay cluster
 *********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState(NetworkHandleType Network, FrSM_BswM_StateType CurrentState)
{
# if ( FBLCW_KEY_SLOT_MODE == STD_ON )
  vuintx i;
  const FrSM_ClusterConfigType * FrSM_ClusterConfigPtr = FrSM_GetClusterConfigOfPCConfig();

  for (i = 0; i < FrSM_GetSizeOfClusterConfigOfPCConfig(); i++)
  {
    if (FrSM_ClusterConfigPtr[i].NetworkHandleOfClusterConfig == Network)
    {
      break;
    }
  }
# endif /* FBLCW_KEY_SLOT_MODE == STD_ON */
  /* PRQA S 3112, 2983, 1338 2 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FBLCW_DUMMY_STATEMENT(Network);
  FBLCW_DUMMY_STATEMENT(CurrentState);
}
# define FBLCW_FR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define FBLCW_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if ( FBLCW_KEY_SLOT_MODE == STD_ON )
/**********************************************************************************************************************
  FblCwCheckNwStatus
**********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
static void FblCwCheckNwStatus(void)
{
  vuint8 localRxBuffer[FBLCW_NW_STATUS_RX_BUFFER_SIZE];
  vuint8 rxLen;
  Fr_RxLPduStatusType rxStatus;
  tCwNwStatus nwStatus;
  Std_ReturnType ret;
  Fr_POCStatusType pocStatus;

  /* Init local variables */
  rxLen = sizeof(localRxBuffer);
  rxStatus = FR_NOT_RECEIVED;
  pocStatus.State = FR_POCSTATE_CONFIG;

  /* Determine the state of the protocol operation controller (POC) */
  ret = FrIf_GetPOCStatus( (uint8)FBLCW_FR_CONTROLLER_IDX_MAIN_NETWORK, &pocStatus);

  /* Check first frame only in case the POC is in state NORMAL_ACTIVE */
  if ((E_OK == ret) && (FR_POCSTATE_NORMAL_ACTIVE == pocStatus.State))
  {
    /* Check if first frame has been received */
    /* The value of FrIf_InvalidTxHandle is subtracted, because the Tx LPDu handles are placed at the start of the Tx/Rx LPdu handle space. */
    ret = Fr_ReceiveRxLPdu( (uint8)FBLCW_FR_CONTROLLER_IDX_MAIN_NETWORK, (uint16)FBLCW_NW_STATUS_PDU, localRxBuffer, &rxStatus, &rxLen);
  }

  /* Evaluate the network status only in the case the LPdu has been received successfully */
  if ((E_OK == ret) && (FR_RECEIVED == rxStatus))
  {
    /* Extract the network status parameter */
    /* PRQA S 3353 1 */ /* MD_FblCw_FalseFinding */
    nwStatus = ((vuint16) localRxBuffer[0u] << 8u) | (vuint16) localRxBuffer[1u];
    /* Reset timeout counter */
    cwNwStatusTimeoutCtr = 0u;

    /* Check current FlexRay mode */
    if (FBL_CW_ALL_SLOT_MODE_REQUESTED == cwAllSlots)
    {
      /* Change to all slot only once */
      if (E_OK == FrIf_AllSlots(FBLCW_FRIF_MAIN_NETWORK))
      {
        cwAllSlots = FBL_CW_ALL_SLOT_MODE;
      }
    }

    if (FBL_CW_ALL_SLOT_MODE == cwAllSlots)
    {
      /* Bootloader has been started in BOOT schedule, "All Slots" mode enabled */
      if (FBL_CW_NW_STATUS_BOOT == nwStatus)
      {
        /* Restart S3 timer if network status "boot" is received */
        ResetTesterTimeout();
        /* Set network timeout to S3 */
        cwNwStatusTimeout = (TESTER_PRESENT_TIMEOUT/FBLCW_TASK_CYCLE);
      }
      /* Start application is requested by the schedule coordinator */
      else if (FBL_CW_NW_STATUS_NORMAL == nwStatus)
      {
        if (kApplValid == ApplFblIsValidApp())
        {
          /* Set ApplStart flag, shutdown FBL and perform a reset */
          FblBmSetApplStartMagicFlag(); /* PRQA S 3109 */ /* MD_FblCw_3109 */
          FblCwShutdownRequest(kFblCwResetEcuRegularCase);
        }
      }
      else
      {
        /* Other schedule requested, perform immediate reset */
        FblCwShutdownRequest(kFblCwResetEcuRegularCase);
      }
    }
    else /* FBL_CW_KEY_SLOT_MODE == cwAllSlots */
    {
      /* Bootloader still in startup phase, check requested schedule */
      if (FBL_CW_NW_STATUS_BOOT == nwStatus)
      {
        /* Restart S3 timer if network status "boot" is received */
        ResetTesterTimeout();
        /* Set network timeout to S3 */
        cwNwStatusTimeout = (TESTER_PRESENT_TIMEOUT/FBLCW_TASK_CYCLE);
        /* Bootloader schedule requested, enable "All Slots" mode */
        if (E_OK == FrIf_AllSlots(FBLCW_FRIF_MAIN_NETWORK))
        {
          /* Invoke state transition to full communication ("All Slots" mode) */
          cwAllSlots = FBL_CW_ALL_SLOT_MODE;
        }
      }
      else
      {
        /* Other schedule requested, check validity of application software */
        if (kApplValid == ApplFblIsValidApp())
        {
          /* Set ApplStart flag, shutdown FBL and perform a reset */
          FblBmSetApplStartMagicFlag(); /* PRQA S 3109 */ /* MD_FblCw_3109 */
          FblCwShutdownRequest(kFblCwResetEcuRegularCase);
        }
      }
    }
  }
  else
  {
    /* First frame not received, network status is not present */
    if (FBL_CW_KEY_SLOT_MODE == cwAllSlots)
    {
      /* Startup phase: active schedule has not been determined yet => monitor timeout */
      if (cwNwStatusTimeoutCtr > cwNwStatusTimeout)
      {
        /* Timeout is expired, check validity of application software */
        if (kApplValid == ApplFblIsValidApp())
        {
          /* Set ApplStart flag, shutdown FBL and perform a reset */
          FblBmSetApplStartMagicFlag(); /* PRQA S 3109 */ /* MD_FblCw_3109 */
          FblCwShutdownRequest(kFblCwResetEcuRegularCase);
        }
      }
    }
    else /* FBL_CW_ALL_SLOT_MODE == cwAllSlots */
    {
      /* Synchronization lost: wait S3 for resync */
      if (cwNwStatusTimeoutCtr > cwNwStatusTimeout)
      {
         FblCwShutdownRequest(kFblCwResetEcuRegularCase);
      }
    }
  }
}
# endif /* FBLCW_KEY_SLOT_MODE == STD_ON */
#endif /* FBLCW_MODULE_FRSM == STD_ON */

#if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
/**********************************************************************************************************************
  FblCwPduShutdownRequest
**********************************************************************************************************************/
void FblCwPduShutdownRequest(void)
{
  /* Setup timer and state for shutdown handling */
  cwShutdownState = kFblCwShutdownRequested;
  cwShutdownTimer = kFblCwShutdownWaitTime;
}
#endif /* FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON */


#if ( FBLCW_MODULE_COMM == STD_ON )
/**********************************************************************************************************************
 *  Dcm_ComM_NoComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM call-back for entering no communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_NO_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_NoComModeEntered(NetworkHandleType channel)
{
  cwComMChannelIsOnline[channel] = FALSE;
  ApplFbl_ComM_NoComModeEntered(channel);
}

/**********************************************************************************************************************
 *  Dcm_ComM_SilentComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM callback for entering silent communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_SILENT_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_SilentComModeEntered(NetworkHandleType channel)
{
  cwComMChannelIsOnline[channel] = FALSE;
  ApplFbl_ComM_SilentComModeEntered(channel);
}

/**********************************************************************************************************************
 *  Dcm_ComM_FullComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM callback for entering full communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_FULL_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_FullComModeEntered(NetworkHandleType channel)
{
  cwComMChannelIsOnline[channel] = TRUE;
  ApplFbl_ComM_FullComModeEntered(channel);
}
#endif /* FBLCW_MODULE_COMM == STD_ON */

#define FBLCW_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define FBLCW_LIN_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( FBLCW_MODULE_LINSM == STD_ON )
# if ( LINSM_MASTERNODE_POSSIBLE == STD_ON )
/***********************************************************************************************************************
 *  BswM_LinTp_RequestMode
 **********************************************************************************************************************/
/*! \brief       Function called by LinTp to request a mode for the corresponding LIN channel
 *  \param[in]   Network The LIN channel that the LIN TP mode request corresponds to
 *  \param[in]   LinTpRequestedMode The requested LIN TP mode
 **********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_LinTp_RequestMode(NetworkHandleType Network, LinTp_Mode LinTpRequestedMode)
{
  /* Check for valid Network value */
  if (Network < FblCw_GetSizeOfLinIfScheduleMappingOfPCConfig())
  {
    /* Switch to request schedule  */
    if (LinTpRequestedMode == LINTP_DIAG_REQUEST)
    {
      (void)LinSM_ScheduleRequest(Network, FblCw_GetLinIfRequestScheduleOfLinIfScheduleMapping(Network));
    }
    else if (LinTpRequestedMode == LINTP_DIAG_RESPONSE)
    {
      (void)LinSM_ScheduleRequest(Network, FblCw_GetLinIfResponseScheduleOfLinIfScheduleMapping(Network));
    }
    else
    {
      /* Nothing to do */
    }
  }
}
# endif /* LINSM_MASTERNODE_POSSIBLE == STD_ON */

/***********************************************************************************************************************
 *  BswM_LinSM_CurrentSchedule
 **********************************************************************************************************************/
/*! \brief       Function called by LinSM to indicate its current schedule
 *  \param[in]   Network The LIN channel that the indicated schedule corresponds to
 *  \param[in]   CurrentSchedule The currently active schedule table of the LIN channel
 **********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentSchedule(NetworkHandleType Network, LinIf_SchHandleType CurrentSchedule)
{
  FBLCW_DUMMY_STATEMENT(Network);            /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  FBLCW_DUMMY_STATEMENT(CurrentSchedule);    /* PRQA S 3112, 2983, 1338 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}

/***********************************************************************************************************************
 *  BswM_LinSM_CurrentState
 **********************************************************************************************************************/
/*! \brief       Function called by LinSM to indicate its current state
 *  \param[in]   Network The LIN channel that the indicated state corresponds to
 *  \param[in]   CurrentState The current state of the LIN channel
 **********************************************************************************************************************/
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentState(NetworkHandleType Network, LinSM_ModeType CurrentState)
{
# if ( LINSM_MASTERNODE_POSSIBLE == STD_ON )
  /* Check for valid Network value */
  if (Network < FblCw_GetSizeOfLinIfScheduleMappingOfPCConfig())
  {
    if (CurrentState == LINSM_BSWM_FULL_COM)
    {
      (void)LinSM_ScheduleRequest(Network, FblCw_GetLinIfResponseScheduleOfLinIfScheduleMapping(Network));
    }
  }
# else /* LINSM_MASTERNODE_POSSIBLE == STD_ON */
   /* Nothing to be done for slave-only nodes */
   FBLCW_DUMMY_STATEMENT(Network);           /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt */
   FBLCW_DUMMY_STATEMENT(CurrentState);      /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt */
# endif /* LINSM_MASTERNODE_POSSIBLE == STD_ON */
}
#endif /* FBLCW_MODULE_LINSM == STD_ON */

#define FBLCW_LIN_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Module specific MISRA deviations:

  MD_FblAssert_Assertion:
    Reason: This is an assertion macro used only for debugging in development (FBL_ENABLE_ASSERTION). There should
            be no need to extend the amount of statements, so the current usage is accepted.
    Risk: Unintended debugging code behavior could result, through adding further statements,
    Prevention: A comment is in place to avoid that further statements are added to the if condition.

  MD_FblCw_FalseFinding:
    Reason: QAC fails to analyze the code correctly and issues a false finding
    Risk: No identifiable risk.
    Prevention: No prevention required.

  MD_FblCw_OtherComponentFinding:
    Reason: The finding is issued in a other component.
    Risk: No identifiable risk.
    Prevention: No prevention required.

  MD_FblCw_ConstValue:
    Reason: Value is constant depending on configuration aspects or platform specific implementation.
      This leads to constant control expressions, unreachable code or redundant operations.
    Risk: Wrong or missing functionality.
    Prevention: Code inspection and test of the different variants in the component test.

  MD_FblCw_0314_MemCpy:
    Reason: The copy function have a void pointer as a function parameter.
    Risk: No risk, because the underlying vuint8 pointer type is known.
    Prevention: No prevention necessary.

  MD_FblCw_0779:
    Reason: This type name was chosen explicitly to be as similar to the generated type but with a fixed length
    Risk: The types could be mixed up
    Prevention: During code review special attention has to be dedicated to verify the correct usage of types

  MD_FblCw_0832:
    Reason: File name of header has to be generated because name varies according to configuration.
    Risk: Decreased readability.
    Prevention: No prevention required.

  MD_FblCw_2981:
    Reason: The object initialization value is used only on certain configurations.
    Risk: No risk.
    Prevention: No prevention required.

  MD_FblCw_3109:
    Reason: Multi-line macros encapsulated in curly brackets to reduce side-effects. Results in empty statement after
      the closing bracket.
    Risk: No identifiable risk.
    Prevention: No prevention required.

  MD_FblCw_3197:
    Reason: Some configurations overwrite variables which have been initialized every time.
    Risk: No risk.
    Prevention: No prevention required.

  MD_FblCw_3218:
    Reason: The local data buffers of this module are kept at a central location for a better overview and maintenance.
    Risk: Scope is larger than required (whole file instead of one function). Some other function could access
      the variable.
    Prevention: Restrict the functionality in this module to the intended purpose. Don't add functions which shall not
      be able to access the local data buffers.

  MD_FblCw_3673:
    Reason: The prototype is not adapted because future code additions might use the respective parameter as output.
    Risk: The parameter value might be changed unintentionally, thus causing malfunction in the calling instance.
    Prevention: All changes to the affected code parts have to be reviewed by the module responsible.

  MD_FblCw_4304_BooleanCast:
    Reason: A bool result is casted to the AUTOSAR boolean (unsigned char).
    Risk: No identifiable risk.
    Prevention: No prevention required.

  MD_FblCw_4394_SignedCast:
    Reason: A cast from an unsigned to signed type is performed to get also negative values.
    Risk: No identifiable risk.
    Prevention: No prevention required.

*/

/**********************************************************************************************************************
 *  END OF FILE: FBL_CW.C
 *********************************************************************************************************************/
