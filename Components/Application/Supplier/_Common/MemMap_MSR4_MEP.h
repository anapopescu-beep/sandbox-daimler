/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defined for all BSW modules
 *                which are used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all OEMs
 *                                              rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub, 
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                              add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin 
 *            2012-09-04  Ht                    add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                   MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu    ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu    ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu    ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                   FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *  01.11.00  2017-07-05  Seu    ESCAN00095756  FEAT-2455: Support ASR4.2 compatible MemMap for MCALs
 *            2017-08-01  Seu    ESCAN00096129  MEMMAP_SW_MINOR_VERSION / MEM_SW_MINOR_VERSION is not correct
 *  01.12.00  2018-10-17  visdfe ESCAN00095695  Add support for Os_CoreGen7 within _MemMap.h (Include of Os_MemMap.h)
 *                               TASK-78775     Change MemMap_Common.h to Template
 *  01.13.00  2021-05-06  virmfr HALBE-3985     CommonAsr_MemMap shall include Common_MemMap generated compatibility header
 *  02.00.00  2021-06-09  visto  HALBE-4594     Create a branch for >=R27 Features
 *  02.01.00  2021-08-25  virmfr HALBE-4526     MemMap_Common.h removed
 *  02.01.01  2021-09-07  virmfr HALBE-5304     MemMapIncludesList removed
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#ifdef VSWT_USED
#include "EthTrcv_30_Generic_MemMap.h"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Package Merger: Start Section MemMapModuleList */



/**********************************************************************************************************************
 *  EEP_30_XXI2C01 START
 *********************************************************************************************************************/

/******** CODE sections **********************************************************************************************/

#ifdef EEP_30_XXI2C01_START_SEC_CODE
# undef EEP_30_XXI2C01_START_SEC_CODE /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_CODE
# undef EEP_30_XXI2C01_STOP_SEC_CODE /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef EEP_30_XXI2C01_START_SEC_CONST_32
# undef EEP_30_XXI2C01_START_SEC_CONST_32 /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_CONST_32
# undef EEP_30_XXI2C01_STOP_SEC_CONST_32 /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED
# undef EEP_30_XXI2C01_START_SEC_CONST_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED
# undef EEP_30_XXI2C01_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXI2C01_START_SEC_PBCFG_ROOT
# undef EEP_30_XXI2C01_START_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_PBCFG_ROOT
# undef EEP_30_XXI2C01_STOP_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXI2C01_INST2_START_SEC_PBCFG_ROOT
# undef EEP_30_XXI2C01_INST2_START_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef EEP_30_XXI2C01_INST2_STOP_SEC_PBCFG_ROOT
# undef EEP_30_XXI2C01_INST2_STOP_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef EEP_30_XXI2C01_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef EEP_30_XXI2C01_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef EEP_30_XXI2C01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef EEP_30_XXI2C01_START_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_XXI2C01_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_XXI2C01_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_XXI2C01_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EEP_30_XXI2C01 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  EEP_30_XXSPI01 START
 *********************************************************************************************************************/

/******** CODE sections **********************************************************************************************/

#ifdef EEP_30_XXSPI01_START_SEC_CODE
# undef EEP_30_XXSPI01_START_SEC_CODE /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_CODE
# undef EEP_30_XXSPI01_STOP_SEC_CODE /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef EEP_30_XXSPI01_START_SEC_CONST_32
# undef EEP_30_XXSPI01_START_SEC_CONST_32 /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_CONST_32
# undef EEP_30_XXSPI01_STOP_SEC_CONST_32 /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXSPI01_START_SEC_CONST_UNSPECIFIED
# undef EEP_30_XXSPI01_START_SEC_CONST_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_CONST_UNSPECIFIED
# undef EEP_30_XXSPI01_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXSPI01_START_SEC_PBCFG_ROOT
# undef EEP_30_XXSPI01_START_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_PBCFG_ROOT
# undef EEP_30_XXSPI01_STOP_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef EEP_30_XXSPI01_INST2_START_SEC_PBCFG_ROOT
# undef EEP_30_XXSPI01_INST2_START_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef EEP_30_XXSPI01_INST2_STOP_SEC_PBCFG_ROOT
# undef EEP_30_XXSPI01_INST2_STOP_SEC_PBCFG_ROOT /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef EEP_30_XXSPI01_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef EEP_30_XXSPI01_START_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef EEP_30_XXSPI01_STOP_SEC_VAR_NO_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef EEP_30_XXSPI01_START_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_XXSPI01_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef EEP_30_XXSPI01_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef EEP_30_XXSPI01_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  EEP_30_XXSPI01 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSWT_30_88Q5050 START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(ETHSWT_30_88Q5050_START_SEC_CODE)
# undef ETHSWT_30_88Q5050_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_CODE)
# undef ETHSWT_30_88Q5050_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_CODE_FAST)
# undef ETHSWT_30_88Q5050_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST                                          /* mapped to default fast code section */
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_CODE_FAST)
# undef ETHSWT_30_88Q5050_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_CODE_ISR)
# undef ETHSWT_30_88Q5050_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_CODE_ISR)
# undef ETHSWT_30_88Q5050_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_CONST_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                         /* mapped to default const 8bit section */
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_CONST_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_CONST_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_CONST_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_CONST_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_CONST_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(ETHSWT_30_88Q5050_START_SEC_CONST_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_CONST_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(ETHSWT_30_88Q5050_START_SEC_CONST_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_CONST_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_FAST_CONST_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_FAST_CONST_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_FAST_CONST_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_FAST_CONST_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_FAST_CONST_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(ETHSWT_30_88Q5050_START_SEC_PBCFG_ROOT)
# undef ETHSWT_30_88Q5050_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_PBCFG_ROOT)
# undef ETHSWT_30_88Q5050_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(ETHSWT_30_88Q5050_START_SEC_PBCFG_GLOBALROOT)
# undef ETHSWT_30_88Q5050_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_PBCFG_GLOBALROOT)
# undef ETHSWT_30_88Q5050_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_PBCFG)
# undef ETHSWT_30_88Q5050_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_PBCFG)
# undef ETHSWT_30_88Q5050_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_INIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                                      /* mapped to default var init 8bit section */
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default var stop section */
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_INIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_INIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_INIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_PBCFG)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_PBCFG)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5050_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHSWT_30_88Q5050 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSWT_30_88Q5072 START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(ETHSWT_30_88Q5072_START_SEC_CODE)
# undef ETHSWT_30_88Q5072_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_CODE)
# undef ETHSWT_30_88Q5072_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_CODE_FAST)
# undef ETHSWT_30_88Q5072_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST                                          /* mapped to default fast code section */
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_CODE_FAST)
# undef ETHSWT_30_88Q5072_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_CODE_ISR)
# undef ETHSWT_30_88Q5072_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_CODE_ISR)
# undef ETHSWT_30_88Q5072_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_CONST_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                         /* mapped to default const 8bit section */
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_CONST_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_CONST_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_CONST_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_CONST_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_CONST_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(ETHSWT_30_88Q5072_START_SEC_CONST_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_CONST_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(ETHSWT_30_88Q5072_START_SEC_CONST_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_CONST_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_FAST_CONST_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_FAST_CONST_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_FAST_CONST_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_FAST_CONST_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_FAST_CONST_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(ETHSWT_30_88Q5072_START_SEC_PBCFG_ROOT)
# undef ETHSWT_30_88Q5072_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_PBCFG_ROOT)
# undef ETHSWT_30_88Q5072_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(ETHSWT_30_88Q5072_START_SEC_PBCFG_GLOBALROOT)
# undef ETHSWT_30_88Q5072_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_PBCFG_GLOBALROOT)
# undef ETHSWT_30_88Q5072_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_PBCFG)
# undef ETHSWT_30_88Q5072_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_PBCFG)
# undef ETHSWT_30_88Q5072_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_INIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                                      /* mapped to default var init 8bit section */
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default var stop section */
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_INIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_INIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_INIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_PBCFG)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_PBCFG)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_88Q5072_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHSWT_30_88Q5072 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSWT START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHSWT_30_BCM8953X_START_SEC_CODE
  #undef ETHSWT_30_BCM8953X_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_CODE
  #undef ETHSWT_30_BCM8953X_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_CODE_FAST
  #undef ETHSWT_30_BCM8953X_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_CODE_FAST
  #undef ETHSWT_30_BCM8953X_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_CODE_ISR
  #undef ETHSWT_30_BCM8953X_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_CODE_ISR
  #undef ETHSWT_30_BCM8953X_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_19.6 */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_CONST_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_CONST_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_CONST_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_CONST_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_CONST_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_CONST_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_CONST_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_CONST_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_FAST_CONST_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_FAST_CONST_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_FAST_CONST_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_FAST_CONST_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_FAST_CONST_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_FAST_CONST_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_FAST_CONST_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_INIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_INIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_INIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_INIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_INIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_INIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOINIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOINIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOINIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_INIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_INIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_INIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_INIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_INIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_INIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_NOINIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_NOINIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_NOINIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_BCM8953X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHSWT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSWT_30_RTL90XX START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(ETHSWT_30_RTL90XX_START_SEC_CODE)
# undef ETHSWT_30_RTL90XX_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_CODE)
# undef ETHSWT_30_RTL90XX_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_CODE_FAST)
# undef ETHSWT_30_RTL90XX_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST                                          /* mapped to default fast code section */
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_CODE_FAST)
# undef ETHSWT_30_RTL90XX_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_CODE_ISR)
# undef ETHSWT_30_RTL90XX_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_CODE_ISR)
# undef ETHSWT_30_RTL90XX_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_CONST_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                         /* mapped to default const 8bit section */
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_CONST_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_CONST_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_CONST_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_CONST_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_CONST_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(ETHSWT_30_RTL90XX_START_SEC_CONST_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_CONST_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(ETHSWT_30_RTL90XX_START_SEC_CONST_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_CONST_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(ETHSWT_30_RTL90XX_START_SEC_PBCFG_ROOT)
# undef ETHSWT_30_RTL90XX_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_PBCFG_ROOT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM */
#if defined(ETHSWT_30_RTL90XX_START_SEC_PBCFG_GLOBALROOT)
# undef ETHSWT_30_RTL90XX_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_PBCFG_GLOBALROOT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_PBCFG)
# undef ETHSWT_30_RTL90XX_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_PBCFG)
# undef ETHSWT_30_RTL90XX_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                                      /* mapped to default var init 8bit section */
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default var stop section */
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_PBCFG)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_PBCFG)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_RTL90XX_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/*******  SWITCH_FIRMWARE sections  **********************************************************************************/
#if defined ETHSWT_30_RTL90XX_START_SEC_SWITCH_FIRMWARE_CONST_32BIT
# undef ETHSWT_30_RTL90XX_START_SEC_SWITCH_FIRMWARE_CONST_32BIT

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section can be mapped to a different memory section."
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".SwitchFirmware"
   */
# endif

# define START_SEC_CONST_32BIT
#endif
#if defined ETHSWT_30_RTL90XX_STOP_SEC_SWITCH_FIRMWARE_CONST_32BIT
# undef ETHSWT_30_RTL90XX_STOP_SEC_SWITCH_FIRMWARE_CONST_32BIT

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section can be mapped to a different memory section."
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  ETHSWT_30_RTL90XX END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSWT START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_CODE
# undef ETHSWT_30_SJA1105PQRS_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_CODE
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_CODE_FAST
# undef ETHSWT_30_SJA1105PQRS_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST                                          /* mapped to default fast code section */
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_CODE_FAST
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_CODE_ISR
# undef ETHSWT_30_SJA1105PQRS_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_CODE_ISR
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_CONST_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                         /* mapped to default const 8bit section */
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_CONST_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_CONST_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_CONST_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_CONST_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_CONST_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_CONST_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_CONST_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_FAST_CONST_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_FAST_CONST_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_FAST_CONST_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_FAST_CONST_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_FAST_CONST_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_FAST_CONST_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_FAST_CONST_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                                      /* mapped to default var init 8bit section */
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default var stop section */
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOINIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOINIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOINIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_NOINIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_NOINIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_NOINIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#ifdef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef ETHSWT_30_SJA1105PQRS_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHSWT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSWT_30_SJA1110ABCD START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_CODE)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_CODE)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_CODE_FAST)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST                                          /* mapped to default fast code section */
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_CODE_FAST)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_CODE_ISR)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_CODE_ISR)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_CONST_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT                                         /* mapped to default const 8bit section */
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_CONST_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_CONST_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_CONST_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_CONST_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_PBCFG_ROOT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_PBCFG_ROOT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM */
#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_PBCFG_GLOBALROOT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_PBCFG_GLOBALROOT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_PBCFG)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_PBCFG)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT                                      /* mapped to default var init 8bit section */
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                                                 /* default var stop section */
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_PBCFG)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_PBCFG)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_64BIT
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_64BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef ETHSWT_30_SJA1110ABCD_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHSWT_30_SJA1110ABCD END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETH_30_AR7000 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETH_30_AR7000_START_SEC_CODE
  #undef ETH_30_AR7000_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CODE
  #undef ETH_30_AR7000_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

#ifdef ETH_30_AR7000_START_SEC_CODE_ISR
  #undef ETH_30_AR7000_START_SEC_CODE_ISR
  #define START_SEC_CODE_ISR                        /* mapped to default ISR code section */
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CODE_ISR
  #undef ETH_30_AR7000_STOP_SEC_CODE_ISR
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETH_30_AR7000_START_SEC_CONST_8BIT
# undef ETH_30_AR7000_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CONST_8BIT
# undef ETH_30_AR7000_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETH_30_AR7000_START_SEC_CONST_16BIT
# undef ETH_30_AR7000_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CONST_16BIT
# undef ETH_30_AR7000_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETH_30_AR7000_START_SEC_CONST_32BIT
# undef ETH_30_AR7000_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CONST_32BIT
# undef ETH_30_AR7000_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETH_30_AR7000_START_SEC_CONST_UNSPECIFIED
# undef ETH_30_AR7000_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
# undef ETH_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_16BIT
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_32BIT
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_AR7000_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_AR7000_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_DESCRIPTOR
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_DESCRIPTOR
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_DESCRIPTOR
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_DESCRIPTOR
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_AR7000_START_SEC_VAR_NOINIT_BUFFER
# undef ETH_30_AR7000_START_SEC_VAR_NOINIT_BUFFER
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_BUFFER
# undef ETH_30_AR7000_STOP_SEC_VAR_NOINIT_BUFFER
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETH_30_AR7000 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETH_30_MSE102X START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined ETH_30_MSE102X_START_SEC_CODE
# undef ETH_30_MSE102X_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined ETH_30_MSE102X_STOP_SEC_CODE
# undef ETH_30_MSE102X_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined ETH_30_MSE102X_START_SEC_CODE_ISR
# undef ETH_30_MSE102X_START_SEC_CODE_ISR
# define START_SEC_CODE_ISR                                           /* mapped to default ISR code section */
#endif
#if defined ETH_30_MSE102X_STOP_SEC_CODE_ISR
# undef ETH_30_MSE102X_STOP_SEC_CODE_ISR
# define STOP_SEC_CODE_ISR                                            /* default code stop section */
#endif

#if defined ETH_30_MSE102X_START_SEC_APPL_CODE
# undef ETH_30_MSE102X_START_SEC_APPL_CODE
# define START_SEC_APPL_CODE                                          /* mapped to default APPL code section */
#endif
#if defined ETH_30_MSE102X_STOP_SEC_APPL_CODE
# undef ETH_30_MSE102X_STOP_SEC_APPL_CODE
# define STOP_SEC_APPL_CODE                                           /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#if defined ETH_30_MSE102X_START_SEC_CONST_8BIT
# undef ETH_30_MSE102X_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#if defined ETH_30_MSE102X_STOP_SEC_CONST_8BIT
# undef ETH_30_MSE102X_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_30_MSE102X_START_SEC_CONST_16BIT
# undef ETH_30_MSE102X_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#if defined ETH_30_MSE102X_STOP_SEC_CONST_16BIT
# undef ETH_30_MSE102X_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_30_MSE102X_START_SEC_CONST_32BIT
# undef ETH_30_MSE102X_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#if defined ETH_30_MSE102X_STOP_SEC_CONST_32BIT
# undef ETH_30_MSE102X_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#if defined ETH_30_MSE102X_START_SEC_CONST_UNSPECIFIED
# undef ETH_30_MSE102X_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined ETH_30_MSE102X_STOP_SEC_CONST_UNSPECIFIED
# undef ETH_30_MSE102X_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#if defined ETH_30_MSE102X_START_SEC_PBCFG
# undef ETH_30_MSE102X_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#if defined ETH_30_MSE102X_STOP_SEC_PBCFG
# undef ETH_30_MSE102X_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#if defined ETH_30_MSE102X_START_SEC_PBCFG_ROOT
# undef ETH_30_MSE102X_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#if defined ETH_30_MSE102X_STOP_SEC_PBCFG_ROOT
# undef ETH_30_MSE102X_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#if defined ETH_30_MSE102X_START_SEC_VAR_NOINIT_BOOLEAN
# undef ETH_30_MSE102X_START_SEC_VAR_NOINIT_BOOLEAN
# define START_SEC_VAR_NOINIT_BOOLEAN
#endif
#if defined ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_BOOLEAN
# undef ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_BOOLEAN
# define STOP_SEC_VAR
#endif

#if defined ETH_30_MSE102X_START_SEC_VAR_NOINIT_8BIT
# undef ETH_30_MSE102X_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_8BIT
# undef ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_MSE102X_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_MSE102X_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETH_30_MSE102X_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETH_30_MSE102X_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_30_MSE102X_START_SEC_VAR_NOINIT_16BIT
# undef ETH_30_MSE102X_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_16BIT
# undef ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_30_MSE102X_START_SEC_VAR_NOINIT_32BIT
# undef ETH_30_MSE102X_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_32BIT
# undef ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#if defined ETH_30_MSE102X_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_MSE102X_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_MSE102X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETH_30_MSE102X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_MSE102X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETH_30_MSE102X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETH_30_MSE102X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#if defined ETH_30_MSE102X_START_SEC_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_MSE102X_START_SEC_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section must be aligned to a 64 BYTES border!"
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthDesc"
   */
# endif

# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETH_30_MSE102X_STOP_SEC_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED
# undef ETH_30_MSE102X_STOP_SEC_DESCRIPTOR_VAR_NOINIT_UNSPECIFIED

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section must be aligned to a 64 BYTES border!"
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# define STOP_SEC_VAR
#endif

#if defined ETH_30_MSE102X_START_SEC_BUFFER_VAR_NOINIT_8BIT
# undef ETH_30_MSE102X_START_SEC_BUFFER_VAR_NOINIT_8BIT

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section must be aligned to a 64 BYTES border!"
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=".EthBuffers"
   */
# endif

# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined ETH_30_MSE102X_STOP_SEC_BUFFER_VAR_NOINIT_8BIT
# undef ETH_30_MSE102X_STOP_SEC_BUFFER_VAR_NOINIT_8BIT

# if defined _MICROSOFT_C_VTT_
   /* VTT usecase - nothing to do here */
# else
#  error "For Integrator: This section must be aligned to a 64 BYTES border!"
   /* Pragma must be placed here. */
   /* Example for GHS compiler:  
#  pragma ghs section bss=default
   */
# endif

# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  ETH_30_MSE102X END
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**        \file  Lin_MemMap.inc
 *        \brief  AUTOSAR LIN Driver
 *
 *      \details  AUTOSAR LIN Driver for all target systems
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LIN START
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/
/* PRQA S 0883 514 */ /* MD_LIN_TESTSUITE_WORKAROUND */
#if defined(LIN_30_SJA1124SPI_START_SEC_CODE)
# undef LIN_30_SJA1124SPI_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_CODE)
# undef LIN_30_SJA1124SPI_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_CODE_FAST)
# undef LIN_30_SJA1124SPI_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_CODE_FAST)
# undef LIN_30_SJA1124SPI_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_CODE_ISR)
# undef LIN_30_SJA1124SPI_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_CODE_ISR)
# undef LIN_30_SJA1124SPI_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#ifdef LIN_30_SJA1124SPI_START_SEC_CODE_APPL
  #undef LIN_30_SJA1124SPI_START_SEC_CODE_APPL /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE         /* mapped to default code section */
#endif
#ifdef LIN_30_SJA1124SPI_STOP_SEC_CODE_APPL
  #undef LIN_30_SJA1124SPI_STOP_SEC_CODE_APPL /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE         /* default code stop section */
#endif


/*******  CONST sections  *********************************************************************************************/

/* CONST sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_CONST_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_CONST_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_CONST_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_CONST_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_CONST_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_CONST_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_CONST_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_CONST_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_FAST_CONST_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_FAST_CONST_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_FAST_CONST_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_FAST_CONST_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_FAST_CONST_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_FAST_CONST_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_FAST_CONST_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#if defined(LIN_30_SJA1124SPI_START_SEC_PBCFG_ROOT)
# undef LIN_30_SJA1124SPI_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_PBCFG_ROOT)
# undef LIN_30_SJA1124SPI_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#if defined(LIN_30_SJA1124SPI_START_SEC_PBCFG_GLOBALROOT)
# undef LIN_30_SJA1124SPI_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_PBCFG_GLOBALROOT)
# undef LIN_30_SJA1124SPI_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_PBCFG)
# undef LIN_30_SJA1124SPI_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_PBCFG)
# undef LIN_30_SJA1124SPI_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  ***********************************************************************************************/

/* VAR INIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_INIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_INIT_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_INIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_INIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_INIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_INIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOINIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOINIT_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOINIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOINIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOINIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOINIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_PBCFG)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_PBCFG)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_ZERO_INIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_ZERO_INIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_ZERO_INIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_INIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_INIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_INIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef LIN_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef LIN_30_SJA1124SPI_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  LIN END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  VMEM_30_XXHYPER01 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef VMEM_30_XXHYPER01_START_SEC_CODE
# undef VMEM_30_XXHYPER01_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#ifdef VMEM_30_XXHYPER01_STOP_SEC_CODE
# undef VMEM_30_XXHYPER01_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#ifdef VMEM_30_XXHYPER01_START_SEC_CONST_8BIT
# undef VMEM_30_XXHYPER01_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#ifdef VMEM_30_XXHYPER01_STOP_SEC_CONST_8BIT
# undef VMEM_30_XXHYPER01_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VMEM_30_XXHYPER01_START_SEC_CONST_32BIT
# undef VMEM_30_XXHYPER01_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef VMEM_30_XXHYPER01_STOP_SEC_CONST_32BIT
# undef VMEM_30_XXHYPER01_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VMEM_30_XXHYPER01_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXHYPER01_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VMEM_30_XXHYPER01_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXHYPER01_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef VMEM_30_XXHYPER01_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_XXHYPER01_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VMEM_30_XXHYPER01_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_XXHYPER01_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */
#ifdef VMEM_30_XXHYPER01_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXHYPER01_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VMEM_30_XXHYPER01_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXHYPER01_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VMEM_30_XXHYPER01 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_XXSPI01 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_XXSPI01_START_SEC_CODE)
# undef VMEM_30_XXSPI01_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_XXSPI01_STOP_SEC_CODE)
# undef VMEM_30_XXSPI01_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_XXSPI01_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_XXSPI01_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_XXSPI01_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_XXSPI01_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VMEM_30_XXSPI01_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXSPI01_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VMEM_30_XXSPI01_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXSPI01_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_XXSPI01_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_XXSPI01_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_XXSPI01_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_XXSPI01_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/
/* VAR ZERO INI sections */
#ifdef VMEM_30_XXSPI01_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXSPI01_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VMEM_30_XXSPI01_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXSPI01_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */
#ifdef VMEM_30_XXSPI01_START_SEC_VAR_NOINIT_8BIT
# undef VMEM_30_XXSPI01_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef VMEM_30_XXSPI01_STOP_SEC_VAR_NOINIT_8BIT
# undef VMEM_30_XXSPI01_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VMEM_30_XXSPI01_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_XXSPI01_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VMEM_30_XXSPI01_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_XXSPI01_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VMEM_30_XXSPI01_START_SEC_VAR_NOINIT_BUFFER
# undef VMEM_30_XXSPI01_START_SEC_VAR_NOINIT_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
# error "For the integrator: The start address of this section must be 32 bit aligned."
/* pragma must be placed here. */
/* Example for TI ARM compiler. */
/* # pragma SET_DATA_SECTION (".VMEM_SEC_VAR_NOINIT_BUFFER") */
#endif
#ifdef VMEM_30_XXSPI01_STOP_SEC_VAR_NOINIT_BUFFER
# undef VMEM_30_XXSPI01_STOP_SEC_VAR_NOINIT_BUFFER
# define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  VMEM_30_XXSPI01 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_XXSPI02 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_XXSPI02_START_SEC_CODE)
# undef VMEM_30_XXSPI02_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_XXSPI02_STOP_SEC_CODE)
# undef VMEM_30_XXSPI02_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_XXSPI02_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXSPI02_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_XXSPI02_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_XXSPI02_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */
#if defined VMEM_30_XXSPI02_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_XXSPI02_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined VMEM_30_XXSPI02_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_XXSPI02_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif
#if defined VMEM_30_XXSPI02_START_SEC_VAR_NOINIT_8BIT
# undef VMEM_30_XXSPI02_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined VMEM_30_XXSPI02_STOP_SEC_VAR_NOINIT_8BIT
# undef VMEM_30_XXSPI02_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#if defined VMEM_30_XXSPI02_START_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXSPI02_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined VMEM_30_XXSPI02_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VMEM_30_XXSPI02_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

/**********************************************************************************************************************
 *  VMEM_30_XXSPI02 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_FS26_START_SEC_CODE
  #undef SBC_30_FS26_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_FS26_STOP_SEC_CODE
  #undef SBC_30_FS26_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_FS26_START_SEC_CODE_FAST
  #undef SBC_30_FS26_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_FS26_STOP_SEC_CODE_FAST
  #undef SBC_30_FS26_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_FS26_START_SEC_CODE_ISR
  #undef SBC_30_FS26_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_FS26_STOP_SEC_CODE_ISR
  #undef SBC_30_FS26_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_FS26_START_SEC_CONST_8BIT
# undef SBC_30_FS26_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_FS26_STOP_SEC_CONST_8BIT
# undef SBC_30_FS26_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_FS26_START_SEC_CONST_16BIT
# undef SBC_30_FS26_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_CONST_16BIT
# undef SBC_30_FS26_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS26_START_SEC_CONST_32BIT
# undef SBC_30_FS26_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_CONST_32BIT
# undef SBC_30_FS26_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS26_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_FS26_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_FS26_START_SEC_FAST_CONST_8BIT
# undef SBC_30_FS26_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_FS26_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS26_START_SEC_FAST_CONST_16BIT
# undef SBC_30_FS26_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_FS26_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS26_START_SEC_FAST_CONST_32BIT
# undef SBC_30_FS26_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_FS26_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS26_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_FS26_START_SEC_PBCFG_ROOT
# undef SBC_30_FS26_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_FS26_STOP_SEC_PBCFG_ROOT
# undef SBC_30_FS26_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_FS26_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_FS26_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_FS26_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_FS26_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS26_START_SEC_PBCFG
# undef SBC_30_FS26_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_FS26_STOP_SEC_PBCFG
# undef SBC_30_FS26_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_INIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_INIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_INIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_FS26_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_FS26_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_FS26_START_SEC_VAR_PBCFG
# undef SBC_30_FS26_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_PBCFG
# undef SBC_30_FS26_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS26_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS26_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS26_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_FS6500_START_SEC_CODE
  #undef SBC_30_FS6500_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_FS6500_STOP_SEC_CODE
  #undef SBC_30_FS6500_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_FS6500_START_SEC_CODE_FAST
  #undef SBC_30_FS6500_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_FS6500_STOP_SEC_CODE_FAST
  #undef SBC_30_FS6500_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_FS6500_START_SEC_CODE_ISR
  #undef SBC_30_FS6500_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_FS6500_STOP_SEC_CODE_ISR
  #undef SBC_30_FS6500_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_FS6500_START_SEC_CONST_8BIT
# undef SBC_30_FS6500_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_FS6500_STOP_SEC_CONST_8BIT
# undef SBC_30_FS6500_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_FS6500_START_SEC_CONST_16BIT
# undef SBC_30_FS6500_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_CONST_16BIT
# undef SBC_30_FS6500_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS6500_START_SEC_CONST_32BIT
# undef SBC_30_FS6500_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_CONST_32BIT
# undef SBC_30_FS6500_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS6500_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_FS6500_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_FS6500_START_SEC_FAST_CONST_8BIT
# undef SBC_30_FS6500_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_FS6500_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS6500_START_SEC_FAST_CONST_16BIT
# undef SBC_30_FS6500_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_FS6500_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS6500_START_SEC_FAST_CONST_32BIT
# undef SBC_30_FS6500_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_FS6500_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS6500_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_FS6500_START_SEC_PBCFG_ROOT
# undef SBC_30_FS6500_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_FS6500_STOP_SEC_PBCFG_ROOT
# undef SBC_30_FS6500_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_FS6500_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_FS6500_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_FS6500_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS6500_START_SEC_PBCFG
# undef SBC_30_FS6500_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_FS6500_STOP_SEC_PBCFG
# undef SBC_30_FS6500_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_INIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_INIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_INIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_FS6500_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_FS6500_START_SEC_VAR_PBCFG
# undef SBC_30_FS6500_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_PBCFG
# undef SBC_30_FS6500_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS6500_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS6500_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS6500_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_FS85_START_SEC_CODE
  #undef SBC_30_FS85_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_FS85_STOP_SEC_CODE
  #undef SBC_30_FS85_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_FS85_START_SEC_CODE_FAST
  #undef SBC_30_FS85_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_FS85_STOP_SEC_CODE_FAST
  #undef SBC_30_FS85_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_FS85_START_SEC_CODE_ISR
  #undef SBC_30_FS85_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_FS85_STOP_SEC_CODE_ISR
  #undef SBC_30_FS85_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_FS85_START_SEC_CONST_8BIT
# undef SBC_30_FS85_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_FS85_STOP_SEC_CONST_8BIT
# undef SBC_30_FS85_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_FS85_START_SEC_CONST_16BIT
# undef SBC_30_FS85_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_CONST_16BIT
# undef SBC_30_FS85_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS85_START_SEC_CONST_32BIT
# undef SBC_30_FS85_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_CONST_32BIT
# undef SBC_30_FS85_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS85_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_FS85_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_FS85_START_SEC_FAST_CONST_8BIT
# undef SBC_30_FS85_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_FS85_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS85_START_SEC_FAST_CONST_16BIT
# undef SBC_30_FS85_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_FS85_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS85_START_SEC_FAST_CONST_32BIT
# undef SBC_30_FS85_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_FS85_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS85_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_FS85_START_SEC_PBCFG_ROOT
# undef SBC_30_FS85_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_FS85_STOP_SEC_PBCFG_ROOT
# undef SBC_30_FS85_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_FS85_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_FS85_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_FS85_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_FS85_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_FS85_START_SEC_PBCFG
# undef SBC_30_FS85_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_FS85_STOP_SEC_PBCFG
# undef SBC_30_FS85_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_INIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_INIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_INIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_FS85_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_FS85_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_FS85_START_SEC_VAR_PBCFG
# undef SBC_30_FS85_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_PBCFG
# undef SBC_30_FS85_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_FS85_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS85_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_FS85_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_GENERIC_START_SEC_CODE
  #undef SBC_30_GENERIC_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_CODE
  #undef SBC_30_GENERIC_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_GENERIC_START_SEC_CODE_FAST
  #undef SBC_30_GENERIC_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_CODE_FAST
  #undef SBC_30_GENERIC_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_GENERIC_START_SEC_CODE_ISR
  #undef SBC_30_GENERIC_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_CODE_ISR
  #undef SBC_30_GENERIC_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_GENERIC_START_SEC_CONST_8BIT
# undef SBC_30_GENERIC_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_CONST_8BIT
# undef SBC_30_GENERIC_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_GENERIC_START_SEC_CONST_16BIT
# undef SBC_30_GENERIC_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_CONST_16BIT
# undef SBC_30_GENERIC_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_GENERIC_START_SEC_CONST_32BIT
# undef SBC_30_GENERIC_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_CONST_32BIT
# undef SBC_30_GENERIC_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_GENERIC_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_GENERIC_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_GENERIC_START_SEC_FAST_CONST_8BIT
# undef SBC_30_GENERIC_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_GENERIC_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_GENERIC_START_SEC_FAST_CONST_16BIT
# undef SBC_30_GENERIC_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_GENERIC_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_GENERIC_START_SEC_FAST_CONST_32BIT
# undef SBC_30_GENERIC_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_GENERIC_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_GENERIC_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_GENERIC_START_SEC_PBCFG_ROOT
# undef SBC_30_GENERIC_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_PBCFG_ROOT
# undef SBC_30_GENERIC_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_GENERIC_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_GENERIC_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_GENERIC_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_GENERIC_START_SEC_PBCFG
# undef SBC_30_GENERIC_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_PBCFG
# undef SBC_30_GENERIC_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_INIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_INIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_INIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_GENERIC_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_GENERIC_START_SEC_VAR_PBCFG
# undef SBC_30_GENERIC_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_PBCFG
# undef SBC_30_GENERIC_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_GENERIC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_L9396_START_SEC_CODE
  #undef SBC_30_L9396_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_L9396_STOP_SEC_CODE
  #undef SBC_30_L9396_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_L9396_START_SEC_CODE_FAST
  #undef SBC_30_L9396_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_L9396_STOP_SEC_CODE_FAST
  #undef SBC_30_L9396_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_L9396_START_SEC_CODE_ISR
  #undef SBC_30_L9396_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_L9396_STOP_SEC_CODE_ISR
  #undef SBC_30_L9396_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_L9396_START_SEC_CONST_8BIT
# undef SBC_30_L9396_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_L9396_STOP_SEC_CONST_8BIT
# undef SBC_30_L9396_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_L9396_START_SEC_CONST_16BIT
# undef SBC_30_L9396_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_CONST_16BIT
# undef SBC_30_L9396_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L9396_START_SEC_CONST_32BIT
# undef SBC_30_L9396_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_CONST_32BIT
# undef SBC_30_L9396_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L9396_START_SEC_CONST_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_L9396_START_SEC_FAST_CONST_8BIT
# undef SBC_30_L9396_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_L9396_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L9396_START_SEC_FAST_CONST_16BIT
# undef SBC_30_L9396_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_L9396_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L9396_START_SEC_FAST_CONST_32BIT
# undef SBC_30_L9396_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_L9396_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L9396_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_L9396_START_SEC_PBCFG_ROOT
# undef SBC_30_L9396_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_L9396_STOP_SEC_PBCFG_ROOT
# undef SBC_30_L9396_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_L9396_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_L9396_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_L9396_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_L9396_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L9396_START_SEC_PBCFG
# undef SBC_30_L9396_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_L9396_STOP_SEC_PBCFG
# undef SBC_30_L9396_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_INIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_INIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_INIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_L9396_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_L9396_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_L9396_START_SEC_VAR_PBCFG
# undef SBC_30_L9396_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_PBCFG
# undef SBC_30_L9396_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L9396_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L9396_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L9396_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_L99PM62_START_SEC_CODE
  #undef SBC_30_L99PM62_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_CODE
  #undef SBC_30_L99PM62_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_L99PM62_START_SEC_CODE_FAST
  #undef SBC_30_L99PM62_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_CODE_FAST
  #undef SBC_30_L99PM62_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_L99PM62_START_SEC_CODE_ISR
  #undef SBC_30_L99PM62_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_CODE_ISR
  #undef SBC_30_L99PM62_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_L99PM62_START_SEC_CONST_8BIT
# undef SBC_30_L99PM62_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_CONST_8BIT
# undef SBC_30_L99PM62_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_L99PM62_START_SEC_CONST_16BIT
# undef SBC_30_L99PM62_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_CONST_16BIT
# undef SBC_30_L99PM62_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L99PM62_START_SEC_CONST_32BIT
# undef SBC_30_L99PM62_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_CONST_32BIT
# undef SBC_30_L99PM62_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L99PM62_START_SEC_CONST_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_L99PM62_START_SEC_FAST_CONST_8BIT
# undef SBC_30_L99PM62_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_L99PM62_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L99PM62_START_SEC_FAST_CONST_16BIT
# undef SBC_30_L99PM62_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_L99PM62_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L99PM62_START_SEC_FAST_CONST_32BIT
# undef SBC_30_L99PM62_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_L99PM62_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L99PM62_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_L99PM62_START_SEC_PBCFG_ROOT
# undef SBC_30_L99PM62_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_PBCFG_ROOT
# undef SBC_30_L99PM62_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_L99PM62_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_L99PM62_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_L99PM62_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_L99PM62_START_SEC_PBCFG
# undef SBC_30_L99PM62_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_PBCFG
# undef SBC_30_L99PM62_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_INIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_INIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_INIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_L99PM62_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_L99PM62_START_SEC_VAR_PBCFG
# undef SBC_30_L99PM62_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_PBCFG
# undef SBC_30_L99PM62_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_L99PM62_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_LP8774_START_SEC_CODE
  #undef SBC_30_LP8774_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_LP8774_STOP_SEC_CODE
  #undef SBC_30_LP8774_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_LP8774_START_SEC_CODE_FAST
  #undef SBC_30_LP8774_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_LP8774_STOP_SEC_CODE_FAST
  #undef SBC_30_LP8774_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_LP8774_START_SEC_CODE_ISR
  #undef SBC_30_LP8774_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_LP8774_STOP_SEC_CODE_ISR
  #undef SBC_30_LP8774_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_LP8774_START_SEC_CONST_8BIT
# undef SBC_30_LP8774_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_LP8774_STOP_SEC_CONST_8BIT
# undef SBC_30_LP8774_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_LP8774_START_SEC_CONST_16BIT
# undef SBC_30_LP8774_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_CONST_16BIT
# undef SBC_30_LP8774_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_LP8774_START_SEC_CONST_32BIT
# undef SBC_30_LP8774_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_CONST_32BIT
# undef SBC_30_LP8774_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_LP8774_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_LP8774_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_LP8774_START_SEC_FAST_CONST_8BIT
# undef SBC_30_LP8774_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_LP8774_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_LP8774_START_SEC_FAST_CONST_16BIT
# undef SBC_30_LP8774_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_LP8774_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_LP8774_START_SEC_FAST_CONST_32BIT
# undef SBC_30_LP8774_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_LP8774_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_LP8774_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_LP8774_START_SEC_PBCFG_ROOT
# undef SBC_30_LP8774_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_LP8774_STOP_SEC_PBCFG_ROOT
# undef SBC_30_LP8774_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_LP8774_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_LP8774_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_LP8774_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_LP8774_START_SEC_PBCFG
# undef SBC_30_LP8774_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_LP8774_STOP_SEC_PBCFG
# undef SBC_30_LP8774_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_INIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_INIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_INIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_LP8774_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_LP8774_START_SEC_VAR_PBCFG
# undef SBC_30_LP8774_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_PBCFG
# undef SBC_30_LP8774_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_LP8774_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_LP8774_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_LP8774_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_MC33905_START_SEC_CODE
  #undef SBC_30_MC33905_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_MC33905_STOP_SEC_CODE
  #undef SBC_30_MC33905_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_MC33905_START_SEC_CODE_FAST
  #undef SBC_30_MC33905_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_MC33905_STOP_SEC_CODE_FAST
  #undef SBC_30_MC33905_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_MC33905_START_SEC_CODE_ISR
  #undef SBC_30_MC33905_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_MC33905_STOP_SEC_CODE_ISR
  #undef SBC_30_MC33905_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_MC33905_START_SEC_CONST_8BIT
# undef SBC_30_MC33905_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_MC33905_STOP_SEC_CONST_8BIT
# undef SBC_30_MC33905_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_MC33905_START_SEC_CONST_16BIT
# undef SBC_30_MC33905_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_CONST_16BIT
# undef SBC_30_MC33905_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33905_START_SEC_CONST_32BIT
# undef SBC_30_MC33905_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_CONST_32BIT
# undef SBC_30_MC33905_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33905_START_SEC_CONST_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_MC33905_START_SEC_FAST_CONST_8BIT
# undef SBC_30_MC33905_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_MC33905_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33905_START_SEC_FAST_CONST_16BIT
# undef SBC_30_MC33905_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_MC33905_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33905_START_SEC_FAST_CONST_32BIT
# undef SBC_30_MC33905_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_MC33905_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33905_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_MC33905_START_SEC_PBCFG_ROOT
# undef SBC_30_MC33905_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_MC33905_STOP_SEC_PBCFG_ROOT
# undef SBC_30_MC33905_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_MC33905_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_MC33905_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_MC33905_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33905_START_SEC_PBCFG
# undef SBC_30_MC33905_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_MC33905_STOP_SEC_PBCFG
# undef SBC_30_MC33905_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_INIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_INIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_INIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_MC33905_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_MC33905_START_SEC_VAR_PBCFG
# undef SBC_30_MC33905_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_PBCFG
# undef SBC_30_MC33905_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33905_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33905_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33905_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_MC33908_START_SEC_CODE
  #undef SBC_30_MC33908_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_MC33908_STOP_SEC_CODE
  #undef SBC_30_MC33908_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_MC33908_START_SEC_CODE_FAST
  #undef SBC_30_MC33908_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_MC33908_STOP_SEC_CODE_FAST
  #undef SBC_30_MC33908_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_MC33908_START_SEC_CODE_ISR
  #undef SBC_30_MC33908_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_MC33908_STOP_SEC_CODE_ISR
  #undef SBC_30_MC33908_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_MC33908_START_SEC_CONST_8BIT
# undef SBC_30_MC33908_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_MC33908_STOP_SEC_CONST_8BIT
# undef SBC_30_MC33908_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_MC33908_START_SEC_CONST_16BIT
# undef SBC_30_MC33908_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_CONST_16BIT
# undef SBC_30_MC33908_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33908_START_SEC_CONST_32BIT
# undef SBC_30_MC33908_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_CONST_32BIT
# undef SBC_30_MC33908_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33908_START_SEC_CONST_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_MC33908_START_SEC_FAST_CONST_8BIT
# undef SBC_30_MC33908_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_MC33908_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33908_START_SEC_FAST_CONST_16BIT
# undef SBC_30_MC33908_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_MC33908_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33908_START_SEC_FAST_CONST_32BIT
# undef SBC_30_MC33908_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_MC33908_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33908_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_MC33908_START_SEC_PBCFG_ROOT
# undef SBC_30_MC33908_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_MC33908_STOP_SEC_PBCFG_ROOT
# undef SBC_30_MC33908_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_MC33908_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_MC33908_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_MC33908_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_MC33908_START_SEC_PBCFG
# undef SBC_30_MC33908_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_MC33908_STOP_SEC_PBCFG
# undef SBC_30_MC33908_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_INIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_INIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_INIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_MC33908_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_MC33908_START_SEC_VAR_PBCFG
# undef SBC_30_MC33908_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_PBCFG
# undef SBC_30_MC33908_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_MC33908_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33908_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_MC33908_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_TCAN114X_START_SEC_CODE
  #undef SBC_30_TCAN114X_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_CODE
  #undef SBC_30_TCAN114X_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_TCAN114X_START_SEC_CODE_FAST
  #undef SBC_30_TCAN114X_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_CODE_FAST
  #undef SBC_30_TCAN114X_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_TCAN114X_START_SEC_CODE_ISR
  #undef SBC_30_TCAN114X_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_CODE_ISR
  #undef SBC_30_TCAN114X_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_TCAN114X_START_SEC_CONST_8BIT
# undef SBC_30_TCAN114X_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_CONST_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_TCAN114X_START_SEC_CONST_16BIT
# undef SBC_30_TCAN114X_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_CONST_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN114X_START_SEC_CONST_32BIT
# undef SBC_30_TCAN114X_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_CONST_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN114X_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_TCAN114X_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_TCAN114X_START_SEC_FAST_CONST_8BIT
# undef SBC_30_TCAN114X_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN114X_START_SEC_FAST_CONST_16BIT
# undef SBC_30_TCAN114X_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN114X_START_SEC_FAST_CONST_32BIT
# undef SBC_30_TCAN114X_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN114X_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_TCAN114X_START_SEC_PBCFG_ROOT
# undef SBC_30_TCAN114X_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_PBCFG_ROOT
# undef SBC_30_TCAN114X_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_TCAN114X_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TCAN114X_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TCAN114X_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN114X_START_SEC_PBCFG
# undef SBC_30_TCAN114X_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_PBCFG
# undef SBC_30_TCAN114X_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_INIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_INIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_INIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_TCAN114X_START_SEC_VAR_PBCFG
# undef SBC_30_TCAN114X_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_PBCFG
# undef SBC_30_TCAN114X_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN114X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_TCAN1167_START_SEC_CODE
  #undef SBC_30_TCAN1167_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_CODE
  #undef SBC_30_TCAN1167_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_TCAN1167_START_SEC_CODE_FAST
  #undef SBC_30_TCAN1167_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_CODE_FAST
  #undef SBC_30_TCAN1167_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_TCAN1167_START_SEC_CODE_ISR
  #undef SBC_30_TCAN1167_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_CODE_ISR
  #undef SBC_30_TCAN1167_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_TCAN1167_START_SEC_CONST_8BIT
# undef SBC_30_TCAN1167_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_CONST_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_TCAN1167_START_SEC_CONST_16BIT
# undef SBC_30_TCAN1167_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_CONST_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN1167_START_SEC_CONST_32BIT
# undef SBC_30_TCAN1167_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_CONST_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN1167_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_TCAN1167_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_TCAN1167_START_SEC_FAST_CONST_8BIT
# undef SBC_30_TCAN1167_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN1167_START_SEC_FAST_CONST_16BIT
# undef SBC_30_TCAN1167_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN1167_START_SEC_FAST_CONST_32BIT
# undef SBC_30_TCAN1167_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN1167_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_TCAN1167_START_SEC_PBCFG_ROOT
# undef SBC_30_TCAN1167_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_PBCFG_ROOT
# undef SBC_30_TCAN1167_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_TCAN1167_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TCAN1167_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TCAN1167_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TCAN1167_START_SEC_PBCFG
# undef SBC_30_TCAN1167_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_PBCFG
# undef SBC_30_TCAN1167_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_INIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_INIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_INIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_TCAN1167_START_SEC_VAR_PBCFG
# undef SBC_30_TCAN1167_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_PBCFG
# undef SBC_30_TCAN1167_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TCAN1167_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_TLE9263_START_SEC_CODE
  #undef SBC_30_TLE9263_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_CODE
  #undef SBC_30_TLE9263_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_TLE9263_START_SEC_CODE_FAST
  #undef SBC_30_TLE9263_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_CODE_FAST
  #undef SBC_30_TLE9263_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_TLE9263_START_SEC_CODE_ISR
  #undef SBC_30_TLE9263_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_CODE_ISR
  #undef SBC_30_TLE9263_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_TLE9263_START_SEC_CONST_8BIT
# undef SBC_30_TLE9263_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_CONST_8BIT
# undef SBC_30_TLE9263_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_TLE9263_START_SEC_CONST_16BIT
# undef SBC_30_TLE9263_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_CONST_16BIT
# undef SBC_30_TLE9263_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9263_START_SEC_CONST_32BIT
# undef SBC_30_TLE9263_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_CONST_32BIT
# undef SBC_30_TLE9263_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9263_START_SEC_CONST_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_TLE9263_START_SEC_FAST_CONST_8BIT
# undef SBC_30_TLE9263_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_TLE9263_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9263_START_SEC_FAST_CONST_16BIT
# undef SBC_30_TLE9263_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_TLE9263_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9263_START_SEC_FAST_CONST_32BIT
# undef SBC_30_TLE9263_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_TLE9263_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9263_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_TLE9263_START_SEC_PBCFG_ROOT
# undef SBC_30_TLE9263_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_PBCFG_ROOT
# undef SBC_30_TLE9263_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_TLE9263_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLE9263_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLE9263_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9263_START_SEC_PBCFG
# undef SBC_30_TLE9263_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_PBCFG
# undef SBC_30_TLE9263_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_INIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_INIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_INIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLE9263_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_TLE9263_START_SEC_VAR_PBCFG
# undef SBC_30_TLE9263_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_PBCFG
# undef SBC_30_TLE9263_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9263_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_TLE9273_START_SEC_CODE
  #undef SBC_30_TLE9273_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_CODE
  #undef SBC_30_TLE9273_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_TLE9273_START_SEC_CODE_FAST
  #undef SBC_30_TLE9273_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_CODE_FAST
  #undef SBC_30_TLE9273_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_TLE9273_START_SEC_CODE_ISR
  #undef SBC_30_TLE9273_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_CODE_ISR
  #undef SBC_30_TLE9273_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_TLE9273_START_SEC_CONST_8BIT
# undef SBC_30_TLE9273_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_CONST_8BIT
# undef SBC_30_TLE9273_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_TLE9273_START_SEC_CONST_16BIT
# undef SBC_30_TLE9273_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_CONST_16BIT
# undef SBC_30_TLE9273_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9273_START_SEC_CONST_32BIT
# undef SBC_30_TLE9273_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_CONST_32BIT
# undef SBC_30_TLE9273_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9273_START_SEC_CONST_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_TLE9273_START_SEC_FAST_CONST_8BIT
# undef SBC_30_TLE9273_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_TLE9273_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9273_START_SEC_FAST_CONST_16BIT
# undef SBC_30_TLE9273_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_TLE9273_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9273_START_SEC_FAST_CONST_32BIT
# undef SBC_30_TLE9273_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_TLE9273_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9273_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_TLE9273_START_SEC_PBCFG_ROOT
# undef SBC_30_TLE9273_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_PBCFG_ROOT
# undef SBC_30_TLE9273_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_TLE9273_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLE9273_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLE9273_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9273_START_SEC_PBCFG
# undef SBC_30_TLE9273_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_PBCFG
# undef SBC_30_TLE9273_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_INIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_INIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_INIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLE9273_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_TLE9273_START_SEC_VAR_PBCFG
# undef SBC_30_TLE9273_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_PBCFG
# undef SBC_30_TLE9273_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9273_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_TLE9278_START_SEC_CODE
  #undef SBC_30_TLE9278_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_CODE
  #undef SBC_30_TLE9278_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_TLE9278_START_SEC_CODE_FAST
  #undef SBC_30_TLE9278_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_CODE_FAST
  #undef SBC_30_TLE9278_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_TLE9278_START_SEC_CODE_ISR
  #undef SBC_30_TLE9278_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_CODE_ISR
  #undef SBC_30_TLE9278_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_TLE9278_START_SEC_CONST_8BIT
# undef SBC_30_TLE9278_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_CONST_8BIT
# undef SBC_30_TLE9278_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_TLE9278_START_SEC_CONST_16BIT
# undef SBC_30_TLE9278_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_CONST_16BIT
# undef SBC_30_TLE9278_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9278_START_SEC_CONST_32BIT
# undef SBC_30_TLE9278_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_CONST_32BIT
# undef SBC_30_TLE9278_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9278_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_TLE9278_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_TLE9278_START_SEC_FAST_CONST_8BIT
# undef SBC_30_TLE9278_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_TLE9278_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9278_START_SEC_FAST_CONST_16BIT
# undef SBC_30_TLE9278_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_TLE9278_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9278_START_SEC_FAST_CONST_32BIT
# undef SBC_30_TLE9278_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_TLE9278_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9278_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_TLE9278_START_SEC_PBCFG_ROOT
# undef SBC_30_TLE9278_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_PBCFG_ROOT
# undef SBC_30_TLE9278_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_TLE9278_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLE9278_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLE9278_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLE9278_START_SEC_PBCFG
# undef SBC_30_TLE9278_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_PBCFG
# undef SBC_30_TLE9278_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_INIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_INIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_INIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLE9278_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_TLE9278_START_SEC_VAR_PBCFG
# undef SBC_30_TLE9278_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_PBCFG
# undef SBC_30_TLE9278_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLE9278_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_TLF3068X_START_SEC_CODE
  #undef SBC_30_TLF3068X_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_CODE
  #undef SBC_30_TLF3068X_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_TLF3068X_START_SEC_CODE_FAST
  #undef SBC_30_TLF3068X_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_CODE_FAST
  #undef SBC_30_TLF3068X_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_TLF3068X_START_SEC_CODE_ISR
  #undef SBC_30_TLF3068X_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_CODE_ISR
  #undef SBC_30_TLF3068X_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_TLF3068X_START_SEC_CONST_8BIT
# undef SBC_30_TLF3068X_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_CONST_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_TLF3068X_START_SEC_CONST_16BIT
# undef SBC_30_TLF3068X_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_CONST_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF3068X_START_SEC_CONST_32BIT
# undef SBC_30_TLF3068X_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_CONST_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF3068X_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_TLF3068X_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_TLF3068X_START_SEC_FAST_CONST_8BIT
# undef SBC_30_TLF3068X_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF3068X_START_SEC_FAST_CONST_16BIT
# undef SBC_30_TLF3068X_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF3068X_START_SEC_FAST_CONST_32BIT
# undef SBC_30_TLF3068X_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF3068X_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_TLF3068X_START_SEC_PBCFG_ROOT
# undef SBC_30_TLF3068X_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_PBCFG_ROOT
# undef SBC_30_TLF3068X_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_TLF3068X_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLF3068X_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLF3068X_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF3068X_START_SEC_PBCFG
# undef SBC_30_TLF3068X_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_PBCFG
# undef SBC_30_TLF3068X_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_INIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_INIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_INIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_TLF3068X_START_SEC_VAR_PBCFG
# undef SBC_30_TLF3068X_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_PBCFG
# undef SBC_30_TLF3068X_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF3068X_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_TLF35584_START_SEC_CODE
  #undef SBC_30_TLF35584_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_CODE
  #undef SBC_30_TLF35584_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_TLF35584_START_SEC_CODE_FAST
  #undef SBC_30_TLF35584_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_CODE_FAST
  #undef SBC_30_TLF35584_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_TLF35584_START_SEC_CODE_ISR
  #undef SBC_30_TLF35584_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_CODE_ISR
  #undef SBC_30_TLF35584_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_TLF35584_START_SEC_CONST_8BIT
# undef SBC_30_TLF35584_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_CONST_8BIT
# undef SBC_30_TLF35584_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_TLF35584_START_SEC_CONST_16BIT
# undef SBC_30_TLF35584_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_CONST_16BIT
# undef SBC_30_TLF35584_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF35584_START_SEC_CONST_32BIT
# undef SBC_30_TLF35584_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_CONST_32BIT
# undef SBC_30_TLF35584_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_TLF35584_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_TLF35584_START_SEC_FAST_CONST_8BIT
# undef SBC_30_TLF35584_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_TLF35584_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF35584_START_SEC_FAST_CONST_16BIT
# undef SBC_30_TLF35584_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_TLF35584_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF35584_START_SEC_FAST_CONST_32BIT
# undef SBC_30_TLF35584_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_TLF35584_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF35584_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_TLF35584_START_SEC_PBCFG_ROOT
# undef SBC_30_TLF35584_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_PBCFG_ROOT
# undef SBC_30_TLF35584_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_TLF35584_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLF35584_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TLF35584_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TLF35584_START_SEC_PBCFG
# undef SBC_30_TLF35584_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_PBCFG
# undef SBC_30_TLF35584_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_INIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_INIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_INIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLF35584_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_TLF35584_START_SEC_VAR_PBCFG
# undef SBC_30_TLF35584_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_PBCFG
# undef SBC_30_TLF35584_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TLF35584_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_TPS653850_START_SEC_CODE
  #undef SBC_30_TPS653850_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_CODE
  #undef SBC_30_TPS653850_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_TPS653850_START_SEC_CODE_FAST
  #undef SBC_30_TPS653850_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_CODE_FAST
  #undef SBC_30_TPS653850_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_TPS653850_START_SEC_CODE_ISR
  #undef SBC_30_TPS653850_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_CODE_ISR
  #undef SBC_30_TPS653850_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_TPS653850_START_SEC_CONST_8BIT
# undef SBC_30_TPS653850_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_CONST_8BIT
# undef SBC_30_TPS653850_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_TPS653850_START_SEC_CONST_16BIT
# undef SBC_30_TPS653850_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_CONST_16BIT
# undef SBC_30_TPS653850_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TPS653850_START_SEC_CONST_32BIT
# undef SBC_30_TPS653850_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_CONST_32BIT
# undef SBC_30_TPS653850_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TPS653850_START_SEC_CONST_UNSPECIFIED /* COV_SBC_UNUSED_MEM_SEC */
# undef SBC_30_TPS653850_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_TPS653850_START_SEC_FAST_CONST_8BIT
# undef SBC_30_TPS653850_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_TPS653850_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TPS653850_START_SEC_FAST_CONST_16BIT
# undef SBC_30_TPS653850_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_TPS653850_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TPS653850_START_SEC_FAST_CONST_32BIT
# undef SBC_30_TPS653850_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_TPS653850_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TPS653850_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_TPS653850_START_SEC_PBCFG_ROOT
# undef SBC_30_TPS653850_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_PBCFG_ROOT
# undef SBC_30_TPS653850_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_TPS653850_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TPS653850_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_TPS653850_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_TPS653850_START_SEC_PBCFG
# undef SBC_30_TPS653850_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_PBCFG
# undef SBC_30_TPS653850_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_INIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_INIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_INIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TPS653850_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_TPS653850_START_SEC_VAR_PBCFG
# undef SBC_30_TPS653850_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_PBCFG
# undef SBC_30_TPS653850_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_TPS653850_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_UJA1078_START_SEC_CODE
  #undef SBC_30_UJA1078_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_CODE
  #undef SBC_30_UJA1078_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_UJA1078_START_SEC_CODE_FAST
  #undef SBC_30_UJA1078_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_CODE_FAST
  #undef SBC_30_UJA1078_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_UJA1078_START_SEC_CODE_ISR
  #undef SBC_30_UJA1078_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_CODE_ISR
  #undef SBC_30_UJA1078_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_UJA1078_START_SEC_CONST_8BIT
# undef SBC_30_UJA1078_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_CONST_8BIT
# undef SBC_30_UJA1078_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_UJA1078_START_SEC_CONST_16BIT
# undef SBC_30_UJA1078_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_CONST_16BIT
# undef SBC_30_UJA1078_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1078_START_SEC_CONST_32BIT
# undef SBC_30_UJA1078_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_CONST_32BIT
# undef SBC_30_UJA1078_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1078_START_SEC_CONST_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_UJA1078_START_SEC_FAST_CONST_8BIT
# undef SBC_30_UJA1078_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_UJA1078_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1078_START_SEC_FAST_CONST_16BIT
# undef SBC_30_UJA1078_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_UJA1078_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1078_START_SEC_FAST_CONST_32BIT
# undef SBC_30_UJA1078_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_UJA1078_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1078_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_UJA1078_START_SEC_PBCFG_ROOT
# undef SBC_30_UJA1078_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_PBCFG_ROOT
# undef SBC_30_UJA1078_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_UJA1078_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_UJA1078_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_UJA1078_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1078_START_SEC_PBCFG
# undef SBC_30_UJA1078_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_PBCFG
# undef SBC_30_UJA1078_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_INIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_INIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_INIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_UJA1078_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_UJA1078_START_SEC_VAR_PBCFG
# undef SBC_30_UJA1078_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_PBCFG
# undef SBC_30_UJA1078_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1078_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef SBC_30_UJA1168_START_SEC_CODE
  #undef SBC_30_UJA1168_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE      /* mapped to default code section */
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_CODE
  #undef SBC_30_UJA1168_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE      /* default code stop section */
#endif

#ifdef SBC_30_UJA1168_START_SEC_CODE_FAST
  #undef SBC_30_UJA1168_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_FAST      /* mapped to default fast code section */
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_CODE_FAST
  #undef SBC_30_UJA1168_STOP_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE           /* default code stop section */
#endif

#ifdef SBC_30_UJA1168_START_SEC_CODE_ISR
  #undef SBC_30_UJA1168_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CODE_ISR      /* mapped to default ISR code section */
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_CODE_ISR
  #undef SBC_30_UJA1168_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef SBC_30_UJA1168_START_SEC_CONST_8BIT
# undef SBC_30_UJA1168_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT      /* mapped to default const 8bit section */
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_CONST_8BIT
# undef SBC_30_UJA1168_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#ifdef SBC_30_UJA1168_START_SEC_CONST_16BIT
# undef SBC_30_UJA1168_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_CONST_16BIT
# undef SBC_30_UJA1168_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1168_START_SEC_CONST_32BIT
# undef SBC_30_UJA1168_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_CONST_32BIT
# undef SBC_30_UJA1168_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1168_START_SEC_CONST_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_CONST_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#ifdef SBC_30_UJA1168_START_SEC_FAST_CONST_8BIT
# undef SBC_30_UJA1168_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_FAST_CONST_8BIT
# undef SBC_30_UJA1168_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1168_START_SEC_FAST_CONST_16BIT
# undef SBC_30_UJA1168_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_FAST_CONST_16BIT
# undef SBC_30_UJA1168_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1168_START_SEC_FAST_CONST_32BIT
# undef SBC_30_UJA1168_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_FAST_CONST_32BIT
# undef SBC_30_UJA1168_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1168_START_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_FAST_CONST_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

/* NOTE: ASR3.x till ASR4.0.1 only. Root table for postbuild data */
#ifdef SBC_30_UJA1168_START_SEC_PBCFG_ROOT
# undef SBC_30_UJA1168_START_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_PBCFG_ROOT
# undef SBC_30_UJA1168_STOP_SEC_PBCFG_ROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* ESCAN00065501 */
/* NOTE: ASR4.0.3 (CFG5) only. The origin root table for postbuild data. Relevant only for EcuM. */
#ifdef SBC_30_UJA1168_START_SEC_PBCFG_GLOBALROOT
# undef SBC_30_UJA1168_START_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_PBCFG_GLOBALROOT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_PBCFG_GLOBALROOT
# undef SBC_30_UJA1168_STOP_SEC_PBCFG_GLOBALROOT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef SBC_30_UJA1168_START_SEC_PBCFG
# undef SBC_30_UJA1168_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_PBCFG
# undef SBC_30_UJA1168_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_INIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_INIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_INIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_INIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_INIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_INIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOINIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOINIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOINIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOINIT_SAFE
# undef SBC_30_UJA1168_START_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_SAFE
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_SAFE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#ifdef SBC_30_UJA1168_START_SEC_VAR_PBCFG
# undef SBC_30_UJA1168_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_PBCFG
# undef SBC_30_UJA1168_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_ZERO_INIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_ZERO_INIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_INIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_INIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_INIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_NOINIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_NOINIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_NOINIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_INIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_INIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_INIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#ifdef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# undef SBC_30_UJA1168_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_88Q1010 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_88Q1010_START_SEC_CODE
# undef ETHTRCV_30_88Q1010_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_CODE
# undef ETHTRCV_30_88Q1010_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_88Q1010_START_SEC_CONST_8BIT
# undef ETHTRCV_30_88Q1010_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_88Q1010_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_CONST_16BIT
# undef ETHTRCV_30_88Q1010_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_88Q1010_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_CONST_32BIT
# undef ETHTRCV_30_88Q1010_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_88Q1010_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_88Q1010_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_88Q1010_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_PBCFG
# undef ETHTRCV_30_88Q1010_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_PBCFG
# undef ETHTRCV_30_88Q1010_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_88Q1010_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_88Q1010_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q1010_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_88Q1010_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_88Q1010_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_88Q1010_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_88Q1010 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_88Q2112 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_88Q2112_START_SEC_CODE
# undef ETHTRCV_30_88Q2112_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_CODE
# undef ETHTRCV_30_88Q2112_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_88Q2112_START_SEC_CONST_8BIT
# undef ETHTRCV_30_88Q2112_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_88Q2112_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_CONST_16BIT
# undef ETHTRCV_30_88Q2112_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_88Q2112_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_CONST_32BIT
# undef ETHTRCV_30_88Q2112_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_88Q2112_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_88Q2112_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_88Q2112_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_PBCFG
# undef ETHTRCV_30_88Q2112_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_PBCFG
# undef ETHTRCV_30_88Q2112_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_88Q2112_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_88Q2112_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_88Q2112_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_88Q2112_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_88Q2112_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_88Q2112_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_88Q2112 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_AR7000 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_AR7000_START_SEC_CODE
  #undef ETHTRCV_30_AR7000_START_SEC_CODE
  #define START_SEC_CODE                            /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CODE
  #undef ETHTRCV_30_AR7000_STOP_SEC_CODE
  #define STOP_SEC_CODE                             /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_8BIT
# undef ETHTRCV_30_AR7000_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_16BIT
# undef ETHTRCV_30_AR7000_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_32BIT
# undef ETHTRCV_30_AR7000_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_AR7000_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

/*******  NVM sections  **********************************************************************************************/

#ifdef ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED_NVM
# undef ETHTRCV_30_AR7000_START_SEC_CONST_UNSPECIFIED_NVM
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED_NVM
# undef ETHTRCV_30_AR7000_STOP_SEC_CONST_UNSPECIFIED_NVM
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED_NVM
# undef ETHTRCV_30_AR7000_START_SEC_VAR_NOINIT_UNSPECIFIED_NVM
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED_NVM
# undef ETHTRCV_30_AR7000_STOP_SEC_VAR_NOINIT_UNSPECIFIED_NVM
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_AR7000 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM89810 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_BCM89810_START_SEC_CODE
# undef ETHTRCV_30_BCM89810_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_CODE
# undef ETHTRCV_30_BCM89810_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_BCM89810_START_SEC_CONST_8BIT
# undef ETHTRCV_30_BCM89810_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_BCM89810_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_CONST_16BIT
# undef ETHTRCV_30_BCM89810_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_BCM89810_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_CONST_32BIT
# undef ETHTRCV_30_BCM89810_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_BCM89810_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_BCM89810_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_BCM89810_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_PBCFG
# undef ETHTRCV_30_BCM89810_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_PBCFG
# undef ETHTRCV_30_BCM89810_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_BCM89810_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_BCM89810_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_BCM89810_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_BCM89810_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_BCM89810_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_BCM89810_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_BCM89810_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_BCM89810_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_BCM89810_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_BCM89810_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_BCM89810_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_BCM89810_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_BCM89810_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89810_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_BCM89810_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM89810_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_BCM89810_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM89810 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM89811 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_BCM89811_START_SEC_CODE
# undef ETHTRCV_30_BCM89811_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_CODE
# undef ETHTRCV_30_BCM89811_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_BCM89811_START_SEC_CONST_8BIT
# undef ETHTRCV_30_BCM89811_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_BCM89811_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_CONST_16BIT
# undef ETHTRCV_30_BCM89811_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_BCM89811_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_CONST_32BIT
# undef ETHTRCV_30_BCM89811_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_BCM89811_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_BCM89811_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_BCM89811_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_PBCFG
# undef ETHTRCV_30_BCM89811_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_PBCFG
# undef ETHTRCV_30_BCM89811_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_BCM89811_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_BCM89811_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_BCM89811_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_BCM89811_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_BCM89811_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_BCM89811_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_BCM89811_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_BCM89811_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_BCM89811_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_BCM89811_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_BCM89811_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_BCM89811_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_BCM89811_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM89811_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_BCM89811_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM89811_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_BCM89811_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM89811 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM8988X START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_BCM8988X_START_SEC_CODE
# undef ETHTRCV_30_BCM8988X_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_CODE
# undef ETHTRCV_30_BCM8988X_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_BCM8988X_START_SEC_CONST_8BIT
# undef ETHTRCV_30_BCM8988X_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_BCM8988X_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_CONST_16BIT
# undef ETHTRCV_30_BCM8988X_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_BCM8988X_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_CONST_32BIT
# undef ETHTRCV_30_BCM8988X_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_BCM8988X_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_BCM8988X_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_BCM8988X_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_PBCFG
# undef ETHTRCV_30_BCM8988X_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_PBCFG
# undef ETHTRCV_30_BCM8988X_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_BCM8988X_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_BCM8988X_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_BCM8988X_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_BCM8988X_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_BCM8988X_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_BCM8988X_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_BCM8988X_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_BCM8988X_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_BCM8988X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_BCM8988X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_BCM8988X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM8988X END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TC811 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_DP83TC811_START_SEC_CODE
# undef ETHTRCV_30_DP83TC811_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_CODE
# undef ETHTRCV_30_DP83TC811_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_DP83TC811_START_SEC_CONST_8BIT
# undef ETHTRCV_30_DP83TC811_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_DP83TC811_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_CONST_16BIT
# undef ETHTRCV_30_DP83TC811_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_DP83TC811_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_CONST_32BIT
# undef ETHTRCV_30_DP83TC811_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_DP83TC811_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_DP83TC811_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_DP83TC811_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_PBCFG
# undef ETHTRCV_30_DP83TC811_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_PBCFG
# undef ETHTRCV_30_DP83TC811_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_DP83TC811_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_DP83TC811_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_DP83TC811_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_DP83TC811_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_DP83TC811_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_DP83TC811_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_DP83TC811_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_DP83TC811_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TC811_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_DP83TC811_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_DP83TC811_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TC811 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TG720 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_DP83TG720_START_SEC_CODE
# undef ETHTRCV_30_DP83TG720_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_CODE
# undef ETHTRCV_30_DP83TG720_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_DP83TG720_START_SEC_CONST_8BIT
# undef ETHTRCV_30_DP83TG720_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_DP83TG720_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_CONST_16BIT
# undef ETHTRCV_30_DP83TG720_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_DP83TG720_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_CONST_32BIT
# undef ETHTRCV_30_DP83TG720_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_DP83TG720_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_DP83TG720_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_DP83TG720_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_PBCFG
# undef ETHTRCV_30_DP83TG720_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_PBCFG
# undef ETHTRCV_30_DP83TG720_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_DP83TG720_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_DP83TG720_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_DP83TG720_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_DP83TG720_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_DP83TG720_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_DP83TG720_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_DP83TG720_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_DP83TG720_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_DP83TG720_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_DP83TG720_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_DP83TG720_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TG720 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTRCV_30_E52013 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_E52013_START_SEC_CODE) /* PRQA S 0883 */ /* Appears only while testing */
# undef CANTRCV_30_E52013_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CODE)
# undef CANTRCV_30_E52013_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_E52013_START_SEC_CODE_FAST)
# undef CANTRCV_30_E52013_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_E52013_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_E52013_START_SEC_CODE_ISR)
# undef CANTRCV_30_E52013_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_E52013_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_E52013_START_SEC_CONST_8BIT)
# undef CANTRCV_30_E52013_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_E52013_START_SEC_CONST_16BIT)
# undef CANTRCV_30_E52013_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_E52013_START_SEC_CONST_32BIT)
# undef CANTRCV_30_E52013_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_E52013_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_E52013_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_E52013_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_E52013_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_E52013_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_E52013_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_E52013_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_E52013_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_E52013_START_SEC_PBCFG)
# undef CANTRCV_30_E52013_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_PBCFG)
# undef CANTRCV_30_E52013_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_E52013_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_E52013_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_E52013_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_E52013 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_ETHMII START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_ETHMII_START_SEC_CODE
# undef ETHTRCV_30_ETHMII_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_CODE
# undef ETHTRCV_30_ETHMII_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_ETHMII_START_SEC_CONST_8BIT
# undef ETHTRCV_30_ETHMII_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_ETHMII_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_CONST_16BIT
# undef ETHTRCV_30_ETHMII_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_ETHMII_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_CONST_32BIT
# undef ETHTRCV_30_ETHMII_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_ETHMII_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_ETHMII_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_ETHMII_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_PBCFG
# undef ETHTRCV_30_ETHMII_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_PBCFG
# undef ETHTRCV_30_ETHMII_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_ETHMII_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_ETHMII_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_ETHMII_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_ETHMII_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_ETHMII_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_ETHMII_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_ETHMII END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTRCV_30_GENERICCAN START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CODE)
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CODE)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CODE_FAST)
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CODE_ISR)
# undef CANTRCV_30_GENERICCAN_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_PBCFG)
# undef CANTRCV_30_GENERICCAN_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_PBCFG)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_GENERICCAN_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_GENERICCAN END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRTRCV_30___YOUR_TRCV___START_SEC_CODE 
    #undef FRTRCV_30___YOUR_TRCV___START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_30___YOUR_TRCV___STOP_SEC_CODE 
    #undef FRTRCV_30___YOUR_TRCV___STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRTRCV_30___YOUR_TRCV___START_SEC_CONST_8BIT 
    #undef FRTRCV_30___YOUR_TRCV___START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRTRCV_30___YOUR_TRCV___STOP_SEC_CONST_8BIT 
    #undef FRTRCV_30___YOUR_TRCV___STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_30___YOUR_TRCV___START_SEC_CONST_32BIT 
    #undef FRTRCV_30___YOUR_TRCV___START_SEC_CONST_32BIT 
    #define START_SEC_CONST_32BIT
#endif

#ifdef FRTRCV_30___YOUR_TRCV___STOP_SEC_CONST_32BIT 
    #undef FRTRCV_30___YOUR_TRCV___STOP_SEC_CONST_32BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_30___YOUR_TRCV___START_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_30___YOUR_TRCV___START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRTRCV_30___YOUR_TRCV___STOP_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_30___YOUR_TRCV___STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR sections */

#ifdef FRTRCV_30___YOUR_TRCV___START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_30___YOUR_TRCV___START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FRTRCV_30___YOUR_TRCV___STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_30___YOUR_TRCV___STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LIN TRANSCEIVER GENERIC DRIVER START
 *********************************************************************************************************************/
/*******  CODE sections **********************************************************************************************/

#if defined(LINTRCV_30_GENERIC_START_SEC_CODE)
# undef LINTRCV_30_GENERIC_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined(LINTRCV_30_GENERIC_STOP_SEC_CODE)
# undef LINTRCV_30_GENERIC_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(LINTRCV_30_GENERIC_START_SEC_CONST_8BIT)
# undef LINTRCV_30_GENERIC_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(LINTRCV_30_GENERIC_STOP_SEC_CONST_8BIT)
# undef LINTRCV_30_GENERIC_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LINTRCV_30_GENERIC_START_SEC_CONST_32BIT)
# undef LINTRCV_30_GENERIC_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(LINTRCV_30_GENERIC_STOP_SEC_CONST_32BIT)
# undef LINTRCV_30_GENERIC_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


#if defined(LINTRCV_30_GENERIC_START_SEC_CONST_UNSPECIFIED)
# undef LINTRCV_30_GENERIC_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(LINTRCV_30_GENERIC_STOP_SEC_CONST_UNSPECIFIED)
# undef LINTRCV_30_GENERIC_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(LINTRCV_30_GENERIC_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LINTRCV_30_GENERIC_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(LINTRCV_30_GENERIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LINTRCV_30_GENERIC_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(LINTRCV_30_GENERIC_START_SEC_VAR_ZERO_INIT_8BIT)
# undef LINTRCV_30_GENERIC_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(LINTRCV_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef LINTRCV_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LINTRCV_30_GENERIC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LINTRCV_30_GENERIC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LINTRCV_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LINTRCV_30_GENERIC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* PRQA S 0883 4 */ /* MD_LINTRCV_0883 */
/**********************************************************************************************************************
 *  LIN TRANSCEIVER GENERIC DRIVER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_KD10XX START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_KD10XX_START_SEC_CODE
# undef ETHTRCV_30_KD10XX_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_CODE
# undef ETHTRCV_30_KD10XX_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_KD10XX_START_SEC_CONST_8BIT
# undef ETHTRCV_30_KD10XX_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_KD10XX_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_CONST_16BIT
# undef ETHTRCV_30_KD10XX_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_KD10XX_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_CONST_32BIT
# undef ETHTRCV_30_KD10XX_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_KD10XX_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_KD10XX_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_KD10XX_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_PBCFG
# undef ETHTRCV_30_KD10XX_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_PBCFG
# undef ETHTRCV_30_KD10XX_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_KD10XX_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_KD10XX_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_KD10XX_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_KD10XX_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_KD10XX_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_KD10XX_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_KD10XX_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_KD10XX_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_KD10XX_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_KD10XX_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_KD10XX_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_KD10XX_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_KD10XX_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KD10XX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_KD10XX_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_KD10XX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_KD10XX_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_KD10XX END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_KSZ9031 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_KSZ9031_START_SEC_CODE
# undef ETHTRCV_30_KSZ9031_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_CODE
# undef ETHTRCV_30_KSZ9031_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_KSZ9031_START_SEC_CONST_8BIT
# undef ETHTRCV_30_KSZ9031_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_KSZ9031_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_CONST_16BIT
# undef ETHTRCV_30_KSZ9031_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_KSZ9031_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_CONST_32BIT
# undef ETHTRCV_30_KSZ9031_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_KSZ9031_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_KSZ9031_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_KSZ9031_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_PBCFG
# undef ETHTRCV_30_KSZ9031_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_PBCFG
# undef ETHTRCV_30_KSZ9031_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_KSZ9031_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_KSZ9031_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_KSZ9031_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_KSZ9031_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_KSZ9031_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_KSZ9031_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_KSZ9031_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_KSZ9031_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_KSZ9031_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_KSZ9031_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_KSZ9031_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_KSZ9031 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_MSE102X START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_MSE102X_START_SEC_CODE
# undef ETHTRCV_30_MSE102X_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_CODE
# undef ETHTRCV_30_MSE102X_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_MSE102X_START_SEC_CONST_8BIT
# undef ETHTRCV_30_MSE102X_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_MSE102X_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_CONST_16BIT
# undef ETHTRCV_30_MSE102X_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_MSE102X_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_CONST_32BIT
# undef ETHTRCV_30_MSE102X_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_MSE102X_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_MSE102X_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_MSE102X_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_PBCFG
# undef ETHTRCV_30_MSE102X_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_PBCFG
# undef ETHTRCV_30_MSE102X_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_MSE102X_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_MSE102X_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_MSE102X_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_MSE102X_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_MSE102X_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_MSE102X_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_MSE102X_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_MSE102X_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_MSE102X_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_MSE102X_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_MSE102X_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_MSE102X_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_MSE102X_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_MSE102X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_MSE102X_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_MSE102X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_MSE102X_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_MSE102X END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_RTL9000 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_RTL9000_START_SEC_CODE
# undef ETHTRCV_30_RTL9000_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_CODE
# undef ETHTRCV_30_RTL9000_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_RTL9000_START_SEC_CONST_8BIT
# undef ETHTRCV_30_RTL9000_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_RTL9000_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_CONST_16BIT
# undef ETHTRCV_30_RTL9000_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_RTL9000_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_CONST_32BIT
# undef ETHTRCV_30_RTL9000_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_RTL9000_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_RTL9000_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_RTL9000_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_PBCFG
# undef ETHTRCV_30_RTL9000_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_PBCFG
# undef ETHTRCV_30_RTL9000_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_RTL9000_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_RTL9000_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_RTL9000_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_RTL9000_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_RTL9000_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_RTL9000_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_RTL9000_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_RTL9000_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_RTL9000_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_RTL9000_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_RTL9000_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_RTL9000_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_RTL9000_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9000_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_RTL9000_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_RTL9000_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_RTL9000_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_RTL9000 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_RTL9010 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_RTL9010_START_SEC_CODE
# undef ETHTRCV_30_RTL9010_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_CODE
# undef ETHTRCV_30_RTL9010_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_RTL9010_START_SEC_CONST_8BIT
# undef ETHTRCV_30_RTL9010_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_RTL9010_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_CONST_16BIT
# undef ETHTRCV_30_RTL9010_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_RTL9010_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_CONST_32BIT
# undef ETHTRCV_30_RTL9010_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_RTL9010_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_RTL9010_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_RTL9010_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_PBCFG
# undef ETHTRCV_30_RTL9010_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_PBCFG
# undef ETHTRCV_30_RTL9010_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_RTL9010_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_RTL9010_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_RTL9010_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_RTL9010_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_RTL9010_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_RTL9010_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_RTL9010_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_RTL9010_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_RTL9010_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_RTL9010_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_RTL9010 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTRCV_30_SBC START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_SBC_START_SEC_CODE) /* PRQA S 0883 */ /* Appears only while testing */
# undef CANTRCV_30_SBC_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_CODE)
# undef CANTRCV_30_SBC_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_SBC_START_SEC_CODE_FAST)
# undef CANTRCV_30_SBC_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_SBC_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_SBC_START_SEC_CODE_ISR)
# undef CANTRCV_30_SBC_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_SBC_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_SBC_START_SEC_CONST_8BIT)
# undef CANTRCV_30_SBC_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_SBC_START_SEC_CONST_16BIT)
# undef CANTRCV_30_SBC_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_SBC_START_SEC_CONST_32BIT)
# undef CANTRCV_30_SBC_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_SBC_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_SBC_START_SEC_FAST_CONST_8BIT)
# undef CANTRCV_30_SBC_START_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_FAST_CONST_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_FAST_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_SBC_START_SEC_FAST_CONST_16BIT)
# undef CANTRCV_30_SBC_START_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_FAST_CONST_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_FAST_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_SBC_START_SEC_FAST_CONST_32BIT)
# undef CANTRCV_30_SBC_START_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_FAST_CONST_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_FAST_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_SBC_START_SEC_FAST_CONST_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_FAST_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_FAST_CONST_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_FAST_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_SBC_START_SEC_PBCFG)
# undef CANTRCV_30_SBC_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_PBCFG)
# undef CANTRCV_30_SBC_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_SBC_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_SBC_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_SBC_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_SBC END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LIN TRANSCEIVER SBC DRIVER START
 *********************************************************************************************************************/
/*******  CODE sections **********************************************************************************************/

#if defined(LINTRCV_30_SBC_START_SEC_CODE)
# undef LINTRCV_30_SBC_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined(LINTRCV_30_SBC_STOP_SEC_CODE)
# undef LINTRCV_30_SBC_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(LINTRCV_30_SBC_START_SEC_CONST_8BIT)
# undef LINTRCV_30_SBC_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(LINTRCV_30_SBC_STOP_SEC_CONST_8BIT)
# undef LINTRCV_30_SBC_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LINTRCV_30_SBC_START_SEC_CONST_32BIT)
# undef LINTRCV_30_SBC_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(LINTRCV_30_SBC_STOP_SEC_CONST_32BIT)
# undef LINTRCV_30_SBC_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


#if defined(LINTRCV_30_SBC_START_SEC_CONST_UNSPECIFIED)
# undef LINTRCV_30_SBC_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(LINTRCV_30_SBC_STOP_SEC_CONST_UNSPECIFIED)
# undef LINTRCV_30_SBC_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(LINTRCV_30_SBC_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LINTRCV_30_SBC_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(LINTRCV_30_SBC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LINTRCV_30_SBC_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(LINTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_8BIT)
# undef LINTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(LINTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef LINTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LINTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LINTRCV_30_SBC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LINTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LINTRCV_30_SBC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* PRQA S 0883 4 */ /* MD_LINTRCV_0883 */
/**********************************************************************************************************************
 *  LIN TRANSCEIVER SBC DRIVER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1040 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TJA1040_START_SEC_CODE)
# undef CANTRCV_30_TJA1040_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CODE)
# undef CANTRCV_30_TJA1040_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1040_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1040_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1040_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1040_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_PBCFG)
# undef CANTRCV_30_TJA1040_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_PBCFG)
# undef CANTRCV_30_TJA1040_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1040_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1040 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1041 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TJA1041_START_SEC_CODE)
# undef CANTRCV_30_TJA1041_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CODE)
# undef CANTRCV_30_TJA1041_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1041_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1041_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1041_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1041_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_PBCFG)
# undef CANTRCV_30_TJA1041_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_PBCFG)
# undef CANTRCV_30_TJA1041_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1041_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1041 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE)
# undef CANTRCV_30_TJA1043_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1043_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1043_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1043_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_PBCFG)
# undef CANTRCV_30_TJA1043_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_PBCFG)
# undef CANTRCV_30_TJA1043_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1043_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1048 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TJA1048_START_SEC_CODE)
# undef CANTRCV_30_TJA1048_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CODE)
# undef CANTRCV_30_TJA1048_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1048_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1048_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1048_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1048_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_PBCFG)
# undef CANTRCV_30_TJA1048_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_PBCFG)
# undef CANTRCV_30_TJA1048_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1048_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1048 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1055 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TJA1055_START_SEC_CODE)
# undef CANTRCV_30_TJA1055_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CODE)
# undef CANTRCV_30_TJA1055_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1055_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1055_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1055_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1055_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_PBCFG)
# undef CANTRCV_30_TJA1055_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_PBCFG)
# undef CANTRCV_30_TJA1055_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1055_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1055 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  FRTRCV TJA1080 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRTRCV_30_TJA1080_START_SEC_CODE 
    #undef FRTRCV_30_TJA1080_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_CODE 
    #undef FRTRCV_30_TJA1080_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_30_TJA1080_START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_30_TJA1080_STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_30_TJA1080_START_SEC_CONST_32BIT 
    #undef FRTRCV_30_TJA1080_START_SEC_CONST_32BIT 
    #define START_SEC_CONST_32BIT
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_CONST_32BIT 
    #undef FRTRCV_30_TJA1080_STOP_SEC_CONST_32BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_30_TJA1080_START_SEC_CONST_16BIT 
    #undef FRTRCV_30_TJA1080_START_SEC_CONST_16BIT 
    #define START_SEC_CONST_16BIT
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_CONST_16BIT 
    #undef FRTRCV_30_TJA1080_STOP_SEC_CONST_16BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_30_TJA1080_START_SEC_CONST_8BIT 
    #undef FRTRCV_30_TJA1080_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_CONST_8BIT 
    #undef FRTRCV_30_TJA1080_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/


#ifdef FRTRCV_30_TJA1080_START_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1080_START_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1080_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_32BIT 
    #undef FRTRCV_30_TJA1080_START_SEC_VAR_NOINIT_32BIT 
    #define START_SEC_VAR_NOINIT_32BIT
#endif

#ifdef FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_32BIT 
    #undef FRTRCV_30_TJA1080_STOP_SEC_VAR_NOINIT_32BIT 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRTRCV TJA1080 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FRTRCV_30_TJA1082 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRTRCV_30_TJA1082_START_SEC_CODE
    #undef FRTRCV_30_TJA1082_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_30_TJA1082_STOP_SEC_CODE 
    #undef FRTRCV_30_TJA1082_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRTRCV_30_TJA1082_START_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRTRCV_30_TJA1082_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_32BIT
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_32BIT
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_8BIT
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef FRTRCV_30_TJA1082_START_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef FRTRCV_30_TJA1082_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED 
    #undef FRTRCV_30_TJA1082_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRTRCV_30_TJA1082 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef FRTRCV_START_SEC_CODE 
    #undef FRTRCV_START_SEC_CODE 
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_STOP_SEC_CODE 
    #undef FRTRCV_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif

#ifdef FRTRCV_30_TJA1085_START_SEC_CODE
    #undef FRTRCV_30_TJA1085_START_SEC_CODE
    #define START_SEC_CODE
#endif

#ifdef FRTRCV_30_TJA1085_STOP_SEC_CODE 
    #undef FRTRCV_30_TJA1085_STOP_SEC_CODE 
    #define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef FRTRCV_START_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_START_SEC_CONST_UNSPECIFIED 
    #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FRTRCV_STOP_SEC_CONST_UNSPECIFIED 
    #undef FRTRCV_STOP_SEC_CONST_UNSPECIFIED 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_START_SEC_CONST_32BIT 
    #undef FRTRCV_START_SEC_CONST_32BIT 
    #define START_SEC_CONST_32BIT
#endif

#ifdef FRTRCV_STOP_SEC_CONST_32BIT 
    #undef FRTRCV_STOP_SEC_CONST_32BIT 
    #define STOP_SEC_CONST
#endif

#ifdef FRTRCV_START_SEC_CONST_8BIT 
    #undef FRTRCV_START_SEC_CONST_8BIT 
    #define START_SEC_CONST_8BIT
#endif

#ifdef FRTRCV_STOP_SEC_CONST_8BIT 
    #undef FRTRCV_STOP_SEC_CONST_8BIT 
    #define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#ifdef FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif

#ifdef FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef FRTRCV_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
    #define STOP_SEC_VAR
#endif


#ifdef FRTRCV_START_SEC_VAR_NOINIT_8BIT
    #undef FRTRCV_START_SEC_VAR_NOINIT_8BIT 
    #define START_SEC_VAR_NOINIT_8BIT
#endif

#ifdef FRTRCV_STOP_SEC_VAR_NOINIT_8BIT 
    #undef FRTRCV_STOP_SEC_VAR_NOINIT_8BIT 
    #define STOP_SEC_VAR
#endif


/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1100 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_TJA1100_START_SEC_CODE
# undef ETHTRCV_30_TJA1100_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CODE
# undef ETHTRCV_30_TJA1100_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_TJA1100_START_SEC_CONST_8BIT
# undef ETHTRCV_30_TJA1100_START_SEC_CONST_8BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_CONST_16BIT
# undef ETHTRCV_30_TJA1100_START_SEC_CONST_16BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_CONST_32BIT
# undef ETHTRCV_30_TJA1100_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_PBCFG
# undef ETHTRCV_30_TJA1100_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_PBCFG
# undef ETHTRCV_30_TJA1100_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_TJA1100_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_TJA1100_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1100_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1100 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1103 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef ETHTRCV_30_TJA1103_START_SEC_CODE
# undef ETHTRCV_30_TJA1103_START_SEC_CODE
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_CODE
# undef ETHTRCV_30_TJA1103_STOP_SEC_CODE
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

#ifdef ETHTRCV_30_TJA1103_START_SEC_CONST_8BIT
# undef ETHTRCV_30_TJA1103_START_SEC_CONST_8BIT
# define START_SEC_CONST_8BIT
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_CONST_8BIT
# undef ETHTRCV_30_TJA1103_STOP_SEC_CONST_8BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_CONST_16BIT
# undef ETHTRCV_30_TJA1103_START_SEC_CONST_16BIT
# define START_SEC_CONST_16BIT
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_CONST_16BIT
# undef ETHTRCV_30_TJA1103_STOP_SEC_CONST_16BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_CONST_32BIT
# undef ETHTRCV_30_TJA1103_START_SEC_CONST_32BIT
# define START_SEC_CONST_32BIT
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_CONST_32BIT
# undef ETHTRCV_30_TJA1103_STOP_SEC_CONST_32BIT
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_TJA1103_START_SEC_CONST_UNSPECIFIED
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
# undef ETHTRCV_30_TJA1103_STOP_SEC_CONST_UNSPECIFIED
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_PBCFG
# undef ETHTRCV_30_TJA1103_START_SEC_PBCFG
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_PBCFG
# undef ETHTRCV_30_TJA1103_STOP_SEC_PBCFG
# define STOP_SEC_CONST
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_PBCFG_ROOT
# undef ETHTRCV_30_TJA1103_START_SEC_PBCFG_ROOT
# define START_SEC_CONST_PBCFG
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_PBCFG_ROOT
# undef ETHTRCV_30_TJA1103_STOP_SEC_PBCFG_ROOT
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_8BIT
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_8BIT
# undef ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_TJA1103_START_SEC_VAR_ZERO_INIT_8BIT
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef ETHTRCV_30_TJA1103_STOP_SEC_VAR_ZERO_INIT_8BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_16BIT
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_16BIT
# undef ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_16BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_32BIT
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_32BIT
# undef ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_32BIT
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1103_START_SEC_VAR_NOINIT_UNSPECIFIED
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1103_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

#ifdef ETHTRCV_30_TJA1103_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1103_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef ETHTRCV_30_TJA1103_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef ETHTRCV_30_TJA1103_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1103 END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1145 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TJA1145_START_SEC_CODE)
# undef CANTRCV_30_TJA1145_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CODE)
# undef CANTRCV_30_TJA1145_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1145_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TJA1145_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1145_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TJA1145_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_PBCFG)
# undef CANTRCV_30_TJA1145_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_PBCFG)
# undef CANTRCV_30_TJA1145_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TJA1145_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TJA1145 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */

/**********************************************************************************************************************
 *  CANTRCV_30_TLE62512G START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TLE62512G_START_SEC_CODE)
# undef CANTRCV_30_TLE62512G_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CODE)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_CODE_FAST)
# undef CANTRCV_30_TLE62512G_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_CODE_ISR)
# undef CANTRCV_30_TLE62512G_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_PBCFG)
# undef CANTRCV_30_TLE62512G_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_PBCFG)
# undef CANTRCV_30_TLE62512G_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE62512G_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TLE62512G END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */

/**********************************************************************************************************************
 *  LIN TRANSCEIVER TLE7259 DRIVER START
 *********************************************************************************************************************/
/*******  CODE sections **********************************************************************************************/

#if defined(LINTRCV_30_TLE7259_START_SEC_CODE)
# undef LINTRCV_30_TLE7259_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#if defined(LINTRCV_30_TLE7259_STOP_SEC_CODE)
# undef LINTRCV_30_TLE7259_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(LINTRCV_30_TLE7259_START_SEC_CONST_8BIT)
# undef LINTRCV_30_TLE7259_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(LINTRCV_30_TLE7259_STOP_SEC_CONST_8BIT)
# undef LINTRCV_30_TLE7259_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(LINTRCV_30_TLE7259_START_SEC_CONST_32BIT)
# undef LINTRCV_30_TLE7259_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(LINTRCV_30_TLE7259_STOP_SEC_CONST_32BIT)
# undef LINTRCV_30_TLE7259_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


#if defined(LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED)
# undef LINTRCV_30_TLE7259_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED)
# undef LINTRCV_30_TLE7259_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#if defined(LINTRCV_30_TLE7259_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LINTRCV_30_TLE7259_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(LINTRCV_30_TLE7259_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef LINTRCV_30_TLE7259_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(LINTRCV_30_TLE7259_START_SEC_VAR_ZERO_INIT_8BIT)
# undef LINTRCV_30_TLE7259_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(LINTRCV_30_TLE7259_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef LINTRCV_30_TLE7259_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(LINTRCV_30_TLE7259_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LINTRCV_30_TLE7259_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(LINTRCV_30_TLE7259_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef LINTRCV_30_TLE7259_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* PRQA S 0883 4 */ /* MD_LINTRCV_0883 */
/**********************************************************************************************************************
 *  LIN TRANSCEIVER TLE7259 DRIVER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_TLE9255 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CANTRCV_30_TLE9255_START_SEC_CODE)
# undef CANTRCV_30_TLE9255_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CODE)
# undef CANTRCV_30_TLE9255_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_CODE_FAST)
# undef CANTRCV_30_TLE9255_START_SEC_CODE_FAST /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_FAST    /* mapped to default fast code section */
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CODE_FAST)
# undef CANTRCV_30_TLE9255_STOP_SEC_CODE_FAST  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_CODE_ISR)
# undef CANTRCV_30_TLE9255_START_SEC_CODE_ISR  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR     /* mapped to default ISR code section */
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CODE_ISR)
# undef CANTRCV_30_TLE9255_STOP_SEC_CODE_ISR   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_CONST_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT     /* mapped to default const 8bit section */
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CONST_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST           /* default const stop section */
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_CONST_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CONST_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_CONST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_CONST_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CONST_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CONST_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* FAST CONST sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CONST_FAST_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_CONST_FAST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CONST_FAST_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_CONST_FAST_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CONST_FAST_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_CONST_FAST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_FAST_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_CONST_FAST_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_CONST_FAST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/* Postbuild CFG CONST sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_PBCFG)
# undef CANTRCV_30_TLE9255_START_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_PBCFG)
# undef CANTRCV_30_TLE9255_STOP_SEC_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT      /* mapped to default var init 8bit section */
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_INIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                /* default var stop section */
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_INIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_INIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR NOINIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOINIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOINIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOINIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* ESCAN00065501 */
#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_PBCFG)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_PBCFG
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_PBCFG)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_PBCFG /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR ZERO INIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST INIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_INIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_INIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_INIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif


/* VAR FAST NOINIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_NOINIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_NOINIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_NOINIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR FAST ZERO INIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_FAST_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE INIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_INIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_INIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_INIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE NOINIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOCACHE ZERO INIT sections */

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_16BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_ZERO_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_32BIT
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED)
# undef CANTRCV_30_TLE9255_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CANTRCV_30_TLE9255 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */

/**********************************************************************************************************************
 *  WDG_30_SBC START
 *********************************************************************************************************************/
 
/******** CODE sections **********************************************************************************************/
#ifdef WDG_30_SBC_START_SEC_CODE                      
    #undef WDG_30_SBC_START_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CODE
#endif
#ifdef WDG_30_SBC_STOP_SEC_CODE
    #undef WDG_30_SBC_STOP_SEC_CODE   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef WDG_30_SBC_START_SEC_CONST_UNSPECIFIED
    #undef WDG_30_SBC_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef WDG_30_SBC_STOP_SEC_CONST_UNSPECIFIED
    #undef WDG_30_SBC_STOP_SEC_CONST_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif
#ifdef WDG_30_SBC_START_SEC_PBCFG_ROOT
  #undef WDG_30_SBC_START_SEC_PBCFG_ROOT  /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_PBCFG
#endif
#ifdef WDG_30_SBC_STOP_SEC_PBCFG_ROOT
  #undef WDG_30_SBC_STOP_SEC_PBCFG_ROOT   /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
#ifdef WDG_30_SBC_START_SEC_VAR_INIT_8BIT       /* Init variables */
    #undef WDG_30_SBC_START_SEC_VAR_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_INIT_8BIT
#endif
#ifdef WDG_30_SBC_STOP_SEC_VAR_INIT_8BIT
    #undef WDG_30_SBC_STOP_SEC_VAR_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif  
#ifdef WDG_30_SBC_START_SEC_VAR_ZERO_INIT_8BIT    /* Cleared variables */
    #undef WDG_30_SBC_START_SEC_VAR_ZERO_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef WDG_30_SBC_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef WDG_30_SBC_STOP_SEC_VAR_ZERO_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_SBC_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDG_30_SBC_START_SEC_VAR_ZERO_INIT_32BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef WDG_30_SBC_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDG_30_SBC_STOP_SEC_VAR_ZERO_INIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_SBC_START_SEC_VAR_INIT_UNSPECIFIED
    #undef WDG_30_SBC_START_SEC_VAR_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef WDG_30_SBC_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef WDG_30_SBC_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif
  
#ifdef WDG_30_SBC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDG_30_SBC_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef WDG_30_SBC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDG_30_SBC_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_SBC_START_SEC_VAR_NOINIT_32BIT   /* No init variables */
    #undef WDG_30_SBC_START_SEC_VAR_NOINIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef WDG_30_SBC_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDG_30_SBC_STOP_SEC_VAR_NOINIT_32BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_SBC_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef WDG_30_SBC_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef WDG_30_SBC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDG_30_SBC_STOP_SEC_VAR_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  WDG_30_SBC END
 *********************************************************************************************************************/
 

/**********************************************************************************************************************
 *  WDG_30_TLE4278G START
 *********************************************************************************************************************/
 
/******** CODE sections **********************************************************************************************/
#ifdef WDG_30_TLE4278G_START_SEC_CODE                      
    #undef WDG_30_TLE4278G_START_SEC_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CODE
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_CODE
    #undef WDG_30_TLE4278G_STOP_SEC_CODE   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/
#ifdef WDG_30_TLE4278G_START_SEC_CONST_UNSPECIFIED
    #undef WDG_30_TLE4278G_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_CONST_UNSPECIFIED
    #undef WDG_30_TLE4278G_STOP_SEC_CONST_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_CONST
#endif
#ifdef WDG_30_TLE4278G_START_SEC_PBCFG_ROOT
  #undef WDG_30_TLE4278G_START_SEC_PBCFG_ROOT  /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define START_SEC_CONST_PBCFG
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_PBCFG_ROOT
  #undef WDG_30_TLE4278G_STOP_SEC_PBCFG_ROOT   /* PRQA S 0841 */ /* MD_MSR_Undef */
  #define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
#ifdef WDG_30_TLE4278G_START_SEC_VAR_INIT_8BIT       /* Init variables */
    #undef WDG_30_TLE4278G_START_SEC_VAR_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_INIT_8BIT
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_VAR_INIT_8BIT
    #undef WDG_30_TLE4278G_STOP_SEC_VAR_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif  
#ifdef WDG_30_TLE4278G_START_SEC_VAR_ZERO_INIT_8BIT    /* Cleared variables */
    #undef WDG_30_TLE4278G_START_SEC_VAR_ZERO_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_VAR_ZERO_INIT_8BIT
    #undef WDG_30_TLE4278G_STOP_SEC_VAR_ZERO_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_TLE4278G_START_SEC_VAR_ZERO_INIT_32BIT
    #undef WDG_30_TLE4278G_START_SEC_VAR_ZERO_INIT_32BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_VAR_ZERO_INIT_32BIT
    #undef WDG_30_TLE4278G_STOP_SEC_VAR_ZERO_INIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_TLE4278G_START_SEC_VAR_INIT_UNSPECIFIED
    #undef WDG_30_TLE4278G_START_SEC_VAR_INIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_VAR_INIT_UNSPECIFIED
    #undef WDG_30_TLE4278G_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif
  
#ifdef WDG_30_TLE4278G_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDG_30_TLE4278G_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
    #undef WDG_30_TLE4278G_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_TLE4278G_START_SEC_VAR_NOINIT_32BIT   /* No init variables */
    #undef WDG_30_TLE4278G_START_SEC_VAR_NOINIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_VAR_NOINIT_32BIT
    #undef WDG_30_TLE4278G_STOP_SEC_VAR_NOINIT_32BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif

#ifdef WDG_30_TLE4278G_START_SEC_VAR_NOINIT_UNSPECIFIED 
    #undef WDG_30_TLE4278G_START_SEC_VAR_NOINIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef WDG_30_TLE4278G_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef WDG_30_TLE4278G_STOP_SEC_VAR_NOINIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
    #define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  WDG_30_TLE4278G END
 *********************************************************************************************************************/
 


/**********************************************************************************************************************
 *  VCANIDPS START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef VCANIDPS_START_SEC_CODE
# undef VCANIDPS_START_SEC_CODE                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef VCANIDPS_STOP_SEC_CODE
# undef VCANIDPS_STOP_SEC_CODE                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef VCANIDPS_START_SEC_APPL_CODE
# undef VCANIDPS_START_SEC_APPL_CODE                  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef VCANIDPS_STOP_SEC_APPL_CODE
# undef VCANIDPS_STOP_SEC_APPL_CODE                   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif


/*******  CONST sections  ********************************************************************************************/

#ifdef VCANIDPS_START_SEC_CONST_UNSPECIFIED
# undef VCANIDPS_START_SEC_CONST_UNSPECIFIED          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VCANIDPS_STOP_SEC_CONST_UNSPECIFIED
# undef VCANIDPS_STOP_SEC_CONST_UNSPECIFIED           /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VCANIDPS_START_SEC_PBCFG
# undef VCANIDPS_START_SEC_PBCFG                      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_PBCFG
#endif
#ifdef VCANIDPS_STOP_SEC_PBCFG
# undef VCANIDPS_STOP_SEC_PBCFG                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

#ifdef VCANIDPS_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VCANIDPS_START_SEC_VAR_NOINIT_UNSPECIFIED     /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VCANIDPS_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VCANIDPS_STOP_SEC_VAR_NOINIT_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VCANIDPS_START_SEC_VAR_INIT_UNSPECIFIED
# undef VCANIDPS_START_SEC_VAR_INIT_UNSPECIFIED       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef VCANIDPS_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef VCANIDPS_STOP_SEC_VAR_INIT_UNSPECIFIED        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VCANIDPS_START_SEC_VAR_ZERO_INIT_8BIT
# undef VCANIDPS_START_SEC_VAR_ZERO_INIT_8BIT         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VCANIDPS_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VCANIDPS_STOP_SEC_VAR_ZERO_INIT_8BIT          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VCANIDPS END
 *********************************************************************************************************************/


/* PRQA L:MEMMAP_0841_TAG */


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/

