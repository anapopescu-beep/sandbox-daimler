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

#define SEC_SEEDKEY_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Security module configuration settings */
#include "Sec_Inc.h"

/* If the SeedKey is removed from the generator, the complete module will not be compiled */
#if defined( SEC_ENABLE_SEEDKEY )

/* Global definitions for security module */
#include "Sec_Types.h"

/* Interfaces of seed-key */
#include "Sec_SeedKey.h"

#include "Sec.h"

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

/* Interface version compatibility check */
#if defined( SECACCESS_API_REFERENCE_VERSION_MAJOR ) && \
    defined( SECACCESS_API_REFERENCE_VERSION_MINOR )
#else
# error "Error in Sec_SeedKey.c: Interface version requirements not defined!"
#endif

#if ( SECACCESS_API_REFERENCE_VERSION_MAJOR != SECACCESS_API_VERSION_MAJOR) || \
    ( SECACCESS_API_REFERENCE_VERSION_MINOR > SECACCESS_API_VERSION_MINOR)
# error "Error in Sec_SeedKey.c: Interface version compatibility check failed!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/


/* PRQA S 3453 TAG_SecSeeKey_3453_1 */ /* MD_CBD_19.7 */

/* Clear by default */
#if defined( SEC_COMPARE_SIZE )
# undef SEC_COMPARE_SIZE
#endif /* SEC_COMPARE_SIZE */

/* Adaptation of seed/key comparison in SecM_CompareKey */
# if defined( SEC_BYTE_ARRAY_KEY )
/** Array size of compared key */
#  define SEC_COMPARE_SIZE    SEC_KEY_LENGTH
# endif /* SEC_BYTE_ARRAY_KEY */
# if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )
/** Variable member to be compared with computed value */
#  define SEC_COMPARE_VALUE   key.data
# else
/** Variable to be compared with computed value */
#  define SEC_COMPARE_VALUE   key
# endif /* SEC_ENABLE_SEED_KEY_EXTENDED_API */

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL ) && \
    defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
/** Access base type of seed parameter */
# if defined( SEC_BYTE_ARRAY_SEED ) || \
     defined( SEC_WORD_ARRAY_SEED )
#  define SEC_BASE_SEED(seed)  ((seed).data)
# else
#  define SEC_BASE_SEED(seed)  (*((seed).data))
# endif /* SEC_BYTE_ARRAY_SEED || SEC_WORD_ARRAY_SEED */
#else
/** Access seed parameter directly */
# define SEC_BASE_SEED(seed)  (seed)
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL && SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */

#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )
/** Access base type of key parameter */
# define SEC_BASE_KEY(key)    ((key).data)
#else
/** Access key parameter directly */
# define SEC_BASE_KEY(key)    (key)
#endif /* SEC_ENABLE_SEED_KEY_EXTENDED_API */

/* PRQA L:TAG_SecSeeKey_3453_1 */

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/** Base type of seed/key comparison in SecM_CompareKey */
typedef SecM_KeyStorageType   SecM_CompareType;

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

static SecM_StatusType SecM_GenerateRandom( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom, SecM_WordType length );
#if defined( SEC_ENABLE_SEED_KEY_PRNG_LCG )
static SecM_WordType SecM_LcgRandom( SecM_WordType input );
static SecM_StatusType SecM_GenerateRandomLcg( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom,
   V_MEMRAM1 SecM_WordType V_MEMRAM2 V_MEMRAM3 * pLength );
#endif /* SEC_ENABLE_SEED_KEY_PRNG_LCG */

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
static SecM_StatusType SecM_ConsumeEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool,
   SecM_LengthType consumed );
# if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
# else
static void SecM_InitEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool );
# endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
# if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
# else
#  define SECM_RAMCODE_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
static void SecM_ProvideEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool,
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * entropy, SecM_LengthType length );
#  define SECM_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SECM_STOP_SEC_VAR
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  SecM_GenerateRandom
 **********************************************************************************************************************/
/*! \brief       Wrapper function to generate a random numbers
 *  \details     Fills the provided array with pseudo random numbers
 *  \param[out]  pRandom Buffer for generated random numbers
 *  \param[in]   length Number of random bytes to be generated
 *  \return      SECM_OK     if generation was successful
 *               SECM_NOT_OK if generation has failed (e.g. wrong parameters)
 **********************************************************************************************************************/
static SecM_StatusType SecM_GenerateRandom( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom, SecM_WordType length )
{
   SecM_StatusType result = SECM_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
   SecM_WordType localLength = length;
   SecM_WordType * pLength = &localLength;

   if (SEC_PRNG_GENERATE_RANDOM(pRandom, pLength) == SECM_OK) /* PRQA S 2991, 2995 */ /* MD_SecSeedKey_2991_2992_2995_2996 */
   {
      /* Check if requested length is actual length */
      if (length == localLength) /* PRQA S 2991, 2995 */ /* MD_SecSeedKey_2991_2992_2995_2996 */
      {
         result = SECM_OK;
      }
   }

   return result;
}

#if defined( SEC_ENABLE_SEED_KEY_PRNG_LCG )
/***********************************************************************************************************************
 *  SecM_LcgRandom
 **********************************************************************************************************************/
/*! \brief       Pseudo random number generator based on a linear congruential generator (LCG)
 *  \details     Implementation uses a constant modulus value of 2^32
 *               Attention: The quality of the "randomness" highly depends on the choice of the multiplication and
 *               increment modifier.
 *  \param[in]   input Previous random number or seed value
 *  \return      Next random number
 **********************************************************************************************************************/
static SecM_WordType SecM_LcgRandom( SecM_WordType input )
{
   SecM_WordType  output;

   /* Multiplication may lead to overflow, making this equal to a modulo operation with 2^32 */
   output = (input * SEC_LCG_RANDOM_MULTIPLIER) + SEC_LCG_RANDOM_INCREMENT;

   return output;
}

/***********************************************************************************************************************
 *  SecM_GenerateRandomLcg
 **********************************************************************************************************************/
/*! \brief       Generate random numbers using LCG
 *  \details     Fills the provided array with pseudo random numbers
 *  \param[out]  pRandom Buffer for generated random numbers
 *  \param[in,out] pLength Number of random bytes to be generated (output: Actual number of random bytes generated)
 *  \return      SECM_OK     if generation was successful
 *               SECM_NOT_OK if generation has failed (e.g. wrong parameters)
 **********************************************************************************************************************/
/* PRQA S 3673 2 */ /* MD_MSR_Rule8.13 */
static SecM_StatusType SecM_GenerateRandomLcg( V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom,
   V_MEMRAM1 SecM_WordType V_MEMRAM2 V_MEMRAM3 * pLength )
{
   SecM_ShortFastType   index;
   SecM_ShortFastType   remainderLength;
   SecM_ShortFastType   byteCount;
   SecM_WordType        randomWord;

   /* Limit seed value to size of word */
   byteCount = *pLength;
   if (byteCount > SEC_WORD_TYPE_SIZE)
   {
      byteCount = SEC_WORD_TYPE_SIZE;
   }

   /* Initialize current random value with initial seed value (up to 4 bytes) */
   randomWord = SecM_GetInteger(byteCount, pRandom);

   /* Remaining random bytes to be generated */
   remainderLength = *pLength;

   /* Initialize index into byte seed array */
   index = 0u;

   /* Populate array starting with initial seed stored in random[0-3] */
   while (remainderLength > 0u)
   {
      /* Generate next pseudo random number */
      randomWord = SecM_LcgRandom(randomWord);

      /* Limit serialized length to remainder */
      if (remainderLength < SEC_WORD_TYPE_SIZE)
      {
         byteCount = remainderLength;
      }
      else
      {
         byteCount = SEC_WORD_TYPE_SIZE;
      }

      /* Store serialized word in output value */
      SecM_SetInteger(byteCount, randomWord, &pRandom[index]);

      index += SEC_WORD_TYPE_SIZE;
      remainderLength -= byteCount;  /* PRQA S 3382 */ /* MD_SecSeedKey_3382 */
   }

   /* Generation always succeeds */
   return SECM_OK;
}
#endif /* SEC_ENABLE_SEED_KEY_PRNG_LCG */

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
/***********************************************************************************************************************
 *  SecM_ConsumeEntropy
 **********************************************************************************************************************/
/*! \brief       Notify about consumed entropy from pool
 *  \param[in,out] pEntropyPool Pointer to entropy pool
 *  \param[in]   consumed Number of consumed entropy bytes
 *  \return      SECM_OK     if it was possible to consume the requested length
 *               SECM_NOT_OK consumed is larger than actual available
 **********************************************************************************************************************/
static SecM_StatusType SecM_ConsumeEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool,
   SecM_LengthType consumed )
{
   SecM_StatusType      result;
   SecM_ShortFastType   index;
   SecM_LengthType      offset;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pSource; /* PRQA S 3678 */ /* MD_MSR_Rule8.13 */
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pTarget;

   result = SECM_OK;

   /* More data consumed than available? */
   if (consumed > pEntropyPool->fillLevel)
   {
      result = SECM_NOT_OK;
   }
   else
   {
      /* Any entropy consumed? */
      if (consumed > 0u)
      {
         pSource = &pEntropyPool->data[consumed];
         pTarget = pEntropyPool->data;

         /* Copy remaining entropy to beginning of pool */
         for (index = 0u; index < (SEC_ENTROPY_POOL_SIZE - (SecM_ShortFastType)consumed); index++)
         {
            pTarget[index] = pSource[index];
         }

         /* Update remaining entropy level */
         pEntropyPool->fillLevel -= consumed;

         /* Update current position in ring buffer */
         offset = pEntropyPool->fillLevel;
         if (offset >= SEC_ENTROPY_POOL_SIZE)
         {
            offset = 0u;
         }

         pEntropyPool->offset = offset;
      }
   }

   return result;
}
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
/***********************************************************************************************************************
 *  SecM_InitEntropy
 **********************************************************************************************************************/
/*! \brief       Initialize entropy pool
 *  \param[in,out] pEntropyPool Pointer to entropy pool
 **********************************************************************************************************************/
# if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
void SecM_InitEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool )
# else
static void SecM_InitEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool )
# endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */
{
   SecM_SizeType index;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pPool;

   /* Setup pool state */
   pEntropyPool->fillLevel = 0u;
   pEntropyPool->offset    = 0u;
   pEntropyPool->state     = SEC_RNG_UNINTIALIZED;

   /* Initialize pool with zeros */
   pPool = pEntropyPool->data;
   for (index = 0u; index < SEC_ENTROPY_POOL_SIZE; index++)
   {
      pPool[index] = 0x00u;
   }
}
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL */

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
# define SECM_RAMCODE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  SecM_ProvideEntropy
 **********************************************************************************************************************/
/*! \brief       Provide entropy to pool
 *  \param[in,out] pEntropyPool Pointer to entropy pool
 *  \param[in]   entropy Pointer to buffer holding new entropy
 *  \param[in]   length Length of provided entropy
 **********************************************************************************************************************/
/* PRQA S 3673 7 */ /* MD_MSR_Rule8.13 */
# if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
void SecM_ProvideEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool,
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * entropy, SecM_LengthType length )
# else
static void SecM_ProvideEntropy( V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pEntropyPool,
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * entropy, SecM_LengthType length )
# endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */
{
   SecM_ShortFastType   index;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pPool;
   SecM_LengthType      fillLevel;
   SecM_LengthType      offset;

   /* Initialize local variables */
   pPool       = pEntropyPool->data;
   fillLevel   = pEntropyPool->fillLevel;
   offset      = pEntropyPool->offset;

   /* Add new entropy to pool */
   for (index = 0u; index < length; index++)
   {
      /* Merge new entropy with existing pool data (ring buffer) */
      pPool[offset] ^= entropy[index];

      /* Update current position in ring buffer */
      offset++;
      if (offset >= SEC_ENTROPY_POOL_SIZE)
      {
         offset = 0u;
      }

      /* Update fill level of pool, saturated to buffer size */
      if (fillLevel < SEC_ENTROPY_POOL_SIZE)
      {
         fillLevel++;
      }
   }

   /* Write back updated values */
   pEntropyPool->fillLevel = fillLevel;
   pEntropyPool->offset    = offset;
}
# define SECM_RAMCODE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL */

#define SECM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  SecM_GenerateSeed
 **********************************************************************************************************************/
/*! \brief       Calculates random seed value
 *  \detail      Uses a pseudo random number generator and an initial seed to generate a seed value
 *               In case of HIS specification 1.0.1 or earlier the last seed is stored in an internal structure.
 *  \pre         Implicit entropy: The values of seedX and seedY (default API), seed[0-3] (byte array) or seed[0] (word array)
 *                should have a random start value
 *               Explicit entropy: Entropy pool passed in seed parameter has to be initialized and must hold at least
 *                one byte of entropy
 *  \param[in,out]  Pointer to seed, where the random values shall be stored
 *  \return      SECM_OK     if generation was successful
 *               SECM_NOT_OK if generation has failed (e.g. wrong parameters)
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_MSR_Rule8.13 */
SecM_StatusType SecM_GenerateSeed( V_MEMRAM1 SecM_SeedType V_MEMRAM2 V_MEMRAM3 * seed )
{
   SecM_StatusType result;
   V_MEMRAM1 SecM_SeedBaseType V_MEMRAM2 V_MEMRAM3 * pBaseSeed;
   V_MEMRAM1 SecM_ByteType V_MEMRAM2 V_MEMRAM3 * pRandom;
#if defined( SEC_BYTE_ARRAY_SEED )
#else
   SecM_ByteType        randomBuffer[SEC_INITIAL_SEED_LENGTH];
# if defined( SEC_WORD_ARRAY_SEED )
   SecM_ShortFastType   index;
# endif /* SEC_WORD_ARRAY_SEED */
#endif /* SEC_BYTE_ARRAY_SEED */

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
   V_MEMRAM1 SecM_EntropyPoolType V_MEMRAM2 V_MEMRAM3 * pPool;
# if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
# else
   SecM_EntropyPoolType entropyPool;
# endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL */

   /* Access seed base type through local variable */
#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL ) && \
    defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
   pBaseSeed = seed->data;
# else
   /* PRQA S 0310 1 */ /* MD_SecSeedKey_0310 */
   pBaseSeed = (V_MEMRAM1 SecM_SeedBaseType V_MEMRAM2 V_MEMRAM3 *)seed;
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL && SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */

#if defined( SEC_BYTE_ARRAY_SEED )
   /* Directly store generated random numbers in seed buffer */
   pRandom = pBaseSeed;
#else
   /* Store generated random numbers in temporary buffer */
   pRandom = randomBuffer;

# if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL ) && \
     defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
# else
   /* Serialize implicit seed provided as input into temporary buffer */
#  if defined( SEC_WORD_ARRAY_SEED )
   SecM_SetInteger(SEC_INITIAL_SEED_LENGTH, pBaseSeed[0], randomBuffer);
#  else
   SecM_SetInteger(SEC_WORD_TYPE_SIZE, pBaseSeed->seedX, &randomBuffer[0u]);
   SecM_SetInteger(SEC_WORD_TYPE_SIZE, pBaseSeed->seedY, &randomBuffer[SEC_WORD_TYPE_SIZE]);
#  endif /* SEC_WORD_ARRAY_SEED */
# endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL && SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */
#endif /* SEC_BYTE_ARRAY_SEED */

#if defined( SEC_ENABLE_SEED_KEY_ENTROPY_POOL )
# if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
   /* Use provided explicit entropy */
   pPool = seed->entropyPool;
# else
   /* Setup temporary entropy pool to handle implicit entropy */
   pPool = &entropyPool;

   /* Initialize temporary entropy pool */
   SecM_InitEntropy(pPool);

   /* Use implicit entropy to fill entropy pool */
   SecM_ProvideEntropy(pPool, pRandom, SEC_INITIAL_SEED_LENGTH);
# endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */

   result = SECM_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */

   /* Entropy of PRNG initialized yet? */
   if (SEC_RNG_UNINTIALIZED == pPool->state) /* PRQA S 2991, 2995 */ /* MD_SecSeedKey_2991_2992_2995_2996 */
   {
      /* Pool must hold at least one byte of entropy */
      if (pPool->fillLevel == 0u) /* PRQA S 2992, 2996 */ /* MD_SecSeedKey_2991_2992_2995_2996 */
      {
         result = SECM_NOT_OK;
      }
      else
      {
         /* Provide full buffer to initialization, regardless of actual fill level */
         pPool->fillLevel = (SecM_LengthType)SEC_ENTROPY_POOL_SIZE;
         result = SEC_PRNG_INIT_ENTROPY(pPool);

         /* Notify about consumed entropy regardless of initialization result */
         if (SecM_ConsumeEntropy(pPool, pPool->fillLevel) != SECM_OK) /* PRQA S 2992, 2996 */ /* MD_SecSeedKey_2991_2992_2995_2996 */
         {
            result = SECM_NOT_OK;
         }

# if defined( SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY )
         if (result == SECM_OK)
         {
            /* Remember initialized state */
            pPool->state = SEC_RNG_INTIALIZED;
         }
# endif /* SEC_ENABLE_SEED_KEY_EXPLICIT_ENTROPY */
      }
   }
   else
   {
      /* Stir PRNG with any new entropy */
      if (pPool->fillLevel >= (SecM_LengthType)SEC_ENTROPY_POOL_SIZE)
      {
         result = SEC_PRNG_STIR_ENTROPY(pPool);

         /* Notify about consumed entropy regardless of initialization result */
         if (SecM_ConsumeEntropy(pPool, pPool->fillLevel) != SECM_OK) /* PRQA S 2992, 2996 */ /* MD_SecSeedKey_2991_2992_2995_2996 */
         {
            result = SECM_NOT_OK;
         }
      }
   }

   if (result == SECM_OK)
#endif /* SEC_ENABLE_SEED_KEY_ENTROPY_POOL */
   {
#if defined( SEC_BYTE_ARRAY_SEED )
      /* Fill array with pseudo random numbers */
      result = SecM_GenerateRandom(pRandom, SEC_SEED_LENGTH);

#elif defined( SEC_WORD_ARRAY_SEED )
      /* Populate seed array */
      for (index = 0u; index < SEC_SEED_WORD_LENGTH; index++)
      {
         /* Generate next pseudo random number */
         result = SecM_GenerateRandom(pRandom, SEC_WORD_TYPE_SIZE);

         /* Store in output value */
         pBaseSeed[index]  = SecM_GetInteger(SEC_WORD_TYPE_SIZE, pRandom);

         if (result != SECM_OK)
         {
            break;
         }
      }
#else
      /* Generate pseudo random numbers */
      result = SecM_GenerateRandom(pRandom, SEC_WORD_TYPE_SIZE);
      pBaseSeed->seedX = SecM_GetInteger(SEC_WORD_TYPE_SIZE, pRandom);

      if (result == SECM_OK) /* PRQA S 2991, 2995 */ /* MD_SecSeedKey_2991_2992_2995_2996 */
      {
         /* Generate pseudo random numbers */
         result = SecM_GenerateRandom(pRandom, SEC_WORD_TYPE_SIZE);
         pBaseSeed->seedY = SecM_GetInteger(SEC_WORD_TYPE_SIZE, pRandom);

      }
#endif /* SEC_<type>_ARRAY_SEED */

      if (result == SECM_OK) /* PRQA S 2991, 2995 */ /* MD_SecSeedKey_2991_2992_2995_2996 */
      {
         /* Start validity timer of seed if applicable */
         SecM_StartKeyTimer();
      }
   }

   return result;
}

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
#else
/***********************************************************************************************************************
 *  SecM_ComputeKey
 **********************************************************************************************************************/
/*! \brief       Calculates a key value based on the provided seed and constant value
 *  \pre         Function SecM_GenerateSeed must have been called at least once.
 *  \param[in]   inputSeed The random seed the key calculation shall be based on
 *  \param[in]   constant A fixed constant used by the key calculation algorithm
 *                        Contains additional parameters (workspace, secret key) in case of extended API
 *  \param[out]  computedKey Pointer to resulting key data as a formula of key = f(seed,k)
 *  \return      SECM_OK     if calculation was successful
 *               SECM_NOT_OK if calculation has failed (e.g. wrong parameters)
 **********************************************************************************************************************/
SecM_StatusType SecM_ComputeKey( SecM_SeedStorageType inputSeed, SecM_ConstType constant,
   V_MEMRAM1 SecM_KeyStorageType V_MEMRAM2 V_MEMRAM3 * computedKey )
{
   SecM_StatusType result;

   result = SecM_ComputeKeyVendor(inputSeed, constant, computedKey);

   return result;
}
#endif /* SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION */

/***********************************************************************************************************************
 *  SecM_CompareKey
 **********************************************************************************************************************/
/*! \brief       Compare received key against computed one
 *  \details     Runs the key calculation and compares the calculated key against the received key
 *  \pre         Function SecM_GenerateSeed must have been called before.
 *  \param[in]   key Key for the authorisation
 *                   Contains additional parameters (workspace, secret key) in case of extended API
 *  \param[in]   lastSeed Start value (seed) for the authorisation
 *  \return      SECM_OK if key calculation and comparison was successful
 *               SECM_NOT_OK if key calculation failed or key mismatch
 **********************************************************************************************************************/
/* PRQA S 3673, 3677 1 */ /* MD_MSR_Rule8.13 */
SecM_StatusType SecM_CompareKey( SecM_KeyType key, SecM_SeedType lastSeed )
{
   SecM_StatusType      result;
   SecM_ConstType       keyConstant;

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
#else
   volatile SecM_CompareType computeVal;
# if defined( SEC_COMPARE_SIZE )
   SecM_ShortFastType   index;
# endif /* SEC_COMPARE_SIZE */

/* Clear contents computed value */
# if defined( SEC_COMPARE_SIZE )
   for (index = 0u; index < SEC_COMPARE_SIZE; index++)
   {
      computeVal[index] = 0u;
   }
# else
   computeVal = 0u;
# endif /* SEC_COMPARE_SIZE */
#endif /* SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION */

   /* Initialize local variables */
   result = SECM_NOT_OK;

   /* Verify validity of seed if applicable */
   if (SecM_GetKeyTimer() > 0u)
   {
#if defined( SEC_ENABLE_SEED_KEY_EXTENDED_API )
      /* Extended API used */
      /* Pass configured key constant */
      keyConstant.constant = SEC_ECU_KEY;
      /* Pass context required for calculation
         Move from key as this parameter is usually not available in SecM_ComputeKey */
      keyConstant.context  = key.context;
#else
      /* Pass configured key constant */
      keyConstant = SEC_ECU_KEY;
#endif /* SEC_ENABLE_SEED_KEY_EXTENDED_API */

      /* Run key calculation */
#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
      result = SecM_CompareKeyVendor(SEC_BASE_KEY(key), SEC_BASE_SEED(lastSeed), keyConstant);
#else
      result = SecM_ComputeKey(SEC_BASE_SEED(lastSeed), keyConstant, (SecM_CompareType*)&computeVal); /* PRQA S 0312 */ /* MD_SecSeedKey_0312 */

      /* Compare provided value against computed value
         Perform full comparison regardless of current result to prevent timing analysis */
# if defined( SEC_COMPARE_SIZE )
      for (index = 0u; index < SEC_COMPARE_SIZE; index++)
      {
         /* PRQA S 0404 1 */ /* MD_SecSeedKey_0404 */
         if (computeVal[index] != SEC_COMPARE_VALUE[index])
         {
            /* Comparison failed report failure */
            result = SECM_NOT_OK;
         }
      }
# else
      if (computeVal != SEC_COMPARE_VALUE)
      {
         /* Comparison failed report failure */
         result = SECM_NOT_OK;
      }
# endif /* SEC_COMPARE_SIZE */
#endif /* SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION */

      /* Invalidate seed validity */
      SecM_StopKeyTimer();
   }

#if defined( SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION )
#else
   /* Destroy temporary key (un-spy) */
# if defined( SEC_COMPARE_SIZE )
   for (index = 0u; index < SEC_COMPARE_SIZE; index++)
   {
      computeVal[index] = 0u;
   }
# else
   computeVal = 0u;
# endif
#endif /* SEC_ENABLE_SEED_KEY_EXTERNAL_COMPARISION */

   return result;
}

#define SECM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SEC_ENABLE_SEEDKEY */

/***********************************************************************************************************************
 *  MISRA
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_SecSeedKey_0310:
      Reason:     Casting to the respective base type.
      Risk:       No risk, as both types are equivalent.
      Prevention: No prevention required.

   MD_SecSeedKey_0312:
      Reason:     The volatile attribute is requested to be valid only in the same variable declaration scope.
      Risk:       The variable which has the volatile attribute casted away can potential lead to an undefined behavior.
      Prevention: The cases in which the volatile attribute is casted away shall not be critical from an optimization
                  point of view.

   MD_SecSeedKey_0404:
      Reason:     Several read accesses to a volatile variable required to compare the complete content.
      Risk:       No risk, as there is no modifications of the volatile variable between.
      Prevention: No prevention requireed.

   MD_SecSeedKey_2991_2992_2995_2996:
      Reason:     The value of the if-controlling expression or logical operation depends on the configuration.
      Risk:       No risk.
      Prevention: No prevention necessary.

   MD_SecSeedKey_3382:
      Reason:     Subtraction from unsigned value without explicit range check directly before operation.
                  Instead limitation of subtracted value is located above as it is required before.
      Risk:       Distance between limitation and subtraction makes correlation less obvious.
      Prevention: Ensure correct limitation of subtracted value through code inspection.

*/

/***********************************************************************************************************************
 *  END OF FILE: SEC_SEEDKEY.C
 **********************************************************************************************************************/
