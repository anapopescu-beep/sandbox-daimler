/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Ssa.h
 *    Component:  Security_AsrSwcSsa_Daimler
 *       Module:  Ssa
 *    Generator:  -
 *
 *  Description:  Header of the Standard Security Architecture
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author   Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2016-09-09  vismpf                 Initial creation
 *                        visrpp                 Initial creation
 *                        visewl                 Initial creation
 *  01.01.00  2017-03-01  visewl   ESCAN00093671 Wrong local tick-count after executing SecOC ECU Shared Secret
 *                                               Distribution
 *                                 ESCAN00093678 SecOC freshness based verification fails for local tick-counts greater
 *                                               than 0xFFFFFFFF
 *  01.01.00  2017-03-01  visewl   ESCAN00093711 Distribution of an invalid shared secret
 *                                 ESCAN00094023 Compiler Error: E_PENDING undeclared identifier
 *                                 ESCAN00094217 Incorrect logging of Signature Verification Events
 *                                 ESCAN00094327 Failed SecOC MAC verification events might not be logged
 *            2017-03-31  visewl   ESCAN00094719 NVM access causing DET error
 *                        visewl   ESCAN00094722 Secure Coding Sequence returns NRC0x10 when DET checks are enabled
 *            2017-04-11  visewl   ESCAN00094094 Broadcast messages (e.g. TickCount of VSM) might be sent over an
 *                                               unexpected amount of frames
 *                                 ESCAN00094325 Loss of RTC value causes wrong local tick-count
 *                                 ESCAN00094388 Static variable TimeM_PreviousIgnitionState not initialized and never
 *                                               assigned a value to.
 *            2017-04-11  visewl   FEATC-1141    Update to Daimler Security Architecture Specification 1.2
 *                                               - Added runnable for verifying stored certificates
 *                                               - Added callouts to application for storing key data permanently
 *                                               - Before replacing any certificate verify stored certificates
 *                                               - Changed key agreement protocol: Generation of symmetric session keys
 *                                                 now based on ephemeral private/public key pair.
 *                                               - Added verification of SubjectKeyIdentifier before encryption of
 *                                                 shared car-specific secret.
 *                                               - Initialize (pseudo) random number generator by the car-specific
 *                                                 secret
 *                                               - Verification of SpecialECU value
 *                                               - Tick-count synchronization status
 *                                               - Using Data Id instead of freshness value Id of Verification Status
 *                                               - Routine Service Reset VIN added
 *                                               - ReadData service SSA Version Information added
 *                                               - Removed redundant code
 *                                               - Revised the NULL_PTR checks and the calls of the new log entry
 *                                                 notification
 *                                               - Discard return values of function used for marking the RAM blocks as
 *                                                 changed
 *                                               - Added support of RoE-Lite notification
 *                                               - Adding external RAM mirror for writing RAM block to NV memory
 *                                               - Adaption of output of security event log to latest requirements
 *                                               - Static variable RightsM_NonceValidTime not initialized.
 *                                               - Make sure that DiagnosticAuthentication_Issuer and Serial Data are
 *                                                 always readable (not only in authenticated state)
 *                                               - Added support of DynamicallyDefineDataIdentifier service
 *                                               - Support of TargetSubjectKeyIdentifier
 *                                               - Storing nonce together with timestamp and validity info in NVM.
 *                                               - Content of authentication broadcast message adapted.
 *                                               - TargetSubjectKeyIdentifier is optional
 *                                               - Code optimizations
 *                                               - Check "SpecialECU" field in consideration of the requested use case
 *                                               - New element TargetSubjectKeyIdentifier added
 *                                               - New OID for AlgorithmIdentifier
 *                                               - Ignore 'Validity - not after' field when comparing link certificates
 *                                               - Maintaining the VSM local tick-count: Compensation for the loss of
 *                                                 the RTC value
 *                                               - Tick-count synchronization status
 *                                               - Call out for setting the RTC to new tick-count
 *  01.01.01  2017-04-24  visewl   ESCAN00094845 Compiler Error: Non-constant aggregate initializer was used
 *                                 ESCAN00094846 Compiler Error: Variable was not declared after brace
 *  01.02.00  2017-04-26  visewl   ESCAN00094925 Reception of secured tick-count messages fails
 *            2017-04-27  visewl   ESCAN00094940 SecOC freshness based verification fails for local tick-counts smaller
 *                                               than 128
 *                                 ESCAN00094953 Unclear and missing parameters for SecOC related security log events
 *            2017-04-28  visewl   ESCAN00094957 Increased size of all log entries' timestamps to 5 bytes
 *  01.02.01  2017-06-07  visewl   ESCAN00095002 Compiler error: Missing section definitions
 *                                 ESCAN00095105 Compiler error: Redefinition of formal parameter 'task'
 *                                 ESCAN00095167 Code contains C99 comments
 *                                 ESCAN00095188 All diagnostic services are rejected through check of access rights
 *                                               (non-aligned access error)
 *                                 ESCAN00095242 An aborting Secure Coding Sequence fails when DET checks are enabled
 *                                 ESCAN00095346 Diagnostic services with access rights granted by the ECU-individual
 *                                               ACL are rejected by check of access rights
 *                                 ESCAN00095359 Compiler error: SecLog: Non constant as initializer
 *                                 ESCAN00095360 Compiler error: RightsM: Undeclared identifier
 *                                 STORYC-1379   Adding element TargetSubjectKeyIdentifier
 *                                 STORYC-1380   Adding Operation SPduTxConfirmation to interface FreshnessManagement
 *                                 STORYC-1381   After start-up a change of the local tick-count by the received secured
 *                                               time message to future shall not be logged
 *                                 STORYC-1382   Pass-through/delegate of interface for reading out local tick-count
 *                                 STORYC-1383   Always clear shared secret from RAM
 *                                 STORYC-1385   Masking ignition cycle  when checking for MAX_IGNITION_CYCLES
 *                                 STORYC-1386   Abort coding sequence if VIN is changed after coding sequence has
 *                                               started
 *                                 STORYC-1415   Certificate parsing: Change from PrintableString to UTF8String
 *            2017-06-07  visewl   STORYC-1377   Resolve misuse of IRV access macros in SecLog and Coding
 *                                 STORYC-1387   Change CodingFlag to VINStatus
 *            2017-06-23  visewl   ESCAN00094815 Port connector connects incompatible port prototypes: Ssa.IgnitionStatus
 *                                 ESCAN00095616 Generation error -- Invalid or missing ModeRequestTypeMap for mode
 *                                 ESCAN00095605 Compiler error: Using structure elements RightsM that are not generated
 *                                 ESCAN00095606 Compiler error: Incompatible declarations for generated runnables
 *            2017-07-03  visewl   STORYC-1372   Variant Coding: Checking for SCN-Service before signature calculation
 *                                               and for normal 2E-Service after SCN-Service
 *                                 STORYC-1378   Restricted Authentication
 *                                 STORYC-1384   Dummy log entry (all zeroes) in all ring-buffers if local-tickcount is set
 *                                 STORYC-1388   Handling of parallel coding sequences - First Step block access from
 *                                               different channels
 *                                 STORYC-1389   Adaption of port and element names to Daimler specific naming
 *                                 STORYC-1674   Change MainFunction cycle from 1ms to 10ms
 *                                 STORYC-1683   The SSA shall not support a DiagnosticUserRole with ID 0x00
 *                                 STORYC-1733   Invalid SHORT-LABEL for COMPU-SCALE in several COMPU-METHODs
 *                                 ESCAN00095710 Compiler error: Identifier "Csm_VerifyResultType" is undefined
 *                                 ESCAN00095711 Incompatible interfaces with SecOC
 *                                 ESCAN00095719 SSA port cannot be connected to the corresponding Dem service port
 *                                 ESCAN00095721 Compiler error: Undeclared identifier
 *                                               RTE_MODE_DcmDiagnosticSessionControl_DefaultSession
 *            2017-07-03  visewl   STORYC-1742   New ReadData Service SecOC Local TickCount
 *  01.02.02  2017-08-28  visewl   ESCAN00095831 Compiler error: Static function Coding_MarkReceived() declared but not
 *                                               defined
 *                                 ESCAN00095884 Compiler error: Unresolved function
 *                                               Rte_Write_Ssa_SecLog_SecLog_EventNotification_Data
 *                                 ESCAN00096223 Variant Coding returns DCM_E_REQUESTSEQUENCEERROR when request writing
 *                                               of a coding relevant did
 *                                 ESCAN00096429 InputOutputControlByIdentifier diagnostic service is always rejected
 *                                 ESCAN00096432 Authentication fails on VSM
 *                                 ESCAN00096435 Incorrect VIN status notification after VIN has changed
 *  01.03.00  2017-09-29  visewl   STORYC-2301   Ssa Release: Preparation of TimeM
 *                                 STORYC-2306   Ssa Release: Preparation of RightsM
 *            2017-10-27  visewl   STORYC-2304   Ssa Release: Preparation of KeyM
 *                                 STORYC-2305   Ssa Release: Preparation of Coding
 *                                 STORYC-2307   Ssa Release: Preparation of Cdd
 *                                 STORYC-2129   Adapt implementation to Specification 1.3
 *                                               Ssa Release: Preparation of BcTp
 *            2017-11-06  visewl   STORYC-2302   Ssa Release: Preparation of SecLog
 *                                 ESCAN00097397 DET error from Fls due to wrong Ram Buffer addresses.
 *            2017-11-10  visewl   STORYC-2303   Ssa Release: Preparation of CertP
 *                                 ESCAN00096608 UUID's of constants not unique
 *                                 ESCAN00097352 RTE Error due to active Transformer Error Handling
 *            2017-11-24  visewl   ESCAN00096737 Wrong folders within CC_FILES_TO_BUILD list of Ssa_rules.mak
 *            2017-11-28  visewl   ESCAN00097585 Routine replace certificate invalidates the stored certificate
 *            2017-11-30  visewl   ESCAN00097640 Routines reading the shared secret might return with error code
 *                                               "general reject"
 *            2017-11-30  visewl   ESCAN00098042 Invalid Size in Bytes of the Security Event Log for the service 0x0187
 *  01.04.00  2018-01-19  visewl   ESCAN00098041 Security Log reporting of "authentication status" information incorrect
 *            2018-01-19  visewl   ESCAN00098055 Variant coding data won't become invalid when VIN is changed from
 *                                               default VIN to Non-Default VIN
 *            2018-01-19  visewl   ESCAN00098064 Service DID_018B_SecOcDataID is missing
 *            2018-01-24  visewl   ESCAN00098128 Ephemeral public key for generation of symmetric session key remains on
 *                                               init value
 *            2018-01-31  visewl   STORYC-3119   Asynchronous Csm Usage for Signature Generation and Verification
 *  01.04.01  2018-04-12  visewl   STORYC-4266   Asynchronous handling for Daimler SSA Routine Controls to relieve Dcm
 *                                               main function
 *                                 STORYC-4394   Do not extract identifiers in case of OBD services any more
 *                                 STORYC-4397   No verification of stored certificates any more
 *                                 STORYC-4729   Using mirror RAM block for data service security event log read
 *                                 ESCAN00098495 Ssa_TimeM_SecOC_FvM_SPduTxConfirmation has no return values any more
 *                                 ESCAN00098496 Prevent infinite loop after ReadDataByIdentifier service with incorrect
 *                                               length
 *                                 ESCAN00098497 Removed error code definitions from preprocessor directives
 *                                 ESCAN00098534 Changed VIN sending cycle so that it is transmitted exactly once per
 *                                               second
 *                                 ESCAN00098634 Only one broadcast message per second is sent if there more than one
 *                                               locally authenticated users
 *                                 ESCAN00098667 Maximum size of certificates changed to 910 bytes
 *                                 ESCAN00098767 The NvM control link services now returns E_OK if no coding blocks exist
 *                                 ESCAN00098787 Changed security level notified to application and written to security
 *                                               log
 *                                 ESCAN00098998 Added handling of CODING_WRITEDATA_STATE_WRITEBYDID_OR_CALID
 *                                 ESCAN00099095 Assigning value to KeyM_SignatureOutLength before using it
 *                                 ESCAN00099097 Added missing state transition to KEYM_GEN_SIG_STATE_IDLE
 *                                 ESCAN00099099 Resolved missing exit of KeyM exclusive area
 *                                 ESCAN00099100 The CSM callback functions does not return any value any more
 *                                 ESCAN00099101 Replaced Csm_VerifyResultType by Crypto_VerifyResultType
 *                                 STORYC-4970   Extend asynchronous calls by KeyExchange and Random
 *                                 STORYC-4971   Splitting of Key Generation to a defined amount of keys
 *                                 ESCAN00099164 Set symmetric SecOc keys valid after all relevant key elements are set
 *                                 ESCAN00099207 Added module Ssa_ProcCtrl
 *                                 ESCAN00099496 Reject authentication broadcast message with invalid user roles
 *                                 ESCAN00099497 Diagnostic user remains authenticated after detection of a soft reset
 *                                 STORYC-5768   Allow re-direction of Ssa_MemCpy
 *  01.04.02  2018-06-14  visewl   STORYC-5003   Release of component
 *                                 STORYC-5700   Restricted NVM write block calls associated with TimeM broadcast events
 *                                               to once per ignition cycle
 *                                 STORYC-5733   Configurable usage of the ProcCtrl buffer handling
 *                                 STORYC-5855   Support HW AES decryption
 *                                 STORYC-5866   Updated basic access control list to version 18.17.02
 *                                 STORYC-5867   Added TimeM mode switch port for controlling operation of main function.
 *                                 ESCAN00099503 Detection of RAM content only after diagnostic service request for a
 *                                               soft reset
 *                                 ESCAN00099576 Correction of operation status usage in ProcCtrl buffer state machine
 *                                 ESCAN00099792 Setting correct output data length for routine Authenticate Diagnostic
 *                                               User or Tester
 *                                 ESCAN00099952 SecLog_DecFailedMacCounterForDTC now returns FALSE by default
 *                                 ESCAN00099955 Ssa_TimeM_SecOC_FvM_SPduTxConfirmation always returns RTE_E_OK
 *                                 ESCAN00100021 Fixed logging of EraseMemory and Enable SAR Memory Overwrite events
 * 01.04.03  2019-01-07  visewl    ESCAN00100697 Blind out the suppressPositiveResponse bit when evaluating the
 *                                               diagnostic session type
 *                                 ESCAN00100833 Not re-starting the "logging active timer" when a positive verification
 *                                               result in signalled
 *                                 ESCAN00101368 Also accepting broadcasted car-specific shared secret in authentication
 *                                               state "supplier" and "development enhanced"
 *                                 STORYC-7370   No verification of Subject Key Identifier in routine "SecOC ECU TickCount
 *                                               Synchronization"
 *                                 STORYC-7369   Clearing DTC 0xD12083 and resetting the FailedMacVerification counters
 *                                               within each ignition cycle
 *                                 STORYC-7368   Updated basic access control list to version 18.43.01
 *                                 STORYC-7367   Storing tick-count RAM block to NVM whenever the real-time offset is
 *                                               stored to NVM
 *                                               Always storing Coding VIN RAM block to NVM after being changed
 *                                               Ensuring data consistency storing SecLog NVRAM blocks to NVM
 * 01.05.00  2019-03-25  visewl    STORYC-7877   Safe BcTp and FvM
 *                                 STORYC-7878   Merged asynchronous Ssa v1.4.4 and synchronous Ssa v1.3.7
 *                                 STORYC-8061   Allowing more than 99 Coding DIDs
 *                                 STORYC-8068   Changed ProcCtrl buffer handling for security log ReadDataById services
 *                                 STORYC-8580   Optimize access to enhanced access rights table
 *           2019-04-11  visewl    ESCAN00101841 Clear enhanced access rights after successful authentication
 *                                 ESCAN00101859 Fixed logging of rights management events for unauthenticated users
 *                                 ESCAN00102369 Fixed handling of current diagnostic channel identifier in Coding module
 *                                               for enabling the restart of the variant coding sequence
 *                                 ESCAN00102742 Returning correct verification result if central auth. broadcast started
 *                                 ESCAN00102817 Fixed state machine handling for asynchronous signature verification in
 *                                               KeyM module
 *                                 ESCAN00102832 Fixed state machine handling for asynchronous signature verification in
 *                                               Coding module
 *                                 ESCAN00102845 Fixed state machine handling for asynchronous generation of shared secret
 *                                               in KeyM module
 *           2019-06-17  visewl    ESCAN00103402 Reset counter for numbers of generated keys in error case
 *                                 ESCAN00103461 Corrected direction of time change for security log written in TimeM
 *                                 ESCAN00103462 Comparing also month element of received and stored real-time offset
 * 02.00.00  2019-10-01  visewl    ESCAN00103828 Fixed comparison of certificate's serial numbers
 *                                 ESCAN00103832 Adapt minimum length for routine control service response messages
 *                                 ESCAN00104177 Resolved unknown verification result for failed authentication
 *                                 ESCAN00104178 Also checking issuer field of Backend Ca link certificate
 *                                 ESCAN00104313 Fixed logging of failed and successful certificate verification events
 *                                 SEC-680       Extend VIN Handling and Variant Coding
 *                                 SEC-683       Storing RightsM nonce immediately
 *                                 SEC-686       Configurable cycle times for sending secured tick-count and IF for
 *                                               pre-open signal
 *                                 SEC-841       Using binary search for ACL table accesses
 *           2020-24-01  visewl    SEC-752       Make sizes of SecLog circular buffers individually configurable
 *           2020-02-04  visewl    SEC-896       Revised misconfiguration event
 *           2020-03-26  visewl    SEC-681       Adapt logging of failed PDU MAC verification events
 *                                 SEC-682       Add mechanism for detection of brute force attacks against CMAC
 *                                 SEC-684       Extend seeding of RNG by a nonce requested by a callout function
 *                                 SEC-685       Splitting up of SecLog NVM block
 *                                 SEC-844       RTO broadcast by gateway ECU
 *                                 SEC-848       RoutineControl Certificate Self Check
 *                                 SEC-853       New diagnostic services for reading VIN Status, VIN Lock Status and
 *                                               Real-Time Offset
 *                                 SEC-856       Revise setting DTC 0xD12087
 *           2020-04-06  visewl    ESCAN00103831 Not de-authenticating any user if one user has requested default session
 *                                 ESCAN00104816 Changed calculation of percental potion of tick-count to be turned back
 *                                 ESCAN00104965 Setting correct length of Authenticate routine response message
 *                                 ESCAN00105107 Start sending the secured time messages with short cycle time
 *                                               immediately after being requested
 *                                 ESCAN00105187 Logging diagnostic channel extracted from authentication broadcast
 *                                 ESCAN00105188 Corrected direction of time change in Ssa_TimeM_TimeRawData_Set()
 *                                 ESCAN00105490 Prevent endless loop by using iter type for counter variable
 *                                 ESCAN00105836 Removed pointer like data types of operation prototypes of C/S port
 *                                               interfaces CertP_Functions and KeyM_Certificate
 * 02.00.03  2020-05-12  vismwe    SEC-847       ReadDataByIdentifier SecOC PDU Data-IDs and Key CMACs
 *                                 SEC-850       Revise authentication state processing conc. soft reset and timeout
 *                                 SEC-1487      Logging of difference of old and new value of the real-time.
 *                       visrpp    SEC-688       Additional NRCs when checking access rights of diagnostic services
 *                       visewl    ESCAN00106429 Resolved compile error caused by using PIM access macros as init values
 *                                 ESCAN00106430 Resolved compile error caused by using SecLog_SecOcVerificationStateType
 *                                 ESCAN00106432 Corrected invalidation of nonce used for authentication.
 *                                 ESCAN00106435 Corrected processing of certificate's serial number during authentication
 *                                 ESCAN00106436 Adapted result handling of enhance access rights service
 *                                 ESCAN00106437 Adapted state handling of enhance access rights service
 *                                 ESCAN00100544 Respond with NRC IncorrectMessageLengthOrInvalidFormat if required
 *                                 ESCAN00104116 Check diagnostic routine control service requests for minimum length
 *                                 ESCAN00106527 Setting DTC 0xD164456 in case of a VIN broadcast timeout
 *                                 ESCAN00106534 Process return code of Rte_Call_Ssa_KeyStorage_StorePermanently
 * 03.00.00  2020-08-28  visewl    SEC-1743      Unique ECU ID chain process
 *                                 SEC-1777      Distribution of car-specific secret based on Unique ECU ID chain
 * 03.00.01  2020-10-23  visewl    ESCAN00107680 Adding null pointer and length check to Coding Notification_Indication
 *           2020-11-19  visknb    SEC-2023      ReadDataByIdentifier DID 0197 Status SSA Pre-Compile Switches
 *           2020-11-26  visknb    SEC-2021      ReadDataByIdentifier RandomNumber (DID 0x191)
 *           2020-12-01  visewl    SEC-2025      Replace of Trust Model Root CA certificate
 *           2020-12-12  visknb    SEC-2060      Additional Diagnostic Read and Write Data Services
 *           2020-12-21  visewl    SEC-2124      Revise CSR and Replace TM Certificates routines
 *           2021-01-07  visknb    SEC-2062      Processing mileage information and production rights
 *           2021-01-14  visewl    ESCAN00108295 Providing correct SecLog global event counter values by diag. services
 *           2021-01-14  vismwe    SEC-2061      Revise replacement of certificates (Diagnostic Chain)
 *           2021-01-14  visewl    ESCAN00108833 Enhance certificate verification
 * 03.00.02  2021-02-21  visewl    SEC-2064      Revise diagnostic services for commissioning
 *           2021-02-17  visewl    ESCAN00108608 Setting car-specific shared secret after generating it
 *           2021-02-24  visknb    SEC-2125      Revise RoutineControl Certificate Self Check - Diagnostic chain and
 *                                               Unique ECU Id chain
 *           2021-02-24  visknb    SEC-2063      COM signal timeout for reception of VIN broadcast message
 *           2021-02-24  visknb    SEC-2356      Enable static seed for security access, revised logging of NRCs
 *           2021-03-05  visewl    SEC-2168      Using service ports of AsrKeyM
 *           2021-03-05  visewl    SEC-2354      Adding extensions of CSR body
 *           2021-03-12  visknb    ESCAN00107827 Storing new tick-count set by SecOC_ECU_Shared_Secret_Distribution
 *                       visknb    ESCAN00108723 Accepting secured tick-count messages just below threshold
 *           2021-03-23  visewl    SEC-2523      Adapted power management S/R interface
 *           2021-03-26  visewl    SEC-2278      New NRC DCM_E_AUTHENTICATIONREQUIRED, revised verification results
 *           2011-03-30  visknb    SEC-2527      Introduced consistency checks when setting real-time or tick-count
 * 03.00.03  2021-06-28  visewl    SEC-2360      Add routine service Inject Seed
 *           2021-07-16  vikasnl   SEC-2932      Add routine service Trust Model Generate Key Pair
 *           2021-07-26  visewl    SEC-2975      Add routine service Status of Post Production Flag, adapt Odo S/R IF
 *           2021-07-28  vismwe    SEC-3039      Add RoutineControl Get Certificate Entry (RID 0x027D)
 *           2021-08-04  visewl    SEC-2058      Support diagnostic service 0x29 by external service processing
 *           2021-08-11  vismwe    ESCAN00109345 Correction of writing separator log entry into SecLog's circular buffers
 *           2021-08-13  visewl    SEC-3125      Accept secured tick-count in case of equality to the allowed difference
 *           2021-08-13  visewl    SEC-3128      Restrict supported DID list length for diagnostic read services
 *           2021-08-16  vismwe    ESCAN00109483 SelfCheck might fail with verification result 
 *                                               "certificate is not accessible or invalid"
 *           2021-08-17  visewl    ESCAN00109040 Fixed InitMonitorForEvent handling of DTC 0x164456
 *           2021-08-17  visewl    ESCAN00109041 Corrected positive/negative response handling of routine Verify_Signature
 *           2021-08-17  visewl    ESCAN00109456 Adopt CurrentVIN as CodingVIN after successful Variant Coding
 *           2021-08-17  vismwe    ESCAN00109989 Correct parsing of AsrKeyM certificates
 *           2021-08-17  vikasnl   ESCAN00109609 Correct state handling for diagnostic service RID 0x0279
 * 03.01.00  2021-12-17  viseag    SEC-3563      Resolve MISRA metric violations and optimize: TimeM, CertP, ProcCtrl
 *                                 SEC-3565      Resolve MISRA metric violations and optimize: RightsM
 *           2022-01-18  vismwe    ESCAN00110254 Signature verification during Variant Coding is logged with wrong ID
 *           2022-01-21  visknb    ESCAN00110459 Diagnostic routine 'Get Certificate Entry' shall positively return 
 *                                               with verification result ENTRY_IN_CERTIFICATE_NOT_AVAILABLE.
 *                                 ESCAN00110457 Diagnostic routine 'Get Certificate Entry' returns correctly 
 *                                               for empty entries.
 *           2022-01-26  visknb    ESCAN00110616 Handling of invalid certificates in DID 019F 'Trust model certificates'
 *           2022-02-04  viseag    SEC-3961      Revise error handling of $29 handler
 *           2022-02-07  visewl    ESCAN00110461 Checking ECU certificate's special ECU field during service RID 0x0279
 *           2022-02-07  vismwe    ESCAN00110258 Undefined behaviour while logging a successful certificate verification
 *                                               event
 *           2022-02-11  visewl    ESCAN00110521 Changed expected NVRAM block status in TimeM if restored to default
 *           2022-02-14  visewl    SEC-3953      Add diagnostic service 'Trust Model Root Replacement Key' (DID 0x0198)
 *                       visewl    SEC-3955      Add interface for VeDoc relevant information
 *           2022-02-16  visewl    ESCAN00111294 Correct BusOdometer RTE read access
 *           2022-02-16  viseag    SEC-3992      Preparation for DET Checks
 *                                 SEC-4025      DET Checks for Coding, TimeM, RightsM, Cdd, FvM, CertP
 *                                 ESCAN00111239 Correct pre-compile switch dependent CSM primitve call state handling
 *           2022-02-17  viseag    SEC-3794      VCA-based silent analyis: Utils
 *           2022-02-21  viseag    ESCAN00111340 Remove NULL_PTR access during TimeM initialization
 *           2022-02-22  visewl    ESCAN00111234 Add AsrKeyM callback notifications for each Trust Model certificate
 *           2022-02-22  vismwe    SEC-3957      Generate Trust Model Key Pair on temporary key slots
 *           2022-02-23  visewl    ESCAN00110462 Provide info whether Trust Model chain is injected by DID 0x0197
 *                       visewl    SEC-3959      Inhibit usage of dummy or outdated Trust Model chain certificates
 *           2022-02-24  viseag    SEC-4068      VCA-based silent analyis: Coding
 *                                 SEC-4078      VCA-based silent analyis: SecLog
 *           2022-02-25  viseag    SEC-4080      VCA-based silent analyis: TimeM
 *           2022-02-28  visknb    ESCAN00111116 Add missing Trust Model certificate verification steps
 *           2022-03-01  visewl    ESCAN00110464 Clear DTC 0x164456 during module init if CurrentVIN equals CodingVIN
 *                                 ESCAN00111176 Coding routine control services return with verification failure
 *                                               if synchronization from resp. to NVM fails
 *                                 ESCAN00111392 Log successful diagnostic service execution events UID 0x0F
 *                                 SEC-3963      Log successful diagnostic service execution events UID 0x10 and 0x11
 *           2022-03-03  visewl    ESCAN00111175 Log of Trust Model certificate verification events
 *           2022-03-07  visewl    ESCAN00111403 Correct buffer size passed to RTE for C/S call
 *           2022-03-09  visewl    SEC-4251      Update verification results of diagnostic services to CDDT
 *                       viseag    SEC-4070      VCA-based silent analyis: FvM
 *                       viseag    SEC-4064      VCA-based silent analyis: Cdd
 *           2022-03-16  viseag    SEC-3568      Resolve MISRA metric violations and optimize: SecLog
 *           2022-03-17  visknb    SEC-4029      Add DET Checks: ProcCtrl, KeyM
 *           2022-03-23  viseag    SEC-4039      Resolve MISRA metric violations and optimize: Coding
 *           2022-04-05  viseag    SEC-4062      VCA-based silent analyis: BcTp
 *           2022-04-06  visknb    SEC-4074      VCA-based silent analyis: ProcCtrl
 *           2022-04-13  viseag    SEC-4066      VCA-based silent analyis: CertP
 *           2022-05-06  visknb    ESCAN00111793 Subfunction processing during Authentication service $29
 *           2022-05-09  rstemmler SEC-4493      Support access rights evaluation for service 0x38
 *           2022-05-10  viseag    SEC-4435      VCA-based silent analyis: KeyM
 *           2022-05-11  visknb    SEC-3561      Resolve MISRA metric violations and optimize: KeyM
 *           2022-05-17  visewl    SEC-4479      Set CAL parameters to not accessible
 *           2022-05-17  visewl    SEC-4517      Prevent only preplaced Trust Model chain of trust from being used
 *           2022-05-17  visewl    SEC-4525      Enhance busy handling during SecOC key derivation
 *           2022-05-18  rstemmler SEC-4523      Routine services GetCertificateEntry provides public key w/ 32 bytes
 *           2022-05-18  viseag    ESCAN00111914 Corrected buffer length and added length check for comparison
 *                                               of unique ECU IDs
 *           2022-06-03  visknb    ESCAN00112016 Corrected availability check for certificates in service 0x0199
 *           2022-06-07  visewl    ESCAN00111928 Corrected RTE buffer for truncated MAC generation result
 *           2022-06-15  visewl    ESCAN00112091 Store MAC Verifications Threshold Exceeded Counters to NVM
 *           2022-06-23  visewl    SEC-4670      Extend CSM primitive calls via Ssa_Cdd and using data references in 
 *                                               port interfaces
 *           2022-06-28  visewl    ESCAN00112196 Security log might be read with a wrong signature
 * 03.01.01  2022-07-14  viseag    SEC-4249      Review and rework of VCA based silent analysis
 *           2022-07-25  visewl    ESCAN00112324 Resolve compile error: undeclared identifier
 *           2022-08-12  viseag    ESCAN00112445 Log failed instead of successful verification event if certificate
 *                                               verification failed and if an asynchronous Csm job is used
 *           2022-09-08  viseag    ESCAN00112609 Increment counter for PKI-related and authentication-related
 *                                               failed certificate verifications for missing PKI roles.
 *           2022-09-28  visknb    ESCAN00112729 Certificate verification during diagnostic routine control service
 *                                               execution deviates from specification
 *                                 ESCAN00112671 SelfCheck returns positive verification result before all checks 
 *                                               have been performed
 *           2022-09-29  visknb    ESCAN00112262 Correction of setting DTC 0xD12087
 * 03.02.00  2022-10-28  viseag    ESCAN00113095 Correction of DER encoding of unique ECU IDs
 *           2022-11-14  viseag    SEC-5313      Code optimizations
 *           2022-11-17  viseag    ESCAN00113205 Treat 'busy'/'pending' Csm return values in synchronous Csm operations
 *                                               as error in function KeyM_VerifyPublicKeyWithEcuPrivateKey
 *           2022-11-25  visknb    ESCAN00112864 Introduce a check for NvmErrorStatus != NVM_REQ_OK for write requests
 *                                               storing VIN and/or VIN status to NvM
 *                                 ESCAN00112868 Introduce a check for NvmErrorStatus != NVM_REQ_OK within the API
 *                                               GetStoreState when storing of VIN and/or VIN status to NvM
 *                                 ESCAN00112709 Introduce a check for NvmErrorStatus != NVM_REQ_OK for write requests
 *                                               restoring or storing Coding data from/to NvM
 *           2022-11-28  visknb    ESCAN00113211 Fix callback handling for the case that the ServiceCerificate() call
 *                                               returns busy (routine Replace Trust Model Certificates)
 *           2022-11-29  viseag    ESCAN00112867 Introduce a check for NvmErrorStatus != NVM_REQ_OK after NvM write
 *                                               request for routines Replace Trust Model Certificates and
 *                                               Replace Trust Model Root Certificate
 *                       rstemmler ESCAN00112950 ProcCtrl will now return the ErrorCode (NRC) that is preset by the caller
 *                                               (DCM) if underlying calls return with E_NOT_OK but don't set a NRC.
 *                                               DIDs 0199, 019B, 019C, 019D, 0x19F will now set ConditionsNotCorrect
 *                                               in case the trustmodel certificates are not injected yet.
 *                       viseag    ESCAN00112866 Introduce a check for NvmErrorStatus != NVM_REQ_OK after NvM write
 *                                               request for the PostProductionStatus.
 *                                 ESCAN00112865 Introduce a check for NvmErrorStatus != NVM_REQ_OK after NvM write
 *                                               request for the nonce and nonce status in several KeyM routines.
 *           2022-12-01  visknb    ESCAN00113163 Fix certificate verification for diagnostic services for deriving
 *                                               the SecOC keys in the garage
 *                       rstemmler SEC-5228      Correct handling of operation status DCM_CANCEL in
 *                                               Ssa_Coding_DataServices_VINDataIdentifier_WriteData and in
 *                                               Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start.
 *                                               Add doxy comment to all services that are called by ProcCtrl only, that
 *                                               DCM_CANCEL is not handled.
 *           2022-12-05  viseag    SEC-4796      VCA-based silent analysis: Analysis of write accesses to external buffers
 *           2022-12-05  rstemmler ESCAN00112512 After the length check, RightsM_GetSubfunc() now additionally checks if
 *                                               the service is supported (listed in one of the ACLs). If not, the NRC is
 *                                               changed from InvalidFormatOrLength to ServiceNotSupported.
 *           2022-12-05  visewl    SEC-5466      Optimize KeyM mainloop processing
 *                                 SEC-5468      Reverse order for writing RTO and tick-count to NVM
 *           2022-12-09  visewl    SEC-5497      Remove check for requester's authorization in service DID 0x0199
 *                       viseag    ESCAN00113392 Log generalized verification result if trust model certificate
 *                                               verification failed
 *           2022-12-09  visknb    SEC-5453      FETA for KeyM submodule
 *                       visewl    SEC-5437      FETA for BcTp, Cdd, FvM, SecLog and Utils submodules
 *                                 SEC-5455      FETA for RightsM submodule
 *                       viseag    SEC-5457      FETA for CertP submodule
 *           2022-12-13  visewl    SEC-5503      Optimize NvM handling for Coding data blocks
 *           2022-12-13  visknb    SEC-5506      Enhance setting of chain of trust state in TM Root CA cert replacement
 * 03.02.01  2023-03-13  visknb    SEC-5943      Restrict commissioning routines by additional post production flag check
 *           2023-03-20  visknb    ESCAN00113802 Add compileTime assertions for relevant dataType sizes.
 *                                 ESCAN00114169 Add VCA assertion for Csm_MacGenerateResultType_MacGenAesCmacTrunc
 *           2023-03-23  visewl    ESCAN00114168 Apply exclusive areas to shared data used by external S29 processing
 * 03.02.02  2023-05-09  visknb    ESCAN00114530 In ReplaceRoot and ReplaceCertificates routine rollback is triggered
 *                                               if additional verification of certificate entries fails with E_NOT_OK
 *           2023-05-23  visknb    ESCAN00114327 Exclude compile-time assertions and Vca checks for data types
 *                                               that do not exist in specific configurations
 *           2023-05-23  visknb    ESCAN00114391 De-authentication no longer stops authentication broadcast related
 *                                               to different diagnostic channels than the de-authenticated one
 *           2023-05-30  visknb    ESCAN00114687 Allow configurable sizes for Csm_KeyDataType_Ssa_RootCert,
 *                                               Csm_KeyDataType_Ssa_BackendCert and Csm_KeyDataType_Ssa_EcuCert
 * 03.02.30  2024-02-08  visknb    ESCAN00116135 Introduce additional checks for replacement of oversized certificates in
 *                                               routines ReplaceTMCertificates and ReplaceTMRootCertificate routines.
 *           2024-02-09  visewl    ESCAN00114990 Prevent compiler reordering of trigger statements in BcTp
 *           2024-02-12  visewl    ESCAN00116526 Fix cancel handling of diagnostic services
 *           2024-02-14  visewl    ESCAN00116709 Ignore invalid odometer value for post production state handling
 *           2024-02-15  visknb    ESCAN00116013 Fix reporting of DTC 0xD12083 in VSM configuration
 *********************************************************************************************************************/

#if !defined (SSA_H)
# define SSA_H

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Ssa_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define SSA_SW_MAJOR_VERSION                                         (3u)
# define SSA_SW_MINOR_VERSION                                         (2u)
# define SSA_SW_PATCH_VERSION                                         (30u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  BcTp
 *********************************************************************************************************************/
/*!
 * \fn          Ssa_BcTp_Init
 * \brief       Initializes internal variables of the broadcast transport protocol sub component.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Before this runnable has been executed, no other calls to sub module may be done.
 */

/*!
 * \fn          Ssa_BcTp_MainFunction
 * \brief       Cyclically called to continue sending of a started broadcast message.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM and GW only.
 */

/*!
 * \fn          Ssa_BcTp_ReceiveDiagnosticAuthentication
 * \brief       Handles the reception of a diagnostic authentication broadcast part.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Shall be called whenever a part of a diagnostic authentication broadcast is received.
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_BcTp_ReceiveRealTimeOffset
 * \brief       Handles the reception of a real time offset broadcast part.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Shall be called whenever a part of a real time offset broadcast is received.
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_BcTp_ReceiveSharedSecret
 * \brief       Handles the reception of a shared secret broadcast part.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Shall be called whenever a part of a shared secret broadcast is received.
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_BcTp_ReceiveTickCount
 * \brief       Handles the reception of a tick count broadcast part.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Shall be called whenever a part of a tick count broadcast is received.
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_BcTp_ReceiveTickCountTimeout
 * \brief       Handles the COM time-out event of the secured tick-count signal. Forwards it to the FvM.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Shall be called whenever a COM time-out event of the secured tick-count signal is received.
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_BcTp_ReceiveVIN
 * \brief       Handles the reception of a VIN broadcast part.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Shall be called whenever a part of a VIN broadcast is received.
 * \config      Not in VSM.
 */

 /*!
 * \fn          Ssa_BcTp_ReceiveVINTimeout
 * \brief       Handles the COM time-out event of the VIN receive signal and forwards it to the Coding module.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Shall be called whenever a COM time-out for the VIN reception occurs.
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_BcTp_SendDiagnosticAuthentication
 * \brief       Handles the transmission of the diagnostic authentication broadcast.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_BcTp_SendRealTimeOffset
 * \brief       Handles the transmission of the real time offset broadcast.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM and GW only.
 */

/*!
 * \fn          Ssa_BcTp_SendSharedSecret
 * \brief       Handles the transmission of the shared secret broadcast.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_BcTp_SendTickCount
 * \brief       Handles the transmission of the tick count broadcast.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM and GW only.
 */

/*!
 * \fn          Ssa_BcTp_SendVIN
 * \brief       Handles the transmission of the VIN broadcast.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/**********************************************************************************************************************
 *  Cdd
 *********************************************************************************************************************/
/*!
 * \fn          Ssa_Cdd_Csm_CancelJob
 * \brief       Cancels the given job.
 * \details     -
 * \param[in]   jobId           Holds the identifier of the job using the CSM service.
 * \param[in]   operationMode   Indicates which operation mode(s) to perform.
 * \return      Return value of Csm_CancelJob().
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Acts only as proxy and forwards request to Csm_CancelJob().
 */

/*!
 * \fn            Ssa_Cdd_Csm_Hash
 * \brief         Hashes the given data by calling Csm_Hash().
 * \details       -
 * \param[in]     jobId           Holds the identifier of the job using the CSM service.
 * \param[in]     operationMode   Indicates which operation mode(s) to perform.
 * \param[in]     dataBuffer      Contains the pointer to the data to be hashed.
 * \param[in]     dataLength      Contains the number of bytes to be hashed.
 * \param[out]    resultBuffer    Holds a pointer to the memory location, which will hold the generated hash.
 * \param[in,out] resultLength    Holds a pointer to the memory location, which holds the length of resultBuffer (as in parameter)
 *                                and which will hold the length of the generated hash (as out parameter).
 * \return        Return value of Ssa_Cdd_Csm_Hash().
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE|FALSE according to the job with which Csm_Hash() is called.
 * \note          Acts only as proxy and forwards request to Csm_Hash().
 */

/*!
 * \fn            Ssa_Cdd_Csm_KeyElementCopy
 * \brief         Copies a key element to another key element.
 * \details       -
 * \param[in]     keyId                Holds the identifier of the key whose key element shall be the source element.
 * \param[in]     keyElementId         Holds the identifier of the key element which shall be the source for the
 *                                     copy operation.
 * \param[in]     targetKeyId          Holds the identifier of the key whose key element shall be the destination element.
 * \param[in]     targetKeyElementId   Holds the identifier of the key element which shall be the destination for
 *                                     the copy operation.
 * \return        RTE_E_OK if Csm_KeyElementCopy() returned E_OK.
 *                RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY if Csm_KeyElementCopy() returned CRYPTO_E_BUSY.
 *                RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK in all other case.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 * \note          Acts only as proxy and forwards request to Csm_KeyElementCopy().
 */

/*!
 * \fn            Ssa_Cdd_Csm_KeyElementGet
 * \brief         Retrieves the key element bytes from a specific key element of the key identified by the
 *                keyId and stores the key element in the memory location pointed by the key pointer.
 * \details       -
 * \param[in]     keyId        Holds the identifier of the key from which a key element shall be extracted.
 * \param[in]     keyElementId Holds the identifier of the key element to be extracted.
 * \param[out]    keyPtr       Holds the pointer to the memory location where the key shall be copied to.
 * \param[in,out] keyLengthPtr Holds a pointer to the memory location in which the output buffer length in bytes is
 *                             stored. On calling this function, this parameter shall contain the buffer length in
 *                             bytes of the keyPtr. When the request has finished, the actual size of the written
 *                             input bytes shall be stored.
 * \return        RTE_E_OK if Csm_KeyElementGet() returned E_OK.
 *                RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY if Csm_KeyElementGet() returned CRYPTO_E_BUSY.
 *                RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK in all other case.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 * \note          Acts only as proxy and forwards request to Csm_KeyElementGet().
 */

/*!
 * \fn          Ssa_Cdd_Csm_KeyElementSet
 * \brief       Sets the given key element bytes to the key identified by keyId.
 * \details     -
 * \param[in]   keyId        Holds the identifier of the job using the CSM service.
 * \param[in]   keyElementId Holds the identifier of the key element to be written.
 * \param[in]   keyPtr       Holds the pointer to the key element bytes to be processed.
 * \param[in]   keyLength    Contains the number of key element bytes.
 * \return      RTE_E_OK if Csm_KeyElementSet() returned E_OK.
 *              RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY if Csm_KeyElementSet() returned CRYPTO_E_BUSY.
 *              RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK in all other case.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        Acts only as proxy and forwards request to Csm_KeyElementSet().
 */

/*!
 * \fn          Ssa_Cdd_Csm_KeySetValid
 * \brief       Sets the given key to valid.
 * \details     -
 * \param[in]   keyId        Holds the identifier of the job using the CSM service.
 * \return      RTE_E_OK if Csm_KeySetValid() returned E_OK.
 *              RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY if Csm_KeySetValid() returned CRYPTO_E_BUSY.
 *              RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK in all other case.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        Acts only as proxy and forwards request to Csm_KeySetValid().
 */

/*!
 * \fn            Ssa_Cdd_Csm_SignatureGenerate
 * \brief         Generates the the signature over the given data by calling Csm_SignatureGenerate().
 * \details       -
 * \param[in]     jobId           Holds the identifier of the job using the CSM service.
 * \param[in]     operationMode   Indicates which operation mode(s) to perform.
 * \param[in]     dataBuffer      Contains the pointer to the data over which the siganture shall be calculated.
 * \param[in]     dataLength      Contains the number of bytes over which the siganture shall be calculated.
 * \param[out]    resultBuffer    Holds a pointer to the memory location, which will hold the generated signature.
 * \param[in,out] resultLength    Holds a pointer to the memory location, which holds the length of resultBuffer (as in parameter)
 *                                and which will hold the length of the generated signatur (as out parameter).
 * \return        Return value of Ssa_Cdd_Csm_SignatureGenerate().
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE|FALSE according to the job with which Csm_SignatureGenerate() is called.
 * \note          Acts only as proxy and forwards request to Csm_SignatureGenerate().
 */

/*!
 * \fn          Ssa_Cdd_Csm_SignatureVerify
 * \brief       Verifies the given signature by comparing with a generated signature by calling Csm_SignatureVerify().
 * \details     -
 * \param[in]   jobId           Holds the identifier of the job using the CSM service.
 * \param[in]   operationMode   Indicates which operation mode(s) to perform.
 * \param[in]   dataBuffer      Contains the pointer to the data to be verified.
 * \param[in]   dataLength      Contains the number of bytes to be verified.
 * \param[in]   compareBuffer   Holds a pointer to the signature to be verified.
 * \param[in]   compareLength   Contains the signature length in bytes.
 * \param[out]  resultBuffer    Holds a pointer to the memory location, which will hold the result of the signature verification.
 * \return      Return value of Csm_SignatureVerify().
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE|FALSE according to the job with which Csm_SignatureVerify() is called.
 * \note        Acts only as proxy and forwards request to Csm_SignatureVerify().
 */

/*!
 * \fn          Ssa_Cdd_Init
 * \brief       Initializes internal variables of the Complex Device Driver sub component.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Before this runnable has been executed, no other calls to sub module may be done.
 */

/*!
 * \fn          Ssa_Cdd_KeyM_CsrElementSet
 * \brief       Set certificate signing request element data.
 * \details     -
 * \param[in]   CertId                               Holds the identifier of the certificate.
 * \param[in]   CertElementId                        Holds the identifier of the certificate element.
 * \param[in]   EncodingType                         Holds the encoding type of the certificate element.
 * \param[in]   ElementData                          Points to an array of element data.
 * \param[in]   ElementDataLength                    Max number of bytes available in ElementData.
 * \return      E_OK                                 CSR element was set successfully.
 *              E_NOT_OK                             Due to internal error, the CSR element could not be set.
 *              KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *              KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        Acts only as proxy and forwards request to KeyM_CsrElementSet().
 */

/*!
 * \fn            Ssa_Cdd_KeyM_GetCertificate
 * \brief         Gets certificate data.
 * \details       -
 * \param[in]     CertId                           Holds the identifier of the certificate.
 * \param[out]    CertData                         Holds the pointer to the memory location where the certificate data shall be copied to.
 * \param[in,out] CertDataLength                   In: Max number of bytes that can be copied to CertData. Out: Number of bytes copied to CertData.
 * \return        E_OK                             Certificate data available and provided.
 *                E_NOT_OK                         Operation not accepted due to an internal error.
 *                KEYM_E_PARAMETER_MISMATCH        Certificate ID invalid.
 *                KEYM_E_KEY_CERT_SIZE_MISMATCH    Provided buffer for the certificate too small.
 *                KEYM_E_KEY_CERT_EMPTY            No certificate data available, the certificate slot is empty.
 *                KEYM_E_KEY_CERT_READ_FAIL        Certificate cannot be provided, access denied.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */

/*!
 * \fn          Ssa_Cdd_KeyM_ServiceCertificate
 * \brief       Handles a service certificate operation request.
 * \details     -
 * \param[in]   Service                              Provides the type of service the key manager has to perform.
 * \param[in]   CertNamePtr                          Points to an array that defines the name of the certificate to
 *                                                   be updated
 * \param[in]   CertNameLength                       Specifies the number of bytes in CertNamePtr. The value 0
 *                                                   indicates that no CertNamePtr is provided within this function.
 * \param[in]   RequestData                          Information that comes along with the request.
 * \param[in]   RequestDataLength                    Length of data in the RequestData array.
 * \param[out]  ResponseData                         Data returned by the function.
 * \param[in]   ResponseDataLength                   Max number of bytes available in ResponseDataPtr.
 * \return      E_OK                                 Service data operation successfully accepted.
 *              E_NOT_OK                             Operation not accepted due to an internal error.
 *              KEYM_E_PARAMETER_MISMATCH            Parameter does not match with expected value.
 *              KEYM_E_KEY_CERT_SIZE_MISMATCH        Parameter size doesn't match.
 *              KEYM_E_BUSY                          Service cannot be performed yet. KeyM is
 *                                                   currently busy with other jobs.
 *              KEYM_E_KEY_CERT_EMPTY                Certificate slot is empty.
 *              KEYM_E_CERT_INVALID_CHAIN_OF_TRUST   Invalid chain of trust.
 * \pre         -
 * \note        The parsing of a certificate and the verifying of certificate elements is performed synchronously
 *              within this function.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \note        Acts only as proxy and forwards request to KeyM_ServiceCertificate().
 */

/*!
 * \fn          Ssa_Cdd_KeyM_SetCertificate
 * \brief       Sets certificate data to the key management module
 * \details     -
 * \param[in]   CertId                           Holds the identifier of the certificate.
 * \param[in]   CertData                         Holds the pointer to the memory location where the certificate data shall be read from.
 *                                               This pointer is only used as read-only.
 * \param[in]   CertDataLength                   Max number of bytes that can be read from CertData.
 * \return      E_OK                             Certificate accepted.
 *              E_NOT_OK                         Certificate could not be set.
 *              KEYM_E_PARAMETER_MISMATCH        Parameter does not match with expected value.
 *              KEYM_E_KEY_CERT_SIZE_MISMATCH    Parameter size doesn't match.
 * \pre         -
 * \note        The parsing of a certificate and the verifying of certificate elements is performed synchronously
 *              within this function.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Cdd_MainFunction
 * \brief       Main function of the Cdd sub component.
 * \details     This function is cyclically called. It decouples the S29 service request coming as BSW callout
 *              from DCM from Ssa SWC processing.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Cdd_NvM_GetErrorStatus
 * \brief       Iterates over all configured blocks and saves summed up NvM block specific result in given pointer.
 * \details     -
 * \param[in]   ErrorStatus  Holds a pointer to the memory location which will hold the summed up block status.
 * \return      E_OK      result was saved in ErrorStatus
 *              E_NOT_OK  otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Cdd_NvM_ReadBlock
 * \brief       Iterates over all configured blocks and set up read jobs.
 * \details     -
 * \param[in]   DstPtr - Shall be a NULL_PTR
 * \return      E_OK      jobs were setup
 *              E_NOT_OK  otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Cdd_NvM_SetRamBlockStatus
 * \brief       Iterates over all configured blocks and sets the NvM block specific RAM status.
 * \details     -
 * \param[in]   RamBlockStatus
 * \return      E_OK      RAM status set
 *              E_NOT_OK  RAM status not set
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Cdd_NvM_WriteBlock
 * \brief       Iterates over all configured blocks and set up write jobs.
 * \details     -
 * \param[in]   SrcPtr  Shall be a NULL_PTR
 * \return      E_OK      jobs were setup
 *              E_NOT_OK  otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 *  \fn            Ssa_Cdd_DiagnosticService_Authentication_0x29
 *  \brief         Processes a received diagnostic service request with SID 0x29.
 *  \details       DCM calls this function as soon as the supported diagnostic service 0x29, configured to be handled
 *                 by a CDD, is received. All of the relevant diagnostic request parameter information is forwarded by
 *                 DCM through the pMsgContext function parameter.
 *                 The configuration parameter /Dcm/DcmConfigSet/DcmDsd/DcmDsdServiceTable/DcmDsdService/DcmDsdSidTabFnc
 *                 must be set to the concrete name of the callout (Ssa_Cdd_DiagnosticService_Authentication_0x29).
 *  \param[in]     opStatus           The operation status
 *  \param[in,out] pMsgContext        Message-related information for one diagnostic protocol identifier.
 *                                    The pointers in pMsgContext points behind the SID.
 *                                    The context information of a diagnostic request contained in the structure pMsgContext
 *                                    is defined by the Dcm.
 *  \param[out]    ErrorCode          Negative response code in case return value is DCM_E_NOT_OK
 *  \return        DCM_E_PENDING      Job processing is not yet finished
 *  \return        DCM_E_OK           Job processing finished, send positive response
 *  \return        DCM_E_NOT_OK       Job processing finished, send NRC from the ErrorCode
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 */

/**********************************************************************************************************************
 *  CertP
 *********************************************************************************************************************/
/*!
 * \fn          Ssa_CertP_Init
 * \brief       Initializes internal variables of the certificate parser sub component.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Before this runnable has been executed, no other calls to sub module may be done.
 */

/*!
 * \fn          Ssa_CertP_AttributeCertificate_Parse
 * \brief       Parses an attribute certificate.
 * \details     -
 * \param[in]   rawCertData Holds a pointer to the raw certificate data to be parsed.
 * \param[in]   rawCertLength Contains the number of bytes of rawCertData.
 * \param[in,out] parsedCert  Holds the pointer to the memory location where the parser information shall be stored.
 * \return      RTE_E_OK Certificate could parsed
 *              RTE_E_CertP_Functions_E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_CertP_Certificate_Compare
 * \brief       Compares two certificates.
 * \details     -
 * \param[in]   rawCertData1 Holds a pointer to the first raw certificate data to be verified.
 * \param[in]   parsedCert1 Holds the pointer to the memory location where the parser information of first certificate are stored.
 * \param[in]   pkiRole1 PKI role of the first certificate
 * \param[in]   rawCertData2 Holds a pointer to the second raw certificate data to be verified.
 * \param[in]   parsedCert2 Holds the pointer to the memory location where the parser information of first certificate are stored.
 * \param[in]   pkiRole2  PKI role of the first certificate
 * \param[out]  isEqual TRUE if first and second certificate are equal, otherwise FALSE.
 * \return      RTE_E_OK Compare executed
 *              RTE_E_CertP_Functions_E_NOT_OK Invalid parameter, compare not executed
 * \pre         Ssa_CertP_Certificate_Parse or Ssa_CertP_AttributeCertificate_Parse have to be called before.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_CertP_Certificate_Parse
 * \brief       Parses a certificate.
 * \details     -
 * \param[in]   rawCertData Holds a pointer to the raw certificate data to be parsed.
 * \param[in]   rawCertLength Contains the number of bytes of rawCertData.
 * \param[in,out] parsedCert  Holds the pointer to the memory location where the parser information shall be stored.
 * \return      RTE_E_OK Certificate could parsed
 *              RTE_E_CertP_Functions_E_NOT_OK otherwise
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_CertP_Certificate_Verify
 * \brief       Verifies passed certificate against passed issuer certificate. Furthermore, expected role is verified.
 * \details     -
 * \param[in]   rawCertData      Holds a pointer to the raw certificate data to be verified.
 *                               Must provide at least sizeof(CertP_RawCertBufferType) many bytes to ensure that
 *                               no null pointer is passed to the RTE.
 * \param[in,out] parsedCert     Holds the pointer to the memory location where the parsed information are stored.
 * \param[in]   rawCertIssuer    Holds a pointer to the raw certificate issuer data to be verified.
 *                               Must provide at least sizeof(CertP_RawCertBufferType) many bytes to ensure that
 *                               no null pointer is passed to the RTE.
 * \param[in]   parsedCertIssuer Holds the pointer to the memory location where the parsed information of issuer certificate are stored.
 * \param[in]   expectedPkiRole  Expected role of the certificate to be verified.
 * \return      RTE_E_OK Certificate could be verified.
 *              RTE_E_CertP_Functions_E_NOT_OK An error occurred.
 *              RTE_E_CertP_Functions_E_PENDING Requested service is pending. Try again with operation status Pending.
 * \pre         Ssa_CertP_Certificate_Parse or Ssa_CertP_AttributeCertificate_Parse have to be called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_CertP_Certificate_Verify_Extended
 * \brief       Verifies passed certificate against passed issuer certificate. Furthermore, expected role, nonce and target vin / unique ECU id are verified if needed.
 * \details     -
 * \param[in]   rawCertData      Holds a pointer to the raw certificate data to be verified.
 *                               Must provide at least sizeof(CertP_RawCertBufferType) many bytes to ensure that
 *                               no null pointer is passed to the RTE.
 * \param[in,out] parsedCert     Holds the pointer to the memory location where the parsed information are stored.
 * \param[in]   rawCertIssuer    Holds a pointer to the raw certificate issuer data to be verified.
 *                               Must provide at least sizeof(CertP_RawCertBufferType) many bytes to ensure that
 *                               no null pointer is passed to the RTE.
 * \param[in]   parsedCertIssuer Holds the pointer to the memory location where the parsed information of issuer certificate are stored.
 * \param[in]   expectedPkiRole  Expected role of the certificate to be verified.
 * \param[in]   expectedNonce    Holds a pointer to a memory location where the expected nonce is stored.
 * \return      RTE_E_OK Certificate could be verified.
 *              RTE_E_CertP_Functions_E_NOT_OK An error occurred.
 *              RTE_E_CertP_Functions_E_PENDING Requested service is pending. Try again with operation status Pending.
 * \pre         Ssa_CertP_Certificate_Parse or Ssa_CertP_AttributeCertificate_Parse have to be called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_CertP_CsmCallbackNotification_SignatureVerify
 * \brief       Callback Notification from CSM.
 * \details     Notifies the CertP that a signature verify job used for verifying the signature of certificates has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_CertP_ParseTime
 * \brief       Parses an encoded ASN1 time element.
 * \details     -
 * \param[in]   data        Holds a pointer to the raw data that shall be parsed.
 *                          The value of either a GeneralizedTime or UTC TLV element.
 *                          Expected to provide at least sizeof(Ssa_Data15ByteType) many bytes.
 * \param[in]   dataLength  Contains the number of bytes of data.
 * \param[out]  dateTime    Holds the pointer to the memory location where the parsed date and time information shall be stored.
 * \return      RTE_E_OK                       Parse success.
 *              RTE_E_CertP_Functions_E_NOT_OK Parse failure. 
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/**********************************************************************************************************************
 *  Coding
 *********************************************************************************************************************/
/*!
 * \fn          Ssa_Coding_CsmCallbackNotification_SigVerify_Coding
 * \brief       Callback Notification from CSM.
 * \details     Notifies the Coding module that a signature verify job used for secure variant coding has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead
 * \brief       Checks if the VIN Lock Status can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  if data is readable.
 *              RTE_E_DataServices_DID_018E_VIN_Lock_Status_E_NOT_OK if data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData
 * \brief       Reads the VIN Lock Status and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK  if data was read.
 *              RTE_E_DataServices_DID_018E_VIN_Lock_Status_E_NOT_OK if data was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead
 * \brief       Checks if the VIN Status can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  if data is readable.
 *              RTE_E_DataServices_DID_018E_VIN_Status_E_NOT_OK if data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData
 * \brief       Reads the VIN Status and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK  if data was read.
 *              RTE_E_DataServices_DID_018E_VIN_Status_E_NOT_OK if data was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
* \fn          Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead
* \brief       Checks if the precompile switches can be read.
* \details     -
* \param[in]   OpStatus  Current operation status.
* \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
* \return      RTE_E_OK  if data is readable.
*              RTE_E_DataServices_DID_0197_Precompile_switch_E_NOT_OK if data is not readable.
* \pre         -
* \context     TASK
* \reentrant   FALSE
* \synchronous TRUE
*/

/*!
* \fn          Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData
* \brief       Reads the states of the precompile switches and passes them to the given data parameter.
* \details     -
* \param[in]   OpStatus  Current operation status.
* \param[out]  Data      Holds the pointer to the memory location where the read data shall be stored.
* \return      RTE_E_OK  if data was read.
*              RTE_E_DataServices_DID_0197_Precompile_switch_E_NOT_OK if data was not read.
* \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data4ByteType) many bytes.
* \context     TASK
* \reentrant   FALSE
* \synchronous TRUE
*/

/*!
 * \fn          Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead
 * \brief       Checks if SSA major version of the SSA version information can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable
 *              RTE_E_DataServices_SSA_Version_Information_Read_SSA_Major_Version_E_NOT_OK data is not readable
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData
 * \brief       Reads the SSA major version of the SSA version information and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_SSA_Version_Information_Read_SSA_Major_Version_E_NOT_OK if data was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead
 * \brief       Checks if SSA minor version of the SSA version information can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable
 *              RTE_E_DataServices_SSA_Version_Information_Read_SSA_Minor_Version_E_NOT_OK data is not readable
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData
 * \brief       Reads the SSA minor version of the SSA version information and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_SSA_Version_Information_Read_SSA_Minor_Version_E_NOT_OK if data was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead
 * \brief       Checks if SSA patch level of the SSA version information can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable
 *              RTE_E_DataServices_SSA_Version_Information_Read_SSA_Patch_Level_E_NOT_OK data is not readable
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData
 * \brief       Reads the SSA patch level of the SSA version information and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_SSA_Version_Information_Read_SSA_Patch_Level_E_NOT_OK if data was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead
 * \brief       Checks if VINDataIdentifier can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable
 *              RTE_E_DataServices_VINDataIdentifier_E_NOT_OK data is not readable
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_VINDataIdentifier_ReadData
 * \brief       Reads VINDataIdentifier and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_VINDataIdentifier_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data17ByteType) many bytes.
 *              Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_DataServices_VINDataIdentifier_WriteData
 * \brief       Writes Reads VINDataIdentifier.
 * \details     -
 * \param[in]   Data Holds a pointer to the VINDataIdentifier to be stored.
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data was written.
 *              RTE_E_DataServices_VINDataIdentifier_E_NOT_OK if data was not written.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_Init
 * \brief       Initializes internal variables of the coding sub component.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Before this runnable has been executed, no other calls to sub module may be done.
 */

/*!
 * \fn          Ssa_Coding_InitMonitorForEvent_DTC_0x164456
 * \brief       Notifies that this event is cleared, or that the operation (monitoring) cycle restarts.
 *              Immediately checks the VIN Status for re-qualifying this DTC.
 * \details     -
 * \param[in]   InitMonitorReason Init monitor reason.
 * \return      RTE_E_OK always.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_MainFunction
 * \brief       Cyclically called to handle timeout. In case of VSM, functions sends VIN cyclically.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start
 * \brief       Transfer a Signature Verification Key to the ECU, which afterwards will be used for signature verification within software reprogramming or variant coding process. To enable the ECU to validate the Signature Verification Key, the key is transferred within an appropriate certificate.
 * \details     -
 * \param[in]   Data_Verification_Certificate Holds a pointer to the certificate to be used for verification.
 *              Must reference a buffer of at least sizeof(Dcm_Data2002ByteType) many bytes.
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[in]   DataLength Length of certificates stored in Data_Verification_Certificate.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start
 * \brief       Resets the currently stored VINDataIdentifier to its default value.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK otherwise.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start
 * \brief       Verifies the integrity and authenticity e.g. of variant coding data using a signature verification.
 * \details     -
 * \param[in]   Data_to_be_checked - Identifies data which shall be verified (0 for Variant Coding).
 * \param[in]   Signature_Value Holds a pointer to the signature to be used for verification.
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_Coding_ServiceRequestNotification_Confirmation
 * \brief       Confirmation of the former Dcm Service Request Indication.
 * \details     -
 * \param[in]   SID                 Requested service identifier.
 * \param[in]   ReqType             Type of Request.
 * \param[in]   SourceAddress       Source address of tester.
 * \param[in]   ConfirmationStatus  Current confirmation status.
 * \return      RTE_E_OK always.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Only indication used.
 */

/*!
 * \fn          Ssa_Coding_ServiceRequestNotification_Indication
 * \brief       Indication of a Dcm service request indication which aims for writing of coding relevant data. If request is coding relevant and coding was started, request data is used as part of signature verification. If request is coding relevant but coding was not started, request is discarded.
 * \details     -
 * \param[in]   SID  Requested service identifier.
 * \param[in]   RequestData  Pointer to the whole data of the current request
 * \param[in]   DataSize Length of RequestData in bytes.
 * \param[in]   ReqType Type of Request.
 * \param[in]   SourceAddress  Source address of tester.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if no coding request or coding request valid.
 *              RTE_E_ServiceRequestNotification_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Only indication used.
 */

/*!
 * \fn          Ssa_Coding_VIN_Get
 * \brief       Get the stored VIN.
 * \details     -
 * \param[out]  vin  Holds the pointer to the memory location where the VIN shall be stored.
 * \return      RTE_E_OK VIN copied successfully.
 *              RTE_E_Coding_VIN_E_NOT_OK copying VIN failed.
 * \pre         The buffer referenced by vin must provide at least sizeof(Coding_VINDataType) many bytes.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_VIN_GetStoreState
 * \brief       Get the VIN store state.
 * \details     -
 * \param[out]  state  Holds the pointer to the memory location where the VIN store state shall be stored.
 * \return      RTE_E_OK state written successfully.
 *              RTE_E_Coding_VINControl_E_NOT_OK writing state failed.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_VIN_Lock
 * \brief       Offers possibility to protect the current VIN to be written.
 * \details     -
 * \param[in]   locked TRUE if VIN shall be locked, FALSE for unlocking.
 * \return      RTE_E_OK always.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_Coding_VIN_Receive
 * \brief       Handles the reception of a VIN broadcast.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Triggered whenever a VIN broadcast was received.
 * \config      Not in VSM.
 */

 /*!
 * \fn          Ssa_Coding_VIN_Receive_Timeout
 * \brief       Handles the reception of a COM Signal Timeout for the VIN reception.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Triggered whenever a COM Signal Timeout for the VIN reception occurs.
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_Coding_VIN_Set
 * \brief       Updates the stored VIN to given value.
 * \details     -
 * \param[in]   vin Holds the pointer to the VIN to be stored.
 * \return      RTE_E_OK if VIN was stored.
 *              RTE_E_Coding_VINControl_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/**********************************************************************************************************************
 *  KeyM
 *********************************************************************************************************************/

/*!
 * \fn          Ssa_KeyM_Certificate_CheckTrustModelChainOfTrust
 * \brief       Gets the Trust Model chain of trust state.
 * \details     -
 * \param[out]  state     Holds the pointer to the memory location where the state shall be written.
 *                        Must be a valid pointer.
 * \return      RTE_E_OK                        Getting state succeeded.
 *              RTE_E_KeyM_Certificate_E_NOT_OK Getting state failed.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_Certificate_GetBackendSerialNumber
 * \brief       Reads the serial number of the backend certificate and passes it to the given memory location.
 * \details     -
 * \param[out]  serialNumber  Holds the pointer to the memory location where the serial number shall be stored.
 *                            Must reference a buffer of at least sizeof(Ssa_Data2ByteType) many bytes.
 * \param[in,out] serialNumberLength In: Size in bytes of memory location. Out: Length of serial number written to memory location.
 * \return      RTE_E_OK if serial number was read.
 *              RTE_E_KeyM_Certificate_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_Certificate_GetBackendSubject
 * \brief       Reads the subject of the backend certificate and passes it to the given memory location.
 * \details     -
 * \param[out]    backendSubject Holds the pointer to the memory location where the subject shall be stored.
 *                               Must reference a buffer of at least sizeof(Ssa_Data30ByteType) many bytes.
 * \param[in,out] dataLength In: Size in bytes of memory location. Out: Length of subject written to memory location.
 * \return      RTE_E_OK if serial number was read.
 *              RTE_E_KeyM_Certificate_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey
 * \brief       Signs passed data with a size of up to 1024 by with the private Key of the ECU.
 * \details     -
 * \param[in]   data Holds the pointer to the memory location to be signed.
 * \param[in]   dataLength Length in bytes of memory location to be signed.
 * \param[out]  signature Holds the pointer to the memory location where the signature shall be stored.
 *                        Must reference a buffer of at least SSA_SIZEOF_SIGNATURE many bytes.
 * \return      RTE_E_OK if signature was build
 *              RTE_E_KeyM_Certificate_E_NOT_OK otherwise.
 *              RTE_E_KeyM_Certificate_E_PENDING Requested service is pending. Try again with operation status Pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE according to the job referenced in /MICROSAR/Ssa/SsaKeyM/SsaKeyMCsmTrustModelEcuLiveSignatureGenerateJobRef
 */

/*!
 * \fn          Ssa_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey
 * \brief       Signs passed data with a size of up to 4092 by with the private Key of the ECU.
 * \details     -
 * \param[in]   data Holds the pointer to the memory location to be signed.
 * \param[in]   dataLength Length in bytes of memory location to be signed.
 * \param[out]  signature Holds the pointer to the memory location where the signature shall be stored.
 *                        Must reference a buffer of at least SSA_SIZEOF_SIGNATURE many bytes.
 * \return      RTE_E_OK if signature was build
 *              RTE_E_KeyM_Certificate_E_NOT_OK otherwise.
 *              RTE_E_KeyM_Certificate_E_PENDING Requested service is pending. Try again with operation status Pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE according to the job referenced in /MICROSAR/Ssa/SsaKeyM/SsaKeyMCsmTrustModelEcuLiveSignatureGenerateJobRef
 */

/*!
 * \fn          Ssa_KeyM_Certificate_VerifyCertWithBackendCert
 * \brief       Verifies the passed certificate with the stored backend certificate.
 * \details     -
 * \param[in]   cert Holds a pointer to the raw certificate data to be verified.
 *              Must reference a buffer of at least sizeof(CertP_RawCertBufferType) many bytes.
 * \param[in]   parsedCertStructure Holds the pointer to the memory location where the parser information of the certificate are stored.
 * \param[in]   certLength Length of the raw certificate in bytes.
 * \param[in]   expectedPkiRole Expected role of the certificate to be verified.
 * \param[in]   expectedNonce Holds a pointer to a memory location where the expected nonce is stored.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed. The verification result is written to parsedCertStructure.
 *              RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK otherwise. Verification failed.
 *              RTE_E_KeyM_Certificate_E_PENDING Requested service is pending. Try again with operation status Pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_KeyM_Com_VehicleSharedSecretNotification
 * \brief       Handles the reception of a shared secret notification broadcast, so symmetric keys will be generated and hash of shared secret will be stored.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Triggered whenever a shared secret broadcast was received.
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_KeyExchangeCalcPubVal
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a key exchange calculate public value job used during Distribution
 *              of the car-specific secret at the garage or dealership has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous key management job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_KeyGenerate_TrustModelEcuCsr
 * \brief       Callback Notification from CSM.
 * \details     Notifies Ssa_KeyM that generating a new key pair into the ECU CSR private key slot has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous key management job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_KeyExchangeCalcSecret
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a key exchange calculate secret job Distribution of the car-specific
 *              secret at the garage or dealership has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous key management job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_RandomGenerate
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a random generate job used for generating a car-specific secret has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_RandomSeed
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a random seed job has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Not in VSM.
 *              Asynchronous key management job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_SignatureGenerate
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a signature generate job used for generating a signature with the
 *              private ECU key has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 *              Asynchronous job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_SignatureGenerate_TrustModelEcuLive
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a signature generate job used for generating a signature with the
 *              Trust Model ECU live key has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_SignatureGenerate_TrustModelEcuCsr
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a signature generate job used for generating a signature with the
 *              Trust Model ECU CSR key has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_SignatureVerify
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a signature verify job used for verifying the signature of passed data
 *              with a temporarily set Ed25519ph public key, e.g. of a passed certificate, has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_SignatureVerify_ReplacementAuthority
 * \brief       Callback Notification from CSM.
 * \details     Notifies the Ssa_KeyM that the signature verify job used for verifying the signature over the passed
 *              data with the Replacement Authority's public key has finished.
 * \param[in]   result  Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_SignatureVerify_TrustModelTemp
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a signature verify job used for verifying the signature of passed data
 *              with a temporarily set  Ed25519 public key, e.g. of a Trust Model certificate, has finished.
 * \param[in]   result  Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous job processing.
 */

/*!
 * \fn          Ssa_KeyM_CsmCallbackNotification_SignatureVerify_TrustModelBackend
 * \brief       Callback Notification from CSM.
 * \details     Notifies the KeyM that a signature verify job used for verifying the signature of passed data
 *              with the public key of the Trust Model backend certificate has finished.
 * \param[in]   result  Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Asynchronous job processing.
 */

/*!
 * \fn          Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackend
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Backend certificate verification has been finished.
 * \param[in]   CertId  The identifier of the certificate that has been verified.
 * \param[in]   Result  Contains information about the result of the operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackendPeer
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Backend Peer certificate verification has been finished.
 * \param[in]   CertId  The identifier of the certificate that has been verified.
 * \param[in]   Result  Contains information about the result of the operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcu
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Ecu certificate verification has been finished.
 * \param[in]   CertId  The identifier of the certificate that has been verified.
 * \param[in]   Result  Contains information about the result of the operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuCsr
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Ecu Csr certificate verification has been finished.
 * \param[in]   CertId  The identifier of the certificate that has been verified.
 * \param[in]   Result  Contains information about the result of the operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuPeer
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Ecu Peer certificate verification has been finished.
 * \param[in]   CertId  The identifier of the certificate that has been verified.
 * \param[in]   Result  Contains information about the result of the operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediate
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Intermediate certificate verification has been finished.
 * \param[in]   CertId  The identifier of the certificate that has been verified.
 * \param[in]   Result  Contains information about the result of the operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediatePeer
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Intermediate Peer certificate verification has been finished.
 * \param[in]   CertId  The identifier of the certificate that has been verified.
 * \param[in]   Result  Contains information about the result of the operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelRoot
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Root certificate verification has been finished.
 * \param[in]   CertId  The identifier of the certificate that has been verified.
 * \param[in]   Result  Contains information about the result of the operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackend
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Backend certificate service operation has been finished.
 * \param[in]   CertId           The certificate identifier which this service was request for.
 * \param[in]   Result           Contains information about the result of the operation.
 * \param[in]   ResultDataLength Contains the length of the resulting data of this operation if any.
 * \param[in]   ResultDataPtr    Pointer to the data of the result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackendPeer
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Backend Peer certificate service operation has been finished.
 * \param[in]   CertId           The certificate identifier which this service was request for.
 * \param[in]   Result           Contains information about the result of the operation.
 * \param[in]   ResultDataLength Contains the length of the resulting data of this operation if any.
 * \param[in]   ResultDataPtr    Pointer to the data of the result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcu
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Ecu certificate service operation has been finished.
 * \param[in]   CertId           The certificate identifier which this service was request for.
 * \param[in]   Result           Contains information about the result of the operation.
 * \param[in]   ResultDataLength Contains the length of the resulting data of this operation if any.
 * \param[in]   ResultDataPtr    Pointer to the data of the result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuCsr
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Ecu Csr service operation has been finished.
 * \param[in]   CertId           The certificate identifier which this service was request for.
 * \param[in]   Result           Contains information about the result of the operation.
 * \param[in]   ResultDataLength Contains the length of the resulting data of this operation if any.
 * \param[in]   ResultDataPtr    Pointer to the data of the result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuPeer
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Ecu Peer certificate service operation has been finished.
 * \param[in]   CertId           The certificate identifier which this service was request for.
 * \param[in]   Result           Contains information about the result of the operation.
 * \param[in]   ResultDataLength Contains the length of the resulting data of this operation if any.
 * \param[in]   ResultDataPtr    Pointer to the data of the result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediate
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Intermediate certificate service operation has been finished.
 * \param[in]   CertId           The certificate identifier which this service was request for.
 * \param[in]   Result           Contains information about the result of the operation.
 * \param[in]   ResultDataLength Contains the length of the resulting data of this operation if any.
 * \param[in]   ResultDataPtr    Pointer to the data of the result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediatePeer
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Intermediate Peer certificate service operation has been finished.
 * \param[in]   CertId           The certificate identifier which this service was request for.
 * \param[in]   Result           Contains information about the result of the operation.
 * \param[in]   ResultDataLength Contains the length of the resulting data of this operation if any.
 * \param[in]   ResultDataPtr    Pointer to the data of the result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelRoot
 * \brief       Callback notification from AsrKeyM.
 * \details     Notifies the Ssa_KeyM that a Trust Model Root certificate service operation has been finished.
 * \param[in]   CertId           The certificate identifier which this service was request for.
 * \param[in]   Result           Contains information about the result of the operation.
 * \param[in]   ResultDataLength Contains the length of the resulting data of this operation if any.
 * \param[in]   ResultDataPtr    Pointer to the data of the result.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_Backend_CA_Certificate_ConditionCheckRead
 * \brief       Checks if backend certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable
 *              RTE_E_DataServices_Backend_CA_Certificate_Read_E_NOT_OK data is not readable
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ConditionCheckRead
 * \brief       Checks if subject key identifier of backend certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable
 *              RTE_E_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_E_NOT_OK data is not readable
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_Backend_CA_Certificate_Identification_SubjectKeyIdentifier_ReadData
 * \brief       Reads subject key identifier of backend certificate and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Backend_CA_Certificate_Identification_Read_Backend_CA_SubjectKeyIdentifier_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data20ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadData
 * \brief       Reads backend certificate and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Backend_CA_Certificate_Read_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_Backend_CA_Certificate_ReadDataLength
 * \brief       Reads the length of the backend certificate and pass it to given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Backend_CA_Certificate_Read_E_NOT_OK if length was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead
 * \brief       Checks if the SecOC PDU Data-IDs and their corresponding Key CMACs can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK   if condition check was successful.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK   if condition check failed.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData
 * \brief       Reads the SecOC PDU Data-IDs and their corresponding Key CMACs and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING if request is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data4092ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength
 * \brief       Reads the length of the SecOC PDU Data-IDs and their corresponding Key CMACs and passes it to the given length parameter.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK    if data length is readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK    if data length is not readable.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead
 * \brief       Checks if generated random number can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK   if request was successful.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK  if request failed.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_ReadData
 * \brief       Reads generated random number and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the random number shall be stored.
 * \return      RTE_E_OK  If data read is successful.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK   If readData failed.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData must have been called before.
 *              This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead
 * \brief       Checks if generated random number result can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  If request is sucessful.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK   If request fails.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0191_Generated_Random_Number_Result_ReadData
 * \brief       Generates a random number and passes the status (result) of the random number generation to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the status of the random number generation shall be stored.
 * \return      RTE_E_OK                                                             if Csm returns anything but pending or routine is canceled
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING    if Csm returns pending
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK  if request fails
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0193_Common_Name_ConditionCheckRead
 * \brief       Checks if the common name can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  Common name is valid.
 *              RTE_E_DataServices_DID_0193_Common_Name_E_NOT_OK  Common name is not valid.
 * \pre         Ssa_KeyM_DataServices_DID_0193_SerialNumber_ReadData must have been called before.
 *              The preconditions of Ssa_KeyM_DataServices_DID_0193_SerialNumber_ReadData also hold.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0193_Common_Name_ReadData
 * \brief       Passes the common name to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the common name shall be stored.
 * \return      RTE_E_OK  if data was read.
 *              RTE_E_DataServices_DID_0193_Common_Name_E_NOT_OK  if data could not be read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data30ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_0193_Common_Name_ConditionCheckRead must have been called before.
 *              The preconditions of Ssa_KeyM_DataServices_DID_0193_Common_Name_ConditionCheckRead also hold.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0193_SerialNumber_ConditionCheckRead
 * \brief       Checks if the serial number can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  SerialNumber is valid.
 *              RTE_E_DataServices_DID_0193_SerialNumber_E_NOT_OK  SerialNumber is not valid.
 * \pre         Ssa_KeyM_DataServices_DID_0193_SubjectPublicKeyInfo_ReadData must have been called before.
 *              The preconditions of Ssa_KeyM_DataServices_DID_0193_SubjectPublicKeyInfo_ReadData also hold.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0193_SerialNumber_ReadData
 * \brief       Passes the serial number to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the serial number shall be stored.
 * \return      RTE_E_OK  Serial number was read successfully.
 *              RTE_E_DataServices_DID_0193_SerialNumber_E_NOT_OK  Reading SerialNumber failed.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data16ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_0193_SerialNumber_ConditionCheckRead must have been called before.
 *              The preconditions of Ssa_KeyM_DataServices_DID_0193_SerialNumber_ConditionCheckRead also hold.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0193_SubjectKeyIdentifier_ConditionCheckRead
 * \brief       Parses Stored Certificate.
 *              Checks if the subject key identifier can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  SubjectKeyIdentifier is valid.
 *              RTE_E_DataServices_DID_0193_SubjectKeyIdentifier_E_NOT_OK  Parsing was not successful or SubjectKeyIdentifier is not valid.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0193_SubjectKeyIdentifier_ReadData
 * \brief       Passes the subject key identifier to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the subject key identifier shall be stored.
 * \return      RTE_E_OK   If data was read.
 *              RTE_E_DataServices_DID_0193_SubjectKeyIdentifier_E_NOT_OK  If data could not be read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data20ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_0193_SubjectKeyIdentifier_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0193_SubjectPublicKeyInfo_ConditionCheckRead
 * \brief       Checks if the subject public key info can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  SubjectPublicKeyInfo is valid.
 *              RTE_E_DataServices_DID_0193_SubjectPublicKeyInfo_E_NOT_OK  SubjectPublicKeyInfo is not valid.
 * \pre         Ssa_KeyM_DataServices_DID_0193_SubjectKeyIdentifier_ReadData must have been called before.
 *              The preconditions of Ssa_KeyM_DataServices_DID_0193_SubjectKeyIdentifier_ReadData also hold.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0193_SubjectPublicKeyInfo_ReadData
 * \brief       Passes the subject public key info to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the subject public key info shall be stored.
 * \return      RTE_E_OK  If data was read.
 *              RTE_E_DataServices_DID_0193_SubjectPublicKeyInfo_E_NOT_OK If data could not be read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_0193_SubjectPublicKeyInfo_ConditionCheckRead must have been called before.
 *              The preconditions of Ssa_KeyM_DataServices_DID_0193_SubjectPublicKeyInfo_ConditionCheckRead also hold.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0194_ECC_CA_Certificate_Identification_ConditionCheckRead
 * \brief       Checks if subject key identifier of backend certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  If request was successful.
 *              RTE_E_DataServices_DID_0194_ECC_CA_Certificate_Identification_E_NOT_OK  If request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

 /*!
 * \fn          Ssa_KeyM_DataServices_DID_0194_ECC_CA_Certificate_Identification_ReadData
 * \brief       Reads subject key identifier of backend certificate and passes it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_DID_0194_ECC_CA_Certificate_Identification_E_NOT_OK  if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data20ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ConditionCheckRead
 * \brief       Does nothing.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  If request was successful.
 *              RTE_E_DataServices_DID_0198_Root_Replacement_Key_E_NOT_OK  If request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0198_Root_Replacement_Key_ReadData
 * \brief       Reads the Trust Model Root Replacement Key.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the key data shall be stored.
 *                        Data must point to a buffer of at least 32 bytes.
 * \return      RTE_E_OK                                                  if key has been read successfully.
 *              RTE_E_DataServices_DID_0198_Root_Replacement_Key_E_NOT_OK if key is not readable.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Certificates_ConditionCheckRead
 * \brief       Checks if the certificates as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate data are available.
 *              RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK if certificate data are not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Certificates_ReadData
 * \brief       Reads the certificate data as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data        Holds the pointer to the memory location where the certificate data shall be stored.
 * \return      RTE_E_OK if certificate data are available.
 *              RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK if certificate data are not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data3006ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_0199_Certificates_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Certificates_ReadDataLength
 * \brief       Reads the length of the certificate data as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the certificate data length shall be stored.
 * \return      RTE_E_OK if certificate data are available.
 *              RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK if certificate data are not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_KeyM_DataServices_DID_0199_Certificates_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Data_Signature_ConditionCheckRead
 * \brief       Checks if the data signature as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  If request was successful.
 *              RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK  If request failed.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Data_Signature_ReadData
 * \brief       Reads the data signature as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data        Holds the pointer to the memory location where the data signature shall be stored.
 * \return      RTE_E_OK if certificate data are available.
 *              RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK if data signature is not available.
 *              RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead
 * \brief       Checks if the ephemeral ECU public key as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if ephemeral ECU public key is available.
 *              RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK if ephemeral ECU public key is not available.
 *              RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData
 * \brief       Reads the ephemeral ECU public key as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data        Holds the pointer to the memory location where the ephemeral ECU public key shall be stored.
 * \return      RTE_E_OK if ephemeral ECU public key is available.
 *              RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK if ephemeral ECU public key is not available.
 *              RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Nonce_ConditionCheckRead
 * \brief       Checks if the nonce as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if nonce is available.
 *              RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK if nonce is not available.
 *              RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_0199_Nonce_ReadData
 * \brief       Reads the nonce as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the nonce shall be stored.
 * \return      RTE_E_OK if nonce is available.
 *              RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK if nonce is not available.
 *              RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_0199_Nonce_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead
 * \brief       Checks if the Trust Model ECU CSR can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if CSR is available.
 *              RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK if CSR is not available.
 *              RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData
 * \brief       Reads the Trust Model ECU CSR.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the CSR shall be stored.
 * \return      RTE_E_OK if CSR is available.
 *              RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK if CSR is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength
 * \brief       Reads the length of the Trust Model ECU CSR.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the CSR shall be stored.
 * \return      RTE_E_OK if CSR is available.
 *              RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK if CSR is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_KeyM_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead
 * \brief       Checks if the Trust Model ECU certificate can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData
 * \brief       Reads the Trust Model ECU certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength
 * \brief       Reads the length of the Trust Model ECU certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_KeyM_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead
 * \brief       Checks if the Trust Model Intermediate CA certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData
 * \brief       Reads the Trust Model Intermediate CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength
 * \brief       Reads the length of the Trust Model Intermediate CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_KeyM_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead
 * \brief       Checks if the Trust Model Backend CA certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData
 * \brief       Reads the Trust Model Backend CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength
 * \brief       Reads the length of the Trust Model Backend CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_KeyM_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead
 * \brief       Checks if the Trust Model Root CA certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019E_Trust_model_Root_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData
 * \brief       Reads the Trust Model Root CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019E_Trust_model_Root_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength
 * \brief       Reads the length of the Trust Model Root CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019E_Trust_model_Root_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_KeyM_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead
 * \brief       Checks if the Trust Model certificates can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019F_Trust_model_Root_certificates_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadData
 * \brief       Reads the Trust Model certificates.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019F_Trust_model_Root_certificates_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data4008ByteType) many bytes.
 *              Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ReadDataLength
 * \brief       Reads the length of the Trust Model certificates.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019F_Trust_model_Root_certificates_E_NOT_OK if certificate is not available.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_KeyM_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead
 * \brief       Checks if the data signature calculated over nonce and ephemeral key within the ReadDataByIdentifier service 'ECU certificate' can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK data is not readable.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_Data_Signature_ReadData
 * \brief       Reads data signature calculated over nonce and ephemeral key within the ReadDataByIdentifier service 'ECU certificate' and passes it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK if data was not read.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead
 * \brief       Checks if the ECU certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK data is not readable.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadData
 * \brief       Reads the ECU certificate and passes it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK if data was not read.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_KeyM_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength
 * \brief       Reads the length of the ECU certificate and passes it to given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK if length was not read.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead
 * \brief       Checks if the ephemeral key generated within the ReadDataByIdentifier service 'ECU certificate' can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK data is not readable.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData
 * \brief       Reads the ephemeral key generated within the ReadDataByIdentifier service 'ECU certificate' and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_KeyM_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead
 * \brief       Checks if the nonce generated within the ReadDataByIdentifier service 'ECU certificate' can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK data is not readable.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_ECU_Certificate_Read_Nonce_ReadData
 * \brief       Reads the nonce generated within the ReadDataByIdentifier service 'ECU certificate' and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK if data was not read.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_KeyM_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ConditionCheckRead
 * \brief       Checks if root certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_Root_CA_Certificate_Read_E_NOT_OK data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadData
 * \brief       Reads root certificate and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Root_CA_Certificate_Read_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_Root_CA_Certificate_Read_ReadDataLength
 * \brief       Reads the length of the root certificate and pass it to given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Root_CA_Certificate_Read_E_NOT_OK if length was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ConditionCheckRead
 * \brief       Checks if checksum of PDU data identifiers can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_E_NOT_OK data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadData
 * \brief       Reads checksum of PDU data identifiers and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data4092ByteType) many bytes.
 *              Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_ReadDataLength
 * \brief       Reads the length of the checksum of PDU data identifiers and pass it to given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_SecOC_PDU_Data_IDs_and_Key_Checksum_Read_Secured_PDU_Data_IDs_and_Key_Checksum_E_NOT_OK if length was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead
 * \brief       Checks if hash value of shared secret can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_DCM_E_PENDING  If request is pending.
 *              RTE_E_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_E_NOT_OK data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ReadData
 * \brief       Reads hash value of shared secret and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_SecOC_Vehicle_Shared_Secret_Hash_Read_SecOC_Vehicle_Shared_Secret_Hash_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data4ByteType) many bytes.
 *              Ssa_KeyM_DataServices_SecOC_Vehicle_Shared_Secret_Hash_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_Init
 * \brief       Initializes internal variables of the key management sub component.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Before this runnable has been executed, no other calls to sub module may be done.
 */

/*!
 * \fn          Ssa_KeyM_MainFunction
 * \brief       Main function of the key management sub component.
 * \details     This function is cyclically called to generate the symmetric SecOc keys, to seed the random number generator, to store
 *              the hash of the car-specific secret and to request for storing the SecOc keys permanently.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Get_Certificate_Entry_Start
 * \brief       Provides the requested certificate entry.
 * \details     -
 * \param[in]   Certificate_Identification_In   Certificate identification
 * \param[in]   In_Certificate_Entry_In         Entry identification
 * \param[in]   OpStatus                        Current operation status.
 * \param[out]  routineInfo_Out                 Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out         Positive Response Code of the routine.
 * \param[out]  Certificate_identification_Out  Certificate identification
 * \param[out]  Out_Certificate_Entry_Out       Entry identification
 * \param[out]  Certificate_Content_Out         Provided entry content.
 * \param[out]  DataLength                      Length of entry content.
 * \param[out]  ErrorCode                       Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                        if routine could be successfully executed.
 *              RTE_E_RoutineServices_Get_Certificate_Entry_E_NOT_OK            if request failed.
 * \pre         The buffer referenced by Certificate_Content_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Inject_Seed
 * \brief       Injects in an authenticated way seed data into the random number generator.
 *              The seed data have to be encrypted by a session key derived by a preceding DH key exchange.
 * \details     -
 * \param[in]   Ephemeral_Backend_Public_Key_In The ephemeral Backend public key.
 * \param[in]   Data_Signature_In               Signature over the encrypted seed and ephemeral key.
 * \param[in]   Encrypted_Seed_In               The encrypted seed data.
 * \param[in]   OpStatus                        Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo                     Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out         Positive Response Code of the routine.
 * \param[in]   DataLength                      Length of encrypted seed stored in Encrypted_Seed_In.
 * \param[out]  ErrorCode                       Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                        if routine could be successfully executed.
 *              RTE_E_RoutineServices_Inject_Seed_E_NOT_OK      if request failed.
 *              RTE_E_RoutineServices_Inject_Seed_DCM_E_PENDING if request is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage
 *              of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Replace_Certificates
 * \brief       Replaces the currently stored ECU Certificate (Only VSM), Backend CA Certificate or Root CA Certificate. The Root CA Certificate may only be replaced together with the Backend CA Certificate. The Backend CA Certificate may only be exchanged together with the ECU Certificate (Only VSM). Replacement of Root or Backend certificate needs a corresponding link certificate. The ECU Certificate is only supported on VSM.
 * \details     -
 * \param[in]   Certificates Holds the pointer to the certificates ( up to 4).
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[in]   DataLength Length of the certificates
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Replace_Certificates_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Replace_Trust_model_Certificates
 * \brief       Replaces the currently stored Trust model ECU Certificate, Trust model Intermediate CA Certificate and Trust model Backend CA Certificate.
 * \details     -
 * \param[in]   Trust_Certificates_In     The new certificates.
 * \param[in]   OpStatus                  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo_Out           Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out   Positive response code of the routine.
 * \param[in]   DataLength                Length of the certificates.
 * \param[out]  ErrorCode                 Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine has been executed successfully.
 *              RTE_E_RoutineServices_Replace_Trust_model_Certificates_E_NOT_OK if an error occurred during execution.
 *              RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Replace_Trust_model_Root_Certificate
 * \brief       Replaces the currently stored Trust Model Root CA Certificate.
 * \details     -
 * \param[in]   signature_new_Root_In   The signature calculated over new the Trust Model Root CA certificate by the
 *                                      replacement authority.
 * \param[in]   signature_In            The signature calculated over the replacement package by Daimler Backend.
 * \param[in]   Certificates_In         The Enhanced Rights certificate authorizing the replacement of the present
 *                                      Trust Model Root CA certificate and the new Trust Model Root CA certificate.
 *                                      Must reference a buffer of at least sizeof(Dcm_Data2004ByteType) many bytes.
 * \param[in]   OpStatus                Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo_Out         Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out Positive response code of the routine.
 * \param[in]   DataLength              Length of the certificates.
 * \param[out]  ErrorCode               Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Routine_Certificate_Self_Check
 * \brief       Verifies the chain of trust of the stored certificates and their compatibility to the private key.
 * \details     -
 * \param[in]   OpStatus              Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo           Execution status of the routine for positive responses.
 * \param[out]  Verification_Result   Positive Response Code of the routine.
 * \param[out]  DataLength            Length of Verification_Result
 * \param[out]  ErrorCode             Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed or OpStatus was DCM_CANCEL.
 *              RTE_E_RoutineServices_Routine_Certificate_Self_Check_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_PENDING if request is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Verification_Result must provide at least sizeof(Dcm_Data18ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption
 * \brief       Starts the generation of the shared secret and individual encryption for the passed ECU certificate. If standard shared secret is still used, a new one is generated.
 * \details     -
 * \param[in]   Nonce Hold the pointer to the nonce.
 * \param[in]   Ephemeral_ECU_Public_Key Holds the pointer to the ephemeral ECU public key.
 * \param[in]   Data_Signature_In Holds the pointer to signature calculated over nonce and ephemeral ECU public key.
 * \param[in]   Target_ECU_Certificate Holds the pointer to the certificate of the target ECU for verifying passed signature.
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[out]  Date_and_Time Holds the pointer to the memory location to store date and time.
 * \param[out]  Tick_Count Holds the pointer to the memory location to store the tick count
 * \param[out]  Tick_Count_Offset Holds the pointer to the memory location to store tick count offset
 * \param[out]  Encrypted_Nonce_and_Shared_Secret Holds the pointer to the memory location to store the encrypted nonce and secret.
 * \param[out]  Ephemeral_VSM_Public_Key Holds the pointer to the ephemeral VSM public key.
 * \param[out]  Data_Signature_Out Holds the pointer to the memory location to store the generated signature.
 * \param[out]  VSM_s_ECU_Certificate Holds the pointer to the memory location to store the VSM certificate.
 * \param[in,out] DataLength In: Length of data passed in buffer Target_ECU_Certificate. Out: Length of data passed in buffer VSM_s_ECU_Certificate.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Date must provide at least sizeof(Dcm_Data20ByteType) many bytes.
 *              The buffer referenced by Date_and_Time must provide at least sizeof(Dcm_Data7ByteType) many bytes.
 *              The buffer referenced by Tick_Count must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Offset must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Encrypted_Nonce_and_Shared_Secret must provide at least sizeof(Dcm_Data80ByteType) many bytes.
 *              The buffer referenced by Ephemeral_VSM_Public_Key must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              The buffer referenced by Data_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by VSM_s_ECU_Certificate must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization
 * \brief       Starts the generation of the shared secret and individual encryption for the passed ECU certificate.
 * \details     -
 * \param[in]   Nonce Hold the pointer to the nonce.
 * \param[in]   Ephemeral_ECU_Public_Key Holds the pointer to the ephemeral ECU public key.
 * \param[in]   Data_Signature_In Holds the pointer to signature calculated over nonce and ephemeral ECU public key.
 * \param[in]   Target_ECU_Certificate Holds the pointer to the certificate of the target ECU for verifying passed signature.
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[out]  Date_and_Time Holds the pointer to the memory location to store date and time.
 * \param[out]  Tick_Count Holds the pointer to the memory location to store the tick count
 * \param[out]  Tick_Count_Offset Holds the pointer to the memory location to store tick count offset
 * \param[out]  Encrypted_Nonce_and_Shared_Secret Holds the pointer to the memory location to store the encrypted nonce and secret.
 * \param[out]  Ephemeral_VSM_Public_Key Holds the pointer to the ephemeral VSM public key.
 * \param[out]  Data_Signature_Out Holds the pointer to the memory location to store the generated signature.
 * \param[out]  VSM_s_ECU_Certificate Holds the pointer to the memory location to store the VSM certificate.
 * \param[in,out] DataLength In: Length of data passed in buffer Target_ECU_Certificate. Out: Length of data passed in buffer VSM_s_ECU_Certificate.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Date must provide at least sizeof(Dcm_Data20ByteType) many bytes.
 *              The buffer referenced by Date_and_Time must provide at least sizeof(Dcm_Data7ByteType) many bytes.
 *              The buffer referenced by Tick_Count must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Offset must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Encrypted_Nonce_and_Shared_Secret must provide at least sizeof(Dcm_Data80ByteType) many bytes.
 *              The buffer referenced by Ephemeral_VSM_Public_Key must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              The buffer referenced by Data_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by VSM_s_ECU_Certificate must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Trust_Model_Generate_Key_Pair
 * \brief       Starts the generation of a new ECU private/public key pair, as specified for RID 0x027B.
 * \details     High level view over the operation of this service in case everything succeeds:
 *                - Reject the service if pre-compile switch SSA_DIAG_SERVICE_TRUST_MODEL_GENERATE_KEY_PAIR is STD_OFF.
 *                - Generate a new Ed25519 key pair into the trust model CSR private key slot.
 *                - Copy the generated public key into the trust model CSR public key slot.
 *                - Generate a CSR which includes the CSR public key.
 *                - Sign the CSR using the live private key.
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out  Provides more details about the routine's outcome in case of a positive
 *                                       diagnostic response code.
 * \param[out]  CSR_Signature_Out  Signature over the returned CSR using the ECU live private key.
 * \param[out]  Trust_Model_ECU_CSR_Out  Certificate Signing request for the newly generated ECU CSR key pair.
 * \param[out]  DataLength  Length of Trust_Model_ECU_CSR_Out in bytes.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_PENDING if request is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage
 *              of shared memory by services called by ProcCtrl.
 *              The buffer referenced by CSR_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by Trust_Model_ECU_CSR_Out must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys
 * \brief       Derives the symmetric key used for SecOc from the shared secret.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret
 * \brief       Generates a new shared secret.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution
 * \brief       Triggers the transmission of a generated shared secret.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
 * \brief       Distributes the car-specific secret at the garage or dealership based on the Unique ECU ID chain.
 * \details     -
 * \param[in]   Date_and_Time_In                      The date and time the target ECU shall be set to.
 * \param[in]   Tick_Count_In                         The tick-count the target ECU shall be set to.
 * \param[in]   Tick_Count_Offset_In                  The tick-count offset the target ECU shall be set to.
 * \param[in]   Encrypted_Nonce_and_Shared_Secret_In  The encrypted nonce and car-specific secret to be decrypted by the target ECU.
 * \param[in]   Ephemeral_VSM_Public_Key_In           The ephemeral VSM public key.
 * \param[in]   Data_Signature_In                     The signature to be verified.
 * \param[in]   Certificates_In                       The VSM's certificates.
 * \param[in]   OpStatus                              Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[in]   routineInfo_Out                       Execution status of the routine for positive responses.
 * \param[in]   Verification_Result_Out               Positive response code of the routine.
 * \param[in]   DataLength                            Length of Certificates_In.
 * \param[in]   ErrorCode                             Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption
 * \brief       Encrypts the car-specific secret at the garage or dealership based on the Unique ECU ID chain.
 *              Generates a new car-specific secret if it is still the default value.
 *              Provides time synchronization information.
 * \details     -
 * \param[in]   Nonce_In                                The nonce
 * \param[in]   Ephemeral_ECU_Public_Key_In             The ephemeral ECU public key.
 * \param[in]   In_Data_Signature_In                    The signature to be verified.
 * \param[in]   In_Certificates_In                      The certificates of the target ECU.
 * \param[in]   OpStatus                                Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo_Out                         Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out                 Positive response code of the routine.
 * \param[out]  Date_and_Time_Out                       Current date and time of VSM.
 * \param[out]  Tick_Count_Out                          Current tick-count of VSM.
 * \param[out]  Tick_Count_Offset_Out                   Current tick-count offset of VSM.
 * \param[out]  Encrypted_Nonce_and_Shared_Secret_Out   The encrypted nonce and car-specific secret.
 * \param[out]  Ephemeral_VSM_Public_Key_Out            The ephemeral VSM public key.
 * \param[out]  Out_Data_Signature_Out                  The generated signature.
 * \param[out]  Out_Certificates_Out                    The VSM's certificates.
 * \param[in,out] DataLength                            In: Length of In_Certificates_In. Out: Length of Out_Certificates_Out.
 * \param[out]  ErrorCode                               Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Date_and_Time_Out must provide at least sizeof(Dcm_Data7ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Out must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Offset_Out must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Encrypted_Nonce_and_Shared_Secret_Out must provide at least sizeof(Dcm_Data80ByteType) many bytes.
 *              The buffer referenced by Ephemeral_VSM_Public_Key_Out must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              The buffer referenced by Out_Data_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by Out_Certificates_Out must provide at least sizeof(Dcm_Data3006ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_KeyM_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization
 * \brief       Encrypts the car-specific secret at the garage or dealership based on the Unique ECU ID chain.
 *              Never generates a new car-specific secret.
 *              Provides time synchronization information.
 * \details     -
 * \param[in]   Nonce_In                                The nonce
 * \param[in]   Ephemeral_ECU_Public_Key_In             The ephemeral ECU public key.
 * \param[in]   In_Data_Signature_In                    The signature to be verified.
 * \param[in]   In_Certificates_In                      The certificates of the target ECU.
 * \param[in]   OpStatus                                Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo_Out                         Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out                 Positive response code of the routine.
 * \param[out]  Date_and_Time_Out                       Current date and time of VSM.
 * \param[out]  Tick_Count_Out                          Current tick-count of VSM.
 * \param[out]  Tick_Count_Offset_Out                   Current tick-count offset of VSM.
 * \param[out]  Encrypted_Nonce_and_Shared_Secret_Out   The encrypted nonce and car-specific secret.
 * \param[out]  Ephemeral_VSM_Public_Key_Out            The ephemeral VSM public key.
 * \param[out]  Out_Data_Signature_Out                  The generated signature.
 * \param[out]  Out_Certificates_Out                    The VSM's certificates.
 * \param[in,out] DataLength                            In: Length of In_Certificates_In. Out: Length of Out_Certificates_Out.
 * \param[out]  ErrorCode                               Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Date_and_Time_Out must provide at least sizeof(Dcm_Data7ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Out must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Offset_Out must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Encrypted_Nonce_and_Shared_Secret_Out must provide at least sizeof(Dcm_Data80ByteType) many bytes.
 *              The buffer referenced by Ephemeral_VSM_Public_Key_Out must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              The buffer referenced by Out_Data_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by Out_Certificates_Out must provide at least sizeof(Dcm_Data3006ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/**********************************************************************************************************************
 *  RightsM
 *********************************************************************************************************************/

/*!
 * \fn          Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess
 * \brief       Provides the serial number of the diagnostic authentication certificate.
 * \details     This function provides the serial number of the diagnostic authentication certificate for the diagnostic user
 *              which successfully run the security access last.
 * \param[out]  serialNumber   Serial number of the diagnostic authentication certificate.
 * \return      RTE_E_OK                                 Request successful.
 *              RTE_E_Ssa_RightsM_Certificate_E_NOT_OK   Request failed. No successful security access has been run yet.
 * \pre         The buffer referenced by serialNumber must provide at least sizeof(RightsM_SerialNumberType) many bytes.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_Com_ReceiveBroadcastAuthentication
 * \brief       Handles the reception of a authentication broadcast message.
 * \details     This function handles the reception of a authentication broadcast message. If the received broadcast
 *              message is valid the ECU becomes (centrally) authenticated.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_RightsM_CsmCallbackNotification_RandomGenerate
 * \brief       Callback Notification from CSM.
 * \details     Notifies the RightsM that a random generate used for generating a nonce has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess
 * \brief       Callback Notification from CSM.
 * \details     Notifies the RightsM that a signature verify job used for the security access has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_CsmCallbackNotification_SignatureVerify
 * \brief       Callback Notification from CSM.
 * \details     Notifies the RightsM that a signature verify job used for verifying the proof of ownership
 *              during diagnostic tester authentication has finished.
 * \param[in]   result    Contains the result of the cryptographic operation.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead
 * \brief       Checks if hash of basic access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                              Request successful.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK   Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData
 * \brief       Reads hash of basic access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the hash data shall be copied to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead
 * \brief       Checks if the Candela file major version of the basic access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                                            Request successful.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK   Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData
 * \brief       Reads the Candela file major version of the basic access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the major version shall be written to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK if data was not read.
 * \pre         Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead
 * \brief       Checks if the Candela file minor version of the basic access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                                            Request successful.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK   Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData
 * \brief       Reads the Candela file minor version of the basic access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the minor version shall be written to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK if data was not read.
 * \pre         Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead
 * \brief       Checks if the Candela file patch version of the basic access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                                            Request successful.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK   Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData
 * \brief       Reads the Candela file patch version of the basic access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the patch version shall be written to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK if data was not read.
 * \pre         Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead
 * \brief       Checks if the generation time GTC of the basic access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                                      Request successful.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK    Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData
 * \brief       Reads the generation time GTC of the basic access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the generation time GTC shall be copied to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data15ByteType) many bytes.
 *              Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead
 * \brief       Checks if hash of ECU individual access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                              Request successful.
 *              RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK   Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData
 * \brief       Reads hash of ECU individual access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the hash data shall be copied to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead
 * \brief       Checks if the Candela file major version of the ECU individual access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK    if data is readable.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_E_NOT_OK data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData
 * \brief       Reads the Candela file major version of the ECU individual access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the major version shall be written to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_E_NOT_OK if data was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead
 * \brief       Checks if the Candela file minor version of the ECU individual access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK    if data is readable.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_E_NOT_OK if data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData
 * \brief       Reads the Candela file minor version of the ECU individual access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the minor version shall be written to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_E_NOT_OK if data was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead
 * \brief       Checks if the Candela file patch version of the ECU individual access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK    if data is readable.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_E_NOT_OK If data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData
 * \brief       Reads the Candela file patch version of the ECU individual access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the patch version shall be written to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_E_NOT_OK if data was not read.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead
 * \brief       Checks if the generation time GTC of the ECU individual access control list can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK    If data is readable.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_E_NOT_OK if data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData
 * \brief       Reads the generation time GTC of the ECU individual access control list.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the generation time GTC shall be copied to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data15ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead
 * \brief       Checks if the current diagnostic user-role can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  if data is readable.
 *              RTE_E_DataServices_DID_018C_Cebas_UserRole_E_NOT_OK if data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData
 * \brief       Reads the current diagnostic user-role and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the issuer shall be copied to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_018C_Cebas_UserRole_E_NOT_OK if data was not read. Invalid diagnostic channel.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead
 * \brief       Checks if the issuer of the current diagnostic authentication certificate can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK    if data is readable.
 *              RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK if data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData
 * \brief       Reads the issuer of the current diagnostic authentication certificate.
 * \details     This function reads the issuer of the current diagnostic authentication certificate if the diagnostic user or tester is locally
 *              authenticated, else it reads the subject of the backend certificate.
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the issuer shall be copied to.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data15ByteType) many bytes.
 *              Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead
 * \brief       Checks if the serial number of the current diagnostic authentication certificate can be read.
 * \details     Reads the serial number of the current diagnostic authentication certificate.
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                                                                                                    Request successful.
 *              RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK   Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData
 * \brief       Reads the serial number of current diagnostic authentication certificate.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Pointer to the buffer where the serial number shall be copied to.
 * \return      RTE_E_OK                                                                                                                                    Request successful.
 *              RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK   Request failed.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data16ByteType) many bytes.
 *              Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead or
 *              Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength
 * \brief       Reads the length of the serial number of current diagnostic authentication certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Pointer to the buffer where the data length shall be written to.
 * \return      RTE_E_OK                                                                                                                                    Request successful.
 *              RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK   Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState
 * \brief       Reads the diagnostic channel and the authentication state.
 * \details     -
 * \param[out]  diagChanAndAuthStatus   Bit 0-3: Diagnostic Channel
 *                                      Bit 4-6: Reserved
 *                                      Bit 7  : Diagnostic test tool authenticated on this channel: 0=false, 1=true
 *                                      0xFF if there is no valid current diagnostic channel.
 * \return      RTE_E_OK    Request successful.
 *              RTE_E_RightsM_DiagnosticChannel_E_NOT_OK Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole
 * \brief       Provides the diagnostic user role for the current diagnostic channel.
 * \details     -
 * \param[out]  userRole  The diagnostic user role for the current diagnostic channel, ANYBODY if there is no current diagnostic channel.
 * \return      RTE_E_OK  Request successful.
 *              RTE_E_RightsM_DiagnosticChannel_E_NOT_OK Request failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask
 * \brief       Reads the diagnostic user role bit mask.
 * \details     -
 * \param[out]  userRolesBitMask  The diagnostic user roles bit mask.
 *                                Zero if no diagnostic user or tester is authenticated.
 * \return      RTE_E_OK          Request successful.
 *              RTE_E_RightsM_DiagnosticChannel_E_NOT_OK Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus
 * \brief       Provides the post production status.
 * \details     -
 * \param[out]  status    The post production status: 'Deactivated', 'Irreversibly Activated' or 'Reversibly Activated'
 * \return      RTE_E_OK  Request successful.
 *              RTE_E_RightsM_DiagnosticChannel_E_NOT_OK Request failed.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole
 * \brief       Reads the currently active diagnostic user role.
 * \details     This function provides the currently active diagnostic user role for the diagnostic user defined by the
 *              given source address.
 * \param[in]   SourceAddress Source address of diagnostic user resp. tester.
 * \param[out]  UserRole      The currently active diagnostic user role.
 *                            ANYBODY (=0) if no diagnostic user or tester is authenticated for the given source address.
 * \return      RTE_E_OK      Request successful.
 *              RTE_E_RightsM_DiagnosticFirewall_E_NOT_OK Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted
 * \brief       Checks whether for the given diagnostic service enhanced access right has been granted.
 * \details     This function checks whether for the given diagnostic service and the given source address enhanced
 *              access right has been granted.
 * \param[in]   SourceAddress       Source address of diagnostic user resp. tester.
 * \param[in]   SID                 Service identifier of the requested diagnostic service.
 * \param[out]  AccessRightGranted  TRUE          Enhanced access right is granted.
                                    FALSE         Enhanced access right is not granted.
 * \return      RTE_E_OK      Request successful.
 *              RTE_E_RightsM_DiagnosticFirewall_E_NOT_OK Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_DiagnosticSessionChangeIndication
 * \brief       Processes a changed diagnostic session.
 * \details     This function processes a changed diagnostic session and is to be called on entry of mode "default session". It ensures that
 *              the authenticated state is left when an S3 timeout occurs.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier
 * \brief       Verifies a subject key identifier.
 * \details     This function verifies the provided subject key identifier against the target subject key identifier provided by a previously obtained SecOcIs certificate.
 * \param[in]
 * \return      RTE_E_OK                                Request successful (subject key identifier is accepted by RightsM).
 *              RTE_E_RightsM_EnhancedRights_E_NOT_OK   Request failed (subject key identifier is rejected by RightsM).
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_Init
 * \brief       Initializes internal variables of the rights management sub component.
 * \details     This function initializes internal variables of the rights management sub component.
 *              If a soft reset is detected authentication persists.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_MainFunction
 * \brief       Main function of the rights management sub component.
 * \details     This function is cyclically called to handle timeout. In case of VSM this function cyclically sends the broadcast authentication message.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_Nonce_Destroy
 * \brief       Destroys the nonce.
 * \details     This function destroys the nonce that is persistently stored in the RightsM by overwriting it with random data.
 * \return      RTE_E_OK                        Request successful. Nonce has been destroyed.
 *              RTE_E_RightsM_Nonce_E_PENDING   Request is pending.
 *              RTE_E_RightsM_Nonce_E_NOT_OK    Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_Nonce_Get
 * \brief       Reads the nonce.
 * \details     This function provides the stored nonce if there is a valid one. If a newly generated nonce is requested this function provides a newly
 *              generated nonce only if there is no stored, valid nonce. A generated nonce becomes invalid 24 hours after it has been generated.
 * \param[in]   generateNew   TRUE:    A new nonce is generated if there is no valid available.
 *                            FALSE:   A new nonce is not generated if there is no valid available
 * \param[out]  nonce         Pointer to the buffer where the nonce shall be stored to.
 * \return      RTE_E_OK                      Request successful (nonce was read or generated).
 *              RTE_E_RightsM_Nonce_E_NOT_OK  Request failed (no valid nonce was available and no nonce was generated).
 * \pre         This service may only be called by services called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory.
 *              The buffer referenced by nonce must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn            Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start
 * \brief         Authenticates a diagnostic user or tester against the ECU to obtain the appropriate access rights (authorization).
 * \details       -
 * \param[in]     Configuration                             Bit 0: Uni- or bidirectional Authentication: 0=unidirectional, 1=bidirectional, Bit 1-7: Reserved.
 *                Task                                      0x00: Initiate Authentication, 0x01: Verify certificate ownership , 0x02 De-authenticate.
 *                Challenge_Certificate_Proof_of_Ownership  Pointer to challenge tester and diagnostic authentication certificate or proof of ownership tester.
 *                                                          Must reference a buffer of at least sizeof(Dcm_Data4004ByteType) many bytes.
 *                OpStatus                                  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]    routineInfo                               Execution status of the routine in case of a positive response.
 *                Verification_Result                       Positive response code of the routine.
 *                Authentication_Result                     Pointer to the memory location where the challenge ECU, theECU certificate and the proof of ownership ECU shall be stored.
 * \param[in,out] DataLength                                In: Length in bytes of Challenge_Certificate_Proof_of_Ownership, Out: Length in bytes of Authentication_Result.
 * \param[out]    ErrorCode                                 Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return        RTE_E_OK                                                                            Request successful.
 *                RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK       Request failed.
 *                RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING  Requested service is pending.
 * \pre           This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *                The buffer referenced by Authentication_Result must provide at least sizeof(Dcm_Data3006ByteType) many bytes.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE|FALSE
 */

/*!
 * \fn          Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start
 * \brief       Request enhanced access rights.
 * \details     This function requests further access rights beyond the ones which are granted by the basic and ECU individual access control list after
 *              authentication of the diagnostic user or tester.
 * \param[in]   Enhanced_Rights_Certificate Pointer to the enhanced rights certificate.
 *              Must reference a buffer of at least sizeof(Dcm_Data2002ByteType) many bytes.
 *              OpStatus                    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo                 Execution status of the routine in case of a positive response.
 *              Verification_Result         Positive response code of the routine.
 * \param[in]   DataLength                  Length of Enhanced_Rights_Certificate in bytes.
 * \param[out]  ErrorCode                   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                          Request successful.
 *              RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK      Request failed.
 *              RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING Requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start
 * \brief       Initiates time synchronization.
 * \details     This function initiates time synchronization by requesting a one-time challenge (nonce)
 * \param[in]   OpStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  routineInfo Execution status of the routine in case of a positive response.
 *              Nonce       Pointer to the memory location where the nonce shall be stored.
 *              ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                                              Request successful.
 *              RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK       Request failed.
 *              RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING  Requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Nonce must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults
 * \brief       Gets the current post production status.
 * \details     -
 * \param[in]   OpStatus                  Current operation status.
 * \param[out]  routineInfo_Out           Execution status of the routine in case of a positive response.
 * \param[out]  Post_Production_Flag_Out  The current post production status: 'deactivated', 'irreversibly activated' or 'reversibly activated'.
 * \param[out]  ErrorCode                 Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                            Request succeeded.
 *              RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK       Request failed.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start
 * \brief       Sets the post production status to either 'irreversibly activated' or 'reversibly activated'.
 * \details     -
 * \param[in]   In_Post_Production_Flag_In    The post production status to be set: Only status 'irreversibly activated' or 'reversibly activated' are allowed.
 * \param[in]   OpStatus                      Current operation status.
 * \param[out]  routineInfo_Out               Execution status of the routine in case of a positive response.
 * \param[out]  Out_Post_Production_Flag_Out  The current post production status.
 * \param[out]  ErrorCode                     Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                            Request succeeded.
 *              RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK       Request failed.
 *              RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_PENDING  Request is pending.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE if 'irreversibly activated' is set, else FALSE
 */

/*!
 * \fn          Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop
 * \brief       Sets the post production status to 'deactivated'.
 * \details     -
 * \param[in]   In_Post_Production_Flag_In    The post production status to be set: Only status 'deactivated' is allowed.
 * \param[in]   OpStatus                      Current operation status.
 * \param[out]  routineInfo_Out               Execution status of the routine in case of a positive response.
 * \param[out]  Out_Post_Production_Flag_Out  The current post production status.
 * \param[out]  ErrorCode                     Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                            Request succeeded.
 *              RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK       Request failed.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_RightsM_SecurityAccess_CompareKey
 * \brief       Verifies the passed key against the previously generated seed.
 * \details     -
 * \param[in]   secLevel    The security level to be accessed.
 *                          secLevel = (<sub-function id of service 0x27> + 1) / 2
 *                          It must not exceed 0x30.
 *              key         Pointer to the key (signature) to be verified.
 *              opStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                      Request successful or canceled.
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK   Request failed.
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING  Request pending. Try again with operation status Pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_RightsM_SecurityAccess_GetSeed
 * \brief       Provides a seed for the requested security level.
 * \details     This function is used during security access to generate a seed for a requested security level.
 * \param[in]   secLevel    The security level to be accessed.
 *                          secLevel = (<sub-function id of service 0x27> + 1) / 2
 *                          It must not exceed 0x30.
 *              opStatus    Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  seed        Pointer to the memory location where the seed shall be stored.
 *              ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                      Request successful or canceled.
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK   Request failed.
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING  Request pending. Try again with operation status Pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by seed must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_RightsM_ServiceRequestNotification_Confirmation
 * \brief       Confirms that the processing of the diagnostic service is finished.
 * \details     This function confirms that the processing of the diagnostic service is finished.
 *              It invalidates the current diagnostic channel id.
 * \param[in]   SID                Identifier of the requested diagnostic service.
 *              ReqType            Type of the request.
 *              SourceAddress      Source address of tester.
 *              ConfirmationStatus Current confirmation status.
 * \return      RTE_E_OK    Request successful.
 *              RTE_E_ServiceRequestNotification_E_NOT_OK Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_RightsM_ServiceRequestNotification_Indication
 * \brief       Validates the incoming diagnostic service.
 * \details     This function checks the access rights of the incoming diagnostic service with regard to the user role
 *              of the authenticated diagnostic user or tester. If access right is not granted the service request is aborted.
 * \param[in]   SID           Identifier of the requested diagnostic service.
 *              RequestData   Pointer to the whole data of the current request.
 *              DataSize      Length of RequestData in bytes.
 *              ReqType       Type of the request.
 *              SourceAddress Source address of tester. The diagnostic channel ID is derived from it.
 * \param[out]  ErrorCode     Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                    Request successful (access is granted).
 *              RTE_E_ServiceRequestNotification_E_NOT_OK   Request failed (access is not granted).
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/**********************************************************************************************************************
 *  SecLog
 *********************************************************************************************************************/
/*!
 * \fn          Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData
 * \brief       Reads SecOc data ID and passes it to the given data parameter.
 * \details     -
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_CSDataServices_DID_018B_SecOcDataID_E_NOT_OK data is not readable.
 * \pre         The buffer referenced by Data must provide at least sizeof(DataArrayType_uint8_2) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
 * \brief       Checks if current counter values of security event log can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK data is not readable.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
 * \brief       Reads the current counter values of the security event log and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data1024ByteType) many bytes.
 *              Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
 * \brief       Reads the length of the current counter values of the security event log and passes it to the given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK if length was not read.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead
 * \brief       Checks if security event log can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData
 * \brief       Reads security event log and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING if requested service is pending.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data4092ByteType) many bytes.
 *              Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE|FALSE
 */

/*!
 * \fn          Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength
 * \brief       Reads the length of the security event log and pass it to given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status. OpStatus DCM_CANCEL is not handled.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK if length was not read.
 * \pre         This service may only be called by Ssa_ProcCtrl. Otherwise, data consistency is not ensured due to usage of shared memory by services called by ProcCtrl.
 *              Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_IgnitionStatusChanged
 * \brief       Notifies a change in the ignition status, if status switches to I_C03_ISW_STAT_IGN_ON it triggers the storing of the security event log data.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_Init
 * \brief       Initializes internal variables of the security logging sub component.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Before this runnable has been executed, no other calls to sub module may be done.
 */

/*!
 * \fn          Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083
 * \brief       Notifies that this event is cleared, or that the operation (monitoring) cycle restarts.
 *              Clears counter for failed PDU MAC verifications.
 * \details     -
 * \param[in]   InitMonitorReason Init monitor reason.
 * \return      RTE_E_OK always.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess
 * \brief       Logs a security event which is related to an authorization by security access.
 * \details     -
 * \param[in]   diagChanAuthStatus Current diagnostic channel and authentication status.
 * \param[in]   securityLevel Requested security level.
 * \param[in]   securityAccessResult Result of security access.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_AuthorizationBySecurityAccess_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime
 * \brief       Logs a security event which is related to a change of the tick-count of date and time.
 * \details     -
 * \param[in]   contextDateTimeChange Context in which the time was changed.
 * \param[in]   deltaTimeChange Delta of the time change in ticks.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_ChangeVin
 * \brief       Logs a security event which is related to the a change of the VIN.
 * \details     -
 * \param[in]   newVin Holds a pointer to the new VIN.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_ChangeVinEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_EcuIndividualAclReplacement
 * \brief       Logs a security event which is related to a replacement of the ECU individual access control list.
 * \details     -
 * \param[in]   newAclVersion Holds a pointer to the new access control list version.
 * \param[in]   compatibility 0 - List is compatible, 1 List is incompatible.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_EcuIndividualAclReplacementEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_FailedCertificateVerification
 * \brief       Logs a security event which is related to a failed certificate verification.
 * \details     -
 * \param[in]   pkiRole Role of the verified certificate.
 * \param[in]   validationResult Result of the verification.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_FailedCertVerificationEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_FailedSecOcMacVerification
 * \brief       Notifies about a failed SecOC Mac verification, collects the data and creates a security log event.
 * \details     -
 * \param[in]   verificationStatus Status of the SecOC verification.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_VerificationStatusIndication_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast
 * \brief       Notifies about a failed Mac verification of a secure broadcast message, collects the data and creates a security log event.
 * \details     -
 * \param[in]   verificationStatus Status of the verification.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_RightsManagement
 * \brief       Logs a security event which is related to a rejected diagnostic request.
 * \details     -
 * \param[in]   diagChanAuthStatus Current diagnostic channel and authentication status.
 * \param[in]   serviceId Requested diagnostic service id.
 * \param[in]   subFunction Requested diagnostic sub function.
 * \param[in]   dataIdOrRoutineId Requested diagnostic data or routine id.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_RightsManagementEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot
 * \brief       Logs a security event which is related to a secure or authenticated boot attempt.
 * \details     -
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_SecureBootOrAuthenticatedBootEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_SignatureVerification
 * \brief       Logs a security event which is related to a signature verification.
 * \details     -
 * \param[in]   parg0 Kind of the signature verification.
 * \param[in]   verificationResult Result of the signature verification.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_SignatureVerificationEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights
 * \brief       Logs a security event which is related to a successful authentication or
 *              to an enhancement of the diagnostic rights for the passed role.
 * \details     -
 * \param[in]   diagChanAuthStatus Current diagnostic channel and authentication status.
 * \param[in]   pkiRole Current role of authenticated certificate.
 * \param[in]   authenticationContent Pointer to the authentication data.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_SuccessfulAuthAndEnhanceRights_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_SuccessfulCertificateVerification
 * \brief       Logs a security event which is related to a successful certificate verification.
 * \details     -
 * \param[in]   certId SerialNumber of the affected certificate with size SSA_SIZEOF_SERIALNUMBER.
 * \param[in]   pkiRole Current role of verified certificate.
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_SuccessfulCertVerificationEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution
 * \brief       Logs a security event which is related to a successful diagnostic service execution.
 * \details     -
 * \param[in]   parg0 UID of diagnostic service
 * \param[in]   additionalInfo Additional information to the diagnostic service
 * \return      RTE_E_OK if data was logged.
 *              RTE_E_SecLog_ChangeVinEvent_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_SecLog_MainFunction
 * \brief       Cyclically called to write log to nv-memory.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/**********************************************************************************************************************
 *  TimeM
 *********************************************************************************************************************/

/*!
 * \fn          Ssa_TimeM_Com_ReceiveRealTimeOffset
 * \brief       Notifies about the reception of a real time offset broadcast. Catches data and stores new real time offset.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_TimeM_DataServices_DID_018A_TickCount_ConditionCheckRead
 * \brief       Checks if tick-count can be read.
 * \details     -
 * \param[in]   OpStatus   Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK   if data is readable.
 *              RTE_E_DataServices_DID_018A_TickCount_E_NOT_OK if data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData
 * \brief       Reads the tick-count.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read tick-count shall be stored.
 * \return      RTE_E_OK    if data was read.
 *              RTE_E_DataServices_DID_018A_TickCount_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data6ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ConditionCheckRead
 * \brief       Checks if the date and time reference of the real-time offset can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  if data is readable.
 *              RTE_E_DataServices_DID_018D_Real_Time_Offset_E_NOT_OK if data is readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData
 * \brief       Reads the date and time reference of the real-time offset.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the read date and time reference shall be stored.
 * \return      RTE_E_OK  if data was read.
 *              RTE_E_DataServices_DID_018D_Real_Time_Offset_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data15ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ConditionCheckRead
 * \brief       Checks if the tick-count offset of the real-time offset can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_DID_018D_TickCount_E_NOT_OK Request if data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData
 * \brief       Reads the tick-count offset of the real-time offset.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the read tick-count offset shall be stored.
 * \return      RTE_E_OK  if data was read.
 *              RTE_E_DataServices_DID_018D_TickCount_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ConditionCheckRead
 * \brief       Checks if system time can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_E_NOT_OK data is not readable.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData
 * \brief       Reads system time and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_E_NOT_OK if data was not read.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data15ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_Init
 * \brief       Initializes internal variables of the time management sub component.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Before this runnable has been executed, no other calls to sub module may be done.
 */

/*!
 * \fn          Ssa_TimeM_Mainfunction
 * \brief       Cyclically called to increment timer. In case of VSM, functions sends tick count cyclically.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_PowernetMgmtStateChanged
 * \brief       Notifies a change of the powernet management state, if notified state is PRE_OPN
 *              storing the local tick-count to NvM is requested.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_RealTime_Compare
 * \brief       Compares to passed real time with each other.
 * \details     -
 * \param[in]   t1 Holds the pointer to the first real time.
 * \param[in]   compareOp TIMEM_IS_LESS or TIMEM_IS_GREATER
 * \param[in]   t2 Holds the pointer to the second real time.
 * \param[out]  result Holds the pointer to the memory location where the result is stored.
 * \return      RTE_E_OK if compare was successful.
 *              RTE_E_TimeM_RealTime_E_NOT_OK otherwise.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_RealTime_Get
 * \brief       Gets the current real time.
 * \details     -
 * \param[out]  realTime Holds the pointer to the memory location where the real time shall be stored.
 * \return      RTE_E_OK if real time was read.
 *              RTE_E_TimeM_RealTime_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_RealTime_Set
 * \brief       Sets a new real time. The real time is binded to the current tick count. In case of VSM, new real time will be broadcasted.
 * \details     -
 * \param[in]   realTime Holds the pointer to the new real time.
 * \param[in]   changeReason Reason for the change of the real time.
 * \return      RTE_E_OK if real time was set.
 *              RTE_E_TimeM_RealTime_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_ReceiveChangeTickCountEvent
 * \brief       Notifies of the reception of ChangeTickCount event. Reads data and uses it for writing a security log entry.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_TimeM_ReceiveRealTimeOffsetCorrectionRequest
 * \brief       Notifies of the reception of a real-time offset correction request.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      VSM and GW only.
 */

/*!
 * \fn          Ssa_TimeM_TickCount_Get
 * \brief       Reads the current tick count and pass it to given parameter.
 * \details     -
 * \param[out]  tickCount Holds the pointer to a memory location where the tick count is stored.
 * \return      RTE_E_OK  Tickcount read successfully.
 *              RTE_E_TimeM_TickCount_E_NOT_OK Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_TimeRawData_ResetLocalTickCount
 * \brief       Resets the local tick-count.
 * \details     -
 * \return      RTE_E_OK        always if ECU type is not VSM.
 *              E_NOT_OK        always if ECU type is VSM.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_TimeRawData_Get
 * \brief       Reads the current tick count, date and time and its offset and pass it to the given data parameter.
 * \details     -
 * \param[out]  dateTimeOffset  Holds the pointer to a memory location where the date and time is stored.
 * \param[out]  tickCountOffset  Holds the pointer to a memory location where the tick count offset is stored.
 * \param[out]  tickCount  Holds the pointer to a memory location where the tick count is stored.
 * \return      RTE_E_OK If ECU type is VSM and time data was written successfully.
 *              RTE_E_TimeM_TimeRawData_E_NOT_OK If ECU type is not VSM or if writing time data failed.
 * \pre         The buffer referenced by dateTimeOffset must provide at least sizeof(Ssa_Data7ByteType) many bytes.
                The buffer referenced by tickCountOffset must provide at least sizeof(Ssa_Data5ByteType) many bytes.
                The buffer referenced by tickCount must provide at least sizeof(Ssa_Data5ByteType) many bytes.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_TimeM_TimeRawData_Set
 * \brief       Writes the current tick count, date and time and its offset.
 * \details     -
 * \param[in]   dateTimeOffset  Holds the pointer to the date and time.
 * \param[in]   tickCountOffset Holds the pointer to tick count offset.
 * \param[in]   tickCount       Holds the pointer to tick count.
 * \return      RTE_E_OK        always if ECU type is not VSM.
 *              E_NOT_OK        always if ECU type is VSM.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/**********************************************************************************************************************
 *  ProcCtrl
 *********************************************************************************************************************/

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead
 * \brief       Checks if the SecOC PDU Data-IDs and their corresponding Key CMACs can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData
 * \brief       Reads the SecOC PDU Data-IDs and their corresponding Key CMACs and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data4092ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength
 * \brief       Reads the length of the SecOC PDU Data-IDs and their corresponding Key CMACs and passes it to the given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING if request is pending.
 * \pre         Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead
 * \brief       Checks if generated random number can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  if data is readable.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING  if data is not readable.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK  if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData
 * \brief       Reads generated random number and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the random number shall be stored.
 * \return      RTE_E_OK  if data is readable.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING if request is pending.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK if data is not readable.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead must have been called before.
 *              Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead
 * \brief       Checks if generated random number result can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK  if data is readable.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING  if data is not readable.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK  if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData
 * \brief       Generates a random number and passes the status (result) of the random number generation to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the status of the random number generation shall be stored.
 * \return      RTE_E_OK  if data is readable.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING if request is pending.
 *              RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK if data is not readable.
 * \pre         Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead
 * \brief       Checks if the certificates as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate data are available.
 *              RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK if certificate data are not available.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData
 * \brief       Reads the certificate data as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Holds the pointer to the memory location where the certificate data shall be stored.
 * \return      RTE_E_OK if certificate data are available.
 *              RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK if certificate data are not available.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data3006ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength
 * \brief       Reads the length of the certificate data as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the certificate data length shall be stored.
 * \return      RTE_E_OK if certificate data are available.
 *              RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK if certificate data are not available.
 * \pre         Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead
 * \brief       Checks if the data signature as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                               If the data signature is available.
 *              RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK    If the data signature is not available.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData
 * \brief       Checks if the data signature as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                               If the data signature is available.
 *              RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK    If the data signature is not available.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead
 * \brief       Checks if the ephemeral ECU public key as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if ephemeral ECU public key is available.
 *              RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK if ephemeral ECU public key is not available.
 *              RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING if requested service is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData
 * \brief       Reads the ephemeral ECU public key as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  Data        Holds the pointer to the memory location where the ephemeral ECU public key shall be stored.
 * \return      RTE_E_OK if ephemeral ECU public key is available.
 *              RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK if ephemeral ECU public key is not available.
 *              RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING if requested service is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead
 * \brief       Checks if the nonce as part of the service TrustModelRequestEphemeralPublicKey can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if nonce is available.
 *              RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK if nonce is not available.
 *              RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING if requested service is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData
 * \brief       Reads the nonce as part of the service TrustModelRequestEphemeralPublicKey.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the nonce shall be stored.
 * \return      RTE_E_OK if nonce is available.
 *              RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK if nonce is not available.
 *              RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING if requested service is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead
 * \brief       Checks if the Trust Model ECU CSR can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if CSR is available.
 *              RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK if CSR is not available.
 *              RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING if requested service is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData
 * \brief       Reads the Trust Model ECU CSR.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the CSR shall be stored.
 * \return      RTE_E_OK if CSR is available.
 *              RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK if CSR is not available.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength
 * \brief       Reads the length of the Trust Model ECU CSR.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the CSR shall be stored.
 * \return      RTE_E_OK if CSR is available.
 *              RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK if CSR is not available.
 * \pre         Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead
 * \brief       Checks if the Trust Model ECU certificate can be read.
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK if certificate is not available.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData
 * \brief       Reads the Trust Model ECU certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK if certificate is not available.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength
 * \brief       Reads the length of the Trust Model ECU certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK if certificate is not available.
 * \pre         Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead
 * \brief       Checks if the Trust Model Intermediate CA certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData
 * \brief       Reads the Trust Model Intermediate CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength
 * \brief       Reads the length of the Trust Model Intermediate CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead
 * \brief       Checks if the Trust Model Backend CA certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData
 * \brief       Reads the Trust Model Backend CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength
 * \brief       Reads the length of the Trust Model Backend CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead
 * \brief       Checks if the Trust Model Root CA certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019E_Trust_model_Root_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData
 * \brief       Reads the Trust Model Root CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019E_Trust_model_Root_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength
 * \brief       Reads the length of the Trust Model Root CA certificate.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019E_Trust_model_Root_CA_Certificate_E_NOT_OK if certificate is not available.
 * \pre         Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead
 * \brief       Checks if the Trust Model certificates can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019F_Trust_model_Root_certificates_E_NOT_OK if certificate is not available.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData
 * \brief       Reads the Trust Model certificates.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data      Holds the pointer to the memory location where the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019F_Trust_model_Root_certificates_E_NOT_OK if certificate is not available.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data4008ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength
 * \brief       Reads the length of the Trust Model certificates.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the length of the certificate shall be stored.
 * \return      RTE_E_OK if certificate is available.
 *              RTE_E_DataServices_DID_019F_Trust_model_Root_certificates_E_NOT_OK if certificate is not available.
 * \pre         Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead
 * \brief       Checks if the data signature calculated over nonce and ephemeral key within the ReadDataByIdentifier service 'ECU certificate' can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ReadData
 * \brief       Reads data signature calculated over nonce and ephemeral key within the ReadDataByIdentifier service 'ECU certificate' and passes it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead
 * \brief       Checks if the ECU certificate can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadData
 * \brief       Reads the ECU certificate and passes it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength
 * \brief       Reads the length of the ECU certificate and passes it to given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK if length was not read.
 *              RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING if request is pending.
 * \pre         Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead
 * \brief       Checks if the ephemeral key generated within the ReadDataByIdentifier service 'ECU certificate' can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData
 * \brief       Reads the ephemeral key generated within the ReadDataByIdentifier service 'ECU certificate' and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead
 * \brief       Checks if the nonce generated within the ReadDataByIdentifier service 'ECU certificate' can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ReadData
 * \brief       Reads the nonce generated within the ReadDataByIdentifier service 'ECU certificate' and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
 * \brief       Checks if current counter values of security event log can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
 * \brief       Reads the current counter values of the security event log and passes it to the given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data1024ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
 * \brief       Reads the length of the current counter values of the security event log and passes it to the given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK if length was not read.
 *              RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING if request is pending.
 * \pre         Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead
 * \brief       Checks if security event log can be read.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if data is readable.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK data is not readable.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData
 * \brief       Reads security event log and pass it to given data parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  Data  Holds the pointer to the memory location where the read data shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK if data was not read.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Data must provide at least sizeof(Dcm_Data4092ByteType) many bytes.
 *              Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength
 * \brief       Reads the length of the security event log and pass it to given length parameter.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  DataLength  Holds the pointer to the memory location where the read length shall be stored.
 * \return      RTE_E_OK if data was read.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK if length was not read.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING if request is pending.
 * \pre         Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead must have been called before.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn            Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester
 * \brief         Authenticates a diagnostic user or tester against the ECU to obtain the appropriate access rights (authorization).
 * \details       -
 * \param[in]     Configuration                             Bit 0: Uni- or bidirectional Authentication: 0=unidirectional, 1=bidirectional, Bit 1-7: Reserved.
 *                Task                                      0x00: Initiate Authentication, 0x01: Verify certificate ownership , 0x02 De-authenticate.
 *                Challenge_Certificate_Proof_of_Ownership  Pointer to challenge tester and diagnostic authentication certificate or proof of ownership tester.
 *                OpStatus                                  Current operation status.
 *                routineInfo                               Execution status of the routine in case of a positive response.
 * \param[out]    Verification_Result                       Positive response code of the routine.
 *                Authentication_Result                     Pointer to the memory location where the challenge ECU, theECU certificate and the proof of ownership ECU shall be stored.
 * \param[in,out] DataLength                                In: Length in bytes of Challenge_Certificate_Proof_of_Ownership, Out: Length in bytes of Authentication_Result.
 * \param[out]    ErrorCode                                 Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return        RTE_E_OK if routine and called sub routines could be successfully executed.
 *                RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK if request failed.
 *                RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING if request is pending.
 * \pre           The buffer referenced by Challenge_Certificate_Proof_of_Ownership must provide at least sizeof(Dcm_Data4004ByteType) many bytes.
 *                The buffer referenced by Authentication_Result must provide at least sizeof(Dcm_Data3006ByteType) many bytes.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check
 * \brief       Verifies the chain of trust of the stored certificates and their compatibility to the private key.
 * \details     -
 * \param[in]   OpStatus              Current operation status.
 * \param[out]  routineInfo           Execution status of the routine for positive responses.
 * \param[out]  Verification_Result   Positive Response Code of the routine.
 * \param[in]   DataLength            Length of Verification_Result
 * \param[out]  ErrorCode             Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Certificate_Self_Check_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Verification_Result must provide at least sizeof(Dcm_Data18ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights
 * \brief       Request enhanced access rights.
 * \details     This function requests further access rights beyond the ones which are granted by the basic and ECU individual access control list after
 *              authentication of the diagnostic user or tester.
 * \param[in]   Enhanced_Rights_Certificate Pointer to the enhanced rights certificate.
 *              OpStatus                    Current operation status.
 * \param[out]  routineInfo                 Execution status of the routine in case of a positive response.
 *              Verification_Result         Positive response code of the routine.
 * \param[in]   DataLength                  Length of Enhanced_Rights_Certificate in bytes.
 * \param[out]  ErrorCode                   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate
 * \brief       Transfer a Signature Verification Key to the ECU, which afterwards will be used for signature verification within software reprogramming or variant coding process. To enable the ECU to validate the Signature Verification Key, the key is transferred within an appropriate certificate.
 * \details     -
 * \param[in]   Data_Verification_Certificate Holds a pointer to the certificate to be used for verification.
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[in]   DataLength Length of certificates stored in Data_Verification_Certificate.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed
 * \brief       Injects in an authenticated way seed data into the random number generator.
 *              The seed data have to be encrypted by a session key derived by a preceding DH key exchange.
 * \details     -
 * \param[in]   Ephemeral_Backend_Public_Key_In The ephemeral Backend public key.
 * \param[in]   Data_Signature_In               Signature over the encrypted seed and ephemeral key.
 * \param[in]   Encrypted_Seed_In               The encrypted seed data.
 * \param[in]   OpStatus                        Current operation status.
 * \param[out]  routineInfo                     Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out         Positive Response Code of the routine.
 * \param[in]   DataLength                      Length of encrypted seed stored in Encrypted_Seed_In.
 * \param[out]  ErrorCode                       Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                        if routine could be successfully executed.
 *              RTE_E_RoutineServices_Inject_Seed_E_NOT_OK      if request failed.
 *              RTE_E_RoutineServices_Inject_Seed_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates
 * \brief       Replaces the currently stored ECU Certificate, Backend CA Certificate or Root CA Certificate. The Root CA Certificate may only be replaced together with the Backend CA Certificate. The Backend CA Certificate may only be exchanged together with the ECU Certificate. Replacement of Root or Backend certificate needs a corresponding link certificate.
 * \details     -
 * \param[in]   Certificates Holds the pointer to the certificates (up to 4).
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[in]   DataLength Length of the certificates
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Replace_Certificates_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates
 * \brief       Replaces the currently stored Trust model ECU Certificate, Trust model Intermediate CA Certificate and Trust model Backend CA Certificate.
 * \details     -
 * \param[in]   Trust_Certificates_In     The new certificates.
 * \param[in]   OpStatus                  Current operation status.
 * \param[out]  routineInfo_Out           Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out   Positive response code of the routine.
 * \param[in]   DataLength                Length of the certificates.
 * \param[out]  ErrorCode                 Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine has been executed successfully.
 *              RTE_E_RoutineServices_Replace_Trust_model_Certificates_E_NOT_OK if an error occurred during execution.
 *              RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_PENDING if requested service is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate
 * \brief       Replaces the currently stored Trust Model Root CA certificate.
 * \details     -
 * \param[in]   signature_new_Root_In   The signature calculated over new the Trust Model Root CA certificate by the
 *                                      replacement authority.
 * \param[in]   signature_In            The signature calculated over the replacement package by Daimler Backend.
 * \param[in]   Certificates_In         The Enhanced Rights certificate authorizing the replacement of the present
 *                                      Trust Model Root CA certificate and the new Trust Model Root CA certificate.
 * \param[in]   OpStatus                Current operation status.
 * \param[out]  routineInfo_Out         Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out Positive response code of the routine.
 * \param[in]   DataLength              Length of the certificates.
 * \param[out]  ErrorCode               Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_PENDING if requested service is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values
 * \brief       Resets the currently stored VINDataIdentifier to its default value.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption
 * \brief       Starts the generation of the shared secret and individual encryption for the passed ECU certificate. If standard shared secret is still used, a new one is generated.
 * \details     -
 * \param[in]   Nonce Hold the pointer to the nonce.
 * \param[in]   Ephemeral_ECU_Public_Key Holds the pointer to the ephemeral ECU public key.
 * \param[in]   Data_Signature_In Holds the pointer to signature calculated over nonce and ephemeral ECU public key.
 * \param[in]   Target_ECU_Certificate Holds the pointer to the certificate of the target ECU for verifying passed signature.
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[out]  Date_and_Time Holds the pointer to the memory location to store date and time.
 * \param[out]  Tick_Count Holds the pointer to the memory location to store the tick count
 * \param[out]  Tick_Count_Offset Holds the pointer to the memory location to store tick count offset
 * \param[out]  Encrypted_Nonce_and_Shared_Secret Holds the pointer to the memory location to store the encrypted nonce and secret.
 * \param[out]  Ephemeral_VSM_Public_Key Holds the pointer to the ephemeral VSM public key.
 * \param[out]  Data_Signature_Out Holds the pointer to the memory location to store the generated signature.
 * \param[out]  VSM_s_ECU_Certificate Holds the pointer to the memory location to store the VSM certificate.
 * \param[in,out] DataLength In: Length of data passed in buffer Target_ECU_Certificate. Out: Length of data passed in buffer VSM_s_ECU_Certificate.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Date_and_Time must provide at least sizeof(Dcm_Data7ByteType) many bytes.
 *              The buffer referenced by Tick_Count must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Offset must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Encrypted_Nonce_and_Shared_Secret must provide at least sizeof(Dcm_Data80ByteType) many bytes.
 *              The buffer referenced by Ephemeral_VSM_Public_Key must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              The buffer referenced by Data_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by VSM_s_ECU_Certificate must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization
 * \brief       Starts the generation of the shared secret and individual encryption for the passed ECU certificate.
 * \details     -
 * \param[in]   Nonce Hold the pointer to the nonce.
 * \param[in]   Ephemeral_ECU_Public_Key Holds the pointer to the ephemeral ECU public key.
 * \param[in]   Data_Signature_In Holds the pointer to signature calculated over nonce and ephemeral ECU public key.
 * \param[in]   Target_ECU_Certificate Holds the pointer to the certificate of the target ECU for verifying passed signature.
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[out]  Date_and_Time Holds the pointer to the memory location to store date and time.
 * \param[out]  Tick_Count Holds the pointer to the memory location to store the tick count
 * \param[out]  Tick_Count_Offset Holds the pointer to the memory location to store tick count offset
 * \param[out]  Encrypted_Nonce_and_Shared_Secret Holds the pointer to the memory location to store the encrypted nonce and secret.
 * \param[out]  Ephemeral_VSM_Public_Key Holds the pointer to the ephemeral VSM public key.
 * \param[out]  Data_Signature_Out Holds the pointer to the memory location to store the generated signature.
 * \param[out]  VSM_s_ECU_Certificate Holds the pointer to the memory location to store the VSM certificate.
 * \param[in,out] DataLength In: Length of data passed in buffer Target_ECU_Certificate. Out: Length of data passed in buffer VSM_s_ECU_Certificate.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Date_and_Time must provide at least sizeof(Dcm_Data7ByteType) many bytes.
 *              The buffer referenced by Tick_Count must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Offset must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Encrypted_Nonce_and_Shared_Secret must provide at least sizeof(Dcm_Data80ByteType) many bytes.
 *              The buffer referenced by Ephemeral_VSM_Public_Key must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              The buffer referenced by Data_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by VSM_s_ECU_Certificate must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution
 * \brief       Triggers the transmission of a generated shared secret.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair
 * \brief       Starts the generation of a new ECU private/public key pair, as specified for RID 0x027B.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out  Provides more details about the routine's outcome in case of a positive
 *                                       diagnostic response code.
 * \param[out]  CSR_Signature_Out  Signature over the returned CSR using the ECU live private key.
 * \param[out]  Trust_Model_ECU_CSR_Out  Certificate Signing request for the newly generated ECU CSR key pair.
 * \param[out]  DataLength  Length of Trust_Model_ECU_CSR_Out in bytes.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by CSR_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by Trust_Model_ECU_CSR_Out must provide at least sizeof(Dcm_Data1002ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys
 * \brief       Derives the symmetric key used for SecOc from the shared secret.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_E_NOT_OK if request failed.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret
 * \brief       Generates a new shared secret.
 * \details     -
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_E_NOT_OK if request failed.
 *              RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time
 * \brief       Initiates time synchronization.
 * \details     This function initiates time synchronization by requesting a one-time challenge (nonce)
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  routineInfo Execution status of the routine in case of a positive response.
 *              Nonce       Pointer to the memory location where the nonce shall be stored.
 *              ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by Nonce must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
 * \brief       Distributes the car-specific secret at the garage or dealership based on the Unique ECU ID chain.
 * \details     -
 * \param[in]   Date_and_Time_In                      The date and time the target ECU shall be set to.
 * \param[in]   Tick_Count_In                         The tick-count the target ECU shall be set to.
 * \param[in]   Tick_Count_Offset_In                  The tick-count offset the target ECU shall be set to.
 * \param[in]   Encrypted_Nonce_and_Shared_Secret_In  The encrypted nonce and car-specific secret to be decrypted by the target ECU.
 * \param[in]   Ephemeral_VSM_Public_Key_In           The ephemeral VSM public key.
 * \param[in]   Data_Signature_In                     The signature to be verified.
 * \param[in]   Certificates_In                       The VSM's certificates.
 * \param[in]   OpStatus                              Current operation status.
 * \param[out]  routineInfo_Out                       Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out               Positive response code of the routine.
 * \param[in]   DataLength                            Length of Certificates_In.
 * \param[out]  ErrorCode                             Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_PENDING if requested service is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Encryption
 * \brief       Encrypts the car-specific secret at the garage or dealership based on the Unique ECU ID chain.
 *              Generates a new car-specific secret if it is still the default value.
 *              Provides time synchronization information.
 * \details     -
 * \param[in]   Nonce_In                                The nonce
 * \param[in]   Ephemeral_ECU_Public_Key_In             The ephemeral ECU public key.
 * \param[in]   In_Data_Signature_In                    The signature to be verified.
 * \param[in]   In_Certificates_In                      The certificates of the target ECU.
 * \param[in]   OpStatus                                Current operation status.
 * \param[out]  routineInfo_Out                         Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out                 Positive response code of the routine.
 * \param[out]  Date_and_Time_Out                       Current date and time of VSM.
 * \param[out]  Tick_Count_Out                          Current tick-count of VSM.
 * \param[out]  Tick_Count_Offset_Out                   Current tick-count offset of VSM.
 * \param[out]  Encrypted_Nonce_and_Shared_Secret_Out   The encrypted nonce and car-specific secret.
 * \param[out]  Ephemeral_VSM_Public_Key_Out            The ephemeral VSM public key.
 * \param[out]  Out_Data_Signature_Out                  The generated signature.
 * \param[out]  Out_Certificates_Out                    The VSM's certificates.
 * \param[in,out] DataLength                            In: Length of In_Certificates_In. Out: Length of Out_Certificates_Out.
 * \param[out]  ErrorCode                               Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING if requested service is pending.
 * \pre         The buffer referenced by Date_and_Time_Out must provide at least sizeof(Dcm_Data7ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Out must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Offset_Out must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Encrypted_Nonce_and_Shared_Secret_Out must provide at least sizeof(Dcm_Data80ByteType) many bytes.
 *              The buffer referenced by Ephemeral_VSM_Public_Key_Out must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              The buffer referenced by Out_Data_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by Out_Certificates_Out must provide at least sizeof(Dcm_Data3006ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_TickCount_Synchronization
 * \brief       Encrypts the car-specific secret at the garage or dealership based on the Unique ECU ID chain.
 *              Never generates a new car-specific secret.
 *              Provides time synchronization information.
 * \details     -
 * \param[in]   Nonce_In                                The nonce
 * \param[in]   Ephemeral_ECU_Public_Key_In             The ephemeral ECU public key.
 * \param[in]   In_Data_Signature_In                    The signature to be verified.
 * \param[in]   In_Certificates_In                      The certificates of the target ECU.
 * \param[in]   OpStatus                                Current operation status.
 * \param[out]  routineInfo_Out                         Execution status of the routine for positive responses.
 * \param[out]  Verification_Result_Out                 Positive response code of the routine.
 * \param[out]  Date_and_Time_Out                       Current date and time of VSM.
 * \param[out]  Tick_Count_Out                          Current tick-count of VSM.
 * \param[out]  Tick_Count_Offset_Out                   Current tick-count offset of VSM.
 * \param[out]  Encrypted_Nonce_and_Shared_Secret_Out   The encrypted nonce and car-specific secret.
 * \param[out]  Ephemeral_VSM_Public_Key_Out            The ephemeral VSM public key.
 * \param[out]  Out_Data_Signature_Out                  The generated signature.
 * \param[out]  Out_Certificates_Out                    The VSM's certificates.
 * \param[in,out] DataLength                            In: Length of In_Certificates_In. Out: Length of Out_Certificates_Out.
 * \param[out]  ErrorCode                               Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_E_NOT_OK if an error occurred.
 *              RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING if requested service is pending.
 * \pre         The buffer referenced by Date_and_Time_Out must provide at least sizeof(Dcm_Data7ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Out must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Tick_Count_Offset_Out must provide at least sizeof(Dcm_Data5ByteType) many bytes.
 *              The buffer referenced by Encrypted_Nonce_and_Shared_Secret_Out must provide at least sizeof(Dcm_Data80ByteType) many bytes.
 *              The buffer referenced by Ephemeral_VSM_Public_Key_Out must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 *              The buffer referenced by Out_Data_Signature_Out must provide at least sizeof(Dcm_Data64ByteType) many bytes.
 *              The buffer referenced by Out_Certificates_Out must provide at least sizeof(Dcm_Data3006ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 * \config      VSM only.
 */

/*!
 * \fn          Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature
 * \brief       Verifies the integrity and authenticity e.g. of variant coding data using a signature verification.
 * \details     -
 * \param[in]   Data_to_be_checked - Identifies data which shall be verified (0 for Variant Coding).
 * \param[in]   Signature_Value Holds a pointer to the signature to be used for verification.
 * \param[in]   OpStatus  Current operation status.
 * \param[out]  routineInfo  Execution status of the routine for positive responses.
 * \param[out]  Verification_Result  Positive Response Code of the routine.
 * \param[out]  ErrorCode  Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK if request failed.
 *              RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_SecurityAccess_CompareKey
 * \brief       Verifies the passed key against the previously generated seed.
 * \details     -
 * \param[in]   secLevel    The security level to be accessed.
 *              key         Pointer to the key (signature) to be verified.
 *              opStatus    Current operation status.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK if request failed.
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING if request is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_SecurityAccess_GetSeed
 * \brief       Provides a seed for the requested security level.
 * \details     This function is used during security access to generate a seed for a requested security level.
 * \param[in]   secLevel    The security level to be accessed.
 *              opStatus    Current operation status.
 * \param[out]  seed        Pointer to the memory location where the seed shall be stored.
 *              ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK if routine and called sub routines could be successfully executed.
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK if request failed.
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING if request is pending.
 * \pre         The buffer referenced by seed must provide at least sizeof(Dcm_Data32ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */

/*!
 * \fn          Ssa_ProcCtrl_ServiceDispatcher
 * \brief       Dispatches incoming events in order to start a diagnostic service calls.
 * \details     The function decouples the execution of the diagnostic application calls from the DCM call context.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate
 * \brief       Processes the diagnostic Authentication service
 * \details     -
 * \param[in]   OpStatus    Current operation status.
 * \param[in]   ReqData     Points to the request data buffer to be evaluated or passed to the application
 * \param[in]   ReqBufSize  Size of request buffer
 * \param[in]   ReqDataLen  Request data length
 * \param[out]  ResData     Points to the response data buffer to be written or passed to the application to provide data at
 * \param[in]   ResBufSize  Size of response buffer
 * \param[out]  ResDataLen  Response data length
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                  routine and called sub routines could be successfully executed.
 *              RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK      if request failed.
 *              RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING if request is pending.
 * \pre         The buffer referenced by ReqData must be at least of the length ReqBufSize.
 *              The buffer referenced by ResData must be at least of the length ResBufSize.
 * \context     TASK, context of Ssa_Cdd_MainFunction
 * \reentrant   FALSE
 * \synchronous FALSE
 * \note        Used by Ssa_Cdd.
 */

/**********************************************************************************************************************
 *  FvM
 *********************************************************************************************************************/
/*!
 * \fn          Ssa_FvM_ComModeChanged
 * \brief       Notifies each time a communication channel enters the state COMM_FULL_COMMUNICATION.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_FvM_Com_ReceiveTickCount
 * \brief       Notifies about the reception of a real time offset broadcast. Catches data and uses it as new tick count if valid.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \config      Not in VSM.
 */

/*!
 * \fn          Ssa_FvM_Com_ReceiveTickCountTimeout
 * \brief       Handles the COM time-out event of the secured tick-count signal forwarded by the BcTp.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Shall be called whenever a COM time-out event of the secured tick-count signal received.
 * \config      Not in VSM.
 */

/*!
 * \fn            Ssa_FvM_GetRxFreshness
 * \brief         Calculates the tick count as freshness for a Rx PDU.
 * \details       -
 * \param[in]     freshnessValueId  Freshness id of the current PDU.
 * \param[in]     truncatedFreshnessValue  Holds the pointer to the received truncated freshness value.
 * \param[in]     truncatedFreshnessValueLength Lengths in bits of the received truncated freshness value.
 * \param[in]     authVerifyAttempts Attempt to get the freshness for the received PDU.
 * \param[out]    freshnessValue Holds the pointer to a memory location where the calculated freshness is stored.
 * \param[in,out] freshnessValueLength Requested and calculated length in bits of the calculated freshness value.
 * \return        RTE_E_OK if freshness is provided.
 *                RTE_E_SecOC_FreshnessManagement_E_NOT_OK otherwise.
 * \pre           freshnessValue is a valid pointer and referencing a buffer of the bit size *freshnessValueLength
 *                and at least of size sizeof(freshnessValueType).
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 * \note          Used by SecOC and BcTp.
 */

/*!
 * \fn          Ssa_FvM_GetTxFreshness
 * \brief       Calculates the tick count as freshness for a Tx PDU.
 * \details     -
 * \param[in]   freshnessValueId Freshness id of the current PDU.
 * \param[out]  freshnessValue Holds the pointer to a memory location where the calculated freshness is stored.
 * \param[out]  freshnessValueLength Requested and calculated length in bits of the calculated freshness value.
 *                                   The length must be a multiple of 8 and must not be larger than 64.
 * \return      RTE_E_OK if freshness is provided.
 *              RTE_E_SecOC_FreshnessManagement_E_NOT_OK otherwise.
 * \pre         The size of the buffer referenced by the out parameter 'freshnessValue' is at least of the bit size *freshnessValueLength,
 *              and at least given by sizeof(freshnessValueType).
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        Used by SecOC and BcTp.
 */

/*!
 * \fn          Ssa_FvM_GetTxFreshnessTruncData
 * \brief       Calculates the tick count as freshness and truncated freshness for a Tx PDU.
 * \details     -
 * \param[in]   freshnessValueId Freshness id of the current PDU.
 * \param[out]  freshnessValue Holds the pointer to a memory location where the calculated freshness is stored.
 * \param[out]  freshnessValueLength Requested and calculated length in bits of the calculated freshness value.
 *                                   The length must be a multiple of 8 and must not be larger than 64.
 * \param[out]  truncatedFreshnessValue Holds the pointer to a memory location where the calculated truncated freshness is stored.
 * \param[out]  truncatedFreshnessValueLength Requested and calculated length in bits of the calculated truncated freshness value.
 *                                            The length must be a multiple of 8 and must not be larger than 64.
 * \return      RTE_E_OK if freshness is provided.
 *              RTE_E_SecOC_FreshnessManagement_E_NOT_OK otherwise.
 * \pre         The size of the buffer referenced by the out parameter freshnessValue is at least of the bit size *freshnessValueLength
 *              and at least given by sizeof(freshnessValueType).
 *              The size of the buffer referenced by the out parameter truncatedFreshnessValue is at least of the bit size *truncatedFreshnessValueLength
 *              and at least given by sizeof(freshnessValueType).
 *              It is truncatedFreshnessValueLength <= freshnessValueLength.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        Used by SecOC.
 */

/*!
 * \fn          Ssa_FvM_Init
 * \brief       Initializes internal variables of the freshness value management sub component.
 * \details     -
 * \pre         Ssa_TimeM_Init has been executed
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        Before this runnable has been executed, no other calls to sub module may be done.
 */

/*!
 * \fn          Ssa_FvM_InitMonitorForEvent_DTC_0xD12081
 * \brief       Notifies that this event is cleared, or that the operation (monitoring) cycle restarts.
 *              Restarts de-bouncing timer for detection of rejected secured tick-count messages.
 * \details     -
 * \param[in]   InitMonitorReason Init monitor reason.
 * \return      RTE_E_OK always.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_FvM_InitMonitorForEvent_DTC_0xD12087
 * \brief       Notifies that this event is cleared, or that the operation (monitoring) cycle restarts.
 *              Restarts de-bouncing timer for detection of both missing and unauthenticated secured tick-count messages.
 * \details     -
 * \param[in]   InitMonitorReason Init monitor reason.
 * \return      RTE_E_OK always.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_FvM_InitialTickCount_Set
 * \brief       Set an initial tick count.
 * \details     -
 * \param[in]   tickCount The tick-count to be set.
 * \return      RTE_E_OK  always.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_FvM_LocalTickCountSyncStatus_Get
 * \brief       Gets the current local tick-count synchronization status.
 * \details     -
 * \param[out]  syncState Holds the pointer to the memory location where the synchronization status shall be stored.
 * \return      RTE_E_OK if real time was read.
 *              RTE_E_TimeM_LocalTickCountSyncStatus_E_NOT_OK otherwise.
 * \pre         syncState must be a valid pointer
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_FvM_Mainfunction
 * \brief       Cyclically called to increment timer. In case of VSM, function sends tick count cyclically.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */

/*!
 * \fn          Ssa_FvM_SPduTxConfirmation
 * \brief       Used by the SecOC to indicate that the Secured I-PDU has been initiated for transmission.
 * \details     -
 * \param[in]   freshnessValueId The freshness value identifier.
 * \return      RTE_E_OK always
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        This indication is without any effect in the Ssa.
 */

/**********************************************************************************************************************
 *  FvM callout functions
 *********************************************************************************************************************/

/*!
 * \fn          Std_ReturnType Rte_Call_FvM_RealTimeClock_Get(uint64 *rtcTickCount)
 * \brief       Gets the RTC (real-time clock) tick-count.
 * \details     -
 * \param[out]  rtcTickCount Holds the pointer to the memory location of size 64 bits where the RTC tick-count shall be stored.
 *                           The callee must ensure a valid write access.
 * \return      RTE_E_OK if rtcTickCOunt has been read successfully.
 *              RTE_E_Ssa_RealTimeClock_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn          Std_ReturnType Rte_Call_FvM_RealTimeClock_Set(uint64 rtcTickCount)
 * \brief       Sets the RTC (real-time clock) tick-count.
 * \details     -
 * \param[in]   rtcTickCount The RTC tick-count value
 * \return      RTE_E_OK if rtcTickCOunt has been set successfully.
 *              RTE_E_Ssa_RealTimeClock_E_NOT_OK otherwise.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */

/*!
 * \fn            Std_ReturnType Rte_Call_Ssa_RightsM_DiagnosticInformation_Get(uint8 *diagVersion, uint8 *diagVariant)
 * \brief         Requests for the current diagnostic version and diagnostic variant from application to verify access control list.
 * \details       -
 * \param[out]    diagVersion  Buffer of size one byte for the diagnostic version.
 * \param[out]    diagVariant  Buffer of size one byte for the diagnostic variant.
 * \return        RTE_E_OK if diagnostic version and variant has been set.
 *                RTE_E_Ssa_RightsM_DiagnosticInformation_E_NOT_OK otherwise.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */

/*!
 * \fn            Std_ReturnType Rte_Call_Ssa_KeyStorage_StorePermanently(Ssa_KeyStorageUseCaseType keyStorageUseCase, Ssa_KeyStorageTaskType keyStorageTask)
 * \brief         Requests for storing the key material or certificates permanently i.e. for making them persistent.
 * \details       -
 * \param[in]     keyStorageUseCase     Key storage use case:
 *                SSA_KEYSTORAGE_USECASE_CRYPTO                       Request for storing Csm key material (i.e. SecOC keys and car-specific secret and/or the hash of it).
 *                SSA_KEYSTORAGE_USECASE_CERTIFICATES                 Request for storing the replaced diagnostic chain certificates of Csm.
 *                SSA_KEYSTORAGE_USECASE_TRUST_MODEL_CERTIFICATES     Request for storing
 *                                                                    - Trust Model Backend Ca certificate of KeyM,
 *                                                                    - Trust Model Intermediate Ca certificate of KeyM,
 *                                                                    - Trust Model ECU KeyM certificate of KeyM,
 *                                                                    - Trust Model Backend Ca public key of Csm,
 *                                                                    - Trust Model Intermediate Ca public key of Csm and
 *                                                                    - Trust Model ECU public key of Csm
 *                SSA_KEYSTORAGE_USECASE_TRUST_MODEL_ROOT_CERTIFICATE Request for storing
 *                                                                    - Trust Model Root Ca certificate of KeyM and
 *                                                                    - Trust Model Root Ca public key of Csm
 *                SSA_KEYSTORAGE_USECASE_RNG_SEED_STATE               Request for storing RNG state
 * \param[in]     keyStorageTask          Key storage task:
 *                SSA_OPSTATUS_INITIAL  Initial call
 *                SSA_OPSTATUS_CHECKSTATE Used for calling again after function returned with E_PENDING
 *                SSA_OPSTATUS_CANCEL     Cancel
 * \return        RTE_E_OK                        if storing has been finished successfully.
 *                RTE_E_Ssa_KeyStorage_E_NOT_OK   if an error occurred.
 *                RTE_E_Ssa_KeyStorage_E_PENDING  if request is pending.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   FALSE
 */

/*!
 * \fn            Std_ReturnType Rte_Call_Ssa_KeyProc_PrepareKeyExchange(Ssa_OpStatusType opStatus, uint32 keyId)
 * \brief         Requests for preparing the key exchange operation.
 * \details       The user of the Ssa might use this callout function to do some preparative calculations in advance
 *                of the key exchange operation calculation done by the underlying crypto stack.
 * \param[in]     opStatus  Operation status:
 *                SSA_OPSTATUS_INITIAL    Initial call
 *                SSA_OPSTATUS_CHECKSTATE Used for calling again after function returned with E_PENDING
 *                SSA_OPSTATUS_CANCEL     Cancel
 * \param[in]     keyId     Key identifier of the key exchange key used for calculating the public value and the shared
 *                          secret for the key exchange.
 * \return        RTE_E_OK                        if request has finished successfully.
 *                RTE_E_Ssa_KeyProc_E_NOT_OK      if an error occurred.
 *                RTE_E_Ssa_KeyProc_E_PENDING     if request is pending.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   FALSE
 */

/*!
 * \fn            Std_ReturnType Rte_Call_Ssa_KeyProc_GenerateKeyPair(uint32 privateKeyId, uint32 publicKeyId)
 * \brief         Requests for generating a Ed25519 key pair.
 * \details       The user of the Ssa might use this callout function to do generate a Ed25519 key pair. 
 * \param[in]     privateKeyId     Key identifier of the private key that is generated.
 * \param[in]     publicKeyId      Key identifier of the public key that is generated.
 * \return        RTE_E_OK                        if request has finished successfully.
 *                RTE_E_Ssa_KeyProc_E_NOT_OK      if an error occurred.
 *                RTE_E_Ssa_KeyProc_E_PENDING     if request is pending.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   FALSE
 */

/*!
 * \fn            Std_ReturnType Rte_Call_Ssa_VeDocRelevantInfo_GetData(uint8 *data, uint16 *dataLength)
 * \brief         Requests for the VeDoc relevant information, e.g., to be used as common name in the Trust Model CSR.
 * \details       The user of the Ssa shall use this callout function to provide VeDoc relevant imnformation to Ssa
 *                which in turn uses it for creation of the CSR (certificate signing request).
 * \param[out]    data        Buffer where the VeDoc relevant inforamtion shall be written to.
 * \param[in,out] dataLength  Length of data. Ssa provides a buffer of 64 bytes.
 * \return        RTE_E_OK                              if request has finished successfully.
 *                RTE_E_Ssa_VeDocRelevantInfo_E_NOT_OK  if an error occurred.
 * \pre           -
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */

/**********************************************************************************************************************
 *  Exclusive areas
 *********************************************************************************************************************/

/*!
 * \exclusivearea Coding_ExclusiveArea_VIN
 *                Ensures consistency of the Coding global RAM variables.
 * \protects      Rte_Pim_CodingVIN
 *                Rte_Pim_CodingVINMirror
 *                Rte_Pim_CurrentVIN
 *                Rte_Pim_CurrentVINMirror
 *                Coding_VinReceiveTimeout
 *                Coding_VIN_State
 * \usedin        Ssa_Coding_DataServices_VINDataIdentifier_ReadData
 *                Ssa_Coding_MainFunction
 *                Ssa_Coding_VIN_Get
 *                Ssa_Coding_VIN_Lock
 *                Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start
 *                Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start
 *                Ssa_Coding_DataServices_VINDataIdentifier_WriteData
 *                Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start
 *                Ssa_Coding_VIN_Receive
 *                Ssa_Coding_VIN_Set
 * \exclude       Ssa_Coding_Init
 * \length        SHORT Only few bytes are copied within this exclusive area.
 *                      Only few instructions are within this exclusive area.
 * \endexclusivearea
 */

/*!
 * \exclusivearea FvM_ExclusiveArea
 *                Ensures consistency of the FvM global RAM variables.
 * \protects      Rte_Ssa_FvM_TickCount
 *                Rte_Ssa_FvM_LastSecuredTickCount
 *                Ssa_FvM_TickCountAcceptanceTimeoutCounter
                  Ssa_FvM_TickCountAuthReceptionTimeoutCounter
                  Ssa_FvM_TickCountReceptionTimeoutCounter
                  Ssa_FvM_TickCountReceptionComTimeoutCounter
                  Ssa_FvM_DiffLastRejectedTickCount
 * \usedin        Ssa_FvM_Com_ReceiveTickCount
 *                Ssa_FvM_Mainfunction
 *                Ssa_FvM_GetRxFreshness
 *                Ssa_FvM_GetTxFreshness
 *                Ssa_FvM_GetTxFreshnessTruncData
 *                Ssa_FvM_InitialTickCount_Set
 * \exclude       Ssa_FvM_Init
 * \length        SHORT Only few bytes are copied within this exclusive area.
 *                      Only few instructions are within this exclusive area.
 * \endexclusivearea
 */

/*!
 * \exclusivearea KeyM_ExclusiveArea
 *                Ensures consistency of a KeyM global RAM state variable.
 * \protects      KeyM_MainLoopProc.state
 * \usedin        Ssa_KeyM_Com_VehicleSharedSecretNotification
 *                Ssa_KeyM_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys
 *                Ssa_KeyM_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret
 *                Ssa_KeyM_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption
 * \exclude       Ssa_KeyM_Init
 * \length        SHORT Only few instructions are within this exclusive area.
 * \endexclusivearea
 */

/*!
 * \exclusivearea ProcCtrl_ExclusiveArea
 *                Ensures consistency of the ProcCtrlglobal RAM variables.
 * \protects      Ssa_ProcCtrlBuffer
 * \usedin        All API functions except of Ssa_ProcCtrl_Init.
 * \exclude       Ssa_TimeM_Init
 * \length        MEDIUM The data buffers of the diagnostic services might be copied.
 * \endexclusivearea
 */

/*!
 * \exclusivearea RightsM_ExclusiveArea
 *                Ensures consistency of the RightsM global RAM variables.
 * \protects      RightsM_DiagChannelData
 *                RightsM_SecuritySettings
 *                RightsM_EnhancedAccessRights
 *                RightsM_TargetSubjectKeyIdentifier
 *                RightsM_TargetSubjectKeyIdentifierValid
 *                Rte_Pim_RightsMNonce
 *                Rte_Pim_RightsMNonceMirror
 * \usedin        Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess
 *                Ssa_RightsM_Com_ReceiveBroadcastAuthentication
 *                Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData
 *                Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData
 *                Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData
 *                Ssa_RightsM_DiagnosticSessionChangeIndication
 *                Ssa_RightsM_MainFunction
 *                Ssa_RightsM_Nonce_Destroy
 *                Ssa_RightsM_ServiceRequestNotification_Confirmation
 *                Ssa_RightsM_ServiceRequestNotification_Indication
 *                Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start
 *                Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start
 *                Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start
 *                Ssa_RightsM_SecurityAccess_CompareKey
 *                Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState
 *                Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask
 *                Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted
 *                Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole
 *                Ssa_RightsM_Nonce_Get
 *                Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier
 * \exclude       Ssa_RightsM_Init
 * \length        MEDIUM The more diagnostic channels are configured the more data has to be handled.
 *                       The Enhanced ACL is searched in an exclusive area.
 * \endexclusivearea
 */

/*!
 * \exclusivearea SecLog_ExclusiveArea
 *                Ensures consistency of the SecLog global RAM variables.
 * \protects      Ssa_SecLog_MirrorRamBlockUsed
 *                Ssa_SecLog_NvMWriteRequested
 *                Ssa_SecLog_NvMWriteState
 *                Ssa_SecLog_NvmCtrl
 *                Ssa_SecLog_FailedMacVerificationCounter
 *                Ssa_SecLog_FailedMacVerificationCounterDtc
 *                Rte_Pim_LogDataEvnt1_FailedCertVerif
 *                Rte_Pim_LogDataEvnt1_FailedCertVerif_Mirror
 *                Rte_Pim_LogDataEvnt2_SucCertVerif
 *                Rte_Pim_LogDataEvnt2_SucCertVerif_Mirror
 *                Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights
 *                Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror
 *                Rte_Pim_LogDataEvnt4_AuthBySecAccess
 *                Rte_Pim_LogDataEvnt4_AuthBySecAccess_Mirror
 *                Rte_Pim_LogDataEvnt5_SucDiagServiceExec
 *                Rte_Pim_LogDataEvnt5_SucDiagServiceExec_Mirror
 *                Rte_Pim_LogDataEvnt6_RightsMgmt
 *                Rte_Pim_LogDataEvnt6_RightsMgmt_Mirror
 *                Rte_Pim_LogDataEvnt7_SigVerif
 *                Rte_Pim_LogDataEvnt7_SigVerif_Mirror
 *                Rte_Pim_LogDataEvnt8_TickCountDateAndTime
 *                Rte_Pim_LogDataEvnt8_TickCountDateAndTime_Mirror
 *                Rte_Pim_LogDataEvnt9_SecOcMisconfig
 *                Rte_Pim_LogDataEvnt9_SecOcMisconfig_Mirror
 *                Rte_Pim_LogDataEvnt10_FailedPduMacVerif
 *                Rte_Pim_LogDataEvnt10_FailedPduMacVerif_Mirror
 *                Rte_Pim_LogDataEvnt11_SecOrAuthBoot
 *                Rte_Pim_LogDataEvnt11_SecOrAuthBoot_Mirror
 *                Rte_Pim_LogDataEvnt12_ChangeOfVin
 *                Rte_Pim_LogDataEvnt12_ChangeOfVin_Mirror
 *                Rte_Pim_LogDataEvnt13_AclReplacement
 *                Rte_Pim_LogDataEvnt13_AclReplacement_Mirror
 *                Rte_Pim_LogFailedMacVerifCount_ExceededTh1
 *                Rte_Pim_LogFailedMacVerifCount_ExceededTh1_Mirror
 *                Rte_Pim_LogFailedMacVerifCount_ExceededTh2
 *                Rte_Pim_LogFailedMacVerifCount_ExceededTh2_Mirror
 *                Rte_Pim_LogFailedMacVerifCount_ExceededTh3
 *                Rte_Pim_LogFailedMacVerifCount_ExceededTh3_Mirror
 * \usedin        Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
 *                Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
 *                Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
 *                Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead
 *                Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData
 *                Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength
 *                Ssa_SecLog_MainFunction
 *                Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess
 *                Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime
 *                Ssa_SecLog_LogEvent_ChangeVin
 *                Ssa_SecLog_LogEvent_EcuIndividualAclReplacement
 *                Ssa_SecLog_LogEvent_FailedCertificateVerification
 *                Ssa_SecLog_LogEvent_FailedSecOcMacVerification
 *                Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast
 *                Ssa_SecLog_LogEvent_RightsManagement
 *                Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot
 *                Ssa_SecLog_LogEvent_SignatureVerification
 *                Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights
 *                Ssa_SecLog_LogEvent_SuccessfulCertificateVerification
 *                Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution
 * \exclude       Ssa_SecLog_Init
 * \length        MEDIUM The individual SecLog buffers might be copied.
 * \endexclusivearea
 */

/*!
 * \exclusivearea TimeM_ExclusiveArea
 *                Ensures consistency of the TimeM global RAM variables.
 * \protects      Rte_Ssa_TimeM_TickCount
 *                Rte_Ssa_TimeM_TickCountMirror
 *                Rte_Ssa_TimeM_TickCountValueToBeStoredToNvM
 *                Rte_Ssa_TimeM_RealTimeOffset
 *                Rte_Ssa_TimeM_RealTimeOffsetMirror
 *                TimeM_TickCountNvmWriteRequested
 *                TimeM_TickCountNvmWriteState
 *                TimeM_RealTimeOffsetNvmWriteRequested
 *                TimeM_RealTimeOffsetNvmWriteState
 * \usedin        Ssa_TimeM_Com_ReceiveRealTimeOffset
 *                Ssa_TimeM_Com_ReceiveTickCount
 *                Ssa_TimeM_DataServices_DID_018A_TickCount_ReadData
 *                Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_DateTime_ReadData
 *                Ssa_TimeM_DataServices_DID_018D_RealTimeOffset_TickCount_ReadData
 *                Ssa_TimeM_DataServices_Secured_System_Date_and_Time_Read_GeneralizedTime_ReadData
 *                Ssa_TimeM_Mainfunction
 *                Ssa_TimeM_PowernetMgmtStateChanged
 *                Ssa_TimeM_RealTime_Get
 *                Ssa_TimeM_RealTime_Set
 *                Ssa_TimeM_SecOC_FvM_GetRxFreshness
 *                Ssa_TimeM_SecOC_FvM_GetTxFreshness
 *                Ssa_TimeM_SecOC_FvM_GetTxFreshnessTruncData
 *                Ssa_TimeM_TickCount_Get
 *                Ssa_TimeM_TimeRawData_Get
 *                Ssa_TimeM_TimeRawData_ResetLocalTickCount
 *                Ssa_TimeM_TimeRawData_Set
 * \exclude       Ssa_TimeM_Init
 * \length        SHORT Only few bytes are copied within this exclusive area.
 * \endexclusivearea
 */

/*!
 * \exclusivearea Cdd_ExclusiveArea_External_S29_Processing
 *                Ensures consistency of Cdd global RAM variables.
 * \protects      Ssa_Cdd_S29Proc
 *                Ssa_Cdd_S29MainProcState
 * \usedin        Ssa_Cdd_MainFunction
 *                Ssa_Cdd_DiagnosticService_Authentication_0x29
 * \exclude       Ssa_Cdd_Init
 * \length        SHORT Only few bytes are copied within this exclusive area.
 * \endexclusivearea
 */

#endif /* SSA_H */
/**********************************************************************************************************************
 *  END OF FILE: Ssa.h
 *********************************************************************************************************************/
