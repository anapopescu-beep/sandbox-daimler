/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file   Crypto_30_vHsm_Types.h
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

#if !defined (CRYPTO_30_VHSM_TYPES_H)
# define CRYPTO_30_VHSM_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Csm_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* vHsm Number of job request kinds */
# define CRYPTO_30_VHSM_CRYPTO_JOBKIND                                (0u) /*!< Job kind for Crypto jobs */
# define CRYPTO_30_VHSM_KEYMANAGEMENT_JOBKIND                         (1u) /*!< Job kind for Key Management jobs */
# define CRYPTO_30_VHSM_KEYMANAGEMENT_COPY_PARTIAL_JOBKIND            (2u) /*!< Job kind for Key Element Copy Partial jobs */
# define CRYPTO_30_VHSM_CRYPTO_MACGEN_JOBKIND                         (3u) /*!< Job kind for MAC Generate jobs */
# define CRYPTO_30_VHSM_CRYPTO_MACVER_JOBKIND                         (4u) /*!< Job kind for MAC Verify jobs */
# define CRYPTO_30_VHSM_KEYMANAGEMENT_KEYDERIVEJOB_JOBKIND            (5u) /*!< Job kind for MAC Verify jobs */
# define CRYPTO_30_VHSM_JOBKIND_INVALID                               (6u) /*!< Invalid Job kind */
# define CRYPTO_30_VHSM_NR_OF_JOBKINDS                                (CRYPTO_30_VHSM_JOBKIND_INVALID) /*!< Number of valid job kinds */

/* vHsm Key management actions */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTSET                     (0x00u) /*!< Action for Crypto_30_KeyElementSet() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTGET                     (0x01u) /*!< Action for Crypto_30_KeyElementGet() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTCOPY                    (0x02u) /*!< Action for Crypto_30_KeyElementCopy() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYCOPY                           (0x03u) /*!< Action for Crypto_30_KeyCopy() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYDERIVE                         (0x04u) /*!< Action for Crypto_30_KeyDerive() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYGENERATE                       (0x05u) /*!< Action for Crypto_30_KeyGenerate() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYVALIDSET                       (0x06u) /*!< Action for Crypto_30_KeyValidSet() */
# define CRYPTO_30_VHSM_KEYM_ACTION_RANDOMSEED                        (0x07u) /*!< Action for Crypto_30_RandomSeed() */
# define CRYPTO_30_VHSM_KEYM_ACTION_CERTIFICATEPARSE                  (0x08u) /*!< Action for Crypto_30_CertificateParse() */
# define CRYPTO_30_VHSM_KEYM_ACTION_CERTIFICATEVERIFY                 (0x09u) /*!< Action for Crypto_30_CertificateVerify() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYEXCHANGECALCPUBVAL             (0x0Au) /*!< Action for Crypto_30_KeyExchangeCalcPubVal() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYEXCHANGECALCSECRET             (0x0Bu) /*!< Action for Crypto_30_KeyExchangeCalcSecret() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTIDSGET                  (0x0Cu) /*!< Action for Crypto_30_KeyElementIdsGet() */
# define CRYPTO_30_VHSM_KEYM_ACTION_KEYELEMENTCOPYPARTIAL             (0x0Du) /*!< Action for Crypto_30_KeyElementCopyPartial() */
# define CRYPTO_30_VHSM_KEYM_ACTION_INVALID                           (0x0Eu) /*!< Invalid Job kind */
# define CRYPTO_30_VHSM_NR_OF_KEYM_ACTION                             (CRYPTO_30_VHSM_KEYM_ACTION_INVALID) /*!< Number of valid job kinds */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8   Crypto_30_vHsm_ChannelIdType;

typedef P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) Crypto_30_vHsm_JobRequestBufferPtrType;
typedef P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA)  Crypto_30_vHsm_JobResponseBufferPtrType;

typedef uint32   Crypto_30_vHsm_JobResponseBufferSizeType;
typedef uint32   Crypto_30_vHsm_JobRequestBufferSizeType;

typedef uint32 Crypto_30_vHsm_KeyM_ActionType;

/*! Struct containing the input and output information of a KeyM job */
typedef struct Crypto_30_vHsm_KeyM_InputOutputTypeStruct
{
  P2CONST(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA) inputPtr;        /*!< Pointer for the input data */
  uint32 inputLength;                                                 /*!< Size of the input data */
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) outputPtr;         /*!< Pointer for the output data */
  P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) outputLengthPtr;  /*!< Size of the output data */
  uint32 keyElementSourceOffset;                                      /*!< offset for the source key element during key element copy partial */
  uint32 keyElementTargetOffset;                                      /*!< offset for the target key element during key element copy partial */
  uint32 keyElementCopyLength;                                        /*!< Number of bytes to copy during key element copy partial */
} Crypto_30_vHsm_KeyM_InputOutputType;

/*! Struct containing basic information about a KeyM job */
typedef struct Crypto_30_vHsm_KeyM_JobTypeStruct
{
  Crypto_30_vHsm_KeyM_ActionType action;                              /*!< action which shall be performed (e.g. KeyElementGet, KeyElementSet,...) */
  uint32 cryptoKeyId;                                                 /*!< Id of they key */
  uint32 secondaryCryptoKeyId;                                        /*!< Id of they secondary key */
  uint32 keyElementId;                                                /*!< Id of they key element */
  uint32 secondaryKeyElementId;                                       /*!< Id of they secondary key element */
  Crypto_30_vHsm_KeyM_InputOutputType inputOutput;                    /*!< struct containing the input and output information */
} Crypto_30_vHsm_KeyM_JobType;

typedef uint8 Crypto_30_vHsm_JobKindType;

#endif /* CRYPTO_30_VHSM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Types.h
 *********************************************************************************************************************/
