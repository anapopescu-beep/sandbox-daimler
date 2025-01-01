/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2013 by Vector Informatik GmbH.                                           All rights reserved.
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
 *         File:  _Compiler_Cfg.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the Compiler_Cfg.h
 *                This file has to be extended with the memory and pointer classes for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Heike Honert                  Ht            Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.01  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.02  2009-04-27  Ht                    support OEM specific _compiler_cfg.inc file, improve list of components 
 *                                              (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm, If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.03  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.04  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-09-02  Lo                    add external Flash driver support
 *  01.02.02  2009-09-21  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
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
 *  01.03.02  2010-02-15  Ht                   support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
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
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat,
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-04  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-01  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-10-20  Ht                    ESCAN00054334: add If_AsrIfFeeTiSub
 *                                              ESCAN00054719: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin
 *                                              add define REGSPACE - add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *********************************************************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* Package Merger: Start Section CompilerCfgIncludes */



/* Package Merger: Stop Section CompilerCfgIncludes */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define AUTOSAR_COMSTACKDATA

#define MSR_REGSPACE  REGSPACE

/* Configurable memory class for pointers to registers (e.g. static volatile CONSTP2VAR(uint16, PWM_CONST, REGSPACE)). */
#define REGSPACE


/* due to compatibility to ASR 2.1 */
#define _STATIC_   STATIC
#define _INLINE_   INLINE

/* Package Merger: Start Section CompilerCfgModuleList */



/**********************************************************************************************************************
 *  COMM START 
 *********************************************************************************************************************/

#define COMM_CODE

#define COMM_CONST
#define COMM_PBCFG

#define COMM_VAR_NO_INIT
#define COMM_VAR_PBCFG
#define COMM_VAR_CLEARED

#define COMM_APPL_VAR
#define COMM_NVM_DATA
#define COMM_NVM_DATA_NO_INIT

/**********************************************************************************************************************
 *  COMM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CanSM START
 *********************************************************************************************************************/

#define CANSM_CODE

#define CANSM_CONST


#define CANSM_APPL_CODE

#define CANSM_VAR_NOINIT
#define CANSM_VAR_ZERO_INIT

#define CANSM_APPL_VAR


/*******  FAST sections **********************************************************************************************/

#define CANSM_CONST_FAST

#define CANSM_VAR_NOINIT_FAST
#define CANSM_VAR_ZERO_INIT_FAST


/**********************************************************************************************************************
 *  CanSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FrSM START
 *********************************************************************************************************************/

#define FRSM_CODE
#define FRSM_APPL_CODE

#define FRSM_CONST
#define FRSM_PBCFG

#define FRSM_VAR_NOINIT
#define FRSM_VAR_ZERO_INIT

#define FRSM_APPL_VAR


/**********************************************************************************************************************
 *  FrSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LINSM START
 *********************************************************************************************************************/

#define LINSM_CODE
#define LINSM_CONST
#define LINSM_PBCFG
#define LINSM_VAR_NOINIT
#define LINSM_VAR_ZERO_INIT
#define LINSM_APPL_DATA


/**********************************************************************************************************************
 *  LINSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHSM START 
 *********************************************************************************************************************/

#define ETHSM_CODE

#define ETHSM_CONST
#define ETHSM_APPL_CONST
#define ETHSM_PBCFG
#define ETHSM_APPL_DATA

#define ETHSM_VAR_NOINIT
#define ETHSM_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETHSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  Cdd_AsrCdd START 
 *********************************************************************************************************************/

/* Copy the compiler abstraction defines for each of your configured CDDs and replace the prefix _CDD with the MSN of your configured CDD as higher case. */

#define _CDD_CODE
#define _CDD_APPL_DATA

/* Add additional compiler abstraction defines for each of you configured CDDs here. */

/**********************************************************************************************************************
 *  Cdd_AsrCdd END
 *********************************************************************************************************************/


/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/*        STARTSINGLE_OF_MULTIPLE_COMMENT      */


/**********************************************************************************************************************
 *  Can START    DRVCAN_MPC5700MCANASR
 *********************************************************************************************************************/

#define CAN_CODE                                   /* CAN modules code qualifier               */ /* PRQA S 0883 */ /* Appears only while testing */
#define CAN_STATIC_CODE                            /* CAN local code qualifier                 */
#define CAN_CONST                                  /* constant memory                          */
#define CAN_CONST_PBCFG                            /* postbuild generated constant/flash       */
#define CAN_VAR_NOINIT                             /* none initialized variables               */
#define CAN_VAR_INIT                               /* initialized variables                    */
#define CAN_VAR_PBCFG                              /* postbuild generated variables/dynamic RAM (CFG5 only) */
#define CAN_INT_CTRL                               /* access to Interrupt controller registers */
#define CAN_REG_CANCELL                            /* CAN cell register qualifier              */
#define CAN_RX_TX_DATA                             /* pointer width >= CAN_REG_CANCELL  / CAN rx/tx data / RAM or SFR    (rx data pointer for Indication and PreCopy functions to higher layers / tx data pointers / sdu  from application)   */
#define CAN_APPL_CODE                              /* Application code qualifier               */
#define CAN_APPL_CONST                             /* Application constant memory              */
#define CAN_APPL_VAR                               /* Application variables                    */
#define CAN_VAR_FAR                                /* far local variable qualifier */
#define CAN_VAR_NEAR                               /* near local variable qualifier */

#define CAN_PBCFG  CAN_CONST_PBCFG       /* used for compatibility (used by upper layer EcuM) */

/**********************************************************************************************************************
 *  Can END    DRVCAN_MPC5700MCANASR
 *********************************************************************************************************************/

/*  STOPSINGLE_OF_MULTIPLE_COMMENT  */
/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 766 */



/**********************************************************************************************************************
 *  CRYPTO_30_LIBCV START
 *********************************************************************************************************************/

#define CRYPTO_30_LIBCV_CODE
#define CRYPTO_30_LIBCV_APPL_CODE

#define CRYPTO_30_LIBCV_CONST

#define CRYPTO_30_LIBCV_VAR_NOINIT
#define CRYPTO_30_LIBCV_VAR_ZERO_INIT
#define CRYPTO_30_LIBCV_APPL_VAR
#define CRYPTO_30_LIBCV_APPL_DATA

#define CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR

/**********************************************************************************************************************
 *  CRYPTO_30_LIBCV END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CRYPTO_30_VHSM START
 *********************************************************************************************************************/

#define CRYPTO_30_VHSM_CODE
#define CRYPTO_30_VHSM_APPL_CODE
#define CRYPTO_30_VHSM_CONST

#define CRYPTO_30_VHSM_VAR_NOINIT
#define CRYPTO_30_VHSM_VAR_INIT
#define CRYPTO_30_VHSM_VAR_ZERO_INIT
#define CRYPTO_30_VHSM_APPL_VAR
#define CRYPTO_30_VHSM_APPL_DATA

/**********************************************************************************************************************
 *  CRYPTO_30_VHSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETH_30_TC3XX START 
 *********************************************************************************************************************/

#define ETH_30_TC3XX_CODE
#define ETH_30_TC3XX_CODE_ISR

#define ETH_30_TC3XX_CONST
#define ETH_30_TC3XX_APPL_CONST
#define ETH_30_TC3XX_PBCFG
#define ETH_30_TC3XX_APPL_DATA
#define ETH_30_TC3XX_APPL_VAR

#define ETH_30_TC3XX_APPL_CODE

#define ETH_30_TC3XX_VAR_NOINIT
#define ETH_30_TC3XX_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETH_30_TC3XX END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FR START 
 *********************************************************************************************************************/

#define FR_CODE                                                       /* FR modules code qualifier */
#define FR_CODE_ISR                                                   /* module interrupt service routines */

#define FR_CONST                                                      /* FR constant memory */
#define FR_APPL_CONST                                                 /* Application constant memory, coming from outside of the module */
#define FR_PBCFG                                                      /* postbuild generated constant/flash */
#define FR_APPL_DATA                                                  /* memory class for pointers to application data (expected to be in RAM or ROM) passed via API */
#define FR_VAR_FRM_DATA                                               /* memory class for pointers to Flexray memory data in RAM */
#define FR_APPL_CODE                                                  /* memory class for pointers to application functions (e.g. call back function pointers) */

#define FR_VAR_NOINIT                                                 /* none initialized variables. To be used for all global or static variables that are never initialized */
#define FR_VAR_NOINIT_FAST                                            /* like FR_VAR_NOINIT, optimized access */
#define FR_VAR_ZERO_INIT




/**********************************************************************************************************************
 *  FR END
 *********************************************************************************************************************/





/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**        \file  Lin_Compiler_Cfg.inc
 *        \brief  AUTOSAR LIN Driver
 *
 *      \details  AUTOSAR LIN Driver for all target systems
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  LIN DRIVER START
 **********************************************************************************************************************/

#define LIN_CODE
#define LIN_CODE_FAST
#define LIN_CODE_ISR
#define LIN_APPL_CODE

#define LIN_CONST
#define LIN_CONST_FAST
#define LIN_PBCFG

#define LIN_VAR_PBCFG
#define LIN_VAR_INIT
#define LIN_VAR_NOINIT
#define LIN_VAR_ZERO_INIT
#define LIN_VAR_INIT_FAST
#define LIN_VAR_NOINIT_FAST
#define LIN_VAR_ZERO_INIT_FAST

#define LIN_VAR_INIT_NOCACHE
#define LIN_VAR_NOINIT_NOCACHE
#define LIN_VAR_ZERO_INIT_NOCACHE

#define LIN_APPL_VAR
#define LIN_VAR_REGS

/***********************************************************************************************************************
 *  LIN DRIVER END
 **********************************************************************************************************************/




/***********************************************************************************************************************
 *  VMEM_30_VRPCPROXY START
 **********************************************************************************************************************/

#define VMEM_30_VRPCPROXY_CODE
#define VMEM_30_VRPCPROXY_CONST
#define VMEM_30_VRPCPROXY_APPL_VAR
#define VMEM_30_VRPCPROXY_VAR_ZERO_INIT
#define VMEM_30_VRPCPROXY_VAR_NOINIT
#define VMEM_30_VRPCPROXY_PBCFG

/***********************************************************************************************************************
 *  VMEM_30_VRPCPROXY END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TLF35584_CODE
#define SBC_30_TLF35584_CODE_FAST
#define SBC_30_TLF35584_CODE_ISR

#define SBC_30_TLF35584_CONST
#define SBC_30_TLF35584_CONST_FAST
#define SBC_30_TLF35584_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TLF35584_PBCFG_ROOT

#define SBC_30_TLF35584_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TLF35584_VAR_INIT
#define SBC_30_TLF35584_VAR_NOINIT
#define SBC_30_TLF35584_VAR_ZERO_INIT
#define SBC_30_TLF35584_VAR_INIT_FAST
#define SBC_30_TLF35584_VAR_NOINIT_FAST
#define SBC_30_TLF35584_VAR_ZERO_INIT_FAST

#define SBC_30_TLF35584_VAR_INIT_NOCACHE
#define SBC_30_TLF35584_VAR_NOINIT_NOCACHE
#define SBC_30_TLF35584_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TLF35584_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_88Q1010 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_88Q1010_CODE
#define ETHTRCV_30_88Q1010_CODE_INLINE
#define ETHTRCV_30_88Q1010_CODE_FAST
#define ETHTRCV_30_88Q1010_CODE_ISR

#define ETHTRCV_30_88Q1010_CONST
#define ETHTRCV_30_88Q1010_CONST_FAST
#define ETHTRCV_30_88Q1010_PBCFG


#define ETHTRCV_30_88Q1010_PBCFG_ROOT

#define ETHTRCV_30_88Q1010_VAR_PBCFG

#define ETHTRCV_30_88Q1010_APPL_VAR
#define ETHTRCV_30_88Q1010_APPL_CONST
#define ETHTRCV_30_88Q1010_APPL_CODE
#define ETHTRCV_30_88Q1010_APPL_DATA
#define ETHTRCV_30_88Q1010_VAR_NOINIT
#define ETHTRCV_30_88Q1010_VAR_ZERO_INIT
#define ETHTRCV_30_88Q1010_VAR_INIT_FAST
#define ETHTRCV_30_88Q1010_VAR_NOINIT_FAST
#define ETHTRCV_30_88Q1010_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_88Q1010_VAR_INIT_NOCACHE
#define ETHTRCV_30_88Q1010_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_88Q1010_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_88Q1010 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_88Q2112 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_88Q2112_CODE
#define ETHTRCV_30_88Q2112_CODE_INLINE
#define ETHTRCV_30_88Q2112_CODE_FAST
#define ETHTRCV_30_88Q2112_CODE_ISR

#define ETHTRCV_30_88Q2112_CONST
#define ETHTRCV_30_88Q2112_CONST_FAST
#define ETHTRCV_30_88Q2112_PBCFG


#define ETHTRCV_30_88Q2112_PBCFG_ROOT

#define ETHTRCV_30_88Q2112_VAR_PBCFG

#define ETHTRCV_30_88Q2112_APPL_VAR
#define ETHTRCV_30_88Q2112_APPL_CONST
#define ETHTRCV_30_88Q2112_APPL_CODE
#define ETHTRCV_30_88Q2112_APPL_DATA
#define ETHTRCV_30_88Q2112_VAR_NOINIT
#define ETHTRCV_30_88Q2112_VAR_ZERO_INIT
#define ETHTRCV_30_88Q2112_VAR_INIT_FAST
#define ETHTRCV_30_88Q2112_VAR_NOINIT_FAST
#define ETHTRCV_30_88Q2112_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_88Q2112_VAR_INIT_NOCACHE
#define ETHTRCV_30_88Q2112_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_88Q2112_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_88Q2112 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_ETHMII START 
 *********************************************************************************************************************/

#define ETHTRCV_30_ETHMII_CODE
#define ETHTRCV_30_ETHMII_CODE_INLINE
#define ETHTRCV_30_ETHMII_CODE_FAST
#define ETHTRCV_30_ETHMII_CODE_ISR

#define ETHTRCV_30_ETHMII_CONST
#define ETHTRCV_30_ETHMII_CONST_FAST
#define ETHTRCV_30_ETHMII_PBCFG


#define ETHTRCV_30_ETHMII_PBCFG_ROOT

#define ETHTRCV_30_ETHMII_VAR_PBCFG

#define ETHTRCV_30_ETHMII_APPL_VAR
#define ETHTRCV_30_ETHMII_APPL_CONST
#define ETHTRCV_30_ETHMII_APPL_CODE
#define ETHTRCV_30_ETHMII_APPL_DATA
#define ETHTRCV_30_ETHMII_VAR_NOINIT
#define ETHTRCV_30_ETHMII_VAR_ZERO_INIT
#define ETHTRCV_30_ETHMII_VAR_INIT_FAST
#define ETHTRCV_30_ETHMII_VAR_NOINIT_FAST
#define ETHTRCV_30_ETHMII_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_ETHMII_VAR_INIT_NOCACHE
#define ETHTRCV_30_ETHMII_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_ETHMII_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_ETHMII END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1040 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1040_CODE
#define CANTRCV_30_TJA1040_CODE_FAST
#define CANTRCV_30_TJA1040_CODE_ISR

#define CANTRCV_30_TJA1040_CONST
#define CANTRCV_30_TJA1040_CONST_FAST
#define CANTRCV_30_TJA1040_PBCFG

#define CANTRCV_30_TJA1040_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1040_VAR_INIT
#define CANTRCV_30_TJA1040_VAR_NOINIT
#define CANTRCV_30_TJA1040_APPL_VAR
#define CANTRCV_30_TJA1040_APPL_CODE
#define CANTRCV_30_TJA1040_VAR_ZERO_INIT
#define CANTRCV_30_TJA1040_VAR_INIT_FAST
#define CANTRCV_30_TJA1040_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1040_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1040_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1040_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1040_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1040 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1043_CODE
#define CANTRCV_30_TJA1043_CODE_FAST
#define CANTRCV_30_TJA1043_CODE_ISR

#define CANTRCV_30_TJA1043_CONST
#define CANTRCV_30_TJA1043_CONST_FAST
#define CANTRCV_30_TJA1043_PBCFG

#define CANTRCV_30_TJA1043_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1043_VAR_INIT
#define CANTRCV_30_TJA1043_VAR_NOINIT
#define CANTRCV_30_TJA1043_APPL_VAR
#define CANTRCV_30_TJA1043_APPL_CODE
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT
#define CANTRCV_30_TJA1043_VAR_INIT_FAST
#define CANTRCV_30_TJA1043_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1043_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1043_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */



/**********************************************************************************************************************
 *  FRTRCV TJA1080 START 
 *********************************************************************************************************************/

#define FRTRCV_30_TJA1080_CONST
#define FRTRCV_30_TJA1080_VAR_NOINIT
#define FRTRCV_30_TJA1080_VAR_ZERO_INIT
#define FRTRCV_30_TJA1080_CODE
#define FRTRCV_30_TJA1080_APPL_DATA

/**********************************************************************************************************************
 *  FRTRCV TJA1080 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRTRCV_30_TJA1082 START 
 *********************************************************************************************************************/

#define FRTRCV_30_TJA1082_CODE
#define FRTRCV_30_TJA1082_APPL_CODE
#define FRTRCV_30_TJA1082_CONST
#define FRTRCV_30_TJA1082_VAR_NOINIT
#define FRTRCV_30_TJA1082_VAR_INIT
#define FRTRCV_30_TJA1082_APPL_DATA
#define FRTRCV_30_TJA1082_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  FRTRCV_30_TJA1082 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

#define FRTRCV_30_TJA1085_CODE
#define FRTRCV_30_TJA1085_APPL_CODE
#define FRTRCV_CONST
#define FRTRCV_30_TJA1085_CONST
#define FRTRCV_30_TJA1085_VAR_NOINIT
#define FRTRCV_30_TJA1085_VAR_ZERO_INIT
#define FRTRCV_30_TJA1085_APPL_DATA

/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1145 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1145_CODE
#define CANTRCV_30_TJA1145_CODE_FAST
#define CANTRCV_30_TJA1145_CODE_ISR

#define CANTRCV_30_TJA1145_CONST
#define CANTRCV_30_TJA1145_CONST_FAST
#define CANTRCV_30_TJA1145_PBCFG

#define CANTRCV_30_TJA1145_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1145_VAR_INIT
#define CANTRCV_30_TJA1145_VAR_NOINIT
#define CANTRCV_30_TJA1145_APPL_VAR
#define CANTRCV_30_TJA1145_APPL_CODE
#define CANTRCV_30_TJA1145_VAR_ZERO_INIT
#define CANTRCV_30_TJA1145_VAR_INIT_FAST
#define CANTRCV_30_TJA1145_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1145_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1145_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1145_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1145_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1145 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  LIN TRANSCEIVER TLE7259 DRIVER START
 *********************************************************************************************************************/

#define LINTRCV_30_TLE7259_CODE

#define LINTRCV_30_TLE7259_CONST
#define LINTRCV_30_TLE7259_PBCFG

#define LINTRCV_30_TLE7259_VAR_NOINIT
#define LINTRCV_30_TLE7259_VAR_ZERO_INIT

#define LINTRCV_30_TLE7259_APPL_VAR
#define LINTRCV_30_TLE7259_APPL_CODE
/* PRQA S 0883 4 */ /* MD_LINTRCV_0883 */
/**********************************************************************************************************************
 *  LIN TRANSCEIVER TLE7259 DRIVER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WDG_30_SBC START
 *********************************************************************************************************************/

#define WDG_30_SBC_CODE
#define WDG_30_SBC_CONST
#define WDG_30_SBC_VAR
#define WDG_30_SBC_VAR_INIT
#define WDG_30_SBC_VAR_NOINIT
#define WDG_30_SBC_APPL_DATA
#define WDG_30_SBC_PBCFG


/**********************************************************************************************************************
 *  WDG_30_SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FblPlatformMessage START 
 *********************************************************************************************************************/

#define FBLPLATFORMMESSAGE_CODE
#define FBLPLATFORMMESSAGE_DATA
#define FBLPLATFORMMESSAGE_APPL_DATA

/**********************************************************************************************************************
 *  FblPlatformMessage END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  BSWSTUB-BSWM START
 *********************************************************************************************************************/

#define BSWM_CODE

/**********************************************************************************************************************
 *  BSWSTUB-BSWM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRTRCV START
 *********************************************************************************************************************/

#define FRTRCV_VAR_NOINIT
#define FRTRCV_CODE
#define FRTRCV_CONST
#define FRTRCV_APPL_DATA

/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FBLBM_HDR START
 *********************************************************************************************************************/

#define FBLBMHDR_CONST
#define FBLBMHDR_CODE

/**********************************************************************************************************************
 *  FBLBM_HDR END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FBLBM_MAIN START
 *********************************************************************************************************************/

#define FBLBM_CONST
#define FBLBM_HEADER_CONST

/**********************************************************************************************************************
 *  FBLBM_MAIN END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FBLLIB_SECBOOT START
 *********************************************************************************************************************/

#define FBLSB_CONST
#define FBLSB_CODE

/**********************************************************************************************************************
 *  FBLLIB_SECBOOT END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  VOTAM START
 **********************************************************************************************************************/

#define VOTAM_VAR_NOINIT
#define VOTAM_CONST

#define VOTAM_APPL_VAR

/***********************************************************************************************************************
 *  VOTAM END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  FBL_MEM2HIS START 
 *********************************************************************************************************************/

#define FBL_MEM2HIS_VAR_NOINIT

/**********************************************************************************************************************
 *  FBL_MEM2HIS END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FblCw START 
 *********************************************************************************************************************/

/* Module Constant Data */
#define FBLCW_CONST
/* Module Constant Data of the Postbuild Configuration */
#define FBLCW_PBCFG
/* Module Var Data of the Postbuild Configuration */
#define FBLCW_VAR_PBCFG


/* Module Implementation */
#define FBLCW_CODE

/* Module Variables which are initialized by the startup code or by the call of FblCw_InitMemory() */
#define FBLCW_VAR_NOINIT
/* Module Variables which are initialized by call of FblCw_Init() */
#define FBLCW_VAR_ZERO_INIT
/* Module Variables which are initialized by call of FblCw_Init() */
#define FBLCW_VAR_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define FBLCW_APPL_CODE
/* Application Buffer which is located in RAM */
#define FBLCW_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define FBLCW_APPL_DATA

/**********************************************************************************************************************
 *  FblCw END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  PDUR START 
 *********************************************************************************************************************/

#define PDUR_CODE
#define PDUR_VAR_NO_INIT
#define PDUR_VAR_CLEARED
#define PDUR_VAR
#define PDUR_CONST
#define PDUR_PBCFG
#define PDUR_VAR_PBCFG
#define PDUR_APPL_DATA
#define PDUR_APPL_CODE

/**********************************************************************************************************************
 *  PDUR END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LINIF START
 *********************************************************************************************************************/

#define LINIF_CODE
#define LINIF_CONST
#define LINIF_VAR_NOINIT
#define LINIF_VAR_ZERO_INIT
#define LINIF_VAR_PBCFG
#define LINIF_APPL_DATA
#define LINIF_APPL_VAR
#define LINIF_PBCFG
#define LINIF_APPL_PBCFG
#define LINIF_CBK_TRCV_CODE

/**********************************************************************************************************************
 *  LINIF END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LIN TP START
 *********************************************************************************************************************/

#define LINTP_CODE
#define LINTP_CONST
#define LINTP_VAR_NOINIT
#define LINTP_VAR_ZERO_INIT
#define LINTP_VAR_PBCFG
#define LINTP_APPL_DATA
#define LINTP_APPL_VAR
#define LINTP_PBCFG
#define LINTP_APPL_PBCFG

/**********************************************************************************************************************
 *  LIN TP END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANIF START 
 *********************************************************************************************************************/

#define CANIF_CODE
#define CANIF_CODE_FAST
#define CANIF_CODE_ISR


#define CANIF_CONST
#define CANIF_CONST_FAST
#define CANIF_PBCFG

#define CANIF_VAR_PBCFG /* ESCAN00065502 */

#define CANIF_VAR_INIT
#define CANIF_VAR_NOINIT
#define CANIF_VAR_ZERO_INIT

#define CANIF_VAR_INIT_FAST
#define CANIF_VAR_NOINIT_FAST
#define CANIF_VAR_ZERO_INIT_FAST

#define CANIF_VAR_INIT_NOCACHE
#define CANIF_VAR_NOINIT_NOCACHE
#define CANIF_VAR_ZERO_INIT_NOCACHE


#define CANIF_APPL_CODE
#define CANIF_APPL_VAR
#define CANIF_APPL_PBCFG


/*-------------------------------------------------------------------------------------------------------------------*/

/* Has to be kept in default section -> Default access */
#define CANIF_VAR_STACK


/* VAR section of higher layers (TP / NM / PduR / CanSM / EcuM) automatically mapped to APPL_VAR */
#define CANIF_APPL_STATE_VAR   CANIF_APPL_VAR
#define CANIF_APPL_MSG_VAR     CANIF_APPL_VAR

/* VAR section of lower layers (CAN Driver / Transceiver Driver) automatically mapped to APPL_VAR */
#define CANIF_CBK_VAR          CANIF_APPL_VAR

/* #define CANIF_CBK_TRCV_VAR     CANIF_CBK_VAR    not used yet */
#define CANIF_CBK_DRV_VAR      CANIF_CBK_VAR

/* Code sections - DO NOT MODIFY */
#define CANIF_CBK_TRCV_CODE     CANIF_APPL_CODE
#define CANIF_CBK_CANDRV_CODE   CANIF_APPL_CODE
#define CANIF_APPL_STATE_CODE   CANIF_APPL_CODE
#define CANIF_APPL_MSG_CODE     CANIF_APPL_CODE


/* Upper layer data pointer */
#define CANIF_UL_STANDARD_VAR    CANIF_APPL_VAR
#define CANIF_UL_ADVANCED_VAR    CANIF_APPL_VAR
#define CANIF_UL_OSEKNM_VAR      CANIF_APPL_VAR

/**********************************************************************************************************************
 *  CANIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRYIF START
 *********************************************************************************************************************/

#define CRYIF_CODE
#define CRYIF_CONST

#define CRYIF_VAR_ZERO_INIT
#define CRYIF_APPL_VAR
#define CRYIF_APPL_DATA

/**********************************************************************************************************************
 *  CRYIF END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETHIF START 
 *********************************************************************************************************************/

#define ETHIF_CODE
#define ETHIF_CODE_ISR
#define ETHIF_ETHCTRL_INLINE_CODE
#define ETHIF_ETHTRCV_INLINE_CODE
#define ETHIF_ETHSWT_INLINE_CODE
#define ETHIF_GW_INLINE_CODE
#define ETHIF_LINK_INLINE_CODE
#define ETHIF_MIRROR_INLINE_CODE
#define ETHIF_MODE_INLINE_CODE
#define ETHIF_RX_INLINE_CODE
#define ETHIF_STATS_INLINE_CODE
#define ETHIF_TX_INLINE_CODE
#define ETHIF_UTILS_INLINE_CODE
#define ETHIF_ZEROCOPY_INLINE_CODE

#define ETHIF_CONST

#define ETHIF_APPL_VAR
#define ETHIF_APPL_DATA
#define ETHIF_APPL_CODE

#define ETHIF_VAR_NO_INIT
#define ETHIF_VAR_NO_INIT_FAST

#define ETHIF_VAR_INIT

/**********************************************************************************************************************
 *  ETHIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  FRIF START 
 *********************************************************************************************************************/

#define FRIF_CODE
#define FRIF_CODE_FAST
#define FRIF_CODE_ISR

#define FRIF_CONST
#define FRIF_CONST_FAST
#define FRIF_PBCFG
#define FRIF_PBCFG_GLOBALROOT

#define FRIF_VAR_INIT
#define FRIF_VAR_NOINIT
#define FRIF_VAR_ZERO_INIT
#define FRIF_VAR_INIT_FAST
#define FRIF_VAR_NOINIT_FAST
#define FRIF_VAR_PBCFG
#define FRIF_VAR_ZERO_INIT_FAST

#define FRIF_APPL_DATA
#define FRIF_APPL_CODE

/**********************************************************************************************************************
 *  FRIF END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  SOAD START 
 *********************************************************************************************************************/

#define SOAD_CODE

#define SOAD_APPL_DATA
#define SOAD_APPL_VAR

#define SOAD_CONST
#define SOAD_PBCFG

#define SOAD_VAR_NO_INIT
#define SOAD_VAR_CLEARED
#define SOAD_VAR_PBCFG

/**********************************************************************************************************************
 *  SOAD END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VMEMACCM START
 *********************************************************************************************************************/

#define VMEMACCM_CODE

#define VMEMACCM_CONST

#define VMEMACCM_VMEM_CODE
#define VMEMACCM_VMEM_CONST

#define VMEMACCM_APPL_VAR /* use for user data buffers located in RAM */

#define VMEMACCM_VAR_INIT
#define VMEMACCM_VAR_NOINIT
#define VMEMACCM_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  VMEMACCM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  vRpcProxy START 
 *********************************************************************************************************************/
/* Module Implementation */
#define VRPCPROXY_CODE
#define VRPCPROXY_PBCFG

/* Module Constant Data */
#define VRPCPROXY_CONST

/* Module Variables which are initialized by call of vRpcProxy_Init() */
#define VRPCPROXY_VAR_INIT
#define VRPCPROXY_VAR_NOINIT
#define VRPCPROXY_VAR_ZERO_INIT

/* Application Code Implementation (e.g. Callbacks) */
#define VRPCPROXY_APPL_CODE
/* Application Buffer which is located in RAM */
#define VRPCPROXY_APPL_VAR
/* Application Buffer which is located in ROM or RAM */
#define VRPCPROXY_APPL_DATA
/**********************************************************************************************************************
 *  vRpcProxy END
 *********************************************************************************************************************/



/* Added define to avoid Test include errors */
#define APP_SW 3

/**********************************************************************************************************************
 *  ADC START
 *********************************************************************************************************************/

#define ADC_CODE
#define ADC_VAR_NOINIT
#define ADC_VAR_POWER_ON_INIT
#define ADC_VAR_FAST
#define ADC_VAR
#define ADC_CONST
#define ADC_APPL_DATA
#define ADC_APPL_CONST
#define ADC_APPL_CODE
#define ADC_CALLOUT_CODE

/**********************************************************************************************************************
 *  ADC END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  CRC START
 *********************************************************************************************************************/

#define CRC_CODE
#define CRC_VAR_NOINIT
#define CRC_VAR_POWER_ON_INIT
#define CRC_VAR_FAST
#define CRC_VAR
#define CRC_CONST
#define CRC_APPL_DATA
#define CRC_APPL_CONST
#define CRC_APPL_CODE
#define CRC_CALLOUT_CODE

/**********************************************************************************************************************
 *  ADC END
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  DIO START
 *********************************************************************************************************************/

#define DIO_CODE
#define DIO_VAR_NOINIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST
#define DIO_VAR
#define DIO_CONST
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_APPL_CODE
#define DIO_CALLOUT_CODE

/**********************************************************************************************************************
 *  DIO END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  DMA START
 *********************************************************************************************************************/

#define DMA_CODE
#define DMA_VAR_NOINIT
#define DMA_VAR_POWER_ON_INIT
#define DMA_VAR_FAST
#define DMA_VAR
#define DMA_CONST
#define DMA_APPL_DATA
#define DMA_APPL_CONST
#define DMA_APPL_CODE
#define DMA_CALLOUT_CODE
#define DMA_PBCFG

/**********************************************************************************************************************
 *  DMA END
 *********************************************************************************************************************/
 
  /**********************************************************************************************************************
 *  DSADC START
 *********************************************************************************************************************/

#define DSADC_CODE
#define DSADC_VAR_NOINIT
#define DSADC_VAR_POWER_ON_INIT
#define DSADC_VAR_FAST
#define DSADC_VAR
#define DSADC_CONST
#define DSADC_APPL_DATA
#define DSADC_APPL_CONST
#define DSADC_APPL_CODE
#define DSADC_CALLOUT_CODE
#define DSADC_PBCFG

  /**********************************************************************************************************************
 *  DSADC SEND
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  FEE START
 *********************************************************************************************************************/

#define FEE_CODE
#define FEE_VAR_NOINIT
#define FEE_VAR_POWER_ON_INIT
#define FEE_VAR_FAST
#define FEE_VAR
#define FEE_CONST
#define FEE_APPL_DATA
#define FEE_APPL_CONST
#define FEE_APPL_CODE
#define FEE_CALLOUT_CODE
#define FEE_PBCFG
 
/**********************************************************************************************************************
 *  FEE END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  FLS START
 *********************************************************************************************************************/

#define FLS_CODE
#define FLS_VAR_NOINIT
#define FLS_VAR_POWER_ON_INIT
#define FLS_VAR_FAST
#define FLS_VAR
#define FLS_CONST
#define FLS_APPL_DATA
#define FLS_APPL_CONST
#define FLS_APPL_CODE
#define FLS_CALLOUT_CODE
#define FLS_17_DMU_CODE

/**********************************************************************************************************************
 *  FLS END
 *********************************************************************************************************************/

   /**********************************************************************************************************************
 *  FLSLOADER START
 *********************************************************************************************************************/

#define FLSLOADER_CODE
#define FLSLOADER_VAR_NOINIT
#define FLSLOADER_VAR_POWER_ON_INIT
#define FLSLOADER_VAR_FAST
#define FLSLOADER_VAR
#define FLSLOADER_CONST
#define FLSLOADER_APPL_DATA
#define FLSLOADER_APPL_CONST
#define FLSLOADER_APPL_CODE
#define FLSLOADER_CALLOUT_CODE

/**********************************************************************************************************************
 *  FLSLOADER END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  GPT START
 *********************************************************************************************************************/

#define GPT_CODE
#define GPT_VAR_NOINIT
#define GPT_VAR_POWER_ON_INIT
#define GPT_VAR_FAST
#define GPT_VAR
#define GPT_CONST
#define GPT_APPL_DATA
#define GPT_APPL_CONST
#define GPT_APPL_CODE
#define GPT_CALLOUT_CODE

/**********************************************************************************************************************
 *  GPT END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  ICU START
 *********************************************************************************************************************/

#define ICU_CODE
#define ICU_VAR_NOINIT
#define ICU_VAR_POWER_ON_INIT
#define ICU_VAR_FAST
#define ICU_VAR
#define ICU_CONST
#define ICU_APPL_DATA
#define ICU_APPL_CONST
#define ICU_APPL_CODE
#define ICU_CALLOUT_CODE

/**********************************************************************************************************************
 *  ICU END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  IRQ START
 *********************************************************************************************************************/

#define IRQ_CODE
#define IRQ_VAR_NOINIT
#define IRQ_VAR_POWER_ON_INIT
#define IRQ_VAR_FAST
#define IRQ_VAR
#define IRQ_CONST
#define IRQ_APPL_DATA
#define IRQ_APPL_CONST
#define IRQ_APPL_CODE
#define IRQ_CALLOUT_CODE

/**********************************************************************************************************************
 *  IRQ END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  MCU START
 *********************************************************************************************************************/

#define MCU_CODE
#define MCU_VAR_NOINIT
#define MCU_VAR_POWER_ON_INIT
#define MCU_VAR_FAST
#define MCU_VAR
#define MCU_CONST
#define MCU_APPL_DATA
#define MCU_APPL_CONST
#define MCU_APPL_CODE
#define MCU_CALLOUT_CODE

#define GPTA_CODE
#define GPTA_VAR_NOINIT
#define GPTA_VAR_POWER_ON_INIT
#define GPTA_VAR_FAST
#define GPTA_VAR
#define GPTA_CONST
#define GPTA_APPL_DATA
#define GPTA_APPL_CONST
#define GPTA_APPL_CODE
#define GPTA_CALLOUT_CODE

/**********************************************************************************************************************
 *  MCU END
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  OCU START
 *********************************************************************************************************************/

#define OCU_CODE
#define OCU_VAR_NOINIT
#define OCU_VAR_POWER_ON_INIT
#define OCU_VAR_FAST
#define OCU_VAR
#define OCU_CONST
#define OCU_APPL_DATA
#define OCU_APPL_CONST
#define OCU_APPL_CODE
#define OCU_CALLOUT_CODE

/**********************************************************************************************************************
 *  OCU END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  PORT START
 *********************************************************************************************************************/

#define PORT_CODE
#define PORT_VAR_NOINIT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR_FAST
#define PORT_VAR
#define PORT_CONST
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_APPL_CODE
#define PORT_CALLOUT_CODE

/**********************************************************************************************************************
 *  PORT END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  PWM START
 *********************************************************************************************************************/

#define PWM_CODE
#define PWM_VAR_NOINIT
#define PWM_VAR_POWER_ON_INIT
#define PWM_VAR_FAST
#define PWM_VAR
#define PWM_CONST
#define PWM_APPL_DATA
#define PWM_APPL_CONST
#define PWM_APPL_CODE
#define PWM_CALLOUT_CODE

/**********************************************************************************************************************
 *  PWM END
 *********************************************************************************************************************/

   /**********************************************************************************************************************
 *  SMU START
 *********************************************************************************************************************/

#define SMU_CODE
#define SMU_VAR_NOINIT
#define SMU_VAR_POWER_ON_INIT
#define SMU_VAR_FAST
#define SMU_VAR
#define SMU_CONST
#define SMU_APPL_DATA
#define SMU_APPL_CONST
#define SMU_APPL_CODE
#define SMU_CALLOUT_CODE

/**********************************************************************************************************************
 *  SMU END
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  SPI START
 *********************************************************************************************************************/

#define SPI_CODE
#define SPI_VAR_NOINIT
#define SPI_VAR_POWER_ON_INIT
#define SPI_VAR_FAST
#define SPI_VAR
#define SPI_CONST
#define SPI_APPL_DATA
#define SPI_APPL_CONST
#define SPI_APPL_CODE
#define SPI_CALLOUT_CODE

/**********************************************************************************************************************
 *  SPI END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  UART START
 *********************************************************************************************************************/

#define UART_CODE
#define UART_VAR_NOINIT
#define UART_VAR_POWER_ON_INIT
#define UART_VAR_FAST
#define UART_VAR
#define UART_CONST
#define UART_APPL_DATA
#define UART_APPL_CONST
#define UART_APPL_CODE
#define UART_CALLOUT_CODE

/**********************************************************************************************************************
 *  UART END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  WDG START
 *********************************************************************************************************************/

#define WDG_CODE
#define WDG_VAR_NOINIT
#define WDG_VAR_POWER_ON_INIT
#define WDG_VAR_FAST
#define WDG_VAR
#define WDG_CONST
#define WDG_APPL_DATA
#define WDG_APPL_CONST
#define WDG_APPL_CODE
#define WDG_CALLOUT_CODE

/**********************************************************************************************************************
 *  WDG END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CANNM START 
 *********************************************************************************************************************/

#define CANNM_CODE

#define CANNM_CONST
#define CANNM_PBCFG

#define CANNM_VAR_NOINIT
#define CANNM_VAR_INIT
#define CANNM_VAR_ZERO_INIT
#define CANNM_VAR_PBCFG
#define CANNM_APPL_VAR

/**********************************************************************************************************************
 *  CANNM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRNM START
 *********************************************************************************************************************/

#define FRNM_CODE

#define FRNM_CONST
#define FRNM_PBCFG

#define FRNM_VAR_NOINIT
#define FRNM_VAR_INIT
#define FRNM_VAR_ZERO_INIT
#define FRNM_VAR_PBCFG
#define FRNM_APPL_VAR

/**********************************************************************************************************************
 *  FRNM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  NM START 
 *********************************************************************************************************************/
 
#define NM_CODE
#define NM_APPL_CODE

#define NM_CONST

#define NM_VAR_NO_INIT
#define NM_VAR_INIT
#define NM_APPL_VAR
#define NM_VAR_CLEARED

/**********************************************************************************************************************
 *  NM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  UDPNM START 
 *********************************************************************************************************************/

#define UDPNM_CODE

#define UDPNM_CONST
#define UDPNM_APPL_VAR
#define UDPNM_PBCFG

#define UDPNM_VAR_NOINIT
#define UDPNM_VAR_INIT
#define UDPNM_VAR_ZERO_INIT
#define UDPNM_VAR_PBCFG

/**********************************************************************************************************************
 *  UDPNM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

#define CSM_CODE
#define CSM_APPL_CODE
#define CSM_RTE_CODE

#define CSM_CONST

#define CSM_VAR_NOINIT
#define CSM_VAR_ZERO_INIT
#define CSM_APPL_VAR
#define CSM_APPL_CONST

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VSECPRIM START
 *********************************************************************************************************************/

#define VSECPRIM_CODE
#define VSECPRIM_CONST
#define VSECPRIM_APPL_CONST
#define VSECPRIM_APPL_VAR
#define VSECPRIM_APPL_DATA


/**********************************************************************************************************************
 *  VSECPRIM END
 *********************************************************************************************************************/


# define DET_CODE
# define DET_VAR
# define DET_APPL_DATA
# define DET_CONST


/**********************************************************************************************************************
 *  IPBASE START
 *********************************************************************************************************************/

#define IPBASE_CODE

#define IPBASE_CONST
#define IPBASE_APPL_CONST
#define IPBASE_PBCFG
#define IPBASE_APPL_DATA

#define IPBASE_VAR_NOINIT

/**********************************************************************************************************************
 *  IPBASE END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  WRAPNV START
 *********************************************************************************************************************/

#define WRAPNV_CODE
#define WRAPNV_VAR_NOINIT
#define WRAPNV_CONST
#define WRAPNV_DATA

/**********************************************************************************************************************
 *  WRAPNV END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTP START 
 *********************************************************************************************************************/

#define CANTP_CODE
#define CANTP_CONST

#define CANTP_PBCFG
#define CANTP_VAR_PBCFG

#define CANTP_VAR_INIT
#define CANTP_VAR_NOINIT

#define CANTP_APPL_CODE
#define CANTP_APPL_DATA

/**********************************************************************************************************************
 *  CANTP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DOIP START
 *********************************************************************************************************************/

#define DOIP_CODE

#define DOIP_APPL_CONST
#define DOIP_APPL_DATA
#define DOIP_APPL_VAR
#define DOIP_CONST
#define DOIP_PBCFG

#define DOIP_VAR_NO_INIT
#define DOIP_VAR_CLEARED

/**********************************************************************************************************************
 *  DOIP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  TCPIP START
 *********************************************************************************************************************/

#define TCPIP_CODE
#define TCPIP_CODE_ISR

#define TCPIP_CONST
#define TCPIP_PBCFG

#define TCPIP_APPL_CODE
#define TCPIP_APPL_CONST
#define TCPIP_APPL_DATA
#define TCPIP_APPL_VAR

#define TCPIP_VAR_INIT
#define TCPIP_VAR_CLEARED
#define TCPIP_VAR_NO_INIT

/**********************************************************************************************************************
 *  TCPIP END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  TP_ISO10681 START
 *********************************************************************************************************************/

#define FRTP_CODE

#define FRTP_CODE
#define FRTP_CONST

#define FRTP_APPL_DATA
#define FRTP_APPL_CODE

#define FRTP_VAR_NO_INIT
#define FRTP_VAR_CLEARED

#define FRTP_PBCFG
#define FRTP_PBCFG_ROOT
#define FRTP_VAR_PBCFG

/**********************************************************************************************************************
 *  TP_ISO10681 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#define VSTDLIB_CODE
#define VSTDLIB_VAR_FAR
#define VSTDLIB_APPL_VAR
#define VSTDLIB_CONST

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/




#define _TASKING_C_TRICORE_ 1

#define _TASKING_C_ARM_ 1U



/* Package Merger: Stop Section CompilerCfgModuleList */

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


#endif  /* COMPILER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Compiler_Cfg.h
 *********************************************************************************************************************/
