/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Implementation of the HIS security module - Seed/key authentication
 *
 *  \description  Offers challenge/response authentication interface
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

#ifndef SEC_SEEDKEY_H
#define SEC_SEEDKEY_H

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

/* Interface version */
/** Major interface version identifies incompatible changes */
#define SECACCESS_API_VERSION_MAJOR       0x01u
/** Minor interface version identifies backward compatible changes */
#define SECACCESS_API_VERSION_MINOR       0x02u
/** Release interface version identifies cosmetic changes */
#define SECACCESS_API_VERSION_RELEASE     0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec_Inc.h"

/* If the SeedKey is removed from the generator, the complete module will not be compiled */
#if defined( SEC_ENABLE_SEEDKEY )

#include "Sec_SeedKey_Cfg.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( SEC_BYTE_ARRAY_SEED )
/** Length of initial seed value */
# if (SEC_SEED_LENGTH < SEC_WORD_TYPE_SIZE)
#  define SEC_INITIAL_SEED_LENGTH   SEC_SEED_LENGTH
# else
#  define SEC_INITIAL_SEED_LENGTH   SEC_WORD_TYPE_SIZE
# endif /* SEC_SEED_LENGTH < SEC_WORD_TYPE_SIZE */
#elif defined( SEC_WORD_ARRAY_SEED )
# define SEC_INITIAL_SEED_LENGTH    SEC_WORD_TYPE_SIZE
/** Convert seed length in bytes to length in words */
# define SEC_SEED_WORD_LENGTH       (((SEC_SEED_LENGTH - 1u) / SEC_WORD_TYPE_SIZE) + 1u)
#else
# define SEC_INITIAL_SEED_LENGTH    (SEC_WORD_TYPE_SIZE * 2u)
#endif /* SEC_<type>_ARRAY_SEED */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* Supporting data types for easier handling */

#if defined( SEC_BYTE_ARRAY_KEY )
/* This is a deviation from the HIS specification! */
/** Base type for key data */
typedef SecM_ByteType      SecM_KeyBaseType;
/** Type for actual key data storage */
typedef SecM_KeyBaseType   SecM_KeyStorageType[SEC_KEY_LENGTH];
#else
/* According to HIS specification */
/** Base type for key data */
typedef SecM_WordType      SecM_KeyBaseType;
/** Type for actual key data storage */
typedef SecM_KeyBaseType   SecM_KeyStorageType;
#endif /* SEC_BYTE_ARRAY_KEY */

#if defined( SEC_BYTE_ARRAY_SEED )
/* This is a deviation from the HIS specification! */
/** Base type for seed data */
typedef SecM_ByteType      SecM_SeedBaseType;
/** Type for seed values */
typedef SecM_SeedBaseType  SecM_SeedStorageType[SEC_SEED_LENGTH];
#elif defined( SEC_WORD_ARRAY_SEED )
/* This is a deviation from the HIS specification! */
/** Base type for seed data */
typedef SecM_WordType      SecM_SeedBaseType;
/** Type for seed values */
typedef SecM_SeedBaseType  SecM_SeedStorageType[SEC_SEED_WORD_LENGTH];
#else
/* According to HIS specification */
/** Base type for key constant */
typedef struct
{
   SecM_WordType seedX;
   SecM_WordType seedY;
} SecM_SeedBaseType;
/** Type for actual key data storage */
typedef SecM_SeedBaseType  SecM_SeedStorageType;
#endif /* SEC_<type>_ARRAY_SEED */

typedef SecM_WordType      SecM_ConstBaseType;

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API ) || \
    defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
/** Common information required by extended API */
typedef struct
{
   /** Workspace required by key computation */
   SecM_WorkspaceType   workspace;
   /** Watchdog trigger function */
   FL_WDTriggerFctType  wdTriggerFct;
} SecM_SeedKeyContextType;
#endif /* SEC_ENABLE_SEED_KEY_EXTENDED_API || SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */

#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
typedef SecM_SeedKeyContextType  SecM_GenerateSeedParamType;
#endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )
/* Extended seed/key API */

typedef SecM_SeedKeyContextType  SecM_ComputeKeyParamType;

/** Information for symmetric key algorithm */
typedef struct
{
   /** Common information */
   SecM_ComputeKeyParamType   common;
   /** Secret key */
   SecM_SymKeyType            secretKey;
} SecM_ComputeKeySymParamType;

/** Information for asymmetric key algorithm */
typedef struct
{
   /** Common information */
   SecM_ComputeKeyParamType   common;
   /** Public key pair */
   SecM_AsymKeyType           publicKey;
} SecM_ComputeKeyAsymParamType;

/* This is a deviation from the HIS specification! */
/** Type for key constants */
typedef struct
{
   /** Constant for key calculation */
   SecM_ConstBaseType   constant;
   /** Additional context information, e.g. workspace */
   SecM_VoidPtrType     context;
} SecM_ConstType;
#else
/** Type for key constants */
typedef SecM_ConstBaseType SecM_ConstType;
#endif /* SEC_ENABLE_SEED_KEY_EXTENDED_API */

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
/** Intialization state of random number generator */
typedef enum
{
   SEC_RNG_UNINTIALIZED,   /**< Uninitialized state */
   SEC_RNG_INTIALIZED      /**< Initialized state */
} SecM_RngState;

/** Entropy pool type */
typedef struct
{
   SecM_ByteType     data[SEC_ENTROPY_POOL_SIZE];  /**< Actual entropy data (ring buffer) */
   SecM_LengthType   fillLevel;                    /**< Fill level of entropy pool, saturates at pool size */
   SecM_LengthType   offset;                       /**< Current position in ring buffer */
   SecM_RngState     state;                        /**< Initialization state of random number generator */
   SecM_VoidPtrType  context;                      /**< Not used anymore, kept for backward compatibility */
} SecM_EntropyPoolType;
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL */

/**********************************************************************************************************************/

/* Types specified by HIS specification */

/** Type for seed values */
#if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
/* This is a deviation from the HIS specification! */
/** Type for seed values */
typedef struct
{
   /** Pointer to actual seed data */
   V_MEMRAM1 SecM_SeedBaseType V_MEMRAM2 V_MEMRAM3 *     data;
   V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 *  entropyPool;
} SecM_SeedType;
#else
typedef SecM_SeedStorageType  SecM_SeedType;
#endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )
/* Extended seed/key API */

/* This is a deviation from the HIS specification! */
/** Type for key values */
typedef struct
{
   /** Pointer to actual key data */
   V_MEMRAM1 SecM_KeyBaseType V_MEMRAM2 V_MEMRAM3 *   data;
   /** Additional context information, e.g. workspace */
   SecM_VoidPtrType                                   context;
} SecM_KeyType;
#else
/** Type for key values */
typedef SecM_KeyStorageType   SecM_KeyType;
#endif /* SEC_ENABLE_SEED_KEY_EXTENDED_API */

/* Pointer types for API-functions */
typedef SecM_StatusType SEC_CALL_TYPE (* pSecGenerateSeedFct)( V_MEMRAM1 SecM_SeedType V_MEMRAM2 V_MEMRAM3 * seed );
#if defined( SEC_ENABLE_SEED_KEY_ASYMMETRIC )
typedef SecM_StatusType SEC_CALL_TYPE (* pSecComputeKeyFct)( SecM_KeyStorageType inputKey, SecM_ConstType constant,
   V_MEMRAM1 SecM_SeedStorageType V_MEMRAM2 V_MEMRAM3 * computedSeed );
#else
typedef SecM_StatusType SEC_CALL_TYPE (* pSecComputeKeyFct)( SecM_SeedStorageType inputSeed, SecM_ConstType constant,
   V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey );
#endif /* SEC_ENABLE_SEED_KEY_ASYMMETRIC */
typedef SecM_StatusType SEC_CALL_TYPE (* pSecCompareKeyFct)( SecM_KeyType key, SecM_SeedType lastSeed );

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#if defined( __cplusplus )
extern "C" {
#endif

/* Functions specified by HIS specification */

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern SecM_StatusType SecM_GenerateSeed( V_MEMRAM1 SecM_SeedType V_MEMRAM2 V_MEMRAM3 * seed );
#if defined( SEC_ENABLE_SEED_KEY_ASYMMETRIC )
extern SecM_StatusType SecM_ComputeKey( SecM_KeyStorageType inputKey, SecM_ConstType constant,
   V_MEMRAM1 SecM_SeedStorageType V_MEMRAM2 V_MEMRAM3 * computedSeed );
#else
extern SecM_StatusType SecM_ComputeKey( SecM_SeedStorageType inputSeed, SecM_ConstType constant,
   V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey );
#endif /* SEC_ENABLE_SEED_KEY_ASYMMETRIC */
extern SecM_StatusType SecM_CompareKey( SecM_KeyType key, SecM_SeedType lastSeed );

/**********************************************************************************************************************/

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL ) && \
    defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
void SecM_InitEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool );

# define SECM_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define SECM_RAMCODE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
void SecM_ProvideEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool,
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * entropy, SecM_LengthType length );
# define SECM_RAMCODE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define SECM_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL && SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
extern SecM_StatusType SecM_CompareKeyVendor( SecM_KeyStorageType key, SecM_SeedStorageType seed, SecM_ConstType constant );
#else
# if defined( SEC_ENABLE_SEED_KEY_ASYMMETRIC )
extern SecM_StatusType SecM_ComputeKeyVendor( SecM_KeyStorageType inputKey, SecM_ConstType constant,
   V_MEMRAM1 SecM_SeedStorageType V_MEMRAM2 V_MEMRAM3 * computedSeed );
# else
extern SecM_StatusType SecM_ComputeKeyVendor( SecM_SeedStorageType inputSeed, SecM_ConstType constant,
   V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey );
# endif /* SEC_ENABLE_SEED_KEY_ASYMMETRIC */
#endif /* SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( __cplusplus )
} /* extern "C" */
#endif

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#if defined( SEC_WORD_ARRAY_SEED )
# if ( (SEC_SEED_LENGTH % 4u) != 0u )
#  error "Error in configuration: Seed lengths (in bytes) has to be a multiple of 4!"
# endif
#endif /* SEC_WORD_ARRAY_SEED */

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )
# if defined( SEC_BYTE_ARRAY_SEED ) || \
     defined( SEC_WORD_ARRAY_SEED )
# else
#  error "Error in configuration: Asymmetric seed/key calculation only supports seed data stored as array!"
# endif /* SEC_BYTE_ARRAY_SEED || SEC_WORD_ARRAY_SEED */
#endif /* SEC_ENABLE_SEED_KEY_EXTENDED_API */
#endif /* SEC_ENABLE_SEEDKEY */
#endif /* SEC_SEEDKEY_H */

/***********************************************************************************************************************
 *  END OF FILE: SEC_SEEDKEY.H
 **********************************************************************************************************************/
