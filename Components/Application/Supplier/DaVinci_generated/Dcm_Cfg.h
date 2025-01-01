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
 *              File: Dcm_Cfg.h
 *   Generation Time: 2024-01-03 15:18:51
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


#if !defined(DCM_CFG_H)
# define DCM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/*! Implementation version */
# define DCM_CFG_MAJOR_VERSION                                                 17u
# define DCM_CFG_MINOR_VERSION                                                  5u
# define DCM_CFG_PATCH_VERSION                                                  0u

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! Access to version information */
# define DCM_VERSION_INFO_API                                                  STD_OFF
/*! Development error detection and reporting */
# define DCM_DEV_ERROR_REPORT                                                  STD_OFF
/*! Highest possible safety module usage */
# define DCM_DEV_ERROR_DETECT                                                  STD_OFF
/*! Specifies whether DCM will be put into SafeBSW mode (restricted features). */
# define DCM_DEV_RUNTIME_CHECKS                                                STD_OFF
/*! Support reporting of security events to IdsM */
# define DCM_DEBUG_SECURITY_EVENT_REPORT_ENABLED                               STD_OFF
/*! Optimization for single client configurations */
# define DCM_NET_MULTI_CLIENT_ENABLED                                          STD_ON
/*! Support communication control on all ECU channels */
# define DCM_NET_COMCTRL_ALLNET_SUPPORT_ENABLED                                STD_ON
/*! Periodic transmission unit */
# define DCM_NET_PERIODIC_TX_ENABLED                                           STD_OFF
/*! Periodic transmission unused byte padding */
# define DCM_NET_PERIODIC_MSG_PADDING_ENABLED                                  STD_OFF
/*! Periodic transmission UUDT delay timer */
# define DCM_NET_UUDT_DELAYTIMER_ENABLED                                       STD_OFF
/*! Support monitoring of requests to other ECUs */
# define DCM_NET_MONITOR_FOREIGN_N_TA_ENABLED                                  STD_OFF
/*! Support generic connections */
# define DCM_NET_GENERIC_CONNECTION_ENABLED                                    STD_OFF
/*! Protect against clients other than the one started the non-default session */
# define DCM_NET_PROTECT_SESSION_OF_CLIENT_ENABLED                             STD_ON
/*! Paged buffer support for DEM interfaces */
# define DCM_DEMIF_PAGED_BUFFER_ENABLED                                        STD_ON
/*! Paged buffer support */
# define DCM_PAGED_BUFFER_ENABLED                                              STD_ON
/*! Any diagnostic object needs rule check */
# define DCM_MODEMGR_CHECK_SUPPORT_ENABLED                                     STD_OFF
/*! ECU rapid shutdown mode management support */
# define DCM_MODE_RPD_SHTDWN_ENABLED                                           STD_ON
/*! ECU reset mode management support */
# define DCM_MODE_ECU_RESET_ENABLED                                            STD_ON
/*! Control DTC setting mode management support */
# define DCM_MODE_CTRLDTCSETTING_ENABLED                                       STD_ON
/*! Control DTC setting mode management monitoring support */
# define DCM_MODE_CTRLDTCSETTING_MONITOR_ENABLED                               STD_OFF
/*! Communication control mode management support */
# define DCM_MODE_COMMCTRL_ENABLED                                             STD_ON
/*! Communication control mode management monitoring support */
# define DCM_MODE_COMMCTRL_MONITOR_ENABLED                                     STD_OFF
/*! Security access mode management support */
# define DCM_MODE_SECURITY_ACCESS_ENABLED                                      STD_OFF
/*! Response on event mode management support */
# define DCM_MODE_ROE_ENABLED                                                  STD_OFF
/*! Authentication general NRC mode management support */
# define DCM_MODE_AUTH_GENERAL_NRC_ENABLED                                     STD_OFF
/*! Support security access state management */
# define DCM_STATE_SECURITY_ENABLED                                            STD_OFF
/*! Support security access delay on boot */
# define DCM_STATE_SEC_DELAY_ON_BOOT_ENABLED                                   STD_OFF
/*! Support SecurityGet-/SetAttemptCounter APIs */
# define DCM_STATE_SEC_ATT_CNTR_EXT_STORAGE_ENABLED                            STD_OFF
/*! Support security fixed bytes */
# define DCM_STATE_SECURITY_FIXED_BYTES_ENABLED                                STD_OFF
/*! Support mulitple secuirty fixed bytes per security level */
# define DCM_STATE_MULTIPLE_SECURITYFIXEDBYTES_ENABLED                         STD_OFF
/*! Support authentication state management */
# define DCM_STATE_AUTHENTICATION_ENABLED                                      STD_OFF
/*! Support security level bypass */
# define DCM_STATE_SECURITY_BYPASS_ENABLED                                     STD_OFF
/*! DEM Interfaces for AR 4.2.1 */
# define DCM_DEMIF_421_ENABLED                                                 STD_OFF
/*! DEM Interfaces for AR 4.3.0 */
# define DCM_DEMIF_430_ENABLED                                                 STD_ON
/*! DEM Interfaces for AR 4.3.1 */
# define DCM_DEMIF_431_ENABLED                                                 STD_OFF
/*! Support DID manager  */
# define DCM_DIDMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support external DID look up filter */
# define DCM_DIDMGR_EXTENDED_LOOKUP_ENABLED                                    STD_OFF
/*! Any paged DID supported */
# define DCM_DIDMGR_PAGED_SUPPORT_ENABLED                                      STD_OFF
/*! Wether implicit communication of RTE affects Dcm */
# define DCM_DIDMGR_RTE_IMPLICIT_COM_ENABLED                                   STD_ON
/*! Support IO control (Reset To Default, Freeze Current State, Short Term Adjustment) operation in S/R style */
# define DCM_DIDMGR_SR_IO_CONTROL_ENABLED                                      STD_OFF
/*! There is a dynamically define periodic DID */
# define DCM_DIDMGR_PERIODICDYNDID_ENABLED                                     STD_OFF
/*! Automatically remove any periodic DID not supported any more in the current state */
# define DCM_DIDMGR_PERIODICDID_CLR_ON_STATE_CHG_ENABLED                       STD_OFF
/*! Support DID ROE */
# define DCM_DIDMGR_OP_INFO_ROE_ENABLED                                        STD_OFF
/*! Support dynamically define DID additional information */
# define DCM_DIDMGR_OP_INFO_DEFINE_ENABLED                                     STD_OFF
/*! The ConditionCheckRead operation on source items will be called */
# define DCM_DIDMGR_DYNDID_SRCITEM_CHECK_COND_ENABLED                          STD_OFF
/*! The session and security states as well as any configured mode conditions on source items will be validated */
# define DCM_DIDMGR_DYNDID_SRCITEM_CHECK_STATE_ENABLED                         STD_OFF
/*! Automatically clear any dynamically defined DID not supported any more in the current state */
# define DCM_DIDMGR_DYNDID_CLR_ON_STATE_CHG_ENABLED                            STD_OFF
/*! Supports any DID NvM signals with read operation */
# define DCM_DIDMGR_NVM_READ_ENABLED                                           STD_OFF
/*! Supports any DID NvM signals with write operation */
# define DCM_DIDMGR_NVM_WRITE_ENABLED                                          STD_OFF
/*! Supports DID 0xF186 signal with read operation */
# define DCM_DIDMGR_DID_F186_READ_ENABLED                                      STD_OFF
/*! Support report of NODI Byte */
# define DCM_DIDMGR_REPORT_NODIBYTE_ENABLED                                    STD_OFF
/*! Support read operation */
# define DCM_DIDMGR_OPTYPE_READ_ENABLED                                        STD_ON
/*! Support DID ranges with gaps */
# define DCM_DIDMGR_OPTYPE_RANGE_ISAVAIL_ENABLED                               STD_OFF
/*! Support return control to ECU */
# define DCM_DIDMGR_OPTYPE_IO_RETCTRL2ECU_ENABLED                              STD_OFF
/*! Support short term adjustment */
# define DCM_DIDMGR_OPTYPE_IO_SHRTTERMADJ_ENABLED                              STD_OFF
/*! Support RID manager  */
# define DCM_RIDMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support external RID look up filter */
# define DCM_RIDMGR_EXTENDED_LOOKUP_ENABLED                                    STD_OFF
/*! Support direct memory access */
# define DCM_MEMMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support memory transfer via FBL */
# define DCM_FBLMGR_SUPPORT_ENABLED                                            STD_OFF
/*! Support manager for OBD and UDS IDs */
# define DCM_OBDUDSIDMGR_SUPPORT_ENABLED                                       STD_OFF
/*! Support calibration for OBD and UDS IDs */
# define DCM_OBDUDSIDMGR_CALIBRATION_ENABLED                                   STD_OFF
/*! Support UDS MIDs provided by DEM module */
# define DCM_OBDUDSIDMGR_UDSMID_SUPPORT_BY_DEM_ENABLED                         STD_OFF
/*! Support UDS MIDs from DCM configuration */
# define DCM_OBDUDSIDMGR_UDSMID_SUPPORT_BY_DCM_ENABLED                         STD_OFF
/*! Support of OBD calibration via service 0x22 will be handled by DCM */
# define DCM_SVC_22_OBD_CALIBRATION_ENABLED                                    STD_OFF
/*! Support of OBD calibration via service 0x31 will be handled by DCM */
# define DCM_SVC_31_OBD_CALIBRATION_ENABLED                                    STD_OFF
/*! Support OBD manager for IDs */
# define DCM_OBDIDMGR_SUPPORT_ENABLED                                          STD_OFF
/*! Support OBD-MIDs through the AUTOSAR DEM APIs */
# define DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DEM_ENABLED                            STD_OFF
/*! Support OBD-MIDs in DCM, don't use the AUTOSAR DEM APIs */
# define DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DCM_ENABLED                            STD_OFF
/*! Support manager for OBD DTCs */
# define DCM_OBDDTCMGR_SUPPORT_ENABLED                                         STD_OFF
/*! Split task concept */
# define DCM_SPLIT_TASKS_ENABLED                                               STD_OFF
/*! Delay the unregistration of a diagnostic user */
# define DCM_NET_KEEP_ALIVE_TIME_ENABLED                                       STD_OFF
/*! Start keep alive timer on functional 0x3E 80 request */
# define DCM_NET_KEEP_ALIVE_TIME_START_ON_FUNC_3E_80_ENABLED                   STD_OFF
/*! Parallel service processing */
# define DCM_MULTI_THREAD_ENABLED                                              STD_OFF
/*! Ignore any reqeust with response SID */
# define DCM_DIAG_IGNORE_RESPONSE_SID_ENABLED                                  STD_OFF
/*! Support final response after reset from FBL */
# define DCM_DIAG_JUMPFROMFBL_ENABLED                                          STD_ON
/*! Support jump to the FBL */
# define DCM_DIAG_JUMPTOFBL_ENABLED                                            STD_ON
/*! Suppression of NRC 0x7E, 0x7F on functional requests */
# define DCM_DIAG_SUPPRESS_NRC_7F_7E_ENABLED                                   STD_ON
/*! BswM notification for updated application */
# define DCM_DIAG_NOTIF_BSWM_APPL_UPDATED_ENABLED                              STD_OFF
/*! Reset to default session on any functionally requested OBD service */
# define DCM_DIAG_RST2DEF_ON_FUNC_OBD_REQ_ENABLED                              STD_OFF
/*! Support DCM state recovery */
# define DCM_DIAG_STATE_RECOVERY_ENABLED                                       STD_OFF
/*! Support RCR-RP transmission limitation */
# define DCM_DIAG_RCRRP_LIMIT_ENABLED                                          STD_ON
/*! Support virtual requests */
# define DCM_DIAG_VIRTUAL_REQUEST_ENABLED                                      STD_OFF
/*! Support diagnostic service dispatcher */
# define DCM_DIAG_SERVICE_DISPATCHER_ENABLED                                   STD_OFF
/*! Support SpecificCauseCode in negative response messages */
# define DCM_DIAG_SPECIFIC_CAUSE_CODE_ENABLED                                  STD_OFF
/*! Support variant management */
# define DCM_VARMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support configuration variant management */
# define DCM_VARMGR_MULTI_SVC_EXCLUSIVE_ENABLED                                STD_OFF
/*! Support VSG variant management */
# define DCM_VARMGR_MULTI_SVC_INCLUSIVE_ENABLED                                STD_OFF
/*! Support communication variant management */
# define DCM_VARMGR_MULTI_COM_ENABLED                                          STD_ON
/*! Active configuration mode for pre-compile */
# define DCM_VARMGR_MODE_PRECOMPILE_ENABLED                                    STD_OFF
/*! Active configuration mode for link-time */
# define DCM_VARMGR_MODE_LINKTIME_ENABLED                                      STD_OFF
/*! Active configuration mode for post build loadable */
# define DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED                                STD_OFF
/*! Active configuration mode for post build selectable */
# define DCM_VARMGR_MODE_POSTBUILD_SELECT_ENABLED                              STD_ON
/*! Support authentication manager */
# define DCM_AUTHMGR_SUPPORT_ENABLED                                           STD_OFF
/*! Support authentication with services white lists */
# define DCM_AUTHMGR_WHITELIST_SERVICES_ENABLED                                STD_OFF
/*! Support authentication with DID white lists */
# define DCM_AUTHMGR_WHITELIST_DID_ENABLED                                     STD_OFF
/*! Support authentication with RID white lists */
# define DCM_AUTHMGR_WHITELIST_RID_ENABLED                                     STD_OFF
/*! Support authentication with memory selection white lists */
# define DCM_AUTHMGR_WHITELIST_MEM_ENABLED                                     STD_OFF
/*! Support authentication state persistence in non-volatile memory */
# define DCM_AUTHMGR_PERSIST_STATE_ENABLED                                     STD_OFF
/*! Support API Dcm_SetDeauthenticatedRole() */
# define DCM_AUTHMGR_SET_DEAUTH_ROLE_ENABLED                                   STD_OFF
/*! Support Default Session Timeout */
# define DCM_AUTHMGR_DEFAULT_SESSION_TIMEOUT_ENABLED                           STD_OFF
/*! Diagnostic service 0x01 handled by DCM */
# define DCM_SVC_01_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x02 handled by DCM */
# define DCM_SVC_02_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x03 handled by DCM */
# define DCM_SVC_03_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x04 handled by DCM */
# define DCM_SVC_04_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x06 handled by DCM */
# define DCM_SVC_06_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x07 handled by DCM */
# define DCM_SVC_07_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x08 handled by DCM */
# define DCM_SVC_08_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x09 handled by DCM */
# define DCM_SVC_09_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x0A handled by DCM */
# define DCM_SVC_0A_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x10 handled by DCM */
# define DCM_SVC_10_SUPPORT_ENABLED                                            STD_ON
/*! Support jump to bootloader */
# define DCM_SVC_10_JMP2BOOT_ENABLED                                           STD_ON
/*! Reset the ECU before the final response is sent */
# define DCM_SVC_10_RST2BOOT_HIS_ENABLED                                       STD_OFF
/*! Diagnostic service 0x11 handled by DCM */
# define DCM_SVC_11_SUPPORT_ENABLED                                            STD_ON
# define DCM_SVC_11_ECU_RESET_ENABLED                                          STD_ON
# define DCM_SVC_11_RAPID_SHTDWN_ENABLED                                       STD_ON
/*! Reset the ECU before the final response is sent */
# define DCM_SVC_11_RST2BOOT_HIS_ENABLED                                       STD_OFF
# define DCM_SVC_11_01_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_11_02_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_11_03_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_11_04_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_11_05_SUPPORT_ENABLED                                         STD_ON
/*! Diagnostic service 0x14 handled by DCM */
# define DCM_SVC_14_SUPPORT_ENABLED                                            STD_ON
/*! User memory identifier available */
# define DCM_SVC_14_USER_MEM_ID_ENABLED                                        STD_OFF
/*! User memory identifier evaluation */
# define DCM_SVC_14_USER_MEM_ID_CHECK_ENABLED                                  STD_OFF
/*! Diagnostic service 0x19 handled by DCM */
# define DCM_SVC_19_SUPPORT_ENABLED                                            STD_ON
# define DCM_SVC_19_01_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_02_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_03_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_04_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_05_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_06_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_07_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_08_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_09_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0A_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_0B_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0C_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0D_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0E_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0F_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_10_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_11_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_12_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_13_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_14_SUPPORT_ENABLED                                         STD_ON
# define DCM_SVC_19_15_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_16_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_17_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_18_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_19_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_1A_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_42_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_55_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_56_SUPPORT_ENABLED                                         STD_OFF
/*! User memory identifier evaluation */
# define DCM_SVC_19_USER_MEM_ID_CHECK_ENABLED                                  STD_OFF
/*! Dtc Status patch support */
# define DCM_SVC_19_PATCH_SUPPORT_ENABLED                                      STD_OFF
/*! Diagnostic service 0x22 handled by DCM */
# define DCM_SVC_22_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x23 handled by DCM */
# define DCM_SVC_23_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x24 handled by DCM */
# define DCM_SVC_24_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x27 handled by DCM */
# define DCM_SVC_27_SUPPORT_ENABLED                                            STD_OFF
/*! Support multiple attempt counter instances */
# define DCM_SVC_27_MULTI_ATTEMPT_COUNTER_ENABLED                              STD_OFF
/*! Support multiple delay timer instances */
# define DCM_SVC_27_MULTI_DELAY_TIMER_ENABLED                                  STD_OFF
/*! Security attempt counter reset on delay timer expiry */
# define DCM_STATE_SEC_RESET_ATT_CNTR_ON_TIMEOUT_ENABLED                       STD_OFF
/*! Diagnostic service 0x28 handled by DCM */
# define DCM_SVC_28_SUPPORT_ENABLED                                            STD_ON
/*! Support communication control on the request channel */
# define DCM_SVC_28_CURNET_SUPPORT_ENABLED                                     STD_ON
/*! Diagnostic service 0x29 handled by DCM */
# define DCM_SVC_29_SUPPORT_ENABLED                                            STD_OFF
/*! Support unidirectional certificate verification */
# define DCM_SVC_29_01_SUPPORT_ENABLED                                         STD_OFF
/*! Support bidirectional certificate verification */
# define DCM_SVC_29_02_SUPPORT_ENABLED                                         STD_OFF
/*! Support certificate transmission */
# define DCM_SVC_29_04_SUPPORT_ENABLED                                         STD_OFF
/*! Diagnostic service 0x2A handled by DCM */
# define DCM_SVC_2A_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x2C handled by DCM */
# define DCM_SVC_2C_SUPPORT_ENABLED                                            STD_OFF
/*! Support dynamically define DID by identifier */
# define DCM_SVC_2C_01_SUPPORT_ENABLED                                         STD_OFF
/*! Support dynamically define DID by memory address */
# define DCM_SVC_2C_02_SUPPORT_ENABLED                                         STD_OFF
/*! Support clear dynamically defined DID */
# define DCM_SVC_2C_03_SUPPORT_ENABLED                                         STD_OFF
/*! Support NvM persistence of dynamically defined DID */
# define DCM_SVC_2C_NVRAM_SUPPORT_ENABLED                                      STD_OFF
/*! Diagnostic service 0x2E handled by DCM */
# define DCM_SVC_2E_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x2F handled by DCM */
# define DCM_SVC_2F_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x31 handled by DCM */
# define DCM_SVC_31_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x34 handled by DCM */
# define DCM_SVC_34_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x35 handled by DCM */
# define DCM_SVC_35_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x36 handled by DCM */
# define DCM_SVC_36_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x37 handled by DCM */
# define DCM_SVC_37_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x38 handled by DCM */
# define DCM_SVC_38_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x3D handled by DCM */
# define DCM_SVC_3D_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x3E handled by DCM */
# define DCM_SVC_3E_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x85 handled by DCM */
# define DCM_SVC_85_SUPPORT_ENABLED                                            STD_ON
/*! Support DTC group in requests  */
# define DCM_SVC_85_DTC_GRP_ENABLED                                            STD_OFF
/*! Diagnostic service 0x86 handled by DCM */
# define DCM_SVC_86_SUPPORT_ENABLED                                            STD_OFF
/*! Support stop response on event with store event-bit unset */
# define DCM_SVC_86_00_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on DTC status-change with store event-bit unset */
# define DCM_SVC_86_01_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on change of data identifier with store event-bit unset */
# define DCM_SVC_86_03_SUPPORT_ENABLED                                         STD_OFF
/*! Support report activated events with store event-bit unset */
# define DCM_SVC_86_04_SUPPORT_ENABLED                                         STD_OFF
/*! Support start response on event with store event-bit unset */
# define DCM_SVC_86_05_SUPPORT_ENABLED                                         STD_OFF
/*! Support clear response on event with store event-bit unset */
# define DCM_SVC_86_06_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on comparison of values with store event-bit unset */
# define DCM_SVC_86_07_SUPPORT_ENABLED                                         STD_OFF
/*! Support stop response on event with store event-bit set */
# define DCM_SVC_86_40_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on DTC status-change with store event-bit set */
# define DCM_SVC_86_41_SUPPORT_ENABLED                                         STD_OFF
/*! Support response on change of data identifier with store event-bit set */
# define DCM_SVC_86_43_SUPPORT_ENABLED                                         STD_OFF
/*! Support start response on event with store event-bit set */
# define DCM_SVC_86_45_SUPPORT_ENABLED                                         STD_OFF
/*! Support clear response on event with store event-bit set */
# define DCM_SVC_86_46_SUPPORT_ENABLED                                         STD_OFF
/*! Service 0x86 needs a timer */
# define DCM_SVC_86_TIMER_ENABLED                                              STD_OFF
/*! Service 0x86 will be reset on session transition */
# define DCM_SVC_86_RST_ON_DSC_ENABLED                                         STD_OFF
/*! Service 0x86 needs nv blocks */
# define DCM_SVC_86_NVM_SUPPORT_ENABLED                                        STD_OFF
/*! Service 0x86 event type DID supported  */
# define DCM_SVC_86_EVTYPE_ONCHGDID_ENABLED                                    STD_OFF
/*! Service 0x86 event type DTC supported  */
# define DCM_SVC_86_EVTYPE_ONCHGDTC_ENABLED                                    STD_OFF

/*! The maximum number of iterations per DCM task activation */
# define DCM_RUNTIME_USAGE_ITERATIONS                                           0u
/*! DCM AUTOSAR versions */
# define DCM_DCM_AR_VERSION_421                                                0x0421u
/*! DCM AUTOSAR versions */
# define DCM_DCM_AR_VERSION_422                                                0x0422u
/*! DCM active AUTOSAR version */
# define DCM_DCM_AR_VERSION                                                    0x0422u
/*! Vendor specific DCM extension identifier */
# define DCM_EXTENSION_ID                                                      0x96ACD543u
/*! Invalid security event */
# define DCM_DEBUG_SEV_INVALID                                                 0xFFFFu
/*! Security event for successful authentication */
# define DCM_DEBUG_SEV_AUTHENTICATION_SUCCESSFUL                               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_CERTIFICATE_FAILURE */
# define DCM_DEBUG_SEV_CERTIFICATE_FAILURE                                     DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_CLEAR_DTC_SUCCESSFUL */
# define DCM_DEBUG_SEV_CLEAR_DTC_SUCCESSFUL                                    DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_COMMUNICATION_CONTROL_SWITCHED_OFF */
# define DCM_DEBUG_SEV_COMMUNICATION_CONTROL_SWITCHED_OFF                      DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_DTC_SETTING_SWITCHED_OFF */
# define DCM_DEBUG_SEV_DTC_SETTING_SWITCHED_OFF                                DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_ECU_RESET */
# define DCM_DEBUG_SEV_ECU_RESET                                               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_ECU_UNLOCK_SUCCESSFUL */
# define DCM_DEBUG_SEV_ECU_UNLOCK_SUCCESSFUL                                   DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_INCORRECT_MESSAGE_LENGTH_OR_FORMAT */
# define DCM_DEBUG_SEV_INCORRECT_MESSAGE_LENGTH_OR_FORMAT                      DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_REQUEST_DOWNLOAD */
# define DCM_DEBUG_SEV_REQUEST_DOWNLOAD                                        DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_REQUEST_OUT_OF_RANGE */
# define DCM_DEBUG_SEV_REQUEST_OUT_OF_RANGE                                    DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_REQUEST_SEQUENCE_ERROR */
# define DCM_DEBUG_SEV_REQUEST_SEQUENCE_ERROR                                  DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_REQUESTED_ACTIONS_REQUIRES_AUTHENTICATION */
# define DCM_DEBUG_SEV_REQUESTED_ACTIONS_REQUIRES_AUTHENTICATION               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SECURITY_ACCESS_DENIED */
# define DCM_DEBUG_SEV_SECURITY_ACCESS_DENIED                                  DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SECURITY_ACCESS_INVALID_KEY */
# define DCM_DEBUG_SEV_SECURITY_ACCESS_INVALID_KEY                             DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SECURITY_ACCESS_NUMBER_OF_ATTEMPTS_EXCEEDED */
# define DCM_DEBUG_SEV_SECURITY_ACCESS_NUMBER_OF_ATTEMPTS_EXCEEDED             DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SECURITY_ACCESS_REQUIRED_TIME_DELAY_NOT_EXPIRED */
# define DCM_DEBUG_SEV_SECURITY_ACCESS_REQUIRED_TIME_DELAY_NOT_EXPIRED         DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SERVICE_NOT_SUPPORTED */
# define DCM_DEBUG_SEV_SERVICE_NOT_SUPPORTED                                   DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_SUBFUNCTION_NOT_SUPPORTED */
# define DCM_DEBUG_SEV_SUBFUNCTION_NOT_SUPPORTED                               DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_WRITE_DATA */
# define DCM_DEBUG_SEV_WRITE_DATA                                              DCM_DEBUG_SEV_INVALID
/*! Security event DIAG_SEV_WRITE_INV_DATA */
# define DCM_DEBUG_SEV_WRITE_INV_DATA                                          DCM_DEBUG_SEV_INVALID
/*! Specifies the AUTOSAR version of the PduR API */
# define DCM_PDUR_API_AR_VERSION                                               0x412
/*! Number of available buffers */
# define DCM_NET_NUM_BUFFERS                                                    1u
/*! Maximum number of ComM channels to keep ECU awake */
# define DCM_NET_MAX_NUM_COMM_CHANNELS                                          1u
/*! Maximum number of ComM channels DCM communicates over */
# define DCM_NET_MAX_NUM_CHANNELS                                               1u
/*! Maximum number of parallel running connections */
# define DCM_NET_MAX_NUM_TRANSP_OBJECTS                                         3u
/*! Maximum number of periodic transmission objects */
# define DCM_NET_MAX_NUM_PERIODIC_TX_OBJ                                        0u
/*! Periodic buffer size */
# define DCM_NET_PERIODIC_BUFFER_SIZE                                           0u
/*! Pattern byte used for periodic transmission message padding */
# define DCM_NET_PERIODIC_MSG_PADDING_PATTERN                                  0xAAu
/*! The maximum size of all configured buffers */
# define DCM_NET_MAX_BUFFER_SIZE                                               4095u
/*! Maximum number of connections */
# define DCM_NET_MAX_NUM_CONNECTIONS                                            3u
/*! Number of channels from main connections and ComControl channels */
# define DCM_NET_MAX_NUM_ALL_COMM_CHANNELS                                        2u
/*! The default DemClientId */
# define DCM_NET_DEFAULT_DEM_CLIENTID                                          DemConf_DemClient_DemClient
/*! The number of periodic messages to be sent within the delay time */
# define DCM_NET_DELAY_BULK_TRANSMISSION                                        0u
/*! Maximum periodic response length for service 0x2A */
# define DCM_SVC2A_MAX_RESPONSE_LEN                                             0u
/*! Size of table Dcm_CfgNetBufferInfo */
# define DCM_CFGNETBUFFERINFO_SIZE                                              1u
/*! Size of table Dcm_CfgNetProtocolNotificationInfo */
# define DCM_CFGNETPROTOCOLNOTIFICATIONINFO_SIZE                                1u
/*!  ----- Symbolic name values for DCM protocols -----  */
# define DcmConf_DcmDslProtocolRow_DcmDslProtocolRow_29812fbf                   3u
/*!  ----- Symbolic name values for Rx PduIds -----  */
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx_2b322367  0u
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx_d414628a  2u
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx_c0cc433b  4u
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx_2873db84  1u
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx_5a27dd11  3u
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx_6a163982  5u
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx_3b6533a8  1u
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx_510ebea9  3u
# define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx_536fd8c4  5u
/*!  ----- Symbolic name values for Tx PduIds -----  */
# define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx_70f6d2b0  0u
# define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx_2b590afc  1u
# define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx_3060e687  2u
# define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx_82eb6958  0u
# define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx_afb57ffd  1u
# define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx_f8a04d74  2u
/*! Size of table Dcm_CfgNetRxPduInfo_Left */
# define DCM_CFGNETRXPDUINFO_LEFT_SIZE                                          6u
/*! Size of table Dcm_CfgNetTxPduInfo_Left */
# define DCM_CFGNETTXPDUINFO_LEFT_SIZE                                          3u
/*! Size of table Dcm_CfgNetConnectionInfo_Left */
# define DCM_CFGNETCONNECTIONINFO_LEFT_SIZE                                     3u
/*! Size of table Dcm_CfgNetProtocolInfo_Left */
# define DCM_CFGNETPROTOCOLINFO_LEFT_SIZE                                       1u
/*! Size of table Dcm_CfgNetAllComMChannelMap_Left */
# define DCM_CFGNETALLCOMMCHANNELMAP_LEFT_SIZE                                  1u
/*! Size of table Dcm_CfgNetConnComMChannelMap_Left */
# define DCM_CFGNETCONNCOMMCHANNELMAP_LEFT_SIZE                                 1u
/*! Size of table Dcm_CfgNetNetworkHandleLookUpTable_Left */
# define DCM_CFGNETNETWORKHANDLELOOKUPTABLE_LEFT_SIZE                           2u
/*! Size of table Dcm_CfgNetComCtrlChannelListAll_Left */
# define DCM_CFGNETCOMCTRLCHANNELLISTALL_LEFT_SIZE                              2u
/*! Size of table Dcm_CfgNetRxPduInfo_Right */
# define DCM_CFGNETRXPDUINFO_RIGHT_SIZE                                         6u
/*! Size of table Dcm_CfgNetTxPduInfo_Right */
# define DCM_CFGNETTXPDUINFO_RIGHT_SIZE                                         3u
/*! Size of table Dcm_CfgNetConnectionInfo_Right */
# define DCM_CFGNETCONNECTIONINFO_RIGHT_SIZE                                    3u
/*! Size of table Dcm_CfgNetProtocolInfo_Right */
# define DCM_CFGNETPROTOCOLINFO_RIGHT_SIZE                                      1u
/*! Size of table Dcm_CfgNetAllComMChannelMap_Right */
# define DCM_CFGNETALLCOMMCHANNELMAP_RIGHT_SIZE                                 1u
/*! Size of table Dcm_CfgNetConnComMChannelMap_Right */
# define DCM_CFGNETCONNCOMMCHANNELMAP_RIGHT_SIZE                                1u
/*! Size of table Dcm_CfgNetNetworkHandleLookUpTable_Right */
# define DCM_CFGNETNETWORKHANDLELOOKUPTABLE_RIGHT_SIZE                          2u
/*! Size of table Dcm_CfgNetComCtrlChannelListAll_Right */
# define DCM_CFGNETCOMCTRLCHANNELLISTALL_RIGHT_SIZE                             2u
/*! Reference to padding function */
# define DCM_PAGEDBUFFER_PADDING_FUNC_REF                                       1u
/*! The mode rule reference for DTC setting re-enabling */
# define DCM_MODE_CTRLDTCSETTING_MONITOR_MODERULE_REF                             0u
/*! The mode rule reference for communication control re-enabling */
# define DCM_MODE_COMMCTRL_MONITOR_MODERULE_REF                                   0u
/*! The mode rule reference for sending the general authentication NRC */
# define DCM_MODE_AUTH_SEND_GENERAL_NRC_MODERULE_REF                              0u
/*! The mode rule reference for persisting the authentication state */
# define DCM_MODE_AUTH_PERSIST_STATE_MODERULE_REF                                 0u
/*! Number of session states */
# define DCM_STATE_NUM_SESSION                                                  4u
/*! Number of security access states */
# define DCM_STATE_NUM_SECURITY                                                 0u
/*! Number of security levels (all security states except the "locked" one) */
# define DCM_STATE_SECURITY_NUM_LEVELS                                          0u
/*! Size of table Dcm_CfgStatePreconditions */
# define DCM_CFGSTATEPRECONDITIONS_SIZE                                         7u
/*! Size of table Dcm_CfgStateSessionInfo */
# define DCM_CFGSTATESESSIONINFO_SIZE                                           4u
/*! Size of table Dcm_CfgStateSessionNotificationInfo */
# define DCM_CFGSTATESESSIONNOTIFICATIONINFO_SIZE                               2u
/*!  ----- Symbolic name values for Session -----  */
# define DcmConf_DcmDspSessionRow_Default                                       1u
# define DcmConf_DcmDspSessionRow_Programming                                   2u
# define DcmConf_DcmDspSessionRow_Extended                                      3u
# define DcmConf_DcmDspSessionRow_Development                                  126u
/*! Number of DID ranges */
# define DCM_NUM_DID_RANGES                                                     0u
/*! Read paged data page buffer size */
# define DCM_DIDMGR_READ_PAGE_SIZE                                                    7u
/*! Total number of DynDID items */
# define DCM_NUM_DYNDID_ITEMS                                                     0u
/*! Number of dynamically defined DIDs */
# define DCM_NUM_DYNDIDS                                                          0u
/*! Number of IO control DIDs */
# define DCM_NUM_IODIDS                                                           0u
/*! Maximum size of an IO control DIDs CEMR to be passed to the application */
# define DCM_DIDMGR_IODID_MAX_EXT_CEMR_SIZE                                       1u
/*! Size of table Dcm_CfgDidMgrDidLookUpTable */
# define DCM_CFGDIDMGRDIDLOOKUPTABLE_SIZE                                      94u
/*! Size of table Dcm_CfgDidMgrDidRanges */
# define DCM_CFGDIDMGRDIDRANGES_SIZE                                            1u
/*! Size of table Dcm_CfgDidMgrRangeDidInfoRefs */
# define DCM_CFGDIDMGRRANGEDIDINFOREFS_SIZE                                     1u
/*! Size of table Dcm_CfgDidMgrDidInfo */
# define DCM_CFGDIDMGRDIDINFO_SIZE                                             93u
/*! Size of table Dcm_CfgDidMgrDidOpInfo */
# define DCM_CFGDIDMGRDIDOPINFO_SIZE                                           118u
/*! Size of table Dcm_CfgDidMgrDidOpClassInfo */
# define DCM_CFGDIDMGRDIDOPCLASSINFO_SIZE                                      240u
/*! Size of table Dcm_CfgDidMgrSignalOpClassInfo */
# define DCM_CFGDIDMGRSIGNALOPCLASSINFO_SIZE                                    442u
/*! Invalid value for Routine Info Byte */
# define DCM_CFGRIDMGR_INVALID_ROUTINEINFOBYTE                                    0u
/*! Size of table Dcm_CfgRidMgrRidLookUpTable */
# define DCM_CFGRIDMGRRIDLOOKUPTABLE_SIZE                                      25u
/*! Size of table Dcm_CfgRidMgrRidInfo */
# define DCM_CFGRIDMGRRIDINFO_SIZE                                             24u
/*! Size of table Dcm_CfgRidMgrOpInfo */
# define DCM_CFGRIDMGROPINFO_SIZE                                              36u
/*! Specifies total number of supported memory operations */
# define DCM_MEMMGR_NUM_MEMORY_OPERATIONS                                       2u
/*! Specifies total number of memory ranges in single MID or no MID mode */
# define DCM_MEMMGR_MEMMAP_NUM_ENTRIES                                            2u
/*! Size of table Dcm_CfgMemMgrAlfidLookUpTable */
# define DCM_CFGMEMMGRALFIDLOOKUPTABLE_SIZE                                    17u
/*! Size of table Dcm_CfgMemMgrMidLookUpTable */
# define DCM_CFGMEMMGRMIDLOOKUPTABLE_SIZE                                       1u
/*! Size of table Dcm_CfgMemMgrMidInfo */
# define DCM_CFGMEMMGRMIDINFO_SIZE                                              1u
/*! Size of table Dcm_CfgMemMgrMemMap */
# define DCM_CFGMEMMGRMEMMAP_SIZE                                               2u
/*! Call out function for service 0x34 */
# define DCM_PROCESS_REQUEST_DOWNLOAD                                          Dcm_ProcessRequestDownload
/*! Call out function for service 0x36 */
# define DCM_PROCESS_TRANSFER_DATA_WRITE                                       Dcm_ProcessTransferDataWrite
/*! Call out function for service 0x37 */
# define DCM_PROCESS_REQUEST_TRANSFER_EXIT                                     Dcm_ProcessRequestTransferExit
/*! Configured main function period time */
# define DCM_TASK_CYCLE_MS                                                       10u
/*! Configured keep alive time */
# define DCM_NET_KEEP_ALIVE_TIME                                                  0u
/*! The total number threads */
# define DCM_NUM_THREADS                                                        1u
/*! Tester present timeout */
# define DCM_DIAG_TIME_S3                                                           500u
/*! Maximum number of RCR-RP response before processing interruption */
# define DCM_DIAG_RCRRP_LIMIT_COUNT                                            30u
/*! Specifies the NRC to be sent, once the maximum number of RCR-RP responses has been reached */
# define DCM_DIAG_CANCEL_OP_NRC                                                DCM_E_GENERALREJECT
/*! Specifies the reference to function that stops the repeater */
# define DCM_DIAG_SERVICEINFO_REPEATEREND_IDX                                  13u
/*! Size of table Dcm_CfgDiagSvcIdLookUpTable */
# define DCM_CFGDIAGSVCIDLOOKUPTABLE_SIZE                                      14u
/*! Size of table Dcm_CfgDiagSvcInitializers */
# define DCM_CFGDIAGSVCINITIALIZERS_SIZE                                        1u
/*! Size of table Dcm_CfgDiagServiceInfo */
# define DCM_CFGDIAGSERVICEINFO_SIZE                                           14u
/*! Size of table Dcm_CfgDiagSvcIdExecPrecondTable */
# define DCM_CFGDIAGSVCIDEXECPRECONDTABLE_SIZE                                 13u
/*! Size of table Dcm_CfgDiagSvcPostProcessors */
# define DCM_CFGDIAGSVCPOSTPROCESSORS_SIZE                                      8u
/*! Size of table Dcm_CfgDiagSvcUpdaters */
# define DCM_CFGDIAGSVCUPDATERS_SIZE                                            3u
/*! Size of table Dcm_CfgDiagSvcCancellers */
# define DCM_CFGDIAGSVCCANCELLERS_SIZE                                          6u
/*! Size of table Dcm_CfgDiagOemNotificationInfo */
# define DCM_CFGDIAGOEMNOTIFICATIONINFO_SIZE                                    4u
/*! Size of table Dcm_CfgDiagSysNotificationInfo */
# define DCM_CFGDIAGSYSNOTIFICATIONINFO_SIZE                                    1u
/*! Size of table Dcm_CfgDiagSvcId2ProtMap */
# define DCM_CFGDIAGSVCID2PROTMAP_SIZE                                         13u
/*! Total number of configuration variants */
# define DCM_VARMGR_NUM_CFG_VARIANTS                                              2u
/*! Release specific variant magic number */
# define DCM_CFG_FINAL_MAGIC_NUMBER                                            0x3530u
/*! Release specific generator compatibility number */
# define DCM_CFG_GEN_COMPATIBILITY_VERSION                                     0x1280u
/*! Maximum numbers of Dids which could be handled in parallel. */
# define DCM_RSRCMGR_DID_LOCK_LIST_SIZE                                         1u
/*! The deauthenticated role */
# define DCM_AUTHMGR_DEAUTHENTICATED_ROLE                                      0x00000000u
/*! Default session timeout for transition to deauthenticated state */
# define DCM_AUTHMGR_DEFAULT_SESSION_TIMEOUT                                      0u
/*! Overall max size of client/server challenge */
# define DCM_AUTHMGR_CHALLENGE_MAX_SIZE                                           0u
/*! Size of the role element in a certificate */
# define DCM_AUTHMGR_CERT_ROLE_SIZE                                             0u
/*! Specifies total number of supported DID white list elements */
# define DCM_AUTHMGR_NUM_DID_WL_ELEMENTS                                        0u
/*! Specifies total number of supported memory selection white list elements */
# define DCM_AUTHMGR_NUM_MEM_WL_ELEMENTS                                        0u
/*! Specifies total number of supported RID white list elements */
# define DCM_AUTHMGR_NUM_RID_WL_ELEMENTS                                        0u
/*! Specifies total number of supported service white list elements */
# define DCM_AUTHMGR_NUM_SERVICE_WL_ELEMENTS                                    0u
/*! Invalid white list KeyM element id */
# define DCM_AUTHMGR_INVALID_WL_KEYM_ELEMENT_ID                                65535u
/*! Invalid authentication info reference */
# define DCM_AUTHMGR_INVALID_AUTH_INFO_REF                                     0xFFu
/*! General NRC for authentication */
# define DCM_AUTHMGR_GENERAL_NRC                                               0x00u
/*! Size of table Dcm_CfgSvc10SubFuncLookUpTable */
# define DCM_CFGSVC10SUBFUNCLOOKUPTABLE_SIZE                                    5u
/*! Size of table Dcm_CfgSvc10SubFuncInfo */
# define DCM_CFGSVC10SUBFUNCINFO_SIZE                                           4u
/*! Size of table Dcm_CfgSvc10SubFuncExecPrecondTable */
# define DCM_CFGSVC10SUBFUNCEXECPRECONDTABLE_SIZE                               4u
/*! The ECU power down time */
# define DCM_SVC_11_POWERDOWNTIME                                              255u
/*! Size of table Dcm_CfgSvc11SubFuncLookUpTable */
# define DCM_CFGSVC11SUBFUNCLOOKUPTABLE_SIZE                                    5u
/*! Size of table Dcm_CfgSvc11SubFuncInfo */
# define DCM_CFGSVC11SUBFUNCINFO_SIZE                                           4u
/*! Size of table Dcm_CfgSvc11SubFuncExecPrecondTable */
# define DCM_CFGSVC11SUBFUNCEXECPRECONDTABLE_SIZE                               4u
/*! Specifies the user memory identifier to be accepted */
# define DCM_SVC_14_USER_MEM_ID                                                0x00u
/*! Reference to the Dcm_CfgStatePreconditions[] entry */
# define DCM_SVC_14_USERMEM_ID_PRECON_REF                                             0u
/*! Specifies the user memory identifier to be accepted */
# define DCM_SVC_19_USER_MEM_ID                                                0x00u
/*! Reference to the Dcm_CfgStatePreconditions[] entry */
# define DCM_SVC_19_USERMEM_ID_PRECON_REF                                             0u
/*! Size of table Dcm_CfgSvc19SubFuncLookUpTable */
# define DCM_CFGSVC19SUBFUNCLOOKUPTABLE_SIZE                                    7u
/*! Size of table Dcm_CfgSvc19SubFuncInfo */
# define DCM_CFGSVC19SUBFUNCINFO_SIZE                                           6u
/*! Size of table Dcm_CfgSvc19SubFuncExecPrecondTable */
# define DCM_CFGSVC19SUBFUNCEXECPRECONDTABLE_SIZE                               6u
/*! Specifies the maximum number of DIDs per single request service 0x22 */
# define DCM_SVC_22_MAX_DID_LIST_LEN                                            1u
/*! The total number of failed attempt counter monitors */
# define DCM_SVC_27_NUM_ATTEMPT_COUNTERS                                        0u
/*! The total number of failed attempt timers */
# define DCM_SVC_27_NUM_DELAY_TIMERS                                            0u
/*! Size of table Dcm_CfgSvc28SubFuncLookUpTable */
# define DCM_CFGSVC28SUBFUNCLOOKUPTABLE_SIZE                                    3u
/*! Size of table Dcm_CfgSvc28SubFuncInfo */
# define DCM_CFGSVC28SUBFUNCINFO_SIZE                                           2u
/*! Size of table Dcm_CfgSvc28SubFuncExecPrecondTable */
# define DCM_CFGSVC28SUBFUNCEXECPRECONDTABLE_SIZE                               2u
/*! Size of table Dcm_CfgSvc28MessageTypeLookUpTable */
# define DCM_CFGSVC28MESSAGETYPELOOKUPTABLE_SIZE                                4u
/*! Size of table Dcm_CfgSvc28SubNetIdLookUp */
# define DCM_CFGSVC28SUBNETIDLOOKUP_SIZE                                        3u
/*! Size of table Dcm_CfgSvc28SubNetIdMap */
# define DCM_CFGSVC28SUBNETIDMAP_SIZE                                           2u
/*! Specifies the buffers size needed for data extraction of a DDDID source item */
# define DCM_SVC_2C_READ_BUFFER_SIZE                                              0u
/*! Buffer size for the routine parameter integrity */
# define DCM_SVC_31_INTEGRITY_BUFFER_SIZE                                         1u
/*! Size of table Dcm_CfgSvc3ESubFuncLookUpTable */
# define DCM_CFGSVC3ESUBFUNCLOOKUPTABLE_SIZE                                    2u
/*! Size of table Dcm_CfgSvc3ESubFuncExecPrecondTable */
# define DCM_CFGSVC3ESUBFUNCEXECPRECONDTABLE_SIZE                               1u
/*! Specifies the total request length for service 0x85 */
# define DCM_SVC_85_REQ_LENGTH                                                  1u
/*! Size of table Dcm_CfgSvc85SubFuncLookUpTable */
# define DCM_CFGSVC85SUBFUNCLOOKUPTABLE_SIZE                                    3u
/*! Size of table Dcm_CfgSvc85SubFuncExecPrecondTable */
# define DCM_CFGSVC85SUBFUNCEXECPRECONDTABLE_SIZE                               2u
/*! Size of table Dcm_CfgSvc85SubFuncInfo */
# define DCM_CFGSVC85SUBFUNCINFO_SIZE                                           2u
/**********************************************************************************************************************
 *  User configuration file content
 *********************************************************************************************************************/
/* User Config File Start */
/* Workaround S3 timer */
#ifdef DCM_DIAG_TIME_S3
#undef DCM_DIAG_TIME_S3
#define DCM_DIAG_TIME_S3 1900 //in ticks (multiple of Dcm/DcmConfigSet/DcmGeneral/DcmTaskTime)
#endif
/* User Config File End */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION DECLARATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA DECLARATIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#endif /* !defined(DCM_CFG_H) */

/**********************************************************************************************************************
 *  END OF FILE: Dcm_Cfg.h
 *********************************************************************************************************************/

