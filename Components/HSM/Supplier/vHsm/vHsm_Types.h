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
/*      \file   vHsm_Types.h
 *      \brief  Vector Hardware Security Module Firmware Types
 *
 *      \details  Declares data structures required for interaction with Vector Hardware Security Module Firmware.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_TYPES_H)
# define VHSM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "Csm_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* vHsm Key management actions */
# define VHSM_KEYM_ACTION_KEYELEMENTSET                               (0x00u)
# define VHSM_KEYM_ACTION_KEYELEMENTGET                               (0x01u)
# define VHSM_KEYM_ACTION_KEYELEMENTCOPY                              (0x02u)
# define VHSM_KEYM_ACTION_KEYCOPY                                     (0x03u)
# define VHSM_KEYM_ACTION_KEYDERIVE                                   (0x04u)
# define VHSM_KEYM_ACTION_KEYGENERATE                                 (0x05u)
# define VHSM_KEYM_ACTION_KEYVALIDSET                                 (0x06u)
# define VHSM_KEYM_ACTION_RANDOMSEED                                  (0x07u)
# define VHSM_KEYM_ACTION_CERTIFICATEPARSE                            (0x08u)
# define VHSM_KEYM_ACTION_CERTIFICATEVERIFY                           (0x09u)
# define VHSM_KEYM_ACTION_KEYEXCHANGECALCPUBVAL                       (0x0Au)
# define VHSM_KEYM_ACTION_KEYEXCHANGECALCSECRET                       (0x0Bu)
# define VHSM_KEYM_ACTION_KEYELEMENTIDSGET                            (0x0Cu)
# define VHSM_KEYM_ACTION_KEYELEMENTCOPYPARTIAL                       (0x0Du)
# define VHSM_KEYM_ACTION_SIZE                                        (0x0Eu)

/* Job kinds */
# define VHSM_CRYPTO_JOBKIND                                          (0x00u)
# define VHSM_KEYM_JOBKIND                                            (0x01u)
# define VHSM_KEYM_COPY_PARTIAL_JOBKIND                               (0x02u)
# define VHSM_CRYPTO_MACGEN_JOBKIND                                   (0x03u)
# define VHSM_CRYPTO_MACVER_JOBKIND                                   (0x04u)
# define VHSM_CRYPTO_KEYDERIVE_JOBKIND                                (0x05u)
# define VHSM_JOBKIND_INVALID                                         (0x06u)
# define VHSM_NR_OF_JOBREQUESTKINDS                                   (VHSM_JOBKIND_INVALID)
# define VHSM_NR_OF_JOBRESPONSEKINDS                                  (VHSM_JOBKIND_INVALID)

/* Sanction kinds */
# define VHSM_SANCTION_NONE                                           (0x00u)
# define VHSM_SANCTION_RESET                                          (0x01u)
# define VHSM_SANCTION_CUSTOM                                         (0x02u)
# define VHSM_SANCTION_HALT                                           (0x03u)

/* Secureboot segment processing type */
# define VHSM_NONE                                                    (0x00u)
# define VHSM_PARALLEL                                                (0x01u)
# define VHSM_SEQUENTIAL                                              (0x02u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint32 vHsm_ChannelIdType;
typedef uint32 vHsm_JobRequestIdType;
typedef uint32 vHsm_KeyM_ActionType;
typedef uint8 vHsm_JobRequestKindType;
typedef uint8 vHsm_JobResponseKindType;

typedef struct
{
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) inputPtr;
  uint32 inputLength;
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) outputPtr;
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) outputLengthPtr;
  uint32 keyElementSourceOffset;
  uint32 keyElementTargetOffset;
  uint32 keyElementCopyLength;
} vHsm_KeyM_InputOutputType;

typedef struct
{
  vHsm_KeyM_ActionType action;
  uint32 cryIfKeyId;
  uint32 secondaryCryIfKeyId;
  uint32 keyElementId;
  uint32 secondaryKeyElementId;
  vHsm_KeyM_InputOutputType inputOutput;
} vHsm_KeyM_JobType;

typedef enum
{
  VHSM_JOB_STATE_IDLE,
  VHSM_JOB_STATE_WAITING,
  VHSM_JOB_STATE_PROCESSING,
  VHSM_JOB_STATE_ACTIVATED,
  VHSM_JOB_STATE_PENDING
}vHsm_JobObjectstateType;

typedef struct
{
  Crypto_JobType job;
  Crypto_JobPrimitiveInfoType jobPrimitiveInfo;
  Crypto_JobInfoType jobInfo;
  Crypto_PrimitiveInfoType primitiveInfo;
  Crypto_JobRedirectionInfoType jobRedirectionInfoRef;
}vHsm_Api_TempJobType;

typedef union
{ /* PRQA S 0750 */ /* MD_MSR_Union */
  vHsm_Api_TempJobType          crypto_Job;
  vHsm_KeyM_JobType             keyM_Job;
} vHsm_JobDataUnionType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* VHSM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Types.h
 *********************************************************************************************************************/
