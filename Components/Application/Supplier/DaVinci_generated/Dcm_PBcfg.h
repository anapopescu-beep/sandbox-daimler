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
 *              File: Dcm_PBcfg.h
 *   Generation Time: 2023-08-03 15:01:39
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


#if !defined(DCM_PBCFG_H)
# define DCM_PBCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/*! Implementation version */
# define DCM_PBCFG_MAJOR_VERSION                                               17u
# define DCM_PBCFG_MINOR_VERSION                                                5u
# define DCM_PBCFG_PATCH_VERSION                                                0u

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

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

#endif /* !defined(DCM_PBCFG_H) */

/**********************************************************************************************************************
 *  END OF FILE: Dcm_PBcfg.h
 *********************************************************************************************************************/

