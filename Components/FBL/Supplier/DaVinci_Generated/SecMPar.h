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
 *            Module: Smh
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecMPar.h
 *   Generation Time: 2023-07-05 16:23:55
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(SECMPAR_H)
#define SECMPAR_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Sec_Inc.h"

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define SECM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Decryption functions */
SecM_StatusType DecryptAes128 ( const V_MEMRAM1 SecM_DecInputParamType V_MEMRAM2 V_MEMRAM3 * pInBlock,
   V_MEMRAM1 SecM_DecOutputParamType V_MEMRAM2 V_MEMRAM3 * pOutBlock,
   const V_MEMRAM1 SecM_DecParamType V_MEMRAM2 V_MEMRAM3 * pDecParam);



SecM_StatusType SecM_VerifyCrc32( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam );
SecM_StatusType SmhSecurityClassCCC_Ed25519Sha512( V_MEMRAM1 SecM_SignatureParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam );

SecM_StatusType SecM_VerificationClassDDD_Crc32( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam );
SecM_StatusType SecM_VerificationClassCCC_Ed25519Sha512( V_MEMRAM1 SecM_VerifyParamType V_MEMRAM2 V_MEMRAM3 * pVerifyParam );



#define SECM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

#define SECM_START_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define SECM_STOP_SEC_VAR
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define SECM_START_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* AES key used for decrpytion of download data */
/* Public Key for Security Access */
/* Verification Key Reference */

V_MEMROM0 extern V_MEMROM1 SecM_CryptographicKeyType V_MEMROM2 SecM_CryptographicKeys[3];

V_MEMROM0 extern V_MEMROM1 SecM_DecPrimitiveType V_MEMROM2 SecM_DecryptionPrimitives[1];

V_MEMROM0 extern V_MEMROM1 SecM_CrcPrimitiveType V_MEMROM2 SecM_CrcPrimitives[1];




V_MEMROM0 extern V_MEMROM1 SecM_RamDataType V_MEMROM2 SecM_SignaturePrimitivesContextBuffs[1];

V_MEMROM0 extern V_MEMROM1 SecM_SigPrimitiveType V_MEMROM2 SecM_SignaturePrimitives[1];



V_MEMROM0 extern V_MEMROM1 SecM_JobInfoType V_MEMROM2 SecM_JobInfo[6];


#define SECM_STOP_SEC_CONST
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SECMPAR_H */
