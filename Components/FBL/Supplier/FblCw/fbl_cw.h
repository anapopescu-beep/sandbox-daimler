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
 *         File:  fbl_cw.h
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
 *  Version    Date        Author  Change Id        Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  06.00.00   2020-06-04  visrie  FBL-1016         Support EcuM_Init() mechanism
 *  06.00.01   2020-07-07  vistbe  ESCAN00097857    Stay in Boot / Force boot mode is supported for CAN only
 *  06.00.02   2020-08-05  visjdn  ESCAN00105438    DET cannot be removed from Bootloader project
 *  06.00.03   2020-09-03  vistmo  ESCAN00106854    Queued request reception can cause communication to lock up
 *                                 ESCAN00106991    Bootloader is not able to communicate
 *  06.00.04   2020-09-22  visrcn  FBL-2367         Fix generator issues related to NM handling
 *  06.00.05   2020-10-15  visrcn  ESCAN00107399    Exception due to NULL pointer access during StayInBoot
 *  06.01.00   2020-10-26  visrcn  ESCAN00107400    Dummy NM indication with message length != 8 does not work
 *  06.01.01   2021-03-26  vistbe  ESCAN00108314    DET called during FblCw_Init (caused by ComM)
 *                                 FBL-3066         Added/adapted MemMap sections
 *  06.01.02   2021-06-15  vistbe  ESCAN00109326    Queued request reception can cause communication to lock up
 *  06.02.00   2021-07-26  visjdn  FBL-2256         Add support for MSR4 LIN slave
 *                                 FBL-3348         Adapt MemMap sections for callback functions
 *                                 ESCAN00108234    Compiler error: function Dcm_ComM_(Full/SilteNo)ComModeEntered
 *                                                  declared implicitly
 *  06.02.01   2021-09-01  visjdn  ESCAN00109577    Compiler error: Unknown symbols EthIf_MainFunction, EthSM_MainFunction,
 *                                                  Eth_<Infix>_MainFunction and EthTrcv_<Infix>_MainFunction
 *  06.03.00   2021-10-04  vistbe  FBL-3385         Add support for multiple ETH transceivers & R27 ComM
 *  06.03.01   2022-03-03  vishor  ESCAN00111320    Bootloader is not able to communicate or the response is on the
 *                                                   wrong connection
 *  06.03.02   2022-04-12  vismix  ESCAN00111553    Bootloader is not able to communicate
 *  06.03.03   2022-04-25  vistbe  ESCAN00111380    vBsdAd Mainfunction not called by FBL
 *  06.04.00   2022-05-13  vismix  FBL-5107         Support FlexRay change/read bandwidth parameters
 *  06.04.01   2022-06-29  vismix  ESCAN00111660    Compiler error: LinIf_GlobalTimeBaseMS/LinIf_MainFunction undefined
 *  06.04.02   2023-02-01  vistbe  ESCAN00112194    SetPduMode to online missing after baudrate switch
 *********************************************************************************************************************/

#ifndef FBL_CW_H
# define FBL_CW_H

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/
# define FBLWRAPPERCOM_PDUR_VERSION           0x0604u
# define FBLWRAPPERCOM_PDUR_RELEASE_VERSION   0x02u

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"
# include "Dcm_Cbk.h"
# include "FblCw_Cfg.h"
# include "FblCw_Lcfg.h"

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/**
  \defgroup  FblCwIdentification FblCw Identification
  \brief  Vendor and module identification of this implementation.
  \{
*/
# define FBLCW_VENDOR_ID              30u              /**< the vendor ID of this implementation. */
# define FBLCW_MODULE_ID              255u             /**< the module ID of this implementation. */
/**
  \}
*/

/**
  \defgroup  FblCwARReleaseVersion FblCw AUTOSAR release version number
  \brief  Version number of AUTOSAR release on which the appropriate implementation is based on.
  \{
*/
# define FBLCW_AR_RELEASE_MAJOR_VERSION       4u
# define FBLCW_AR_RELEASE_MINOR_VERSION       0u
# define FBLCW_AR_RELEASE_REVISION_VERSION    3u
/**
  \}
*/

/**
  \defgroup  FblCwDetErrorCodes FblCw Det Error Codes
  \brief  FblCw development error IDs.
  \{
*/
# define FBLCW_E_NO_ERROR                    0u /**< this code is used to detect that no error occurred. Det_ReportError() is not called.  */
# define FBLCW_E_PARAM                       1u /**< the API service has been with a wrong parameter. */
# define FBLCW_E_UNINIT                      2u /**< the API service has been called before FblCw was initialized with FblCw_Init() or after a call to FblCw_DeInit() */
# define FBLCW_E_PARAM_POINTER               3u /**< the API service has been called with a not expected NULL pointer */
# define FBLCW_E_INIT_FAILED                 4u /**< the API service has been when FblCw was already initialized. */
/**
  \}
*/

/**
  \defgroup  FblCwApiIds FblCw Module Service Identifiers
  \brief  Unique identifier of a FblCw module service.
  \{
*/
# define FBLCW_APIID_INIT                      0u
# define FBLCW_APIID_STARTOFRECEPTION          1u
# define FBLCW_APIID_COPYRXDATA                2u
# define FBLCW_APIID_COPYTXDATA                3u
# define FBLCW_APIID_TPRXINDICATION            4u
# define FBLCW_APIID_TPTXCONFIRMATION          5u
/**
  \}
*/

/* Reference interface version */
/** Major interface version identifies incompatible changes */
# define FBL_CW_API_REFERENCE_VERSION_MAJOR      0x02u
/** Minor interface version identifies backward compatible changes */
# define FBL_CW_API_REFERENCE_VERSION_MINOR      0x00u
/** Release interface version identifies cosmetic changes */
# define FBL_CW_API_REFERENCE_VERSION_RELEASE    0x00u

# if defined( kFblCwTxPendingTimeout )
# else
/** Retry timeout for transmission */
#  if( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
#   define kFblCwTxPendingTimeout           (5000u / FBL_REPEAT_CALL_CYCLE)
#  else
#   define kFblCwTxPendingTimeout           (100u / FBL_REPEAT_CALL_CYCLE)
#  endif
# endif
# if defined( kFblCwMaxWaitTime )
# else
/** Wait time for transmission in case response pending is in progress */
#  if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
#   define kFblCwMaxWaitTime                (1000u / FBL_REPEAT_CALL_CYCLE)
#  else
#   define kFblCwMaxWaitTime                (10u / FBL_REPEAT_CALL_CYCLE)
#  endif
# endif
/** Default value for CanIf mode switch timeout */
# if defined( kFblCwTxModeSwitchTimeout )
# else
/** Wait time for CanIf mode switch */
#  define kFblCwTxModeSwitchTimeout        (100u / FBL_REPEAT_CALL_CYCLE)
# endif

/** Default waiting time for shutdown callback */
# if defined (kFblCwShutdownWaitTime)
# else
#  define kFblCwShutdownWaitTime           (4500u / FBL_REPEAT_CALL_CYCLE)
# endif

/* Flag if a call to Timer or State Task is currently allowed
   Commonly this is used e.g. to prevent a call to the tasks if a flash operation
   is currently in progress and the tasks cannot be called, because they are complex and in ROM.
   But this configuration is mandatory for RCR-RP handling when the MSR communcation stack is used. */

/* All Task code is in RAM */
# define FblCwIsTimerTaskAllowed()        0x01u
# define FblCwIsStateTaskAllowed()        0x01u

/** This define indicates task locks are handled by ComWrapper */
# define FBL_CW_LOCKS_TASKS
/** This define indicates task locks are handled by ComWrapper (compatibility variant) */
# define FBLCW_LOCKS_TASKS

/* Call parameter type for reset cases */
/** This define will be used in case of regular ECU reset e.g. after 11 01 */
# define kFblCwResetEcuRegularCase         0x00u
/** This define will be used in case of non-regular reset of the diagnostic e.g.: Timeout, EcuReset with SuppressPosRsp */
# define kFblCwResetEcuTesterTimeout       0x01u

/* Macros for compatibility */
# define FblCwSetOfflineMode()
# define FblCwSetOnlineMode()

/** Re-map CwTransmit to CwCanTransmit, because response type is not required here */
# define FblCwTransmit(data, length, type) FblCwPduTransmit((data), (length)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
/** Re-map FblCwShutdownRequest to FblCwPduShutdownRequest, because reset case is not needed here */
#  define FblCwShutdownRequest(a)           FblCwPduShutdownRequest() /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# else
/* Shutdown request from Diag-layer to Com-Wrapper */
#  define FblCwShutdownRequest(a)          FblSetShutdownRequest() /* PRQA S 3453 */    /* MD_MSR_FctLikeMacro */
# endif

/* Parameter CallType for FblCwTransmit. Not used, but included for compatibility */
# define kFblCwTxCallPosResponse           0x00u
# define kFblCwTxCallNegResponse           0x01u
# define kFblCwTxCallFailedResponse        0x02u
# define kFblCwTxCallRcrRp                 0x03u
# define kFblCwTxCallNoResponse            0x04u

/* Parameter for FblDiagConfirmation and FblDiagTxErrorIndication */
# define kFblCwMsgTypeNormal               0x00u   /**< Default response */
# define kFblCwMsgTypeRcrRp                0x03u   /**< Response pending message */

/** Length of the RCRP messages */
# define kFblCwRcrRpMsgLength              0x03u


/* Macros for compatibility */
# define FblCwDiscardReception()
# define FblCwSetTxInit()
# define FblCwSetRxBlock()

# if ( FBLCW_MODULE_FRSM == STD_ON )
/* Macros for detection of wake-up event */
#  define FblCwGetWakeUpEvent()           (0x01u == cwWakeUpFlag)
#  define FblCwSetWakeUpEvent()           (cwWakeUpFlag = 0x01u)
#  define FblCwClrWakeUpEvent()           (cwWakeUpFlag = 0x00u)
# endif

# if (FBLCW_CHANGE_PARAMETER == STD_OFF)
#  define FblCw_ResetParameter() kFblOk
# endif

# if (FBLCW_MAXIMUM_SIZE_OF_DCM_DSL_CONNECTION_INFO > 1u)
/** More than one connection configured */
#  define FBL_CW_ENABLE_MULTIPLE_CONNECTIONS
# endif


# if (FBLCW_DECLINED_REQUESTS == STD_ON)
#  define kFblCwNumberOfRequests (kFblCwMaxNumDeclinedRequests + 1u)
#  define FBL_CW_ENABLE_DECLINED_REQUESTS
# else
#  define kFblCwNumberOfRequests 1u
# endif
# define FBL_CW_MAIN_REQUEST_INDEX 0u

/**********************************************************************************************************************
 *  CONSISTENCY CHECK
 *********************************************************************************************************************/
#if ( FBLCW_KEY_SLOT_MODE == STD_ON )
# if ( FBLCW_USE_INIT_POINTER == STD_ON)
#  error "FBLCW_KEY_SLOT_MODE is not supported if FBLCW_USE_INIT_POINTER is used!"
# endif
# if !defined (FBLCW_NW_STATUS_PDU)
#  error "Define the FBLCW_NW_STATUS_PDU in the user config file! At this point the handle ID of the FrIfLPdu of the first slot shall be configured."
# endif
#endif

#if defined ( FRNM_NUMBER_OF_FRNM_CHANNELS )
# if ( FRNM_NUMBER_OF_FRNM_CHANNELS > 1u )
#  error "Multiple FrNm channels are currently not supported"
# endif /* FRNM_NUMBER_OF_FRNM_CHANNELS > 1 */
#endif /* FRNM_NUMBER_OF_FRNM_CHANNELS */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/** Data type to handle the RxTesterSourceAddress as a 16 bit value */
typedef uint16 FblCw_RxTesterSourceAddressOfDcmDslConnectionInfo16BitType; /* PRQA S 0779 */  /* MD_FblCw_0779 */

/** Data type for CW length information */
typedef PduLengthType tCwDataLengthType;
typedef tCwDataLengthType tTpDataType;




#if ( FBLCW_EXISTS_FR_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
# if ( FBLCW_KEY_SLOT_MODE == STD_ON)
typedef vuint16 tCwNwStatus;
# endif /* FBL_CW_ENABLE_KEY_SLOT_MODE */
#endif /* FBL_CW_ENABLE_BUSTYPE_FR */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FBLCW_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  FblCw_InitMemory
**********************************************************************************************************************/
/*! \brief    The function initializes variables, which cannot be initialized with the startup code.
    \details  -
    \context  TASK
    \synchronous TRUE
    \reentrant   FALSE
    \pre      FblCw_Init() is not called yet.
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_InitMemory(void);

/**********************************************************************************************************************
  FblCw_Init
**********************************************************************************************************************/
/*! \brief    This service initializes internal and external interfaces and variables of the MICROSAR FBLCW layer
              for the further processing.
    \details  -
    \param[in] config  NULL_PTR if FBLCW_USE_INIT_POINTER is STD_OFF
                      Pointer to the FblCw configuration data if FBLCW_USE_INIT_POINTER is STD_ON
    \context  TASK
    \warning  FblCw_Init shall not pre-empt any FblCw function.
              The rest of the system must guarantee that FblCw_Init is not called in such a way.
    \synchronous TRUE
    \reentrant   FALSE
    \pre      FblCw_InitMemory() has to be executed previously, if the startup code does not initialize variables.
    \pre      FblCw is not in initialized state.
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_Init(P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) config);

/**********************************************************************************************************************
  FblCw_Deinit
**********************************************************************************************************************/
/*! \brief    By a call to ComDeInit FblCw is put into an not initialized state.
    \details  -
    \context  TASK
    \warning  FblCw_Deinit shall not pre-empt any FblCw function.
              The rest of the system must guarantee that FblCw_DeInit is not called in such a way.
    \synchronous TRUE
    \reentrant   FALSE
    \pre      -
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_Deinit(void);

/**********************************************************************************************************************
 *  FblCwIdleTask
 *********************************************************************************************************************/
/*! \brief       Communication wrapper idle task function
 *  \details     The function polls the communication channels, it also executes some pending actions,
 *               which could not fulfilled in the event function.
 *               Note, that the order of polling is a design decision: Error-Task, TX-Task, RX-Task.
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwIdleTask(void);

/**********************************************************************************************************************
 *  FblCwTimerTask
 *********************************************************************************************************************/
/*! \brief       Communication wrapper timer task function
 *  \detail      Typically called with a 1 ms cycle time
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwTimerTask(void);

/**********************************************************************************************************************
 *  FblCwStateTask
 *********************************************************************************************************************/
/*! \brief       Polling of CAN/FlexRay receive messages and message confirmation
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwStateTask(void);

/**********************************************************************************************************************
 *  FblCwPduTransmit
 *********************************************************************************************************************/
/*! \brief       Schedule data for transmission.
 *  \param[in]   data Pointer to transmit data
 *  \param[in]   length Length of data
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwPduTransmit(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data, tCwDataLengthType length);

# if (FBLCW_DECLINED_REQUESTS == STD_ON)
/**********************************************************************************************************************
 *  FblCwPduTransmitDeclinedRequest
 *********************************************************************************************************************/
/*! \brief       Schedule data for transmission.
 *  \param[in]   data Pointer to transmit data
 *  \param[in]   length Length of data
 *  \param[in]   connectionIndex Connection index of declined messages
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwPduTransmitDeclinedRequest(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data, tCwDataLengthType length, vuint8 connectionIndex);
# endif

/**********************************************************************************************************************
 *  FblCwTransmitRP
 *********************************************************************************************************************/
/*! \brief       Transmit given data buffer with RCR-RP
 *  \pre         CW is initialized
 *  \param[in]   data Pointer to the data to be transmitted
 *********************************************************************************************************************/
void FblCwTransmitRP(const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data);

/**********************************************************************************************************************
 *  FblCwRetransmitRP
 *********************************************************************************************************************/
/*! \brief       Transmit the stored response pending buffer
 *  \pre         CW is initialized, FblCwTransmitRP executed before
 *********************************************************************************************************************/
void FblCwRetransmitRP(void);


/**********************************************************************************************************************
 *  FblCwTxSetTargetAddress
**********************************************************************************************************************/
/*! \brief       Prepare response address.
 *  \param[in]   targetAddress  Target node addressed in response
**********************************************************************************************************************/
void FblCwTxSetTargetAddress(FblCw_DcmDslConnectionInfoIterType targetAddress);

/**********************************************************************************************************************
 *  FblCwTxGetTargetAddress
**********************************************************************************************************************/
/*! \brief       Get active response address / connection.
 *  \return      Active response address / connection
**********************************************************************************************************************/
FblCw_DcmDslConnectionInfoIterType FblCwGetResponseAddress(void);

/**********************************************************************************************************************
 *  FblCwResetResponseAddress
 *********************************************************************************************************************/
/*! \brief       Reset response address / connection to default value
 *********************************************************************************************************************/
void FblCwResetResponseAddress(void);

/**********************************************************************************************************************
 *  FblCwPrepareResponseAddress
 *********************************************************************************************************************/
/*! \brief       Read target address from NV-memory and prepare response address
 *  \return      kFblOk if setting response address was successful, kFblFailed otherwise
 *********************************************************************************************************************/
tFblResult FblCwPrepareResponseAddress(void);

/**********************************************************************************************************************
 *  FblCwSaveResponseAddress
 *********************************************************************************************************************/
/*! \brief       Save response address to NV-memory
 *  \return      kFblOk if address was successfully store, kFblFailed otherwise
 *********************************************************************************************************************/
tFblResult FblCwSaveResponseAddress(void);

# if ( FBLCW_BAUDRATE_SWITCH == STD_ON )
/**********************************************************************************************************************
 *  FblCwCheckBaudrate
 *********************************************************************************************************************/
/*! \brief       Check whether requested baud rate is supported for active connection
 *  \param[in]   baudrate  Requested baud rate (in kBaud)
 *  \return      kFblOk if baud rate is supported for active connection, kFblFailed otherwise
 *********************************************************************************************************************/
tFblResult FblCwCheckBaudrate(vuint32 baudrate);

/**********************************************************************************************************************
 *  FblCwSwitchBaudrate
 *********************************************************************************************************************/
/*! \brief       Switch baud rate of active connection
 *  \param[in]   baudrate Requested baud rate (in kBaud)
 *  \return      kFblOk if baud rate was successfully switched, kFblFailed otherwise
 *********************************************************************************************************************/
tFblResult FblCwSwitchBaudrate(vuint32 baudrate);
# endif

/**********************************************************************************************************************
 *  FblCwResetRxBlock
 *********************************************************************************************************************/
/*! \brief       Reset transport layer called by DiagResponseProcessor
 *********************************************************************************************************************/
void FblCwResetRxBlock(void);

/**********************************************************************************************************************
 *  FblCwGetPayloadLimit
 *********************************************************************************************************************/
/*! \brief       Get payload limit of active connection
 *  \return      Payload limit of active connection in bytes
 *********************************************************************************************************************/
tCwDataLengthType FblCwGetPayloadLimit(void);

# if (FBLCW_CHANGE_PARAMETER == STD_ON)
/**********************************************************************************************************************
 *  FblCw_ChangeParameter
 *********************************************************************************************************************/
/*! \brief      This API function is used to change transport layer parameters
 *  \param[in]  parameter Parameter type that shall be changed
 *  \param[in]  value New value of given parameter type
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ChangeParameter(TPParameterType parameter, uint16 value);

/**********************************************************************************************************************
 *  FblCw_ResetParameter
 *********************************************************************************************************************/
/*! \brief      This API function is used to reset transport layer parameters to default values
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ResetParameter(void);

/**********************************************************************************************************************
 *  FblCw_ReadParameter
 *********************************************************************************************************************/
/*! \brief      This API function is used to read transport layer parameters
 *  \param[in]  parameter Parameter type that shall be read
 *  \param[out] value Reference of parameter value
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ReadParameter(TPParameterType parameter, uint16 * value);
# endif

# if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
/**********************************************************************************************************************
  FblCwPduShutdownRequest
**********************************************************************************************************************/
/*! \brief      Shutdown all connections to prepare for reset
**********************************************************************************************************************/
void FblCwPduShutdownRequest(void);
# endif


# define FBLCW_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL DATA DECLARATIONS
 *********************************************************************************************************************/
# if(FBLCW_USE_INIT_POINTER == STD_ON)
#  define FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern P2CONST(FblCw_ConfigType, FBLCW_VAR_ZERO_INIT, FBLCW_PBCFG) FblCw_ConfigDataPtr;

#  define FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif

# define FBLCW_START_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */



# define FBLCW_STOP_SEC_VAR
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif

/**********************************************************************************************************************
 *  END OF FILE: FBL_CW.H
 *********************************************************************************************************************/
