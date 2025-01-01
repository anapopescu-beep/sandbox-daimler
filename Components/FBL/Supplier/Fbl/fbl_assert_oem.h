/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        OEM specific assertion defines
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2023 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  10.00.00   2020-10-14  viscb   FBL-2177         DRECU2020-01 adaptions, input verification and encrypted download
 *  10.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *  10.01.01   2021-02-02  viscb   ESCAN00108445    QM release
 *  10.01.02   2021-04-21  viscb   ESCAN00108537    No changes
 *                                 ESCAN00108093    No changes
 *                                 ESCAN00108139    No changes
 *                                 FBL-3360         No changes
 *  10.01.03   2021-05-28  viscb   ESCAN00109398    No changes
 *                                 ESCAN00109400    No changes
 *  10.01.04   2021-06.07  viscb   ESCAN00109435    No changes
 *                                 ESCAN00109437    No changes
 *  10.02.00   2021-07-09  vishor  FBL-3567         No changes
 *                                 ESCAN00107081    No changes
 *  10.02.01   2021-08-26  visjdn  ESCAN00109069    No changes
 *  10.02.02   2021-10-27  visrie  ESCAN00109153    No changes
 *  10.03.00   2022-03-15  vishor  FBL-4621         No changes
 *                                 ESCAN00110728    No changes
 *                                 ESCAN00110898    No changes
 *                                 ESCAN00110960    No changes
 *                                 ESCAN00111146    No changes
 *                                 ESCAN00111396    No changes
 *  10.04.00   2022-06-01  vishor  FBL-5094         No changes
 *                                 ESCAN00110486    No changes
 *  10.04.01   2022-06-27  vismix  ESCAN00112173    No changes
 *                                 ESCAN00112160    No changes
 *  10.04.02   2022-08-26  vismix  FBL-5754         No changes
 *                                 ESCAN00112447    No changes
 *                                 ESCAN00112459    No changes
 *  10.04.03   2023-01-09  vismix  ESCAN00112744    No changes
 *                                 ESCAN00113013    No changes
 *                                 ESCAN00113078    No changes
 **********************************************************************************************************************/

#ifndef FBL_ASSERT_OEM_H
#define FBL_ASSERT_OEM_H

/***********************************************************************************************************************
 *  DEFINITION OF ASSERTION CODES (OEM)
 **********************************************************************************************************************/

/* 0x80-0xFF: OEM specific */
/* Diagnostic module errors */
#define kFblOemAssertMainHandlerIdxInvalid   0x80u
#define kFblOemAssertWrongServiceHandler     0x81u
#define kFblOemAssertInvalidError            0x82u
#define kFblOemAssertSnapshotCreateError     0x84u

/* 0xA0-0xBF: Internal assertions */
#define kFblOemAssertParameterOutOfRange     0xA0u

#define kFblOemAssertIllegalReturnValue      0xE1u

/***********************************************************************************************************************
 *  END OF FILE: FBL_ASSERT_OEM.H
 **********************************************************************************************************************/

#endif /* FBL_ASSERT_OEM_H */
