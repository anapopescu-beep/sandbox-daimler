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


#include "Rte_Compiler_Cfg.h"

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
 *  CRYPTO_30_HWA START
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_CODE
#define CRYPTO_30_HWA_APPL_DATA
#define CRYPTO_30_HWA_APPL_VAR
#define CRYPTO_30_HWA_VAR_ZERO_INIT
#define CRYPTO_30_HWA_CONST
#define CRYPTO_30_HWA_VAR_NOINIT

/**********************************************************************************************************************
 *  CRYPTO_30_HWA END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRYPTO_30_HWA START
 *********************************************************************************************************************/

#define CRYPTO_30_HWA_CODE
#define CRYPTO_30_HWA_APPL_DATA
#define CRYPTO_30_HWA_APPL_VAR
#define CRYPTO_30_HWA_VAR_ZERO_INIT
#define CRYPTO_30_HWA_CONST
#define CRYPTO_30_HWA_VAR_NOINIT

/**********************************************************************************************************************
 *  CRYPTO_30_HWA END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CRYPTO_30_KEYM START
 *********************************************************************************************************************/

#define CRYPTO_30_KEYM_CODE
#define CRYPTO_30_KEYM_CONST
#define CRYPTO_30_KEYM_APPL_DATA
#define CRYPTO_30_KEYM_APPL_VAR
#define CRYPTO_30_KEYM_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  CRYPTO_30_KEYM END
 *********************************************************************************************************************/



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
 *  DrvFls_VttCanoe01Asr START 
 **********************************************************************************************************************/

#define FLS_APPL_CODE
#define FLS_APPL_CONST
#define FLS_APPL_DATA
#define FLS_CODE
#define FLS_VAR

/**********************************************************************************************************************
 *  DrvFls_VttCanoe01Asr END
 **********************************************************************************************************************/




/***********************************************************************************************************************
 *  VMEM_30_TC3XXINF01 START
 **********************************************************************************************************************/

#define VMEM_30_TC3XXINF01_CODE
#define VMEM_30_TC3XXINF01_CONST
#define VMEM_30_TC3XXINF01_APPL_VAR
#define VMEM_30_TC3XXINF01_VAR_NOINIT
#define VMEM_30_TC3XXINF01_VAR_ZERO_INIT
#define VMEM_30_TC3XXINF01_PBCFG

/***********************************************************************************************************************
 *  VMEM_30_TC3XXINF01 END
 **********************************************************************************************************************/


 
/*******************************************************************************
**                      Include Section
*******************************************************************************/

#ifdef __GNUC__
  #include "intrinsics.h"
#endif


/*******************************************************************************
*                      Compiler dependent macros  
*******************************************************************************/


#ifdef __TASKING__

  #ifndef IFX_NO_INLINE
    #define IFX_NO_INLINE __noinline
  #endif

  #define ISYNC() __asm("isb")
  #define DSYNC() __asm("dsb")
  #define NOP() __asm("nop")

#endif

#ifdef __GNUC__

  #ifndef IFX_NO_INLINE
  #define IFX_NO_INLINE __attribute__ ((noinline))
  #endif


  #define ISYNC() __asm("isb")
  #define DSYNC() __asm("dsb")
  #define NOP() __asm("nop")

#endif
/* Added define to avoid Test include errors */
#define APP_SW 3


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
#define FEE_REGSPACE
#define FEE_CALLOUT_CODE
#define FEE_PBCFG
 
/**********************************************************************************************************************
 *  FEE END
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  FLS START
 *********************************************************************************************************************/

#define FLS_17_DMU_CODE
#define FLS_17_DMU_VAR_NOINIT
#define FLS_17_DMU_VAR_POWER_ON_INIT
#define FLS_17_DMU_VAR_FAST
#define FLS_17_DMU_VAR
#define FLS_17_DMU_CONST
#define FLS_17_DMU_APPL_DATA
#define FLS_17_DMU_APPL_CONST
#define FLS_17_DMU_APPL_CODE
#define FLS_17_DMU_REGSPACE
#define FLS_17_DMU_CALLOUT_CODE

/**********************************************************************************************************************
 *  FLS END
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



#define MEMIF_CODE
#define MEMIF_PRIVATE_CODE
#define MEMIF_CONST
#define MEMIF_APPL_DATA



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
 *  NvM START 
 *********************************************************************************************************************/

#define NVM_APPL_DATA
#define NVM_APPL_CODE
#define NVM_APPL_CONST

#define NVM_CONFIG_DATA
#define NVM_CONFIG_CONST

#define NVM_FAST_DATA

#define NVM_PRIVATE_CODE
#define NVM_PRIVATE_CONST
#define NVM_PRIVATE_DATA

#define NVM_PUBLIC_CODE
#define NVM_PUBLIC_CONST

/* SchM/RTE declares NvM_MainFunction, using NVM_CODE *
 * It MUST be defined to NVM_PUBLIC_CODE!             */
#define NVM_CODE NVM_PUBLIC_CODE

/**********************************************************************************************************************
 *  NvM END
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  OS START
 *********************************************************************************************************************/

#define OS_CODE                         /* Regular OS code. */
#define OS_CODE_FAST                    /* Time critical OS code. (currently not used) */
#define OS_CODE_SLOW                    /* Not time critical OS code. (currently not used) */
#define OS_CODE_ISR                     /* OS ISRs. (currently not used) */

#define OS_PANICHOOK_CODE               /* Panic Hook */
#define OS_PRETASKHOOK_CODE             /* PreTask Hook */
#define OS_POSTTASKHOOK_CODE            /* PostTask Hook */
#define OS_STARTUPHOOK_CODE             /* Startup Hook */
#define OS_ERRORHOOK_CODE               /* Error Hook */
#define OS_PROTECTIONHOOK_CODE          /* Protection Hook */
#define OS_SHUTDOWNHOOK_CODE            /* Shutdown Hook */

#define OS_CONST                        /* Constant data. */
#define OS_CONST_FAST                   /* Constant data with fast access. (currently not used) */

#define OS_VAR_INIT                     /* Initialized dynamic data. (Not used by the OS) */
#define OS_VAR_NOINIT                   /* Not initialized dynamic data. */
#define OS_VAR_ZERO_INIT                /* Zero initialized dynamic data. */
#define OS_VAR_INIT_FAST                /* Initialized dynamic data with fast access. (Not used by the OS) */
#define OS_VAR_NOINIT_FAST              /* Not initialized dynamic data with fast access. */
#define OS_VAR_ZERO_INIT_FAST           /* Zero initialized dynamic data with fast access. */

#define OS_VAR_INIT_NOCACHE             /* Initialized dynamic data not cached. (Not used by the OS) */
#define OS_VAR_NOINIT_NOCACHE           /* Not initialized dynamic data not cached. */
#define OS_VAR_ZERO_INIT_NOCACHE        /* Zero initialized dynamic data not cached. */

#define OS_APPL_VAR                     /* Dynamic data from user space (always in RAM). */
#define OS_APPL_DATA                    /* Data from user space (maybe in RAM or ROM). */


#include "Os_Compiler_Cfg.h"

/**********************************************************************************************************************
 *  OS END
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
 *  KEYM START
 *********************************************************************************************************************/

#define KEYM_CODE
#define KEYM_APPL_CODE
#define KEYM_RTE_CODE

#define KEYM_CONST
#define KEYM_PBCFG

#define KEYM_VAR_INIT
#define KEYM_VAR_NO_INIT
#define KEYM_VAR_ZERO_INIT
#define KEYM_APPL_VAR
#define KEYM_APPL_DATA

/**********************************************************************************************************************
 *  KEYM END
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



/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC START 
 *********************************************************************************************************************/

#define CRC_APPL_DATA
#define CRC_PRIVATE_CODE
#define CRC_CODE
#define CRC_CONST

/**********************************************************************************************************************
 *  SYSSERVICE_ASRCRC END
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




/**********************************************************************************************************************
 *  VttCntrl START
 **********************************************************************************************************************/

#define VTTCNTRL_APPL_DATA
#define VTTCNTRL_CONST
#define VTTCNTRL_CODE
#define VTTCNTRL_APPL_CONST
#define VTTCNTRL_PBCFG
#define VTTCNTRL_APPL_VAR
#define VTTCNTRL_VAR
#define VTTCNTRL_APPL_CODE

/**********************************************************************************************************************
 *  VttCntrl END
 **********************************************************************************************************************/




#define _TASKING_C_TRICORE_ 1

#define _TASKING_C_ARM_ 1U



/**********************************************************************************************************************
 *  VHSMUPD START
 *********************************************************************************************************************/

#define VHSMUPD_CODE

#define VHSMUPD_CONST

#define VHSMUPD_APPL_VAR
#define VHSMUPD_APPL_CONST

/**********************************************************************************************************************
 *  VHSMUPD END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VHSMUPD_EXT START
 *********************************************************************************************************************/

#define VHSMUPD_EXT_CODE

#define VHSMUPD_EXT_CONST

#define VHSMUPD_EXT_VAR_NOINIT

#define VHSMUPD_EXT_APPL_VAR
#define VHSMUPD_EXT_APPL_CONST

/**********************************************************************************************************************
 *  VHSMUPD_EXT END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VHSMUPD_HAL START
 *********************************************************************************************************************/

#define VHSMUPD_HAL_CODE

#define VHSMUPD_HAL_CONST

/**********************************************************************************************************************
 *  VHSMUPD_HAL END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VHSM START
 *********************************************************************************************************************/

#define VHSM_CODE
#define VHSM_APPL_CODE
#define VHSM_CONST
#define VHSM_VAR_NOINIT
#define VHSM_VAR_ZERO_INIT
#define VHSM_VAR_INIT
#define VHSM_APPL_VAR
#define VHSM_APPL_DATA

/**********************************************************************************************************************
 *  VHSM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VHSM_CUSTOM START
 *********************************************************************************************************************/

#define VHSM_CUSTOM_CODE
#define VHSM_CUSTOM_APPL_DATA
#define VHSM_CUSTOM_APPL_VAR
#define VHSM_CUSTOM_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  VHSM_CUSTOM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VHSM_HAL START
 *********************************************************************************************************************/

#define VHSM_HAL_CODE
#define VHSM_HAL_CODE_ISR
#define VHSM_HAL_APPL_DATA
#define VHSM_HAL_APPL_VAR
#define VHSM_HAL_VAR_ZERO_INIT
#define VHSM_HAL_CONST
#define VHSM_HAL_VAR_NOINIT

/**********************************************************************************************************************
 *  VHSM_HAL END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VHSM_HAL START
 *********************************************************************************************************************/

#define VHSM_HAL_CODE
#define VHSM_HAL_CODE_ISR
#define VHSM_HAL_APPL_DATA
#define VHSM_HAL_APPL_VAR
#define VHSM_HAL_VAR_ZERO_INIT
#define VHSM_HAL_CONST
#define VHSM_HAL_VAR_NOINIT

/**********************************************************************************************************************
 *  VHSM_HAL END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  DEMOHSM START
 *********************************************************************************************************************/
 
#define vHsm_KeyM_WriteOnceHandling_KeyElementSet Crypto_30_LibCv_KeyElementSet

/**********************************************************************************************************************
 *  DEMOHSM END
 *********************************************************************************************************************/



/* DemoHsm */

/* Flash driver requires some additional defines using GHS compiler */
#ifdef __ghs__
  #include <arm_ghs.h>
  #define ISYNC() __ISB()
  #define DSYNC() __DSB()
  #define NOP() __NOP()
#endif



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
