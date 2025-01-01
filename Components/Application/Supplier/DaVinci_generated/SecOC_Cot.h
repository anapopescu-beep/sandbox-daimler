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
 *            Module: SecOC
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: SecOC_Cot.h
 *   Generation Time: 2023-07-10 14:36:04
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (SECOC_COT_H)
# define SECOC_COT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SecOC_Types.h"
#include "SecOC_Cfg.h"

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
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define SECOC_START_SEC_CODE
#include "SecOC_MemMap.h"   /* PRQA S 5087 */  /* MD_MSR_MemMap */

 /* configuratble SecOC verification status callouts */ 



# if (SECOC_CUSTOM_AUTHENTICATION_API == STD_ON)
/***********************************************************************************************************************
 *  SecOC_GenerateAuthenticationInfo()
 **********************************************************************************************************************/
/*!
 * \brief       Custom callout for calculating the authenticator value
 * \details     The authenticator must be calculated inside this callout using the customer algorithms.
 * \param[in]   txFreshnessId                Id of the freshness value.
 * \param[in]   txAuthenticPduInfoPtr        Pointer to the authentic Pdu which shall be used as input for the Authenticator calculation.
 * \param[out]  txAuthenticatorPtr           Pointer to the authenticator buffer. Write the calculated authenticator to this buffer.
 * \param[in]   txAuthenticatorLength        Length of the authenticator buffer.
 * \return      E_OK                         Calculation successful.
 *              E_NOT_OK                     Calculation failed.
 *              SECOC_E_BUSY                 Calculation can not be executed at this moment. The SecOC will call the API again depending on the Build Attempts counter.
 * \context     TASK
 * \synchronous TRUE
 * \reentrant   TRUE, for different FreshnessValueIDs.
 */ 
FUNC(Std_ReturnType, SECOC_CODE) SecOC_GenerateAuthenticationInfo(uint16 txFreshnessId,
                                                                       P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) txAuthenticPduInfoPtr,
                                                                       P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) txAuthenticatorPtr,
                                                                       uint32 txAuthenticatorLength);

/***********************************************************************************************************************
 *  SecOC_VerifyAuthenticationInfo()
 **********************************************************************************************************************/
/*!
 * \brief       Custom callout for the verification of the received secured Pdu
 * \details     The authenticator must be verified inside this callout using the customer algorithms.  
 * \param[in]   rxFreshnessId            Id of the freshness value.
 * \param[in]   rxAuthenticPduInfoPtr    Pointer to the authentic Pdu.
 * \param[in]   rxAuthenticatorPtr       Pointer to the authenticator buffer. 
 * \param[in]   rxAuthenticatorLength    Length of the authenticator buffer. 
 * \param[out]  verifyResultPtr          Pointer to result buffer.  
 * \return      E_OK                     Verification successful. 
 *              E_NOT_OK                 Verification failed.  
 *              SECOC_E_BUSY             Verification can not be executed at this moment. The SecOC will call the API again depending on the Build Attempts counter.
 * \context     TASK
 * \synchronous TRUE
 * \reentrant   TRUE, for different FreshnessValueIDs.
 */ 
FUNC(Std_ReturnType, SECOC_CODE) SecOC_VerifyAuthenticationInfo(uint16 rxFreshnessId, 
                                                                     P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) rxAuthenticPduInfoPtr, 
                                                                     P2CONST(uint8, AUTOMATIC, SECOC_APPL_DATA) rxAuthenticatorPtr,
                                                                     uint32 rxAuthenticatorLength,
                                                                     P2VAR(Crypto_VerifyResultType, AUTOMATIC, SECOC_APPL_DATA) verifyResultPtr);
# endif

#define SECOC_STOP_SEC_CODE
#include "SecOC_MemMap.h"   /* PRQA S 5087 */  /* MD_MSR_MemMap */

#endif  /* SECOC_COT_H */
/**********************************************************************************************************************
  END OF FILE: SecOC_Cot.h
**********************************************************************************************************************/
