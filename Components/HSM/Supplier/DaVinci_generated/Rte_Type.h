/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Type.h
 *           Config:  vHsmConfig.dpa
 *      ECU-Project:  vHsmConfig
 *
 *        Generator:  MICROSAR RTE Generator Version 4.28.0
 *                    RTE Core Version 1.28.0
 *          License:  CBD2200336
 *
 *      Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/* double include prevention */
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

# include "Rte.h"

/* PRQA S 1039 EOF */ /* MD_Rte_1039 */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_KeyM_ConstDataPtrType
typedef const uint8 * KeyM_ConstDataPtrType;

# define Rte_TypeDef_KeyM_CryptoKeyDataType
typedef uint8 * KeyM_CryptoKeyDataType;

# define Rte_TypeDef_KeyM_DataPtrType
typedef uint8 * KeyM_DataPtrType;

# define Rte_TypeDef_KeyM_LengthPtrType
typedef uint32 * KeyM_LengthPtrType;

# define Rte_TypeDef_KeyM_const_CryptoKeyDataType
typedef const uint8 * KeyM_const_CryptoKeyDataType;

# define Rte_TypeDef_Csm_ConfigIdType
typedef uint16 Csm_ConfigIdType;

# define Rte_TypeDef_KeyM_CertElementIdType
typedef uint16 KeyM_CertElementIdType;

# define Rte_TypeDef_KeyM_CertificateIdType
typedef uint16 KeyM_CertificateIdType;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_Crypto_OperationModeType
typedef uint8 Crypto_OperationModeType;

# define Rte_TypeDef_Crypto_ResultType
typedef uint8 Crypto_ResultType;

# define Rte_TypeDef_Crypto_VerifyResultType
typedef uint8 Crypto_VerifyResultType;

# define Rte_TypeDef_Csm_KeyElementEnumType
typedef uint32 Csm_KeyElementEnumType;

# define Rte_TypeDef_Csm_ResultType
typedef uint8 Csm_ResultType;

# define Rte_TypeDef_Csm_VerifyResultType
typedef uint8 Csm_VerifyResultType;

# define Rte_TypeDef_KeyM_CertificateStatusType
typedef uint8 KeyM_CertificateStatusType;

# define Rte_TypeDef_KeyM_CsrEncodingType
typedef uint8 KeyM_CsrEncodingType;

# define Rte_TypeDef_KeyM_ResultType
typedef uint8 KeyM_ResultType;

# define Rte_TypeDef_KeyM_ServiceCertificateType
typedef uint8 KeyM_ServiceCertificateType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_Csm_DataPtr
typedef uint8 * Csm_DataPtr;

#  define Rte_TypeDef_Csm_LengthPtr
typedef uint32 * Csm_LengthPtr;

#  define Rte_TypeDef_Csm_const_DataPtr
typedef const uint8 * Csm_const_DataPtr;

#  define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

#  define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

#  define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

#  define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

#  define Rte_TypeDef_Csm_VerifyResultPtr
typedef Csm_VerifyResultType * Csm_VerifyResultPtr;

# endif
# include "Rte_DataHandleType.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned int Rte_BitType;
/**********************************************************************************************************************
 * type and extern declarations of RTE internal variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

# define RTE_STATE_UNINIT    (0U)
# define RTE_STATE_SCHM_INIT (1U)
# define RTE_STATE_INIT      (2U)

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Buffers for Basic Tasks triggered by OS Schedule Table
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_ZERO_INIT) Rte_ScheduleTable_OsTask_Step;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint32, RTE_VAR_ZERO_INIT) Rte_ScheduleTable_Ostask_HighPrio_Step;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



# endif /* defined(RTE_CORE) */

#endif /* RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

*/
