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
 *            Module: Dcm
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Lcfg.c
 *   Generation Time: 2024-01-04 13:37:42
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] DCM06009 - Invalid data identifier (DID) configuration - DcmDspDidSignal signals overlap. 
 * - [Reduced Severity due to User-Defined Parameter] Signal /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ECU_Extract_Version_Read/ECU_Extract_Information_Checksum and signal /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ECU_Extract_Version_Read/ECU_Extract_Information_ECU_Name overlap.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/ECU_Extract_Version_Read_ECU_Extract_Information_Checksum[0:DcmDspDataSize](value=320) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataSize)
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/ECU_Extract_Version_Read_ECU_Extract_Information_ECU_Name[0:DcmDspDataSize](value=248) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataSize)
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ECU_Extract_Version_Read/ECU_Extract_Information_Checksum[0:DcmDspDidDataPos](value=432) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidSignal/DcmDspDidDataPos)
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ECU_Extract_Version_Read/ECU_Extract_Information_ECU_Name[0:DcmDspDidDataPos](value=192) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidSignal/DcmDspDidDataPos)
 * 
 * [Warning] DCM06009 - Invalid data identifier (DID) configuration - DcmDspDidSignal signals overlap. 
 * - [Reduced Severity due to User-Defined Parameter] Signal /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ECU_Extract_Version_Read/ECU_Extract_Information_Checksum and signal /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ECU_Extract_Version_Read/ECU_Extract_Information_ECU_Name overlap.
 * Erroneous configuration elements:
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/ECU_Extract_Version_Read_ECU_Extract_Information_Checksum[0:DcmDspDataSize](value=320) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataSize)
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/ECU_Extract_Version_Read_ECU_Extract_Information_ECU_Name[0:DcmDspDataSize](value=248) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspData/DcmDspDataSize)
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ECU_Extract_Version_Read/ECU_Extract_Information_Checksum[0:DcmDspDidDataPos](value=432) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidSignal/DcmDspDidDataPos)
 * /ActiveEcuC/Dcm/DcmConfigSet/DcmDsp/DID_ECU_Extract_Version_Read/ECU_Extract_Information_ECU_Name[0:DcmDspDidDataPos](value=192) (DefRef: /MICROSAR/Dcm/DcmConfigSet/DcmDsp/DcmDspDid/DcmDspDidSignal/DcmDspDidDataPos)
 *********************************************************************************************************************/


#define DCM_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
                                                                                                                                                     /* PRQA S 1533 EOF */ /* MD_Dcm_ObjectOnlyAccessedOnce */
#include "Dcm.h"
#include "Rte_Dcm.h"
#include "Dcm_Int.h"
#include "PduR_Dcm.h"
#include "ComM_Dcm.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if (DCM_DIDMGR_NVM_READ_ENABLED == STD_ON) || \
    (DCM_DIDMGR_NVM_WRITE_ENABLED == STD_ON)
# if defined(NVM_VENDOR_ID)
#  if (NVM_VENDOR_ID == 30u)
/* Only Vector NvM supports this feature up to now */
#   define Dcm_GetDcmNvMBlockId(blockId)                             (uint16)(NvM_GetDcmBlockId(blockId))                                            /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
#  endif
# endif

/* Default NvM handle offset */
# if !defined(Dcm_GetDcmNvMBlockId)
#  define Dcm_GetDcmNvMBlockId(blockId)                              (uint16)(blockId)                                                               /* PRQA S 3453 */ /* QAC 7.0:  A function could probably be used instead of this function-like macro */ /* Macro is more efficient! */
# endif
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Major_Version_ReadData()
 ***********************************************************************************************************************/
/*! \brief         Wraps DIDs read interface.
 *  \details       Stores the constant configuration data into the provided data context.
 *  \param[in,out] pDataContext   Pointer to the data context
 *  \return        E_OK           The data is successfully provided
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Major_Version_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  );
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Minor_Version_ReadData()
 ***********************************************************************************************************************/
/*! \brief         Wraps DIDs read interface.
 *  \details       Stores the constant configuration data into the provided data context.
 *  \param[in,out] pDataContext   Pointer to the data context
 *  \return        E_OK           The data is successfully provided
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Minor_Version_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  );
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Patch_Version_ReadData()
 ***********************************************************************************************************************/
/*! \brief         Wraps DIDs read interface.
 *  \details       Stores the constant configuration data into the provided data context.
 *  \param[in,out] pDataContext   Pointer to the data context
 *  \return        E_OK           The data is successfully provided
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Patch_Version_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  );
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ReadData()
 ***********************************************************************************************************************/
/*! \brief         Wraps DIDs read interface.
 *  \details       Stores the constant configuration data into the provided data context.
 *  \param[in,out] pDataContext   Pointer to the data context
 *  \return        E_OK           The data is successfully provided
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  );
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ReadData()
 ***********************************************************************************************************************/
/*! \brief         Wraps DIDs read interface.
 *  \details       Stores the constant configuration data into the provided data context.
 *  \param[in,out] pDataContext   Pointer to the data context
 *  \return        E_OK           The data is successfully provided
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  );
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ReadData()
 ***********************************************************************************************************************/
/*! \brief         Wraps DIDs read interface.
 *  \details       Stores the constant configuration data into the provided data context.
 *  \param[in,out] pDataContext   Pointer to the data context
 *  \return        E_OK           The data is successfully provided
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  );
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ReadData()
 ***********************************************************************************************************************/
/*! \brief         Wraps DIDs read interface.
 *  \details       Stores the constant configuration data into the provided data context.
 *  \param[in,out] pDataContext   Pointer to the data context
 *  \return        E_OK           The data is successfully provided
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0203_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0203_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0207_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0207_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0260_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0260_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0261_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0261_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0262_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0262_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0263_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0263_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0264_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0264_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0266_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0266_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0267_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0267_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0268_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0268_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0268_Stop()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0268_Stop(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0268_RequestResults()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0268_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0274_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0274_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0277_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0277_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0279_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0279_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_027B_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_027B_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_027D_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_027D_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0302_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0302_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0302_RequestResults()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0302_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0329_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0329_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0329_RequestResults()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0329_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0330_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0330_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_0330_RequestResults()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0330_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_F703_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F703_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_F703_RequestResults()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F703_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_F782_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F782_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_RidMgr_F791_Start()
 ***********************************************************************************************************************/
/*! \brief         Wraps RIDs execution interface.
 *  \details       Converts uint8 arrays to other signal types required by the RID execution interface and vice versa.
 *  \param[in]     OpStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier
 *  \param[in,out] DataLength         IN: Concrete length of the dynamic request signal
 *                                    OUT: Concrete length of the dynamic response Signal
 *  \param[out]    ErrorCode          Negative response code
 *  \return        E_OK               The operation is finished
 *  \return        DCM_E_PENDING      The operation is not yet finished
 *  \return        DCM_E_FORCE_RCRRP  Forces a RCR-RP response
 *                                    The call out will called again once the response is sent. The OpStatus parameter
 *                                    will contain the transmission result
 *  \return        E_NOT_OK           The operation has failed. A concrete NRC shall be set, otherwise the DCM sends NRC
 *                                    0x22
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F791_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_RidMgrRidLengthPtrType DataLength,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_SvcWrapper_Ssa_Cdd_DiagnosticService_Authentication_0x29()
 ***********************************************************************************************************************/
/*! \brief         Wraps a specific externally implemented service-processor.
 *  \details       Encapsulates the internally used pContext parameter.
 *  \param[in]     pContext              Pointer to the context
 *  \param[in]     opStatus              The operation status
 *  \param[in,out] pMsgContext           Message-related information for one diagnostic protocol identifier
 *                                       The pointers in pMsgContext points behind the SID.
 *  \param[out]    ErrorCode             Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_OK              Job processing finished, send positive response
 *  \return        DCM_E_PENDING         Job processing is not yet finished
 *  \return        DCM_E_FORCE_RCRRP     (Vendor extension) Forces a RCR-RP response.
 *                                       The call out will called again once the response is sent. The OpStatus
 *                                       parameter will contain the transmission result
 *  \return        DCM_E_PROCESSINGDONE  (Vendor extension) Can be returned instead of calling Dcm_ProcessingDone() for
 *                                       the current pMsgContext.
 *                                       Saves application code and stack usage.
 *  \return        DCM_E_STOP_REPEATER   Stops the repeater proxy
 *  \return        DCM_E_NOT_OK          Job processing finished, send NRC from the ErrorCode
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SvcWrapper_Ssa_Cdd_DiagnosticService_Authentication_0x29(
  Dcm_ContextPtrType pContext,
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
 ***********************************************************************************************************************/
/*! \brief         Dummy post-processor
 *  \details       This post-processor is called for diagnostic services which do not require any post processing.
 *  \param[in]     pContext  Pointer to the context
 *  \param[in]     status    The post-processing status
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(
  Dcm_ContextPtrType pContext,
  Dcm_ConfirmationStatusType status
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
 ***********************************************************************************************************************/
/*! \brief         Realizes a dummy paged buffer updater.
 *  \details       This function is never called.
 *  \param[in]     pContext      Pointer to the context
 *  \param[in]     opStatus      The operation status
 *  \param[in,out] pDataContext  Pointer to the data context
 *  \param[out]    ErrorCode     Negative response code
 *  \return        E_NOT_OK      Operation failed. Take the NRC from ErrorCode. Do not call again
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(
  Dcm_ContextPtrType pContext,
  Dcm_OpStatusType opStatus,
  Dcm_DiagDataContextPtrType pDataContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  );
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
 ***********************************************************************************************************************/
/*! \brief         Dummy service cancellation.
 *  \details       -
 *  \param[in]     pContext      Pointer to the context
 *  \context       TASK
 *  \reentrant     FALSE
 *  \pre           -
 ***********************************************************************************************************************/
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(
  Dcm_ContextPtrType pContext
  );
#define DCM_STOP_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA DECLARATIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DCM protocol descriptor */
DCM_LOCAL VAR(Dcm_MsgItemType, DCM_VAR_NOINIT) Dcm_CfgNetBuffer_000[4095];
#define DCM_STOP_SEC_VAR_NO_INIT_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! TxPduId to DCM connection map */
CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo_Left[3]=
{
    0u
  , 1u
  , 2u
};
/*! Map of DCM relevant network handles */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap_Left[1]=
{
    0u
};
/*! Service 0x28 list of channels for the all-comm-channel parameter */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetComCtrlChannelListAll_Left[2]=
{
   1u
  , 0u
};
/*! TxPduId to DCM connection map */
CONST(Dcm_NetConnRefMemType, DCM_CONST) Dcm_CfgNetTxPduInfo_Right[3]=
{
    2u
  , 0u
  , 1u
};
/*! Map of DCM relevant network handles */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetConnComMChannelMap_Right[1]=
{
    0u
};
/*! Service 0x28 list of channels for the all-comm-channel parameter */
CONST(Dcm_CfgNetNetIdRefMemType, DCM_CONST) Dcm_CfgNetComCtrlChannelListAll_Right[2]=
{
   1u
  , 0u
};
/*! Look up table of all supported ALFIDs */
CONST(uint8, DCM_CONST) Dcm_CfgMemMgrAlfidLookUpTable[17]=
{
   16u
  ,0x11u
  ,0x12u
  ,0x13u
  ,0x14u
  ,0x21u
  ,0x22u
  ,0x23u
  ,0x24u
  ,0x31u
  ,0x32u
  ,0x33u
  ,0x34u
  ,0x41u
  ,0x42u
  ,0x43u
  ,0x44u
};
/*! Look up table of all supported MIDs */
CONST(uint8, DCM_CONST) Dcm_CfgMemMgrMidLookUpTable[1]=
{
   0u
};
/*! Look up table of DCM service identifiers */
CONST(uint8, DCM_CONST) Dcm_CfgDiagSvcIdLookUpTable[14]=
{
   13u
  ,0x10u
  ,0x11u
  ,0x14u
  ,0x19u
  ,0x22u
  ,0x23u
  ,0x28u
  ,0x29u
  ,0x2Eu
  ,0x31u
  ,0x3Du
  ,0x3Eu
  ,0x85u
};
/*! Service 0x10 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc10SubFuncLookUpTable[5]=
{
   4u
  ,0x01u
  ,0x02u
  ,0x03u
  ,0x7Eu
};
/*! Service 0x11 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc11SubFuncLookUpTable[5]=
{
   4u
  ,0x01u
  ,0x03u
  ,0x04u
  ,0x05u
};
/*! Service 0x19 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc19SubFuncLookUpTable[7]=
{
   6u
  ,0x01u
  ,0x02u
  ,0x04u
  ,0x06u
  ,0x0Au
  ,0x14u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubFuncLookUpTable[3]=
{
   2u
  ,0x00u
  ,0x01u
};
/*! Service 0x28 look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28MessageTypeLookUpTable[4]=
{
   3u
  ,0x01u
  ,0x02u
  ,0x03u
};
/*! Service 0x28 network ID lookup */
CONST(uint8, DCM_CONST) Dcm_CfgSvc28SubNetIdLookUp[3]=
{
   2u
  ,0x00u
  ,0x0Fu
};
/*! Service 0x3E look up table  */
CONST(uint8, DCM_CONST) Dcm_CfgSvc3ESubFuncLookUpTable[2]=
{
   1u
  ,0x00u
};
/*! Look up table of service 0x85 */
CONST(uint8, DCM_CONST) Dcm_CfgSvc85SubFuncLookUpTable[3]=
{
   2u
  ,0x01u
  ,0x02u
};
#define DCM_STOP_SEC_CONST_8
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_16
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgDidMgrDidLookUpTable[94]=
{
   93u
  ,0x0100u
  ,0x0102u
  ,0x0107u
  ,0x010Au
  ,0x010Bu
  ,0x0131u
  ,0x0133u
  ,0x0136u
  ,0x0138u
  ,0x0140u
  ,0x0142u
  ,0x0180u
  ,0x0181u
  ,0x0182u
  ,0x0184u
  ,0x0185u
  ,0x0186u
  ,0x0187u
  ,0x0188u
  ,0x0189u
  ,0x018Au
  ,0x018Cu
  ,0x018Du
  ,0x018Eu
  ,0x018Fu
  ,0x0190u
  ,0x0191u
  ,0x0197u
  ,0x0198u
  ,0x0199u
  ,0x019Au
  ,0x019Bu
  ,0x019Cu
  ,0x019Du
  ,0x019Eu
  ,0x019Fu
  ,0x01A2u
  ,0x01E0u
  ,0x01E1u
  ,0x01E3u
  ,0x01E4u
  ,0x0200u
  ,0x0210u
  ,0x0220u
  ,0x0240u
  ,0x0241u
  ,0x0242u
  ,0x0243u
  ,0x0244u
  ,0x02EAu
  ,0x0300u
  ,0x0301u
  ,0x0302u
  ,0x0310u
  ,0x0311u
  ,0x0340u
  ,0xE104u
  ,0xEF00u
  ,0xEF01u
  ,0xEF03u
  ,0xEF04u
  ,0xEF05u
  ,0xF100u
  ,0xF103u
  ,0xF104u
  ,0xF10Du
  ,0xF111u
  ,0xF121u
  ,0xF131u
  ,0xF150u
  ,0xF151u
  ,0xF153u
  ,0xF154u
  ,0xF155u
  ,0xF15Bu
  ,0xF18Cu
  ,0xF190u
  ,0xF804u
  ,0xFD01u
  ,0xFD03u
  ,0xFD04u
  ,0xFD08u
  ,0xFD09u
  ,0xFD10u
  ,0xFD2Au
  ,0xFD2Fu
  ,0xFD30u
  ,0xFD31u
  ,0xFD50u
  ,0xFDDFu
  ,0xFDFFu
  ,0xFE00u
  ,0xFEFFu
};
/*! RID look up table  */
CONST(uint16, DCM_CONST) Dcm_CfgRidMgrRidLookUpTable[25]=
{
   24u
  ,0x0203u
  ,0x0207u
  ,0x0211u
  ,0x0212u
  ,0x0245u
  ,0x0260u
  ,0x0261u
  ,0x0262u
  ,0x0263u
  ,0x0264u
  ,0x0266u
  ,0x0267u
  ,0x0268u
  ,0x0274u
  ,0x0277u
  ,0x0279u
  ,0x027Bu
  ,0x027Du
  ,0x0302u
  ,0x0329u
  ,0x0330u
  ,0xF703u
  ,0xF782u
  ,0xF791u
};
#define DCM_STOP_SEC_CONST_16
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! DCM buffer descriptor */
CONST(Dcm_CfgNetBufferInfoType, DCM_CONST) Dcm_CfgNetBufferInfo[1]=
{
   { Dcm_CfgNetBuffer_000,4095u}
};
/*! DCM protocol switch notifications */
CONST(Dcm_CfgNetProtocolNotificationInfoType, DCM_CONST) Dcm_CfgNetProtocolNotificationInfo[1]=
{
   { NULL_PTR}
};
/*! RxPduId map */
CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo_Left[6]=
{
   { TRUE, 0u}
  ,{ FALSE, 0u}
  ,{ TRUE, 1u}
  ,{ FALSE, 1u}
  ,{ TRUE, 2u}
  ,{ FALSE, 2u}
};
/*! DCM connection descriptor */
CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo_Left[3]=
{
   { 0x0EF9u,PduRConf_PduRSrcPdu_PduRSrcPdu_7f35c914, 0u,0u,0x00u,0x00u, 0u}
  ,{ 0x0EF8u,PduRConf_PduRSrcPdu_PduRSrcPdu_249a1158, 0u,0u,0x00u,0x00u, 0u}
  ,{ 0x0F0Du,PduRConf_PduRSrcPdu_PduRSrcPdu_3fa3fd23, 0u,0u,0x00u,0x00u, 0u}
};
/*! DCM protocol descriptor */
CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo_Left[1]=
{
   { {        0u,       0u},4095u, 3u, 0u,TRUE,0u,DemConf_DemClient_DemClient, 0u}
};
/*! Map of all relevant for DCM network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap_Left[1]=
{
   ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6
};
/*! Look up table of DCM relevant network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable_Left[2]=
{
   1u
  ,ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6
};
/*! Communication variant specifics */
CONST(Dcm_CfgNetVariantInfoType, DCM_CONST) Dcm_CfgNetConfig_Left=
{
   Dcm_CfgNetRxPduInfo_Left
  ,Dcm_CfgNetConnectionInfo_Left
  ,Dcm_CfgNetProtocolInfo_Left
  ,Dcm_CfgNetConnComMChannelMap_Left
  ,Dcm_CfgNetNetworkHandleLookUpTable_Left
  ,Dcm_CfgNetAllComMChannelMap_Left
  ,Dcm_CfgNetComCtrlChannelListAll_Left
  ,Dcm_CfgNetTxPduInfo_Left
  ,NULL_PTR
  ,NULL_PTR
  ,   6u
  ,   3u
  ,   1u
  ,   1u
  ,   0u
  ,   3u
  ,   1u
  ,   1u
  ,   3u
};
/*! RxPduId map */
CONST(Dcm_CfgNetRxPduInfoType, DCM_CONST) Dcm_CfgNetRxPduInfo_Right[6]=
{
   { TRUE, 2u}
  ,{ FALSE, 2u}
  ,{ TRUE, 0u}
  ,{ FALSE, 0u}
  ,{ TRUE, 1u}
  ,{ FALSE, 1u}
};
/*! DCM connection descriptor */
CONST(Dcm_CfgNetConnectionInfoType, DCM_CONST) Dcm_CfgNetConnectionInfo_Right[3]=
{
   { 0x0EF8u,PduRConf_PduRSrcPdu_PduRSrcPdu_a0766459, 0u,0u,0x00u,0x00u, 0u}
  ,{ 0x0F0Du,PduRConf_PduRSrcPdu_PduRSrcPdu_f76356d0, 0u,0u,0x00u,0x00u, 0u}
  ,{ 0x0EF9u,PduRConf_PduRSrcPdu_PduRSrcPdu_8d2872fc, 0u,0u,0x00u,0x00u, 0u}
};
/*! DCM protocol descriptor */
CONST(Dcm_CfgNetProtocolInfoType, DCM_CONST) Dcm_CfgNetProtocolInfo_Right[1]=
{
   { {        0u,       0u},4095u, 3u, 0u,TRUE,0u,DemConf_DemClient_DemClient, 0u}
};
/*! Map of all relevant for DCM network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetAllComMChannelMap_Right[1]=
{
   ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727
};
/*! Look up table of DCM relevant network handles */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgNetNetworkHandleLookUpTable_Right[2]=
{
   1u
  ,ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727
};
/*! Communication variant specifics */
CONST(Dcm_CfgNetVariantInfoType, DCM_CONST) Dcm_CfgNetConfig_Right=
{
   Dcm_CfgNetRxPduInfo_Right
  ,Dcm_CfgNetConnectionInfo_Right
  ,Dcm_CfgNetProtocolInfo_Right
  ,Dcm_CfgNetConnComMChannelMap_Right
  ,Dcm_CfgNetNetworkHandleLookUpTable_Right
  ,Dcm_CfgNetAllComMChannelMap_Right
  ,Dcm_CfgNetComCtrlChannelListAll_Right
  ,Dcm_CfgNetTxPduInfo_Right
  ,NULL_PTR
  ,NULL_PTR
  ,   6u
  ,   3u
  ,   1u
  ,   1u
  ,   0u
  ,   3u
  ,   1u
  ,   1u
  ,   3u
};
/*! Diagnostic service execution conditions */
CONST(Dcm_CfgStatePreconditionInfoType, DCM_CONST) Dcm_CfgStatePreconditions[7]=
{
   { { 0x0Fu}}
  ,{ { 0x0Du}}
  ,{ { 0x0Cu}}
  ,{ { 0x0Eu}}
  ,{ { 0x05u}}
  ,{ { 0x04u}}
  ,{ { 0x08u}}
};
/*! Session state properties */
CONST(Dcm_CfgStateSessionInfoType, DCM_CONST) Dcm_CfgStateSessionInfo[4]=
{
   { {        2u,     200u},RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION,0x01u}
  ,{ {        2u,     200u},RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION,0x02u}
  ,{ {        2u,     200u},RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION,0x03u}
  ,{ {        2u,     200u},RTE_MODE_DcmDiagnosticSessionControl_Development,0x7Eu}
};
/*! Session state change notification(s) */
CONST(Dcm_CfgStateNotificationInfoType, DCM_CONST) Dcm_CfgStateSessionNotificationInfo[2]=
{
   { DiagSessionChangeCallback}
  ,{ NULL_PTR}
};
/*! DID ranges look up */
CONST(Dcm_CfgDidMgrDidRangeType, DCM_CONST) Dcm_CfgDidMgrDidRanges[1]=
{
   {    0u,   0u}
};
/*! DID ranges to DID info map */
CONST(Dcm_CfgDidMgrDidInfoRefType, DCM_CONST) Dcm_CfgDidMgrRangeDidInfoRefs[1]=
{
   0u /* dummy initializer */
};
/*! DID properties */
CONST(Dcm_CfgDidMgrDidInfoType, DCM_CONST) Dcm_CfgDidMgrDidInfo[93]=
{
   {    0u, 508u, 508u,   0u,   0u,0x01u} /* DID: 0x0100 */
  ,{   12u,  12u,  12u,   1u,   0u,0x03u} /* DID: 0x0102 */
  ,{    0u,2613u,2613u,   3u,   0u,0x01u} /* DID: 0x0107 */
  ,{    2u,   2u,   2u,   4u,   0u,0x01u} /* DID: 0x010A */
  ,{    2u,   2u,   2u,   5u,   0u,0x03u} /* DID: 0x010B */
  ,{    1u,   1u,   1u,   7u,   0u,0x03u} /* DID: 0x0131 */
  ,{    5u,   5u,   5u,   9u,   0u,0x01u} /* DID: 0x0133 */
  ,{    2u,   2u,   2u,  10u,   0u,0x03u} /* DID: 0x0136 */
  ,{    2u,   2u,   2u,  12u,   0u,0x01u} /* DID: 0x0138 */
  ,{   24u,  24u,  24u,  13u,   0u,0x01u} /* DID: 0x0140 */
  ,{    1u,   1u,   1u,  14u,   0u,0x01u} /* DID: 0x0142 */
  ,{    0u,1002u,1002u,  15u,   0u,0x01u} /* DID: 0x0180 */
  ,{    0u,1002u,1002u,  16u,   0u,0x01u} /* DID: 0x0181 */
  ,{   20u,  20u,  20u,  17u,   0u,0x01u} /* DID: 0x0182 */
  ,{   15u,  31u,  31u,  18u,   0u,0x01u} /* DID: 0x0184 */
  ,{  164u, 164u, 164u,  19u,   0u,0x01u} /* DID: 0x0185 */
  ,{   15u,  15u,  15u,  20u,   0u,0x01u} /* DID: 0x0186 */
  ,{    0u,4092u,4092u,  21u,   0u,0x01u} /* DID: 0x0187 */
  ,{    0u,4092u,4092u,  22u,   0u,0x01u} /* DID: 0x0188 */
  ,{    4u,   4u,   4u,  23u,   0u,0x01u} /* DID: 0x0189 */
  ,{    6u,   6u,   6u,  24u,   0u,0x01u} /* DID: 0x018A */
  ,{    1u,   1u,   1u,  25u,   0u,0x01u} /* DID: 0x018C */
  ,{   20u,  20u,  20u,  26u,   0u,0x01u} /* DID: 0x018D */
  ,{    2u,   2u,   2u,  27u,   0u,0x01u} /* DID: 0x018E */
  ,{    0u,4092u,4092u,  28u,   0u,0x01u} /* DID: 0x018F */
  ,{    0u,1024u,1024u,  29u,   0u,0x01u} /* DID: 0x0190 */
  ,{   33u,  33u,  33u,  30u,   0u,0x01u} /* DID: 0x0191 */
  ,{    4u,   4u,   4u,  31u,   0u,0x01u} /* DID: 0x0197 */
  ,{   32u,  32u,  32u,  32u,   0u,0x01u} /* DID: 0x0198 */
  ,{  128u,3134u,3134u,  33u,   0u,0x01u} /* DID: 0x0199 */
  ,{    0u,1002u,1002u,  34u,   0u,0x01u} /* DID: 0x019A */
  ,{    0u,1002u,1002u,  35u,   0u,0x01u} /* DID: 0x019B */
  ,{    0u,1002u,1002u,  36u,   0u,0x01u} /* DID: 0x019C */
  ,{    0u,1002u,1002u,  37u,   0u,0x01u} /* DID: 0x019D */
  ,{    0u,1002u,1002u,  38u,   0u,0x01u} /* DID: 0x019E */
  ,{    0u,4008u,4008u,  39u,   0u,0x01u} /* DID: 0x019F */
  ,{    0u, 258u, 258u,  40u,   0u,0x03u} /* DID: 0x01A2 */
  ,{    0u,4080u,4080u,  42u,   0u,0x01u} /* DID: 0x01E0 */
  ,{    0u,3060u,3060u,  43u,   0u,0x01u} /* DID: 0x01E1 */
  ,{    0u, 510u, 510u,  44u,   0u,0x01u} /* DID: 0x01E3 */
  ,{    0u,1275u,1275u,  45u,   0u,0x01u} /* DID: 0x01E4 */
  ,{    9u,   9u,   9u,  46u,   0u,0x01u} /* DID: 0x0200 */
  ,{    6u,   6u,   6u,  47u,   0u,0x01u} /* DID: 0x0210 */
  ,{    2u,   2u,   2u,  48u,   0u,0x01u} /* DID: 0x0220 */
  ,{    5u,   5u,   5u,  49u,   0u,0x01u} /* DID: 0x0240 */
  ,{    0u,  22u,  22u,  50u,   0u,0x03u} /* DID: 0x0241 */
  ,{    0u,  22u,  22u,  52u,   0u,0x03u} /* DID: 0x0242 */
  ,{    3u,   3u,   3u,  54u,   0u,0x01u} /* DID: 0x0243 */
  ,{    0u,   8u,   8u,  55u,   0u,0x03u} /* DID: 0x0244 */
  ,{    4u,   4u,   4u,  57u,   0u,0x01u} /* DID: 0x02EA */
  ,{ 1073u,1073u,1073u,  58u,   0u,0x03u} /* DID: 0x0300 */
  ,{  144u, 144u, 144u,  60u,   0u,0x03u} /* DID: 0x0301 */
  ,{  233u, 233u, 233u,  62u,   0u,0x03u} /* DID: 0x0302 */
  ,{   16u,  16u,  16u,  64u,   0u,0x03u} /* DID: 0x0310 */
  ,{    3u,   3u,   3u,  66u,   0u,0x03u} /* DID: 0x0311 */
  ,{   28u,  28u,  28u,  68u,   0u,0x03u} /* DID: 0x0340 */
  ,{    0u, 320u, 320u,  70u,   0u,0x01u} /* DID: 0xE104 */
  ,{   94u,  94u,  94u,  71u,   0u,0x01u} /* DID: 0xEF00 */
  ,{   53u,  53u,  53u,  72u,   0u,0x01u} /* DID: 0xEF01 */
  ,{   27u,  27u,  27u,  73u,   0u,0x01u} /* DID: 0xEF03 */
  ,{    3u,   3u,   3u,  74u,   0u,0x01u} /* DID: 0xEF04 */
  ,{    0u, 381u, 381u,  75u,   0u,0x01u} /* DID: 0xEF05 */
  ,{    4u,   4u,   4u,  76u,   0u,0x01u} /* DID: 0xF100 */
  ,{    0u,  48u,  48u,  77u,   0u,0x01u} /* DID: 0xF103 */
  ,{    0u,1000u,1000u,  78u,   0u,0x01u} /* DID: 0xF104 */
  ,{    4u,   4u,   4u,  79u,   0u,0x01u} /* DID: 0xF10D */
  ,{   10u,  10u,  10u,  80u,   0u,0x01u} /* DID: 0xF111 */
  ,{    0u,1270u,1270u,  81u,   0u,0x01u} /* DID: 0xF121 */
  ,{    1u,   1u,   1u,  82u,   0u,0x01u} /* DID: 0xF131 */
  ,{    3u,   3u,   3u,  83u,   0u,0x01u} /* DID: 0xF150 */
  ,{    0u, 381u, 381u,  84u,   0u,0x01u} /* DID: 0xF151 */
  ,{    3u,   3u,   3u,  85u,   0u,0x01u} /* DID: 0xF153 */
  ,{    2u,   2u,   2u,  86u,   0u,0x01u} /* DID: 0xF154 */
  ,{    0u, 254u, 254u,  87u,   0u,0x01u} /* DID: 0xF155 */
  ,{    0u,2540u,2540u,  88u,   0u,0x01u} /* DID: 0xF15B */
  ,{    0u,  33u,  33u,  89u,   0u,0x01u} /* DID: 0xF18C */
  ,{   17u,  17u,  17u,  90u,   0u,0x03u} /* DID: 0xF190 */
  ,{    1u, 321u, 321u,  92u,   0u,0x02u} /* DID: 0xF804 */
  ,{   12u,  12u,  12u,  93u,   0u,0x01u} /* DID: 0xFD01 */
  ,{   22u,  22u,  22u,  94u,   0u,0x03u} /* DID: 0xFD03 */
  ,{   16u,  16u,  16u,  96u,   0u,0x03u} /* DID: 0xFD04 */
  ,{    1u,   1u,   1u,  98u,   0u,0x01u} /* DID: 0xFD08 */
  ,{    8u,   8u,   8u,  99u,   0u,0x01u} /* DID: 0xFD09 */
  ,{  420u, 420u, 420u, 100u,   0u,0x03u} /* DID: 0xFD10 */
  ,{ 1160u,1160u,1160u, 102u,   0u,0x03u} /* DID: 0xFD2A */
  ,{    1u,   1u,   1u, 104u,   0u,0x03u} /* DID: 0xFD2F */
  ,{    1u,   1u,   1u, 106u,   0u,0x03u} /* DID: 0xFD30 */
  ,{   40u,  40u,  40u, 108u,   0u,0x03u} /* DID: 0xFD31 */
  ,{    3u,   3u,   3u, 110u,   0u,0x02u} /* DID: 0xFD50 */
  ,{   30u,  30u,  30u, 111u,   0u,0x03u} /* DID: 0xFDDF */
  ,{    5u,   5u,   5u, 113u,   0u,0x03u} /* DID: 0xFDFF */
  ,{    0u, 240u, 240u, 115u,   0u,0x01u} /* DID: 0xFE00 */
  ,{    4u,   4u,   4u, 116u,   0u,0x03u} /* DID: 0xFEFF */
};
/*! DID operation properties */
CONST(Dcm_CfgDidMgrDidOpInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpInfo[118]=
{
   {    0u,   0u,0x07u} /* DID: 0x0100 */
  ,{    1u,   3u,0x05u} /* DID: 0x0102 */
  ,{    2u,   5u,0x01u} /* DID: 0x0102 */
  ,{    0u,   6u,0x07u} /* DID: 0x0107 */
  ,{    0u,   9u,0x05u} /* DID: 0x010A */
  ,{    0u,  11u,0x05u} /* DID: 0x010B */
  ,{    3u,  13u,0x01u} /* DID: 0x010B */
  ,{    4u,  14u,0x05u} /* DID: 0x0131 */
  ,{    5u,  16u,0x01u} /* DID: 0x0131 */
  ,{    0u,  17u,0x05u} /* DID: 0x0133 */
  ,{    4u,  19u,0x05u} /* DID: 0x0136 */
  ,{    5u,  21u,0x01u} /* DID: 0x0136 */
  ,{    0u,  22u,0x05u} /* DID: 0x0138 */
  ,{    0u,  24u,0x05u} /* DID: 0x0140 */
  ,{    0u,  26u,0x05u} /* DID: 0x0142 */
  ,{    0u,  28u,0x07u} /* DID: 0x0180 */
  ,{    0u,  31u,0x07u} /* DID: 0x0181 */
  ,{    0u,  34u,0x05u} /* DID: 0x0182 */
  ,{    0u,  36u,0x07u} /* DID: 0x0184 */
  ,{    0u,  39u,0x05u} /* DID: 0x0185 */
  ,{    0u,  41u,0x05u} /* DID: 0x0186 */
  ,{    0u,  43u,0x07u} /* DID: 0x0187 */
  ,{    0u,  46u,0x07u} /* DID: 0x0188 */
  ,{    0u,  49u,0x05u} /* DID: 0x0189 */
  ,{    0u,  51u,0x05u} /* DID: 0x018A */
  ,{    0u,  53u,0x05u} /* DID: 0x018C */
  ,{    0u,  55u,0x05u} /* DID: 0x018D */
  ,{    0u,  57u,0x05u} /* DID: 0x018E */
  ,{    1u,  59u,0x07u} /* DID: 0x018F */
  ,{    0u,  62u,0x07u} /* DID: 0x0190 */
  ,{    1u,  65u,0x05u} /* DID: 0x0191 */
  ,{    1u,  67u,0x05u} /* DID: 0x0197 */
  ,{    1u,  69u,0x05u} /* DID: 0x0198 */
  ,{    1u,  71u,0x07u} /* DID: 0x0199 */
  ,{    1u,  74u,0x07u} /* DID: 0x019A */
  ,{    0u,  77u,0x07u} /* DID: 0x019B */
  ,{    1u,  80u,0x07u} /* DID: 0x019C */
  ,{    1u,  83u,0x07u} /* DID: 0x019D */
  ,{    1u,  86u,0x07u} /* DID: 0x019E */
  ,{    1u,  89u,0x07u} /* DID: 0x019F */
  ,{    1u,  92u,0x07u} /* DID: 0x01A2 */
  ,{    1u,  95u,0x01u} /* DID: 0x01A2 */
  ,{    0u,  96u,0x07u} /* DID: 0x01E0 */
  ,{    0u,  99u,0x07u} /* DID: 0x01E1 */
  ,{    0u, 102u,0x07u} /* DID: 0x01E3 */
  ,{    0u, 105u,0x07u} /* DID: 0x01E4 */
  ,{    1u, 108u,0x05u} /* DID: 0x0200 */
  ,{    1u, 110u,0x05u} /* DID: 0x0210 */
  ,{    1u, 112u,0x05u} /* DID: 0x0220 */
  ,{    1u, 114u,0x05u} /* DID: 0x0240 */
  ,{    1u, 116u,0x07u} /* DID: 0x0241 */
  ,{    2u, 119u,0x01u} /* DID: 0x0241 */
  ,{    1u, 120u,0x07u} /* DID: 0x0242 */
  ,{    2u, 123u,0x01u} /* DID: 0x0242 */
  ,{    1u, 124u,0x05u} /* DID: 0x0243 */
  ,{    1u, 126u,0x07u} /* DID: 0x0244 */
  ,{    2u, 129u,0x01u} /* DID: 0x0244 */
  ,{    1u, 130u,0x05u} /* DID: 0x02EA */
  ,{    1u, 132u,0x05u} /* DID: 0x0300 */
  ,{    0u, 134u,0x01u} /* DID: 0x0300 */
  ,{    1u, 135u,0x05u} /* DID: 0x0301 */
  ,{    0u, 137u,0x01u} /* DID: 0x0301 */
  ,{    1u, 138u,0x05u} /* DID: 0x0302 */
  ,{    0u, 140u,0x01u} /* DID: 0x0302 */
  ,{    1u, 141u,0x05u} /* DID: 0x0310 */
  ,{    1u, 143u,0x01u} /* DID: 0x0310 */
  ,{    1u, 144u,0x05u} /* DID: 0x0311 */
  ,{    1u, 146u,0x01u} /* DID: 0x0311 */
  ,{    0u, 147u,0x05u} /* DID: 0x0340 */
  ,{    6u, 149u,0x01u} /* DID: 0x0340 */
  ,{    0u, 150u,0x07u} /* DID: 0xE104 */
  ,{    0u, 153u,0x01u} /* DID: 0xEF00 */
  ,{    1u, 154u,0x05u} /* DID: 0xEF01 */
  ,{    0u, 156u,0x05u} /* DID: 0xEF03 */
  ,{    0u, 158u,0x05u} /* DID: 0xEF04 */
  ,{    0u, 160u,0x07u} /* DID: 0xEF05 */
  ,{    0u, 163u,0x05u} /* DID: 0xF100 */
  ,{    0u, 165u,0x07u} /* DID: 0xF103 */
  ,{    0u, 168u,0x07u} /* DID: 0xF104 */
  ,{    0u, 171u,0x05u} /* DID: 0xF10D */
  ,{    0u, 173u,0x05u} /* DID: 0xF111 */
  ,{    0u, 175u,0x07u} /* DID: 0xF121 */
  ,{    1u, 178u,0x05u} /* DID: 0xF131 */
  ,{    0u, 180u,0x05u} /* DID: 0xF150 */
  ,{    0u, 182u,0x07u} /* DID: 0xF151 */
  ,{    0u, 185u,0x05u} /* DID: 0xF153 */
  ,{    0u, 187u,0x05u} /* DID: 0xF154 */
  ,{    0u, 189u,0x07u} /* DID: 0xF155 */
  ,{    0u, 192u,0x07u} /* DID: 0xF15B */
  ,{    0u, 195u,0x07u} /* DID: 0xF18C */
  ,{    0u, 198u,0x05u} /* DID: 0xF190 */
  ,{    3u, 200u,0x01u} /* DID: 0xF190 */
  ,{    3u, 201u,0x01u} /* DID: 0xF804 */
  ,{    6u, 202u,0x05u} /* DID: 0xFD01 */
  ,{    0u, 204u,0x05u} /* DID: 0xFD03 */
  ,{    6u, 206u,0x01u} /* DID: 0xFD03 */
  ,{    0u, 207u,0x05u} /* DID: 0xFD04 */
  ,{    3u, 209u,0x01u} /* DID: 0xFD04 */
  ,{    6u, 210u,0x05u} /* DID: 0xFD08 */
  ,{    6u, 212u,0x05u} /* DID: 0xFD09 */
  ,{    6u, 214u,0x01u} /* DID: 0xFD10 */
  ,{    6u, 215u,0x01u} /* DID: 0xFD10 */
  ,{    6u, 216u,0x01u} /* DID: 0xFD2A */
  ,{    6u, 217u,0x01u} /* DID: 0xFD2A */
  ,{    6u, 218u,0x01u} /* DID: 0xFD2F */
  ,{    6u, 219u,0x01u} /* DID: 0xFD2F */
  ,{    1u, 220u,0x05u} /* DID: 0xFD30 */
  ,{    6u, 222u,0x01u} /* DID: 0xFD30 */
  ,{    6u, 223u,0x05u} /* DID: 0xFD31 */
  ,{    6u, 225u,0x01u} /* DID: 0xFD31 */
  ,{    6u, 226u,0x01u} /* DID: 0xFD50 */
  ,{    1u, 227u,0x05u} /* DID: 0xFDDF */
  ,{    6u, 229u,0x01u} /* DID: 0xFDDF */
  ,{    6u, 230u,0x05u} /* DID: 0xFDFF */
  ,{    6u, 232u,0x01u} /* DID: 0xFDFF */
  ,{    6u, 233u,0x07u} /* DID: 0xFE00 */
  ,{    6u, 236u,0x05u} /* DID: 0xFEFF */
  ,{    6u, 238u,0x01u} /* DID: 0xFEFF */
};
/*! DID operation classes */
CONST(Dcm_CfgDidMgrDidOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrDidOpClassInfo[240]=
{
   {  0u}
  ,{  1u}
  ,{  2u}
  ,{  3u}
  ,{  4u}
  ,{  5u}
  ,{  6u}
  ,{  7u}
  ,{  8u}
  ,{  9u}
  ,{ 10u}
  ,{ 11u}
  ,{ 13u}
  ,{ 15u}
  ,{ 17u}
  ,{ 18u}
  ,{ 19u}
  ,{ 20u}
  ,{ 22u}
  ,{ 24u}
  ,{ 26u}
  ,{ 28u}
  ,{ 30u}
  ,{ 32u}
  ,{ 34u}
  ,{ 46u}
  ,{ 58u}
  ,{ 59u}
  ,{ 60u}
  ,{ 61u}
  ,{ 62u}
  ,{ 63u}
  ,{ 64u}
  ,{ 65u}
  ,{ 66u}
  ,{ 67u}
  ,{ 68u}
  ,{ 70u}
  ,{ 71u}
  ,{ 73u}
  ,{ 83u}
  ,{ 93u}
  ,{ 94u}
  ,{ 95u}
  ,{ 96u}
  ,{ 97u}
  ,{ 98u}
  ,{ 99u}
  ,{ 100u}
  ,{ 101u}
  ,{ 102u}
  ,{ 103u}
  ,{ 104u}
  ,{ 105u}
  ,{ 106u}
  ,{ 107u}
  ,{ 109u}
  ,{ 111u}
  ,{ 113u}
  ,{ 115u}
  ,{ 116u}
  ,{ 117u}
  ,{ 118u}
  ,{ 119u}
  ,{ 120u}
  ,{ 121u}
  ,{ 123u}
  ,{ 125u}
  ,{ 126u}
  ,{ 127u}
  ,{ 128u}
  ,{ 129u}
  ,{ 133u}
  ,{ 134u}
  ,{ 138u}
  ,{ 139u}
  ,{ 140u}
  ,{ 141u}
  ,{ 142u}
  ,{ 143u}
  ,{ 144u}
  ,{ 145u}
  ,{ 146u}
  ,{ 147u}
  ,{ 148u}
  ,{ 149u}
  ,{ 150u}
  ,{ 151u}
  ,{ 152u}
  ,{ 153u}
  ,{ 154u}
  ,{ 155u}
  ,{ 156u}
  ,{ 157u}
  ,{ 158u}
  ,{ 159u}
  ,{ 160u}
  ,{ 161u}
  ,{ 162u}
  ,{ 163u}
  ,{ 164u}
  ,{ 165u}
  ,{ 166u}
  ,{ 167u}
  ,{ 168u}
  ,{ 169u}
  ,{ 170u}
  ,{ 171u}
  ,{ 172u}
  ,{ 181u}
  ,{ 190u}
  ,{ 195u}
  ,{ 200u}
  ,{ 202u}
  ,{ 204u}
  ,{ 207u}
  ,{ 210u}
  ,{ 211u}
  ,{ 212u}
  ,{ 213u}
  ,{ 214u}
  ,{ 215u}
  ,{ 216u}
  ,{ 217u}
  ,{ 218u}
  ,{ 219u}
  ,{ 220u}
  ,{ 221u}
  ,{ 222u}
  ,{ 223u}
  ,{ 224u}
  ,{ 225u}
  ,{ 226u}
  ,{ 227u}
  ,{ 228u}
  ,{ 229u}
  ,{ 230u}
  ,{ 231u}
  ,{ 232u}
  ,{ 233u}
  ,{ 234u}
  ,{ 235u}
  ,{ 247u}
  ,{ 257u}
  ,{ 269u}
  ,{ 271u}
  ,{ 273u}
  ,{ 275u}
  ,{ 276u}
  ,{ 277u}
  ,{ 278u}
  ,{ 279u}
  ,{ 280u}
  ,{ 281u}
  ,{ 289u}
  ,{ 295u}
  ,{ 301u}
  ,{ 308u}
  ,{ 315u}
  ,{ 318u}
  ,{ 321u}
  ,{ 322u}
  ,{ 323u}
  ,{ 324u}
  ,{ 326u}
  ,{ 328u}
  ,{ 329u}
  ,{ 330u}
  ,{ 331u}
  ,{ 332u}
  ,{ 333u}
  ,{ 334u}
  ,{ 338u}
  ,{ 342u}
  ,{ 343u}
  ,{ 344u}
  ,{ 345u}
  ,{ 346u}
  ,{ 347u}
  ,{ 348u}
  ,{ 349u}
  ,{ 352u}
  ,{ 355u}
  ,{ 356u}
  ,{ 357u}
  ,{ 358u}
  ,{ 361u}
  ,{ 364u}
  ,{ 365u}
  ,{ 366u}
  ,{ 367u}
  ,{ 368u}
  ,{ 369u}
  ,{ 370u}
  ,{ 371u}
  ,{ 372u}
  ,{ 373u}
  ,{ 374u}
  ,{ 375u}
  ,{ 376u}
  ,{ 377u}
  ,{ 378u}
  ,{ 380u}
  ,{ 381u}
  ,{ 382u}
  ,{ 384u}
  ,{ 386u}
  ,{ 388u}
  ,{ 395u}
  ,{ 402u}
  ,{ 409u}
  ,{ 410u}
  ,{ 411u}
  ,{ 413u}
  ,{ 415u}
  ,{ 416u}
  ,{ 417u}
  ,{ 418u}
  ,{ 419u}
  ,{ 420u}
  ,{ 421u}
  ,{ 422u}
  ,{ 423u}
  ,{ 424u}
  ,{ 425u}
  ,{ 426u}
  ,{ 427u}
  ,{ 430u}
  ,{ 431u}
  ,{ 432u}
  ,{ 433u}
  ,{ 434u}
  ,{ 435u}
  ,{ 436u}
  ,{ 437u}
  ,{ 438u}
  ,{ 439u}
  ,{ 440u}
  ,{ 441u}
  ,{ 442u}
};
/*! DID signal operation classes */
CONST(Dcm_CfgDidMgrSignalOpClassInfoType, DCM_CONST) Dcm_CfgDidMgrSignalOpClassInfo[442]=
{
   { ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadData)),   0u, 508u,0x0002u} /* DID: 0x0100 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0100 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Reprogramming_Attempt_Counter_Read_Reprogramming_Attempts_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0100 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ReadData)),  12u,  12u,0x0002u} /* DID: 0x0102 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0102 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Trace_Memory_Read_Diagnostic_Trace_Memory_WriteData)),  12u,  12u,0x1002u} /* DID: 0x0102 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_ReadData)),   0u,2613u,0x0002u} /* DID: 0x0107 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0107 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Global_Time_Sync_Measured_Values_Read_GTSM_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0107 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ReadData)),   2u,   2u,0x0002u} /* DID: 0x010A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Odometer_in_Low_Resolution_Read_Vehicle_Odometer_in_Low_Resolution_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x010A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_ReadData)),   1u,   1u,0x0002u} /* DID: 0x010B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_ReadData)),   1u,   1u,0x0002u} /* DID: 0x010B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x010B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x010B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_Block_Size_Value_as_defined_in_ISO_15765_2_WriteData)),   1u,   1u,0x1002u} /* DID: 0x010B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Adjust_ISO_15765_2_Block_Size_and_STmin_Parameter_Read_STmin_Value_as_defined_in_ISO_15765_2_WriteData)),   1u,   1u,0x1002u} /* DID: 0x010B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0131_SAR_Data_Storage_Status_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0131 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0131_SAR_Data_Storage_Status_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0131 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0131_SAR_Data_Storage_Status_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0131 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Current_Operating_Time_Read_Current_Operating_Time_ReadData)),   4u,   4u,0x0002u} /* DID: 0x0133 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Current_Operating_Time_Read_Operating_Time_Status_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0133 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Current_Operating_Time_Read_Current_Operating_Time_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0133 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Current_Operating_Time_Read_Operating_Time_Status_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0133 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0136 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0136 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0136 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0136 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0136 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0136 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0138 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Customer_Settings_Read_PS_Curve_Stat_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0138 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Customer_Settings_Read_BltSlckDec_Md_Stat_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0138 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Customer_Settings_Read_PS_Curve_Stat_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0138 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0140 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0142 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0142 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Root_CA_Certificate_Read_Root_CA_Certificate_ReadData)),   0u,1002u,0x0002u} /* DID: 0x0180 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Root_CA_Certificate_Read_Root_CA_Certificate_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0180 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Root_CA_Certificate_Read_Root_CA_Certificate_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0180 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Backend_CA_Certificate_Read_Backend_CA_Certificate_ReadData)),   0u,1002u,0x0002u} /* DID: 0x0181 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Backend_CA_Certificate_Read_Backend_CA_Certificate_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0181 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Backend_CA_Certificate_Read_Backend_CA_Certificate_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0181 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_ReadData)),  20u,  20u,0x0002u} /* DID: 0x0182 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0182 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_ReadData)),  15u,  15u,0x0002u} /* DID: 0x0184 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_ReadData)),   0u,  16u,0x0002u} /* DID: 0x0184 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0184 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0184 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0184 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Generation_Time_GTC_ReadData)),  15u,  15u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Major_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Minor_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Patch_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Hash_ReadData)),  64u,  64u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Generation_Time_GTC_ReadData)),  15u,  15u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Major_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Minor_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Patch_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Hash_ReadData)),  64u,  64u,0x0002u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_Basic_ACL_Hash_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Generation_Time_GTC_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Access_Control_List_Version_Read_ECU_indvidual_ACL_Hash_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0185 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData)),  15u,  15u,0x0002u} /* DID: 0x0186 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0186 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Security_Event_Log_Read_Security_Event_Log_ReadData)),   0u,4092u,0x0002u} /* DID: 0x0187 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Security_Event_Log_Read_Security_Event_Log_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0187 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Security_Event_Log_Read_Security_Event_Log_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0187 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_ReadData)),   0u,4092u,0x0002u} /* DID: 0x0188 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0188 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0188 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_ReadData)),   4u,   4u,0x0002u} /* DID: 0x0189 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0189 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_Local_TickCount_Read_TickCount_ReadData)),   6u,   6u,0x0002u} /* DID: 0x018A */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_Local_TickCount_Read_TickCount_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x018A */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_User_Role_Read_Cebas_UserRole_ReadData)),   1u,   1u,0x0002u} /* DID: 0x018C */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_User_Role_Read_Cebas_UserRole_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x018C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Real_Time_Offset_Read_Real_Time_Offset_ReadData)),  15u,  15u,0x0002u} /* DID: 0x018D */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Real_Time_Offset_Read_TickCount_ReadData)),   5u,   5u,0x0002u} /* DID: 0x018D */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Real_Time_Offset_Read_Real_Time_Offset_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x018D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Real_Time_Offset_Read_TickCount_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x018D */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VIN_Status_Read_VIN_Status_ReadData)),   1u,   1u,0x0002u} /* DID: 0x018E */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VIN_Status_Read_VIN_Lock_Status_ReadData)),   1u,   1u,0x0002u} /* DID: 0x018E */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VIN_Status_Read_VIN_Status_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x018E */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VIN_Status_Read_VIN_Lock_Status_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x018E */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_CMACs_Read_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData)),   0u,4092u,0x0002u} /* DID: 0x018F */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_CMACs_Read_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x018F */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SecOC_PDU_Data_IDs_and_Key_CMACs_Read_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x018F */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadData)),   0u,1024u,0x0002u} /* DID: 0x0190 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0190 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0190 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_RandomNumber_Read_Generated_Random_Number_Result_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0191 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_RandomNumber_Read_Generated_Random_Number_ReadData)),  32u,  32u,0x0002u} /* DID: 0x0191 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_RandomNumber_Read_Generated_Random_Number_Result_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0191 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_RandomNumber_Read_Generated_Random_Number_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0191 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Status_SSA_Pre_Compile_Switches_Read_Precompile_switch_ReadData)),   4u,   4u,0x0002u} /* DID: 0x0197 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Status_SSA_Pre_Compile_Switches_Read_Precompile_switch_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0197 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Root_Replacement_Key_Read_Root_Replacement_Key_ReadData)),  32u,  32u,0x0002u} /* DID: 0x0198 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Root_Replacement_Key_Read_Root_Replacement_Key_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0198 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Nonce_ReadData)),  32u,  32u,0x0002u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Ephemeral_ECU_Public_Key_ReadData)),  32u,  32u,0x0002u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Data_Signature_ReadData)),  64u,  64u,0x0002u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Certificates_ReadData)),   0u,3006u,0x0002u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Certificates_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Nonce_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Data_Signature_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_Request_ephemeral_public_key_Read_Certificates_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0199 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_ECU_CSR_Read_Trust_model_ECU_CSR_ReadData)),   0u,1002u,0x0002u} /* DID: 0x019A */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_ECU_CSR_Read_Trust_model_ECU_CSR_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x019A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_ECU_CSR_Read_Trust_model_ECU_CSR_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x019A */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_ECU_certificate_Read_Trust_model_ECU_Certificate_ReadData)),   0u,1002u,0x0002u} /* DID: 0x019B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_ECU_certificate_Read_Trust_model_ECU_Certificate_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x019B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_ECU_certificate_Read_Trust_model_ECU_Certificate_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x019B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Intermediate_CA_certificate_Read_Trust_model_Intermediate_CA_Certificate_ReadData)),   0u,1002u,0x0002u} /* DID: 0x019C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Intermediate_CA_certificate_Read_Trust_model_Intermediate_CA_Certificate_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x019C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Intermediate_CA_certificate_Read_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x019C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Backend_CA_certificate_Read_Trust_model_Backend_CA_certificate_ReadData)),   0u,1002u,0x0002u} /* DID: 0x019D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Backend_CA_certificate_Read_Trust_model_Backend_CA_certificate_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x019D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Backend_CA_certificate_Read_Trust_model_Backend_CA_certificate_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x019D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Root_CA_certificate_Read_Trust_model_Root_CA_certificate_ReadData)),   0u,1002u,0x0002u} /* DID: 0x019E */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Root_CA_certificate_Read_Trust_model_Root_CA_certificate_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x019E */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_Root_CA_certificate_Read_Trust_model_Root_CA_certificate_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x019E */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_full_chain_of_trust_certificates_Read_Trust_model_certificates_ReadData)),   0u,4008u,0x0002u} /* DID: 0x019F */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_full_chain_of_trust_certificates_Read_Trust_model_certificates_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x019F */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_model_full_chain_of_trust_certificates_Read_Trust_model_certificates_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x019F */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadData)),   0u, 258u,0x0002u} /* DID: 0x01A2 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x01A2 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x01A2 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Trust_Model_CSR_Supplier_Signature_Read_Trust_Model_CSR_Supplier_Signature_WriteData)),   0u, 258u,0x1004u} /* DID: 0x01A2 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Task_Response_Time_Read_Task_histograms_ReadData)),   0u,4080u,0x0002u} /* DID: 0x01E0 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Task_Response_Time_Read_Task_histograms_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x01E0 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Task_Response_Time_Read_Task_histograms_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x01E0 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CPU_Load_Read_CPU_load_histograms_ReadData)),   0u,3060u,0x0002u} /* DID: 0x01E1 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CPU_Load_Read_CPU_load_histograms_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x01E1 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CPU_Load_Read_CPU_load_histograms_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x01E1 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Stack_Load_Read_Maximum_ReadData)),   0u, 510u,0x0002u} /* DID: 0x01E3 */                         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Stack_Load_Read_Maximum_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x01E3 */                   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Stack_Load_Read_Maximum_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x01E3 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadData)),   0u,1275u,0x0002u} /* DID: 0x01E4 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x01E4 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Memory_Usage_Cycles_Read_Memory_Usage_Cycles_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x01E4 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_1_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_2_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_3_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_4_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Supply_battery_voltage_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_5_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_6_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_7_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_8_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0200 */                  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_1_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_2_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_3_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_4_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Supply_battery_voltage_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_5_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_6_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_7_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_input_Read_Neues_Bitfeld_8_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0200 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_CANoutput1_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0210 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0210 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0210 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0210 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0210 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_CANoutput1_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0210 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0210 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0210 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0210 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0210 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HW_input_Read_Voltage_KL30t_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0220 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HW_input_Read_Voltage_Motor_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0220 */                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HW_input_Read_Voltage_KL30t_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0220 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HW_input_Read_Voltage_Motor_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0220 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0240 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Internal_ECU_information_Read_ECU_Temperature_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0240 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Internal_ECU_information_Read_MOTOR_Current_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0240 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0240 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Internal_ECU_information_Read_ECU_Temperature_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0240 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Internal_ECU_information_Read_MOTOR_Current_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0240 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ReadData)),   0u,  22u,0x0002u} /* DID: 0x0241 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0241 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0241 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_WriteData)),   0u,  22u,0x1004u} /* DID: 0x0241 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ReadData)),   0u,  22u,0x0002u} /* DID: 0x0242 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0242 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0242 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_WriteData)),   0u,  22u,0x1004u} /* DID: 0x0242 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_BSR_Counter_read_Read_BSR_Counter_ReadData)),   3u,   3u,0x0002u} /* DID: 0x0243 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_BSR_Counter_read_Read_BSR_Counter_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0243 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadData)),   0u,   8u,0x0002u} /* DID: 0x0244 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0x0244 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0244 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PRE_SAFE_Counter_read_Read_CombinedDataElement_WriteData)),   0u,   8u,0x1004u} /* DID: 0x0244 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_System_Time_read_Read_System_time_ReadData)),   4u,   4u,0x0002u} /* DID: 0x02EA */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_System_Time_read_Read_System_time_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x02EA */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_ReadData)),1073u,1073u,0x0002u} /* DID: 0x0300 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0300 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_PreSafe_Cycles_Level_1_8_Read_CombinedSignal_WriteData)),1073u,1073u,0x1002u} /* DID: 0x0300 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_ReadData)), 144u, 144u,0x0002u} /* DID: 0x0301 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0301 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Release_Cycles_BSR_and_PreSafe_Read_CombinedSignal_WriteData)), 144u, 144u,0x1002u} /* DID: 0x0301 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_ReadData)), 233u, 233u,0x0002u} /* DID: 0x0302 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0302 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Tensioning_Cycle_BSR_Read_CombinedSignal_WriteData)), 233u, 233u,0x1002u} /* DID: 0x0302 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_1_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0310 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_2_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0310 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_3_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0310 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_4_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0310 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_5_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0310 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_6_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0310 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgrDidNoOp)),   1u,   1u,0x0001u} /* DID: 0x0310 */                                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgrDidNoOp)),   1u,   1u,0x0001u} /* DID: 0x0310 */                                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_1_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_2_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_3_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_4_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_5_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_6_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_1_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0310 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_2_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0310 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_3_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0310 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_4_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0310 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_5_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0310 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Equipment_6_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0310 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgrDidNoOp)),   1u,   1u,0x1006u} /* DID: 0x0310 */                                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgrDidNoOp)),   1u,   1u,0x1006u} /* DID: 0x0310 */                                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsabbruchschwelle_WriteData)),   2u,   2u,0x1002u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Unterspannungsbereichsschwelle_WriteData)),   2u,   2u,0x1002u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsbereichsschwelle_WriteData)),   2u,   2u,0x1002u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Vehicle_Equipment_Read_Ueberspannungsabbruchschwelle_WriteData)),   2u,   2u,0x1002u} /* DID: 0x0310 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ReadData)),   2u,   2u,0x0002u} /* DID: 0x0311 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ReadData)),   1u,   1u,0x0002u} /* DID: 0x0311 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0311 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0311 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Bitfield_WriteData)),   2u,   2u,0x1002u} /* DID: 0x0311 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ZZZ_Vehicle_Equipment_Development_Read_Zykluszeit_Messtechnik_WriteData)),   1u,   1u,0x1002u} /* DID: 0x0311 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_ReadData)),  28u,  28u,0x0002u} /* DID: 0x0340 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0x0340 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_WriteData)),  28u,  28u,0x1002u} /* DID: 0x0340 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_ReadData)),   0u, 320u,0x0002u} /* DID: 0xE104 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xE104 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Read_Calibration_Identification_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xE104 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Major_Version_ReadData)),   1u,   1u,0x0008u} /* DID: 0xEF00 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Minor_Version_ReadData)),   1u,   1u,0x0008u} /* DID: 0xEF00 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Patch_Version_ReadData)),   1u,   1u,0x0008u} /* DID: 0xEF00 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ReadData)),   1u,   1u,0x0008u} /* DID: 0xEF00 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ReadData)),  10u,  10u,0x0008u} /* DID: 0xEF00 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ReadData)),  10u,  10u,0x0008u} /* DID: 0xEF00 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgrDidNoOp)),  30u,  30u,0x0001u} /* DID: 0xEF00 */                                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ReadData)),  40u,  40u,0x0008u} /* DID: 0xEF00 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ReadData)),  10u,  10u,0x0002u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ReadData)),  10u,  10u,0x0002u} /* DID: 0xEF01 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ReadData)),  30u,  30u,0x0002u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Major_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Minor_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Diagnostic_Extract_Patch_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_CANdela_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_DDM_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Diagnostic_Extract_Version_Read_Exported_Diagnostic_Variant_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF01 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ReadData)),  20u,  20u,0x0002u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ReadData)),   2u,   2u,0x0002u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Major_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Minor_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Patch_Level_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Standard_Application_SW_Package_Build_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_C_P_Identification_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_Supplier_Identification_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Standard_Application_SW_Package_Information_Read_AUTOSAR_Platform_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Major_Version_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF04 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Minor_Version_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF04 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Patch_Level_ReadData)),   1u,   1u,0x0002u} /* DID: 0xEF04 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Major_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Minor_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SSA_Version_Information_Read_SSA_Patch_Level_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadData)),   0u, 381u,0x0002u} /* DID: 0xEF05 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xEF05 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Minimum_Software_Version_Read_Minimum_Software_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xEF05 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ActiveDiagnosticInformation_Read_Identification_ReadData)),   3u,   3u,0x0002u} /* DID: 0xF100 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ActiveDiagnosticInformation_Read_Session_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF100 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ActiveDiagnosticInformation_Read_Identification_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF100 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ActiveDiagnosticInformation_Read_Session_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF100 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadData)),   0u,  48u,0x0002u} /* DID: 0xF103 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xF103 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Dump_of_Vedoc_Relevant_Information_Read_PatchedObject_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF103 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadData)),   0u,1000u,0x0002u} /* DID: 0xF104 */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xF104 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_Name_Read_Diagnostic_ECU_Name_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF104 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Year_Appl_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Application_Software_Month_Appl_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Year_Boot_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_DDS_Package_Release_Read_DDS_Package_Release_of_Boot_Software_Month_Boot_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF10D */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ReadData)),  10u,  10u,0x0002u} /* DID: 0xF111 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_MercedesCarGroupHardware_Read_Hardware_Part_Number_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF111 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_ReadData)),   0u,1270u,0x0002u} /* DID: 0xF121 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xF121 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_MercedesCarGroupSoftware_Read_Software_Logical_Block_Numbers_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF121 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF131 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Supported_configuration_mechanisms_Read_Config_mechanisms_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF131 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HardwareVersion_Read_HW_year_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF150 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HardwareVersion_Read_HW_week_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF150 */                    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HardwareVersion_Read_HW_patch_level_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF150 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HardwareVersion_Read_HW_year_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF150 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HardwareVersion_Read_HW_week_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF150 */          /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HardwareVersion_Read_HW_patch_level_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF150 */   /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadData)),   0u, 381u,0x0002u} /* DID: 0xF151 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xF151 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SoftwareVersion_Read_Software_Logical_Block_Version_Information_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF151 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_year_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF153 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_week_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF153 */           /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ReadData)),   1u,   1u,0x0002u} /* DID: 0xF153 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_year_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF153 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_week_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF153 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_BootSoftwareVersion_Read_Boot_SW_patch_level_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF153 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ReadData)),   2u,   2u,0x0002u} /* DID: 0xF154 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HardwareSupplier_Read_Hardware_Supplier_Identification_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF154 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadData)),   0u, 254u,0x0002u} /* DID: 0xF155 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xF155 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SoftwareSupplier_Read_Software_Logical_Block_Supplier_Identification_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF155 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadData)),   0u,2540u,0x0002u} /* DID: 0xF15B */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xF15B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ReadFingerprint_Read_Software_Fingerprint_s_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF15B */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ReadData)),   0u,  33u,0x0002u} /* DID: 0xF18C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xF18C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF18C */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VINDataIdentifier_Read_VINDataIdentifier_ReadData)),  17u,  17u,0x0002u} /* DID: 0xF190 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VINDataIdentifier_Read_VINDataIdentifier_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xF190 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_VINDataIdentifier_Read_VINDataIdentifier_WriteData)),  17u,  17u,0x1002u} /* DID: 0xF190 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Write_Number_of_data_items_WriteData)),   1u,   1u,0x1002u} /* DID: 0xF804 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Calibration_Identifications_CAL_ID_Write_Calibration_Identification_WriteData)),   0u, 320u,0x1004u} /* DID: 0xF804 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SW_Version_Read_SW_Version_ReadData)),  12u,  12u,0x0002u} /* DID: 0xFD01 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_SW_Version_Read_SW_Version_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD01 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_serial_number_Read_ECU_traceability_number_ReadData)),  12u,  12u,0x0002u} /* DID: 0xFD03 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_ReadData)),  10u,  10u,0x0002u} /* DID: 0xFD03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_serial_number_Read_ECU_traceability_number_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_serial_number_Read_ECU_traceability_number_WriteData)),  12u,  12u,0x1002u} /* DID: 0xFD03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_WriteData)),  10u,  10u,0x1002u} /* DID: 0xFD03 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ReadData)),  10u,  10u,0x0002u} /* DID: 0xFD04 */       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD04 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD04 */  /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Partnumber_WriteData)),  10u,  10u,0x1002u} /* DID: 0xFD04 */      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_patch_level_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_week_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Version_HW_year_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_patch_level_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_week_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HSM_Identification_Read_HSM_MB_Supplier_Version_HW_year_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD04 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Reset_Cause_Management_Read_Reset_Cause_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD08 */         /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Reset_Cause_Management_Read_Reset_Cause_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD08 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Last_Warm_Reset_Parameters_Read_Last_Detected_Warm_Reset_Cause_ReadData)),   4u,   4u,0x0002u} /* DID: 0xFD09 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Last_Warm_Reset_Parameters_Read_Reset_Cause_Counter_ReadData)),   4u,   4u,0x0002u} /* DID: 0xFD09 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Last_Warm_Reset_Parameters_Read_Last_Detected_Warm_Reset_Cause_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD09 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Last_Warm_Reset_Parameters_Read_Reset_Cause_Counter_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD09 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Cycle_configuration_Read_Cycles_ReadData)), 420u, 420u,0x0002u} /* DID: 0xFD10 */                 /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Cycle_configuration_Read_Cycles_WriteData)), 420u, 420u,0x1002u} /* DID: 0xFD10 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Steps_library_Read_Steps_ReadData)),1160u,1160u,0x0002u} /* DID: 0xFD2A */                        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Steps_library_Read_Steps_WriteData)),1160u,1160u,0x1002u} /* DID: 0xFD2A */                       /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_Location_Read_Side_Allocation_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD2F */               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_ECU_Location_Read_Side_Allocation_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD2F */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData)),   1u,   1u,0x0002u} /* DID: 0xFD30 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD30 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD30 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HB_Calibration_Read_CombinedSignal_ReadData)),  40u,  40u,0x0002u} /* DID: 0xFD31 */              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HB_Calibration_Read_CombinedSignal_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFD31 */    /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_HB_Calibration_Read_CombinedSignal_WriteData)),  40u,  40u,0x1002u} /* DID: 0xFD31 */             /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Hardware_Version_Information_Write_HW_year_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD50 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Hardware_Version_Information_Write_HW_week_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD50 */     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Hardware_Version_Information_Write_HW_patch_level_WriteData)),   1u,   1u,0x1002u} /* DID: 0xFD50 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData)),  30u,  30u,0x0002u} /* DID: 0xFDDF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFDDF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData)),  30u,  30u,0x1002u} /* DID: 0xFDDF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_ReadData)),   5u,   5u,0x0002u} /* DID: 0xFDFF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFDFF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_WriteData)),   5u,   5u,0x1002u} /* DID: 0xFDFF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_AEC_Status_Read_AEC_Status_ReadData)),   0u, 240u,0x0002u} /* DID: 0xFE00 */                      /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_AEC_Status_Read_AEC_Status_ReadDataLength)),   0u,   0u,0x0102u} /* DID: 0xFE00 */                /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_AEC_Status_Read_AEC_Status_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFE00 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_ReadData)),   4u,   4u,0x0002u} /* DID: 0xFEFF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_ConditionCheckRead)),   0u,   0u,0x0201u} /* DID: 0xFEFF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_DidMgrOpFuncType)(Rte_Call_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_WriteData)),   4u,   4u,0x1002u} /* DID: 0xFEFF */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! RID properties */
CONST(Dcm_CfgRidMgrRidInfoType, DCM_CONST) Dcm_CfgRidMgrRidInfo[24]=
{
   {    0u,   3u,0x01u, 0u} /* RID: 0x0203 */
  ,{    1u,   3u,0x01u, 0u} /* RID: 0x0207 */
  ,{    2u,   2u,0x01u, 0u} /* RID: 0x0211 */
  ,{    3u,   2u,0x01u, 0u} /* RID: 0x0212 */
  ,{    4u,   2u,0x07u, 0u} /* RID: 0x0245 */
  ,{    7u,   0u,0x01u, 0u} /* RID: 0x0260 */
  ,{    8u,   0u,0x01u, 0u} /* RID: 0x0261 */
  ,{    9u,   3u,0x01u, 0u} /* RID: 0x0262 */
  ,{   10u,   3u,0x01u, 0u} /* RID: 0x0263 */
  ,{   11u,   3u,0x01u, 0u} /* RID: 0x0264 */
  ,{   12u,   0u,0x01u, 0u} /* RID: 0x0266 */
  ,{   13u,   0u,0x01u, 0u} /* RID: 0x0267 */
  ,{   14u,   1u,0x07u, 0u} /* RID: 0x0268 */
  ,{   17u,   3u,0x01u, 0u} /* RID: 0x0274 */
  ,{   18u,   1u,0x01u, 0u} /* RID: 0x0277 */
  ,{   19u,   1u,0x01u, 0u} /* RID: 0x0279 */
  ,{   20u,   1u,0x01u, 0u} /* RID: 0x027B */
  ,{   21u,   2u,0x01u, 0u} /* RID: 0x027D */
  ,{   22u,   2u,0x07u, 0u} /* RID: 0x0302 */
  ,{   25u,   2u,0x07u, 0u} /* RID: 0x0329 */
  ,{   28u,   2u,0x07u, 0u} /* RID: 0x0330 */
  ,{   31u,   6u,0x07u, 0u} /* RID: 0xF703 */
  ,{   34u,   6u,0x01u, 0u} /* RID: 0xF782 */
  ,{   35u,   6u,0x01u, 0u} /* RID: 0xF791 */
};
/*! RID operation properties */
CONST(Dcm_CfgRidMgrOpInfoType, DCM_CONST) Dcm_CfgRidMgrOpInfo[36]=
{
   { ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0203_Start)),   0u,   0u,   2u, 102u, 9u, 0u} /* RID: 0x0203 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0207_Start)),   0u,4064u,   2u,   2u, 9u, 0u} /* RID: 0x0207 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Clear_Resource_Consumption_Data_Start_Start)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x0211 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Reset_VINDataIdentifier_Start_Start)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x0212 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_Start)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x0245 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_Stop)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x0245 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Synchronize_to_Non_volatile_Memory_Start_RequestResults)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x0245 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0260_Start)),   2u,4006u,   2u,3008u, 9u, 0u} /* RID: 0x0260 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0261_Start)),   0u,2002u,   2u,   2u, 9u, 0u} /* RID: 0x0261 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0262_Start)),   0u,2002u,   2u,   2u, 9u, 0u} /* RID: 0x0262 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0263_Start)),  65u,  65u,   2u,   2u, 9u, 0u} /* RID: 0x0263 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0264_Start)),   0u,4008u,   2u,   2u, 9u, 0u} /* RID: 0x0264 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0266_Start)),   0u,   0u,  33u,  33u, 9u, 0u} /* RID: 0x0266 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0267_Start)),   0u,   0u,   1u,  19u, 9u, 0u} /* RID: 0x0267 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0268_Start)),   1u,   1u,   2u,   2u, 9u, 0u} /* RID: 0x0268 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0268_Stop)),   1u,   1u,   2u,   2u, 9u, 0u} /* RID: 0x0268 */                                               /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0268_RequestResults)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0x0268 */                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0274_Start)),   0u,3006u,   2u,   2u, 9u, 0u} /* RID: 0x0274 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0277_Start)), 128u,2132u,   2u,   2u, 9u, 0u} /* RID: 0x0277 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0279_Start)), 193u,3199u,   2u,   2u, 9u, 0u} /* RID: 0x0279 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_027B_Start)),   0u,   0u,  66u,1068u, 9u, 0u} /* RID: 0x027B */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_027D_Start)),   2u,   2u,   4u,  68u, 9u, 0u} /* RID: 0x027D */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0302_Start)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0x0302 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_Stop)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x0302 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0302_RequestResults)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0x0302 */                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0329_Start)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0x0329 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Trigger_BSR_Start_Stop)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x0329 */            /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0329_RequestResults)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0x0329 */                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0330_Start)),   2u,   2u,   2u,   2u, 9u, 0u} /* RID: 0x0330 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_Stop)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0x0330 */ /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_0330_RequestResults)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0x0330 */                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_F703_Start)),   1u,   1u,   1u,   1u, 9u, 0u} /* RID: 0xF703 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Rte_Call_RoutineServices_Routine_Cycle_Execution_Start_Stop)),   0u,   0u,   1u,   1u, 3u, 0u} /* RID: 0xF703 */        /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_F703_RequestResults)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0xF703 */                                     /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_F782_Start)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0xF782 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
  ,{ ((Dcm_RidMgrOpFuncType)(Dcm_RidMgr_F791_Start)),   0u,   0u,   2u,   2u, 9u, 0u} /* RID: 0xF791 */                                              /* PRQA S 0313 */ /* MD_Dcm_0313 */
};
/*! Properties of the MIDs */
CONST(Dcm_CfgMemMgrMemIdInfoType, DCM_CONST) Dcm_CfgMemMgrMidInfo[1]=
{
   { Dcm_CfgMemMgrMemMap,   2u}
};
/*! Properties of the memory map of a specific MID */
CONST(Dcm_CfgMemMgrMemMapInfoType, DCM_CONST) Dcm_CfgMemMgrMemMap[2]=
{
   { {    1u,   1u},0x70000000u,0x70017F00u}
  ,{ {    0u,   1u},0xEE000000u,0xFF000000u}
};
/*! DCM service initializers */
CONST(Dcm_DiagSvcInitFuncType, DCM_CONST) Dcm_CfgDiagSvcInitializers[1]=
{
   NULL_PTR /* end marker */
};
/*! DCM service properties */
CONST(Dcm_CfgDiagServiceInfoType, DCM_CONST) Dcm_CfgDiagServiceInfo[14]=
{
   { Dcm_Service10Processor,0x01u, 1u,   1u,   2u, 0u, 0u} /* SID: 0x10 */
  ,{ Dcm_Service11Processor,0x01u, 1u,   3u,   4u, 0u, 0u} /* SID: 0x11 */
  ,{ Dcm_Service14Processor,0x00u, 3u,   0u,   0u, 0u, 1u} /* SID: 0x14 */
  ,{ Dcm_Service19Processor,0x01u, 1u,   5u,   0u, 2u, 2u} /* SID: 0x19 */
  ,{ Dcm_Service22Processor,0x00u, 2u,   0u,   0u, 0u, 3u} /* SID: 0x22 */
  ,{ Dcm_Service23Processor,0x00u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x23 */
  ,{ Dcm_Service28Processor,0x01u, 1u,   6u,   0u, 0u, 0u} /* SID: 0x28 */
  ,{ Dcm_SvcWrapper_Ssa_Cdd_DiagnosticService_Authentication_0x29,0x03u, 1u,   0u,   0u, 0u, 0u} /* SID: 0x29 */
  ,{ Dcm_Service2EProcessor,0x00u, 3u,   0u,   0u, 0u, 4u} /* SID: 0x2E */
  ,{ Dcm_Service31Processor,0x01u, 3u,   0u,   0u, 0u, 0u} /* SID: 0x31 */
  ,{ Dcm_Service3DProcessor,0x00u, 4u,   0u,   0u, 0u, 0u} /* SID: 0x3D */
  ,{ Dcm_Service3EProcessor,0x01u, 1u,   0u,   0u, 0u, 0u} /* SID: 0x3E */
  ,{ Dcm_Service85Processor,0x01u, 1u,   7u,   0u, 0u, 5u} /* SID: 0x85 */
  ,{ Dcm_RepeaterDeadEnd,0x00u, 0u,   0u,   0u, 0u, 0u} /* Dcm_RepeaterDeadEnd */
};
/*! Indirection from diag service info to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgDiagSvcIdExecPrecondTable[13]=
{
      0u /* SID: 0x10 */
  ,   0u /* SID: 0x11 */
  ,   1u /* SID: 0x14 */
  ,   1u /* SID: 0x19 */
  ,   0u /* SID: 0x22 */
  ,   0u /* SID: 0x23 */
  ,   2u /* SID: 0x28 */
  ,   0u /* SID: 0x29 */
  ,   0u /* SID: 0x2E */
  ,   0u /* SID: 0x31 */
  ,   2u /* SID: 0x3D */
  ,   0u /* SID: 0x3E */
  ,   2u /* SID: 0x85 */
};
/*! DCM service post processors */
CONST(Dcm_DiagSvcConfirmationFuncType, DCM_CONST) Dcm_CfgDiagSvcPostProcessors[8]=
{
   Dcm_ServiceNoPostProcessor
  ,Dcm_Service10PostProcessor
  ,Dcm_Service10FastPostProcessor
  ,Dcm_Service11PostProcessor
  ,Dcm_Service11FastPostProcessor
  ,Dcm_Service19PostProcessor
  ,Dcm_Service28PostProcessor
  ,Dcm_Service85PostProcessor
};
/*! DCM service paged buffer updater */
CONST(Dcm_DiagSvcUpdateFuncType, DCM_CONST) Dcm_CfgDiagSvcUpdaters[3]=
{
   Dcm_ServiceNoUpdater
  ,Dcm_PagedBufferDataPadding
  ,Dcm_Service19Updater
};
/*! DCM service paged buffer canceller */
CONST(Dcm_DiagSvcCancelFuncType, DCM_CONST) Dcm_CfgDiagSvcCancellers[6]=
{
   Dcm_ServiceNoCancel
  ,Dcm_Service14Cancel
  ,Dcm_Service19Cancel
  ,Dcm_Service22Cancel
  ,Dcm_Service2ECancel
  ,Dcm_Service85Cancel
};
/*! OEM notification functions */
CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagOemNotificationInfo[4]=
{
   { Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Indication,Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_ResetPreconditionCheck_Confirmation}
  ,{ Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_RightsM_Indication,Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_RightsM_Confirmation}
  ,{ Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_Coding_Indication,Rte_Call_ServiceRequestManufacturerNotification_DcmDslServiceRequestManufacturerNotification_Coding_Confirmation}
  ,{ NULL_PTR,NULL_PTR}
};
/*! System supplier notification functions */
CONST(Dcm_CfgDiagNotificationInfoType, DCM_CONST) Dcm_CfgDiagSysNotificationInfo[1]=
{
   { NULL_PTR,NULL_PTR}
};
/*! DCM service to protocol map */
CONST(Dcm_CfgDiagSvc2ProtMapMemType, DCM_CONST) Dcm_CfgDiagSvcId2ProtMap[13]=
{
   0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
  ,0x01u
};
/*! Dcm all variant root */
CONST(Dcm_ConfigsType, DCM_CONST) Dcm_CfgConfigsRoot=
{
   
  {
     &Dcm_CfgNetConfig_Left
    ,
    {
       Dcm_CfgDiagSvcId2ProtMap
    }
  }
  ,
  {
     &Dcm_CfgNetConfig_Right
    ,
    {
       Dcm_CfgDiagSvcId2ProtMap
    }
  }
};
/*! Service 0x10 sub-service properties table  */
CONST(Dcm_CfgSvc10SubFuncInfoType, DCM_CONST) Dcm_CfgSvc10SubFuncInfo[4]=
{
   { { 20u, 200u}, 0u} /* Session ID: 0x01 */
  ,{ { 20u, 200u}, 1u} /* Session ID: 0x02 */
  ,{ { 20u, 200u}, 0u} /* Session ID: 0x03 */
  ,{ { 20u, 200u}, 0u} /* Session ID: 0x7E */
};
/*! Indirection from service 0x10 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc10SubFuncExecPrecondTable[4]=
{
      0u /* Session ID: 0x01 */
  ,   0u /* Session ID: 0x02 */
  ,   0u /* Session ID: 0x03 */
  ,   1u /* Session ID: 0x7E */
};
/*! Service 0x11 sub-service properties table  */
CONST(Dcm_CfgSvc11SubFuncInfoType, DCM_CONST) Dcm_CfgSvc11SubFuncInfo[4]=
{
   { Dcm_Service11_01Processor} /* SF: 0x01 */
  ,{ Dcm_Service11_03Processor} /* SF: 0x03 */
  ,{ Dcm_Service11_04Processor} /* SF: 0x04 */
  ,{ Dcm_Service11_05Processor} /* SF: 0x05 */
};
/*! Indirection from service 0x11 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc11SubFuncExecPrecondTable[4]=
{
      0u /* SF: 0x01 */
  ,   0u /* SF: 0x03 */
  ,   0u /* SF: 0x04 */
  ,   0u /* SF: 0x05 */
};
/*! Service 0x19 sub-service properties table  */
CONST(Dcm_CfgSvc19SubFuncInfoType, DCM_CONST) Dcm_CfgSvc19SubFuncInfo[6]=
{
   { Dcm_Service19_01Processor, 2u} /* SF: 0x01 */
  ,{ Dcm_Service19_02Processor, 2u} /* SF: 0x02 */
  ,{ Dcm_Service19_04Processor, 5u} /* SF: 0x04 */
  ,{ Dcm_Service19_06Processor, 5u} /* SF: 0x06 */
  ,{ Dcm_Service19_0AProcessor, 1u} /* SF: 0x0A */
  ,{ Dcm_Service19_14Processor, 1u} /* SF: 0x14 */
};
/*! Indirection from service 0x19 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc19SubFuncExecPrecondTable[6]=
{
      1u /* SF: 0x01 */
  ,   1u /* SF: 0x02 */
  ,   1u /* SF: 0x04 */
  ,   1u /* SF: 0x06 */
  ,   1u /* SF: 0x0A */
  ,   1u /* SF: 0x14 */
};
/*! Service 0x28 sub-service properties table  */
CONST(Dcm_CfgSvc28SubFuncInfoType, DCM_CONST) Dcm_CfgSvc28SubFuncInfo[2]=
{
   { Dcm_Service28_XXProcessor, 2u} /* SF: 0x00 */
  ,{ Dcm_Service28_XXProcessor, 2u} /* SF: 0x01 */
};
/*! Indirection from service 0x28 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc28SubFuncExecPrecondTable[2]=
{
      2u /* SF: 0x00 */
  ,   2u /* SF: 0x01 */
};
/*! Service 0x28 network ID to ComM channel map */
CONST(NetworkHandleType, DCM_CONST) Dcm_CfgSvc28SubNetIdMap[2]=
{
   DCM_SVC_28_NETWORK_ALL
  ,DCM_SVC_28_NETWORK_CURRENT
};
/*! Indirection from service 0x3E sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc3ESubFuncExecPrecondTable[1]=
{
      0u /* SF: 0x00 */
};
/*! Indirection from service 0x85 sub functions to execution pre conditions */
CONST(Dcm_CfgStateRefMemType, DCM_CONST) Dcm_CfgSvc85SubFuncExecPrecondTable[2]=
{
      2u /* SF: 0x01 */
  ,   2u /* SF: 0x02 */
};
/*! DCM service 0x85 properties */
CONST(Dcm_CfgSvc85SubFuncInfoType, DCM_CONST) Dcm_CfgSvc85SubFuncInfo[2]=
{
   { Dem_EnableDTCSetting,RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING} /* SF: 0x01 */
  ,{ Dem_DisableDTCSetting,RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING} /* SF: 0x02 */
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_ModeOnComControlModeChange()
***********************************************************************************************************************/
/* Implements CDD Dcm_ModeOnComControlModeChange() */
FUNC(void, DCM_CODE) Dcm_ModeOnComControlModeChange(NetworkHandleType channelId, Dcm_CommunicationModeType mode)
{
  switch(channelId)
  {
    case ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6:
      ((void)(Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6(mode)));
      break;
    case ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727:
      ((void)(Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727(mode)));
      break;
    default: /* Just exit the switch case */
      break;
  }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define DCM_START_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Major_Version_ReadData()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_DidMgr<Internal>ReadData() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Major_Version_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  )
{
  uint8 const lReadData[1] = {0x23};

  Dcm_UtiProvideDataAsUN(pDataContext, lReadData, 1); /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */

  return E_OK;
}
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Minor_Version_ReadData()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_DidMgr<Internal>ReadData() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Minor_Version_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  )
{
  uint8 const lReadData[1] = {0x29};

  Dcm_UtiProvideDataAsUN(pDataContext, lReadData, 1); /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */

  return E_OK;
}
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Patch_Version_ReadData()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_DidMgr<Internal>ReadData() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Patch_Version_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  )
{
  uint8 const lReadData[1] = {0x00};

  Dcm_UtiProvideDataAsUN(pDataContext, lReadData, 1); /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */

  return E_OK;
}
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ReadData()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_DidMgr<Internal>ReadData() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Identification_Type_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  )
{
  uint8 const lReadData[1] = {0x00};

  Dcm_UtiProvideDataAsUN(pDataContext, lReadData, 1); /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */

  return E_OK;
}
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ReadData()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_DidMgr<Internal>ReadData() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_XDIS_Version_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  )
{
  uint8 const lReadData[10] = {0x32, 0x33, 0x2E, 0x32, 0x2E, 0x32, 0xFF, 0xFF, 0xFF, 0xFF};

  Dcm_UtiProvideDataAsUN(pDataContext, lReadData, 10); /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */

  return E_OK;
}
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ReadData()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_DidMgr<Internal>ReadData() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Export_Date_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  )
{
  uint8 const lReadData[10] = {0x32, 0x30, 0x32, 0x33, 0x2D, 0x30, 0x37, 0x2D, 0x32, 0x30};

  Dcm_UtiProvideDataAsUN(pDataContext, lReadData, 10); /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */

  return E_OK;
}
/***********************************************************************************************************************
 *  Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ReadData()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_DidMgr<Internal>ReadData() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_DidMgr_ECU_Extract_Version_Read_ECU_Extract_Information_Checksum_ReadData(
  Dcm_DiagDataContextPtrType pDataContext
  )
{
  uint8 const lReadData[40] = {0xF0, 0x60, 0x00, 0x12, 0x86, 0xAC, 0xD0, 0xF8, 0x24, 0x16, 0x14, 0xC6, 0xF5, 0x0B, 0x33,
                               0xBF, 0x52, 0xCC, 0xF8, 0x49, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

  Dcm_UtiProvideDataAsUN(pDataContext, lReadData, 40); /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */

  return E_OK;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0203_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0203_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Check_Reprogramming_Preconditions_Start_Start(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 2u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ /* SBSW_DCM_GEN_RID_WRAPPER */
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0207_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0207_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_PreCheckProgrammingDependencies_Start_Start(
                Dcm_UtiGetReqDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                *DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0260_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0260_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  uint8 dataInConfiguration;
  uint8 dataInTask;
  Std_ReturnType stdReturn;

  dataInConfiguration = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 0u)));  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */

  dataInTask = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 1u)));  


  stdReturn = Rte_Call_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start_Start(
                dataInConfiguration,
                dataInTask,
                Dcm_UtiGetReqDataRel(pMsgContext, 2u),
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 2u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ /* SBSW_DCM_GEN_RID_WRAPPER */
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0261_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0261_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Enhance_Access_Rights_Start_Start(
                Dcm_UtiGetReqDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                *DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0262_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0262_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start_Start(
                Dcm_UtiGetReqDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                *DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0263_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0263_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  uint8 dataInData_to_be_checked;
  Std_ReturnType stdReturn;

  dataInData_to_be_checked = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 0u)));  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Verify_Signature_Start_Start(
                dataInData_to_be_checked,
                Dcm_UtiGetReqDataRel(pMsgContext, 1u),
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0264_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0264_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Replace_Certificates_Start_Start(
                Dcm_UtiGetReqDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                *DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0266_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0266_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start_Start(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ /* SBSW_DCM_GEN_RID_WRAPPER */
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0267_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0267_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Certificate_Self_Check_Start_Start(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ /* SBSW_DCM_GEN_RID_WRAPPER */
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0268_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0268_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  uint8 dataInIn_Post_Production_Flag;
  Std_ReturnType stdReturn;

  dataInIn_Post_Production_Flag = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 0u)));  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_Start(
                dataInIn_Post_Production_Flag,
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0268_Stop()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0268_Stop(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  uint8 dataInIn_Post_Production_Flag;
  Std_ReturnType stdReturn;

  dataInIn_Post_Production_Flag = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 0u)));  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_Stop(
                dataInIn_Post_Production_Flag,
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0268_RequestResults()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0268_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Status_of_Post_Production_Flag_Start_RequestResults(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0274_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0274_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Replace_Trust_model_Certificates_Start_Start(
                Dcm_UtiGetReqDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                *DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0277_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0277_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Replace_Trust_model_Root_Certificate_Start_Start(
                Dcm_UtiGetReqDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */
                Dcm_UtiGetReqDataRel(pMsgContext, 64u),
                Dcm_UtiGetReqDataRel(pMsgContext, 128u),
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                *DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0279_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0279_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start_Start(
                Dcm_UtiGetReqDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */
                Dcm_UtiGetReqDataRel(pMsgContext, 7u),
                Dcm_UtiGetReqDataRel(pMsgContext, 12u),
                Dcm_UtiGetReqDataRel(pMsgContext, 17u),
                Dcm_UtiGetReqDataRel(pMsgContext, 97u),
                Dcm_UtiGetReqDataRel(pMsgContext, 129u),
                Dcm_UtiGetReqDataRel(pMsgContext, 193u),
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                *DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_027B_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_027B_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;


  stdReturn = Rte_Call_RoutineServices_Routine_Trust_Model_Generate_Key_Pair_Start_Start(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 2u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 66u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ /* SBSW_DCM_GEN_RID_WRAPPER */
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_027D_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_027D_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  uint8 dataInIn_Certificate_Identification;
  uint8 dataInIn_Certificate_Entry;
  Std_ReturnType stdReturn;

  dataInIn_Certificate_Identification = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 0u)));  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */

  dataInIn_Certificate_Entry = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 1u)));  


  stdReturn = Rte_Call_RoutineServices_Routine_Get_Certificate_Entry_Start_Start(
                dataInIn_Certificate_Identification,
                dataInIn_Certificate_Entry,
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 2u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 3u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 4u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                DataLength,
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ /* SBSW_DCM_GEN_RID_WRAPPER */
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0302_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0302_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_Start(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0302_RequestResults()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0302_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_RequestResults(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0329_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0329_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Trigger_BSR_Start_Start(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0329_RequestResults()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0329_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Trigger_BSR_Start_RequestResults(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0330_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0330_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  uint8 dataInType_of_tensioning_cycle;
  uint8 dataInPreSafe_Duration;
  Std_ReturnType stdReturn;

  dataInType_of_tensioning_cycle = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 0u)));  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */

  dataInPreSafe_Duration = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 1u)));  

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_Start(
                dataInType_of_tensioning_cycle,
                dataInPreSafe_Duration,
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_0330_RequestResults()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_0330_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_RequestResults(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_F703_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F703_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  uint8 dataInCycle;
  Std_ReturnType stdReturn;

  dataInCycle = ((uint8)(Dcm_UtiGetReqDataAsU8Rel(pMsgContext, 0u)));  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Cycle_Execution_Start_Start(
                dataInCycle,
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_F703_RequestResults()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F703_RequestResults(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Cycle_Execution_Start_RequestResults(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_F782_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F782_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Erase_All_Start_Start(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_RidMgr_F791_Start()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_RidMgr<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_RidMgr_F791_Start(
  Dcm_OpStatusType OpStatus,
  Dcm_MsgContextPtrType pMsgContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_RidMgrRidLengthPtrType DataLength,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  Std_ReturnType stdReturn;

  DCM_IGNORE_UNREF_PARAM(DataLength);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */

  stdReturn = Rte_Call_RoutineServices_Routine_Force_External_WDG_Start_Start(
                OpStatus,
                Dcm_UtiGetResDataRel(pMsgContext, 0u),  /* PRQA S 2985 */ /* MD_Dcm_Redundant_2985 */ /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                Dcm_UtiGetResDataRel(pMsgContext, 1u),  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
                ErrorCode
                );  /* SBSW_DCM_GEN_COMB_PARAM_PTR_FORWARD */ 
  return stdReturn;
}
/***********************************************************************************************************************
 *  Dcm_SvcWrapper_Ssa_Cdd_DiagnosticService_Authentication_0x29()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_SvcWrapper_<XXX>() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SvcWrapper_Ssa_Cdd_DiagnosticService_Authentication_0x29(
  Dcm_ContextPtrType pContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_OpStatusType opStatus,
  Dcm_MsgContextPtrType pMsgContext,
  Dcm_NegativeResponseCodePtrType ErrorCode
  )
{
  DCM_IGNORE_UNREF_PARAM(pContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  return Ssa_Cdd_DiagnosticService_Authentication_0x29(opStatus, pMsgContext, ErrorCode);  /* SBSW_DCM_GEN_PARAM_PTR_FORWARD */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoPostProcessor()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoPostProcessor() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoPostProcessor(
  Dcm_ContextPtrType pContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_ConfirmationStatusType status
  )
{
  DCM_IGNORE_UNREF_PARAM(pContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(status);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoUpdater()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoUpdater() */
DCM_LOCAL FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_ServiceNoUpdater(
  Dcm_ContextPtrType pContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_OpStatusType opStatus,
  Dcm_DiagDataContextPtrType pDataContext,  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  Dcm_NegativeResponseCodePtrType ErrorCode  /* PRQA S 3673 */ /* MD_Dcm_APIStd_3673 */
  )
{
  DCM_IGNORE_UNREF_PARAM(pContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(opStatus);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(pDataContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  DCM_IGNORE_UNREF_PARAM(ErrorCode);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  return E_NOT_OK;
}
/***********************************************************************************************************************
 *  Dcm_ServiceNoCancel()
 ***********************************************************************************************************************/
/* Implements CDD Dcm_ServiceNoCancel() */
DCM_LOCAL FUNC(void, DCM_CALLOUT_CODE) Dcm_ServiceNoCancel(
  Dcm_ContextPtrType pContext  /* PRQA S 3673 */ /* MD_Dcm_Design_3673 */
  )
{
  DCM_IGNORE_UNREF_PARAM(pContext);  /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  /* nothing to do */
}
#define DCM_STOP_SEC_CALLOUT_CODE
#include "Dcm_MemMap.h"                                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: Dcm_Lcfg.c
 *********************************************************************************************************************/

