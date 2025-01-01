/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - Type definitions
 *
 *  \description  Defines types, constants and configuration switches used by the security module
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#ifndef SECM_TYPES_H
#define SECM_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Global configuration */
#include "v_cfg.h"
#include "Fbl_Cfg.h"
/* Global definitions */
#include "v_def.h"

/* Additional header files */
#include "Std_Types.h"
#if defined( SEC_ENABLE_CSM )
# include "Csm_Types.h"
#endif /* SEC_ENABLE_CSM */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Defaults for configuration defines */


#if defined( SEC_WATCHDOG_CYCLE_COUNT )
#else
/** Watchdog triggered every n-th cycle (has to power of two) */
# define SEC_WATCHDOG_CYCLE_COUNT   (0x20u)
#endif

/**********************************************************************************************************************/

/* Return codes */

/** Positive return code */
#define SECM_OK      0x00u
/** Negative return code */
#define SECM_NOT_OK  0xFFu

#if defined( SEC_CALL_TYPE )
#else
/** Qualifier for function pointer declarations */
# define SEC_CALL_TYPE
#endif /* SEC_CALL_TYPE */

/** Null pointer for RAM data */
#define SEC_RAM_DATA_NULL              ((SecM_RamDataType)V_NULL)
/** Pointer to indicate use of internal default workspace */
#define SEC_DEFAULT_WORKSPACE          ((SecM_WorkspacePtrType)V_NULL)
/** Size to indicate use of internal default workspace */
#define SEC_DEFAULT_WORKSPACE_SIZE     0u
/** Size to indicate use of default key (e.g. for decryption) */
#define SEC_DEFAULT_KEY_SIZE           0u

/**********************************************************************************************************************/

/* Watchdog handling */

/** Empty watchdog trigger function pointer */
#define SEC_WATCHDOG_NONE              ((FL_WDTriggerFctType)0u)

/** Trigger watchdog
 *  Watchdog is disabled in case null pointer is passed */
#define SEC_WATCHDOG_TRIGGER(function)    \
   if ((SEC_WATCHDOG_NONE) != (function)) \
   {                                      \
      (function)();                       \
   }

#if ( SEC_WATCHDOG_CYCLE_COUNT == 1uL )
/** Trigger watchdog every cycle */
# define SEC_WATCHDOG_CYCLE_TRIGGER(function, cycle)           \
   {                                                           \
      SEC_WATCHDOG_TRIGGER(function);                          \
   }
#else /* SEC_WATCHDOG_CYCLE_COUNT > 1uL */
/** Trigger watchdog every n-th cycle */
# define SEC_WATCHDOG_CYCLE_TRIGGER(function, cycle)           \
   if (((cycle) & (SEC_WATCHDOG_CYCLE_COUNT - 1u)) == 0x00u)   \
   {                                                           \
      SEC_WATCHDOG_TRIGGER(function);                          \
   }
#endif /* SEC_WATCHDOG_CYCLE_COUNT == 1uL */

/**********************************************************************************************************************/

/* Type sizes */

/** Byte size of byte type */
#define SEC_BYTE_TYPE_SIZE    1u
/** Byte size of short type */
#define SEC_SHORT_TYPE_SIZE   2u
/** Byte size of word type */
#define SEC_WORD_TYPE_SIZE    4u

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/* Types specified by HIS specification */

/** Data type for word values (32 bit) */
typedef vuint32 SecM_WordType;

/* Supporting data types for easier handling */

/** Data type for byte values (8 bit)*/
typedef vuint8  SecM_ByteType;
/** Data type for short values (16 bit) */
typedef vuint16 SecM_ShortType;

/** Pointer type to byte data in RAM */
typedef V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 *       SecM_RamDataType;
/** Pointer type to short data in RAM */
typedef V_MEMRAM1 SecM_ShortType V_MEMRAM2 V_MEMRAM3 *      SecM_RamShortType;
/** Pointer type to word data in RAM */
typedef V_MEMRAM1 SecM_WordType V_MEMRAM2 V_MEMRAM3 *       SecM_RamWordType;
/** Pointer type to constant byte data in RAM */
typedef const V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * SecM_ConstRamDataType;
/** Pointer type to constant word data in RAM */
typedef const V_MEMRAM1 SecM_WordType V_MEMRAM2 V_MEMRAM3 * SecM_ConstRamWordType;
/** Pointer type to byte data in ROM */
typedef V_MEMROM1 SecM_ByteType V_MEMROM2 V_MEMROM3 *       SecM_RomDataType;
/** Void pointer type */
typedef V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 *                SecM_VoidPtrType;
/** Void pointer type (const) */
typedef const V_MEMRAM1 void V_MEMRAM2 V_MEMRAM3 *          SecM_ConstVoidPtrType;
/** Void pointer type to ROM memory */
typedef V_MEMROM1 void V_MEMROM2 V_MEMROM3 *                SecM_RomVoidPtrType;

/**********************************************************************************************************************/

/* Types specified by HIS specification */

/** Data type for status codes */
typedef SecM_ByteType SecM_StatusType;
/** Data type for length information */
typedef SecM_ShortType SecM_LengthType;

/** Data type for address information */
typedef SecM_WordType SecM_AddrType;
/** Data type for size information */
typedef SecM_WordType SecM_SizeType;

/** Description of a download segment */
typedef struct
{
   SecM_AddrType transferredAddress;
   SecM_AddrType targetAddress;
   SecM_SizeType length;
} FL_SegmentInfoType;

/** List of downloaded segments */
typedef struct
{
   /** Number of segments in list */
   SecM_WordType        nrOfSegments;
   /** List of segments */
   /* According to HIS specification */
   V_MEMRAM1 FL_SegmentInfoType V_MEMRAM2 V_MEMRAM3 * segmentInfo;
} FL_SegmentListType;

/** Pointer to watchdog trigger function */
typedef void (* FL_WDTriggerFctType)( void );
/** Pointer to memory read function */
typedef SecM_SizeType (* FL_ReadMemoryFctType)( SecM_AddrType address, SecM_RamDataType buffer, SecM_SizeType length );

/**********************************************************************************************************************/

/* Fast types (used for loops) */

#if defined( C_CPUTYPE_8BIT )
/** Fast type which can hold at least a byte */
typedef SecM_ByteType   SecM_ByteFastType;
/** Fast type which can hold at least a short */
typedef SecM_ShortType  SecM_ShortFastType;
#elif defined( C_CPUTYPE_16BIT )
typedef SecM_ShortType  SecM_ByteFastType;
typedef SecM_ShortType  SecM_ShortFastType;
#elif defined( C_CPUTYPE_32BIT )
typedef SecM_WordType   SecM_ByteFastType;
typedef SecM_WordType   SecM_ShortFastType;
#endif /* C_CPUTYPE */

/** Fast type which can hold length information */
typedef SecM_ShortFastType SecM_LengthFastType;

/**********************************************************************************************************************/

/* Buffer types */

/** Information of buffer located in RAM */
typedef struct
{
   /** Pointer to data */
   SecM_ConstRamDataType   data;
   /** Buffer size given in byte */
   SecM_LengthType         size;
} SecM_RamBufferType;

/** Information of buffer located in ROM */
typedef struct
{
   /** Pointer to data */
   SecM_RomDataType  data;
   /** Buffer size given in byte */
   SecM_LengthType   size;
} SecM_RomBufferType;

/** Information of special buffer located in RAM with current position information */
typedef struct
{
   /** Pointer to data */
   SecM_RamDataType buffer;
   /** Current index position */
   SecM_ShortType pos;
   /** Buffer size given in byte */
   SecM_LengthType size;
} SecM_RamBufferProcessingType;

/** Pointer type to SecM_RamBufferProcessingType in RAM */
typedef V_MEMRAM1 SecM_RamBufferProcessingType V_MEMRAM2 V_MEMRAM3 * SecM_RamBufferProcessingPtrType;

/*********************************************************************************************************************/

/* Workspace types */

/** Basic workspace structure used for aligned pointer type */
typedef struct
{
   SecM_ByteType  digest[1];  /**< Placeholder for message digest located at beginning of every workspace */
   SecM_WordType  dummy;      /**< Dummy member to enforce alignment, not actually used */
} SecM_BasicWkspType;

/** Pointer to aligned workspace */
typedef V_MEMRAM1 SecM_BasicWkspType V_MEMRAM2 V_MEMRAM3 * SecM_WorkspacePtrType;

/** Reference to workspace */
typedef struct
{
   /** Pointer to data */
   SecM_WorkspacePtrType   data;
   /** Buffer size given in byte */
   SecM_LengthType         size;
} SecM_WorkspaceType;

/** Reference to verification workspace */
typedef struct
{
   /** Pointer to data */
   SecM_ByteType   *data;
   /** Buffer size given in byte */
   SecM_WordType size;
} SecM_VerificationWksp;

/*********************************************************************************************************************/

/* Cryptographic key types */

/** Reference to cryptographic key */
#if defined( SEC_ENABLE_KEY_LOCATION_RAM )
typedef SecM_RamBufferType SecM_CryptKeyType;
#else
typedef SecM_RomBufferType SecM_CryptKeyType;
#endif /* SEC_ENABLE_KEY_LOCATION_RAM */

/** Reference to symmetric cryptographic key (always located in RAM) */
typedef SecM_RamBufferType SecM_SymKeyType;

/** Reference to asymmetric cryptographic key pair */
typedef struct
{
   /** Shared key */
   SecM_CryptKeyType shared;
   /** Individual (public) key */
   SecM_CryptKeyType individual;
} SecM_AsymKeyType;

/** Reference to AES key (key and IV) */
typedef struct
{
   /** Shared key */
   SecM_CryptKeyType key;
   /** Individual (public) key */
   SecM_CryptKeyType iv;
} SecM_AesKeyType;

/** Reference to PBKDF2 input parameters */
typedef struct
{
   SecM_CryptKeyType    iterations;
   SecM_CryptKeyType    salt;
   SecM_CryptKeyType    password;
   SecM_CryptKeyType    function;
} SecM_PBKDF2KeyType;

/** Reference to the cryptographic key value (always located in ROM) */
typedef struct
{
   /** Pointer to data */
   SecM_RomDataType  data;
   /** Buffer size given in byte */
   SecM_LengthType   size;
   /** Corresponding CryptoKeyElementId */
   uint32 cryptoElementId;
} SecM_CryptographicKeyValueType;

/** Pointer to the cryptographic key value */
typedef V_MEMROM1 SecM_CryptographicKeyValueType V_MEMROM2 V_MEMROM3 * SecM_CryptographicKeyValuePtrType;

/** Reference to the cryptographic keys */
typedef struct
{
   SecM_ByteType count;
   SecM_CryptographicKeyValuePtrType keyValues;
} SecM_CryptographicKeyType;

/** Pointer to the cryptographic keys */
typedef V_MEMROM1 SecM_CryptographicKeyType V_MEMROM2 V_MEMROM3 * SecM_CryptographicKeyPtrType;

/*********************************************************************************************************************/

/* Job types */

/** Specifies the SECM services */
typedef enum
{
   SECM_HASH,
   SECM_MACVERIFY,
   SECM_MACGENERATE,
   SECM_ENCRYPTION,
   SECM_DECRYPTION,
   SECM_RANDOMGENERATE,
   SECM_RANDOMSEED,
   SECM_SIGNATUREVERIFY,
   SECM_AEADENCRYPT,
   SECM_AEADDECRYPT,
   SECM_KEYDERIVE
} SecM_JobServiceType;

/** Specifies the supported key types */
typedef enum
{
   SEC_KEY_TYPE_NONE,
   SEC_KEY_TYPE_AES,
   SEC_KEY_TYPE_MAC,
   SEC_KEY_TYPE_SYMMETRIC,
   SEC_KEY_TYPE_ASYMMETRIC,
   SEC_KEY_TYPE_PBKDF2
} SecM_JobKeyType;

typedef enum
{
   SEC_BUFF_UNTIL_FULL,
   SEC_BUFF_FIFO
} SecM_BufferMode;

typedef enum
{
   SEC_BUFF_OK,
   SEC_BUFF_FULL
} SecM_BufferRetType;

typedef enum
{
   SECM_DECRAEAD_AUTHDATA,
   SECM_DECRAEAD_DECRYPT
} SecM_DecrStatusFsm;

/** Job Param type for AEAD decryption primitive */
typedef struct
{
   SecM_ShortType                   authDataLength;   /**< Length of the authentication data */
   SecM_ShortType                   dataTagLength;    /**< Length of the Tag */
} SecM_JobDecryptionAEADParamTypes;

/** Structure of a SECM job */
typedef struct
{
   SecM_JobServiceType service;
   uint32 csmJobId;
   uint32 csmKeyId;
   SecM_WordType smhKeyId;
   SecM_JobKeyType keyType;
   SecM_RomVoidPtrType jobParam;
} SecM_JobInfoType;

/** Pointer to a SECM job */
typedef V_MEMROM1 SecM_JobInfoType V_MEMROM2 V_MEMROM3 * SecM_JobInfoPtrType;

/** Operation modes of the SECM */
#if defined( SEC_ENABLE_CSM )
typedef Crypto_OperationModeType SecM_OperationModeType;
# define SECM_OPERATIONMODE_NONE           (0u)
# define SECM_OPERATIONMODE_START          CRYPTO_OPERATIONMODE_START
# define SECM_OPERATIONMODE_IV             (0x10u)
# define SECM_OPERATIONMODE_UPDATE         CRYPTO_OPERATIONMODE_UPDATE
# define SECM_OPERATIONMODE_FINISH         CRYPTO_OPERATIONMODE_FINISH
# define SECM_OPERATIONMODE_STREAMSTART    CRYPTO_OPERATIONMODE_STREAMSTART
# define SECM_OPERATIONMODE_SINGLECALL     CRYPTO_OPERATIONMODE_SINGLECALL
#endif /* SEC_ENABLE_CSM */

/*********************************************************************************************************************/

/* Decryption/encryption types */
#if defined( SEC_ENABLE_ENCRYPTION ) || defined( SEC_ENABLE_DECRYPTION )
/** Input data passed to SecM_Decryption interface */
typedef struct
{
   SecM_ConstRamDataType   DataBuffer; /**< Pointer to encrypted input data */
   SecM_LengthType         Length;     /**< Length of input data */
} SecM_DecInputParamType;

/** Output data passed to SecM_Decryption interface */
typedef struct
{
   SecM_RamDataType        DataBuffer; /**< Pointer to decrypted output data */
   SecM_LengthType         Length;     /**< Length of output buffer / data */
} SecM_DecOutputParamType;

/** Parameter structure for SecM_Decryption interface */
typedef struct
{
   /** Start address of the segment */
   SecM_AddrType           segmentAddress;
   /** Length of segment in bytes */
   SecM_SizeType           segmentLength;
   /** Data format ID of encryption and compression */
   SecM_ByteType           mode;
   /** Pointer to watchdog trigger function */
   FL_WDTriggerFctType     wdTriggerFct;
   /* The following members are an extension of the HIS specification */
   /** Reference to decryption key */
   SecM_SymKeyType         key;
} SecM_DecParamType;

/** Pointer to the Smh decryption/encryption job function */
typedef SecM_StatusType(*SecM_JobDecryptionType)     (SecM_WordType jobId, SecM_OperationModeType mode, SecM_VoidPtrType keyPtr,
   SecM_ConstRamDataType dataPtr, SecM_WordType dataLength, SecM_RamDataType resultPtr, SecM_WordType * resultLengthPtr);

/** Parameters of encryption / decryption primitive */
typedef struct
{
   SecM_JobDecryptionType           func;       /**< Pointer to the function */
   SecM_WordType                    jobId;      /**< Smh job ID */
} SecM_DecPrimitiveType;

#endif /* SEC_ENABLE_ENCRYPTION || SEC_ENABLE_DECRYPTION */
/*********************************************************************************************************************/

/* Verification types */

/* CRC types */
#if defined( SEC_ENABLE_CRC )
/** Type for CRC value */
typedef SecM_ShortType  SecM_Crc16Type;
typedef SecM_WordType   SecM_Crc32Type;
typedef SecM_WordType   SecM_Crc64BaseType;
typedef struct
{
   SecM_Crc64BaseType   highWord;   /** High word of CRC-64 */
   SecM_Crc64BaseType   lowWord;    /** Low word of CRC-64 */
} SecM_Crc64Type;

# if (SEC_CRC_TYPE == SEC_CRC16 )
typedef SecM_Crc16Type        SecM_CRCType;
# elif ( SEC_CRC_TYPE == SEC_CRC32 )
typedef SecM_Crc32Type        SecM_CRCType;
# elif ( SEC_CRC_TYPE == SEC_CRC64 )
typedef SecM_Crc64Type        SecM_CRCType;
# else
#  error "Unknown CRC type."
# endif

typedef void * SecM_CRCParamGenericType;
typedef SecM_StatusType(*SecM_CRCFunctionGenericType) (void * crcParam);

/** CRC primitive type */
typedef struct
{
   SecM_ByteType crcType;
   SecM_CRCFunctionGenericType pCrcFunc;
   SecM_ByteType crcSize;
   boolean computationOnly;
   boolean updateVerifiedData;
} SecM_CrcPrimitiveType;
#else
typedef SecM_WordType   SecM_CRCType;
#endif /* SEC_ENABLE_CRC */

/** Hash primitive type */
typedef struct
{
   SecM_WordType jobId;
   SecM_RamDataType digest;
   SecM_LengthType digestLength;
   boolean computationOnly;
   boolean updateVerifiedData;
} SecM_HashPrimitiveType;

/** Mac primitive type */
typedef struct
{
   SecM_WordType jobId;
   SecM_WordType contextBufferSize;
   V_MEMRAM1 SecM_VerificationWksp V_MEMRAM2 V_MEMRAM3 * pVerWks;
   boolean computationOnly;
   boolean updateVerifiedData;
} SecM_MacPrimitiveType;

/** Signature primitive type */
typedef struct
{
   SecM_WordType jobId;
   SecM_WordType hashJobId;
   SecM_RamDataType hashDigest;
   SecM_LengthType hashDigestLength;
   SecM_WordType contextBufferSize;
   V_MEMRAM1 SecM_VerificationWksp V_MEMRAM2 V_MEMRAM3 * pVerWks;
   boolean updateVerifiedData;
} SecM_SigPrimitiveType;

/* Key derive primitive type */
typedef struct
{
   SecM_WordType  jobId;
   uint32         targetKeyId;
} SecM_KeyDerivePrimitiveType;

/* General types */

/** Type to reference current hash value (also used to pass workspace) */
/* According to HIS specification: store address as unsigned 32 bit integer */
typedef SecM_SizeType         SecM_ResultBufferType;

/** Anonymous pointer to verification key (actual type depending on security class) */
typedef SecM_VoidPtrType      SecM_VerifyKeyType;

/** Pointer to verification data */
typedef SecM_RamDataType      SecM_VerifyDataType;

/** Parameter structure for SecM_Verification interface */
typedef struct
{
   /** Address and length information of download segments */
   /* According to HIS specification */
   FL_SegmentListType   segmentList;
   /** Start address of logical block */
   SecM_AddrType        blockStartAddress;
   /** Length of logical block */
   SecM_SizeType        blockLength;
   /** Pointer to verification data (e.g. checksum and/or signature) */
   SecM_VerifyDataType  verificationData;
   /** CRC total calculated over full logical block */
   SecM_CRCType         crcTotal;
   /** Pointer to watchdog trigger function */
   FL_WDTriggerFctType  wdTriggerFct;
   /** Pointer to memory read function */
   FL_ReadMemoryFctType readMemory;
   /* The following members are an extension of the HIS specification */
   /** Reference to workspace */
   SecM_WorkspaceType   workspace;
   /** Pointer to verification key */
   SecM_VerifyKeyType   key;
} SecM_VerifyParamType;

/** Structure to describe current hash value (also used to pass workspace) */
typedef struct
{
   SecM_ResultBufferType sigResultBuffer;
   SecM_SizeType         length;
} SecM_SignatureType;

/* Parameter structure for signature verification */
typedef struct
{
   /** Reference to current hash value (also used to pass workspace) */
   SecM_SignatureType   currentHash;
   /** Pointer to the current length of the hashed data */
   V_MEMRAM1 SecM_SizeType V_MEMRAM2 V_MEMRAM3 * currentDataLength;
   /** Signature state / operation to be executed */
   SecM_StatusType      sigState;
   /** Pointer to input or verification data */
   SecM_VerifyDataType  sigSourceBuffer;
   /** Size of input or verification data */
   SecM_LengthType      sigByteCount;
   /** Pointer to watchdog trigger function */
   FL_WDTriggerFctType  wdTriggerFct;
   /* The following members are an extension of the HIS specification */
   /** Pointer to verification key */
   SecM_VerifyKeyType   key;
} SecM_SignatureParamType;

/* Types for CRC workspace */
typedef enum
{
   CRC_WORKSPACE_UNDEF,
   CRC_WORKSPACE_INIT
} SecM_CrcWorkspaceStateType;

typedef struct
{
   SecM_ResultBufferType workspacePtr;
   SecM_SizeType workspaceLength;
   SecM_CrcWorkspaceStateType state;
} SecM_CrcWorkspaceInfoType;

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#if ( 0u == SEC_WATCHDOG_CYCLE_COUNT ) || \
    ( (SEC_WATCHDOG_CYCLE_COUNT & (SEC_WATCHDOG_CYCLE_COUNT - 1u)) != 0u )
# error "Error in SEC_TYPES.H: Watchdog cycle count has to be a power of two (2^n)!"
#endif

#endif /* SECM_TYPES_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC_TYPES.H
 **********************************************************************************************************************/
